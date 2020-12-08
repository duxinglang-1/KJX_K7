# 1 "temp/res/Dataaccount.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/Dataaccount.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/Dataaccount.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/Dataaccount.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_DATAACCOUNT"
# 20 "temp/res/Dataaccount.c"
>



    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_DTCNT_RENAME"/>
    <STRING id="STR_ID_DTCNT_ADVANCED_SETTING"/>
    <STRING id="STR_ID_DTCNT_HOME_PAGE"/>
    <STRING id="STR_ID_DTCNT_CONNECTION_TYPE"/>
    <STRING id="STR_ID_DTCNT_USE_PROXY"/>
    <STRING id="STR_ID_DTCNT_PROXY_ADDRESS"/>
    <STRING id="STR_ID_DTCNT_PROXY_PORT"/>
    <STRING id="STR_ID_DTCNT_PROXY_USER_NAME"/>
    <STRING id="STR_ID_DTCNT_PROXY_PASS_WORD"/>
    <STRING id="STR_ID_DTCNT_DNS_ADDRESS1"/>
    <STRING id="STR_ID_DTCNT_DNS_ADDRESS2"/>
    <STRING id="STR_ID_DTCNT_IP_ADDRESS"/>
    <STRING id="STR_ID_DTCNT_SUBNET_MASK"/>
    <STRING id="STR_ID_DTCNT_ADD_GPRS"/>
    <STRING id="STR_ID_DTCNT_COLON"/>
    <STRING id="STR_ID_DTCNT_MAX_CSD_ACCOUNT_REACHED"/>
    <STRING id="STR_ID_DTCNT_NOT_ALLOW_DELETE"/>
    <STRING id="STR_ID_DTCNT_NOT_ALLOW_EDIT"/>
    <STRING id="STR_ID_DTCNT_GPRS_CHAP_AUTH"/>
    <STRING id="STR_ID_DTCNT_GPRS_APN"/>
    <STRING id="STR_ID_DTCNT_GPRS_AUTH_TYP"/>
    <STRING id="STR_ID_DTCNT_GPRS_INPUT_LACK"/>
    <STRING id="STR_ID_DTCNT_NAME_INVALID"/>
    <STRING id="STR_ID_DTCNT_CHANGE_DEFAULT"/>
# 68 "temp/res/Dataaccount.c"
    <STRING id="STR_ID_DTCNT_DELETE_ASK"/>

    <STRING id="STR_ID_DTCNT_ERR_MSG_INVALID_PORT"/>
    <STRING id="STR_ID_DTCNT_ERR_MSG_EMPTY_PORT_NUMBER"/>
    <STRING id="STR_ID_DTCNT_NOT_READY"/>

    <STRING id="STR_ID_DATA_CONNECTION_SIM"/>
    <STRING id="STR_ID_DATA_CONNECTION_SIM_NOT_ALLOW_CHANGED"/>
    <STRING id="STR_ID_DTCNT_NO_AVAILABLE_ACCOUNT"/>
# 389 "temp/res/Dataaccount.c"
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>



    <IMAGE id="SERVICES_DATA_CONNECT_IMAGE_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\submenu\\\\services\\\\DataAccount\\\\SB_DATA.bmp"</IMAGE>




    <IMAGE id="IMG_ID_DTCNT_NON_DEFAULT_ACCOUNT_ID">"..\\\\..\\\\Customer\\\\Images""\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DTCNT_DEFAULT_ACCOUNT_ID">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_V.BMP"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <MENUITEM id="MENU_ID_DTCNT_SIM_1" str="STR_GLOBAL_SIM_1"/>
# 413 "temp/res/Dataaccount.c"
    <MENU id="MENU_ID_DATA_CONNECTION_SIM" str="STR_ID_DATA_CONNECTION_SIM" highlight="mmi_data_connection_sim_hilite_hdlr">
        <MENUITEM_ID>MENU_ID_DTCNT_SIM_1</MENUITEM_ID>
