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
 *****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vapp_worldclock_map_view.h"
#include "mmi_rp_vapp_worldclock_def.h"
#include "vapp_worldclock_select_city.h"
#include "trc\vadp_app_trc.h"
#include "GlobalResDef.h"


/****************************************************************************
 *class
 ***************************************************************************/

VFX_IMPLEMENT_CLASS("VappWCMapPage", VappWCMapPage, VfxPage);

VappWCMapPage::VappWCMapPage():
    m_isTZShow(VFX_FALSE),
    m_isMoving(VFX_FALSE),
    m_isMapView(VFX_FALSE),
    m_homeTZ(0.0F),
    m_currTZ(0.0F),
    m_tzPanel(NULL),
    m_homeCity(NULL),
    m_frnCity1(NULL),
    m_frnCity2(NULL),
    m_timeZone(NULL),
    m_backGround(NULL),    
    m_map(NULL),
    m_shadowL(NULL),
    m_shadowR(NULL),
    m_homeSpot(NULL),
    m_frnSpot1(NULL),
    m_frnSpot2(NULL),
    m_backButton(NULL),
    m_listButton(NULL),
    m_floatCityCount(0)
{
    for (VfxU8 i = 0; i < WC_FLOAT_CITY_NUM; i++)
    {
        m_floatCity[i] = NULL;
    }
    VFX_ALLOC_NEW(m_fontEffect, VfxFontEffect, this);
    m_fontEffect->setType(VFX_FONT_EFFECT_ENHANCED_BORDER);
    m_fontEffect->setEnhancedBorder(VfxColor(255, 255, 255, 255), 2, 0);
}

void VappWCMapPage::onInit()
{
    VfxPage::onInit();
    VFX_LOG(VFX_FUNC, VAPP_WORLDCLOCK_ON_INIT_MAPPAGE);
    //map init
    VFX_OBJ_CREATE(m_map, VfxImageFrame, this);
    m_map->setResId(IMG_ID_VAPP_WC_MAP);
    m_map->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_map->setSize(WC_MAP_WIDTH, WC_MAP_HEIGHT);
    m_map->setPos(0, 0);
    //m_map->setCacheMode(VFX_CACHE_MODE_FORCE);
    m_map->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    m_map->setAutoAnimate(VFX_TRUE);	
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_LINEAR);

    VfxMainScr *scr = getMainScr();
    VFX_OBJ_CREATE_EX(m_homeCity, VappWCHomeCityPanel, this, (scr));
    VFX_OBJ_CREATE_EX(m_frnCity1, VappWCFrnCityPanel, this, (scr, 0));
    VFX_OBJ_CREATE_EX(m_frnCity2, VappWCFrnCityPanel, this, (scr, 1));
    //home city panel init here
    m_homeCity->setPos (WC_HOME_PANEL_X, WC_HOME_PANEL_Y);
    m_homeCity->setAutoAnimate(VFX_TRUE);
   // m_homeCity->m_signalCityChanged.connect(this, &VappWCMapPage::onUpdateMap);
    //m_homeCity->m_signalCityChanged.connect(m_frnCity1, &VappWCFrnCityPanel::onHomeCityChanged);
    //m_homeCity->m_signalCityChanged.connect(m_frnCity2, &VappWCFrnCityPanel::onHomeCityChanged);
    //m_homeCity->m_signalDstChanged.connect(m_frnCity1, &VappWCFrnCityPanel::onDayLightSavingChange);
    //m_homeCity->m_signalDstChanged.connect(m_frnCity2, &VappWCFrnCityPanel::onDayLightSavingChange);
    //foreign city 1
    m_frnCity1->setPos(WC_FOREIGN_PANEL_1_X, WC_FOREIGN_PANEL_1_Y);
    m_frnCity1->setAutoAnimate(VFX_TRUE);
   // m_frnCity1->m_signalCityChanged.connect(this, &VappWCMapPage::onUpdateMap);
    //m_frnCity1->m_signalSetHome.connect(m_homeCity, &VappWCHomeCityPanel::onSetHomeCity);
    //m_frnCity1->m_signalDstChanged.connect(m_homeCity, &VappWCHomeCityPanel::onDayLightSavingChange);
    //m_frnCity1->m_signalDstChanged.connect(m_frnCity2, &VappWCFrnCityPanel::onDayLightSavingChange);
    //foreign city 2
    m_frnCity2->setPos(WC_FOREIGN_PANEL_2_X, WC_FOREIGN_PANEL_2_Y);
    m_frnCity2->setAutoAnimate(VFX_TRUE);
  //  m_frnCity2->m_signalCityChanged.connect(this, &VappWCMapPage::onUpdateMap);
   // m_frnCity2->m_signalSetHome.connect(m_homeCity, &VappWCHomeCityPanel::onSetHomeCity);	
   // m_frnCity2->m_signalDstChanged.connect(m_homeCity, &VappWCHomeCityPanel::onDayLightSavingChange);
   // m_frnCity2->m_signalDstChanged.connect(m_frnCity1, &VappWCFrnCityPanel::onDayLightSavingChange);
    
    updateMap();
    showListButton();
    //time lines
    VFX_OBJ_CREATE(m_tlBackButton, VfxFloatTimeline, this);
    m_tlBackButton->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY); 
    m_tlBackButton->setDurationTime(250);
    VFX_OBJ_CREATE(m_tlTZPanel, VfxFloatTimeline, this);
    m_tlTZPanel->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY); 
    m_tlTZPanel->setDurationTime(250);
    VFX_OBJ_CREATE(m_tlShadowL, VfxFloatTimeline, this);
    m_tlShadowL->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY); 
    m_tlShadowL->setDurationTime(250);
    VFX_OBJ_CREATE(m_tlShadowR, VfxFloatTimeline, this);
    m_tlShadowR->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY); 
    m_tlShadowR->setDurationTime(250);
}

