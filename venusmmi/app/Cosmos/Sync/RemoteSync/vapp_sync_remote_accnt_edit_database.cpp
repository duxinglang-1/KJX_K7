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
 *  vapp_sync_accnt_edit_database.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "common_nvram_editor_data_item.h"
#include "custom_mmi_default_value.h"

extern "C"
{
#include "Unicodexdcl.h"
}
#include "SyncSrvGprot.h"

#include "vfx_string.h"
#include "vapp_sync_remote_accnt_edit_database.h"

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
 * Class VappSyncRemoteAccntEditDBPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappSyncRemoteAccntEditDBPage",
								VappSyncRemoteAccntEditDBPage, 
								VappSyncAccntEditDatabasePage);

VappSyncRemoteAccntEditDBPage::VappSyncRemoteAccntEditDBPage(const VfxS32 &accntIndex, const VfxU32 &dbMask)
	: VappSyncAccntEditDatabasePage(accntIndex, dbMask)
{
}

VfxWString VappSyncRemoteAccntEditDBPage::getAddress(const VfxS32 accntIndex, const VfxU32 &dbID)
{
	nvram_ef_syncml_account_struct *accnt;
	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, accntIndex);

	VfxWChar *buffer;
	VFX_ALLOC_MEM(buffer, (MAX_SYNCML_DATABASE_ADDR_LEN << 1), this);
	VfxU32 len = vfx_sys_strlen((const VfxChar *)accnt->database_address[dbID]);
	
	mmi_asc_n_to_wcs((WCHAR *)buffer, (CHAR *)accnt->database_address[dbID], len);

	VfxWString dbStr;
	dbStr.loadFromMem((const VfxWChar *)buffer);
	VFX_FREE_MEM(buffer);
	
	return dbStr;
}
	
VfxU32 VappSyncRemoteAccntEditDBPage::getMaxAddrLen(const VfxS32 accntIndex, const VfxU32 &dbID) const
{
	return (MAX_SYNCML_DATABASE_ADDR_LEN - 1); 
}

void VappSyncRemoteAccntEditDBPage::saveAddr(const VfxS32 accntIndex,
						 						const VfxU32 &dbID, 
						 						const VfxWChar *buffer, 
						 						const VfxU32 &length)
{
	nvram_ef_syncml_account_struct *accnt;

	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, accntIndex);

	mmi_wcs_n_to_asc((CHAR *)accnt->database_address[dbID], (WCHAR *)buffer, (length << 1));
	
	accnt->timestamp = srv_sync_get_current_time();
	
	// DB string should be asc
	srv_sync_write_accnt(SRV_SYNC_REMOTE, accnt, accntIndex);
}


