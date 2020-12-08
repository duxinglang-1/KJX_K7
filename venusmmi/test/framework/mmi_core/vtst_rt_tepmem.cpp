/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vtst_rt_tempmem.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Description
 *      New memory test bed
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "vfx_uc_include.h"
//#include "vadp_mmi_frm.h"
#include "vtst_rt_main.h"

#ifdef __cplusplus
extern "C"
{
#endif

//#include "WguiCategoryGprot.h"



#ifdef __cplusplus
}
#endif

#include "mmi_frm_mem_prot.h"

#ifdef __AFX_RT_TEST__

extern "C"
{
 	#include "vfx_config.h"
    #include "GlobalResDef.h"
    #include "kal_general_types.h"
    #include "stack_config.h"
    #include "MMIDataType.h"
    #include "mmi_frm_mem_gprot.h"
    #include "mmi_res_range_def.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "CustDataRes.h"
    #include "Unicodexdcl.h"
    #include "mmi_frm_events_gprot.h"
    #include "wgui_categories_text_viewer.h"
    #include "GlobalConstants.h"
    #include "wgui_categories_util.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "string.h"
    #include "mmi_frm_input_gprot.h"
    #include "TimerEvents.h"
    #include "mmi_frm_timer_gprot.h"
    #include "app_mem.h"
    #include "vfx_object.h"
    #include "vfx_class_info.h"
    #include "vfx_datatype.h"
    #include "vfx_cpp_base.h"
    #include "vfx_sys_memory.h"
    #include "vfx_app_launcher.h"
    //#include "kal_active_module.h"
}

enum {
    EVT_ID_APP_FINISHED = EVT_ID_SCENARIO_MAX + 1,
};

extern "C"
void applib_mem_ap(void);



#define NEW_MEM_UT_POOL_SIZE   (mmi_frm_asm_get_pool_size_r())
#define NEW_MEM_UT_APP1_SIZE   (NEW_MEM_UT_POOL_SIZE / 5)
#define NEW_MEM_UT_APP2_SIZE   ((NEW_MEM_UT_POOL_SIZE / 5) * 2)
#define NEW_MEM_UT_APP3_SIZE   ((NEW_MEM_UT_POOL_SIZE / 5) * 3)
#define NEW_MEM_UT_APP4_SIZE   ((NEW_MEM_UT_POOL_SIZE / 5) * 4)
#define NEW_MEM_UT_APP5_SIZE   (NEW_MEM_UT_POOL_SIZE)

static mmi_ret app1_launch_proc(mmi_event_struct *evt);
static mmi_ret app2_launch_proc(mmi_event_struct *evt);
static mmi_ret app3_launch_proc(mmi_event_struct *evt);
static mmi_ret app4_launch_proc(mmi_event_struct *evt);
static void app_scrn_enter5(void);
static void new_memory_test3_timer(void);

static mmi_id g_gid[5];
static mmi_id srv_id;
static mmi_id app_id;
static void* app4_mem = NULL;
static void* app5_mem = NULL;


