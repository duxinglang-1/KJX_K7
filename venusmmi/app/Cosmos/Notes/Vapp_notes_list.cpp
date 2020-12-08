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
 *  Vapp_notes_list.cpp
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

#ifndef __VAPP_NOTES_LIST_CPP__
#define __VAPP_NOTES_LIST_CPP__
#ifdef __MMI_NOTE_APP__ 
 
#include "vcp_include.h"
#include "Vapp_notes_list.h"
#include "vadp_mmi_frm.h"
#include "Vapp_notes_struct.h"
#include "Vapp_notes_editor.h"
#include "mmi_rp_vapp_notes_def.h"
#include "vfx_adp_device.h"
#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif
extern "C"
{
    #include "GlobalResDef.h"
	#include "DateTimeGprot.h"
	#include "Wgui_categories_util.h"
	extern U8 applib_dt_sec_2_mytime(U32 utc_sec, applib_time_struct *result);
	extern void mmi_note_list_highlight_set_hdlr(S32 index);
	extern U16 venus_mmi_note_load_text(void);
	extern void mmi_note_app_single_note_delete(void);
	extern U16 mmi_note_sort_color_based_list(VfxId id);
	extern  void mmi_note_app_marked_list_delete(void);
	extern U16 mmi_notes_get_notes_count_from_category_selected_color(void);
	extern U16 mmi_note_get_color_selected_from_category_screen(void);
	extern void mmi_note_set_color_selected_from_category_screen(U16 color);
	extern U16 mmi_notes_get_total_num_of_marked_notes();
	extern U16 find_index_if_the_same_node_in_main_list(U16 index);
	void mmi_get_rgb_color_for_notes(U8 color, U16* red ,U16* green, U16* blue);
	 
	void mmi_app_notes_update_note_count_by_color(VfxU16 color);
	U16 mmi_notes_get_notes_count_from_category_selected_color_ext(U16 color);
	U16 mmi_vapp_notes_search_text_in_notes_list(WCHAR* string);
	U16 vapp_notes_get_searched_count(void);
	U16 vapp_notes_set_searched_count(U16 k);
    MMI_BOOL vapp_notes_list_get_item_edited_deleted_or_added(void);
	void vapp_notes_list_set_item_edited_deleted_or_added(MMI_BOOL);
}


VfxU16 g_current_selected_frame = 0;
extern "C" VfxU16 g_list_in_search_mode;
VfxU16 g_list_in_mark_delete_mode = 0;
VfxU16 notes_view_through_search = 0;
extern "C" venus_mmi_note_list_struct g_venus_mmi_note_cntx;
extern "C" venus_mmi_note_edit_struct g_venus_note_edit_cntx;
extern "C" venus_mmi_note_mark_list_struct g_venus_note_mark_cntx;
extern "C" U16 g_sort_list[];
extern "C" U8 category_list_node_selected;
extern VfxId page_id;
extern "C" VfxU16 g_search_sort_list[MMI_APP_NOTE_MAX_ITEM];
/*code segment*/

VFX_IMPLEMENT_CLASS("VappNotesPage", VappNotesPage, VfxPage);
#ifndef __LOW_COST_SUPPORT_COMMON__
VFX_IMPLEMENT_CLASS("VappNotesCategoryView", VappNotesCategoryView, VfxPage);
#endif

void VappNotesPage::onInit()
{

    VfxPage::onInit(); 
	/*
	setAlignParent(
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE, 
                        VFX_FRAME_ALIGNER_MODE_SIDE);*/
   // setBgColor(VFX_COLOR_WHITE);	

	VFX_OBJ_CREATE(title_bar, VcpTitleBar, this);

	setTopBar(title_bar);

	VFX_OBJ_CREATE(tool_bar,VcpToolBar,this);
	setBottomBar(tool_bar);	
	tool_bar->addItem(ADD_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_ADD_NOTE), IMG_ID_VAPP_NOTES_ADD_NEW_NOTE);		
#ifndef __LOW_COST_SUPPORT_COMMON__
	tool_bar->addItem(CATEGORY_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_CATEGORY), IMG_ID_VAPP_NOTES_CATEGORY);	
#endif	
	tool_bar->addItem(LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);	
	tool_bar->addItem(SEARCH_BUTTON, VFX_WSTR_RES(STR_GLOBAL_SEARCH), IMG_ID_VAPP_NOTES_SEARCH);	
	tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);

	setTopbarTitle();
	
	if(m_color)
	 {
		 mmi_note_sort_color_based_list(m_color);
       	}

	if(mmi_notes_get_notes_count_from_category_selected_color_ext(m_color) == 0)
	{	   		
	
	#ifndef __LOW_COST_SUPPORT_COMMON__
		if(m_color)
		{
			tool_bar->setDisableItem(CATEGORY_BUTTON, VFX_FALSE);
		}
		else
		{
			tool_bar->setDisableItem(CATEGORY_BUTTON, VFX_TRUE);
		}
	#endif		
		tool_bar->setDisableItem(SEARCH_BUTTON, VFX_TRUE);
		tool_bar->setDisableItem(LIST_DELETE_BUTTON, VFX_TRUE);
		
	}
		
		VFX_OBJ_CREATE(frame_top, VfxFrame, this);
		frame_top->setPos(0, 0);	 
	 	frame_top->setSize(LCD_WIDTH,TOP_BAR_HEIGHT);  

		
		VFX_OBJ_CREATE(listMenu, VcpListMenu, this);
		listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM); 
		listMenu->setContentProvider(this); 	
		VfxSize parentSize = this->getSize();
		listMenu->setPos(NOTES_APP_LIST_START_GAP_X,  TOP_BAR_HEIGHT + 1);		
		listMenu->setSize(parentSize.width-NOTES_APP_LIST_START_GAP_X-NOTES_APP_LIST_END_GAP_X,parentSize.height-TOP_BAR_HEIGHT);
		//listMenu->setSize(LCD_WIDTH-NOTES_APP_LIST_START_GAP_X-NOTES_APP_LIST_END_GAP_X, tool_bar->getRect().getMinY() -2*TOP_BAR_HEIGHT- 41);
		listMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
	
		listMenu->setItemHeight(NOTES_APP_LIST_ITEM_HEIGHT); 
		listMenu->setItemSeparatorHidden(VFX_TRUE);
		listMenu->setItemHighlightHidden(VFX_TRUE);
		listMenu->m_signalItemTapped.connect(this, &VappNotesPage::vapp_notes_page_onSelectionitemtapped);
		listMenu->m_signalItemLongTapped.connect(this, &VappNotesPage::vapp_notes_page_onSelectionItemLongTapped);
		
		VfxFrame *frame_bottom;		
		VFX_OBJ_CREATE(frame_bottom, VfxFrame, this);
		frame_bottom->setPos(0, listMenu->getRect().getMaxY() +1);	 
		frame_bottom->setSize(LCD_WIDTH,TOP_BAR_HEIGHT);  

		listMenu->m_signalItemSelectionStateChanged.connect(this, &VappNotesPage::vapp_notes_page_onSelectionChanged);
    	
}

void VappNotesPage::setTopbarTitle()
{
	VfxWString title1,hint;
#ifndef __LOW_COST_SUPPORT_COMMON__
	if(m_color)
	 {
		 mmi_note_sort_color_based_list(m_color);
		switch(m_color)
		{
			case NOTES_CATAEGORY_COLOR_WHITE:
					title1 = VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_WHITE);
					break;
			case NOTES_CATAEGORY_COLOR_BLUE:
					title1 = VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_BLUE);
					break;
			case NOTES_CATAEGORY_COLOR_GREEN:
					title1 = VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_GREEN);
					break;
			case NOTES_CATAEGORY_COLOR_YELLOW:
					title1 = VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_YELLOW);
					break;
			case NOTES_CATAEGORY_COLOR_ORANGE:
					title1 = VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_ORANGE);
					break;
			case NOTES_CATAEGORY_COLOR_RED:
					title1 = VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_RED);
					break;
			default:
				break;
		}
		hint = VfxWString().format("(%d)",mmi_notes_get_notes_count_from_category_selected_color());
		title1 += hint;
		title_bar->setTitle(title1);
		 
	 }
	else
#endif  /*__LOW_COST_SUPPORT_COMMON__*/
	{
		title1 = VFX_WSTR_RES(STR_ID_VAPP_NOTES_APP_TITLE);		
		mmi_note_set_color_selected_from_category_screen(0);
		hint = VfxWString().format("(%d/%d)",mmi_notes_get_notes_count_from_category_selected_color() ,MMI_MAX_NOTE_ITEM);
		title1 += hint;
		title_bar->setTitle(title1);
	}

}



void VappNotesPage::onEnter(VfxBool isBackward)
{
		VfxPage::onEnter(isBackward);
		setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    //getMainScr()->setImgContent(VfxImageSrc());
	getMainScr()->setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
	

	if(isBackward == VFX_TRUE)
	{
		if(listMenu)
		{
			if(listMenu->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION)
			{
				return;
			}
		}
		if(g_list_in_search_mode > 0)
		{
			//if( mmi_note_get_color_selected_from_category_screen() == 0)
			//{
			 vapp_notes_page_onSearchTextChanged(search_editor);
			//}
			return;
		}
		if(notes_view_through_search)
		{
		    
            listMenu->disableSearchBar();
			listMenu->resetAllItems(VFX_TRUE);
			notes_view_through_search = 0;
		}
			
		if(tool_bar == NULL)
		{
				VFX_OBJ_CREATE(tool_bar,VcpToolBar,this);
				setBottomBar(tool_bar);	
				tool_bar->addItem(ADD_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_ADD_NOTE), IMG_ID_VAPP_NOTES_ADD_NEW_NOTE);					
			#ifndef __LOW_COST_SUPPORT_COMMON__
				tool_bar->addItem(CATEGORY_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_CATEGORY), IMG_ID_VAPP_NOTES_CATEGORY);	
			#endif			
				tool_bar->addItem(LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);	
				tool_bar->addItem(SEARCH_BUTTON, VFX_WSTR_RES(STR_GLOBAL_SEARCH), IMG_ID_VAPP_NOTES_SEARCH);	
				tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);
		}
		setTopbarTitle();

		if(vapp_notes_list_get_item_edited_deleted_or_added())
		{
		   updateToolBar();
			}
		if(!m_color)
		{
			vapp_notes_list_set_item_edited_deleted_or_added(MMI_FALSE);
		}
	#ifndef __LOW_COST_SUPPORT_COMMON__		
		if(m_category_new)
		{
    		updateToolBar();
		}
		m_category_new = 0;
	#endif
	}
	}
			
void VappNotesPage::updateToolBar()
{
  if(!tool_bar) return;
			if(mmi_notes_get_notes_count_from_category_selected_color_ext(m_color) == 0)
			{
					
				#ifndef __LOW_COST_SUPPORT_COMMON__
					if(m_color)
					{
						tool_bar->setDisableItem(CATEGORY_BUTTON, VFX_FALSE);
					}
					else
					{
						tool_bar->setDisableItem(CATEGORY_BUTTON, VFX_TRUE);
					}
				#endif  /*__LOW_COST_SUPPORT_COMMON__*/
					tool_bar->setDisableItem(SEARCH_BUTTON, VFX_TRUE);
					tool_bar->setDisableItem(LIST_DELETE_BUTTON, VFX_TRUE);
					listMenu->resetAllItems(VFX_TRUE);
			}
			else
			{
				 #ifndef __LOW_COST_SUPPORT_COMMON__
					tool_bar->setDisableItem(CATEGORY_BUTTON, VFX_FALSE);
		         #endif
					tool_bar->setDisableItem(SEARCH_BUTTON, VFX_FALSE);
					tool_bar->setDisableItem(LIST_DELETE_BUTTON, VFX_FALSE);
					listMenu->resetAllItems(VFX_TRUE);
			}
}
	



VFX_IMPLEMENT_CLASS("VappNotesPageviewer", VappNotesPageviewer, VfxPage);

