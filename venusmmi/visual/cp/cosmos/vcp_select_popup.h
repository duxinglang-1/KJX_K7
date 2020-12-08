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
 *  vcp_select_popup.h
 *
 * Project:
 * --------
 *  Venus UI Component
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VCP_SELECT_POPUP_H__
#define __VCP_SELECT_POPUP_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vcp_button.h"
#include "vfx_base_popup.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vfx_text_frame.h"
#include "vfx_cpp_base.h"
#include "vfx_input_event.h"
#include "vfx_timer.h"
#include "vfx_frame.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vcp_scrollable.h"
#include "vcp_popup_data_type.h"
#include "vcp_list_menu.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

// VcpSelectPopup
#if defined(__MMI_MAINLCD_320X480__)

    // VcpSelectPopup
    
    #define VCP_SELECT_POPUP_WIDTH_PORTRAIT              (290)
    #define VCP_SELECT_POPUP_WIDTH_LANDSCAPE             (340)
    #define VCP_SELECT_POPUP_UP_HEIGHT                   (25)
    #define VCP_SELECT_POPUP_BOTTOM_HEIGHT               (15)
    #define VCP_SELECT_POPUP_BOTTOM_HEIGHT_QUICK         (16)
                     
    #define VCP_SELECT_POPUP_TEXT_X                      (145)
    #define VCP_SELECT_POPUP_TEXT_Y                      (13)
    #define VCP_SELECT_POPUP_TEXT_WIDTH                  (258)
    #define VCP_SELECT_POPUP_TEXT_SIZE                   (15)
    
    #define VCP_SELECT_POPUP_RADIO_X                     (145)
    #define VCP_SELECT_POPUP_RADIO_Y                     (0)
    #define VCP_SELECT_POPUP_RADIO_WIDTH_PORTRAIT        (282)
    #define VCP_SELECT_POPUP_RADIO_WIDTH_LANDSCAPE       (332)

    #define VCP_SELECT_POPUP_BUTTON_Y_SHIFT              (8)
    #define VCP_SELECT_POPUP_BUTTON_1_X                  (11)
    #define VCP_SELECT_POPUP_BUTTON_2_X                  (148)
    #define VCP_SELECT_POPUP_BUTTON_WIDTH                (131)
    #define VCP_SELECT_POPUP_BUTTON_HEIGHT               (47)

    #define VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (312)
    #define VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE     (208)
#elif defined(__MMI_MAINLCD_480X800__)

    // VcpSelectPopup
    
    #define VCP_SELECT_POPUP_WIDTH_PORTRAIT              (446)
    #define VCP_SELECT_POPUP_WIDTH_LANDSCAPE             (546)
    #define VCP_SELECT_POPUP_UP_HEIGHT                   (45)
    #define VCP_SELECT_POPUP_BOTTOM_HEIGHT               (26)
    #define VCP_SELECT_POPUP_BOTTOM_HEIGHT_QUICK         (35)
                     
    #define VCP_SELECT_POPUP_TEXT_X                      (223)
    #define VCP_SELECT_POPUP_TEXT_Y                      (22)
    #define VCP_SELECT_POPUP_TEXT_WIDTH                  (382)
    #define VCP_SELECT_POPUP_TEXT_SIZE                   (24)
    
    #define VCP_SELECT_POPUP_RADIO_X                     (223)
    #define VCP_SELECT_POPUP_RADIO_Y                     (0)
    #define VCP_SELECT_POPUP_RADIO_WIDTH_PORTRAIT        (432)
    #define VCP_SELECT_POPUP_RADIO_WIDTH_LANDSCAPE       (532)

    #define VCP_SELECT_POPUP_BUTTON_Y_SHIFT              (10)
    #define VCP_SELECT_POPUP_BUTTON_1_X                  (21)
    #define VCP_SELECT_POPUP_BUTTON_2_X                  (228)
    #define VCP_SELECT_POPUP_BUTTON_WIDTH                (197)
    #define VCP_SELECT_POPUP_BUTTON_HEIGHT               (73)

    #define VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (602)
    #define VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE     (344)

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)

    // VcpSelectPopup
    
    #define VCP_SELECT_POPUP_WIDTH_PORTRAIT              (222)
    #define VCP_SELECT_POPUP_WIDTH_LANDSCAPE             (242)
    #define VCP_SELECT_POPUP_UP_HEIGHT                   (20)
    #define VCP_SELECT_POPUP_BOTTOM_HEIGHT               (13)
    #define VCP_SELECT_POPUP_BOTTOM_HEIGHT_QUICK         (13)
                     
    #define VCP_SELECT_POPUP_TEXT_X                      (111)
    #define VCP_SELECT_POPUP_TEXT_Y                      (10)
    #define VCP_SELECT_POPUP_TEXT_WIDTH                  (206)
    #define VCP_SELECT_POPUP_TEXT_SIZE                   (13)
    
    #define VCP_SELECT_POPUP_RADIO_X                     (111)
    #define VCP_SELECT_POPUP_RADIO_Y                     (0)
    #define VCP_SELECT_POPUP_RADIO_WIDTH_PORTRAIT        (216)
    #define VCP_SELECT_POPUP_RADIO_WIDTH_LANDSCAPE       (236)

    #define VCP_SELECT_POPUP_BUTTON_Y_SHIFT              (5)
    #define VCP_SELECT_POPUP_BUTTON_1_X                  (8)
    #define VCP_SELECT_POPUP_BUTTON_2_X                  (114)
    #define VCP_SELECT_POPUP_BUTTON_WIDTH                (100)
    #define VCP_SELECT_POPUP_BUTTON_HEIGHT               (40)

    #if defined(__MMI_MAINLCD_240X320__)
    #define VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (270)
    #else
    #define VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (315)
    #endif
    #define VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE     (180)
