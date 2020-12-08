/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  Vapp_email_uri.cpp
 *
 * Project:
 * --------
 *  COSMOS Email URI support
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

#include "MMI_features.h"

#include "App_mine.h"
#include "App_url.h"
#include "Conversions.h"
#include "UriAgentSrvGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "UsbSrvGprot.h"

#ifdef __cplusplus
}
#endif

#include "vapp_email_main.h"
#include "vapp_email_uri.h"
#include "vapp_email_util.h"
#include "vcp_global_popup.h"
#include "vapp_usb_gprot.h"

#ifdef __MMI_URI_AGENT__

#define EMAIL_URI_MAILTO_SCHEME                         "mailto"
#define EMAIL_URI_MAILTO_TO_HEADER                      "to"
#define EMAIL_URI_MAILTO_CC_HEADER                      "cc"
#define EMAIL_URI_MAILTO_FROM_HEADER                    "from"
#define EMAIL_URI_MAILTO_SUB_HEADER                     "subject"
#define EMAIL_URI_MAILTO_BODY_HEADER                    "body"
#define EMAIL_URI_BUFFER_LENGTH                         255

typedef struct 
{
    VfxBool is_valid;
    char *param;
    char *addr_ptr;
    char *to_ptr;
    char *cc_ptr;
    char *from_ptr;
    char *subject_ptr;
    char *body_ptr;
    U16 addr_len;
    U16 to_len;
    U16 cc_len;
    U16 from_len;
    U16 subject_len;
    U16 body_len;
    srv_uriagent_appid_enum ura_appid;
    srv_uriagent_uri_request_hdlr_cb cb;
} vapp_email_uri_info_struct;

static VfxBool hasRegistered = VFX_FALSE;
static vapp_email_uri_info_struct vapp_email_uri_info;

extern void vapp_email_app_send_for_uri(
                mmi_email_app_send_param_struct *param, U32 paramFlag);

mmi_ret vapp_email_uri_post_launch(mmi_event_struct *evt)
{
     vapp_email_uri_mailto_send();
     return MMI_TRUE;
}

void vapp_email_uri_mail_cfm_proc(VfxId id, void *userData)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, 0);
        MMI_FRM_POST_EVENT(&evt, vapp_email_uri_post_launch, NULL);
        return;
    }
    vapp_email_uri_mailto_back();
}


// Check the URI string and display compose mail screen
void vapp_email_uri_mailto_handler(
        srv_uriagent_appid_enum ura_appid,
        char *url,
        char *param,
        srv_uriagent_options_enum options,
        srv_uriagent_uri_request_hdlr_cb cb)
{
    if ((url == NULL) || (param == NULL))
    {
        if (cb != NULL)
        {
            (*cb)(ura_appid,
                  SRV_URIAGENT_APPID_EMAIL,
                  SRV_URIAGENT_ERR_UNSUPPORTED);
        }
        return;
    }

#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR*)L"root"))
        {
            VcpPopupTypeEnum type;
            mmi_frm_nmgr_balloon(
	            MMI_SCENARIO_ID_DEFAULT,
	            MMI_EVENT_INFO_BALLOON,
	            MMI_NMGR_BALLOON_TYPE_INFO,
	            (WCHAR*)GetString(vapp_usb_get_error_info(0, &type)));
            if (cb != NULL)
            {
                (*cb)(ura_appid,
                      SRV_URIAGENT_APPID_EMAIL,
                      SRV_URIAGENT_ERR_UNSUPPORTED);
            }
            return;
        }
    }
