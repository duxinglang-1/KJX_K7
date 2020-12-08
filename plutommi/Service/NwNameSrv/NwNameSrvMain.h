/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  NwNameSrvProt.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This header is the internal header for the network name service.
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

#ifndef NW_NAME_SRV_MAIN_H
#define NW_NAME_SRV_MAIN_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "NwNameSrvGprot.h"
#include "mmi_frm_utility_gprot.h"

/****************************************************************************
 * Trace
 ****************************************************************************/

#if defined(__MTK_TARGET__)
/*
 * Only target compiler supports C99 __VA_ARGS__.
 */
#define SRV_NWNAME_LOG_EX(...) MMI_TRACE(MMI_COMMON_TRC_G3_IDLE, __VA_ARGS__)
#define SRV_NWNAME_LOG(_x)     SRV_NWNAME_LOG_EX _x

#define SRV_NWNAME_PRINT_EX(...) MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G3_IDLE, __VA_ARGS__)
#define SRV_NWNAME_PRINT(_x)     SRV_NWNAME_PRINT_EX _x
#else
#define SRV_NWNAME_LOG(_x)
#define SRV_NWNAME_PRINT(_x)
#endif /* defined(__MTK_TARGET__) */


/****************************************************************************
 * Define
 ****************************************************************************/

/* Sub module ID:*/
#define SRV_NW_NAME_MOD_CPHS            (1 << 0)
#define SRV_NW_NAME_MOD_SPDI            (1 << 1)

#if defined(__MMI_EONS_SRV__)
#define SRV_NW_NAME_MOD_EONS            (1 << 2)
#endif

/* Max. number of supported entries in the EF_SPDI. */
#define SRV_NW_NAME_MAX_SPDI_NUM        (85)

/* Size of a PLMN BCD entry. */
#define SRV_NW_NAME_PLMN_BCD_SIZE       (3)


/****************************************************************************
 * Typedef
 ****************************************************************************/

/*
 * TODO: shrink the buffer size.
 */
typedef struct
{
    U8              module_init_mask;

    /* EF_SPN */
    MMI_BOOL    is_rplmn_required_in_home;
    MMI_BOOL    is_spn_required_in_roaming;

    /* SPDI */
    U8      spdi_num;
    U8      spdi_plmn[SRV_NW_NAME_MAX_SPDI_NUM][SRV_NW_NAME_PLMN_BCD_SIZE];

    /* Network name */
#if defined(__MMI_EONS_SRV__)
    WCHAR   eons[SRV_NW_NAME_MAX_BUF_SIZE];
#endif
    WCHAR   nitz[SRV_NW_NAME_MAX_BUF_SIZE];
    WCHAR   rom[SRV_NW_NAME_MAX_BUF_SIZE];
    WCHAR   ons[SRV_NW_NAME_MAX_BUF_SIZE];
    WCHAR   short_ons[SRV_NW_NAME_MAX_BUF_SIZE];
    WCHAR   spn[SRV_NW_NAME_MAX_BUF_SIZE];

    mmi_sim_enum    sim;

#ifdef __VSIM__
    MMI_BOOL is_vsim_on;
#endif

#ifdef __OP01_3G__
    srv_nw_name_service_indication_struct srv_ind_cache;
#endif
} srv_nw_name_struct;

/* Context. */
typedef struct
{
    srv_nw_name_struct      nw_name[MMI_SIM_TOTAL];
} srv_nw_name_cntx_struct;


/****************************************************************************
 * Function
 ****************************************************************************/

extern srv_nw_name_struct *srv_nw_name_get_context(mmi_sim_enum sim);


extern void srv_nw_name_set_mod_waiting(mmi_sim_enum sim, U8 module);


extern void srv_nw_name_set_mod_ready(mmi_sim_enum sim, U8 module);


extern void srv_nw_name_update_name(mmi_sim_enum sim);


#endif /* NW_NAME_SRV_MAIN_H */

