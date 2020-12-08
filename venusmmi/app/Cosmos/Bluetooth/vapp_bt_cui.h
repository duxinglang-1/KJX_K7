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
 *  vapp_bt_cui.h
 *
 * Project:
 * --------
 *  Cosmos
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
#include "MMI_features.h" 

#ifndef __VAPP_BT_CUI_H__
#define __VAPP_BT_CUI_H__

#ifdef __MMI_BT_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_include.h"
#include "vfx_app.h"
#include "..\..\framework\mmi_core\vfx_cui.h"
#include "vcui_bt_gprot.h"
#include "vapp_bt_page.h" // for VappBTPageBase


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappBtSelDevPage : public VappBTPageBase
{

public:    
    void onSearch(VfxObject* obj, VfxId id);
    VfxBool isSearching();
    virtual void onBack();
    static void btSelDevEventHandle(U32 event, void* para);


/*---------------------------------------------------------------------------*
 * Function: getCount()
 * Date:Nov/25/2011
 * Description: the count of dev list.
 *    
 *    @return: return the dev list count.
 *---------------------------------------------------------------------------*/
    virtual VfxU32 getCount() const;


/*---------------------------------------------------------------------------*
 * Function: getMenuEmptyText()
 * Date:Dec 19/2011
 * Description: get text when the dev list is empty.
 *    
 * Parameters
 *    @&text:  [OUT] the text resource
 *    @&color: [OUT] the text color
 *    @return: VFX_TRUE if success.
 *---------------------------------------------------------------------------*/
virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);

protected:
    virtual void onInit();
    virtual void onDeinit();

/*---------------------------------------------------------------------------*
 * Function: handleBtEvents()
 * Date:Dec 19/2011
 * Description: virtual function from VappBTPageBase, call back when a BT event arised.
 *    
 * Parameters
 *	  @event: the event Id.
 *    @para: the event paragrame.
 *---------------------------------------------------------------------------*/
	virtual void handleBtEvents(VfxU32 event, void* para);	

/*---------------------------------------------------------------------------*
 * Function: onClickedDev()
 * Date:Dec 19/2011
 * Description: virtual function from VappBTPageBase, call back when a dev in the list being clicked.
 *    
 * Parameters
 *    @index: the index of the dev being clicked.
 *    @dev_Info: the information of the dev which is clicked.
 *---------------------------------------------------------------------------*/
	virtual void onClickedDev(VfxU32 index, const srv_bt_cm_dev_struct* dev_Info);

/*---------------------------------------------------------------------------*
 * Function: getDevInfoByIndex()
 * Date:Dec 19/2011
 * Description: get the dev info by the index.
 *    
 * Parameters
 *    @index: the index of the dev.
 *    @return: return the dev information.
 *---------------------------------------------------------------------------*/
	virtual const srv_bt_cm_dev_struct* getDevInfoByIndex(U32 index);
private:
	enum
	{
		VAPP_BT_SEL_DEV_PAGE_BOTTOM_SEARCH_BUT_ID = 1,
		VAPP_BT_SEL_DEV_PAGE_BOTTOM_STOP_BUT_ID,
		VAPP_BT_SEL_DEV_PAGE_BOTTOM_BUT_ID_TOtAL
	};
	VfxBool m_isSearching;
    VcpTitleBar *m_btSelDevPageTitleBar;
    VcpToolBar *m_btSelDevPageBBar;
    VcpListMenu* m_btSelDevPageListMenu;
    //VfxBool m_btSelDevPageSelDevFlag;
    srv_bt_cm_dev_struct* m_selectDevInfo;
    VfxU32 m_recentUsedDevNum;
    srv_bt_cm_dev_struct m_recentUsedDev[SRV_BT_CM_MAX_USED_DEVICE_LIST];

};

class VappBtSelDevCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappBtSelDevCui);

public:
    virtual void onRun(void* args, VfxU32 argSize);
    static VfxBool btSelDevPreCheck(void);
    static VfxU32 m_btSelDevCuiRefCnt;
    static mmi_id m_btSelDevCuiId;
    VfxU32 getSelDevCodMask();
	
