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
 *  vapp_theme.h
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
#ifdef __MMI_THEMES_APPLICATION__

#ifndef __VAPP_THEME_H__
#define __VAPP_THEME_H__

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
#include "vcp_form.h"

#include "vapp_setting_dlui_menu.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define DLT_THEME_TAG 0x38
#define THM_TRC_GRP TRACE_GROUP_2
#define INVALID_THEME_HANDLE (0xFFFFFFFF)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
/***************************************************************************** 
 * VappThemeCell 
 *****************************************************************************/
class VappThemeCell : public VcpFormItemLauncherCell
{
	VFX_DECLARE_CLASS(VappThemeCell);

// Constructor
public:
	VappThemeCell(){}

// Override
protected:
	virtual void onInit();

// Methods
private:
	void onTap(VcpFormItemCell* sender, VfxId senderId);
};


/***************************************************************************** 
 * Class VappThemeMemAllocator
 *****************************************************************************/
class VappThemeMemAllocator : public VfxObject
{
public:
	VappThemeMemAllocator(mmi_id grpId = GRP_ID_INVALID);

	void setGroupId(mmi_id grpId){ m_groupId = grpId; }
	VfxU8 *allocMem(VfxS32 size);
	void freeMem(void *mem);
	void createBuffer(void);
	void freeBuffer(void);

	VfxSignal0 m_signalBeforeMemFree;
	VfxSignal0 m_signalMemReady;
	
private:
	VfxBool isMemValid(void);
	
protected:
	void *m_buffer;
	KAL_ADM_ID m_heapId;
	VfxU32 m_counter;
	mmi_id m_groupId;
};


/***************************************************************************** 
 * Class VappThemeApp
 *****************************************************************************/
class VappThemeApp : public VfxCui, public IVfxMainScrHandler
{
	VFX_DECLARE_CLASS(VappThemeApp);
public:
	VappThemeApp() :m_allocator(NULL) {};

protected:
	virtual void onInit(void);
	virtual void onDeinit(void);
	virtual void onRun(void * args,VfxU32 argSize);
	virtual void onScr1stReady(VfxMainScrEx *scr);
	virtual void onGroupTopActive(void);
	virtual void onGroupTopInactive(void);
	mmi_id getAppGroupId(void);

protected:
	VappThemeMemAllocator *m_allocator;
};


/***************************************************************************** 
 * Class VappThemeCntx
 *****************************************************************************/
class VappThemeCntx : public VfxObject
{
	VFX_OBJ_DECLARE_SINGLETON_CLASS(VappThemeCntx);
	
protected:
	VappThemeCntx();

// Inteface:
public:
	virtual VfxU32 getActiveIndex(void);
	virtual VfxBool setActiveIndex(VfxU32 index);

// Overridable	
public:
	virtual VfxS16 active(const VfxWChar *path){ return -1; }
	virtual VfxS16 active(VfxU32 index);
	virtual VfxS16 deactive(void);

	virtual VfxBool isDltActive(void);
	virtual void setIsDltActive(VfxBool isDlt, VfxU32 index = 0);
	virtual VfxBool checkActive(void);
};


/***************************************************************************** 
 * Class VappThemeData
 *****************************************************************************/
class VfxClassInfo;
class VappThemeSwitchDesc;
class VappThemeData : public VfxObject
{
public:
	typedef enum
	{
		THEME_TYPE_SYS,	
#if defined(__MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__) || defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__)
		THEME_TYPE_DLT,
#endif
		THEME_TYPE_TOTAL
	}ThemeTypeEnum;

//Overridable
	virtual VfxBool getTypeStr(VfxWString &typeName){ return VFX_FALSE; }
	virtual void active(VfxS32 index){}
	virtual VfxU32 getCount(void) const { return 0; }
	virtual VfxImageSrc getPreviewImg(VfxS32 pos, VfxU8 *buffer, VfxU32 size){ return VFX_IMAGE_SRC_NULL; }
	virtual VfxImageSrc getThumbnail(VfxS32 pos, VfxU8 *buffer, VfxU32 size){ return VFX_IMAGE_SRC_NULL; }
	virtual VfxWString getText(VfxS32 pos) { return VFX_WSTR_NULL; }
	virtual VfxBool isActivated(VfxS32 pos){ return VFX_FALSE; }
	virtual void genSwitchDesc(VappThemeSwitchDesc &switchData, VfxS32 pos);
	virtual VfxClassInfo *getCuiClassInfo(void) { return NULL; }
	virtual VfxBool isValid(VfxS32 pos) { return VFX_TRUE; }
	
	VfxSignal1<VfxBool> m_signalNeedReset;
};


/***************************************************************************** 
 * Class VappThemeSwitchDesc
 *****************************************************************************/
class VappThemeSwitchDesc
{
public:
	VappThemeSwitchDesc();
	
	void initRes(void);
	VappThemeSwitchDesc &operator =(const VappThemeSwitchDesc &other);
	
	VappThemeData::ThemeTypeEnum type;
	union
	{
		VfxS32 index;
		VfxWChar *path;
		void *usr_data;
	}u;
	
	VfxId m_switchingId;
	VfxId m_invalidId;
	VfxId m_changedId;
	VfxId m_compatibleAskId;
	VfxId m_switchAskId;

	VfxBool isNeedConfirm;
	VfxBool isRestore;
};

/***************************************************************************** 
 * Class VappThemeSysData
 *****************************************************************************/
class VappThemeSysData : public VappThemeData
{
public:
	VappThemeSysData(){}

// Override
	virtual VfxBool getTypeStr(VfxWString &typeName);
	virtual VfxU32 getCount(void) const;
	virtual VfxImageSrc getPreviewImg(VfxS32 pos, VfxU8 *buffer, VfxU32 size);
	virtual VfxImageSrc getThumbnail(VfxS32 pos, VfxU8 *buffer, VfxU32 size);
	virtual VfxWString getText(VfxS32 pos);
	virtual VfxBool isActivated(VfxS32 pos);
	virtual void genSwitchDesc(VappThemeSwitchDesc &desc, VfxS32 pos);
	virtual VfxClassInfo *getCuiClassInfo(void);
};



/***************************************************************************** 
 * Class VappThemeSwitchMainScr
 *****************************************************************************/
class VappThemeSwitchMainScr : public VfxMainScr
{
// Methods
public:
    VappThemeSwitchMainScr() {setIsSmallScreen();}

// Overrides
protected:
    virtual void on1stReady() {setBgColor(VFX_COLOR_TRANSPARENT);}
};


/***************************************************************************** 
 * Class VappThemeSwitchCui
 *****************************************************************************/
class VappThemeSwitchCui : public VfxCui
{
    VFX_DECLARE_CLASS(VappThemeSwitchCui);    
public:
	VappThemeSwitchCui() : m_mainScr(NULL){ m_switchDesc.initRes();}
	
// Overrides
protected:
    virtual void onRun(void * args, VfxU32 argSize);

// Overridable
protected:
	virtual VfxBool active(void);
	virtual VfxS32 checkValid(void){ return 0; }
	
private:
	void onCompatibleCallback(VfxObject *obj, VfxId id);
	void showProgress(void);
	void onPopState(VfxBasePopup *sender, VfxBasePopupStateEnum state);
	void onConfirm(VfxObject *obj, VfxId id);

// Implement
protected:
	VappThemeSwitchMainScr *m_mainScr;
	VappThemeSwitchDesc m_switchDesc;

};

#endif /* __VAPP_THEME_H__ */
#endif /*__MMI_THEMES_APPLICATION__*/
