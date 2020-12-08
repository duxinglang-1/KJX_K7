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
 *  cmcc_wlan_auth_ui.c
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


#include "DataAccountCommon.h"

#include "inlinecuigprot.h"
#include "smssrvgprot.h"
#include "DtcntSrvIprot.h"

#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"

#include "mmi_rp_app_dataaccount_def.h"

#include "cmcc_wlan_auth_gprot.h"
#include "cmcc_wlan_auth_prot.h"

///////////////////////////////////////////////////////////////////////////////
// Setting / UI part
#define CMCC_WLAN_SETTING_FILENAME "cmccwlan.dat"
#define CMCC_WLAN_MAX_INPUT_LEN    60

#define CMCC_WLAN_LOADING_TYPE_SMS    1
#define CMCC_WLAN_LOADING_TYPE_LOGIN  2

#define CMCC_WLAN_MAKE_FILENAME(str) \
    do{\
    kal_wsprintf(str,\
        "%c:\\%s",\
        (CHAR) FS_GetDrive(FS_DRIVE_I_SYSTEM, 1, FS_DRIVE_I_SYSTEM),\
        CMCC_WLAN_SETTING_FILENAME);\
    }while(0)

#define CMCC_WLAN_FRM_CLOSE_GRP(id) \
    do{\
        mmi_id tmpid = id;\
        id = 0;\
        mmi_frm_group_close(tmpid);\
    }while(0)

enum
{
    CMCC_SETTING_INLINE_ID_USER_CAPA = (CUI_INLINE_ITEM_ID_BASE + 0),
    CMCC_SETTING_INLINE_ID_USER_EDIT,

    CMCC_SETTING_INLINE_ID_PASS_CAPA,
    CMCC_SETTING_INLINE_ID_PASS_EDIT,

    CMCC_SETTING_INLINE_ID_AUTH_CAPA,
    CMCC_SETTING_INLINE_ID_AUTH_EDIT,

    CMCC_SETTING_INLINE_ID_NOTE_CAPA,
    CMCC_SETTING_INLINE_ID_NOTE_EDIT,

    CMCC_SETTING_INLINE_ID_APPLY_BTN,
    CMCC_SETTING_INLINE_ID_MODIFY_BTN,
    CMCC_SETTING_INLINE_ID_RESET_BTN,
};


enum
{
    CMCC_PASSWORD_INLINE_ID_OLD_CAPA = (CUI_INLINE_ITEM_ID_BASE + 0),
    CMCC_PASSWORD_INLINE_ID_OLD_EDIT,

    CMCC_PASSWORD_INLINE_ID_NEW1_CAPA,
    CMCC_PASSWORD_INLINE_ID_NEW1_EDIT,

    CMCC_PASSWORD_INLINE_ID_NEW2_CAPA,
    CMCC_PASSWORD_INLINE_ID_NEW2_EDIT,
};

enum
{
    CMCC_WLAN_UI_ACTIVITY_NULL = 0,
    CMCC_WLAN_UI_ACTIVITY_LOGIN,
    CMCC_WLAN_UI_ACTIVITY_LOGOUT,
};

typedef struct
{
    S32 notify_auto;
    U8 username[CMCC_WLAN_MAX_INPUT_LEN + 1];
    U8 password[CMCC_WLAN_MAX_INPUT_LEN + 1];

    // Temp
    BOOL saved;
}cmcc_wlan_file_struct;

typedef struct
{
    mmi_id grp_id;
    mmi_id inline_id;

    mmi_id sub_grp_id;
    mmi_id sub_inline_id;

    mmi_id tmp_parent_id; /* For POPUP, CONFIRM, LOADING */
    S32 loading_type;

    SMS_HANDLE sms_handle;
    U32 sms_state; // 0 = NULL, 1 = SENDING

    WCHAR tempwstr[256];
    WCHAR sms_content[256];

    U32 ui_activity;
    cmcc_wlan_auth_callback cb;

    BOOL need_login;
    BOOL confirm_checked;
    BOOL need_logout;
}cmcc_wlan_setting_struct;


#define CMCC_SMS_WBUF (g_cmcc_wlan_setting.sms_content)
#define CMCC_TEMP_WBUF (g_cmcc_wlan_setting.tempwstr)

static cmcc_wlan_setting_struct g_cmcc_wlan_setting;
static cmcc_wlan_file_struct g_cmcc_file_cntx;

/* Screen 1, main setting */
static mmi_id cmcc_wlan_auth_setting_screen(mmi_id parent_id, BOOL login);
static mmi_ret cmcc_wlan_portal_setting_proc(mmi_event_struct *evt);
static void cmcc_wlan_inline_notify(cui_event_inline_notify_struct *evt);

static void cmcc_wlan_save(mmi_id evt_id);
static U32 cmcc_wlan_save_check(mmi_id evt_id);

/* Screen 2, modify password */
static mmi_id cmcc_wlan_modify_password(mmi_id parent_id);
static mmi_ret cmcc_wlan_modify_password_proc(mmi_event_struct *evt);

static U32 cmcc_wlan_sms_modify_password_check(void);

/* Utility */
static void ucs2ascii(const WCHAR *ucs, U8 *ascii, S32 len);
static void ascii2ucs(const U8 *ascii, WCHAR *ucs, S32 len);

static void cmcc_file_save(void);
static void cmcc_file_load(void);

/* Send SMS to 10086 */
static void cmcc_wlan_sms_callback(srv_sms_callback_struct* callback_data);

static void cmcc_wlan_sms_send(void);
static void cmcc_wlan_sms_send_go(void);

static void cmcc_wlan_sms_apply_password(void);
static void cmcc_wlan_sms_modify_password(void);
static void cmcc_wlan_sms_reset_password(void);

static void cmcc_wlan_auth_show_popup(U32 err_str_id, mmi_event_notify_enum type);

static void cmcc_wlan_auth_show_loading(void);
static void cmcc_wlan_auth_close_loading(void);

static void cmcc_wlan_auth_show_sms_confirm(void);
static mmi_ret cmcc_wlan_sms_confirm_callback(mmi_event_struct *evt);

static void cmcc_wlan_auth_show_http_confirm(void);
static void cmcc_wlan_http_confirm_yes(void);
static void cmcc_wlan_http_confirm_no(void);
static void cmcc_wlan_http_confirm_checkbox_callback(MMI_BOOL checked);
static mmi_ret cmcc_wlan_http_confirm_del_callback(mmi_event_struct *evt);

static cmcc_wlan_auth_ret_enum cmcc_wlan_auth_go(void);
static void cmcc_wlan_auth_ui_login_callback(cmcc_wlan_auth_ret_enum ret);
static void cmcc_wlan_auth_ui_logout_callback(cmcc_wlan_auth_ret_enum ret);

static void cmcc_wlan_auth_loading_cancel(void);
static mmi_ret cmcc_wlan_auth_loading_del_callback(mmi_event_struct *evt);


