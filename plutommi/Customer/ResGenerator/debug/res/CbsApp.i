# 1 "temp/res/CbsApp.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/CbsApp.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 2 "temp/res/CbsApp.c" 2


# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 5 "temp/res/CbsApp.c" 2

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_CBS">
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SmsAppResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_CBS_CAPTION"/>
# 47 "temp/res/CbsApp.c"
    <STRING id="STR_ID_CBS_NEW_MSG_TITLE"/>
    <STRING id="STR_ID_CBS_NEW_MSG_FROM"/>

    <STRING id="STR_ID_CBS_RECEIVE_MODE"/>
    <STRING id="STR_ID_CBS_CHANNELS"/>
    <STRING id="STR_ID_CBS_LANGUAGES"/>
    <STRING id="STR_ID_CBS_INBOX"/>
    <STRING id="STR_ID_CBS_SUBSCRIBE"/>
    <STRING id="STR_ID_CBS_CANCEL_SUBSCRIPTION"/>
    <STRING id="STR_ID_CBS_NOT_READY_YET"/>
    <STRING id="STR_ID_CBS_CHNL_FULL"/>
    <STRING id="STR_ID_CBS_CHNL_DUPLICTED"/>
    <STRING id="STR_ID_CBS_ALL_LANGS"/>
    <STRING id="STR_ID_CBS_LANG_OTHERS"/>
    <STRING id="STR_ID_CBS_LANG_UNSPECIFIED"/>
    <STRING id="STR_ID_CBS_CHNL_NAME"/>
    <STRING id="STR_ID_CBS_CHNL_NUMBER"/>
    <STRING id="STR_ID_CBS_MSG_BODY"/>
    <STRING id="STR_ID_CBS_ADD_CHNL"/>
    <STRING id="STR_ID_CBS_EDIT_CHNL"/>

        <STRING id="STR_ID_CBS_LANG_ARABIC"/>
        <STRING id="STR_ID_CBS_LANG_CZECH"/>
        <STRING id="STR_ID_CBS_LANG_DANISH"/>
        <STRING id="STR_ID_CBS_LANG_GERMAN"/>
        <STRING id="STR_ID_CBS_LANG_GREEK"/>
        <STRING id="STR_ID_CBS_LANG_ENGLISH"/>
        <STRING id="STR_ID_CBS_LANG_SPANISH"/>
        <STRING id="STR_ID_CBS_LANG_FINNISH"/>
        <STRING id="STR_ID_CBS_LANG_FRENCH"/>
        <STRING id="STR_ID_CBS_LANG_HEBREW"/>
        <STRING id="STR_ID_CBS_LANG_HUNGARIAN"/>
        <STRING id="STR_ID_CBS_LANG_ICELANDIC"/>
        <STRING id="STR_ID_CBS_LANG_ITALIAN"/>
        <STRING id="STR_ID_CBS_LANG_DUTCH"/>
        <STRING id="STR_ID_CBS_LANG_NORWEGIAN"/>
        <STRING id="STR_ID_CBS_LANG_POLISH"/>
        <STRING id="STR_ID_CBS_LANG_PORTUGUESE"/>
        <STRING id="STR_ID_CBS_LANG_RUSSIAN"/>
        <STRING id="STR_ID_CBS_LANG_SWEDISH"/>
        <STRING id="STR_ID_CBS_LANG_TURKISH"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>





        <IMAGE id="IMG_ID_CBS_COMMON">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_WRITE.bmp"</IMAGE>
        <IMAGE id="IMG_ID_CBS_CHNL_NAME">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\Channel\\\\CH_TITLE.bmp"</IMAGE>
        <IMAGE id="IMG_ID_CBS_CHNL_NUMBER">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\Channel\\\\CH_NB.bmp"</IMAGE>



        <IMAGE id="IMG_ID_CBS_SUBSCRIBE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_BROAD.bmp"</IMAGE>
        <IMAGE id="IMG_ID_CBS_UNSUBSCRIBE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Sms\\\\Submenu\\\\SB_CBS_UNSUB.bmp"</IMAGE>




    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <!--Menu Item Area-->
