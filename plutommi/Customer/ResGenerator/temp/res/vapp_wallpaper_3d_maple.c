#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_MAPLE__)
<APP id="APP_VENUS_WALLPAPER_3D_MAPLE"
    package_name="mtk.native.wallpaper.3d.maple"
    name="STR_ID_LIVE_WALLPAPER_3D_MAPLE"
    type="venus"
    hidden_in_mainmenu="true">

    #define MAPLE_RES_PATH    RES_IMG_ROOT"\\\\3D\\\\Wallpaper\\\\Maple\\\\"

    <MEMORY heap= "70 * 1024" />

    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_SCN"> MAPLE_RES_PATH"Maple_scene\\\\Maple_scene.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_SCN_CAMERA"> MAPLE_RES_PATH"Maple_camera\\\\Maple_camera.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_BUTTERFLY_SCN"> MAPLE_RES_PATH"Maple_butterfly\\\\Maple_butterfly.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_BG_TREE_SCN"> MAPLE_RES_PATH"Maple_bg_tree\\\\Maple_bg_tree.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_PETALS_SCN"> MAPLE_RES_PATH"Maple_petals_1\\\\Maple_petals_1.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_PETALS_FALL_SCN"> MAPLE_RES_PATH"Maple_petals_2\\\\Maple_petals_2.scn"</BINARY3D>

    #define COSMOS_WP_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_3D_MAPLE_THUMBNAIL">COSMOS_WP_PATH"thumb_maple3D.jpg"</IMAGE>
    
    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_SCN_ANIM">MAPLE_RES_PATH"Maple_scene\\\\Maple_scene.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_SCN_CAMERA_ANIM">MAPLE_RES_PATH"Maple_camera\\\\Maple_camera.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_BUTTERFLY_ANIM">MAPLE_RES_PATH"Maple_butterfly\\\\Maple_butterfly.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_BG_TREE_ANIM">MAPLE_RES_PATH"Maple_bg_tree\\\\Maple_bg_tree.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_PETALS_ANIM">MAPLE_RES_PATH"Maple_petals_1\\\\Maple_petals_1.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_MAPLE_PETALS_FALL_ANIM">MAPLE_RES_PATH"Maple_petals_2\\\\Maple_petals_2.ani"</BINARY3D>

</APP>
#endif


