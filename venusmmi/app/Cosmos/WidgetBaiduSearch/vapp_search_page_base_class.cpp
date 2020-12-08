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
 *  vapp_search_page_base_class.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

#if defined(__MMI_BAIDU_SEARCH_COSMOS__) || defined (__MMI_GOOGLE_SEARCH_COSMOS__)

#include "nvram_common_defs.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "vcp_include.h"
#include "vapp_search_page_base_class.h"

extern "C"
{
#include "GlobalResDef.h"   
#include "browser_api.h"
#include "PhbSrvGprot.h" 

#ifndef __MMI_GOOGLE_SEARCH_COSMOS__
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__) 
#include "dcmgr.h" // DCM
#endif
#endif
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
#ifndef __MMI_GOOGLE_SEARCH_COSMOS__
#pragma arm section code = "DYNAMIC_CODE_BAIDUSEARCH_ROCODE", rodata = "DYNAMIC_CODE_BAIDUSEARCH_RODATA"
#endif
//VFX_IMPLEMENT_CLASS("VappSearchWidgetBasePage", VappSearchWidgetBasePage, VfxPage);
VFX_IMPLEMENT_VIRTUAL_CLASS("VappSearchWidgetBasePage", VappSearchWidgetBasePage, VfxPage);

VappSearchWidgetBasePage::VappSearchWidgetBasePage():
	m_textEditor(NULL),
	m_lastEditoLength(0),
	m_count(0),
	m_length(0)
{
}

void VappSearchWidgetBasePage::setListSearchIconID(VfxResId resId)
{
    m_listSearchIconID = resId;
}

void VappSearchWidgetBasePage::setSearchButtonNID(VfxResId resId)
{
    m_searchButtonNID = resId;
}

void VappSearchWidgetBasePage::setSearchButtonPID(VfxResId resId)
{
    m_searchButtonPID = resId;
}

void VappSearchWidgetBasePage::setTitleBGID(VfxResId resId)
{
    m_titleBGID = resId;
}

void VappSearchWidgetBasePage::setSearchStringID(VfxResId resId)
{
    m_searchSTRID = resId;
}

