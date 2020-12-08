# 1 "temp/res/Bootup.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/Bootup.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/Bootup.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/Bootup.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_BOOTUP">



    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <STRING id="STR_ID_BOOTUP_NAND_NOT_SUPPORTED"/>
    <STRING id="STR_ID_BOOTUP_USER_DRIVE_CORRUPTED"/>
    <STRING id="STR_ID_BOOTUP_SYSTEM_DRIVE_CORRUPTED"/>
    <STRING id="STR_ID_BOOTUP_NAND_VERSION_MISMATCH"/>


    <STRING id="STR_ID_BOOTUP_NAND_QUOTA_OVER_DISK"/>
    <STRING id="STR_ID_BOOTUP_NAND_QUOTA_USAGE_WARNING"/>
    <STRING id="STR_ID_BOOTUP_FLIGHT_MODE_ASK"/>
    <STRING id="STR_ID_BOOTUP_SOFTKEY_EMERGENCY"/>
    <STRING id="STR_ID_BOOTUP_INPUT_PHONE_PASSWORD"/>
    <STRING id="STR_ID_BOOTUP_WRONG_PHONE_PASSWORD"/>
    <STRING id="STR_ID_BOOTUP_EMERGENCY_CALL_ASK"/>
    <STRING id="STR_ID_BOOTUP_REMAINING_TRIALS_PROMPT"/>


    <STRING id="STR_ID_BOOTUP_INPUT_CHV1"/>
    <STRING id="STR_ID_BOOTUP_INPUT_UBCHV1"/>
    <STRING id="STR_ID_BOOTUP_NEW_CHV1"/>







    <STRING id="STR_ID_BOOTUP_WRONG_CHV1"/>
    <STRING id="STR_ID_BOOTUP_WRONG_UBCHV1"/>
    <STRING id="STR_ID_BOOTUP_CONFIRM_NEW_CHV1"/>
    <STRING id="STR_ID_BOOTUP_CHV1_NOT_MATCH"/>




    <STRING id="STR_ID_BOOTUP_INPUT_NP"/>
    <STRING id="STR_ID_BOOTUP_INPUT_NSP"/>
    <STRING id="STR_ID_BOOTUP_INPUT_SP"/>
    <STRING id="STR_ID_BOOTUP_INPUT_CP"/>
    <STRING id="STR_ID_BOOTUP_INPUT_SIMP"/>
# 69 "temp/res/Bootup.c"
    <STRING id="STR_ID_BOOTUP_INPUT_NSSP"/>
    <STRING id="STR_ID_BOOTUP_INPUT_SIMCP"/>







    <STRING id="STR_ID_BOOTUP_WRONG_NP"/>
    <STRING id="STR_ID_BOOTUP_WRONG_NSP"/>
    <STRING id="STR_ID_BOOTUP_WRONG_SP"/>
    <STRING id="STR_ID_BOOTUP_WRONG_CP"/>
    <STRING id="STR_ID_BOOTUP_WRONG_SIMP"/>

    <STRING id="STR_ID_BOOTUP_WRONG_NSSP"/>
    <STRING id="STR_ID_BOOTUP_WRONG_SIMCP"/>





    <STRING id="STR_ID_BOOTUP_SIM_ACCESS_ERROR"/>
    <STRING id="STR_ID_BOOTUP_SIM_CHV1_BLOCKED"/>
    <STRING id="STR_ID_BOOTUP_SIM_BLOCKED"/>
# 102 "temp/res/Bootup.c"
    <STRING id="STR_ID_BOOTUP_FORMATING"/>
# 118 "temp/res/Bootup.c"
    <STRING id="STR_ID_BOOTUP_WAIT_FOR_SIM"/>
# 131 "temp/res/Bootup.c"
    <STRING id="STR_ID_BOOTUP_SIM_CAME_OFF"/>






    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>





    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
# 158 "temp/res/Bootup.c"
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_BOOTUP"/>
    <SCREEN id="SCR_ID_BOOTUP_BASE"/>

    <SCREEN id="SCR_ID_BOOTUP_DISK_CHECK_FORMAT_QUERY"/>
    <SCREEN id="SCR_ID_BOOTUP_DISK_CHECK_FORMATTING"/>


    <SCREEN id="SCR_ID_BOOTUP_SIM_SELECTION"/>

    <SCREEN id="SCR_ID_BOOTUP_FLIGHT_MODE_QUERY"/>

    <SCREEN id="SCR_ID_BOOTUP_DETECT_FACTORY_MODE_END"/>
    <SCREEN id="SCR_ID_BOOTUP_ANIMATION"/>
    <SCREEN id="SCR_ID_BOOTUP_DUMMY_WAITING"/>
    <SCREEN id="SCR_ID_BOOTUP_REAL_WAITING"/>
    <SCREEN id="SCR_ID_BOOTUP_PHONE_LOCK"/>
    <SCREEN id="SCR_ID_BOOTUP_CHV1_OR_PER"/>
    <SCREEN id="SCR_ID_BOOTUP_UBCHV1"/>
    <SCREEN id="SCR_ID_BOOTUP_NEW_CHV1"/>
    <SCREEN id="SCR_ID_BOOTUP_CONFIRM_NEW_CHV1"/>
    <SCREEN id="SCR_ID_BOOTUP_PER_LOCK_WAITING"/>
    <SCREEN id="SCR_ID_BOOTUP_PEN_CALIBRATION_BASE"/>





    <SENDER id="EVT_ID_MMI_BOOTUP_INTERRUPTIBLE_CHANGED" hfile="BootupAppGprot.h"/>

    <RECEIVER id="EVT_ID_SRV_BOOTUP_START" proc="mmi_bootup_flow_start"/>
    <RECEIVER id="EVT_ID_MMI_BOOTUP_INTERRUPTIBLE_CHANGED" proc="mmi_bootup_set_scenario_for_interrupt"/>
    <RECEIVER id="EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED" proc="mmi_bootup_sec_on_sim_status_changed"/>




    <CACHEDATA type="short" id="NVRAM_POWER_ON_DISPLAY_SUCCESS">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <TIMER id="BOOTUP_WAITING_EVENT_TIMER"/>
    <TIMER id="BOOTUP_ANIMATION_TIMER"/>
    <TIMER id="BOOTUP_WAITING_SCREEN_TIMER"/>

</APP>
