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

/*******************************************************************************
 * Filename:
 * ---------
 *  cmcc_wlan_auth_http.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
  
#include "MMI_features.h"

#ifdef __MMI_OP01_WIFI__


#include "MMI_include.h"
#include "DataAccountCommon.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"

#include "fs_type.h"
#include "fs_func.h"

#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"

#include "cbm_consts.h"
#include "wps_struct.h"
#include "cbm_api.h"

#ifdef __SSL_SUPPORT__
#include "tls_api.h"
#endif

#include "cmcc_wlan_auth_gprot.h"
#include "cmcc_wlan_auth_prot.h"

// For debug
//#define __CMCC_WLAN_AUTH_UT__ 


#ifdef __CMCC_WLAN_AUTH_UT__
static void copy_http_rsp_file_ut(void);
static void copy_http_req_file_ut(U8 *url, U8 *post);
#endif /* __CMCC_WLAN_AUTH_UT__ */

/* Defines */
#define CMCC_WLAN_WPS_TIMEOUT  120

#define CMCC_WLAN_HTTP_TYR_URL "http://www.baidu.com/"
#define CMCC_WLAN_WPS_USER_AGENT "G3WLAN(MTK)\r\n"

#define CMCC_WLAN_HTTP_FILENAME_LEN 32
#define CMCC_WLAN_HTTP_FILENAME "wlanhttp.html"

#define CMCC_WLAN_MAX_FILE_BUF_SIZE ((CMCC_WLAN_HTTP_FILENAME_LEN + 3) * 4)
#define CMCC_WLAN_MAX_STRING_LEN 128

#define CMCC_WLAN_MAKE_FILENAME(str) \
    do{\
    kal_wsprintf(str,\
        "%c:\\%s",\
        (CHAR) FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_DRIVE_I_SYSTEM),\
        CMCC_WLAN_HTTP_FILENAME);\
    }while(0)

#define CMCC_SET_WPS_MSG_HANDLER(cb, msg) \
    do{\
        mmi_frm_set_protocol_event_handler(msg, (PsIntFuncPtr)cb, MMI_TRUE);\
    }while(0)

#define HTML_PORTAL_S_INIT 0
#define HTML_PORTAL_S_TAG_INIT 1
#define HTML_PORTAL_S_TAG 2

#define HTML_PORTAL_FORM_S_INIT   1
#define HTML_PORTAL_FORM_S_INPUT  2

#define CMCC_WLAN_ACTIVITY_NONE 0
#define CMCC_WLAN_ACTIVITY_LOGIN 1
#define CMCC_WLAN_ACTIVITY_LOGOUT 2


typedef enum
{
    CMCC_WLAN_S_NULL,

    CMCC_WLAN_S_WPS_INIT,  /* Set up channel */

    CMCC_WLAN_S_AUTH_TRY,
    CMCC_WLAN_S_AUTH_PORTAL,
    CMCC_WLAN_S_AUTH_LOGIN,
    CMCC_WLAN_S_AUTH_LOGOUT,
}cmcc_wlan_stat_enum;

typedef struct
{
    CHAR *form_name;
    CHAR *action_url;
    CHAR *portal_url;

    CHAR *wlanacname;
    CHAR *wlanacip;
    CHAR *wlanuserip;
    CHAR *wlanacssid;
    //CHAR *actiontype;
    CHAR *languagetype;
    CHAR *logonsessid;
}cmcc_wlan_portal_cntx_struct;

typedef struct 
{
    CHAR *logout_url;
    CHAR *logout_post;
}cmcc_wlan_logout_data_struct;

typedef struct
{
    /* Response */
    FS_HANDLE fh;
    CHAR buf[CMCC_WLAN_MAX_FILE_BUF_SIZE];
    U32 buf_len;
    U32 buf_off;
    S32 buf_state;
    CHAR temp_string[CMCC_WLAN_MAX_STRING_LEN + 1];

    U32 ret;
    cmcc_wlan_auth_callback callback;

    U8 activity; 
    U16 wps_request_id;

    cmcc_wlan_stat_enum s;
}cmcc_wlan_cntx_struct;

static U8 g_wps_channel_id = 0xFF;

static cmcc_wlan_cntx_struct g_cmcc_wlan_cntx;
static cmcc_wlan_portal_cntx_struct g_cmcc_wlan_portal_cntx;
static cmcc_wlan_logout_data_struct g_cmcc_wlan_logout_data;

static void cmcc_wlan_auth_fsm(void);
static void cmcc_wlan_send_callback(cmcc_wlan_auth_ret_enum ret);

static void cmcc_wlan_wps_init_req(void);
static MMI_BOOL cmcc_wlan_wps_init_rsp(void *msg, S32 src, void *ilm);

static void cmcc_wlan_wps_clean_req(void);
static MMI_BOOL cmcc_wlan_wps_clean_rsp(void *msg, S32 src, void *ilm);

static void cmcc_wlan_wps_try_req(void);
static void cmcc_wlan_wps_portal_req(void);
static void cmcc_wlan_wps_portal_rsp(wps_http_rsp_struct *para);

static void cmcc_wlan_wps_login_req(void);
static void cmcc_wlan_wps_login_rsp(wps_http_rsp_struct *para);

static void cmcc_wlan_wps_logout_req(void);
static void cmcc_wlan_wps_logout_rsp(wps_http_rsp_struct *para);

static void cmcc_wlan_wps_http_request(U8 *url, U8 *data, BOOL auto_redirect);
static MMI_BOOL cmcc_wlan_wps_http_ind(void *msg, S32 src, void *ptr);
static MMI_BOOL cmcc_wlan_wps_http_rsp(void *msg, S32 src, void *ptr);

static BOOL cmcc_wlan_html_open(void);
static BOOL cmcc_wlan_html_read(void);
static CHAR cmcc_wlan_html_next_char(void);
static BOOL cmcc_wlan_html_close(void);

static void cmcc_wlan_remake_logout_parameter(void);
static BOOL cmcc_wlan_html_parse_portal(void);
static BOOL cmcc_wlan_html_parse_login(void);

static BOOL parse_form(CHAR *tag_line);
static BOOL parse_input(CHAR *tag_line);
static void parse_save_field(CHAR *name, CHAR *value);

static U32 make_http_user_data(CHAR *buf, U32 len, BOOL login);

static U16 cmcc_wps_get_next_req_id(void);

