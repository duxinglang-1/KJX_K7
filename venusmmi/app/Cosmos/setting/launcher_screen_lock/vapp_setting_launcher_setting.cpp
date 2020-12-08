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
 *  vapp_setting_launcher_settng.cpp
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
Dear yiquan,
it is ok on the temp~

[Yiquan, 05/08]
Dear Zhongxiao,
    would you help me to verify this CR with load as follow path:
    \\glbfs14\sw_releases\Valid_Before_20120601\from_yiquan\for_03181389\
    many thanks!

[Wen, 5/8]
Dear Yiqun:
@VappSettingVarUIPreviewPage::onToolBarClick, m_dluiProvider->setDefaultDLUI() has close the current page, so it will fatal error at the next instruction.
please return directly after setDefauldDLUI(), thanks a lot.

[Load Path]
\\mtksdd01.gslb.mediatek.inc\high_priority\sw_releases\W12.18\11B\official

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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_THEMES_APPLICATION__) || defined(__MMI_VUI_APP_ICON_ROBOT__) || defined(__MMI_VUI_APP_ICON_MM__) || defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) \
    || defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__) || defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__) 
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "../res/vapp_setting_dlui_memory.h"
#include "mmi_rp_vapp_setting_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_vapp_launcher_setting_def.h"

#if defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)
#include "mmi_rp_vapp_scr_lock_setting_def.h"
#endif

//#include "mmi_rp_vapp_theme_def.h"
#include "vcp_global_popup.h"
#include "vapp_fmgr.h"

#include "vapp_setting_launcher_scr_lock_gprot.h"

#include "vapp_launcher_gprot.h"
#include "vapp_setting_launcher_setting.h"
#include "vapp_setting_dlui_menu.h"
#include "vapp_setting_dlui_content_provider.h"
#include "vapp_setting_launcher_content_provider.h"
#include "vapp_setting_scr_lock_content_provider.h"

#include "vapp_setting_framework.h"
#include "vapp_setting_framework_gprot.h"

#include "Vapp_usb_gprot.h"
#include "vapp_theme_gprot.h"

extern "C"
{
#include "PhoneSetupResList.h"
#include "mmi_rp_file_type_def.h"
#include "Mmi_rp_app_usbsrv_def.h"
#ifdef __MMI_USB_SUPPORT__
#include "UsbSrvGprot.h"
#endif

#include "MMIDataType.h"
#include "ps_public_enum.h"
}
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/    
extern "C"
{
     typedef enum 
    {
        VCUI_DLUI_LAUNCHER,
        VCUI_DLUI_SCRNLOCK,
        VCUI_DLUI_CLR_STYLE,
        VCUI_DLUI_APPICON,
    
        VCUI_DLUI_END
    } VcuiDluiTypeEnum;
    
    typedef struct 
    {
        VfxU32 s_dluiType;
        VfxU32 s_dluiFgSize;
    } VcuiDluiDataStruct;

mmi_id vapp_launcher_setting_launch(mmi_id parentId)
{
	mmi_id id = GRP_ID_INVALID;
    
#if defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__)    
    VcuiDluiDataStruct args;
    args.s_dluiType = VCUI_DLUI_LAUNCHER;
    args.s_dluiFgSize = VAPP_SETTINGS_LAUNCHER_MAX_FG_MEMORY;
    id = VfxAppLauncher::createCui(
					VAPP_LAUNCHER_SETTING,
					VFX_OBJ_CLASS_INFO(VappLauncherSettingApp),
                    parentId,
                    &args,
                    sizeof(args)
                    );
#endif
	return id;
}

mmi_id vapp_scr_lock_setting_launch(mmi_id parentId)
{
	mmi_id id = GRP_ID_INVALID;
    
#if defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)
    VcuiDluiDataStruct args;
    args.s_dluiType = VCUI_DLUI_SCRNLOCK;
    args.s_dluiFgSize = VAPP_SETTINGS_SCR_LOCK_MAX_FG_MEMORY;
    id = VfxAppLauncher::createCui(
					VAPP_SCR_LOCK_SETTING,
                    VFX_OBJ_CLASS_INFO(VappLauncherSettingApp),
                    parentId,
                    &args,
                    sizeof(args));
#endif
	return id;
}

void vapp_dlui_setting_run(mmi_id cuiId)
{
    VfxAppLauncher::runCui(cuiId);
}

void vapp_dlui_setting_close(mmi_id cuiId)
{
    VfxAppLauncher::terminate(cuiId);
}
}

