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
 *  NwNameSrvSpdi.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the EF_SPDI of the network name service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "NwInfoSrvGprot.h"
#include "SimAccessSrvGprot.h"
#include "app_plmn.h"
#include "mmi_frm_gprot.h"

// for sim_service_table_query
#include "sim_public_api.h"
#include "ps_public_utility.h"


// auto add by kw_check begin
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "NwNameSrvMain.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_common_app_trc.h"
#include "MMI_common_app_trc.h"
#include "string.h"
#include "sim_common_enums.h"
#include "SimCtrlSrvGprot.h"
// auto add by kw_check end 


/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_spdi_unpack_tlv
 * DESCRIPTION
 *  This function unpacks a TLV object.
 * PARAMETERS
 *  data            [IN]            Start address of the TLV object
 *  size            [IN]            TLV object length
 *  tag             [OUT]           Tag of TLV
 *  len             [OUT]           Length of TLV
 *  val             [OUT]           Value of TLV
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_nw_name_spdi_unpack_tlv(
                    U8 *data,
                    U16 size,
                    U8 *tag,
                    U8 *len,
                    U8 **val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Per the EF_SPDI definition, the length of the TLV object can be coded on
       one or more bytes. We support up to 2 bytes. */
    if (size >= 2 && data[1] <= 0x7F)
    {
        if (size >= data[1] + 2)
        {
            *tag = data[0];
            *len = data[1];
            *val = data + 2;

            return MMI_TRUE;
        }
    }
    else if (size >= 3 && data[1] == 0x81 && data[2] >= 0x80)
    {
        if (size >= data[2] + 3)
        {
            *tag = data[0];
            *len = data[2];
            *val = data + 3;

            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_spdi_unpack
 * DESCRIPTION
 *  This function unpacks the EF_SPDI.
 * PARAMETERS
 *  spdi            [IN]            SPDI context
 *  data            [IN]            SPDI data
 *  len             [IN]            data length
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_spdi_unpack(
    srv_nw_name_struct *cntx,
    U8 *data,
    U16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag, len, *val;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx);

    /*
     * Unpack the constructed TLV object:
     *
     *      A3: service provider display information tag
     *      80: service provider PLMN list tag
     */
    if (!srv_nw_name_spdi_unpack_tlv(data, size, &tag, &len, &val) || tag != 0xA3)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_SPDI_UNPACK, 500, cntx->sim));
        return;
    }

    if (!srv_nw_name_spdi_unpack_tlv(val, len, &tag, &len, &val) || tag != 0x80)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_SPDI_UNPACK, 501, cntx->sim));
        return;
    }

    /*
     * Invalid length.
     */
    if (len == 0 || len % SRV_NW_NAME_PLMN_BCD_SIZE != 0)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_SPDI_UNPACK, 502, cntx->sim));
        return;
    }

    /*
     * Copy the PLMN list.
     */
    SRV_NWNAME_LOG((TRC_SRV_NWNAME_SPDI_UNPACK, 200, cntx->sim));

    cntx->spdi_num = len / SRV_NW_NAME_PLMN_BCD_SIZE;

    if (cntx->spdi_num > SRV_NW_NAME_MAX_SPDI_NUM)
    {
        cntx->spdi_num = SRV_NW_NAME_MAX_SPDI_NUM;
    }

    for (i = 0; i < cntx->spdi_num; i++)
    {
        memcpy(
            cntx->spdi_plmn[i],
            val + i * SRV_NW_NAME_PLMN_BCD_SIZE,
            SRV_NW_NAME_PLMN_BCD_SIZE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_spdi_read_data_hdlr
 * DESCRIPTION
 *  This function handles the response of reading EF_SPDI data.
 * PARAMETERS
 *  error_code              : [IN]      Error code
 *  read_length             : [IN]      Data length
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_spdi_read_data_hdlr(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx;
    srv_sim_data_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->data && param->user_data);

    data = (srv_sim_data_struct *)param->data;
    cntx = (srv_nw_name_struct *)param->user_data;

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_SPDI_READ_DATA_HDLR, param->result, data->length, cntx->sim));

    if (param->result && data->data && data->length > 0)
    {
        srv_nw_name_spdi_unpack(cntx, data->data, data->length);
    }

    srv_nw_name_set_mod_ready(cntx->sim, SRV_NW_NAME_MOD_SPDI);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_spdi_read_data
 * DESCRIPTION
 *  This function gets the EF_SPDI data.
 * PARAMETERS
 *  spdi_data_size           : [IN]         Size
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_spdi_read_data(srv_nw_name_struct *cntx, U16 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx);

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_SPDI_READ_DATA, cntx->sim));

    srv_sim_read_binary(
        (U16)FILE_SPDI_IDX,
        NULL,
        0,
        size,
        cntx->sim,
        srv_nw_name_spdi_read_data_hdlr,
        cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_spdi_read_info_hdlr
 * DESCRIPTION
 *  This function handles the response of reading EF_SPDI file info.
 * PARAMETERS
 *  error_code           : [IN]         Error code
 *  total_size           : [IN]         File size
 *  record_num           : [IN]         Number of records
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_spdi_read_info_hdlr(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx;
    srv_sim_file_info_struct *info;
    sim_service_state_enum state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->data && param->user_data);

    info = (srv_sim_file_info_struct *)param->data;
    cntx = (srv_nw_name_struct *)param->user_data;

    /*
     * TODO: we should request SIM module to provide a unified API for this.
     */
#if (MMI_MAX_SIM_NUM >= 2)
    state = sim_service_table_query(SERVICE_SP_DSPL_INFO,
                (kal_uint8)l4c_gemini_get_switched_sim_id((sim_interface_enum)mmi_frm_sim_to_index(cntx->sim)));
#else
    state = sim_service_table_query(SERVICE_SP_DSPL_INFO);
#endif

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_SPDI_READ_INFO_HDLR, param->result, state, cntx->sim));

    if (!param->result || state != SERVICE_SUPPORT)
    {
        srv_nw_name_set_mod_ready(cntx->sim, SRV_NW_NAME_MOD_SPDI);
    }
    else
    {
        srv_nw_name_spdi_read_data(cntx, info->file_size);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_spdi_read_info
 * DESCRIPTION
 *  This function gets the EF_SPDI file info.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_nw_name_spdi_read_info(srv_nw_name_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx);

    SRV_NWNAME_LOG((TRC_SRV_NWNAME_SPDI_READ_INFO, cntx->sim));

    ret = srv_sim_get_file_info(
            (U16)FILE_SPDI_IDX,
            NULL,
            cntx->sim,
            srv_nw_name_spdi_read_info_hdlr,
            cntx);

    MMI_ASSERT(ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_spdi_init_module
 * DESCRIPTION
 *  This function initializes the EF_SPDI.
 * PARAMETERS
 *  sim           : [IN]        SIM id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_nw_name_spdi_init_module(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cntx);

    srv_nw_name_set_mod_waiting(sim, SRV_NW_NAME_MOD_SPDI);

    cntx->spdi_num = 0;
    srv_nw_name_spdi_read_info(cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_nw_name_spdi_is_present
 * DESCRIPTION
 *  This function checks if the current network PLMN is in the service provider
 *  PLMN list. Please refer to the EF_SPDI for details.
 * PARAMETERS
 *  sim             : [IN]      SIM ID
 * RETURNS
 *  On yes, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_nw_name_spdi_is_present(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_struct *cntx = srv_nw_name_get_context(sim);
    CHAR sim_plmn[SRV_MAX_PLMN_LEN + 1];
    CHAR bcch_plmn[SRV_MAX_PLMN_LEN + 1];
    MMI_BOOL ret, is_pcs1900 = KAL_FALSE;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!cntx)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_SPDI_IS_PRESENT_ERROR, 500, sim));
        return MMI_FALSE;
    }

    ret = srv_nw_info_get_nw_plmn(sim, bcch_plmn, SRV_MAX_PLMN_LEN + 1);
    if (!ret)
    {
        SRV_NWNAME_LOG((TRC_SRV_NWNAME_SPDI_IS_PRESENT_ERROR, 501, sim));
        return MMI_FALSE;
    }

    for (i = 0; i < cntx->spdi_num; i++)
    {
        applib_plmn_convert_bcd_2_string(
            cntx->spdi_plmn[i],
            SRV_NW_NAME_PLMN_BCD_SIZE,
            sim_plmn,
            SRV_MAX_PLMN_LEN + 1);

        if (srv_nw_info_get_camp_on_band(sim) == SRV_NW_BAND_PCS1900)
        {
            is_pcs1900 = KAL_TRUE;
        }

        if (applib_plmn_is_matched(sim_plmn, bcch_plmn, is_pcs1900))
        {
            SRV_NWNAME_LOG((TRC_SRV_NWNAME_SPDI_PLMN_IS_PRESENT, sim));
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

