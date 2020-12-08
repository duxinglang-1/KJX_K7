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
 *  wbxmlp_main.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  wbxml parser file
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
//#include "drm_util.h"
#include "drm_gprot.h"

#include "Conversions.h"

#include "wbxmlp.h"
#include "wbxmlp_def.h"

#include "drm_def.h"
#include "fs_errcode.h"
#include "fs_func.h"

#include "kal_general_types.h"
#include "kal_public_api.h"

static wbxml_parser_struct wbxml_parser_array[WBXML_MAX_HANDLE_NUM];
kal_char* wbxml_publicid_table[WBXML_NUM_PUBLICID] = {
    NULL,
    "unknown id",
    "-//WAPFORUM//DTD WML 1.0//EN",
    "-//WAPFORUM//DTD WTA 1.0//EN",
    "-//WAPFORUM//DTD WML 1.1//EN",
    "-//WAPFORUM//DTD WML 1.0//EN",
    "-//WAPFORUM//DTD WML 1.0//EN",
    "-//WAPFORUM//DTD WML 1.0//EN",
    "-//WAPFORUM//DTD WML 1.1//EN",
    "-//WAPFORUM//DTD WML 1.2//EN",
    "-//WAPFORUM//DTD WML 1.3//EN",
    "-//WAPFORUM//DTD WML 1.0//EN",
    "-//WAPFORUM//DTD WTA-WML 1.2//EN",
    "-//WAPFORUM//DTD CHANNEL 1.2//EN",
    "unknown id",
    "unknown id",
    "-//WIRELESSVILLAGE//DTD CSP 1.1//EN",
    "-//WIRELESSVILLAGE//DTD CSP 1.2//EN",
    "-//WIRELESSVILLAGE//DTD CSP 1.3//EN"
};


#ifdef TEST_WBXMLP
extern FS_HANDLE  result; /* this file handle is used to save parsing result when testing */

#endif

/* static function declaration */
static void wbxml_default_header_hdlr(void * resv,
        kal_char *publicid, kal_uint32 charset, kal_uint8 mainver, kal_uint8 subver);
static void wbxml_default_stag_hdlr(void *resv, const kal_char *el, const kal_char **attr);
static void wbxml_default_elem_end_hdlr(void *resv, const kal_char *el);
static void wbxml_default_data_hdlr(void *resv, const kal_char  *el, const kal_char *data, kal_uint32 len, kal_uint8 datatype);
static kal_int32 wbxml_default_get_tagname_hdlr(kal_char *ptr, kal_uint32 tagcp,  kal_uint8 token);
static kal_int32 wbxml_default_get_attrname_hdlr(kal_char *ptr, kal_char *attrprefix, kal_uint32 attrcp, kal_uint8 token);


static kal_int32 wbxml_parse_header(wbxml_parser_struct  *parser);
static kal_int32 wbxml_parse_body(wbxml_parser_struct  *parser);
static kal_int32 wbxml_parse_element(wbxml_parser_struct  *parser);
static kal_int32 wbxml_parse_stag(wbxml_parser_struct  *parser, kal_int32 *battr, kal_int32 *bcontent);
static kal_int32 wbxml_parse_attrlist(wbxml_parser_struct  *parser, kal_char **attrlist);
static kal_int32 wbxml_parse_content(wbxml_parser_struct  *parser);



static kal_int32 wbxml_parse_extension(wbxml_parser_struct  *parser, kal_char **data, kal_uint32 *len);
static kal_int32 wbxml_parse_string(wbxml_parser_struct  *parser, kal_char **data, kal_uint32 *len);
static kal_int32 wbxml_parse_opaque(wbxml_parser_struct  *parser, kal_char **data, kal_uint32 *len);
static kal_int32 wbxml_parse_entity(wbxml_parser_struct  *parser, kal_char **data, kal_uint32 *len);
static kal_int32 wbxml_parse_pi(wbxml_parser_struct  *parser);


static kal_int32 wbxml_get_one_token(wbxml_parser_struct  *parser);
static kal_uint32 wbxml_get_mb_uint32(wbxml_parser_struct  *parser);
static kal_int32 wbxml_read_chars_by_len(wbxml_parser_struct  *parser, kal_char *dest, kal_uint32 len);
static kal_int32 wbxml_read_termstr(wbxml_parser_struct  *parser, kal_char **dest);
static kal_int32 wbxml_read_str_from_strtbl(wbxml_parser_struct *parser, kal_char **dest, kal_uint32 index);

static void wbxml_pop_tagstack(wbxml_parser_struct *parser);
static kal_int32 wbxml_push_tagstack(wbxml_parser_struct *parser, kal_char *tagname);
static void wbxml_save_content_data(
                wbxml_parser_struct *parser,
                FS_HANDLE *handle,
                kal_char **dest,
                kal_uint32 len_dest,
                const kal_char *data,
                kal_uint32 len_data);


/*****************************************************************************
 * FUNCTION
 *  wbxml_init_folder
 * DESCRIPTION
 *  this function is used to init folder
 * PARAMETERS
 *  void
 * RETURNS
 *  bool
 *****************************************************************************/
