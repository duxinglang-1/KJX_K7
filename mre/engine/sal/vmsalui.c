/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * vmsalui.c
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
 * 
 *
*==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/


#include "vmswitch.h"
#ifdef __MRE_CORE_BASE__

#include "MMIDataType.h"
#include "NotificationGprot.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_mem_gprot.h"

#include "vmsalui.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmlog.h"
#include "vmmem.h"


#ifdef __COSMOS_MMI_PACKAGE__	
extern VMINT vm_nmgr_confirm_popup_show(vm_common_ui_info_struct *ui_info, vm_common_ui_res_struct *ui_res_p);
extern VMINT vm_nmgr_confirm_popup_cancel(VMINT grp_id);
#endif	/* __COSMOS_MMI_PACKAGE__ */

extern void vm_nmgr_confirm_popup_user_callback (vm_common_ui_confirm_evt_enum evt_id, VMINT common_ui_id);

static const mmi_event_notify_enum popup_type_mapping_evt_table[] =
{
	MMI_EVENT_FAILURE,
	MMI_EVENT_INFO,
	MMI_EVENT_WARNING,
	MMI_EVENT_SUCCESS,
	MMI_EVENT_PROGRESS,
	MMI_EVENT_QUERY
};

#ifndef __COSMOS_MMI_PACKAGE__	
static const mmi_event_notify_enum confirm_popup_type_mapping_evt_table[] =
{
	MMI_EVENT_FAILURE,
	MMI_EVENT_INFO,
	MMI_EVENT_WARNING,
	MMI_EVENT_SUCCESS,
	MMI_EVENT_PROGRESS,
	MMI_EVENT_QUERY
};

typedef struct
{
    mmi_proc_func     callBack;    
    void                  *userData;   
    vm_confirm_type_enum  gpType;      
    MMI_ID                parentID;    
    mmi_scenario_id       scenID;
    mmi_event_notify_enum evtType; 
    VMWCHAR               *text;
    VMWCHAR               *btnText1;
    VMWCHAR               *btnText2;
} vm_confirm_property_struct;


static mmi_ret vm_nmgr_confirm_popup_callback(mmi_alert_result_evt_struct *evt)
{	
	VMINT common_ui_id = (VMINT)evt->user_tag;
	vm_common_ui_confirm_evt_enum evt_id = VM_COMMON_UI_CONFIRM_EVENT_MAX;

	if (evt->evt_id == EVT_ID_ALERT_QUIT)
	{	
		switch (evt->result)
		{
			case MMI_ALERT_CNFM_1:	
				evt_id = VM_COMMON_UI_CONFIRM_EVENT_USER_1;
				break;
			case MMI_ALERT_CNFM_2:
				break;
			case MMI_ALERT_CNFM_3:	
				evt_id = VM_COMMON_UI_CONFIRM_EVENT_USER_2;
				break;	
			case MMI_ALERT_CNFM_CANCEL:
				evt_id = VM_COMMON_UI_CONFIRM_EVENT_BUTTON_NONE;
				break;
			case MMI_ALERT_NORMAL_EXIT:
				break;
			case MMI_ALERT_INTERRUPT_EXIT:
				evt_id = VM_COMMON_UI_CONFIRM_EVENT_BUTTON_NONE;
				break;				
			default:
				break; 
		}
	}	
	else if (evt->evt_id == EVT_ID_GROUP_DEINIT)
	{
		evt_id = VM_COMMON_UI_CONFIRM_EVENT_BUTTON_NONE;
	}

	if (evt_id != VM_COMMON_UI_CONFIRM_EVENT_MAX)
	{
		vm_nmgr_confirm_popup_user_callback(evt_id, common_ui_id);
	}

	return MMI_RET_OK;
}

