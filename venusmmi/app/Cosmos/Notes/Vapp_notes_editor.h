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
 *  Vapp_notes_editor.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Header file for class declaration for Notes application
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/


#ifndef __VAPP_NOTES_EDITOR_H__
#define __VAPP_NOTES_EDITOR_H__

#ifdef __MMI_NOTE_APP__

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_text_editor.h"
//#define __LOW_COST_SUPPORT_COMMON__

class VappNotesEditor : public VfxPage
{
    VFX_DECLARE_CLASS(VappNotesEditor);
public:
	VcpTitleBar *title_bar;
	VcpTextEditor *text_editor;
	VappNotesEditor(VfxWChar *data = NULL)
	{
		m_data = data;
	}
	
// variables
private:
	
	enum {
		BG_COLOR_BUTTON = 1,
		DISCARD_BUTTON,
		SAVE_BUTTON
  	};
	
private:
	VfxWChar *m_data;
	VcpToolBar *edit_tool_bar;
	//VcpButton *button_bgcolor, *button_save, *button_discard; 
	VcpFunctionBar *m_FuncFrame;
	VfxBool from_funcbar;
 
//member functions

public:
		
     virtual void onInit();		 
	 //virtual void onCreateView();
	 virtual void onUpdate();
	 virtual void onEnter(VfxBool isBackward);
	 virtual void onBack();
	 virtual void adjustImeResize(const VfxSize &size, VfxFrame *focusFrame);
	 virtual VfxBool onKeyInput(VfxKeyEvent &event);
	/*Event handler for the buttons provided on the Editor screen*/
	void vapp_notes_editor_save_button_handler(VfxId id);
	void vapp_notes_editor_discard_button_handler(VfxId id);

#ifndef __LOW_COST_SUPPORT_COMMON__
	void vapp_notes_editor_category_button_handler(VfxId id);
        void vapp_notes_editor_edit_color_selection(VfxObject *obj, VfxId id);
	void vapp_notes_editor_edit_color_selection_back(VfxObject *obj, VfxId id);
#endif

	void vapp_notes_editor_onTextChanged(VcpTextEditor *editor);
	void vapp_notes_editor_funcBarItemSelection(VfxObject *obj, VfxId id);
	void vapp_notes_editor_toolBarItemSelection(VfxObject *obj, VfxId id);
	
	/*void vapp_notes_editor_paper_color_selected_from_func_bar(VfxBool m_value)
	{
		from_funcbar = m_value;
	}
	VfxBool vapp_notes_editor_get_paper_color_selected_from_funcbar()
	{
		return from_funcbar;
	}*/
	
};

#ifndef __LOW_COST_SUPPORT_COMMON__
class VappNotesPaperColorselection : public VfxBasePopup 
{
    VFX_DECLARE_CLASS(VappNotesPaperColorselection);

public:
    VfxSignal2 <
        VfxObject*,     // sender 
        VfxId           // id
    > m_signalButtonClicked;

VfxSignal2 <VfxObject *, VfxU32> m_signalcallback;

void vapp_notes_paper_color_popup_setText(const VfxWString &text);
void vapp_notes_paper_color_popup_setTitle(const VfxWString &text);
void vapp_notes_paper_color_popup_AddImage(VfxId id, VfxBool is_highlighted, const VfxImageSrc &imgScr);
void vapp_notes_paper_color_popup_onButtonClick(VfxObject* sender, VfxId id);
void vapp_notes_paper_color_popup_AddCancelButton();

private:
    VfxFrame                        *m_backgroundTop;
    VfxFrame                        *m_background;
    VfxFrame                        *m_icon;
    VfxTextFrame                    *m_textFrame;
    VcpPopupTypeEnum                m_infoType;
    VcpButton                       *m_button[6];
    VfxS32                          m_buttonCount;
    VfxBool                         m_hasTitle;
   // VfxBool                         m_hasIcon;
	VfxBool                         m_hasCancelText;
	VfxS32                         m_textCancelHeight;
	VcpButton                    *m_button_Cancel;
    VfxS32                          m_textHeight;
    VfxS32                          m_upRegionHeight;
    VfxS32                          m_bottomRegionHeight;
	VfxS32							m_lineCount;
protected:
     virtual void onInit();	
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual void onEnter();
    virtual void onExit();
    virtual void onUpdate();
    virtual void onPenInputOnOutside(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);


};
#endif   /*__LOW_COST_SUPPORT_COMMON__*/

#if defined(__MMI_MAINLCD_320X480__)

#define VCP_NOTESAPP_POPUP_TEXT_X_ICON           (82)
#define VCP_NOTESAPP_POPUP_TEXT_X                (5)
#define VCP_NOTESAPP_POPUP_TEXT_Y                (15)
#define VCP_NOTESAPP_POPUP_TEXT_WIDTH_ICON       (183)
#define VCP_NOTESAPP_POPUP_TEXT_WIDTH            (280)

