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
 *  EonsSrvMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the Enhanced Operator Name String (EONS).
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

#if defined(__MMI_EONS_SRV__)
#include "EonsSrvGprot.h"
#include "EonsSrvMain.h"
#include "BootupSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "NwInfoSrvGprot.h"
#include "SimAccessSrvGprot.h"
#include "GSM7BitDefaultAlphabet.h"
#include "app_plmn.h"
#include "NWNameSrvGprot.h"
#include "mmi_frm_gprot.h"

/* SMSAL header: */
#include "smsal_utils.h"

// for sim_service_table_query
#include "sim_public_api.h"

// auto add by kw_check begin
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_common_app_trc.h"
#include "MMI_common_app_trc.h"
#include "mmi_rp_srv_eons_def.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "sim_common_enums.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "Unicodexdcl.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
// auto add by kw_check end 


/****************************************************************************
 * Define
 ****************************************************************************/

/* Max. number of supported entries in the EF_SPDI. */
#define SRV_EONS_MAX_OPL_NUM            (50)

/* Size of a PLMN BCD entry. */
#define SRV_EONS_PLMN_BCD_SIZE          (3)

/* Size of a EF_OPL record. */
#define SRV_EONS_OPL_RECORD_SIZE        (8)

/*
 * Module
 */
#define SRV_EONS_MOD_OPL                (1 << 0)

#define SRV_EONS_MOD_PNN                (1 << 1)


/****************************************************************************
 * Macro
 ****************************************************************************/

/*
 * Macro: (1) set flag (2) clear flag and (3) check if flag is set.
 */
#define SRV_EONS_SET(_var, _flag)       (_var |= _flag)
#define SRV_EONS_CLR(_var, _flag)       (_var &= ~_flag)
#define SRV_EONS_HAS(_var, _flag)       (((_var & _flag) == _flag))

/* Get array size. */
#define SRV_EONS_GET_SIZE(_x)           (sizeof(_x) / sizeof(_x[0]))


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    U8      index;
    U8      plmn[SRV_EONS_PLMN_BCD_SIZE];
    U16     lac1;
    U16     lac2;
} srv_eons_opl_struct;

typedef struct
{
    MMI_BOOL            is_pending_init_req;
    U8                  module_init_mask;
    U8                  num_of_pnn_rec;
    U8                  num_of_opl_rec;
    U8                  idx_of_opl;
    U8                  num_of_opl;         /* num of valid OPL in the array */
    U16                 size_of_pnn_file;
    U16                 size_of_opl_file;
    mmi_sim_enum        sim;
    srv_eons_opl_struct opl[SRV_EONS_MAX_OPL_NUM];
} srv_eons_struct;

typedef struct
{
    U16                     record_index;
    srv_eons_struct        *eons;
    srv_eons_get_name_cb    callback;
    void                   *user_data;
} srv_eons_req_struct;

typedef struct
{
    srv_eons_struct eons[MMI_SIM_TOTAL];
} srv_eons_cntx_struct;


/****************************************************************************
 * Global variable
 ****************************************************************************/

static srv_eons_cntx_struct g_srv_eons_cntx;


/****************************************************************************
 * Prototype
 ****************************************************************************/

static void srv_eons_read_opl_record(srv_eons_struct *eons);

static void srv_eons_update_module_state(mmi_sim_enum sim, U8 module);

static mmi_ret srv_eons_handle_sim_changed_by_sat(mmi_event_struct *event);

extern kal_uint16 applib_addr_gsm7_strlen(kal_uint8 *gsm7_array, kal_uint16 size);

extern void applib_addr_gsm7_2_string(kal_uint8 *gsm7_array, kal_uint8 *buf, kal_uint16 buf_size);

/****************************************************************************
 * Function
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_eons_emit_updated
 * DESCRIPTION
 *  This function emits the EONS updated event.
 * PARAMETERS
 *  sim           : [IN]      SIM id
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_emit_updated(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_updated_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_EONS_LOG((TRC_SRV_EONS_EMIT_UPDATED, sim, 200));

    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_EONS_UPDATED);
    evt.sim = sim;

    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_get_context
 * DESCRIPTION
 *  This function gets the EONS context.
 * PARAMETERS
 *  sim           : [IN]      SIM id
 * RETURNS
 *  EONS context.
 *****************************************************************************/
