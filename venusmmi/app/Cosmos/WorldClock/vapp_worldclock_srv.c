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
 * vapp_worldclock_srv.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#include "MMIDataType.h"
#include "vapp_worldclock_gprot.h"
#include "vapp_worldclock_data.h"
#include "custom_mmi_default_value.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_rp_vapp_worldclock_def.h"
#include "mmi_trc_int.h"
#include "worldclock.h"
#include "app_datetime.h"
#include "Unicodexdcl.h"
#include "DateTimeGprot.h"


typedef struct
{
    U16 HomeCityIndex;                      /* index of current selected city in world map */ 
    U16 FrnCityIdx[WC_FRN_CITY_NUM];		/* foreign city index */
    U8 DSTHome;                             /* home city day light saving*/
    U8 DSTForeign[WC_FRN_CITY_NUM];		    /* foreign city day light saving */
    
} worldclock_context_struct;


#define WC_NUM_CITY STR_CITY_TOTAL_NUM - STR_WORLDCLOCK_CITY_NONE
#define WC_MAX_CITY_NAME_LEN 30
#define WC_TZ_COUNT 37
#define WC_SAME_TZ_CITY_NUM 10

worldclock_context_struct wc_cntx; 
U16 WcTimeZoneIndex[WC_NUM_CITY];
const FLOAT ValidTZ[WC_TZ_COUNT] =
    { -12.0, -11.0, -10.0, -9.5, -9.0, -8.5,
      -8.0,  -7.0,  -6.0,  -5.0, -4.0, -3.5, 
      -3.0,  -2.0,  -1.0,   0.0,  1.0,  2.0, 
       3.0,   3.5,   4.0,   4.5,  5.0,  5.5,
       5.75,  6.0,   6.5,   7.0,  8.0,  9.0,
       9.5,   10.0,  10.5,  11.0, 11.5, 12.0, 12.25
     };


/*******************************/
/*           function for pluto              */
/*******************************/
U8 g_dst;
wc_context_struct g_wc_cntx;

void WcInit(void)
{}
FLOAT GetTimeZone(U8 cityIndex)
{
    return mmi_wc_get_time_zone(cityIndex);
}
CHAR *mmi_wc_get_home_city(void)
{
    return 0;
}
void WcSetCityIndex(U16 index)
{}
#if defined (__MMI_NITZ_TZ_SUPPORT__) || defined (__MMI_WC_TZ_SUPPORT__)
void mmi_wc_set_default_city_for_tz(void)
{}
#endif
#ifdef __MMI_NITZ_TZ_SUPPORT__
S16 mmi_wc_set_home_city_from_nitz(S16 nitz_tz, U8 is_set)
{}
#endif /* __MMI_NITZ_TZ_SUPPORT__ */ 
extern U16 mmi_wc_get_default_city_size2(void);


#ifdef __MMI_WORLD_CLOCK__
void HighlightWCMenu(void)
{}
void HighlightWcBrowseCity(void)
{}
void EntryWcBrowseCity(void)
{}
void mmi_wc_set_curr_gid(mmi_id gid)
{}
#endif /* HighlightWCMenu */

#ifdef __MMI_WORLD_CLOCK_SUBLCD_SETTING__
void ReadValueCityNVRAM(void)
{}
#endif
#if defined(__MMI_DUAL_CLOCK__) 
void mmi_wc_get_foreign_city_info(MYTIME *foreign_time, PU8 *city_name)
{}
#endif
void mmi_wc_entry_city_scrn(void)
{}
void cui_worldclock_launch(void)
{}
mmi_id cui_worldclock_create(mmi_id parent_gid)
{
    return 0;
}
void cui_worldclock_set_current_city(U16 city_index)
{}
void cui_worldclock_set_timezone(U16 city_index)
{}
void cui_worldclock_run(mmi_id cui_gid)
{}
void cui_worldclock_close(mmi_id cui_gid)
{}
void mmi_wc_update_datetime(void)
{}
extern U16 srv_phb_convert_to_pinyin(U16 *input_string, U16 *output_string, U16 out_len);
//extern void mmi_dt_set_dt(const MYTIME *time, mmi_dt_set_time_res_funcptr callback, void* usr_data);
extern S8 *GetString(U16 StringId);



