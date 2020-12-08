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
 * VappWorldclockMapView.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
 /***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_worldclock_list_view.h"
//#include "mmi_rp_vapp_worldclock_def.h"
#include "mmi_rp_vapp_clock_def.h"
#include "vapp_worldclock_select_city.h"
#include "trc\vadp_app_trc.h"
#include "GlobalResDef.h"
//#define __LOW_COST_SUPPORT__

/****************************************************************************
 *class
 ***************************************************************************/

 
#ifdef __LOW_COST_SUPPORT_COMMON__
#pragma arm section code = "DYNAMIC_CODE_CLOCK_ROCODE", rodata = "DYNAMIC_CODE_CLOCK_RODATA"
class VappWCViewCityCellItem:public VcpListMenuCellClientBaseFrame
{
public:
	//constrcut
	VappWCViewCityCellItem();
	VappWCViewCityCellItem(VfxU8 Index, const VfxWString &text);
	//VappWCViewCityCellItem(VfxU8 Index, const VfxWString &text);
	//~VappWCViewCityCellItem();
protected:
	virtual void onCreateElements(void);
	virtual void onCloseElements(void);
	virtual void onLayoutElements(void);
	virtual void onUpdateElements(void);

//public:
	//void setContent(const VfxWString &text, const VfxWString &text1);
private:
	VfxS8 compareData(VfxDateTime DT, VfxDateTime dt);
	
	
public:
#ifndef __MMI_WORLDCLOCK_SLIM__	
	VcpAnalogClock *m_analogClock;
#endif
private:
	VfxWString m_text;
	//VfxWString m_text1;
	VfxTextFrame *m_city;
	//VfxTextFrame *m_timezone;
	VfxTextFrame *m_amPm;
	//VfxId m_imgScr;
	VfxImageFrame *m_homeIcon;	
	//VcpDigitalTextClock *m_date;
	VfxTextFrame *m_date;
	VcpDigitalTextClock *m_digitalClock;
	//VcpAnalogClock *m_analogClock;		
	VappWCDataControl m_dataControl;
	VfxU8 m_cityIndex;
	VfxU8 m_flag;
	VfxImageFrame  *m_itemBg;
	
};

VappWCViewCityCellItem::VappWCViewCityCellItem(VfxU8 Index, const VfxWString &text):
		m_text(text),
		m_cityIndex(Index)
{
}

		
void VappWCViewCityCellItem::onCreateElements()
{

	VcpListMenuCell *cell = getCell();
	if(!cell)
	{
		return;
	}
		
	VFX_OBJ_CREATE(m_itemBg, VfxImageFrame, this);
	VFX_OBJ_CREATE(m_city, VfxTextFrame, this);
	VFX_OBJ_CREATE(m_date, VfxTextFrame, this);
	VFX_OBJ_CREATE(m_digitalClock, VcpDigitalTextClock, this);
#ifndef __MMI_WORLDCLOCK_SLIM__	
	VFX_OBJ_CREATE(m_analogClock, VcpAnalogClock, this);
#endif
#ifndef __MMI_WORLDCLOCK_SLIM__
	if(m_cityIndex == 0)
	{
		m_itemBg->setResId(IMG_ID_VAPP_WC_LIST_HOME_BG);
		m_city->setColor(WC_HOME_NORMAL_COLOR);
		m_date->setColor(WC_HOME_LOWLIGHT_COLOR);
		m_digitalClock->setTextColor(WC_HOME_NORMAL_COLOR);
		VFX_OBJ_CREATE(m_homeIcon, VfxImageFrame, this);
	}
	else
#endif		
	{
		m_itemBg->setResId(IMG_ID_VAPP_WC_LIST_FRN_BG);
#ifndef __MMI_WORLDCLOCK_SLIM__
		m_city->setColor(WC_FRN_NORMAL_COLOR);
#else
		m_city->setColor(WC_FRN_LOWLIGHT_COLOR);
#endif
		m_date->setColor(WC_FRN_LOWLIGHT_COLOR);
		m_digitalClock->setTextColor(WC_FRN_NORMAL_COLOR);
	}

	m_city->setFont(VfxFontDesc(WC_CITYNAME_FONT));
	m_city->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);		
	m_date->setFont(VfxFontDesc(WC_DATE_FONT));
    //m_date->setFormatFlags(VFX_DATE_TIME_DATE_YEAR|
						   //VFX_DATE_TIME_DATE_MONTH|
	                       //VFX_DATE_TIME_DATE_DAY); 
	m_digitalClock->setFont(VfxFontDesc(WC_DCLOCK_FONT));
	m_digitalClock->setFormatFlags(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE);
	m_itemBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);	

}