# 424 "temp/res/Dataaccount.c"
    </MENU>
    <MENU id="SERVICES_DATA_CONNECT_MAIN_MENU_ID" str="STR_GLOBAL_DATA_ACCOUNTS" img="SERVICES_DATA_CONNECT_IMAGE_ID" highlight="DataConnectHiliteHandler"/>





        <MENUITEM id="MENU_ID_DTCNT_OPT_ADD_GPRS" str="STR_ID_DTCNT_ADD_GPRS"/>


        <MENU id="MENU_ID_DTCNT_ACCOUNT_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
                <MENUITEM id="MENU_ID_DTCNT_OPT_EDIT" str="STR_GLOBAL_EDIT"/>
                <MENUITEM_ID>MENU_ID_DTCNT_OPT_ADD_GPRS</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_DTCNT_OPT_ADD_CSD</MENUITEM_ID>
                <MENUITEM id="MENU_ID_DTCNT_OPT_DELETE" str="STR_GLOBAL_DELETE"/>
                <MENUITEM id="MENU_ID_DTCNT_OPT_CHANGE_DEFAULT" str="STR_ID_DTCNT_CHANGE_DEFAULT"/>
        </MENU>






        <MENUITEM id="MENU_ID_DTCNT_OPT2_ADD_GPRS" str="STR_ID_DTCNT_ADD_GPRS"/>

        <MENU id="MENU_ID_DTCNT_ACCOUNT_OPTION2" type="OPTION" str="STR_GLOBAL_OPTIONS">
                <MENUITEM_ID>MENU_ID_DTCNT_OPT2_ADD_GPRS</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_DTCNT_OPT2_ADD_CSD</MENUITEM_ID>
        </MENU>






        <MENUITEM id="MENU_ID_DTCNT_OPT3_ADD_GPRS" str="STR_ID_DTCNT_ADD_GPRS"/>

        <MENU id="MENU_ID_DTCNT_ACCOUNT_OPTION3" type="OPTION" str="STR_GLOBAL_OPTIONS">
                <MENUITEM id="MENU_ID_DTCNT_OPT3_VIEW" str="STR_GLOBAL_VIEW"/>
                <MENUITEM_ID>MENU_ID_DTCNT_OPT3_ADD_GPRS</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_DTCNT_OPT3_ADD_CSD</MENUITEM_ID>
                <MENUITEM id="MENU_ID_DTCNT_OPT3_CHANGE_DEFAULT" str="STR_ID_DTCNT_CHANGE_DEFAULT"/>
        </MENU>
# 838 "temp/res/Dataaccount.c"
    <!------------------------------------------------------Events---------------------------------------------------------->


    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_HOME_PLMN_CHANGED" proc="mmi_dtcnt_on_home_plmn_changed"/>

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="mmi_dtcnt_on_sim_detected"/>
    <RECEIVER id="EVT_ID_SRV_CBM_BEARER_INFO" proc="mmi_dtcnt_on_cbm_bearer_info"/>




    <!------------------------------------------------------Other Resource---------------------------------------------------------->
        <SCREEN id="GRP_ID_DTCNT"/>
    <SCREEN id="GRP_ID_DTCNT_PROV"/>
    <SCREEN id="GRP_ID_DATA_CONNECTION_SIM"/>
    <SCREEN id="SCR_ID_DTCNT_LIST"/>
    <SCREEN id="SCR_ID_DTCNT_LIST_OPTION"/>
    <SCREEN id="SCR_ID_DTCNT_CSD_COMMON"/>
    <SCREEN id="SCR_ID_DTCNT_GPRS_COMMON"/>
    <SCREEN id="SCR_ID_DTCNT_ADVANCED"/>
    <SCREEN id="SCR_ID_DTCNT_OTA_LIST"/>
    <SCREEN id="SCR_ID_DTCNT_EDIT"/>
    <SCREEN id="SCR_ID_DTCNT_NOTIFICATION"/>
    <SCREEN id="SCR_ID_DTCNT_MAIN"/>
    <SCREEN id="SCR_ID_DTCNT_GPRS_LIST"/>
    <SCREEN id="SCR_ID_DTCNT_OTA_GPRS_LIST"/>

    <SCREEN id="SCR_ID_DTCNT_LIST_ALWAYS_ASK"/>
    <SCREEN id="SCR_ID_DTCNT_LIST_ACCOUNT_SELECTION"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_NORMAL_LIST"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_SIM_LIST"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_NORMAL_DUAL_ACCT_LIST_EACH"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_CBM_LIST"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_WLAN_LIST"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_WLAN_SEARCH_PROCESS"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_PASSPHRASE_INPUT"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_WAPI_PSK_INPUT"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_WAPI_CERT_INPUT"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_CSD_COMMON_VIEW"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_GPRS_COMMON_VIEW"/>
    <SCREEN id="SCR_ID_DTCNT_CUI_ADVANCED_VIEW"/>

    <SCREEN id="SCR_ID_DTCNT_OTA_MAIN"/>

    <SCREEN id="SCR_ID_DTCNT_PROGRESSING"/>
# 957 "temp/res/Dataaccount.c"
</APP>
