#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_INTERACTIVE_VIDEO__)
<APP id="APP_VENUS_WALLPAPER_FRAME_VIDEO"
    package_name="mtk.native.wallpaper.frame.video"
    name="STR_ID_LIVE_WALLPAPER_FRAME_VIDEO"
    type="venus"
    hidden_in_mainmenu="true">

#if defined(__COSMOS_MMI_PACKAGE__) || defined(__MED_IN_ASM__)
    
    #if defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__)
        #if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (24 == MAIN_MEDIA_LAYER_BITS_PER_PIXEL)
        <MEMORY base="1 * (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*3 + 500) + 20 * 1024" />
        #else
        <MEMORY base="1 * (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2 + 500) + 20 * 1024" />
        #endif
    #elif defined(__FS_ASYNC_SUPPORT__) && !(defined(__LOW_COST_SUPPORT_COMMON__) && defined(__COSMOS_MMI_PACKAGE__))
        #if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (24 == MAIN_MEDIA_LAYER_BITS_PER_PIXEL)
        <MEMORY base="3 * (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*3 + 500) + 20 * 1024" />
        #else
        <MEMORY base="3 * (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2 + 500) + 20 * 1024" />
        #endif
    #else
        #if defined(MAIN_MEDIA_LAYER_BITS_PER_PIXEL) && (24 == MAIN_MEDIA_LAYER_BITS_PER_PIXEL)
        <MEMORY base="2 * (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*3 + 500) + 20 * 1024" />
        #else
        <MEMORY base="2 * (GDI_LCD_WIDTH*GDI_LCD_HEIGHT*2 + 500) + 20 * 1024" />
        #endif
    #endif
#endif
#if !defined(__COSMOS_MMI_PACKAGE__)
    <STRING id="STR_ID_VAPP_WALLPAPER_CREATE_FAIL_AND_USE_DEFAULT"/>
#endif
    
</APP>
#endif


