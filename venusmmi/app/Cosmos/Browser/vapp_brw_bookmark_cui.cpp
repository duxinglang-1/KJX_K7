
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * vapp_brw_bookmark_cui.cpp
 *
 * Project:
 * --------
 *   MAUI
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _VAPP_BRW_BOOKMARK_CUI_CPP_
#define _VAPP_BRW_BOOKMARK_CUI_CPP_

/*  Include: MMI header file */
#ifdef __MMI_BROWSER_2__

#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */
#include "BrowserSrvProts.h"
#include "BrowserSrvBookmarks.h"
#include "Conversions.h"
#include "vcui_bookmark_gprot.h"
#include "GlobalResDef.h"
#include "app_mem.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_events_gprot.h"
#ifdef __cplusplus
}
#endif /* __cplusplus */
#include "vapp_brw_bookmark_cui.h"

mmi_id m_bowserBookmarkCuiId = GRP_ID_INVALID;
VfxBool m_is_asm_initialized = VFX_FALSE;

#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */

mmi_id vcui_bkm_sel_bkm_create(mmi_id parent_id)
{
    if(parent_id != GRP_ID_INVALID)
    {
    	
        if(m_bowserBookmarkCuiId != GRP_ID_INVALID) // cui has been created
        {
            VappBrowserUtility::displayPopup(STR_GLOBAL_NOT_AVAILABLE, MMI_NMGR_BALLOON_TYPE_FAILURE, MMI_EVENT_INFO_BALLOON);
            return GRP_ID_INVALID;
        }
        vapp_brw_bookmark_launch_args args;
        args.isBookmarkAddMode = VFX_FALSE;
        m_bowserBookmarkCuiId = VfxAppLauncher::createCui(
                                            VCUI_BKM,
                                            VFX_OBJ_CLASS_INFO(VappBrwBookmarkCui),
                                            parent_id,
                                            &args,
                                            sizeof(vapp_brw_bookmark_launch_args));
        return m_bowserBookmarkCuiId;
    }
    else
    {
        return GRP_ID_INVALID;
    }
}



/* Execute CUI*/
void vcui_bkm_sel_bkm_run(mmi_id cui_id)
{
#if 1
		if (!g_srv_brw_memory_pool)
        {
            g_srv_brw_memory_pool = mmi_frm_asm_alloc_nc_r(VCUI_BKM, SRV_BRW_BOOKMARK_POOL_SIZE);
            if (!g_srv_brw_memory_pool)
            {
                VappBrowserUtility::displayPopup(STR_GLOBAL_NOT_AVAILABLE, MMI_NMGR_BALLOON_TYPE_FAILURE, MMI_EVENT_INFO_BALLOON);
            }
            m_is_asm_initialized = VFX_TRUE;
            g_srv_brw_cntx.brw_adm_id = kal_adm_create(
                                        (char*)g_srv_brw_memory_pool,
                                        SRV_BRW_BOOKMARK_POOL_SIZE,
                                        NULL,
                                        KAL_FALSE);
            MMI_ASSERT(g_srv_brw_cntx.brw_adm_id);
        }
        VfxS32 errorCode = srv_brw_bkm_initialize_bookmark_context();
        if(errorCode == 0)
        {
            if(g_srv_brw_cntx.bookmark_count == 0)
            {
                VappBrowserUtility::displayPopup(STR_GLOBAL_EMPTY, MMI_NMGR_BALLOON_TYPE_FAILURE, MMI_EVENT_INFO_BALLOON);
                errorCode = 1;
            }
        }
        if(errorCode != 0)
        {
            if(errorCode < 0)
            {
                VappBrowserUtility::fileSystemErrorHandler(errorCode);
            }
            if(m_is_asm_initialized)
            {
                m_is_asm_initialized = VFX_FALSE;
                srv_brw_bkm_deinitialize_bookmark_context();
                if (g_srv_brw_cntx.brw_adm_id)
                {
                    kal_adm_delete(g_srv_brw_cntx.brw_adm_id);
                    g_srv_brw_cntx.brw_adm_id = NULL;
                }
				mmi_frm_asm_free_r(VCUI_BKM, g_srv_brw_memory_pool);
                g_srv_brw_memory_pool = NULL;
            }
        }
		#endif
    VfxAppLauncher::runCui(cui_id);
}

