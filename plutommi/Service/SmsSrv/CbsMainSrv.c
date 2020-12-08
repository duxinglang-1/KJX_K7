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
 *  CbsMainSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CBS(Cell Broadcast Service) Service Initialization Handler
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __SRV_CBS_SUPPORT__

#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "stack_msgs.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "string.h"
#include "custom_mmi_default_value.h"
#include "DateTimeType.h"
#include "app_datetime.h"

#include "mmi_msg_struct.h"
#include "ps_public_enum.h"
#include "ProtocolEvents.h"
#include "MMI_common_app_trc.h"
#include "SmsSrvGProt.h"
#include "CbsSrvGProt.h"
#include "SmsProtSrv.h"
#include "SmsUtilSrv.h"
#include "SmsDispatchSrv.h"
#include "CbsProtSrv.h"
#include "SatSrvGprot.h"
#include "SimCtrlSrvGprot.h"

/**************************************************************
* MARCO
**************************************************************/
#define SRV_CBS_INIT_DONE           (SRV_CBS_FLAG_STORAGE_DONE | SRV_CBS_FLAG_SETTING_DONE)
#define SRV_CBS_GS_MAX              (0x03)

/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    srv_sms_sim_enum sim_id;
} srv_cbs_init_cntx_struct;

typedef struct
{
    srv_sms_sim_enum sim_id;
} cbs_refresh_cntx_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_cbs_cntx_struct srv_cbs_cntx_array[SMS_SIM_NUM];


/**************************************************************
* Static Function Declaration
**************************************************************/
static void srv_cbs_startup_hdlr(void* in_msg, srv_sms_sim_enum sim_id);
static void srv_cbs_gs_change_hdlr(void *in_msg, srv_sms_sim_enum sim_id);
static void srv_cbs_new_msg_hdlr(void* in_msg, srv_sms_sim_enum sim_id);
static U32 srv_cbs_get_local_utc_sec(void);
static void srv_cbs_init_storage_callback(srv_sms_callback_struct *callback_data);
static void srv_cbs_init_setting_callback(srv_sms_callback_struct *callback_data);
static void srv_cbs_init_done_hdlr(
                srv_cbs_cntx_struct *cbs_cntx,
                srv_cbs_init_cntx_struct *init_cntx);
static void srv_cbs_refresh_setting_callback(srv_sms_callback_struct *callback_data);
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
static void srv_cbs_sim_refresh_hdlr(srv_sms_sim_enum sim_id);
static void srv_cbs_sim_availablity_change_handle(mmi_event_struct *evt);
#endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */

/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_cbs_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_cbs_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_sms_disp_struct *event_data = (mmi_evt_sms_disp_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_EVENT_PROC, evt->evt_id);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SMS_PS_NORMAL_IND:
        {
            if (event_data->msg_id == PTR_MSG_ID_SRV_SMS_STARTUP_READ_IND)
            {
                srv_cbs_startup_hdlr(event_data->data, (srv_sms_sim_enum)event_data->sim_id);
            }
            break;
        }

        case EVT_ID_SRV_SMS_PS_CB_MSG_IND:
            srv_cbs_new_msg_hdlr(event_data->data, (srv_sms_sim_enum)event_data->sim_id);
            break;

        case EVT_ID_SRV_SMS_PS_CB_GS_CHANGE_IND:
            srv_cbs_gs_change_hdlr(event_data->data, (srv_sms_sim_enum)event_data->sim_id);
            break;
            
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
        case EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED:
            srv_cbs_sim_availablity_change_handle(evt);
            break;
#endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */

        default:
            break;
    }

    return MMI_RET_OK;
}

