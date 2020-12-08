
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * BrowserUIPlugIn.c
 *
 * Project:
 * --------
 *   MAUI
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
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _VAPP_BRW_URL_INPUT_CPP_
#define _VAPP_BRW_URL_INPUT_CPP_

/*  Include: MMI header file */
#ifdef __MMI_BROWSER_2__

#include "vapp_brw_url_input.h"
#include "vapp_brw_main.h"
#include "vapp_brw_interface.h"
#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */
#include "BrowserSrvInterface.h"
#include "Conversions.h"
#include "CbmSrvGprot.h"
#ifdef __cplusplus
}
#endif /* __cplusplus */


VfxBool VappBrowserSearchListDataProvider::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color
    )
{
    if(getCount() == 0 || index >= getCount())
    {
        return VFX_TRUE;
    }
    VfxU8 addressListCount = 0;
	#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    addressListCount = srv_brw_address_list_get_matched_item_count();
	#endif
    VfxU8 bookmarksListCount = srv_brw_bookmark_list_get_matched_item_count();
    VfxU8 searchListCount ;
	#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    if(m_searchItemsEnabled)
    {
        searchListCount = srv_brw_search_list_get_matched_item_count();
    }
    else
	#endif
    {
        searchListCount = 0;
    }

    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
    	#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        if(m_searchItemsEnabled)
        {
            if(index >= addressListCount && index < (addressListCount + searchListCount))
            {
                VfxWChar *textBuff = text.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
                mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                    (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, 
                    (U8*) srv_brw_search_list_get_matched_item((S32)(index - addressListCount)));
                text.unlockBuf();
                return VFX_TRUE;
            }
        }
		#endif
		#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
        if(index < addressListCount)
        {
            MMI_BOOL isAscii = MMI_TRUE;
            VfxS8* titlePtr = (VfxS8*)srv_brw_address_list_get_matched_item_title((S32)index, &isAscii);
            VfxWChar *textBuff = text.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
            if(isAscii)
            {
                mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                    (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH, 
                    (U8*) titlePtr);
            }
            else
            {
                mmi_ucs2ncpy((CHAR*) textBuff, (CHAR*) titlePtr , SRV_BRW_MAX_TITLE_LENGTH);
            }
			if(text.isEmpty())
			{
            	mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*) srv_brw_address_list_get_matched_item((S32)index));
			}
            text.unlockBuf();
        }
		#endif
        if(index >= (addressListCount + searchListCount))
        {
            VfxS8* titlePtr = (VfxS8*)srv_brw_bookmark_list_get_matched_item_title((S32)index - (addressListCount + searchListCount));
            VfxWChar *textBuff = text.lockBuf((SRV_BRW_MAX_TITLE_LENGTH + 1) *ENCODING_LENGTH);
            mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*) titlePtr);
            text.unlockBuf();
        }
    }
    else if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
    	#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        if(m_searchItemsEnabled)
        {
            if(index >= addressListCount && index < (addressListCount + searchListCount))
            {
                switch(srv_brw_search_list_get_matched_item_search_engine((S32)index - addressListCount))
                {
                    case SRV_BRW_SEARCH_ENGINE_BAIDU:
                    {
                        text.loadFromRes(STR_ID_VAPP_BRW_BAIDU);
						break;
                    }

                    case SRV_BRW_SEARCH_ENGINE_GOOGLE:
                    {
                        text.loadFromRes(STR_ID_VAPP_BRW_GOOGLE);
						break;
                    }

                    case SRV_BRW_SEARCH_ENGINE_YAHOO:
                    {
                        text.loadFromRes(STR_ID_VAPP_BRW_YAHOO);
						break;
                    }

                    case SRV_BRW_SEARCH_ENGINE_BING:
                    {
                        text.loadFromRes(STR_ID_VAPP_BRW_BING);
						break;
                    }
                }
                return VFX_TRUE;
            }
        }
		#endif
		if(index >= getCount())
		{
			//this if here  just avoids the macro error
			return VFX_TRUE;
		}
		#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
        else if(index < addressListCount)
        {
            VfxWChar *textBuff = text.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
            mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*) srv_brw_address_list_get_matched_item((S32)index));
            text.unlockBuf();
        }
		#endif
        else if(index >= (addressListCount + searchListCount))
        {
            VfxWChar *textBuff = text.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
            mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*) srv_brw_bookmark_list_get_matched_item((S32)index - (addressListCount + searchListCount)));
            text.unlockBuf();
        }
    }

    return VFX_TRUE;
}