/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_html_open
 * DESCRIPTION 
 *  cmcc wlan html open
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL cmcc_wlan_html_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cmcc_wlan_cntx.fh >= 0)
    {
        FS_Close(g_cmcc_wlan_cntx.fh);
        g_cmcc_wlan_cntx.fh = -1;
    }

    filename = (WCHAR*)g_cmcc_wlan_cntx.buf;
    CMCC_WLAN_MAKE_FILENAME(filename);
    g_cmcc_wlan_cntx.fh = FS_Open(filename, FS_READ_ONLY | FS_OPEN_SHARED);

    if (g_cmcc_wlan_cntx.fh < 0)
    {
        return FALSE;
    }

    /* reset read buffer */
    g_cmcc_wlan_cntx.buf_off = 0;
    g_cmcc_wlan_cntx.buf_len = 0;

    return TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_html_read
 * DESCRIPTION 
 *  cmcc wlan html read
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL cmcc_wlan_html_read(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cmcc_wlan_cntx.buf_off = 0;
    g_cmcc_wlan_cntx.buf_len = 0;

    ret = FS_Read(g_cmcc_wlan_cntx.fh, g_cmcc_wlan_cntx.buf, CMCC_WLAN_MAX_FILE_BUF_SIZE, &g_cmcc_wlan_cntx.buf_len);
    if (ret < 0 || g_cmcc_wlan_cntx.buf_len == 0)
    {
        g_cmcc_wlan_cntx.buf_len = 0;
        return FALSE;
    }

    return TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_html_close
 * DESCRIPTION 
 *  cmcc wlan html close
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL cmcc_wlan_html_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cmcc_wlan_cntx.fh >= 0)
    {
        FS_Close(g_cmcc_wlan_cntx.fh);
        g_cmcc_wlan_cntx.fh = -1;
    }

    return TRUE;
}

/* Parse utility */


/*****************************************************************************
 * FUNCTION 
 *  *cmcc_wlan_toupper
 * DESCRIPTION 
 *  *cmcc wlan toupper
 * PARAMETERS 
 *  CHAR *str
 * RETURNS 
 *  static CHAR 
*****************************************************************************/
static CHAR *cmcc_wlan_toupper(CHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; str[i] != 0; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 'a' - 'A';
        }
    }

    return str;
}



/*****************************************************************************
 * FUNCTION 
 *  *cmcc_wlan_tolower
 * DESCRIPTION 
 *  *cmcc wlan tolower
 * PARAMETERS 
 *  CHAR *str
 * RETURNS 
 *  static CHAR 
*****************************************************************************/
static CHAR *cmcc_wlan_tolower(CHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; str[i] != 0; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 'a' - 'A';
        }
    }

    return str;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_html_next_char
 * DESCRIPTION 
 *  cmcc wlan html next char
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static CHAR 
*****************************************************************************/
static CHAR cmcc_wlan_html_next_char(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cmcc_wlan_cntx.fh < 0)
    {
        return 0;
    }

    if (g_cmcc_wlan_cntx.buf_off >= g_cmcc_wlan_cntx.buf_len)
    {
        // read more
        if (!cmcc_wlan_html_read())
        {
            return 0;
        }

        if (g_cmcc_wlan_cntx.buf_off >= g_cmcc_wlan_cntx.buf_len)
        {
            return 0;
        }
    }

    c = g_cmcc_wlan_cntx.buf[g_cmcc_wlan_cntx.buf_off++];
    return c;
}


/*****************************************************************************
 * FUNCTION 
 *  *get_next_words
 * DESCRIPTION 
 *  *get next words
 * PARAMETERS 
 *  CHAR **pp
 * RETURNS 
 *  static CHAR 
*****************************************************************************/
static CHAR *get_next_words(CHAR **pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *p = *pp;
    CHAR *words = *pp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // Skip PRE blanks
    while(*words == ' ' || *words == '\t')
    {
        words++;
    }

    if (*words == '\"')
    {
        words++;
        p = words;
        while(*p != '\"' && *p != '\0')
        {
            p++;
        }
    }
    else if (*words == '\'')
    {
        words++;
        p = words;
        while(*p != '\'' && *p != '\0')
        {
            p++;
        }
    }
    else
    {
        p = words;
        while (*p != ' ' && *p !=  '=' && *p != '\0')
        {
            p++;
        }
    }

    if (*p != 0)
    {
        *(p++) = 0;
    }

    *pp = p;
    return words;
}


/*****************************************************************************
 * FUNCTION 
 *  is_termi_character
 * DESCRIPTION 
 *  is termi character
 * PARAMETERS 
 *  CHAR c
 *  const CHAR *termi
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL is_termi_character(CHAR c, const CHAR *termi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(termi != NULL && termi[0] != 0);

    i = 0;
    for (i = 0; termi[i] != 0; i++)
    {
        if (c == termi[i])
        {
            return TRUE;
        }
    }

    return FALSE;
}


/*****************************************************************************
 * FUNCTION 
 *  *get_next_string_from_file
 * DESCRIPTION 
 *  *get next string from file
 * PARAMETERS 
 *  const CHAR *termi
 * RETURNS 
 *  static CHAR 
*****************************************************************************/
static CHAR *get_next_string_from_file(const CHAR *termi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    CHAR c, *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str = g_cmcc_wlan_cntx.temp_string;

    // Skip leading blank
    c = cmcc_wlan_html_next_char();
    while(is_termi_character(c, termi))
    {
        c = cmcc_wlan_html_next_char();
    }

    if (c == 0)
    {
        return NULL;
    }

    i = 0;
    if (c == '\'')
    {
        c = cmcc_wlan_html_next_char();
        while(c != 0 && c != '\'')
        {
            if (i + 1 < CMCC_WLAN_MAX_STRING_LEN - 1)
            {
                str[i++] = c;
            }
            c = cmcc_wlan_html_next_char();
        }
    }
    else if (c == '\"')
    {
        c = cmcc_wlan_html_next_char();
        while(c != 0 && c != '\"')
        {
            if (i + 1 < CMCC_WLAN_MAX_STRING_LEN - 1)
            {
                str[i++] = c;
            }
            c = cmcc_wlan_html_next_char();
        }
    }
    else
    {
        while(c != 0 && !is_termi_character(c, termi))
        {
            if (i + 1 < CMCC_WLAN_MAX_STRING_LEN - 1)
            {
                str[i++] = c;
            }
            c = cmcc_wlan_html_next_char();
    }
    }

    str[i] = 0;
    return str;
}


/*****************************************************************************
 * FUNCTION 
 *  parse_form_safe_free
 * DESCRIPTION 
 *  parse form safe free
 * PARAMETERS 
 *  CHAR **pp
 * RETURNS 
 *  static void 
*****************************************************************************/
static void parse_form_safe_free(CHAR **pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*pp != NULL)
    {
        OslMfree(*pp);
        *pp = NULL;
    }
}


