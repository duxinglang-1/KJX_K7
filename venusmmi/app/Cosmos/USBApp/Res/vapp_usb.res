#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
<APP id="VAPP_USBMMI" name="STR_ID_VAPP_USB_APPNAME" type="venus">

    #ifndef __MMI_USB_SLIM__
     <MEMORY base = "0"/>
     #else
    <MEMORY heap = "200*1024"/>
    		#endif

	<RECEIVER id="EVT_ID_USB_PERMIT_CFG" proc="vapp_usb_handle_query_permit_show"/>
	<RECEIVER id="EVT_ID_USB_PERMIT_CFG_PRE_CHECK" proc="vapp_usb_handle_query_permit_pre_check"/>
	<RECEIVER id="EVT_ID_USB_PLUG_IN" proc="vapp_usb_handle_plug_in"/>
	<RECEIVER id="EVT_ID_USB_CONFIG_RSP" proc="vapp_usb_cfg_rsp_callback"/>
	<RECEIVER id="EVT_ID_USB_MMI_NOTIFY" proc="vapp_usb_mmi_notify_callback"/>
	<RECEIVER id="EVT_ID_SRV_CHARBAT_NOTIFY" proc="vapp_usb_charger_notify_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_REMINDER_PWRRESET_REQ" proc="vapp_usb_reminder_notify_hdlr"/>

	
	

    <STRING id = "STR_ID_VAPP_USB_APPNAME">USB</STRING>
	<STRING id = "STR_ID_VAPP_USB_CONFIG_MS">Mass storage</STRING>
	<STRING id = "STR_ID_VAPP_USB_COM">COM port</STRING>
	#ifdef __MMI_WEBCAM__
  <STRING id = "STR_ID_VAPP_USB_WEBCAM">Web camera</STRING>
  #endif
  <STRING id = "STR_ID_VAPP_USB_CONFIG_COMPORT_JAVA">JAVA connection</STRING>
  <STRING id = "STR_ID_VAPP_USB_CONFIG_MTP">MTP storage</STRING>
  #ifdef __MMI_PICT_BRIDGE_SUPPORT__
  <STRING id = "STR_ID_VAPP_USB_CONFIG_PICT_BRIGE">PictBridge</STRING>
  #endif
	<STRING id = "STR_ID_VAPP_USB_CONNECT_SUCCESS">Connected</STRING>
	<STRING id = "STR_ID_VAPP_USB_CONFIG_TITLE">USB mode</STRING>
	<STRING id = "STR_ID_VAPP_USB_CONNECTING">Connecting</STRING>
	<STRING id = "STR_ID_VAPP_USB_CONNECT_FAIL">Connect fail</STRING>
	<STRING id = "STR_ID_VAPP_USB_INIT_TIME">00:00</STRING>
    <STRING id = "STR_ID_VAPP_USB_AM">AM</STRING>
	<STRING id = "STR_ID_VAPP_USB_PM">PM</STRING>
	//<STRING id = "STR_ID_VAPP_USB_CHARGING">Charging</STRING>
	<STRING id = "STR_ID_VAPP_USB_CHARGING_ERROR">Charging error</STRING>
	//<STRING id = "STR_ID_VAPP_USB_CHARGING_COMPLETED">Charging completed</STRING>
	<STRING id = "STR_ID_VAPP_USB_MS_CONFIRM">Some apps might be closed or unavailable in Mass storage mode.Continue?</STRING>
	<STRING id = "STR_ID_VAPP_USB_MTP_CONFIRM">Some apps might be closed or unavailable in MTP mode.Continue?</STRING>
	<STRING id = "STR_ID_VAPP_USB_CONFIG_MS_ONLY">USB Detect! Shutdown for Mass storage?</STRING>
	#ifdef __USB_TETHERING__
	<STRING id = "STR_ID_VAPP_USB_TETHERING">USB tethering</STRING>
	#endif
	<STRING id = "STR_ID_VAPP_USB_CONTINUE">Continue</STRING>
	<STRING id = "STR_ID_VAPP_USB_NOT_AVAILABLE_IN_MTP_MODE">Not available in MTP mode</STRING>
	<STRING id = "STR_ID_VAPP_USB_MS_SHUT_DOWN_CONFIRM">Device will be powered off.Continue?</STRING>
	<STRING id = "STR_ID_VAPP_USB_WAIT_CONFIG_MS">Please wait</STRING>

	#define ROOT_PATH RES_IMG_ROOT"\\\\USB\\\\"
	#define COMMON_PATH RES_IMG_ROOT"\\\\Common\\\\"
    <IMAGE id="IMG_ID_VAPP_USB_BATTERY_BORDER">ROOT_PATH"Charging_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_USB_BATTERY_LEVEL1">ROOT_PATH"Power01.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_USB_BATTERY_LEVEL2">ROOT_PATH"Power02.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_USB_BATTERY_LEVEL3">ROOT_PATH"Power03.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_USB_USBMODE_BG">COMMON_PATH"Grid_BG.9slice.png"</IMAGE>

  #ifdef __VENUS_3D_UI_ENGINE__
  <BINARY3D id="VS_ID_VAPP_USB_REFLECTION" base_path="current">"Vapp_usb_reflection.vs"</BINARY3D>
  <BINARY3D id="FS_ID_VAPP_USB_REFLECTION" base_path="current">"Vapp_usb_reflection.fs"</BINARY3D>
  #endif
  <TIMER id = "USB_EXIT_MS_PROGRESS_TIMER"/>

</APP>
#else
<APP id="VAPP_USBMMI"></APP>
#endif