#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
static void srv_cbs_sim_availablity_change_handle(mmi_event_struct *evt)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_event_detected_evt_struct *sim_ctrl_changed_evt = (srv_sim_ctrl_event_detected_evt_struct*)evt;
    srv_sms_sim_enum sim = (srv_sms_sim_enum)sim_ctrl_changed_evt->sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_SIM_CTRL_EVENT_DET_INSERTED == sim_ctrl_changed_evt->type)
    {
        return;
    }
    else
    {
        if(sim & MMI_SIM1)
        {
            srv_cbs_sim_refresh_hdlr(SRV_SMS_SIM_1) ;   
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        if(sim & MMI_SIM2)
        {
            srv_cbs_sim_refresh_hdlr(SRV_SMS_SIM_2) ;  
        }
    #endif /*(MMI_MAX_SIM_NUM >= 2)*/
    #if (MMI_MAX_SIM_NUM >= 3)
        if(sim & MMI_SIM3)
        {
            srv_cbs_sim_refresh_hdlr(SRV_SMS_SIM_3) ;  
        }
    #endif /*(MMI_MAX_SIM_NUM >= 3)*/
    #if (MMI_MAX_SIM_NUM >= 4)
        if(sim & MMI_SIM4)
        {
            srv_cbs_sim_refresh_hdlr(SRV_SMS_SIM_4) ;  
        }
    #endif /*(MMI_MAX_SIM_NUM >= 4)*/
    }
    
    return ;
}
#endif /* (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)) */


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_is_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_cbs_is_ready(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_cntx_struct *cbs_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cbs_cntx = srv_cbs_get_cntx(sim_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_IS_READY, sim_id, cbs_cntx->is_ready);

    return cbs_cntx->is_ready;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_startup_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_startup_hdlr(void *in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_startup_read_ind_struct *read_ind = (mmi_sms_startup_read_ind_struct*)in_msg;
    srv_cbs_cntx_struct *cbs_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_STARTUP_HDLR, sim_id, read_ind->sim_status);

    cbs_cntx = srv_cbs_get_cntx(sim_id);

    if (!(cbs_cntx->flag & SRV_CBS_FLAG_STARTUP_IND))
    {


    #ifndef __MMI_DYNAMIC_SIM_DYNAMIC_UI__  
        if (read_ind->sim_status == L4C_SIM_INSERTED)
        
    #else
        if ((read_ind->sim_status == L4C_SIM_INSERTED) || (read_ind->sim_status == L4C_SIM_BLOCK))
        
    #endif
        {
            srv_cbs_init_cntx_struct *init_cntx;

            cbs_cntx->flag = SRV_CBS_FLAG_STARTUP_IND;
            cbs_cntx->flag |= SRV_CBS_FLAG_SIM_INSERTED;

            init_cntx = OslMalloc(sizeof(srv_cbs_init_cntx_struct));

            init_cntx->sim_id = sim_id;

            srv_cbs_storage_init(sim_id, srv_cbs_init_storage_callback, init_cntx);
            srv_cbs_setting_init(sim_id, srv_cbs_init_setting_callback, init_cntx);
        }
	else
	{
	    cbs_cntx->flag |= SRV_CBS_FLAG_INIT_DONE;
	}
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_sim_refresh_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
#if (defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__))
void srv_cbs_sim_refresh_hdlr(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_cntx_struct *cbs_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cbs_cntx = srv_cbs_get_cntx(sim_id);

    if (cbs_cntx->flag & SRV_CBS_FLAG_INIT_DONE)
    {
        if (cbs_cntx->is_ready)
        {
            srv_cbs_ready_event_struct event_data;

            cbs_cntx->is_ready = MMI_FALSE;

            MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_READY_IND);
            event_data.sim_id = sim_id;
            event_data.is_ready = MMI_FALSE;
            MMI_FRM_CB_EMIT_EVENT(&event_data);
        }

        if (cbs_cntx->flag & SRV_CBS_FLAG_REFRESH)
        {
            cbs_cntx->flag |= SRV_CBS_FLAG_REFRESH_REPEAT;
        }
        else
        {
            cbs_refresh_cntx_struct *refresh_cntx;

            cbs_cntx->flag |= SRV_CBS_FLAG_REFRESH;

            refresh_cntx = OslMalloc(sizeof(cbs_refresh_cntx_struct));

            refresh_cntx->sim_id = sim_id;

            srv_cbs_setting_init(
                sim_id,
                srv_cbs_refresh_setting_callback,
                refresh_cntx);
        }
    }
    else
    {
        /* It is initializing, just need to set the SIM refresh flag */
        cbs_cntx->flag |= SRV_CBS_FLAG_REFRESH;
    }
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_cbs_sim_refresh_event_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret srv_cbs_sim_refresh_event_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sat_sim_refresh_event_struct *event_data = (srv_sat_sim_refresh_event_struct *)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(event_data->refresh_type == SRV_SAT_REFRESH_FILE_CHANGE)
    {
        S32 i;

        for (i = 0; i < event_data->num_of_file; i++)
        {
            /* Channel change: FILE_CBMI_IDX, FILE_CBMID_IDX, FILE_CBMIR_IDX
             * Language chane: FILE_LP_IDX, FILE_ELP_IDX
             */
            if ((event_data->file_list[i] == FILE_CBMI_IDX) ||
                (event_data->file_list[i] == FILE_CBMID_IDX) ||
                (event_data->file_list[i] == FILE_CBMIR_IDX) ||
                (event_data->file_list[i] == FILE_LP_IDX) ||
                (event_data->file_list[i] == FILE_ELP_IDX))
            {
                srv_cbs_cntx_struct *cbs_cntx;
                srv_sms_sim_enum sim_id = (srv_sms_sim_enum)(event_data->sim_id | MMI_GSM);
                //U32 index;

                cbs_cntx = srv_cbs_get_cntx(sim_id);

                if (cbs_cntx->flag & SRV_CBS_FLAG_INIT_DONE)
                {
                    if (cbs_cntx->is_ready)
                    {
                        srv_cbs_ready_event_struct event_data;

                        cbs_cntx->is_ready = MMI_FALSE;

                        MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_READY_IND);
                        event_data.sim_id = sim_id;
                        event_data.is_ready = MMI_TRUE;
                        MMI_FRM_CB_EMIT_EVENT(&event_data);
                    }

                    if (cbs_cntx->flag & SRV_CBS_FLAG_REFRESH)
                    {
                        cbs_cntx->flag |= SRV_CBS_FLAG_REFRESH_REPEAT;
                    }
                    else
                    {
                        cbs_refresh_cntx_struct *refresh_cntx;

                        cbs_cntx->flag |= SRV_CBS_FLAG_REFRESH;

                        refresh_cntx = OslMalloc(sizeof(cbs_refresh_cntx_struct));

                        refresh_cntx->sim_id = sim_id;

                        srv_cbs_setting_init(
                            sim_id,
                            srv_cbs_refresh_setting_callback,
                            refresh_cntx);
                    }
                }
                else
                {
                    /* It is initializing, just need to set the SIM refresh flag */
                    cbs_cntx->flag |= SRV_CBS_FLAG_REFRESH;
                }

                break;
            }
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_gs_change_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_gs_change_hdlr(void *in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_cb_gs_change_ind_struct *change_ind = (mmi_sms_cb_gs_change_ind_struct*)in_msg;
    srv_cbs_gs_change_event_struct event_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GS_CHANGE_HDLR, change_ind->geography_type);

    if (change_ind->geography_type <= SRV_CBS_GS_MAX)
    {
        MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_GS_CHANGE_IND);
        event_data.sim_id = sim_id;

        if (change_ind->geography_type == SRV_CBS_GS_MAX)
        {
            event_data.change_type = SRV_CBS_GS_CELL;
        }
        else
        {
            event_data.change_type = (srv_cbs_gs_enum)change_ind->geography_type;
        }

        MMI_FRM_CB_EMIT_EVENT(&event_data);
    } 
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_new_msg_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_new_msg_hdlr(void* in_msg, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cb_msg_ind_struct *msg_ind = (mmi_cb_msg_ind_struct*)in_msg;
    srv_cbs_new_msg_event_struct event_data;
    U16 msg_id = SRV_CBS_INVALID_MSG_ID;
    U32 skip_char;
    srv_cbs_lang_enum lang_type;
    srv_sms_dcs_enum msg_dcs = SRV_SMS_DCS_7BIT;
    srv_sms_class_enum msg_class = SRV_SMS_CLASS_UNSPECIFIED;
    MMI_BOOL is_compress = MMI_FALSE;
    MMI_BOOL is_reserved = MMI_FALSE;
    srv_cbs_mode_enum mode;
    U8 *msg_content = msg_ind->msg_data;
    U32 msg_len = msg_ind->msg_length;
    U32 conten_len;
    WCHAR *content_buff;
    U32 real_out_len = 0;
    srv_cbs_cntx_struct *cbs_cntx;
    srv_cbs_msg_node_struct msg_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cbs_cntx = srv_cbs_get_cntx(sim_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_NEW_MSG_HDLR, sim_id, cbs_cntx->is_ready);

    if (cbs_cntx->is_ready == MMI_FALSE)
    {
        return;
    }

	if ((msg_ind->sn & 0xc000) == 0)
    {
		mode = SRV_CBS_MODE_IMMEDICATE;
    }
    else
    {
		mode = SRV_CBS_MODE_NORMAL;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_NEW_MSG_HDLR_1, mode);

    skip_char = srv_cbs_decode_dcs(
                    msg_ind->dcs,
                    msg_content,
                    msg_len,
                    &lang_type,
                    &msg_dcs,
                    &msg_class,
                    &is_compress,
                    &is_reserved);

    /* Need to handle compress and reserved type CBS Msg? */

    msg_content += skip_char;
    msg_len -= skip_char;

    msg_node.msg_dcs = msg_dcs;
    msg_node.lang_type = lang_type;
    msg_node.mode = mode;
    msg_node.mi = msg_ind->mi;
    msg_node.timestamp = srv_cbs_get_local_utc_sec();

    msg_id = srv_cbs_add_msg(&msg_node, msg_content, msg_len, sim_id);

    MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_NEW_MSG_IND);
    event_data.sim_id = sim_id;
    event_data.msg_id = msg_id;
    event_data.channel_id = msg_ind->mi;

    srv_cbs_get_channel_name(event_data.channel_name, msg_ind->mi, sim_id);

    event_data.lang_type = lang_type;
    event_data.msg_dcs = msg_dcs;
    event_data.msg_class = msg_class;
    event_data.mode = mode;
    event_data.orig_msg_len = msg_len;

    switch (msg_dcs)
    {
        case SRV_SMS_DCS_UCS2:
            conten_len = msg_len / ENCODING_LENGTH;
            break;

        case SRV_SMS_DCS_8BIT:
        case SRV_SMS_DCS_7BIT:
        default:
            conten_len = msg_len;
            break;
    }

    if (conten_len >= SRV_SMS_MAX_CHAR_NUM)
    {
        conten_len = SRV_SMS_MAX_CHAR_NUM - 1;
    }

    content_buff = OslMalloc((conten_len + 1) * ENCODING_LENGTH);

    srv_cbs_convert_content_for_display(
        content_buff,
        &real_out_len,
        conten_len,
        msg_content,
        msg_len,
        msg_dcs);

    content_buff[real_out_len] = '\0';

    event_data.content = content_buff;
    event_data.content_len = real_out_len;

    MMI_FRM_CB_EMIT_EVENT(&event_data);

    OslMfree(content_buff);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_init_storage_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_init_storage_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_init_cntx_struct *init_cntx;
    srv_cbs_cntx_struct *cbs_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    init_cntx = (srv_cbs_init_cntx_struct*)callback_data->user_data;

    cbs_cntx = srv_cbs_get_cntx(init_cntx->sim_id);

    cbs_cntx->flag |= SRV_CBS_FLAG_STORAGE_DONE;

    srv_cbs_init_done_hdlr(cbs_cntx, init_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_init_setting_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_init_setting_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_init_cntx_struct *init_cntx;
    srv_cbs_cntx_struct *cbs_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    init_cntx = (srv_cbs_init_cntx_struct*)callback_data->user_data;

    cbs_cntx = srv_cbs_get_cntx(init_cntx->sim_id);

    cbs_cntx->flag |= SRV_CBS_FLAG_SETTING_DONE;

    srv_cbs_init_done_hdlr(cbs_cntx, init_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_init_done_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cbs_init_done_hdlr(
                srv_cbs_cntx_struct *cbs_cntx,
                srv_cbs_init_cntx_struct *init_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cbs_cntx->flag & SRV_CBS_FLAG_REFRESH)
    {
        cbs_cntx->flag &= (~SRV_CBS_FLAG_REFRESH);

        srv_cbs_setting_init(
            init_cntx->sim_id,
            srv_cbs_init_setting_callback,
            init_cntx);
    }
    else
    {
        if ((cbs_cntx->flag & SRV_CBS_INIT_DONE) == SRV_CBS_INIT_DONE)
        {
            srv_cbs_ready_event_struct event_data;
            srv_sms_sim_enum sim_id = init_cntx->sim_id;

            OslMfree(init_cntx);

            cbs_cntx->is_ready = MMI_TRUE;
            cbs_cntx->flag |= SRV_CBS_FLAG_INIT_DONE;

            MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_READY_IND);
            event_data.sim_id = sim_id;
            event_data.is_ready = MMI_TRUE;
            MMI_FRM_CB_EMIT_EVENT(&event_data);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_refresh_setting_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_refresh_setting_callback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbs_refresh_cntx_struct *refresh_cntx;
    srv_cbs_cntx_struct *cbs_cntx;
    srv_sms_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    refresh_cntx = (cbs_refresh_cntx_struct*)callback_data->user_data;

    sim_id = refresh_cntx->sim_id;

    cbs_cntx = srv_cbs_get_cntx(sim_id);

    if (cbs_cntx->flag & SRV_CBS_FLAG_REFRESH_REPEAT)
    {
        cbs_cntx->flag &= (~SRV_CBS_FLAG_REFRESH_REPEAT);

        /* Initialize again with same context */
        srv_cbs_setting_init(
            sim_id,
            srv_cbs_refresh_setting_callback,
            refresh_cntx);
    }
    else
    {
        srv_cbs_ready_event_struct event_data;

        OslMfree(refresh_cntx);

        cbs_cntx->flag &= (~SRV_CBS_FLAG_REFRESH);
        cbs_cntx->is_ready = MMI_TRUE;

        MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_READY_IND);
        event_data.sim_id = sim_id;
        event_data.is_ready = MMI_TRUE;
        MMI_FRM_CB_EMIT_EVENT(&event_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_cbs_cntx_struct* srv_cbs_get_cntx(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_cntx_struct *cbs_cntx;
#ifdef __SRV_SMS_MULTI_SIM__
    U32 index;
#endif /* __SRV_SMS_MULTI_SIM__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_SIM__
    index = srv_sms_sim_id_to_sim_index(sim_id);

    cbs_cntx = &srv_cbs_cntx_array[index];
#else
    cbs_cntx = srv_cbs_cntx_array;
#endif /* __SRV_SMS_MULTI_SIM__ */

    return cbs_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_local_utc_sec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U32 srv_cbs_get_local_utc_sec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME local_time;
    U32 utc_sec;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DTGetRTCTime(&local_time);

    utc_sec = mmi_dt_mytime_2_utc_sec(&local_time, MMI_FALSE);

    return utc_sec;
}
#endif /* __MOD_SMSAL__ */
#endif /*__SRV_CBS_SUPPORT__*/
