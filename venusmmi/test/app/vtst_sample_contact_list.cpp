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
 *  vtst_sample_contact_list.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 *      Sample screens for contact list
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_res_range_def.h"
#include "GlobalResDef.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#ifdef __cplusplus
}   /* extern "C" */
#endif
#include "vfx_config.h"
#ifdef __AFX_RT_TEST__
#include "vtst_sample_contact_list.h"
#include "vtst_rt_main.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_page.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vcp_tool_bar.h"
#include "vfx_config.h"
#include "mmi_rp_vtst_sample_def.h"
#include "vfx_string.h"
#include "vfx_signal.h"
#include "vcp_list_menu.h"
#include "vcp_text_editor.h"
#include "vcp_base_menu.h"
#include "vcp_text_utils.h"
#include "vfx_font_desc.h"
#include "vfx_app.h"
#include "vfx_main_scr.h"
#include "vcp_tabctrl_page.h"
#include "mmi_rp_srv_venus_component_tab_title_bar_def.h"
#include "vcp_state_image.h"
#include "vfx_text_frame.h"
#include "vfx_app_launcher.h"

#define VAPP_TEST_GROUP_NUMBER 3
const VfxWChar* strContactNames[] = 
{
    (const VfxWChar*)L"Ann Visell",
    (const VfxWChar*)L"Andy Sun",
	(const VfxWChar*)L"Denny Huang",
	(const VfxWChar*)L"Dome Lee",
	(const VfxWChar*)L"Dragon T",
	(const VfxWChar*)L"Ellis Lin",
	(const VfxWChar*)L"Evt Lee",
	(const VfxWChar*)L"Evva Ss"
};
const VfxWChar* strContactGroups[]=
{
    (const VfxWChar*)L"A",
    (const VfxWChar*)L"D",
    (const VfxWChar*)L"E",
};

VfxS32 numberContactGroups[]=
{
	2, 3, 3
};
VFX_IMPLEMENT_CLASS("VappTestContactListPage", VappTestContactListPage, VfxPage);
void VappTestContactListPage::onInit()
{
    VfxPage::onInit();
    
	setStatusBar(VFX_TRUE);
	setBgColor(VFX_COLOR_WHITE);  

	VFX_OBJ_CREATE(m_bar, VcpToolBar, this);
#ifdef __AFX_RT_TEST__  /* for image icon */
	m_bar->addItem(1, VFX_WSTR("Add contact"), IMG_TEST_CONTACT_ADD_CONTACT);
	m_bar->addItem(2, VFX_WSTR("Groups"), IMG_TEST_CONTACT_GROUPS);
	m_bar->addItem(3, VFX_WSTR("Multi option"), IMG_TEST_CONTACT_MULTI_OPTION);
	m_bar->addItem(4, VFX_WSTR("Settings"), IMG_TEST_CONTACT_SETTING);
#endif
	m_bar->m_signalButtonTap.connect(this, &VappTestContactListPage::onToolBarClick);
	setBottomBar(m_bar);

// Load group list menu form xml
	VFX_OBJ_CREATE(m_list, VcpGroupListMenu, this);
	m_list->setPos(VfxPoint(0, 0));
	m_list->setSize(320, 355);
	m_list->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);

    m_list->setContentProvider(this);

	m_list->m_signalFocusChanged.connect(this, &VappTestContactListPage::OnListFocused);
	m_list->m_signalItemTapped.connect(this, &VappTestContactListPage::OnListTapped);

	m_list->enableSearchBar();
	m_searchbar = m_list->getSearchBar();
	m_editor = m_searchbar->getSearchEditor();
	m_editor->setHint(VFX_WSTR("Searching"));
	m_editor->m_signalTextChanged.connect(this, &VappTestContactListPage::OnTextChanged);
// search list
	m_search_count = 0;
	m_search_index = 0;
	m_search_text_length = 0;
	m_show_search = VFX_FALSE;
	
}

void VappTestContactListPage::onToolBarClick(VfxObject* sender, VfxId id)
{
	if(sender == m_bar)
	{
		switch(id)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;

		}
	}
}

