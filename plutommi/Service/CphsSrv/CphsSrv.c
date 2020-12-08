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
 *  CphsSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements service functions for CPHS feature.
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifndef CPHSSRV_C
#define CPHSSRV_C

#include "ProtocolEvents.h"
#include "CphsSrvGprot.h"
#include "PhbSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "StatusIconRes.h"
#include "mmi_frm_utility_gprot.h"
#include "sim_public_api.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "string.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "mmi_msg_struct.h"
#include "sim_common_enums.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "ps_public_struct.h"

#include "mmi_rp_srv_cphs_def.h"

#if (MMI_MAX_SIM_NUM >=2)
#include "ps_public_utility.h"
#endif


/* 
 * Typedef
 */
typedef struct
{
    MMI_BOOL valid_csp[MMI_SIM_TOTAL];
    U8 csp_info[MMI_SIM_TOTAL][SRV_CPHS_GROUP_TOTAL];
} srv_cphs_cntx_struct;


/* 
 * Local Variable
 */
static srv_cphs_cntx_struct g_srv_cphs_cntx;

/* 
 * Local Function
 */


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_cphs_info_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim         [IN]        
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cphs_cphs_info_hdlr(mmi_sim_enum sim, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cphs_mmi_info_ind_struct *local_ptr;
    MMI_BOOL *valid_csp;
    U32 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_index = mmi_frm_sim_to_index(sim);
    valid_csp = &g_srv_cphs_cntx.valid_csp[sim_index];

    local_ptr = (mmi_cphs_mmi_info_ind_struct*) info;

#if (MMI_MAX_SIM_NUM >= 2)
    if (local_ptr->is_valid_csp && sim_service_table_query(SERVICE_CSP, (kal_uint8)l4c_gemini_get_switched_sim_id((sim_interface_enum)sim_index)) == SERVICE_SUPPORT)
#else
    if (local_ptr->is_valid_csp && sim_service_table_query(SERVICE_CSP) == SERVICE_SUPPORT)
#endif
    {
        *valid_csp = MMI_TRUE;
        srv_cphs_parse_csp_info(local_ptr->csp, sim);
    }
    else
    {
        *valid_csp = MMI_FALSE;
    }

    srv_cphs_parse_msisdn_info(local_ptr->no_msisdn, local_ptr->msisdn, sim);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_cphs_info_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 *  mod_src     [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
static U8 srv_cphs_cphs_info_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim = mmi_frm_l4c_mod_to_sim((module_type)mod_src);
    srv_cphs_cphs_info_hdlr(sim, info);
    return (U8)MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cphs_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (sim_index = 0; sim_index < MMI_SIM_TOTAL; sim_index++)
    {
        memset(g_srv_cphs_cntx.csp_info[sim_index], 0xFF, SRV_CPHS_GROUP_TOTAL);
    }
    mmi_frm_set_protocol_event_handler(PRT_MSG_ID_MMI_CPHS_MMI_INFO_IND, (PsIntFuncPtr)srv_cphs_cphs_info_ind, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_reset_als_status_icon
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cphs_reset_als_status_icon(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifndef __COSMOS_MMI_PACKAGE__

    srv_mode_switch_type_enum usable_side;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
#if (MMI_MAX_SIM_NUM < 2)
    wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_SIGNAL_STRENGTH);
#else /* (MMI_MAX_SIM_NUM < 2) */
    usable_side = srv_mode_switch_get_current_mode();
    usable_side &= sim;
    if (usable_side & MMI_SIM1)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIGNAL_STRENGTH, IMG_SI_MASTER_SIGNAL_STRENGTH);
    }
    if (usable_side & MMI_SIM2)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SLAVE_SIGNAL_STRENGTH, IMG_SI_SLAVE_SIGNAL_STRENGTH);
    }
#if (MMI_MAX_SIM_NUM >= 3)
    if (usable_side & MMI_SIM3)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM3_SIGNAL_STRENGTH, IMG_SI_SIM3_SIGNAL_STRENGTH);
    }
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#if (MMI_MAX_SIM_NUM >= 4)
    if (usable_side & MMI_SIM4)
    {
        wgui_status_icon_bar_change_icon_image(STATUS_ICON_SIM4_SIGNAL_STRENGTH, IMG_SI_SIM4_SIGNAL_STRENGTH);
    }
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* MMI_MAX_SIM_NUM < 2 */
#else /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */ 
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_ALTERNATE_LINE_L1);
    wgui_status_icon_bar_reset_icon_display(STATUS_ICON_ALTERNATE_LINE_L2);
#endif /* __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__ */
#endif /* __COSMOS_MMI_PACKAGE__ */
}


