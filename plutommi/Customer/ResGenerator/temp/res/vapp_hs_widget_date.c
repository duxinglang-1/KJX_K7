#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_DATE">
#if defined(__MMI_VUI_HOMESCREEN_DATE__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_DATE"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH     ROOT_PATH"Widget\\\\"
    #define DATE_WIDGET_PATH WIDGET_PATH"Date\\\\"
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    #define VUI_HS_IMG_TYPE "BMP"
#else /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
    #define VUI_HS_IMG_TYPE "PNG"
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE">WIDGET_PATH"Widgeticon_Date.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE_BG">DATE_WIDGET_PATH"Widgeticon_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE_D0">DATE_WIDGET_PATH"Widgeticon_0.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE_D1">DATE_WIDGET_PATH"Widgeticon_1.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE_D2">DATE_WIDGET_PATH"Widgeticon_2.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE_D3">DATE_WIDGET_PATH"Widgeticon_3.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE_D4">DATE_WIDGET_PATH"Widgeticon_4.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE_D5">DATE_WIDGET_PATH"Widgeticon_5.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE_D6">DATE_WIDGET_PATH"Widgeticon_6.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE_D7">DATE_WIDGET_PATH"Widgeticon_7.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE_D8">DATE_WIDGET_PATH"Widgeticon_8.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_ICON_DATE_D9">DATE_WIDGET_PATH"Widgeticon_9.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE">DATE_WIDGET_PATH"Date_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_D0">DATE_WIDGET_PATH"Date_0.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_D1">DATE_WIDGET_PATH"Date_1.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_D2">DATE_WIDGET_PATH"Date_2.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_D3">DATE_WIDGET_PATH"Date_3.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_D4">DATE_WIDGET_PATH"Date_4.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_D5">DATE_WIDGET_PATH"Date_5.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_D6">DATE_WIDGET_PATH"Date_6.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_D7">DATE_WIDGET_PATH"Date_7.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_D8">DATE_WIDGET_PATH"Date_8.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_D9">DATE_WIDGET_PATH"Date_9.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M1">DATE_WIDGET_PATH"Date_Jan.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M2">DATE_WIDGET_PATH"Date_Feb.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M3">DATE_WIDGET_PATH"Date_Mar.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M4">DATE_WIDGET_PATH"Date_Apr.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M5">DATE_WIDGET_PATH"Date_May.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M6">DATE_WIDGET_PATH"Date_Jun.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M7">DATE_WIDGET_PATH"Date_Jul.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M8">DATE_WIDGET_PATH"Date_Aug.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M9">DATE_WIDGET_PATH"Date_Sep.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M10">DATE_WIDGET_PATH"Date_Oct.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M11">DATE_WIDGET_PATH"Date_Nov.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_M12">DATE_WIDGET_PATH"Date_Dec.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_W0">DATE_WIDGET_PATH"Date_Sun.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_W1">DATE_WIDGET_PATH"Date_Mon.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_W2">DATE_WIDGET_PATH"Date_Tue.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_W3">DATE_WIDGET_PATH"Date_Wed.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_W4">DATE_WIDGET_PATH"Date_Thu.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_W5">DATE_WIDGET_PATH"Date_Fri.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_DATE_W6">DATE_WIDGET_PATH"Date_Sat.png"</IMAGE>

#endif

</APP>

