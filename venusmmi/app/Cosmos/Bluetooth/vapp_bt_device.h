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
 *  vapp_bt_device.h
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

#ifndef __VAPP_BT_DEVICE_H__
#define __VAPP_BT_DEVICE_H__

#ifdef __MMI_BT_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "BTcmSrvGprot.h"
#include "BtAudioSrvGprot.h"
#include "vapp_bt_page.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
	VBT_PAIRED_STATE_IDLE,
	VBT_PAIRED_STATE_CONNECTING,
	VBT_PAIRED_STATE_DISCONNECTING,
	VBT_PAIRED_STATE_END
}vbt_state;
/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappBTPairedListPage: public VappBTPageBase
{
//	VFX_DECLARE_CLASS(VappBTPairedListPage);
	
public:
	virtual void onDeinit();
	
	virtual void onInit();
	
	void onOptionMenuClick(VfxObject *sender, VfxId Idx);/*click option menu one item, display rename or delete popup*/
	
	void setSearchBottombar();	 /*click search bottom bar*/
	void onSearchBarClick(VfxObject *sender, VfxId Idx);  /*the bottom bar handle to enter a new page of search device*/


	void onRenamePopupBarClick(VfxObject* sender, VcpInputPopupButtonEnum chosen); /*when on rename or delete or authorize Popup, press yes or no*/
	void onDeletePopupBarClick(VfxObject* sender, VfxId chosen); /*when on rename or delete or authorize Popup, press yes or no*/
	void onConnCancelClick(VfxObject* sender, VfxFloat curr_progress);
	//void onschFailBarClick(VfxObject *sender,VfxId Id);
	
	void connectComplete(void *para);
	void disconComplete(void *para);
	void disconnInd(void *para);
    static void audioSrvNotify(BtAudEvent evt, U32 arg, void *userData);
	
	   /*---------------------------------------------------------------------------*
	* Function: getMenuEmptyText()
	* Date:Dec 5/2011
	* Description: Get the empty text resource for the text when list menu is empty
	*	 
	* Parameters
	*	 @&text: [OUT] the text resource
	*	 @&color: [OUT] the text color
	*	 @return: VFX_TURE is success
	*---------------------------------------------------------------------------*/
	   virtual VfxBool getMenuEmptyText(VfxWString &text,VcpListMenuTextColorEnum &color); 

protected:
/*---------------------------------------------------------------------------*
 * Function: handleBtEvents()
 * Date:Dec 7/2011
 * Description: virtual function from VappBTPageBase, call back when a BT event arised.
 *    
 * Parameters
 *    @event: the event Id.
 *    @para: the event paragrame.
 *---------------------------------------------------------------------------*/
	virtual void handleBtEvents(VfxU32 event, void* para);

/*---------------------------------------------------------------------------*
 * Function: onClickedDev()
 * Date:Dec 5/2011
 * Description: virtual function from VappBTPageBase, call back when a dev in the list being clicked.
 *    
 * Parameters
 *    @dev_Info: the information of the dev which is clicked.
 *---------------------------------------------------------------------------*/
	virtual void onClickedDev(VfxU32 index, const srv_bt_cm_dev_struct* dev_Info);

/*---------------------------------------------------------------------------*
 * Function: onUserSelectSIM()
 * Date:Dec 5/2011
 * Description: call back function,  be called when user select a prefer sim card.
 *	  
 * Parameters
 *	  @item: item user clicked.
 *	  @id: item ID.
 *---------------------------------------------------------------------------*/
	void onUserSelectSIM(VfxObject* item, VfxId id);

/*---------------------------------------------------------------------------*
 * Function: onEnter()
 * Date:Dec 7/2011
 * Description: virtual function from VfxPage, call back While entering the page to be active.
 *    
 * Parameters
 *    @isBackward: VFX_TRUE if back to be active from other page.
 *---------------------------------------------------------------------------*/
	virtual void onEnter(VfxBool isBackward);

private:
	void connect();
	void disconnect(); 
	void rename();	
	void delte();	
#ifdef __MMI_BT_AUTHORIZE__
    void authorize();
#endif  // __MMI_BT_AUTHORIZE__

private:
    VfxU32 m_audSrvHd;
	srv_bt_cm_bt_addr m_devClicked_addr;
	VfxWChar m_devClickedName[SRV_BT_CM_BD_UCS2_NAME_LEN];
    VcpIndicatorPopup *m_connPopup;
	VcpIndicatorPopup *m_disconnPopup;
    VfxU8 m_state;
	
};