static MMI_BOOL vm_nmgr_global_popup_defer_callback(mmi_scenario_id scen_id, void *arg)
{
    vm_confirm_property_struct *p = (vm_confirm_property_struct *)arg;
	mmi_confirm_property_struct confirm_arg;
	
	mmi_frm_group_enter(p->parentID, MMI_FRM_NODE_SMART_CLOSE_FLAG);
			
	mmi_confirm_property_init(&confirm_arg, CNFM_TYPE_USER_DEFINE);
	confirm_arg.parent_id = p->parentID;
    if (p->gpType == VM_CONFIRM_ONE_BUTTON_STR)
    {
		confirm_arg.softkey[0].str = (WCHAR *)(get_string(0));
		confirm_arg.softkey[2].str = (WCHAR *)(p->btnText1);
	}
	else if (p->gpType == VM_CONFIRM_TWO_BUTTON_STR)
	{
		confirm_arg.softkey[0].str = (WCHAR *)(p->btnText1);	
		confirm_arg.softkey[2].str = (WCHAR *)(p->btnText2);			
	}
	confirm_arg.f_auto_map_empty_softkey = MMI_FALSE;
    confirm_arg.callback = (mmi_proc_func)(p->callBack);
	confirm_arg.user_tag = (void *)(p->userData);	
	
	mmi_confirm_display((WCHAR *)(p->text), p->evtType, &confirm_arg);
	
	mmi_frm_asm_free_anonymous(p->text);
	mmi_frm_asm_free_anonymous(p->btnText1);
    if (p->gpType == VM_CONFIRM_TWO_BUTTON_STR)
        mmi_frm_asm_free_anonymous(p->btnText2);

    return MMI_TRUE;
}


static mmi_ret vm_nmgr_global_popup_proc(mmi_event_struct *evt)
{
	vm_confirm_property_struct * p = (vm_confirm_property_struct *)evt->user_data;

    if (evt->evt_id == EVT_ID_GROUP_DEINIT)
    {
        if (mmi_frm_nmgr_is_scenario_deferred(p->scenID, vm_nmgr_global_popup_defer_callback, evt->user_data))
        {
			p->callBack(evt);
			
			mmi_frm_nmgr_cancel_deferred_scenario(
				p->scenID, 
				vm_nmgr_global_popup_defer_callback,
				evt->user_data);
			
			mmi_frm_asm_free_anonymous(p->text);
			mmi_frm_asm_free_anonymous(p->btnText1);
			if (p->gpType == VM_CONFIRM_TWO_BUTTON_STR)
				mmi_frm_asm_free_anonymous(p->btnText2);
        }
		else
		{}

        mmi_mfree(evt->user_data);
    }
	else if (evt->evt_id == EVT_ID_DELETE_DANGLE_GROUP_REQ)
	{
		return MMI_RET_ERR;
	}
	else if (evt->evt_id == EVT_ID_GROUP_ACTIVE)
	{
	    mmi_frm_start_scenario(p->scenID);
	}
	else if (evt->evt_id == EVT_ID_GROUP_INACTIVE)
	{
	    mmi_frm_end_scenario(p->scenID);
	}

    return MMI_RET_OK;
}

static VMINT vm_nmgr_global_popup_common(mmi_scenario_id scenID, MMI_ID parentID, mmi_event_notify_enum evtType, void *arg)
{
    VMINT id;
	vm_confirm_property_struct *p = (vm_confirm_property_struct *)arg;
	
    id = mmi_frm_group_create(parentID, GRP_ID_AUTO_GEN, vm_nmgr_global_popup_proc, (void *)arg);    
	
	p->parentID = id;
    mmi_frm_nmgr_notify_by_app(
        scenID,
        evtType,
        vm_nmgr_global_popup_defer_callback,
        (void *)arg);
	return id;
}