/*****************************************************************************
 * FUNCTION 
 *  ucs2ascii
 * DESCRIPTION 
 *  ucs2ascii
 * PARAMETERS 
 *  const WCHAR *ucs
 *  U8 *ascii
 *  S32 len
 * RETURNS 
 *  static void 
*****************************************************************************/
static void ucs2ascii(const WCHAR *ucs, U8 *ascii, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len && ucs[i] != 0; i++)
    {
        ascii[i] = (U8)ucs[i];
    }
    ascii[i] = 0;
}


/*****************************************************************************
 * FUNCTION 
 *  ascii2ucs
 * DESCRIPTION 
 *  ascii2ucs
 * PARAMETERS 
 *  const U8 *ascii
 *  WCHAR *ucs
 *  S32 len
 * RETURNS 
 *  static void 
*****************************************************************************/
static void ascii2ucs(const U8 *ascii, WCHAR *ucs, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len && ascii[i] != 0; i++)
    {
        ucs[i] = ascii[i];
    }
    ucs[i] = 0;
}



/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_save_check
 * DESCRIPTION 
 *  cmcc wlan save check
 * PARAMETERS 
 *  mmi_id evt_id
 * RETURNS 
 *  static U32 
*****************************************************************************/
static U32 cmcc_wlan_save_check(mmi_id evt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(evt_id, CMCC_SETTING_INLINE_ID_USER_EDIT, CMCC_TEMP_WBUF);
    if (CMCC_TEMP_WBUF[0] == 0)
    {
        return STR_CMCC_WLAN_EMPTY_USERNAME;
    }

    cui_inline_get_value(evt_id, CMCC_SETTING_INLINE_ID_PASS_EDIT, CMCC_TEMP_WBUF);
    if (CMCC_TEMP_WBUF[0] == 0)
    {
        return STR_CMCC_WLAN_EMPTY_PASSWORD;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_save
 * DESCRIPTION 
 *  cmcc wlan save
 * PARAMETERS 
 *  mmi_id evt_id
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_save(mmi_id evt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 err_str_id = 0;
    cmcc_wlan_auth_ret_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    err_str_id = cmcc_wlan_save_check(evt_id);
    if (err_str_id != 0)
    {
        g_cmcc_wlan_setting.tmp_parent_id = g_cmcc_wlan_setting.grp_id;
        cmcc_wlan_auth_show_popup(err_str_id, MMI_EVENT_FAILURE);
        return;
    }

    cui_inline_get_value(evt_id, CMCC_SETTING_INLINE_ID_USER_EDIT, CMCC_TEMP_WBUF);
    ucs2ascii(CMCC_TEMP_WBUF, g_cmcc_file_cntx.username, CMCC_WLAN_MAX_INPUT_LEN);

    cui_inline_get_value(evt_id, CMCC_SETTING_INLINE_ID_PASS_EDIT, CMCC_TEMP_WBUF);
    ucs2ascii(CMCC_TEMP_WBUF, g_cmcc_file_cntx.password, 60);

    //cui_inline_get_value(evt_id, CMCC_SETTING_INLINE_ID_AUTH_EDIT, &g_cmcc_file_cntx.auto_auth);
    cui_inline_get_value(evt_id, CMCC_SETTING_INLINE_ID_NOTE_EDIT, &g_cmcc_file_cntx.notify_auto);

    /* Save to file */
    g_cmcc_file_cntx.saved = TRUE;
    cmcc_file_save();

    CMCC_WLAN_FRM_CLOSE_GRP(g_cmcc_wlan_setting.grp_id);

    if (g_cmcc_wlan_setting.need_login)
    {
        /* Go... */
        ret = cmcc_wlan_auth_go();
        if (ret != CMCC_WLAN_AUTH_WBLOCK)
        {
            cmcc_wlan_auth_ui_login_callback(ret);
        }
    }
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_file_save
 * DESCRIPTION 
 *  cmcc file save
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_file_save(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    CMCC_WLAN_MAKE_FILENAME(CMCC_TEMP_WBUF);
    h = FS_Open(CMCC_TEMP_WBUF, FS_READ_WRITE | FS_CREATE_ALWAYS);
    if (h < 0)
    {
        return;
    }

    FS_Write(h, &g_cmcc_file_cntx, sizeof(cmcc_wlan_file_struct), NULL);
    FS_Close(h);
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_file_load
 * DESCRIPTION 
 *  cmcc file load
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_file_load(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static BOOL loaded = FALSE;
    FS_HANDLE h = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (loaded)
    {
        return;
    }
    loaded = TRUE;

    memset(&g_cmcc_file_cntx, 0, sizeof(cmcc_wlan_file_struct));
    CMCC_WLAN_MAKE_FILENAME(CMCC_TEMP_WBUF);
    h = FS_Open(CMCC_TEMP_WBUF, FS_READ_ONLY);
    if (h < 0)
    {
        return;
    }
    FS_Read(h, &g_cmcc_file_cntx, sizeof(cmcc_wlan_file_struct), NULL);
    FS_Close(h);

    g_cmcc_file_cntx.saved = TRUE;
}



/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_portal_setting_proc
 * DESCRIPTION 
 *  cmcc wlan portal setting proc
 * PARAMETERS 
 *  mmi_event_struct *evt
 * RETURNS 
 *  static mmi_ret 
*****************************************************************************/
static mmi_ret cmcc_wlan_portal_setting_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
        if (g_cmcc_wlan_setting.grp_id != 0 && g_cmcc_wlan_setting.need_login)
        {
            cmcc_wlan_auth_ui_login_callback(CMCC_WLAN_AUTH_NO_ACCOUNT);
        }
        g_cmcc_wlan_setting.grp_id = 0;
        break;

    // Inline CUI event
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        // Save setting data
        g_cmcc_wlan_setting.tmp_parent_id = g_cmcc_wlan_setting.grp_id;
        if (((cui_event_inline_submit_struct*)evt)->item_id == CMCC_SETTING_INLINE_ID_MODIFY_BTN)
        {
            cmcc_wlan_modify_password(((cui_event_inline_submit_struct*)evt)->sender_id);
        }
        else if (((cui_event_inline_submit_struct*)evt)->item_id == CMCC_SETTING_INLINE_ID_APPLY_BTN)
        {
            cmcc_wlan_sms_apply_password();
        }
        else if (((cui_event_inline_submit_struct*)evt)->item_id == CMCC_SETTING_INLINE_ID_RESET_BTN)
        {
            cmcc_wlan_sms_reset_password();
        }
        else
        {
            cmcc_wlan_save(((cui_event_inline_submit_struct*)evt)->sender_id);
        }
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        CMCC_WLAN_FRM_CLOSE_GRP(g_cmcc_wlan_setting.grp_id);
        if (g_cmcc_wlan_setting.need_login)
        {
            cmcc_wlan_auth_ui_login_callback(CMCC_WLAN_AUTH_NO_ACCOUNT);
        }
        break;

    case EVT_ID_CUI_INLINE_NOTIFY:
        cmcc_wlan_inline_notify((cui_event_inline_notify_struct*)evt);
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_charge_notify
 * DESCRIPTION 
 *  cmcc wlan charge notify
 * PARAMETERS 
 *  mmi_event_struct *param
 * RETURNS 
 *  static mmi_ret 
*****************************************************************************/
static mmi_ret cmcc_wlan_charge_notify(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cmcc_wlan_setting.tmp_parent_id = g_cmcc_wlan_setting.grp_id;
    cmcc_wlan_auth_show_popup(STR_CMCC_WLAN_AUTH_NOTIFY, MMI_EVENT_INFO);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_inline_notify
 * DESCRIPTION 
 *  cmcc wlan inline notify
 * PARAMETERS 
 *  cui_event_inline_notify_struct *evt
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_inline_notify(cui_event_inline_notify_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->event_type)
    {
    case CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED:
        if (evt->param != evt->param_ext
            && evt->item_id == CMCC_SETTING_INLINE_ID_NOTE_EDIT)
        {
            U8 notify_auto;

            cui_inline_get_value(evt->sender_id, CMCC_SETTING_INLINE_ID_NOTE_EDIT, &notify_auto);
            if (notify_auto == 0)
            {
                mmi_event_struct evt;

                MMI_FRM_INIT_EVENT(&evt, 0);
                mmi_frm_post_event(&evt, cmcc_wlan_charge_notify, NULL);
            }
        }
        break;

    case CUI_INLINE_NOTIFY_HIGHLIGHT_ITEM:
        switch (evt->item_id)
        {
        case CMCC_SETTING_INLINE_ID_APPLY_BTN:
        case CMCC_SETTING_INLINE_ID_RESET_BTN:
        case CMCC_SETTING_INLINE_ID_MODIFY_BTN:
            cui_inline_set_softkey_icon(evt->sender_id, evt->item_id, MMI_LEFT_SOFTKEY, IMG_GLOBAL_OK);
            cui_inline_set_softkey_text(evt->sender_id, evt->item_id, MMI_LEFT_SOFTKEY, STR_GLOBAL_OK);
            break;

        default:
            break;
        }
        break;
    }
}

///////////////////////////////////////////////////////////////////////////


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_setting_screen
 * DESCRIPTION 
 *  cmcc wlan auth setting screen
 * PARAMETERS 
 *  mmi_id parent_id
 *  BOOL need_login
 * RETURNS 
 *  static mmi_id 
*****************************************************************************/
static mmi_id cmcc_wlan_auth_setting_screen(mmi_id parent_id, BOOL need_login)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_item_softkey_struct save_softkey_item = {{
        {STR_GLOBAL_SAVE, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {STR_GLOBAL_SAVE, IMG_GLOBAL_SAVE_CSK}}};

    cui_inline_item_softkey_struct login_softkey_item = {{
        {STR_GLOBAL_LOGIN, 0},
        {CUI_INLINE_SOFTKEY_DEFAULT_VALUE, 0},
        {STR_GLOBAL_LOGIN, IMG_GLOBAL_COMMON_CSK}}};

    cui_inline_set_item_struct inline_item[11];

    cui_inline_struct inline_cntx;

    cui_inline_item_caption_struct caption_item[4];
    cui_inline_item_text_edit_struct edit_item[2];
    cui_inline_item_select_struct select_item[2];
    cui_inline_item_display_only_struct btn_item[3];

    S32 i_idx = 0; // inline item index
    S32 e_idx = 0; // editor item index
    S32 c_idx = 0; // caption item index
    S32 s_idx = 0; // selection item index
    S32 d_idx = 0; // display only item index

    mmi_id grp_id, cui_id;

    U16 radio_str[] = {STR_GLOBAL_OFF, STR_GLOBAL_ON};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // Load setting
    cmcc_file_load();

    // Create group as inline cui's host.
    if (g_cmcc_wlan_setting.grp_id != 0)
    {
        CMCC_WLAN_FRM_CLOSE_GRP(g_cmcc_wlan_setting.grp_id);
    }

    if (parent_id == 0)
    {
        parent_id = GRP_ID_ROOT;
    }

    grp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, cmcc_wlan_portal_setting_proc, NULL);
    mmi_frm_group_enter(grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_cmcc_wlan_setting.grp_id = grp_id;

    // Username
    /* Username caption */
    caption_item[c_idx].string_id = STR_GLOBAL_USERNAME;
    inline_item[i_idx].item_id = CMCC_SETTING_INLINE_ID_USER_CAPA;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[i_idx].image_id = 0; //IMG_EMAIL_EMAIL_ADDRESS_ID;
    inline_item[i_idx].item_data = &caption_item[c_idx];
    i_idx++;
    c_idx++;

    /* Username editor */
    edit_item[e_idx].string_id = 0;
    edit_item[e_idx].default_text_id = 0;
    edit_item[e_idx].buffer_size = 60;
    edit_item[e_idx].input_type = IMM_INPUT_TYPE_ASCII_CHAR;
    edit_item[e_idx].input_extended_type = 0;
    edit_item[e_idx].required_input_mode_set = NULL;

    inline_item[i_idx].item_id = CMCC_SETTING_INLINE_ID_USER_EDIT;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
    inline_item[i_idx].image_id = 0;
    inline_item[i_idx].item_data = &edit_item[e_idx];
    i_idx++;
    e_idx++;

    // Password
    /* Password caption */
    caption_item[c_idx].string_id = STR_GLOBAL_PASSWORD;
    inline_item[i_idx].item_id = CMCC_SETTING_INLINE_ID_PASS_CAPA;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[i_idx].image_id = 0;
    inline_item[i_idx].item_data = &caption_item[c_idx];
    i_idx++;
    c_idx++;

    /* Password editor */
    edit_item[e_idx].string_id = 0;
    edit_item[e_idx].default_text_id = 0;
    edit_item[e_idx].buffer_size = 60;
    edit_item[e_idx].input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
    edit_item[e_idx].input_extended_type = 0;
    edit_item[e_idx].required_input_mode_set = NULL;

    inline_item[i_idx].item_id = CMCC_SETTING_INLINE_ID_PASS_EDIT;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
    inline_item[i_idx].image_id = 0;
    inline_item[i_idx].item_data = &edit_item[e_idx];
    i_idx++;
    e_idx++;

    // Notify when auth automatically
    /* Notify caption */
    caption_item[c_idx].string_id = STR_CMCC_WLAN_NOTI_AUTH;
    inline_item[i_idx].item_id = CMCC_SETTING_INLINE_ID_NOTE_CAPA;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[i_idx].image_id = 0; //IMG_EMAIL_PROTOCOL_ID;
    inline_item[i_idx].item_data = &caption_item[c_idx];
    i_idx++;
    c_idx++;

    /* Notify selection */
    select_item[s_idx].n_items = 2;
    select_item[s_idx].highlighted_item = (g_cmcc_file_cntx.saved ? g_cmcc_file_cntx.notify_auto : 1); //default ON
    select_item[s_idx].list_of_item_id = radio_str;

    inline_item[i_idx].item_id = CMCC_SETTING_INLINE_ID_NOTE_EDIT;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_SELECT;
    inline_item[i_idx].image_id = 0;
    inline_item[i_idx].item_data = &select_item[s_idx];
    i_idx++;
    s_idx++;

    /* Apply password */
    btn_item[d_idx].string_id = STR_CMCC_WLAN_APPLY_PASSWORD;
    inline_item[i_idx].item_id = CMCC_SETTING_INLINE_ID_APPLY_BTN;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_CENTER_JUSTIFY;
    inline_item[i_idx].image_id = 0; 
    inline_item[i_idx].item_data = &btn_item[d_idx];
    i_idx++;
    d_idx++;

    /* Modify password button */
    btn_item[d_idx].string_id = STR_CMCC_WLAN_MODIFY_PASSWORD;
    inline_item[i_idx].item_id = CMCC_SETTING_INLINE_ID_MODIFY_BTN;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_CENTER_JUSTIFY;
    inline_item[i_idx].image_id = 0; 
    inline_item[i_idx].item_data = &btn_item[d_idx];
    i_idx++;
    d_idx++;

    /* Reset password */
    btn_item[d_idx].string_id = STR_CMCC_WLAN_RESET_PASSWORD;
    inline_item[i_idx].item_id = CMCC_SETTING_INLINE_ID_RESET_BTN;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_DISPLAY_ONLY | CUI_INLINE_ITEM_CENTER_JUSTIFY;
    inline_item[i_idx].image_id = 0; 
    inline_item[i_idx].item_data = &btn_item[d_idx];
    i_idx++;
    d_idx++;

    // Ready to run
    inline_cntx.items_count = i_idx;
    inline_cntx.title = STR_CMCC_WLAN_AUTH_MAIN;
    inline_cntx.title_icon = 0;
    inline_cntx.screen_flag = CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE;
    if (need_login)
    {
        inline_cntx.softkey = &login_softkey_item;
    }
    else
    {
        inline_cntx.softkey = &save_softkey_item;
    }
    inline_cntx.items = inline_item;

    cui_id = cui_inline_create(grp_id, &inline_cntx);
    g_cmcc_wlan_setting.inline_id = cui_id;

    /* Init value */
    if (g_cmcc_file_cntx.saved)
    {
        // Set Username
        ascii2ucs(g_cmcc_file_cntx.username, CMCC_TEMP_WBUF, 60);
        cui_inline_set_value(cui_id, CMCC_SETTING_INLINE_ID_USER_EDIT, CMCC_TEMP_WBUF);

        // Password
        ascii2ucs(g_cmcc_file_cntx.password, CMCC_TEMP_WBUF, 60);
        cui_inline_set_value(cui_id, CMCC_SETTING_INLINE_ID_PASS_EDIT, CMCC_TEMP_WBUF);
    }

    g_cmcc_wlan_setting.need_login = need_login;
    cui_inline_run(g_cmcc_wlan_setting.inline_id);

    return grp_id;
}


/////////////////////////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_modify_password_proc
 * DESCRIPTION 
 *  cmcc wlan modify password proc
 * PARAMETERS 
 *  mmi_event_struct *evt
 * RETURNS 
 *  static mmi_ret 
*****************************************************************************/
static mmi_ret cmcc_wlan_modify_password_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
    case EVT_ID_GROUP_DEINIT:
        g_cmcc_wlan_setting.sub_grp_id = 0;
        break;

    // Inline CUI event
    case EVT_ID_CUI_INLINE_SUBMIT:
    case EVT_ID_CUI_INLINE_CSK_PRESS:
        g_cmcc_wlan_setting.tmp_parent_id = g_cmcc_wlan_setting.sub_grp_id;
        cmcc_wlan_sms_modify_password();
        break;

    case EVT_ID_CUI_INLINE_ABORT:
        mmi_frm_group_close(g_cmcc_wlan_setting.sub_grp_id);
        break;

    default:
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_sms_callback
 * DESCRIPTION 
 *  cmcc wlan sms callback
 * PARAMETERS 
 *  srv_sms_callback_struct* sms
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_sms_callback(srv_sms_callback_struct* sms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cmcc_wlan_setting.sms_state == 0)
    {
        return;
    }

    cmcc_wlan_auth_close_loading();
    g_cmcc_wlan_setting.sms_handle = NULL;
    g_cmcc_wlan_setting.sms_state = 0;

    if (sms->result)
    {
        cmcc_wlan_auth_show_popup(
            STR_CMCC_WLAN_SEND_SMS_SUCC,
            MMI_EVENT_SUCCESS);

        // Close modify password screen
        if (g_cmcc_wlan_setting.sub_grp_id != 0)
        {
            mmi_frm_group_close(g_cmcc_wlan_setting.sub_grp_id);
        }
    }
    else
    {
        cmcc_wlan_auth_show_popup(
            STR_CMCC_WLAN_SEND_SMS_FAIL,
            MMI_EVENT_FAILURE);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_sms_send
 * DESCRIPTION 
 *  cmcc wlan sms send
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_sms_send(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cmcc_wlan_setting.sms_state ||
        !srv_sms_is_sms_ready() ||
        srv_sms_is_sms_busy() ||
        srv_sms_is_bg_send_action_busy())
    {
        // Popup
        cmcc_wlan_auth_show_popup(STR_CMCC_WLAN_SMS_BUSY, MMI_EVENT_FAILURE);
        return;
    }

    cmcc_wlan_auth_show_sms_confirm();
}



/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_sms_send_go
 * DESCRIPTION 
 *  cmcc wlan sms send go
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_sms_send_go(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE sms_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_handle = srv_sms_get_send_handle();
    if (sms_handle == NULL)
    {
        return;
    }

    g_cmcc_wlan_setting.sms_state = 1;
    srv_sms_set_address(sms_handle, (CHAR*)(L"10086"));
    srv_sms_set_content(sms_handle, 
        (CHAR*)CMCC_SMS_WBUF, 
        kal_wstrlen(CMCC_SMS_WBUF) * 2);
    srv_sms_send_msg(sms_handle, cmcc_wlan_sms_callback, NULL);

    if (g_cmcc_wlan_setting.sms_state == 0)
    {
        return;
    }

    g_cmcc_wlan_setting.sms_handle = sms_handle;
    g_cmcc_wlan_setting.loading_type = CMCC_WLAN_LOADING_TYPE_SMS;
    cmcc_wlan_auth_show_loading();
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_sms_apply_password
 * DESCRIPTION 
 *  cmcc wlan sms apply password
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_sms_apply_password(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(CMCC_SMS_WBUF, "KTWLAN");
    cmcc_wlan_sms_send();
}



/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_sms_modify_password_check
 * DESCRIPTION 
 *  cmcc wlan sms modify password check
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static U32 
*****************************************************************************/
static U32 cmcc_wlan_sms_modify_password_check(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cui_inline_get_value(g_cmcc_wlan_setting.sub_inline_id, 
        CMCC_PASSWORD_INLINE_ID_OLD_EDIT, 
        CMCC_SMS_WBUF);
    if (CMCC_SMS_WBUF[0] == 0)
    {
        return STR_CMCC_WLAN_EMPTY_OLD_PASSWORD;
    }

    cui_inline_get_value(g_cmcc_wlan_setting.sub_inline_id,
        CMCC_PASSWORD_INLINE_ID_NEW1_EDIT,
        CMCC_SMS_WBUF);
    if (CMCC_SMS_WBUF[0] == 0)
    {
        return STR_CMCC_WLAN_EMPTY_NEW1_PASSWORD;
    }

    cui_inline_get_value(g_cmcc_wlan_setting.sub_inline_id,
        CMCC_PASSWORD_INLINE_ID_NEW2_EDIT,
        CMCC_SMS_WBUF);
    if (CMCC_SMS_WBUF[0] == 0)
    {
        return STR_CMCC_WLAN_EMPTY_NEW2_PASSWORD;
    }

    cui_inline_get_value(g_cmcc_wlan_setting.sub_inline_id,
        CMCC_PASSWORD_INLINE_ID_NEW1_EDIT,
        CMCC_TEMP_WBUF);

    if (kal_wstrcmp(CMCC_SMS_WBUF, CMCC_TEMP_WBUF) != 0)
    {
        return STR_CMCC_WLAN_DIFFERENT_NEW_PASSWORD;
    }

    return 0;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_sms_modify_password
 * DESCRIPTION 
 *  cmcc wlan sms modify password
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_sms_modify_password(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 err_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check first */
    err_str_id = cmcc_wlan_sms_modify_password_check();
    if (err_str_id != 0)
    {
        g_cmcc_wlan_setting.tmp_parent_id = g_cmcc_wlan_setting.sub_grp_id;
        cmcc_wlan_auth_show_popup(err_str_id, MMI_EVENT_FAILURE);
        return;
    }

    kal_wsprintf(CMCC_SMS_WBUF, "XGWLANMM ");

    cui_inline_get_value(g_cmcc_wlan_setting.sub_inline_id, 
        CMCC_PASSWORD_INLINE_ID_OLD_EDIT, 
        CMCC_SMS_WBUF + kal_wstrlen(CMCC_SMS_WBUF));
    kal_wstrcat(CMCC_SMS_WBUF, L" ");
    cui_inline_get_value(g_cmcc_wlan_setting.sub_inline_id,
        CMCC_PASSWORD_INLINE_ID_NEW1_EDIT,
        CMCC_SMS_WBUF + kal_wstrlen(CMCC_SMS_WBUF));

    cmcc_wlan_sms_send();
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_sms_reset_password
 * DESCRIPTION 
 *  cmcc wlan sms reset password
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_sms_reset_password(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(g_cmcc_wlan_setting.sms_content, "CZWLANMM");
    cmcc_wlan_sms_send();
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_modify_password
 * DESCRIPTION 
 *  cmcc wlan modify password
 * PARAMETERS 
 *  mmi_id parent_id
 * RETURNS 
 *  static mmi_id 
*****************************************************************************/
static mmi_id cmcc_wlan_modify_password(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_inline_struct inline_cntx;

    cui_inline_item_softkey_struct softkey_item = {{
        {STR_GLOBAL_OK, IMG_GLOBAL_OK},
        {STR_GLOBAL_BACK, IMG_GLOBAL_BACK},
        {STR_GLOBAL_OK, IMG_GLOBAL_COMMON_CSK}}};

    cui_inline_set_item_struct inline_item[6];

    cui_inline_item_caption_struct caption_item[3];
    cui_inline_item_text_edit_struct edit_item[3];

    S32 i_idx = 0; // inline item index
    S32 e_idx = 0; // editor item index
    S32 c_idx = 0; // caption item index

    mmi_id grp_id, cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // Load setting
    cmcc_file_load();

    // Create group as inline cui's host.
    if (g_cmcc_wlan_setting.sub_grp_id != 0)
    {
        mmi_frm_group_close(g_cmcc_wlan_setting.sub_grp_id);
        g_cmcc_wlan_setting.sub_grp_id = 0;
    }

    if (parent_id == 0)
    {
        parent_id = GRP_ID_ROOT;
    }

    grp_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, cmcc_wlan_modify_password_proc, NULL);
    mmi_frm_group_enter(grp_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    g_cmcc_wlan_setting.sub_grp_id = grp_id;

    // Old password
    /* Old password caption */
    caption_item[c_idx].string_id = STR_CMCC_WLAN_OLD_PASSWORD;
    inline_item[i_idx].item_id = CMCC_PASSWORD_INLINE_ID_OLD_CAPA;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[i_idx].image_id = 0;
    inline_item[i_idx].item_data = &caption_item[c_idx];
    i_idx++;
    c_idx++;

    /* Old password editor */
    edit_item[e_idx].string_id = 0;
    edit_item[e_idx].default_text_id = 0;
    edit_item[e_idx].buffer_size = 60;
    edit_item[e_idx].input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
    edit_item[e_idx].input_extended_type = 0;
    edit_item[e_idx].required_input_mode_set = NULL;

    inline_item[i_idx].item_id = CMCC_PASSWORD_INLINE_ID_OLD_EDIT;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
    inline_item[i_idx].image_id = 0;
    inline_item[i_idx].item_data = &edit_item[e_idx];
    i_idx++;
    e_idx++;

    // New password 1
    /* Password1 caption */
    caption_item[c_idx].string_id = STR_CMCC_WLAN_NEW_PASSWORD;
    inline_item[i_idx].item_id = CMCC_PASSWORD_INLINE_ID_NEW1_CAPA;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[i_idx].image_id = 0;
    inline_item[i_idx].item_data = &caption_item[c_idx];
    i_idx++;
    c_idx++;

    /* Password1 editor */
    edit_item[e_idx].string_id = 0;
    edit_item[e_idx].default_text_id = 0;
    edit_item[e_idx].buffer_size = 60;
    edit_item[e_idx].input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
    edit_item[e_idx].input_extended_type = 0;
    edit_item[e_idx].required_input_mode_set = NULL;

    inline_item[i_idx].item_id = CMCC_PASSWORD_INLINE_ID_NEW1_EDIT;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
    inline_item[i_idx].image_id = 0;
    inline_item[i_idx].item_data = &edit_item[e_idx];
    i_idx++;
    e_idx++;

    // New password 2
    /* Password2 caption */
    caption_item[c_idx].string_id = STR_CMCC_WLAN_NEW_PASSWORD2;
    inline_item[i_idx].item_id = CMCC_PASSWORD_INLINE_ID_NEW2_CAPA;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_CAPTION;
    inline_item[i_idx].image_id = 0;
    inline_item[i_idx].item_data = &caption_item[c_idx];
    i_idx++;
    c_idx++;

    /* Password2 editor */
    edit_item[e_idx].string_id = 0;
    edit_item[e_idx].default_text_id = 0;
    edit_item[e_idx].buffer_size = 60;
    edit_item[e_idx].input_type = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
    edit_item[e_idx].input_extended_type = 0;
    edit_item[e_idx].required_input_mode_set = NULL;

    inline_item[i_idx].item_id = CMCC_PASSWORD_INLINE_ID_NEW2_EDIT;
    inline_item[i_idx].item_flag = CUI_INLINE_ITEM_TYPE_TEXT_EDIT;
    inline_item[i_idx].image_id = 0;
    inline_item[i_idx].item_data = &edit_item[e_idx];
    i_idx++;
    e_idx++;

    // Ready to run
    inline_cntx.items_count = i_idx;
    inline_cntx.title = STR_CMCC_WLAN_MODIFY_PASSWORD;
    inline_cntx.title_icon = 0;
    inline_cntx.screen_flag = CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE;
    inline_cntx.softkey = &softkey_item;
    inline_cntx.items = inline_item;

    cui_id = cui_inline_create(grp_id, &inline_cntx);
    g_cmcc_wlan_setting.sub_inline_id = cui_id;

    cui_inline_run(cui_id);
    return grp_id;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_loading_cancel
 * DESCRIPTION 
 *  cmcc wlan auth loading cancel
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_auth_loading_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_cmcc_wlan_setting.loading_type)
    {
    case CMCC_WLAN_LOADING_TYPE_SMS:
        srv_sms_abort_send(g_cmcc_wlan_setting.sms_handle);
        g_cmcc_wlan_setting.sms_state = 0;
        break;

    case CMCC_WLAN_LOADING_TYPE_LOGIN:
        cmcc_wlan_http_abort();
        cmcc_wlan_auth_ui_login_callback(CMCC_WLAN_AUTH_ABORTED);
        break;

    default:
        ASSERT(0);
        break;
    }

    mmi_frm_scrn_close(g_cmcc_wlan_setting.tmp_parent_id, SCR_ID_CMCC_WLAN_AUTH_LOADING_SCREEN);
}

/* Show loading screen */

/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_show_loading
 * DESCRIPTION 
 *  cmcc wlan auth show loading
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_auth_show_loading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cmcc_wlan_setting.tmp_parent_id == 0)
    {
        g_cmcc_wlan_setting.tmp_parent_id = GRP_ID_ROOT;
    }

    if (!mmi_frm_scrn_enter(
            g_cmcc_wlan_setting.tmp_parent_id,
            SCR_ID_CMCC_WLAN_AUTH_LOADING_SCREEN,
            NULL,
            cmcc_wlan_auth_show_loading,
            MMI_FRM_FULL_SCRN))
    {
        return;
    }

    switch (g_cmcc_wlan_setting.loading_type)
    {
    case CMCC_WLAN_LOADING_TYPE_SMS:
        str_id = STR_CMCC_WLAN_SMS_SEND_LOADING;
        break;

    case CMCC_WLAN_LOADING_TYPE_LOGIN:
        str_id = STR_CMCC_WLAN_HTTP_LOGIN_LOADING;
        break;

    default:
        return;
    }

    ShowCategory66Screen(
        STR_CMCC_WLAN_AUTH_MAIN,
        0,
        0,
        0,
        STR_GLOBAL_CANCEL,
        IMG_GLOBAL_BACK,
        (U8*)GetString(str_id),
        mmi_get_event_based_image(MMI_EVENT_PROGRESS),
        NULL);
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(cmcc_wlan_auth_loading_cancel, KEY_EVENT_UP);

    mmi_frm_scrn_set_leave_proc(
        g_cmcc_wlan_setting.tmp_parent_id,
        SCR_ID_CMCC_WLAN_AUTH_LOADING_SCREEN,
        cmcc_wlan_auth_loading_del_callback);
}

static mmi_ret cmcc_wlan_auth_loading_del_callback(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            cmcc_wlan_auth_loading_cancel();
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_close_loading
 * DESCRIPTION 
 *  cmcc wlan auth close loading
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_auth_close_loading(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(
        g_cmcc_wlan_setting.tmp_parent_id,
        SCR_ID_CMCC_WLAN_AUTH_LOADING_SCREEN);
    g_cmcc_wlan_setting.tmp_parent_id = 0;
}

/* Show popup screen */

/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_show_popup
 * DESCRIPTION 
 *  cmcc wlan auth show popup
 * PARAMETERS 
 *  U32 str_id
 *  mmi_event_notify_enum type
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_auth_show_popup(U32 str_id, mmi_event_notify_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cmcc_wlan_setting.tmp_parent_id == 0)
    {
        g_cmcc_wlan_setting.tmp_parent_id = GRP_ID_ROOT;
    }

    mmi_popup_property_init(&popup);
    popup.parent_id = g_cmcc_wlan_setting.tmp_parent_id;

    mmi_popup_display(
        (WCHAR*)GetString((U16)str_id),
        type,
        &popup);
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_show_confirm
 * DESCRIPTION 
 *  cmcc wlan auth show confirm
 * PARAMETERS 
 *  U32 confirm_type
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_auth_show_sms_confirm()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct conf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cmcc_wlan_setting.tmp_parent_id == 0)
    {
        g_cmcc_wlan_setting.tmp_parent_id = GRP_ID_ROOT;
    }

    mmi_confirm_property_init(&conf, CNFM_TYPE_YESNO);
    conf.parent_id = g_cmcc_wlan_setting.tmp_parent_id;
    conf.callback = cmcc_wlan_sms_confirm_callback;
    conf.user_tag = NULL;

    mmi_confirm_display(
        (WCHAR*)GetString(STR_CMCC_WLAN_CONFIRM_SMS),
        MMI_EVENT_QUERY,
        &conf);
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_sms_confirm_callback
 * DESCRIPTION 
 *  cmcc wlan sms confirm callback
 * PARAMETERS 
 *  mmi_event_struct *evt
 * RETURNS 
 *  static mmi_ret 
*****************************************************************************/
static mmi_ret cmcc_wlan_sms_confirm_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *alert_result_evt = (mmi_alert_result_evt_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (alert_result_evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alert_result_evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                cmcc_wlan_sms_send_go();
                break;

            default:
                break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_show_http_confirm
 * DESCRIPTION 
 *  cmcc wlan auth show http confirm
 * PARAMETERS 
 *  U32 confirm_type
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_auth_show_http_confirm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_cmcc_wlan_setting.tmp_parent_id == 0)
    {
        g_cmcc_wlan_setting.tmp_parent_id = GRP_ID_ROOT;
    }

    if (!mmi_frm_scrn_enter(
            g_cmcc_wlan_setting.tmp_parent_id,
            SCR_ID_CMCC_WLAN_AUTH_CONFIRM_SCREEN,
            NULL,
            cmcc_wlan_auth_show_http_confirm,
            MMI_FRM_SMALL_SCRN))
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    if (gui_buffer == NULL)
    {
        g_cmcc_wlan_setting.confirm_checked = g_cmcc_file_cntx.notify_auto;
    }

    wgui_cat3010_op01_show(
        (UI_string_type)GetString(STR_GLOBAL_YES),
        NULL,
        (UI_string_type)GetString(STR_GLOBAL_NO),
        NULL,
        (UI_string_type)GetString(STR_CMCC_WLAN_CONFIRM_AUTH),
        (UI_string_type)GetString(STR_CMCC_WLAN_NOTI_AUTH),
        cmcc_wlan_http_confirm_checkbox_callback,
        g_cmcc_wlan_setting.confirm_checked,
        gui_buffer);

    mmi_frm_scrn_set_leave_proc(
        g_cmcc_wlan_setting.tmp_parent_id,
        SCR_ID_CMCC_WLAN_AUTH_CONFIRM_SCREEN,
        cmcc_wlan_http_confirm_del_callback);

    SetLeftSoftkeyFunction(cmcc_wlan_http_confirm_yes, KEY_EVENT_UP);
    SetRightSoftkeyFunction(cmcc_wlan_http_confirm_no, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_confirm_checkbox_callback
 * DESCRIPTION 
 *  
 * PARAMETERS 
 *  MMI_BOOL checked
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_http_confirm_checkbox_callback(MMI_BOOL checked)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //g_cmcc_file_cntx.notify_auto = checked;
    //cmcc_file_save();

    g_cmcc_wlan_setting.confirm_checked = checked;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_confirm_yes
 * DESCRIPTION 
 *  cmcc wlan http confirm yes
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_http_confirm_yes(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cmcc_wlan_auth_ret_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(
        g_cmcc_wlan_setting.tmp_parent_id,
        SCR_ID_CMCC_WLAN_AUTH_CONFIRM_SCREEN);

    /* Save setting */
    if (g_cmcc_wlan_setting.confirm_checked != g_cmcc_file_cntx.notify_auto)
    {
        g_cmcc_file_cntx.notify_auto = g_cmcc_wlan_setting.confirm_checked;
        cmcc_file_save();
    }

    /* Go... */
    ret = cmcc_wlan_auth_go();
    if (ret != CMCC_WLAN_AUTH_WBLOCK)
    {
        cmcc_wlan_auth_ui_login_callback(ret);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_confirm_no
 * DESCRIPTION 
 *  cmcc wlan http confirm no
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_http_confirm_no(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close(
        g_cmcc_wlan_setting.tmp_parent_id,
        SCR_ID_CMCC_WLAN_AUTH_CONFIRM_SCREEN);
    cmcc_wlan_auth_ui_login_callback(CMCC_WLAN_AUTH_ABORTED);
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_http_confirm_del_callback
 * DESCRIPTION 
 *  cmcc wlan http confirm del callback
 * PARAMETERS 
 *  mmi_event_struct *evt
 * RETURNS 
 *  static mmi_ret 
*****************************************************************************/
static mmi_ret cmcc_wlan_http_confirm_del_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
            cmcc_wlan_auth_ui_login_callback(CMCC_WLAN_AUTH_ABORTED);
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_go
 * DESCRIPTION 
 *  cmcc wlan auth go
 * PARAMETERS 
 *  void
 * RETURNS 
 *  static void 
*****************************************************************************/
static cmcc_wlan_auth_ret_enum cmcc_wlan_auth_go(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cmcc_wlan_auth_ret_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = cmcc_wlan_http_login(cmcc_wlan_auth_ui_login_callback);
    if (ret == CMCC_WLAN_AUTH_WBLOCK)
    {
        g_cmcc_wlan_setting.tmp_parent_id = GRP_ID_ROOT;
        g_cmcc_wlan_setting.loading_type = CMCC_WLAN_LOADING_TYPE_LOGIN;
        cmcc_wlan_auth_show_loading();
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_setting_show
 * DESCRIPTION 
 *  cmcc wlan auth setting show
 * PARAMETERS 
 *  mmi_id parent_id
 * RETURNS 
 *  mmi_id 
*****************************************************************************/
mmi_id cmcc_wlan_auth_setting_show(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cmcc_wlan_auth_setting_screen(parent_id, FALSE);
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_setting_query
 * DESCRIPTION 
 *  cmcc wlan auth setting query
 * PARAMETERS 
 *  BOOL *saved
 *  BOOL *auto_login
 *  BOOL *notify_auto
 * RETURNS 
 *  void 
*****************************************************************************/
void cmcc_wlan_auth_setting_query(BOOL *saved, BOOL *auto_login, BOOL *notify_auto)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmcc_file_load();
    
    if (saved != NULL)
    {
        *saved = g_cmcc_file_cntx.saved;
    }

    if (notify_auto != NULL)
    {
        *notify_auto = g_cmcc_file_cntx.notify_auto;
    }
}


/*****************************************************************************
 * FUNCTION 
 *  *cmcc_wlan_auth_setting_get_user
 * DESCRIPTION 
 *  *cmcc wlan auth setting get user
 * PARAMETERS 
 *  void
 * RETURNS 
 *  const S8 
*****************************************************************************/
const CHAR *cmcc_wlan_auth_setting_get_user(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmcc_file_load();
    return (CHAR*)g_cmcc_file_cntx.username;
}


/*****************************************************************************
 * FUNCTION 
 *  *cmcc_wlan_auth_setting_get_pass
 * DESCRIPTION 
 *  *cmcc wlan auth setting get pass
 * PARAMETERS 
 *  void
 * RETURNS 
 *  const S8 
*****************************************************************************/
const CHAR *cmcc_wlan_auth_setting_get_pass(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cmcc_file_load();
    return (CHAR*)g_cmcc_file_cntx.password;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_login
 * DESCRIPTION 
 *  cmcc wlan auth login
 * PARAMETERS 
 *  mmi_id parent_id
 *  U32 wifi_daac_id
 *  cmcc_wlan_auth_callback cb
 * RETURNS 
 *  cmcc_wlan_auth_ret_enum 
*****************************************************************************/
cmcc_wlan_auth_ret_enum cmcc_wlan_auth_login(cmcc_wlan_auth_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cmcc_wlan_auth_ret_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGIN, cb);

    if (g_cmcc_wlan_setting.ui_activity != CMCC_WLAN_UI_ACTIVITY_NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGIN, -1);
        return CMCC_WLAN_AUTH_BUSY;
    }

    cmcc_file_load();

    g_cmcc_wlan_setting.cb = cb;
    g_cmcc_wlan_setting.ui_activity = CMCC_WLAN_UI_ACTIVITY_LOGIN;

    // Send message to ABM
    srv_dtcnt_wlan_send_portal_login_start_req(cmcc_wlan_http_get_abm_id());

    if (g_cmcc_file_cntx.saved)
    {
        /* Show confirm */
        if (g_cmcc_file_cntx.notify_auto)
        {
            g_cmcc_wlan_setting.tmp_parent_id = GRP_ID_ROOT;
            cmcc_wlan_auth_show_http_confirm();
        }
        else
        {
            ret = cmcc_wlan_auth_go();
            if (ret != CMCC_WLAN_AUTH_WBLOCK)
            {
                g_cmcc_wlan_setting.cb = NULL;
                g_cmcc_wlan_setting.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;

                // Send message to ABM
                srv_dtcnt_wlan_send_portal_login_stop_req(MMI_FALSE);
                return ret;
            }
        }
    }
    else
    {
        cmcc_wlan_auth_setting_screen(0, TRUE);
    }

    return CMCC_WLAN_AUTH_WBLOCK;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_ui_login_callback
 * DESCRIPTION 
 *  cmcc wlan auth ui callback
 * PARAMETERS 
 *  cmcc_wlan_auth_ret_enum ret
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_auth_ui_login_callback(cmcc_wlan_auth_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // Close loading
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_UI_LOGIN_CALLBACK, ret, g_cmcc_wlan_setting.cb);

    cmcc_wlan_auth_close_loading();
    if (g_cmcc_wlan_setting.ui_activity == CMCC_WLAN_UI_ACTIVITY_LOGIN)
    {
        if (g_cmcc_wlan_setting.cb != NULL)
        {
            g_cmcc_wlan_setting.cb(ret); 
            g_cmcc_wlan_setting.cb = NULL;

            if (ret == CMCC_WLAN_AUTH_OK || ret == CMCC_WLAN_AUTH_NO_NEED_LOGIN)
            {
                g_cmcc_wlan_setting.need_logout = MMI_TRUE;
            }
        }

        g_cmcc_wlan_setting.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;

        // Send message to ABM
        srv_dtcnt_wlan_send_portal_login_stop_req(ret == CMCC_WLAN_AUTH_OK || ret == CMCC_WLAN_AUTH_NO_NEED_LOGIN);
    }
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_logout
 * DESCRIPTION 
 *  cmcc wlan auth logout
 * PARAMETERS 
 *  cmcc_wlan_auth_callback cb
 * RETURNS 
 *  cmcc_wlan_auth_ret_enum 
*****************************************************************************/
cmcc_wlan_auth_ret_enum cmcc_wlan_auth_logout(cmcc_wlan_auth_callback cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cmcc_wlan_auth_ret_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGOUT, cb);

    if (g_cmcc_wlan_setting.ui_activity != CMCC_WLAN_UI_ACTIVITY_NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGOUT, -1);
        return CMCC_WLAN_AUTH_BUSY;
    }

    if (!g_cmcc_wlan_setting.need_logout)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGOUT, -2);
        return CMCC_WLAN_AUTH_OK;
    }
    g_cmcc_wlan_setting.need_logout = MMI_FALSE;

    ret = cmcc_wlan_http_logout(cmcc_wlan_auth_ui_logout_callback);
    if (ret != CMCC_WLAN_AUTH_WBLOCK)
    {
        // Send message to ABM
        srv_dtcnt_wlan_send_portal_logout_req();
        return ret;
    }

    g_cmcc_wlan_setting.cb = cb;
    g_cmcc_wlan_setting.ui_activity = CMCC_WLAN_UI_ACTIVITY_LOGOUT;

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_LOGOUT, ret);
    return ret;
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_ui_logout_callback
 * DESCRIPTION 
 *  cmcc wlan auth ui callback
 * PARAMETERS 
 *  cmcc_wlan_auth_ret_enum ret
 * RETURNS 
 *  static void 
*****************************************************************************/
static void cmcc_wlan_auth_ui_logout_callback(cmcc_wlan_auth_ret_enum ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_UI_LOGOUT_CALLBACK, ret, g_cmcc_wlan_setting.cb);

    if (g_cmcc_wlan_setting.ui_activity == CMCC_WLAN_UI_ACTIVITY_LOGOUT)
    {
        if (g_cmcc_wlan_setting.cb != NULL)
        {
            g_cmcc_wlan_setting.cb(ret);
            g_cmcc_wlan_setting.cb = NULL;
        }

        g_cmcc_wlan_setting.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;

        // Send message to ABM
        srv_dtcnt_wlan_send_portal_logout_req();
    }
}


/*****************************************************************************
 * FUNCTION 
 *  cmcc_wlan_auth_abort
 * DESCRIPTION 
 *  cmcc wlan auth abort
 * PARAMETERS 
 *  void
 * RETURNS 
 *  void 
*****************************************************************************/
void cmcc_wlan_auth_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_ABORT, g_cmcc_wlan_setting.ui_activity);

    if (g_cmcc_wlan_setting.ui_activity == CMCC_WLAN_UI_ACTIVITY_NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_ABORT, -1);
        return;
    }

    if (g_cmcc_wlan_setting.ui_activity == CMCC_WLAN_UI_ACTIVITY_LOGIN)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_ABORT, 1);

        g_cmcc_wlan_setting.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;
        g_cmcc_wlan_setting.cb = NULL;

        /* Abort HTTP session */
        cmcc_wlan_http_abort();

        /* Close confirm screen */
        mmi_frm_scrn_close(
            g_cmcc_wlan_setting.tmp_parent_id,
            SCR_ID_CMCC_WLAN_AUTH_CONFIRM_SCREEN);

        /* Close setting screen */
        CMCC_WLAN_FRM_CLOSE_GRP(g_cmcc_wlan_setting.grp_id);

        /* Close loading */
        cmcc_wlan_auth_close_loading();

        // Send message to ABM
        srv_dtcnt_wlan_send_portal_login_stop_req(MMI_FALSE);
        return;
    }

    if (g_cmcc_wlan_setting.ui_activity == CMCC_WLAN_UI_ACTIVITY_LOGOUT)
    {
        MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_ABORT, 2);

        g_cmcc_wlan_setting.ui_activity = CMCC_WLAN_UI_ACTIVITY_NULL;
        cmcc_wlan_http_abort();

        // Send message to ABM
        srv_dtcnt_wlan_send_portal_logout_req();

        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, WLAN_CMCC_FUNC_CMCC_WLAN_AUTH_ABORT, -100);
}


#endif /* __MMI_OP01_WIFI__ */
