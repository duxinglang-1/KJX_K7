#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WORLDCLOCK"
     package_name="native.mtk.worldclock"
		name="STR_ID_VAPP_WORLDCLOCK"
		img="IMG_ID_VAPP_WORLDCLOCK"
     launch="vapp_world_clock_launch" type="venus">
#ifdef __COSMOS_3D_V10__
    <MEMORY heap="309600" vrt_mem_factor="2.8f"/>
#elif __LOW_COST_SUPPORT_COMMON__
    <MEMORY heap="309600" vrt_mem_factor = "2.0f"/>
#else
    <MEMORY heap="309600"/>
#endif
    <CACHEDATA type="short" id="NVRAM_WC_HOME_CITY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00,0x00] </DEFAULT_VALUE>
        <DESCRIPTION>home city index</DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_WC_HOME_DST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION>home city dst</DESCRIPTION>
    </CACHEDATA>
    	<STRING id="STR_WORLDCLOCK_CITY_NONE"/>
    <STRING id="STR_WORLDCLOCK_CITY1"/>
    <STRING id="STR_WORLDCLOCK_CITY2"/>
    <STRING id="STR_WORLDCLOCK_CITY3"/>
    <STRING id="STR_WORLDCLOCK_CITY4"/>
    <STRING id="STR_WORLDCLOCK_CITY5"/>
    <STRING id="STR_WORLDCLOCK_CITY6"/>
    <STRING id="STR_WORLDCLOCK_CITY7"/>
    <STRING id="STR_WORLDCLOCK_CITY8"/>
    <STRING id="STR_WORLDCLOCK_CITY9"/>
    <STRING id="STR_WORLDCLOCK_CITY10"/>
    <STRING id="STR_WORLDCLOCK_CITY11"/>
    <STRING id="STR_WORLDCLOCK_CITY12"/>
    <STRING id="STR_WORLDCLOCK_CITY13"/>
    <STRING id="STR_WORLDCLOCK_CITY14"/>
    <STRING id="STR_WORLDCLOCK_CITY15"/>
    <STRING id="STR_WORLDCLOCK_CITY16"/>
    <STRING id="STR_WORLDCLOCK_CITY17"/>
    <STRING id="STR_WORLDCLOCK_CITY18"/>
    <STRING id="STR_WORLDCLOCK_CITY19"/>
    <STRING id="STR_WORLDCLOCK_CITY20"/>
    <STRING id="STR_WORLDCLOCK_CITY21"/>
    <STRING id="STR_WORLDCLOCK_CITY22"/>
    <STRING id="STR_WORLDCLOCK_CITY23"/>
    <STRING id="STR_WORLDCLOCK_CITY24"/>
    <STRING id="STR_WORLDCLOCK_CITY25"/>
    <STRING id="STR_WORLDCLOCK_CITY26"/>
    <STRING id="STR_WORLDCLOCK_CITY27"/>
    <STRING id="STR_WORLDCLOCK_CITY28"/>
    <STRING id="STR_WORLDCLOCK_CITY29"/>
    <STRING id="STR_WORLDCLOCK_CITY30"/>
    <STRING id="STR_WORLDCLOCK_CITY31"/>
    <STRING id="STR_WORLDCLOCK_CITY32"/>
    <STRING id="STR_WORLDCLOCK_CITY33"/>
    <STRING id="STR_WORLDCLOCK_CITY34"/>
    <STRING id="STR_WORLDCLOCK_CITY35"/>
    <STRING id="STR_WORLDCLOCK_CITY36"/>
    <STRING id="STR_WORLDCLOCK_CITY37"/>
    <STRING id="STR_WORLDCLOCK_CITY38"/>
    <STRING id="STR_WORLDCLOCK_CITY39"/>
    <STRING id="STR_WORLDCLOCK_CITY40"/>
    <STRING id="STR_WORLDCLOCK_CITY41"/>
    <STRING id="STR_WORLDCLOCK_CITY42"/>
    <STRING id="STR_WORLDCLOCK_CITY43"/>
    <STRING id="STR_WORLDCLOCK_CITY44"/>
    <STRING id="STR_WORLDCLOCK_CITY45"/>
    <STRING id="STR_WORLDCLOCK_CITY46"/>
    <STRING id="STR_WORLDCLOCK_CITY47"/>
    <STRING id="STR_WORLDCLOCK_CITY48"/>
    <STRING id="STR_WORLDCLOCK_CITY49"/>
    <STRING id="STR_WORLDCLOCK_CITY50"/>
    <STRING id="STR_WORLDCLOCK_CITY51"/>
    <STRING id="STR_WORLDCLOCK_CITY52"/>
    <STRING id="STR_WORLDCLOCK_CITY53"/>
    <STRING id="STR_WORLDCLOCK_CITY54"/>
    <STRING id="STR_WORLDCLOCK_CITY55"/>
    <STRING id="STR_WORLDCLOCK_CITY56"/>
    <STRING id="STR_WORLDCLOCK_CITY57"/>
    <STRING id="STR_WORLDCLOCK_CITY58"/>
    <STRING id="STR_WORLDCLOCK_CITY59"/>
    <STRING id="STR_WORLDCLOCK_CITY60"/>
    <STRING id="STR_WORLDCLOCK_CITY61"/>
    <STRING id="STR_WORLDCLOCK_CITY62"/>
    <STRING id="STR_WORLDCLOCK_CITY63"/>
    <STRING id="STR_WORLDCLOCK_CITY64"/>
    <STRING id="STR_WORLDCLOCK_CITY65"/>
    <STRING id="STR_WORLDCLOCK_CITY66"/>
    <STRING id="STR_WORLDCLOCK_CITY67"/>
    <STRING id="STR_WORLDCLOCK_CITY68"/>
    <STRING id="STR_WORLDCLOCK_CITY69"/>
    <STRING id="STR_WORLDCLOCK_CITY70"/>
    <STRING id="STR_WORLDCLOCK_CITY71"/>
    <STRING id="STR_WORLDCLOCK_CITY72"/>
    <STRING id="STR_WORLDCLOCK_CITY73"/>
    <STRING id="STR_WORLDCLOCK_CITY74"/>
    <STRING id="STR_WORLDCLOCK_CITY75"/>
    <STRING id="STR_WORLDCLOCK_CITY76"/>
    <STRING id="STR_WORLDCLOCK_CITY77"/>
    <STRING id="STR_CITY_TOTAL_NUM"/>
    <STRING id="STR_ID_VAPP_WORLDCLOCK"/>    
    <STRING id="STR_ID_VAPP_WC_HOMECICY"/>
    <STRING id="STR_ID_VAPP_WC_GMT"/>
    <STRING id="STR_ID_VAPP_WC_ADDCICY"/>
    <STRING id="STR_ID_VAPP_WC_REPLACE_CICY"/>
    <STRING id="STR_ID_VAPP_WC_DST_ACT"/>
    <STRING id="STR_ID_VAPP_WC_DST_DISABLE"/>
    <STRING id="STR_ID_VAPP_WC_HOMECICY_TITLE"/>
    <STRING id="STR_ID_VAPP_WC_HOMECICY_MENU"/>
    <STRING id="STR_ID_VAPP_WC_DST_POP_ACT"/>
    <STRING id="STR_ID_VAPP_WC_DST_POP_INACT"/>
    <STRING id="STR_ID_VAPP_WC_HOMECICY_CHANGE_POP"/>
    <STRING id="STR_ID_VAPP_WC_DEL_WARNING"/>
    <STRING id="STR_ID_VAPP_WC_CITY_VIEW"/>
    <STRING id="STR_ID_VAPP_WC_HOME_OPTION"/>
    <STRING id="STR_ID_VAPP_WC_FOREIGN_OPTION"/>
    <STRING id="STR_ID_VAPP_WC_NO_MATCHED_CITY"/>
    <STRING id="STR_ID_VAPP_WC_CITY_FULL"/>
    <STRING id="STR_ID_VAPP_WC_CITY_EXIST"/>
    <STRING id="STR_ID_VAPP_WC_DATE_TODAY"/>
    <STRING id="STR_ID_VAPP_WC_DATE_YESTERDAY"/>
    <STRING id="STR_ID_VAPP_WC_DATE_TOMORROW"/>

    <THEME>
        <IMAGE id="IMG_ID_VAPP_WORLDCLOCK" desc="Main menu world clock icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\WorldClock.png"</IMAGE>    
    </THEME>

    <IMAGE id="IMG_ID_VAPP_WC_BG">RES_IMG_ROOT"\\\\WorldClock\\\\bg.jpg"</IMAGE>
    
    //<IMAGE id="IMG_ID_VAPP_WC_MAP">RES_IMG_ROOT"\\\\WorldClock\\\\map.png"</IMAGE>