VfxBool VappBrowserSearchListDataProvider::getItemImage(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxImageSrc &image
        )
{
    if(fieldType == VCP_LIST_MENU_FIELD_ICON)
    {
    	VfxU8 addressListCount = 0;
    	#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
        addressListCount = srv_brw_address_list_get_matched_item_count();
		#endif
        VfxU8 bookmarksListCount = srv_brw_bookmark_list_get_matched_item_count();
        VfxU8 searchListCount ;
		#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        if(m_searchItemsEnabled)
        {
            searchListCount = srv_brw_search_list_get_matched_item_count();
        }
        else
		#endif
        {
            searchListCount = 0;
        }
		if(index >= getCount())
		{
			return VFX_FALSE;
		}
		#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
        else if(index < addressListCount)
        {
            image.setResId(IMG_ID_VAPP_BRW_LIST_ICON_URL_RESULT);
        }
		#endif
		#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        else if(index >= addressListCount && index < (addressListCount + searchListCount))
        {
            image.setResId(IMG_ID_VAPP_BRW_LIST_ICON_SEARCH_RESULT);
        }
		#endif
        else if(index >= (addressListCount + searchListCount))
        {
            image.setResId(IMG_ID_VAPP_BRW_LIST_ICON_USER_BKM_FILE);
        }
    }
    return VFX_TRUE;
}

