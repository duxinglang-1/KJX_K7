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
 *  SimCtrlSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  The implementation of SIM control service.
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

#ifndef __SIM_CTRL_SRV_H__
#define __SIM_CTRL_SRV_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "SimCtrlSrvGprot.h"
#include "MMI_common_app_trc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"


#define SRV_SIM_CTRL_TRC_GROUP MMI_COMMON_TRC_G3_SIM_CTRL


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef enum
{
    SRV_SIM_CTRL_HPLMN_PRI_NONE = 0,
    SRV_SIM_CTRL_HPLMN_PRI_IMSI,
    SRV_SIM_CTRL_HPLMN_PRI_EHPLMN,
    SRV_SIM_CTRL_HPLMN_PRI_ENS,

    SRV_SIM_CTRL_HPLMN_PRI_END_OF_ENUM
} srv_sim_ctrl_hplmn_pri_enum;

typedef struct
{
    /*
     * For SIM hot swap. When power-on or PLUG_IN is detected, is_initializing
     * will be set to TRUE first, and reset to FALSE after received
     * PASSWORD_REQUIRED_IND(NO_REQUIRED).
     */
    MMI_BOOL is_initializing;
    
    MMI_BOOL is_available;
    srv_sim_ctrl_ua_cause_enum unavailable_cause;
    srv_sim_ctrl_change_check_enum change_check;
    CHAR imsi[SRV_MAX_IMSI_LEN + 1];
    srv_sim_ctrl_hplmn_pri_enum home_plmn_priority;
    U8 mnc_len_in_ef_ad;
    U8 home_plmn_length;
    CHAR home_plmn[SRV_MAX_PLMN_LEN + 1];
    MMI_BOOL is_refreshing;
    MMI_BOOL is_usim;
#ifdef	__INVALID_SIM_RECOVERY__
    MMI_BOOL is_recovering_invalid_sim;
    CHAR chv1[SRV_SIM_CTRL_MAX_CHV_LEN];
    CHAR temp_chv1[SRV_SIM_CTRL_MAX_CHV_LEN];
#endif //
#ifdef __R7_EHPLMN__
    struct
    {
        MMI_BOOL is_valid;
        S8 num;
        CHAR plmn[SRV_SIM_CTRL_MAX_EHPLMN_ENTRIES_NUM][SRV_MAX_PLMN_LEN + 1];
    } ehplmn;
#endif

    struct
    {
        U8 chv1;
        U8 chv2;
        U8 ubchv1;
        U8 ubchv2;
    } n_remaining_attempts;

    struct
    {
        MMI_BOOL chv1_enabled;
        MMI_BOOL chv1_verified;
        MMI_BOOL chv2_enabled;
        MMI_BOOL chv2_verified;
    } chv_status;
} srv_sim_ctrl_sim_cntx_struct;


/****************************************************************************
 * Functions
 ****************************************************************************/

extern mmi_ret srv_sim_ctrl_veri_init(mmi_event_struct *evt);
extern mmi_ret srv_sim_ctrl_adp_init(mmi_event_struct *evt);
extern srv_sim_ctrl_sim_cntx_struct *srv_sim_ctrl_get_sim_cntx(mmi_sim_enum sim);
extern void srv_sim_ctrl_update_chv_info(mmi_sim_enum sim, const sim_chv_info_struct *chv_info);

extern void srv_sim_ctrl_emit_change_events(
    mmi_sim_enum sim,
    srv_sim_ctrl_sim_cntx_struct *sim_cntx,
    MMI_BOOL is_available_before,
    srv_sim_ctrl_ua_cause_enum unavailable_cause_before,
    MMI_BOOL force_to_emit,
    MMI_BOOL post);

extern MMI_BOOL srv_sim_ctrl_password_required_ind_hdlr(mmi_sim_enum sim, void *msg);
extern MMI_BOOL srv_sim_ctrl_smu_fail_ind_hdlr(mmi_sim_enum sim, void *msg);
extern MMI_BOOL srv_sim_ctrl_is_type_of_valid_chv_info(kal_uint16 type);
extern void srv_sim_ctrl_set_sim_available(srv_sim_ctrl_sim_cntx_struct *sim_cntx, MMI_BOOL avai, srv_sim_ctrl_ua_cause_enum ua_cause);

#endif /* __SIM_CTRL_SRV_H__ */

