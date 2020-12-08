#include "mmi_features.h"
#include "custresdef.h"

#if defined(__MMI_VUI_LAUNCHER_COSMOS__) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)
<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_LAUNCHER_COSMOS_MM_BARREL_SETTING" name="STR_ID_VAPP_LAUNCHER_COSMOS_MM_BARREL_SETTING_NAME"
     package_name = "native.mtk.launcher_cosmos_mm_barrel_setting"
     img = "IMG_ID_VAPP_LAUNCHER_COSMOS_MM_BARREL_SETTING_APP_ICON"
     launch="vapp_launcher_cosmos_mm_barrel_setting_launch"
     hidden_in_mainmenu="true"
     type="venus">
     
    <MEMORY base="0"/>
    
    <!----- MMI CACHE ------->
    <!----- Set default switch FX as Roll ------->
    <CACHEDATA 
          type="byte" 
          id="NVRAM_VAPP_LAUNCHER_COSMOS_MM_BARREL_SETTING"
          restore_flag="TRUE"
          >
        <DEFAULT_VALUE>[0x06]</DEFAULT_VALUE>            
        <DESCRIPTION>Last selection of barrel setting</DESCRIPTION>   
    </CACHEDATA>
        
    <!----- String ----->
    <STRING id="STR_ID_VAPP_LAUNCHER_COSMOS_MM_BARREL_SETTING_NAME"/>
    
    <!----- Images ----->
   
    <THEME>
        <IMAGE id="IMG_ID_VAPP_LAUNCHER_COSMOS_MM_BARREL_SETTING_APP_ICON" desc="main menu barrel setting">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Flip_FX.png"</IMAGE>
    </THEME>
    
</APP>
#endif // defined(__MMI_VUI_LAUNCHER_COSMOS__) && defined(__MMI_VUI_MAIN_MENU_SWITCH_EFFECT__)