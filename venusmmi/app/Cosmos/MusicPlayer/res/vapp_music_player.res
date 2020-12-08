#include "mmi_features.h"
#ifdef __COSMOS_MUSICPLY__

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="VAPP_MUSIC_PLAYER"
     package_name = "native.mtk.musicplayer"
     name = "STR_ID_VAPP_MUSIC_PLAYER"
     img = "IMG_ID_VAPP_MUSICPLY_ICON"
     launch = "vapp_music_player_launch"
     package_proc = "vapp_music_player_package_proc" 
     type="venus">

#ifdef __COSMOS_3D_V10__
<MEMORY 
    inc="Cosmos\MusicPlayer\vapp_music_player_datatype.h, PlstSrvGprot.h"
    fg="($(VAPP_MUSICPLY_META_FILE_IMAGE_SIZE) + $(VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH)*$(VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT)*2)*$(VAPP_MUSICPLY_DECODE_COVER_BUFFER_NUM) + $(VAPP_MUSICPLY_MEDIACACHE_WORKING_SIZE) + $(VAPP_MUSICPLY_MEDIACACHE_CACHE_SIZE) + $(SRV_PLST_ARTWORK_RESIZED_WIDTH)*$(SRV_PLST_ARTWORK_RESIZED_HEIGHT)*2"
    heap="(840*1024) + SRV_PLST_MIN_MEM_CONTROL + VAPP_MUSICPLY_PLST_DB_MEM_SIZE"
    vrt_mem_factor="7.5f"
    />
#else
#ifdef LOW_COST_SUPPORT
<MEMORY 
    inc="Cosmos\MusicPlayer\vapp_music_player_datatype.h, PlstSrvGprot.h"
    fg="($(VAPP_MUSICPLY_META_FILE_IMAGE_SIZE) + $(VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH)*$(VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT)*2)*$(VAPP_MUSICPLY_DECODE_COVER_BUFFER_NUM) + $(VAPP_MUSICPLY_MEDIACACHE_WORKING_SIZE) + $(VAPP_MUSICPLY_MEDIACACHE_CACHE_SIZE) + $(SRV_PLST_ARTWORK_RESIZED_WIDTH)*$(SRV_PLST_ARTWORK_RESIZED_HEIGHT)*2"
    heap="(260*1024) + VAPP_MUSICPLY_COVER_FLOW_EXTRA_HEAP_SIZE + SRV_PLST_MIN_MEM_CONTROL + VAPP_MUSICPLY_PLST_DB_MEM_SIZE"
    vrt_mem_factor = "1.0"
    />
#else
<MEMORY 
    inc="Cosmos\MusicPlayer\vapp_music_player_datatype.h, PlstSrvGprot.h"
    fg="($(VAPP_MUSICPLY_META_FILE_IMAGE_SIZE) + $(VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH)*$(VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT)*2)*$(VAPP_MUSICPLY_DECODE_COVER_BUFFER_NUM) + $(VAPP_MUSICPLY_MEDIACACHE_WORKING_SIZE) + $(VAPP_MUSICPLY_MEDIACACHE_CACHE_SIZE) + $(SRV_PLST_ARTWORK_RESIZED_WIDTH)*$(SRV_PLST_ARTWORK_RESIZED_HEIGHT)*2"
    heap="(260*1024) + VAPP_MUSICPLY_COVER_FLOW_EXTRA_HEAP_SIZE + SRV_PLST_MIN_MEM_CONTROL + VAPP_MUSICPLY_PLST_DB_MEM_SIZE"
    />
