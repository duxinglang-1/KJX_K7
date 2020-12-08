# 1 "temp/res/NITZ.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/NITZ.c"
# 56 "temp/res/NITZ.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 57 "temp/res/NITZ.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 58 "temp/res/NITZ.c" 2
# 1 "../../mmi/setting/settinginc/SettingDefs.h" 1
# 59 "temp/res/NITZ.c" 2


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_NITZ">


    <!-----------------------------------------------------Include Resource Area----------------------------------------------------->
        <INCLUDE file = "GlobalMenuItems.h"/>
    <INCLUDE file = "GlobalResDef.h"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_NITZ_BASE"/>
    <STRING id="STR_ID_NITZ_APP"/>
    <STRING id="STR_ID_NITZ_APP_CONFIRM_FIRST"/>
    <STRING id="STR_ID_NITZ_CONFIRM_TITLE"/>
    <STRING id="STR_ID_NITZ_CONFIRM_INFO"/>
    <STRING id="STR_ID_NITZ_MAX"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_NITZ_CONFIRM" >"..\\\\..\\\\Customer\\\\Images""\\\\EmptyImage.bmp"</IMAGE>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_NITZ_APP"/>
    <SCREEN id="GRP_ID_NITZ_INDICATION"/>
    <SCREEN id="SCR_ID_NITZ_BASE"/>
                <SCREEN id="SCR_ID_SETTINGS_NITZ"/>
    <SCREEN id="SCR_ID_NITZ_CONFIRM"/>
    <SCREEN id="SCR_ID_NITZ_MAX"/>

    <MENU id="MENU_ID_NITZ_APP" type="OPTION" str="STR_ID_NITZ_APP">
        <MENUITEM id="MENU_ID_NITZ_APP_OFF" str="STR_GLOBAL_OFF"></MENUITEM>
        <MENUITEM id="MENU_ID_NITZ_APP_CONFIRM_FIRST" str="STR_ID_NITZ_APP_CONFIRM_FIRST"></MENUITEM>
        <MENUITEM id="MENU_ID_NITZ_APP_ON" str="STR_GLOBAL_ON"></MENUITEM>
    </MENU>


    <CACHEDATA type="byte" id="RESTORE_DEFAULT_AUTOUPDATE_TIME">
        <DEFAULT_VALUE> [0] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <!------------------------------------------------------callback manager sender part---------------------------------------------------------->
       <RECEIVER id="EVT_ID_SRV_NITZ_UPDATE_REQ" proc="mmi_nitz_dt_update_handler"/>



</APP>
