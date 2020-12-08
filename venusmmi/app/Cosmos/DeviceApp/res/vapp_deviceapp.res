#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_DEVICE" name="STR_ID_VAPP_DEVICEAPP" type="venus">
    <LAYOUT file="vapp_deviceapp.xml" />


    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    //<STRING id="STR_ID_VAPP_CHARGER_CHARGING"/>
    //<STRING id="STR_ID_VAPP_CHARGER_CHARGE_COMPLETED"/>
    <STRING id="STR_ID_VAPP_CHARGER_CHARGING_ERROR"/>
    <STRING id="STR_ID_VAPP_CHARGER_BATTERY_ERROR"/>
    <STRING id="STR_ID_VAPP_CHARGER_LOW_BATTERY"/>
    <STRING id="STR_ID_VAPP_CHARGER_LOW_BATTERY_SHUTDOWN"/>
    //<STRING id="STR_ID_VAPP_CHARGER_LOW_BATTERY_MT_PROHIBIT"/>
    //<STRING id="STR_ID_VAPP_CHARGER_SAVE_POWER_ON"/>
    //<STRING id="STR_ID_VAPP_CHARGER_SAVE_POWER_OFF"/>
    //<STRING id="STR_ID_VAPP_CHARGER_CONNECTED"/>
    //<STRING id="STR_ID_VAPP_CHARGER_REMOVED"/>
    //<STRING id="STR_ID_VAPP_CHARGING_TIMEOUT"/>
    //<STRING id="STR_ID_VAPP_USB_CHARGER_CONNECTED"/>
    //<STRING id="STR_ID_VAPP_USB_CHARGER_REMOVED"/>
    //<STRING id="STR_ID_VAPP_CHARGE_BAD_CONTACT"/>
    //<STRING id="STR_ID_VAPP_BATTERY_BAD_CONTACT"/>

    <STRING id="STR_ID_VAPP_GPIO_BRIGHTNESS"/>
#ifdef __MMI_CABC__
    <STRING id="STR_ID_VAPP_GPIO_CABC"/>
#endif

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #define VDEVICEAPP_PATH RES_IMG_ROOT"\\\\Settings\\\\ListIcon\\\\"    
    <IMAGE id="IMG_ID_VAPP_DEVICE_BRIGHTNESS_MIN">VDEVICEAPP_PATH"Brightness_MIN.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DEVICE_BRIGHTNESS_MAX">VDEVICEAPP_PATH"Brightness_MAX.png"</IMAGE>
    

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    
    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
    <RECEIVER id="EVT_ID_SRV_CHARBAT_NOTIFY" proc="vapp_charger_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CHARBAT_REMIND_LOW_POWER" proc="vapp_charger_other_evt_hdlr"/>
    <TIMER id ="VAPP_LOW_BATTERY_SCR_TIMER"/>
    
</APP>

