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
 *  SmsConverterSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Converter
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
#include "mmi_frm_mem_gprot.h"
#include "ps_public_struct.h"
#include "custom_mmi_default_value.h"
#include "app_datetime.h"
#include "DateTimeType.h"
#include "Unicodexdcl.h"
#include "string.h"

#include "mcd_l4_common.h"
#include "csmcc_enums.h"
#include "l4c2abm_struct.h"
#include "mmi_common_app_trc.h"
#include "SmsSrvGProt.h"
#include "SmsProtSrv.h"
#include "SmsEmsSrv.h"
#include "SmsConverterSrv.h"
#include "Smslib.h"
#include "ps_public_utility.h"
#include "ems.h"
#ifdef __SMS_CLOUD_SUPPORT__
#include "SmsBackupRestoreSrv.h"
#endif



/**************************************************************
* MARCO
**************************************************************/
#define SPDU_STATUS_BIT_MASK        0x07
#define PDU_SCA_LEN_FIELD_SIZE      (1)
#define TPDU_FO_FIELD_SIZE          (1)
#define TPDU_MSG_REF_OFFSET         TPDU_FO_FIELD_SIZE

typedef enum
{
    SRV_SMS_LIB_TYPE_DEFAULT   = 0x00,
    SRV_SMS_LIB_TYPE_REPLAY_PATH,    
    SRV_SMS_LIB_TYPE_PID,
    SRV_SMS_LIB_TYPE_DCS,
    SRV_SMS_LIB_TYPE_UDHI,
    SRV_SMS_LIB_TYPE_ST_RP,        
    SRV_SMS_LIB_REVERED
} srv_sms_lib_type_enum;


/**************************************************************
* Structure Declaration
**************************************************************/


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
__inline static U8 srv_sms_semi_octet_to_digit(U8 semi_octet);
__inline static U8 srv_sms_digit_to_semi_octet(U8 digit);

static srv_sms_cause_enum srv_sms_pack_msg_data(
                            srv_sms_pack_struct *pack_data,
                            srv_sms_msg_node_struct* msg_node,
                            srv_sms_int_msg_data_struct* msg_data,
                            srv_sms_pack_enum pack_flag);

static void srv_sms_smslib_set_sc_addr(
                smslib_general_struct *sms_encode_data,
                char* ucs2_sc_addr);
static void srv_sms_smslib_set_number(
                smslib_general_struct *sms_encode_data,
                char* ucs2_addr);
static void srv_sms_smslib_set_lib_type(
                smslib_general_struct *sms_encode_data,
                U8 num,
                srv_sms_lib_type_enum type);

static void srv_sms_smslib_set_msg_ref(
                smslib_general_struct *sms_encode_data,
                U8 msg_ref);

static void srv_sms_ucs2_addr_to_tp_addr(U8 *tp_addr, U8 *tp_addr_len, char* ucs2_addr);
static void srv_sms_ucs2_addr_to_l4_number(l4c_number_struct *l4c_number, char* ucs2_addr);


static srv_sms_cause_enum srv_sms_ems_status_to_cause(EMSTATUS ems_result);

static void srv_sms_decode_data_to_msg_data(
                srv_sms_msg_data_struct* msg_data,
                smslib_general_struct* decode_data);

static MMI_BOOL srv_sms_unpack_data_to_msg_data(
                    srv_sms_msg_data_struct* msg_data,
                    srv_sms_unpack_struct* unpack_data);

/**************************************************************
* Function Defination
**************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_sms_scts_to_utc_sec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_sms_scts_to_utc_sec(U8 scts[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 time_zone;
    MMI_BOOL is_neg;
    U32 sec;
    U8 temp_time_zone;
    U32 utc_sec;
    MYTIME mytime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SCTS_TO_UTC_SEC);

    srv_sms_scts_to_mytime(&mytime, scts);

	if(0X08 & (scts[6]))
    {
        is_neg = MMI_TRUE;
    }
    else
    {
        is_neg = MMI_FALSE;
    }

    temp_time_zone = scts[6];
    temp_time_zone = temp_time_zone & (~0X08);
    time_zone = srv_sms_semi_octet_to_digit(temp_time_zone);
    sec = time_zone * 900;


    utc_sec = mmi_dt_mytime_2_utc_sec(&mytime, MMI_FALSE);


    if(is_neg)
    {
        utc_sec += sec;
    }
    else
    {
        utc_sec -= sec;
    }
        
    return utc_sec;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_utc_sec_to_scts
 * DESCRIPTION
 *  convert UTC Second to SCTS (SMS Center Timestamp)
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_utc_sec_to_scts(U8 scts[], U32 utc_sec)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME mytime;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UTC_SEC_TO_SCTS);

    mmi_dt_utc_sec_2_mytime(utc_sec, &mytime, MMI_FALSE);
    srv_sms_mytime_to_scts(scts, &mytime);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_scts_to_mytime
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_scts_to_mytime(MYTIME* mytime, U8 scts[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 month;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SCTS_TO_MYTIME);

    month = srv_sms_semi_octet_to_digit(scts[1]);

    if (month == 0)
    {
        mytime->nYear = DT_MIN_YEAR;
        mytime->nMonth = 1;
        mytime->nDay = 1;
        mytime->nHour = 0;
        mytime->nMin = 0;
        mytime->nSec = 0;
    }
    else
    {
        mytime->nYear = srv_sms_semi_octet_to_digit(scts[0]) + 2000;

        if (mytime->nYear > 2090)
        {
            mytime->nYear = mytime->nYear - 100;
        }

        mytime->nMonth = month;
        mytime->nDay   = srv_sms_semi_octet_to_digit(scts[2]);
        mytime->nHour  = srv_sms_semi_octet_to_digit(scts[3]);
        mytime->nMin   = srv_sms_semi_octet_to_digit(scts[4]);
        mytime->nSec   = srv_sms_semi_octet_to_digit(scts[5]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_semi_octet_to_digit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_mytime_to_scts(U8 scts[], MYTIME* mytime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MYTIME_TO_SCTS);

    scts[0] = srv_sms_digit_to_semi_octet((U8)(mytime->nYear % 100));
    scts[1] = srv_sms_digit_to_semi_octet(mytime->nMonth);
    scts[2] = srv_sms_digit_to_semi_octet(mytime->nDay);
    scts[3] = srv_sms_digit_to_semi_octet(mytime->nHour);
    scts[4] = srv_sms_digit_to_semi_octet(mytime->nMin);
    scts[5] = srv_sms_digit_to_semi_octet(mytime->nSec);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_status_to_spdu_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_sms_msg_status_to_spdu_status(srv_sms_status_enum msg_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum status;
    U8 pdu_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_STATUS_TO_SPDU_STATUS, msg_status);

    /* Remove the Unsupported status flag */
    status = (srv_sms_status_enum)(msg_status & (~SRV_SMS_STATUS_UNSUPPORTED));

    switch (status)
    {
        case SRV_SMS_STATUS_NONE:
            pdu_status = SPDU_STATUS_FREE_SPACE;
            break;

        case SRV_SMS_STATUS_UNREAD: 
            pdu_status = SPDU_STATUS_UNREAD;
            break;

        case SRV_SMS_STATUS_READ: 
            pdu_status = SPDU_STATUS_READ;
            break;

        case SRV_SMS_STATUS_SENT: 
            pdu_status = SPDU_STATUS_SENT;
            break;

        case SRV_SMS_STATUS_DRAFT:
            pdu_status = SPDU_STATUS_DRAFT;
            break;

        case SRV_SMS_STATUS_UNSENT: 
        default:
            pdu_status = SPDU_STATUS_UNSENT;
            break;
    }

    return pdu_status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_status_to_spdu_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_status_enum srv_sms_spdu_status_to_msg_status(U8 pdu_status, srv_sms_storage_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SPDU_STATUS_TO_MSG_STATUS, pdu_status);

    if ((storage_type == SRV_SMS_STORAGE_ME) &&
        (pdu_status == SPDU_STATUS_DRAFT))
    {
        msg_status = SRV_SMS_STATUS_DRAFT;
    }
    else
    {
        U8 status_bit = pdu_status & SPDU_STATUS_BIT_MASK;

        switch (status_bit)
        {
            case SPDU_STATUS_READ: 
                msg_status = SRV_SMS_STATUS_READ;
                break;

            case SPDU_STATUS_UNREAD: 
                msg_status = SRV_SMS_STATUS_UNREAD;
                break;

            case SPDU_STATUS_SENT: 
                msg_status = SRV_SMS_STATUS_SENT;
                break;

            case SPDU_STATUS_UNSENT:
                msg_status = SRV_SMS_STATUS_UNSENT;
                break;

            default:
                msg_status = SRV_SMS_STATUS_NONE;
                break;
        }
    }

    return msg_status;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_semi_octet_to_digit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
