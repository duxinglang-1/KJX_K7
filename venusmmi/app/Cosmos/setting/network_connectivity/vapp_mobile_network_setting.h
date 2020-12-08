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
 *  vapp_mobile_network_setting.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_MOBILE_NETWORK_SETTING_H__
#define __VAPP_MOBILE_NETWORK_SETTING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
   VAPP_MOBILE_NETWORK_OPERATOR_SELECTION,
#if defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__)
   VAPP_MOBILE_NETWORK_GPRS_SETTING,
#endif /* defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__) */
#if defined(__UMTS_FDD_MODE__) && defined(__HSPA_PREFERENCE_SETTING__) && defined(__DYNAMIC_HSPA_PREFERENCE__) && defined(__HSDPA_SUPPORT__) && defined(__HSUPA_SUPPORT__)	
   VAPP_MOBILE_NETWORK_HSPA_SETTING,
#endif

   VAPP_MOBILE_NETWORK_SETTING_CELL_TOTAL
} vapp_mobile_network_setting_cell_type;

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappMobileNetworkSettingCui : public VfxCui
{	
    VFX_DECLARE_CLASS(VappMobileNetworkSettingCui);

protected:
    virtual void onRun(void* args, VfxU32 argSize);
};

class VappMobileNetworkSettingMainScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappMobileNetworkSettingMainScr);
public:
		void onPageReady();
protected:
	virtual void on1stReady();

private:
	VfxPage *m_settingPage;

};
/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappMobileNetworkSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappMobileNetworkSettingPage);
    // Overrides
    protected:
    virtual void onInit();
    virtual void onDeinit() {VfxPage::onDeinit(); m_pageIsAvailable = VFX_FALSE;};
    virtual void onEntered();
    // Method
    public:
    void initPage();
    void onCellReady();
    void DisableCell(mmi_sim_enum sim, VfxBool isDisable);
    // For handle async callback, if page is not available, do not process any operation of page
    static VfxBool isPageAvailable() {return m_pageIsAvailable;};
    protected:
    void initAllCell();
 
    // Variable
    public:
    VfxSignal0 m_signalPageReady;
    protected:
    static VfxBool m_pageIsAvailable;
//    VfxObjList m_cellList;
    VfxU32 m_readyCount;
    VfxObjListEntry *m_initCellEntry;
    VcpFormItemBase *m_cell[MMI_MAX_SIM_NUM][VAPP_MOBILE_NETWORK_SETTING_CELL_TOTAL];
    VcpForm *m_form;
    //VfxPage *m_nwSelectionPage;
};

class VappMobileNetworkSelectionLaunchCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappMobileNetworkSelectionLaunchCell);
    // Overrides
    protected:
    virtual void onInit();

    public:    
    virtual void setSim(mmi_sim_enum sim);
    virtual void initCell() {m_signalReady.postEmit();}
    // Methods
    public:
    void onTapped(VcpFormItemCell* sender, VfxId id);
    void onPageReady();

    // Variables
    public:
    VfxSignal0 m_signalReady;
    
    protected:
    VfxPage *m_nwSelectionPage;
    mmi_sim_enum m_sim;
};

#if defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__)
class VappMobileNetworkGprsLaunchCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappMobileNetworkGprsLaunchCell);
    // Overrides
    protected:
    virtual void onInit();
    
    public:
    virtual void setSim(mmi_sim_enum sim);
    virtual void initCell();

    // Methods
    public:
    void onTapped(VcpFormItemCell* sender, VfxId id);
    void onGetGprsMode(VfxU8 mode);
    void onGprsModeUpdate(mmi_sim_enum sim, VfxU8 mode);
    static mmi_ret onProc(mmi_event_struct *evt);

    protected:
    void updateMode(VfxU8 mode);

    // Varibles
    public:
    VfxSignal0 m_signalReady;
    
    protected:
    VfxU8 m_mode;
    mmi_sim_enum m_sim;
};
#endif /* defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__) */
#if defined(__UMTS_FDD_MODE__) && defined(__HSPA_PREFERENCE_SETTING__) && defined(__DYNAMIC_HSPA_PREFERENCE__) && defined(__HSDPA_SUPPORT__) && defined(__HSUPA_SUPPORT__)	
class VappMobileNetworkHspaSwitchCell : public VcpFormItemSwitchCell
{
    VFX_DECLARE_CLASS(VappMobileNetworkHspaSwitchCell);

