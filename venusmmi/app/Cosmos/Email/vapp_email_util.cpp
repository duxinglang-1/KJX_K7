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
 *  Vapp_email_setting.cpp
 *
 * Project:
 * --------
 *  COSMOS Email Account Global Setting
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

#include "vapp_email_util.h"
#include "vapp_email_main.h"
#include "vcp_global_popup.h"
extern "C"{
#include "App_mine.h"
#include "App_UseDetails.h"
#include "soc_api.h"
#include "FileMgrSrvGprot.h"
#include "che_api.h"
#include "mmi_rp_app_cosmos_global_def.h"
}

/****************** Single Select Page ******************/
VappEmailListSingleSelectTmplPage::
    VappEmailListSingleSelectTmplPage(VfxBool hasTBar)
    :
    m_itemCount(0),
    m_initSelectIndex(0),
    m_selectedIndex(0),
    hasToolBar(hasTBar),
    needPopPage(VFX_TRUE),
    style(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK)
{
}


void VappEmailListSingleSelectTmplPage::onInit(void)
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(m_topBar, VcpTitleBar, this);
    setTopBar(m_topBar);

    if (hasToolBar)
    {
        VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
        setBottomBar(m_toolBar);
        m_toolBar->m_signalButtonTap.connect(
            this,
            &VappEmailListSingleSelectTmplPage::onToolBarClick);
    }

    VFX_OBJ_CREATE(m_menu, VcpListMenu, this);
    m_menu->setContentProvider(this);
    m_menu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_menu->setMenuMode(style, VFX_TRUE);
    m_menu->m_signalItemTapped.connect(
        this,
        &VappEmailListSingleSelectTmplPage::onItemTapped);
    m_menu->setRect(0, 0, getSize().width, getSize().height);
    m_menu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
}

void VappEmailListSingleSelectTmplPage::setListItem(
    VfxU32 count,
    VfxResId titleRes,
    VfxResId itemTextRes[])
{
    VFX_ASSERT(count <= SUPPORT_MAX_ITEM);
    
    m_itemCount = count;
    m_topBar->setTitle(VFX_WSTR_RES(titleRes));
    for (VfxU32 i = 0; i < count; ++i)
    {
        m_itemTextRes[i] = itemTextRes[i];
    }
}

void VappEmailListSingleSelectTmplPage::setInitSelectItem(VfxU32 index)
{
    m_initSelectIndex = index;
    m_selectedIndex = index;
}

void VappEmailListSingleSelectTmplPage::setMenuMode(VcpListMenuModeEnum s)
{
    style = s;
    m_menu->setMenuMode(style, VFX_TRUE);
}

void VappEmailListSingleSelectTmplPage::setNoPopPage()
{
    needPopPage = VFX_FALSE;
}

void VappEmailListSingleSelectTmplPage::onItemTapped(VcpListMenu *, VfxU32 index)
{
    if (index == this->m_selectedIndex)
    {
        if (needPopPage)
        {
        getMainScr()->popPage();
    }
    }
    else
    {
        this->m_selectedIndex = index;
        m_signal_save.emit(this, this->m_selectedIndex);
    }
}

VcpListMenuItemStateEnum VappEmailListSingleSelectTmplPage::getItemState(
    VfxU32 index) const
{
    if (index == m_initSelectIndex)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }

    return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

VfxBool VappEmailListSingleSelectTmplPage::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color)
{
    VFX_ASSERT(index < m_itemCount && index < SUPPORT_MAX_ITEM);
    
    text = VFX_WSTR_RES(m_itemTextRes[index]);
    return VFX_TRUE;
}

VfxU32 VappEmailListSingleSelectTmplPage::getCount() const
{
    return m_itemCount;
}

void VappEmailListSingleSelectTmplPage::setToolBar(
    VfxId id1, VfxResId text1, VfxResId img1,
    VfxId id2, VfxResId text2, VfxResId img2)
{
    m_toolBar->addItem(id1, VFX_WSTR_RES(text1), img1);
    m_toolBar->addItem(id2, VFX_WSTR_RES(text2), img2);
}

void VappEmailListSingleSelectTmplPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    m_signal_toolbar_Tap.emit(obj, id, this->m_selectedIndex);
}