#endif // LOW_COST_SUPPORT
#endif //__COSMOS_3D_V10__

		<!-- 1.for meta parser
			 2.for media cache cache buffer
			 3.for media cache working buffer
			 4.for JPG decode -->

    <!-----------------------------------------------------NVRAM Area----------------------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_VAPP_MUSICPLY_REPEAT_STATE">
        <DEFAULT_VALUE>[0x00]</DEFAULT_VALUE>
        <DESCRIPTION>Music player repeat state</DESCRIPTION>
    </CACHEDATA> 
    
    <CACHEDATA type="byte" id="NVRAM_VAPP_MUSICPLY_SHUFFLE_STATE">
        <DEFAULT_VALUE>[0x00]</DEFAULT_VALUE>
        <DESCRIPTION>Music player shuffle state</DESCRIPTION>
    </CACHEDATA> 
    
    <CACHEDATA type="byte" id="NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_TYPE">
        <DEFAULT_VALUE>[0x00]</DEFAULT_VALUE>
        <DESCRIPTION>Music player sound effect type</DESCRIPTION>
    </CACHEDATA> 
    
    <CACHEDATA type="byte" id="NVRAM_VAPP_MUSIC_PLAYER_SOUND_EFFECT_INDEX">
        <DEFAULT_VALUE>[0x00]</DEFAULT_VALUE>
        <DESCRIPTION>Music player sound effect index</DESCRIPTION>
    </CACHEDATA> 
    
    <CACHEDATA type="byte" id="NVRAM_VAPP_MUSICPLY_LYRICS_STATE">
        <DEFAULT_VALUE>[0x01]</DEFAULT_VALUE>
        <DESCRIPTION>Music player lyrics panel on or off</DESCRIPTION>
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
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TAB_ARTIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TAB_ALBUM"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TAB_PLAYLIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_ARTIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNKNOWN_ALBUM"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_NEW_PLAYLIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNIT_SONGS"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNIT_ALBUM"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNIT_ALBUMS"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNIT_ARTIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_UNIT_ARTISTS"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SEARCH"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_ADD_TO_PLST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_PLAY_ALL"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_FOLD"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_MORE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_NOW_PLAYING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_DELETE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_REFRESH"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_SELECT_ALL"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_UNSELECT_ALL"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_CANCEL"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_ADD"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TITLE_ADD_TO_PLST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TITLE_FAVORITE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TITLE_PLAYLIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TITLE_DELETE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_NO_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_PLAYLIST_NO_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_NO_SONG_PLAYING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SEARCH_NO_RESULT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_REFRESHING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_DELETE_HINT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_DELETE_ARTIST_HINT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_DELETE_ALBUM_HINT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_DELETE_PLST_HINT"/>
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
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_SORT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TITLE_SORT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TB_RENAME"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_REMOVE_TITLE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_RENAME_TITLE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TITLE_ADD_TO_PLST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_MENU_ADD_TO_PLST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_DEL_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_RMV_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_DEL_ARTIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_DEL_ALBUM"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_MENU_HINT_DEL_PLST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TITLE_NOW_PLAYING_PLST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_TITLE_SETTING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SUBTITILE_SOUND_SETTING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SUBTITILE_DB_SETTING"/>
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
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SETTING_RESET_DB"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_RESET_HINT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_BTN_RESET"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_SAVE_TO_FAV"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_RESETTING"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_REFRESH_HINT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_POPUP_CLOSE_HINT"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_ERROR_NOT_PAUSABLE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_DELETE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_ERROR_CANNOT_REMOVE"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SEARCH_SONG"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SEARCH_ARTIST"/>
    <STRING id="STR_ID_VAPP_MUSIC_PLAYER_SEARCH_ALBUM"/>
    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>  
    <THEME>
        <IMAGE id="IMG_ID_VAPP_MUSICPLY_ICON" desc="Main menu music player icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Music.png"</IMAGE>
    </THEME>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_NCENTER_ICON">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_music_player.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_FILE_TYPE_IMAGE">RES_IMG_ROOT"\\\\FMGR\\\\ListIcon\\\\Audio.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_PANEL_TOP">RES_IMG_ROOT"\\\\MusicPlayer\\\\bg_title.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_PANEL_LYRICS">RES_IMG_ROOT"\\\\MusicPlayer\\\\bg_lyrics.9slice.png"</IMAGE>
    //<IMAGE id="IMG_ID_VAPP_MUSICPLY_PANEL_LYRICS_SHADOW">RES_IMG_ROOT"\\\\MusicPlayer\\\\lyrics_shadow.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_PANEL_SLIDER">RES_IMG_ROOT"\\\\MusicPlayer\\\\bg_slider.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_PANEL_PLAYBACK">RES_IMG_ROOT"\\\\MusicPlayer\\\\bg_playback_btn.9slice.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_TAB_SONG">RES_IMG_ROOT"\\\\MusicPlayer\\\\tab_song.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_TAB_ARTIST">RES_IMG_ROOT"\\\\MusicPlayer\\\\tab_artist.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_TAB_ALBUM">RES_IMG_ROOT"\\\\MusicPlayer\\\\tab_album.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_TAB_PLAYLIST">RES_IMG_ROOT"\\\\MusicPlayer\\\\tab_playlist.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_TB_ADD">RES_IMG_ROOT"\\\\MusicPlayer\\\\tb_add.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_TB_PLAYER">RES_IMG_ROOT"\\\\MusicPlayer\\\\tb_player.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_TB_PLAY_ALL">RES_IMG_ROOT"\\\\MusicPlayer\\\\tb_playall.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_TB_REARRANGE">RES_IMG_ROOT"\\\\MusicPlayer\\\\tb_rearrange.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_TB_NEW_PLAYLIST">RES_IMG_ROOT"\\\\MusicPlayer\\\\tb_new_playlist.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_TB_RENAME">RES_IMG_ROOT"\\\\MusicPlayer\\\\tb_rename_list.png"</IMAGE>
    
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_ADD_FAV_N">RES_IMG_ROOT"\\\\MusicPlayer\\\\btn_fav_on.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_RMV_FAV_N">RES_IMG_ROOT"\\\\MusicPlayer\\\\btn_fav_off.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_SETTING_N">RES_IMG_ROOT"\\\\MusicPlayer\\\\btn_setting_normal.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_SETTING_P">RES_IMG_ROOT"\\\\MusicPlayer\\\\btn_setting_press.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_NONE">RES_IMG_ROOT"\\\\MusicPlayer\\\\btn_repeat_none.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_SINGLE">RES_IMG_ROOT"\\\\MusicPlayer\\\\btn_repeat_single.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_REPEAT_ALL">RES_IMG_ROOT"\\\\MusicPlayer\\\\btn_repeat_all.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_ON">RES_IMG_ROOT"\\\\MusicPlayer\\\\btn_shuffle_on.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_SHUFFLE_OFF">RES_IMG_ROOT"\\\\MusicPlayer\\\\btn_shuffle_off.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG1_N">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_BG1_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG1_P">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_BG1_P.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG2_N">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_BG2_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG2_P">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_BG2_P.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PREV_N">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_Prev_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PREV_D">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_Prev_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PLAY_N">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_Play_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PLAY_D">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_Play_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_N">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_Pause_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_NEXT_N">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_Next_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_NEXT_D">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_Next_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BACK_TO_LIST_N">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_Browser_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_NOW_PLAYING_LIST_N">RES_IMG_ROOT"\\\\MusicPlayer\\\\Btn_Nowplaylist_N.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG_2_N">RES_IMG_ROOT"\\\\Gallery\\\\VideoPlayer\\\\Btn_BG_N.png"</IMAGE> 
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG_2_P">RES_IMG_ROOT"\\\\Gallery\\\\VideoPlayer\\\\Btn_BG_P.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_BG_2_D">RES_IMG_ROOT"\\\\Gallery\\\\VideoPlayer\\\\Btn_BG_D.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PLAY_2_N">RES_IMG_ROOT"\\\\Gallery\\\\VideoPlayer\\\\Btn_Play.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_PAUSE_2_N">RES_IMG_ROOT"\\\\Gallery\\\\VideoPlayer\\\\Btn_Pause.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_BTN_STOP_2_N">RES_IMG_ROOT"\\\\Gallery\\\\VideoPlayer\\\\Btn_Stop.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_MUSICPLY_DEFAULT_DISK">RES_IMG_ROOT"\\\\MusicPlayer\\\\disk.png"</IMAGE>
#ifdef __LOW_COST_SUPPORT_COMMON__
	<IMAGE id="IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER">RES_IMG_ROOT"\\\\MusicPlayer\\\\default_cover_cf.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER_BG">RES_IMG_ROOT"\\\\MusicPlayer\\\\Default_Cover_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER_ICON">RES_IMG_ROOT"\\\\MusicPlayer\\\\Default_Cover_Sign.png"</IMAGE>