/*****************************************************************************
 * FUNCTION 
 *  parse_form_free
 * DESCRIPTION 
 *  parse form free
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void parse_form_free(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parse_form_safe_free(&g_cmcc_wlan_portal_cntx.form_name);
    parse_form_safe_free(&g_cmcc_wlan_portal_cntx.action_url);
    parse_form_safe_free(&g_cmcc_wlan_portal_cntx.portal_url);

    parse_form_safe_free(&g_cmcc_wlan_portal_cntx.wlanacname);
    parse_form_safe_free(&g_cmcc_wlan_portal_cntx.wlanacip);
    parse_form_safe_free(&g_cmcc_wlan_portal_cntx.wlanuserip);
    parse_form_safe_free(&g_cmcc_wlan_portal_cntx.wlanacssid);
    //parse_form_safe_free(&g_cmcc_wlan_portal_cntx.actiontype);
    parse_form_safe_free(&g_cmcc_wlan_portal_cntx.languagetype);
    parse_form_safe_free(&g_cmcc_wlan_portal_cntx.logonsessid);
}


/*****************************************************************************
 * FUNCTION 
 *  parse_form
 * DESCRIPTION 
 *  parse form
 * PARAMETERS 
 *  CHAR *tag_line
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL parse_form(CHAR *tag_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *action_url = NULL, *formname = NULL;
    CHAR *words;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    words = get_next_words(&tag_line);
    cmcc_wlan_toupper(words);
    if (strcmp(words, "FORM") != 0)
    {
        return FALSE;
    }

    words = get_next_words(&tag_line);
    while (words != NULL && words[0] != 0)
    {
        cmcc_wlan_toupper(words);
        if (strcmp(words, "ACTION") == 0)
        {
            // Get action URL
            action_url = get_next_words(&tag_line);
        }
        else if (strcmp(words, "NAME") == 0)
        {
            formname = get_next_words(&tag_line);
        }
        else
        {
            // Skip it
            get_next_words(&tag_line);
        }

        words = get_next_words(&tag_line);
    }

    if (action_url != NULL)
    {
        g_cmcc_wlan_portal_cntx.action_url = OslMalloc(strlen(action_url) + 1);
        strcpy(g_cmcc_wlan_portal_cntx.action_url, action_url);
    }

    if (formname != NULL)
    {
        g_cmcc_wlan_portal_cntx.form_name = OslMalloc(strlen(formname) + 1);
        cmcc_wlan_tolower(words);
        strcpy(g_cmcc_wlan_portal_cntx.form_name, formname);
    }

    return TRUE;
}



/*****************************************************************************
 * FUNCTION 
 *  parse_save_field_safe
 * DESCRIPTION 
 *  parse save field safe
 * PARAMETERS 
 *  CHAR **pp
 *  CHAR *value
 * RETURNS 
 *  static void 
*****************************************************************************/
static void parse_save_field_safe(CHAR **pp, CHAR *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(value);

    parse_form_safe_free(pp);
    *pp = OslMalloc(len + 1);
    strcpy(*pp, value);
}


/*****************************************************************************
 * FUNCTION 
 *  parse_save_field
 * DESCRIPTION 
 *  parse save field
 * PARAMETERS 
 *  CHAR *name
 *  CHAR *value
 * RETURNS 
 *  static void 
*****************************************************************************/
static void parse_save_field(CHAR *name, CHAR *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(name != NULL);
    ASSERT(value != NULL);

    cmcc_wlan_tolower(name);
    if (strcmp(name, "wlanacname") == 0)
    {
        parse_save_field_safe(&g_cmcc_wlan_portal_cntx.wlanacname, value);
    }
    else if (strcmp(name, "wlanuserip") == 0)
    {
        parse_save_field_safe(&g_cmcc_wlan_portal_cntx.wlanuserip, value);
    }
    else if (strcmp(name, "wlanacip") == 0)
    {
        parse_save_field_safe(&g_cmcc_wlan_portal_cntx.wlanacip, value);
    }
    else if (strcmp(name, "wlanacssid") == 0)
    {
        parse_save_field_safe(&g_cmcc_wlan_portal_cntx.wlanacssid, value);
    }
    else if (strcmp(name, "languagetype") == 0)
    {
        parse_save_field_safe(&g_cmcc_wlan_portal_cntx.languagetype, value);
    }
    else if (strcmp(name, "portalurl") == 0)
    {
        parse_save_field_safe(&g_cmcc_wlan_portal_cntx.portal_url, value);
    }
    else if (strcmp(name, "logonsessid") == 0)
    {
        parse_save_field_safe(&g_cmcc_wlan_portal_cntx.logonsessid, value);
    }
    else
    {
        // Nothing to do
    }
}


/*****************************************************************************
 * FUNCTION 
 *  make_http_user_data
 * DESCRIPTION 
 *  make http user data
 * PARAMETERS 
 *  CHAR *buf
 *  U32 len
 *  BOOL login
 * RETURNS 
 *  static U32 
*****************************************************************************/
static U32 make_http_user_data(CHAR *buf, U32 len, BOOL login)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const CHAR CMCC_LOGIN_STR_TEMPLATE[] = 
        "USER=%s&PWD=%s&wlanacname=%s&wlanuserip=%s&pwdtype=1&inputtype=0&areatype=0&actiontype=LOGIN";

    static const CHAR CMCC_LOGOUT_STR_TEMPLATE[] = 
        "wlanuserip=%s&wlanacname=%s&logonsessid=%s&actiontype=LOGOUT";

    U32 total = 0;
    CHAR *wlanacname, *wlanuserip, *logonsessid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlanacname = g_cmcc_wlan_portal_cntx.wlanacname;
    if (wlanacname == NULL) wlanacname = "";

    wlanuserip = g_cmcc_wlan_portal_cntx.wlanuserip;
    if (wlanuserip == NULL) wlanuserip = "";

    logonsessid = g_cmcc_wlan_portal_cntx.logonsessid;
    if (logonsessid == NULL) logonsessid = "";

    ASSERT(g_cmcc_wlan_portal_cntx.action_url != NULL);
    ASSERT(g_cmcc_wlan_portal_cntx.action_url[0] != 0);

    total = 0;
    if (login)
    {
        total += strlen(CMCC_LOGIN_STR_TEMPLATE);
        total += strlen(cmcc_wlan_auth_setting_get_user());
        total += strlen(cmcc_wlan_auth_setting_get_pass());
        total += strlen(wlanacname);
        total += strlen(wlanuserip);
        total -= 2 * 4;
    }
    else
    {
        total += strlen(CMCC_LOGOUT_STR_TEMPLATE);
        total += strlen(wlanuserip);
        total += strlen(wlanacname);
        total += strlen(logonsessid);
        total -= 2 * 3;
    }

    if (buf == NULL)
    {
        return total;
    }

    ASSERT(len >= total);

    if (login)
    {
        sprintf(buf, CMCC_LOGIN_STR_TEMPLATE,
            cmcc_wlan_auth_setting_get_user(),
            cmcc_wlan_auth_setting_get_pass(),
            wlanacname,
            wlanuserip);
    }
    else
    {
        sprintf(buf, CMCC_LOGOUT_STR_TEMPLATE,
            wlanuserip,
            wlanacname,
            logonsessid);
    }

    return total;
}


