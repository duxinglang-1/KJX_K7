/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * ModeSwitchSrv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for mode switch service 
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#include "ModeSwitchSrvGProt.h"
#include "ModeSwitchSrvProt.h"

#include "ps_public_enum.h"

#include "NetSetAppGprot.h"
#include "BtcmSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NetSetSrvProt.h"
#include "DtcntSrvGprot.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "l3_inc_enums.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "string.h"
#include "NetSetSrvGprot.h"
#include "mmi_msg_struct.h"
#include "stack_msgs.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "nvram_data_items.h"
#include "mmi_frm_nvram_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_rp_srv_modeswitch_def.h"
/* auto add by kw_check end */
/***************************************************************************** 
* Include
*****************************************************************************/
#define PHNSET_TRACE0   NETSET_TRACE0
#define PHNSET_TRACE1   NETSET_TRACE1
#define PHNSET_TRACE2   NETSET_TRACE2
#define PHNSET_TRACE3   NETSET_TRACE3

#define SRV_MODE_FLAG L4C_SETTING_WLAN_FLIGHT_MODE


/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Global Variable
*****************************************************************************/
#define SRV_MODE_TURN_OFF (0)
#define SRV_MODE_TURN_ON  (1)
#define SRV_MODE_IGNORE   (0)
#define SRV_MODE_SWITCH   (1)

static srv_mode_switch_cntx_struct g_srv_mode_switch_cntx;

static U8 g_srv_mode_switch_gsm_mode;
static U8 g_srv_mode_switch_in_flight_mode;
static U8 g_srv_mode_flag;
/*static MMI_BOOL g_srv_mode_switch_switch_network_mode;*/

static U8 g_cfun_state;

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* Common Functions for both single SIM and Dual SIM project */
static void srv_mode_switch_proc_rsp(U16 result, mmi_proc_func callback, void* user_data);
/* fill message array with switch case */

static void srv_mode_switch_update_wlan_state(U16 state);
static void srv_mode_switch_update_other_state(U16 state);
static void srv_mode_switch_update_gsm_state(U16 state);

static void srv_mode_switch_switch_gsm_mode(srv_mode_switch_type_enum sel_mode);

/* switch WLAN / BT / WLAN */
static void srv_mode_switch_switch_all_mode(void);
static void srv_mode_switch_switch_all_mode_rsp(U16 result);

/* switch GSM mode state */
#if (MMI_MAX_SIM_NUM == 1)
static void srv_mode_switch_req(srv_mode_switch_type_enum switch_item);
static void srv_mode_switch_rsp(void *info);
#endif
#if (MMI_MAX_SIM_NUM >= 2) // Gemini+
static void srv_mode_switch_req_ext(srv_mode_switch_type_enum switch_item);
#endif 
static void srv_mode_switch_rsp_ext(void *info);

/* Set switching flag */
static void srv_mode_switch_set_switching(MMI_BOOL switching);


/* Notification function */
static void srv_mode_switch_pre_switch_notification(void);
static void srv_mode_switch_switch_other_notification(void);
static void srv_mode_switch_switch_finish_notification(void);

/* Network flight mode */
/*static void srv_mode_switch_update_flight_mode_flag(void);*/
static void srv_mode_switch_set_mode_flag(srv_mode_switch_flag_enum flag);
static void srv_mode_switch_clear_mode_flag(srv_mode_switch_flag_enum flag);
static MMI_BOOL srv_mode_switch_is_mode_flag_on(srv_mode_switch_flag_enum flag);


static void srv_mode_switch_set_gsm_mode(srv_mode_switch_type_enum sel_mode);


/***************************************************************************** 
* External Function
*****************************************************************************/


typedef enum
{
	SRV_MODE_SWITCH_GSM,
	SRV_MODE_SWITCH_WLAN,
	SRV_MODE_SWITCH_OTHER_APP,
	SRV_MODE_SWITCH_ALL
} srv_mode_switch_app_type_enum;

typedef struct
{
	U8 state;
	U8 mark;
} srv_mode_switch_req_func_struct;

#define SRV_MODE_SWITCH_FUNC_NUM (3)

/* adjust the order of switch*/
/* if g_flight_mode_flag is TRUE, then switch other first, and gsm last.*/
/* else FLASE, gsm first and other last*/
static MMI_BOOL g_flight_mode_flag;
const static FuncPtrShort g_mode_switch_switch_func_array[SRV_MODE_SWITCH_FUNC_NUM] = 
{
    srv_mode_switch_update_gsm_state,
    srv_mode_switch_update_wlan_state,
    srv_mode_switch_update_other_state
};

static srv_mode_switch_req_func_struct switch_all_array[SRV_MODE_SWITCH_FUNC_NUM];

