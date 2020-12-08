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
*  vapp_certman_util.cpp
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "vfx_mc_include.h"
#include "stack_common.h"
#include "stack_msgs.h"
extern "C"{
#include "certman_api.h"
#include "PhoneSetupGprots.h"
}

#include "ctype.h"
#include "vapp_certman_cfg.h"
#include "vapp_certman_util.h"
#include "vapp_certman_gprot.h"
#include "vcp_text_view.h"

/* Pluto string */
#include "mmi_rp_vapp_certman_def.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "FileManagerResDef.h"
#include "GlobalResDef.h"
#include "FileMgrResDef.h"


VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappCertmanIfMapList);

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(VappCertmanServiceMapList);

VfxU32 VappCertmanUtil::curr_trans_id = 0;


void VappCertmanUtilities::vapp_certman_cert_strncpy(VfxU8 *Destination, VfxU8 *Source, certman_dcs_enum dcs_type, VfxU32 dest_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dcs_type == CERTMAN_DCS_ASCII)
    {
        mmi_asc_n_to_ucs2((CHAR*) Destination, (CHAR*) Source, (dest_size - ENCODING_LENGTH) / ENCODING_LENGTH);
    }
    else
    {
        mmi_ucs2ncpy((CHAR*) Destination, (CHAR*) Source, (dest_size - ENCODING_LENGTH) / ENCODING_LENGTH);
    }
}

void VappCertmanUtilities::vapp_certman_send_msg_on_queue(module_type src_mod, module_type dest_mod, void *data, msg_type msg_id)
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


void VappCertmanUtilities::vapp_certman_bootup_notify(mmi_event_struct *evt)
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
    Message.oslMsgId = (msg_type)MSG_ID_MMI_READY_NOTIFY_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}


void VappCertmanUtilities::vapp_certman_set_protocol_events(void)
{
    //SetProtocolEventHandler(vapp_certman_install_certificates_ind_handler, MSG_ID_MMI_CERTMAN_INSTALL_CERT_IND);
    SetProtocolEventHandler(VappCertmanInterfaces::vapp_certman_select_certificates_ind_hndlr, MSG_ID_MMI_CERTMAN_SELECT_CERT_IND);
    SetProtocolEventHandler(VappCertmanInterfaces::vapp_certman_invalid_cert_hndlr, MSG_ID_MMI_CERTMAN_INVALID_CERT_IND);
    SetProtocolEventHandler(VappCertmanInterfaces::vapp_certman_select_user_certificates_ind_hndlr, MSG_ID_MMI_CERTMAN_SELECT_USER_CERT_IND);

    SetProtocolEventHandler(VappCertmanInterfaces::vapp_certman_privkey_passwd_ind_hndlr, MSG_ID_CERTMAN_PRIVKEY_USAGE_PASSWORD_IND);
    SetProtocolEventHandler(
    VappCertmanInterfaces::vapp_certman_privkey_cnf_ind_hndlr,
    MSG_ID_CERTMAN_PRIVKEY_USAGE_CONFIRM_IND);
}



//////////////////////////////////////////////////////////////////////////////////////////

VappCertmanIfMapItem::VappCertmanIfMapItem(void)
{
    isvalid = VFX_FALSE;
}

VappCertmanIfMapList::VappCertmanIfMapList()
{
    list_count = 0;
}

VfxBool VappCertmanIfMapList::add (VfxU32 transid, mmi_id app_handler)
{
    for (VfxU32 i=0; i<VAPP_CERTMAN_MAX_IF_MAP_SIZE; i++)
    {
        if (list[i].isvalid == VFX_FALSE)
        {
            list[i].transid = transid;
            list[i].app_handler = app_handler;
            list[i].isvalid = VFX_TRUE;
            list_count++;
            return VFX_TRUE;
        }
    }
	return VFX_FALSE;
    //VFX_ASSERT(0);
}


