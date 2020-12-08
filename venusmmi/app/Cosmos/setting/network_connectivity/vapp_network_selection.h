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
 *  vapp_network_selection.h
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
#ifndef __VAPP_NETWORK_SELECTION_H__
#define __VAPP_NETWORK_SELECTION_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_plmn_list.h"
extern "C"
{
#include "NetsetSrvGprot.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
// Mask for PLMN type
typedef enum
{
    VAPP_SETTING_PLMN_TYPE_NONE = 0x00,
    VAPP_SETTING_HOME_PLMN = 0x01,
    VAPP_SETTING_FORBIDDEN_PLMN = 0x02,
    VAPP_SETTING_UNKNOWN_PLMN = 0x04,

    VAPP_SETTING_CURRENT_PLMN = 0x10,

    VAPP_SETTING_PLMN_TYPE_INVALID = 0xFF
} VappSettingPlmnType;

// Enum for network selection operation type
typedef enum
{
    VAPP_NETWORK_SELECTION_NO_PROCESS,
    VAPP_NETWORK_SELECTION_GET_LIST,
    VAPP_NETWORK_SELECTION_ABORT_GET_LIST,
    VAPP_NETWORK_SELECTION_CAMP_ON,
    VAPP_NETWORK_SELECTION_AUTO_CAMP_ON,    
    VAPP_NETWORK_SELECTION_SWITCH_RAT,
    VAPP_NETWORK_SELECTION_OTHER,
    
    VAPP_NETWORK_SELECTION_PROCESS_STATE_END
}VappNetworkSelectionProcessState;

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappManualNetworkSelectionForm;
class VappAutoNetworkSelectionForm;

class VappNetworkSelectionPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappNetworkSelectionPage);
    // Overrides
    public:
    virtual void onInit();
    protected:
    virtual void onEntered();
    virtual void onExit(VfxBool isBackward);

    // Methods
    public:
//    static mmi_ret rspProc(mmi_event_struct *evt);
    VappNetworkSelectionPage() : m_sim(MMI_SIM_NONE), m_autoForm(NULL), m_manualForm(NULL) {m_isPageAvailable = VFX_TRUE;};
    VappNetworkSelectionPage(mmi_sim_enum sim) : m_autoForm(NULL), m_manualForm(NULL) {m_sim = sim; m_isPageAvailable = VFX_TRUE;};
    //~VappNetworkSelectionPage();
    void InitPage();
    void onSegBtnTap(VfxObject *obj, VfxId id);
    static VfxBool isPageAvailable() {return m_isPageAvailable;};

    private:
    void updateForm(VfxId formId);
    void updateAutoForm();
    void updateManualForm();
    void onAutoFormReady();
    // Used for setting

    void setNwSelectionModeRsp(mmi_nw_set_plmn_select_mode_rsp_struct *result);
    static mmi_ret settingRspProc(mmi_event_struct *evt);

    // Variables
    public:
    VfxSignal0 m_signalPageIsReady;
    
    private:
    mmi_sim_enum m_sim;
    VappAutoNetworkSelectionForm *m_autoForm;
    VappManualNetworkSelectionForm *m_manualForm;
    srv_netset_nw_selection_mode_enum m_serviceMode;
    VcpSegmentButton *m_segBtn;
    static VfxBool m_isPageAvailable;
};

// For auto network selection
/***************************************************************************** 
 * VappAutoNetworkSelectionForm
 *****************************************************************************/
class VappAutoNetworkSelectionForm : public VcpForm
{
    VFX_DECLARE_CLASS(VappAutoNetworkSelectionForm);
    // Methods
    public:
    VappAutoNetworkSelectionForm() : m_isInit(VFX_FALSE), m_autoCampOnPopup(NULL), m_serviceMode(0), m_failedPopup(NULL) {m_currentPopup = NULL;};
    virtual void onDeinit();
    void setSim(mmi_sim_enum sim) {m_sim = sim;};
    void updateForm();
    void onAutoSelectPlmn(VcpFormItemCell* sender, VfxId senderId);
    void autoSelectPlmnRsp(VfxBool result);

#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
#if !defined(__LOW_COST_SUPPORT_COMMON__)
    void onEntryPreferrence(VcpFormItemCell* sender, VfxId senderId);    
    void onPreferrenceListReady(VfxBool result);
#endif // #if !defined(__LOW_COST_SUPPORT_COMMON__)
    void onPopClicked(VfxObject* sender, VfxId id);
    
    // Variables
    public:
    VfxSignal0 m_signalFormIsReady;

