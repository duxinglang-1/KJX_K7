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
 *  vapp_certman_pluto_adaptor.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "FileMgrSrvGProt.h"
#include "mmi_frm_queue_gprot.h"
#include "vapp_certman_types.h"
#include "MenuCuiGprot.h"
#include "mmi_rp_vapp_certman_def.h"
#include "vapp_certman_pluto_adaptor.h"
#include "CertmanMMIGprots.h"

#ifdef __cplusplus
extern "C"{
#endif
#include "certman_api.h"
#ifdef __cplusplus
}
#endif

#include "GlobalResDef.h"
#include "mmi_frm_mem_gprot.h"


void mmi_certman_bootup_notify(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_CERTMAN;
    Message.oslMsgId = MSG_ID_MMI_READY_NOTIFY_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


kal_bool mmi_certman_get_cert_label(kal_uint32 cert_id, kal_uint8 *label_buffer, kal_uint32 buf_size)
{
    certman_error_enum error;
    certman_dcs_enum dcs_type;
    U8* temp_buff;
    temp_buff = OslMalloc(buf_size);
    if (cert_id == 0)
    {
        mmi_ucs2ncpy((CHAR*) label_buffer, (CHAR*) GetString(STR_GLOBAL_NONE), buf_size);
        OslMfree(temp_buff);
        return KAL_TRUE;
    }
    error = certman_get_cert_label(cert_id, temp_buff, buf_size, &dcs_type);
    if (error == CERTMAN_ERR_NONE)
    {
        if (dcs_type == CERTMAN_DCS_ASCII)
        {
            mmi_asc_n_to_ucs2((CHAR*) label_buffer, (CHAR*) temp_buff, (buf_size - ENCODING_LENGTH) / ENCODING_LENGTH);
        }
        else
        {
            mmi_ucs2ncpy((CHAR*) label_buffer, (CHAR*) temp_buff, (buf_size - ENCODING_LENGTH) / ENCODING_LENGTH);
        }
        OslMfree(temp_buff);
        return KAL_TRUE;
    }
    OslMfree(temp_buff);
    return KAL_FALSE;
}

void mmi_certman_install_da_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action_type,
        PU16 filename,
        PS8 download_url,
        PS8 mime_type_str_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vapp_certman_install_cert_file((WCHAR*)filename);
}

void mmi_certman_send_msg_on_queue(module_type src_mod, module_type dest_mod, void *data, U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = src_mod;
    Message.oslDestId = dest_mod;
    Message.oslMsgId = msg_id;
    Message.oslSapId = MMI_CERTMAN_APP_SAP;
    Message.oslDataPtr = (oslParaType*) data;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


void mmi_certman_select_user_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_uint32 key_purpose,
        kal_uint8 cert_type_len,
        kal_uint8 *cert_types,
        kal_uint16 mod_name,
        kal_wchar *issuers_filename,
        kal_uint32 trans_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_select_user_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data =
        (mmi_certman_select_user_cert_ind_struct*)
        OslConstructDataPtr(sizeof(mmi_certman_select_user_cert_ind_struct));

    data->action = action;
    data->trans_id = trans_id;
    data->key_purpose = key_purpose;
    data->cert_type_len = cert_type_len;
    memcpy((CHAR*) data->cert_types, (CHAR*) cert_types, data->cert_type_len);
    data->mod_name = mod_name;
    data->source_mod = src_mod;
    mmi_ucs2cpy((CHAR*) data->issuer_filename, (CHAR*) issuers_filename);
    mmi_certman_send_msg_on_queue(
        src_mod,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_IND);
}


void vapp_certman_install_handler(mmi_menu_id item_id, const WCHAR* filepath, 
                     const srv_fmgr_fileinfo_struct* fileinfo)
{
    vapp_certman_install_cert_file((WCHAR*)filepath);
}


void mmi_certman_invalid_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_bool disable_install,
        kal_uint32 error,
        kal_uint16 mod_name,
        kal_wchar *cert_filename,
        kal_uint32 trans_id)
{
        /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_certman_invalid_cert_ind_struct *data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Allocate memory. */
    data = (mmi_certman_invalid_cert_ind_struct*) OslConstructDataPtr(sizeof(mmi_certman_invalid_cert_ind_struct));
    data->action = action;
    data->trans_id = trans_id;
    data->disable_install_option = disable_install;
    data->error = error;
    data->mod_name = mod_name;
    data->src_mod = src_mod;
    mmi_ucs2cpy((CHAR*) data->cert_filename, (CHAR*) cert_filename);
    /* Send the response message. */
    mmi_certman_send_msg_on_queue(
        src_mod,
        MOD_MMI,
        (void*)data,
        MSG_ID_MMI_CERTMAN_INVALID_CERT_IND);
}

#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
