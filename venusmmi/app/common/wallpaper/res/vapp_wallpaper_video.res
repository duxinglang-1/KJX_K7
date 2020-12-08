#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)
<APP id="APP_VENUS_WALLPAPER_VIDEO"
    package_name="mtk.native.wallpaper.video"
    name="STR_ID_LIVE_WALLPAPER_VIDEO"
    type="venus" 
    hidden_in_mainmenu="true">

#if defined(__MED_IN_ASM__)
    #if defined(__COSMOS_MMI_PACKAGE__)
    <MEMORY base="total(SRV_MDI_VDOPLY_MP4) + GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2 * 2" inc="gdi_lcd_config.h" />
    #else
    <MEMORY base="total(SRV_MDI_VDOPLY_MP4) + GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2" inc="gdi_lcd_config.h" />
    #endif
#endif

</APP>
#endif