# 120 "temp/res/CbsApp.c"
    <MENUITEM id="MENU_ID_CBS_CHANNELS" str="STR_ID_CBS_CHANNELS" img="IMG_ID_CBS_COMMON"/>
    <MENUITEM id="MENU_ID_CBS_LANGUAGES" str="STR_ID_CBS_LANGUAGES" img="IMG_ID_CBS_COMMON"/>
    <MENUITEM id="MENU_ID_CBS_INBOX" str="STR_ID_CBS_INBOX" img="IMG_ID_CBS_COMMON"/>

    <MENUITEM id="MENU_ID_CBS_RECEIVE_MODE_ON" str="STR_GLOBAL_ON"/>
    <MENUITEM id="MENU_ID_CBS_RECEIVE_MODE_OFF" str="STR_GLOBAL_OFF"/>

    <MENUITEM id="MENU_ID_CBS_CHNL_OPT_SUBSCRIBE" str="STR_ID_CBS_SUBSCRIBE"/>
    <MENUITEM id="MENU_ID_CBS_CHNL_OPT_UNSUBSCRIBE" str="STR_ID_CBS_CANCEL_SUBSCRIPTION"/>
    <MENUITEM id="MENU_ID_CBS_CHNL_OPT_ADD" str="STR_GLOBAL_ADD"/>
    <MENUITEM id="MENU_ID_CBS_CHNL_OPT_EDIT" str="STR_GLOBAL_EDIT"/>
    <MENUITEM id="MENU_ID_CBS_CHNL_OPT_DELETE" str="STR_GLOBAL_DELETE"/>

    <MENUITEM id="MENU_ID_CBS_VIEWER_OPT_DELETE" str="STR_GLOBAL_DELETE"/>
    <MENUITEM id="MENU_ID_CBS_VIEWER_OPT_USE_NUM" str="STR_ID_SMS_USE_NUM_ADDRESS"/>




    <!--Menu Tree Area-->
# 153 "temp/res/CbsApp.c"
    <MENU id="MENU_ID_CBS_RECEIVE_MODE" type="APP_SUB" flag = "MMI_RG_MENU_FLAG_CHECKBOX" str="STR_ID_CBS_RECEIVE_MODE" img="IMG_ID_CBS_COMMON">
        <MENUITEM_ID>MENU_ID_CBS_RECEIVE_MODE_ON</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_RECEIVE_MODE_OFF</MENUITEM_ID>
    </MENU>

        <MENU id="MENU_ID_CBS_MAIN" type="APP_MAIN" str="STR_ID_CBS_CAPTION">
                <MENUITEM_ID>MENU_ID_CBS_RECEIVE_MODE</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_CBS_CHANNELS</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_CBS_LANGUAGES</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_CBS_INBOX</MENUITEM_ID>
        </MENU>

    <MENU id="MENU_ID_CBS_CHNL_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_CBS_CHNL_OPT_SUBSCRIBE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_CHNL_OPT_UNSUBSCRIBE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_CHNL_OPT_ADD</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_CHNL_OPT_EDIT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_CHNL_OPT_DELETE</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_CBS_VIEWER_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_CBS_VIEWER_OPT_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CBS_VIEWER_OPT_USE_NUM</MENUITEM_ID>



    </MENU>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_CBS_SIM_SELECT"/>
    <SCREEN id="SCR_ID_CBS_MAIN_MENU"/>
    <SCREEN id="SCR_ID_CBS_RECEIVE_MODE"/>
    <SCREEN id="SCR_ID_CBS_LANG_LIST"/>
    <SCREEN id="SCR_ID_CBS_CHNL_LIST"/>
    <SCREEN id="SCR_ID_CBS_CHNL_LIST_OPTIONS"/>
    <SCREEN id="SCR_ID_CBS_ADD_CHNL"/>
    <SCREEN id="SCR_ID_CBS_EDIT_CHNL"/>
    <SCREEN id="SCR_ID_CBS_INBOX_LIST"/>
    <SCREEN id="SCR_ID_CBS_VIEWER"/>
    <SCREEN id="SCR_ID_CBS_VIEWER_OPTION"/>
    <SCREEN id="SCR_ID_CBS_NEW_NORMAL_IND"/>
    <SCREEN id="SCR_ID_CBS_NEW_IMMEDIATE_IND"/>

    <!-----------------------------------------------Callback Manager Register------------------------------------------------------>
        <RECEIVER id="EVT_ID_SRV_CBS_NEW_MSG_IND" proc="mmi_cbs_new_msg_event_proc"/>
        <RECEIVER id="EVT_ID_SRV_CBS_GS_CHANGE_IND" proc="mmi_cbs_gs_change_event_proc"/>
        <RECEIVER id="EVT_ID_SRV_CBS_ADD_MSG" proc="mmi_cbs_msg_changed_event_proc"/>
        <RECEIVER id="EVT_ID_SRV_CBS_DEL_MSG" proc="mmi_cbs_msg_changed_event_proc"/>
        <RECEIVER id="EVT_ID_SRV_CBS_ADD_CHNL" proc="mmi_cbs_setting_changed_event_proc"/>
        <RECEIVER id="EVT_ID_SRV_CBS_DEL_CHNL" proc="mmi_cbs_setting_changed_event_proc"/>
        <RECEIVER id="EVT_ID_SRV_CBS_UPDATE_CHNL" proc="mmi_cbs_setting_changed_event_proc"/>
        <RECEIVER id="EVT_ID_SRV_CBS_MODE_CHANGE" proc="mmi_cbs_setting_changed_event_proc"/>
        <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_cbs_mode_switch_event_hdlr"/>

</APP>
