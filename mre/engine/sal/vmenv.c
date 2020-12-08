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
*  
*
* Project:
* --------
*  MAUI
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "vmswitch.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "GlobalConstants.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "Conversions.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_rp_app_mre_def.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_am_def.h"
#endif
#include "app_mem.h"
#include "fs_type.h"
#include "fs_func.h"
#include "CommonScreens.h"
#include "DevConfigDef.h"
#include "DevConfigGprot.h"
#include "AMGprot.h"
#include "FileMgrSrvGProt.h"
#include "MRESrvGProt.h"
#include "kal_public_api.h"

#include "vmsys.h"
#include "vmloader.h"
#include "vmchset.h"
#include "vmio.h"
#include "vmstdlib.h"
#include "vmgraph.h"
#include "vmres.h"
#include "vmnvram.h"
#include "vmgettag.h"
#include "vmcert.h"
#include "vmmem.h"
#include "vmopt.h"
#include "vmgfxold.h"
#include "vmvip.h"
#include "vmmd5.h"
#include "vmrsa.h"
#include "vmenv.h"
#include "vmtimer.h"
#include "vmnvramadapter.h"

#include "vmenv.h"
#include "vmproevt.h"
#include "vmpromng.h"

#include "vmmacrostub.h"
#include "MREAppMgrSrvGprot.h"

//#define __MMI_MRE_SWLA_DEBUG__

#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MMI_MRE_SWLA_DEBUG__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
#define MRE_SWLA_START(_symbol_)
#define MRE_SWLA_STOP(_symbol_)
#endif


/************************************************************
* 
* 全局函数声明。
*
************************************************************/
#ifdef __COSMOS_MMI_PACKAGE__
extern void vapp_mre_app_launch_by_path(WCHAR* appPath);
extern void vapp_mre_app_install(WCHAR* appPath);
extern void vapp_mre_vso_install(WCHAR *filepath);

#endif
extern VMINT vm_start_mre_envirment(vm_mre_evt_cb_t vam_cb, VMINT state);
extern void vm_stop_mre_envirment(void);
extern VMINT vm_start_mre_app(VMWSTR fileName, vm_mre_app_evt_cb_t vam_cb);
extern VM_P_HANDLE vm_pmng_set_fg(VMWSTR fileName);

/*
#if defined(__USB_IN_NORMAL_MODE__)
extern kal_bool mmi_usb_is_in_mass_storage_mode(void);
extern void mmi_usb_app_unavailable_popup(U16 stringId);
#endif
*/

extern VMUINT vm_init_default_game(VMUINT* appcount, VMUINT* smcount, VMUINT* socount);
extern VMUINT8* mre_buildin_app_array[];


extern VMINT mre_running;
extern VMUINT8* app_mem_base;

void * am_mem_ptr = NULL;
void* parameter_of_start = NULL;
VMBOOL is_can_del_parameter_of_start = MMI_TRUE;



/*************************************************************************
 *
 * vmenv.c需要实现的函数。
 *
 *************************************************************************/
static VMINT vam_state = VAM_OUT_OF_USE;

static VMINT mre_version[]= {
#include "vmversion.h"
};

static VMINT parent_handle = 0;
VMINT g_start_app_flag = 0;
VMWSTR g_parent_path = NULL;
/*****************************************************************************
 * FUNCTION
 *  vm_start_app
 * DESCRIPTION
 *  Call MRE engine to start another application
 * PARAMETERS
 *  filepath: filepath to start
 * RETURNS
 *  void
 *****************************************************************************/
