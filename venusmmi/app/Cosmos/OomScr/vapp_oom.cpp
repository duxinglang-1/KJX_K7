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
 *  vapp_oom.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  Cosmos OOM Screen
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_oom.h"
#include "vcp_popup.h"
#include "vcp_tool_bar.h"
#include "vcp_status_icon_bar.h"
#include "vapp_platform_context.h"

// resource header
#include "mmi_rp_vapp_oom_scr_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"   // for VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL

extern "C" {
#include "Mmi_frm_mem_prot.h"   // for mmi_frm_asmi_invoke_success_callback()
#include "mmiapi_func.h"   // for mmiapi_is_MMI_task()
#include "CommonScreensResDef.h" // for SCR_APPMEM_STOP_PROMPT
#include "AppMgrSrvGprot.h" // for srv_appmgr_get_app_package_name()
#include "GlobalResDef.h"


MMI_BOOL mmi_frm_asmi_check_enough_memory(mmi_id app_id);   // in AppMemMgrCore.c
}

/*****************************************************************************
 * Defines
 *****************************************************************************/

#if defined(__MMI_MAINLCD_480X800__)
static const VfxS32 VAPP_OOM_TITLE_TEXT_MARGIN = 14;
static const VfxS32 VAPP_OOM_TITLE_TEXT_FONT_SIZE = 26;

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
static const VfxS32 VAPP_OOM_TITLE_TEXT_MARGIN = 5;
static const VfxS32 VAPP_OOM_TITLE_TEXT_FONT_SIZE = 13;

#else // default HVGA 320X480
static const VfxS32 VAPP_OOM_TITLE_TEXT_MARGIN = 8;
static const VfxS32 VAPP_OOM_TITLE_TEXT_FONT_SIZE = 18;

#endif


#define ID_TOOLBAR_CANCEL		'CANL'


static void asm_mgr_invoke_release_mem_success_callback(mmi_id asmManagerGid, mmi_id launchAppId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(mmi_frm_asmi_check_enough_memory(launchAppId) );
    MMI_ASSERT(mmiapi_is_MMI_task() );
    /*
     * If press END key go back idle, we make the asm process ended and won't invoke success callback here.
     * Actually, mmi_display_popupcallback won't invoke callback if exit this popup screen.
     */
    mmi_frm_asmi_invoke_success_callback(launchAppId);
    mmi_frm_group_close(asmManagerGid);
}

/*****************************************************************************
 * Class VappOomScr
 *****************************************************************************/

VappOomScr::VappOomScr(mmi_id asmManagerGid, mmi_id launchAppId):
m_appStopState(STOPPED),
m_launchAppId(launchAppId),
m_asmManagerGid(asmManagerGid),
m_appToStop(0),
m_appList(NULL),
m_appCount(0),
m_confirmPopup(NULL),
m_indicatorPopup(NULL),
m_toolbar(NULL),
m_statusBar(NULL),
m_text(NULL),
m_popupConfirmed(VFX_FALSE)
{
}


