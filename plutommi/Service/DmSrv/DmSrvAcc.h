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
 *  DmSrvAcc.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM service account manager header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __DM_SRV_ACC_H__
#define __DM_SRV_ACC_H__

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "mmi_include.h"
#include "DMTypeDef.h"
#include "Common_nvram_editor_data_item.h"
/****************************************************************************
 * Define
 ****************************************************************************/

/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef enum
{
    SRV_DM_ACC_INSTALL_ACC_RESULT_NEW,
    SRV_DM_ACC_INSTALL_ACC_RESULT_UPDATE,
    SRV_DM_ACC_INSTALL_ACC_RESULT_FULL,
    SRV_DM_ACC_INSTALL_ACC_RESULT_END
} srv_dm_acc_install_acc_result_enum;

typedef struct
{
    U8 curr_used_record_index;
} srv_dm_acc_cntx_struct;

/****************************************************************************
 * Global variable
 ****************************************************************************/

/****************************************************************************
 * Global Function
 ****************************************************************************/
extern void srv_dm_acc_init(void);
extern void srv_dm_acc_get_acc_req_hdlr(void *msg);
extern void srv_dm_acc_send_get_acc_cnf(dm_account_struct *acc);
extern void srv_dm_acc_save_acc_by_index(nvram_ef_dm_srv_acc_struct *acc, S32 record_index);
extern MMI_BOOL srv_dm_acc_get_acc_by_index(nvram_ef_dm_srv_acc_struct *acc, S32 record_index);
extern MMI_BOOL srv_dm_acc_get_acc_by_server_id(nvram_ef_dm_srv_acc_struct *acc, U8 *record_index, CHAR *server_id);
extern void srv_dm_acc_save_default_acc(nvram_ef_dm_srv_acc_struct *acc);
extern MMI_BOOL srv_dm_acc_get_default_acc(nvram_ef_dm_srv_acc_struct *acc);
extern void srv_dm_acc_remove_acc(void);
extern void srv_dm_acc_convert_acc_mmi_to_ps(dm_account_struct *dm_acc, const nvram_ef_dm_srv_acc_struct *nvram_acc);
extern void srv_dm_acc_convert_acc_ps_to_mmi(nvram_ef_dm_srv_acc_struct *nvram_acc, const dm_account_struct *dm_acc);
extern void srv_dm_acc_check_default_acc_valid(void);
extern void srv_dm_acc_restore_default_acc(void);
extern srv_dm_acc_install_acc_result_enum srv_dm_acc_install_acc(nvram_ef_dm_srv_acc_struct *acc);
extern MMI_BOOL srv_dm_acc_check_server_id_exist(CHAR *server_id);
extern mmi_ret srv_dm_acc_dtcnt_changed_hdlr(mmi_event_struct* evt);
extern U32 srv_dm_acc_get_curr_used_dtcnt_id(void);
extern void srv_dm_acc_get_proxy_info(kal_uint32 data_account_id, dm_proxy_info_struct *proxy_info);

#endif /* __DM_SRV_ACC_H__ */