void VappNotesPage::vapp_notes_page_onSelectionitemtapped(VcpListMenu *menu, VfxU32 index)
{
	VappNotesPageviewer *pageview;

	mmi_note_list_highlight_set_hdlr(index);
	//if(g_list_in_search_mode > 0)
	//{
		//g_list_in_search_mode = 0;
		//notes_view_through_search = 1;
		//listMenu->disableSearchBar();
           /*for performance issue*/
	
		/*if(tool_bar == NULL)
		{
			VFX_OBJ_CREATE(tool_bar,VcpToolBar,this);
			setBottomBar(tool_bar);	
			tool_bar->addItem(ADD_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_ADD_NOTE), IMG_ID_VAPP_NOTES_ADD_NEW_NOTE);	
			tool_bar->addItem(CATEGORY_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_CATEGORY), IMG_ID_VAPP_NOTES_CATEGORY);	
			tool_bar->addItem(LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);	
			tool_bar->addItem(SEARCH_BUTTON, VFX_WSTR_RES(STR_GLOBAL_SEARCH), IMG_ID_VAPP_NOTES_SEARCH);	
			tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);
		}*/
	//}

	VFX_OBJ_CREATE(pageview, VappNotesPageviewer, getMainScr());	
	getMainScr()->pushPage(0, pageview);
	
}	

void VappNotesPage::vapp_notes_page_onSelectionItemLongTapped(VcpListMenu *menu, VfxU32 index)
{

	vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);
	mmi_note_list_highlight_set_hdlr(index);
	venus_mmi_note_load_text();


	VcpMenuPopup *context;
	VfxWString title1;
    VFX_OBJ_CREATE(context, VcpMenuPopup, this);
	title1.loadFromMem((VfxWChar*)g_venus_note_edit_cntx.curr_edit);
    context->setTitle(title1);

	
	context->addItem(CNTXT_EDIT_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_EDIT));
	context->addItem(CNTXT_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE));

	context->m_signalMenuCallback.connect(this, &VappNotesPage::vapp_notes_page_OptionPopup_cntx);
    context->showMenu();


}



void VappNotesPage::vapp_notes_page_OptionPopup_cntx(VcpMenuPopup * menu,  VcpMenuPopupEventEnum event, VcpMenuPopupItem * item)
{
	if (event == VCP_MENU_POPUP_EVENT_ITEM_SELECTED)
	{
		switch (item->getId())
        {
			case CNTXT_DELETE_BUTTON:
				{
					VcpConfirmPopup *deleteConfirm;
					VFX_OBJ_CREATE(deleteConfirm, VcpConfirmPopup, findScreen());

					deleteConfirm->setText(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_DELETE_NOTE_ASK));
					deleteConfirm->setInfoType(VCP_POPUP_TYPE_WARNING);

					deleteConfirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
					deleteConfirm->setCustomButton(
					VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE),
					VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_CANCEL),
					VCP_POPUP_BUTTON_TYPE_WARNING,
					VCP_POPUP_BUTTON_TYPE_CANCEL);
					deleteConfirm->show(VFX_TRUE);
					deleteConfirm->m_signalButtonClicked.connect(this,&VappNotesPage::vapp_notes_page_OptionDeleteconfirm);
				}

				break;
			case CNTXT_EDIT_BUTTON:
				{
					VappNotesEditor *notes_editor;
					VfxWString txt;
					if(g_list_in_search_mode > 0)
					{
						g_list_in_search_mode = 0;
						listMenu->disableSearchBar();
					}
					VFX_OBJ_CREATE_EX(notes_editor, VappNotesEditor, getMainScr(),((VfxWChar*)&g_venus_note_edit_cntx.curr_edit)); 
						
					getMainScr()->pushPage(0, notes_editor);
				}
				break;
			default:
				break;

		}

	}
    

}


void VappNotesPage::vapp_notes_page_OptionDeleteconfirm(VfxObject *obj, VfxId id)
{

	if(id == VCP_CONFIRM_POPUP_BUTTON_USER_1 || id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
	{
					if(g_list_in_search_mode > 0)
					{
						g_list_in_search_mode = 0;
						listMenu->disableSearchBar();
						/*add the toolbar here as we remove the tollbar in searchbar*/
						if(tool_bar == NULL)
						{
							VFX_OBJ_CREATE(tool_bar,VcpToolBar,this);
							setBottomBar(tool_bar);	
							tool_bar->addItem(ADD_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_ADD_NOTE), IMG_ID_VAPP_NOTES_ADD_NEW_NOTE);								
					     #ifndef __LOW_COST_SUPPORT_COMMON__
							tool_bar->addItem(CATEGORY_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_CATEGORY), IMG_ID_VAPP_NOTES_CATEGORY);	
					     #endif
							tool_bar->addItem(LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);	
							tool_bar->addItem(SEARCH_BUTTON, VFX_WSTR_RES(STR_GLOBAL_SEARCH), IMG_ID_VAPP_NOTES_SEARCH);	
							tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);
						}
					}
			if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
			{
					mmi_note_app_single_note_delete();
					vapp_notes_list_set_item_edited_deleted_or_added(MMI_TRUE);
			}
			
					if(mmi_note_get_color_selected_from_category_screen())
					{
						getMainScr()->popPage(); /*deleting the category list screen*/
					}
					/*remove previous context if any*/
					listMenu->resetAllItems(VFX_TRUE);
					/*Amit*/
		    	VfxWString hint, title1;
					title1 = VFX_WSTR_RES(STR_ID_VAPP_NOTES_APP_TITLE);
					mmi_note_set_color_selected_from_category_screen(0);
					hint = VfxWString().format("(%d/%d)",mmi_notes_get_notes_count_from_category_selected_color() ,MMI_MAX_NOTE_ITEM);
					title1 += hint;
					title_bar->setTitle(title1);


		if(g_venus_mmi_note_cntx.item_num == 0)	
		{
			tool_bar->setDisableItem(LIST_DELETE_BUTTON, VFX_TRUE);
		#ifndef __LOW_COST_SUPPORT_COMMON__
			tool_bar->setDisableItem(CATEGORY_BUTTON, VFX_TRUE);
    #endif
			tool_bar->setDisableItem(SEARCH_BUTTON, VFX_TRUE);
		}
					
	}
	
}

void VappNotesPageviewer::vapp_notes_viewer_OptionDeleteconfirm(VfxObject *obj, VfxId id)
{

	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		getMainScr()->popPage(); /*deleting the viewer screen*/
		vapp_notes_list_set_item_edited_deleted_or_added(MMI_TRUE);
		if (mmi_note_get_color_selected_from_category_screen())
		{
			getMainScr()->popPage(); /*deleting the category list screen*/
			if(g_list_in_search_mode)
			{
                g_list_in_search_mode = 0;
			}
		}
		mmi_note_app_single_note_delete();
	}
	//else if(id == 200)
	//{
		/*code here for Cancel delete as this is the auto destro so no need to take actions*/

	//}

}



VfxBool VappNotesPageviewer::onKeyInput(VfxKeyEvent &event)
{
  
		if (event.type == VFX_KEY_EVENT_TYPE_DOWN||
		 event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS ||
		 event.type == VFX_KEY_EVENT_TYPE_REPEAT)
    {
        switch (event.keyCode)
        {
			case VFX_KEY_CODE_ARROW_RIGHT:
			{
				 if(g_list_in_search_mode != 0)
	   	          {
	                return VFX_TRUE; 
	               }
				if(mmi_notes_get_notes_count_from_category_selected_color() != 1)
				{
					 #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
					#endif
					button_next->setIsEffect(VFX_TRUE);
					button_next->setEffectRatio(1.5F);
					button_next->setEffectOffset(VfxPoint(0,NOTES_APP_VIEW_PAGE_VIEW_OFFSET));
					button_next->setState(VCP_IMAGE_BUTTON_STATE_PRESSED);
					VappNotesPageviewer::vapp_notes_viewer_next_button_handler(NULL, 0);
				}
				return VFX_TRUE;  
			}
			
			case VFX_KEY_CODE_ARROW_LEFT:
        	{
				if (mmi_notes_get_notes_count_from_category_selected_color() != 1)
				{
				  if (g_list_in_search_mode != 0)
	   	          {
	                return VFX_TRUE; 
	               }
				#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
				button_previous->setIsEffect(VFX_TRUE);
				button_previous->setEffectRatio(1.5F);
				button_previous->setEffectOffset(VfxPoint(0,NOTES_APP_VIEW_PAGE_VIEW_OFFSET));
				button_previous->setState(VCP_IMAGE_BUTTON_STATE_PRESSED);
				VappNotesPageviewer::vapp_notes_viewer_prev_button_handler(NULL, 0);		
				}
			   return VFX_TRUE;        
        	}
     
			default:
                break;
		}
    }
    if (event.type == VFX_KEY_EVENT_TYPE_UP)
    {
		switch (event.keyCode)
        {
			case VFX_KEY_CODE_ARROW_RIGHT:
			{
			    if (g_list_in_search_mode != 0)
		        {
	               return VFX_TRUE; 
	            }
				if (mmi_notes_get_notes_count_from_category_selected_color() != 1)
				{
				   button_next->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
				}
				return VFX_TRUE;  
			}
			
			case VFX_KEY_CODE_ARROW_LEFT:
			{
				if (g_list_in_search_mode != 0)
	                {
                  return VFX_TRUE; 
                 }
				if (mmi_notes_get_notes_count_from_category_selected_color() != 1)
				{
				button_previous->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
				}
			 
				return VFX_TRUE;           
			}
			      
			default:
                break;
		}
    }

    return VfxPage::onKeyInput(event);
}