/*******************************/

static void mmi_wc_sort_byname(void);
#ifndef __LOW_COST_SUPPORT_COMMON__
static void mmi_wc_sort_bytz(void);
#endif

void mmi_wc_init(void)
{
    mmi_wc_sort_byname();
	
	vapp_wc_init_key_cityinfo();
}

void vapp_wc_init_key_cityinfo(void)
{
    U32 i;
    S16 error;

    ReadValue(NVRAM_WC_HOME_CITY, &wc_cntx.HomeCityIndex, DS_SHORT, &error);
    ReadValue(NVRAM_WC_HOME_DST, &wc_cntx.DSTHome, DS_BYTE, &error);
	
    for(i = 0; i < WC_FRN_CITY_NUM; i++)
    {
        ReadRecord(NVRAM_EF_SRV_WC_FRN_CITY, i + 1, &wc_cntx.FrnCityIdx[i], sizeof(U16), &error);
        ReadRecord(NVRAM_EF_SRV_WC_FRN_DST, i + 1, &wc_cntx.DSTForeign[i], sizeof(U8), &error);
    }

	// sync the city
	for (i = 0; i < WC_FRN_CITY_NUM; i++)
	{
		if (mmi_wc_get_home_index() == mmi_wc_get_frn_index(i))
		{
			mmi_wc_save_frn_dst(wc_cntx.DSTHome, i);
		}
	}	
}

void mmi_wc_sort_byname(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables 											   */
	/*----------------------------------------------------------------*/
	U16 i, j;
	U16 temp;
	U16 index1, index2;
	U16 city_num = NUM_OF_CITY;
	WCHAR city1[WC_MAX_CITY_NAME_LEN], city2[WC_MAX_CITY_NAME_LEN];
	U16 flag = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													   */
	/*----------------------------------------------------------------*/
	for (i = 0; i < city_num; i++)
	{
		WcTimeZoneIndex[i] = i + 1;
	}
 
	for (i = 0; i < city_num - 1; i++)
	{
		for (j = 0; j < (city_num - 1) - i - 1; j++)
		{
			index1 = WcTimeZoneIndex[j + 1];
			index2 = WcTimeZoneIndex[j];
			mmi_wcscpy(city1, (const WCHAR *)GetString(TimeZoneData2[index1].CityName));
            mmi_wcscpy(city2, (const WCHAR *)GetString(TimeZoneData2[index2].CityName));			
			//mmi_ucs2strlen
			if(city1[0] >= 0x4E00 && city1[0] <= 0x9FA5 && flag == 0)
			{
				flag = 1;				
			}
			
			if(flag)
			{
				WCHAR city1_cn[WC_MAX_CITY_NAME_LEN], city2_cn[WC_MAX_CITY_NAME_LEN];
				
				srv_phb_convert_to_pinyin(city1, city1_cn, WC_MAX_CITY_NAME_LEN);
				srv_phb_convert_to_pinyin(city2, city2_cn, WC_MAX_CITY_NAME_LEN);
				if (mmi_wcscmp(city1_cn, city2_cn) < 0)
			{
				temp = WcTimeZoneIndex[j];	
				WcTimeZoneIndex[j] = WcTimeZoneIndex[j + 1];
				WcTimeZoneIndex[j + 1] = temp;
			}

		}
			else
			{

				if (mmi_wcscmp(city1, city2) < 0)
			{
				temp = WcTimeZoneIndex[j];	
				WcTimeZoneIndex[j] = WcTimeZoneIndex[j + 1];
				WcTimeZoneIndex[j + 1] = temp;
			}

}
 
		}
	}
}
#ifndef __LOW_COST_SUPPORT_COMMON__
void mmi_wc_sort_bytz(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U16 tmp;
    U16 swap = FALSE;
    U16 index1, index2;
    U16 city_num = NUM_OF_CITY;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < city_num - 1; i++)
    {
        WcTimeZoneIndex[i] = i + 1;
    }

    for (i = 0; i < city_num - 1; i++)
    {
        for (j = 0; j < (city_num - 1) - i - 1; j++)
        {
            index1 = WcTimeZoneIndex[j + 1];
            index2 = WcTimeZoneIndex[j];
            if (TimeZoneData2[index1].CityTimeZone < TimeZoneData2[index2].CityTimeZone)
            {
                swap = TRUE;
            }
            else if (TimeZoneData2[index1].CityTimeZone == TimeZoneData2[index2].CityTimeZone)
            {
                if (TimeZoneData2[index1].CityPosX < TimeZoneData2[index2].CityPosX)
                {
                    swap = TRUE;
                }
                else if (TimeZoneData2[index1].CityPosX == TimeZoneData2[index2].CityPosX)
                    if (TimeZoneData2[index1].CityPosY < TimeZoneData2[index2].CityPosY)
                    {
                        swap = TRUE;
                    }
            }

            if (swap)
            {
                tmp = WcTimeZoneIndex[j];
                WcTimeZoneIndex[j] = WcTimeZoneIndex[j + 1];
                WcTimeZoneIndex[j + 1] = tmp;
                swap = FALSE;
            }
        }
    }
}
 #endif
