#include "mmi_features.h"
#include "custresdef.h"
#include "vapp_hs_def.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_WALLPAPER_SPANGLE">
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPANGLE__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id = "STR_ID_WALLPAPER_VUI_LIVE_SPANGLEGOLD"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #define SPANGLE_BASE CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Wallpaper\\\\Spangle\\\\"
    
    #ifndef __VENUS_3D_UI_ENGINE__
    <IMAGE id="VAPP_WALLPAPER_IMG_SPANGLE_SPRITE_LIST_GOLD">SPANGLE_BASE"sprite_list_gold.png"</IMAGE>
    #else
    <IMAGE id="VAPP_WALLPAPER_IMG_SPANGLE_SPRITE_LIST_GOLD">SPANGLE_BASE"sprite_list_gold.ktx"</IMAGE>
    #endif
    
    <IMAGE id="VAPP_WALLPAPER_IMG_SPANGLE_SPARK">SPANGLE_BASE"spark.png"</IMAGE>

    #define COSMOS_WALLPAPER_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_SPANGLE_THUMBNAIL">COSMOS_WALLPAPER_PATH"thumb_spangle.jpg"</IMAGE>

#ifdef __VENUS_3D_UI_ENGINE__
    <BINARY3D id="VAPP_WALLPAPER_SPANGLE_VERTEX_SHADER" base_path="current">"spangle.vs"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_SPANGLE_FRAGMENT_SHADER" base_path="current">"spangle.fs"</BINARY3D>
#endif

#endif

</APP>


