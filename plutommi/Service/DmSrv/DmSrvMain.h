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
 *  DmSrvMain.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM service main header
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
#ifndef __DM_SRV_MAIN_H__
#define __DM_SRV_MAIN_H__

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "DmSrvIprot.h"

/****************************************************************************
 * Define
 ****************************************************************************/
#define SRV_DM_NW_MASK_IN_CALL      0x01
#define SRV_DM_NW_MASK_NO_SERVICE   0x02
#define SRV_DM_NW_MASK_IN_WAP       0x04

/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef enum
{
    SRV_DM_INIT_STATUS_IDLE,
    SRV_DM_INIT_STATUS_SRV_ON_INIT,
    SRV_DM_INIT_STATUS_SRV_INIT_FINISH,
    SRV_DM_INIT_STATUS_END
} srv_dm_init_status_enum;

typedef enum
{
    SRV_DM_INIT_FLAG_BOOTUP,
    SRV_DM_INIT_FLAG_SR,
    SRV_DM_INIT_FLAG_TOTAL
} srv_dm_init_flag_enum;

typedef struct
{
    U8 init_flag[SRV_DM_INIT_FLAG_TOTAL];
    srv_dm_init_status_enum init_status;
    U8 cbm_app_id;
    U8 nw_mask;
    MMI_BOOL is_restore_factory;
} srv_dm_main_cntx;
/****************************************************************************
 * Global variable
 ****************************************************************************/

/****************************************************************************
 * Global Function
 ****************************************************************************/
extern mmi_ret srv_dm_init(mmi_event_struct *evt);
extern void srv_dm_init_reg_cbm_app_id(void);
extern void srv_dm_init_set_flag(srv_dm_init_flag_enum flag);
extern void srv_dm_init_check_srv_finish(void);
extern void srv_dm_init_srv_finish(void);
extern void srv_dm_init_send_srv_init_finish_ind(void);
extern void srv_dm_init_ps_init_finish_ind_hdlr(void *msg);
extern void srv_dm_init_sr_result_ind_hdlr(void *msg);
extern mmi_sim_enum srv_dm_get_reg_sim(void);
extern void srv_dm_init_set_status(srv_dm_init_status_enum status);
extern srv_dm_init_status_enum srv_dm_init_get_status(void);
extern U8 srv_dm_get_cbm_app_id(void);
extern void srv_dm_defer_user_interaction(srv_dm_app_adp_evt_enum evt_id, U32 defer_time);
extern void srv_dm_cancel_defer_user_interaction(void);
extern void srv_dm_resume_user_interaction(void* arg);
extern mmi_ret srv_dm_sim_unavailable_notify_hdlr(mmi_event_struct* para);
extern mmi_ret srv_dm_restore_start_notify_hdlr(mmi_event_struct *evt);
extern MMI_BOOL srv_dm_check_restore_factory(void);
extern void srv_dm_nw_changed(void);
extern MMI_BOOL srv_dm_check_nw_available(void);
extern MMI_BOOL srv_dm_check_nw_mask(U32 mask);
extern void srv_dm_set_nw_mask(U32 mask);
extern void srv_dm_unset_nw_mask(U32 mask);
extern void srv_dm_reset_nw_mask(void);
extern mmi_ret srv_dm_nw_info_srv_avail_changed_hdlr(mmi_event_struct *evt);
extern mmi_ret srv_dm_ucm_status_change_hdlr(mmi_event_struct* evt);
extern void srv_dm_send_app_display_nmgr_popup_evt(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR* string);

#endif /* __DM_SRV_MAIN_H__ */