U16 mmi_wc_search_byname(WCHAR *cityName, U16 *searchResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 i,count = 0;
        U32 j;
        U16 city_num = NUM_OF_CITY;    
        WCHAR des[WC_MAX_CITY_NAME_LEN + 1], src[WC_MAX_CITY_NAME_LEN + 1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_ASSERT(searchResult != NULL);
    if(cityName != NULL)
    {
        if (cityName[0] == '\n' && mmi_wcslen(cityName) != 1)
        {
            cityName += 1;
        }
        if (mmi_wcslen(cityName) >= WC_MAX_CITY_NAME_LEN)
        {
            cityName[WC_MAX_CITY_NAME_LEN -1] = '\0';
        }
        mmi_wcscpy (src, cityName);
    }
    for (i = 0;  i < WC_MAX_CITY_NAME_LEN && src[i] != '\0'; i++)
    {
        if (src[i] >= 'A' && src[i] <= 'Z')
        {
            src[i] += 32;
        }
    }
	
    for(i = 0;i < city_num - 1; i++)
    {
	mmi_wcscpy(des, (const WCHAR *)GetString(TimeZoneData2[WcTimeZoneIndex[i]].CityName));
        for(j = 0; j < mmi_wcslen(des); j++)
        {
            if (des[j] >= 'A' && des[j] <= 'Z')
            {
                des[j] += 32;
            }
        }
	if(cityName == NULL || mmi_wcsncmp(des, src, mmi_wcslen(cityName)) == 0 || (mmi_wcscmp(cityName, L"\n") == 0))
        {
            searchResult[count++] = WcTimeZoneIndex[i];
        }
    }
    return count;
}
#ifndef __LOW_COST_SUPPORT_COMMON__
U16 mmi_wc_search_bypos(WCCityPosition cityPos,U16 distance, U16 *searchResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 x, y;
    U16 count = 0;
    U16 city_num = NUM_OF_CITY;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(searchResult != NULL);
    for (i = 1; i < city_num; i++)
    {
        if (!TimeZoneData2[i].isMapShow)
            continue;
        x = TimeZoneData2[i].CityPosX;
        y = TimeZoneData2[i].CityPosY;   

        if (x >= cityPos.pos_x - distance && x <= cityPos.pos_x + distance
            && y >= cityPos.pos_y - distance && y <= cityPos.pos_y + distance)
        {
            searchResult[count++] = i;
        }
    }
    return count;
}

U16 mmi_wc_search_by_x(S32 pos_x, U16 distance, U16 *searchResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        U16 i;
        U16 x;
        U16 count = 0;
        U16 city_num = NUM_OF_CITY;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(searchResult != NULL);
    for (i = 1; i < city_num; i++)
    {
        if (!TimeZoneData2[i].isMapShow)
            continue;
        x = TimeZoneData2[i].CityPosX;  

        if (x >= pos_x - distance && x <= pos_x + distance)
        {
            searchResult[count++] = i;
        }
    }
    return count;
}
#endif

U16 mmi_wc_search_bytz(FLOAT cityTZ, U16 *searchResult)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 count = 0;
    U16 city_num = NUM_OF_CITY;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(searchResult != NULL);
    for(i = 1; i < city_num; i++)
    {
        if (!TimeZoneData2[i].isMapShow)
            continue;
        if(TimeZoneData2[i].CityTimeZone == cityTZ)
        {
            searchResult[count++] = i;
        }
    }
    return count;
}


