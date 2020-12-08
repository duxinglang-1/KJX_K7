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
 * vapp_worldclock_data_control.cpp
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
#include "vapp_worldclock_data_control.h"
#include "vapp_worldclock_gprot.h"
//#include "mmi_rp_vapp_worldclock_def.h"
#include "mmi_rp_vapp_clock_def.h"
#include "custom_world_clock.h"
#include "vfx_string.h"

extern "C"
{
#include "GeneralSettingSrvGprot.h"
}
#pragma arm section code = "DYNAMIC_CODE_CLOCK_ROCODE", rodata = "DYNAMIC_CODE_CLOCK_RODATA"
VfxWString VappWCDataControl::getCityString(VfxU16 cityIndex)
{
    VfxWString cityString;
    VfxU16 strid;
    strid = mmi_wc_get_city_strid(cityIndex);
    cityString.loadFromRes(strid);
    return cityString;
}
 
VfxWString VappWCDataControl::getTimeZoneStr(VfxFloat tz)
{
    VfxS8 sym;
    VfxU32 i, j;
    VfxWString tzString;
    VfxWString temp;
    tzString.loadFromRes(STR_ID_VAPP_WC_GMT);
    if (tz >= 0)
    {
        if (tz == 0)
            sym = WC_SYM_SPACE;
        else
            sym = WC_SYM_POSITIVE;
    }
    else
    {
        sym = WC_SYM_NEGATIVE;
        tz = -(tz);
    }
    temp.format("%c", sym);
    tzString += temp;
        
    i = (VfxU32)(tz * 100) / 100;
    j = (VfxU32)(tz * 100) % 100;
    if (j == 0)
    {
        temp.format("%d", i);
    }
    else
    {
        if (j * 2 % 100 == 0)
            j = 5;
        temp.format("%d.%d", i, j);
       
    }
    tzString +=temp;
    return tzString;
}

VfxFloat VappWCDataControl::getTimeZone(VfxU16 cityIndex)
{
    return mmi_wc_get_time_zone(cityIndex);
}

VfxU16 VappWCDataControl::getCityListByName(VfxWChar *city, VfxU16 *result)
{
    return mmi_wc_search_byname(city, result);
}

VfxU16 VappWCDataControl::getHomeCityIndex()
{
    return mmi_wc_get_home_index();
}

VfxU16 VappWCDataControl::getFrnCityIndex(VfxU8 m_cityCount)
{
    return mmi_wc_get_frn_index(m_cityCount);
}

void VappWCDataControl::saveHomeCityIdx(VfxU16 cityIndex)
{
    mmi_wc_save_home_city(cityIndex);
}

void VappWCDataControl::saveFrnCityIdx(VfxU16 cityIndex, VfxU8 m_cityCount)
{
    mmi_wc_save_frn_city(cityIndex, m_cityCount);
}

#ifndef __LOW_COST_SUPPORT_COMMON__

VfxU16 VappWCDataControl::getCityListByTZ(VfxFloat tz, VfxU16 *result)
{
    return mmi_wc_search_bytz(tz, result);
}

VfxU16 VappWCDataControl::getCityByPos(VfxPoint pos)
{
    WCCityPosition cityPos;
    cityPos.pos_x = pos.x;
    cityPos.pos_y = pos.y;
    VfxU16 touchCity[20];
    VfxU16 distance = WC_SEARCH_BY_POS_DISTANCE;
    for (VfxU8 i = 0; i < 20; i++)
    {
        touchCity[i] = 0;
    }
    VfxU16 cityCount = 0;
    cityCount = mmi_wc_search_bypos(cityPos, distance, touchCity);	
    VfxU16 cityIndex = touchCity[0];
    if(cityCount > 1)
    {
        cityPos = mmi_wc_get_city_pos(touchCity[0]);
        VfxU16 distance = (cityPos.pos_x - pos.x)*(cityPos.pos_x - pos.x) + 
                            (cityPos.pos_y - pos.y)*(cityPos.pos_y - pos.y);
        VfxU16 distance2;
        for (VfxU8 i = 1; i < cityCount; i++)
        {
            cityPos = mmi_wc_get_city_pos(touchCity[i]);
            distance2 = (cityPos.pos_x - pos.x)*(cityPos.pos_x - pos.x) + 
                        (cityPos.pos_y - pos.y)*(cityPos.pos_y - pos.y);
            if (distance2 < distance)
            {
                cityIndex = touchCity[i];
            }
        }
    }
    return cityIndex;
}

