# 1 "temp/res/NITZSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/NITZSrv.c"
# 56 "temp/res/NITZSrv.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 57 "temp/res/NITZSrv.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 58 "temp/res/NITZSrv.c" 2
# 1 "../../mmi/setting/settinginc/SettingDefs.h" 1
# 59 "temp/res/NITZSrv.c" 2


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_NITZ">

        <SENDER id="EVT_ID_SRV_NITZ_UPDATE" hfile="NITZSrvGprot.h"/>

        <SENDER id="EVT_ID_SRV_NITZ_UPDATE_REQ" hfile="NITZSrvGprot.h"/>

        <SENDER id="EVT_ID_NITZ_NW_NAME_UPDATE_NOTIFY" hfile="NITZSrvGprot.h"/>

<!-----------------------------------------------------cache Resource Area------------------------------------------------------>
        <CACHEDATA type="byte" id="NVRAM_SETTING_AUTOUPDATE_DT_TIME_STATUS" restore_flag="TRUE" >
                <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
                <DESCRIPTION> auto update date and time state </DESCRIPTION>
        </CACHEDATA>


</APP>
