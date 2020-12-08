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
 * VappBrowserMain.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VAPP_BRW_FAVOURITES_H_
#define _VAPP_BRW_FAVOURITES_H_

#include "MMI_include.h"
#include "MMIDataType.h"
#ifdef __MMI_BROWSER_2__
#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */
#include "BrowserSrvInterface.h"
#include "BrowserSrvBookmarks.h"
#include "BrowserSrvGprot.h"
#include "BrowserSrvMain.h"
#ifdef __cplusplus
}
#endif /* __cplusplus */

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_tabctrl_page.h"
#include "vcp_menu_popup.h"
#include "vapp_brw_main.h"
#include "mmi_rp_vapp_browser_def.h"
#include "vapp_fmgr_cp.h"
#include "vapp_brw_main.h"

#define BRW_DETAILS_TEXT_MAX_LENGTH   1000
#define FOLDER_INDENTATION_SIZE        25
/****************************************************************************
* Class VappBrowserBookmarks
****************************************************************************/
class VappBrowserBookmarksContext : public VfxObject
{
public:
    VfxWChar m_selFolderName[(SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH];
    VfxWString m_selFilePath;
    VfxWString m_selFileName;
    VfxWString m_selFileExtn;
    VfxWString m_selFileURL;
    VfxS32 m_selFileIndex;
    VfxU32 m_totalFileCount;
    srv_brw_bkm_bookmark_list_struct m_bookmarkList[SRV_BRW_BKM_MAX_COUNT];

    VappBrowserBookmarksContext(void):
        m_selFileIndex(-1),
        m_totalFileCount(0)
    {
    }

    void setTotalFileCount(VfxU32 count)
    {
        m_totalFileCount = count;
    }

    VfxU32 getTotalFileCount(void)
    {
        return (m_totalFileCount);
    }
    void updateFileCount(void);
    VfxU8 getFileCountByType(srv_brw_bkm_types_enum selType);
};


/****************************************************************************
* Class VappBrowserRecentPageDataProvider
****************************************************************************/
class VappBrowserRecentPageDataProvider : public VfxObject, public IVcpGroupListMenuContentProvider
{
private:
    VfxU8 m_todaysRecentPageCount;
    VfxU8 m_yesterdaysRecentPageCount;
    VfxU8 m_beforeYesterdaysRecentPageCount;
public:
    VfxU8 m_groupCount;
    VfxU8 m_actualGroup[3];
    enum
    {
        RECENT_PAGES_GROUP_TODAY = 0,
        RECENT_PAGES_GROUP_YESTERDAY,
        RECENT_PAGES_GROUP_DAY_BEFORE_YESTERDAY,
        RECENT_PAGES_GROUP_TOTAL,
    } ;


    virtual VfxBool getItemText(
        VcpMenuPos pos,                   // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
    {
        text.loadFromRes(STR_ID_VAPP_BRW_NO_BROWSING_HISTORY);
        return VFX_TRUE;
    }


    virtual VfxU32 getCount(VfxU32 group) const;
    virtual VfxU32 getGroupCount()const;
    
    void setTodaysCount(VfxU8 count)
    {
        m_todaysRecentPageCount = count;
    }

    VfxU8 getTodaysCount(void)
    {
        return (m_todaysRecentPageCount);
    }

    void setYesterdaysCount(VfxU8 count)
    {
        m_yesterdaysRecentPageCount = count;
    }

    VfxU8 getYesterdaysCount(void)
    {
        return (m_yesterdaysRecentPageCount);
    }

    void setBeforeYesterdaysCount(VfxU8 count)
    {
        m_beforeYesterdaysRecentPageCount = count;
    }

    VfxU8 getBeforeYesterdaysCount(void)
    {
        return (m_beforeYesterdaysRecentPageCount);
    }
    void updateGroupCount(void);
    VfxU32 getActualRecentPageIndex(VcpMenuPos &pos);
};

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
/****************************************************************************
* Class VappBrowserStoredPageDataProvider
****************************************************************************/
class VappBrowserStoredPageDataProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    VfxU8* m_selectedListInfo;
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    virtual VfxU32 getCount() const 
    {
        return ((VfxU32) srv_brw_get_stored_page_list_count());
    }

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
    {
        text.loadFromRes(STR_ID_VAPP_BRW_NO_SAVED_PAGES);
        return VFX_TRUE;
    }

};
#endif /* __MMI_BRW_STORED_PAGES_SUPPORT__ */


#ifdef __MMI_VBOOKMARK__
/****************************************************************************
* Class VappBrowserBookmarksDataProvider
****************************************************************************/
class VappBrowserBookmarksDataProvider : public VfxObject, public IVcpListMenuContentProvider
{
private:
    enum
    {
        LIST_MODE_NORMAL = 0,
        LIST_MODE_SELECTION,
        LIST_MODE_END
    } list_mode;
public:
    VfxS16 curr_item_index;
    VappBrowserBookmarksContext *m_bookmarksContext;
    VfxU8* m_selectedListInfo;
    VfxBool m_isCustomControlNeeded;

