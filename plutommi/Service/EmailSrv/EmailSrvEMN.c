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
 *  EmailSrvEMN.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to implement the Email EMN functions.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_EMAIL__
#include <ctype.h>

#include "EmailSrvGProt.h"
#include "EmailSrvProt.h"
#include "EmailSrvStorage.h"

#if defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__)
#ifndef __SRV_EMAIL_EMN__
#define __SRV_EMAIL_EMN__
#endif
#endif /* defined(__XML_SUPPORT__) && defined(__WBXML_SUPPORT__) */

#ifdef __SRV_EMAIL_EMN__

#include "app_str.h"
#include "app_mine.h"
#include "app_usedetails.h"
#include "wbxmlp.h"
#include "xml_def.h"

#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "customer_ps_inc.h"
#include "kal_general_types.h"
#include "string.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_inet_app_trc.h"
#include "kal_trace.h"
#include "fs_func.h"
#include "Unicodexdcl.h"

/* Tag Tokens */
#define SRV_EMAIL_EMN_TAG_EMN                   0x05

/* Attribute Start Tokens */
#define SRV_EMAIL_EMN_START_TIMESTAMP           0x05
#define SRV_EMAIL_EMN_START_MAILBOX             0x06
#define SRV_EMAIL_EMN_START_MAILBOX_MAILAT      0x07
#define SRV_EMAIL_EMN_START_MAILBOX_POP         0x08
#define SRV_EMAIL_EMN_START_MAILBOX_IMAP        0x09
#define SRV_EMAIL_EMN_START_MAILBOX_HTTP        0x0A
#define SRV_EMAIL_EMN_START_MAILBOX_HTTP3W      0x0B
#define SRV_EMAIL_EMN_START_MAILBOX_HTTPS       0x0C
#define SRV_EMAIL_EMN_START_MAILBOX_HTTPS3W     0x0D

/* Attribute Value Tokens */
#define SRV_EMAIL_EMN_VALUE_COM                 0x85
#define SRV_EMAIL_EMN_VALUE_EDU                 0x86
#define SRV_EMAIL_EMN_VALUE_NET                 0x87
#define SRV_EMAIL_EMN_VALUE_ORG                 0x88

#define SRV_EMAIL_EMN_TAGS_MIN                  SRV_EMAIL_EMN_TAG_EMN
#define SRV_EMAIL_EMN_TAGS_MAX                  SRV_EMAIL_EMN_TAG_EMN

#define SRV_EMAIL_EMN_SATTR_MIN                 SRV_EMAIL_EMN_START_TIMESTAMP
#define SRV_EMAIL_EMN_SATTR_MAX                 SRV_EMAIL_EMN_START_MAILBOX_HTTPS3W

#define SRV_EMAIL_EMN_VATTR_MIN                 SRV_EMAIL_EMN_VALUE_COM
#define SRV_EMAIL_EMN_VATTR_MAX                 SRV_EMAIL_EMN_VALUE_ORG

#define SRV_EMAIL_EMN_YEAR_MIN                  0
#define SRV_EMAIL_EMN_YEAR_MAX                  9999
#define SRV_EMAIL_EMN_MONTH_MIN                 1
#define SRV_EMAIL_EMN_MONTH_MAX                 12
#define SRV_EMAIL_EMN_DAY_MIN                   1
#define SRV_EMAIL_EMN_DAY_MAX                   31
#define SRV_EMAIL_EMN_HOUR_MIN                  0
#define SRV_EMAIL_EMN_HOUR_MAX                  23
#define SRV_EMAIL_EMN_MINUTE_MIN                0
#define SRV_EMAIL_EMN_MINUTE_MAX                59
#define SRV_EMAIL_EMN_SECOND_MIN                0
#define SRV_EMAIL_EMN_SECOND_MAX                59

#define SRV_EMAIL_EMN_RETCODE_SUCC              0
#define SRV_EMAIL_EMN_RETCODE_FAIL              -1
#define SRV_EMAIL_EMN_RETCODE_MEM_FULL          -2
#define SRV_EMAIL_EMN_RETCODE_CHARSET_ERR       -3
#define SRV_EMAIL_EMN_RETCODE_TAG_ERR           -4
#define SRV_EMAIL_EMN_RETCODE_PARAM_ERR         -5
#define SRV_EMAIL_EMN_RETCODE_TYPE_ERR          -6
#define SRV_EMAIL_EMN_RETCODE_MB_NOT_SUPPORT    -7
#define SRV_EMAIL_EMN_RETCODE_MB_TOO_LONG       -8
#define SRV_EMAIL_EMN_RETCODE_MB_INVALID        -9
#define SRV_EMAIL_EMN_RETCODE_TS_INVALID        -10

