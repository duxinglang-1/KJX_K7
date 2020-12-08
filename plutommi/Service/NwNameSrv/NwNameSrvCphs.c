/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  NwNameSrvCphs.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements CPHS of the network name service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "ProtocolEvents.h"
#include "GSM7BitDefaultAlphabet.h"
#include "SIMAccessSrvGprot.h"

// for sim_service_table_query
#include "sim_public_api.h"
#include "ps_public_utility.h"


// auto add by kw_check begin
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "NwNameSrvMain.h"
#include "mmi_msg_struct.h"
#include "mmi_common_app_trc.h"
#include "MMI_common_app_trc.h"
#include "NwNameSrvGprot.h"
#include "stack_config.h"
#include "mmi_frm_events_gprot.h"
#include "stack_msgs.h"
// auto add by kw_check end 


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_convert_sim_str_to_ucs2
 * DESCRIPTION
 *  Convert a SIM string to UCS2 string.
 * PARAMETERS
 *  sim_data            [IN]  Source SIM string data
 *  max_data_size       [IN]  Maximum data size of sim_data[] in bytes
 *  src_encoding        [IN]  Source encoding
 *  ucs2_str            [OUT] Destination buffer
 *  ucs2_max_char_len   [IN]  Maximum string length of ucs2_str[]
 * RETURNS
 *  MMI_TRUE if successfully converted
 *****************************************************************************/
