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
 * SsoCui.c
 *
 * Project:
 * --------
 *	 MAUI
 *
 * Description:
 * ------------
 *	This file is intends for SsoCui log in
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
 * removed!
 * removed!
 * removed!

*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#include "MMI_features.h"

#if defined (__MMI_SSO__) || defined (__SOCIAL_NETWORK_SUPPORT__)

#include "MMIDataType.h"
#include "gui_typedef.h"
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "GlobalResDef.h"
#include "wgui_categories_search.h"
#include "GlobalDefs.h"
#include "CommonScreensResDef.h"/* EVT_ID_ALERT_QUIT */
#include "ProfilesSrvGprot.h" /* SUCCESS_TONE */
#include "CommonScreens.h"    /* DisplayPopup */
#include "MenuCuiGprot.h"     /* cui_menu_event_struct */
#include "wgui_categories_popup.h" /* UI_POPUP_NOTIFYDURATION_TIME */
#include "InlineCuiGprot.h"   /* CUI_INLINE_INSERT_TAIL */
#include "Wgui_categories_util.h"/* register left and right key */

#include "mmi_rp_app_sso_def.h" /* sso app gen about yahoo service */
#include "PhbSrvGprot.h" /* phb contacts srv */
#include "SmsSrvGprot.h" /* sms srv */
#include "SsoCuiGprot.h" /* ssocui */
#include "SsoSrvGprot.h" /* sso service interface */

#include "CloudSrvGprot.h" /*cloud service*/
#include "mmi_rp_cui_sso_def.h" /* ssocui res */

/* #include "Browser_struct.h" */
#include "Browser_api.h" /* open the http */
#include "MMI_common_app_trc.h"

#ifdef __MMI_SSO__
#include "mmi_rp_srv_sso_def.h"
#endif

#ifdef __SOCIAL_NETWORK_SUPPORT__
#include "snssrvgprot.h" /*sns service*/
#include "mmi_rp_srv_sns_def.h"
#endif

#include "SnsSrvGprot.h"
#define SSO_ID_LEN 64
#define SSO_PW_LEN 64
#define SSO_INLINE_ITEM_NO 8

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
#define sso_accounts_no 64

/* sso log in screen id,password,login, sign up */
typedef enum 
{
    SSO_LOGIN_ID_CAPTION = CUI_INLINE_ITEM_ID_BASE + 1,
    SSO_LOGIN_ID_CONTEXT,
    SSO_LOGIN_PW_CAPTION,
    SSO_LOGIN_PW_CONTEXT,
    SSO_LOGIN_BLANK_CAPTION_F,
    SSO_LOGIN_LOGIN,
    SSO_LOGIN_BLANK_CAPTION_S,
    SSO_LOGIN_SIGNUP,
    SSO_LOGIN_TOTAL
} cui_sso_login_enum;

static const cui_inline_item_caption_struct sso_id_caption = {STR_ID_CUI_SSO_ID};
static const cui_inline_item_text_edit_struct sso_id_edit =
{
    0,
    0,
    SSO_ID_LEN,
    IMM_INPUT_TYPE_EMAIL,
    0,
    NULL
};
static const cui_inline_item_caption_struct sso_pw_caption = {STR_ID_CUI_SSO_PW};
static const cui_inline_item_text_edit_struct sso_pw_edit =
{
    0,
    0,
    SSO_PW_LEN,
    IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD,
    0,
    NULL
};
static const cui_inline_item_caption_struct sso_blank_caption_f = {STR_ID_CUI_SSO_LOGIN_BLANK};
/* static const cui_inline_item_display_only_struct sso_login_donly = {STR_ID_CUI_SSO_LOGIN, 0};*/
/* button */
static const cui_inline_item_button_struct sso_login_bt = {STR_ID_CUI_SSO_LOGIN};
static const cui_inline_item_caption_struct sso_blank_caption_s = {STR_ID_CUI_SSO_LOGIN_BLANK};
/*static const cui_inline_item_display_only_struct sso_signup_donly = {STR_ID_CUI_SSO_SIGNUP, 0};*/
/* button */
static const cui_inline_item_button_struct sso_signup_bt = {STR_ID_CUI_SSO_SIGNUP};

const cui_inline_item_softkey_struct g_sso_login_inline_softkey = 
{
    {{CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}, {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0}, {0, CUI_INLINE_SOFTKEY_DEFAULT_VALUE}}
};

