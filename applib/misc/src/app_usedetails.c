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
 * app_usedetails.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains function to extract address info, ex: Email, URL and phonenumber.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _APP_USEDETAILS_C
#define _APP_USEDETAILS_C

/***************************************************************************** 
* Include
*****************************************************************************/
//#include "kal_release.h"
//#include "kal_non_specific_general_types.h"
#include "string.h"
#include "app_usedetails.h"
#include "app_str.h"
#include "app_url.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ps_public_utility.h"
#include "global_def.h"
#include "mmi_frm_mem_gprot.h"
#include "unicodexdcl.h"

extern kal_uint8 custom_wild_char(void);
extern kal_uint8 custom_auto_dtmf_modifier(void);
kal_bool l4_custom_is_phb_valid_char(kal_uint8 ch);
applib_address_node_struct *applib_parse_email_from_text_unicode(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        kal_wchar *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate);

applib_address_node_struct *applib_parse_phoneno_from_text_unicode(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        kal_wchar *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate);

applib_address_node_struct *applib_parse_ussd_string_from_text_unicode(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        kal_wchar *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate);

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

/***************************************************************************** 
* Global Variable
*****************************************************************************/

/***************************************************************************** 
* Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_phoneno_char
 * DESCRIPTION
 *  This internal function is used to check if input char is valid phone number character
 * PARAMETERS
 *  ch		[IN]	character being checked
 *  is_written_char_valid [IN] count written char,ex. '-','(',')', as valid char
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_valid_phoneno_char(char ch, kal_bool is_written_char_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char phoneno_special_chars[] = {'+','w','p','P','W'};
    char phoneno_written_chars[] = {'-','(',')'};

    kal_int32 num_phoneno_special_chars = sizeof(phoneno_special_chars);
    kal_int32 num_phoneno_written_chars = sizeof(phoneno_written_chars);
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (ch != NULL)
    {
        if (ch >= '0' && ch <= '9')
        {
            return KAL_TRUE;
        }

        for (i = 0; i < num_phoneno_special_chars; i++)
        {
            if (ch == phoneno_special_chars[i])
            {
                return KAL_TRUE;
            }
        }

        if (is_written_char_valid == KAL_TRUE)
        {
            for (i = 0; i < num_phoneno_written_chars; i++)
            {
                if (ch == phoneno_written_chars[i])
                {
                    return KAL_TRUE;
                }
            }
        }

        return KAL_FALSE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_phoneno_wchar
 * DESCRIPTION
 *  This internal function is used to check if input char is valid phone number character
 * PARAMETERS
 *  ch		[IN]	character being checked
 *  is_written_char_valid [IN] count written char,ex. '-','(',')', as valid char
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_valid_phoneno_wchar(kal_wchar ch, kal_bool is_written_char_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar phoneno_special_chars[] = {L'+',L'w',L'p',L'W',L'P'};
    kal_wchar phoneno_written_chars[] = {L'-',L'(',L')'};

    kal_int32 num_phoneno_special_chars = (sizeof(phoneno_special_chars)/2);
    kal_int32 num_phoneno_written_chars = (sizeof(phoneno_written_chars)/2);
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (ch != NULL)
    {
        if (ch >= L'0' && ch <= L'9')
        {
            return KAL_TRUE;
        }

        for (i = 0; i < num_phoneno_special_chars; i++)
        {
            if (ch == phoneno_special_chars[i])
            {
                return KAL_TRUE;
            }
        }

        if (is_written_char_valid == KAL_TRUE)
        {
            for (i = 0; i < num_phoneno_written_chars; i++)
            {
                if (ch == phoneno_written_chars[i])
                {
                    return KAL_TRUE;
                }
            }
        }

        return KAL_FALSE;
    }
    else
    {
        return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_local_part_char
 * DESCRIPTION
 *  This internal function is used to check if input char is valid Email local part character
  * PARAMETERS
 *  ch		[IN]	character being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_valid_email_local_part_char(char ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ch >= 'a' && ch <= 'z') ||
        (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
    {
        return KAL_TRUE;
    }
    switch (ch)
    {
        /* Reference RFC 2822 */
        case '.':
        case '!':
        case '#':
        case '$':
        case '%':
        case '&':
        case '\'':
        case '*':
        case '+':
        case '-':
        case '/':
        case '=':
        case '?':
        case '^':
        case '_':
        case '`':
        case '{':
        case '|':
        case '}':
        case '~':
            return KAL_TRUE;
        default:
            return KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_local_part_char
 * DESCRIPTION
 *  This internal function is used to check if input char is valid Email local part character
  * PARAMETERS
 *  ch		[IN]	character being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_valid_email_local_part_wchar(kal_wchar ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ch >= L'a' && ch <= L'z') ||
        (ch >= L'A' && ch <= L'Z') || (ch >= L'0' && ch <= L'9'))
    {
        return KAL_TRUE;
    }
    switch (ch)
    {
        /* Reference RFC 2822 */
        case L'.':
        case L'!':
        case L'#':
        case L'$':
        case L'%':
        case L'&':
        case L'\'':
        case L'*':
        case L'+':
        case L'-':
        case L'/':
        case L'=':
        case L'?':
        case L'^':
        case L'_':
        case L'`':
        case L'{':
        case L'|':
        case L'}':
        case L'~':
            return KAL_TRUE;
        default:
            return KAL_FALSE;
    }
}
/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_local_part
 * DESCRIPTION
 *  This function is to check if the input ASCII str can be Email local part
  * PARAMETERS
 *  str		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_is_valid_email_local_part(const char *str, int cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    char ch = '\0';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnt == 0)
    {
        return KAL_FALSE;
    }
 
    for (i = 0; i < cnt; i++)
    {
        ch = *(str + i);
        if (applib_is_valid_email_local_part_char(ch) == KAL_FALSE)
        {
            return KAL_FALSE;
        }
    }

    if (*str == '.' || ch == '.')  /* '.' should not be the first or last character in the local-part */
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_local_part_unicode
 * DESCRIPTION
 *  This function is to check if the input UCS2 str can be Email local part
  * PARAMETERS
 *  str		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_is_valid_email_local_part_unicode(const kal_wchar *str, int cnt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    kal_wchar ch = L'\0';

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cnt == 0)
    {
        return KAL_FALSE;
    }
 
    for (i = 0; i < cnt; i++)
    {
        ch = *(str + i);
        if (applib_is_valid_email_local_part_wchar(ch) == KAL_FALSE)
        {
            return KAL_FALSE;
        }
    }

    if (*str == L'.' || ch == L'.')  /* '.' should not be the first or last character in the local-part */
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_domain_name_char
 * DESCRIPTION
 *  This internal function is used to check if input char is valid Email character
  * PARAMETERS
 *  ch		[IN]	character being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_valid_email_domain_name_char(char ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!((ch >= 'a' && ch <= 'z') ||
          (ch >= 'A' && ch <= 'Z') ||
          (ch >= '0' && ch <= '9') || (ch == '-') || (ch == '.')))
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_domain_name_wchar
 * DESCRIPTION
 *  This internal function is used to check if input char is valid Email character
  * PARAMETERS
 *  ch		[IN]	character being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_valid_email_domain_name_wchar(kal_wchar ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (!((ch >= L'a' && ch <= L'z') ||
          (ch >= L'A' && ch <= L'Z') ||
          (ch >= L'0' && ch <= L'9') || (ch == L'-') || (ch == L'.')))
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_domain_name
 * DESCRIPTION
 *  This function is to check if the input ASCII str can be Email domain name part
  * PARAMETERS
 *  str		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_is_valid_email_domain_name(const char *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: We only do very preliminary test here. It need a lot of improvement
    if (*str == '\0')
    {
        return KAL_FALSE;
    }
    
    do
    {
        if (applib_is_valid_email_domain_name_char(*str) == KAL_FALSE)
        {
            return KAL_FALSE;
        }
        str++;
    }
    while (*str != '\0');

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_domain_name_unicode
 * DESCRIPTION
 *  This function is to check if the input ASCII str can be Email domain name part
  * PARAMETERS
 *  str		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_is_valid_email_domain_name_unicode(const kal_wchar *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: We only do very preliminary test here. It need a lot of improvement
    if (*str == L'\0')
    {
        return KAL_FALSE;
    }
    
    do
    {
        if (applib_is_valid_email_domain_name_wchar(*str) == KAL_FALSE)
        {
            return KAL_FALSE;
        }
        str++;
    }
    while (*str != L'\0');

    return KAL_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  applib_is_lp_paired
 * DESCRIPTION
 *  This internal function is used to check if the left parenthesis '(' is paired with
 *  a right parenthesis ')'
 * PARAMETERS
 *  lp_pos		[IN]	left parenthesis position
 *  length      [IN]    the string length to check (string started with the lp)
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_lp_paired(const char *lp_pos, kal_int32 length)
{
    const char *ch = lp_pos;
    int lp_count = 0;
    
    while (length > 0)
    {
        if (*ch == '(')
        {
            lp_count++;
        }
        else if (*ch == ')')
        {
            lp_count--;
        }
        length--;
        ch++;
    }
    return ((lp_count == 0) ? KAL_TRUE : KAL_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_lp_paired_wchar
 * DESCRIPTION
 *  This internal function is used to check if the left parenthesis '(' is paired with
 *  a right parenthesis ')'
 * PARAMETERS
 *  lp_pos		[IN]	left parenthesis position
 *  length      [IN]    the string length to check (string started with the lp)
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_lp_paired_wchar(const kal_wchar *lp_pos, kal_int32 length)
{
    const kal_wchar *ch = lp_pos;
    int lp_count = 0;
    
    while (length > 0)
    {
        if (*ch == L'(')
        {
            lp_count++;
        }
        else if (*ch == L')')
        {
            lp_count--;
        }
        length--;
        ch++;
    }
    return ((lp_count == 0) ? KAL_TRUE : KAL_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  applib_duplicate_phoneno_no_written_sep
 * DESCRIPTION
 *  This function is used to duplicate a phone number.
 *  The duplicate contains only digit and '+', 'w', 'p' characters, that is, skipping '(', ')', '-', '.', etc.
 * PARAMETERS
 *  mem_alloc_fn    [IN]	Memory allication function
 *  str		[IN]	Input phone number string
 * RETURNS
 *  phone number string
 *****************************************************************************/
static char *applib_duplicate_phoneno_no_written_sep(applib_mem_alloc_fn mem_alloc_fn, char *str)
{
    char *number = NULL;
    char *ptr = NULL;
    kal_int32 dest_len = 0;

    if (str == NULL)
    {
        return NULL;
    }

    number = mem_alloc_fn(strlen(str) + 1);
    ptr = str;
    while (*ptr != '\0')
    {
        if (applib_is_valid_phoneno_char(*ptr, KAL_FALSE) == KAL_TRUE)
        {
            number[dest_len++] = *ptr;
        }
        ptr++;
    }
    number[dest_len] = '\0';
    return number;
}

/*****************************************************************************
 * FUNCTION
 *  applib_duplicate_phoneno_no_written_sep
 * DESCRIPTION
 *  This function is used to duplicate a phone number.
 *  The duplicate contains only digit and '+', 'w', 'p' characters, that is, skipping '(', ')', '-', '.', etc.
 * PARAMETERS
 *  mem_alloc_fn    [IN]	Memory allication function
 *  str		[IN]	Input phone number string
 * RETURNS
 *  phone number string
 *****************************************************************************/
static kal_wchar *applib_duplicate_phoneno_no_unicode_written_sep(applib_mem_alloc_fn mem_alloc_fn, kal_wchar *str)
{
    kal_wchar *number = NULL;
    kal_wchar *ptr = NULL;
    kal_int32 dest_len = 0;

    if (str == NULL)
    {
        return NULL;
    }

    number = mem_alloc_fn(app_ucs2_strlen((kal_int8*)str)*2 + 2);
    ptr = str;
    while (*ptr != L'\0')
    {
        if (applib_is_valid_phoneno_wchar(*ptr, KAL_FALSE) == KAL_TRUE)
        {
            number[dest_len++] = *ptr;
        }
        ptr++;
    }
    number[dest_len] = L'\0';
    return number;
}


/*****************************************************************************
 * FUNCTION
 *  applib_parse_email_from_text
 * DESCRIPTION
 *  This internal function is used to get specific addresses from one UTF8-encoded text.
 *  The list is in reverse order.
 * PARAMETERS
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  check_stop_fn   [IN]    Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data
 *  is_stopped      [IN/OUT]Specify if parsing procedure being stopped by user
 *  is_remove_duplicate [IN] Remove duplicate address or not. 
 
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_parse_email_from_text(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        char *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate)
{
    char *unicode_data;
	applib_address_node_struct *address_list = NULL;
	
    if (input_data == NULL || dataLen == 0)
    {
        return NULL;
    }
    unicode_data = (char*)mmi_frm_asm_alloc_anonymous(2*(dataLen+1));
    mmi_asc_n_to_ucs2(unicode_data,(char*)input_data,dataLen);
    address_list = applib_parse_email_from_text_unicode(mem_alloc_fn,
										mem_free_fn,
										check_stop_fn,
										(kal_wchar*)unicode_data,
										dataLen,
										is_stopped,
										is_remove_duplicate);
    mmi_frm_asm_free_anonymous(unicode_data);
	return address_list;
}


/*****************************************************************************
 * FUNCTION
 *  applib_parse_email_from_text_unicode
 * DESCRIPTION
 *  This internal function is used to get specific addresses from one UTF8-encoded text.
 *  The list is in reverse order.
 * PARAMETERS
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  check_stop_fn   [IN]    Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data
 *  is_stopped      [IN/OUT]Specify if parsing procedure being stopped by user
 *  is_remove_duplicate [IN] Remove duplicate address or not. 
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_parse_email_from_text_unicode(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        kal_wchar *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    applib_address_node_struct *address_list = NULL;  
    int len = 0, parsed_no = 0;
    kal_wchar *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mem_alloc_fn == NULL || 
	 mem_free_fn == NULL || 
	 input_data == NULL || 
	 dataLen == 0 ||
	 *is_stopped == KAL_TRUE)
    {
        return NULL;
    }

    /*UCS2 character number*/
    dataLen = dataLen / 2;

    data = input_data;
    len = dataLen;
    while (data - input_data < dataLen)
    {
        kal_wchar *start = NULL;
        kal_wchar *end = NULL;

        start = kal_wstrchr(data, L'@');
        end = start + app_ucs2_strlen((kal_int8*)L"@");    
        if (start == NULL)  /* not found */
        {
            return address_list;
        }
        else if (start == data || applib_is_valid_email_local_part_wchar(*(start - 1)) == KAL_FALSE || 
            *(start - 1) == L'.')  /* '.' should not be the last character in the local-part */
        {
            data = start + app_ucs2_strlen((kal_int8*)L"@");  /* continue from the end of the pattern */
            len = dataLen - (data - input_data);
            continue;
        }
        else
        {
            while((start - 1 >= data) && applib_is_valid_email_local_part_wchar(*(start - 1)))
            {
                start--;
            }
            ASSERT(start >= data);

            while (*start == L'.')  /* '.' should not be the first character in the local-part */
            {
                start++;
            }
            
            /*we get the begining of URL string and go to find its end*/
            while ((end - data) < len &&  applib_is_valid_email_domain_name_wchar(*end))
            {
                end++;
            }
            while (*(end - 1) == L'.')  /* removing trailing dot(s)*/
            {
                end--;
            }

            if (end == app_ucs2_strstr(data, L"@") + app_ucs2_strlen((kal_int8*)L"@"))  /* host string is NULL */
            {
                if ((end - data) < len)
                {
                    data = end;  /* continue from the following char */
                    len = dataLen - (end - input_data);
                    continue;
                }
                else
                {
                    return address_list;
                }
            }
            else if ((end - data) <= len)
            {
                kal_wchar tmp = *end;
                applib_address_node_struct *address = NULL;
                kal_bool is_duplicated;

                *end = L'\0';
                is_duplicated = KAL_FALSE;
                if (is_remove_duplicate)
                {
                    address = address_list;
                    while (address != NULL)
                    {
                        if (app_ucs2_wcsicmp((kal_wchar*)address->data, (kal_wchar*)start) == 0)
                        {
                            is_duplicated = KAL_TRUE;
                            break;
                        }
                        address = address->next;
                    }
                }

                if (!is_remove_duplicate || !is_duplicated)
                {
                    address = (applib_address_node_struct*)mem_alloc_fn(sizeof(applib_address_node_struct));
                    if (address == NULL)
                    {
                        return address_list;
                    }
                    address->data = NULL;
                    address->dataType = APPLIB_ADDR_TYPE_EMAIL;
                    address->pos = (kal_uint32)start;
                    address->length = app_ucs2_strlen((kal_int8*)start)*2;
                    address->data = (kal_wchar *)mem_alloc_fn(address->length + 2);
                    if (address->data == NULL)
                    {
                        mem_free_fn(address);
                        return address_list;
                    }
                    app_ucs2_strcpy((kal_int8*)(address->data), (kal_int8*)start);
                    address->data2 = NULL;

                    address->next = address_list;                    
                    address_list = address;

                    parsed_no++;
                    if (check_stop_fn != NULL && 
                        check_stop_fn(APPLIB_ADDR_TYPE_EMAIL, address, parsed_no) == KAL_TRUE)
                    {
                        *end = tmp;
                        *is_stopped = KAL_TRUE;
                        return address_list;
                    }
                }
                *end = tmp;
                data = end;  /* continue from the following char */
                len = dataLen - (end - input_data);
                continue;
            }
            else
            {
                return address_list;
            }
        }
    }
    return address_list;
}

/*****************************************************************************
 * FUNCTION
 *  applib_parse_phoneno_from_text
 * DESCRIPTION
 *  This internal function is used to get specific addresses from one UTF8-encoded text.
 *  The list is in reverse order.
 * PARAMETERS
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  check_stop_fn   [IN]    Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data
 *  is_stopped      [IN/OUT]Specify if parsing procedure being stopped by user
 *  is_remove_duplicate [IN] Remove duplicate address or not. 
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_parse_phoneno_from_text(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        char *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate)
{
			char *unicode_data;
			applib_address_node_struct *address_list = 0;
			
			if (input_data == NULL || dataLen == 0)
			{
				return NULL;
			}
			unicode_data = (char*)mmi_frm_asm_alloc_anonymous(2*(dataLen+1));
			mmi_asc_n_to_ucs2(unicode_data,(char*)input_data,dataLen);
			address_list = applib_parse_phoneno_from_text_unicode(mem_alloc_fn,
												mem_free_fn,
												check_stop_fn,
												(kal_wchar*)unicode_data,
												dataLen,
												is_stopped,
												is_remove_duplicate);
			mmi_frm_asm_free_anonymous(unicode_data);
			return address_list;
}
/*****************************************************************************
 * FUNCTION
 *  applib_parse_phoneno_from_text
 * DESCRIPTION
 *  This internal function is used to get specific addresses from one UTF8-encoded text.
 *  The list is in reverse order.
 * PARAMETERS
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  check_stop_fn   [IN]    Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data
 *  is_stopped      [IN/OUT]Specify if parsing procedure being stopped by user
 *  is_remove_duplicate [IN] Remove duplicate address or not. 
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_parse_phoneno_from_text_unicode(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        kal_wchar *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    applib_address_node_struct *address_list = NULL;  
    int len = 0, parsed_no = 0;
    kal_wchar *data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mem_alloc_fn == NULL || 
	 mem_free_fn == NULL || 
	 input_data == NULL || 
	 dataLen == 0 ||
	 *is_stopped == KAL_TRUE)
    {
        return NULL;
    }

    /*UCS2 character number*/
    dataLen = dataLen / 2;
    
    data = input_data;
    len = dataLen;
    while (data - input_data < dataLen)
    {
        kal_int32 i = 0, no_length = 0, str_length = 0;
        kal_wchar *start = data;
        kal_wchar *end = start;
        kal_bool space_allowed = KAL_FALSE;


        for(i = 0; i < len; i++)
        {
            if(*end == L'+')
            {
                space_allowed = KAL_TRUE;

                if(no_length == 0)
                {
                    no_length++;
                    str_length++;
                }
                else
                {         
                    break;  /* search stop */
                }
            }
            else if((*end >= L'0') && (*end <= L'9'))
            {
                space_allowed = KAL_TRUE;

                if(no_length > APPLIB_MAX_PHONE_NUM_LEN)  /* Phone number is too long */
                {
                    break;  /* search stop */
                }
                no_length++;
                str_length++;
            }
            else if((*end == L'(') || (*end == L')') || (*end == L'-'))
            {
                space_allowed = KAL_TRUE;

                str_length++;
                /* part of the number but not add to length */
            }
            else if((*end == L' ') && (space_allowed == KAL_TRUE))
            {
                space_allowed = KAL_FALSE;
                str_length++;
            }
            else if((*end == L'w') || (*end == L'p') || (*end == L'W') || (*end == L'P'))
            {
                space_allowed = KAL_TRUE;

                if(no_length == 0)
                {
                }
                else
                {
                    if(no_length > APPLIB_MAX_PHONE_NUM_LEN)  /* Phone number is too long */
                    {
                        break;  /* search stop */
                    }
                    no_length++;
                    str_length++;
                }
            }
            else
            {
                if(str_length > 0)
                {
                    break;	
                }
            }		

            end += 1;
            if (str_length == 0)
            {
                start = end;
            }
        }

        /* remove invalid trailing char */
        while (no_length >= APPLIB_MIN_PHONE_NUM_LEN && (*(end - 1) == L'w' || *(end - 1) == L'p' || 
            *(end - 1) == L'W' || *(end - 1) == L'P' || *(end - 1) == L'(' || *(end - 1) == L')' || *(end - 1) == L'-' || *(end - 1) == L' '))
        {
            if (*(end - 1) == L'w' || *(end - 1) == L'p' || *(end - 1) == L'W' || *(end - 1) == L'P')
            {
                no_length -= 1;
            }
            str_length -= 1;
            end -= 1;
        }
        
        /* remove invalid heading char */
        while (no_length >= APPLIB_MIN_PHONE_NUM_LEN && (*start == L'-' || *start == L')' ||
            (*start == '(' && applib_is_lp_paired_wchar(start, str_length) == KAL_FALSE)))
        {
            str_length -= 1;
            start += 1;
        }

        /* The number sequence is too long to be a valid PLMN number */
        if (( *start != '+'  && no_length >= APPLIB_MAX_PHONE_NUM_LEN) ||
            ( *start == '+'  && no_length > APPLIB_MAX_PHONE_NUM_LEN))  
        {
            while(applib_is_valid_phoneno_wchar(*end++, KAL_TRUE) == KAL_TRUE);
            data = end;  /* continue from the following char */
            len = dataLen - (end - input_data);
            continue;
        }
        else if (( *start != '+'  && no_length >= APPLIB_MIN_PHONE_NUM_LEN) ||
            ( *start == '+'  && no_length > APPLIB_MIN_PHONE_NUM_LEN))

        {
	     applib_address_node_struct *address = NULL;
            kal_wchar tmp = *end;
            kal_bool is_duplicated = KAL_FALSE;

            *end = L'\0';

            if (is_remove_duplicate)
            {
                address = address_list;
                while (address != NULL)
                {
                    if (app_ucs2_wcsicmp((kal_wchar*)address->data, (kal_wchar*)start) == 0)
                    {
                        is_duplicated = KAL_TRUE;
                        break;
                    }
                    address = address->next;
                }
            }

            if (is_remove_duplicate == KAL_FALSE || is_duplicated == KAL_FALSE)
            {
                address = (applib_address_node_struct*)mem_alloc_fn(sizeof(applib_address_node_struct));
                if (address == NULL)
    	         {
                    return address_list;
            	  }
                address->data = NULL;
                address->dataType = APPLIB_ADDR_TYPE_PHONENUMBER;
                address->pos = (kal_uint32)start;
                address->length = app_ucs2_strlen((kal_int8*)start)*2;
                address->next = address_list;
                address->data = (kal_wchar *)mem_alloc_fn(address->length + 2);
                app_ucs2_strcpy((kal_int8*)(address->data), (kal_int8*)start);
                address->data2 = applib_duplicate_phoneno_no_unicode_written_sep(mem_alloc_fn, address->data);
                *end = tmp;

                address_list = address;
                data = end;  /* continue from the following char */
                len = dataLen - (end - input_data);
                parsed_no++;
                if (check_stop_fn != NULL && 
                    check_stop_fn(APPLIB_ADDR_TYPE_PHONENUMBER, address, parsed_no) == KAL_TRUE)
                {
                    *is_stopped = KAL_TRUE;
                    return address_list;
                }
                continue;
            }
            else /* the format is valid, but it is duplicated number*/
            {
                *end = tmp;
                data = end;  /* continue from the following char */
                len = dataLen - (end - input_data);
                continue;
            }
        }
        else
        {
            data = end;  /* continue from the following char */
            len = dataLen - (end - input_data);
            continue;
        }
    }
    return address_list;
}

/*****************************************************************************
 * FUNCTION
 *  applib_parse_ussd_string_from_text
 * DESCRIPTION
 *  This internal function is used to get specific addresses from one UTF8-encoded text.
 *  The list is in reverse order.
 * PARAMETERS
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  check_stop_fn   [IN]    Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data
 *  is_stopped      [IN/OUT]Specify if parsing procedure being stopped by user
 *  is_remove_duplicate [IN] Remove duplicate address or not. 
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_parse_ussd_string_from_text(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        char *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate)
{
		char *unicode_data;
		applib_address_node_struct *address_list = 0;
		
		if (input_data == NULL || dataLen == 0)
		{
			return NULL;
		}
		unicode_data = (char*)mmi_frm_asm_alloc_anonymous(2*(dataLen+1));
		mmi_asc_n_to_ucs2(unicode_data,(char*)input_data,dataLen);
		address_list = applib_parse_ussd_string_from_text_unicode(mem_alloc_fn,
											 mem_free_fn,
											 check_stop_fn,
											 (kal_wchar*)unicode_data,
											 dataLen,
											 is_stopped,
											 is_remove_duplicate);
		mmi_frm_asm_free_anonymous(unicode_data);
	return address_list;
}

/*****************************************************************************
 * FUNCTION
 *  applib_parse_ussd_string_from_text_unicode
 * DESCRIPTION
 *  This internal function is used to get specific addresses from one UTF8-encoded text.
 *  The list is in reverse order.
 * PARAMETERS
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  check_stop_fn   [IN]    Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data
 *  is_stopped      [IN/OUT]Specify if parsing procedure being stopped by user
 *  is_remove_duplicate [IN] Remove duplicate address or not. 
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_parse_ussd_string_from_text_unicode(
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        applib_check_stop_fn check_stop_fn,
        kal_wchar *input_data, 
        kal_int32 dataLen,
        kal_bool *is_stopped,
        kal_bool is_remove_duplicate)
{  
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    applib_address_node_struct *address_list = NULL;  
    int len = 0, parsed_no = 0;
    kal_wchar *data = NULL;
    kal_wchar tmp;
    kal_bool is_duplicated;
    kal_bool is_ss_string;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (mem_alloc_fn == NULL || 
	 mem_free_fn == NULL || 
	 input_data == NULL || 
	 dataLen == 0 ||
	 *is_stopped == KAL_TRUE)
    {
        return NULL;
    }

    /*UCS2 character number*/
    dataLen = dataLen / 2;
    data = input_data;
    len = dataLen;
    while (data - input_data < dataLen)
    {
        kal_int32 i = 0, no_length = 0, str_length = 0;
        kal_wchar *start = data;
        kal_wchar *end = start;

        for(i = 0; i < len; i++)
        {
            if(((*end >= L'0') && (*end <= L'9')) || (*end == L'*') || (*end == L'#')  || (*end == L'+') )
            {
                no_length++;
                str_length++;
            }
            else
            {
                if(str_length > 0)
                {
                    break;	
                }
            }		

            end += 1;
            if (str_length == 0)
            {
                start = end;
            }
        }

        /* SS_OPERATION: 1 */
		is_ss_string = KAL_FALSE;
        for (i=0; i<MAX_SIM_NUM; i++)
        {
            if (applib_ss_string_parsing_unicode((kal_wchar *)start, (kal_uint8)(end - start), i, KAL_FALSE) == 1)
            {
                is_ss_string = KAL_TRUE;
            }
        }
        
        /*
        if((applib_ss_string_parsing_unicode((kal_wchar *)start, (kal_uint8)(end - start), 0, KAL_FALSE) == 1) ||
            (applib_ss_string_parsing_unicode((kal_wchar *)start, (kal_uint8)(end - start), 1, KAL_FALSE) == 1))
        */
        if (is_ss_string == KAL_TRUE)
        {
            applib_address_node_struct *address = NULL;
            tmp = *end;
            is_duplicated = KAL_FALSE;

            *end = L'\0';

            if (is_remove_duplicate)
            {
                address = address_list;
                while (address != NULL)
                {
                    if (app_ucs2_wcsicmp((kal_wchar*)address->data, (kal_wchar*)start) == 0)
                    {
                        is_duplicated = KAL_TRUE;
                        break;
                    }
                    address = address->next;
                }
            }

            if (is_remove_duplicate == KAL_FALSE || is_duplicated == KAL_FALSE)
            {
                address = (applib_address_node_struct*)mem_alloc_fn(sizeof(applib_address_node_struct));
                if (address == NULL)
    	         {
                    return address_list;
            	  }

                address->data = NULL;
                address->dataType = APPLIB_ADDR_TYPE_USSD;
                address->pos = (kal_uint32)start;
                address->length = app_ucs2_strlen((kal_int8*)start)*2;
                address->next = address_list;
                address->data = (kal_wchar *)mem_alloc_fn(address->length + 2);
                app_ucs2_strcpy((kal_int8*)(address->data), (kal_int8*)start);
                address->data2 = (kal_wchar *)mem_alloc_fn(address->length + 2);
                app_ucs2_strcpy((kal_int8*)(address->data2), (kal_int8*)start);
                *end = tmp;

                address_list = address;
                data = end;  /* continue from the following char */
                len = dataLen - (end - input_data);
                parsed_no++;
                if (check_stop_fn != NULL && 
                    check_stop_fn(APPLIB_ADDR_TYPE_USSD, address, parsed_no) == KAL_TRUE)
                {
                    *is_stopped = KAL_TRUE;
                    return address_list;
                }
            }
            else
            {
                *end = tmp;
                data = end;  /* continue from the following char */
                len = dataLen - (end - input_data);
            }
        }
        else
        {
            data = end;  /* continue from the following char */
            len = dataLen - (end - input_data);
        }
    }
    return address_list;
}


/*****************************************************************************
 * FUNCTION
 *  applib_remove_overlapped_address
 * DESCRIPTION
 *  This function is used to remove overlapped addresses
 * PARAMETERS
 *  addr_list		[IN]	Address list being checked
 *  mem_free_fn		[IN]	Memory free function
 * RETURNS
 *  None
 *****************************************************************************/
static void applib_remove_overlapped_address(applib_address_node_struct **addr_list, applib_mem_free_fn mem_free_fn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *addr_list_tp1 = NULL;
    applib_address_node_struct *addr_list_tp2 = NULL;
    applib_address_node_struct *addr_list_tp2_prv = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_list == NULL || *addr_list == NULL)
    {
        return;
    }

    addr_list_tp1 = *addr_list;
    addr_list_tp2 = *addr_list;
    
    while(addr_list_tp1 != NULL)
    {
        addr_list_tp2 = *addr_list;
        addr_list_tp2_prv = NULL;

        while(addr_list_tp2 != NULL)
        {
            kal_bool remove = KAL_FALSE;
            if (addr_list_tp1->dataType != addr_list_tp2->dataType)   /* check different link type */
            {
                if (addr_list_tp1->pos <= addr_list_tp2->pos && 
                    addr_list_tp1->pos + addr_list_tp1->length >= addr_list_tp2->pos)
                {
                    remove = KAL_TRUE;
                }
            }

            if (remove)
            {
                applib_address_node_struct *tmp = addr_list_tp2;
                if (addr_list_tp2 == *addr_list)
                {
                    *addr_list = (*addr_list)->next;
                    addr_list_tp2 = *addr_list;
                }
                else
                {
                    addr_list_tp2 = addr_list_tp2->next;
                    if (addr_list_tp2_prv != NULL)
                    {
                        addr_list_tp2_prv->next = addr_list_tp2;
                    }
                }

                if (tmp->data)
                {
                    mem_free_fn(tmp->data);
                }
                
                if (tmp->data2)
                {
                    mem_free_fn(tmp->data2);
                }
                mem_free_fn(tmp);
            }
            else
            {
                addr_list_tp2_prv = addr_list_tp2;
                addr_list_tp2 = addr_list_tp2->next;
            }
        }
        addr_list_tp1 = addr_list_tp1->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_remove_duplicate_unicode_address
 * DESCRIPTION
 *  This function is used to remove duplicate unicode addresses
 * PARAMETERS
 *  addr_list		[IN]	Address list being checked
 *  mem_free_fn		[IN]	Memory free function
 * RETURNS
 *  None
 *****************************************************************************/
void applib_remove_duplicate_unicode_address(applib_address_node_struct **addr_list, applib_mem_free_fn mem_free_fn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *addr_list_tp1 = NULL;
    applib_address_node_struct *addr_list_tp2 = NULL;
    applib_address_node_struct *addr_list_tp2_prv = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_list == NULL || *addr_list == NULL)
    {
        return;
    }

    addr_list_tp1 = *addr_list;
    addr_list_tp2 = *addr_list;
    
    while(addr_list_tp1 != NULL)
    {
        addr_list_tp2 = *addr_list;
        addr_list_tp2_prv = NULL;

        while(addr_list_tp2 != NULL)
        {
            kal_bool remove = KAL_FALSE;
            if (addr_list_tp1 == addr_list_tp2)
            {
            }
            else if (addr_list_tp1->dataType == addr_list_tp2->dataType)   /* For the same link type, remove duplicated links */
            {
                if (app_ucs2_wcsicmp((kal_wchar*)addr_list_tp1->data, (kal_wchar*)addr_list_tp2->data) == 0)
                {
                    remove = KAL_TRUE;
                }
            }

            if (remove)
            {
                applib_address_node_struct *tmp = addr_list_tp2;
                if (addr_list_tp2 == *addr_list)
                {
                    *addr_list = (*addr_list)->next;
                    addr_list_tp2 = *addr_list;
                }
                else
                {
                    addr_list_tp2 = addr_list_tp2->next;
                    if (addr_list_tp2_prv != NULL)
                    {
                        addr_list_tp2_prv->next = addr_list_tp2;
                    }
                }

                if (tmp->data)
                {
                    mem_free_fn(tmp->data);
                }

                if (tmp->data2)
                {
                    mem_free_fn(tmp->data2);
                }
                mem_free_fn(tmp);
            }
            else
            {
                addr_list_tp2_prv = addr_list_tp2;
                addr_list_tp2 = addr_list_tp2->next;
            }
        }
        addr_list_tp1 = addr_list_tp1->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_remove_duplicate_address
 * DESCRIPTION
 *  This function is used to remove duplicate addresses
 * PARAMETERS
 *  addr_list		[IN]	Address list being checked
 *  mem_free_fn		[IN]	Memory free function
 * RETURNS
 *  None
 *****************************************************************************/
void applib_remove_duplicate_address(applib_address_node_struct **addr_list, applib_mem_free_fn mem_free_fn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *addr_list_tp1 = NULL;
    applib_address_node_struct *addr_list_tp2 = NULL;
    applib_address_node_struct *addr_list_tp2_prv = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (addr_list == NULL || *addr_list == NULL)
    {
        return;
    }

    addr_list_tp1 = *addr_list;
    addr_list_tp2 = *addr_list;
    
    while(addr_list_tp1 != NULL)
    {
        addr_list_tp2 = *addr_list;
        addr_list_tp2_prv = NULL;

        while(addr_list_tp2 != NULL)
        {
            kal_bool remove = KAL_FALSE;
            if (addr_list_tp1 == addr_list_tp2)
            {
            }
            else if (addr_list_tp1->dataType == addr_list_tp2->dataType)   /* For the same link type, remove duplicated links */
            {
                if (app_stricmp((kal_char *)(addr_list_tp1->data), (kal_char *)(addr_list_tp2->data)) == 0)
                {
                    remove = KAL_TRUE;
                }
            }

            if (remove)
            {
                applib_address_node_struct *tmp = addr_list_tp2;
                if (addr_list_tp2 == *addr_list)
                {
                    *addr_list = (*addr_list)->next;
                    addr_list_tp2 = *addr_list;
                }
                else
                {
                    addr_list_tp2 = addr_list_tp2->next;
                    if (addr_list_tp2_prv != NULL)
                    {
                        addr_list_tp2_prv->next = addr_list_tp2;
                    }
                }

                if (tmp->data)
                {
                    mem_free_fn(tmp->data);
                }

                if (tmp->data2)
                {
                    mem_free_fn(tmp->data2);
                }
                mem_free_fn(tmp);
            }
            else
            {
                addr_list_tp2_prv = addr_list_tp2;
                addr_list_tp2 = addr_list_tp2->next;
            }
        }
        addr_list_tp1 = addr_list_tp1->next;
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_free_address_list
 * DESCRIPTION
 *  This interface function is used to free all addresses of one list
 * PARAMETERS
 *  addr_list		[IN]	Addresses list
 *  mem_free_fn		[IN]	Memory free function
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_free_address_list(applib_address_node_struct **addr_list, applib_mem_free_fn mem_free_fn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	applib_address_node_struct *addr_list_tp = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    if (addr_list == NULL || *addr_list == NULL || mem_free_fn == NULL)
	{
		return KAL_FALSE;	
	}
	while(*addr_list)
	{
		addr_list_tp = (*addr_list)->next;
		if ((*addr_list)->data)
		{
			mem_free_fn((*addr_list)->data);	
		}
		if ((*addr_list)->data2)
		{
			mem_free_fn((*addr_list)->data2);	
		}
		mem_free_fn(*addr_list);
		*addr_list = addr_list_tp;
	}
    
    *addr_list = NULL;
	return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_concatenaet_address_list
 * DESCRIPTION
 *  This interface function is used to concatenate list2 to the end of list1. 
 *  Users should be awared about the consistency of memory alloc/free owner
 * PARAMETERS
 *  list1		[IN]	Addresses list 1
 *  list2		[IN]	Addresses list 2
 * RETURNS
 *  applib_address_node_struct *
 *****************************************************************************/
applib_address_node_struct *applib_concatenate_address_list(applib_address_node_struct *list1, 
                                                            applib_address_node_struct *list2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	applib_address_node_struct *c_list = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (list1 == NULL)
    {
        return list2;
    }
    else if (list2 == NULL)
    {
        return list1;
    }

    c_list = list1;
    while(list1->next != NULL)
    {
        list1 = list1->next;
    }
    list1->next = list2;

    return c_list;
}


/*****************************************************************************
 * FUNCTION
 *  applib_sort_address_list_by_offset
 * DESCRIPTION
 *  This function is used to sort an address list in the ascending order by their offset in the original text.
 *  Now we use bubble sort, which can be improved by quicker algorithmn.
 * PARAMETERS
 *  list       	[IN/OUT]	list to be sorted
 * RETURNS
 *****************************************************************************/
static void applib_sort_address_list_by_offset(applib_address_node_struct **list)
{
    if (list == NULL || *list == NULL || (*list)->next == NULL)
    {
        return;
    }
    else
    {
        applib_address_node_struct *ptr1 = (*list)->next;
        applib_address_node_struct *ptr1_prev = *list;
        while (ptr1)
        {
            applib_address_node_struct *ptr2 = *list;
            applib_address_node_struct *ptr2_prev = NULL;
            kal_bool move = KAL_FALSE;
            
            while (ptr2 && ptr1 != ptr2)
            {
                if (ptr1->pos < ptr2->pos)   /* insert before */
                {
                    if (ptr2_prev == NULL)
                    {
                        ptr1_prev->next = ptr1->next;
                        ptr1->next = ptr2;
                        *list = ptr1;
                    }
                    else
                    {
                        ptr1_prev->next = ptr1->next;
                        ptr1->next = ptr2;
                        ptr2_prev->next = ptr1;
                    }
                    move = KAL_TRUE;
                    break;
                }

                ptr2_prev = ptr2;
                ptr2 = ptr2->next;
            }

            if (move != KAL_TRUE)
            {
                ptr1_prev = ptr1;
                ptr1 = ptr1->next;
            }
            else
            {
                ptr1 = ptr1_prev->next;
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_get_exclusive_address_list_from_text
 * DESCRIPTION
 *  This interface function is used to get all addresses from one UTF8-encoded text.
 *  It will remove duplcate address.
 * PARAMETERS
 *  addr_type		[IN]	Address Types
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data        
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_get_exclusive_address_list_from_text(applib_addr_type_enum addr_type,
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        char *input_data, 
        kal_int32 dataLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_bool stopped = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return applib_get_exclusive_address_list_from_text_ext(addr_type, mem_alloc_fn, mem_free_fn, NULL, 
        APPLIB_INPUT_DATA_TYPE_UTF8, input_data, dataLen, &stopped);
}

/*****************************************************************************
 * FUNCTION
 *  applib_get_address_list_from_text
 * DESCRIPTION
 *  This interface function is used to get all addresses from one UTF8-encoded text.
 *  It doesn't remove duplcate address.
 * PARAMETERS
 *  addr_type		[IN]	Address Types
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data        
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_get_address_list_from_text(applib_addr_type_enum addr_type,
        applib_mem_alloc_fn mem_alloc_fn, 
        applib_mem_free_fn mem_free_fn,
        char *input_data, 
        kal_int32 dataLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_bool stopped = KAL_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return applib_get_address_list_from_text_ext(addr_type, mem_alloc_fn, mem_free_fn, NULL, 
        APPLIB_INPUT_DATA_TYPE_UTF8, input_data, dataLen, &stopped);
}

/*****************************************************************************
 * FUNCTION
 *  applib_get_exclusive_address_list_from_text_ext
 * DESCRIPTION
 *  This interface function is used to get all addresses from one UTF8-encoded text.
 *  It will remove duplcate address.
 * PARAMETERS
 *  addr_type		[IN]	Address Types
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  check_stop_fn   [IN]    Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data_type [IN]    Parsed text charset
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data
 *  is_stopped      [IN/OUT]Specify if parsing procedure being stopped by user
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_get_exclusive_address_list_from_text_ext(applib_addr_type_enum addr_type,
	applib_mem_alloc_fn mem_alloc_fn, 
	applib_mem_free_fn mem_free_fn,
	applib_check_stop_fn check_stop_fn,
	applib_charset_enum input_data_type,
	char *input_data, 
	kal_int32 dataLen,
	kal_bool *is_stopped)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *ptr = NULL;
    applib_address_node_struct *addr_list = NULL;
    applib_address_node_struct *url_addr_list = NULL;
    applib_address_node_struct *email_addr_list = NULL;
    applib_address_node_struct *phone_addr_list = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mem_alloc_fn == NULL || mem_free_fn == NULL || input_data == NULL || dataLen == 0 || *is_stopped == KAL_TRUE)
    {
        return NULL;
    }

    /* Parse URLs*/
    if (addr_type & APPLIB_ADDR_TYPE_URL)
    {
        if (input_data_type == APPLIB_INPUT_DATA_TYPE_ASCII ||
            input_data_type == APPLIB_INPUT_DATA_TYPE_UTF8)
        {
            url_addr_list = applib_parse_url_from_text(
        					mem_alloc_fn, 
        					mem_free_fn,
        					check_stop_fn,
        					input_data, 
        					dataLen,
        					is_stopped,
        					KAL_TRUE);

        }
        else if (input_data_type == APPLIB_INPUT_DATA_TYPE_UNICODE)
        {

            url_addr_list = applib_parse_url_from_text_unicode(
        					mem_alloc_fn, 
        					mem_free_fn, 
                            check_stop_fn,
        					(kal_wchar*)input_data, 
        					dataLen,
        					is_stopped,
        					KAL_TRUE);
        }
        addr_list = url_addr_list;
    }

    /* Parse Email*/
    if (*is_stopped == KAL_FALSE && addr_type & APPLIB_ADDR_TYPE_EMAIL)
    {
        if (input_data_type == APPLIB_INPUT_DATA_TYPE_ASCII ||
            input_data_type == APPLIB_INPUT_DATA_TYPE_UTF8)
        {
            email_addr_list = applib_parse_email_from_text(
        					mem_alloc_fn, 
        					mem_free_fn, 
        					check_stop_fn,
        					input_data, 
        					dataLen,
        					is_stopped,
        					KAL_TRUE);

        }
        else if (input_data_type == APPLIB_INPUT_DATA_TYPE_UNICODE)
        {
			email_addr_list = applib_parse_email_from_text_unicode(
        					mem_alloc_fn, 
        					mem_free_fn,
        					check_stop_fn,
        					(kal_wchar*)input_data, 
        					dataLen,
        					is_stopped,
        					KAL_TRUE);
        }
        addr_list = applib_concatenate_address_list(addr_list, email_addr_list);
    }
    
    /* Parse Phone Number*/
    if (*is_stopped == KAL_FALSE && addr_type & APPLIB_ADDR_TYPE_PHONENUMBER)
    {
        if (input_data_type == APPLIB_INPUT_DATA_TYPE_ASCII ||
            input_data_type == APPLIB_INPUT_DATA_TYPE_UTF8)
        {
            phone_addr_list = applib_parse_phoneno_from_text(
        					mem_alloc_fn, 
        					mem_free_fn,
        					check_stop_fn,
        					input_data, 
        					dataLen,
        					is_stopped,
        					KAL_TRUE);

        }
        else if (input_data_type == APPLIB_INPUT_DATA_TYPE_UNICODE)
        {
            phone_addr_list = applib_parse_phoneno_from_text_unicode(
        					mem_alloc_fn, 
        					mem_free_fn, 
        					check_stop_fn,
        					(kal_wchar*)input_data, 
        					dataLen,
        					is_stopped,
        					KAL_TRUE);
        }
        addr_list = applib_concatenate_address_list(addr_list, phone_addr_list);
    }    

    /* Parse USSD String*/
    if (*is_stopped == KAL_FALSE && addr_type & APPLIB_ADDR_TYPE_USSD)
    {
        if (input_data_type == APPLIB_INPUT_DATA_TYPE_ASCII ||
            input_data_type == APPLIB_INPUT_DATA_TYPE_UTF8)
        {
            phone_addr_list = applib_parse_ussd_string_from_text(
        					mem_alloc_fn, 
        					mem_free_fn,
        					check_stop_fn,
        					input_data, 
        					dataLen,
        					is_stopped,
        					KAL_TRUE);

        }
        else if (input_data_type == APPLIB_INPUT_DATA_TYPE_UNICODE)
        {		
            phone_addr_list = applib_parse_ussd_string_from_text_unicode(
        					mem_alloc_fn, 
        					mem_free_fn, 
        					check_stop_fn,
        					(kal_wchar*)input_data, 
        					dataLen,
        					is_stopped,
        					KAL_TRUE);
        }
        addr_list = applib_concatenate_address_list(addr_list, phone_addr_list);
    }    

    /*Remove duplicate addresses*/
    applib_remove_overlapped_address(&addr_list, mem_free_fn);

    /* adjust offset */
    ptr = addr_list;
    while(ptr)
    {
        ptr->pos = ptr->pos - (kal_uint32)input_data;
        ptr = ptr->next;
    }

    applib_sort_address_list_by_offset(&addr_list);
    return addr_list;
}

/*****************************************************************************
 * FUNCTION
 *  applib_get_address_list_from_text
 * DESCRIPTION
 *  This interface function is used to get all addresses from one UTF8-encoded text.
 *  It doesn't remove duplcate address.
 * PARAMETERS
 *  addr_type		[IN]	Address Types
 *  mem_alloc_fn    [IN]	Memory allication function
 *  mem_free_fn		[IN]	Memory free function
 *  check_stop_fn   [IN]    Check if parsing should be stopped (being invoked when every address is parsed)
 *  input_data_type [IN]    Parsed text charset
 *  input_data		[IN]	Input text data
 *  dataLen       	[IN]	Length of input text data
 *  is_stopped      [IN/OUT]Specify if parsing procedure being stopped by user
 * RETURNS
 *  addresses list (applib_address_node_struct)
 *****************************************************************************/
applib_address_node_struct *applib_get_address_list_from_text_ext(applib_addr_type_enum addr_type,
	applib_mem_alloc_fn mem_alloc_fn, 
	applib_mem_free_fn mem_free_fn,
	applib_check_stop_fn check_stop_fn,
	applib_charset_enum input_data_type,
	char *input_data, 
	kal_int32 dataLen,
	kal_bool *is_stopped)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_address_node_struct *ptr = NULL;
    applib_address_node_struct *addr_list = NULL;
    applib_address_node_struct *url_addr_list = NULL;
    applib_address_node_struct *email_addr_list = NULL;
    applib_address_node_struct *phone_addr_list = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mem_alloc_fn == NULL || mem_free_fn == NULL || input_data == NULL || dataLen == 0 || *is_stopped == KAL_TRUE)
    {
        return NULL;
    }

    /* Parse URLs*/
    if (addr_type & APPLIB_ADDR_TYPE_URL)
    {
        if (input_data_type == APPLIB_INPUT_DATA_TYPE_ASCII ||
            input_data_type == APPLIB_INPUT_DATA_TYPE_UTF8)
        {
            url_addr_list = applib_parse_url_from_text(
        					mem_alloc_fn, 
        					mem_free_fn,
        					check_stop_fn,
        					input_data, 
        					dataLen,
        					is_stopped,
        					KAL_FALSE);

        }
        else if (input_data_type == APPLIB_INPUT_DATA_TYPE_UNICODE)
        {

            url_addr_list = applib_parse_url_from_text_unicode(
        					mem_alloc_fn, 
        					mem_free_fn, 
                            check_stop_fn,
        					(kal_wchar*)input_data, 
        					dataLen,
        					is_stopped,
        					KAL_FALSE);
        }
        addr_list = url_addr_list;
    }

    /* Parse Email*/
    if (*is_stopped == KAL_FALSE && addr_type & APPLIB_ADDR_TYPE_EMAIL)
    {
        if (input_data_type == APPLIB_INPUT_DATA_TYPE_ASCII ||
            input_data_type == APPLIB_INPUT_DATA_TYPE_UTF8)
        {
            email_addr_list = applib_parse_email_from_text(
        					mem_alloc_fn, 
        					mem_free_fn, 
        					check_stop_fn,
        					input_data, 
        					dataLen,
        					is_stopped,
        					KAL_FALSE);

        }
        else if (input_data_type == APPLIB_INPUT_DATA_TYPE_UNICODE)
        {
			email_addr_list = applib_parse_email_from_text_unicode(
        					mem_alloc_fn, 
        					mem_free_fn,
        					check_stop_fn,
        					(kal_wchar*)input_data, 
        					dataLen,
        					is_stopped,
        					KAL_FALSE);
        }
        addr_list = applib_concatenate_address_list(addr_list, email_addr_list);
    }
    
    /* Parse Phone Number*/
    if (*is_stopped == KAL_FALSE && addr_type & APPLIB_ADDR_TYPE_PHONENUMBER)
    {
        if (input_data_type == APPLIB_INPUT_DATA_TYPE_ASCII ||
            input_data_type == APPLIB_INPUT_DATA_TYPE_UTF8)
        {
            phone_addr_list = applib_parse_phoneno_from_text(
        					mem_alloc_fn, 
        					mem_free_fn,
        					check_stop_fn,
        					input_data, 
        					dataLen,
        					is_stopped,
        					KAL_FALSE);

        }
        else if (input_data_type == APPLIB_INPUT_DATA_TYPE_UNICODE)
        {
            phone_addr_list = applib_parse_phoneno_from_text_unicode(
        					mem_alloc_fn, 
        					mem_free_fn, 
        					check_stop_fn,
        					(kal_wchar*)input_data, 
        					dataLen,
        					is_stopped,
        					KAL_FALSE);
        }
        addr_list = applib_concatenate_address_list(addr_list, phone_addr_list);
    }    

    /* Parse USSD String*/
    if (*is_stopped == KAL_FALSE && addr_type & APPLIB_ADDR_TYPE_USSD)
    {
        if (input_data_type == APPLIB_INPUT_DATA_TYPE_ASCII ||
            input_data_type == APPLIB_INPUT_DATA_TYPE_UTF8)
        {
            phone_addr_list = applib_parse_ussd_string_from_text(
        					mem_alloc_fn, 
        					mem_free_fn,
        					check_stop_fn,
        					input_data, 
        					dataLen,
        					is_stopped,
        					KAL_FALSE);

        }
        else if (input_data_type == APPLIB_INPUT_DATA_TYPE_UNICODE)
        {		
            phone_addr_list = applib_parse_ussd_string_from_text_unicode(
        					mem_alloc_fn, 
        					mem_free_fn, 
        					check_stop_fn,
        					(kal_wchar*)input_data, 
        					dataLen,
        					is_stopped,
        					KAL_FALSE);
        }
        addr_list = applib_concatenate_address_list(addr_list, phone_addr_list);
    }    

    /*Remove duplicate addresses*/
    applib_remove_overlapped_address(&addr_list, mem_free_fn);

    /* adjust offset */
    ptr = addr_list;
    while(ptr)
    {
        ptr->pos = ptr->pos - (kal_uint32)input_data;
        ptr = ptr->next;
    }

    applib_sort_address_list_by_offset(&addr_list);
    return addr_list;
}


/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_address
 * DESCRIPTION
 *  This function is to check if the input str is valid email address
  * PARAMETERS
 *  str		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_is_valid_email_address(const char *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char c;
    kal_int32 pos, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str == NULL)
    {
        return KAL_FALSE;
    }

    /* get the str len */
    len = 0;
    while(str[len] != '\0')
    {
        len++;
    }
    if (len < 3)
    {
        return KAL_FALSE;
    }

    /* find the '@' position */
    pos = 0;
    while(pos < len)
    {
        c = str[pos];
        if (c == '@')
        {
            break;
        }
        pos++;
    }

    if (pos == 0 || pos >= len - 1)
    {
        /* '@' at first or last or no '@' */
        return KAL_FALSE;
    }

    if (*(str) == '.' || *(str + pos - 1) == '.')
    {
        /* '.' at the begin or end postion of local part */
        return KAL_FALSE;
    }

    if (!applib_is_valid_email_local_part(str, pos))
    {
        /* local part invalid */
        return KAL_FALSE;
    }

    if (*(str + pos + 1) == '.' || *(str + len - 1) == '.')
    {
        /* '.' at the begin or end postion of domain part */
        return KAL_FALSE;
    }

    if (!applib_is_valid_email_domain_name(str + pos + 1))
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_email_address_unicode
 * DESCRIPTION
 *  This function is to check if the input UCS2 str is valid email address
  * PARAMETERS
 *  str		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_is_valid_email_address_unicode(const kal_wchar *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar c;
    kal_int32 pos, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str == NULL)
    {
        return KAL_FALSE;
    }

    /* get the str len */
    len = 0;
    while(str[len] != L'\0')
    {
        len++;
    }
    if (len < 3)
    {
        return KAL_FALSE;
    }

    /* find the '@' position */
    pos = 0;
    while(pos < len)
    {
        c = str[pos];
        if (c == L'@')
        {
            break;
        }
        pos++;
    }

    if (pos == 0 || pos >= len - 1)
    {
        /* '@' at first or last or no '@' */
        return KAL_FALSE;
    }

    if (*(str) == L'.' || *(str + pos - 1) == L'.')
    {
        /* '.' at the begin or end postion of local part */
        return KAL_FALSE;
    }

    if (!applib_is_valid_email_local_part_unicode(str, pos))
    {
        /* local part invalid */
        return KAL_FALSE;
    }

    if (*(str + pos + 1) == L'.' || *(str + len - 1) == L'.')
    {
        /* '.' at the begin or end postion of domain part */
        return KAL_FALSE;
    }

    if (!applib_is_valid_email_domain_name_unicode(str + pos + 1))
    {
        return KAL_FALSE;
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_are_valid_chars
 * DESCRIPTION
 *  This function is to check if the chars of the input str are valid or not
 * PARAMETERS
 *  number		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_are_valid_chars(kal_uint8 *number)
{
    kal_uint8 i;

    for(i=0; number[i] != '\0'; i++)
    {
        if (l4_custom_is_phb_valid_char(number[i]) == KAL_FALSE)
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_ss_string_parsing
 * DESCRIPTION
 *  This function is to check if the input str is SS string
 * PARAMETERS
 *  str		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_uint8 applib_ss_string_parsing(kal_uint8 *string_ptr, kal_uint8 length, kal_uint8 sim_interface, kal_bool is_in_call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 tmp_str[APPLIB_MAX_USSD_LEN+1]; //MAUI_02044055
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length > APPLIB_MAX_USSD_LEN)
    {
        return 0; /* INVALID_OPERATION:0 */
    }
    else
    {
        kal_mem_cpy(tmp_str, string_ptr, length);
        tmp_str[length] = '\0';
        if (applib_are_valid_chars(tmp_str) != KAL_TRUE)
        {
            return 0;
        }
        return l4c_cc_ss_string_parsing((kal_uint8 *)string_ptr, (kal_int8)length, sim_interface, is_in_call);
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_ss_string_parsing_unicode
 * DESCRIPTION
 *  This function is to check if the input str is SS string
 * PARAMETERS
 *  str		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_uint8 applib_ss_string_parsing_unicode(kal_wchar *string_ptr, kal_uint8 length, kal_uint8 sim_interface, kal_bool is_in_call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char ucs2_string[(APPLIB_MAX_USSD_LEN+1)*2];
    char acs_string[APPLIB_MAX_USSD_LEN+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length > APPLIB_MAX_USSD_LEN)
    {
        return 0; /* INVALID_OPERATION:0 */
    }
    else
    {
        memset(ucs2_string, 0x00, (APPLIB_MAX_USSD_LEN+1)*2);
        memset(acs_string, 0x00, APPLIB_MAX_USSD_LEN+1);
        memcpy(ucs2_string, string_ptr, length * 2);
        app_ucs2_str_to_asc_str((kal_int8 *)acs_string, (kal_int8 *) ucs2_string);

        if (applib_are_valid_chars((kal_uint8 *)acs_string) != KAL_TRUE)
        {
            return 0;
        }

        return l4c_cc_ss_string_parsing((kal_uint8 *)acs_string, (kal_int8)strlen(acs_string), sim_interface, is_in_call);
    }
}

/*****************************************************************************
 * FUNCTION
 *  applib_check_input_number_valid
 * DESCRIPTION
 *  This function is to check if the basic format of input str is valid or not
 *  which include str pointer, str length, characters
 * PARAMETERS
 *  number		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_check_input_number_valid(kal_uint8 *number)
{
    kal_uint16 len;
    kal_uint8 i;
    kal_uint8 tmp_num[APPLIB_MAX_PHONE_NUM_LEN+1];

    if(number == NULL)
        return KAL_FALSE;

    len = strlen((kal_char*)number);

    if ( (number[0] == '+' && len > APPLIB_MAX_PHONE_NUM_LEN) ||
         (number[0] != '+' && len >= APPLIB_MAX_PHONE_NUM_LEN) || 
         len == 0)
    {
        return KAL_FALSE;
    }

    memcpy(tmp_num, number, APPLIB_MAX_PHONE_NUM_LEN + 1);
    for(i=0; i<len; i++)
    {
        if (tmp_num[i]>='A' && tmp_num[i]<='Z')
            tmp_num[i] += 'a' - 'A';
    }

    if( applib_are_valid_chars(tmp_num)==KAL_FALSE)
        return KAL_FALSE;

    if( (tmp_num[0] != '+' && (tmp_num[0]=='p' || tmp_num[0]==custom_auto_dtmf_modifier())) ||
         (tmp_num[0] == '+' && (tmp_num[1]=='p' || tmp_num[1]==custom_auto_dtmf_modifier())) )
        return KAL_FALSE;

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_tel_ssc
 * DESCRIPTION
 *  This function is to check if the number is valid ssc/tel  or not
 * PARAMETERS
 *  number		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static kal_bool applib_is_valid_tel_ssc(kal_uint8 *number)
{
    kal_uint8 i, j;
    kal_uint8 length;
    kal_int16 plus_index;

    if (applib_check_input_number_valid(number)==KAL_FALSE )
        return KAL_FALSE;

    i = 0;
    
    /* ignore '*' and '#' */
    while ( (number[i] == '*' || number[i] == '#') )
        i++;

    length = strlen((kal_char*)number);
    if(i==0)
    {
        /* the beginning of the string is not '*' or '#' 
        * the '+' could only appear in the beginning.
        */

        plus_index = -1;
        for ( i=0; i<length ; i++)
        {
            if (number[i] == '+' )
            {
                plus_index = i;
            }
        }

        // '+' can only be present at the head
        if (plus_index > 0)
            return KAL_FALSE;
        // we treat the number "+" as invalid number;
        else if (plus_index == 0 && length == 1)
            return KAL_FALSE;

        // * or # can't be preset at the head in the tel number
        plus_index++;
        if(number[plus_index] == '#' || number[plus_index] == '*')
            return KAL_FALSE;

    }
    else
    {
        /* the beginning of the string is '*' or '#' */

        /* Judge if there is a SC number with no  '+' and 'p' */
        while ((number[i] >=  '0' && number[i] <= '9' ) 
                || number[i]=='p' || number[i] == 'w')
        {       
            if ((number[i] == 'p' || number [i] == 'w') && number[length-1]=='#')
            {
                break;
            }
            i++;
        }
        if (number[i] != '*' && number[i] != '#' && number[i] != '\0')
            return KAL_FALSE;

        if( number[i] == '\0')
            return KAL_TRUE;

        /* judge if there is only one '*' || '#' */
        i++;

        /*************************************
        * Judge if there is any '+' in the remain string,
        * If there is any '+' which is not at the head of the string, return ERROR
        *************************************/
        plus_index = i;
        for (j=i ; number[j] != '\0'; j++)
        {
            if (number[j] == '+')
                plus_index = j;        
        }

        if (plus_index != i)
            return KAL_FALSE;
    }
    return KAL_TRUE;

}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_number
 * DESCRIPTION
 *  This function is to check if the number is tel, ssc, or invalid number
 *  Note that this function will not check if the number is an ECC or not
 * PARAMETERS
 *  number		[IN]	string being checked
 * RETURNS
 *  applib_number_type_enum
 *****************************************************************************/
kal_uint8  applib_is_valid_number(kal_uint8 *number)
{
    kal_uint8 length;

    if(number==NULL)
        return KAL_FALSE;

    length = strlen((char*) number);
    if (length == 0)
        return APPLIB_INVALID_NUMBER;

    if (number[length-1] == '#')
    {
        return applib_is_valid_ssc(number) == KAL_TRUE ? APPLIB_SSC_NUMBER : APPLIB_INVALID_NUMBER;
    }    
    return applib_is_valid_tel(number) == KAL_TRUE ? APPLIB_TEL_NUMBER : APPLIB_INVALID_NUMBER;
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_number_unicode
 * DESCRIPTION
 *  This function is to check if the number is tel, ssc, or invalid number
 *  where the input number is coded using UCS2
 * PARAMETERS
 *  number		[IN]	string being checked     
 * RETURNS
 *  applib_number_type_enum
 *****************************************************************************/
kal_uint8 applib_is_valid_number_unicode(kal_wchar *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char ucs2_string[APPLIB_MAX_PHONE_NUM_LEN * 2 + 2];
    char acs_string[APPLIB_MAX_PHONE_NUM_LEN + 1];
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(ucs2_string, 0x00, APPLIB_MAX_PHONE_NUM_LEN * 2 + 2);
    memset(acs_string, 0x00, APPLIB_MAX_PHONE_NUM_LEN + 1);

    if(number == NULL)
    {
        return KAL_FALSE;
    }

    len = app_ucs2_strlen((kal_int8*)number);
    len = (len < APPLIB_MAX_PHONE_NUM_LEN)? len : APPLIB_MAX_PHONE_NUM_LEN;
    
    //MAUI_02319395 last two bytes are end of string
    memcpy(ucs2_string, (char*)number, len*2);
    app_ucs2_str_to_asc_str((kal_int8 *)acs_string, (kal_int8 *) ucs2_string);

    return applib_is_valid_number( (kal_uint8*)acs_string);
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_tel
 * DESCRIPTION
 *  This function is to check if the number is tel or not
 * PARAMETERS
 *  number		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_is_valid_tel(kal_uint8 *number)
{
    kal_uint8 length;

    if(number==NULL)
        return KAL_FALSE;

    length = strlen((char*) number);
    if (length == 0)
        return KAL_FALSE;
    
    if (number[length-1] != '#')
    {
        return applib_is_valid_tel_ssc(number);
    }
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_is_valid_ssc
 * DESCRIPTION
 *  This function is to check if the number is ssc or not
 * PARAMETERS
 *  number		[IN]	string being checked     
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
kal_bool applib_is_valid_ssc(kal_uint8 *number)
{
    kal_uint8 length;

    if(number==NULL)
        return KAL_FALSE;

    length = strlen((char*) number);
    if (length == 0)
        return KAL_FALSE;

    if (number[length-1] == '#')
    {
        return applib_is_valid_tel_ssc(number);
    }
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_encode_number
 * DESCRIPTION
 *  This function is to encode the input number to eliminate '+' and change type of number
 * PARAMETERS
 *  src_num          [IN]	string to be encoded     
 *  des_num         [IN]	the storage storing the encoded number
 *  ton                [IN]	the type of number of src_num
 * RETURNS
 *  TON after encoding
 *****************************************************************************/
kal_uint8 applib_encode_number(kal_uint8 *src_num, kal_uint8 *des_num, kal_uint8 ton)
{
    kal_uint8 i, j, len;

    if(src_num==NULL || des_num==NULL)
    {
        return KAL_FALSE;
    }

    if( src_num[0] == '\0')
    {    
        des_num[0] = '\0';
        return 0x81;
    }
    
    if (applib_check_input_number_valid(src_num)==KAL_FALSE )
        return KAL_FALSE;
    

    len = strlen((kal_char*)src_num);
    if ( applib_is_valid_number(src_num) != APPLIB_INVALID_NUMBER)
    {
        /* eliminate '+', if any, set TON as 0x91 */
        for (i = 0, j=0;i < len;i++)
        {
            if (src_num[i] == '+')
            {
                ton = 0x91;
            }
            else
            {
                des_num[j++] = src_num[i];
            }
        }
        des_num[j] = '\0';

        return ton;
    }

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  applib_encode_number_unicode
 * DESCRIPTION
 *  This function is to encode the input number to eliminate '+' and change type of number
 *  where the src_num coded using UCS2
 * PARAMETERS
 *  src_num          [IN]	string to be encoded     
 *  des_num         [IN]	the storage storing the encoded number
 *  ton                [IN]	the type of number of src_num
 * RETURNS
 *  TON after encoding
 *****************************************************************************/
kal_uint8 applib_encode_number_unicode(kal_wchar *src_num, kal_wchar *des_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tmp_string[APPLIB_MAX_PHONE_NUM_LEN * 2 + 2];
    char acs_string[APPLIB_MAX_PHONE_NUM_LEN + 1];
    int ton;
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tmp_string, 0x00, APPLIB_MAX_PHONE_NUM_LEN * 2 + 2);
    memset(acs_string, 0x00, APPLIB_MAX_PHONE_NUM_LEN + 1);

    if(src_num==NULL || des_num==NULL)
    {
        return KAL_FALSE;
    }

    len = app_ucs2_strlen((kal_int8*)src_num);
    len = (len < APPLIB_MAX_PHONE_NUM_LEN)? len : APPLIB_MAX_PHONE_NUM_LEN;
    
    memcpy(tmp_string, (char*)src_num, len*2);
    app_ucs2_str_to_asc_str((kal_int8 *)acs_string, (kal_int8 *) tmp_string);

    ton = applib_encode_number( (kal_uint8*)acs_string, (kal_uint8*)tmp_string, acs_string[0]=='+' ? 0x91 : 0x81);
    app_asc_str_to_ucs2_str((kal_int8 *)des_num, (kal_int8 *)tmp_string);
    return ton;
}


/*****************************************************************************
 * FUNCTION
 *  applib_decode_number
 * DESCRIPTION
 *  This function is to decode the input number to add '+' to the appropriate position according to the ton.
 *
 *  Since we can't know where the input source number comes from, it might be from the entries
 *  in the SIM or NVRAM which can't control by the phone. So, in this function, we do less check 
 *  for srouce number.
 *
 * PARAMETERS
 *  src_num          [IN]	string to be decoded     
 *  des_num         [IN]	the storage storing the decoded number
 *  ton                [IN]	the type of number of src_num
 * RETURNS
 *  the string length after decoding
 *****************************************************************************/
kal_uint8 applib_decode_number(kal_uint8 *src_num, kal_uint8 *des_num, kal_uint8 ton)
{
    kal_uint8 i, j;
    kal_int16 plus_pos;;

    if(src_num==NULL || des_num==NULL)
    {
        return KAL_FALSE;
    }

    plus_pos = -1;
    i = j = 0;
    if (ton == 0x91)
    {
        plus_pos = 0;
        /* try to find out the position of the plus*/

        /* skip the beginning '*' and '#' */
        while ( (src_num[i] == '*' || src_num[i] == '#') )
        {
            i++;
        }

        /* if there is no * or # in the beginning of the number,
         * we should treat this number as normal tel number, 
         * and put the '+' at the head
         */
         
        if (i != 0 && src_num[i] != '\0')
        {
            /* skip the SC number */
            while (src_num[i] != '*' && src_num[i] != '#' && src_num[i] != '\0')
            {
                i++;
            }
            
            /* skip one '*' || '#' */
            if(src_num[i] != '\0' && (src_num[i] == '*' || src_num[i] == '#'))
            {
                plus_pos = ++i;
            }        
        }
                  
    }

    /* to handle src_num="" && ton=ox91, we need to decode this as "+" */
    if (plus_pos==0 && strlen((kal_char*)src_num)==0 )
    {
        des_num[j++] = '+';
    }

    for(i = 0 ; src_num[i] != '\0' ; i++)
    {
        if( i == plus_pos)
        {
            des_num[j++] = '+';
            des_num[j++] = src_num[i];
        }
        else
        {
            des_num[j++] = src_num[i];
        }
    }
    des_num[j] = '\0';

    return strlen((kal_char*)des_num);
}

/*****************************************************************************
 * FUNCTION
 *  applib_decode_number_unicode
 * DESCRIPTION
 *  This function is to decode the input number to add '+' to the appropriate position according to the ton
 *  where the src_num is coded using UCS2
 * PARAMETERS
 *  src_num          [IN]	string to be decoded     
 *  des_num         [IN]	the storage storing the decoded number
 *  ton                [IN]	the type of number of src_num
 * RETURNS
 *  the string length after decoding
 *****************************************************************************/
kal_uint8 applib_decode_number_unicode(kal_wchar *src_num, kal_wchar *des_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char tmp_string[APPLIB_MAX_PHONE_NUM_LEN * 2 + 2];
    char acs_string[APPLIB_MAX_PHONE_NUM_LEN + 1];
    int len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(tmp_string, 0x00, APPLIB_MAX_PHONE_NUM_LEN * 2 + 2);
    memset(acs_string, 0x00, APPLIB_MAX_PHONE_NUM_LEN + 1);

    if(src_num==NULL || des_num==NULL)
    {
        return KAL_FALSE;
    }

    len = app_ucs2_strlen((kal_int8*)src_num);
    len = (len < APPLIB_MAX_PHONE_NUM_LEN)? len : APPLIB_MAX_PHONE_NUM_LEN;
    
    memcpy(tmp_string, (char*)src_num, len*2);
    app_ucs2_str_to_asc_str((kal_int8 *)acs_string, (kal_int8 *) tmp_string);

    len = applib_decode_number( (kal_uint8*)acs_string, (kal_uint8*)tmp_string, acs_string[0]=='+' ? 0x91 : 0x81);
    app_asc_str_to_ucs2_str((kal_int8 *)des_num, (kal_int8 *)tmp_string);
    return len;
}


#endif /* _APP_USEDETAILS_C */ 

