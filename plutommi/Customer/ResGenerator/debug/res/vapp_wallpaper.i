# 1 "temp/res/vapp_wallpaper.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/vapp_wallpaper.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 2 "temp/res/vapp_wallpaper.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 3 "temp/res/vapp_wallpaper.c" 2

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






        <APPCONCURRENT concurrent_w_order = "APP_VENUS_WALLPAPER_TOTAL, APP_IDLE"/>


</APP>