#else

    // VcpSelectPopup
    
    #define VCP_SELECT_POPUP_WIDTH_PORTRAIT              (290)
    #define VCP_SELECT_POPUP_WIDTH_LANDSCAPE             (340)
    #define VCP_SELECT_POPUP_UP_HEIGHT                   (25)
    #define VCP_SELECT_POPUP_BOTTOM_HEIGHT               (19)
    #define VCP_SELECT_POPUP_BOTTOM_HEIGHT_QUICK         (26)
                     
    #define VCP_SELECT_POPUP_TEXT_X                      (145)
    #define VCP_SELECT_POPUP_TEXT_Y                      (13)
    #define VCP_SELECT_POPUP_TEXT_WIDTH                  (258)
    #define VCP_SELECT_POPUP_TEXT_SIZE                   (15)
    
    #define VCP_SELECT_POPUP_RADIO_X                     (145)
    #define VCP_SELECT_POPUP_RADIO_Y                     (0)
    #define VCP_SELECT_POPUP_RADIO_WIDTH_PORTRAIT        (280)
    #define VCP_SELECT_POPUP_RADIO_WIDTH_LANDSCAPE       (330)

    #define VCP_SELECT_POPUP_BUTTON_Y_SHIFT              (8)
    #define VCP_SELECT_POPUP_BUTTON_1_X                  (16)
    #define VCP_SELECT_POPUP_BUTTON_2_X                  (148)
    #define VCP_SELECT_POPUP_BUTTON_WIDTH                (127)
    #define VCP_SELECT_POPUP_BUTTON_HEIGHT               (47)

    #define VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_PORTRAIT     (312)
    #define VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE     (208)
#endif    

#define     VCP_SELECT_POPUP_BUTTON_OK         ('OK')
#define     VCP_SELECT_POPUP_BUTTON_CANCEL     ('NoOK')

enum VcpSelectPopupCellTypeEnum
{
     VCP_SELECT_POPUP_CELL_TYPE_SINGLE_TEXT,
     VCP_SELECT_POPUP_CELL_TYPE_ICON_SINGLE_TEXT,
	 VCP_SELECT_POPUP_CELL_TYPE_ICON_SINGLE_TEXT_EX,
     VCP_SELECT_POPUP_CELL_TYPE_END_OF_ENUM
};
enum VcpSelectPopupTypeEnum
{
     VCP_SELECT_POPUP_BUTTON_TYPE_QUICK,
     VCP_SELECT_POPUP_BUTTON_TYPE_SINGLE,
     VCP_SELECT_POPUP_BUTTON_TYPE_MULTI,
     VCP_SELECT_POPUP_BUTTON_TYPE_END_OF_ENUM
};

