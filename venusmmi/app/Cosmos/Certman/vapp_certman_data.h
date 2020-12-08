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
 *  vapp_certman_data.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __VAPP_CERTMAN_DATA_H__
#define __VAPP_CERTMAN_DATA_H__
#ifdef __CERTMAN_SUPPORT__
#ifdef __COSMOS_MMI_PACKAGE__ 

#include "vfx_mc_include.h"
#include "vapp_certman_cfg.h"
#include "vapp_certman_msg_hndlr.h"
#include "vapp_certman_types.h"

class VappCertmanDataUser
{
public:
    /* Notification funtion to nottfy data users */
    virtual void VappCertmanDataRspHndlr(void* msg)=0;
};

class VappCertmanCertListDataItem
{
    friend class VappCertmanCertListData;
    friend class VappCertmanViewKeyUsagePage;

    VfxU32 cert_prop;
    VfxU32 cert_group;
    VfxBool selected;
    VfxU32 key_purpose;
    VfxU32 certificate_dcs;
    VfxU32 key_purpose_change;
    VfxU32 key_purpose_all;
    VfxU32 cert_id;
    VfxU8 cert_label[CERTMAN_LABEL_SIZE];
    applib_time_struct not_before;
    applib_time_struct not_after;

public:
    VfxU8* getcertlabel(void);
    VfxU32 getcertid(void);
    VfxU32 getcertprop(void);
    VfxU32 getcertgroup(void);
    VfxU32 getdcs(void);
    VfxU32 getkeypurpose(void);
    applib_time_struct getnotbefore(void);
    applib_time_struct getnotafter(void);

    VfxBool is_selected(void) const;
    void toggle_select(void);
    VappCertmanCertListDataItem(void);
};


class VappCertmanCertListData : public VappCertmanMsgHndlrUser
{
    VfxU32 key_type;
    VfxU32 cert_group;

    /*-------------------------------------------------------*/

    typedef enum
    {
        REQ_STATE,
        DATA_STATE
    }vapp_certman_data_by_issuer_file_state_enum;

    /* make flags if more members */
    VfxBool get_by_issue_file;

    VfxU32 key_purpose;
    VfxU8 pubkey_types[VAPP_CERTMAN_NUM_KEYTYPE_IN_LIST];
    VfxU8 pubkey_type_num;
    VfxWChar issuer_filename[VAPP_CERTMAN_MAX_FILE_PATH_LENGTH];
    vapp_certman_data_by_issuer_file_state_enum state;

    /*-------------------------------------------------------*/

    VfxU32 certificate_count;
    mutable VappCertmanCertListDataItem certificate_list_item[CERTMAN_NUM_CERT_IN_DATABASE];

    VappCertmanDataUser *data_user_obj;

    void getlist(void);
    void updatelist(void);
    void finishgetlist(void);

    void getlistbyissuerfile(void);

    VappCertmanMsgHndlr msghndlr;
    void VappCertmanGenericRspHndlr(void* msg);

    void cert_list_by_group_cnf_hndlr(void* msg);
    void cert_list_by_issue_file_cnf(void* msg);

public:
    VappCertmanCertListDataItem* get_cert_list_item(VfxU32 index) const;
    VfxU32 get_cert_count(void) const;
    VappCertmanCertListData(VfxU32 cert_group, VfxU32 key_type ,VappCertmanDataUser* data_user_obj);

    /*------------------------------------------------------------------------------------------*/
    VappCertmanCertListData(VfxU32 key_purpose, VfxU32 cert_group, 
        VfxU32 *pubkey_types, VfxU32 pubkey_type_num,
        VfxWChar *issuer_filename, VappCertmanDataUser* data_user_obj);
    /*------------------------------------------------------------------------------------------*/

    /* After first creation data may need to be refeshed. This would be trigger from outside*/
    void refresh(void);
};

class VappCertmanCertFileData :public VappCertmanMsgHndlrUser
{
    typedef enum
    {
        PARSE_BEGIN_CNF_RECIEVED = 0x01
    }file_data_state_enum;

    VfxWChar filename[VAPP_CERTMAN_MAX_FILE_PATH_LENGTH];
    VappCertmanDataUser *data_user_obj;
    VappCertmanMsgHndlr msghndlr;
    certman_encoding_enum encoding_type;

    VfxU32 state;
    void getdetails(void);
    void VappCertmanGenericRspHndlr(void* msg);

public:


    /* provide get functions*/
    VfxU32 job_id;
    VfxU32 cert_total;
    VfxU32 num_priv_key;
    VfxU32 num_user_cert;
    VfxU32 num_auth_cert;
    VfxU32 cert_ref_ids[CERTMAN_NUM_PARSED_CERT];


    /* functions to create file object. File object may require password. 
    check this in pre func. If password in required, call get_data_set_passwd to set password */
    VfxU32 get_data_pre_func(void);
    VfxU32 get_data_set_passwd(const VfxWChar* password);
    void get_data_post_func(void);

    /* Constructor.*/
    VappCertmanCertFileData(VfxWChar* filename, VappCertmanDataUser* data_user_obj);
    ~VappCertmanCertFileData(void);
};


/* Further break this class? */
class VappCertmanCertDetailsData : public VappCertmanMsgHndlrUser
{
    typedef enum
    {
        CERT_PARSED_DATA_RECIEVED = 0x01,
    }cert_details_data_enum;

    certman_cert_display_struct *display_p;

    certman_parsed_data_struct* parsed_data_p;

