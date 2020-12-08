#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN">
#if defined(__MMI_VUI_HOMESCREEN__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_WALLPAPER_SETTING"/>
    <STRING id="VAPP_HS_STR_WALLPAPER_LIVE_WALLPAPER"/>
    <STRING id="VAPP_HS_STR_WALLPAPER_GALLERY"/>
    <STRING id="VAPP_HS_STR_WALLPAPER_DOWNLOAD"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define SHORTCUT_PATH   ROOT_PATH"Shortcut\\\\"
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    #define VUI_HS_IMG_TYPE "BMP"
#else /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
    #define VUI_HS_IMG_TYPE "PNG"
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */

    <IMAGE id="VAPP_HS_IMG_DT_IND">ROOT_PATH"Desktop_Dot_Normal.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_DT_IND_HILITE">ROOT_PATH"Desktop_Dot_Highlight.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_SC_BAR_LEFT_ARROW">ROOT_PATH"Shortcut_Left_Arrow.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_SC_BAR_RIGHT_ARROW">ROOT_PATH"Shortcut_Right_Arrow.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_SC_HILITE">ROOT_PATH"Shortcut_icon_Highlight.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAR_FOLD">ROOT_PATH"WidgetBar_Right_Arrow.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAR_UNFOLD">ROOT_PATH"WidgetBar_Left_Arrow.png"</IMAGE>

#if defined(__MMI_FTE_SUPPORT_SLIM__)
    <IMAGE id="VAPP_HS_IMG_SI_BG">ROOT_PATH"Statusbar_BG.9slice.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_IDLE_MODE_TEXT_BG">ROOT_PATH"SongName_BG.9slice.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_SC_BAR_BG">ROOT_PATH"Shortcut_BG.9slice."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_SC_POOL_BG">ROOT_PATH"Shortcut_pool_BG.9slice.bmp"</IMAGE>
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    <IMAGE id="VAPP_HS_IMG_WG_BAR_BG">ROOT_PATH"WidgetBar_BG_Shell.9slice."VUI_HS_IMG_TYPE</IMAGE>
#else
    <IMAGE id="VAPP_HS_IMG_WG_BAR_BG">ROOT_PATH"WidgetBar_BG.9slice."VUI_HS_IMG_TYPE</IMAGE>
#endif
#else /* defined(__MMI_FTE_SUPPORT_SLIM__) */
    <IMAGE id="VAPP_HS_IMG_SI_BG">ROOT_PATH"Statusbar_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_IDLE_MODE_TEXT_BG">ROOT_PATH"SongName_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_SC_BAR_BG">ROOT_PATH"Shortcut_BG."VUI_HS_IMG_TYPE</IMAGE>
    <IMAGE id="VAPP_HS_IMG_SC_POOL_BG">ROOT_PATH"Shortcut_pool_BG.bmp"</IMAGE>
#if defined(__MMI_VUI_SHELL_MULTI_PAGE__)
    <IMAGE id="VAPP_HS_IMG_WG_BAR_BG">ROOT_PATH"WidgetBar_BG_Shell."VUI_HS_IMG_TYPE</IMAGE>
#else
    <IMAGE id="VAPP_HS_IMG_WG_BAR_BG">ROOT_PATH"WidgetBar_BG."VUI_HS_IMG_TYPE</IMAGE>
#endif
#endif /* defined(__MMI_FTE_SUPPORT_SLIM__) */

    <IMAGE id="VAPP_HS_IMG_SC_DIALER">SHORTCUT_PATH"SC_dialPad.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_SC_MAIN_MENU">SHORTCUT_PATH"SC_MainMenu.png"</IMAGE>
#ifdef BROWSER_SUPPORT
    <IMAGE id="VAPP_HS_IMG_SC_BROWSER">SHORTCUT_PATH"SC_Browser.png"</IMAGE>
#endif
#ifdef __MMI_FILE_MANAGER__
    <IMAGE id="VAPP_HS_IMG_SC_FILE_MANAGER">SHORTCUT_PATH"SC_FileManager.png"</IMAGE>
