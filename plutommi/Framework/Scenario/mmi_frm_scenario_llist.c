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
 * mmi_frm_scenario_list.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#include "mmi_frm_scenario_list.h"
#include "Custom_events_notify.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMI_fw_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_fw_trc.h"
#include "mmi_frm_history.h"
#include "kal_public_api.h"
#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "BootupSrvGprot.h"
#include "fix_size_mem.h"
#include "NotificationGprot.h"
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define DECODE_SCEN_ATTR_PRIO(_prio, _scen_info)    \
    do {    \
        ((_scen_info)->scrn_priority)   = (mmi_scen_attr_prio_enum)((_prio) & MMI_SCEN_SCRN_PRIO_MASK);    \
        ((_scen_info)->snd_priority)    = (mmi_scen_attr_prio_enum)((_prio) & MMI_SCEN_SND_PRIO_MASK);     \
        ((_scen_info)->vib_priority)    = (mmi_scen_attr_prio_enum)((_prio) & MMI_SCEN_VIB_PRIO_MASK);     \
        ((_scen_info)->bl_priority)     = (mmi_scen_attr_prio_enum)((_prio) & MMI_SCEN_BL_PRIO_MASK);      \
    } while(0)

#define ENCODE_SCEN_ATTR_PRIO(_prio, _scen_info)    \
        do {    \
            (_prio) = ((_scen_info)->scrn_priority) | ((_scen_info)->snd_priority << 4) |   \
            ((_scen_info)->vib_priority << 8) | ((_scen_info)->bl_priority << 12)           \
        } while(0)

/***************************************************************************** 
 * Local variable
 *****************************************************************************/
static mmi_scenario_list scenario_list_header = NULL;
static S32 scenario_list_length = 0;
static MMI_BOOL is_before_1st_start_scenario = MMI_TRUE;
/***************************************************************************** 
 * Internal Interface prototype
 *****************************************************************************/

/***************************************************************************** 
 * Internal Interface
 *****************************************************************************/
static void load_default_attr_prio(mmi_app_scenario_attribute_struct *scen_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scen_p->notify_priority = mmi_get_scenario_default_prio(scen_p->scenario_id);
}


static mmi_app_scenario_attribute_struct *get_started_scenario_info(mmi_scenario_id scenario_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_scenario_position position;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    position = scenario_list_find(scenario_id);

    return (position == NULL) ? NULL : &(position->scenario_info);
}


/***************************************************************************** 
 * External Interface
 *****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_is_scenario_started
 * DESCRIPTION
 *  Check if designated scenario is started.
 * PARAMETERS
 *  scenario_id :      [IN]  scenario id.
 * RETURNS
 *  Return MMI_FALSE if the scenario is started, otherwise return MMI_TRUE.
 *****************************************************************************/