/*****************************************************************************
 * FUNCTION 
 *  parse_input
 * DESCRIPTION 
 *  parse input
 * PARAMETERS 
 *  CHAR *tag_line
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL parse_input(CHAR *tag_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *words;
    CHAR *l, *r;
    CHAR *name, *value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    words = get_next_words(&tag_line);
    cmcc_wlan_toupper(words);
    if (strcmp(words, "/FORM") == 0)
    {
        return TRUE;
    }

    if (strcmp(words, "INPUT") != 0)
    {
        return TRUE;
    }

    name = value = NULL;
    while (tag_line[0] != 0)
    {
        l = get_next_words(&tag_line);
        r = get_next_words(&tag_line);

        cmcc_wlan_toupper(l);
        if (strcmp(l, "NAME") == 0)
        {
            name = r;
        }
        else if (strcmp(l, "VALUE") == 0)
        {
            value = r;
        }
    }

    if (name != NULL && value != NULL)
    {
        parse_save_field(name, value);
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_html_parse_portal
 * DESCRIPTION 
 *  cmcc wlan html parse portal
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL cmcc_wlan_html_parse_portal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR c, string[256];
    U32 istr;
    U32 s, form_s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmcc_wlan_html_open())
    {
        return FALSE;
    }

    // Reset
    parse_form_free();

    istr = 0;
    s = HTML_PORTAL_S_INIT;
    form_s = HTML_PORTAL_FORM_S_INIT;
    while (1)
    {
        c = cmcc_wlan_html_next_char();
        if (c == 0)
        {
            break;
        }
        
        // Skip CRLF
        if (c == '\r' || c == '\n')
        {
            continue;
        }

        switch (s)
        {
        case HTML_PORTAL_S_INIT:
            if (c == ' ' || c == '\t')
            {
                continue;
            }

            if (c == '<')
            {
                istr = 0;
                string[0] = 0;
                s = HTML_PORTAL_S_TAG;
            }
            break;

        case HTML_PORTAL_S_TAG:
            if (c == '>')
            {
                // One full tag line found
                string[istr++] = 0;

                switch (form_s)
                {
                case HTML_PORTAL_FORM_S_INIT:
                    if (parse_form(string))
                    {
                        form_s = HTML_PORTAL_FORM_S_INPUT;
                    }
                    break;

                case HTML_PORTAL_FORM_S_INPUT:
                    if (parse_input(string))
                    {
                        if (g_cmcc_wlan_portal_cntx.action_url != NULL &&
                            (g_cmcc_wlan_portal_cntx.wlanacname!= NULL || 
                            g_cmcc_wlan_portal_cntx.wlanuserip != NULL ||
                            g_cmcc_wlan_portal_cntx.portal_url != NULL))
                        {
                            // The success break point
                            goto END;
                        }
                        else
                        {
                            // Reset parsed http data
                            parse_form_free();
                            form_s = HTML_PORTAL_FORM_S_INIT;
                            break;
                        }
                    }
                    break;
                }

                //end;
                s = HTML_PORTAL_S_INIT;
                break;
            }

            if (istr < 255)
            {
                string[istr++] = c;
            }
            break;

        default:
            break;
        }
    }

END:
    cmcc_wlan_html_close();
    return TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_html_parse_logonsessid
 * DESCRIPTION 
 *  cmcc wlan html parse logonsessid
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL cmcc_wlan_html_parse_logonsessid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const CHAR term[] = "\r\n\t <>=?";
    CHAR *str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cmcc_wlan_html_open())
    {
        return FALSE;
    }

    str = get_next_string_from_file(term);
    while (str != NULL && str[0] != 0)
    {
        cmcc_wlan_tolower(str);
        if (strcmp(str, "logonsessid") == 0)
        {
            str = get_next_string_from_file(term);
            if (str != NULL && str[0] != 0)
            {
                parse_save_field_safe(&g_cmcc_wlan_portal_cntx.logonsessid, str);
                break;;
            }
        }

        str = get_next_string_from_file(term);
    }

    cmcc_wlan_html_close();

    if (g_cmcc_wlan_portal_cntx.logonsessid == NULL || 
        g_cmcc_wlan_portal_cntx.logonsessid[0] == 0)
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_html_parse_login
 * DESCRIPTION 
 *  cmcc wlan html parse login
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
static BOOL cmcc_wlan_html_parse_login(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmcc_wlan_html_parse_portal();

    if (g_cmcc_wlan_portal_cntx.logonsessid != NULL &&
        g_cmcc_wlan_portal_cntx.logonsessid[0] != 0)
    {
        return TRUE;
    }

    return cmcc_wlan_html_parse_logonsessid();
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_send_msg
 * DESCRIPTION 
 *  cmcc wlan http send msg
 * PARAMETERS 
 *  U16 msg_id
 *  void *local_param_ptr
 *  void *peer_buf_ptr
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_http_send_msg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WPS;
    Message.oslSapId = WPS_APP_SAP;
    Message.oslMsgId = (msg_type)msg_id;
    Message.oslDataPtr = (oslParaType*)local_param_ptr;
    Message.oslPeerBuffPtr = peer_buf_ptr;
    OslMsgSendExtQueue(&Message);
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wps_get_next_req_id
 * DESCRIPTION 
 *  
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static U16 cmcc_wps_get_next_req_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    if (g_cmcc_wlan_cntx.wps_request_id <= 8000 ||
        g_cmcc_wlan_cntx.wps_request_id >= 9000)
    {
        g_cmcc_wlan_cntx.wps_request_id = 8000;
    }

    return ++g_cmcc_wlan_cntx.wps_request_id;
}

/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_init_req
 * DESCRIPTION 
 *  cmcc wlan wps init req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_wps_init_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct *req;
    peer_buff_struct *peer_buff_ptr = NULL;
    wps_set_channel_req_var_struct set_channel_req_var;
    kal_uint16 len, pdu_length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_REQ, __LINE__);

    ASSERT(g_cmcc_wlan_cntx.s == CMCC_WLAN_S_WPS_INIT);

    req = construct_local_para(sizeof(wps_set_channel_req_struct), TD_CTRL | TD_RESET);
    req->req_id = cmcc_wps_get_next_req_id();
    req->use_default = 0;
    req->conn_type = WPS_CONN_TYPE_HTTP;
    req->net_id = cmcc_wlan_http_get_dtcnt_id();
    req->app_id = 1;
    req->timeout = CMCC_WLAN_WPS_TIMEOUT;
    req->use_proxy = 0;
    req->server_auth_username[0] = 0;
    req->server_auth_password[0] = 0;

    set_channel_req_var.static_header_len = len = strlen(CMCC_WLAN_WPS_USER_AGENT);
    set_channel_req_var.static_header = (kal_uint8*)get_ctrl_buffer((len + 1));
    sprintf((kal_char*) set_channel_req_var.static_header, CMCC_WLAN_WPS_USER_AGENT);
    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, NULL);
    if (pdu_length > 0)
    {
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var,get_pdu_ptr(peer_buff_ptr, &len));
    }
    free_ctrl_buffer(set_channel_req_var.static_header);

    CMCC_SET_WPS_MSG_HANDLER(cmcc_wlan_wps_init_rsp, MSG_ID_WPS_SET_CHANNEL_RSP);
    cmcc_wlan_http_send_msg(MSG_ID_WPS_SET_CHANNEL_REQ, req, peer_buff_ptr);
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_init_rsp
 * DESCRIPTION 
 *  cmcc wlan wps init rsp
 * PARAMETERS 
 *  void *msg
 *  S32 src
 *  void *ptr
 * RETURNS 
 *  static void 
*****************************************************************************/
static MMI_BOOL cmcc_wlan_wps_init_rsp(void *msg, S32 src, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_RSP, 0);

    if (p->req_id != g_cmcc_wlan_cntx.wps_request_id)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_RSP, -1);
        return MMI_FALSE;
    }

    if (p->result != WPS_OK)
    {
        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_WPS_ERROR);
        return MMI_TRUE;
    }

    g_wps_channel_id = p->channel_id;
    if (g_cmcc_wlan_cntx.activity == CMCC_WLAN_ACTIVITY_LOGIN)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_RSP, 1);
        g_cmcc_wlan_cntx.s = CMCC_WLAN_S_AUTH_TRY;
        cmcc_wlan_auth_fsm();
    }
    else if (g_cmcc_wlan_cntx.activity == CMCC_WLAN_ACTIVITY_LOGOUT)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_RSP, 2);
        g_cmcc_wlan_cntx.s = CMCC_WLAN_S_AUTH_LOGOUT;
        cmcc_wlan_auth_fsm();
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_RSP, -2);
        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_WPS_ERROR);
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_try_req
 * DESCRIPTION 
 *  cmcc wlan wps try req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_wps_try_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_TRY_REQ, __LINE__);

    ASSERT(g_cmcc_wlan_cntx.s == CMCC_WLAN_S_AUTH_TRY);
    parse_form_free();