void VappTestContactListPage::OnTextChanged(VcpTextEditor *editor)
{
	VfxWChar *text;
	text = editor->getText();

	VfxWString string;
	string.loadFromMem(text);
	VfxU32 text_length = string.getLength();

	VfxS32 total_count = 0, index = 0;

	if(text_length == 0)
	{

		if(m_show_search)
		{
			m_show_search = VFX_FALSE;
			m_list->setGroupHeaderHidden(VFX_FALSE);
			m_list->updateAllItems();
		}
		return;
	}
	m_search_text_length = text_length;
	for(index = 0; index <VAPP_TEST_GROUP_NUMBER; index++)
		total_count += numberContactGroups[index];


	VfxS32 start_index = -1, end_index = -1;
	for(VfxS32 i = 0; i<total_count; i++)
	{
		VfxWString tstring;
		VfxS32 j;
		VfxS32 index = -1;
		tstring.loadFromMem(strContactNames[i]);
		VfxS32 length = tstring.getLength();
		if(text_length > length)
			break;

		for(j = 0; j<text_length; j++)
				if (!((text[j] == strContactNames[i][j]) \
					|| ((text[j] +32) == strContactNames[i][j])\
					|| ((text[j] -32) == strContactNames[i][j])))
				{
					index = j;
					break;
				}

	    if(index == -1)
		{
			start_index = i;
			break;
		}

	}

	if(start_index >=0)
	{
		for(VfxS32 i = start_index; i<total_count; i++)
		{
			VfxWString tstring;
			VfxS32 j;
			tstring.loadFromMem(strContactNames[i]);
			VfxS32 length = tstring.getLength();

			if(text_length > length)
				break;

			for(j = 0; j<text_length; j++)
				if (!((text[j] == strContactNames[i][j]) \
					|| ((text[j] +32) == strContactNames[i][j])\
					|| ((text[j] -32) == strContactNames[i][j])))
					break;

			if(j != text_length)
			{
				end_index = i -1;
				break;
			}
		}
	}
	if(end_index == -1)
	{
		m_search_count = 0;
		m_list->setGroupHeaderHidden(VFX_TRUE);
		m_list->updateAllItems();
	}
	else if(end_index >= start_index)
	{
		m_search_index = start_index;
		m_search_count = end_index - start_index +1;
		m_show_search = VFX_TRUE;
		m_list->setGroupHeaderHidden(VFX_TRUE);
		m_list->updateAllItems();
	}
}

void VappTestContactListPage::OnListFocused(VcpGroupListMenu * sender, // Sender
        VcpMenuPos new_pos,        // Current focus list item index
        VcpMenuPos old_pos        // Previous focus list item index
		)
{
	if(sender == m_list)
	{
		if(new_pos.pos!=0xffffffff)
		{
			VfxWString text;
			m_list->getItemTextIfPresent(new_pos,VCP_LIST_MENU_FIELD_TEXT,text);
			//m_editor->setHint(text);
		}
	}
}

void VappTestContactListPage::OnListTapped(VcpGroupListMenu * sender, // Sender
        VcpMenuPos pos)
{
	if(sender == m_list)
	{
		// handle tap event
	}
}

