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
 * vapp_worldclock_panel.cpp
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file is defines constant, enum value, structure, and function prototype for world clock.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
**********************************************************************************/
/****************************************************************************
  *Include
  ***************************************************************************/
#include "vapp_worldclock_panel.h"
#include "MMIDataType.h"
#include "mmi_rp_vapp_worldclock_def.h"
#include "vapp_worldclock_select_city.h"
#include "custom_world_clock.h"
#include "trc\vadp_app_trc.h"
#include "GlobalResDef.h"
#include "vdat_systime.h"


/****************************************************************************
  *class
  ***************************************************************************/

VFX_IMPLEMENT_CLASS("VappWCHomeCityPanel", VappWCHomeCityPanel, VfxFrame);

VappWCHomeCityPanel :: VappWCHomeCityPanel(VfxMainScr *mainScr):
    m_mainScr(mainScr),
    m_city(NULL),
    m_timeZone(NULL),
    m_analogClock(NULL),
    m_digtalClock(NULL),
    m_date(NULL),
    m_citySelect(0),
    m_amPm(NULL)
{
}
void VappWCHomeCityPanel ::onInit()
{
    VfxFrame::onInit();
    VFX_LOG(VFX_FUNC, VAPP_WORLDCLOCK_ON_INIT_HOME_CITY);
    setSize(WC_HOME_PANEL_WIDTH, WC_HOME_PANEL_HEIGHT);
    setBounds(VfxRect(0, 0, WC_HOME_PANEL_WIDTH, WC_HOME_PANEL_HEIGHT));
    VfxImageFrame *backGround;
    VFX_OBJ_CREATE(backGround, VfxImageFrame, this);
    backGround->setResId(IMG_ID_VAPP_WC_HOME_BG);
    backGround->setSize(WC_HOME_PANEL_WIDTH, WC_HOME_PANEL_HEIGHT);
    backGround->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    VfxImageFrame *homeCityIcon;
    VFX_OBJ_CREATE(homeCityIcon, VfxImageFrame, this);
    homeCityIcon->setResId(IMG_ID_VAPP_WC_HOMECITY_ICON);
    homeCityIcon->setAnchor(1.0, 1.0);
    homeCityIcon->setPos(WC_HOME_CITY_ICON_X, WC_HOME_CITY_ICON_Y);

    VFX_OBJ_CREATE(m_city, VfxTextFrame, this);
    m_city->setString(m_dataControl.getCityString(m_dataControl.getHomeCityIndex()));
    m_city->setFont(VfxFontDesc(WC_HOME_CITY_FONT_SIZE));
    m_city->setAnchor(0.5F, 0.5F);
    m_city->setPos(WC_HOME_CITY_X, WC_HOME_CITY_Y);	

    VFX_OBJ_CREATE(m_timeZone, VfxTextFrame, this);
    m_timeZone->setString(m_dataControl.getTimeZoneStr(m_dataControl.getTimeZone(m_dataControl.getHomeCityIndex())));
    m_timeZone->setFont(VfxFontDesc(WC_HOME_TZ_FONT_SIZE));
    m_timeZone->setColor(VfxColor(255, 200, 200, 200));
    m_timeZone->setPos(WC_HOME_TZ_X, WC_HOME_TZ_Y);
    VdatTimeNotification *systemTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    systemTimeSrv->m_signalTimeChanged.connect(this, &VappWCHomeCityPanel::onSystemTimeChanged);
    updateTime();
}

void VappWCHomeCityPanel::updateTime()
{
    if (m_date != NULL)
    {
        VFX_OBJ_CLOSE(m_date);
    }
    if (m_digtalClock != NULL)
    {
        VFX_OBJ_CLOSE(m_digtalClock);
    }
    if (m_analogClock != NULL)
    {
        VFX_OBJ_CLOSE(m_analogClock);
    }
    if (m_amPm != NULL)
    {
        VFX_OBJ_CLOSE(m_amPm);
    }
    VFX_OBJ_CREATE(m_date, VcpDigitalTextClock, this);  
    m_date->setFormatFlags(VFX_DATE_TIME_DATE_YEAR|
                            VFX_DATE_TIME_DATE_MONTH|
                            VFX_DATE_TIME_DATE_DAY); 
    m_date->setFont(VfxFontDesc(WC_HOME_DATE_FONT_SIZE));
    m_date->setBounds(0, 0, (WC_HOME_DATE_WIDTH + 2), WC_HOME_DATE_HEIGHT);
    m_date->setTextColor(VfxColor(255, 200, 200, 200));
    m_date->setAnchor(1.0F, 0.0F);
    m_date->setPos(WC_HOME_DATE_X, WC_HOME_DATE_Y);
    m_date->setAlignMode(VcpDigitalTextClock::ALIGN_MODE_RIGHT);
    VFX_OBJ_CREATE(m_digtalClock, VcpDigitalTextClock, this); 
    m_digtalClock->setFormatFlags(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE);
    m_digtalClock->setFont(VfxFontDesc(WC_HOME_DCLOCK_FONT_SIZE));
    m_digtalClock->setBounds(0, 0, WC_HOME_DCLOCK_WIDTH, WC_HOME_DCLOCK_HEIGHT);
    m_digtalClock->setAnchor(0.5F, 0.5F);
    m_digtalClock->setPos(WC_HOME_DCLOCK_X, WC_HOME_DCLOCK_Y);
    m_digtalClock->setAlignMode(VcpDigitalTextClock::ALIGN_MODE_LEFT);

    VFX_OBJ_CREATE(m_analogClock, VcpAnalogClock, this);
    m_analogClock->setPos(WC_HOME_ACLOCK_X, WC_HOME_ACLOCK_Y);
    m_analogClock->setCenter(VfxPoint(WC_CLOCK_CENTER_X, WC_CLOCK_CENTER_X));
    setTime();
}

