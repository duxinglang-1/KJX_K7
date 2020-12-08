# 1 "temp/res/CallLog.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/CallLog.c"
# 226 "temp/res/CallLog.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 227 "temp/res/CallLog.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 228 "temp/res/CallLog.c" 2



<?xml version = "1.0" encoding = "UTF-8"?>


<APP id = "APP_CALLLOG"
# 244 "temp/res/CallLog.c"
>


<!----------------- XML Begin ------------------------------------------------->

<!----------------- Include Area ---------------------------------------------->

    <INCLUDE file = "GlobalResDef.h"/>







<!----------------- Common ---------------------------------------------------->

    <!----------------- Event Id ------------------------------------------->

    <!----------------- CallLogSrv Event Handler ----------------------->
    <RECEIVER id="EVT_ID_SRV_CLOG_READY" proc="mmi_clog_srv_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CLOG_ADD_LOG" proc="mmi_clog_srv_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CLOG_UPDATE_LOG" proc="mmi_clog_srv_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CLOG_UPDATE_ALL" proc="mmi_clog_srv_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CLOG_DEL_LOG" proc="mmi_clog_srv_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CLOG_DEL_ALL" proc="mmi_clog_srv_evt_hdlr"/>

    <RECEIVER id="EVT_ID_GPIO_EXT_DEV_KEY_1" proc="mmi_clog_gpio_hookkey_hdlr"/>