static mmi_id app1_launch(mmi_id caller_id, MMI_BOOL if_hide_in_oom)
{
	mmi_frm_asm_property_struct p;
	mmi_frm_asm_property_struct get;
    g_gid[0] = mmi_frm_group_create(caller_id, TEMP_MEM_APP1, app1_launch_proc, NULL);
	mmi_frm_group_enter(g_gid[0], MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_frm_asm_property_init(&p);
	p.f_skip_size_checking = 1;
	if (if_hide_in_oom)
	{
		p.f_hide_in_oom = 1;
	}
	mmi_frm_asm_set_property(g_gid[0], &p);
	mmi_frm_asm_prepare(g_gid[0], NEW_MEM_UT_APP1_SIZE, 
                        app1_launch_proc, 
                        NULL, 
                        MMI_FRM_ASM_F_NONE);
	return g_gid[0];
}


static void app_scrn_enter1()
{
	U16 buff[15];
	mmi_asc_to_wcs(buff, "group1 screen");
	if (!mmi_frm_scrn_enter(g_gid[0], GLOBAL_SCR_DUMMY, NULL, app_scrn_enter1, MMI_FRM_FULL_SCRN))
	{
		return;
	}
	ShowCategory7Screen(0, 0, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 
                        (U8*)buff, NULL);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


static void app_scrn_enter2()
{
	U16 buff[15];
	mmi_asc_to_wcs(buff, "group2 screen");
	if (!mmi_frm_scrn_enter(g_gid[1], GLOBAL_SCR_DUMMY, NULL, app_scrn_enter2, MMI_FRM_FULL_SCRN))
	{
		return;
	}
	ShowCategory7Screen(0, 0, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 
                        (U8*)buff, NULL);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


static void app_scrn_enter3()
{
	U16 buff[15];
	mmi_asc_to_wcs(buff, "group3 screen");
	if (!mmi_frm_scrn_enter(g_gid[2], GLOBAL_SCR_DUMMY, NULL, app_scrn_enter3, MMI_FRM_FULL_SCRN))
	{
		return;
	}
	ShowCategory7Screen(0, 0, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 
                        (U8*)buff, NULL);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}

static mmi_ret app1_launch_proc(mmi_event_struct *evt)
{
	mmi_scenario_evt_struct *sevt = (mmi_scenario_evt_struct *)evt;
	switch(evt->evt_id)
	{
		void * mem; 
		case EVT_ID_ASM_PREPARED:
			mem = mmi_frm_asm_alloc_r(((mmi_frm_asm_prepare_evt_struct*)evt)->app_id, NEW_MEM_UT_APP1_SIZE);
			MMI_ASSERT(mem);		
			mmi_frm_group_set_user_data(((mmi_frm_asm_prepare_evt_struct*)evt)->app_id, mem);
			app_scrn_enter1();
			break;
		case EVT_ID_ASM_FORCE_FREE:
			mem = mmi_frm_group_get_user_data(((mmi_frm_asm_evt_struct*)evt)->app_id);
			if (mem)
			{
				mmi_frm_asm_free_r(((mmi_frm_asm_evt_struct*)evt)->app_id, mem);
				mmi_frm_group_set_user_data(((mmi_frm_asm_prepare_evt_struct*)evt)->app_id, NULL);
			}
			mmi_frm_group_close(((mmi_frm_asm_evt_struct*)evt)->app_id);
			return MMI_FRM_ASM_FREED;
			break;
		case EVT_ID_GROUP_DEINIT:
			mem = mmi_frm_group_get_user_data(sevt->targ_group);
			if (mem)
				mmi_frm_asm_free_r(sevt->targ_group, mem);
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}


static mmi_id app2_launch(mmi_id caller_id,MMI_BOOL if_hide_oom)
{
	mmi_frm_asm_property_struct p;
    g_gid[1] = mmi_frm_group_create(caller_id, TEMP_MEM_APP2, app2_launch_proc, NULL);
	mmi_frm_group_enter(g_gid[1], MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_frm_asm_property_init(&p);
	p.f_skip_size_checking = 1;
	if (if_hide_oom)
	{
		p.f_hide_in_oom = 1;
	}
    mmi_frm_asm_set_property(g_gid[1], &p);
	mmi_frm_asm_prepare(g_gid[1], NEW_MEM_UT_APP2_SIZE, 
                        app2_launch_proc, 
                        NULL, 
                        MMI_FRM_ASM_F_NONE);
   return g_gid[1];


}

static mmi_ret app2_launch_proc(mmi_event_struct *evt)
{
	void * mem; 
	switch(evt->evt_id)
	{
		case EVT_ID_ASM_PREPARED:
			mem = mmi_frm_asm_alloc_r(((mmi_frm_asm_prepare_evt_struct*)evt)->app_id, NEW_MEM_UT_APP2_SIZE);
			MMI_ASSERT(mem);	
			mmi_frm_group_set_user_data(((mmi_frm_asm_prepare_evt_struct*)evt)->app_id, mem);
			app_scrn_enter2();
			return MMI_FRM_ASM_FREED;
			break;
		case EVT_ID_ASM_FORCE_FREE:
        case EVT_ID_ASM_CANCELED:            
			mem = mmi_frm_group_get_user_data(((mmi_frm_asm_evt_struct*)evt)->app_id);
			if (mem)
			{
				mmi_frm_asm_free_r(((mmi_frm_asm_evt_struct*)evt)->app_id, mem);
				mmi_frm_group_set_user_data(((mmi_frm_asm_prepare_evt_struct*)evt)->app_id, NULL);
			}
			mmi_frm_group_close(((mmi_frm_asm_evt_struct*)evt)->app_id);
			break;
		case EVT_ID_GROUP_DEINIT:
			mem = mmi_frm_group_get_user_data(g_gid[1]);
			if (mem)
				mmi_frm_asm_free_r(g_gid[1], mem);
			break;
		default:
			break;
	}
	return MMI_RET_OK;

}



static mmi_id app3_launch(mmi_id caller_id, MMI_BOOL if_hide_oom)
{
	mmi_frm_asm_property_struct p;
    g_gid[2] = mmi_frm_group_create(caller_id, TEMP_MEM_APP3, app3_launch_proc, NULL);
	mmi_frm_group_enter(g_gid[2], MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_frm_asm_property_init(&p);
	p.f_skip_size_checking = 1;
	if (if_hide_oom)
	{
		p.f_hide_in_oom = 1;
	}
    mmi_frm_asm_set_property(g_gid[2], &p);
	mmi_frm_asm_prepare(g_gid[2], NEW_MEM_UT_APP3_SIZE, 
                        app3_launch_proc, 
                        NULL, 
                        MMI_FRM_ASM_F_NONE);
	return g_gid[2];


}

static mmi_ret app3_launch_proc(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		void * mem;
		case EVT_ID_ASM_PREPARED:
			mem = mmi_frm_asm_alloc_r(((mmi_frm_asm_prepare_evt_struct*)evt)->app_id, NEW_MEM_UT_APP3_SIZE);
			MMI_ASSERT(mem);		
			mmi_frm_group_set_user_data(((mmi_frm_asm_prepare_evt_struct*)evt)->app_id, mem);
			app_scrn_enter3();	
			break;
		case EVT_ID_ASM_FORCE_FREE:
			mem = mmi_frm_group_get_user_data(((mmi_frm_asm_evt_struct*)evt)->app_id);
			if (mem)
			{
				mmi_frm_asm_free_r(((mmi_frm_asm_evt_struct*)evt)->app_id, mem);
				mmi_frm_group_set_user_data(((mmi_frm_asm_prepare_evt_struct*)evt)->app_id, NULL);
			}
			mmi_frm_group_close(((mmi_frm_asm_evt_struct*)evt)->app_id);
			return MMI_FRM_ASM_FREED;
			break;
		case EVT_ID_GROUP_DEINIT:
			mem = mmi_frm_group_get_user_data(g_gid[2]);
			if (mem)
				mmi_frm_asm_free_r(g_gid[2], mem);
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}




static void new_memory_test1_timer(void)
{
	mmi_group_event_struct evt;
	MMI_ASSERT(mmi_frm_group_get_active_id() == g_gid[2]);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_FINISHED);//(&evt, EVT_ID_APP_FINISHED, g_gid[2]);
	mmi_frm_group_close(g_gid[0]);
	mmi_frm_group_close(g_gid[1]);
	mmi_frm_group_close(g_gid[2]);
	mmi_frm_send_event_to_group(app_id, &evt);
}



static mmi_ret new_memory_test1_post_event(mmi_event_struct *evt)
{
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
	StartTimer(KEY_TIMER_ID_NONE, 5000, new_memory_test1_timer);
	return MMI_RET_OK;
}



static mmi_id app4_launch(mmi_id caller_id)
{
	mmi_frm_asm_property_struct p;
    g_gid[3] = mmi_frm_group_create(caller_id, TEMP_MEM_APP4, app4_launch_proc, NULL);
	mmi_frm_group_enter(g_gid[3], MMI_FRM_NODE_SMART_CLOSE_FLAG);
	p.f_skip_size_checking = 1;
	p.f_hide_in_oom = 0;
	
    mmi_frm_asm_set_property(g_gid[3], &p);
	mmi_frm_asm_prepare(g_gid[3], NEW_MEM_UT_APP4_SIZE, 
                        app4_launch_proc, 
                        NULL, 
                        MMI_FRM_ASM_F_NONE);
	return g_gid[3];
}


static void app_scrn4_rsk(void)
{
	
}


static void app_scrn_enter4()
{
	U16 buff[15];
	mmi_asc_to_wcs(buff, "group4 screen");
	if (!mmi_frm_scrn_enter(g_gid[3], GLOBAL_SCR_DUMMY, NULL, app_scrn_enter4, MMI_FRM_FULL_SCRN))
	{
		return;
	}
	ShowCategory7Screen(0, 0, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 
                        (U8*)buff, NULL);
	SetRightSoftkeyFunction(app_scrn4_rsk, KEY_EVENT_UP);
}

static void app4_free_asm(void)
{
	if(app4_mem)
	{
		mmi_frm_asm_free_r(g_gid[3], app4_mem);
		app4_mem = NULL;
		mmi_frm_group_close(g_gid[3]);
		applib_mem_ap_notify_stop_finished(g_gid[3], MMI_TRUE);
	}
}

static mmi_ret app4_launch_proc(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{
		case EVT_ID_ASM_PREPARED:
			if (!app4_mem)
			{		
				app4_mem = mmi_frm_asm_alloc_r(((mmi_frm_asm_prepare_evt_struct*)evt)->app_id, NEW_MEM_UT_APP4_SIZE);
				MMI_ASSERT(app4_mem);		
			}
			app_scrn_enter4();	
			break;
		case EVT_ID_ASM_FORCE_FREE:
			StartTimer(KEY_TIMER_ID_NONE, 2000, app4_free_asm);
			
			return MMI_FRM_ASM_WAITING_TO_FREE;
			break;
		case EVT_ID_GROUP_DEINIT:
  			if (app4_mem)
			{
				mmi_frm_asm_free_r(g_gid[3], app4_mem);
				app4_mem = NULL;
			}
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}


static void new_memory_test2_timer(void)
{
	mmi_group_event_struct evt;
	MMI_ASSERT(mmi_frm_group_get_active_id() == g_gid[2]);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_FINISHED);//(&evt, EVT_ID_APP_FINISHED, g_gid[2]);
	mmi_frm_group_close(g_gid[2]);
    mmi_frm_group_close(g_gid[3]);
	mmi_frm_send_event_to_group(app_id, &evt);
}

static mmi_ret new_memory_test2_post_event(mmi_event_struct *evt)
{
    // select app to stop
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
    // confirm yes
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
    // back to OOM list
	ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
	ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
    // cancel OOM, back to app4 screen
	ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
	ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
	app3_launch(GRP_ID_ROOT, MMI_FALSE);
	StartTimer(KEY_TIMER_ID_NONE + 1, 6000, new_memory_test2_timer);
	return MMI_RET_OK;
}

static void app5_stop_callback(void)
{
	
}


static mmi_ret new_memory_test3_post_event2(mmi_event_struct *evt)
{
	MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_NORMAL);

    // select to stop app
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);

    // confirm yes
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);

	MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_WAITING);
	StartTimer(KEY_TIMER_ID_NONE + 1, 5500, new_memory_test3_timer);
	return MMI_RET_OK;
}

static mmi_ret new_memory_test3_post_event(mmi_event_struct *evt)
{
	mmi_event_struct evt1;
	MMI_FRM_INIT_EVENT(&evt1, 0);
    MMI_FRM_POST_EVENT(&evt1, new_memory_test3_post_event2, NULL);

	return MMI_RET_OK;
}


static void new_memory_test3_timer(void)
{
	mmi_group_event_struct evt;
	MMI_ASSERT(mmi_frm_asm_get_manger_state() == MMI_FRM_ASM_MANAGER_STATE_FINISHED);
	MMI_ASSERT(mmi_frm_group_get_active_id() == g_gid[2]);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_FINISHED);//(&evt, EVT_ID_APP_FINISHED, g_gid[2]);
	mmi_frm_group_close(g_gid[2]);
	mmi_frm_send_event_to_group(app_id, &evt);

}

