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
 *  vapp_sync_remote_cui.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  CUI for sync
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
#include "custom_mmi_default_value.h"
#include "mmi2syncml_struct.h"
#include "nvram_common_defs.h"
#include "GlobalResDef.h"

extern "C"
{
#include "ModeSwitchSrvGprot.h"
}
#include "SyncSrvGprot.h"

#include "mmi_rp_vapp_sync_def.h"
#include "mmi_rp_srv_sync_def.h"

#include "vfx_string.h"
#include "vfx_app_launcher.h"
#include "vfx_cui.h"

#include "vapp_sync.h"
#include "vapp_sync_gprot.h"
#include "vcui_sync_gprot.h"

#include "vcui_sync_remote.h"

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
U32 vcui_sync_can_display(U32 app_type)
{
	nvram_ef_syncml_account_struct *accnt;
	U32 ret = 0;
	
	accnt = (nvram_ef_syncml_account_struct *)OslMalloc(sizeof(nvram_ef_syncml_account_struct));

	for (VfxU32 i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		memset(accnt, 0, NVRAM_EF_SYNCML_ACCOUNT_SIZE);
		srv_sync_read_accnt_buffer(accnt, NVRAM_EF_SYNCML_ACCOUNT_SIZE, SRV_SYNC_REMOTE, i);

		if (accnt->app_to_sync & app_type)
		{
			ret = 1;
			break;
		}
	} 

	OslMfree(accnt);

	return ret;
}

mmi_id vcui_sync_create(mmi_id parent_id, void *usr_data)
{
	if (srv_sync_is_synchronizing())
	{
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(STR_ID_VAPP_SYNC_PLEASE_WAIT));
		return GRP_ID_INVALID;
	}

	if (vcui_sync_can_display(SYNCML_DB_PHONEBOOK) == 0)
	{	
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(STR_ID_VAPP_SYNC_NO_ACCNT));
		
		return GRP_ID_INVALID;

	}

	if (!VappSyncApp::isSyncAvailable(VFX_TRUE))
	{
		return GRP_ID_INVALID;
	}


    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_SYNC,
                                        VFX_OBJ_CLASS_INFO(VcuiSyncRemote),
                                        parent_id,
                                        usr_data,
                                        4);

    return cui_id;
}

void vcui_sync_set_database(mmi_id cui_id, U32 db_mask)
{
    VcuiSyncRemote *obj = VFX_OBJ_DYNAMIC_CAST(VfxApp::getObject(cui_id), VcuiSyncRemote);
    if(obj != NULL)
	{
    obj->setDB(db_mask);
}
}

void vcui_sync_run(mmi_id cui_id)
{
	VfxAppLauncher::runCui(cui_id);
}

void vcui_sync_close(mmi_id cui_id)
{
	VfxAppLauncher::terminate(cui_id);
}

/***************************************************************************** 
 * Class VcuiSyncRemote
 *****************************************************************************/ 
VFX_IMPLEMENT_CLASS("VcuiSyncRemote", VcuiSyncRemote, VfxCui);
void VcuiSyncRemote::onRun(void* args, VfxU32 argSize)
{
	VcuiSyncAccntListScr *scr;
	VFX_OBJ_CREATE_EX(scr, VcuiSyncAccntListScr, this, (m_database));
	if (scr != NULL)
	{
		scr->show();
	}
}

void VcuiSyncRemote::setDB(const VfxU32 db_mask)
{
	m_database = db_mask;
}


/***************************************************************************** 
 * Class VcuiSyncAccntListScr
 *****************************************************************************/
VfxU32 VcuiSyncAccntListScr::s_needUpdate = 0;

void VcuiSyncAccntListScr::onInit(void)
{
	VfxAppScr::onInit();

	VcpMenuPopup *menuPop;

	VFX_OBJ_CREATE(menuPop, VcpMenuPopup, this);
	menuPop->setAutoDestory(VFX_TRUE);
	menuPop->setTitle(VFX_WSTR_RES(STR_ID_VAPP_SYNC_REMOTE_ACCNTS));
	menuPop->m_signalMenuCallback.connect(this, &VcuiSyncAccntListScr::onMenuCallack); 

	m_menuPopupWeakPtr =  menuPop;

	refreshIndexArray();

	mmi_frm_cb_reg_event(EVT_ID_SRV_SYNC_ACCNT_OP, VcuiSyncAccntListScr::onSyncAccntEvt, getObjHandle());
}