void VappWCHomeCityPanel::setTime()
{
    VfxDateTime dt;
    VfxU16 cityIndex = m_dataControl.getHomeCityIndex();
    VfxFloat homeTz = m_dataControl.getTimeZone(cityIndex);
    m_dataControl.getTime(homeTz, homeTz, dt);
    VfxU32 hour = dt.getHour();
    if (hour >=6 && hour < 18 )
    {
        m_analogClock->setClockBackground(vrt_sys_res_image_lock(IMG_ID_VAPP_WC_ACLOCK_DAY_BG));
        m_analogClock->setClockHourHand(IMG_ID_VAPP_WC_ACLOCK_DAY_H);
        m_analogClock->setClockMinuteHand(IMG_ID_VAPP_WC_ACLOCK_DAY_M);
        m_analogClock->setClockSecondHand(IMG_ID_VAPP_WC_ACLOCK_DAY_S);
        m_analogClock->setClockAxis(IMG_ID_VAPP_WC_ACLOCK_DAY_C);
    }
    else
    {
        m_analogClock->setClockBackground(vrt_sys_res_image_lock(IMG_ID_VAPP_WC_ACLOCK_NIGHT_BG));
        m_analogClock->setClockHourHand(IMG_ID_VAPP_WC_ACLOCK_NIGHT_H);
        m_analogClock->setClockMinuteHand(IMG_ID_VAPP_WC_ACLOCK_NIGHT_M);
        m_analogClock->setClockSecondHand(IMG_ID_VAPP_WC_ACLOCK_NIGHT_S);
        m_analogClock->setClockAxis(IMG_ID_VAPP_WC_ACLOCK_NIGHT_C);
    }
    if (m_dataControl.getTimeFormat() == 0)
    {
        VFX_OBJ_CREATE(m_amPm, VfxTextFrame, this);
        m_amPm->setString(m_dataControl.getAmPmString(dt));
        VfxFontDesc font;
        font.size = WC_HOME_AMPM_FONT_SIZE;
        m_amPm->setFont(font);
        m_amPm->setPos(WC_HOME_AMPM_POS_X, WC_HOME_AMPM_POS_Y);
    }
    m_analogClock->setTime(dt);
    m_digtalClock->setTime(dt);
    m_date->setTime(dt);
    m_analogClock->startClock();
    m_digtalClock->startClock();
    m_date->startClock(); 
}

void VappWCHomeCityPanel::onSelectCity(VfxObject *sender, VfxU16 cityIndex)
{
    m_citySelect = cityIndex;
    VappWCSelectCityPage *page = VFX_OBJ_DYNAMIC_CAST(sender, VappWCSelectCityPage);
    if (page != NULL)
    {
        VcpConfirmPopup *cfPopup;
        VFX_OBJ_CREATE(cfPopup, VcpConfirmPopup, sender);
        cfPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WC_HOMECICY_CHANGE_POP));
        cfPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
        cfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
        cfPopup->setCustomButton(
                        VFX_WSTR_RES(STR_GLOBAL_CONTINUE),
                        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                        VCP_POPUP_BUTTON_TYPE_WARNING,
                        VCP_POPUP_BUTTON_TYPE_CANCEL
                        );
        cfPopup->m_signalButtonClicked.connect(this, &VappWCHomeCityPanel::onCmdPopCallback);
        cfPopup->show(VFX_TRUE);
    }
}

