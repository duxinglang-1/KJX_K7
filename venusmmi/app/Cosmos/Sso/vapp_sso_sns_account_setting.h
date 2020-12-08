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
 *  vapp_sso_sns_account_setting.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SSO_SNS_ACCOUNT_SETTING_H__
#define __VAPP_SSO_SNS_ACCOUNT_SETTING_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#if defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_SSO__)

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_page.h"
#include "vcp_text_editor.h"
#include "vcp_button.h"
#include "vcp_form.h"
#include "vcp_list_menu.h"
#include "vcui_sso_gprot.h"
#include "vcp_indicator_popup.h"
#if defined(__SOCIAL_NETWORK_SUPPORT__)
#include "vapp_sns_settings.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif
#ifdef __MMI_SSO__
#include "SsoSrvGprot.h"
#endif
#ifdef __cplusplus
}
#endif

#if defined(__MMI_SSO__)
class VappSsoAccountsCell : public VcpFormItemCell
{
    VFX_DECLARE_CLASS(VappSsoAccountsCell);

public:
    VappSsoAccountsCell();
    VappSsoAccountsCell(srv_sso_account_struct *account);

public:
    void update(void);
    void updateAccount(srv_sso_account_struct *account);
    srv_sso_account_struct* getSsoAccount();

protected:
    virtual void onInit(void);
    virtual void onDeinit(void);

    virtual void onCellTap(VfxPenEvent &event);

private:
    void onButtonClicked(VfxObject *item, VfxId id);
    void ssoInit(void);

private:

#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 10,
        TEXT1_TOP_GAPS    = 6,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 10,
        TEXT2_BOTTOM_GAPS = 6,
        IMG_LEFT_GAPS     = 10,
        IMG_RIGHT_GAPS    = 10,
        IMG_MAX_WIDTH     = 30
    };
#elif defined(__MMI_MAINLCD_480X800__)
    enum
    {
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 14,
        TEXT1_TOP_GAPS    = 13,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 14,
        TEXT2_BOTTOM_GAPS = 13,
        IMG_LEFT_GAPS     = 14,
        IMG_RIGHT_GAPS    = 14,
        IMG_MAX_WIDTH     = 45
    };
#else
    enum
    {
        TEXT1_LEFT_GAPS   = 0,
        TEXT1_RIGHT_GAPS  = 5,
        TEXT1_TOP_GAPS    = 7,
        TEXT2_LEFT_GAPS   = 0,
        TEXT2_RIGHT_GAPS  = 5,
        TEXT2_BOTTOM_GAPS = 4,
        IMG_LEFT_GAPS     = 5,
        IMG_RIGHT_GAPS    = 5,
        IMG_MAX_WIDTH     = 25
    };
#endif

#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        TAIL_FRAME_LEFT_GAPS   = 0,
        TAIL_FRAME_RIGHT_GAPS  = 10,
    };
#elif defined(__MMI_MAINLCD_480X800__)
    enum
    {
        TAIL_FRAME_LEFT_GAPS   = 0,
        TAIL_FRAME_RIGHT_GAPS  = 14,
    };
#else
    enum
    {
        TAIL_FRAME_LEFT_GAPS  = 0,
        TAIL_FRAME_RIGHT_GAPS  = 5
    };
#endif

#if defined(__MMI_MAINLCD_320X480__)
#define FONT_SIZE_HINT           VFX_FONT_DESC_VF_SIZE(14)
#define FONT_SIZE_MAIN          VFX_FONT_DESC_VF_SIZE(20)
#elif defined(__MMI_MAINLCD_480X800__)
#define FONT_SIZE_HINT           VFX_FONT_DESC_VF_SIZE(21)
#define FONT_SIZE_MAIN          VFX_FONT_DESC_VF_SIZE(30)
#else
#define FONT_SIZE_HINT           VFX_FONT_DESC_VF_SIZE(12)
#define FONT_SIZE_MAIN          VFX_FONT_DESC_VF_SIZE(16)
#endif

    VfxImageFrame *m_icon;
    VcpImageButton *m_sync;
    VfxImageFrame *m_doingSync;
    srv_sso_account_struct *m_ssoAccount;
};
#endif

class VappAccountsSettingsPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappAccountsSettingsPage);

public:
    VappAccountsSettingsPage();
    VappAccountsSettingsPage(VfxBool sns_only);

protected:
    virtual void onInit(void);
    virtual void onEnter(VfxBool isBackWard);
    virtual void onDeinit(void);
    virtual void onExited(void);
private:
    VfxChar* getProfileId(VfxS32 index);

    static mmi_ret onEvtHdlr(mmi_event_struct *param);
    void handleEvtHdlr(mmi_event_struct *param);
private:
    void selectSyncInterval(void);
    void onItemTap(VcpFormItemCell* cell, VfxId cell_id);
    void onLoginCb(VfxPage *page, vcui_sso_login_result_enum result, VfxS32 err);
    void onMenuButtonTap(VfxObject *sender, VfxId id);
    void refresh();

    static mmi_ret Listener(mmi_event_struct* evt);
    enum {
        ID_SYNC_INTERVAL
    };
private:
    VcpForm *m_form;

    VfxBool m_sns_only;
    VfxU8 m_ssoCount;
    VfxU16 m_accCount;
    VfxS32 m_listId;
    VfxU32 m_intervalId;
    VfxS32 m_currLoginId;

    static VappAccountsSettingsPage *m_self;
};

#endif 
#endif /* __VAPP_SSO_SNS_ACCOUNT_SETTING_H__ */
