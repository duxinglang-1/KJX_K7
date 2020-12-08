/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_GCALL">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    
    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <EVENT id="EVT_ID_SRV_GCALL_ACT" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_GCALL_CNF" type="SENDER"/>
    <RECEIVER id="EVT_ID_SRV_GCALL_ACT" proc="srv_gcall_post_act_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_GCALL_CNF" proc="srv_gcall_post_cnf_evt_hdlr"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <STRING id="STR_ID_GCALL_UNKNOWN_CALLER"/>
    <STRING id="STR_ID_GCALL_RESTRICTED"/>
    <STRING id="STR_ID_GCALL_UNAVAILABLE"/>
#ifdef __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__
    <STRING id="STR_ID_GCALL_REJECT_BY_USER"/>
    <STRING id="STR_ID_GCALL_PAYPHONE"/>
    <STRING id="STR_ID_GCALL_LEFT_PARENTHESIS"/>
    <STRING id="STR_ID_GCALL_RIGHT_PARENTHESIS"/>
#endif
    <STRING id="STR_ID_GCALL_UNABLE_TO_CONNECT"/>
    <STRING id="STR_ID_GCALL_OP_FAIL"/>
#ifdef __MMI_UCM_DETAIL_ERROR_MSG__
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
#endif /* __MMI_UCM_DETAIL_ERROR_MSG__ */
    <STRING id="STR_ID_GCALL_FDN_FAIL"/>
    <STRING id="STR_ID_GCALL_CALL_ENDED"/>
#ifdef __MMI_UCM_DETAIL_ERROR_MSG__
    <STRING id="STR_ID_GCALL_BARRED_CALL"/>
#endif /* __MMI_UCM_DETAIL_ERROR_MSG__ */
    <STRING id="STR_ID_GCALL_CALL_ABORTED"/>
    <STRING id="STR_ID_GCALL_REDIAL"/>
    <STRING id="STR_ID_GCALL_REDIAL_TIMES"/>
    <STRING id="STR_ID_GCALL_REDIAL_NEXT_ATTEMPT"/>
    <STRING id="STR_ID_GCALL_REDIAL_SEC"/>
    <STRING id="STR_ID_GCALL_REDIAL_MIN"/>
#ifdef __CCBS_SUPPORT__
    <STRING id="STR_ID_GCALL_CCBS_NFY"/>
#endif
    <STRING id="STR_ID_GCALL_DTMF_CONFIRMATION"/>
#if 0 /* don't display detail info */
    <STRING id="STR_ID_GCALL_SS_NFY_FWDNG_CONDITIONAL"/>
    <STRING id="STR_ID_GCALL_SS_NFY_FWDNG_UNCONDITIONAL"/>
    <STRING id="STR_ID_GCALL_SS_NFY_FWDED"/>
    <STRING id="STR_ID_GCALL_SS_NFY_FWDED_UNCONDITIONAL"/>
    <STRING id="STR_ID_GCALL_SS_NFY_FWDED_CONDITIONAL"/>
    <STRING id="STR_ID_GCALL_SS_NFY_BUSY_FORWARDED"/>
    <STRING id="STR_ID_GCALL_SS_NFY_FWDED_NOREPLY"/>
    <STRING id="STR_ID_GCALL_SS_NFY_FWDED_NOT_REACHABLE"/>
#else
    <STRING id="STR_ID_GCALL_SS_NFY_CF_ON"/>
#endif
    <STRING id="STR_ID_GCALL_SS_NFY_ALL_BARRED"/>
    <STRING id="STR_ID_GCALL_SS_NFY_ALL_OUTGOING_BARRED"/>
    <STRING id="STR_ID_GCALL_SS_NFY_ALL_INCOMING_BARRED"/>
    <STRING id="STR_ID_GCALL_SS_NFY_WTG"/>
    <STRING id="STR_ID_GCALL_SS_NFY_HLD"/>
    <STRING id="STR_ID_GCALL_SS_NFY_RTVD"/>
#if 0
    <STRING id="STR_ID_GCALL_SS_NFY_SWAP"/>
#endif
    <STRING id="STR_ID_GCALL_SS_NFY_CONF"/>
#if 0
    <STRING id="STR_ID_GCALL_SS_NFY_SPLIT"/>
#endif
    <STRING id="STR_ID_GCALL_SS_NFY_CUG"/>
    <STRING id="STR_ID_GCALL_SS_NFY_CLIR_REJECTED"/>
    <STRING id="STR_ID_GCALL_SS_NFY_CTFAC"/>
