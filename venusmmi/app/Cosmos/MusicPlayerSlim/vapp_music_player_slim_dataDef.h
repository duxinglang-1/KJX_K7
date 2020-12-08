

#include "mmi_features.h"
#ifdef __MMI_MUSIC_PLAYER_SLIM__

#ifndef __VAPP_MUSIC_PLAYER_DATA_DEF_H__
#define __VAPP_MUSIC_PLAYER_DATA_DEF_H__


typedef enum
{
    MUSIC_RET_OK = 0,              /* operation success. */
    MUSIC_RET_ASYNC = 1,           /* request accepted, need more time to handle. */
    
    MUSIC_RET_FAILED = -1,         /* operation failed. */
    MUSIC_RET_ERR_BEG = -100,
    MUSIC_RET_ERR_BAD_STATE,
    MUSIC_RET_ERR_BAD_PARA,        /* input parameter wrong. */
    MUSIC_RET_ERR_UNKNOWN,
    MUSIC_RET_ERR_LIST_DAMAGE,     /* song list file damaged. */
    
    MUSIC_RET_LIST_FULL,           /* playlist item reach the max number. */
    MUSIC_RET_LIST_END,            /* playing to the end of playlist. */
    MUSIC_RET_NEXT_LOOP,           /* playing to the end of playlist, and continue next loop. */
    MUSIC_RET_MEMORY_FULL,         /* storage memory full. */
    MUSIC_RET_MSDC_NOTEXIST,       /* memory card can not available. */
    MUSIC_RET_UNSUPPORTED_FILE,    /* not supported file format. */
    
    MUSIC_RET_MAX
}MusicPlayRetEnum;

typedef enum
{
    /* playlist event. */
    MUSIC_CB_OPEN = 0,             /* open playlist result. */
    MUSIC_CB_ADD,                  /* add file into playlist. */
    MUSIC_CB_DELETE,               /* delete song from playlist. */
    MUSIC_CB_DELETE_ACTIVE,        /* delele current active item. */
    MUSIC_CB_DELETE_PROGRESS,      /* delete song progress. */
    MUSIC_CB_MSDC_PLUG_OUT = 5,    /* memory card plug out. */
    MUSIC_CB_MSDC_PLUG_IN,         /* memory card plug in. */
    MUSIC_CB_USB_MS_MODE,          /* enter usb mass toryage mode. */
    MUSIC_CB_EVT_PRE_FORMAT,
    MUSIC_CB_EVT_AFT_FORMAT,

    /* playback event. */
    MUSIC_CB_PLAY = 20,
    MUSIC_CB_PAUSE,
    MUSIC_CB_RESUME,
    MUSIC_CB_STOP,
    MUSIC_CB_TERMINATE,            /* terminate play, ex, by BT device */
    MUSIC_CB_INTERRUPT,
    MUSIC_CB_INTERRUPT_RESUME,
    MUSIC_CB_BT_CONNECT,           /* while connecting to A2DP. */
    MUSIC_CB_SEEKING,              /* seeking start & done. */
    MUSIC_CB_FILE_END,             /* current song play to end. */
    MUSIC_CB_SONG_SWITCHED,        /* auto switch, manul switch song to prev\next. */
    MUSIC_CB_DUR_UPDATED,          /* MDI build cache done, call ap to update duration. */
    MUSIC_CB_LIST_END,             /* reach the end of play list. */
    
    MUSIC_CB_MAX
}MusicPlayCBEvtEnum;

typedef enum
{
    /* playlist event. */

    /* playback event. */
    MUSIC_SUB_BT_CONNECT_START,    /* sub event of bt connecting start. */
    MUSIC_SUB_BT_CONNECT_DONE,     /* sub event of bt connecting done. */
    MUSIC_SUB_SEEKING_START,       /* sub event of seeking start. */
    MUSIC_SUB_SEEKING_DONE,        /* sub event of seeking done. */
    MUSIC_SUB_SEEKING_FAILED,      /* sub event of seeking failed. */
    MUSIC_SUB_RESUME_AUTO,         /* sub event of INTERRUPT_RESUME auto. */
    MUSIC_SUB_RESUME_REQUEST,      /* sub event of INTERRUPT_RESUME request, notufy caller to resume. */
    MUSIC_SUB_MAX
}MusicPlayCBSubEvtEnum;



#endif  // __VAPP_MUSIC_PLAYER_DATA_DEF_H__
#endif  // __MMI_MUSIC_PLAYER_SLIM__