#endif /* __MMI_USB_SUPPORT__ */
    
    if (!vapp_email_util_check_env())
    {
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE));
        if (cb != NULL)
        {
            (*cb)(ura_appid,
                  SRV_URIAGENT_APPID_EMAIL,
                  SRV_URIAGENT_ERR_UNSUPPORTED);
        }
        return;
    }
    
    /* avoid the continuous key press on browser */
    if (vapp_email_uri_info.param)
    {
        if (vapp_email_uri_info.cb != NULL)
        {
            (*vapp_email_uri_info.cb)(
                vapp_email_uri_info.ura_appid,
                SRV_URIAGENT_APPID_EMAIL,
                SRV_URIAGENT_ERR_PROCESSING);
        }
        return;
    }
    
    memset(&vapp_email_uri_info, 0, sizeof(vapp_email_uri_info_struct));
    vapp_email_uri_info.param =
        (char*)OslMalloc(sizeof(char) * (EMAIL_URI_BUFFER_LENGTH + 1));

    memset(
        vapp_email_uri_info.param,
        0,
        sizeof(char) * (EMAIL_URI_BUFFER_LENGTH + 1));

    memcpy(vapp_email_uri_info.param,
        param,
        EMAIL_URI_BUFFER_LENGTH * sizeof(char));

    if (!vapp_email_uri_mailto_parser())
    {       
        if (vapp_email_uri_info.param)
        {
            OslMfree(vapp_email_uri_info.param);
            vapp_email_uri_info.param = NULL;
        }
        if (cb != NULL)
        {
            (*cb)(
                ura_appid,
                SRV_URIAGENT_APPID_EMAIL,
                SRV_URIAGENT_ERR_UNSUPPORTED);
        }
        return;
    }
    
    vapp_email_uri_info.cb = cb;
    vapp_email_uri_info.ura_appid = ura_appid;
    if (vapp_email_uri_info.cb != NULL)
    {
        (*vapp_email_uri_info.cb)(
            vapp_email_uri_info.ura_appid,
            SRV_URIAGENT_APPID_EMAIL,
            SRV_URIAGENT_ERR_OK);
    }
    vapp_email_uri_info.cb = NULL;
    
    if (options == SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP)
    {
        vcp_global_popup_show_confirm_two_button_id(
            GRP_ID_ROOT, VCP_POPUP_TYPE_QUESTION, STR_EMAIL_FTO_URI_SEND_NOW,
            STR_GLOBAL_YES, STR_GLOBAL_NO, 
            VCP_POPUP_BUTTON_TYPE_RECOMMEND, VCP_POPUP_BUTTON_TYPE_CANCEL,
            vapp_email_uri_mail_cfm_proc, NULL);
    }
    else
    {
        vapp_email_uri_mailto_send();
    }
}


// Go back to the last screen and free the memory
void vapp_email_uri_mailto_back(void)
{
    if (vapp_email_uri_info.param)
    {
        OslMfree(vapp_email_uri_info.param);
        vapp_email_uri_info.param = NULL;
    }
}

// Search the string find the first match of '&' or '?'
char* vapp_email_uri_mailto_find_sector(char *data)
{
    char *finder = NULL;

    finder = data;
    while (*finder && (*finder != '&') && (*finder != '?'))
    {
        finder++;
    }
    return ((*finder) ? finder : NULL);
}