#if 0 /* don't display detail info */
    <STRING id="STR_ID_GCALL_SS_NFY_IS_FORWARDED"/>
    <STRING id="STR_ID_GCALL_SS_NFY_IS_FORWARDED_CALL"/>
#endif
#ifdef __OP21__    
    <STRING id="STR_ID_GCALL_NUMBER_NOT_AVAILABLE"/>
    <STRING id="STR_ID_GCALL_CALLER_USER_NOT_AVAILABLE"/>
    <STRING id="STR_ID_GCALL_NOT_AVAILABLE_USER"/>
    <STRING id="STR_ID_GCALL_BUSY_NUMBER"/>
    <STRING id="STR_ID_GCALL_NOT_ANSWER_FROM_USER"/>
#endif /* __OP21__ */
    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    /* For the detail of scope="XML" please check user manual */

#if defined(__COSMOS_MMI_PACKAGE__) || !defined(__MMI_UCM_SLIM__)
    <IMAGE id="IMG_ID_GCALL_LINE1">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_line1.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GCALL_LINE2">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_line2.bmp"</IMAGE>
#endif /* defined(__COSMOS_MMI_PACKAGE__) || !defined(__MMI_UCM_SLIM__) */

#ifdef __MMI_UCM_NUMBER_TYPE__
    <IMAGE id="IMG_ID_GCALL_NUMBER_MOBILE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_mobile.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GCALL_NUMBER_HOME">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_home.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GCALL_NUMBER_OFFICE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_office.bmp"</IMAGE>
    <IMAGE id="IMG_ID_GCALL_NUMBER_FAX">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Outgoing\\\\CL_fax.bmp"</IMAGE>
#endif /* __MMI_UCM_NUMBER_TYPE__ */

#if defined(__COSMOS_MMI_PACKAGE__)
    <THEME>
        <IMAGE id="IMG_ID_GCALL_OUTGOING"               desc = "Outgoing call default image"/>
    #ifdef __MMI_VIDEO_TELEPHONY__
        <IMAGE id="IMG_ID_GCALL_VT_OUTGOING_CALL"       desc = "Outgoing VT call default image"/>
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    </THEME>
#elif defined(__MMI_FTE_SUPPORT__)
#if defined(__FTE_NON_SLIM_RES__)
    <IMAGE id="IMG_ID_GCALL_OUTGOING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\CL_NET"</IMAGE>
#else
    <IMAGE id="IMG_ID_GCALL_OUTGOING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\CL_NET.png"</IMAGE>
#endif
#ifdef __MMI_VIDEO_TELEPHONY__
    <IMAGE id="IMG_ID_GCALL_VT_OUTGOING_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoTelephony\\\\Outgoing\\\\CL_VOutgoing.PNG"</IMAGE>
#endif /* __MMI_VIDEO_TELEPHONY__ */
#elif defined(__OP01__FWPBW__)
    <IMAGE id="IMG_ID_GCALL_OUTGOING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\CL_NET.bmp"</IMAGE>
#ifdef __MMI_VIDEO_TELEPHONY__
    <IMAGE id="IMG_ID_GCALL_VT_OUTGOING_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoTelephony\\\\Outgoing\\\\CL_VOutgoing.bmp"</IMAGE>
#endif /* __MMI_VIDEO_TELEPHONY__ */
#else /* Normal */
    <IMAGE id="IMG_ID_GCALL_OUTGOING">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Connect\\\\CL_NET.PNG"</IMAGE>
#ifdef __MMI_VIDEO_TELEPHONY__
    <IMAGE id="IMG_ID_GCALL_VT_OUTGOING_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\Video\\\\VideoTelephony\\\\Outgoing\\\\CL_VOutgoing.gif"</IMAGE>
#endif /* __MMI_VIDEO_TELEPHONY__ */
#endif /* __COSMOS_MMI_PACKAGE__ */
#if defined(__FTE_NON_SLIM_RES__)
    <IMAGE id="IMG_ID_GCALL_CALL_ENDED">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\ended\\\\CL_END"__MMI_RES_TYPE_POPUP_SCREEN__</IMAGE>
#else
    <IMAGE id="IMG_ID_GCALL_CALL_ENDED">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\ended\\\\CL_END_removed.png."</IMAGE>
#endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!--Menu Tree Area-->

    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <TIMER id="SS_NOTIFY_TIMER"/>

</APP>
