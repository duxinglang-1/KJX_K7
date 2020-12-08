#include "mmi_features.h"
#include "custresdef.h"
#include "vapp_hs_def.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_WALLPAPER_WAVE">
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_WAVE__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id = "STR_ID_WALLPAPER_VUI_LIVE_WAVE"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define REFLECT_BASE    ROOT_PATH"Wallpaper\\\\Reflection\\\\"

#if defined(__MMI_VUI_SHELL_MULTI_PAGE__) || defined(__MMI_VUI_LITE_DISPLAY__)
    <IMAGE id="VAPP_WALLPAPER_IMG_REFLECTED">REFLECT_BASE"JZG_BG_S.jpg"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_REFLECTEDFG">REFLECT_BASE"JZG_FG_S.png"</IMAGE>
#else
    <IMAGE id="VAPP_WALLPAPER_IMG_REFLECTED">REFLECT_BASE"JZG_BG_M.jpg"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_REFLECTEDFG">REFLECT_BASE"JZG_FG_M.png"</IMAGE>
#endif

    #define COSMOS_WALLPAPER_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_WAVE_THUMBNAIL">COSMOS_WALLPAPER_PATH"thumb_wave.jpg"</IMAGE>
#endif
</APP>


