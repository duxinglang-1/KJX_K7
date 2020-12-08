# 1 "temp/res/FileMgrSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/FileMgrSrv.c"
<?xml version="1.0" encoding="UTF-8"?>

# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 4 "temp/res/FileMgrSrv.c" 2

<APP id="SRV_FILEMANAGER">
    <INCLUDE file="GlobalResDef.h"/>

<!--
**************************************** String section ***************************************
-->
<!-- FS Error -->


    <STRING id="FMGR_FS_ABORTED_ERROR_TEXT"/>
    <STRING id="FMGR_FS_PATH_OVER_LEN_ERROR_TEXT"/>
    <STRING id="FMGR_FS_ROOT_DIR_FULL_TEXT"/>
    <STRING id="FMGR_FS_MEDIA_CHANGED_TEXT"/>
    <STRING id="FMGR_FS_FAT_ALLOC_ERROR_TEXT"/>
    <STRING id="FMGR_FS_WRITE_PROTECTION_TEXT"/>
    <STRING id="FMGR_FS_DRIVE_NOT_FOUND_TEXT"/>
    <STRING id="FMGR_FS_PARAM_ERROR_TEXT"/>
    <STRING id="FMGR_FS_FILE_NOT_FOUND_TEXT"/>
    <STRING id="FMGR_FS_ACCESS_DENIED_TEXT"/>
    <STRING id="FMGR_FS_PATH_NOT_FOUND_TEXT"/>
    <STRING id="FMGR_FS_DEVICE_BUSY_TEXT"/>
    <STRING id="FMGR_FS_APP_QUOTA_FULL_TEXT"/>
# 81 "temp/res/FileMgrSrv.c"
<!-- Storage name -->
# 124 "temp/res/FileMgrSrv.c"
    <STRING id="STR_FMGR_CARD_MOUNTING"/>

    <!-- Event registration -->
        <SENDER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" hfile="FileMgrSrvGProt.h" />
        <SENDER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" hfile="FileMgrSrvGProt.h" />
        <SENDER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" hfile="FileMgrSrvGProt.h" />
        <SENDER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" hfile="FileMgrSrvGProt.h" />
        <SENDER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_READY" hfile="FileMgrSrvGProt.h" />
        <SENDER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" hfile="FileMgrSrvGProt.h" />
        <SENDER id="EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE" hfile="FileMgrSrvGProt.h" />

        <SENDER id="EVT_ID_SRV_FMGRI_CARD_PLUG_IN" hfile="FileMgrSrvIProt.h" />
        <SENDER id="EVT_ID_SRV_FMGRI_CARD_PLUG_OUT" hfile="FileMgrSrvIProt.h" />
        <SENDER id="EVT_ID_SRV_FMGRI_CARD_DISPLAY_MOUNTING" hfile="FileMgrSrvIProt.h" />





    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_fmgr_ms_handler" />
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_fmgr_ms_handler" />

    <!-- NVRAM related -->
    <CACHEDATA type="byte" id="NVRAM_EF_FMGR_SORT_OPTION_LID" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

</APP>
