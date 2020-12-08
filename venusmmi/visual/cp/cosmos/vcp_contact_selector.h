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

/*******************************************************************************
 * Filename:
 * ---------
 *  vcp_contact_selector.h
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  contact selector class header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_CONTACT_SELECTOR_H__
#define __VCP_CONTACT_SELECTOR_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_include.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)
#define VCP_CONTACT_SELECTOR_LR_GAP              8
#define VCP_CONTACT_SELECTOR_LEFT_GAP            5
#define VCP_CONTACT_SELECTOR_RIGHT_GAP           5
#define VCP_CONTACT_SELECTOR_TOP_GAP             8
#define VCP_CONTACT_SELECTOR_BUTTOM_GAP          8
#define VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT    40
#define VCP_CONTACT_SELECTOR_INPUTBOX_WIDTH    250
#define VCP_CONTACT_SELECTOR_BUTTON_GAP          5
#define VCP_CONTACT_SELECTOR_BUTTON_HEIGHT      40
#define VCP_CONTACT_SELECTOR_BUTTON_WIDTH       40
#define VCP_CONTACT_SELECTOR_INPUTBOX_MAX_CHARS 10
#define VCP_CONTACT_SELECTOR_HINT_WIDTH         40
#define VCP_CONTACT_SELECTOR_CONTACT_GAP         5
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT     26
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MIN_WIDTH  20
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MAX_WIDTH 130
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_FONT_SZIE  18
#define VCP_CONTACT_SELECTOR_CONTACT_HINT_FONT_SZIE    16
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN      5
#define VCP_CONTACT_SELECTOR_CONTACT_DELETE_ICON_WIDTH 25
#define VCP_CONTACT_SELECTOR_MAX_LINE_NUM               2
#define VCP_CONTACT_SELECTOR_LINE_GAP                   8
#define VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH            30
#define VCP_CONTACT_SELECTOR_MORE_BTN_L_MARGIN          3
#define VCP_CONTACT_SELECTOR_MORE_BTN_R_MARGIN          6
#define VCP_CONTACT_SELECTOR_MORE_BTN_T_MARGIN          0
#define VCP_CONTACT_SELECTOR_MORE_BTN_B_MARGIN          0
#define VCP_CONTACT_SELECTOR_ICON_SHADOW                2
#elif defined(__MMI_MAINLCD_480X800__)
#define VCP_CONTACT_SELECTOR_LR_GAP             14
#define VCP_CONTACT_SELECTOR_LEFT_GAP            8
#define VCP_CONTACT_SELECTOR_RIGHT_GAP           8
#define VCP_CONTACT_SELECTOR_TOP_GAP            10
#define VCP_CONTACT_SELECTOR_BUTTOM_GAP         10
#define VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT    67
#define VCP_CONTACT_SELECTOR_INPUTBOX_WIDTH    250
#define VCP_CONTACT_SELECTOR_BUTTON_GAP          8
#define VCP_CONTACT_SELECTOR_BUTTON_HEIGHT      67
#define VCP_CONTACT_SELECTOR_BUTTON_WIDTH       67
#define VCP_CONTACT_SELECTOR_INPUTBOX_MAX_CHARS 10
#define VCP_CONTACT_SELECTOR_HINT_WIDTH         40
#define VCP_CONTACT_SELECTOR_CONTACT_GAP         8
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT     50
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MIN_WIDTH  20
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MAX_WIDTH 200
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_FONT_SZIE  32
#define VCP_CONTACT_SELECTOR_CONTACT_HINT_FONT_SZIE    30
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN      5
#define VCP_CONTACT_SELECTOR_CONTACT_DELETE_ICON_WIDTH 25
#define VCP_CONTACT_SELECTOR_MAX_LINE_NUM               2
#define VCP_CONTACT_SELECTOR_LINE_GAP                  10
#define VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH            50
#define VCP_CONTACT_SELECTOR_MORE_BTN_L_MARGIN          3
#define VCP_CONTACT_SELECTOR_MORE_BTN_R_MARGIN          6
#define VCP_CONTACT_SELECTOR_MORE_BTN_T_MARGIN          0
#define VCP_CONTACT_SELECTOR_MORE_BTN_B_MARGIN          0
#define VCP_CONTACT_SELECTOR_ICON_SHADOW                4
#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define VCP_CONTACT_SELECTOR_LR_GAP              5
#define VCP_CONTACT_SELECTOR_LEFT_GAP            5
#define VCP_CONTACT_SELECTOR_RIGHT_GAP           5
#define VCP_CONTACT_SELECTOR_TOP_GAP             5
#define VCP_CONTACT_SELECTOR_BUTTOM_GAP          5
#define VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT    40
#define VCP_CONTACT_SELECTOR_INPUTBOX_WIDTH    250
#define VCP_CONTACT_SELECTOR_BUTTON_GAP          5
#define VCP_CONTACT_SELECTOR_BUTTON_HEIGHT      40
#define VCP_CONTACT_SELECTOR_BUTTON_WIDTH       40
#define VCP_CONTACT_SELECTOR_INPUTBOX_MAX_CHARS 10
#define VCP_CONTACT_SELECTOR_HINT_WIDTH         40
#define VCP_CONTACT_SELECTOR_CONTACT_GAP         5
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT     26
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MIN_WIDTH  20
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MAX_WIDTH 130
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_FONT_SZIE  18
#define VCP_CONTACT_SELECTOR_CONTACT_HINT_FONT_SZIE    16
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN      5
#define VCP_CONTACT_SELECTOR_CONTACT_DELETE_ICON_WIDTH 25
#define VCP_CONTACT_SELECTOR_MAX_LINE_NUM               2
#define VCP_CONTACT_SELECTOR_LINE_GAP                   5
#define VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH            30
#define VCP_CONTACT_SELECTOR_MORE_BTN_L_MARGIN          3
#define VCP_CONTACT_SELECTOR_MORE_BTN_R_MARGIN          6
#define VCP_CONTACT_SELECTOR_MORE_BTN_T_MARGIN          0
#define VCP_CONTACT_SELECTOR_MORE_BTN_B_MARGIN          0
#define VCP_CONTACT_SELECTOR_ICON_SHADOW                2
#else
#define VCP_CONTACT_SELECTOR_LR_GAP             10
#define VCP_CONTACT_SELECTOR_LEFT_GAP            5
#define VCP_CONTACT_SELECTOR_RIGHT_GAP           5
#define VCP_CONTACT_SELECTOR_TOP_GAP             5
#define VCP_CONTACT_SELECTOR_BUTTOM_GAP          5
#define VCP_CONTACT_SELECTOR_INPUTBOX_HEIGHT    40
#define VCP_CONTACT_SELECTOR_INPUTBOX_WIDTH    250
#define VCP_CONTACT_SELECTOR_BUTTON_GAP          5
#define VCP_CONTACT_SELECTOR_BUTTON_HEIGHT      40
#define VCP_CONTACT_SELECTOR_BUTTON_WIDTH       40
#define VCP_CONTACT_SELECTOR_INPUTBOX_MAX_CHARS 10
#define VCP_CONTACT_SELECTOR_HINT_WIDTH         40
#define VCP_CONTACT_SELECTOR_CONTACT_GAP         5
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_HEIGHT     26
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MIN_WIDTH  20
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MAX_WIDTH 130
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_FONT_SZIE  18
#define VCP_CONTACT_SELECTOR_CONTACT_HINT_FONT_SZIE    16
#define VCP_CONTACT_SELECTOR_CONTACT_BUTTON_MARGIN      5
#define VCP_CONTACT_SELECTOR_CONTACT_DELETE_ICON_WIDTH 25
#define VCP_CONTACT_SELECTOR_MAX_LINE_NUM               2
#define VCP_CONTACT_SELECTOR_LINE_GAP                   5
#define VCP_CONTACT_SELECTOR_MORE_BTN_WIDTH            30
#define VCP_CONTACT_SELECTOR_MORE_BTN_L_MARGIN          3
#define VCP_CONTACT_SELECTOR_MORE_BTN_R_MARGIN          6
#define VCP_CONTACT_SELECTOR_MORE_BTN_T_MARGIN          0
#define VCP_CONTACT_SELECTOR_MORE_BTN_B_MARGIN          0
#define VCP_CONTACT_SELECTOR_ICON_SHADOW                2
#endif

#define VCP_CONTACT_SELECTOR_SEARCH_BTN_ID      0
#define VCP_CONTACT_SELECTOR_MORE_BTN_ID        1

// <group DOM_Editor_VcpContactSelector_Enum>
// the contact list changed enum
enum VcpContactChangedEnum
{
    // add contact to list
    VCP_CONTACT_CHANGED_ADD,
    // delete contact from list
    VCP_CONTACT_CHANGED_DELETE,
    // END of Enum
    VCP_CONTACT_CHANGED_END_OF_ENUM
};

class VcpContactEditor;

/***************************************************************************** 
 * Class VcpContact
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpContact is a class provide select contact function.
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpContact : public VfxBase
{

// Constructor / Destructor
public:
    // <group DOM_ContactSelector_VcpContact_Constructor/Destructor>
    VcpContact();

    VcpContact &operator=(const VcpContact &other);

    VfxBool operator==(const VcpContact &other) const;

    VcpContact* append(VcpContact* contact);

    VcpContact* getNext() { return m_next; }

// Method
public:
    // <group DOM_ContactSelector_VcpContact_Method>


// Override
public:

// Implementation
protected:


public:
    VfxWString m_name;
    VfxWString m_phoneNumber;
    VfxWString m_email;
    VcpContact *m_next;
};


/***************************************************************************** 
 * Class VcpContactSelector
 *****************************************************************************/

