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
 *  vapp_setting_launcher_setting.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SETTING_LAUNCHER_SETTING_H__
#define __VAPP_SETTING_LAUNCHER_SETTING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_setting_dlui_content_provider.h"

#include "vcp_base_menu.h"
#include "vfx_control.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
/***************************************************************************** 
 * Class
 *****************************************************************************/
class VappVarUIMenu;
class VappSettingVarUIPreviewPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappSettingVarUIPreviewPage);
    // Overrides
protected:
    virtual void onInit();
	virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();	
    virtual void onExited2();

	// Methods
public:
    VappSettingVarUIPreviewPage();    
    VappSettingVarUIPreviewPage(IVappDLUISettingProvider* dluiProvider,
                                const VcpMenuPos& focusPos);
	virtual ~VappSettingVarUIPreviewPage() {m_dluiProvider->exit();}
	void onToolBarClick(VfxObject* sender, VfxId id);
	void onFoucsItemChanged(VfxS32 group, VfxS32 pos);
	void onSetSuccess(VfxObject* sender, VfxBool result);
	void _createBaseMenu();
	void _createTextFrame(VfxS32 positionY);

public:
    VfxSignal0 m_signalAllocFgMem;
    VfxSignal0 m_signalRelaseFgMem;
protected:
	IVappDLUISettingProvider* m_dluiProvider;
	VcpMenuPos m_focusPos;
	VappVarUIMenu* m_baseMenu;
	VfxTextFrame* m_textFrame;
	VfxS32 m_screenNum;
};

#if defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__) || defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)
class VappLauncherSettingApp : public VfxCui, public IVfxMainScrHandler
{
	VFX_DECLARE_CLASS(VappLauncherSettingApp);

public:
    void enterCurrent();
    void exitCurrent();
    // Overrides
    protected:
	void onInit(void);
	void onDeinit(void);
	void onRun(void * args,VfxU32 argSize);
	virtual void onScr1stReady(VfxMainScrEx *scr);
	void onGroupTopActive(void);
	void onGroupTopInactive(void);

private:
    void createBuffer();
    void freeBuffer();

protected:
	VfxContext* m_fgCntx;
    VfxU8* m_buffer;
    IVappDLUISettingProvider* m_provider;

private:
    VfxU32 m_dluiType;
    VfxU32 m_fgSize;
};
#endif // defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__) || defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)
#endif /* __VAPP_SETTING_LAUNCHER_SETTING_H__ */