static const cui_inline_set_item_struct g_sso_login_inline_item[] = 
{
    {SSO_LOGIN_ID_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&sso_id_caption},    
    {SSO_LOGIN_ID_CONTEXT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&sso_id_edit},    
    {SSO_LOGIN_PW_CAPTION, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&sso_pw_caption},
    {SSO_LOGIN_PW_CONTEXT, CUI_INLINE_ITEM_TYPE_TEXT_EDIT, 0, (void*)&sso_pw_edit},  
    {SSO_LOGIN_BLANK_CAPTION_F, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&sso_blank_caption_f},    
    /* {SSO_LOGIN_LOGIN, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void*)&sso_login_donly},    */
    {SSO_LOGIN_LOGIN, CUI_INLINE_ITEM_TYPE_BUTTON, 0, (void*)&sso_login_bt},
    {SSO_LOGIN_BLANK_CAPTION_S, CUI_INLINE_ITEM_TYPE_CAPTION, 0, (void*)&sso_blank_caption_s},    
    /* {SSO_LOGIN_SIGNUP, CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY, 0, (void*)&sso_signup_donly} */
    {SSO_LOGIN_SIGNUP, CUI_INLINE_ITEM_TYPE_BUTTON, 0, (void*)&sso_signup_bt}
};
const cui_inline_struct g_sso_login_inline_struct =
{
     SSO_INLINE_ITEM_NO,
     STR_ID_MMI_SSO_YAHOO_SERVICE,
     0,
     CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE,
     NULL,/*&g_sso_login_inline_softkey,*/
     g_sso_login_inline_item
}; 

typedef struct
{
    MMI_ID parent_gid;
    MMI_ID cui_gid;
    mmi_id inline_gid;
    srv_sns_account_struct *account;
    MMI_BOOL sns_flag;
    mmi_id sns_pop_gid;
} ssocui_sns_infor_struct;
ssocui_sns_infor_struct g_ssocui_sns_infor_struct;

mmi_id g_ssocui_gid;
mmi_id g_ssocui_parent_gid; 
mmi_id g_ssocui_inline_gid;
static WCHAR g_ssocui_pname[SSO_ID_LEN + 1];
static WCHAR g_ssocui_id[SSO_ID_LEN + 1];
static WCHAR g_ssocui_pw[SSO_PW_LEN + 1];

U32 g_ssocui_provider;
U8 g_ssocui_account_id;
mmi_id g_ssocui_pop_gid;
mmi_ret cui_sso_login_gpro(mmi_event_struct *evt);

#ifdef __MMI_SSO__
void cui_sso_login_account_cb(S32 req_id, srv_sso_result result, U32 provider, U8 account_id, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_post_evt
 * DESCRIPTION
 *  post the event, base the event_enum, fill the event struct
 * PARAMETERS
 *  event_enum  [IN] cui_sso_login_result_event_enum 
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sso_login_post_evt(cui_sso_login_result_event_enum event_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static cui_sso_login_done_event_struct sso_evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sso_evt.evt_id = EVT_ID_CUI_SSO_LOGIN_DONE;
    sso_evt.result = event_enum;
	sso_evt.size = sizeof(cui_sso_login_done_event_struct);
	sso_evt.user_data = NULL;
	sso_evt.sender_id = g_ssocui_gid;
    sso_evt.provider = g_ssocui_provider;
    sso_evt.account_id = g_ssocui_account_id;
	mmi_frm_group_post_to_parent(sso_evt.sender_id, (mmi_group_event_struct*)&sso_evt);
    MMI_TRACE(
        MMI_INET_TRC_G7_SSO, 
        CUI_SSO_LOGIN_POST_EVT, 
        sso_evt.evt_id, 
        sso_evt.result,
        sso_evt.size, 
        sso_evt.user_data, 
        sso_evt.sender_id, 
        sso_evt.provider,
        sso_evt.account_id); 
}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_delete_account_cb
 * DESCRIPTION
 *  log in spec id, the callback
 * PARAMETERS
 *  result [IN] srv_sso_result 
 *  provider [IN] U32 
 *  account_id [IN] U8  
 *  user_data [IN] void *
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sso_delete_account_cb(S32 req_id, srv_sso_result result, void *userdata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_SSO_OK == result)
    {
        MMI_TRACE(MMI_INET_TRC_G7_SSO, CUI_SSO_DELETE_ACCOUNT_CB_SUCESS); 
        srv_sso_add_account(g_ssocui_provider, g_ssocui_id, g_ssocui_pw, cui_sso_login_account_cb, NULL);  
        return;
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G7_SSO, CUI_SSO_DELETE_ACCOUNT_CB_FAILED); 
        string_id = srv_sso_get_error_string(result);
        mmi_popup_display_ext(string_id, MMI_EVENT_FAILURE, NULL); 
        cui_sso_login_post_evt(EVT_ID_CUI_SSO_LOGIN_FAILED);
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_account_cb
 * DESCRIPTION
 *  log in spec id, the callback
 * PARAMETERS
 *  result [IN] srv_sso_result 
 *  provider [IN] U32 
 *  account_id [IN] U8  
 *  user_data [IN] void *
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sso_login_account_cb(S32 req_id, srv_sso_result result, U32 provider, U8 account_id, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_STR_ID string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alert_dismiss(g_ssocui_pop_gid);
    if (SRV_SSO_OK == result)
    {
        mmi_popup_display_ext(STR_ID_CUI_SSO_LOGIN_OK, MMI_EVENT_SUCCESS, NULL);
        cui_sso_login_post_evt(EVT_ID_CUI_SSO_LOGIN_OK);
    }
    else
    {
        string_id = srv_sso_get_error_string(result);
        mmi_popup_display_ext(string_id, MMI_EVENT_FAILURE, NULL); 
        cui_sso_login_post_evt(EVT_ID_CUI_SSO_LOGIN_FAILED);
    }
    MMI_TRACE(MMI_INET_TRC_G7_SSO, CUI_SSO_LOGIN_ACCOUNT_CB, result, provider, account_id, user_data); 
}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_signup
 * DESCRIPTION
 *  entry the sigu up http
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sso_login_signup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    WCHAR url[SRV_SSO_URL_SIZE] = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!srv_sso_get_provider_signup_url(g_ssocui_provider, url))
	{
		mmi_popup_display_ext(srv_sso_get_error_string(srv_sso_get_ready()), MMI_EVENT_INFO, NULL);
        return;
	}
