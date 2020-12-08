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
 *  Vapp_notes_editor.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Source file for the class definition for the Notes application class
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

#include "MMI_features.h"

#ifndef __VAPP_NOTES_EDITOR_CPP__
#define __VAPP_NOTES_EDITOR_CPP__
#ifdef __MMI_NOTE_APP__
#include "vfx_uc_include.h" 
#include "vfx_mc_include.h" 
#include "vcp_include.h"
#include "vadp_mmi_frm.h"
#include "Vapp_notes_struct.h"
extern "C"
{
	#include "Vapp_notes_base.h"
}
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "Vapp_notes_editor.h"
//#include "ui_core\mvc\Vfx_frame.h"


extern "C"
{
    #include "GlobalResDef.h"
	//#include "Mmi_rp_fw_test1_def.h"
	#include "mmi_rp_vapp_notes_def.h"
	void save_current_edit_color(VfxId color);
	void mmi_get_rgb_color_for_notes(U8 color, U16* red ,U16* green, U16* blue);
	void vapp_notes_get_rgb_color_for_underline_in_editor(U8 color, U16* red, U16* green ,U16* blue);
	 
#ifndef __LOW_COST_SUPPORT_COMMON__
	U8 mmi_note_get_new_note_color(U8 operation);
#endif
	U16 mmi_note_get_color_selected_from_category_screen();
	U16 vapp_notes_get_current_editor_color_for_hilight();
	MMI_BOOL vapp_notes_list_get_item_edited_deleted_or_added(void);
	void vapp_notes_list_set_item_edited_deleted_or_added(MMI_BOOL set);
	void mmi_notes_save_handling_on_editor_back_key(void);
}

extern "C" VfxU16 g_list_in_search_mode;

VfxWChar editor_string[102] = {0};
#define NOTE_INFO_BAR_HEIGHT  25

/*code segment*/

VFX_IMPLEMENT_CLASS("VappNotesEditor", VappNotesEditor, VfxPage);

#ifndef __LOW_COST_SUPPORT_COMMON__
VFX_IMPLEMENT_CLASS("VappNotesPaperColorselection", VappNotesPaperColorselection, VfxBasePopup);
#endif

/*void VappNotesEditor::onCreateView()
{

}*/


void VappNotesEditor::onInit()
{
    VfxPage::onInit(); // call base class
	//setBgColor(VFX_COLOR_WHITE);
	VfxSize parentSize;
	     
	VFX_OBJ_CREATE(title_bar, VcpTitleBar, this);
    title_bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_NEW_NOTE)); //set title text
    setTopBar(title_bar);  

	VFX_OBJ_CREATE(edit_tool_bar,VcpToolBar,this);
	setBottomBar(edit_tool_bar);	
	edit_tool_bar->addItem(SAVE_BUTTON, VFX_WSTR_RES(STR_GLOBAL_SAVE), IMG_ID_VAPP_NOTES_EDIT_SAVE);	
#ifndef __LOW_COST_SUPPORT_COMMON__
	edit_tool_bar->addItem(BG_COLOR_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_PAPER_COLOR), IMG_ID_VAPP_NOTES_PAPER_COLOR);	
#endif	
	edit_tool_bar->addItem(DISCARD_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DISCARD), IMG_ID_VAPP_NOTES_CANCEL);	
	edit_tool_bar->m_signalButtonTap.connect(this, &VappNotesEditor::vapp_notes_editor_toolBarItemSelection);

	U16 red =0,green = 0,blue = 0;

	VFX_OBJ_CREATE(text_editor, VcpTextEditor , this);
	text_editor->setPos(0,0);	
   text_editor->disableBackground(VFX_TRUE);
   text_editor->setSize(getSize().width,getSize().height);
	text_editor->setMargins(VCP_NOTESAPP_EDIT_VIEW_MARGIN,0,VCP_NOTESAPP_EDIT_VIEW_MARGIN,0);
	text_editor->setUnderline(VFX_TRUE);
	text_editor->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
	 /*logic here for color of editor if message already exist then edit show editor as per notes color
		 other wise show the color for add for last saved notes color */
	  
	VFX_OBJ_CREATE(m_FuncFrame, VcpFunctionBar, this);	 