static mmi_ret app5_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    case EVT_ID_ASM_FORCE_FREE:
        // since we do background free, just return MMI_FRM_ASM_WAITING_TO_FREE
        return MMI_FRM_ASM_WAITING_TO_FREE;   
    }
    return MMI_RET_OK;
}

static mmi_id app5_launch(mmi_id caller_id)  //background free memory application
{
    mmi_frm_asm_property_struct p;

/*
	applib_mem_ap_register(
            APPLIB_MEM_AP_ID_TEST1, 
            STR_GLOBAL_1, 
            IMG_GLOBAL_L1, 
            app5_stop_callback);
*/
	g_gid[4] = mmi_frm_group_create(caller_id, GRP_ID_AUTO_GEN, app5_proc, NULL);

    /* skip size checking */
    mmi_frm_asm_get_property(g_gid[4], &p);
    p.f_skip_size_checking = 1;
    mmi_frm_asm_set_property(g_gid[4], &p);

	mmi_frm_group_enter(g_gid[4], MMI_FRM_NODE_SMART_CLOSE_FLAG);
	app5_mem = mmi_frm_asm_alloc_r(g_gid[4], mmi_frm_asm_get_pool_size_r() - NEW_MEM_UT_APP3_SIZE + 1024);
	app_scrn_enter5();
	return g_gid[4];
}



