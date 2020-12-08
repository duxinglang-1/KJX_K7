#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_SAKURA__)
<APP id="APP_VENUS_WALLPAPER_3D_SAKURA"
    package_name="mtk.native.wallpaper.3d.sakura"
    name="STR_ID_LIVE_WALLPAPER_3D_SAKURA"
    type="venus"
    hidden_in_mainmenu="true">

    #define SAKURA_RES_PATH    RES_IMG_ROOT"\\\\3D\\\\Wallpaper\\\\Sakura\\\\"

    <MEMORY heap= "70 * 1024" />

    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_SCN"> SAKURA_RES_PATH"Sakura_scene\\\\Sakura_scene.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_SCN_CAMERA"> SAKURA_RES_PATH"Sakura_camera\\\\Sakura_camera.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_BUTTERFLY_SCN"> SAKURA_RES_PATH"Sakura_butterfly\\\\Sakura_butterfly.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_BG_TREE_SCN"> SAKURA_RES_PATH"Sakura_bg_tree\\\\Sakura_bg_tree.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_PETALS_SCN"> SAKURA_RES_PATH"Sakura_petals_1\\\\Sakura_petals_1.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_PETALS_FALL_SCN"> SAKURA_RES_PATH"Sakura_petals_2\\\\Sakura_petals_2.scn"</BINARY3D>

    #define COSMOS_WP_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_3D_SAKURA_THUMBNAIL">COSMOS_WP_PATH"thumb_sakura3D.jpg"</IMAGE>
    
    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_SCN_ANIM">SAKURA_RES_PATH"Sakura_scene\\\\Sakura_scene.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_SCN_CAMERA_ANIM">SAKURA_RES_PATH"Sakura_camera\\\\Sakura_camera.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_BUTTERFLY_ANIM">SAKURA_RES_PATH"Sakura_butterfly\\\\Sakura_butterfly.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_BG_TREE_ANIM">SAKURA_RES_PATH"Sakura_bg_tree\\\\Sakura_bg_tree.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_PETALS_ANIM">SAKURA_RES_PATH"Sakura_petals_1\\\\Sakura_petals_1.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_SAKURA_PETALS_FALL_ANIM">SAKURA_RES_PATH"Sakura_petals_2\\\\Sakura_petals_2.ani"</BINARY3D>

</APP>
#endif