typedef struct 
{
    CHAR *attrname;
    CHAR *attrprefix;
} srv_email_emn_attr_struct;

typedef struct
{
    MYTIME time;
    CHAR address[SRV_EMAIL_MAX_ADDR_LEN + 1];
} srv_email_emn_info_struct;

typedef struct
{
    EMAIL_SRV_HANDLE srv_handle;
    MMI_BOOL allow_register;
    srv_email_emn_funcptr_type emn_callback;
    srv_email_funcptr_type clear_callback;
} srv_email_emn_struct;

static const CHAR *srv_email_emn_tags[SRV_EMAIL_EMN_TAGS_MAX - SRV_EMAIL_EMN_TAGS_MIN + 1] =
{
    "Emn"   /* 0x05 */
};

static const srv_email_emn_attr_struct srv_email_emn_start_attrs[SRV_EMAIL_EMN_SATTR_MAX - SRV_EMAIL_EMN_SATTR_MIN + 1] =
{
    {"timestamp",   NULL},              /* 0x05 */
    {"mailbox",     NULL},              /* 0x06 */
    {"mailbox",     "mailat:"},         /* 0x07 */
    {"mailbox",     "pop://"},          /* 0x08 */
    {"mailbox",     "imap://"},         /* 0x09 */
    {"mailbox",     "http://"},         /* 0x0A */
    {"mailbox",     "http://www."},     /* 0x0B */
    {"mailbox",     "https://"},        /* 0x0C */
    {"mailbox",     "https://www."}     /* 0x0D */
};

static const CHAR *srv_email_emn_value_attrs[SRV_EMAIL_EMN_VATTR_MAX - SRV_EMAIL_EMN_VATTR_MIN + 1] =
{
    ".com", /* 0x85 */
    ".edu", /* 0x86 */
    ".net", /* 0x87 */
    ".org"  /* 0x88 */
};

static WP_HANDLE srv_email_emn_wbxml_handle = (WP_HANDLE)-1;
static XML_PARSER_STRUCT *srv_email_emn_xml_p = NULL;
static CHAR *srv_email_emn_addr_p = NULL;
static MYTIME *srv_email_emn_time_p = NULL;
static MMI_BOOL srv_email_emn_addr_exist = MMI_FALSE;
static MMI_BOOL srv_email_emn_time_exist = MMI_FALSE;
static S32 srv_email_emn_errcode = 0;

static srv_email_emn_struct srv_email_emn;
static srv_email_emn_struct *srv_email_emn_p = NULL;
static MMI_BOOL srv_email_emn_inited = MMI_FALSE;

static S32 srv_email_emn_parse_emn_file(
            S32 mime_type,
            S32 mime_subtype,
            const WCHAR *filepath,
            srv_email_emn_info_struct *info_p);
static S32 srv_email_emn_parse_wbxml_file(const WCHAR *filepath);
static S32 srv_email_emn_parse_xml_file(const WCHAR *filepath);

static void srv_email_emn_wbxml_start_hdlr(
                void *resv,
                const kal_char *tagname,
                const kal_char **attrlist);
static kal_int32 srv_email_emn_wbxml_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token);
static kal_int32 srv_email_emn_wbxml_get_attrname_by_token(
                    kal_char *ptr,
                    kal_char *attrprefix,
                    kal_uint32 attrcp,
                    kal_uint8 token);

static S32 srv_email_emn_parse_mailbox(const CHAR *pMbox, CHAR *pAddr, S32 buflen);
static S32 srv_email_emn_parse_wbxml_timestamp(const CHAR *pTstamp, MYTIME *pTime);
static MMI_BOOL srv_email_emn_is_timestamp_valid(MYTIME *pTime);

static void srv_email_emn_xml_start_hdlr(
                void *data,
                const kal_char *el,
                const kal_char **attr,
                kal_int32 error);
static S32 srv_email_emn_parse_xml_timestamp(const CHAR *pTstamp, MYTIME *pTime);

static S32 srv_email_emn_convert_wbxml_parser_errcode(S32 errcode);
static S32 srv_email_emn_convert_xml_parser_errcode(S32 errcode);