# 281 "temp/res/CallLog.c"
    <!----------------- CallLogApp Event Id ---------------------------->
    <EVENT id = "EVT_ID_MMI_CLOG_ACT_START_APPLY"/> <!-- Action --->
    <EVENT id = "EVT_ID_MMI_CLOG_ACT_APPLY_DONE"/>

    <EVENT id = "EVT_ID_MMI_CLOG_LT_EXIST"/> <!-- Layout --->

    <EVENT id = "EVT_ID_MMI_CLOG_VR_EXIT"/> <!-- Viewer --->


    <!----------------- Group Id ------------------------------------------->
    <SCREEN id = "GRP_ID_CLOG_ROOT"/>
    <SCREEN id = "GRP_ID_CLOG_ROOT1"/>
    <SCREEN id = "GRP_ID_CLOG_ROOT2"/>
    <SCREEN id = "GRP_ID_CLOG_ROOT3"/>
    <SCREEN id = "GRP_ID_CLOG_ROOT4"/>
    <SCREEN id = "GRP_ID_CLOG_ROOT_LAST"/>

    <SCREEN id = "GRP_ID_CLOG_LAYOUT"/>
    <SCREEN id = "GRP_ID_CLOG_LAYOUT1"/>
    <SCREEN id = "GRP_ID_CLOG_LAYOUT2"/>
    <SCREEN id = "GRP_ID_CLOG_LAYOUT3"/>
    <SCREEN id = "GRP_ID_CLOG_LAYOUT4"/>
    <SCREEN id = "GRP_ID_CLOG_LAYOUT_LAST"/>

    <SCREEN id = "GRP_ID_CLOG_VIEWER"/>
    <SCREEN id = "GRP_ID_CLOG_VIEWER1"/>
    <SCREEN id = "GRP_ID_CLOG_VIEWER2"/>
    <SCREEN id = "GRP_ID_CLOG_VIEWER3"/>
    <SCREEN id = "GRP_ID_CLOG_VIEWER4"/>
    <SCREEN id = "GRP_ID_CLOG_VIEWER_LAST"/>

    <SCREEN id = "GRP_ID_CLOG_OPTION"/>
    <SCREEN id = "GRP_ID_CLOG_OPTION1"/>
    <SCREEN id = "GRP_ID_CLOG_OPTION2"/>
    <SCREEN id = "GRP_ID_CLOG_OPTION3"/>
    <SCREEN id = "GRP_ID_CLOG_OPTION4"/>
    <SCREEN id = "GRP_ID_CLOG_OPTION_LAST"/>

    <SCREEN id = "GRP_ID_CLOG_ACTION"/>
    <SCREEN id = "GRP_ID_CLOG_ACTION1"/>
    <SCREEN id = "GRP_ID_CLOG_ACTION2"/>
    <SCREEN id = "GRP_ID_CLOG_ACTION3"/>
    <SCREEN id = "GRP_ID_CLOG_ACTION4"/>
    <SCREEN id = "GRP_ID_CLOG_ACTION_LAST"/>

    <SCREEN id = "GRP_ID_CLOG_ADVANCED"/>

    <SCREEN id = "GRP_ID_CLOG_CALL_TIME"/>
    <SCREEN id = "GRP_ID_CLOG_CALL_TIME1"/>
    <SCREEN id = "GRP_ID_CLOG_CALL_TIME2"/>
    <SCREEN id = "GRP_ID_CLOG_CALL_TIME3"/>
    <SCREEN id = "GRP_ID_CLOG_CALL_TIME4"/>
    <SCREEN id = "GRP_ID_CLOG_CALL_TIME_LAST"/>

    <SCREEN id = "GRP_ID_CLOG_CALL_COST"/>
    <SCREEN id = "GRP_ID_CLOG_CALL_COST1"/>
    <SCREEN id = "GRP_ID_CLOG_CALL_COST2"/>
    <SCREEN id = "GRP_ID_CLOG_CALL_COST3"/>
    <SCREEN id = "GRP_ID_CLOG_CALL_COST4"/>
    <SCREEN id = "GRP_ID_CLOG_CALL_COST_LAST"/>

    <SCREEN id = "GRP_ID_CLOG_SMS_COUNT"/>
    <SCREEN id = "GRP_ID_CLOG_SMS_COUNT1"/>
    <SCREEN id = "GRP_ID_CLOG_SMS_COUNT2"/>
    <SCREEN id = "GRP_ID_CLOG_SMS_COUNT3"/>
    <SCREEN id = "GRP_ID_CLOG_SMS_COUNT4"/>
    <SCREEN id = "GRP_ID_CLOG_SMS_COUNT_LAST"/>

    <SCREEN id = "GRP_ID_CLOG_GPRS_COUNT"/>
    <SCREEN id = "GRP_ID_CLOG_GPRS_COUNT1"/>
    <SCREEN id = "GRP_ID_CLOG_GPRS_COUNT2"/>
    <SCREEN id = "GRP_ID_CLOG_GPRS_COUNT3"/>
    <SCREEN id = "GRP_ID_CLOG_GPRS_COUNT4"/>
    <SCREEN id = "GRP_ID_CLOG_GPRS_COUNT_LAST"/>


    <!----------------- String Id ----------------------------------------->


    <STRING id = "STR_ID_CLOG_IF_RESET_COUNT"/>

    <!----------------- Image Id ------------------------------------------>

    <!----------------- Menu Id ------------------------------------------->

<!----------------- Common End ------------------------------------------------>
# 487 "temp/res/CallLog.c"
<!----------------- Call Cost ------------------------------------------------->


    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_CLOG_CALL_COST"/>
    <SCREEN id = "SCR_ID_CLOG_CALL_COST_SIM1"/>
    <SCREEN id = "SCR_ID_CLOG_CALL_COST_SIM2"/>
    <SCREEN id = "SCR_ID_CLOG_CALL_COST_SIM3"/>
    <SCREEN id = "SCR_ID_CLOG_CALL_COST_SIM4"/>
    <SCREEN id = "SCR_ID_CLOG_CCOST_SIM_SELECTION"/>

    <!----------------- String Id ----------------------------------------->

    <STRING id = "STR_ID_CLOG_CCOST"/>
    <STRING id = "STR_ID_CLOG_CCOST_PRICE"/>
    <STRING id = "STR_ID_CLOG_CCOST_UNIT"/>
    <STRING id = "STR_ID_CLOG_CCOST_SET_PPU"/>
    <STRING id = "STR_ID_CLOG_CCOST_SET_MAX"/>

    <STRING id = "STR_ID_CLOG_CALL_COST"/>
    <STRING id = "STR_ID_CLOG_CCOST_SET"/>
    <STRING id = "STR_ID_CLOG_CCOST_PPU"/>
