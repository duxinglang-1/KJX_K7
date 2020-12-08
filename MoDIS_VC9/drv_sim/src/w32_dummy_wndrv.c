#ifndef __MTK_TARGET__

#include "kal_release.h"
#include "syscomp_config.h"

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "app_buff_alloc.h"
#include "stack_ltlcom.h"

#include "wndrv_cnst.h"
#include "wndrv_ft_types.h"

/*
add for eap dummy functions
*/
#include "wndrv_supc_types.h"
#include "supc_abm_msgs.h"
#include "supc_inc.h"
#include "certman_defs.h"
#include "certman_struct.h"
#include "w32_dummy_wndrv.h"


/**/
kal_uint8      WNDRV_PTA_isOFF;        /* PTA Default is disable */
kal_uint32     Protocol_Status4WLAN = 0;
kal_uint32     BT_STATE_Report2WLAN = 0;

typedef struct
{
    kal_uint32 msg_index;
    kal_char* arg_type;
} trc_msg_type;

/**/

msg_type supc_msg_mapping_table[] =
{
	MSG_ID_TST_INJECT_STRING,
	MSG_ID_SIM_READY_IND,
	MSG_ID_TIMER_EXPIRY,
	MSG_ID_WNDRV_SUPC_DATA_IND,
	MSG_ID_SUPC_ABM_WIFI_INIT_REQ,
	MSG_ID_SUPC_ABM_WIFI_DEINIT_REQ,//5
	MSG_ID_WNDRV_SUPC_INIT_CNF,
	MSG_ID_WNDRV_SUPC_DEINIT_CNF,
	MSG_ID_WNDRV_SUPC_NETWORK_CONNECT_IND,
	MSG_ID_WNDRV_SUPC_NETWORK_CONNECT_FAIL_IND,
	MSG_ID_WNDRV_SUPC_NETWORK_DISCONNECT_IND,//10
	MSG_ID_WNDRV_SUPC_NETWORK_STATISTICS_IND,
	MSG_ID_WNDRV_SUPC_SITE_SURVEY_IND,
	MSG_ID_WNDRV_SUPC_PMKID_CANDIDATE_IND,
	MSG_ID_WNDRV_SUPC_STATUS_IND,
	MSG_ID_WNDRV_SUPC_QUERY_CAPABILITY_IND,//15
	MSG_ID_SUPC_ABM_WIFI_CONNECT_REQ,
	MSG_ID_SUPC_ABM_WIFI_DISCONNECT_REQ,
	MSG_ID_SUPC_ABM_WIFI_AP_LIST_REQ,
#ifdef __CERTMAN_SUPPORT__	
	MSG_ID_CERTMAN_GET_CERT_BY_ID_CNF,
	MSG_ID_CERTMAN_GET_PRIVKEY_CNF,//20
	MSG_ID_CERTMAN_GET_CERT_CHAIN_CNF,
#endif	
	MSG_ID_SUPC_ABM_WIFI_DISCONNECT_CNF,
	MSG_ID_SUPC_ABM_WIFI_DISCONNECT_IND,
	MSG_ID_SUPC_ABM_WIFI_CONNECT_IND,
	MSG_ID_SUPC_ABM_WIFI_CONNECT_CNF,//25
	MSG_ID_WNDRV_SUPC_PMKID_UPDATE_REQ,
	MSG_ID_WNDRV_SUPC_DATA_REQ,
	MSG_ID_WNDRV_SUPC_INIT_REQ,
	MSG_ID_WNDRV_SUPC_AUTH_STATE_UPDATE_REQ,
	MSG_ID_WNDRV_SUPC_BLACKLIST_UPDATE_REQ,//30
	MSG_ID_WNDRV_SUPC_DEINIT_REQ,
	MSG_ID_WNDRV_SUPC_ADD_KEY_REQ,
	MSG_ID_SUPC_MMI_WIFI_CURR_AP_INFO_IND,
	MSG_ID_WNDRV_SUPC_QUERY_CAPABILITY_REQ,
	MSG_ID_SUPC_ABM_WIFI_AP_LIST_CNF,//35
	MSG_ID_SUPC_ABM_WIFI_INIT_CNF,
	MSG_ID_SUPC_ABM_WIFI_DEINIT_CNF,
	MSG_ID_SIM_READ_REQ,
	MSG_ID_WNDRV_SUPC_JOIN_NETWORK_REQ,
	MSG_ID_WNDRV_SUPC_DISJOIN_NETWORK_REQ, //40
	MSG_ID_WNDRV_SUPC_SITE_SURVEY_REQ,
	MSG_ID_WNDRV_SUPC_CHIP_POWERON_REQ,
	MSG_ID_WNDRV_SUPC_CHIP_POWEROFF_REQ,
	MSG_ID_WNDRV_SUPC_REMOVE_KEY_REQ
};

