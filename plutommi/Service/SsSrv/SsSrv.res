/* Needed header files of the compile option in XML files, if you need others need to add here */

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_SS">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <EVENT id="EVT_ID_SRV_SS_INDICATION" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SS_ACT_RESPONSE"/>
    <EVENT id="EVT_ID_SRV_SS_ACT_NOTIFY" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_SS_INT_ACT"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <STRING id="STR_ID_SRV_SS_BS_ALL_TELESERVICES"/>
    <STRING id="STR_ID_SRV_SS_BS_TELEPHONY"/>
    <STRING id="STR_ID_SRV_SS_BS_ALL_DATA_TELESERVICES"/>
    <STRING id="STR_ID_SRV_SS_BS_FACSIMILE_SERVICES"/>
    <STRING id="STR_ID_SRV_SS_BS_SHORT_MESSAGE_SERVICES"/>
    <STRING id="STR_ID_SRV_SS_BS_ALL_TELESERVICES_EXCEPT_SMS"/>
    <STRING id="STR_ID_SRV_SS_BS_VOICE_GROUP_CALL_SERVICE"/>
    <STRING id="STR_ID_SRV_SS_BS_VOICE_BROADCAST_SERVICE"/>
    <STRING id="STR_ID_SRV_SS_BS_ALL_BEARER_SERVICES"/>
    <STRING id="STR_ID_SRV_SS_BS_ALL_ASYNC_SERVICES"/>
    <STRING id="STR_ID_SRV_SS_BS_ALL_SYNC_SERVICES"/>
    <STRING id="STR_ID_SRV_SS_BS_ALL_DATA_CIRCUIT_SYNC"/>
    <STRING id="STR_ID_SRV_SS_BS_ALL_DATA_CIRCUIT_ASYNC"/>
    <STRING id="STR_ID_SRV_SS_BS_ALL_GPRS_BEARER_SERVICES"/>
    <STRING id="STR_ID_SRV_SS_BS_BS_ALLPADACCESSCA_SERVICES"/>
    <STRING id="STR_ID_SRV_SS_BS_BS_ALLDATAPDS_SERVICES"/>
    #ifdef __MMI_SS_SHOW_CAUSE__
    <STRING id="STR_ID_SRV_SS_UNKNOWN_CAUSE"/>
    #endif
    <STRING id="STR_ID_SRV_SS_BAOC"/>
    <STRING id="STR_ID_SRV_SS_BOIC"/>
    <STRING id="STR_ID_SRV_SS_BOICEXHC"/>
    <STRING id="STR_ID_SRV_SS_BAIC"/>
    <STRING id="STR_ID_SRV_SS_BAICROAM"/>
    <STRING id="STR_ID_SRV_SS_BAC"/>
    <STRING id="STR_ID_SRV_SS_BOC"/>
    <STRING id="STR_ID_SRV_SS_BIC"/>
    <STRING id="STR_ID_SRV_SS_CB_UNKNOWN"/>
    <STRING id="STR_ID_SRV_SS_CFU"/>
    <STRING id="STR_ID_SRV_SS_CFB"/>
    <STRING id="STR_ID_SRV_SS_CFNRY"/>
    <STRING id="STR_ID_SRV_SS_CFNRC"/>
    <STRING id="STR_ID_SRV_SS_CFA"/>
    <STRING id="STR_ID_SRV_SS_CFC"/>
    <STRING id="STR_ID_SRV_SS_CF_UNKNOWN"/>
    <STRING id="STR_ID_SRV_SS_CW"/>  
    <STRING id="STR_ID_SRV_SS_ACTIVATED"/>
    <STRING id="STR_ID_SRV_SS_ACTIVATED_PERMANENTLY"/>
    <STRING id="STR_ID_SRV_SS_ACTIVATED_BY_DEFAULT"/>
    <STRING id="STR_ID_SRV_SS_DEACTIVATED"/>
    <STRING id="STR_ID_SRV_SS_DEACTIVATED_BY_DEFAULT"/>
    <STRING id="STR_ID_SRV_SS_PROVIDED"/>
    <STRING id="STR_ID_SRV_SS_NOT_PROVIDED"/>
    <STRING id="STR_ID_SRV_SS_WRONG_PASSWD"/>
    <STRING id="STR_ID_SRV_SS_BLOCK"/>
    <STRING id="STR_ID_SRV_SS_CLIP"/>
    <STRING id="STR_ID_SRV_SS_CLIR"/>
    <STRING id="STR_ID_SRV_SS_COLP"/>
    <STRING id="STR_ID_SRV_SS_COLR"/>
    <STRING id="STR_ID_SRV_SS_CNAP"/>
    <STRING id="STR_ID_SRV_SS_CCBS"/>
    <STRING id="STR_ID_SRV_SS_EMLPP"/>
    <STRING id="STR_ID_SRV_SS_NOT_AVAILABLE"/>
    <STRING id="STR_ID_SRV_SS_FDN_FAIL"/>




    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */


    /* For the detail of scope="XML" please check user manual */


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!--Menu Tree Area-->

    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */

    <!------------------------------------------------------Other Resource---------------------------------------------------------->


</APP>