// Parse the data and save the pointer
VfxBool vapp_email_uri_mailto_parser(void)
{
    char *parser_head = NULL, *parser_tail = NULL;
    VfxBool is_valid = FALSE;
    
    parser_head = vapp_email_uri_info.param;
    if (parser_head[0] != '?')
    {   // in this IF, to handle Email address
        vapp_email_uri_info.addr_ptr = parser_head;
        parser_tail = vapp_email_uri_mailto_find_sector(parser_head);
        if (parser_tail == NULL)    // only Email address found
        {
            vapp_email_uri_info.addr_len = strlen(vapp_email_uri_info.param);
            return TRUE;
        }
        else
        {
            vapp_email_uri_info.addr_len = parser_tail - parser_head;
            parser_tail[0] = '&';
            parser_head = parser_tail + 1;
        }
        vapp_email_uri_info.is_valid = TRUE;
    }
    else
    {   // just ignore '?'
        parser_head += 1;
    }
    do 
    {
        switch (parser_head[0])
        {
            case 't':
            case 'T':
                {   // handle {to}
                    is_valid = vapp_email_uri_mailto_parse_sector(
                                &parser_head,
                                &parser_tail,
                                &vapp_email_uri_info.to_ptr,
                                EMAIL_URI_MAILTO_TO_HEADER,
                                (U16)strlen(EMAIL_URI_MAILTO_TO_HEADER),
                                &vapp_email_uri_info.to_len);
                }
                break;
            case 'c':
            case 'C':
                {   // handle {cc}
                    is_valid = vapp_email_uri_mailto_parse_sector(
                                &parser_head,
                                &parser_tail,
                                &vapp_email_uri_info.cc_ptr,
                                EMAIL_URI_MAILTO_CC_HEADER,
                                (U16)strlen(EMAIL_URI_MAILTO_CC_HEADER),
                                &vapp_email_uri_info.cc_len);
                }
                break;
            case 'f':
            case 'F':
                {   // handle {from}
                    is_valid = vapp_email_uri_mailto_parse_sector(
                                &parser_head,
                                &parser_tail,
                                &vapp_email_uri_info.from_ptr,
                                EMAIL_URI_MAILTO_FROM_HEADER,
                                (U16)strlen(EMAIL_URI_MAILTO_FROM_HEADER),
                                &vapp_email_uri_info.from_len);
                    is_valid = FALSE;
                }
                break;
            case 's':
            case 'S':
                {   // handle {subject}
                    is_valid = vapp_email_uri_mailto_parse_sector(
                                &parser_head,
                                &parser_tail,
                                &vapp_email_uri_info.subject_ptr,
                                EMAIL_URI_MAILTO_SUB_HEADER,
                                (U16)strlen(EMAIL_URI_MAILTO_SUB_HEADER),
                                &vapp_email_uri_info.subject_len);
                }
                break;
            case 'b':
            case 'B':
                {   // handle {body}, so {bcc} not supported
                    is_valid = vapp_email_uri_mailto_parse_sector(
                                &parser_head,
                                &parser_tail,
                                &vapp_email_uri_info.body_ptr,
                                EMAIL_URI_MAILTO_BODY_HEADER,
                                (U16)strlen(EMAIL_URI_MAILTO_BODY_HEADER),
                                &vapp_email_uri_info.body_len);
                }
                break;
            default:
                {
                    parser_tail =
                        vapp_email_uri_mailto_find_sector(parser_head);
                    if (parser_tail != NULL)
                    {
                        if (parser_tail[1] != '\0')
                        {
                            parser_head = parser_tail + 1;
                        }
                        else
                        {   // reach the end
                            parser_tail = NULL;
                        }
                    }
                }
                break;
        }
        if (!vapp_email_uri_info.is_valid)
        {
            vapp_email_uri_info.is_valid = is_valid;
        }
    } while(parser_tail != NULL);
    return vapp_email_uri_info.is_valid;
}

static VfxS8 vapp_email_util_tolower(char ch)
{
   if( ch >='A' && ch <= 'Z' )
      return (char)(ch + ('a' - 'A'));
   return ch;
}

static VfxS32 vapp_email_util_strnicmp(
    const char *s1,
    const char *s2,
    int maxlen)
{
    VfxS8 ch1, ch2;
    while (maxlen-- > 0)
    {
      ch1 = vapp_email_util_tolower(*s1++);
      ch2 = vapp_email_util_tolower(*s2++);
      if( ch1 > ch2 )
         return 1;
      if( ch1 < ch2 )
         return -1;
   }
   return 0;
}