VfxBool VappBrowserSearchListDataProvider::getItemTextFormat(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VcpRichText &format)
{

    if(getCount() == 0 || index >= getCount())
    {
        return VFX_FALSE;
    }
	
    VfxU8 addressListCount = 0;
	#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    addressListCount = srv_brw_address_list_get_matched_item_count();
	#endif
    VfxU8 bookmarksListCount = srv_brw_bookmark_list_get_matched_item_count();
    VfxU8 searchListCount ;
	#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    if(m_searchItemsEnabled)
    {
        searchListCount = srv_brw_search_list_get_matched_item_count();
    }
    else
	#endif
    {
        searchListCount = 0;
    }

    VfxWString text;
    text.setEmpty();
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
    	#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        if(m_searchItemsEnabled)
        {
            if(index >= addressListCount && index < (addressListCount + searchListCount))
            {
                VfxWChar *textBuff = text.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
                mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                    (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, 
                    (U8*) srv_brw_search_list_get_matched_item((S32)(index - addressListCount)));
                text.unlockBuf();
            }
        }
		#endif
		#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
        if(index < addressListCount)
        {
            MMI_BOOL isAscii = MMI_TRUE;
            VfxS8* titlePtr = (VfxS8*)srv_brw_address_list_get_matched_item_title((S32)index, &isAscii);
            VfxWChar *textBuff = text.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
            if(isAscii)
            {
                mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                    (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH, 
                    (U8*) titlePtr);
            }
            else
            {
                mmi_ucs2ncpy((CHAR*) textBuff, (CHAR*) titlePtr , SRV_BRW_MAX_TITLE_LENGTH);
            }
			if(text.isEmpty())
			{
            	mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*) srv_brw_address_list_get_matched_item((S32)index));
			}
            text.unlockBuf();
        }
		#endif
        if(index >= (addressListCount + searchListCount))
        {
            VfxS8* titlePtr = (VfxS8*)srv_brw_bookmark_list_get_matched_item_title((S32)index - (addressListCount + searchListCount));
            VfxWChar *textBuff = text.lockBuf((SRV_BRW_MAX_TITLE_LENGTH + 1) *ENCODING_LENGTH);
            mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                (SRV_BRW_MAX_TITLE_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*) titlePtr);
            text.unlockBuf();
        }
    }
    else if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
    	#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        if(m_searchItemsEnabled)
        {
            if(index >= addressListCount && index < (addressListCount + searchListCount))
            {
                return VFX_FALSE;
            }
        }
		#endif
		
		if(index >= getCount())
		{
			return VFX_FALSE;
		}
		#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
        else if(index < addressListCount)
        {
            VfxWChar *textBuff = text.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
            mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*) srv_brw_address_list_get_matched_item((S32)index));
            text.unlockBuf();
        }
		#endif
        else if(index >= (addressListCount + searchListCount))
        {
            VfxWChar *textBuff = text.lockBuf((SRV_BRW_MAX_URL_LENGTH + 1) *ENCODING_LENGTH);
            mmi_chset_utf8_to_ucs2_string((U8*)textBuff, 
                (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*) srv_brw_bookmark_list_get_matched_item((S32)index - (addressListCount + searchListCount)));
            text.unlockBuf();
        }
    }
    VfxU32 inputTextLength = m_inputText.getLength();
    VfxU32 matchedTextLength = text.getLength();
    WCHAR *matchedTextPortion = NULL;
	VfxWString pos = VfxWString(VFX_WSTR("://"));
	VfxWString dot = VfxWString(VFX_WSTR("."));
	VfxWChar *pSearchText = mmi_wcsupr((WCHAR*)m_inputText.getBuf());
    VfxWChar *pTargetText = mmi_wcsupr((WCHAR*)text.getBuf());
    if(inputTextLength > 0)
    {
    	// the follow change fixed the MAUI_03113482 and the MAUI_03126718
    	if(fieldType == VCP_LIST_MENU_FIELD_TEXT) // for the title matched
    	{
			matchedTextPortion = mmi_wcsstr(pTargetText, pSearchText);
		}
    	else if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1) // for the url matched
    	{
			if(inputTextLength > 6)
    	{
	        	matchedTextPortion = mmi_wcsstr(pTargetText, pSearchText);
    }
		else
		{
				matchedTextPortion = mmi_wcsstr(pTargetText, (WCHAR*)pos.getBuf());
				matchedTextPortion += 3; // remove "://"

				if(matchedTextLength < inputTextLength) //protect the for  loop
				{
					return VFX_FALSE;
				}
				while(matchedTextPortion != NULL)
				{
					if(*matchedTextPortion == *pSearchText)//first char match 
					{
						VfxBool m_isBreak = VFX_TRUE;
						if(inputTextLength > 1)
						{
							for(int i=0; i<inputTextLength; i++)
							{
								if(*(matchedTextPortion+i) != *(pSearchText+i))
								{
									m_isBreak = VFX_FALSE;
								}
							}
						}
						if(m_isBreak)
						{
							break;
						}else
						{
							matchedTextPortion = mmi_wcsstr(matchedTextPortion , (WCHAR*)dot.getBuf());
			if(matchedTextPortion != NULL)
			{
								matchedTextPortion ++; // remove "."
							}
						}

					}
					else
					{
						matchedTextPortion = mmi_wcsstr(matchedTextPortion , (WCHAR*)dot.getBuf());
						if(matchedTextPortion!=NULL)
						{
							matchedTextPortion ++; // remove "."
						}
					}
				}
				if(matchedTextPortion != NULL)
				{
					//matchedTextPortion = mmi_wcsstr(pTargetText, pSearchText);
					matchedTextPortion = mmi_wcsstr(matchedTextPortion, pSearchText);
			}
			
		}
	        
		}
		//end for fix issues modification
		
        //matchedTextPortion = mmi_wcsstr((WCHAR*)text.getBuf(), (WCHAR*)m_inputText.getBuf());
    }
    if(!matchedTextPortion)
    {
        return VFX_FALSE;
    }
    VfxU32 matchedTextPortionLength = mmi_wcslen(matchedTextPortion);
    VfxU32 startIndex = matchedTextLength - matchedTextPortionLength;
    format.setRange(startIndex, startIndex + inputTextLength);
    format.setTextBgColor(VfxColor(VFX_COLOR_RES(CLR_COSMOS_BG_SEARCH)));
    format.setTextColor(VfxColor(VCP_FORM_DARK_FONT_COLOR));
    return VFX_TRUE;
}