void VcuiSyncAccntListScr::onDeinit(void)
{
	mmi_frm_cb_dereg_event(EVT_ID_SRV_SYNC_ACCNT_OP, VcuiSyncAccntListScr::onSyncAccntEvt, getObjHandle());
	
	if (m_menuPopupWeakPtr.isValid())
	{
		VcpMenuPopup *menuPop = m_menuPopupWeakPtr.get();

		VFX_OBJ_CLOSE(menuPop);
	}

	VfxAppScr::onDeinit();
}


void VcuiSyncAccntListScr::onEnter(VfxBool isBackward)
{
	VfxAppScr::onEnter(isBackward);
	
	if(0 == getAccntCount())
	{
		exit();
	}
	else
	{	
		if (m_menuPopupWeakPtr.isValid())
		{
			VcpMenuPopup *menuPop = m_menuPopupWeakPtr.get();

			
			if(1 == VcuiSyncAccntListScr::s_needUpdate || isBackward)
			{
				VcpMenuPopupItem* menuitem;
				VfxU32 i;
				for(i = 0; i < m_nAccnt; i++)
				{
					menuitem = menuPop->getItemById(m_indexArray[i].index);
					menuPop->removeItem(menuitem);
				}
			   
				refreshIndexArray();
				
				VcuiSyncAccntListScr::s_needUpdate = 0;						
			}
			
			nvram_ef_syncml_account_struct *accnt;
			VFX_ALLOC_MEM(accnt, sizeof(nvram_ef_syncml_account_struct), this);
			for (VfxU32 i = 0; i < m_nAccnt; i++)
			{
				srv_sync_read_accnt_buffer(accnt, NVRAM_EF_SYNCML_ACCOUNT_SIZE, SRV_SYNC_REMOTE, m_indexArray[i].index);
				
				menuPop->addItem(m_indexArray[i].index, VFX_WSTR_MEM((const VfxWChar *)accnt->account_name));
			}
			
			VFX_FREE_MEM(accnt);
			
			menuPop->showMenu();
	
		}
	}
}
void VcuiSyncAccntListScr::onMenuCallack(VcpMenuPopup* menu, VcpMenuPopupEventEnum evt, VcpMenuPopupItem *item)
{
    if (evt == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
    {
    	srv_sync_ret_enum ret = srv_sync_start(SRV_SYNC_REMOTE, (U8)item->getId(), m_dbMask, NULL);
		if (ret == SRV_SYNC_RET_OK)
		{
			vapp_sync_launch(0, NULL);
		}
    }

	exit();
}

VfxU32 VcuiSyncAccntListScr::refreshIndexArray(void)
{
	nvram_ef_syncml_account_struct *accnt;
	m_nAccnt = 0;

	VFX_ALLOC_MEM(accnt, sizeof(nvram_ef_syncml_account_struct), this);
	for (VfxU32 i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		if (srv_sync_read_accnt_buffer(accnt, NVRAM_EF_SYNCML_ACCOUNT_SIZE, SRV_SYNC_REMOTE, i) &&
			(accnt->timestamp != 0) &&
			(accnt->app_to_sync & m_dbMask))
		{
			m_indexArray[m_nAccnt].index = i;
			m_indexArray[m_nAccnt].timestamp = accnt->timestamp;
			m_nAccnt++;
		}
	}

	VappSyncAccntListMenu::sortIndexList(m_indexArray, m_nAccnt);

	VFX_FREE_MEM(accnt);

	return m_nAccnt;
}

VfxU32 VcuiSyncAccntListScr::getAccntCount(void)
{	
	nvram_ef_syncml_account_struct *accnt;
	VfxU32 count = 0;
	
	for (VfxU8 i = 0; i < MAX_SYNCML_SV_PROFILES; i++)
	{
		accnt = (nvram_ef_syncml_account_struct *)srv_sync_read_accnt(SRV_SYNC_REMOTE, i);
		if (accnt->timestamp != 0)
		{
			count++;
		}
	}

	return count;
}

mmi_ret VcuiSyncAccntListScr::onSyncAccntEvt(mmi_event_struct *evt)
{
	VcuiSyncAccntListScr *thiz = (VcuiSyncAccntListScr *)handleToObject((VfxObjHandle)evt->user_data);

	if (thiz != NULL)
	{
		s_needUpdate = 1;
	}
	
	return MMI_RET_OK;
}

