#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_PHOTO">
#if defined(__MMI_VUI_HOMESCREEN_PHOTO__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_PHOTO"/>
    <STRING id="VAPP_HS_STR_PHOTO_IMG_SMALL"/>
    <STRING id="VAPP_HS_STR_PHOTO_IMG_RATIO_IMPROPER"/>
    <STRING id="VAPP_HS_STR_PHOTO_ADD_PHOTO"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH     ROOT_PATH"Widget\\\\"
    #define PHOTO_WIDGET_PATH WIDGET_PATH"Photoframe\\\\"

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    #define VUI_HS_IMG_TYPE "BMP"
#else
    #define VUI_HS_IMG_TYPE "PNG"
#endif

    <IMAGE id="VAPP_HS_IMG_WG_ICON_PHOTO">WIDGET_PATH"Widgeticon_photoframe.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PHOTO_BG">PHOTO_WIDGET_PATH"PF_bg."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PHOTO_DEFAULT">PHOTO_WIDGET_PATH"PF_default.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PHOTO_SELE_UP">PHOTO_WIDGET_PATH"PF_setting_off.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PHOTO_SELE_DOWN">PHOTO_WIDGET_PATH"PF_setting_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PHOTO_PROCESS">PHOTO_WIDGET_PATH"PF_loading.png"</IMAGE>

#endif

</APP>