static srv_eons_struct *srv_eons_get_context(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        cntx = &g_srv_eons_cntx.eons[i];

        if (cntx->sim == sim)
        {
            return cntx;
        }
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_unpack_tlv
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
static MMI_BOOL srv_eons_unpack_tlv(
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

    /* Per the EF_PNN definition, the length of the network name TLV object is
       only 1 byte. */
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

    return MMI_FALSE;
}


#if defined(__REL7__)
/*****************************************************************************
 * FUNCTION
 *  srv_eons_parse_pnn_plmn_additional_info
 * DESCRIPTION
 *  This function parses the additional information in the EF_PNN record.
 * PARAMETERS
 *  data                : [IN]      EF_PNN data
 *  size                : [IN]      Data size in bytes
 *  eons                : [OUT]     EONS name structure
 *  name_buf_size       : [OUT]     Offest to the next field in EF_PNN
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE;
 *****************************************************************************/
static MMI_BOOL srv_eons_parse_pnn_plmn_additional_info(
    U8 *data,
    U16 size,
    srv_eons_name_struct *eons,
    U16 *offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag, len, *val;
    U8 *ucs2_str;
    U8 dcs;
    U16 out_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Unpack the full network name TLV object:
     *
     *      80: PLMN Additional Information tag
     */
    *offset = 0;

    if (!srv_eons_unpack_tlv(data, size, &tag, &len, &val) || tag != 0x80)
    {
        SRV_EONS_LOG((TRC_SRV_EONS_PARSE_PNN, 602));
        return MMI_FALSE;
    }
    
    *offset = 2 + len; /* 2: tag and length */

    SRV_EONS_LOG((TRC_SRV_EONS_PARSE_PNN, 220));

    switch (val[0])
    {
        case 0x80:
            dcs = MMI_UCS2_DCS;
            break;
        case 0x81:
            dcs = MMI_UCS2_81;
            break;
        case 0x82:
            dcs = MMI_UCS2_82;
            break;
        default:
            dcs = 0; /* invalid or not supported */
            break;
    }

    if (dcs != 0)
    {
        ucs2_str = CovertStringForPlatform(
                    (val + 1),
                    (U16)(len - 1),
                    dcs,
                    &out_len);

        mmi_wcsncpy(eons->plmn_info, (const WCHAR *)ucs2_str, SRV_EONS_MAX_PLMN_INFO_BUF_SIZE - 1);
        mmi_mfree(ucs2_str);
    }

    return MMI_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_eons_parse_pnn_short_name
 * DESCRIPTION
 *  This function parses the short name in the EF_PNN record.
 * PARAMETERS
 *  data                : [IN]      EF_PNN data
 *  size                : [IN]      Data size in bytes
 *  eons                : [OUT]     EONS name structure
 *  name_buf_size       : [OUT]     Offest to the next field in EF_PNN
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE;
 *****************************************************************************/
static MMI_BOOL srv_eons_parse_pnn_short_name(
    U8 *data,
    U16 size,
    srv_eons_name_struct *eons,
    U16 *offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag, len, *val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Unpack the full network name TLV object:
     *
     *      45: short name for network IEI
     */
    *offset = 0;

    if (!srv_eons_unpack_tlv(data, size, &tag, &len, &val) || tag != 0x45)
    {
        SRV_EONS_LOG((TRC_SRV_EONS_PARSE_PNN, 601));
        return MMI_FALSE;
    }

    *offset = 2 + len; /* 2: tag and length */

    SRV_EONS_LOG((TRC_SRV_EONS_PARSE_PNN, 210));

    /* TODO: support PNN short name */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_parse_pnn_full_name
 * DESCRIPTION
 *  This function parses the full name in the EF_PNN record.
 * PARAMETERS
 *  data                : [IN]      EF_PNN data
 *  size                : [IN]      Data size in bytes
 *  eons                : [OUT]     EONS name structure
 *  name_buf_size       : [OUT]     Offest to the next field in EF_PNN
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_eons_parse_pnn_full_name(
    U8 *data,
    U16 size,
    srv_eons_name_struct *eons,
    U16 *offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 tag, len, *val;
    U8 coding_scheme, num_of_spare_bits;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * Unpack the full network name TLV object:
     *
     *      43: full name for network IEI
     */
    *offset = 0;

    if (!srv_eons_unpack_tlv(data, size, &tag, &len, &val) || tag != 0x43)
    {
        SRV_EONS_LOG((TRC_SRV_EONS_PARSE_PNN, 600));
        return MMI_FALSE;
    }

    *offset = 2 + len; /* 2: tag and length */

    /* Shall contain at least one byte of the text string. */

    if (len >= 2)
    {
        /* ext(1)  coding_scheme(3)  Add_CI(1)  Num_of_spare_bits (3) */
        coding_scheme = (val[0] & 0x70) >> 4;
        num_of_spare_bits = (val[0] & 0x07);

        /* Jump to the text string field. */
        val = val + 1;
        len = len - 1;

        /*
         * Octets (packed GSM 7-bit default alphabet) in EF_PNN.
         */
        if (coding_scheme == 0)
        {
            U8 *gsm_str;
            U8 *ucs2_str;
            U16 len_in_character, out_len;

            SRV_EONS_LOG((TRC_SRV_EONS_PARSE_PNN, 200));

            /* Unpack the packed 7-bit default alphabet.

               If the number of spare bits is 7, to avoid the situation where
               the receiving entity confuses 7 binary zero pad bits as @
               character, the <CR> character shall be used for padding in this
               situation. (TS 23.038) */
            if (num_of_spare_bits == 7)
            {
                val[len - 1] &= 0x01; /* clear */
                val[len - 1] |= 0x1A; /* set as <CR> */
            }

            len_in_character = applib_addr_gsm7_strlen(val, len);
            gsm_str = mmi_malloc(len_in_character+1);

            applib_addr_gsm7_2_string(val, gsm_str, len_in_character + 1);

            // remove last space of the string
            while (gsm_str[len_in_character-1] == 0x20)
            {
                len_in_character--;
            }

            /* Convert 7-bit default alphabet to UCS2 string. */
            ucs2_str = CovertStringForPlatform(
                        gsm_str,
                        len_in_character,
                        (U8)MMI_DEFAULT_DCS,
                        &out_len);

            /* Copy to the output buffer. */
            mmi_wcsncpy(eons->full_name, (const WCHAR *)ucs2_str, SRV_EONS_MAX_BUF_SIZE - 1);

            mmi_mfree(gsm_str);
            mmi_mfree(ucs2_str);
        }

        /*
         * Octets (UCS2) in EF_PNN.
         */
        else if (coding_scheme == 1)
        {
            U8 *ucs2_str;
            U8 dcs;
            U16 out_len;

            SRV_EONS_LOG((TRC_SRV_EONS_PARSE_PNN, 201));

            switch (val[0])
            {
                case 0x80:
                    dcs = MMI_UCS2_DCS;
                    break;
                case 0x81:
                    dcs = MMI_UCS2_81;
                    break;
                case 0x82:
                    dcs = MMI_UCS2_82;
                    break;
                default:
                    dcs = 0; /* invalid or not supported */
                    break;
            }

            if (dcs != 0)
            {
                ucs2_str = CovertStringForPlatform(
                            (val + 1),
                            (U16)(len - 1),
                            dcs,
                            &out_len);

                mmi_wcsncpy(eons->full_name, (const WCHAR *)ucs2_str, SRV_EONS_MAX_BUF_SIZE - 1);
                mmi_mfree(ucs2_str);
            }
        }
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_parse_pnn
 * DESCRIPTION
 *  This function parses an EF_PNN record.
 * PARAMETERS
 *  data                : [IN]      EF_PNN data
 *  size                : [IN]      Data size in bytes
 *  name_buf            : [IN]      Name buffer
 *  name_buf_size       : [IN]      Name buffer size in WCHAR
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_parse_pnn(
    U8 *data,
    U16 size,
    srv_eons_name_struct *eons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 offset;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * PNN full name (Mandatory)
     */
    ret = srv_eons_parse_pnn_full_name(data, size, eons, &offset);
    if (!ret)
    {
        return;
    }

    /*
     * PNN short name (Optional)
     */
    data += offset;
    size -= offset;

    srv_eons_parse_pnn_short_name(data, size, eons, &offset);

    /*
     * PNN additional information (Optional)
     */
    data += offset;
    size -= offset;

#if defined(__REL7__)
    srv_eons_parse_pnn_plmn_additional_info(data, size, eons, &offset);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_parse_opl
 * DESCRIPTION
 *  This function parse an EF_OPL record.
 * PARAMETERS
 *  data            : [IN]          Data
 *  size            : [IN]          Size of 'data' in bytes
 *  opl             : [OUT]         OPL record structure
 * RETURNS
 *  On success, return MMI_TRUE; otherwise, return MMI_FALSE.
 *****************************************************************************/
static MMI_BOOL srv_eons_parse_opl(U8 *data, U16 size, srv_eons_opl_struct *opl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(data && opl);

    if (size >= SRV_EONS_OPL_RECORD_SIZE)
    {
        SRV_EONS_LOG((TRC_SRV_EONS_PRASE_OPL, 200));

        /* PLMN in BCD format */
        memcpy(opl->plmn, data, SRV_EONS_PLMN_BCD_SIZE);

        /* LAC */
        opl->lac1 = data[3] * 256 + data[4];
        opl->lac2 = data[5] * 256 + data[6];

        /* Index */
        opl->index = data[7];

        return MMI_TRUE;
    }

    SRV_EONS_LOG((TRC_SRV_EONS_PRASE_OPL, 600));

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_read_pnn_record_hdlr
 * DESCRIPTION
 *  This function handles the 'read EF_PNN' response.
 * PARAMETERS
 *  param               : [IN]          Parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_read_pnn_record_hdlr(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_req_struct *req;
    srv_eons_struct *eons;
    srv_sim_data_struct *data;
    srv_eons_name_struct *name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data && param->data);

    data = (srv_sim_data_struct *)param->data;
    req = (srv_eons_req_struct *)param->user_data;
    eons = req->eons;

    name = (srv_eons_name_struct *)mmi_malloc(sizeof(srv_eons_name_struct));

    kal_mem_set(name, 0, sizeof(srv_eons_name_struct));

    name->sim = eons->sim;

    if (!param->result || !data->length || !data->data)
    {
        SRV_EONS_LOG((TRC_SRV_EONS_READ_PNN_RECORD_HDLR, eons->sim, 600));
    }
    else
    {
        SRV_EONS_LOG((TRC_SRV_EONS_READ_PNN_RECORD_HDLR, eons->sim, 200));

        srv_eons_parse_pnn(
            data->data,
            data->length,
            name);
    }

    MMI_ASSERT(req->callback);
    req->callback(name, req->user_data);

    mmi_mfree(req);
    mmi_mfree(name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_read_pnn_record
 * DESCRIPTION
 *  This function reads the EF_PNN record.
 * PARAMETERS
 *  req             : [IN]          EONS 'read EF_PNN' request
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_read_pnn_record(srv_eons_req_struct *req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *eons;
    U16 record_size;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req && req->eons);
    eons = req->eons;

    /* Assert. Cannot divide a number by zero . */
    MMI_ASSERT(eons->num_of_pnn_rec > 0); 
    record_size = eons->size_of_pnn_file / eons->num_of_pnn_rec;

    SRV_EONS_LOG((TRC_SRV_EONS_READ_PNN_RECORD, eons->sim, 200));

    ret = srv_sim_read_record(
            (U16)FILE_PNN_IDX,
            NULL,
            req->record_index,
            record_size,
            eons->sim,
            srv_eons_read_pnn_record_hdlr,
            req);

    MMI_ASSERT(ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_read_pnn_info_hdlr
 * DESCRIPTION
 *  This function handles the EF_PNN file info.
 * PARAMETERS
 *  param           : [IN]          Parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_read_pnn_info_hdlr(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *eons;
    srv_sim_file_info_struct *info;
    sim_service_state_enum state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data && param->data);

    eons = (srv_eons_struct *)param->user_data;
    info = (srv_sim_file_info_struct *)param->data;

    /*
     * TODO: we should request SIM module to provide a unified API for this.
     */
#if (MMI_MAX_SIM_NUM >= 2)
    state = sim_service_table_query(SERVICE_PLMN_NAME,
                l4c_gemini_get_switched_sim_id((sim_interface_enum)mmi_frm_sim_to_index(eons->sim)));
#else
    state = sim_service_table_query(SERVICE_PLMN_NAME);
#endif

    if (!param->result || state != SERVICE_SUPPORT)
    {
        SRV_EONS_LOG((TRC_SRV_EONS_READ_PNN_INFO_HDLR, eons->sim, 600));
    }
    else
    {
        SRV_EONS_LOG((TRC_SRV_EONS_READ_PNN_INFO_HDLR, eons->sim, 200));

        eons->num_of_pnn_rec = info->num_of_rec;
        eons->size_of_pnn_file = info->file_size;
    }

    srv_eons_update_module_state(eons->sim, SRV_EONS_MOD_PNN);
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_read_pnn_info
 * DESCRIPTION
 *  This function reads EF_PNN file info.
 * PARAMETERS
 *  eons            : [IN]          EONS
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_read_pnn_info(srv_eons_struct *eons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(eons);

    SRV_EONS_LOG((TRC_SRV_EONS_READ_PNN_INFO, eons->sim, 200));

    ret = srv_sim_get_file_info(
            (U16)FILE_PNN_IDX,
            NULL,
            eons->sim,
            srv_eons_read_pnn_info_hdlr,
            eons);

    MMI_ASSERT(ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_read_opl_record_hdlr
 * DESCRIPTION
 *  This function handles EF_OPL record.
 * PARAMETERS
 *  param           : [IN]          Parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_read_opl_record_hdlr(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *eons;
    srv_sim_data_struct *data;
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data && param->data);

    eons = (srv_eons_struct *)param->user_data;
    data = (srv_sim_data_struct *)param->data;

    if (!param->result || !data->data || data->length < SRV_EONS_OPL_RECORD_SIZE)
    {
        SRV_EONS_LOG((TRC_SRV_EONS_READ_OPL_RECORD_HDLR, eons->sim, 600));
    }
    else
    {
        SRV_EONS_LOG((TRC_SRV_EONS_READ_OPL_RECORD_HDLR, eons->sim, 200));

        ret = srv_eons_parse_opl(
                data->data,
                data->length,
                &(eons->opl[eons->num_of_opl]));

        if (ret)
        {
            ++eons->num_of_opl;
        }
    }

    ++eons->idx_of_opl;

    srv_eons_read_opl_record(eons);
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_read_opl_record
 * DESCRIPTION
 *  This function reads one EF_OPL record.
 * PARAMETERS
 *  eons           : [IN]       EONS
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_read_opl_record(srv_eons_struct *eons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(eons);

    if (eons->idx_of_opl > eons->num_of_opl_rec ||
        eons->idx_of_opl > SRV_EONS_MAX_OPL_NUM)
    {
        SRV_EONS_LOG((TRC_SRV_EONS_READ_OPL_RECORD, eons->sim, 400));

        srv_eons_update_module_state(eons->sim, SRV_EONS_MOD_OPL);
    }
    else
    {
        SRV_EONS_LOG((TRC_SRV_EONS_READ_OPL_RECORD, eons->sim, 200));

        ret = srv_sim_read_record(
                (U16)FILE_OPL_IDX,
                NULL,
                eons->idx_of_opl,
                SRV_EONS_OPL_RECORD_SIZE,
                eons->sim,
                srv_eons_read_opl_record_hdlr,
                eons);

        MMI_ASSERT(ret);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_read_opl_info_hdlr
 * DESCRIPTION
 *  This function handles the EF_OPL file info.
 * PARAMETERS
 *  param               : [IN]          Parameter
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_read_opl_info_hdlr(srv_sim_cb_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *eons;
    srv_sim_file_info_struct *info;
    sim_service_state_enum state;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param && param->user_data && param->data);

    eons = (srv_eons_struct *)param->user_data;
    info = (srv_sim_file_info_struct *)param->data;

#if (MMI_MAX_SIM_NUM >= 2)
    state = sim_service_table_query(SERVICE_OPLMN_LIST,
                l4c_gemini_get_switched_sim_id((sim_interface_enum)mmi_frm_sim_to_index(eons->sim)));
#else
    state = sim_service_table_query(SERVICE_OPLMN_LIST);
#endif

    if (!param->result || state != SERVICE_SUPPORT || !info->num_of_rec ||
        info->file_size / info->num_of_rec < SRV_EONS_OPL_RECORD_SIZE)
    {
        SRV_EONS_LOG((TRC_SRV_EONS_READ_OPL_INFO_HDLR, eons->sim, 600));

        srv_eons_update_module_state(eons->sim, SRV_EONS_MOD_OPL);
    }
    else
    {
        SRV_EONS_LOG((TRC_SRV_EONS_READ_OPL_INFO_HDLR, eons->sim, 200));

        eons->num_of_opl_rec = info->num_of_rec;
        eons->size_of_opl_file = info->file_size;

        srv_eons_read_opl_record(eons);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_read_opl_info
 * DESCRIPTION
 *  This function reads the EF_OPL file info.
 * PARAMETERS
 *  eons           : [IN]       EONS
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_read_opl_info(srv_eons_struct *eons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(eons);

    SRV_EONS_LOG((TRC_SRV_EONS_READ_OPL_INFO, eons->sim, 200));

    ret = srv_sim_get_file_info(
            (U16)FILE_OPL_IDX,
            NULL,
            eons->sim,
            srv_eons_read_opl_info_hdlr,
            eons);

    MMI_ASSERT(ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_init_module
 * DESCRIPTION
 *  This function initializes the module of the EONS service.
 * PARAMETERS
 *  sim           : [IN]        SIM id
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_init_module(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *eons = srv_eons_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(eons);

    /*
     * Fail-safe. The ticket is used to prevent that the handset initializes
     * the EONS again when the initialization process is already ongoing.
     *
     * TODO: this function should be called again when the SIM refreshes.
     */
    if (eons->module_init_mask)
    {
        SRV_EONS_LOG((TRC_SRV_EONS_INIT_MODULE, sim, 202));

        eons->is_pending_init_req = MMI_TRUE;
    }
    else
    {
        SRV_EONS_LOG((TRC_SRV_EONS_INIT_MODULE, sim, 200));

        eons->num_of_pnn_rec = 0;
        eons->size_of_pnn_file = 0;
        eons->num_of_opl_rec = 0;
        eons->size_of_opl_file = 0;
        eons->idx_of_opl = 1;       /* SIM record index starts from 1, not 0. */
        eons->num_of_opl = 0;

        SRV_EONS_SET(eons->module_init_mask, SRV_EONS_MOD_OPL);
        srv_eons_read_opl_info(eons);

        SRV_EONS_SET(eons->module_init_mask, SRV_EONS_MOD_PNN);
        srv_eons_read_pnn_info(eons);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_update_module_state
 * DESCRIPTION
 *  This function updates the module state.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_eons_update_module_state(mmi_sim_enum sim, U8 module)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *eons = srv_eons_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_EONS_LOG((TRC_SRV_EONS_UPDATE_MODULE_STATE, sim, 200, module));

    MMI_ASSERT(eons);

    SRV_EONS_CLR(eons->module_init_mask, module);

    if (eons->module_init_mask == 0)
    {
        if (eons->is_pending_init_req)
        {
            srv_eons_init_module(sim);
            eons->is_pending_init_req = MMI_FALSE;
        }
        else
        {
            srv_eons_emit_updated(sim);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_handle_bootup_before_idle
 * DESCRIPTION
 *  This function handles the bootup before idle event.
 * PARAMETERS
 *  event           : [IN]          Event
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_eons_handle_bootup_before_idle(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_EONS_LOG((TRC_SRV_EONS_HANDLE_BOOTUP_BEFORE_IDLE, 200));

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        cntx = srv_eons_get_context(mmi_frm_index_to_sim(i));
        MMI_ASSERT(cntx);
        
        if (srv_sim_ctrl_is_available(cntx->sim))
        {
            srv_eons_init_module(cntx->sim);
        }
        else
        {
            srv_eons_emit_updated(cntx->sim);
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_handle_bootup_early_init
 * DESCRIPTION
 *  This function handles the bootup early init.
 * PARAMETERS
 *  event           : [IN]      Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret srv_eons_handle_bootup_early_init(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_cntx_struct *cntx = &g_srv_eons_cntx;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_EONS_LOG((TRC_SRV_EONS_HANDLE_BOOTUP_EARLY_INIT, 200));

    kal_mem_set(cntx, 0, sizeof(srv_eons_cntx_struct));

    for (i = 0; i < MMI_SIM_TOTAL; i++)
    {
        cntx->eons[i].sim = mmi_frm_index_to_sim(i);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_handle_sim_state_changed
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  event           : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_eons_handle_sim_state_changed(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sim_ctrl_availability_changed_evt_struct *evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    evt = (srv_sim_ctrl_availability_changed_evt_struct *)event;

    MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,
              TRC_SRV_EONS_HANDLE_SIM_STATE_CHANGED,
              evt->sim,
              200,
              evt->is_available_before,
              evt->is_available_now);

    if (srv_bootup_is_completed() &&
        evt->is_available_now && !evt->is_available_before)
    {
        srv_eons_init_module(evt->sim);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_handle_service_availability_changed
 * DESCRIPTION
 *  This function handles the service availability changed event.
 *  it needs to initial eons if receive service availability during bootup
 * PARAMETERS
 *  event               : [IN]          Event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret srv_eons_handle_service_availability_changed(
    mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *evt;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    evt = (srv_nw_info_service_availability_changed_evt_struct *)event;
    MMI_ASSERT(evt);

    if (evt->new_status == SRV_NW_INFO_SA_FULL_SERVICE && srv_bootup_is_booting())
    {
        SRV_EONS_LOG((TRC_SRV_EONS_HANDLE_AVAILABILITY_CHANGED,
                evt->old_status, evt->new_status, 500, evt->sim));
        
        if (srv_sim_ctrl_is_available(evt->sim))
        {
            srv_eons_init_module(evt->sim);
            
            SRV_EONS_LOG((TRC_SRV_EONS_HANDLE_AVAILABILITY_CHANGED,
                evt->old_status, evt->new_status, 501, evt->sim));
        }
        return MMI_RET_OK;
    }

    SRV_EONS_LOG((TRC_SRV_EONS_HANDLE_AVAILABILITY_CHANGED,
                    evt->old_status, evt->new_status, 200, evt->sim));
    return MMI_RET_OK;
}


/* For the detail information, please refer to the EonsSrvGprot.h */
mmi_ret srv_eons_main_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    switch (event->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_EARLY_INIT:
            ret = srv_eons_handle_bootup_early_init(event);
            break;
            
        case EVT_ID_SRV_BOOTUP_BEFORE_IDLE:
            ret = srv_eons_handle_bootup_before_idle(event);
            break;

        case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
            ret = srv_eons_handle_sim_state_changed(event);
            break;

        case EVT_ID_SRV_NW_NAME_SIM_CHANGED_BY_SAT:
            ret = srv_eons_handle_sim_changed_by_sat(event);
            break;

        case EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED:
            ret = srv_eons_handle_service_availability_changed(event);
            break;

        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}


/* For the detail information, please refer to the EonsSrvGprot.h */
MMI_BOOL srv_eons_is_ready(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *eons = srv_eons_get_context(sim);
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (eons && !eons->module_init_mask && srv_bootup_is_completed())
    {
        ret = MMI_TRUE;
    }

    SRV_EONS_LOG((TRC_SRV_EONS_IS_READY, sim, 200, ret));

    return ret;
}


/* For the detail information, please refer to the EonsSrvGprot.h */
U8 srv_eons_is_present(mmi_sim_enum sim, const CHAR *plmn, U16 lac)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *eons = srv_eons_get_context(sim);
    srv_eons_opl_struct *opl;
    CHAR opl_plmn[SRV_MAX_PLMN_LEN + 1];
    kal_bool is_pcs1900 = KAL_FALSE;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!eons || !plmn || !srv_eons_is_ready(sim))
    {
        SRV_EONS_LOG((TRC_SRV_EONS_IS_PRESENT, sim, 500, 0));
        return 0;
    }

    for (i = 0; i < eons->num_of_opl; i++)
    {
        opl = &(eons->opl[i]);

        applib_plmn_convert_bcd_2_string(
            opl->plmn,
            SRV_EONS_PLMN_BCD_SIZE,
            opl_plmn,
            SRV_MAX_PLMN_LEN + 1);

        if (srv_nw_info_get_camp_on_band(eons->sim) == SRV_NW_BAND_PCS1900)
        {
            is_pcs1900 = KAL_TRUE;
        }

        if (applib_plmn_is_matched_ex(opl_plmn, plmn, is_pcs1900, KAL_TRUE) &&
            lac >= opl->lac1 && lac <= opl->lac2 && opl->index != 0xFF)
        {
            SRV_EONS_LOG((TRC_SRV_EONS_IS_PRESENT, sim, 200, opl->index));
            return opl->index;
        }
    }

    SRV_EONS_LOG((TRC_SRV_EONS_IS_PRESENT, sim, 200, 0));

    return 0;
}


/* For the detail information, please refer to the EonsSrvGprot.h */
MMI_BOOL srv_eons_get_name(
     mmi_sim_enum sim,
     const CHAR *plmn,
     U16 lac,
     srv_eons_get_name_cb callback,
     void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *eons = srv_eons_get_context(sim);
    srv_eons_req_struct *req;
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!eons || !plmn || !callback ||
        !srv_eons_is_ready(sim) || !srv_sim_ctrl_is_available(sim))
    {
        SRV_EONS_LOG((TRC_SRV_EONS_GET_NAME, sim, 500));
        return MMI_FALSE;
    }

    index = srv_eons_is_present(sim, plmn, lac);

    /*
     * Return if not found.
     */
    if (index == 0 || index > eons->num_of_pnn_rec)
    {
        SRV_EONS_LOG((TRC_SRV_EONS_GET_NAME, sim, 501));
        return MMI_FALSE;
    }

    /*
     * Get the EONS network name.
     */
    SRV_EONS_LOG((TRC_SRV_EONS_GET_NAME, sim, 200));

    req = (srv_eons_req_struct *)mmi_malloc(sizeof(srv_eons_req_struct));

    req->eons = eons;
    req->record_index = index;
    req->callback = callback;
    req->user_data = user_data;

    srv_eons_read_pnn_record(req);

    return MMI_TRUE;
}


/* For the detail information, please refer to the EonsSrvGprot.h */
MMI_BOOL srv_eons_default_network_name_is_needed(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *eons = srv_eons_get_context(sim);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (eons->num_of_opl == 0 && 
        eons->num_of_pnn_rec > 0 && 
        !srv_nw_info_is_roaming(sim))
    {
        return MMI_TRUE;
    }  
    
    return MMI_FALSE;
}


/* For the detail information, please refer to the EonsSrvGprot.h */
MMI_BOOL srv_eons_get_default_network_name(
     mmi_sim_enum sim,
     srv_eons_get_name_cb callback,
     void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_eons_struct *eons = srv_eons_get_context(sim);
    srv_eons_req_struct *req;
    U8 index = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!eons || !callback ||
        !srv_eons_is_ready(sim) || !srv_sim_ctrl_is_available(sim))
    {
        SRV_EONS_LOG((TRC_SRV_EONS_GET_NAME, sim, 500));
        return MMI_FALSE;
    }

    SRV_EONS_LOG((TRC_SRV_EONS_GET_NAME, sim, 200));

    req = (srv_eons_req_struct *)mmi_malloc(sizeof(srv_eons_req_struct));

    req->eons = eons;
    req->record_index = index;
    req->callback = callback;
    req->user_data = user_data;

    srv_eons_read_pnn_record(req);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_eons_handle_sim_changed_by_sat
 * DESCRIPTION
 *  This function
 * PARAMETERS
 *  event           : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_eons_handle_sim_changed_by_sat(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_name_sat_changed_evt_struct *evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(event);

    evt = (srv_nw_name_sat_changed_evt_struct *)event;

	SRV_EONS_LOG((TRC_SRV_EONS_HANDLE_SIM_CHANGED_BY_SAT, 200));

   	srv_eons_init_module(evt->sim);

    return MMI_RET_OK;
}
#endif /* defined(__MMI_EONS_SRV__) */
