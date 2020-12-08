/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  GeneralSettingSrv.c
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 * removed!
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
#include "mmi_include.h"
/*#include "l4c_common_enum.h"*/
#include "ps_public_enum.h"
#include "Nvram_data_items.h"
#include "nvram_interface.h"
#include "nvram_common_defs.h"
#include "GlobalResDef.h"
#include "GeneralSettingSrvGprot.h"
#include "mmi_rp_srv_general_setting_def.h"
#include "FontDcl.h"
#include "SSCStringTable.h"
#include "Rmmi_struct.h"
#include "stack_config.h"
#include "mmi_frm_queue_gprot.h"

#ifdef __MMI_AUTO_LANG_EN__
#include "SSCStringTable.h"

#include "CustResDef.h"
#endif
#include "ProtocolEvents.h"
#include "Device.h"
#include "Wgui_categories_util.h" // for wgui_status_icon_bar_change_timer_format_callback()
#include "DateTimeGprot.h"
#include "lang_interface.h"
#ifdef __MMI_AUTO_LANG_EN__
#include "mmi_msg_struct.h"
#endif

#ifdef __KJX_MULTI_LANGUAGE__
#include "Kjx_main.h"
#include "Kjx_prin.h" 
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define SRV_AUTO_LANGUAGE_IDX 0xFF 

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Variables
 *****************************************************************************/
static MMI_BOOL g_general_setting_is_init;
static rmmi_sim_uart_setting_enum g_uart_setting;

/***************************************************************************** 
 * Function
 *****************************************************************************/
static void srv_setting_at_set_rtc(void *msg, int mod_id);
static void srv_setting_at_set_date_time_format(void *msg, int mod_id);
#ifndef __SLIM_AT__
static void srv_setting_set_date_format_from_at(U8 date_sep_fmt);
#endif
static void srv_setting_at_query_date_time_format(void *msg, int mod_id);
#ifndef __SLIM_AT__
static U8 srv_setting_get_date_format_for_at(void);
#endif
static void srv_setting_at_set_language(void *msg, int mod_id);
#ifndef __SLIM_AT__
static void srv_setting_at_set_language_send(U8 code, int mod_id);
#endif
static void srv_setting_at_query_language(void *msg, int mod_id);
#ifdef __MMI_AUTO_LANG_EN__
static MMI_BOOL srv_setting_language_sim_startup_info_hdlr(void *msg, S32 src_mod);
static MMI_BOOL srv_setting_prepare_auto_language(U8 *language_ind_array);
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_setting_init_general_setting
 * DESCRIPTION
 *  Init general setting 
 * PARAMETERS
 *  
 * RETURNS
 *  static void
 *****************************************************************************/
void srv_setting_init_general_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S16 error;
    #ifdef __GEMINI__
	U8 buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    #endif


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_general_setting_is_init)
	{
	    return;
	}
    /* UART setting */
    #ifdef __GEMINI__
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, (void*)buffer, 
        NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);

    g_uart_setting = (rmmi_sim_uart_setting_enum)buffer[L4C_SETTING_DUAL_SIM_UART];
    #else
    g_uart_setting = RMMI_UART_TO_SIM1;
    #endif

    /* AT handler */
#ifdef __COSMOS_MMI_PACKAGE__
    SetProtocolEventHandler(srv_setting_at_set_rtc, PRT_MSG_ID_MMI_EQ_SET_RTC_TIME_REQ_IND);
#endif
    SetProtocolEventHandler(srv_setting_at_set_date_time_format, PRT_MMI_EQ_SET_DATE_TIME_FORMAT_REQ_IND);    
    SetProtocolEventHandler(srv_setting_at_query_date_time_format, PRT_MMI_EQ_QUERY_DATE_TIME_FORMAT_REQ_IND);    

    /* Language */
    SetProtocolEventHandler(srv_setting_at_query_language, PRT_MMI_EQ_QUERY_LANGUAGE_REQ_IND);    
#ifdef __COSMOS_MMI_PACKAGE__
    SetProtocolEventHandler(srv_setting_at_set_language, PRT_MMI_EQ_SET_LANGUAGE_REQ_IND);        
#endif

#ifdef __MMI_AUTO_LANG_EN__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_SMU_STARTUP_INFO_IND, (PsIntFuncPtr)srv_setting_language_sim_startup_info_hdlr, MMI_TRUE);
#endif
    g_general_setting_is_init = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  PhnsetSetUARTConfig
 * DESCRIPTION
 *  This function is to set UART config to mobile
 * PARAMETERS
 *  rmmi_sim_uart_setting_enum   UART config        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_setting_set_uart_setting(rmmi_sim_uart_setting_enum uart_config)
{
#ifdef __GEMINI__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
	S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, (void*)buffer, 
        NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
    
    switch(uart_config)
    {
    case RMMI_UART_TO_SIM1:
        g_uart_setting = RMMI_UART_TO_SIM1;
        break;
        
    case RMMI_UART_TO_SIM2:
        g_uart_setting = RMMI_UART_TO_SIM2;
        break;

    #if (MMI_MAX_SIM_NUM >= 3)
    case RMMI_UART_TO_SIM3:
        {
            g_uart_setting = RMMI_UART_TO_SIM3;
            break;
        }

    #if (MMI_MAX_SIM_NUM >= 4)
    case RMMI_UART_TO_SIM4:
        {
            g_uart_setting = RMMI_UART_TO_SIM4;
            break;
        }
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */  

        
    case RMMI_SIM_UART_SETTING_NONE:
        g_uart_setting = RMMI_SIM_UART_SETTING_NONE;
        break;
        
    default:
        MMI_ASSERT(0);
        break;
    }
    
    buffer[L4C_SETTING_DUAL_SIM_UART] = g_uart_setting;
    
    WriteRecord(NVRAM_EF_SYS_CACHE_OCTET_LID, NVRAM_SYS_FLIGHTMODE_STATE, (void*)buffer, 
    NVRAM_EF_SYS_CACHE_OCTET_SIZE, &error);
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetUARTConfig
 * DESCRIPTION
 *  This function is to get UART config
 * PARAMETERS
 *  void          
 * RETURNS
 *  void
 *****************************************************************************/
rmmi_sim_uart_setting_enum srv_setting_get_uart_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_general_setting_is_init)
	{
	    srv_setting_init_general_setting();
	}
    return g_uart_setting;
}