void VappWCViewCityCellItem::onLayoutElements()
{
	m_city->setPos(WC_CITYNAME_POS_X, WC_CITYNAME_POS_Y);
	m_city->setBounds(0, 0, WC_CITYNAME_WIDTH, WC_CITYNAME_HEIGHT);

	m_date->setBounds(0, 0, WC_DATE_WIDTH, WC_DATE_HEIGHT);	
#ifndef __MMI_WORLDCLOCK_SLIM__
	m_date->setAnchor(0.5, 0);
#else
	m_date->setAnchor(0.0, 0);
#endif
	m_date->setPos(WC_DATE_POS_X, WC_DATE_POS_Y);
	//m_date->setAlignMode(VcpDigitalTextClock::ALIGN_MODE_LEFT);

	m_digitalClock->setBounds(0, 0, WC_DCLOCK_WIDTH, WC_DCLOCK_HEIGHT);
	m_digitalClock->setPos(WC_DCLOCK_POS_X, WC_DCLOCK_POS_Y);
	m_digitalClock->setAlignMode(VcpDigitalTextClock::ALIGN_MODE_LEFT);	
#ifndef __MMI_WORLDCLOCK_SLIM__
	m_analogClock->setPos(WC_ACLOCK_POS_X, WC_ACLOCK_POS_Y);
	m_analogClock->setCenter(VfxPoint(WC_ACLOCK_CENTER, WC_ACLOCK_CENTER));
	m_analogClock->setAnchor(1, 0);
#endif	
#ifndef __MMI_WORLDCLOCK_SLIM__
	if(m_cityIndex == 0)
	{
		m_homeIcon->setPos(WC_HOME_ICON_POS_X, WC_HOME_ICON_POS_Y);		
	}
#endif	
	
}


void VappWCViewCityCellItem::onUpdateElements()
{

	VfxU16 cityindex;
	VfxFloat hometz, tz;
	m_itemBg->setSize(LCD_WIDTH, WC_ITEM_HEIGHT);
	m_city->setString(m_text);
#ifndef __MMI_WORLDCLOCK_SLIM__
	if(m_cityIndex == 0)
	{
		cityindex = m_dataControl.getHomeCityIndex();
		m_homeIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_WC_HOME_ICON));
	}
	else
	
	{
		cityindex = m_dataControl.getFrnCityIndex(m_cityIndex - 1);
	}
#else
		cityindex = m_dataControl.getFrnCityIndex(m_cityIndex );
#endif

    tz = m_dataControl.getTimeZone(cityindex);
    VfxDateTime dt;
	VfxDateTime DT;
    hometz = m_dataControl.getTimeZone(m_dataControl.getHomeCityIndex ());
    m_dataControl.getTime(hometz, tz, dt);
	m_dataControl.getTime(hometz, hometz, DT);
    VfxDateTime timeDiff;
    timeDiff.setTime(1, 0, 0);
#ifndef __MMI_WORLDCLOCK_SLIM__	
	m_analogClock->setClockBackground(vrt_sys_res_image_lock(IMG_ID_VAPP_WC_ACLOCK_BG));
	m_analogClock->setClockAxis(IMG_ID_VAPP_WC_ACLOCK_C);
	m_analogClock->setClockHourHand(IMG_ID_VAPP_WC_ACLOCK_H);
	m_analogClock->setClockMinuteHand(IMG_ID_VAPP_WC_ACLOCK_M);
	m_analogClock->setClockSecondHand(IMG_ID_VAPP_WC_ACLOCK_S); 
#endif

		if (m_dataControl.getTimeFormat() == 0)
		{
			VFX_OBJ_CREATE(m_amPm, VfxTextFrame, this);//edit
			m_amPm->setString(m_dataControl.getAmPmString(dt));
			m_amPm->setFont(VfxFontDesc(WC_AMPM_FONT));
			m_amPm->setAnchor(0, 1);		
			m_amPm->setPos(WC_AMPM_POS_X, WC_AMPM_POS_Y);
#ifndef __MMI_WORLDCLOCK_SLIM__
			if(m_cityIndex == 0)
			{
				m_amPm->setColor(WC_HOME_LOWLIGHT_COLOR);
			}
			else
#endif			
			{
				m_amPm->setColor(WC_FRN_LOWLIGHT_COLOR);
			}
		}

    if (cityindex != m_dataControl.getHomeCityIndex())
    {
        VfxU8 homeDst = m_dataControl.getHomeCityDst();
	#ifndef __MMI_WORLDCLOCK_SLIM__
        VfxU8 frnDst = m_dataControl.getFrnCityDst(m_cityIndex - 1);
	#else
		VfxU8 frnDst = m_dataControl.getFrnCityDst(m_cityIndex);
	#endif
        if (frnDst - homeDst > 0)
        {
            dt.increase(timeDiff);
        }
        else if (frnDst - homeDst < 0)
        {
            dt.decrease(timeDiff);
        }
    }