#ifdef __MMI_BT_AUTHORIZE__
class VappBTAuthorizePage: public VfxPage, public IVcpListMenuContentProvider
{
//    VFX_DECLARE_CLASS(VappBTAuthorizePage);
    
public:
	VappBTAuthorizePage(srv_bt_cm_bt_addr aDevAddress)
	{
		m_DevAddress = aDevAddress;
	}

    virtual void onInit();


/*---------------------------------------------------------------------------*
 * Function: getItemImage()
 * Date:Dec 5/2011
 * Description: virtual function from IVcpListMenuContentProvider, give image of list items.
 *    
 * Parameters
 *    @index: [IN] the index of item
 *    @fieldType: [IN] the type of the field in the cell
 *    @&image: [OUT] the image resource
 *    @return: VFX_TURE is success
 *---------------------------------------------------------------------------*/
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);
	

/*---------------------------------------------------------------------------*
 * Function: getItemState()
 * Date:Dec 9/2011
 * Description: virtual from IVcpListMenuContentProvider, give the item status.
 *    
 * Parameters
 *    @index: the index of the item to be given status.
 *    @return: item status.
 *---------------------------------------------------------------------------*/
	virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
	

/*---------------------------------------------------------------------------*
 * Function: getCount()
 * Date:Dec 9/2011
 * Description: the count of list items .
 *    
 *    @return: return the dev list count.
 *---------------------------------------------------------------------------*/
    virtual VfxU32 getCount() const;

/*---------------------------------------------------------------------------*
 * Function: setAlwaysAskStatus()
 * Date:Dec 9/2011
 * Description: set the status of m_alwaysAskStatus
 *    
 * Parameters
 *    @aAlwaysAsk: the value to be set.
 *---------------------------------------------------------------------------*/
	void setAlwaysAskStatus(srv_bt_cm_authorize_type aAlwaysAsk);
    void onItemSelect(VcpListMenu *menuList, VfxU32 item_id);

private:
	srv_bt_cm_bt_addr m_DevAddress;
	srv_bt_cm_authorize_type m_alwaysAskStatus;
	VcpListMenu			*m_listMenu;
};
#endif  // __MMI_BT_AUTHORIZE__

#ifdef __GEMINI__
class VappBTPreferSIMPage: public VfxPage, public IVcpListMenuContentProvider
{
    
public:
	
	VappBTPreferSIMPage(srv_bt_cm_bt_addr aDevAddress)
	{
		m_DevAddress = aDevAddress;
	}
	
    virtual void onInit();


/*---------------------------------------------------------------------------*
 * Function: getItemImage()
 * Date:Dec 5/2011
 * Description: virtual function from IVcpListMenuContentProvider, give image of list items.
 *    
 * Parameters
 *    @index: [IN] the index of item
 *    @fieldType: [IN] the type of the field in the cell
 *    @&image: [OUT] the image resource
 *    @return: VFX_TURE is success
 *---------------------------------------------------------------------------*/
    virtual VfxBool getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color);
	

/*---------------------------------------------------------------------------*
 * Function: getItemState()
 * Date:Dec 9/2011
 * Description: virtual from IVcpListMenuContentProvider, give the item status.
 *    
 * Parameters
 *    @index: the index of the item to be given status.
 *    @return: item status.
 *---------------------------------------------------------------------------*/
	virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;
	

/*---------------------------------------------------------------------------*
 * Function: getCount()
 * Date:Dec 9/2011
 * Description: the count of list items .
 *    
 *    @return: return the dev list count.
 *---------------------------------------------------------------------------*/
    virtual VfxU32 getCount() const;
    void onItemSelect(VcpListMenu *menuList, VfxU32 item_id);

private:
	srv_bt_cm_bt_addr m_DevAddress;
	mmi_sim_enum m_selectSIM;
	VfxS32 m_availableSIMCount;
	VcpListMenu			*m_listMenu;
	mmi_sim_enum	m_insertSimEnum[MMI_SIM_TOTAL];
};
#endif  // __GEMINI__

#endif // __MMI_BT_SUPPORT__

#endif /* __VAPP_BT_DEVICE_H__ */