#ifdef __MTK_TARGET__
    cmcc_wlan_wps_http_request(CMCC_WLAN_HTTP_TYR_URL, NULL, TRUE);
#else /* __MTK_TARGET__ */
    cmcc_wlan_wps_http_request("http://localhost:143/", NULL, TRUE);
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_reassemble_portalurl
 * DESCRIPTION 
 *  cmcc wlan reassemble portalurl
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_reassemble_portalurl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, len;
    CHAR *url;
    CHAR *acname, *userip, *acip;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_cmcc_wlan_portal_cntx.portal_url != NULL && 
        g_cmcc_wlan_portal_cntx.portal_url[0] != 0);

    url = g_cmcc_wlan_portal_cntx.portal_url;
    for (i = 0; url[i] != 0; i++)
    {
        if (url[i] == '?')
        {
            return;
        }
    }

    acname = g_cmcc_wlan_portal_cntx.wlanacname;
    if (acname == NULL)
    {
        acname = "";
    }

    userip = g_cmcc_wlan_portal_cntx.wlanuserip;
    if (userip == NULL)
    {
        userip = "";
    }

    acip = g_cmcc_wlan_portal_cntx.wlanacip;
    if (acip == NULL)
    {
        acip = "";
    }

    //
    len = strlen(g_cmcc_wlan_portal_cntx.portal_url);
    len += 1; // '?'

    len += strlen("wlanacname");
    len += 1; // '='
    len += strlen(acname);

    len += 1; // '&'
    len += strlen("wlanuserip");
    len += 1; // '='
    len += strlen(userip);

    len += 1; // '&'
    len += strlen("wlanacip");
    len += 1; // '='
    len += strlen(acip);

    if (len > 2000)
    {
        return;
    }

    url = (CHAR*)OslMalloc(len + 1);
    strcpy(url, g_cmcc_wlan_portal_cntx.portal_url);
    sprintf(url, 
        "%s?wlanacname=%s&wlanuserip=%s&wlanacip=%s", 
        g_cmcc_wlan_portal_cntx.portal_url, acname, userip, acip);

    parse_form_safe_free(&g_cmcc_wlan_portal_cntx.portal_url);
    g_cmcc_wlan_portal_cntx.portal_url = url;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_portal_req
 * DESCRIPTION 
 *  cmcc wlan wps portal req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_wps_portal_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_REQ, __LINE__);

    ASSERT(g_cmcc_wlan_cntx.s == CMCC_WLAN_S_AUTH_PORTAL);
    ASSERT(g_cmcc_wlan_portal_cntx.portal_url != NULL && 
        g_cmcc_wlan_portal_cntx.portal_url[0] != 0);

    // Re-assemble Portal URL if need, error torental
    cmcc_wlan_reassemble_portalurl();

    cmcc_wlan_wps_http_request(g_cmcc_wlan_portal_cntx.portal_url, NULL, TRUE);

    /* Clean portal URL */
    parse_form_free();
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_portal_rsp
 * DESCRIPTION 
 *  cmcc wlan wps portal rsp
 * PARAMETERS 
 *  void *msg
 *  S32 src
 *  void *ptr
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_wps_portal_rsp(wps_http_rsp_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);

    if (g_cmcc_wlan_cntx.activity != CMCC_WLAN_ACTIVITY_LOGIN)
    {
        /* Aborted */
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        return;
    }

    if (para->result != WPS_OK)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_WPS_ERROR);
        return;
    }

    if (para->status != 200)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_OK);
        return;
    }

    if (!cmcc_wlan_html_parse_portal())
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_WPS_ERROR);
        return;
    }

    if (g_cmcc_wlan_portal_cntx.wlanacname == NULL && 
        g_cmcc_wlan_portal_cntx.wlanuserip == NULL &&
        g_cmcc_wlan_portal_cntx.wlanacssid == NULL &&
        g_cmcc_wlan_portal_cntx.action_url == NULL &&
        g_cmcc_wlan_portal_cntx.portal_url == NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_OK);
        return;
    }

    if (g_cmcc_wlan_portal_cntx.action_url != NULL && 
        g_cmcc_wlan_portal_cntx.form_name != NULL &&
        strcmp(g_cmcc_wlan_portal_cntx.form_name, "loginform") == 0)
    {
        // Ready to login
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        g_cmcc_wlan_cntx.s = CMCC_WLAN_S_AUTH_LOGIN;
        cmcc_wlan_auth_fsm();
    }
    else if (g_cmcc_wlan_portal_cntx.portal_url != NULL)
    {
        // Redirect
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        g_cmcc_wlan_cntx.s = CMCC_WLAN_S_AUTH_PORTAL;
        cmcc_wlan_auth_fsm();
    }
    else
    {
        // Seems OK
        // No need to authenicate
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_OK);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_login_req
 * DESCRIPTION 
 *  cmcc wlan wps login req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_wps_login_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *post_data;
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_REQ, __LINE__);

    ASSERT(g_cmcc_wlan_cntx.s == CMCC_WLAN_S_AUTH_LOGIN);

    len = make_http_user_data(NULL, 0, TRUE);
    if (len > 1000 * 2)
    {
        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_WPS_ERROR);
        return;
    }
    post_data = (CHAR*)OslMalloc(len + 1);
    len = make_http_user_data(post_data, len, TRUE);

    cmcc_wlan_wps_http_request(g_cmcc_wlan_portal_cntx.action_url, post_data, FALSE);
    OslMfree(post_data);

    parse_form_free();
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_remake_logout_parameter
 * DESCRIPTION 
 *  cmcc wlan remake logout parameter
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_remake_logout_parameter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parse_form_safe_free(&g_cmcc_wlan_logout_data.logout_url);
    if (g_cmcc_wlan_portal_cntx.action_url != NULL)
    {
        len = strlen(g_cmcc_wlan_portal_cntx.action_url);
        g_cmcc_wlan_logout_data.logout_url = (CHAR*)OslMalloc(len + 1);
        strcpy(g_cmcc_wlan_logout_data.logout_url, g_cmcc_wlan_portal_cntx.action_url);
    }

    len = make_http_user_data(NULL, 0, FALSE);
    if (len < 1000 * 2)
    {
        parse_form_safe_free(&g_cmcc_wlan_logout_data.logout_post);

        g_cmcc_wlan_logout_data.logout_post = (CHAR*)OslMalloc(len + 1);
        len = make_http_user_data(g_cmcc_wlan_logout_data.logout_post, len, FALSE);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_login_rsp
 * DESCRIPTION 
 *  cmcc wlan wps login rsp
 * PARAMETERS 
 *  void *msg
 *  S32 src
 *  void *ptr
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_wps_login_rsp(wps_http_rsp_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, 0);

    if (g_cmcc_wlan_cntx.activity != CMCC_WLAN_ACTIVITY_LOGIN)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, -1);
        return;
    }

    if (para->result != WPS_OK)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, -2);
        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_WPS_ERROR);
        return;
    }

    if (para->status != 200)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, -3);
        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_WPS_ERROR);
        return;
    }

    if (cmcc_wlan_html_parse_login())
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, 1);
        // remake logout parameter
        cmcc_wlan_remake_logout_parameter();

        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_OK);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, -4);
        cmcc_wlan_send_callback(CMCC_WLAN_AUTH_WPS_ERROR);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_logout_req
 * DESCRIPTION 
 *  cmcc wlan wps logout req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_wps_logout_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGOUT_REQ, __LINE__);

    ASSERT(g_cmcc_wlan_cntx.s == CMCC_WLAN_S_AUTH_LOGOUT);

    cmcc_wlan_wps_http_request(g_cmcc_wlan_logout_data.logout_url,
        g_cmcc_wlan_logout_data.logout_post,
        TRUE);
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_logout_rsp
 * DESCRIPTION 
 *  cmcc wlan wps logout rsp
 * PARAMETERS 
 *  void *msg
 *  S32 src
 *  void *ptr
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_wps_logout_rsp(wps_http_rsp_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cmcc_wlan_cntx.activity != CMCC_WLAN_ACTIVITY_LOGOUT)
    {
        return;
    }

    cmcc_wlan_send_callback(CMCC_WLAN_AUTH_OK);
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_clean_req
 * DESCRIPTION 
 *  cmcc wlan wps clean req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_wps_clean_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_CLEAN_REQ, __LINE__);

    g_cmcc_wlan_cntx.s = CMCC_WLAN_S_NULL;
    cmcc_wps_get_next_req_id(); /* To resume one sequence id */
    if (g_wps_channel_id == 0xFF)
    {
        return;
    }

    req = construct_local_para(sizeof(wps_unset_channel_req_struct), TD_CTRL | TD_RESET);
    req->channel_id = g_wps_channel_id;

    CMCC_SET_WPS_MSG_HANDLER(cmcc_wlan_wps_clean_rsp, MSG_ID_WPS_UNSET_CHANNEL_RSP);
    cmcc_wlan_http_send_msg(MSG_ID_WPS_UNSET_CHANNEL_REQ, req, NULL);
    g_wps_channel_id = 0xFF;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_clean_rsp
 * DESCRIPTION 
 *  cmcc wlan wps clean rsp
 * PARAMETERS 
 *  void *msg
 *  S32 src
 *  void *ilm
 * RETURNS 
 *  static void 