module_type supc_module_mapping_table[] =
{
  MOD_SUPC,
  MOD_ABM,
  MOD_WNDRV,
  MOD_MMI,
  MOD_SIM,
  MOD_TIMER
};

sap_type supc_sap_mapping_table[] =
{
	SUPC_ABM_SAP,
	WNDRV_SUPC_SAP,
	SUPC_MMI_SAP,
	PS_SIM_SAP
};

kal_uint32 supc_debug_level = MOD_SUPC;

kal_bool wndrv_create(comptask_handler_struct **handle)
{
	return 0;
}

kal_bool dhcp_create(comptask_handler_struct **handle)
{
	return 0;
}

kal_bool hostap_task_create(comptask_handler_struct **handle)
{
	return 0;
}

void RFTool_WiFi_EEPROM_Read(kal_uint32 eeprom_index, kal_uint16 *eeprom)
{
        
}

void RFTool_WiFi_EEPROM_Write(kal_uint32 eeprom_index, kal_uint16 eeprom)
{

}

void RFTool_WiFi_BBCR_Read(kal_uint32 bbcr_index, kal_uint8 *bbcr)
{

}

void RFTool_WiFi_BBCR_Write(kal_uint32 bbcr_index, kal_uint8 bbcr)
{

}

void RFTool_WiFi_MCR16_Write(kal_uint32 mcr_index, kal_uint16 mcr16)
{

}

void RFTool_WiFi_MCR16_Read(kal_uint32 mcr_index, kal_uint16 *mcr16)
{

}

void RFTool_WiFi_MCR32_Write(kal_uint32 mcr_index, kal_uint32 mcr32)
{

}

void RFTool_WiFi_MCR32_Read(kal_uint32 mcr_index, kal_uint32 *mcr32)
{

}

void RFTool_WiFi_PwrMgt(wndrv_test_pwr_mgt_enum pwr_mgt)
{
        
}

void RFTool_WiFi_PktRx(kal_uint32 ch_freq, void (* callback) (wndrv_test_rx_status_struct* result))
{
        
}

void RFTool_WiFi_PktTx(kal_uint8 country_code[2], wndrv_test_pkt_tx_struct pkt_tx)
{
        
}

void RFTool_WiFi_LocalFreq(kal_uint8 country_code[2], wndrv_test_tx_struct local_freq)
{
        
}

void RFTool_WiFi_CarrierSupp(kal_uint8 country_code[2], wndrv_test_tx_struct carrier_supp)
{
        
}

void RFTool_WiFi_ContTx(kal_uint8 country_code[2], wndrv_test_tx_struct cont_tx)
{
        
}

void RFTool_WiFi_DacDCOffset(kal_uint8 *i_ch, kal_uint8 *q_ch)
{
	
}

void RFTool_WiFi_EnterNormalMode(void)
{
        
}

void RFTool_WiFi_EnterTestMode(void)
{
	
}

void RFTool_WiFi_Stop(void)
{
        
}

void RFTool_WiFi_EFUSE_Write(kal_uint32 efuse_index, kal_uint32 efuse)
{

}

void RFTool_WiFi_EFUSE_Read(kal_uint32 efuse_index, kal_uint32 *efuse)
{

}

kal_uint32 wndrv_query_chip_capability(void)
{
    return 1;
}

void wndrv_PowerSave_Ctrl (kal_uint8 bCtl)
{
}

kal_uint8 wndrv_PS_GetHandle (kal_int8 *psName)
{
    return 1;
}

void wndrv_PS_Enable (kal_uint8 handle)
{

}

