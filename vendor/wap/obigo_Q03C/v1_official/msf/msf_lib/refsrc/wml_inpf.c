#ifndef Q03C_IND_MOD_ARCH_SUPPORT
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

/*
 * Copyright (C) Obigo AB, 2002-2006.
 * All rights reserved.
 *
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 *
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 *
 */
/*
 * brs_char.c
 *
 * Created by Henrik Olsson. 030603
 *
 * Revision history:
 *   030603, Created
 *
 */
/************************************************************
 * This file is used for:
 * + validating wml input using a format string
 ************************************************************/



/*******************************************************************************
 *
 * Filename:
 * ---------
 * wml_inpf.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
 *
 * Author:
 * -------
 * 
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include <string.h>
#include <stdio.h>

#include "wml_inpf.h"

#include "msf_cmmn.h"
#include "msf_chrt.h"

/*
 * Returns TRUE if the character pointed to by 'ch' 
 * conforms to the 'format_code'.
 * Returns FALSE otherwise and replaces ch with
 * a character that confirms to the format
 */
static
int
wml_make_char_valid(char *ch, char format_code, int isConstant)
{
  int isOk = TRUE;

  if(isConstant)
  {
    if (*ch != format_code)
    {
      *ch = format_code;
      isOk = FALSE;
    }
  }
  else
  {

    switch (format_code)
    {
      case 'A':
      {
        if (!*ch || !ct_isascii(*ch) || ct_isdigit(*ch) || ct_islower(*ch))
        {
          char newChar[] = "A";
          if(ct_islower(*ch))
          {
            newChar[0] = (char)(*ch - ('a' - 'A'));
          }
          *ch = newChar[0];
          isOk = FALSE;
        }
        break;
      }
      case 'a':
      {
        if (!*ch || !ct_isascii(*ch) || ct_isdigit(*ch) || ct_isupper(*ch))
        {
          char newChar[] = "a";
          if(ct_isupper(*ch))
          {
            newChar[0] = (char)(*ch + ('a' - 'A'));
          }
          *ch = newChar[0];
          isOk = FALSE;
        }
        break;
      }
      case 'N':
      {
        if (!*ch ||  !ct_isascii(*ch) || !ct_isdigit(*ch))
        {
          *ch = '0';
          isOk = FALSE;
        }
        break;
      }
      case 'n':
      {
        if (!*ch || !ct_isascii(*ch) || ct_isupper(*ch) || ct_islower(*ch))
        {
          *ch = '0';
          isOk = FALSE;
        }
        break;
      }
      case 'X':
      {
        if (!*ch || !ct_isascii(*ch) || ct_islower(*ch))
        {
          char newChar[] = "A";
          if(ct_islower(*ch))
          {
            newChar[0] = (char)(*ch - ('a' - 'A'));
          }
          *ch = newChar[0];
          isOk = FALSE;
        }
        break;
      }
      case 'x':
      {
        if (!*ch || !ct_isascii(*ch) || ct_isupper(*ch))
        {
          char newChar[] = "a";
          if(ct_isupper(*ch))
          {
            newChar[0] = (char)(*ch + ('a' - 'A'));
          }
          *ch = newChar[0];
          isOk = FALSE;
        }
        break;
      }
      case 'M':
      case 'm':
      default:
      {
        if (!*ch || !ct_isascii(*ch))
        {
          *ch = 'a';
          isOk = FALSE;
        }
        break;
      }
    } 
  }
  return isOk;
}