void vm_start_app(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT flag)
{
    VMWCHAR filename[MAX_APP_NAME_LEN + 1];
    
    parent_handle = parent_app_handle;
    g_start_app_flag = flag;

    if (VM_START_APP_RESTART_PARENT & flag)
    {
        vm_get_exec_filename(filename);
        g_parent_path = (VMWSTR)_vm_kernel_malloc(MAX_APP_NAME_LEN + 1);
        if (g_parent_path)
        {
            memcpy(g_parent_path,filename,MAX_APP_NAME_LEN + 1);
        }
    }

    if (VM_START_APP_INSTALL & flag)
    {
        if (!srv_mre_appmgr_is_app_installed_by_path((U16 *)filepath))
        {
            srv_mre_appmgr_install_app((U16 *)filepath, SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL, NULL);
        }
    }
    
#ifdef __COSMOS_MMI_PACKAGE__
    if (VM_START_APP_NO_SELECT_POPUP &  flag)
    {
        vapp_mre_app_launch_by_path((WCHAR *)filepath);
    }
    else
    {
        vapp_mre_app_install((WCHAR *)filepath);
    }
#else
    mmi_am_launch_app_by_path((U16*)filepath);
#endif

    if (VM_START_APP_EXIT_PARENT & flag || VM_START_APP_RESTART_PARENT & flag)
    {
        vm_pmng_delete_process(parent_app_handle);
    }    
}

void vm_start_app_with_para(const VMWCHAR* filepath, VMINT parent_app_handle, VMINT is_parent_exit,void* parameter,VMINT parameter_size)
{
/* setup parameter  */

	if((0 != parameter_size) && (NULL != parameter))// parameter check 
	{
		if(MMI_TRUE == is_can_del_parameter_of_start)// can be free
		{
			// if can free we will free the memory which use previous time.
			_vm_kernel_free(parameter_of_start); 
			parameter_of_start = NULL;
			
			// alloc a mew memory block
			parameter_of_start = (void*)_vm_kernel_malloc(parameter_size);
			if(NULL == parameter_of_start)
            {
				ASSERT(0);
            }
			memset(parameter_of_start,0,parameter_size);
			memcpy(parameter_of_start,parameter,parameter_size);
		}
	}
	vm_start_app(filepath,parent_app_handle,is_parent_exit);
}

void vm_start_parent()
{
    if (g_parent_path)
    {
        VMINT exec_ret;
        
        if (!mre_running)
        {
            vm_start_mre_envirment(NULL,0);
        }
        
        exec_ret = vm_execute(g_parent_path,NULL);
        
        MMI_PRINT(MOD_MRE,MMI_MRE_TRC_G8_PRO,"[MRE][PRO]VM_MSG_RESTART_PARENT path=%s,ret=%d", 
            g_parent_path, exec_ret);
            
        _vm_kernel_free((void*)g_parent_path);
        g_parent_path = NULL;
    }
    
}

VMINT vm_get_and_reset_parent_app(void)
{
    VMINT handle = parent_handle;
    parent_handle = 0;
    return handle;
}

void vm_vam_set_vam_state(VMINT state)
{
	vam_state = state;
}

VMINT vm_vam_is_in_use(void)
{
	if (vam_state == VAM_IN_USE)
		return TRUE;
	return FALSE;
}

void vm_vam_unload_core_by_asm(void)
{
	if (vm_pmng_current_counter() <= 0)
		vm_stop_mre_envirment();
}

void vm_exit(void) 
{
	vm_exit_ex(0);	
}

void vm_exit_ex(VMINT param) 
{
	if (!mre_running)
	{
		return;
	}
	
	vm_stop_mre_envirment_ex(param);	
}

void vm_exit_by_asm(void)
{
	extern vm_mre_evt_cb_t vam_callback;

	if (!mre_running)
	{
		applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_MRE_CORE, KAL_TRUE);
		return;
	}

	if (vam_state == VAM_IN_USE)
	{
		if (vam_callback != NULL)
		{
			vm_log_debug("ASM callback to AM callback.");
			vam_callback(MRE_EVT_QUIT);
		}
		vam_state = VAM_OUT_OF_USE;
	}

	vm_stop_mre_envirment();

	applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_MRE_CORE, KAL_TRUE);
}

