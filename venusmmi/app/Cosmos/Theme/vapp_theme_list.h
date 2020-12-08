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
 *  vapp_theme_list.h
 *
 * Project:
 * --------
 *  Venus
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
#ifdef __MMI_THEMES_APPLICATION__
#ifndef __VAPP_THEME_LIST_H__
#define __VAPP_THEME_LIST_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"
#include "vfx_weak_ptr.h"
#include "vfx_base_popup.h"
#include "vfx_cui.h"

#include "vcp_list_menu.h"
#include "vcp_indicator_popup.h"
#include "vcp_form.h"

#include "vapp_setting_dlui_menu.h"
#include "vapp_setting_dlui_content_provider.h"
#include "vapp_setting_launcher_setting.h"
#include "vapp_theme_menu.h"

/***************************************************************************** 
 * Class VappThemePreviewPage
 *****************************************************************************/
class VappThemePreviewPage: public VappSettingVarUIPreviewPage
{
public:
	VappThemePreviewPage() : VappSettingVarUIPreviewPage() {}
    VappThemePreviewPage(IVappDLUISettingProvider* provider, const VcpMenuPos& pos, VappThemeMemAllocator *fgAllocator);

// Override
protected:
	virtual void onInit(void);
	virtual void onEntered(void);

private:
	void onInactive(void);
	void onMemReady(void);

private:
	VfxBool m_isReleased;
	VappThemeMemAllocator *m_fgAllocator;
};


/***************************************************************************** 
 * Class VappThemeListPage
 *****************************************************************************/
class VappThemeListPage : public VfxPage, public IVappThemeMatrixMenuContentProvider, public IVappDLUISettingProvider
{
// Constructor
public:
	VappThemeListPage(VappThemeMemAllocator *fgAllocator = NULL);

	static mmi_ret onDevEvt(mmi_event_struct *evt);

	virtual mmi_ret onProc(mmi_event_struct * evt);

// Override
protected:	
	virtual void onInit(void);
	virtual void onDeinit(void);
	virtual void onEnter(VfxBool isBackward);
	virtual void onEntered(void);
	virtual void onExited2(void);
	void onInactive(void);

	// Matrix menu interface
   	virtual VfxBool getMenuEmptyText(VfxWString &text);
	virtual VfxBool hasGroupHeader(VfxS32 group) const
	{
		return (getGroupCount() > 1);
	}

	virtual VfxU32 getCount(VfxU32 group) const
	{
		if (isDltGroup(group) && !m_isShowDltGroup)
		{
			return 0;
		}
		
		return m_themeData[group]->getCount();		
	}
	
	virtual VfxU32 getGroupCount() const 
    {
#ifdef __MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__
        return VappThemeData::THEME_TYPE_TOTAL;
#else
        return 1;
#endif
    }
	virtual VfxBool getItemText(VcpMenuPos pos, VfxWString &text);
	virtual VfxBool getItemImage(VcpMenuPos pos, VfxImageSrc &src);
	virtual VfxBool freeItemImage(VcpMenuPos pos, VfxImageSrc &src);
	virtual void * allocNcMem(VfxU32 size, void *userData);
	virtual void freeNcMem(void *mem, void *userData);
	virtual VappThemeMenuItemStateEnum getItemState(VcpMenuPos pos ) const;
	virtual VfxBool check(VcpMenuPos pos);
	virtual VfxBool isAsyncImage(VcpMenuPos pos);

	// Preview interface
	virtual void exit(){}
	virtual VfxBool getDLUIThumb(VfxS32 group, VfxS32 pos, VfxImageSrc& image){ return VFX_FALSE; }
	virtual VfxFrame* getDLUIScreenShot(VfxS32 group, VfxS32 pos);
	virtual VfxBool freeDLUIScreenShot(VfxS32 group, VfxS32 pos, VfxFrame* previewImg);
	virtual const VfxWString getDLUIName(VfxS32 group, VfxS32 pos)
	{
		return m_themeData[group]->getText(pos);
	}
	virtual VfxS32 getDLUIGroupCount() const
	{
		return getGroupCount();
	}
	virtual VfxS32 getDLUIItemCount(VfxS32 group) const
	{
		return m_themeData[group]->getCount();
	}

	virtual VfxBool getDefaultDLUI(VfxS32& group, VfxS32& pos)
	{
		group = pos = 0;
		return VFX_TRUE;
	}

	virtual void setDefaultDLUI(VfxS32 group, VfxS32 pos)
	{
		m_selectPos.group = group;
		m_selectPos.pos = pos;
		
		onSelect(VFX_TRUE);
	}
	
	virtual VfxBool isCurUIDefault(VfxS32 group, VfxS32 pos) const
	{
		 return (getItemState(VcpMenuPos(group, pos)) == VAPP_THEMEE_MENU_ITEM_STATE_SELECTED);
	}

	virtual VfxBool isDltGroup(VfxS32 group) const
	{
		return (group > VappThemeData::THEME_TYPE_SYS);
	}
	
// Overridable
protected:
	void active(const VcpMenuPos &pos)
	{
		m_activeType = (VappThemeData::ThemeTypeEnum)pos.group;
		m_themeData[pos.group]->active(pos.pos);
	}

	virtual void onInitData(void);
	virtual void onItemTap(VappThemeMatrixMenu *obj, VcpMenuPos pos);
	void onSelect(VfxBool hasSelect);
	void onNeedReset(VfxBool hasDltTheme);
	void relayout(void);
	void createMenu(void);
	void updateFgChild(void);
	void releaseFgChild(void);
	
protected:
	VappThemeData::ThemeTypeEnum m_activeType;
	VcpMenuPos m_selectPos;

	VappThemeData *m_themeData[VappThemeData::THEME_TYPE_TOTAL];
	VappThemeMatrixMenu *m_matrix;
	VfxBool m_isReleased;
	VfxBool m_isRefreshing;
	VfxBool m_isShowDltGroup;
	VappThemeMemAllocator *m_fgAllocator;
};


#endif /* __VAPP_THEME_LIST_H__ */
#endif /*__MMI_THEMES_APPLICATION__*/
