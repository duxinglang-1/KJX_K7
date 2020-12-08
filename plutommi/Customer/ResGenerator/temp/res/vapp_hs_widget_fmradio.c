#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_FMRADIO">
#if defined(__MMI_VUI_HOMESCREEN_FM_RADIO__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_FM_RADIO"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH     ROOT_PATH"Widget\\\\"
    #define FMRADIO_WIDGET_PATH WIDGET_PATH"FMRadio\\\\"

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    #define VUI_HS_IMG_TYPE "BMP"
#else
    #define VUI_HS_IMG_TYPE "PNG"
#endif

    <IMAGE id="VAPP_HS_IMG_WG_ICON_FMR">WIDGET_PATH"Widgeticon_FMRadio.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_BG">FMRADIO_WIDGET_PATH"RADIO_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_NEXT_UP">FMRADIO_WIDGET_PATH"RADIO_tune_inc_off.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_NEXT_DOWN">FMRADIO_WIDGET_PATH"RADIO_tune_inc_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_NEXT_DISABLE">FMRADIO_WIDGET_PATH"RADIO_tune_inc_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_PREV_UP">FMRADIO_WIDGET_PATH"RADIO_tune_dec_off.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_PREV_DOWN">FMRADIO_WIDGET_PATH"RADIO_tune_dec_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_PREV_DISABLE">FMRADIO_WIDGET_PATH"RADIO_tune_dec_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_PLAY_UP">FMRADIO_WIDGET_PATH"RADIO_play_off.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_PLAY_DOWN">FMRADIO_WIDGET_PATH"RADIO_play_on.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_PLAY_DISABLE">FMRADIO_WIDGET_PATH"RADIO_play_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_STOP_UP">FMRADIO_WIDGET_PATH"RADIO_stop_off.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_FMR_STOP_DOWN">FMRADIO_WIDGET_PATH"RADIO_stop_on.png"</IMAGE>

#endif

</APP>