void VappNotesPageviewer::onInit()
{
	VfxPage::onInit(); // call base class	
	//setBgColor(VFX_COLOR_WHITE);

	/*top frame for buttons - Previous and Next*/
	VfxSize parentSize;

	if(tool_bar)
	{
		VFX_OBJ_CLOSE(tool_bar);
		tool_bar = NULL;
	}
	if(button_next)
	{
		VFX_OBJ_CLOSE(button_next);
		button_next = NULL;
	}
	if(button_previous)
	{
		VFX_OBJ_CLOSE(button_previous);
		button_previous = NULL;
	}
	if(top_button_frame)
	{
		VFX_OBJ_CLOSE(top_button_frame);
		top_button_frame = NULL;
	}
	
	
	VFX_OBJ_CREATE(top_button_frame, VfxFrame, this);
	top_button_frame->setPos(0,0);  
	top_button_frame->setSize(LCD_WIDTH, NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT_TEMP);  
	//top_button_frame->setBgColor(VFX_COLOR_WHITE); 	
	top_button_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_VIEW_TITLE_BG));
	top_button_frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	//top_button_frame->setBorderColor(VFX_COLOR_BLACK);	
	
	if((mmi_notes_get_notes_count_from_category_selected_color() != 1)&&(g_list_in_search_mode == 0))
	{
	
	
		VFX_OBJ_CREATE(button_previous, VcpImageButton, top_button_frame);	
		//button_previous->setStyle(VCP_BUTTON_STYLE_DEFAULT);
		//button_previous->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
		//button_previous->setImage(VcpStateImage(IMG_ID_VAPP_NOTES_LEFT_ARROW));
		//button_previous->setRect(VfxRect(NOTES_APP_VIEW_PAGE_PREV_BUTTON_X, NOTES_APP_VIEW_PAGE_PREV_BUTTON_Y, NOTES_APP_VIEW_PAGE_PREV_BUTTON_WIDTH, NOTES_APP_VIEW_PAGE_PREV_BUTTON_HEIGHT)); 
		button_previous->setImage(
					VcpStateImage(
						IMG_ID_VAPP_NOTES_VIEW_PREVIOUS_ITEM_GLOBAL,
						IMG_ID_VAPP_NOTES_VIEW_PREVIOUS_ITEM_GLOBAL,
						IMG_ID_VAPP_NOTES_VIEW_PREVIOUS_ITEM_GLOBAL,
						IMG_ID_VAPP_NOTES_VIEW_PREVIOUS_ITEM_GLOBAL));
	button_previous->setRect(VfxRect(NOTES_APP_VIEW_PAGE_PREV_BUTTON_X, NOTES_APP_VIEW_PAGE_PREV_BUTTON_Y, NOTES_APP_VIEW_PAGE_PREV_BUTTON_WIDTH, NOTES_APP_VIEW_PAGE_PREV_BUTTON_HEIGHT)); 
		//button_previous->setIsStretchMode(VFX_TRUE);
		button_previous->setIsEffect(VFX_TRUE);
		 button_previous->setEffectRatio(1.5F);
		 button_previous->setEffectOffset(VfxPoint(0,NOTES_APP_VIEW_PAGE_VIEW_OFFSET));
	button_previous->m_signalClicked.connect(this, &VappNotesPageviewer::vapp_notes_viewer_prev_button_handler);

		VFX_OBJ_CREATE(button_next, VcpImageButton, top_button_frame);	
		//button_next->setStyle(VCP_BUTTON_STYLE_DEFAULT);
		//button_next->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
		//button_next->setImage(VcpStateImage(IMG_ID_VAPP_NOTES_RIGHT_ARROW));
		button_next->setImage(
					VcpStateImage(
						IMG_ID_VAPP_NOTES_VIEW_NEXT_ITEM_GLOBAL,
						IMG_ID_VAPP_NOTES_VIEW_NEXT_ITEM_GLOBAL,
						IMG_ID_VAPP_NOTES_VIEW_NEXT_ITEM_GLOBAL,
						IMG_ID_VAPP_NOTES_VIEW_NEXT_ITEM_GLOBAL));
	button_next->setRect(VfxRect(LCD_WIDTH - NOTES_APP_VIEW_PAGE_PREV_BUTTON_WIDTH-NOTES_APP_VIEW_PAGE_PREV_BUTTON_X, NOTES_APP_VIEW_PAGE_PREV_BUTTON_Y , NOTES_APP_VIEW_PAGE_PREV_BUTTON_WIDTH, NOTES_APP_VIEW_PAGE_PREV_BUTTON_HEIGHT )); /*x ccordinate, y coordinate, width, heigth*/
		//button_next->setIsStretchMode(VFX_TRUE);
	 button_next->setIsEffect(VFX_TRUE);
	 button_next->setEffectRatio(1.5F);
	 button_next->setEffectOffset(VfxPoint(0,NOTES_APP_VIEW_PAGE_VIEW_OFFSET));
	 button_next->m_signalClicked.connect(this, &VappNotesPageviewer::vapp_notes_viewer_next_button_handler);
	}

	
	VFX_OBJ_CREATE(tool_bar,VcpToolBar,this);
	setBottomBar(tool_bar);
	tool_bar->addItem(EDIT_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_EDIT), IMG_ID_VAPP_NOTES_EDIT);	
	tool_bar->addItem(DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);	
	tool_bar->m_signalButtonTap.connect(this, &VappNotesPageviewer::vapp_notes_viewer_page_tool_bar_button_handler);	

	U16 red =0,green = 0,blue = 0;
	VfxWChar viewText[102] = {'A','m','i','t'};
	
	U32 cmp_time = 0;
	MYTIME calender_time;
	S8 arr[100] = {'\0',};


	if(view_panel)
	{
		VFX_OBJ_CLOSE(view_panel);
		view_panel = NULL;
	}
	if(text_frame_date1)
	{
		VFX_OBJ_CLOSE(text_frame_date1);
		text_frame_date1 = NULL;
	}
	if(text_frame_time1)
	{
		VFX_OBJ_CLOSE(text_frame_time1);
		text_frame_time1 = NULL;
	}
	if(m_hintText)
	{
		VFX_OBJ_CLOSE(m_hintText);
		m_hintText = NULL;
	}
	if(bg_frame1)
	{
		VFX_OBJ_CLOSE(bg_frame1);
		bg_frame1 = NULL;
	}
	if(current_view_frame)
	{
		VFX_OBJ_CLOSE(current_view_frame);
		current_view_frame = NULL;
	}
	if(m_text1)
	{
		VFX_OBJ_CLOSE(m_text1);
		m_text1 = NULL;
	}


	VFX_OBJ_CREATE(view_panel, VcpPagePanel, this);
	view_panel->setPos(VfxPoint(0,  NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT));
	//VfxU32 height = top_button_frame->getRect().getMaxY()  - 1 ;
	parentSize = this->getSize();
	view_panel->setSize(parentSize.width,parentSize.height-NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT);
	view_panel->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
	
	/*data for the current frame*/
   	/*********************/
	
	VFX_OBJ_CREATE(current_view_frame, VfxFrame, view_panel);
	current_view_frame->setPos(VfxPoint(0, 0));
	current_view_frame->setSize(LCD_WIDTH, tool_bar->getRect().getMinY() - 1 );
	
	venus_mmi_note_load_text();
	VfxU8 color = g_venus_note_edit_cntx.curr_color;
	mmi_get_rgb_color_for_notes(color, &red ,&green, &blue);
	//U16 editor_image_id = mmi_get_editor_image_id(color);
		
	/* need to update this code later*/	
	
	if(mmi_note_get_color_selected_from_category_screen())
	{
		 
		update = VfxWString().format("%d/%d",category_list_node_selected + 1,mmi_notes_get_notes_count_from_category_selected_color());
	}
	else
	{
 
		update = VfxWString().format("%d/%d",g_venus_note_edit_cntx.curr_item +1, mmi_notes_get_notes_count_from_category_selected_color());
	}
 


	VfxFontDesc fontDesc2;
	
	VFX_OBJ_CREATE(m_hintText, VfxTextFrame, top_button_frame);	
	m_hintText->setAnchor(0.5,0.5);
	m_hintText->setPos(LCD_WIDTH/2, NOTES_APP_VIEW_PAGE_TOP_BAR_HEIGHT/2);
	m_hintText->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_hintText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_hintText->setMaxLines(1);
    m_hintText->setColor(VFX_COLOR_WHITE);
    fontDesc2.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_VIEW_PAGE_VIEW_HINT_TITLE_FONT);
    m_hintText->setFont(fontDesc2);
	
	m_hintText->setString(update);


    VFX_OBJ_CREATE(bg_frame1, VfxFrame, current_view_frame);
	bg_frame1->setPos(0,0);	 
	bg_frame1->setSize(LCD_WIDTH, NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT);  
	bg_frame1->setBgColor(VfxColor(255,red,green,blue));
	
	 
	VFX_OBJ_CREATE(bg_frame_upper1, VfxFrame, bg_frame1);
	bg_frame_upper1->setBgColor(VfxColor(255, 0, 0, 0)); 
	bg_frame_upper1->setPos(0,0);	
	bg_frame_upper1->setSize(LCD_WIDTH, NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT);  
	bg_frame_upper1->setOpacity(0.05);
	
	VFX_OBJ_CREATE(text_frame_date1, VfxTextFrame, bg_frame1);	 

	cmp_time = g_venus_note_edit_cntx.time;

	VfxU32 localSec = 0;
                localSec = applib_dt_sec_utc_to_local(cmp_time);
                mmi_dt_utc_sec_2_mytime(localSec, &calender_time, MMI_FALSE);
	date_string(&calender_time, (UI_string_type)arr, DT_IDLE_SCREEN);

	VfxWString title1;
	title1.loadFromMem((VfxWChar*)arr);
	
	text_frame_date1->setString(title1);	 
	text_frame_date1->setPos(NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_X , NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_Y);	 	
	text_frame_date1->setColor(VfxColor(255,80,80,80));
    font_size1.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_LIST_ITEM_SUB_TEXT_FONT);	
    text_frame_date1->setFont(font_size1);
	
	time_string(&calender_time, (UI_string_type)arr, DT_IDLE_SCREEN);

	VFX_OBJ_CREATE(text_frame_time1, VfxTextFrame, bg_frame1);

	
	
	VfxWString title2;
	title2.loadFromMem((VfxWChar*)arr);
	text_frame_time1->setString(title2);	 
	text_frame_time1->setPos(NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_X ,  NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_Y);	 	
	
	text_frame_time1->setColor(VfxColor(255,80,80,80));
    font_size2.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_LIST_ITEM_SUB_TEXT_FONT);		
    text_frame_time1->setFont(font_size2);


	VFX_OBJ_CREATE(m_text1, VcpTextView, current_view_frame);
	
	m_text1->setMargins(VCP_NOTESAPP_EDIT_VIEW_MARGIN,0,VCP_NOTESAPP_EDIT_VIEW_MARGIN,VCP_NOTESAPP_EDIT_VIEW_MARGIN);
	m_text1->disableBackground(VFX_TRUE);
	m_text1->setBgColor(VfxColor(255,red,green,blue));
	 
	m_text1->setUnderline(VFX_FALSE);
	m_text1->setMinLineHeight(VCP_NOTESAPP_EDITOR_LINE_GAP);
	m_text1->setPos(0, NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT);
	
	m_text1->setSize(LCD_WIDTH,NOTES_APP_VIEW_PAGE_VIEW_VIEW_FRAME_HEIGHT);	
	

	//m_text1->setHint(VFX_WSTR("Please tap to input:"));
	m_text1->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);
	mmi_ucs2cpy((S8*)viewText,(S8*)g_venus_note_edit_cntx.curr_edit);
	m_text1->setText(viewText, NULL); /* set text without any text format*/
	m_text1->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
	
	/*data for the new frame*/
	/*******************/

	if(new_view_frame)
	{
		VFX_OBJ_CLOSE(new_view_frame);
		new_view_frame = NULL;
	}
	if(text_frame_date2)
	{
		VFX_OBJ_CLOSE(text_frame_date2);
		text_frame_date2 = NULL;
	}
	if(text_frame_time2)
	{
		VFX_OBJ_CLOSE(text_frame_time2);
		text_frame_time2 = NULL;
	}
	if(m_text2)
	{
		VFX_OBJ_CLOSE(m_text2);
		m_text2 = NULL;
	}
	if(bg_frame2)
	{
		VFX_OBJ_CLOSE(bg_frame2);
		bg_frame2 = NULL;
	}
	if(new_view_frame)
	{
		VFX_OBJ_CLOSE(new_view_frame);
		new_view_frame = NULL;
	}

	VFX_OBJ_CREATE(new_view_frame, VfxFrame, view_panel);	
	new_view_frame->setPos(VfxPoint(0, 0));
	new_view_frame->setSize(LCD_WIDTH, tool_bar->getRect().getMinY()  - 1);

	VFX_OBJ_CREATE(bg_frame2, VfxFrame, new_view_frame);
	bg_frame2->setPos(0,0);  
	bg_frame2->setSize(LCD_WIDTH, NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT);  	
	VFX_OBJ_CREATE(bg_frame_upper2, VfxFrame, bg_frame2);
	bg_frame_upper2->setBgColor(VfxColor(255, 0, 0, 0)); 
	bg_frame_upper2->setPos(0,0);	
	bg_frame_upper2->setSize(LCD_WIDTH, NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT);  
	bg_frame_upper2->setOpacity(0.05);	
	//bg_frame2->setBorderColor(VFX_COLOR_GREY);	
   // bg_frame2->setBorderWidth(1);
	
	VFX_OBJ_CREATE(text_frame_date2, VfxTextFrame, bg_frame2);	 
		 
	text_frame_date2->setPos(NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_X ,  NOTES_APP_VIEW_PAGE_VIEW_FRAME_DATE_Y);		
	text_frame_date2->setColor(VfxColor(255,80,80,80));
	font_size2.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_LIST_ITEM_SUB_TEXT_FONT);	
	text_frame_date2->setFont(font_size2);
	

	VFX_OBJ_CREATE(text_frame_time2, VfxTextFrame, bg_frame2);
 
	text_frame_time2->setPos(NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_X ,  NOTES_APP_VIEW_PAGE_VIEW_FRAME_TIME_Y);	 	
	text_frame_time2->setColor(VfxColor(255,80,80,80));
    font_size2.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_LIST_ITEM_SUB_TEXT_FONT);	
    text_frame_time2->setFont(font_size2);

 	g_current_selected_frame = FRAME_1;
	view_panel->setCurrentFrame(current_view_frame);

	

}