/*****************************************************************************
 * FUNCTION
 *  srv_setting_set_primary_sim
 * DESCRIPTION
 *  Set the major card, used in COSMOS, use the same record of UART setting 
 * PARAMETERS
 *  sim     :   [IN]    which sim will be set to major card
 * RETURNS
 *  void
 *****************************************************************************/
void srv_setting_set_primary_card(mmi_sim_enum sim)
{
#ifdef __GEMINI__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    rmmi_sim_uart_setting_enum uart_setting = RMMI_SIM_UART_SETTING_NONE;
    rmmi_sim_uart_setting_enum current_setting;
    rmmi_master_sim_change_req_struct *req;
    oslModuleType dest_mod = MOD_ATCI;
    srv_setting_uart_notification_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_setting = srv_setting_get_uart_setting();
    switch (sim)
	{
	case MMI_SIM1:
		uart_setting = RMMI_UART_TO_SIM1;
		break;
    case MMI_SIM2:
        uart_setting = RMMI_UART_TO_SIM2;
        break;
    #if (MMI_MAX_SIM_NUM >= 3)
    case MMI_SIM3:
        uart_setting = RMMI_UART_TO_SIM3;
        break;

    #if (MMI_MAX_SIM_NUM >= 4)
    case MMI_SIM4:
        uart_setting = RMMI_UART_TO_SIM4;
        break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */        
	default:
		ASSERT(0);
	}
    srv_setting_set_uart_setting(uart_setting);
    
    /* 
     * On COSMOS, switch major card / UART setting will not reboot the phone 
     * Service should send message to indicate L4 the change
     */
    req = (rmmi_master_sim_change_req_struct*)OslConstructDataPtr(sizeof(rmmi_master_sim_change_req_struct));
    req->sim_setting = uart_setting;
    switch (current_setting)
	{
	case RMMI_UART_TO_SIM1:
		dest_mod = MOD_ATCI;
		break;
    case RMMI_UART_TO_SIM2:
		dest_mod = MOD_ATCI_2;
		break;        
    #if (MMI_MAX_SIM_NUM >= 3)
    case RMMI_UART_TO_SIM3:
		dest_mod = MOD_ATCI_3;
		break;  
    #if (MMI_MAX_SIM_NUM >= 4)
    case RMMI_UART_TO_SIM4:
		dest_mod = MOD_ATCI_4;
		break; 
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
	default:
        break;		
	}
    mmi_frm_send_ilm(dest_mod, MSG_ID_MMI_ATCI_MASTER_SIM_CHANGE_REQ, (oslParaType*)req, NULL);

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_SETTING_UART_SETTING_CHANGED);
    evt.new_uart = uart_setting;
    MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);      
#endif    
}

 
/*****************************************************************************
 * FUNCTION
 *  srv_setting_get_primary_card
 * DESCRIPTION
 *  Get major card setting, used in COSMOS, use the same record of UART setting 
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_sim_enum
 *****************************************************************************/
mmi_sim_enum srv_setting_get_primary_card(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum ret = MMI_SIM_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifdef __GEMINI__
    switch (srv_setting_get_uart_setting())
	{
	case RMMI_UART_TO_SIM1:
		ret = MMI_SIM1;
		break;

	case RMMI_UART_TO_SIM2:
		ret = MMI_SIM2;
		break;

    #if (MMI_MAX_SIM_NUM >= 3)
	case RMMI_UART_TO_SIM3:
		ret = MMI_SIM3;
		break;

    #if (MMI_MAX_SIM_NUM >= 4)
	case RMMI_UART_TO_SIM4:
		ret = MMI_SIM4;
		break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ 
    
	default:
		break;
	}
    #else
    ret = MMI_SIM1;
    #endif
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_setting_set_time_format
 * DESCRIPTION
 *  Set system time format 
 * PARAMETERS
 *  timeFormat  :   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_setting_set_time_format(srv_setting_time_format_enum timeFormat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 input = (U8)timeFormat;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset to default if the time format is invalid */
    if (input >= SETTING_TIME_FORMAT_END)
	{
	    input= SETTING_TIME_FORMAT_12_HOURS;
	}
    WriteValue(TIME_FORMAT, &input, DS_BYTE, &error);
    // TODO: SEND NOTIFICATION
    wgui_status_icon_bar_change_timer_format_callback();
}

/*****************************************************************************
 * FUNCTION
 *  srv_setting_get_time_format
 * DESCRIPTION
 *  Get system time format 
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_setting_time_format_enum
 *****************************************************************************/
srv_setting_time_format_enum srv_setting_get_time_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(TIME_FORMAT, &data, DS_BYTE, &error);

    if (data >= SETTING_TIME_FORMAT_END)
    {
	data = SETTING_TIME_FORMAT_12_HOURS;
        WriteValue(TIME_FORMAT, &data, DS_BYTE, &error);    
    }
    return (srv_setting_time_format_enum)data;
}

/*****************************************************************************
 * FUNCTION
 *  srv_setting_set_date_format
 * DESCRIPTION
 *  Set system date format 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_setting_set_date_format(srv_setting_date_format_enum dateFormat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;    
    U8 input = (U8)dateFormat;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset to default if the date format is invalid */    
    if (input >= SETTING_DATE_FORMAT_END)
	{
	    input = SETTING_DATE_FORMAT_DD_MM_YYYY;
	}
    WriteValue(DATE_FORMAT, &input, DS_BYTE, &error);
}
 
 
/*****************************************************************************
 * FUNCTION
 *  srv_setting_get_date_format
 * DESCRIPTION
 *  Get system date format 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_setting_date_format_enum
 *****************************************************************************/