kal_bool wbxml_init_folder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE fh;
    kal_int32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fh = FS_Open((kal_uint16*)L"Z:\\@USER\\", FS_READ_ONLY | FS_OPEN_DIR);

    if (fh >= FS_NO_ERROR)
    {
        FS_Close(fh);
    }
    else
    {
        ret = FS_CreateDir((kal_uint16*)L"Z:\\@USER\\");

        if (ret < 0)
        {
            return KAL_FALSE;
        }
        
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_free_buffer
 * DESCRIPTION
 *  this function is used to free buffer
 * PARAMETERS
 *  parser      [IN]        Global parser struct
 *  p           [IN]        Pointer to be free
 * RETURNS
 *  void
 *****************************************************************************/
static void wbxml_free_buffer(wbxml_parser_struct *parser, void *p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->free_buffer_ptr)
    {
        parser->free_buffer_ptr(p);
    }
    else
    {
        free_ctrl_buffer(p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_get_buffer
 * DESCRIPTION
 *  this function is used to get buffer
 * PARAMETERS
 *  parser      [IN]        Global parser struct
 *  size        [IN]        Size of buffer
 * RETURNS
 *  void
 *****************************************************************************/
static void *wbxml_get_buffer(wbxml_parser_struct *parser, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->get_buffer_ptr)
    {
        return parser->get_buffer_ptr(size);
    }
    else
    {
        if (size <= WBXML_MAX_BUFFER_SIZE)
        {
            return get_ctrl_buffer(size);
        }
        else
        {
            return NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_new_parser
 * DESCRIPTION
 *  this function is used to new a parser for application
 * PARAMETERS
 *  void 
 * RETURNS
 *  handle of parser. 
 *      -1: means failed;
 *      0 or >0:  means succeed;
 *****************************************************************************/
WP_HANDLE wbxml_new_parser(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 index;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < WBXML_MAX_HANDLE_NUM; index++)
    {
        if (wbxml_parser_array[index].occupy == 0)
        {
            memset( &(wbxml_parser_array[index]), 0, sizeof(wbxml_parser_struct));
            wbxml_parser_array[index].occupy = 1;
            
            wbxml_init_folder();

            return (WP_HANDLE)index;
        }
    }
  
    return (WP_HANDLE)(-1); /* cannot find empty parser for application */

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_close_parserr
 * DESCRIPTION
 *  this function is used to close a parser for application
 * PARAMETERS
 *  handle          [IN]        handle of parser struct for application         
 * RETURNS
 *  void 
 *****************************************************************************/
void wbxml_close_parser(WP_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wbxml_parser_struct *p;
    kal_uint32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle >= 0)
    {
        p = &(wbxml_parser_array[handle]);
        if (p->source > 0)
            DRM_close_file(p->source);
        if (p->strtbl != NULL)
            wbxml_free_buffer(p, p->strtbl);
        if (p->namebuf != NULL)
            wbxml_free_buffer(p, p->namebuf);
        if (p->load != NULL)
            wbxml_free_buffer(p, p->load);
        while (p->tagstack[i] != NULL)
        {
            wbxml_free_buffer(p, p->tagstack[i]);
            i++;
        }
        memset(p, 0, sizeof(wbxml_parser_struct));
    }

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_stop_parserr
 * DESCRIPTION
 *  this function is used to stop a parser for application
 * PARAMETERS
 *  handle          [IN]        handle of parser struct for application
 * RETURNS
 *  void 
 *****************************************************************************/
void wbxml_stop_parser(WP_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wbxml_parser_struct *p;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle >= 0)
    {
        p = &(wbxml_parser_array[handle]);

        p->stop = 1;
    }

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_get_error_tag
 * DESCRIPTION
 *  this function is used to get error tag name when wbxml_parse return error
 * PARAMETERS
 *  handle          [IN]        handle of parser struct for application 
 * RETURNS
 *  error tag name
 *****************************************************************************/

kal_char *wbxml_get_error_tag(WP_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wbxml_parser_struct *p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p = &(wbxml_parser_array[handle]);
    
    return p->tagstack[p->curr_depth-1];
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_register_header_handler
 * DESCRIPTION
 *  this functin is used to register header handler
 * PARAMETERS
 *  handle          [IN]        handle of parser struct for application
 *  header_hdlr     [IN]        Function handler to handle header data
 * RETURNS
 *  void
 *****************************************************************************/
void wbxml_register_header_handler(WP_HANDLE handle,  wbxml_header_hdlr header_hdlr)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle >= 0)
    {
        wbxml_parser_array[handle].header_hdlr = (header_hdlr == NULL) ? wbxml_default_header_hdlr : header_hdlr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_register_element_handler
 * DESCRIPTION
 *  this function is used to register element handler
 * PARAMETERS
 *  handle          [IN]        handle of parser struct for application
 *  stag_hdlr       [IN]        Function handler to handle start element data
 *  end_hdlr        [IN]        Function handler to handle end element data
 * RETURNS
 *  void
 *****************************************************************************/
void wbxml_register_element_handler(WP_HANDLE handle,
                           wbxml_stag_hdlr stag_hdlr, wbxml_end_elem_hdlr end_hdlr)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle >= 0)
    {
        wbxml_parser_array[handle].stag_hdlr = (stag_hdlr == NULL) ? wbxml_default_stag_hdlr : stag_hdlr;
        wbxml_parser_array[handle].end_elem_hdlr = (end_hdlr == NULL) ? wbxml_default_elem_end_hdlr : end_hdlr;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_register_data_handler
 * DESCRIPTION
 *  this function is used to register data handler
 * PARAMETERS
 *  handle          [IN]        handle of parser struct for application
 *  data_hdlr       [IN]        Function handler to handle data
 * RETURNS
 *  void
 *****************************************************************************/
void wbxml_register_data_handler(WP_HANDLE handle, wbxml_data_hdlr data_hdlr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle >= 0)
    {
        wbxml_parser_array[handle].data_hdlr = 
            (data_hdlr == NULL) ? wbxml_default_data_hdlr : data_hdlr;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_register_get_name_handler
 * DESCRIPTION
 *  this function is used to register data handler
 * PARAMETERS
 *  handle                      [IN]        handle of parser struct for application
 *  get_tagname_by_token        [IN]        Function handler to get tagname by token
 *  get_attrname_by_token       [IN]        Function handler to get attrname by token
 * RETURNS
 *  void
 *****************************************************************************/
void wbxml_register_get_name_handler(WP_HANDLE  handle,
                        wbxml_get_tagname_by_token get_tagname_by_token, wbxml_get_attrname_by_token get_attrname_by_token)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle >= 0)
    {
        wbxml_parser_array[handle].get_tagname_by_token =
            (get_tagname_by_token == NULL) ? wbxml_default_get_tagname_hdlr : get_tagname_by_token;
        wbxml_parser_array[handle].get_attrname_by_token =
            (get_attrname_by_token == NULL) ? wbxml_default_get_attrname_hdlr : get_attrname_by_token;
    }
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_configure_memory
 * DESCRIPTION
 *  this function is used to configure memory functuon
 * PARAMETERS
 *  handle                  [IN]        handle of parser struct for application
 *  get_buffer              [IN]        Function to malloc buffer
 *  free_buffer             [IN]        function to free buffer
 * RETURNS
 *  void
 *****************************************************************************/
void wbxml_configure_memory(WP_HANDLE  handle,
            wbxml_malloc_buffer_ptr get_buffer,  wbxml_free_buffer_ptr free_buffer)


{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (handle >= 0)
    {
        wbxml_parser_array[handle].get_buffer_ptr = get_buffer;
        wbxml_parser_array[handle].free_buffer_ptr = free_buffer;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_default_stag_hdlr
 * DESCRIPTION
 *  this function is used as default element start handler.
 * PARAMETERS
 *  resv        [IN]        reserved
 *  el          [IN]        Element name
 *  attr        [IN]        Attribution list
 * RETURNS
 *  void
 *****************************************************************************/
static void wbxml_default_stag_hdlr(void *resv, const kal_char *el, const kal_char **attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef TEST_WBXMLP
    kal_int32 i=0, length ;
    kal_char *el_info;
#endif /* TEST_WBXMLP */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef TEST_WBXMLP 

    el_info = get_ctrl_buffer(1024);
    memset(el_info, 0, 1024);

    strcat(el_info, "<");
    strcat(el_info, el);
    strcat(el_info, " ");


    while ((attr[i] != NULL) && (attr[i+1] != NULL))
    {
        strcat(el_info, attr[i]);
        strcat(el_info, " = ");
        strcat(el_info, attr[i+1]);
        strcat(el_info, "; ");
        i+=2;
    }

    strcat(el_info, ">");
    strcat(el_info, "\r\n");

    kal_prompt_trace(MOD_MMI, el_info);
    FS_Write(result, el_info, strlen(el_info), (kal_uint32*)&length);
    free_ctrl_buffer(el_info);
    el_info = NULL;
#endif /* TEST_WBXMLP */ 

}


/*****************************************************************************
 * FUNCTION
 *  wbxml_default_elem_end_hdlr
 * DESCRIPTION
 *  this function is used as default element_end_handler
 * PARAMETERS
 *  resv        [IN]        reserved
 *  el          [IN]        Element name
 * RETURNS
 *  void
 *****************************************************************************/
static void wbxml_default_elem_end_hdlr(void *resv, const kal_char *el)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef TEST_WBXMLP
    kal_char endtag[100];
    kal_int32 length;
#endif /* TEST_WBXMLP*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef TEST_WBXMLP


    memset(endtag, 0, 100);
    strcat(endtag, "</");
    strcat(endtag, el);
    strcat(endtag, ">");
    strcat(endtag, "\r\n");

    kal_prompt_trace(MOD_MMI, endtag);
    FS_Write(result, endtag, strlen(endtag), (kal_uint32*)&length);
#endif /*TEST_WBXMLP*/
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_default_header_hdlr
 * DESCRIPTION
 *  this function is used as default header_handler
 * PARAMETERS
 *  resv                [IN]        reserved
 *  publicid            [IN]        public id
 *  charset             [IN]        charset encoding
 *  mainver             [IN]        main version
 *  subver              [IN]        sub version
 * RETURNS
 *  void
 *****************************************************************************/
static void wbxml_default_header_hdlr(void * resv,
                        kal_char *publicid, kal_uint32 charset, kal_uint8 mainver, kal_uint8 subver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_default_get_tagname_hdlr
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 *  ptr             [IN]        buf to save tag name
 *  tagcp           [IN]        tag space code page
 *  token           [IN]        token of tag
 * RETURNS
 *  -1: over 2048bytes
 *  0: cannot find tagname for such token
 *  >0: success
 *****************************************************************************/
static kal_int32 wbxml_default_get_tagname_hdlr(kal_char *ptr, kal_uint32 tagcp,  kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;

}


/*****************************************************************************
 * FUNCTION
 *  wbxml_default_get_attrname_hdlr
 * DESCRIPTION
 *  this function is used to get attrname by token 
 * PARAMETERS
 *  ptr             [IN]        buf to save attribute name or attribute value
 *  prefix          [IN]        buf to save attribute value prefix if prefix is exsit in attrstart
 *  attrcp          [IN]        attribute code page
 *  token           [IN]        token of attrstart or attrvalue
 * RETURNS
 *  -1: over 2048bytes
 *  0: cannot find tagname for such token
 *  >0: success
 *****************************************************************************/
static kal_int32 wbxml_default_get_attrname_hdlr (kal_char *ptr, kal_char *attrprefix, kal_uint32 attrcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_default_data_hdlr
 * DESCRIPTION
 *  this function is used as general data handler
 * PARAMETERS
 *  resv        [IN]        reserved
 *  el          [IN]        Element name
 *  data        [IN]        Data to be handled
 *  len         [IN]        Length of data   
 *  datataype   [IN]        data type of data(1:string; 2:opaque; 3: entity; 4:extension; 5: mixed)
 * RETURNS
 *  void
 *****************************************************************************/
static void wbxml_default_data_hdlr(void *resv, const kal_char  *el, const kal_char *data, kal_uint32 len, kal_uint8 datatype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef TEST_WBXMLP

    kal_uint32 length;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_prompt_trace(MOD_MMI, data);
    kal_prompt_trace(MOD_MMI, "\r\n");
    FS_Write(result, (void*)data, len, &length);
    FS_Write(result, "\r\n", 2, &length);  
#endif /* TEST_WBXMLP */ 
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_parser
 * DESCRIPTION
 *  this function is used to parser wbxml text, whether in file or in buffer
 * PARAMETERS
 *  handle          [IN]        handle of parser struct for application 
 *  src             [IN]        file name or start pointer of buffer
 *  length          [IN]        if file, length should <= 0, or else length is the
 *                              length of wbxml text in buffer
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
kal_int32 wbxml_parse(WP_HANDLE handle, kal_char* src, kal_int32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wbxml_parser_struct *p;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (handle < 0)
    {
        return WBXML_RESULT_FAIL;
    }

    p = &(wbxml_parser_array[handle]);

    if (length > 0)     /* application pass wbxml text with buffer */
    {
        p->start = src;
        p->length = length;
    }
    else                /* application pass wbxml text with file */
    {
        p->source = DRM_open_file((kal_wchar*)src, FS_READ_ONLY, DRM_PERMISSION_NONE);
        if (p->source <= FS_NO_ERROR)
            return WBXML_RESULT_FAIL;
    }

    /* malloc fixed length(2K) buffer for name to save name got from application by
     * calling callback parser->get_tagname_by_token. this buffer won't be free until
     * application close parser.
     */
    if (p->namebuf == NULL)
    {
        p->namebuf = wbxml_get_buffer(p, WBXML_MAX_BUFFER_SIZE);
        if (p->namebuf == NULL)
        {
            return WBXML_E_NO_MEMORY;
        }
    }
    /* if application pass wbxml text with file, we malloc fixed length(2K) buffer as load. this buffer won't be free until
     * application close parser.
     */

    if ((p->source != 0)&&(p->load == NULL))
    {
        p->load = wbxml_get_buffer(p, WBXML_MAX_BUFFER_SIZE);
        if (p->load == NULL)
        {
            return WBXML_E_NO_MEMORY;
        }    
    }

    result = wbxml_parse_header(p);

    if (result < WBXML_RESULT_OK)
    {
        if (p->source > 0)
        {
            DRM_close_file (p->source);
        }
        return result;
    }

    result = wbxml_parse_body(p);

    if (result < WBXML_RESULT_OK)
    {
        if (p->source > 0)
        {
            DRM_close_file(p->source);
        }
        return result;
    }

    return WBXML_RESULT_OK;
    
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_parse_header
 * DESCRIPTION
 *  this function is used to parser header of wbxml text
 *  version = u_int8
 *  publicid = mb_u_int32
 *  charset  = mb_u_int32
 *  strbl = length *byte
 * PARAMETERS
 *  parser          [IN]        parser struct 
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
static kal_int32 wbxml_parse_header(wbxml_parser_struct  *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 version;
    kal_uint32 len, index = 0;
    kal_int32 token;
    kal_char *publicid = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* get version: version = uint8, 
     * high 4 bits is main (version -1), low 4 bits is sub version
     */
    token = wbxml_get_one_token(parser);
    if (token < 0)
    {
        return WBXML_RESULT_FAIL;
    }
    version = (kal_uint8)token;
    parser->ver_sub = 0x0F & version;
    parser->ver_main = (version>>4) + 1;

    /* get publicid and charset */
    parser->publicid = wbxml_get_mb_uint32(parser);
    if (parser->publicid == 0)
    { /* if publicid is 0, that means we should get publicid from publicid table 
       * firstly we get its index in strtbl, and read it after parsing strtbl
       */
        index = wbxml_get_mb_uint32(parser);
    }
    else
    {
        if (parser->publicid < 0x0E)
        {
            publicid = wbxml_publicid_table[parser->publicid];
        }
        else
        {
            publicid = "reserved";
        }
    }
        
    parser->charset = wbxml_get_mb_uint32(parser);

   /* if (parser->charset != 0x6A)
    {
        return WBXML_E_UNKNOWN_CHARSET;
    }*/

    /* get length of string table */
    len = wbxml_get_mb_uint32(parser);
    if (len > WBXML_MAX_BUFFER_SIZE)
        return WBXML_E_NO_MEMORY;

    if (len > 0)
    {/* save string table */
        kal_int32 len_read;
        
        parser->len_strtbl = len;
        parser->strtbl = wbxml_get_buffer(parser, len+1);
        if (parser->strtbl == NULL)
        {
            return WBXML_E_NO_MEMORY;
        }
        len_read = wbxml_read_chars_by_len(parser, parser->strtbl, len);
        if (len_read < 0)
        {
            wbxml_free_buffer(parser, parser->strtbl);
            return WBXML_RESULT_FAIL;
        }
        parser->strtbl[len_read] = 0;
    }
    
    if (parser->publicid == 0)
    {/* if publicid is 0, that means we should get publicid from publicid table 
      * before we get its index already, now read it after parsing strtbl
      */
        publicid = parser->strtbl + index;
    }
    /* callback header handler */
    if (parser->header_hdlr)
    {
        parser->header_hdlr(NULL, publicid, parser->charset, parser->ver_main, parser->ver_sub);
    }

    return WBXML_RESULT_OK;

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_parse_body
 * DESCRIPTION
 *  this function is used to parser body of wbxml text
 *  body  = *pi  element  *pi
 * PARAMETERS
 *  parser          [IN]        parser struct 
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
static kal_int32 wbxml_parse_body(wbxml_parser_struct  *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 token;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* parse *pi */
    while ((token = wbxml_get_one_token(parser)) == WBXML_GT_PI)
    {
        result = wbxml_parse_pi(parser);
        if (result < WBXML_RESULT_OK)
        {
            return result;
        }
    }

    /* parse element */
    result = wbxml_parse_element(parser);
    if ((result < WBXML_RESULT_OK) || (parser->stop == 1))
    {
        return result;
    }

    /* parse *pi */
    while ((token = wbxml_get_one_token(parser)) == WBXML_GT_PI)
    {
        result = wbxml_parse_pi(parser);
        if (result < WBXML_RESULT_OK)
        {
            return result;
        }
    }

    result = token;
    return WBXML_RESULT_OK;   
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_parse_element
 * DESCRIPTION
 *  this function is used to parser element of wbxml text
 *  element = ([switchPage]  stag)  [ 1*attribute  END  ]  [ *content  END  ]
 * PARAMETERS
 *  parser          [IN]        parser struct 
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
static kal_int32 wbxml_parse_element(wbxml_parser_struct  *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 result, i = 0;
    kal_int32 bcontent = 0, battr = 0;
    kal_char *attrlist[WBXML_MAX_ATTR_COUNT];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = wbxml_parse_stag(parser, &battr, &bcontent);

    if (result < WBXML_RESULT_OK)
    {
        return result;
    }

    memset(attrlist, 0, sizeof(attrlist));
    if (battr)
    {/* attribute list is exist, parse attrlist */

        result = wbxml_parse_attrlist(parser, attrlist);
        if (result < WBXML_RESULT_OK)
        {
            /* Added by Huiyong for free buffer */
            while ((i < WBXML_MAX_ATTR_COUNT) && (attrlist[i] != NULL))
            {
                wbxml_free_buffer(parser, attrlist[i]);
                i++;
            }

            return result;
        }
    }
    /* callback stag handler, and free attribute list */
    parser->stag_hdlr(NULL, (const char*)(parser->tagstack[parser->curr_depth-1]), (const char**)attrlist);
    while ((i < WBXML_MAX_ATTR_COUNT) && (attrlist[i] != NULL))
    {
        wbxml_free_buffer(parser, attrlist[i]);
        i++;
    }
    /* after callback stag handler, we should check if stop */
    if (parser->stop == 1)
    {
        return WBXML_RESULT_OK;
    }    
    if (bcontent)
    {/* content is exist, parse content */
        result = wbxml_parse_content(parser); /* data callback is called in parsing content */
        if ((result < WBXML_RESULT_OK)||(parser->stop == 1))
        {
            return result;
        }
    }
    /* callback end tag handler, and free current tagname */
    parser->end_elem_hdlr(NULL, parser->tagstack[parser->curr_depth-1]);
    wbxml_pop_tagstack(parser);
    
    /* after callback end tag handler, we should check if stop */
    if (parser->stop == 1)
    {
        return WBXML_RESULT_OK;
    }

    return WBXML_RESULT_OK;
    

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_parse_stag
 * DESCRIPTION
 *  this function is used to parser stag of wbxml text
 *   ([switchPage] stag)  
 *   stag = TAG | (literalTag index)
 *   literalTag = LITERAL | LITERAL_A | LITERAL_C | LITERAL_AC
 * PARAMETERS
 *  parser          [IN]        parser struct 
 *  battr           [OUT]       if attribute list is exist in element
 *  bcontent        [OUT]       if content is exist in element
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
static kal_int32 wbxml_parse_stag(wbxml_parser_struct  *parser, kal_int32 *battr, kal_int32 *bcontent)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 tagvalue;
    kal_uint32 index; /* index in string table */
    kal_int32 token, len; /* length of tag name got from application */
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    token = parser->token;

    /* if there SWITCH_PAGE, save it as tag space code page */
    if (token == WBXML_GT_SWITCH_PAGE)
    {
        parser->tagcp = wbxml_get_mb_uint32(parser);
        token = wbxml_get_one_token(parser);
    }
    /* handle token */
    switch (token)
    {
        case WBXML_GT_LITERAL:
            *battr = 0;
            *bcontent = 0;
            index = wbxml_get_mb_uint32(parser);
            result = wbxml_push_tagstack(parser, parser->strtbl + index);
            if (result < WBXML_RESULT_OK)
            {
                return result;
            }
            break;
            
        case WBXML_GT_LITERAL_A:
            *battr = 1;
            *bcontent = 0;
            index = wbxml_get_mb_uint32(parser);
            result = wbxml_push_tagstack(parser, parser->strtbl + index);
            if (result < WBXML_RESULT_OK)
            {
                return result;
            }
            break;

        case WBXML_GT_LITERAL_C:
            *battr = 0;
            *bcontent = 1;
            index = wbxml_get_mb_uint32(parser);
            result = wbxml_push_tagstack(parser, parser->strtbl + index);
            if (result < WBXML_RESULT_OK)
            {
                return result;
            }
            break;

        case WBXML_GT_LITERAL_AC:
            *battr = 1;
            *bcontent = 1;
            index = wbxml_get_mb_uint32(parser);
            result = wbxml_push_tagstack(parser, parser->strtbl + index);
            if (result < WBXML_RESULT_OK)
            {
                return result;
            }
            break;

        default: /* TAG:  */
            if (token < 0)
            {
                return WBXML_RESULT_FAIL;
            }
            *battr = 0x80&token; /* 7th bit marks battr*/
            *bcontent = 0x40&token; /* 6th bit marks bcontent */
            tagvalue = 0x3F&token;

            if ((len = parser->get_tagname_by_token(parser->namebuf, parser->tagcp, tagvalue)) <= 0)
            {
                return WBXML_E_UNKNOWN_TAG;
            }
            result = wbxml_push_tagstack(parser, parser->namebuf);
            if (result < WBXML_RESULT_OK)
            {
                return result;
            }

    }
    result = len;
    return WBXML_RESULT_OK;

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_parse_attrlist
 * DESCRIPTION
 *  this function is used to parser attrlist of wbxml text: 
 *  [  1* attribute  END]
 * PARAMETERS
 *  parser          [IN]        parser struct 
 *  attrlist        [OUT]       char* array for attributes list
 *                              attrlist[0]: attrstart; attrlist[1]: attrvalue;
 *                              attrlist[i]: attrstart; attrlist[i+1]: attrvalue;
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
static kal_int32 wbxml_parse_attrlist(wbxml_parser_struct  *parser, kal_char **attrlist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 token;
    kal_uint32 sub_len, index, i=0;
    kal_int32 result, len1 = 0, len2 = 0, len3 = 0;
    kal_char *attrvalue = NULL, *temp = NULL;     /* temp is to save each value for each  attrvalue token */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    attrvalue = wbxml_get_buffer(parser, WBXML_MAX_BUFFER_SIZE);
    if (attrvalue == NULL)
    {
        return WBXML_E_NO_MEMORY;
    }
    attrvalue[0] = 0;

    token = wbxml_get_one_token(parser);
    while (token != WBXML_GT_END)
    {
        /* firstly handle attrstart:
         * attrStart  =  ([switchPage]  ATTRSTART)  |  (LITERAL  index)
         */
        switch (token)
        {
            case WBXML_GT_SWITCH_PAGE:
                parser->attrcp = wbxml_get_mb_uint32(parser);
                token = wbxml_get_one_token(parser);
                continue;

            case WBXML_GT_LITERAL:
                index = wbxml_get_mb_uint32(parser);
                result = wbxml_read_str_from_strtbl(parser, &(attrlist[i]), index);
                if (result < 0)
                {
                    return result;
                }
                break;

            default:
                if (token < 0)
                {
                    wbxml_free_buffer(parser, attrvalue);
                    return WBXML_RESULT_FAIL;
                }
                if (token >= 128)
                {/* attrstart token should be < 128, if over 128, error occures */
                    wbxml_free_buffer(parser, attrvalue);
                    return WBXML_E_UNKNOWN_TAG;
                }
                len1 = parser->get_attrname_by_token(parser->namebuf, attrvalue, parser->attrcp, (kal_uint8)token);
                if (len1 <= 0)
                {
                    wbxml_free_buffer(parser, attrvalue);
                    return WBXML_E_UNKNOWN_TAG;
                }
                attrlist[i] = wbxml_get_buffer(parser, len1+1);
                if (attrlist[i] == NULL)
                {
                    wbxml_free_buffer(parser, attrvalue);
                    return WBXML_E_NO_MEMORY;
                }
                memcpy(attrlist[i], parser->namebuf, len1);//todo: if need to memset namebuf after every memcpy?
                (attrlist[i])[len1] = 0;

        }


        /* then get attrvalue :
         * attrValue  =  ([switchPage]  ATTRVALUE)  |  string  |  extension  |  entity  |  opaque
         *  attrvalue maybe combination of string, entity, opaque, and so on
         */

        if (*attrvalue != 0)  /* if attribute prefix exist, we should take it as attribute value */
        {
            len2 = strlen(attrvalue);
        }
        while (1) 
        {

            kal_int32 bexit = 0;
            token = wbxml_get_one_token(parser);

            switch (token)
            {
                case WBXML_GT_SWITCH_PAGE:
                    parser->attrcp = wbxml_get_mb_uint32(parser);
                    continue;

                case WBXML_GT_STR_I:
                case WBXML_GT_STR_T:
                    result = wbxml_parse_string(parser, &temp, &sub_len);
                    if (result < WBXML_RESULT_OK)
                    {
                        wbxml_free_buffer(parser, attrvalue);
                        return result;
                    }
                    if (temp != NULL)
                    {
                        len2 += sub_len;
                        if (len2 >= WBXML_MAX_BUFFER_SIZE)
                        {   
                            wbxml_free_buffer(parser, temp);
                            wbxml_free_buffer(parser, attrvalue);
                            return WBXML_E_NO_MEMORY;
                        }
                        strcat(attrvalue, temp);
                        wbxml_free_buffer(parser, temp);
                        temp = NULL;
                    }

                    break;

                case WBXML_GT_EXT_0:
                case WBXML_GT_EXT_1:
                case WBXML_GT_EXT_2:
                case WBXML_GT_EXT_I_0:
                case WBXML_GT_EXT_I_1:
                case WBXML_GT_EXT_I_2:
                case WBXML_GT_EXT_T_0:
                case WBXML_GT_EXT_T_1:
                case WBXML_GT_EXT_T_2:   
                    result = wbxml_parse_extension(parser, &temp, &sub_len);
                    if (result < WBXML_RESULT_OK)
                    {
                        wbxml_free_buffer(parser, attrvalue);
                        return result;
                    }
                    if (temp != NULL)
                    {
                        len2 += sub_len;
                        if (len2 >= WBXML_MAX_BUFFER_SIZE)
                        {   
                            wbxml_free_buffer(parser, temp);
                            wbxml_free_buffer(parser, attrvalue);
                            return WBXML_E_NO_MEMORY;
                        }
                        strcat (attrvalue, temp);
                        wbxml_free_buffer(parser, temp);
                        temp = NULL;
                    }
                    break;

                case WBXML_GT_ENTITY:
                    result = wbxml_parse_entity(parser, &temp, &sub_len);
                    if (result < WBXML_RESULT_OK)
                    {
                        wbxml_free_buffer(parser, attrvalue);
                        return result;
                    }
                    if (temp != NULL)
                    {
                        len2 += sub_len;
                        if (len2 >= WBXML_MAX_BUFFER_SIZE)
                        {
                            wbxml_free_buffer(parser, temp);
                            wbxml_free_buffer(parser, attrvalue);
                            return WBXML_E_NO_MEMORY;
                        }
                        strcat(attrvalue, temp);
                        wbxml_free_buffer(parser, temp);
                        temp = NULL;
                    }
                    break;

                case WBXML_GT_OPAQUE:
                    result = wbxml_parse_opaque(parser, &temp, &sub_len);
                    if (result < WBXML_RESULT_OK)
                    {
                        wbxml_free_buffer(parser, attrvalue);
                        return result;
                    }
                    if (temp != NULL)
                    {
                        len2 += sub_len;
                        if (len2 >= WBXML_MAX_BUFFER_SIZE)
                        {   
                            wbxml_free_buffer(parser, temp);
                            wbxml_free_buffer(parser, attrvalue);
                             return WBXML_E_NO_MEMORY;
                        }

                        len3 = (kal_int32)strlen(attrvalue);
                        memcpy(&attrvalue[len3], temp, sub_len);
                        len3 += sub_len;
                        attrvalue[len3] = 0;
                        
                        wbxml_free_buffer(parser, temp);
                        temp = NULL;
                    }
                    break;

                default:
                    if (token < 0)
                    {
                        wbxml_free_buffer(parser, attrvalue);
                        return WBXML_RESULT_FAIL;
                    }
                    if (token < 128)
                    {/* here is the only exit of while(1)*/
                        bexit = 1;
                        break;
                    }
                    else /* attrvalue token should >= 128 */
                    {
                        kal_int32 ret;
                        ret = parser->get_attrname_by_token(parser->namebuf, NULL, parser->attrcp, (kal_uint8)token);
                        if (ret <= 0)
                        {
                            wbxml_free_buffer(parser, attrvalue);
                            return WBXML_E_UNKNOWN_TAG;
                        }
                        len2 += ret;
                        if (len2 >= WBXML_MAX_BUFFER_SIZE)
                        {   
                            wbxml_free_buffer(parser, attrvalue);
                            return WBXML_E_NO_MEMORY;
                        }
                        strncat (attrvalue, parser->namebuf, ret);
                    }
            }
            if (bexit == 1)
            {
                break;
            }
        }
        /* copy attrvalue to attrlist[i+1] */
        attrlist[i+1] = wbxml_get_buffer(parser,len2+1);
        if (attrlist[i+1] == NULL)
        {
            wbxml_free_buffer(parser, attrvalue);
            return WBXML_E_NO_MEMORY;
        }
        memcpy(attrlist[i+1], attrvalue, len2);
        attrlist[i+1][len2] = 0;
        attrvalue[0] = 0;  /* reset attrvalue for next attribute in next loop */
        i+=2;
        if (i >= WBXML_MAX_ATTR_COUNT) /* if attrlist over  WBXML_MAX_ATTR_COUNT, return fail */
        {
            kal_int32 j=0;
            while ((attrlist[j] != NULL) && (j <= ( i-1)))
            {
                wbxml_free_buffer(parser, attrlist[j]);
                attrlist[j] = NULL;
                j++;
            }    
            wbxml_free_buffer(parser, attrvalue);
            return WBXML_RESULT_FAIL;
        }
    }
    wbxml_free_buffer(parser, attrvalue);
    return WBXML_RESULT_OK;

}

static kal_int32 wbxml_save_content_to_file(wbxml_parser_struct *parser, FS_HANDLE *handle, kal_int32 data_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len = 0, ret, left_len = data_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = FS_Open(L"Z:\\@USER\\wbxml_temp", FS_READ_WRITE | FS_CREATE_ALWAYS);

    do 
    {
        ret = DRM_read_file(parser->source, parser->load, WBXML_MAX_BUFFER_SIZE, &parser->length);
        
        if ((ret < FS_NO_ERROR)||(parser->length == (kal_uint32)0))
        {
    #ifdef TEST_WBXMLP
            ASSERT(ret >= FS_NO_ERROR);
            ASSERT(parser->length > 0);
    #endif /* TEST_WBXMLP */
            return WBXML_RESULT_FAIL;
        }

        if (left_len >= WBXML_MAX_BUFFER_SIZE)        
        {
            FS_Write(*handle, (void*)parser->load, parser->length, &len);
        }
        else
        {
            FS_Write(*handle, (void*)parser->load, left_len - 1, &len);
			break;
        }
        
        left_len -= WBXML_MAX_BUFFER_SIZE;

    } while (parser->length == WBXML_MAX_BUFFER_SIZE);

    DRM_seek_file(parser->source, parser->offset + data_len, FS_FILE_BEGIN);

    return WBXML_RESULT_OK;
}


static kal_int32 wbxml_read_file_data(wbxml_parser_struct *parser, FS_HANDLE fhandle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 len = 0, ret, exit = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    DRM_seek_file(parser->source, parser->offset, FS_FILE_BEGIN);

    do
    {
        parser->current = 0;
        ret = DRM_read_file(parser->source, parser->load, WBXML_MAX_BUFFER_SIZE, &parser->length);
        
        if ((ret < FS_NO_ERROR)||(parser->length == 0))
        {
    #ifdef TEST_WBXMLP
            ASSERT(ret >= FS_NO_ERROR);
            ASSERT(parser->length > 0);
    #endif /* TEST_WBXMLP */
            return WBXML_RESULT_FAIL;
        }
        
        while(parser->current < parser->length)
        {
            if (parser->load[parser->current] == 0)
            {
				exit = 1;
				len += 1;
                break;
            }

            parser->current++;
        }

        len += parser->current;

		if (exit)
		{
			break;
		}

    } while (parser->length == WBXML_MAX_BUFFER_SIZE);

    parser->current = 0;
    DRM_seek_file(parser->source, parser->offset, FS_FILE_BEGIN);

    return len;
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_parse_content
 * DESCRIPTION
 *  this function is used to parser content of wbxml text
 *  [ * content   END ]
 *  Content  =  element  |  string  |  extension  |  entity  |  pi  |  opaque
 * PARAMETERS
 *  parser          [IN]        parser struct 
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
static kal_int32 wbxml_parse_content(wbxml_parser_struct  *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char  *dest=NULL, *temp=NULL; /* ptr is the start pointer in dest when copying temp to dest */
    kal_uint32 sub_len, len = 0;
    kal_int32 result;
    kal_int32 token;
    FS_HANDLE handle = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    parser->data_type = 0; /* firstly reset data_type to 0  for each content */

    while ((token = wbxml_get_one_token(parser)) != WBXML_GT_END)
    {
        /* the reason to malloc dest in while loop:
         * for default, dest will be free after callback data_hdlr.but after handling default,
         * there is still data.
         * such as: <a><b>xyz</b>asd</a>
         * "xyz" will be handled in default, after parser child element <b> through embeded calling, 
         * we need to handle "asd" in current function.
         */
        if (dest == NULL)
        {
            dest = wbxml_get_buffer(parser, WBXML_MAX_BUFFER_SIZE);
            if (dest == NULL)
            {
                return WBXML_E_NO_MEMORY;
            }
            dest[0] = 0;
        }

        switch (token)
        {
            case WBXML_GT_SWITCH_PAGE:
                parser->tagcp = wbxml_get_mb_uint32(parser);
                continue;

            case WBXML_GT_STR_I:
            case WBXML_GT_STR_T:
                result = wbxml_parse_string(parser, &temp, &sub_len);
                if (result < WBXML_RESULT_OK)
                {
                    return result;
                }
                if (temp != NULL)
                {
                    wbxml_save_content_data(parser, &handle, &dest, len, temp, sub_len);
                    len += sub_len;
                    wbxml_free_buffer(parser, temp);
                    temp = NULL;
                    
                }
                if (sub_len > WBXML_MAX_BUFFER_SIZE)
                {
                    wbxml_save_content_to_file(parser, &handle, sub_len);
                }

                if (parser->data_type == 0)
                {
                    parser->data_type = 1; /* string */
                }
                else
                {
                    parser->data_type = 5; /* mixed */
                }
                break;

            case WBXML_GT_EXT_0:
            case WBXML_GT_EXT_1:
            case WBXML_GT_EXT_2:
            case WBXML_GT_EXT_I_0:
            case WBXML_GT_EXT_I_1:
            case WBXML_GT_EXT_I_2:
            case WBXML_GT_EXT_T_0:
            case WBXML_GT_EXT_T_1:
            case WBXML_GT_EXT_T_2:   
                result = wbxml_parse_extension(parser, &temp, &sub_len);
                if (result < WBXML_RESULT_OK)
                {
                    return result;
                }
                if (temp != NULL)
                {
                    wbxml_save_content_data(parser, &handle, &dest, len, temp, sub_len);
                    len += sub_len;
                    wbxml_free_buffer(parser, temp);
                    temp = NULL;
                    
                }
                if (parser->data_type == 0)
                {
                    parser->data_type = 4; /* extension */
                }
                else
                {
                    parser->data_type = 5; /* mixed */
                }
                break;

            case WBXML_GT_ENTITY:
                result = wbxml_parse_entity(parser, &temp, &sub_len);
                if (result < WBXML_RESULT_OK)
                {
                    return result;
                }
                if (temp != NULL)
                {
                    wbxml_save_content_data(parser, &handle, &dest, len, temp, sub_len);
                    len += sub_len;
                    wbxml_free_buffer(parser, temp);
                    temp = NULL;
                }
                if (parser->data_type == 0)
                {
                    parser->data_type = 3; /* entity */
                }
                else
                {
                    parser->data_type = 5; /* mixed */
                }                
                break;

            case WBXML_GT_OPAQUE:
                result = wbxml_parse_opaque(parser, &temp, &sub_len);
                if (result < WBXML_RESULT_OK)
                {
                    return result;
                }
                if (temp != NULL)
                {
                    wbxml_save_content_data(parser, &handle, &dest, len, temp, sub_len);
                    len += sub_len;
                    wbxml_free_buffer(parser, temp);
                    temp = NULL;
                }
                if (parser->data_type == 0)
                {
                    parser->data_type = 2; /* opaque */
                }
                else
                {
                    parser->data_type = 5; /* mixed */
                }
                break;

            case WBXML_GT_PI:   /* just skip pi */
                result = wbxml_parse_pi(parser);
                if (result < WBXML_RESULT_OK)
                {
                    return result;
                }
                break;

            default:
                if (token < 0)
                {
                    return WBXML_RESULT_FAIL;
                }
                if (handle != 0)
                {
                    FS_Close(handle);
                    parser->data_hdlr(NULL, parser->tagstack[parser->curr_depth-1], (kal_char*)L"Z:\\@USER\\wbxml_temp", 0, parser->data_type);
                    len = 0;
                    handle = 0;
                    /* free dest malloced in this loop */
                    wbxml_free_buffer(parser, dest); 
                    dest = NULL;
                }
                else
                {
                    if (dest[0] != 0) 
                    {
                        /* means that there is data before child element stag since last data_hdlr 
                         * we should call data_hdlr firstly.
                         */
                            parser->data_hdlr (NULL, parser->tagstack[parser->curr_depth-1], dest, len, parser->data_type);
                            len = 0;
                    }
                    wbxml_free_buffer(parser, dest); /* before entering child element, we should free dest */
                    dest = NULL;
                }
                result = wbxml_parse_element(parser);
                if ((result < WBXML_RESULT_OK) || (parser->stop == 1))
                {
                    return result;
                }
                parser->data_type = 0; /* reset data_type to 0(string) after parsing child element */
        }

    }
    
    if (handle != 0)
    { /* data is large then 2k, so pass data with file to application */
        FS_Close(handle);
        parser->data_hdlr(NULL, parser->tagstack[parser->curr_depth-1], (kal_char*)L"Z:\\@USER\\wbxml_temp", 0, parser->data_type);
    }    
    
    else if(dest != NULL)
    { /* data is less then 2k, so pass data with buffer to application */
        parser->data_hdlr(NULL, parser->tagstack[parser->curr_depth-1], dest, len, parser->data_type);
        wbxml_free_buffer(parser, dest);
    }

    /* after callback end tag handler, we should check if stop */
    if (parser->stop == 1)
    {
        return WBXML_RESULT_OK;
    }
    
    return WBXML_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_parse_extension
 * DESCRIPTION
 *  this function is used to parser extension of wbxml text
 *  extension  = [switchPage]  ((EXT_I  termstr)  |  (EXT_T  index)  |  EXT )
 *  [swichPage] is already handled in wbxml_parse_content() and wbxml_parse_attrlist();
 * PARAMETERS
 *  parser          [IN]        parser struct 
 *  data            [IN]        buffer to save extension
 *  len             [IN]        length of extension data 
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
static kal_int32 wbxml_parse_extension(wbxml_parser_struct  *parser, kal_char **data, kal_uint32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 token;
    kal_int32 result;
    kal_uint32 index;
    kal_char *dest = NULL, *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    token = parser->token;
    if ((dest = wbxml_get_buffer(parser, WBXML_MAX_BUFFER_SIZE)) == NULL)
    {
        return WBXML_E_NO_MEMORY;
    }
    dest[0] = 0;

    switch(token)
    {
        case WBXML_GT_EXT_0:
        case WBXML_GT_EXT_1:
        case WBXML_GT_EXT_2:
            return WBXML_RESULT_OK; /* just skip*/

        case WBXML_GT_EXT_I_0: //escaped
        case WBXML_GT_EXT_I_1: //unescaped
        case WBXML_GT_EXT_I_2: //no change
            result = wbxml_read_termstr(parser, &temp);
            if (result < 0)
            {
                return result;
            }
            *len = result;
            break;

        case WBXML_GT_EXT_T_0:
            index = wbxml_get_mb_uint32(parser);
            
            result = parser->get_attrname_by_token(parser->namebuf, NULL, parser->attrcp, (kal_uint8)index);
            if (result <= 0)
            {                
                return WBXML_E_UNKNOWN_TAG;
            }

            *len = result;
            if ((*data = wbxml_get_buffer(parser, result+1)) == NULL)
            {
                return WBXML_E_NO_MEMORY;
            }
            
            memcpy(*data, parser->namebuf, result);
            wbxml_free_buffer(parser, dest);
            return WBXML_RESULT_OK;

        case WBXML_GT_EXT_T_1:
        case WBXML_GT_EXT_T_2:
            index = wbxml_get_mb_uint32(parser);
            result = wbxml_read_str_from_strtbl(parser, &temp, index);
            if (result < 0)
            {
                return result;
            }
            *len = result;
    }
    strcpy(dest, WBXML_EXT_START_MARK);

    if (temp)
    strcat(dest, temp);    
    *len += strlen(WBXML_EXT_START_MARK);

    if (temp)
    wbxml_free_buffer (parser, temp);

    switch(token)
    {
        case WBXML_GT_EXT_I_0: //escaped
        case WBXML_GT_EXT_T_0:
            strcat(dest, WBXML_EXT_END_MARK_0);
            *len += strlen (WBXML_EXT_END_MARK_0);
            break;

        case WBXML_GT_EXT_I_1: //unescaped
        case WBXML_GT_EXT_T_1:
            strcat(dest, WBXML_EXT_END_MARK_1);
            *len += strlen(WBXML_EXT_END_MARK_1);
            break;

        case WBXML_GT_EXT_I_2: //no change
        case WBXML_GT_EXT_T_2:
            strcat(dest, WBXML_EXT_END_MARK_2);
            *len += strlen(WBXML_EXT_END_MARK_2);
            break;

    }
    return WBXML_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  wbxml_parse_string
 * DESCRIPTION
 *  this function is used to parser string of wbxml text
 *  string  =  inline  |  tableref
 *  inline  =  STR_I  termstr
 *  tableref  =  STR_T  index
 *  termstr  =  charset-dependent string with termination
 *  index  =  mb_u_int32
 * PARAMETERS
 *  parser          [IN]        parser struct 
 *  data            [IN]        buffer to save string
 *  len             [IN]        length of string data
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
static kal_int32 wbxml_parse_string(wbxml_parser_struct  *parser, kal_char **data, kal_uint32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 token;
    kal_int32 result;
    kal_uint32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    token = parser->token;

    switch (token)
    {
        case WBXML_GT_STR_I:
            result = wbxml_read_termstr(parser, data);
            if (result < 0)
            {
                return  result;
            }
            *len = result;
            break;

        case WBXML_GT_STR_T:
            index = wbxml_get_mb_uint32(parser);
            result = wbxml_read_str_from_strtbl(parser, data, index);
            if (result < 0)
            {
                return  result;
            }
            *len = result;
            break;

        default :
            ASSERT((token == WBXML_GT_STR_I) || (token == WBXML_GT_STR_T));
    }
    return WBXML_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  wbxml_parse_entity
 * DESCRIPTION
 *  this function is used to parser entity of wbxml text
 *  entity  =  ENTITY  entcode
 *  entcode  =  mb_u_int32
 * PARAMETERS
 *  parser          [IN]        parser struct 
 *  data            [IN]        buffer to save entity
 *  len             [IN]        length of entity data
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
static kal_int32 wbxml_parse_entity(wbxml_parser_struct  *parser, kal_char **data, kal_uint32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 entcode;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entcode = (kal_uint16)wbxml_get_mb_uint32(parser);

    if (entcode > 256)
    {
        kal_uint8 value[10];
        *len = mmi_chset_ucs2_to_utf8( value, (kal_uint16)entcode);
        
        if((*data = wbxml_get_buffer(parser, *len+1)) == NULL)
        {
             return WBXML_E_NO_MEMORY;
        }
        memcpy (*data, value, *len);
        (*data)[*len] = 0;
    }
    else
    {
       if((*data = wbxml_get_buffer(parser, 2)) == NULL)
       {
            return WBXML_E_NO_MEMORY;
       }
       (*data)[0] = (kal_char) entcode;
       (*data)[1] = 0;
       *len = 1;
    }
    return WBXML_RESULT_OK;

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_parse_opaque
 * DESCRIPTION
 *  this function is used to parser opaque of wbxml text
 *  opaque  =  OPAQUE  length  *byte
 * PARAMETERS
 *  parser          [IN]        parser struct 
 *  data            [IN]        buffer to save opaque
 *  len             [IN]        length of opaque data
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
static kal_int32 wbxml_parse_opaque(wbxml_parser_struct  *parser, kal_char **data, kal_uint32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 length;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    length = wbxml_get_mb_uint32(parser);
    if ((*data = wbxml_get_buffer (parser, length+1)) == NULL)
    {
        return WBXML_E_NO_MEMORY;
    }
    result = wbxml_read_chars_by_len (parser, *data, length);
    if (result < 0)
    {
        return result;
    }
    (*data)[length] = 0;
    *len = length;
    return WBXML_RESULT_OK;
}




/*****************************************************************************
 * FUNCTION
 *  wbxml_parse_pi
 * DESCRIPTION
 *  this function is used to parser pi of wbxml text
 *  pi  =  PI  attrStart  *attrValue  END
 * PARAMETERS
 *  parser          [IN]        parser struct 
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
static kal_int32 wbxml_parse_pi(wbxml_parser_struct  *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *piattrlist[WBXML_MAX_ATTR_COUNT];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(piattrlist, 0, sizeof(piattrlist));
    return wbxml_parse_attrlist(parser, piattrlist);

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_get_one_token
 * DESCRIPTION
 *  this function is used to get next token in wbxml text
 * PARAMETERS
 *  parser          [IN]        parser struct 
 * RETURNS
 *  token (unsigned 8 bit integer) or error code
 *****************************************************************************/
static kal_int32 wbxml_get_one_token(wbxml_parser_struct  *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 token;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->start != NULL)
    {/* application pass wbxml text with buffer */
        if (parser->current == parser->length)
        {
            return WBXML_RESULT_FAIL;
        }
        token = *(parser->start + parser->current);
        parser->current++;
    }
    else
    {/* application pass wbxml text with file */
        if (parser->current == 0)
        {/* load already reached the end, we need to read next wbxml text from file to load*/
            kal_int32 ret;
            ret = DRM_read_file(parser->source, parser->load, WBXML_MAX_BUFFER_SIZE, &parser->length);
            if ((ret < FS_NO_ERROR)||(parser->length == 0))
            {
                return WBXML_RESULT_FAIL;
            }
        }
        /* get toke directly from load buffer */
        token = parser->load[parser->current];
        parser->current++;

        if (parser->current == parser->length)
        {/* if load buffer reaches the end, reset it */
            parser->current = 0;
        }
    }
    parser->token = token;
    return token;
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_get_mb_uint32
 * DESCRIPTION
 *  this function is used to get multi-byte unsigned 32 bits integer in wbxml text
 * PARAMETERS
 *  parser          [IN]        parser struct 
 * RETURNS
 *  multi-byte unsigned 32 bits integer
 *****************************************************************************/
static kal_uint32 wbxml_get_mb_uint32(wbxml_parser_struct  *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 n = 0;
    kal_char *start;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   

    if (parser->start != NULL)
    {/* application pass wbxml text with buffer */
        start = (char*)(parser->start + parser->current);
        while(*(start) & 0x80)
        {/* if the 7th bit is 1, continue to read next byte */
            n |= ((unsigned char)*start & 0x7F);
            (parser->current)++;
            start++;
            n <<= 7;
        }
        /* handle the end byte of mb_uint32 */
        n |= (unsigned char)*start;
        (parser->current)++;
    }
    else
    {/* application pass wbxml text with file */
        if (parser->current == 0)
        {/* load already reached the end, we need to read next wbxml text from file to load*/
            DRM_read_file(parser->source, parser->load, WBXML_MAX_BUFFER_SIZE, &parser->length);
        }
        start = &(parser->load[parser->current]);
        parser->offset = parser->current; /* to record the start position of mb_uint32 */
        while(*(start) & 0x80)
        {
            if (parser->current+1 == parser->length)
            {/* such case means that, mb_uint32 doesn't terminate at the end of load buffer
              * so we need to reset the load and file, and read file from the start of mb_uint32.
              */
                parser->offset -= parser->length;
                DRM_seek_file(parser->source, parser->offset, FS_FILE_CURRENT);
                DRM_read_file(parser->source, parser->load, WBXML_MAX_BUFFER_SIZE, &parser->length);
                parser->current = 0;
                start = parser->load;
                n = 0;
                continue;
            }

            n |= ((unsigned char)*start & 0x7F);
            (parser->current)++;
            start = &(parser->load[parser->current]);
            n <<= 7;

        }
        n |= (unsigned char)*start;
        (parser->current)++;    
        if (parser->current == parser->length)
        {/* if load buffer reaches the end, reset it */
            parser->current = 0;
        }
    }
    return n;

}


/*****************************************************************************
 * FUNCTION
 *  wbxml_read_chars_by_len
 * DESCRIPTION
 *  this function is used to read chars with specified length in wbxml text
 * PARAMETERS
 *  parser          [IN]        parser struct 
 *  dest            [IN]        destination buffer to store chars
 *  len             [IN]        the length of chars to read
 * RETURNS
 *  the real length of chars readed. if it is < 0, means failed.
 *****************************************************************************/
static kal_int32 wbxml_read_chars_by_len(wbxml_parser_struct  *parser, kal_char *dest, kal_uint32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *start;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->start != NULL)
    {/* application pass wbxml text with buffer */
        if ((parser->current + len) > parser->length)
        {
#ifdef TEST_WBXMLP        
            ASSERT ((parser->current + len) > parser->length);
#endif /* TEST_WBXMLP */
            return WBXML_RESULT_FAIL;
        }
        start = (char*)(parser->start+parser->current);
        memcpy(dest, start, len);
        parser->current += len;
    }
    else
    {/* application pass wbxml text with file */
        if (parser->current == 0)
        {/* load already reached the end, we need to read next wbxml text from file to load*/
            kal_int32 ret;
            ret = DRM_read_file(parser->source, parser->load, WBXML_MAX_BUFFER_SIZE, &parser->length);

            if ((ret < FS_NO_ERROR)||(parser->length == 0))
            {
#ifdef TEST_WBXMLP
                ASSERT(ret >= FS_NO_ERROR);
                ASSERT(parser->length > 0);
#endif /*TEST_WBXMLP */
                return WBXML_RESULT_FAIL;
            }
        }
        start = &(parser->load[parser->current]);
        parser->offset = parser->current; /* to record the start position of chars */

        /* handle the case that load buffer doesn't include whole chars */
        if (parser->current+len > parser->length)
        {
            kal_int32 ret;
            parser->offset -= parser->length;
            DRM_seek_file(parser->source, parser->offset, FS_FILE_CURRENT);
            ret = DRM_read_file(parser->source, parser->load, WBXML_MAX_BUFFER_SIZE, &parser->length);
            if ((ret < FS_NO_ERROR)||(parser->length == 0))
            {
#ifdef TEST_WBXMLP
                ASSERT(ret >= FS_NO_ERROR);
                ASSERT(parser->length > 0);
#endif /*TEST_WBXMLP */
                return WBXML_RESULT_FAIL;
            }
            parser->current = 0;
            start = parser->load;
        }
        /* copy chars from load to dest */
        memcpy(dest, start, len);
        parser->current +=len;
        if (parser->current == parser->length)
        {
            parser->current = 0;
        }
    }
    return len;

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_read_termstr
 * DESCRIPTION
 *  this function is used to read chars with termination (0) in wbxml text
 * PARAMETERS
 *  parser          [IN]        parser struct 
 *  dest            [IN]        destination buffer to store chars
 * RETURNS
 *  the real length of chars readed. if it is < 0, means failed.
 *****************************************************************************/
static kal_int32 wbxml_read_termstr(wbxml_parser_struct  *parser, kal_char **dest)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    kal_char *start;
    kal_uint32 file_pos = 0, old_pos = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parser->start != NULL)
    {/* application pass wbxml text with buffer */
        start = (char*)(parser->start+parser->current);
        len = strlen(start);

        if ((parser->current+len) > parser->length)
        {
#ifdef TEST_WBXMLP
            ASSERT((parser->current+len) > parser->length);
#endif /* TEST_WBXMLP*/
            return WBXML_RESULT_FAIL;
        }
        if ((*dest = wbxml_get_buffer(parser, len+1)) == NULL)
        {
            return WBXML_E_NO_MEMORY;
        }
        strcpy(*dest, start);
        parser->current += len+1; /* terminator should be count */
    }
    else
    {/* application pass wbxml text with file */
        if (parser->current == 0)
        {/* load already reached the end, we need to read next wbxml text from file to load*/
            kal_int32 ret;
            ret = DRM_read_file(parser->source, parser->load, WBXML_MAX_BUFFER_SIZE, &parser->length);
            if ((ret < FS_NO_ERROR)||(parser->length == 0))
            {
#ifdef TEST_WBXMLP
                ASSERT(ret >= FS_NO_ERROR);
                ASSERT(parser->length > 0);
#endif /* TEST_WBXMLP */
                return WBXML_RESULT_FAIL;
            }
        }
        start = &(parser->load[parser->current]);

        //parser->offset = parser->current; /* to record the start position of termstr */
        DRM_file_pos(parser->source, &file_pos);
        parser->offset = file_pos - (parser->length - parser->current); /* to record the start position of termstr */
        old_pos = parser->current;

        while(parser->current < parser->length)
        {
            if (parser->load[parser->current] == 0)
            {   /* case :load buffer include whole termstr, reset current to original */
                parser->current = old_pos;
                break;
            }
            parser->current++;
        }  
        /* handle the case that load buffer doesn't include whole termstr */
        if (parser->current == parser->length)
        {
            kal_int32 ret;

            ret = wbxml_read_file_data(parser, parser->source);
            
            if (ret < FS_NO_ERROR)
            {
#ifdef TEST_WBXMLP
                ASSERT(ret >= FS_NO_ERROR);
                ASSERT(parser->length > 0);
#endif /* TEST_WBXMLP */
                return WBXML_RESULT_FAIL;
            }
            parser->current = 0;
            start = parser->load;

            if (ret > WBXML_MAX_BUFFER_SIZE)
            {
                return ret;
            }

            DRM_seek_file(parser->source, parser->offset + WBXML_MAX_BUFFER_SIZE, FS_FILE_BEGIN);
        }

        /* malloc for dest, and copy termstr to dest */
        len = strlen(start);
        if ((*dest = wbxml_get_buffer(parser, len+1)) == NULL)
        {
            return WBXML_E_NO_MEMORY;
        }
        strcpy(*dest, start);
        parser->current += len+1; /* including terminator 0 */
        if (parser->current == parser->length)
        {
            parser->current = 0;
        }
        
    }
    return len;

}

/*****************************************************************************
 * FUNCTION
 *  wbxml_read_str_from_strtbl
 * DESCRIPTION
 *  this function is used to read string with termination in string table
 * PARAMETERS
 *  parser          [IN]        parser struct 
 *  dest            [IN]        destination buffer to store chars
 *  index           [IN]        index in string table
 * RETURNS
 *  the real length of chars readed. if it < 0, means failed.
 *****************************************************************************/
static kal_int32 wbxml_read_str_from_strtbl(wbxml_parser_struct *parser, kal_char **dest, kal_uint32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index >= parser->len_strtbl)
    {
#ifdef TEST_WBXMLP
        ASSERT(index < parser->len_strtbl);
#endif /* TEST_WBXMLP */
        return WBXML_RESULT_FAIL;
    }

    if ((len = strlen(parser->strtbl + index)) > WBXML_MAX_BUFFER_SIZE)
    {
        return WBXML_E_NO_MEMORY;
    }
    if ((*dest = wbxml_get_buffer(parser, len + 1)) == NULL)
    {
        return WBXML_E_NO_MEMORY;
    }

    memcpy(*dest, parser->strtbl+index, len);
    (*dest)[len] = 0;

    return len;
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_save_content_data
 * DESCRIPTION
 *  This function is used to save data to buffer or file: if data is over 2k,
 *  file will be used, else buffer will be used
 * PARAMETERS
 *  parser          [IN]            Global parser struct
 *  handle          [IN/OUT]        FILE HANDLE to save data
 *  dest            [IN/OUT]        Buffer to save data
 *  len_data        [IN]            length of data in dest buffer
 *  data            [IN]            Data to be saved
 *  len_data        [IN]            Length of data
 * RETURNS
 *  void
 *****************************************************************************/
static void wbxml_save_content_data(
                wbxml_parser_struct *parser,
                FS_HANDLE *handle,
                kal_char **dest,
                kal_uint32 len_dest,
                const kal_char *data,
                kal_uint32 len_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*dest == NULL) && (*handle != 0))
        FS_Write(*handle, (void*)data, len_data, &len);
    else
    {
        if (*dest == NULL)
            return;

        if (len_dest + len_data > WBXML_MAX_BUFFER_SIZE)
        {
            *handle = FS_Open(L"Z:\\@USER\\wbxml_temp", FS_READ_WRITE | FS_CREATE_ALWAYS);
            FS_Write(*handle, (void*)*dest, len_dest, &len);
            FS_Write(*handle, (void*)data, len_data, &len);
            wbxml_free_buffer(parser, *dest);
            *dest = NULL;
        }
        else
            memcpy(*dest+len_dest, data, len_data);
    }
    return;
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_push_tagstack
 * DESCRIPTION
 *  This function is used to push tagstack to tag list
 * PARAMETERS
 *  parser      [IN]        parser struct
 *  tagname     [IN]        Start tag name to be pused
 * RETURNS
 *  if successful, return WBXML_RESULT_OK
 *****************************************************************************/
static kal_int32 wbxml_push_tagstack(wbxml_parser_struct *parser, kal_char *tagname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *namebuffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* if parser->curr_depth overs WBXML_MAX_ELEM_DEPTH, it maybe cause out of memory */
    if (parser->curr_depth >= WBXML_MAX_ELEM_DEPTH)
    {
        return WBXML_RESULT_FAIL;
    }
    namebuffer = wbxml_get_buffer(parser, strlen(tagname) + 1);
    if (namebuffer == NULL)
    {
        return WBXML_E_NO_MEMORY;
    }
    strcpy(namebuffer, tagname);

    parser->tagstack[parser->curr_depth] = namebuffer;
    parser->curr_depth++;

    return WBXML_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_pop_tagstack
 * DESCRIPTION
 *  This function is used to pop last start_tag in tag stack
 * PARAMETERS
 *  parser      [IN]        parser struct
 * RETURNS
 *  void
 *****************************************************************************/
static void wbxml_pop_tagstack(wbxml_parser_struct *parser)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parser->curr_depth--;
    if (parser->tagstack[parser->curr_depth] != NULL)
    {
        wbxml_free_buffer(parser, parser->tagstack[parser->curr_depth]);
        parser->tagstack[parser->curr_depth] = NULL;
    }
    return;
}


/*****************************************************************************
 * FUNCTION
 *  wbxml_get_ext_0
 * DESCRIPTION
 *  this function is used to get EXT_0 string 
 * PARAMETERS
 *  data            [IN]        data to search
 *  len             [OUT]       the length of EXT_0 string
 * RETURNS
 *  the start position in data or NULL
 *****************************************************************************/

kal_char *wbxml_get_ext_0(const kal_char* data, kal_uint32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *start = NULL, *end = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((start = strstr(data, WBXML_EXT_START_MARK)) != NULL)
    {
        end = strstr(start, WBXML_EXT_END_MARK_0);
        if (end != NULL)
        {
            *len = end-start+1;
            return start;
        }
    }
    len = 0;
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_get_ext_1
 * DESCRIPTION
 *  this function is used to get EXT_1 string 
 * PARAMETERS
 *  data            [IN]        data to search
 *  len             [OUT]       the length of EXT_1 string
 * RETURNS
 *  the start position in data or NULL
 *****************************************************************************/

kal_char *wbxml_get_ext_1(const kal_char* data, kal_uint32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *start = NULL, *end = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((start = strstr(data, WBXML_EXT_START_MARK)) != NULL)
    {
        end = strstr(start, WBXML_EXT_END_MARK_1);
        if (end != NULL)
        {
            *len = end-start+1;
            return start;
        }
    }
    len = 0;
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  wbxml_get_ext_2
 * DESCRIPTION
 *  this function is used to get EXT_2 string 
 * PARAMETERS
 *  data            [IN]        data to search
 *  len             [OUT]       the length of EXT_2 string
 * RETURNS
 *  the start position in data or NULL
 *****************************************************************************/

kal_char *wbxml_get_ext_2(const kal_char* data, kal_uint32 *len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *start = NULL, *end = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((start = strstr(data, WBXML_EXT_START_MARK)) != NULL)
    {
        end = strstr(start, WBXML_EXT_END_MARK_2);
        if (end != NULL)
        {
            *len = end-start+1;
            return start;
        }
    }
    len = 0;
    return NULL;
}


#endif     /* __WBXML_SUPPORT__ */
