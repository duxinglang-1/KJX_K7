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
 *   gs_srv_appmgr.cpp
 *
 * Project:
 * -------- 
 *   MAUI
 *
 * Description:
 * ------------
 *   IAppmgr implement file
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 
#include "mmi_include.h"
#include "vmresmng.h"
#include "AppMgrSrvGprot.h"
#ifdef __cplusplus
}
#endif 

#include "gs_srv_appmgr_impl.h"

//static functions

typedef struct
{
    VM_P_HANDLE                 pHandle;
    void*                       callback;
    void*                       user_data;
}gs_cb_data;

void AppmgrService::uninstall_cb(srv_appmgr_cb_event_enum result, void* user_data)
{
    gs_cb_data* data = (gs_cb_data*)user_data;
    gs_appmgr_uninstall_cb_fct callback = (gs_appmgr_uninstall_cb_fct)data->callback;
    
    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(data->pHandle) && data->callback)
    {
        callback((gs_appmgr_uninstall_cb_enum)result,data->user_data);
        vm_free(data);
        vm_pmng_reset_ctx();
    }
}

gs_appmgr_cb_event_enum AppmgrService::transEvent(U16 event_id)
{
    switch (event_id)
    {
    case EVT_ID_SRV_APPMGR_INSTALL_PACKAGE:
        return GS_APPMGR_CB_EVENT_INSTALL_PACKAGE;
    case EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE:
        return GS_APPMGR_CB_EVENT_UPDATE_PACKAGE;
    case EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE:
        return GS_APPMGR_CB_EVENT_UNINSTALL_PACKAGE;
    case EVT_ID_SRV_APPMGR_UPDATE_BADGE:
        return GS_APPMGR_CB_EVENT_UPDATE_BADGE;
    case EVT_ID_SRV_APPMGR_INSTALL_START:
        return GS_APPMGR_CB_EVENT_INSTALL_START;
    case EVT_ID_SRV_APPMGR_INSTALL_PROGRESS:
        return GS_APPMGR_CB_EVENT_INSTALL_PROGRESS;
    case EVT_ID_SRV_APPMGR_INSTALL_FINISH:
        return GS_APPMGR_CB_EVENT_INSTALL_FINISH;
    case EVT_ID_SRV_APPMGR_INSTALL_ERROR:
        return GS_APPMGR_CB_EVENT_INSTALL_ERROR;
    }
    return GS_APPMGR_CB_EVENT_INSTALL_PACKAGE;
}

mmi_ret AppmgrService::appmgr_event_hdlr(mmi_event_struct *param)
{
    mmi_ret ret = MMI_RET_OK;
    void* user_data = NULL;
    gs_appmgr_event_cb_fct callback = NULL;
    VMINT res_handle;
    VMINT size;
    srv_appmgr_update_event_struct *evt = (srv_appmgr_update_event_struct*)param;

    res_handle = vm_res_findfirst(-1, VM_RES_TYPE_APPMGR);
    while (res_handle  != VM_RES_NOT_FIND)
	{
		vm_res_get_data( VM_RES_TYPE_APPMGR, res_handle, (void**)&user_data, &size );
	    vm_res_get_callback( VM_RES_TYPE_APPMGR, res_handle, (void**)&callback );
	    
	    if (VM_PMNG_OP_OK == vm_pmng_set_ctx(vm_res_get_process_handle(VM_RES_TYPE_APPMGR, res_handle)) && callback)
        {
            callback(transEvent(param->evt_id), (void*)evt->app_name, strlen(evt->app_name)+1, user_data);
            vm_pmng_reset_ctx(); 
        }

        callback = NULL;
		res_handle = vm_res_findnext(-1, VM_RES_TYPE_APPMGR);
	}
	vm_res_findclose(VM_RES_TYPE_APPMGR);
    return MMI_RET_OK;
}

void AppmgrService::unreg(VM_P_HANDLE handle)
{
    VMINT res_handle;

    while ((res_handle = vm_res_findfirst(handle, VM_RES_TYPE_APPMGR))  != VM_RES_NOT_FIND)
	{
    	vm_res_release_data(VM_RES_TYPE_APPMGR, res_handle);
	}
	vm_res_findclose(VM_RES_TYPE_APPMGR);
}

void AppmgrService::release(VM_P_HANDLE process_handle, VMINT sys_state)
{  
	if (VM_PMNG_UNLOAD == sys_state)
	{
	    unreg(process_handle);
	}		    
}

void AppmgrService::init(void)
{
    static MMI_BOOL inited = MMI_FALSE;
    if (!inited)
    {
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_PACKAGE,appmgr_event_hdlr,NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE,appmgr_event_hdlr,NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,appmgr_event_hdlr,NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE,appmgr_event_hdlr,NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_START,appmgr_event_hdlr,NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_PROGRESS,appmgr_event_hdlr,NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_FINISH,appmgr_event_hdlr,NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_INSTALL_ERROR,appmgr_event_hdlr,NULL);
        
        vm_res_type_set_notify_callback(VM_RES_TYPE_APPMGR,  (vm_res_release_callback_t)&release);
        inited = MMI_TRUE;
    }
}



//interfaces


GS_IBase *CreateAppmgrService(U32 hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    AppmgrService* service = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    AppmgrService::init();
    GS_NEW_EX(service, AppmgrService,(hd));
    return (GS_IBase*)(GS_CBase*)service;
}


