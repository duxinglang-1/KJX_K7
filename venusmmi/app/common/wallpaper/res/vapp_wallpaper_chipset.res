#include "mmi_features.h"
#include "custresdef.h"
#include "vapp_hs_def.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_WALLPAPER_CHIPSET">
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_CHIPSET__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id = "STR_ID_WALLPAPER_VUI_LIVE_CHIPSET"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>    
    #define CHIPSET_BASE    CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Wallpaper\\\\Chipset\\\\"
    
    #ifndef __VENUS_3D_UI_ENGINE__
        #if defined(__COSMOS_MMI_PACKAGE__) && defined(__LOW_COST_SUPPORT_COMMON__)
        <!---Cosmos slim, use JPG to save ROM size. Other package use ABMv2 for faster loading ---->
        <IMAGE id="VAPP_WALLPAPER_IMG_CHIPSET_BG">CHIPSET_BASE"IC_Bg.jpg"</IMAGE>
        #else
        <IMAGE id="VAPP_WALLPAPER_IMG_CHIPSET_BG">CHIPSET_BASE"IC_Bg.png"</IMAGE>
        #endif
    #else
        <IMAGE id="VAPP_WALLPAPER_IMG_CHIPSET_BG">CHIPSET_BASE"IC_Bg.ktx"</IMAGE>
    #endif
    
    <IMAGE id="VAPP_WALLPAPER_IMG_CHIPSET_DOT">CHIPSET_BASE"dot.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_CHIPSET_TAIL">CHIPSET_BASE"tail.png"</IMAGE>

    #define COSMOS_WALLPAPER_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_CHIPSET_THUMBNAIL">COSMOS_WALLPAPER_PATH"thumb_chipset.jpg"</IMAGE>

#ifdef __VENUS_3D_UI_ENGINE__
    <BINARY3D id="VAPP_WALLPAPER_CHIPSET_VERTEX_SHADER" base_path="current">"chipset.vs"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_CHIPSET_FRAGMENT_SHADER" base_path="current">"chipset.fs"</BINARY3D>
#endif

#endif

</APP>