void VappWCMapPage::map2ndReady()
{
	m_map->setCacheMode(VFX_CACHE_MODE_FORCE);

	m_homeCity->m_signalCityChanged.connect(this, &VappWCMapPage::onUpdateMap);
	m_homeCity->m_signalCityChanged.connect(m_frnCity1, &VappWCFrnCityPanel::onHomeCityChanged);
	m_homeCity->m_signalCityChanged.connect(m_frnCity2, &VappWCFrnCityPanel::onHomeCityChanged);
	m_homeCity->m_signalDstChanged.connect(m_frnCity1, &VappWCFrnCityPanel::onDayLightSavingChange);
	m_homeCity->m_signalDstChanged.connect(m_frnCity2, &VappWCFrnCityPanel::onDayLightSavingChange);
	//foreign city 1
	
	m_frnCity1->m_signalCityChanged.connect(this, &VappWCMapPage::onUpdateMap);
	m_frnCity1->m_signalSetHome.connect(m_homeCity, &VappWCHomeCityPanel::onSetHomeCity);
	m_frnCity1->m_signalDstChanged.connect(m_homeCity, &VappWCHomeCityPanel::onDayLightSavingChange);
	m_frnCity1->m_signalDstChanged.connect(m_frnCity2, &VappWCFrnCityPanel::onDayLightSavingChange);
	//foreign city 2
	
	m_frnCity2->m_signalCityChanged.connect(this, &VappWCMapPage::onUpdateMap);
	m_frnCity2->m_signalSetHome.connect(m_homeCity, &VappWCHomeCityPanel::onSetHomeCity);	
	m_frnCity2->m_signalDstChanged.connect(m_homeCity, &VappWCHomeCityPanel::onDayLightSavingChange);
	m_frnCity2->m_signalDstChanged.connect(m_frnCity1, &VappWCFrnCityPanel::onDayLightSavingChange);
		



}

VappWCMapPage::~VappWCMapPage()
{
    VFX_DELETE(m_fontEffect);
}