static void srv_cphs_send_cps_refresh_event(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cphs_csp_refresh_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_CPHS_CSP_REFRESH);
    evt.sim_id = sim_id;
    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_parse_csp_info
 * DESCRIPTION
 *  This function is used to parse CSP information when SIM refresh happens (File Change: EFcsp).
 * PARAMETERS
 *  csp_data:       [IN]        CSP data (22 bytes)
 *  sim:            [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cphs_parse_csp_info(U8 *csp_data, mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *csp_info;
    U32 i, sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_index = mmi_frm_sim_to_index(sim);
    csp_info = g_srv_cphs_cntx.csp_info[sim_index];

    for (i = 0; i < 22; i++)
    {
        switch (csp_data[i])
        {
            case 0x01:
                csp_info[SRV_CPHS_GROUP_CALL_OFFERING] = csp_data[++i];
                break;

            case 0x02:
                csp_info[SRV_CPHS_GROUP_CALL_RESTRICTION] = csp_data[++i];
                break;

            case 0x03:
                csp_info[SRV_CPHS_GROUP_OTHER_SUPP_SERVICES] = csp_data[++i];
                break;

            case 0x04:
                csp_info[SRV_CPHS_GROUP_CALL_COMPLETION] = csp_data[++i];
                break;

            case 0x05:
                csp_info[SRV_CPHS_GROUP_TELESERVICES] = csp_data[++i];
            #ifdef __MMI_CSP_SMS_COMMON_SETTING_ALWAYS_ON__
                csp_info[SRV_CPHS_GROUP_TELESERVICES] |= 0x18;
            #endif
                break;

            case 0x06:
                csp_info[SRV_CPHS_GROUP_CPHS_TELESERVICES] = csp_data[++i];
                break;

            case 0x07:
                csp_info[SRV_CPHS_GROUP_CPHS_FEATURES] = csp_data[++i];
                break;

            case 0x08:
                csp_info[SRV_CPHS_GROUP_NUMBER_IDENTIFI] = csp_data[++i];
                break;

            case 0x09:
                csp_info[SRV_CPHS_GROUP_PHASE_2_PLUS_SERVICES] = csp_data[++i];
                break;

            case 0xC0:
                csp_info[SRV_CPHS_GROUP_VALUE_ADDED_SERVICES] = csp_data[++i];
            #ifdef __MMI_CSP_LANG_SEL_MENU_ALWAYS_ON__
                csp_info[SRV_CPHS_GROUP_VALUE_ADDED_SERVICES] |= 0x01;
            #endif
                break;

            case 0xD5:
                csp_info[SRV_CPHS_GROUP_INFORMATION_NUMBERS] = csp_data[++i];
                break;

            default:
                break;
        }
    }

    /* When ALS=0, the indicator icon on status bar should not display line1 or line2 */
    if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_CPHS_TELESERVICES, SRV_CPHS_SERVICE_ALS, sim))
    {
        srv_cphs_reset_als_status_icon(sim);
    }

    srv_cphs_send_cps_refresh_event(sim);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_is_valid_csp
 * DESCRIPTION
 *  This function is used to check if there is a valid CSP present on the SIM.
 * PARAMETERS
 *  sim:            [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  MMI_TRUE if has, otherwise MMI_FALSE
 *****************************************************************************/
MMI_BOOL srv_cphs_is_valid_csp(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_index = mmi_frm_sim_to_index(sim);
    return g_srv_cphs_cntx.valid_csp[sim_index];
}


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_is_service_available
 * DESCRIPTION
 *  This function is used to check if the menu item(s) relevant to that service can be presented
 *  to the user.
 *  If it is not a valid CSP, we will treat all the services as available!!!
 *  If the menu item(s) relevant to that service do(es) not want to be displayed in this case,
 *  then you MUST use the check API "srv_cphs_is_valid_csp" for additional check.
 * PARAMETERS
 *  group:          [IN]        CPHS Group
 *  service:        [IN]        CPHS Service
 *  sim:            [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  MMI_TRUE if available, otherwise MMI_FALSE
 *****************************************************************************/
MMI_BOOL srv_cphs_is_service_available(srv_cphs_group_enum group, srv_cphs_service_enum service, mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *csp_info;
    U32 sim_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_index = mmi_frm_sim_to_index(sim);
    csp_info = g_srv_cphs_cntx.csp_info[sim_index];

    MMI_ASSERT(group < SRV_CPHS_GROUP_TOTAL);
    if (IsBitSet(csp_info[group], service))
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_parse_msisdn_info
 * DESCRIPTION
 *  This function is used to parse MSISDN information when SIM refresh happens (File Change: EFmsisdn).
 * PARAMETERS
 *  no_msisdn:      [IN]        No. of MSISDN
 *  msisdn:         [IN]        MSISDN data
 *  sim:            [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cphs_parse_msisdn_info(U8 no_msisdn, l4csmu_addr_struct *msisdn, mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_owner_number_parse_msisdn_info((U8) mmi_frm_sim_to_index(sim), no_msisdn, msisdn);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_get_msisdn_name
 * DESCRIPTION
 *  This function is used to get MSISDN name by type.
 * PARAMETERS
 *  msisdn_type:    [IN]        MSISDN Type
 *  sim:            [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  MSISDN name
 *****************************************************************************/
const WCHAR* srv_cphs_get_msisdn_name(srv_cphs_msisdn_type_enum msisdn_type, mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_owner_number_get_name((U8) mmi_frm_sim_to_index(sim), (U16) msisdn_type);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cphs_get_msisdn_number
 * DESCRIPTION
 *  This function is used to get MSISDN number by type.
 * PARAMETERS
 *  msisdn_type:    [IN]        MSISDN Type
 *  sim:            [IN]        MMI_SIM1/MMI_SIM2
 * RETURNS
 *  MSISDN number
 *****************************************************************************/
const WCHAR* srv_cphs_get_msisdn_number(srv_cphs_msisdn_type_enum msisdn_type, mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_owner_number_get_number((U8) mmi_frm_sim_to_index(sim), (U16) msisdn_type);
}

#endif /* CPHSSRV_C */