MMI_BOOL mmi_frm_is_scenario_started(mmi_scenario_id scenario_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (NULL != scenario_list_find(scenario_id)) ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_has_no_scenario_been_started
 * DESCRIPTION
 *  Check if mmi_frm_start_scenario invoked at least once
 * PARAMETERS
 *  void
 * RETURNS
 *  Return MMI_TRUE if before first mmi_frm_start_scenario is invoked
 *****************************************************************************/
MMI_BOOL mmi_frm_has_no_scenario_been_started()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return is_before_1st_start_scenario;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_start_scenario
 * DESCRIPTION
 *  This api should be invoked when
 *  1. application launch time, before enter new screen;
 *  2. background application invoke a notification;
 * PARAMETERS
 *  scenario_id :      [IN]  scenario id.
 * RETURNS
 *  Return MMI_FALSE if the scenario is already started, otherwise return MMI_TRUE.
 *****************************************************************************/
MMI_BOOL mmi_frm_start_scenario(mmi_scenario_id scenario_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_app_scenario_attribute_struct scen;
	  mmi_scenario_position position;
	  mmi_scenario_end_evt_struct scen_end_evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL != (position = scenario_list_find(scenario_id)))
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_START_SCENARIO_FAIL, scenario_id);
        position->scenario_info.ref_cnt++;
        return MMI_FALSE;
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_START_SCENARIO_SUCCESS, scenario_id);
        /* Load default attribute priority and add new scenario into list */
        scen.scenario_id = scenario_id;
        scen.ref_cnt = 1;
        load_default_attr_prio(&scen);
        if (!scenario_list_get_header())
        {/* First time to insert scenario */
            scenario_list_create();
        }
        scenario_list_insert(scen, scenario_list_get_header());
        //mmi_frm_nmgr_invoke_deder_event();
        MMI_FRM_INIT_EVENT(&scen_end_evt, EVT_ID_SCENARIO_END);
        scen_end_evt.scenario_id = scenario_id;
        MMI_FRM_CB_EMIT_EVENT(&scen_end_evt);   
        is_before_1st_start_scenario = MMI_FALSE;
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_end_scenario
 * DESCRIPTION
 *  This api should be invoked when
 *  1. application exit, screen been destoried;
 *  2. background application end a notification, destory screen or end work flow;
 * PARAMETERS
 *  scenario_id :      [IN]  scenario id.
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_frm_end_scenario(mmi_scenario_id scenario_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_scenario_position position;
	mmi_scenario_end_evt_struct scen_end_evt;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == (position = scenario_list_find(scenario_id)))
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_END_SCENARIO_FAIL, scenario_id);
        return MMI_FALSE;
    }
    else
    {
        MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_END_SCENARIO_SUCCESS, scenario_id);
        position->scenario_info.ref_cnt--;
        MMI_ASSERT(position->scenario_info.ref_cnt >= 0);
        if (0 == position->scenario_info.ref_cnt)
        {
            scenario_list_delete(scenario_id);
            MMI_ASSERT(!scenario_list_find(scenario_id));
            if (scenario_list_is_empty())
            {
                scenario_list_destroy();
            }
            // DECOUPLE:: should send end scenario event, let nmgr register callback to process defer.
            /* Send post event to process deferred notification */
            MMI_FRM_INIT_EVENT(&scen_end_evt, EVT_ID_SCENARIO_END);
            scen_end_evt.scenario_id = scenario_id;
            MMI_FRM_CB_EMIT_EVENT(&scen_end_evt);
	        //mmi_frm_nmgr_invoke_deder_event();
            return MMI_TRUE;
        }
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_set_scenario_info
 * DESCRIPTION
 *  This api should be invoked if application want to change scenario related priority
 *  before the scenario been processed.
 * PARAMETERS
 *  scenario_info
 * RETURNS
 *  void
 *****************************************************************************/
/* Help re-config priority */
void mmi_frm_set_scenario_info(mmi_app_scenario_struct *scenario_info)
{

}

MMI_BOOL mmi_frm_is_scrn_priority_enough(mmi_scenario_id scenario_id)
{
	mmi_scenario_id active_scen_id;
    mmi_app_scenario_struct noti_scen = {MMI_SCENARIO_ID_GENERAL, MMI_SCEN_PRIO_NONE, MMI_SCEN_PRIO_NONE, MMI_SCEN_PRIO_NONE, MMI_SCEN_PRIO_NONE};    
    mmi_app_scenario_struct active_scen = {MMI_SCENARIO_ID_GENERAL, MMI_SCEN_PRIO_NONE, MMI_SCEN_PRIO_NONE, MMI_SCEN_PRIO_NONE, MMI_SCEN_PRIO_NONE};
    noti_scen.scenario_id = scenario_id;
    active_scen_id = mmi_frm_get_active_scenario_id();
	active_scen.scenario_id = active_scen_id;
    mmi_frm_get_scenario_info(&noti_scen);
    mmi_frm_get_scenario_info(&active_scen);
    if (noti_scen.scrn_priority >= active_scen.scrn_priority)
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
 *  mmi_frm_get_scenario_info
 * DESCRIPTION
 *  Get scenario information static-configured or dynamic-configured by application.
 * PARAMETERS
 *  scenario_info :      [IN]  scenario information structure.
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_get_scenario_info(mmi_app_scenario_struct *scenario_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_app_scenario_attribute_struct scen_info, *scen_info_ptr;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    scen_info_ptr = get_started_scenario_info(scenario_info->scenario_id);
    if (NULL != scen_info_ptr)
    {
        scen_info = *scen_info_ptr;
        MMI_ASSERT(scen_info.scenario_id == scenario_info->scenario_id);
    }
    else
    {/* Notification scenario maybe be started in nmgr, e.g. common popup */
        scen_info.scenario_id = scenario_info->scenario_id;
        load_default_attr_prio(&scen_info);
    }

    DECODE_SCEN_ATTR_PRIO(scen_info.notify_priority, scenario_info);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_get_active_scenario_id
 * DESCRIPTION
 *  Get the current active scenario id.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_scenario_id mmi_frm_get_active_scenario_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_scenario_position position;
	mmi_scenario_id active_scen_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    position = scenario_list_get_latest();
    active_scen_id = (position == NULL) ? MMI_SCENARIO_ID_INVALID : position->scenario_info.scenario_id;
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_GET_ACTIVE_SCENARIO_ID, active_scen_id);

    return active_scen_id;
}


