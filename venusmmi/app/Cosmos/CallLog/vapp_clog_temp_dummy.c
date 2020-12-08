#include "MMI_include.h"
#include "CallLogGprot.h"


void mmi_clog_launch(void)
{
}

void mmi_clog_sendkey_launch(void)
{
}

void mmi_clog_dclt_launch(void)
{
}

void mmi_clog_mclt_launch(void)
{
}

void mmi_clog_rclt_launch(void)
{
}

void mmi_clog_aclt_launch(void)
{
}

MMI_BOOL mmi_clog_nmgr_check(void)
{
    return MMI_FALSE;
}

void mmi_clog_nmgr_enter(void)
{
}

void mmi_clog_nmgr_query(void)
{
}

void mmi_clog_clear_all_new_events(void)
{
}

void mmi_clog_hs_re_query_data(S32 num)
{
}

MMI_RET mmi_clog_act_init_prop(mmi_clog_act_prop_struct *prop)
{
    return MMI_RET_ERR;
}

MMI_ID mmi_clog_act_apply(MMI_ID parent_gid, mmi_clog_act_prop_struct *prop)
{
    return 0;
}

MMI_IMG_ID mmi_clog_get_log_icon(const srv_clog_log_identity_struct *idt)
{
    return 0;
}

void mmi_clog_op11_hs_stnt_check_num(void)
{
}

void mmi_clog_op11_hs_idct_check_num(void)
{
}

void mmi_clog_op11_hs_menu_query_data(S32 num)
{
}

void mmi_clog_hs_re_clear_all(void)
{
}

void mmi_clog_op11_hs32_sb_check_num(S32 sidebar_id, S32 indctr_id)
{
}

void mmi_clog_op11_hs32_shct_query_data(S32 sidebar_id, S32 shct_id, void *shct_data)
{
}




#define MMI_V_CHARGER_DUMMY_START

#include "PoweronChargerProt.h"
#include "device.h"
#include "charbatsrvgprot.h"
#include "ProtocolEvents.h"

charbat_context_struct g_charbat_context = 
{
    0,                  /* g_charbat_context.PowerOnCharger */
    0,                  /* g_charbat_context.PowerOnChargingPeriod */
    0,                  /* g_charbat_context.ChargingAbnormal */
    0,                  /* g_charbat_context.ChargingComplete */
    0,                  /* g_charbat_context.LowBatteryFlag */
    0,                  /* g_charbat_context.LowBatteryTxProhibitFlag */
    BATTERY_LEVEL_0,    /* g_charbat_context.chargerLevel */
    PMIC_VBAT_STATUS,   /* g_charbat_context.batteryStatus */
    0,                  /* g_charbat_context.isChargerConnected */
    0,                  /* g_charbat_context.LowBatteryCutOffCallCnt */
    0                   /* g_charbat_context.BatteryNotifyModId */    
};

/***************************************************************************** 
* Local Variable
*****************************************************************************/
MMI_BOOL mmi_devmgr_is_charging = MMI_FALSE;


/***************************************************************************** 
* Local Function
*****************************************************************************/
mmi_ret mmi_charger_enable_charging_icon(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}


void InitChargerPwrOn()
{
    srv_charbat_init_event_hdlr();
}


void mmi_charbat_update_status_icon(void)
{
}

void InitializeChargingScr(void)
{
#ifdef __MMI_USB_SUPPORT__
{
    extern void vapp_launch_charger(void);
    vapp_launch_charger();
}
#endif
}


void BatteryStatusRsp(void *info)
{
    srv_charbat_status_ind_hdlr(info);
}


mmi_ret mmi_charbat_main_evt_hdlr(mmi_event_struct* para)
{
    return MMI_RET_OK;
}


mmi_ret mmi_charbat_other_evt_hdlr(mmi_event_struct* evt)
{
    return MMI_RET_OK;
}


void LowBatteryCommonAction(void) // will be phase out
{
    // please refer srv_charbat_low_battery_common_action();
}


void BatteryStatusIndication(U8 battery_voltage)
{
}


BOOL IS_LOW_BATTERY(void)
{
    return srv_charbat_is_low_battery();
}


void BatteryIndicationPopup(U16 stringId)
{
}


MMI_BOOL mmi_pwron_abnormal_charing_entry_func(mmi_scenario_id scen_id, void *arg)
{
    return MMI_TRUE;
}

void IdleScreenChargerConnected(U8 playtone)
{
}


void IdleScreenChargerDisconnected(void)
{
}

void IdleScreenBatteryFullCharged(void)
{
}


void mmi_charger_bootup_callback(void)
{
}

void ChgrPlayLowBatTone(void)
{
}

U8 mmi_gpio_get_current_battery_level(void)
{
    return (U8)srv_charbat_get_battery_level();
}

MMI_BOOL mmi_gpio_is_charger_connected(void)
{
    return srv_charbat_is_charging();
}

/*MMI_BOOL mmi_gpio_is_charging_full(void)
{
    return srv_charbat_get_charger_status(SRV_CHARBAT_STATUS_CHARGE_COMPLETE);    
}*/

void mmi_devmgr_charger_send_ack(U8 action)
{
    srv_charbat_send_ack(action);
}





