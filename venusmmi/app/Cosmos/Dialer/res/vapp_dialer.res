#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_DIALER"
    package_name="native.mtk.dialer"
    name="STR_ID_VAPP_DIALER"
    img="IMG_ID_VAPP_DIALER"
    launch="vapp_dialer_launch_from_phb" type="venus">

#ifndef __LOW_COST_SUPPORT_COMMON__
    <MEMORY heap="500*1024" cui="VCUI_LANGUAGE_SETTING"/>
#else
    <MEMORY heap="400*1024" cui="VCUI_LANGUAGE_SETTING"/>
#endif

    <LAYOUT file="vapp_dialer.xml"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_DIALER_SEARCH_CALLLOG">RES_THEME_ROOT"\\\\DEFAULT\\\\DIALPAD\\\\LISTICON\\\\calllog.png"</IMAGE>
    <IMAGE id="IMG_ID_DIALER_SEARCH_CONTACT">RES_THEME_ROOT"\\\\DEFAULT\\\\DIALPAD\\\\LISTICON\\\\contact.png"</IMAGE>

    <THEME>
        <IMAGE id="IMG_ID_VAPP_DIALER" desc="IMG_ID_VAPP_DIALER">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Call.png"</IMAGE>
#if defined (__MMI_MAINLCD_240X320__) && defined (__MMI_DIALER_SLIM__)

#else
        <IMAGE id="IMG_ID_DIALER_KEY1" desc="IMG_ID_DIALER_KEY1"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY2" desc="IMG_ID_DIALER_KEY2"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY3" desc="IMG_ID_DIALER_KEY3"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY4" desc="IMG_ID_DIALER_KEY4"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY5" desc="IMG_ID_DIALER_KEY5"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY6" desc="IMG_ID_DIALER_KEY6"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY7" desc="IMG_ID_DIALER_KEY7"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY8" desc="IMG_ID_DIALER_KEY8"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY9" desc="IMG_ID_DIALER_KEY9"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY0" desc="IMG_ID_DIALER_KEY0"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_POUND" desc="IMG_ID_DIALER_POUND"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_STAR" desc="IMG_ID_DIALER_STAR"></IMAGE>
#endif
        <IMAGE id="IMG_ID_DIALER_ADD_CONTACT_DISABLE" desc="IMG_ID_DIALER_ADD_CONTACT_DISABLE"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_ADD_CONTACT" desc="IMG_ID_DIALER_ADD_CONTACT"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_ADD_CONTACT_PRESS" desc="IMG_ID_DIALER_ADD_CONTACT_PRESS"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY_BUTTON_DISABLE" desc="IMG_ID_DIALER_KEY_BUTTON_DISABLE"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY_BUTTON" desc="IMG_ID_DIALER_KEY_BUTTON"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEY_BUTTON_PRESS" desc="IMG_ID_DIALER_KEY_BUTTON_PRESS"></IMAGE>
#ifdef __MMI_VIDEO_TELEPHONY__
        <IMAGE id="IMG_ID_DIALER_VIDEO_CALL_DISABLE" desc="IMG_ID_DIALER_VIDEO_CALL_DISABLE"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_VIDEO_CALL" desc="IMG_ID_DIALER_VIDEO_CALL"></IMAGE>
#endif
        <IMAGE id="IMG_ID_DIALER_VIDEO_CALL_PRESS" desc="IMG_ID_DIALER_VIDEO_CALL_PRESS"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_BACKSPACE_DISABLE" desc="IMG_ID_DIALER_BACKSPACE_DISABLE"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_BACKSPACE" desc="IMG_ID_DIALER_BACKSPACE"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_BACKSPACE_PRESS" desc="IMG_ID_DIALER_BACKSPACE_PRESS"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_EMERGENCY_DISABLE" desc="IMG_ID_DIALER_EMERGENCY_DISABLE"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_EMERGENCY" desc="IMG_ID_DIALER_EMERGENCY"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_EMERGENCY_PRESS" desc="IMG_ID_DIALER_EMERGENCY_PRESS"></IMAGE>
        //<IMAGE id="IMG_ID_DIALER_SIM1_CALL_DISABLE" desc="IMG_ID_DIALER_SIM1_CALL_DISABLE"></IMAGE>
        //<IMAGE id="IMG_ID_DIALER_SIM1_CALL" desc="IMG_ID_DIALER_SIM1_CALL"></IMAGE>
        //<IMAGE id="IMG_ID_DIALER_SIM1_CALL_PRESS" desc="IMG_ID_DIALER_SIM1_CALL_PRESS"></IMAGE>
        //<IMAGE id="IMG_ID_DIALER_SIM2_CALL_DISABLE" desc="IMG_ID_DIALER_SIM2_CALL_DISABLE"></IMAGE>
        //<IMAGE id="IMG_ID_DIALER_SIM2_CALL" desc="IMG_ID_DIALER_SIM2_CALL"></IMAGE>
        //<IMAGE id="IMG_ID_DIALER_SIM2_CALL_PRESS" desc="IMG_ID_DIALER_SIM2_CALL_PRESS"></IMAGE>

        <IMAGE id="IMG_ID_DIALER_SPEED_DIAL_BALL" desc="IMG_ID_DIALER_SPEED_DIAL_BALL"></IMAGE>
        //<IMAGE id="IMG_ID_DIALER_EDITOR" desc="IMG_ID_DIALER_EDITOR"></IMAGE>
        //<IMAGE id="IMG_ID_DIALER_CALL_ICON" desc="IMG_ID_DIALER_CALL_ICON"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_EDITOR_BG" desc="IMG_ID_DIALER_EDITOR_BG"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_KEYBOARD_BG" desc="IMG_ID_DIALER_KEYBOARD_BG"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_TEXT_BG01" desc="IMG_ID_DIALER_TEXT_BG01"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_TEXT_BG02" desc="IMG_ID_DIALER_TEXT_BG02"></IMAGE>
#ifdef __MMI_PHB_SPEED_DIAL__ 

        <IMAGE id="IMG_ID_DIALER_SPEED_2" desc="IMG_ID_DIALER_SPEED_2"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_SPEED_3" desc="IMG_ID_DIALER_SPEED_3"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_SPEED_4" desc="IMG_ID_DIALER_SPEED_4"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_SPEED_5" desc="IMG_ID_DIALER_SPEED_5"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_SPEED_6" desc="IMG_ID_DIALER_SPEED_6"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_SPEED_7" desc="IMG_ID_DIALER_SPEED_7"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_SPEED_8" desc="IMG_ID_DIALER_SPEED_8"></IMAGE>
        <IMAGE id="IMG_ID_DIALER_SPEED_9" desc="IMG_ID_DIALER_SPEED_9"></IMAGE>
#endif        

        <COLOR id="COL_ID_DIALER_HINT_BG"/>
    </THEME>

    <!--String ID----------------------------------------------------------------------------------------->
    <STRING id="STR_ID_VAPP_DIALER"/>
    <STRING id="STR_ID_VAPP_DIALER_EMERGENCY"/>
    //<STRING id="STR_ID_VAPP_DIALER_EDIT_BEFORE_CALL"/>
    <STRING id="STR_ID_VAPP_DIALER_VOICE_MAIL"/>

    <!--Timer ID----------------------------------------------------------------------------------------->
    <TIMER id="PHB_QUICK_SEARCH_TIMER"/>
    <TIMER id="DIALER_LONG_PRESS_TIMER"/>

</APP>

