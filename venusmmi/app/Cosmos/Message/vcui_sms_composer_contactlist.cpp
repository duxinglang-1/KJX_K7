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
 *  vcui_sms_composer_contactlist.cpp
 *
 * Project:
 * --------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/ 
#include "mmi_features.h" 
#ifdef __MMI_SMS_COMPOSER__
#include "vfx_uc_include.h"
#include "vapp_contact_entry.h"
#include "vcui_sms_composer_contactlist.h"
#ifdef __MMI_VUI_COSMOS_CP__
#include "mmi_rp_app_cosmos_global_def.h"
#endif
#include "mmi_rp_vapp_dialer_def.h"
#ifdef __MMI_EMAIL__
#include "..\Email\vapp_email_composer.h"
extern "C"
{
	#include "EmailSrvgprot.h"
}
#endif


VFX_IMPLEMENT_CLASS("VcuiSmsComposerContactList", VcuiSmsComposerContactList, VfxFrame);
void VcuiSmsComposerContactList::onInit()
{
	VfxFrame::onInit();	
	vrt_size_struct mainScreenSize;

    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
	
	VFX_OBJ_CREATE(m_contactlist, ContactList, this);
	this->m_contactlist->m_signalReady.connect(this, &VcuiSmsComposerContactList::onListReady);
    this->m_contactlist->m_signalRefresh.connect(this, &VcuiSmsComposerContactList::onListRefresh);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	/* set the size depending upon the number of items*/
	
	this->setSize(mainScreenSize.width, mainScreenSize.height);

}

VfxBool VcuiSmsComposerContactList::getItemText(
		VfxU32 index,                    // [IN] the index of item
		VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
		VfxWString &text,                // [OUT] the text resource
		VcpListMenuTextColorEnum &color  // [OUT] the text color
		)
{
#ifdef __MMI_EMAIL__
  	if (m_contactlisttype == ENUM_VCUI_SMSC_CONTACTLIST_TYPE_EMAIL)
	{
		WCHAR address[200];
		VfxWChar* startPos = (VfxWChar*)mmi_ucs2str((CHAR*)m_hinttext.getBuf(), (CHAR*)"@");		
		if (startPos != NULL)
		{
			VappEmailComp::queryRecentContact(index , address, startPos + 1);
		}
		else
		{
	            VappEmailComp::queryRecentContact(index , address);
		}
		if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
		{			
			text.loadFromMem(address);
		}
	/*//	else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
		{
	//		text.loadFromMem(address);
		}*/

	}
	else 
#endif
	{   
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
	    {
            ContactEntry entry(m_contactlist->getId(index));
		    text = entry.getName().getString();
	    }
	    else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
	    {
            ContactEntry entry(m_contactlist->getId(index));
	        VfxU32 type = m_contactlist->getType(index);
	        VfxU32 subType = m_contactlist->getSubType(index);
	        VfxU32 subId = m_contactlist->getSubId(index);
	        switch(type)
	        {
	        case MMI_PHB_CONTACT_FIELD_ID_NUMBER:
	        {
			    VappContactNumber num = entry.getNumberById(subId);
			    text = num.getLabel();
			    text += VFX_WSTR(": ");
			    text += num.getString();			
	        }
		    break;
	        case MMI_PHB_CONTACT_FIELD_ID_EMAIL:
			    {
				    VappContactEmail Email = entry.getEmailById(subId);
				    text = Email.getLabel();							  
				    text += VFX_WSTR(": ");
				    text += Email.getString();
				    /*text = VFX_WSTR("Email: ");
				    text += entry.getEmailById(subId).getString();   */
			    }
			    break;
	        default:
	            break;
	        }
	    }	
	}

    color = VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT;


	return VFX_TRUE;
}

VfxBool VcuiSmsComposerContactList::getItemTextFormat(
					VfxU32 index,                    // [IN] the index of item
					VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
					VcpRichText &format        // [OUT] the text resource
            )
{
#ifdef __MMI_EMAIL__
  	if (m_contactlisttype == ENUM_VCUI_SMSC_CONTACTLIST_TYPE_EMAIL)
	{
	}
	else
#endif
	{
		VfxFontDesc font;
		ContactMatchInfo matchInfo = m_contactlist->getMatchInfo(index);
		//Get the highlighter position from the starting point
		VfxPoint range = matchInfo.getRange(0);
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT && 
			matchInfo.m_field == MMI_PHB_CONTACT_FIELD_ID_NAME)
        {
			//font.attr |= VFX_FONT_DESC_ATTR_BOLD;
			font.size = VCP_LIST_MENU_FONT_SIZE_MEDIUM;
			format.setTextBgColor(VfxColor(VFX_COLOR_RES(COL_ID_DIALER_HINT_BG)));			
			//format.setTextColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
			format.setTextColor(VfxColor(VCP_FORM_DARK_FONT_COLOR));
			format.setRange(range.x, range.y);
			format.setFont(font);
			return VFX_TRUE;
		}
		else if ((fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1 &&
			matchInfo.m_field == MMI_PHB_CONTACT_FIELD_ID_NUMBER))
		{
			ContactEntry entry(m_contactlist->getId(index));
			VfxU32 subId = m_contactlist->getSubId(index);
			VappContactNumber num = entry.getNumberById(subId);
			VfxU32 offset = num.getLabel().getLength() + 2;
			
			font.attr |= VFX_FONT_DESC_ATTR_BOLD;
			font.size = VCP_LIST_MENU_FONT_SIZE_SMALL;
			format.setTextBgColor(VfxColor(VFX_COLOR_RES(COL_ID_DIALER_HINT_BG)));			
			//format.setTextColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
			format.setTextColor(VfxColor(VCP_FORM_DARK_FONT_COLOR));
			//format.setRange(matchInfo.m_head + offset , matchInfo.m_tail + offset);
			format.setRange(range.x + offset, range.y + offset);
			format.setFont(font);
			return VFX_TRUE;
		}
	}
    
    return VFX_FALSE;
}