srv_setting_date_format_enum srv_setting_get_date_format(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(DATE_FORMAT, &data, DS_BYTE, &error);

    if (data >= SETTING_DATE_FORMAT_END)
    {
		data = SETTING_DATE_FORMAT_DD_MM_YYYY;
        WriteValue(DATE_FORMAT, &data, DS_BYTE, &error);    
    }
    return (srv_setting_date_format_enum)data;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_setting_set_date_seperator
 * DESCRIPTION
 *  Set system date seperator 
 * PARAMETERS
 *  dateSeperator   :   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_setting_set_date_seperator(srv_setting_date_seperator_enum dateSeperator)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;    
    U8 input = (U8)dateSeperator; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (input >= SETTING_DATE_SEPERATOR_END)
	{
	    input = SETTING_DATE_SEPERATOR_DOT;
	}
    WriteValue(NVRAM_DT_SEP_FORMAT, &input, DS_BYTE, &error);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_setting_get_date_seperator
 * DESCRIPTION
 *  Get system date seperator 
 * PARAMETERS
 *  void
 * RETURNS
 *  mmi_setting_date_seperator_enum
 *****************************************************************************/
srv_setting_date_seperator_enum srv_setting_get_date_seperator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 data;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_DT_SEP_FORMAT, &data, DS_BYTE, &error);

    if (data >= SETTING_DATE_SEPERATOR_END)
    {
	data = SETTING_DATE_SEPERATOR_DOT;
        WriteValue(NVRAM_DT_SEP_FORMAT, &data, DS_BYTE, &error);    
    }
    return (srv_setting_date_seperator_enum)data;
}

/*****************************************************************************
 * FUNCTION
 *  srv_setting_at_set_rtc
 * DESCRIPTION
 *  AT Command set Date Time Format
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_setting_at_set_rtc(void *msg, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME at_time;
    mmi_eq_set_rtc_time_req_ind_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_rtc_time_req_ind_struct*) msg;
    if (msgReq->rtc_type == RTC_TIME_CLOCK_IND)
    {
        mmi_at_general_res_req_struct *rsp_msg;

        at_time.nSec = msgReq->alarm.data_time.rtc_sec;
        at_time.nMin = msgReq->alarm.data_time.rtc_min;
        at_time.nHour = msgReq->alarm.data_time.rtc_hour;
        at_time.nDay = msgReq->alarm.data_time.rtc_day;
        at_time.nMonth = msgReq->alarm.data_time.rtc_mon;
        at_time.nYear = msgReq->alarm.data_time.rtc_year + YEARFORMATE;

        rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));

        if (at_time.nYear < 1970 || at_time.nYear > 2030
            || at_time.nMonth > 12 || (at_time.nMonth == 0) || (at_time.nDay == 0) ||
            at_time.nDay > LastDayOfMonth(at_time.nMonth, at_time.nYear) || at_time.nHour > 23 || at_time.nMin > 59)
        {
            rsp_msg->result = MMI_FALSE;
        }
        else
        {
            rsp_msg->result = MMI_TRUE;
        }

        mmi_dt_set_rtc_dt(&at_time);
        mmi_frm_send_ilm((oslModuleType)mod_id, MSG_ID_MMI_AT_GENERAL_RES_REQ, (oslParaType*)rsp_msg, NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_setting_at_set_date_time_format
 * DESCRIPTION
 *  AT Command set Date Time Format
 * PARAMETERS
 *  msg     [?]     Set date time format request message, specifying time/date
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_setting_at_set_date_time_format(void *msg, int mod_id)
{
#ifndef __SLIM_AT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 date_time_fmt = 0;
    mmi_eq_set_date_time_format_req_ind_struct *msgReq;
    mmi_at_general_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_date_time_format_req_ind_struct*) msg;

    if (msgReq->is_date_set)
    {
		srv_setting_set_date_format_from_at(msgReq->mode);
    }
    else
    {
        switch (msgReq->mode)
        {
            case TIME_HH_MM_24:
                date_time_fmt = 1;
                break;
            case TIME_HH_MM_12:
                date_time_fmt = 0;
                break;
            default:
                break;  /* formt not support */
        }

        srv_setting_set_time_format((srv_setting_time_format_enum)date_time_fmt);
    }

    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    
    rsp_msg->result = MMI_TRUE;

    mmi_frm_send_ilm((oslModuleType)mod_id, MSG_ID_MMI_AT_GENERAL_RES_REQ, (oslParaType*)rsp_msg, NULL);
