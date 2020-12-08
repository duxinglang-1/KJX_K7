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
 *  PhbUtilSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements service functions for phb utility.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_include.h"

#include "PhbOPSrv.h"
#include "PhbSrvGprot.h"
#include "PhbSrv.h"
#include "GSM7BitDefaultAlphabet.h"
#include "app_usedetails.h"
#include "app_url.h"

#ifdef __MMI_VCARD__
#include "vcard_lib.h"
#include "FileMgrType.h"
#endif

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "gui.h"
#include "gui_data_types.h"
#include "Gsm7BitNationalLang.h"
#include "custom_phb_config.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "string.h"
#include "PhbSrvIprot.h"
#include "ImeGprot.h"

#define SRV_PHB_CONVERT_BUFF_ZI 32      /* ZI convert function need 32 bytes for buffer. */

/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_latin
 * DESCRIPTION
 *  This function is used to convert lowercase letter to uppercase letter.
 * PARAMETERS
 *  wc:                 [IN]        
 * RETURNS
 *  Wild character
 *****************************************************************************/
U16 srv_phb_convert_to_latin(U16 wc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Latin Basic        0x0000 ~ 0x007F */
    /* Latin-1            0x0080 ~ 0x00FF */
    /* Latin extend-A     0x0100 ~ 0x017F */
    /* Latin extend-B     0x0180 ~ 0x024F */
    /* Greek              0x0370 ~ 0x03FF */
    /* Cyrillic           0x0400 ~ 0x04FF */
    if ((wc >= 0xC0 && wc <= 0xC5) || (wc >= 0xE0 && wc <= 0xE5) ||     /* Latin-1 */
        (wc >= 0x0100 && wc <= 0x0105))                           /* Latin extend-A */
    {
       return 0x41; /* A */
    }
    else if (wc >= 0x0180 && wc <= 0x0185)    /* Latin extend-B */
    {
        return 0x42; /* B */
    }
    else if ((wc == 0xC7) || (wc == 0xE7) ||    /* Latin-1 */
             (wc >= 0x0106 && wc <= 0x010D) ||   /* Latin extend-A */
             (wc >= 0x0186 && wc <= 0x0188))    /* Latin extend-B */
    {
        return 0x43; /* C */
    }
    else if ((wc == 0xD0) || (wc == 0xF0)||    /* Latin-1 */
             (wc >= 0x010E && wc <= 0x0111) ||   /* Latin extend-A */
             (wc >= 0x0189 && wc <= 0x018C))    /* Latin extend-B */
    {
        return 0x44; /* D */
    }
    else if ((wc >= 0xC8 && wc <= 0xCB) || (wc >= 0xE8 && wc <= 0xEB) ||     /* Latin-1 */
             (wc >= 0x0112 && wc <= 0x011B) ||   /* Latin extend-A */
             (wc >= 0x018E && wc <= 0x0190))    /* Latin extend-B */
    {
        return 0x45; /* E */
    }
    else if (wc >= 0x0191 && wc <= 0x0192)    /* Latin extend-B */
    {
        return 0x46; /* F */
    }
    else if ((wc >= 0x011C && wc <= 0x0123) ||   /* Latin extend-A */
             (wc >= 0x0193 && wc <= 0x0194))    /* Latin extend-B */
    {
        return 0x47; /* G */
    }
    else if (wc >= 0x0124 && wc <= 0x0127)  /* Latin extend-A */
    {
        return 0x48; /* H */
    }
    else if ((wc >= 0xCC && wc <= 0xCF) || (wc >= 0xEC && wc <= 0xEF) ||    /* Latin-1 */
             (wc >= 0x0128 && wc <= 0x0131))  /* Latin extend-A */
    {
        return 0x49; /* I */
    }
    else if (wc >= 0x0132 && wc <= 0x0135)   /* Latin extend-A */
    {
        return 0x4A; /* J */
    }
    else if (wc >= 0x0136 && wc <= 0x0138)  /* Latin extend-A */
    {
        return 0x4B; /* K */
    }
    else if (wc >= 0x0139 && wc <= 0x0142)  /* Latin extend-A */
    {
        return 0x4C; /* L */
    }
    else if ((wc == 0xD1) || (wc == 0xF1) ||   /* Latin-1 */
             (wc >= 0x0143 && wc <= 0x014A))  /* Latin extend-A */
    {
        return 0x4E; /* N */
    }
    else if ((wc >= 0xD2 && wc <= 0xD6) || (wc >= 0xF2 && wc <= 0xF6) ||    /* Latin-1 */
             (wc >= 0x014B && wc <= 0x0151))   /* Latin extend-A */
    {
        return 0x4F; /* O */
    }
    else if (wc >= 0x0154 && wc <= 0x0159)   /* Latin extend-A */
    {
        return 0x52; /* R */
    }
    else if (wc >= 0x015A && wc <= 0x0161)  /* Latin extend-A */
    {
        return 0x53; /* S */
    }
    else if (wc >= 0x0162 && wc <= 0x0167)   /* Latin extend-A */
    {
        return 0x54; /* T */
    }
    else if ((wc >= 0xD9 && wc <= 0xDC) || (wc >= 0xF9 && wc <= 0xFC) ||    /* Latin-1 */
             (wc >= 0x0168 && wc <= 0x0173))   /* Latin extend-A */
    {
        return 0x55; /* U */
    }
    else if (wc >= 0x0174 && wc <= 0x0175)   /* Latin extend-A */
    {
        return 0x57; /* W */
    }
    else if ((wc == 0xDD) || (wc == 0xFD) ||   /* Latin-1 */
             (wc >= 0x0176 && wc <= 0x0178))   /* Latin extend-A */
    {
        return 0x59; /* Y */
    }
    else if (wc >= 0x0179 && wc <= 0x017E)  /* Latin extend-A */
    {
        return 0x60; /* Z */
    }
    return wc;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_towupper
 * DESCRIPTION
 *  This function is used to convert lowercase letter to uppercase letter.
 * PARAMETERS
 *  wc:                 [IN]        
 * RETURNS
 *  Wild character
 *****************************************************************************/
U16 srv_phb_towupper(U16 wc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_towupper(wc);
}


#ifdef __MMI_PHB_EMPTY_NAME_TOP__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_upper_english
 * DESCRIPTION
 *  This function is check a character is upper english char
 * PARAMETERS
 *  code:              [IN]        char
 * RETURNS
 *  MMI_TRUE:                  
 *  MMI_FALSE:                 
 *****************************************************************************/
static MMI_BOOL srv_phb_check_upper_english(WCHAR code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (code >= 0x41 && code <= 0x5A)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_phb_compare_wchar
 * DESCRIPTION
 *  This function is used to compare two wild characters.
 * PARAMETERS
 *  char1:              [IN]        First character
 *  char2:              [IN]        Second character
 * RETURNS
 *  >0:                 First is greater than second
 *  =0:                 First is identical to second
 *  <0:                 First is less than second
 *****************************************************************************/
S32 srv_phb_compare_wchar(U16 char1, U16 char2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 char1_temp;
    U16 char2_temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    char1_temp = srv_phb_convert_to_latin(char1);
    if (char1_temp == char1)
    {
        char1_temp = srv_phb_towupper(char1);
    }
    
    char2_temp = srv_phb_convert_to_latin(char2);
    if (char2_temp == char2)
    {
        char2_temp = srv_phb_towupper(char2);
    }
    
    if (char1 == char2 || char1_temp == char2_temp)
    {
        return 0;
    }

#ifdef __MMI_PHB_EMPTY_NAME_TOP__
    else if (srv_phb_check_upper_english((WCHAR)char1_temp) != srv_phb_check_upper_english((WCHAR)char2_temp))
    {
        if (srv_phb_check_upper_english(char1_temp))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
#endif

    /* no match */
#ifndef __MMI_PHB_EMPTY_NAME_TOP__
    if (char1_temp < 'A')
    {
        char1_temp += 0x7B;
    }
    if (char2_temp < 'A')
    {
        char2_temp += 0x7B;
    }
#endif
    return char1_temp - char2_temp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_chinese_char
 * DESCRIPTION
 *  This function is check a character is chinese
 * PARAMETERS
 *  code:              [IN]        character
 * RETURNS
 *  MMI_TRUE:                  chinese
 *  MMI_FALSE:                 not chinese
 *****************************************************************************/
MMI_BOOL srv_phb_check_chinese_char(WCHAR code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((code >= 0x4E00) && (code <= 0x9FA5))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_punctuation_char
 * DESCRIPTION
 *  This function is check a character is unicode punctuation
 * PARAMETERS
 *  char:              [IN]        character
 * RETURNS
 *  MMI_TRUE:                  punctuation
 *  MMI_FALSE:                 not punctuation
 *****************************************************************************/
MMI_BOOL srv_phb_check_punctuation_char(WCHAR code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((code >= 0x0020 && code <= 0x002F) ||
        (code >= 0x003A && code <= 0x0040) ||
        (code >= 0x005B && code <= 0x0060) ||
        (code >= 0x00A1 && code <= 0x00BF))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_pinyin_compare_wchar
 * DESCRIPTION
 *  This function is used to compare two wild characters.
 * PARAMETERS
 *  char1:              [IN]        First character
 *  char2:              [IN]        Second character
 * RETURNS
 *  >0:                 First is greater than second
 *  =0:                 First is identical to second
 *  <0:                 First is less than second
 *****************************************************************************/
S32 srv_phb_pinyin_compare_wchar(U16 char1, U16 char2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 char1_temp;
    U16 char2_temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    char1_temp = srv_phb_convert_to_latin(char1);
    if (char1_temp == char1)
    {
        char1_temp = srv_phb_towupper(char1);
    }
    
    char2_temp = srv_phb_convert_to_latin(char2);
    if (char2_temp == char2)
    {
        char2_temp = srv_phb_towupper(char2);
    }
    
    if (char1 == char2 || char1_temp == char2_temp)
    {
        return 0;
    }
    else if (srv_phb_check_chinese_char((WCHAR)char1) != srv_phb_check_chinese_char((WCHAR)char2))
    {
        if (srv_phb_check_chinese_char(char1))
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }

#ifdef __MMI_PHB_EMPTY_NAME_TOP__
    else if (srv_phb_check_upper_english((WCHAR)char1_temp) != srv_phb_check_upper_english((WCHAR)char2_temp))
    {
        if (srv_phb_check_upper_english(char1_temp))
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
#endif
    /* no match */
#ifndef __MMI_PHB_EMPTY_NAME_TOP__
    if (char1_temp < 'A')
    {
        char1_temp += 0x7B;
    }
    if (char2_temp < 'A')
    {
        char2_temp += 0x7B;
    }
#endif
    return char1_temp - char2_temp;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_is_chinese_string
 * DESCRIPTION
 *  This function check a string is chinese
 * PARAMETERS
 *  string:              [IN]        input string
 * RETURNS
 *  MMI_TRUE:                 is chinese
 *  MMI_FALSE:                not chinese
 *****************************************************************************/
MMI_BOOL srv_phb_is_chinese_string(WCHAR* string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!string)
    {
        return MMI_FALSE;
    }
    while (*string)
    {
        if (srv_phb_check_chinese_char(*string))
        {
            return MMI_TRUE;
        }
        string++;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_wcs_n_cmp
 * DESCRIPTION
 *  This function is used to compare two ucs2 strings.
 * PARAMETERS
 *  string1:            [IN]        First string
 *  string2:            [IN]        Second string
 * RETURNS
 *  >0:                 First is greater than second
 *  =0:                 First is identical to second
 *  <0:                 First is less than second
 *****************************************************************************/
S32 srv_phb_wcs_n_cmp(const WCHAR* string1, const WCHAR* string2, S32 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len1, len2;
    S32 max_len, min_len;
    S32 distance, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len1 = min(mmi_wcslen(string1), count);
    len2 = min(mmi_wcslen(string2), count);
    if (len1 > len2)
    {
        max_len = len1;
        min_len = len2;
    }
    else
    {
        max_len = len2;
        min_len = len1;
    }

    for (i = 0; i < max_len; i++)
    {
        /* If all characters are identical from 0 to min_len */
        if (i >= min_len)
        {
            /* First is greater than second */
            if (len1 > len2)
            {
                return string1[i];
            }
            /* First and second are identical */
            else if (len1 == len2)
            {
                return 0;
            }
            /* len1 < len2: First is less than second */
            else
            {
                return -string2[i];
            }
        }
        /* First, compare from 0 to min_len */
        else
        {
            /* First and second are not identical, return distance */
            if ((distance = srv_phb_compare_wchar(string1[i], string2[i])) != 0)
            {
                return distance;
            }
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_acs_wcs_n_cmp
 * DESCRIPTION
 *  This function is used to compare two ucs2 strings.
 * PARAMETERS
 *  string1:            [IN]        First string
 *  string2:            [IN]        Second string
 * RETURNS
 *  >0:                 First is greater than second
 *  =0:                 First is identical to second
 *  <0:                 First is less than second
 *****************************************************************************/
S32 srv_phb_acs_wcs_n_cmp(const CHAR* string1, const WCHAR* string2, U16 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len1, len2;
    S32 max_len, min_len;
    S32 distance, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len1 = min(strlen(string1), count);
    len2 = min(mmi_wcslen(string2), count);
    if (len1 > len2)
    {
        max_len = len1;
        min_len = len2;
    }
    else
    {
        max_len = len2;
        min_len = len1;
    }

    for (i = 0; i < max_len; i++)
    {
        /* If all characters are identical from 0 to min_len */
        if (i >= min_len)
        {
            /* First is greater than second */
            if (len1 > len2)
            {
                return string1[i];
            }
            /* First and second are identical */
            else if (len1 == len2)
            {
                return 0;
            }
            /* len1 < len2: First is less than second */
            else
            {
                return -string2[i];
            }
        }
        /* First, compare from 0 to min_len */
        else
        {
            /* First and second are not identical, return distance */
            if ((distance = srv_phb_compare_wchar((U16)(string1[i]), string2[i])) != 0)
            {
                return distance;
            }
        }
    }
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_compare_ucs2_string
 * DESCRIPTION
 *  This function is used to compare two ucs2 strings.
 * PARAMETERS
 *  string1:            [IN]        First string
 *  string2:            [IN]        Second string
 * RETURNS
 *  >0:                 First is greater than second
 *  =0:                 First is identical to second
 *  <0:                 First is less than second
 *****************************************************************************/
S32 srv_phb_compare_ucs2_string(U16 *string1, U16 *string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len1, len2;
    S32 max_len, min_len;
    S32 distance, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len1 = mmi_wcslen(string1);
    len2 = mmi_wcslen(string2);

    if (len1 > len2)
    {
        max_len = len1;
        min_len = len2;
    }
    else
    {
        max_len = len2;
        min_len = len1;
    }

    for (i = 0; i < max_len; i++)
    {
        /* If all characters are identical from 0 to min_len */
        if (i >= min_len)
        {
            /* First is greater than second */
            if (len1 > len2)
            {
                return string1[i];
            }
            /* First and second are identical */
            else if (len1 == len2)
            {
                return 0;
            }
            /* len1 < len2: First is less than second */
            else
            {
                return -string2[i];
            }
        }
        /* First, compare from 0 to min_len */
        else
        {
            /* First and second are not identical, return distance */
            if ((distance = srv_phb_compare_wchar(string1[i], string2[i])) != 0)
            {
                return distance;
            }
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_compare_pinyin_string
 * DESCRIPTION
 *  This function is used to compare two pinyin strings.
 * PARAMETERS
 *  string1:            [IN]        First string
 *  string2:            [IN]        Second string
 * RETURNS
 *  >0:                 First is greater than second
 *  =0:                 First is identical to second
 *  <0:                 First is less than second
 *****************************************************************************/
S32 srv_phb_compare_pinyin_string(U16 *string1, U16 *string2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len1, len2;
    S32 max_len, min_len;
    S32 distance, i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len1 = mmi_wcslen(string1);
    len2 = mmi_wcslen(string2);

    if (len1 > len2)
    {
        max_len = len1;
        min_len = len2;
    }
    else
    {
        max_len = len2;
        min_len = len1;
    }

    for (i = 0; i < max_len; i++)
    {
        /* If all characters are identical from 0 to min_len */
        if (i >= min_len)
        {
            /* First is greater than second */
            if (len1 > len2)
            {
                return string1[i];
            }
            /* First and second are identical */
            else if (len1 == len2)
            {
                return 0;
            }
            /* len1 < len2: First is less than second */
            else
            {
                return -string2[i];
            }
        }
        /* First, compare from 0 to min_len */
        else
        {
            /* First and second are not identical, return distance */
            if ((distance = srv_phb_pinyin_compare_wchar(string1[i], string2[i])) != 0)
            {
                return distance;
            }
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_gsm_extended_count
 * DESCRIPTION
 *  This function is used to calculate GSM extended characters' count.
 * PARAMETERS
 *  buffer:             [IN]        Input buffer
 *  max_buffer_len:     [IN]        Max length of buffer
 * RETURNS
 *  GSM extended characters' count
 *****************************************************************************/
U32 srv_phb_gsm_extended_count(U16 *buffer, U32 max_buffer_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 extend_num = 0;
    U32 count = 0;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (buffer[len] && count < max_buffer_len)
    {
        if (UI_TEST_GSM_EXTENDED((UI_character_type) buffer[len++]))
        {
            count++;
            extend_num++;
        }
        count++;
    }

    return extend_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_ucs2_character
 * DESCRIPTION
 *  This function is used to check if UCS2 character (such as Chinese) exists or not.
 * PARAMETERS
 *  buffer:             [IN]        Input buffer
 * RETURN VALUES
 *  MMI_TRUE:           Include a UCS2 character
 *  MMI_FALSE:          Didn't include it
 *****************************************************************************/
MMI_BOOL srv_phb_check_ucs2_character(U16 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*buffer)
    {
        if (UI_TEST_UCS2_CHARACTER(*buffer))
        {
            return MMI_TRUE;
        }
        buffer++;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_international_number
 * DESCRIPTION
 *  This function is used to check if it is an international number or not.
 * PARAMETERS
 *  type:               [IN]        TON
 * RETURNS
 *  MMI_TRUE:           International number
 *  MMI_FALSE:          Others number
 *****************************************************************************/
MMI_BOOL srv_phb_check_international_number(U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((type & 0x10) && (type != 0xFF))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_valid_number
 * DESCRIPTION
 *  This function is used to check if it is a valid number or not.
 * PARAMETERS
 *  number:             [IN]        Number to check
 * RETURN VALUES
 *  MMI_TRUE:           Valid number
 *  MMI_FALSE:          Invalid number
 *****************************************************************************/
MMI_BOOL srv_phb_check_valid_number(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number[0])
    {
        /* call the applib validity API to check if number is valid */
        if (applib_is_valid_number_unicode(number) == APPLIB_INVALID_NUMBER)
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_valid_number_ex
 * DESCRIPTION
 *  This function is used to check if it is a valid number or not.
 * PARAMETERS
 *  number:             [IN]        Number to check
 *  is_sim:             [IN]        Number comes from SIM or not
 * RETURN VALUES
 *  MMI_TRUE:           Valid number
 *  MMI_FALSE:          Invalid number
 *****************************************************************************/
MMI_BOOL srv_phb_check_valid_number_ex(U16 *number, MMI_BOOL is_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_check_valid_number(number))
    {
        if (!is_sim && !mmi_ucs2str((CHAR*) number, "?"))
        {
            return MMI_TRUE;
        }

        if (is_sim && !mmi_ucs2str((const CHAR *) number, "w") && !mmi_ucs2str((const CHAR *) number, "W"))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_valid_url
 * DESCRIPTION
 *  This function is used to check if it is a valid URL or not.
 * PARAMETERS
 *  url:                [IN]        URL to check
 * RETURN VALUES
 *  MMI_TRUE:           Valid URL
 *  MMI_FALSE:          Invalid URL
 *****************************************************************************/
MMI_BOOL srv_phb_check_valid_url(U16 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *utf8_url;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (url[0])
    {
        utf8_url = OslMalloc(MMI_PHB_URL_LENGTH + 1);
        mmi_wcs_n_to_asc(utf8_url, url, MMI_PHB_URL_LENGTH * sizeof(U16));

        if (applib_url_is_valid_ext(utf8_url, KAL_TRUE, KAL_FALSE) == 0)
        {
            OslMfree(utf8_url);
            return MMI_TRUE;
        }

        OslMfree(utf8_url);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_bcd_get_half_byte
 * DESCRIPTION
 *  This function is used to convert ASCII code to BCD code.
 * PARAMETERS
 *  digit:              [IN]        
 * RETURNS
 *  BCD code
 *****************************************************************************/
static U8 srv_phb_convert_to_bcd_get_half_byte(U8 digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 half_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (digit <= '9' && digit >= '0')
    {
        half_byte = digit - '0';
    }
    else
    {
        switch (digit)
        {
            case '*':
                half_byte = 0x0A;
                break;

            case '#':
                half_byte = 0x0B;
                break;

            case 'p':
            case 'P':
                half_byte = 0x0C;
                break;

            case 'w':
            case 'W':
            case '?':
                half_byte = 0x0D;
                break;

            case '+':
                half_byte = 0x0E;
                break;

            default:
                half_byte = 0x0F;
                break;
        }
    }

    return half_byte;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_bcd
 * DESCRIPTION
 *  This function is used to convert ASCII string to BCD.
 * PARAMETERS
 *  dest:               [OUT]       BCD encoding string
 *  source:             [IN]        ASCII encoding string
 *  max_dest_len:       [IN]        Max length of dest buffer
 * RETURNS
 *  No. of bytes converted
 *****************************************************************************/
U32 srv_phb_convert_to_bcd(U8 *dest, U8 *source, U32 max_dest_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U8 lower_byte, upper_byte;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (source[i] != '\0')
    {
        lower_byte = srv_phb_convert_to_bcd_get_half_byte(source[i]);
        upper_byte = srv_phb_convert_to_bcd_get_half_byte(source[i + 1]);

        if ((i >> 1) >= max_dest_len)
        {
            return (i >> 1);
        }

        *(dest + (i >> 1)) = (upper_byte << 4) + lower_byte;

        if (source[i + 1] == '\0')
        {
            if ((i >> 1) >= max_dest_len)
            {
                return (i >> 1) + 1;
            }

            *(dest + (i >> 1)) |= 0xF0;
            return (i >> 1) + 1;
        }

        i += 2;
    }

    if ((i >> 1) >= max_dest_len)
    {
        return (i >> 1);
    }

    *(dest + (i >> 1)) = 0xFF;
    return (i >> 1);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_digit_get_digit
 * DESCRIPTION
 *  This function is used to convert BCD code to ASCII code.
 * PARAMETERS
 *  bcd:                [IN]        
 *  is_sim:             [IN]        
 * RETURNS
 *  ASCII code
 *****************************************************************************/
static U8 srv_phb_convert_to_digit_get_digit(U8 bcd, MMI_BOOL is_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 digit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bcd <= 9)
    {
        digit = bcd + '0';
    }
    else
    {
        switch (bcd)
        {
            case 0x0A:
                digit = '*';
                break;

            case 0x0B:
                digit = '#';
                break;

            case 0x0C:
                digit = 'p';
                break;

            case 0x0D:
                if (is_sim)
                {
                    digit = '?';
                }
                else
                {
                    digit = 'w';
                }
                break;

            case 0x0E:
                digit = '+';
                break;

            default:
                digit = '\0';
                break;
        }
    }

    return digit;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_digit
 * DESCRIPTION
 *  This function is used to convert BCD string to ASCII. (0x0D will be converted to '?')
 * PARAMETERS
 *  dest:               [OUT]       ASCII encoding string
 *  source:             [IN]        BCD encoding string
 *  max_dest_len:       [IN]        Max length of dest buffer
 * RETURNS
 *  No. of bytes converted
 *****************************************************************************/
U32 srv_phb_convert_to_digit(U8 *dest, U8 *source, U32 max_dest_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_convert_to_digit_ex(dest, source, max_dest_len, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_digit_ex
 * DESCRIPTION
 *  This function is used to convert BCD string to ASCII. (0x0D will be converted to '?'
 *  if is_sim MMI_TRUE, otherwise it will be 'w')
 *  It will be removed when MMI callog revise.
 * PARAMETERS
 *  dest:               [OUT]       ASCII encoding string
 *  source:             [IN]        BCD encoding string
 *  max_dest_len:       [IN]        Max length of dest buffer
 *  is_sim:             [IN]        Number comes from SIM or not
 * RETURNS
 *  No. of bytes converted
 *****************************************************************************/
U32 srv_phb_convert_to_digit_ex(U8 *dest, U8 *source, U32 max_dest_len, MMI_BOOL is_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0;
    U8 ch1, ch2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((source[i] != 0xFF) && (j < max_dest_len - 1))
    {
        ch1 = source[i] & 0x0F;
        ch2 = (source[i] & 0xF0) >> 4;

        *(dest + j) = srv_phb_convert_to_digit_get_digit(ch1, is_sim);

        if (ch2 == 0x0F)
        {
            *(dest + j + 1) = '\0';
            return j + 1;
        }
        else
        {
            *(dest + j + 1) = srv_phb_convert_to_digit_get_digit(ch2, is_sim);
        }
        i++;
        j += 2;
    }

    *(dest + j) = '\0';
    return j;
}

#if defined(__PHB_0x81_SUPPORT__)


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_0x81_get_offset
 * DESCRIPTION
 *  This function is used to get 0x81 offset.
 * PARAMETERS
 *  base:               [IN]        
 *  code:               [IN]        
 * RETURNS
 *  0x81 offset
 *****************************************************************************/
static U8 srv_phb_convert_to_0x81_get_offset(U16 base, U16 code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (U8) (code - base + 0x80);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_0x81_get_base
 * DESCRIPTION
 *  This function is used to get 0x81 base.
 * PARAMETERS
 *  code:               [IN]        
 * RETURNS
 *  0x81 base
 *****************************************************************************/
static U16 srv_phb_convert_to_0x81_get_base(U16 code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((code >= 0x0E00) && (code <= 0x0E5F))   /* Thai 0E00 ~ 0E5F */
    {
        return 0x0E00;
    }
    if ((code >= 0x0080) && (code <= 0x00FF))   /* C1 Controls and Latin-1 Supplement */
    {
        return 0x0080;
    }
    if ((code >= 0x0100) && (code <= 0x017F))   /* Latin Extended - A */
    {
        return 0x0100;
    }
    if ((code >= 0x0180) && (code <= 0x01FF))   /* Latin Extended - B (Partial) */
    {
        return 0x0180;
    }
    if ((code >= 0x0400) && (code <= 0x047F))   /* Russian 0400 ~ 04FF */
    {
        return 0x0400;
    }
    if ((code >= 0x0600) && (code <= 0x067F))   /* Arabic 0600 ~ 06FF */
    {
        return 0x0600;
    }
    if ((code >= 0x0900) && (code <= 0x097F))
    {
        return 0x0900;
    }
    if ((code >= 0x0980) && (code <= 0x09FF))   /* Bengali 0980 ~ 09FF */
    {
        return 0x0980;
    }
    if ((code >= 0x0A00) && (code <= 0x0A7F))   /* Punjabi 0A00 ~ 0A7F */
    {
        return 0x0A00;
    }
    if ((code >= 0x0A80) && (code <= 0x0AFF))   /* Gujarati 0A80 ~ 0AFF */
    {
        return 0x0A80;
    }
    if ((code >= 0x0B00) && (code <= 0x0B7F))   /* Oriya 0B00 ~ 0B7F */
    {
        return 0x0B00;
    }
    if ((code >= 0x0B80) && (code <= 0x0BFF))   /* Tamil 0B80 ~ 0BFF */
    {
        return 0x0B80;
    }
    if ((code >= 0x0C00) && (code <= 0x0C7F))   /* Telugu 0C00 ~ 0C7F */
    {
        return 0x0C00;
    }
    if ((code >= 0x0C80) && (code <= 0x0CFF))   /* Kannada 0C80 ~ 0CFF */
    {
        return 0x0C80;
    }
    if ((code >= 0x0D00) && (code <= 0x0D7F))   /* Malayalam 0D00 ~ 0D7F */
    {
        return 0x0D00;
    }
    if ((code >= 0x3100) && (code <= 0x312F))   /* BOPOMOFO 0x3100 ~ 0x312F */
    {
        return 0x3100;
    }

    return 0x0000;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_0x81
 * DESCRIPTION
 *  This function is used to convert UCS2 string (such as PHB name) to 0x81 encoding.
 *  We will copy the convert result to input buffer when is_convert is assigned as MMI_TRUE.
 * PARAMETERS
 *  name:               [IN/OUT]    PHB name
 *  is_convert:         [IN]        Copy the convert result or not
 * RETURNS
 *  No. of bytes converted
 *****************************************************************************/
U32 srv_phb_convert_to_0x81(U16 *name, MMI_BOOL is_convert)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 code;
    U16 base = 0;
    MMI_BOOL flag = MMI_TRUE;
    U16 *temp_name = name;
    U32 i = 3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Find first UCS2 character as base */
    while (*temp_name)
    {
        code = *temp_name;

        if (code >= 0x80 && UI_TEST_UCS2_CHARACTER(code))
        {
            base = srv_phb_convert_to_0x81_get_base(code);
            break;
        }
        temp_name++;
    }

    /* Check if whole string can be encoded as 0x81 */
    temp_name = name;
    if (base > 0)
    {
        U8 *result_name = srv_phb_mem_malloc(mmi_wcslen(name) + 3, SRV_PHB_MEMORY_TYPE_CTR);
        result_name[0] = (U8) 0x81;
        result_name[1] = (U8) mmi_wcslen(name);
        result_name[2] = (U8) (base >> 7);

        do
        {
            code = *temp_name;

            if (!UI_TEST_UCS2_CHARACTER(code))
            {
                if (UI_TEST_GSM_EXTENDED(code))
                {
                    flag = MMI_FALSE;
                    break;
                }
                else
                {
                    result_name[i] = GSM7BitMapASCIIToDefaultByte(code);
                }
            }
            else if (srv_phb_convert_to_0x81_get_base(code) != base)
            {
                flag = MMI_FALSE;
                break;
            }
            else
            {
                result_name[i] = srv_phb_convert_to_0x81_get_offset(base, code);
            }
            temp_name++;
            i++;
        }
        while (*temp_name);

        if (flag)
        {
            /* Write result to the same buffer */
            if (is_convert)
            {
                memcpy(name, result_name, i);
            }

            srv_phb_mem_free(result_name);
            return i;
        }

        srv_phb_mem_free(result_name);
    }

    return 0;
}

#endif /* defined(__PHB_0x81_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_name
 * DESCRIPTION
 *  This function is used to compine PHB first and last name.
 * PARAMETERS
 *  name:               [OUT]       PHB name
 *  f_name:             [IN]        First name
 *  l_name:             [IN]        Last name
 *  max_name_len:       [IN]        Max length of PHB name
 * RETURNS
 *  No. of characters converted
 *****************************************************************************/
void srv_phb_convert_to_name(U16 *name, U16 *f_name, U16 *l_name, U32 max_name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 old_len = max_name_len;
    U16* name_1;
    U16* name_2;
    U16 separator;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (srv_phb_get_name_display_type())
    {
        case SRV_PHB_NAME_DISPLAY_TYPE_2:
            name_1 = l_name;
            name_2 = f_name;
            separator = ',';
            break;
            
        case SRV_PHB_NAME_DISPLAY_TYPE_3:
            name_1 = f_name;
            name_2 = l_name;
            separator = ' ';
            break;
            
        case SRV_PHB_NAME_DISPLAY_TYPE_4:
            name_1 = f_name;
            name_2 = l_name;
            separator = ',';
            break;
            
        case SRV_PHB_NAME_DISPLAY_TYPE_1:
        default:
            name_1 = l_name;
            name_2 = f_name;
            separator = ' ';
            break;
    }
    if (name_1 || name_2)
    {
        if (name_1)
        {
            while (max_name_len && *name_1)
            {
                *(name++) = *(name_1++);
                max_name_len--;
            }
        }
        if ((max_name_len > 1) && (old_len != max_name_len) && name_2 && *name_2)
        {
            *(name++) = separator;
            max_name_len--;
        }
        if (name_2)
        {
            while (max_name_len && *name_2)
            {
                *(name++) = *(name_2++);
                max_name_len--;
            }
        }
    }
    *name = L'\0';
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_spelling
 * DESCRIPTION
 *  This function is used to convert to spelling. (ex. Chinese '一' can be converted to 'Y', 'i').
 * PARAMETERS
 *  input_mode:         [IN]        Input method mode
 *  input_char:         [IN]        Input character
 *  output_char:        [OUT]       Output characters
 *  out_len:            [IN]        Output buffer length
 * RETURNS
 *  No. of characters converted
 *****************************************************************************/
U16 srv_phb_convert_to_spelling(U16 input_mode, WCHAR input_char, WCHAR *output_char, U16 out_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_ZI__) || defined(__MMI_CSTAR__) || defined(__MMI_T9__) || defined(__MMI_ITAP__) || defined(__MMI_GUOBI__)
    S32 i = 0;
    U16 char_buffer[SRV_PHB_CONVERT_BUFF_ZI + 1];
#endif /* defined(__MMI_ZI__) || defined(__MMI_CSTAR__) || defined(__MMI_T9__) || defined(__MMI_ITAP__) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_ZI__) || defined(__MMI_CSTAR__) || defined(__MMI_T9__) || defined(__MMI_GUOBI__)
    if (input_char)
    {
        if ((input_char >= 0x4E00) && (input_char <= 0x9FA5) &&
            mmi_imc_get_char_info(input_char, char_buffer, SRV_PHB_CONVERT_BUFF_ZI, (mmi_imm_input_mode_enum)input_mode))
        {
            switch (input_mode)
            {
                case IMM_INPUT_MODE_QUICK_SEARCH_BOPOMO:
                case IMM_INPUT_MODE_QUICK_SEARCH_PINYIN:
                case IMM_INPUT_MODE_QUICK_SEARCH_SM_STROKE:
                case IMM_INPUT_MODE_QUICK_SEARCH_TR_STROKE:
                case IMM_INPUT_MODE_QUICK_SEARCH_HK_STROKE:
                    while ((i < SRV_PHB_CONVERT_BUFF_ZI) && char_buffer[i] && (i < out_len))
                    {
                        *(output_char++) = char_buffer[i++];
                    }
                    break;

                default:
                    break;
            }
            return i;
        }
    }
#elif defined(__MMI_ITAP__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    *output_char = input_char;
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_pinyin
 * DESCRIPTION
 *  This function is used to convert to pinyin. (ex. Chinese '一个' can be converted to 'Y', 'i', 'G', 'e').
 * PARAMETERS
 *  input_string:       [IN]        Input strings
 *  output_string:      [OUT]       Output strings
 *  out_len:            [IN]        Output buffer length
 * RETURNS
 *  No. of characters converted
 *****************************************************************************/
U16 srv_phb_convert_to_pinyin(U16 *input_string, U16 *output_string, U16 out_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 len;
    U16 *temp_string = output_string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*input_string && out_len)
    {
        len = srv_phb_convert_to_spelling(IMM_INPUT_MODE_QUICK_SEARCH_PINYIN, *input_string, temp_string, out_len);
        temp_string += len;
        out_len -= len;
        if (out_len && (*(temp_string - 1)) != (*input_string))
        {
            *(temp_string++) = *input_string;
            out_len--;
        }
        input_string++;
    }

    return (U16) (temp_string - output_string);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_initial
 * DESCRIPTION
 *  This function is used to convert to initial. (ex. Chinese '一个' can be converted to 'Y', 'G').
 * PARAMETERS
 *  input_string:       [IN]        Input strings
 *  output_string:      [OUT]       Output strings
 *  out_len:            [IN]        Output buffer length
 * RETURNS
 *  No. of characters converted
 *****************************************************************************/
void srv_phb_convert_to_initial(U16 *input_string, U16 *output_string, U16 out_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL new_word = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*input_string && out_len)
    {
        if ((*input_string == L' ') || (*input_string == L';') || (*input_string == L','))
        {
            new_word = MMI_TRUE;
        }
        else if (new_word) 
        {
            *(output_string++) = *input_string;
            out_len--;
            new_word = MMI_FALSE;
        }
        input_string++;
    }
    *output_string = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_remove_invalid_name
 * DESCRIPTION
 *  This function is used to remove invalid characters.
 * PARAMETERS
 *  name:               [IN/OUT]    PHB name
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_remove_invalid_name(U16 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *temp_name = name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*name)
    {
        /* remove 0D0A, phb doesn't support 0D0A */
        if (*name == 0x0D && (*(name + 1) == 0x0A))
        {
            name += 2;
        }
        /* remove 1B00, because editor regards 1B00 as a special identification */
        else if (*name == 0x1B || *name == 0x0A)
        {
            name++;
        }
        else if (*name == 0xFFFF)
        {
            name++;
        }
        else
        {
            *(temp_name++) = *(name++);
        }
    }
    *temp_name = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_remove_invalid_number
 * DESCRIPTION
 *  This function is used to remove invalid characters.
 * PARAMETERS
 *  number:             [IN/OUT]    PHB number
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_remove_invalid_number_ex(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *temp_number = number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*number)
    {
        if ((*number >= '0' && *number <= '9') ||
            (*number == '*' || *number == '+' || *number == '#') ||
            (*number == 'p' || *number == 'P' || *number == 'w' || *number == 'W' || *number == '?'))
        {
            if (*number == 'P')
            {
                *temp_number = 'p';
            }
            else if (*number == 'W')
            {
                *temp_number = 'w';
            }
            else
            {
                *temp_number = *number;
            }
            temp_number++;
        }
        number++;
    }
    *temp_number = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_remove_invalid_number
 * DESCRIPTION
 *  This function is used to remove invalid characters.
 * PARAMETERS
 *  number:             [IN/OUT]    PHB number
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_remove_invalid_number(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *temp_number = number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number == NULL)
    {
        return;
    }
    while (*number)
    {
        if ((*number >= '0' && *number <= '9') ||
            (*number == '*' || *number == '+' || *number == '#') ||
            (*number == 'p' || *number == 'P' || *number == 'w' || *number == 'W'))
        {
            if (*number == 'P')
            {
                *temp_number = 'p';
            }
            else if (*number == 'W')
            {
                *temp_number = 'w';
            }
            else
            {
                *temp_number = *number;
            }
            temp_number++;
        }
        number++;
    }
    *temp_number = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_number_asc_to_wcs
 * DESCRIPTION
 *  This function is used to remove invalid characters.
 * PARAMETERS
 *  number:             [IN/OUT]    PHB number
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_number_asc_to_wcs(mmi_phb_wcs_num_struct* dest, mmi_phb_asc_num_struct* src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src && dest)
    {
        mmi_asc_to_wcs((WCHAR*)dest->number, (CHAR*)src->number);
        dest->type = src->type;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_number_asc_to_wcs
 * DESCRIPTION
 *  This function is used to remove invalid characters.
 * PARAMETERS
 *  number:             [IN/OUT]    PHB number
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_number_wcs_to_asc(mmi_phb_asc_num_struct* dest, mmi_phb_wcs_num_struct* src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src && dest)
    {
        mmi_wcs_to_asc((CHAR*)dest->number, (WCHAR*)src->number);
        dest->type = src->type;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_free_link
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_phb_free_link(srv_phb_node_struct* head, srv_phb_node_struct* tail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_node_struct* temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_FREE_LINK, head, tail, tail->next);
    while (head)
    {
        temp = head;
        head = head->next;
        srv_phb_mem_free(temp);
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_OP_ADM_FREE, temp);
        if (temp == tail)
        {
            break;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  srv_phb_free_link_ex
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_phb_free_link_ex(srv_phb_node_struct* head, srv_phb_node_struct* tail, srv_phb_query_mem_entry_struct *mem_entry_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_node_struct* temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_FREE_LINK, head, tail, tail->next);
    while (head)
    {
        temp = head;
        head = head->next;
        // srv_phb_mem_free(temp);
        mem_entry_p->mem_free_func(temp, mem_entry_p->user_data);
        MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_OP_ASM_FREE, temp, mem_entry_p->user_data, mem_entry_p->mem_free_func);
        if (temp == tail)
        {
            break;
        }
    }
}


#ifdef __MMI_VCARD__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_number_type_to_vcard
 * DESCRIPTION
 *  convert phone book number type to vcard number type
 * PARAMETERS
 *  type       :  [IN] mmi_phb_num_type_enum
 * RETURNS
 *  vcard_tel_type_enum
 *****************************************************************************/
vcard_tel_type_enum srv_phb_convert_number_type_to_vcard(mmi_phb_num_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_PHB_NUM_TYPE_MOBILE:
            return VCARD_TEL_TYPE_CELL;
        case MMI_PHB_NUM_TYPE_HOME:
            return VCARD_TEL_TYPE_HOME;
        case MMI_PHB_NUM_TYPE_OFFICE:
            return VCARD_TEL_TYPE_WORK;
        case MMI_PHB_NUM_TYPE_FAX:
            return VCARD_TEL_TYPE_FAX;
        default:
            return VCARD_TEL_TYPE_TOTAL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_number_type_from_vcard
 * DESCRIPTION
 *  convert from vcard telephone type to phone book number type
 * PARAMETERS
 *  type       [IN]           
 * RETURNS
 *  vcard_tel_type_enum
 *****************************************************************************/
mmi_phb_num_type_enum srv_phb_convert_number_type_from_vcard(vcard_tel_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case VCARD_TEL_TYPE_HOME:
            return MMI_PHB_NUM_TYPE_HOME;
        case VCARD_TEL_TYPE_WORK:
            return MMI_PHB_NUM_TYPE_OFFICE;
        case VCARD_TEL_TYPE_FAX:
            return MMI_PHB_NUM_TYPE_FAX;
        case VCARD_TEL_TYPE_CELL:
        default:
            return MMI_PHB_NUM_TYPE_MOBILE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_email_type_to_vcard
 * DESCRIPTION
 *  convert phone book email type to vcard email type
 * PARAMETERS
 *  type       [IN]           
 * RETURNS
 *  vcard_email_type_enum
 *****************************************************************************/
vcard_email_type_enum srv_phb_convert_email_type_to_vcard(mmi_phb_email_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case MMI_PHB_EMAIL_TYPE_NONE:
            return VCARD_EMAIL_TYPE_INTERNET;
        case MMI_PHB_EMAIL_TYPE_HOME:
            return VCARD_EMAIL_TYPE_HOME;
        case MMI_PHB_EMAIL_TYPE_OFFICE:
            return VCARD_EMAIL_TYPE_WORK;
        default:
            return VCARD_EMAIL_TYPE_TOTAL;
}

}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_email_type_from_vcard
 * DESCRIPTION
 *  convert vcard email type to phone book email type
 * PARAMETERS
 *  type       [IN]           
 * RETURNS
 *  mmi_phb_email_type_enum
 *****************************************************************************/
mmi_phb_email_type_enum srv_phb_convert_email_type_from_vcard(vcard_email_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case VCARD_EMAIL_TYPE_HOME:
            return MMI_PHB_EMAIL_TYPE_HOME;
        case VCARD_EMAIL_TYPE_WORK:
        default:
            return MMI_PHB_EMAIL_TYPE_OFFICE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_image_type_to_vcard
 * DESCRIPTION
 *  convert file image type to vcard photo type
 * PARAMETERS
 *  type       [IN]           
 * RETURNS
 *  vcard_photo_type_enum
 *****************************************************************************/
vcard_photo_type_enum srv_phb_convert_image_type_to_vcard(mmi_fmgr_filetype_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (type)
    {
        case FMGR_TYPE_BMP:
            return VCARD_PHOTO_TYPE_BMP;
    
    #if defined(__GDI_MEMORY_PROFILE_2__)
        case FMGR_TYPE_JPG:
            return VCARD_PHOTO_TYPE_JPG;
    
        case FMGR_TYPE_JPEG:
            return VCARD_PHOTO_TYPE_JPEG;
    #endif /* defined(__GDI_MEMORY_PROFILE_2__) */
    
        case FMGR_TYPE_GIF:
            return VCARD_PHOTO_TYPE_GIF;
    
    #if defined(GDI_USING_PNG)
        case FMGR_TYPE_PNG:
            return VCARD_PHOTO_TYPE_PNG;
    #endif /* defined(GDI_USING_PNG) */
    
        case FMGR_TYPE_WBMP:
            return VCARD_PHOTO_TYPE_WBMP;
    
        case FMGR_TYPE_WBM:
            return VCARD_PHOTO_TYPE_WBM;
    
        default:
            return VCARD_PHOTO_TYPE_TOTAL;
    }
}
#endif /* __MMI_VCARD__ */

