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
 *  vapp_dtcnt_cmcc_wlan_auth_http.cpp
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
  
#include "MMI_features.h"
#ifdef __MMI_OP01_WIFI__
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vapp_dtcnt_wlan_cmcc_auth_ui.h"
#include "vapp_dtcnt_wlan_cmcc_auth_http.h"

// For debug
//#define __CMCC_WLAN_AUTH_UT__ 

/*******************************************************************************
* Export API 
*******************************************************************************/

/*****************************************************************************
 * FUNCTION 
 *  getAbmId
 * DESCRIPTION 
 *  
 * PARAMETERS 
 * RETURNS 
 *  
*****************************************************************************/
U8 VappCmccWlanAuthHttp::getAbmId(void)
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
 *  getDtcntId
 * DESCRIPTION 
 *  
 * PARAMETERS 
 * RETURNS 
 *  
*****************************************************************************/
U32 VappCmccWlanAuthHttp::getDtcntId(void)
{
    static U32 net_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (net_id == 0)
    {
        net_id = cbm_set_app_id(CBM_WIFI_ACCT_ID, getAbmId());

        // Turn ON SSL plain text log
#ifdef __SSL_SUPPORT__
        tls_log_plaintext(KAL_TRUE);
#endif
    }

    return net_id;
}

/***************************************************************************** 
* Class VappCmccWlanAuthHttp
*****************************************************************************/
static const char* VAPP_CMCC_WLAN_HTTP_TYR_URL = "http://www.baidu.com/";
static const char* VAPP_CMCC_WLAN_WPS_USER_AGENT = "G3WLAN(MTK)\r\n";
static const char* VAPP_CMCC_WLAN_HTTP_FILENAME = "wlanhttp.html";
static U8 g_wps_channel_id = 0xFF;
vapp_cmcc_wlan_cntx_struct VappCmccWlanAuthHttp::gCmccWlanCntx = {0};
vapp_cmcc_wlan_portal_cntx_struct VappCmccWlanAuthHttp::gCmccWlanPortalCntx = {0};
vapp_cmcc_wlan_logout_data_struct VappCmccWlanAuthHttp::gCmccWlanLogoutData = {0};

/* Parse utility */

/*****************************************************************************
 * FUNCTION 
 *  *characterToupper
 * DESCRIPTION 
 *  *cmcc wlan toupper
 * PARAMETERS 
 *  char *str
 * RETURNS 
 *  static char 
*****************************************************************************/
char* VappCmccWlanAuthHttp::characterToupper(char *str)
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
 *  *characterTolower
 * DESCRIPTION 
 *  *cmcc wlan tolower
 * PARAMETERS 
 *  char *str
 * RETURNS 
 *  static char 
*****************************************************************************/
char* VappCmccWlanAuthHttp::characterTolower(char *str)
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
 *  *getNextWords
 * DESCRIPTION 
 *  *get next words
 * PARAMETERS 
 *  char **pp
 * RETURNS 
 *  static char 
*****************************************************************************/
char* VappCmccWlanAuthHttp::getNextWords(char **pp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *p = *pp;
    char *words = *pp;

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
 *  isTermiCharacter
 * DESCRIPTION 
 *  is termi character
 * PARAMETERS 
 *  char c
 *  const char *termi
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::isTermiCharacter(char c, const char *termi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(termi != NULL && termi[0] != 0);
    for (i = 0; termi[i] != 0; i++)
    {
        if (c == termi[i])
        {
            return VFX_TRUE;
        }
    }

    return VFX_FALSE;
}

/*****************************************************************************
 * FUNCTION 
 *  htmlOpen
 * DESCRIPTION 
 *  cmcc wlan html open
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::htmlOpen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR *filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VappCmccWlanAuthHttp::gCmccWlanCntx.fh >= 0)
    {
        FS_Close(VappCmccWlanAuthHttp::gCmccWlanCntx.fh);
        VappCmccWlanAuthHttp::gCmccWlanCntx.fh = -1;
    }

    filename = (WCHAR*)VappCmccWlanAuthHttp::gCmccWlanCntx.buf;
    VAPP_CMCC_WLAN_MAKE_FILENAME_HTTP(filename);
    VappCmccWlanAuthHttp::gCmccWlanCntx.fh = FS_Open(filename, FS_READ_ONLY | FS_OPEN_SHARED);

    if (VappCmccWlanAuthHttp::gCmccWlanCntx.fh < 0)
    {
        return VFX_FALSE;
    }

    /* reset read buffer */
    VappCmccWlanAuthHttp::gCmccWlanCntx.buf_off = 0;
    VappCmccWlanAuthHttp::gCmccWlanCntx.buf_len = 0;

    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  htmlRead
 * DESCRIPTION 
 *  cmcc wlan html read
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::htmlRead(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VappCmccWlanAuthHttp::gCmccWlanCntx.buf_off = 0;
    VappCmccWlanAuthHttp::gCmccWlanCntx.buf_len = 0;

    ret = FS_Read(VappCmccWlanAuthHttp::gCmccWlanCntx.fh, VappCmccWlanAuthHttp::gCmccWlanCntx.buf, VAPP_CMCC_WLAN_MAX_FILE_BUF_SIZE, &VappCmccWlanAuthHttp::gCmccWlanCntx.buf_len);
    if (ret < 0 || VappCmccWlanAuthHttp::gCmccWlanCntx.buf_len == 0)
    {
        VappCmccWlanAuthHttp::gCmccWlanCntx.buf_len = 0;
        return VFX_FALSE;
    }

    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  htmlClose
 * DESCRIPTION 
 *  cmcc wlan html close
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::htmlClose(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VappCmccWlanAuthHttp::gCmccWlanCntx.fh >= 0)
    {
        FS_Close(VappCmccWlanAuthHttp::gCmccWlanCntx.fh);
        VappCmccWlanAuthHttp::gCmccWlanCntx.fh = -1;
    }

    return VFX_TRUE;
}



/*****************************************************************************
 * FUNCTION 
 *  htmlNextChar
 * DESCRIPTION 
 *  cmcc wlan html next char
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static char 
*****************************************************************************/
char VappCmccWlanAuthHttp::htmlNextChar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char c = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VappCmccWlanAuthHttp::gCmccWlanCntx.fh < 0)
    {
        return 0;
    }

    if (VappCmccWlanAuthHttp::gCmccWlanCntx.buf_off >= VappCmccWlanAuthHttp::gCmccWlanCntx.buf_len)
    {
        // read more
        if (!htmlRead())
        {
            return 0;
        }

        if (VappCmccWlanAuthHttp::gCmccWlanCntx.buf_off >= VappCmccWlanAuthHttp::gCmccWlanCntx.buf_len)
        {
            return 0;
        }
    }

    c = VappCmccWlanAuthHttp::gCmccWlanCntx.buf[VappCmccWlanAuthHttp::gCmccWlanCntx.buf_off++];
    return c;
}





