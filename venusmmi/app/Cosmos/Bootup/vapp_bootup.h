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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_bootup.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal header of Venus bootup
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_BOOTUP_H__
#define __VAPP_BOOTUP_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "MMI_features.h"
#include "GlobalResDef.h"

extern "C"
{
#include "MMIDataType.h"
#include "ProcedureGprot.h"
#include "BootupSrvIprot.h"
#include "mmi_frm_gprot.h"
#include "mmi_trc.h"
}


void vapp_bootup_early_init(void);

mmi_frm_proc_result_enum vapp_bootup_start_events_timer(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

mmi_frm_proc_result_enum vapp_bootup_wait_for_gpio(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

mmi_frm_proc_ctrl_enum vapp_bootup_events_stop_on_timeout(
    void *user_data,
    const mmi_frm_proc_set_status_struct *info);

mmi_frm_proc_result_enum vapp_bootup_flow_pen_calibration(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

mmi_frm_proc_result_enum vapp_bootup_flow_disk_check(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

mmi_frm_proc_result_enum vapp_bootup_normal_init(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

mmi_frm_proc_result_enum vapp_bootup_init_sim_module(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

mmi_frm_proc_result_enum vapp_bootup_decide_mode(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

mmi_frm_proc_result_enum vapp_bootup_boot_protocol(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

mmi_frm_proc_result_enum vapp_bootup_normal_init(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

mmi_frm_proc_result_enum vapp_bootup_play_animation(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

mmi_frm_proc_ctrl_enum vapp_bootup_ani_on_proc_status_changed(
    void *user_data,
    const mmi_frm_proc_set_status_struct *set_status);


mmi_frm_proc_result_enum vapp_bootup_flow_security(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);

#ifdef __GADGET_SUPPORT__
mmi_frm_proc_result_enum vapp_widget_preinstall_widget(
    void *arg,
    const mmi_frm_proc_id_info_struct id_info);
#endif

void vapp_bootup_notify_before_idle(void);

void vapp_bootup_notify_completed(void);


#define VAPP_BOOTUP_TRC_GROUP MMI_COMMON_TRC_G3_BOOTUP


#endif /* __VAPP_BOOTUP_H__ */

