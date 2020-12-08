#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_WALLPAPER_WILDWORLD">

#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WILDWORLD__)
    <!-----------------------------------------------------NVRAM Resource Area----------------------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_PHNSET_LIVE_WALLPAPER_WILDWORLD_DN">
        <DEFAULT_VALUE>[0x01]</DEFAULT_VALUE>
        <DESCRIPTION>Live Wallpaper Wild World day or night setting</DESCRIPTION>
    </CACHEDATA> 
    
    <STRING id = "STR_ID_WALLPAPER_VUI_LIVE_WILDWORLD"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #define WILDWORLD_BASE     CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Wallpaper\\\\WildWorld\\\\"
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_1">WILDWORLD_BASE"ww_layer1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_1_2">WILDWORLD_BASE"ww_layer1-1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_2">WILDWORLD_BASE"ww_layer2.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_2_2">WILDWORLD_BASE"ww_layer2-1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_3">WILDWORLD_BASE"ww_layer3.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_3_2">WILDWORLD_BASE"ww_layer3-1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_4">WILDWORLD_BASE"ww_layer4.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_4_2">WILDWORLD_BASE"ww_layer4-1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_5">WILDWORLD_BASE"ww_layer5.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_5_2">WILDWORLD_BASE"ww_layer5-1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_BG_DAY">WILDWORLD_BASE"ww_layerBg_day-1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_BG_DAY_2">WILDWORLD_BASE"ww_layerBg_day.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_BG_NIGHT">WILDWORLD_BASE"ww_layerBg_night-1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_LAYER_BG_NIGHT_2">WILDWORLD_BASE"ww_layerBg_night.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_CHAR_DINOSAUR">WILDWORLD_BASE"ww_char_dinosaur.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_CHAR_PTEROSAUR">WILDWORLD_BASE"ww_char_pterosaur.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_WILDWORLD_FIREBALL">WILDWORLD_BASE"ww_fireball.png"</IMAGE>

    #define COSMOS_WALLPAPER_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_WILDWORLD_THUMBNAIL">COSMOS_WALLPAPER_PATH"thumb_wildworld.jpg"</IMAGE>

#endif

</APP>


