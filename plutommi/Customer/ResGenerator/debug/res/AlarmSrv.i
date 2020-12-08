# 1 "temp/res/AlarmSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/AlarmSrv.c"
<?xml version="1.0" encoding="UTF-8"?>

# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 4 "temp/res/AlarmSrv.c" 2

<APP id="SRV_ALARM">

        <EVENT id="EVT_ID_SRV_ALM_OP" type="SENDER"/>

        <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="srv_alm_notify_hdlr"/>
        <RECEIVER id="EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT" proc="srv_alm_notify_hdlr"/>

</APP>