#ifndef __LOW_COST_SUPPORT_COMMON__
	m_FuncFrame->addItem(BG_COLOR_BUTTON, VFX_WSTR_RES(STR_ID_VAAP_NOTES_COLOR));
#endif
	m_FuncFrame->addItem(DISCARD_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DISCARD));
	m_FuncFrame->addItem(SAVE_BUTTON, VFX_WSTR_RES(STR_GLOBAL_SAVE));
	m_FuncFrame->setItemSpecial(SAVE_BUTTON);
	text_editor->setFunctionBar(m_FuncFrame);
	m_FuncFrame->m_signalButtonTap.connect(this,&VappNotesEditor::vapp_notes_editor_funcBarItemSelection);
	
	VfxU8 color;

	if(m_data == NULL)
	{
		title_bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_NEW_NOTE)); //set title text
		
	#ifndef __LOW_COST_SUPPORT_COMMON__
		color = mmi_note_get_new_note_color(MMI_NOTE_OP_ADD);
	#else
		color = NOTES_CATAEGORY_COLOR_YELLOW;
	#endif
		save_current_edit_color(color);
		
		mmi_get_rgb_color_for_notes(color, &red, &green ,&blue);
		   
		   text_editor->setBgColor(VfxColor(255, red, green, blue));
		    getMainScr()->setBgColor(VfxColor(255, red, green, blue));
		  
		/*already in category then add the note same as category color other wise take the last saved from main category*/
		vapp_notes_get_rgb_color_for_underline_in_editor(color, &red, &green ,&blue);
		text_editor->setColor(VCP_TEXT_UNDERLINE_COLOR,VfxColor(255, red, green, blue));
		   
		text_editor->setText(editor_string, MMI_MAX_NOTE_LEN);
		text_editor->hideCounter(VFX_TRUE);
		edit_tool_bar->setDisableItem(SAVE_BUTTON, VFX_TRUE);
		  
		m_FuncFrame->setDisableItem(SAVE_BUTTON,VFX_TRUE);
		 
		 
	}
	else
	{
		title_bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_EDIT_NOTE)); //set title text
	#ifndef __LOW_COST_SUPPORT_COMMON__		
		color = mmi_note_get_new_note_color(MMI_NOTE_OP_EDIT);
	#else
		color = NOTES_CATAEGORY_COLOR_YELLOW;
	#endif
	
	   mmi_get_rgb_color_for_notes(color, &red, &green ,&blue);
	   text_editor->setBgColor(VfxColor(255, red, green, blue));
	   
	   getMainScr()->setBgColor(VfxColor(255, red, green, blue));
		   
		vapp_notes_get_rgb_color_for_underline_in_editor(color, &red, &green ,&blue);
		text_editor->setColor(VCP_TEXT_UNDERLINE_COLOR,VfxColor(255, red, green, blue));
		text_editor->setText(m_data, 100);
		VfxS8 char_count = mmi_ucs2strlen((const char*) m_data);

		if (char_count < 95)
		{
			text_editor->hideCounter(VFX_TRUE);
		}
		else
		{
			text_editor->hideCounter(VFX_FALSE);
		}

	
	}

		text_editor->setMinLineHeight(VCP_NOTESAPP_EDITOR_LINE_GAP);
		text_editor->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
		//text_editor->setHint(VFX_WSTR_RES(STR_ID_VAPP_NOTES_EDIT_EMPTY_TEXT));
		//text_editor->disableBackground(VFX_TRUE);
		//text_editor->setBgColor(VfxColor(255, red, green, blue));
		text_editor->m_signalTextChanged.connect(this, &VappNotesEditor::vapp_notes_editor_onTextChanged);
}



		
		

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif




void VappNotesEditor::adjustImeResize(const VfxSize & size, VfxFrame * focusFrame)
{
	//text_editor->setSize(size.width,size.height-title_bar.getRect.MaxY());
	// title_bar;
	VfxSize  m_size = size;
	VFX_UNUSED(focusFrame);
	setSize(m_size.width,m_size.height);
}

void VappNotesEditor::onEnter(VfxBool isBackward)
{
	VfxPage::onEnter(isBackward);

}