# 520 "temp/res/CallLog.c"
    <STRING id = "STR_ID_CLOG_CCOST_LAST"/>
    <STRING id = "STR_ID_CLOG_CCOST_TOTAL"/>
    <STRING id = "STR_ID_CLOG_CCOST_RESET"/>
    <STRING id = "STR_ID_CLOG_CCOST_MAX"/>
# 542 "temp/res/CallLog.c"
    <!----------------- Image Id ------------------------------------------>
    <IMAGE id = "IMG_ID_CLOG_CALL_COST">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Submenu\\\\Call\\\\SB_COAST.bmp"</IMAGE>

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_CLOG_CALL_COST" type = "APP_SUB" str = "STR_ID_CLOG_CALL_COST"
          img = "IMG_ID_CLOG_CALL_COST">
# 560 "temp/res/CallLog.c"
        <MENUITEM id = "MENU_ID_CLOG_CCOST_LAST" str = "STR_ID_CLOG_CCOST_LAST"/>
        <MENUITEM id = "MENU_ID_CLOG_CCOST_TOTAL" str = "STR_ID_CLOG_CCOST_TOTAL"/>
        <MENUITEM id = "MENU_ID_CLOG_CCOST_RESET" str = "STR_ID_CLOG_CCOST_RESET"/>
        <MENUITEM id = "MENU_ID_CLOG_CCOST_MAX" str = "STR_ID_CLOG_CCOST_MAX"/>
        <MENUITEM id = "MENU_ID_CLOG_CCOST_PPU" str = "STR_ID_CLOG_CCOST_PPU"/>
# 583 "temp/res/CallLog.c"
    </MENU>


<!----------------- Call Cost End --------------------------------------------->



<!----------------- SMS Counter ----------------------------------------------->
# 650 "temp/res/CallLog.c"
<!----------------- SMS Counter End ------------------------------------------->






<!----------------- GPRS Counter ---------------------------------------------->



    <!----------------- Timer Id ------------------------------------------>

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_CLOG_GPRS_COUNT"/>
    <SCREEN id = "SCR_ID_CLOG_GPRS_COUNT_SIM1"/>
    <SCREEN id = "SCR_ID_CLOG_GPRS_COUNT_SIM2"/>
    <SCREEN id = "SCR_ID_CLOG_GPRS_COUNT_SIM3"/>
    <SCREEN id = "SCR_ID_CLOG_GPRS_COUNT_SIM4"/>

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_CLOG_GPRS_COUNT"/>
    <STRING id = "STR_ID_CLOG_GPRS_COUNT_B"/>
    <STRING id = "STR_ID_CLOG_GPRS_COUNT_KB"/>
    <STRING id = "STR_ID_CLOG_GPRS_COUNT_MB"/>
# 688 "temp/res/CallLog.c"
    <STRING id = "STR_ID_CLOG_GPRS_LAST_SENT"/>
    <STRING id = "STR_ID_CLOG_GPRS_LAST_RECVED"/>
    <STRING id = "STR_ID_CLOG_GPRS_ALL_SENT"/>
    <STRING id = "STR_ID_CLOG_GPRS_ALL_RECVED"/>
    <STRING id = "STR_ID_CLOG_GPRS_RESET"/>
    <STRING id = "STR_ID_CLOG_GPRS_COUNT_IF_RESET"/>
# 712 "temp/res/CallLog.c"
    <!----------------- Image Id ------------------------------------------>
    <IMAGE id = "IMG_ID_CLOG_GPRS_COUNT">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Submenu\\\\Call\\\\SB_CGPRS.bmp"</IMAGE>

    <!----------------- Menu Id ------------------------------------------->

    <MENU id = "MENU_ID_CLOG_GPRS_COUNT" type = "APP_SUB" str = "STR_ID_CLOG_GPRS_COUNT"
          img = "IMG_ID_CLOG_GPRS_COUNT">