/*****************************************************************************
* FUNCTION
*  srv_email_emn_parse_emn_file
* DESCRIPTION
*  This function is used to parse the Email notification file.
* PARAMETERS
*  mime_type        [IN]        The mime type
*  mime_subtype     [IN]        The mime sub-type
*  filepath         [IN]        The EMN file path
*  info_p           [IN]        Used to store the EMN information
* RETURNS
*  The error code.
*****************************************************************************/
static S32 srv_email_emn_parse_emn_file(
            S32 mime_type,
            S32 mime_subtype,
            const WCHAR *filepath,
            srv_email_emn_info_struct *info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!((mime_type == MIME_TYPE_TEXT && mime_subtype == MIME_SUBTYPE_EMN_XML) ||
        (mime_type == MIME_TYPE_APPLICATION && mime_subtype == MIME_SUBTYPE_EMN_WBXML)))
    {
        return SRV_EMAIL_EMN_RETCODE_TYPE_ERR;
    }

    if (!filepath || !info_p)
    {
        return SRV_EMAIL_EMN_RETCODE_PARAM_ERR;
    }

    srv_email_emn_addr_p = info_p->address;
    srv_email_emn_time_p = &info_p->time;
    srv_email_emn_addr_exist = MMI_FALSE;
    srv_email_emn_time_exist = MMI_FALSE;
    srv_email_emn_errcode = 0;

    if (mime_type == MIME_TYPE_TEXT && mime_subtype == MIME_SUBTYPE_EMN_XML)
    {
        ret = srv_email_emn_parse_xml_file(filepath);
    }
    else
    {
        ret = srv_email_emn_parse_wbxml_file(filepath);
    }

    srv_email_emn_addr_p = NULL;
    srv_email_emn_time_p = NULL;
    srv_email_emn_addr_exist = MMI_FALSE;
    srv_email_emn_time_exist = MMI_FALSE;
    srv_email_emn_errcode = 0;

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_parse_wbxml_file
 * DESCRIPTION
 *  This function is used to parse the Email notification (wbxml).
 * PARAMETERS
 *  filepath            [IN]        The EMN file path
 * RETURNS
 *  The error code.
 *****************************************************************************/
