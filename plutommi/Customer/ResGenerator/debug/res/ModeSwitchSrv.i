# 1 "temp/res/ModeSwitchSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/ModeSwitchSrv.c"
# 55 "temp/res/ModeSwitchSrv.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 56 "temp/res/ModeSwitchSrv.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 57 "temp/res/ModeSwitchSrv.c" 2

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_MODESWITCH">

        <SENDER id="EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY" hfile="ModeSwitchSrvGprot.h"/>
        <SENDER id="EVT_ID_SRV_MODE_SWITCH_SWITCH_OTHER_NOTIFY" hfile="ModeSwitchSrvGprot.h"/>
        <SENDER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" hfile="ModeSwitchSrvGprot.h"/>

        <CACHEDATA type="byte" id="NVRAM_DUALMODE_MODE_SWITCH_TYPE" restore_flag="TRUE">
                <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
                <DESCRIPTION> Byte Cache </DESCRIPTION>
        </CACHEDATA>

</APP>
