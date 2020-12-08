#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_MRE">

#if defined(__MMI_VUI_HOMESCREEN_MRE_LINK__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_MRE"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH     ROOT_PATH"Widget\\\\"
    #define MRE_WIDGET_PATH WIDGET_PATH"MRE\\\\"

    <IMAGE id="VAPP_HS_IMG_WG_ICON_MRE">WIDGET_PATH"Widgeticon_MRE.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_MRE">MRE_WIDGET_PATH"MRE_MRE.png"</IMAGE>

#endif


</APP>