static void srv_mode_switch_init_switch_cntx(srv_mode_switch_type_enum sel_mode, srv_mode_switch_state_enum sel_flight_mode, mmi_proc_func cb_func_ptr, void *user_data)
{
    memset(&g_srv_mode_switch_cntx, 0x00, sizeof(srv_mode_switch_cntx_struct));
    memset(&switch_all_array, 0, sizeof(switch_all_array));

    g_srv_mode_switch_cntx.curr_mode = srv_mode_switch_get_current_mode();
    g_srv_mode_switch_cntx.sel_mode = sel_mode;

    g_srv_mode_switch_cntx.curr_flight_mode = srv_mode_switch_is_network_service_available() ? SRV_MODE_SWITCH_OFF : SRV_MODE_SWITCH_ON;
    g_srv_mode_switch_cntx.select_flight_mode = sel_flight_mode;
    
    g_srv_mode_switch_cntx.switch_cb_func = cb_func_ptr;
    g_srv_mode_switch_cntx.user_data = user_data;

    srv_mode_switch_set_switching(MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_rf_mode
 * DESCRIPTION
 *  Function to switch mode of GSM Network
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mode_switch_switch_rf_mode(srv_mode_switch_type_enum sel_mode, mmi_proc_func cb_func_ptr, void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_mode_switch_type_enum cur_mode = SRV_MODE_SWITCH_ALL_OFF;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchSrv.c] srv_mode_switch_switch_mode()");

	MMI_ASSERT(cb_func_ptr);
	
	/* mode switching is TRUE, return */
	if (srv_mode_switch_is_switching())
	{
		return MMI_FALSE;
	}
	
	cur_mode = srv_mode_switch_get_current_mode();
	
	PHNSET_TRACE2(0, "[ModeSwitchSrv.c] cur_mode[%d] sel_mode[%d]", cur_mode, sel_mode);

	if (cur_mode == sel_mode)
	{
		srv_mode_switch_proc_rsp(1, cb_func_ptr, user_data);
		return MMI_TRUE;
	}

    srv_mode_switch_init_switch_cntx(sel_mode, SRV_MODE_SWITCH_OFF, cb_func_ptr, user_data);
    
	switch_all_array[SRV_MODE_SWITCH_GSM].state = sel_mode;
	switch_all_array[SRV_MODE_SWITCH_GSM].mark = SRV_MODE_SWITCH;    

	srv_mode_switch_switch_all_mode();

	return MMI_TRUE;
}


#if (MMI_MAX_SIM_NUM == 1)
/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_network_mode
 * DESCRIPTION
 *  Switch network mode, when switch to flight mode will turn off BT and WLAN, 
 *  when switch back from flight mode will ture on BT and WLAN. 
 *  THIS API IS ONLY AVAILABLE FOR SINGLE SIM PROJECT.
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 *****************************************************************************/
MMI_BOOL srv_mode_switch_switch_network_mode(srv_mode_switch_type_enum mode, mmi_proc_func cb_func_ptr, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_type_enum current_mode;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchSrv.c] srv_mode_switch_switch_network_mode()");

	MMI_ASSERT(cb_func_ptr);
	
	/* mode switching is TRUE, return */
	if (srv_mode_switch_is_switching())
	{
		return MMI_FALSE;
	}
	
    /*g_srv_mode_switch_switch_network_mode = MMI_TRUE;*/

    current_mode = srv_mode_switch_get_current_mode();
    if (current_mode == mode
		/* still switch if switching to flight mode and current RF is all off */
		&& (mode == SRV_MODE_SWITCH_ALL_OFF && !srv_mode_switch_is_network_service_available())
		&& g_cfun_state == 0)
    {
	srv_mode_switch_proc_rsp(1, cb_func_ptr, user_data);
        return MMI_TRUE;
    }
    else
    {
        srv_mode_switch_init_switch_cntx(
            mode,
            ((mode == SRV_MODE_SWITCH_FLIGHT_MODE) ? SRV_MODE_SWITCH_ON : SRV_MODE_SWITCH_OFF),
            cb_func_ptr, 
            user_data);

		switch_all_array[SRV_MODE_SWITCH_GSM].mark = SRV_MODE_SWITCH;
        switch_all_array[SRV_MODE_SWITCH_GSM].state = mode;
        switch (mode)
    	{
    	case SRV_MODE_SWITCH_FLIGHT_MODE:
            #ifdef __MMI_WLAN_FEATURES__
            if (srv_netset_get_pref_mode() != P_GSM_ONLY)
            {
                switch_all_array[SRV_MODE_SWITCH_WLAN].state = SRV_MODE_TURN_OFF;
        		switch_all_array[SRV_MODE_SWITCH_WLAN].mark = SRV_MODE_SWITCH;
            }        
            #endif /* __MMI_WLAN_FEATURES__ */
            switch_all_array[SRV_MODE_SWITCH_OTHER_APP].mark = SRV_MODE_SWITCH;
    		break;
    	default:
            if (current_mode == SRV_MODE_SWITCH_FLIGHT_MODE)
        	{
                #ifdef __MMI_WLAN_FEATURES__
                if (srv_netset_get_pref_mode() != P_WLAN_ONLY)
                {
                switch_all_array[SRV_MODE_SWITCH_WLAN].state = SRV_MODE_TURN_ON;
        		switch_all_array[SRV_MODE_SWITCH_WLAN].mark = SRV_MODE_SWITCH;
                }
                #endif /* __MMI_WLAN_FEATURES__ */
                switch_all_array[SRV_MODE_SWITCH_OTHER_APP].mark = SRV_MODE_SWITCH;
        	}
    		break;
    	}
    }
    PHNSET_TRACE1(0, "[ModeSwitchSrv.c] switch to mode(%d)", mode);
	PHNSET_TRACE3(0, "[ModeSwitchSrv.c] switch_info mark WLAN[%d] BT[%d] GSM[%d]", switch_all_array[0].mark, switch_all_array[1].mark, switch_all_array[2].mark);

	srv_mode_switch_switch_all_mode();

	return MMI_TRUE;    
}
#endif /* (MMI_MAX_SIM_NUM == 1) */


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_network_mode_ext
 * DESCRIPTION
 *  Function to switch GSM / BT / WLAN
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mode_switch_switch_network_mode_ext(srv_mode_switch_req_struct switch_info, mmi_proc_func cb_func_ptr, void* user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchSrv.c] srv_mode_switch_switch_network_mode_ext()");

	MMI_ASSERT(cb_func_ptr);
	
	/* mode switching is TRUE, return */
	if (srv_mode_switch_is_switching())
	{
		return MMI_FALSE;
	}
	

    /*g_srv_mode_switch_switch_network_mode = MMI_TRUE;*/

    srv_mode_switch_init_switch_cntx(
        (srv_mode_switch_type_enum)(switch_info.rf != 0xFF ? switch_info.rf : srv_mode_switch_get_current_mode()),
        ((switch_info.wlan == 0 && switch_info.bt == 0 && switch_info.rf == 0) ? SRV_MODE_SWITCH_ON : SRV_MODE_SWITCH_OFF),
        cb_func_ptr, 
        user_data);

	if (switch_info.wlan != 0xFF)
	{
		switch_all_array[SRV_MODE_SWITCH_WLAN].state = switch_info.wlan;
		switch_all_array[SRV_MODE_SWITCH_WLAN].mark = SRV_MODE_SWITCH;
	}

	if (switch_info.bt != 0xFF)
	{
		switch_all_array[SRV_MODE_SWITCH_OTHER_APP].state = switch_info.bt;
		switch_all_array[SRV_MODE_SWITCH_OTHER_APP].mark = SRV_MODE_SWITCH;
	}

	if (switch_info.rf != 0xFF)
	{
		switch_all_array[SRV_MODE_SWITCH_GSM].state = switch_info.rf;
		switch_all_array[SRV_MODE_SWITCH_GSM].mark = SRV_MODE_SWITCH;
	}

	PHNSET_TRACE3(0, "[ModeSwitchSrv.c] switch_info mark WLAN[%d] BT[%d] GSM[%d]", switch_all_array[0].mark, switch_all_array[1].mark, switch_all_array[2].mark);
	PHNSET_TRACE3(0, "[ModeSwitchSrv.c] switch_info state WLAN[%d] BT[%d] GSM[%d]", switch_info.wlan, switch_info.bt, switch_info.rf);

	srv_mode_switch_switch_all_mode();

	return MMI_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_flight_mode
 * DESCRIPTION
 *  Switch to flight mode or back to normal mode 
 *  If check_sim is MMI_TRUE, the phone will only turn on RF of inserted SIM
 * PARAMETERS
 *  flight_mode_on      [IN]    is switch to flight mode
 *  check_sim           [IN]    is switch the RF according to SIM insert status
 *  callback            [IN]
 *  user_data
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mode_switch_switch_flight_mode(MMI_BOOL flight_mode_on, MMI_BOOL check_sim, mmi_proc_func callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    srv_mode_switch_type_enum sel_mode;
#endif
#if (MMI_MAX_SIM_NUM > 1)    
    srv_mode_switch_req_struct switch_info; 
    U8 data[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    S16 error;
#endif
    g_flight_mode_flag = flight_mode_on;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    // Single SIM project just switch RF
   sel_mode = flight_mode_on ? SRV_MODE_SWITCH_ALL_OFF : SRV_MODE_SWITCH_SIM1;
   return srv_mode_switch_switch_network_mode(sel_mode, callback, user_data);
#else
    if (flight_mode_on)        
	{
        switch_info.wlan = 0;
        switch_info.bt = 0;
        switch_info.rf = SRV_MODE_SWITCH_ALL_OFF;
        return srv_mode_switch_switch_network_mode_ext(switch_info, callback, user_data);	
	}

    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);    

    switch_info.wlan = 1;
    switch_info.bt = 1;
    switch_info.rf = 0;
    
    if (check_sim)
    {
        U8 index;
        MMI_BOOL sim_currently_inserted = MMI_FALSE;
        MMI_BOOL sim_previously_selected = MMI_FALSE;
        U32 inserted_sim_num = 0;
        for (index = 0; index < MMI_MAX_SIM_NUM; index++)
        {
            sim_currently_inserted = srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(index))? MMI_TRUE : MMI_FALSE; // Gemini+
            sim_previously_selected = (MMI_BOOL)(data[L4C_SETTING_DUAL_SIM_MODE] & (1<<index));
            switch_info.rf |= ((sim_currently_inserted && sim_previously_selected) ? 1 : 0)<<index;
            inserted_sim_num += (U32)sim_currently_inserted;
        }
        
        if (inserted_sim_num == 0)
        {
            switch_info.rf |= SRV_MODE_SWITCH_SIM1;
        }
        else if (switch_info.rf == SRV_MODE_SWITCH_ALL_OFF)
        {
            #ifdef __COSMOS_MMI_PACKAGE__
            /* Turn on the only inserted SIM because no individual RF switch will be displayed */
            if (inserted_sim_num == 1)
        	{
                for (index = 0; index < MMI_MAX_SIM_NUM; index++)
                {
                    sim_currently_inserted = srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(index))? MMI_TRUE : MMI_FALSE;
                    if (sim_currently_inserted)
                    {
                        switch_info.rf |= 1<<index;
                    }
                }
        	}
            #else
            #if (MMI_MAX_SIM_NUM == 2)
            /* Turn on the inserted SIM on Dual SIM project */
			if(data[L4C_SETTING_DUAL_SIM_MODE] != SRV_MODE_SWITCH_ALL_OFF)
			{
                for (index = 0; index < MMI_MAX_SIM_NUM; index++)
                {
                    sim_currently_inserted = srv_sim_ctrl_is_inserted(mmi_frm_index_to_sim(index))? MMI_TRUE : MMI_FALSE;
                    if (sim_currently_inserted)
                    {
                        switch_info.rf |= 1<<index;
                    }
                }
			}
            #endif
            #endif
        }
    }
    else
    {
        switch_info.rf |= data[L4C_SETTING_DUAL_SIM_MODE];
    }

    return srv_mode_switch_switch_network_mode_ext(switch_info, callback, user_data);
