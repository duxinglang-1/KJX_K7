#include "mmi_features.h"
#include "custresdef.h"
#include "gdi_lcd_config.h"
#include "vfx_sys_config.h"

#if defined(__MMI_COSMOS_MOVIE_THEATER__)
<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_MOVIE_THEATER" name="STR_ID_VAPP_MOVIE_THEATER_AP_NAME"
     package_name = "native.mtk.movietheater"
     img = "IMG_ID_VAPP_MOVIE_THEATER_APP_ICON"
     launch = "vapp_movie_theater_launch"
     package_proc = "vapp_movie_theater_package_proc" type="venus">

    <MEMORY
        inc="vapp_movie_theater_gprot.h, vfx_sys_config.h, MotSrvGprot.h"
        heap="150 * 1024"
        extra_base="base(SRV_MOT)"
        fg="fg(SRV_MOT) + max(VAPP_MOVIE_THEATER_INDEX_FG_MEM, max(VAPP_MOVIE_THEATER_CATEGORY_FG_MEM, VAPP_MOVIE_THEATER_DETAIL_FG_MEM))"
    />

    <!----- MMI CACHE ------->
    <CACHEDATA
         type="byte"
         id="NVRAM_VAPP_MOVIE_THEATER_OPT_DEFAULT_DRV_TYPE"
         restore_flag="TRUE">
        <DEFAULT_VALUE>[0x00]</DEFAULT_VALUE>
        <DESCRIPTION>Movie theater default storage setting</DESCRIPTION>
    </CACHEDATA>

    <!----- Layout ------->

    <!----- THEME ----->
    <THEME>
        <IMAGE id="IMG_ID_VAPP_MOVIE_THEATER_APP_ICON" desc = "Main menu movie theater icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\MovieTheater.png"</IMAGE>
    </THEME>

    <!----- String ------->
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_AP_NAME"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_MOVIE_NAME"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_DURATION"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_YEAR"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_STARRING"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_CATEGORY"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_PLOT"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_NO_VIDEO"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_DETAILS"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_PLAY"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_LAST_PLAY_TIME"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_MEMORY_FULL"/>
    <STRING id="STR_ID_VAPP_MOVIE_THEATER_POPUP_REFRESHING"/>

    <!----- Images ----->
    #define COMMON_IMG_PATH         RES_IMG_ROOT"\\\\Common\\\\Button\\\\"
    #define GALLERY_INDEX_PATH      RES_IMG_ROOT"\\\\Gallery\\\\Index\\\\"
    #define MUSIC_PLAYER_IMAGE_PATH              RES_IMG_ROOT"\\\\MusicPlayer\\\\"

    <IMAGE id="IMG_ID_VAPP_MOVIE_THEATER_DEFAULT_VIDEO_ICON">GALLERY_INDEX_PATH"icon_myvideo.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MOVIE_THEATER_DETAIL_ICON">COMMON_IMG_PATH"Details.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MOVIE_THEATER_PLAY_ICON">MUSIC_PLAYER_IMAGE_PATH"tb_playall.png"</IMAGE>

    <!-- Icon for supported file types  -->


    <!-- Supported file type option handler: Image -->
    <!-- Supported file type option handler: Video -->
    <!-- Supported file type option handler: Stream -->
</APP>
#endif