VappBrowserEditShortcut::VappBrowserEditShortcut(const VfxWChar * url):
    m_shortcutID(-1),
    m_inputEditor(NULL),
    m_searchItemList(NULL),
    m_editItemListContentProvider(NULL),
    m_toolBar(NULL),
    m_frame(NULL),
    m_orignalBookmarks(0)
{
    MMI_ASSERT(url);
    m_urlBuffer = (VfxWChar*)VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
    memset(m_urlBuffer, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
    mmi_ucs2ncpy((CHAR*)m_urlBuffer, (CHAR*)url, SRV_BRW_MAX_URL_LENGTH);
}

void VappBrowserEditShortcut::onInit(void)
{
    VfxPage::onInit();
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(VFX_WSTR_RES(STR_GLOBAL_EDIT));
    setTopBar(m_titleBar); 
	m_orignalBookmarks = g_srv_brw_cntx.bookmark_count;
	
    //VFX_OBJ_CLOSE(m_titleBar);
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    if(m_shortcutID == -1)
    {
        m_toolBar->addItem(EDIT_SHORTCUT_SAVE, VFX_WSTR_RES(STR_ID_VAPP_BRW_GO), IMG_ID_VAPP_BRW_GO);
    }
    else
    {
        m_toolBar->addItem(EDIT_SHORTCUT_SAVE, VFX_WSTR_RES(STR_GLOBAL_SAVE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
    }
    m_toolBar->addItem(EDIT_SHORTCUT_CANCEL, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &VappBrowserEditShortcut::onTBClick);
    setBottomBar(m_toolBar);

    VfxRect page_rect2 = getRect();
    VFX_OBJ_CREATE(m_frame, VfxFrame , this);
    m_frame->setPos(VfxPoint(page_rect2.origin.x, page_rect2.origin.y));
    m_frame->setSize(page_rect2.size.width, TEXT_EDITOR_HEIGHT + (2 * TEXT_EDITOR_HEIGHT_MARGIN));
	m_frame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
     VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);


    VfxRect page_rect = m_frame->getRect();

    VFX_OBJ_CREATE(m_inputEditor, VcpTextEditor , m_frame);
    m_inputEditor->setPos(VfxPoint(page_rect.size.width/2, (TEXT_EDITOR_HEIGHT + 2 * TEXT_EDITOR_HEIGHT_MARGIN)/2));
    m_inputEditor->setSize(page_rect.size.width - 2 * TEXT_EDITOR_WIDTH_MARGIN, TEXT_EDITOR_HEIGHT);
	m_inputEditor->setAnchor(VfxFPoint(0.5F, 0.5F));

    if(m_shortcutID > -1)
    {
        m_urlBuffer = (VfxWChar*)VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
        memset(m_urlBuffer, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
        nvram_brw_global_shortcuts_item_struct* shortcutItem = srv_brw_get_global_shortcut(m_shortcutID);
        mmi_asc_to_ucs2((CHAR*) m_urlBuffer, (CHAR*) shortcutItem->url);
    }
    m_inputEditor->setText(m_urlBuffer, SRV_BRW_MAX_URL_LENGTH);               /* set text without any text format*/
    m_inputEditor->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_inputEditor->setIME(IMM_INPUT_TYPE_SENTENCE);
    m_inputEditor->setHint(VFX_WSTR_RES(STR_ID_VAPP_BRW_TAP_TO_INPUT));   /* Set hint text when editor content is empty */
    m_inputEditor->m_signalTextChanged.connect(this, &VappBrowserEditShortcut::onTextChanged);       /* connect the signal of any text changed */
    m_inputEditor->setHighlight(0, mmi_ucs2strlen((CHAR*)m_urlBuffer));
    m_inputEditor->setDeleteButton(VFX_TRUE);
    //m_inputEditor->activate(); move this part to onEntered()
	m_inputEditor->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
     VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    VappBrowserASMMemoryMgmt::freeMemory(m_urlBuffer);
    m_urlBuffer = NULL;

    VcpFunctionBar *funcBar;
    VFX_OBJ_CREATE(funcBar, VcpFunctionBar, m_inputEditor);
    if(m_shortcutID > -1)
    {
        funcBar->addItem(1, VFX_WSTR_RES(STR_GLOBAL_SAVE));
    }
    else
    {
        funcBar->addItem(1, VFX_WSTR_RES(STR_ID_VAPP_BRW_GO));
    }
    funcBar->setItemSpecial(1);
    m_inputEditor->setFunctionBar(funcBar);
    funcBar->m_signalButtonTap.connect(this,&VappBrowserEditShortcut::onFuncBarItemSelected);

    VFX_OBJ_CREATE(m_searchItemList, VcpListMenu, this);
    VFX_OBJ_CREATE(m_editItemListContentProvider, VappBrowserSearchListDataProvider, this);
	m_searchItemList->setCacheLen(getSize().height/2);
    if(m_shortcutID == -1)
    {
        m_editItemListContentProvider->m_searchItemsEnabled = VFX_TRUE;
    }
    else
    {
        m_editItemListContentProvider->m_searchItemsEnabled = VFX_FALSE;
    }
    m_searchItemList->setContentProvider(m_editItemListContentProvider);
    m_searchItemList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT);
    m_searchItemList->m_signalItemTapped.connect(this, &VappBrowserEditShortcut::onItemTap);
    VfxRect page_rect1 = getRect();
    m_searchItemList->setPos(VfxPoint(0, page_rect.origin.y + page_rect.size.height/* + TEXT_EDITOR_HEIGHT + 5*/));
    m_searchItemList->setSize(page_rect1.size.width,page_rect1.size.height - TEXT_EDITOR_HEIGHT - 2 * TEXT_EDITOR_HEIGHT_MARGIN);
    m_searchItemList->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    registerKeyHandler(VFX_KEY_CODE_OK);
}

void VappBrowserEditShortcut::handleKeyInput(VfxKeyEvent &event)
{
    m_inputEditor->setAutoActivateByKey(VFX_TRUE);
    m_inputEditor-> processKeyInput(event);
}

VfxBool VappBrowserEditShortcut::onKeyInput(VfxKeyEvent &event)
{
    if(m_shortcutID == -1)
    {
        if(event.type == VFX_KEY_EVENT_TYPE_DOWN && (event.keyCode == VFX_KEY_CODE_OK || event.keyCode == VFX_KEY_CODE_CSK))
        {
            onTBClick((VfxObject*)m_toolBar, EDIT_SHORTCUT_SAVE);
            return VFX_TRUE;
        }
    }
    return VfxPage::onKeyInput(event);
}

void VappBrowserEditShortcut::onFuncBarItemSelected(VfxObject *sender, VfxId id)
{
    onTBClick((VfxObject*)m_toolBar, EDIT_SHORTCUT_SAVE);
}

void VappBrowserEditShortcut::onEnter(VfxBool isBackward)
{
	if(m_orignalBookmarks < g_srv_brw_cntx.bookmark_count)
    {
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_bookmark_items_list));
		g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_bookmark_items_list = (U8*) srv_brw_malloc(g_srv_brw_cntx.bookmark_count);
		m_orignalBookmarks = g_srv_brw_cntx.bookmark_count;
	}
}