*****************************************************************************/
static MMI_BOOL cmcc_wlan_wps_clean_rsp(void *msg, S32 src, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_CLEAN_RSP, __LINE__);
    // We dont care

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_http_request
 * DESCRIPTION 
 *  cmcc wlan wps http request
 * PARAMETERS 
 *  U8 *url
 *  U8 *data
 *  BOOL auto_redirect
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_wps_http_request(U8 *url, U8 *data, BOOL auto_redirect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_req_struct *http_req;
    wps_http_req_var_struct http_req_var;
    peer_buff_struct *peer_buff_ptr;
    kal_uint16 pdu_length;

    static U8 header[] = 
        "Accept-Charset: gb2312\r\n"
        "Content-Type: application/x-www-form-urlencoded\r\n"
        "Connection: Keep-Alive\r\n"
        "Accept-Encoding: gzip\r\n\r\n";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_WPS_HTTP_REQUEST, __LINE__);

    http_req = construct_local_para(sizeof(wps_http_req_struct), TD_CTRL | TD_RESET);

    http_req->channel_id = g_wps_channel_id;
    http_req->request_id = cmcc_wps_get_next_req_id();
    if (data == NULL)
    {
        http_req->method = WPS_HTTP_METHOD_GET;
    }
    else
    {
        http_req->method = WPS_HTTP_METHOD_POST;
    }
    http_req->option = WPS_HTTP_OPTION_NO_CACHE;
    if (!auto_redirect)
    {
        http_req->option |= WPS_HTTP_OPTION_DO_NOT_REDIRECT;
    }
    http_req->reply_type = WPS_DATA_TYPE_FILE_NO_PROG_IND;
    CMCC_WLAN_MAKE_FILENAME(http_req->reply_path);
    FS_Delete(http_req->reply_path);
    http_req->reply_segment_len = 0;

    http_req->post_type = WPS_DATA_TYPE_BUFFER;
    http_req->post_path[0] = '\0';
    http_req->post_total_len = (data == NULL) ? 0 : strlen((CHAR*)data);
    http_req->more_post = KAL_FALSE;

    /* Peer buffer */
    memset(&http_req_var, 0, sizeof(wps_http_req_var_struct));
    http_req_var.request_url_len = strlen((CHAR*)url);
    http_req_var.request_url = url;
    http_req_var.request_header_len = strlen((CHAR*)header);
    http_req_var.request_header = header;

    if (data == NULL)
    {
        http_req_var.post_segment_len = 0;
        http_req_var.post_segment = NULL;
    }
    else
    {
        http_req_var.post_segment_len = strlen((CHAR*)data);
        http_req_var.post_segment = data;
    }

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &http_req_var, NULL);
    peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_RESET);
    wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var, get_pdu_ptr(peer_buff_ptr, &pdu_length));

