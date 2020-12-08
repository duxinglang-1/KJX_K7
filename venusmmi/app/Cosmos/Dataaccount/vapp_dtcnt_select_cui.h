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
 *  vapp_dtcnt_select_cui.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file define the class to select dtcnt
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_CUI_H__
#define __VAPP_DTCNT_CUI_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifdef __TCPIP__
#include "mmi_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_dtcnt_def.h"
#include "vapp_dtcnt_gprot.h"
#include "vapp_dtcnt.h"
#include "mmi_rp_vcui_dtcnt_def.h"
#include "vcui_dtcnt_select_gprot.h"
#include "vcp_menu_popup.h"
#include "mmi_frm_utility_gprot.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

// internal use
enum VappDtcntSelectItemType
{
    VAPP_DTCNT_SELECT_ITEM_NONE,
    VAPP_DTCNT_SELECT_ITEM_AUTO,
    VAPP_DTCNT_SELECT_ITEM_ALWAYS_ASK,
    VAPP_DTCNT_SELECT_ITEM_CSD,
    VAPP_DTCNT_SELECT_ITEM_GPRS,
    VAPP_DTCNT_SELECT_ITEM_TOTAL    
}; 


// internal use
enum VappDtcntSelectAcctType
{
    VAPP_DTCNT_SELECT_ACCT_DEFAULT,
    VAPP_DTCNT_SELECT_ACCT_USER_DEFINED,
    VAPP_DTCNT_SELECT_ACCT_END
};


// internal use
typedef struct
{
    VappDtcntSelectItemType itemType;
    VfxU16 itemName;
} VappDtcntSelectItem;


/***************************************************************************** 
 * Class VappDtcntSelectCfmPop
 *****************************************************************************/

/*
 * DESCRIPTION
 *  confirm popup customized for cbm select cui
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */

class VappDtcntSelectCfmPop: public VcpConfirmPopup
{
protected:
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
};


/***************************************************************************** 
 * Class VappDtcntSelectParam
 *****************************************************************************/

/*
 * DESCRIPTION
 *  select dtcnt parameter class,used to customized data account selection CUI
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */

class VappDtcntSelectParam : public VfxObject
{ 

public:
    VappDtcntSelectParam(); // default constructor
    virtual ~VappDtcntSelectParam() {};

// Override
public:
    virtual void onInit();
    virtual void onDeinit();

// Methods to get member value
public:
    // get method
    VfxU8 getBearers() {return m_bearers;}
    
    VfxU8 getAppId() {return m_appId;}
    
    VfxU32 getSimAccountID(VfxU32 index) {return m_simAccountId[index];}
    
    cui_dtcnt_select_option_enum getOptions()  {return m_options;}
    
    cui_dtcnt_select_sim_enum getSimSelection() {return m_simSelection;}
    
    cui_dtcnt_select_type_enum getSelectType() {return m_selectType;}

    // set method
    void setBearers(VfxU8 bearers) {m_bearers = bearers;}
    
    void setAppId(VfxU8 appId) {m_appId = appId;}
    
    void setSimAccountID(VfxU32 index, VfxU32 accountId) {m_simAccountId[index] = accountId;}
    
    void setOptions(cui_dtcnt_select_option_enum options) {m_options = options;}
    
    void setSimSelection(cui_dtcnt_select_sim_enum simSelection) {m_simSelection = simSelection;}
    
    void setSelectType(cui_dtcnt_select_type_enum selectType) {m_selectType = selectType;}

// Variable
private:
    VfxU8 m_bearers;        // account list bearer filter
    VfxU8 m_appId;          // APP ID of each APP
    VfxU32 m_simAccountId[MMI_SIM_TOTAL]; // encoded account id, used to get account name as hint or mark selected account before 

    cui_dtcnt_select_option_enum   m_options;       // select option type
    cui_dtcnt_select_sim_enum      m_simSelection; // SIM profile selection filter
    cui_dtcnt_select_type_enum     m_selectType;         // select CUI type
};


