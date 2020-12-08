
#include "MMI_features.h"

#if defined(__MMI_VUI_SCREEN_LOCK_FACTORY__) && defined(__MMI_VUI_SCREEN_LOCK_PAINTING__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "CustResDef.h"


/*****************************************************************************
 * XML
 *****************************************************************************/

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SCREEN_LOCK_PAINTING">

    <!-- System Resource Area -------------------------------------------------->


    <!-- String Resource Area-------------------------------------------------->
	<STRING id="STR_ID_VAPP_SCREEN_LOCK_PAINTING_NAME"/>   //Painting name

    <!-- Image Resource Area--------------------------------------------------->
	#define ROOT_PATH RES_IMG_ROOT"\\\\ScreenLock\\\\ScreenLockPainting\\\\"
	#define LOCK_SCREEN_BAR_TIME_PATH ROOT_PATH"time\\\\"

	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_BG">ROOT_PATH"bg.jpg"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_FLY01">ROOT_PATH"Dragonfly01.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_FLY02">ROOT_PATH"Dragonfly02.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_INDICATOR">ROOT_PATH"indicator.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_BG">ROOT_PATH"time_bg.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_00">LOCK_SCREEN_BAR_TIME_PATH"lock_screen_bar_time_0.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_01">LOCK_SCREEN_BAR_TIME_PATH"lock_screen_bar_time_1.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_02">LOCK_SCREEN_BAR_TIME_PATH"lock_screen_bar_time_2.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_03">LOCK_SCREEN_BAR_TIME_PATH"lock_screen_bar_time_3.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_04">LOCK_SCREEN_BAR_TIME_PATH"lock_screen_bar_time_4.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_05">LOCK_SCREEN_BAR_TIME_PATH"lock_screen_bar_time_5.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_06">LOCK_SCREEN_BAR_TIME_PATH"lock_screen_bar_time_6.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_07">LOCK_SCREEN_BAR_TIME_PATH"lock_screen_bar_time_7.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_08">LOCK_SCREEN_BAR_TIME_PATH"lock_screen_bar_time_8.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_09">LOCK_SCREEN_BAR_TIME_PATH"lock_screen_bar_time_9.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_TIME_DOT">LOCK_SCREEN_BAR_TIME_PATH"lock_screen_bar_time_dot.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_FISH">ROOT_PATH"fish"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_STATUSBAR_BG">ROOT_PATH"StatusBar_BG.9slice.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PAINTING_SCREENSHOT">ROOT_PATH"screenshot.jpg"</IMAGE>

    <!-- Event Area (Sender) -------------------------------------------------->


    <!-- Event Area (Receiver) ------------------------------------------------>

    <RECEIVER id="EVT_ID_VAPP_SCREEN_LOCK_SYS_INIT" proc="VappScreenLockPaintingPublisher"/>

</APP>

#endif /* defined(__MMI_VUI_SCREEN_LOCK_FACTORY__)  && defined(__MMI_VUI_SCREEN_LOCK_PAINTING__)*/