/*****************************************************************************
 * FUNCTION 
 *  *getNextStringFromFile
 * DESCRIPTION 
 *  *get next string from file
 * PARAMETERS 
 *  const char *termi
 * RETURNS 
 *  static char 
*****************************************************************************/
char* VappCmccWlanAuthHttp::getNextStringFromFile(const char *termi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i  = 0;
    char c = 0;
    char *str = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    str = VappCmccWlanAuthHttp::gCmccWlanCntx.temp_string;

    // Skip leading blank
    c = htmlNextChar();
    while(isTermiCharacter(c, termi))
    {
        c = htmlNextChar();
    }

    if (c == 0)
    {
        return NULL;
    }
    if (c == '\'')
    {
        c = htmlNextChar();
        while(c != 0 && c != '\'')
        {
            if (i + 1 < VAPP_CMCC_WLAN_MAX_STRING_LEN - 1)
            {
                str[i++] = c;
            }
            c = htmlNextChar();
        }
    }
    else if (c == '\"')
    {
        c = htmlNextChar();
        while(c != 0 && c != '\"')
        {
            if (i + 1 < VAPP_CMCC_WLAN_MAX_STRING_LEN - 1)
            {
                str[i++] = c;
            }
            c = htmlNextChar();
        }
    }
    else
    {
        while(c != 0 && !isTermiCharacter(c, termi))
        {
            if (i + 1 < VAPP_CMCC_WLAN_MAX_STRING_LEN - 1)
            {
                str[i++] = c;
            }
            c = htmlNextChar();
    	}
    }

    str[i] = 0;
    return str;
}


/*****************************************************************************
 * FUNCTION 
 *  parseFormSafeFree
 * DESCRIPTION 
 *  parse form safe free
 * PARAMETERS 
 *  char **pp
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::parseFormSafeFree(char **pp)
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
 *  parseFormFree
 * DESCRIPTION 
 *  parse form free
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::parseFormFree(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                   gCmccWlanPortalCntx                                   */
    /*----------------------------------------------------------------*/
    parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.form_name);
    parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url);
    parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url);

    parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacname);
    parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacip);
    parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanuserip);
    parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacssid);
    //parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.actiontype);
    parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.languagetype);
    parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.logonsessid);
}