typedef VMINT (*launch_func)(VMINT,vm_mre_app_evt_cb_t);
static VMINT vm_execute_int(VMWSTR filename, 
                            VMUINT version,
                            VMINT (*launch_func)(VMINT,vm_mre_app_evt_cb_t),
                            VMINT param,
                vm_mre_app_evt_cb_t vam_cb)
{
    VMINT i;
	VMINT ret = VM_EXECUTE_APP_SUCCESS;

    if (vm_vam_app_is_running(filename) > 0)
    {
        if (vm_pmng_set_fg(filename) >= 0)
        {
            return VM_EXECUTE_APP_SUCCESS;
        }
        else
        {
            return VM_EXECUTE_INTERNAL_ERROR;
        }
    }

    if (version != 0)
	{
	    version = version >> 16;
	    for (i = 0; i < sizeof(mre_version)/sizeof(VMINT); i++)
	    {
	        if ((VMINT)(version/100) == (VMINT)(mre_version[i]/100))
	        {
	            //branch match!
	            if (version%100 > mre_version[i]%100)
	            {
	                return VM_EXECUTE_VERSION_NOT_MATCH;
	            }
	        }
	    }          
	}

	if ((ret = (*launch_func)(param, vam_cb)) >= 0)
	{
		return VM_EXECUTE_APP_SUCCESS;
	}
	else
	{
		vm_log_error("Failed create preload process, ret = %d", ret);
	
		switch (ret)
		{
		case VM_PMNG_ERROR_PARAM:
		case VM_PMNG_ERROR_IO:
			return VM_EXECUTE_APP_ILLEGAL;
		case VM_PMNG_NO_SCHEDULE:
			return VM_EXECUTE_INTERNAL_ERROR;
		case VM_PMNG_NO_MEM:
			return VM_EXECUTE_APP_NOT_ENOUGH_MEMORY;
		case VM_PMNG_SEC_TAG_PLATFORM_PARAM_DISMATCH:
			return VM_EXECUTE_PLATFORM_PARAM_DISMATCH;
		case VM_PMNG_SEC_APP_TIMESTAMP_ERROR:
			return VM_EXECUTE_TIMESTAMP_ERROR;
		case VM_PMNG_SEC_IMSI_DISMATCH:
			return VM_EXECUTE_IMSI_DISMATCH;
		case VM_PMNG_SEC_BAN_LIST_APP:
			return VM_EXECUTE_BANNED_APP;
		case VM_PMNG_SEC_INVALIDATE_APP:
			return VM_EXECUTE_APP_ILLEGAL;
		case VM_PMNG_SEC_CERT_OMREDUE:
			return VM_EXECUTE_CERT_OVERDUE;
        case VM_PMNG_WAIT_ASM:
            return VM_EXECUTE_SYS_ASYN_ASM;
        case VM_PMNG_NOT_SUPPORT_VP:
            return VM_EXECUTE_SYS_NOT_SUPPORT_VP;
        case VM_PMNG_ONLY_ONE_FOREGROUND:
            return VM_EXECUTE_ONLY_ONE_FOREGROUND;
        case VM_PMNG_MAX_APP_NUM_REACHED:
            return VM_EXECUTE_MAX_APP_NUM_REACHED;
		default:
			return VM_EXECUTE_INTERNAL_ERROR;
		}
	}
}

VMINT vm_execute(VMWSTR filename, vm_mre_app_evt_cb_t vam_cb)
{
	VMINT ret = VM_EXECUTE_APP_SUCCESS;
	VMINT bufSize = 4;
    VMUINT version = 0;
    VMWCHAR new_filename[MAX_APP_NAME_LEN+10];

	if (vm_update_check_launch(filename, new_filename))
	{
	    filename = (VMWSTR)new_filename;
	}
      
    vm_get_vm_tag(filename, VM_CE_INFO_PLAT_REQ, &version, &bufSize);

    return vm_execute_int(filename,version,vm_start_mre_app,(VMINT)filename,vam_cb);
}

extern VMINT vm_start_mre_preload_app(vm_preload_app_info_t *preload_info, vm_mre_app_evt_cb_t vam_cb);

VMINT vm_execute_preload_app(vm_preload_app_info_t *preload_info, vm_mre_app_evt_cb_t vam_cb)
{
	return vm_execute_int(preload_info->fullFileName,preload_info->version,vm_start_mre_preload_app,(VMINT)preload_info,vam_cb);
}