    private:
    VfxBool m_isInit;
    mmi_sim_enum m_sim;    
    VcpIndicatorPopup *m_autoCampOnPopup;
    VcpFormItemLauncherCell *m_autoSelect;
#if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
/* under construction !*/
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */

#if !defined(__LOW_COST_SUPPORT_COMMON__)
    VcpFormItemLauncherCell *m_autoPreference;
#endif // #if !defined(__LOW_COST_SUPPORT_COMMON__)

    VcpFormItemLauncherCell *m_manualRefresh;

    VfxU8 m_serviceSelMode;
    VfxU8 m_serviceMode;

    VcpConfirmPopup *m_failedPopup;    
    // The popup will be closed automatically when press HOME key, 
    // use a weak pointer to keep the current popup
    VfxWeakPtr<VfxBasePopup> m_currentPopup;
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
#endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */
// For Manual network selection

/***************************************************************************** 
 * VappNetworkSelectionPlmnNode
 *****************************************************************************/
class VappNetworkSelectionPlmnNode : public VappSettingPlmnNodeBase
{
    VFX_DECLARE_CLASS(VappNetworkSelectionPlmnNode);  

    // Method
    public:
	VappNetworkSelectionPlmnNode() : m_type(VAPP_SETTING_PLMN_TYPE_INVALID) {};
    VappNetworkSelectionPlmnNode(const CHAR* plmn, srv_netset_rat_mode_enum rat, VfxU8 type);
    VappNetworkSelectionPlmnNode(VappNetworkSelectionPlmnNode *node);
    void setValue(VappNetworkSelectionPlmnNode *node);
    VfxU8 getType() {return m_type;};
    void setType(VfxU8 type) {m_type = type;};

    // Variable
    protected:
    VfxU8        m_type;
};

/***************************************************************************** 
 * VappNetworkSelectionCell with icon and additonal information icon
 *****************************************************************************/
class VappNetworkSelectionCell : public VcpFormItemLauncherCell
{
    VFX_DECLARE_CLASS(VappNetworkSelectionCell);
    protected:
    // The size parameter should be the same as the VcpListMenuCellIconSingleTextFrame
#if defined(__MMI_MAINLCD_320X480__)
    enum
    {
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 10,
        IMG_LEFT_GAPS    = 10,
        IMG_RIGHT_GAPS   = 10,
        IMG_MAX_WIDTH    = 30,
        // Add for network selection
        IMG_MAX_HEIGHT    = 30,        
        IMG_2_MAX_WIDTH  = 30,
        IMG_2_RIGHT_GAPS = 10
    };
#elif defined(__MMI_MAINLCD_480X800__)
    enum
    {
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 18,
        IMG_LEFT_GAPS    = 14,
        IMG_RIGHT_GAPS   = 18,
        IMG_MAX_WIDTH    = 35,
        // Add for network selection
        IMG_MAX_HEIGHT    = 35,   
        IMG_2_MAX_WIDTH  = 30,
        IMG_2_RIGHT_GAPS = 10        
    };
#else
    enum
    {
        TEXT_LEFT_GAPS   = 0,
        TEXT_RIGHT_GAPS  = 8,
        IMG_LEFT_GAPS    = 11,
        IMG_RIGHT_GAPS   = 11,
        IMG_MAX_WIDTH    = 23,
        // Add for network selection
        IMG_MAX_HEIGHT    = 23,
        IMG_2_MAX_WIDTH  = 30,
        IMG_2_RIGHT_GAPS = 10
    };
#endif       

    // Overrides
    public:
    virtual void onInit();
    virtual void onUpdate();
    // Methods
    VappNetworkSelectionCell() : m_addInfo(VFX_WSTR_NULL){};
    void setHintPosition();
    void setIconResId(VfxU32 id) 
    {
        if (id)
        {
            m_iconFrame->setResId(id);
        }
    };
    
    // Variables
    private:
    // For display
    VfxImageFrame *m_iconFrame;  // For home, forbidden, unknown, current icon
    VfxImageFrame *m_addInfoIcon; // For additional information icon
    VfxWString m_addInfo;
};

/***************************************************************************** 
 * VappNetworkSelectionListParser get PLMN list and save data to list
 *****************************************************************************/
class VappNetworkSelectionListParser : public VfxObject
{
    VFX_DECLARE_CLASS(VappNetworkSelectionListParser);
    // Methods
    public:
    void updateList(); // Update the list, m_signalListReady will be emit when list is updated
    void updateListInt(); 
    void abortGetList();
    void abortGetListBeforeClose();
    