    VappBrowserBookmarksDataProvider(void)
    {
        curr_item_index = -1;
        m_bookmarksContext = NULL;
        m_isCustomControlNeeded = VFX_TRUE;
    }

    void updateCustomControlStatus(VfxBool isCustomControlNeeded)
    {
        m_isCustomControlNeeded = isCustomControlNeeded;
    }

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

   virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        ) 
    {
        text.loadFromRes(STR_ID_VAPP_BRW_NO_BOOKMARKS);
        return VFX_TRUE;
    }

   virtual VfxU32 getCount() const 
    {
        return ((VfxU32)m_bookmarksContext->getTotalFileCount());
    }

   virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;

   virtual VfxBool getItemIsDisabled(
        VfxU32 index       // [IN] the index of item
        ) const;

    virtual VcpListMenuCellBaseControl *getItemCustomControl(
        VfxU32 index,                                       // [IN] index of the item
        VcpListMenuCellControlLocationTypeEnum location,    // [IN] Control location
        VfxFrame *parentFrame                               // [IN] parent frame of the custom content frame
        ) ;

    virtual void closeItemCustomControl(
        VfxU32 index,                                       // [IN] index of the item
        VcpListMenuCellControlLocationTypeEnum location,    // [IN] Control location
        VcpListMenuCellBaseControl *cellControl             // [IN] the content frame to be released
        )
    {
        if(cellControl)
        {
            VFX_OBJ_CLOSE(cellControl);
        }
    }

    void initialize(void)
    {
        m_bookmarksContext = new(VappBrowserBookmarksContext);
        memset(m_bookmarksContext->m_selFolderName, 0, (SRV_BRW_BKM_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH);
        m_bookmarksContext->updateFileCount();
    }

    void initialize(VfxWString &selFolderName)
    {
        m_bookmarksContext = new(VappBrowserBookmarksContext);
        mmi_ucs2cpy((CHAR*)m_bookmarksContext->m_selFolderName, (const CHAR*)selFolderName.getBuf());
        m_bookmarksContext->updateFileCount();
    }
    void deinitialize(void)
    {
        if(m_bookmarksContext)
        {
            delete m_bookmarksContext;
        }
    }
    VfxBool isRootFolderSelected(void);
    void setNormalMode()
    {
        list_mode = LIST_MODE_NORMAL;
    }

    void setSelectionMode()
    {
        list_mode = LIST_MODE_SELECTION;
    }
};

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__

/****************************************************************************
* Class VappBrowserFoldersDataProvider
****************************************************************************/
class VappBrowserFoldersDataProvider : public VfxObject, public IVcpListMenuContentProvider
{
public:
    srv_brw_bkm_bookmark_list_struct m_bookmarkFolderList[SRV_BRW_BKM_MAX_COUNT];
    VfxS16 m_folderCount;
    VfxS16 m_selectedIndex;

    VappBrowserFoldersDataProvider(void):
        m_folderCount(0),
		m_selectedIndex(SRV_BRW_ROOT_PARENT_INDEX)
    {
    }

    virtual VfxU32 getCount() const 
    {
        return ((VfxU32)m_folderCount + 1);
    }

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index
        ) const;

    virtual VfxBool getItemTextFrameFormat(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxTextFrame *frame             // [OUT] the text frame
        ) ;

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );

    U32 initialize(VfxWString &selFolderName);
};
#endif
#endif

