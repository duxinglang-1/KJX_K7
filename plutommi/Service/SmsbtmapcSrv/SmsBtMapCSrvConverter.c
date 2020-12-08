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
 *
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

#include "mmi_common_app_trc.h"
#include "SmsSrvGProt.h"
#include "SmsBtMapCSrvGProt.h"
#include "SmsBtMapCSrvProt.h"
#include "SmsBtMapCSrvConverter.h"
#include "Smslib.h"
#include "ps_public_utility.h"
#include "ems.h"
#ifdef __SRV_SMS_BTMAPC__


/**************************************************************
* MARCO
**************************************************************/

/**************************************************************
* Static Function Declaration
**************************************************************/
__inline static U8 srv_sms_btmapc_semi_octet_to_digit(U8 semi_octet);
__inline static U8 srv_sms_btmapc_digit_to_semi_octet(U8 digit);

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
U32 srv_sms_btmapc_scts_to_utc_sec(U8 scts[])
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

    srv_sms_btmapc_scts_to_mytime(&mytime, scts);

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
    time_zone = srv_sms_btmapc_semi_octet_to_digit(temp_time_zone);
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
void srv_sms_btmapc_utc_sec_to_scts(U8 scts[], U32 utc_sec)
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
    srv_sms_btmapc_mytime_to_scts(scts, &mytime);
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
void srv_sms_btmapc_scts_to_mytime(MYTIME* mytime, U8 scts[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 month;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SCTS_TO_MYTIME);

    month = srv_sms_btmapc_semi_octet_to_digit(scts[1]);

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
        mytime->nYear = srv_sms_btmapc_semi_octet_to_digit(scts[0]) + 2000;

        if (mytime->nYear > 2090)
        {
            mytime->nYear = mytime->nYear - 100;
        }

        mytime->nMonth = month;
        mytime->nDay   = srv_sms_btmapc_semi_octet_to_digit(scts[2]);
        mytime->nHour  = srv_sms_btmapc_semi_octet_to_digit(scts[3]);
        mytime->nMin   = srv_sms_btmapc_semi_octet_to_digit(scts[4]);
        mytime->nSec   = srv_sms_btmapc_semi_octet_to_digit(scts[5]);
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
void srv_sms_btmapc_mytime_to_scts(U8 scts[], MYTIME* mytime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_MYTIME_TO_SCTS);

    scts[0] = srv_sms_btmapc_digit_to_semi_octet((U8)(mytime->nYear % 100));
    scts[1] = srv_sms_btmapc_digit_to_semi_octet(mytime->nMonth);
    scts[2] = srv_sms_btmapc_digit_to_semi_octet(mytime->nDay);
    scts[3] = srv_sms_btmapc_digit_to_semi_octet(mytime->nHour);
    scts[4] = srv_sms_btmapc_digit_to_semi_octet(mytime->nMin);
    scts[5] = srv_sms_btmapc_digit_to_semi_octet(mytime->nSec);
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
__inline static U8 srv_sms_btmapc_semi_octet_to_digit(U8 semi_octet)
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
__inline static U8 srv_sms_btmapc_digit_to_semi_octet(U8 digit)
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
 *  srv_sms_msg_node_to_msg_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_btmapc_msg_node_to_msg_data(
        srv_sms_msg_data_struct* msg_data,
        srv_sms_btmapc_msg_node_struct* msg_node)
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
 *  srv_sms_msg_node_to_msg_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_btmapc_msg_node_to_msg_info(
        srv_sms_msg_info_struct* msg_info,
        srv_sms_btmapc_msg_node_struct* msg_node)
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
    mmi_ucs2cpy(msg_info->content, (S8*)msg_node->content);
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
srv_sms_mti_enum srv_sms_btmapc_status_to_mti(srv_sms_status_enum status)
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


#endif /* __SRV_SMS_BTMAPC__ */
#endif /* __MOD_SMSAL__ */