class VcpSelectCoreData : public VfxBase
{
public:
    VfxId      m_id;
    VfxWString m_text;
    VfxBool    m_isSelect;
    VfxBool    m_isDisable;
};


class VcpSelectCoreMenu : public VcpListMenu, public IVcpListMenuContentProvider
{

// Constructor / Destructor
public:
    VcpSelectCoreMenu() : 
        m_data(NULL),
        m_dataCount(0),
        m_bufferCount(0),
        m_type(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK)
        {}
// Override
protected:
    virtual void onInit();    
    virtual void onDeinit();
    virtual void onUpdate();
    
    // IVcpListMenuContentProvider
    virtual VfxBool getItemText(
            VfxU32 index,                    
            VcpListMenuFieldEnum fieldType,  
            VfxWString &text,                
            VcpListMenuTextColorEnum &color  
            );  

    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   // [IN] index of the item
        ) const;
    virtual VfxBool getItemIsDisabled(
        VfxU32 index       // [IN] the index of item
        ) const;

public:
    void addItem(const VcpSelectCoreData* item);
	void updateItem(const VcpSelectCoreData& item);

    virtual VfxBool getIsSelected(VfxS32 index);
    virtual VfxId getItemId(VfxS32 index);
    virtual void setIsDisableItem(VfxId id, VfxBool isDisabled);
    virtual VfxBool getIsDisableItem(VfxId id);
    void setType(VcpListMenuModeEnum type);
    virtual void update();
// Implementation
private:
    void onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState);
    void onTapped(VcpListMenu *sender, VfxU32 index);
    
// Signal
public:
VfxSignal2 <
        VfxObject *, // Sender
        VfxU32         // List item index
    > m_signalQuickSelected;
// Variable
private:

    VcpSelectCoreData **m_data;
    VfxS32 m_dataCount;
    VfxS32 m_bufferCount;
protected:
    VcpListMenuModeEnum m_type;	
};


/*****************************************************************************
 * Class VcpSelectPopup
 * VcpSelectPopup have three type : quick select, single select and multi select.
 * For quick select, the popup will disapear when user choose one item. For single
 * and multi select popup, the user should press ok make their final decision.
 * 
 * EXAMPLE
 * <code>
 *      VFX_OBJ_CREATE(m_selectPopup, VcpSelectPopup, this);
 *      m_selectPopup->setText(VFX_WSTR("call 2"));
 *      m_selectPopup->addItem('Viki', VFX_WSTR("Viki"));
 *      m_selectPopup->addItem('Juli', VFX_WSTR("Julie"));
 *      m_selectPopup->setAutoDestory(VFX_FALSE);
 *      m_selectPopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_SINGLE);
 *      m_selectPopup->m_signalPopupState.connect(this, &VtstRtSelectPopup::onPopupStateChanged);
 *      m_selectPopup->m_signalButtonClicked.connect(this, &VtstRtSelectPopup::onPopupButtonClicked);
 * </code>
 *****************************************************************************/ 
class VcpSelectPopup : public VfxBasePopup
{
// Constructor / Destructor
public:
    // <group DOM_SelectPopup_VcpSelectPopup_Constructor/Destructor>
	VcpSelectPopup();
	VcpSelectPopup(VcpSelectCoreMenu* radioMenu);
// Method
public:
    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // set title text
    void setText(
        const VfxWString &text          // [IN] text
        );
    
    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // add a new button. App can add unlimited buttons. but it should consider memory usage. 
    void addItem(
        VfxId id,                      // [IN] button id 
        const VfxWString &text,         // [IN] button text
        VfxBool isSelected = VFX_FALSE
        );

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // To Update the text for already existing item.
	void updateItem(VfxId id, const VfxWString &text);

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // get title text
    const VfxWString& getText() const
    {
        return m_textFrame->getString();
    }
    // set title text
    void setText(
        const VfxWChar* text           // [IN] text
        );
    
    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // add a new button. App can add unlimited buttons. but it should consider memory usage. 
    void addItem(
        VfxId id,                      // [IN] button id 
        const VfxWChar* text,         // [IN] button text
        VfxBool isSelected = VFX_FALSE
        );

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // To Update the text for already existing item.
	void updateItem(VfxId id, const VfxWChar* text);