void VappWCHomeCityPanel::onSetHomeCity(VfxObject *sender, VfxU16 cityIndex, VfxU8 dst)
{
    if (cityIndex == m_dataControl.getHomeCityIndex())
    {
        return;
    }
    m_citySelect = cityIndex;
    VfxS8 dstFlag = dst - m_dataControl.getHomeCityDst();
    m_dataControl.updateSysTime(m_citySelect, dstFlag);
    m_dataControl.saveHomeCityDst(dst);
    update(m_citySelect);
    m_signalCityChanged.postEmit(this, m_citySelect);
}
	
void VappWCHomeCityPanel::onDayLightSavingChange(VfxObject *sender, VfxU16 cityIndex, VfxU8 dst)
{
    if (cityIndex == m_dataControl.getHomeCityIndex() && cityIndex != 0)
    {
        dayLightSavingHandler(0);
    }
}

void VappWCHomeCityPanel::onCmdPopCallback(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case REPLACE_CITY:
        {
            showSelectCityPage();
            break;
        }
        case ACTIVE_DAY_LIGHT:
        {
            VfxU8 dst = m_dataControl.getHomeCityDst() == 1 ? 0 : 1;
            dayLightSavingHandler(1);
            m_signalDstChanged.postEmit(this, m_dataControl.getHomeCityIndex(), dst);
            break;
        }
        case CLOSE:
            break;
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            if (m_citySelect != m_dataControl.getHomeCityIndex())
            {
                VfxU8 homeDst = 0;
                for (VfxU32 i = 0; i < WC_FRN_CITY_NUM; i++)
                {
                   if (m_citySelect == m_dataControl.getFrnCityIndex(i))
                   {
                       homeDst = m_dataControl.getFrnCityDst(i);
                   }
                }
                m_dataControl.updateSysTime(m_citySelect, homeDst - m_dataControl.getHomeCityDst()); 
                m_dataControl.saveHomeCityDst(homeDst);
                update(m_citySelect);
            }
            VappWCSelectCityPage *page = VFX_OBJ_DYNAMIC_CAST(obj->getParent(), VappWCSelectCityPage);
            if (page != NULL)
            {
                m_mainScr->popPage();
            }        	
            m_signalCityChanged.postEmit(this, m_citySelect);
            break;
        }
    }
}

void VappWCHomeCityPanel::onSystemTimeChanged(VfxU32 flag)
{
    if (flag & VDAT_SYSTIME_CHANGED_HOUR) 
    {
        updateTime();
    }
}

void VappWCHomeCityPanel::showSelectCityPage()
{
    VappWCSelectCityPage *page;
    VFX_OBJ_CREATE_EX(page, VappWCSelectCityPage, m_mainScr,(VFX_FALSE));
    page->m_signalCitySelected.connect(this, &VappWCHomeCityPanel::onSelectCity);
    page->setTitleText(VFX_WSTR_RES(STR_ID_VAPP_WC_ADDCICY));					
    m_mainScr->pushPage(0, page);
}
void VappWCHomeCityPanel::showEditMenu()
{
    VcpCommandPopup *cmdPopup;
    VFX_OBJ_CREATE(cmdPopup, VcpCommandPopup, m_mainScr);
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
    cmdPopup->m_signalButtonClicked.connect(this, &VappWCHomeCityPanel::onCmdPopCallback);
    cmdPopup->setAutoDestory(VFX_TRUE);
    cmdPopup->show(VFX_TRUE);
}

void VappWCHomeCityPanel::update(VfxU16 cityIndex)
{
    m_dataControl.saveHomeCityIdx(cityIndex);
    VfxWString cityString;	
    cityString = m_dataControl.getCityString(cityIndex);
    setCityString(cityString);
    VfxFloat tz;
    VfxWString tzString;
    tz = m_dataControl.getTimeZone(cityIndex);
    tzString = m_dataControl.getTimeZoneStr(tz);
    setTimeZone(tzString);
    updateTime();
}

void VappWCHomeCityPanel::dayLightSavingHandler(VfxU8 flag)
{
    VfxWString infoStr;
    VfxU8 dst = m_dataControl.getHomeCityDst();
    if (dst != 0)
    {
        m_dataControl.saveHomeCityDst(0);
        m_dataControl.updateSysTime(m_dataControl.getHomeCityIndex(), -1);
        infoStr = VFX_WSTR_RES(STR_ID_VAPP_WC_DST_POP_INACT);
    }
    else
    {
        m_dataControl.saveHomeCityDst(1);
        m_dataControl.updateSysTime(m_dataControl.getHomeCityIndex(), 1);
        infoStr = VFX_WSTR_RES(STR_ID_VAPP_WC_DST_POP_ACT);
    }
    if (flag == 1)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)infoStr.getBuf());
    }
    updateTime();
}


