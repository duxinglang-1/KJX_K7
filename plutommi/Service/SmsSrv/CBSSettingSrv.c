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
 *  CbsSettingSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CBS(Cell Broadcast Service) Service Setting Handler
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
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "Unicodexdcl.h"
#include "ps_public_struct.h"
#include "string.h"

#include "ps_public_enum.h"
#include "mmi_msg_struct.h"
#include "nvram_common_defs.h"
#include "ProtocolEvents.h"
#include "MMI_common_app_trc.h"
#include "SmsSrvGProt.h"
#include "CbsSrvGProt.h"
#include "CbsProtSrv.h"
#include "SmsUtilSrv.h"
#include "SmsDispatchSrv.h"


/**************************************************************
* MARCO
**************************************************************/
#define CBS_INVALID_MID_INDEX                        0xFF
#define CBS_INVALID_NAME_INDEX                       0xFF
#define CBS_INVALID_DCS_INDEX                        0xFF


/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    U16 mid;
    WCHAR name[SRV_CBS_CHNL_NAME_LEN + 1];
} cbs_chnl_name_entry_struct;

typedef struct
{
    MMI_BOOL mode;
    srv_sms_sim_enum sim_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} cbs_subscribe_struct;

typedef struct
{
    srv_sms_sim_enum sim_id;
    cbs_chnl_entry_struct entry;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} cbs_add_chnl_struct;

typedef struct
{
    U8 mid_index;
    U16 mid;
    srv_sms_sim_enum sim_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} cbs_del_chnl_struct;

typedef struct
{
    MMI_BOOL is_new_name;
    srv_sms_sim_enum sim_id;
    srv_cbs_chnl_entry_struct new_chnl;
    srv_cbs_chnl_entry_struct old_chnl;
    cbs_chnl_entry_struct new_entry;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} cbs_update_chnl_struct;

typedef struct
{
    srv_sms_sim_enum sim_id;
    cbs_lang_cntx_struct lang_cntx;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} cbs_select_lang_struct;

typedef struct
{
    srv_sms_sim_enum sim_id;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} setting_init_cntx_struct;


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/


/**************************************************************
* Static Function Declaration
**************************************************************/
static void srv_cbs_subscribe_callback(srv_sms_disp_cb_struct* callback_data);
static void srv_cbs_ps_data_to_chnl_info(
                cbs_chnl_cntx_struct *chnl_cntx,
                mmi_sms_get_cb_mode_rsp_struct *cb_mode_data,
                srv_sms_sim_enum sim_id);
static void srv_cbs_chnl_info_to_ps_data(
                mmi_sms_set_cb_mode_req_struct *set_mode_data,
                cbs_chnl_cntx_struct *chnl_cntx);
static void srv_cbs_ps_data_to_lang_info(
                cbs_lang_cntx_struct *lang_cntx,
                mmi_sms_get_cb_mode_rsp_struct *cb_mode_data,
                srv_sms_sim_enum sim_id);
static void srv_cbs_lang_info_to_ps_data(
                mmi_sms_set_cb_mode_req_struct *set_mode_data,
                cbs_lang_cntx_struct *lang_cntx);

static srv_cbs_lang_enum srv_cbs_dcs_to_lang_type(U16 lang_dcs);
static U8 srv_cbs_get_unused_mid_index(cbs_chnl_cntx_struct* chnl_cntx);
static U8 srv_cbs_get_unused_name_index(cbs_chnl_cntx_struct* chnl_cntx);
static cbs_chnl_entry_struct* srv_cbs_get_chnl_entry(U16 mid, cbs_chnl_cntx_struct* chnl_cntx);
static U8 srv_cbs_get_chnl_mid_index(U16 mid, cbs_chnl_cntx_struct* chnl_cntx);
//static U8 srv_cbs_get_chnl_name_index(U16 mid, cbs_chnl_cntx_struct* chnl_cntx);
static MMI_BOOL srv_cbs_is_chnl_exist(U16 mid, cbs_chnl_cntx_struct* chnl_cntx);

static void srv_cbs_read_multi_chnl_record(
                cbs_chnl_name_entry_struct *chnl_name_buff,
                U16 index,
                U16 amount,
                srv_sms_sim_enum sim_id);
static void srv_cbs_write_chnl_name_record(
                U16 chnl_id,
                WCHAR* name_buff,
                U16 index,
                srv_sms_sim_enum sim_id);
static void srv_cbs_del_chnl_name_record(U16 index, srv_sms_sim_enum sim_id);

static void srv_cbs_add_chnl_entry(
                cbs_chnl_entry_struct* entry,
                cbs_chnl_cntx_struct *chnl_cntx,
                srv_sms_sim_enum sim_id);
static void srv_cbs_del_chnl_entry(
                U16 mid,
                cbs_chnl_cntx_struct *chnl_cntx,
                srv_sms_sim_enum sim_id);
static void srv_cbs_update_chnl_entry(
                U16 mid,
                cbs_chnl_entry_struct* entry,
                cbs_chnl_cntx_struct *chnl_cntx,
                srv_sms_sim_enum sim_id);

static void srv_cbs_add_chnl_callback(srv_sms_disp_cb_struct* callback_data);
static void srv_cbs_del_chnl_callback(srv_sms_disp_cb_struct* callback_data);
static void srv_cbs_update_chnl_callback(srv_sms_disp_cb_struct* callback_data);
static void srv_cbs_select_lang_callback(srv_sms_disp_cb_struct* callback_data);

static void srv_cbs_setting_init_callback(srv_sms_disp_cb_struct* callback_data);

static void srv_cbs_disp_subscribe(
                mmi_cb_subscribe_req_struct *req_data,
                srv_sms_sim_enum sim_id,
                SrvSmsDispCallbackFunc callback_func,
                void* user_data);
static void srv_cbs_disp_get_cb_mode(
                srv_sms_sim_enum sim_id,
                SrvSmsDispCallbackFunc callback_func,
                void* user_data);
static void srv_cbs_disp_set_cb_mode(
                mmi_sms_set_cb_mode_req_struct *req_data,
                srv_sms_sim_enum sim_id,
                SrvSmsDispCallbackFunc callback_func,
                void* user_data);

static void srv_cbs_set_chnl_flag(
                cbs_chnl_flag_enum flag,
                U32 index,
                MMI_BOOL is_set,
                cbs_chnl_cntx_struct* chnl_cntx);
static MMI_BOOL srv_cbs_get_chnl_flag(
                    cbs_chnl_flag_enum flag,
                    U32 index,
                    cbs_chnl_cntx_struct* chnl_cntx);


