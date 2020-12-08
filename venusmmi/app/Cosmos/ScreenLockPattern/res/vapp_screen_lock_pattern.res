#include "mmi_features.h"
#include "custresdef.h"

#ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SCREEN_LOCK_PATTERN" name="STR_ID_VAPP_SCREEN_LOCK_PATTERN" type="venus">
    <MEMORY base="0" />

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_NAME"/>
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_SET"/>
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_CONFIRM"/>
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_RETRY"/>
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_CONTINUE"/>
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_BALLOON_CONFIRM_OK"/>
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_PATTERN_SETTING_BALLOON_CONFIRM_FAIL"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_IMG_ROOT"\\\\ScreenLock\\\\ScreenLockPattern\\\\"

    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PATTERN_ICON">ROOT_PATH"icon.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PATTERN_SCREENSHOT">ROOT_PATH"screenshot.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PATTERN_ARROW_G">ROOT_PATH"Arrow_G.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PATTERN_ARROW_R">ROOT_PATH"Arrow_R.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PATTERN_CIRCLE_G">ROOT_PATH"Circle_G.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PATTERN_CIRCLE_R">ROOT_PATH"Circle_R.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PATTERN_DOT">ROOT_PATH"Dot.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PATTERN_LINE">ROOT_PATH"Line.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PATTERN_TIME_BG">ROOT_PATH"Time_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_PATTERN_STATUSBAR_BG">ROOT_PATH"StatusBar_BG.9slice.png"</IMAGE>

    <RECEIVER id="EVT_ID_VAPP_SCREEN_LOCK_SYS_INIT" proc="VappScreenLockPatternPublisher"/>
</APP>

#endif // #ifdef __MMI_VUI_SCREEN_LOCK_PATTERN__

