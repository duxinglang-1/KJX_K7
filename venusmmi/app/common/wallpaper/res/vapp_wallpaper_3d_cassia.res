#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_3D_CASSIA__)
<APP id="APP_VENUS_WALLPAPER_3D_CASSIA"
    package_name="mtk.native.wallpaper.3d.cassia"
    name="STR_ID_LIVE_WALLPAPER_3D_CASSIA"
    type="venus"
    hidden_in_mainmenu="true">

    #define CASSIA_RES_PATH    RES_IMG_ROOT"\\\\3D\\\\Wallpaper\\\\Cassia\\\\"

    <MEMORY heap= "70 * 1024" />

    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_SCN"> CASSIA_RES_PATH"Cassia_scene\\\\Cassia_scene.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_SCN_CAMERA"> CASSIA_RES_PATH"Cassia_camera\\\\Cassia_camera.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_BUTTERFLY_SCN"> CASSIA_RES_PATH"Cassia_butterfly\\\\Cassia_butterfly.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_BG_TREE_SCN"> CASSIA_RES_PATH"Cassia_bg_tree\\\\Cassia_bg_tree.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_PETALS_SCN"> CASSIA_RES_PATH"Cassia_petals_1\\\\Cassia_petals_1.scn"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_PETALS_FALL_SCN"> CASSIA_RES_PATH"Cassia_petals_2\\\\Cassia_petals_2.scn"</BINARY3D>

    #define COSMOS_WP_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_3D_CASSIA_THUMBNAIL">COSMOS_WP_PATH"thumb_cassia3D.jpg"</IMAGE>
    
    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_SCN_ANIM">CASSIA_RES_PATH"Cassia_scene\\\\Cassia_scene.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_SCN_CAMERA_ANIM">CASSIA_RES_PATH"Cassia_camera\\\\Cassia_camera.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_BUTTERFLY_ANIM">CASSIA_RES_PATH"Cassia_butterfly\\\\Cassia_butterfly.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_BG_TREE_ANIM">CASSIA_RES_PATH"Cassia_bg_tree\\\\Cassia_bg_tree.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_PETALS_ANIM">CASSIA_RES_PATH"Cassia_petals_1\\\\Cassia_petals_1.ani"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_3D_CASSIA_PETALS_FALL_ANIM">CASSIA_RES_PATH"Cassia_petals_2\\\\Cassia_petals_2.ani"</BINARY3D>

</APP>
#endif