# 730 "temp/res/CallLog.c"
        <MENUITEM id = "MENU_ID_CLOG_GPRS_LAST_SENT" str = "STR_ID_CLOG_GPRS_LAST_SENT"/>
        <MENUITEM id = "MENU_ID_CLOG_GPRS_LAST_RECVED" str = "STR_ID_CLOG_GPRS_LAST_RECVED"/>
        <MENUITEM id = "MENU_ID_CLOG_GPRS_ALL_SENT" str = "STR_ID_CLOG_GPRS_ALL_SENT"/>
        <MENUITEM id = "MENU_ID_CLOG_GPRS_ALL_RECVED" str = "STR_ID_CLOG_GPRS_ALL_RECVED"/>
        <MENUITEM id = "MENU_ID_CLOG_GPRS_RESET" str = "STR_ID_CLOG_GPRS_RESET"/>
# 752 "temp/res/CallLog.c"
     </MENU>



<!----------------- GPRS Counter End ------------------------------------------>


<!----------------- Call Log -------------------------------------------------->

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_CLOG_MAIN_MENU"/>
    <SCREEN id = "SCR_ID_CLOG_LAYOUT"/>
    <SCREEN id = "SCR_ID_CLOG_DIALED_CALL"/>
    <SCREEN id = "SCR_ID_CLOG_RECVED_CALL"/>
    <SCREEN id = "SCR_ID_CLOG_MISSED_CALL"/>
    <SCREEN id = "SCR_ID_CLOG_ALL_CALL"/>
    <SCREEN id = "SCR_ID_CLOG_OPTION"/>
    <SCREEN id = "SCR_ID_CLOG_ADVANCED"/>
    <SCREEN id = "SCR_ID_CLOG_VIEWER"/>

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_CLOG_CALL_LOG"/>

    <STRING id = "STR_ID_CLOG_ALL_CALL"/>
    <STRING id = "STR_ID_CLOG_DIALED_CALL"/>
    <STRING id = "STR_ID_CLOG_RECVED_CALL"/>
    <STRING id = "STR_ID_CLOG_MISSED_CALL"/>





    <STRING id = "STR_ID_CLOG_ADD_TO_BLACK_LIST"/>
    <STRING id = "STR_ID_CLOG_IF_ADD_TO_BLACK_LIST"/>







    <STRING id = "STR_ID_CLOG_SINGLE_MISSED_CALL"/>
    <STRING id = "STR_ID_CLOG_MULTI_MISSED_CALLS"/>

    <STRING id = "STR_ID_CLOG_UNKNOWN_NUMBER"/>

    <STRING id = "STR_ID_CLOG_ANON_URI"/>
# 813 "temp/res/CallLog.c"
    <STRING id = "STR_ID_CLOG_TYPE"/>
    <STRING id = "STR_ID_CLOG_NAME"/>

    <STRING id = "STR_ID_CLOG_TIME"/>
    <STRING id = "STR_ID_CLOG_TIMES"/>
    <STRING id = "STR_ID_CLOG_TOTAL_NUM"/>
# 831 "temp/res/CallLog.c"
    <STRING id = "STR_ID_CLOG_NUMBER"/>
    <STRING id = "STR_ID_CLOG_TIMESTAMP"/>
# 857 "temp/res/CallLog.c"
    <!----------------- Image Id ------------------------------------------>



    <IMAGE id = "IMG_ID_CLOG_MAIN_ICON">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Submenu\\\\Call\\\\CC_callhistory.bmp"</IMAGE>
# 878 "temp/res/CallLog.c"
    <IMAGE id = "IMG_ID_CLOG_NEW_MISSED_CALL">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\Missed\\\\CL_MIS.png"</IMAGE>



    <IMAGE id = "IMG_ID_CLOG_DELETE_BOX">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Submenu\\\\Call\\\\SB_CRSET.bmp"</IMAGE>


    <IMAGE id = "IMG_ID_CLOG_ALL_CALL">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Submenu\\\\Call\\\\SB_CALL.bmp"</IMAGE>
# 896 "temp/res/CallLog.c"
    <IMAGE id = "IMG_ID_CLOG_DIALED_CALL">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CDIA.bmp"</IMAGE>
    <IMAGE id = "IMG_ID_CLOG_MISSED_CALL">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CMIS.bmp"</IMAGE>
    <IMAGE id = "IMG_ID_CLOG_RECVED_CALL">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_CREC.bmp"</IMAGE>