void* vm_vam_malloc(VMINT size)
{
	if (size == sysconf.am_memory_size)
	{
		return am_mem_ptr;
	}
	else
	{
		return NULL;
	}
	//return _vm_kernel_malloc(size);
}

void vm_vam_free(void* p)
{
	//_vm_kernel_free(p);
}

#ifdef __MMI_USB_SUPPORT__
mmi_ret mmi_mre_enter_usb_mode(mmi_event_struct* evt)
{
	if (stub_mmi_usb_is_in_mass_storage_mode())
	{
	    vm_get_tag_deinit(0);
		vm_exit_ex(VM_QUIT_MASS_STORAGE);
	}
	return MMI_RET_OK;
}
#else
mmi_ret mmi_mre_enter_usb_mode(mmi_event_struct* evt)
{
        return MMI_RET_OK;
}
#endif    //__MMI_USB_SUPPORT__


void mmi_mre_card_plug_out_hdlr(void)
{
	if (vm_pmng_deal_card_plug_out_event(NULL) == 0 
		&& vam_state != VAM_IN_USE)
	{
		vm_exit();
	}
}

mmi_ret mmi_mre_fmgr_notify_hdlr(mmi_event_struct* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_fmgr_notification_format_event_struct *format_evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(param->evt_id)
	{
        case EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT:
        	format_evt = (srv_fmgr_notification_format_event_struct*)param;
        	if( mmi_mre_pre_format_hdlr(format_evt->drv_letter) == 0 )
        	{
        		return MMI_RET_ERR;
        	}
        	break;
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        	mmi_mre_card_plug_out_hdlr();
        	break;
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN: 
        	break;
        default: break;
	}
	return MMI_RET_OK;
}