#else
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER">RES_IMG_ROOT"\\\\MusicPlayer\\\\default_cover_cf.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_DEFAULT_COVER_NO_TEXT">RES_IMG_ROOT"\\\\MusicPlayer\\\\default_cover_cf1.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_GRID_BG">RES_IMG_ROOT"\\\\Common\\\\Grid_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_SLIDER_DL">RES_IMG_ROOT"\\\\MusicPlayer\\\\Slider_Horizontal_DL_H.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_LIST_PLAYING">RES_IMG_ROOT"\\\\MusicPlayer\\\\list_playing.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_LIST_SONG">RES_IMG_ROOT"\\\\MusicPlayer\\\\list_song.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_LIST_ARTIST">RES_IMG_ROOT"\\\\MusicPlayer\\\\list_artist.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_LIST_ALBUM">RES_IMG_ROOT"\\\\MusicPlayer\\\\list_album.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_MUSICPLY_DROP_SHADOW_D">RES_IMG_ROOT"\\\\MusicPlayer\\\\shadow_d.9slice.png"</IMAGE> 
    <IMAGE id="IMG_ID_VAPP_MUSICPLY_DROP_SHADOW_R">RES_IMG_ROOT"\\\\MusicPlayer\\\\shadow_r.9slice.png"</IMAGE>

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
    
#ifdef __COSMOS_3D_V10__    

    <!--------------------------------------- 3D Resources --------------------------------------------->  