#ifndef __MMI_BRW_SLIM__
class VappBrowserRecentPage : public VfxPage
{
public:
    enum
    {
        FAVOURITES_RECENT_PAGES_CLEAR = 0,
        FAVOURITES_RECENT_PAGES_END
    };

    enum
    {
        COMMAND_CLEAR_TODAYS = 0,
        COMMAND_CLEAR_LAST_TWO_DAYS,
        COMMAND_CLEAR_ALL,
        COMMAND_CLEAR_CANCEL,
        COMMAND_CLEAR_END
    };
    enum
    {
        COMMAND_LONG_TAP_DELETE = 0,
        COMMAND_LONG_TAP_END
    };

    VfxU32 selectedRecentPageIndex;
    VcpGroupListMenu *m_recentPagesList;
    VappBrowserRecentPageDataProvider *m_recentPageContentProvider;
    VcpToolBar *m_toolBar;
    VcpCommandPopup *m_commandPopup;
    VcpMenuPopup *m_contextMenu;
    VcpIndicatorPopup *m_popup;

    VappBrowserRecentPage(void):
        m_recentPagesList(NULL),
        m_recentPageContentProvider(NULL),
        m_toolBar(NULL),
        m_commandPopup(NULL),
        m_contextMenu(NULL),
        m_popup(NULL)
    {
    }

    virtual void onInit();
    virtual void onDeinit();
    void onItemTap(VcpGroupListMenu *sender, VcpMenuPos pos);
    void onTBClick(VfxObject* sender, VfxId id);
    void onCommandCallClick(VfxObject *obj, VfxId id);
    void clearTodaysEventHandler(VfxObject* obj, VfxId id);
    void clearTwoDaysEventHandler(VfxObject* obj, VfxId id);
    void clearAllEventHandler(VfxObject* obj, VfxId id);
    void onItemLongTapped(VcpGroupListMenu *sender, VcpMenuPos pos);
    void contextMenuCallack(VcpMenuPopup *menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem *item);
    void clearRecentPageCallback(S32 user_data, U32 result, void *obj);
    void recentPageListDataReceiveCallback(S32 userData, U32 result, void *data);
    //VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
    void recentpageDeleteHandler(VfxObject* obj, VfxId id);
    void updateTBState(void);
    void wifiBearerCallback(VfxU32 state, VfxU32 errorCause);
    void launchUrlCallback(void);
};
#endif

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
class VappBrowserStoredPage : public VfxPage
{
private:
    VfxU8 m_selectedItemsCount;
public:
    enum
    {
        FAVOURITES_STORED_PAGES_DELETE = 0,
        FAVOURITES_STORED_PAGES_END
    } ;
    enum
    {
        COMMAND_LONG_TAP_DELETE = 0,
        COMMAND_LONG_TAP_END
    };
    enum
    {
        MULTI_OPTION_SELECT_ALL = 0,
        MULTI_OPTION_UNSELECT_ALL,
        MULTI_OPTION_DELETE,
        MULTI_OPTION_CANCEL,
        MULTI_OPTION_END
    } ;


    VcpListMenu *m_storedPagesList;
    VappBrowserStoredPageDataProvider *m_storedPageContentProvider;
    VcpToolBar *m_toolBar;
    VcpToolBar *m_multiOptionToolBar;
    VcpMenuPopup *m_contextMenu;
    VfxU32 selectedStoredPageIndex;
    VcpIndicatorPopup *m_popup;
    VfxBool m_isSelectAll;

    VappBrowserStoredPage(void):
        m_selectedItemsCount(0),
        m_storedPagesList(NULL),
        m_storedPageContentProvider(NULL),
        m_toolBar(NULL),
        m_multiOptionToolBar(NULL),
        m_contextMenu(NULL),
        m_popup(NULL)
    {
    }