void VappNotesEditor::onBack()
{
	VfxPage::onBack();

	U16 *string = text_editor->getText();

			

			if(mmi_ucs2strlen((S8*)string) == 0)
			{
					return;
			}
			else
			{
				vapp_notes_list_set_item_edited_deleted_or_added(MMI_TRUE);

				save_and_add_notes_to_list(string);
				mmi_notes_save_handling_on_editor_back_key();
			}


}



void VappNotesEditor::onUpdate()
{

}

#ifndef __LOW_COST_SUPPORT_COMMON__
void VappNotesPaperColorselection::onInit()
{
	VfxBasePopup::onInit();

	m_lineCount = 0;
	m_buttonCount = 0;
	
	VFX_OBJ_CREATE(m_backgroundTop, VfxFrame, this);
	setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	
	VFX_OBJ_CREATE(m_background, VfxFrame, this);
	
    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, m_backgroundTop);
    m_textFrame->setRect(0, 0, VCP_NOTESAPP_POPUP_TEXT_WIDTH, VCP_NOTESAPP_POPUP_UP_HEIGHT);
    m_textFrame->setAnchor(0.5,0.8);
    m_textFrame->setColor(VfxColor(255,21,21,21));
	VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_NOTESAPP_POPUP_TITLE_FONT);
    m_textFrame->setFont(fontDesc);
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    //m_textFrame->setMaxLines(4);  
    checkUpdate();


}
#endif  /*__LOW_COST_SUPPORT_COMMON__*/

void VappNotesEditor::vapp_notes_editor_funcBarItemSelection(VfxObject *obj, VfxId id)
{
	switch(id)
	{
	#ifndef __LOW_COST_SUPPORT_COMMON__
	case BG_COLOR_BUTTON:
			text_editor->deactivate();
			VappNotesEditor::vapp_notes_editor_category_button_handler(id);
			//vapp_notes_editor_paper_color_selected_from_func_bar(VFX_TRUE);
			from_funcbar = VFX_TRUE;
			break;
	#endif
	case DISCARD_BUTTON:
			VappNotesEditor::vapp_notes_editor_discard_button_handler(id);
		    break;
	case SAVE_BUTTON:
		   VappNotesEditor::vapp_notes_editor_save_button_handler(id);
		   break;

	default:
		break;
	}

}

void VappNotesEditor::vapp_notes_editor_toolBarItemSelection(VfxObject *obj, VfxId id)
{
	switch(id)
	{
	#ifndef __LOW_COST_SUPPORT_COMMON__
	case BG_COLOR_BUTTON:
			//vapp_notes_editor_paper_color_selected_from_func_bar(VFX_FALSE);
			from_funcbar = VFX_FALSE;
			VappNotesEditor::vapp_notes_editor_category_button_handler(id);
			break;
	#endif
	case DISCARD_BUTTON:
			VappNotesEditor::vapp_notes_editor_discard_button_handler(id);
		    break;
	case SAVE_BUTTON:
		   VappNotesEditor::vapp_notes_editor_save_button_handler(id);
		   break;

	default:
		break;
	}
}

void VappNotesEditor::vapp_notes_editor_onTextChanged(VcpTextEditor *editor)
{
	VfxS8 char_count = 0;
	
	VfxWChar *text_string = text_editor->getText();

	char_count = mmi_ucs2strlen((const char*) text_string);

	if(char_count)
	{
		edit_tool_bar->setDisableItem(SAVE_BUTTON, VFX_FALSE);
		m_FuncFrame->setDisableItem(SAVE_BUTTON,VFX_FALSE);
	}
	else
	{
		edit_tool_bar->setDisableItem(SAVE_BUTTON, VFX_TRUE);
		m_FuncFrame->setDisableItem(SAVE_BUTTON,VFX_TRUE);
	}

	if (char_count < MMI_MAX_NOTE_LEN - 5)
	{
		text_editor->hideCounter(VFX_TRUE);
	}
	else
	{
		text_editor->hideCounter(VFX_FALSE);
	}
	
}

void VappNotesEditor::vapp_notes_editor_discard_button_handler(VfxId id)
{ 
			
            getMainScr()->popPage();
            
   
}