/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_receive_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_cbs_get_receive_mode(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL mode;
    srv_cbs_cntx_struct *cbs_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_RECEIVE_MODE, sim_id);

    cbs_cntx = srv_cbs_get_cntx(sim_id);

    if (cbs_cntx->is_ready)
    {
        mode = (MMI_BOOL)cbs_cntx->mode;
    }
    else
    {
        mode = MMI_FALSE;
    }

    return mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_subscribe
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_cbs_subscribe(
        MMI_BOOL is_subsrcibe,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbs_subscribe_struct *subscribe_cntx;
    mmi_cb_subscribe_req_struct *req_data;
    srv_cbs_cntx_struct *cbs_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_SUBSCRIBE, is_subsrcibe, sim_id);

    cbs_cntx = srv_cbs_get_cntx(sim_id);

    if (cbs_cntx->is_ready)
    {
        subscribe_cntx = OslMalloc(sizeof(cbs_subscribe_struct));

        subscribe_cntx->mode = is_subsrcibe;
        subscribe_cntx->sim_id = sim_id;
        subscribe_cntx->callback_func = callback_func;
        subscribe_cntx->user_data = user_data;

        req_data = (mmi_cb_subscribe_req_struct*)OslConstructDataPtr(sizeof(mmi_cb_subscribe_req_struct));

        req_data->on_off = is_subsrcibe;

        srv_cbs_disp_subscribe(
            req_data,
            sim_id,
            srv_cbs_subscribe_callback,
            subscribe_cntx);
    }
    else
    {
        srv_sms_callback(
            SRV_SMS_ACTION_CB_SELECT_LANG,
            MMI_FALSE,
            SRV_SMS_CAUSE_CB_NOT_READY,
            NULL,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_cbs_get_channel(
            srv_cbs_channel_struct *chnl_data,
            srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    srv_cbs_cntx_struct *cbs_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_CHANNEL, sim_id);

    cbs_cntx = srv_cbs_get_cntx(sim_id);

    if (cbs_cntx->is_ready)
    {
        cbs_chnl_cntx_struct *chnl_cntx = &cbs_cntx->chnl_cntx;
        srv_cbs_chnl_entry_struct *entry;
        U32 i;

        chnl_data->max_entry = chnl_cntx->max_entry;
        chnl_data->total = chnl_cntx->total;

        entry = chnl_data->entry;

        for (i = 0; i < chnl_cntx->total; i++)
        {
            entry[i].id = chnl_cntx->entry[i].mid;
            entry[i].mask = chnl_cntx->entry[i].mask;
            mmi_wcscpy(entry[i].name, chnl_cntx->entry[i].name);
        }
    }
    else
    {
        chnl_data->total = 0;
        result = MMI_FALSE;
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_channel_single_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_cbs_get_channel_single_entry(
            srv_cbs_chnl_entry_struct *chnl_data,
            U16 chnl_id,
            srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_BOOL result = MMI_TRUE;
    srv_cbs_cntx_struct *cbs_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_CHANNEL, sim_id);

    cbs_cntx = srv_cbs_get_cntx(sim_id);

    if (cbs_cntx->is_ready)
    {
        cbs_chnl_cntx_struct *chnl_cntx = &cbs_cntx->chnl_cntx;
        //srv_cbs_chnl_entry_struct *entry;
        U32 i;

        for (i = 0; i < chnl_cntx->total; i++)
        {
            if (chnl_cntx->entry[i].mid == chnl_id)
            {
                chnl_data->mask = chnl_cntx->entry[i].mask;
                chnl_data->id = chnl_cntx->entry[i].mid;

                mmi_wcscpy(chnl_data->name, chnl_cntx->entry[i].name);
                return MMI_TRUE;
            };
        }
    }
    return MMI_FALSE;

}

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_add_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_cbs_add_channel(
        srv_cbs_chnl_entry_struct* chnl_entry,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_cntx_struct *cbs_cntx;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_ADD_CHANNEL, sim_id);

    cbs_cntx = srv_cbs_get_cntx(sim_id);

    do
    {
        cbs_chnl_cntx_struct *chnl_cntx;
        U8 mid_index;
        U8 name_index;
        mmi_sms_set_cb_mode_req_struct* set_cb_data;
        cbs_add_chnl_struct *add_chnl_cntx;

        if (!cbs_cntx->is_ready)
        {
            error_cause = SRV_SMS_CAUSE_CB_NOT_READY;
            break;
        }

        chnl_cntx = &cbs_cntx->chnl_cntx;

        if (srv_cbs_is_chnl_exist(chnl_entry->id, chnl_cntx))
        {
            error_cause = SRV_SMS_CAUSE_CB_CHNL_DUPLICATED;
            break;
        }

        mid_index = srv_cbs_get_unused_mid_index(chnl_cntx);
        name_index = srv_cbs_get_unused_name_index(chnl_cntx);

        if ((mid_index == CBS_INVALID_MID_INDEX) ||
            (name_index == CBS_INVALID_NAME_INDEX))
        {
            error_cause = SRV_SMS_CAUSE_CB_CHNL_FULL;
            break;
        }

        /* Set the Name Index / MID index as Use first;
         * set this MID index as in operating status */
        srv_cbs_set_chnl_flag(CHNL_FLAG_NAME_USED, name_index, MMI_TRUE, chnl_cntx);
        srv_cbs_set_chnl_flag(CHNL_FLAG_MID_USED, mid_index, MMI_TRUE, chnl_cntx);

        add_chnl_cntx = OslMalloc(sizeof(cbs_add_chnl_struct));

        add_chnl_cntx->entry.mid = chnl_entry->id;
        add_chnl_cntx->entry.mask = chnl_entry->mask;
        mmi_wcscpy(add_chnl_cntx->entry.name, chnl_entry->name);
        add_chnl_cntx->entry.mid_index = mid_index;
        add_chnl_cntx->entry.name_index = name_index;

        add_chnl_cntx->sim_id = sim_id;
        add_chnl_cntx->callback_func = callback_func;
        add_chnl_cntx->user_data = user_data;

        set_cb_data = (mmi_sms_set_cb_mode_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_set_cb_mode_req_struct));

        srv_cbs_chnl_info_to_ps_data(set_cb_data, chnl_cntx);

        set_cb_data->info.para_ind = SMSAL_CB_MI | SMSAL_CB_MI_MASK;

        set_cb_data->info.mid[mid_index] = chnl_entry->id;
        set_cb_data->info.mid_mask[mid_index] = chnl_entry->mask;

        srv_cbs_disp_set_cb_mode(
            set_cb_data,
            sim_id,
            srv_cbs_add_chnl_callback,
            add_chnl_cntx);
    } while (0);

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_callback(
            SRV_SMS_ACTION_CB_ADD_CHNL,
            MMI_FALSE,
            error_cause,
            NULL,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_delete_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_cbs_delete_channel(
        U16 channel_id,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_cntx_struct *cbs_cntx;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DELETE_CHANNEL, sim_id);

    cbs_cntx = srv_cbs_get_cntx(sim_id);

    do
    {
        cbs_chnl_cntx_struct *chnl_cntx;
        U8 mid_index;
        MMI_BOOL is_operating;
        mmi_sms_set_cb_mode_req_struct* set_cb_data;
        cbs_del_chnl_struct *del_chnl_cntx;

        if (!cbs_cntx->is_ready)
        {
            error_cause = SRV_SMS_CAUSE_CB_NOT_READY;
           break;
        }

        chnl_cntx = &cbs_cntx->chnl_cntx;
        mid_index = srv_cbs_get_chnl_mid_index(channel_id, chnl_cntx);

        if (mid_index == CBS_INVALID_MID_INDEX)
        {
            error_cause = SRV_SMS_CAUSE_CB_CHNL_NOT_EXISTED;
            break;
        }

        is_operating = srv_cbs_get_chnl_flag(
                            CHNL_FLAG_MID_OPERATING,
                            mid_index,
                            chnl_cntx);

        if (is_operating)
        {
            error_cause = SRV_SMS_CAUSE_OP_CONFLICT;
            break;
        }

        /* Set this MID as in operating state */
        srv_cbs_set_chnl_flag(
            CHNL_FLAG_MID_OPERATING,
            mid_index,
            MMI_TRUE,
            chnl_cntx);

        del_chnl_cntx = OslMalloc(sizeof(cbs_del_chnl_struct));

        del_chnl_cntx->mid_index = mid_index;
        del_chnl_cntx->mid = channel_id;
        del_chnl_cntx->sim_id = sim_id;
        del_chnl_cntx->callback_func = callback_func;
        del_chnl_cntx->user_data = user_data;

        set_cb_data = (mmi_sms_set_cb_mode_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_set_cb_mode_req_struct));

        srv_cbs_chnl_info_to_ps_data(set_cb_data, chnl_cntx);

        set_cb_data->info.para_ind = SMSAL_CB_MI | SMSAL_CB_MI_MASK;

        set_cb_data->info.mid[mid_index] = SRV_CBS_UNUSED_CBMI;
        set_cb_data->info.mid_mask[mid_index] = MMI_FALSE;

        srv_cbs_disp_set_cb_mode(
            set_cb_data,
            sim_id,
            srv_cbs_del_chnl_callback,
            del_chnl_cntx);
    } while (0);

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_callback(
            SRV_SMS_ACTION_CB_DELETE_CHNL,
            MMI_FALSE,
            error_cause,
            NULL,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_update_channel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_cbs_update_channel(
        srv_cbs_chnl_entry_struct* new_chnl,
        srv_cbs_chnl_entry_struct* old_chnl,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_cntx_struct *cbs_cntx;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_UPDATE_CHANNEL, sim_id);

    cbs_cntx = srv_cbs_get_cntx(sim_id);

    do
    {
        cbs_chnl_cntx_struct *chnl_cntx;
        cbs_chnl_entry_struct *old_entry;
        MMI_BOOL is_operating;
        U8 name_index;
        U8 mid_index;
        MMI_BOOL is_new_name = MMI_FALSE;

        if (!cbs_cntx->is_ready)
        {
            error_cause = SRV_SMS_CAUSE_CB_NOT_READY;
            break;
        }

        chnl_cntx = &cbs_cntx->chnl_cntx;
        old_entry = srv_cbs_get_chnl_entry(old_chnl->id, chnl_cntx);

        if (old_entry == NULL)
        {
            error_cause = SRV_SMS_CAUSE_CB_CHNL_NOT_EXISTED;
            break;
        }

        mid_index = old_entry->mid_index;
        is_operating = srv_cbs_get_chnl_flag(
                            CHNL_FLAG_MID_OPERATING,
                            mid_index,
                            chnl_cntx);

        if (is_operating)
        {
            error_cause = SRV_SMS_CAUSE_OP_CONFLICT;
            break;
        }

        if ((old_chnl->id != new_chnl->id) && srv_cbs_is_chnl_exist(new_chnl->id, chnl_cntx))
        {
            error_cause = SRV_SMS_CAUSE_CB_CHNL_DUPLICATED;
            break;
        }

        name_index = old_entry->name_index;

        if (name_index == CBS_INVALID_NAME_INDEX)
        {
            name_index = srv_cbs_get_unused_name_index(chnl_cntx);
            is_new_name = MMI_TRUE;
        }

        if (name_index == CBS_INVALID_NAME_INDEX)
        {
            /* This case shouldn't be happened. */
            error_cause = SRV_SMS_CAUSE_CB_CHNL_FULL;
            break;
        }

        if (is_new_name)
        {
            srv_cbs_set_chnl_flag(CHNL_FLAG_NAME_USED, name_index, MMI_TRUE, chnl_cntx);
        }

        if ((old_chnl->id != new_chnl->id) || (old_chnl->mask != new_chnl->mask))
        {
            mmi_sms_set_cb_mode_req_struct* set_cb_data;
            cbs_update_chnl_struct *update_chnl_cntx;
            cbs_chnl_entry_struct *new_entry;

            srv_cbs_set_chnl_flag(CHNL_FLAG_MID_OPERATING, mid_index, MMI_TRUE, chnl_cntx);

            update_chnl_cntx = OslMalloc(sizeof(cbs_update_chnl_struct));
            new_entry = &update_chnl_cntx->new_entry;

            memcpy(&update_chnl_cntx->new_chnl, new_chnl, sizeof(srv_cbs_chnl_entry_struct));
            memcpy(&update_chnl_cntx->old_chnl, old_chnl, sizeof(srv_cbs_chnl_entry_struct));

            mmi_wcscpy(new_entry->name, new_chnl->name);
            new_entry->mid = new_chnl->id;
            new_entry->mask = new_chnl->mask;
            new_entry->mid_index = mid_index;
            new_entry->name_index = name_index;

            update_chnl_cntx->is_new_name = is_new_name;
            update_chnl_cntx->sim_id = sim_id;
            update_chnl_cntx->callback_func = callback_func;
            update_chnl_cntx->user_data = user_data;

            set_cb_data = (mmi_sms_set_cb_mode_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_set_cb_mode_req_struct));

            srv_cbs_chnl_info_to_ps_data(set_cb_data, chnl_cntx);

            set_cb_data->info.para_ind = 0;

            if (old_chnl->id != new_chnl->id)
            {
                set_cb_data->info.para_ind |= SMSAL_CB_MI;
                set_cb_data->info.mid[mid_index] = new_chnl->id;
            }

            if (old_chnl->mask != new_chnl->mask)
            {
                set_cb_data->info.para_ind |= SMSAL_CB_MI_MASK;
                set_cb_data->info.mid_mask[mid_index] = new_chnl->mask;
            }

            srv_cbs_disp_set_cb_mode(
                set_cb_data,
                sim_id,
                srv_cbs_update_chnl_callback,
                update_chnl_cntx);
        }
        else
        {
            srv_cbs_update_chnl_event_struct event_data;

            srv_cbs_write_chnl_name_record(
                new_chnl->id,
                new_chnl->name,
                name_index,
                sim_id);

            old_entry->name_index = name_index;
            mmi_wcscpy(old_entry->name, new_chnl->name);

            MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_UPDATE_CHNL);
            event_data.sim_id = sim_id;
            memcpy(&event_data.new_chnl, new_chnl, sizeof(srv_cbs_chnl_entry_struct));
            memcpy(&event_data.old_chnl, old_chnl, sizeof(srv_cbs_chnl_entry_struct));

            srv_sms_callback(
                SRV_SMS_ACTION_CB_UPDATE_CHNL,
                MMI_TRUE,
                SRV_SMS_CAUSE_NO_ERROR,
                NULL,
                user_data,
                callback_func);

            MMI_FRM_CB_EMIT_EVENT(&event_data);
        }
    } while (0);

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_callback(
            SRV_SMS_ACTION_CB_UPDATE_CHNL,
            MMI_FALSE,
            error_cause,
            NULL,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_language
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_cbs_get_language(
            srv_cbs_language_struct *lang_data,
            srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    srv_cbs_cntx_struct *cbs_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cbs_cntx = srv_cbs_get_cntx(sim_id);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_LANGUAGE, sim_id, cbs_cntx->is_ready);

    if (cbs_cntx->is_ready)
    {
        cbs_lang_cntx_struct *lang_cntx = &cbs_cntx->lang_cntx;
        srv_cbs_lang_entry_struct *entry;
        U32 i;

        lang_data->is_all_on = lang_cntx->is_all_on;
        lang_data->total = lang_cntx->total;
        lang_data->is_all_on = lang_cntx->is_all_on;

        entry = lang_data->entry;

        for (i = 0; i < lang_cntx->total; i++)
        {
            entry[i].lang_type = lang_cntx->entry[i].type;
            entry[i].mask = lang_cntx->entry[i].mask;
        }
    }
    else
    {
        lang_data->total = 0;
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_select_language
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_cbs_select_language(
        srv_cbs_language_struct *lang_data,
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_cntx_struct *cbs_cntx;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_SELECT_LANGUAGE, sim_id);

    cbs_cntx = srv_cbs_get_cntx(sim_id);

    if (cbs_cntx->is_ready)
    {
        U32 i;
        cbs_lang_cntx_struct *lang_cntx;
        cbs_select_lang_struct *sel_lang_cntx;

        sel_lang_cntx = OslMalloc(sizeof(cbs_select_lang_struct));
        lang_cntx = &sel_lang_cntx->lang_cntx;

        memcpy(lang_cntx, &cbs_cntx->lang_cntx, sizeof(cbs_lang_cntx_struct));

        for (i = 0; i < (U32)lang_data->total; i++)
        {
            srv_cbs_lang_entry_struct *sel_entry = &lang_data->entry[i];
            MMI_BOOL is_find = MMI_FALSE;
            U32 j;

            for (j = 0; j < (U32)lang_cntx->total; j++)
            {
                cbs_lang_entry_struct *entry = &lang_cntx->entry[j];

                if (entry->type == sel_entry->lang_type)
                {
                    entry->mask = sel_entry->mask;
                    is_find = MMI_TRUE;
                    break;
                }
            }

            if (!is_find)
            {
                error_cause = SRV_SMS_CAUSE_CB_LANG_NOT_EXISTED;
                break;
            }
        }

        if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
            MMI_BOOL is_all_on = MMI_TRUE;

            for (i = 0; i < (U32)lang_cntx->total; i++)
            {
                if (lang_cntx->entry[i].mask == MMI_FALSE)
                {
                    is_all_on = MMI_FALSE;
                }
            }

            if (lang_data->is_all_on && (!is_all_on))
            {
                error_cause = SRV_SMS_CAUSE_DATA_INVALID;
            }
            else
            {
                lang_cntx->is_all_on = lang_data->is_all_on;
            }
        }

        if (error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
            mmi_sms_set_cb_mode_req_struct* set_cb_data;

            sel_lang_cntx->sim_id = sim_id;
            sel_lang_cntx->callback_func = callback_func;
            sel_lang_cntx->user_data = user_data;

            set_cb_data = (mmi_sms_set_cb_mode_req_struct*)OslConstructDataPtr(sizeof(mmi_sms_set_cb_mode_req_struct));

            srv_cbs_lang_info_to_ps_data(set_cb_data, lang_cntx);

            srv_cbs_disp_set_cb_mode(
                set_cb_data,
                sim_id,
                srv_cbs_select_lang_callback,
                sel_lang_cntx);
        }
        else
        {
            OslMfree(sel_lang_cntx);
        }
    }
    else
    {
        error_cause = SRV_SMS_CAUSE_CB_NOT_READY;
    }

    if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_sms_callback(
            SRV_SMS_ACTION_CB_SELECT_LANG,
            MMI_FALSE,
            error_cause,
            NULL,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_subscribe_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_subscribe_callback(srv_sms_disp_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_subscribe_cb_struct subscribe_cb_data;
    srv_cbs_mode_change_event_struct event_data;
    cbs_subscribe_struct *subscribe_cntx;
    mmi_sms_get_cb_mode_rsp_struct *rsp_data;
    SrvSmsCallbackFunc callback_func;
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_data = (mmi_sms_get_cb_mode_rsp_struct*)callback_data->data;
    subscribe_cntx = (cbs_subscribe_struct*)callback_data->user_data;

    callback_func = subscribe_cntx->callback_func;
    user_data = subscribe_cntx->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_SUBSCRIBE_CALLBACK, rsp_data->result);

    if (rsp_data->result)
    {
        srv_cbs_cntx_struct *cbs_cntx;

        cbs_cntx = srv_cbs_get_cntx(subscribe_cntx->sim_id);

        cbs_cntx->mode = subscribe_cntx->mode;

        MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_MODE_CHANGE);
        event_data.sim_id = subscribe_cntx->sim_id;
        event_data.mode = subscribe_cntx->mode;

        OslMfree(subscribe_cntx);

        srv_sms_callback(
            SRV_SMS_ACTION_CB_SUBSCRIBE,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            &subscribe_cb_data,
            user_data,
            callback_func);

        MMI_FRM_CB_EMIT_EVENT(&event_data);
    }
    else
    {
        OslMfree(subscribe_cntx);

        srv_sms_callback(
            SRV_SMS_ACTION_CB_SUBSCRIBE,
            MMI_FALSE,
            SRV_SMS_CAUSE_UNKNOWN_ERROR,
            &subscribe_cb_data,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_ps_data_to_chnl_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_ps_data_to_chnl_info(
                cbs_chnl_cntx_struct *chnl_cntx,
                mmi_sms_get_cb_mode_rsp_struct *cb_mode_data,
                srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 total = 0;
    U32 total_mid_num = cb_mode_data->total_mid_num;
    cbs_chnl_name_entry_struct *chnl_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_PS_DATA_TO_CHNL_INFO, total_mid_num);

    /* Reset the channel context because the sim refresh case will run this scenario */
    memset(chnl_cntx, 0, sizeof(cbs_chnl_cntx_struct));

    chnl_name = OslMalloc(sizeof(cbs_chnl_name_entry_struct) * SRV_CBS_MAX_CHNL_NUM);

    srv_cbs_read_multi_chnl_record(chnl_name, 0, SRV_CBS_MAX_CHNL_NUM, sim_id);

    if (total_mid_num > SRV_CBS_MAX_CHNL_NUM)
    {
        total_mid_num = SRV_CBS_MAX_CHNL_NUM;
    }

    for (i = 0; i < total_mid_num; i++)
    {
        U16 curr_mid = cb_mode_data->info.mid[i];

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_PS_DATA_TO_CHNL_INFO_1, curr_mid);

        if (curr_mid != SRV_CBS_UNUSED_CBMI)
        {
            U32 j;
            MMI_BOOL is_duplicated = MMI_FALSE;

            /* The channel is ordered by Channel ID
                 Using Insert Sorting */
            for (j = 0; j < total; j++)
            {
                U16 tmp_id = chnl_cntx->entry[j].mid;

                if (tmp_id >= curr_mid)
                {
                    if (tmp_id == curr_mid)
                    {
                        is_duplicated = MMI_TRUE;
                    }
                    break;
                }
            }

            /* Skip the duplicated channel */
            if (is_duplicated == MMI_FALSE)
            {
                U32 k;
                U8 name_index;
                cbs_chnl_entry_struct *new_entry;
    
                for (k = total; k > j; k--)
                {
                    memcpy(&chnl_cntx->entry[k], &chnl_cntx->entry[k - 1], sizeof(cbs_chnl_entry_struct));
                }

                for (name_index = 0; name_index < SRV_CBS_MAX_CHNL_NUM; name_index++)
                {
                    if (curr_mid == chnl_name[name_index].mid)
                    {
                        break;
                    }
                }

                new_entry = &chnl_cntx->entry[j];

                new_entry->mid = curr_mid;
                new_entry->mask = (MMI_BOOL)cb_mode_data->info.mid_mask[i];
                new_entry->mid_index = i;

                /* Set this Channle MID index as Used */
                srv_cbs_set_chnl_flag(CHNL_FLAG_MID_USED, i, MMI_TRUE, chnl_cntx);

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_PS_DATA_TO_CHNL_INFO_2, name_index);

                if (name_index == SRV_CBS_MAX_CHNL_NUM)
                {
                    new_entry->name[0] = '\0';
                    new_entry->name_index = CBS_INVALID_NAME_INDEX;
                }
                else
                {
                    mmi_wcsncpy(
                        new_entry->name,
                        chnl_name[name_index].name,
                        SRV_CBS_CHNL_NAME_LEN);
                    new_entry->name[SRV_CBS_CHNL_NAME_LEN] = '\0';
                    new_entry->name_index = name_index;

                    /* Set this Channle Name index as Used */
                    srv_cbs_set_chnl_flag(CHNL_FLAG_NAME_USED, name_index, MMI_TRUE, chnl_cntx);
                }

                total++;
            }
        }
    }

    chnl_cntx->max_entry = (U8)total_mid_num;
    chnl_cntx->total = (U8)total;

    for (i = 0; i < SRV_CBS_MAX_CHNL_NUM; i++)
    {
        MMI_BOOL is_used;

        is_used = srv_cbs_get_chnl_flag(CHNL_FLAG_NAME_USED, i, chnl_cntx);
    
        if ((!is_used) && (chnl_name[i].mid != SRV_CBS_UNUSED_CBMI))
        {
            srv_cbs_del_chnl_name_record((U16)i, sim_id);
        }
    }

    OslMfree(chnl_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_chnl_info_to_ps_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_chnl_info_to_ps_data(
                mmi_sms_set_cb_mode_req_struct *set_mode_data,
                cbs_chnl_cntx_struct *chnl_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_CHNL_INFO_TO_PS_DATA, chnl_cntx->total);

    set_mode_data->info.para_ind = SMSAL_CB_DCS_MASK | SMSAL_CB_ALL_LANG;

    for (i = 0; i < SRV_CBS_MAX_CHNL_NUM; i++)
    {
        set_mode_data->info.mid[i] = SRV_CBS_UNUSED_CBMI;
        set_mode_data->info.mid_mask[i] = MMI_TRUE;
    }

    for (i = 0; i < (U32)chnl_cntx->total; i++)
    {
        cbs_chnl_entry_struct *entry = &chnl_cntx->entry[i];
        U32 index = entry->mid_index;
    
        set_mode_data->info.mid[index] = entry->mid;
        set_mode_data->info.mid_mask[index] = entry->mask;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_ps_data_to_lang_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_ps_data_to_lang_info(
                cbs_lang_cntx_struct *lang_cntx,
                mmi_sms_get_cb_mode_rsp_struct *cb_mode_data,
                srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 total = 0;
    U8 total_dcs_num = cb_mode_data->total_dcs_num;
    cbs_lang_entry_struct *entry = lang_cntx->entry;
    MMI_BOOL is_all_on = cb_mode_data->info.is_all_language_on;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_PS_DATA_TO_LANG_INFO, total_dcs_num);

    if (total_dcs_num > SRV_CBS_MAX_LANG_NUM)
    {
        total_dcs_num = SRV_CBS_MAX_LANG_NUM;
    }

    for (i = 0; i <total_dcs_num; i++)
    {
        srv_cbs_lang_enum lang_type;
        U16 dcs = cb_mode_data->info.dcs[i];

        lang_type = srv_cbs_dcs_to_lang_type(dcs);

        if (lang_type != SRV_CBS_LANG_INVALID)
        {
            U32 j;
            MMI_BOOL is_duplicated = MMI_FALSE;

            for (j = 0; j < total; j++)
            {
                if (entry[j].type == lang_type)
                {
                    is_duplicated = MMI_TRUE;
                    break;
                }
            }

            if (!is_duplicated)
            {
                entry[i].dcs = dcs;
                entry[i].type = lang_type;
                entry[i].mask = (MMI_BOOL)cb_mode_data->info.dcs_mask[i];
                entry[i].dcs_index = i;

                total++;
            }
        }
    }

    if (is_all_on)
    {
        for (i = 0; i < total; i++)
        {
            if (entry[i].mask == MMI_FALSE)
            {
                is_all_on = MMI_FALSE;
            }
        }
    }

    lang_cntx->total = total;
    lang_cntx->is_all_on = is_all_on;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_lang_info_to_ps_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_lang_info_to_ps_data(
                mmi_sms_set_cb_mode_req_struct *set_mode_data,
                cbs_lang_cntx_struct *lang_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_LANG_INFO_TO_PS_DATA, lang_cntx->total);

    set_mode_data->info.is_all_language_on = lang_cntx->is_all_on;
    set_mode_data->info.para_ind = SMSAL_CB_DCS | SMSAL_CB_DCS_MASK | SMSAL_CB_ALL_LANG;

    for (i = 0; i < SRV_CBS_MAX_LANG_NUM; i++)
    {
        set_mode_data->info.dcs[i] = SRV_CBS_UNUSED_CBMI;
        set_mode_data->info.dcs_mask[i] = MMI_TRUE;
    }

    for (i = 0; i < (U32)lang_cntx->total; i++)
    {
        cbs_lang_entry_struct *entry = &lang_cntx->entry[i];
        U32 index = entry->dcs_index;
    
        set_mode_data->info.dcs[index] = entry->dcs;
        set_mode_data->info.dcs_mask[index] = entry->mask;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_dcs_to_lang_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_cbs_lang_enum srv_cbs_dcs_to_lang_type(U16 lang_dcs)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_lang_enum lang_type = SRV_CBS_LANG_INVALID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DCS_TO_LANG_TYPE, lang_dcs);

    if (lang_dcs != SRV_CBS_UNUSED_DCS)
    {
        U8 first_byte;
        U8 second_byte;

        first_byte = (lang_dcs & 0xff00) >> 8;
        second_byte = (lang_dcs & 0x00ff);

        if (first_byte == 0x00)
        {
            U8 msg_content[3];
            srv_sms_class_enum msg_class;
            srv_sms_dcs_enum msg_dcs;
            MMI_BOOL is_compress;
            MMI_BOOL is_reserved;

            srv_cbs_decode_dcs(
                second_byte,
                msg_content,
                0,
                &lang_type,
                &msg_dcs,
                &msg_class,
                &is_compress,
                &is_reserved);

            if (lang_type != SRV_CBS_LANG_0_UNSPECIFIED)
            {
                lang_type = SRV_CBS_LANG_INVALID;
            }
        }
        else
        {
            lang_type = srv_cbs_decode_lang(first_byte, second_byte);
        }
    }

    return lang_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_unused_mid_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_cbs_get_unused_mid_index(cbs_chnl_cntx_struct* chnl_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 unused_index = CBS_INVALID_MID_INDEX;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(chnl_cntx->max_entry <= SRV_CBS_MAX_CHNL_NUM);

    for (i = 0; i < (U32)chnl_cntx->max_entry; i++)
    {
        MMI_BOOL is_used;

        is_used = srv_cbs_get_chnl_flag(CHNL_FLAG_MID_USED, i, chnl_cntx);
    
        if (!is_used)
        {
            unused_index = i;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_UNUSED_MID_INDEX, unused_index);

    return unused_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_unused_name_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_cbs_get_unused_name_index(cbs_chnl_cntx_struct* chnl_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 unused_index = CBS_INVALID_NAME_INDEX;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CBS_MAX_CHNL_NUM; i++)
    {
        MMI_BOOL is_used;

        is_used = srv_cbs_get_chnl_flag(CHNL_FLAG_NAME_USED, i, chnl_cntx);
    
        if (!is_used)
        {
            unused_index = i;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_UNUSED_CHNL_NAME_INDEX, unused_index);

    return unused_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_chnl_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static cbs_chnl_entry_struct* srv_cbs_get_chnl_entry(U16 mid, cbs_chnl_cntx_struct* chnl_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbs_chnl_entry_struct *entry = NULL;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_CHNL_ENTRY, mid);

    for (i = 0; i < (U32)chnl_cntx->total; i++)
    {
        cbs_chnl_entry_struct *tmp_entry = &chnl_cntx->entry[i];

        if (tmp_entry->mid == mid)
        {
            entry = tmp_entry;
            break;
        }
    }

    return entry;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_chnl_mid_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U8 srv_cbs_get_chnl_mid_index(U16 mid, cbs_chnl_cntx_struct* chnl_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index = CBS_INVALID_MID_INDEX;
    cbs_chnl_entry_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry = srv_cbs_get_chnl_entry(mid, chnl_cntx);

    if (entry == NULL)
    {
        index = CBS_INVALID_MID_INDEX;
    }
    else
    {
        index = entry->mid_index;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_CHNL_MID_INDEX, index);

    return index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_chnl_name_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
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
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_cbs_is_chnl_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_cbs_is_chnl_exist(U16 mid, cbs_chnl_cntx_struct* chnl_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;
    cbs_chnl_entry_struct *entry = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_IS_CHNL_EXIST, mid);

    entry = srv_cbs_get_chnl_entry(mid, chnl_cntx);

    if (entry == NULL)
    {
        result = MMI_FALSE;
    }
    else
    {
        result = MMI_TRUE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_channel_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_cbs_get_channel_name(
        WCHAR channel_name[],
        U16 channel_id,
        srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cbs_cntx_struct *cbs_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_GET_CHANNEL_NAME, channel_id, sim_id);

    channel_name[0] = '\0';

    cbs_cntx = srv_cbs_get_cntx(sim_id);

    if (cbs_cntx->is_ready)
    {
        U32 i;
        cbs_chnl_cntx_struct *chnl_cntx = &cbs_cntx->chnl_cntx;

        for (i = 0; i < chnl_cntx->total; i++)
        {
            cbs_chnl_entry_struct *entry = &chnl_cntx->entry[i];

            if (entry->mid == channel_id)
            {
                mmi_wcscpy(channel_name, entry->name);
                break;
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_read_multi_chnl_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_read_multi_chnl_record(
                cbs_chnl_name_entry_struct *chnl_name_buff,
                U16 index,
                U16 amount,
                srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = index + 1;
    U16 buff_size;
    S16 error_code;
#ifdef __SRV_SMS_MULTI_SIM__
    U32 sim_index;
    U32 i;
#endif /* __SRV_SMS_MULTI_SIM__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_READ_MULTI_CHNL_RECORD, index, amount, sim_id);

#ifdef __SRV_SMS_MULTI_SIM__
    sim_index = srv_sms_sim_id_to_sim_index(sim_id);

    for (i = 0; i < sim_index; i++)
    {
        record_index += NVRAM_EF_SRV_CBS_CHNL_NAME_NUM;
    }
#endif /* __SRV_SMS_MULTI_SIM__ */

    buff_size = sizeof(cbs_chnl_name_entry_struct) * amount;

    ReadMultiRecord(
        NVRAM_EF_SRV_CBS_CHNL_NAME_LID,
        record_index,
        chnl_name_buff,
        buff_size,
        amount,
        &error_code);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_write_chnl_name_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_write_chnl_name_record(
                U16 chnl_id,
                WCHAR *name_buff,
                U16 index,
                srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbs_chnl_name_entry_struct chnl_name;
    U16 record_index = index + 1;
    S16 error_code;
#ifdef __SRV_SMS_MULTI_SIM__
    U32 sim_index;
    U32 i;
#endif /* __SRV_SMS_MULTI_SIM__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_WRITE_CHNL_NAME_RECORD, index, sim_id);

#ifdef __SRV_SMS_MULTI_SIM__
    sim_index = srv_sms_sim_id_to_sim_index(sim_id);

    for (i = 0; i < sim_index; i++)
    {
        record_index += NVRAM_EF_SRV_CBS_CHNL_NAME_NUM;
    }
#endif /* __SRV_SMS_MULTI_SIM__ */

    chnl_name.mid = chnl_id;
    memcpy(chnl_name.name, name_buff, sizeof(U16) * SRV_CBS_CHNL_NAME_LEN);

    WriteRecord(
        NVRAM_EF_SRV_CBS_CHNL_NAME_LID,
        record_index,
        &chnl_name,
        sizeof(cbs_chnl_name_entry_struct),
        &error_code);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_del_chnl_name_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_del_chnl_name_record(U16 index, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = index + 1;
    cbs_chnl_name_entry_struct channel_name;
    S16 error_code;
#ifdef __SRV_SMS_MULTI_SIM__
    U32 sim_index;
    U32 i;
#endif /* __SRV_SMS_MULTI_SIM__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DEL_CHNL_NAME_RECORD, index, sim_id);

#ifdef __SRV_SMS_MULTI_SIM__
    sim_index = srv_sms_sim_id_to_sim_index(sim_id);

    for (i = 0; i < sim_index; i++)
    {
        record_index += NVRAM_EF_SRV_CBS_CHNL_NAME_NUM;
    }
#endif /* __SRV_SMS_MULTI_SIM__ */

    channel_name.mid = SRV_CBS_UNUSED_CBMI;
    channel_name.name[0] = 0;

    WriteRecord(
        NVRAM_EF_SRV_CBS_CHNL_NAME_LID,
        record_index,
        &channel_name,
        sizeof(cbs_chnl_name_entry_struct),
        &error_code);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_add_chnl_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_add_chnl_entry(
                cbs_chnl_entry_struct* entry,
                cbs_chnl_cntx_struct *chnl_cntx,
                srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbs_chnl_entry_struct *tmp_entry;
    U32 total = chnl_cntx->total;
    U32 i;
    U32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_ADD_CHNL_ENTRY, total);

    if (entry->name_index != CBS_INVALID_NAME_INDEX)
    {
        srv_cbs_write_chnl_name_record(entry->mid, entry->name, entry->name_index, sim_id);
    }

    tmp_entry = chnl_cntx->entry;
    
    for (i = 0; i < total; i++)
    {
        if (tmp_entry[i].mid >= entry->mid)
        {
            break;
        }
    }

    for (j = total; j > i; j--)
    {
        memcpy(&tmp_entry[j], &tmp_entry[j - 1], sizeof(cbs_chnl_entry_struct));
    }

    memcpy(&tmp_entry[i], entry, sizeof(cbs_chnl_entry_struct));

    chnl_cntx->total++;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_del_chnl_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_del_chnl_entry(
                U16 mid,
                cbs_chnl_cntx_struct *chnl_cntx,
                srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbs_chnl_entry_struct *tmp_entry;
    U32 total = chnl_cntx->total;
    U32 i;
    U32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DEL_CHNL_ENTRY, mid, total);

    tmp_entry = chnl_cntx->entry;
    
    for (i = 0; i < total; i++)
    {
        if (tmp_entry[i].mid == mid)
        {
            break;
        }
    }

    if (i < total)
    {
        U8 name_index = tmp_entry[i].name_index;
    
        if (name_index != CBS_INVALID_NAME_INDEX)
        {
            srv_cbs_set_chnl_flag(CHNL_FLAG_NAME_USED, name_index, MMI_FALSE, chnl_cntx);
            srv_cbs_del_chnl_name_record(name_index, sim_id);
        }

        srv_cbs_set_chnl_flag(CHNL_FLAG_MID_USED, tmp_entry[i].mid_index, MMI_FALSE, chnl_cntx);

        for (j = i; j < (total - 1); j++)
        {
            memcpy(&tmp_entry[j], &tmp_entry[j + 1], sizeof(cbs_chnl_entry_struct));
        }

        chnl_cntx->total--;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_update_chnl_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_update_chnl_entry(
                U16 mid,
                cbs_chnl_entry_struct* entry,
                cbs_chnl_cntx_struct *chnl_cntx,
                srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbs_chnl_entry_struct *tmp_entry;
    U32 total = chnl_cntx->total;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_UPDATE_CHNL_ENTRY, mid, total);

    tmp_entry = chnl_cntx->entry;

    /* Find the old entry */
    for (i = 0; i < total; i++)
    {
        if (tmp_entry[i].mid == mid)
        {
            break;
        }
    }

    if (i < total)
    {
        U8 old_name_index = tmp_entry[i].name_index;
        U8 new_name_index = entry->name_index;

        if (mid == entry->mid)
        {
            memcpy(&tmp_entry[i], entry, sizeof(cbs_chnl_entry_struct));
        }
        else
        {
            U32 j;

            /* Delete Old Entry */
            if (i < total)
            {
                for (j = i; j < (total - 1); j++)
                {
                    memcpy(&tmp_entry[j], &tmp_entry[j + 1], sizeof(cbs_chnl_entry_struct));
                }

                total--;
            }

            /* Add New Entry */
            for (i = 0; i < total; i++)
            {
                if (tmp_entry[i].mid >= entry->mid)
                {
                    break;
                }
            }

            for (j = total; j > i; j--)
            {
                memcpy(&tmp_entry[j], &tmp_entry[j - 1], sizeof(cbs_chnl_entry_struct));
            }

            memcpy(&tmp_entry[i], entry, sizeof(cbs_chnl_entry_struct));
        }

        if ((old_name_index != CBS_INVALID_NAME_INDEX) && 
            (old_name_index != new_name_index))
        {
            srv_cbs_del_chnl_name_record(old_name_index, sim_id);
        }

        if (new_name_index != CBS_INVALID_NAME_INDEX)
        {
            srv_cbs_write_chnl_name_record(
                entry->mid,
                entry->name,
                new_name_index,
                sim_id);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_add_chnl_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_add_chnl_callback(srv_sms_disp_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_cb_mode_rsp_struct *rsp_data;
    cbs_add_chnl_struct* add_chnl_cntx;
    srv_cbs_add_channel_cb_struct add_cb_data;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
    srv_sms_sim_enum sim_id;
    srv_cbs_cntx_struct *cbs_cntx;
    cbs_chnl_cntx_struct *chnl_cntx;
    cbs_chnl_entry_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_data = (mmi_sms_set_cb_mode_rsp_struct*)callback_data->data;
    add_chnl_cntx = (cbs_add_chnl_struct*)callback_data->user_data;
    callback_func = add_chnl_cntx->callback_func;
    user_data = add_chnl_cntx->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_ADD_CHNL_CALLBACK, rsp_data->result);

    sim_id = add_chnl_cntx->sim_id;
    cbs_cntx = srv_cbs_get_cntx(sim_id);
    chnl_cntx = &cbs_cntx->chnl_cntx;
    entry = &add_chnl_cntx->entry;

    if (rsp_data->result)
    {
        srv_cbs_add_chnl_event_struct event_data;

        cbs_cntx = srv_cbs_get_cntx(sim_id);
   
        srv_cbs_add_chnl_entry(
            entry,
            chnl_cntx,
            sim_id);

        MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_ADD_CHNL);
        event_data.sim_id = sim_id;
        event_data.chnl_id = entry->mid;

        OslMfree(add_chnl_cntx);

        srv_sms_callback(
            SRV_SMS_ACTION_CB_ADD_CHNL,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            &add_cb_data,
            user_data,
            callback_func);

        MMI_FRM_CB_EMIT_EVENT(&event_data);
    }
    else
    {
        /* If set CB mode failed, clear the used flag */
        srv_cbs_set_chnl_flag(CHNL_FLAG_NAME_USED, entry->name_index, MMI_FALSE, chnl_cntx);
        srv_cbs_set_chnl_flag(CHNL_FLAG_MID_USED, entry->mid_index, MMI_FALSE, chnl_cntx);

        OslMfree(add_chnl_cntx);

        srv_sms_callback(
            SRV_SMS_ACTION_CB_ADD_CHNL,
            MMI_FALSE,
            SRV_SMS_CAUSE_UNKNOWN_ERROR,
            &add_cb_data,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_del_chnl_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_del_chnl_callback(srv_sms_disp_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_cb_mode_rsp_struct *rsp_data;
    cbs_del_chnl_struct* del_chnl_cntx;
    srv_cbs_delete_channel_cb_struct del_cb_data;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
    srv_sms_sim_enum sim_id;
    srv_cbs_cntx_struct *cbs_cntx;
    cbs_chnl_cntx_struct *chnl_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_data = (mmi_sms_set_cb_mode_rsp_struct*)callback_data->data;
    del_chnl_cntx = (cbs_del_chnl_struct*)callback_data->user_data;
    callback_func = del_chnl_cntx->callback_func;
    user_data = del_chnl_cntx->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DEL_CHNL_CALLBACK, rsp_data->result);

    sim_id = del_chnl_cntx->sim_id;
    cbs_cntx = srv_cbs_get_cntx(sim_id);
    chnl_cntx = &cbs_cntx->chnl_cntx;

    srv_cbs_set_chnl_flag(
        CHNL_FLAG_MID_OPERATING,
        del_chnl_cntx->mid_index,
        MMI_FALSE,
        chnl_cntx);

    if (rsp_data->result)
    {
        srv_cbs_del_chnl_event_struct event_data;

        srv_cbs_del_chnl_entry(
            del_chnl_cntx->mid,
            chnl_cntx,
            sim_id);

        MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_DEL_CHNL);
        event_data.sim_id = sim_id;
        event_data.chnl_id = del_chnl_cntx->mid;

        OslMfree(del_chnl_cntx);

        srv_sms_callback(
            SRV_SMS_ACTION_CB_DELETE_CHNL,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            &del_cb_data,
            user_data,
            callback_func);

        MMI_FRM_CB_EMIT_EVENT(&event_data);
    }
    else
    {
        OslMfree(del_chnl_cntx);

        srv_sms_callback(
            SRV_SMS_ACTION_CB_DELETE_CHNL,
            MMI_FALSE,
            SRV_SMS_CAUSE_UNKNOWN_ERROR,
            &del_cb_data,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_update_chnl_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_update_chnl_callback(srv_sms_disp_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_cb_mode_rsp_struct *rsp_data;
    cbs_update_chnl_struct* update_chnl_cntx;
    srv_cbs_update_channel_cb_struct update_cb_data;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
    srv_sms_sim_enum sim_id;
    srv_cbs_cntx_struct *cbs_cntx;
    //cbs_chnl_cntx_struct *chnl_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_data = (mmi_sms_set_cb_mode_rsp_struct*)callback_data->data;
    update_chnl_cntx = (cbs_update_chnl_struct*)callback_data->user_data;
    callback_func = update_chnl_cntx->callback_func;
    user_data = update_chnl_cntx->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_UPDATE_CHNL_CALLBACK, rsp_data->result);

    sim_id = update_chnl_cntx->sim_id;
    cbs_cntx = srv_cbs_get_cntx(sim_id);
    //chnl_cntx = &cbs_cntx->chnl_cntx;

    srv_cbs_set_chnl_flag(
        CHNL_FLAG_MID_OPERATING,
        update_chnl_cntx->new_entry.mid_index,
        MMI_FALSE,
        &cbs_cntx->chnl_cntx);

    if (rsp_data->result)
    {
        srv_cbs_update_chnl_event_struct event_data;
 
        srv_cbs_update_chnl_entry(
            update_chnl_cntx->old_chnl.id,
            &update_chnl_cntx->new_entry,
            &cbs_cntx->chnl_cntx,
            sim_id);

        MMI_FRM_INIT_EVENT(&event_data, EVT_ID_SRV_CBS_UPDATE_CHNL);
        event_data.sim_id = sim_id;
        memcpy(&event_data.new_chnl, &update_chnl_cntx->new_chnl, sizeof(srv_cbs_chnl_entry_struct));
        memcpy(&event_data.old_chnl, &update_chnl_cntx->old_chnl, sizeof(srv_cbs_chnl_entry_struct));

        OslMfree(update_chnl_cntx);

        srv_sms_callback(
            SRV_SMS_ACTION_CB_UPDATE_CHNL,
            MMI_TRUE,
            SRV_SMS_CAUSE_NO_ERROR,
            &update_cb_data,
            user_data,
            callback_func);

        MMI_FRM_CB_EMIT_EVENT(&event_data);
    }
    else
    {
        if (update_chnl_cntx->is_new_name)
        {
            srv_cbs_set_chnl_flag(
                CHNL_FLAG_NAME_USED,
                update_chnl_cntx->new_entry.name_index,
                MMI_FALSE,
                &cbs_cntx->chnl_cntx);
        }

        OslMfree(update_chnl_cntx);

        srv_sms_callback(
            SRV_SMS_ACTION_CB_UPDATE_CHNL,
            MMI_FALSE,
            SRV_SMS_CAUSE_UNKNOWN_ERROR,
            &update_cb_data,
            user_data,
            callback_func);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_select_lang_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_select_lang_callback(srv_sms_disp_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_cb_mode_rsp_struct *rsp_data;
    cbs_select_lang_struct* sel_lang_cntx;
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_cbs_select_language_cb_struct sel_cb_data;
    SrvSmsCallbackFunc callback_func;
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_data = (mmi_sms_set_cb_mode_rsp_struct*)callback_data->data;
    sel_lang_cntx = (cbs_select_lang_struct*)callback_data->user_data;
    callback_func = sel_lang_cntx->callback_func;
    user_data = sel_lang_cntx->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_SELECT_LANG_CALLBACK, rsp_data->result);

    if (rsp_data->result)
    {
        srv_cbs_cntx_struct *cbs_cntx;

        cbs_cntx = srv_cbs_get_cntx(sel_lang_cntx->sim_id);
        memcpy(&cbs_cntx->lang_cntx, &sel_lang_cntx->lang_cntx, sizeof(cbs_lang_cntx_struct));
    }
    else
    {
        error_cause = SRV_SMS_CAUSE_UNKNOWN_ERROR;
    }

    OslMfree(sel_lang_cntx);

    srv_sms_callback(
        SRV_SMS_ACTION_CB_SELECT_LANG,
        (MMI_BOOL)rsp_data->result,
        error_cause,
        &sel_cb_data,
        user_data,
        callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_setting_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_cbs_setting_init(
        srv_sms_sim_enum sim_id,
        SrvSmsCallbackFunc callback_func,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    setting_init_cntx_struct *init_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_SETTING_INIT);

    init_cntx = OslMalloc(sizeof(setting_init_cntx_struct));

    init_cntx->sim_id = sim_id;
    init_cntx->callback_func = callback_func;
    init_cntx->user_data = user_data;

    srv_cbs_disp_get_cb_mode(
        init_cntx->sim_id,
        srv_cbs_setting_init_callback,
        init_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_setting_init_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_setting_init_callback(srv_sms_disp_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    setting_init_cntx_struct *init_cntx;
    mmi_sms_get_cb_mode_rsp_struct *rsp_data;
    SrvSmsCallbackFunc callback_func;
    void *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_data = (mmi_sms_get_cb_mode_rsp_struct*)callback_data->data;
    init_cntx = (setting_init_cntx_struct*)callback_data->user_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_SETTING_INIT_CALLBACK, rsp_data->result);

    if (rsp_data->result)
    {
        srv_cbs_cntx_struct *cbs_cntx;
        srv_sms_sim_enum sim_id = init_cntx->sim_id;

        cbs_cntx = srv_cbs_get_cntx(sim_id);

        cbs_cntx->mode = rsp_data->mode;

        srv_cbs_ps_data_to_chnl_info(&cbs_cntx->chnl_cntx, rsp_data, sim_id);
        srv_cbs_ps_data_to_lang_info(&cbs_cntx->lang_cntx, rsp_data, sim_id);
    }

    callback_func = init_cntx->callback_func;
    user_data = init_cntx->user_data;

    OslMfree(init_cntx);

    srv_sms_succ_callback(
        SRV_SMS_ACTION_NONE,
        NULL,
        user_data,
        callback_func);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_disp_subscribe
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_disp_subscribe(
                mmi_cb_subscribe_req_struct *req_data,
                srv_sms_sim_enum sim_id,
                SrvSmsDispCallbackFunc callback_func,
                void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DISP_SUBSCRIBE, sim_id);

    srv_sms_write_sim_req(
        SRV_SMS_CB_SUBSCRIBE,
        0,
        0,
        req_data,
        sim_id,
        callback_func,
        user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_disp_get_cb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_disp_get_cb_mode(
                srv_sms_sim_enum sim_id,
                SrvSmsDispCallbackFunc callback_func,
                void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DISP_GET_CB_MODE, sim_id);

    srv_sms_read_sim_req(
        SRV_SMS_CB_MODE,
        0,
        0,
        sim_id,
        callback_func,
        user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_disp_set_cb_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_disp_set_cb_mode(
                mmi_sms_set_cb_mode_req_struct *req_data,
                srv_sms_sim_enum sim_id,
                SrvSmsDispCallbackFunc callback_func,
                void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_CBS_DISP_SET_CB_MODE, sim_id);

    srv_sms_write_sim_req(
        SRV_SMS_CB_MODE,
        0,
        0,
        req_data,
        sim_id,
        callback_func,
        user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_set_chnl_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_cbs_set_chnl_flag(
                cbs_chnl_flag_enum flag,
                U32 index,
                MMI_BOOL is_set,
                cbs_chnl_cntx_struct* chnl_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < SRV_CBS_MAX_CHNL_NUM)
    {
        U32 bit_total = (index * CHNL_FLAG_TOTAL) + flag;
        U32 byte_index = bit_total / 8;
        U32 bit_index = bit_total % 8;
        U8 bit_mask = 0x01 << bit_index;

        if (is_set)
        {
            chnl_cntx->flag[byte_index] |= bit_mask;
        }
        else
        {
            chnl_cntx->flag[byte_index] &= (~bit_mask);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cbs_get_chnl_flag
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_cbs_get_chnl_flag(
                    cbs_chnl_flag_enum flag,
                    U32 index,
                    cbs_chnl_cntx_struct* chnl_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index < SRV_CBS_MAX_CHNL_NUM)
    {
        U32 bit_total = (index * CHNL_FLAG_TOTAL) + flag;
        U32 byte_index = bit_total / 8;
        U32 bit_index = bit_total % 8;
        U8 bit_mask = 0x01 << bit_index;

        return (MMI_BOOL)((chnl_cntx->flag[byte_index] & bit_mask) != 0);
    }
    else
    {
        return MMI_FALSE;
    }
}


#endif /* __MOD_SMSAL__ */
#endif /*__SRV_CBS_SUPPORT__*/