#endif /* __SLIM_AT__ */    
}
#ifndef __SLIM_AT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_dt_get_datefmt
 * DESCRIPTION
 *  This function is to get date format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_setting_set_date_format_from_at(U8 date_sep_fmt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 date_fmt;
	U8 sep;
	/*
	 *	 0 -> D-M-Y
	 *	 1 -> M-D-Y
	 *	 2 -> Y-M-D
	 */
	/*
	 *   0 -> .
	 *	 1 -> :
	 *	 2 -> /
	 *	 3 -> -
	 */ 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(date_sep_fmt)
	{
		case DATE_DD_MMM_YYYY: /* 27-08-2008 */
            date_fmt = 0;
			sep = 3;
			break;
				
		case DATE_DD_MM_YYYY_S: /* 27/08/2008 */
            date_fmt = 0;
			sep = 2;
            break;
				
        case DATE_MM_DD_YYYY_S: /* 08/27/2008 */
            date_fmt = 1;
			sep = 2;
            break;
				
        case DATE_YYYY_MM_DD_S: /* 2008/08/27 */
            date_fmt = 2;
			sep = 2;
            break;
				
        case DATE_YYYY_MM_DD_H: /* 2008-08-27 */
			date_fmt = 2;
            sep = 3;
            break;
				
        case DATE_MMM_DD_YYYY: /* 2008.08.27 */
		default:
			date_fmt = 1;
			sep = 0;
			
			break;
	}
	
	srv_setting_set_date_format((srv_setting_date_format_enum)date_fmt);
	srv_setting_set_date_seperator((srv_setting_date_seperator_enum)sep);	
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_setting_at_query_date_time_format
 * DESCRIPTION
 *  Query date time format setting from AT command
 * PARAMETERS
 *  msg     [?]     Query type (time/date)
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_setting_at_query_date_time_format(void *msg, int mod_id)
{
#ifndef __SLIM_AT__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 date_time_fmt;
    mmi_eq_query_date_time_format_req_ind_struct *in_msg = (mmi_eq_query_date_time_format_req_ind_struct*) msg;
    mmi_eq_query_date_time_format_res_req_struct *res_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_msg = (mmi_eq_query_date_time_format_res_req_struct*)
        OslConstructDataPtr(sizeof(mmi_eq_query_date_time_format_res_req_struct));

    if (in_msg->is_date == MMI_TRUE)
    {   /* Query date format */

        res_msg->is_date = MMI_TRUE;
		res_msg->mode = srv_setting_get_date_format_for_at();

    }
    else
    {   /* Query time format */

        res_msg->is_date = MMI_FALSE;
        date_time_fmt = (U8)srv_setting_get_time_format();

        switch (date_time_fmt)
        {
            case 0:
                res_msg->mode = TIME_HH_MM_12;
                break;
            case 1:
                res_msg->mode = TIME_HH_MM_24;
                break;
            default:
                res_msg->mode = TIME_HH_MM_12;
                break;
        }
    }
    mmi_frm_send_ilm((oslModuleType)mod_id, PRT_MMI_EQ_QUERY_DATE_TIME_FORMAT_RES_REQ, (oslParaType*)res_msg, NULL);
#endif /* __SLIM_AT__ */
}
#ifndef __SLIM_AT__
/*****************************************************************************
 * FUNCTION
 *  mmi_phnset_dt_get_datefmt
 * DESCRIPTION
 *  This function is to get date seperator format
 *  Functionality:
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_setting_get_date_format_for_at(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 date_fmt;
	U8 sep_fmt;
	U8 ret;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*
	 *	 0 -> D-M-Y
	 *	 1 -> M-D-Y
	 *	 2 -> Y-M-D
	 */
	date_fmt = (U8)srv_setting_get_date_format();
	/*
	 *   0 -> .
	 *	 1 -> :
	 *	 2 -> /
	 *	 3 -> -
	 */
	sep_fmt = (U8)srv_setting_get_date_seperator();

	switch(date_fmt + sep_fmt)
	{
	    case 1:
            ret = DATE_MMM_DD_YYYY;
            break;
            
		case 2:
			ret = DATE_DD_MM_YYYY_S;
			break;
			
		case 3:
		{
			if (date_fmt == 1)
			{
				ret = DATE_MM_DD_YYYY_S;	
			}
			else 
			{
				ret = DATE_DD_MMM_YYYY;
			}
		}
		break;
			
		case 4:	
			ret = DATE_YYYY_MM_DD_S;
		    break;
            
        case 5:
        default:
            ret = DATE_YYYY_MM_DD_H;
		break;
				
	}

	return ret;
}
#endif
extern sLanguageDetails *gLanguageArray;
extern U16 gCurrLangIndex;
extern U16 gMaxDeployedLangs;
#ifndef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_setting_set_language
 * DESCRIPTION
 *  Set system language by index of gLanguageArray 
 * PARAMETERS
 *  language_idx    :   [IN] index of language in gLanguageArray
 * RETURNS
 *  MMI_FALSE : system do not support this language
 *  MMI_TRUE  : the language is set successfully
 *****************************************************************************/
MMI_BOOL srv_setting_set_language(U8 language_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_setting_set_language_ext(language_idx);
    if (result != MMI_TRUE)
	{
	    return result;
	}
#ifdef __MMI_SET_DEF_ENCODING_TYPE__
    srv_setting_set_encoding_type_by_language();
#endif
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_setting_set_language_ext
 * DESCRIPTION
 *  Set system language by index of gLanguageArray 
 * PARAMETERS
 *  language_idx    :   [IN] index of language in gLanguageArray
 * RETURNS
 *  MMI_FALSE : system do not support this language
 *  MMI_TRUE  : the language is set successfully
 *****************************************************************************/
MMI_BOOL srv_setting_set_language_ext(U8 language_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_AUTO_LANG_EN__
    U16 autoLangIdx;
    #endif /* __MMI_AUTO_LANG_EN__ */ 
    S16 error;
    srv_setting_language_notification_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_set_language_ext %d", language_idx);
    if (language_idx >= MAX_LANGUAGES
    #ifdef __MMI_AUTO_LANG_EN__        
        && language_idx != SRV_AUTO_LANGUAGE_IDX
        #endif /* __MMI_AUTO_LANG_EN__ */ 
        )
	{
	    return MMI_FALSE;
	}
#ifdef __MMI_AUTO_LANG_EN__    
    if (language_idx == SRV_AUTO_LANGUAGE_IDX)
    {
        autoLangIdx = srv_setting_get_auto_language_id(); 
        mmi_res_set_language((CHAR)autoLangIdx);
    }
    else
#endif /* __MMI_AUTO_LANG_EN__ */
    {
        mmi_res_set_language((CHAR)language_idx);
    }
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_set_language_ext set");
    WriteValue(NVRAM_SETTING_LANG, &language_idx, DS_BYTE, &error);

    /* send language change notification */
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_SETTING_LANGUAGE_CHANGED);
    evt.language_ssc_code = gLanguageArray[language_idx].aLangSSC;
	MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);    
    
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_setting_set_language
 * DESCRIPTION
 *  Set system language by SSC code of language, Please refer to 
 *  SSCStringHandler.h
 * PARAMETERS
 *  ssc_code    :   [IN]    ssc code of language
 * RETURNS
 *  MMI_FALSE : system do not support this language
 *  MMI_TRUE  : the language is set successfully
 *****************************************************************************/
MMI_BOOL srv_setting_set_language_by_ssc(U8* ssc_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Auto language */
#ifdef __MMI_AUTO_LANG_EN__    
    if (strcmp(SSC_AUTO, ssc_code) == 0)
	{
	    return srv_setting_set_language(SRV_AUTO_LANGUAGE_IDX);
	}
#endif    
    for (i = 0; i < MAX_LANGUAGES; i++)
	{
        if (strcmp((CHAR*)gLanguageArray[i].aLangSSC, (CHAR*)ssc_code) == 0)
        {
            break;
        }		
	}
    if (i == MAX_LANGUAGES)
	{
	    return MMI_FALSE;
	}
    return srv_setting_set_language(i);
}
#endif //#ifndef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_setting_init_language
 * DESCRIPTION
 *  This function is to read language setting from nvram and set
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void srv_setting_init_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
	U8 buffer[NVRAM_EF_SYS_LANGUAGE_SSC_SIZE] = {0};