static void app5_free_mem(void)
{
    // free memory then back to OOM list
	mmi_id asm_id;

	if(app5_mem)
    {   
        mmi_frm_asm_free_r(g_gid[4], app5_mem);
        app5_mem = NULL;
    }

    mmi_frm_group_close(g_gid[4]);
    
	mmi_frm_asm_manager_is_launched(&asm_id);
	if (mmi_frm_group_get_top_parent_group_id(mmi_frm_group_get_active_id()) == asm_id)
	{
        // back to OOM list should start new app
		ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
		ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
	}
}


static void app_scrn_exit5(void)
{
    mmi_frm_group_hide(g_gid[4]);
	StartTimer(KEY_TIMER_ID_NONE, 1000, app5_free_mem);
	//mmi_frm_scrn_close_active_id();
}


static void app_scrn_enter5(void)
{
	U16 buff[15];
	mmi_asc_to_wcs(buff, "group5 screen");
	if (!mmi_frm_scrn_enter(g_gid[4], GLOBAL_SCR_DUMMY, NULL, 
					        app_scrn_enter5, MMI_FRM_FULL_SCRN))
	{
		return;
	}
	ShowCategory7Screen(0, 0, STR_GLOBAL_OK, IMG_GLOBAL_OK, STR_GLOBAL_BACK, IMG_GLOBAL_BACK, 
                        (U8*)buff, NULL);
	SetRightSoftkeyFunction(app_scrn_exit5, KEY_EVENT_UP);
}

