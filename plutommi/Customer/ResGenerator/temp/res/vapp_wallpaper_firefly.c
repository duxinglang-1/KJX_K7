#include "mmi_features.h"
#include "custresdef.h"
#include "vapp_hs_def.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_WALLPAPER_FIREFLY">

#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_FIREFLY__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id = "STR_ID_WALLPAPER_VUI_LIVE_FIREFLY"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #define FIREFLY_BASE     CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Wallpaper\\\\Firefly\\\\"

    #if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_LITE_DISPLAY__)
    <IMAGE id="VAPP_WALLPAPER_IMG_FIREFLY_BG2">FIREFLY_BASE"FF_BG_M.jpg"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_FIREFLY_FG_1">FIREFLY_BASE"FF_FG1_M.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_FIREFLY_FG_2">FIREFLY_BASE"FF_FG2_M.png"</IMAGE>    
    #else
    <IMAGE id="VAPP_WALLPAPER_IMG_FIREFLY_BG2">FIREFLY_BASE"FF_BG_S.jpg"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_FIREFLY_FG_1">FIREFLY_BASE"FF_FG1_S.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_FIREFLY_FG_2">FIREFLY_BASE"FF_FG1_S.png"</IMAGE>
    #endif

    <IMAGE id="VAPP_WALLPAPER_IMG_FIREFLY_FLY6">FIREFLY_BASE"firefly_1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_FIREFLY_FLY7">FIREFLY_BASE"firefly_2.png"</IMAGE>

    #define COSMOS_WALLPAPER_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_FIREFLY_THUMBNAIL">COSMOS_WALLPAPER_PATH"thumb_firefly.jpg"</IMAGE>

#endif

</APP>