void VappNotesPageviewer::onEnter(VfxBool isbackward)
{
	VfxPage::onEnter(isbackward);
	if((button_next)&&(button_previous))
	{
      button_next->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
	  button_previous->setState(VCP_IMAGE_BUTTON_STATE_NORMAL);
	}
}


 void VappNotesPageviewer::vapp_notes_viewer_prev_button_handler(VfxObject* obj, VfxId id)
{		
	VfxWChar viewText[102] = {'0'};
	

	if(mmi_note_get_color_selected_from_category_screen())
	{
		if(category_list_node_selected == 0)
		{
			// set the last item in list as curr item return;
			category_list_node_selected = mmi_notes_get_notes_count_from_category_selected_color()-1;
			mmi_note_list_highlight_set_hdlr(category_list_node_selected);
		}
		else
		{
			category_list_node_selected--;
			mmi_note_list_highlight_set_hdlr(category_list_node_selected);
		}
		update = VfxWString().format("%d/%d",category_list_node_selected+1, mmi_notes_get_notes_count_from_category_selected_color());
	}

	else
	{
		if(g_venus_note_edit_cntx.curr_item == 0)
	{
			// set the last item in list as curr item return;
			g_venus_note_edit_cntx.curr_item = mmi_notes_get_notes_count_from_category_selected_color() -1;
			mmi_note_list_highlight_set_hdlr(g_venus_note_edit_cntx.curr_item);
		}
		else
		{
		g_venus_note_edit_cntx.curr_item--; 
		mmi_note_list_highlight_set_hdlr(g_venus_note_edit_cntx.curr_item);
		}
		
		update = VfxWString().format("%d/%d",g_venus_note_edit_cntx.curr_item +1, mmi_notes_get_notes_count_from_category_selected_color());
	}

	{
		m_hintText->setString(update);
		venus_mmi_note_load_text();
		mmi_ucs2cpy((S8*)viewText,(S8*)g_venus_note_edit_cntx.curr_edit);
		U8 color = g_venus_note_edit_cntx.curr_color;
		VfxU16 red = 0,green = 0, blue = 0;
		mmi_get_rgb_color_for_notes(color, &red ,&green, &blue);
		U32 cmp_time = 0;
		MYTIME calender_time;
		S8 arr[100] = {'\0',};
		 cmp_time = g_venus_note_edit_cntx.time;
		
		 VfxU32 localSec = 0;
                localSec = applib_dt_sec_utc_to_local(cmp_time);
                mmi_dt_utc_sec_2_mytime(localSec, &calender_time, MMI_FALSE);
		date_string(&calender_time, (UI_string_type)arr, DT_IDLE_SCREEN);
		VfxWString title1,title2;
		title1.loadFromMem((VfxWChar*)arr);
		time_string(&calender_time, (UI_string_type)arr, DT_IDLE_SCREEN);
		title2.loadFromMem((VfxWChar*)arr);
		
			
		if(g_current_selected_frame == FRAME_1)
		{
			g_current_selected_frame = FRAME_2;
			if(m_text1)
			{
				VFX_OBJ_CLOSE(m_text1);
				m_text1 = NULL;
			}
			VFX_OBJ_CREATE(m_text2, VcpTextView, new_view_frame);
	
			m_text2->setMargins(VCP_NOTESAPP_EDIT_VIEW_MARGIN,0,VCP_NOTESAPP_EDIT_VIEW_MARGIN,VCP_NOTESAPP_EDIT_VIEW_MARGIN);
			
			m_text2->setUnderline(VFX_FALSE);
			m_text2->setMinLineHeight(VCP_NOTESAPP_EDITOR_LINE_GAP);
			m_text2->setPos(0, NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT);
			m_text2->setSize(LCD_WIDTH, NOTES_APP_VIEW_PAGE_VIEW_VIEW_FRAME_HEIGHT);
			
			m_text2->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);	
			m_text2->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
			m_text2->setText(viewText, NULL); /* set text without any text format*/	
			m_text2->setBgColor(VfxColor(255, red, green, blue));
			 
			bg_frame2->setBgColor(VfxColor(255, red, green, blue));
		 
			text_frame_date2->setString(title1);
			text_frame_time2->setString(title2);
		 
			bg_frame_upper2->setOpacity(0.05);
			view_panel->switchTo(
				new_view_frame, 
				VCP_PAGE_EFFECT_PUSH, 
				0001,
				VCP_PAGE_DIRECTION_FROM_LEFT,
				VFX_FALSE,
				NULL,
				0);
			
			
		}
		else
		{
			g_current_selected_frame = FRAME_1;
			if(m_text2)
			{
				VFX_OBJ_CLOSE(m_text2);
				m_text2 = NULL;
			}
			VFX_OBJ_CREATE(m_text1, VcpTextView, current_view_frame);
	
			m_text1->setMargins(VCP_NOTESAPP_EDIT_VIEW_MARGIN,0,VCP_NOTESAPP_EDIT_VIEW_MARGIN,VCP_NOTESAPP_EDIT_VIEW_MARGIN);
			
			m_text1->setUnderline(VFX_FALSE);
			m_text1->setMinLineHeight(VCP_NOTESAPP_EDITOR_LINE_GAP);
			m_text1->setPos(0, NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT);
			m_text1->setSize(LCD_WIDTH, NOTES_APP_VIEW_PAGE_VIEW_VIEW_FRAME_HEIGHT);
			
			m_text1->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);	
			m_text1->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
			m_text1->setText(viewText, NULL); /* set text without any text format*/ 
			m_text1->setBgColor(VfxColor(255, red, green, blue));
		 
			bg_frame1->setBgColor(VfxColor(255, red, green, blue));
		 
			text_frame_date1->setString(title1);
		    text_frame_time1->setString(title2);
		 
			bg_frame_upper1->setOpacity(0.05);
			view_panel->switchTo(
				current_view_frame, 
				VCP_PAGE_EFFECT_PUSH, 
				0001,
				VCP_PAGE_DIRECTION_FROM_LEFT,
				VFX_FALSE,
				NULL,
				0);
			
		}
		
	}
	
}

void VappNotesPageviewer::vapp_notes_viewer_next_button_handler(VfxObject* obj, VfxId id)
{		
	VfxWChar viewText[102] = {'0'};
	
	if(mmi_note_get_color_selected_from_category_screen())
	{
		if(category_list_node_selected == mmi_notes_get_notes_count_from_category_selected_color()-1)
		{
			//return;
			category_list_node_selected = 0;
			mmi_note_list_highlight_set_hdlr(category_list_node_selected);
		}
		else
		{
			category_list_node_selected++;
			mmi_note_list_highlight_set_hdlr(category_list_node_selected);
		}
		update = VfxWString().format("%d/%d",category_list_node_selected+1, mmi_notes_get_notes_count_from_category_selected_color());
	}
    
	else
	{
		if(g_venus_note_edit_cntx.curr_item == g_venus_mmi_note_cntx.item_num - 1)
		{
			g_venus_note_edit_cntx.curr_item = 0;
			mmi_note_list_highlight_set_hdlr(g_venus_note_edit_cntx.curr_item);
			//return;
		}
		else
		{
		g_venus_note_edit_cntx.curr_item++;	
		mmi_note_list_highlight_set_hdlr(g_venus_note_edit_cntx.curr_item);
		}
		
		update = VfxWString().format("%d/%d",g_venus_note_edit_cntx.curr_item +1, mmi_notes_get_notes_count_from_category_selected_color());
	}
	
		m_hintText->setString(update);
		venus_mmi_note_load_text();
		mmi_ucs2cpy((S8*)viewText,(S8*)g_venus_note_edit_cntx.curr_edit);
		mmi_ucs2cpy((S8*)viewText,(S8*)g_venus_note_edit_cntx.curr_edit);
		U8 color = g_venus_note_edit_cntx.curr_color;
		VfxU16 red = 0,green = 0, blue = 0;
		mmi_get_rgb_color_for_notes(color, &red ,&green, &blue);

		U32 cmp_time = 0;
		MYTIME calender_time;
		S8 arr[100] = {'\0',};

		 cmp_time = g_venus_note_edit_cntx.time;
		
		VfxU32 localSec = 0;
                localSec = applib_dt_sec_utc_to_local(cmp_time);
                mmi_dt_utc_sec_2_mytime(localSec, &calender_time, MMI_FALSE);
		date_string(&calender_time, (UI_string_type)arr, DT_IDLE_SCREEN);
		VfxWString title1,title2;
		title1.loadFromMem((VfxWChar*)arr);
		time_string(&calender_time, (UI_string_type)arr, DT_IDLE_SCREEN);
		title2.loadFromMem((VfxWChar*)arr);


		if(g_current_selected_frame == FRAME_1)
		{
			g_current_selected_frame = FRAME_2;
			if(m_text1)
			{
				VFX_OBJ_CLOSE(m_text1);
				m_text1 = NULL;
			}
			VFX_OBJ_CREATE(m_text2, VcpTextView, new_view_frame);
	
			m_text2->setMargins(VCP_NOTESAPP_EDIT_VIEW_MARGIN,0,VCP_NOTESAPP_EDIT_VIEW_MARGIN,VCP_NOTESAPP_EDIT_VIEW_MARGIN);
			
			m_text2->setUnderline(VFX_FALSE);
			m_text2->setMinLineHeight(VCP_NOTESAPP_EDITOR_LINE_GAP);
			m_text2->setPos(0, NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT);
			m_text2->setSize(LCD_WIDTH, NOTES_APP_VIEW_PAGE_VIEW_VIEW_FRAME_HEIGHT);
			
			m_text2->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);	
			m_text2->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
			m_text2->setText(viewText, NULL); /* set text without any text format*/	
			m_text2->setBgColor(VfxColor(255, red, green, blue));
		 
			bg_frame2->setBgColor(VfxColor(255, red, green, blue));
		 
			text_frame_date2->setString(title1);
			text_frame_time2->setString(title2);
		 
			bg_frame_upper2->setOpacity(0.05);
			
			view_panel->switchTo(
				new_view_frame, 
				VCP_PAGE_EFFECT_PUSH, 
				0001,
				VCP_PAGE_DIRECTION_FROM_RIGHT,
				VFX_FALSE,
				NULL,
				0);
			
		}
		else
		{	
			g_current_selected_frame = FRAME_1;
			if(m_text2)
			{
				VFX_OBJ_CLOSE(m_text2);
				m_text2 = NULL;
			}
			VFX_OBJ_CREATE(m_text1, VcpTextView, current_view_frame);
	
			m_text1->setMargins(VCP_NOTESAPP_EDIT_VIEW_MARGIN,0,VCP_NOTESAPP_EDIT_VIEW_MARGIN,VCP_NOTESAPP_EDIT_VIEW_MARGIN);
			
			m_text1->setUnderline(VFX_FALSE);
			m_text1->setMinLineHeight(VCP_NOTESAPP_EDITOR_LINE_GAP);
			m_text1->setPos(0, NOTES_APP_VIEW_PAGE_VIEW_BG_FRAME_HEIGHT);
			m_text1->setSize(LCD_WIDTH, NOTES_APP_VIEW_PAGE_VIEW_VIEW_FRAME_HEIGHT);
			
			m_text1->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);	
			m_text1->setLineMode(VCP_TEXT_LINE_MODE_MULTI);
			m_text1->setText(viewText, NULL); /* set text without any text format*/		
			m_text1->setBgColor(VfxColor(255, red, green, blue));
		 
			bg_frame1->setBgColor(VfxColor(255, red, green, blue));
		 
			text_frame_date1->setString(title1);
			text_frame_time1->setString(title2);
		 
			bg_frame_upper1->setOpacity(0.05);
			view_panel->switchTo(
				current_view_frame, 
				VCP_PAGE_EFFECT_PUSH, 
				0001,
				VCP_PAGE_DIRECTION_FROM_RIGHT,
				VFX_FALSE,
				NULL,
				0);
			
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
		#endif
	
}


void VappNotesPageviewer::vapp_notes_viewer_page_tool_bar_button_handler(VfxObject * obj,VfxId id)
{
	if(id == EDIT_BUTTON)
	{
		VappNotesEditor *notes_editor;
		
		VFX_OBJ_CREATE_EX(notes_editor, VappNotesEditor, getMainScr(),((VfxWChar*)&g_venus_note_edit_cntx.curr_edit)); 
		getMainScr()->popPage(); /*deleting the viewer screen*/				
		getMainScr()->pushPage(0, notes_editor);

		
	}
	else if(id == DELETE_BUTTON)
	{
		VcpConfirmPopup *deleteConfirm;
		VFX_OBJ_CREATE(deleteConfirm, VcpConfirmPopup, findScreen());

		deleteConfirm->setText(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_DELETE_NOTE_ASK));
		deleteConfirm->setInfoType(VCP_POPUP_TYPE_WARNING);

		deleteConfirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
		deleteConfirm->setCustomButton(
        VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE),
        VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_CANCEL),
        VCP_POPUP_BUTTON_TYPE_WARNING,
        VCP_POPUP_BUTTON_TYPE_CANCEL);
		deleteConfirm->show(VFX_TRUE);
		deleteConfirm->m_signalButtonClicked.connect(this,&VappNotesPageviewer::vapp_notes_viewer_OptionDeleteconfirm);
	}

}

