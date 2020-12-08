#include "MMI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_MRE_APPMGR">
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    <!-----------------------------------------------------MRE AppMgr Shortcut app Resource Area------------------------------------------------------>
    //#ifdef MRE_APPMGR_SC_QQ
    #ifdef __MMI_MRE_SHORTCUT_QQ__
    <STRING id="STR_ID_MRE_APPMGR_NAME_QQ"/>
    <IMAGE id="IMG_ID_MRE_APPMGR_QQ" >RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\QQ.png"</IMAGE>
    #endif
   
    //#ifdef MRE_APPMGR_SC_OPERA
    #ifdef __MMI_MRE_SHORTCUT_OPERA__
    <STRING id="STR_ID_MRE_APPMGR_NAME_OPERA"/>
    <IMAGE id="IMG_ID_MRE_APPMGR_OPERA" >RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\Opera.png"</IMAGE>
    #endif
       <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="srv_mre_push_event_hdlr"/>
		<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="srv_mre_push_event_hdlr"/>
		<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="srv_mre_push_event_hdlr"/>
		<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="srv_mre_push_event_hdlr"/>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

</APP>

