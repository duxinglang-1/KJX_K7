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
 *  vcp_tabctrl_page.h
 *
 * Project:
 * --------
 *  Venus FW
 *
 * Description:
 * ------------
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
 * removed!
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_TABCTRL_PAGE_H__
#define __VCP_TABCTRL_PAGE_H__

/*****************************************************************************
 * Include
 *****************************************************************************/
// by RHR //#include "vfx_mc_include.h"
// by RHR //#include "vfx_uc_include.h"

#include "vfx_page.h"
#include "vfx_object.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"

#include "vcp_state_image.h"
#include "vcp_tab_title_bar.h"

#if defined(__MMI_VUI_COSMOS_CP__)

/*****************************************************************************
 * Define
 *****************************************************************************/

/*****************************************************************************
 * Class VcpTabCtrlPage
 *****************************************************************************/

/*
 * VcpTabCtrlPage
 */
class VcpTabCtrlPage : public VfxPage
{
    VFX_DECLARE_CLASS(VcpTabCtrlPage);
// Declaration
public:

// Constructor / Destructor
public:
    // <group DOM_TabctrlPage_VcpTabCtrlPage_Constructor/Destructor>
    // Constructor
    VcpTabCtrlPage();
    virtual ~VcpTabCtrlPage();

// Method
public:
    // for XML
    //void    addTab(VcpTabInfo &info) { addTab(info.id, info.name, info.icon); }

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // add one tab, if tabPage is NULL, onCreateTabPage will be called to obtain the tabpage pointer
    VfxBool addTab(
        VfxId tabId,                    // [IN] id of tab, should be unique and cannot be VFX_ID_NULL
        const VfxWString &name,         // [IN] name of this tab
        const VcpStateImage &icon,      // [IN] icon of this tab
        VfxPage *tabPage = NULL         // [IN] tabpage of this tab, can be NULL
    );
	VfxBool addTab(
		VfxId tabId,								// [IN] id of tab, should be unique and cannot be VFX_ID_NULL
		const VfxResId nameId,			// [IN] name id of this tab
		const VcpStateImage &icon,		// [IN] icon of this tab
		VfxPage *tabPage						// [IN] tabpage of this tab, can be NULL
	);
	VfxBool addTab(
		VfxId tabId,								// [IN] id of tab, should be unique and cannot be VFX_ID_NULL
		const VfxWChar *name,			// [IN] name of this tab
		const VcpStateImage &icon,		// [IN] icon of this tab
		VfxPage *tabPage						// [IN] tabpage of this tab, can be NULL
	);

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // replace one tab
    VfxBool replaceTab(
        VfxId tabId,                    // [IN] id of tab, should be unique and cannot be VFX_ID_NULL
        const VfxWString &name,         // [IN] name of this tab
        const VcpStateImage &icon,      // [IN] icon of this tab
        VfxPage *tabPage = NULL         // [IN] tabpage of this tab, can be NULL
    );
   VfxBool replaceTab(
        VfxId tabId,                    // [IN] id of tab, should be unique and cannot be VFX_ID_NULL
        const VfxResId nameId,         // [IN] name id of this tab
        const VcpStateImage &icon,      // [IN] icon of this tab
        VfxPage *tabPage = NULL         // [IN] tabpage of this tab, can be NULL
    );
   VfxBool replaceTab(
        VfxId tabId,                    // [IN] id of tab, should be unique and cannot be VFX_ID_NULL
        const VfxWChar* name,         // [IN] name of this tab in string format
        const VcpStateImage &icon,      // [IN] icon of this tab
        VfxPage *tabPage = NULL         // [IN] tabpage of this tab, can be NULL
    );

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // set current(highlight) tab
    VfxBool setCurrTab(
        VfxId tabId                     // [IN] id of tab
    );

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // close a tab
    VfxBool closeTab(
        VfxId tabId                     // [IN] id of tab
    );

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // update icon of given tab
    void changeTab(
        VfxId tabId,                    // [IN] id of tab
        const VcpStateImage &icon       // [IN] new icon
    );

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // update name of given tab
    void changeTab(
        VfxId tabId,                    // [IN] id of tab
        const VfxWString &name          // [IN] new name
    );
	void changeTab(
        VfxId tabId,                    // [IN] id of tab
        const VfxResId nameId          // [IN] resource id of new name
    );
	void changeTab(
        VfxId tabId,                    // [IN] id of tab
        const VfxWChar *name         // [IN] new name in string format
    );
    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // update name/icon of given tab
    void changeTab(
        VfxId tabId,                    // [IN] id of tab
        const VfxWString &name,         // [IN] new name
        const VcpStateImage &icon       // [IN] new icon
    );
	 void changeTab(
        VfxId tabId,                    // [IN] id of tab
        const VfxResId nameId,         // [IN] new name
        const VcpStateImage &icon       // [IN] new icon
    );
	 void changeTab(
        VfxId tabId,                    // [IN] id of tab
        const VfxWChar *name,         // [IN] new name
        const VcpStateImage &icon       // [IN] new icon
    );
    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // Query id of current(highlight) tab
    VfxId getCurrTab() const;

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // Query tab page pointer by tab id.
    // Return NULL if tabId is not valid or tab page is not created yet.
    VfxPage* getTabPage(
        VfxId tabId                     // [IN] id of tab
    ) const;

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // enable / disable one tab page
    // Note. you can not disable current tab
    // RETURNS: VFX_TRUE if succeeded, VFX_FALSE if not.
    VfxBool setTabEnabled (
        VfxId tabId,                    // [IN] tab ID
        VfxBool isEnabled               // [IN] whether it is enabled
    );

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // get whether one tab is enabled
    // RETURNS: VFX_TRUE if it is enabled, VFX_FALSE if not.
    VfxBool getTabIsEnabled (
        VfxId tabId                     // [IN] tab ID
    );

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Method>
    // get pointer of tabtitlebar, so that you can customize its setting.
    // Note. please dont change following properties:
    //  size, pos, posZ, frame hierarchy, tab add/removal.
    // RETURNS: pointer to tabtitlebar
    VcpTabTitleBar *getTabCtrl() const;

// Signal
public:
    // <group DOM_TabctrlPage_VcpTabCtrlPage_Event>
    // This signal is invoked when a tab switch finish
    // void YourClass::m_signalTabSwitched(VfxObject* sender, VfxId tabId)
    VfxSignal2 <VfxObject*, VfxId> m_signalTabSwitched;

// Overridable
protected:
    // <group DOM_TabctrlPage_VcpTabCtrlPage_Overridable>
    // When the page of a tab is NULL, this interface will be called to create it.
    virtual VfxPage *onCreateTabPage(
        VfxId tabId                     // [IN] id of tab to be created.
    );

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Overridable>
    // When tab is about to switch, this interface will be called.
    virtual void onTabSwitching(
        VfxId tabId                     // [IN] id of new tab.
    );

