#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_SNOW">
#if defined(__MMI_VUI_HOMESCREEN_SNOW__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_SNOW"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH     ROOT_PATH"Widget\\\\"
    #define SNOW_WIDGET_PATH WIDGET_PATH"Snow\\\\"
    <IMAGE id="VAPP_HS_IMG_WG_ICON_SNOW">WIDGET_PATH"Widgeticon_Snow.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_SNOWMAN">SNOW_WIDGET_PATH"SnowMan.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_SNOW1">SNOW_WIDGET_PATH"Snowflake1.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_SNOW2">SNOW_WIDGET_PATH"Snowflake2.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_SNOW3">SNOW_WIDGET_PATH"Snowflake3.png"</IMAGE>

#endif

</APP>

