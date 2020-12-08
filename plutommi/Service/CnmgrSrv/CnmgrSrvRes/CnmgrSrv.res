#include "MMI_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_CNMGR">

#ifdef __TCPIP__

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <EVENT id="EVT_ID_SRV_CNMGR_NOTIFY_NWINFO" type="SENDER"/>
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)   
    <RECEIVER id="EVT_ID_GPIO_AFTER_LCD_SLEEP_IN" proc="srv_cnmgr_gpio_lcd_sleep_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="srv_cnmgr_gpio_lcd_sleep_evt_hdlr"/>
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */
    <TIMER id="SRV_CNMGR_TIMER_ID" />

#endif /* __TCPIP__ */

</APP>

