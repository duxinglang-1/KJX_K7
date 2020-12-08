# 1 "temp/res/Cbm.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/Cbm.c"

# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 3 "temp/res/Cbm.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/Cbm.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_CBM">





    <!--Include Area-->

    <!------------------------String Resource Area-------------------------->
# 34 "temp/res/Cbm.c"
    <!------------------------Image Resource Area--------------------------->

    <!-------------------------Menu Resource Area--------------------------->

    <!------------------------Screen Resource Area-------------------------->
    <SCREEN id="GRP_ID_MMI_CBM_APP"/>
    <SCREEN id="SCR_ID_MMI_CBM_NOTIFY"/>

    <!---------------------------Other Resource----------------------------->
    <RECEIVER id="EVT_ID_SRV_CBM_BEARER_INFO" proc="mmi_cbm_handle_cbm_bearer_info"/>
    <RECEIVER id="EVT_ID_SRV_CBM_WLAN_QUERY" proc="mmi_cbm_srv_cbm_wlan_query_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_LOCKER_LOCKED" proc="mmi_cbm_evt_proc_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="mmi_cbm_evt_proc_hdlr"/>




    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND" proc="mmi_cbm_evt_proc_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_cbm_evt_proc_hdlr"/>



</APP>
