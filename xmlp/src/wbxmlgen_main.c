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
 *  wbxmlgen_main.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  wbxml generator file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __WBXML_SUPPORT__

//#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include "kal_release.h"        /* Basic data type */
//#include "App_buff_alloc.h"

#include "fs_type.h"
//#include "fat_fs.h"

//#include "wbxmlp.h"
#include "wbxmlp_def.h"

#include "wbxmlgen.h"
#include "wbxmlgen_def.h"

#include "fs_func.h"
#include "fs_errcode.h"
#include "xmlgen_common.h"

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_internal_api.h"


#define wbxml_generate_get_buffer     get_ctrl_buffer
#define wbxml_generate_free_buffer    free_ctrl_buffer

static wbxml_generator_struct wg_array[WG_MAX_HANDLE_NUM];
extern kal_char* wbxml_publicid_table[];





/*****************************************************************************
 * FUNCTION
 *  wbxml_new_generator
 * DESCRIPTION
 *  this function is used to create a new generator
 * PARAMETERS
 *  dest    [IN]    file or buffer to save wbxml text
 *  length  [IN]    buffer length if buffer
 * RETURNS
 *  handle of generator. 
 *      -1: means failed;
 *      0 or >0:  means succeed;
 *****************************************************************************/

WG_HANDLE wbxml_new_generator(kal_char* dest, kal_uint32 length)
{
    kal_int32 index;
    WG_HANDLE hd = -1;
    wbxml_generator_struct *p = NULL;

    if(dest == NULL)
    {
        return (WG_HANDLE)(-1);
    }
    for (index = 0; index < WG_MAX_HANDLE_NUM; index++)
    {
        if (wg_array[index].occupy == 0)
        {
            p = &(wg_array[index]);
            memset (p, 0, sizeof(wbxml_generator_struct));
            p->occupy = 1;
            hd = (WG_HANDLE)index;
            break;
        }
    }
    
    if (index == WG_MAX_HANDLE_NUM)
    {
        return (WG_HANDLE)(-1);
    }
    
    if (length == 0)    /* wbxml text will be saved to file */
    {
        p->file = FS_Open((WCHAR*)dest, FS_READ_WRITE | FS_CREATE_ALWAYS);
        if (p->file < FS_NO_ERROR)
        {
            p->occupy = 0;
            return (WG_HANDLE)(-1);
        }
    }
    else    /* wbxml text will be saved to buffer */
    {
        p->buf = dest;
        p->buflen = length;
    }
    /* malloc temp buffer */
    p->tempbuf = wbxml_generate_get_buffer(WG_BUFFER_SIZE);
    if (p->tempbuf == NULL)
    {
        p->occupy = 0;
        return (WG_HANDLE)(-1);
    }
    return hd;
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_close_generator
 * DESCRIPTION
 *  this function is used to close a generator
 * PARAMETERS
 *  hd    [IN]    handle of generator
 * RETURNS
 *      -1: means failed;
 *      >=0 :  means succeed, returns generated data length in dest buffer or file
 *****************************************************************************/

kal_int32 wbxml_close_generator(WG_HANDLE hd)
{
    wbxml_generator_struct *p = NULL;
    kal_uint32 length;


    if ((hd < 0) || (hd >= WG_MAX_HANDLE_NUM))
    {
        return -1;
    }
    p = &(wg_array[hd]);

    if(p->file != 0)
    {
        FS_Close(p->file);       
    }
    if (p->tempbuf != NULL)
    {
        wbxml_generate_free_buffer(p->tempbuf);
    }

    if (p->curdepth != 0)  
    {
        memset(p, 0, sizeof(wbxml_generator_struct));
        return XG_E_MISMATCH_TAG;
    }
    length = p->curlen;
    memset(p, 0, sizeof(wbxml_generator_struct));
    return length;
}

/*****************************************************************************
* FUNCTION
*  wbxml_register_get_token_handler
* DESCRIPTION
*  this function is used to register get token handler
* PARAMETERS
*  handle                       [IN]        handle of parser struct for application
*  get_token_by_tagname         [IN]        Function handler to get token by tagname
*  get_token_by_attrname        [IN]        Function handler to get token by attrname 
*  get_token_by_attrvalue       [IN]        Function handler to get token by attrvalue 
* RETURNS
*  void
*****************************************************************************/
void wbxml_register_get_token_handler(WG_HANDLE handle, wbxml_get_token_by_tagname get_token_by_tagname, 
        wbxml_get_token_by_attrname get_token_by_attrname, wbxml_get_token_by_attrvalue get_token_by_attrvaule)
                                     
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    wg_array[handle].get_token_by_tagname = 
        (get_token_by_tagname == NULL)? wbxml_default_get_tagtoken_hdlr : get_token_by_tagname;
    wg_array[handle].get_token_by_attrname =
        (get_token_by_attrname == NULL)? wbxml_default_get_attrnametoken_hdlr : get_token_by_attrname;
    wg_array[handle].get_token_by_attrvalue =
        (get_token_by_attrvaule == NULL)? wbxml_default_get_attrvaluetoken_hdlr : get_token_by_attrvaule;

    
}