#else
	U8 data;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
	srv_setting_get_language(buffer);
	srv_setting_set_language_ext(buffer);
#else
    data = srv_setting_get_language();
    if (data == 0xFF)
    {
    #ifndef __MMI_AUTO_LANG_EN__
        /* auto language is not supported, reset the language to English */
        data = 0;
    #endif /* __MMI_AUTO_LANG_EN__ */ 
    }

#ifdef __KJX_MULTI_LANGUAGE__
	switch(g_kjx_language)
	{
	case LANG_ENGLISH:				//英
	case LANG_FRENCH:				//法
	case LANG_GERMAN:				//德
	case LANG_ITALIAN:				//意大利
	case LANG_SPANISH:				//西班牙
	case LANG_PORTUGUESE:			//葡萄牙
	case LANG_POLISH:				//波兰
	case LANG_DANISH:				//丹麦
	case LANG_SWEDISH:				//瑞典
	case LANG_NORWEGIAN:			//挪威
	case LANG_FINNISH:				//芬兰
	case LANG_DUTCH:				//荷兰
	case LANG_UKRAINIAN:			//乌克兰
	case LANG_RUSSIAN:				//俄罗斯
	case LANG_GREEK:				//希腊
	case LANG_TURKISH:				//土耳其
	case LANG_ARABIC:				//阿拉伯
	case LANG_HEBREW:				//希伯来语(以色列)
	case LANG_PERSIAN:				//波斯语(伊朗)
	case LANG_URDU: 				//乌尔都语(巴基斯坦)
	case LANG_HINDI:				//印地语(印度)
	case LANG_BENGALI:				//孟加拉
	case LANG_LAO:					//老挝
	case LANG_KHMER:				//高棉语(柬埔寨)
	case LANG_MYANMAR:				//缅甸
	case LANG_VIETNAMESE:			//越南
	case LANG_INDONESIAN:			//印度尼西亚
	case LANG_MALAY:				//马来语(马来西亚,文莱)
	case LANG_THAI: 				//泰国
	case LANG_FILIPINO: 			//菲律宾语
	case LANG_KOREAN:				//朝鲜语(朝鲜,韩国)
	case LANG_JAPANESE: 			//日本
		data = 0;
		break;

	case LANG_CHN:					//中文普通话
	case LANG_CHN_SC:				//中文四川话
	case LANG_CHN_GD:				//中文广东话
	case LANG_CHN_MN:				//中文闽南话
	case LANG_CHN_XZ:				//中文藏语
	case LANG_CHN_XZ_LASA:				//中文藏语拉萨
	case LANG_CHN_XZ_ANDUO:				//中文藏语安多
	case LANG_CHN_XZ_KANGBA:			//中文藏语康巴
	case LANG_CHN_EXTRA:			//中文其他方言
		data = 1;
		break;

	default:
		data = 1;
		break;
	}
#endif

    srv_setting_set_language_ext(data);        
#endif //__MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__

#ifdef __MMI_SET_DEF_ENCODING_TYPE__
    srv_setting_init_encoding_type();
#endif    
}

#ifndef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_setting_get_language
 * DESCRIPTION
 *  Get current system language index, different from gCurrLangIndex, if 
 *  return value = 0xFF, means at auto language setting
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_setting_get_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 data;
    S16 error;
#if defined(__OP01__) || defined(__OP02__)
    U8 i = 0;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SETTING_LANG, &data, DS_BYTE, &error);
    
#if defined(__OP01__) || defined(__OP02__)
	if(data == 0xFE)
	{
        for (i = 0; i < MAX_LANGUAGES; i++)
        {
            if (strcmp((PS8)gLanguageArray[i].aLangSSC, SSC_SCHINESE) == 0)
            {
                data = i;
				break;
            }		
        }
    }
#endif

    return data;
}

/*****************************************************************************
 * FUNCTION
 *  srv_setting_get_language_string
 * DESCRIPTION
 *  Get the language string of input language 
 * PARAMETERS
 *  
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
WCHAR* srv_setting_get_language_string(U8 language_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (language_idx >= MAX_LANGUAGES
#ifdef __MMI_AUTO_LANG_EN__
        && language_idx != SRV_AUTO_LANGUAGE_IDX
#endif /* __MMI_AUTO_LANG_EN__ */
        )
	{
	    return NULL;
	}
#ifdef __MMI_AUTO_LANG_EN__
    if (language_idx == SRV_AUTO_LANGUAGE_IDX)
    {
        return (WCHAR*)GetString(STR_GLOBAL_AUTOMATIC);
    }
#endif /* __MMI_AUTO_LANG_EN__ */        
    return (WCHAR*)gLanguageArray[language_idx].aName;
}
#endif // #ifndef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__

#ifdef __MMI_AUTO_LANG_EN__
static U8 g_lp = CBS0_LANG_UNSPECIFIED;
typedef struct
{
    srv_phnset_language_enum language;
    CHAR *language_ssc;
} srv_setting_auto_language_struct;

