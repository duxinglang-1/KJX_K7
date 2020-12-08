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
 *  vcui_bookmark_opera.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _VCUI_BOOKMARK_OPERA_H_
#define _VCUI_BOOKMARK_OPERA_H_

#if (defined(__COSMOS_MMI_PACKAGE__) && defined(OPERA_BROWSER))

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMIDataType.h"
#include "vcui_bookmark_gprot.h"

// Opera bookmark APIs
#include "OpDevBookmark.h"

// Venus framework header
#include "vfx_object.h"
#include "vfx_cui.h"
#include "vfx_main_scr.h"
#include "vfx_page.h"

// Venus CP header
#include "vcp_list_menu.h"
#include "vcp_form.h"
#include "vcp_popup.h"

/***************************************************************************** 
 * Pre-declaration
 *****************************************************************************/

/***************************************************************************** 
 * Constant
 *****************************************************************************/

/***************************************************************************** 
 * Structure
 *****************************************************************************/

/***************************************************************************** 
 * Class VcuiSelectBookmarkCui
 *****************************************************************************/

class VcuiSelectBookmarkCui : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiSelectBookmarkCui);

// Override
protected:
    virtual void onRun(void *args, VfxU32 argSize);
};

/***************************************************************************** 
 * Class VcuiSelectBookmarkMainScr
 *****************************************************************************/

class VcuiSelectBookmarkMainScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VcuiSelectBookmarkMainScr);

// Override
protected:
    virtual void on1stReady();
};

/***************************************************************************** 
 * Class VcuiSelectBookmarkPage
 *****************************************************************************/

class VcuiSelectBookmarkPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VcuiSelectBookmarkPage);

// Declaration
private:
    // Tool bar item ID
    enum
    {
        TOOL_BAR_ID_CANCEL
    };
    
// Constructor / Destructor
public:
    VcuiSelectBookmarkPage();
        
// Override for VfxPage
protected:
    virtual void onInit();
    
    virtual void onDeinit();
    
    // Notify for back key process
    virtual void onBack();

    // Override this virtual function to return the screen support rotate types.
    virtual VfxScrRotateTypeEnum onQueryRotateEx(const VfxScreenRotateParam &param);

// Override for IVcpListMenuContentProvider
public:
    // Get the text resource for the text fields of list cell
    virtual VfxBool getItemText(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        );
    
    // Get the image resource for the image fields of list cell
    virtual VfxBool getItemImage(
        VfxU32 index,                   // [IN] the index of item
        VcpListMenuFieldEnum fieldType, // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        );

    // Get the empty text resource for the text when list menu is empty
    virtual VfxBool getMenuEmptyText(
        VfxWString &text,               // [OUT] the text resource
        VcpListMenuTextColorEnum &color // [OUT] the text color
        );

    // Get the item count of the list menu
    virtual VfxU32 getCount() const;
    
// Variable
private:
    VfxU8                   *m_selectTitle;
    VfxU8                   *m_selectUrl;
    VcpListMenu             *m_bookmarkListMenu;
    opera_bookmark_list_t   m_currentFolderBookmarkList;
        
//Implementation
private:
    void onToolBarTap(VfxObject* obj, VfxId id);
    void onListMenuItemTap(VcpListMenu *sender, VfxU32 index);
    void postResultToCaller();
};

/***************************************************************************** 
 * Class VcuiAddBookmarkCui
 *****************************************************************************/

class VcuiAddBookmarkCui : public VfxCui
{
    VFX_DECLARE_CLASS(VcuiAddBookmarkCui);

// Method
public:
    void setAddedUrlByUtf8(const VfxU8 *addedUrlUtf8);
    VfxWString &getAddedUrl(void);
    
// Override
protected:
    virtual void onRun(void *args, VfxU32 argSize);
    
// Variable
private:
    VfxWString m_addedUrl;
};

/***************************************************************************** 
 * Class VcuiAddBookmarkMainScr
 *****************************************************************************/

class VcuiAddBookmarkMainScr : public VfxMainScr
{
    VFX_DECLARE_CLASS(VcuiAddBookmarkMainScr);

// Override
protected:
    virtual void on1stReady();
};

/***************************************************************************** 
 * Class VcuiAddBookmarkPage
 *****************************************************************************/

class VcuiAddBookmarkPage : public VfxPage
{
    VFX_DECLARE_CLASS(VcuiAddBookmarkPage);

// Declaration
private:
    // Tool bar item ID
    enum
    {
        TOOL_BAR_ID_SAVE,
        TOOL_BAR_ID_CANCEL
    };

    // Form item ID
    enum
    {
        FORM_ID_TITLE_TEXT_INPUT,
        FORM_ID_URL_TEXT_INPUT,
        FORM_ID_SELECT_FOLDER_LAUNCHER_CELL
    };
    
// Constructor / Destructor
public:
    VcuiAddBookmarkPage();
        
// Static method
public:
    static void *getAddBkmUserData();
    static void setAddBkmUserData(void *userData);
    
// Method
public:
    void setSelectFolderId(VfxS32 selectFolderId);
    VfxS32 getSelectFolderId();
    void addBkmResultHandler(VfxS32 result);
    
// Override for VfxPage
protected:
    virtual void onInit();
    
