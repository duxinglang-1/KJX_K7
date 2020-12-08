
#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__
#include "Wgui.h"
#ifndef __VAPP_MUSIC_PLAYER_SLIM_DATATYPE_H__
#define __VAPP_MUSIC_PLAYER_SLIM_DATATYPE_H__

#include "MediaCacheSrvMem.h"

/***************************************************************************** 
 * Definition
 *****************************************************************************/
enum
{
	    FONT_SIZE_ARTIST = 12,
        FONT_SIZE_SONG = 14,
#ifdef __MMI_MAINLCD_320X480__ //HVGA
		//app mode
        TITLE_BTN_X = 24,
        TITLE_BTN_Y = 37,
        TITLE_SETTING_Y = 36,
        REPEAT_BTN_Y = 72,
        REPEAT_BTN_X = 76,
        TITLE_H = 41,
        INDEX_Y = 13,
        COVER_Y = 78,
        COVER_X = 101,
        PLAYBACK_Y = 90,
        PREV_BTN_X = 50,
        PLAY_BTN_X = 87,
        PLAY_BTN_Y = 15,
        PREV_BTN_Y = 20,
        ARTIST_H = 29,
        INDEX_H = 59,
        SONG_TITLE_H = 57, //not use
        SLIDER_Y = 25,
		//cui mode
        CUI_PLAY_BTN_X = 20,
        CUI_PLAY_BTN_Y = 38,
        CUI_SLIDER_Y = 47,
        CUI_SLIDER_X = 58,
		CUI_TIME_Y = 25

#elif defined(__MMI_MAINLCD_240X320__) //QVGA
        TITLE_BTN_X = 20,
        TITLE_BTN_Y = 34,
        TITLE_SETTING_Y = 33,
        REPEAT_BTN_Y = 66,
        REPEAT_BTN_X = 36,
        TITLE_H = 37,
        INDEX_Y = 11,
        COVER_Y = 41,
        COVER_X = 89,
        PLAYBACK_Y = 74,
        PREV_BTN_X = 39,
        PLAY_BTN_X = 58,
        PLAY_BTN_Y = 10,
        PREV_BTN_Y = 15,
        ARTIST_H = 29,
        INDEX_H = 55,
        SONG_TITLE_H = 57,  //not use
        SLIDER_Y = 21,
        //cui mode
		CUI_PLAY_BTN_X = 18,
		CUI_PLAY_BTN_Y = 30,
		CUI_SLIDER_Y = 40,
		CUI_SLIDER_X = 58,
		CUI_TIME_Y = 18
#elif defined(__MMI_MAINLCD_240X400__) //WQVGA
        TITLE_BTN_X = 20,
        TITLE_BTN_Y = 34,
        TITLE_SETTING_Y = 36,
        REPEAT_BTN_Y = 68,
        REPEAT_BTN_X = 38,
        TITLE_H = 37,
        INDEX_Y = 11,
        COVER_Y = 41,
        COVER_X = 89,
        PLAYBACK_Y = 74,
        PREV_BTN_X = 39,
        PLAY_BTN_X = 58,
        PLAY_BTN_Y = 10,
        PREV_BTN_Y = 15,
        ARTIST_H = 29,
        INDEX_H = 55,
        SONG_TITLE_H = 57, //not use
        SLIDER_Y = 21,
        //cui mode
		CUI_PLAY_BTN_X = 18,
		CUI_PLAY_BTN_Y = 30,
		CUI_SLIDER_Y = 40,
		CUI_SLIDER_X = 58,
		CUI_TIME_Y = 18

#else
#endif
};

#if defined(__MMI_MAINLCD_240X320__)
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH 240
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT (320-TITLE_H-PLAYBACK_Y-MMI_STATUS_BAR_HEIGHT)

#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH 240
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT (400-TITLE_H-PLAYBACK_Y-MMI_STATUS_BAR_HEIGHT)

#elif defined(__MMI_MAINLCD_320X480__)
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH 320
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT (480-TITLE_H-PLAYBACK_Y-MMI_STATUS_BAR_HEIGHT)

#else //(__MMI_MAINLCD_480X800__)
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_WIDTH 480
#define VAPP_MUSICPLY_LARGE_ALBUM_COVER_HEIGHT (800-TITLE_H-PLAYBACK_Y-MMI_STATUS_BAR_HEIGHT)
#endif

#define VAPP_MUSICPLY_META_FILE_IMAGE_SIZE 150 * 1024 //meta parser image size
#define VAPP_MUSICPLY_MAX_SONG_NUM 1024
/***************************************************************************** 
 * Enumeration
 *****************************************************************************/

enum PageIDEnum
{
    PAGE_ID_ALL_SONGS = 100,          
    PAGE_ID_NOW_PLAYING,              // 101
    PAGE_ID_NOW_PLAYING_LIST,         // 102
    PAGE_ID_SETTING_SOUND_EFFECT,     // 104
    PAGE_ID_NONE,                     // 105
  
    PAGE_ID_END_OF_ENUM
};

enum PageSwitchMode
{
    PAGE_SWITCH_MODE_ENTER,             // 0
    PAGE_SWITCH_MODE_BACK,              // 1
    PAGE_SWITCH_MODE_SWITCH,            // 2
    PAGE_SWITCH_MODE_NONE               // 3
};

#endif /*__VAPP_MUSIC_PLAYER_SLIM_DATATYPE_H__*/
#endif /*__MMI_MUSIC_PLAYER_SLIM__*/