__inline static U8 srv_sms_semi_octet_to_digit(U8 semi_octet)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((semi_octet & 0x0F) % 10) * 10 + ((semi_octet & 0xF0) >> 4) % 10;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_digit_to_semi_octet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
__inline static U8 srv_sms_digit_to_semi_octet(U8 digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 temp_digit = digit % 100;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((temp_digit % 10) << 4 | (temp_digit / 10));
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_convert_msg_data_to_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_cause_enum srv_sms_convert_msg_data_to_pdu(
                    U8** pdu_list,
                    U8* pdu_len_list,
                    U8* total_num,
                    srv_sms_msg_node_struct* msg_node,
                    srv_sms_int_msg_data_struct* msg_data,
                    srv_sms_pack_enum pack_flag,
                    srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_sms_convert_msg_data_to_pdu_ext(
                pdu_list,
                pdu_len_list,
                total_num,
                msg_node,
                msg_data,
                pack_flag,
                sim_id,
                NULL,
                NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_convert_msg_data_to_pdu_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_cause_enum srv_sms_convert_msg_data_to_pdu_ext(
                    U8** pdu_list,
                    U8* pdu_len_list,
                    U8* total_num,
                    srv_sms_msg_node_struct *msg_node,
                    srv_sms_int_msg_data_struct* msg_data,
                    srv_sms_pack_enum pack_flag,
                    srv_sms_sim_enum sim_id,
                    GetPduListFunc get_pdu_list_func,
                    void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_para_enum para_flag = msg_data->para_flag;
    const srv_sms_setting_struct *default_setting;
    smslib_general_struct *sms_encode_data = NULL;
    srv_sms_pack_struct pack_data;
    U32 temp_timestamp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_PDU, msg_node, msg_data);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_PDU_1, SRV_SMS_MAX_SEND_SEG, pack_flag, sim_id);

    default_setting = srv_sms_get_default_setting(sim_id);

    if (msg_node != NULL)
    {
        msg_node->status = msg_data->status;
    }

    do
    {
        S8 *sc_address;
        S8 temp_address[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
        MYTIME local_time;
        MYTIME *timestamp;
        U32 i;
        smslib_mti_enum sms_mti;
        U8 reply_path;
        U8 status_report;
        U8* tmp_pdu_list[SRV_SMS_MAX_SEG];

        /* Check Number */
        if ((msg_data->number[0] != '\0') || (msg_data->number[1] != '\0'))
        {
            if (srv_sms_check_ucs2_number(msg_data->number) == MMI_FALSE)
            {
            #ifdef __SMS_CLOUD_SUPPORT__
                if(in_cloud_action != SRV_SMS_CLOUD_ACTION_RESTORE)
                {
                    error_cause = SRV_SMS_CAUSE_NUMBER_INVALID;
                    break;
                }
                else
                {
                    mmi_ucs2_to_asc(msg_node->number, msg_data->number);
                }
            #else
                error_cause = SRV_SMS_CAUSE_NUMBER_INVALID;
                break;
            #endif
                
            }
            else
            {
                if (msg_node != NULL)
                {
                    mmi_ucs2_to_asc(msg_node->number, msg_data->number);
                }
            }
        }
        else
        {
            if (msg_node != NULL)
            {
                msg_node->number[0] = '\0';
            }

            if (msg_data->is_allow_num_emtpy == MMI_FALSE)
            {
                error_cause = SRV_SMS_CAUSE_NUMBER_EMPTY;
                break;
            }
        }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_PDU_2);

        /* Check SC Address */
        if (para_flag & SRV_SMS_PARA_SCA)
        {
            sc_address = msg_data->sc_address;

            if ((sc_address[0] != '\0') || (sc_address[1] != '\0'))
            {
                if (srv_sms_check_ucs2_number((S8*)sc_address) == MMI_FALSE)
                {
                    error_cause = SRV_SMS_CAUSE_SC_INVALID;
                    break;
                }
            }
            else
            {
                if (msg_data->is_allow_sc_emtpy == MMI_FALSE)
                {
                    error_cause = SRV_SMS_CAUSE_SC_EMPTY;
                    break;
                }
            }
        }
        else
        {
            temp_address[0] = '\0';
            temp_address[1] = '\0';

            sc_address = temp_address;
        }

    #ifdef __SRV_SMS_MSG_INFO_PORT__
        if ((para_flag & SRV_SMS_PARA_PORT) && msg_node != NULL)
        {
            msg_node->port_num = msg_data->dest_port;
        }
    #endif /* __SRV_SMS_MSG_INFO_PORT__ */

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_PDU_3);

        /* Pack TP-UD */
        srv_sms_get_pack_data(&pack_data);

        error_cause = srv_sms_pack_msg_data(
                        &pack_data,
                        msg_node,
                        msg_data,
                        pack_flag);

        if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
        {
            break;
        }

        /* Allocate Encode Buffer */
        sms_encode_data = OslMalloc(sizeof(smslib_general_struct));

        switch (msg_data->status)
        {
            case SRV_SMS_STATUS_UNREAD:
            case SRV_SMS_STATUS_READ:
                sms_mti = SMSLIB_MTI_DELIVER;
                break;

            case SRV_SMS_STATUS_SENT:
            case SRV_SMS_STATUS_UNSENT:
            case SRV_SMS_STATUS_DRAFT:
            default:
                sms_mti = SMSLIB_MTI_SUBMIT;
                break;
        }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_PDU_4, sms_mti);

        /* Make sure the defination srv_sms_mti_enum is same as smslib_mti_enum */
        if (msg_node != NULL)
        {
            msg_node->mti = (U8)sms_mti;
        }

        smslib_alloc_sms_struct(sms_mti, sms_encode_data);
        smslib_reset_sms_struct(sms_encode_data);

        /* Set Number */
        srv_sms_smslib_set_number(sms_encode_data, msg_data->number);

        /* Set SC Address */
        srv_sms_smslib_set_sc_addr(sms_encode_data, (S8*)sc_address);

        /* Set SCTS (SMS Center Timestamp) */
        if (para_flag & SRV_SMS_PARA_TIMESTAMP)
        {
            timestamp = &msg_data->timestamp;
        }
        else
        {
            DTGetRTCTime(&local_time);

            timestamp = &local_time;
        }

        if (sms_mti == SMSLIB_MTI_DELIVER)
        {
            U8 *scts = sms_encode_data->tpdu.data.deliver_tpdu.scts;

            srv_sms_mytime_to_scts(scts, timestamp);
        }

        if (msg_node != NULL)
        {
            temp_timestamp = mmi_dt_mytime_2_utc_sec(timestamp, MMI_FALSE);
        #ifdef __SMS_CLOUD_SUPPORT__
            if(SRV_SMS_CLOUD_ACTION_RESTORE == srv_sms_get_cloud_action_ctnx())
            {
                msg_node->timestamp = temp_timestamp;
            }
            else
            {
                msg_node->timestamp = applib_dt_sec_local_to_utc(temp_timestamp);
            }
        #else
            msg_node->timestamp = applib_dt_sec_local_to_utc(temp_timestamp);
        #endif
        }

        /* Set SCTS (SMS Center Timestamp) */
        if (sms_mti == SMSLIB_MTI_SUBMIT)
        {
            smslib_submit_peer_struct *submit_tpdu;

            submit_tpdu = &sms_encode_data->tpdu.data.submit_tpdu;

            submit_tpdu->vp_flag = SMSLIB_VPF_RELATIVE;
            submit_tpdu->no_validity_period = 1;
    
            if (para_flag & SRV_SMS_PARA_VP)
            {
                *submit_tpdu->validity_period = (U8)msg_data->vp;
            }
            else
            {
                *submit_tpdu->validity_period = (U8)default_setting->vp;
            }
        }

        /* Set TP-PID */
        if (para_flag & SRV_SMS_PARA_PID)
        {
            srv_sms_smslib_set_lib_type(sms_encode_data, (U8)msg_data->pid, SRV_SMS_LIB_TYPE_PID);

            if (msg_node != NULL)
            {
                msg_node->pid = (U8)msg_data->pid;
            }
        }
        else
        {
            if (msg_node != NULL)
            {
                msg_node->pid = SRV_SMS_PID_DEFAULT;
            }
        }

        /* Set Reply Path */
        if (para_flag & SRV_SMS_PARA_REPLY_PATH)
        {
            reply_path = (U8)msg_data->reply_path;
        }
        else
        {
            reply_path = (U8)default_setting->reply_path;
        }
        srv_sms_smslib_set_lib_type(sms_encode_data, reply_path, SRV_SMS_LIB_TYPE_REPLAY_PATH);

        /* Set Status Report */
        if (para_flag & SRV_SMS_PARA_STATUS_REPORT)
        {
            status_report = (U8)msg_data->status_report;
        }
        else
        {
            status_report = (U8)default_setting->status_report;
        }
        srv_sms_smslib_set_lib_type(sms_encode_data, status_report, SRV_SMS_LIB_TYPE_ST_RP);

        srv_sms_smslib_set_lib_type(sms_encode_data, pack_data.ori_dcs, SRV_SMS_LIB_TYPE_DCS);
        srv_sms_smslib_set_lib_type(sms_encode_data, pack_data.udhi, SRV_SMS_LIB_TYPE_UDHI);

        *total_num = pack_data.total_seg;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_PDU_5, *total_num);

        if (msg_node != NULL)
        {
            msg_node->total_seg = pack_data.total_seg;
            msg_node->start_seg = 1;

            if (pack_data.total_seg > 0)
            {
                msg_node->ref_num = srv_sms_get_curr_concat_ref_num();
            }
        }

        if (pdu_list == NULL)
        {
            MMI_ASSERT(get_pdu_list_func != NULL);

            get_pdu_list_func(tmp_pdu_list, pack_data.total_seg, user_data);
        }
        else
        {
            for (i = 0; i < pack_data.total_seg; i++)
            {
                tmp_pdu_list[i] = pdu_list[i];
            }
        }

        for (i = 0; i < pack_data.total_seg; i++)
        {
            U8 pdu_raw_data_size = SRV_SMS_MAX_PDU_SIZE;
            smslib_status_enum encode_result;

            if (para_flag & SRV_SMS_PARA_MSG_REF)
            {
                srv_sms_smslib_set_msg_ref(sms_encode_data, msg_data->msg_ref[i]);
            }

            memcpy(sms_encode_data->forMMI_UserData, pack_data.tpud[i], pack_data.tpud_len[i]);
            sms_encode_data->forMMI_UserData_length = pack_data.tpud_len[i];

            smslib_convert_MMIUserData_to_TPUserData(sms_encode_data);
            encode_result = smslib_encode_pdu(tmp_pdu_list[i], &pdu_raw_data_size, sms_encode_data);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_PDU_6, encode_result);

            if (encode_result == SMSLIB_STATUS_OK)
            {
                pdu_len_list[i] = sms_encode_data->pdu_len;

                /* Reference TS 11.11 Clause 10.5.3 */
                if (sms_encode_data->pdu_len < SRV_SMS_MAX_PDU_SIZE)
                {
                    U8 remain_len = SRV_SMS_MAX_PDU_SIZE - sms_encode_data->pdu_len;

                    memset(tmp_pdu_list[i] + sms_encode_data->pdu_len, 0xFF, remain_len);
                }
            }
            else
            {
                error_cause = SRV_SMS_CAUSE_UNKNOWN_ERROR;
            }
        }
    } while (0);

    if (sms_encode_data != NULL)
    {
        smslib_dealloc_sms_struct(sms_encode_data);
        OslMfree(sms_encode_data);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_MSG_DATA_TO_PDU_6, error_cause);

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_convert_spdu_to_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_convert_spdu_to_msg_data(
            srv_sms_msg_data_struct* msg_data,
            srv_sms_spdu_struct** spdu_list,
            U8 total_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    smslib_general_struct *decode_data;
    srv_sms_unpack_struct unpack_data;
    U32 i;
    U8 first_octet = 0;
    MMI_BOOL is_decoded = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_SPDU_TO_MSG_DATA, msg_data, spdu_list, total_num);

    srv_sms_get_unpack_data(&unpack_data);

    decode_data = (smslib_general_struct*)OslMalloc(sizeof(smslib_general_struct));

    for (i = 0; i < total_num; i++)
    {
        if (spdu_list[i] == NULL)
        {
            unpack_data.tpud[i] = NULL;
            unpack_data.tpud_len[i] = 0;
            unpack_data.dcs[i] = SRV_SMS_DCS_7BIT;
            unpack_data.ori_dcs[i] = SRV_SMS_DCS_7BIT;
        }
        else
        {
            smslib_tpdu_decode_struct *tpdu_data = &decode_data->tpdu;
            smslib_status_enum decode_status;
            U8 *pdu_raw_data = spdu_list[i]->pdu;
            U8 ori_dcs = SRV_SMS_DCS_7BIT;

            memset(decode_data, 0, sizeof(smslib_general_struct));

            decode_status = smslib_decode_pdu(pdu_raw_data, SRV_SMS_MAX_SPDU_SIZE, decode_data);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_SPDU_TO_MSG_DATA_1, decode_status);

            if (decode_status != SMSLIB_STATUS_OK)
            {
                result = MMI_FALSE;
                break;
            }

            smslib_get_msg_content(KAL_FALSE, decode_data, NULL);

            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_SPDU_TO_MSG_DATA_2);

            /* make sure the srv_sms_mti_enum is same as  smslib_mti_enum,
             * otherwise need to convert*/
            msg_data->mti = (srv_sms_mti_enum)tpdu_data->mti;

            unpack_data.dcs[i] = srv_sms_smslib_alphabet_to_dcs(tpdu_data->alphabet_type);

            switch (tpdu_data->mti)
            {
                case SMSLIB_MTI_DELIVER:
                {
                    smslib_deliver_peer_struct *deliver_tpdu = &tpdu_data->data.deliver_tpdu;

                    ori_dcs = deliver_tpdu->dcs;
                    break;
                }

                case SMSLIB_MTI_SUBMIT:
                {
                    smslib_submit_peer_struct *submit_tpdu = &tpdu_data->data.submit_tpdu;

                    ori_dcs = submit_tpdu->dcs;
                    break;
                }

                case SMSLIB_MTI_STATUS_REPORT:
                {
                    smslib_status_report_peer_struct *report_tpdu = &tpdu_data->data.report_tpdu;

                    ori_dcs = report_tpdu->dcs;
                    msg_data->tp_st = report_tpdu->status;
                    break;
                }

                default:
                    MMI_ASSERT(0);
                    break;
            }

            unpack_data.ori_dcs[i] = ori_dcs;

            if (decode_data->forMMI_UserData_length > SRV_SMS_MSG_LEN)
            {
                unpack_data.tpud_len[i] = SRV_SMS_MSG_LEN;
            }
            else
            {
                unpack_data.tpud_len[i] = (U8)decode_data->forMMI_UserData_length;
            }

            memcpy(
                unpack_data.tpud[i],
                decode_data->forMMI_UserData,
                unpack_data.tpud_len[i]);

            if (!is_decoded)
            {
                is_decoded = MMI_TRUE;

                first_octet = decode_data->tpdu.fo;
                srv_sms_decode_data_to_msg_data(
                    msg_data,
                    decode_data);
            }

            smslib_dealloc_sms_struct(decode_data);
        }
    }

    if (result == MMI_TRUE)
    {
        unpack_data.total_seg = total_num;
        unpack_data.fo = first_octet;

        result = srv_sms_unpack_data_to_msg_data(
                    msg_data,
                    &unpack_data);
    }

    OslMfree(decode_data);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_CONVERT_SPDU_TO_MSG_DATA_3, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_info_to_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_msg_info_to_msg_data(
        srv_sms_msg_data_struct* msg_data,
        srv_sms_msg_info_struct* msg_info,
        EMSData* ems_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_para_enum para_flag = (srv_sms_para_enum)msg_data->para_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_INFO_TO_MSG_DATA, para_flag);

    mmi_ucs2cpy(msg_data->number, msg_info->number);

    msg_data->status = msg_info->status;
    msg_data->mti = srv_sms_status_to_mti(msg_info->status);
    msg_data->folder_id = msg_info->folder_id;

    if (para_flag & SRV_SMS_PARA_SIM_ID)
    {
        msg_data->sim_id = msg_info->sim_id;
    }

    if (para_flag & SRV_SMS_PARA_STORAGE_TYPE)
    {
        msg_data->storage_type = msg_info->storage_type;
    }

    if (para_flag & SRV_SMS_PARA_TIMESTAMP)
    {
        memcpy(&msg_data->timestamp, &msg_info->timestamp, sizeof(MYTIME));
    }

    if (para_flag & SRV_SMS_PARA_PID)
    {
        msg_data->pid = msg_info->pid;
    }