    // Internal use
    public:
    VappNetworkSelectionListParser() : m_sim(MMI_SIM_NONE), m_currentProcess(VAPP_NETWORK_SELECTION_NO_PROCESS), m_waitingForAbort(VFX_FALSE) {m_isGetListAborted = VFX_FALSE;};
    VappNetworkSelectionListParser(mmi_sim_enum sim) : m_sim(sim), m_currentProcess(VAPP_NETWORK_SELECTION_NO_PROCESS), m_waitingForAbort(VFX_FALSE) {m_isGetListAborted = VFX_FALSE;};
    virtual ~VappNetworkSelectionListParser() {m_isGetListAborted = VFX_TRUE;};
    virtual VappSettingPlmnList *getList() {return m_list;};
    void createList(mmi_nw_get_plmn_list_rsp_struct *data);
    static mmi_ret getPlmnListProc(mmi_event_struct *evt);
    void updateListAfterCampOn();
    static VfxBool isGetListAborted() {return m_isGetListAborted;};
    void onGetPlmnList(mmi_event_struct *evt);

    #if defined(__GSM_RAT__) && defined(__UMTS_RAT__) && !defined(__OP01_3G__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__GSM_RAT__) && defined(__UMTS_RAT__) */

    // Variable
    public: 
    VfxSignal2 <VfxBool, VappNetworkSelectionProcessState> m_signalListReady;
    VfxSignal2 <VfxBool, VappNetworkSelectionProcessState> m_signalGetListAbort;
    protected:
    mmi_sim_enum m_sim;
    VappSettingPlmnList *m_list;
    VappNetworkSelectionProcessState m_currentProcess;
    VfxBool m_waitingForAbort;
    static VfxBool m_isGetListAborted;
};

/***************************************************************************** 
 * VappNetworkSelectionListProvider provide data to UI
 *****************************************************************************/
class VappNetworkSelectionListProvider : public VfxObject
{
    public:
    VfxWString getPlmnName(VfxId plmnId);
    VfxWString getPlmnRat(VfxId plmnId);
    VfxId getPlmnIconId(VfxId plmnId);
    VfxWString getAdditonalInformation(VfxId plmnId);

    // Internal use
    VappNetworkSelectionListProvider() : m_list(NULL) {};
   
    void setList(VappSettingPlmnList *list) {m_list = list;};

    // Variables
    protected:
    VappSettingPlmnList *m_list;
};

/***************************************************************************** 
 * VappNetworkSelectionController control the camp on process
 *****************************************************************************/
class VappNetworkSelectionController : public VfxObject
{
    VFX_DECLARE_CLASS(VappNetworkSelectionController);
    public:
    void campOn(mmi_sim_enum sim, VappNetworkSelectionPlmnNode *node);
    void campOnInt();
    void autoCampOn(mmi_sim_enum sim);
    static mmi_ret campOnProc(mmi_event_struct *evt);

    // Internal used
    // When manual camp on PLMN, should set the service mode to auto (COSMOS UE design)
    void campOnFinished(mmi_nw_set_plmn_rsp_struct *data);
    // Variable
    VfxSignal2 <VfxBool, VappNetworkSelectionProcessState> m_signalCampOnResult;
    VfxSignal2 <VfxBool, VappNetworkSelectionProcessState> m_signalAutoCampOnResult;
    
    protected:
    VappNetworkSelectionPlmnNode m_campOnNode;
    mmi_sim_enum m_sim; // temp variable for set service mode
    VfxBool m_isAutoCampOn;
};

/***************************************************************************** 
 * VappNetworkSelectionInterface 
 *****************************************************************************/
// interface for manual network select 
class VappNetworkSelectionInterface : public VfxObject
{
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappNetworkSelectionInterface);
    // Methods
    public:
    VappNetworkSelectionInterface() : 
        m_parser(NULL), 
        m_provider(NULL), 
        m_sim(MMI_SIM_NONE), 
        m_list(NULL),
        m_waitingForClosed(VFX_FALSE),
        m_processState(VAPP_NETWORK_SELECTION_NO_PROCESS)
    {
        m_controller.m_signalCampOnResult.connect(this, &VappNetworkSelectionInterface::processSignal);
        m_controller.m_signalAutoCampOnResult.connect(this, &VappNetworkSelectionInterface::processSignal);
    };


    // Please call Init() when enter the network selection screen
    void Init(mmi_sim_enum sim) 
    {
        m_parser = NULL; 
        m_provider = NULL; 
        m_list = NULL;
        m_sim = sim;
        m_waitingForClosed = VFX_FALSE;
    };

    // Please call closed when the parent is closed
    void close() 
    {
        autoClosed();
        m_parser = NULL; 
        m_provider = NULL; 
        m_list = NULL;
    };

    // Prepare list
    // Prepare the list, m_signalListReady will be emit when list is updated
    // Return VFX_FALSE if currently cannot update list    
    VfxBool updateList(VfxObject *parent); 
    void updateListAfterCampOn();
    void abortGetList();

    // Get context of PLMN
    VfxU16 getCount();
    VfxWString getPlmnName(VfxId plmnId);
    VfxWString getPlmnRat(VfxId plmnId);
    VfxId getPlmnIconId(VfxId plmnId);
    VfxWString getAdditonalInformation(VfxId plmnId);

