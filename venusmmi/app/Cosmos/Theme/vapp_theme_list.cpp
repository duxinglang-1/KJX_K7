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
 *  Theme AP
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#ifdef __MMI_THEMES_APPLICATION__
#include "MMIDataType.h"
#include "CustVenusThemeRes.h"
#include "GlobalResDef.h"


extern "C"
{
#include "FileMgrSrvGProt.h"
#include "mmi_msg_struct.h"
#include "mmi_frm_scenario_gprot.h"
}


#include "mmi_rp_app_usbsrv_def.h"
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_vapp_theme_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

#include "vcp_navi_title_bar.h"
#include "vapp_theme_gprot.h"


#ifdef __MMI_THEME_DLT_SUPPORT__
#include "vapp_theme_dlt.h"
#endif

#include "vapp_theme.h"
#include "vapp_theme_list.h"

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
 * Class VappThemePreviewPage
 *****************************************************************************/
VappThemePreviewPage::VappThemePreviewPage(IVappDLUISettingProvider* provider, const VcpMenuPos& pos, VappThemeMemAllocator *fgAllocator) 
	: VappSettingVarUIPreviewPage(provider, pos),
	  m_isReleased(VFX_FALSE),
	  m_fgAllocator(fgAllocator)
{
}

void VappThemePreviewPage::onInit(void)
{
	VappSettingVarUIPreviewPage::onInit();

	m_fgAllocator->m_signalMemReady.connect(this, &VappThemePreviewPage::onMemReady);
	m_fgAllocator->m_signalBeforeMemFree.connect(this, &VappThemePreviewPage::onInactive);

	m_isReleased = VFX_FALSE;
}

void VappThemePreviewPage::onEntered(void)
{
	VappSettingVarUIPreviewPage::onEntered();

	if (m_isReleased)
	{
		m_baseMenu->updateCachedImage();
		m_isReleased = VFX_FALSE;
	}
	
	m_baseMenu->forceCache();
}

void VappThemePreviewPage::onInactive(void)
{
	m_baseMenu->releaseCachedImage();
	m_isReleased = VFX_TRUE;
}

void VappThemePreviewPage::onMemReady(void)
{
	m_isReleased = VFX_TRUE;
}

/***************************************************************************** 
 * Class VappThemeListPage
 *****************************************************************************/
VappThemeListPage::VappThemeListPage(VappThemeMemAllocator *fgAllocator) : 
	m_selectPos(-1, -1),
	m_matrix(NULL),
	m_isReleased(VFX_FALSE),
	m_isRefreshing(VFX_TRUE),
	m_isShowDltGroup(VFX_TRUE),
	m_fgAllocator(fgAllocator)
{
	for (VfxS32 i = VappThemeData::THEME_TYPE_TOTAL; i != 0; i--)
	{
		m_themeData[i - 1] = NULL;
	}	
}

void VappThemeListPage::onInit(void)
{
	VfxPage::onInit();

	VcpTitleBar *titleBar;

	VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
	titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_THEME));
	setTopBar(titleBar);

	onInitData();
	createMenu();

#ifdef __MMI_THEME_DLT_SUPPORT__
	mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappThemeListPage::onDevEvt, getObjHandle());
	mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, VappThemeListPage::onDevEvt, getObjHandle());
#endif

	m_fgAllocator->m_signalBeforeMemFree.connect(this, &VappThemeListPage::onInactive);

}

void VappThemeListPage::createMenu(void)
{
	if (m_matrix == NULL)
	{
		VFX_OBJ_CREATE(m_matrix, VappThemeMatrixMenu, this);
		m_matrix->setSize(getSize().width, getSize().height);
		m_matrix->setAlignParent(
	                VFX_FRAME_ALIGNER_MODE_SIDE,
	                VFX_FRAME_ALIGNER_MODE_SIDE,
	                VFX_FRAME_ALIGNER_MODE_SIDE,
	                VFX_FRAME_ALIGNER_MODE_SIDE);
		m_matrix->setItemHeight(VappThemeViewCell::HEIGHT);
		m_matrix->setContentProvider(this);
		m_matrix->setCacheLen(1);
		m_matrix->m_signalTap.connect(this, &VappThemeListPage::onItemTap);
	}
}

void VappThemeListPage::updateFgChild(void)
{
#if 1//def __MMI_THEME_SUPPORT_ASYNC_IMAGE__
	createMenu();
#else
/* under construction !*/
#endif
}

void VappThemeListPage::releaseFgChild(void)
{
#if 1//def __MMI_THEME_SUPPORT_ASYNC_IMAGE__
	VFX_OBJ_CLOSE(m_matrix);
#else
/* under construction !*/
#endif

	m_isReleased = VFX_TRUE;
}

