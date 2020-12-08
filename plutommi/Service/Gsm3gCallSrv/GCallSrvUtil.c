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
/*******************************************************************************
 *  Modification Notice:
 *  --------------------------
 *  This software is modified by MediaTek Inc. and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   GCallSrvUtil.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  GSM / 3G call service
 *  Utility, which shall not access any context
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "App_usedetails.h"

#include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_xxx */

#ifdef __IP_NUMBER__
#include "CallSetSrvGprot.h" /* srv_callset_ip_number_get_activated_number */
#endif

#include "CphsSrvGprot.h" /* srv_cphs_is_service_available */
#include "Custom_ecc.h" /* ecc_custom_verify_emergency_number */
#include "PhbSrvGprot.h" /* srv_phb_hold_cm_user_data, srv_phb_destory_cm_user_data */

#include "UcmSrvGProt.h"
#include "..\UcmSrv\UCMSrvIntProt.h"

#include "GCallSrvProt.h"

#include "ModeSwitchSrvGprot.h" /* srv_mode_switch_get_current_mode, srv_mode_switch_is_network_service_available */
#if (MMI_MAX_SIM_NUM >= 2)
#include "NwUsabSrvGprot.h" /* srv_nw_usab_is_usable */
#endif /* (MMI_MAX_SIM_NUM >= 2) */


#include "MMI_features.h"
#include "MMIDataType.h"
#include "csmcc_common_enums.h"
#include "CustDataRes.h"
#include "mmi_rp_srv_gcall_def.h"
#include "Unicodexdcl.h"
#include "kal_non_specific_general_types.h"
#include "NetSetSrvGprot.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "GCallSrvDef.h"
#include "l4c2abm_struct.h"
#include "string.h"
#include "GlobalConstants.h"
#include "l3_inc_enums.h"
#include "kal_release.h"


#ifdef __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__
 /*****************************************************************************
  * FUNCTION
  *  srv_gcall_util_get_no_cli_display_text
  * DESCRIPTION
  *  Function gets the message by the cause of no CLI
  * PARAMETERS
  * 
  * RETURNS
  *  void
  *****************************************************************************/
 void srv_gcall_util_get_no_cli_display_text(U8 cause, PU8 no_cli_display_text)
 {
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
 
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
 
     switch (cause)
     {
         case CSMCC_CLI_UNAVAILABLE:
         case CSMCC_CLI_INTERACTION:
             mmi_ucs2cpy((CHAR *) no_cli_display_text, GetString(STR_ID_GCALL_UNAVAILABLE));
             break;
         case CSMCC_CLI_REJECT_BY_USER:
             mmi_ucs2cpy((CHAR *) no_cli_display_text, GetString(STR_ID_GCALL_REJECT_BY_USER));
             break;
         case CSMCC_COIN_LINE_PAYPHONE:
             mmi_ucs2cpy((CHAR *) no_cli_display_text, GetString(STR_ID_GCALL_PAYPHONE));
             break;
         default:
             mmi_ucs2cpy((CHAR *) no_cli_display_text, GetString(STR_ID_GCALL_UNAVAILABLE));
             break;
     }
 }
#endif /* __MMI_UCM_DISPLAY_CAUSE_OF_NO_CLI__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_type_available
 * DESCRIPTION
 *  Function gets the message by the cause of no CLI
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_gcall_util_type_available(srv_ucm_call_type_enum call_type, MMI_BOOL include_ecc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* general */
    if (!srv_mode_switch_is_network_service_available() /* flight mode */)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UTIL_TYPE_AVAILABLE, 1);
        return MMI_FALSE;
    }

    /* sim specific */
    sim_id = srv_gcall_get_interface_with_ucm_call_type(call_type);

#ifdef __MMI_3G_SWITCH__
    if ((SRV_UCM_VIDEO_CALL_TYPE_ALL & call_type) &&
        (sim_id != srv_netset_get_3g_capability_sim()))
    {
        /* if call_type belongs to video call, check the setting status */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UTIL_TYPE_AVAILABLE, 5);
        return MMI_FALSE;
    }
    else