VfxBool VappWCMapPage::onPenInput(VfxPenEvent & event)
{
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_UP:
        {
            if (m_isMapView == VFX_TRUE)
            {
                if (m_isMoving == VFX_TRUE)
                {
                    m_isMoving = VFX_FALSE;
                    mapFreeRun(event);
                }
                else if (m_isTZShow == VFX_TRUE)
                {
                   timeZonePaneleOut();
                   if (m_backButton == NULL)
                   {
                       showBackButton();
                   }
                }
                else
                {
                    VfxPoint tmp = event.pos;
                    fancyMapView(tmp, 0.0F);
                    m_isTZShow = VFX_TRUE;    
                    if (m_backButton != NULL)
                    {
                        VFX_OBJ_CLOSE(m_backButton);
                    }
                }
                break;
            }
            else
            {
                VfxFrame *hitframe = hitTest(event.getRelPos(this));
                if (hitframe == NULL) break;
                if (hitframe == m_frnCity1 || hitframe->getParentFrame() == m_frnCity1)
                {
                    if (m_dataControl.getFrnCityIndex(0))
                    {
                        m_frnCity1->showEditMenu();
                    }
                    else
                    {
                        m_frnCity1->showSelectCityPage(); 
                    }
                }
                else if (hitframe == m_frnCity2 || hitframe->getParentFrame() == m_frnCity2)
                {
                    if(m_dataControl.getFrnCityIndex(1))
                    {
                        m_frnCity2->showEditMenu();
                    }
                    else
                    {
                        m_frnCity2->showSelectCityPage();
                    }
                }
                else if(hitframe == m_homeCity || hitframe->getParentFrame () == m_homeCity)
                {
                    m_homeCity->showEditMenu();
                }
                else if (hitframe == m_map && m_isTZShow == VFX_FALSE)
                {
                    m_homeCity->setPos(m_homeCity->getPos().x, (- WC_HOME_PANEL_HEIGHT));
                    m_frnCity1->setPos(m_frnCity1->getPos().x, LCD_HEIGHT);
                    m_frnCity2->setPos(m_frnCity2->getPos().x, LCD_HEIGHT);
                    clearMapSpot();
                    showBackButton();
                    VFX_OBJ_CLOSE(m_listButton);
                    m_isMapView = VFX_TRUE;
                }
            }
            m_isTZShow = VFX_FALSE;
            m_isMoving = VFX_FALSE;
            break;
        }
        case VFX_PEN_EVENT_TYPE_LONG_TAP:
        {
            break;
        }
        case VFX_PEN_EVENT_TYPE_MOVE:
        {
            VfxFrame *hitFrame = hitTest(event.pos);
            if (hitFrame == NULL) 
                break;
            if (hitFrame != m_map && hitFrame->getParentFrame() != m_map)
                break;
            if (m_isTZShow == VFX_TRUE)
                break;
            if (m_isMapView == VFX_TRUE && m_isTZShow == VFX_FALSE)
            {
                VfxS32 x;
                VfxS32 movDistanceX = event.pos.x - event.downPos.x;
                VfxS32 movDistanceY = event.pos.y - event.downPos.y;
                if ((movDistanceX >= -10 && movDistanceX <= 10) && (movDistanceY >= -10 && movDistanceY <= 10))
                    break;
                x = m_map->getPos().x + event.pos.x - event.prevPos.x;
                if (x < LCD_WIDTH - WC_MAP_WIDTH)
                {
                    x = LCD_WIDTH - WC_MAP_WIDTH;
                }
                else if (x >0)
                {
                    x = 0;
                }
                VfxAutoAnimate::setDuration(VFX_TIMELINE_DEFAULT_DUR_TIME);
                m_map->setPos(x, m_map->getPos().y);
            }
            m_isMoving = VFX_TRUE;
            break;
        }
        
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            break;
        }
    }
    return VFX_TRUE;
}

VfxBool VappWCMapPage::onKeyInput(VfxKeyEvent & event)
{
    switch (event.keyCode)
    {
        case VFX_KEY_CODE_BACK:
            if (m_isMapView == VFX_TRUE)
            {
                m_isMapView = VFX_FALSE;
                timeZonePaneleOut();
                m_homeCity->setPos(WC_HOME_PANEL_X, WC_HOME_PANEL_Y);
                m_frnCity1->setPos(WC_FOREIGN_PANEL_1_X, WC_FOREIGN_PANEL_1_Y);
                m_frnCity2->setPos(WC_FOREIGN_PANEL_2_X, WC_FOREIGN_PANEL_2_Y);
                if (m_backButton != NULL)
                {
                    VFX_OBJ_CLOSE(m_backButton);
                } 
                updateMap();
                showListButton();
                return VFX_TRUE;
            }
            return VFX_FALSE;
        case VFX_KEY_CODE_ARROW_LEFT:
            if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                if(m_isMapView == VFX_TRUE && m_isTZShow == VFX_FALSE)
                {
                    VfxS32 movDistance = 10;
                    VfxS32 x = m_map->getPos().x - movDistance;
                    if (x < LCD_WIDTH - WC_MAP_WIDTH)
                    {
                        x = LCD_WIDTH - WC_MAP_WIDTH;
                    }
                    m_map->setPos(x, m_map->getPos().y);
                    return VFX_TRUE;
                }
                else if (m_isTZShow == VFX_TRUE)
                {
                    timeZonePaneleOut();
                    m_isTZShow = VFX_TRUE;
                    fancyMapView(VfxPoint(0,0), m_dataControl.getPrevTimeZone(m_currTZ));
                    return VFX_TRUE;
                }
            }
            return VFX_FALSE;
        case VFX_KEY_CODE_ARROW_RIGHT:
            if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
            {
                if (m_isMapView == VFX_TRUE && m_isTZShow == VFX_FALSE)
                {
                    VfxS32 movDistance = 10;
                    VfxS32 x = m_map->getPos().x + movDistance;
                    if (x > 0)
                    {
                        x = 0;
                    }
                    m_map->setPos(x, m_map->getPos().y);
                    return VFX_TRUE;
                }
                else if (m_isTZShow == VFX_TRUE)
                {
                    timeZonePaneleOut();
                    m_isTZShow = VFX_TRUE;
                    fancyMapView(VfxPoint(0,0), m_dataControl.getNextTimeZone(m_currTZ));
                    return VFX_TRUE;
                }
             }
             return VFX_FALSE;
        case VFX_KEY_CODE_OK:
            if (m_isMapView == VFX_FALSE && m_isTZShow == VFX_FALSE)
            {
                m_homeCity->setPos(m_homeCity->getPos().x, (- WC_HOME_PANEL_HEIGHT));
                m_frnCity1->setPos(m_frnCity1->getPos().x, LCD_HEIGHT);
                m_frnCity2->setPos(m_frnCity2->getPos().x, LCD_HEIGHT);
                clearMapSpot();
                showBackButton();
                VFX_OBJ_CLOSE(m_listButton);
                m_isMapView = VFX_TRUE; 
                return VFX_TRUE;
            }
            return VFX_FALSE;
        default:
                return VFX_FALSE;
    }   
}