static srv_setting_auto_language_struct srv_auto_lang_struct[] = 
{
    /* ISO 639 2-alphabet Language Codes */
    {CBS2_ZH, SSC_SCHINESE},
    {CBS2_TW, SSC_TCHINESE},
    {CBS0_ENGLISH, SSC_ENGLISH},
    {CBS0_SPANISH, SSC_SPANISH},
    {CBS2_TH, SSC_THAI},
    {CBS0_FRENCH, SSC_FRENCH},
    {CBS0_GERMAN, SSC_GERMAN},
    {CBS0_ITALIAN, SSC_ITALIAN},
    {CBS0_PORTUGUESE, SSC_PORTUGUESE},
    {CBS1_RUSSIAN, SSC_RUSSIAN},
    {CBS2_BG, SSC_BULGARIAN},
    {CBS0_TURKISH, SSC_TURKISH},
    {CBS2_VI, SSC_VIETNAMESE},
    {CBS2_ID, SSC_INDONESIAN},
    {CBS2_MS, SSC_MALAY},
    {CBS1_ARABIC, SSC_ARABIC},
    {CBS2_FA, SSC_PERSIAN},
    {CBS2_SK, SSC_SLOVAK},
    //{CBS2_NL, SSC_DUTCH},
    //{CBS1_FINNISH, SSC_FINNISH},
    //{CBS2_SV, SSC_SWEDISH},
    {CBS2_HR, SSC_CROATIAN},
    {CBS2_RO, SSC_ROMANIAN},
    {CBS2_SL, SSC_SLOVENIAN},
    //{CBS2_EL, SSC_GREEK},
    //{CBS2_CS, SSC_CZECH},
    {CBS0_LANG_UNSPECIFIED, NULL /* Language UnSpecificed */ },
    {CBS_INVALID, NULL /* Language UnSpecificed */ }
};

#define SRV_SETTING_NUM_OF_AUTO_LANGUAGE   (sizeof(srv_auto_lang_struct) / sizeof(srv_auto_lang_struct[0]))
#define SRV_MAX_AUTO_LANGUAGE (5)
/*****************************************************************************
 * FUNCTION
 *  srv_setting_set_lp
 * DESCRIPTION
 *  This function is for SIM info indication to set LP
 *  Functionality:
 * PARAMETERS
 *  LP          [IN]            
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void srv_setting_set_lp(U8 lp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Phonesetup.c] mmi_setting_set_lp %d", lp);
    g_lp = lp;
}


/*****************************************************************************
 * FUNCTION
 *  PhnsetGetAutoLangIdx
 * DESCRIPTION
 *  This function is to read language setting from nvram and set
 *  Functionality:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_setting_get_auto_language_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 lang_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_lp != CBS_INVALID && g_lp != CBS0_LANG_UNSPECIFIED)
    {
        for (lang_idx = 0; lang_idx < SRV_SETTING_NUM_OF_AUTO_LANGUAGE; lang_idx++)
        {
            if (g_lp == srv_auto_lang_struct[lang_idx].language)
            {
                if (srv_auto_lang_struct[lang_idx].language_ssc)
                {
                    return GetLanguageIndex((CHAR*) srv_auto_lang_struct[lang_idx].language_ssc);
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    #ifdef __OP01__
    {
        // Set the default language to SC
        U8 i;
        for (i = 0; i < MAX_LANGUAGES; i++)
        {
            if (strcmp((CHAR*)gLanguageArray[i].aLangSSC, SSC_SCHINESE) == 0)
            {
                return i;
            }		
        }
    }
    #endif /* __OP01__ */    
    
    #ifdef MMI_ON_HARDWARE_P
    return (U16) GetLanguageIndex((CHAR*) MMI_DEFLANGSSC_FOR_AUTO);
    #else 
    return 0;
    #endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_setting_prepare_auto_language_by_sim_file
 * DESCRIPTION
 *  Set the language of phone by SIM file EFLI and EFPL 
 * PARAMETERS
 *  li_array    :   [IN] EFLI data from MSG_ID_MMI_SMU_STARTUP_INFO_IND
 *  pl_array    :   [IN] EFPL data from MSG_ID_MMI_SMU_STARTUP_INFO_IND
 * RETURNS
 *  void
 *****************************************************************************/
void srv_setting_prepare_auto_language_by_sim_file(U8 *li_array, U8 *pl_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if language can set by EFLI */
    if (srv_setting_prepare_auto_language(li_array))
	{
	    return;
	}
    /* Check if language can set by EFPL */
    if (srv_setting_prepare_auto_language(pl_array))
	{
	    return;
	}    
}
 

/*****************************************************************************
 * FUNCTION
 *  srv_setting_prepare_auto_language
 * DESCRIPTION
 *  Set the language of phone by SIM file EFLI and EFPL 
 * PARAMETERS
 *  language_ind_array  :   [IN]    EFLI or EFPL data from 
 *                                  MSG_ID_MMI_SMU_STARTUP_INFO_IND
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_setting_prepare_auto_language(U8 *language_ind_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_MAX_AUTO_LANGUAGE; i++)
    {
        /* found LP from language_type/SSC mapping table --> srv_auto_lang_struct[]  */
        for (j = 0; j < SRV_SETTING_NUM_OF_AUTO_LANGUAGE; j++)
        {
    	    if (language_ind_array[i] == CBS_INVALID || language_ind_array[i] == CBS0_LANG_UNSPECIFIED)
    	    {
        		return MMI_FALSE;
    	    }
            if (language_ind_array[i] == srv_auto_lang_struct[j].language)
            {
                break;
            }
        }

        /* Find language array (gLanguageArray) using found SSC */
        if (j != SRV_SETTING_NUM_OF_AUTO_LANGUAGE)
        {
            if (srv_auto_lang_struct[j].language_ssc)
            {
                if (GetLanguageIndex((CHAR*) srv_auto_lang_struct[j].language_ssc) != 0xFFFF)
                {
                    srv_setting_set_lp(language_ind_array[i]);
                    return MMI_TRUE;
                }
            }
        }
    }
    return MMI_FALSE;
}