#endif /* __MMI_3G_SWITCH__ */
    {
        if (srv_mode_switch_get_current_mode() & (srv_mode_switch_type_enum)sim_id)
        {
            if ((include_ecc == MMI_FALSE) &&
                ((srv_sim_ctrl_is_available(sim_id) == MMI_FALSE) || 
                (srv_nw_usab_is_usable(sim_id)== MMI_FALSE)))
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UTIL_TYPE_AVAILABLE, 2);
                return MMI_FALSE;
            }
            else
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UTIL_TYPE_AVAILABLE, 3);
                return MMI_TRUE;
            }
        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UTIL_TYPE_AVAILABLE, 4);
            return MMI_FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_op_need_rsp
 * DESCRIPTION
 *  check if ucm rsp is needed for the act_op
 * PARAMETERS
 *  act_op          [IN]        ucm act op
 * RETURNS
 *  MMI_TRUE if rsp is needed
 *****************************************************************************/
MMI_BOOL srv_gcall_util_op_need_rsp(srv_ucm_int_act_opcode_enum act_op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (act_op)
    {
        case SRV_UCM_INT_NO_ACT:
        case SRV_UCM_INT_START_DTMF_ACT:
        case SRV_UCM_INT_STOP_DTMF_ACT:
        case SRV_UCM_INT_AUTO_REJECT_ACT:
        case SRV_UCM_INT_FORCE_RELEASE_ACT:
            return MMI_FALSE;

        default:
            return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_op_is_exclusive
 * DESCRIPTION
 *  CHLD op
 * PARAMETERS
 *  handle          [IN]        
 *  Cause(?)        [OUT]       Value
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_gcall_util_op_is_exclusive(srv_ucm_int_act_opcode_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (op)
    {
        case SRV_UCM_INT_HOLD_ACT:
        case SRV_UCM_INT_RETRIEVE_ACT:
        case SRV_UCM_INT_SWAP_ACT:
        case SRV_UCM_INT_CONFERENCE_ACT:
        case SRV_UCM_INT_SPLIT_ACT:
    #ifdef __MMI_UCM_ECT__
        case SRV_UCM_INT_EXPLICIT_CALL_TRANSFER_ACT:
    #endif /* __MMI_UCM_ECT__ */
        case SRV_UCM_INT_END_SINGLE_ACT:
        case SRV_UCM_INT_END_CONFERENCE_ACT:
        case SRV_UCM_INT_END_ALL_ACT:
        case SRV_UCM_INT_AUTO_REJECT_ACT:
            return MMI_TRUE;

        default:
            return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_is_valid_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  strNumber       [IN]
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL srv_gcall_util_is_valid_number(mmi_sim_enum interface, PU8 number, srv_gcall_dir_enum dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!number)
    {
        return MMI_FALSE;
    }

    if (srv_gcall_util_is_valid_ecc(interface, number, dir)
        || (applib_is_valid_number(number) != APPLIB_INVALID_NUMBER))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_get_ecc_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  strNumber       [IN]
 * RETURNS
 *  pBOOL
 *****************************************************************************/
ecc_call_type_enum srv_gcall_util_get_ecc_type(mmi_sim_enum interface, srv_gcall_dir_enum dir)
{
    if (dir == SRV_GCALL_DIR_MO_STK)
    {
        return ECC_SAT_CALL;
    }
    else if (interface == MMI_SIM1)
    {
        return ECC_SIM1_CALL;
    }
#if (MMI_MAX_SIM_NUM >= 2)
    else if (interface == MMI_SIM2)
    {
        return ECC_SIM2_CALL;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    else if (interface == MMI_SIM3)
    {
        return ECC_SIM3_CALL;
    }
#if (MMI_MAX_SIM_NUM == 4)
    else if (interface == MMI_SIM4)
    {
        return ECC_SIM4_CALL;
    }
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */
    else
    {
        return ECC_ALL_CALL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_is_valid_ecc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  strNumber       [IN]
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL srv_gcall_util_is_valid_ecc(mmi_sim_enum interface, PU8 number, srv_gcall_dir_enum dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ucs2_num[SRV_GCALL_MAX_NUMBER * ENCODING_LENGTH];
    ecc_call_type_enum ecc_call_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!number)
    {
        return MMI_FALSE;
    }

    memset(ucs2_num, 0, SRV_GCALL_MAX_NUMBER * ENCODING_LENGTH);
    mmi_asc_n_to_ucs2((CHAR *)ucs2_num, (CHAR *)number, SRV_GCALL_MAX_NUMBER - 1);

    ecc_call_type = srv_gcall_util_get_ecc_type(interface, dir);
    if (ecc_call_type == ECC_ALL_CALL)
    {
        return MMI_FALSE;
    }

    if (ecc_custom_verify_emergency_number(
        (PU8)ucs2_num, 
        (U8)mmi_ucs2strlen((CHAR *)ucs2_num), 
        ECC_ENCODING_UCS2, 
        ecc_call_type, 
        NULL, 
        NULL, 
        NULL))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_is_valid_dtmf
 * DESCRIPTION
 *  Validation check before sending DTMF
 * PARAMETERS
 *  strNumber       [IN] dtmf digit in ascii
 * RETURNS
 *  pBOOL
 *****************************************************************************/
MMI_BOOL srv_gcall_util_is_valid_dtmf(U16 digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 asc_digit = srv_gcall_util_convert_dtmf_to_ascii(&digit);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if((asc_digit == (U8)'*')
        || (asc_digit == (U8)'#')
        || ((asc_digit >= (U8)'0') && (asc_digit <= (U8)'9')))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }        
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_is_data_csd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_gcall_util_is_data_csd(srv_gcall_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (call_type)
    {
        case CSMCC_DATA_CALL:
        case CSMCC_FAX_CALL:
        case CSMCC_CSD_CALL:
        case CSMCC_SAT_DATA_CALL:
            return MMI_TRUE;

        default:
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_convert_dtmf_to_ascii
 * DESCRIPTION
 *  Function maps keycode from enum value to ascii equiv.
 * PARAMETERS
 *  digit           [IN]        
 *  Ascii(?)        [OUT]       Equivalent
 *  DTMF(?)         [IN]        Keycode digit
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_gcall_util_convert_dtmf_to_ascii(U16 *digit)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (*digit)
    {
        case KEY_0:
        case KEY_1:
        case KEY_2:
        case KEY_3:
        case KEY_4:
        case KEY_5:
        case KEY_6:
        case KEY_7:
        case KEY_8:
        case KEY_9:
            return '0' + (*digit) - KEY_0;
        case KEY_STAR:
            return '*';
        case KEY_POUND:
            return '#';
        default:
            return KEY_INVALID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_get_ss_notify_str_id
 * DESCRIPTION
 *  Function derives call features such as CUG, CLIP etc.
 * PARAMETERS
 *  event           [IN]        
 *  Response(?)     [IN]        Structure from CHLD
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_gcall_util_get_ss_notify_str_id(U16 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
    #if 0 /* don't display detail info */
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
    #else
        case CSMCC_NOTIFY_CFC:
        case CSMCC_NOTIFY_CFU:
        case CSMCC_NOTIFY_CF_CFU:
        case CSMCC_NOTIFY_CF_CFC:
        case CSMCC_NOTIFY_CF_CFB:
        case CSMCC_NOTIFY_CF_CFNRY:
        case CSMCC_NOTIFY_CF_CFNRC:
        case CSMCC_NOTIFY_CF:
            return STR_ID_GCALL_SS_NFY_CF_ON;
    #endif

        case CSMCC_NOTIFY_BAC:
            return STR_ID_GCALL_SS_NFY_ALL_BARRED;
        case CSMCC_NOTIFY_BAOC:
            return STR_ID_GCALL_SS_NFY_ALL_OUTGOING_BARRED;
        case CSMCC_NOTIFY_BAIC:
            return STR_ID_GCALL_SS_NFY_ALL_INCOMING_BARRED;
        case CSMCC_NOTIFY_CW:
            return STR_ID_GCALL_SS_NFY_WTG;

        case CSMCC_NOTIFY_CALL_HELD:
            return STR_ID_GCALL_SS_NFY_HLD;

        case CSMCC_NOTIFY_CALL_RETRIEVED:
            return STR_ID_GCALL_SS_NFY_RTVD;

        case CSMCC_NOTIFY_MPTY:
            return STR_ID_GCALL_SS_NFY_CONF;

        case CSMCC_NOTIFY_CUG:
            return STR_ID_GCALL_SS_NFY_CUG;

        case CSMCC_NOTIFY_CLIR_REJECT:
            return STR_ID_GCALL_SS_NFY_CLIR_REJECTED;

        case CSMCC_NOTIFY_ECT_ACTIVE:
            return STR_ID_GCALL_SS_NFY_CTFAC;

        default:
            return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_get_internal_call_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type
 * RETURNS
 *  void
 *****************************************************************************/
srv_gcall_type_enum srv_gcall_util_get_internal_call_type(srv_ucm_call_type_enum ucm_call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (ucm_call_type)
    {
        case SRV_UCM_VOICE_CALL_TYPE:
            return CSMCC_VOICE_CALL;    
        case SRV_UCM_DATA_CALL_TYPE:
            return CSMCC_DATA_CALL;
        case SRV_UCM_CSD_CALL_TYPE:
            return CSMCC_CSD_CALL;
        case SRV_UCM_VIDEO_CALL_TYPE:
            return CSMCC_VIDEO_CALL; 
    #if (MMI_MAX_SIM_NUM >= 2)
        case SRV_UCM_VOICE_CALL_TYPE_SIM2:
            return CSMCC_VOICE_CALL;
        case SRV_UCM_DATA_CALL_TYPE_SIM2:
            return CSMCC_DATA_CALL;
        case SRV_UCM_CSD_CALL_TYPE_SIM2:
            return CSMCC_CSD_CALL;
        case SRV_UCM_VIDEO_CALL_TYPE_SIM2:
            return CSMCC_VIDEO_CALL; 
    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_UCM_VOICE_CALL_TYPE_SIM3:
            return CSMCC_VOICE_CALL;
        case SRV_UCM_DATA_CALL_TYPE_SIM3:
            return CSMCC_DATA_CALL;
        case SRV_UCM_CSD_CALL_TYPE_SIM3:
            return CSMCC_CSD_CALL;
    #if (MMI_MAX_SIM_NUM == 4)
        case SRV_UCM_VOICE_CALL_TYPE_SIM4:
            return CSMCC_VOICE_CALL;
        case SRV_UCM_DATA_CALL_TYPE_SIM4:
            return CSMCC_DATA_CALL;
        case SRV_UCM_CSD_CALL_TYPE_SIM4:
            return CSMCC_CSD_CALL;
    #endif /* (MMI_MAX_SIM_NUM == 4) */
    #endif /* (MMI_MAX_SIM_NUM >= 3) */
    #endif /* (MMI_MAX_SIM_NUM >= 2) */
        default:
            break;
    }

    return CSMCC_INVALID_CALL_TYPE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_get_ucm_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_result_enum srv_gcall_util_get_ucm_result(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (result)
    {
        case SRV_GCALL_RESULT_OK:
            return SRV_UCM_RESULT_OK;

        case SRV_GCALL_RESULT_BUSY:
            return SRV_UCM_RESULT_UCM_BUSY;

        case SRV_GCALL_RESULT_EMPTY_NUMBER:
            return SRV_UCM_RESULT_EMPTY_NUMBER;

        case SRV_GCALL_RESULT_INVALID_NUMBER_FORMAT:
        case SRV_GCALL_RESULT_UNASSIGNED_NUM:
        case SRV_GCALL_RESULT_NO_ROUTE_TO_DESTINATION:
            return SRV_UCM_RESULT_INVALID_NUMBER;

        case SRV_GCALL_RESULT_USER_BUSY:
            return SRV_UCM_RESULT_CALLED_PARTY_BUSY;

        case SRV_GCALL_RESULT_NO_ANSWER_ON_ALERT:
            return SRV_UCM_RESULT_CALLED_PARTY_NOT_ANSWERED;

        case SRV_GCALL_RESULT_ECC_ONLY:
            return SRV_UCM_RESULT_SOS_NUMBER_ONLY;
             
        case SRV_GCALL_RESULT_NO_CIRCUIT_CHANNEL_AVAIL:
        case SRV_GCALL_RESULT_NETWORK_OUT_OF_ORDER:
        case SRV_GCALL_RESULT_TEMPORARY_FAILURE:
        case SRV_GCALL_RESULT_SWITCH_EQUIPMENT_CONGESTION:
        case SRV_GCALL_RESULT_REQUESTED_CKT_CHANEL_NOT_AVIL:
        case SRV_GCALL_RESULT_ACCESS_INFO_DISCARDED:
        case SRV_GCALL_RESULT_REQ_FAC_NOT_SUBS:
        case SRV_GCALL_RESULT_QOS_UNAVAIL:
        case SRV_GCALL_RESULT_BEARER_CAP_NOT_AUTHORISED:
        case SRV_GCALL_RESULT_BEARER_CAP_NOT_AVAIL:
        case SRV_GCALL_RESULT_SER_UNAVAILABLE:
            return SRV_UCM_RESULT_NETWORK_NOT_AVAILABLE;

    #if (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__))
        case SRV_GCALL_RESULT_INCOMPATIBLE_DEST: /* 88 */
            return SRV_UCM_RESULT_VT_FALLBACK;
    #endif /* (defined(__OP01__) && defined(__MMI_VIDEO_TELEPHONY__)) */

        default:
            return SRV_UCM_RESULT_UNSPECIFIED_ERROR;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_get_ucm_call_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_call_state_enum srv_gcall_util_get_ucm_call_state(srv_gcall_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (state)
    {
        case SRV_GCALL_STATE_IDLE:
            return SRV_UCM_IDLE_STATE;

        case SRV_GCALL_STATE_OUTGOING:
            return SRV_UCM_OUTGOING_STATE;

        case SRV_GCALL_STATE_INCOMING:
            return SRV_UCM_INCOMING_STATE;

        case SRV_GCALL_STATE_ACTIVE:
            return SRV_UCM_ACTIVE_STATE;

        case SRV_GCALL_STATE_HOLD:
            return SRV_UCM_HOLD_STATE;

        default:
            return SRV_UCM_CALL_STATE_END_OF_ENUM;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_get_ucm_origin
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type
 * RETURNS
 *  void
 *****************************************************************************/
srv_ucm_int_call_origin_enum srv_gcall_util_get_ucm_origin(srv_gcall_dir_enum dir)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (dir)
    {
        case SRV_GCALL_DIR_MO:
        case SRV_GCALL_DIR_MO_STK:
            return SRV_UCM_INT_MO_ORIGIN;    

        case SRV_GCALL_DIR_MT:
            return SRV_UCM_INT_MT_ORIGIN;

        default:
            MMI_ASSERT(0);
            break;
    }

    return SRV_UCM_INT_NONE_ORIGIN;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_is_reset_csp_group_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_gcall_util_is_reset_csp_group_service(mmi_sim_enum sim, U8 group, U8 srv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (srv_cphs_is_service_available((srv_cphs_group_enum)group, (srv_cphs_service_enum)srv, sim) ? 0 : 1);
}


#ifdef __IP_NUMBER__
/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_get_curr_ip_number_ucs2
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gcall_util_get_curr_ip_number_ucs2(mmi_sim_enum sim, WCHAR *buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_callset_ip_number_struct ip_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(buf);

    memset(&ip_num, 0, sizeof(ip_num));

    srv_callset_ip_number_get_activated_number(sim, &ip_num);

    if (!mmi_ucs2strlen((CHAR *)ip_num.number))
    {
        buf[0] = L'\0';
    }
    else
    {
        mmi_ucs2ncpy((CHAR *)buf, (CHAR *)ip_num.number, SRV_UCM_MAX_IP_NUMBER_LEN);
    }
}
#endif /* __IP_NUMBER__ */


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_get_ucm_single_call_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type   [IN]    ucm bitwise call type
 * RETURNS
 *  ucm single call type
 *****************************************************************************/
srv_ucm_call_type_enum srv_gcall_util_get_ucm_single_call_type(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_call_type_enum single_call_type = SRV_UCM_CALL_TYPE_END_OF_ENUM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* single call type */
    if (srv_gcall_util_get_internal_call_type(call_type) != CSMCC_INVALID_CALL_TYPE)
    {
        return call_type;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MMI_MAX_SIM_NUM >= 2 */
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MMI_MAX_SIM_NUM >= 3 */
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MMI_MAX_SIM_NUM >= 4 */
#endif

    return single_call_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_gcall_util_mgmt_phb_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  is_hold   [IN]    use MMI_TRUE to hold; use MMI_FALSE to destroy
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_gcall_util_mgmt_phb_info(MMI_BOOL is_hold, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!user_data)
    {
        return MMI_FALSE;
    }

    if (is_hold)
    {
        result = srv_phb_hold_cm_user_data(user_data);
    }
    else
    {
        srv_phb_destory_cm_user_data(user_data);
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_GCALL_UTIL_MGMT_PHB_INFO, is_hold, user_data, result);

    return result;

}