/***************************************************************************** 
 * Class VappDtcntSelectItemInfo
 *****************************************************************************/

/*
 * DESCRIPTION
 *  data account cui list item base info.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntSelectItemInfo : public VfxObject
{

public:
    VappDtcntSelectItemInfo() : 
        m_profileId(0), 
        m_itemStrId(VFX_RES_ID_NULL), 
        m_accountType(VAPP_DTCNT_SELECT_ACCT_DEFAULT), 
        m_itemType(VAPP_DTCNT_SELECT_ITEM_NONE) 
    {
        mmi_wcscpy((WCHAR*)m_name, (WCHAR*)L"");
        mmi_wcscpy((WCHAR*)m_address, (WCHAR*)L"");
    }
    virtual ~VappDtcntSelectItemInfo() {}

// override
public:
    virtual void onInit();
    virtual void onDeinit();

//method (get/set)
public:
    VfxU32 getProfileId() {return m_profileId;}
    
    VfxU16 getItemStrId() {return m_itemStrId;}
    
    VappDtcntSelectAcctType getAccountType() {return m_accountType;}
    
    VappDtcntSelectItemType getItemType() {return m_itemType;}
    
    VfxWChar *getName() {return m_name;}
    
    VfxWChar *getAddress() {return m_address;}
    
    void setProfileId(VfxU32 profileId) {m_profileId = profileId;}
    
    void setItemStrId(VfxU16 itemStrId) {m_itemStrId = itemStrId;}
    
    void setAccountType(VappDtcntSelectAcctType accountType){m_accountType = accountType;}
    
    void setItemType(VappDtcntSelectItemType itemType){m_itemType = itemType;}
    
    void setName(VfxWChar *name){mmi_wcscpy((WCHAR*)m_name, (WCHAR*)name);}
    
    void setAddress(VfxWChar *address){mmi_wcscpy((WCHAR*)m_address, (WCHAR*)address);}

private:
    VfxU32 m_profileId; // profile id
    VfxU16 m_itemStrId; // string id for special type, such as automatic 
    VappDtcntSelectAcctType m_accountType; // account type
    VappDtcntSelectItemType m_itemType;    // select cui list item type
    VfxWChar m_name[MAX_DATA_ACCOUNT_NAME_LEN + 1]; // account name
    VfxWChar m_address[MAX_DTCNT_LIST_ADDR_LEN]; // account address
};


/***************************************************************************** 
 * Class VappDtcntSelectDispContext
 *****************************************************************************/