#ifdef BROWSER_SUPPORT
	wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)url);
#endif
}


static mmi_ret cui_sso_login_popup_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *event = (mmi_alert_result_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->result == MMI_ALERT_CNFM_CANCEL)
    {
        /*nothing to do */
        S32 req_id = *(S32 *)event->user_tag;
        srv_sso_cancel(req_id);
    }

    if (event->evt_id == EVT_ID_ALERT_QUIT)
    {
        if (event->result == MMI_POPUP_NORMAL_EXIT || event->result == MMI_POPUP_INTERRUPT_EXIT)
        {
            /*nothing to do */
			if (event->user_tag)
			{
			    OslMfree(event->user_tag);
				event->user_tag = NULL;
			}
        }
    }
    MMI_TRACE(MMI_INET_TRC_G7_SSO, CUI_SSO_LOGIN_POPUP_CB, event->evt_id, event->result); 
    return MMI_RET_OK;
}
#endif

#ifdef __SOCIAL_NETWORK_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_post_evt_sns
 * DESCRIPTION
 *  post the event, base the event_enum, fill the event struct
 * PARAMETERS
 *  event_enum  [IN] cui_sso_login_result_event_enum 
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sso_login_post_evt_sns(cui_sso_login_result_event_enum event_enum)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_sso_login_done_sns_event_struct sso_evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sso_evt.evt_id = EVT_ID_CUI_SSO_LOGIN_DONE_SNS;
    sso_evt.result = event_enum;
	sso_evt.size = sizeof(cui_sso_login_done_sns_event_struct);
	sso_evt.user_data = NULL;
    sso_evt.sender_id = g_ssocui_sns_infor_struct.cui_gid;
    sso_evt.account = g_ssocui_sns_infor_struct.account;
	mmi_frm_group_post_to_parent(sso_evt.sender_id, (mmi_group_event_struct*)&sso_evt);	
}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_account_sns_cb
 * DESCRIPTION
 *  log in spec sns id, the callback
 * PARAMETERS
 *  param [IN] mmi_event_struct * 
 * RETURNS
 *****************************************************************************/
static mmi_ret cui_sso_login_account_sns_cb(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_result_struct *result = (srv_sns_evt_result_struct *)param;
    MMI_STR_ID string_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_alert_dismiss(g_ssocui_sns_infor_struct.sns_pop_gid);
    if (result->result != SRV_SNS_OK)
    {
        string_id = srv_sns_get_error_string(result->result);
        mmi_popup_display_ext(string_id, MMI_EVENT_FAILURE, NULL); 
        cui_sso_login_post_evt_sns(EVT_ID_CUI_SSO_LOGIN_FAILED);
    }
    else
    {
        cui_sso_login_post_evt_sns(EVT_ID_CUI_SSO_LOGIN_OK);
    }

    return MMI_RET_OK;
}


