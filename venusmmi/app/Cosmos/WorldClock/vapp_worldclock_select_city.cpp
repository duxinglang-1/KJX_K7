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
 * vapp_worldclock_select_city.cpp
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file implements world clock application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
/****************************************************************************
  *Include
  ***************************************************************************/

#include "MMI_features.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_worldclock_def.h"

#include "vdat_systime.h"

#include "vcp_navi_title_bar.h"

#include "vapp_worldclock_select_city.h"
#include "vapp_worldclock_gprot.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif
extern "C"
{
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif
}

/****************************************************************************
  *Class VappWCSelectCityPage
  ***************************************************************************/	 
VFX_IMPLEMENT_CLASS("VappWCSelectCityPage", VappWCSelectCityPage, VfxPage);
	  
VappWCSelectCityPage::VappWCSelectCityPage(VfxBool isHighlightDisable):
    m_cityLen(0),
    m_listLen(0),
    m_firstEnter(VFX_TRUE),
    m_isHighlightDisable(isHighlightDisable)
{
    VFX_ALLOC_MEM(m_listIndex, sizeof(VfxU16)*NUM_OF_CITY, this);
    memset(m_listIndex, 0x00, NUM_OF_CITY * sizeof(VfxU16)); 
	
    VFX_ALLOC_MEM(m_dateList, sizeof(VfxWChar*)*NUM_OF_CITY, this);
    VFX_ALLOC_MEM(m_timeList, sizeof(VfxWChar*)*NUM_OF_CITY, this);
	
    for (VfxU32 i = 0; i < NUM_OF_CITY; i++)
    {
        VFX_ALLOC_MEM(m_dateList[i], sizeof(VfxWChar)*20, this);
		memset(m_dateList[i], 0x00, sizeof(VfxWChar)*20);
		
		VFX_ALLOC_MEM(m_timeList[i], sizeof(VfxWChar)*20, this);
        memset(m_timeList[i], 0x00, sizeof(VfxWChar)*20); 
    }       
}

VappWCSelectCityPage::~VappWCSelectCityPage()
{
    for (VfxU32 i = 0; i < NUM_OF_CITY; i++)
    {
        VFX_FREE_MEM(m_dateList[i]);
        VFX_FREE_MEM(m_timeList[i]);
    } 
    VFX_FREE_MEM(m_listIndex);
    VFX_FREE_MEM(m_dateList);
    VFX_FREE_MEM(m_timeList);
}

void VappWCSelectCityPage::onInit ()
{
    VfxPage::onInit();

    VfxWString title;
    title.loadFromRes(STR_ID_VAPP_WC_REPLACE_CICY);
	
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(title);
    setTopBar(m_titleBar);
	
    VFX_OBJ_CREATE(m_citylist, VcpListMenu, this);
    m_citylist->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
    m_citylist->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
    m_citylist->setContentProvider(this);	 
    m_citylist->setRect(0, 0, LCD_WIDTH, getSize().height);
    m_citylist->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_citylist->setBounds(VfxRect(0, 0, LCD_WIDTH, getSize().height));
    m_citylist->m_signalItemTapped.connect(this, &VappWCSelectCityPage::onItemTapped);
    m_citylist->enableSearchBar(VFX_TRUE);
    m_citylist->setItemHighlightHidden(m_isHighlightDisable);

    VcpTextEditor *textInput;
    textInput = m_citylist->getSearchBar()->getSearchEditor();
    textInput->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    textInput->setIME(IMM_INPUT_TYPE_SENTENCE, IME_SETTING_FLAG_NONE);
    textInput->m_signalTextChanged.connect(this, &VappWCSelectCityPage::onTextChanged);
    m_listLen = m_dataControl.getCityListByName(NULL, m_listIndex);

#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("wup", SA_start);
#endif

    updateDateTimeList();
#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("wup", SA_stop);
#endif 
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappWCSelectCityPage::onTimeUpdate);
}

void VappWCSelectCityPage::onEntered()
{
	if (m_firstEnter)
	{
		m_firstEnter = VFX_FALSE;
		m_citylist->updateAllItems();
	}
}

