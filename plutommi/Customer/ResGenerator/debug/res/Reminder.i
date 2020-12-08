# 1 "temp/res/Reminder.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/Reminder.c"
# 55 "temp/res/Reminder.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 56 "temp/res/Reminder.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 57 "temp/res/Reminder.c" 2


<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_REMINDER">

        <RECEIVER id="EVT_ID_SRV_REMINDER_BOOTUP_START" proc="mmi_reminder_bootup_start"/>
        <RECEIVER id="EVT_ID_SRV_REMINDER_PWRRESET_REQ" proc="mmi_reminder_on_pwrreset_notify"/>
        <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_remdr_ut_notify_hdlr"/>

        <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_reset_alm_remdr_notify_hdlr"/>
  <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="mmi_factory_alm_remdr_notify_hdlr"/>

</APP>
