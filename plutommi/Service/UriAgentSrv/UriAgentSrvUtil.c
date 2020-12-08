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
 *    UriAgentSrvUtil.c
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    URI Agent Utilities
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

 /***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_URI_AGENT__
#include <string.h>

#include "MMIDataType.h"
#include "kal_general_types.h"

/***************************************************************************** 
 * Defines
 *****************************************************************************/
#define IS_ALPHA(c)        (((c >= 'a') && (c <= 'z')) || ((c >= 'A') && (c <= 'Z')))
#define IS_DIGIT(c)        ((c >= '0') && (c <= '9'))
#define IS_ALPHADIGIT(c)   (IS_ALPHA(c) || IS_DIGIT(c))

/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_check_validity_of_prefix
 * DESCRIPTION
 *  Check the valitity of URI prefix
 * PARAMETERS
 *  prefix      [IN]        URI prefix (null terminated string)
 * RETURNS
 *  MMI_TRUE: This prefix is valid
 *  MMI_FALSE: This prefix is invalid
 *****************************************************************************/
MMI_BOOL srv_uriagent_check_validity_of_prefix(const char *prefix)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * prefix = scheme ":" format
     * scheme = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." ) 
     * format = *(CHARACTER) 
     */

    /* prefix cannot be empty; the first character of prefix should be ALPHA; ':' should exist in prefix */
    if (!prefix || prefix[0] == '\0' || !IS_ALPHA(*prefix) || strchr(prefix, ':') == NULL)
    {
        return MMI_FALSE;
    }

    for (index = 0; index < strlen(prefix); index++)
    {
        char ch = prefix[index];

        if (ch == ':')
        {
            return MMI_TRUE;
        }
        if (!IS_ALPHADIGIT(ch) && (ch != '+') && (ch != '-') && (ch != '.'))
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_uriagent_check_validity_of_scheme
 * DESCRIPTION
 *  Check the validity of URI scheme
 * PARAMETERS
 *  scheme      [IN]        URI scheme (null terminated string)
 * RETURNS
 *  MMI_TRUE: This scheme is valid
 *  MMI_FALSE: This scheme is invalid
 *****************************************************************************/
MMI_BOOL srv_uriagent_check_validity_of_scheme(const char *scheme)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* scheme = ALPHA *( ALPHA / DIGIT / "+" / "-" / "." ) */

    /* scheme cannot be empty; the first character of scheme should be ALPHA. */
    if (!scheme || scheme[0] == '\0' || !IS_ALPHA(*scheme))
    {
        return MMI_FALSE;
    }

    for (index = 0; index < strlen(scheme); index++)
    {
        char ch = scheme[index];

        if (!IS_ALPHADIGIT(ch) && (ch != '+') && (ch != '-') && (ch != '.'))
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}

#endif /* __MMI_URI_AGENT__ */ 

