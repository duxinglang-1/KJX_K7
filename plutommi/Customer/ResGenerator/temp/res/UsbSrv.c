#include "MMI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_USBSRV">
#ifdef __MMI_USB_SUPPORT__

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
    #ifdef __DM_LAWMO_SUPPORT__
        <RECEIVER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" proc="srv_usb_dmui_lock_notify"/>
    #endif
    
    <TIMER id = "USB_SHUTDOWN_SCR_TIMER"/>
    <TIMER id = "PENDING_USBDETECTION_HDLR_TIMER"/>
#endif /* __MMI_USB_SUPPORT__ */	
</APP>

