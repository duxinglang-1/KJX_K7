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
 *  vapp_theme.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Theme app
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
 * removed!
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
#include "CustVenusThemeRes.h"

#ifdef __MMI_THEMES_APPLICATION__
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "FileMgrSrvGprot.h"
#include "vapp_launcher_gprot.h"
extern "C"
{
#include "mmi_msg_struct.h"
#include "mmi_frm_scenario_gprot.h"
}

#include "mmi_rp_app_usbsrv_def.h"
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_vapp_theme_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#include "vfx_renderer.h"
#include "vfx_main_scr.h"
#include "vfx_app_launcher.h"
#include "vcp_navi_title_bar.h"
#include "vcp_confirm_popup.h"
#include "vcp_indicator_popup.h"
#include "vcp_list_menu.h" //VCP_LIST_MENU_FONT_SIZE_MEDIUM
#include "vapp_theme_gprot.h"

#ifdef __MMI_THEME_DLT_SUPPORT__
#include "vapp_theme_dlt.h"
#ifdef __LOW_COST_SUPPORT_COMMON__
#include "vapp_theme_evt_hdlr.h"
#endif
#endif

#include "vapp_theme.h"
#include "vapp_theme_list.h"
#include "Vapp_setting_launcher_scr_lock_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#ifndef max
#define max(_a, _b) (((_a) > (_b)) ? (_a) : (_b))
#endif
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" void mmi_fe_init_font_effect_theme(void);

extern "C" 
VfxU8 vapp_theme_at_handler(void *msg, VfxU32 mod_id)
{	
#ifndef __SLIM_AT__

    mmi_set_mmi_default_prof_ind_struct *mmi_set_prof_struct = (mmi_set_mmi_default_prof_ind_struct*) msg;

	if (mmi_set_prof_struct->category == 3)
	{
		VfxU8 index = mmi_set_prof_struct->param3 - 1;
		mmi_at_general_res_req_struct *rsp;

		rsp = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
		
		if (VFX_FALSE)//(index < mmi_res_get_theme_count())
		{
			VappThemeCntx *cntx = VFX_OBJ_GET_INSTANCE(VappThemeCntx);
			cntx->deactive();
			cntx->active((VfxU32)index);
			
			rsp->result = KAL_TRUE;
		}
		else
		{
			rsp->result = KAL_FALSE;
		}
		
		mmi_frm_send_ilm((oslModuleType)mod_id, MSG_ID_MMI_AT_GENERAL_RES_REQ, (oslParaType*)rsp, NULL);

		return 1;
	}
#endif /* __SLIM_AT__ */
	return 0;
}

extern "C" 
mmi_id vapp_theme_init(mmi_event_struct *evt)
{
	mmi_res_init_theme();

	VappThemeCntx *cntx = VFX_OBJ_GET_INSTANCE(VappThemeCntx);
	cntx->checkActive();

	mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SET_MMI_DEFAULT_PROF_IND, (PsIntFuncPtr)vapp_theme_at_handler, MMI_TRUE);

#if defined(__MMI_THEME_DLT_SUPPORT__) && defined(__LOW_COST_SUPPORT_COMMON__) 	
	vapp_theme_evt_init(evt);
#endif

	return MMI_RET_OK;
}

/***************************************************************************** 
 * VappThemeCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappThemeCell", VappThemeCell, VcpFormItemLauncherCell);
void VappThemeCell::onInit()
{
    VcpFormItemLauncherCell::onInit();

	setAccessory(VCPFORM_NEXT_ITEM_ICON);
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_THEME));
    m_signalTap.connect(this, &VappThemeCell::onTap);
}


void VappThemeCell::onTap(VcpFormItemCell *cell, VfxId id)
{
	VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

	if (mainScr != NULL)
	{
		mmi_id cuiId = VfxAppLauncher::createCui(
							VAPP_THEME,
							VFX_OBJ_CLASS_INFO(VappThemeApp),
							mainScr->getApp()->getGroupId());

		if (cuiId != GRP_ID_INVALID)
		{
			VfxAppLauncher::runCui(cuiId);
		}
	}
}

/***************************************************************************** 
 * Class VappThemeMemAllocator
 *****************************************************************************/