VFX_IMPLEMENT_CLASS("VappWCFrnCityPanel", VappWCFrnCityPanel, VfxFrame);
VappWCFrnCityPanel::VappWCFrnCityPanel(VfxMainScr *mainScr, VfxU8 cityCount) :
    m_mainScr(mainScr),
    m_cityCount(cityCount),
    m_cityIndex(0),
    m_plus(NULL),
    m_addString(NULL),
    m_city(NULL),
    m_timeZone(NULL),
    m_digtalClock(NULL),
    m_date(NULL),
    m_amPm(NULL)
{
}

void VappWCFrnCityPanel::onInit()
{
    VfxFrame::onInit();
    VFX_LOG(VFX_INFO, VAPP_WORLDCLOCK_ON_INIT_FOREIGN_CITY, m_cityCount);
    setSize(WC_FOREIGN_PANEL_WIDTH, WC_FOREIGN_PANEL_HEIGHT);
    setBounds(VfxRect(0, 0, WC_FOREIGN_PANEL_WIDTH, WC_FOREIGN_PANEL_HEIGHT));
    VfxImageFrame *backGround;
    VFX_OBJ_CREATE(backGround, VfxImageFrame, this);
    backGround->setResId(IMG_ID_VAPP_WC_FOREIGN_BG);
    backGround->setSize(WC_FOREIGN_PANEL_WIDTH, WC_FOREIGN_PANEL_HEIGHT);
    backGround->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_cityIndex = m_dataControl.getFrnCityIndex(m_cityCount);
    if(m_cityIndex)
    {
        initCityInfor(m_cityIndex);
    }
    else
    {
        showEmpty();
    }
}

void VappWCFrnCityPanel::initCityInfor(const VfxU16 &cityIndex)
{
    VfxWString frnCity;
    frnCity = m_dataControl.getCityString(cityIndex);
    VFX_OBJ_CREATE (m_city, VfxTextFrame, this);
    m_city->setString(frnCity);
    m_city->setFont(VfxFontDesc(WC_FOREIGN_CITY_FONT_SIZE));
    m_city->setAnchor(0.5F, 0.0F);
    m_city->setPos(VfxPoint(getSize().width >> 1, WC_FOREIGN_CITY_Y));
    VFX_OBJ_CREATE (m_timeZone, VfxTextFrame, this);
    VfxFloat timeZone = m_dataControl.getTimeZone(m_dataControl.getFrnCityIndex(m_cityCount));
    m_timeZone->setString(m_dataControl.getTimeZoneStr (timeZone));
    m_timeZone->setFont(VfxFontDesc(WC_FOREIGN_TZ_FONT_SIZE));
    m_timeZone->setColor(VfxColor(255, 200, 200, 200));
    m_timeZone->setAnchor(0.5F, 0.0F);
    m_timeZone->setPos(VfxPoint(getSize().width >> 1, WC_FOREIGN_TZ_Y));
    updateTime();
}

void VappWCFrnCityPanel::onSelectCity(VfxObject *sender, VfxU16 cityIndex)
{
    VappWCSelectCityPage *page = VFX_OBJ_DYNAMIC_CAST(sender, VappWCSelectCityPage);
    if (page != NULL)
    {
        m_mainScr->popPage();
    }
    if (m_dataControl.getFrnCityIndex(m_cityCount) == cityIndex)
    {
        return;
    }
    m_cityIndex = cityIndex;
    m_dataControl.saveFrnCityIdx(cityIndex, m_cityCount);
    if (cityIndex == m_dataControl.getHomeCityIndex())
    {
        m_dataControl.saveFrnCityDst(m_dataControl.getHomeCityDst(), m_cityCount);
    }
    for (VfxU8 i =0; i < WC_FRN_CITY_NUM; i++)
    {
        if (m_dataControl.getFrnCityIndex(i) == cityIndex)
        {
            m_dataControl.saveFrnCityDst(m_dataControl.getFrnCityDst(i), m_cityCount);
        }
    }
    if(m_city == NULL)
    {
        VFX_OBJ_CLOSE(m_plus);
        VFX_OBJ_CLOSE(m_addString);
    }
    else
    {
        VFX_OBJ_CLOSE(m_city);
        VFX_OBJ_CLOSE(m_digtalClock);
        VFX_OBJ_CLOSE(m_date);
        VFX_OBJ_CLOSE(m_timeZone);
        if (m_amPm != NULL)
        {
            VFX_OBJ_CLOSE(m_amPm);
        }
    }
    initCityInfor(cityIndex);
    m_signalCityChanged.postEmit(this, m_cityIndex);
}

