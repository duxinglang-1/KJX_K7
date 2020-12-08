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
 *  NwInfoSrvAttach.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Handling of NW_ATTACH_IND related info.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MMI_NW_INFO_SRV_H__
#define __MMI_NW_INFO_SRV_H__

/****************************************************************************
 * Include
 ****************************************************************************/

#include "NwInfoSrvGprot.h"
#include "MMI_common_app_trc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"


#define SRV_NW_INFO_TRC_GROUP MMI_COMMON_TRC_G3_NETWORK


/****************************************************************************
 * Typedef
 ****************************************************************************/

typedef struct
{
    MMI_BOOL first_availability_emitted;
    srv_nw_info_service_availability_enum service_availability;
    mmi_network_enum protocol;
    srv_nw_info_capability_bit_set cell_capability;
    srv_nw_info_capability_bit_set channel_capability;
    srv_nw_info_sim_dn_status_bit_set dn_status;
    MMI_BOOL sim_is_rejected;
    
    struct
    {
        U8 strength_in_percentage;
        srv_nw_band_enum gsm_band;
        S16 gsm_RSSI_in_qdBm;
#ifdef __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    } signal;
    
    srv_nw_info_location_info_struct location;
    MMI_BOOL is_roaming;
#ifdef __SRV_NW_INFO_CIPHER_SUPPORT__
    srv_nw_info_cipher_info_struct cipher_info;
#endif
#ifdef __HOMEZONE_SUPPORT__
    srv_nw_info_homezone_info_struct homezone_info;
#endif
    MMI_BOOL display_fake_nw;
#ifdef __INVALID_SIM_RECOVERY__
    struct
    {
        MMI_BOOL enable_ivsr;
        MMI_BOOL is_in_test_mode;
        CHAR plmn_cs[SRV_MAX_PLMN_LEN + 1];
        CHAR plmn_ps[SRV_MAX_PLMN_LEN + 1];
    } ivsr_info;
#endif /* __INVALID_SIM_RECOVERY__ */
} srv_nw_info_cntx_struct;


/****************************************************************************
 * Functions
 ****************************************************************************/

extern srv_nw_info_cntx_struct *srv_nw_info_get_cntx(mmi_sim_enum sim);
extern MMI_BOOL srv_nw_info_nw_attach_ind_hdlr(void *msg, S32 src_mod);

extern MMI_BOOL srv_nw_info_update_sim_dn_status(
                    srv_nw_info_cntx_struct *cntx,
                    mmi_sim_enum sim,
                    l4c_gprs_status_enum gprs_status);

extern srv_nw_info_capability_bit_set srv_nw_info_map_cell_capability(
    mmi_network_enum protocol,
    U32 l4_bit_set);

extern MMI_BOOL srv_nw_info_rx_level_ind_hdlr(void *msg, S32 src_mod);

extern void srv_nw_info_post_roaming_changed(mmi_sim_enum sim, MMI_BOOL is_roaming_now);

#endif /* __MMI_NW_INFO_SRV_H__ */
