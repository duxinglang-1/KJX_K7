
#include "MMI_features.h" 
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_VENUS_SHELL_SCRLOCK">

/* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
<!--Include Area-->
<INCLUDE file="GlobalResDef.h"/>
    

#ifdef __MMI_VUI_SHELL_SCREEN_LOCK__

#define SHELL_SCRLOCK_PATH  CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\HomeScreen\\\\scrlock\\\\"


<!-- 
**************************************** String section ***************************************
-->

<STRING id="VAPP_SHELL_SCRLOCK_UNLOCK_STR"/>
<STRING id="VAPP_SHELL_SCRLOCK_UNLOCK_PROMPT"/>

<!-- 
**************************************** Image section ****************************************
-->

<IMAGE id="VAPP_SHELL_IMG_SCRLOCK_BGIMG">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\HomeScreen\\\\Wallpaper01.jpg"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SCRLOCK_LOCK_BG_N">SHELL_SCRLOCK_PATH"Lock_BG_Nor.9slice.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SCRLOCK_LOCK_BG_P">SHELL_SCRLOCK_PATH"Lock_BG_Pre.9slice.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SCRLOCK_LOCK_U">SHELL_SCRLOCK_PATH"Lock_ICON_U.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SCRLOCK_LOCK_D">SHELL_SCRLOCK_PATH"Lock_ICON_D.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SCRLOCK_PROGRESS_N">SHELL_SCRLOCK_PATH"Progress_Nor.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SCRLOCK_PROGRESS_P">SHELL_SCRLOCK_PATH"Progress_Pre.png"</IMAGE>


#endif /* __MMI_VUI_SHELL_SCREEN_LOCK__ */

</APP>


