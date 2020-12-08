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
 *   jvm_cache.cpp
 *
 * Project:
 * --------
 *   Maui_Software
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
#include "kal_release.h"
#include "jvm_interface.h"
#include "jvm_base64.h"

static kal_char ALPHABET[] = 
{
    /* 0    1    2    3    4    5    6    7 */
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', /* 0 */
    'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', /* 1 */
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', /* 2 */
    'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', /* 3 */
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', /* 4 */
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', /* 5 */
    'w', 'x', 'y', 'z', '0', '1', '2', '3', /* 6 */
    '4', '5', '6', '7', '8', '9', '+', '/'  /* 7 */
};


/*****************************************************************************
 * FUNCTION
 *  jvm_base64_encode_3_bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in              [?]         
 *  in_length       [IN]        
 *  out             [?]         
 *  fmt(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline void jvm_base64_encode_3_bytes(kal_uint8 *in, kal_int32 in_length, kal_uint8 *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    register kal_uint8 a = 0, b = 0, c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(in != NULL && in_length > 0);
    ASSERT(out != NULL);

    a = in[0];
    out[0] = ALPHABET[(a >> 2) & 0x3F];

    if (in_length > 2)
    {
        b = in[1];
        c = in[2];
        out[1] = ALPHABET[((a << 4) & 0x30) + ((b >> 4) & 0xf)];
        out[2] = ALPHABET[((b << 2) & 0x3c) + ((c >> 6) & 0x3)];
        out[3] = ALPHABET[c & 0x3F];
    }
    else if (in_length > 1)
    {
        b = in[1];
        out[1] = ALPHABET[((a << 4) & 0x30) + ((b >> 4) & 0xf)];
        out[2] = ALPHABET[((b << 2) & 0x3c)];
        out[3] = '=';
    }
    else
    {
        out[1] = ALPHABET[((a << 4) & 0x30)];
        out[2] = '=';
        out[3] = '=';
    }

}


/*****************************************************************************
 * FUNCTION
 *  jvm_base64_encode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in              [?]         
 *  in_length       [IN]        
 *  out_length      [?]         
 *  fmt(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 *jvm_base64_encode(kal_uint8 *in, kal_int32 in_length, kal_int32 *out_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 in_index, out_index;
    kal_uint8 *out = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_length <= 0)
    {
        *out_length = 0;
        return NULL;
    }
    ASSERT(in != NULL);

    *out_length = (in_length + 2) / 3 * 4;
    out = (kal_uint8*) jvm_malloc(*out_length * sizeof(kal_uint8));
    ASSERT(out != NULL);
    memset(out, 0x00, *out_length * sizeof(kal_uint8));

    for (in_index = 0, out_index = 0; out_index < *out_length; in_index += 3, out_index += 4)
    {
        jvm_base64_encode_3_bytes(in + in_index, in_length - in_index, out + out_index);
    }

    return out;
}


/*****************************************************************************
 * FUNCTION
 *  jvm_base64_decode_alphabet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  alphabet        [IN]        
 *  fmt(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline kal_uint8 jvm_base64_decode_alphabet(kal_uint8 alphabet)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char data = (kal_char) alphabet;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data >= 'A' && data <= 'Z')
        return data - 'A';
    if (data >= 'a' && data <= 'z')
        return data - 'a' + 26;
    if (data >= '0' && data <= '9')
        return data - '0' + 52;

    if (data == '+')
        return 62;
    else if (data == '/')
        return 63;
    else if (data == '=')
        return 64;

    ASSERT(0);
    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  jvm_base64_decode_4bytes
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in              [?]         
 *  in_length       [IN]        
 *  out             [?]         
 *  fmt(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
__inline void jvm_base64_decode_4bytes(kal_uint8 *in, kal_int32 in_length, kal_uint8 *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 a = 0, b = 0, c = 0, d = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(in_length % 4 == 0);

    a = jvm_base64_decode_alphabet(in[0]);
    b = jvm_base64_decode_alphabet(in[1]);
    c = jvm_base64_decode_alphabet(in[2]);
    d = jvm_base64_decode_alphabet(in[3]);

    out[0] = ((a << 2) & 0xFC) | ((b >> 4) & 0x03);
    if (c != 64 && d != 64)  
    {
        out[1] = ((b << 4) & 0xF0) | ((c >> 2) & 0x0F);
        out[2] = ((c << 6) & 0xFC) | (d & 0x3F);
    }
    else
    {
        if (c == 64)  
            out[1] = (b << 4) & 0xF0;
        if (d == 64)  
            out[2] = (c << 6) & 0xFC;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jvm_base64_decode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  in              [?]         
 *  in_length       [IN]        
 *  out_length      [?]         
 *  fmt(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 *jvm_base64_decode(kal_uint8 *in, kal_int32 in_length, kal_int32 *out_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 in_real_length;
    kal_int32 index, out_index;
    kal_uint8 *out;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (in_length <= 0)
    {
        *out_length = 0;
        return NULL;
    }

    ASSERT(in != NULL);
    ASSERT(in_length % 4 == 0);

    in_real_length = in_length;
    for (index = in_length - 1; index >= 0 && in[index] == '='; index--, in_real_length--);

    *out_length = in_length * 3 / 4 - (in_length - in_real_length);
    out = (kal_uint8*) jvm_malloc(*out_length * sizeof(kal_uint8));
    ASSERT(out != NULL);
    memset(out, 0x00, *out_length * sizeof(kal_uint8));

    for (index = 0, out_index = 0; index < in_length; index += 4, out_index += 3)
    {
        jvm_base64_decode_4bytes(in + index, in_length - index, out + out_index);
    }
    return out;
}

