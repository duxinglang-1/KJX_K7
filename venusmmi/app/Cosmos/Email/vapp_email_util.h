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
 *  Vapp_email_util.h
 *
 * Project:
 * --------
 *  COSMOS Email utillty
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

#ifndef _VAPP_EMAIL_UTIL_H_
#define _VAPP_EMAIL_UTIL_H_

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
extern "C" {
#include "EmailAppGprot.h"
#include "EmailSrvGprot.h"
#ifdef __DRM_SUPPORT__
#include "Drm_gprot.h"
#include "RightsMgrResDef.h"
#include "RightsMgrGProt.h"
#endif /* __DRM_SUPPORT__ */
}
#include "vapp_email_prot.h"

class VappEmailListSingleSelectTmplPage
        : public VfxPage, public IVcpListMenuContentProvider
{
public:
    VappEmailListSingleSelectTmplPage(){};
    explicit VappEmailListSingleSelectTmplPage(VfxBool hasTBar);
    
    virtual void onInit();
    
    virtual void onQueryRotateEx(VfxScreenRotateParam &param)
    {
    }
    
    void setListItem(VfxU32 count, VfxResId titleRes, VfxResId itemTextRes[]);

    void setToolBar(
            VfxId id1, VfxResId text1, VfxResId img1,
            VfxId id2, VfxResId text2, VfxResId img2);

    void setInitSelectItem(VfxU32 index);

    void setMenuMode(VcpListMenuModeEnum style);

    void setNoPopPage();

    VfxSignal2 <VfxObject*, VfxS32> m_signal_save;

    VfxSignal3 <VfxObject*, VfxId, VfxS32> m_signal_toolbar_Tap;

    void onToolBarClick(VfxObject *obj, VfxId id);
    
    void onItemTapped(VcpListMenu *, VfxU32 index);

    virtual VfxBool getItemText(
                        VfxU32 index,
                        VcpListMenuFieldEnum fieldType,
                        VfxWString &text,
                        VcpListMenuTextColorEnum &color);
    
    virtual VfxU32 getCount() const;
    
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
    
private:
    static const VfxU32 SUPPORT_MAX_ITEM = 10;
    VcpTitleBar *m_topBar;
    VcpToolBar *m_toolBar;
    VcpListMenu *m_menu;
    VfxResId m_titleTextRes;
    VfxResId m_itemTextRes[SUPPORT_MAX_ITEM];
    VfxU32 m_itemCount;
    VfxU32 m_initSelectIndex;
    VfxU32 m_selectedIndex;
    VfxBool hasToolBar;
    VfxBool needPopPage;
    VcpListMenuModeEnum style;
};


class VappEmailSimpleInputTmplPage : public VfxPage
{
public:
    virtual void onInit();
    
    void setItem(
            VfxResId titleRes,
            VfxResId leftTopRes,
            VfxBool hasRightLable,
            const VfxWString &rightLableStr);

    void setItem(
            VfxResId titleRes,
            VfxResId leftTopRes,
            VfxBool hasRightLable,
            VfxResId rightLableRes);

    void setText(const VfxWString& text, VfxU32 max_len);
    void setEditorIME(VfxU64 ime);
    
    VfxSignal2 <VfxObject*, const VfxWString&> m_signal_save;

private:
    void onToolBarClick(VfxObject *obj, VfxId id);
    
private:
    VcpTitleBar *m_topBar;
    VfxTextFrame *m_labelTop;
    VcpTextEditor *m_textEditor;
    VfxTextFrame *m_labelRight;
    VfxWString editorText;
};

void vapp_email_alert_cfm(VfxResId redId);

void vapp_email_indicator_pop(
    VcpIndicatorPopup **ind, VfxResId resId,
    VfxPage *page,
    VcpIndicatorPopupStyleEnum type = VCP_INDICATOR_POPUP_STYLE_ACTIVITY);

void vapp_email_indicator_pop(
    VcpIndicatorPopup **ind,
    const VfxWString &str,
    VfxPage *page,
    VcpIndicatorPopupStyleEnum type = VCP_INDICATOR_POPUP_STYLE_ACTIVITY);

VcpFormItemTextInput* vapp_email_create_text_input_form_item(
    VfxWString labelText,
    VfxWChar *text,
    VfxS32 maxLen,
    VfxU64 inputType, 
    VfxU32 inputSetting,
    VfxBool isAutoDeactivated,
    VfxFrame *funcBar,
    VcpForm *parentForm);

void vapp_email_set_titlebar(VfxResId title_res_id, VfxPage *page);
void vapp_email_set_titlebar(const VfxWString &titleStr, VfxPage *page);

void vapp_email_util_nmgr_balloon(VfxResId resId);

VfxBool vapp_email_util_server_port_is_valid(VfxU32 port);

void vapp_email_util_get_mine_type(
        const WCHAR *filename,
        S32 *mime_type,
        S32 *mime_subtype);

VfxBool vapp_email_util_is_server_vaild(const VfxWChar *server);

VfxBool vapp_email_util_chk_addr(const VfxWChar *mailAddr);

VfxBool vapp_email_util_chk_addr_ex(WCHAR *mailAddr);

void vapp_email_util_comp_md5(const CHAR *input, S32 input_len, U8* digest);

VfxBool vapp_email_util_dir_exist(const WCHAR *path);

VfxS32 vapp_email_util_file_exist(const WCHAR *path, VfxBool *exist);

VfxS32 vapp_email_util_file_get_size(const WCHAR *path, VfxU32 *size);

VfxBool vapp_email_drm_is_file_lock(WCHAR* file_name, VfxBool *is_drm_file);

U16 vapp_email_util_get_err_code(S32 major, S32 minor);

srv_email_result_enum vapp_email_util_get_fldr_id_by_acct(
                        EMAIL_ACCT_ID acct_id, 
                        S32 count,
                        S32 *folder_type, 
                        EMAIL_FLDR_ID *fldr_id);

VfxBool vapp_email_util_check_env(void);

#endif /* _VAPP_EMAIL_UTIL_H_ */

