#include "mmi_features.h"

#if defined(__COSMOS_MUSICPLY__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_MUSIC_PLAYER" type="venus">
    <LAYOUT file="vapp_widget_music_player.xml" />

    <STRING id="STR_ID_VAPP_WIDGET_MUSPLY"/>
    <STRING id="STR_ID_VAPP_WIDGET_SHOW_CONTROL"/>
    <STRING id="STR_ID_VAPP_WIDGET_TAP_TO_ADD_SONG"/>

    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_ICON">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\icon_mp_widget.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BACKGROUND">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\bg.9slice.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_COVER_FRAME">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\frame.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_COVER_DEFAULT">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\cover_default.png"</IMAGE>

<THEME>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_SLIDER_BG" desc="wiget music player progress bar background"/>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_SLIDER_BAR" desc="wiget music player progress bar"/>
</THEME>

    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_NORMAL">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_Play_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_PRESS">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_Play_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PLAY_DISABLE">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_Play_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PAUSE_NORMAL">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_Pause_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PAUSE_PRESS">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_Pause_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PREV_NORMAL">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_Prev_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PREV_PRESS">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_Prev_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_PREV_DISABLE">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_Prev_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_NEXT_NORMAL">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_Next_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_NEXT_PRESS">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_Next_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_NEXT_DISABLE">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_Next_D.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_LARGE_NORMAL">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_BG1_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_LARGE_PRESS">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_BG1_P.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_SMALL_NORMAL">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_BG2_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_MUSPLY_BTN_BG_SMALL_PRESS">RES_IMG_ROOT"\\\\Widget\\\\Music\\\\btn\\\\Btn_BG2_P.png"</IMAGE>            

    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetMusicPlayerPublisher"/>
</APP>

#endif /* defined(__COSMOS_MUSICPLY__) */