/*
 * DESCRIPTION
 *  VcpContactSelector is a class provide select contact function.
 * EXAMPLE
 * <code>
 *
 * </code>
 */
class VcpContactSelector : public VfxControl
{

// Constructor / Destructor
public:
    // <group DOM_ContactSelector_VcpContactSelector_Constructor/Destructor>
    VcpContactSelector();
    
// Method
public:
    // <group DOM_ContactSelector_VcpContactSelector_Method>
    // add contact
    VfxBool add(const VcpContact &contact);

    // <group DOM_ContactSelector_VcpContactSelector_Method>
    // add contact
    VfxBool add(VfxWString name, VfxWString phoneNumber, VfxWString email = VFX_WSTR_EMPTY);

    // <group DOM_ContactSelector_VcpContactSelector_Method>
    // remove contact
    VfxBool remove(const VcpContact &contact);

    // <group DOM_ContactSelector_VcpContactSelector_Method>
    // remove contact
    VfxBool remove(VfxS32 index);

    // <group DOM_ContactSelector_VcpContactSelector_Method>
    // set hint text
    void setHintText(const VfxWString &hint);

    // <group DOM_ContactSelector_VcpContactSelector_Method>
    // delete all contact
    void clear(void);

    // <group DOM_ContactSelector_VcpContactSelector_Method>
    // get contact list
    VcpContact *getContactList() { return m_contact; }