void wndrv_PS_Disable(kal_uint8 handle)
{
        
}
void wndrv_set_Protocol_Status(kal_uint32 value, kal_uint32 mask)
{

}

kal_bool wndrv_chip_isOK(void)
{
    return 0;
}

kal_int32  wndrv_hdl_lcd_sleep_in(void *event)
{
    return 0;
}

kal_int32  wndrv_hdl_lcd_sleep_out(void *event)
{
    return 0;
}

void* wifi_construct_local_para(kal_uint16 local_para_size, kal_uint32 direction)
{
    return construct_local_para(local_para_size, direction);
}


void* wifi_construct_peer_buff(kal_uint16 pdu_len, kal_uint16  header_len,
                               kal_uint16 tail_len, kal_uint32 direction)
{
    return construct_peer_buff(pdu_len, header_len, tail_len, direction);
}

void wifi_free_local_para(local_para_struct *local_para_ptr)
{
    free_local_para(local_para_ptr);
}

void wifi_free_peer_buff(peer_buff_struct *pdu_ptr)
{
    free_peer_buff(pdu_ptr);
}

void* wifi_get_ctrl_buffer(kal_uint32 buff_size)
{
    return get_ctrl_buffer(buff_size);
}

void wifi_free_ctrl_buffer(void *usr_buff)
{
    free_ctrl_buffer(usr_buff);
}

void wifi_free_ilm(ilm_struct *ilm_ptr)
{
    free_ilm(ilm_ptr);
}

void wifi_assert_fail(char* expr, char* file, kal_uint32 line, kal_uint32 ex1, kal_uint32 ex2, kal_uint32 ex3)
{
#if defined(DEBUG_KAL)
    kal_assert_fail(expr, file, line, KAL_TRUE, ex1, ex2, ex3, NULL);
#endif /*DEBUG_KAL*/
} 

/* Start -- 2011.10.12 Jau add to make Modis build pass { */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* Stop  -- 2011.10.12 Jau add to make Modis build pass } */

/*eap related dummy functions*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifndef __WPS_SUPPORT__

int wpas_wps_init(struct wpa_supplicant *wpa_s)
{
    return 0;
}

int wpas_wps_scan_pbc_overlap(struct wpa_supplicant *wpa_s,
			      struct wndrv_supc_bss_info_struct* selected,
			      struct wpa_ssid *ssid)
{
    return 0;
}


int wpas_wps_start_pbc(struct wpa_supplicant *wpa_s, const u8 *bssid)
{
    return 0;
}

int wpas_wps_start_pin(struct wpa_supplicant *wpa_s, const u8 *bssid,
		       const char *pin)
{
    return 0;
}


void supc_wps_reg_selected_timer_expiry_handler(void* para_hf)
{
}

void supc_wps_registrar_pbc_timer_expiry_handler(void* para_hf)
{
}
#endif

#ifndef __WPS_SUPPORT__

void supc_wps_walk_timer_expiry_handler(void* para_hf)
{
}


enum wps_request_type wpas_wps_get_req_type(struct wpa_ssid *ssid)
{
    return 0;
}

int wpas_wps_ssid_bss_match(
                struct wpa_supplicant *wpa_s,
			    struct wpa_ssid *ssid,
			    struct wndrv_supc_bss_info_struct* bss)
{
    return 0;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

struct wpabuf * wps_build_assoc_req_ie(enum wps_request_type req_type)
{
    return NULL;
}


void wpas_wps_deinit(struct wpa_supplicant *wpa_s)
{
}

int wpas_wps_eapol_cb(struct wpa_supplicant *wpa_s)
{
    return 1;
}
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __CERTMAN_SUPPORT__ */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if !defined(__CUSTOM_WIFI_FEATURES_SWITCH__)

kal_eventgrpid supc_sim_block_ev_id;

kal_bool supc_create(comptask_handler_struct **handle)
{
   static comptask_handler_struct wpa_handler_info =
	{
      NULL,       /* task entry function */
      NULL,         /* task initialization function */
	    NULL,		/* task configuration function */
      NULL,           /* task reset handler */
      NULL          /* task termination handler */
	};

   *handle = &wpa_handler_info;
	return KAL_TRUE;
}
#endif
#endif