    // <group DOM_TabctrlPage_VcpTabCtrlPage_Overridable>
    // When tab switch finish, this interface will be called.
    virtual void onTabSwitched(
        VfxId tabId                     // [IN] id of current tab.
    );

// Override
protected:
    virtual void onInit();
    virtual void onObjectNotify(VfxId id, void *userData);
    virtual VfxRect onGetPageRect() const;
    virtual VfxFrame *onGetActiveChild() const;
    virtual VfxPageBar *onSetBar(VfxPageBarLocationEnum loc, VfxPageBar *newBar);
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited();
    virtual void onExited2();
    virtual void onUpdate();

// Override
public:
    virtual void processRotate(const VfxScreenRotateParam &param);
    virtual mmi_ret processProc(mmi_event_struct *evt);

// Implementation
private:
    void    doTabSwitch(VfxBool noAnimation);
    void    onTabTransitStop(VfxObject *obj, VfxBool in, VfxS32 direction);
    void    onTabBarSwitched(VfxObject *obj, VfxId newTabId);
    void    onBoundChanged(VfxFrame *, const VfxRect &);
    void    stopTransition();
    void    fixRotation(VfxPage * page);

// Variable
private:
    VfxId       m_currTab, m_newTab;
    VfxId       m_phaseInTab, m_phaseOutTab;
    VcpTabTitleBar *m_bar;             // Real tab bar control

#define VCP_TAB_CTRL_PAGE_LIST_MAX_COUNT 8

    class List : public VfxBase
    {
    public:
        class Info : public VfxBase
        {
        public:
            Info();
            ~Info();
        // Variable
        public:
            VfxId                   id;
            VfxWString              name;
            VcpStateImage           icon;
            VfxWeakPtr<VfxPage>     page;
        };

    public:
        List();
        ~List();

    public:
        VfxBool add(VfxId id, const VfxWString &name, const VcpStateImage &icon,
                VfxPage *tabPage, IVfxAllocatable * alloc);
        Info    *find(VfxId id) const;
        VfxBool remove(VfxId id);
        VfxBool replace(VfxId id, const VfxWString &name, const VcpStateImage &icon, VfxPage *tabPage);
        Info *  getFirstInfo() const;
        Info *  getLastInfo() const;

    private:
        Info    m_objList[VCP_TAB_CTRL_PAGE_LIST_MAX_COUNT];
        Info    *m_objListEnd;

        static void assignListInfo(VcpTabCtrlPage::List::Info * info, VfxId id, const VfxWString &name, const VcpStateImage &icon, VfxPage *page);
    };

    List        m_pageList;        // List of Tab info
};

#endif // #if defined (__MMI_VUI_COSMOS_CP__)
#endif // __VCP_TABCTRL_PAGE_H__