U16 mmi_wc_get_home_index(void)
{
	return wc_cntx.HomeCityIndex;
}
 
U16 mmi_wc_get_frn_index(U8 cityOrder)
{
    MMI_ASSERT(cityOrder < WC_FRN_CITY_NUM);
    return wc_cntx.FrnCityIdx[cityOrder];	
}

void mmi_wc_save_home_city(U16 cityIndex)
{	 
	S16 error;
   
	wc_cntx.HomeCityIndex = cityIndex;
	WriteValue(NVRAM_WC_HOME_CITY, &cityIndex, DS_SHORT, &error);
}

void mmi_wc_save_frn_city(U16 cityIndex, U8 cityOrder)
{	 
    S16 error;
    MMI_ASSERT(cityOrder < WC_FRN_CITY_NUM);
    wc_cntx.FrnCityIdx[cityOrder] = cityIndex;
    WriteRecord(NVRAM_EF_SRV_WC_FRN_CITY, (U16)cityOrder + 1, &cityIndex, sizeof(U16), &error);
}

FLOAT mmi_wc_get_time_zone(U16 cityIndex)
{
	return TimeZoneData2[cityIndex].CityTimeZone;	
}
#ifndef __LOW_COST_SUPPORT_COMMON__

FLOAT mmi_wc_get_next_time_zone(FLOAT currTZ)
{
    U32 i = 0;
    for (; i < WC_TZ_COUNT; i++)
    {
        if (currTZ == ValidTZ[i])
        {
            break;
        }
    }
    if (i == WC_TZ_COUNT - 1)
    {
        return ValidTZ[0];
    }
    else
    {
        return ValidTZ[i + 1];
    }
}

FLOAT mmi_wc_get_prev_time_zone(FLOAT currTZ)
{
    U32 i = 0;
    for (; i < WC_TZ_COUNT; i++)
    {
        if (currTZ == ValidTZ[i])
        {
            break;
        }
    }
    if (i == 0)
    {
        return ValidTZ[WC_TZ_COUNT - 1];
    }
    else
    {
        return ValidTZ[i - 1];
    }
}
#endif
U16 mmi_wc_get_city_strid(U16 cityIndex)
{
	return TimeZoneData2[cityIndex].CityName;
}

WCCityPosition mmi_wc_get_city_pos(U16 cityIndex)
{
    WCCityPosition cityPos;
    cityPos.pos_x = TimeZoneData2[cityIndex].CityPosX;
    cityPos.pos_y = TimeZoneData2[cityIndex].CityPosY;
    return cityPos;
}

U8 mmi_wc_get_home_dst(void)
{
    return wc_cntx.DSTHome;
}

U8 mmi_wc_get_frn_dst(U8 cityOrder)
{
    MMI_ASSERT(cityOrder < WC_FRN_CITY_NUM);
    return wc_cntx.DSTForeign[cityOrder];
}

void srv_wc_save_home_dst(U8 homeDst)
{

	U32 i;

	mmi_wc_save_home_dst(homeDst);
	for (i = 0; i < WC_FRN_CITY_NUM; i++)
	{
		if (mmi_wc_get_home_index() == mmi_wc_get_frn_index(i))
		{
			mmi_wc_save_frn_dst(wc_cntx.DSTHome, i);
		}
	}	


}

