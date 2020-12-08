#include "vmfrm.h"
#include "vmopt.h"
#include "GlobalResDef.h"
#include "Wgui_categories_util.h"
#include "mmi_rp_app_mre_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "vmpromnginner.h"
#include "gpiosrvgprot.h"

extern void vm_reg_key_handler(void);
extern void vm_reg_pen_handler(void);
extern VMINT vm_ime_close_ime_screen(void);
extern VMINT vm_pmng_set_inactive(VM_P_HANDLE pHandle);
extern VMINT vm_pmng_set_bg_ex(VM_P_HANDLE pHandle);
extern VM_P_HANDLE vm_pmng_set_fg_ex(VM_P_HANDLE pHandle);
extern VMBOOL vm_pmng_is_support_screen(VM_P_HANDLE phandle);
extern void vm_graphic_flatten_previous_blt_layer_to_base_layer(void);

typedef struct
{
	mmi_id 		group_id;
	VM_P_HANDLE pHandle;
}vm_frm_node;

static vm_frm_node 	g_vm_frm_nodes[MRE_SUPPORT_MAX_APP_NUM];
static VMINT		g_vm_frm_scenario_flag = 1;
static VMINT		g_vm_frm_scenario_handle = 0;

static void vm_frm_scenario_lock(VM_P_HANDLE pHandle)
{
	g_vm_frm_scenario_flag = 0;
	g_vm_frm_scenario_handle = pHandle;
}

static void vm_frm_scenario_unlock(void)
{
	g_vm_frm_scenario_flag = 1;
	g_vm_frm_scenario_handle = 0;
}

static VMINT vm_frm_scenario_is_lock(VM_P_HANDLE pHandle)
{
	if (0 == g_vm_frm_scenario_flag && pHandle == g_vm_frm_scenario_handle)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

static mmi_id vm_frm_gen_group_id(VM_P_HANDLE pHandle)
{
	VMINT i = 0;

	for (i = 0; i < MRE_SUPPORT_MAX_APP_NUM; i++)
	{
		if (g_vm_frm_nodes[i].pHandle == pHandle)
		{
			return g_vm_frm_nodes[i].group_id;
		}
	}

	for (i = 0; i < MRE_SUPPORT_MAX_APP_NUM; i++)
	{
		if (g_vm_frm_nodes[i].pHandle == NULL)
		{
			g_vm_frm_nodes[i].pHandle = pHandle;
			return g_vm_frm_nodes[i].group_id;
		}
	}	

	return 0;
}

static VMINT vm_frm_clear_group_id(VM_P_HANDLE pHandle)
{
	VMINT i = 0;

	for (; i < MRE_SUPPORT_MAX_APP_NUM; i++)
	{
		if (g_vm_frm_nodes[i].pHandle == pHandle)
		{
			g_vm_frm_nodes[i].pHandle = 0;
			return 0;
		}
	}
	return -1;
}

static mmi_ret vm_frm_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_OK;
	VM_P_HANDLE	pHandle = (VM_P_HANDLE)evt->user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_frm_scenario_is_lock(pHandle))
    {
    	return ret;
    }
    MMI_TRACE(MMI_MRE_TRC_G8_FRM,TRC_MRE_FRM_GROUP_PROC,pHandle,evt->evt_id);
    
    switch (evt->evt_id)
    {        	
        case EVT_ID_GROUP_DEINIT:
         	vm_frm_clear_group_id(pHandle);
            break;
		case EVT_ID_GROUP_GOBACK_IN_END_KEY:
		case EVT_ID_GROUP_DELETE_REQ:
		case EVT_ID_GROUP_DELETE_REQ_IN_END_KEY:
            vm_pmng_set_bg_ex(pHandle);
			break;
		default:
			break;
    }
    return ret;
}

static void vm_frm_exit_func(mmi_scrn_essential_struct* data)
{
	vm_graphic_flatten_previous_blt_layer_to_base_layer();
    leave_full_screen();
    vm_pmng_set_inactive((VM_P_HANDLE)data->user_data);
}

static void vm_frm_entry_func(mmi_scrn_essential_struct* data)
{
    MMI_TRACE(MMI_MRE_TRC_G8_FRM,TRC_MRE_FRM_ENTRY_FUNC,data->user_data);
    
    gui_screen_switch_effect_block(MMI_TRUE);
    
	mmi_frm_scrn_enter(data->group_id, data->scrn_id, (FuncPtr)vm_frm_exit_func, (FuncPtr)vm_frm_entry_func, MMI_FRM_FULL_SCRN);

	/* To resolve screen rotate UI error */
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    
	entry_full_screen();
	
	vm_reg_key_handler();
    vm_reg_pen_handler();

	if (!vm_frm_scenario_is_lock((VM_P_HANDLE)data->user_data))
    {
    	vm_pmng_set_fg_ex((VM_P_HANDLE)data->user_data);
    }    
}