     // set title text
    void setText(
        VfxResId text           // [IN] text
        );
    
    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // add a new button. App can add unlimited buttons. but it should consider memory usage. 
    void addItem(
        VfxId id,                      // [IN] button id 
        VfxResId text,         // [IN] button text
        VfxBool isSelected = VFX_FALSE
        );

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // To Update the text for already existing item.
	void updateItem(VfxId id, VfxResId text);

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // set title text alignment mode
    void setTextAlignMode(
        VfxTextFrame::AlignModeEnum value // [IN] text Alignment mode
        );

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // set tpye of select popup
    void setType(
        VcpSelectPopupTypeEnum type       // [IN] type
        );

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // get tpye of select popup
    VcpSelectPopupTypeEnum getType()
    {
        return m_type;
    }

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // get first selected index, return -1 if no found
    VfxS32 getFirstSeletedIndex();

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // get the next selected index after input index, return -1 if no found
    VfxS32 getNextSelectedIndex(
        VfxS32 index                    // [IN] index
        );

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // get Id by input index
    VfxId getIdbyIndex(
        VfxS32 index                    // [IN] index
        );

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // get first selected Id
    inline VfxId getFirstSeletedId()
    {
        return getIdbyIndex(getFirstSeletedIndex());
    }

    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // set disable a item or not
    void setIsDisableItem(VfxId id, VfxBool isDisable);
    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // get disable a item or not
    VfxBool getIsDisableItem(VfxId id);
    // <group DOM_SelectPopup_VcpSelectPopup_Method>
    // show method
	void show(VfxBool isAnim);
	// <group DOM_SelectPopup_VcpSelectPopup_Method>
    // set is allowed no select item in select popup
    // If true, then the Ok button will not be disalbed if no select
    void setIsAllowedNoSelect(
        VfxBool value                           // [IN] allowed no select or not
        )
    {
        m_isAllowedEmptySelect = value;
    }


// Override
protected:
    // <group DOM_SelectPopup_VcpSelectPopup_Override>
    virtual void onInit();
    // <group DOM_SelectPopup_VcpSelectPopup_Override>
    virtual void onUpdate();
    // <group DOM_SelectPopup_VcpSelectPopup_Override>
    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    // <group DOM_SelectPopup_VcpSelectPopup_Override>
    virtual void onEnter();
#if 0
/* under construction !*/
/* under construction !*/
#endif
    // <group DOM_SelectPopup_VcpSelectPopup_Override>
    virtual void onLeaveStack();
    // <group DOM_SelectPopup_VcpSelectPopup_Override>
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    );

    
// Implenmention
private:
    // <group DOM_SelectPopup_VcpSelectPopup_Implenmention>
    void onButtonClick(VfxObject* sender, VfxId id);
    // <group DOM_SelectPopup_VcpSelectPopup_Implenmention>
    void onSelectionChanged(VfxObject* sender, VfxU32 index);

// Event
public:
    // <group DOM_SelectPopup_VcpSelectPopup_Event>
    // This singal is invoked when button is clicked
    // void YourClass::onButtonClicked(VfxObject* sender, VfxId id)
    VfxSignal2 <
        VfxObject*,     // sender 
        VfxId           // id
    > m_signalButtonClicked;

// Variable    
protected:
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
  //  VfxFrame                        *m_backgroundTop;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
    VfxFrame                        *m_backgroundBottom;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
    VfxFrame                        *m_backgroundBottomImage;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
    VfxTextFrame                    *m_textFrame;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
    VcpSelectCoreMenu               *m_RadioMenu;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>  
    VfxS32                          m_itemCount;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
  //  VfxS32                          m_textHeight;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
   // VfxS32                          m_upRegionHeight;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
 //   VfxS32                          m_bottomRegionHeight;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
    VfxBool                         m_buttonPressed;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
    VcpSelectPopupTypeEnum          m_type;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
    VfxFrame                        *m_buttonPanel;
    // <group DOM_SelectPopup_VcpSelectPopup_Variable>
    VcpButton                       *m_button[2];
	// <group DOM_SelectPopup_VcpSelectPopup_Variable>
	VfxBool							m_isAllowedEmptySelect;
};
#endif /* __VCP_POPUP_H__ */