void VappOomScr::onInit()
{
    VfxAppCatScr::onInit();

    initAppList();

    // create status bar
    VFX_OBJ_CREATE(m_statusBar, VcpStatusIconBar, this);
    m_statusBar->setAutoAnimate(VFX_TRUE);
    m_statusBar->setPos(0, 0);
    VfxS32 statusHeight = m_statusBar->getSize().height;

    // create toolbar
    VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
    m_toolbar->addItem(ID_TOOLBAR_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL),
            VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolbar->m_signalButtonTap.connect(this, &VappOomScr::onToolbarClick);
    VfxS32 toolbarHeight = m_toolbar->getSize().height;
    m_toolbar->setPos(0, getSize().height - toolbarHeight);
    m_toolbar->setSize(getSize().width, toolbarHeight);

    // create title region
    VfxFrame * textBackground;
    VFX_OBJ_CREATE(textBackground, VfxFrame, this);
    VFX_OBJ_CREATE(m_text, VcpTextView, textBackground);

    m_text->setPos(VAPP_OOM_TITLE_TEXT_MARGIN, VAPP_OOM_TITLE_TEXT_MARGIN);
    m_text->setSize(getSize().width - 2 * VAPP_OOM_TITLE_TEXT_MARGIN, 0);
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VAPP_OOM_TITLE_TEXT_FONT_SIZE);
    m_text->setFont(fontDesc);
    VfxWString string = VFX_WSTR_RES(STR_ID_APP_OOMSCR_LIST_TITLE);
    VfxWChar tempBuff[512];
    swprintf(( wchar_t*)tempBuff, 512, (wchar_t*)GetString(STR_ID_APP_OOMSCR_LIST_TITLE), (wchar_t*)GetString(applib_mem_ap_get_name(m_launchAppId) ) );
    string.loadFromMem(tempBuff);
    m_text->setText(string, NULL);
    m_text->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_WHITE);
    m_text->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
    m_text->setAutoResized(VFX_TRUE);
    m_text->forceUpdate();
    VfxS32 textHeight = m_text->getSize().height;

    textBackground->setImgContent(VfxImageSrc(IMG_ID_VAPP_OOMSCR_HINT_BG) );
    textBackground->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    textBackground->setPos(0, statusHeight);
    textBackground->setSize(getSize().width, textHeight + 2 * VAPP_OOM_TITLE_TEXT_MARGIN);

    // create the list
    VFX_OBJ_CREATE(m_list, VcpListMenu, this);
    m_list->addMarginAreaFrame(VCP_LIST_MENU_MARGIN_AREA_TOP, 
            VCP_LIST_MENU_MARGIN_AREA_FRAME_PLACEMENT_LEFT, textBackground);
	m_list->setPos(VfxPoint(0, statusHeight) );
    VfxS32 listHeight = getSize().height - statusHeight - toolbarHeight;
	m_list->setSize(getSize().width, listHeight);
    m_list->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
	m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_list->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON);

    m_list->setContentProvider(this);

	m_list->m_signalItemTapped.connect(this, &VappOomScr::onListTapped);
    m_list->m_signalCmdButtonClicked.connect(this, &VappOomScr::onCmdButtonClicked);

    // create the popups
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
    m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_confirmPopup->setCustomButton(VFX_WSTR_RES(STR_ID_APP_OOMSCR_EXIT),
            VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_WARNING, VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VappOomScr::confirmPopupHandler);
    m_confirmPopup->setAutoDestory(VFX_FALSE);
    m_confirmPopup->m_signalPopupState.connect(this, &VappOomScr::onPopupStateChange);
    

    VFX_OBJ_CREATE(m_indicatorPopup, VcpIndicatorPopup, this);
    m_indicatorPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_indicatorPopup->setText(VFX_WSTR_RES(STR_ID_APP_OOMSCR_EXITING));
    m_indicatorPopup->setAutoDestory(VFX_FALSE);
}

void VappOomScr::onDeinit()
{
    deinitAppList();
    VfxAppCatScr::onDeinit();
}

void VappOomScr::onAppClosed()
{
    if (m_appStopState == STOPPING || m_appStopState == CANCEL || MMI_FRM_ASM_NOT_PREPARE_MEMORY == mmi_frm_asm_get_asm_state())
    {
        // In OOM normal stop app procedure.
        return;
    }
    mmi_id asmManagerGid = m_asmManagerGid;
    mmi_id launchAppId   = m_launchAppId;

    if (mmi_frm_asmi_check_enough_memory(m_launchAppId) )
    {
        asm_mgr_invoke_release_mem_success_callback(asmManagerGid, launchAppId);
        VfxWString string;
        VfxWChar tempBuff[255];
        swprintf(( wchar_t*)tempBuff, 255, (wchar_t*)GetString(STR_ID_APP_OOMSCR_MEMORY_ENOUGH_AND_RUN), (wchar_t*)GetString(applib_mem_ap_get_name(launchAppId)));
        string.loadFromMem(tempBuff);
        
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_SUCCESS,
            string.getBuf());
    }

	return;
}

void VappOomScr::initAppList()
{
    VFX_ALLOC_MEM(m_appList, MMI_FRM_APPMEM_MAX_APP_PROMPTED * sizeof(applib_mem_ap_usage_struct), this);
    reloadAppList();
}

void VappOomScr::reloadAppList()
{
    m_appCount = mmi_frm_asm_get_asm_usage(m_launchAppId, m_appList, MMI_FALSE, MMI_FALSE);
}

void VappOomScr::deinitAppList()
{
    VFX_FREE_MEM(m_appList);
}

