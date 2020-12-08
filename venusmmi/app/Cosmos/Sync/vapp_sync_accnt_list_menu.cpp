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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#include "GlobalResDef.h"
#include "mmi_rp_vapp_sync_def.h"

#include "vfx_string.h"
#include "vfx_adp_device.h"
#include "vcp_confirm_popup.h"

#include "vapp_sync.h"
#include "vapp_sync_accnt_list_menu.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define RETURN_IF_FAIL(p) if (!(p)) { return; }
#define RETURN_VAL_IF_FAIL(p, val) if (!(p)) { return val; }


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappSyncAccntListMenu
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSyncAccntListMenu", VappSyncAccntListMenu, VcpGroupListMenu);
void VappSyncAccntListMenu::onInit(void)
{
	VcpGroupListMenu::onInit();

	setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);	
	setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX);
	setContentProvider(this);
	
	m_signalItemTapped.connect(this, &VappSyncAccntListMenu::onItemTap);
	m_signalItemLongTapped.connect(this, &VappSyncAccntListMenu::onLongTap);

	m_nAccnt = getUpdatedCount();
	VappSyncAccntListMenu::sortIndexList(m_indexArray, m_nAccnt);
}

void VappSyncAccntListMenu::onLongTap(VcpGroupListMenu *obj, VcpMenuPos pos)
{
	vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
	
	VcpMenuPopup *menuPopup;
	
	VFX_OBJ_CREATE(menuPopup, VcpMenuPopup, this);
	menuPopup->setAutoDestory(VFX_TRUE);

	VfxWString title;
	getItemTextIfPresent(pos, VCP_LIST_MENU_FIELD_TEXT, title);
	menuPopup->setTitle(title);
	
	menuPopup->addItem(VAPP_SYNC_ACCNT_LIST_ACTION_SYNC, VFX_WSTR_RES(STR_ID_VAPP_SYNC_NOW));
	menuPopup->addItem(VAPP_SYNC_ACCNT_LIST_ACTION_DELETE, VFX_WSTR_RES(STR_GLOBAL_DELETE));
	menuPopup->addItem(VAPP_SYNC_ACCNT_LIST_ACTION_VLOG, VFX_WSTR_RES(STR_ID_VAPP_SYNC_LOG));

	// connect menu callback signal
	menuPopup->m_signalMenuCallback.connect(this, &VappSyncAccntListMenu::onMenuCallack);
	menuPopup->showMenu();

	m_index = pos.pos;
}

VfxBool VappSyncAccntListMenu::getItemText(
									VcpMenuPos pos, 				 // [IN] the position of item
									VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
									VfxWString &text,				 // [OUT] the text resource
									VcpListMenuTextColorEnum &color  // [OUT] the text color
									)
{
	switch(fieldType)
	{
		case VCP_LIST_MENU_FIELD_TEXT:
			return getText(getAccntIndex(pos.pos), text);
			
		case VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT:
			return getHeaderText(text);
			
		default:
			break;
	}
	
	return VFX_FALSE;
}	

VfxBool VappSyncAccntListMenu::getItemImage(
	VcpMenuPos pos, 				 // [IN] the position of item
	VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
	VfxImageSrc &image				 // [OUT] the image resource
	)
{
	if ((pos.pos >= 0) &&
		(fieldType == VCP_LIST_MENU_FIELD_ICON) &&
		isShowIcon(getAccntIndex(pos.pos)))
	{
		image.setResId(IMG_ID_VAPP_STATUS_SYNC_ERROR);
		
		return VFX_TRUE;
	}
	
	return VFX_FALSE;
}

void VappSyncAccntListMenu::onMenuCallack(
								VcpMenuPopup *menu, 
								VcpMenuPopupEventEnum evt, 
								VcpMenuPopupItem *item)
{
    if (evt == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
    	switch (item->getId())
    	{
    		case VAPP_SYNC_ACCNT_LIST_ACTION_SYNC:
			case VAPP_SYNC_ACCNT_LIST_ACTION_VLOG:
				m_signalAction.postEmit(this, item->getId(), getAccntIndex(m_index));
				break;
				
			case VAPP_SYNC_ACCNT_LIST_ACTION_DELETE:
			{
    	    	VcpConfirmPopup *confirm;
				VfxWString strAsk = VFX_WSTR_RES(STR_ID_VAPP_SYNC_DEL_ASK);
				
				strAsk += VFX_WSTR_RES(STR_ID_VAPP_SYNC_QUOTES_LEFT);
				strAsk += menu->getTitle();
				strAsk += VFX_WSTR_RES(STR_ID_VAPP_SYNC_QUOTES_RIGHT);
				strAsk += VFX_WSTR_RES(STR_ID_VAPP_SYNC_QUESTION);
				
				VFX_OBJ_CREATE(confirm, VcpConfirmPopup, findScreen());
				confirm->setInfoType(VCP_POPUP_TYPE_WARNING);
				confirm->setText(strAsk);
				confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
				confirm->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_DELETE), 
										 VFX_WSTR_RES(STR_GLOBAL_CANCEL),
										 VCP_POPUP_BUTTON_TYPE_WARNING,
										 VCP_POPUP_BUTTON_TYPE_CANCEL);
				confirm->m_signalButtonClicked.connect(this, &VappSyncAccntListMenu::onCmdCallback);
				confirm->setAutoDestory(VFX_TRUE);
				
				confirm->show(VFX_TRUE);
				break;
			}
			default:
				break;
    	}
    }   
}


void VappSyncAccntListMenu::onCmdCallback(VfxObject *obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		m_signalAction.postEmit(this, VAPP_SYNC_ACCNT_LIST_ACTION_DELETE, getAccntIndex(m_index));
	}
}

void VappSyncAccntListMenu::updateAllItems()
{
	m_nAccnt = getUpdatedCount();
	
	VappSyncAccntListMenu::sortIndexList(m_indexArray, m_nAccnt);
	
	VcpGroupListMenu::updateAllItems();
}

void VappSyncAccntListMenu::sortIndexList(IndexTimestampStruct *list, const VfxU32 &len)
{
	if (len <= 1) 
	{
		return;
	}

	// bubble sort
	for (VfxU32 i = 0; i < len; i++)
	{
		for (VfxU32 j = i + 1; j < len; j++)
		{
			if (list[j].timestamp > list[i].timestamp)
			{
				VfxS32 tempIndex = list[i].index;
				VfxS32 tempTimeStamp = list[i].timestamp;

				list[i].index = list[j].index;
				list[i].timestamp = list[j].timestamp;

				list[j].index = tempIndex;
				list[j].timestamp = tempTimeStamp;
			}
		}
	}
	
}

