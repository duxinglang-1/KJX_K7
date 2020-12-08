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
 *  DmSrvFota.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM service FOTA manager header file.
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
#ifndef __DM_SRV_FOTA_H__
#define __DM_SRV_FOTA_H__

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "DMTypeDef.h"
#include "DmSrvGprot.h"
/****************************************************************************
 * Define
 ****************************************************************************/
/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef enum
{
    SRV_DM_FOTA_STATUS_IDLE,
    SRV_DM_FOTA_STATUS_USER_QUERY,
    SRV_DM_FOTA_STATUS_UPDATE_WAIT_CNF,
    SRV_DM_FOTA_STATUS_UPDATE_DEFER,
    SRV_DM_FOTA_STATUS_UPDATE_CNF,
    SRV_DM_FOTA_STATUS_REBOOT,
    SRV_DM_FOTA_STATUS_END
} srv_dm_fota_status_enum;

typedef struct
{
    srv_dm_fota_status_enum status;
    dm_ui_mode_enum ui_mode;
    srv_dm_fota_query_cb_func_type query_cb;
    void *query_user_data;
} srv_dm_fota_cntx_struct;

/****************************************************************************
 * Global variable
 ****************************************************************************/

/****************************************************************************
 * Global Function
 ****************************************************************************/
extern void srv_dm_fota_init(void);
extern void srv_dm_fota_set_status(srv_dm_fota_status_enum status);
extern srv_dm_fota_status_enum srv_dm_fota_get_status(void);
extern void srv_dm_fota_bootup_check_update(void);
extern void srv_dm_fota_update_req_ind_hdlr(void *msg);
extern void srv_dm_fota_send_update_rsp(dm_ui_interaction_enum result);
extern void srv_dm_fota_send_app_update_evt(void);
extern void srv_dm_fota_update_app_rsp(dm_ui_interaction_enum result, U32 defer_time);
extern void srv_dm_fota_reset_ind_hdlr(void *msg);
extern void srv_dm_fota_resume_update_notify(void);
extern void srv_dm_fota_query_send_user_init_fota_req(void);
extern void srv_dm_fota_query_user_init_fota_rsp_hdlr(void *msg);
extern void srv_dm_fota_query_report_app(srv_dm_fota_query_result_enum result);
extern void srv_dm_fota_query_finish(srv_dm_fota_query_result_enum result);

#endif /* __DM_SRV_FOTA_H__ */
