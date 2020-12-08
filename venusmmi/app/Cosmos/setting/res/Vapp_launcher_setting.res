#include "mmi_features.h"
#include "custresdef.h"
#include "custom_mmi_default_value.h"
#include "../../../venusmmi/app/Cosmos/setting/res/vapp_setting_dlui_memory.h"

<?xml version="1.0" encoding="UTF-8"?>

#if defined(__MMI_THEMES_APPLICATION__) || defined(__MMI_VUI_APP_ICON_ROBOT__) || defined(__MMI_VUI_APP_ICON_MM__) || defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__) \
    || defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__) || defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__)
<APP id="VAPP_LAUNCHER_SETTING" name="STR_ID_VAPP_SETTING_LAUNCHER_SETTING" type="venus">
    <MEMORY heap = "300*1024" 
    fg = "VAPP_SETTINGS_LAUNCHER_MAX_FG_MEMORY"
    cui="VCUI_THEME_SWITCH"
    inc = "../../../venusmmi/app/Cosmos/setting/res/vapp_setting_dlui_memory.h"/>  

    // String Id LAUNCHER SETTING
    <STRING id = "STR_ID_VAPP_SETTING_LAUNCHER_SETTING"/>
    <STRING id = "STR_ID_VAPP_SETTING_CHOOSE_LAUNCHER"/>
    <STRING id = "STR_ID_VAPP_SETTING_LAUNCHER_SWITCHING"/>
    <STRING id = "STR_ID_VAPP_SETTING_LAUNCHER_CHANGED"/>
    <STRING id = "STR_ID_VAPP_SETTING_SYSTEM_PROVIDE"/>
    <STRING id = "STR_ID_VAPP_SETTING_USER_DOWNLOAD"/>

    // Image Id
    <IMAGE id = "IMG_ID_VAPP_SETTING_LAUNCHER_SELECT">RES_IMG_ROOT"\\\\Common\\\\ScreenShot\\\\icon_select.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VAPP_SETTING_LAUNCHER_BG_L">RES_IMG_ROOT"\\\\Common\\\\ScreenShot\\\\Large_BG.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VAPP_SETTING_LAUNCHER_BG_S">RES_IMG_ROOT"\\\\Common\\\\ScreenShot\\\\Small_BG.9slice.png"</IMAGE>;       
</APP>
#endif

#if defined(__MMI_VUI_SETTING_SCREEN_LOCK_SELECTION__)
<APP id="VAPP_SCR_LOCK_SETTING" name="STR_ID_VAPP_SETTING_SCREEN_LOCK_SETTING" type="venus">
    <MEMORY heap = "300*1024" 
    fg = "VAPP_SETTINGS_SCR_LOCK_MAX_FG_MEMORY"
    cui="VCUI_THEME_SWITCH"
    inc = "../../../venusmmi/app/Cosmos/setting/res/vapp_setting_dlui_memory.h"/>  
    // String Id SCREEN_LOCK
    <STRING id = "STR_ID_VAPP_SETTING_SCREEN_LOCK_SETTING"/>    
    <STRING id = "STR_ID_VAPP_SETTING_CHOOSE_SCREEN_LOCK"/>
    <STRING id = "STR_ID_VAPP_SETTING_SCREEN_LOCK_SWITCHING"/>
    <STRING id = "STR_ID_VAPP_SETTING_SCREEN_LOCK_CHANGED"/>
    
</APP>
#endif