#endif /* (MMI_MAX_SIM_NUM > 1) */
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_proc_rsp
 * DESCRIPTION
 *  Response with input callback function and user data 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_mode_switch_proc_rsp(U16 result, mmi_proc_func callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_rsp_event_struct rsp_event;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_event.evt_id = EVT_ID_SRV_MODE_SWITCH_FINISH;
    rsp_event.result = result;
    rsp_event.user_data = user_data;
    
    (*callback)((mmi_event_struct*)&rsp_event);
} 
 

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_gsm_mode
 * DESCRIPTION
 *  Function to switch GSM status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_switch_gsm_mode(srv_mode_switch_type_enum sel_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE1(0, "[ModeSwitchSrv.c] srv_mode_switch_switch_gsm_mode(%d)", sel_mode);
    srv_mode_switch_pre_switch_notification();
	if (srv_mode_switch_get_current_mode()!= sel_mode
	#if (MMI_MAX_SIM_NUM == 1)
		|| g_cfun_state != 0
	#endif
		)
	{
    #if (MMI_MAX_SIM_NUM == 1)
    /* Send CFUN request */
		srv_mode_switch_req(g_srv_mode_switch_cntx.sel_mode);
    #else
    /* send EFUN request */
        srv_mode_switch_req_ext(g_srv_mode_switch_cntx.sel_mode);
    #endif
	}
	else
	{
		srv_mode_switch_rsp_ext(NULL); // still need to update NVRAM
	}
}


