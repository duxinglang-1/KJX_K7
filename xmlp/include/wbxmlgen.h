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
 *  wbxmlgen.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  wbxml generator extern header file
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
#ifndef WBXMLGEN_H
#define WBXMLGEN_H
#ifdef __WBXML_SUPPORT__

#include "kal_general_types.h"
#include "xmlgen_common.h"

/* define data type */
typedef enum{
    WBXML_DATA_TYPE_STRING, /* string */
    WBXML_DATA_TYPE_OPAQUE,  /* qpaque */
    WBXML_DATA_TYPE_EXT_T_0
}wbxml_data_type_enum;

/* define charset type */
typedef enum{
    WBXML_CHARSET_ISO_8859_1,   /* iso-8859-1 */
    WBXML_CHARSET_ISO_8859_2,   /* iso-8859-2 */
    WBXML_CHARSET_ISO_8859_3,   /* iso-8859-3 */
    WBXML_CHARSET_ISO_8859_4,   /* iso-8859-4 */
    WBXML_CHARSET_ISO_8859_5,   /* iso-8859-5 */
    WBXML_CHARSET_ISO_8859_6,   /* iso-8859-6 */
    WBXML_CHARSET_ISO_8859_7,   /* iso-8859-7 */
    WBXML_CHARSET_ISO_8859_8,   /* iso-8859-8 */
    WBXML_CHARSET_ISO_8859_9,   /* iso-8859-9 */
    WBXML_CHARSET_SHIFT_JIS,    /* shift-jis */
    WBXML_CHARSET_US_ASCII,     /* us-ascii */
    WBXML_CHARSET_UTF_8         /* utf-8 */
}wbxml_charset_type_enum;

/* file handle */
typedef kal_int8 WG_HANDLE;


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  wbxml_get_token_by_tagname
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 *  tagname:         [IN]        tag name
 *  tagcp:           [IN]        tag space code page
 *  token:           [IN]        token of tag
 * RETURN VALUES
 *  -1: over 2048bytes
 *  0: cannot find tagname for such token
 *  >0: success
 *****************************************************************************/
typedef kal_int32 (*wbxml_get_token_by_tagname)(
                    const kal_char *tagname,
                    kal_uint8 tagcp,
                    kal_uint8* token);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  wbxml_get_token_by_attrname
 * DESCRIPTION
 *  this function is used to get attrname by token 
 * PARAMETERS
 *  attrname:        [IN]        attribute name
 *  attrcp:          [IN]        attribute code page
 *  token:           [IN]        token of attrstart or attrvalue
 *  reserved:        [IN]        reserved
 * RETURN VALUES
 *  -1: over 2048bytes
 *  0: cannot find tagname for such token
 *  >0: success
 *****************************************************************************/
typedef kal_int32 (*wbxml_get_token_by_attrname)(
                    const kal_char *attrname,
                    kal_uint8 attrcp,
                    kal_uint8* token,
                    void *reserved);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  wbxml_get_token_by_attrvalue
 * DESCRIPTION
 *  this function is used to get attrname by token 
 * PARAMETERS
 *  attrvalue:        [IN]       attribute name
 *  attrcp:          [IN]        attribute code page
 *  token:           [IN]        token of attrstart or attrvalue
 *  reserved:        [IN]        reserved
 * RETURN VALUES
 *  -1: over 2048bytes
 *  0: cannot find tagname for such token
 *  >0: success
 *****************************************************************************/
typedef kal_int32 (*wbxml_get_token_by_attrvalue)(
                    const kal_char *attrvalue,
                    kal_uint8 attrcp,
                    kal_uint8 *token,
                    kal_uint8 *reserved);


/*****************************************************************************
 * FUNCTION
 *  wbxml_new_generator
 * DESCRIPTION
 *  this function is used to create a new generator
 * PARAMETERS
 *  dest:    [IN]    file or buffer to save wbxml text
 *  length:  [IN]    buffer length if buffer
 * RETURN VALUES
 *  -1: means failed;
 *  0 or >0:  means succeed;
 *****************************************************************************/
extern WG_HANDLE wbxml_new_generator(kal_char* dest, kal_uint32 length);


/*****************************************************************************
 * FUNCTION
 *  wbxml_close_generator
 * DESCRIPTION
 *  this function is used to close a generator
 * PARAMETERS
 *  hd:    [IN]    handle of generator
 * RETURN VALUES
 *  -1: means failed;
 *  >=0 :  means succeed, returns generated data length in dest buffer or file
 *****************************************************************************/
extern kal_int32 wbxml_close_generator(WG_HANDLE hd);


