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
 *  vapp_sso_prot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SSO_PROT_H__
#define __VAPP_SSO_PROT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#if defined(__MMI_SSO__)

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_page.h"
#include "vcp_text_editor.h"
#include "vcp_button.h"
#include "vcp_form.h"
#include "vcp_list_menu.h"
#include "vcui_sso_gprot.h"
#include "vcp_indicator_popup.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "PhbSrvGprot.h"
#include "SmsSrvGprot.h"
#include "SsoSrvGprot.h"
#include "mmi_inet_app_trc.h"

#ifdef __cplusplus
}
#endif

#ifdef __VCARD_CLOUD_SUPPORT__
#define SSO_SUPPORT_CONTACTS
#endif

#ifdef __SMS_CLOUD_SUPPORT__
#define SSO_SUPPORT_SMS
#endif

#define VAPP_SSO_TRACE0(tr)                  MMI_TRACE(TRACE_GROUP_7, tr)
#define VAPP_SSO_TRACE1(tr, a1)              MMI_TRACE(TRACE_GROUP_7, tr, a1)
#define VAPP_SSO_TRACE2(tr, a1, a2)          MMI_TRACE(TRACE_GROUP_7, tr, a1, a2)
#define VAPP_SSO_TRACE3(tr, a1, a2, a3)      MMI_TRACE(TRACE_GROUP_7, tr, a1, a2, a3)
#define VAPP_SSO_TRACE4(tr, a1, a2, a3, a4)  MMI_TRACE(TRACE_GROUP_7, tr, a1, a2, a3, a4)
#define VAPP_SSO_TRACE6(tr, a1, a2, a3, a4, a5, a6)  MMI_TRACE(TRACE_GROUP_7, tr, a1, a2, a3, a4, a5, a6)

typedef struct _vapp_sso_wizard_args
{   
    VfxU8 accountId;
    VfxU32 provider;
} vapp_sso_wizard_args;

class VappSso : public VfxApp
{
    VFX_DECLARE_CLASS(VappSso);
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onRun(void* args, VfxU32 argSize);
private:
    void onLoginCb(VfxPage *page, vcui_sso_login_result_enum result, VfxS32 err);
    static mmi_ret Listener(mmi_event_struct* evt);
    void handleListener(mmi_event_struct* evt);

private:
    VfxU8      m_account;
    VfxU32     m_provider;
    VfxMainScr *m_scr;
};

class VappSsoAccountPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappSsoAccountPage);

public:
    VappSsoAccountPage();
    VappSsoAccountPage(VfxU32 provider, VfxU8 accountId);

private:
    void onItemTap(VcpFormItemCell* cell, VfxId cell_id);
    static void onSsoLogoutCb(S32 reg_id, srv_sso_result result, void *userdata);
    void handleSsoLogoutCb(srv_sso_result result);
    void showProcessingPop(VfxWString str);
    void onCancelProcessing(VfxObject *obj, VfxFloat processing);
    static mmi_ret Listener(mmi_event_struct* evt);

    enum
	{
		ID_SSO_BACKUP = 1,
		ID_SSO_RESTORE,
        ID_SSO_LOGOUT,

        ID_SNS_END
	};
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
private:
    VfxU8         m_accountId;
    VfxS32        m_reqId;
    VfxU32        m_provider;
    VcpForm       *m_form;
    VcpFormItemLauncherCell *m_backup;
    VcpFormItemLauncherCell *m_restore;
    VcpFormItemLauncherCell *m_logout;
    VcpIndicatorPopup *m_processing;
};

#if defined(__CLOUD_SUPPORT__)
class VappSsoBackupRestorePage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSsoBackupRestorePage);

public:
    VappSsoBackupRestorePage();
    VappSsoBackupRestorePage(VfxU32 provider, VfxU8 accountId, VfxBool isBackup, VfxBool wizard);

    static void* onAsmMallocCB(VfxU32 size);
    static void onAsmFreeCB(void* ptr);
public:
    // <group DOM_ListMenu_IVcpListMenuContentProvider_Overridable>
    // Get the text resource for the text fields of list cell
    // RETURNS: VFX_TRUE or VFX_FALSE
    virtual VfxBool getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        );

    virtual VfxU32 getCount() const;

    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

private:
    void onItemTapped(VcpListMenu *list_menu, VfxU32 index);
    void onMenuButtonTap(VfxObject *sender, VfxId id);
    static void onPhbBackupCb(srv_phb_async_op_cb_struct* info);
    void handlePhbBackupCb(srv_phb_async_op_cb_struct* info);
    static void onSmsBackupCb(srv_sms_callback_struct* callback_data);
    void handleSmsBackupCb(srv_sms_callback_struct* callback_data);
    static void onPhbRestoreCb(srv_phb_async_op_cb_struct* info);
    void handlePhbRestoreCb(srv_phb_async_op_cb_struct* info);
    static void onSmsRestoreCb(srv_sms_callback_struct* callback_data);
    void handleSmsRestoreCb(srv_sms_callback_struct* callback_data);
    static mmi_ret Listener(mmi_event_struct* evt);

    void showProcessing(VfxWString &str);
    void onCancel(VfxObject *obj, VfxFloat processing);
    void cancelBackRestore();
    void showErrorMsg();

    U8* handleAsmMallocCB(VfxU32 size);
    void handleAsmFreeCB(void* ptr);
#define SSO_BACKUP_RESTORE_SELECTED_SET(f, b) ((f) |= (1 << (b)))
#define SSO_BACKUP_RESTORE_SELECTED_CLEAR(f, b) ((f) &= ~(1 << (b)))
#define SSO_BACKUP_RESTORE_SELECTED_IS_SET(f, b) ((f) & (1 << (b)))

private:
    enum
    {
        ID_CLOUD_CONTACTS,
        ID_CLOUD_SMS,

        ID_CLOUD_TOTAL
    };
    enum
    {
        ID_SSO_TOOLBAR_BACKUP = 1,
        ID_SSO_TOOLBAR_RESTORE,
        ID_SSO_TOOLBAR_CANCEL,

        ID_SSO_TOOLBAR_TOTAL
    };
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
private:
    VfxU8         m_appCount;
    VfxU8         m_accountId;
    VfxBool       m_isBackup;
    VfxBool       m_wizard;
    VfxS32        m_phbErr;
    VfxS32        m_smsErr;
    VfxU32        m_provider;
    VfxU32        m_selected;
    VfxU32        m_done;
    VcpListMenu   *m_list;
    VcpToolBar    *m_toolbar;
    VfxWeakPtr<VcpIndicatorPopup> m_processing;
    srv_phb_handle m_phbHdlr;
    SMS_HANDLE     m_smsHdlr;
    VfxChar       *m_serviceName;
    static VappSsoBackupRestorePage* m_context;
};
#endif

#endif /* __MMI_SSO__ */
#endif /* __VAPP_SSO_PROT_H__ */
