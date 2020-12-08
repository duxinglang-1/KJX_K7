# 1 "temp/res/ScreenRotation.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/ScreenRotation.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/ScreenRotation.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/ScreenRotation.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_AUTO_ROTATE">



    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


        <!-----------------------------------------NVRAM CACHE---------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_EF_SENSOR_UI_ROTATION_SWITCH" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> UI rotation is on </DESCRIPTION>
    </CACHEDATA>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->





                <SENDER id="EVT_ID_AUTO_ROTATE_QUERY" hfile="ScreenRotationGprot.h"/>
                <SENDER id="EVT_ID_ORIENTATION_CHANGED" hfile="ScreenRotationGprot.h"/>

</APP>