    // Overrides
    protected:
    virtual void onInit();
    virtual void onDeinit();
    public:
    virtual void initCell();
    virtual void setSim(mmi_sim_enum sim);
    
    // Methods
    public:
    void onSwitch(VcpFormItemSwitchCell* sender, VfxId id, VfxBool mode);
    void onHspaModeUpdate(VfxBool result);
    static mmi_ret onProc(mmi_event_struct *evt);
    static void initData();
    static void onGetHspaMode(mmi_sim_enum sim, VfxBool mode);    
    static VappMobileNetworkHspaSwitchCell* getCell(){return m_cell[0];};
    // Variables
    public:
    VfxSignal0 m_signalReady;
    /* Init the mode before create the switch cell to avoid the animation of switch */
    static VfxBool m_hspaMode[MMI_MAX_SIM_NUM];
    static VappMobileNetworkHspaSwitchCell* m_cell[MMI_MAX_SIM_NUM];
    protected:
    //VfxBool m_mode;
    mmi_sim_enum m_sim;
};
#endif

#if defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__)
class VappGprsConnectionSettingPage : public VfxPage, public IVcpListMenuContentProvider
{
    // Overrides
    protected:
    virtual void onInit();

    public:
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const {return 2;};
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const {return ((m_currentSelected == index) ? VCP_LIST_MENU_ITEM_STATE_SELECTED: VCP_LIST_MENU_ITEM_STATE_NONE);}

    // Methods
    public:
//    VappGprsConnectionSettingPage() m_sim(MMI_SIM_NONE), m_currentSelected(0) {};
    virtual ~VappGprsConnectionSettingPage() {m_pageIsAvailable = VFX_FALSE;};
    void setSim(mmi_sim_enum sim);
    void setSelected(VfxU8 selectId) {m_currentSelected = selectId;};
    void onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx);
    void onSwitchFinished(mmi_nw_set_gprs_connect_type_rsp_struct *evt);
    static mmi_ret switchProc(mmi_event_struct *evt);
    static VfxBool isPageAvailable() {return m_pageIsAvailable;};
    // Variables
    public:
    VfxSignal2 <mmi_sim_enum, VfxU8> m_signalSettingUpdate;
    static VfxBool m_pageIsAvailable;
    
    protected:
    VcpTitleBar *m_titleBar;
    mmi_sim_enum m_sim;
    VfxU8 m_currentSelected;
};
#endif /* defined(__MMI_GPRS_FEATURES__) && !defined(__MMI_EM_NW_GPRS_CONN__) */
#if defined(__MONITOR_PAGE_DURING_TRANSFER__) //&& !defined(__LOW_COST_SUPPORT_COMMON__)
class VappMonitorPchSettingPage : public VfxPage, public IVcpListMenuContentProvider
{
    // Overrides
    protected:
    virtual void onInit();

    public:
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const {return 2;};
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

    public:
    void onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx);
    void onConfirmPopupTap(VfxObject* sender, VfxId id);
    void onSettingFinish(VfxBool result);

    protected:
    void switchPch(void);

    protected:
    VcpIndicatorPopup *m_indPopup;
    VfxU32 m_selectIdx;

};
#endif // #if defined(__MONITOR_PAGE_DURING_TRANSFER__) //&& !defined(__LOW_COST_SUPPORT_COMMON__)
#endif /* __VAPP_MOBILE_NETWORK_SETTING_H__ */
 