#ifdef __VENUS_3D_UI_ENGINE__    
    <IMAGE id="IMG_ID_VAPP_WC_MAP">RES_IMG_ROOT"\\\\WorldClock\\\\map.ktx"</IMAGE>
#else
    <IMAGE id="IMG_ID_VAPP_WC_MAP">RES_IMG_ROOT"\\\\WorldClock\\\\map.png"</IMAGE>
#endif    

    <IMAGE id="IMG_ID_VAPP_WC_MAP_SHADOW">RES_IMG_ROOT"\\\\WorldClock\\\\shadow_map.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_HOME_BG">RES_IMG_ROOT"\\\\WorldClock\\\\bg_home.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_FOREIGN_BG">RES_IMG_ROOT"\\\\WorldClock\\\\bg_city.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_SHADOW_L">RES_IMG_ROOT"\\\\WorldClock\\\\shadow_tz_l.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_SHADOW_R">RES_IMG_ROOT"\\\\WorldClock\\\\shadow_tz_r.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_LIGHTSPOT_HOME">RES_IMG_ROOT"\\\\WorldClock\\\\dot_home.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_LIGHTSPOT_FRN">RES_IMG_ROOT"\\\\WorldClock\\\\dot_city.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_LIGHTSPOT_NOR">RES_IMG_ROOT"\\\\WorldClock\\\\dot_mapcity.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_HOMECITY_ICON">RES_IMG_ROOT"\\\\WorldClock\\\\icon_home.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_BACKBUTTON">RES_IMG_ROOT"\\\\WorldClock\\\\btn_back.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_LISTBUTTON">RES_IMG_ROOT"\\\\WorldClock\\\\btn_list.png"</IMAGE>
