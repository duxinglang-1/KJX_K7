#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_PROFILE">

#if defined(__MMI_VUI_HOMESCREEN_PROFILE__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_PROFILE"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH     ROOT_PATH"Widget\\\\"
    #define PROFILE_WIDGET_PATH WIDGET_PATH"Profile\\\\"
    
    <IMAGE id="VAPP_HS_IMG_WG_ICON_PROFILE">WIDGET_PATH"Widgeticon_profile.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_BG">PROFILE_WIDGET_PATH"Profile_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_CURR_BG">PROFILE_WIDGET_PATH"Profile_Curr_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_GENERAL_L">PROFILE_WIDGET_PATH"Profile_General_Large.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_GENERAL_S">PROFILE_WIDGET_PATH"Profile_General_Small.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_SILENT_L">PROFILE_WIDGET_PATH"Profile_Silent_Large.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_SILENT_S">PROFILE_WIDGET_PATH"Profile_Silent_Small.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_MEETING_L">PROFILE_WIDGET_PATH"Profile_Meeting_Large.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_MEETING_S">PROFILE_WIDGET_PATH"Profile_Meeting_Small.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_OUTDOOR_L">PROFILE_WIDGET_PATH"Profile_Outdoor_Large.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_OUTDOOR_S">PROFILE_WIDGET_PATH"Profile_Outdoor_Small.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_MYSTYLE_L">PROFILE_WIDGET_PATH"Profile_MyStyle_Large.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_MYSTYLE_S">PROFILE_WIDGET_PATH"Profile_MyStyle_Small.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_ACTIVITY_L">PROFILE_WIDGET_PATH"Profile_Activity_L.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PROF_ACTIVITY_S">PROFILE_WIDGET_PATH"Profile_Activity_S.png"</IMAGE>
    
#endif

</APP>

