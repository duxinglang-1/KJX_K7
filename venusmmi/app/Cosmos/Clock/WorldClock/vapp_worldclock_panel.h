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
 * vapp_worldclock_panel.h
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
#ifndef __VAPP_WORLD_CLOCK_PANEL_H__
#define __VAPP_WORLD_CLOCK_PANEL_H__

/****************************************************************************
  *Include
  ***************************************************************************/
#include "vapp_worldclock_data_control.h"
#include "vcp_include.h"
#include "vfx_uc_include.h"

/****************************************************************************
  *Class
  ***************************************************************************/
/****************************************************************************
 *home city panel
 ***************************************************************************/
class VappWCHomeCityPanel : public VfxFrame
{

    VFX_DECLARE_CLASS(VappWCHomeCityPanel);
    
public:
    VappWCHomeCityPanel(){}
    VappWCHomeCityPanel(VfxMainScr *mainScr); 

    enum EditMenu
    {
       REPLACE_CITY,
       ACTIVE_DAY_LIGHT,
       CLOSE
    };
  
    void showSelectCityPage();
    void showEditMenu();
    void onSelectCity(VfxObject *sender, VfxU16 cityIndex);
    void onSetHomeCity(VfxObject *sender, VfxU16 cityIndex, VfxU8 dst);
    void onDayLightSavingChange(VfxObject *sender, VfxU16 cityIndex, VfxU8 dst);
    void update(VfxU16 cityIndex);
    
private:
    virtual void onInit();
    void updateTime();
    void setTime();
    void setTimeZone(const VfxWString tzString)
    {
	    m_timeZone->setString(tzString);
    }
    void setCityString(const VfxWString homeCity)
    {
	    m_city->setString(homeCity);
    }
    void dayLightSavingHandler(VfxU8 flag);
    void onCmdPopCallback(VfxObject *obj, VfxId id);
    void onSystemTimeChanged(VfxU32 flag);

public:
    VfxSignal2 <
        VfxObject *, // Sender
        VfxU16       // cityIndex
        > m_signalCityChanged;
    VfxSignal3 <
        VfxObject *, // Sender
        VfxU16,       // cityIndex
        VfxU8        // daylightsaving
        > m_signalDstChanged;

private:
    VappWCDataControl m_dataControl;
    VfxTextFrame *m_amPm;
    VfxTextFrame *m_city;
    VfxTextFrame *m_timeZone;
    VcpAnalogClock *m_analogClock;
    VcpDigitalTextClock *m_digtalClock;
    VcpDigitalTextClock *m_date;
    VfxMainScr *m_mainScr;
    //VfxFloat m_currTZ;
    VfxU16 m_citySelect;            
};


/****************************************************************************
 *foreign city panel
 ***************************************************************************/
class VappWCFrnCityPanel : public VfxFrame
{

    VFX_DECLARE_CLASS(VappWCFrnCityPanel);
    
public:
    VappWCFrnCityPanel(){}
    VappWCFrnCityPanel(VfxMainScr *mainScr, VfxU8 cityCount);
    enum EditMenu
    {
       REPLACE_CITY,
       ACTIVE_DAY_LIGHT,
       SET_AS_HOMECITY,
       REMOVE,
       CLOSE
    };
    void showSelectCityPage();
    void showEditMenu();
    void onDayLightSavingChange(VfxObject *sender, VfxU16 cityIndex, VfxU8 dst);
    void onHomeCityChanged(VfxObject *sender, VfxU16 cityIndex);
    
public:
    VfxSignal2 <
        VfxObject*,              // Sender
        VfxU16                   // cityIndex
        > m_signalCityChanged;
    VfxSignal3 <
        VfxObject*,              // Sender
        VfxU16,                  // cityIndex
        VfxU8                    //day light saving time
        > m_signalSetHome;
     VfxSignal3 <
        VfxObject *, // Sender
        VfxU16,      // cityIndex
        VfxU8        // daylightsaving
        > m_signalDstChanged;
    
private:
    virtual void onInit();
    void onDeleteCell(VfxObject *sender, VfxId button);
    void initCityInfor(const VfxU16 &cityIndex);
    void setCityString(VfxWString frnCity)
    {
	    m_city->setString(frnCity);
    }
    void setTimeZone(const VfxWString &tzString)
    {
	    m_timeZone->setString(tzString);
    }
    void setTime();
    void updateTime();
    void onSelectCity(VfxObject *sender, VfxU16 cityIndex);
    void onCmdPopCallback(VfxObject *obj, VfxId id);
    void showEmpty();
    void dayLightSavingHandler(VfxU8 flag);
    
private:

    VfxU8 m_cityCount;
    VfxU16 m_cityIndex;
    VfxMainScr *m_mainScr;
    VfxTextFrame *m_amPm;
    VfxTextFrame *m_plus;
    VfxTextFrame *m_addString;
    VfxTextFrame *m_city;
    VfxTextFrame *m_timeZone;
    VcpDigitalTextClock *m_digtalClock;
    VcpDigitalTextClock *m_date;
    VappWCDataControl m_dataControl;
          
};



/****************************************************************************
 *time zone panel show when long tap on map
 ***************************************************************************/
class VappWorldClockTZPanel : public VfxFrame
{
    VFX_DECLARE_CLASS(VappWorldClockTZPanel);

public:
    void setTimeZone(const VfxWString tzString);
    void setTime(const VfxDateTime &dt);

private:

    VfxTextFrame *m_timeZone;
    VfxTextFrame *m_amPm;
    VcpDigitalTextClock *m_date;
    VcpDigitalTextClock *m_clock;
    virtual void onInit ();
};

/****************************************************************************
 *float city 
 ***************************************************************************/
class VappWCFloatCity : public VfxFrame
{
    VFX_DECLARE_CLASS(VappWCFloatCity);

public:

    VappWCFloatCity(){};
    VappWCFloatCity(VfxU16 cityIndex, VfxFontEffect *fontEffect);
    
    enum CityStringPos
    {
        SHOW_LEFT,
        SHOW_RIGHT
    };
    
    void setAlignMode(CityStringPos mode);
    VfxSize getCitySize(void)
    {
        return m_citySize;
    }

private:
    
    VfxTextFrame *m_cityName;
    VfxImageFrame *m_cityImg;
    VfxWString m_cityString;
    VfxSize m_citySize;
    VfxFontDesc m_cityFont;
private:
    virtual void onInit ();
};

#endif