VfxBool VappOomScr::onKeyInput(VfxKeyEvent &event)
{
    if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch (event.keyCode)
        {
        case VFX_KEY_CODE_BACK:
            mmi_frm_asmi_invoke_cancel_callback(m_launchAppId, MMI_FRM_APPMEM_CANCEL_BACK_FROM_PROMPT_SCRN);
			m_appStopState = CANCEL;
            mmi_frm_group_close(m_asmManagerGid);
            return FALSE;
        default:
            break;
        };
    }
    return VfxAppCatScr::onKeyInput(event);
}


VfxU32 VappOomScr::getCount() const
{
    return m_appCount;
}

VfxBool VappOomScr::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text = getAppTitle(index);
        color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

VfxBool VappOomScr::getItemTextFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VcpRichText &format)
{
    return VFX_FALSE;
}

VfxBool VappOomScr::getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image)
{
    if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL ||
           fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED ||
           fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
    {
        image.setResId(IMG_ID_VAPP_OOMSCR_CLOSE_ICON);
        return VFX_TRUE;
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
    {
        image.setResId(IMG_ID_VAPP_OOMSCR_CLOSE_ICON);
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappOomScr::getItemIsHighlightable(VfxU32 index) const
{
    return VFX_FALSE;
}

VfxWString VappOomScr::getAppTitle(VfxU32 index)
{
    VfxWString result;
    if (m_appList[index].app_id == VAPP_WIDGET_DELEGATOR)
    {
        WCHAR string[MMI_APP_NAME_MAX_LEN];
        mmi_ret ret = srv_appmgr_get_app_package_name("native.mtk.vapp_widget_delegator", string);
        if (ret == MMI_RET_OK)
        {
            result.loadFromMem(string);
            return result;
        }
    }

    if (APPMEM_STR_NON_DEFINED == m_appList[index].string_id)
    {
        result.format("APP%d", m_appList[index].app_id);
    }
    else
    {
        result.loadFromMem((WCHAR*)GetString(m_appList[index].string_id));
    }
    return result;
}

void VappOomScr::onListTapped(VcpListMenu * sender, VfxU32 index)
{
}

extern "C" kal_int32 srv_java_appfactory_get_running_app_num(void);

void VappOomScr::onCmdButtonClicked(VcpListMenu * sender, VfxU32 index)
{
    VfxBool javaApp = VFX_FALSE;
#ifdef __J2ME__
    if (m_appList[index].app_id == APPLIB_MEM_AP_ID_JAVA)
    {
        javaApp = VFX_TRUE;
    }
#endif

    VfxWString text;
    if (javaApp)
    {
#ifdef __J2ME__
        kal_int32 javaCount = srv_java_appfactory_get_running_app_num();
        if (javaCount <= 1)
        {
            VfxWChar tempBuff[255];
            swprintf(( wchar_t*)tempBuff, 255, (wchar_t*)GetString(STR_ID_APP_OOMSCR_CONFIRM_EXIT_NORMAL_TEXT), (wchar_t*)getAppTitle(index).getBuf() );
            text.loadFromMem(tempBuff);
        }
        else if (javaCount == 2)
        {
            text = VFX_WSTR_RES(STR_ID_APP_OOMSCR_CONFIRM_EXIT_2_JAVA_TEXT);
        }
        else
        {
            VfxWChar tempBuff[255];
            swprintf(( wchar_t*)tempBuff, 255, (wchar_t*)GetString(STR_ID_APP_OOMSCR_CONFIRM_EXIT_MOER_JAVA_TEXT), javaCount);
            text.loadFromMem(tempBuff);
        }
#endif // __J2ME__
    }
    else
    {
        VfxWChar tempBuff[255];
        swprintf(( wchar_t*)tempBuff, 255, (wchar_t*)GetString(STR_ID_APP_OOMSCR_CONFIRM_EXIT_NORMAL_TEXT), (wchar_t*)getAppTitle(index).getBuf() );
        text.loadFromMem(tempBuff);
    }
    
    m_confirmPopup->setText(text);
    m_confirmPopup->show(VFX_TRUE);
    m_appToStop = m_appList[index].app_id;
}

void VappOomScr::confirmPopupHandler(VfxObject* obj, VfxId id)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
		ShowIndicatorPopup();
		mmi_frm_asm_stop_app_by_MMI_task(m_appToStop, MEM_AP_STOP_TYPE_FORCE);

        // remove the id from app list
        for (int i = 0; i < m_appCount; ++i)
        {
            if (m_appList[i].app_id == m_appToStop)
            {
                for (int j = i; j < (m_appCount - 1); ++j)
                {
                    memcpy(&m_appList[j], &m_appList[j+1], sizeof(m_appList[0]));
                }
                --m_appCount;
                break;
            }
        }

    }
}

void VappOomScr::onToolbarClick(VfxObject* obj, VfxId id)
{
    if (id == ID_TOOLBAR_CANCEL)
    {
        mmi_frm_asmi_invoke_cancel_callback(m_launchAppId, MMI_FRM_APPMEM_CANCEL_BACK_FROM_PROMPT_SCRN);
		m_appStopState = CANCEL;
        mmi_frm_group_close(m_asmManagerGid);
    }
}

void VappOomScr::onStopFinished()
{
    // reload
    m_indicatorPopup->hide(VFX_TRUE);
    m_appStopState = STOPPED;
    if (mmi_frm_asmi_check_enough_memory(m_launchAppId) )
    {
        asm_mgr_invoke_release_mem_success_callback(m_asmManagerGid, m_launchAppId);
    }
    else
    {
        // reload list
        m_list->updateAllItems();
        reloadAppList();
    }
}

void VappOomScr::onPopupStateChange(VfxBasePopup* obj,  VfxBasePopupStateEnum state)
{
	if (m_confirmPopup == obj)
	{
		switch (state)
		{
			case VFX_BASE_POPUP_AFTER_END_ANIMATION:
                m_popupConfirmed = VFX_FALSE;
				break;
            default:
                break;
		}
	}
}

void VappOomScr::ShowIndicatorPopup(void)
{
    m_appStopState = STOPPING;
    m_indicatorPopup->show(VFX_TRUE);
    m_popupConfirmed = VFX_TRUE;	
}

/*****************************************************************************
 * Others
 *****************************************************************************/

static VappOomScr * g_vapp_oom_scr = NULL;

struct VappOomGuiData
{
    mmi_id asmManagerGid;

    mmi_id launchAppId;
};

static VappOomGuiData gOomContext;

extern "C" void vadp_p2v_vapp_oom_exit();


extern "C" void vadp_p2v_vapp_oom_entry()
{
    if (g_vapp_oom_scr == NULL)
    {
        if (!mmi_frm_scrn_enter(gOomContext.asmManagerGid,
                                SCR_APPMEM_STOP_PROMPT,
                                vadp_p2v_vapp_oom_exit,
                                vadp_p2v_vapp_oom_entry,
                                MMI_FRM_FULL_SCRN))
        {
            return;
        }

        VfxAppCatScr::initalize();

        //VFX_OBJ_CREATE_EX(g_vapp_oom_scr, VappOomScr, VfxAppCatScr::getContext(), (gOomContext.asmManagerGid, gOomContext.launchAppId) );
        VFX_OBJ_CREATE_EX(g_vapp_oom_scr, VappOomScr, VFX_OBJ_GET_INSTANCE(VappPlatformContext), (gOomContext.asmManagerGid, gOomContext.launchAppId) );

		if(MMI_FRM_ASM_IS_WAITING_APP_STOP == mmi_frm_asm_get_asm_state())
		{
			g_vapp_oom_scr->ShowIndicatorPopup();
		}

    }
}

extern "C" void vadp_p2v_vapp_oom_exit()
{
    if (g_vapp_oom_scr != NULL)
    {
        VFX_OBJ_CLOSE(g_vapp_oom_scr);

        VfxAppCatScr::deinitalize();
    }
}

extern "C" void vadp_p2v_vapp_oom_init(mmi_id asmManagerGid, mmi_id launchAppId)
{
    gOomContext.asmManagerGid = asmManagerGid;
    gOomContext.launchAppId = launchAppId;
    vadp_p2v_vapp_oom_entry();
}

extern "C" void vadp_p2v_vapp_oom_stop_finished()
{
    if (g_vapp_oom_scr != NULL)
    {
        g_vapp_oom_scr->onStopFinished();
    }
}

extern "C" mmi_ret vadp_p2v_vapp_oom_event_handler(mmi_event_struct *evt)
{
    // when group under root has been closed
    if (evt->evt_id == EVT_ID_APP_TERMINATED)
    {
        // in OOM screen
        if (g_vapp_oom_scr != NULL)
        {
    		g_vapp_oom_scr->onAppClosed();
    	}
    }
	return MMI_RET_OK;
}

