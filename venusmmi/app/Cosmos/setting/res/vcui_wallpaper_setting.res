#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VCUI_WALLPAPER_SETTING" name="STR_ID_VAPP_WALLPAPER_SETTING_CUI" type="venus">
    <MEMORY heap="1024*100" 
        #ifndef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
            #ifndef __LOW_COST_SUPPORT_COMMON__
            cui="VCUI_IMGCLIP"
            #endif
            />
        #else
            #ifndef __LOW_COST_SUPPORT_COMMON__
            cui="max(VCUI_IMGCLIP, VCUI_GALLERY_VIDEO_PLAYER)"
            #else
            cui="VCUI_GALLERY_VIDEO_PLAYER"
            #endif
            fg="total(SRV_MDI_VDOPLY_MP4)+GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2" 
            inc="../../../venusmmi/app/Cosmos/setting/res/vapp_setting_memory.h"/>
        #endif
    <STRING id = "STR_ID_VAPP_WALLPAPER_SETTING_CUI"/>

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    #define HOME_IMG_ROOT       RES_IMG_ROOT"\\\\Launcher\\\\LauncherCosmos\\\\Home\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_SETTING_CUI_TOOBAR_WALLPAPER">HOME_IMG_ROOT"icon_wallpaper.png"</IMAGE>
#endif

</APP>