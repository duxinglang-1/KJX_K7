#include "mmi_features.h"

#ifdef __MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_WAVE__

#include "custresdef.h"
#include "vapp_hs_def.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_WALLPAPER_3D_WAVE">
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id = "STR_ID_WALLPAPER_VUI_LIVE_3D_WAVE"/>
    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #ifdef __COSMOS_MMI__
    #define RES_3D_WAVE_BASE    RES_IMG_ROOT"\\\\3D\\\\Wallpaper\\\\ripple\\\\Texture\\\\"
    #else
    #define RES_3D_WAVE_BASE    CUST_IMG_PATH"\\\\MainLCD\\\\Default\\\\3D\\\\Wallpaper\\\\ripple\\\\Texture\\\\"
    #endif
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_3D_WAVE_THUMB">RES_3D_WAVE_BASE"thumb_ripple.jpg"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_3D_WAVE_BG">RES_3D_WAVE_BASE"bg.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_3D_WAVE_LEAVE_1">RES_3D_WAVE_BASE"Leave_1.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_3D_WAVE_LEAVE_2">RES_3D_WAVE_BASE"Leave_2.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_3D_WAVE_LEAVE_3">RES_3D_WAVE_BASE"Leave_3.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_3D_WAVE_LEAVE_4">RES_3D_WAVE_BASE"Leave_4.png"</IMAGE>

    <BINARY3D id="VAPP_WALLPAPER_3D_WAVE_FRAGMENT_SHADER" base_path="current">"wave_3d.fs"</BINARY3D>
</APP>

#endif