#define VCP_NOTESAPP_POPUP_BUTTON_Y_SHIFT        (13)
#define VCP_NOTESAPP_POPUP_BUTTON_X              (24)
#define VCP_NOTESAPP_POPUP_BUTTON_Y              (7)
#define VCP_NOTESAPP_POPUP_BUTTON_GAP_H           (20)
#define VCP_NOTESAPP_POPUP_BUTTON_GAP_V           (13)
#define VCP_NOTESAPP_POPUP_BUTTON_WIDTH          (64)
#define VCP_NOTESAPP_POPUP_BUTTON_HEIGHT         (64)
#define VCP_NOTESAPP_POPUP_UP_HEIGHT         (49)
#define VCP_NOTESAPP_POPUP_BOTTOM_HEIGHT     (154)
#define VCP_NOTESAPP_POPUP_CANCEL_HEIGHT     (72)
#define VCP_NOTESAPP_EDIT_VIEW_MARGIN              15

#define VCP_NOTESAPP_POPUP_TITLE_FONT     (18)

#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_X     (10)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_Y     (165)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_WIDTH     (260)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_HEIGHT     (45)
#define VCP_NOTESAPP_POPUP_BUTTON_HILIGHT_MARGIN     (13)
#define VCP_NOTESAPP_EDITOR_LINE_GAP                  36
#endif




#if defined(__MMI_MAINLCD_480X800__)
#define VCP_NOTESAPP_POPUP_TEXT_WIDTH            (406)
#define VCP_NOTESAPP_POPUP_BUTTON_WIDTH          (94)
#define VCP_NOTESAPP_POPUP_BUTTON_HEIGHT         (94)

#define VCP_NOTESAPP_POPUP_BUTTON_X              (36)
#define VCP_NOTESAPP_POPUP_BUTTON_Y              (11)
#define VCP_NOTESAPP_POPUP_BUTTON_GAP_H           (27)
#define VCP_NOTESAPP_POPUP_BUTTON_GAP_V           (17)
#define VCP_NOTESAPP_POPUP_UP_HEIGHT             (83)
#define VCP_NOTESAPP_POPUP_BOTTOM_HEIGHT         (205)
#define VCP_NOTESAPP_POPUP_TITLE_FONT               (24)  /*not confirm yet*/
#define VCP_NOTESAPP_POPUP_BUTTON_HILIGHT_MARGIN     (17)
#define VCP_NOTESAPP_EDITOR_LINE_GAP                  60

#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_X     (35)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_Y     (225)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_WIDTH     (340)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_HEIGHT     (65)
#define VCP_NOTESAPP_POPUP_CANCEL_HEIGHT                (105)
#define VCP_NOTESAPP_EDIT_VIEW_MARGIN              15
#endif

#if defined(__MMI_MAINLCD_240X400__)
#define VCP_NOTESAPP_POPUP_TEXT_WIDTH            (207)
#define VCP_NOTESAPP_POPUP_BUTTON_WIDTH          (47)
#define VCP_NOTESAPP_POPUP_BUTTON_HEIGHT         (47)

#define VCP_NOTESAPP_POPUP_BUTTON_X              (20)
#define VCP_NOTESAPP_POPUP_BUTTON_Y              (5)
#define VCP_NOTESAPP_POPUP_BUTTON_GAP_H           (13)
#define VCP_NOTESAPP_POPUP_BUTTON_GAP_V           (9)
#define VCP_NOTESAPP_POPUP_UP_HEIGHT             (34)
#define VCP_NOTESAPP_POPUP_BOTTOM_HEIGHT         (130)
#define VCP_NOTESAPP_POPUP_TITLE_FONT               (15)  /*not confirm yet*/
#define VCP_NOTESAPP_POPUP_BUTTON_HILIGHT_MARGIN     (10)
#define VCP_NOTESAPP_EDITOR_LINE_GAP                  32

#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_X     (10)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_Y     (117)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_WIDTH     (187)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_HEIGHT     (35)
#define VCP_NOTESAPP_POPUP_CANCEL_HEIGHT                (42)
#define VCP_NOTESAPP_EDIT_VIEW_MARGIN              10
#endif

#if defined(__MMI_MAINLCD_240X320__)
#define VCP_NOTESAPP_POPUP_TEXT_WIDTH            (207)
#define VCP_NOTESAPP_POPUP_BUTTON_WIDTH          (47)
#define VCP_NOTESAPP_POPUP_BUTTON_HEIGHT         (47)

#define VCP_NOTESAPP_POPUP_BUTTON_X              (20)
#define VCP_NOTESAPP_POPUP_BUTTON_Y              (5)
#define VCP_NOTESAPP_POPUP_BUTTON_GAP_H           (13)
#define VCP_NOTESAPP_POPUP_BUTTON_GAP_V           (9)
#define VCP_NOTESAPP_POPUP_UP_HEIGHT             (34)
#define VCP_NOTESAPP_POPUP_BOTTOM_HEIGHT         (130)
#define VCP_NOTESAPP_POPUP_TITLE_FONT               (15)  /*not confirm yet*/
#define VCP_NOTESAPP_POPUP_BUTTON_HILIGHT_MARGIN     (10)
#define VCP_NOTESAPP_EDITOR_LINE_GAP                  32

#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_X     (10)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_Y     (117)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_WIDTH     (187)
#define VCP_NOTESAPP_POPUP_CANCEL_BUTTON_HEIGHT     (35)
#define VCP_NOTESAPP_POPUP_CANCEL_HEIGHT                (42)
#define VCP_NOTESAPP_EDIT_VIEW_MARGIN              10
#endif


#endif  /*__MMI_NOTE_APP__*/
#endif /* __VAPP_NOTES_EDITOR_H__ */



