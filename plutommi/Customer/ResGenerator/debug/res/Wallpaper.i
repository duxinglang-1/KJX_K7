# 1 "temp/res/Wallpaper.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/Wallpaper.c"
# 202 "temp/res/Wallpaper.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 203 "temp/res/Wallpaper.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 204 "temp/res/Wallpaper.c" 2

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_WALLPAPER">
    <INCLUDE file = "GlobalResDef.h"/>
    <!-- string ---------------------------------------------------------------------------------->
# 220 "temp/res/Wallpaper.c"
    <STRING id = "STR_WALLPAPER_SYSTEM"/>
    <STRING id = "STR_WALLPAPER_DOWNLOAD"/>
    <STRING id = "STR_WP_IDLE_WP_DECODE_ERR"/>




    <STRING id = "STR_ID_DISPCHAR_THEME_WALLPAPER"/>
    <STRING id = "STR_ID_WALLPAPER_GALLERY"/>
# 237 "temp/res/Wallpaper.c"
        <STRING id = "STR_ID_STATIC_WALLPAPER"/>
        <STRING id = "STR_ID_VIDEO_WALLPAPER"/>
        <STRING id = "STR_ID_HOMESCREEN_WALLPAPER"/>
        <STRING id = "STR_ID_LOCKSCREEN_WALLPAPER"/>

    <!-- image ------------------------------------------------------------------------------------>
# 270 "temp/res/Wallpaper.c"
    <!-- screen ----------------------------------------------------------------------------------->
    <SCREEN id = "SCR_MAIN_WALLPAPER"/>
    <SCREEN id = "SCR_MAIN_WALLPAPER_FIX"/>
    <SCREEN id = "SCR_WALLPAPER_SYSTEM_LIST"/>
    <SCREEN id = "SCR_WALLPAPER_VIEW"/>
    <SCREEN id = "SCR_WALLPAPER_VIEW_2"/>
    <SCREEN id = "SCR_WALLPAPER_DOWNLOAD_VIEW"/>
    <SCREEN id = "SCR_ID_PHNSET_IDLE_CLOCK_TYPE"/>
    <SCREEN id = "SCR_IDLE_SCR_DISP_WP_PREVIEW"/>
    <SCREEN id = "SCR_IDLE_SCR_DISP_WPSS_WAITING"/>

    <!-- screen group id -------------------------------------------------------------------------->
    <SCREEN id = "GRP_ID_DISPLAY_FMGR_COMMON"/>
    <SCREEN id = "GRP_ID_WALLPAPER_MAIN"/>
    <SCREEN id = "GRP_ID_WALLPAPER_SYSTEM"/>
    <SCREEN id = "GRP_ID_WALLPAPER_SYSTEM_SUB"/>
    <SCREEN id = "GRP_ID_WALLPAPER_PREVIEW"/>
    <SCREEN id = "GRP_ID_WALLPAPER_LIVE_WALLPAPER"/>
    <SCREEN id = "GRP_ID_WALLPAPER_ROTATE"/>

    <SCREEN id = "GRP_ID_WALLPAPER_HOME_WALLPAPER"/>
    <SCREEN id = "GRP_ID_WALLPAPER_LOCK_WALLPAPER"/>

    <!-- menu ------------------------------------------------------------------------------------->
# 324 "temp/res/Wallpaper.c"
    <!-- wallpaper main menu -->
    <MENU id = "MENU_SETTING_WALLPAPER" type = "APP_SUB" str = "STR_GLOBAL_WALLPAPER">
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_HOMESCREEN</MENUITEM_ID>
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_LOCKSCREEN</MENUITEM_ID>
    </MENU>
    <MENU id = "MENU_SETTING_WALLPAPER_HOMESCREEN" type = "APP_SUB" str = "STR_ID_HOMESCREEN_WALLPAPER">
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_SYSTEM</MENUITEM_ID>

        <MENUITEM_ID>MENU_SETTING_WALLPAPER_DOWNLOAD</MENUITEM_ID>




    </MENU>

    <MENU id = "MENU_SETTING_WALLPAPER_LOCKSCREEN" type = "APP_SUB" str = "STR_ID_LOCKSCREEN_WALLPAPER">
        <MENUITEM_ID>MENU_SETTING_WALLPAPER_SYSTEM</MENUITEM_ID>

        <MENUITEM_ID>MENU_SETTING_WALLPAPER_DOWNLOAD</MENUITEM_ID>

    </MENU>

    <MENU id = "MENU_SETTING_WALLPAPER_SYSTEM" type = "APP_SUB" str = "STR_WALLPAPER_SYSTEM">



        <MENUITEM_ID>MENU_SETTING_STATIC_WALLPAPER</MENUITEM_ID>






    </MENU>




    <MENUITEM id = "MENU_SETTING_WALLPAPER_DOWNLOAD" str = "STR_WALLPAPER_DOWNLOAD"/>



    <MENUITEM id = "MENU_SETTING_STATIC_WALLPAPER" str = "STR_ID_STATIC_WALLPAPER"/>
# 387 "temp/res/Wallpaper.c"
    <!-- For file manager service handler -->




    <MENUITEM id = "MENU_ID_FMGR_FWD_WALLPAPER" str = "STR_GLOBAL_WALLPAPER"/>





    <FILE_TYPES>




        <FILE_OPTION_HDLR option="MENU_ID_FMGR_FWD_WALLPAPER" enabler="mmi_phnset_display_use_as_enabler" handler="mmi_fmgr_to_wallpaper_hdlr"/>




    </FILE_TYPES>
# 453 "temp/res/Wallpaper.c"
<SENDER id="EVT_ID_PHNSET_WALLPAPER_CHANGED_NOTIFY" hfile="PhoneSetupGprots.h"/>
<SENDER id="EVT_ID_PHNSET_SUBWALLPAPER_CHANGED_NOTIFY" hfile="PhoneSetupGprots.h"/>






<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_phnset_wp_ss_pwr_disp_ms_hdlr"/>
<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_phnset_wp_ss_pwr_disp_ms_hdlr"/>


    <CACHEDATA type="double" id="NVRAM_DISPCHAR_AVATAR_WPSS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> avatar wallpaper and ss setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NARAM_DISPCHAR_AVATAR_ONOFF" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> avatar pwr on and off setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_DISPCHAR_AVATAR_WPSS_SERIALNUM" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> wallpaper and ss serial num </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_DISPCHAR_AVATAR_ONOFF_SERIALNUM" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> pwr on and off serial num </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_WALLPAPER_ROTATE_STATUS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> wallpaper rotate status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PHNSET_LIVE_WALLPAPER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Live Wallpaper setting </DESCRIPTION>
    </CACHEDATA>
# 509 "temp/res/Wallpaper.c"
    <CACHEDATA type="short" id="NVRAM_FUNANDGAMES_SETWALLPAPER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current wallpaper id </DESCRIPTION>

        <FIELD>

            <OPTION hint="Image 1"> [0x01, 0x00] </OPTION>
# 538 "temp/res/Wallpaper.c"
        </FIELD>

    </CACHEDATA>

    <CACHEDATA type="short" id="RESTORE_DEFAULT_FUNANDGAMES_SETWALLPAPER">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_SETWALLPAPER_SUB" restore_flag="TRUE" restore_id="@RESTORE_DEFAULT_SETWALLPAPER_SUB">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current sub wallpaper id </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="RESTORE_DEFAULT_SETWALLPAPER_SUB">
        <DEFAULT_VALUE> [0x01, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <!-- For screen lock wallpaper -->
# 569 "temp/res/Wallpaper.c"
</APP>
