#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_SAKURA__)
<APP id="APP_VENUS_WALLPAPER_SAKURA">

	<STRING id = "STR_ID_WALLPAPER_VUI_LIVE_SAKURA"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #define SAKURA_BASE     CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Wallpaper\\\\Sakura\\\\"
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_BENCH">SAKURA_BASE"bench.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_BRANCH">SAKURA_BASE"branch.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_GRASS">SAKURA_BASE"grass.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_BG1">SAKURA_BASE"sakura_bg.png"</IMAGE>
	<IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_BG2">SAKURA_BASE"sakura_bg1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_FG1">SAKURA_BASE"sakura_fg1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_FG2">SAKURA_BASE"sakura_fg2.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_SHADOW">SAKURA_BASE"shadow-of-branch.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_SUNSHINE1">SAKURA_BASE"sun-shine1.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_SUNSHINE2">SAKURA_BASE"sun-shine2.png"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_BUTTERFLY">SAKURA_BASE"butterfly"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_BUTTERFLY0">SAKURA_BASE"butterfly0"</IMAGE>
    <IMAGE id="VAPP_WALLPAPER_IMG_SAKURA_PETAL">SAKURA_BASE"petals"</IMAGE>
    
    #define COSMOS_WALLPAPER_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_SAKURA_THUMBNAIL">COSMOS_WALLPAPER_PATH"thumb_sakura.jpg"</IMAGE>

</APP>
#endif