/*****************************************************************************
 * FUNCTION 
 *  parseForm
 * DESCRIPTION 
 *  parse form
 * PARAMETERS 
 *  char *tag_line
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::parseForm(char *tag_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *action_url = NULL, *formname = NULL;
    char *words = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    words = getNextWords(&tag_line);
    characterToupper(words);
    if (strcmp(words, "FORM") != 0)
    {
        return VFX_FALSE;
    }

    words = getNextWords(&tag_line);
    while (words != NULL && words[0] != 0)
    {
        characterToupper(words);
        if (strcmp(words, "ACTION") == 0)
        {
            // Get action URL
            action_url = getNextWords(&tag_line);
        }
        else if (strcmp(words, "NAME") == 0)
        {
            formname = getNextWords(&tag_line);
        }
        else
        {
            // Skip it
            getNextWords(&tag_line);
        }

        words = getNextWords(&tag_line);
    }

    if (action_url != NULL)
    {
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url = (char *)OslMalloc(strlen(action_url) + 1);
        strcpy(VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url, action_url);
    }

    if (formname != NULL)
    {
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.form_name = (char *)OslMalloc(strlen(formname) + 1);
        characterTolower(words);
        strcpy(VappCmccWlanAuthHttp::gCmccWlanPortalCntx.form_name, formname);
    }

    return VFX_TRUE;
}



/*****************************************************************************
 * FUNCTION 
 *  parseSaveFieldSafe
 * DESCRIPTION 
 *  parse save field safe
 * PARAMETERS 
 *  char **pp
 *  char *value
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::parseSaveFieldSafe(char **pp, char *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(value);

    parseFormSafeFree(pp);
    *pp = (char *)OslMalloc(len + 1);
    strcpy(*pp, value);
}


/*****************************************************************************
 * FUNCTION 
 *  parseSaveField
 * DESCRIPTION 
 *  parse save field
 * PARAMETERS 
 *  char *name
 *  char *value
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::parseSaveField(char *name, char *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(name != NULL);
    ASSERT(value != NULL);

    characterTolower(name);
    if (strcmp(name, "wlanacname") == 0)
    {
        parseSaveFieldSafe(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacname, value);
    }
    else if (strcmp(name, "wlanuserip") == 0)
    {
        parseSaveFieldSafe(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanuserip, value);
    }
    else if (strcmp(name, "wlanacip") == 0)
    {
        parseSaveFieldSafe(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacip, value);
    }
    else if (strcmp(name, "wlanacssid") == 0)
    {
        parseSaveFieldSafe(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacssid, value);
    }
    else if (strcmp(name, "languagetype") == 0)
    {
        parseSaveFieldSafe(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.languagetype, value);
    }
    else if (strcmp(name, "portalurl") == 0)
    {
        parseSaveFieldSafe(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url, value);
    }
    else if (strcmp(name, "logonsessid") == 0)
    {
        parseSaveFieldSafe(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.logonsessid, value);
    }
    else
    {
        // Nothing to do
    }
}


/*****************************************************************************
 * FUNCTION 
 *  makeHttpUserData
 * DESCRIPTION 
 *  make http user data
 * PARAMETERS 
 *  char *buf
 *  U32 len
 *  BOOL login
 * RETURNS 
 *  static U32 
*****************************************************************************/
U32 VappCmccWlanAuthHttp::makeHttpUserData(char *buf, U32 len, BOOL login)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const char CMCC_LOGIN_STR_TEMPLATE[] = 
        "USER=%s&PWD=%s&wlanacname=%s&wlanuserip=%s&pwdtype=1&inputtype=0&areatype=0&actiontype=LOGIN";

    static const char CMCC_LOGOUT_STR_TEMPLATE[] = 
        "wlanuserip=%s&wlanacname=%s&logonsessid=%s&actiontype=LOGOUT";

    U32 total = 0;
    char *wlanacname = NULL, *wlanuserip = NULL, *logonsessid = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wlanacname = VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacname;
    if (wlanacname == NULL) wlanacname = "";

    wlanuserip = VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanuserip;
    if (wlanuserip == NULL) wlanuserip = "";

    logonsessid = VappCmccWlanAuthHttp::gCmccWlanPortalCntx.logonsessid;
    if (logonsessid == NULL) logonsessid = "";

    ASSERT(VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url != NULL);
    ASSERT(VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url[0] != 0);

    if (login)
    {
        total += strlen(CMCC_LOGIN_STR_TEMPLATE);
        total += strlen(getUsername());
        total += strlen(getPassword());
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
            getUsername(),
           	getPassword(),
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
 *  parseInput
 * DESCRIPTION 
 *  parse input
 * PARAMETERS 
 *  char *tag_line
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::parseInput(char *tag_line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *words = NULL;
    char *l = NULL, *r = NULL;
    char *name = NULL, *value = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    words = getNextWords(&tag_line);
    characterToupper(words);
    if (strcmp(words, "/FORM") == 0)
    {
        return VFX_TRUE;
    }

    if (strcmp(words, "INPUT") != 0)
    {
        return VFX_TRUE;
    }

    name = value = NULL;
    while (tag_line[0] != 0)
    {
        l = getNextWords(&tag_line);
        r = getNextWords(&tag_line);

        characterToupper(l);
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
        parseSaveField(name, value);
    }
    return VFX_FALSE;
}


/*****************************************************************************
 * FUNCTION 
 *  htmlParsePortal
 * DESCRIPTION 
 *  cmcc wlan html parse portal
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::htmlParsePortal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char c = 0, string[256] = {0};
    U32 istr;
    U32 s, form_s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!htmlOpen())
    {
        return VFX_FALSE;
    }

    // Reset
    parseFormFree();

    istr = 0;
    s = VAPP_HTML_PORTAL_S_INIT;
    form_s = VAPP_HTML_PORTAL_FORM_S_INIT;
    while (1)
    {
        c = htmlNextChar();
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
        case VAPP_HTML_PORTAL_S_INIT:
            if (c == ' ' || c == '\t')
            {
                continue;
            }

            if (c == '<')
            {
                istr = 0;
                string[0] = 0;
                s = VAPP_HTML_PORTAL_S_TAG;
            }
            break;

        case VAPP_HTML_PORTAL_S_TAG:
            if (c == '>')
            {
                // One full tag line found
                string[istr++] = 0;

                switch (form_s)
                {
                case VAPP_HTML_PORTAL_FORM_S_INIT:
                    if (parseForm(string))
                    {
                        form_s = VAPP_HTML_PORTAL_FORM_S_INPUT;
                    }
                    break;

                case VAPP_HTML_PORTAL_FORM_S_INPUT:
                    if (parseInput(string))
                    {
                        if (VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url != NULL &&
                            (VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacname!= NULL || 
                            VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanuserip != NULL ||
                            VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url != NULL))
                        {
                            // The success break point
                            goto END;
                        }
                        else
                        {
                            // Reset parsed http data
                            parseFormFree();
                            form_s = VAPP_HTML_PORTAL_FORM_S_INIT;
                            break;
                        }
                    }
                    break;
                }

                //end;
                s = VAPP_HTML_PORTAL_S_INIT;
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
    htmlClose();
    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  htmlParseLogonsessid
 * DESCRIPTION 
 *  cmcc wlan html parse logonsessid
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::htmlParseLogonsessid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const char term[] = "\r\n\t <>=?";
    char *str = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!htmlOpen())
    {
        return VFX_FALSE;
    }

    str = getNextStringFromFile(term);
    while (str != NULL && str[0] != 0)
    {
        characterTolower(str);
        if (strcmp(str, "logonsessid") == 0)
        {
            str = getNextStringFromFile(term);
            if (str != NULL && str[0] != 0)
            {
                parseSaveFieldSafe(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.logonsessid, str);
                break;;
            }
        }

        str = getNextStringFromFile(term);
    }

    htmlClose();

    if (VappCmccWlanAuthHttp::gCmccWlanPortalCntx.logonsessid == NULL || 
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.logonsessid[0] == 0)
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  htmlParseLogin
 * DESCRIPTION 
 *  cmcc wlan html parse login
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static BOOL 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::htmlParseLogin(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    htmlParsePortal();

    if (VappCmccWlanAuthHttp::gCmccWlanPortalCntx.logonsessid != NULL &&
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.logonsessid[0] != 0)
    {
        return VFX_TRUE;
    }

    return htmlParseLogonsessid();
}

/*****************************************************************************
 * FUNCTION 
 *  getNextReqId
 * DESCRIPTION 
 *  get next req id
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
U16 VappCmccWlanAuthHttp::getNextReqId(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    if (VappCmccWlanAuthHttp::gCmccWlanCntx.wps_request_id <= 8000 ||
        VappCmccWlanAuthHttp::gCmccWlanCntx.wps_request_id >= 9000)
    {
        VappCmccWlanAuthHttp::gCmccWlanCntx.wps_request_id = 8000;
    }

    return ++VappCmccWlanAuthHttp::gCmccWlanCntx.wps_request_id;
}

/*****************************************************************************
 * FUNCTION 
 *  remakeLogoutPara
 * DESCRIPTION 
 *  cmcc wlan remake logout parameter
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::remakeLogoutPara(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanLogoutData.logout_url);
    if (VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url != NULL)
    {
        len = strlen(VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url);
        VappCmccWlanAuthHttp::gCmccWlanLogoutData.logout_url = (char*)OslMalloc(len + 1);
        strcpy(VappCmccWlanAuthHttp::gCmccWlanLogoutData.logout_url, VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url);
    }

    len = makeHttpUserData(NULL, 0, FALSE);
    if (len < 1000 * 2)
    {
        parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanLogoutData.logout_post);

        VappCmccWlanAuthHttp::gCmccWlanLogoutData.logout_post = (char*)OslMalloc(len + 1);
        len = makeHttpUserData(VappCmccWlanAuthHttp::gCmccWlanLogoutData.logout_post, len, FALSE);
    }
}



/*****************************************************************************
 * FUNCTION 
 *  reassemblePortalUrl
 * DESCRIPTION 
 *  cmcc wlan reassemble portalurl
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::reassemblePortalUrl(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, len = 0;
    char *url = NULL;
    char *acname = NULL, *userip = NULL, *acip = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url != NULL && 
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url[0] != 0);

    url = VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url;
    for (i = 0; url[i] != 0; i++)
    {
        if (url[i] == '?')
        {
            return;
        }
    }

    acname = VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacname;
    if (acname == NULL)
    {
        acname = "";
    }

    userip = VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanuserip;
    if (userip == NULL)
    {
        userip = "";
    }

    acip = VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacip;
    if (acip == NULL)
    {
        acip = "";
    }

    //
    len = strlen(VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url);
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

    url = (char*)OslMalloc(len + 1);
#ifdef __MTK_TARGET__
    strcpy(url, VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url);
    sprintf(url, 
        "%s?wlanacname=%s&wlanuserip=%s&wlanacip=%s", 
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url, acname, userip, acip);
#else
    strcpy(url, "www.sina.com.cn");
#endif
    parseFormSafeFree(&VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url);
    VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url = url;
}

/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_login
 * DESCRIPTION 
 *  cmcc wlan http login
 * PARAMETERS 
 *  U32 wifi_dataacnt_id
 *  vapp_dtcnt_wlan_auth_http_callback cb
 * RETURNS 
 *  vapp_cmcc_wlan_auth_ret_enum 
*****************************************************************************/
vapp_cmcc_wlan_auth_ret_enum VappCmccWlanAuthHttp::httpLogin(vapp_dtcnt_wlan_auth_callback cb, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_HTTP_LOGIN, VappCmccWlanAuthHttp::gCmccWlanCntx.activity, VappCmccWlanAuthHttp::gCmccWlanCntx.s);

    if (VappCmccWlanAuthHttp::gCmccWlanCntx.activity != VAPP_CMCC_WLAN_ACTIVITY_NONE)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_HTTP_LOGIN, -1, -1);
        return VAPP_CMCC_WLAN_AUTH_PARA_ERROR;
    }
    ASSERT(VappCmccWlanAuthHttp::gCmccWlanCntx.s == VAPP_CMCC_WLAN_S_NULL);

    VappCmccWlanAuthHttp::gCmccWlanCntx.activity = VAPP_CMCC_WLAN_ACTIVITY_LOGIN;
    VappCmccWlanAuthHttp::gCmccWlanCntx.callback = cb;
    VappCmccWlanAuthHttp::gCmccWlanCntx.user_data = user_data;
    VappCmccWlanAuthHttp::gCmccWlanCntx.s = VAPP_CMCC_WLAN_S_WPS_INIT;
    authFsm();
    return VAPP_CMCC_WLAN_AUTH_WBLOCK;
}