void VappWCMapPage::onSelectCity(VfxObject *sender, VfxU16 cityIndex)
{
    VappWCSelectCityPage *page = VFX_OBJ_DYNAMIC_CAST(sender, VappWCSelectCityPage);
} 
void VappWCMapPage::onBubbleBack(VfxObject *sender, VfxU16 id)
{
}

void VappWCMapPage::onBackButtonClick(VfxObject *sender, VfxId buttonId)
{
    timeZonePaneleOut();
    m_homeCity->setPos(WC_HOME_PANEL_X, WC_HOME_PANEL_Y);
    m_frnCity1->setPos(WC_FOREIGN_PANEL_1_X, WC_FOREIGN_PANEL_1_Y);
    m_frnCity2->setPos(WC_FOREIGN_PANEL_2_X, WC_FOREIGN_PANEL_2_Y);
    m_isMapView = VFX_FALSE;
    m_tlBackButton->setToValue(0.0F);
    updateMap();
    showListButton();
    VFX_OBJ_CLOSE(sender);
}

void VappWCMapPage::onListButtonClick(VfxObject *sender, VfxId buttonId)
{
    showSelectCityPage();
}

void VappWCMapPage::onUpdateMap(VfxObject *sender, VfxU16 id)
{
    updateMap();
}
void VappWCMapPage::showFloatCity(VfxU16 *cityList, VfxS32 &max, VfxS32 &min)
{
    VFX_LOG(VFX_FUNC, VAPP_WORLDCLOCK_SHOW_FLOATCITY);
    VfxU8 i = 0;
    m_floatCityCount = 0;
	VfxS32 minLeft = 0;
	VfxPoint cityPos[WC_FLOAT_CITY_NUM];
    while (cityList[i] && i < WC_FLOAT_CITY_NUM)
    {
        VfxPoint pos;
        VappWCFloatCity *city;
        VFX_OBJ_CREATE_EX(city, VappWCFloatCity, this,(cityList[i], m_fontEffect));
        cityPos[i] = m_dataControl.getCityPos(cityList[i]);
        pos = convertPointFrom(cityPos[i], m_map);
        VfxS32 cityWidth = city->getCitySize().width;
        if ((pos.x <= cityWidth && isOverlap(cityList[i], cityList, VFX_FALSE) == VFX_FALSE) || isOverlap(cityList[i], cityList, VFX_TRUE)== VFX_TRUE)
        {
            if (pos.x + cityWidth > max)
        	{
				max = cityWidth + pos.x;
			}

                
            cityPos[i].x -= 5; //city Spot 's width is 10
            city->setAlignMode(VappWCFloatCity::SHOW_RIGHT);
            city->setAnchor(0.0F, 0.5F);
			if(pos.x - 5 <= minLeft)
			{
				minLeft = pos.x - 5;
			}
        }
        else
        {
			if((pos.x - cityWidth <= minLeft) && isOverlap(cityList[i], cityList, VFX_FALSE) == VFX_TRUE)
			{
				minLeft = pos.x - cityWidth;
			}
			if(pos.x + 5 > max)
			{
				max = pos.x + 5;
			}
			cityPos[i].x += 5;
             city->setAnchor(1.0, 0.5F);
        }


        //city->setPos(cityPos);
        m_floatCity[m_floatCityCount] = city;
        i ++;
        m_floatCityCount ++;
    }
    if(minLeft < 0)
	{
		VfxS32 oldMapPosX = m_map->getPos().x;
		VfxS32 newMapPosX = oldMapPosX - minLeft;
		m_map->setPos(newMapPosX, m_map->getPos().y);			
	}
	else if(max >LCD_WIDTH)
	{
		VfxS32 oldMapPosX = m_map->getPos().x;
		VfxS32 newMapPosX = oldMapPosX - (max - LCD_WIDTH);
		min = min -(max - LCD_WIDTH);
		min = min > WC_TZ_PANEL_WIDTH ? min : WC_TZ_PANEL_WIDTH;
		m_map->setPos(newMapPosX, m_map->getPos().y);	

	}
	for(i = 0; i < m_floatCityCount; i++)
	{
			{
				m_floatCity[i]->setPos(convertPointFrom(cityPos[i], m_map));
			}
	}
	
}