void VappSearchWidgetBasePage::onInit()
{
    VfxPage::onInit(); // call base class

	setStatusBar(VFX_TRUE);

	VcpToolBar *m_toolBar;
	VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    /*
	m_toolBar->addItem(1, VFX_WSTR_RES(STR_ID_SEARCH_WIDGET_SEARCH), VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);//IMG_EMAIL_FTO_ADD);
	m_toolBar->addItem(2, VFX_WSTR_RES(STR_ID_SEARCH_WIDGET_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);*/

	m_toolBar->addItem(1, m_searchSTRID, VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH);    
        m_toolBar->addItem(2, VCP_STR_TOOL_BAR_CANCEL, VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
	
    
	m_toolBar->m_signalButtonTap.connect(this,&VappSearchWidgetBasePage::onBBarClicked);
	setBottomBar(m_toolBar);

	VfxFrame *m_mainFrame;
	VFX_OBJ_CREATE(m_mainFrame, VfxFrame, this);
	m_mainFrame->setPos(0,0);
	m_mainFrame->setBounds(0,0,LCD_WIDTH,LCD_HEIGHT); 
	m_mainFrame->setBgColor(VFX_COLOR_WHITE);

	//VfxImageSrc searchBgImage((VfxResId)IMG_ID_VAPP_TITLE_BG);m_titleBGID
    VfxImageSrc searchBgImage((VfxResId)m_titleBGID);

	VfxFrame *searchFrame;
	VFX_OBJ_CREATE(searchFrame, VfxFrame, m_mainFrame);
	searchFrame->setPos(0,0);
	searchFrame->setImgContent(searchBgImage);
	searchFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	searchFrame->setBounds(0,0,LCD_WIDTH,searchBgImage.getSize().height); //100
	searchFrame->setBgColor(VFX_COLOR_WHITE);
	
	VFX_OBJ_CREATE(m_iconFrame, VfxFrame, searchFrame);
	m_iconFrame->setImgContent(m_iconImage);
	m_iconFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_iconFrame->setAnchor(0.5f,0.5f);
	m_iconFrame->setPos(ICON_POS_X,ICON_POS_Y);
	m_iconFrame->setBounds(0,0,ICON_SIZE,ICON_SIZE);

	VFX_OBJ_CREATE(m_textEditor, VcpTextEditor, searchFrame);
	m_textEditor->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_ZISE)));
	m_textEditor->setPos(TEXT_EDITOR_POS_X,TEXT_EDITOR_POS_Y);
	m_textEditor->setBounds(VfxRect(0, 0, TEXT_EDITOR_POS_WIDTH, TEXT_EDITOR_POS_HEIGHT));
	m_textEditor->setMaxLength(KEY_WORD_MAX_LENGTH-1);
	m_textEditor->m_signalTextChanged.connect(this,&VappSearchWidgetBasePage::onSearchHistory);
	m_textEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
	m_textEditor->activate();

	VFX_ALLOC_MEM(m_keyWord,KEY_WORD_MAX_LENGTH*2,this);

	VcpImageButton *m_imageButton;
	VFX_OBJ_CREATE(m_imageButton,VcpImageButton,searchFrame);
    m_imageButton->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
	m_imageButton->setAnchor(0.5f,0.5f);
    m_imageButton->setPos(VfxPoint(BUTTON_POS_X, BUTTON_POS_Y));
	m_imageButton->setBounds(VfxRect(0, 0, BUTTON_POS_WIDTH, BUTTON_POS_HEIGHT));

    /*VcpStateImage buttonImgList(IMG_ID_VAPP_SEARCH_BUTTON_N,
                              	IMG_ID_VAPP_SEARCH_BUTTON_P,
                              	IMG_ID_VAPP_SEARCH_BUTTON_N,
                              	IMG_ID_VAPP_SEARCH_BUTTON_N);*/

    VcpStateImage buttonImgList(m_searchButtonNID,
                                m_searchButtonPID,
                                m_searchButtonNID,
                                m_searchButtonNID);


    m_imageButton->setImage(buttonImgList);       
	m_imageButton->m_signalClicked.connect(this, &VappSearchWidgetBasePage::onSearchBntClicked);
	
	VFX_OBJ_CREATE(m_listmenu, VcpListMenu, this);

	VfxS32 i;

	for(i=0;i<HISTORY_MAX_COUNT;i++)
	{
		m_strHistory[i] = &(m_buffer[i * KEY_WORD_MAX_LENGTH]);
		memset(m_strHistory[i],0,KEY_WORD_MAX_LENGTH);
	}
	
	loadingSearchHistory();

	for(i=0;i<HISTORY_MAX_COUNT;i++)
	{
		VFX_ALLOC_MEM(m_displayHistory[i],KEY_WORD_MAX_LENGTH*2,this);
		memset(m_displayHistory[i],0,KEY_WORD_MAX_LENGTH*2);
	}
		
	m_listmenu->setPos(VfxPoint(0, searchBgImage.getSize().height));
	//m_listmenu->setSize(VfxSize(getSize()));
	m_listmenu->setBounds(VfxRect(0, 0, LCD_WIDTH,(getSize().height)
        -(searchBgImage.getSize().height)));
	m_listmenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                   VFX_FRAME_ALIGNER_MODE_SIDE,
                                   VFX_FRAME_ALIGNER_MODE_SIDE,
                                   VFX_FRAME_ALIGNER_MODE_SIDE);
	m_listmenu->setContentProvider(this);
	m_listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
	m_listmenu->m_signalItemTapped.connect(this, &VappSearchWidgetBasePage::onItemTap);
	
	for(i=0;i<HISTORY_MAX_COUNT;i++)  // display the history
	{
		if(m_strHistory[i][0]==0 && m_strHistory[i][1]==0)
		{
			break;
		}
		else
		{
			mmi_wcscpy(m_displayHistory[i], m_strHistory[i]);		
		}
	}
	m_count = i;
	m_listmenu->updateAllItems();
	
	VcpFunctionBar *m_funcBar;
    VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, this);

    m_funcBar->addItem(m_searchSTRID,(VfxId)'Save');
    m_funcBar->setItemSpecial('Save');
	m_funcBar->m_signalButtonTap.connect(this,&VappSearchWidgetBasePage::onSearchBntClicked);
    m_textEditor->setFunctionBar(m_funcBar);  
}