/* logout */

/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_logout
 * DESCRIPTION 
 *  cmcc wlan http logout
 * PARAMETERS 
 *  vapp_dtcnt_wlan_auth_http_callback cb
 * RETURNS 
 *  vapp_cmcc_wlan_auth_ret_enum 
*****************************************************************************/
vapp_cmcc_wlan_auth_ret_enum VappCmccWlanAuthHttp::httpLogout(vapp_dtcnt_wlan_auth_callback cb, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_HTTP_LOGOUT, VappCmccWlanAuthHttp::gCmccWlanCntx.activity, VappCmccWlanAuthHttp::gCmccWlanCntx.s);

    if (VappCmccWlanAuthHttp::gCmccWlanCntx.activity != VAPP_CMCC_WLAN_ACTIVITY_NONE)
    {
        return VAPP_CMCC_WLAN_AUTH_PARA_ERROR;
    }

    ASSERT(VappCmccWlanAuthHttp::gCmccWlanCntx.s == VAPP_CMCC_WLAN_S_NULL);

    if (VappCmccWlanAuthHttp::gCmccWlanLogoutData.logout_post == NULL ||
        VappCmccWlanAuthHttp::gCmccWlanLogoutData.logout_post[0] == 0) 
    {
        return VAPP_CMCC_WLAN_AUTH_OK;
    }

    VappCmccWlanAuthHttp::gCmccWlanCntx.activity = VAPP_CMCC_WLAN_ACTIVITY_LOGOUT;
    VappCmccWlanAuthHttp::gCmccWlanCntx.callback = cb;
    VappCmccWlanAuthHttp::gCmccWlanCntx.user_data = user_data;
	
    VappCmccWlanAuthHttp::gCmccWlanCntx.s = VAPP_CMCC_WLAN_S_WPS_INIT;
    authFsm();
    return VAPP_CMCC_WLAN_AUTH_WBLOCK;
}

