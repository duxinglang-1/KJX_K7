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
 *  vapp_sync_remote_accnt_edit_regular.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#include "common_nvram_editor_data_item.h"
#include "mmi_rp_vapp_sync_def.h"

#include "vfx_string.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_confirm_popup.h"

#include "vapp_sync_remote_accnt_edit_regular.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define RETURN_IF_FAIL(p) if (!(p)) { return; }
#define RETURN_VAL_IF_FAIL(p, val) if (!(p)) { return val; }

/***************************************************************************** 
 * define
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappSyncRemoteAccntEditRegularPage
 *****************************************************************************/
const VfxResId VappSyncRemoteAccntEditRegularPage::s_regularStrResList[SRV_SYNC_REGULAR_TOTAL] = 
{
	STR_ID_VAPP_SYNC_REGULAR_NEVER,
	STR_ID_VAPP_SYNC_REGULAR_PWRON,
	STR_ID_VAPP_SYNC_REGULAR_DATA_CHANGE,
	STR_ID_VAPP_SYNC_REGULAR_EVERY_DAY,
	STR_ID_VAPP_SYNC_REGULAR_EVERY_WEEK,
	STR_ID_VAPP_SYNC_REGULAR_EVERY_MONTH
};

VFX_IMPLEMENT_CLASS("VappSyncRemoteAccntEditRegularPage", VappSyncRemoteAccntEditRegularPage, VfxPage);

VappSyncRemoteAccntEditRegularPage::VappSyncRemoteAccntEditRegularPage(const VfxU8 &regular , const VfxU8 &accntIdx)
	: m_regular(regular),
	  m_index(accntIdx)
{
}

void VappSyncRemoteAccntEditRegularPage::onInit(void)
{
	VfxPage::onInit();

	VcpTitleBar *titleBar;
	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC_REGULAR_SYNC));
	setTopBar(titleBar);

	VcpListMenu *lstMenu;
	VFX_OBJ_CREATE(lstMenu, VcpListMenu, this);
	lstMenu->setSize(getSize());
	lstMenu->setContentProvider(this);
	lstMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
	lstMenu->setContentProvider(this);
	lstMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
	lstMenu->m_signalItemTapped.connect(this, &VappSyncRemoteAccntEditRegularPage::onListItemTap);
    lstMenu->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);

}

void VappSyncRemoteAccntEditRegularPage::onListItemTap(VcpListMenu *obj, VfxU32 index)
{

	if (index != SRV_SYNC_REGULAR_AT_DATA_CHANGE)
	{
		m_signalSelected.emit(this, index);
	}
	else
	{
		VfxS32 accntIdx = srv_sync_has_regular_sync(index);

		if (accntIdx < 0)
		{
			m_signalSelected.emit(this, index);	
		}
		else
		{
			if (m_index != accntIdx)
			{
				VfxWString strWarning, strName;
			
				nvram_ef_syncml_account_struct *accnt;
				
				VFX_ALLOC_MEM(accnt, NVRAM_EF_SYNCML_ACCOUNT_SIZE, this);
				srv_sync_read_accnt_buffer(accnt, NVRAM_EF_SYNCML_ACCOUNT_SIZE, SRV_SYNC_REMOTE, (U8)accntIdx);
				strName = VFX_WSTR_MEM((const VfxWChar *)accnt->account_name);
				VFX_FREE_MEM(accnt);
			
				strWarning = VFX_WSTR_RES(STR_ID_VAPP_SYNC_REGULAR_WARNING_LEFT);
				strWarning += strName;
				strWarning += VFX_WSTR_RES(STR_ID_VAPP_SYNC_REGULAR_WARNING_RIGHT);
				
				VcpConfirmPopup *popup;
				VFX_OBJ_CREATE(popup, VcpConfirmPopup, findScreen());
				popup->setInfoType(VCP_POPUP_TYPE_FAILURE);
				popup->setText(strWarning);
				popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
				popup->setAutoDestory(VFX_TRUE);
				popup->show(VFX_TRUE);

				obj->setItemState(m_regular, VCP_LIST_MENU_ITEM_STATE_SELECTED);
				obj->setItemState(index, VCP_LIST_MENU_ITEM_STATE_UNSELECTED);
			}
			else
			{
	m_signalSelected.emit(this, index);
}
		}
	}
}

VcpListMenuItemStateEnum VappSyncRemoteAccntEditRegularPage::getItemState(VfxU32 index) const
{
	
	if (m_regular != index)
	{
		return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}

	return VCP_LIST_MENU_ITEM_STATE_SELECTED;
}

VfxBool VappSyncRemoteAccntEditRegularPage::getItemText(
								VfxU32 index,					 // [IN] the index of item
								VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
								VfxWString &text,				 // [OUT] the text resource
								VcpListMenuTextColorEnum &color  // [OUT] the text color
								)
{
	if (fieldType != VCP_LIST_MENU_FIELD_TEXT)
	{
		return VFX_FALSE;
	}

	text.loadFromRes(VAPP_SYNC_GET_REGULAR_RES(index));
	color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;

	return VFX_TRUE;
}

