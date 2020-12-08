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
 *  vcui_bookmark_opera.cpp
 *
 * Project:
 * -------- 
 *  Bookmark CUI
 *
 * Description:
 * ------------
 *  This file contains bookmark CUI for Opera browser solution.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if (defined(__COSMOS_MMI_PACKAGE__) && defined(OPERA_BROWSER))

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMIDataType.h"
#include "vcui_bookmark_opera.h"

// Resource
#include "GlobalResDef.h"
#include "vapp_package_res.h"
#include "mmi_rp_vcui_bkm_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"

// Opera bookmark APIs
#include "OpDevBookmark.h"
#include "opera_api.h"

// Framework header
#include "mmi_frm_scenario_gprot.h"
#include "vfx_datatype.h"
#include "vfx_object.h"
#include "vfx_app_launcher.h"
#include "vfx_string.h"
#include "vfx_text_frame.h"

// Venus CP header
#include "vcp_include.h"
#include "vcp_navi_title_bar.h"
#include "vcp_tool_bar.h"
#include "vcp_form.h"
#include "vcp_list_menu.h"
#include "vcp_popup.h"

// Service APIs
#include "NotificationGprot.h"

extern "C"
{
// Utilities
#include "Conversions.h"
#include "ImeGprot.h"

extern int mmi_charset_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
}

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

static void vcui_bkm_opera_bookmark_changed_cb(void);
static void vcui_bkm_add_bookmark_result_cb(int result);
 
/***************************************************************************** 
 * Local Function
 *****************************************************************************/

void vcui_bkm_opera_bookmark_changed_cb(void)
{
}

void vcui_bkm_add_bookmark_result_cb(int result)
{
    VcuiAddBookmarkPage *cuiObject = reinterpret_cast<VcuiAddBookmarkPage*>(VcuiAddBookmarkPage::getAddBkmUserData());

    cuiObject->addBkmResultHandler(result);
}

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

extern "C"
{
#define SELECT_BOOKMARK_GLOBAL_FUNCTION

mmi_id vcui_bkm_sel_bkm_create(mmi_id parent_gid)
{
    mmi_id cui_id = VfxAppLauncher::createCui(VCUI_BKM,
                                              VFX_OBJ_CLASS_INFO(VcuiSelectBookmarkCui),
                                              parent_gid,
                                              NULL,
                                              0);
    return cui_id;
}

void vcui_bkm_sel_bkm_run(mmi_id cui_gid)
{
    VfxAppLauncher::runCui(cui_gid);
}

void vcui_bkm_sel_bkm_close(mmi_id cui_gid)
{
    VfxAppLauncher::terminate(cui_gid);
}

#define ADD_BOOKMARK_GLOBAL_FUNCTION

mmi_id vcui_bkm_add_bkm_create(mmi_id parent_gid)
{
    mmi_id cui_id = VfxAppLauncher::createCui(VCUI_BKM,
                                              VFX_OBJ_CLASS_INFO(VcuiAddBookmarkCui),
                                              parent_gid,
                                              NULL,
                                              0);
    return cui_id;
}

void vcui_bkm_add_bkm_run(mmi_id cui_gid, const U8 *added_utf8_url)
{
    VcuiAddBookmarkCui *addBkmCui = (VFX_OBJ_DYNAMIC_CAST(VfxAppLauncher::getObject(cui_gid), VcuiAddBookmarkCui));
    addBkmCui->setAddedUrlByUtf8(added_utf8_url);
    VfxAppLauncher::runCui(cui_gid);
}

void vcui_bkm_add_bkm_close(mmi_id cui_gid)
{
    VfxAppLauncher::terminate(cui_gid);
}

// TODO: Remove
#define DUMMY_FUNCTION_FOR_OLD_PLUTOMMI_INTERFACE

mmi_id cui_bkm_sel_bkm_create(mmi_id parent_gid)
{
    return vcui_bkm_sel_bkm_create(parent_gid);
//    return GRP_ID_INVALID;
}

void cui_bkm_sel_bkm_run(mmi_id cui_gid)
{
    vcui_bkm_sel_bkm_run(cui_gid);
//    return;
}

void cui_bkm_sel_bkm_close(mmi_id cui_gid)
{
    vcui_bkm_sel_bkm_close(cui_gid);
//    return;
}

mmi_id cui_bkm_add_bkm_create(mmi_id parent_gid)
{
    return vcui_bkm_add_bkm_create(parent_gid);
//    return GRP_ID_INVALID;
}

void cui_bkm_add_bkm_run(mmi_id cui_gid, const U8 *added_utf8_url)
{
    vcui_bkm_add_bkm_run(cui_gid, added_utf8_url);
//    return;
}

void cui_bkm_add_bkm_close(mmi_id cui_gid)
{
    vcui_bkm_add_bkm_close(cui_gid);
//    return;
}
}