static MMI_BOOL srv_setting_language_sim_startup_info_hdlr(void *msg, S32 src_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_smu_startup_info_ind_struct *local_data = (mmi_smu_startup_info_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* process and store LP in context */
    srv_setting_prepare_auto_language_by_sim_file(local_data->language, local_data->language_ext);

    /* If UsrLangIdx != 0xFF, not necessary to handle it because */
    /* 1. PhnsetSetLangByNvramValue() has been executed --> Language has already set */
    /* 2. PhnsetSetLangByNvramValue() did not executed --> */
    /*    PhnsetSetLangByNvramValue() will be execute later and Language will be set at that time */
    if (srv_setting_get_language()== 0xFF)
    {
        /* in ReadRes.c, do not change NVRAM data */
        srv_setting_set_language(0xFF);
    }
    return MMI_FALSE;
}
#endif /* __MMI_AUTO_LANG_EN__ */ 

/*****************************************************************************
 * FUNCTION
 *  ATSetLanguage
 * DESCRIPTION
 *  Set Language from AT command
 * PARAMETERS
 *  msg     [?]     Set language request
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_setting_at_set_language(void *msg, int mod_id)
{
#ifndef __SLIM_AT__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* to see the value of language code */
    U8 data = 0;
    CHAR *ssc_sp;
    mmi_eq_set_language_req_ind_struct *msgInd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgInd = (mmi_eq_set_language_req_ind_struct*) msg;

    switch (msgInd->lang_code)
    {
        case MMI_PS_AT_LANG_TW:
            ssc_sp = SSC_TCHINESE;  /* data = 1; */
            break;
        case MMI_PS_AT_LANG_ZH:
            ssc_sp = SSC_SCHINESE;  /* data = 2; */
            break;

        case MMI_PS_AT_LANG_DEFAULT:
        case MMI_PS_AT_LANG_EN:
        default:
            ssc_sp = SSC_ENGLISH;   /* data = 0; */
            break;
    }

    data = (U8)mmi_lang_support((U8*)ssc_sp);

    /* Language not support (out of boundary) */
    if (data >= gMaxDeployedLangs)
    {
        srv_setting_at_set_language_send(0xFF, mod_id);
        return;
    }

    if (data != gCurrLangIndex)
    {
    #ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
		srv_setting_set_language((U8*)ssc_sp);
	#else
        srv_setting_set_language(data);
	#endif
    }

    srv_setting_at_set_language_send(data, mod_id);
#endif /* __SLIM_AT__ */
}


#ifndef __SLIM_AT__
/*****************************************************************************
 * FUNCTION
 *  srv_setting_at_set_language_send
 * DESCRIPTION
 *  Send to AT command when language change, for AT+CLAE
 * PARAMETERS
 *  code        [IN]        Language to be set
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_setting_at_set_language_send(U8 code, int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_set_language_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_eq_set_language_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_set_language_req_struct));

    /*
     * switch (code)
     * {
     * case 0: msgReq->lang_code = MMI_PS_AT_LANG_EN; break;
     * case 1: msgReq->lang_code = MMI_PS_AT_LANG_TW; break;
     * case 2: msgReq->lang_code = MMI_PS_AT_LANG_ZH; break;
     * default: msgReq->lang_code = MMI_PS_AT_LANG_EN; break;
     * }
     */

    if (code > gMaxDeployedLangs)
    {
        msgReq->lang_code = MMI_PS_AT_LANG_UNKWN;
    }
    else
    {
        if (strcmp((CHAR*) gLanguageArray[code].aLangSSC, SSC_ENGLISH) == 0)
        {
            msgReq->lang_code = MMI_PS_AT_LANG_EN;
        }
        else if (strcmp((CHAR*) gLanguageArray[code].aLangSSC, SSC_TCHINESE) == 0)
        {
            msgReq->lang_code = MMI_PS_AT_LANG_TW;
        }
        else if (strcmp((CHAR*) gLanguageArray[code].aLangSSC, SSC_SCHINESE) == 0)
        {
            msgReq->lang_code = MMI_PS_AT_LANG_ZH;
        }
        else
        {
            msgReq->lang_code = MMI_PS_AT_LANG_UNKWN;
        }
    }
    mmi_frm_send_ilm((oslModuleType)mod_id, PRT_MMI_EQ_SET_LANGUAGE_REQ, (oslParaType*)msgReq, NULL);
}
#endif /* __SLIM_AT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_setting_at_query_language
 * DESCRIPTION
 *  Query language setting from AT command
 * PARAMETERS
 *  msg     [?]     No action
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_setting_at_query_language(void *msg, int mod_id)
{
#ifndef __SLIM_AT__    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 lang_type = MMI_PS_AT_LANG_DEFAULT;
    mmi_eq_query_language_res_req_struct *res_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_msg =
        (mmi_eq_query_language_res_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_query_language_res_req_struct));

    if (strcmp((CHAR*) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_TCHINESE) == 0)
    {
        lang_type = MMI_PS_AT_LANG_TW;
    }
    else if (strcmp((CHAR*) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_SCHINESE) == 0)
    {
        lang_type = MMI_PS_AT_LANG_ZH;
    }
    else if (strcmp((CHAR*) gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH) == 0)
    {
    	lang_type = MMI_PS_AT_LANG_EN;
    }
    else
    {
        lang_type = MMI_PS_AT_LANG_UNKWN;
    }

    res_msg->lang_code = lang_type;

    mmi_frm_send_ilm((oslModuleType)mod_id, PRT_MMI_EQ_QUERY_LANGUAGE_RES_REQ, (oslParaType*)res_msg, NULL);
#endif /* __SLIM_AT__ */
}

#ifdef __MMI_SET_DEF_ENCODING_TYPE__
/*****************************************************************************
 * FUNCTION
 *  srv_setting_set_encoding_type_by_language
 * DESCRIPTION
 *  This function is to set the default encoding type according to current language
 * PARAMETERS
 *  void          
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void srv_setting_set_encoding_type_by_language(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_chset_enum chset_list[CHSET_TOTAL];
    mmi_chset_enum default_chset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* If language is English, don't change the default encoding */
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_set_encoding_type_by_language gCurrLangIndex %d", gCurrLangIndex);
    if (strcmp((CHAR*)gLanguageArray[gCurrLangIndex].aLangSSC, SSC_ENGLISH) == 0)
    {
        return;
    }

    mmi_chset_get_chset_list_by_language(chset_list, &default_chset);
    if (srv_setting_get_encoding_type() != default_chset)
    {
        srv_setting_set_encoding_type(default_chset);
    }
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_set_encoding_type_by_language g_chset_text_encoding %d", g_chset_text_encoding);
}