#ifdef __MMI_WORLDCLOCK_SLIM__
	else
	{
		VFX_OBJ_CREATE(m_homeIcon, VfxImageFrame, this);
		m_homeIcon->setImgContent(VfxImageSrc(IMG_ID_VAPP_WC_HOME_ICON));
		m_homeIcon->setPos(WC_HOME_ICON_POS_X, WC_HOME_ICON_POS_Y);
		m_city->setColor(WC_HOME_LOWLIGHT_COLOR);
		m_date->setColor(WC_HOME_LOWLIGHT_COLOR);
		m_digitalClock->setTextColor(WC_HOME_NORMAL_COLOR);
		m_amPm->setColor(WC_HOME_NORMAL_COLOR);
		VfxU8 homeDst = m_dataControl.getHomeCityDst();
		VfxU8 frnDst = m_dataControl.getFrnCityDst(m_cityIndex);
		if(frnDst != homeDst)
		{
			m_dataControl.saveHomeCityDst(frnDst);
			m_dataControl.updateSysTime(m_dataControl.getHomeCityIndex(), (m_dataControl.getHomeCityDst() == 1 ? 1 : -1));
		}

    }
#endif	

	VfxS8 cp = compareData(DT, dt);
	if(cp == 0)
	{
		m_date->setString(STR_ID_VAPP_WC_DATE_TODAY);
	}
	else if(cp == 1)
	{
		m_date->setString(STR_ID_VAPP_WC_DATE_YESTERDAY);
	}
	else
	{
		m_date->setString(STR_ID_VAPP_WC_DATE_TOMORROW);
	}
#ifndef __MMI_WORLDCLOCK_SLIM__
    m_analogClock->setTime(dt);
	m_analogClock->startClock();
#endif
    m_digitalClock->setTime(dt);
    //m_date->setTime(dt);
	
	m_digitalClock->startClock();
	//m_date->startClock(); 	
}


VfxS8 VappWCViewCityCellItem::compareData(VfxDateTime DT, VfxDateTime dt)
{
	if(DT.getYear() == dt.getYear())
	{
		if(DT.getMonth() == dt.getMonth())
		{
			if(DT.getDay() == dt.getDay())
			{
				return 0;
			}
			else if(DT.getDay() > dt.getDay())
			{
				return 1;				
			}
			else
			{
				return -1;
			}
		}
		else if(DT.getMonth() > dt.getMonth())
		{
			return 1;
		}
		else
		{
			return -1;
		}		
	}
	else if(DT.getYear() > dt.getYear())
	{
		return 1;
	}
	else
	{
		return -1;
	}

}
void VappWCViewCityCellItem::onCloseElements()
{
	VFX_OBJ_CLOSE(m_city);
	VFX_OBJ_CLOSE(m_date);
	VFX_OBJ_CLOSE(m_digitalClock);
#ifndef __MMI_WORLDCLOCK_SLIM__	
	VFX_OBJ_CLOSE(m_analogClock);
#endif
#ifndef __MMI_WORLDCLOCK_SLIM__
	if(m_cityIndex == 0)
	{
		VFX_OBJ_CLOSE(m_homeIcon);

	}
#endif	
}


VappWCListViewPage::VappWCListViewPage()
{
}


VappWCListViewPage::~VappWCListViewPage()
{
}


