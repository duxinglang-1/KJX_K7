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
 *  vapp_sim_ctrl.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SIM control UI of Venus MMI
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"

#include "vfx_datatype.h"
#include "vcp_global_popup.h"
#include "vapp_nmgr_gprot.h"

#include "mmi_rp_vapp_sim_ctrl_def.h"

extern "C"
{
#include "mmi_frm_events_gprot.h"
#include "SimCtrlSrvGprot.h"
#include "BootupSrvGprot.h"
#include "NotificationGprot.h"
#include "GlobalResDef.h"
#include "Wgui_categories_util.h"
}


typedef struct
{
    srv_sim_ctrl_ua_cause_enum cause;
#if (MMI_MAX_SIM_NUM >= 2)
    VfxU16 simx_str;
#endif
    VfxU16 sim_str;
} vapp_sim_ctrl_cause_msg_struct;

// cared event
static const vapp_sim_ctrl_cause_msg_struct g_vapp_sim_ctrl_cause_msg[] =
{
// Hot swap will be handled by Detect.
#ifndef  __SIM_HOT_SWAP_SUPPORT__
    { SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_SIM_CTRL_SIMX_REMOVED,
    #endif
        STR_ID_VAPP_SIM_CTRL_SIM_REMOVED },
#endif

    { SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR,
    #if (MMI_MAX_SIM_NUM >= 2)
        STR_ID_VAPP_SIM_CTRL_SIMX_ACCESS_ERROR,
    #endif
        STR_ID_VAPP_SIM_CTRL_SIM_ACCESS_ERROR },
    /* ------------------------------------------ */
    { SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM,
    #if (MMI_MAX_SIM_NUM >= 2)
        0,
    #endif
        0 }
};
#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
static VfxS32 g_vapp_sim_ctrl_pop_handle = GRP_ID_INVALID;
#endif
#if (MMI_MAX_SIM_NUM >= 2)
static VfxWString vapp_sim_ctrl_compose_sim_str(
    VfxResId str_template_id,
    mmi_sim_enum sim)
{
    //static const VfxS32 MAX_STR_LEN = 128;
    static const VfxU16 SIM_STR_ID[MMI_SIM_TOTAL] =
    {
        STR_GLOBAL_SIM_1,
        STR_GLOBAL_SIM_2,
    #if (MMI_MAX_SIM_NUM >= 3)
        STR_GLOBAL_SIM_3,
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        STR_GLOBAL_SIM_4
    #endif
    };
    
    //VfxS32 simIndex = mmi_frm_sim_to_index(sim);
    //VfxWChar *buffer = (VfxWChar *)OslMalloc((MAX_STR_LEN + 1) * sizeof(VfxWChar));
    
    //mmi_wsprintf(
    //    buffer,
    //    (MAX_STR_LEN + 1) * sizeof(VfxWChar),
    //    str_template_id,
    //    SIM_STR_ID[simIndex]);
    VfxWString str;
    str.format((VfxWChar*)GetString(str_template_id),(VfxWChar*)GetString(SIM_STR_ID[mmi_frm_sim_to_index(sim)]));
    //VfxWString str(str_template_id);
    //str += VFX_WSTR_RES(SIM_STR_ID[mmi_frm_sim_to_index(sim)]);
    //OslMfree(buffer);

    return str;
}
#endif //#if (MMI_MAX_SIM_NUM >= 2)


static VfxWString vapp_sim_ctrl_get_cause_msg(mmi_sim_enum sim, srv_sim_ctrl_ua_cause_enum cause)
{
    for (VfxS32 i = 0; g_vapp_sim_ctrl_cause_msg[i].cause != SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM; ++i)
    {
        if (g_vapp_sim_ctrl_cause_msg[i].cause == cause)
        {
#if (MMI_MAX_SIM_NUM >= 2)
            if (srv_sim_ctrl_get_num_of_inserted() >= 2)
            {
                return vapp_sim_ctrl_compose_sim_str(
                            g_vapp_sim_ctrl_cause_msg[i].simx_str,
                            sim);
            }
#endif
            // For only 1 sim-card inserted or for single proj case.
            return VFX_WSTR_RES(g_vapp_sim_ctrl_cause_msg[i].sim_str);
        }
    }

    return VFX_WSTR_RES(STR_GLOBAL_ERROR);
}

VfxBool vapp_sim_ctrl_is_cared_cause(srv_sim_ctrl_ua_cause_enum cause)
{
    for (VfxS32 i = 0; g_vapp_sim_ctrl_cause_msg[i].cause != SRV_SIM_CTRL_UA_CAUSE_END_OF_ENUM; ++i)
    {
    	if (g_vapp_sim_ctrl_cause_msg[i].cause == cause)
    	{
    		return VFX_TRUE;
    	}
    }

	return VFX_FALSE;
}

