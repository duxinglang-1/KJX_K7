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
 *  SmsStatusReportSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Status Report Handler
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_nvram_gprot.h"
#include "Unicodexdcl.h"
#include "string.h"
#include "app_datetime.h"
#include "DateTimeType.h"

#include "MMI_common_app_trc.h"
#include "nvram_common_defs.h"
#include "SmsSrvGProt.h"
#include "SmsProtSrv.h"
#include "ps_public_enum.h"
#include "SmsStatusReportSrv.h"
#include "SmsUtilSrv.h"
#include "SmsConverterSrv.h"
#include "SmsStorageSrv.h"
#ifdef __SRV_SMS_ARCHIVE__
#include "SmsArchiveSrv.h"
#endif /* __SRV_SMS_ARCHIVE__ */
#include "PhbSrvGprot.h"


/**************************************************************
* MARCO
**************************************************************/
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
#define SRV_SMS_SR_READ_NUM             (SRV_SMS_MAX_BUFF_SIZE / sizeof(srv_sms_sr_entry_struct))
#define SRV_SMS_SR_MAX_LIST_SIZE        (NVRAM_EF_SRV_SMS_STATUS_REPORT_TOTAL)

#ifdef __MMI_UM_REPORT_BOX__
#define SRV_SMS_SR_BACKUP_NUM           3
#define SRV_SMS_SR_MAX_NUM              (SRV_SMS_SR_MAX_LIST_SIZE + SRV_SMS_SR_BACKUP_NUM)
#else /* __MMI_UM_REPORT_BOX__ */
#define SRV_SMS_SR_MAX_NUM              (SRV_SMS_SR_MAX_LIST_SIZE)
#endif /* __MMI_UM_REPORT_BOX__ */
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */


/**************************************************************
* Structure Declaration
**************************************************************/
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
/* Make sure the structure is same as nvram_ef_srv_sms_status_report_struct */
typedef struct
{
    U8 total_seg;
    U8 msg_ref[SRV_SMS_MAX_SEG];
    U8 status[SRV_SMS_MAX_SEG];
    U8 number[SRV_SMS_MAX_ADDR_LEN + 1];
#ifdef __SRV_SMS_MULTI_SIM__
    U16 sim_id;
#endif /* __SRV_SMS_MULTI_SIM__ */
    U32 timestamp;
} srv_sms_sr_entry_struct;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */


/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_sms_sr_status_enum srv_sms_sr_tp_st_to_status(U8 tp_st);

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
static U16 srv_sms_sr_add_new_entry(srv_sms_sr_entry_struct *entry);
static void srv_sms_sr_add_into_list(U16 report_id);
static void srv_sms_sr_del_from_list(U16 report_id);
#ifdef __MMI_UM_REPORT_BOX__
static void srv_sms_sr_sort_list(void);
#endif
static U16 srv_sms_sr_get_discarded_id(void);
static U16 srv_sms_sr_get_unused_id(void);
static MMI_BOOL srv_sms_sr_is_report_exist(U16 report_id);
static void srv_sms_sr_write_nvram_record(U16 report_id, srv_sms_sr_entry_struct *entry);
static void srv_sms_sr_add_data_to_entry(
                srv_sms_sr_entry_struct *entry,
                srv_sms_sr_add_struct *add_data);
static U16 srv_sms_sr_find_report_id(
                U8 number[],
                U16 msg_ref,
                srv_sms_sim_enum sim_id,
                U8 *curr_seg);
static U16 srv_sms_sr_is_completed(U16 report_id);
static void srv_sms_sr_entry_to_info(srv_sms_status_report_struct *data, srv_sms_sr_entry_struct *entry);
#ifdef __MMI_UM_REPORT_BOX__
static U16 srv_sms_sr_add_backup_entry(srv_sms_sr_entry_struct *entry);
static U16 srv_sms_sr_get_backup_id(void);
static srv_sms_sr_status_enum srv_sms_sr_get_status(U16 report_id);
#endif /* __MMI_UM_REPORT_BOX__ */
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */

static void srv_sms_convert_report_data(
                srv_sms_status_report_struct *report_data,
                srv_sms_status_report_ind_struct *ind_data,
                srv_sms_sr_status_enum status,
                srv_sms_sim_enum sim_id);

/**************************************************************
* Static Function Declaration
**************************************************************/
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
static srv_sms_sr_entry_struct sms_sr_entry[SRV_SMS_SR_MAX_NUM];
static U16 sms_sr_list[SRV_SMS_SR_MAX_LIST_SIZE];
static U16 sms_sr_list_size;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */


/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_sms_status_report_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_status_report_ind_hdlr(
        srv_sms_status_report_ind_struct *ind_data,
        srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sr_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STATUS_REPORT_IND_HDLR, sim_id);

    status = srv_sms_sr_tp_st_to_status(ind_data->tp_st);

    if ((status == SRV_SMS_SRS_SUCC) || (status == SRV_SMS_SRS_FAILED))
    {
    #ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
        U16 report_id = SRV_SMS_INVALID_MSG_ID;
        U8 curr_seg = 0;
    #else /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
        srv_sms_event_new_status_report_struct event_data;
    #endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */

    #ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
        report_id = srv_sms_sr_find_report_id(
                        ind_data->number,
                        ind_data->msg_ref,
                        sim_id,
                        &curr_seg);

        if (report_id != SRV_SMS_INVALID_MSG_ID)
        {
            U32 timestamp;

            timestamp = srv_sms_scts_to_utc_sec(ind_data->discharge_time);

            srv_sms_sr_update_report(
                report_id,
                curr_seg,
                ind_data->msg_ref,
                timestamp,
                status);

            if (srv_sms_sr_is_completed(report_id))
            {
                srv_sms_event_new_status_report_struct event_data;

                event_data.sim_id = sim_id;
                event_data.report_id = report_id;

                srv_sms_get_report_info(&event_data.report_data, report_id);

            #ifndef __MMI_UM_REPORT_BOX__
                srv_sms_sr_del_report(report_id);
            #endif /* __MMI_UM_REPORT_BOX__ */

                srv_sms_emit_event(EVT_ID_SRV_SMS_STATUS_REPORT, &event_data);
            }
        }
    #ifndef __MMI_UM_REPORT_BOX__
        else
        {
            srv_sms_event_new_status_report_struct event_data;

            event_data.sim_id = sim_id;
            event_data.report_id = SRV_SMS_INVALID_MSG_ID;

            srv_sms_convert_report_data(
                &event_data.report_data,
                ind_data,
                status,
                sim_id);
            
            srv_sms_emit_event(EVT_ID_SRV_SMS_STATUS_REPORT, &event_data);
        }
    #endif /* __MMI_UM_REPORT_BOX__ */
    #else /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
        event_data.sim_id = sim_id;
        event_data.report_id = SRV_SMS_INVALID_MSG_ID;

        srv_sms_convert_report_data(
            &event_data.report_data,
            ind_data,
            status,
            sim_id);

        srv_sms_emit_event(EVT_ID_SRV_SMS_STATUS_REPORT, &event_data);
    #endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */

    #ifdef __SRV_SMS_DELIVERY_STATUS__
        srv_sms_update_sr_status(
            (S8*)ind_data->number,
            ind_data->msg_ref,
            sim_id,
            status,
            NULL,
            NULL);
    #endif /* __SRV_SMS_DELIVERY_STATUS__ */
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_status_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_delete_status_report(U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_STATUS_REPORT, report_id);

    result = srv_sms_sr_is_report_exist(report_id);

    if (result)
    {
    #ifdef __MMI_UM_REPORT_BOX__
        srv_sms_event_del_report_struct event_data;
    #endif /* __MMI_UM_REPORT_BOX__ */

        srv_sms_sr_del_report(report_id);
        srv_sms_sr_del_from_list(report_id);

    #ifdef __MMI_UM_REPORT_BOX__
        srv_sms_emit_event(EVT_ID_SRV_SMS_DEL_REPORT, &event_data);
    #endif /* __MMI_UM_REPORT_BOX__ */
    }

    return result;
#else /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    return MMI_FALSE;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_delete_status_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_delete_all_status_report(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DELETE_ALL_STATUS_REPORT);

    for (i = 0; i < SRV_SMS_SR_MAX_LIST_SIZE; i++)
    {
        srv_sms_delete_status_report(i);
    }

    return MMI_TRUE;
#else /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    return MMI_FALSE;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_report_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_get_report_info(srv_sms_status_report_struct *data, U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_REPORT_INFO, report_id);

    result = srv_sms_sr_is_report_exist(report_id);

    /* Check report ID validity*/
    if (result)
    {
        srv_sms_sr_entry_struct *entry = &sms_sr_entry[report_id];

        srv_sms_sr_entry_to_info(data, entry);
    }

    return result;
#else /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    return MMI_FALSE;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_report_sim_id
 * DESCRIPTION
 *  Get Message's SIM Card ID
 * PARAMETERS
 *  msg_id          [IN]        Message ID
 * RETURNS
 *  srv_sms_sim_enum
 *****************************************************************************/
srv_sms_sim_enum srv_sms_get_report_sim_id(U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum sim_id = SRV_SMS_SIM_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_SIM__
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    /* Check report ID validity*/
    if (srv_sms_sr_is_report_exist(report_id))
    {
        sim_id = (srv_sms_sim_enum)(sms_sr_entry[report_id].sim_id);
    }
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
#endif /* __SRV_SMS_MULTI_SIM__ */

    return sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_report_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_get_report_number(U16 report_id, WCHAR* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_sms_sr_is_report_exist(report_id);

    /* Check report ID validity*/
    if (result)
    {
        srv_sms_sr_entry_struct *entry = &sms_sr_entry[report_id];

        mmi_asc_to_wcs(number, (CHAR*)entry->number);
    }
    else
    {
        number[0] = '\0';
    }
#else /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    number[0] = '\0';
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_report_list_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_get_report_list_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_REPORT_LIST_SIZE, sms_sr_list_size);

    return sms_sr_list_size;
#else /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    return 0;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_report_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_get_report_id(U16 list_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    U16 report_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(sms_sr_list_size <= SRV_SMS_SR_MAX_LIST_SIZE);
    
    if (list_index < sms_sr_list_size)
    {
        return sms_sr_list[list_index];
    }
    else
    {
        report_id = SRV_SMS_INVALID_MSG_ID;
    }

    return report_id;
#else /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    return SRV_SMS_INVALID_MSG_ID;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_report_list_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_get_report_list_index(U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
    U16 list_index = SRV_SMS_INVALID_LIST_INDEX;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sms_sr_list_size; i++)
    {
        if (sms_sr_list[i] == report_id)
        {
            list_index = i;
            break;
        }
    }
    
    return list_index;
#else /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
    return SRV_SMS_INVALID_LIST_INDEX;
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_tp_st_to_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_sr_status_enum srv_sms_sr_tp_st_to_status(U8 tp_st)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sr_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_TP_ST_TO_STATUS, tp_st);

    if (tp_st < ST_TE1_CONGESTION)
    {
        status = SRV_SMS_SRS_SUCC;
    }
    else if (tp_st > ST_TE1_ERROR_IN_SME)
    {
        status = SRV_SMS_SRS_FAILED;
    }
    else
    {
        status = SRV_SMS_SRS_PENDING;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_TP_ST_TO_STATUS_1, status);

    return status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_report_id_to_msg_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_report_id_to_msg_id(U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    return (report_id + SRV_SMS_MAX_SMS_ENTRY + SRV_SMS_MAX_ARCH_ENTRY);
#else /* __SRV_SMS_ARCHIVE__ */
    return (report_id + SRV_SMS_MAX_SMS_ENTRY);
#endif /* __SRV_SMS_ARCHIVE__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_id_to_report_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_sms_msg_id_to_report_id(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    return (msg_id - SRV_SMS_MAX_SMS_ENTRY - SRV_SMS_MAX_ARCH_ENTRY);
#else /* __SRV_SMS_ARCHIVE__ */
    return (msg_id - SRV_SMS_MAX_SMS_ENTRY);
#endif /* __SRV_SMS_ARCHIVE__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_report_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_is_report_msg(U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_ARCHIVE__
    if (msg_id < (SRV_SMS_MAX_SMS_ENTRY + SRV_SMS_MAX_ARCH_ENTRY))
    {
        result = MMI_FALSE;
    }
#else /* __SRV_SMS_ARCHIVE__ */
    if (msg_id < SRV_SMS_MAX_SMS_ENTRY)
    {
        result = MMI_FALSE;
    }
#endif /* __SRV_SMS_ARCHIVE__ */

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_IS_REPORT_MSG, msg_id, result);

    return result;
}