/* abort current pending LOGIN / LOGOUT action. 
 Do nothing if there is no pending operation */

/*****************************************************************************
 * FUNCTION 
 *  httpAbort
 * DESCRIPTION 
 *  cmcc wlan http abort
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void VappCmccWlanAuthHttp::httpAbort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_HTTP_ABORT, VappCmccWlanAuthHttp::gCmccWlanCntx.activity, VappCmccWlanAuthHttp::gCmccWlanCntx.s);

    // Unset channel
    VappCmccWlanAuthHttp::gCmccWlanCntx.activity = VAPP_CMCC_WLAN_ACTIVITY_NONE;
    wpsCleanReq();
}

/*****************************************************************************
 * FUNCTION 
 *  httpSendMsg
 * DESCRIPTION 
 *  cmcc wlan http send msg
 * PARAMETERS 
 *  U16 msg_id
 *  void *local_param_ptr
 *  void *peer_buf_ptr
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::httpSendMsg(U16 msg_id, void *local_param_ptr, void *peer_buf_ptr)
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
    Message.oslPeerBuffPtr = (peer_buff_struct *)peer_buf_ptr;
    OslMsgSendExtQueue(&Message);
}

/*****************************************************************************
 * FUNCTION 
 *  authFsm
 * DESCRIPTION 
 *  cmcc wlan auth fsm
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::authFsm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_FSM, VappCmccWlanAuthHttp::gCmccWlanCntx.s);

    switch (VappCmccWlanAuthHttp::gCmccWlanCntx.s)
    {
    case VAPP_CMCC_WLAN_S_WPS_INIT:
        wpsInitReq();
        return;

    case VAPP_CMCC_WLAN_S_AUTH_TRY:
        wpsTryReq();
        return;

    case VAPP_CMCC_WLAN_S_AUTH_PORTAL:
        wpsPortalReq();
        return;

    case VAPP_CMCC_WLAN_S_AUTH_LOGIN:
        wpsLoginReq();
        return;

    case VAPP_CMCC_WLAN_S_AUTH_LOGOUT:
        wpsLogoutReq();
        return;

    default:
        return;
    }
}



/*****************************************************************************
 * FUNCTION 
 *  sendCallback
 * DESCRIPTION 
 *  cmcc wlan send callback
 * PARAMETERS 
 *  U32 ret
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::sendCallback(vapp_cmcc_wlan_auth_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_SEND_CALLBACK, VappCmccWlanAuthHttp::gCmccWlanCntx.activity, VappCmccWlanAuthHttp::gCmccWlanCntx.s);

    // Unset channel if there is.
    wpsCleanReq();

    if (VappCmccWlanAuthHttp::gCmccWlanCntx.callback != NULL)
    {
        VappCmccWlanAuthHttp::gCmccWlanCntx.callback(ret);
        VappCmccWlanAuthHttp::gCmccWlanCntx.callback = NULL;
		VappCmccWlanAuthHttp::gCmccWlanCntx.user_data = NULL;
    }
    VappCmccWlanAuthHttp::gCmccWlanCntx.activity = VAPP_CMCC_WLAN_ACTIVITY_NONE;
}

/*****************************************************************************
 * FUNCTION 
 *  wpsInitReq
 * DESCRIPTION 
 *  cmcc wlan wps init req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::wpsInitReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct *req = NULL;
    peer_buff_struct *peer_buff_ptr = NULL;
    wps_set_channel_req_var_struct set_channel_req_var = {0};
    kal_uint16 len = 0, pdu_length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_REQ, __LINE__);

    ASSERT(VappCmccWlanAuthHttp::gCmccWlanCntx.s == VAPP_CMCC_WLAN_S_WPS_INIT);

    req = (wps_set_channel_req_struct *)construct_local_para(sizeof(wps_set_channel_req_struct), TD_CTRL | TD_RESET);
    req->req_id = getNextReqId();
    req->use_default = (kal_bool)0;
    req->conn_type = WPS_CONN_TYPE_HTTP;
    req->net_id = getDtcntId();
    req->app_id = 1;
    req->timeout = VAPP_CMCC_WLAN_WPS_TIMEOUT;
    req->use_proxy = (kal_bool)0;
    req->server_auth_username[0] = 0;
    req->server_auth_password[0] = 0;

    set_channel_req_var.static_header_len = len = strlen(VAPP_CMCC_WLAN_WPS_USER_AGENT);
    set_channel_req_var.static_header = (kal_uint8*)get_ctrl_buffer((len + 1));
    sprintf((kal_char*) set_channel_req_var.static_header, VAPP_CMCC_WLAN_WPS_USER_AGENT);
    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, NULL);
    if (pdu_length > 0)
    {
        peer_buff_ptr = (peer_buff_struct *)construct_peer_buff(pdu_length, 0, 0, TD_RESET);
        wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, (kal_uint8 *)get_pdu_ptr(peer_buff_ptr, &len));
    }
    free_ctrl_buffer(set_channel_req_var.static_header);

    VAPP_CMCC_SET_WPS_MSG_HANDLER(wpsInitRsp, MSG_ID_WPS_SET_CHANNEL_RSP);
    httpSendMsg(MSG_ID_WPS_SET_CHANNEL_REQ, req, peer_buff_ptr);
}

/*****************************************************************************
 * FUNCTION 
 *  wpsInitRsp
 * DESCRIPTION 
 *  cmcc wlan wps init rsp
 * PARAMETERS 
 *  void *msg
 *  S32 src
 *  void *ptr
 * RETURNS 
 *  static void 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::wpsInitRsp(void *msg, S32 src, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_rsp_struct *p = (wps_set_channel_rsp_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_RSP, 0);

    if (p->req_id != VappCmccWlanAuthHttp::gCmccWlanCntx.wps_request_id)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_RSP, -1);
        return VFX_FALSE;
    }

    if (p->result != WPS_OK)
    {
        sendCallback(VAPP_CMCC_WLAN_AUTH_WPS_ERROR);
        return VFX_TRUE;
    }

    g_wps_channel_id = p->channel_id;
    if (VappCmccWlanAuthHttp::gCmccWlanCntx.activity == VAPP_CMCC_WLAN_ACTIVITY_LOGIN)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_RSP, 1);
        VappCmccWlanAuthHttp::gCmccWlanCntx.s = VAPP_CMCC_WLAN_S_AUTH_TRY;
        authFsm();
    }
    else if (VappCmccWlanAuthHttp::gCmccWlanCntx.activity == VAPP_CMCC_WLAN_ACTIVITY_LOGOUT)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_RSP, 2);
        VappCmccWlanAuthHttp::gCmccWlanCntx.s = VAPP_CMCC_WLAN_S_AUTH_LOGOUT;
        authFsm();
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_INIT_RSP, -2);
        sendCallback(VAPP_CMCC_WLAN_AUTH_WPS_ERROR);
    }

    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  wpsTryReq
 * DESCRIPTION 
 *  cmcc wlan wps try req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::wpsTryReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_TRY_REQ, __LINE__);

    ASSERT(VappCmccWlanAuthHttp::gCmccWlanCntx.s == VAPP_CMCC_WLAN_S_AUTH_TRY);
    parseFormFree();

#ifdef __MTK_TARGET__
    wpsHttpReq(VAPP_CMCC_WLAN_HTTP_TYR_URL, NULL, TRUE);
#else /* __MTK_TARGET__ */
    wpsHttpReq("http://www.sina.com.cn/", NULL, TRUE);