#ifndef __MMI_MRE_DISABLE_FMGR__
void mmi_fmgr_vxp_option_hdlr(mmi_menu_id item_id, const WCHAR* filepath, const srv_fmgr_fileinfo_struct* fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 type = -1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (0 == mmi_ucs2icmp((CHAR*)(filepath + kal_wstrlen(filepath)-4), (CHAR*)L".vxp"))
    {
        type = 0;
    }
    else
    {
        type = 1;
    }
    
    switch (item_id)
    {
        case MENU_ID_FMGR_MRE_FILE_OPEN:
#ifdef __COSMOS_MMI_PACKAGE__
            if (0 == type)
            {
            srv_mre_appmgr_launch_by_filepath((U16 *)filepath);
            }
            else if (1 == type)
            {
				S32 app_type;
				app_type = srv_mre_appmgr_get_file_type((U16 *)filepath);
				switch(app_type)
				{
					case SRV_MRE_APPMGR_APP_TYPE_WIDGET:
						#if !defined(__MMI_VUI_WIDGET_MRE__)
						return;
						#endif
						break;
					case SRV_MRE_APPMGR_APP_TYPE_WALLPAPER:
						#if !defined(__MMI_VUI_WALLPAPER_MRE__)
						return;
						#endif
						break;
					case SRV_MRE_APPMGR_APP_TYPE_LAUNCHER:
						#if !defined(__MMI_VUI_LAUNCHER_MRE__)
						return;
						#endif
						break;
					case SRV_MRE_APPMGR_APP_TYPE_SCRLOCK:
						#if !defined(__MMI_VUI_SCREEN_LOCK_MRE__)
						return;
						#endif
						break;
					default:break;
				}
                vapp_mre_vso_install((WCHAR* )filepath);
            }
#else
            //mmi_am_start_from_fm((U16 *)filepath);
          // 
#if ((defined(__PLUTO_MMI_PACKAGE__))&&(!defined(__MMI_FTE_SUPPORT__))&&!defined(__MMI_MRE_MAIN_MENU__)&& !defined(__MMI_MRE_SUB_MENU__)&& !defined(__MMI_MAINMENU_SPREAD_SUPPORT__))
			mmi_am_launch_app_by_path((U16 *)filepath);  //only pluto mmi with slim or normal mre package without mmi mainmenu spread can have open.
#endif

#endif 
			break;
//#ifdef __MMI_APP_MANAGER_SUPPORT__
		case MENU_ID_FMGR_MRE_OPTION_INSTALL:
#if ((defined(__PLUTO_MMI_PACKAGE__))&&(!defined(__MMI_FTE_SUPPORT__))&&!defined(__MMI_MRE_MAIN_MENU__)&& !defined(__MMI_MRE_SUB_MENU__)&& !defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) // here no need to install
			{
				//in pluto mmi with mre slim(normal)package without mainmeun spread,should not install app
			}
#else
		{
			MMI_BOOL ret = MMI_FALSE;
			{
				ret = srv_mre_appmgr_is_able_to_install((U16 *)filepath);
		    if(ret == MMI_FALSE)
				{
		    		MMI_ID parent_gid;
						mmi_popup_property_struct arg;   
						parent_gid = GRP_ID_ROOT;
						mmi_popup_property_init(&arg);              
						arg.callback = NULL;       
						arg.user_tag = NULL;          
						arg.parent_id = parent_gid; 
						arg.rotation = MMI_FRM_SCREEN_ROTATE_0;
						mmi_popup_display((WCHAR*)GetString(STR_MRE_REACH_MAX_NUM),MMI_EVENT_FAILURE,&arg);  
						return ;
				 }
			}
			#if defined(__MRE_APP_LAUNCH__)&& !defined(__COSMOS_MMI_PACKAGE__)
			if(mmi_am_install_app_check_popup((U16 *)filepath))
	        {
	     #endif
			ret = srv_mre_appmgr_install_app((U16 *)filepath,SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL,NULL);
			if(MMI_TRUE == ret)
			{
				// install success popup
			    MMI_ID parent_gid;
			    mmi_popup_property_struct arg;   
			    parent_gid = GRP_ID_ROOT;
			    mmi_popup_property_init(&arg);              
			    arg.callback = NULL;       
			    arg.user_tag = NULL;          
			    arg.parent_id = parent_gid; 
			    arg.rotation = MMI_FRM_SCREEN_ROTATE_0;
			    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE),MMI_EVENT_SUCCESS,&arg);  
				return ;
			}
			else
			{
				// install unsuccess popup
				MMI_ID parent_gid;
			    mmi_popup_property_struct arg;   
			    parent_gid = GRP_ID_ROOT;
			    mmi_popup_property_init(&arg);              
			    arg.callback = NULL;       
			    arg.user_tag = NULL;          
			    arg.parent_id = parent_gid; 
			    arg.rotation = MMI_FRM_SCREEN_ROTATE_0;
			    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_FAILED),MMI_EVENT_FAILURE,&arg);  
				return ;
			}
		#if defined(__MRE_APP_LAUNCH__)&& !defined(__COSMOS_MMI_PACKAGE__)	
			}
			else
			{
				return ;
		    }
		#endif //#if defined(__MRE_APP_LAUNCH__)&& !defined(__COSMOS_MMI_PACKAGE__)	
		}
#endif  //
			break;
//#endif			
        default:
            break;
    }
}
#endif

