# 1 "temp/res/UmSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/UmSrv.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/UmSrv.c" 2

<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_UNIFIEDMESSAGE">

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

        <SENDER id="EVT_ID_SRV_UM_NOTIFY_READY" hfile="UmSrvGprot.h"/>
        <SENDER id="EVT_ID_SRV_UM_NOTIFY_HIGHLIGHT_MSG" hfile="UmSrvGprot.h"/>
        <SENDER id="EVT_ID_SRV_UM_NOTIFY_REFRESH" hfile="UmSrvGprot.h"/>


    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_um_sd_card_plug_in_out_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_um_sd_card_plug_in_out_hdlr"/>


        <RECEIVER id="EVT_ID_SETTING_LANGUAGE_CHANGED" proc="srv_um_receive_event"/>




    <TIMER id="SRV_UM_SEND_MSG_TIMER_ID"/>
# 32 "temp/res/UmSrv.c"
</APP>