/***************************************************************************** 
 * Class VcuiSelectBookmarkCui
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiSelectBookmarkCui", VcuiSelectBookmarkCui, VfxCui);

void VcuiSelectBookmarkCui::onRun(void *args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    // Create and display main screen
    VcuiSelectBookmarkMainScr *mainScr;
    VFX_OBJ_CREATE(mainScr, VcuiSelectBookmarkMainScr, this);
    mainScr->show();
}

/***************************************************************************** 
 * Class VcuiSelectBookmarkMainScr
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiSelectBookmarkMainScr", VcuiSelectBookmarkMainScr, VfxMainScr);

void VcuiSelectBookmarkMainScr::on1stReady()
{
    VfxMainScr::on1stReady();

    // Create and display first page
    VcuiSelectBookmarkPage *page;
    VFX_OBJ_CREATE(page, VcuiSelectBookmarkPage, this);
    pushPage(VFX_ID_NULL, page);
}

/***************************************************************************** 
 * Class VcuiSelectBookmarkPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiSelectBookmarkPage", VcuiSelectBookmarkPage, VfxPage);

VcuiSelectBookmarkPage::VcuiSelectBookmarkPage():
    m_selectTitle(NULL),
    m_selectUrl(NULL),
    m_bookmarkListMenu(NULL)
{
}

void VcuiSelectBookmarkPage::onInit()
{
    VfxPage::onInit();

    // Initiate Opera bookmark service and get bookmark list within root folder
    if (OperaApi_BookmarkInit(vcui_bkm_opera_bookmark_changed_cb) == OPERA_API_OK &&
        OperaApi_GetBookmarkListWithinFolder(OPERA_BOOKMARK_ROOT_FOLDER_ID,
                                             OPERA_BOOKMARK_LIST_ALL,
                                             &m_currentFolderBookmarkList) == OPERA_API_OK)
    {
        // Create title bar
        VcpTitleBar *titleBar;
        VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
        titleBar->setTitle(VFX_WSTR_RES(STR_GLOBAL_BOOKMARKS));
        setTopBar(titleBar);
        
        // Create tool bar
        VcpToolBar *toolBar;
        VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
        toolBar->addItem(TOOL_BAR_ID_CANCEL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        toolBar->m_signalButtonTap.connect(this, &VcuiSelectBookmarkPage::onToolBarTap);
        setBottomBar(toolBar);
        
        // Create bookmark list menu
        VFX_OBJ_CREATE(m_bookmarkListMenu, VcpListMenu, this);
        m_bookmarkListMenu->setSize(getSize());
        m_bookmarkListMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                           VFX_FRAME_ALIGNER_MODE_SIDE,
                                           VFX_FRAME_ALIGNER_MODE_SIDE,
                                           VFX_FRAME_ALIGNER_MODE_SIDE);
        m_bookmarkListMenu->setContentProvider(this);
        m_bookmarkListMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
        m_bookmarkListMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE);
        m_bookmarkListMenu->m_signalItemTapped.connect(this, &VcuiSelectBookmarkPage::onListMenuItemTap);
    }
    else
    {
        postResultToCaller();
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE).getBuf());
    }
}

void VcuiSelectBookmarkPage::onDeinit()
{
    OperaApi_BookmarkExit(vcui_bkm_opera_bookmark_changed_cb);
    
    VfxPage::onDeinit();
}

void VcuiSelectBookmarkPage::onBack()
{
    if (m_currentFolderBookmarkList.this_folder_id == OPERA_BOOKMARK_ROOT_FOLDER_ID)
    {
        postResultToCaller();
    }
    else
    {
        // Go back to parent level bookmark folder
        if (OperaApi_GetBookmarkListWithinFolder(m_currentFolderBookmarkList.parent_folder_id,
                                                 OPERA_BOOKMARK_LIST_ALL,
                                                 &m_currentFolderBookmarkList) == OPERA_API_OK)
        {
            m_bookmarkListMenu->resetAllItems();
            return;
        }
    }
}

VfxScrRotateTypeEnum VcuiSelectBookmarkPage::onQueryRotateEx(const VfxScreenRotateParam &param)
{
    return param.rotateTo;
}

VfxBool VcuiSelectBookmarkPage::getItemText(VfxU32 index,
                                            VcpListMenuFieldEnum fieldType,
                                            VfxWString &text,
                                            VcpListMenuTextColorEnum &color)
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        VfxS32 itemId;
        Opera_BookmarkItemType itemType;
        
        if (OperaApi_GetBookmarkItemIdAndTypeByIndex(m_currentFolderBookmarkList.this_folder_id,
                                                     index,
                                                     &itemId,
                                                     &itemType) == OPERA_API_OK)
        {
            VfxU8 *itemNameUtf8;
            VfxU8 *itemNameUcs2;
            VfxU32 textLength;
            
            if (itemType == OPERA_BOOKMARK_ITEM_TYPE_FOLDER)
            {
                if (OperaApi_GetFolderNameById(itemId, &itemNameUtf8) == OPERA_API_OK)
                {
                    textLength = mmi_chset_utf8_strlen(itemNameUtf8);
                    itemNameUcs2 = reinterpret_cast<VfxU8*>(text.lockBuf(textLength + 1));
                    mmi_chset_utf8_to_ucs2_string(itemNameUcs2, (textLength+1) * ENCODING_LENGTH, itemNameUtf8);
                    text.unlockBuf();
                    
                    return VFX_TRUE;
                }
            }
            else if (itemType == OPERA_BOOKMARK_ITEM_TYPE_BOOKMARK)
            {
                if (OperaApi_GetBookmarkTitleById(itemId, &itemNameUtf8) == OPERA_API_OK)
                {
                    textLength = mmi_chset_utf8_strlen(itemNameUtf8);
                    itemNameUcs2 = reinterpret_cast<VfxU8*>(text.lockBuf(textLength + 1));
                    mmi_chset_utf8_to_ucs2_string(itemNameUcs2, (textLength+1) * ENCODING_LENGTH, itemNameUtf8);
                    text.unlockBuf();
                    
                    return VFX_TRUE;
                }
            }
        }
        
        VFX_ASSERT(0);
    }
    
    return VFX_FALSE;
}

VfxBool VcuiSelectBookmarkPage::getItemImage(VfxU32 index,
                                             VcpListMenuFieldEnum fieldType,
                                             VfxImageSrc &image)
{
    VfxS32 itemId;
    Opera_BookmarkItemType itemType;
    
    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
        if (OperaApi_GetBookmarkItemIdAndTypeByIndex(m_currentFolderBookmarkList.this_folder_id,
                                                     index,
                                                     &itemId,
                                                     &itemType) == OPERA_API_OK)
        {
            if (itemType == OPERA_BOOKMARK_ITEM_TYPE_FOLDER)
            {
                image.setResId(IMG_ID_VCUI_BKM_OPERA_FOLDER_ICON);
                
                return VFX_TRUE;
            }
            else if (itemType == OPERA_BOOKMARK_ITEM_TYPE_BOOKMARK)
            {
                image.setResId(IMG_ID_VCUI_BKM_OPERA_DEFAULT_FAVICON);
                
                return VFX_TRUE;
            }
        }
        
        VFX_ASSERT(0);
    }
    else if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
    {
        if (OperaApi_GetBookmarkItemIdAndTypeByIndex(m_currentFolderBookmarkList.this_folder_id,
                                                     index,
                                                     &itemId,
                                                     &itemType) == OPERA_API_OK)
        {
            if (itemType == OPERA_BOOKMARK_ITEM_TYPE_FOLDER)
            {
                image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
                
                return VFX_TRUE;
            }
            else if (itemType == OPERA_BOOKMARK_ITEM_TYPE_BOOKMARK)
            {
                return VFX_TRUE;
            }
        }
        
        VFX_ASSERT(0);
    }
    
    return VFX_FALSE;
}

VfxBool VcuiSelectBookmarkPage::getMenuEmptyText(VfxWString &text,
                                                 VcpListMenuTextColorEnum &color)
{
    text.loadFromRes(STR_ID_VCUI_BKM_OPERA_NO_BOOKMARKS);
    
    return VFX_TRUE;
}

VfxU32 VcuiSelectBookmarkPage::getCount() const
{
    return m_currentFolderBookmarkList.num_of_items;
}

void VcuiSelectBookmarkPage::onToolBarTap(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case TOOL_BAR_ID_CANCEL:
            postResultToCaller();
            break;
            
        default:
            break;
    }
}

void VcuiSelectBookmarkPage::onListMenuItemTap(VcpListMenu *sender, VfxU32 index)
{
    VfxS32 itemId;
    Opera_BookmarkItemType itemType;
    
    if (OperaApi_GetBookmarkItemIdAndTypeByIndex(m_currentFolderBookmarkList.this_folder_id,
                                                 index,
                                                 &itemId,
                                                 &itemType) == OPERA_API_OK)
    {
        if (itemType == OPERA_BOOKMARK_ITEM_TYPE_FOLDER)
        {
            // Go to child level bookmark folder
            if (OperaApi_GetBookmarkListWithinFolder(itemId,
                                                     OPERA_BOOKMARK_LIST_ALL,
                                                     &m_currentFolderBookmarkList) == OPERA_API_OK)
            {
                sender->resetAllItems();
                return;
            }
        }
        else if (itemType == OPERA_BOOKMARK_ITEM_TYPE_BOOKMARK)
        {
            // Select bookmark done, post result to caller application
            if (OperaApi_GetBookmarkTitleById(itemId, &m_selectTitle) == OPERA_API_OK &&
                OperaApi_GetBookmarkUrlById(itemId, &m_selectUrl) == OPERA_API_OK)
            {
                postResultToCaller();
                return;
            }
        }
    }
    
    VFX_ASSERT(0);
}

void VcuiSelectBookmarkPage::postResultToCaller()
{
    vcui_bkm_sel_bkm_result_evt_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_BKM_SEL_BKM_RESULT, getApp()->getGroupId());
    
    evt.selected_utf8_title = m_selectTitle;
    evt.selected_utf8_url = m_selectUrl;
    
    VfxCui *selbkmCui = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
    selbkmCui->postToCaller((mmi_group_event_struct*)&evt);
}

/***************************************************************************** 
 * Class VcuiAddBookmarkCui
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiAddBookmarkCui", VcuiAddBookmarkCui, VfxCui);

void VcuiAddBookmarkCui::setAddedUrlByUtf8(const VfxU8 *addedUrlUtf8)
{
    VfxU8 *addedUrlUcs2;
    VfxU32 urlLength;
    
    urlLength = mmi_chset_utf8_strlen(addedUrlUtf8);
    addedUrlUcs2 = reinterpret_cast<VfxU8*>(m_addedUrl.lockBuf(urlLength + 1));
    mmi_chset_utf8_to_ucs2_string(addedUrlUcs2, (urlLength+1) * ENCODING_LENGTH, (VfxU8*)addedUrlUtf8);
    m_addedUrl.unlockBuf();
}

VfxWString &VcuiAddBookmarkCui::getAddedUrl(void)
{
    return m_addedUrl;
}

void VcuiAddBookmarkCui::onRun(void *args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    // Create and display main screen
    VcuiAddBookmarkMainScr *mainScr;
    VFX_OBJ_CREATE(mainScr, VcuiAddBookmarkMainScr, this);
    mainScr->show();
}

/***************************************************************************** 
 * Class VcuiAddBookmarkMainScr
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiAddBookmarkMainScr", VcuiAddBookmarkMainScr, VfxMainScr);

void VcuiAddBookmarkMainScr::on1stReady()
{
    VfxMainScr::on1stReady();

    // Create and display first page
    VcuiAddBookmarkPage *page;
    VFX_OBJ_CREATE(page, VcuiAddBookmarkPage, this);
    pushPage(VFX_ID_NULL, page);
}

/***************************************************************************** 
 * Class VcuiAddBookmarkPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiAddBookmarkPage", VcuiAddBookmarkPage, VfxPage);

void *VcuiAddBookmarkPage::m_addBkmUserData = NULL;

VcuiAddBookmarkPage::VcuiAddBookmarkPage():
    m_addBkmForm(NULL),
    m_addBkmIndicatorPopup(NULL),
    m_selectFolderId(OPERA_BOOKMARK_ROOT_FOLDER_ID)
{
}

void *VcuiAddBookmarkPage::getAddBkmUserData()
{
    return m_addBkmUserData;
}

void VcuiAddBookmarkPage::setAddBkmUserData(void *userData)
{
    m_addBkmUserData = userData;
}

void VcuiAddBookmarkPage::setSelectFolderId(VfxS32 selectFolderId)
{
    m_selectFolderId = selectFolderId;
}

VfxS32 VcuiAddBookmarkPage::getSelectFolderId()
{
    return m_selectFolderId;
}

void VcuiAddBookmarkPage::addBkmResultHandler(VfxS32 result)
{
    // Delete indicator popup
    if (m_addBkmIndicatorPopup)
    {
        m_addBkmIndicatorPopup->hide(VFX_TRUE);
        VFX_OBJ_CLOSE(m_addBkmIndicatorPopup);
        
        switch (result)
        {
            case OPERA_ADD_BOOKMARK_SUCCESS:
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_SUCCESS,
                    (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_SAVED).getBuf());
                postResultToCaller();
                break;
                
            case OPERA_ADD_BOOKMARK_INVALID_URL:
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_INVALID_URL).getBuf());
                break;
                
            case OPERA_ADD_BOOKMARK_INVALID_TITLE:
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_INVALID_INPUT).getBuf());
                break;
                
            case OPERA_ADD_BOOKMARK_FILE_SYSTEM_ERROR:
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_FAILED_TO_SAVE).getBuf());
                postResultToCaller();
                break;
                
            case OPERA_ADD_BOOKMARK_FULL:
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL).getBuf());
                postResultToCaller();
                break;
                
            case OPERA_ADD_BOOKMARK_CANCELED:
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_FAILED_TO_SAVE).getBuf());
                postResultToCaller();
                break;
                
            case OPERA_ADD_BOOKMARK_ERROR:
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_FAILED_TO_SAVE).getBuf());
                postResultToCaller();
                break;
                
            default:
                mmi_frm_nmgr_balloon(
                    MMI_SCENARIO_ID_DEFAULT,
                    MMI_EVENT_INFO_BALLOON,
                    MMI_NMGR_BALLOON_TYPE_FAILURE,
                    (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_FAILED_TO_SAVE).getBuf());
                postResultToCaller();
                break;
        }
    }
}

void VcuiAddBookmarkPage::onInit()
{
    VfxPage::onInit();

    // Initiate Opera bookmark service and get bookmark list within root folder
    if (OperaApi_BookmarkInit(vcui_bkm_opera_bookmark_changed_cb) == OPERA_API_OK)
    {
        // Create title bar
        VcpTitleBar *titleBar;
        VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
        titleBar->setTitle(VFX_WSTR_RES(STR_ID_VCUI_BKM_OPERA_ADD_BOOKMARK));
        setTopBar(titleBar);
        
        // Create tool bar
        VcpToolBar *toolBar;
        VFX_OBJ_CREATE(toolBar, VcpToolBar, this);
        toolBar->addItem(TOOL_BAR_ID_SAVE, VFX_WSTR_RES(VCP_STR_TOOL_BAR_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
        toolBar->addItem(TOOL_BAR_ID_CANCEL, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        toolBar->m_signalButtonTap.connect(this, &VcuiAddBookmarkPage::onToolBarTap);
        setBottomBar(toolBar);
        
        // Create add bookmark form
        VFX_OBJ_CREATE(m_addBkmForm, VcpForm, this);
        m_addBkmForm->setSize(getSize());
        m_addBkmForm->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                        VFX_FRAME_ALIGNER_MODE_SIDE,
                                        VFX_FRAME_ALIGNER_MODE_SIDE,
                                        VFX_FRAME_ALIGNER_MODE_SIDE);
        m_addBkmForm->setBgColor(VFX_COLOR_WHITE);

        VcuiAddBookmarkCui *addBkmCui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiAddBookmarkCui);
        
        // Create caption for bookmark title
        m_addBkmForm->addCaption(VFX_WSTR_RES(STR_ID_VCUI_BKM_OPERA_NAME));
        
        // Create text input for bookmark title
        VcpFormItemTextInput *titleTextInput;
        VFX_OBJ_CREATE(titleTextInput, VcpFormItemTextInput, m_addBkmForm);
        titleTextInput->getTextBox()->setIME(IMM_INPUT_TYPE_SENTENCE);
        titleTextInput->getTextBox()->setText(addBkmCui->getAddedUrl(), VCUI_BKM_MAX_URL_LEN);
        m_addBkmForm->addItem(titleTextInput, FORM_ID_TITLE_TEXT_INPUT);
        
        // Create caption for bookmark URL
        m_addBkmForm->addCaption(VFX_WSTR_RES(STR_GLOBAL_URL));
        
        // Create text input for bookmark URL
        VcpFormItemTextInput *urlTextInput;
        VFX_OBJ_CREATE(urlTextInput, VcpFormItemTextInput, m_addBkmForm);
        urlTextInput->getTextBox()->setIME(IMM_INPUT_TYPE_URL);
        urlTextInput->getTextBox()->setText(addBkmCui->getAddedUrl(), VCUI_BKM_MAX_URL_LEN);
        m_addBkmForm->addItem(urlTextInput, FORM_ID_URL_TEXT_INPUT);
        
        // Create caption for select folder
        m_addBkmForm->addCaption(VFX_WSTR_RES(STR_ID_VCUI_BKM_OPERA_SELECT_FOLDER));
        
        // Create launcher cell for select folder
        VcpFormItemLauncherCell *selectFolderLauncherCell;
        VFX_OBJ_CREATE(selectFolderLauncherCell, VcpFormItemLauncherCell, m_addBkmForm);
        selectFolderLauncherCell->setMainText(VFX_WSTR_RES(STR_GLOBAL_BOOKMARKS));
        selectFolderLauncherCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
        selectFolderLauncherCell->m_signalTap.connect(this, &VcuiAddBookmarkPage::onSelectFolderLauncherCellTap);
        m_addBkmForm->addItem(selectFolderLauncherCell, FORM_ID_SELECT_FOLDER_LAUNCHER_CELL);
    }
    else
    {
        postResultToCaller();
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            (WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE).getBuf());
    }
}

void VcuiAddBookmarkPage::onDeinit()
{
    OperaApi_BookmarkExit(vcui_bkm_opera_bookmark_changed_cb);
    
    m_addBkmIndicatorPopup = NULL;
    
    VfxPage::onDeinit();
}

void VcuiAddBookmarkPage::onBack()
{
    postResultToCaller();
}

void VcuiAddBookmarkPage::onEnter(VfxBool isBackward)
{
    VcpFormItemLauncherCell *selectFolderLauncherCell;
    selectFolderLauncherCell = VFX_OBJ_DYNAMIC_CAST(m_addBkmForm->getItem(FORM_ID_SELECT_FOLDER_LAUNCHER_CELL),
                                                    VcpFormItemLauncherCell);
    
    if (m_selectFolderId == OPERA_BOOKMARK_ROOT_FOLDER_ID)
    {
        selectFolderLauncherCell->setMainText(VFX_WSTR_RES(STR_GLOBAL_BOOKMARKS));
    }
    else
    {
        VfxU8 *itemNameUtf8;
        VfxU8 *itemNameUcs2;
        VfxU32 textLength;
        VfxWString text;
        
        if (OperaApi_GetFolderNameById(m_selectFolderId, &itemNameUtf8) == OPERA_API_OK)
        {
            textLength = mmi_chset_utf8_strlen(itemNameUtf8);
            itemNameUcs2 = reinterpret_cast<VfxU8*>(text.lockBuf(textLength + 1));
            mmi_chset_utf8_to_ucs2_string(itemNameUcs2,
                                          (textLength+1) * ENCODING_LENGTH,
                                          itemNameUtf8);
            text.unlockBuf();
            selectFolderLauncherCell->setMainText(text);
        }
        else
        {
            VFX_ASSERT(0);
        }
    }
}

void VcuiAddBookmarkPage::onToolBarTap(VfxObject* obj, VfxId id)
{
    switch (id)
    {
        case TOOL_BAR_ID_SAVE:
            VfxU8 *titleUtf8;
            VfxU8 *urlUtf8;
            VfxS32 textUtf8Length;
            VcpFormItemTextInput *textInput;
            
            textInput = VFX_OBJ_DYNAMIC_CAST(m_addBkmForm->getItem(FORM_ID_TITLE_TEXT_INPUT), VcpFormItemTextInput);
            textUtf8Length = mmi_charset_ucs2_to_utf8_length_in_bytes(reinterpret_cast<VfxU8*>(textInput->getTextBox()->getText()));
            VFX_ALLOC_MEM(titleUtf8, textUtf8Length + 1, this);
            mmi_chset_ucs2_to_utf8_string(titleUtf8,
                                          textUtf8Length + 1,
                                          reinterpret_cast<VfxU8*>(textInput->getTextBox()->getText()));
            
            textInput = VFX_OBJ_DYNAMIC_CAST(m_addBkmForm->getItem(FORM_ID_URL_TEXT_INPUT), VcpFormItemTextInput);
            textUtf8Length = mmi_charset_ucs2_to_utf8_length_in_bytes(reinterpret_cast<VfxU8*>(textInput->getTextBox()->getText()));
            VFX_ALLOC_MEM(urlUtf8, textUtf8Length + 1, this);
            mmi_chset_ucs2_to_utf8_string(urlUtf8,
                                          textUtf8Length + 1,
                                          reinterpret_cast<VfxU8*>(textInput->getTextBox()->getText()));

            VfxS32 addBkmResult;
            setAddBkmUserData(this);
            addBkmResult = OperaApi_AddNewBookmark((char*)titleUtf8,
                                                   (char*)urlUtf8,
                                                   m_selectFolderId,
                                                   vcui_bkm_add_bookmark_result_cb);
            if (addBkmResult == OPERA_API_OK)
            {
                // Display indicator popup
                VFX_OBJ_CREATE(m_addBkmIndicatorPopup, VcpIndicatorPopup, this);
                m_addBkmIndicatorPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
                m_addBkmIndicatorPopup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
                m_addBkmIndicatorPopup->setAutoDestory(VFX_FALSE);
                m_addBkmIndicatorPopup->show(VFX_TRUE);
            }
            else
            {
                addBkmResultHandler(addBkmResult);
            }

            VFX_FREE_MEM(titleUtf8);
            VFX_FREE_MEM(urlUtf8);
            
            break;
            
        case TOOL_BAR_ID_CANCEL:
            postResultToCaller();
            break;
            
        default:
            break;
    }
}

void VcuiAddBookmarkPage::onSelectFolderLauncherCellTap(VcpFormItemCell *sender, VfxId id)
{
    // Create and display the page of select folder
    VcuiAddBookmarkMainScr *addBkmMainScr = VFX_OBJ_DYNAMIC_CAST(getMainScr(), VcuiAddBookmarkMainScr);
    VcuiSelectFolderPage *page;
    VFX_OBJ_CREATE(page, VcuiSelectFolderPage, addBkmMainScr);
    addBkmMainScr->pushPage(VFX_ID_NULL, page);
}

void VcuiAddBookmarkPage::postResultToCaller()
{
    vcui_bkm_add_bkm_result_evt_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_BKM_ADD_BKM_CLOSE, getApp()->getGroupId());
    
    VfxCui *addBkmCui = VFX_OBJ_DYNAMIC_CAST(getApp(), VfxCui);
    addBkmCui->postToCaller((mmi_group_event_struct*)&evt);
}

/***************************************************************************** 
 * Class VcuiSelectFolderTreeNode
 *****************************************************************************/