static void new_memory_test4_timer(void)
{
	mmi_id asm_id;
	mmi_group_event_struct evt;

	MMI_ASSERT(!mmi_frm_group_is_present(g_gid[1]));
	MMI_ASSERT(!mmi_frm_asm_manager_is_launched(&asm_id));
	//MMI_ASSERT(applib_mem_ap_get_alloc_count() == 0);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_FINISHED);//(&evt, EVT_ID_APP_FINISHED, g_gid[2]
	mmi_frm_send_event_to_group(app_id, &evt);
}

static mmi_ret new_memory_test4_post_event(mmi_event_struct *evt)
{
	mmi_id asm_id;
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP);
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
	ExecuteCurrKeyHandler(KEY_LSK, KEY_EVENT_UP); // progressing screen
	mmi_frm_asm_cancel_prepare(g_gid[1], app2_launch_proc, NULL);
	mmi_frm_group_close(g_gid[1]);
	MMI_ASSERT(!mmi_frm_asm_manager_is_launched(&asm_id));
	StartTimer(KEY_TIMER_ID_NONE +1, 3000, new_memory_test4_timer);
	return MMI_RET_OK;
}

static void new_memory_test5_post_check(mmi_event_struct *evt1)
{	
	mmi_group_event_struct  evt;
	mmi_frm_group_close(g_gid[3]);
	//MMI_ASSERT(applib_mem_ap_get_alloc_count() == 0);
	MMI_FRM_INIT_EVENT(&evt, EVT_ID_APP_FINISHED);//(&evt, EVT_ID_APP_FINISHED, g_gid[2]
	mmi_frm_post_event_to_group(app_id, &evt);
}