VfxU32 VappWCSelectCityPage::getCount() const
{
	if (m_firstEnter)
	{
		return 0;
	}
	else
	{
		return m_listLen;
	}
}

void VappWCSelectCityPage::setTitleText(const VfxWString &titleString)
{
    m_titleBar->setTitle(titleString);
}

VfxBool VappWCSelectCityPage::getMenuEmptyText(VfxWString &text,VcpListMenuTextColorEnum &color)
{
	if (m_firstEnter)
	{
		text.loadFromRes(STR_GLOBAL_LOADING);
	}
	else
	{
		text.loadFromRes(STR_ID_VAPP_WC_NO_MATCHED_CITY);
	}
    
    return VFX_TRUE;
}

VfxBool VappWCSelectCityPage::getItemText(VfxU32 index,VcpListMenuFieldEnum fieldType, VfxWString& text,VcpListMenuTextColorEnum & color)
{
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_TEXT:
        {
            if(m_listIndex[index] != 0)
            {
                text = m_dataControl.getCityString(m_listIndex[index]);
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
            
        }
        case VCP_LIST_MENU_FIELD_SUB_TEXT1:
        {
            if(m_listIndex[index] != 0)
            {
                text = m_dataControl.getTimeZoneStr(m_dataControl.getTimeZone(m_listIndex[index]));
                color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
                return VFX_TRUE;
            }
        }
    }
    return VFX_FALSE;
}

VfxBool VappWCSelectCityPage::getItemTextFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VcpRichText & format)
{
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT && m_cityLen)
    {
        format.setRange(0, m_cityLen);
        format.setTextBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_SEARCH));
        format.setTextColor(VFX_COLOR_BLACK);
        format.setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VcpListMenuCellClientBaseFrame* VappWCSelectCityPage::getItemCustomContentFrame(VfxU32 index, VfxFrame * parentFrame)
{
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("wcu", SA_start);
#endif

    VappWCSelectCityCellItem * dateTime;
    VFX_OBJ_CREATE_EX(dateTime, VappWCSelectCityCellItem, parentFrame, (index, this));
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("wcu", SA_stop);
#endif

    return dateTime;
}

void VappWCSelectCityPage::closeItemCustomContentFrame(
                                VfxU32 index,
                                VcpListMenuCellClientBaseFrame *cell)
{
    VFX_OBJ_CLOSE(cell);
}

void VappWCSelectCityPage::onTextChanged(VcpTextEditor * sender)
{
    memset(m_listIndex, 0x00, NUM_OF_CITY);
    m_listLen = m_dataControl.getCityListByName(sender->getText(), m_listIndex);
	
    m_cityLen = mmi_wcslen(sender->getText());
	
    VfxWString temp;
    temp.loadFromMem(sender->getText());
	
    if (temp.getItem(0) == '\n')
    {
        m_cityLen -= 1;
    }
    m_citylist->updateAllItems();
}

void VappWCSelectCityPage::onItemTapped(VcpListMenu *, VfxU32 index)
{
    selectcityindex = m_listIndex[index];
    m_signalCitySelected.postEmit(this, selectcityindex);
}

void VappWCSelectCityPage::onTimeUpdate(VfxU32 flag)
{
    if (flag & VDAT_SYSTIME_CHANGED_MIN) 
    {
        updateDateTimeList();
        m_citylist->updateAllItems();
    }
}