extern "C"
mmi_ret vapp_sim_ctrl_on_sim_avai_changed(mmi_event_struct *evt)
{
    if (!srv_bootup_is_completed())
    {
        return MMI_RET_OK;
    }

    srv_sim_ctrl_availability_changed_evt_struct *avai_evt =
        reinterpret_cast<srv_sim_ctrl_availability_changed_evt_struct*>(evt);

    if (vapp_sim_ctrl_is_cared_cause(avai_evt->unavailable_cause))
    {
#ifdef __SIM_RECOVERY_ENHANCEMENT__
		if ((avai_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_INITIALIZING ||
			 avai_evt->unavailable_cause_before == SRV_SIM_CTRL_UA_CAUSE_ACCESS_ERROR) &&
			 avai_evt->unavailable_cause == SRV_SIM_CTRL_UA_CAUSE_RECOVERY)
		{
			/* Popup recovery message only on first-time recovery start */
			return MMI_RET_OK;
		}
#endif /* __SIM_RECOVERY_ENHANCEMENT__ */

        VfxWString msgStr(vapp_sim_ctrl_get_cause_msg(avai_evt->sim, avai_evt->unavailable_cause));
    
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_HIGHEST_SCRN,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_FAILURE,
            msgStr.getBuf());
    }

    return MMI_RET_OK;
}


#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
static void vapp_sim_ctrl_on_pop_callback (VfxId id, void *userData)
{
	g_vapp_sim_ctrl_pop_handle = GRP_ID_INVALID;
}

extern "C"
mmi_ret vapp_sim_ctrl_on_sim_event_detected(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    typedef struct
    {
		U16 cameoff;
		U16 accessError;
    } sim_message_struct;
    
    static const sim_message_struct resId =
    {
#if (MMI_MAX_SIM_NUM >= 2)
		STR_ID_VAPP_SIM_CTRL_SIMX_CAME_OFF,
		STR_ID_VAPP_SIM_CTRL_SIMX_ACCESS_ERROR
#else
		STR_ID_VAPP_SIM_CTRL_SIM_CAME_OFF,
		STR_ID_VAPP_SIM_CTRL_SIM_ACCESS_ERROR
#endif
    };
    
    srv_sim_ctrl_event_detected_evt_struct *detected_evt;
	U16 strId = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    detected_evt = (srv_sim_ctrl_event_detected_evt_struct*)evt;

    switch (detected_evt->type)
    {
    	// As UE: recovery_end don't show any popup
    	//case SRV_SIM_CTRL_EVENT_DET_RECOVERY_END:
        case SRV_SIM_CTRL_EVENT_DET_INSERTED:
			strId = STR_ID_VAPP_SIM_CTRL_SIM_INSERTED;
			break;
			
        case SRV_SIM_CTRL_EVENT_DET_REMOVED:
            strId = STR_ID_VAPP_SIM_CTRL_SIM_REMOVED;
            break;

		case SRV_SIM_CTRL_EVENT_DET_RECOVERY_START:
			strId = resId.cameoff;
			break;
			
		default:
			break;
    }
	
	if (g_vapp_sim_ctrl_pop_handle != GRP_ID_INVALID)
	{
		vapp_nmgr_global_popup_cancel(g_vapp_sim_ctrl_pop_handle);
	}

	if (strId != 0)
	{
		const WCHAR *buffer;
		VfxWString strInfo;

#if (MMI_MAX_SIM_NUM >= 2)
		if (detected_evt->type == SRV_SIM_CTRL_EVENT_DET_RECOVERY_START)
		{
			strInfo = vapp_sim_ctrl_compose_sim_str(strId, detected_evt->sim);
			buffer = (const WCHAR *)strInfo.getBuf();
		}
		else
#endif //MMI_MAX_SIM_NUM
		{
			buffer = (const WCHAR *)get_string(strId);
		}
		
		g_vapp_sim_ctrl_pop_handle = 
			vapp_nmgr_global_popup_show_confirm_one_button_str(
			MMI_SCENARIO_ID_HIGHEST_SCRN,
			VCP_POPUP_TYPE_INFO,
			VFX_WSTR_MEM(buffer),
			VFX_WSTR_RES(STR_GLOBAL_OK),
			VCP_POPUP_BUTTON_TYPE_NORMAL,
			vapp_sim_ctrl_on_pop_callback,
			NULL);
	}

    return MMI_RET_OK;
}

#endif /* __SIM_HOT_SWAP_SUPPORT__ */


#if (MMI_MAX_SIM_NUM >= 2) && defined(__UMTS_RAT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (MMI_MAX_SIM_NUM >= 2) && defined(__UMTS_RAT__) */