static VMINT vm_nmgr_global_popup_show_confirm(
        vm_confirm_type_enum gpType,
        mmi_scenario_id scenID,
        mmi_event_notify_enum evtType, 
        const VMWCHAR *text, 
        const VMWCHAR *btnText1, 
        const VMWCHAR *btnText2, 
        mmi_proc_func callBack,
        void *userData)
{
	VMINT id;
    vm_confirm_property_struct *arg = (vm_confirm_property_struct *)mmi_malloc(sizeof(vm_confirm_property_struct));

	arg->gpType = gpType;
    arg->scenID = scenID;
    arg->evtType = evtType;
    arg->callBack = callBack;
    arg->userData = userData;
    
    arg->text = (VMWCHAR *)mmi_frm_asm_alloc_anonymous_sw((kal_wstrlen(text)+ 1) * sizeof(VMWCHAR));
	if (arg->text == NULL)
	{
		mmi_mfree(arg);
		return 0;
	}
    memcpy(arg->text, text, (kal_wstrlen(text) + 1) * sizeof(VMWCHAR));
    
	arg->btnText1 = (VMWCHAR *)mmi_frm_asm_alloc_anonymous_sw((kal_wstrlen(btnText1) + 1) * sizeof(VMWCHAR));
	if (arg->btnText1 == NULL)
	{
		mmi_mfree(arg);
		mmi_frm_asm_free_anonymous(arg->text);
		return 0;
	}
    memcpy(arg->btnText1, btnText1, (kal_wstrlen(btnText1) + 1) * sizeof(VMWCHAR));

    if (arg->gpType == VM_CONFIRM_TWO_BUTTON_STR)
    {
		arg->btnText2 = (VMWCHAR *)mmi_frm_asm_alloc_anonymous_sw((kal_wstrlen(btnText2) + 1) * sizeof(VMWCHAR));
		if (arg->btnText2 == NULL)
		{
			mmi_mfree(arg);
			mmi_frm_asm_free_anonymous(arg->text);		
			mmi_frm_asm_free_anonymous(arg->btnText1);
			return 0;
		}
	    memcpy(arg->btnText2, btnText2, (kal_wstrlen(btnText2) + 1) * sizeof(VMWCHAR));
    }
	
    id = vm_nmgr_global_popup_common(scenID, GRP_ID_ROOT, evtType, arg);
    return id;     
}

static void vm_nmgr_confirm_popup_cancel(VMINT grp_id)
{
	mmi_frm_group_close(grp_id);
}

static VMINT vm_nmgr_confirm_popup_show(vm_common_ui_info_struct *ui_info, vm_common_ui_res_struct *ui_res_p)
{
	mmi_event_notify_enum confirm_popup_type = confirm_popup_type_mapping_evt_table[ui_info->confirm_popup_para.confirm_popup_type];
	VMINT grp_id = 0;
		
	if (ui_info->confirm_popup_para.confirm_type == VM_COMMON_UI_CONFIRM_TYPE_ONE_BUTTON)
	{
		ui_res_p->gpType = VM_CONFIRM_ONE_BUTTON_STR;
		grp_id = vm_nmgr_global_popup_show_confirm(
				VM_CONFIRM_ONE_BUTTON_STR,
				MMI_SCENARIO_ID_DEFAULT,
				confirm_popup_type, 
				(VMWCHAR *)(ui_info->confirm_popup_para.popup_string), 
				(VMWCHAR *)(ui_info->confirm_popup_para.popup_button_string1),
				NULL,
				vm_nmgr_confirm_popup_callback,
				(void *)(ui_res_p->m_nResid));
	}
	else if (ui_info->confirm_popup_para.confirm_type == VM_COMMON_UI_CONFIRM_TYPE_TWO_BUTTON)
	{
		ui_res_p->gpType = VM_CONFIRM_TWO_BUTTON_STR;	
		grp_id = vm_nmgr_global_popup_show_confirm(
				VM_CONFIRM_TWO_BUTTON_STR,
				MMI_SCENARIO_ID_DEFAULT,
				confirm_popup_type, 
				(VMWCHAR *)(ui_info->confirm_popup_para.popup_string), 
				(VMWCHAR *)(ui_info->confirm_popup_para.popup_button_string1), 
				(VMWCHAR *)(ui_info->confirm_popup_para.popup_button_string2), 
				vm_nmgr_confirm_popup_callback,
				(void *)(ui_res_p->m_nResid));
	}

	return grp_id;
}


#endif	/* __COSMOS_MMI_PACKAGE__ */

void vm_nmgr_confirm_popup_user_callback (vm_common_ui_confirm_evt_enum evt_id, VMINT common_ui_id)	
{
    VMINT res_node_size = 0;
    vm_common_ui_res_struct *res_p = NULL;

	if (vm_res_get_data(VM_RES_TYPE_COMMON_UI, common_ui_id, (void **)&res_p, &res_node_size) < VM_RES_OK)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CONFIRM_USER_CB_GET_RES_FAIL, common_ui_id); 
		return;
	}

	if (res_p->gpType == VM_CONFIRM_ONE_BUTTON_STR && evt_id == VM_COMMON_UI_CONFIRM_EVENT_USER_1)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CONFIRM_USER_CB_WRONG_EVT_ID, res_p->gpType, evt_id); 
	}
	else
	{
		if (res_p->gpType == VM_CONFIRM_ONE_BUTTON_STR && evt_id == VM_COMMON_UI_CONFIRM_EVENT_USER_2)
		{
			evt_id = VM_COMMON_UI_CONFIRM_EVENT_USER_1;
		}
		
		if (vm_pmng_set_ctx(res_p->m_pHandle) == VM_PMNG_OP_OK)
		{
			if (res_p->callback_func)
			{
				res_p->callback_func(evt_id, res_p->user_data);
			}
			vm_pmng_reset_ctx();
		}
	}
	
	_vm_kernel_free(res_p);
	
	if (vm_res_release_data(VM_RES_TYPE_COMMON_UI, common_ui_id) < VM_RES_OK)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CONFIRM_RELEASE_RES_FAIL, common_ui_id);
		return;
	}	
}

