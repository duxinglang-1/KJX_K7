#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_CLOCK" 
     package_name="native.mtk.clock" 
     name="STR_ID_VAPP_CLOCK" 
     img="IMG_ID_VAPP_CLOCK" 
     launch="vapp_clock_launch" type="venus">

    <MEMORY heap = "300*1024"
    		cui = "VCUI_TONE_SELECTOR"
    		vrt_mem_factor = "3.0" />

    <LAYOUT file="vapp_alarm.xml" />
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    // Clock
    <IMAGE id="IMG_ID_VAPP_CLOCK" desc="Main menu icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\clock.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CLOCK_ICON_ALARM">RES_IMG_ROOT"\\\\Clock\\\\alarm.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CLOCK_ICON_WORLDCLOCK">RES_IMG_ROOT"\\\\Clock\\\\worldclock.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CLOCK_ICON_STOPWATCH">RES_IMG_ROOT"\\\\Clock\\\\stopwatch.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CLOCK_ICON_TIMER">RES_IMG_ROOT"\\\\Clock\\\\timer.png"</IMAGE>
    // Alarm
    #define ALARM_PATH 			 RES_IMG_ROOT"\\\\Alarm\\\\"
		#define ALARM_DCLOCK_PATH ALARM_PATH"ClockDay\\\\"
		#define ALARM_NCLOCK_PATH ALARM_PATH"ClockNight\\\\"
    #define ALARM_THEME_PATH RES_THEME_ROOT"\\\\Theme1\\\\Alarm\\\\"
    #define ALARM_IND_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Popup\\\\"
    
    #ifndef __MMI_ALARM_SLIM__ 
    <IMAGE id="IMG_ID_VAPP_ALARM_STATUS_ICON">RES_IMG_ROOT"\\\\StatusIcon\\\\Alarm.png"</IMAGE>
    //<IMAGE id="IMG_ID_VAPP_ALARM_BG">ALARM_THEME_PATH"Alarm_BG.9slice.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_ALARM_IND_ON_SCRLK_BG">ALARM_PATH"Alarm.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_ALARM_DCLOCK_CIRCLE">ALARM_DCLOCK_PATH"Circle.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_ALARM_DCLOCK_BG">ALARM_DCLOCK_PATH"Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_ALARM_DCLOCK_HOUR">ALARM_DCLOCK_PATH"Hour.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_ALARM_DCLOCK_MINUTE">ALARM_DCLOCK_PATH"Minute.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_ALARM_DCLOCK_SECOND">ALARM_DCLOCK_PATH"Second.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_ALARM_NCLOCK_CIRCLE">ALARM_NCLOCK_PATH"Circle.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_ALARM_NCLOCK_BG">ALARM_NCLOCK_PATH"Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_ALARM_NCLOCK_HOUR">ALARM_NCLOCK_PATH"Hour.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_ALARM_NCLOCK_MINUTE">ALARM_NCLOCK_PATH"Minute.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_ALARM_NCLOCK_SECOND">ALARM_NCLOCK_PATH"Second.png"</IMAGE>
    #endif
    
    // WorldClock
    <IMAGE id="IMG_ID_VAPP_WC_BG">RES_IMG_ROOT"\\\\WorldClock\\\\bg.jpg"</IMAGE>
    
    //<IMAGE id="IMG_ID_VAPP_WC_MAP">RES_IMG_ROOT"\\\\WorldClock\\\\map.png"</IMAGE>
#ifdef __VENUS_3D_UI_ENGINE__    
    <IMAGE id="IMG_ID_VAPP_WC_MAP">RES_IMG_ROOT"\\\\WorldClock\\\\map.ktx"</IMAGE>
#else
    <IMAGE id="IMG_ID_VAPP_WC_MAP">RES_IMG_ROOT"\\\\WorldClock\\\\map.png"</IMAGE>
#endif    
#ifndef __LOW_COST_SUPPORT_COMMON__
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
#endif    
#if 0
    <IMAGE id="IMG_ID_VAPP_WC_BUBBLE_BG">RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Popup\\\\Pop_Comfirm_BG.9slice.png"</IMAGE>
#endif
#ifdef __LOW_COST_SUPPORT_COMMON__
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
#endif
#ifndef __MMI_WORLDCLOCK_SLIM__    
    <IMAGE id="IMG_ID_VAPP_WC_LIST_HOME_BG">RES_IMG_ROOT"\\\\WorldClock\\\\BG_H.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_LIST_FRN_BG">RES_IMG_ROOT"\\\\WorldClock\\\\BG_N.9slice.png"</IMAGE>
#else
	  <IMAGE id="IMG_ID_VAPP_WC_LIST_FRN_BG">RES_IMG_ROOT"\\\\Redesign\\\\WorldClock\\\\bg.9slice.png"</IMAGE>