void VappNotesPage::vapp_notes_page_tool_bar_button_handler(VfxObject * obj,VfxId id)
{
	 switch(id)
	 {
        case ADD_BUTTON:
		{
			 /*put a check here for max count*/

			 if(g_venus_mmi_note_cntx.item_num == MMI_MAX_NOTE_ITEM)
			 {
					
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_ITEM_LIMIT).getBuf() ));

			}
			else
			{
 				VappNotesEditor *notes_editor;
				g_venus_note_edit_cntx.curr_item = (U16)(-1);
				VFX_OBJ_CREATE(notes_editor, VappNotesEditor, getMainScr()); 		
				getMainScr()->pushPage(0, notes_editor);			
			}
			 break;
		}
			
#ifndef __LOW_COST_SUPPORT_COMMON__
		case CATEGORY_BUTTON:
		{
			/*write here for diff category  notes */
			VfxU16 i = 0;
			for(i = NOTES_CATAEGORY_COLOR_WHITE; i <= NOTES_CATAEGORY_COLOR_RED; i++)
			{
				mmi_app_notes_update_note_count_by_color(i);
			}
			VappNotesCategoryView *m_notesCategory;
			VFX_OBJ_CREATE(m_notesCategory,VappNotesCategoryView,getMainScr());
			getMainScr()->pushPage(0, m_notesCategory);
            break;
		}
#endif	
		case LIST_DELETE_BUTTON:
		{
			memset(&g_venus_note_mark_cntx, 0x00, sizeof(venus_mmi_note_mark_list_struct));
			listMenu->resetAllItems(VFX_TRUE);
			listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION);
			listMenu->setShadowIsDisabled(VFX_TRUE);
			g_list_in_mark_delete_mode = 1;

			if(del_tool_bar != NULL)
			{
				VFX_OBJ_CLOSE(del_tool_bar);
				del_tool_bar = NULL;
			}
			VFX_OBJ_CREATE(del_tool_bar,VcpToolBar,this);
			setBottomBar(del_tool_bar);
			
			del_tool_bar->addItem(SELECT_ALL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_SELECT_ALL), IMG_ID_VAPP_NOTES_SELECT_ALL);	
			del_tool_bar->addItem(MARK_LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);			
			del_tool_bar->addItem(CANCEL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_CANCEL), IMG_ID_VAPP_NOTES_CANCEL);

			del_tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);			
			del_tool_bar->setDisableItem(SELECT_ALL_BUTTON, VFX_FALSE);
			del_tool_bar->setDisableItem(MARK_LIST_DELETE_BUTTON, VFX_TRUE);
			del_tool_bar->setDisableItem(CANCEL_BUTTON, VFX_FALSE);	
			title_bar->setTitle(VFX_WSTR_RES(STR_ID_VAAP_NOTES_DELETE_NOTES_TITLE));
			listMenu->m_signalItemTapped.disconnect(this, &VappNotesPage::vapp_notes_page_onSelectionitemtapped);
			listMenu->m_signalItemLongTapped.disconnect(this, &VappNotesPage::vapp_notes_page_onSelectionItemLongTapped);

			break;
		}


		case SEARCH_BUTTON:
		{	
			g_list_in_search_mode = 1;
			listMenu->enableSearchBar();
			VfxU16 height = tool_bar->getRect().getMinY() -2*TOP_BAR_HEIGHT- 41 + 52;
			//VFX_OBJ_CLOSE(tool_bar);
			tool_bar = NULL;
		 
			  setBar(VFX_PAGE_BAR_LOCATION_BOTTOM,NULL,VFX_TRUE);
			VfxSize parentSize = this->getSize();
			//listMenu->setSize(LCD_WIDTH-NOTES_APP_LIST_START_GAP_X-NOTES_APP_LIST_END_GAP_X,height);
			listMenu->setSize(parentSize.width-NOTES_APP_LIST_START_GAP_X-NOTES_APP_LIST_END_GAP_X,parentSize.height-TOP_BAR_HEIGHT);
			listMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
			//listMenu->updateAllItems();
			//listMenu->resetAllItems(VFX_TRUE);
			//VFX_OBJ_GET_INSTANCE(VfxRenderer)-> debugDump();
			search_bar = listMenu->getSearchBar();
			search_editor = search_bar->getSearchEditor();
			search_editor->activate();
			//search_editor->setHint(VFX_WSTR_RES(STR_ID_VAPP_NOTES_HINT_SEARCHING));
			VfxWString title1;	
			title1 = VFX_WSTR_RES(STR_GLOBAL_SEARCH);
			//title1 += hint;
			title_bar->setTitle(title1);
			search_editor->m_signalTextChanged.connect(this, &VappNotesPage::vapp_notes_page_onSearchTextChanged);
			break;
		}

		case MARK_LIST_DELETE_BUTTON:
		{
			VfxU16 count = mmi_notes_get_total_num_of_marked_notes();
			VcpConfirmPopup *deleteConfirm;
			VFX_OBJ_CREATE(deleteConfirm, VcpConfirmPopup, findScreen());
			VfxWString prefix,num,postfix;
			
			num = VfxWString().format("%d",count);
			if(count == 1)
			{
              prefix = VFX_WSTR_RES(STR_ID_VAPP_NOTES_DELETE_CONFIRM_ONE_STRING_1);
			}
			else
			{
			  prefix = VFX_WSTR_RES(STR_ID_VAPP_NOTES_DELETE_CONFIRM_STRING_1);
			}
			prefix += num;
			postfix = VFX_WSTR_RES(STR_ID_VAPP_NOTE_DELETE_STRING_2);
			prefix += postfix;
			deleteConfirm->setText(prefix);
			deleteConfirm->setInfoType(VCP_POPUP_TYPE_WARNING);

			deleteConfirm->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
			deleteConfirm->setCustomButton(
			VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE),
			VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_CANCEL),
			VCP_POPUP_BUTTON_TYPE_WARNING,
			VCP_POPUP_BUTTON_TYPE_CANCEL);
			deleteConfirm->show(VFX_TRUE);
			deleteConfirm->m_signalButtonClicked.connect(this,&VappNotesPage::vapp_notes_page_marked_notes_delete_confirmation);
			break;
		}	


		case SELECT_ALL_BUTTON:
		{
			for (int i = 0; i < mmi_notes_get_notes_count_from_category_selected_color(); i++ )
				g_venus_note_mark_cntx.mark_flag[i] = 1;			

			del_tool_bar->removeItem(SELECT_ALL_BUTTON);
			del_tool_bar->removeItem(MARK_LIST_DELETE_BUTTON);
			del_tool_bar->removeItem(CANCEL_BUTTON);

			del_tool_bar->addItem(UNSELECT_ALL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_UNSELECT_ALL), IMG_ID_VAPP_NOTES_UNSELECT_ALL);	
			del_tool_bar->addItem(MARK_LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);			
			del_tool_bar->addItem(CANCEL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_CANCEL), IMG_ID_VAPP_NOTES_CANCEL);
			del_tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);
			listMenu->updateAllItems();
			
			break;
		}	

		case UNSELECT_ALL_BUTTON:
		{			
			for (int i = 0; i < mmi_notes_get_notes_count_from_category_selected_color(); i++ )
				g_venus_note_mark_cntx.mark_flag[i] = 0;			
			
			del_tool_bar->removeItem(UNSELECT_ALL_BUTTON);
			del_tool_bar->removeItem(MARK_LIST_DELETE_BUTTON);
			del_tool_bar->removeItem(CANCEL_BUTTON);

			del_tool_bar->addItem(SELECT_ALL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_SELECT_ALL), IMG_ID_VAPP_NOTES_SELECT_ALL);	
			del_tool_bar->addItem(MARK_LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);			
			del_tool_bar->addItem(CANCEL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_CANCEL), IMG_ID_VAPP_NOTES_CANCEL);

			del_tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);
			
			del_tool_bar->setDisableItem(SELECT_ALL_BUTTON, VFX_FALSE);
			del_tool_bar->setDisableItem(MARK_LIST_DELETE_BUTTON, VFX_TRUE);
			del_tool_bar->setDisableItem(CANCEL_BUTTON, VFX_FALSE);
			listMenu->updateAllItems();
			
			break;
		}

		case CANCEL_BUTTON:
		{
			listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL);
			listMenu->resetAllItems(VFX_TRUE);
			listMenu->m_signalItemTapped.connect(this, &VappNotesPage::vapp_notes_page_onSelectionitemtapped);			
			listMenu->m_signalItemLongTapped.connect(this, &VappNotesPage::vapp_notes_page_onSelectionItemLongTapped);			
			if(del_tool_bar)
			{
				VFX_OBJ_CLOSE(del_tool_bar);
				del_tool_bar = NULL;
			}
			
			setTopbarTitle();
			
			setBottomBar(tool_bar);
			break;
		}	
			
       default:					
            break;
	 }
}

void VappNotesPage::vapp_notes_page_onSearchTextChanged(VcpTextEditor *editor)
{
	U16 count = 0;
	if(g_list_in_search_mode == 1)
	{
		g_list_in_search_mode = 2;
	}
	VfxWChar *text_string = search_editor->getText();
	/*if count is none then display the all list*/
	VfxS8 char_count = 0;
	char_count = mmi_ucs2strlen((const char*) text_string);
	if(char_count == 0)
	{
		VfxWString title1;	
		title1 = VFX_WSTR_RES(STR_GLOBAL_SEARCH);
		//title1 += hint;
		title_bar->setTitle(title1);
		g_list_in_search_mode = 1;
		vapp_notes_set_searched_count(0);
		//listMenu->updateAllItems();
		listMenu->resetAllItems(VFX_TRUE);
		return;
	}
	count = mmi_vapp_notes_search_text_in_notes_list(text_string);
	if(count)
	{
		VfxWString title1,hint;	
		title1 = VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_SEARCH_COUNT);
		hint = VfxWString().format("(%d)",count);
		title1 += hint;
		title_bar->setTitle(title1);
		//listMenu->updateAllItems();
		listMenu->resetAllItems(VFX_TRUE);
	}
	else
	{
		VfxWString title1,hint;	
		title1 = VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_SEARCH_COUNT);
		hint = VfxWString().format("(%d)",count);
		title1 += hint;
		title_bar->setTitle(title1);
		vapp_notes_set_searched_count(0);
		//listMenu->updateAllItems();
		listMenu->resetAllItems(VFX_TRUE);
	}

}

void VappNotesPage::vapp_notes_page_marked_notes_delete_confirmation(VfxObject * obj,VfxId id)
{
	if(id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
		mmi_note_app_marked_list_delete();
		vapp_notes_list_set_item_edited_deleted_or_added(MMI_TRUE);
		/*need tyo update the mark list array to 0 as the check boxes will be shown for the 
		checked index if not set to zero*/

		for (int i = 0; i < g_venus_mmi_note_cntx.item_num; i++ )
			g_venus_note_mark_cntx.mark_flag[i] = 0;	

		if(mmi_note_get_color_selected_from_category_screen())
		{
			getMainScr()->popPage(); /*deleting the category list to reach main listscreen*/
			return;
		}

		vapp_notes_list_set_item_edited_deleted_or_added(MMI_FALSE);
		listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL);
		listMenu->m_signalItemTapped.connect(this, &VappNotesPage::vapp_notes_page_onSelectionitemtapped);	
		listMenu->m_signalItemLongTapped.connect(this, &VappNotesPage::vapp_notes_page_onSelectionItemLongTapped);	
		listMenu->updateAllItems();                  /*to update the checked boxes status on the mark several screen*/              
		listMenu->resetAllItems(VFX_TRUE);    /*to update the list after deletion of items*/
		VFX_OBJ_CLOSE(del_tool_bar);
		del_tool_bar = NULL;
		VFX_OBJ_CLOSE(tool_bar);
		tool_bar = NULL;
		VFX_OBJ_CREATE(tool_bar,VcpToolBar,this);
		setBottomBar(tool_bar);	
		tool_bar->addItem(ADD_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_ADD_NOTE), IMG_ID_VAPP_NOTES_ADD_NEW_NOTE);			
         	#ifndef __LOW_COST_SUPPORT_COMMON__
		tool_bar->addItem(CATEGORY_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_CATEGORY), IMG_ID_VAPP_NOTES_CATEGORY);	
	        #endif		
		tool_bar->addItem(LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);	
		tool_bar->addItem(SEARCH_BUTTON, VFX_WSTR_RES(STR_GLOBAL_SEARCH), IMG_ID_VAPP_NOTES_SEARCH);	
		tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);
		VfxWString title1,hint;
		title1 = VFX_WSTR_RES(STR_ID_VAPP_NOTES_APP_TITLE);
		mmi_note_set_color_selected_from_category_screen(0);
		hint = VfxWString().format("(%d/%d)",mmi_notes_get_notes_count_from_category_selected_color() ,MMI_MAX_NOTE_ITEM);
		title1 += hint;
		title_bar->setTitle(title1);
		if(g_venus_mmi_note_cntx.item_num == 0)
		{		
			#ifndef __LOW_COST_SUPPORT_COMMON__
			tool_bar->setDisableItem(CATEGORY_BUTTON, VFX_TRUE);
			#endif	
			tool_bar->setDisableItem(LIST_DELETE_BUTTON, VFX_TRUE);
			tool_bar->setDisableItem(SEARCH_BUTTON, VFX_TRUE);

		}
		
		
	}
}