#endif /* __MTK_TARGET__ */
}

/*****************************************************************************
 * FUNCTION 
 *  wpsPortalReq
 * DESCRIPTION 
 *  cmcc wlan wps portal req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::wpsPortalReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_REQ, __LINE__);

    ASSERT(VappCmccWlanAuthHttp::gCmccWlanCntx.s == VAPP_CMCC_WLAN_S_AUTH_PORTAL);
    ASSERT(VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url != NULL && 
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url[0] != 0);

    // Re-assemble Portal URL if need, error torental
    reassemblePortalUrl();

    wpsHttpReq(VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url, NULL, TRUE);

    /* Clean portal URL */
    parseFormFree();
}


/*****************************************************************************
 * FUNCTION 
 *  wpsPortalRsp
 * DESCRIPTION 
 *  cmcc wlan wps portal rsp
 * PARAMETERS 
 *  void *msg
 *  S32 src
 *  void *ptr
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::wpsPortalRsp(wps_http_rsp_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);

    if (VappCmccWlanAuthHttp::gCmccWlanCntx.activity != VAPP_CMCC_WLAN_ACTIVITY_LOGIN)
    {
        /* Aborted */
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        return;
    }

    if (para->result != WPS_OK)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        sendCallback(VAPP_CMCC_WLAN_AUTH_WPS_ERROR);
        return;
    }

    if (para->status != 200)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        sendCallback(VAPP_CMCC_WLAN_AUTH_OK);
        return;
    }

    if (!htmlParsePortal())
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        sendCallback(VAPP_CMCC_WLAN_AUTH_WPS_ERROR);
        return;
    }

    if (VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacname == NULL && 
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanuserip == NULL &&
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.wlanacssid == NULL &&
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url == NULL &&
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url == NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        sendCallback(VAPP_CMCC_WLAN_AUTH_OK);
        return;
    }

    if (VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url != NULL && 
        VappCmccWlanAuthHttp::gCmccWlanPortalCntx.form_name != NULL &&
        strcmp(VappCmccWlanAuthHttp::gCmccWlanPortalCntx.form_name, "loginform") == 0)
    {
        // Ready to login
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        VappCmccWlanAuthHttp::gCmccWlanCntx.s = VAPP_CMCC_WLAN_S_AUTH_LOGIN;
        authFsm();
    }
    else if (VappCmccWlanAuthHttp::gCmccWlanPortalCntx.portal_url != NULL)
    {
        // Redirect
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        VappCmccWlanAuthHttp::gCmccWlanCntx.s = VAPP_CMCC_WLAN_S_AUTH_PORTAL;
        authFsm();
    }
    else
    {
        // Seems OK
        // No need to authenicate
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_PORTAL_RSP, __LINE__);
        sendCallback(VAPP_CMCC_WLAN_AUTH_OK);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  wpsLoginReq
 * DESCRIPTION 
 *  cmcc wlan wps login req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::wpsLoginReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *post_data = NULL;
    U32 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_REQ, __LINE__);

    ASSERT(VappCmccWlanAuthHttp::gCmccWlanCntx.s == VAPP_CMCC_WLAN_S_AUTH_LOGIN);

    len = makeHttpUserData(NULL, 0, TRUE);
    if (len > 1000 * 2)
    {
        sendCallback(VAPP_CMCC_WLAN_AUTH_WPS_ERROR);
        return;
    }
    post_data = (char*)OslMalloc(len + 1);
    len = makeHttpUserData(post_data, len, TRUE);

    wpsHttpReq(VappCmccWlanAuthHttp::gCmccWlanPortalCntx.action_url, (U8 *)post_data, FALSE);
    OslMfree(post_data);

    parseFormFree();
}