void VappWCFrnCityPanel::onDayLightSavingChange(VfxObject *sender, VfxU16 cityIndex, VfxU8 dst)
{
    if (cityIndex != 0)
    {
        if (cityIndex == m_dataControl.getFrnCityIndex(m_cityCount))
    {
        dayLightSavingHandler(0);
    }
        else if (m_dataControl.getFrnCityIndex(m_cityCount) != 0)
        {
            updateTime();
        }
    }
}

void VappWCFrnCityPanel::onHomeCityChanged(VfxObject *sender, VfxU16 cityIndex)
{
    if (m_dataControl.getFrnCityIndex(m_cityCount) != 0)
    {
        updateTime();
    }
}

void VappWCFrnCityPanel::onCmdPopCallback(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case REPLACE_CITY:
        {
            showSelectCityPage();
            break;
        }
        case ACTIVE_DAY_LIGHT:
        {
            VfxU8 dst = m_dataControl.getFrnCityDst(m_cityCount) == 1 ? 0 : 1;
            m_signalDstChanged.emit(this, m_dataControl.getFrnCityIndex(m_cityCount), dst);
            dayLightSavingHandler(1); 
            break;
        }
        case SET_AS_HOMECITY:
        {
            VFX_OBJ_CLOSE(obj);
            VcpConfirmPopup *cfPopup;
            VFX_OBJ_CREATE(cfPopup, VcpConfirmPopup, this);
            cfPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WC_HOMECICY_CHANGE_POP));
            cfPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            cfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            cfPopup->setCustomButton(
                        VFX_WSTR_RES(STR_GLOBAL_CONTINUE),
                        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                        VCP_POPUP_BUTTON_TYPE_WARNING,
                        VCP_POPUP_BUTTON_TYPE_CANCEL
                        );
            cfPopup->m_signalButtonClicked.connect(this, &VappWCFrnCityPanel::onCmdPopCallback);
            cfPopup->show(VFX_TRUE);
            break;
        }
        case REMOVE:
        {
            VFX_OBJ_CLOSE(obj);
            VcpConfirmPopup *cfPopup;
            VFX_OBJ_CREATE(cfPopup, VcpConfirmPopup, this);
            cfPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WC_DEL_WARNING));
            cfPopup->setInfoType(VCP_POPUP_TYPE_WARNING);
            cfPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
            cfPopup->setCustomButton(
                        VFX_WSTR_RES(STR_GLOBAL_REMOVE),
                        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
                        VCP_POPUP_BUTTON_TYPE_WARNING,
                        VCP_POPUP_BUTTON_TYPE_CANCEL
                        );
            cfPopup->m_signalButtonClicked.connect(this, &VappWCFrnCityPanel::onDeleteCell);
            cfPopup->show(VFX_TRUE);
            break;
        }
        case CLOSE:
            break;
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:
        {
            VfxU8 dst = m_dataControl.getFrnCityDst(m_cityCount);
            m_dataControl.saveFrnCityIdx(0, m_cityCount);
            m_dataControl.saveFrnCityDst(0, m_cityCount);
            VFX_OBJ_CLOSE(m_city);
            VFX_OBJ_CLOSE(m_timeZone);
            VFX_OBJ_CLOSE(m_date);
            VFX_OBJ_CLOSE(m_digtalClock);
            if (m_amPm != NULL)
            {
                VFX_OBJ_CLOSE(m_amPm);
            }
            showEmpty();
            m_signalSetHome.postEmit(this, m_cityIndex, dst);
            m_signalCityChanged.postEmit(this, m_cityIndex);
        }
        default:
            break;
    }
}

void VappWCFrnCityPanel::onDeleteCell(VfxObject *sender, VfxId button)
{
    if(button == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        m_dataControl.saveFrnCityIdx(0, m_cityCount);
        m_dataControl.saveFrnCityDst(0, m_cityCount);
        VFX_OBJ_CLOSE(m_city);
        VFX_OBJ_CLOSE(m_timeZone);
        VFX_OBJ_CLOSE(m_date);
        VFX_OBJ_CLOSE(m_digtalClock);
        if (m_amPm != NULL)
        {
            VFX_OBJ_CLOSE(m_amPm);
        }
        showEmpty();
        m_signalCityChanged.postEmit(this, m_cityIndex);
    }
}


void VappWCFrnCityPanel::showSelectCityPage()
{
    VappWCSelectCityPage *page;
    VFX_OBJ_CREATE_EX(page, VappWCSelectCityPage, m_mainScr, (VFX_FALSE));
    page->m_signalCitySelected.connect(this, &VappWCFrnCityPanel::onSelectCity);
    page->setTitleText(VFX_WSTR_RES(STR_ID_VAPP_WC_ADDCICY));

    m_mainScr->pushPage(VFX_ID_NULL, page);
}