void VappThemeListPage::onInitData(void)
{
	VappThemeSysData *sysData;
	VFX_OBJ_CREATE(sysData, VappThemeSysData, this);
	m_themeData[VappThemeData::THEME_TYPE_SYS] = sysData;

#ifdef __MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__
	VappThemeDltData *dltData;
	VFX_OBJ_CREATE(dltData, VappThemeDltData, this);
	m_themeData[VappThemeData::THEME_TYPE_DLT] = dltData;
	dltData->m_signalNeedReset.connect(this, &VappThemeListPage::onNeedReset);
#endif

	VappThemeCntx *cntx = VFX_OBJ_GET_INSTANCE(VappThemeCntx);
	if (!cntx->isDltActive())
	{
		m_selectPos.group = VappThemeData::THEME_TYPE_SYS;
		m_selectPos.pos   = (VfxS32)cntx->getActiveIndex();	
	}
}

void VappThemeListPage::onDeinit(void)
{
#ifdef __MMI_THEME_DLT_SUPPORT__
	mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, VappThemeListPage::onDevEvt, getObjHandle());
	mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VappThemeListPage::onDevEvt, getObjHandle());
#endif

	VfxPage::onDeinit();
}

void VappThemeListPage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);

	if (isBackward)
	{
		m_isShowDltGroup = VFX_FALSE;
		createMenu();
		
		m_matrix->setCacheLen(1);
		m_matrix->updateLayout();
	}
}

void VappThemeListPage::onEntered(void)
{
	VfxPage::onEntered();

	m_isShowDltGroup = VFX_TRUE;
	if (m_isReleased)
	{
		updateFgChild();

		m_isReleased = VFX_FALSE;
	}
	
	m_matrix->forceCache();
	relayout();
}

void VappThemeListPage::onExited2(void)
{
	// To save memory, don't let preview page and matrix page cocurrency
	releaseFgChild();
	
	if (m_matrix != NULL)
	{
		m_matrix->clearFocusItem();
	}

	VfxPage::onExited2();
}

mmi_ret VappThemeListPage::onDevEvt(mmi_event_struct *evt)
{
	VappThemeListPage *thiz = (VappThemeListPage *)handleToObject((VfxObjHandle)evt->user_data);

	if (thiz != NULL)
	{
		thiz->onProc(evt);
	}

	return MMI_RET_OK;
}

void VappThemeListPage::onInactive(void)
{
	releaseFgChild();
}

mmi_ret VappThemeListPage::onProc(mmi_event_struct * evt)
{
	if (evt->evt_id == EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT ||
		evt->evt_id == EVT_ID_USB_ENTER_MS_MODE)
	{
		if (m_selectPos.group != VappThemeData::THEME_TYPE_SYS)		
		{
			getMainScr()->closePage('PREV');
		}
	}

	return MMI_RET_OK;
}


VfxBool VappThemeListPage::getMenuEmptyText(VfxWString &text)
{
	if (m_isRefreshing)
	{
		text.loadFromRes(STR_ID_VAPP_THEME_LOADING_DLT);
	}
	else
	{
		text.loadFromRes(STR_ID_VAPP_THEME_NO_DLT);
	}	
	
	return VFX_TRUE;
}
		
VfxBool VappThemeListPage::getItemText(VcpMenuPos pos, VfxWString &text)
{
	if (pos.pos == -1)
	{
		m_themeData[pos.group]->getTypeStr(text);
	}
	else
	{
			text = m_themeData[pos.group]->getText(pos.pos);
	}

	return VFX_TRUE;
}	
			
VfxBool VappThemeListPage::getItemImage(VcpMenuPos pos, VfxImageSrc &src)
{
	if (pos.pos >= 0)
	{
		VfxU8 *mem = NULL;

		if (isDltGroup(pos.group))
		{
			mem = m_fgAllocator->allocMem(VAPP_THEME_CELL_CACHE_BUFFER_SIZE);
		}
		// System theme don't need buffer.
		src = m_themeData[pos.group]->getThumbnail(pos.pos, mem, VAPP_THEME_CELL_CACHE_BUFFER_SIZE);
		if (src.getType() != VFX_IMAGE_SRC_TYPE_MEM)
		{
			m_fgAllocator->freeMem(mem);
		}
		
		return VFX_TRUE;
	}

	return VFX_FALSE;
}	

VfxBool VappThemeListPage::freeItemImage(VcpMenuPos pos, VfxImageSrc &src)
{

	if (isDltGroup(pos.group) && src.getType() == VFX_IMAGE_SRC_TYPE_MEM)
	{
		m_fgAllocator->freeMem((void *)src.getMem());
	}
	
	return VFX_TRUE;
}

