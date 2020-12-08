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
 *  vapp_sync_accnt_edit_name.cpp
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
#include "common_nvram_editor_data_item.h"

#include "mmi_rp_vapp_sync_def.h"
#include "SyncSrvGprot.h"

#include "vapp_sync.h"
#include "vapp_sync_accnt_list.h"
#include "vapp_sync_remote_accnt_list.h"
#include "vapp_sync_remote_accnt_edit_name.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define ID_TOOLBAR_SYNC_ACCNT_SAVE		'SAVE'
#define ID_TOOLBAR_SYNC_ACCNT_CANCEL	'CANL'


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/***************************************************************************** 
 * Class VappSyncRemoteAccntEditNamePage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappSyncRemoteAccntEditNamePage", 
								VappSyncRemoteAccntEditNamePage, 
								VappSyncAccntEditNamePage);
VappSyncRemoteAccntEditNamePage::VappSyncRemoteAccntEditNamePage(const VfxS32 &accntIndex)
	: VappSyncAccntEditNamePage(accntIndex)
{
}

VfxBool VappSyncRemoteAccntEditNamePage::onSaveName(const VfxS32 &accntIndex, const VfxWString &string)
{
	VfxPage *page = getMainScr()->getPage(VAPP_SYNC_PAGE_ID(LIST));

	VappSyncAccntListPage *listPage;
	listPage = VFX_OBJ_DYNAMIC_CAST(page, VappSyncAccntListPage);

	if (listPage != NULL)
{
		VfxPage *tabPage = listPage->getTabPage(listPage->getCurrTab());
		VappSyncRemoteAccntListPage *rmtListPage;
		rmtListPage = VFX_OBJ_DYNAMIC_CAST(tabPage, VappSyncRemoteAccntListPage);
		if (rmtListPage != NULL &&
			rmtListPage->checkExistAccntName(accntIndex, string.getBuf()))
		{
			return VFX_FALSE;
		}
	}
	
	nvram_ef_syncml_account_struct *accnt;
	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, (VfxU8)accntIndex);
	VFX_ASSERT(accnt != NULL);

	mmi_ucs2ncpy((CHAR *)accnt->account_name, (const CHAR *)string.getBuf(), string.getLength());
	
	accnt->account_name[string.getLength() * 2] = 0;
	accnt->account_name[string.getLength() * 2 + 1] = 0;

	srv_sync_write_accnt(SRV_SYNC_REMOTE, accnt, accntIndex);

	return VFX_TRUE;
}

VfxWString VappSyncRemoteAccntEditNamePage::getName(const VfxS32 &accntIndex) const
{ 
	
	nvram_ef_syncml_account_struct *accnt;
	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, (VfxU8)accntIndex);
	VFX_ASSERT(accnt != NULL);

	VfxWString string = VFX_WSTR_MEM((const VfxWChar *)accnt->account_name);
	
	return string; 
}

VfxWString VappSyncRemoteAccntEditNamePage::getLabel(const VfxS32 &accntIndex) const
{
	return VFX_WSTR_RES(STR_ID_VAPP_SYNC_ACCNT_NAME); 
}

VfxU32 VappSyncRemoteAccntEditNamePage::getMaxLen(const VfxS32 &accntIndex) const
{
	return MAX_SYNCML_PROFILE_NAME - 1; 
}


