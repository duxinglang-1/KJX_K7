# 1 "temp/res/vCalendar.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/vCalendar.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 2 "temp/res/vCalendar.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 3 "temp/res/vCalendar.c" 2


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_VCALENDAR">


    <INCLUDE file = "GlobalResDef.h"/>
    <INCLUDE file = "mmi_rp_srv_vobject_def.h"/>


    <INCLUDE file = "Mmi_rp_app_todolist_def.h"/>
    <INCLUDE file = "Mmi_rp_app_calendar_def.h"/>






    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->

        <STRING id="STR_ID_VCLNDR_FORWARD"/>
        <STRING id="STR_ID_VCLNDR_SAVE_TO_TDL"/>
        <STRING id="STR_ID_VCLNDR_SAVE_TO_CLNDR"/>
        <STRING id="STR_ID_VCLNDR_TASK_FULL"/>


        <!--End String Resource Area-->
    <!--End String Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->

        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
        <!--Screen ID Area-->

    <SCREEN id = "SCR_ID_VCLNDR_FORWARD"/>
    <SCREEN id = "SCR_ID_VCLNDR_FILENAME"/>
    <SCREEN id = "SCR_ID_VCLNDR_FILENAME_OPT"/>
    <SCREEN id = "SCR_ID_VCLNDR_RECV_OPT"/>

    <SCREEN id = "GRP_ID_VCLNDR_RECV"/>
    <SCREEN id = "GRP_ID_VCLNDR_SAVE_TO_FILE"/>
    <SCREEN id = "GRP_ID_VCLNDR_SAVE_TO_TDL"/>
    <SCREEN id = "GRP_ID_VCLNDR_SEND"/>


        <!--End Screen Resource Area-->
        <!--End Screen Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->


        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Menu Item Area-->
        <!--Menu Item Area-->

    <MENU id="MENU_VCLNDR_RECV_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM id="MENU_VCLNDR_RECV_OPT_CLNDR" str="STR_ID_VCLNDR_SAVE_TO_CLNDR"/>
        <MENUITEM id="MENU_VCLNDR_RECV_OPT_TDL" str="STR_ID_VCLNDR_SAVE_TO_TDL"/>

        <MENUITEM id="MENU_VCLNDR_RECV_OPT_FMGR" str="@OID:STR_ID_VOBJ_FORWARD_TO_FILE_MGR"/>

    </MENU>

    <MENUITEM id = "MENU_VCLNDR_USE_AS_EVENT" str = "@OID:ORGANIZER_MENU_CALENDER_STRINGID"/>
    <MENUITEM id = "MENU_VCLNDR_USE_AS_TASK" str = "@OID:STR_ID_TDL_TASKS"/>

        <!--End Menu Item Area-->
        <!--End Menu Item Area-->
        <!--------------------------------------------------------------------------------------------------------------------->

</APP>



<FILE_TYPES>
    <FILE_OPTION_HDLR option="MENU_VCLNDR_USE_AS_EVENT" enabler="mmi_vcal_fmgr_use_enabler" handler="mmi_vcal_fmgr_use_handler"/>
    <FILE_OPTION_HDLR option="MENU_VCLNDR_USE_AS_TASK" enabler="mmi_vcal_fmgr_use_enabler" handler="mmi_vcal_fmgr_use_handler"/>
</FILE_TYPES>
