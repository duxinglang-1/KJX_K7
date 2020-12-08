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
 *  CallSetSrvUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Call setting service utilities
 *
 * Author:
 * -------
 * 
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
 *============================================================================== 
 *******************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "CallSetSrvGprot.h"
#include "CallSetSrvIprot.h"
#include "CallSetSrvProt.h"
#include "mmi_rp_srv_callset_def.h"

#include "SsSrvGprot.h"
#include "SimCtrlSrvGprot.h" /* srv_sim_ctrl_xxx */
#include "CphsSrvGprot.h" /* srv_cphs_is_service_available */
#include "ModeSwitchSrvGprot.h" /* srv_mode_switch_get_current_mode, srv_mode_switch_is_network_service_available  */


#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "kal_non_specific_general_types.h"
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "NetSetSrvGprot.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/
static const U16 g_srv_result_string[] = 
{
	STR_GLOBAL_DONE,							/* SRV_CALLSET_RESULT_OK */
	STR_GLOBAL_BUSY_TRY_LATER,					/* SRV_CALLSET_RESULT_BUSY */
	STR_GLOBAL_NOT_AVAILABLE,					/* SRV_CALLSET_RESULT_NOT_AVAILABLE */
	STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL, /* SRV_CALLSET_RESULT_NOT_AVAILABLE_INCALL */
	STR_ID_SRV_CALLSET_RESULT_FULL,				/* SRV_CALLSET_RESULT_FULL*/
	STR_ID_SRV_CALLSET_RESULT_TOO_LONG,			/* SRV_CALLSET_RESULT_TOO_LONG */
	STR_ID_SRV_CALLSET_RESULT_EMPTY,			/* SRV_CALLSET_RESULT_EMPTY */
	STR_GLOBAL_INVALID_NUMBER,					/* SRV_CALLSET_RESULT_INVALID_FORMAT */
	STR_GLOBAL_UNFINISHED,						/* SRV_CALLSET_RESULT_INVALID_INPUT */
	STR_ID_SRV_CALLSET_RESULT_DUPLICATED,		/* SRV_CALLSET_RESULT_DUPLICATE */
	STR_GLOBAL_FILE_NOT_FOUND,					/* SRV_CALLSET_RESULT_NOT_FOUND  */
	STR_GLOBAL_UNFINISHED						/* SRV_CALLSET_RESULT_UNKNOWN_ERROR */
};

/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_callset_get_result_string_id
 * DESCRIPTION
 *  to get the corresponding string id for a specific result cause
 * PARAMETERS
 *  cause : [IN] the result cause
 * RETURNS
 *  U16 : the corresponding string id for the result cause
 *****************************************************************************/ 
U16 srv_callset_get_result_string_id(srv_callset_result_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	return (cause < SRV_CALLSET_RESULT_END_OF_ENUM) ? g_srv_result_string[cause] : STR_GLOBAL_UNFINISHED;
}


/*****************************************************************************
 * FUNCTION
 *  srv_callset_is_available
 * DESCRIPTION
 *  to check if sim-related call setting service is available
 * PARAMETERS
 *  sim : [IN] target sim
 * RETURNS
 *  MMI_TRUE if the specific sim-related call setting service is available
 *****************************************************************************/
MMI_BOOL srv_callset_is_available(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_type_enum usable_side;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_mode_switch_is_network_service_available())
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IS_AVAILABLE, sim, MMI_FALSE, 1);
        return MMI_FALSE;
    }

    usable_side = srv_mode_switch_get_current_mode();

	/* check sim mode setting */
	if (!(usable_side & sim))
	{
		MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IS_AVAILABLE, sim, MMI_FALSE, 3);
		return MMI_FALSE;
	}

	/* check sim status */
	if (!srv_sim_ctrl_is_available(sim))
	{
		MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IS_AVAILABLE, sim, MMI_FALSE, 4);
		return MMI_FALSE;
	}

    if (
    #ifdef __MMI_CALLSET_CALLER_ID__
        srv_callset_is_caller_id_supported(sim) || 
    #endif /* __MMI_CALLSET_CALLER_ID__ */
        srv_ss_check_capability(sim, SRV_SS_ACT_CALL_WAIT, 0, SRV_SS_ALL_CALL) ||
        srv_ss_check_capability(sim, SRV_SS_ACT_CALL_FORWARD, SRV_SS_CALL_FORWARD_CFALL, SRV_SS_ALL_CALL) ||
        srv_ss_check_capability(sim, SRV_SS_ACT_CALL_BAR, SRV_SS_CALL_BAR_BAC, SRV_SS_ALL_CALL) ||
        srv_callset_is_line_switch_supported(sim) ||
    #ifdef __MMI_CALLSET_CUG__
        srv_callset_is_cug_supported(sim) ||
    #endif /* __MMI_CALLSET_CUG__ */
        MMI_FALSE
        )
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IS_AVAILABLE, sim, MMI_TRUE, 1);
        return MMI_TRUE;
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_CALLSET_IS_AVAILABLE, sim, MMI_FALSE, 6);
        return MMI_FALSE;
    }
}


#ifdef __MMI_CALLSET_CALLER_ID__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_support_cid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void*
 *****************************************************************************/
MMI_BOOL srv_callset_is_caller_id_supported(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (MMI_BOOL)(srv_cphs_is_service_available(SRV_CPHS_GROUP_NUMBER_IDENTIFI, SRV_CPHS_SERVICE_CLI_BLOCK, sim) ||
                srv_cphs_is_service_available(SRV_CPHS_GROUP_NUMBER_IDENTIFI, SRV_CPHS_SERVICE_CLI_SEND, sim));
}
#endif /* __MMI_CALLSET_CALLER_ID__ */


#ifdef __MMI_CALLSET_CUG__
/*****************************************************************************
 * FUNCTION
 *  srv_callset_is_cug_supported
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void*
 *****************************************************************************/
MMI_BOOL srv_callset_is_cug_supported(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_cphs_is_service_available(SRV_CPHS_GROUP_OTHER_SUPP_SERVICES, SRV_CPHS_SERVICE_CUG, sim);
}
#endif /* __MMI_CALLSET_CUG__ */


/*****************************************************************************
 * FUNCTION
 *  srv_callset_is_line_switch_supported
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void*
 *****************************************************************************/
MMI_BOOL srv_callset_is_line_switch_supported(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_cphs_is_service_available(SRV_CPHS_GROUP_CPHS_TELESERVICES, SRV_CPHS_SERVICE_ALS, sim);
}


