# 1 "temp/res/UsbSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/UsbSrv.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 2 "temp/res/UsbSrv.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 3 "temp/res/UsbSrv.c" 2

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_USBSRV">


    <CACHEDATA type="byte" id="NVRAM_DEFAULT_USB_APP" restore_flag="FALSE" restore_id="@NVRAM_CACHE_ID_RESERVED">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <EVENT id="EVT_ID_USB_PERMIT_CFG" type="SENDER"/>
                <EVENT id="EVT_ID_USB_PERMIT_CFG_PRE_CHECK" type="SENDER"/>
                <EVENT id="EVT_ID_USB_ENTER_MS_MODE" type="SENDER"/>
                <EVENT id="EVT_ID_USB_EXIT_MS_MODE" type="SENDER"/>
                <EVENT id="EVT_ID_USB_PLUG_IN" type="SENDER"/>
                <EVENT id="EVT_ID_USB_CONFIG_RSP" type="SENDER"/>
                <EVENT id="EVT_ID_USB_MMI_NOTIFY" type="SENDER"/>
                <EVENT id="EVT_ID_USB_PLUG_OUT" type="SENDER"/>
                <EVENT id="EVT_ID_USB_PRE_EXIT_MODE" type="SENDER"/>
                <EVENT id="EVT_ID_USB_ALM_STATE" type="SENDER"/>




    <TIMER id = "USB_SHUTDOWN_SCR_TIMER"/>
    <TIMER id = "PENDING_USBDETECTION_HDLR_TIMER"/>

</APP>
