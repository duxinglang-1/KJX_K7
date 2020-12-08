#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MAV__)
<APP id="APP_VENUS_WALLPAPER_MAV"
    package_name="mtk.native.wallpaper.mav"
    name="STR_ID_LIVE_WALLPAPER_MAV"
    type="venus" 
    hidden_in_mainmenu="true">

#ifdef __COSMOS_MMI_PACKAGE__
    <MEMORY base="2 * (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2 + 500) + 20 * 1024" />
#endif

    <STRING id="STR_ID_VAPP_WALLPAPER_MAV_CREATE_FAIL_AND_USE_DEFAULT"/>
</APP>
#endif