/*****************************************************************************
 * FUNCTION 
 *  wpsLoginRsp
 * DESCRIPTION 
 *  cmcc wlan wps login rsp
 * PARAMETERS 
 *  void *msg
 *  S32 src
 *  void *ptr
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::wpsLoginRsp(wps_http_rsp_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, 0);

    if (VappCmccWlanAuthHttp::gCmccWlanCntx.activity != VAPP_CMCC_WLAN_ACTIVITY_LOGIN)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, -1);
        return;
    }

    if (para->result != WPS_OK)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, -2);
        sendCallback(VAPP_CMCC_WLAN_AUTH_WPS_ERROR);
        return;
    }

    if (para->status != 200)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, -3);
        sendCallback(VAPP_CMCC_WLAN_AUTH_WPS_ERROR);
        return;
    }

    if (htmlParseLogin())
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, 1);
        // remake logout parameter
        remakeLogoutPara();

        sendCallback(VAPP_CMCC_WLAN_AUTH_OK);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGIN_RSP, -4);
        sendCallback(VAPP_CMCC_WLAN_AUTH_WPS_ERROR);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  wpsLogoutReq
 * DESCRIPTION 
 *  cmcc wlan wps logout req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::wpsLogoutReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_LOGOUT_REQ, __LINE__);

    ASSERT(VappCmccWlanAuthHttp::gCmccWlanCntx.s == VAPP_CMCC_WLAN_S_AUTH_LOGOUT);

    wpsHttpReq(VappCmccWlanAuthHttp::gCmccWlanLogoutData.logout_url,
        (U8 *)VappCmccWlanAuthHttp::gCmccWlanLogoutData.logout_post,
        TRUE);
}

/*****************************************************************************
 * FUNCTION 
 *  wpsLogoutRsp
 * DESCRIPTION 
 *  cmcc wlan wps logout rsp
 * PARAMETERS 
 *  void *msg
 *  S32 src
 *  void *ptr
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::wpsLogoutRsp(wps_http_rsp_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (VappCmccWlanAuthHttp::gCmccWlanCntx.activity != VAPP_CMCC_WLAN_ACTIVITY_LOGOUT)
    {
        return;
    }

    sendCallback(VAPP_CMCC_WLAN_AUTH_OK);
}


/*****************************************************************************
 * FUNCTION 
 *  wpsCleanReq
 * DESCRIPTION 
 *  cmcc wlan wps clean req
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::wpsCleanReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_req_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_CLEAN_REQ, __LINE__);

    VappCmccWlanAuthHttp::gCmccWlanCntx.s = VAPP_CMCC_WLAN_S_NULL;
    getNextReqId(); /* To resume one sequence id */
    if (g_wps_channel_id == 0xFF)
    {
        return;
    }

    req = (wps_unset_channel_req_struct *)construct_local_para(sizeof(wps_unset_channel_req_struct), TD_CTRL | TD_RESET);
    req->channel_id = g_wps_channel_id;

    VAPP_CMCC_SET_WPS_MSG_HANDLER(wpsCleanRsp, MSG_ID_WPS_UNSET_CHANNEL_RSP);
    httpSendMsg(MSG_ID_WPS_UNSET_CHANNEL_REQ, req, NULL);
    g_wps_channel_id = 0xFF;
}


/*****************************************************************************
 * FUNCTION 
 *  wpsCleanRsp
 * DESCRIPTION 
 *  cmcc wlan wps clean rsp
 * PARAMETERS 
 *  void *msg
 *  S32 src
 *  void *ilm
 * RETURNS 
 *  static void 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::wpsCleanRsp(void *msg, S32 src, void *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_CLEAN_RSP, __LINE__);
    // We dont care

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION 
 *  wpsHttpReq
 * DESCRIPTION 
 *  cmcc wlan wps http request
 * PARAMETERS 
 *  U8 *url
 *  U8 *data
 *  BOOL auto_redirect
 * RETURNS 
 *  static void 
*****************************************************************************/
void VappCmccWlanAuthHttp::wpsHttpReq(const char *url, U8 *data, BOOL auto_redirect)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_req_struct *http_req = NULL;
    wps_http_req_var_struct http_req_var = {0};
    peer_buff_struct *peer_buff_ptr = NULL;
    kal_uint16 pdu_length = 0;

	static const U8 header[] = 
        "Accept-Charset: gb2312\r\n"
        "Content-Type: application/x-www-form-urlencoded\r\n"
        "Connection: Keep-Alive\r\n"
        "Accept-Encoding: gzip\r\n\r\n";
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_WLAN_CMCC_FUNC_CMCC_WLAN_WPS_HTTP_REQUEST, __LINE__);

    http_req = (wps_http_req_struct *)construct_local_para(sizeof(wps_http_req_struct), TD_CTRL | TD_RESET);

    http_req->channel_id = g_wps_channel_id;
    http_req->request_id = getNextReqId();
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
    VAPP_CMCC_WLAN_MAKE_FILENAME_HTTP(http_req->reply_path);
    FS_Delete(http_req->reply_path);
    http_req->reply_segment_len = 0;

    http_req->post_type = WPS_DATA_TYPE_BUFFER;
    http_req->post_path[0] = '\0';
    http_req->post_total_len = (data == NULL) ? 0 : strlen((char*)data);
    http_req->more_post = KAL_FALSE;

    /* Peer buffer */
    http_req_var.request_url_len = strlen((char*)url);
    http_req_var.request_url = (kal_uint8 *)url;
    http_req_var.request_header_len = strlen((char*)header);
    http_req_var.request_header = (kal_uint8 *)header;

    if (data == NULL)
    {
        http_req_var.post_segment_len = 0;
        http_req_var.post_segment = NULL;
    }
    else
    {
        http_req_var.post_segment_len = strlen((char*)data);
        http_req_var.post_segment = data;
    }

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ, &http_req_var, NULL);
    peer_buff_ptr = (peer_buff_struct *)construct_peer_buff(pdu_length, 0, 0, TD_RESET);
    wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var, (kal_uint8 *)get_pdu_ptr(peer_buff_ptr, &pdu_length));

#ifdef __CMCC_WLAN_AUTH_UT__
    copy_http_req_file_ut(url, data);