/*****************************************************************************
 * FUNCTION
 *  srv_setting_set_encoding_type
 * DESCRIPTION
 *  This function is LSK handler for Phonesetup->Default Encoding Type -> X
 *  Follow functions:
 * PARAMETERS
 *  void
 *  a(?)        [IN/OUT]        
 *  b(?)        [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
void srv_setting_set_encoding_type(mmi_chset_enum encoding_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_chset_text_encoding = encoding_type;
    WriteValue(NVRAM_SETTING_DEF_ENCODING, &encoding_type, DS_BYTE, &error);
    /* send notification */
}


/*****************************************************************************
 * FUNCTION
 *  srv_setting_init_encoding_type
 * DESCRIPTION
 *  Init encoding  type of phone 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_setting_init_encoding_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 encoding_type;    
	#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
	U8 curLangSSC[NVRAM_EF_SYS_LANGUAGE_SSC_SIZE];
	#endif
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_init_encoding_type 1 g_chset_text_encoding %d", g_chset_text_encoding);
    ReadValue(NVRAM_SETTING_DEF_ENCODING, &encoding_type, DS_BYTE, &error);
    if (encoding_type == 0xFF)
    {
    #ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
		srv_setting_get_language(curLangSSC);
		if (strcmp(curLangSSC, SSC_AUTO) == 0)
	#else
        if (srv_setting_get_language() != 0)
	#endif
        {
            srv_setting_set_encoding_type_by_language();            
        }
        else
    	{
    	    encoding_type = mmi_chset_get_english_default_chset();
            WriteValue(NVRAM_SETTING_DEF_ENCODING, &encoding_type, DS_BYTE, &error);
    	}
    }
    g_chset_text_encoding = (mmi_chset_enum)encoding_type;
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_init_encoding_type 2 g_chset_text_encoding %d", g_chset_text_encoding);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_setting_get_encoding_type
 * DESCRIPTION
 *  Get system encoding type 
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 *****************************************************************************/
mmi_chset_enum srv_setting_get_encoding_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_chset_enum)g_chset_text_encoding;
}

#ifdef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
void srv_setting_set_initial_language(U8* langSSC)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//U8 buffer[NVRAM_EF_SYS_LANGUAGE_SSC_SIZE] = SSC_AUTO;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	nvram_external_write_data(NVRAM_EF_SYS_LANGUAGE_SSC_LID, 1, langSSC, NVRAM_EF_SYS_LANGUAGE_SSC_SIZE);
}

void srv_setting_get_initial_language(U8* langSSC)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 buffer[NVRAM_EF_SYS_LANGUAGE_SSC_SIZE] = {0};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	nvram_external_read_data(NVRAM_EF_SYS_LANGUAGE_SSC_LID, 1, buffer, sizeof(buffer));	
	strcpy((S8*)langSSC, (S8*)buffer);
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_get_initial_language %s ==> %s", buffer, langSSC);
}

void srv_setting_get_language(U8* langSSC)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U8 buffer[NVRAM_EF_SYS_LANGUAGE_SSC_SIZE] = {0};
	S16 error;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	ReadRecord(NVRAM_EF_SYS_LANGUAGE_SSC_LID, 1, buffer, NVRAM_EF_SYS_LANGUAGE_SSC_SIZE, &error);

#if defined(__OP01__) || defined(__OP02__)
	strcpy((PS8)buffer, SSC_SCHINESE);
#endif

	strcpy((S8*)langSSC, (S8*)buffer);
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_get_language %s ==> %s", buffer, langSSC);
}

MMI_BOOL srv_setting_set_language(U8* langSSC)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MMI_BOOL result;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	result = srv_setting_set_language_ext(langSSC);

	if (result != MMI_TRUE)
	{
		return result;
	}
	
#ifdef __MMI_SET_DEF_ENCODING_TYPE__
	srv_setting_set_encoding_type_by_language();
#endif

	return result;	
}

MMI_BOOL srv_setting_set_language_ext(U8* langSSC)
{
    #ifdef __MMI_AUTO_LANG_EN__
		U16 autoLangIdx;
    #endif /* __MMI_AUTO_LANG_EN__ */ 
		S16 error;
		U8 index;
		srv_setting_language_notification_struct evt;
		
		/*----------------------------------------------------------------*/
		/* Code Body													  */
		/*----------------------------------------------------------------*/
		MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_set_language_ext SSC: %s", langSSC);
		index = (U8)mmi_lang_support(langSSC);
		MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_set_language_ext lang_idx = %02d", index);
		if (index == 0xFF)
		{
			return MMI_FALSE;
		}
		if (index >= MAX_LANGUAGES
    #ifdef __MMI_AUTO_LANG_EN__        
			&& index != SRV_AUTO_LANGUAGE_IDX
        #endif /* __MMI_AUTO_LANG_EN__ */ 
			)
		{
			return MMI_FALSE;
		}
#ifdef __MMI_AUTO_LANG_EN__    
		if (index == SRV_AUTO_LANGUAGE_IDX)
		{
			autoLangIdx = srv_setting_get_auto_language_id(); 
			mmi_res_set_language((CHAR)autoLangIdx);
		}
		else
#endif /* __MMI_AUTO_LANG_EN__ */
		{
			mmi_res_set_language((CHAR)index);
		}
		MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_set_language_ext set");
		WriteRecord(NVRAM_EF_SYS_LANGUAGE_SSC_LID, 1, langSSC, NVRAM_EF_SYS_LANGUAGE_SSC_SIZE, &error);
	
		/* send language change notification */
		MMI_FRM_INIT_EVENT(&evt, EVT_ID_SETTING_LANGUAGE_CHANGED);
		evt.language_ssc_code = gLanguageArray[index].aLangSSC;
		MMI_FRM_CB_EMIT_EVENT((mmi_event_struct *)&evt);	
		
		return MMI_TRUE;
}

WCHAR* srv_setting_get_language_string(U8* langSSC)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 index = (U8)mmi_lang_support(langSSC);
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (index == 0xFF)
	{
		MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[GeneralSettingSrv.c] srv_setting_set_language_ext lang_idx = %02d", index);
		index = 0;
	}
	return (WCHAR*)gLanguageArray[index].aName;
}

#endif