void VappWCMapPage::showBackButton()
{
    VFX_OBJ_CREATE(m_backButton, VcpImageButton, this);
    VfxImageSrc backButton(IMG_ID_VAPP_WC_BACKBUTTON);
    m_backButton->setSize(backButton.getSize());
    m_backButton->setBounds(VfxRect(0, 0, backButton.getSize().width, backButton.getSize().height));//40, 40));
    VcpStateImage imageList;
    imageList.setImage(IMG_ID_VAPP_WC_BACKBUTTON, IMG_ID_VAPP_WC_BACKBUTTON, IMG_ID_VAPP_WC_BACKBUTTON, IMG_ID_VAPP_WC_BACKBUTTON);
    m_backButton->setImage(imageList);
    m_backButton->setPos(WC_BACK_BUTTON_X, WC_BACK_BUTTON_Y);
    m_backButton->setIsEffect(VFX_TRUE);
    m_backButton->setEffectSize(VfxSize(HALO_WIDTH, HALO_HEIGHT));
    m_backButton->m_signalClicked.connect(this, &VappWCMapPage::onBackButtonClick);
    m_tlBackButton->setTarget(m_backButton);
    m_tlBackButton->setToValue(1.0F);	
}

void VappWCMapPage::showListButton()
{
    VFX_OBJ_CREATE(m_listButton, VcpImageButton, this);
    VfxImageSrc listButton(IMG_ID_VAPP_WC_LISTBUTTON);
    m_listButton->setSize(listButton.getSize());
    m_listButton->setBounds(VfxRect(0, 0, listButton.getSize().width, listButton.getSize().height));//44, 45));
    VcpStateImage imageList;
    imageList.setImage(IMG_ID_VAPP_WC_LISTBUTTON, IMG_ID_VAPP_WC_LISTBUTTON, IMG_ID_VAPP_WC_LISTBUTTON, IMG_ID_VAPP_WC_LISTBUTTON);
    m_listButton->setImage(imageList);
    m_listButton->setPos(WC_LIST_BUTTON_X, WC_LIST_BUTTON_Y);
    m_listButton->m_signalClicked.connect(this, &VappWCMapPage::onListButtonClick);
}


void VappWCMapPage::showSelectCityPage()
{
    VFX_LOG(VFX_FUNC, VAPP_WORLDCLOCK_MAPPAGE_SHOW_SELECTPAGE);
    VappWCSelectCityPage *Page;
    VFX_OBJ_CREATE_EX(Page, VappWCSelectCityPage, getMainScr(),(VFX_TRUE));
    Page->setTitleText(VFX_WSTR_RES(STR_ID_VAPP_WC_CITY_VIEW));
    Page->m_signalCitySelected.connect(this, &VappWCMapPage::onSelectCity);
    getMainScr()->pushPage(0, Page);
}

void VappWCMapPage::fadeAction(WCFadeAction fadeAct)
{
    m_tlShadowL->setTarget(m_shadowL);	 
    m_tlShadowR->setTarget(m_shadowR);
    if (fadeAct == FADE_IN)
    {
        m_tlShadowL->setFromValue(0.0F);
        m_tlShadowL->setToValue(1.0F);
        m_tlShadowR->setFromValue(0.0F);
        m_tlShadowR->setToValue(1.0F);
    }
    else if (fadeAct == FADE_OUT)
    {
        m_tlShadowL->setFromValue(1.0F);
        m_tlShadowL->setToValue(0.0F);
        m_tlShadowR->setFromValue(1.0F);
        m_tlShadowR->setToValue(0.0F);
    }
    m_tlShadowL->start();
    m_tlShadowR->start(); 
}

void VappWCMapPage::updateMap()
{
    VfxPoint pos;
    VfxS16 temp;
    VfxU16 cityIndex;
    cityIndex= m_dataControl.getHomeCityIndex();
    pos = m_dataControl.getCityPos(cityIndex);
    temp = LCD_WIDTH /2 - pos.x;
    if (temp < (LCD_WIDTH - WC_MAP_WIDTH))
    {
        temp = LCD_WIDTH - WC_MAP_WIDTH;
    }
    else if (temp > 0)
    {
        temp = 0;
    }
    m_map->setPos(temp, 0);
    if (cityIndex != 0)
    {
        if (m_homeSpot == NULL)
        {
            VFX_OBJ_CREATE(m_homeSpot, VfxImageFrame, m_map);
            m_homeSpot->setResId(IMG_ID_VAPP_WC_LIGHTSPOT_HOME);
        }
        m_homeSpot->setAnchor(0.5F, 0.5F);
        m_homeSpot->setPos(m_dataControl.getCityPos(cityIndex));
    }
    cityIndex = m_dataControl.getFrnCityIndex(0);
    if (cityIndex != 0)
    {
        if (m_frnSpot1 == NULL)
        {
            VFX_OBJ_CREATE(m_frnSpot1, VfxImageFrame, m_map);
            m_frnSpot1->setResId(IMG_ID_VAPP_WC_LIGHTSPOT_FRN);
        }
        m_frnSpot1->setAnchor(0.5F, 0.5F);
        m_frnSpot1->setPos(m_dataControl.getCityPos(cityIndex));
    }
    else
    {
        if (m_frnSpot1 != NULL)
        {
            VFX_OBJ_CLOSE(m_frnSpot1);
        }
    }
    cityIndex = m_dataControl.getFrnCityIndex(1);
    if (cityIndex != 0)
    {
        if (m_frnSpot2 == NULL)
        {
            VFX_OBJ_CREATE(m_frnSpot2, VfxImageFrame, m_map);
            m_frnSpot2->setResId(IMG_ID_VAPP_WC_LIGHTSPOT_FRN);
        }
        m_frnSpot2->setAnchor(0.5F, 0.5F);
        m_frnSpot2->setPos(m_dataControl.getCityPos(cityIndex));
    }
    else
    {
        if (m_frnSpot2 != NULL)
        {
            VFX_OBJ_CLOSE(m_frnSpot2);
        }
    }
}