/* Close CUI */
void  vcui_bkm_sel_bkm_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
    if(m_is_asm_initialized == VFX_TRUE)
    {
        m_is_asm_initialized = VFX_FALSE;
        srv_brw_bkm_deinitialize_bookmark_context();
        if (g_srv_brw_cntx.brw_adm_id)
        {
            kal_adm_delete(g_srv_brw_cntx.brw_adm_id);
            g_srv_brw_cntx.brw_adm_id = NULL;
        }
        mmi_frm_asm_free_r(VCUI_BKM, g_srv_brw_memory_pool);
        g_srv_brw_memory_pool = NULL;
    }
}

mmi_id vcui_bkm_add_bkm_create(mmi_id parent_id)
{
    if(parent_id != GRP_ID_INVALID)
    {
        if(m_bowserBookmarkCuiId != GRP_ID_INVALID)
        {
            VappBrowserUtility::displayPopup(STR_GLOBAL_NOT_AVAILABLE, MMI_NMGR_BALLOON_TYPE_FAILURE, MMI_EVENT_INFO_BALLOON);
            return GRP_ID_INVALID;
        }
        vapp_brw_bookmark_launch_args args;
        args.isBookmarkAddMode = VFX_TRUE;
        m_bowserBookmarkCuiId = VfxAppLauncher::createCui(
                                                                VCUI_BKM,
                                                                VFX_OBJ_CLASS_INFO(VappBrwBookmarkCui),
                                                                parent_id,
                                                                &args,
                                                                sizeof(vapp_brw_bookmark_launch_args));
        return m_bowserBookmarkCuiId;
    }
    else
    {
        return GRP_ID_INVALID;
    }



}

/* Execute CUI*/
void vcui_bkm_add_bkm_run(mmi_id cui_id, const U8* url)
{
	#if 1
        if (!g_srv_brw_memory_pool)
        {
		g_srv_brw_memory_pool = mmi_frm_asm_alloc_nc_r(VCUI_BKM, SRV_BRW_BOOKMARK_POOL_SIZE);
            if (!g_srv_brw_memory_pool)
            {
                VappBrowserUtility::displayPopup(STR_GLOBAL_NOT_AVAILABLE, MMI_NMGR_BALLOON_TYPE_FAILURE, MMI_EVENT_INFO_BALLOON);
            }
            m_is_asm_initialized = VFX_TRUE;
            g_srv_brw_cntx.brw_adm_id = kal_adm_create(
                                        (char*)g_srv_brw_memory_pool,
                                    SRV_BRW_BOOKMARK_POOL_SIZE,
                                        NULL,
                                        KAL_FALSE);
            MMI_ASSERT(g_srv_brw_cntx.brw_adm_id);
        }
        VfxS32 errorCode = srv_brw_bkm_initialize_bookmark_context();
        if(errorCode == 0)
        {
            if(VappBrowserUtility::checkAvailableBookmarkMemory() == VFX_FALSE)
            {
                errorCode = 1;
            }
        }
        if(errorCode != 0)
        {
            if(errorCode < 0)
            {
                VappBrowserUtility::fileSystemErrorHandler(errorCode);
            }
            if(m_is_asm_initialized)
            {
                m_is_asm_initialized = VFX_FALSE;
                srv_brw_bkm_deinitialize_bookmark_context();
                if (g_srv_brw_cntx.brw_adm_id)
                {
                    kal_adm_delete(g_srv_brw_cntx.brw_adm_id);
                    g_srv_brw_cntx.brw_adm_id = NULL;
                }
            mmi_frm_asm_free_r(VCUI_BKM, g_srv_brw_memory_pool);
                g_srv_brw_memory_pool = NULL;
            }
        }
	#endif

    VappBrwBookmarkCui *bookmarkCui = ((VappBrwBookmarkCui *)VfxAppLauncher::getObject(m_bowserBookmarkCuiId));
    VFX_ALLOC_MEM(bookmarkCui->m_addBookmarkUrl, (SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH, bookmarkCui);
    mmi_chset_utf8_to_ucs2_string(
        (U8*) bookmarkCui->m_addBookmarkUrl,
        (SRV_BRW_MAX_URL_LEN + 1) * ENCODING_LENGTH,
        (U8*) url);
    VfxAppLauncher::runCui(cui_id);
    VFX_FREE_MEM(bookmarkCui->m_addBookmarkUrl);
}

/* Close CUI */
void  vcui_bkm_add_bkm_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
    if(m_is_asm_initialized == VFX_TRUE)
    {
        m_is_asm_initialized = VFX_FALSE;
        srv_brw_bkm_deinitialize_bookmark_context();
        if (g_srv_brw_cntx.brw_adm_id)
        {
            kal_adm_delete(g_srv_brw_cntx.brw_adm_id);
            g_srv_brw_cntx.brw_adm_id = NULL;
        }
        mmi_frm_asm_free_r(VCUI_BKM, g_srv_brw_memory_pool);
        g_srv_brw_memory_pool = NULL;
    }
}

