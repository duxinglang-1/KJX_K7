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
 *  vapp_bt_search.h
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

#ifndef __VAPP_BT_SEARCH_H__
#define __VAPP_BT_SEARCH_H__

#ifdef __MMI_BT_SUPPORT__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_bt_page.h"

/***************************************************************************** 
 * Define 
 *****************************************************************************/
 class VcpTitleBar;
class VcpToolBar;
 class VcpIndicatorPopup;
#define MAX_INQUIRY_DURATION        (60)
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
	VBT_SCH_STATE_IDLE,
	VBT_SCH_STATE_SEARCHING,
	VBT_SCH_STATE_PAIRING,
	VBT_SCH_STATE_END
}vbt_sch_state;

/***************************************************************************** 
 * Class 
 *****************************************************************************/

class VappBTSearchDevPage: public VappBTPageBase
{
//	VFX_DECLARE_CLASS(VappBTSearchDevPage);
	
public:

	virtual void onDeinit();
	
	virtual void onInit();
	virtual void onBack();

	void setBottombar();
	void onStopBarClick(VfxObject* sender, VfxId Idx);

	void onResearchingBarClick(VfxObject* sender, VfxId Idx);
	
    void searchComplete(void *para);

    void bondResult(void *para);
    void pairResult(void *para);

/*---------------------------------------------------------------------------*
 * Function: getMenuEmptyText()
 * Date:Dec 12/2011
 * Description: virtual function from IVcpListMenuContentProvider
 *    
 * Parameters
 *    @&text: the text to be show when dev list is empty.
 *    @&color: text color.
 *    @return: VFX_TRUE if success.
 *---------------------------------------------------------------------------*/
    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color);
#ifdef __MMI_BT_AUTHORIZE__

/*---------------------------------------------------------------------------*
 * Function: onAlwayConnBarClick()
 * Date:Dec 7/2011
 * Description: slot function, call back when user clicked "always connect bar".
 *    
 * Parameters
 *    @sender: send obj handle
 *    @chosen: the button id of user clicked.
 *---------------------------------------------------------------------------*/
    void onAlwayConnBarClick(VfxObject* sender, VfxId chosen);
#endif  // __MMI_BT_AUTHORIZE__
	
protected:
	

/*---------------------------------------------------------------------------*
 * Function: onClickedDev()
 * Date:Dec 12/2011
 * Description: virtual function from VappBTPageBase, call back when a dev in the list being clicked.
 *    
 * Parameters
 *    @dev_Info: 
 *---------------------------------------------------------------------------*/
	virtual void onClickedDev(VfxU32 index, const srv_bt_cm_dev_struct* dev_Info); 


/*---------------------------------------------------------------------------*
 * Function: handleBtEvents()
 * Date:Dec 12/2011
 * Description: virtual function from VappBTPageBase, call back when a BT event arised.
 *    
 * Parameters
 *    @event: the event Id.
 *    @para: the event paragrame.
 *---------------------------------------------------------------------------*/
	virtual void handleBtEvents(VfxU32 event, void* para);

private:
	void pairDev(VfxU32 index);

private:
	VcpTitleBar *m_schTitle;
	VcpToolBar *m_bottomBar;
		
	VfxBool m_firstPair;
	VfxBool m_initiatorPair;
	VcpIndicatorPopup *m_pairingPopup;
	VfxU32 m_state;
	VfxS32 m_pairIndex;
	srv_bt_cm_bt_addr m_bondDevAddr;
};

#endif //__MMI_BT_SUPPORT__


#endif // __VAPP_BT_SEARCH_H__