VcuiSelectFolderTreeNode::VcuiSelectFolderTreeNode():
    m_nodeId(OPERA_BOOKMARK_ROOT_FOLDER_ID),
    m_siblingNode(NULL),
    m_childNode(NULL)
{
}

/***************************************************************************** 
 * Class VcuiSelectFolderListNode
 *****************************************************************************/
 
VcuiSelectFolderListNode::VcuiSelectFolderListNode():
    m_nodeId(0),
    m_nodeLevel(0)
{
}

/***************************************************************************** 
 * Class VcuiSelectFolderListMenuCell
 *****************************************************************************/
 
VFX_IMPLEMENT_CLASS("VcuiSelectFolderListMenuCell", VcuiSelectFolderListMenuCell, VcpListMenuCellClientBaseFrame);

VcuiSelectFolderListMenuCell::VcuiSelectFolderListMenuCell():
    m_folderList(0),
    m_folderNameTextFrame(0),
    m_index(0)
{
}

void VcuiSelectFolderListMenuCell::onCreateElements()
{
    VFX_OBJ_CREATE(m_folderNameTextFrame, VfxTextFrame, this);
}

void VcuiSelectFolderListMenuCell::onCloseElements()
{
}

void VcuiSelectFolderListMenuCell::onLayoutElements()
{
    m_folderNameTextFrame->setRect(VfxRect(0, 
                                           getRect().getMidY() - m_folderNameTextFrame->getRect().getHeight() / 2,
                                           getRect().getWidth(),
                                           m_folderNameTextFrame->getRect().getHeight()));

    m_folderNameTextFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                          VFX_FRAME_ALIGNER_MODE_SIDE,
                                          VFX_FRAME_ALIGNER_MODE_SIDE,
                                          VFX_FRAME_ALIGNER_MODE_SIDE);
}

