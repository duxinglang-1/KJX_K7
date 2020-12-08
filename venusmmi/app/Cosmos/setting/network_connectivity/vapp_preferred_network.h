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
 *  Vapp_preferred_network.h
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
#ifndef __VAPP_PREFERRED_NETWORK_H__
#define __VAPP_PREFERRED_NETWORK_H__
#if !defined(__LOW_COST_SUPPORT_COMMON__)
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_plmn_list.h"
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_vcui_mobile_nw_setting_def.h"

extern "C"
{
#include "NetSetSrvGprot.h"    
}
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    VAPP_PREFERRED_NW_NONE,
    VAPP_PREFERRED_NW_GET_LIST,
    VAPP_PREFERRED_NW_ADD_TO_LIST,        
    VAPP_PREFERRED_NW_DELETE_FROM_LIST,
    VAPP_PREFERRED_NW_CHANGE_PRIORITY,
    VAPP_PREFERRED_NW_ABORT_OPERATION,

    VAPP_PREFERRED_NW_OP_TYPE_END
} VappPreferredNwOpTypeEnum;

#define VAPP_PREF_NW_PROGRESS_FAILED (-1)
#define VAPP_PREF_NW_PROGRESS_DONE (1)
/***************************************************************************** 
 * Class 
 *****************************************************************************/

/***************************************************************************** 
 * VappNetworkSelectionPlmnNode
 *****************************************************************************/
class VappPreferredNwPlmnNode : public VappSettingPlmnNodeBase
{
    VFX_DECLARE_CLASS(VappPreferredNwPlmnNode);  

    // Method
    public:
	VappPreferredNwPlmnNode() {};
    VappPreferredNwPlmnNode(const CHAR* plmn, srv_netset_rat_mode_enum rat, VfxU16 priority);
    VfxU16 getPriority() {return m_priority;};
    void setPriority(VfxU16 priority) {m_priority = priority;};
    // Variable
    protected:
    VfxU16 m_priority;
};

class VappPreferredNwSettingParser : public VfxObject
{
    // Method
    public:
    void updateList(mmi_sim_enum sim);
    VappSettingPlmnList *getSimList() {return m_list;};
    VfxU16 getSimFileType() {return m_simFileType;};
    // Call the 
    void abortUpdateList() {m_abortUpdateList = VFX_TRUE;};
    
    // Internal used
    static mmi_ret updateListProc(mmi_event_struct *evt);
    void prepareList(mmi_smu_get_preferred_oper_list_rsp_struct *data);

    // Variables
    public: 
    VfxSignal2 <VfxS8, VappPreferredNwOpTypeEnum> m_signalListReady;
    // internal used
    static VfxBool m_abortUpdateList;

    protected:
    VappSettingPlmnList *m_list;
    VfxU16 m_simFileType;
};

class VappPreferredNwSettingProvider : public VfxObject
{
    // Method
    public:
    VfxWString getSimPlmn(VfxId plmnId);
    VfxWString getSimPlmnName(VfxId plmnId);
    VfxWString getSimPlmnRat(VfxId plmnId);
    VfxU16 getSimPlmnCount();

    void getSystemPlmn(VfxId plmnId, CHAR *buffer);
    VfxWString getSystemPlmnString(VfxId plmnId);
    VfxWString getSystemPlmnName(VfxId plmnId);
    VfxU16 getSystemPlmnCount() {return m_systemListCount;};

    VappPreferredNwSettingProvider();
    ~VappPreferredNwSettingProvider();
    void setList(VappSettingPlmnList *list) {m_list = list;};


    // Variables
    protected:
    VappSettingPlmnList *m_list;
    VfxU16 m_systemListCount;
    srv_netset_plmn_struct* m_systemList;
};

class VappPreferredNwSettingController : public VfxObject
{
    // Methods
    public:
    // startIndex: all the nodes in the list will be added after this index
    void addToSimList(mmi_sim_enum sim, VappSettingPlmnList *list, VfxU16 startIndex);
    void deleteFromSimList(mmi_sim_enum sim,VappSettingPlmnList *list);
    void changePriority(mmi_sim_enum sim,VappSettingPlmnNodeBase *node, VfxU16 oldPriority, VfxU16 newPriority);
    void abortOperation(VfxBool isAboutToClose = VFX_FALSE) 
    {
        if (isAboutToClose)
    	{
    	    m_abortBeforeClosed = VFX_TRUE;
    	}
        else
        {
            m_abortOp = VFX_TRUE;
        }
    };

    // Internal used
    VappPreferredNwSettingController() {m_abortBeforeClosed = VFX_FALSE;};
    void operationFailed();
    void processInt();
    void deinitList();
    static mmi_ret opProc(mmi_event_struct *evt);
    // Variables
    public:
    VfxSignal2 <VfxS8, VappPreferredNwOpTypeEnum> m_signalOpProgress;

