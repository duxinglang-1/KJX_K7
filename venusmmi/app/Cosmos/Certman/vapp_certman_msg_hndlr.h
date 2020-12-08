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
*  vapp_certman_msg_hndlr.h
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#ifndef __VAPP_CERTMAN_MSG_HNDLR_H__
#define __VAPP_CERTMAN_MSG_HNDLR_H__
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "vfx_mc_include.h"
extern "C"{
#include "certman_api.h"
}

/* Message handler user class. The user of message handler must derive from this */
class VappCertmanMsgHndlrUser
{
public:
    /* Notification funtion to noitfy message handler users */
    virtual void VappCertmanGenericRspHndlr(void* msg)=0;
};

/* Message handler class. This class is responsible for handling messages to and from certman task */
class VappCertmanMsgHndlr
{

    typedef enum
    {
        PARSE_CTX_CREATED = 0x01,
        IMPORT_CTX_CREATED = 0x02
    }msghndlr_state_enum;

    VfxU32 more; /* To know if request data is recieved through more than one primitive */
    VfxU32 trans_id;
    /* some certman API's require these to be provided as handle.*/
    certman_ctx_parse_struct *ctx_parse_p; 
    certman_ctx_import_struct *ctx_import_p;

    void free_ctx_parse(void);
    void free_ctx_import(void);

    /* User object */
    VappCertmanMsgHndlrUser *user_obj;

    void onInit(void);
    VfxU32 state;
public:

    /*----------------------------------CERT LIST REQS-------------------------------------------*/
    void get_cert_list_by_group(VfxU32 cert_group, VfxU32 key_type);
    void get_cert_details_by_id(VfxU32 cert_id);
    void delete_cert(VfxU32 cert_id);
    void get_cert_list_by_issuers_file(VfxU32 cert_group,
        VfxU32 key_purpose,
        VfxU8 pubkey_types[CERTMAN_NUM_KEYTYPE_IN_LIST],
        VfxU8 num_types,
        const VfxWChar *issuers_filename);

    /*------------------------------INSTALL and INVALID START REQS----------------------------------*/
    VfxU32 verify_file_before_parse(VfxWChar* filename_p, certman_encoding_enum &encoding_type);
    VfxU32 set_file_decrypt_password(VfxU8* password);
    void parse_begin_req(void);
    void get_parse_details_req(VfxU32 cert_id, VfxU32 job_id);

    /*------------------------------INSTALL and INVALID END REQS-------------------------------------*/
    VfxU32 new_import_begin(VfxU32 cert_id, VfxU32 job_id);
    VfxU32 new_import_set_label(VfxU8* label, certman_dcs_enum dcs_type);
    VfxU32 new_import_set_priv_key_protection(certman_privkey_protection_enum protection_method, VfxU8* password);
    void new_import_req(void);
    void send_parse_end_req(VfxU32 job_id);


    /*-----------------------------------------------------------------------------------------------*/
    void get_cert_list_by_issuers_file_req(VfxU32 cert_group, VfxU32 key_purpose, VfxU8 *pubkey_types, VfxU8 num_types, const VfxWChar *issuers_filename);


    /* Clean up funtion in case objects are destroyed before certman task response */
    static void send_parse_end_req_cleanup(void* msg);
    static void parsed_data_free(void* msg);

    void update_key_purpose(VfxU32 cert_id, VfxU32 key_purpose);

    /* todo: make these private. Call them from destructor only */
    //done

    /* Set "more" member variable */
    void setmore(VfxS32 arg);

    /* Set and get user objects */
    VappCertmanMsgHndlrUser * get_user_obj(void);
    void set_user_obj(VappCertmanMsgHndlrUser * obj);

    /* Cnf from certman task handled here  */
    static void GenericCnfHndlr(void* msg);

    /* Contructors */
    VappCertmanMsgHndlr(VappCertmanMsgHndlrUser* obj);
    VappCertmanMsgHndlr(void);

    ~VappCertmanMsgHndlr(void);
};

/* certman task must not change order of these items */
typedef struct
{
    kal_uint8               ref_count;
    kal_uint16              msg_len;
    kal_uint32              trans_id;   /* application transaction ID. Using this to get message handler object */
}vapp_certman_generic_rsp_struct;

#endif /* __COSMOS_MMI_PACKAGE__  */
#endif /* __CERTMAN_SUPPORT__ */
#endif /* __VAPP_CERTMAN_MSG_HNDLR_H__ */
