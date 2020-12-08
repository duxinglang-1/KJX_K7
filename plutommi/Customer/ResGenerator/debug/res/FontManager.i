# 1 "temp/res/FontManager.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/FontManager.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/FontManager.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/FontManager.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_FONT_MANAGER">



    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,mmi_rp_file_type_def.h,SettingResDef.h,FileMgrResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
# 46 "temp/res/FontManager.c"
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
# 57 "temp/res/FontManager.c"
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
# 85 "temp/res/FontManager.c"
    <!--Menu Tree Area-->

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
# 125 "temp/res/FontManager.c"
        <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_lang_err_memory_card_notify_silent_reboot_hdlr"/>
        <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" proc="mmi_lang_err_memory_card_notify_silent_reboot_hdlr"/>
        <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_lang_err_memory_card_notify_silent_reboot_hdlr"/>

        <TIMER id="FONT_SILENT_REBOOT_TIMER"/>
</APP>
