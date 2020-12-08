#include "mmi_features.h"
#include "custresdef.h"
#include "gdi_lcd_config.h"
#include "vfx_sys_config.h"

#ifdef __MMI_3D_MEDIA_CENTER__
<?xml version="1.0" encoding="UTF-8"?>
<APP id="VAPP_MEDIA_CENTER" 
     name="STR_ID_VAPP_MEDIA_CENTER_AP_NAME"
     package_name = "native.mtk.media_center"
     img = "IMG_ID_VAPP_MEDIA_CENTER_APP_ICON"
     launch = "vapp_media_center_launch"
     package_proc = "vapp_media_center_package_proc" 
     type="venus">

    <MEMORY heap="700 * 1024" vrt_mem_factor="10"/>

    <!----- MMI CACHE ------->
    <CACHEDATA
         type="short"
         id="NVRAM_VAPP_MEDIA_CENTER_LAST_LAUNCHED_ITEM"
         restore_flag="TRUE">
        <DEFAULT_VALUE>[0x00,0x00]</DEFAULT_VALUE>
        <DESCRIPTION>remembers last launched app item</DESCRIPTION>
    </CACHEDATA>

    <!----- String ------->
    <STRING id="STR_ID_VAPP_MEDIA_CENTER_AP_NAME">"Media Center"</STRING>

    <!----- Images ----->
    #define MC_PATH          RES_IMG_ROOT"\\\\MediaCenter\\\\"
    <IMAGE id="IMG_ID_VAPP_MEDIA_CENTER_APP_ICON">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\MediaCenter.png"</IMAGE>
	
    <!-----------------------------------------------------  3D Section  ------------------------------------------------------>
#ifdef __COSMOS_3D_V10__

