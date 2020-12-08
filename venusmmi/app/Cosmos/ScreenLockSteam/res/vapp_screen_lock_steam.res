#include "mmi_features.h"
#include "vapp_screen_lock_app_def.h"
#include "custresdef.h"

// 3D resource define
#ifdef __COSMOS_3D_SCREEN_LOCK__
#ifndef RES_BIN_V3D_THEME_ROOT
#define RES_BIN_V3D_THEME_ROOT          RES_THEME_ROOT
#define RES_BIN_V3D_COMMON_PATH         RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\Common\\\\"
#define RES_BIN_V3D_COMMON_SHADER_PATH  RES_BIN_V3D_COMMON_PATH"\\\\Shader\\\\"
#define RES_BIN_V3D_COMMON_IMAGE_PATH   RES_BIN_V3D_COMMON_PATH"\\\\Image\\\\"
#endif /* RES_BIN_V3D_THEME_ROOT */
#endif

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SCREEN_LOCK_STEAM" name="STR_ID_VAPP_SCREEN_LOCK_STEAM" type="venus">
    <MEMORY base="0" />

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #define ROOT_PATH RES_IMG_ROOT"\\\\ScreenLock\\\\"
    #define COMMON_IMG_PATH RES_THEME_ROOT"\\\\Default\\\\Common\\\\"
    #define ROOT_PATH_3D RES_IMG_ROOT"\\\\3D\\\\ScrLock\\\\Texture\\\\"

#ifdef __COSMOS_3D_SCREEN_LOCK__
// 3D resource
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_STEAM_SETTING_NAME"/> 

    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_STEAM_SETTING_SNAPSHOT">ROOT_PATH_3D"screenshot.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_STEAM_SETTING_ICON">ROOT_PATH_3D"icon.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_STEAM_SCREEN_LOCK_BRUSH_TEX">ROOT_PATH_3D"brush.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_STEAM_SCREEN_LOCK_FOG_ALPHA">ROOT_PATH_3D"fog_alpha.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_STEAM_SCREEN_LOCK_STEAM">ROOT_PATH_3D"steam.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_STEAM_SCREEN_LOCK_WATER_DROP">ROOT_PATH_3D"waterdrop.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_STEAM_SCREEN_LOCK_LEVEL_MAP">ROOT_PATH_3D"level.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_STEAM_SCREEN_LOCK_HALO">ROOT_PATH_3D"halo.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_STEAM_SCREEN_LOCK_EDGE_HALO">ROOT_PATH_3D"Edge_Halo.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_STEAM_SCREEN_LOCK_STATUS_BAR_BG">ROOT_PATH_3D"status_bar_empty.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_STEAM_SCREEN_LOCK_WINDOW_EDGE">ROOT_PATH_3D"glass_edge.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_STEAM_SCREEN_LOCK_BLING">ROOT_PATH_3D"bling.9slice.png"</IMAGE>
    <BINARY3D id="VAPP_STEAM_SCREEN_LOCK_STROKE_VERTEX_SHADER" base_path="current">"stroke.vs"</BINARY3D>
    <BINARY3D id="VAPP_STEAM_SCREEN_LOCK_STROKE_FRAGMENT_SHADER" base_path="current">"stroke.fs"</BINARY3D>
    <BINARY3D id="VAPP_STEAM_SCREEN_LOCK_STEAM_FRAGMENT_SHADER" base_path="current">"steam.fs"</BINARY3D>
    <BINARY3D id="VAPP_STEAM_SCREEN_LOCK_DROPLET_FRAGMENT_SHADER" base_path="current">"droplet.fs"</BINARY3D>

    <!------------------ 3d asset resource ------------------->
    // lock mesh
    <BINARY3D id="VAPP_STEAM_SCREEN_LOCK_SCN_LOCK_ICON">RES_THEME_ROOT"\\\\Default\\\\3D\\\\ScrLock\\\\Icon_Lock\\\\Icon_Lock.scn"</BINARY3D>

    // mail mesh
    <BINARY3D id="VAPP_STEAM_SCREEN_LOCK_SCN_MAIL_ICON">RES_THEME_ROOT"\\\\Default\\\\3D\\\\ScrLock\\\\Icon_Mail\\\\Icon_Mail.scn"</BINARY3D>
    <BINARY3D id="V3D_GEN_ID__DEFAULT_3D_SCRLOCK_ICON_MAIL_C_TEX_3DICON_MTL">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\ScrLock\\\\Icon_Mail_C\\\\Tex_3DIcon.mtl"</BINARY3D>

    // phone mesh
    <BINARY3D id="VAPP_STEAM_SCREEN_LOCK_SCN_PHONE_ICON">RES_THEME_ROOT"\\\\Default\\\\3D\\\\ScrLock\\\\Icon_Phone\\\\Icon_Phone.scn"</BINARY3D>
    <BINARY3D id="V3D_GEN_ID__DEFAULT_3D_SCRLOCK_ICON_PHONE_C_TEX_3DICON_MTL">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\ScrLock\\\\Icon_Phone_C\\\\Tex_3DIcon.mtl"</BINARY3D>

    // camera mesh
    <BINARY3D id="VAPP_STEAM_SCREEN_LOCK_SCN_CAMCODER_ICON">RES_THEME_ROOT"\\\\Default\\\\3D\\\\ScrLock\\\\Icon_Camera\\\\Icon_Camera.scn"</BINARY3D>

    // shake
    <BINARY3D id="VAPP_STEAM_SCREEN_LOCK_TIMELINE_SHAKE">RES_THEME_ROOT"\\\\Default\\\\3D\\\\ScrLock\\\\Shake\\\\Shake_Dummy001-node-rz.tl"</BINARY3D>

    // spin
    <BINARY3D id="VAPP_STEAM_SCREEN_LOCK_TIMELINE_SPIN">RES_THEME_ROOT"\\\\Default\\\\3D\\\\ScrLock\\\\Spin\\\\Spin_Dummy001-node-rz.tl"</BINARY3D>

    <!-----------------------------------------------------Other Resource Area------------------------------------------------------>   
    <RECEIVER id="EVT_ID_VAPP_SCREEN_LOCK_SYS_INIT" proc="VappScreenLockSteamPublisher"/>
#endif
</APP>