#endif
#ifndef __MMI_WORLDCLOCK_SLIM__ 	       
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_H">RES_IMG_ROOT"\\\\WorldClock\\\\Clock\\\\Clock_Hour.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_M">RES_IMG_ROOT"\\\\WorldClock\\\\Clock\\\\Clock_Minute.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_S">RES_IMG_ROOT"\\\\WorldClock\\\\Clock\\\\Clock_Second.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_BG">RES_IMG_ROOT"\\\\WorldClock\\\\Clock\\\\Clock_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_ACLOCK_C">RES_IMG_ROOT"\\\\WorldClock\\\\Clock\\\\Circle.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WC_HOME_ICON">RES_IMG_ROOT"\\\\WorldClock\\\\icon_home.png"</IMAGE>
#else
	  <IMAGE id="IMG_ID_VAPP_WC_HOME_ICON">RES_IMG_ROOT"\\\\Redesign\\\\WorldClock\\\\icon_home.png"</IMAGE>
#endif    
    
		<!-----------------------------------------------------String Resource Area------------------------------------------------------>    
    // Alarm
    #ifndef __MMI_ALARM_SLIM__ 
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_FOR_3MIN">"Snooze(3 mins)"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_FOR_5MIN">"Snooze(5 mins)"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_FOR_10MIN">"Snooze(10 mins)"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_FOR_15MIN">"Snooze(15 mins)"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZING_FOR_3MIN">"Snoozing for 3 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZING_FOR_10MIN">"Snoozing for 10 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZING_FOR_15MIN">"Snoozing for 15 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_3MIN">"3 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_5MIN">"5 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_10MIN">"10 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_15MIN">"15 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SETTINGS">"Settings"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_NO_ALARM_SET">"No alarm set"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_FOR">"Snoozing for "</STRING>
    #endif
    
    <STRING id="STR_ID_VAPP_ALARM">"Alarm"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_NO_ALARMS">"No alarms"</STRING>
 
    <STRING id="STR_ID_VAPP_ALARM_NEXT_ALARM">"Next alarm"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_MAX_NUMBER">"Maximum number reached"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_ALARM_OPTIONS">"Alarm options"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_DELETE_ASK">"Delete the alarm?"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SET_ALARM">"Set alarm"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_REPEAT">"Repetition"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_RINGTONE">"Ringtone"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_VIBRATE">"Vibrate"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE">"Snooze"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_LABEL">"Label"</STRING>

    <STRING id="STR_ID_VAPP_ALARM_DISMISS">"Dismiss"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_MOVE_UP_DISMISS">"Move up to dismiss"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_MOVE_DOWN_SNOOZE">"Move down to snooze"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZING_FOR_5MIN">"Snoozing for 5 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_SUN">"Sunday"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_MON">"Monday"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_TUE">"Tuesday"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_WED">"Wednesday"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_THU">"Thursday"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_FRI">"Friday"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_SAT">"Saturday"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_SHORT_SUN">"Sun"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_SHORT_MON">"Mon"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_SHORT_TUE">"Tue"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_SHORT_WED">"Wed"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_SHORT_THU">"Thu"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_SHORT_FRI">"Fri"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_WDAY_SHORT_SAT">"Sat"</STRING> 
    <STRING id="STR_ID_VAPP_ALARM_REPEAT_ONCE">"Once"</STRING> 
    <STRING id="STR_ID_VAPP_ALARM_COMMA">","</STRING> 
    <STRING id="STR_ID_VAPP_ALARM_L_BRACKET">"("</STRING> 
    <STRING id="STR_ID_VAPP_ALARM_R_BRACKET">")"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_DELETE_SELECTED">"Delete selected alarms"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_DELETE_ONE_SELECTED">"Delete selected alarm"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_QUESTION_MARK">"?"</STRING> 
    <STRING id="STR_ID_VAPP_ALARM_MARK_ALL">"Mark all"</STRING> 
    <STRING id="STR_ID_VAPP_ALARM_UNMARK_ALL">"Unmark all"</STRING> 
    
    // WorldClock
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
#if 0    
    <STRING id="STR_ID_VAPP_WC_HOMECICY_TITLE"/>