void VappWCSelectCityPage::updateDateTimeList()
{
    VfxFloat hTimeZone = m_dataControl.getTimeZone(m_dataControl.getHomeCityIndex());
    VfxU8 homeDst = m_dataControl.getHomeCityDst();
    VfxDateTime dt;
    VfxDateTime timeDiff;
    timeDiff.setTime(1, 0, 0);
    VfxFloat currTimeZone = 0;
	
    for(VfxU32 i = 1; i < NUM_OF_CITY; i++)
    {
        VfxU8 destDst = 0;
        currTimeZone = m_dataControl.getTimeZone(i);
        m_dataControl.getTime(hTimeZone, currTimeZone, dt);
		
        if (m_dataControl.getHomeCityIndex() == i)
        {
            destDst = m_dataControl.getHomeCityDst();
        }
        if (m_dataControl.getFrnCityIndex(0) == i)
        {
            destDst = m_dataControl.getFrnCityDst(0);
        }
        else if (m_dataControl.getFrnCityIndex(1) == i)
        {
            destDst = m_dataControl.getFrnCityDst(1);
        }
        if (destDst - homeDst > 0)
        {
            dt.increase(timeDiff);
        }
        else if (destDst - homeDst < 0)
        {
            dt.decrease(timeDiff);
        }
        vfx_sys_wcscpy(m_dateList[i], dt.getDateTimeString(VFX_DATE_TIME_DATE_DAY|VFX_DATE_TIME_DATE_MONTH|VFX_DATE_TIME_DATE_YEAR));
        vfx_sys_wcscpy(m_timeList[i], dt.getDateTimeString(VFX_DATE_TIME_TIME_MINUTE|VFX_DATE_TIME_TIME_HOUR));
    }
}

VfxWString VappWCSelectCityPage::getDateString(VfxU32 index)
{
    VfxWString temp;
    temp.loadFromMem(m_dateList[m_listIndex[index]]);
    return temp;
}

VfxWString VappWCSelectCityPage::getTimeString(VfxU32 index)
{
    VfxWString temp;
    temp.loadFromMem(m_timeList[m_listIndex[index]]);
    return temp;
}

VappWCSelectCityCellItem::VappWCSelectCityCellItem(VfxU32 index, VappWCSelectCityPage *page):
    m_index(index)
{
    m_parent = page;
}

void VappWCSelectCityCellItem::onCreateElements(void)
{
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("woc", SA_start);
#endif

	VcpListMenuCellMultiTextFrame::onCreateElements();

	VFX_OBJ_CREATE(m_time, VfxTextFrame, this);
	
	m_time->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_MEDIUM));	

	VFX_OBJ_CREATE(m_date, VfxTextFrame, this);
	
	m_date->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_SMALL));
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("woc", SA_stop);
#endif

}

void VappWCSelectCityCellItem::onUpdateElements(void)
{
#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("wou", SA_start);
#endif

    VcpListMenuCellMultiTextFrame::onUpdateElements();

	m_time->setString(m_parent->getTimeString(m_index));
	m_date->setString(m_parent->getDateString(m_index));
	if (getCell()->m_isHighlight)
	{
		m_time->setColor(getCell()->getTextColor(VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT));
		m_date->setColor(getCell()->getTextColor(VCP_LIST_MENU_TEXT_COLOR_HIGHLIGHT)); 
	}
	else
	{
		m_time->setColor(getCell()->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL));
		m_date->setColor(getCell()->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL)); 
	}
#ifdef __MAUI_SOFTWARE_LA__
		SLA_CustomLogging("wou", SA_stop);
#endif

}


void VappWCSelectCityCellItem::onLayoutElements(void)
{
#ifdef __MAUI_SOFTWARE_LA__
			SLA_CustomLogging("wol", SA_start);
#endif

    VcpListMenuCellMultiTextFrame::onLayoutElements();
	
    m_time->setAnchor(1.0F, 0.0F);
    m_time->setPos(getSize().width - TEXT1_LEFT_GAPS, TEXT1_TOP_GAPS);

	m_date->setAnchor(1.0F, 1.0F);
    m_date->setPos(getSize().width - TEXT2_RIGHT_GAPS, getSize().height - TEXT2_BOTTOM_GAPS);
	
#ifdef __MAUI_SOFTWARE_LA__
			SLA_CustomLogging("wol", SA_stop);
#endif

}

void VappWCSelectCityCellItem:: onCloseElements(void)
{
    VcpListMenuCellMultiTextFrame::onCloseElements();
	
    VFX_OBJ_CLOSE(m_time);
    VFX_OBJ_CLOSE(m_date);
}

