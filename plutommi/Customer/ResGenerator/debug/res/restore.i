# 1 "temp/res/restore.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/restore.c"
# 90 "temp/res/restore.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 91 "temp/res/restore.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 92 "temp/res/restore.c" 2


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "APP_RESTORE">


    <!-- string ----------------------------------------------------------------------------------->
    <STRING id = "STR_SETTING_RESTORE_CONFIRM"/>
    <STRING id = "STR_SETTING_RESTORE_PROCESSING"/>




    <STRING id = "STR_ID_RESTORE_TITLE"/>


    <!-- image ------------------------------------------------------------------------------------>
    <IMAGE id = "IMG_SETTING_STORE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_STORE.bmp"</IMAGE>


    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "SCR_RESTORE"/>
    <SCREEN id = "SCR_RESTORE_PROCESSING"/>
    <SCREEN id = "SCR_SETTING_RESTORE_CONFIRM"/>


    <!-- group ----------------------------------------------------------------------------------->
        <SCREEN id = "GRP_ID_PHNSET_RESTORE"/>


    <!-- menu ------------------------------------------------------------------------------------->
    <MENU id = "MENU_SETTING_RESTORE" type = "APP_MAIN" str = "STR_ID_RESTORE_TITLE" img = "IMG_SETTING_STORE" highlight = "HighlightRstScr">
    </MENU>






</APP>