#endif    
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
    <STRING id="STR_ID_VAPP_WC_NOCITY"/>
    // Stopwatch
    <STRING id="STR_ID_VAPP_STOPWATCH_START">"Start"</STRING>
    <STRING id="STR_ID_VAPP_STOPWATCH_RESET">"Reset"</STRING>
    <STRING id="STR_ID_VAPP_STOPWATCH_CONTINUE">"Continue"</STRING>
    <STRING id="STR_ID_VAPP_STOPWATCH_STOP">"Pause"</STRING>
    <STRING id="STR_ID_VAPP_STOPWATCH_LAP">"Lap"</STRING>
    <STRING id="STR_ID_VAPP_STOPWATCH">"stopwatch"</STRING>
    <STRING id="STR_ID_VAPP_STOPWATCH_FASTEST">"The Fastest"</STRING>
    <STRING id="STR_ID_VAPP_STOPWATCH_SLOWEST">"The Slowest"</STRING>
    <STRING id="STR_ID_VAPP_STOPWATCH_NC_CLOSE">"Close Stopwatch ?"</STRING>
    // Timer
    <STRING id="STR_ID_VAPP_TIMER_OK">"OK"</STRING>
    <STRING id="STR_ID_VAPP_TIMER">"Timer"</STRING>
    <STRING id="STR_ID_VAPP_TIMER_CANCEL">"Cancel"</STRING>
    <STRING id="STR_ID_VAPP_TIMER_SET">"set time"</STRING>
    <STRING id="STR_ID_VAPP_TIMER_HOUR">"Hour"</STRING>
    <STRING id="STR_ID_VAPP_TIMER_MINUTE">"Minute"</STRING>
    <STRING id="STR_ID_VAPP_TIMER_SECOND">"Second"</STRING>
    <STRING id="STR_ID_VAPP_TIMER_NC_CLOSE">"Close Timer ?"</STRING>
    // Timer indication
    <STRING id="STR_ID_VAPP_TIMER_IND_TIME_OUT">"Time out"</STRING>
    <!-----------------------------------------------------Timer Area------------------------------------------------------> 
    // Stopwatch
    <TIMER id="MMI_STOPWATCH_TIMER"/>
    <TIMER id="MMI_TIMER_TIMER"/>
    <TIMER id="MMI_TIMER_AUTO_STOP_RING"/>
    <!-----------------------------------------------------CatheData Area------------------------------------------------------>
    // Alarm
    <CACHEDATA type="byte" id="NVRAM_ALARM_SETTINGS_SNOOZE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION>Alarm setting snooze list</DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_ALARM_SETTINGS_VOL">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>alarm setting vol level</DESCRIPTION>
    </CACHEDATA> 
    
    // WorldClock
    <CACHEDATA type="short" id="NVRAM_WC_HOME_CITY" restore_flag="TRUE">
    <DEFAULT_VALUE> [0x00,0x00] </DEFAULT_VALUE>
    <DESCRIPTION>home city index</DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_WC_HOME_DST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION>home city dst</DESCRIPTION>
    </CACHEDATA>
    <!---------------------------------------------------------SENDER Area------------------------------------------------------>
    <EVENT id="EVT_ID_VAPP_CLOCK_STOPWATCH_BG_RUN_START" type="SENDER"/>
    <EVENT id="EVT_ID_VAPP_CLOCK_STOPWATCH_BG_RUN_END" type="SENDER"/>
    <EVENT id="EVT_ID_VAPP_CLOCK_TIMER_BG_RUN_START" type="SENDER"/>
    <EVENT id="EVT_ID_VAPP_CLOCK_TIMER_BG_RUN_END" type="SENDER"/>
    <EVENT id="EVT_ID_VAPP_TIMER_IND_RESET" type="SENDER"/>
    <!---------------------------------------------------------RECEIVER Area------------------------------------------------------>
    // Stopwatch
    <RECEIVER id="EVT_ID_VAPP_CLOCK_STOPWATCH_BG_RUN_START" proc="vapp_stopwatch_update_ncell"/>
    <RECEIVER id="EVT_ID_VAPP_CLOCK_STOPWATCH_BG_RUN_END" proc="vapp_stopwatch_update_ncell"/>
    <RECEIVER id="EVT_ID_VAPP_CLOCK_TIMER_BG_RUN_START" proc="vapp_timer_update_ncell"/>
    <RECEIVER id="EVT_ID_VAPP_CLOCK_TIMER_BG_RUN_END" proc="vapp_timer_update_ncell"/>
    <RECEIVER id="EVT_ID_VAPP_TIMER_IND_RESET" proc="vapp_timer_proc"/>
		// WorldClock
		<RECEIVER id="EVT_ID_VAPP_LANGUAGE_CHANGED" proc="vapp_worldclock_evt_handlr"/>
		// Alarm
		<RECEIVER id="EVT_ID_SRV_REMINDER_PWRRESET_REQ" proc="vapp_alarm_evt_handlr"/>
    <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="vapp_alarm_evt_handlr"/>
    <RECEIVER id="EVT_ID_SRV_REMINDER_BOOTUP_START" proc="vapp_alarm_bootup_start"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="vapp_alarm_evt_handlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="vapp_alarm_evt_handlr"/>
    
    <THEME>
    // WorldClock
        <IMAGE id="IMG_ID_VAPP_WORLDCLOCK" desc="Main menu world clock icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\WorldClock.png"</IMAGE>    
    // Alarm    
        <IMAGE id="IMG_ID_VAPP_ALARM" desc="Main menu alarm icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Alarm.png"</IMAGE>  
    	  <IMAGE id="IMG_ID_VAPP_ALARM_BG" desc="the bg image for recent alarm"></IMAGE>
	      <COLOR id="VAPP_ALARM_SUB_COLOR" desc="color of cell having event"/>
    </THEME>
</APP>