#if (MMI_MAX_SIM_NUM >= 2) // Gemini+
/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_req_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_req_ext(srv_mode_switch_type_enum switch_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_efun_state_req_struct *efun_state_req;
	mmi_nw_cfun_state_req_struct *cfun_state_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MTK_TARGET__
	srv_mode_switch_rsp_ext(NULL);
	return;
#endif
	if(g_cfun_state)
	{
		SetProtocolEventHandler(srv_mode_switch_rsp_ext, MSG_ID_MMI_NW_CFUN_STATE_RSP);
		cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));
		cfun_state_req->cfun_state = g_cfun_state - 1;
		mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_NW_CFUN_STATE_REQ, (oslParaType*)cfun_state_req, NULL);
		
	}
	else
	{
	    SetProtocolEventHandler(srv_mode_switch_rsp_ext, MSG_ID_MMI_NW_EFUN_STATE_RSP);
        efun_state_req = OslConstructDataPtr(sizeof(mmi_nw_efun_state_req_struct));
        efun_state_req->efun_state = switch_item;
        mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_NW_EFUN_STATE_REQ, (oslParaType*)efun_state_req, NULL);
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_rsp_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_rsp_ext(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_efun_state_rsp_struct *efun_state_rsp = (mmi_nw_efun_state_rsp_struct*) info;
	mmi_nw_cfun_state_rsp_struct *cfun_state_rsp = (mmi_nw_cfun_state_rsp_struct*) info;
    MMI_BOOL rtn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_cfun_state)
	{
		ClearProtocolEventHandler(MSG_ID_MMI_NW_CFUN_STATE_RSP);
	}
	else
	{
        ClearProtocolEventHandler(MSG_ID_MMI_NW_EFUN_STATE_RSP);
	}
#ifdef __MTK_TARGET__
	if(g_cfun_state)
	{
		rtn = (MMI_BOOL) cfun_state_rsp->result;
	}
    else
    {
        rtn = (MMI_BOOL) efun_state_rsp->result;
    }
#else
   rtn = MMI_TRUE;
#endif
	g_cfun_state = 0;

    if (rtn)
    {
        srv_mode_switch_set_gsm_mode(g_srv_mode_switch_cntx.sel_mode);
    }
    else
    {
        g_srv_mode_switch_cntx.sel_mode = g_srv_mode_switch_cntx.curr_mode;
        g_srv_mode_switch_cntx.select_flight_mode = g_srv_mode_switch_cntx.curr_flight_mode;
    }

    srv_mode_switch_update_cb_func();
}

#if (MMI_MAX_SIM_NUM == 1)
/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_req
 * DESCRIPTION
 *  Function to fill message and send request to L4C and L4C_2 to switch mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_req(srv_mode_switch_type_enum switch_item)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_nw_cfun_state_req_struct *cfun_state_req = NULL;
    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE1(0, "[ModeSwitchSrv.c] srv_mode_switch_req(%d)", switch_item);
#ifndef __MTK_TARGET__
	srv_mode_switch_rsp_ext(NULL);
	return;
