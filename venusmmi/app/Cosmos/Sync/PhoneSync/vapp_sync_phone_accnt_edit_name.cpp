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
 *  vapp_sync_phone_accnt_edit_name.cpp
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
extern "C"
{
#include "common_nvram_editor_data_item.h"
#include "BtcmSrvGprot.h"
#include "conversions.h"
#include "SyncSrvGprot.h"
}

#include "mmi_rp_vapp_sync_def.h"
#include "vapp_sync_ncenter.h"

#include "vfx_system.h"
#include "vcp_navi_title_bar.h"
#include "vcp_form.h"
#include "vapp_sync_phone_accnt_edit_name.h"

#include "vsrv_ndeclaration.h"
#include "vapp_ncenter.h"
#include "vcp_status_icon_bar.h"
#include "vapp_ncenter_system_cell.h"



/***************************************************************************** 
 * Define
 *****************************************************************************/

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
 * Class VappSyncPhoneAccntEditNamePage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappSyncPhoneAccntEditNamePage", 
								VappSyncPhoneAccntEditNamePage, 
								VappSyncAccntEditNamePage);
VappSyncPhoneAccntEditNamePage::VappSyncPhoneAccntEditNamePage(const VfxS32 &accntIndex)
	: VappSyncAccntEditNamePage(accntIndex)
{
}

void VappSyncPhoneAccntEditNamePage::onInit(void)
{
	VappSyncAccntEditNamePage::onInit();

	VcpTitleBar *titleBar = (VcpTitleBar *)getBar(VFX_PAGE_BAR_LOCATION_TOP);
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC_PHONE_NAME));

}

VfxBool VappSyncPhoneAccntEditNamePage::onSaveName(const VfxS32 &accntIndex, const VfxWString &string)
{
	nvram_ef_syncml_device_accnt_struct *accnt;
	accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, (VfxU8)accntIndex);
	VFX_ASSERT(accnt != NULL);

	U8 utf8_buffer[SRV_BT_CM_BD_FNAME_LEN];

	// change name in cm directly
    mmi_chset_ucs2_to_utf8_string((U8*)utf8_buffer, SRV_BT_CM_BD_FNAME_LEN, (U8*)string.getBuf());
	srv_bt_cm_set_dev_name((srv_bt_cm_bt_addr *)&accnt->dev_bt_addr, utf8_buffer);
	
	if(VFX_TRUE == VappSyncNCenterMngr::isNotiExist(NOTIFY_TYPE_UNFINISHED))	
	  {	
		 VfxWString subStr;
		 
		 void* accnt = srv_sync_read_accnt(SRV_SYNC_PHONE,accntIndex);
		nvram_ef_syncml_device_accnt_struct *phnAccnt = (nvram_ef_syncml_device_accnt_struct*)accnt;
		VfxWChar ucs2_buff[SRV_BT_CM_BD_UCS2_NAME_LEN];
	
		srv_bt_cm_get_dev_ucs2_name((srv_bt_cm_bt_addr *)&phnAccnt->dev_bt_addr, 
									SRV_BT_CM_BD_UCS2_NAME_LEN,
									(WCHAR *)ucs2_buff);
		subStr.loadFromMem((const VfxWChar *)ucs2_buff);				     
		VsrvNGroupSingleTitle *group = NULL;
		VsrvNotificationEvent *noti =NULL;
		VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_SYNC));
		group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC)); 
	    VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent,((VsrvNGroup*) group, ID_NOTI_UNFINISHED));
		noti->setSubText(subStr);								
	    noti->notify();							
	  }	
	return VFX_TRUE;
}

VfxWString VappSyncPhoneAccntEditNamePage::getName(const VfxS32 &accntIndex) const
{ 
	VfxWChar ucs2_buff[SRV_BT_CM_BD_UCS2_NAME_LEN];
	
	nvram_ef_syncml_device_accnt_struct *accnt;
	accnt = (nvram_ef_syncml_device_accnt_struct *)srv_sync_read_accnt(SRV_SYNC_PHONE, (VfxU8)accntIndex);
	VFX_ASSERT(accnt != NULL);
	
	ucs2_buff[0] = 0;
	ucs2_buff[1] = 0;
	
	srv_bt_cm_get_dev_ucs2_name((srv_bt_cm_bt_addr *)&accnt->dev_bt_addr, SRV_BT_CM_BD_UCS2_NAME_LEN, (WCHAR *)ucs2_buff);

	if (vfx_sys_wcslen((const VfxWChar *)ucs2_buff) == 0)
	{
		return VFX_WSTR_MEM((VfxWChar *)accnt->dev_name);
	}
	else
	{
	return VFX_WSTR_MEM(ucs2_buff); 
}

}

VfxWString VappSyncPhoneAccntEditNamePage::getLabel(const VfxS32 &accntIndex) const
{
	return VFX_WSTR_RES(STR_ID_VAPP_SYNC_PHONE_NAME); 
}

VfxU32 VappSyncPhoneAccntEditNamePage::getMaxLen(const VfxS32 &accntIndex) const
{
	return (SRV_BT_CM_BD_UCS2_NAME_LEN - 1); 
}

void VappSyncPhoneAccntEditNamePage::onSave(void)
{
	VcpFormItemTextInput *txtInput;
	txtInput = (VcpFormItemTextInput *)m_form->getItem(ID_VAPP_SYNC_EDIT_NAME);

	if (txtInput->getText().getLength() == 0)
	{
		txtInput->setWarningText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_INVALID_PHONE_NAME));
		return;
	}
	if (!onSaveName(m_accntIndex, txtInput->getText()))
	{
		txtInput->setWarningText(VFX_WSTR_RES(STR_ID_VAPP_SYNC_PHONE_NAME_EXIST));
		return;
	}

	m_signalEditDone.postEmit(this, m_accntIndex);
}

