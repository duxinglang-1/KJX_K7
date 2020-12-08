#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SCREEN_LOCK_SHUTTLE" 
     name="STR_ID_VAPP_SCREEN_LOCK_SHUTTLE"
     package_name = "native.mtk.screen_lock_shuttle"
     img = "IMG_ID_VAPP_SCREEN_LOCK_SHUTTLE_ICON"
     launch = "vapp_screen_lock_shuttle_launch"
     package_proc = "vapp_screen_lock_shuttle_proc"
     type="venus">
    
    <MEMORY heap="10*1024" cui="VAPP_SCR_LOCK_SETTING"/>
    
    <STRING id="STR_ID_VAPP_SCREEN_LOCK_SHUTTLE"/>

    <THEME>
        <IMAGE id="IMG_ID_VAPP_SCREEN_LOCK_SHUTTLE_ICON" desc="Sreen Lock Shuttle">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\ScreenLock.png"</IMAGE>
    </THEME>
</APP>
