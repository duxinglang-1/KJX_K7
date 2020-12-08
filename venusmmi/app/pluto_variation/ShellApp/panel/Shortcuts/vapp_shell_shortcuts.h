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
 *  vapp_shell_shortcuts.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Shell shortcuts class defination
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_SHELL_SHORTCUTS_H__
#define __VAPP_SHELL_SHORTCUTS_H__
#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_SHORTCUTS__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "ShellApp\base\vapp_shell_panel.h"
#include "vcp_option_menu.h"
#include "vcp_popup.h"
#include "vcp_image_button.h"
#include "vfx_datatype.h"
#include "vfx_basic_type.h"
#include "vfx_cpp_base.h"
#include "vfx_frame.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vfx_animation.h"
#include "vfx_primitive_frame.h"
#include "vcp_frame_effect.h"
#include "vfx_string.h"
#include "vfx_text_frame.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
extern "C"
{
#include "custom_shell_shortcuts_cfg.h"
#include "ShortcutsDefs.h"
#include "common_nvram_editor_data_item.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
struct VappShellShctItemInfoStruct 
{
    VfxId menuId;
    VfxId parentMenuId;
    VfxId iconId;
};

extern const VfxU8 VAPP_SHELL_SHCT_CAND_LIST_NUM;
extern const VappShellShctItemInfoStruct vappShellShctCandList[];

#define VAPP_SHELL_SHCT_CFG_ITEM_INFO(menuId, parentMenuId, iconId)  {menuId, parentMenuId, iconId}
#define VAPP_SHELL_SHCT_CFG_ITEM_INFO_END       {0, 0, 0}

enum ShctOperationStateEnum
{
    OPERATION_STATE_IDLE,       // operation state of non-operation
    OPERATION_STATE_ADD,        // operation state of add new shortcut
    OPERATION_STATE_REPLACE,    // operation state of replace shortcut
    OPERATION_STATE_REMOVE,     // operation state of remove shortcut
    OPERATION_STATE_END
};

/***************************************************************************** 
 * Class VappShellShctItemIcon
 *****************************************************************************/

class VappShellShctItemIcon : public VcpImageButton
{
// Declaration
public:
    enum ShctIconZoomTypeEnum
    {
        TAP_ZOOM_IN,     // button remove shortcut
        TAP_ZOOM_OUT,    // button replace shortcut
        LONG_TAP_ZOOM_OUT,
        TYPE_END
    };

// Constructor / Destructor
public:
    VappShellShctItemIcon();
    ~VappShellShctItemIcon() {};

// Method
public:
    // This function gets the item icon size
    // RETURNS: Size of the item icon
    static VfxSize getShctItemIconSize();
    void setIcon(VfxId iconId);
    void onIconSwitch(VfxId iconId);
    void onIconSwitchFinish(VfxFrame *obj, VfxBool isFinish);
    void displayZoomAnimation(ShctIconZoomTypeEnum zoomType);

// Variable
public:
    VfxSignal2 <VappShellShctItemIcon *, VfxPenEvent &> m_signalTap;
    VfxSignal2 <VappShellShctItemIcon *, VfxPenEvent &> m_signalHold;

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

// Declaration
public:
    enum ShctIconPressStatusEnum
    {
        ICON_STATUS_IDLE,
        ICON_STATUS_PRESSED,
        ICON_STATUS_END
    };

// Variable
private:
    VfxTransformTimeline *m_zoomTimeLine;
    VfxTransformTimeline *m_tapTimeLine;
    VfxImageFrame *m_frontIcon;
    VfxImageFrame *m_backIcon;
    VcpFrameEffect *m_frameEffect1;
    VcpFrameEffect *m_frameEffect2;
    VfxId          m_iconId;
    ShctIconPressStatusEnum m_pressStatus;
};


/***************************************************************************** 
 * Class VappShellShctItem
 *****************************************************************************/

class VappShellShctItem : public VfxFrame
{
// Constructor / Destructor
public:
    VappShellShctItem(nvram_ef_shell_shortcuts_item_struct *itemInfo, VfxS32 index);
    ~VappShellShctItem() {};

// Method
public:
    VfxId getItemId();

    mmi_shct_item_type_enum getItemType();

    // This function adds a menu item as a shortcut
    void addShctItem(
        mmi_shct_item_type_enum itemType,
        VfxId itemId     // [IN] The new menu item ID
    );

    // This function replaces the selected item with a new menu item
    void replaceShctItem(
        mmi_shct_item_type_enum itemType,
        VfxId itemId    // [IN] The new menu item ID
    );

    // This function removes the selected item as an empty one
    void removeShctItem();
    
    void setItemChangedState(VfxBool changedState);

    VfxBool getItemChangedState();

    // This function handles the item tap operation
    void onShctItemTap(
        VfxBaseTimeline *timeLine,
        VfxBool isFinished
    );

    // This function handles the item long press operation
    void onShctItemHold(
        VappShellShctItemIcon* obj,  // [IN] pointer to the selected item icon
        VfxPenEvent &event      // [IN] pen event
    );

    void setItemTextBg();

    void saveToNvram();

    void updateItemIcon();

    void updateItemText();

// Implementation
private:
    // This function launch the App by the menu id
    void launchApp(
        VfxId itemId    // [IN] menu id of the application
    );

    // This function get the item img id by menu id
    VfxId getItemIconId();

    VfxWString getItemString();
// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Variable
private:
    VappShellShctItemIcon   *m_itemIcon;
    VfxTextFrame            *m_itemText;
    VfxImageFrame           *m_itemTextBg;
    VfxId                   m_itemId;
    mmi_shct_item_type_enum m_itemType;
    VfxS32                  m_index;
    VfxBool                 m_isChanged;
};


/***************************************************************************** 
 * Class VappShellShctScr
 *****************************************************************************/

class VappShellShctScr : public VappShellPanel
{
    VAPP_SHELL_PANEL_CREATE(VappShellShctScr, VFX_TRUE);

// Constructor / Destructor
public:
    VappShellShctScr();

// Method
public:
    // This function provides the title string ID
    // RETURNS: String ID of shell shortcuts title
    virtual VfxS32 getPanelStrId();

    // This function displays the command popup screen
    void displayItemEditCnfScr();

    // This function displays the candidate menu list screen
    void displayCandidateList();

    // This function saves the selected item when user press the button
    void setSelItem(
        VappShellShctItem *shctItem  // [IN] the selected item
    );

    // This function saves the operation state when user press the button
    void setOperationState(
        ShctOperationStateEnum operationState   // [IN] the operation state
    );

    ShctOperationStateEnum getOperationState();


    void removeShctItem(mmi_shct_item_type_enum itemType, VfxId itemId);

    void setIconPos(
        VfxPoint &iconPos
    );

    VfxPoint getIconPos();

    VfxSize getIconSize();

    void setTextPos(
        VfxPoint &textPos
    );

    VfxPoint getTextPos();

    void setTextSize(
        VfxSize &textSize
    );

    VfxSize getTextSize();

    void setTextBgImgPos(
        VfxPoint &textBgImgPos
    );

    VfxPoint getTextBgImgPos();

    void setTextBgImgSize(
        VfxSize &textBgImgSize
    );

    VfxSize getTextBgImgSize();

    void onJavaListSel(VfxId itemId);
    void onBrwBkmListSel(VfxId itemId);

    VfxBool checkIsDuplicated(VfxId itemId, mmi_shct_item_type_enum itemType);

// Method
private:
    void configItemDisplay();

    // This function calculates the item bounds by index
    // RETURNS: The item bounds
    void displayItem(
        VfxU8 index     // [IN] item index
    );

    // This function sort the menu id list
    void candListSorting(
        VfxId *menuIdList,  // [IN/OUT] the sort list
        const VfxU8 itemNum // [IN] the list count
    );

    // This function gets the sub menu items
    VfxU8 getSubMenuItemCount(
        VfxId parentMenuId  // [IN] parent menu id
    );
    
    // This function gets the menu item ptr by menu ID
    VcpOptionMenuItem *getOptionMenuItem(
        VfxId menuId   // [IN] the checking menu ID
    );

    // This function gets the sub menu list of the parent menu id
    void getSubMenuItemList(
        const VfxId parentMenuId,   // [IN] parent menu id
        VfxId *subMenuIdList        // [IN/OUT] sub menu id list
    );

    void updateAllItemIcons();

    void updateAllItemTexts();

// Implementation
private:
    // This function handles the command popup item selection event
    void onItemEditCnfScrSel(
        VfxObject* sender,  // [IN] the sender object 
        VfxId id            // [IN] the selected item ID
    );

    // This function handles the candidate list selection event
    void onCandidateListSel(
        VcpOptionMenu *sender,                      // [IN] the sender object
        VcpOptionMenu::VcpOptionMenuEventEnum evt,  // [IN] the operation event
        VcpOptionMenuItem *item                     // [IN] pointer to the option menu item
    );

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onInitView();
    virtual void onDeinitView();
    virtual void onEnterView();
    virtual void onExitView(ShellExitCauseEnum cause);

// Declaration
private:
    enum ShctEditCnfScrButtonEnum
    {
        BUTTON_REMOVE_SHORTCUT,     // button remove shortcut
        BUTTON_REPLACE_SHORTCUT,    // button replace shortcut
        BUTTON_CANCEL,              // button cancel
        BUTTON_END
    };

    struct ShctCandSubMenuStruct
    {
        VfxId parentMenu;
        VfxU8 count;
        VfxId *subMenuList;
    };

// Variable
private:
    nvram_ef_shell_shortcuts_item_struct *m_itemNvramInfo;
    VappShellShctItem       *m_shctItem[VAPP_SHELL_SHCT_MAX_ITEM];
    VappShellShctItem       *m_shctItemSel;
    ShctOperationStateEnum  m_operationState;
    VcpCommandPopup         *m_editCnfScr;
    VfxPoint                m_iconPos;
    VfxPoint                m_textPos;
    VfxSize                 m_textSize;
    VfxPoint                m_textBgImgPos;
    VfxSize                 m_textBgImgSize;
    VfxImageFrame           *m_imgBg;

    VcpOptionMenu           *m_candidateList;
    VcpOptionMenuItem       **m_menuItems;
    VfxU8                   m_maxOptionMenuItem;
    VfxU8                   m_appCount;
    VfxU8                   m_parentCount;
    VfxId                   *m_appMenuList;
    VfxId                   *m_parentMenuList;
    ShctCandSubMenuStruct   *m_subMenuList;
};

#endif /* __MMI_VUI_SHELL_SHORTCUTS__ */
#endif /* __VAPP_SHELL_SHORTCUTS_H__ */