#endif

    cfun_state_req = OslConstructDataPtr(sizeof(mmi_nw_cfun_state_req_struct));
    switch(switch_item)
    {
	case SRV_MODE_SWITCH_FLIGHT_MODE:
        cfun_state_req->cfun_state = 4;
        break;
        
    case SRV_MODE_SWITCH_SIM1:
        cfun_state_req->cfun_state = 1;
        break;

    default:
        ASSERT(0); // Only used for single SIM project
        break;
    }
	if(g_cfun_state)
	{		
        cfun_state_req->cfun_state = g_cfun_state - 1;
	}
    SetProtocolEventHandler(srv_mode_switch_rsp, MSG_ID_MMI_NW_CFUN_STATE_RSP);
    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_NW_CFUN_STATE_REQ, (oslParaType*)cfun_state_req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_rsp
 * DESCRIPTION
 *  Function to fill message array with different switch type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_rsp(void *info)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_nw_cfun_state_rsp_struct *cfun_state_rsp;
	MMI_BOOL result;
    
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cfun_state_rsp = (mmi_nw_cfun_state_rsp_struct*)info;
    #ifdef __MTK_TARGET__
    result = cfun_state_rsp->result;
    #else
    result = MMI_TRUE;
    #endif
	PHNSET_TRACE1(0, "[ModeSwitchSrv.c] srv_mode_switch_rsp(%d)", result);

    ClearProtocolEventHandler(MSG_ID_MMI_NW_CFUN_STATE_RSP);

	g_cfun_state = 0;

	if (result && (g_srv_mode_switch_cntx.curr_mode != g_srv_mode_switch_cntx.sel_mode))
	{
	    srv_mode_switch_set_gsm_mode(g_srv_mode_switch_cntx.sel_mode);
	    srv_mode_switch_update_cb_func();
	}
    else
    {
        /*g_srv_mode_switch_switch_network_mode = MMI_FALSE;*/
        srv_mode_switch_proc_rsp(result, g_srv_mode_switch_cntx.switch_cb_func, g_srv_mode_switch_cntx.user_data);

        srv_mode_switch_set_switching(MMI_FALSE);
        memset(&g_srv_mode_switch_cntx, 0x00, sizeof(srv_mode_switch_cntx_struct));
    }
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_is_switching
 * DESCRIPTION
 *  Function to get current mode switch status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_set_switching(MMI_BOOL switching)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHNSET_TRACE1(0, "[ModeSwitchSrv.c] srv_mode_switch_set_switching(%d)", switching);
	g_srv_mode_switch_cntx.srv_mode_switching = switching;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_is_switching
 * DESCRIPTION
 *  Function to get current mode switch status
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mode_switch_is_switching(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return g_srv_mode_switch_cntx.srv_mode_switching;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_set_current_mode
 * DESCRIPTION
 *  Function to set mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_mode_switch_set_current_mode(srv_mode_switch_type_enum sel_mode)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM == 1)
    U8 sel_flight_mode;
    /* Turn on BT when select from query mode */
    PHNSET_TRACE1(0, "[ModeSwitchSrv.c] srv_mode_switch_set_current_mode(%d)", sel_mode);
    sel_flight_mode = (sel_mode == SRV_MODE_SWITCH_FLIGHT_MODE) ? SRV_MODE_SWITCH_IN_FLIGHT_MODE : SRV_MODE_SWITCH_IN_NORMAL_MODE;
#endif 
    if (
        #if (MMI_MAX_SIM_NUM == 1)
        sel_flight_mode == g_srv_mode_switch_in_flight_mode &&
        #endif
        srv_mode_switch_get_current_mode() == sel_mode)
	{
	    return;
	}
#if (MMI_MAX_SIM_NUM == 1)
	g_srv_mode_switch_in_flight_mode = sel_flight_mode;
#endif

    srv_mode_switch_set_gsm_mode(sel_mode);
}

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_set_gsm_mode
 * DESCRIPTION
 *  Set the GSM mode 
 *  Switch to flight mode -> set mode to all off and update L4C_SETTING_FLIGHT_MODE only
 *  Switch to normal mode -> set mode to previous and update L4C_SETTING_FLIGHT_MODE only
 *  Swtich to GSM mode -> update to L4C_SETTING_DUAL_SIM_MODE only
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_mode_switch_set_gsm_mode(srv_mode_switch_type_enum sel_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 data[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE1(0, "[ModeSwitchSrv.c] srv_mode_switch_set_gsm_mode(%d)", sel_mode);
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);

	switch(sel_mode)
	{
	case SRV_MODE_SWITCH_ALL_OFF:
        if (g_srv_mode_switch_cntx.select_flight_mode == SRV_MODE_SWITCH_ON)
        {
            data[L4C_SETTING_FLIGHT_MODE] = MMI_TRUE;
        }
        else
        {
            data[L4C_SETTING_FLIGHT_MODE] = MMI_FALSE;
#if (MMI_MAX_SIM_NUM >= 2)
            data[L4C_SETTING_DUAL_SIM_MODE] = sel_mode;
#endif
        }   
        break;

    default:
        data[L4C_SETTING_FLIGHT_MODE] = MMI_FALSE;
#if (MMI_MAX_SIM_NUM >= 2)
        data[L4C_SETTING_DUAL_SIM_MODE] = sel_mode;
#endif
        break;
	}

    g_srv_mode_switch_gsm_mode = sel_mode;
	WriteRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_get_current_mode
 * DESCRIPTION
 *  Function to get current mode
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_mode_switch_type_enum srv_mode_switch_get_current_mode(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mode_switch_init();
    
    PHNSET_TRACE1(0, "[ModeSwitchSrv.c] srv_mode_switch_get_current_mode() return %d", g_srv_mode_switch_gsm_mode);	
	return (srv_mode_switch_type_enum)g_srv_mode_switch_gsm_mode;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_check_mode
 * DESCRIPTION
 *  Check the mode of input SIM  
 * PARAMETERS
 *  
 * RETURNS
 *  srv_mode_check_mode_enum
 *****************************************************************************/
srv_mode_switch_state_enum srv_mode_switch_get_network_mode(mmi_sim_enum sim)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_type_enum current_mode;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_mode = srv_mode_switch_get_current_mode();

    return (current_mode & sim) ? SRV_MODE_SWITCH_ON : SRV_MODE_SWITCH_OFF;
}


#if (MMI_MAX_SIM_NUM >= 2)
/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_get_prev_dual_sim_status
 * DESCRIPTION
 *  Get dual sim status (not including flight mode) 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
srv_mode_switch_state_enum srv_mode_switch_get_pre_network_mode(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    S16 error = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHNSET_TRACE0(0, "[ModeSwitchSrv.c] srv_mode_switch_get_prev_dual_sim_status()");
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);

	switch(data[L4C_SETTING_DUAL_SIM_MODE])
	{
	case SIM1_ONLY_CONFIG:
        if (sim == MMI_SIM1)
    	{
    	    return SRV_MODE_SWITCH_ON;
    	}
		break;

	case SIM2_ONLY_CONFIG:
        if (sim == MMI_SIM2)
    	{
    	    return SRV_MODE_SWITCH_ON;
    	}
		break;

	case DAUL_SIM_CONFIG:
   	    return SRV_MODE_SWITCH_ON;
      
	default:
	    break;
	}
    return SRV_MODE_SWITCH_OFF;    
}
#endif 


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_update_cb_func
 * DESCRIPTION
 *  Callback function of mode switch item
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mode_switch_update_cb_func(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchSrv.c] srv_mode_switch_update_cb_func()");
	srv_mode_switch_switch_all_mode();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_update_wlan_state
 * DESCRIPTION
 *  Function to switch WLAN
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_update_wlan_state(U16 state)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_WLAN_FEATURES__
	PHNSET_TRACE1(0, "[ModeSwitchSrv.c] srv_mode_switch_update_wlan_state : %d", state);
	