/*****************************************************************************
* FUNCTION
*  wbxml_register_get_token_handler
* DESCRIPTION
*  this function is used to register get token handler
* PARAMETERS
*  handle:                       [IN]        handle of parser struct for application
*  get_token_by_tagname:         [IN]        Function handler to get token by tagname
*  get_token_by_attrname:        [IN]        Function handler to get token by attrname
*  get_token_by_attrvalue:       [IN]        Function handler to get token by attrvalue
* RETURNS
*  void
*****************************************************************************/
extern void wbxml_register_get_token_handler(
                WG_HANDLE  handle,
                wbxml_get_token_by_tagname get_token_by_tagname,
                wbxml_get_token_by_attrname get_token_by_attrname,
                wbxml_get_token_by_attrvalue get_token_by_attrvalue);


/*****************************************************************************
 * FUNCTION
 *  wbxml_generate_header
 * DESCRIPTION
 *  this function is used to generate xml declaration like this:
 *  <?xml version="1.0" encoding="UTF-8" ?>
 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  mainver:     [IN]    main version, is number between 0 and 9
 *  subver:      [IN]    sub version, is number between 0 and 9
 *  publicid:    [IN]    public id
 *  charset:     [IN]    charset
 * RETURN VALUES
 *  <0:  means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 wbxml_generate_header(
                    WG_HANDLE hd,
                    kal_uint8 mainver,
                    kal_uint8 subver,
                    const kal_char* publicid,
                    wbxml_charset_type_enum charset);


/*****************************************************************************
 * FUNCTION
 *  wbxml_generate_stag
 * DESCRIPTION
 *  This function is for application to generate start tag as following:
 *  \<book1 auther="John" title="XML SPEC"\> 
 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  el:          [IN]    element name
 *  attrlist:    [IN]    attribute struct array.
 *                      If no attribute, attrlist should be NULL, and num_attr should be
 *  num_attr:    [IN]    number of attribute struct
 *  iscontent:   [IN]    whether is content
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 wbxml_generate_stag(
                    WG_HANDLE hd,
                    const kal_char* el,
                    xg_attr_struct* attrlist,
                    kal_uint32 num_attr,
                    kal_bool iscontent);


/*****************************************************************************
* FUNCTION
*  wbxml_generate_data
* DESCRIPTION
*  This function is for application to generate element content.
*  Application can pass data with file or buffer. If with file, data is the 
*  file name encoded with Unicode, datalen should be 0; if with buffer, data
*  is ptr to buffer, datalen is the length of buffer
* PARAMETERS
*  hd:           [IN]    handle of generator
*  data:         [IN]    Filename or buffer with data. 
*  datalen:      [IN]    if with buffer, datalen is the length of buffer, for inline
*                       string, datalen includes terminator "0"
*                       if with file, datalen should be 0.
*  data_type:    [IN]    type of data, is a value of WBXML_DATA_TYPE_ENUM
* RETURN VALUES
*  <0: means failed, returns error code;
*  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 wbxml_generate_data(
                    WG_HANDLE hd,
                    kal_char* data,
                    kal_uint32 datalen,
                    wbxml_data_type_enum data_type);


/*****************************************************************************
 * FUNCTION
 *  wbxml_generate_empty_element
 * DESCRIPTION
 *  This function is for application to generate empty which has no content and
 *  end tag as following: 
 *  \<b b1="m" b2="n" /\>

 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  el:          [IN]    element name
 *  attrlist:    [IN]    attribute struct array.
 *                      If no attribute, attrlist should be NULL, and num_attr should be
 *  num_attr:    [IN]    number of attribute struct
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 wbxml_generate_empty_element(
                    WG_HANDLE hd,
                    const kal_char* el,
                    xg_attr_struct* attrlist,
                    kal_uint32 num_attr);


/*****************************************************************************
 * FUNCTION
 *  xml_generate_inline_element
 * DESCRIPTION
 *  This function is for application to generate a whole element without child element
 *  and attribute, only content. just as following: \<a\> test \</a\>.
 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  el:          [IN]    element name
 *  data:        [IN]    Filename or buffer with data. 
 *  datalen:     [IN]    if with buffer, datalen is the length of buffer,
 *                      if with file, datalen should be 0
 *  datatype:    [IN]    data type
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 wbxml_generate_inline_element(
                    WG_HANDLE hd,
                    const kal_char* el,
                    kal_char* data,
                    kal_uint32 datalen,
                    kal_uint8 datatype);


/*****************************************************************************
 * FUNCTION
 *  wbxml_generate_etag
 * DESCRIPTION
 *  This function is for application to generate end tag as following:
 *  \</book1\>
 * PARAMETERS
 *  hd:          [IN]    handle of generator
 *  el:          [IN]    element name
 * RETURN VALUES
 *  <0: means failed, returns error code;
 *  0 :  means succeed;
 *****************************************************************************/
extern kal_int32 wbxml_generate_etag(WG_HANDLE hd, const kal_char* el);


#endif  /* __WBXML_SUPPORT__ */
#endif  /* WBXMLGEN_H */