static mmi_ret cui_sso_sns_login_popup_cb(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *event = (mmi_alert_result_evt_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (event->result == MMI_ALERT_CNFM_CANCEL)
    {
        S32 req_id = *(S32 *)event->user_tag;
        srv_sns_cancel(req_id);
    }

    if (event->evt_id == EVT_ID_ALERT_QUIT)
    {
        if (event->result == MMI_POPUP_NORMAL_EXIT || event->result == MMI_POPUP_INTERRUPT_EXIT)
        {
			if (event->user_tag)
			{
				OslMfree(event->user_tag);
				event->user_tag = NULL;
			}
        }
    }

    return MMI_RET_OK;
}


static mmi_ret cui_sso_sns_not_ready_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sns_evt_ready_struct *ready = (srv_sns_evt_ready_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ready->is_ready)
    {
        if (mmi_frm_group_is_present(g_ssocui_sns_infor_struct.cui_gid))
        {
            mmi_frm_group_close(g_ssocui_sns_infor_struct.cui_gid);
        }  
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_create_run_sns
 * DESCRIPTION
 *  This function is used to create and run sns login cui.
 * PARAMETERS
 * parent_gid [IN]   MI_ID  cui parent gid
 * provoider  [IN]   srv_sns_account_struct *account
 * RETURNS
 *  return login cui group id
 *****************************************************************************/
extern MMI_ID cui_sso_login_create_run_sns(MMI_ID parent_gid, srv_sns_account_struct *account)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!srv_sns_is_ready())
	{
		kal_prompt_trace(MOD_MMI_COMMON_APP,"cui_sso_login_create_run_sns sns is not ready");
		return GRP_ID_INVALID;
	}
	mmi_frm_cb_reg_event(EVT_ID_SRV_SNS_READY, cui_sso_sns_not_ready_proc, NULL);
    memset(&g_ssocui_sns_infor_struct, 0, sizeof(ssocui_sns_infor_struct));
    g_ssocui_sns_infor_struct.parent_gid = parent_gid;
    g_ssocui_sns_infor_struct.sns_flag = MMI_TRUE;
    g_ssocui_sns_infor_struct.account = account;
    g_ssocui_sns_infor_struct.cui_gid = mmi_frm_group_create_ex(
        parent_gid, 
        GRP_ID_AUTO_GEN, 
        cui_sso_login_gpro, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    g_ssocui_sns_infor_struct.inline_gid = cui_inline_create(
		g_ssocui_sns_infor_struct.cui_gid, 
		&g_sso_login_inline_struct);
    /* to get provider name */
    cui_inline_set_title_string(g_ssocui_sns_infor_struct.inline_gid, account->name);
    /* to get account name */
    cui_inline_set_value(g_ssocui_sns_infor_struct.inline_gid, SSO_LOGIN_ID_CONTEXT, account->login_id);    
	if (account->login_id != NULL)
	{
		cui_inline_set_highlight_item(g_ssocui_sns_infor_struct.inline_gid, SSO_LOGIN_PW_CONTEXT);
	}	

	cui_inline_run(g_ssocui_sns_infor_struct.inline_gid);
    return g_ssocui_sns_infor_struct.cui_gid; 
}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_sns_close
 * DESCRIPTION
 *  This function is used to close SSO login cui of sns.
 * PARAMETERS
 *  gid          [in]    login cui group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sso_login_sns_close(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(gid);
}
#endif /*__SOCIAL_NETWORK_SUPPORT__*/


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_login
 * DESCRIPTION
 *  log in the account, and send the event
 * PARAMETERS
 *  menu_evt    : [IN] mmi_event_struct
 *  enum_type     [IN] cui_sso_login_event_enum
 * RETURNS
 *  mmi_ret
 * RETURN VALUES
 *  void
 *****************************************************************************/
static void cui_sso_login_login(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct arg;
    srv_sso_account_struct buffer;
    WCHAR account_name[SSO_ID_LEN + 1];
    srv_sso_account_struct temp_buffer[sso_accounts_no];
    U8 real_no;
    U8 i;
    S32 *popup_ud;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_ssocui_id, 0x00, sizeof(g_ssocui_id));
    memset(g_ssocui_pw, 0x00, sizeof(g_ssocui_pw));

    if (g_ssocui_sns_infor_struct.sns_flag == MMI_TRUE)/*sns accounts*/
    {
        cui_inline_get_value(g_ssocui_sns_infor_struct.inline_gid, SSO_LOGIN_ID_CONTEXT, g_ssocui_id);
        cui_inline_get_value(g_ssocui_sns_infor_struct.inline_gid, SSO_LOGIN_PW_CONTEXT, g_ssocui_pw);
    }
    else
    {
        cui_inline_get_value(g_ssocui_inline_gid, SSO_LOGIN_ID_CONTEXT, g_ssocui_id);
        cui_inline_get_value(g_ssocui_inline_gid, SSO_LOGIN_PW_CONTEXT, g_ssocui_pw);
    }

    if ((mmi_wcslen(g_ssocui_id) == 0) || (mmi_wcslen(g_ssocui_pw) == 0))
    {
        mmi_popup_display_simple_ext(STR_GLOBAL_EMPTY, MMI_EVENT_WARNING, g_ssocui_gid, NULL);
        return;
    }

    MMI_TRACE(
        MMI_INET_TRC_G7_SSO, 
        CUI_SSO_LOGIN_LOGIN, 
        g_ssocui_provider, 
        g_ssocui_id,
        g_ssocui_pw); 
    
    /* process */
    ClearAllKeyHandler();
	mmi_confirm_property_init(&arg, CNFM_TYPE_CANCEL);
    arg.f_enter_history = 1;

	
    if (g_ssocui_sns_infor_struct.sns_flag == MMI_TRUE)/*sns accounts*/
    {
    #ifdef __SOCIAL_NETWORK_SUPPORT__
        /* to get provider name */
        arg.parent_id = g_ssocui_sns_infor_struct.cui_gid;
        arg.callback = cui_sso_sns_login_popup_cb;
        popup_ud = (S32 *)OslMalloc(sizeof(S32 *));
        arg.user_tag = popup_ud;
        g_ssocui_sns_infor_struct.sns_pop_gid = mmi_confirm_display_ext(STR_ID_CUI_SSO_LOGINGIN, MMI_EVENT_PROGRESS, &arg);
        *popup_ud = srv_sns_login(g_ssocui_sns_infor_struct.account->provider, g_ssocui_id, g_ssocui_pw, cui_sso_login_account_sns_cb, NULL);
        if (*popup_ud < 0)
        {
            mmi_alert_dismiss(g_ssocui_pop_gid);
        }
	#endif 
    }
    else /* cloud accounts*/
    {
    #ifdef __MMI_SSO__
        arg.parent_id = g_ssocui_gid;
        arg.callback = cui_sso_login_popup_cb;
        
        /*judge the login or new add  the account exists*/
        if (srv_sso_get_account(g_ssocui_provider, g_ssocui_account_id, &buffer))
        {
            srv_sso_get_account_name(g_ssocui_provider, g_ssocui_account_id, account_name);
            if (0 == mmi_wcscmp(account_name, g_ssocui_id))
            {
                popup_ud = (S32 *)OslMalloc(sizeof(S32 *));
                arg.user_tag = popup_ud;
                g_ssocui_pop_gid = mmi_confirm_display_ext(STR_ID_CUI_SSO_LOGINGIN, MMI_EVENT_PROGRESS, &arg);
                *popup_ud = srv_sso_login_account(g_ssocui_provider, g_ssocui_account_id, g_ssocui_pw, cui_sso_login_account_cb, NULL);
                if (*popup_ud < 0)
                {
                    mmi_alert_dismiss(g_ssocui_pop_gid);
                }
            }
            else
            {
                popup_ud = (S32 *)OslMalloc(sizeof(S32 *));
                arg.user_tag = popup_ud;
                g_ssocui_pop_gid = mmi_confirm_display_ext(STR_ID_CUI_SSO_LOGINGIN, MMI_EVENT_PROGRESS, &arg);
                *popup_ud = srv_sso_del_account(g_ssocui_provider, g_ssocui_account_id, cui_sso_delete_account_cb, NULL);
                if (*popup_ud < 0)
                {
                    mmi_alert_dismiss(g_ssocui_pop_gid);
                }
            }
        }
        else
        {
            real_no = srv_sso_get_accounts(g_ssocui_provider, SRV_SSO_LOGIN_DONT_CARE, temp_buffer, sso_accounts_no);
            for (i = 0; i < real_no; i++)
            {
                srv_sso_get_account_name(temp_buffer[i].provider, temp_buffer[i].account, account_name);
                if (0 == mmi_wcscmp(account_name, g_ssocui_id))
                {
                    popup_ud = (S32 *)OslMalloc(sizeof(S32 *));
                    arg.user_tag = popup_ud;
                    g_ssocui_pop_gid = mmi_confirm_display_ext(STR_ID_CUI_SSO_LOGINGIN, MMI_EVENT_PROGRESS, &arg);
                    *popup_ud = srv_sso_login_account(g_ssocui_provider, temp_buffer[i].account, g_ssocui_pw, cui_sso_login_account_cb, NULL);
                    if (*popup_ud < 0)
                    {
                        mmi_alert_dismiss(g_ssocui_pop_gid);
                    }
                    return;
                }
            }

            popup_ud = (S32 *)OslMalloc(sizeof(S32 *));
            arg.user_tag = popup_ud;
            g_ssocui_pop_gid = mmi_confirm_display_ext(STR_ID_CUI_SSO_LOGINGIN, MMI_EVENT_PROGRESS, &arg);
            srv_sso_add_account(g_ssocui_provider, g_ssocui_id, g_ssocui_pw, cui_sso_login_account_cb, NULL);
            if (*popup_ud < 0)
            {
                mmi_alert_dismiss(g_ssocui_pop_gid);
            }
        }
	#endif
    }  

}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_option
 * DESCRIPTION
 * The option of login
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 * RETURN VALUES
 *  MMI_RET_OK
 *****************************************************************************/