static MMI_BOOL srv_nw_name_convert_sim_str_to_ucs2(
    const U8 *sim_data,
    U32 max_data_size,
    MMIDCSENUM src_encoding,
    WCHAR *ucs2_str,
    U32 ucs2_max_char_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_data_size;
    U8 *decode_temp_result;
    U16 ucs2_str_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(sim_data && ucs2_str);

    ucs2_str[0] = 0;

    /*
     * Get the length of the 7-bit string, which is terminated with 0xFF.
     */
    sim_data_size = 0;
    while (sim_data_size < max_data_size && sim_data[sim_data_size] != 0xFF)
    {
        sim_data_size++;
    }

    if (sim_data_size == 0)
    {
        return MMI_TRUE;    /* Empty string is allowed. */
    }

    /* 
       string which read from sim file may contain the space in the end of string.
       we will remove it for better UE. 
       Besides, needs to prevent sim_data_size less than zero in while loop,
       It may happen when the front memory content is 0x20.
       PS: 0x20 is the space character defined in the GSM 7-bit default alphabet.
    */
    while (sim_data[sim_data_size-1] == 0x20 && sim_data_size > 0)
    {
        sim_data_size--;
    }

    /*
     * Decode the string from GSM 7-bits to UCS2.
     */
    decode_temp_result = CovertStringForPlatform(
                            (U8 *)sim_data,
                            (U16)sim_data_size,
                            (U8)src_encoding,
                            &ucs2_str_len);

    /* Use mmi_ucs2ncpy since the buffer might not be 2-bytes aligned. */
    mmi_ucs2ncpy(
        (CHAR *)ucs2_str,
        (const CHAR *)decode_temp_result,
        ucs2_max_char_len);

    mmi_mfree(decode_temp_result);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_convert_sim_str_to_ucs2_ex
 * DESCRIPTION
 *  Convert an extended SIM string to UCS2 string.
 *  See 51.011 annex B.
 * PARAMETERS
 *  sim_data            [IN]  Source SIM string data
 *  max_data_size       [IN]  Maximum length of sim_data[] in bytes
 *  ucs2_str            [OUT] Destination buffer
 *  ucs2_max_char_len   [IN]  Maximum string length of ucs2_str[]
 * RETURNS
 *  MMI_TRUE if successfully converted
 *****************************************************************************/
static MMI_BOOL srv_nw_name_convert_sim_str_to_ucs2_ex(
    const U8 *sim_data,
    U32 max_data_size,
    WCHAR *ucs2_str,
    U32 ucs2_max_char_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMIDCSENUM src_encoding;
    const U8 *real_sim_data_begin;
    U32 real_max_data_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(sim_data && ucs2_str);

    ucs2_str[0] = 0;

    src_encoding = MMI_DEFAULT_DCS;
    real_sim_data_begin = sim_data;
    real_max_data_size = max_data_size;

    if (sim_data[0] >= 0x80) /* If the first byte indicates the encoding */
    {
        switch (sim_data[0]) /* Encoding */
        {
            case 0x80:
                src_encoding = MMI_UCS2_DCS;
                break;

            case 0x81:
                src_encoding = MMI_UCS2_81;
                break;

            case 0x82:
                src_encoding = MMI_UCS2_82;
                break;

            default:
                /* Undefined encoding */
                return MMI_FALSE;
        }

        /* Shift one byte */
        real_sim_data_begin++;
        real_max_data_size--;
    }
    else
    {
        src_encoding = MMI_DEFAULT_DCS;
    }

    return srv_nw_name_convert_sim_str_to_ucs2(
            real_sim_data_begin,
            real_max_data_size,
            src_encoding,
            ucs2_str,
            ucs2_max_char_len);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_cphs_mmi_info_ind_hdlr_int
 * DESCRIPTION
 *  This function handles the CPHS MMI Info indication.
 * PARAMETERS
 *  sim             : [IN]          SIM id
 *  param           : [IN]          Message
 * RETURNS
 *  MMI_TRUE: stop routing.
 *  MMI_FALSE: keep routing.
 *****************************************************************************/
static U8 srv_nw_name_cphs_mmi_info_ind_hdlr_int(mmi_sim_enum sim, void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);
    mmi_cphs_mmi_info_ind_struct *msg = (mmi_cphs_mmi_info_ind_struct *)param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_CPHS_HDLR, sim));

    MMI_ASSERT(cntx && msg);

    if (msg->is_spn_valid)
    {
        if ((msg->is_spn_RPLMN_required & 0x01))
        {
            cntx->is_rplmn_required_in_home = MMI_TRUE;
        }
        else
        {
            cntx->is_rplmn_required_in_home = MMI_FALSE;
        }

        if ((msg->is_spn_RPLMN_required & 0x02))
        {
            cntx->is_spn_required_in_roaming = MMI_FALSE;
        }
        else
        {
            cntx->is_spn_required_in_roaming = MMI_TRUE;
        }
    }

    if (msg->is_opname_valid)
    {
        srv_nw_name_convert_sim_str_to_ucs2(
            (U8 *)msg->opname,
            sizeof(msg->opname),
            MMI_DEFAULT_DCS,
            cntx->ons,
            SRV_NW_NAME_MAX_STR_LEN);
    }
    else
    {
        cntx->ons[0] = 0;
    }

    if (msg->is_sopname_valid)
    {
        srv_nw_name_convert_sim_str_to_ucs2(
            (U8 *)msg->sopname,
            sizeof(msg->sopname),
            MMI_DEFAULT_DCS,
            cntx->short_ons,
            SRV_NW_NAME_MAX_STR_LEN);
    }
    else
    {
        cntx->short_ons[0] = 0;
    }

    if (msg->is_spn_valid)
    {
        srv_nw_name_convert_sim_str_to_ucs2_ex(
            (U8 *)msg->spn,
            sizeof(msg->spn),
            cntx->spn,
            SRV_NW_NAME_MAX_STR_LEN);
    }
    else
    {
        cntx->spn[0] = 0;
    }

    srv_nw_name_set_mod_ready(cntx->sim, SRV_NW_NAME_MOD_CPHS);

    return (U8)MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_cphs_mmi_info_ind_hdlr
 * DESCRIPTION
 *  This function handles the CPHS MMI Info indication.
 * PARAMETERS
 *  param               : [IN]          Local parameter
 *  src_mod             : [IN]          Source module ID
 *  peer_buf            : [IN]          Peer buffer
 * RETURNS
 *  MMI_TRUE: stop routing.
 *  MMI_FALSE: keep routing.
 *****************************************************************************/