void VappNotesEditor::vapp_notes_editor_save_button_handler(VfxId id)
{ 
			U16 *string = text_editor->getText();

			/*if text content is empty then show a popup*/

			if(mmi_ucs2strlen((S8*)string) == 0)
			{
					

					/*VcpConfirmPopup *alert;
					VFX_OBJ_CREATE(alert, VcpConfirmPopup, findScreen());
					alert->setText(VFX_WSTR("No content in note to save"));
					alert->setInfoType(VCP_POPUP_TYPE_FAILURE);
					alert->setAutoDestory(VFX_TRUE);
					alert->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
					alert->show(VFX_TRUE);*/
			}
			else
			{

				save_and_add_notes_to_list(string);
			
				getMainScr()->popPage(); /*pop the editor page*/
				vapp_notes_list_set_item_edited_deleted_or_added(MMI_TRUE);
				
			#ifndef __LOW_COST_SUPPORT_COMMON__
				if(mmi_note_get_color_selected_from_category_screen()) /*pop the back color list*/
				{
					getMainScr()->popPage(); /*to remoce the category page*/
					if(g_list_in_search_mode)
					{
                            g_list_in_search_mode = 0;
					} 
				}
			#endif
				/*set a global for list to update*/
			//	mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)(L"Saved"));
			}
   
}

#ifndef __LOW_COST_SUPPORT_COMMON__
void VappNotesEditor::vapp_notes_editor_category_button_handler(VfxId id)
{
		VappNotesPaperColorselection *PaperColor;
		U16 color = 0;
		VFX_OBJ_CREATE(PaperColor, VappNotesPaperColorselection, this);
		PaperColor->setAutoDestory(VFX_TRUE);
		PaperColor->vapp_notes_paper_color_popup_setTitle(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_PAPER_COLOR));

		color = vapp_notes_get_current_editor_color_for_hilight();
		if(color == NOTES_CATAEGORY_COLOR_WHITE)
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_WHITE, VFX_TRUE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_WHITE));
		}
		else
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_WHITE, VFX_FALSE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_WHITE));
		}
			
		if(color == NOTES_CATAEGORY_COLOR_BLUE)
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_BLUE, VFX_TRUE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_BLUE));
		}
		else
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_BLUE, VFX_FALSE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_BLUE));
		}
		
		if(color == NOTES_CATAEGORY_COLOR_GREEN)
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_GREEN, VFX_TRUE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_GREEN));
		}
		else
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_GREEN, VFX_FALSE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_GREEN));
		}
		if(color == NOTES_CATAEGORY_COLOR_YELLOW)
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_YELLOW, VFX_TRUE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_YELLOW));
		}
		else
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_YELLOW, VFX_FALSE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_YELLOW));
		}
		
		if(color == NOTES_CATAEGORY_COLOR_ORANGE)
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_ORANGE, VFX_TRUE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_ORANGE));
		}
		else
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_ORANGE, VFX_FALSE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_ORANGE));
		}


		if(color == NOTES_CATAEGORY_COLOR_RED)
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_RED, VFX_TRUE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_RED));
		}
		else
		{
			PaperColor->vapp_notes_paper_color_popup_AddImage(NOTES_CATAEGORY_COLOR_RED, VFX_FALSE, VfxImageSrc(IMG_ID_VAPP_NOTES_PAPER_COLOR_RED));
		}

		
		
		PaperColor->vapp_notes_paper_color_popup_AddCancelButton();
		//PaperColor->setcolorInfoType(VCP_POPUP_TYPE_QUESTION);
		PaperColor->m_signalButtonClicked.connect(this, &VappNotesEditor::vapp_notes_editor_edit_color_selection); //CHECK
		PaperColor->m_signalcallback.connect(this, &VappNotesEditor::vapp_notes_editor_edit_color_selection_back); //CHECK)
		PaperColor->show(VFX_TRUE);
		
}
void VappNotesPaperColorselection::vapp_notes_paper_color_popup_AddCancelButton()
{
	VFX_OBJ_CREATE(m_button_Cancel, VcpButton, m_background);
    m_button_Cancel->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
	//m_button_Cancel->changeVisual(VfxVisualFactory::create(VIS_ID_COMMAND_POPUP_BUTTON_CANCEL,m_button_Cancel));
	m_button_Cancel->setStyle(VCP_BUTTON_STYLE_GREY);
	VfxFontDesc btnfontDesc(30);
	btnfontDesc.effect = VFX_FE1_3;
	m_button_Cancel->setTextFont(btnfontDesc);
	m_button_Cancel->setTextColor(VfxColor(255,255,255,255));
    m_button_Cancel->setText(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_CANCEL));
    m_button_Cancel->setRect(VfxRect(VCP_NOTESAPP_POPUP_CANCEL_BUTTON_X, VCP_NOTESAPP_POPUP_CANCEL_BUTTON_Y, VCP_NOTESAPP_POPUP_CANCEL_BUTTON_WIDTH, VCP_NOTESAPP_POPUP_CANCEL_BUTTON_HEIGHT));
	m_bottomRegionHeight += VCP_NOTESAPP_POPUP_CANCEL_HEIGHT;
                                    
    m_button_Cancel->m_signalClicked.connect(this, &VappNotesPaperColorselection::vapp_notes_paper_color_popup_onButtonClick);
    m_button_Cancel->setId(12);
	checkUpdate();
}