static void new_memory_test5_check(void)
{
	mmi_event_struct evt;
	mmi_frm_group_close(mmi_frm_group_get_active_id());
	mmi_frm_group_close(g_gid[0]);
	MMI_FRM_INIT_EVENT(&evt, 0);
	MMI_FRM_POST_EVENT(&evt, new_memory_test5_post_check, NULL);
}


static void new_memory_test5_timer(void)
{
	if(app5_mem)
	{
		mmi_frm_asm_free_r(g_gid[4], app5_mem);
        app5_mem = NULL;
		mmi_frm_appmem_stop_finished(g_gid[4], STR_GLOBAL_1, MMI_TRUE); //update OOM Screen
	}
	StartTimer(KEY_TIMER_ID_NONE +1, 1000, new_memory_test5_check);
}
static mmi_ret srv_proc(mmi_event_struct *evt)
{
	switch(evt->evt_id)
	{	
		void *mem;
		case EVT_ID_MEM_IS_ENOUGH:
			mem = mmi_frm_asm_alloc_r(srv_id, NEW_MEM_UT_APP1_SIZE);
			break;
			
		default: 
			break;
	}
	return MMI_RET_OK;
}


class VtstRttepmem : public VtstRtApp
{
	VFX_DECLARE_CLASS(VtstRttepmem);
	
public:
    virtual void onRun(void* args, VfxU32 argSize)
    {
        VtstRtApp::onRun(args, argSize);
        
        vtst_testcase_start(this, VFX_FALSE);       
    }

protected:
    virtual void onInit()
    {
        VtstRtApp::onInit();
    }
    virtual mmi_ret onProc(mmi_event_struct *e)
    {
        switch (e->evt_id)
        {
        case EVT_ID_APP_FINISHED:
            {
                endPhase();
            }
            break;
        }
        return MMI_RET_OK;
    }

    virtual int start()
    {
        return 0; // unknow phase count
    }