static U8 srv_nw_name_cphs_mmi_info_ind_hdlr(
    void *param,
    int src_mod,
    void *peer_buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)src_mod);

    return srv_nw_name_cphs_mmi_info_ind_hdlr_int(sim, param);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_cphs_bootup_early_init_hdlr
 * DESCRIPTION
 *  This function initializes the CPHS of network name service.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nw_name_cphs_bootup_early_init_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_CPHS_INIT));

    mmi_frm_set_protocol_event_handler(
        PRT_MSG_ID_MMI_CPHS_MMI_INFO_IND,
        (PsIntFuncPtr)srv_nw_name_cphs_mmi_info_ind_hdlr,
        MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_parse_spn
 * DESCRIPTION
 *  This function parse an EF_SPN data
 * PARAMETERS
 *  data            : [IN]          Data
 *  size            : [IN]          Size of 'data' in bytes
 *  nw_name             : [OUT]     service network name structure
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_parse_spn(
    U8 *data,
    U16 size,
    srv_nw_name_struct *nw_name)
{

    if(data[0] & 0x01)
    {
        nw_name->is_rplmn_required_in_home = MMI_TRUE;
    }
    else
    {
        nw_name->is_rplmn_required_in_home = MMI_FALSE;
    }

    if(data[0] & 0x02)
    {
        nw_name->is_spn_required_in_roaming = MMI_FALSE;
    }
    else
    {
        nw_name->is_spn_required_in_roaming = MMI_TRUE;
    }
    data++;
    size -= 1;
    srv_nw_name_convert_sim_str_to_ucs2_ex(
        data,
        size,
        nw_name->spn,
        SRV_NW_NAME_MAX_STR_LEN);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_read_spn_hdlr
 * DESCRIPTION
 *  This function handles the EF_SPN (type: Transparent)
 * PARAMETERS
 *  eons           : [IN]       EONS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nw_name_read_spn_hdlr(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_nw_name_struct *nw_name;
    srv_sim_data_struct *spn_data;
	sim_service_state_enum state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data && param->data);

    spn_data = (srv_sim_data_struct *)param->data;
    nw_name = (srv_nw_name_struct *)param->user_data;

#if (MMI_MAX_SIM_NUM >= 2)
    state = sim_service_table_query(SERVICE_SPN,
                (kal_uint8)l4c_gemini_get_switched_sim_id((sim_interface_enum)mmi_frm_sim_to_index(nw_name->sim)));
#else
    state = sim_service_table_query(SERVICE_SPN);
#endif

    if (!param->result || state!=SERVICE_SUPPORT || !spn_data->length || !spn_data->data)
    {
        SRV_NWNAME_LOG((TRC_SRV_NW_NAME_READ_SPN_HDLR, nw_name->sim, 600));
    }
    else
    {
        SRV_NWNAME_LOG((TRC_SRV_NW_NAME_READ_SPN_HDLR, nw_name->sim, 200));

        srv_nw_name_parse_spn(
            spn_data->data,
            spn_data->length,
            nw_name);
    }

	srv_nw_name_set_mod_ready(nw_name->sim, SRV_NW_NAME_MOD_CPHS);
}



/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_read_spn
 * DESCRIPTION
 *  This function reads the EF_SPN (type: Transparent)
 * PARAMETERS
 *  eons           : [IN]       EONS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nw_name_read_spn(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
	srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_READ_SPN, sim, 200));

    ret = srv_sim_read_binary(
            (U16)FILE_SPN_IDX,
            NULL,
            0,
            17,
            cntx->sim,
            srv_nw_name_read_spn_hdlr,
            cntx);

    MMI_ASSERT(ret);
}

#if 0 
#if defined(__MMI_DUAL_SIM__)
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
#endif /* defined(__MMI_DUAL_SIM__) */
#endif/* #if 0*/