void VcuiSelectFolderListMenuCell::onUpdateElements()
{
    if (!m_folderList || !m_folderNameTextFrame)
    {
        return;
    }
    
    VfxWString text;
    if (m_index == 0 && m_folderList[m_index].m_nodeId == OPERA_BOOKMARK_ROOT_FOLDER_ID)
    {
        text = VFX_WSTR_RES(STR_GLOBAL_BOOKMARKS);
    }
    else
    {
        VfxU8 *itemNameUtf8;
        VfxU8 *itemNameUcs2;
        VfxU32 textLength;
        
        if (OperaApi_GetFolderNameById(m_folderList[m_index].m_nodeId, &itemNameUtf8) == OPERA_API_OK)
        {
            textLength = mmi_chset_utf8_strlen(itemNameUtf8);
            itemNameUcs2 = reinterpret_cast<VfxU8*>(text.lockBuf(textLength + 1));
            mmi_chset_utf8_to_ucs2_string(itemNameUcs2,
                                          (textLength+1) * ENCODING_LENGTH,
                                          itemNameUtf8);
            text.unlockBuf();
        }
        else
        {
            VFX_ASSERT(0);
        }
    }
    
    VfxS32 indentationLength = m_folderList[m_index].m_nodeLevel * FOLDER_INDENTATION_LENGTH;
    m_folderNameTextFrame->setString(text);
    m_folderNameTextFrame->setColor(VFX_COLOR_BLACK);
    m_folderNameTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_folderNameTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_folderNameTextFrame->setIndent(indentationLength);
}