/*---------------------------------------------------------------------------*
 * Function: sendMsgToCaller()
 * Date:Dec 19/2011
 * Description: Duplicate codes.
 *	  
 *---------------------------------------------------------------------------*/
	void sendMsgToCaller(VfxBool aResult, VfxAppPostToCallerCb aCb);

/*---------------------------------------------------------------------------*
 * Function: addPageToScr()
 * Date:Jan/9/2012
 * Description: add VappBtSelDevPage to screen.
 *    
 * Parameters
 *    @*scr: [IN] the handle of the screen.
 *---------------------------------------------------------------------------*/
	void addPageToScr(VfxMainScr *scr);

/*---------------------------------------------------------------------------*
 * Function: btPowerOnEventHandle()
 * Date:Jan/17/2012
 * Description: handle the bt call back event.
 *    
 * Parameters
 *    @event: event id.
 *    @para:  event para.
 *---------------------------------------------------------------------------*/
    static void btPowerOnEventHandle(VfxU32 event, void* para);

/*---------------------------------------------------------------------------*
 * Function: onButtonClick()
 * Date:Jan/17/2012
 * Description: call back when user clicked confirm form button. 
 *    
 * Parameters
 *    @sender: 
 *    @id: 
 *---------------------------------------------------------------------------*/
    void onButtonClick(VfxObject* sender, VfxU32 id);

public:
	VappBTSmallScr* m_smallScr;
	S32 m_serviceHandle; //service handle, if it is less than 0, it means invalid handle
	VfxS32 m_btPowerOnScrcmSrvHd;

protected:
	using VfxApp::onProcessClose;
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual void onInit();
    virtual void onDeinit();

/*---------------------------------------------------------------------------*
 * Function: onScrBack()
 * Date:Jan/17/2012
 * Description: virtual function from VfxApp,
 *    When receiving the BACK key in the screen, the function will be invoked.
 * Parameters
 *    @*scr: 
 *    @return:
 *---------------------------------------------------------------------------*/
	virtual VfxBool onScrBack(VfxAppScr *scr);

private:
    VfxU32 m_btSelDevCuiCodMask;
};

class VappBtPowerOnCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappBtPowerOnCui);

public:
    virtual void onRun(void* args, VfxU32 argSize);
    static mmi_id m_btPowerOnCuiId;
    //virtual mmi_ret onProc(mmi_event_struct *evt);

/*---------------------------------------------------------------------------*
 * Function: btPowerOnEventHandle()
 * Date:Jan/17/2012
 * Description: handle the bt call back event.
 *    
 * Parameters
 *    @event: event id.
 *    @para:  event para.
 *---------------------------------------------------------------------------*/
    static void btPowerOnEventHandle(U32 event, void* para);

/*---------------------------------------------------------------------------*
 * Function: sendMsgToCaller()
 * Date:Dec 19/2011
 * Description: Duplicate codes.
 *    
 *---------------------------------------------------------------------------*/
	void sendMsgToCaller(VfxBool aResult, VfxAppPostToCallerCb aCb);

/*---------------------------------------------------------------------------*
 * Function: onButtonClick()
 * Date:Jan/17/2012
 * Description: call back when user clicked confirm form button. 
 *    
 * Parameters
 *    @sender: 
 *    @id: 
 *---------------------------------------------------------------------------*/
    void onButtonClick(VfxObject* sender, VfxU32 id);



/*---------------------------------------------------------------------------*
 * Function: showConfirmScreen()
 * Date:Jan/17/2012
 * Description: show globle popup to get user's choice.
 *    
 *---------------------------------------------------------------------------*/
	void showConfirmScreen(void);


/*---------------------------------------------------------------------------*
 * Function: showIndictorPopup()
 * Date:Jan/17/2012
 * Description: show indictor popup
 *    
 *---------------------------------------------------------------------------*/
	void showIndictorPopup(void);


protected:
	using VfxApp::onProcessClose;
    virtual VfxAppCloseAnswerEnum onProcessClose(VfxAppCloseOption options);
    virtual void onDeinit();

private:
    VfxS32 m_btPowerOnScrcmSrvHd;
	VappBTSmallScr* m_smallScr;
};

#endif  // __MMI_BT_SUPPORT__

#endif  /* __VAPP_BT_CUI_H__ */