static S32 srv_email_emn_parse_wbxml_file(const WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_emn_wbxml_handle = wbxml_new_parser();
    if (srv_email_emn_wbxml_handle < 0)
    {
        return SRV_EMAIL_EMN_RETCODE_MEM_FULL;
    }

    wbxml_register_header_handler(srv_email_emn_wbxml_handle, NULL);
    wbxml_register_element_handler(srv_email_emn_wbxml_handle, srv_email_emn_wbxml_start_hdlr, NULL);
    wbxml_register_data_handler(srv_email_emn_wbxml_handle, NULL);
    wbxml_register_get_name_handler(
        srv_email_emn_wbxml_handle,
        srv_email_emn_wbxml_get_tagname_by_token,
        srv_email_emn_wbxml_get_attrname_by_token);

    ret = wbxml_parse(srv_email_emn_wbxml_handle, (kal_char*)filepath, 0);

    wbxml_close_parser(srv_email_emn_wbxml_handle);

    srv_email_emn_wbxml_handle = (WP_HANDLE)-1;

    if (srv_email_emn_errcode == 0 && ret == WBXML_RESULT_OK)
    {
        if (!srv_email_emn_addr_exist)
        {
            srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_MB_INVALID;
        }
        else if (!srv_email_emn_time_exist)
        {
            srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_TS_INVALID;
        }
    }

    if (srv_email_emn_errcode < 0)
    {
        return srv_email_emn_errcode;
    }
    else
    {
        return srv_email_emn_convert_wbxml_parser_errcode(ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_wbxml_start_hdlr
 * DESCRIPTION
 *  The handler of the wbxml element start.
 * PARAMETERS
 *  resv                [IN]        reserved
 *  tagname             [IN]        Element name
 *  attrlist            [IN]        Attribution list
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_emn_wbxml_start_hdlr(
                void *resv,
                const kal_char *tagname,
                const kal_char **attrlist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; attrlist[i]; i += 2)
    {
        if (app_stricmp((kal_char*)attrlist[i], "mailbox") == 0)
        {
            if (srv_email_emn_addr_exist)
            {
                srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_MB_INVALID;
            }
            else
            {
                srv_email_emn_errcode =
                    srv_email_emn_parse_mailbox(
                        (const CHAR*)attrlist[i + 1],
                        srv_email_emn_addr_p,
                        SRV_EMAIL_MAX_ADDR_LEN + 1);
                srv_email_emn_addr_exist = MMI_TRUE;
            }
        }
        else if (app_stricmp((CHAR*)attrlist[i], "timestamp") == 0)
        {
            if (srv_email_emn_time_exist)
            {
                srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_TS_INVALID;
            }
            else
            {
                srv_email_emn_errcode =
                    srv_email_emn_parse_wbxml_timestamp(
                        (const CHAR*)attrlist[i + 1],
                        srv_email_emn_time_p);
                srv_email_emn_time_exist = MMI_TRUE;
            }
        }

        if (srv_email_emn_errcode < 0)
        {
            wbxml_stop_parser(srv_email_emn_wbxml_handle);
            return;
        }
    }

    if (!srv_email_emn_addr_exist)
    {
        srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_MB_INVALID;
    }
    else if (!srv_email_emn_time_exist)
    {
        srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_TS_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_wbxml_get_tagname_by_token
 * DESCRIPTION
 *  The handler of the wbxml get tagname by token.
 * PARAMETERS
 *  ptr              [OUT]       The buf to save tag name
 *  tagcp            [IN]        The tag space code page
 *  token            [IN]        The token of tag
 * RETURNS
 *  The length of the tag name.
 *****************************************************************************/
static kal_int32 srv_email_emn_wbxml_get_tagname_by_token(kal_char *ptr, kal_uint32 tagcp, kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *temp = NULL;
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (token >= SRV_EMAIL_EMN_TAGS_MIN && token <= SRV_EMAIL_EMN_TAGS_MAX)
    {
        temp = (CHAR*)srv_email_emn_tags[token - SRV_EMAIL_EMN_TAGS_MIN];
        strcpy(ptr, temp);
        len = strlen(temp);
    }

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_wbxml_get_attrname_by_token
 * DESCRIPTION
 *  The handler of the wbxml get attrname by token.
 * PARAMETERS
 *  ptr              [OUT]       The buf to save attribute name or attribute value
 *  prefix           [OUT]       The buf to save attribute value prefix if prefix is exsit in attrstart
 *  attrcp           [IN]        The attribute code page
 *  token            [IN]        The token of attrstart or attrvalue
 * RETURNS
 *  The length of the attribute name.
 *****************************************************************************/
static kal_int32 srv_email_emn_wbxml_get_attrname_by_token(
                    kal_char *ptr,
                    kal_char *attrprefix,
                    kal_uint32 attrcp,
                    kal_uint8 token)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (token >= SRV_EMAIL_EMN_SATTR_MIN && token <= SRV_EMAIL_EMN_SATTR_MAX)
    {
        srv_email_emn_attr_struct *pAttr = (srv_email_emn_attr_struct*)&srv_email_emn_start_attrs[token - SRV_EMAIL_EMN_SATTR_MIN];

        strcpy(ptr, pAttr->attrname);
        if (pAttr->attrprefix)
        {
            strcpy(attrprefix, pAttr->attrprefix);
        }
        len = strlen(pAttr->attrname);
    }
    else if (token >= SRV_EMAIL_EMN_VATTR_MIN && token <= SRV_EMAIL_EMN_VATTR_MAX)
    {
        CHAR *temp = NULL;

        temp = (CHAR*)srv_email_emn_value_attrs[token - SRV_EMAIL_EMN_VATTR_MIN];
        strcpy(ptr, temp);
        len = strlen(temp);
    }

    return len;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_parse_mailbox
 * DESCRIPTION
 *  Parse the mailbox attribute.
 * PARAMETERS
 *  pMbox            [IN]        Point to the mailbox attribute
 *  pAddr            [OUT]       Point to the email address buffer
 *  buflen           [IN]        The length of the email address buffer
 * RETURNS
 *  The error code.
 *****************************************************************************/
static S32 srv_email_emn_parse_mailbox(const CHAR *pMbox, CHAR *pAddr, S32 buflen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_emn_attr_struct *pAttr;
    S32 len = 0;
    CHAR *temp;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = SRV_EMAIL_EMN_START_MAILBOX_MAILAT; i <= SRV_EMAIL_EMN_START_MAILBOX_HTTPS3W; i++)
    {
        pAttr = (srv_email_emn_attr_struct*)&srv_email_emn_start_attrs[i - SRV_EMAIL_EMN_SATTR_MIN];
        len = strlen(pAttr->attrprefix);
        if (app_strnicmp((CHAR*)pMbox, pAttr->attrprefix, len) == 0)
        {
            if (i > SRV_EMAIL_EMN_START_MAILBOX_MAILAT)
            {
                return SRV_EMAIL_EMN_RETCODE_MB_NOT_SUPPORT;
            }

            break;
        }
    }

    if (i > SRV_EMAIL_EMN_START_MAILBOX_HTTPS3W)
    {
        len = 0;
    }

    temp = (CHAR*)pMbox + len;

    if (buflen < (S32)strlen(temp) + 1)
    {
        return SRV_EMAIL_EMN_RETCODE_MB_TOO_LONG;
    }

    if (applib_is_valid_email_address(temp))
    {
        strcpy(pAddr, temp);
        return SRV_EMAIL_EMN_RETCODE_SUCC;
    }
    else
    {
        return SRV_EMAIL_EMN_RETCODE_MB_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_parse_wbxml_timestamp
 * DESCRIPTION
 *  Parse the timestamp attribute (wbxml).
 * PARAMETERS
 *  pTstamp          [IN]        Point to the timestamp attribute
 *  pTime            [OUT]       Point to the time structure
 * RETURNS
 *  The error code.
 *****************************************************************************/
static S32 srv_email_emn_parse_wbxml_timestamp(const CHAR *pTstamp, MYTIME *pTime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *s = (U8*)pTstamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pTime, 0, sizeof(MYTIME));

    /* Year */
    pTime->nYear =
        ((s[0] >> 4) * 1000) + ((s[0] & 0x0F) * 100) +
        ((s[1] >> 4) * 10) + (s[1] & 0x0F);

    /* Month */
    pTime->nMonth = ((s[2] >> 4) * 10) + (s[2] & 0x0F);

    /* Day */
    pTime->nDay = ((s[3] >> 4) * 10) + (s[3] & 0x0F);

    /* Hour */
    if (s[4] != 0)
    {
        pTime->nHour = ((s[4] >> 4) * 10) + (s[4] & 0x0F);

        /* Minute */
        if (s[5] != 0)
        {
            pTime->nMin= ((s[5] >> 4) * 10) + (s[5] & 0x0F);

            /* Second */
            if (s[6] != 0)
            {
                pTime->nSec= ((s[6] >> 4) * 10) + (s[6] & 0x0F);
            }
        }
    }

    if (srv_email_emn_is_timestamp_valid(pTime))
    {
        return SRV_EMAIL_EMN_RETCODE_SUCC;
    }
    else
    {
        return SRV_EMAIL_EMN_RETCODE_TS_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_is_timestamp_valid
 * DESCRIPTION
 *  Check the validity of the timestamp.
 * PARAMETERS
 *  pTime            [IN]           Point to the time structure
 * RETURNS
 *  MMI_TRUE/MMI_FALSE
 *****************************************************************************/
static MMI_BOOL srv_email_emn_is_timestamp_valid(MYTIME *pTime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((pTime->nYear <= SRV_EMAIL_EMN_YEAR_MAX) &&
        (pTime->nMonth >= SRV_EMAIL_EMN_MONTH_MIN && pTime->nMonth <= SRV_EMAIL_EMN_MONTH_MAX) &&
        (pTime->nDay >= SRV_EMAIL_EMN_DAY_MIN && pTime->nDay <= SRV_EMAIL_EMN_DAY_MAX) &&
        (pTime->nHour <= SRV_EMAIL_EMN_HOUR_MAX) &&
        (pTime->nMin <= SRV_EMAIL_EMN_MINUTE_MAX) &&
        (pTime->nSec <= SRV_EMAIL_EMN_SECOND_MAX))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_parse_xml_file
 * DESCRIPTION
 *  This function is used to parse the Email notification (xml).
 * PARAMETERS
 *  filepath            [IN]        The EMN file path
 * RETURNS
 *  The error code
 *****************************************************************************/
static S32 srv_email_emn_parse_xml_file(const WCHAR *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_email_emn_xml_p = (XML_PARSER_STRUCT*)OslMalloc(sizeof(XML_PARSER_STRUCT));

    if (xml_new_parser(srv_email_emn_xml_p) < 0)
    {
        OslMfree(srv_email_emn_xml_p);
        srv_email_emn_xml_p = NULL;
        return SRV_EMAIL_EMN_RETCODE_MEM_FULL;
    }

    xml_register_element_handler(srv_email_emn_xml_p, srv_email_emn_xml_start_hdlr, NULL);
    xml_register_data_handler(srv_email_emn_xml_p, NULL);

    ret = xml_parse(srv_email_emn_xml_p, (kal_wchar*)filepath);
    xml_close_parser(srv_email_emn_xml_p);

    OslMfree(srv_email_emn_xml_p);
    srv_email_emn_xml_p = NULL;

    if (srv_email_emn_errcode == 0 && ret == XML_RESULT_OK)
    {
        if (!srv_email_emn_addr_exist)
        {
            srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_MB_INVALID;
        }
        else if (!srv_email_emn_time_exist)
        {
            srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_TS_INVALID;
        }
    }

    if (srv_email_emn_errcode < 0)
    {
        return srv_email_emn_errcode;
    }
    else
    {
        return srv_email_emn_convert_xml_parser_errcode(ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_xml_start_hdlr
 * DESCRIPTION
 *  The handler of the xml element start.
 * PARAMETERS
 *  data         [IN]        reserved
 *  el           [IN]        Element name
 *  attr         [IN]        Attribution list
 *  error        [IN]        error code
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_email_emn_xml_start_hdlr(
                void *data,
                const kal_char *el,
                const kal_char **attr,
                kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; attr[i]; i += 2)
    {
        if (app_stricmp((CHAR*)attr[i], "mailbox") == 0)
        {
            if (srv_email_emn_addr_exist)
            {
                srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_MB_INVALID;
            }
            else
            {
                srv_email_emn_errcode =
                    srv_email_emn_parse_mailbox(
                        (const CHAR*)attr[i + 1],
                        srv_email_emn_addr_p,
                        SRV_EMAIL_MAX_ADDR_LEN + 1);
                srv_email_emn_addr_exist = MMI_TRUE;
            }
        }
        else if (app_stricmp((CHAR*)attr[i], "timestamp") == 0)
        {
            if (srv_email_emn_time_exist)
            {
                srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_TS_INVALID;
            }
            else
            {
                srv_email_emn_errcode =
                    srv_email_emn_parse_xml_timestamp(
                        (const CHAR*)attr[i + 1],
                        srv_email_emn_time_p);
                srv_email_emn_time_exist = MMI_TRUE;
            }
        }

        if (srv_email_emn_errcode < 0)
        {
            xml_stop_parse(srv_email_emn_xml_p);
            return;
        }
    }

    if (!srv_email_emn_addr_exist)
    {
        srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_MB_INVALID;
    }
    else if (!srv_email_emn_time_exist)
    {
        srv_email_emn_errcode = SRV_EMAIL_EMN_RETCODE_TS_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_parse_xml_timestamp
 * DESCRIPTION
 *  Parse the timestamp attribute (xml).
 * PARAMETERS
 *  pTstamp          [IN]        Point to the timestamp attribute
 *  pTime            [OUT]       Point to the time structure
 * RETURNS
 *  The error code
 *****************************************************************************/
static S32 srv_email_emn_parse_xml_timestamp(const CHAR *pTstamp, MYTIME *pTime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *s = (CHAR*)pTstamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pTime, 0, sizeof(MYTIME));

    if (strlen(s) != 20)
    {
        return SRV_EMAIL_EMN_RETCODE_TS_INVALID;
    }

    if (s[4] != '-' || s[7] != '-' || s[10] != 'T' ||
        s[13] != ':' || s[16] != ':' || s[19] != 'Z')
    {
        return SRV_EMAIL_EMN_RETCODE_TS_INVALID;
    }

    if (!(isdigit(s[0]) && isdigit(s[1]) && isdigit(s[2]) && isdigit(s[3]) &&
          isdigit(s[5]) && isdigit(s[6]) && isdigit(s[8]) && isdigit(s[9]) &&
          isdigit(s[11]) && isdigit(s[12]) && isdigit(s[14]) && isdigit(s[15]) &&
          isdigit(s[17]) && isdigit(s[18])))
    {
        return SRV_EMAIL_EMN_RETCODE_TS_INVALID;
    }

    /* Year */
    pTime->nYear =
        ((s[0] - '0') * 1000) + ((s[1] - '0') * 100) +
        ((s[2] - '0') * 10) + (s[3] - '0');

    /* Month */
    pTime->nMonth = ((s[5] - '0') * 10) + (s[6] - '0');

    /* Day */
    pTime->nDay = ((s[8] - '0') * 10) + (s[9] - '0');

    /* Hour */
    pTime->nHour = ((s[11] - '0') * 10) + (s[12] - '0');

    /* Minute */
    pTime->nMin= ((s[14] - '0') * 10) + (s[15] - '0');

    /* Second */
    pTime->nSec= ((s[17] - '0') * 10) + (s[18] - '0');

    if (srv_email_emn_is_timestamp_valid(pTime))
    {
        return SRV_EMAIL_EMN_RETCODE_SUCC;
    }
    else
    {
        return SRV_EMAIL_EMN_RETCODE_TS_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_convert_wbxml_parser_errcode
 * DESCRIPTION
 *  Convert the wbxml parser error code
 * PARAMETERS
 *  err_code        [IN]        
 * RETURNS
 *  MMI_PROV_RETCODE
 *****************************************************************************/
static S32 srv_email_emn_convert_wbxml_parser_errcode(S32 errcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (errcode)
    {
        case WBXML_RESULT_OK:
            return SRV_EMAIL_EMN_RETCODE_SUCC;

        case WBXML_E_NO_MEMORY:
            return SRV_EMAIL_EMN_RETCODE_MEM_FULL;

        case WBXML_E_UNKNOWN_CHARSET:
            return SRV_EMAIL_EMN_RETCODE_CHARSET_ERR;

        case WBXML_E_UNKNOWN_TAG:
        case WBXML_E_MISMATCH_TAG:
            return SRV_EMAIL_EMN_RETCODE_TAG_ERR;

        default:
            return SRV_EMAIL_EMN_RETCODE_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_convert_xml_parser_errcode
 * DESCRIPTION
 *  Convert the xml parser error code
 * PARAMETERS
 *  err_code        [IN]        
 * RETURNS
 *  MMI_PROV_RETCODE
 *****************************************************************************/
static S32 srv_email_emn_convert_xml_parser_errcode(S32 errcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (errcode)
    {
        case XML_RESULT_OK:
            return SRV_EMAIL_EMN_RETCODE_SUCC;

        case XML_RESULT_ENCODING_ERROR:
            return SRV_EMAIL_EMN_RETCODE_CHARSET_ERR;

        case XML_RESULT_OUT_OF_MEMORY:
            return SRV_EMAIL_EMN_RETCODE_MEM_FULL;

        default:
            return SRV_EMAIL_EMN_RETCODE_FAIL;
    }
}

#endif /* __SRV_EMAIL_EMN__ */


/*****************************************************************************
 * FUNCTION
 *  srv_email_receive_emn_file
 * DESCRIPTION
 *  This function is used to process the EMN notification.
 * PARAMETERS
 *  srv_handle          [IN]        The service handle
 *  session_id          [IN]        The session ID
 *  mime_type           [IN]        The mime type
 *  mime_subtype        [IN]        The mime sub-type
 *  action              [IN]        The action
 *  filepath            [IN]        The file path
 *  url                 [IN]        The file original URI
 *  mime_type_string    [IN]        The mime type string
 * RETURNS
 *  void
 *****************************************************************************/
void srv_email_receive_emn_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        CHAR *url,
        CHAR *mime_type_string)
{

#ifdef __SRV_EMAIL_EMN__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_email_emn_info_struct *info_p = NULL;
    srv_email_acct_info_struct *acct_p = NULL;
    EMAIL_ACCT_ID acct_id[EMAIL_STOR_ACCT_NUM_MAX];
    EMAIL_ACCT_ID emn_acct_id = EMAIL_ACCT_INVALID_ID;
    srv_email_result_enum retval = SRV_EMAIL_RESULT_SUCC;
    S32 ret = 0;
    WCHAR addr[SRV_EMAIL_MAX_ADDR_LEN + 1];
    U32 count = 0;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_FUNC_NWK_EMN_RECEIVED, srv_email_emn_p->emn_callback);

    if (!srv_email_emn_p || !srv_email_emn_p->emn_callback)
    {
        return;
    }

    count = srv_email_stor_acct_id_get(acct_id);
    if (!count)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_NWK_EMN_NO_ACCT_IN_LOCAL);
        return;
    }

    info_p = (srv_email_emn_info_struct*)OslMalloc(sizeof(srv_email_emn_info_struct));

    ret = srv_email_emn_parse_emn_file(mime_type, mime_subtype, (const WCHAR*)filepath, info_p);

    FS_Delete(filepath);

    if (ret < 0)
    {
        MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_EMN_PARSE_FILE, ret);
        OslMfree(info_p);
        return;
    }

    mmi_asc_to_ucs2((CHAR*)addr, info_p->address);
    OslMfree(info_p);

    acct_p = (srv_email_acct_info_struct*)OslMalloc(sizeof(srv_email_acct_info_struct));

    for (i = 0; i < count; i++)
    {
        memset(acct_p, 0, sizeof(srv_email_acct_info_struct));
        acct_p->acct_id = acct_id[i];

        retval = srv_email_stor_acct_info_read(acct_p);
        if (retval != SRV_EMAIL_RESULT_SUCC)
        {
            MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_ERROR_NWK_EMN_READ_ACCT_INFO, ret);
            break;
        }

        if ((acct_p->notify_option == SRV_EMAIL_NOTIFY_ON ||
             acct_p->notify_option == SRV_EMAIL_NOTIFY_HOME_NETWORK_ONLY) &&
			!mmi_wcsicmp((const WCHAR*)acct_p->email_addr.email_addr, (const WCHAR*)addr))
        {
            emn_acct_id = acct_id[i];
            break;
        }
    }

    OslMfree(acct_p);

    MMI_TRACE(MMI_INET_TRC_G9_EMAIL, SRV_EMAIL_INFO_NWK_EMN_PARSE_DONE, emn_acct_id);
    if (emn_acct_id != EMAIL_ACCT_INVALID_ID)
    {
        srv_email_emn_p->emn_callback(emn_acct_id);
    }
#endif /* __SRV_EMAIL_EMN__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_emn_init
 * DESCRIPTION
 *  This function is used to initialize the EMN module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 ****************************************************************************/
srv_email_result_enum srv_email_emn_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_EMAIL_EMN__
    if (!srv_email_emn_inited)
    {
        srv_email_emn_p = &srv_email_emn;
        memset(srv_email_emn_p, 0, sizeof(srv_email_emn_struct));
        srv_email_emn_p->allow_register = MMI_TRUE;
        srv_email_emn_inited = MMI_TRUE;
    }
#endif /* __SRV_EMAIL_EMN__ */

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_register_emn_notify
 * DESCRIPTION
 *  This function is used to register the EMN notify function for
 *  the specified service instance.
 * PARAMETERS
 *  srv_handle      [IN]        The service handle
 *  emn_callback    [IN]        The EMN notify function
 *  clear_callback  [IN]        The EMN clear notify function
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_register_emn_notify(
                        EMAIL_SRV_HANDLE srv_handle,
                        srv_email_emn_funcptr_type emn_callback,
                        srv_email_funcptr_type clear_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_EMAIL_EMN__
    if (!emn_callback)
    {
        return SRV_EMAIL_RESULT_INVALID_PARAMETER;
    }

    // TODO: check the service handle first

    if (!srv_email_emn_p->allow_register)
    {
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    if (srv_email_emn_p->clear_callback)
    {
        srv_email_emn_p->allow_register = MMI_FALSE;
        srv_email_emn_p->clear_callback();
        srv_email_emn_p->allow_register = MMI_TRUE;
    }

    srv_email_emn_p->srv_handle = srv_handle;
    srv_email_emn_p->emn_callback = emn_callback;
    srv_email_emn_p->clear_callback = clear_callback;
#endif /* __SRV_EMAIL_EMN__ */

    return SRV_EMAIL_RESULT_SUCC;
}


/*****************************************************************************
 * FUNCTION
 *  srv_email_clear_emn_notify
 * DESCRIPTION
 *  This function is used to clear the EMN notify function for
 *  the specified service instance.
 * PARAMETERS
 *  srv_handle      [IN]        The service handle
 * RETURNS
 *  The result code.
 ****************************************************************************/
srv_email_result_enum srv_email_clear_emn_notify(EMAIL_SRV_HANDLE srv_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_EMAIL_EMN__
    // TODO: check the service handle first

    if (!srv_email_emn_p->emn_callback)
    {
        return SRV_EMAIL_RESULT_INVALID_STATE;
    }

    if (srv_email_emn_p->srv_handle != srv_handle)
    {
        return SRV_EMAIL_RESULT_INVALID_HANDLE;
    }

    srv_email_emn_p->srv_handle = EMAIL_SRV_INVALID_HANDLE;
    srv_email_emn_p->emn_callback = NULL;
    srv_email_emn_p->clear_callback = NULL;
#endif /* __SRV_EMAIL_EMN__ */

    return SRV_EMAIL_RESULT_SUCC;
}


#endif /* __MMI_EMAIL__ */