    // For internal use, post emit this signal to trigger add next
    VfxSignal0 m_signalPostOp;
    VappPreferredNwOpTypeEnum m_operation;
    mmi_sim_enum m_opSim;
    VappSettingPlmnList *m_opList;
    VfxU16 m_opIndex; // Used for multi-add / multi-delete
    VfxU16 m_startIndex; // Used for mulit-add, all PLMN will be add after this index
    VfxBool m_abortOp;
    static VfxBool m_abortBeforeClosed; // Set to VFX_TRUE if the controller will be closed
};

class VappPreferredNwSettingInterface : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappPreferredNwSettingInterface);
    // Method
    public:
    void initInterface(mmi_sim_enum sim, VfxObject *parent) {m_sim = sim; m_parent = parent;};
    void closeInterface() {autoClosed();};
    
    void updateList();    

    
    VfxU16 getSimFileType() {return m_simFileType;};    
    VfxU16 getSimPlmnCount();
    VfxWString getSimPlmn(VfxId plmnId);
    VfxWString getSimPlmnName(VfxId plmnId);
    VfxWString getSimPlmnRat(VfxId plmnId);
    VfxU16 getSimPlmnLimit();

    void getSystemPlmn(VfxId plmnId, CHAR *buffer);
    VfxWString getSystemPlmnString(VfxId plmnId);
    VfxWString getSystemPlmnName(VfxId plmnId);
    VfxU16 getSystemPlmnCount();


    VfxU8 addToSimList(VappSettingPlmnList *list);
    void deleteFromSimList(VappSettingPlmnList *list);
    void changePriority(VfxId oldPriority, VfxId newPriority);
    void abortOperation();

    void swapSimPlmnDisplay(VfxId originalPlmnId, VfxId newPlmnId);

    // Internal Used
    VappPreferredNwSettingInterface() : 
        m_sim(MMI_SIM_NONE),
        m_parent(NULL),
        m_simFileType(0),
        m_simList(NULL),
        m_opList(NULL),
        m_parser(NULL),
        m_provider(NULL),
        m_processState(VAPP_PREFERRED_NW_NONE)
    {
        m_controller.m_signalOpProgress.connect(this, &VappPreferredNwSettingInterface::controllerSignalProc);
    };
        
    void autoClosed();
    void setProcess(VappPreferredNwOpTypeEnum type) {m_processState = type;};
    void endProcess() 
    {
        m_processState = VAPP_PREFERRED_NW_NONE;
    };
    VfxBool isProcessing() {return (m_processState != VAPP_PREFERRED_NW_NONE) ? VFX_TRUE : VFX_FALSE;};
    VappPreferredNwOpTypeEnum getProcessType() {return m_processState;} ;   


    VappSettingPlmnNodeBase *getSimPlmnNode(VfxId plmnId);
    void controllerSignalProc(VfxS8 progress, VappPreferredNwOpTypeEnum type);
    void updateListAfterChangePriority();
    // Variable
    public:
    VfxSignal1 <VfxBool> m_signalListReady;
    VfxSignal2 <VfxBool, VfxFloat>  m_signalAddProgress;
    VfxSignal2 <VfxBool, VfxFloat>  m_signalDelProgress;
    VfxSignal1 <VfxBool> m_signalChangePriorityDone;
    VfxSignal0 m_signalOpAborted;
    
    protected:
    mmi_sim_enum m_sim;
    VfxObject *m_parent;

    VfxU16 m_simFileType;
    VappSettingPlmnList *m_simList;
    VappSettingPlmnList *m_opList;

    VappPreferredNwSettingParser *m_parser;
    VappPreferredNwSettingProvider *m_provider;
    VappPreferredNwSettingController m_controller;

    VappPreferredNwOpTypeEnum m_processState;

    VfxU16 m_actualOpNum;
    VfxU16 m_OpTotalNum;
};


class VappSettingPreferredNetworkMainPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSettingPreferredNetworkMainPage);
    // Typedef
    typedef enum
    {
        VAPP_PREF_NW_MAIN_PAGE,
        VAPP_PREF_NW_DEL_PAGE,
        
        VAPP_PREF_NW_PAGE_TYPE_END
    } VappPrefNwPageTypeEnum;
    // Methods
    public:
    virtual void onInit();
    VappSettingPreferredNetworkMainPage() : 
        m_sim(MMI_SIM_NONE), 
        m_toolBar(NULL), 
        m_listMenu(NULL), 
        m_updateListAndPopPage(VFX_FALSE), 
        m_gotoEndOfList(VFX_FALSE),
        m_pageType(VAPP_PREF_NW_MAIN_PAGE),
        m_listFlag(NULL),
        m_cancelWaitingPopup(NULL),
        m_listCount(0) {};
    VappSettingPreferredNetworkMainPage(mmi_sim_enum sim) : 
        m_sim(sim), 
        m_toolBar(NULL), 
        m_listMenu(NULL), 
        m_updateListAndPopPage(VFX_FALSE), 
        m_gotoEndOfList(VFX_FALSE),
        m_pageType(VAPP_PREF_NW_MAIN_PAGE),
        m_listFlag(NULL),
        m_cancelWaitingPopup(NULL),
        m_listCount(0) {};
    ~VappSettingPreferredNetworkMainPage();
    
    void updateList();
    void updateAfterOp(VfxBool gotoEndOfList);
    void updateToolBar();
    void setSim(mmi_sim_enum sim) {m_sim = sim;};

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const;

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;
    
    virtual VfxBool getItemIsHighlightable(
        VfxU32 index       // [IN] the index of item
        ) const;

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
    {
        text = VFX_WSTR_RES(STR_ID_VAPP_SETTING_NO_PREFERRED_NETWORK);
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        return VFX_TRUE;
    }
    
    // Internal used
    void switchPageType(VappPrefNwPageTypeEnum pageType);
    void onToolBarTapped(VfxObject *obj, VfxId id);    

    void onListReady(VfxBool result);    

    void onCommandPopupTapped(VfxObject *obj, VfxId id);    

    void onSelectStateChanged(VcpListMenu *sender, VfxU32 id, VcpListMenuItemStateEnum state);
    void onDeleteConfirmPopupTapped(VfxObject *obj, VfxId id);
    void onDelProgress(VfxBool result, VfxFloat progress);
    void deleteSelectedPlmn(void);
    void onCancelDel(VfxObject *obj, VfxId id);
    void cancelDelete();
    
    protected:
    // Do not pop page when page in delete status
    virtual void onBack();
    // Variables
    protected:
    mmi_sim_enum m_sim;
    VcpTitleBar *m_titleBar;
    VcpToolBar  *m_toolBar;
    VcpListMenu *m_listMenu;
    VfxBool m_updateListAndPopPage;
    VfxBool m_gotoEndOfList;
    VappPrefNwPageTypeEnum m_pageType;
    VfxU8 *m_listFlag;
    VcpIndicatorPopup *m_progressPopup;
    VcpIndicatorPopup *m_cancelWaitingPopup;
    VfxU16 m_listCount;
    VfxBool m_isCancel;
};

class VappSettingPreferredNetworkChangePriorityPage : public VfxPage, public IVcpListMenuContentProvider
{
    // Overrides
    public:
    virtual void onInit();
    virtual void onBack();

        
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const;

    virtual VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        );
    
    virtual VfxBool getItemIsHighlightable(
        VfxU32 index       // [IN] the index of item
        ) const
    {
        return VFX_FALSE;
    }


    // Methods
    void onChangePriority(VcpListMenu *sender);
    void onChangePriorityFinish(VfxBool result);
    
    // Variable
    public:
    VfxSignal1 <VfxBool> m_signalUpdateList;
    
    protected: 
    VcpTitleBar *m_titleBar;
    VcpListMenu *m_listMenu;

    VfxU32 m_startIndex;
    VfxU32 m_endIndex;   
};

class VappSettingPreferredNetworkAddListPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSettingPreferredNetworkAddListPage);
    // Overrids
    public:
    virtual void onInit();
    
    // Methods
    public:
    VappSettingPreferredNetworkAddListPage() :  m_toolBar(NULL), m_listMenu(NULL), m_progressPopup(NULL), m_listFlag(NULL), m_listCount(0) {};
    ~VappSettingPreferredNetworkAddListPage();
    // Internal used
    void addSelectedPlmn(srv_netset_rat_mode_enum rat);
    void onSelectStateChanged(VcpListMenu *sender, VfxU32 id, VcpListMenuItemStateEnum state);
    void onToolBarTapped(VfxObject *obj, VfxId id);
    void onCommandPopupTapped(VfxObject *obj, VfxId id);    
    void showLimitPopup();
    void onAddProgress(VfxBool result, VfxFloat progress);
    void onCancelAdd(VfxObject *obj, VfxId id);
    void cancelAdd();
    
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const;

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    // Variables
    public:
    VfxSignal1 <VfxBool> m_signalUpdateList;
    
    protected:
    VcpToolBar  *m_toolBar;
    VcpListMenu *m_listMenu;
    VcpIndicatorPopup *m_progressPopup;
    VfxU8 *m_listFlag;
    VfxU16 m_listCount;
    
};


class VappSettingPreferredNetworkCreateNewPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappSettingPreferredNetworkCreateNewPage);
    // Overrides
    public:
    virtual void onInit();

    VappSettingPreferredNetworkCreateNewPage() : m_progressPopup(NULL) {};
    void addPlmn(const VfxWString &plmn, srv_netset_rat_mode_enum ratType = SRV_NETSET_RAT_NONE);
    void onToolBarTapped(VfxObject *obj, VfxId id);
    void onAddProgress(VfxBool result, VfxFloat progress);
    void onTextChanged(VcpTextEditor *obj);
    
    #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
/* under construction !*/
    #endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
    // Variables
    public:
    VfxSignal1 <VfxBool> m_signalUpdateList;
    
    protected:
    VcpToolBar  *m_toolBar;
    VcpForm     *m_form;
    VcpFormItemTextInput *m_textInputCell;
    VcpFunctionBar *m_funcBar;
    #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
/* under construction !*/
    #endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
    VcpIndicatorPopup *m_progressPopup;
};

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // __LOW_COST_SUPPORT_COMMON__
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
#endif /* __VAPP_PREFERRED_NETWORK_H__ */
 