#ifdef __MTK_TARGET__
	// TODO
	if (state)
	{
		srv_dtcnt_wlan_hw_reset_on((srv_dtcnt_wlan_cb_func_ptr)srv_mode_switch_update_cb_func, NULL);
	}
	else
	{
		srv_dtcnt_wlan_hw_reset_off((srv_dtcnt_wlan_cb_func_ptr)srv_mode_switch_update_cb_func, NULL);
	}
#else /* __MTK_TARGET__ */
	srv_mode_switch_update_cb_func();
#endif /* __MTK_TARGET__ */
#else /* __MMI_WLAN_FEATURES__ */
    srv_mode_switch_update_cb_func();
#endif /* __MMI_WLAN_FEATURES__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_update_other_state
 * DESCRIPTION
 *  Function to switch BT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_update_other_state(U16 state)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_SUPPORT__
    srv_mode_switch_switch_other_notification();
#else /* __MMI_BT_SUPPORT__ */
    srv_mode_switch_update_cb_func();
#endif /* __MMI_BT_SUPPORT__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_update_gsm_state
 * DESCRIPTION
 *  Function to switch GSM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_update_gsm_state(U16 state)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_mode_switch_switch_gsm_mode((srv_mode_switch_type_enum)state);
}
 

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_all_mode_rsp
 * DESCRIPTION
 *  Response function to switch GSM / BT / WLAN Internal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_switch_all_mode_rsp(U16 result)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    if (g_srv_mode_switch_switch_network_mode) // this variable is meaningless?
	{
        if (g_srv_mode_switch_cntx.sel_mode == SRV_MODE_SWITCH_ALL_OFF && g_srv_mode_switch_cntx.select_flight_mode == SRV_MODE_SWITCH_ON) // Gemini+: need modify for new all sim off mode
    	{
    	    g_srv_mode_switch_in_flight_mode = SRV_MODE_SWITCH_IN_FLIGHT_MODE;
    	}
    	else
    	{
            g_srv_mode_switch_in_flight_mode = SRV_MODE_SWITCH_IN_NORMAL_MODE;
    	}
	}
   
    srv_mode_switch_proc_rsp(result, g_srv_mode_switch_cntx.switch_cb_func, g_srv_mode_switch_cntx.user_data);
    

    /*g_srv_mode_switch_switch_network_mode = MMI_FALSE;*/
    srv_mode_switch_switch_finish_notification();

	srv_mode_switch_set_switching(MMI_FALSE);

	memset(&g_srv_mode_switch_cntx, 0x00, sizeof(srv_mode_switch_cntx_struct));
    g_flight_mode_flag = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_all_mode
 * DESCRIPTION
 *  Function to switch GSM / BT / WLAN Internal
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_switch_all_mode(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 i = 0;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PHNSET_TRACE0(0, "[ModeSwitchSrv.c] srv_mode_switch_switch_all_mode()");
    
	for (i = 0; i < SRV_MODE_SWITCH_FUNC_NUM; i++)
	{   
    	if (g_flight_mode_flag == MMI_FALSE)
        {		
            if (switch_all_array[i].mark)
            {
    			switch_all_array[i].mark = SRV_MODE_IGNORE;

                PHNSET_TRACE2(0, "[ModeSwitchSrv.c] array[%d] state[%d]", i, switch_all_array[i].state);
                (*g_mode_switch_switch_func_array[i])(switch_all_array[i].state);
    			
    			return;
            }
        }
        else
        {
           if (switch_all_array[i].mark)
            {
    			switch_all_array[i].mark = SRV_MODE_IGNORE;

                PHNSET_TRACE2(0, "[ModeSwitchSrv.c] array[%d] state[%d]", i, switch_all_array[SRV_MODE_SWITCH_FUNC_NUM-i-1].state);
                (*g_mode_switch_switch_func_array[SRV_MODE_SWITCH_FUNC_NUM-i-1])(switch_all_array[SRV_MODE_SWITCH_FUNC_NUM-i-1].state);
    			
    			return;
            }
        }
	}

	for (i = 0; i < SRV_MODE_SWITCH_FUNC_NUM; i++)
	{
		switch_all_array[i].mark = 0;
		switch_all_array[i].state = 0;
	}

    if (!g_srv_mode_switch_cntx.switch_cb_func)
	{
        /* work around solution for incorrect callback from BT */
        /* Should be removed after W11.29 */
	    return;
	}

	srv_mode_switch_switch_all_mode_rsp(1);
}