#ifdef __cplusplus
}
#endif /* __cplusplus */

//VFX_IMPLEMENT_CLASS("VappBrwBookmarkScr", VappBrwBookmarkScr, VfxMainScr);

void VappBrwBookmarkScr::onDeinit(void)
{
}

void VappBrwBookmarkScr::on1stReady(void)
{
    if(getMode() == CUI_MODE_ADD_BOOKMARK)
    {
        VfxWString title;
        VFX_OBJ_CREATE_EX(m_addBookmarkPage,VappBrowserAddBookmark,this, 
            (title, m_addBookmarkUrl, VappBrowserAddBookmark::BOOKMARK_MODE_ADD_TO));
        pushPage(0, m_addBookmarkPage);
    }
    else
    {
        VFX_OBJ_CREATE(m_selectBookmarkPage,VappBrowserSelectBookmark,this);
        pushPage(0, m_selectBookmarkPage);
    }
}


VFX_IMPLEMENT_CLASS("VappBrwBookmarkCui", VappBrwBookmarkCui, VfxCui);

void VappBrwBookmarkCui::onRun(void *arg, VfxU32 argSize)
{
    VfxCui::onRun(arg, argSize);
    vapp_brw_bookmark_launch_args *args = (vapp_brw_bookmark_launch_args*)arg;
    VFX_OBJ_CREATE_EX(m_bookmarkScr, VappBrwBookmarkScr, this, (m_addBookmarkUrl));
    if(args->isBookmarkAddMode)
    {
        m_bookmarkScr->setMode(VappBrwBookmarkScr::CUI_MODE_ADD_BOOKMARK);
    }
    else
    {
        m_bookmarkScr->setMode(VappBrwBookmarkScr::CUI_MODE_SELECT_BOOKMARK);
    }
    m_bookmarkScr->show();
}

mmi_ret VappBrwBookmarkCui::onProc(mmi_event_struct * evt)
{
    if(evt->evt_id == EVT_ID_GROUP_EXIT)
    {
        VappBrwBookmarkCui *bookmarkCuiInstance;
        bookmarkCuiInstance = (VappBrwBookmarkCui *)VfxApp::getObject(m_bowserBookmarkCuiId); // get cui instance
        vcui_bkm_sel_bkm_result_evt_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_VCUI_BKM_ADD_BKM_CLOSE);
        evt.sender_id = m_bowserBookmarkCuiId;
        bookmarkCuiInstance->sendToCaller((mmi_group_event_struct*)&evt);
    }
    return 0;
}

void VappBrwBookmarkCui::onDeinit(void)
{
    m_bowserBookmarkCuiId = GRP_ID_INVALID;
}


// SelectBookmarkPage
void VappBrowserSelectBookmark::onInit(void)
{
    VfxPage::onInit();

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_BRW_BOOKMARKS));
    setTopBar(m_titleBar); 

    VFX_OBJ_CREATE(m_bookmarksList, VcpListMenu, this);
    VFX_OBJ_CREATE(m_bookmarksContentProvider, VappBrowserBookmarksDataProvider, this);
    m_bookmarksContentProvider->initialize();
    m_bookmarksList->setContentProvider(m_bookmarksContentProvider);
    m_bookmarksContentProvider->setNormalMode(); 
    m_bookmarksContentProvider->updateCustomControlStatus(VFX_FALSE);
    m_bookmarksList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
    m_bookmarksList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE, VFX_FALSE);
    m_bookmarksList->m_signalItemTapped.connect(this, &VappBrowserSelectBookmark::onItemTap);
    VfxRect page_rect = getRect();
    m_bookmarksList->setRect(0, 0, page_rect.size.width, page_rect.size.height);
    m_bookmarksList->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

}