static void cui_sso_login_option(cui_event_inline_submit_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id opt_nenu_gid;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_ssocui_id, 0x00, sizeof(g_ssocui_id));
    memset(g_ssocui_pw, 0x00, sizeof(g_ssocui_pw));

    cui_inline_get_value(evt->sender_id, SSO_LOGIN_ID_CONTEXT, g_ssocui_id);
    cui_inline_get_value(evt->sender_id, SSO_LOGIN_PW_CONTEXT, g_ssocui_pw);
    
    opt_nenu_gid = cui_menu_create_and_run(
        g_ssocui_sns_infor_struct.sns_flag ? g_ssocui_sns_infor_struct.cui_gid : g_ssocui_gid,
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_OPTION,
        MENU_ID_SSOCUI_LOGIN_OPT,
        MMI_FALSE, /* Use global resource */
        NULL);
    MMI_TRACE( MMI_INET_TRC_G7_SSO, CUI_SSO_LOGIN_OPTION, g_ssocui_id, g_ssocui_pw);
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_tap_callback
 * DESCRIPTION
 *  Set intuitive command function for login
 * PARAMETERS
 *  tap_type: [IN]   The current tap menu status highlight or not
 *  index   : [IN]   The tap menu index
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_sso_login_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    MMI_TRACE(MMI_INET_TRC_G7_SSO, CUI_SSO_LOGIN_TAP_CB, tap_type, index);
    {
            if (index == (SSO_LOGIN_LOGIN - SSO_LOGIN_ID_CAPTION))/* log in */
            {
                cui_sso_login_login();
            }
            if (index == (SSO_LOGIN_SIGNUP - SSO_LOGIN_ID_CAPTION)) /* sign up */
            {
            #ifdef __MMI_SSO__
                cui_sso_login_signup();
			#endif
            }
    }
}
#endif /* #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */

static void cui_sso_login_set_item_state(mmi_id gid, U8 operation)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cui_inline_lock_main_screen(gid);
	cui_inline_set_item_attributes(gid, SSO_LOGIN_LOGIN, operation, CUI_INLINE_ITEM_DISABLE);
	cui_inline_unlock_main_screen(gid);
}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_gpro
 * DESCRIPTION
 * The pro for ssocui group
 * PARAMETERS
 *  evt    : [IN] mmi_event_struct
 * RETURNS
 *  mmi_ret
 * RETURN VALUES
 *  MMI_RET_OK
 *****************************************************************************/
static mmi_ret cui_sso_login_gpro(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
    {
        if (g_ssocui_sns_infor_struct.sns_flag == MMI_TRUE
            #ifndef BROWSER_SUPPORT
			  || 1
			#endif
		   )
        {
			cui_event_inline_common_struct *i_evt = (cui_event_inline_common_struct*)evt;
			cui_inline_lock_main_screen(i_evt->sender_id);
			cui_inline_delete_item(
                mmi_frm_group_get_active_id(), 
                SSO_LOGIN_BLANK_CAPTION_S); 
            cui_inline_delete_item(
                mmi_frm_group_get_active_id(), 
                SSO_LOGIN_SIGNUP);    
			cui_inline_unlock_main_screen(i_evt->sender_id);
        }
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_list_tap_callback(cui_sso_login_tap_callback);
    #endif
		{
			cui_event_inline_common_struct *i_evt = (cui_event_inline_common_struct*)evt;
			MMI_BOOL Is_Empty = MMI_FALSE;

			memset(g_ssocui_pw, 0x00, sizeof(g_ssocui_pw));
			cui_inline_get_value(i_evt->sender_id, SSO_LOGIN_PW_CONTEXT, g_ssocui_pw);
			if (mmi_wcslen(g_ssocui_pw) == 0)
			{
				Is_Empty = MMI_TRUE;
			}
			if (!Is_Empty)
			{
				memset(g_ssocui_id, 0x00, sizeof(g_ssocui_id));
				cui_inline_get_value(i_evt->sender_id, SSO_LOGIN_PW_CONTEXT, g_ssocui_id);
				if (mmi_wcslen(g_ssocui_id) == 0)
				{
					Is_Empty = MMI_TRUE;
				}
			}
			cui_sso_login_set_item_state(i_evt->sender_id, ((Is_Empty)?(CUI_INLINE_SET_ATTRIBUTE):(CUI_INLINE_RESET_ATTRIBUTE)));
		}
        break;
    }
    
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt; 
            if ((mmi_wcslen(g_ssocui_id) == 0) || (mmi_wcslen(g_ssocui_pw) == 0))
            {
                cui_menu_set_item_disabled(menu_evt->sender_id, MENU_ID_MMI_SSOCUI_LOGIN, MMI_TRUE);
            }
            if (g_ssocui_sns_infor_struct.sns_flag == MMI_TRUE)
            {
                cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_MMI_SSOCUI_SIGNUP, MMI_TRUE);
            }
            break;
        }

    case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            if (menu_evt->highlighted_menu_id == MENU_ID_MMI_SSOCUI_LOGIN)
            {
                /* login the spec id */
                 cui_sso_login_login();
            }
			#ifdef __MMI_SSO__
            else if (menu_evt->highlighted_menu_id == MENU_ID_MMI_SSOCUI_SIGNUP)
            {
                /* entry the sign up http */
                cui_sso_login_signup();
            }
            #endif

            break;
        }
        break;
        
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *i_evt = (cui_event_inline_notify_struct *)evt;
			MMI_BOOL Is_NotEmpty = MMI_FALSE;

			if (i_evt->event_type == CUI_INLINE_NOTIFY_TEXT_NOT_EMPTY)
			{
				if (i_evt->item_id == SSO_LOGIN_ID_CONTEXT )
				{
					memset(g_ssocui_pw, 0x00, sizeof(g_ssocui_pw));
					cui_inline_get_value(i_evt->sender_id, SSO_LOGIN_PW_CONTEXT, g_ssocui_pw);
					if (mmi_wcslen(g_ssocui_pw) != 0)
					{
						Is_NotEmpty = MMI_TRUE;
					}
				}
				else if (i_evt->item_id == SSO_LOGIN_PW_CONTEXT)
				{
					memset(g_ssocui_id, 0x00, sizeof(g_ssocui_id));
					cui_inline_get_value(i_evt->sender_id, SSO_LOGIN_ID_CONTEXT, g_ssocui_id);
					if (mmi_wcslen(g_ssocui_id) != 0)
					{
						Is_NotEmpty = MMI_TRUE;
					}
				}

				if (Is_NotEmpty)
				{
					cui_sso_login_set_item_state(i_evt->sender_id, CUI_INLINE_RESET_ATTRIBUTE);
				}
			}
			else if (i_evt->event_type == CUI_INLINE_NOTIFY_TEXT_EMPTY)
			{
				cui_sso_login_set_item_state(i_evt->sender_id, CUI_INLINE_SET_ATTRIBUTE);
			}
			else if (i_evt->event_type == CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM)
			{
			    if ((i_evt->item_id == SSO_LOGIN_LOGIN ) || (i_evt->item_id == SSO_LOGIN_SIGNUP))
			    {
					cui_inline_set_softkey_text(i_evt->sender_id, i_evt->item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OK);
			    }
				else
				{
				    cui_inline_set_softkey_text(i_evt->sender_id, i_evt->item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OPTIONS);
				}
			}
            break;
        }

    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
            cui_menu_close(menu_evt->sender_id);
            break;
        }
    case EVT_ID_CUI_INLINE_CSK_PRESS:
    case EVT_ID_CUI_INLINE_SUBMIT: 
        {
            cui_event_inline_submit_struct *inline_evt = (cui_event_inline_submit_struct *)evt;
            if (inline_evt->item_id == SSO_LOGIN_ID_CONTEXT)
            {
                cui_sso_login_option(inline_evt);
            }
            else if (inline_evt->item_id == SSO_LOGIN_PW_CONTEXT)
            {
                cui_sso_login_option(inline_evt);
            }
            else if (inline_evt->item_id == SSO_LOGIN_LOGIN)/* log in */
            {
                /* login the spec id */
                cui_sso_login_login();
            }
            else if (inline_evt->item_id == SSO_LOGIN_SIGNUP)/* sign up */
            {
             #ifdef __MMI_SSO__
                /* entry the sign up http */
                cui_sso_login_signup();
			 #endif
            }
            break;
        }

    case EVT_ID_GROUP_GOBACK_IN_END_KEY:
    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_sso_login_done_event_struct *ssocui_evt = (cui_sso_login_done_event_struct*)evt;
            if (g_ssocui_sns_infor_struct.sns_flag == MMI_TRUE)
            {
            #ifdef __SOCIAL_NETWORK_SUPPORT__
                cui_sso_login_post_evt_sns(EVT_ID_CUI_SS0_LOGIN_ABORT);
            #endif
            }
            else
            {
            #ifdef __MMI_SSO__
                cui_sso_login_post_evt(EVT_ID_CUI_SS0_LOGIN_ABORT);
			#endif
            }
            break;
        }

    case EVT_ID_GROUP_DEINIT:
        {
            g_ssocui_sns_infor_struct.sns_flag = MMI_FALSE;
            break;
        }

    default:
        break;
    }

    /* just for input */
    if (cui_menu_is_menu_event(evt->evt_id))
    {
    	if (g_ssocui_sns_infor_struct.sns_flag)
		{
			wgui_inputs_options_menu_handler(evt, g_ssocui_sns_infor_struct.cui_gid);
		}
		else 
		{
			wgui_inputs_options_menu_handler(evt, g_ssocui_gid);
		}
    }

    return MMI_RET_OK;
}