void vm_frm_init(void)
{
	VMINT i = 0;

	for (; i < MRE_SUPPORT_MAX_APP_NUM; i++)
	{
		g_vm_frm_nodes[i].group_id = GRP_ID_MRE0+i;
		g_vm_frm_nodes[i].pHandle = 0;
	}
}

mmi_id vm_frm_get_group_id(VM_P_HANDLE pHandle)
{
	VMINT i = 0;

	for (; i < MRE_SUPPORT_MAX_APP_NUM; i++)
	{
		if (g_vm_frm_nodes[i].pHandle == pHandle)
		{
			return g_vm_frm_nodes[i].group_id;
		}
	}
	
	return 0;
}

VM_P_HANDLE vm_frm_get_app_handle(mmi_id group_id)
{
	VMINT i = 0;

	for (; i < MRE_SUPPORT_MAX_APP_NUM; i++)
	{
		if (g_vm_frm_nodes[i].group_id == group_id)
		{
			return g_vm_frm_nodes[i].pHandle;
		}
	}
	
	return 0;
}

VMINT vm_frm_entry_app_screen(VM_P_HANDLE pHandle)
{
	mmi_id group_id = 0;
	mmi_scenario_state_enum state;

	if (!vm_pmng_is_support_screen(pHandle))
	{
	    return -1;
	}

	group_id = vm_frm_gen_group_id(pHandle);

    MMI_TRACE(MMI_MRE_TRC_G8_FRM,TRC_MRE_FRM_ENTRY_APP_SCREEN,pHandle,group_id);
    
	if (0 == group_id)
	{
//		vm_log_fatal("[MRE]vm_frm_entry_app_screen get group id fail!");
		return -1;
	}

	vm_frm_scenario_lock(pHandle);
	if (mmi_frm_group_is_present(group_id))
	{
		state = mmi_frm_group_get_state(group_id);
		if (MMI_SCENARIO_STATE_HIDE & state)
		{
			mmi_frm_group_unhide(group_id);
		}
		else if (MMI_SCENARIO_STATE_INACTIVE &  state)
		{
			mmi_frm_set_active_group(group_id);
		}			
	}
	else
	{
		mmi_frm_group_create(GRP_ID_ROOT, group_id, vm_frm_group_proc, (void*)pHandle);
	    mmi_frm_group_enter(group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

	    mmi_frm_scrn_first_enter(group_id, MRE_SCREEN_ID0, 
                    (FuncPtr)vm_frm_entry_func, (void*)pHandle);
	}
    vm_frm_scenario_unlock();
	
	/* 
	 * resolve bugs about MRE Editor :
	 * 1. 在vm_editor_create中disable softkey，但是softkey区域显示蓝色（异常）。
	 * 2. 隐藏VK后，App收到的rect坐标错误。
	 */
	MMI_content_y = 0;
	MMI_content_height = UI_DEVICE_HEIGHT;
	
   	return 0;
}

VMINT vm_frm_exit_app_screen(VM_P_HANDLE pHandle)
{
	mmi_id group_id = 0;
	
	if (!vm_pmng_is_support_screen(pHandle))
	{
	    return -1;
	}

	vm_frm_scenario_lock(pHandle);
//		vm_ime_close_ime_screen();
		group_id = vm_frm_get_group_id(pHandle);
		MMI_TRACE(MMI_MRE_TRC_G8_FRM,TRC_MRE_FRM_EXIT_APP_SCREEN,pHandle,group_id);
		
		if (group_id > 0)
		{
			mmi_frm_group_close(group_id);
		}
		vm_frm_clear_group_id(pHandle);
		vm_frm_scenario_unlock();

	return 0;
}


MMI_BOOL vm_frm_is_active(void)
{
	MMI_ID i = GRP_ID_MRE0;
	MMI_ID active_id = mmi_frm_group_get_active_id();

	for (; i <= GRP_ID_MRE9; i++)
	{
		if (active_id == i)
        {
            return MMI_TRUE;
        }
	}
    return MMI_FALSE;
}

mmi_ret vm_frm_backlight_notify_hdlr(mmi_event_struct* evt)
{
    VM_P_HANDLE pHandle;
    if (!vm_frm_is_active())
    {
        return 0;
    }

    pHandle = vm_frm_get_app_handle(mmi_frm_group_get_active_id());
    if (vm_frm_scenario_is_lock(pHandle))
    {
    	return 0;
    }
    
    if (EVT_ID_GPIO_LCD_SLEEP_IN == evt->evt_id)
    {
        vm_pmng_set_inactive(pHandle);
    }
    else if (EVT_ID_GPIO_LCD_SLEEP_OUT == evt->evt_id)
    {
        vm_pmng_set_fg_ex(pHandle);
    }
    return 0;
}

