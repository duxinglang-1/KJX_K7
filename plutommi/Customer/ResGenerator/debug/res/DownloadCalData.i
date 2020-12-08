# 1 "temp/res/DownloadCalData.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/DownloadCalData.c"
# 74 "temp/res/DownloadCalData.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 75 "temp/res/DownloadCalData.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 76 "temp/res/DownloadCalData.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_SETTING_DOWNLOAD_CAL_DATA">



    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="STR_ID_PHNSET_DOWNLOAD_DATA_INVALID"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

    <!------------------------------------------------------Sender Resource---------------------------------------------------------->
        <SENDER id="EVT_ID_MMI_DL_CAL_DATA_NOTIFY" hfile="PhnsetDlCalDataGprot.h"/>

    <!------------------------------------------------------receiver Resource---------------------------------------------------------->
    <RECEIVER id="EVT_ID_MMI_DL_CAL_DATA_NOTIFY" proc="mmi_phnset_dl_data_is_invalid_hdlr"/>

</APP>