#ifdef __MMI_SSO__
static mmi_ret cui_sso_not_ready_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sso_evt_ready_struct *ready = (srv_sso_evt_ready_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ready->is_ready)
    {
        if (mmi_frm_group_is_present(g_ssocui_gid))
        {
            mmi_frm_group_close(g_ssocui_gid);
        }  
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_create
 * DESCRIPTION
 *  This function is used to create login cui.
 * PARAMETERS
 * parent_gid [IN]   MI_ID  cui parent gid
 * provoider  [IN]   U32 provider id
 * account    [IN]   U8  account id
 * RETURNS
 *  return login cui group id
 *****************************************************************************/
extern MMI_ID cui_sso_login_create(MMI_ID parent_gid, U32 provider, U8 account)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sso_account_struct account_buf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_ssocui_sns_infor_struct, 0, sizeof(ssocui_sns_infor_struct));
	if(!srv_sso_is_ready())
	{
		kal_prompt_trace(MOD_MMI_COMMON_APP,"cui_sso_login_create sso is not ready");
		g_ssocui_gid = GRP_ID_INVALID;
		return g_ssocui_gid;
	}
	mmi_frm_cb_reg_event(EVT_ID_SRV_SSO_READY, cui_sso_not_ready_proc, NULL);

    if (srv_sso_get_account(provider, account, &account_buf))
    {
        g_ssocui_gid = mmi_frm_group_create_ex(
            parent_gid, 
            GRP_ID_AUTO_GEN, 
            cui_sso_login_gpro, 
            NULL, 
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
        g_ssocui_provider = provider;
        g_ssocui_account_id = account;
        g_ssocui_parent_gid = parent_gid;
        g_ssocui_inline_gid = cui_inline_create(g_ssocui_gid, &g_sso_login_inline_struct);
        /* to get provider name */
        srv_sso_get_provider_name(provider, g_ssocui_pname);
        cui_inline_set_title_string(g_ssocui_inline_gid, g_ssocui_pname);
        /* to get account name */
        srv_sso_get_account_name(provider, account, g_ssocui_id);
        cui_inline_set_value(g_ssocui_inline_gid, SSO_LOGIN_ID_CONTEXT, g_ssocui_id);  
		if (mmi_wcslen(g_ssocui_id) != 0)
		{
			cui_inline_set_highlight_item(g_ssocui_inline_gid, SSO_LOGIN_PW_CONTEXT);
		}	
    }
    else /* if the account not exists*/
    {
        if (srv_sso_get_provider(provider, NULL))
        {
            g_ssocui_gid = mmi_frm_group_create_ex(
                parent_gid, 
                GRP_ID_AUTO_GEN, 
                cui_sso_login_gpro, 
                NULL, 
                MMI_FRM_NODE_SMART_CLOSE_FLAG);
            g_ssocui_provider = provider;
            g_ssocui_parent_gid = parent_gid;
            g_ssocui_inline_gid = cui_inline_create(g_ssocui_gid, &g_sso_login_inline_struct);
            /* to get provider name */
            srv_sso_get_provider_name(provider, g_ssocui_pname);
            cui_inline_set_title_string(g_ssocui_inline_gid, g_ssocui_pname);  
        }
        else
        {
            g_ssocui_gid = GRP_ID_INVALID;
        }
    }
    MMI_TRACE(
        MMI_INET_TRC_G7_SSO, 
        CUI_SSO_LOGIN_CREATE, 
        g_ssocui_parent_gid, 
        g_ssocui_gid, 
        g_ssocui_inline_gid, 
        g_ssocui_provider, 
        g_ssocui_account_id); 
    return g_ssocui_gid; 
}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_create_bootup
 * DESCRIPTION
 *  This function is used to create login cui.
 * PARAMETERS
 * parent_gid [IN]   MI_ID  cui parent gid
 * provoider  [IN]   U32 provider id
 * account    [IN]   U8  account id
 * RETURNS
 *  return login cui group id
 *****************************************************************************/