    virtual void onInit();
    virtual void onDeinit();
    virtual void onBack();
    void onItemTap(VcpListMenu *sender, VfxU32 index);
    void onButtonClick(VcpListMenu *sender, VfxU32 index);
    void onTBClick(VfxObject* sender, VfxId id);
    void onItemLongTapped(VcpListMenu *sender, VfxU32 index);
    void contextMenuCallack(VcpMenuPopup *menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem *item);
    void deleteStoredPageCallback(S32 userData, U32 result, void *data);
    void storedPageListDataReceiveCallback(S32 userData, U32 result, void *data);
    void onMultiOptionTBClick(VfxObject* sender, VfxId id);
    void multiDeleteEventHandler(VfxObject* obj, VfxId id);
    void onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
	//virtual VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
    void updateTBState(void);
    void storedpageDeleteHandler(VfxObject* obj, VfxId id);
    void wifiBearerCallback(VfxU32 state, VfxU32 errorCause);
    void launchUrlCallback(void);
    void mySetBottomBar(void);
};
#endif

class VappBrowserBookmarkPage : public VfxPage
{
private:
    VfxU8 m_selectedItemsCount;
    VfxU8 m_totalSelectableItems;

public:
    enum
    {
        FAVOURITES_BOOKMARKS_ADD = 0,
        FAVOURITES_BOOKMARKS_DELETE,
        #ifndef __MMI_BRW_SLIM__
        FAVOURITES_IMPORT_BOOKMARK,
        FAVOURITES_EXPORT_BOOKMARK,
        #endif
        FAVOURITES_BOOKMARKS_END
    } ;
    enum
    {
        COMMAND_LONG_TAP_EDIT = 0,
        COMMAND_LONG_TAP_SHARE,
        COMMAND_LONG_TAP_DELETE,
        COMMAND_LONG_TAP_END
    };
    enum
    {
        MULTI_OPTION_SELECT_ALL = 0,
        MULTI_OPTION_UNSELECT_ALL,
        MULTI_OPTION_DELETE,
        MULTI_OPTION_CANCEL,
        MULTI_OPTION_END
    } ;
    enum
    {
        COMMAND_ADD_BOOKMARK = 0,
        COMMAND_ADD_FOLDER,
        COMMAND_ADD_CANCEL,
        COMMAND_ADD_END
    };

    enum
    {
        FOLDER_MODE_ADD = 0,
        FOLDER_MODE_EDIT,
        FOLDER_MODE_END
    } m_folderMode;

    VfxBool m_isUpdateNeeded;
    VfxU32 selectedBookmarkItemIndex;
    VcpListMenu *m_bookmarksList;
    VappBrowserBookmarksDataProvider *m_bookmarksContentProvider;
    VcpToolBar *m_toolBar;
    VcpToolBar *m_multiOptionToolBar;
    VcpMenuPopup *m_contextMenu;
    VcpInputPopup *m_folderInput;
    VcpIndicatorPopup *m_popup;
    VfxBool m_isSelectAll;
    VfxWChar *m_exportbookmarkfolder;
    VfxWChar *m_bookmarkUrl;
    VfxU32 m_orginalBookmarkItems;
    VcpConfirmPopup *m_confirmPopup;
    VfxObjWeakPtr m_confirmPopup_wpt; // for fix MAUI_03180415
    #ifdef __MMI_BRW_SLIM__
	VcpTitleBar *m_titleBar;
	#endif

    VappBrowserBookmarkPage(void):
        m_selectedItemsCount(0),
        m_totalSelectableItems(0),
        m_folderMode(FOLDER_MODE_ADD),
        m_isUpdateNeeded(VFX_FALSE),
        m_bookmarksList(NULL),
        m_bookmarksContentProvider(NULL),
        m_toolBar(NULL),
        m_multiOptionToolBar(NULL),
        m_contextMenu(NULL),
        m_folderInput(NULL),
        m_popup(NULL),
        m_exportbookmarkfolder(NULL),
        m_bookmarkUrl(NULL),
        m_orginalBookmarkItems(0),
        m_confirmPopup(NULL)
    {
    }


    VfxBool isUpdateNeeded(void)
    {
        return m_isUpdateNeeded;
    }

    void setUpdateNeededStatus(VfxBool status)
    {
        m_isUpdateNeeded = status;
    }

    VfxU8 getSelectedItemsCount(void)
    {
        return m_selectedItemsCount;
    }

    void setOrignalBookmarkItems(VfxU32 number)
    {
        m_orginalBookmarkItems = number;
    }