VfxBool VappNotesPaperColorselection::onPenInput(VfxPenEvent &event)
{
    return VfxBasePopup::onPenInput(event);
}


VfxBool VappNotesPaperColorselection::onKeyInput(VfxKeyEvent &event)
{
	if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch (event.keyCode)
        {
         case VFX_KEY_CODE_BACK:
                leave(VFX_TRUE);
                m_signalcallback.postEmit(this, 15);
                return VFX_TRUE;   
         default:
                break;
         }
    }
    return VfxBasePopup::onKeyInput(event);
}


void VappNotesPaperColorselection::onEnter()
{
	VfxBasePopup::onEnter();
}


void VappNotesPaperColorselection::onExit()
{
   VfxBasePopup::onExit();
}




void VappNotesPaperColorselection::onPenInputOnOutside(VfxPenEvent &event)
{
    VfxBasePopup::onPenInputOnOutside(event);
}

void VappNotesPaperColorselection::vapp_notes_paper_color_popup_setTitle(const VfxWString &text)
{
    if (text.isNull())
    {
        m_hasTitle = VFX_FALSE;
    }
    else
    {
        m_textFrame->setString(text);
        m_textFrame->setColor(VFX_COLOR_RES(VCP_COL_POPUP_TITLE_FONT));
        m_hasTitle = VFX_TRUE;
    }
    checkUpdate();
}

void VappNotesPaperColorselection::vapp_notes_paper_color_popup_setText(const VfxWString &text)
{
    if (text.isNull())
    {
        m_hasCancelText = VFX_FALSE;
    }
    else
    {

    }
    checkUpdate();
}


void VappNotesPaperColorselection::onUpdate()
{
    if (m_hasTitle)
    {
            m_textFrame->setRect(0, 0, VCP_NOTESAPP_POPUP_TEXT_WIDTH,VCP_NOTESAPP_POPUP_UP_HEIGHT);
            m_textFrame->forceUpdate();
           // m_textHeight = m_textFrame->getSize().height;
			m_backgroundTop->setHidden(VFX_FALSE);
			m_upRegionHeight = VCP_NOTESAPP_POPUP_UP_HEIGHT;
			m_backgroundTop->setBounds(0,0,VCP_NOTESAPP_POPUP_TEXT_WIDTH,m_upRegionHeight);

			m_background->setPos(0,m_upRegionHeight);
			m_background->setBounds(0,0,VCP_NOTESAPP_POPUP_TEXT_WIDTH,m_bottomRegionHeight);
       // m_background->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND_BOTTOM));
		
    }
    else
    {
        m_backgroundTop->setHidden(VFX_TRUE);
        m_upRegionHeight = 0;
        m_background->setPos(0,m_upRegionHeight);
        m_background->setBounds(0,0,VCP_NOTESAPP_POPUP_TEXT_WIDTH,m_bottomRegionHeight);
        m_background->setImgContent(VfxImageSrc(VCP_IMG_POPUP_BACKGROUND));
		
}
    setBounds(0,0,VCP_NOTESAPP_POPUP_TEXT_WIDTH, m_upRegionHeight + m_bottomRegionHeight);
}
void VappNotesPaperColorselection::vapp_notes_paper_color_popup_onButtonClick(VfxObject* sender, VfxId id)
{
    VfxS32 i;

    for (i = 0; i < 6; i++)
    {
        if (m_button[i] == sender)
        {
            m_signalButtonClicked.postEmit(this, id);
            break;
        }
    }

	if(id == 12)
	{
            m_signalButtonClicked.postEmit(this, id);
	}
	leave(VFX_TRUE);
}