VfxBool VappTestContactListPage::getItemText(
    VcpMenuPos pos,                    // // [IN] the position of item
    VcpListMenuFieldEnum fieldType,    // [IN] the type of the field in the cell
    VfxWString &text,                  // [OUT] the text resource
    VcpListMenuTextColorEnum &color   // [OUT] the text color
    )
{
	if(m_show_search)
	{
		if(m_search_count == 0)
		{
			text.loadFromMem((const VfxWChar*)L"Empty");
		}
		else
		{
		    text.loadFromMem(strContactNames[pos.pos+m_search_index]);
		}
		return VFX_TRUE;
	}
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
	{
		VfxS32 number = 0, index;
		for(index = 0; index <pos.group; index++)
			number += numberContactGroups[index];
		text.loadFromMem(strContactNames[number+pos.pos]);
	}
	else if(fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
	{
		text.loadFromMem(strContactGroups[pos.group]);
	}
    color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;

	return VFX_TRUE;
}

VfxBool VappTestContactListPage::getItemTextFormat(
        VcpMenuPos pos,                  // [IN] the position of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VcpRichText &format          // [OUT] the text resource
        )
{
	if((m_show_search) && (fieldType == VCP_LIST_MENU_FIELD_TEXT) && (m_search_count>0))
	{
		format.setRange(0, m_search_text_length);
		format.setTextColor(VfxColor(VFX_COLOR_WHITE));
		format.setTextBgColor(VfxColor(100, 78, 183, 15));
		format.setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM));
		return VFX_TRUE;
	}
	return VFX_FALSE;
}
// Get the item count of the a group
VfxU32 VappTestContactListPage::getCount(VfxU32 group) const
{
	if(m_show_search)
	{
		return m_search_count;
	}
	else
	{
		return numberContactGroups[group];
	}
}
// Get the group count of the lis menu
VfxU32 VappTestContactListPage::getGroupCount() const
{
    return VAPP_TEST_GROUP_NUMBER;
}


VFX_IMPLEMENT_CLASS("VappTestContact", VappTestContact, VfxApp);

void VappTestContact::onRun(void* args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);
    	
	VappTestContactListScrn *scrn;
    
    VFX_OBJ_CREATE(scrn, VappTestContactListScrn, this);
    scrn->show();
   
}


VFX_IMPLEMENT_CLASS("VappTestContactListScrn", VappTestContactListScrn, VfxMainScr);

void VappTestContactListScrn::on1stReady()
{
    VfxMainScr::on1stReady();

	VappTestContactTabPage *TabPage;
	VFX_OBJ_CREATE(TabPage, VappTestContactTabPage, this);
	pushPage(0, TabPage);
}

VFX_IMPLEMENT_CLASS("VappTestContactTabPage", VappTestContactTabPage, VcpTabCtrlPage);
void VappTestContactTabPage::onInit()
{
	VcpTabCtrlPage::onInit(); // call base class

    // add 3 tab, and set to first
    addTab(1, VFX_WSTR("Dialpad"), VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_DL));
    addTab(2, VFX_WSTR("Call log"), VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CL));
    addTab(3, VFX_WSTR("Contact"), VcpStateImage(VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CT));
    setCurrTab(3);

}

VfxPage *VappTestContactTabPage::onCreateTabPage(VfxId tabId)
{
    // create tab page, and update its content

    switch(tabId)
    {
    case 1:
		VappTestContactOtherPage *page_1;
		VFX_OBJ_CREATE(page_1, VappTestContactOtherPage, this);
		return page_1;
        break;
    case 2:
		VappTestContactOtherPage *page_2;
		VFX_OBJ_CREATE(page_2, VappTestContactOtherPage, this);
		return page_2;
        break;
    case 3:
		VappTestContactListPage *page;
		VFX_OBJ_CREATE(page, VappTestContactListPage, this);
		return page;
        break;
	default:
		VFX_ASSERT(0);
    }

}


VFX_IMPLEMENT_CLASS("VappTestContactOtherPage", VappTestContactOtherPage, VfxPage);
void VappTestContactOtherPage::onInit()
{
    VfxPage::onInit(); // call base class
	setBgColor(VFX_COLOR_WHITE);
	
	VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
    m_text->setPos(VfxPoint(10, 50));
    m_text->setString(VFX_WSTR("Normal"));
	m_text->setColor(VFX_COLOR_BLACK);

    }
/*****************************************************************************
 * Global Function
 *****************************************************************************/

VtstTestResultEnum vtst_contact_list_entry(VfxU32 param)
{
    VFX_UNUSED(param);
	VfxAppLauncher::launchWithAsmSize(
        FW_TEST1+1,
        VFX_OBJ_CLASS_INFO(VappTestContact),
        GRP_ID_ROOT, 204800 * 1,
        NULL, 0);
   return VTST_TR_OK;
}
#endif