mmi_scenario_id mmi_frm_get_exit_scenario_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_scenario_position position, latest;
	mmi_scenario_id exit_scen_id;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    latest = scenario_list_get_latest();
	position = scenario_list_find_next(latest->scenario_info.scenario_id);
    exit_scen_id = (position == NULL) ? MMI_SCENARIO_ID_INVALID : position->scenario_info.scenario_id;
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_GET_EXIT_SCENARIO_ID, exit_scen_id);

    return exit_scen_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_init_scenario
 * DESCRIPTION
 *  Initialize scenario list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_init_scenario(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_INIT_SCENARIO);
    scenario_list_create();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_deinit_scenario
 * DESCRIPTION
 *  Destroy scenario list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_deinit_scenario(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_FW_TRC_G1_FRM, TRC_MMI_FRM_DEINIT_SCENARIO);
    scenario_list_destroy();
}


/***************************************************************************** 
 * Scenario list operation interface
 *****************************************************************************/
void scenario_list_create(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(!scenario_list_header);
    scenario_list_header = (mmi_scenario_list)mmi_frm_malloc(sizeof(mmi_scenario_list_node));
    memset(scenario_list_header, 0, sizeof(mmi_scenario_list_node));
}


void scenario_list_destroy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_position position, tmp_p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    position = scenario_list_header;
    /* Won't count header as list length */
    if (scenario_list_header)
    {
    	scenario_list_length++;
    }
    while (position)
    {
        tmp_p = position->next;
        mmi_frm_free(position);
        position = tmp_p;
        scenario_list_length--;
    }
	MMI_ASSERT(scenario_list_length == 0);
    scenario_list_header = NULL;
}


MMI_BOOL scenario_list_is_empty(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (scenario_list_length == 0) ? MMI_TRUE : MMI_FALSE;
}


MMI_BOOL scenario_list_is_last(mmi_scenario_position position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (position->next == NULL) ? MMI_TRUE : MMI_FALSE;
}


U32 scenario_list_get_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return scenario_list_length;
}


mmi_scenario_position scenario_list_find(mmi_scenario_id scen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_position position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!scenario_list_get_header())
        return NULL;

    position = scenario_list_header->next;
    while (position && position->scenario_info.scenario_id != scen_id)
    {
        position = position->next;
    }
    return position;
}


mmi_scenario_position scenario_list_find_previous(mmi_scenario_id scen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_position position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!scenario_list_get_header())
        return NULL;

    position = scenario_list_header;
    while (position->next && position->next->scenario_info.scenario_id != scen_id)
    {
        position = position->next;
    }
    return position;
}


mmi_scenario_position scenario_list_find_next(mmi_scenario_id scen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_position position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!scenario_list_get_header())
        return NULL;
	
    position = scenario_list_header->next;
    while (position && position->scenario_info.scenario_id != scen_id && !position->next)
    {
        position = position->next;
    }
    return position->next;
}


void scenario_list_delete(mmi_scenario_id scen_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_position position, tmp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    position = scenario_list_find_previous(scen_id);

    if (!scenario_list_is_last(position))
    {
        tmp_p = position->next;
        position->next = tmp_p->next;
        mmi_frm_free(tmp_p);
        scenario_list_length--;
        MMI_ASSERT(scenario_list_length >= 0);
    }
    else
    {/* Can't find designated scenario id */
    }
}


void scenario_list_insert_after(mmi_scenario_list_elem_type scen, mmi_scenario_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_position pos;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    pos = scenario_list_find_previous(id);
    scenario_list_insert(scen, pos);
}