/*
 * DESCRIPTION
 *  used for cui to store display context
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntSelectDispContext : public VfxObject
{

public:
    VappDtcntSelectDispContext();
    virtual ~VappDtcntSelectDispContext() {}

// override
public:
    virtual void onInit();
    virtual void onDeinit();

// method
public:
    //get/set
    VfxU32 getListItemNumber() {return m_listItemNumber;}
    
    VappDtcntSelectItemInfo *getListInfo(VfxU32 index) {return m_listInfo[index];}
    
    void setListItemNumber(VfxU32 listItemNumber) {m_listItemNumber = listItemNumber;}
    
    void setListInfo(VfxU32 index, VappDtcntSelectItemInfo *info);
    
    // other
    void arrangeAcctListInfo(
        VappDtcntSelectItemInfo **ListInfo,  // list info, use const point of m_listInfo
        VfxU32 start,                       // start index of listinfo (included)
        VfxU32 end                          // end index of listinfo (not included)            
    );
    
    void swapListInfo(VappDtcntSelectItemInfo *ListInfo1, VappDtcntSelectItemInfo *ListInfo2);

    // prepare list info for single select or cbm select cui
    void prepareListInfo(
        VappDtcntSelectParam *param,    // select parameter
        mmi_sim_enum simEnum,
        VfxBool isSingleSelect          // single select if true, or for CBM
    );

    //
    VfxU32 getSimAccountId(VfxU32 index) {return m_simAccountId[index];}
    VfxWChar *getSimAccountName(VfxU32 index) {return m_simAccountName[index];}
    VfxBool getSelectedFlag() {return m_selectedFlag;}

    //set
    void setSimAccountId(VfxU32 index, VfxU32 acctId) {m_simAccountId[index] = acctId;}
    void setSimAccountName(VfxU32 index, VfxWChar *name) {mmi_wcscpy((WCHAR*)m_simAccountName[index], (WCHAR*)name);}
    void setSelectedFlag(VfxBool selectedFlag) {m_selectedFlag = selectedFlag;}
// varibale
private:
    VfxU32 m_listItemNumber;
    VappDtcntSelectItemInfo *m_listInfo[VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM + MAX_DATA_ACCOUN_CUI_FIX_ITEM];

    VfxU32 m_simAccountId[MMI_SIM_TOTAL];
    VfxWChar m_simAccountName[MMI_SIM_TOTAL][MAX_DATA_ACCOUNT_NAME_LEN + 1];

    VfxBool m_selectedFlag; // flag used for back key
};


/***************************************************************************** 
 * Class VappDtcntSelectPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  page for single select cui page and dual select cui second page.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntSelectPage : public VfxPage, public IVcpListMenuContentProvider
{
 
public:
    VappDtcntSelectPage() : 
        m_scrPageNum(1),
        m_currIndex(0),
        m_sim(MMI_SIM1),
        m_listMenu(NULL), 
        m_dispContext(NULL) 
    {
    }
    VappDtcntSelectPage(VfxU32 scrPageNum, mmi_sim_enum sim, VappDtcntSelectDispContext *dispContext) :
        m_scrPageNum(scrPageNum),
        m_currIndex(0),
        m_sim(sim),
        m_listMenu(NULL), 
        m_dispContext(dispContext) 
    {
    }
    virtual ~VappDtcntSelectPage() {}

// override from Provider
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxU32 getCount() const;

    virtual VfxBool getMenuEmptyText(
            VfxWString &text,                // [OUT] the text resource
            VcpListMenuTextColorEnum &color  // [OUT] the text color
            ) ;

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        );

// override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onBack();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param){};
    virtual void onEnter(VfxBool isBackward);
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__    
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
#endif

// signal
protected:
    // this signal is used to post evt to parent id when single select,
    // or update first or second account when choose dual account
    void onItemTapped(
        VcpListMenu *sender,    // list menu
        VfxU32 index            // list index
    );

    // get real account id
    VfxU32 getRealAccountId(
        VfxU32 acctId //input account id, may be Automatic
    ) const;

private:
    VfxU32 m_scrPageNum;
    VfxS32 m_currIndex;
    mmi_sim_enum m_sim;
    VcpListMenu *m_listMenu;
    VappDtcntSelectDispContext *m_dispContext;
};


/***************************************************************************** 
 * Class VappDtcntDualSelectPage
 *****************************************************************************/