    VfxU32 getOrignalBookmarkItems(void)
    {
        return m_orginalBookmarkItems;
    }
    
    virtual void onInit();
    virtual void onDeinit();
    virtual void onBack();
    void onTBClick(VfxObject* sender, VfxId id);
    void onButtonClick(VcpListMenu *sender,  VfxU32 index);
    void onItemTap(VcpListMenu *sender, VfxU32 index);
    void onItemLongTapped(VcpListMenu *sender, VfxU32 index);
    void contextMenuCallack(VcpMenuPopup *menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem *item);
    void bookmarkDeleteHandler(VfxObject* obj, VfxId id);
    void onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
    void onMultiOptionTBClick(VfxObject* sender, VfxId id);
    void selectAllItems(VfxBool isSelected);
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    void onClickInputButton(VfxObject* sender, VcpInputPopupButtonEnum button_id);
    #endif
    //VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
    void multiDeleteEventHandler(VfxObject* obj, VfxId id);
    void onCommandCallClick(VfxObject *obj, VfxId id);
    void fmgrCuiCallback(void *param);
    void updateTBState(void);
    void onBookmarkDeleteCallback();
    void bkmProvisioningCallback(void *param);
    void bookmarkExportCallback(void *param);
    void wifiBearerCallback(VfxU32 state, VfxU32 errorCause);
    void launchUrlCallback(void);
    VfxBool isBookMarkAddedSuccess();
    void bkmSetBottomBar(void);
};


class VappBrowserFavouritesPage : public VcpTabCtrlPage
{
private:
    VFX_DECLARE_CLASS(VappBrowserFavouritesPage);
	#ifndef __MMI_BRW_SLIM__
    VfxBool m_isRecentPagesListAvailable;
	#endif
    VfxBool m_isBookmarksListAvailable;
    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    VfxBool m_isStoredPagesListAvailable;
    #endif 
    // Override
public:

    enum
    {
        VAPP_BRW_FAVOURITES_TAB_BOOKMARKS = 1,
        #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
        VAPP_BRW_FAVOURITES_TAB_STORED_PAGES,
        #endif
#ifndef __MMI_BRW_SLIM__
        VAPP_BRW_FAVOURITES_TAB_RECENT_PAGES,
#endif
        VAPP_BRW_FAVOURITES_TAB_TOTAL
    }m_selectedTab;

    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    VappBrowserStoredPage *m_storedPageTabPage;
    #endif
    VappBrowserBookmarkPage *m_bookmarksTabPage;
    VcpIndicatorPopup *m_popup;
	#ifndef __MMI_BRW_SLIM__
    VappBrowserRecentPage *m_recentPageTabPage;
	#endif
	VfxS8 m_dummy;

    VappBrowserFavouritesPage(void):
	#ifndef __MMI_BRW_SLIM__
    m_isRecentPagesListAvailable(VFX_FALSE),
    #endif
    m_isBookmarksListAvailable (VFX_TRUE),
    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    m_isStoredPagesListAvailable (VFX_FALSE),
    #endif
    m_selectedTab(VAPP_BRW_FAVOURITES_TAB_BOOKMARKS),
    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    m_storedPageTabPage (NULL),
    #endif
	#ifndef __MMI_BRW_SLIM__
    m_recentPageTabPage (NULL),
    #endif
    m_dummy (0)//for fix build warning
    {
    }
    #ifndef __MMI_BRW_SLIM__
    void setRecentPageListAvailability(VfxBool availability)
    {
        m_isRecentPagesListAvailable = availability;
    }


    VfxBool getRecentPageListAvailability(void)
    {
        return (m_isRecentPagesListAvailable);
    }
	#endif
	
    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    void setStoredPageListAvailability(VfxBool availability)
    {
        m_isStoredPagesListAvailable = availability;
    }

    VfxBool getStoredPageListAvailability(void)
    {
        return (m_isStoredPagesListAvailable);
    }
    #endif
    void setBookmarksListAvailability(VfxBool availability)
    {
        m_isBookmarksListAvailable = availability;
    }

    VfxBool getBookmarksListAvailability(void)
    {
        return (m_isBookmarksListAvailable);
    }