#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_status_report_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_status_report_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 remain = SRV_SMS_SR_MAX_LIST_SIZE;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STATUS_REPORT_INIT);

    memset(sms_sr_list, 0xFF, SRV_SMS_SR_MAX_LIST_SIZE * sizeof(U16));
    sms_sr_list_size = 0;

    while (remain > 0)
    {
        U16 amout;
        U16 start_id;
        S16 error_code;

        start_id = SRV_SMS_SR_MAX_LIST_SIZE - remain;

        if (remain > SRV_SMS_SR_READ_NUM)
        {
            amout = SRV_SMS_SR_READ_NUM;
            remain -= SRV_SMS_SR_READ_NUM;
        }
        else
        {
            amout = remain;
            remain = 0;
        }

        ReadMultiRecord(
            NVRAM_EF_SRV_SMS_STATUS_REPORT_LID,
            (U16)(start_id + 1),
            &sms_sr_entry[start_id],
            (U16)(sizeof(srv_sms_sr_entry_struct) * amout),
            amout,
            &error_code);
    }

    for (i = 0; i < SRV_SMS_SR_MAX_LIST_SIZE; i++)
    {
        srv_sms_sr_entry_struct *entry = &sms_sr_entry[i];

        if (entry->total_seg > 0)
        {
            srv_sms_sr_add_into_list(i);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_add_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_sr_add_report(srv_sms_sr_add_struct *add_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 report_id = SRV_SMS_INVALID_MSG_ID;
    U8 total_seg = add_data->total_seg;
    U8 curr_seg = add_data->curr_seg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_ADD_REPORT);

    if ((total_seg <= SRV_SMS_MAX_SEG) && (curr_seg < total_seg))
    {
        srv_sms_sr_entry_struct entry;

        srv_sms_sr_add_data_to_entry(&entry, add_data);

    #ifdef __MMI_UM_REPORT_BOX__
        if (add_data->is_hidden)
        {
            report_id = srv_sms_sr_add_backup_entry(&entry);
        }
        else
    #endif /* __MMI_UM_REPORT_BOX__ */
        {
            report_id = srv_sms_sr_add_new_entry(&entry);
        }

        MMI_ASSERT(report_id != SRV_SMS_INVALID_MSG_ID);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_ADD_REPORT_1, report_id);

    return report_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_del_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_sr_del_report(U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sr_entry_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_DEL_REPORT, report_id);

    MMI_ASSERT(report_id < SRV_SMS_SR_MAX_NUM);

    entry = &sms_sr_entry[report_id];

    memset(entry, 0, sizeof(srv_sms_sr_entry_struct));

#ifdef __MMI_UM_REPORT_BOX__
    if (report_id < SRV_SMS_SR_MAX_LIST_SIZE)
#endif /* __MMI_UM_REPORT_BOX__ */
    {
        srv_sms_sr_write_nvram_record(report_id, entry);
        srv_sms_sr_del_from_list(report_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_update_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_sr_update_report(
            U16 report_id,
            U8 curr_seg,
            U8 msg_ref,
            U32 timestamp,
            srv_sms_sr_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    srv_sms_sr_entry_struct *entry = &sms_sr_entry[report_id];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_UPDATE_REPORT, report_id, curr_seg, msg_ref);

    MMI_ASSERT(curr_seg < SRV_SMS_MAX_SEG);
    MMI_ASSERT(report_id < SRV_SMS_SR_MAX_NUM);

    entry = &sms_sr_entry[report_id];

    if ((entry->total_seg > 0) && (curr_seg < entry->total_seg))
    {
        srv_sms_event_update_report_struct event_data;


        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_UPDATE_REPORT_1, entry->total_seg);

        entry->timestamp = timestamp;
        entry->msg_ref[curr_seg] = msg_ref;
        entry->status[curr_seg] = status;

        event_data.report_id = report_id;

        srv_sms_exec_interrupt_event(EVT_ID_SRV_SMS_UPDATE_REPORT, &event_data);

    #ifdef __MMI_UM_REPORT_BOX__
        if (report_id < SRV_SMS_SR_MAX_LIST_SIZE)
        {
            srv_sms_sr_write_nvram_record(report_id, entry);

            srv_sms_sr_sort_list();

            srv_sms_emit_event(EVT_ID_SRV_SMS_UPDATE_REPORT, &event_data);
        }
    #else /* __MMI_UM_REPORT_BOX__ */
        srv_sms_sr_write_nvram_record(report_id, entry);
    #endif /* __MMI_UM_REPORT_BOX__ */
    }
    else
    {
        result = MMI_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_unhide_report
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_sms_sr_unhide_report(U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 dest_id = report_id;
#ifdef __MMI_UM_REPORT_BOX__
    srv_sms_sr_entry_struct *bakup_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_UNHIDE_REPORT, report_id);

    MMI_ASSERT((report_id >= SRV_SMS_SR_MAX_LIST_SIZE) && (report_id < SRV_SMS_SR_MAX_NUM));

    bakup_entry = &sms_sr_entry[report_id];

    dest_id = srv_sms_sr_add_new_entry(bakup_entry);

    memset(bakup_entry, 0, sizeof(srv_sms_sr_entry_struct));
#endif /* __MMI_UM_REPORT_BOX__ */

    return dest_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_add_new_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_sr_add_new_entry(srv_sms_sr_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 report_id;
#ifdef __MMI_UM_REPORT_BOX__
    srv_sms_event_add_report_struct event_data;
#endif /* __MMI_UM_REPORT_BOX__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_ADD_NEW_ENTRY, sms_sr_list_size);

    if (sms_sr_list_size == SRV_SMS_SR_MAX_LIST_SIZE)
    {
        report_id = srv_sms_sr_get_discarded_id();

        srv_sms_delete_status_report(report_id);
    }
    else
    {
        report_id = srv_sms_sr_get_unused_id();
    }

    MMI_ASSERT(report_id < SRV_SMS_SR_MAX_LIST_SIZE);

    memcpy(&sms_sr_entry[report_id], entry, sizeof(srv_sms_sr_entry_struct));

    srv_sms_sr_write_nvram_record(report_id, entry);
    srv_sms_sr_add_into_list(report_id);

#ifdef __MMI_UM_REPORT_BOX__
    srv_sms_emit_event(EVT_ID_SRV_SMS_ADD_REPORT, &event_data);
#endif /* __MMI_UM_REPORT_BOX__ */

    return report_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_add_to_msg_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_sr_add_into_list(U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 j;
    U32 new_timestamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_ADD_INTO_LIST, report_id, sms_sr_list_size);

    MMI_ASSERT(report_id < SRV_SMS_SR_MAX_LIST_SIZE);
    MMI_ASSERT(sms_sr_list_size < SRV_SMS_SR_MAX_LIST_SIZE);

    new_timestamp = sms_sr_entry[report_id].timestamp;

    for (i = 0; i < sms_sr_list_size; i++)
    {
        U32 cmp_timestamp;
        U16 cmp_id = sms_sr_list[i];

        cmp_timestamp = sms_sr_entry[cmp_id].timestamp;

        if (new_timestamp > cmp_timestamp)
        {
            break;
        }
    }

    for (j = (sms_sr_list_size - 1); j >= i; j--)
    {
        sms_sr_list[j + 1] = sms_sr_list[j];
    }

    sms_sr_list[i] = report_id;

    sms_sr_list_size++;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_del_from_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_sr_del_from_list(U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_num = sms_sr_list_size;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_DEL_FROM_LIST, report_id, sms_sr_list_size);

    MMI_ASSERT(report_id < SRV_SMS_SR_MAX_LIST_SIZE);

    if (total_num > 0)
    {
        for (i = 0; i < total_num; i++)
        {
            if (sms_sr_list[i] == report_id)
            {
                break;
            }
        }

        if (i < total_num)
        {
            for (; i < (total_num - 1); i++)
            {
                sms_sr_list[i] = sms_sr_list[i + 1];
            }

            sms_sr_list[total_num - 1] = SRV_SMS_INVALID_MSG_ID;

            sms_sr_list_size--;
        }
    }
}

#ifdef __MMI_UM_REPORT_BOX__

/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_sort_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_sr_sort_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < sms_sr_list_size; i++)
    {
        U16 max_index = i;
        U16 max_id = sms_sr_list[i];
        U32 max_timestamp = sms_sr_entry[max_id].timestamp;

        for (j = (i + 1); j < sms_sr_list_size; j++)
        {
            U16 cmp_id = sms_sr_list[j];
            U32 cmp_timestamp = sms_sr_entry[cmp_id].timestamp;

            if (cmp_timestamp > max_timestamp)
            {
                max_timestamp = cmp_timestamp;
                max_index = j;
            }
        }

        if (max_index != i)
        {
            U16 tmp_id;

            tmp_id = sms_sr_list[max_index];
            sms_sr_list[max_index] = sms_sr_list[i];
            sms_sr_list[i] = tmp_id;
        }
    }
}

#endif /* __MMI_UM_REPORT_BOX__*/
/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_get_discarded_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_sr_get_discarded_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UM_REPORT_BOX__
    S32 i;
    U16 report_id = SRV_SMS_INVALID_MSG_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_GET_DISCARDED_ID);

    for (i = (SRV_SMS_SR_MAX_LIST_SIZE - 1); i >= 0; i--)
    {
        U16 tmp_id = sms_sr_list[i];
        U16 status = srv_sms_sr_get_status(tmp_id);
    
        if (status == SRV_SMS_SRS_PENDING)
        {
            if (report_id == SRV_SMS_INVALID_MSG_ID)
            {
                report_id = tmp_id;
            }
        }
        else
        {
            report_id = tmp_id;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_GET_DISCARDED_ID_1, report_id);

    return report_id;
#else /* __MMI_UM_REPORT_BOX__ */
    return sms_sr_list[SRV_SMS_SR_MAX_LIST_SIZE - 1];
#endif /* __MMI_UM_REPORT_BOX__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_get_unused_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_sr_get_unused_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 report_id = SRV_SMS_INVALID_MSG_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_GET_UNUSED_ID);

    for (i = 0; i < SRV_SMS_SR_MAX_LIST_SIZE; i++)
    {
        if (sms_sr_entry[i].total_seg == 0)
        {
            report_id = i;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_GET_UNUSED_ID_1, report_id);

    return report_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_is_report_exist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_sr_is_report_exist(U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((report_id < SRV_SMS_SR_MAX_LIST_SIZE) && 
        (sms_sr_entry[report_id].total_seg > 0))
    {
        result = MMI_TRUE;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_IS_REPORT_EXIST, report_id, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_write_nvram_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_sr_write_nvram_record(U16 report_id, srv_sms_sr_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = report_id + 1; 
    S16 error_code;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_WRITE_NVRAM_RECORD);

    MMI_ASSERT(report_id < NVRAM_EF_SRV_SMS_STATUS_REPORT_TOTAL);

    WriteRecord(
        NVRAM_EF_SRV_SMS_STATUS_REPORT_LID,
        record_index,
        entry,
        (U16)sizeof(srv_sms_sr_entry_struct),
        &error_code);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_add_data_to_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_sr_add_data_to_entry(
                srv_sms_sr_entry_struct *entry,
                srv_sms_sr_add_struct *add_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 curr_seg = add_data->curr_seg;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    strcpy((char*)entry->number, (const char*)add_data->number);

    entry->total_seg = add_data->total_seg;
    entry->timestamp = srv_sms_get_local_sec();
    for (i = 0; i < SRV_SMS_MAX_SEG; i++)
    {
        if (i == curr_seg)
        {
            entry->status[i] = add_data->curr_status;
            entry->msg_ref[i] = add_data->curr_msg_ref;
        }
        else
        {
            entry->status[i] = SRV_SMS_SRS_NONE;
            entry->msg_ref[i] = 0;
        }
    }      
#ifdef __SRV_SMS_MULTI_SIM__
    entry->sim_id = add_data->sim_id;
#endif /* __SRV_SMS_MULTI_SIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_find_report_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_sr_find_report_id(
                U8 number[],
                U16 msg_ref,
                srv_sms_sim_enum sim_id,
                U8 *curr_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 report_id = SRV_SMS_INVALID_MSG_ID;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_FIND_REPORT_ID, number, msg_ref);

    for (i = 0; i < SRV_SMS_SR_MAX_NUM; i++)
    {
        srv_sms_sr_entry_struct *entry = &sms_sr_entry[i];

        if ((entry->total_seg > 0)
        #ifdef __SRV_SMS_MULTI_SIM__
            && (entry->sim_id == sim_id)
        #endif /* __SRV_SMS_MULTI_SIM__ */
            )
        {
            if (srv_sms_cmp_asc_num((S8*)number, (S8*)entry->number))
            {
                U32 j;

                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_FIND_REPORT_ID_1, i);

                for (j = 0; j < entry->total_seg; j++)
                {
                    if ((entry->msg_ref[j] == msg_ref) && 
                        (entry->status[j] == SRV_SMS_SRS_PENDING))
                    {
                        report_id = i;
                        *curr_seg = j;
                        break;
                    }
                }
            }
        }

        if (report_id != SRV_SMS_INVALID_MSG_ID)
        {
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_FIND_REPORT_ID_2, report_id);

    return report_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_is_completed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_sr_is_completed(U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sr_entry_struct *entry;
    MMI_BOOL is_completed = MMI_TRUE;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_IS_COMPLETED, report_id);

    MMI_ASSERT(report_id < SRV_SMS_SR_MAX_NUM);

    entry = &sms_sr_entry[report_id];

    for (i = 0; i < entry->total_seg; i++)
    {
        if ((entry->status[i] == SRV_SMS_SRS_NONE) ||
            (entry->status[i] == SRV_SMS_SRS_PENDING))
        {
            is_completed = MMI_FALSE;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_IS_COMPLETED_1, is_completed);

    return is_completed;
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_entry_to_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_sr_entry_to_info(srv_sms_status_report_struct *report_data, srv_sms_sr_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 succ_count = 0;
    U8 fail_count = 0;
    U8 pending_count = 0;
    U32 i;
    srv_sms_sr_status_enum status;
    U32 temp_timestap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //report_data->sec_timestamp = entry->timestamp;
    temp_timestap = applib_dt_sec_utc_to_local(entry->timestamp);
    mmi_dt_utc_sec_2_mytime(temp_timestap, &report_data->timestamp, MMI_FALSE);
    report_data->sec_timestamp = temp_timestap;
    for (i = 0; i < entry->total_seg; i++)
    {
        switch (entry->status[i])
        {
            case SRV_SMS_SRS_SUCC:
                succ_count++;
                break;

            case SRV_SMS_SRS_FAILED:
                fail_count++;
                break;

            case SRV_SMS_SRS_PENDING:
                pending_count++;
                break;

            default:
                MMI_ASSERT(0);
                break;
        }
    }

    if (pending_count > 0)
    {
        status = SRV_SMS_SRS_PENDING;
    }
    else if (fail_count > 0)
    {
        status = SRV_SMS_SRS_FAILED;
    }
    else
    {
        status = SRV_SMS_SRS_SUCC;
    }

    report_data->status = status;
    report_data->total_seg = entry->total_seg;
    report_data->succ_num = succ_count;
    report_data->fail_num = fail_count;
    mmi_asc_to_wcs(report_data->number, (CHAR*)entry->number);

#ifdef __SRV_SMS_MULTI_SIM__
    report_data->sim_id = (srv_sms_sim_enum)entry->sim_id;
#else /* __SRV_SMS_MULTI_SIM__ */
    report_data->sim_id = SRV_SMS_SIM_1;
#endif /* __SRV_SMS_MULTI_SIM__ */
}


#ifdef __MMI_UM_REPORT_BOX__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_add_backup_entry
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_sr_add_backup_entry(srv_sms_sr_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 report_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_ADD_BACKUP_ENTRY);

    report_id = srv_sms_sr_get_backup_id();

    MMI_ASSERT((report_id >= SRV_SMS_SR_MAX_LIST_SIZE) && (report_id < SRV_SMS_SR_MAX_NUM));

    memcpy(&sms_sr_entry[report_id], entry, sizeof(srv_sms_sr_entry_struct));

    return report_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_get_backup_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static U16 srv_sms_sr_get_backup_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 report_id = SRV_SMS_INVALID_MSG_ID;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = SRV_SMS_SR_MAX_LIST_SIZE; i < SRV_SMS_SR_MAX_NUM; i++)
    {
        if (sms_sr_entry[i].total_seg == 0)
        {
            report_id = i;
            break;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SR_GET_BACKUP_ID, report_id);

    return report_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_get_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_sr_status_enum srv_sms_sr_get_status(U16 report_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sr_status_enum status = SRV_SMS_SRS_SUCC;
    U32 i;
    srv_sms_sr_entry_struct *entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(report_id < SRV_SMS_SR_MAX_NUM);

    entry = &sms_sr_entry[report_id];

    for (i = 0; i < entry->total_seg; i++)
    {
        if (entry->status[i] == SRV_SMS_SRS_PENDING)
        {
            status = SRV_SMS_SRS_PENDING;
            break;
        }
        else if (entry->status[i] == SRV_SMS_SRS_FAILED)
        {
            status = SRV_SMS_SRS_FAILED;
        }
    }

    return status;
}
#endif /* __MMI_UM_REPORT_BOX__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_get_seg_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_sr_status_enum srv_sms_sr_get_seg_status(U16 report_id, U8 curr_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(curr_seg < SRV_SMS_MAX_SEG);

    if (srv_sms_sr_is_report_exist(report_id) &&
        (curr_seg < sms_sr_entry[report_id].total_seg))
    {
        return (srv_sms_sr_status_enum)(sms_sr_entry[report_id].status[curr_seg]);
    }
    else
    {
        return SRV_SMS_SRS_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_sr_get_total_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_sms_sr_get_total_status(U16 report_id, srv_sms_sr_status_enum sr_status[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 total = 0;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (report_id < SRV_SMS_SR_MAX_LIST_SIZE)
    {
        srv_sms_sr_entry_struct *entry = &sms_sr_entry[report_id];

        total = entry->total_seg;

        for (i = 0; i < total; i++)
        {
            sr_status[i] = (srv_sms_sr_status_enum)(entry->status[i]);
        }

    }

    for (i = total; i < SRV_SMS_MAX_SEG; i++)
    {
        sr_status[i] = SRV_SMS_SRS_INVALID;
    }

    return total;
}
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_convert_report_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_convert_report_data(
                srv_sms_status_report_struct *report_data,
                srv_sms_status_report_ind_struct *ind_data,
                srv_sms_sr_status_enum status,
                srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U32 temp_timestap;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_REPORT_DATA);

    report_data->sim_id = sim_id;
    report_data->total_seg = 1;
    report_data->status = status;

    if (status == SRV_SMS_SRS_SUCC)
    {
        report_data->succ_num = 1;
        report_data->fail_num = 0;
    }
    else
    {
        report_data->succ_num = 0;
        report_data->fail_num = 1;
    }
    temp_timestap = srv_sms_scts_to_utc_sec(ind_data->discharge_time);
	temp_timestap = applib_dt_sec_utc_to_local(temp_timestap);
	mmi_dt_utc_sec_2_mytime(temp_timestap, &report_data->timestamp, MMI_FALSE);

    //srv_sms_scts_to_mytime(&report_data->timestamp, ind_data->discharge_time);

    //report_data->sec_timestamp = mmi_dt_mytime_2_utc_sec(&report_data->timestamp, MMI_FALSE);
    report_data->sec_timestamp = temp_timestap;
    mmi_asc_to_wcs(report_data->number, (CHAR*)ind_data->number); 
}

#endif /* __MOD_SMSAL__ */