#ifdef __CMCC_WLAN_AUTH_UT__
    copy_http_req_file_ut(url, data);
#endif /* #ifdef __CMCC_WLAN_AUTH_UT__ */

    CMCC_SET_WPS_MSG_HANDLER(cmcc_wlan_wps_http_rsp, MSG_ID_WPS_HTTP_RSP);
    CMCC_SET_WPS_MSG_HANDLER(cmcc_wlan_wps_http_ind, MSG_ID_WPS_HTTP_AUTH_IND);

    cmcc_wlan_http_send_msg(MSG_ID_WPS_HTTP_REQ, http_req, peer_buff_ptr);
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_http_ind
 * DESCRIPTION 
 *  cmcc wlan wps http ind
 * PARAMETERS 
 * RETURNS 
 *  static void 
*****************************************************************************/
static MMI_BOOL cmcc_wlan_wps_http_ind(void *msg, S32 src, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_res_struct *res;
    ilm_struct *ilm = NULL;
    wps_http_auth_ind_struct *ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm = (ilm_struct*)ptr;
    ind = (wps_http_auth_ind_struct*)ilm->local_para_ptr;
    if (ind->request_id != g_cmcc_wlan_cntx.wps_request_id)
    {
        return MMI_FALSE;
    }

    res = (wps_http_auth_res_struct*) construct_local_para(sizeof(wps_http_auth_res_struct), TD_CTRL);
    res->channel_id = ind->channel_id;
    res->request_id = ind->request_id;
    res->username[0] = 0;
    res->password[0] = 0;

    cmcc_wlan_http_send_msg(MSG_ID_WPS_HTTP_AUTH_RES, res, NULL);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_wps_http_rsp
 * DESCRIPTION 
 *  cmcc wlan wps http response
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static MMI_BOOL cmcc_wlan_wps_http_rsp(void *msg, S32 src, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm = (ilm_struct*)ptr;
    wps_http_rsp_struct *para = (wps_http_rsp_struct*)ilm->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (para->request_id != g_cmcc_wlan_cntx.wps_request_id)
    {
        //Aborted request or others' request
        return MMI_FALSE;
    }

#ifdef __CMCC_WLAN_AUTH_UT__
    copy_http_rsp_file_ut();
#endif /* __CMCC_WLAN_AUTH_UT__ */

    switch (g_cmcc_wlan_cntx.s)
    {
    case CMCC_WLAN_S_AUTH_TRY:
    case CMCC_WLAN_S_AUTH_PORTAL:
        cmcc_wlan_wps_portal_rsp(para);
        break;

    case CMCC_WLAN_S_AUTH_LOGIN:
        cmcc_wlan_wps_login_rsp(para);
        break;

    case CMCC_WLAN_S_AUTH_LOGOUT:
        cmcc_wlan_wps_logout_rsp(para);
        break;

    default:
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_fsm
 * DESCRIPTION 
 *  cmcc wlan auth fsm
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_auth_fsm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_FSM, g_cmcc_wlan_cntx.s);

    switch (g_cmcc_wlan_cntx.s)
    {
    case CMCC_WLAN_S_WPS_INIT:
        cmcc_wlan_wps_init_req();
        return;

    case CMCC_WLAN_S_AUTH_TRY:
        cmcc_wlan_wps_try_req();
        return;

    case CMCC_WLAN_S_AUTH_PORTAL:
        cmcc_wlan_wps_portal_req();
        return;

    case CMCC_WLAN_S_AUTH_LOGIN:
        cmcc_wlan_wps_login_req();
        return;

    case CMCC_WLAN_S_AUTH_LOGOUT:
        cmcc_wlan_wps_logout_req();
        return;

    default:
        return;
    }
}


//////////////////////////////////////////////////////////////////////////////////////
// Exported API
/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_get_abm_id
 * DESCRIPTION 
 *  
 * PARAMETERS 
 * RETURNS 
 *  
*****************************************************************************/
U8 cmcc_wlan_http_get_abm_id(void)
{
    static U8 app_id = CBM_INVALID_APP_ID;

    if (app_id == CBM_INVALID_APP_ID)
    {
        cbm_register_app_id(&app_id);
    }

    return app_id;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_get_dtcnt_id
 * DESCRIPTION 
 *  
 * PARAMETERS 
 * RETURNS 
 *  
*****************************************************************************/
U32 cmcc_wlan_http_get_dtcnt_id(void)
{
    static U32 net_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (net_id == 0)
    {
        net_id = cbm_set_app_id(CBM_WIFI_ACCT_ID, cmcc_wlan_http_get_abm_id());

        // Turn ON SSL plain text log
#ifdef __SSL_SUPPORT__
        tls_log_plaintext(KAL_TRUE);
#endif
    }

    return net_id;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_login
 * DESCRIPTION 
 *  cmcc wlan http login
 * PARAMETERS 
 *  U32 wifi_dataacnt_id
 *  cmcc_wlan_auth_callback cb
 * RETURNS 
 *  cmcc_wlan_auth_ret_enum 
*****************************************************************************/
cmcc_wlan_auth_ret_enum cmcc_wlan_http_login(cmcc_wlan_auth_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_HTTP_LOGIN, g_cmcc_wlan_cntx.activity, g_cmcc_wlan_cntx.s);

    if (g_cmcc_wlan_cntx.activity != CMCC_WLAN_ACTIVITY_NONE)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_HTTP_LOGIN, -1, -1);
        return CMCC_WLAN_AUTH_PARA_ERROR;
    }
    ASSERT(g_cmcc_wlan_cntx.s == CMCC_WLAN_S_NULL);

    g_cmcc_wlan_cntx.activity = CMCC_WLAN_ACTIVITY_LOGIN;
    g_cmcc_wlan_cntx.callback = cb;
    g_cmcc_wlan_cntx.s = CMCC_WLAN_S_WPS_INIT;
    cmcc_wlan_auth_fsm();
    return CMCC_WLAN_AUTH_WBLOCK;
}

