#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_KEY_WG_MUSICPLAYER">
#if defined(__MMI_VUI_WIDGET_KEY_MUSIC_PLAYER__)

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_WG_KEY_STR_MUSIC_PLAYER"/>
    <STRING id="VAPP_WG_KEY_STR_MUSIC_PLAYER_NO_SONGS"/>
    <STRING id="VAPP_WG_KEY_STR_AUDIO_PLAYER"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\LauncherKey\\\\"
    #define WIDGET_ROOT_PATH     ROOT_PATH"Common\\\\Widget_common\\\\"
    #define MUSIC_PLAYER_WIDGET_PATH ROOT_PATH"Widget\\\\Music\\\\"

    <IMAGE id="VAPP_KL_WG_ICON_MUSIC_PLAYER">WIDGET_ROOT_PATH"widget_music_plaer.png"</IMAGE>


    //<IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_BACKGROUND">MUSIC_PLAYER_WIDGET_PATH"music_glass.png"</IMAGE>
#ifdef __MMI_MAINLCD_320X240__    
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_BACKGROUND_BG">MUSIC_PLAYER_WIDGET_PATH"music_glass_bg.png"</IMAGE>
#else
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_BACKGROUND_BG">MUSIC_PLAYER_WIDGET_PATH"music_glass_bg.9slice.png"</IMAGE>
#endif

    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_PROGRESS_BG">MUSIC_PLAYER_WIDGET_PATH"music_time_info_glass.9slice.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_PROGRESS_FG">MUSIC_PLAYER_WIDGET_PATH"progress_bar.9slice.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_PLAY">MUSIC_PLAYER_WIDGET_PATH"start.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_DEFAULT_IMG">MUSIC_PLAYER_WIDGET_PATH"music_CD.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_DEFAULT_VIDIO_IMG">MUSIC_PLAYER_WIDGET_PATH"music_video.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_SONG_INFO">MUSIC_PLAYER_WIDGET_PATH"musci_song_info_glass.9slice.png"</IMAGE>
#ifdef __MMI_MAINLCD_320X240__
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_PICK_PREV">MUSIC_PLAYER_WIDGET_PATH"music_last.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_PICK_NEXT">MUSIC_PLAYER_WIDGET_PATH"music_next.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_PICK_PREV_SELECT">MUSIC_PLAYER_WIDGET_PATH"music_last_select.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_PICK_NEXT_SELECT">MUSIC_PLAYER_WIDGET_PATH"music_next_select.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_PICK_PREV_DIS">MUSIC_PLAYER_WIDGET_PATH"music_last_disabled.png"</IMAGE>
    <IMAGE id="VAPP_KL_WG_MUSIC_PLAYER_PICK_NEXT_DIS">MUSIC_PLAYER_WIDGET_PATH"music_next_disabled.png"</IMAGE>
#endif
    
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetKeyMusicPlayerPublisher"/>
#endif    
</APP>
