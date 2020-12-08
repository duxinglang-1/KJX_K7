# 1 "temp/res/NSSApp.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/NSSApp.c"
# 73 "temp/res/NSSApp.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 74 "temp/res/NSSApp.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 75 "temp/res/NSSApp.c" 2

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_NSS">


    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>
    <!----------------- String Id ----------------------------------------->
    <STRING id="STR_ID_SETTING_NOTIFICATIONSETTINGS"/>

    <STRING id="STR_ID_SETTING_NOTIFICATIONSETTINGS_BACKGROUND_DATA"/>

    <STRING id="STR_ID_APPNAME_NOTIFICATION_CENTER"/>
    <STRING id="STR_ID_APPNAME_NOTIFICATION_ALERT"/>
                <STRING id="STR_ID_APPNAME_BADGE_APP_ICON"/>
                <STRING id="STR_ID_APPNAME_SOUND"/>
                <STRING id="STR_ID_APPNAME_VIEW_IN_LOCK_SCREEN"/>
                <STRING id="STR_ID_APPNAME_POPUP"/>

                <STRING id="STR_ID_APPNAME_NOTIFICATION_ALERT_NONE"/>
                <STRING id="STR_ID_APPNAME_NOTIFICATION_ALERT_STATUSBAR"/>
                <STRING id="STR_ID_APPNAME_NOTIFICATION_ALERT_POPUP"/>

                <STRING id="STR_ID_SETTING_BACKGROUND_DATA_RESULT"/>

    <!----------------------Image Id----------------------------------------------------------------------->
    <!-- Notification settings image need update the image----------------------------------------SB_NSS.PBM------------------------------->
    <IMAGE id = "IMG_NSS_NCENTER">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Ncenter\\\\NCenter.png"</IMAGE>

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_NSS_APP" str = "STR_ID_SETTING_NOTIFICATIONSETTINGS" parent = "MAIN_MENU_SETTINGS_MENUID" img = "IMG_NSS_NCENTER" highlight = "mmi_nss_hilight"/>

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id="GRP_ID_NSS_GROUP"/>
    <SCREEN id="SRN_ID_NSS_APPLIST_SCREEN"/>
    <SCREEN id="SRN_ID_NSS_BACKGROUND_DATA_SCREEN"/>


</APP>