void VappEmailSimpleInputTmplPage::onInit(void)
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(m_topBar, VcpTitleBar, this); 
    setTopBar(m_topBar);

    VcpToolBar *m_toolBar;
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->m_signalButtonTap.connect(
        this,
        &VappEmailSimpleInputTmplPage::onToolBarClick);
    m_toolBar->addItem(
        'OK',
        VFX_WSTR_RES(STR_GLOBAL_OK),
        IMG_EMAIL_FTO_SAVE);
    m_toolBar->addItem(
        'CNCL',
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        IMG_EMAIL_FTO_CANCEL);
    setBottomBar(m_toolBar);

    VFX_OBJ_CREATE(m_labelTop, VfxTextFrame, this);
    m_labelTop->setPos(
        VcpFormItemLabeledControl::LEFT_GAP,
        VcpFormItemLabeledControl::TOP_GAP);
    m_labelTop->setSize(getSize().width, FONT_SMALL);
    m_labelTop->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(FONT_SMALL)));
    m_labelTop->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));

    VFX_OBJ_CREATE(m_textEditor, VcpTextEditor, this);    
    VFX_OBJ_CREATE(m_labelRight, VfxTextFrame, this);    
    m_labelRight->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
}

void VappEmailSimpleInputTmplPage::setItem(
    VfxResId titleRes, VfxResId leftTopRes,
    VfxBool hasRightLable, const VfxWString &rightLableStr)
{
    m_topBar->setTitle(VFX_WSTR_RES(titleRes));
    m_labelTop->setString(VFX_WSTR_RES(leftTopRes));

    m_textEditor->setPos(VcpFormItemLabeledControl::LEFT_GAP, 
        m_labelTop->getRect().getMaxY() + VcpFormItemLabeledControl::TOP_GAP);
    if (hasRightLable)
    {
        m_textEditor->setSize(
            getRect().size.width - 80,
            VCPFRM_STANDARD_BTN_HEIGHT);

        m_labelRight->setString(rightLableStr);

        m_labelRight->setPos(
            m_textEditor->getRect().getMaxX() +
                VcpFormItemLabeledControl::LEFT_GAP,
            m_labelTop->getRect().getMaxY() +
                VcpFormItemLabeledControl::TOP_GAP + 11);

        m_labelRight->setSize(
            getRect().getWidth() - VcpFormItemLabeledControl::LEFT_GAP,
            VCPFRM_STANDARD_BTN_HEIGHT);
    }
    else
    {
        m_textEditor->setSize(
            getRect().size.width - VcpFormItemLabeledControl::LEFT_GAP * 2,
            VCPFRM_STANDARD_BTN_HEIGHT);
        m_labelRight->setSize(0, 0);
    }
}

void VappEmailSimpleInputTmplPage::setItem(
    VfxResId titleRes,
    VfxResId leftTopRes,
    VfxBool hasRightLable,
    VfxResId rightLableRes)
{
    setItem(titleRes, leftTopRes, hasRightLable, VFX_WSTR_RES(rightLableRes));
}

void VappEmailSimpleInputTmplPage::setText(
    const VfxWString& text,
    VfxU32 max_len)
{
    VFX_ASSERT(max_len <= 128);
    editorText = text;
    m_textEditor->setText((VfxWChar*)editorText.getBuf(), max_len);
}

void VappEmailSimpleInputTmplPage::setEditorIME(VfxU64 ime)
{
    m_textEditor->setIME(ime, IME_SETTING_FLAG_NONE);
}

void VappEmailSimpleInputTmplPage::onToolBarClick(VfxObject *obj, VfxId id)
{
    switch(id)
    {
        case 'OK':
        {
            editorText.loadFromMem(m_textEditor->getText());
            m_signal_save.emit(this, editorText);
            break;
        }
        case 'CNCL':
        {
            getMainScr()->popPage();
            break;
        }
    }
}

static MMI_BOOL vapp_email_util_pop_nmgr_handler(mmi_scenario_id scen_id, void *arg)
{
    VfxS32 handle = VCP_GLOBAL_POPUP_INVALID_HANDLE;
    handle = vcp_global_popup_show_confirm_one_button_id(
        GRP_ID_ROOT, VCP_POPUP_TYPE_FAILURE, (VfxResId)arg, STR_GLOBAL_OK, 
        VCP_POPUP_BUTTON_TYPE_NORMAL, NULL, NULL);
    VFX_OBJ_GET_INSTANCE(VappEmailMgr)->addGlobalPopHandle(handle);
    return MMI_TRUE;
}

void vapp_email_alert_cfm(VfxResId resId)
{
    mmi_frm_nmgr_notify_by_app(
        MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_FAILURE,
        (mmi_noti_scrn_func_ptr)vapp_email_util_pop_nmgr_handler,
        (void*)resId);
}