void VappWCFrnCityPanel::showEditMenu()
{
    VcpCommandPopup *cmdPopup;
    VFX_OBJ_CREATE(cmdPopup, VcpCommandPopup, this);
    cmdPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_WC_FOREIGN_OPTION));
    cmdPopup->addItem(REPLACE_CITY, VFX_WSTR_RES(STR_ID_VAPP_WC_REPLACE_CICY), VCP_POPUP_BUTTON_TYPE_NORMAL);
    if (m_dataControl.getFrnCityDst(m_cityCount))
    {
        cmdPopup->addItem(ACTIVE_DAY_LIGHT, VFX_WSTR_RES(STR_ID_VAPP_WC_DST_DISABLE), VCP_POPUP_BUTTON_TYPE_NORMAL);
    }
    else
    {
        cmdPopup->addItem(ACTIVE_DAY_LIGHT, VFX_WSTR_RES(STR_ID_VAPP_WC_DST_ACT), VCP_POPUP_BUTTON_TYPE_NORMAL);
    }
    cmdPopup->addItem(SET_AS_HOMECITY, VFX_WSTR_RES(STR_ID_VAPP_WC_HOMECICY_MENU), VCP_POPUP_BUTTON_TYPE_NORMAL);
    cmdPopup->addItem(REMOVE, VFX_WSTR_RES(STR_GLOBAL_REMOVE), VCP_POPUP_BUTTON_TYPE_NORMAL);
    cmdPopup->addItem(CLOSE, VFX_WSTR_RES(STR_GLOBAL_CANCEL), VCP_POPUP_BUTTON_TYPE_CANCEL);
    cmdPopup->m_signalButtonClicked.connect(this, &VappWCFrnCityPanel::onCmdPopCallback);
    cmdPopup->setAutoDestory(VFX_TRUE);
    cmdPopup->show(VFX_TRUE);
}

void VappWCFrnCityPanel::showEmpty()
{
    VFX_OBJ_CREATE(m_plus, VfxTextFrame, this);
    m_plus->setString(VFX_WSTR("+"));
    VfxFontDesc plusFont;
    plusFont.size = WC_FOREIGN_PLUS_FONT_SIZE;
    m_plus->setFont(plusFont);
    m_plus->setColor(VfxColor(255, 227, 227, 227));
    m_plus->setAnchor(0.5F, 0.5F);
    m_plus->setPos(WC_FOREIGN_PANEL_WIDTH >> 1, WC_FOREIGN_PLUS_Y);
    VFX_OBJ_CREATE(m_addString, VfxTextFrame, this);
    m_addString->setString(VFX_WSTR_RES(STR_GLOBAL_ADD));
    VfxFontDesc addFont;
    addFont.size = WC_FOREIGN_ADD_FONT_SIZE;
    m_addString->setFont(addFont);
    m_addString->setAnchor(0.5F, 0.0F);
    m_addString->setPos(getSize().width >> 1, WC_FOREIGN_ADD_Y);
}

void VappWCFrnCityPanel::setTime()
{
    VfxFloat hometz, tz;	
    tz = m_dataControl.getTimeZone(m_cityIndex);
    VfxDateTime dt;
    hometz = m_dataControl.getTimeZone(m_dataControl.getHomeCityIndex ());
    m_dataControl.getTime(hometz, tz, dt);
    VfxDateTime timeDiff;
    timeDiff.setTime(1, 0, 0);
    if (m_cityIndex != m_dataControl.getHomeCityIndex())
    {
        VfxU8 homeDst = m_dataControl.getHomeCityDst();
        VfxU8 frnDst = m_dataControl.getFrnCityDst(m_cityCount);
        if (frnDst - homeDst > 0)
        {
            dt.increase(timeDiff);
        }
        else if (frnDst - homeDst < 0)
        {
            dt.decrease(timeDiff);
        }
    }
    if (m_dataControl.getTimeFormat() == 0)
    {
        VFX_OBJ_CREATE(m_amPm, VfxTextFrame, this);
        m_amPm->setString(m_dataControl.getAmPmString(dt));
        VfxFontDesc font;
        font.size = WC_FOREIGN_AMPM_FONT_SIZE;
        m_amPm->setFont(font);
        m_amPm->setPos(WC_FOREIGN_AMPM_POS_X, WC_FOREIGN_AMPM_POS_Y);
    }
    m_digtalClock->setTime(dt);
    m_date->setTime(dt);
    m_digtalClock->startClock();
    m_date->startClock();
}