void VappBrowserEditShortcut::onEntered()
{
	m_inputEditor->activate();
}


void VappBrowserEditShortcut::onTextChanged(VcpTextEditor *editor)
{
    m_editItemListContentProvider->m_inputText = VFX_WSTR_MEM(editor->getText());
	VfxU8 addressListItems = 0;
	#ifdef __MMI_BRW_URL_AUTO_COMPLETION__ 
	addressListItems = srv_brw_address_list_get_number_of_items();
	#endif
    VfxU8 bookmarkListItems = g_srv_brw_cntx.bookmark_count;
    VfxU8 searchListItems;
	#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    if(m_shortcutID == -1)
    {
        searchListItems = srv_brw_search_list_get_number_of_items();
    }
    else
	#endif
    {
        searchListItems = 0;
    }
    if((searchListItems + addressListItems + bookmarkListItems) >0)
    {
        VfxWChar *inputStr = editor->getText();
		#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
        if(addressListItems > 0)
        {
            if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list && addressListItems)
            {
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list = (U8*) srv_brw_malloc(addressListItems);
            }
            srv_brw_address_list_find_entry((U8*)inputStr);
        }
		#endif
        if(bookmarkListItems > 0)
        {
            if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_bookmark_items_list && bookmarkListItems)
            {
                g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_bookmark_items_list = (U8*) srv_brw_malloc(bookmarkListItems);
            }
            srv_brw_bookmark_list_find_entry((U8*)inputStr);
        }
		#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
        if(m_editItemListContentProvider->m_searchItemsEnabled)
        {
            if(searchListItems > 0)
            {
                if (!g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_search_items_list && searchListItems)
                {
                    g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_search_items_list = (U8*) srv_brw_malloc(searchListItems);
                }
                srv_brw_search_list_find_entry((U8*)inputStr);
            }
        }
		#endif
        m_searchItemList->resetAllItems(VFX_FALSE);
        m_searchItemList->updateAllItems();
    }
}

