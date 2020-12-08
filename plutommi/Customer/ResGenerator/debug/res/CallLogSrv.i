# 1 "temp/res/CallLogSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/CallLogSrv.c"
# 75 "temp/res/CallLogSrv.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 76 "temp/res/CallLogSrv.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 77 "temp/res/CallLogSrv.c" 2



<?xml version = "1.0" encoding = "UTF-8"?>


<APP id = "SRV_CALLLOG">


<!----------------- XML Begin ------------------------------------------------->

<!----------------- Include Area ---------------------------------------------->


<!----------------- Common ---------------------------------------------------->

    <!----------------- Event Id ------------------------------------------->
        <EVENT id="EVT_ID_SRV_CLOG_READY" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CLOG_ADD_LOG" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CLOG_UPDATE_LOG" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CLOG_UPDATE_ALL" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CLOG_DEL_LOG" type="SENDER"/>
        <EVENT id="EVT_ID_SRV_CLOG_DEL_ALL" type="SENDER"/>

        <RECEIVER id="EVT_ID_PHB_ADD_CONTACT" proc="srv_clog_phb_evt_hdlr"/>
        <RECEIVER id="EVT_ID_PHB_UPD_CONTACT" proc="srv_clog_phb_evt_hdlr"/>
        <RECEIVER id="EVT_ID_PHB_DEL_CONTACT" proc="srv_clog_phb_evt_hdlr"/>



        <RECEIVER id="EVT_ID_SRV_SHUTDOWN_HANDLER_RESET" proc="srv_clog_shutdown_evt_hdlr"/>



<!----------------- Common End ------------------------------------------------>






<!----------------- XML END --------------------------------------------------->

</APP>