# 909 "temp/res/CallLog.c"
    <IMAGE id = "IMG_ID_CLOG_TAB_ALL_CALL">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_TAB_CALL.bmp"</IMAGE>
    <IMAGE id = "IMG_ID_CLOG_TAB_DIALED_CALL">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_TAB_CDIA.bmp"</IMAGE>
    <IMAGE id = "IMG_ID_CLOG_TAB_MISSED_CALL">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_TAB_CMIS.bmp"</IMAGE>
    <IMAGE id = "IMG_ID_CLOG_TAB_RECVED_CALL">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\SubMenu\\\\SB_TAB_CREC.bmp"</IMAGE>
# 963 "temp/res/CallLog.c"
    <!----------------- Menu Id ------------------------------------------->
    <MENUSET id = "MENU_ID_CLOG_MENSET_SUB_MODULES">

        <MENUITEM_ID>MENU_ID_CLOG_CALL_TIME</MENUITEM_ID>


        <MENUITEM_ID>MENU_ID_CLOG_CALL_COST</MENUITEM_ID>





        <MENUITEM_ID>MENU_ID_CLOG_GPRS_COUNT</MENUITEM_ID>

    </MENUSET>




    <MENUITEM id = "MENU_ID_CLOG_DIALED_CALL" str = "STR_GLOBAL_DIALLED_CALLS" img = "IMG_ID_CLOG_DIALED_CALL"
            shortcut = "ON" shortcut_img = "IMG_ID_CLOG_DIALED_CALL" launch= "mmi_clog_dclt_launch"/>

    <MENUITEM id = "MENU_ID_CLOG_MISSED_CALL" str = "STR_GLOBAL_MISSED_CALLS" img = "IMG_ID_CLOG_MISSED_CALL"
            shortcut = "ON" shortcut_img = "IMG_ID_CLOG_MISSED_CALL" launch= "mmi_clog_mclt_launch"/>

    <MENUITEM id = "MENU_ID_CLOG_RECVED_CALL" str = "STR_GLOBAL_RECEIVED_CALLS" img = "IMG_ID_CLOG_RECVED_CALL"
            shortcut = "ON" shortcut_img = "IMG_ID_CLOG_RECVED_CALL" launch= "mmi_clog_rclt_launch"/>

    <MENUITEM id = "MENU_ID_CLOG_ALL_CALL" str = "STR_ID_CLOG_ALL_CALL" img = "IMG_ID_CLOG_ALL_CALL"
              shortcut = "OFF" shortcut_img = "IMG_ID_CLOG_ALL_CALL" launch= "mmi_clog_aclt_launch"/>
# 1038 "temp/res/CallLog.c"
    <MENUSET id = "MENU_ID_CLOG_MENSET_SEND_MSG">



        <MENUITEM id = "MENU_ID_CLOG_SEND_SMS" str = "STR_GLOBAL_SEND_TEXT_MESSAGE"/>

        <MENUITEM id = "MENU_ID_CLOG_SEND_MMS" str = "STR_GLOBAL_SEND_MULTIMEDIA_MESSAGE"/>


    </MENUSET>


    <MENUSET id = "MENU_ID_CLOG_MENSET_OP_DEL">
        <MENUITEM id = "MENU_ID_CLOG_DELETE" str = "STR_GLOBAL_DELETE"/>
        <MENUITEM id = "MENU_ID_CLOG_DELETE_ALL" str = "STR_GLOBAL_DELETE_ALL"/>
    </MENUSET>

    <MENUSET id = "MENU_ID_CLOG_MENSET_OP_EVENT">
    </MENUSET>



    <MENU id = "MENU_ID_CLOG_ADVANCED" type = "APP_SUB" str = "STR_GLOBAL_ADVANCED">
        <MENUSET_ID>MENU_ID_CLOG_MENSET_SUB_MODULES</MENUSET_ID>
    </MENU>


    <MENU id = "MENU_ID_CLOG_OPTION" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
        <MENUITEM id = "MENU_ID_CLOG_VIEW" str = "STR_GLOBAL_VIEW"/>
        <MENUITEM id = "MENU_ID_CLOG_MAKE_CALL" str = "STR_GLOBAL_DIAL"/>

        <MENUSET_ID>MENU_ID_CLOG_MENSET_SEND_MSG</MENUSET_ID>

        <MENUITEM id = "MENU_ID_CLOG_SAVE_TO_PHB" str = "STR_GLOBAL_SAVE_TO_PHONEBOOK"/>

        <MENUITEM id = "MENU_ID_CLOG_ADD_TO_BLACK_LIST" str = "STR_ID_CLOG_ADD_TO_BLACK_LIST"/>
