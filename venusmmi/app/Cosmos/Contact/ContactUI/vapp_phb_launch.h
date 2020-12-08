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
 *  vapp_phb_launch.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifndef __PB_LAUNCH_H__
#define __PB_LAUNCH_H__

#include "vfx_uc_include.h"
#include "vfx_mc_include.h"

#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vcp_menu_popup.h"

#include "vapp_phb_gprot.h"
#include "vapp_phb_list.h"
#include "vapp_phb_multi.h"
#include "vcui_phb_gprot.h"

#include "vapp_clog_ui.h"        // for calllog app


/***************************************************************************** 
 * Class VappPhbApp
 *****************************************************************************/ 
class VappPhbApp: public VfxApp
{
    VFX_DECLARE_CLASS(VappPhbApp);

public:
    VappPhbApp();

    virtual void onRun(void* args, VfxU32 argSize);

    void setSubAppId(vapp_phb_sub_app_type_enum id);

    vapp_phb_sub_app_type_enum getSubAppId();

    void setUserData(void* userData);

    void* getUserData(vapp_phb_sub_app_type_enum id);

private:
    vapp_phb_sub_app_type_enum m_subAppId;
    void* m_clogUserData;
    void* m_dialerUserData;
    void* m_contactUserData;
};


/***************************************************************************** 
 * Class VappPhbScr
 *****************************************************************************/ 
class VappPhbScr: public VfxMainScr
{
    VFX_DECLARE_CLASS(VappPhbScr);

public:
    VappPhbScr();
    
    void onContactEvent(ContactTask *task, mmi_event_struct *evt);

protected:
    virtual void on1stReady();

    virtual void on2ndReady();

    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

private:
    VfxPage *m_page;
};


/***************************************************************************** 
 * Class VappPhbPage
 *****************************************************************************/ 
class VappPhbPage: public VcpTabCtrlPage
{
    VFX_DECLARE_CLASS(VappPhbPage);

protected:
    virtual void onInit();

#ifdef __MMI_SNS_CONTACTS__
    // [workaround-VcpTabCtrlPage can't provide correct entered timing]
    virtual void onEntered();
#endif

    virtual VfxPage *onCreateTabPage(VfxId tabId);

    virtual void onTabSwitched(VfxId tabId);

public:
    void updatePage(VfxId tabId);

public:
    VfxBool m_b2ndReady;

private:
    VfxPage *m_dialerPage;
    VfxPage *m_clogPage;
    VfxPage *m_contactPage;
};


/***************************************************************************** 
 * Class VappPhbListTabPage
 *****************************************************************************/ 
class VappPhbListTabPage: public VfxPage, public VappPhbMarkCmdInterface
{
public:
    // default constructor
    VappPhbListTabPage();

public:
    // signal toolbar click handler
    void onToolBarClick(VfxObject *obj, VfxId id);

    // contact count
    void onCountChanged(VappPhbListCp* list, VfxU32 count);

    // cmd start
    virtual void onCmdStart(vapp_phb_mark_cmd_type_enum cmd);

    // cmd end
    virtual void onCmdEnd(vapp_phb_mark_cmd_type_enum cmd);

    void onItemTaped(VcpGroupListMenu *list, VcpMenuPos pos);

    void onItemLongTaped(VcpGroupListMenu *list, VcpMenuPos pos);

    void selectSimPopup(VfxBool call, mmi_sim_enum sim);

    void onSimSelected(VcpMenuPopup*, VcpMenuPopupEventEnum, VcpMenuPopupItem*);

    void onContextMenuSelected(VcpMenuPopup*, VcpMenuPopupEventEnum, VcpMenuPopupItem*);
#if defined ( __MMI_SMS_COMPOSER__) ||defined(__MMI_UNIFIED_COMPOSER__)
    void createMsg(mmi_phb_contact_id id, VappContactNumber& number, mmi_sim_enum sim);
#endif
    void updatePage();
    static mmi_ret listener(mmi_event_struct *evt);

protected:
    virtual void onInit();

    virtual void onBack();

    virtual mmi_ret onProc(mmi_event_struct *evt);

#ifdef __LOW_COST_SUPPORT_COMMON__
    virtual void onEntered();

    virtual void onExit(VfxBool isBackward);

    virtual void onExited();
#endif /* __LOW_COST_SUPPORT_COMMON__ */

	virtual void onDeinit();
private:
    VcpToolBar        *m_toolBar;
    VappPhbListCp     *m_list;
    VfxObject         *m_cmdObj;
    mmi_phb_contact_id m_id;
    VappContactNumber  m_number;
#ifdef __LOW_COST_SUPPORT_COMMON__
    VfxWString                 m_searchText;
    VcpTextEditorHistoryStruct m_editorHistory;
    VcpListMenuHistoryStruct   m_listHistory;
    VfxBool                    m_recreatePhbForm;
    VfxBool                    m_setHistory;
#endif /* __LOW_COST_SUPPORT_COMMON__ */

private:
#ifdef __LOW_COST_SUPPORT_COMMON__
    void clearPhbForm();
    void recreatePhbForm();
#endif /* __LOW_COST_SUPPORT_COMMON__ */


#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
    VappPhbMarkShareObj  *Shareobj;
#endif /* __MMI_OPP_SUPPORT__  && __MMI_VCARD__ */
    VappPhbMarkDeleteObj  *DeleteObj;

#ifdef __MMI_PHB_MARK_MESSAGE__
    VappPhbMarkMsgObj *Msgobj;
#endif /* __MMI_PHB_MARK_MESSAGE__ */
    enum
    {
        VAPP_PHB_LIST_CMD_ADD,
#ifdef __MMI_PHB_CALLER_GROUP__
        VAPP_PHB_LIST_CMD_GROUP,
#endif /* MMI_PHB_CALLER_GROUP */

#if defined (__MMI_OPP_SUPPORT__) && defined (__MMI_VCARD__)
        VAPP_PHB_LIST_CMD_SHARE,
#endif
        VAPP_PHB_LIST_CMD_DELETE,
#ifdef __MMI_PHB_MARK_MESSAGE__
        VAPP_PHB_LIST_CMD_MESSAGE,
#endif /* __MMI_PHB_MARK_MESSAGE__ */
#ifdef __MMI_PHB_MYCARD__
        VAPP_PHB_LIST_CMD_MYCARD,
#endif /* __MMI_PHB_MYCARD__*/
        VAPP_PHB_LIST_CMD_SETTING
    };

    enum
    {
        VAPP_PHB_MORE_ACTION_EDIT,
        VAPP_PHB_MORE_ACTION_DELETE,
        VAPP_PHB_MORE_ACTION_CALL = 0x10,
        VAPP_PHB_MORE_ACTION_MESSAGE = 0x20,
        VAPP_PHB_MORE_ACTION_SELECT_SIM_CALL = 0x30,
        VAPP_PHB_MORE_ACTION_SELECT_SIM_MSG = 0x40
    };
};

#endif /* __PB_LAUNCH_H__ */