void VappWCListViewPage::onInit()
{
	VfxPage::onInit();	
	//VFX_OBJ_CREATE(m_titlebar, VcpTitleBar, this);
	//m_titlebar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_WORLDCLOCK));
	//setTopBar(m_titlebar);
	
	VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
	m_toolbar->addItem(ID_VAPP_WC_ADD, STR_GLOBAL_ADD, VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD);
#ifndef __MMI_WORLDCLOCK_SLIM__
	m_toolbar->addItem(ID_VAPP_WC_LIST, STR_GLOBAL_LIST, VCP_IMG_TOOL_BAR_COMMON_ITEM_LIST);
#endif
	m_toolbar->m_signalButtonTap.connect(this, &VappWCListViewPage::onToolBarClick);
	setBottomBar(m_toolbar);
    setItemData();
	VFX_OBJ_CREATE(m_listmenu, VcpListMenu, this);
	m_listmenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
	m_listmenu->setContentProvider(this);
	m_listmenu->m_signalItemTapped.connect(this, &VappWCListViewPage::onTapButton);
    m_listmenu->setRect(0, 0, LCD_WIDTH, getSize().height);
    m_listmenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listmenu->setBounds(VfxRect(0, 0, LCD_WIDTH, getSize().height));	
	m_listmenu->setItemHeight(WC_ITEM_HEIGHT);
#if defined(__MMI_MAINLCD_320X480__)
	m_listmenu->setViewRect(VfxRect(0, 0, LCD_WIDTH, getSize().height + 2));
#endif
#if defined(__MMI_WORLDCLOCK_SLIM__)
	m_listmenu->setViewRect(VfxRect(0, 0, LCD_WIDTH, getSize().height + 2));
	m_listmenu->setItemSeparatorHidden(VFX_TRUE);

#endif
	m_citySelect = 0;
//#ifndef __MMI_WORLDCLOCK_SLIM__
	m_frnflag = 0;
//#endif
}


VfxU32 VappWCListViewPage::getCount() const
{
	VfxU32 temp;
	VfxU32 i;
#ifndef __MMI_WORLDCLOCK_SLIM__
	for( i = 1; i < cityMaxNumber; i++)
	{	
		if(m_cityIndex[i] == 0)
		{
			break;
		}
			
	}
	temp = i;
	return temp;
#else
	for( i = 0; i < cityMaxNumber; i++)
	{	
		if(m_cityIndex[i] == 0)
		{
			break;
		}
			
	}
	temp = i;
	return temp;
#endif
}


VfxBool VappWCListViewPage::getItemText(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxWString & text, VcpListMenuTextColorEnum & color)
{
	if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
	{
		text = m_dataControl.getCityString(m_cityIndex[index]);
		return VFX_TRUE;
	}
	return VFX_FALSE;
}


VfxBool VappWCListViewPage::getItemTextFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VcpRichText & format)
{
	return VFX_FALSE;
}


VcpListMenuCellClientBaseFrame *VappWCListViewPage::getItemCustomContentFrame(VfxU32 index, VfxFrame * parentFrame)
{
	setItemData();
	VfxWString text;
	VfxWString text1;
	VfxU8 cIndex;
	VcpListMenuTextColorEnum textColor;
	VcpListMenuCellClientBaseFrame *obj;
	getItemText(index, VCP_LIST_MENU_FIELD_TEXT, text, textColor);
	cIndex = (VfxU8) index;	
	VFX_OBJ_CREATE_EX(obj, VappWCViewCityCellItem, parentFrame, (cIndex,  text));	
	
	VFX_ASSERT(obj != NULL);
	return obj;	
}


void VappWCListViewPage::closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame * cell)
{
	VFX_OBJ_CLOSE(cell);
}

VfxBool VappWCListViewPage::getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color)
{
    text.loadFromRes(STR_ID_VAPP_WC_NOCITY);

    return VFX_TRUE;
}


void VappWCListViewPage::setItemData()
{
#ifndef __MMI_WORLDCLOCK_SLIM__
	m_cityIndex[0] = m_dataControl.getHomeCityIndex();
	m_cityZone[0] = m_dataControl.getTimeZone(m_cityIndex[0]);
	for(VfxU8 i = 1; i < cityMaxNumber; i++)
	{
		m_cityIndex[i] = m_dataControl.getFrnCityIndex(i-1);
		m_cityZone[i] = m_dataControl.getTimeZone(m_cityIndex[i]);
	}
#else
	for(VfxU8 i = 0; i < cityMaxNumber; i++)
	{
		m_cityIndex[i] = m_dataControl.getFrnCityIndex(i);
		m_cityZone[i] = m_dataControl.getTimeZone(m_cityIndex[i]);
	}
#endif
}