VfxU16 VappWCDataControl::getCityByX(VfxS32 posX)
{
    VfxU16 touchCity[30];
    VfxU16 distance = WC_SEARCH_BY_X_DISTANCE;
    for (VfxU8 i = 0; i < 30; i++)
    {
        touchCity[i] = 0;
    }
    VfxU16 cityCount = 0;
    cityCount = mmi_wc_search_by_x(posX, distance, touchCity);
    VfxU16 cityIndex = touchCity[0];
    if (cityCount > 1)
    {
        WCCityPosition cityPos = mmi_wc_get_city_pos(touchCity[0]);
        distance = vfxAbs(cityPos.pos_x - posX);
        for (VfxU8 i = 1; i < cityCount; i++)
        {
            cityPos = mmi_wc_get_city_pos(touchCity[i]);
            VfxU16 dis = vfxAbs(cityPos.pos_x - posX);
            if (dis < distance)
            {
                distance = dis;
                cityIndex = touchCity[i];
            }
        }
    }
    return cityIndex;
}

VfxPoint VappWCDataControl::getCityPos(VfxU16 cityIndex)
{
    VfxPoint cityPos;
    WCCityPosition temp;
    temp = mmi_wc_get_city_pos(cityIndex);
    cityPos.x = temp.pos_x;
    cityPos.y = temp.pos_y;
    return cityPos;
}
#endif

VfxU8 VappWCDataControl::getTimeFormat()
{
    if(srv_setting_get_time_format())
        return 1;
    else
        return 0;
}

VfxWString VappWCDataControl::getAmPmString(VfxDateTime dt)
{
    VfxWString amPm;
    if (srv_setting_get_time_format() == SETTING_TIME_FORMAT_12_HOURS)
    {
        VfxWChar string_buf[32], ampm_buf[3];
        VfxU8 str_len;
        dt.getDateTimeString(VFX_DATE_TIME_TIME_MINUTE|VFX_DATE_TIME_TIME_HOUR, (VfxWChar*)string_buf, 32);
        str_len = vfx_sys_wcslen((VfxWChar*)string_buf);
        vfx_sys_wcscpy((VfxWChar*)ampm_buf, (VfxWChar*)&string_buf[str_len-2]);
        amPm.loadFromMem(ampm_buf);
    }
    return amPm;
}

void VappWCDataControl::getTime(VfxFloat src, VfxFloat des, VfxDateTime &dt)
{
    VfxU8 increase_flag = 0;
    VfxFloat time_zone_diff = 0;
    applib_time_struct temp_time, time_diff, time_result;
    applib_dt_get_rtc_time(&temp_time);
    if (des > src)
    {
        increase_flag = 1;
        time_zone_diff = des - src ;
    }
    else if (des < src)
    {
        increase_flag = 0;
        time_zone_diff = des - src ;
        time_zone_diff = - time_zone_diff;
    }
    
    time_diff = applib_conv_tz_to_mytime(time_zone_diff);
    if (increase_flag)
    {
        applib_dt_increase_time(&temp_time, &time_diff, &time_result);
    }
    else
    {
        applib_dt_decrease_time(&temp_time, &time_diff, &time_result);
    }
    dt.setDateTime(&time_result);   
}

VfxU8 VappWCDataControl::getHomeCityDst()
{
    return mmi_wc_get_home_dst();
}

VfxU8 VappWCDataControl::getFrnCityDst(VfxU8 m_cityCount)
{
    return mmi_wc_get_frn_dst(m_cityCount);
}

void VappWCDataControl::saveHomeCityDst(VfxU8 homeDst)
{
    mmi_wc_save_home_dst(homeDst);
}

void VappWCDataControl::saveFrnCityDst(VfxU8 frnDst, VfxU8 m_cityCount)
{
    mmi_wc_save_frn_dst(frnDst, m_cityCount);
}

void VappWCDataControl::updateSysTime(VfxU16 newCityIndex, VfxS16 dstFlag)
{
    mmi_wc_update_sys_datetime(newCityIndex, dstFlag);
}
#ifndef __LOW_COST_SUPPORT_COMMON__

VfxFloat VappWCDataControl::getPrevTimeZone(VfxFloat currTZ)
{
    return mmi_wc_get_prev_time_zone(currTZ);
}

VfxFloat VappWCDataControl::getNextTimeZone(VfxFloat currTZ)
{
    return mmi_wc_get_next_time_zone(currTZ);
}
#endif
#pragma arm section code, rodata