VappThemeMemAllocator::VappThemeMemAllocator(mmi_id grpId) 
	: m_buffer(NULL), 
	  m_heapId(NULL), 
	  m_counter(0),
	  m_groupId(grpId)
{
}

void VappThemeMemAllocator::createBuffer(void)
{
	if (m_buffer == NULL)
	{
		m_buffer = applib_asm_alloc_nc_r(m_groupId, VAPP_THEME_TOTAL_CELL_MEM);
		VFX_ASSERT(m_buffer != NULL);
		m_heapId = kal_adm_create(m_buffer, VAPP_THEME_TOTAL_CELL_MEM, NULL, KAL_TRUE);

		m_signalMemReady.emit();
		m_counter = 0;
	}
}


void VappThemeMemAllocator::freeBuffer(void)
{
	if (m_buffer != NULL)
	{
		kal_adm_delete(m_heapId);
		applib_asm_free_r(m_groupId, m_buffer);

		m_heapId = NULL;
		m_buffer = NULL;
	}
}

VfxBool VappThemeMemAllocator::isMemValid(void)
{
	if (m_buffer == NULL || m_heapId == NULL)
	{
		return VFX_FALSE;
	}

	return VFX_TRUE;
}


VfxU8 *VappThemeMemAllocator::allocMem(VfxS32 size)
{
	if (!isMemValid())
	{
		return NULL;
	}
	
	void *mem = kal_adm_alloc_noncacheable(m_heapId, size, NULL);
	if (mem != NULL);
	{
		m_counter++;
	}
	
	return (VfxU8 *)mem;
}


void VappThemeMemAllocator::freeMem(void *mem)
{
	if (!isMemValid() || (mem == NULL))
	{
		return ;
	}
	
	m_counter--;
	kal_adm_free(m_heapId, mem);
}


/***************************************************************************** 
 * Class VappThemeApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappThemeApp", VappThemeApp, VfxCui);
void VappThemeApp::onInit(void)
{
	VfxApp::onInit();

	VFX_OBJ_CREATE_EX(m_allocator, VappThemeMemAllocator, this, (getGroupId()));
}

void VappThemeApp::onDeinit(void)
{
	m_allocator->freeBuffer();
	
	VfxApp::onDeinit();
}

void VappThemeApp::onRun(void * args,VfxU32 argSize)
{
	VfxMainScrEx *scr;
	VFX_OBJ_CREATE_EX(scr, VfxMainScrEx, this, (this));
	scr->show();
}

void VappThemeApp::onScr1stReady(VfxMainScrEx *scr)
{
	VappThemeListPage *page;
	
	VFX_OBJ_CREATE_EX(page, VappThemeListPage, scr, (m_allocator));
	scr->pushPage('GRID', page);
}

void VappThemeApp::onGroupTopActive(void)
{
	m_allocator->setGroupId(getGroupId());
	m_allocator->createBuffer();
	
}

void VappThemeApp::onGroupTopInactive(void)
{
	m_allocator->m_signalBeforeMemFree.emit();
	m_allocator->freeBuffer();
}

mmi_id VappThemeApp::getAppGroupId(void)
{
	return getGroupId();
}

/***************************************************************************** 
 * VappThemeCntx
 *****************************************************************************/
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappThemeCntx);
VappThemeCntx::VappThemeCntx()
{
}

VfxS16 VappThemeCntx::active(VfxU32 index)
{	
	deactive();
	
	setActiveIndex(index);
	
	return (mmi_res_set_system_theme(index) ? 0 : -1);
}