void VappWCListViewPage::showSelectCityPage(VfxBool HighLight, VfxBool HFlag)
{
    VFX_LOG(VFX_FUNC, VAPP_WORLDCLOCK_MAPPAGE_SHOW_SELECTPAGE);
    VappWCSelectCityPage *Page;
    VFX_OBJ_CREATE_EX(Page, VappWCSelectCityPage, getMainScr(), (HighLight));
    Page->setTitleText(VFX_WSTR_RES(STR_ID_VAPP_WC_CITY_VIEW));
#ifndef __MMI_WORLDCLOCK_SLIM__
	if(!HighLight)
	{
		if(HFlag)
		{
			Page->m_signalCitySelected.connect(this, &VappWCListViewPage::onHomeCityChange);

		}
		else
		{
			Page->m_signalCitySelected.connect(this, &VappWCListViewPage::onFrnSelectCity);
		}
	}
#else
	Page->m_signalCitySelected.connect(this, &VappWCListViewPage::onFrnSelectCity);
#endif
    getMainScr()->pushPage(0, Page);
}

#ifndef __MMI_WORLDCLOCK_SLIM__
void VappWCListViewPage::onHomeCityChange(VfxObject *sender, VfxU16 cityIndex)
{
    VappWCSelectCityPage *page = (VappWCSelectCityPage *)sender;
	m_citySelect = cityIndex;
	for (VfxU32 i = 0; i < cityMaxNumber; i++)
    {
        if (m_cityIndex[i] == cityIndex)
        {
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, VFX_WSTR_RES(STR_ID_VAPP_WC_CITY_EXIST));
			return;
        }
    }
    if (page != NULL)
    {
        VcpConfirmPopup *cfPopup;
        VFX_OBJ_CREATE(cfPopup, VcpConfirmPopup, sender);
        cfPopup->setText(STR_ID_VAPP_WC_HOMECICY_CHANGE_POP);
        cfPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        cfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        cfPopup->setCustomButton(
                        STR_GLOBAL_CONTINUE,
                        STR_GLOBAL_CANCEL,
                        VCP_POPUP_BUTTON_TYPE_WARNING,
                        VCP_POPUP_BUTTON_TYPE_CANCEL
                        );
        cfPopup->m_signalButtonClicked.connect(this, &VappWCListViewPage::onHomeCmdPopCallback);
        cfPopup->show(VFX_TRUE);
    }

}
#endif

void VappWCListViewPage::onFrnSelectCity(VfxObject *sender, VfxU16 cityIndex)
{
	VappWCSelectCityPage *page = (VappWCSelectCityPage *)sender;
	m_citySelect = cityIndex;
	VfxU32 i;

	if(page != NULL)
	{
		for (i = 0; i < cityMaxNumber; i++)
	    {
	        if (m_cityIndex[i] == cityIndex)
	        {
	            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, VFX_WSTR_RES(STR_ID_VAPP_WC_CITY_EXIST));
				return;
	        }
	    }
		getMainScr()->popPage();
	}

	if(!m_frnflag)
	{
	#ifndef __MMI_WORLDCLOCK_SLIM__
		for(i = 1; i < cityMaxNumber; i++)
	#else
		for(i = 0; i < cityMaxNumber; i++)
	#endif	
		{
			if(m_cityIndex[i] == 0)
			break;
		}

	}
	else
	{

		i = m_selectID;
		m_frnflag = 0;
	}



#ifndef __MMI_WORLDCLOCK_SLIM__
	m_dataControl.saveFrnCityIdx(cityIndex, i - 1);
#else
	m_dataControl.saveFrnCityIdx(cityIndex, i);
#endif
    setItemData();
	m_listmenu->resetAllItems();

}


void VappWCListViewPage::onToolBarClick(VfxObject * sender, VfxId id)
{
	VfxU32 i;
	switch(id)
	{
	case ID_VAPP_WC_ADD:
	
		for(i = 1; i < cityMaxNumber; i++)
		{
			if(m_cityIndex[i] == 0)
			break;
		}
		if(i == cityMaxNumber)
		{
			mmi_frm_nmgr_balloon(
						MMI_SCENARIO_ID_DEFAULT,
						MMI_EVENT_INFO_BALLOON,
						MMI_NMGR_BALLOON_TYPE_FAILURE,
						VFX_WSTR_RES(STR_ID_VAPP_WC_CITY_FULL));   //STR_ID_VAPP_WC_CITY_FULL
			return;					
		}
		showSelectCityPage(VFX_FALSE, VFX_FALSE);
		break;
				
#ifndef __MMI_WORLDCLOCK_SLIM__
	case ID_VAPP_WC_LIST:
	
		showSelectCityPage(VFX_TRUE, VFX_FALSE);
		break;

#endif
	}

}


