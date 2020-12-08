/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  vapp_widget_favorite_contact.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the favorite contact widget for KeyLaucher project.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VAPP_WIDGET_FAVORITE_CONTACT_H
#define VAPP_WIDGET_FAVORITE_CONTACT_H

#include "MMIDataType.h"
extern "C"
{
#include "mmi_cb_mgr_gprot.h"
}
#include "vfx_base_popup.h"
#include "vfx_primitive_frame.h"
#include "vfx_text_frame.h"
#include "vcp_button.h"
#include "vcp_base_menu.h"
#include "vapp_widget.h"

/*const*/
#define WIDGET_CONTACT_MENU_HEIGHT            (CELL_NORMAL_HEIGHT * CELL_NORMAL_COUNT + CELL_HIGHLIGHT_HEIGHT)
#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
//QVGA & WQVGA

#define WIDGET_CONTACT_MENU_WIDTH             186
#ifdef __MMI_MAINLCD_240X320__
#define CELL_NORMAL_COUNT                     3
#else
#define CELL_NORMAL_COUNT                     4
#endif

#define CELL_PREVIEW_WIDTH                    182
#define CELL_PREVIEW_HEIGHT                   172
#define CELL_PREVIEW_BUTTON_WIDTH             160
#define CELL_PREVIEW_BUTTON_HEIGHT            30
#define CELL_PREVIEW_BUTTON_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(16)
#define CELL_PREVIEW_FIRST_BUTTON_Y           60
#define CELL_PREVIEW_BUTTON_GAP               3
#define CELL_PREVIEW_WARNING_TEXT_HEIGHT      126
#define CELL_PREVIEW_WARNING_TEXT_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(15)
#define CELL_PREVIEW_SOFTKEY_FONT_SIZE        VFX_FONT_DESC_VF_SIZE(14)
#define CELL_PREVIEW_SOFTKEY_BORDER_GAP       10
#define CELL_PREVIEW_SOFTKEY_SIZE             VfxSize(LCD_WIDTH, 25)
#define CELL_PREVIEW_SOFTKEY_POS              VfxPoint(0, LCD_HEIGHT - 2)
#define WIDGET_CONTACT_CELL_GAP               0
#define CELL_NO_CONTACT_NAME_FONT_SIZE        VFX_FONT_DESC_VF_SIZE(13)
#define CELL_NO_CONTACT_NAME_POS              VfxPoint(46, CELL_NORMAL_HEIGHT >> 1)
#define CELL_NO_CONTACT_PIC_POS               VfxPoint(10, 1)
#define CELL_NO_CONTACT_PIC_SIZE              VfxSize(28, 33)
#define CELL_EMPTY_NAME_FONT_SIZE             VFX_FONT_DESC_VF_SIZE(13)
#define CELL_EMPTY_NAME_POS                   VfxPoint(61, CELL_HIGHLIGHT_HEIGHT >> 1)
#define CELL_EMPTY_PIC_POS                    VfxPoint(10, CELL_HIGHLIGHT_HEIGHT >> 1)
#define CELL_EMPTY_PIC_SIZE                   VfxSize(38, 42)
#define CELL_NORMAL_WIDTH                     182
#define CELL_NORMAL_HEIGHT                    41
#define CELL_NORMAL_CONTACT_NAME_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(18)
#define CELL_NORMAL_CONTACT_NAME_POS          VfxPoint(CELL_NORMAL_WIDTH >> 1, CELL_NORMAL_HEIGHT >> 1)
#define CELL_NORMAL_CONTACT_NAME_SIZE         VfxSize(CELL_NORMAL_WIDTH - 20, 18)
#define CELL_HIGHLIGHT_WIDTH                  182
#define CELL_HIGHLIGHT_HEIGHT                 68
#define CELL_HIGHLIGHT_CONTACT_NAME_FONT_SIZE VFX_FONT_DESC_VF_SIZE(18)
#define CELL_HIGHLIGHT_CONTACT_NAME_POS       VfxPoint(63, 15)
#define CELL_HIGHLIGHT_CONTACT_NAME_SIZE      VfxSize(CELL_HIGHLIGHT_WIDTH - 66 -10, 18)
#define CELL_HIGHLIGHT_CONTACT_PIC_POS        VfxPoint(15, 14)
#define CELL_HIGHLIGHT_CONTACT_PIC_SIZE       VfxSize(38, 42)
#define CELL_CONTACT_NUMBER_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(13)
#define CELL_CONTACT_NUMBER_POS               VfxPoint(63, 41)
#define CELL_CONTACT_NUMBER_SIZE              VfxSize(CELL_HIGHLIGHT_WIDTH - 66 -10, 13)


