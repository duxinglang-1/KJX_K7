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
 *  DmSrvDl.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM service download manager header file
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __DM_SRV_DL_H__
#define __DM_SRV_DL_H__

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "DMTypeDef.h"
#include "DlAgentSrvGProt.h"

/****************************************************************************
 * Define
 ****************************************************************************/
/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef enum
{
    SRV_DM_DL_STATUS_IDLE,
    SRV_DM_DL_STATUS_DL_WAIT_CNF,
    SRV_DM_DL_STATUS_DOWNLOADING,
    SRV_DM_DL_STATUS_SUSPEND,
    SRV_DM_DL_STATUS_PKG_FINISH,
    SRV_DM_DL_STATUS_FINISH,
    SRV_DM_DL_STATUS_END
} srv_dm_dl_status_enum;

typedef struct
{
    srv_dm_dl_status_enum status;
    S32 session_id;
    MMI_BOOL auto_resume;
    U32 percent;
    dm_start_dl_res_ind_struct *dl_ind_info;
} srv_dm_dl_cntx_struct;

/****************************************************************************
 * Global variable
 ****************************************************************************/

/****************************************************************************
 * Global Function
 ****************************************************************************/
extern void srv_dm_dl_init(void);
extern void srv_dm_dl_receive_upc_file(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        PU16 filepath,
        PS8 url,
        PS8 mime_type_string);
extern void srv_dm_dl_da_fumo_setting(
        S32 session_id,
        S32 mime_type,
        S32 mime_subtype,
        S32 action,
        U32 filesize,
        S8 *url,
        S8 *mime_type_string,
        U32 content_len,
        S8 *content,
        srv_da_setting_struct *setting);
extern void srv_dm_dl_set_status(srv_dm_dl_status_enum status);
extern srv_dm_dl_status_enum srv_dm_dl_get_status(void);
extern void srv_dm_dl_start_dl_ind_hdlr(void *msg);
extern void srv_dm_dl_start_oma_dl(void);
extern void srv_dm_dl_send_app_dl_start_evt(void);
extern void srv_dm_dl_start_oma_dl_cb_hdlr(BOOL success);
extern void srv_dm_dl_da_report_hdlr(
        S32 session_id,
        S32 status,
        S32 error,
        U32 seq_num,
        U32 acc_size,
        U32 total_size);
extern void srv_dm_dl_send_app_dl_progress_evt(U32 acc_size, U32 total_size);
extern void srv_dm_dl_progress_app_rsp(dm_dl_status_enum status);
extern void srv_dm_dl_send_app_dl_finish_evt(S32 status, S32 error);
extern MMI_BOOL srv_dm_dl_check_suspend(void);
extern void srv_dm_dl_suspend(void);
extern void srv_dm_dl_auto_resume_timeout_hdlr(void);
extern void srv_dm_dl_send_report_ind(dm_dl_status_enum status);
extern U32 srv_dm_dl_get_curr_percent(void);

#endif /* __DM_SRV_DL_H__ */
