#include "mmi_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_EARTH__

#include "custresdef.h"
#include "vapp_hs_def.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_WALLPAPER_3D_EARTH">
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id = "STR_ID_WALLPAPER_VUI_LIVE_3D_EARTH"/>
    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #ifdef __COSMOS_MMI__
    #define EARTH_BASE    RES_IMG_ROOT"\\\\3D\\\\Wallpaper\\\\theEarth\\\\Texture\\\\"
    #else
    #define EARTH_BASE    CUST_IMG_PATH"\\\\MainLCD\\\\Default\\\\3D\\\\Wallpaper\\\\theEarth\\\\Texture\\\\"
    #endif

    <IMAGE id="IMG_ID_VAPP_WALLPAPER_EARTH_SPACE">EARTH_BASE"bg.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_EARTH_MOON">EARTH_BASE"theMoon.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_EARTH_DAY">EARTH_BASE"day.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_EARTH_NIGHT">EARTH_BASE"night.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_EARTH_GLOSS">EARTH_BASE"gloss.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_EARTH_THUMBNAIL">EARTH_BASE"thumb_theEarth.jpg"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_EARTH_CLOUD">EARTH_BASE"cloud.ktx"</IMAGE>

    <BINARY3D id="VAPP_WALLPAPER_EARTH_FRAGMENT_SHADER" base_path="current">"globe.fs"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_EARTH_VERTEX_SHADER" base_path="current">"globe.vs"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_EARTH_DIST">EARTH_BASE"raw.raw"</BINARY3D>
</APP>

#endif