#ifndef RES_BIN_V3D_THEME_ROOT
#define RES_BIN_V3D_THEME_ROOT          RES_THEME_ROOT
#define RES_BIN_V3D_COMMON_PATH         RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Common\\\\"
#define RES_BIN_V3D_COMMON_SHADER_PATH  RES_BIN_V3D_COMMON_PATH"\\\\Shader\\\\"
#define RES_BIN_V3D_COMMON_IMAGE_PATH   RES_BIN_V3D_COMMON_PATH"\\\\Image\\\\"
#endif /* RES_BIN_V3D_THEME_ROOT */

    <!----- Background and plate ----->
	#define RES_MC_ROOT         RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\MediaCenter\\\\"
	#define RES_MC_TEXTURE          RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\MediaCenter\\\\texture\\\\"

    <IMAGE id="IMG_ID_VAPP_MEDIA_CENTER_APP_BG">RES_MC_TEXTURE"bg_2.jpg"</IMAGE>
	
    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_SCENE">RES_MC_ROOT"scene\\\\scene.scn"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_SCENE_FOCUS_ANIM">RES_MC_ROOT"scene\\\\1166_2166.ani"</BINARY3D>
    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_PLATE">RES_MC_ROOT"plate\\\\plate.scn"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_PLATE_ANIM">RES_MC_ROOT"plate\\\\plate.ani"</BINARY3D>
                 
    <!----- Title Frame ----->
    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_SCENE">RES_MC_ROOT"textBoard\\\\textBoard.scn"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_IN">RES_MC_ROOT"textBoard\\\\textBoard_0_533.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_OUT">RES_MC_ROOT"textBoard\\\\textBoard_566_1000.ani"</BINARY3D>

    <IMAGE id="IMG_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_CAMERA">RES_MC_TEXTURE"tex_icon_camera.KTX"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_GALLERY">RES_MC_TEXTURE"tex_icon_gallery.KTX"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_MUSIC">RES_MC_TEXTURE"tex_icon_music.KTX"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_RADIO">RES_MC_TEXTURE"tex_icon_radio.KTX"</IMAGE>  
    <IMAGE id="IMG_ID_VAPP_MEDIA_CENTER_TEXT_BOARD_SOUNDREC">RES_MC_TEXTURE"tex_icon_soundrec.KTX"</IMAGE> 
       
    <!----- App items ----->
    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_ITEM_CAMERA_ICON">RES_MC_ROOT"cameraIcon\\\\cameraIcon.scn"</BINARY3D>
    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_ITEM_CAMERA_FOCUS">RES_MC_ROOT"cameraFocus\\\\cameraFocus.scn"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_CAMERA_FOCUS_OPENING_ANIM">RES_MC_ROOT"cameraFocus\\\\33_1000.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_CAMERA_FOCUS_ANIM_1">RES_MC_ROOT"cameraFocus\\\\1266_5000.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_CAMERA_FOCUS_ANIM_2">RES_MC_ROOT"cameraFocus\\\\5166_10666.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_CAMERA_FOCUS_CLOSING_ANIM">RES_MC_ROOT"cameraFocus\\\\11000_11200.ani"</BINARY3D>

    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_ICON">RES_MC_ROOT"musicIcon\\\\musicIcon.scn"</BINARY3D>
    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_FOCUS">RES_MC_ROOT"musicFocus\\\\musicFocus.chr"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_FOCUS_OPENING_ANIM">RES_MC_ROOT"musicFocus\\\\33_4500.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_FOCUS_ANIM_1">RES_MC_ROOT"musicFocus\\\\4666_7000.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_FOCUS_ANIM_2">RES_MC_ROOT"musicFocus\\\\9133_9333.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_FOCUS_ANIM_3">RES_MC_ROOT"musicFocus\\\\13600_13666.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_FOCUS_ANIM_4">RES_MC_ROOT"musicFocus\\\\13666_16866.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_FOCUS_ANIM_5">RES_MC_ROOT"musicFocus\\\\17000_18533.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_MUSIC_PLY_FOCUS_CLOSING_ANIM">RES_MC_ROOT"musicFocus\\\\18666_18866.ani"</BINARY3D>

    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_ITEM_SOUND_REC_ICON">RES_MC_ROOT"soundrecIcon\\\\soundrecIcon.scn"</BINARY3D>
    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_ITEM_SOUND_REC_FOCUS">RES_MC_ROOT"soundrecFocus\\\\soundrecFocus.scn"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_SOUND_REC_FOCUS_OPENING_ANIM">RES_MC_ROOT"soundrecFocus\\\\33_4000.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_SOUND_REC_FOCUS_ANIM_1">RES_MC_ROOT"soundrecFocus\\\\4166_7866.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_SOUND_REC_FOCUS_ANIM_2">RES_MC_ROOT"soundrecFocus\\\\8000_13166.ani"</BINARY3D>	
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_SOUND_REC_FOCUS_ANIM_3">RES_MC_ROOT"soundrecFocus\\\\13333_17500.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_SOUND_REC_FOCUS_CLOSING_ANIM">RES_MC_ROOT"soundrecFocus\\\\17666_17866.ani"</BINARY3D>

    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_ITEM_FM_ICON">RES_MC_ROOT"radioIcon\\\\radioIcon.scn"</BINARY3D>
    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_ITEM_FM_FOCUS">RES_MC_ROOT"radioFocus\\\\radioFocus.scn"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_FM_FOCUS_OPENING_ANIM">RES_MC_ROOT"radioFocus\\\\33_3000.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_FM_FOCUS_ANIM_1">RES_MC_ROOT"radioFocus\\\\3166_4333.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_FM_FOCUS_CLOSING_ANIM">RES_MC_ROOT"radioFocus\\\\4500_4700.ani"</BINARY3D>	

    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_ITEM_GALLERY_ICON">RES_MC_ROOT"galleryIcon\\\\galleryIcon.scn"</BINARY3D>
    <BINARY3D id="SCN_ID_VAPP_MEDIA_CENTER_ITEM_GALLERY_FOCUS">RES_MC_ROOT"galleryFocus\\\\galleryFocus.scn"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_GALLERY_FOCUS_OPENING_ANIM">RES_MC_ROOT"galleryFocus\\\\33_4000.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_GALLERY_FOCUS_ANIM_1">RES_MC_ROOT"galleryFocus\\\\4033_8066.ani"</BINARY3D>
    <BINARY3D id="ANI_ID_VAPP_MEDIA_CENTER_ITEM_GALLERY_FOCUS_CLOSING_ANIM">RES_MC_ROOT"galleryFocus\\\\8166_8366.ani"</BINARY3D>
#endif

</APP>
#endif