/* 
 * formats 'inStr' according to a valid 'format' string and places the
 * result in 'outStr'.
 *
 * Returns: TRUE if 'outStr' was properly generated according to format.
 * The only reason for failure is if the formatted string doesn't fit into
 * 'outStr'

 * 'startSel','endSel': defines a selection in inStr that this function should 
 * delete if possible. If 'startSel' equals 'endSel' it only says where 'newChars'
 * should be inserted. 'startSel' must be <= 'endSel'
 *
 * 'newChars' are characters to be inserted in 'outStr' at startSel position.
 * if 'newChars is NULL no chars are inserted.
 *
 * 'format' is a format string formatted according to WAP-WML-INPUT-FORMAT.
 *
 * 'inputRequired' should be set according to if -wap-input-required has been set.
 *  (1=true 0=false -1=<not set>
 *
 * 'outStr' is the resulting string. 'outStr' must not point to the same data as 'inStr'. 
 * If outStr is NULL
 * no data is written to 'outStr' but 'outStrSize' is still calculated. If the formatted
 * string doesn't fit into 'outStr' the str is generated 'outStrSize' bytes (ie 
 * not nullterminated) and the required size is returned in 'outStrSize'.
 *
 * 'outStrSize' is an in/out parameter. At entry of the function it states 
 * the size of the 'outStr'.
 * At exit of the function it states the required size of the  'outStr'. This
 * might be used to calculate how much to allocate for the formatted string. 

*/
int 
wml_input_make_valid(const char* inStr,
                     int startSel,
                     int endSel,
                     char* newChars,
                     const char* formatStr,
                     int inputRequired,
                     char* outStr,
                     int* outStrSize)
{
  int formatStrPos = 0;
  int isMultiple = FALSE;
  int inStrPos = 0;
  int outStrPos = 0;
  int newCharsPos = 0;
  int isLanguageSpecific = FALSE;
  enum States {
    FORMAT_PARSE, 
    FORMAT_APPLY,
    FINISHED 
  };
  int multipleLimit = -1;
  char currFormat = 0;

  int inStrLen = inStr ? strlen(inStr) : 0;
  int newCharsLen = newChars ? strlen(newChars) : 0;

  int state = FORMAT_PARSE;
  int isConstant = FALSE;
  int isOk = TRUE;
  const char* pFormatStr = "*M";
  if(formatStr && strlen(formatStr))
  {
    pFormatStr = formatStr;
  }


  if(!inputRequired && (!newChars || !newChars[0]) && (endSel - startSel) == inStrLen)
  {
    state = FINISHED;
  }

  while (state != FINISHED)
  {
    switch(state)
    {
      case FORMAT_PARSE:
      {
        if(pFormatStr[formatStrPos] && multipleLimit)
        {
          if(isLanguageSpecific)
          {
            if(pFormatStr[formatStrPos] == '>')
            {
              isLanguageSpecific = FALSE;
              currFormat = 'M';
              state = FORMAT_APPLY;
              if(!isMultiple)
              {
                formatStrPos++;
              }
            }
            else
            {
              formatStrPos++;
            }
          }
          else if(isConstant)
          {
            currFormat = pFormatStr[formatStrPos];
            if(!isMultiple)
            {
              formatStrPos++;
            }
            state = FORMAT_APPLY;
          }
          else
          {
            switch (pFormatStr[formatStrPos])
            {
              case '0':
              case '1':
              case '2':
              case '3':
              case '4':
              case '5':
              case '6':
              case '7':
              case '8':
              case '9':
              {
                if(multipleLimit == -1)
                {
                  isMultiple = TRUE;
                  sscanf(&pFormatStr[formatStrPos],"%d", &multipleLimit);
                }
                formatStrPos++;
                break;
              }
              case '\\':
              {
                /*a constant*/
                isConstant = TRUE;
                formatStrPos++;
                break;
              }
              case '*':
              {
                isMultiple = TRUE;
                formatStrPos++;
                break;
              }
              case '<':
              {
                isLanguageSpecific = TRUE;
                formatStrPos++;
                break;
              }
              default:
              {
                currFormat = pFormatStr[formatStrPos];
                state = FORMAT_APPLY;
                if(!isMultiple)
                {
                  formatStrPos++;
                }
              }
            }
          }
        }
        else
        {
          state = FINISHED;
        }
        break;
      }
      case FORMAT_APPLY:
      {
        state = FORMAT_PARSE;
        if(inStr && inStrPos < startSel)
        {
          int charLen = msf_cmmn_utf8_charlen(&inStr[inStrPos]);
          if(outStr && (outStrPos < *outStrSize))
          {
            outStr[outStrPos] = inStr[inStrPos];
            wml_make_char_valid(&outStr[outStrPos], currFormat, isConstant);
          }
          if(multipleLimit != -1)
          {
            multipleLimit--;
          }
          inStrPos += charLen;
          outStrPos++;
        }
        else if(inStr && inStrPos < inStrLen || newCharsPos < newCharsLen)
        {
          if(newChars && newCharsPos < newCharsLen)
          {
            int charLen = 1;
            /*add new chars*/
            charLen = msf_cmmn_utf8_charlen(&newChars[newCharsPos]);
            if(outStr && (outStrPos < *outStrSize))
            {
              outStr[outStrPos] = newChars[newCharsPos];
              wml_make_char_valid(&outStr[outStrPos], currFormat, isConstant);
            }
            if(multipleLimit != -1)
            {
              multipleLimit--;
            }
            outStrPos++;
            newCharsPos += charLen;
            if(!isMultiple)
            {
              /*overwrite*/
              inStrPos++;
            }
          }
          else
          {
            while((inStrPos < endSel) && 
              (isMultiple && (!inputRequired || (((endSel - startSel) - inStrLen) + newCharsLen))))
            {
              /*delete selection*/
              inStrPos++;
            }
            if(inStrPos < inStrLen)
            {
              int charLen = msf_cmmn_utf8_charlen(&inStr[inStrPos]);
              if(outStr && (outStrPos < *outStrSize))
              {
                outStr[outStrPos] = inStr[inStrPos];
                wml_make_char_valid(&outStr[outStrPos], currFormat, isConstant);
              }
              if(multipleLimit != -1)
              {
                multipleLimit--;
              }
              inStrPos += charLen;
              outStrPos++;

            }
          }
        }
        else
        {
          if(isMultiple && !inputRequired)
          {
            state = FINISHED;
          }
          else
          {
            if(outStr && (outStrPos < *outStrSize))
            {
              outStr[outStrPos] = 0;
              wml_make_char_valid(&outStr[outStrPos], currFormat, isConstant);
            }
            if(multipleLimit != -1)
            {
              multipleLimit--;
            }
            outStrPos++;
          }
        }
        if(!isMultiple)
        {
          isConstant = FALSE;
        }
        inputRequired = FALSE;
      }
    }
  }
  /*add nulltermination*/
  if(outStr && (outStrPos < *outStrSize))
  {
    outStr[outStrPos] = 0;
  }
  outStrPos++;

  if(outStrPos > *outStrSize)
  {
    isOk = FALSE;
  }

  *outStrSize = outStrPos;

  return isOk;
}


#endif/*Q03C_IND_MOD_ARCH_SUPPORT*/