void VappWCListViewPage::onTapButton(VcpListMenu *, VfxId id)
{
	m_selectID = id;	
	m_signalCityChanged.connect(this, &VappWCListViewPage::updateTime);
#ifndef __MMI_WORLDCLOCK_SLIM__
	switch(id)
	{
	case 0:
		showHomeEditMenu();
		break;
	case 1:
	case 2:
	case 3:
		showFrnEditMenu();
		break;
	}
#else
	showFrnEditMenu();
#endif
}



#ifndef __MMI_WORLDCLOCK_SLIM__
void VappWCListViewPage::showHomeEditMenu()
{
    VcpCommandPopup *cmdPopup;
    VFX_OBJ_CREATE(cmdPopup, VcpCommandPopup, this);
    cmdPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WC_HOME_OPTION));
    cmdPopup->addItem(REPLACE_CITY, VFX_WSTR_RES(STR_ID_VAPP_WC_REPLACE_CICY), VCP_POPUP_BUTTON_TYPE_NORMAL);
    if (m_dataControl.getHomeCityDst())
    {
        cmdPopup->addItem(ACTIVE_DAY_LIGHT, VFX_WSTR_RES(STR_ID_VAPP_WC_DST_DISABLE), VCP_POPUP_BUTTON_TYPE_NORMAL);
    }    
    else
    {
        cmdPopup->addItem(ACTIVE_DAY_LIGHT, VFX_WSTR_RES(STR_ID_VAPP_WC_DST_ACT), VCP_POPUP_BUTTON_TYPE_NORMAL);
    }
    cmdPopup->addItem(CLOSE, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    cmdPopup->m_signalButtonClicked.connect(this, &VappWCListViewPage::onHomeCmdPopCallback);
    cmdPopup->setAutoDestory(VFX_TRUE);
    cmdPopup->show(VFX_TRUE);

}


void VappWCListViewPage::onHomeCmdPopCallback(VfxObject *obj, VfxId id)
{
	switch (id)
    {
        case REPLACE_CITY:
        {
			//m_frnflag = 1;
            showSelectCityPage(VFX_FALSE, VFX_TRUE);			
            break;
        }
        case ACTIVE_DAY_LIGHT:
        {
            VfxU8 dst = m_dataControl.getHomeCityDst() == 1 ? 0 : 1;
            HomeDLSHandler(1);
			//onDayLightSavingChange();
            //m_signalDstChanged.postEmit(this, m_dataControl.getHomeCityIndex(), dst);
            break;
        }
        case CLOSE:
            break;
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {          
			m_dataControl.updateSysTime(m_citySelect, 0);
			m_dataControl.saveHomeCityIdx(m_citySelect);
			VappWCSelectCityPage *page = (VappWCSelectCityPage *)obj;
            if (page != NULL)
            {
              getMainScr()->popPage();
            } 
			m_signalCityChanged.postEmit(this, m_citySelect);
            break;
        }
    }

}
#endif

void VappWCListViewPage::updateTime(VfxObject *sender, VfxU16 cityIndex)
{
	m_listmenu->resetAllItems();
}

#ifndef __MMI_WORLDCLOCK_SLIM__
void VappWCListViewPage::HomeDLSHandler(VfxBool flag)
{
    VfxWString infoStr;
    VfxU8 dst = m_dataControl.getHomeCityDst(); 
    if (dst != 0)
    {
        m_dataControl.saveHomeCityDst(0);
        m_dataControl.updateSysTime(m_dataControl.getHomeCityIndex(), -1);
        infoStr.loadFromRes(STR_ID_VAPP_WC_DST_POP_INACT);
    }
    else
    {
        m_dataControl.saveHomeCityDst(1);
        m_dataControl.updateSysTime(m_dataControl.getHomeCityIndex(), 1);
        infoStr.loadFromRes(STR_ID_VAPP_WC_DST_POP_ACT);
    }
    if (flag == 1)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)infoStr.getBuf());
    }

	m_listmenu->updateItem(m_selectID);		

}

