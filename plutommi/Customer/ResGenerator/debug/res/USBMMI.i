# 1 "temp/res/USBMMI.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/USBMMI.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 2 "temp/res/USBMMI.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 3 "temp/res/USBMMI.c" 2

<?xml version = "1.0" encoding="UTF-8"?>

<APP id = "APP_USBMMI">



<!----------------- Include Area ---------------------------------------------->

    <INCLUDE file = "MMI_features.h"/>
    <INCLUDE file = "MMIDataType.h"/>
    <INCLUDE file = "GlobalResDef.h"/>
        <INCLUDE file = "gdi_features.h"/>

<!----------------- Common Area ----------------------------------------------->

<!----------------- String Id ----------------------------------------->
    <STRING id = "STR_USB_CONFIG_TITLE">USB Config.</STRING>







    <STRING id = "STR_USB_CONFIG_MS">Mass Storage</STRING>
    <STRING id = "STR_USB_CONFIG_CDCACM_DATA">Data Port</STRING>


    <STRING id = "STR_USB_CONFIG_MS_ONLY">USB Detect! Shutdown for Mass storage?</STRING>
# 56 "temp/res/USBMMI.c"
    <STRING id = "STR_ID_USB_NO_MS_FOR_PC">USB: No storage for PC</STRING>
    <STRING id = "STR_ID_USB_SYS_NOT_READY">System not ready, Please try later!</STRING>




    <STRING id = "STR_ID_USB_UART2_OCCUPIED">Not allow when PS set to None</STRING>
# 71 "temp/res/USBMMI.c"
<!----------------- Menu Id ----------------------------------------->
# 102 "temp/res/USBMMI.c"
<!----------------- Event callbacks------------------------------------>


<RECEIVER id="EVT_ID_USB_PERMIT_CFG" proc="mmi_usb_handle_query_permit_show"/>
<RECEIVER id="EVT_ID_USB_PERMIT_CFG_PRE_CHECK" proc="mmi_usb_handle_query_permit_pre_check"/>
<RECEIVER id="EVT_ID_USB_PLUG_IN" proc="mmi_usb_handle_plug_in"/>
<RECEIVER id="EVT_ID_USB_CONFIG_RSP" proc="mmi_usb_config_rsp_callback"/>
<RECEIVER id="EVT_ID_USB_MMI_NOTIFY" proc="mmi_usb_mmi_notify_callback"/>
<RECEIVER id="EVT_ID_USB_ALM_STATE" proc="mmi_usb_alm_state_callback"/>




<!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "GRP_ID_USB_BOOT_MODE"/>
    <SCREEN id = "GRP_ID_USB_MMI"/>
    <SCREEN id = "SCR_DEV_USBDETECT"/>
    <SCREEN id = "SCR_USB_POWER_ON"/>
    <SCREEN id = "SCR_USB_CHGR_CMPLT"/>
    <SCREEN id = "SCR_USB_POWER_ON_DONE"/>
    <SCREEN id = "SCR_ID_USB_WEBCAM"/>
    <SCREEN id = "SCR_ID_USB_PROGRESS"/>
    <SCREEN id = "SCR_ID_USB_WAIT"/>


<!----------------- Image Id ------------------------------------------->



    <IMAGE id = "IMG_USB_POWER_ON">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Active\\\\Poweronoff\\\\USB_noanimation.""GIF"</IMAGE>
    <IMAGE id = "IMG_USB_CHGR_CMPLT">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Active\\\\Poweronoff\\\\USB_ChgrCmplt.""GIF"</IMAGE>
    <IMAGE id = "IMG_ID_USB_CHARGING">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Active\\\\Poweronoff\\\\USB_on.gif"</IMAGE>
# 144 "temp/res/USBMMI.c"
<TIMER id="USB_WAIT_FOR_MASS_STORAGE"/>

<!----------------- XML END --------------------------------------------------->



</APP>