    // Camp on PLMN
    void campOn(VfxId plmnId);
    void autoCampOn();
    
    // Internal used
    void processSignal(VfxBool result, VappNetworkSelectionProcessState type);
    
    void autoClosed() 
    {
        if (isProcessing() && getProcessType() != VAPP_NETWORK_SELECTION_ABORT_GET_LIST)
    	{
            if (getProcessType() == VAPP_NETWORK_SELECTION_GET_LIST)
        	{
        	    m_parser->abortGetListBeforeClose();
                VFX_OBJ_CLOSE_INSTANCE(VappNetworkSelectionInterface);                
        	}
            else
            {
        	    m_waitingForClosed = VFX_TRUE;
            }
    	}
        else
        {
            VFX_OBJ_CLOSE_INSTANCE(VappNetworkSelectionInterface);
        }
    }
    void setProcess(VappNetworkSelectionProcessState type) 
    {
        m_processState = type; 
        m_signalStateChanged.emit();
    };
    void endProcess() 
    {
        m_processState = VAPP_NETWORK_SELECTION_NO_PROCESS;
        m_signalStateChanged.emit();
        if (m_waitingForClosed)
    	{
            VFX_OBJ_CLOSE_INSTANCE(VappNetworkSelectionInterface);
    	}
    };
    VfxBool isProcessing() {return (m_processState != VAPP_NETWORK_SELECTION_NO_PROCESS) ? VFX_TRUE : VFX_FALSE;};
    VappNetworkSelectionProcessState getProcessType() {return m_processState;} ;
    
    // Variable
    public:
    VfxSignal1 <VfxBool> m_signalListReady;
    VfxSignal1 <VfxBool> m_signalAbortGetList;
    VfxSignal1 <VfxBool> m_signalCampOnResult;
    VfxSignal1 <VfxBool> m_signalAutoCampOnResult;
    VfxSignal0 m_signalStateChanged;
    
    protected:
    VappNetworkSelectionListParser   *m_parser;
    VappNetworkSelectionListProvider *m_provider;
    VappNetworkSelectionController   m_controller;
    
    mmi_sim_enum         m_sim;
    VappSettingPlmnList *m_list;
    VfxBool              m_waitingForClosed;
    VappNetworkSelectionProcessState m_processState;
};

/***************************************************************************** 
 * VappManualNetworkSearchingPopup
 *****************************************************************************/
class VappManualNetworkSearchingPopup : public VcpIndicatorPopup
{
    // Method
    protected:
    virtual void onDeinit();
    
    // Variable
    public:
    VfxSignal0 m_signalPopupDestroyed;
};

/***************************************************************************** 
 * VappManualNetworkSelectionForm
 *****************************************************************************/
class VappManualNetworkSelectionForm : public VcpForm
{
    VFX_DECLARE_CLASS(VappManualNetworkSelectionForm);
    // Overrids
    public:
    //virtual void onInit();
    
    // Methods
    public:
    void setSim(mmi_sim_enum sim) {m_sim = sim;};
    void updateForm();

    VappManualNetworkSelectionForm() : m_isInit(VFX_FALSE), m_isUpdatingList(VFX_FALSE), m_progressPopup(NULL), m_searchingPopup(NULL), m_retryPopup(NULL) {m_currentPopup = NULL;};
    virtual void onDeinit();

    void clearCell();

    void onManualRefresh(VcpFormItemCell* sender, VfxId senderId);    
    void onCancelSearching(VfxObject* sender, VfxId id);
    void stopManualRefreshWhenExitPopup();
    void stopManualRefresh();
    void stopManualRefreshDone(VfxBool result);

    void onPlmnListReady(VfxBool result);
    void updatePlmnList();

    void onCampOn(VcpFormItemCell* sender, VfxId senderId);    
    void campOnPlmn(VfxId plmnId);
    void onCampOnFinish(VfxBool result);
    
    void onPopClicked(VfxObject* sender, VfxId id);

    // Variables
    public:
    private:
    VfxBool      m_isInit;
    mmi_sim_enum m_sim;
    VfxId        m_selectId;
    VfxBool      m_isUpdatingList;    

    VcpFormItemLauncherCell *m_manualRefreshCell;
    VcpIndicatorPopup       *m_progressPopup;
    VappManualNetworkSearchingPopup *m_searchingPopup;
    VcpConfirmPopup *m_retryPopup;    
    // The popup will be closed automatically when press HOME key, 
    // use a weak pointer to keep the current popup
    VfxWeakPtr<VfxBasePopup> m_currentPopup; 
};
#endif /* __VAPP_NETWORK_SELECTION_H__ */
 