void mmi_wc_save_home_dst(U8 homeDst)
{
    S16 error;
	
    homeDst = homeDst > 0 ? 1 : 0;
    wc_cntx.DSTHome = homeDst;
    WriteValue(NVRAM_WC_HOME_DST, &homeDst, DS_BYTE, &error);
#ifdef __MMI_TDL_NITZ_SUPPORT__
	srv_tdl_init();
#endif
}

void mmi_wc_save_frn_dst(U8 frnDst, U8 cityOrder)
{
    S16 error;
    MMI_ASSERT(cityOrder < WC_FRN_CITY_NUM);
    frnDst = frnDst > 0 ? 1 : 0;
    wc_cntx.DSTForeign[cityOrder] = frnDst;
    WriteRecord(NVRAM_EF_SRV_WC_FRN_DST, (U16)cityOrder + 1, &frnDst, sizeof(U8), &error);
}

void mmi_wc_update_sys_datetime(U16 newCityIndex, S16 dstFlag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    U16 oldIndex;
    FLOAT oldTimeZone, newTimeZone;
    S16 error;
    applib_time_struct sys_time;
    applib_time_struct tz_diff_mytime;
    applib_time_struct currTime;
    applib_time_struct dst_mytime;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    memset(&sys_time, 0, sizeof(applib_time_struct));
    memset(&tz_diff_mytime, 0, sizeof(applib_time_struct));
    memset(&currTime, 0, sizeof(applib_time_struct));
    memset(&dst_mytime, 0, sizeof(applib_time_struct));
    dst_mytime.nHour = 1;
    ReadValue(NVRAM_WC_HOME_CITY, &oldIndex, DS_SHORT, &error);
    oldTimeZone = mmi_wc_get_time_zone(oldIndex);
    newTimeZone = mmi_wc_get_time_zone(newCityIndex);
    applib_dt_get_rtc_time(&sys_time);
    if (newTimeZone >= oldTimeZone)
    {
        tz_diff_mytime = applib_conv_tz_to_mytime(newTimeZone - oldTimeZone);
        applib_dt_increase_time(&sys_time, &tz_diff_mytime, &sys_time);
    }
    else if (newTimeZone < oldTimeZone)
    {
        tz_diff_mytime = applib_conv_tz_to_mytime(oldTimeZone - newTimeZone);
        applib_dt_decrease_time(&sys_time, &tz_diff_mytime, &sys_time);
    }
    if (dstFlag == -1)
    {       
        applib_dt_decrease_time(&sys_time, &dst_mytime, &sys_time);
    }
    else if (dstFlag == 1)
    {
        applib_dt_increase_time(&sys_time, &dst_mytime, &sys_time);
    }        
    
    if (applib_dt_is_valid(&sys_time))
    {
        mmi_dt_set_dt((MYTIME*)&sys_time, NULL, NULL);
    }
}


#ifdef __MMI_NITZ_TZ_SUPPORT__


MMI_BOOL mmi_wc_set_home_timezone(FLOAT timeZone)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 default_city_count = 0;
    U32 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	default_city_count = mmi_wc_get_default_city_size2();

	/* search default city index and set to default city index */
	for (i = 0; i < default_city_count; i++)
	{
		if ((DefaultCityData2[i].CityTimeZone == timeZone) 
            && (mmi_wc_get_time_zone(mmi_wc_get_home_index()) != timeZone)
			&& DefaultCityData2[i].CityIndex)
		{
			mmi_wc_save_home_city(DefaultCityData2[i].CityIndex);
			return MMI_TRUE;
		}
	}

    for (i = 0; i < WC_TZ_COUNT; i++)
    {
        if (timeZone == ValidTZ[i])
        {
            if (mmi_wc_get_time_zone(mmi_wc_get_home_index())!= timeZone)
            {
                U16 searchResult[WC_SAME_TZ_CITY_NUM];
                U16 cityCount = mmi_wc_search_bytz(timeZone, searchResult);
                for (j = 0; j < cityCount ; j++)
                {
                    if (searchResult[j] != mmi_wc_get_home_index())
                    {
                        mmi_wc_save_home_city(searchResult[j]);
			            return MMI_TRUE;
                    }
                }
            }
            break;
        }
    }
    return MMI_FALSE;
}
#endif