/* END ALL MODE SWITCH LOGICAL */


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_send_notification_int
 * DESCRIPTION
 *  Send mode switch service event 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_mode_switch_send_notification_int(U16 evt_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, evt_id);
    evt.gsm_curr_mode = g_srv_mode_switch_cntx.curr_mode;
    evt.gsm_select_mode = g_srv_mode_switch_cntx.sel_mode;
    evt.curr_flight_mode = g_srv_mode_switch_cntx.curr_flight_mode;
    evt.select_flight_mode = g_srv_mode_switch_cntx.select_flight_mode;
    PHNSET_TRACE2(0, "[ModeSwitchSrv.c] gsm_curr_mode[%d] gsm_select_mode[%d]", evt.gsm_curr_mode, evt.gsm_select_mode);
    MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);

}
 

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_pre_switch_notification
 * DESCRIPTION
 *  Send notification of EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_mode_switch_pre_switch_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_mode_switch_send_notification_int(EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY);
}

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_other_notification
 * DESCRIPTION
 *  Send notification of EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY 
 * PARAMETERS
 *  void
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_mode_switch_switch_other_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mode_switch_send_notification_int(EVT_ID_SRV_MODE_SWITCH_SWITCH_OTHER_NOTIFY);
    PHNSET_TRACE0(0, "[ModeSwitchSrv.c] switch other");
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_switch_finish_notification
 * DESCRIPTION
 *  Send notification of EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY 
 * PARAMETERS
 *  void
 * RETURNS
 *  static void
 *****************************************************************************/