#elif defined(__MMI_MAINLCD_320X240__)
//LQVGA
#define WIDGET_CONTACT_MENU_WIDTH             188
#define CELL_NORMAL_COUNT                     3
#define CELL_PREVIEW_WIDTH                    182
#define CELL_PREVIEW_HEIGHT                   172
#define CELL_PREVIEW_BUTTON_WIDTH             160
#define CELL_PREVIEW_BUTTON_HEIGHT            30
#define CELL_PREVIEW_BUTTON_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(16)
#define CELL_PREVIEW_FIRST_BUTTON_Y           71
#define CELL_PREVIEW_BUTTON_GAP               0
#define CELL_PREVIEW_WARNING_TEXT_HEIGHT      126
#define CELL_PREVIEW_WARNING_TEXT_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(15)
#define CELL_PREVIEW_SOFTKEY_FONT_SIZE        VFX_FONT_DESC_VF_SIZE(14)
#define CELL_PREVIEW_SOFTKEY_BORDER_GAP       17
#define CELL_PREVIEW_SOFTKEY_SIZE             VfxSize(LCD_WIDTH, 30)
#define CELL_PREVIEW_SOFTKEY_POS              VfxPoint(0, LCD_HEIGHT - 2)
#define WIDGET_CONTACT_CELL_GAP               0
#define CELL_NO_CONTACT_NAME_FONT_SIZE        VFX_FONT_DESC_VF_SIZE(13)
#define CELL_NO_CONTACT_NAME_POS              VfxPoint(43, CELL_NORMAL_HEIGHT >> 1)
#define CELL_NO_CONTACT_PIC_POS               VfxPoint(10, 3)
#define CELL_NO_CONTACT_PIC_SIZE              VfxSize(24, 20)
#define CELL_EMPTY_NAME_FONT_SIZE             VFX_FONT_DESC_VF_SIZE(13)
#define CELL_EMPTY_NAME_POS                   VfxPoint(65, CELL_HIGHLIGHT_HEIGHT >> 1)
#define CELL_EMPTY_PIC_POS                    VfxPoint(15, CELL_HIGHLIGHT_HEIGHT >> 1)
#define CELL_EMPTY_PIC_SIZE                   VfxSize(38, 42)
#define CELL_NORMAL_WIDTH                     188
#define CELL_NORMAL_HEIGHT                    30
#define CELL_NORMAL_CONTACT_NAME_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(18)
#define CELL_NORMAL_CONTACT_NAME_POS          VfxPoint(CELL_NORMAL_WIDTH >> 1, CELL_NORMAL_HEIGHT >> 1)
#define CELL_NORMAL_CONTACT_NAME_SIZE         VfxSize(CELL_NORMAL_WIDTH - 20, 18)
#define CELL_HIGHLIGHT_WIDTH                  188
#define CELL_HIGHLIGHT_HEIGHT                 57
#define CELL_HIGHLIGHT_CONTACT_NAME_FONT_SIZE VFX_FONT_DESC_VF_SIZE(18)
#define CELL_HIGHLIGHT_CONTACT_NAME_POS       VfxPoint(63, 15)
#define CELL_HIGHLIGHT_CONTACT_NAME_SIZE      VfxSize(CELL_HIGHLIGHT_WIDTH - 66 -10, 18)
#define CELL_HIGHLIGHT_CONTACT_PIC_POS        VfxPoint(18, 7)
#define CELL_HIGHLIGHT_CONTACT_PIC_SIZE       VfxSize(38, 42)
#define CELL_CONTACT_NUMBER_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(13)
#define CELL_CONTACT_NUMBER_POS               VfxPoint(63, 35)
#define CELL_CONTACT_NUMBER_SIZE              VfxSize(CELL_HIGHLIGHT_WIDTH - 66 -10, 13)

