# 1 "temp/res/Idle.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/Idle.c"
# 124 "temp/res/Idle.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 125 "temp/res/Idle.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 126 "temp/res/Idle.c" 2


<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_IDLE" type="venus" name ="STR_ID_IDLE_MAIN_MENU">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>

    <!----- Memory setting----------------------------------------------------->



    <MEMORY heap="$(IDLE_ASM_HEAP_SIZE) + base(APP_VENUS_WALLPAPER)" fg="$(VFX_SYS_MEM_VRT_SIZE)+$(IDLE_ASM_FG_SIZE)" vrt_mem_factor="IDLE_ASM_VRT_MEM_FACTOR" inc="IdleMemCfg.h, vfx_sys_config.h"/>

    <!----- String Resource Area ---------------------------------------------->

        <STRING id="STR_ID_IDLE_MAIN_MENU"/>
    <STRING id="STR_ID_IDLE_CONTACT"/>
    <STRING id="STR_ID_IDLE_LOCK_PROMPT"/>
# 164 "temp/res/Idle.c"
    <!----- Image Resource Area ----------------------------------------------->
# 183 "temp/res/Idle.c"
    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="GRP_ID_IDLE_MAIN"/>
    <SCREEN id="SCR_ID_IDLE_MAIN"/>
    <SCREEN id="SCR_ID_IDLE_SUBLCD"/>


    <!----- Menu Resource Area ------------------------------------------------>


    <!----- Timer Resource Area ---- ------------------------------------------>




    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <RECEIVER id="EVT_ID_PHB_OWNER_NUMBER_CHANGED" proc="mmi_idle_main_evt_hdlr"/>




    <RECEIVER id="EVT_ID_SRV_NW_NAME_CHANGED" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_SAVER_ENTER" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_SAVER_EXIT" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_LOCKER_LOCKED" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SCR_LOCKER_UNLOCKED" proc="mmi_idle_main_evt_hdlr"/>


    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_ACTIVE" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_CONNECTED" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_INACTIVE" proc="mmi_idle_main_evt_hdlr"/>

    <RECEIVER id="EVT_ID_SRV_CALLSET_LINE_SWITCHED" proc="mmi_idle_main_evt_hdlr"/>
# 225 "temp/res/Idle.c"
    <EVENT id="EVT_ID_IDLE_GROUP_ENTER" type="SENDER"/>






    <EVENT id="EVT_ID_IDLE_GROUP_EXIT" type="SENDER"/>






    <EVENT id="EVT_ID_IDLE_ENTER" type="SENDER"/>






    <EVENT id="EVT_ID_IDLE_EXIT" type="SENDER"/>
# 255 "temp/res/Idle.c"
    <EVENT id="EVT_ID_IDLE_LAUNCHED" type="SENDER"/>






    <EVENT id="EVT_ID_IDLE_BEFORE_GROUP_ENTER" type="SENDER"/>






    <EVENT id="EVT_ID_IDLE_BEFORE_GROUP_EXIT" type="SENDER"/>

    <RECEIVER id="EVT_ID_IDLE_GROUP_ENTER" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_GROUP_EXIT" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_ENTER" proc="mmi_idle_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_EXIT" proc="mmi_idle_main_evt_hdlr"/>

    <EVENT id="EVT_ID_IDLE_MAIN_NOTIFY_REQ"/>
    <EVENT id="EVT_ID_IDLE_MAIN_UPDATE_REQ"/>

</APP>
