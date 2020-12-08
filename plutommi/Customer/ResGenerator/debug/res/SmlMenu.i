# 1 "temp/res/SmlMenu.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/SmlMenu.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/SmlMenu.c" 2



# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 7 "temp/res/SmlMenu.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_SIM_ME_LOCK">



    <!--Include Area-->
    <INCLUDE file = "GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="STR_ID_CATEGORY_NP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_NSP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_CP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_SP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_SIMP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_NSP_SP_LOCK"/>
    <STRING id="STR_ID_CATEGORY_SIMP_CP_LOCK"/>

    <STRING id="STR_ID_SML_LOCK_MENU"/>
    <STRING id="STR_ID_SML_UNLOCK_MENU"/>
    <STRING id="STR_ID_SML_ADD_MENU"/>
    <STRING id="STR_ID_SML_REMOVE_MENU"/>
    <STRING id="STR_ID_SML_DEACTIVATE_MENU"/>

    <STRING id="STR_ID_SML_REBOOT_MSG"/>
    <STRING id="STR_ID_SML_QUREY_MSG"/>
    <STRING id="STR_ID_SML_BLOCK_MSG"/>
    <STRING id="STR_ID_SML_NO_EF_GID"/>

    <STRING id="STR_ID_SML_AUTOKEY_CONFIRM"/>
    <STRING id="STR_ID_LAST_RETRY_MSG"/>
    <STRING id="STR_ID_GENERAL_RETRY_MSG"/>
    <STRING id="STR_ID_UNLOCK_FIRST_MSG"/>
    <STRING id="STR_ID_EMPTY_CATEGORY_MSG"/>
    <STRING id="STR_ID_NO_RECORD_MSG"/>
    <STRING id="STR_ID_NO_DATA_MSG"/>

    <STRING id="STR_ID_SML_CAT_LOCKED"/>
    <STRING id="STR_ID_SML_CAT_UNLOCKED"/>
    <STRING id="STR_ID_SML_CAT_AUTOLOCKED"/>
    <STRING id="STR_ID_SML_CAT_DISABLED"/>

    <STRING id="STR_ID_SML_AUTOLOCKED"/>
    <STRING id="STR_ID_SML_FAIL_TO_AUTOLOCK"/>

    <STRING id="STR_ID_SML_NP_DATA"/>
    <STRING id="STR_ID_SML_NSP_DATA"/>
    <STRING id="STR_ID_SML_SP_DATA"/>
    <STRING id="STR_ID_SML_CP_DATA"/>
    <STRING id="STR_ID_SML_SIMP_DATA"/>

    <STRING id="STR_ID_SML_ASK_DELETE_CATEGORY"/>
    <STRING id="STR_ID_SML_ASK_DISABLE_CATEGORY"/>
# 74 "temp/res/SmlMenu.c"
    <STRING id="STR_ID_SML_INPUT_PASSWORD"/>
    <STRING id="STR_ID_SML_CONFIRM_PASSWORD"/>
    <STRING id="STR_ID_SML_DIFF_PASSWORD"/>
    <STRING id="STR_ID_SML_REMAIN_TRIALS"/>
    <STRING id="STR_ID_SML_INVALID_LENGTH"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
# 96 "temp/res/SmlMenu.c"
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_SML_LOCK_MENU"/>
    <SCREEN id="SCR_ID_SML_UNLOCK_MENU"/>
    <SCREEN id="SCR_ID_SML_ADD_MENU"/>
    <SCREEN id="SCR_ID_SML_REMOVE_MENU"/>
    <SCREEN id="SCR_ID_SML_DEACTIVATE_MENU"/>

    <SCREEN id="SCR_ID_SML_QUERY_POPUP"/>
    <SCREEN id="SCR_ID_SML_FILL_DATA"/>
    <SCREEN id="SCR_ID_SML_AUTOKEY_CONFIRM"/>
    <SCREEN id="SCR_ID_SML_REMOVE_CONFIRM"/>
    <SCREEN id="SCR_ID_SML_DEACTIVATE_CONFIRM"/>
    <SCREEN id="SCR_ID_SML_INPUT_KEY"/>
    <SCREEN id="SCR_ID_SML_CONFIRM_KEY"/>
    <SCREEN id="SCR_ID_SML_DUMMY"/>

    <SCREEN id="GRP_ID_SML_SIMS"/>
    <SCREEN id="GRP_ID_SML_MAIN"/>
    <SCREEN id="GRP_ID_SML_DATA"/>
    <SCREEN id="GRP_ID_SML_PSWD"/>

    <TIMER id="SML_AUTOLOCK_IDLE_NOTIFY_TIMER"/>

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_sml_sim_status_change"/>




</APP>
