# 1 "temp/res/SchedulePowerOnOff.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/SchedulePowerOnOff.c"
# 118 "temp/res/SchedulePowerOnOff.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 119 "temp/res/SchedulePowerOnOff.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 120 "temp/res/SchedulePowerOnOff.c" 2


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_SPOF">

    <!-- string ----------------------------------------------------------------------------------->
    <STRING id = "SPOF_MAIN_TITLE_STRINGID"/>
    <STRING id = "SPOF_STATUS_STRINGID"/>
    <STRING id = "SPOF_DISABLE_STRINGID"/>
    <STRING id = "SPOF_ENABLE_STRINGID"/>
    <STRING id = "SPOF_TIME_CONFLICT"/>
    <STRING id = "SPOF_POWER_OFF_CONFIRM"/>
    <STRING id = "STR_MENU_SETTING_SCHEDULE_POWER"/>
    <STRING id = "STR_MENU_SETTING_SCH_POW_SET1_POW_ON"/>
    <STRING id = "STR_MENU_SETTING_SCH_POW_SET1_POW_OFF"/>


    <!-- image ------------------------------------------------------------------------------------>
# 148 "temp/res/SchedulePowerOnOff.c"
    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "GRP_ID_PHNSET_SCHEDULE_POWER_CONFIRM"/>
    <SCREEN id = "SCR_ID_SPOF_CONFIRM"/>



    <!-- menu ------------------------------------------------------------------------------------->

    <MENU id = "MENU_SETTING_SCHEDULE_POWER" type = "APP_SUB" str = "STR_MENU_SETTING_SCHEDULE_POWER">
        <MENUITEM id = "MENU_SETTING_SCHEDULE_POWER_ON" str = "STR_MENU_SETTING_SCH_POW_SET1_POW_ON"/>
        <MENUITEM id = "MENU_SETTING_SCHEDULE_POWER_OFF" str = "STR_MENU_SETTING_SCH_POW_SET1_POW_OFF"/>
    </MENU>

    <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_spof_reminder_srv_proc"/>






</APP>