    // <group DOM_ContactSelector_VcpContactSelector_Method>
    // get contact count
    VfxS32 getContactCount(void) { return m_count; }

    // <group DOM_ContactSelector_VcpContactSelector_Method>
    // hide contact list
    void hideContact(VfxBool value);

    // <group DOM_ContactSelector_VcpContactSelector_Method>
    // get inputbox pointer
    VcpContactEditor *getInputbox() { return m_inputbox; }

// Signal
public:
    // <group DOM_ContactSelector_VcpContactSelector_Signal>
    // indicate the text content has been changed, usually DO search in phonebook
    VfxSignal2 <VcpContactSelector *, VfxWChar *> m_signalTextChanged;

    // <group DOM_ContactSelector_VcpContactSelector_Signal>
    // indicate the contact list changes
    VfxSignal2 <VcpContactSelector *, VcpContactChangedEnum> m_signalContactChanged;

    // <group DOM_ContactSelector_VcpContactSelector_Signal>
    // on contact search button clicked, usually DO go to phonebook
    VfxSignal0 m_signalSearchButtonClicked;

    // <group DOM_ContactSelector_VcpContactSelector_Signal>
    // on more button clicked
    VfxSignal1 <VcpContactSelector *> m_signalMoreButtonClicked;

// Override
public:
    virtual void onBoundsChanged(
        VfxFrame *frame,
        const VfxRect &rect);

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onUpdate();
    virtual VfxBool onPenInput(VfxPenEvent &event);

// Implementation
protected:
    // signal slot
    void onTextEditorActivated(VcpTextEditor *editor, VfxBool activated);
    void onTextChanged(VcpTextEditor *editor);
    void onButtonClick(VfxObject *obj, VfxId id);
    void onContactButtonClick(VfxObject* sender, VfxId id);

private:
    // inputbox
    VcpContactEditor *m_inputbox;
    VcpButton *m_button;
    VfxTextFrame* m_hintTextFrame;
    VfxWString m_hintText;
    VcpContact *m_contact;
    VcpButton **m_contactButton;
    VcpButton *m_moreButton;
    VfxS32 m_count;
    VfxS32 m_displayCount;
    VfxBool m_isContactHide;     // show contact in inputbox or below inputbox
    VfxBool m_isHideContactList; // when editor is active, show or hide contact list below inputbox
    VfxTextFrame *m_truncateText;
    VfxTextFrame *m_contactText; // display all contact in a text frame
    VfxS8 m_hiliteBtnIdx;
};


/***************************************************************************** 
 * Class VcpContactEditor
 *****************************************************************************/
class VcpContactEditor : public VcpTextEditor
{
public:
    virtual VfxBool onContainPoint(
        const VfxPoint &point       // [IN] the point in the coordinate of the frame
    ) const;

    void setContactRect(const VfxRect &rect) { m_rect = rect; }
    
private:
    VfxRect m_rect;
};

#endif /* __VCP_CONTACT_SELECTOR_H__ */