#endif /* #ifdef __CMCC_WLAN_AUTH_UT__ */

    VAPP_CMCC_SET_WPS_MSG_HANDLER(wpsHttpRsp, MSG_ID_WPS_HTTP_RSP);
    VAPP_CMCC_SET_WPS_MSG_HANDLER(wpsHttpInd, MSG_ID_WPS_HTTP_AUTH_IND);

    httpSendMsg(MSG_ID_WPS_HTTP_REQ, http_req, peer_buff_ptr);
}


/*****************************************************************************
 * FUNCTION 
 *  wpsHttpInd
 * DESCRIPTION 
 *  cmcc wlan wps http ind
 * PARAMETERS 
 * RETURNS 
 *  static void 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::wpsHttpInd(void *msg, S32 src, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_auth_res_struct *res = NULL;
    ilm_struct *ilm = NULL;
    wps_http_auth_ind_struct *ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm = (ilm_struct*)ptr;
    ind = (wps_http_auth_ind_struct*)ilm->local_para_ptr;
    if (ind->request_id != VappCmccWlanAuthHttp::gCmccWlanCntx.wps_request_id)
    {
        return VFX_FALSE;
    }

    res = (wps_http_auth_res_struct*) construct_local_para(sizeof(wps_http_auth_res_struct), TD_CTRL);
    res->channel_id = ind->channel_id;
    res->request_id = ind->request_id;
    res->username[0] = 0;
    res->password[0] = 0;

    httpSendMsg(MSG_ID_WPS_HTTP_AUTH_RES, res, NULL);
    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION 
 *  wpsHttpRsp
 * DESCRIPTION 
 *  cmcc wlan wps http response
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
VfxBool VappCmccWlanAuthHttp::wpsHttpRsp(void *msg, S32 src, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm = (ilm_struct*)ptr;
    wps_http_rsp_struct *para = (wps_http_rsp_struct*)ilm->local_para_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (para->request_id != VappCmccWlanAuthHttp::gCmccWlanCntx.wps_request_id)
    {
        //Aborted request or others' request
        return VFX_FALSE;
    }

#ifdef __CMCC_WLAN_AUTH_UT__
    copy_http_rsp_file_ut();
#endif /* __CMCC_WLAN_AUTH_UT__ */

    switch (VappCmccWlanAuthHttp::gCmccWlanCntx.s)
    {
    case VAPP_CMCC_WLAN_S_AUTH_TRY:
    case VAPP_CMCC_WLAN_S_AUTH_PORTAL:
        wpsPortalRsp(para);
        break;

    case VAPP_CMCC_WLAN_S_AUTH_LOGIN:
        wpsLoginRsp(para);
        break;

    case VAPP_CMCC_WLAN_S_AUTH_LOGOUT:
        wpsLogoutRsp(para);
        break;

    default:
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

const char* VappCmccWlanAuthHttp::getPassword()
{
    VappCmccWlanAutoAuth *autoAuthObj = (VappCmccWlanAutoAuth *)VfxObject::handleToObject((VfxObjHandle)VappCmccWlanAuthHttp::gCmccWlanCntx.user_data);
    if(autoAuthObj)
    {
    return  (char*)autoAuthObj->getFileData()->password;
    }
    return NULL;
}

const char* VappCmccWlanAuthHttp::getUsername()
{
    VappCmccWlanAutoAuth *autoAuthObj = (VappCmccWlanAutoAuth *)VfxObject::handleToObject((VfxObjHandle)VappCmccWlanAuthHttp::gCmccWlanCntx.user_data);
    if(autoAuthObj)
    {
        return  (char*)autoAuthObj->getFileData()->username;
    }
    return NULL;
}

#ifdef __CMCC_WLAN_AUTH_UT__
WCHAR* VappCmccWlanAuthHttp::copy_http_file_get_filename(BOOL req)
{
    WCHAR *filename;
    FS_HANDLE fh;
    U32 seq = 0;

    filename = (WCHAR*)VappCmccWlanAuthHttp::gCmccWlanCntx.buf;

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

void VappCmccWlanAuthHttp::ut_copy_html(FS_HANDLE fhSrc, FS_HANDLE fhDst)
{
    U32 len;
    char buf[VAPP_CMCC_WLAN_MAX_FILE_BUF_SIZE];

    if (fhSrc < 0 || fhDst < 0)
    {
        return;
    }

    while(1)
    {
        len = 0;
        FS_Read(fhSrc, buf, VAPP_CMCC_WLAN_MAX_FILE_BUF_SIZE, &len);
        if (len <= 0)
        {
            break;
        }
        FS_Write(fhDst, buf, len, NULL);
    }
}

void VappCmccWlanAuthHttp::copy_http_rsp_file_ut(void)
{
    WCHAR *filename;
    FS_HANDLE fhSrc, fhDst;

    filename = (WCHAR*)VappCmccWlanAuthHttp::gCmccWlanCntx.buf;
    VAPP_CMCC_WLAN_MAKE_FILENAME_HTTP(filename);
    fhSrc = FS_Open(filename, FS_READ_ONLY | FS_OPEN_SHARED);

    filename = copy_http_file_get_filename(0);
    fhDst = FS_Open(filename, FS_READ_WRITE | FS_CREATE_ALWAYS);

    ut_copy_html(fhSrc, fhDst);

    FS_Close(fhDst);
    FS_Close(fhSrc);
}

void VappCmccWlanAuthHttp::copy_http_req_file_ut(U8 *url, U8 *post)
{
    WCHAR *filename;
    FS_HANDLE fh;

    filename = copy_http_file_get_filename(1);
    fh = FS_Open(filename, FS_READ_WRITE | FS_CREATE_ALWAYS);

    if (url != NULL && url[0] != 0)
    {
        FS_Write(fh, url, strlen((char*)url), NULL);
    }

    if (post != NULL && post[0] != 0)
    {
        FS_Write(fh, "\r\n\r\n", 4, NULL);
        FS_Write(fh, post, strlen((char*)post), NULL);
    }

    FS_Close(fh);
}


#endif /* __CMCC_WLAN_AUTH_UT__ */

#endif /* __MMI_OP01_WIFI__ */
