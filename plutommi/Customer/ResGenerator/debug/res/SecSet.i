# 1 "temp/res/SecSet.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/SecSet.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/SecSet.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/SecSet.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_SECURITY_SETTING">



    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    <INCLUDE file="GlobalMenuItems.h"/>
    <INCLUDE file="mmi_rp_app_mainmenu_def.h"/> <!-- MAIN_MENU_TITLE_SETTINGS_ICON -->
    <INCLUDE file="mmi_rp_app_mmi_certman_def.h"/> <!-- MENU_CERTIFICATE_MANAGER -->
    <INCLUDE file="mmi_rp_app_apn_control_def.h"/> <!-- MENU_ID_SECSET_ACL_MAIN -->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="STR_ID_SECSET_APP_NAME"/>
    <STRING id="STR_ID_SECSET_CHANGE_PASSWORD"/>
    <STRING id="STR_ID_SECSET_PHONE_LOCK"/>
    <STRING id="STR_ID_SECSET_LOCKED"/>
    <STRING id="STR_ID_SECSET_UNLOCKED"/>
    <STRING id="STR_ID_SECSET_TEMP_FAIL"/>
    <STRING id="STR_ID_SECSET_INVALID_LENGTH"/>

    <STRING id="STR_ID_SECSET_SIM_SETTING"/>
# 44 "temp/res/SecSet.c"
    <STRING id="STR_ID_SECSET_PHONE_SETTING"/>
    <STRING id="STR_ID_SECSET_CHV1_LOCK"/>
    <STRING id="STR_ID_SECSET_CHANGE_CHV1_PASSWORD"/>
    <STRING id="STR_ID_SECSET_CHANGE_CHV2_PASSWORD"/>
    <STRING id="STR_ID_SECSET_OLD_PHONE_PASSWORD"/>
    <STRING id="STR_ID_SECSET_NEW_PHONE_PASSWORD"/>
    <STRING id="STR_ID_SECSET_CONFIRM_NEW_PHONE_PASSWORD"/>
    <STRING id="STR_ID_SECSET_DIFF_NEW_PHONE_PASSWORD"/>
    <STRING id="STR_ID_SECSET_ENABLE_CHV1_PROMPT"/>
    <STRING id="STR_ID_SECSET_CHV2_DISABLED"/>

    <STRING id="STR_ID_SECSET_OLD_CHV1"/>
    <STRING id="STR_ID_SECSET_CHV2_BLOCKED"/>
    <STRING id="STR_ID_SECSET_UBCHV1_BLOCKED_ONLY"/>
    <STRING id="STR_ID_SECSET_UBCHV2_BLOCKED"/>
# 75 "temp/res/SecSet.c"
    <STRING id="STR_ID_SECSET_WRONG_CHV2"/>
    <STRING id="STR_ID_SECSET_WRONG_UBCHV2"/>
    <STRING id="STR_ID_SECSET_CHV2_NOT_MATCH"/>
    <STRING id="STR_ID_SECSET_SIM_ERROR"/>
# 105 "temp/res/SecSet.c"
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

    <IMAGE id="IMG_SECSET_MENU_ENTRY">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SubMenu\\\\Settings\\\\SB_SECUR.bmp"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <MENU id="MENU_ID_SECSET_MAIN_MENU" type="APP_MAIN" str="STR_ID_SECSET_APP_NAME"
        img="IMG_SECSET_MENU_ENTRY" highlight="mmi_secset_main_menu_highlight_hdlr">
        <MENUITEM_ID>MENU_ID_SECSET_SIM1_ENTRY</MENUITEM_ID>
# 123 "temp/res/SecSet.c"
        <MENUITEM_ID>MENU_ID_SECSET_PHONE_SETTING</MENUITEM_ID>



    </MENU>




    <MENU id="MENU_ID_SECSET_SIM1_MENU" type="APP_SUB" str="STR_ID_SECSET_SIM_SETTING">

        <MENUITEM_ID>MENU_ID_SECSET_SIM1_CHV1_LOCK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SECSET_SIM1_CHANGE_CHV1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SECSET_SIM1_CHANGE_CHV2</MENUITEM_ID>



    </MENU>
# 174 "temp/res/SecSet.c"
    <MENU id="MENU_ID_SECSET_PHONE_SETTING" type="APP_SUB" str="STR_ID_SECSET_PHONE_SETTING">
        <MENUITEM_ID>MENU_ID_SECSET_PHONE_LOCK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SECSET_CHANGE_PHONE_PASSWORD</MENUITEM_ID>
    </MENU>
# 224 "temp/res/SecSet.c"
    <MENUITEM id="MENU_ID_SECSET_SIM1_ENTRY" str="STR_ID_SECSET_SIM_SETTING"/>


    <MENUITEM id="MENU_ID_SECSET_SIM1_CHV1_LOCK" str="STR_ID_SECSET_CHV1_LOCK"/>

    <MENUITEM id="MENU_ID_SECSET_SIM1_CHANGE_CHV1" str="STR_ID_SECSET_CHANGE_CHV1_PASSWORD"/>
    <MENUITEM id="MENU_ID_SECSET_SIM1_CHANGE_CHV2" str="STR_ID_SECSET_CHANGE_CHV2_PASSWORD"/>
# 263 "temp/res/SecSet.c"
    <MENUITEM id="MENU_ID_SECSET_PHONE_LOCK" str="STR_ID_SECSET_PHONE_LOCK"
        shortcut="ON" shortcut_img="IMG_SECSET_MENU_ENTRY" launch="mmi_secset_phone_set_lock_by_shortcut"/>

    <MENUITEM id="MENU_ID_SECSET_CHANGE_PHONE_PASSWORD" str="STR_ID_SECSET_CHANGE_PASSWORD"/>





    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_SECSET"/>
    <SCREEN id="GRP_ID_SECSET_VERIFICATION"/>
    <SCREEN id="GRP_ID_SECSET_SSC"/>
    <SCREEN id="GRP_ID_SECSET_SHORTCUT"/>
    <SCREEN id="SCR_ID_SECSET_DUMMY_WAITING"/>





        <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_secset_on_sim_availability_changed"/>




</APP>