S32 AppmgrService::queryInterface(S32 iid, GS_IBase **pptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Please notes: pptr may be a proxy, your call should not use it directly. */
    if (pptr == NULL)
        return 0;
    if (iid == IID_IAPPMGR)
    {
        addRef();
        *pptr = BIND_PROXY(IAppmgr, this);
        return 1;
    }
    return GS_CBase::queryInterface(iid, pptr);
}

U32 CALLCC AppmgrService::get_app_package_num(gs_appmgr_query_type_enum flag)
{
    return srv_appmgr_get_app_package_num((srv_appmgr_flag_type)flag);
}

S32 CALLCC AppmgrService::get_app_package_list(gs_appmgr_query_type_enum flag, gs_app_package_name_struct *name_array, U32 num)
{
    return srv_appmgr_get_app_package_list((srv_appmgr_flag_type)flag, (mmi_app_package_name_struct *)name_array, num);
}

S32 CALLCC AppmgrService::get_app_package_name(const CHAR* app_name, WCHAR *string)
{
    return srv_appmgr_get_app_package_name((const mmi_app_package_char *)app_name,string);
}

S32 CALLCC AppmgrService::get_app_package_image(const CHAR* app_name, gs_image_src_struct *image)
{
    mmi_ret ret;
    mmi_image_src_struct image_struct;
    
    ret = srv_appmgr_get_app_package_image((const mmi_app_package_char *)app_name, &image_struct);
    if (MMI_RET_OK == ret)
    {
        image->type = (gs_image_src_type_enum)image_struct.type;
        memcpy((void*)&image->data, (void*)&image_struct.data, sizeof(image->data));
    }
    return (S32)ret;
}

S32 CALLCC AppmgrService::get_app_package_badge(const CHAR* app_name, WCHAR *badge)
{
    mmi_ret ret;
    srv_app_info_struct info;
    ret = srv_appmgr_get_app_package_info((const mmi_app_package_char *)app_name, &info);
    if (MMI_RET_OK == ret)
    {
        memcpy((void*)badge, info.badge, sizeof(info.badge));
    }
    return (S32)ret;
}

static gs_appmgr_app_package_type_enum trans_package_type(srv_appmgr_app_package_type_enum type)
{
    switch (type)
    {
    case SRV_APPMGR_MRE_APP_PACKAGE_TYPE:
        return GS_APPMGR_MRE_APP_PACKAGE_TYPE;
    case SRV_APPMGR_NATIVE_APP_PACKAGE_TYPE:
        return GS_APPMGR_NATIVE_APP_PACKAGE_TYPE;
    case SRV_APPMGR_JAVA_APP_PACKAGE_TYPE:
        return GS_APPMGR_JAVA_APP_PACKAGE_TYPE;
#ifdef __GADGET_SUPPORT__        
    case SRV_APPMGR_WIDGET_APP_PACKAGE_TYPE:
        return GS_APPMGR_WIDGET_APP_PACKAGE_TYPE;  
#endif        
    default:
        return GS_APPMGR_UNKNOWN_APP_PACKAGE_TYPE;
    }
}

gs_appmgr_app_package_type_enum CALLCC AppmgrService::get_app_package_type(const CHAR* app_name)
{
    return trans_package_type(srv_appmgr_get_app_package_type((const mmi_app_package_char *)app_name));
}

typedef struct
{
    MMI_EVT_PARAM_HEADER
 
    mmi_app_package_name_struct app_name;
} mmi_app_launch_evt_struct;

static void post_launch_app(mmi_event_struct *param)
{
    mmi_app_launch_evt_struct *evt = (mmi_app_launch_evt_struct *)param;

    srv_appmgr_launch((const mmi_app_package_char *)evt->app_name);
}

U16 CALLCC AppmgrService::launch_app(const CHAR* app_name)
{
    mmi_app_launch_evt_struct evt;

    MMI_FRM_INIT_EVENT(&evt, 0);
    memcpy(evt.app_name, app_name, 60);

    mmi_frm_post_event((mmi_event_struct *)&evt, (mmi_proc_func)post_launch_app, NULL);

    return 0;
}
 

S32 CALLCC AppmgrService::install_app(const CHAR* file_path) /* Not support now */
{
    // TODO: to be constructed
    return 0;
}


S32 CALLCC AppmgrService::uninstall_app(const CHAR* app_name, gs_appmgr_uninstall_cb_fct cb_fct, void* user_data)
{
    gs_cb_data* data;
    
    data = (gs_cb_data*)vm_malloc(sizeof(gs_cb_data));
    if (!data)
    {
        return -2;
    }
    data->pHandle = vm_pmng_get_current_handle();
    data->callback = (void*)cb_fct;
    data->user_data = user_data;
    return (S32)srv_appmgr_uninstall_app((const mmi_app_package_char *)app_name, uninstall_cb, (void* )data);    
}

S32 CALLCC AppmgrService::reg_event_hdlr(gs_appmgr_event_cb_fct cb_fct, void* user_data)
{
    VM_P_HANDLE handle;
    
    if ( NULL == cb_fct)
    {
        return -2;
    }

    handle = vm_pmng_get_current_handle();
    if (vm_res_get_data_list_count_by_proecss(handle, VM_RES_TYPE_APPMGR) > 0)
    {
        return -5;
    }
   

    if (vm_res_save_data(VM_RES_TYPE_APPMGR, (void*)user_data, 4, (void*)cb_fct, handle) < 0)
    {
       return -4;
    }
    return 0;
}

void CALLCC AppmgrService::unreg_event_hdlr(void)
{
    VM_P_HANDLE handle = vm_pmng_get_current_handle();
    unreg(handle);
}




