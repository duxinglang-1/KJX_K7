# 1 "temp/res/Alarm.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/Alarm.c"
# 55 "temp/res/Alarm.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 56 "temp/res/Alarm.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 57 "temp/res/Alarm.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_ALARM"
# 71 "temp/res/Alarm.c"
>


    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="GlobalMenuItems.h"/>
    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>

    <TIMER id="ALARM_ALERT_NOTIFYDURATION_TIMER"/>
    <TIMER id="ALARM_TIMER_WAIT_FOR_CALL"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="ALARMS_SNOOZE_STRINGID"/>
    <STRING id="ALARM_REPEAT_STRING"/>
    <STRING id="ALARM_ONCE_STRING"/>
    <STRING id="ALARM_HOURLY_STRING"/>
    <STRING id="ALARM_EVREYDAY_STRING"/>
    <STRING id="ALARM_DAYS_STRING"/>
    <STRING id="ALARM_WEEKLY_STRING"/>
    <STRING id="ALARM_MONTHLY_STRING"/>
    <STRING id="ALARM_SEASONLY_STRING"/>
    <STRING id="ALARM_YEARLY_STRING"/>
    <STRING id="ALARM_TITHI_STRING"/>
    <STRING id="ALARMS_POWER_ON"/>
# 110 "temp/res/Alarm.c"
    <STRING id="ALARMS_SETTING_SNOOZE_INTERVAL"/>
    <STRING id="STR_ID_ALM_DISABLE_ASK"/>
    <STRING id="STR_ID_ALM_NO_MARKED"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

    <IMAGE id="ALARMS_EDIT_SOFTKEY_IMAGEID" >"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\EmptyImage.bmp"</IMAGE>

    <IMAGE id="ALARM_ANIMATION_INDICATION_IMAGEID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MAINLCD\\\\Alarm\\\\ALARM.png"</IMAGE>







    <IMAGE id="ORGANIZER_MENU_ALARMS_IMAGEID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Submenu\\\\Alarm\\\\SB_OAM.bmp"</IMAGE>
# 137 "temp/res/Alarm.c"
    <IMAGE id="ALARMS_SET_ALERT_TYPE_IMAGEID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Submenu\\\\Alarm\\\\SB_alert.bmp"</IMAGE>





    <!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
    <SCREEN id="SCR_ID_ALM_LIST"/>
    <SCREEN id="SCR_ID_ALM_SAVE_CONFIRM"/>
    <SCREEN id="SCR_ID_ALM_INDICATION"/>
    <SCREEN id="SCR_ID_ALM_PWRON_CONFIRM"/>
    <SCREEN id="SCR_ID_ALM_EDITOR"/>
    <SCREEN id="SCR_ID_ALM_AUDIO_OPT_FMRADIO"/>
    <SCREEN id="SCR_ID_ALM_AUDIO_OPT_FMRADIO_CHANNEL_LIST"/>
    <SCREEN id="SCR_ID_ALM_AUDIO_OPT_FMRDO_CHANNEL_OPT"/>
    <SCREEN id="SCR_ID_ALM_FMRDO_PREV"/>
    <SCREEN id="SCR_ID_ALM_FMRDO_MANUAL_INPUT"/>
    <SCREEN id="SCR_ID_ALM_FMRDO_MANUAL_INPUT_OPT"/>
    <SCREEN id="SCR_ID_ALM_TONE_SETUP"/>
    <SCREEN id="SCR_ID_ALM_TONE_SETUP_EXT_MELODY"/>
    <SCREEN id="SCR_ID_ALM_TONE_SETUP_EXT_MELODY_DRV"/>
    <SCREEN id="SCR_ID_ALM_SETTING"/>
    <SCREEN id="SCR_ID_ALM_CUSTOM_REPEAT_TYPE"/>
    <SCREEN id="SCR_ID_ALM_TOTAL"/>
    <!--Screen Group Id-->
    <SCREEN id="GRP_ID_ALM_LIST"/>
    <SCREEN id="GRP_ID_ALM_IND"/>
    <SCREEN id="GRP_ID_ALM_EDITOR"/>
    <SCREEN id="GRP_ID_ALM_AUDIO_OPTION"/>
    <SCREEN id="GRP_ID_ALM_AUDIO_OPTION_MAN_INPUT"/>
    <SCREEN id="GRP_ID_ALM_AUDIO_FM_CHANNEL_OPTION"/>
    <SCREEN id="GRP_ID_ALM_AUDIO_FM_MAN_OPTION"/>
    <SCREEN id="GRP_ID_ALM_REPEAT_TYPE_MENU"/>
    <SCREEN id="GRP_ID_ALM_TOTAL"/>
        <!--Screen ID Area-->
    <!--End Screen Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
# 196 "temp/res/Alarm.c"
    <MENU id="ORGANIZER_ALARM_MENU"
          type="APP_MAIN"
          parent="MAIN_MENU_ORGANIZER_MENUID"
          str="STR_GLOBAL_ALARM"
          img="ORGANIZER_MENU_ALARMS_IMAGEID"
          highlight="HighlightAlmMenu"
          shortcut="ON" shortcut_img="ORGANIZER_MENU_ALARMS_IMAGEID" launch="EntryAlmMenu">
# 213 "temp/res/Alarm.c"
    </MENU>
# 256 "temp/res/Alarm.c"
    <MENUITEM id="MENU_ID_ALM_REPEAT_TYPE_MAIN" str="ALARM_REPEAT_STRING"/>
    <MENUITEM id="MENU_ID_ALM_REPEAT_TYPE_CUSTOM_OPTION_MENU" str="STR_GLOBAL_OPTIONS"/>



    <!------------------------------------------------------ event handler ------------------------------------------------------>

        <RECEIVER id="EVT_ID_MMI_BOOTUP_INTERRUPTIBLE_CHANGED" proc="mmi_alarm_enable_pending_alarm"/>
        <RECEIVER id="EVT_ID_NMGR_PLAY_TONE" proc="mmi_alm_nmgr_evt_tone_handlr"/>
        <RECEIVER id="EVT_ID_NMGR_PLAY_VIB" proc="mmi_alm_nmgr_evt_vib_handlr"/>
        <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_alm_remdr_notify_hdlr"/>




    <RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_alm_clam_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_ALM_OP" proc="mmi_alm_srv_alm_op_hdlr"/>
</APP>
