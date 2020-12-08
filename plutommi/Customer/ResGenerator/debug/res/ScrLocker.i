# 1 "temp/res/ScrLocker.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/ScrLocker.c"
# 152 "temp/res/ScrLocker.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 153 "temp/res/ScrLocker.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 154 "temp/res/ScrLocker.c" 2


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_SCR_LOCKER">

    <!----- Include Area ------------------------------------------------------>
    <INCLUDE file="GlobalResDef.h"/>


    <!----- String Resource Area ---------------------------------------------->
    <STRING id="STR_ID_SLK_UNLOCK"/>






    <STRING id="STR_ID_SLK_KBD_HELP_MSG"/>
    <STRING id="STR_ID_SLK_KBD_HELP_MSG2"/>
    <STRING id="STR_ID_SLK_KBD_UNLOCK_ME_MSG"/>
# 213 "temp/res/ScrLocker.c"
    <!----- Image Resource Area ----------------------------------------------->
# 235 "temp/res/ScrLocker.c"
    <!----- Screen Resource Area ---------------------------------------------->
    <SCREEN id="GRP_ID_SLK_MAIN"/>
    <SCREEN id="SCR_ID_SLK_MAIN"/>
    <SCREEN id="GRP_ID_SLK_SETTING"/>




    <!----- Menu Resource Area ------------------------------------------------>
# 263 "temp/res/ScrLocker.c"
    <!------------------------------------------------------MMI Cache Resource---------------------------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_SETTING_AUTOKEYPADLOCK" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Auto KeyPad Lock Status </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SETTING_AUTOKEYPADLOCK_TIME" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Auto KeyPad Lock Timer </DESCRIPTION>
    </CACHEDATA>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->

    <TIMER id="KEYPAD_LOCK_TIMER"/>
    <TIMER id="IDLE_APP_AUTO_LOCK_TIMER_ID"/>

    <RECEIVER id="EVT_ID_POST_KEY_EVT_ROUTING" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_READY" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_ADD_MSG" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_DEL_MSG" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_SMS_UPDATE_MSG" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MMS_NMGR_ALERT" proc="mmi_slk_main_evt_hdlr"/>




    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="mmi_slk_main_evt_hdlr"/>



    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_DEINIT" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_BEFORE_GROUP_ENTER" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_BEFORE_GROUP_EXIT" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_IDLE_LAUNCHED" proc="mmi_slk_main_evt_hdlr"/>
    <RECEIVER id="EVT_ID_PRE_TOUCH_EVT_ROUTING" proc="mmi_slk_main_evt_hdlr"/>
# 313 "temp/res/ScrLocker.c"
    <EVENT id="EVT_ID_SCR_LOCKER_LOCKED" type="SENDER"/>






    <EVENT id="EVT_ID_SCR_LOCKER_UNLOCKED" type="SENDER"/>

    <EVENT id="EVT_ID_SLK_OBJ_CLOSE_REQ"/>
    <EVENT id="EVT_ID_SLK_OBJ_CLOSED_IND"/>
# 341 "temp/res/ScrLocker.c"
</APP>