    VfxBool getAllListAvailability(void)
    {
        return (
			#ifndef __MMI_BRW_SLIM__
			m_isRecentPagesListAvailable && 
			#endif
            #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
            m_isStoredPagesListAvailable && 
            #endif 
            m_isBookmarksListAvailable);
    }

    MMI_BOOL isBookmarksTabSelected(void)
    {
        return ((MMI_BOOL)(getCurrTab() == VAPP_BRW_FAVOURITES_TAB_BOOKMARKS));
    }

    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);

    virtual VfxPage *onCreateTabPage(VfxId tabId);
    void showPage(void);
    void requestListData(void);
    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    void getStoredPageListData(void);
    #endif
    void getRecentPageListData(void);
	#ifndef __MMI_BRW_SLIM__
    VfxPage* showRecentPagesList(void);
	#endif
    VfxPage* showBookmarksList(void);
    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    VfxPage* showStoredPagesList(void);
    #endif
    void recentPageListDataReceiveCallback(S32 userData, U32 result, void *data);
    #ifdef __MMI_BRW_STORED_PAGES_SUPPORT__
    void storedPageListDataReceiveCallback(S32 userData, U32 result, void *data);
    #endif
	//VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
};

#ifdef __MMI_BRW_STORED_PAGES_SUPPORT__

/****************************************************************************
* Class VappBrowserStoredPageDetailsPage
****************************************************************************/
class VappBrowserStoredPageDetailsPage : public VfxPage
{
public:
    enum
    {
        STORED_PAGES_DETAILS_TAB_DELETE = 0,
        STORED_PAGES_DETAILS_TAB_TOTAL
    };

    VcpIndicatorPopup *m_popup;
    VcpTextView *m_textDisplay;
    VfxU32 m_selectedIndex;
    VcpTitleBar *m_titleBar;
    VcpToolBar *m_toolBar;
    VfxWChar *m_outputStr;

    VappBrowserStoredPageDetailsPage(VfxU32 selectedIndex):
    m_popup(NULL),
    m_textDisplay(NULL),
    m_selectedIndex(selectedIndex),
    m_titleBar(NULL),
    m_toolBar(NULL)
    {
    }

    void requestStoredPageData(void);
    void showPage();
    virtual void onInit();
    virtual void onDeinit();
    void onTBClick(VfxObject* sender, VfxId id);
    void getDetailsReceiveCallback(S32 userData, U32 result, void *data);
    void deleteStoredPageCallback(S32 userData, U32 result, void *data);
    void deleteStoredPageEventHandler(VfxObject* obj, VfxId id);
    void storedPageListDataReceiveCallback(S32 userData, U32 result, void *data);
	//VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
};
#endif


/****************************************************************************
* Class VappBrowserBookmarksDetailsPage
****************************************************************************/
class VappBrowserBookmarksDetailsPage : public VfxPage
{
public:
    enum
    {
        BOOKMARKS_DETAILS_TAB_EDIT = 0,
		#ifndef __MMI_BRW_SLIM__
        BOOKMARKS_DETAILS_TAB_SHARE,
		#endif
        BOOKMARKS_DETAILS_TAB_DELETE,
        BOOKMARKS_DETAILS_TAB_TOTAL
    };
    VcpTextView *m_textDisplay;
    VfxU8 m_selFileIndex;
    VcpTitleBar *m_titleBar;
    VcpToolBar *m_toolBar;
    VfxWChar *m_outputStr;

    VfxSignal0 m_deleteCallback;

    VappBrowserBookmarksDetailsPage(VfxU8 selected_file_index):
    m_textDisplay(NULL),
    m_selFileIndex(selected_file_index),
    m_titleBar(NULL), 
    m_toolBar(NULL)
    {
    }

    virtual void onInit();
    virtual void onDeinit();
    void onTBClick(VfxObject* sender, VfxId id);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
    void bookmarkDeleteHandler(VfxObject* obj, VfxId id);
};



/****************************************************************************
* Class VappBrowserAddBookmark
****************************************************************************/
class VappBrowserAddBookmark : public VfxPage
{

public:
    enum
    {
        ADD_BOOKMARK_SAVE = 0,
        ADD_BOOKMARK_CANCEL,
        ADD_BOOKMARK_END
    } ;

