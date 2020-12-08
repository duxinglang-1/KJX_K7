# 1 "temp/res/ConnectivityMainmenu.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/ConnectivityMainmenu.c"
# 190 "temp/res/ConnectivityMainmenu.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 191 "temp/res/ConnectivityMainmenu.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 192 "temp/res/ConnectivityMainmenu.c" 2



<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_CONNECTIVITY_MAINMENU"
# 206 "temp/res/ConnectivityMainmenu.c"
>
    <INCLUDE file = "GlobalMenuItems.h"/>
    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_app_bluetooth_def.h"/>






    <INCLUDE file = "mmi_rp_app_mainmenu_def.h"/>


    <INCLUDE file = "mmi_rp_app_dataaccount_def.h"/>
# 237 "temp/res/ConnectivityMainmenu.c"
    <!-- string ----------------------------------------------------------------------------------->

    <STRING id = "STR_MENU_ID_CONNECTIVITY_TEXT"/>
    <STRING id = "STR_ID_CONNECTIVITY_TEXT"/>
# 251 "temp/res/ConnectivityMainmenu.c"
    <!-- image ------------------------------------------------------------------------------------>

    <IMAGE id = "IMG_MENU_ID_CONNECTIVITY_ICON">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SubMenu\\\\Settings\\\\ST_connect.bmp"</IMAGE>
# 264 "temp/res/ConnectivityMainmenu.c"
    <!-- screen ----------------------------------------------------------------------------------->


    <!-- menu ------------------------------------------------------------------------------------->


    <MENU id = "MENU_ID_CONNECTIVITY" type = "APP_MAIN" str = "STR_MENU_ID_CONNECTIVITY_TEXT" parent = "MAIN_MENU_SETTINGS_MENUID" img = "IMG_MENU_ID_CONNECTIVITY_ICON" highlight = "HighlightConnectivity">
# 293 "temp/res/ConnectivityMainmenu.c"
        <MENUITEM_ID>MENU_ID_DATA_CONNECTION_SIM</MENUITEM_ID>


        <MENUITEM_ID>SERVICES_DATA_CONNECT_MAIN_MENU_ID</MENUITEM_ID>
# 325 "temp/res/ConnectivityMainmenu.c"
</MENU>
# 336 "temp/res/ConnectivityMainmenu.c"
</APP>
