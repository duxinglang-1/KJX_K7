# 1 "temp/res/PowerOnOffDisplay.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/PowerOnOffDisplay.c"
# 98 "temp/res/PowerOnOffDisplay.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 99 "temp/res/PowerOnOffDisplay.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 100 "temp/res/PowerOnOffDisplay.c" 2


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_PHNSET_ONOFF">

    <!-- string ----------------------------------------------------------------------------------->

    <STRING id = "STR_ID_PHNSET_ON_OFF_SYSTEM"/>
    <STRING id = "STR_ID_PHNSET_ON_OFF_DOWNLOAD"/>



    <STRING id = "STR_SETTING_POWER_ON_DISPLAY"/>
    <STRING id = "STR_SETTING_POWER_OFF_DISPLAY"/>



    <!-- image ----------------------------------------------------------------------------------->



    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON_SYSTEM_LIST"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON_SYSTEM_VIEW"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON_SYSTEM_VIEW_2"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON_USER_VIEW"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_OFF"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_OFF_SYSTEM_LIST"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_OFF_SYSTEM_VIEW"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_OFF_SYSTEM_VIEW_2"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_OFF_USER_VIEW"/>
    <SCREEN id = "SCR_ID_PHNSET_POWER_ON_OFF_LAST"/>

    <!-- screen group id -------------------------------------------------------------------------->
    <SCREEN id = "GRP_ID_POWER_ON_OFF_MAIN"/>
    <SCREEN id = "GRP_ID_POWER_ON_OFF_SYSTEM"/>
    <SCREEN id = "GRP_ID_POWER_ON_OFF_PREVIEW"/>

    <!-- menu ------------------------------------------------------------------------------------->



    <!-- Power on display main menu -->
    <MENU id = "MENU_SETTING_POWER_ON_DISPLAY" type = "APP_SUB" str = "STR_SETTING_POWER_ON_DISPLAY">
        <MENUITEM_ID>MENU_SETTING_POWER_ON_SYSTEM</MENUITEM_ID>

    <MENUITEM_ID>MENU_SETTING_POWER_ON_DOWNLOAD</MENUITEM_ID>




    </MENU>
    <MENUITEM id = "MENU_SETTING_POWER_ON_SYSTEM" str = "STR_ID_PHNSET_ON_OFF_SYSTEM"/>
    <MENUITEM id = "MENU_SETTING_POWER_ON_DOWNLOAD" str = "STR_ID_PHNSET_ON_OFF_DOWNLOAD"/>




    <!-- Power off display main menu -->

    <MENU id = "MENU_SETTING_POWER_OFF_DISPLAY" type = "APP_SUB" str = "STR_SETTING_POWER_OFF_DISPLAY">
        <MENUITEM_ID>MENU_SETTING_POWER_OFF_SYSTEM</MENUITEM_ID>

    <MENUITEM_ID>MENU_SETTING_POWER_OFF_DOWNLOAD</MENUITEM_ID>




    </MENU>
    <MENUITEM id = "MENU_SETTING_POWER_OFF_SYSTEM" str = "STR_ID_PHNSET_ON_OFF_SYSTEM"/>
    <MENUITEM id = "MENU_SETTING_POWER_OFF_DOWNLOAD" str = "STR_ID_PHNSET_ON_OFF_DOWNLOAD"/>





    <!-- For file manager service handler -->
    <MENUITEM id = "MENU_ID_FMGR_FWD_POWER_ON" str = "STR_SETTING_POWER_ON_DISPLAY"/>
    <MENUITEM id = "MENU_ID_FMGR_FWD_POWER_OFF" str = "STR_SETTING_POWER_OFF_DISPLAY"/>
    <FILE_TYPES>
        <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_POWER_ON" enabler="mmi_phnset_display_use_as_enabler" handler="mmi_fmgr_to_power_on_display_hdlr"/>
        <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_POWER_OFF" enabler="mmi_phnset_display_use_as_enabler" handler="mmi_fmgr_to_power_off_display_hdlr"/>
    </FILE_TYPES>



    <CACHEDATA type="short" id="NVRAM_RESTORE_POWER_ON_DISPLAY">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_RESTORE_POWER_OFF_DISPLAY">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CURRENT_POWER_ON_DISPLAY" restore_flag="TRUE" restore_id="@NVRAM_RESTORE_POWER_ON_DISPLAY">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current power on display </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_CURRENT_POWER_OFF_DISPLAY" restore_flag="TRUE" restore_id="@NVRAM_RESTORE_POWER_OFF_DISPLAY">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current power off display </DESCRIPTION>
    </CACHEDATA>
</APP>
