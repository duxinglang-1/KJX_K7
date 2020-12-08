# 1 "temp/res/GCallSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/GCallSrv.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/GCallSrv.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 4 "temp/res/GCallSrv.c" 2

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_GCALL">



    <!--Include Area-->

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <EVENT id="EVT_ID_SRV_GCALL_ACT" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_GCALL_CNF" type="SENDER"/>
    <RECEIVER id="EVT_ID_SRV_GCALL_ACT" proc="srv_gcall_post_act_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_GCALL_CNF" proc="srv_gcall_post_cnf_evt_hdlr"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <STRING id="STR_ID_GCALL_UNKNOWN_CALLER"/>
    <STRING id="STR_ID_GCALL_RESTRICTED"/>
    <STRING id="STR_ID_GCALL_UNAVAILABLE"/>

    <STRING id="STR_ID_GCALL_REJECT_BY_USER"/>
    <STRING id="STR_ID_GCALL_PAYPHONE"/>
    <STRING id="STR_ID_GCALL_LEFT_PARENTHESIS"/>
    <STRING id="STR_ID_GCALL_RIGHT_PARENTHESIS"/>

    <STRING id="STR_ID_GCALL_UNABLE_TO_CONNECT"/>
    <STRING id="STR_ID_GCALL_OP_FAIL"/>

    <STRING id="STR_ID_GCALL_UNRECOGNIZED_NUMBER"/>
    <STRING id="STR_ID_GCALL_NETWORK_FAIL"/>
    <STRING id="STR_ID_GCALL_BUSY_NETWORK_TRY_LATER"/>
    <STRING id="STR_ID_GCALL_USER_BUSY"/>
    <STRING id="STR_ID_GCALL_NETWORK_BUSY"/>
    <STRING id="STR_ID_GCALL_NOT_RESPONDING"/>
    <STRING id="STR_ID_GCALL_NO_ANSWER"/>
    <STRING id="STR_ID_GCALL_ACM_EXCEEDED"/>
    <STRING id="STR_ID_GCALL_UNEXPECTED_ERROR"/>
    <STRING id="STR_ID_GCALL_IMEI_ERROR"/>
    <STRING id="STR_ID_GCALL_GPRS_NOT_ALLOWED"/>
    <STRING id="STR_ID_GCALL_MT_DATA_CALL_FAIL"/>
    <STRING id="STR_ID_GCALL_NETWORK_NOT_ALLOWED"/>
    <STRING id="STR_ID_GCALL_COMMAND_NOT_SUPPORTED"/>
    <STRING id="STR_ID_GCALL_DATA_ERROR"/>
    <STRING id="STR_ID_GCALL_MESSAGE_TYPE_ERROR"/>
    <STRING id="STR_ID_GCALL_ACCESS_FAIL"/>
    <STRING id="STR_ID_GCALL_TIMER_EXPIRED"/>
    <STRING id="STR_ID_GCALL_CSD_DISCONNECTING"/>
    <STRING id="STR_ID_GCALL_INVALID_COMMAND"/>

    <STRING id="STR_ID_GCALL_FDN_FAIL"/>
    <STRING id="STR_ID_GCALL_CALL_ENDED"/>

    <STRING id="STR_ID_GCALL_BARRED_CALL"/>

    <STRING id="STR_ID_GCALL_CALL_ABORTED"/>
    <STRING id="STR_ID_GCALL_REDIAL"/>
    <STRING id="STR_ID_GCALL_REDIAL_TIMES"/>
    <STRING id="STR_ID_GCALL_REDIAL_NEXT_ATTEMPT"/>
    <STRING id="STR_ID_GCALL_REDIAL_SEC"/>
    <STRING id="STR_ID_GCALL_REDIAL_MIN"/>



    <STRING id="STR_ID_GCALL_DTMF_CONFIRMATION"/>
# 80 "temp/res/GCallSrv.c"
    <STRING id="STR_ID_GCALL_SS_NFY_CF_ON"/>

    <STRING id="STR_ID_GCALL_SS_NFY_ALL_BARRED"/>
    <STRING id="STR_ID_GCALL_SS_NFY_ALL_OUTGOING_BARRED"/>
    <STRING id="STR_ID_GCALL_SS_NFY_ALL_INCOMING_BARRED"/>
    <STRING id="STR_ID_GCALL_SS_NFY_WTG"/>
    <STRING id="STR_ID_GCALL_SS_NFY_HLD"/>
    <STRING id="STR_ID_GCALL_SS_NFY_RTVD"/>



    <STRING id="STR_ID_GCALL_SS_NFY_CONF"/>



    <STRING id="STR_ID_GCALL_SS_NFY_CUG"/>
    <STRING id="STR_ID_GCALL_SS_NFY_CLIR_REJECTED"/>
    <STRING id="STR_ID_GCALL_SS_NFY_CTFAC"/>
# 110 "temp/res/GCallSrv.c"
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>





    <IMAGE id="IMG_ID_GCALL_LINE1">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_line1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GCALL_LINE2">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_line2.bmp"</IMAGE>
# 149 "temp/res/GCallSrv.c"
    <IMAGE id="IMG_ID_GCALL_OUTGOING">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\Connect\\\\CL_NET.PNG"</IMAGE>







    <IMAGE id="IMG_ID_GCALL_CALL_ENDED">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\ended\\\\CL_END_removed.png."</IMAGE>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <!--Menu Tree Area-->





    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <TIMER id="SS_NOTIFY_TIMER"/>

</APP>
