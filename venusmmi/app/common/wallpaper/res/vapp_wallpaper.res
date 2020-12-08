#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_WALLPAPER"
     package_name="mtk.native.wallpaper"
     name="STR_ID_LIVE_WALLPAPER_DUMMY_NAME"
     type="venus"
     hidden_in_mainmenu="true" >
    <MEMORY fg = "max4(total(APP_VENUS_WALLPAPER_VIDEO), total(APP_VENUS_WALLPAPER_INTERGRAFX), total(APP_VENUS_WALLPAPER_FRAME_VIDEO), total(VAPP_WALLPAPER_MRE))"
            base = "total(APP_VENUS_WALLPAPER_3D_SAKURA)" />
</APP>

<APP id = "APP_VENUS_WALLPAPER_TOTAL" 
     name="STR_ID_LIVE_WALLPAPER_TOTAL_DUMMY_NAME" 
     type="venus" 
     hidden_in_mainmenu="true">
    <MEMORY base = "total(APP_VENUS_WALLPAPER)"/>

    #if defined(__MED_IN_ASM__) && !defined(__COSMOS_MMI_PACKAGE__)
        #if (defined(STREAM_SUPPORT) && defined(__MMI_MEDIA_PLAYER__))
        <APPCONCURRENT concurrent_w_order = "SRV_MDI_AUDPLY, APP_VENUS_WALLPAPER_TOTAL, APP_IDLE"/>
        <APPCONCURRENT concurrent_w_order = "SRV_MDI_STREAMING, APP_VENUS_WALLPAPER_TOTAL, APP_IDLE"/>
        #else
        <APPCONCURRENT concurrent_w_order = "APP_VENUS_WALLPAPER_TOTAL, APP_IDLE"/>
        #endif
    #endif
</APP>
