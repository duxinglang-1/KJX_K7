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
 * Filename:
 * ---------
 *  DmSrvOtap.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM service over the air provisioning header file
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __DM_SRV_OTAP_H__
#define __DM_SRV_OTAP_H__

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "MMIDataType.h"
#include "DMTypeDef.h"
#include "Common_nvram_editor_data_item.h"
#include "CcaSrvGprot.h"

/****************************************************************************
 * Define
 ****************************************************************************/

/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef enum
{
    SRV_DM_OTAP_CCA_NS_BOOTSTRAP,
    SRV_DM_OTAP_CCA_NS_PROXY,
    SRV_DM_OTAP_CCA_NS_APPLICATION,
    SRV_DM_OTAP_CCA_NS_PORT,
    SRV_DM_OTAP_CCA_NS_PXAUTHINFO,
    SRV_DM_OTAP_CCA_NS_APPADDR,
    SRV_DM_OTAP_CCA_NS_APPPORT,
    SRV_DM_OTAP_CCA_NS_APPAUTH,
    SRV_DM_OTAP_CCA_NS_TOTAL
} srv_dm_otap_node_symbol_enum;

typedef struct
{
    nvram_ef_dm_srv_acc_struct acc;
    U8 proxy_id[DM_MD5_HASH_LENGTH];
    MMI_BOOL match_update;
    MMI_BOOL is_valid;
} srv_dm_otap_prof_struct;

typedef struct
{
    U8 proxy_id[DM_MD5_HASH_LENGTH]; /* For mapping profile number use. */
    U32 dtcnt_id;
} srv_dm_otap_proxy_struct;

typedef struct
{
    S32 auth_level;
    dm_auth_type_enum auth_pref;
    U8 auth_name[DM_MAX_ID_STR];
    U8 auth_pw[DM_MAX_ID_STR];
    U8 auth_nonce[DM_MAX_NAME_STR];
} srv_dm_otap_auth_struct;

typedef struct
{
    S32 hConfig;
    S32 prof_id;
    U16 app_id;    
    U16 config_id;
    U8 valid_profile_num;
    U8 num_acc;
    U8 num_proxy;
    U8 iter;
    U8 num_installed;
    srv_cca_status_enum cca_status;
    srv_dm_otap_prof_struct *otap_prof;
    srv_dm_otap_proxy_struct *proxy;
} srv_dm_otap_cntx_struct;

/****************************************************************************
 * Global variable
 ****************************************************************************/

/****************************************************************************
 * Global Function
 ****************************************************************************/
extern void srv_dm_otap_cca_app_get_prof_hdlr(srv_cca_app_get_prof_ind_struct *newConfigDoc);
extern void srv_dm_otap_cca_app_configure_hdlr(srv_cca_app_configure_ind_struct *newConfigDoc);
extern void srv_dm_otap_cca_app_update_prof_hdlr(srv_cca_app_update_prof_ind_struct *newConfigDoc);
extern void srv_dm_otap_send_cca_app_get_prof_rsp(srv_cca_status_enum status);
extern void srv_dm_otap_send_cca_app_configure_rsp(srv_cca_status_enum status);
extern void srv_dm_otap_send_cca_app_update_prof_rsp(srv_cca_status_enum status);
extern void srv_dm_otap_send_app_install_prof_evt(void);
extern void srv_dm_otap_install_prof_app_rsp(srv_cca_status_enum status);
extern srv_cca_status_enum srv_dm_otap_proc_cca_nodes(
                            S32 hConfig,
                            S32 node_hdl,
                            U16 symbol,
                            cca_iterator_struct *param_list,
                            void *user_data);
extern U8 srv_dm_otap_get_valid_prof_num(void);
extern MMI_BOOL srv_dm_otap_check_otap_prof_valid(srv_dm_otap_prof_struct *otap_prof);
extern MMI_BOOL srv_dm_otap_check_curr_prof_is_to_udpate(void);
extern MMI_BOOL srv_dm_otap_check_update_status(void);
extern void srv_dm_otap_install_prof(void);
extern void srv_dm_otap_find_next_prof(void);
extern void srv_dm_otap_convert_acc(nvram_ef_dm_srv_acc_struct *dm_acc, const srv_dm_otap_prof_struct *otap_prof);
extern srv_dm_otap_prof_struct* srv_dm_otap_get_curr_prof(void);

#endif /* __DM_SRV_OTAP_H__ */
