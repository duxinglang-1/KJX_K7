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
 *  vapp_theme_app_icon.h
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
#ifndef __VAPP_THEME_APPICON_H__
#define __VAPP_THEME_APPICON_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"
#include "vfx_cui.h"

#include "vcp_form.h"

#include "vapp_theme.h"
#include "vapp_theme_list.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define DLT_THEME_TAG 0x38
#define THM_TRC_GRP TRACE_GROUP_2

#define VAPP_THEME_SYSTEM_APPICON_CNT (1)
#define VAPP_THEME_SYSTEM_APPICON_POS(_pos) (_pos - VAPP_THEME_SYSTEM_APPICON_CNT)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * VappThemeCell 
 *****************************************************************************/
class VappThemeAppIconCell : public VcpFormItemLauncherCell
{
	VFX_DECLARE_CLASS(VappThemeAppIconCell);

// Constructor
public:
	VappThemeAppIconCell(){}

// Override
protected:
	virtual void onInit();
	void onTap(VcpFormItemCell* sender, VfxId senderId);
};


#ifndef __MMI_VUI_DOWNLOADABLE_APP_ICON__
/***************************************************************************** 
 * VappThemeAppIconCntx
 *****************************************************************************/
class VappThemeAppIconCntx : public VappThemeCntx
{
	VFX_OBJ_DECLARE_SINGLETON_CLASS(VappThemeAppIconCntx);
	
protected:
	VappThemeAppIconCntx();

// Overridable
public:
    using VappThemeCntx::active;
	virtual VfxS16 active(VfxU32 index);
	virtual VfxS16 deactive(void);
	virtual VfxU32 getActiveIndex(void);
	virtual VfxBool setActiveIndex(VfxU32 index);
	virtual void setIsDltActive(VfxBool isDlt, VfxU32 index = 0) { setActiveIndex(index); }
	virtual VfxBool checkActive(void);
	virtual VfxU32 restoreAppicon(void);
	virtual void onLauncherChange(void);
	
protected:
	VfxS32 m_hdlr;
};
#endif //  __MMI_VUI_DOWNLOADABLE_APP_ICON__


/***************************************************************************** 
 * Class VcuiThemeAppIcon
 *****************************************************************************/
class VcuiThemeAppIcon : public VappThemeApp
{
	VFX_DECLARE_CLASS(VcuiThemeAppIcon);
public:
	VcuiThemeAppIcon() : VappThemeApp() {}

protected:
	virtual void onScr1stReady(VfxMainScrEx *scr);
};


/***************************************************************************** 
 * Class VappThemeAppIcon
 *****************************************************************************/
class VappThemeAppIcon : public VfxApp, public IVfxMainScrHandler
{
	VFX_DECLARE_CLASS(VappThemeAppIcon);
public:
	VappThemeAppIcon() : m_allocator(NULL) {}

protected:
	virtual void onInit(void);
	virtual void onDeinit(void);
	virtual void onRun(void * args,VfxU32 argSize);
	virtual void onScr1stReady(VfxMainScrEx *scr);
	virtual void onGroupTopActive(void);
	virtual void onGroupTopInactive(void);

private:
	VappThemeMemAllocator *m_allocator;
};


/***************************************************************************** 
 * Class VappThemeSysData
 *****************************************************************************/
class VappThemeAppIconData : public VappThemeSysData
{
public:
	VappThemeAppIconData(){}
// Override
	virtual VfxBool getTypeStr(VfxWString &typeName);
	virtual VfxImageSrc getThumbnail(VfxS32 pos, VfxU8 *buffer, VfxU32 size);
	virtual VfxImageSrc getPreviewImg(VfxS32 pos, VfxU8 *buffer, VfxU32 size);
	virtual VfxU32 getCount(void) const;
	virtual VfxWString getText(VfxS32 pos);
	virtual VfxBool isActivated(VfxS32 pos);
	virtual void genSwitchDesc(VappThemeSwitchDesc &desc, VfxS32 pos);
	virtual VfxClassInfo *getCuiClassInfo(void);
};


/***************************************************************************** 
 * Class VappThemeAppIconSwitchCui
 *****************************************************************************/
class VappThemeAppIconSwitchCui : public VappThemeSwitchCui
{
    VFX_DECLARE_CLASS(VappThemeAppIconSwitchCui);   

// Overridable
protected:
	virtual VfxBool active(void);
};


/***************************************************************************** 
 * Class VappThemeAppIconListPage
 *****************************************************************************/
class VappThemeAppIconListPage : public VappThemeListPage
{
// Constructor
public:
	VappThemeAppIconListPage(VappThemeMemAllocator *fgAllocator = NULL) : VappThemeListPage(fgAllocator)
	{}

// Override
protected:	
	virtual void onInitData(void);
	virtual VfxU32 getGroupCount() const;
	virtual VfxBool isDltGroup(VfxS32 group) const;
	virtual VfxBool getMenuEmptyText(VfxWString &text);

};

extern 	mmi_id vapp_theme_appicon_launch(void);
extern VfxS32 vapp_theme_appicon_for_curr_launcher(VfxS32 launcherIntType);

#endif /* __VAPP_THEME_APPICON_H__ */
#endif /*__MMI_THEMES_APPLICATION__*/