    enum
    {
        BOOKMARK_FB_PREV = 0,
        BOOKMARK_FB_NEXT,
        BOOKMARK_FB_SAVE,
        BOOKMARK_FB_END
    } ;

    typedef enum
    {
        BOOKMARK_MODE_ADD = 0,
        BOOKMARK_MODE_EDIT,
        BOOKMARK_MODE_ADD_TO,
        BOOKMARK_MODE_END
    } bookmark_mode_enum;
    bookmark_mode_enum m_bookmarkMode;

    VfxU8 m_selectedFileIndex;
    VfxWString m_selFilePath;
    VfxWString m_titleStrimg;
    VfxWString m_urlStrimg;
    VcpTitleBar *m_titleBar;
    VcpForm *m_form;
    VcpFormItemCaption *m_titleCaption;
    VcpFormItemCaption *m_UrlCaption;
    VcpFormItemTextInput *m_titleInput;
    VcpFormItemTextInput *m_UrlInput;
    VfxWString m_parentFolder;
    #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
    VfxWChar* m_selectedParentFolder;
    VcpFormItemCaption *m_parentFolderCaption;
    VcpFormItemLauncherCell *m_parentFolderCell;
    #endif
    VcpToolBar *m_toolBar;
    VcpFunctionBar *m_funcBar;

    VappBrowserAddBookmark(VfxWString &parentFolder):
		m_bookmarkMode(BOOKMARK_MODE_ADD),
        m_titleBar(NULL),
        m_form(NULL),
        m_titleCaption(NULL),
        m_UrlCaption(NULL),
        m_titleInput(NULL),
        m_UrlInput(NULL),
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        m_parentFolder(parentFolder),
        m_selectedParentFolder(NULL),
        m_parentFolderCaption(NULL),
        m_parentFolderCell(NULL),
        #endif
		m_toolBar(NULL),
        m_funcBar(NULL)    
    {
    }

    VappBrowserAddBookmark(VfxWString &titleString, VfxWString &urlString, VfxU8 addMode):
		m_bookmarkMode((bookmark_mode_enum)addMode),
		m_titleStrimg(titleString),
		m_urlStrimg(urlString),
        m_titleBar(NULL),
        m_form(NULL),
        m_titleCaption(NULL),
        m_UrlCaption(NULL),
        m_titleInput(NULL),
        m_UrlInput(NULL),
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
		m_selectedParentFolder(NULL),
        m_parentFolderCaption(NULL),
        m_parentFolderCell(NULL),
        #endif
        m_toolBar(NULL),
        m_funcBar(NULL)
        
    {
        #ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__
        m_parentFolder.setEmpty();
        #endif
    }
    VappBrowserAddBookmark(VfxU8 selFileIndex);

    virtual void onInit();
    virtual void onDeinit();
	virtual void onRotate(const VfxScreenRotateParam & param);
    void onTBClick(VfxObject* sender, VfxId id);
    void onButtonClicked(VcpFormItemCell* sender, VfxId Id);
    void onFolderSelect(VfxWChar *selectedFolderPath);
    //VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
    void onFuncBarItemSelected(VfxObject *sender, VfxId id);
    void onTitleEditorActivated(VcpTextEditor *editor, VfxBool activated);
    void onUrlEditorActivated(VcpTextEditor *editor, VfxBool activated);
};

#ifdef __MMI_BRW_BKM_FOLDER_SUPPORT__

/****************************************************************************
* Class VappBrowserBookmarkFolderPage
****************************************************************************/
class VappBrowserBookmarkFolderPage : public VfxPage
{
private:
    VfxU8 m_selectedItemsCount;

public:
    enum
    {
        FAVOURITES_BOOKMARKS_ADD_BOOKMARK = 0,
        FAVOURITES_BOOKMARKS_DELETE,
        FAVOURITES_BOOKMARKS_END
    } ;
    enum
    {
        COMMAND_LONG_TAP_EDIT = 0,
        COMMAND_LONG_TAP_SHARE,
        COMMAND_LONG_TAP_DELETE,
        COMMAND_LONG_TAP_END
    };
    enum
    {
        MULTI_OPTION_SELECT_ALL = 0,
        MULTI_OPTION_UNSELECT_ALL,
        MULTI_OPTION_DELETE,
        MULTI_OPTION_CANCEL,
        MULTI_OPTION_END
    } ;

