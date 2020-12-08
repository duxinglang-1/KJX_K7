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
 *  DmSrvLawmo.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * DM service LAWMO header file
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
#ifndef __DM_SRV_LAWMO_H__
#define __DM_SRV_LAWMO_H__

/****************************************************************************
 * Include Files                                                                
 ****************************************************************************/
#include "mmiapi_dm_struct.h"
#include "DmSrvGprot.h"
#include "DMTypeDef.h"

/****************************************************************************
 * Define
 ****************************************************************************/
/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    SRV_DM_LAWMO_LOCK_STATUS_NONE,
    SRV_DM_LAWMO_LOCK_STATUS_ON_LOCKING,
    SRV_DM_LAWMO_LOCK_STATUS_FULLY_LOCK,
    SRV_DM_LAWMO_LOCK_STATUS_PARTIALLY_LOCK,
    SRV_DM_LAWMO_LOCK_STATUS_END
} srv_dm_lawmo_lock_status_enum;

typedef enum
{
    SRV_DM_LAWMO_WIPE_STATUS_NONE,
    SRV_DM_LAWMO_WIPE_STATUS_START,
    SRV_DM_LAWMO_WIPE_STATUS_FACTORY_RESET,
    SRV_DM_LAWMO_WIPE_STATUS_FMGR_FORMAT,
    SRV_DM_LAWMO_WIPE_STATUS_APP_WIPE,
    SRV_DM_LAWMO_WIPE_STATUS_BOOTUP_WIPE_FINISH,
    SRV_DM_LAWMO_WIPE_STATUS_END
} srv_dm_lawmo_wipe_status_enum;

//#if 0
typedef enum
{
    MMI_DMUI_REPORT_MARK_NEED_NOT_REPORT,
    MMI_DMUI_REPORT_MARK_NOT_REPORT,
    MMI_DMUI_REPORT_MARK_REPORT,
    MMI_DMUI_REPORT_MARK_TOTAL
} mmi_dmui_report_mark_enum;

typedef enum
{
    MMI_DMUI_MO_SPECIAL_APP_LAWMO_LOCK_IDLE,
    MMI_DMUI_MO_SPECIAL_APP_LAWMO_WIPE_FMGR,
    MMI_DMUI_MO_SPECIAL_APP_SCOMO_JAVA,
    MMI_DMUI_MO_SPECIAL_APP_TOTAL
} mmi_dmui_mo_special_app_enum;

typedef struct
{
    mmi_dmui_app_id_enum        app_id;
    mmi_dmui_mo_type_enum       mo_type;
    void                        *callback;
    mmi_dmui_report_mark_enum   report_mark;
    mmi_dmui_status_enum        status;
} mmi_dmui_mo_register_info_struct;

typedef struct
{
    U8 max_reg_app;
    mmi_dmui_cmd_enum mo_cmd;
    mmi_dmui_cmd_enum curr_mo_cmd;
    mmi_dmui_mo_type_enum mo_type;
    mmi_dmui_mo_type_enum curr_mo_type;
    mmi_dmui_status_enum mo_status[MMI_DMUI_MO_TYPE_TOTAL];
    MMI_BOOL is_cmd_success;
    MMI_BOOL is_curr_cmd_success;
    MMI_BOOL is_server_cmd;
    mmi_dmui_mo_register_info_struct mo_special_reg_info[MMI_DMUI_MO_SPECIAL_APP_TOTAL];
    mmi_dmui_mo_register_info_struct mo_reg_info[
                                #ifdef __DM_LAWMO_SUPPORT__
                                        (S32)MMI_DMUI_APP_ID_TOTAL * 2 +
                                #endif /* __DM_LAWMO_SUPPORT__ */
                                #ifdef __DM_SCOMO_SUPPORT__
                                        0 +
                                #endif /* __DM_SCOMO_SUPPORT__ */
                                        1];
} mmi_dmui_mo_context_struct;
//#endif

typedef struct
{
    U8 max_reg_app;
    srv_dm_lawmo_lock_cmd_enum lock_cmd;
    srv_dm_lawmo_wipe_cmd_enum wipe_cmd;
    srv_dm_lawmo_lock_status_enum lock_status;
    srv_dm_lawmo_wipe_status_enum wipe_status;
    s32 wipe_app_number;
    MMI_BOOL is_cmd_success;
    MMI_BOOL is_curr_cmd_success;
    MMI_BOOL is_server_cmd;
} srv_dm_lawmo_context_struct;

/****************************************************************************
 * Global variable
 ****************************************************************************/

/****************************************************************************
 * Global Function
 ****************************************************************************/
extern void srv_dm_lawmo_init(void);
extern void srv_dm_lawmo_get_status_from_nvram(void);
extern void srv_dm_lawmo_req_ind_hdlr(void *msg);
extern void srv_dm_lawmo_lock_send_evt(srv_dm_lawmo_lock_cmd_enum lock_cmd);
extern void srv_dm_lawmo_wipe_send_evt(srv_dm_lawmo_wipe_cmd_enum wipe_cmd);
extern void srv_dm_lawmo_send_cmd_req(srv_dm_lawmo_lock_cmd_enum cmd);
extern void srv_dm_lawmo_send_req_ind(dm_lawmo_result_enum result);
extern void srv_dm_lawmo_get_cmd(dm_lawmo_cmd_enum cmd);
extern void srv_dm_lawmo_exe_lock_cmd(srv_dm_lawmo_lock_cmd_enum cmd);
extern void srv_dm_lawmo_exe_wipe_cmd(srv_dm_lawmo_wipe_cmd_enum cmd);

extern void mmi_dmui_lawmo_req_ind_hdlr(void *msg);
extern void mmi_dmui_send_lawmo_req_ind(dm_lawmo_result_enum result);
extern void mmi_dmui_lawmo_cmd_sender(void);
extern void mmi_dmui_lawmo_special_app_cmd_sender(mmi_dmui_mo_special_app_enum spe_app_index);
extern void mmi_dmui_lawmo_cmd_finish(void);
extern void mmi_dmui_send_lawmo_cmd_req(mmi_dmui_app_id_enum app_id, mmi_dmui_cmd_enum cmd);
extern void mmi_dmui_lawmo_cmd_rsp_hdlr(void *msg);
extern mmi_dmui_cmd_enum mmi_dmui_get_lawmo_cmd(dm_lawmo_cmd_enum cmd);
extern void mmi_dmui_switch_nw_mode(void);
extern mmi_ret mmi_dmui_switch_nw_mode_cb(mmi_event_struct *evt);

extern void mmi_dmui_change_status_on_command(void);
extern void mmi_dmui_change_status_after_command(void);
extern mmi_dmui_mo_type_enum mmi_dmui_get_mo_type(mmi_dmui_cmd_enum cmd);
extern U32 mmi_dmui_mo_switch_error_code(mmi_dmui_result_enum result);

extern void srv_dm_lawmo_save_lock_status_to_nvram(MMI_BOOL is_locked);
extern MMI_BOOL srv_dm_lawmo_get_lock_status_from_nvram(void);
extern void srv_dm_lawmo_save_wipe_status_to_nvram(MMI_BOOL is_wipping);
extern MMI_BOOL srv_dm_lawmo_get_wipe_status_from_nvram(void);
extern void srv_dm_lawmo_exe_cmd(mmi_dmui_cmd_enum cmd);
#if 0
/* under construction !*/
/* under construction !*/
#endif

extern void srv_dm_lawmo_lock_report_cb(MMI_BOOL result, CHAR *debug_info);
#endif /* __DM_SRV_LAWMO_H__ */
