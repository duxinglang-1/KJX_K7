#include "mmi_features.h"
#include "custresdef.h"
#include "vapp_hs_def.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_WALLPAPER_SPACE">
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SPACE__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id = "STR_ID_WALLPAPER_VUI_LIVE_SPACE"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #define SPACE_BASE      CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Wallpaper\\\\Space\\\\"

#ifndef __VENUS_3D_UI_ENGINE__    
    #if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_LITE_DISPLAY__)
    <IMAGE id="VAPP_WALLPAPER_IMG_SPACE_BG">SPACE_BASE"STrek_BG_M.jpg"</IMAGE>
    #else
    <IMAGE id="VAPP_WALLPAPER_IMG_SPACE_BG">SPACE_BASE"STrek_BG_S.jpg"</IMAGE>
    #endif
#else
    #if !defined(__MMI_VUI_SHELL_MULTI_PAGE__) && !defined(__MMI_VUI_LITE_DISPLAY__)
    <IMAGE id="VAPP_WALLPAPER_IMG_SPACE_BG">SPACE_BASE"STrek_BG_M.ktx"</IMAGE>
    #else
    <IMAGE id="VAPP_WALLPAPER_IMG_SPACE_BG">SPACE_BASE"STrek_BG_S.ktx"</IMAGE>
    #endif
    <BINARY3D id="VAPP_WALLPAPER_SPACE_LINE_VS" base_path="current">"space_line.vs"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_SPACE_LINE_FS" base_path="current">"space_line.fs"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_SPACE_BG_VS" base_path="current">"space_bg.vs"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_SPACE_BG_FS" base_path="current">"space_bg.fs"</BINARY3D>
#endif

    #define COSMOS_WALLPAPER_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_SPACE_THUMBNAIL">COSMOS_WALLPAPER_PATH"thumb_space.jpg"</IMAGE>

#endif

</APP>


