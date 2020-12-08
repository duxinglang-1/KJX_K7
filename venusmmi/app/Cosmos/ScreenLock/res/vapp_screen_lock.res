#include "mmi_features.h"
#include "vapp_screen_lock_app_def.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SCREEN_LOCK" name="STR_ID_VAPP_SCREEN_LOCK" type="venus">
    <MEMORY base="0" fg="VAPP_SCREEN_LOCK_FG_MEM"
         vrt_mem_factor="VAPP_SCREEN_LOCK_EXTRA_CACHE_MEM_FACTOR"
         inc="vapp_screen_lock_mem_cfg.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_SCR_LOCK_SETTING_TITLE"/> /* Screen auto-lock */
    <STRING id="STR_ID_SCR_LOCK_15_SEC"/>        /* 15s */
    <STRING id="STR_ID_SCR_LOCK_30_SEC"/>
    <STRING id="STR_ID_SCR_LOCK_1_MIN"/>         /* 1min */
    <STRING id="STR_ID_SCR_LOCK_2_MIN"/>
    <STRING id="STR_ID_SCR_LOCK_5_MIN"/>
    <STRING id="STR_ID_SCR_LOCK_10_MIN"/>
    <STRING id="STR_ID_SCR_LOCK_NEVER"/>         /* Never */

    <!------------------------------------------------------MMI Cache Resource---------------------------------------------------------->    
    <CACHEDATA type="byte" id="NVRAM_SETTING_AUTO_SCREENLOCK_TIME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X02] </DEFAULT_VALUE>
        <DESCRIPTION> Auto Screen Lock Timer </DESCRIPTION>
    </CACHEDATA>

    <!-----------------------------------------------------Other Resource Area------------------------------------------------------>   
    /*
     * This event is emitted before launch screen lock
     *
     * Screen lock will not be launched if register callback return MMI_RET_ERR
     * else return MMI_RET_OK
     *
     * Structure: vapp_screen_lock_pre_lock_evt_struct
     */
    <SENDER id="EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING" hfile="vapp_screen_lock_gprot.h"/>

    /*
     * This event is emitted after screen lock has been lunched
     */
    <SENDER id="EVT_ID_VAPP_SCREEN_LOCK_LOCKED_EVT" hfile="vapp_screen_lock_gprot.h"/>


    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="vapp_screen_lock_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="vapp_screen_lock_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_PRE_KEY_EVT_ROUTING" proc="vapp_screen_lock_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_POST_KEY_EVT_ROUTING" proc="vapp_screen_lock_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_PRE_TOUCH_EVT_ROUTING" proc="vapp_screen_lock_main_evt_hdlr"/>
#if defined(__MMI_CLAMSHELL__)
    <RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="vapp_screen_lock_main_evt_hdlr"/>
#endif
</APP>