    virtual VfxS32 phase(VfxS32 idx)
    { 
		U32 i = 0;
		#ifdef __COSMOS_MMI_PACKAGE__
        if (idx == i) //temp memory
        {
        	U32 size;
			size = mmi_frm_temp_get_max_left_size();
			MMI_ASSERT((size - 9 * (20))>= (20 * 1024));
			i++;
            return 500;
        }
        else if (idx == i)//temp memory
        {
        	S8 *ptr[10];
			U8 i;
			for(i=0; i<10; i++)
		    {
		    	ptr[i] = (S8 *)mmi_frm_temp_alloc(2*1024);
				MMI_ASSERT(ptr);
				MMI_ASSERT(mmi_frm_temp_get_allocate_num() == (i + 1));
			}
			for(i=0; i<10; i++)
			{
				mmi_frm_temp_free(ptr[i]);
				MMI_ASSERT(mmi_frm_temp_get_allocate_num() == (9 - i));
			}
			mmi_frm_temp_check_all_free();
			i++;
            return 500;
        }
		else if (idx == i) // hide application in OOM Screen
	    {
			mmi_event_struct evt;
			app1_launch(GRP_ID_ROOT, MMI_TRUE);
			app2_launch(GRP_ID_ROOT, MMI_FALSE);
			applib_mem_ap_dump();
			app3_launch(GRP_ID_ROOT, MMI_FALSE);
		    MMI_FRM_INIT_EVENT(&evt, 0);
            MMI_FRM_POST_EVENT(&evt, new_memory_test1_post_event, NULL);
			i++;
			return -1;
		}
		
		else if (idx == i)  //Async case
	    {
			mmi_event_struct evt;
	    	app4_launch(GRP_ID_ROOT);
			app2_launch(GRP_ID_ROOT, MMI_FALSE);
			MMI_FRM_INIT_EVENT(&evt, 0);
            MMI_FRM_POST_EVENT(&evt, new_memory_test2_post_event, NULL);
			i++;
			return -1;
		}
		else if (idx == i)  //background free application, go back to OOM should launch new application
		{
			mmi_event_struct evt;
			app5_launch(GRP_ID_ROOT);
            app_scrn_exit5();
			//ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_DOWN);
			//ExecuteCurrKeyHandler(KEY_RSK, KEY_EVENT_UP);
			app3_launch(GRP_ID_ROOT, MMI_FALSE);
			MMI_FRM_INIT_EVENT(&evt, 0);
            MMI_FRM_POST_EVENT(&evt, new_memory_test3_post_event, NULL);
			i++;
			return -1;
		}
		else if(idx == i)   // Cancel prepare request
		{
			mmi_event_struct evt;
			app4_launch(GRP_ID_ROOT);
			app2_launch(GRP_ID_ROOT, MMI_FALSE);
			MMI_FRM_INIT_EVENT(&evt, 0);
            MMI_FRM_POST_EVENT(&evt, new_memory_test4_post_event, NULL);
			i++;
			return -1;
		}
		else if(idx == i)  // background free at oom screen
		{
			app5_launch(GRP_ID_ROOT);
			app1_launch(GRP_ID_ROOT, MMI_FALSE);			
			app4_launch(GRP_ID_ROOT);
			StartTimer(KEY_TIMER_ID_NONE +1, 2000, new_memory_test5_timer);
			i++;
			return -1;
		}
		/*
		else if (idx == 7)
		{
			void *mem = NULL;
			app1_launch(GRP_ID_ROOT, MMI_FALSE);
			app2_launch(GRP_ID_ROOT, MMI_FALSE);
			srv_id = mmi_frm_srv_instance_create(g_gid[1], TEMP_MEM_APP3, srv_proc, NULL);
			mem = mmi_frm_asm_alloc_r(srv_id, NEW_MEM_UT_APP3_SIZE);
			if (mem)
			{
				mmi_frm_srv_instance_set_user_data(srv_id, mem);
			}
			return -1;
		}
    	*/
        else
        {
            return VTST_RT_END_TESTCASE;
        }
        
        #else
        	return VTST_RT_END_TESTCASE;
        
		#endif
    }

    virtual void end()
    {
    }

};
VFX_IMPLEMENT_CLASS("RttempmemTest", VtstRttepmem, VtstRtApp);



void vtst_rt_temp_free_med(void *ptr, module_type id)
{
    mmi_frm_asm_free_anonymous(ptr);
}


VtstTestResultEnum vtst_rt_tepmem(VfxU32 param)
{
	VtstRtAppStartupParam startup;
	startup.memSize = APP1_HEAP_SIZE;
	startup.buffer  = (VfxU8 *)mmi_frm_asm_alloc_anonymous(startup.memSize);
    app_id = VfxAppLauncher::launchWithMem( 
	                    APP1_BASE, 
	                    VFX_OBJ_CLASS_INFO(VtstRttepmem),
	                    GRP_ID_ROOT,
	                    (void *)startup.buffer,startup.memSize,
	                    (VfxAppContextCbType)vtst_rt_temp_free_med, (void *)stack_get_active_module_id(),
	                    &startup,
	                    sizeof(VtstRtAppStartupParam));



		
	 return VTST_TR_OK;	
}


#endif
