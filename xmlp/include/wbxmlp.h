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
 *  wbxmlp.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  wbxml parser extern header file
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
#ifndef WBXMLP_H
#define WBXMLP_H
#ifdef __WBXML_SUPPORT__

#include "kal_general_types.h"

/* DOM-NOT_FOR_SDK-BEGIN */
#define WBXML_EXT_START_MARK    "$("
#define WBXML_EXT_END_MARK_0    ":escape)"
#define WBXML_EXT_END_MARK_1    ":unesc)"
#define WBXML_EXT_END_MARK_2    ":noesc)"
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  wbxml_stag_hdlr
 * DESCRIPTION
 *  this function is element start handler.
 * PARAMETERS
 *  resv:        [IN]        reserved
 *  tagname:     [IN]        Element name
 *  attrlist:    [IN]        Attribution list
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*wbxml_stag_hdlr)(
                void *resv,
                const kal_char *tagname,
                const kal_char **attrlist);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  wbxml_end_elem_hdlr
 * DESCRIPTION
 *  this function is element end handler.
 * PARAMETERS
 *  resv:        [IN]        reserved
 *  tagname:     [IN]        Element name
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*wbxml_end_elem_hdlr)(void *resv, const kal_char  *tagname);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  wbxml_end_elem_hdlr
 * DESCRIPTION
 *  this function is element end handler.
 * PARAMETERS
 *  resv:        [IN]        reserved
 *  publicid:    [IN]        public id
 *  charset:     [IN]        charset
 *  mainver:     [IN]        mainver
 *  subver:      [IN]        subver
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*wbxml_header_hdlr)(
                void *resv,
                kal_char *publicid,
                kal_uint32 charset,
                kal_uint8 mainver,
                kal_uint8 subver);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  wbxml_default_data_hdlr
 * DESCRIPTION
 *  this function is used as general data handler
 * PARAMETERS
 *  resv:        [IN]        reserved
 *  el:          [IN]        Element name
 *  data:        [IN]        Data to be handled
 *  len:         [IN]        Length of data   
 *  datataype:   [IN]        data type of data(1:string; 2:opaque; 3: entity; 4:extension; 5: mixed)
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*wbxml_data_hdlr)(
                void *resv,
                const kal_char *tagname,
                const kal_char *data,
                kal_uint32 len,
                kal_uint8 datatype);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  wbxml_get_tagname_by_token
 * DESCRIPTION
 *  this function is used to get tagname by token 
 * PARAMETERS
 *  ptr:             [IN]        buf to save tag name
 *  tagcp:           [IN]        tag space code page
 *  token:           [IN]        token of tag
 * RETURN VALUES
 *  -1: over 2048bytes
 *  0: cannot find tagname for such token
 *  >0: success
 *****************************************************************************/
typedef kal_int32 (*wbxml_get_tagname_by_token)(
                     kal_char *ptr,
                     kal_uint32 tagcp,
                     kal_uint8 token);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  wbxml_get_attrname_by_token
 * DESCRIPTION
 *  this function is used to get attrname by token 
 * PARAMETERS
 *  ptr:             [IN]        buf to save attribute name or attribute value
 *  prefix:          [IN]        buf to save attribute value prefix if prefix is exsit in attrstart
 *  attrcp:          [IN]        attribute code page
 *  token:           [IN]        token of attrstart or attrvalue
 * RETURN VALUES
 *  -1: over 2048bytes
 *  0: cannot find tagname for such token
 *  >0: success
 *****************************************************************************/
typedef kal_int32 (*wbxml_get_attrname_by_token)(
                    kal_char *ptr,
                    kal_char *attrprefix,
                    kal_uint32 attrcp,
                    kal_uint8 token);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  wbxml_malloc_buffer_ptr
 * DESCRIPTION
 *  this function is used to malloc buffer 
 * PARAMETERS
 *  len:             [IN]        the length of buffer
 * RETURNS
 *  void
 *****************************************************************************/
typedef void *(*wbxml_malloc_buffer_ptr)(kal_int32 len);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  wbxml_free_buffer_ptr
 * DESCRIPTION
 *  this function is used to free buffer 
 * PARAMETERS
 *  ptr:             [IN]        buffer pointer
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*wbxml_free_buffer_ptr)(void *ptr);


/* define error code */
typedef enum
{
    WBXML_E_MISMATCH_TAG = -5,      /* the tag doesn't match with another */
    WBXML_E_UNKNOWN_TAG = -4,       /* the tag is unknown */
    WBXML_E_UNKNOWN_CHARSET = -3,   /*  the charset is unknown */
    WBXML_E_NO_MEMORY = -2,         /* the memory isn't enough */
    WBXML_RESULT_FAIL = -1,         /* fail to parse wbxml */
    WBXML_RESULT_OK = 0             /* function call succeed */
}wbxml_error_enum;

/* WBXML PARSER HANDLE */
typedef kal_int8 WP_HANDLE;


/*****************************************************************************
 * FUNCTION
 *  wbxml_new_parser
 * DESCRIPTION
 *  this function is used to new a parser for application
 * PARAMETERS
 *  void 
 * RETURN VALUES
 *  -1: means failed;
 *  0 or >0:  means succeed;
 *****************************************************************************/