void vapp_email_indicator_pop(VcpIndicatorPopup **ind, 
    const VfxWString &str, VfxPage *page, VcpIndicatorPopupStyleEnum type)
{
    VFX_OBJ_CREATE((*ind), VcpIndicatorPopup, page);
    (*ind)->setInfoType(type);
    (*ind)->setText(str);
    (*ind)->setAutoDestory(VFX_TRUE);
    (*ind)->show(VFX_TRUE);
}

void vapp_email_indicator_pop(VcpIndicatorPopup **i,
    VfxResId r,
    VfxPage *p,
    VcpIndicatorPopupStyleEnum t)
{
    vapp_email_indicator_pop(i, VFX_WSTR_RES(r), p, t);
}


VcpFormItemTextInput* vapp_email_create_text_input_form_item(
    VfxWString labelText,
    VfxWChar *text,
    VfxS32 maxLen,
    VfxU64 inputType, 
    VfxU32 inputSetting,
    VfxBool isAutoDeactivated,
    VfxFrame *funcBar,
    VcpForm *parentForm)
{
    VcpFormItemTextInput *textInput;

    VFX_OBJ_CREATE(textInput , VcpFormItemTextInput, parentForm);
    textInput->setLabelText(labelText);
    textInput->setLabelPosition(VCPFORM_TOP_LEFT);

    VcpTextEditor *textBox = textInput->getTextBox();
    textBox->setAutoDeactivated(isAutoDeactivated);
    textBox->setText(text, maxLen);
    textBox->setFunctionBar(funcBar);
    textBox->setIME(inputType, inputSetting);
    
    return textInput;
}

void vapp_email_set_titlebar(VfxResId title_res_id, VfxPage * page)
{
    VcpTitleBar *m_topBar;
    VFX_OBJ_CREATE(m_topBar, VcpTitleBar, page);	
    m_topBar->setTitle(VFX_WSTR_RES(title_res_id));
    page->setTopBar(m_topBar);
}

void vapp_email_set_titlebar(const VfxWString &titleStr, VfxPage * page)
{
    VcpTitleBar *m_topBar;
    VFX_OBJ_CREATE(m_topBar, VcpTitleBar, page);	
    m_topBar->setTitle(titleStr);
    page->setTopBar(m_topBar);
}

void vapp_email_util_nmgr_balloon(VfxResId resId)
{
    mmi_frm_nmgr_balloon(
        MMI_SCENARIO_ID_DEFAULT,
        MMI_EVENT_INFO_BALLOON,
        MMI_NMGR_BALLOON_TYPE_INFO,
        (WCHAR*)(GetString(resId)));
}

VfxBool vapp_email_util_server_port_is_valid(VfxU32 port)
{
    return port > 0 && port < 65536;
}

WCHAR *vapp_email_util_get_file_ext(WCHAR *file_name)
{
    S32 length = 0;
    WCHAR *file_ptr = NULL;
    
    length = mmi_wcslen(file_name);
    if (length) /* in case empty filename */
    {
        --length;
        
        if (file_name[0] == L'.')
        {
            return file_name;
        }
        // could use {mmi_wcsstr}
        while (length)
        {
            if (file_name[length] == L'.')
            {
                break;
            }
            else
            {
                length -= 1;
            }
        }
        
        if (length) /* in case no file extension */
        {
            file_ptr = file_name + length;
        }
    }
    
    return file_ptr;
}

void vapp_email_util_get_mine_type(
    const WCHAR *filename,
    S32 *mime_type,
    S32 *mime_subtype)
{
    WCHAR *fileExtPtr = vapp_email_util_get_file_ext((WCHAR *)filename);
    CHAR *fileExt = (CHAR*)OslMalloc(
                        (SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1) * ENCODING_LENGTH);
    S32 extLen = 0;
    applib_mime_type_struct *mimeTypePtr = NULL;
    
    memset(fileExt, 0, (SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1) * ENCODING_LENGTH);
    if (fileExtPtr)
    {
        /* neglect "." */   // ignore {.} and convert to {ASCII}
        fileExtPtr = fileExtPtr + 1;
        extLen =
            (((SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1) > (mmi_wcslen(fileExtPtr))) ?
                (mmi_wcslen(fileExtPtr)) :
                (SRV_FMGR_PATH_MAX_FILE_EXT_LEN + 1));

        mmi_ucs2_n_to_asc(
            fileExt,
            (CHAR*)fileExtPtr,
            (U32)(extLen * ENCODING_LENGTH));
    }
    if (strlen(fileExt))
    {
        mimeTypePtr = applib_mime_type_look_up(
                        NULL,
                        fileExt,
                        MIME_TYPE_NONE,
                        MIME_SUBTYPE_NONE);
    }
    if (mimeTypePtr != NULL)
    {
        *mime_type = mimeTypePtr->mime_type;
        *mime_subtype = mimeTypePtr->mime_subtype;
    }
    else
    {
        *mime_type = MIME_TYPE_UNKNOWN;
        *mime_subtype = MIME_SUBTYPE_UNRECOGNIZED;
    }
    OslMfree(fileExt);
}