    VfxWString m_selFolderName;
    VfxBool m_isUpdateNeeded;
    VcpTitleBar *m_titleBar;
    VcpListMenu *m_bookmarksList;
    VappBrowserBookmarksDataProvider *m_bookmarksContentProvider;
    VfxU32 selectedBookmarkItemIndex;
    VcpToolBar *m_toolBar;
    VcpToolBar *m_multiOptionToolBar;
	VcpTitleBar *m_deleteTitleBar;
    VcpMenuPopup *m_contextMenu;
    VfxBool m_isSelectAll;
    VfxWChar *m_selectedBookmarkPath;
    VcpIndicatorPopup *m_popup;
    VfxWChar *m_bookmarkUrl;
    VcpConfirmPopup *m_confirmPopup;
    VfxObjWeakPtr m_confirmPopup_wpt; // for fix MAUI_03178075
    

    VappBrowserBookmarkFolderPage(VfxWString &selFolderName):
        m_selectedItemsCount(0),
        m_selFolderName(selFolderName),
        m_isUpdateNeeded(VFX_FALSE),
        m_titleBar(NULL),
        m_bookmarksList(NULL),
        m_bookmarksContentProvider(NULL),
        m_toolBar(NULL),
        m_multiOptionToolBar(NULL),
        m_deleteTitleBar(NULL),
        m_contextMenu(NULL),
        m_selectedBookmarkPath(NULL),
        m_popup(NULL),
        m_bookmarkUrl(NULL)
    {
    }


    VfxBool isUpdateNeeded(void)
    {
        return m_isUpdateNeeded;
    }

    void setUpdateNeededStatus(VfxBool status)
    {
        m_isUpdateNeeded = status;
    }
    virtual void onInit();
    virtual void onDeinit();
    virtual void onBack();
    virtual void onEnter(VfxBool isBackward);

    void onTBClick(VfxObject* sender, VfxId id);
    void onButtonClick(VcpListMenu *sender,  VfxU32 index);
    void onItemTap(VcpListMenu *sender, VfxU32 index);
    void onItemLongTapped(VcpListMenu *sender, VfxU32 index);
    void contextMenuCallack(VcpMenuPopup *menu, VcpMenuPopupEventEnum event, VcpMenuPopupItem *item);
    void onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
    void onMultiOptionTBClick(VfxObject* sender, VfxId id);
    void selectAllItems(VfxBool isSelected);
    void multiDeleteEventHandler(VfxObject* obj, VfxId id);
    //VfxScrRotateTypeEnum onQueryRotate(const VfxScreenRotateParam &param);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);
    void updateTBState(void);
    void updateMulitiTBState(void);
    void bookmarkDeleteHandler(VfxObject* obj, VfxId id);
    void onBookmarkDeleteCallback();
    void wifiBearerCallback(VfxU32 state, VfxU32 errorCause);
    void launchUrlCallback(void);
    void bkmFolderSetBottomBar(void);
};


class VappBrowserSelectFolderCustomFrame:public VcpListMenuCellClientBaseFrame
{
public:
	VfxTextFrame *m_text;
	virtual void onCreateElements(void){}
	virtual void onCloseElements(void){}
	virtual void onLayoutElements(void){}
    virtual void onUpdateElements(void){}
};


class VappBrowserSelectFolderPage : public VfxPage
{
public:
    VcpTitleBar *m_titleBar;
    VcpListMenu *m_foldersList;
    VappBrowserFoldersDataProvider *m_foldersContentProvider;
    VfxWChar *m_selFolderName;
    VfxSignal1<VfxWChar *> m_selectedFolderCallback;
    U32 m_index;

    VappBrowserSelectFolderPage(VfxWChar *selFolderName);
    virtual void onInit();
    virtual void onDeinit();
    void onItemTap(VcpListMenu *sender, VfxU32 index);
    virtual void onQueryRotateEx(VfxScreenRotateParam & param);

};
#endif

#endif /* __MMI_BROWSER_2__ */

#endif /* _VAPP_BRW_FAVOURITES_H_ */
