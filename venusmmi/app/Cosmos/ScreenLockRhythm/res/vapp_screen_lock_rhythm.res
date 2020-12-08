
#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SCREEN_LOCK_RHYTHM">

    <!-- System Resource Area -------------------------------------------------->


    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_RHYTHM_NAME"/>    //screen lock name
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_RHYTHM_UNREAD_MESSAGE"/>
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_RHYTHM_MISSED_CALL"/>
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_RHYTHM_UNREAD_MESSAGE_MULTIPLE"/>
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_RHYTHM_MISSED_CALL_MULTIPLE"/>
    
    
    <!-- Image Resource Area--------------------------------------------------->
    #define ROOT_PATH RES_IMG_ROOT"\\\\ScreenLock\\\\Rhythm\\\\"

    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_BG">ROOT_PATH"bg.jpg"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_SCREENLOCK_BG">ROOT_PATH"screenlock_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_STATUSBAR_BG">ROOT_PATH"StatusBar_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_SCREENSHOT">ROOT_PATH"screenshot.jpg"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_ARROW">ROOT_PATH"arrow.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_CALL">ROOT_PATH"call.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_MESSAGE">ROOT_PATH"message.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_RHYTHM_INDICATOR_BG">ROOT_PATH"indicator_bg.9slice.png"</IMAGE>

    <!-- Event Area (Sender) -------------------------------------------------->


    <!-- Event Area (Receiver) ------------------------------------------------>

    <RECEIVER id="EVT_ID_VAPP_SCREEN_LOCK_SYS_INIT" proc="VappScreenLockRhythmPublisher"/>

</APP>

#endif /* defined(__MMI_VUI_SCREEN_LOCK_RHYTHM__)*/