void mmi_fmgr_vxp_option_enabler(
                    mmi_menu_id item_id,
                    const WCHAR *filepath,
                    const srv_fmgr_fileinfo_struct *fileinfo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//#ifdef __MMI_APP_MANAGER_SUPPORT__
#ifndef __MMI_MRE_DISABLE_FMGR__
   U16 appname[MMI_APP_NAME_MAX_LEN];
   mmi_app_package_char appcharname[MMI_APP_NAME_MAX_LEN];
   S32 app_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   switch(item_id)
   {
	   case MENU_ID_FMGR_MRE_OPTION_INSTALL:
			srv_mre_appmgr_generate_identification((U16 *)filepath, appname);
			mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8 , (char *)appname, (char *)appcharname, MMI_APP_NAME_MAX_LEN);
			if (MMI_TRUE == srv_mre_appmgr_is_app_installed((mmi_app_package_char *)appcharname))
			{
				/*hide install item when vxp has installed.*/
				mmi_frm_hide_menu_item(item_id);
				return;
			}
			#if ((defined(__PLUTO_MMI_PACKAGE__))&&(!defined(__MMI_FTE_SUPPORT__))&&!defined(__MMI_MRE_MAIN_MENU__)&&!defined(__MMI_MRE_SUB_MENU__)&& !defined(__MMI_MAINMENU_SPREAD_SUPPORT__)) 
			mmi_frm_hide_menu_item(item_id);
			return;
			#endif
			app_type = srv_mre_appmgr_get_file_type((U16 *)filepath);
            switch(app_type)
			{
				case SRV_MRE_APPMGR_APP_TYPE_WIDGET:
					#if !defined(__MMI_VUI_WIDGET_MRE__)
					mmi_frm_hide_menu_item(item_id);
					#endif
					break;
				case SRV_MRE_APPMGR_APP_TYPE_WALLPAPER:
					#if !defined(__MMI_VUI_WALLPAPER_MRE__)
					mmi_frm_hide_menu_item(item_id);
					#endif
					break;
				case SRV_MRE_APPMGR_APP_TYPE_LAUNCHER:
					#if !defined(__MMI_VUI_LAUNCHER_MRE__)
					mmi_frm_hide_menu_item(item_id);
					#endif
					break;
				case SRV_MRE_APPMGR_APP_TYPE_SCRLOCK:
					#if !defined(__MMI_VUI_SCREEN_LOCK_MRE__)
					mmi_frm_hide_menu_item(item_id);
					#endif
					break;
				default:break;
		    }
			return;
			break;
			case MENU_ID_FMGR_MRE_FILE_OPEN:
				#if ((defined(__PLUTO_MMI_PACKAGE__))&&(!defined(__MMI_FTE_SUPPORT__))&&!defined(__MMI_MRE_MAIN_MENU__)&&!defined(__MMI_MRE_SUB_MENU__)&& !defined(__MMI_MAINMENU_SPREAD_SUPPORT__))||defined(__COSMOS_MMI_PACKAGE__)
				{}
				#else
				mmi_frm_hide_menu_item(item_id);
				return;
				#endif
				break;
	   default:break;
   }
//#endif
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_am_is_using_media_memory
 * DESCRIPTION
 *  Check if MRE using media buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  MRE is using media memory or not
 *****************************************************************************/
S32 mmi_am_is_using_media_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (S32)srv_mre_is_using_media_buffer();
}


#ifndef __COSMOS_MMI_PACKAGE__
/*****************************************************************************
 * FUNCTION
 *  mmi_am_get_error_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  error_result        [IN]        
 *  popup_type          [IN]        
 * RETURNS
 *  MRE running string id
 *****************************************************************************/
MMI_STR_ID mmi_am_get_error_info(S32 error_result, S32 *popup_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (error_result == MMI_MRE_ERR_IS_UNAVAILABLE)
    {
#ifndef __MMI_MRE_DISABLE_FMGR__
        return STR_ID_AM_MEDIA_MEMORY_UNAVAIBLE;
#else
        return 0;
#endif
    }
    else
    {
        return 0;
    }
}
#endif

VMINT vm_vam_get_string_data(VMUINT8* gifzm, VMUINT8** data_buf, LANGUAGE_TYPE lan, VMINT* data_len, VMINT* font, VMINT * data_size)
{
	VMINT icon_dat_sz, zm_dat_sz;
	VMINT offset = 13;
	VMINT language = ENG;
	
	if (gifzm == NULL)
		return -1;
	
	icon_dat_sz = *(gifzm + offset + 6) +
		((*(gifzm + offset + 7)) << 8) +
		((*(gifzm + offset + 8)) << 16) +
		((*(gifzm + offset + 9)) << 24);
	
	offset = 23 + icon_dat_sz;	//start addr of matrix
	
	//jump to the addr of specified language matrix
	while (language < lan)
	{
		zm_dat_sz = *(gifzm + offset + 8) +
			((*(gifzm + offset + 9)) << 8) +
			((*(gifzm + offset + 10)) << 16) +
			((*(gifzm + offset + 11)) << 24);
		offset += (12 + zm_dat_sz);
		language++;
	}
	
	//get info
	*data_len = *(gifzm + offset + 5)
		+ ((*(gifzm + offset + 6)) << 8);
	*font = *(gifzm + offset+ 7);
	
	zm_dat_sz = *(gifzm + offset + 8) +
		((*(gifzm + offset + 9)) << 8) +
		((*(gifzm + offset + 10)) << 16) +
		((*(gifzm + offset + 11)) << 24);
	
	if (zm_dat_sz <= 0)
		return -1;

	*data_size = zm_dat_sz;
	
	*data_buf = (VMUINT8 *)(gifzm + offset + 12);
	return 0;
}

