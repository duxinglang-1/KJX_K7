#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_DRAWER"
    package_name="native.mtk.drawer"
    name="STR_ID_VAPP_DRAWER"
    img="IMG_ID_VAPP_DRAWER_ICON_MAINMENU"
    launch="vapp_drawer_launch" type="venus">

    <STRING id="STR_ID_VAPP_DRAWER"/>
    <STRING id="STR_ID_VAPP_DRAWER_UNINSTALL"/>
    <STRING id="STR_ID_VAPP_DRAWER_UNINSTALLING"/>
    <STRING id="STR_ID_VAPP_DRAWER_EXIT_RUNNING_APP"/>

    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\"
    <IMAGE id="IMG_ID_VAPP_DRAWER_BG">ROOT_PATH"BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_FONT_BG">ROOT_PATH"Font_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_BG">ROOT_PATH"Icon_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_SHADOW">ROOT_PATH"Icon_Shadow.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_TOOLBAR_BG">ROOT_PATH"ToolBar_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_TOOLBAR_SHADOW">ROOT_PATH"ToolBar_Shadow.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_BADGE_BG">ROOT_PATH"Point_BG.9slice.png"</IMAGE>

    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Indicator\\\\"
    <IMAGE id="IMG_ID_VAPP_DRAWER_INDICATOR_BG">ROOT_PATH"Indicator_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_INDICATOR_DOT_H">ROOT_PATH"Indicator_g.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_INDICATOR_DOT_N">ROOT_PATH"Indicator_w.png"</IMAGE>

    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\"
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_HOME">ROOT_PATH"Home.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_MAINMENU">ROOT_PATH"MainMenu.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_MUSIC">ROOT_PATH"Music.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_PREINSTALL_APP">ROOT_PATH"App_download.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_JAVA">ROOT_PATH"Java.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_MRE">ROOT_PATH"MRE.png"</IMAGE>

#ifdef __MMI_MAINLCD_480X800__
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_JAVA_RESIZE">ROOT_PATH"Java_add.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_MRE_RESIZE">ROOT_PATH"MRE_add.png"</IMAGE>
#else
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_JAVA_RESIZE">ROOT_PATH"Java_Resize.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_DRAWER_ICON_MRE_RESIZE">ROOT_PATH"MRE_Resize.png"</IMAGE>
#endif

    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Widget\\\\"
    <IMAGE id="IMG_ID_VAPP_DRAWER_APP_UNINSTALL">ROOT_PATH"Uninstall.png"</IMAGE>

</APP>