void VappSearchWidgetBasePage::onDeinit()
{
	VfxS32 i;

	for(i=0;i<HISTORY_MAX_COUNT;i++)
			VFX_FREE_MEM(m_displayHistory[i]);

	VFX_FREE_MEM(m_keyWord);

	return VfxPage::onDeinit();
}

mmi_ret VappSearchWidgetBasePage::onProc(mmi_event_struct *evt)
{
    return VfxPage::onProc(evt);
}

VfxBool VappSearchWidgetBasePage::onPenInput(VfxPenEvent & event)
{
	switch(event.type)
	{
	case VFX_PEN_EVENT_TYPE_DOWN:
		
		break;
	case VFX_PEN_EVENT_TYPE_UP:

		break;
	}
	return VfxControl::onPenInput(event);
}

void VappSearchWidgetBasePage::setSearchHistory(VfxWChar buffer[2000])
{
	m_buffer = buffer;
}

void VappSearchWidgetBasePage::onSearchBntClicked(VfxObject *obj, VfxId id)
{
	if(m_length!=0)
	{		
		VfxS32 i;
		VfxBool isSameKeyWord = VFX_FALSE;

        for(i=m_length-1;i>=0;i--)  //remove the " " character in the tail
        {
            if(m_keyWord[i]==0)// do nothing
            {
            
            }
            else if(m_keyWord[i]==' ')
            {
                m_keyWord[i] = 0;
            }
            else
            {
                break;
            }
        }


		for(i=0;i<HISTORY_MAX_COUNT;i++) 
		{
			if(mmi_wcsicmp(m_keyWord,m_strHistory[i])==0)
			{
				isSameKeyWord = VFX_TRUE;
				break;
			}
		}
		
		if(isSameKeyWord==VFX_FALSE)
		{
			for(i=HISTORY_MAX_COUNT-1;i>=0;i--)
			{
				if(i==0)
				{
					mmi_wcscpy(m_strHistory[i],m_keyWord );
				}
				else
				{
					mmi_wcscpy(m_strHistory[i],m_strHistory[i-1]);
				}
			}
			writeSearchHistory();  

		}
		m_textEditor->deactivate();
		launchBrowser(m_keyWord);        
		
		m_lastEditoLength = 0;
    onSearchHistory(m_textEditor);  //search again, update the display list
	}	
}