#endif
void VappWCListViewPage::showFrnEditMenu()
{
    VcpCommandPopup *cmdPopup;
    VFX_OBJ_CREATE(cmdPopup, VcpCommandPopup, this);
    cmdPopup->setText(STR_ID_VAPP_WC_FOREIGN_OPTION);
    cmdPopup->addItem(F_REPLACE_CITY, STR_ID_VAPP_WC_REPLACE_CICY, VCP_POPUP_BUTTON_TYPE_NORMAL);
#ifndef __MMI_WORLDCLOCK_SLIM__
    if (m_dataControl.getFrnCityDst((VfxU8)(m_selectID-1)))
#else
	if (m_dataControl.getFrnCityDst((VfxU8)m_selectID))
#endif		
    {
        cmdPopup->addItem(F_ACTIVE_DAY_LIGHT, STR_ID_VAPP_WC_DST_DISABLE, VCP_POPUP_BUTTON_TYPE_NORMAL);
    }
    else
    {
        cmdPopup->addItem(F_ACTIVE_DAY_LIGHT, STR_ID_VAPP_WC_DST_ACT, VCP_POPUP_BUTTON_TYPE_NORMAL);
    }
#ifndef __MMI_WORLDCLOCK_SLIM__
	cmdPopup->addItem(F_SET_AS_HOMECITY, STR_ID_VAPP_WC_HOMECICY_MENU, VCP_POPUP_BUTTON_TYPE_NORMAL);
#else
	if(m_dataControl.getFrnCityIndex((VfxU8)m_selectID) !=  m_dataControl.getHomeCityIndex())
	{
		cmdPopup->addItem(F_SET_AS_HOMECITY, STR_ID_VAPP_WC_HOMECICY_MENU, VCP_POPUP_BUTTON_TYPE_NORMAL);

    }
    //cmdPopup->addItem(F_SET_AS_HOMECITY, VFX_WSTR_RES(STR_ID_VAPP_WC_HOMECICY_MENU), VCP_POPUP_BUTTON_TYPE_NORMAL);
#endif
	cmdPopup->addItem(F_REMOVE, STR_GLOBAL_REMOVE, VCP_POPUP_BUTTON_TYPE_NORMAL);
    cmdPopup->addItem(F_CLOSE, STR_GLOBAL_CANCEL, VCP_POPUP_BUTTON_TYPE_CANCEL);
    cmdPopup->m_signalButtonClicked.connect(this, &VappWCListViewPage::onFrnCmdPopCallback);
    cmdPopup->setAutoDestory(VFX_TRUE);
    cmdPopup->show(VFX_TRUE);

}


void VappWCListViewPage::onFrnCmdPopCallback(VfxObject *obj, VfxId id)
{
	switch (id)
	   {
		   case F_REPLACE_CITY:
		   {
	   	//#ifndef __MMI_WORLDCLOCK_SLIM__
			   m_frnflag = 1;
		//#endif
			   showSelectCityPage(VFX_FALSE, VFX_FALSE);
			   break;
		   }
		   case F_ACTIVE_DAY_LIGHT:
		   {
			   FrnDLSHandler(1);
			   break;
		   }
		   case F_SET_AS_HOMECITY:
		   {
			   VFX_OBJ_CLOSE(obj);
			   VcpConfirmPopup *cfPopup;
			   VFX_OBJ_CREATE(cfPopup, VcpConfirmPopup, this);
			   cfPopup->setText(STR_ID_VAPP_WC_HOMECICY_CHANGE_POP);
			   cfPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
			   cfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
			   cfPopup->setCustomButton(
						   STR_GLOBAL_CONTINUE,
						   STR_GLOBAL_CANCEL,
						   VCP_POPUP_BUTTON_TYPE_WARNING,
						   VCP_POPUP_BUTTON_TYPE_CANCEL
						   );
			   cfPopup->m_signalButtonClicked.connect(this, &VappWCListViewPage::onFrnCmdPopCallback);
			   cfPopup->show(VFX_TRUE);
			   break;
		   }
		   case F_REMOVE:
		   {
			  // VFX_OBJ_CLOSE(obj);
			   VcpConfirmPopup *cfPopup;
			   VFX_OBJ_CREATE(cfPopup, VcpConfirmPopup, this);
			   cfPopup->setText(STR_ID_VAPP_WC_DEL_WARNING);
			   cfPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
			   cfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
			   cfPopup->setCustomButton(
						   STR_GLOBAL_REMOVE,
						   STR_GLOBAL_CANCEL,
						   VCP_POPUP_BUTTON_TYPE_WARNING,
						   VCP_POPUP_BUTTON_TYPE_CANCEL
						   );
			   cfPopup->m_signalButtonClicked.connect(this, &VappWCListViewPage::onDeleteCell);
			   cfPopup->show(VFX_TRUE);
			   break;
		   }
		   case F_CLOSE:
			   break;
		   case VCP_CONFIRM_POPUP_BUTTON_USER_1:
		   {
		   	#ifndef __MMI_WORLDCLOCK_SLIM__
				VfxU8 dst = m_dataControl.getFrnCityDst(m_selectID - 1);
				VfxU8 cityIndex = m_dataControl.getFrnCityIndex(m_selectID - 1);
				VfxU8 i ;
				for(i = m_selectID;i < WC_FRN_CITY_NUM;i++)
				{
						if(m_dataControl.getFrnCityIndex(i))
						{
					m_dataControl.saveFrnCityIdx(m_dataControl.getFrnCityIndex(i), i - 1);
					m_dataControl.saveFrnCityDst(m_dataControl.getFrnCityDst(i), i - 1);
				}
				else
					break;

				}
				m_dataControl.saveFrnCityIdx(0, i - 1);
				m_dataControl.saveFrnCityDst(0, i - 1);
				
			#else
				VfxU8 dst = m_dataControl.getFrnCityDst(m_selectID);
				VfxU8 cityIndex = m_dataControl.getFrnCityIndex(m_selectID);
			#endif	
				VfxS8 dstFlag = dst - m_dataControl.getHomeCityDst();
				m_dataControl.updateSysTime(cityIndex, dstFlag);
				m_dataControl.saveHomeCityIdx(cityIndex);
				m_dataControl.saveHomeCityDst(dst);
				m_signalCityChanged.postEmit(this, cityIndex);

		   }
		   default:
			   break;
	   }

}