VMINT vm_vam_measure_zimo_string(VMUINT8 *zimo_buf, VMINT str_len)
{
	VMINT i;
	VMINT offset = 0 ;
	VMINT flag;
	VMINT offset_ch;
	VMINT nTempWidth = 0;
	
	for (i = 0; i < str_len; i++) 
	{
		flag = *(zimo_buf+offset);
		offset_ch = *( zimo_buf+offset+1);
		
		if (flag == 2)
		{
			//nTempWidth +=  7 + 1;//7 代表ASC的实际宽度  + 1代表每个字之间的空格
			nTempWidth +=  7;	//14号字体不需加空格	-linminqi 2010-2-8
		}
		else 
		{
			//nTempWidth += 14 + 1;//14 代表HZ的实际宽度  + 1代表每个字之间的空格
			nTempWidth += 14;	//14号字体不需加空格	-linminqi 2010-2-8
		}
		offset += offset_ch + 2;
	}
	return nTempWidth - 1; //nTempWidth整个字符创都进行加1之后的宽度，但最后一个字符宽度不需要再加1，所以此处-1处理

}


//rencai.xiao 2010/03/01
VMINT vm_vam_get_user_balance(VMUINT* user_balance)
{
    return 0;
}


void vm_get_buildin_app_array(VMINT** app_array_ptr, VMINT* app_array_len_ptr)
{
#ifdef WIN32
	*app_array_ptr = NULL;
	*app_array_len_ptr = 0;
#else
	VMUINT appcount,smcount,socount;
	
	vm_init_default_game(&appcount, &smcount, &socount);

	vm_log_debug("vm_get_buildin_app_array game size = %d", appcount);

	
	if ( appcount > 0 )
	{
		*app_array_ptr = (VMINT*)mre_buildin_app_array;
		*app_array_len_ptr = appcount;
	}
	else
	{
		*app_array_ptr = NULL;
		*app_array_len_ptr = 0;
	}
#endif

}

/*****************************************************************************
 * FUNCTION
 *  vm_vam_get_core_asm_size
 * DESCRIPTION
 *  Get the ASM size of MRE core by byte.
 * RETURNS
 *  ASM size of MRE core by byte.
 *****************************************************************************/
VMUINT vm_vam_get_core_asm_size(void)
{
    return MRE_SYS_ASM_CORE_MEMPOOL_SIZE;
}


/*extern VMUINT8 vm_init_default_game(void);
extern VMUINT8 g_mre_default_game_size;
extern VMUINT8** mre_buildin_app_array;

void vm_get_buildin_app_array(VMINT** app_array_ptr, VMINT* app_array_len_ptr)
{
#ifdef WIN32
	*app_array_ptr = NULL;
	*app_array_len_ptr = 0;
#else
	vm_init_default_game();
	
	if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_MEDIA)
	{
		*app_array_ptr = NULL;
		*app_array_len_ptr = 0;
	}
	else
	{
		*app_array_ptr = (VMINT*)mre_buildin_app_array;
		*app_array_len_ptr = g_mre_default_game_size;
		vm_log_fatal("g_mre_default_game_size = %d",g_mre_default_game_size);
	}
}	
#endif*/

/**
#if (!defined(__MRE_MEDIA_BUF__) && !defined(WIN32))
	*app_array_ptr = (VMINT*)mre_buildin_app_array;
	*app_array_len_ptr = MRE_BUILDIN_APP_COUNT;
#else
	*app_array_ptr = NULL;
	*app_array_len_ptr = 0;
#endif
*
}*/	



