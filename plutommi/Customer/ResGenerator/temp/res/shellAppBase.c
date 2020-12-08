
#include "MMI_features.h" 
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_SHELLAPP_BASE">

/* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
<!--Include Area-->
<INCLUDE file="GlobalResDef.h"/>
    

#ifdef __MMI_VUI_SHELL_MULTI_PAGE__

#define SHELL_COMMON_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\Common\\\\"
#define SHELL_SWITCH_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\Common\\\\Switch\\\\"
#define SHELL_SHORTCUT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\Common\\\\Shortcut\\\\"

<!-- 
**************************************** String section ***************************************
-->

<STRING id="VAPP_SHELL_STR_HOME_TITLE"/>
<STRING id="VAPP_SHELL_SWITCH_TEXT"/>
<STRING id="VAPP_SHELL_MENU_TEXT"/>
<STRING id="VAPP_SHELL_DIAL_TEXT"/>
<STRING id="VAPP_SHELL_LOCK_TEXT"/>

<!-- 
**************************************** Image section ****************************************
-->

<IMAGE id="VAPP_SHELL_IMG_SC_SWITCH">SHELL_SHORTCUT_PATH"Switch_Nor.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SC_SWITCH_PRESS">SHELL_SHORTCUT_PATH"Switch_Pre.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SC_MENU">SHELL_SHORTCUT_PATH"Menu_Nor.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SC_MENU_PRESS">SHELL_SHORTCUT_PATH"Menu_Pre.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SC_DIAL">SHELL_SHORTCUT_PATH"Dial_Nor.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SC_DIAL_PRESS">SHELL_SHORTCUT_PATH"Dial_Pre.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SC_LOCK">SHELL_SHORTCUT_PATH"Lock_Nor.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SC_LOCK_PRESS">SHELL_SHORTCUT_PATH"Lock_Pre.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SC_BG_NOR">SHELL_SHORTCUT_PATH"ShortCut_BG_Nor.9slice.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SC_BG_PRESS">SHELL_SHORTCUT_PATH"ShortCut_BG_Pre.9slice.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SWITCH_BG">SHELL_COMMON_PATH"Home_bg.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_PANEL_BK_BORDER">SHELL_SWITCH_PATH"Switch_BG.9slice.bmp"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SWITCH_SCENE">SHELL_SWITCH_PATH"Switch_bg.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SWITCH_HOME">SHELL_SWITCH_PATH"Switch_Home.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SWITCH_FAV">SHELL_SWITCH_PATH"Switch_Contact.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SWITCH_IMV">SHELL_SWITCH_PATH"Switch_Image.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SWITCH_MSG">SHELL_SWITCH_PATH"Switch_MSG.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SWITCH_MUSIC">SHELL_SWITCH_PATH"Switch_Music.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SWITCH_CALL">SHELL_SWITCH_PATH"Switch_RecentCalls.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SWITCH_SETTING">SHELL_SWITCH_PATH"Switch_Settings.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_SWITCH_SC">SHELL_SWITCH_PATH"Switch_Shortcuts.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_BK_DISABLE">SHELL_COMMON_PATH"Back_Dis.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_BK_NORMAL">SHELL_COMMON_PATH"Back_Nor.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_BK_PRESS">SHELL_COMMON_PATH"Back_Pre.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_DELETE_DIS">SHELL_COMMON_PATH"Delete_Dis.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_DELETE_NOR">SHELL_COMMON_PATH"Delete_Nor.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_DELETE_PRE">SHELL_COMMON_PATH"Delete_Pre.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_IND_BAR">SHELL_COMMON_PATH"PageIndicator\\\\Ind_Nor.9slice.png"</IMAGE>
<IMAGE id="VAPP_SHELL_IMG_IND">SHELL_COMMON_PATH"PageIndicator\\\\Ind_High.9slice.png"</IMAGE>

#endif /* __MMI_VUI_SHELL_MULTI_PAGE__ */

</APP>