void VappNotesPage::onBack()
{	
	if(g_list_in_search_mode > 0)
	{
		VfxSize parentSize;
		g_list_in_search_mode = 0;
		listMenu->disableSearchBar();
		listMenu->setPos(NOTES_APP_LIST_START_GAP_X,  TOP_BAR_HEIGHT + 1);	
		//parentSize = this->getSize();
		listMenu->resetAllItems(VFX_TRUE);
		if(tool_bar == NULL)
		{
			VFX_OBJ_CREATE(tool_bar,VcpToolBar,this);
			setBottomBar(tool_bar);	
			tool_bar->addItem(ADD_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_ADD_NOTE), IMG_ID_VAPP_NOTES_ADD_NEW_NOTE);				
			#ifndef __LOW_COST_SUPPORT_COMMON__
			tool_bar->addItem(CATEGORY_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_CATEGORY), IMG_ID_VAPP_NOTES_CATEGORY);	
			#endif			
			tool_bar->addItem(LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);	
			tool_bar->addItem(SEARCH_BUTTON, VFX_WSTR_RES(STR_GLOBAL_SEARCH), IMG_ID_VAPP_NOTES_SEARCH);	
			tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);
		}
			 
		setTopbarTitle();
		
		//listMenu->setSize(parentSize.width-NOTES_APP_LIST_START_GAP_X-NOTES_APP_LIST_END_GAP_X,parentSize.height-2*TOP_BAR_HEIGHT);
		//listMenu->setSize(LCD_WIDTH-NOTES_APP_LIST_START_GAP_X-NOTES_APP_LIST_END_GAP_X, tool_bar->getRect().getMinY() -2*TOP_BAR_HEIGHT- 41);
		listMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        //if(m_category_new)
		updateToolBar();
		return;
	}
	if((listMenu) && (listMenu->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION))
	{
			if(del_tool_bar)
			{
				VFX_OBJ_CLOSE(del_tool_bar);
				del_tool_bar = NULL;
			}
			listMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL);	
			listMenu->m_signalItemTapped.connect(this, &VappNotesPage::vapp_notes_page_onSelectionitemtapped);	
			listMenu->m_signalItemLongTapped.connect(this, &VappNotesPage::vapp_notes_page_onSelectionItemLongTapped);	
			listMenu->resetAllItems(VFX_TRUE);
			setBottomBar(tool_bar);
		
			setTopbarTitle();
			
	}
		
	else
	{
	
		getMainScr()->popPage();
}
}

VfxU32 VappNotesPage::getCount() const
{

		if(g_list_in_search_mode < 2)
		{
			return mmi_notes_get_notes_count_from_category_selected_color_ext(m_color);	
		}
		else 
		{
			return vapp_notes_get_searched_count();
		}
		
}


 void VappNotesPage::onExited()
{
	 /*if(g_list_in_search_mode > 0)
		 {
			 g_list_in_search_mode = 0;
			 notes_view_through_search = 1;
			 listMenu->disableSearchBar();
		 }*/
}


VcpListMenuCellClientBaseFrame * VappNotesPage::getItemCustomContentFrame(
        VfxU32 index,        // [IN] index of the item
        VfxFrame *parentFrame // [IN] parent frame of the custom content frame
        ) 
       {
		VfxU32 node_index = 0;
		U32 cmp_time = 0;
		MYTIME calender_time;
		S8 arr[100] = {'\0',};
		S8 arr2[40] = {'\0',};

						
		 if(index < mmi_notes_get_notes_count_from_category_selected_color_ext(m_color))
		 {
			VappNotesCustomContentFrame *custFrame = NULL;				
			VFX_OBJ_CREATE(custFrame, VappNotesCustomContentFrame, parentFrame);

			if(listMenu->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION)
			{
				custFrame->setSize(NOTES_APP_LIST_ITEM_CUST_FRAME_WIDTH_MARK, NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT);
			}
			else
			{
				custFrame->setSize(NOTES_APP_LIST_ITEM_CUST_FRAME_WIDTH_NORMAL, NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT);
			}
			
			VfxFrame *bg_frame;
			VFX_OBJ_CREATE(bg_frame, VfxFrame, custFrame);
			
			if(listMenu->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION)
			{
				bg_frame->setSize(NOTES_APP_LIST_ITEM_BG_FRAME_WIDTH_MARK, NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT);
			}
			else
			{
				bg_frame->setSize(NOTES_APP_LIST_ITEM_BG_FRAME_WIDTH_NORMAL, NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT);
			}
			if(listMenu->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION)
			{
				bg_frame->setPos(NOTES_APP_LIST_ITEM_BG_FRAME_POS_X_MARK,0);
				
			}
			else
			{
				bg_frame->setPos(NOTES_APP_LIST_ITEM_BG_FRAME_POS_X_NORMAL,0);
			}
			

			//bg_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_APP_BG_IMAGE));
			//bg_frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE );

			VfxU8 color;
			/*if(mmi_note_get_color_selected_from_category_screen())*/
			/*any color is selected from category*/
			if(m_color)
			{
				if(g_list_in_search_mode < 2)
				{
					node_index = g_sort_list[index];
				}
				else
				{
					node_index = g_search_sort_list[index];
				}

			}
			else
			{
				if(g_list_in_search_mode < 2)
				{
					node_index = g_venus_mmi_note_cntx.note_list[0].next_node;

					for(int i=0; i < index; i++)
					{
						node_index = g_venus_mmi_note_cntx.note_list[node_index].next_node;
					}
				}
				else
				{			
					node_index = g_search_sort_list[index];
				}
			}

			color = g_venus_mmi_note_cntx.note_list[node_index].category_color;
			//image frame for the back ground image
			VfxFrame *img_frame;
			VFX_OBJ_CREATE(img_frame, VfxFrame, bg_frame);
			//temp code below for the bk ground color	
			if(color == NOTES_CATAEGORY_COLOR_YELLOW)
			{
#ifndef __LOW_COST_SUPPORT_COMMON__		
				img_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_YELLOW));
#else
				img_frame->setBgColor(VfxColor(255, 241, 231, 124));
#endif
			}
		#ifndef __LOW_COST_SUPPORT_COMMON__
			else if(color == NOTES_CATAEGORY_COLOR_GREEN)				
				img_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_GREEN));			
			else if(color == NOTES_CATAEGORY_COLOR_BLUE)				
				img_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_BLUE));
			else if(color == NOTES_CATAEGORY_COLOR_RED)
				img_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_RED));
			else if(color == NOTES_CATAEGORY_COLOR_WHITE)
				img_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_WHITE));				
			else if(color == NOTES_CATAEGORY_COLOR_ORANGE)
				img_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_ORANGE));
		#endif   /*__LOW_COST_SUPPORT_COMMON__*/

			//temp code above for the bk ground color			
			img_frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE );//| VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        		img_frame->setPos(0, 0);
			if(listMenu->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION)
			{
				img_frame->setSize(NOTES_APP_LIST_ITEM_IMG_FRAME_WIDTH_MARK, NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT);
			}
			else
			{
				img_frame->setSize(NOTES_APP_LIST_ITEM_IMG_FRAME_WIDTH_NORMAL,NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT);
			}
			


			//text data on the frame - note string, date and time
			VfxTextFrame *text_string, *text_time;			
			VfxFontDesc   font_size_string, font_size_date, font_size_time;

			/*string data*/

			
			VFX_OBJ_CREATE(text_string, VfxTextFrame, img_frame);
			text_string->setString(VFX_WSTR_MEM((VfxWChar*)g_venus_mmi_note_cntx.note_list[node_index].note_node));						
			//text_string.loadFromMem((VfxWChar*)g_venus_mmi_note_cntx.note_list[node_index].note_node); 				
			text_string->setPos(NOTES_APP_LIST_ITEM_TEXT_FRAME_X,NOTES_APP_LIST_ITEM_TEXT_FRAME_Y);	
			if(listMenu->getMenuMode() == VCP_LIST_MENU_MODE_MULTI_SELECTION)
			{
				text_string->setSize(NOTES_APP_LIST_ITEM_TEXT_FRAME_WIDTH_MARK, NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT);
			}
			else
			{
				text_string->setSize(NOTES_APP_LIST_ITEM_TEXT_FRAME_WIDTH_NORMAL,NOTES_APP_LIST_ITEM_CUST_FRAME_HEIGHT); 
			}
			 
			text_string->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    		//text_string->setColor(VFX_COLOR_BLACK);
			text_string->setColor(VfxColor(255, 21, 21, 21));
			font_size_string.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_LIST_ITEM_MAIN_TEXT_FONT);	
     		text_string->setFont(font_size_string);		

 			/*time data*/
			#ifdef __MMI_NOTE_SORT_BY_MODIFY_TIME__
				cmp_time = g_venus_mmi_note_cntx.note_list[node_index].modify_time;
			#else /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */
				cmp_time = g_venus_mmi_note_cntx.note_list[node_index].create_time;
			#endif /* __MMI_NOTE_SORT_BY_MODIFY_TIME__ */

			VfxU32 localSec = 0;
                localSec = applib_dt_sec_utc_to_local(cmp_time);
                mmi_dt_utc_sec_2_mytime(localSec, &calender_time, MMI_FALSE);
			time_string(&calender_time, (UI_string_type)arr, DT_IDLE_SCREEN);	
			date_string(&calender_time, (UI_string_type)arr2, DT_IDLE_SCREEN);	

			mmi_ucs2cat((S8*)arr, (S8*)(L"  "));
			mmi_ucs2cat((S8*)arr,(S8*)arr2);

			VFX_OBJ_CREATE(text_time, VfxTextFrame, img_frame);
			text_time->setString(VFX_WSTR_MEM((VfxWChar*)arr));						
			//text_time.loadFromMem((VfxWChar*)arr);
			text_time->setPos(NOTES_APP_LIST_ITEM_TIME_TEXT_POS_X,NOTES_APP_LIST_ITEM_TIME_TEXT_POS_Y); 	
			text_time->setColor(VfxColor(255, 80, 80, 80));
			//text_time->setColor(VFX_COLOR_GREY);
			//font_size_time.effect = VFX_FONT_DESC_EFFECT_ENGRAVE;
			font_size_time.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_LIST_ITEM_SUB_TEXT_FONT);	
			text_time->setFont(font_size_time);
			

			return custFrame;
		  }

		return NULL;
	}


