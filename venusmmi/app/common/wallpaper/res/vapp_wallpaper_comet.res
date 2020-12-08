#include "mmi_features.h"
#include "custresdef.h"
#include "vapp_hs_def.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_WALLPAPER_COMET">
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_COMET__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id = "STR_ID_WALLPAPER_VUI_LIVE_COMET"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define COMET_BASE      CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Wallpaper\\\\Comet\\\\"
    
    #if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_LITE_DISPLAY__)
    <IMAGE id="VAPP_WALLPAPER_IMG_COMET_MOUNTAIN">COMET_BASE"SNight_FG_M.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_COMET_BG">COMET_BASE"SNight_BG_M.jpg"</IMAGE>
    #else
    <IMAGE id="VAPP_WALLPAPER_IMG_COMET_MOUNTAIN">COMET_BASE"SNight_FG_S.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_COMET_BG">COMET_BASE"SNight_BG_S.jpg"</IMAGE>
    #endif
    
    
    <IMAGE id="VAPP_WALLPAPER_IMG_COMET_DOT">COMET_BASE"dot.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_COMET_TAIL">COMET_BASE"tail.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_COMET_EXPLODE">COMET_BASE"explode.png"</IMAGE>

    #define COSMOS_WALLPAPER_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_COMET_THUMBNAIL">COSMOS_WALLPAPER_PATH"thumb_comet.jpg"</IMAGE>

#endif

</APP>