void VappWCMapPage::fancyMapView(VfxPoint pos, VfxFloat timeZone)
{
    VFX_LOG(VFX_FUNC, VAPP_WORLDCLOCK_FANCY_MAP);
    VFX_OBJ_CREATE(m_shadowL, VfxImageFrame, this);
    m_shadowL->setResId(IMG_ID_VAPP_WC_SHADOW_L);
    m_shadowL->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    VFX_OBJ_CREATE(m_shadowR, VfxImageFrame, this);
    m_shadowR->setResId(IMG_ID_VAPP_WC_SHADOW_R);
    m_shadowR->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    VfxPoint temp = pos;
    pos.y -= WC_STATUS_BAR_HEIGHT;
    VfxPoint cityPos = convertPointTo(pos, m_map);
    VfxU16 cityIndex = m_dataControl.getCityByPos(cityPos);
	//VfxS32 minLeft;
    if (cityIndex == 0)
    {
        cityIndex = m_dataControl.getCityByX(cityPos.x);
    }
    
    VfxU16 floatCity[WC_FLOAT_CITY_NUM];
    for (VfxU8 i = 0; i < WC_FLOAT_CITY_NUM; i++)
    {
        floatCity[i] = 0;
    }
    VfxFloat tz = timeZone;
    VfxU16 count = 0;
    //there is city, show shadow,timezone and float city
    if (cityIndex != 0)
    {
        if (tz == 0.0f)
        {
            tz = m_dataControl.getTimeZone(cityIndex);
        }
        m_currTZ = tz;
        count = m_dataControl.getCityListByTZ((tz), floatCity);
    }
    if (count != 0)
    {
        VfxS32 min = WC_MAP_WIDTH, max = 0;
        for (VfxU8 i = 0; i < count; i++)
        {
            VfxPoint pos = m_dataControl.getCityPos(floatCity[i]);
            if (min > pos.x)
            {
                min = pos.x;
            }
            if (max < pos.x)
            {
                max = pos.x;
            }
        }
        min += m_map->getPos().x;
        max += m_map->getPos().x;
        VfxS32 rightCityPos = max;
        VfxBool isTZRight = VFX_FALSE;
        
        for (VfxU8 i = 0; i< count; i++)
        {
            VfxFontDesc cityFont(WC_FLOAT_CITY_FONT_SIZE);
            VfxSize citySize = cityFont.measureStr(m_dataControl.getCityString(floatCity[i]));
            VfxImageSrc cityImg(IMG_ID_VAPP_WC_LIGHTSPOT_NOR);
            citySize.width += cityImg.getSize().width + WC_FLOAT_CITY_GAP;
            VfxS32 leftCityPosX = m_dataControl.getCityPos(floatCity[i]).x + m_map->getPos().x - citySize.width;
            VfxS32 rightCityPosX = m_dataControl.getCityPos(floatCity[i]).x + m_map->getPos().x + citySize.width;
            if (leftCityPosX > 0 && isOverlap(floatCity[i], floatCity, VFX_TRUE)== VFX_FALSE)
            {
                if (min > leftCityPosX)
                {
                    min = leftCityPosX;
                }
            }
            else if (rightCityPosX > max)
            {
                max = rightCityPosX;
            }
        }
        VfxS32 lShadowPosX = min - WC_SHADOW_MIN_WIDTH;
        lShadowPosX = lShadowPosX < 0 ? lShadowPosX : 0;
        VfxS32 lShadowWidth = min;
        lShadowWidth = lShadowWidth > WC_SHADOW_MIN_WIDTH ? lShadowWidth : WC_SHADOW_MIN_WIDTH;
        if (max + WC_TZ_PANEL_WIDTH > LCD_WIDTH) //right area cann't lay a tz panel
        {
            lShadowPosX = 0;
            if (min < WC_TZ_PANEL_WIDTH)
            {
                VfxS32 oldMapPosX = m_map->getPos().x;
                VfxS32 newMapPosX = oldMapPosX + WC_TZ_PANEL_WIDTH - min; 
                newMapPosX = newMapPosX > 0 ? 0 : newMapPosX;
                max += newMapPosX - oldMapPosX;
                lShadowWidth = WC_TZ_PANEL_WIDTH;
                if (newMapPosX == 0 && WC_TZ_PANEL_WIDTH > (rightCityPos + newMapPosX - oldMapPosX))//map move left, TZ panel lay right
                {
                    newMapPosX -=  max - (LCD_WIDTH - WC_TZ_PANEL_WIDTH);
                    max = LCD_WIDTH - WC_TZ_PANEL_WIDTH;
                    lShadowWidth = min > WC_SHADOW_MIN_WIDTH ? min : WC_SHADOW_MIN_WIDTH;
                    isTZRight = VFX_TRUE;
                }
                m_map->setPos(newMapPosX, m_map->getPos().y);                
            }
        }
        else
        {
            isTZRight = VFX_TRUE;
        }
		
		showFloatCity(floatCity, max, min);
		
		if(isTZRight == VFX_TRUE)
		{
			lShadowWidth = min;
		}
        else
        {
			lShadowWidth = min > WC_TZ_PANEL_WIDTH ? min : WC_TZ_PANEL_WIDTH;

		}
		
	
        if (isTZRight == VFX_TRUE)
        {
            max = LCD_WIDTH - WC_TZ_PANEL_WIDTH;
        }
		
        VfxS32 rShadowPosX = max;
		rShadowPosX = rShadowPosX < LCD_WIDTH ? rShadowPosX : LCD_WIDTH;
        VfxS32 rShadowWidth = (LCD_WIDTH - max);
        rShadowWidth = rShadowWidth > WC_SHADOW_MIN_WIDTH ? rShadowWidth : WC_SHADOW_MIN_WIDTH;
        m_shadowL->setBounds(0, 0, lShadowWidth, LCD_HEIGHT);        
        m_shadowL->setPos(lShadowPosX, 0);
        m_shadowR->setBounds(0, 0, rShadowWidth, LCD_HEIGHT);
        m_shadowR->setPos(rShadowPosX, 0);
        fadeAction(FADE_IN);
        VFX_OBJ_CREATE(m_tzPanel, VappWorldClockTZPanel, this);
        if (min >= WC_TZ_PANEL_WIDTH)
        {
            m_tzPanel->setAnchor(0.5F, 0.5F);
            m_tzPanel->setPos((min) >> 1, (LCD_HEIGHT >> 1) - 24);
        }
        else if (max > LCD_WIDTH - WC_TZ_PANEL_WIDTH)
        {
            m_tzPanel->setAnchor(0.0F, 0.5F);
            m_tzPanel->setPos(0, (LCD_HEIGHT >> 1) - 24);
        }
        else 
        {
            m_tzPanel->setAnchor(0.5F, 0.5F);
            m_tzPanel->setPos((max + LCD_WIDTH) >> 1, (LCD_HEIGHT >> 1) - 24);
        }
        m_tzPanel->setTimeZone(m_dataControl.getTimeZoneStr(tz));
        VfxDateTime dt;
        m_dataControl.getTime(m_dataControl.getTimeZone(m_dataControl.getHomeCityIndex()), tz, dt);
        m_tzPanel->setTime(dt);
        m_tlTZPanel->setTarget(m_tzPanel);
        m_tlTZPanel->setFromValue(0.0F);
        m_tlTZPanel->setToValue(1.0F);
        m_tlTZPanel->start();
    }
    //there is no city ,just show shadow
    if (cityIndex == 0)
    {
        VfxS32 lShadowWidth = temp.x - WC_SEARCH_BY_X_DISTANCE;
        lShadowWidth = lShadowWidth > 26 ? lShadowWidth : 26;
        m_shadowL->setBounds(0, 0, lShadowWidth, LCD_HEIGHT);
        m_shadowL->setPos(0, 0);
        VfxS32 rShadowWidth = LCD_WIDTH - temp.x - WC_SEARCH_BY_X_DISTANCE;
        m_shadowR->setBounds(0, 0, rShadowWidth, LCD_HEIGHT);
        m_shadowR->setPos(temp.x + 35, 0);
        fadeAction(FADE_IN);
    }
    
}