VfxS16 VappThemeCntx::deactive(void)
{
	mmi_res_close_curr_theme();
	
	return 0;
}

VfxBool VappThemeCntx::isDltActive(void)
{
	return (getActiveIndex() == DLT_THEME_TAG);
}

void VappThemeCntx::setIsDltActive(VfxBool isDlt, VfxU32 index)
{
	VfxU32 activeIndex = isDlt ? DLT_THEME_TAG : index;
	
	setActiveIndex(activeIndex);
}

VfxU32 VappThemeCntx::getActiveIndex(void)
{
	VfxU8 activeIndex;
	VfxS16 errCode;
	ReadValue(NVRAM_THEME_ACTIVE_INDEX, &activeIndex, DS_BYTE, &errCode);

	return (VfxU32)activeIndex;
}

VfxBool VappThemeCntx::setActiveIndex(VfxU32 index)
{
	VfxU8 activeIndex = (VfxU8)index;
	VfxS16 errCode;
	
	WriteValue(NVRAM_THEME_ACTIVE_INDEX, &activeIndex, DS_BYTE, &errCode);

	return VFX_TRUE;
}

VfxBool VappThemeCntx::checkActive(void)
{
	VfxBool ret = VFX_FALSE;
	
#ifdef __MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__
	if (isDltActive())
	{
		if (VappThemeDltData::initTheme(VFX_OBJ_GET_INSTANCE(VappThemeDltCntx)))
		{
			ret = VFX_TRUE;
		}
	}
	else
#endif /* __MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__ */
	{
		if(active(getActiveIndex()) >= 0)
		{
			ret = VFX_TRUE;
		}
	}

	// restore to default theme
	if(!ret)
	{
		active((VfxU32)0);
	}

	return VFX_TRUE;
}


/***************************************************************************** 
 * Class VappThemeData
 *****************************************************************************/
void VappThemeData::genSwitchDesc(VappThemeSwitchDesc &desc, VfxS32 pos)
{
	desc.initRes();
}

/***************************************************************************** 
 * Class VappThemeSwitchDesc
 *****************************************************************************/
VappThemeSwitchDesc::VappThemeSwitchDesc() :
    m_switchingId(0),
	m_invalidId(0),
	m_changedId(0),
	m_compatibleAskId(0),
    m_switchAskId(0),
	isNeedConfirm(VFX_TRUE),
	isRestore(VFX_FALSE)
{
	u.index = 0;
}

void VappThemeSwitchDesc::initRes(void)
{
	m_changedId = STR_ID_VAPP_THEME_CHANGED;
	m_compatibleAskId = STR_ID_VAPP_THEME_COMPATIBLE_ASK;
	m_invalidId = STR_ID_VAPP_THEME_INVALID;
	m_switchingId = STR_ID_VAPP_THEME_SWITCH;
	m_switchAskId = STR_ID_VAPP_THEME_CHNAGE_ASK;

	isNeedConfirm = VFX_TRUE;
	isRestore = VFX_FALSE;

	u.path = NULL;
}

VappThemeSwitchDesc &VappThemeSwitchDesc::operator =(const VappThemeSwitchDesc &other)
{
	// avoid self assignee.
	if (this == &other)
	{
		return *this;
	}
	
	type = other.type;
	u = other.u;
	
	m_changedId = other.m_changedId;
	m_compatibleAskId = other.m_compatibleAskId;
	m_invalidId = other.m_invalidId;
	m_switchingId = other.m_switchingId;
	m_switchAskId = other.m_switchAskId;
	isNeedConfirm = other.isNeedConfirm;
	isRestore = other.isRestore;
	
	return *this;
}

/***************************************************************************** 
 * Class VappThemeSysData
 *****************************************************************************/
VfxBool VappThemeSysData::getTypeStr(VfxWString &typeName)
{ 
	typeName.loadFromRes(STR_ID_VAPP_THEME_SYS);

	return VFX_TRUE;
}

