# 1 "temp/res/ReminderSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/ReminderSrv.c"
<?xml version="1.0" encoding="UTF-8"?>

# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 4 "temp/res/ReminderSrv.c" 2

<APP id="SRV_REMINDER">
        <EVENT id="EVT_ID_SRV_REMINDER_BOOTUP_START" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_REMINDER_BOOTUP_INIT" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_REMINDER_BOOTUP_COMPLETE" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_REMINDER_NOTIFY" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_REMINDER_PWRRESET_REQ" type="SENDER"/>

        <RECEIVER id="EVT_ID_SRV_DATETIME_CHANGE" proc="srv_reminder_on_time_change_notify"/>
        <RECEIVER id="EVT_ID_SRV_REMINDER_BOOTUP_COMPLETE" proc="srv_reminder_on_bootup_notify"/>
        <RECEIVER id="EVT_ID_SRV_SHUTDOWN_NORMAL_START" proc="srv_reminder_on_shutdown_notify"/>
# 23 "temp/res/ReminderSrv.c"
</APP>