# 1083 "temp/res/CallLog.c"
        <MENUITEM id = "MENU_ID_CLOG_EDIT_BEFORE_CALL" str = "STR_GLOBAL_EDIT_BEFORE_CALL"/>

        <MENUSET_ID>MENU_ID_CLOG_MENSET_OP_DEL</MENUSET_ID>
        <MENUSET_ID>MENU_ID_CLOG_MENSET_OP_EVENT</MENUSET_ID>







        <MENUITEM_ID>MENU_ID_CLOG_ADVANCED</MENUITEM_ID>
# 1120 "temp/res/CallLog.c"
    </MENU>
# 1144 "temp/res/CallLog.c"
<!----------------- Call Time ------------------------------------------------->


<!----------------- Image Id ------------------------------------------>
   <IMAGE id = "IMG_ID_CLOG_CALL_TIME">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Submenu\\\\Call\\\\SB_CTIME.bmp"</IMAGE>



        <SCREEN id = "GRP_ID_CLOG_CALL_TIME_OPTION"/>



        <STRING id = "STR_ID_CLOG_CTIME_SIM1_RESET_ALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_SIM2_RESET_ALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_SIM3_RESET_ALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_SIM4_RESET_ALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_RESET_ALL"/>

        <STRING id = "STR_ID_CLOG_CTIME_SIM1_LAST_CALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_SIM1_ALL_DIALED_CALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_SIM1_ALL_RECIVED_CALL"/>

        <STRING id = "STR_ID_CLOG_CTIME_SIM2_LAST_CALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_SIM2_ALL_DIALED_CALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_SIM2_ALL_RECIVED_CALL"/>

        <STRING id = "STR_ID_CLOG_CTIME_SIM3_LAST_CALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_SIM3_ALL_DIALED_CALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_SIM3_ALL_RECIVED_CALL"/>

        <STRING id = "STR_ID_CLOG_CTIME_SIM4_LAST_CALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_SIM4_ALL_DIALED_CALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_SIM4_ALL_RECIVED_CALL"/>

        <STRING id = "STR_ID_CLOG_CTIME_IF_RESET_ALL"/>
        <STRING id = "STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM1"/>
        <STRING id = "STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM2"/>
        <STRING id = "STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM3"/>
        <STRING id = "STR_ID_CLOG_CTIME_IF_RESET_ALL_SIM4"/>
        <STRING id = "STR_ID_CLOG_CALL_TIME"/>




<MENU id = "MENU_ID_CLOG_CALL_TIME" str = "STR_ID_CLOG_CALL_TIME" img = "IMG_ID_CLOG_CALL_TIME"/>


<MENU id = "MENU_ID_CLOG_CTIME_OPTION" type = "OPTION" str = "STR_GLOBAL_OPTIONS">
# 1205 "temp/res/CallLog.c"
        <MENUITEM id = "MENU_ID_CLOG_CTIME_RESET_ALL_SIM1" str = "STR_ID_CLOG_CTIME_RESET_ALL"/>
# 1219 "temp/res/CallLog.c"
</MENU>






        <STRING id = "STR_ID_CLOG_VIEW_MISSED_CALL"/>
        <STRING id = "STR_ID_CLOG_VIEW_RING_ONES"/>

        <STRING id = "STR_ID_CLOG_VIEW_UNKNOWN"/>







<!----------------- Call Log End ---------------------------------------------->





<!----------------- XML END --------------------------------------------------->

</APP>