/*
 * DESCRIPTION
 *  page for dual select cui first page.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntDualSIMSelectPage : public VfxPage, public IVcpListMenuContentProvider
{

public:
    VappDtcntDualSIMSelectPage() : 
        m_scrPageNum(1), 
        m_menu(NULL), 
        m_dispContext(NULL) 
    {
    }
    VappDtcntDualSIMSelectPage(VfxU32 scrPageNum, VappDtcntSelectDispContext *dispContext) : 
        m_scrPageNum(scrPageNum),
        m_menu(NULL), 
        m_dispContext(dispContext) 
    {
    }
    virtual ~VappDtcntDualSIMSelectPage() {}

// override from Provider
public:
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    
    virtual VfxBool getItemIsDisabled(
        VfxU32 index       // [IN] the index of item
        ) const {return VFX_FALSE;}
    
    virtual VfxBool getItemTextFormat(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VcpRichTextFormat &format          // [OUT] the text resource
        ) {return VFX_FALSE;}

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    virtual void closeItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc Image               // [IN] the image resource
        ) {}

    virtual VfxU32 getCount() const;

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const {return VCP_LIST_MENU_ITEM_STATE_NONE;}

    virtual VfxBool getItemStateValidation(
        VfxU32 index,                  // [IN] index of the item
        VcpListMenuItemStateEnum state // [IN] the state to be checked
        ) const {return VFX_TRUE;}

    virtual VfxBool swapItem(
        VfxU32 index1, // [IN] index of the first item
        VfxU32 index2  // [IN] index of the second item
        ) {return VFX_FALSE;}

// override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onBack();
    virtual void onQueryRotateEx(VfxScreenRotateParam & param){};
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__    
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
#endif

// signal
protected:
    void onDualItemTapped(
        VcpListMenu *sender, 
        VfxU32 index
    );

    void updateList();

private:
    VfxU32 m_scrPageNum;
    VcpListMenu *m_menu;
    VappDtcntSelectDispContext *m_dispContext;
};


/***************************************************************************** 
 * Class VappDtcntSelectScr
 *****************************************************************************/

/*
 * DESCRIPTION
 *  main screen of data account CUI.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntSelectScr : public VfxMainScr
{

public:
    // default constructor just use for VFX_IMPLEMENT_CLASS
    VappDtcntSelectScr();
    VappDtcntSelectScr(mmi_id cuiId);
    virtual ~VappDtcntSelectScr() {}

// override
public:
    virtual void onInit(); // prepage list data
    virtual void onDeinit();
    virtual void on1stReady(); // display list
    virtual void onQueryRotateEx(VfxScreenRotateParam & param){};

// method
public:
    mmi_id getCuiId() {return m_cuiId;}
    VfxU32 getPageNum() {return m_pageNum;}
    VappDtcntSelectDispContext *getDispContext() {return m_dispContext;}
    void update();
    void setSimType(mmi_sim_enum simType);
#ifdef __DTCNT_SIM_HOT_SWAP_SUPPORT__    
    void onSimChangeEvt(VfxBool flag, mmi_sim_enum sim);
#endif
#ifdef __MMI_CBM_ALWAYS_ASK__
protected:
    void onAlwaysAskListSelect(
        VcpMenuPopup *sender, // sender
        VcpMenuPopupEventEnum evt, //evt
        VcpMenuPopupItem *item // item
    );

    void onAlwaysAskConfirmPopup(
        VfxObject *obj, // sender
        VfxId id        // id
    );
#endif
private:
    mmi_id m_cuiId; // use this to record group id
    VfxU32 m_pageNum; // sim1/sim2 page + selectpage
    VappDtcntSelectDispContext *m_dispContext; // data for select cui
    mmi_sim_enum m_sim;
};


/***************************************************************************** 
 * Class VappDtcntSelect
 *****************************************************************************/

/*
 * DESCRIPTION
 *  data account select cui class.
 *
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VappDtcntSelect : public VfxCui
{
    VFX_DECLARE_CLASS(VappDtcntSelect);
protected:
    using VfxApp::onProcessClose;

public:  
// Constructor / Destructor
    VappDtcntSelect() : m_scr(NULL), m_param(NULL) {}
    virtual ~VappDtcntSelect() {}
    
// Override
public:
    // initial parameter and entry main src
    virtual void onRun(
        void *arg,          // parameter
        VfxU32 argSize      // parameter size  
    ); 
    virtual mmi_ret onProc(
        mmi_event_struct * evt
    );

    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);

    virtual void onInit();

    virtual void onDeinit();

// Method
public:
    VappDtcntSelectScr* getScr() {return m_scr;}
    void getDtcntParam(VappDtcntSelectParam **param) {*param = m_param;}
    void createDtcntParamObject();

// Implementation

private:
    VappDtcntSelectScr *m_scr;
    VappDtcntSelectParam *m_param;
};
#endif
#endif /* __VAPP_DTCNT_CUI_H__ */