void *VappThemeListPage::allocNcMem(VfxU32 size, void *userData)
{
	return (void *)m_fgAllocator->allocMem(size);
}

void VappThemeListPage::freeNcMem(void *mem, void *userData)
{
	m_fgAllocator->freeMem(mem);
}

// Therd is a problem, with VfxImageSrc.
VfxFrame* VappThemeListPage::getDLUIScreenShot(VfxS32 group, VfxS32 pos)
{
    VfxFrame* imgFrame = NULL;

	if (pos >= 0)
	{
		VfxU8 *mem = NULL;

		if (isDltGroup(group))
		{
			mem = m_fgAllocator->allocMem(VAPP_THEME_PREVIEW_CACHE_BUFFER_SIZE);
		}
		// System theme don't need buffer.
		VfxImageSrc image = m_themeData[group]->getPreviewImg(pos, mem, VAPP_THEME_PREVIEW_CACHE_BUFFER_SIZE);
		if (image.getType() != VFX_IMAGE_SRC_TYPE_MEM)
		{
			m_fgAllocator->freeMem(mem);
		}
		
        
        VFX_OBJ_CREATE(imgFrame, VfxFrame, this);
        imgFrame->setImgContent(image);
        imgFrame->setSize(image.getSize());
        
	}

	return imgFrame;
}

VfxBool VappThemeListPage::freeDLUIScreenShot(VfxS32 group, VfxS32 pos, VfxFrame* previewImg)
{
    if (previewImg)
	{
    //previewImg->removeFromParentFrame();
        VfxImageSrc imgSrc(previewImg->getImgContent());
        if (isDltGroup(group) && imgSrc.getType() == VFX_IMAGE_SRC_TYPE_MEM)
	{
            m_fgAllocator->freeMem((void *)imgSrc.getMem());
        }
        VFX_OBJ_CLOSE(previewImg);
	}
	
	return VFX_TRUE;
}

VappThemeMenuItemStateEnum VappThemeListPage::getItemState(VcpMenuPos pos) const
{
	if (m_themeData[pos.group]->isActivated(pos.pos))
	{
		return VAPP_THEMEE_MENU_ITEM_STATE_SELECTED;
	}
	
	return VAPP_THEMEE_MENU_ITEM_STATE_UNSELECTED;
}

VfxBool VappThemeListPage::check(VcpMenuPos pos)
{
#if 0
/* under construction !*/
#endif

	return VFX_TRUE;
}

VfxBool VappThemeListPage::isAsyncImage(VcpMenuPos pos)
{
#if defined(__MMI_THEME_SUPPORT_ASYNC_IMAGE__)
	if (isDltGroup(pos.group))
	{
		return VFX_TRUE;
	}
	else
#endif
	{
		return VFX_FALSE;
	}
}

void VappThemeListPage::onItemTap(VappThemeMatrixMenu *obj, VcpMenuPos pos)
{
	if (pos.pos >= 0)
	{
		m_selectPos = pos;
		
		// For the sake of performance, don't check validation at this stage.
		
		    VappThemePreviewPage *page;
		    VFX_OBJ_CREATE_EX(page, VappThemePreviewPage, getMainScr(), (this, pos, m_fgAllocator));	
			getMainScr()->pushPage('PREV', page);
	}
}

void VappThemeListPage::onSelect(VfxBool hasSelect)
{
    if (hasSelect)
    {
		if (m_themeData[m_selectPos.group]->isActivated(m_selectPos.pos))
		{
			// Popup PreviewPage
			getMainScr()->popPage();
			return;
		}
		
		VappThemeSwitchDesc param;
		
		m_themeData[m_selectPos.group]->genSwitchDesc(param, m_selectPos.pos);
		// A tricky way to resolve the performace issue
		mmi_id cui_id = VfxAppLauncher::createCui(
											VCUI_THEME_SWITCH,
											m_themeData[m_selectPos.group]->getCuiClassInfo(),
											getApp()->getGroupId(),
											&param,
											sizeof(VappThemeSwitchDesc));		
		
		VfxAppLauncher::runCui(cui_id);

    }
	else
	{
		// Popup PreviewPage
		getMainScr()->popPage();
	}
}

void VappThemeListPage::onNeedReset(VfxBool hasDltTheme)
{
	// 
	// If not on top active, there is no fg memory, so don't trigger relayout
	//
	if (!m_isReleased)
	{
		relayout();
	}

	m_isRefreshing = VFX_FALSE;
}


void VappThemeListPage::relayout(void)
{
	m_matrix->setCacheLen(VAPP_THEME_CELL_CACHE_LEN * getSize().height);	
	m_matrix->updateLayout();
}

#endif /*__MMI_THEMES_APPLICATION__*/