VfxU32 VappThemeSysData::getCount(void) const
{
	return (VfxU32)mmi_res_get_theme_count();
}

VfxImageSrc VappThemeSysData::getPreviewImg(VfxS32 pos, VfxU8 *buffer, VfxU32 size)
{
	VfxImageSrc imgSrc;
	const VfxU8 *img = (const VfxU8 *)mmi_res_get_sys_theme_preview(pos);

	if (img != NULL)
	{
		imgSrc.setMem(img);
	}
	else
	{
		imgSrc.setResId(IMG_ID_VAPP_THEME_INVALID);
	}
	

	return imgSrc;
}

VfxImageSrc VappThemeSysData::getThumbnail(VfxS32 pos, VfxU8 *buffer, VfxU32 size)
{
	VfxImageSrc imgSrc;
	VfxU8 *img = (VfxU8 *)mmi_res_get_sys_theme_thumbnail(pos);

	if (img != NULL)
	{
		imgSrc.setMem(img);
	}
	else
	{
		imgSrc.setResId(IMG_ID_VAPP_THEME_INVALID);
	}
	
	return imgSrc;
}

VfxWString VappThemeSysData::getText(VfxS32 pos)
{
	return VFX_WSTR_RES(STR_ID_VAPP_THEME1 + pos);
}

VfxBool VappThemeSysData::isActivated(VfxS32 pos)
{
	VappThemeCntx *cntx = VFX_OBJ_GET_INSTANCE(VappThemeCntx);
	return (cntx->getActiveIndex()== pos);
}

void VappThemeSysData::genSwitchDesc(VappThemeSwitchDesc &desc, VfxS32 pos)
{
	VappThemeData::genSwitchDesc(desc, pos);
	
	desc.type = VappThemeData::THEME_TYPE_SYS;
	desc.u.index = pos;
}

VfxClassInfo *VappThemeSysData::getCuiClassInfo(void)
{
	return VFX_OBJ_CLASS_INFO(VappThemeSwitchCui);
}