void VappNotesPaperColorselection::vapp_notes_paper_color_popup_AddImage(VfxId id, VfxBool is_highlighted, const VfxImageSrc &imgScr)
{
    if (m_buttonCount >=6)
    {
        return;
    }
	
    VfxS32 shift = VCP_COMMAND_POPUP_BUTTON_Y_SHIFT;
    if ( m_hasTitle )
    {
        shift = 0;
}
    


    VFX_OBJ_CREATE(m_button[m_buttonCount], VcpButton, m_background);
	
    m_button[m_buttonCount]->setImgContent(imgScr);
    m_button[m_buttonCount]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_button[m_buttonCount]->setIsAutoResized(VFX_FALSE);
	if(is_highlighted)
	{
		/*m_button[m_buttonCount]->setRect(VfxRect(
                                        VCP_NOTESAPP_POPUP_BUTTON_X + (m_buttonCount%3) * VCP_NOTESAPP_POPUP_BUTTON_WIDTH + (VCP_NOTESAPP_POPUP_BUTTON_GAP_H * (m_buttonCount%3) - VCP_NOTESAPP_POPUP_BUTTON_HILIGHT_MARGIN/2), 
                                        VCP_NOTESAPP_POPUP_BUTTON_Y + ((m_lineCount) * (VCP_NOTESAPP_POPUP_BUTTON_HEIGHT + VCP_NOTESAPP_POPUP_BUTTON_GAP_V) - VCP_NOTESAPP_POPUP_BUTTON_HILIGHT_MARGIN/2),
                                        VCP_NOTESAPP_POPUP_BUTTON_WIDTH + VCP_NOTESAPP_POPUP_BUTTON_HILIGHT_MARGIN, 
                                        VCP_NOTESAPP_POPUP_BUTTON_HEIGHT + VCP_NOTESAPP_POPUP_BUTTON_HILIGHT_MARGIN
                                     ));
		m_button[m_buttonCount]->setIsHighlighted(VFX_TRUE);*/
		m_button[m_buttonCount]->setImage(VcpStateImage(IMG_ID_VAPP_NOTES_PC_HILIGHT_PENCIL_MARK, IMG_ID_VAPP_NOTES_PC_HILIGHT_PENCIL_MARK, IMG_ID_VAPP_NOTES_PC_HILIGHT_PENCIL_MARK, IMG_ID_VAPP_NOTES_PC_HILIGHT_PENCIL_MARK));
		
	}

		m_button[m_buttonCount]->setRect(VfxRect(
                                        VCP_NOTESAPP_POPUP_BUTTON_X + (m_buttonCount%3) * VCP_NOTESAPP_POPUP_BUTTON_WIDTH + VCP_NOTESAPP_POPUP_BUTTON_GAP_H * (m_buttonCount%3), 
                                        VCP_NOTESAPP_POPUP_BUTTON_Y + (m_lineCount) * (VCP_NOTESAPP_POPUP_BUTTON_HEIGHT + VCP_NOTESAPP_POPUP_BUTTON_GAP_V) + shift,
                                        VCP_NOTESAPP_POPUP_BUTTON_WIDTH, 
                                        VCP_NOTESAPP_POPUP_BUTTON_HEIGHT
                                     ));


    m_button[m_buttonCount]->m_signalClicked.connect(this, &VappNotesPaperColorselection::vapp_notes_paper_color_popup_onButtonClick);
    m_button[m_buttonCount]->setId(id);

    switch (id)
    {
        case NOTES_CATAEGORY_COLOR_WHITE:
            m_button[m_buttonCount]->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_PAPER_COLOR_WHITE, IMG_ID_VAPP_NOTES_PAPER_COLOR_WHITE, IMG_ID_VAPP_NOTES_PAPER_COLOR_WHITE, IMG_ID_VAPP_NOTES_PAPER_COLOR_WHITE));
			break;

        case NOTES_CATAEGORY_COLOR_BLUE:
            m_button[m_buttonCount]->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_PAPER_COLOR_BLUE, IMG_ID_VAPP_NOTES_PAPER_COLOR_BLUE, IMG_ID_VAPP_NOTES_PAPER_COLOR_BLUE, IMG_ID_VAPP_NOTES_PAPER_COLOR_BLUE));
            break;

        case NOTES_CATAEGORY_COLOR_GREEN:
            m_button[m_buttonCount]->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_PAPER_COLOR_GREEN, IMG_ID_VAPP_NOTES_PAPER_COLOR_GREEN, IMG_ID_VAPP_NOTES_PAPER_COLOR_GREEN, IMG_ID_VAPP_NOTES_PAPER_COLOR_GREEN));
           break;

        case NOTES_CATAEGORY_COLOR_YELLOW:
            m_button[m_buttonCount]->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_PAPER_COLOR_YELLOW, IMG_ID_VAPP_NOTES_PAPER_COLOR_YELLOW, IMG_ID_VAPP_NOTES_PAPER_COLOR_YELLOW, IMG_ID_VAPP_NOTES_PAPER_COLOR_YELLOW));
            break;

		case NOTES_CATAEGORY_COLOR_ORANGE:
            m_button[m_buttonCount]->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_PAPER_COLOR_ORANGE, IMG_ID_VAPP_NOTES_PAPER_COLOR_ORANGE, IMG_ID_VAPP_NOTES_PAPER_COLOR_ORANGE, IMG_ID_VAPP_NOTES_PAPER_COLOR_ORANGE));
            break;

		case NOTES_CATAEGORY_COLOR_RED:
            m_button[m_buttonCount]->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_PAPER_COLOR_RED, IMG_ID_VAPP_NOTES_PAPER_COLOR_RED, IMG_ID_VAPP_NOTES_PAPER_COLOR_RED, IMG_ID_VAPP_NOTES_PAPER_COLOR_RED));
            break;

        default:
            VFX_ASSERT(0);
    }

    m_buttonCount ++;
	if (!(m_buttonCount % 3))
	{
		m_lineCount++;
	}

                             
   m_bottomRegionHeight = VCP_NOTESAPP_POPUP_BOTTOM_HEIGHT;
    checkUpdate();
}