void VappWCMapPage::mapFreeRun(VfxPenEvent &event)
{
    VfxFloat offset = (VfxFloat) (event.pos.x - event.downPos.x);
    VfxMsec t = event.timeStamp - event.downTimeStamp;
    VfxFloat v = offset * 1000.0F * (0.468F) / (vrt_float)t;
    VfxFloat a = 300.0F;
    if (v > 0)
    {
        a = -a;
    }
    VfxS32 s = (VfxS32)(- v*v/(2*a));
    VfxS32 x;
    x = m_map->getPos().x + s;
    if (x < LCD_WIDTH - WC_MAP_WIDTH)
    {
        x = LCD_WIDTH - WC_MAP_WIDTH;
    }
    else if (x >0)
    {
        x = 0;
    }
    VfxFloat moveTime = v / a;
    moveTime = moveTime >= 0 ? moveTime : - moveTime;
    moveTime *= 1000;
    moveTime = moveTime < 300 ? moveTime : 300;
    VfxAutoAnimate::setDuration((VfxMsec)moveTime);
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_map->setPos(x, m_map->getPos().y);
}

void VappWCMapPage::timeZonePaneleOut()
{
    if (m_isTZShow == VFX_FALSE)
        return;
    m_isTZShow = VFX_FALSE;
    fadeAction(FADE_OUT);
    //close time zone panel
    if (m_tzPanel != NULL)
    {
        m_tlTZPanel->setFromValue(1.0F);
        m_tlTZPanel->setToValue(0.0F);
        m_tlTZPanel->start();
        VFX_OBJ_CLOSE(m_tzPanel);
    }
    if (m_shadowL != NULL)
        VFX_OBJ_CLOSE(m_shadowL);
    if (m_shadowR != NULL)
        VFX_OBJ_CLOSE(m_shadowR);
    if (m_floatCityCount > 0)
    {
        //close float city
        for(m_floatCityCount -= 1; m_floatCityCount >= 0; m_floatCityCount--)
        {
            VFX_OBJ_CLOSE(m_floatCity[m_floatCityCount]);
        }
    }
 }