void VappSearchWidgetBasePage::onSearchHistory(VcpTextEditor *editor)
{
	VfxS32 i;

	mmi_wcscpy(m_keyWord,  m_textEditor->getText());

	if(m_keyWord!=NULL)
	{
		VfxWString tstring;
		tstring.loadFromMem(m_keyWord);
		m_length = tstring.getLength();

        for(i=0;i<KEY_WORD_MAX_LENGTH;i++)  //remove the ' ' on the head
        {
            if(m_keyWord[0]==' ')
            {
                VfxS32 j;
                for(j=0;j<m_length;j++)
                {
                    if(j==m_length-1)
                        m_keyWord[j]=0;
                    else
                        m_keyWord[j]=m_keyWord[j+1];
                        
                }
                m_length--;
            }
            else
                break;
        }
        
		VfxWChar * pWCTemp = (VfxWChar *)L"http//:";
		U8 u8TempLen = mmi_wcslen(pWCTemp);
		if(mmi_wcsnicmp(pWCTemp,m_keyWord,u8TempLen)==0) //remvoe the "http//:"
		{
			for(i=0;i<KEY_WORD_MAX_LENGTH;i++)
			{
				if(i>KEY_WORD_MAX_LENGTH-u8TempLen)
					m_keyWord[i] = 0;
				else
					m_keyWord[i] = m_keyWord[i+u8TempLen];
			}

			m_length -= u8TempLen; 
		}

		pWCTemp = (VfxWChar *)L"www.";
		u8TempLen = mmi_wcslen(pWCTemp);	
		if(mmi_wcsnicmp(pWCTemp,m_keyWord,u8TempLen)==0)//remvoe the "www."
		{
			for(i=0;i<KEY_WORD_MAX_LENGTH;i++)
			{
				if(i>KEY_WORD_MAX_LENGTH-u8TempLen)
					m_keyWord[i] = 0;
				else
					m_keyWord[i] = m_keyWord[i+u8TempLen];
			}

			m_length -= u8TempLen; 
		}

		if(m_length==0) 
		{
			for(i=0;i<HISTORY_MAX_COUNT;i++)
			{
				if(m_strHistory[i][0]==0 && m_strHistory[i][1]==0)
				{
					break;
				}
				else
				{
					mmi_wcscpy(m_displayHistory[i], m_strHistory[i]);		
				}
			}

			m_count = i;
		}
		else if((m_length==1) || (m_lastEditoLength>m_length) || (m_lastEditoLength==0))
		{
			VfxU16 searchIndex=0;
			VfxWChar * temp;
			VfxS32 j;
			
			VFX_ALLOC_MEM(temp,KEY_WORD_MAX_LENGTH*2*(1+MAX_PINYIN_LEN),this);  // Long enough. But the case of using the whole mem is rare. Maybe, len can be less.
			for(i=0;i<HISTORY_MAX_COUNT;i++)
			{				
				memset(temp,0,KEY_WORD_MAX_LENGTH*2*(1+MAX_PINYIN_LEN));
				srv_phb_convert_to_pinyin( (U16 *) m_strHistory[i], (U16 *)temp, KEY_WORD_MAX_LENGTH); //the convert result is Pinyin+characters,eg, input "中国",output "zhong中guo国"

				for(j=0;j<KEY_WORD_MAX_LENGTH;j++) //remove the characters, maybe can't do this step,it is a bug?!
				{
					if(temp[j]>=0x4e00 && temp[j]<=0x9fa5) // 0x4e00, 0x9fa5 -- unicode for the first and the last character 
					{
						VfxS32 m;
						for(m=j;m<KEY_WORD_MAX_LENGTH;m++)
						{
							if(m==(KEY_WORD_MAX_LENGTH-1))
							{
								temp[m]=0;
							}
							else
							{
								temp[m]=temp[m+1];
							}
						}
						j--;
					}
				}

                 for(j=0;j<m_length;j++)
                {
    				if ((m_keyWord[j] == m_strHistory[i][j]) \
    					|| ((m_keyWord[j]>=L'A'&& m_keyWord[j]<=L'Z') \
    					&& (m_keyWord[j] +32) == m_strHistory[i][j])\
    					|| ((m_keyWord[j]>=L'a'&& m_keyWord[j]<=L'z') \
    					&& (m_keyWord[j] -32) == m_strHistory[i][j]))  //search OK
				{					
    					//mmi_wcscpy(m_displayHistory[searchIndex], m_strHistory[i]);		
    					//searchIndex++;
				}
    				else if((m_keyWord[j] == temp[j]) \
    					|| ((m_keyWord[j]>=L'A'&& m_keyWord[j]<=L'Z') \
    					&& (m_keyWord[j] +32) == temp[j]) \
    					|| ((m_keyWord[j]>=L'a'&& m_keyWord[j]<=L'z') \
    					&& (m_keyWord[j] -32) == temp[j])) //convert to pinyin,search OK
				{
    					//mmi_wcscpy(m_displayHistory[searchIndex], m_strHistory[i]);		
    					//searchIndex++;
				}
				else  //search NG 
				{
    				    break;
					// Do nothing
				}
                }

                if(j==m_length)
                {
                    mmi_wcscpy(m_displayHistory[searchIndex], m_strHistory[i]);		
    				searchIndex++;
                }
			}

			VFX_FREE_MEM(temp);
			
			m_count = searchIndex;
		
		}
		else
		{
			VfxU16 searchIndex=0;
			VfxWChar * temp;
			
			VFX_ALLOC_MEM(temp,KEY_WORD_MAX_LENGTH*2*(1+MAX_PINYIN_LEN),this);  // Long enough. But the case of using the whole mem is rare. Maybe, len can be less.

			for(i=0;i<(VfxS32)getCount();i++)
			{
				VfxS32 j;
				
				memset(temp,0,KEY_WORD_MAX_LENGTH*2*(1+MAX_PINYIN_LEN));
				srv_phb_convert_to_pinyin( (U16 *) m_displayHistory[i], (U16 *)temp, KEY_WORD_MAX_LENGTH); //the convert result is Pinyin+characters,eg, input "中国",output "zhong中guo国"

				for(j=0;j<KEY_WORD_MAX_LENGTH;j++) //remove the characters, maybe can't do this step,it is a bug?!
				{
					if(temp[j]>=0x4e00 && temp[j]<=0x9fa5)	
					{
						VfxS32 m;
						for(m=j;m<KEY_WORD_MAX_LENGTH;m++)
						{
							if(m==(KEY_WORD_MAX_LENGTH-1))
							{
								temp[m]=0;
							}
							else
							{
								temp[m]=temp[m+1];
							}
						}
						j--;
					}
				}

				if ((m_keyWord[m_length-1] == m_displayHistory[i][m_length-1]) \
					|| ((m_keyWord[m_length-1]>=L'A'&& m_keyWord[m_length-1]<=L'Z') \
					&& (m_keyWord[m_length-1] +32) == m_displayHistory[i][m_length-1])\
					|| ((m_keyWord[m_length-1]>=L'a'&& m_keyWord[m_length-1]<=L'z') \
					&& (m_keyWord[m_length-1] -32) == m_displayHistory[i][m_length-1]))  //search OK
				{
					mmi_wcscpy(m_displayHistory[searchIndex], m_displayHistory[i]);		
					searchIndex++;
				}
				else if((m_keyWord[m_length-1] == temp[m_length-1]) \
					|| ((m_keyWord[m_length-1]>=L'A'&& m_keyWord[m_length-1]<=L'Z') \
					&& (m_keyWord[m_length-1] +32) == temp[m_length-1]) \
					|| ((m_keyWord[m_length-1]>=L'a'&& m_keyWord[m_length-1]<=L'z') \
					&& (m_keyWord[m_length-1] -32) == temp[m_length-1])) //convert to pinyin,character
				{
					mmi_wcscpy(m_displayHistory[searchIndex], m_displayHistory[i]);		
					searchIndex++;
				}
				else  //search NG.
				{
					// do nothing
				}
                
			}
			
			VFX_FREE_MEM(temp);

			m_count = searchIndex;
		}
		
		m_listmenu->updateAllItems();
		m_lastEditoLength=m_length;
	}

}

