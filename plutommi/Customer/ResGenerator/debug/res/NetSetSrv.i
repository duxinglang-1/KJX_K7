# 1 "temp/res/NetSetSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/NetSetSrv.c"
# 55 "temp/res/NetSetSrv.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 56 "temp/res/NetSetSrv.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 57 "temp/res/NetSetSrv.c" 2


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_NETSET">
    <INCLUDE file = "GlobalResDef.h"/>

    <CACHEDATA type="byte" id="NVRAM_NETSET_PREFERRED_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Current preferred mode </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_NETSET_PREFERRED_MODE_PREV_RF_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Previouse RF mode for preferred mode switch </DESCRIPTION>
    </CACHEDATA>

        <CACHEDATA type="byte" id="NVRAM_NETSET_3G_CAPACITY_SIM" restore_flag="TRUE">
                <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
                <DESCRIPTION> Network 3g capacity sim card </DESCRIPTION>
        </CACHEDATA>


</APP>