void VappBrowserEditShortcut::onItemTap(VcpListMenu *sender, VfxU32 index)
{
    VfxWChar *inputString = (VfxWChar*)VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
    memset(inputString, 0, (SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
	VfxU8 addressListCount = 0;
	#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    addressListCount = srv_brw_address_list_get_matched_item_count();
	#endif
    VfxU8 bookmarksListCount = srv_brw_bookmark_list_get_matched_item_count();
    VfxU8 searchListCount ;
	#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    if(m_editItemListContentProvider->m_searchItemsEnabled)
    {
        searchListCount = srv_brw_search_list_get_matched_item_count();
    }
    else
	#endif
    {
        searchListCount = 0;
    }
	if(index >= m_editItemListContentProvider->getCount())
	{
		//this if here  just avoids the macro error
	}
	#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    else if(index < addressListCount)
    {
        mmi_asc_to_ucs2((CHAR*)inputString ,(CHAR*)srv_brw_address_list_get_matched_item((S32)index));
    }
	#endif
	#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    else if(index >= addressListCount && index < (addressListCount + searchListCount))
    {
        mmi_chset_utf8_to_ucs2_string((U8*)inputString, (SRV_BRW_SEARCH_ITEM_LENGTH + 1) * ENCODING_LENGTH, 
                (U8*)srv_brw_search_list_get_matched_item((S32)index - addressListCount));
    }
	#endif
    else if(index >= (addressListCount + searchListCount))
    {
        mmi_asc_to_ucs2((CHAR*)inputString ,(CHAR*)srv_brw_bookmark_list_get_matched_item((S32)index - (addressListCount + searchListCount)));
    }
    m_inputEditor->setText(inputString, SRV_BRW_MAX_URL_LENGTH);
    m_inputEditor->setCursorIndex(mmi_ucs2strlen((CHAR*)inputString));
    VappBrowserASMMemoryMgmt::freeMemory(inputString);
}

void VappBrowserEditShortcut::onRotate(const VfxScreenRotateParam & param)
{
		
	if(param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90)
	{
		if(m_titleBar)
		{				
			VFX_OBJ_CLOSE(m_titleBar);
			toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_FALSE);
			onUpdate();
		}
	}
	else if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0)
	{
		if(!m_titleBar)
		{
			VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
			m_titleBar->setTitle(VFX_WSTR_RES(STR_GLOBAL_EDIT));
			setTopBar(m_titleBar); 
			toggleBar(VFX_PAGE_BAR_LOCATION_TOP, VFX_TRUE);
		}			
	}
}


void VappBrowserEditShortcut::onQueryRotateEx(VfxScreenRotateParam & param)
{
	if(param.rotateTo == VFX_SCR_ROTATE_TYPE_0 || param.rotateTo == VFX_SCR_ROTATE_TYPE_270 || param.rotateTo == VFX_SCR_ROTATE_TYPE_90)
	{
				
	}
	else
	{
		param.rotateTo = VFX_SCR_ROTATE_TYPE_NORMAL;
	}
}

