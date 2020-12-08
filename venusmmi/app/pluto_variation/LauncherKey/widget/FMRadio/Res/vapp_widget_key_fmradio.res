#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_KEY_WG_FMRADIO">

#if defined(__MMI_VUI_WIDGET_KEY_FM_RADIO__)

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_WIDGET_KEY_STR_FM"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\"
#define WIDGET_ROOT_PATH     ROOT_PATH"Common\\\\Widget_common\\\\"
#define FMRADIO_WIDGET_PATH ROOT_PATH"Widget\\\\FM\\\\"


    <IMAGE id="VAPP_KEY_IMG_WG_ICON_FMRADIO">WIDGET_ROOT_PATH"widget_radio.png"</IMAGE>    

    <IMAGE id="VAPP_KL_WG_FM_BACKGROUND">FMRADIO_WIDGET_PATH"FM_glass.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_FM_BG_TURNON">FMRADIO_WIDGET_PATH"FM_BG_turnon.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_FM_BG_TURNOFF">FMRADIO_WIDGET_PATH"FM_BG_turnoff.png"</IMAGE>

    <IMAGE id="VAPP_KL_WG_FM_POWERON">FMRADIO_WIDGET_PATH"FM_poweron.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_FM_POWERON_DOWN">FMRADIO_WIDGET_PATH"FM_poweron1.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_FM_POWEROFF">FMRADIO_WIDGET_PATH"FM_poweroff.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_FM_POWEROFF_DOWN">FMRADIO_WIDGET_PATH"FM_poweroff1.png"</IMAGE>

    <IMAGE id="VAPP_KL_WG_FM_SEARCH">FMRADIO_WIDGET_PATH"FM_search.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_FM_SEARCH_LOADING_1">FMRADIO_WIDGET_PATH"FM_search_loading1.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_FM_SEARCH_LOADING_2">FMRADIO_WIDGET_PATH"FM_search_loading2.png"</IMAGE>

    <IMAGE id="VAPP_KL_WG_FM_ARROW_DOWN_SELECT">FMRADIO_WIDGET_PATH"FM_arrows_select.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_FM_ARROW_DOWN_TURNOFF">FMRADIO_WIDGET_PATH"FM_arrows_turnoff.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_FM_ARROW_DOWN_TURNON">FMRADIO_WIDGET_PATH"FM_arrows_turnon.png"</IMAGE>

    <IMAGE id="VAPP_KL_WG_FM_ARROW_UP_SELECT">FMRADIO_WIDGET_PATH"FM_arrows0_select.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_FM_ARROW_UP_TURNOFF">FMRADIO_WIDGET_PATH"FM_arrows0_turnoff.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_FM_ARROW_UP_TURNON">FMRADIO_WIDGET_PATH"FM_arrows0_turnon.png"</IMAGE>

   <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetKeyFMRadioPublisher"/>
 #endif
   
</APP>

