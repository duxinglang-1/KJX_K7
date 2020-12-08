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
 * VappWorldclockMapView.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __VAPP_WORLD_CLOCK_MAP_VIEW_H__
#define __VAPP_WORLD_CLOCK_MAP_VIEW_H__
/****************************************************************************
 *Include
 ***************************************************************************/
#include "vapp_worldclock_panel.h"
#include "Vcp_include.h"
#include "vfx_mc_include.h"
#include "custom_world_clock.h"


/****************************************************************************
 *class
 ***************************************************************************/
/****************************************************************************
 *world clock map view page class
 ***************************************************************************/
class VappWCMapPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappWCMapPage);
     
public:
    VappWCMapPage();
    ~VappWCMapPage();
     
public:
    enum WCFadeAction
    {
        FADE_IN,
        FADE_OUT
    };
    VappWCHomeCityPanel * getHomePanel()
    {
        return m_homeCity;
    }
    void updateMap();
	void map2ndReady();
       
private:
    VfxBool onPenInput(VfxPenEvent & event);  
    VfxBool onKeyInput(VfxKeyEvent & event);
    void onInit();
    void onBackButtonClick(VfxObject*sender, VfxId buttonId);
    void onListButtonClick(VfxObject *sender, VfxId buttonId);
    void onDeleteCell(VfxObject* obj, VfxId id);
    void onSelectCity(VfxObject *sender, VfxU16 cityIndex);
    void onBubbleBack(VfxObject *sender, VfxU16 id);
    void onUpdateMap(VfxObject *sender, VfxU16 id);
    void fadeAction(WCFadeAction fadeAct);
    void showFloatCity(VfxU16 *cityList, VfxS32 &max, VfxS32 &minLeft); 
    void showBackButton();
    void showSelectCityPage();
    void fancyMapView(VfxPoint pos, VfxFloat timeZone);
    void mapFreeRun(VfxPenEvent &event);
    void timeZonePaneleOut();
    void clearMapSpot();
    void showListButton();
    VfxBool isOverlap(VfxU16 cityIndex, VfxU16 *cityList, VfxBool isLeft);
             
private:
    VfxBool m_isTZShow;
    VfxBool m_isMoving;
    VfxBool m_isMapView;
    VfxFloat m_homeTZ;
    VfxFloat m_currTZ;
    VfxS8 m_floatCityCount;
    VappWorldClockTZPanel *m_tzPanel;
    VappWCHomeCityPanel *m_homeCity;
    VappWCFrnCityPanel *m_frnCity1;
    VappWCFrnCityPanel *m_frnCity2;
    VfxTextFrame *m_timeZone;
    VfxImageFrame *m_backGround;    
    VfxImageFrame *m_map;
    VfxImageFrame *m_shadowL;
    VfxImageFrame *m_shadowR;
    VfxImageFrame *m_homeSpot;
    VfxImageFrame *m_frnSpot1;
    VfxImageFrame *m_frnSpot2;
    VcpImageButton *m_listButton;
    VcpImageButton *m_backButton;
    VappWCFloatCity *m_floatCity[WC_FLOAT_CITY_NUM];
    VappWCDataControl m_dataControl;
    VfxFloatTimeline *m_tlShadowL;
    VfxFloatTimeline *m_tlShadowR;
    VfxFloatTimeline *m_tlBackButton;
    VfxFloatTimeline *m_tlTZPanel;
    VfxFontEffect *m_fontEffect;
};

#endif