static void srv_mode_switch_switch_finish_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	srv_mode_switch_send_notification_int(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY);
    PHNSET_TRACE0(0, "[ModeSwitchSrv.c] finish");
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_before_idle_event_hdlr
 * DESCRIPTION
 *  Send notification of EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY (after power on mode decision)
 * PARAMETERS
 *  *evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_mode_switch_before_idle_event_hdlr(mmi_event_struct *evt_idle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY);
    evt.gsm_curr_mode = SRV_MODE_SWITCH_ALL_OFF;
    evt.gsm_select_mode = srv_mode_switch_get_current_mode();
    evt.curr_flight_mode = SRV_MODE_SWITCH_OFF;
    evt.select_flight_mode = srv_mode_switch_is_network_service_available() ? SRV_MODE_SWITCH_OFF : SRV_MODE_SWITCH_ON;
    PHNSET_TRACE2(0, "[ModeSwitchSrv.c] gsm_curr_mode[%d] gsm_select_mode[%d]", evt.gsm_curr_mode, evt.gsm_select_mode);
	MMI_FRM_CB_EMIT_POST_EVENT((mmi_event_struct *)&evt);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_is_network_service_available
 * DESCRIPTION
 *  Check if the network is in flight mode(GSM off, WLAN off) 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mode_switch_is_network_service_available(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mode_switch_init();
    
    if (g_srv_mode_switch_in_flight_mode == SRV_MODE_SWITCH_IN_FLIGHT_MODE)
	{
	    return MMI_FALSE;
	}
    return MMI_TRUE;
}

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
#ifdef __MMI_WLAN_FEATURES__
/* under construction !*/
#endif /* __MMI_WLAN_FEATURES__ */        
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

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_set_mode_flag
 * DESCRIPTION
 *  Set flag for mode switch, please refer to srv_mode_switch_flag_enum. 
 * PARAMETERS
 *  flag    :   [IN]     flag to be set
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_set_mode_flag(srv_mode_switch_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    S16 error = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE1(0, "[ModeSwitchSrv.c] srv_mode_switch_set_mode_flag(%d)", flag);
    if (g_srv_mode_flag & flag)
	{
        /* The flag has already been set */
	    return;
	}
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
    data[SRV_MODE_FLAG] |= (U8)flag;
    g_srv_mode_flag |= (U8)flag;
    WriteRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);   
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_reset_mode_flag
 * DESCRIPTION
 *  Clear the flag for mode switch 
 * PARAMETERS
 *  flag    :   [IN]    flag to be cleared
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mode_switch_clear_mode_flag(srv_mode_switch_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    S16 error = 0;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE1(0, "[ModeSwitchSrv.c] srv_mode_switch_set_mode_flag(%d)", flag);
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
    data[SRV_MODE_FLAG] &= (U8)~flag;
    g_srv_mode_flag &= (U8)~flag;
    WriteRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);       
}
 

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_is_mode_flag_on
 * DESCRIPTION
 *  Check the mode flag and return the result 
 * PARAMETERS
 *  flag    :   [IN] flag to be check
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_mode_switch_is_mode_flag_on(srv_mode_switch_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mode_switch_init();
    
    if (g_srv_mode_flag & flag)
	{
	    return MMI_TRUE;
	}
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_enable_query_mode
 * DESCRIPTION
 *  Enable or disable query mode 
 * PARAMETERS
 *  is_enalbe   :   [IN]    Enable/disable query mode
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mode_switch_enable_query_mode(MMI_BOOL is_enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_enable)
	{
    	srv_mode_switch_set_mode_flag(SRV_MODE_SWITCH_QUERY_MODE);
	}
    else
    {
        srv_mode_switch_clear_mode_flag(SRV_MODE_SWITCH_QUERY_MODE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_is_query_mode_enabled
 * DESCRIPTION
 *  Check if the query mode is enabled 
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_mode_switch_is_query_mode_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_mode_switch_is_mode_flag_on(SRV_MODE_SWITCH_QUERY_MODE);
}

 
/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_init
 * DESCRIPTION
 *  Init function for mode switch 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mode_switch_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data[NVRAM_EF_SYS_CACHE_OCTET_SIZE];    
    static MMI_BOOL is_init = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_init)
	{
	    return;
	}
    is_init =  MMI_TRUE;
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, &data, NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
  
    /* Init current mode */
    if (data[L4C_SETTING_FLIGHT_MODE] == MMI_TRUE)
	{
	    g_srv_mode_switch_gsm_mode = SRV_MODE_SWITCH_ALL_OFF;
        g_srv_mode_switch_in_flight_mode = SRV_MODE_SWITCH_IN_FLIGHT_MODE; // Gemini+:
	}
#if (MMI_MAX_SIM_NUM == 1)
/* One sim card surport prefer wlan only */
    else if(srv_netset_get_pref_mode() != SRV_NETSET_PREF_MODE_WLAN_ONLY)
    {
        g_srv_mode_switch_gsm_mode = SRV_MODE_SWITCH_SIM1;
    }
    else
    {
        g_srv_mode_switch_gsm_mode = SRV_MODE_SWITCH_ALL_OFF;
    }
#else    
    else
    {
        g_srv_mode_switch_gsm_mode = data[L4C_SETTING_DUAL_SIM_MODE]; /* refer to sim_radio_status_enum and/or srv_mode_switch_type_enum */
        g_srv_mode_switch_in_flight_mode = SRV_MODE_SWITCH_IN_NORMAL_MODE; // Gemini+:
        }
#endif /* (MMI_MAX_SIM_NUM == 1) */

    /* Init flag */
    g_srv_mode_flag = data[SRV_MODE_FLAG];
    
    PHNSET_TRACE1(0, "srv_mode_switch_init current_mode(%d)", g_srv_mode_switch_gsm_mode);
    PHNSET_TRACE1(0, "srv_mode_switch_init flag(%d)", g_srv_mode_flag); 
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_get_switch_type
 * DESCRIPTION
 *  get mode switch type 
 * PARAMETERS
 *  void     
 * RETURNS
 *  
 *****************************************************************************/
srv_mode_switch_bootup_sel_type_enum srv_mode_switch_get_switch_type(void)
{
#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__    
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 mode_switch_type = 0;
	S16 Err = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE0(0, "[ModeSwitchApp.c] srv_mode_switch_get_switch_type()");

    ReadValue(NVRAM_DUALMODE_MODE_SWITCH_TYPE, &mode_switch_type, DS_BYTE, &Err);
    if (mode_switch_type >= SRV_MODE_SWITCH_TOTAL_MODE || Err != NVRAM_READ_SUCCESS)
    {
        mode_switch_type = SRV_MODE_SWITCH_STATIC_MODE;
        WriteValue(NVRAM_DUALMODE_MODE_SWITCH_TYPE, &mode_switch_type, DS_BYTE, &Err);
    }

    PHNSET_TRACE1(0, "[ModeSwitchApp.c] srv_mode_switch_get_switch_type return [%d]", mode_switch_type);
    return (srv_mode_switch_bootup_sel_type_enum)mode_switch_type;
#else
    return SRV_MODE_SWITCH_STATIC_MODE;
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */
}

#ifdef __MMI_BOOTUP_MODE_SEL_SUPPORT__    
/*****************************************************************************
 * FUNCTION
 *  mmi_mode_switch_set_switch_type
 * DESCRIPTION
 *  set mode switch type 
 * PARAMETERS
 *  U8 type : 0 - dynamic mode  1 - static mode      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mode_switch_set_switch_type(U8 type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 Err = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	PHNSET_TRACE1(0, "[ModeSwitchApp.c] srv_mode_switch_set_switch_type(%d)", type);

	if (type < SRV_MODE_SWITCH_TOTAL_MODE)
	{
		WriteValue(NVRAM_DUALMODE_MODE_SWITCH_TYPE, &type, DS_BYTE, &Err);
	}
	else
	{
		MMI_ASSERT(0);
	}
}
#endif /* __MMI_BOOTUP_MODE_SEL_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_mode_switch_set_at_cfun_flag
 * DESCRIPTION
 *  set mode switch cfucn state flag 
 * PARAMETERS
 *  U8 type : 0 / 4 flight mode. 1: normal mode     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mode_switch_set_at_cfun_flag(U8 cfun_state)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_cfun_state = cfun_state;

}