// Parse the sector and save the pointer and length
VfxBool vapp_email_uri_mailto_parse_sector(
        char **parser_head,
        char **parser_tail,
        char **parser_ptr,
        char *parser,
        U16 parser_len,
        U16 *sector_len)
{
    VfxBool is_valid = FALSE;

    // this sector sting is too short..
    if ((parser_len + 1) >= (U16)strlen(*parser_head))
    {
        (*parser_tail)[0] = '\0';
        memset(*parser_head, 0, strlen(*parser_head));
        *parser_tail = NULL;
        return FALSE;
    }

    // compare with the {title}:to/subject/...
    if (vapp_email_util_strnicmp(*parser_head, parser, parser_len) == 0)
    {
        *parser_head += parser_len;
        while ((*parser_head)[0] == ' ')    // ignore the spaces
        {
            if ((*parser_head)[1] != '\0')  // it's not the end
            {
                *parser_head += 1;
            }
            else                            // reach the end
            {
                *parser_tail = NULL;
                return FALSE;
            }
        }
        if ((*parser_head)[0] == '=')       // find the {=}
        {
            *parser_head += 1;
            *parser_ptr = *parser_head;

            if ((*parser_head)[0] == '&' ||
                (*parser_head)[0] == '\0')
            {
                is_valid = FALSE;
            }
            else
            {
                is_valid = TRUE;
            }
        }
    }

    // to find the end of this sector
    *parser_tail = vapp_email_uri_mailto_find_sector(*parser_head);
    if (*parser_tail != NULL)
    {                                       // it's not the last sector
        if (is_valid)
        {
            *sector_len = *parser_tail - *parser_head;
        }
        if ((*parser_tail)[1] != '\0')      // skip the char {?}/{&}
        {
            *parser_head = *parser_tail + 1;
        }
        else                                // next sector is invalid
        {
            *parser_tail = NULL;
        }
    }
    else                                    // this is the last sector
    {
        if (is_valid)
        {
            *sector_len = strlen(*parser_head);
        }
    }
    return is_valid;
}