extern MMI_ID cui_sso_login_create_bootup(MMI_ID parent_gid, U32 provider, U8 account)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    g_ssocui_gid = mmi_frm_group_create_ex(
        parent_gid, 
        GRP_ID_AUTO_GEN, 
        cui_sso_login_gpro, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_ssocui_provider = provider;
    g_ssocui_parent_gid = parent_gid;
    g_ssocui_inline_gid = cui_inline_create(g_ssocui_gid, &g_sso_login_inline_struct);
    /* to get provider name */
    srv_sso_get_provider_name(provider, g_ssocui_pname);
    cui_inline_set_title_string(g_ssocui_inline_gid, g_ssocui_pname);
    MMI_TRACE(
        MMI_INET_TRC_G7_SSO, 
        CUI_SSO_LOGIN_CREATE, 
        g_ssocui_parent_gid, 
        g_ssocui_gid, 
        g_ssocui_inline_gid, 
        g_ssocui_provider, 
        1234); 
    return g_ssocui_gid; 
}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_run
 * DESCRIPTION
 *  This function is used to run login cui.
 * PARAMETERS
 *  gid          [in]    login cui group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sso_login_run(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_run(g_ssocui_inline_gid);
    MMI_TRACE(
        MMI_INET_TRC_G7_SSO, 
        CUI_SSO_LOGIN_RUN, 
        g_ssocui_parent_gid, 
        g_ssocui_gid, 
        g_ssocui_inline_gid, 
        g_ssocui_provider, 
        g_ssocui_account_id); 
}


/*****************************************************************************
 * FUNCTION
 *  cui_sso_login_close
 * DESCRIPTION
 *  This function is used to close SSO login cui.
 * PARAMETERS
 *  gid          [in]    login cui group id
 * RETURNS
 *  void
 *****************************************************************************/
extern void cui_sso_login_close(MMI_ID gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_close(gid);
    MMI_TRACE(
        MMI_INET_TRC_G7_SSO, 
        CUI_SSO_LOGIN_CLOSE, 
        g_ssocui_parent_gid, 
        g_ssocui_gid, 
        g_ssocui_inline_gid, 
        g_ssocui_provider, 
        g_ssocui_account_id); 
}
#endif
#endif