static VMINT vm_nmgr_confirm_popup(vm_common_ui_info_struct *ui_info)
{
	VM_P_HANDLE phandle;	
	vm_common_ui_res_struct * ui_res_p;
	VMINT common_ui_id;
	VMINT grp_id;

	if ((phandle = vm_pmng_get_app_handle()) == 0)
	{
       	MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CONFIRM_GET_CUR_HANDLE_FAIL);
		return VM_COMMON_UI_ERROR;  		
	}
	
	if((ui_res_p = (vm_common_ui_res_struct *)_vm_kernel_malloc(sizeof(vm_common_ui_res_struct))) == NULL)
    {
       	MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CONFIRM_GET_MEM_FAIL);
		return VM_COMMON_UI_ERROR_OF_MEM;
    }

	ui_res_p->m_pHandle = phandle;
	ui_res_p->callback_func = ui_info->confirm_popup_para.confirm_popup_proc;
	ui_res_p->user_data = ui_info->confirm_popup_para.user_data;
	
	if ((common_ui_id = vm_res_save_data(VM_RES_TYPE_COMMON_UI, (void *) ui_res_p, sizeof(vm_common_ui_res_struct),NULL, phandle)) < 0)
	{
		_vm_kernel_free(ui_res_p);
       	MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CONFIRM_SAVE_RES_FAIL);
		return VM_COMMON_UI_ERROR_OF_RES;
	}
	ui_res_p->m_nResid = common_ui_id;

	grp_id = vm_nmgr_confirm_popup_show(ui_info, ui_res_p);

	MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CONFIRM_POPUP_INFO, grp_id, common_ui_id);

	if (grp_id == 0)
	{
		_vm_kernel_free(ui_res_p);
		if (vm_res_release_data(VM_RES_TYPE_COMMON_UI, common_ui_id) < VM_RES_OK)
		{
			MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CONFIRM_RESLEASE_RES_FAIL, common_ui_id); 
		}
		return VM_COMMON_UI_ERROR;
	}
	else
	{
		ui_res_p->grp_id = grp_id;
	}

	return common_ui_id;
}


VMINT vm_common_ui_show(vm_common_ui_info_struct *ui_info)
{
#ifdef __MMI_NCENTER_SUPPORT__		
	mmi_frm_notification_para_struct notification;
#endif
	mmi_event_notify_enum nmgr_popup_event;
	VMINT ret = VM_COMMON_UI_OK;

	MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_BASIC_INFO, ui_info->ui_type, ui_info->behavior_mask); 
	
	if (ui_info->ui_type == VM_COMMON_UI_TYPE_BALLOON)
	{
#ifdef __COSMOS_MMI_PACKAGE__	
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR *)(ui_info->balloon_para.display_string));
#else
		if (ui_info->behavior_mask & VM_COMMON_UI_MASK_NO_SHOW_UNSUPPORTED)
		{
			ret = VM_COMMON_UI_ERROR_UNSUPPORTED;
		}
		else
		{
			mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO, (WCHAR *)(ui_info->balloon_para.display_string));
		}
#endif
	}
	else if (ui_info->ui_type == VM_COMMON_UI_TYPE_TEXT_PREVIEW)
	{
#ifdef __MMI_NCENTER_SUPPORT__		
		notification.text = (WCHAR *)(ui_info->text_preview_para.display_string);
		notification.option = 0;
		mmi_frm_nmgr_notify(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_GENERAL_PREVIEW, &notification);
#else
		if (ui_info->behavior_mask & VM_COMMON_UI_MASK_NO_SHOW_UNSUPPORTED)
		{
			ret = VM_COMMON_UI_ERROR_UNSUPPORTED;
		}
		else
		{
			mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO, (WCHAR *)(ui_info->text_preview_para.display_string));
		}