VfxBool vapp_email_util_is_server_vaild(const VfxWChar *server)
{
    kal_bool ip_validity = KAL_FALSE;
    kal_uint8 ip_addr[4];
    kal_char in_server[(SRV_EMAIL_MAX_SERVER_NAME_LEN + 1)];

    if(server == NULL || server[0] == '.' || server[0] == 0)
    {
        return VFX_FALSE;
    }
    
    mmi_ucs2_to_asc(in_server, (char*)server);
    if ((soc_ip_check(in_server, ip_addr, &ip_validity) == TRUE) &&
        (ip_validity == FALSE))
    {
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

VfxBool vapp_email_util_chk_addr(const VfxWChar *mailAddr)
{
    return applib_is_valid_email_address_unicode((kal_wchar*)mailAddr) == KAL_TRUE;
}

VfxBool vapp_email_util_chk_addr_ex(WCHAR *mailAddr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0, j = 0;
    WCHAR *temp_str = NULL;
    VfxBool has_space = FALSE;
    U32 src_len = mmi_wcslen(mailAddr);
	MMI_BOOL result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_str = (WCHAR*)OslMalloc((src_len + 1) * sizeof(WCHAR));
    memset(temp_str, 0, (src_len + 1) * sizeof(WCHAR));
    for (; i < src_len; )
    {
        if (!(mailAddr[i] == L' '))
        {
            temp_str[j] = mailAddr[i];
            j += 1;
        }
        else
        {
            has_space = TRUE;
        }
        i += 1;
    }
    if (has_space)
    {
        mmi_wcscpy(mailAddr, temp_str);
    }
    OslMfree(temp_str);

    result = applib_is_valid_email_address_unicode((kal_wchar*)mailAddr);
    return (result ? VFX_TRUE : VFX_FALSE);
}

void vapp_email_util_comp_md5(const CHAR *input, S32 input_len, U8* digest)
{
    static STCHE che_cntx;

    che_init(&che_cntx, CHE_MD5);
    che_process(
        &che_cntx,
        CHE_MD5,
        CHE_MODE_NULL,
        CHE_HASH,
        (U8*)input,
        digest,
        input_len,
        KAL_TRUE);
    che_deinit(&che_cntx);
}

VfxBool vapp_email_util_dir_exist(const WCHAR *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = FS_Open(path, FS_OPEN_DIR | FS_READ_ONLY);
    if (handle >= FS_NO_ERROR)
    {
        FS_Close(handle);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxS32 vapp_email_util_file_exist(const WCHAR *path, VfxBool *exist)
{
    *exist = VFX_FALSE;
    
    FS_HANDLE hd = FS_Open(path, FS_READ_ONLY);

    if (hd < FS_NO_ERROR)
    {
        return hd;
    }
    FS_Close(hd);

    *exist = VFX_TRUE;
    return 0;
}

VfxS32 vapp_email_util_file_get_size(const WCHAR *path, VfxU32 *size)
{
    *size = 0;
    
    FS_HANDLE hd = FS_Open(path, FS_READ_ONLY);
    if (hd < FS_NO_ERROR)
    {
        return hd;
    }

    FS_GetFileSize(hd, size);
    FS_Close(hd);

    return 0;
}

VfxBool vapp_email_drm_is_file_lock(WCHAR* file_name, VfxBool *is_drm_file)
{
#ifdef __DRM_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 method = DRM_METHOD_NONE;
    FS_HANDLE handle;
    VfxBool can_fwd = FALSE;
    VfxBool temp_is_drm_file = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = DRM_open_file(
                (PU16)file_name,
                FS_READ_ONLY | FS_OPEN_SHARED, DRM_PERMISSION_NONE);
    if (handle >= FS_NO_ERROR)
    {
        if ((method = DRM_get_object_method(handle, NULL)) == DRM_METHOD_NONE)
        {
            /* non DRM file, can forward to anywhere */
            can_fwd = TRUE;
            temp_is_drm_file = FALSE;
        }
        else
        {
            if (method & DRM_METHOD_V2)
            {
                can_fwd = TRUE;
                temp_is_drm_file = FALSE;
            }
            else
            {
                temp_is_drm_file = TRUE;

                if (method & DRM_METHOD_SEPARATE_DELIVERY)
                {
                    can_fwd = TRUE;
                }
                else
                {
                    can_fwd = FALSE;
                }
            }
        }
        DRM_close_file(handle);
    }
    else
    {
        can_fwd = FALSE;
        /* CD or FL without right */
        if (handle == DRM_RESULT_NO_PERMISSION)
        {
            temp_is_drm_file = TRUE;
        }
        else
        {
            temp_is_drm_file = FALSE;
        }
    }
    if (is_drm_file != NULL)
    {
        *is_drm_file = (temp_is_drm_file == TRUE);
    }
    return (can_fwd == TRUE);
#else /* __DRM_SUPPORT__ */
    *is_drm_file = VFX_FALSE;
    return VFX_FALSE;
#endif /* __DRM_SUPPORT__ */ 
}


U16 vapp_email_util_get_err_code(S32 major, S32 minor)
{
    S16 i = 0, entry = 0;

    switch (major)
    {
        case SRV_EMAIL_MAIL_ERROR:
        {
            if (minor == SRV_EMAIL_RESULT_FS_ERROR)
            {
                return srv_fmgr_fs_error_get_string(srv_email_errno_get());
            }

            entry = sizeof(email_err_tbl) / sizeof(email_app_err_struct);

            // loop the error table to match the minor
            for (i = 0; i < entry; i++)
            {
                if (email_err_tbl[i].err_no == minor)
                {
                    return email_err_tbl[i].str_id;
                }
            }
            return STR_EMAIL_ERROR_CODE_OPT_FAIL_ID;
        }
        case SRV_EMAIL_SOCKET_ERROR:
#ifdef __SSL_SUPPORT__
        case SRV_EMAIL_TLS_ERROR:
#endif
            return STR_EMAIL_ERROR_CODE_NETWORK_ID;
        case SRV_EMAIL_FS_ERROR:
        case SRV_EMAIL_RESULT_FS_ERROR:
            return srv_fmgr_fs_error_get_string(minor);
        case SRV_EMAIL_DRM_ERROR:
        default:
            return STR_EMAIL_ERROR_CODE_OPT_FAIL_ID;
    }
}

srv_email_result_enum vapp_email_util_get_fldr_id_by_acct(
                        EMAIL_ACCT_ID acct_id, 
                        S32 count,
                        S32 *folder_type, 
                        EMAIL_FLDR_ID *fldr_id)
{
    EMAIL_ACCT_HANDLE acct_handle = 0;
    srv_email_result_enum result = SRV_EMAIL_RESULT_SUCC;
    S32 fldr_count = 1;
    S32 index = 0;

    result = srv_email_acct_create(0, &acct_handle);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        VEMAIL_TRC_COMP_ACCT_CREATE(result);
        return result;
    }
    
    result = srv_email_acct_open(acct_handle, acct_id);
    if (result != SRV_EMAIL_RESULT_SUCC)
    {
        VEMAIL_TRC_COMP_ACCT_OPEN(result, acct_id);
        srv_email_acct_destroy(acct_handle);
        return result;
    }
    
    for (; index < count; index++)
    {
        result = srv_email_acct_get_fldr_id(
                    acct_handle, 
                    SRV_EMAIL_ACCT_FLDR_TYPE_BASIC,
                    folder_type[index], 
                    &fldr_count,
                    &(fldr_id[index]));

        if (result != SRV_EMAIL_RESULT_SUCC)
        {
            VEMAIL_TRC_COMP_ACCT_GET_FLDR_ID(result);
            srv_email_acct_destroy(acct_handle);
            return result;
        }
    }
    srv_email_acct_destroy(acct_handle);
    return SRV_EMAIL_RESULT_SUCC;
}

// Check Email environment, whether can send Email
VfxBool vapp_email_util_check_env(void)
{
    VappEmailStateEnum emailState =
        VappEmailMgr::getInstance()->getEmailAppState();

    if (emailState == VAPP_EMAIL_STATE_DEINITED ||
        emailState == VAPP_EMAIL_STATE_INITIALIZING ||
        emailState == VAPP_EMAIL_STATE_USB_MODE ||
        emailState == VAPP_EMAIL_STATE_TCARD_OUT)
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

