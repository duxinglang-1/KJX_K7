# 1 "temp/res/vObjects.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/vObjects.c"

# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 3 "temp/res/vObjects.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 4 "temp/res/vObjects.c" 2


<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "SRV_VOBJECT">

    <INCLUDE file = "GlobalResDef.h"/>
    <!--------------------------------------------------------------------------------------------------------------------->
    <!--String Resource Area-->
    <!--String Resource Area-->
    <STRING id="STR_ID_VCARD"/>
    <STRING id="STR_ID_VCLNDR"/>
    <STRING id="STR_ID_VBKM"/>


    <STRING id="STR_ID_VOBJ_RECV_VCARD"/>



    <STRING id="STR_ID_VOBJ_RECV_VCLNDR"/>






    <STRING id="STR_ID_VOBJ_RECEIVE_FALL"/>


    <STRING id="STR_ID_VOBJ_FORWARD_TO_FILE_MGR"/>
    <STRING id="STR_ID_VOBJ_DUPLICATE_FILENAME"/>
    <STRING id="STR_ID_VOBJ_FILE_PATH_TOO_LONG"/>


        <!--End String Resource Area-->
    <!--End String Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->

        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
        <!--Screen ID Area-->

    <SCREEN id = "SCR_ID_VOBJ_RECV_OBJECT"/>
    <SCREEN id = "GRP_ID_VOBJ_BEGIN"/>
    <SCREEN id = "GRP_ID_VOBJ_REC_IMPS"/>
    <SCREEN id = "GRP_ID_VOBJ_REC_IDLE"/>
    <SCREEN id = "GRP_ID_VOBJ_END"/>

        <!--End Screen Resource Area-->
        <!--End Screen Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->


        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Menu Item Area-->
        <!--Menu Item Area-->

    <MENUITEM id = "MENU_ID_VOBJ_FMGR_SEND_SMS" str = "@OID:STR_GLOBAL_AS_TEXT_MESSAGE"/>


    <FILE_TYPES>
        <FILE_OPTION_HDLR option="MENU_ID_VOBJ_FMGR_SEND_SMS" enabler="mmi_vobj_fmgr_use_enabler" handler="mmi_vobj_fmgr_use_handler"/>
    </FILE_TYPES>


    <!--End Menu Item Area-->
    <!--End Menu Item Area-->
    <!--------------------------------------------------------------------------------------------------------------------->


    <!--------------------------------------------------------------------------------------------------------------------->
    <!--Event proc Area-->
    <!--Event proc Area-->


    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="mmi_vobj_exit_usb_ms_callback"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_vobj_phone_format_handler"/>


    <!--Event proc Area-->
    <!--Event proc Area-->
    <!--------------------------------------------------------------------------------------------------------------------->

</APP>