    virtual void onDeinit();
    
    // Notify for back key process
    virtual void onBack();
    
    // While entering the page to be active
    virtual void onEnter(VfxBool isBackward);
    
// Variable
private:
    // Add bookmark form
    VcpForm *m_addBkmForm;
    
    // Add bookmark indicator popup
    VcpIndicatorPopup *m_addBkmIndicatorPopup;
    
    // Select folder ID
    VfxS32 m_selectFolderId;

    // User data for add bookmark result callback
    static void *m_addBkmUserData;
        
//Implementation
private:
    void onToolBarTap(VfxObject* obj, VfxId id);
    void onSelectFolderLauncherCellTap(VcpFormItemCell *sender, VfxId id);
    void postResultToCaller();
};

/***************************************************************************** 
 * Class VcuiSelectFolderTreeNode
 *****************************************************************************/

class VcuiSelectFolderTreeNode;

class VcuiSelectFolderTreeNode : public VfxBase
{
// Constructor / Destructor
public:
    VcuiSelectFolderTreeNode();
    
// Variable
public:
    VfxS32 m_nodeId;
    VcuiSelectFolderTreeNode *m_siblingNode;
    VcuiSelectFolderTreeNode *m_childNode;
};

/***************************************************************************** 
 * Class VcuiSelectFolderListNode
 *****************************************************************************/

class VcuiSelectFolderListNode : public VfxBase
{
// Constructor / Destructor
public:
    VcuiSelectFolderListNode();
    
// Variable
public:
    VfxS32 m_nodeId;
    VfxS32 m_nodeLevel;
};

/***************************************************************************** 
 * Class VcuiSelectFolderListMenuCell
 *****************************************************************************/

class VcuiSelectFolderListMenuCell : public VcpListMenuCellClientBaseFrame
{
    VFX_DECLARE_CLASS(VcuiSelectFolderListMenuCell);

// Declaration
private:
    enum
    {
        FOLDER_INDENTATION_LENGTH = 30
    };
    
// Constructor / Destructor
public:
    VcuiSelectFolderListMenuCell();
    
// Override
public:
    // Create the elements (text, images...) in the client frame,
    // sub-class should override this virtual function to create its own elements
    virtual void onCreateElements();

    // Close the elements (text, images...) in the client frame
    // sub-class should override this virtual function to close its own elements
    virtual void onCloseElements();

    // Layout the elements (text, images...) in the client frame
    virtual void onLayoutElements();

    // Get the latest data of the elements (text, images...) from content provider 
    virtual void onUpdateElements();

// Variable
public:
    VcuiSelectFolderListNode *m_folderList;
    VfxTextFrame *m_folderNameTextFrame;
    VfxU32 m_index;
};

/***************************************************************************** 
 * Class VcuiSelectFolderPage
 *****************************************************************************/

class VcuiSelectFolderPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VcuiSelectFolderPage);

// Constructor / Destructor
public:
    VcuiSelectFolderPage();
        
// Override for VfxPage
protected:
    virtual void onInit();
    
    virtual void onDeinit();
    
    // Notify for back key process
    virtual void onBack();

// Override for IVcpListMenuContentProvider
public:
    // Get the item count of the list menu
    virtual VfxU32 getCount() const;
    
    // Get the state of a list item
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index                    // [IN] index of the item
        ) const;

    // Get the content frame of the item, it's used when the cell style is 
    // VCP_LIST_MENU_CELL_STYLE_CUSTOM, uer should create and layout its owned
    // cell content frame and return it here
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,                           // [IN] index of the item
        VfxFrame *parentFrame                   // [IN] parent frame of the custom content frame
        );

    // Uer should release the resource of the content frame which is created by 
    // itself, such as image resource
    virtual void closeItemCustomContentFrame(
        VfxU32 index,                           // [IN] index of the item
        VcpListMenuCellClientBaseFrame *cell    // [IN] the content frame to be released
        );
    
// Variable
private:
    VfxU32                      m_totalNumOfFolder;
    VcuiSelectFolderTreeNode    *m_folderTree;
    VcuiSelectFolderListNode    *m_folderList;
    VcpListMenu                 *m_folderListMenu;
        
//Implementation
private:
    void onListMenuItemTap(VcpListMenu *sender, VfxU32 index);
    void generateFolderTree();
    void addFolderTreeNode(VcuiSelectFolderTreeNode *parentNode);
    void deleteFolderTree(VcuiSelectFolderTreeNode *node);
    void generateFolderList();
    void addFolderListNode(VcuiSelectFolderTreeNode *node, VfxS32 &nodeIndex, VfxS32 nodeLevel);
    void deleteFolderList();
};

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(OPERA_BROWSER) */

#endif /* _VCUI_BOOKMARK_OPERA_H_ */