    VfxU32 cert_prop;
    VfxU32 cert_group;
    VfxU32 cert_id;
    VfxU32 job_id;
    VfxBool use_job_id;

    VfxU32 state;
    VappCertmanDataUser *data_user_obj;

    void getdetails(void);
    void VappCertmanGenericRspHndlr(void* msg);

    /* There are two type of certificate details response structure */
    void parse_cert_details_by_id_struct_func(void* msg);
    void parse_cert_details_struct_func(void* msg);

    VappCertmanMsgHndlr msghndlr;

public:

    /* private */
    VfxU8 cert_info[VAPP_CERTMAN_MAX_DISP_BUFF] ;

    VfxU8* getlabel(void);
    VfxU32 getkeypurpose(void);
    VfxU32 getcertid(void);
    VfxU32 getjobid(void);
    VfxBool IsPersonalCert(void);
    VfxU8* getsubject(void);
    VfxBool AlreadyExists(void);

    VfxU32 set_use_job_id(VfxBool val);
    VappCertmanCertDetailsData(VfxU32 cert_id, VappCertmanDataUser *user_obj);
    VappCertmanCertDetailsData(VfxU32 job_id, VfxU32 cert_id, VappCertmanDataUser *user_obj);
    void cert_details_cnf_hndlr(void* msg);
    const certman_cert_display_struct *GetDisplayStruct(void);

    ~VappCertmanCertDetailsData();
};


/* todo: too many get set */
class VappCertmanCertDetailsInputData //: public VappCertmanMsgHndlrUser
{
private: 
    VfxU8 label[CERTMAN_LABEL_SIZE];
    VfxU32 keyusage_all;
    certman_privkey_protection_enum keyprotection;
    VfxU8 key_protection_passwd[CERTMAN_PASSWORD_SIZE *ENCODING_LENGTH];

public:

    VfxU32 keyusage;
    VfxWChar* getlabel(void);
    VfxU32 getallkeyusage(void);
    VfxU8* getpasswd(void);
    VfxU32 getkeyprotection(void);
    
    /* functions to be called by UI elements in this order. These use message handler internally */
    void set_label(VfxU8* label);
    void set_key_usage(VfxU32 key_usage);
    void set_key_protection_method(certman_privkey_protection_enum protection_method);
    void set_key_protection_password(VfxU8* password);
    void set_key_protection(certman_privkey_protection_enum protection_method, VfxU8* password);
    VappCertmanCertDetailsInputData(VfxU32 key_purpose, VfxU32 key_purpose_all);
};



/* This data class does not ask for data from certman but gets it through constructor */
class VappCertmanKeyUsageListData : public VappCertmanMsgHndlrUser
{
    VfxU32 key_purpose_changed;

    VfxU32 count_key_usages;
    VfxWString all_key_usage_list[VAPP_CERTMAN_TOTAL_KEY_USAGE];
    VappCertmanMsgHndlr msghndlr;
    void VappCertmanGenericRspHndlr(void* msg);

public:
    VfxU32 key_purpose;
    VfxU32 key_purpose_all;
    VfxU8 list_of_state[VAPP_CERTMAN_TOTAL_KEY_USAGE]; /* copy data from user input here */
    VappCertmanKeyUsageListData(VfxU32 key_purpose_all, VfxU32 key_purpose);
    void VappCertmanCommitKeyUsageData(VfxU32 cert_id);
    VfxU32 get_key_usage_count(void) const;
    VfxWString& get_all_key_usage_list_item(VfxU32 index);
};



/**/

class VappCertmanReqDataBase : public VappCertmanMsgHndlrUser
{
protected:
    certman_error_enum status;
    VappCertmanDataUser *data_user_obj;
    VappCertmanMsgHndlr msghndlr;
public:
    VappCertmanReqDataBase(VappCertmanDataUser *data_user_obj);
};


class VappCertmanDeleteReqData : public VappCertmanReqDataBase
{
    void VappCertmanGenericRspHndlr(void* msg);
public:
    VappCertmanDeleteReqData(VfxU32 cert_id, VappCertmanDataUser *data_user_obj);
};

/* 30/09/2010  */
class VappCertmanKeyUsageUpdateReqData : public VappCertmanReqDataBase
{
    VfxU32 cert_id;
    VfxU32 key_purpose;
    void VappCertmanGenericRspHndlr(void* msg);
public:
    VappCertmanKeyUsageUpdateReqData(VfxU32 cert_id, VfxU32 key_purpose, VappCertmanDataUser *data_user_obj);

    VappCertmanKeyUsageUpdateReqData(VappCertmanDataUser *data_user_obj);
    void UpdateKeyUsage(VfxU32 cert_id, VfxU32 key_purpose);
};


/* to help in install */
class VappCertmanImportReqData : public VappCertmanReqDataBase
{
    void VappCertmanGenericRspHndlr(void* msg);

public:

    VfxU32 new_import_begin(VfxU32 cert_id, VfxU32 job_id);
    VfxU32 new_import_set_label(VfxU8* label, certman_dcs_enum dcs_type);
    VfxU32 new_import_set_priv_key_protection(certman_privkey_protection_enum protection_method, VfxU8* password);
    void new_import_req(void);

    VappCertmanImportReqData(VappCertmanDataUser *data_user_obj);
};

#endif /* __COSMOS_MMI_PACKAGE__   */
#endif /* __CERTMAN_SUPPORT__ */
#endif /* __VAPP_CERTMAN_DATA_H__ */
