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
 *  vapp_sync_accnt_list_menu.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Alarm list page.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_rp_vapp_sync_def.h"
#include "GlobalResDef.h"

#include "vapp_sync_accnt_list.h"
#include "vapp_sync_remote_accnt_list.h"
#include "vapp_sync_phone_accnt_list.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define ID_TOOLBAR_SYNC_NEWSYNC	'SYNC'

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappSyncAccntListPage
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncAccntListPage", VappSyncAccntListPage, VcpTabCtrlPage);
void VappSyncAccntListPage::onInit(void)
{
	VcpTabCtrlPage::onInit();

	// add 3 tab, and set to first
	addTab(VAPP_SYNC_ACCNT_REMOTE, VFX_WSTR_RES(STR_ID_VAPP_SYNC_REMOTE), VcpStateImage(IMG_ID_VAPP_SYNC_REMOTE));
#ifdef __MMI_SYNCML_DEVICE_SYNC__
	addTab(VAPP_SYNC_ACCNT_PHONE, VFX_WSTR_RES(STR_ID_VAPP_SYNC_PHONE), VcpStateImage(IMG_ID_VAPP_SYNC_PHONE));
#endif
	VfxU8 value = 0;
	VfxId currTab;
	VfxS16 errCode;
	
	ReadValue(NVRAM_EF_VAPP_SYNC_LAST_TAB, &value, DS_BYTE, &errCode);
	currTab = (value == 0) ? VAPP_SYNC_ACCNT_REMOTE : VAPP_SYNC_ACCNT_PHONE;
	
	setCurrTab(currTab);

	m_signalTabSwitched.connect(this, &VappSyncAccntListPage::onTabSwitch);
}

VfxPage *VappSyncAccntListPage::onCreateTabPage(VfxId tabId)
{
	VfxPage *page = NULL;
	
    switch(tabId)
    {
	    case VAPP_SYNC_ACCNT_REMOTE:
		{
			VappSyncRemoteAccntListPage *remotePage;
			VFX_OBJ_CREATE(remotePage, VappSyncRemoteAccntListPage, this);
			page = remotePage;
	        break;
	    }
		
#ifdef __MMI_SYNCML_DEVICE_SYNC__
	    case VAPP_SYNC_ACCNT_PHONE:
		{
			VappSyncPhoneAccntListPage *phonePage;
			VFX_OBJ_CREATE(phonePage, VappSyncPhoneAccntListPage, this);
			page = phonePage;
	        break;
	    }
#endif
		default:
			VFX_ASSERT(!"Wrong Tab page");
    }

	return page;
}

void VappSyncAccntListPage::onTabSwitch(VfxObject *obj, VfxId tabId)
{
	VfxU8 currTab = (tabId == VAPP_SYNC_ACCNT_REMOTE) ? 0 : 1;
	
	VfxS16 errCode;
	WriteValue(NVRAM_EF_VAPP_SYNC_LAST_TAB, &currTab, DS_BYTE, &errCode);

	VcpTabCtrlPage::onTabSwitched(tabId);
}

