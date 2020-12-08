# 1 "temp/res/SatApp.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/SatApp.c"
# 133 "temp/res/SatApp.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 134 "temp/res/SatApp.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 135 "temp/res/SatApp.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_SAT">



    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h, mmi_rp_srv_editor_def.h, mmi_rp_srv_sat_def.h, mmi_rp_app_mainmenu_def.h"/>

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->


    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="STR_ID_SAT_SIM_REFRESH"/>
    <STRING id="STR_ID_SAT_GET_INPUT_LENGTH_NOT_ENOUGH"/>
    <STRING id="STR_ID_SAT_LANGUAGE_CHANGED"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
# 185 "temp/res/SatApp.c"
    <IMAGE id="IMG_ID_SAT_SIM1_TITLE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SubMenu\\\\Services\\\\SIMToolKit\\\\SB_SIM.bmp"</IMAGE>
# 197 "temp/res/SatApp.c"
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <MENUITEM id="MENU_ID_SAT1_ENTRY" str="STR_ID_SAT_MENU_TITLE"


            img="IMG_ID_SAT_SIM1_TITLE"


        highlight="mmi_service_hilite_sat_hdlr" parent = "MAIN_MENU_SERVICES_MENUID"/>
# 241 "temp/res/SatApp.c"
    <!--Option Menu Tree Area-->



    <MENUITEM id="MENU_ID_SAT_INPUT_DONE_OPT" str="STR_GLOBAL_DONE"/>

    <MENU id="MENU_ID_SAT_INPUT_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_SAT_INPUT_DONE_OPT</MENUITEM_ID>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_SAT_INPUT_OPT"/>
    <SCREEN id="SCR_ID_SAT_CMD_SCREEN"/>

    <RECEIVER id="EVT_ID_SRV_SAT_PROACTIVE_SIM" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SETUP_MENU" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SIM_REFRESH" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SESSION_END" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SIM_CTRL_INFO" proc="mmi_sat_recv_ind"/>

    <RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="mmi_sat_recv_ucm_ind"/>
    <RECEIVER id="EVT_ID_IDLE_ENTER" proc="mmi_sat_recv_idle_ind"/>





</APP>
