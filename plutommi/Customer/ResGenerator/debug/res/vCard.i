# 1 "temp/res/vCard.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/vCard.c"
# 86 "temp/res/vCard.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 87 "temp/res/vCard.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 88 "temp/res/vCard.c" 2

# 1 "../../mmi/inc/MMI_features.h" 1
# 90 "temp/res/vCard.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 91 "temp/res/vCard.c" 2


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_VCARD">


    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_srv_vobject_def.h"/>

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->

    <STRING id="STR_ID_VCARD_NAME_EMPTY"/>
    <STRING id="STR_ID_VCARD_FILE_TO_LARGE"/>
    <STRING id="STR_ID_VCARD_VCARD_DETAILS"/>
# 135 "temp/res/vCard.c"
    <STRING id="STR_ID_VCARD_SAVE_TO_SIM"/>

    <STRING id="STR_ID_VCARD_SAVE_TO_PHONE"/>

    <!--End String Resource Area-->
    <!--End String Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Screen ID Area-->
    <!--Screen ID Area-->

    <SCREEN id = "SCR_ID_VCARD_FORWARD_OPTION"/>
    <SCREEN id = "SCR_ID_VCARD_RECV_VIEW_DETAIL"/>
    <SCREEN id = "SCR_ID_VCARD_RECV_OPT"/>
    <SCREEN id = "SCR_ID_VCARD_ENTER_FILENAME"/>
    <SCREEN id = "SCR_ID_VCARD_ENTER_FILENAME_OPT"/>
    <SCREEN id = "SCR_ID_VCARD_EXPORTING"/>
    <SCREEN id = "SCR_ID_VCARD_IMPORTING"/>
    <SCREEN id = "GRP_ID_VCARD_BEGIN"/>
    <SCREEN id = "GRP_ID_VCARD_RECEVE"/>
    <SCREEN id = "GRP_ID_VCARD_END"/>
    <SCREEN id = "GRP_ID_VCARD_ENUM_TOTAL"/>

    <!--End Screen Resource Area-->
    <!--End Screen Resource Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Menu Item Area-->
    <!--Menu Item Area-->
# 177 "temp/res/vCard.c"
    <MENUITEM id="MENU_ID_VCARD_RECV_OPTION_TO_SIM" str="STR_ID_VCARD_SAVE_TO_SIM"/>

    <MENUITEM id="MENU_ID_VCARD_RECV_OPTION_TO_PHONE" str="STR_ID_VCARD_SAVE_TO_PHONE"/>

    <MENUITEM id="MENU_ID_VCARD_RECV_OPTION_FMGR" str="STR_ID_VOBJ_FORWARD_TO_FILE_MGR"/>


    <MENU id="MENU_ID_VCARD_RECV_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_VCARD_RECV_OPTION_TO_PHONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_VCARD_RECV_OPTION_TO_SIM</MENUITEM_ID>
# 197 "temp/res/vCard.c"
        <MENUITEM_ID>MENU_ID_VCARD_RECV_OPTION_FMGR</MENUITEM_ID>

    </MENU>
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_vcard_sim_profile_hdlr"/>
    <!--End Menu Item Area-->
    <!--End Menu Item Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

</APP>