#if defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__) || defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)
/***************************************************************************** 
 * Class VappLauncherSettingApp
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappLauncherSettingApp", VappLauncherSettingApp, VfxCui);
void VappLauncherSettingApp::onInit()
{
    VfxApp::onInit(); 
    m_buffer = NULL;
    m_fgCntx = NULL;
    m_provider = NULL;
    m_dluiType = -1;
    m_fgSize = 0;
}
    
void VappLauncherSettingApp::onDeinit()
{
    freeBuffer();
    
    VfxApp::onDeinit();
}

void VappLauncherSettingApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

    if (NULL ==args)
        return;

    VcuiDluiDataStruct* arg = (VcuiDluiDataStruct*)args;
    
    m_dluiType = arg->s_dluiType;
    m_fgSize = arg->s_dluiFgSize;
    
    VfxMainScrEx* scr;
    VFX_OBJ_CREATE_EX(scr, VfxMainScrEx, this, (this));
    scr->show();
}

void VappLauncherSettingApp::onScr1stReady(VfxMainScrEx *scr)
{
    // create provider according to dlui type.
#if defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__)
    if (m_dluiType == VCUI_DLUI_LAUNCHER)
    {
        VFX_OBJ_CREATE(m_provider, VappLauncherContentProvider, scr);
    }
#endif // #if defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__) 
#if defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)
    if (m_dluiType == VCUI_DLUI_SCRNLOCK)
    {
        VFX_OBJ_CREATE(m_provider, VappScrLockContentProvider, scr);
    }
#endif //__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__
   // get default pos and create Buffer, so that pass the fgCntx to provider for getting the Screen shot.
    VcpMenuPos defPos(0, 0);
    m_provider->getDefaultDLUI(defPos.group, defPos.pos);
    createBuffer();
    m_provider->setScreenShotContext(m_fgCntx);

    VappSettingVarUIPreviewPage *preViewPage;    
    VFX_OBJ_CREATE_EX(preViewPage, VappSettingVarUIPreviewPage, scr, (m_provider, defPos));
    preViewPage->m_signalAllocFgMem.connect(this, &VappLauncherSettingApp::onGroupTopActive);
    preViewPage->m_signalRelaseFgMem.connect(this, &VappLauncherSettingApp::onGroupTopInactive);
    scr->pushPage(0, preViewPage); 
}

void VappLauncherSettingApp::onGroupTopActive(void)
{
    // if m_provider is NULL, then it should be the App is creating. So, need not be create Buffer here.
    // else it should be reentered, so need create Buffer with FG.
    if (m_provider && !m_fgCntx)
    {
        createBuffer();
        m_provider->setScreenShotContext(m_fgCntx);
        m_provider->m_signalUpdateScrnshot.emit();
    }    
}

void VappLauncherSettingApp::onGroupTopInactive(void)
{
    m_provider->m_signalReleaseAllScrnshot.emit();
    freeBuffer();
}


// helper
void VappLauncherSettingApp::createBuffer()
{
    if (NULL == m_buffer)
    {
        m_buffer = (VfxU8*)applib_asm_alloc_nc_r(m_groupId, m_fgSize);
        VFX_ASSERT(m_buffer != NULL);
    }
    
    if (NULL == m_fgCntx)
    {
        VFX_OBJ_CREATE(m_fgCntx, VfxContext, this);
    }
    m_fgCntx->assignPool(m_buffer, m_fgSize);
}

void VappLauncherSettingApp::freeBuffer()
{
    if (NULL != m_buffer)
    {
        applib_asm_free_r(m_groupId, m_buffer);
        m_buffer = NULL;
    }
    if (NULL != m_fgCntx)
    {
        VFX_OBJ_CLOSE(m_fgCntx);
    }
}
#endif // defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__) || defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)
#if defined (__MMI_VUI_SETTING_LAUNCHER_SELECTION__)
/***************************************************************************** 
 * VappSettingLauncherSettingCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingLauncherSettingCell", VappSettingLauncherSettingCell, VcpFormItemLauncherCell);

void VappSettingLauncherSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_LAUNCHER_SETTING));
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappSettingLauncherSettingCell::onTap);
}

void VappSettingLauncherSettingCell::onTap(VcpFormItemCell * sender,VfxId senderId)
{
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

    if (NULL != mainScr)
    {
        mmi_id launcherId = vapp_launcher_setting_launch(mainScr->getApp()->getGroupId());
        if (GRP_ID_INVALID != launcherId)
        {
            vapp_dlui_setting_run(launcherId);
        }
    }
}
#endif // #if defined (__MMI_VUI_SETTING_LAUNCHER_SELECTION__)

#if defined ( __MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)
/***************************************************************************** 
* VappSettingScreenLockSettingCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingScreenLockSettingCell", VappSettingScreenLockSettingCell, VcpFormItemLauncherCell);

void VappSettingScreenLockSettingCell::onInit()
{
    VcpFormItemLauncherCell::onInit();
    
    setMainText(VFX_WSTR_RES(STR_ID_VAPP_SETTING_SCREEN_LOCK_SETTING));
    setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_signalTap.connect(this, &VappSettingScreenLockSettingCell::onTap);
}

void VappSettingScreenLockSettingCell::onTap(VcpFormItemCell * sender,VfxId senderId)
{
    VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);

    if (NULL != mainScr)
    {
        mmi_id launcherId = vapp_scr_lock_setting_launch(mainScr->getApp()->getGroupId());
        if (GRP_ID_INVALID != launcherId)
        {
            vapp_dlui_setting_run(launcherId);
        }
    }
}
#endif //#if defined ( __MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)

/***************************************************************************** 
* VappSettingVarUIPreviewPage
*****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingVarUIPreviewPage",VappSettingVarUIPreviewPage,VfxPage);

VappSettingVarUIPreviewPage::VappSettingVarUIPreviewPage() :
    m_dluiProvider(NULL), m_focusPos(VcpMenuPos(-1, -1)), m_screenNum(0)
	{ }

VappSettingVarUIPreviewPage::VappSettingVarUIPreviewPage(IVappDLUISettingProvider* dluiProvider,
                                                        const VcpMenuPos& focusPos)
    :m_dluiProvider(dluiProvider), m_focusPos(focusPos), m_screenNum(0)
    { }


void VappSettingVarUIPreviewPage::onInit()
{
    VfxPage::onInit();
    
    VcpTitleBar* titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    VfxWString title = m_dluiProvider->getDLUIName(m_focusPos.group, m_focusPos.pos);    
    titleBar->setTitle(title);
    setTopBar(titleBar);

    VcpToolBar* buttomBar;
    VFX_OBJ_CREATE(buttomBar, VcpToolBar, this);
    buttomBar->m_signalButtonTap.connect(this, &VappSettingVarUIPreviewPage::onToolBarClick);
    buttomBar->addItem('OKAY', VFX_WSTR_RES(STR_GLOBAL_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    buttomBar->addItem('BACK', VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    setBottomBar(buttomBar);

    // Create menu
    _createBaseMenu();

    // get the text frame's height and create it.
    VfxS32 statusBarH = getMainScr()->getStatusBar()->getSize().height;
    VfxS32 titleBarH = getBar(VFX_PAGE_BAR_LOCATION_TOP)->getSize().height;
    VfxS32 textFramePosY = PREVIEW_TXT_POS - (statusBarH + titleBarH);

    _createTextFrame(textFramePosY);

    // set some properties of menu.
    m_baseMenu->m_signalFocusItemChange.connect(this, &VappSettingVarUIPreviewPage::onFoucsItemChanged);
    m_baseMenu->setFocused(VFX_TRUE);
    m_baseMenu->getLayout()->setFocusItem(m_focusPos);
    m_baseMenu->setCacheLen(1);
    m_dluiProvider->m_signalSetSuccess.connect(this, &VappSettingVarUIPreviewPage::onSetSuccess);
}

    // create and set base menu
void VappSettingVarUIPreviewPage::_createBaseMenu()
{
    VFX_OBJ_CREATE_EX(m_baseMenu, VappVarUIMenu, this, (m_dluiProvider));

    m_baseMenu->enableHorizontalScrollIndicator(VFX_FALSE);
    m_baseMenu->setPos(VfxPoint(0, PREVIEW_IMG_V_GAP));
    m_baseMenu->setSize(getSize().width, PREVIEW_BG_HEIGHT);
    m_baseMenu->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    m_baseMenu->setFreeRunUnit(VfxSize(PREVIEW_BG_WIDTH+PREVIEW_IMG_H_GAP, getSize().height));
    m_baseMenu->setMaxDecelerationDistance(PREVIEW_BG_WIDTH+PREVIEW_IMG_H_GAP, 0);
}

// create Text Frame
void VappSettingVarUIPreviewPage::_createTextFrame(VfxS32 positionY)
{
    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);    
    m_textFrame->setAnchor(0.5f, 0.5f);
    m_textFrame->setPos(getSize().width/2, positionY);
    m_textFrame->setSize(PREVIEW_IMG_WIDTH,PREVIEW_TEXT_SIZE);
    m_textFrame->setColor(VfxColor(0, 114, 114, 114));    

    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textFrame->setAutoResized(VFX_TRUE);

    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(PREVIEW_TEXT_SIZE);
    m_textFrame->setFont(fontDesc);
}

void VappSettingVarUIPreviewPage::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);
    m_signalAllocFgMem.emit();
	m_baseMenu->setCacheLen(1);
	m_baseMenu->updateLayout();
}

void VappSettingVarUIPreviewPage::onEntered()
{
    VfxPage::onEntered();

	//m_baseMenu->setCacheLen(VAPP_THEME_CELL_CACHE_LEN * getSize().width);	
    m_baseMenu->setCacheStyle(VCP_BASE_MENU_CACHE_STYLE_CENTER);
	m_baseMenu->setCacheLen(5 * (PREVIEW_BG_WIDTH + PREVIEW_IMG_H_GAP));	
	m_baseMenu->updateLayout();
}

void VappSettingVarUIPreviewPage::onExited2()
{
    m_signalRelaseFgMem.emit();

    VfxPage::onExited2();
}

void VappSettingVarUIPreviewPage::onFoucsItemChanged(VfxS32 group,VfxS32 pos)
{
    VfxWString title = m_dluiProvider->getDLUIName(group, pos);

    VcpTitleBar* titleBar = (VcpTitleBar*)getBar(VFX_PAGE_BAR_LOCATION_TOP);
    titleBar->setTitle(title);

    // get the caption
    VfxS32 index = m_baseMenu->menuPosToIndex(VcpMenuPos(group, pos));
    VfxS32 totalNum = m_baseMenu->getTotalItem();
    VfxWString caption;
    caption.format("%d/%d", index+1, totalNum);
    m_textFrame->setString(caption);
}

void VappSettingVarUIPreviewPage::onSetSuccess(VfxObject* sender, VfxBool result)
{
    if (result)
    {
		VfxMainScr* scr = getMainScr();
		if (scr && scr->getPage(scr->getTopPageId()) == this)
		{
			scr->popPage();
		}
    }
}

void VappSettingVarUIPreviewPage::onToolBarClick(VfxObject* sender, VfxId id)
{
    if ('OKAY' == id)
    {
        VcpMenuPos curPos = m_baseMenu->getLayout()->getFocusItem();
        VfxWString errStr;
        if (!m_dluiProvider->checkDluiValidate(curPos.group, curPos.pos, errStr))
        {
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, 
                                MMI_EVENT_INFO_BALLOON, 
                                MMI_NMGR_BALLOON_TYPE_INFO, 
                                errStr.getBuf());
            return;
        }
        m_dluiProvider->setDefaultDLUI(curPos.group, curPos.pos);
    }
    else
    {
	// setDefaultDLUI may pushPage()
        VfxMainScr* scr = getMainScr();
        if (NULL != scr && scr->getPage(scr->getTopPageId()) == this)
        {
            scr->exit();
        }
    }
}
#endif