// Fill the data to the buffer
void vapp_email_uri_mailto_fill_data(
        mmi_email_app_send_param_struct *param,
        U32 *param_fill_flag)
{
    char *temp_ptr = NULL, *url_ptr = NULL;
    VfxBool ret = TRUE;
    U16 ucs2_str_len = 0;
    
    url_ptr = vapp_email_uri_info.param;
    vapp_email_uri_info.param =
        (char*)OslMalloc((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH);
    // above buffer used to store UCS-2 string
    memset(
        vapp_email_uri_info.param,
        0,
        (EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH);

    temp_ptr =
        (char*)OslMalloc((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH);
    // above buffer used as exchange buffer

    if (vapp_email_uri_info.addr_ptr != NULL)
    {
        if (!vapp_email_uri_mailto_convertor(
                &vapp_email_uri_info.addr_ptr,
                &vapp_email_uri_info.addr_len,
                temp_ptr,
                ((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH),
                &ucs2_str_len))
        {
            ret = FALSE;
        }
    }
    if (ret && (vapp_email_uri_info.to_ptr != NULL))
    {
        if (!vapp_email_uri_mailto_convertor(
                &vapp_email_uri_info.to_ptr,
                &vapp_email_uri_info.to_len,
                temp_ptr,
                ((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH),
                &ucs2_str_len))
        {
            ret = FALSE;
        }
    }
    if (ret && (vapp_email_uri_info.cc_ptr != NULL))
    {
        if (!vapp_email_uri_mailto_convertor(
                &vapp_email_uri_info.cc_ptr,
                &vapp_email_uri_info.cc_len,
                temp_ptr,
                ((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH),
                &ucs2_str_len))
        {
            ret = FALSE;
        }
    }
    if (ret && (vapp_email_uri_info.subject_ptr != NULL))
    {
        if (!vapp_email_uri_mailto_convertor(
                &vapp_email_uri_info.subject_ptr,
                &vapp_email_uri_info.subject_len,
                temp_ptr,
                ((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH),
                &ucs2_str_len))
        {
            ret = FALSE;
        }
    }
    if (ret && (vapp_email_uri_info.body_ptr != NULL))
    {
        if (!vapp_email_uri_mailto_convertor(
                &vapp_email_uri_info.body_ptr,
                &vapp_email_uri_info.body_len,
                temp_ptr,
                ((EMAIL_URI_BUFFER_LENGTH + 1) * ENCODING_LENGTH),
                &ucs2_str_len))
        {
            ret = FALSE;
        }
    }
    OslMfree(temp_ptr);
    OslMfree(url_ptr);  // free the original param
    if (!ret)
    {
        OslMfree(vapp_email_uri_info.param);
        vapp_email_uri_info.param = NULL;
        return;
    }
    if (vapp_email_uri_mailto_fill_addr(
            vapp_email_uri_info.addr_ptr,
            vapp_email_uri_info.addr_len,
            MMI_EMAIL_URI_TO_TYPE,
            param))
    {
        *param_fill_flag |= EMAIL_TO_FILL_FLAG;
    }
    if (vapp_email_uri_mailto_fill_addr(
            vapp_email_uri_info.to_ptr,
            vapp_email_uri_info.to_len,
            MMI_EMAIL_URI_TO_TYPE,
            param))
    {
        *param_fill_flag |= EMAIL_TO_FILL_FLAG;
    }
    if (vapp_email_uri_mailto_fill_addr(
            vapp_email_uri_info.cc_ptr,
            vapp_email_uri_info.cc_len,
            MMI_EMAIL_URI_CC_TYPE,
            param))
    {
        *param_fill_flag |= EMAIL_CC_FILL_FLAG;
    }
    if ((vapp_email_uri_info.subject_ptr != NULL) &&
        (vapp_email_uri_info.subject_len != 0))
    {
        param->subj = vapp_email_uri_info.subject_ptr;
        *param_fill_flag |= EMAIL_SUBJ_FILL_FLAG;
    }
    if ((vapp_email_uri_info.body_ptr != NULL) &&
        (vapp_email_uri_info.body_len != 0))
    {
        param->cont = vapp_email_uri_info.body_ptr;
        *param_fill_flag |= EMAIL_CONT_FILL_FLAG;
    }
}


// Convert the escape URL encoding string to UCS2
VfxBool vapp_email_uri_mailto_convertor(
        char **src_ptr,
        U16 *src_len,
        char *buf_ptr,
        S32 buf_len,
        U16 *ucs2_len)
{
    S32 mmiEncoding = 0;
    U16 out_len = 0;

    memset(buf_ptr, 0, buf_len);
    if (applib_cvt_escape_string_to_normal_string(
            *src_ptr,
            *src_len,
            buf_ptr,
            buf_len))
    {
        *src_ptr = vapp_email_uri_info.param + *ucs2_len;  // *src_ptr changed
        *src_len = strlen(buf_ptr);
    }
    else
    {
        return FALSE;
    }
    mmiEncoding = MMI_CHSET_UTF8;
    out_len = mmi_chset_convert(
                (mmi_chset_enum)mmiEncoding,
                MMI_CHSET_UCS2,
                (char*)buf_ptr,
                (char*)*src_ptr,
                (EMAIL_URI_BUFFER_LENGTH * ENCODING_LENGTH) - *ucs2_len);
    if (out_len == 0)
    {
        return FALSE;
    }
    *ucs2_len += out_len;
    return TRUE;
}


// Parse the data for multi-address filled(UCS2 encoding)
VfxBool vapp_email_uri_mailto_fill_addr(
        char *data,
        U16 data_len,
        vapp_email_uri_addr_type_enum type,
        mmi_email_app_send_param_struct *parm)
{
    S32 i = 0;
    WCHAR *temp_ptr = NULL, *comma_symb_ptr = NULL;
    VfxBool is_valid = FALSE;
    U32 *num_ptr = NULL;
    S32 addr_len = 0;

    if ((data == NULL) || (data_len == 0))
    {
        return FALSE;
    }
    if (type == MMI_EMAIL_URI_TO_TYPE)
    {
        i = 0;
        num_ptr = &(parm->to_num);
    }
    else if (type == MMI_EMAIL_URI_CC_TYPE)
    {
        i = parm->to_num;
        num_ptr = &(parm->cc_num);
    }
    else
    {
        i = parm->to_num + parm->cc_num;
        num_ptr = &(parm->bcc_num);
    }
    for (; i < MMI_EMAIL_MAX_ADDR_NUM; i++)  // to find a blank position
    {
        if (!parm->addr[i].addr_mail ||
            (mmi_wcslen((WCHAR*)parm->addr[i].addr_mail) == 0))
        {
            break;
        }
    }
    if (i == MMI_EMAIL_MAX_ADDR_NUM - 1)  // [NEED REVISE] should not {-1}
    {                                     // no blank found, return flase
        return FALSE;
    }
    temp_ptr = (WCHAR*)data;
    parm->addr[i].addr_mail = (char*)temp_ptr;
    while ((comma_symb_ptr = mmi_wcschr(temp_ptr, L',')) != NULL)
    {
        comma_symb_ptr[0] = L'\0';
        comma_symb_ptr += 1;
        while (comma_symb_ptr[0] == L' ')
        {
            comma_symb_ptr += 1;
        }
        if (comma_symb_ptr[0] == L',')
        {
            temp_ptr = comma_symb_ptr;
            continue;
        }
        if (comma_symb_ptr[0] != L'\0')
        {
            temp_ptr = comma_symb_ptr;
            addr_len = mmi_wcslen((WCHAR*)parm->addr[i].addr_mail);
            if ((addr_len != 0) &&
                (addr_len <= MMI_EMAIL_MAX_ADDR_LEN) &&
                (vapp_email_util_chk_addr_ex((WCHAR*)parm->addr[i].addr_mail)))
            {
                is_valid = TRUE;
                if ((i + 1) == MMI_EMAIL_MAX_ADDR_NUM)  // no blank position
                {
                    break;
                }
                else
                {
                    parm->addr[++i].addr_mail = (char*)temp_ptr;
                    (*num_ptr) += 1;
                }
            }
            else
            {
                parm->addr[i].addr_mail = (char*)temp_ptr;
            }
        }
        comma_symb_ptr = NULL;
    }
    if (parm->addr[i].addr_mail)
    {
        addr_len = mmi_wcslen((WCHAR*)parm->addr[i].addr_mail);
        if ((addr_len != 0) &&
            (addr_len <= MMI_EMAIL_MAX_ADDR_LEN) &&
            (vapp_email_util_chk_addr_ex((WCHAR*)parm->addr[i].addr_mail)))
        {
            is_valid = TRUE;
            (*num_ptr) += 1;
        }
        else
        {
            parm->addr[i].addr_mail = NULL;
        }
    }
    return is_valid;
}

// Display compose mail screen for URI mailto
void vapp_email_uri_mailto_send(void)
{
    mmi_email_app_send_param_struct *param = NULL;
    U32 paramFlag = EMAIL_NONE_FILL_FLAG;
    
    param = (mmi_email_app_send_param_struct*)
                OslMalloc(sizeof(mmi_email_app_send_param_struct));
    memset(param, 0, sizeof(mmi_email_app_send_param_struct));

    VfxBool errorHappened = VFX_FALSE;
    VfxResId errId = STR_GLOBAL_ERROR;
    if (vapp_email_uri_info.param == NULL)
    {
        errId = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
        errorHappened = VFX_TRUE;
    }
    else if (!vapp_email_util_check_env())
    {
        errId = STR_GLOBAL_CURRENTLY_NOT_AVAILABLE;
        errorHappened = VFX_TRUE;
    }

    if (!errorHappened)
    {
        vapp_email_uri_mailto_fill_data(param, &paramFlag);
        if (paramFlag != 0)
        {
            vapp_email_app_send_for_uri(param, paramFlag);
        }
        else
        {
            errId = STR_GLOBAL_INVALID_EMAIL_ADDRESS;
            errorHappened = VFX_TRUE;
        }
        }

    if (errorHappened)
    {
        vapp_email_alert_cfm(errId);
    }
    
    OslMfree(param);
    vapp_email_uri_mailto_post_handler();
}

// Post handler of URI mailto
void vapp_email_uri_mailto_post_handler(void)
{
    if (vapp_email_uri_info.cb != NULL)
    {
        (*vapp_email_uri_info.cb)(
            vapp_email_uri_info.ura_appid,
            SRV_URIAGENT_APPID_EMAIL,
            SRV_URIAGENT_ERR_OK);
    }
    if (vapp_email_uri_info.param)
    {
        OslMfree(vapp_email_uri_info.param);
        vapp_email_uri_info.param = NULL;
    }
    return;
}

void vapp_email_uri_register(void)
{
    if (!hasRegistered)
    {
        srv_uriagent_register_hdlr_by_scheme(
            EMAIL_URI_MAILTO_SCHEME,
            vapp_email_uri_mailto_handler,
            MMI_TRUE);
    }
}

#endif /* __MMI_URI_AGENT__ */