#ifndef RES_BIN_V3D_THEME_ROOT
#define RES_BIN_V3D_THEME_ROOT          RES_THEME_ROOT
#define RES_BIN_V3D_COMMON_PATH         RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Common\\\\"
#define RES_BIN_V3D_COMMON_SHADER_PATH  RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Common\\\\Shader\\\\"
#define RES_BIN_V3D_MUSIC_PLAYER_PATH   RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\MusicPlayer\\\\"
#endif /* RES_BIN_V3D_THEME_ROOT */

    <!------------------ SCENE ------------------->
    <BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_SCENE_SCENE_SCN">RES_BIN_V3D_MUSIC_PLAYER_PATH"scene\\\\Scene.scn"</BINARY3D>
    <BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_SCENE_SCENE_ANI">RES_BIN_V3D_MUSIC_PLAYER_PATH"scene\\\\scene.ani"</BINARY3D>
	
	<!------------------ DISC_MODEL ------------------->
    <BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_DISC_MODEL_DISC_MODEL_SCN">RES_BIN_V3D_MUSIC_PLAYER_PATH"Disc_Model\\\\Disc_Model.scn"</BINARY3D>
    
	<!------------------ DISC_ANI ------------------->
    <BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_DISC_ANI_DISC_ANI_ANI">RES_BIN_V3D_MUSIC_PLAYER_PATH"Disc_Ani\\\\Disc_Ani.ani"</BINARY3D>

	<!------------------ DISC_OPEN ------------------->
	<BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_DISC_OPEN_DISC_OPEN_SCN">RES_BIN_V3D_MUSIC_PLAYER_PATH"Disc_Open\\\\Disc_Open.scn"</BINARY3D>
	<BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_DISC_OPEN_DISC_OPEN_ANI">RES_BIN_V3D_MUSIC_PLAYER_PATH"Disc_Open\\\\Disc_Open.ani"</BINARY3D>
    
    <!------------------ REFLECTION SHADER ------------------->
	<BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_REFLECTION_COVER_VERT_SHADER" base_path="current">"vapp_music_player_reflection_cover_vert_shader.vs"</BINARY3D>
	<BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_REFLECTION_COVER_FRAG_SHADER" base_path="current">"vapp_music_player_reflection_cover_frag_shader.fs"</BINARY3D>
	<BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_REFLECTION_DISC_VERT_SHADER" base_path="current">"vapp_music_player_reflection_disc_vert_shader.vs"</BINARY3D>
	<BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_REFLECTION_DISC_FRAG_SHADER" base_path="current">"vapp_music_player_reflection_disc_frag_shader.fs"</BINARY3D>
	<BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_REFLECTION_LIST_VERT_SHADER" base_path="current">"vapp_music_player_reflection_list_vert_shader.vs"</BINARY3D>
	<BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_REFLECTION_LIST_FRAG_SHADER" base_path="current">"vapp_music_player_reflection_list_frag_shader.fs"</BINARY3D>
	<BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_REFLECTION_PLAYICON_VERT_SHADER" base_path="current">"vapp_music_player_reflection_playicon_vert_shader.vs"</BINARY3D>
	<BINARY3D id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_REFLECTION_PLAYICON_FRAG_SHADER" base_path="current">"vapp_music_player_reflection_playicon_frag_shader.fs"</BINARY3D>
	
	<!------------------ Image ----------------------->
	<IMAGE id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_PLAYICON">RES_BIN_V3D_MUSIC_PLAYER_PATH\\\\texture\\\\"tex_play_icon.ktx"</IMAGE>
	<IMAGE id="V3D_GEN_ID__DEFAULT_3D_MUSICPLAYER_PLAYICON_ALPHA">RES_BIN_V3D_MUSIC_PLAYER_PATH\\\\texture\\\\"tex_play_icon_alpha.ktx"</IMAGE>
  
#endif //__COSMOS_3D_V10__
  
    <!---------------------------------------Supported file type option handler: Audio --------------------------------------------->  
    <MENU id="MENU_ID_VAPP_MUSIC_PLAYER_AUDIO_OPTION" type="OPTION" str="STR_ID_VAPP_MUSIC_PLAYER">
        <MENUITEM_ID>MENU_ID_VAPP_MUSIC_PLAYER_AUDIO_OPEN</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_VAPP_MUSIC_PLAYER_AUDIO_OPEN" str="STR_ID_VAPP_MUSIC_PLAYER"/>
</APP>


<!---------------------------------------Music single player--------------------------------------------->
<APP id="VAPP_MUSIC_SINGLE_PLAYER"
     name="STR_ID_VAPP_MUSIC_SINGLE_PLAYER" 
     type="venus">
    <MEMORY cui="VCUI_MUSIC_PLAYER" heap="100*1024"/>
    
    <STRING id="STR_ID_VAPP_MUSIC_SINGLE_PLAYER"/>
</APP>

#endif __COSMOS_MUSICPLY_COVER_FLOW__

