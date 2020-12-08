# 1 "temp/res/Ss.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/Ss.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/Ss.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/Ss.c" 2
# 1 "../../mmi/inc/CustomCfg.h" 1
# 5 "temp/res/Ss.c" 2

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_SS">



    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_SS_ACT_NOTIFY" proc="mmi_ss_hdlr_act_notify"/>
    <RECEIVER id="EVT_ID_SRV_SS_INDICATION" proc="mmi_ss_hdlr_ind"/>




    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <STRING id="STR_ID_SS_TITLE"/>
    <STRING id="STR_ID_SS_REQUESTING"/>
    <STRING id="STR_ID_SS_USSD_MSG"/>
    <STRING id="STR_ID_SS_PERIOD"/>
    <STRING id="STR_ID_SS_SECOND"/>
    <STRING id="STR_ID_SS_CHANGE_PSW_SUC"/>
    <STRING id="STR_ID_SS_CANCELLED"/>


    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <TIMER id="USSR_SESSION_TIMER"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>






    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <!--Menu Tree Area-->





    <MENUITEM id="MENU_ID_SS_SIM1" str="STR_GLOBAL_SIM_1"/>
    <MENUITEM id="MENU_ID_SS_SIM2" str="STR_GLOBAL_SIM_2"/>
# 75 "temp/res/Ss.c"
    <MENU id="MENU_ID_SS_TYPE_SELECT" type="APP_SUB" str="STR_ID_SS_TITLE" flag="NONMOVEABLE">
        <MENUITEM_ID>MENU_ID_SS_SIM1</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_SS_SIM2</MENUITEM_ID>
    </MENU>




    <!------------------------------------------------------Other Resource---------------------------------------------------------->

    <SCREEN id="GRP_ID_SS_COMMON"/>
    <SCREEN id="GRP_ID_SS_SIM1"/>
    <SCREEN id="GRP_ID_SS_SIM1_USSR"/>
    <SCREEN id="GRP_ID_SS_SIM2"/>
    <SCREEN id="GRP_ID_SS_SIM2_USSR"/>
    <SCREEN id="GRP_ID_SS_SIM3"/>
    <SCREEN id="GRP_ID_SS_SIM3_USSR"/>
    <SCREEN id="GRP_ID_SS_SIM4"/>
    <SCREEN id="GRP_ID_SS_SIM4_USSR"/>

    <SCREEN id="SCR_ID_SS_REQUESTING"/>
    <SCREEN id="SCR_ID_SS_USSR"/>
    <SCREEN id="SCR_ID_SS_USSN"/>
    <SCREEN id="SCR_ID_SS_RESULT"/>





</APP>