/* logout */

/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_logout
 * DESCRIPTION 
 *  cmcc wlan http logout
 * PARAMETERS 
 *  cmcc_wlan_auth_callback cb
 * RETURNS 
 *  cmcc_wlan_auth_ret_enum 
*****************************************************************************/
cmcc_wlan_auth_ret_enum cmcc_wlan_http_logout(cmcc_wlan_auth_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_HTTP_LOGOUT, g_cmcc_wlan_cntx.activity, g_cmcc_wlan_cntx.s);

    if (g_cmcc_wlan_cntx.activity != CMCC_WLAN_ACTIVITY_NONE)
    {
        return CMCC_WLAN_AUTH_PARA_ERROR;
    }

    ASSERT(g_cmcc_wlan_cntx.s == CMCC_WLAN_S_NULL);

    if (g_cmcc_wlan_logout_data.logout_post == NULL ||
        g_cmcc_wlan_logout_data.logout_post[0] == 0) 
    {
        return CMCC_WLAN_AUTH_OK;
    }

    g_cmcc_wlan_cntx.activity = CMCC_WLAN_ACTIVITY_LOGOUT;
    g_cmcc_wlan_cntx.callback = cb;

    g_cmcc_wlan_cntx.s = CMCC_WLAN_S_WPS_INIT;
    cmcc_wlan_auth_fsm();
    return CMCC_WLAN_AUTH_WBLOCK;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_send_callback
 * DESCRIPTION 
 *  cmcc wlan send callback
 * PARAMETERS 
 *  U32 ret
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_send_callback(cmcc_wlan_auth_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_SEND_CALLBACK, g_cmcc_wlan_cntx.activity, g_cmcc_wlan_cntx.s);

    // Unset channel if there is.
    cmcc_wlan_wps_clean_req();

    if (g_cmcc_wlan_cntx.callback != NULL)
    {
        g_cmcc_wlan_cntx.callback(ret);
        g_cmcc_wlan_cntx.callback = NULL;
    }
    g_cmcc_wlan_cntx.activity = CMCC_WLAN_ACTIVITY_NONE;
}

/* abort current pending LOGIN / LOGOUT action. 
 Do nothing if there is no pending operation */

/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_abort
 * DESCRIPTION 
 *  cmcc wlan http abort
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void cmcc_wlan_http_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_HTTP_ABORT, g_cmcc_wlan_cntx.activity, g_cmcc_wlan_cntx.s);

    // Unset channel
    g_cmcc_wlan_cntx.activity = CMCC_WLAN_ACTIVITY_NONE;
    cmcc_wlan_wps_clean_req();
}


#ifdef __CMCC_WLAN_AUTH_UT__
static WCHAR *copy_http_file_get_filename(BOOL req)
{
    WCHAR *filename;
    FS_HANDLE fh;
    U32 seq = 0;

    filename = (WCHAR*)g_cmcc_wlan_cntx.buf;

    kal_wsprintf(filename,"%c:\\cmccwlanseq.dat",(CHAR) FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM));
    fh = FS_Open(filename, FS_READ_ONLY | FS_OPEN_SHARED);
    if (fh >= 0)
    {
        FS_Read(fh, &seq, sizeof(U32), NULL);
        FS_Close(fh);
    }

    seq++;

    kal_wsprintf(filename,"%c:\\cmccwlanseq.dat",(CHAR) FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM));

    fh = FS_Open(filename, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (fh >= 0)
    {
        FS_Write(fh, &seq, sizeof(U32), NULL);
        FS_Close(fh);
    }

    kal_wsprintf(filename,"%c:\\cmccwlanhttp",(CHAR) FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM));
    FS_CreateDir(filename);

    if (req)
    {
        kal_wsprintf(filename,"%c:\\cmccwlanhttp\\http%04dreq.txt",(CHAR) FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM), seq);
    }
    else
    {
        kal_wsprintf(filename,"%c:\\cmccwlanhttp\\http%04drsp.txt",(CHAR) FS_GetDrive(FS_DRIVE_V_NORMAL, 1, FS_DRIVE_I_SYSTEM), seq);
    }
    return filename;
}

static void ut_copy_html(FS_HANDLE fhSrc, FS_HANDLE fhDst)
{
    U32 len;
    CHAR buf[CMCC_WLAN_MAX_FILE_BUF_SIZE];

    if (fhSrc < 0 || fhDst < 0)
    {
        return;
    }

    while(1)
    {
        len = 0;
        FS_Read(fhSrc, buf, CMCC_WLAN_MAX_FILE_BUF_SIZE, &len);
        if (len <= 0)
        {
            break;
        }
        FS_Write(fhDst, buf, len, NULL);
    }
}

static void copy_http_rsp_file_ut(void)
{
    WCHAR *filename;
    FS_HANDLE fhSrc, fhDst;

    filename = (WCHAR*)g_cmcc_wlan_cntx.buf;
    CMCC_WLAN_MAKE_FILENAME(filename);
    fhSrc = FS_Open(filename, FS_READ_ONLY | FS_OPEN_SHARED);

    filename = copy_http_file_get_filename(0);
    fhDst = FS_Open(filename, FS_READ_WRITE | FS_CREATE_ALWAYS);

    ut_copy_html(fhSrc, fhDst);

    FS_Close(fhDst);
    FS_Close(fhSrc);
}

static void copy_http_req_file_ut(U8 *url, U8 *post)
{
    WCHAR *filename;
    FS_HANDLE fh;

    filename = copy_http_file_get_filename(1);
    fh = FS_Open(filename, FS_READ_WRITE | FS_CREATE_ALWAYS);

    if (url != NULL && url[0] != 0)
    {
        FS_Write(fh, url, strlen((CHAR*)url), NULL);
    }

    if (post != NULL && post[0] != 0)
    {
        FS_Write(fh, "\r\n\r\n", 4, NULL);
        FS_Write(fh, post, strlen((CHAR*)post), NULL);
    }

    FS_Close(fh);
}


#endif /* __CMCC_WLAN_AUTH_UT__ */

#endif /* __MMI_OP01_WIFI__ */