void VappNotesEditor::vapp_notes_editor_edit_color_selection(VfxObject *obj, VfxId id)
{
	U16 red =0,green = 0,blue = 0;

	//leave(VFX_TRUE);
	//mmi_vapp_note_apply_editor_color(id);
	if(id != 12)
	{
		save_current_edit_color(id);
		mmi_get_rgb_color_for_notes(id, &red, &green ,&blue);
		text_editor->setBgColor(VfxColor(255, red, green, blue));
	 
		getMainScr()->setBgColor(VfxColor(255, red, green, blue));
	 
		vapp_notes_get_rgb_color_for_underline_in_editor(id, &red, &green ,&blue);
		text_editor->setColor(VCP_TEXT_UNDERLINE_COLOR,VfxColor(255, red, green, blue));
	 
		
		
		checkUpdate();
	}
	if(from_funcbar == VFX_TRUE)
	{
	text_editor->activate();
	}
	
}

void VappNotesEditor::vapp_notes_editor_edit_color_selection_back(VfxObject *obj, VfxId id)
{
	if(from_funcbar == VFX_TRUE)
	{
		text_editor->activate();
	}
	
}
#endif  /*__LOW_COST_SUPPORT_COMMON__*/


VfxBool VappNotesEditor::onKeyInput(VfxKeyEvent &event)
{
	U16 *string = text_editor->getText();

	if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        switch (event.keyCode)
        {
         case VFX_KEY_CODE_HOME:
			if(mmi_ucs2strlen((S8*)string) != 0)
			{
				save_and_add_notes_to_list(string);
			}
			break;                
         default:
                break;
}
    }

    return VfxPage::onKeyInput(event);
}


#endif  /* __MMI_NOTE_APP__*/
#endif /* __VAPP_NOTES_EDITOR_CPP__ */