void VappSearchWidgetBasePage::onItemTap(VcpListMenu *listmenu, VfxU32 id)
{
	VfxWString tempStr;
	
	m_listmenu->getItemTextIfPresent(id,VCP_LIST_MENU_FIELD_TEXT,tempStr);
	m_textEditor->deactivate();
	launchBrowser((VfxWChar *)tempStr.getBuf());
}

void VappSearchWidgetBasePage::onBBarClicked(VfxObject *obj, VfxId id)
{
	if(id==1)
	{	
		onSearchBntClicked(obj, id);
	}
	else
	{
		m_textEditor->deactivate();
		getApp()->exit();
	}

}

void VappSearchWidgetBasePage::setIcon(VfxImageSrc iconImage)
{
	m_iconImage = iconImage; 
	
}

VfxBool VappSearchWidgetBasePage::getItemText(
	VfxU32 index,					 
	VcpListMenuFieldEnum fieldType,  
	VfxWString &text,				 
	VcpListMenuTextColorEnum &color  
	)
{
	if(m_count>0)
		text.loadFromMem(m_displayHistory[index]);

	
	return VFX_TRUE;
}
VfxBool VappSearchWidgetBasePage::getItemImage(
	VfxU32 index,					 
	VcpListMenuFieldEnum fieldType,  
	VfxImageSrc &image				
	)
{
	if(fieldType == VCP_LIST_MENU_FIELD_ICON)
	{
		//image.setResId(IMG_ID_VAPP_SEARCH_ICON);
		image.setResId(m_listSearchIconID);
	}

	return VFX_TRUE;
}

VfxU32 VappSearchWidgetBasePage::getCount() const
{
	return m_count;
}
#ifndef __MMI_GOOGLE_SEARCH_COSMOS__
#pragma arm section code, rodata
#endif
#endif /* defined(__MMI_BAIDU_SEARCH_COSMOS__) || defined (__MMI_GOOGLE_SEARCH_COSMOS__) */

