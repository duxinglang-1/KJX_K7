#include "mmi_features.h"

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="VAPP_MUSIC_PLAYER_SLIM"
     package_name = "native.mtk.musicplayerslim"
     name = "STR_ID_VAPP_MUSIC_PLAYER"
     img = "IMG_ID_VAPP_MUSICPLY_ICON"
     launch = "vapp_music_player_slim_launch"
     type="venus">

<MEMORY 
    inc="Cosmos\MusicPlayerSlim\vapp_music_player_slim_datatype.h"
    fg="($(VAPP_MUSICPLY_META_FILE_IMAGE_SIZE) + $(VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH)*$(VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT)*2)"
    heap = "(250*1024)"
    cui="VCUI_FMGR"
    vrt_mem_factor = "1.0"
    />

		<!-- 1.for meta parser
			 2.for media cache cache buffer
			 3.for media cache working buffer
			 4.for JPG decode -->

    <!-----------------------------------------------------NVRAM Area----------------------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_TYPE">
        <DEFAULT_VALUE>[0x00]</DEFAULT_VALUE>
        <DESCRIPTION>Music player sound effect type</DESCRIPTION>
    </CACHEDATA> 

    <CACHEDATA type="byte" id="NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_INDEX">
        <DEFAULT_VALUE>[0x00]</DEFAULT_VALUE>
        <DESCRIPTION>Music player sound effect index</DESCRIPTION>
    </CACHEDATA> 
    
    <!-----------------------------------------------------Event Resource Area------------------------------------------------------>
    <EVENT id="EVT_ID_VAPP_MUSICPLY_OPEN_CLOSE" type="SENDER"/>
    <EVENT id="EVT_ID_VAPP_MUSICPLY_SHOW_HIDE" type="SENDER"/>
    <EVENT id="EVT_ID_VAPP_MUSICPLY_PLAY_START" type="SENDER"/>
    
    <RECEIVER id="EVT_ID_VAPP_MUSICPLY_OPEN_CLOSE" proc="vapp_music_player_on_open_close"/>
    <RECEIVER id="EVT_ID_VAPP_MUSICPLY_SHOW_HIDE" proc="vapp_music_player_on_show_hide"/>
    <RECEIVER id="EVT_ID_VAPP_MUSICPLY_PLAY_START" proc="vapp_music_player_on_play_start_stop"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TAB_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TAB_PLAYLIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_ARTIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONGS"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_SELECT_ALL"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_UNSELECT_ALL"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_CANCEL"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_ADD"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TITLE_DELETE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_NO_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_PLAYLIST_NO_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_NO_SONG_PLAYING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_DELETE_HINT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_BTN_DELETE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_DELETING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_ALL_SONGS"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_PLST_NAME"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_DEF_PLST_NAME"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_PLST_NAME_EXIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_MAX_PLST_NAME"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_MAX_PLST_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_REMOVE_HINT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_REMOVE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_Popup_ADDING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_REMOVING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_REMOVE_TITLE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_DEL_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_RMV_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TITLE_NOW_PLAYING_PLST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TITLE_SETTING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SUBTITILE_SOUND_SETTING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SETTING_EQ"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SETTING_VOLUME"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SETTING_SNDEFFECT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SETTING_SNDEFFECT_SUB"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SNDEFFECT_NONE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SNDEFFECT_EQ"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SNDEFFECT_3D"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SNDEFFECT_REVERB"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_ALL_SONGS_OF"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_ALL_SONGS_OF_POST"/>    
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_CLOSE_HINT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_ERROR_NOT_PAUSABLE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_DELETE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_REMOVE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_REMOVE_ALLSONGS"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_PLAY"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_MEMORY_FULL"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_ERROR_OPEN_LIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNSUPPORTED_FILE_TYPE"/>
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>  
    <THEME>
        <IMAGE id="IMG_ID_VAPP_MUSICPLY_ICON" desc="Main menu music player icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Music.png"</IMAGE>
    </THEME>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_NCENTER_ICON">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_music_player.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE">RES_IMG_ROOT"\\\\FMGR\\\\ListIcon\\\\Audio.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_PANEL_TOP">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\bg_title.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_PANEL_SLIDER">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\bg_slider.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_PANEL_PLAYBACK">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\bg_playback_btn.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_SETTING">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\btn_setting.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_NONE">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\btn_repeat_none.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_SINGLE">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\btn_repeat_single.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_ALL">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\btn_repeat_all.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_ON">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\btn_shuffle_on.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_OFF">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\btn_shuffle_off.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PREV_N">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Prev_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PREV_D">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Prev_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PREV_P">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Prev_Pressed.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Play_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Play_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PLAY_P">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Play_Pressed.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_N">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Pause_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_D">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Pause_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_P">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Pause_Pressed.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Next_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_NEXT_D">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Next_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_NEXT_P">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Btn_Next_Pressed.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BACK_TO_LIST">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\btn_songlist.png"</IMAGE>
	  <IMAGE id="IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\Default_Cover_Sign.png"</IMAGE>
	  <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_EFFECT">RES_IMG_ROOT"\\\\Redesign\\\\Music\\\\btn_effect.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_MUSICPLY_LIST_PLAYING">RES_IMG_ROOT"\\\\MusicPlayer\\\\list_playing.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_GRID_BG">RES_IMG_ROOT"\\\\Common\\\\Grid_BG.9slice.png"</IMAGE>  
    
    //Ncenter img
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PREV_D_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Music_Prev_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_NEXT_D_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Music_Next_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PREV_N_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Music_Prev_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Music_Next_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Music_Play_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Music_Play_D.png"</IMAGE>    
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Music_Pause.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG1_N_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Btn_BG1_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG1_D_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Btn_BG1_P.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG2_N_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Btn_BG2_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG2_D_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Btn_BG2_P.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG_PANEL_NC">RES_IMG_ROOT"\\\\NCenter\\\\Music\\\\Panel_BG.9slice.png"</IMAGE>
    
    <!--------------------------------------- Timer Resources --------------------------------------------->  
    <TIMER id="COSMOS_MUSICPLY_TIMER_FIND_NEXT"/>
  
    <!---------------------------------------Supported file type option handler: Audio --------------------------------------------->  
    <MENU id="MENU_ID_VAPP_MUSIC_PLAYER_AUDIO_OPTION" type="OPTION" str="STR_ID_VAPP_MUSIC_PLAYER">
        <MENUITEM_ID>MENU_ID_VAPP_MUSIC_PLAYER_AUDIO_OPEN</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_VAPP_MUSIC_PLAYER_AUDIO_OPEN" str="STR_ID_VAPP_MUSIC_PLAYER"/>
</APP>


<!---------------------------------------Music single player--------------------------------------------->
<APP id="VAPP_MUSIC_SLIM_SINGLE_PLAYER"
     name="STR_ID_VAPP_MUSIC_SINGLE_PLAYER" 
     type="venus">
<MEMORY 
    heap="100*1024" 
    fg="($(VAPP_MUSICPLY_META_FILE_IMAGE_SIZE) + $(VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH)*$(VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT)*2)"
    />
    
    <STRING id="STR_ID_VAPP_MUSIC_SINGLE_PLAYER"/>
</APP>