void VappBrowserSelectBookmark::onItemTap(VcpListMenu *sender, VfxU32 index)
{    
	#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
	srv_brw_bkm_types_enum file_type = g_srv_brw_cntx.bkm_cntx_p[m_bookmarksContentProvider->m_bookmarksContext->m_bookmarkList[index].actual_index].type;
    if(file_type == SRV_BRW_BKM_TYPE_FOLDER)
    {
        VfxWString itemText;
        m_bookmarksList->getItemTextIfPresent(index, VCP_LIST_MENU_FIELD_TEXT, itemText);
        mmi_ucs2cpy((CHAR*)m_bookmarksContentProvider->m_bookmarksContext->m_selFolderName, (const CHAR*)itemText.getBuf());
        m_bookmarksContentProvider->m_bookmarksContext->updateFileCount();
        m_bookmarksList->resetAllItems();
    }
    else
	#endif
    {
        VfxU8 actualIndex = m_bookmarksContentProvider->m_bookmarksContext->m_bookmarkList[index].actual_index;
        VfxWChar *bookmarkUrl;
        VappBrwBookmarkCui *bookmarkCui = ((VappBrwBookmarkCui *)VfxAppLauncher::getObject(m_bowserBookmarkCuiId));
        VFX_ALLOC_MEM(bookmarkUrl, (SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH, bookmarkCui);

        memset(bookmarkUrl, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
        mmi_asc_to_ucs2((CHAR*) bookmarkUrl, (CHAR*) g_srv_brw_cntx.bkm_cntx_p[actualIndex].url);

        VfxWChar *bookmarkTitle;
        VFX_ALLOC_MEM(bookmarkTitle, (SRV_BRW_MAX_TITLE_LENGTH + 1) *ENCODING_LENGTH, bookmarkCui);
        mmi_chset_utf8_to_ucs2_string((kal_uint8*) bookmarkTitle, 
            SRV_BRW_MAX_TITLE_LENGTH * ENCODING_LENGTH,
            (kal_uint8*) g_srv_brw_cntx.bkm_cntx_p[actualIndex].title);

        VappBrwBookmarkCui *bookmarkCuiInstance;
        bookmarkCuiInstance = (VappBrwBookmarkCui *)VfxApp::getObject(m_bowserBookmarkCuiId); // get cui instance
        vcui_bkm_sel_bkm_result_evt_struct evt;

        MMI_FRM_INIT_EVENT(&evt, EVT_ID_VCUI_BKM_SEL_BKM_RESULT);
        evt.sender_id = m_bowserBookmarkCuiId;
        U8 url_buff[SRV_BRW_MAX_URL_LENGTH + 1];
        U8 title_buff[SRV_BRW_MAX_TITLE_LENGTH + 1];
        mmi_chset_ucs2_to_utf8_string((U8*) url_buff, SRV_BRW_MAX_URL_LENGTH + 1, (U8*) bookmarkUrl);
        mmi_chset_ucs2_to_utf8_string((U8*) title_buff, SRV_BRW_MAX_TITLE_LENGTH + 1, (U8*) bookmarkTitle);
        evt.selected_utf8_url = url_buff;
        evt.selected_utf8_title = title_buff;
        VFX_FREE_MEM(bookmarkUrl);
        VFX_FREE_MEM(bookmarkTitle);
        bookmarkCuiInstance->sendToCaller((mmi_group_event_struct*)&evt);
    }
}

void VappBrowserSelectBookmark::moveToParentFolder(void)
{
    memset(m_bookmarksContentProvider->m_bookmarksContext->m_selFolderName, 0, (SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
    m_bookmarksContentProvider->m_bookmarksContext->updateFileCount();
    m_bookmarksList->resetAllItems();
}

void VappBrowserSelectBookmark::onQueryRotateEx(VfxScreenRotateParam & param)
{
	if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90) 
	{
				
	}
    else
	{
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
	}
}


void VappBrowserSelectBookmark::onBack(void)
{
    if(!m_bookmarksContentProvider->isRootFolderSelected())
    {
        moveToParentFolder();
    }
    else
    {
        VfxPage::onBack();
    }
}

void VappBrowserSelectBookmark::onDeinit(void)
{
    VFX_OBJ_CLOSE(m_titleBar);
    VFX_OBJ_CLOSE(m_bookmarksList);
    m_bookmarksContentProvider->deinitialize();
    VFX_OBJ_CLOSE(m_bookmarksContentProvider);
    VfxPage::onDeinit(); 
}
#endif /* __MMI_BROWSER_2__ */

#endif /* _VAPP_BRW_BOOKMARK_CUI_CPP_ */
