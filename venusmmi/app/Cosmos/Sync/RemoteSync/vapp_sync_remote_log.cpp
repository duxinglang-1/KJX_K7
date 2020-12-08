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
 *  vapp_sync_remote_log.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  remote sync log
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "common_nvram_editor_data_item.h"
#include "nvram_common_defs.h"

extern "C"
{
#include "mmi_frm_nvram_gprot.h"
}
#include "mmi_rp_vapp_sync_def.h"
#include "SyncSrvGprot.h"

#include "vfx_string.h"
#include "vapp_sync_remote_log.h"

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
 * Class VappSyncRemoteLogPage
 *****************************************************************************/
void VappSyncRemoteLogPage::readLog(void)
{
	VFX_ASSERT(m_buffer != NULL);
	
	VfxS16 errCode;
	
	ReadRecord(NVRAM_EF_SYNCML_VIEW_LOG_LID, 
			   (m_index + 1), 
			   m_buffer, 
			   NVRAM_EF_SYNCML_VIEW_LOG_SIZE, 
			   &errCode);
}

VfxWString VappSyncRemoteLogPage::getAccntName(void) const
{
	nvram_ef_syncml_account_struct *accnt;
	VfxWString accntStr;
	
	accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, m_index);
	accntStr = VFX_WSTR_MEM((const VfxWChar *)accnt->account_name);

	return accntStr;
}

VfxWString VappSyncRemoteLogPage::getRemoteHeader(void) const
{
	return VFX_WSTR_RES(STR_ID_VAPP_SYNC_SERVER_ADDR);
}

VfxWString VappSyncRemoteLogPage::getRemoteName(void) const
{
	nvram_ef_syncml_view_log_struct *vlog = (nvram_ef_syncml_view_log_struct *)m_buffer;
	VfxWString srvAddr;
	srvAddr.format("%s", vlog->last_sync_server);

	return srvAddr;
}

void VappSyncRemoteLogPage::onReset(void)
{
	
	nvram_ef_syncml_view_log_struct *vlog = (nvram_ef_syncml_view_log_struct *)m_buffer;

	if (vlog != NULL)
	{
		VfxS16 errCode;

		vlog->last_sync_time = 0;
		WriteRecord(NVRAM_EF_SYNCML_VIEW_LOG_LID, 
					(m_index + 1), 
					vlog, 
					NVRAM_EF_SYNCML_VIEW_LOG_SIZE, 
					&errCode);
	}

	VappSyncLogPage::onReset();
}