void VappWCFrnCityPanel::updateTime()
{
    if (m_date != NULL)
    {
        VFX_OBJ_CLOSE(m_date);
    }
    if (m_digtalClock != NULL)
    {
        VFX_OBJ_CLOSE(m_digtalClock);
    }
    if (m_amPm != NULL)
    {
        VFX_OBJ_CLOSE(m_amPm);
    }
    VFX_OBJ_CREATE (m_digtalClock , VcpDigitalTextClock, this);
    m_digtalClock->setFormatFlags(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE);
    m_digtalClock->setFont(VfxFontDesc(WC_FOREIGN_DCLOCK_FONT_SIZE));
    m_digtalClock->setBounds(0, 0, WC_FOREIGN_DCLOCK_WIDTH, WC_FOREIGN_DCLOCK_HEIGHT);
    m_digtalClock->setAnchor(0.5F, 0.0F);
    m_digtalClock->setPos(VfxPoint(getSize().width >> 1, WC_FOREIGN_DCLOCK_Y));	
    m_digtalClock->setAlignMode(VcpDigitalTextClock::ALIGN_MODE_LEFT);
    VFX_OBJ_CREATE (m_date, VcpDigitalTextClock, this);  
    m_date->setFormatFlags(VFX_DATE_TIME_DATE_YEAR|
                VFX_DATE_TIME_DATE_MONTH|
                VFX_DATE_TIME_DATE_DAY
                );
    m_date->setFont(VfxFontDesc(WC_FOREIGN_DATE_FONT_SIZE));
    m_date->setTextColor(VfxColor(255, 200, 200, 200));
    m_date->setAnchor(0.5F, 0.0F);
    m_date->setPos(VfxPoint(getSize().width >> 1, WC_FOREIGN_DATE_Y));
    m_date->setAlignMode(VcpDigitalTextClock::ALIGN_MODE_CENTER);
    setTime();
}

void VappWCFrnCityPanel::dayLightSavingHandler(VfxU8 flag)
{
    VfxWString infoStr;
    if (m_dataControl.getFrnCityDst(m_cityCount) != 0)
    {
        m_dataControl.saveFrnCityDst(0, m_cityCount);;
        infoStr = VFX_WSTR_RES(STR_ID_VAPP_WC_DST_POP_INACT);
    }
    else
    {
        m_dataControl.saveFrnCityDst(1, m_cityCount);
        infoStr = VFX_WSTR_RES(STR_ID_VAPP_WC_DST_POP_ACT);
    }
    if (flag == 1)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)infoStr.getBuf());
    }
    updateTime();
}

VFX_IMPLEMENT_CLASS("VappWorldClockTZPanel", VappWorldClockTZPanel, VfxFrame);

void VappWorldClockTZPanel::onInit()
{
    VfxFrame::onInit();
    VFX_LOG(VFX_FUNC, VAPP_WORLDCLOCK_ON_INIT_TZ_PANEL);
    setBounds(0, 0, WC_TZ_PANEL_WIDTH, WC_TZ_PANEL_HEIGHT);
    VFX_OBJ_CREATE(m_timeZone, VfxTextFrame, this);
    VfxFontDesc tzFont;
    tzFont.size = WC_TZ_PANEL_TZ_FONT_SIZE;
    m_timeZone->setFont(tzFont);
    m_timeZone->setColor(VFX_COLOR_WHITE);
    m_timeZone->setAnchor(0.5F, 0.5F);
    m_timeZone->setPos(WC_TZ_PANEL_WIDTH >> 1, WC_TZ_PANEL_TZ_POS_Y);
    VFX_OBJ_CREATE(m_clock, VcpDigitalTextClock, this); 
    m_clock->setFormatFlags(VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE);
    m_clock->setFont(VfxFontDesc(WC_TZ_PANEL_CLOCK_FONT_SIZE));
    m_clock->setBounds(0, 0, WC_TZ_PANEL_CLOCK_WIDTH, WC_TZ_PANEL_CLOCK_HEIGHT);
    m_clock->setAlignMode(VcpDigitalTextClock::ALIGN_MODE_LEFT);
    m_clock->setTextColor(VFX_COLOR_WHITE);
    m_clock->setAnchor(0.5F, 0.5F);
    m_clock->setPos((WC_TZ_PANEL_WIDTH - 10) >> 1, WC_TZ_PANEL_HEIGHT >> 1);
    m_clock->setAlignMode(VcpDigitalTextClock::ALIGN_MODE_LEFT);
    m_clock->startClock(); 
    VFX_OBJ_CREATE(m_date, VcpDigitalTextClock, this);
    m_date->setFormatFlags(VFX_DATE_TIME_DATE_YEAR|
                VFX_DATE_TIME_DATE_MONTH|
                VFX_DATE_TIME_DATE_DAY
                );
    m_date->setFont(VfxFontDesc(WC_TZ_PANEL_DATE_FONT_SIZE));
    m_date->setTextColor(VFX_COLOR_WHITE);
    m_date->setAnchor(0.5F, 0.0F);
    m_date->setPos(WC_TZ_PANEL_WIDTH >> 1, WC_TZ_PANEL_DATE_POS_Y);
    m_date->setAlignMode(VcpDigitalTextClock::ALIGN_MODE_CENTER);
    m_date->startClock(); 
    VfxFloatTimeline *timeline;
    VFX_OBJ_CREATE(timeline, VfxFloatTimeline, this);
    timeline->setTarget(this);
    timeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    timeline->setToValue(1.0F);
    timeline->setDurationTime(3000);
    timeline->start();
}

