#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_ALARM" 
     package_name="native.mtk.alarm" 
     name="STR_ID_VAPP_ALARM" 
     img="IMG_ID_VAPP_ALARM" 
     launch="vapp_alarm_launch" type="venus">

    <MEMORY heap = "300*1024"
    		cui = "VCUI_TONE_SELECTOR"
    		vrt_mem_factor = "2.0" />

    <LAYOUT file="vapp_alarm.xml" />
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ALARM_PATH 			 RES_IMG_ROOT"\\\\Alarm\\\\"
		#define ALARM_DCLOCK_PATH ALARM_PATH"ClockDay\\\\"
		#define ALARM_NCLOCK_PATH ALARM_PATH"ClockNight\\\\"
    #define ALARM_THEME_PATH RES_THEME_ROOT"\\\\Theme1\\\\Alarm\\\\"
    #define ALARM_IND_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Popup\\\\"
    
    
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
    
    
    <STRING id="STR_ID_VAPP_ALARM">"Alarm"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_NO_ALARMS">"No alarms"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_NO_ALARM_SET">"No alarm set"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_NEXT_ALARM">"Next alarm"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SETTINGS">"Settings"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_MAX_NUMBER">"Maximum number reached"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_ALARM_OPTIONS">"Alarm options"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_DELETE_ASK">"Delete the alarm?"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SET_ALARM">"Set alarm"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_REPEAT">"Repetition"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_RINGTONE">"Ringtone"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_VIBRATE">"Vibrate"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE">"Snooze"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_LABEL">"Label"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_FOR">"Snoozing for "</STRING>
    <STRING id="STR_ID_VAPP_ALARM_DISMISS">"Dismiss"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_MOVE_UP_DISMISS">"Move up to dismiss"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_MOVE_DOWN_SNOOZE">"Move down to snooze"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_3MIN">"3 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_5MIN">"5 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_10MIN">"10 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_15MIN">"15 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_FOR_3MIN">"Snooze(3 mins)"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_FOR_5MIN">"Snooze(5 mins)"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_FOR_10MIN">"Snooze(10 mins)"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZE_FOR_15MIN">"Snooze(15 mins)"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZING_FOR_3MIN">"Snoozing for 3 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZING_FOR_5MIN">"Snoozing for 5 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZING_FOR_10MIN">"Snoozing for 10 minutes"</STRING>
    <STRING id="STR_ID_VAPP_ALARM_SNOOZING_FOR_15MIN">"Snoozing for 15 minutes"</STRING>
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
    
    <RECEIVER id="EVT_ID_SRV_REMINDER_PWRRESET_REQ" proc="vapp_alarm_evt_handlr"/>
    <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="vapp_alarm_evt_handlr"/>
    <RECEIVER id="EVT_ID_SRV_REMINDER_BOOTUP_START" proc="vapp_alarm_bootup_start"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="vapp_alarm_evt_handlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="vapp_alarm_evt_handlr"/>
    
    <CACHEDATA type="byte" id="NVRAM_ALARM_SETTINGS_SNOOZE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION>Alarm setting snooze list</DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_ALARM_SETTINGS_VOL">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>alarm setting vol level</DESCRIPTION>
    </CACHEDATA> 
    
    <THEME>
        <IMAGE id="IMG_ID_VAPP_ALARM" desc="Main menu alarm icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Alarm.png"</IMAGE>  
    	<IMAGE id="IMG_ID_VAPP_ALARM_BG" desc="the bg image for recent alarm"></IMAGE>
	<COLOR id="VAPP_ALARM_SUB_COLOR" desc="color of cell having event"/>
    </THEME>
</APP>
