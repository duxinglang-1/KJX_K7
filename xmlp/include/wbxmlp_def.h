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
 *  wbxmlp_def.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  wbxml parser internal header file
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
#ifndef WBXMLP_DEF
#define WBXMLP_DEF
#ifdef __WBXML_SUPPORT__

#include "kal_general_types.h"
#include "wbxmlp.h"
#include "fs_type.h"

/*
 *  BNF description
 *
 *      start       = version publicid charset strtbl body
 *      strtbl      = length *byte
 *      body        = *pi element *pi
 *      element     = stag [ 1*attribute END ] [ *content END ]
 *      content     = element | string | extension | entity | pi | opaque
 *      stag        = TAG | ( LITERAL index )
 *      attribute   = attrStart *attrValue
 *      attrStart   = ATTRSTART | ( LITERAL index )
 *      attrValue   = ATTRVALUE | string | extension | entity
 *      extension   = ( EXT_I termstr ) | ( EXT_T index ) | EXT
 *      string      = inline | tableref
 *      inline      = STR_I termstr
 *      tableref    = STR_T index
 *      entity      = ENTITY entcode
 *      entcode     = mb_u_int32 // UCS-4 character code
 *      pi          = PI attrStart *attrValue END
 *      opaque      = OPAQUE length *byte
 *      version     = u_int8 containing WBXML version number
 *      publicid    = mb_u_int32 | ( zero index )
 *      charset     = mb_u_int32
 *      termstr     = charset-dependent string with termination
 *      index       = mb_u_int32 // integer index into string table.
 *      length      = mb_u_int32 // integer length.
 *      zero        = u_int8 // containing the value zero (0)
 */

/* DOM-NOT_FOR_SDK-BEGIN */
#define WBXML_GT_SWITCH_PAGE        0x00
#define WBXML_GT_END                0x01
#define WBXML_GT_ENTITY             0x02
#define WBXML_GT_STR_I              0x03
#define WBXML_GT_LITERAL            0x04
#define WBXML_GT_EXT_I_0            0x40
#define WBXML_GT_EXT_I_1            0x41
#define WBXML_GT_EXT_I_2            0x42
#define WBXML_GT_PI                 0x43
#define WBXML_GT_LITERAL_C          0x44
#define WBXML_GT_EXT_T_0            0x80
#define WBXML_GT_EXT_T_1            0x81
#define WBXML_GT_EXT_T_2            0x82
#define WBXML_GT_STR_T              0x83
#define WBXML_GT_LITERAL_A          0x84
#define WBXML_GT_EXT_0              0xC0
#define WBXML_GT_EXT_1              0xC1
#define WBXML_GT_EXT_2              0xC2
#define WBXML_GT_OPAQUE             0xC3
#define WBXML_GT_LITERAL_AC         0xC4


#define WBXML_MAX_BUFFER_SIZE   (2048)
#define WBXML_MAX_ATTR_COUNT    (20)
#define WBXML_MAX_ELEM_DEPTH    (20)
#define WBXML_MAX_HANDLE_NUM    (10)

#define WBXML_NUM_PUBLICID      (19)
/* DOM-NOT_FOR_SDK-END */

/* this struct is used to parse wbxml */
typedef struct 
{
    wbxml_header_hdlr  header_hdlr;             /* header handler */
    wbxml_stag_hdlr    stag_hdlr;               /* Start tag handler */
    wbxml_end_elem_hdlr    end_elem_hdlr;       /* end tag handler */
    wbxml_data_hdlr    data_hdlr;               /* data handler */
    wbxml_get_tagname_by_token get_tagname_by_token;    /* Get tagname through tagtoken */
    wbxml_get_attrname_by_token get_attrname_by_token;  /* Get attrstart and attrvalue through tagtoken */
    wbxml_malloc_buffer_ptr get_buffer_ptr;     /* Malloc function */ 
    wbxml_free_buffer_ptr free_buffer_ptr;      /* Free function */
    FS_HANDLE source;                           /* File handle of the WBXML document to be parsed */
    const kal_char *start;                      /* Start pointer to buffer with WBXML document to be parsed */
    kal_char    *strtbl;                        /* string table */
    kal_char    *tagstack[WBXML_MAX_ELEM_DEPTH];/* tag stack to be parsed */
    kal_char    *load;                          /* if file, we use load as buffer and read 2k each time from file */
    kal_char    *namebuf;                       /* fixed name buffer for name got from application via "get_name_by_token" */
    kal_uint32  length;                         /* for buffer, it is the length of buffer with WBXML document to be parsed 
                                                 * for file, it is the length of chars in load[] 
                                                 */
    kal_uint32  len_strtbl;                     /* length of strtbl */
    kal_uint32  current;                        /* Current position to be parsed whenever for file(load[]) or buffer*/
    kal_int32  offset;                          /* it is only for file, and record the offset when need to offset file*/
    kal_uint32  publicid;                       /* public id */
    kal_uint32  charset;                        /* charset */
    kal_uint8   ver_main;                       /* main version */
    kal_uint8   ver_sub;                        /* sub version */
    kal_uint8   data_type;                      /* string: 1; opaque: 2; entity: 3; extension: 4; mixed: 5; */
    kal_uint8   tagcp;                          /* code page of tag space */
    kal_uint8   attrcp;                         /* code page of attribute space */
    kal_uint8   curr_depth;                     /* element depth to be embedded */
    kal_uint8   token;                          /* current token */
    kal_int8    stop;                           /* 1: means stop; 0: means no stop */
    kal_int8    occupy;                         /* 1: means such parser is be occupied; 0 : means not occupied */
} wbxml_parser_struct;

#endif	/* __WBXML_SUPPORT__ */
#endif  /* WBXMLP_DEF */