#else
//HVGA
#define WIDGET_CONTACT_MENU_WIDTH             244
#define CELL_NORMAL_COUNT                     4
#define CELL_PREVIEW_WIDTH                    242
#define CELL_PREVIEW_HEIGHT                   224
#define CELL_PREVIEW_BUTTON_WIDTH             211
#define CELL_PREVIEW_BUTTON_HEIGHT            36
#define CELL_PREVIEW_BUTTON_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(16)
#define CELL_PREVIEW_WARNING_TEXT_HEIGHT      126
#define CELL_PREVIEW_FIRST_BUTTON_Y           80
#define CELL_PREVIEW_BUTTON_GAP               4
#define CELL_PREVIEW_WARNING_TEXT_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(18)
#define CELL_PREVIEW_SOFTKEY_FONT_SIZE        VFX_FONT_DESC_VF_SIZE(14)
#define CELL_PREVIEW_SOFTKEY_BORDER_GAP       10
#define CELL_PREVIEW_SOFTKEY_SIZE             VfxSize(LCD_WIDTH, 30)
#define CELL_PREVIEW_SOFTKEY_POS              VfxPoint(0, LCD_HEIGHT)
#define WIDGET_CONTACT_CELL_GAP               0
#define CELL_NO_CONTACT_NAME_FONT_SIZE        VFX_FONT_DESC_VF_SIZE(18)
#define CELL_NO_CONTACT_NAME_POS              VfxPoint(59, CELL_NORMAL_HEIGHT >> 1)
#define CELL_NO_CONTACT_PIC_POS               VfxPoint(19, 2)
#define CELL_NO_CONTACT_PIC_SIZE              VfxSize(31, 36)
#define CELL_EMPTY_NAME_FONT_SIZE             VFX_FONT_DESC_VF_SIZE(18)
#define CELL_EMPTY_NAME_POS                   VfxPoint(83, CELL_HIGHLIGHT_HEIGHT >> 1)
#define CELL_EMPTY_PIC_POS                    VfxPoint(23, CELL_HIGHLIGHT_HEIGHT >> 1)
#define CELL_EMPTY_PIC_SIZE                   VfxSize(55, 61)
#define CELL_NORMAL_WIDTH                     244
#define CELL_NORMAL_HEIGHT                    47
#define CELL_NORMAL_CONTACT_NAME_FONT_SIZE    VFX_FONT_DESC_VF_SIZE(24)
#define CELL_NORMAL_CONTACT_NAME_POS          VfxPoint(CELL_NORMAL_WIDTH >> 1, CELL_NORMAL_HEIGHT >> 1)
#define CELL_NORMAL_CONTACT_NAME_SIZE         VfxSize(CELL_NORMAL_WIDTH - 30, 24)
#define CELL_HIGHLIGHT_WIDTH                  244
#define CELL_HIGHLIGHT_HEIGHT                 91
#define CELL_HIGHLIGHT_CONTACT_NAME_FONT_SIZE VFX_FONT_DESC_VF_SIZE(24)
#define CELL_HIGHLIGHT_CONTACT_NAME_POS       VfxPoint(80, 21)
#define CELL_HIGHLIGHT_CONTACT_NAME_SIZE      VfxSize(CELL_HIGHLIGHT_WIDTH - 80 -20, 24)
#define CELL_HIGHLIGHT_CONTACT_PIC_POS        VfxPoint(18, 15)
#define CELL_HIGHLIGHT_CONTACT_PIC_SIZE       VfxSize(55, 61)
#define CELL_CONTACT_NUMBER_FONT_SIZE         VFX_FONT_DESC_VF_SIZE(18)
#define CELL_CONTACT_NUMBER_POS               VfxPoint(80, 57)
#define CELL_CONTACT_NUMBER_SIZE              VfxSize(CELL_HIGHLIGHT_WIDTH - 80 -20, 18)

#endif

/*contact Cell*/
class VappWidgetContactMenuCell: public VfxFrame
{
    VFX_DECLARE_CLASS(VappWidgetContactMenuCell);
public:
    enum CellStatusEnum
    {
        CELL_STATUS_EMPTY,
        CELL_STATUS_EMPTY_H,
        CELL_STATUS_NORMAL,
        CELL_STATUS_HIGHLIGHT
    };
public:
    VappWidgetContactMenuCell(VfxU32 index);
    VappWidgetContactMenuCell(){}
public:
    void onInit();
    void onDeinit();
    void setNoContact(VfxBool isAnim);
    void setEmpty(VfxBool isAnim);
    void setHighlight(VfxBool isAnim);
    void setNormal(VfxBool isAnim);
    CellStatusEnum getStatus()
    {
        return m_status;
    }
    VfxBool getResType()
    {
        return m_isFromFile;
    }
    VfxU16 getResId()
    {
        return m_resId;
    }
    VfxWString getResPath()
    {
        return m_resPath;
    }
    VfxWString getName()
    {
        return m_contactName;
    }
    VfxWString getNumber()
    {
        return m_contactNumber;
    }
    VfxU32 getIndex()
    {
        return m_index;
    }
    void Call();
private:
    CellStatusEnum m_status;
    VfxBool m_isFromFile;
    VfxU16 m_resId;
    VfxU32 m_index;
    VfxWString m_contactName;
    VfxWString m_contactNumber;
    VfxWString m_resPath;
    VfxTextFrame *m_name;
    VfxTextFrame *m_number;
    VfxImageFrame *m_callerPic;
    VfxImageFrame *m_backGround;
};