/***************************************************************************** 
 * VappThemeSwitchCui
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappThemeSwitchCui", VappThemeSwitchCui, VfxCui);

void VappThemeSwitchCui::onRun(void* args, VfxU32 argSize)
{
    VFX_OBJ_CREATE(m_mainScr, VappThemeSwitchMainScr, this);
    m_mainScr->show();

	//VappThemeSwitchDesc *desc = (VappThemeSwitchDesc *)args;
	m_switchDesc = *(VappThemeSwitchDesc *)args;

	if (m_switchDesc.isNeedConfirm)
	{
		VcpConfirmPopup *popup;
		
		VFX_OBJ_CREATE(popup, VcpConfirmPopup, m_mainScr);
		popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
		popup->setInfoType(VCP_POPUP_TYPE_QUESTION);
		popup->setText(VFX_WSTR_RES(STR_ID_VAPP_THEME_CHNAGE_ASK));
		popup->setCustomButton(
			VFX_WSTR_RES(STR_GLOBAL_CONTINUE), 
			VFX_WSTR_RES(STR_GLOBAL_CANCEL), 
			VCP_POPUP_BUTTON_TYPE_WARNING,
			VCP_POPUP_BUTTON_TYPE_CANCEL);
		
		popup->m_signalButtonClicked.connect(this, &VappThemeSwitchCui::onConfirm);
		popup->show(VFX_FALSE);
	}
	else
	{
		onConfirm(NULL, VCP_CONFIRM_POPUP_BUTTON_USER_1);
	}
}

VfxBool VappThemeSwitchCui::active(void)
{
	VappThemeCntx *cntx = VFX_OBJ_GET_INSTANCE(VappThemeCntx);

	cntx->deactive(); // deactive the current theme	
	cntx->active((VfxU32)m_switchDesc.u.index);

	return VFX_TRUE;
}

void VappThemeSwitchCui::onConfirm(VfxObject *obj, VfxId id)
{
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		if (obj != NULL)
		{
        	VFX_OBJ_CLOSE(obj);
		}

		// The rule from theme framework: 
		//	<0   invalid
		//	==0 OK
		//	>0	uncompatible, but can be active
		VfxS32 ret = checkValid();
		if (ret == 0)
		{
			showProgress();
		}
		else if (ret < 0)
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_GENERAL,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				(WCHAR *)GetString(m_switchDesc.m_invalidId));
			
			exit();
		}
		else
		{	
			if (m_switchDesc.isNeedConfirm)
			{
				VcpConfirmPopup *confirm;
				VFX_OBJ_CREATE(confirm, VcpConfirmPopup, m_mainScr);
				confirm->setInfoType(VCP_POPUP_TYPE_INFO);

				confirm->setText(VFX_WSTR_RES(m_switchDesc.m_compatibleAskId));
				confirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
				confirm->setCustomButton(VFX_WSTR_RES(STR_GLOBAL_CONTINUE), 
								 VFX_WSTR_RES(STR_GLOBAL_CANCEL),
								 VCP_POPUP_BUTTON_TYPE_NORMAL,
								 VCP_POPUP_BUTTON_TYPE_CANCEL);
				confirm->m_signalButtonClicked.connect(this, &VappThemeSwitchCui::onCompatibleCallback);
				confirm->setAutoDestory(VFX_TRUE);

				confirm->show(VFX_TRUE);
			}
			else
			{
				onCompatibleCallback(NULL, VCP_CONFIRM_POPUP_BUTTON_USER_1);
			}

		}

	}
	else
	{
		exit();
	}
}

void VappThemeSwitchCui::onCompatibleCallback(VfxObject *obj, VfxId id)
{	
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		if (obj != NULL)
		{
        	VFX_OBJ_CLOSE(obj);
		}
		
		showProgress();
	}
	else
	{
		exit();
	}
}

void VappThemeSwitchCui::showProgress(void)
{
	if (m_switchDesc.isNeedConfirm)
	{
		VcpIndicatorPopup *pop;
		
		VFX_OBJ_CREATE(pop, VcpIndicatorPopup, m_mainScr);
		
		pop->setInfoType(VCP_INDICATOR_POPUP_STYLE_TEXT);
		pop->setText(VFX_WSTR_RES(m_switchDesc.m_switchingId));
		pop->setAutoDestory(VFX_TRUE);
		pop->setIsAnimate(VFX_FALSE);
		pop->m_signalPopupState.connect(this, &VappThemeSwitchCui::onPopState);
		pop->show(VFX_FALSE);
	}
	else
	{
		onPopState(NULL, VFX_BASE_POPUP_AFTER_START_ANIMATION);
	}
}

void VappThemeSwitchCui::onPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state)
{
    if(state == VFX_BASE_POPUP_AFTER_START_ANIMATION)
    {
    	VfxResId strId;
		
		if (!active())
		{
			strId = STR_GLOBAL_FAILED;
		}
		else
		{
			strId = m_switchDesc.m_changedId;
		}
		
		VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
		
#if defined(__MMI_FONT_EFFECTS__)
		mmi_fe_init_font_effect_theme();
#endif /* __MMI_FONT_EFFECTS__ */

		mmi_event_struct evt;
		MMI_FRM_INIT_EVENT(&evt, EVT_ID_VAPP_THEME_CHANGED);
		MMI_FRM_CB_EMIT_POST_EVENT(&evt);

		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_GENERAL,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)GetString(strId));

		vapp_launcher_restart();
    }
}


#else
extern "C" 
mmi_id vapp_theme_init(mmi_event_struct *evt)
{
	mmi_res_init_theme();
	return MMI_RET_OK;
}
#endif /*__MMI_THEMES_APPLICATION__*/