void VappNotesPage::vapp_notes_page_onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
	VfxU16 tool_bar_state = 0;
	VfxU16 selected_item_count = 0;
	VfxU16 unselected_item_count = 0;
	
	{
		if(newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
			g_venus_note_mark_cntx.mark_flag[index] = 1;
		else
			g_venus_note_mark_cntx.mark_flag[index] = 0;

		for (int i = 0; i < mmi_notes_get_notes_count_from_category_selected_color(); i++ )
		{	
			if (g_venus_note_mark_cntx.mark_flag[i] == 1)
			{
				tool_bar_state = 1;
				selected_item_count++;
			}
			else
			{
				unselected_item_count++;
			}
		}
	}
	
	
	

	if (tool_bar_state == 1)
	{	
		if(selected_item_count == mmi_notes_get_notes_count_from_category_selected_color())
		{
			del_tool_bar->removeItem(SELECT_ALL_BUTTON);
			del_tool_bar->removeItem(MARK_LIST_DELETE_BUTTON);
			del_tool_bar->removeItem(CANCEL_BUTTON);

			del_tool_bar->addItem(UNSELECT_ALL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_UNSELECT_ALL), IMG_ID_VAPP_NOTES_UNSELECT_ALL);	
			del_tool_bar->setDisableItem(UNSELECT_ALL_BUTTON, VFX_FALSE);
			
			del_tool_bar->addItem(MARK_LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);			
			del_tool_bar->addItem(CANCEL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_CANCEL), IMG_ID_VAPP_NOTES_CANCEL);
			del_tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);

		}
		else
		{
			del_tool_bar->removeItem(SELECT_ALL_BUTTON);
			del_tool_bar->removeItem(UNSELECT_ALL_BUTTON);
			del_tool_bar->removeItem(MARK_LIST_DELETE_BUTTON);
			del_tool_bar->removeItem(CANCEL_BUTTON);

			del_tool_bar->addItem(SELECT_ALL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_SELECT_ALL), IMG_ID_VAPP_NOTES_SELECT_ALL);	
			del_tool_bar->addItem(MARK_LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);			
			del_tool_bar->addItem(CANCEL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_CANCEL), IMG_ID_VAPP_NOTES_CANCEL);
			del_tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);

		}
	}	
	else
	{
		del_tool_bar->setDisableItem(MARK_LIST_DELETE_BUTTON, VFX_TRUE);/*no need to handle*/
		if(unselected_item_count == mmi_notes_get_notes_count_from_category_selected_color())
		{
			del_tool_bar->removeItem(UNSELECT_ALL_BUTTON);
			del_tool_bar->removeItem(MARK_LIST_DELETE_BUTTON);
			del_tool_bar->removeItem(CANCEL_BUTTON);

			del_tool_bar->addItem(SELECT_ALL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_SELECT_ALL), IMG_ID_VAPP_NOTES_SELECT_ALL);	
			
			
			del_tool_bar->addItem(MARK_LIST_DELETE_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_DELETE), IMG_ID_VAPP_NOTES_DELETE);			
			del_tool_bar->setDisableItem(MARK_LIST_DELETE_BUTTON, VFX_TRUE);
			del_tool_bar->addItem(CANCEL_BUTTON, VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTE_CANCEL), IMG_ID_VAPP_NOTES_CANCEL);
			del_tool_bar->m_signalButtonTap.connect(this, &VappNotesPage::vapp_notes_page_tool_bar_button_handler);
		}
	}
}


VcpListMenuItemStateEnum VappNotesPage::getItemState(
        	VfxU32 index   // [IN] index of the item
        	) const
{
	if (g_venus_note_mark_cntx.mark_flag[index] == 1)
		return VCP_LIST_MENU_ITEM_STATE_SELECTED;
	else
		return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
}

void VappNotesPage::onUpdate()
{
	VfxPage::onUpdate();

}

void VappNotesPage::onEntered()
{
//	VfxPage::onEntered();

    checkUpdate();

}

#ifndef __LOW_COST_SUPPORT_COMMON__
void VappNotesCategoryView::onInit()
{
	VfxPage::onInit(); // call base class
   setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
	
	VfxU16 small_button_gap = 0;

	/*add item one by one;*/
	//setBgColor(VFX_COLOR_WHITE);
	VfxFrame *my_bg_frame;
	VFX_OBJ_CREATE(my_bg_frame,VfxFrame,this);
	my_bg_frame->setPos(0, 0);
	my_bg_frame->setSize(LCD_WIDTH,LCD_HEIGHT);  
	//my_bg_frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_APP_BG_IMAGE));
	//my_bg_frame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE );


	VcpButton *m_Bigbutton,*m_buttonWhite,*m_buttonBlue, *m_buttonGreen,*m_buttonYellow,*m_buttonOrange,*m_buttonRed;
	
	VFX_OBJ_CREATE(m_Bigbutton,VcpButton,my_bg_frame);
	m_Bigbutton->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_ALL));
	m_Bigbutton->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_Bigbutton->setRect(VfxRect(NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_X,NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_Y,NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH,NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_HEIGHT));
	m_Bigbutton->setId(VAPP_NOTES_TOTAL_NOTES);
	m_Bigbutton->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_CATEGROY_ALL, IMG_ID_VAPP_NOTES_CATEGROY_ALL, IMG_ID_VAPP_NOTES_CATEGROY_ALL, IMG_ID_VAPP_NOTES_CATEGROY_ALL));
	m_Bigbutton->m_signalClicked.connect(this, &VappNotesCategoryView::vapp_notes_category_page_color_button_handler);

	VfxTextFrame *Total_notes;
	VFX_OBJ_CREATE(Total_notes,VfxTextFrame,m_Bigbutton);
	Total_notes->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);

    Total_notes->setMaxLines(1);
	VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_COUNT_TEXT_FONT);
    Total_notes->setFont(fontDesc);
	Total_notes->setString(VfxWString().format("%d",g_venus_mmi_note_cntx.item_num));
	Total_notes->setFullLineHeightMode(VFX_FALSE);
	U32 text_width = Total_notes->getSize().width;
	U32 text_height = Total_notes->getSize().height;

	VfxTextFrame *Total_notes_tail;
	VFX_OBJ_CREATE(Total_notes_tail,VfxTextFrame,m_Bigbutton);
	VfxFontDesc fontDesc2;
    fontDesc2.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_TAIL_FONT);
    Total_notes_tail->setFont(fontDesc2);
	Total_notes_tail->setString(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_PCS));
	Total_notes_tail->setFullLineHeightMode(VFX_FALSE);
	U32 tail_width = Total_notes_tail->getSize().width;
	U32 tail_height = Total_notes_tail->getSize().height;
	Total_notes->setColor(VFX_COLOR_BLACK);
	U32 height = Total_notes->getRect().getMaxX() + 10;
	Total_notes_tail->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    Total_notes_tail->setMaxLines(1);
	
	Total_notes_tail->setColor(VFX_COLOR_BLACK);

	U32 text_x = (NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH - (text_width + tail_width +NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP))/2;
	U32 text_y = (NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_HEIGHT  -text_height)/2 - NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_SHADOW;
	Total_notes->setPos(text_x,text_y);	 
	
	U32 tail_x = text_x + text_width + NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP;
	U32 tail_y = text_y + text_height -tail_height+NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT_BIG;
	Total_notes_tail->setPos(tail_x ,tail_y);

	VFX_OBJ_CREATE(m_buttonWhite,VcpButton,my_bg_frame);
	m_buttonWhite->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_WHITE));
	m_buttonWhite->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_buttonWhite->setRect(VfxRect(NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_X,NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_Y,NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH,NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_HEIGHT));
	m_buttonWhite->setId(VAPP_NOTES_ONLY_WHITE_NOTES);
	m_buttonWhite->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_WHITE, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_WHITE, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_WHITE, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_WHITE));
	m_buttonWhite->m_signalClicked.connect(this, &VappNotesCategoryView::vapp_notes_category_page_color_button_handler);

	VfxTextFrame *White_notes;
	VFX_OBJ_CREATE(White_notes,VfxTextFrame,m_buttonWhite);
	White_notes->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);

    White_notes->setMaxLines(1);
	//VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_FONT);
    White_notes->setFont(fontDesc);
	White_notes->setString(VfxWString().format("%d",g_venus_mmi_note_cntx.item_num_white));
	White_notes->setFullLineHeightMode(VFX_FALSE);
	 text_width = White_notes->getSize().width;
	text_height = White_notes->getSize().height;
		
	VfxTextFrame *White_notes_tail;
	VFX_OBJ_CREATE(White_notes_tail,VfxTextFrame,m_buttonWhite);
    fontDesc2.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_FONT);
    White_notes_tail->setFont(fontDesc2);
	White_notes_tail->setString(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_PCS));
	White_notes_tail->setFullLineHeightMode(VFX_FALSE);
	 tail_width = White_notes_tail->getSize().width;
	 tail_height = White_notes_tail->getSize().height;
	White_notes->setColor(VFX_COLOR_BLACK);
	// height = Total_notes->getRect().getMaxX() + 10;
	White_notes_tail->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    White_notes_tail->setMaxLines(1);
	
	White_notes_tail->setColor(VFX_COLOR_BLACK);

	small_button_gap = (NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP * NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH)/NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH;
	
	 text_x = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH - (text_width + tail_width +small_button_gap))/2;
	 text_y = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_HEIGHT  -text_height)/2 - NOTES_APP_CATEGORY_SMALL_BUTTON_SHADOW;
	White_notes->setPos(text_x,text_y);	 
	
	 tail_x = text_x + text_width +small_button_gap;
	 tail_y = text_y + text_height -tail_height+NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT;
	White_notes_tail->setPos(tail_x ,tail_y);


	


	VFX_OBJ_CREATE(m_buttonBlue,VcpButton,my_bg_frame);
	m_buttonBlue->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_BLUE));
	m_buttonBlue->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_buttonBlue->setRect(VfxRect(NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_X,NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_Y,NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_WIDTH,NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_HEIGHT));
	m_buttonBlue->setId(VAPP_NOTES_ONLY_BLUE_NOTES);
	//m_buttonBlue->changeVisual(VfxVisualFactory::create(VIS_ID_IMG_BUTTON_EFFECT,m_buttonBlue));
	m_buttonBlue->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_BLUE, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_BLUE, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_BLUE, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_BLUE));
	m_buttonBlue->m_signalClicked.connect(this, &VappNotesCategoryView::vapp_notes_category_page_color_button_handler);

	VfxTextFrame *Blue_notes;
	VFX_OBJ_CREATE(Blue_notes,VfxTextFrame,m_buttonBlue);
	Blue_notes->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);

    Blue_notes->setMaxLines(1);
	//VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_FONT);
    Blue_notes->setFont(fontDesc);
	Blue_notes->setString(VfxWString().format("%d",g_venus_mmi_note_cntx.item_num_blue));
	Blue_notes->setFullLineHeightMode(VFX_FALSE);
	 text_width = Blue_notes->getSize().width;
	text_height = Blue_notes->getSize().height;

	VfxTextFrame *Blue_notes_tail;
	VFX_OBJ_CREATE(Blue_notes_tail,VfxTextFrame,m_buttonBlue);
    fontDesc2.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_FONT);
    Blue_notes_tail->setFont(fontDesc2);
	Blue_notes_tail->setString(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_PCS));
	Blue_notes_tail->setFullLineHeightMode(VFX_FALSE);
	 tail_width = Blue_notes_tail->getSize().width;
	 tail_height = Blue_notes_tail->getSize().height;
	Blue_notes->setColor(VFX_COLOR_BLACK);
	// height = Total_notes->getRect().getMaxX() + 10;
	Blue_notes_tail->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    Blue_notes_tail->setMaxLines(1);
	
	Blue_notes_tail->setColor(VFX_COLOR_BLACK);