void VappWorldClockTZPanel::setTimeZone(VfxWString tzString)
{
    m_timeZone->setString(tzString);
}
void VappWorldClockTZPanel::setTime(const VfxDateTime &dt)
{
    m_date->setTime(dt);
    m_clock->setTime(dt);
    VappWCDataControl data;
    if (data.getTimeFormat() == 0)
    {
        VFX_OBJ_CREATE(m_amPm, VfxTextFrame, this);
        m_amPm->setString(data.getAmPmString(dt));
        VfxFontDesc font;
        font.size = WC_TZ_PANEL_AMPM_FONT_SIZE;
        m_amPm->setFont(font);
        m_amPm->setPos(WC_TZ_PANEL_AMPM_POS_X, WC_TZ_PANEL_AMPM_POS_Y);
        m_clock->setPos((WC_TZ_PANEL_WIDTH - font.measureStr(m_amPm->getString()).width) >> 1, WC_TZ_PANEL_HEIGHT >> 1);
    }
}

VFX_IMPLEMENT_CLASS("VappWCFloatCity", VappWCFloatCity, VfxFrame);

VappWCFloatCity::VappWCFloatCity(VfxU16 cityIndex, VfxFontEffect *fontEffect)
{
    VappWCDataControl data;
    m_cityFont.effect = fontEffect->getEffectId();
    m_cityFont.size = WC_FLOAT_CITY_FONT_SIZE;
    m_cityString = data.getCityString(cityIndex);
    m_citySize = m_cityFont.measureStr(m_cityString);
    VfxImageSrc cityImg(IMG_ID_VAPP_WC_LIGHTSPOT_NOR);
    m_citySize.width += cityImg.getSize().width + WC_FLOAT_CITY_GAP;
    m_citySize.height += 4;
    VfxS32 height = cityImg.getSize().height;
    m_citySize.height = m_citySize.height > height ? m_citySize.height : height;
}

void VappWCFloatCity::onInit ()
{
    VfxFrame::onInit();
    VFX_LOG(VFX_FUNC, VAPP_WORLDCLOCK_ON_INIT_FLOAT_CITY);
    setBounds(0, 0, m_citySize.width, m_citySize.height);
    VFX_OBJ_CREATE(m_cityName, VfxTextFrame, this);
    m_cityName->setFont(m_cityFont);
    m_cityName->setColor(VFX_COLOR_BLACK);
    m_cityName->setString(m_cityString);
    VFX_OBJ_CREATE(m_cityImg, VfxImageFrame, this);
    m_cityImg->setResId(IMG_ID_VAPP_WC_LIGHTSPOT_NOR);	
    setAlignMode(SHOW_LEFT);
}

void VappWCFloatCity::setAlignMode(CityStringPos mode)
{
    VfxImageSrc cityImg(IMG_ID_VAPP_WC_LIGHTSPOT_NOR);
    if (mode == SHOW_LEFT)
    {
        m_cityName->setAnchor(1.0F, 0.5F);
        m_cityName->setPos(m_citySize.width - cityImg.getSize().width - WC_FLOAT_CITY_GAP, (m_citySize.height) >> 1);
        m_cityImg->setAnchor(0.0F, 0.5F);
        m_cityImg->setPos(m_citySize.width - cityImg.getSize().width, (m_citySize.height) >> 1);
    }
    else if (mode == SHOW_RIGHT)
    {
        m_cityImg->setAnchor(0.0F, 0.5F);
        m_cityImg->setPos(0, (m_citySize.height) >> 1);
        m_cityName->setAnchor(0.0F, 0.5F);
        m_cityName->setPos(cityImg.getSize().width + WC_FLOAT_CITY_GAP, (m_citySize.height) >> 1);
    }
}