extern WP_HANDLE wbxml_new_parser(void);


/*****************************************************************************
 * FUNCTION
 *  wbxml_close_parserr
 * DESCRIPTION
 *  this function is used to close a parser for application
 * PARAMETERS
 *  handle:          [IN]        handle of parser struct for application
 * RETURNS
 *  void 
 *****************************************************************************/
extern void wbxml_close_parser(WP_HANDLE handle);


/*****************************************************************************
 * FUNCTION
 *  wbxml_parser
 * DESCRIPTION
 *  this function is used to parser wbxml text, whether in file or in buffer
 * PARAMETERS
 *  handle:          [IN]        handle of parser struct for application 
 *  src:             [IN]        file name or start pointer of buffer
 *  length:          [IN]        if file, length should <= 0, or else length is the
 *                              length of wbxml text in buffer
 * RETURNS
 *  result of the parsing, is one of values in error enum
 *****************************************************************************/
extern kal_int32 wbxml_parse(WP_HANDLE handle, kal_char* src, kal_int32 length);


/*****************************************************************************
 * FUNCTION
 *  wbxml_stop_parserr
 * DESCRIPTION
 *  this function is used to stop a parser for application
 * PARAMETERS
 *  handle:          [IN]        handle of parser struct for application
 * RETURNS
 *  void 
 *****************************************************************************/
extern void wbxml_stop_parser(WP_HANDLE handle);


/*****************************************************************************
 * FUNCTION
 *  wbxml_get_error_tag
 * DESCRIPTION
 *  this function is used to get error tag name when wbxml_parse return error
 * PARAMETERS
 *  handle:          [IN]        handle of parser struct for application 
 * RETURNS
 *  error tag name
 *****************************************************************************/
extern kal_char *wbxml_get_error_tag(WP_HANDLE handle);


/*****************************************************************************
 * FUNCTION
 *  wbxml_register_header_handler
 * DESCRIPTION
 *  this functin is used to register header handler
 * PARAMETERS
 *  handle:          [IN]        handle of parser struct for application
 *  header_hdlr:     [IN]        Function handler to handle header data
 * RETURNS
 *  void
 *****************************************************************************/
extern void wbxml_register_header_handler(WP_HANDLE handle,  wbxml_header_hdlr header_hdlr);


/*****************************************************************************
 * FUNCTION
 *  wbxml_register_data_handler
 * DESCRIPTION
 *  this function is used to register data handler
 * PARAMETERS
 *  handle:          [IN]        handle of parser struct for application
 *  data_hdlr:       [IN]        Function handler to handle data
 * RETURNS
 *  void
 *****************************************************************************/
extern void wbxml_register_data_handler(WP_HANDLE handle, wbxml_data_hdlr data_hdlr);


/*****************************************************************************
 * FUNCTION
 *  wbxml_register_element_handler
 * DESCRIPTION
 *  this function is used to register element handler
 * PARAMETERS
 *  handle:          [IN]        handle of parser struct for application
 *  stag_hdlr:       [IN]        Function handler to handle start element data
 *  end_hdlr:        [IN]        Function handler to handle end element data
 * RETURNS
 *  void
 *****************************************************************************/
extern void wbxml_register_element_handler(
                WP_HANDLE handle,
                wbxml_stag_hdlr stag_hdlr,
                wbxml_end_elem_hdlr end_hdlr);


/*****************************************************************************
 * FUNCTION
 *  wbxml_register_get_name_handler
 * DESCRIPTION
 *  this function is used to register data handler
 * PARAMETERS
 *  handle:                      [IN]        handle of parser struct for application
 *  get_tagname_by_token:        [IN]        Function handler to get tagname by token
 *  get_attrname_by_token:       [IN]        Function handler to get attrname by token
 * RETURNS
 *  void
 *****************************************************************************/
extern void wbxml_register_get_name_handler(
                WP_HANDLE  handle,
                wbxml_get_tagname_by_token get_tagname_by_token,
                wbxml_get_attrname_by_token get_attrname_by_token);


/*****************************************************************************
 * FUNCTION
 *  wbxml_configure_memory
 * DESCRIPTION
 *  this function is used to configure memory functuon
 * PARAMETERS
 *  handle:                  [IN]        handle of parser struct for application
 *  get_buffer:              [IN]        Function to malloc buffer
 *  free_buffer:             [IN]        function to free buffer
 * RETURNS
 *  void
 *****************************************************************************/
extern void wbxml_configure_memory(
                WP_HANDLE  handle,
                wbxml_malloc_buffer_ptr get_buffer,
                wbxml_free_buffer_ptr free_buffer);


/* DOM-NOT_FOR_SDK-BEGIN */
/* API for getting extension data*/
extern kal_char *wbxml_get_ext_0(const kal_char* data, kal_uint32 *len);
extern kal_char *wbxml_get_ext_1(const kal_char* data, kal_uint32 *len);
extern kal_char *wbxml_get_ext_2(const kal_char* data, kal_uint32 *len);
/* DOM-NOT_FOR_SDK-END */


#endif  /* __WBXML_SUPPORT__ */
#endif  /* WBXMLP_H */