void scenario_list_insert(mmi_scenario_list_elem_type scen, mmi_scenario_position position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_position tmp_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(position);
    tmp_p = (mmi_scenario_position)mmi_frm_malloc(sizeof(mmi_scenario_list_node));
    tmp_p->scenario_info = scen;
    tmp_p->next = position->next;
    position->next = tmp_p;
    scenario_list_length++;
}


mmi_scenario_position scenario_list_get_header(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (mmi_scenario_position)scenario_list_header;
}


mmi_scenario_position scenario_list_get_latest(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_scenario_position position;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (scenario_list_is_empty())
    {
        return NULL;
    }
    position = scenario_list_get_header();
    
    return (position == NULL) ? NULL : position->next;
}


mmi_scenario_position scenario_list_first(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (scenario_list_header == NULL) ? NULL : scenario_list_header->next;
}


mmi_scenario_position scenario_list_advance(mmi_scenario_position position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return scenario_list_find_previous(position->scenario_info.scenario_id);
}


mmi_scenario_list_elem_type scenario_list_retrieve(mmi_scenario_position position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	return position->scenario_info;
}


#ifdef MMI_NOTI_MGR_UT
/***************************************************************************** 
 * Scenario list test cases
 *****************************************************************************/
MMI_BOOL mmi_scenario_list_ut(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 idx;
    mmi_scenario_position position;
    mmi_scenario_attribute_struct scen[] = {
        {1, MMI_SCEN_PRIO_DEFAULT}, {2, MMI_SCEN_PRIO_DEFAULT}, {3, MMI_SCEN_PRIO_DEFAULT}, 
        {4, MMI_SCEN_PRIO_DEFAULT}, {5, MMI_SCEN_PRIO_DEFAULT}, {6, MMI_SCEN_PRIO_DEFAULT}, 
        {7, MMI_SCEN_PRIO_DEFAULT}, {8, MMI_SCEN_PRIO_DEFAULT}, {9, MMI_SCEN_PRIO_DEFAULT}, 
        {10, MMI_SCEN_PRIO_DEFAULT}};
    mmi_scenario_list_elem_type scen_elem_tmp;
    const U32 scen_tbl_size = sizeof(scen) / sizeof(scen[0]);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_deinit_scenario();
    MMI_ASSERT(scenario_list_is_empty());
	MMI_ASSERT(!scenario_list_get_header());
    scenario_list_create();
    MMI_ASSERT(scenario_list_is_empty());
    MMI_ASSERT(scenario_list_get_header());
    MMI_ASSERT(scenario_list_get_length() == 0);

    for (idx = 0; idx < scen_tbl_size; idx++)
    {
        scen_elem_tmp.notify_priority = scen[idx].notify_priority;
        scen_elem_tmp.scenario_id = scen[idx].scenario_id;
        scen_elem_tmp.ref_cnt = 1;
        scenario_list_insert(scen_elem_tmp, scenario_list_get_header());
        position = scenario_list_find(scen[idx].scenario_id);
        MMI_ASSERT(position->scenario_info.scenario_id == scen[idx].scenario_id);
        if (idx > 0)
        {
            position = scenario_list_find_previous(scen[idx].scenario_id);
            MMI_ASSERT(position == scenario_list_get_header());
			position = scenario_list_find_next(scen[idx].scenario_id);
            MMI_ASSERT(position->scenario_info.scenario_id == scen[idx - 1].scenario_id);
        }
    }
	MMI_ASSERT(!scenario_list_is_empty() && scenario_list_get_length() == scen_tbl_size);

    for (idx = 0; idx < scen_tbl_size / 2; idx++)
    {
        scenario_list_delete(scen[idx].scenario_id);
        MMI_ASSERT(!scenario_list_find(scen[idx].scenario_id));
    }
    MMI_ASSERT(!scenario_list_is_empty() && scenario_list_get_length() == scen_tbl_size / 2);
    
    scenario_list_destroy();
    MMI_ASSERT(scenario_list_get_length() == 0);
    MMI_ASSERT(scenario_list_is_empty());
    MMI_ASSERT(!scenario_list_get_header());

	return MMI_TRUE;
}
#endif /* MMI_NOTI_MGR_UT */