/*****************************************************************************
* FUNCTION
*  wbxml_default_get_tagtoken_hdlr
* DESCRIPTION
*  this function is used to get tagtoken by tagname 
* PARAMETERS
*  tagname          [IN]        tagname
*  tagcp            [IN]        tag space code page
*  token            [OUT]       token of tag returned by application
* RETURNS
*  -1: cannot find tagtoken for such tagname
*  0: success
*****************************************************************************/

static kal_int32 wbxml_default_get_tagtoken_hdlr(const kal_char *tagname, kal_uint8 tagcp,  kal_uint8* token)
{
    return -1;
}


/*****************************************************************************
* FUNCTION
*  wbxml_default_get_attrnametoken_hdlr
* DESCRIPTION
*  this function is used to get attrtoken by attrname 
* PARAMETERS
*  attrname         [IN]        attrname
*  attrcp           [IN]        attribute code page
*  token            [OUT]       token for attribute name
* RETURNS
*  -1: cannot find tagtoken for such tagname
*  0: success
*****************************************************************************/
static kal_int32 wbxml_default_get_attrnametoken_hdlr(const kal_char *attrname, kal_uint8 attrcp, kal_uint8* token, void *reserved)
{
    return -1;

}

/*****************************************************************************
* FUNCTION
*  wbxml_default_get_attrvaluetoken_hdlr
* DESCRIPTION
*  this function is used to get attrtoken by attrname 
* PARAMETERS
*  attrvalue        [IN]        attrvalue
*  attrcp           [IN]        attribute code page
*  token           [OUT]       token for attribute value
* RETURNS
*  -1: cannot find tagtoken for such tagname
*  0: success
*****************************************************************************/
static kal_int32 wbxml_default_get_attrvaluetoken_hdlr(const kal_char *attrvalue, kal_uint8 attrcp, kal_uint8 *token, kal_uint8 *datatype)
{
    return -1;

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_generate_header
 * DESCRIPTION
 *  this function is used to generate xml declaration like this:
 *  <?xml version="1.0" encoding="UTF-8" ?>
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  mainver     [IN]    main version, is number between 0 and 9
 *  subver      [IN]    sub version, is number between 0 and 9
 *  encode      [IN]    encoding type, is a value of XML_ENCODING_TYPE_ENUM
 * RETURNS
 *      <0:  means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32 wbxml_generate_header(WG_HANDLE hd, kal_uint8 mainver, kal_uint8 subver, const kal_char* publicid, wbxml_charset_type_enum charset)
{
    kal_uint8 ver, id = 0, encode;
    kal_uint8 i;
    kal_uint32 len_strtbl = 0, textlen = 0;
    kal_int32 ret;
    wbxml_generator_struct *p = NULL;

    /* first check if parameters are correct */
    if ((hd < 0) || (hd >= WG_MAX_HANDLE_NUM))
    {
        return XG_E_FAIL;
    }
    if (publicid == NULL)
    {
        return XG_E_FAIL;
    }

    p = &(wg_array[hd]);
    p->tempbuf[0] = 0;

    /* construct version value */
    ver = ((mainver-1)<<4) | (subver&0x0F);
    memcpy(p->tempbuf, &ver, 1);
    textlen++;

    /* define publicid value */
    for(i = 1; i <WBXML_NUM_PUBLICID; i++)
    {
        if ((strcmp(wbxml_publicid_table[i], publicid)) == 0)
        {
            id = i;
            memcpy(p->tempbuf+textlen, &id, 1);
            textlen++;
            break;
        }
    }
    if (i == WBXML_NUM_PUBLICID)
    {
        kal_uint8 index = 0;
        id = 0;
        memcpy(p->tempbuf+textlen, &id, 1); /* publicid token is 0*/
        textlen++;
        memcpy(p->tempbuf+textlen, &index, 1); /* index in string table is 0 */
        textlen++;
    }


    /* define charset, need to consider if encode is multibyte in future */
    switch(charset)
    {
        case WBXML_CHARSET_ISO_8859_1:
            encode = 0x04;    
            break;
        case WBXML_CHARSET_ISO_8859_2:
            encode = 0x05;
            break;
        case WBXML_CHARSET_ISO_8859_3:
            encode = 0x06;
            break;
        case WBXML_CHARSET_ISO_8859_4:
            encode = 0x07;
            break;
        case WBXML_CHARSET_ISO_8859_5:
            encode = 0x08;
            break;
        case WBXML_CHARSET_ISO_8859_6:
            encode = 0x09;
            break;   
        case WBXML_CHARSET_ISO_8859_7:
            encode = 0x0A;
            break; 
        case WBXML_CHARSET_ISO_8859_8:
            encode = 0x0B;
            break; 
        case WBXML_CHARSET_ISO_8859_9:
            encode = 0x0C;
            break;   
        case WBXML_CHARSET_SHIFT_JIS:
            encode = 0x11;
            break; 
        case WBXML_CHARSET_US_ASCII:
            encode = 0x03;
            break;      
        case WBXML_CHARSET_UTF_8:
            encode = 0x6A;
            break;             
        default:
            return XG_E_UNKNOWN_CHARSET;
    }
    memcpy(p->tempbuf+textlen, &encode, 1);
    textlen++;

    /* construct string table */
    if (id == 0)
    {
        kal_uint8 octets[5], bytes;
                
        len_strtbl = strlen(publicid)+1;
        bytes = wbxml_trans_int_to_mb(len_strtbl, octets, 5);
        if ((textlen + len_strtbl + bytes) > WG_BUFFER_SIZE)
        {
            return XG_E_OVER_BUFFER;
        }
        memcpy(p->tempbuf+textlen, octets, bytes); 
        textlen += bytes;
        memcpy(p->tempbuf+textlen, publicid, len_strtbl);
        textlen += len_strtbl;
    }
    else
    {
        memcpy(p->tempbuf+textlen, &len_strtbl, 1);
        textlen++;
    }
//    ASSERT(textlen <= WG_BUFFER_SIZE);

    /* write wbxml text to file or buffer */
    if (((ret = wbxml_generate_flash_text(hd, p->tempbuf, textlen)) < 0))
    {
        return ret;
    }
    return XG_RESULT_OK;
    
}
/*****************************************************************************
 * FUNCTION
 *  wbxml_generate_stag
 * DESCRIPTION
 *  This function is for application to generate start tag as following:
 *  <book1 auther="John" title="XML SPEC"> 
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  el          [IN]    element name
 *  attrlist    [IN]    attribute struct array.
 *                      If no attribute, attrlist should be NULL, and num_attr should be 
 *  num_attr    [IN]    number of attribute struct
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/

kal_int32 wbxml_generate_stag(WG_HANDLE hd, const kal_char* el, xg_attr_struct* attrlist, kal_uint32 num_attr, kal_bool iscontent)
{
    wbxml_generator_struct *p = NULL;
    kal_uint32 textlen = 0, index;
    kal_int32 ret;
    kal_uint8 gtoken, token, token1, token2 = 0, datatype = WBXML_DATA_TYPE_STRING;
 
    /* first check if parameters are correct */
    if ((hd < 0) || (hd >= WG_MAX_HANDLE_NUM))
    {
        return XG_E_FAIL;
    }
    if (el == NULL)
    {
        return XG_E_FAIL;
    }
    if ((attrlist == NULL) && (num_attr != 0))
    {
        return XG_E_FAIL;
    }
    
    if (num_attr > WBXML_MAX_ATTR_COUNT/2) /* only support  WBXML_MAX_ATTR_COUNT attribute*/
    {
        return XG_E_FAIL;
    }
        
    p = &(wg_array[hd]);
    p->tempbuf[0] = 0;

    /* get token of tag name */
    if ((ret = p->get_token_by_tagname(el, p->tagcp, &token)) != 0)
    {
        return XG_E_UNKNOWN_TAG;
    }

    /* if tag code page needs to be change, set new tag code page */
    if (p->istagcpchange)
    {
        gtoken = WBXML_GT_SWITCH_PAGE;
        memcpy(p->tempbuf, &gtoken, 1);
        textlen++;
        memcpy(p->tempbuf + textlen, &(p->tagcp), 1); 
        textlen++;
        p->istagcpchange = 0;
    }

    /* if content is exist, set content mark on token */
    if (iscontent)
    {
        token |= 0x40;
    }

      
    /* if attribute code page needs to be change, set new attribute code page */
    if (num_attr != 0)
    {
        if (p->isattrcpchange)
        {
            gtoken = WBXML_GT_SWITCH_PAGE;
            memcpy(p->tempbuf, &gtoken, 1);
            textlen++;
            memcpy(p->tempbuf + textlen, &(p->attrcp), 1);
            textlen++;
            p->isattrcpchange = 0;
        }
        token |= 0x80;
    }
    
    memcpy(p->tempbuf+textlen, &token, 1);
    textlen++;


    /* get attribute token */
    for (index = 0; index < num_attr; index++)
    {
//        ASSERT(attrlist != NULL);
        
        ret = p->get_token_by_attrname(attrlist[index].attrname, p->attrcp, &token1, NULL);
        if (ret != 0)
        {
            return XG_E_UNKNOWN_TAG;
        }

        memcpy(p->tempbuf+textlen, &token1, 1);
        textlen++;

        ret = p->get_token_by_attrvalue(attrlist[index].attrvalue, p->attrcp, &token2, &datatype);
        if (ret != 0)
        {
            return XG_E_UNKNOWN_TAG;
        }

        if (token2 != 0)
        {/* can find token for such attrvalue */

            if (datatype == WBXML_DATA_TYPE_EXT_T_0)
            {
                gtoken = WBXML_GT_EXT_T_0;
                memcpy(p->tempbuf+textlen, &gtoken, 1);
                textlen++;
            }
                
            memcpy(p->tempbuf+textlen, &token2, 1);
            textlen++;
        }
        else
        {/* cannot find token for such attrvalue, construct it according to datatype */

            switch(datatype)
            {
            case WBXML_DATA_TYPE_STRING:
                gtoken = WBXML_GT_STR_I;
                memcpy(p->tempbuf+textlen, &gtoken, 1);
                textlen++;
                break;
            default:
                return XG_E_FAIL;
            }
            if ((textlen + strlen(attrlist[index].attrvalue)+1) >= WG_BUFFER_SIZE)
            {
                return XG_E_OVER_BUFFER;
            }
            memcpy(p->tempbuf+textlen, attrlist[index].attrvalue, strlen(attrlist[index].attrvalue)+1);
            textlen += strlen(attrlist[index].attrvalue)+1; //including terminator 0
        }

    }
    /* if attribute exist, set attribute end token */
    if ((index != 0)&&(index == num_attr))
    {
        gtoken = WBXML_GT_END;
        memcpy(p->tempbuf+textlen, &gtoken, 1);
        textlen++;
    }
//    ASSERT(textlen <= WG_BUFFER_SIZE);

    /* write wbxml text to file or buffer */
    if (((ret = wbxml_generate_flash_text(hd, p->tempbuf, textlen)) < 0))
    {
        return ret;
    }
    p->curdepth++;
    return XG_RESULT_OK;
    
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_generate_empty_element
 * DESCRIPTION
 *  This function is for application to generate empty which has no content and
 *  end tag as following: 
 *  <b b1="m" b2="n" />

 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  el          [IN]    element name
 *  attrlist    [IN]    attribute struct array.
 *                      If no attribute, attrlist should be NULL, and num_attr should be 
 *  num_attr    [IN]    number of attribute struct
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32 wbxml_generate_empty_element(WG_HANDLE hd, const kal_char* el, xg_attr_struct* attrlist, kal_uint32 num_attr)
{
    wg_array[hd].curdepth--;
    return wbxml_generate_stag(hd, el, attrlist, num_attr, KAL_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  xml_generate_inline_element
 * DESCRIPTION
 *  This function is for application to generate a whole element without child element
 *  and attribute, only content. just as following: <a> test </a>.
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  el          [IN]    element name
 *  data        [IN]    Filename or buffer with data. 
 *  datalen     [IN]    if with buffer, datalen is the length of buffer, 
 *                      if with file, datalen should be 0
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32 wbxml_generate_inline_element(WG_HANDLE hd, const kal_char* el, kal_char* data, kal_uint32 datalen, kal_uint8 datatype)
{
    kal_int32 ret;

    if (data == NULL)
    {
        return XG_E_FAIL;
    }
    if ((ret = wbxml_generate_stag(hd, el, NULL, 0, KAL_TRUE)) < 0)
    {
        return ret;
    }
    if ((ret = wbxml_generate_data(hd, data, datalen, (wbxml_data_type_enum)datatype)) < 0)
    {
        return ret;
    }
    return wbxml_generate_etag(hd, el);
    
}

/*****************************************************************************
* FUNCTION
*  wbxml_generate_data
* DESCRIPTION
*  This function is for application to generate element content.
*  Application can pass data with file or buffer. If with file, data is the 
*  file name encoded with Unicode, datalen should be 0; if with buffer, data
*  is ptr to buffer, datalen is the length of buffer
* PARAMETERS
*  hd           [IN]    handle of generator
*  data         [IN]    Filename or buffer with data. 
*  datalen      [IN]    if with buffer, datalen is the length of buffer, for inline
*                       string, datalen includes terminator "0"
*                       if with file, datalen should be 0.
*  data_type    [IN]    type of data, is a value of WBXML_DATA_TYPE_ENUM
* RETURNS
*      <0: means failed, returns error code;
*      0 :  means succeed;
 *****************************************************************************/
kal_int32 wbxml_generate_data(WG_HANDLE hd, kal_char* data, kal_uint32 datalen, wbxml_data_type_enum data_type)
{
    wbxml_generator_struct *p = NULL;
    kal_uint32 textlen = 0, length;
    kal_uint8 gtoken, multibytes[5], bytes; 
    FS_HANDLE fhandle;
    kal_int32 ret;

    kal_uint8 token2 = 0, datatype = WBXML_DATA_TYPE_STRING;    

    /* first check if parameters are correct */
    if ((hd < 0) || (hd >= WG_MAX_HANDLE_NUM))
    {
        return XG_E_FAIL;
    }
    if (data == NULL)
    {
        return XG_E_FAIL;
    }
    p = &(wg_array[hd]);

    if (datalen != 0)
    {
        ret = p->get_token_by_attrvalue(data, p->attrcp, &token2, &datatype);

        if (token2 != 0)
        {
            /* can find token for such attrvalue */
            if (datatype == WBXML_DATA_TYPE_EXT_T_0)
            {
                gtoken = WBXML_GT_EXT_T_0;
                memcpy(p->tempbuf+textlen, &gtoken, 1);
                textlen++;

                /* transfer data length to multibytes */
                bytes = wbxml_trans_int_to_mb(token2, multibytes, 5);
                memcpy(p->tempbuf+textlen, multibytes, bytes);
                textlen += bytes;

                return wbxml_generate_flash_text(hd, p->tempbuf, textlen);
            }
        }
    }

    switch(data_type)
    {
    case WBXML_DATA_TYPE_STRING:
        gtoken = WBXML_GT_STR_I;
        memcpy(p->tempbuf, &gtoken, 1);
        textlen++;
        break;
    case WBXML_DATA_TYPE_OPAQUE:
        gtoken = WBXML_GT_OPAQUE;
        memcpy(p->tempbuf, &gtoken, 1);
        textlen++;
        /* to get data length if data in file */
        if(datalen == 0)/* data is in file */
        {
            fhandle = FS_Open((WCHAR*)data, FS_READ_ONLY);
            if (fhandle < 0)
            {
                return XG_E_FAIL;
            }
            ret = FS_GetFileSize(fhandle, &length);
            if (ret < 0)
            {
                FS_Close(fhandle);
                return XG_E_FAIL;
            }   
            FS_Close(fhandle);
        }
        else    /* data is in buffer, length is datalen */
        {
            length = datalen;
        }
        /* transfer data length to multibytes */
        bytes = wbxml_trans_int_to_mb(length, multibytes, 5);
        memcpy(p->tempbuf+textlen, multibytes, bytes);
        textlen += bytes;
        break;
    default:
        return XG_E_FAIL;

    }
 //   ASSERT(textlen <= WG_BUFFER_SIZE);
    
    ret = wbxml_generate_flash_text(hd, p->tempbuf, textlen);
    if (ret < 0)
    {
        return ret;
    }
    ret = wbxml_generate_flash_text(hd, data, datalen);
    if (ret < 0)
    {
        return ret;
    }
    if((datalen == 0) && (data_type == WBXML_DATA_TYPE_STRING))
    { /* if inline string is in file, we need to strcat terminated 0 after it, because data read from file doesn't include 0 */
        gtoken = 0;
        return wbxml_generate_flash_text(hd, (kal_char*)&gtoken, 1);
    }
    return XG_RESULT_OK;
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_generate_etag
 * DESCRIPTION
 *  This function is for application to generate end tag as following:
 *  </book1>
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  el          [IN]    element name
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32  wbxml_generate_etag(WG_HANDLE hd, const kal_char* el)
{
    wbxml_generator_struct *p = NULL;
    kal_uint8 gtoken;

    /* first check if parameters are correct */
    if ((hd < 0) || (hd >= WG_MAX_HANDLE_NUM))
    {
        return XG_E_FAIL;
    }
    
    p = &(wg_array[hd]);
    gtoken = WBXML_GT_END;
    p->curdepth--;
    return wbxml_generate_flash_text(hd, (kal_char*)&gtoken, 1);
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_generate_set_tagcp
 * DESCRIPTION
 *  This function is for application to set tag code page. if application want to
 *  transfer tag code page, this function is called.
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  tagcp       [IN]    tag code page
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32 wbxml_generate_set_tagcp(WG_HANDLE hd, kal_uint8 tagcp)
{
    wbxml_generator_struct *p  = NULL;

    
    /* first check if parameters are correct */
    if ((hd < 0) || (hd >= WG_MAX_HANDLE_NUM))
    {
        return XG_E_FAIL;
    }

    p = &(wg_array[hd]);
    p->tagcp = tagcp;
    p->istagcpchange = 1;
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_generate_set_attrcp
 * DESCRIPTION
 *  This function is for application to set attribute code page. if application want to
 *  transfer attribute code page, this function is called.
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  attrcp      [IN]    attribute code page
 * RETURNS
 *      <0: means failed, returns error code;
 *      0 :  means succeed;
 *****************************************************************************/
kal_int32 wbxml_generate_set_attrcp(WG_HANDLE hd, kal_uint8 attrcp)
{
    wbxml_generator_struct *p  = NULL;

    
    /* first check if parameters are correct */
    if ((hd < 0) || (hd >= WG_MAX_HANDLE_NUM))
    {
        return XG_E_FAIL;
    }

    p = &(wg_array[hd]);
    p->attrcp = attrcp;
    p->isattrcpchange = 1;
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_generate_flash_text
 * DESCRIPTION
 *  this function is used to write xml text to file or buffer
 * PARAMETERS
 *  hd          [IN]    handle of generator
 *  text        [IN]    xml text. text can be a filename encoded in wchar, or buffer.
 *  textlen     [IN]    if xml text is in file, len is 0, else len is the length of text buffer
 * RETURNS
 *  handle of generator. 
 *      <0 : means failed, returns error code;
 *      >0 :  means succeed, returns the length of text written;
 *****************************************************************************/

static kal_int32 wbxml_generate_flash_text(kal_int8 hd, kal_char *text, kal_uint32 textlen)
{
    kal_uint32 length, len;
    kal_int32 ret;
    FS_HANDLE fhandle = -1;
    wbxml_generator_struct *p = NULL;

/* first to get xml text length */
    if(textlen == 0)/* text is in file */
    {
        fhandle = FS_Open((WCHAR*)text, FS_READ_ONLY);
        if (fhandle < 0)
        {
            return XG_E_FAIL;
        }
        ret = FS_GetFileSize(fhandle, &length);
        if (ret < 0)
        {
            FS_Close(fhandle);
            return XG_E_FAIL;
        }       
    }
    else /* text is in buffer */
    {
        length = textlen;
    }

    p = &(wg_array[hd]);
        
/* then write xml text to dest */
    if(p->buf != NULL)     /* write xml text to buffer */    
    {
        /* verify if over-buffer */
        if(p->curlen+length > p->buflen)
        {
            if(fhandle != -1)
            {
                FS_Close(fhandle);
            }
            ASSERT(0);
            kal_printf("buffer to save is overflow!!!!\r\n");
            return XG_E_OVER_BUFFER;            
        }
        if (textlen != 0) /* text is in buffer, write xml text from buffer to buffer */
        {
            memcpy(p->buf+p->curlen, text, textlen);
            len = textlen;
            ret = 0;
        }
        else /* text is in file, write xml text from file to buffer */
        {
            ret = xml_generate_write_filetobuf(p->buf+p->curlen, fhandle, &len);
            FS_Close(fhandle);
        }
    }
    else /* write xml text to file */
    {
        if (textlen != 0) /* text is in buffer, write xml text from buffer to file */
        {
            ret = FS_Write(p->file, text, length, &len);
        }
        else    /* text is in file, write xml text from file to file */
        {
            ret = xml_generate_write_filetofile(p->file, fhandle, &len);
            FS_Close(fhandle);     
        }
    }
    if (ret < 0)
    {
        return ret;
    }  
    else
    {
        p->curlen += len;
        return len; 
    }
    
    
}

/*****************************************************************************
* FUNCTION
*  test_wbxmlp
* DESCRIPTION
*  this function is used to test wbxml parser
* PARAMETERS
*  void
* RETURNS
* void
*****************************************************************************/
static kal_int32 wbxml_trans_int_to_mb(kal_int32 value, kal_uint8 *pbuf, kal_uint32 buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    kal_uint8 octets[5];/* 5 bytes is enough to store multi-byte int32 */
    kal_int32 i, start, octlen;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pbuf == NULL || buflen < 1)
    {
        return 0;
    }
    
    /* firstly handle the last byte, because there is no continue-marke in it and must be encoded */
    octets[4] = (kal_uint8)(value & 0x7f);
    
    for (i = 3; (((kal_uint32)value) > 0x7f) && i >= 0; i--)
    {
        value >>= 7;
        octets[i] = (kal_uint8)(0x80 | (value & 0x7f));
    }
    
    start = i + 1;      /* start means the real start byte in octets */
    octlen = 5 - start; /* octLen means the real length of data in octets */
    
    if (octlen > buflen)
        return 0;
    
    memcpy(pbuf, &octets[start], octlen);
    
    return octlen;
}

#endif     /* __WBXML_SUPPORT__ */
