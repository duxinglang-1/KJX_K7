#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_HOMESCREEN_WG_PET">
#if defined(__MMI_VUI_HOMESCREEN_PET__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VAPP_HS_STR_WG_PET"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH       CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\"
    #define WIDGET_PATH     ROOT_PATH"Widget\\\\"
    #define PET_WIDGET_PATH WIDGET_PATH"Pet\\\\"

    <IMAGE id="VAPP_HS_IMG_WG_ICON_PET">WIDGET_PATH"Widgeticon_pet.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_DRAG">PET_WIDGET_PATH"drag\\\\PET_DRAG_01.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_FALL1">PET_WIDGET_PATH"fall\\\\PET_FALL_01.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_FALL2">PET_WIDGET_PATH"fall\\\\PET_FALL_02.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_WALK1">PET_WIDGET_PATH"walk\\\\PET_WALK_01.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_WALK2">PET_WIDGET_PATH"walk\\\\PET_WALK_02.png"</IMAGE>
#ifndef __MMI_VUI_HOMESCREEN_LITE_DISPLAY__
    <IMAGE id="VAPP_HS_IMG_WG_PET_RUN1">PET_WIDGET_PATH"run\\\\PET_RUN_01.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_RUN2">PET_WIDGET_PATH"run\\\\PET_RUN_02.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_RUN3">PET_WIDGET_PATH"run\\\\PET_RUN_03.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_RUN_STOP">PET_WIDGET_PATH"run\\\\PET_RUN_STOP.png"</IMAGE>
#endif
    <IMAGE id="VAPP_HS_IMG_WG_PET_SLEEP0">PET_WIDGET_PATH"sleep\\\\PET_SLEEP_WAKEUP.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_SLEEP1">PET_WIDGET_PATH"sleep\\\\PET_SLEEP_01.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_SLEEP2">PET_WIDGET_PATH"sleep\\\\PET_SLEEP_02.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_SLEEP3">PET_WIDGET_PATH"sleep\\\\PET_SLEEP_03.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_SLEEP_FG">PET_WIDGET_PATH"sleep\\\\PET_SLEEP_BUBBLE.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_IDLE0">PET_WIDGET_PATH"idle\\\\pet_idle_0.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_IDLE1">PET_WIDGET_PATH"idle\\\\pet_idle_1.png"</IMAGE>
#ifndef __MMI_VUI_HOMESCREEN_LITE_DISPLAY__
    <IMAGE id="VAPP_HS_IMG_WG_PET_TURN1">PET_WIDGET_PATH"turn\\\\pet_turn_000.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_TURN2">PET_WIDGET_PATH"turn\\\\pet_turn_045.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_TURN3">PET_WIDGET_PATH"turn\\\\pet_turn_090.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_TURN4">PET_WIDGET_PATH"turn\\\\pet_turn_135.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_TURN5">PET_WIDGET_PATH"turn\\\\pet_turn_180.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_TURN6">PET_WIDGET_PATH"turn\\\\pet_turn_225.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_TURN7">PET_WIDGET_PATH"turn\\\\pet_turn_270.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_TURN8">PET_WIDGET_PATH"turn\\\\pet_turn_315.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_TURN_FLY1">PET_WIDGET_PATH"butturfly\\\\PET_BUTTURFLY_01.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_TURN_FLY2">PET_WIDGET_PATH"butturfly\\\\PET_BUTTURFLY_02.png"</IMAGE>
#endif
    <IMAGE id="VAPP_HS_IMG_WG_PET_EAT_GRASS">PET_WIDGET_PATH"eat\\\\PET_EAT_GRASS.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_EAT_BG">PET_WIDGET_PATH"eat\\\\PET_EAT_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_EAT1">PET_WIDGET_PATH"eat\\\\PET_EAT_01.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_EAT2">PET_WIDGET_PATH"eat\\\\PET_EAT_02.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_EAT3">PET_WIDGET_PATH"eat\\\\PET_EAT_03.png"</IMAGE>
#if defined(MOTION_SENSOR_SUPPORT)
    <IMAGE id="VAPP_HS_IMG_WG_PET_SHAKE1">PET_WIDGET_PATH"shake\\\\PET_SHAKE_01.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_PET_SHAKE2">PET_WIDGET_PATH"shake\\\\PET_SHAKE_02.png"</IMAGE>
#endif

#endif

</APP>

