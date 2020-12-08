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
*  vapp_certman_gprot.h
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
#ifndef __VAPP_CERTMAN_GPROT_H__
#define __VAPP_CERTMAN_GPROT_H__
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "vapp_certman_cfg.h"
#include "vcp_include.h"
#include "vfx_mc_include.h"
#include "vapp_certman_types.h"
#include "FileMgrSrvGProt.h"

/*-----------------interfaces----------------------- */

typedef struct
{
    LOCAL_PARA_HDR
    module_type source_mod;
    vapp_certman_action_enum action;
    kal_bool multiple_selection_flag;
    kal_uint32 trans_id;
    VfxResId title;
    vapp_certman_cert_group_enum cert_group;
    kal_uint32 key_type;
} vapp_certman_select_cert_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    module_type src_mod;
    kal_bool action;
    kal_bool disable_install_option;
    kal_uint32 error;
    kal_uint16 mod_name;
    kal_uint32 trans_id;
    kal_wchar cert_filename[VAPP_CERTMAN_MAX_FILE_PATH_LENGTH];
} vapp_certman_invalid_cert_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    VfxBool result;
    kal_uint32 trans_id;
    kal_uint32 count;
    kal_uint32 cert_ids[VAPP_CERTMAN_CERTIFICATES_MAX];
} vapp_certman_select_cert_rsp_struct;



typedef struct
{
    LOCAL_PARA_HDR
    kal_bool action;
    module_type source_mod;
    kal_uint8 pubkey_type_num;
    kal_uint8 pubkey_types[VAPP_CERTMAN_MAX_CERT_TYPES];
    kal_uint32 key_purpose;
    module_type src_module;
    kal_uint16 mod_name;
    kal_uint32 trans_id;
    kal_wchar issuer_filename[VAPP_CERTMAN_MAX_FILE_PATH_LENGTH];
} vapp_certman_select_user_cert_ind_struct;


typedef struct
{
    LOCAL_PARA_HDR
    VfxBool result;
    kal_uint32 trans_id;
    kal_uint16 invalid_cert_action;
} vapp_certman_invalid_cert_rsp_struct;


typedef struct
{
    LOCAL_PARA_HDR
    VfxBool result;
    kal_uint32 trans_id;
    kal_uint32 personal_cert_id;
} vapp_certman_select_user_cert_rsp_struct;

/**************************************************************/

class VappCertmanInterfaces
{
public:
    static void vapp_certman_select_certificates_ind(module_type src_mod,
        vapp_certman_action_enum action,
        kal_bool multiple_selection_flag,
        VfxU32 trans_id,
        VfxResId title,
        vapp_certman_cert_group_enum cert_group,
        kal_uint32 key_type);



    static void vapp_certman_invalid_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_bool disable_install,
        VfxU32 error,
        VfxU16 mod_name,
        VfxWChar *cert_filename,
        VfxU32 trans_id);

	static VfxBool vapp_certman_invalid_cert_popup_isexist();

    static void vapp_certman_select_user_certificates_ind(
        module_type src_mod,
        kal_bool action,
        kal_uint32 key_purpose,
        kal_uint8 cert_type_len,
        kal_uint8 *cert_types,
        kal_uint16 mod_name,
        kal_wchar *issuers_filename,
        kal_uint32 trans_id);

    static void vapp_certman_init(void);
    static void vapp_certman_send_ocsp_settings(VfxU8* url);
    static void vapp_certman_set_protocol_events(void);

    static void vapp_certman_invalid_cert_hndlr(void *msg);
    static void vapp_certman_select_user_certificates_ind_hndlr(void *msg);
    static void vapp_certman_select_certificates_ind_hndlr(void *msg);

    static void vapp_certman_privkey_passwd_ind_hndlr(void* msg);
    static void vapp_certman_privkey_cnf_ind_hndlr(void* msg);

	static VfxBool isQueneFull();
	static VfxU8 numOfQuene;
};

extern "C" kal_bool mmi_certman_get_cert_label(kal_uint32 cert_id, kal_uint8 *label_buffer, kal_uint32 buf_size);
extern "C" void vapp_certman_install_handler(mmi_menu_id item_id, const WCHAR* filepath, 
                                             const srv_fmgr_fileinfo_struct* fileinfo);

/*----------------For new certman : CUI interfaces ----------------------------*/

#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
#endif /* __VAPP_CERTMAN_GPROT_H__ */