#endif
	}
	else if (ui_info->ui_type == VM_COMMON_UI_TYPE_POPUP)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_POPUP_INFO, ui_info->popup_para.popup_type); 
	
#ifdef __COSMOS_MMI_PACKAGE__	
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR *)(ui_info->popup_para.display_string));
#else
		nmgr_popup_event = popup_type_mapping_evt_table[ui_info->popup_para.popup_type];

		mmi_frm_nmgr_popup(MMI_SCENARIO_ID_DEFAULT, nmgr_popup_event, (WCHAR *)(ui_info->popup_para.display_string));
#endif
	}
	else if (ui_info->ui_type == VM_COMMON_UI_TYPE_CONFIRM)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CONFIRM_INFO, ui_info->confirm_popup_para.confirm_type, ui_info->confirm_popup_para.confirm_popup_type); 
	
		ret = vm_nmgr_confirm_popup(ui_info);
	}
	else
	{
		ret = VM_COMMON_UI_ERROR_WRONG_PARAM;
	}

	return ret;
}

VMINT vm_common_ui_cancel(VMINT common_ui_id)
{
    VMINT res_node_size = 0;
    vm_common_ui_res_struct *res_p = NULL;
    VM_P_HANDLE phandle = -1;
    VM_P_HANDLE curr_phandle = vm_pmng_get_app_handle();	
	VMINT grp_id;

    if ((phandle = vm_res_get_process_handle(VM_RES_TYPE_COMMON_UI, common_ui_id)) < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CANCEL_GET_PRO_FAIL, common_ui_id); 
        return VM_COMMON_UI_ERROR_INVALID_ID;
    }
	
    if (curr_phandle > 0)   /* app, not engine */
    {
        if (phandle != curr_phandle)    /* application A can not cancel alarm belongs to application B */
		{
            MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CANCEL_FROM_OTHER_PROCESS, phandle, curr_phandle); 
            return VM_COMMON_UI_ERROR_OF_PROCESS;
        }
    }

    if (vm_res_get_data(VM_RES_TYPE_COMMON_UI, common_ui_id, (void **)&res_p, &res_node_size) < VM_RES_OK)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_CANCEL_GET_RES_FAIL, common_ui_id); 
		return VM_COMMON_UI_ERROR;
	}

	grp_id = res_p->grp_id;

    vm_nmgr_confirm_popup_cancel(grp_id);

    return VM_COMMON_UI_OK;	
}

static void vm_common_ui_mibr_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
 	VMINT i;
	
 	switch(sys_state)
 	{
 		case VM_PMNG_UNLOAD:
			if (vm_pmng_get_app_handle() == process_handle)
			{			
				while ((i = vm_res_findfirst(process_handle, VM_RES_TYPE_COMMON_UI)) != VM_RES_NOT_FIND)
					{
						MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_MIBR_CB_CANCEL , i);
						vm_common_ui_cancel(i);
						vm_res_findclose(VM_RES_TYPE_COMMON_UI);
					}				
			}
     		break;
		default:
			return;
	}
}

static void vm_common_ui_initial(void)
{
	vm_res_type_set_notify_callback(VM_RES_TYPE_COMMON_UI, vm_common_ui_mibr_notify_callback);
}

static void vm_common_ui_finialize(void)
{
    VMINT i = VM_RES_NOT_FIND;

    while ((i = vm_res_findfirst(-1, VM_RES_TYPE_COMMON_UI)) != VM_RES_NOT_FIND)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_FINIALIZE_CANCEL , i);
        vm_common_ui_cancel(i);
        vm_res_findclose(VM_RES_TYPE_COMMON_UI);
    }

	vm_res_type_set_notify_callback(VM_RES_TYPE_COMMON_UI, NULL);
}

static VMINT vm_common_ui_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case EVT_MOD_INIT:
            vm_common_ui_initial();
            break;
        case EVT_MOD_RELEASE:
            vm_common_ui_finialize();
            break;
    }
    return 0;
}

VMINT _vm_reg_common_ui_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int res = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((res = _vm_reg_module("SUI", (MOD_EVT_PROCESS) vm_common_ui_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_COMMONUI, TRC_MRE_COMMON_UI_REG_FAIL , res);
    }
    return res;
}


#endif /* __MRE_CORE_BASE__ */