VfxU32 VcuiSmsComposerContactList::getCount() const
{
#ifdef __MMI_EMAIL__
	if (m_contactlisttype == ENUM_VCUI_SMSC_CONTACTLIST_TYPE_EMAIL)
	{
		VfxWChar* startPos = (VfxWChar*)mmi_ucs2str((CHAR*)m_hinttext.getBuf(), (CHAR*)"@");
		if (startPos != NULL)
		{
			return VappEmailComp::queryRecentContactCount(startPos + 1);
		}
		else
		{
			return VappEmailComp::queryRecentContactCount();
		}
	}
	else
#endif
	{
	    if (m_contactlist != NULL)
	    {
		    return m_contactlist->getCount();
	    }
	    else
	    {
		    return 0;
	    }
	}

}
VfxBool VcuiSmsComposerContactList::getItemImage(
		VfxU32 index,                    
		VcpListMenuFieldEnum fieldType,  
		VfxImageSrc &image         
		)
{
#ifdef __MMI_EMAIL__
	if (m_contactlisttype == ENUM_VCUI_SMSC_CONTACTLIST_TYPE_EMAIL)
	{
	}
	else 
#endif
	{
	    if (fieldType == VCP_LIST_MENU_FIELD_ICON)
	    {
		    image = ContactStorage::getIcon(m_contactlist->getId(index));
		    return VFX_TRUE;
	    }
	}

	return VFX_FALSE;

}


VcuiSmsComposerContactList::VcuiSmsComposerContactList(VfxS32 len):
    m_hintlength(len),
    m_listmenu(NULL),
    m_contactlist(0)
{   
}
												

void VcuiSmsComposerContactList::updateHintList(VfxWChar *text)
{
	m_hintlength = vfx_sys_wcslen(text);
	m_hinttext.loadFromMem((VfxWChar *)text);
#ifdef __MMI_EMAIL__
	VfxWChar* startPos = NULL;
	startPos = (VfxWChar*)mmi_ucs2str((CHAR*)text, (CHAR*)"@");
	if (!(m_alignField & MMI_PHB_CONTACT_FIELD_NUMBER) && startPos != NULL && startPos > text)
	{
                m_contactlisttype = ENUM_VCUI_SMSC_CONTACTLIST_TYPE_EMAIL;
		if (VappEmailComp::queryRecentContactCount(startPos + 1) > 0)
		{
			if (m_listmenu == NULL)
			{
				VFX_OBJ_CREATE(m_listmenu, VcpListMenu, this);
				this->m_listmenu->setContentProvider(this);
				this->m_listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT); // Set a single text cell style	
				this->m_listmenu->setSize(this->getSize().width, this->getSize().height);
				this->m_listmenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
									VFX_FRAME_ALIGNER_MODE_SIDE, 
									VFX_FRAME_ALIGNER_MODE_SIDE,
									VFX_FRAME_ALIGNER_MODE_SIDE);
			
			}
		}
		else if (m_listmenu != NULL)
		{
			VFX_OBJ_CLOSE(m_listmenu);
			m_listmenu = NULL;
		}

		m_signalListUpdated.postEmit(VappEmailComp::queryRecentContactCount(startPos + 1));	
		if (m_listmenu)
		{
		    this->m_listmenu->resetAllItems(VFX_TRUE);
	        }
	}
	else
#endif
	{
	      m_contactlisttype = ENUM_VCUI_SMSC_CONTACTLIST_TYPE_PHBOOK;
	      this->setSearchString(m_hinttext);
	      this->setAlignField(m_alignField);
	      this->getList();
    }
}


void VcuiSmsComposerContactList::setSearchString(const VfxWString& search)
{
	// query result
    m_contactlist->setQuery(search, MMI_PHB_CONTACT_FIELD_NAME | m_alignField);
}

void VcuiSmsComposerContactList::setAlignField(VfxU32 alignField)
{
	m_alignField = alignField;
	m_contactlist->setAlignField(alignField);
}

void VcuiSmsComposerContactList::getList()
{
    m_contactlist->getList();
}
void VcuiSmsComposerContactList::onListReady()
{
#ifdef __MMI_EMAIL__
	if (m_contactlisttype != ENUM_VCUI_SMSC_CONTACTLIST_TYPE_EMAIL)
#endif
	{
	    vrt_size_struct mainScreenSize;
	    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    
	    if (m_contactlist->getCount() != 0 )
	    {
		    if (m_listmenu == NULL)
		    {
			    VFX_OBJ_CREATE(m_listmenu, VcpListMenu, this);
			    this->m_listmenu->setContentProvider(this);
			    this->m_listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT); // Set a single text cell style	
			    this->m_listmenu->setSize(this->getSize().width, this->getSize().height);
			    this->m_listmenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, 
								    VFX_FRAME_ALIGNER_MODE_SIDE, 
								    VFX_FRAME_ALIGNER_MODE_SIDE,
								    VFX_FRAME_ALIGNER_MODE_SIDE);
			    
		    }
        this->m_listmenu->resetAllItems(VFX_TRUE);
    }
	    else if (m_listmenu != NULL)
	    {
		    VFX_OBJ_CLOSE(m_listmenu);
		    m_listmenu = NULL;
	    }
	    m_signalListUpdated.emit(m_contactlist->getCount());
    }
}


void VcuiSmsComposerContactList::onListRefresh(ContactList* list, mmi_event_struct* evt)
{
    getList();
}

#endif /* __MMI_SMS_COMPOSER__ */