VfxU32 VappCertmanIfMapList::remove_by_transid (VfxU32 transid)
{
    for (VfxU32 i=0; i<VAPP_CERTMAN_MAX_IF_MAP_SIZE; i++)
    {
        if ((list[i].transid == transid)&&(list[i].isvalid == VFX_TRUE))
        {
            list[i].isvalid = VFX_FALSE;
            list_count--;
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


VfxU32 VappCertmanIfMapList::remove_by_apphandler (mmi_id app_handler)
{
    for (VfxU32 i=0; i<VAPP_CERTMAN_MAX_IF_MAP_SIZE; i++)
    {
        if ((list[i].app_handler == app_handler)&&(list[i].isvalid == VFX_TRUE))
        {
            list[i].isvalid = VFX_FALSE;
            list_count--;
            return VFX_TRUE;
        }
    }    
    return VFX_FALSE;
}


const VappCertmanIfMapItem& VappCertmanIfMapList::get_by_trans_id(VfxU32 transid)
{
    for (VfxU32 i=0; i<VAPP_CERTMAN_MAX_IF_MAP_SIZE; i++)
    {
        if ((list[i].transid == transid)&&(list[i].isvalid == VFX_TRUE))
        {
            return list[i];
        }
    }
    return dummy_item;
}


const VappCertmanIfMapItem& VappCertmanIfMapList::get_by_app_handler(VfxU32 app_handler)
{
    for (VfxU32 i=0; i<VAPP_CERTMAN_MAX_IF_MAP_SIZE; i++)
    {
        if ((list[i].app_handler == app_handler)&&(list[i].isvalid == VFX_TRUE))
        {
            return list[i];
        }
    }
    return dummy_item;
}

////////////////////////////////////////////////////////////////////////////////////

VappCertmanServiceMapItem::VappCertmanServiceMapItem()
{
    isvalid = VFX_FALSE;
}


VappCertmanServiceMapList::VappCertmanServiceMapList()
{
    list_count = 0;
}


void VappCertmanServiceMapList::add (VfxU32 transid, void *msghndlr_obj, cleanup_fn_p fp)
{
    for (VfxU32 i=0; i<VAPP_CERTMAN_MAX_SERIVICE_MAP_SIZE; i++)
    {
        if (list[i].isvalid == VFX_FALSE)
        {
            list[i].transid = transid;
            list[i].msghndlr_obj = msghndlr_obj;
            fp = fp;
            list[i].isvalid = VFX_TRUE;
            list_count++;
            return;
        }
    }
    VFX_ASSERT(0);
}


VfxU32 VappCertmanServiceMapList::remove_by_transid (VfxU32 transid)
{
    for (VfxU32 i=0; i<VAPP_CERTMAN_MAX_SERIVICE_MAP_SIZE; i++)
    {
        if ((list[i].transid == transid)&&(list[i].isvalid == VFX_TRUE))
        {
            list[i].isvalid = VFX_FALSE;
            list_count--;
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


const VappCertmanServiceMapItem& VappCertmanServiceMapList::get_by_trans_id(VfxU32 transid)
{
    for (VfxU32 i=0; i<VAPP_CERTMAN_MAX_SERIVICE_MAP_SIZE; i++)
    {
        if ((list[i].transid == transid)&&(list[i].isvalid == VFX_TRUE))
        {
            return list[i];
        }
    }
    return dummy_item;
}

///////////////////////////////////////////////////////////////////////////////////////
VfxU32 VappCertmanUtil::generate_new_trans_id(void)
{
    return curr_trans_id++;
}


VfxU8* VappCertmanUtilities::vapp_certman_suggest_label(VfxU8* subject, certman_dcs_enum &dcs)
{
    //certman_disp_name_struct* subject = &(parsed_data_p->cert.subject);
    VfxU8** names = ((certman_disp_name_struct*)subject)->names;
    certman_dcs_enum* dcs_type = ((certman_disp_name_struct*)subject)->dcs;

    if (names[CERTMAN_NAMETYPE_COMMON_NAME])
    {
        dcs = dcs_type[CERTMAN_NAMETYPE_COMMON_NAME];
        return (VfxU8*)names[CERTMAN_NAMETYPE_COMMON_NAME];
    }
    else if (names[CERTMAN_NAMETYPE_ORGANISATION])
    {
        dcs = dcs_type[CERTMAN_NAMETYPE_ORGANISATION];
        return (VfxU8*)names[CERTMAN_NAMETYPE_ORGANISATION];
    }
    else if (names[CERTMAN_NAMETYPE_ORGANISATION_UNIT])
    {
        dcs = dcs_type[CERTMAN_NAMETYPE_ORGANISATION_UNIT];
        return (VfxU8*)names[CERTMAN_NAMETYPE_ORGANISATION_UNIT];
    }
    else if (names[CERTMAN_NAMETYPE_TITLE])
    {
        dcs = dcs_type[CERTMAN_NAMETYPE_TITLE];
        return (VfxU8*)names[CERTMAN_NAMETYPE_TITLE];
    }
    else if (names[CERTMAN_NAMETYPE_GIVEN_NAME])
    {
        dcs = dcs_type[CERTMAN_NAMETYPE_GIVEN_NAME];
        return (VfxU8*)names[CERTMAN_NAMETYPE_GIVEN_NAME];
    }
    else
        return NULL;
}


VfxU16 VappCertmanUtilities::vapp_certman_convert_error_to_string(certman_error_enum error)
{
    switch(error)
    {
    case CERTMAN_ERR_MEMFULL:
        return STR_ID_VAPP_CERTMAN_MEMORY_FULL;

    case CERTMAN_ERR_INVALID_CONTEXT:
    case CERTMAN_ERR_ACCESS_DENIED:
        return STR_ID_VAPP_CERTMAN_INVALID_CONTEXT;

    case CERTMAN_ERR_FILE_NOT_FOUND:
        return STR_ID_VAPP_CERTMAN_FILE_NOT_FOUND;

    case CERTMAN_ERR_FS_ERROR:
        return STR_GLOBAL_DRM_FS_ERROR;

    case CERTMAN_ERR_INVALID_ENCODING:
        return STR_ID_VAPP_CERTMAN_INVALID_ENCODING;

    case CERTMAN_ERR_UNSUPPORTED_CONTENT:
        return STR_ID_VAPP_CERTMAN_CORRUPTED_FILE;

    case CERTMAN_ERR_INVALID_PASSWORD:
    case CERTMAN_ERR_INCORRECT_PASSWORD:
        return STR_ID_VAPP_CERTMAN_INCORRECT_PASSWORD;

    case CERTMAN_ERR_NEED_PASSWORD:
        return STR_ID_VAPP_CERTMAN_NEED_PASSWORD;

    case CERTMAN_ERR_INVALID_JOB:
        return STR_ID_VAPP_CERTMAN_INVALID_JOB;

    case CERTMAN_ERR_INVALID_CERT_ID:
        return STR_ID_VAPP_CERTMAN_INVALID_CERT_ID;

    case CERTMAN_ERR_LABEL_EXISTS:
        return STR_ID_VAPP_CERTMAN_LABEL_EXISTS;

    case CERTMAN_ERR_DISK_FULL:
        return FMGR_FS_DISK_FULL_TEXT;

    case CERTMAN_ERR_INVALID_LABEL:
        return STR_ID_VAPP_CERTMAN_INVALID_LABEL;

    case CERTMAN_ERR_INVALID_CERT_GROUP:
        return STR_ID_VAPP_CERTMAN_INVALID_CERT_GROUP;

    case CERTMAN_ERR_INVALID_KEY_PURPOSE:
        return STR_ID_VAPP_CERTMAN_INVALID_KEY_PURPOSE;

    case CERTMAN_ERR_CERT_NOT_FOUND:
        return STR_ID_VAPP_CERTMAN_CERTIFICATE_NOT_FOUND;

    case CERTMAN_ERR_INVALID_INPUT:
        return STR_ID_VAPP_CERTMAN_INVALID_INPUT;

    case CERTMAN_ERR_INVALID_FILENAME:
        return STR_GLOBAL_INVALID_FILENAME;

    case CERTMAN_ERR_ID_ALREADY_EXISTS:
    case CERTMAN_ERR_CERT_EXISTS:
        return STR_ID_VAPP_CERTMAN_CERT_EXISTS;

    case CERTMAN_ERR_TOO_MANY_CERTS:
        return STR_ID_VAPP_CERTMAN_TOO_MANY_CERT;

    case CERTMAN_ERR_READ_ONLY:
        return STR_ID_VAPP_CERTMAN_READ_ONLY;

    case CERTMAN_ERR_CORRUPTED_DATA:
    case CERTMAN_ERR_FILE_CORRUPTED:
    case CERTMAN_ERR_INVALID_DATA:
        return STR_ID_VAPP_CERTMAN_CORRUPTED_FILE;

#ifndef __LOW_COST_SUPPORT_COMMON__
    case CERTMAN_ERR_FILE_TOO_LARGE:
        return FMGR_FS_FILE_TOO_LARGE_TEXT;
#endif

    case CERTMAN_ERR_CERT_IN_USE:
        return STR_ID_VAPP_CERTMAN_CERT_IN_USE;

    default:
        return STR_GLOBAL_NONE;
    }
}

VfxWChar* VappCertmanUtilities::vapp_certman_get_alg_string(certman_signature_alg algorithm_enum)
{
    switch(algorithm_enum)
    {
    case CERTMAN_SIGNALG_ECDSA_SHA1:
        return (VfxWChar*)L"SHAECDSA";
    case CERTMAN_SIGNALG_ECDSA_SHA224:
        return (VfxWChar*)L"SHA224ECDSA";
    case CERTMAN_SIGNALG_ECDSA_SHA256:
        return (VfxWChar*)L"SHA256ECDSA";
    case CERTMAN_SIGNALG_ECDSA_SHA384:
        return (VfxWChar*)L"SHA384ECDSA";
    case CERTMAN_SIGNALG_ECDSA_SHA512:
        return (VfxWChar*)L"SHA512ECDSA";
    case CERTMAN_SIGNALG_DSA_SHA1:
        return (VfxWChar*)L"SHADSA";
    case CERTMAN_SIGNALG_RSA_SHA1:
        return (VfxWChar*)L"SHARSA";
    case CERTMAN_SIGNALG_RSA_MD4:
        return (VfxWChar*)L"MD4RSA";
    case CERTMAN_SIGNALG_RSA_MD5:
        return (VfxWChar*)L"MD5RSA";
    case CERTMAN_SIGNALG_RSA_MD2:
        return (VfxWChar*)L"MD2RSA";
    case CERTMAN_SIGNALG_RSA_SHA256:
        return (VfxWChar*)L"SHA256RSA";
    case CERTMAN_SIGNALG_RSA_SHA384:
        return (VfxWChar*)L"SHA384RSA";
    case CERTMAN_SIGNALG_RSA_SHA512:
        return (VfxWChar*)L"SHA512RSA";
    case CERTMAN_SIGNALG_RSA_PSS_SHA1:
        return (VfxWChar*)L"PSSSHARSA";
    case CERTMAN_SIGNALG_RSA_PSS_SHA224:
        return (VfxWChar*)L"PSSSHA224RSA";
    case CERTMAN_SIGNALG_RSA_PSS_SHA256:
        return (VfxWChar*)L"PSSSHA256RSA";
    case CERTMAN_SIGNALG_RSA_PSS_SHA384:
        return (VfxWChar*)L"PSSSHA384RSA";
    case CERTMAN_SIGNALG_RSA_PSS_SHA512:
        return (VfxWChar*)L"PSSSHA512RSA";
    default:
        return (VfxWChar*)L"Unknown";
    }
}

#endif /* __COSMOS_MMI__ */
#endif /* __CERTMAN_SUPPORT__ */