void VappWCMapPage::clearMapSpot()
{
    if (m_homeSpot != NULL)
    {
        VFX_OBJ_CLOSE(m_homeSpot);
    }
    if (m_frnSpot1 != NULL)
    {
        VFX_OBJ_CLOSE(m_frnSpot1);
    }
    if (m_frnSpot2 != NULL)
    {
        VFX_OBJ_CLOSE(m_frnSpot2);
    }
}

VfxBool VappWCMapPage::isOverlap(VfxU16 cityIndex, VfxU16 *cityList, VfxBool isLeft)
{
    VfxU8 i = 0;
    VfxFontDesc cityFont(WC_FLOAT_CITY_FONT_SIZE);
    VfxSize citySize = cityFont.measureStr(m_dataControl.getCityString(cityIndex));
    VfxPoint cityPos = m_dataControl.getCityPos(cityIndex);
	VfxPoint cityLeftTop;
	VfxPoint cityLeftBottom;
	VfxPoint cityRightTop;
	VfxPoint cityRightBottom;
	if(isLeft)
	{
		 cityLeftTop = VfxPoint(cityPos.x - citySize.width -10, cityPos.y - citySize.height/2);//gap of city spot & city spot's width div 2
		 cityLeftBottom = VfxPoint(cityPos.x - citySize.width - 10, cityPos.y + citySize.height/2);
	}
	else
	{
		 cityRightTop = VfxPoint(cityPos.x + citySize.width + 10, cityPos.y - citySize.height/2);
		 cityRightBottom = VfxPoint(cityPos.x + citySize.width + 10, cityPos.y + citySize.height/2);
	}
    
    while (cityList[i] && i < WC_FLOAT_CITY_NUM)
    {
        VfxPoint pos = m_dataControl.getCityPos(cityList[i]);
        if (cityIndex == cityList[i] || (pos.x <= cityPos.x&& !isLeft) ||(pos.x >= cityPos.x && isLeft))
        {   
            i++;
            continue;
        }
        VfxPoint cityBottom = VfxPoint(pos.x, pos.y + citySize.height/2);
        VfxPoint cityTop = VfxPoint(pos.x, pos.y - citySize.height/2);
		if (isLeft)
		{
			if ((cityPos.y >= pos.y && cityLeftTop.x < cityBottom.x && cityLeftTop.y < cityBottom.y) ||
				(cityPos.y < pos.y && cityLeftBottom.x < cityTop.x && cityLeftBottom.y > cityTop.y && (pos.y - cityPos.y) < (citySize.height - 2)))
        {
            return VFX_TRUE;
        }

		}
		else
		{		
			if ((cityPos.y >= pos.y && cityRightTop.x > cityBottom.x && cityRightTop.y < cityBottom.y) ||
				(cityPos.y < pos.y && cityRightBottom.x > cityTop.x && cityRightBottom.y > cityTop.y && (pos.y - cityPos.y) < (citySize.height - 2)))
			{
				return VFX_TRUE;
			}

		}

        i++;
    }
    return VFX_FALSE;
}