small_button_gap = (NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP * NOTES_APP_CATEGORY_PAGE_BLUE_BUTTON_WIDTH)/NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH;
	
	 text_x = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH - (text_width + tail_width +small_button_gap))/2;
	 text_y = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_HEIGHT  -text_height)/2 - NOTES_APP_CATEGORY_SMALL_BUTTON_SHADOW;
	Blue_notes->setPos(text_x,text_y);	 
	
	 tail_x = text_x + text_width +small_button_gap;
	 tail_y = text_y + text_height -tail_height+NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT;
	Blue_notes_tail->setPos(tail_x ,tail_y);



	VFX_OBJ_CREATE(m_buttonGreen,VcpButton,my_bg_frame);
	m_buttonGreen->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_GREEN));
	m_buttonGreen->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_buttonGreen->setRect(VfxRect(NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_X,NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_Y,NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_WIDTH,NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_HEIGHT));
	m_buttonGreen->setId(VAPP_NOTES_ONLY_GREEN_NOTES);
	//m_buttonGreen->changeVisual(VfxVisualFactory::create(VIS_ID_IMG_BUTTON_EFFECT,m_buttonGreen));
	m_buttonGreen->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_GREEN, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_GREEN, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_GREEN, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_GREEN));
	m_buttonGreen->m_signalClicked.connect(this, &VappNotesCategoryView::vapp_notes_category_page_color_button_handler);
	

	VfxTextFrame *Green_notes;
	VFX_OBJ_CREATE(Green_notes,VfxTextFrame,m_buttonGreen);
	Green_notes->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);

    Green_notes->setMaxLines(1);
	//VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_FONT);
    Green_notes->setFont(fontDesc);
	Green_notes->setString(VfxWString().format("%d",g_venus_mmi_note_cntx.item_num_green));
	Green_notes->setFullLineHeightMode(VFX_FALSE);
	 text_width = Green_notes->getSize().width;
	text_height = Green_notes->getSize().height;

	VfxTextFrame *Green_notes_tail;
	VFX_OBJ_CREATE(Green_notes_tail,VfxTextFrame,m_buttonGreen);
    fontDesc2.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_FONT);
    Green_notes_tail->setFont(fontDesc2);
	Green_notes_tail->setString(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_PCS));
	Green_notes_tail->setFullLineHeightMode(VFX_FALSE);
	 tail_width = Green_notes_tail->getSize().width;
	 tail_height = Green_notes_tail->getSize().height;
	Green_notes->setColor(VFX_COLOR_BLACK);
	// height = Total_notes->getRect().getMaxX() + 10;
	Green_notes_tail->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    Green_notes_tail->setMaxLines(1);
	
	Green_notes_tail->setColor(VFX_COLOR_BLACK);
	small_button_gap = (NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP * NOTES_APP_CATEGORY_PAGE_GREEN_BUTTON_WIDTH)/NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH;
	 text_x = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH - (text_width + tail_width +small_button_gap))/2;
	 text_y = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_HEIGHT  -text_height)/2 - NOTES_APP_CATEGORY_SMALL_BUTTON_SHADOW;
	Green_notes->setPos(text_x,text_y);	 
	
	 tail_x = text_x + text_width +small_button_gap;
	 tail_y = text_y + text_height -tail_height+NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT;
	Green_notes_tail->setPos(tail_x ,tail_y);


	VFX_OBJ_CREATE(m_buttonYellow,VcpButton,my_bg_frame);
	m_buttonYellow->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_YELLOW));
	m_buttonYellow->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_buttonYellow->setRect(VfxRect(NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_X,NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_Y,NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_WIDTH,NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_HEIGHT));
	m_buttonYellow->setId(VAPP_NOTES_ONLY_YELLOW_NOTES);
	//m_buttonYellow->changeVisual(VfxVisualFactory::create(VIS_ID_IMG_BUTTON_EFFECT,m_buttonYellow));
	m_buttonYellow->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_YELLOW, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_YELLOW, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_YELLOW, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_YELLOW));
	m_buttonYellow->m_signalClicked.connect(this, &VappNotesCategoryView::vapp_notes_category_page_color_button_handler);

	VfxTextFrame *Yellow_notes;
	VFX_OBJ_CREATE(Yellow_notes,VfxTextFrame,m_buttonYellow);
	Yellow_notes->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);

    Yellow_notes->setMaxLines(1);
	//VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_FONT);
    Yellow_notes->setFont(fontDesc);
	Yellow_notes->setString(VfxWString().format("%d",g_venus_mmi_note_cntx.item_num_yellow));
	Yellow_notes->setFullLineHeightMode(VFX_FALSE);
	 text_width = Yellow_notes->getSize().width;
	text_height = Yellow_notes->getSize().height;

	VfxTextFrame *Yellow_notes_tail;
	VFX_OBJ_CREATE(Yellow_notes_tail,VfxTextFrame,m_buttonYellow);
    fontDesc2.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_FONT);
    Yellow_notes_tail->setFont(fontDesc2);
	Yellow_notes_tail->setString(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_PCS));
	Yellow_notes_tail->setFullLineHeightMode(VFX_FALSE);
	 tail_width = Yellow_notes_tail->getSize().width;
	 tail_height = Yellow_notes_tail->getSize().height;
	Yellow_notes->setColor(VFX_COLOR_BLACK);
	// height = Total_notes->getRect().getMaxX() + 10;
	Yellow_notes_tail->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    Yellow_notes_tail->setMaxLines(1);
	
	Yellow_notes_tail->setColor(VFX_COLOR_BLACK);
small_button_gap = (NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP * NOTES_APP_CATEGORY_PAGE_YELLOW_BUTTON_WIDTH)/NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH;
	
	 text_x = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH - (text_width + tail_width +small_button_gap))/2;
	 text_y = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_HEIGHT  -text_height)/2 - NOTES_APP_CATEGORY_SMALL_BUTTON_SHADOW;
	Yellow_notes->setPos(text_x,text_y);	 
	
	 tail_x = text_x + text_width +small_button_gap;
	 tail_y = text_y + text_height -tail_height+NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT;
	Yellow_notes_tail->setPos(tail_x ,tail_y);


	VFX_OBJ_CREATE(m_buttonOrange,VcpButton,my_bg_frame);
	m_buttonOrange->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_ORANGE));
	m_buttonOrange->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_buttonOrange->setRect(VfxRect(NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_X,NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_Y,NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_WIDTH,NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_HEIGHT));
	m_buttonOrange->setId(VAPP_NOTES_ONLY_ORANGE_NOTES);
	//m_buttonOrange->changeVisual(VfxVisualFactory::create(VIS_ID_IMG_BUTTON_EFFECT,m_buttonOrange));
	m_buttonOrange->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_ORANGE, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_ORANGE, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_ORANGE, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_ORANGE));
	m_buttonOrange->m_signalClicked.connect(this, &VappNotesCategoryView::vapp_notes_category_page_color_button_handler);

	VfxTextFrame *Orange_notes;
	VFX_OBJ_CREATE(Orange_notes,VfxTextFrame,m_buttonOrange);
	Orange_notes->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);

    Orange_notes->setMaxLines(1);
	//VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_FONT);
    Orange_notes->setFont(fontDesc);
	Orange_notes->setString(VfxWString().format("%d",g_venus_mmi_note_cntx.item_num_orange));
	Orange_notes->setFullLineHeightMode(VFX_FALSE);
	 text_width = Orange_notes->getSize().width;
	text_height = Orange_notes->getSize().height;

	VfxTextFrame *Orange_notes_tail;
	VFX_OBJ_CREATE(Orange_notes_tail,VfxTextFrame,m_buttonOrange);
    fontDesc2.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_FONT);
    Orange_notes_tail->setFont(fontDesc2);
	Orange_notes_tail->setString(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_PCS));
	Orange_notes_tail->setFullLineHeightMode(VFX_FALSE);
	 tail_width = Orange_notes_tail->getSize().width;
	 tail_height = Orange_notes_tail->getSize().height;
	Orange_notes->setColor(VFX_COLOR_BLACK);
	// height = Total_notes->getRect().getMaxX() + 10;
	Orange_notes_tail->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    Orange_notes_tail->setMaxLines(1);
	
	Orange_notes_tail->setColor(VFX_COLOR_BLACK);
	small_button_gap = (NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP * NOTES_APP_CATEGORY_PAGE_ORANGE_BUTTON_WIDTH)/NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH;
	
	 text_x = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH - (text_width + tail_width +small_button_gap))/2;
	 text_y = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_HEIGHT  -text_height)/2 - NOTES_APP_CATEGORY_SMALL_BUTTON_SHADOW;
	Orange_notes->setPos(text_x,text_y);	 
	
	 tail_x = text_x + text_width +small_button_gap;
	 tail_y = text_y + text_height -tail_height+NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT;
	Orange_notes_tail->setPos(tail_x ,tail_y);


	VFX_OBJ_CREATE(m_buttonRed,VcpButton,my_bg_frame);
	m_buttonRed->setImgContent(VfxImageSrc(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_RED));
	m_buttonRed->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_buttonRed->setRect(VfxRect(NOTES_APP_CATEGORY_PAGE_RED_BUTTON_X,NOTES_APP_CATEGORY_PAGE_RED_BUTTON_Y,NOTES_APP_CATEGORY_PAGE_RED_BUTTON_WIDTH,NOTES_APP_CATEGORY_PAGE_RED_BUTTON_HEIGHT));
	m_buttonRed->setId(VAPP_NOTES_ONLY_RED_NOTES);
	//m_buttonRed->changeVisual(VfxVisualFactory::create(VIS_ID_IMG_BUTTON_EFFECT,m_buttonRed));
	m_buttonRed->setBgImageList(VcpStateImage(IMG_ID_VAPP_NOTES_CATEGROY_ONLY_RED, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_RED, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_RED, IMG_ID_VAPP_NOTES_CATEGROY_ONLY_RED));
	m_buttonRed->m_signalClicked.connect(this, &VappNotesCategoryView::vapp_notes_category_page_color_button_handler);


	VfxTextFrame *Red_notes;
	VFX_OBJ_CREATE(Red_notes,VfxTextFrame,m_buttonRed);
	Red_notes->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);

    Red_notes->setMaxLines(1);
	//VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_COUNT_TEXT_FONT);
    Red_notes->setFont(fontDesc);
	Red_notes->setString(VfxWString().format("%d",g_venus_mmi_note_cntx.item_num_red));
	Red_notes->setFullLineHeightMode(VFX_FALSE);
	 text_width = Red_notes->getSize().width;
	text_height = Red_notes->getSize().height;

	VfxTextFrame *Red_notes_tail;
	VFX_OBJ_CREATE(Red_notes_tail,VfxTextFrame,m_buttonRed);
    fontDesc2.size = VFX_FONT_DESC_VF_SIZE(NOTES_APP_CATEGORY_PAGE_BUTTON_TAIL_FONT);
    Red_notes_tail->setFont(fontDesc2);
	Red_notes_tail->setString(VFX_WSTR_RES(STR_ID_VAPP_NOTES_NOTES_PCS));
	Red_notes_tail->setFullLineHeightMode(VFX_FALSE);
	 tail_width = Red_notes_tail->getSize().width;
	 tail_height = Red_notes_tail->getSize().height;
	Red_notes->setColor(VFX_COLOR_BLACK);
	// height = Total_notes->getRect().getMaxX() + 10;
	Red_notes_tail->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    Red_notes_tail->setMaxLines(1);
	
	Red_notes_tail->setColor(VFX_COLOR_BLACK);
small_button_gap = (NOTES_APP_CATEGORY_BIG_BUTTON_TEXT_TAIL_GAP * NOTES_APP_CATEGORY_PAGE_RED_BUTTON_WIDTH)/NOTES_APP_CATEGORY_PAGE_BIG_BUTTON_WIDTH;
	
	 text_x = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_WIDTH - (text_width + tail_width +small_button_gap))/2;
	 text_y = (NOTES_APP_CATEGORY_PAGE_WHITE_BUTTON_HEIGHT  -text_height)/2 - NOTES_APP_CATEGORY_SMALL_BUTTON_SHADOW;
	Red_notes->setPos(text_x,text_y);	 
	
	 tail_x = text_x + text_width +small_button_gap;
	 tail_y = text_y + text_height -tail_height+NOTES_APP_CATEGORY_TEXT_TAIL_GAP_ALIGNMENT;
	Red_notes_tail->setPos(tail_x ,tail_y);

}




void VappNotesCategoryView::vapp_notes_category_page_color_button_handler(VfxObject* obj, VfxId id)
{
	/*set here the current color Value and show the notes as per color choice*/
	
	mmi_note_set_color_selected_from_category_screen(id);
 mmi_note_sort_color_based_list(id);

	getMainScr()->popPage();

	if(VAPP_NOTES_TOTAL_NOTES == id)
	{
		if(getMainScr()->getPageCount() == 1)
		{
			return;
		}
		getMainScr()->popPage();	
		return;
	}

	if(getMainScr()->getPageCount() == 1)
	{
		VappNotesPage *scr;
		VFX_OBJ_CREATE_EX(scr, VappNotesPage, getParent(), ((mmi_note_category_color_enum)id));	
		getMainScr()->pushPage(0, scr);
		
	}
	else
	{
		VappNotesPage *scr = (VappNotesPage *)getMainScr()->getPage(0);;
		scr->vapp_notes_list_setColor((mmi_note_category_color_enum)id);
		scr->vapp_notes_list_setNewCategory(VFX_TRUE);
	}

}
#endif  /*__LOW_COST_SUPPORT_COMMON__ */

#endif /*__MMI_NOTE_APP__ */
#endif /* __VAPP_NOTES_LIST_CPP__ */