#ifndef __ULC_SLIM_EMS__
    if (ems_data->listHead == NULL)
    {
        msg_data->is_with_obj = MMI_FALSE;
    }
    else
    {
        msg_data->is_with_obj = MMI_TRUE;
    }
#endif
    if (para_flag & SRV_SMS_PARA_CONTENT_BUFF)
    {
        if ((msg_data->content_buff != NULL) && 
            (msg_data->content_buff_size > ENCODING_LENGTH))
        {
            U16 content_size = msg_data->content_buff_size - ENCODING_LENGTH;
            
        #ifdef __EMS_NON_STD_7BIT_CHAR__
            if ((ems_data->dcs == SRV_SMS_DCS_7BIT) || (ems_data->dcs == SRV_SMS_DCS_UCS2))
        #else /* __EMS_NON_STD_7BIT_CHAR__ */
            if (ems_data->dcs == SRV_SMS_DCS_7BIT)
        #endif /* __EMS_NON_STD_7BIT_CHAR__ */ 
            {               
                U16 real_len;
            
                real_len = srv_sms_remove_escape_char_ext(
                            msg_data->content_buff,
                            (CHAR*)ems_data->textBuffer,
                            (U16)(content_size / ENCODING_LENGTH),
                            (U16)(ems_data->textLength / ENCODING_LENGTH));

                content_size = real_len * ENCODING_LENGTH;
            }    
            else         
            {
                if (content_size > ems_data->textLength)
                {
                    content_size = ems_data->textLength;
                }

                mmi_ucs2ncpy(msg_data->content_buff, (CHAR*)ems_data->textBuffer, content_size);
			    
            }
            msg_data->content_size = content_size;
            msg_data->content_buff[content_size] = '\0';
            msg_data->content_buff[content_size + 1] = '\0';
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_node_to_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_msg_node_to_msg_data(
        srv_sms_msg_data_struct* msg_data,
        srv_sms_msg_node_struct* msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_para_enum para_flag = (srv_sms_para_enum)msg_data->para_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_asc_to_ucs2(msg_data->number, msg_node->number);

    msg_data->status = (srv_sms_status_enum)msg_node->status;
    msg_data->mti = (srv_sms_mti_enum)msg_node->mti;
    msg_data->folder_id = SRV_SMS_FOLDER_DEFAULT;

    if (para_flag & SRV_SMS_PARA_STORAGE_TYPE)
    {
        msg_data->storage_type = (srv_sms_storage_enum)msg_node->storage_type;
    }

    if (para_flag & SRV_SMS_PARA_SIM_ID)
    {
    #ifdef __SRV_SMS_MULTI_SIM__ 
        msg_data->sim_id = (srv_sms_sim_enum)msg_node->sim_id;
    #else /* __SRV_SMS_MULTI_SIM__ */
        msg_data->sim_id = SRV_SMS_SIM_1;
    #endif /* __SRV_SMS_MULTI_SIM__ */
    }

    if (para_flag & SRV_SMS_PARA_TIMESTAMP)
    {
        mmi_dt_utc_sec_2_mytime(msg_node->timestamp, &msg_data->timestamp, MMI_FALSE);
    }

    if (para_flag & SRV_SMS_PARA_PID)
    {
        msg_data->pid = (srv_sms_pid_enum)msg_node->pid;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_encode_spdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_encode_spdu(
        srv_sms_spdu_struct* spdu_data,
        srv_sms_status_enum status,
        U8* pdu_raw_data,
        U8 raw_data_size,
        srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 remain_data_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ENCODE_SPDU, spdu_data, status);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ENCODE_SPDU_1, pdu_raw_data, raw_data_size, sim_id);

    MMI_ASSERT(raw_data_size <= SRV_SMS_MAX_PDU_SIZE);

    spdu_data->status = (U8)status;

    memcpy(spdu_data->pdu, pdu_raw_data, raw_data_size);

    remain_data_size = SRV_SMS_MAX_PDU_SIZE - raw_data_size;

    if (remain_data_size > 0)
    {
        memset((spdu_data->pdu + raw_data_size), 0xFF, remain_data_size);
    }

    if ((status != SRV_SMS_STATUS_UNREAD) &&
        (status != SRV_SMS_STATUS_READ))
    {
        MYTIME local_time;

        DTGetRTCTime(&local_time);

        spdu_data->timestamp = mmi_dt_mytime_2_utc_sec(&local_time, MMI_FALSE);
    }
    else
    {
        spdu_data->timestamp = 0;
    }

#ifdef __SRV_SMS_MULTI_SIM__
    spdu_data->sim_id = sim_id;
#endif /* __SRV_SMS_MULTI_SIM__ */

#ifdef __SRV_SMS_MULTI_ADDR__
    spdu_data->addr_num = 0;
    spdu_data->start_addr_id = SRV_SMS_INVALID_ADDR_ID;
#endif /*  __SRV_SMS_MULTI_ADDR__*/

#ifdef __SRV_SMS_RESEND_COUNT__
    spdu_data->resend_count = 0;
#endif /* __SRV_SMS_RESEND_COUNT__ */

#ifdef __SRV_SMS_DELIVERY_STATUS__
    if (status == SRV_SMS_STATUS_SENT)
    {
        spdu_data->tp_st = SRV_SMS_SRS_NONE;
    }
    else
    {
        spdu_data->tp_st = SRV_SMS_SRS_INVALID;
    }
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_reset_spdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_reset_spdu(srv_sms_spdu_struct* spdu_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    spdu_data->status = SPDU_STATUS_FREE_SPACE;
    memset(spdu_data->pdu, 0xFF, SRV_SMS_MAX_PDU_SIZE);
    spdu_data->timestamp = 0;
#ifdef __SRV_SMS_MULTI_SIM__
    spdu_data->sim_id = SRV_SMS_SIM_1;
#endif /* __SRV_SMS_MULTI_SIM__ */

#ifdef __SRV_SMS_MULTI_ADDR__
    spdu_data->addr_num = 0;
    spdu_data->start_addr_id = SRV_SMS_INVALID_ADDR_ID;
#endif /*  __SRV_SMS_MULTI_ADDR__*/

#ifdef __SRV_SMS_RESEND_COUNT__
    spdu_data->resend_count = 0;
#endif /* __SRV_SMS_RESEND_COUNT__ */
#ifdef __SRV_SMS_DELIVERY_STATUS__
    spdu_data->tp_st = SRV_SMS_SRS_INVALID;
#endif /* __SRV_SMS_DELIVERY_STATUS__ */
}


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_reset_spdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_reset_tcard_spdu(srv_sms_tcard_spdu_struct* spdu_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    spdu_data->status = SPDU_STATUS_FREE_SPACE;
    memset(spdu_data->pdu, 0xFF, SRV_SMS_MAX_PDU_SIZE);
    spdu_data->timestamp = 0;
    spdu_data->sim_id = SRV_SMS_SIM_1;
    spdu_data->addr_num = 0;
    spdu_data->start_addr_id = SRV_SMS_INVALID_ADDR_ID;
    spdu_data->resend_count = 0;
    spdu_data->tp_st = SRV_SMS_SRS_INVALID;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_info_from_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_get_msg_info_from_pdu(
            srv_sms_msg_node_struct* msg_node,
            U8* curr_seg,
            U8* msg_ref,
            U8* out_pdu_len,
            U8* pdu_raw_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    smslib_general_struct *decode_data;
    smslib_status_enum decode_status;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_INFO_FROM_PDU, msg_node, pdu_raw_data);

    decode_data = OslMalloc(sizeof(smslib_general_struct));

    decode_status = smslib_decode_pdu(pdu_raw_data, SRV_SMS_MAX_PDU_SIZE, decode_data);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_MSG_INFO_FROM_PDU_1, decode_status);

    if (decode_status == SMSLIB_STATUS_OK)
    {
        smslib_get_msg_content(KAL_FALSE, decode_data, NULL);

        srv_sms_decode_data_to_msg_node(msg_node, curr_seg, msg_ref, decode_data);

        *out_pdu_len = decode_data->pdu_len;

        result= MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    smslib_dealloc_sms_struct(decode_data);
    OslMfree(decode_data);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_reply_path_from_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_get_reply_path_from_pdu(
            MMI_BOOL* reply_path,
            char* sc_addr,
            U8* pdu_raw_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    smslib_general_struct *decode_data;
    smslib_status_enum decode_status;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    decode_data = OslMalloc(sizeof(smslib_general_struct));

    decode_status = smslib_decode_pdu(pdu_raw_data, SRV_SMS_MAX_PDU_SIZE, decode_data);

    *reply_path = MMI_FALSE;

    if (decode_status == SMSLIB_STATUS_OK)
    {
        smslib_tpdu_decode_struct *tpdu_data;

        tpdu_data = &decode_data->tpdu;

        /* Get Other Parameter */
        switch (tpdu_data->mti)
        {
            case SMSLIB_MTI_DELIVER:
            {
                smslib_deliver_peer_struct *deliver_tpdu = &tpdu_data->data.deliver_tpdu;

                *reply_path = (MMI_BOOL)deliver_tpdu->reply_flag;
                break;
            }

            case SMSLIB_MTI_SUBMIT:
            {
                smslib_submit_peer_struct *submit_tpdu = &tpdu_data->data.submit_tpdu;

                *reply_path = (MMI_BOOL)submit_tpdu->reply_flag;
                break;
            }

            default:
                break;
        }

        /* Message Address */
        srv_sms_l4_number_to_asc_addr(
            sc_addr,
            SRV_SMS_MAX_ADDR_LEN,
            &decode_data->forMMI_SCAAddr);
    }
    else
    {
        sc_addr[0] = '\0';

        result = MMI_FALSE;
    }

    smslib_dealloc_sms_struct(decode_data);
    OslMfree(decode_data);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_decode_data_to_msg_node
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_decode_data_to_msg_node(
        srv_sms_msg_node_struct* msg_node,
        U8 *curr_seg,
        U8 *msg_ref,
        smslib_general_struct* decode_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    smslib_concat_struct *concat_info;
    smslib_tpdu_decode_struct *tpdu_data;
    U8 pid = 0;
    U32 timestamp = 0;
#if (defined(__SRV_SMS_MSG_INFO_DCS__) || defined(__SRV_SMS_MSG_INFO_CONTENT__))
    srv_sms_dcs_enum dcs;
#endif /* (defined(__SRV_SMS_MSG_INFO_DCS__) || defined(__SRV_SMS_MSG_INFO_CONTENT__)) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_DECODE_DATA_TO_MSG_NODE, msg_node, decode_data);

    tpdu_data = &decode_data->tpdu;
    concat_info = &tpdu_data->concat_info;

    /* Message Address */
    srv_sms_l4_number_to_asc_addr(
        msg_node->number,
        SRV_SMS_MAX_ADDR_LEN,
        &decode_data->forMMI_TPAddr);

    /* Concatenated Information */
    msg_node->ref_num = concat_info->ref;

    srv_sms_convert_segment(
        &msg_node->total_seg,
        &msg_node->start_seg,
        curr_seg,
        concat_info->total_seg,
        concat_info->seg);

    /* Message reference */
    *msg_ref = 0;

    /* MTI */
    msg_node->mti = tpdu_data->mti;

    /* Get PID TimeStamp */
    switch (tpdu_data->mti)
    {
        case SMSLIB_MTI_DELIVER:
        {
            smslib_deliver_peer_struct *deliver_tpdu = &tpdu_data->data.deliver_tpdu;

            pid = deliver_tpdu->pid;
            timestamp = srv_sms_scts_to_utc_sec(deliver_tpdu->scts);
            break;
        }

        case SMSLIB_MTI_SUBMIT:
        {
            smslib_submit_peer_struct *submit_tpdu = &tpdu_data->data.submit_tpdu;

            pid = submit_tpdu->pid;
            *msg_ref = submit_tpdu->msg_ref;
            break;
        }

        case SMSLIB_MTI_STATUS_REPORT:
        {
            smslib_status_report_peer_struct *report_tpdu = &tpdu_data->data.report_tpdu;

            pid = report_tpdu->pid;
            timestamp = srv_sms_scts_to_utc_sec(report_tpdu->scts);
            break;
        }

        default:
            MMI_ASSERT(0);
            break;
    }

    /* PID */
    msg_node->pid = pid;

    /* Timestamp */
    msg_node->timestamp = timestamp;

#if (defined(__SRV_SMS_MSG_INFO_DCS__) || defined(__SRV_SMS_MSG_INFO_CONTENT__))
    dcs = srv_sms_smslib_alphabet_to_dcs(tpdu_data->alphabet_type);
#endif /* (defined(__SRV_SMS_MSG_INFO_DCS__) || defined(__SRV_SMS_MSG_INFO_CONTENT__)) */

#ifdef __SRV_SMS_MSG_INFO_PORT__
    msg_node->port_num = tpdu_data->port.dest_port;
#endif /* __SRV_SMS_MSG_INFO_PORT__ */

    /* DCS */
#ifdef __SRV_SMS_MSG_INFO_DCS__
    msg_node->dcs = (U8)dcs;
#endif /* __SRV_SMS_MSG_INFO_DCS__ */

    /* Check Whether it is unsupported Msg */
    if ((tpdu_data->is_compress) ||
        ((tpdu_data->port.dest_port == 0x1581) || (tpdu_data->port.dest_port == 0x158A) ||
         (tpdu_data->port.dest_port == 0x1582) || (tpdu_data->port.dest_port == 0x1583))
    #ifdef __SRV_SMS_NOT_DISPLAY_8BIT_CONTENT_SUPPORT__
        || (tpdu_data->alphabet_type == SMSLIB_EIGHT_BIT)
    #endif /* __SRV_SMS_NOT_DISPLAY_8BIT_CONTENT_SUPPORT__ */ 
       )
    {
        msg_node->status |= SRV_SMS_STATUS_UNSUPPORTED;
    }

#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    {
        srv_sms_get_content_from_tpud(
            (U8*)msg_node->content,
            (U16)(SRV_SMS_MSG_INFO_CONTENT_LEN * ENCODING_LENGTH),
            tpdu_data->fo,
            (U8)dcs,
            decode_data->forMMI_UserData,
            (U8)decode_data->forMMI_UserData_length);
    }
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_convert_segment
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_convert_segment(
        U8 *dest_total_seg,
        U8 *dest_start_seg,
        U8 *dest_curr_seg,
        U8 src_total_seg,
        U8 src_curr_seg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((src_curr_seg > src_total_seg) ||
        (src_curr_seg == 0) || (src_total_seg == 0))
    {
        *dest_total_seg = 1;
        *dest_start_seg = 1;
        *dest_curr_seg = 1;
    }
    else
    {
        *dest_total_seg = src_total_seg;

        if (src_curr_seg > SRV_SMS_MAX_SEG)
        {
            U8 this_seg;

            *dest_start_seg = (((src_curr_seg - 1) / SRV_SMS_MAX_SEG) * SRV_SMS_MAX_SEG) + 1;

            this_seg = src_curr_seg % SRV_SMS_MAX_SEG;

            if (this_seg == 0)
            {
                *dest_curr_seg = SRV_SMS_MAX_SEG;
            }
            else
            {
                *dest_curr_seg = this_seg;
            }
        }
        else
        {
            *dest_start_seg = 1;
            *dest_curr_seg = src_curr_seg;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_msg_node_to_msg_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_msg_node_to_msg_info(
        srv_sms_msg_info_struct* msg_info,
        srv_sms_msg_node_struct* msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_NODE_TO_MSG_INFO, msg_info, msg_node);

    msg_info->status = (srv_sms_status_enum)msg_node->status;
    msg_info->storage_type = (srv_sms_storage_enum)msg_node->storage_type;

    mmi_dt_utc_sec_2_mytime(msg_node->timestamp, &msg_info->timestamp, MMI_FALSE);

    mmi_asc_to_ucs2(msg_info->number, msg_node->number);

    msg_info->folder_id = SRV_SMS_FOLDER_DEFAULT;
    msg_info->pid = (srv_sms_pid_enum)msg_node->pid;
#ifdef __SRV_SMS_MULTI_SIM__ 
    msg_info->sim_id = (srv_sms_sim_enum)msg_node->sim_id;
#else /* __SRV_SMS_MULTI_SIM__ */
    msg_info->sim_id = SRV_SMS_SIM_1;
#endif /* __SRV_SMS_MULTI_SIM__ */
#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    mmi_ucs2cpy(msg_info->content, (S8*)msg_node->content);
#else /* __SRV_SMS_MSG_INFO_CONTENT__ */
    memset(msg_info->content, 0, ENCODING_LENGTH);
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */
}

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_tcard_msg_node_to_msg_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_tcard_msg_node_to_msg_info(
        srv_sms_msg_info_struct* msg_info,
        srv_sms_tcard_msg_node_struct* msg_node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MSG_NODE_TO_MSG_INFO, msg_info, msg_node);

    msg_info->status = (srv_sms_status_enum)msg_node->status;
    msg_info->storage_type = (srv_sms_storage_enum)msg_node->storage_type;

    mmi_dt_utc_sec_2_mytime(msg_node->timestamp, &msg_info->timestamp, MMI_FALSE);

    mmi_asc_to_ucs2(msg_info->number, msg_node->number);

    msg_info->folder_id = SRV_SMS_FOLDER_DEFAULT;
    msg_info->pid = (srv_sms_pid_enum)msg_node->pid;
#ifdef __SRV_SMS_MULTI_SIM__ 
    msg_info->sim_id = (srv_sms_sim_enum)msg_node->sim_id;
#else /* __SRV_SMS_MULTI_SIM__ */
    msg_info->sim_id = SRV_SMS_SIM_1;
#endif /* __SRV_SMS_MULTI_SIM__ */
#ifdef __SRV_SMS_MSG_INFO_CONTENT__
    mmi_ucs2cpy(msg_info->content, (S8*)msg_node->content);
#else /* __SRV_SMS_MSG_INFO_CONTENT__ */
    memset(msg_info->content, 0, ENCODING_LENGTH);
#endif /* __SRV_SMS_MSG_INFO_CONTENT__ */
}

#endif
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_content_from_pdu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_get_content_from_pdu(
            char* content_buff,
            U32 content_buff_size,
            U8* pdu_raw_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    smslib_general_struct *decode_data;
    smslib_status_enum decode_status;
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_CONTENT_FROM_PDU, content_buff, content_buff_size, pdu_raw_data);

    decode_data = OslMalloc(sizeof(smslib_general_struct));

    decode_status = smslib_decode_pdu(pdu_raw_data, SRV_SMS_MAX_PDU_SIZE, decode_data);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_CONTENT_FROM_PDU_1, decode_status);

    if (decode_status == SMSLIB_STATUS_OK)
    {
        smslib_tpdu_decode_struct *tpdu_data;
        srv_sms_dcs_enum dcs;

        smslib_get_msg_content(KAL_FALSE, decode_data, NULL);

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_GET_CONTENT_FROM_PDU_2);

        tpdu_data = &decode_data->tpdu;

        dcs = srv_sms_smslib_alphabet_to_dcs(tpdu_data->alphabet_type);

        srv_sms_get_content_from_tpud(
            (U8*)content_buff,
            (U16)content_buff_size,
            tpdu_data->fo,
            (U8)dcs,
            decode_data->forMMI_UserData,
            (U8)decode_data->forMMI_UserData_length);

        result= MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    smslib_dealloc_sms_struct(decode_data);
    OslMfree(decode_data);

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_pack_msg_data
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_pack_msg_data(
                            srv_sms_pack_struct *pack_data,
                            srv_sms_msg_node_struct* msg_node,
                            srv_sms_int_msg_data_struct* msg_data,
                            srv_sms_pack_enum pack_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_para_enum para_flag = msg_data->para_flag;
    EMSData *int_ems_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PACK_MSG_DATA, pack_data, msg_node, msg_data);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PACK_MSG_DATA_1, SRV_SMS_MAX_SEND_SEG, pack_flag);

    do
    {
        EMSData *pack_ems_data;

        if ((para_flag & SRV_SMS_PARA_CONTENT_BUFF) ||
            (para_flag & SRV_SMS_PARA_CONTENT_FILE))
        {
            int_ems_data = srv_sms_malloc_ems_data();
        
            error_cause = srv_sms_convert_msg_data_to_ems(
                            int_ems_data,
                            msg_data);

            if (error_cause != SRV_SMS_CAUSE_NO_ERROR)
            {
                break;
            }

            pack_ems_data = int_ems_data;
        }
        else
        {
            pack_ems_data = msg_data->content_ems;
        }

        if (pack_ems_data != NULL)
        {
            EMSTATUS ems_result;

            if (msg_node != NULL)
            {
            #ifdef __SRV_SMS_MSG_INFO_DCS__
                msg_node->dcs = pack_ems_data->dcs;
            #endif /* __SRV_SMS_MSG_INFO_DCS__ */

            #ifdef __SRV_SMS_NOT_DISPLAY_8BIT_CONTENT_SUPPORT__
                if (pack_ems_data->dcs == SRV_SMS_DCS_8BIT)
                {
                    msg_node->status |= SRV_SMS_STATUS_UNSUPPORTED;
                }
            #endif /* __SRV_SMS_NOT_DISPLAY_8BIT_CONTENT_SUPPORT__ */ 

            #ifdef __SRV_SMS_MSG_INFO_CONTENT__
            #ifdef __EMS_NON_STD_7BIT_CHAR__
                if ((pack_ems_data->dcs == SRV_SMS_DCS_7BIT) || (pack_ems_data->dcs == SRV_SMS_DCS_UCS2))
            #else /* __EMS_NON_STD_7BIT_CHAR__ */
                if (pack_ems_data->dcs == SRV_SMS_DCS_7BIT)
            #endif /* __EMS_NON_STD_7BIT_CHAR__ */ 
                {           
                    srv_sms_remove_escape_char_ext(
                        (S8*)msg_node->content,
                        (S8*)pack_ems_data->textBuffer,
                        (U16)SRV_SMS_MSG_INFO_CONTENT_LEN,
                        (U16)(pack_ems_data->textLength / ENCODING_LENGTH));
                }
                else
                {
                    mmi_ucs2ncpy((S8*)msg_node->content, (S8*)pack_ems_data->textBuffer, SRV_SMS_MSG_INFO_CONTENT_LEN);
                    msg_node->content[SRV_SMS_MSG_INFO_CONTENT_LEN] = '\0';
                }
            #endif /* __SRV_SMS_MSG_INFO_CONTENT__ */
            }

            ems_result = srv_sms_pack_ems(pack_data, pack_ems_data, pack_flag);

            error_cause = srv_sms_ems_status_to_cause(ems_result);
        }
    } while (0);

    if (int_ems_data != NULL)
    {
        srv_sms_free_ems_data(int_ems_data);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_PACK_MSG_DATA_2, error_cause);

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_smslib_set_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_smslib_set_sc_addr(
                smslib_general_struct *sms_encode_data,
                char* ucs2_sc_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4c_number_struct l4c_numer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SMSLIB_SET_SC_ADDR);

    srv_sms_ucs2_addr_to_l4_number(&l4c_numer, ucs2_sc_addr);
    smslib_convert_MMI_to_RP(&l4c_numer, &sms_encode_data->sca);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_smslib_set_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_smslib_set_number(
                smslib_general_struct *sms_encode_data,
                char* ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SMSLIB_SET_NUMBER);

    switch (sms_encode_data->tpdu.mti)
    {
        case SMSLIB_MTI_DELIVER:
        {
            smslib_deliver_peer_struct *deliver_tpdu;

            deliver_tpdu = &sms_encode_data->tpdu.data.deliver_tpdu;

            srv_sms_ucs2_addr_to_tp_addr(
                deliver_tpdu->orig_addr,
                &deliver_tpdu->no_orig_addr,
                ucs2_addr);
            break;
        }

        case SMSLIB_MTI_SUBMIT:
        {
            smslib_submit_peer_struct *submit_tpdu;

            submit_tpdu = &sms_encode_data->tpdu.data.submit_tpdu;

            srv_sms_ucs2_addr_to_tp_addr(
                submit_tpdu->dest_addr,
                &submit_tpdu->no_dest_addr,
                ucs2_addr);
            break;
        }

        default:
            MMI_ASSERT(0);
            break;
    }
}

static void srv_sms_smslib_set_lib_type(
                smslib_general_struct *sms_encode_data,
                U8 num,
                srv_sms_lib_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (sms_encode_data->tpdu.mti)
    {
        case SMSLIB_MTI_DELIVER:
        {
            smslib_deliver_peer_struct *deliver_tpdu;

            deliver_tpdu = &sms_encode_data->tpdu.data.deliver_tpdu;
            if(type == SRV_SMS_LIB_TYPE_REPLAY_PATH)
                deliver_tpdu->reply_flag = num;
            else if(type == SRV_SMS_LIB_TYPE_PID)
                deliver_tpdu->pid = num;
            else if(type == SRV_SMS_LIB_TYPE_DCS)
                deliver_tpdu->dcs = num;
            else if(type == SRV_SMS_LIB_TYPE_UDHI)
                deliver_tpdu->udh_p = num;
            else
                deliver_tpdu->status_rep_flag = num;
            break;
        }

        case SMSLIB_MTI_SUBMIT:
        {
            smslib_submit_peer_struct *submit_tpdu;

            submit_tpdu = &sms_encode_data->tpdu.data.submit_tpdu;

            if(type == SRV_SMS_LIB_TYPE_REPLAY_PATH)
                submit_tpdu->reply_flag = num;
            else if(type == SRV_SMS_LIB_TYPE_PID)
                submit_tpdu->pid = num;
            else if(type == SRV_SMS_LIB_TYPE_DCS)
                submit_tpdu->dcs = num;
            else if(type == SRV_SMS_LIB_TYPE_UDHI)
                submit_tpdu->udh_p = num;
            else
                submit_tpdu->status_rep_flag = num;
            break;
        }

        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_smslib_set_reply_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/



/*****************************************************************************
 * FUNCTION
 *  srv_sms_smslib_set_msg_ref
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_smslib_set_msg_ref(
                smslib_general_struct *sms_encode_data,
                U8 msg_ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sms_encode_data->tpdu.mti == SMSLIB_MTI_SUBMIT)
    {
        smslib_submit_peer_struct *submit_tpdu;

        submit_tpdu = &sms_encode_data->tpdu.data.submit_tpdu;

        submit_tpdu->msg_ref = msg_ref;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_ucs2_addr_to_tp_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_ucs2_addr_to_tp_addr(U8 *tp_addr, U8 *tp_addr_len, char* ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    l4c_number_struct l4c_numer;
    l4_addr_bcd_struct l4c_bcd_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UCS2_ADDR_TO_TP_ADDR);

    srv_sms_ucs2_addr_to_l4_number(&l4c_numer, ucs2_addr);
    smslib_convert_MMI_to_RP(&l4c_numer, &l4c_bcd_addr);
    smslib_convert_RP_to_TPAddr(&l4c_bcd_addr, tp_addr_len, tp_addr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_ucs2_addr_to_l4_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_ucs2_addr_to_l4_number(l4c_number_struct *l4c_number, char* ucs2_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_UCS2_ADDR_TO_L4_NUMBER);

    if ((ucs2_addr == NULL) || ((ucs2_addr[0] == '\0') && (ucs2_addr[1] == '\0')))
    {
        l4c_number->type = CSMCC_DEFAULT_ADDR_TYPE;
        l4c_number->length = 0;
        l4c_number->number[0] = '\0';
    }
    else
    {
        U16 first_char;
        S8 *ucs2_num = ucs2_addr;
        U8 digit_len;

        memcpy(&first_char, ucs2_num, ENCODING_LENGTH);

        if (first_char == '+')
        {
            l4c_number->type = CSMCC_INTERNATIONAL_ADDR;
            ucs2_num += ENCODING_LENGTH;
        }
        else
        {
            l4c_number->type = CSMCC_DEFAULT_ADDR_TYPE;
        }

        digit_len = mmi_ucs2strlen(ucs2_num);

        if (digit_len > (MAX_CC_ADDR_LEN - 1))
        {
            digit_len = MAX_CC_ADDR_LEN - 1;
        }

        l4c_number->length = digit_len;

        mmi_ucs2_to_asc((S8*)l4c_number->number, ucs2_num);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_asc_addr_to_l4_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_asc_addr_to_l4_number(l4c_number_struct *l4c_number, U8* asc_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_ASC_ADDR_TO_L4_NUMBER, asc_addr);

    if ((asc_addr == NULL) || (asc_addr[0] == '\0'))
    {
        l4c_number->type = CSMCC_DEFAULT_ADDR_TYPE;
        l4c_number->length = 0;
        l4c_number->number[0] = '\0';
    }
    else
    {
        U8 *asc_num = asc_addr;
        U8 digit_len;

        if (asc_addr[0] == '+')
        {
            l4c_number->type = CSMCC_INTERNATIONAL_ADDR;
            asc_num++;
        }
        else
        {
            l4c_number->type = CSMCC_DEFAULT_ADDR_TYPE;
        }

        digit_len = (U8)strlen((S8*)asc_num);

        if (digit_len > (MAX_CC_ADDR_LEN - 1))
        {
            digit_len = MAX_CC_ADDR_LEN - 1;
        }

        l4c_number->length = digit_len;

        memcpy(l4c_number->number, asc_num, digit_len);
        l4c_number->number[digit_len] = '\0'; 
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_l4_number_to_asc_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_l4_number_to_asc_addr(char* asc_addr, U8 max_addr_len, l4c_number_struct *l4c_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 *digit_str = asc_addr;
    U8 digit_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_L4_NUMBER_TO_ASC_ADDR);

    if ((l4c_number->type == CSMCC_INTERNATIONAL_ADDR) ||
        ((l4c_number->type & 0xf0) == 0x90))
    {
        asc_addr[0] = '+';
        digit_str++;
    }

    if (l4c_number->length > (max_addr_len - 1))
    {
        digit_len = max_addr_len - 1;
    }
    else
    {
        digit_len = l4c_number->length;
    }

    memcpy(digit_str, l4c_number->number, digit_len);
    digit_str[digit_len] = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_ems_status_to_cause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_sms_cause_enum srv_sms_ems_status_to_cause(EMSTATUS ems_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum error_cause;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_EMS_STATUS_TO_CAUSE, ems_result);

    switch (ems_result)
    {
        case EMS_OK:
            error_cause = SRV_SMS_CAUSE_NO_ERROR;
            break;

        case EMS_EMS_DATA_EXCEEDED:
            error_cause = SRV_SMS_CAUSE_DATA_EXCEED;
            break;

        case EMS_INVALID_EMS_DATA:
            error_cause = SRV_SMS_CAUSE_DATA_INVALID;
            break;

        default:
            error_cause = SRV_SMS_CAUSE_UNKNOWN_ERROR;
            break;
    }

    return error_cause;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_ems_status_to_cause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_dcs_enum srv_sms_smslib_alphabet_to_dcs(smslib_alphabet_enum alphabet_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_dcs_enum dcs;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SMSLIB_ALPHABET_TO_DCS, alphabet_type);

    switch (alphabet_type)
    {
        case SMSLIB_GSM7_BIT:
            dcs = SRV_SMS_DCS_7BIT;
            break;

        case SMSLIB_EIGHT_BIT:
            dcs = SRV_SMS_DCS_8BIT;
            break;

        case SMSLIB_UCS2:
            dcs = SRV_SMS_DCS_UCS2;
            break;

        case SMSLIB_ALPHABET_UNSPECIFIED:
        default:
            dcs = SRV_SMS_DCS_RESERVED;
            break;
    }
    return dcs;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_status_to_mti
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_sms_mti_enum srv_sms_status_to_mti(srv_sms_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_mti_enum mti;
    srv_sms_status_enum msg_status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_STATUS_TO_MTI, status);

    msg_status = (srv_sms_status_enum)(status & (~SRV_SMS_STATUS_UNSUPPORTED));

    switch (msg_status)
    {
        case SRV_SMS_STATUS_UNREAD:
        case SRV_SMS_STATUS_READ:
            mti = SRV_SMS_MTI_DELIVER;
            break;

        case SRV_SMS_STATUS_SENT:
        case SRV_SMS_STATUS_UNSENT:
        case SRV_SMS_STATUS_DRAFT:
            mti = SRV_SMS_MTI_SUBMIT;
            break;

        default:
            mti = SRV_SMS_MTI_RESERVED;
            break;
    }

    return mti;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_decode_data_to_msg_data
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_decode_data_to_msg_data(
                srv_sms_msg_data_struct* msg_data,
                smslib_general_struct* decode_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_para_enum para_flag = (srv_sms_para_enum)msg_data->para_flag;
    smslib_tpdu_decode_struct *tpdu_data;
    U8 pid = SRV_SMS_PID_DEFAULT;
    U32 timestamp = 0;
    U8 vp = SRV_SMS_VP_MAX;
    U8 status_report = MMI_FALSE;
    U8 reply_path = MMI_FALSE;
    S8 tmp_asc_addr[SRV_SMS_MAX_ADDR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tpdu_data = &decode_data->tpdu;

    /* Check whether it is Unsupported SMS */
    if ((tpdu_data->is_compress) ||
        ((tpdu_data->port.dest_port == 0x1581) || (tpdu_data->port.dest_port == 0x158A) ||
         (tpdu_data->port.dest_port == 0x1582) || (tpdu_data->port.dest_port == 0x1583))
    #ifdef __SRV_SMS_NOT_DISPLAY_8BIT_CONTENT_SUPPORT__
        || (tpdu_data->alphabet_type == SMSLIB_EIGHT_BIT)
    #endif /* __SRV_SMS_NOT_DISPLAY_8BIT_CONTENT_SUPPORT__ */ 
       )
    {
        msg_data->status |= SRV_SMS_STATUS_UNSUPPORTED;
    }

    /* Message Address */
    srv_sms_l4_number_to_asc_addr(
        tmp_asc_addr,
        SRV_SMS_MAX_ADDR_LEN,
        &decode_data->forMMI_TPAddr);

    mmi_asc_to_ucs2(msg_data->number, tmp_asc_addr);

    /* MTI */
    msg_data->mti = (srv_sms_mti_enum)tpdu_data->mti;

    /* Get Other Parameter */
    switch (tpdu_data->mti)
    {
        case SMSLIB_MTI_DELIVER:
        {
            smslib_deliver_peer_struct *deliver_tpdu = &tpdu_data->data.deliver_tpdu;

            pid = deliver_tpdu->pid;
            timestamp = srv_sms_scts_to_utc_sec(deliver_tpdu->scts);
            status_report = (MMI_BOOL)deliver_tpdu->status_rep_flag;
            reply_path = (MMI_BOOL)deliver_tpdu->reply_flag;
            break;
        }

        case SMSLIB_MTI_SUBMIT:
        {
            smslib_submit_peer_struct *submit_tpdu = &tpdu_data->data.submit_tpdu;

            pid = submit_tpdu->pid;
            status_report = (MMI_BOOL)submit_tpdu->status_rep_flag;
            reply_path = (MMI_BOOL)submit_tpdu->reply_flag;

            if ((submit_tpdu->vp_flag == SMSLIB_VPF_ABSOLUTE) && 
                (submit_tpdu->no_validity_period == 1))
            {
                vp = *submit_tpdu->validity_period;
            }
            break;
        }

        case SMSLIB_MTI_STATUS_REPORT:
        {
            smslib_status_report_peer_struct *report_tpdu = &tpdu_data->data.report_tpdu;

            pid = report_tpdu->pid;
            timestamp = srv_sms_scts_to_utc_sec(report_tpdu->scts);
            msg_data->tp_st = report_tpdu->status;
            break;
        }

        default:
            break;
    }

    /* Timestamp */
    if (para_flag & SRV_SMS_PARA_TIMESTAMP)
    {
        mmi_dt_utc_sec_2_mytime(timestamp, &msg_data->timestamp, MMI_FALSE);
    }

    /* SC Address */
    if (para_flag & SRV_SMS_PARA_SCA)
    {
        /* Message Address */
        srv_sms_l4_number_to_asc_addr(
            tmp_asc_addr,
            SRV_SMS_MAX_ADDR_LEN,
            &decode_data->forMMI_SCAAddr);

        mmi_asc_to_ucs2(msg_data->sc_address, tmp_asc_addr);
    }

    /* PID */
    if (para_flag & SRV_SMS_PARA_PID)
    {
        msg_data->pid = (srv_sms_pid_enum)pid;
    }

    /* VP */
    if (para_flag & SRV_SMS_PARA_VP)
    {
        msg_data->vp = (srv_sms_vp_enum)vp;
    }

    /* Status Report Flag */
    if (para_flag & SRV_SMS_PARA_STATUS_REPORT)
    {
        msg_data->status_report = (MMI_BOOL)status_report;
    }
    
    /* Reply Path Flag */
    if (para_flag & SRV_SMS_PARA_REPLY_PATH)
    {
        msg_data->reply_path = (MMI_BOOL)reply_path;
    }

    /* Port Numer */
   if (para_flag & SRV_SMS_PARA_PORT)
    {
        msg_data->src_port = tpdu_data->port.src_port;
        msg_data->dest_port = tpdu_data->port.dest_port;
    }

    /* DCS */
    if (para_flag & SRV_SMS_PARA_DCS)
    {
        msg_data->dcs = srv_sms_smslib_alphabet_to_dcs(tpdu_data->alphabet_type);
    }

    /* Message Class */
    if (para_flag & SRV_SMS_PARA_CLASS)
    {
        /* Make sure the defination is same as smslib_msg_class_enum  */
        msg_data->msg_class = (srv_sms_class_enum)tpdu_data->msg_class;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_unpack_data_to_msg_data
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_unpack_data_to_msg_data(
                    srv_sms_msg_data_struct* msg_data,
                    srv_sms_unpack_struct* unpack_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    EMSData *unpack_ems_data;
    EMSData *int_ems_data = NULL;
    srv_sms_para_enum para_flag = (srv_sms_para_enum)msg_data->para_flag;
    srv_sms_unpack_enum unpack_flag = SRV_SMS_UNPACK_REPLACE_END_CHAR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Get EMSData */
    if (para_flag & SRV_SMS_PARA_CONTENT_EMS)
    {
        unpack_ems_data = msg_data->content_ems;
        srv_sms_reset_ems_data(unpack_ems_data);
    }
    else
    {
        int_ems_data = srv_sms_malloc_ems_data();
        unpack_ems_data = int_ems_data;
    }

    MMI_ASSERT(unpack_ems_data != NULL);

    if (para_flag & SRV_SMS_PARA_ORI_8BIT_DATA)
    {
        unpack_flag |= SRV_SMS_UNPACK_ORI_8BIT_DATA;
    }

    /* Unpack TPUD to EMSData */
    srv_sms_unpack_ems(
        unpack_ems_data,
        unpack_data,
        unpack_flag);
#ifndef __ULC_SLIM_EMS__
    if (unpack_ems_data->listHead == NULL)
    {
        msg_data->is_with_obj = MMI_FALSE;
    }
    else
    {
        msg_data->is_with_obj = MMI_TRUE;
    }
#endif
    msg_data->dcs = (srv_sms_dcs_enum)unpack_ems_data->dcs;

    if (para_flag & SRV_SMS_PARA_CONTENT_FILE)
    {
        S32 fs_error;
        S32 write_result;

        write_result = srv_sms_write_ems_data_to_file(
                        msg_data->content_file_path,
                        unpack_ems_data,
                        &fs_error);

        if (write_result < 0)
        {
            result = MMI_FALSE;
        }
    }
    else if (para_flag & SRV_SMS_PARA_CONTENT_BUFF)
    {
        if ((msg_data->content_buff != NULL) && 
            (msg_data->content_buff_size > ENCODING_LENGTH))
        {
            U16 content_size = msg_data->content_buff_size - ENCODING_LENGTH;

        #ifdef __EMS_NON_STD_7BIT_CHAR__
            if ((unpack_ems_data->dcs == SRV_SMS_DCS_7BIT) || (unpack_ems_data->dcs == SRV_SMS_DCS_UCS2))
        #else /* __EMS_NON_STD_7BIT_CHAR__ */
            if (unpack_ems_data->dcs == SRV_SMS_DCS_7BIT)
        #endif /* __EMS_NON_STD_7BIT_CHAR__ */ 
            {
                U16 real_len;
            
                real_len = srv_sms_remove_escape_char_ext(
                                msg_data->content_buff,
                                (S8*)unpack_ems_data->textBuffer,
                                (U16)(content_size / ENCODING_LENGTH),
                                (U16)(unpack_ems_data->textLength / ENCODING_LENGTH));

                content_size = real_len * ENCODING_LENGTH;
            }
            else
            {
                if (content_size > unpack_ems_data->textLength)
                {
                    content_size = unpack_ems_data->textLength;
                }

                memcpy(msg_data->content_buff, unpack_ems_data->textBuffer, content_size);
                msg_data->content_buff[content_size] = '\0';
                msg_data->content_buff[content_size + 1] = '\0';
            }

            msg_data->content_size = content_size;
        }
    }

    if (int_ems_data != NULL)
    {
        srv_sms_free_ems_data(int_ems_data);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_pdu_msg_ref
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_set_pdu_msg_ref(U8* pdu_data, U8 msg_ref)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sc_field_len = pdu_data[0] + PDU_SCA_LEN_FIELD_SIZE;
    U32 msg_ref_offset = sc_field_len + TPDU_MSG_REF_OFFSET;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    pdu_data[msg_ref_offset] = msg_ref;
}

#endif /* __MOD_SMSAL__ */

