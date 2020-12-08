# 1 "temp/res/shortcuts.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/shortcuts.c"
# 97 "temp/res/shortcuts.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 98 "temp/res/shortcuts.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 99 "temp/res/shortcuts.c" 2

<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_SHORTCUTS">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="Mmi_rp_app_phonesetting_new_def.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_MAIN_MENU_ID"/>
    <STRING id="SHORTCUTS_TITLE_STRING_ID"/>
    <STRING id="SHORTCUTS_FULL_MSG_STRING_ID"/>
    <STRING id="SHORTCUTS_CHANGE_ORDER_STRING_ID"/>
# 125 "temp/res/shortcuts.c"
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_SHORTCUTS_MAINMENU" >"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\ToolBar\\\\Toolbar_mainmenu.bmp"</IMAGE>
    <IMAGE id="IMG_SETTING_SHORTCUT" >"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SubMenu\\\\Shortcut\\\\SB_SC.bmp"</IMAGE>






    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <MENUITEM id="EXTRA_SHORTCUTS_OPTION_ADD_MENUID" str="@OID:STR_GLOBAL_ADD"/>
    <MENUITEM id="EXTRA_SHORTCUTS_OPTION_EDIT_MENUID" str="@OID:STR_GLOBAL_EDIT"/>
    <MENUITEM id="EXTRA_SHORTCUTS_OPTION_DELETE_MENUID" str="@OID:STR_GLOBAL_DELETE"/>
    <MENUITEM id="EXTRA_SHORTCUTS_OPTION_DELETEALL_MENUID" str="@OID:STR_GLOBAL_DELETE_ALL"/>
    <MENUITEM id="EXTRA_SHORTCUTS_OPTION_CHAGNE_ORDER_MENUID" str="SHORTCUTS_CHANGE_ORDER_STRING_ID"/>
# 154 "temp/res/shortcuts.c"
    <!--Menu Tree Area-->




    <MENU id="EXTRA_SHORTCUTS_OPTION_MENUID" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>EXTRA_SHORTCUTS_OPTION_ADD_MENUID</MENUITEM_ID>
        <MENUITEM_ID>EXTRA_SHORTCUTS_OPTION_EDIT_MENUID</MENUITEM_ID>
        <MENUITEM_ID>EXTRA_SHORTCUTS_OPTION_DELETE_MENUID</MENUITEM_ID>
        <MENUITEM_ID>EXTRA_SHORTCUTS_OPTION_DELETEALL_MENUID</MENUITEM_ID>
        <MENUITEM_ID>EXTRA_SHORTCUTS_OPTION_CHAGNE_ORDER_MENUID</MENUITEM_ID>
    </MENU>

    <MENU id="EXTRA_SHORTCUTS_MENUID" type="APP_MAIN" str="SHORTCUTS_TITLE_STRING_ID"
# 176 "temp/res/shortcuts.c"
    img="IMG_SETTING_SHORTCUT"
    highlight="mmi_highlight_shortcuts"

    >
    </MENU>
# 190 "temp/res/shortcuts.c"
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_SHCT_QUICK_MENU_CFG"/>
    <SCREEN id="GRP_ID_SHCT_DEDICATED_KEY_CFG"/>
    <SCREEN id="GRP_ID_SHCT_QUICK_MENU"/>

    <SCREEN id="SCR_ID_SHCT_IDLE_SHORTCUT"/>
    <SCREEN id="SCR_ID_SHCT_MAIN_MENU"/>
    <SCREEN id="SCR_ID_SHCT_EDIT"/>
    <SCREEN id="SCR_ID_SHCT_ORDER"/>
    <SCREEN id="SCR_ID_SHCT_DEDICATED_KEYS"/>
    <SCREEN id="SCR_ID_SHCT_EDIT_DEDICATED_KEYS"/>
    <SCREEN id="SCR_ID_SHCT_APP_SELECT"/>

</APP>