/***************************************************************************** 
 * Class VcuiSelectFolderPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VcuiSelectFolderPage", VcuiSelectFolderPage, VfxPage);

VcuiSelectFolderPage::VcuiSelectFolderPage():
    m_totalNumOfFolder(0),
    m_folderTree(NULL),
    m_folderList(NULL),
    m_folderListMenu(NULL)
{
}

void VcuiSelectFolderPage::onInit()
{
    VfxPage::onInit();

    // Generate folder tree
    generateFolderTree();
    
    // Generate folder list
    generateFolderList();

    // Create title bar
    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VCUI_BKM_OPERA_SELECT_FOLDER));
    setTopBar(titleBar);
    
    // Create folder list menu
    VFX_OBJ_CREATE(m_folderListMenu, VcpListMenu, this);
    m_folderListMenu->setSize(getSize());
    m_folderListMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE,
                                     VFX_FRAME_ALIGNER_MODE_SIDE);
    m_folderListMenu->setContentProvider(this);
    m_folderListMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_folderListMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
    m_folderListMenu->m_signalItemTapped.connect(this, &VcuiSelectFolderPage::onListMenuItemTap);
}

void VcuiSelectFolderPage::onDeinit()
{
    // Delete folder tree
    deleteFolderTree(m_folderTree);
    
    // Delete folder list
    deleteFolderList();
    
    VfxPage::onDeinit();
}

void VcuiSelectFolderPage::onBack()
{
    VcuiAddBookmarkMainScr *addBkmMainScr = VFX_OBJ_DYNAMIC_CAST(getMainScr(), VcuiAddBookmarkMainScr);
    addBkmMainScr->popPage();
}

VfxU32 VcuiSelectFolderPage::getCount() const
{
    return m_totalNumOfFolder;
}

VcpListMenuItemStateEnum VcuiSelectFolderPage::getItemState(VfxU32 index) const
{
    VcuiAddBookmarkPage *addBkmPage = VFX_OBJ_DYNAMIC_CAST(getMainScr()->getPage(getMainScr()->getPrevPageId(getId())),
                                                           VcuiAddBookmarkPage);
    if (addBkmPage->getSelectFolderId() == m_folderList[index].m_nodeId)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

VcpListMenuCellClientBaseFrame *VcuiSelectFolderPage::getItemCustomContentFrame(
    VfxU32 index,
    VfxFrame *parentFrame
    )
{
    if (m_folderListMenu->getCellStyle() == VCP_LIST_MENU_CELL_STYLE_CUSTOM)
    {
        VcuiSelectFolderListMenuCell *selectFolderListMenuCell = NULL;

        VFX_OBJ_CREATE(selectFolderListMenuCell, VcuiSelectFolderListMenuCell, parentFrame);
        selectFolderListMenuCell->m_index = index;
        selectFolderListMenuCell->m_folderList = m_folderList;
        selectFolderListMenuCell->update(VFX_FALSE);

        return (VcpListMenuCellClientBaseFrame *)selectFolderListMenuCell;
    }
    else
    {
        return NULL;
    }
}

void VcuiSelectFolderPage::closeItemCustomContentFrame(
    VfxU32 index,
    VcpListMenuCellClientBaseFrame *cell
    )
{
    if (cell)
    {
        VFX_OBJ_CLOSE(cell);
    }
}

void VcuiSelectFolderPage::onListMenuItemTap(VcpListMenu *sender, VfxU32 index)
{
    VcuiAddBookmarkPage *addBkmPage = VFX_OBJ_DYNAMIC_CAST(getMainScr()->getPage(getMainScr()->getPrevPageId(getId())),
                                                           VcuiAddBookmarkPage);
    addBkmPage->setSelectFolderId(m_folderList[index].m_nodeId);
    back();
}

void VcuiSelectFolderPage::generateFolderTree()
{
    // Add root folder node
    VFX_ALLOC_NEW(m_folderTree, VcuiSelectFolderTreeNode, this);
    m_totalNumOfFolder = 1;

    // Add child folder node
    addFolderTreeNode(m_folderTree);
}

void VcuiSelectFolderPage::addFolderTreeNode(VcuiSelectFolderTreeNode *parentNode)
{
    opera_bookmark_list_t folderList;
    
    if (OperaApi_GetBookmarkListWithinFolder(parentNode->m_nodeId,
                                             OPERA_BOOKMARK_LIST_FOLDER_ONLY,
                                             &folderList) == OPERA_API_OK)
    {
        if (folderList.num_of_items > 0)
        {
            m_totalNumOfFolder += folderList.num_of_items;
            
            // Add child node
            VcuiSelectFolderTreeNode *newNode;
            VcuiSelectFolderTreeNode **iter = &(parentNode->m_childNode);
            for (VfxS32 i = 0; i < folderList.num_of_items; i++)
            {
                VFX_ALLOC_NEW(newNode, VcuiSelectFolderTreeNode, this);
                *iter = newNode;

                Opera_BookmarkItemType itemType;
                if (OperaApi_GetBookmarkItemIdAndTypeByIndex(parentNode->m_nodeId,
                                                             i,
                                                             &(newNode->m_nodeId),
                                                             &itemType) == OPERA_API_OK)
                {
                    addFolderTreeNode(newNode);
                    iter = &((*iter)->m_siblingNode);
                }
                else
                {
                    VFX_ASSERT(0);
                }
            }
        }
    }
    else
    {
        VFX_ASSERT(0);
    }
}

void VcuiSelectFolderPage::deleteFolderTree(VcuiSelectFolderTreeNode *node)
{
    if (node->m_childNode != NULL)
    {
        deleteFolderTree(node->m_childNode);
    }
    if (node->m_siblingNode != NULL)
    {
        deleteFolderTree(node->m_siblingNode);
    }
    VFX_FREE_MEM(node);
}

void VcuiSelectFolderPage::generateFolderList()
{
    VfxS32 nodeIndex = 0;
    VFX_ALLOC_MEM(m_folderList, sizeof(VcuiSelectFolderListNode) * m_totalNumOfFolder, this);
    addFolderListNode(m_folderTree, nodeIndex, 0);
}

void VcuiSelectFolderPage::addFolderListNode(VcuiSelectFolderTreeNode *node, VfxS32 &nodeIndex, VfxS32 nodeLevel)
{
    m_folderList[nodeIndex].m_nodeId = node->m_nodeId;
    m_folderList[nodeIndex].m_nodeLevel = nodeLevel;
    nodeIndex++;
    
    if (node->m_childNode != NULL)
    {
        nodeLevel++;
        addFolderListNode(node->m_childNode, nodeIndex, nodeLevel);
        nodeLevel--;
    }
    if (node->m_siblingNode != NULL)
    {
        addFolderListNode(node->m_siblingNode, nodeIndex, nodeLevel);
    }
}

void VcuiSelectFolderPage::deleteFolderList()
{
    VFX_FREE_MEM(m_folderList);
}

#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(OPERA_BROWSER) */