#if 0
    <IMAGE id="IMG_ID_VAPP_WC_BUBBLE_BG">RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Popup\\\\Pop_Comfirm_BG.9slice.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_NIGHT_H">RES_IMG_ROOT"\\\\WorldClock\\\\ClockNight\\\\Hour.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_NIGHT_M">RES_IMG_ROOT"\\\\WorldClock\\\\ClockNight\\\\Minute.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_NIGHT_S">RES_IMG_ROOT"\\\\WorldClock\\\\ClockNight\\\\Second.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_NIGHT_BG">RES_IMG_ROOT"\\\\WorldClock\\\\ClockNight\\\\Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_NIGHT_C">RES_IMG_ROOT"\\\\WorldClock\\\\ClockNight\\\\Circle.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_DAY_H">RES_IMG_ROOT"\\\\WorldClock\\\\ClockDay\\\\Hour.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_DAY_M">RES_IMG_ROOT"\\\\WorldClock\\\\ClockDay\\\\Minute.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_DAY_S">RES_IMG_ROOT"\\\\WorldClock\\\\ClockDay\\\\Second.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_DAY_BG">RES_IMG_ROOT"\\\\WorldClock\\\\ClockDay\\\\Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_DAY_C">RES_IMG_ROOT"\\\\WorldClock\\\\ClockDay\\\\Circle.png"</IMAGE>
  
    <IMAGE id="IMG_ID_VAPP_WC_LIST_HOME_BG">RES_IMG_ROOT"\\\\WorldClock\\\\BG_H.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_LIST_FRN_BG">RES_IMG_ROOT"\\\\WorldClock\\\\BG_N.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_H">RES_IMG_ROOT"\\\\WorldClock\\\\Clock\\\\Clock_Hour.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_M">RES_IMG_ROOT"\\\\WorldClock\\\\Clock\\\\Clock_Minute.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_S">RES_IMG_ROOT"\\\\WorldClock\\\\Clock\\\\Clock_Second.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_BG">RES_IMG_ROOT"\\\\WorldClock\\\\Clock\\\\Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_C">RES_IMG_ROOT"\\\\WorldClock\\\\Clock\\\\Circle.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_HOME_ICON">RES_IMG_ROOT"\\\\WorldClock\\\\icon_home.png"</IMAGE>
  
		<RECEIVER id="EVT_ID_VAPP_LANGUAGE_CHANGED" proc="vapp_worldclock_evt_handlr"/>
    
</APP>