/*preView*/
class VappWidgetContactPreView : public VfxBasePopup
{
    VFX_DECLARE_CLASS(VappWidgetContactPreView);

public:
    VappWidgetContactPreView(){}
    VappWidgetContactPreView(VfxFrame *cell);
public:
    void onCall(VfxObject *obj, VfxId id);
    void onSendMessage(VfxObject *obj, VfxId id);
    void onRemove(VfxObject *obj, VfxId id);
    void onStateChanged(VfxObject *obj, VfxId id, VcpButtonStateEnum state);
    void onLskClicked(VcpSoftkeyEventEnum key_event);
    void onRskClicked(VcpSoftkeyEventEnum key_event);
    void onSelectClicked(VfxObject *obj, VfxId id);
    void onCancelClicked(VfxObject *obj, VfxId id);
    void onInit(void);
    void onDeinit(void);
    VfxBool onKeyInput(VfxKeyEvent & event);
public:
    VfxSignal1 <
        VfxU32
        > m_signalRemove;

private:
    void changeHighlight(VfxU32 highlightIndex, VfxU32 preHighlighIndex);
    
private:
    VfxBool m_isRemoveView;
    VfxS32 m_highlightItem;
    VfxImageFrame* m_callerPic;
    VfxImageFrame* m_bgPic;
    VfxTextFrame* m_name;
    VfxTextFrame* m_number;
    VcpButton* m_btnCall;
    VcpButton* m_btnSendMsg;
    VcpButton* m_btnRemove;
    VcpSoftkey *m_softKey;
    VfxTextFrame* m_warning;
    VappWidgetContactMenuCell *m_item;
};

/*layout*/
class VappWidgetContactMenuLayout: public VcpBaseMenuLayout
{
public:
    VappWidgetContactMenuLayout(VcpBaseMenu *menu);
public:
    void onInit();
    void onDeinit();
    ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }
    VfxS32 getGroupCount()
    {
        return 1;
    }
    VfxBool hasGroupHeader(VfxS32 group)
    {
        return VFX_FALSE;
    }
    void decreaseCellCount()
    {
        m_cellCount -= 1;
    }
    VfxS32 getCellCount(VfxS32 group);
    VfxS32 getContentLength();
    VfxRect queryCellRect(VcpMenuPos pos);
    VcpMenuPos getCellByPos(VfxPoint pt);
    VcpMenuRegion queryRegion(const VfxRect & r);
private:
    VfxU32 m_cellCount;
    VfxU32 m_cellHeight;
};


/*contact widget menu*/
class VappWidgetContactMenu : public VcpBaseMenu
{
    VFX_DECLARE_CLASS(VappWidgetContactMenu);
public:
    VappWidgetContactMenu(){}
public:
    static mmi_ret onContactSelected(mmi_event_struct* evt);
public:
    void onInit();
    void onDeinit();
    VcpBaseMenuLayout * createLayout();
    VfxFrame * createCell(VfxS32 group, VfxS32 pos);
    void onCloseCell(VfxS32 group,VfxS32 pos,VfxFrame * cellFrame);
    void onUpdateCell(
        const VfxRect &rect,
        VfxS32 group,
        VfxS32 pos,
        VfxFrame* cell,
        VfxU32 flag
    );
    void onTouchCell(
        VcpMenuPos          cellPos,
        CellTouchTypeEnum   touchType,
        VfxPoint            pt,
        VfxFrame            *cell
    );
    void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos preFocusItem);
    void onDragEnd();
    void onContactRemoved(VfxU32 index);
    VfxBool onKeyInput(VfxKeyEvent &event);
    VfxU32 getHighlightIndex()
    {
        return m_highlightIndex;
    }
private:
    void addNewContact();
    void updateMenu();
private :
    static VfxU32 m_highlightIndex;
    static mmi_id m_groupId;
    VfxBool m_tapCell;
    VfxBool m_isKeyRepeat;
    VappWidgetContactMenuLayout *m_layout;
    VappWidgetContactPreView *m_preView;
};


/**/
class VappWidgetContact: public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetContact);
public :
    VappWidgetContact(){}

public :
    static mmi_ret onPhbReady(mmi_event_struct* evt);
    static mmi_ret onMsModeExit(mmi_event_struct *evt);
public :
    void onCreateView();
    void onReleaseView();
    VfxS32 getName(VfxWChar *string, VfxS32 size) const;
    VfxFrame *createIcon(VfxObject *parentObj);
    VappWidgetId getId() const;
    VfxSize getMaxSize() const;
    void setHidden(VfxBool value);

private:
    void createMenu();
    void resetMenu();
private :
    VappWidgetContactMenu *m_menu;
    VcpWaitingIcon * m_indicator;
};
#endif
