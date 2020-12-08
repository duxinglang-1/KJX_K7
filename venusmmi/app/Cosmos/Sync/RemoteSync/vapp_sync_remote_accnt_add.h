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
 *  vapp_sync_remote_accnt_add.h
 *
 * Project:
 * --------
 *  Add remote sync account  class
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SYNC_REMOTE_ACCNT_ADD_H__
#define __VAPP_SYNC_REMOTE_ACCNT_ADD_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"

#include "vapp_sync_accnt_edit_select_database.h"
#include "vapp_sync_remote_accnt_edit_database.h"
#include "vapp_sync_remote_accnt_edit_server.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SYNC_RMT_ACCNT_ADD_PAGE_ID_SERVER 1
#define VAPP_SYNC_RMT_ACCNT_ADD_PAGE_ID_SELDB  2
#define VAPP_SYNC_RMT_ACCNT_ADD_PAGE_ID_DBADDR 3

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class VappSyncRemoteAccntAddSrvPage
 *****************************************************************************/
class VappSyncRemoteAccntAddSrvPage : public VappSyncRemoteAccntEditServerPage
{
	VFX_DECLARE_CLASS(VappSyncRemoteAccntAddSrvPage);

public:
	VappSyncRemoteAccntAddSrvPage(const VfxS32 &index = 0);
	virtual ~VappSyncRemoteAccntAddSrvPage(){}

	
protected:
	void onInit(void);
	void onDeinit(void);
	void onSave(void){ onNext(); }
	void onNext(void);
	void onCancel(void);
	void onFocusChange(VfxObject *obj, VfxId id, VfxBool isActive);
	void onFuncBarClick(VfxObject *sender, VfxId id);

private:
	void *m_accntData;
};


/***************************************************************************** 
 * Class VappSyncRemoteAccntAddSelDBPage
 *****************************************************************************/
class VappSyncRemoteAccntAddSelDBPage : public VappSyncAccntSelectDatabasePage
{
	VFX_DECLARE_CLASS(VappSyncRemoteAccntAddSelDBPage);

public:
	VappSyncRemoteAccntAddSelDBPage(void *accntData = NULL);
	virtual ~VappSyncRemoteAccntAddSelDBPage(){}

	
protected:
	void onInit(void);
	void onCancel(void);
	
private:
	void onSelectDone(VfxObject *obj, VfxU32 mask);

private:
	void *m_accntData;
};


/***************************************************************************** 
 * Class VappSyncRemoteAccntAddDBPage
 *****************************************************************************/
class VappSyncRemoteAccntAddDBPage : public VappSyncRemoteAccntEditDBPage
{
	VFX_DECLARE_CLASS(VappSyncRemoteAccntAddDBPage);

public:
	VappSyncRemoteAccntAddDBPage(const VfxU32 &dbMask = 0, void *accntData = NULL);
	virtual ~VappSyncRemoteAccntAddDBPage(){}
	
protected:
	void onInit(void);
	VfxBool onSave(void);
	void onFinish(void);
	void onCancel(void);
	VfxWString getAddress(const VfxS32 accntIndex, const VfxU32 &dbID);
	void saveAddr(const VfxS32 accntIndex,
				const VfxU32 &dbID, 
				const VfxWChar *buffer, 
				const VfxU32 &length);

private:
	void *m_accntData;
};


#endif /* __VAPP_SYNC_REMOTE_ACCNT_ADD_H__ */