void VappBrowserEditShortcut::onTBClick(VfxObject* sender, VfxId id)
{
    switch(id)
    {
        case EDIT_SHORTCUT_SAVE:
        {
            VfxWChar *inputString = m_inputEditor->getText();
            if(m_shortcutID > -1)
            {
                if (srv_brw_validate_url((U8*)inputString, SRV_BRW_ADDRESS_LIST_URL_LENGTH - 1) < 0)
                {
			        VappBrowserUtility::displayPopup(
				        STR_GLOBAL_INVALID_URL,
				        MMI_NMGR_BALLOON_TYPE_FAILURE,
					    MMI_EVENT_INFO_BALLOON);
                }
                else
                {
                    nvram_brw_global_shortcuts_item_struct *newItem;
                    nvram_brw_global_shortcuts_item_struct *oldItem;
                    newItem = (nvram_brw_global_shortcuts_item_struct*)  VappBrowserASMMemoryMgmt::allocMemory(sizeof(nvram_brw_global_shortcuts_item_struct));
                    memset(newItem, 0, sizeof(nvram_brw_global_shortcuts_item_struct));
                    mmi_chset_ucs2_to_utf8_string((U8*)newItem->url, (NVRAM_BRW_ADDRESS_HISTORY_MAX_URL_LENGTH + 1) * ENCODING_LENGTH, (U8*)inputString);
                    oldItem = srv_brw_get_global_shortcut(m_shortcutID);
                    if(strcmp((CHAR*)newItem->url,  (CHAR*)oldItem->url))
                    {
                        newItem->time = srv_brw_get_current_utc_time();
                        newItem->is_locked = MMI_TRUE;
                        srv_brw_global_shortcuts_list_add_item_at(newItem, m_shortcutID);
                    }
                    VappBrowserASMMemoryMgmt::freeMemory(newItem);
                    getMainScr()->popPage();
                    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
					#ifndef __MMI_BRW_SLIM__
					if(m_brwApp->scr->page->m_homePage != NULL)
					{
                        m_brwApp->scr->page->m_homePage->updateItems(m_shortcutID);
                }
					#endif
                        
                }
            }
            else
            {
                if(mmi_ucs2strlen((CHAR*)inputString) == 0)
                {
                    VappBrowserUtility::displayPopup(
				        STR_ID_VAPP_BRW_INVALID_INPUT,
				        MMI_NMGR_BALLOON_TYPE_FAILURE,
					    MMI_EVENT_INFO_BALLOON);
                    return;
                }
                if (srv_brw_validate_url_ex((U8*)inputString, (SRV_BRW_ADDRESS_LIST_URL_LENGTH - 1), MMI_FALSE) < 0)
                {
                    if(!g_srv_brw_cntx.private_mode_setting)
                    {
                        srv_brw_search_item_list_add_item((CHAR*)inputString, srv_brw_read_search_engine());
                    }
                }
                else
                {
                    if(!g_srv_brw_cntx.private_mode_setting)
                    {
                    	#ifdef __MMI_BRW_ADDRESS_URL_HISTORY_SUPPORT__
                        srv_brw_address_list_add_item((CHAR*)inputString);
                        srv_brw_set_address_list_entry_flag(MMI_TRUE);
						#endif
                    }
                }
                    if (srv_brw_validate_url_ex((U8*)inputString, (SRV_BRW_ADDRESS_LIST_URL_LENGTH - 1), MMI_FALSE) < 0)
                    {
                        VfxChar *searchItemString = (VfxChar*)VappBrowserASMMemoryMgmt::allocMemory(SRV_BRW_SEARCH_ITEM_LENGTH + 1);
                        memset(searchItemString, 0, SRV_BRW_SEARCH_ITEM_LENGTH + 1);
                        mmi_chset_ucs2_to_utf8_string((U8*)searchItemString, SRV_BRW_SEARCH_ITEM_LENGTH, (U8*)inputString);
                        srv_brw_launch_search_string((U8*)searchItemString, srv_brw_read_search_engine());
                        VappBrowserASMMemoryMgmt::freeMemory(searchItemString);
                    }
                    else
                    {
                        srv_brw_load_url_req((U8*)inputString, WAP_BAM_UNKNOWN_CHARSET);
                    }
                    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
                    VcpTextView* textViewer = m_brwApp->scr->page->m_titleBar->getTitleTextEditor();
                    if(!m_brwApp->scr->page->m_titleTextBuffer)
                    {
                        m_brwApp->scr->page->m_titleTextBuffer = (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
                    }
                    mmi_ucs2cpy((CHAR*) m_brwApp->scr->page->m_titleTextBuffer, (CHAR*) inputString);
                    textViewer->setText((VfxWChar*)m_brwApp->scr->page->m_titleTextBuffer, SRV_BRW_MAX_URL_LENGTH);
                    getMainScr()->popPage();
                }
            break;
        }

        case EDIT_SHORTCUT_CANCEL:
        {
            getMainScr()->popPage();
            break;
        }

        default:
        {
        }
    }
}

void VappBrowserEditShortcut::wifiBearerCallback(VfxU32 state, VfxU32 errorCause)
{
    if(state == SRV_CBM_ACTIVATED)
    {
        ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_setProfileCallback.connect(this , &VappBrowserEditShortcut::launchUrlCallback);
    }
    else
    {
        if(errorCause != ABM_E_REJECTED)
        {
            VappBrowserUtility::displayPopup(
                STR_ID_VAPP_BRW_CONNECTION_FAILED,
                MMI_NMGR_BALLOON_TYPE_FAILURE,
			    MMI_EVENT_INFO_BALLOON);
        }
        VFX_OBJ_CLOSE(m_popup);
    }
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_WifiBearerCallback.disconnect(this , &VappBrowserEditShortcut::wifiBearerCallback);
}

void VappBrowserEditShortcut::launchUrlCallback(void)
{
    ((VappBrwServiceInterface *)VFX_OBJ_GET_INSTANCE(VappBrwServiceInterface))->m_setProfileCallback.disconnect(this , &VappBrowserEditShortcut::launchUrlCallback);
    VfxWChar *inputString = m_inputEditor->getText();
    if (srv_brw_validate_url_ex((U8*)inputString, (SRV_BRW_ADDRESS_LIST_URL_LENGTH - 1), MMI_FALSE) < 0)
    {
        VfxChar *searchItemString = (VfxChar*)VappBrowserASMMemoryMgmt::allocMemory(SRV_BRW_SEARCH_ITEM_LENGTH + 1);
        memset(searchItemString, 0, SRV_BRW_SEARCH_ITEM_LENGTH + 1);
        mmi_chset_ucs2_to_utf8_string((U8*)searchItemString, SRV_BRW_SEARCH_ITEM_LENGTH, (U8*)inputString);
        srv_brw_launch_search_string((U8*)searchItemString, srv_brw_read_search_engine());
        VappBrowserASMMemoryMgmt::freeMemory(searchItemString);
    }
    else
    {
        srv_brw_load_url_req((U8*)inputString, WAP_BAM_UNKNOWN_CHARSET);
    }
    VFX_OBJ_CLOSE(m_popup);
    VappBrowserApp *m_brwApp = ((VappBrowserApp *)VfxAppLauncher::getObject(m_browserAppID));
    VcpTextView* textViewer = m_brwApp->scr->page->m_titleBar->getTitleTextEditor();
    if(!m_brwApp->scr->page->m_titleTextBuffer)
    {
        m_brwApp->scr->page->m_titleTextBuffer = (VfxWChar*) VappBrowserASMMemoryMgmt::allocMemory((SRV_BRW_MAX_URL_LENGTH + 1) * ENCODING_LENGTH);
    }
    mmi_ucs2cpy((CHAR*) m_brwApp->scr->page->m_titleTextBuffer, (CHAR*) inputString);
    textViewer->setText((VfxWChar*)m_brwApp->scr->page->m_titleTextBuffer, SRV_BRW_MAX_URL_LENGTH);
    getMainScr()->popPage();
}

void VappBrowserEditShortcut::onDeinit(void)
{
    unregisterKeyHandler(VFX_KEY_CODE_OK);
    VFX_OBJ_CLOSE(m_searchItemList);
    VFX_OBJ_CLOSE(m_editItemListContentProvider);
    VFX_OBJ_CLOSE(m_inputEditor);
    VFX_OBJ_CLOSE(m_toolBar);
	#ifdef __MMI_BRW_URL_AUTO_COMPLETION__
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p && g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list)
    {
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_items_list));
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_items = 0;
    }
	#endif
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p && g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_bookmark_items_list)
    {
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_bookmark_items_list));
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_bookmark_items = 0;
    }
	#ifdef __MMI_BRW_SEARCH_HISTORY_SUPPORT__
    if(g_srv_brw_cntx.srv_brw_dynamic_cntx_p && g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_search_items_list)
    {
        srv_brw_free_browser_memory((void**)&(g_srv_brw_cntx.srv_brw_dynamic_cntx_p->matched_search_items_list));
        g_srv_brw_cntx.srv_brw_dynamic_cntx_p->total_matched_search_items = 0;
    }
	#endif
    VFX_OBJ_CLOSE(m_frame);
    VfxPage::onDeinit(); 
}

#endif /* __MMI_BROWSER_2__ */

#endif /* _VAPP_BRW_URL_INPUT_CPP_ */
