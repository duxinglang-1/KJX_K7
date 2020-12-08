#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_AUDIOPLAYER">
#if defined(__MMI_VUI_HOMESCREEN_AUDIO_PLAYER__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_AUDIO_PLAYER"/>
    <STRING id="VAPP_HS_STR_AUDPLY_PLAYLIST_NOT_READY"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH     ROOT_PATH"Widget\\\\"
    #define AUDPLAYER_WIDGET_PATH WIDGET_PATH"Audio\\\\"

#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    #define VUI_HS_IMG_TYPE "BMP"
#else
    #define VUI_HS_IMG_TYPE "PNG"
#endif

    <IMAGE id="VAPP_HS_IMG_WG_ICON_AUDPLY">WIDGET_PATH"Widgeticon_AudioPlayer.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_BG">AUDPLAYER_WIDGET_PATH"Audio_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_NEXT_UP">AUDPLAYER_WIDGET_PATH"Audio_next_up.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_NEXT_DOWN">AUDPLAYER_WIDGET_PATH"Audio_next_down.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_NEXT_DIS">AUDPLAYER_WIDGET_PATH"Audio_next_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PREV_UP">AUDPLAYER_WIDGET_PATH"Audio_prev_up.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PREV_DOWN">AUDPLAYER_WIDGET_PATH"Audio_prev_down.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PREV_DIS">AUDPLAYER_WIDGET_PATH"Audio_prev_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PLAY_UP">AUDPLAYER_WIDGET_PATH"Audio_play_up.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PLAY_DOWN">AUDPLAYER_WIDGET_PATH"Audio_play_down.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PLAY_DIS">AUDPLAYER_WIDGET_PATH"Audio_play_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PAUSE_UP">AUDPLAYER_WIDGET_PATH"Audio_pause_up.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PAUSE_DOWN">AUDPLAYER_WIDGET_PATH"Audio_pause_down.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PAUSE_DIS">AUDPLAYER_WIDGET_PATH"Audio_pause_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_STOP_UP">AUDPLAYER_WIDGET_PATH"Audio_stop_up.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_STOP_DOWN">AUDPLAYER_WIDGET_PATH"Audio_stop_down.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_STOP_DIS">AUDPLAYER_WIDGET_PATH"Audio_stop_dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PROGRESS_BG">AUDPLAYER_WIDGET_PATH"Audio_progress_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PROGRESS_FG">AUDPLAYER_WIDGET_PATH"Audio_progress_COL.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_AUDPLY_PROGRESS_PROCESS">AUDPLAYER_WIDGET_PATH"Audio_progressing.png"</IMAGE>
#endif

</APP>

