#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_LAUNCHER_MM"
    package_name="native.mtk.launcher_mm"
    name="STR_ID_VAPP_LAUNCHER_MM"
    hidden_in_mainmenu="true"
    type="venus">

    <MEMORY base="0"/>

    <STRING id="STR_ID_VAPP_LAUNCHER_MM"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_MM_CANNOT_CREATE_FOLDER"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_MM_UNINSTALL"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_MM_UNINSTALLING"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_MM_DELETE_FAILED"/>
    <STRING id="STR_ID_VAPP_LAUNCHER_MM_EXIT_RUNNING_APP"/>
    
    <THEME>
        <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_ICON_PREINSTALL_APP">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\App_download.png"</IMAGE>
    </THEME>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Launcher\\\\LauncherMM\\\\"
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_SCREENSHOT">ROOT_PATH"screenshot.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_STATUS_BAR_BG">ROOT_PATH"StatusBar_BG.9slice.png"</IMAGE>
    
    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Launcher\\\\LauncherMM\\\\Mainmenu\\\\"
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_ICON_BG">ROOT_PATH"Icon_BG.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_TOOLBAR_BG">ROOT_PATH"ToolBar_BG.9slice.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Launcher\\\\LauncherMM\\\\Indicator\\\\"
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_INDICATOR_DOT_H">ROOT_PATH"Indicator_g.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_INDICATOR_DOT_N">ROOT_PATH"Indicator_w.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Launcher\\\\LauncherMM\\\\Folder\\\\"
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ARROW">ROOT_PATH"Folder_Arrow.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ARROW_DOWN">ROOT_PATH"Folder_Arrow_Down.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_FOLDER_BG">ROOT_PATH"Folder_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_FOLDER_ICON_BG">ROOT_PATH"Icon_BG.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Common\\\\"
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_ICON_BADGE_BG">ROOT_PATH"Point_BG.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LAUNCHER_MM_ICON_DELETE">ROOT_PATH"MM_Delete.png"</IMAGE>

    <RECEIVER id="EVT_ID_VAPP_LAUNCHER_SYS_INIT" proc="VappLauncherMMPublisher"/>
    
</APP>