void VappWCListViewPage::FrnDLSHandler(VfxBool flag)
{
    VfxWString infoStr;
#ifndef __MMI_WORLDCLOCK_SLIM__
    if (m_dataControl.getFrnCityDst(m_selectID - 1) != 0)
    {
        m_dataControl.saveFrnCityDst(0, m_selectID - 1);;
        //infoStr = VFX_WSTR_RES(STR_ID_VAPP_WC_DST_POP_INACT);
		infoStr.loadFromRes(STR_ID_VAPP_WC_DST_POP_INACT);
    }
    else
    {
        m_dataControl.saveFrnCityDst(1, m_selectID - 1);
        //infoStr = VFX_WSTR_RES(STR_ID_VAPP_WC_DST_POP_ACT);
		infoStr.loadFromRes(STR_ID_VAPP_WC_DST_POP_ACT);
    }
#else
    if (m_dataControl.getFrnCityDst(m_selectID) != 0)
    {
        m_dataControl.saveFrnCityDst(0, m_selectID);;
        //infoStr = VFX_WSTR_RES(STR_ID_VAPP_WC_DST_POP_INACT);
		infoStr.loadFromRes(STR_ID_VAPP_WC_DST_POP_INACT);
    }
    else
    {
        m_dataControl.saveFrnCityDst(1, m_selectID);
        //infoStr = VFX_WSTR_RES(STR_ID_VAPP_WC_DST_POP_ACT);
		infoStr.loadFromRes(STR_ID_VAPP_WC_DST_POP_ACT);
    }
#endif	
    if (flag == 1)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)infoStr.getBuf());
    }
    m_listmenu->updateItem(m_selectID);


}


void VappWCListViewPage::onDeleteCell(VfxObject *obj, VfxId id)
{
	VfxU32 i ;
	if(id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
	{
#ifndef __MMI_WORLDCLOCK_SLIM__
		for(i = m_selectID; i < WC_FRN_CITY_NUM; i++)
#else
		for(i = m_selectID + 1; i < WC_FRN_CITY_NUM; i++)
#endif			
		{
			if(m_dataControl.getFrnCityIndex(i))
			{
				m_dataControl.saveFrnCityIdx(m_dataControl.getFrnCityIndex(i), i - 1);
				m_dataControl.saveFrnCityDst(m_dataControl.getFrnCityDst(i), i - 1);
			}
			else
			{
				break;
			}

		}
	
		m_dataControl.saveFrnCityIdx(0, i - 1);
		m_dataControl.saveFrnCityDst(0, i - 1);
	#ifdef __MMI_WORLDCLOCK_SLIM__
		if(i == 1)
		{
			m_cityIndex[0] = 0;	

		}
	#endif
		m_signalCityChanged.postEmit(this, m_citySelect);
		VFX_OBJ_CLOSE(obj);
	}
}
#pragma arm section code, rodata
#endif //__LOW_COST_SUPPORT__