#endif
    <IMAGE id="VAPP_HS_IMG_SC_PHONE_SETTING">SHORTCUT_PATH"SC_PhoneSetting.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_SC_PROFILES">SHORTCUT_PATH"SC_Profiles.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_SC_PHONEBOOK">SHORTCUT_PATH"SC_PhoneBook.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_SC_CALL_HISTORY">SHORTCUT_PATH"SC_CalHistory.png"</IMAGE>
#if defined(__MOD_SMSAL__)
    <IMAGE id="VAPP_HS_IMG_SC_MESSAGE_CENTER">SHORTCUT_PATH"SC_Msg.png"</IMAGE>
#endif
#ifdef __MMI_CALENDAR__
    <IMAGE id="VAPP_HS_IMG_SC_CALENDAR">SHORTCUT_PATH"SC_Calendar.png"</IMAGE>
#endif
#ifdef __MMI_TODOLIST__
    <IMAGE id="VAPP_HS_IMG_SC_TODO">SHORTCUT_PATH"SC_ToDo.png"</IMAGE>
#endif
    <IMAGE id="VAPP_HS_IMG_SC_ALARM">SHORTCUT_PATH"SC_Alarm.png"</IMAGE>
#if defined(__MMI_CALCULATOR__) || defined(__MMI_VRE_CALCULATOR__)
    <IMAGE id="VAPP_HS_IMG_SC_CALCULATOR">SHORTCUT_PATH"SC_Calculator.png"</IMAGE>
#endif
#ifdef __MMI_AUDIO_PLAYER__
    <IMAGE id="VAPP_HS_IMG_SC_AUDIO_PLAYER">SHORTCUT_PATH"SC_Audio.png"</IMAGE>
#endif
#ifdef __MMI_VIDEO_PLAYER__
    <IMAGE id="VAPP_HS_IMG_SC_VIDEO_PLAYER">SHORTCUT_PATH"SC_Video.png"</IMAGE>
#endif
#ifdef __MMI_MEDIA_PLAYER__
    <IMAGE id="VAPP_HS_IMG_SC_MEDIA_PLAYER">SHORTCUT_PATH"SC_Video.png"</IMAGE>
#endif
    <IMAGE id="VAPP_HS_IMG_SC_SETTING">SHORTCUT_PATH"SC_setting.png"</IMAGE>
#ifdef __MMI_KURO_SUPPORT__
    <IMAGE id="VAPP_HS_IMG_SC_KURO">SHORTCUT_PATH"SC_Kuro.png"</IMAGE>
#endif
#ifdef __MMI_VUI_3D_CUBE_APP__
    <IMAGE id="VAPP_HS_IMG_SC_CUBE">SHORTCUT_PATH"SC_Cube.png"</IMAGE>
#endif
#ifdef __MMI_GADGET_SUPPORT__
    <IMAGE id="VAPP_HS_IMG_SC_WIDGET_MANAGER">SHORTCUT_PATH"SC_WgtMgr.png"</IMAGE>
#endif

#if (defined(__MMI_MRE_APP_OPERA__) || defined(__MMI_MRE_APP_OPERA_EN__) || defined(__MMI_MRE_APP_OPERA_MINI_V6__))
    <IMAGE id="VAPP_HS_IMG_SC_MRE_OPERA">CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_Opera.png"</IMAGE>
#endif

#ifdef __MMI_MRE_APP_YAHOO__
    <IMAGE id="VAPP_HS_IMG_SC_MRE_YM">CUST_IMG_PATH"\\\\MainLCD\\\\MREAPP\\\\AM_App_YM.png"</IMAGE>
#endif

#if defined(__MMI_SEARCH_WEB_GOOGLE__)
    <IMAGE id="VAPP_HS_IMG_SEARCH_BAR_BG">ROOT_PATH"SearchBar_BG.9slice.png"</IMAGE>
#endif /* defined(__MMI_SEARCH_WEB_GOOGLE__) */

#endif /* defined(__MMI_VUI_HOMESCREEN__) */

</APP>

