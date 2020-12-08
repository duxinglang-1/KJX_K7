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
*  MRESrv.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  MRE Service implement file
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "MMIDataType.h"
#include "Unicodexdcl.h"
#include "Conversions.h"
#include "CustDataRes.h"
#include "PixcomFontEngine.h"
#include "DevConfigDef.h"
//#include "mmi_rp_app_am_def.h"  // TODO: move to a common file by Keith
#include "MRESrvGProt.h"
#include "DevConfigGprot.h"
#include "FileMgrSrvGProt.h"
#include "mmi_trc_int.h"
#include "MMI_mre_trc.h"

#include "vmswitch.h"
#include "vmsys.h"
#include "vmenv.h"      // TODO: remove this file later
#include "vmpromng.h"
#include "vmres.h"
#include "vmmullang.h"
#include "vmgettag.h"
#include "vmcerter.h"
#include "vmcert.h"
#include "vmcermng.h"
// #include "vmsysint.h"
#include "vmpromnginner.h"
#include "vmdl.h"
#include "vmappcomm.h"
#include "vmmem.h"
#include "mmi_lib_res_range_def.h"
#include "mmi_rp_app_mre_def.h"
#include "MRESrvDownloadGprot.h"
#include "devprofilegprot.h"

#include "GlobalResDef.h"
#include "mmi_frm_events_gprot.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"
#include "verno.h"
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


/***************************************************************************** 
* Define
*****************************************************************************/
#define SRV_MRE_APP_INFO_DESC L"VREDESC:"
#define SRV_MRE_APP_INFO_PHONE L"VREPHONE:"
#define SRV_MRE_APP_INFO_RANK L"VRERANK:"
#define SRV_MRE_ROM_DIR   64    /* @ */


typedef enum
{
    SRV_MRE_LAN_ENG = 0,
    SRV_MRE_LAN_CHS,
    SRV_MRE_LAN_CHT,
    SRV_MRE_LAN_END_OF_ENUM
} srv_mre_lan_type_enum;

typedef struct 
{
    U8	app_path[SRV_MRE_APPMGR_FILEPATH_LEN];
    void*  	app_cb;
}srv_mre_lan_para_type;

/***************************************************************************** 
* Extern Function
*****************************************************************************/
// TODO: move to a header file [Start]
extern VMINT vm_start_mre_envirment(vm_mre_evt_cb_t vam_cb, VMINT state);
extern VM_P_HANDLE vm_pmng_set_fg(VMWSTR fileName);
extern VM_P_HANDLE vm_pmng_get_handle(VMWSTR file_name);
extern VMUINT vm_init_default_game(VMUINT* appcount, VMUINT* smcount, VMUINT* socount);
extern void vm_pmng_set_create_app_param(VMINT param);
extern _vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);
char *release_verno();
char *build_date_time(void);
char* release_hw_ver(void); 

#ifdef __MRE_AM__
#ifndef __COSMOS_MMI_PACKAGE__
extern void mmi_am_ms_draw_cert_check_popup(void);
#endif
#endif

#ifdef __MRE_CORE_SAFETY__
extern VMINT vm_ce_auth_app_ex( VMWSTR filename, VMUCHAR * cache_buf, VMINT cache_len, VMINT mode );
#endif

// TODO: move to a header file [End]
extern VMUINT8 vm_nvram_get_firstflag(void);
extern VMINT mre_running;
extern mmi_devconfig_system_config_struct sysconf;
extern VMUINT8 *mre_buildin_app_array[];
extern void* parameter_of_start;
extern VMBOOL is_can_del_parameter_of_start;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
static srv_mre_launch_app_cb_t g_srv_mre_launch_app_cb;
static srv_mre_load_core_cb_t g_srv_mre_load_core_cb;
static srv_mre_load_core_caller_enum g_caller_flag;
srv_mre_lan_para_type			launch_para;
//according to VM_CE_VERITY_INSUFFICIENT_SYS_MEM ....
static const srv_mre_launch_app_result_enum mre_srv_verify_map[]={
    SRV_MRE_LAUNCH_APP_NOT_ENOUGH_MEMORY,
    SRV_MRE_LAUNCH_APP_CERT_OVERDUE,
    SRV_MRE_LAUNCH_APP_BAD_PARAM,
    SRV_MRE_LAUNCH_APP_INTERNAL_ERROR,
    SRV_MRE_LAUNCH_APP_INTERNAL_ERROR,
    SRV_MRE_LAUNCH_APP_INTERNAL_ERROR,
    SRV_MRE_LAUNCH_APP_PLATFORM_PARAM_DISMATCH,
    SRV_MRE_LAUNCH_APP_NOT_ENOUGH_MEMORY,
    SRV_MRE_LAUNCH_APP_FORCE,
    SRV_MRE_LAUNCH_APP_FORCE,
    SRV_MRE_LAUNCH_APP_FORCE,
    SRV_MRE_LAUNCH_APP_FORCE,
    SRV_MRE_LAUNCH_APP_FORCE,
    SRV_MRE_LAUNCH_APP_BAD_PARAM,
    SRV_MRE_LAUNCH_APP_FORCE,
    SRV_MRE_LAUNCH_APP_SUCCESS
};
//according to VM_EXECUTE_APP_SUCCESS.....
static const srv_mre_launch_app_result_enum mre_srv_execute_verify_map[]={
    SRV_MRE_LAUNCH_VERSION_NOT_MATCH,
    SRV_MRE_LAUNCH_APP_MAX_NUM,
    SRV_MRE_LAUNCH_APP_ONLY_ONE_FOREGROUND,
    SRV_MRE_LAUNCH_APP_ILLEGAL,
    SRV_MRE_LAUNCH_APP_SYS_ASYN_ASM,
    SRV_MRE_LAUNCH_APP_ILLEGAL,
    SRV_MRE_LAUNCH_APP_EXCEED_FILE_IN_MRE_DIRECTORY,
    SRV_MRE_LAUNCH_APP_CERT_OVERDUE,
    SRV_MRE_LAUNCH_APP_IMSI_DISMATCH,
    SRV_MRE_LAUNCH_APP_BANNED_APP,
    SRV_MRE_LAUNCH_APP_TIMESTAMP_ERROR,
    SRV_MRE_LAUNCH_APP_PLATFORM_PARAM_DISMATCH,
    SRV_MRE_LAUNCH_APP_INTERNAL_ERROR,
    SRV_MRE_LAUNCH_APP_CALL_STACK_FULL,
    SRV_MRE_LAUNCH_APP_NOT_ENOUGH_MEMORY,
    SRV_MRE_LAUNCH_APP_ILLEGAL,
    SRV_MRE_LAUNCH_APP_SUCCESS
};

srv_mre_launch_app_result_enum srv_mre_launch_app_ex(U16 *app_path, srv_mre_launch_app_cb_t app_cb);
/*****************************************************************************
* FUNCTION
*  srv_mre_is_core_loaded
* DESCRIPTION
*  Check if MRE Core is loaded.
* PARAMETERS
*  void
* RETURN VALUES
*  MMI_TRUE : If loaded.
*  MMI_FALSE : If not loaded.
*****************************************************************************/
MMI_BOOL srv_mre_is_core_loaded(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mre_running == TRUE)
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
*  srv_mre_load_core_cb
* DESCRIPTION
*  
* PARAMETERS
*  evt     [IN]        
* RETURNS
*  void
*****************************************************************************/
static void srv_mre_load_core_cb(VAM_START_MRE_EVT evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ( NULL != g_srv_mre_load_core_cb) //MAUI_03033901
    {
        switch (evt)
        {
        case MRE_EVT_START_SUCCESS:
            g_srv_mre_load_core_cb(SRV_MRE_LOAD_CORE_EVT_SUCCESS);
            break;

        case MRE_EVT_START_INTERNEL_ERROR:
            g_srv_mre_load_core_cb(SRV_MRE_LOAD_CORE_EVT_INTERNAL_ERROR);
            break;

        case MRE_EVT_QUIT:
            g_srv_mre_load_core_cb(SRV_MRE_LOAD_CORE_EVT_QUIT);
            break;

        default:
            break;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  srv_mre_load_core
* DESCRIPTION
*  Load MRE Core.
* PARAMETERS
*  load_cb : [IN]  Callback function.
*  caller : [IN] Type of load MRE core.
* RETURN VALUES
*  TODO:
*****************************************************************************/
srv_mre_load_core_result_enum srv_mre_load_core(srv_mre_load_core_cb_t load_cb, srv_mre_load_core_caller_enum caller)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_mre_load_core_result_enum load_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_mre_load_core_cb = load_cb;

    if (caller == SRV_MRE_CALLER_SERVICE)
    {
        ret = vm_start_mre_envirment(NULL, 0);
    }
    else if (caller == SRV_MRE_CALLER_AM || caller == SRV_MRE_CALLER_DOWNLOAD)
    {
        ret = vm_start_mre_envirment(srv_mre_load_core_cb, 0);
    }
    else
    {
        ret = VM_VLC_INTERNEL_ERROR;
    }

    switch (ret)
    {
    case VM_VLC_START_SUCCESS:
        load_ret = SRV_MRE_LOAD_CORE_SUCCESS;
        if (caller == SRV_MRE_CALLER_AM)
        {
            g_caller_flag = SRV_MRE_CALLER_AM;
        }
        else if (caller == SRV_MRE_CALLER_DOWNLOAD)
        {
            g_caller_flag = SRV_MRE_CALLER_DOWNLOAD;
        }
        break;
    case VM_VLC_ASYN_ALLOC_ASM:
        load_ret = SRV_MRE_LOAD_CORE_ASYN_ALLOC_ASM;
        //MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_LOAD_CORE_FAIL, load_ret);
        break;
    case VM_VLC_MASS_STORAGE:
        load_ret = SRV_MRE_LOAD_CORE_MASS_STORAGE;
        //MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_LOAD_CORE_FAIL, load_ret);
        break;
    case VM_VLC_INTERNEL_ERROR:
        load_ret = SRV_MRE_LOAD_CORE_INTERNEL_ERROR;
        // MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_LOAD_CORE_FAIL, load_ret);
        break;
    default:
        load_ret = SRV_MRE_LOAD_CORE_INTERNEL_ERROR;
        //MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_LOAD_CORE_FAIL, load_ret);
        break;
    }
    MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_LOAD_CORE_FAIL, load_ret);
    return load_ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_unload_core
* DESCRIPTION
*  Unload MRE Core.
* PARAMETERS
*  caller : [IN] Type of load MRE core.
* RETURN VALUES
*  void
*****************************************************************************/
void srv_mre_unload_core(srv_mre_load_core_caller_enum caller)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_caller_flag == SRV_MRE_CALLER_AM) /* AM is running */
    {
        if (caller == SRV_MRE_CALLER_AM)    /* Unload core from AM */
        {
            g_caller_flag = SRV_MRE_CALLER_NULL;
        }
        else
        {
            return;
        }
    }
    else if (g_caller_flag == SRV_MRE_CALLER_DOWNLOAD)  /* Download service is running */
    {
        if (caller == SRV_MRE_CALLER_DOWNLOAD)  /* Unload core from download service */
        {
            g_caller_flag = SRV_MRE_CALLER_NULL;
        }
        else
        {
            return;
        }
    }

#ifdef __MRE_LIB_NETWORK__
    if ((vm_pmng_current_counter() <= 0) && (!srv_mre_dl_is_running()))
#else
    if (vm_pmng_current_counter() <= 0)
#endif
    {
        vm_exit();
    }
}


/*****************************************************************************
* FUNCTION
*  srv_mre_launch_app_cb
* DESCRIPTION
*  launch app callback for MRE service.
* PARAMETERS
*  app_path     [IN]    
*  evt     [IN]        
* RETURNS
*  void
*****************************************************************************/
static void srv_mre_launch_app_cb(U16 *app_path, srv_mre_launch_app_evt_enum evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_LAUNCH_APP_CALLBACK_RESULT, evt);
    if(NULL != g_srv_mre_launch_app_cb)
    {
        switch (evt)
        {
        case MRE_EVT_START_SUCCESS:
            g_srv_mre_launch_app_cb(app_path, SRV_MRE_LAUNCH_APP_EVT_SUCCESS);
            break;

        case MRE_EVT_START_ASM_READY:
            g_srv_mre_launch_app_cb(app_path, SRV_MRE_LAUNCH_APP_ASM_READY);
            break;

        case MRE_EVT_START_INTERNEL_ERROR:
            g_srv_mre_launch_app_cb(app_path, SRV_MRE_LAUNCH_APP_EVT_INTERNEL_ERROR);
            break;

        case MRE_EVT_QUIT:
            g_srv_mre_launch_app_cb(app_path, SRV_MRE_LAUNCH_APP_EVT_QUIT);
            break;

        default:
            break;
        }
    }
}


/*****************************************************************************
* FUNCTION
*  srv_mre_launch_app
* DESCRIPTION
*  Launch a MRE application.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  app_cb : [IN] Callback function.
* RETURN VALUES
*  
*****************************************************************************/
srv_mre_launch_app_result_enum srv_mre_launch_app_check_cert(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 ce_check_result = SRV_MRE_VERIFY_BAD_PARAM;   
    srv_mre_launch_app_result_enum ret= SRV_MRE_LAUNCH_APP_FORCE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

    /* Check parameter */
    if (app_path == NULL)
    {
        return SRV_MRE_LAUNCH_APP_BAD_PARAM;
    }

    ce_check_result =srv_mre_is_app_valid(app_path);
    ret = mre_srv_verify_map[ce_check_result];
    /*switch (ce_check_result)
    {
    case SRV_MRE_VERITY_INSUFFICIENT_SYS_MEM:
    ret = SRV_MRE_LAUNCH_APP_NOT_ENOUGH_MEMORY;//not
    break;
    case SRV_MRE_VERIFY_KEY_EXPIRED: //not
    ret = SRV_MRE_LAUNCH_APP_CERT_OVERDUE;
    break;
    case SRV_MRE_VERIFY_CHECK_PARAM_FAIL://not
    ret = SRV_MRE_LAUNCH_APP_BAD_PARAM;
    break;
    case SRV_MRE_VERIFY_PER_MEM_ERROR:
    ret = SRV_MRE_LAUNCH_APP_INTERNAL_ERROR;
    break;
    case SRV_MRE_VERIFY_PER_INIT_ERROR:
    ret =SRV_MRE_LAUNCH_APP_INTERNAL_ERROR ;
    break;
    case SRV_MRE_VERIFY_PER_CATCH_ERROR:
    ret = SRV_MRE_LAUNCH_APP_INTERNAL_ERROR;
    break;
    case SRV_MRE_VERIFY_RESOLUTION_DISMATCH:
    ret = SRV_MRE_LAUNCH_APP_PLATFORM_PARAM_DISMATCH;
    break;
    case SRV_MRE_VERIFY_INSUFFICIENT_MEM:
    ret = SRV_MRE_LAUNCH_APP_NOT_ENOUGH_MEMORY;
    break;
    case SRV_MRE_VERIFY_TIMESTAMP_ERROR:
    ret = SRV_MRE_LAUNCH_APP_FORCE;
    break;
    case SRV_MRE_VERIFY_IMSI_DISMATCH:
    ret = SRV_MRE_LAUNCH_APP_FORCE;
    break;
    case SRV_MRE_VERIFY_APP_BANNED:
    ret = SRV_MRE_LAUNCH_APP_FORCE;
    break;
    case SRV_MRE_VERIFY_DIGEST_DISMATCH:
    ret = SRV_MRE_LAUNCH_APP_FORCE;
    break;
    case SRV_MRE_VERIFY_VERIFY_FAILED:
    ret = SRV_MRE_LAUNCH_APP_FORCE;
    break;
    case SRV_MRE_VERIFY_BAD_DIGEST:
    ret = SRV_MRE_LAUNCH_APP_FORCE;
    break;
    case SRV_MRE_VERIFY_BAD_PARAM:
    ret = SRV_MRE_LAUNCH_APP_FORCE;
    break;
    case SRV_MRE_VERIFY_OK:
    ret = SRV_MRE_LAUNCH_APP_SUCCESS;
    break;
    default:
    ret = SRV_MRE_LAUNCH_APP_FORCE;
    break;

    }*/
    //	if( SRV_MRE_VERIFY_OK != ce_check_result )
    //	{
    //		return SRV_MRE_LAUNCH_APP_CERT_OVERDUE;
    //	}

    //	return SRV_MRE_LAUNCH_APP_SUCCESS;
    return ret;
}

extern void vm_start_parent();
/*****************************************************************************
* FUNCTION
*  srv_mre_launch_app
* DESCRIPTION
*  Launch a MRE application.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  app_cb : [IN] Callback function.
* RETURN VALUES
*  
*****************************************************************************/
mmi_ret srv_mre_launch_app_confirm_popup_proc (mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            {
                //					srv_mre_lan_para_type *launch_para = NULL;
                //					launch_para =(srv_mre_lan_para_type*)evt->user_tag;
                U16 temp_path[SRV_MRE_APPMGR_FILEPATH_LEN];
                mmi_chset_convert(MMI_CHSET_UTF8,MMI_CHSET_UCS2, (char *)(launch_para.app_path), (char *)temp_path, SRV_MRE_APPMGR_FILEPATH_LEN*2);
                srv_mre_launch_app_ex(temp_path, (srv_mre_launch_app_cb_t)launch_para.app_cb);
            }
            break;
        case MMI_ALERT_CNFM_NO:
            {
                vm_start_parent();
            }
            break;
        }
    }
    return MMI_RET_OK;
}

srv_mre_write_app_path(U16 *app_path)
{
    mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8, (char *)app_path, (char *)(launch_para.app_path), SRV_MRE_APPMGR_FILEPATH_LEN);
}

/*****************************************************************************
* FUNCTION
*  srv_mre_launch_app
* DESCRIPTION
*  Launch a MRE application.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  app_cb : [IN] Callback function.
* RETURN VALUES
*  
*****************************************************************************/
mmi_ret srv_mre_install_app_confirm_popup_proc (mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
        case MMI_ALERT_CNFM_YES:
            {
                //					srv_mre_lan_para_type *launch_para = NULL;
                //					launch_para =(srv_mre_lan_para_type*)evt->user_tag;
                MMI_BOOL ret;
                U16 temp_path[SRV_MRE_APPMGR_FILEPATH_LEN];
                mmi_chset_convert(MMI_CHSET_UTF8,MMI_CHSET_UCS2, (char *)(launch_para.app_path), (char *)temp_path, SRV_MRE_APPMGR_FILEPATH_LEN*2);
                ret = srv_mre_appmgr_install_app(temp_path,SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL,NULL);
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
                    return MMI_RET_OK;
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
                    return MMI_RET_OK;
                }
            }
        case MMI_ALERT_CNFM_NO:
            {
            }
            break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_launch_app
* DESCRIPTION
*  Launch a MRE application.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  app_cb : [IN] Callback function.
* RETURN VALUES
*  
*****************************************************************************/
srv_mre_launch_app_result_enum srv_mre_launch_app(U16 *app_path, srv_mre_launch_app_cb_t app_cb)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_launch_app_result_enum result = SRV_MRE_LAUNCH_APP_END_OF_ENUM;
    launch_para.app_cb = (void*)app_cb;
    mmi_chset_convert(MMI_CHSET_UCS2,MMI_CHSET_UTF8, (char *)app_path, (char *)(launch_para.app_path), SRV_MRE_APPMGR_FILEPATH_LEN);
    //launch_para.app_path = app_path;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    MRE_SWLA_START("M10");
#ifdef __MRE_AM__
#ifndef __COSMOS_MMI_PACKAGE__
    result = srv_mre_launch_app_check_cert(app_path);
    MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_LAUNCH_APP_RESULT_2,result);
    if(SRV_MRE_LAUNCH_APP_SUCCESS == result)
    {
        result = srv_mre_launch_app_ex(app_path,app_cb);
        MRE_SWLA_STOP("M10");
    }
    else
    {

        return result;
    }
#else  /* __COSMOS_MMI_PACKAGE__ */
    result = srv_mre_launch_app_ex(app_path,app_cb);
#endif /* __COSMOS_MMI_PACKAGE__ */
#else  /* __MRE_AM__ */ 
    result = srv_mre_launch_app_ex(app_path,app_cb);
#endif /* __MRE_AM__ */ 
    MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_LAUNCH_APP_RESULT_2,result);
    MRE_SWLA_STOP("M10");
    return result;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_launch_app
* DESCRIPTION
*  Launch a MRE application.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  app_cb : [IN] Callback function.
* RETURN VALUES
*  
*****************************************************************************/
srv_mre_launch_app_result_enum srv_mre_launch_app_ex(U16 *app_path, srv_mre_launch_app_cb_t app_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;
    srv_mre_load_core_result_enum load_mre_core_ret;
    srv_mre_launch_app_result_enum start_ret;
    S8 file_path_log_out[SRV_FMGR_PATH_MAX_LEN + 1];


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MRE_SWLA_START("M11");
    /* LOG */
    mmi_wcs_to_asc(file_path_log_out, app_path);
    MMI_PRINT(MOD_MRE, MMI_MRE_TRC_G2_SERVICE, "[MRE][Service] srv_mre_launch_app <app_path:%s>\n", file_path_log_out);

    /* Check parameter */
    if (app_path == NULL)
    {
        MRE_SWLA_STOP("M11");
        return SRV_MRE_LAUNCH_APP_BAD_PARAM;
    }

    /* Load MRE Core */
    if (!srv_mre_is_core_loaded())
    {
        load_mre_core_ret = srv_mre_load_core(NULL, SRV_MRE_CALLER_SERVICE);
        if (load_mre_core_ret != SRV_MRE_LOAD_CORE_SUCCESS)
        {
            MRE_SWLA_STOP("M11");
            return SRV_MRE_LAUNCH_APP_INTERNAL_ERROR;
        }
    }

    /* if application is running, bring to foreground, else start app */
    if (srv_mre_is_app_bg_running(app_path) > 0)
    {
        MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_LAUNCH_APP_IS_BG_RUNNING);
        if ((ret = (S32) vm_pmng_set_fg((VMWSTR) app_path)) >= 0)
        {
            if (app_cb)
            {
                app_cb(app_path, SRV_MRE_LAUNCH_APP_EVT_SUCCESS);
            }
            start_ret = SRV_MRE_LAUNCH_APP_SUCCESS;
        }
        else
        {
            if (app_cb)
            {
                app_cb(app_path, SRV_MRE_LAUNCH_APP_EVT_INTERNEL_ERROR);
            }
            start_ret = SRV_MRE_LAUNCH_APP_INTERNAL_ERROR;
        }
        MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_LAUNCH_APP_SET_FG_RUN_RESULT, start_ret);
    }
    else
    {
        g_srv_mre_launch_app_cb = app_cb;

        /* Add Start <Start With Parameter> */ 
        vm_pmng_set_create_app_param((VMINT)(parameter_of_start)); 
        /* Add END <Start With Parameter> */

        ret = vm_execute((VMWSTR) app_path, (vm_mre_app_evt_cb_t) srv_mre_launch_app_cb);
        MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_LAUNCH_APP_RESULT, ret);
        ret += 16;
        start_ret = mre_srv_execute_verify_map[ret];

        /* switch (ret)
        {
        case VM_EXECUTE_APP_SUCCESS:
        start_ret = SRV_MRE_LAUNCH_APP_SUCCESS;
        break;
        case VM_EXECUTE_APP_ILLEGAL:
        case VM_EXECUTE_SYS_NOT_SUPPORT_VP:
        start_ret = SRV_MRE_LAUNCH_APP_ILLEGAL;
        break;
        case VM_EXECUTE_APP_NOT_ENOUGH_MEMORY:
        start_ret = SRV_MRE_LAUNCH_APP_NOT_ENOUGH_MEMORY;
        break;
        case VM_EXECUTE_APP_CALL_STACK_FULL:
        start_ret = SRV_MRE_LAUNCH_APP_CALL_STACK_FULL;
        break;
        case VM_EXECUTE_INTERNAL_ERROR:
        start_ret = SRV_MRE_LAUNCH_APP_INTERNAL_ERROR;
        break;
        case VM_EXECUTE_PLATFORM_PARAM_DISMATCH:
        start_ret = SRV_MRE_LAUNCH_APP_PLATFORM_PARAM_DISMATCH;
        break;
        case VM_EXECUTE_TIMESTAMP_ERROR:
        start_ret = SRV_MRE_LAUNCH_APP_TIMESTAMP_ERROR;
        break;
        case VM_EXECUTE_BANNED_APP:
        start_ret = SRV_MRE_LAUNCH_APP_BANNED_APP;
        break;
        case VM_EXECUTE_IMSI_DISMATCH:
        start_ret = SRV_MRE_LAUNCH_APP_IMSI_DISMATCH;
        break;
        case VM_EXECUTE_CERT_OVERDUE:
        start_ret = SRV_MRE_LAUNCH_APP_CERT_OVERDUE;
        break;
        case VM_EXECUTE_EXCEED_FILE_IN_MRE_DIRECTORY:
        start_ret = SRV_MRE_LAUNCH_APP_EXCEED_FILE_IN_MRE_DIRECTORY;
        break;
        case VM_EXECUTE_SYS_ASYN_ASM:
        start_ret = SRV_MRE_LAUNCH_APP_SYS_ASYN_ASM;
        break;
        case VM_EXECUTE_ONLY_ONE_FOREGROUND:
        start_ret = SRV_MRE_LAUNCH_APP_ONLY_ONE_FOREGROUND;
        break;
        case VM_EXECUTE_MAX_APP_NUM_REACHED:
        start_ret = SRV_MRE_LAUNCH_APP_MAX_NUM;
        break;
        case VM_EXECUTE_VERSION_NOT_MATCH:
        start_ret = SRV_MRE_LAUNCH_VERSION_NOT_MATCH;
        default:
        start_ret = SRV_MRE_LAUNCH_APP_ILLEGAL;
        break;
        }*/
    }


    srv_mre_unload_core(SRV_MRE_CALLER_SERVICE);
    MRE_SWLA_STOP("M11");
    return start_ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_close_app
* DESCRIPTION
*  Close a MRE application.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
* RETURN VALUES
*  void
*****************************************************************************/
void srv_mre_close_app(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_P_HANDLE p_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_path == NULL)
    {
        return;
    }

    if (!srv_mre_is_core_loaded())
    {
        return;
    }

    if ((p_handle = vm_pmng_get_handle((VMWSTR) app_path)) > 0)
    {
        vm_pmng_delete_process(p_handle);
    }

}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_state
* DESCRIPTION
*  Get the application's state, including FG RUNNING, BG RUNNING and CLOSE.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
* RETURN VALUES
*  .
*****************************************************************************/
srv_mre_check_app_state_result_enum srv_mre_get_app_state(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_P_HANDLE p_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_path == NULL)
    {
        return SRV_MRE_APP_STATE_UNKNOWN;
    }

    if (!srv_mre_is_core_loaded())
    {
        return SRV_MRE_APP_STATE_UNKNOWN;
    }

    if ((p_handle = vm_pmng_get_handle((VMWSTR) app_path)) > 0)
    {
        switch (vm_pmng_state(p_handle))
        {
        case VM_PMNG_UNLOAD:
            return SRV_MRE_APP_STATE_NONSTART;

        case VM_PMNG_FOREGROUND:
            return SRV_MRE_APP_STATE_FORGROUND;

        case VM_PMNG_BACKGROUND:
            return SRV_MRE_APP_STATE_BACKGROUND;

        case VM_PMNG_STARTING:
            return SRV_MRE_APP_STATE_STARTING;

        case VM_PMNG_CLOSING:
            return SRV_MRE_APP_STATE_CLOSING;

        case VM_PMNG_INACTIVE:
            return SRV_MRE_APP_STATE_INACTIVE;

        default:
            return SRV_MRE_APP_STATE_UNKNOWN;
        }
    }
    else
    {
        return SRV_MRE_APP_STATE_NONEXIST;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_image
* DESCRIPTION
*  Get the image data of a MRE application. If p_img is NULL, then return the image size by img_size.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  p_img : [OUT] Pointer to image buffer.
*  img_size : [OUT] Size of image.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_app_image(U16 *app_path, U8 *p_img, U32 *img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    S32 chset_type_size;
    srv_mre_load_core_result_enum load_mre_core_ret;
    U8 *res_buf;
    S32 res_size;
    U8 *temp_icon_ptr;
    S32 temp_icon_size;
    S32 offset = 13;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_path == NULL || img_size == NULL)
    {
        return MMI_FALSE;
    }

    /* Load MRE Core */
    if (!srv_mre_is_core_loaded())
    {
        load_mre_core_ret = srv_mre_load_core(NULL, SRV_MRE_CALLER_SERVICE);
        if (load_mre_core_ret != SRV_MRE_LOAD_CORE_SUCCESS)
        {
            return MMI_FALSE;
        }
    }

    /* Load resource */
    res_buf = vm_load_resource_from_file((PS16) app_path, SRV_MRE_APP_AB2_LOGO, &res_size);
    if(res_buf == NULL)
    {
        if (vm_get_vm_tag((PS16) app_path, VM_CE_INFO_CHARSET, NULL, &chset_type_size) == GET_TAG_TRUE)
        {
            res_buf = vm_load_resource_from_file((PS16) app_path, SRV_MRE_APP_NEW_LOGO, &res_size);
        }
        else
        {
            res_buf = vm_load_resource_from_file((PS16) app_path, SRV_MRE_APP_LOGO, &res_size);
        }
    }

    if (!res_buf)
    {
        ret = MMI_FALSE;
    }
    else
    {
        temp_icon_size = *(res_buf + offset + 6) +
            ((*(res_buf + offset + 7)) << 8) + ((*(res_buf + offset + 8)) << 16) + ((*(res_buf + offset + 9)) << 24);

        if (temp_icon_size >= 0)
        {
            *img_size = (U32) temp_icon_size;
        }
        else
        {
            ret = MMI_FALSE;
        }

        if (p_img == NULL)  /* get icon size */
        {
            ret = MMI_TRUE;
        }
        else    /* get icon data */
        {
            temp_icon_ptr = res_buf + offset + 10;
            memcpy(p_img, temp_icon_ptr, *img_size);
            ret = MMI_TRUE;
        }

        vm_free(res_buf);
    }

    srv_mre_unload_core(SRV_MRE_CALLER_SERVICE);
    return ret;
}

MMI_BOOL srv_mre_get_app_image_ex(U16 *app_path, U8 **p_img, U32 *img_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    S32 chset_type_size;
    srv_mre_load_core_result_enum load_mre_core_ret;
    U8 *res_buf;
    S32 res_size;
    U8 *temp_icon_ptr;
    S32 temp_icon_size;
    S32 offset = 13;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_path == NULL || img_size == NULL)
    {
        return MMI_FALSE;
    }

    /* Load MRE Core */
    if (!srv_mre_is_core_loaded())
    {
        load_mre_core_ret = srv_mre_load_core(NULL, SRV_MRE_CALLER_SERVICE);
        if (load_mre_core_ret != SRV_MRE_LOAD_CORE_SUCCESS)
        {
            return MMI_FALSE;
        }
    }

    /* Load resource */
    res_buf = vm_load_resource_from_file((PS16) app_path, SRV_MRE_APP_AB2_LOGO, &res_size);
    if(res_buf == NULL)
    {
        if (vm_get_vm_tag((PS16) app_path, VM_CE_INFO_CHARSET, NULL, &chset_type_size) == GET_TAG_TRUE)
        {
            res_buf = vm_load_resource_from_file((PS16) app_path, SRV_MRE_APP_NEW_LOGO, &res_size);
        }
        else
        {
            res_buf = vm_load_resource_from_file((PS16) app_path, SRV_MRE_APP_LOGO, &res_size);
        }
    }

    if (!res_buf)
    {
        ret = MMI_FALSE;
    }
    else
    {
        temp_icon_size = *(res_buf + offset + 6) +
            ((*(res_buf + offset + 7)) << 8) + ((*(res_buf + offset + 8)) << 16) + ((*(res_buf + offset + 9)) << 24);

        if (temp_icon_size >= 0)
        {
            *img_size = (U32) temp_icon_size;
        }
        else
        {
            ret = MMI_FALSE;
        }

        if (p_img == NULL)  /* get icon size */
        {
            vm_free(res_buf);
            ret = MMI_TRUE;
        }
        else    /* get icon data */
        {
            temp_icon_ptr = res_buf + offset + 10;
            *p_img = temp_icon_ptr;
            ret = MMI_TRUE;
        }

    }

    srv_mre_unload_core(SRV_MRE_CALLER_SERVICE);
    return ret;
}

MMI_BOOL srv_mre_free_app_image_ex(U8 *p_img)
{
    U8 *res_buf;
    srv_mre_load_core_result_enum load_mre_core_ret;	
    S32 offset = 13;

    if (p_img == NULL)  /* get icon size */
    {
        return MMI_FALSE;
    }

    /* Load MRE Core */
    if (!srv_mre_is_core_loaded())
    {
        load_mre_core_ret = srv_mre_load_core(NULL, SRV_MRE_CALLER_SERVICE);
        if (load_mre_core_ret != SRV_MRE_LOAD_CORE_SUCCESS)
        {
            return MMI_FALSE;
        }
    }

    res_buf = p_img - offset - 10;
    vm_free(res_buf);

    srv_mre_unload_core(SRV_MRE_CALLER_SERVICE);
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_get_info_by_tag
* DESCRIPTION
*  Get info by tag.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  tag : [IN] Tag type.
*  des_buf : [OUT] Destination buffer.
*  des_size : [OUT] Destination buffer size.
*  lan_type : [IN] Language type.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_info_by_tag(
                                 U16 *app_path,
                                 srv_mre_info_type_enum tag,
                                 void *des_buf,
                                 U32 *des_size,
                                 S32 lan_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_load_core_result_enum load_mre_core_ret;
    MMI_BOOL ret = MMI_TRUE;
    S32 gettag_ret = GET_TAG_ERROR;
    S32 result;
    S8 *original_buf = NULL;
    S32 original_buf_size;
    S8 *converted_buf = NULL;
    S32 converted_buf_size;
    CHAR *lang = NULL;
    S32 language = VM_LANG_ENG; // TODO: default language?
    S32 tag_type[2] = {0, 0};
    MMI_BOOL is_support_multi_lan = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_path == NULL || tag >= SRV_MRE_INFO_END_OF_ENUM || des_size == NULL)
    {
        return MMI_FALSE;
    }

    /* Load MRE Core */
    if (!srv_mre_is_core_loaded())
    {
        load_mre_core_ret = srv_mre_load_core(NULL, SRV_MRE_CALLER_SERVICE);
        if (load_mre_core_ret != SRV_MRE_LOAD_CORE_SUCCESS)
        {
            return MMI_FALSE;
        }
    }

#ifndef LOW_COST_SUPPORT
    if( tag == SRV_MRE_INFO_NAME )
    {
        VMINT namesize = 0;

        if (vm_get_vm_tag((short *)app_path, VM_CE_INFO_MULTI_NAME_LIST, NULL, &namesize) == GET_TAG_TRUE)
        {
            VMINT* app_name_list = NULL; 
            char temp[12] = {0};
            VMINT i = 0, j = 0;

            language = 44;

            lang = (CHAR *)srv_dev_profile_get_value_string(dev_profile_current_language);

            for(i=0;i<strlen(lang);i++)
            {
                if(lang[i]>='0' && lang[i]<='9')
                {
                    if(lang[i] != '0')
                    {
                        temp[j] = lang[i];
                        j++;
                    }
                }
            }

            if( j > 0 )
            {
                language = atoi(temp);
            }

            if (vm_get_tag_by_lang_id((short *)app_path, VM_CE_INFO_MULTI_NAME_LIST, NULL, &namesize, language) == GET_TAG_TRUE)
            {
                app_name_list = vm_calloc(namesize + 1);

                if(app_name_list)
                {
                    vm_get_tag_by_lang_id((short *)app_path, VM_CE_INFO_MULTI_NAME_LIST, app_name_list, &namesize, language);

                    if(des_buf == NULL)
                    {
                        *des_size = (U32) namesize;
                    }
                    else
                    {
                        *des_size = (U32) namesize;
                        memcpy(des_buf, app_name_list, namesize);
                    }

                    if (app_name_list)
                    {
                        vm_free(app_name_list);
                    }

                    ret = MMI_TRUE;
                }
                else
                {
                    *des_size = 0;
                    ret = MMI_FALSE;
                }
            }
            else if (vm_get_tag_by_lang_id((short *)app_path, VM_CE_INFO_MULTI_NAME_LIST, NULL, &namesize, 44) == GET_TAG_TRUE)
            {
                app_name_list = vm_calloc(namesize + 1);

                if(app_name_list)
                {
                    vm_get_tag_by_lang_id((short *)app_path, VM_CE_INFO_MULTI_NAME_LIST, app_name_list, &namesize, 44);

                    if(des_buf == NULL)
                    {
                        *des_size = (U32) namesize;
                    }
                    else
                    {
                        *des_size = (U32) namesize;
                        memcpy(des_buf, app_name_list, namesize);
                    }

                    if (app_name_list)
                    {
                        vm_free(app_name_list);
                    }

                    ret = MMI_TRUE;
                }
                else
                {
                    *des_size = 0;
                    ret = MMI_FALSE;
                }
            }

            srv_mre_unload_core(SRV_MRE_CALLER_SERVICE);
            return ret;

        }
    }
#endif

    switch (tag)
    {
    case SRV_MRE_INFO_DEV:
        tag_type[1] = VM_CE_INFO_DEV;
        is_support_multi_lan = MMI_FALSE;
        break;

    case SRV_MRE_INFO_APP_ID:
        tag_type[1] = VM_CE_INFO_APP_ID;
        is_support_multi_lan = MMI_FALSE;
        break;

    case SRV_MRE_INFO_NAME:
        tag_type[0] = VM_CE_INFO_NAME_LIST;
        tag_type[1] = VM_CE_INFO_NAME;
        is_support_multi_lan = MMI_TRUE;
        break;

    case SRV_MRE_INFO_VER:
        tag_type[1] = VM_CE_INFO_VER;
        is_support_multi_lan = MMI_FALSE;
        break;

    case SRV_MRE_INFO_DESC:
        /* tag_type[0] = VM_CE_INFO_DESC_LIST; */
        tag_type[1] = VM_CE_INFO_DESC;
        is_support_multi_lan = MMI_FALSE;
        break;

    case SRV_MRE_INFO_TEL:
        /* tag_type[0] = VM_CE_INFO_DESC_LIST; */
        tag_type[1] = VM_CE_INFO_DESC;
        is_support_multi_lan = MMI_FALSE;
        break;

    case SRV_MRE_INFO_BG_RUN:
        tag_type[1] = VM_CE_INFO_SUPPORT_BG_RUN;
        is_support_multi_lan = MMI_FALSE;
        break;

    default:
        tag_type[0] = -1;
        tag_type[1] = -1;
        break;
    }

    if (lan_type == VM_LANG_NULL)
    {
        lang = (CHAR *)(Get_Current_Lang_CountryCode());
        if (strcmp((PS8) lang, "en-US") == 0)   /* means english */
        {
            language = VM_LANG_ENG;
        }
        else if (strcmp((PS8) lang, "zh-CN") == 0)
        {
            language = VM_LANG_CHS;
        }
        else if (strcmp((PS8) lang, "zh-TW") == 0)
        {
            language = VM_LANG_CHT;
        }
    }
    else
    {
        language = lan_type;
    }

    /* get app original info size */
    if (is_support_multi_lan)
    {
        gettag_ret = vm_get_tag_by_lang_id((PS16) app_path, tag_type[0], NULL, &original_buf_size, language);
    }

    if (gettag_ret != GET_TAG_TRUE)
    {
        gettag_ret = vm_get_vm_tag((PS16) app_path, tag_type[1], NULL, &original_buf_size);
    }

    if (gettag_ret == GET_TAG_TRUE && original_buf_size != 0)
    {
        /* allocate memory for original data */
        original_buf = vm_calloc(original_buf_size + 1);
        if (original_buf)
        {
            gettag_ret = GET_TAG_ERROR;
            /* get app original info */
            if (is_support_multi_lan)
            {
                gettag_ret = vm_get_tag_by_lang_id((PS16) app_path, tag_type[0], original_buf, &original_buf_size, language);
            }

            if (gettag_ret != GET_TAG_TRUE)
            {
                gettag_ret = vm_get_vm_tag((PS16) app_path, tag_type[1], original_buf, &original_buf_size);
                language = VM_LANG_CHS;
            }

            if (gettag_ret == GET_TAG_TRUE)
            {
                /* Do not need to convert */
                if ((!is_support_multi_lan) &&
                    (tag == SRV_MRE_INFO_APP_ID || tag == SRV_MRE_INFO_VER || tag == SRV_MRE_INFO_BG_RUN))
                {
                    if (des_buf == NULL)    /* get buffer size */
                    {
                        *des_size = (U32) original_buf_size;
                    }
                    else    /* get data */
                    {
                        *des_size = (U32) original_buf_size;
                        memcpy(des_buf, original_buf, original_buf_size);
                    }
                }
                else
                {
                    /* allocate memory for converted data */
                    converted_buf_size = (original_buf_size + 1) << 1;
                    converted_buf = vm_calloc(converted_buf_size);
                    if (converted_buf)
                    {
                        S32 chset_type;
                        S32 chset_type_size = 4;
                        /* strcat((PS8) original_buf, "\0"); */

                        /* Check charset type */
                        if (vm_get_vm_tag((PS16) app_path, VM_CE_INFO_CHARSET, &chset_type, &chset_type_size) == GET_TAG_TRUE &&
                            chset_type == 1) /* UCS2 chset */
                        {
                            U16 *temp_ptr;
                            mmi_wcsncpy((WCHAR*) converted_buf, (WCHAR*) original_buf, original_buf_size);
                            /* Trunc space character */
                            temp_ptr = (WCHAR*)converted_buf;
                            while (*temp_ptr != (U16)0)
                            {
                                temp_ptr ++;
                            }
                            temp_ptr --;
                            while (*temp_ptr == (U16)32 && temp_ptr > (WCHAR*)converted_buf) /* search space character */
                            {
                                *temp_ptr = 0;
                                temp_ptr --;
                            }
                            result = original_buf_size;
                        }
                        else
                        {
                            U16 *temp_ptr;
                            /* convert char-set */
                            if (language == VM_LANG_CHT)
                            {
                                result = mmi_chset_convert(
                                    MMI_CHSET_BIG5,
                                    MMI_CHSET_UCS2,
                                    original_buf,
                                    converted_buf,
                                    converted_buf_size);
                            }
                            else
                            {
#ifdef __MMI_CHSET_GB2312__
                                result = mmi_chset_convert(
                                    MMI_CHSET_GB2312,
                                    MMI_CHSET_UCS2,
                                    original_buf,
                                    converted_buf,
                                    converted_buf_size);
#else
                                result = mmi_chset_convert(
                                    MMI_CHSET_ASCII,
                                    MMI_CHSET_UCS2,
                                    original_buf,
                                    converted_buf,
                                    converted_buf_size);
#endif
                            }
                            /* Trunc space character */
                            temp_ptr = (WCHAR*)converted_buf;
                            while (*temp_ptr != (U16)0)
                            {
                                temp_ptr ++;
                            }
                            temp_ptr --;
                            while (*temp_ptr == (U16)32 && temp_ptr > (WCHAR*)converted_buf) /* search space character */
                            {
                                *temp_ptr = 0;
                                temp_ptr --;
                            }
                        }

                        if (result <= 0)
                        {
                            ret = MMI_FALSE;
                        }
                        else
                        {
                            if (tag == SRV_MRE_INFO_TEL)    /* get telephone number from description */
                            {
                                U16 *p_phone, *p_rank;

                                p_phone = mmi_wcsstr((WCHAR*) converted_buf, SRV_MRE_APP_INFO_PHONE);
                                p_rank = mmi_wcsstr((WCHAR*) converted_buf, SRV_MRE_APP_INFO_RANK);
                                if (p_phone && p_rank)
                                {
                                    *des_size =
                                        (U32) ((p_rank - (p_phone + mmi_ucs2strlen((PS8) SRV_MRE_APP_INFO_PHONE)) -
                                        1) << 1);
                                    mmi_wcsncpy(
                                        (WCHAR*) des_buf,
                                        p_phone + mmi_ucs2strlen((PS8) SRV_MRE_APP_INFO_PHONE),
                                        *des_size >> 1);
                                }
                                else
                                {
                                    ret = MMI_FALSE;
                                }
                            }
                            else if (tag == SRV_MRE_INFO_DESC)  /* get description */
                            {
                                U16 *p_desc, *p_phone;

                                p_desc = mmi_wcsstr((WCHAR*) converted_buf, SRV_MRE_APP_INFO_DESC);
                                p_phone = mmi_wcsstr((WCHAR*) converted_buf, SRV_MRE_APP_INFO_PHONE);
                                if (p_phone && p_desc)
                                {
                                    *des_size =
                                        (U32) ((p_phone - (p_desc + mmi_ucs2strlen((PS8) SRV_MRE_APP_INFO_DESC)) -
                                        1) << 1);

                                    if (des_buf == NULL)    /* get buffer size */
                                    {
                                        ret = MMI_TRUE;
                                    }
                                    else    /* get data */
                                    {
                                        mmi_wcsncpy(
                                            (WCHAR*) des_buf,
                                            p_desc + mmi_ucs2strlen((PS8) SRV_MRE_APP_INFO_DESC),
                                            *des_size >> 1);
                                        ret = MMI_TRUE;
                                    }
                                }
                                else
                                {
                                    ret = MMI_FALSE;
                                }
                            }
                            else
                            {
                                *des_size = (U32) result;
                                if (des_buf == NULL)    /* get buffer size */
                                {
                                    ret = MMI_TRUE;
                                }
                                else    /* get data */
                                {
                                    mmi_wcsncpy((WCHAR *)des_buf, (WCHAR *)converted_buf, 
                                        *des_size >> 1);
                                    ret = MMI_TRUE;
                                }
                            }
                        }

                        /* free temp memory */
                        if (converted_buf)
                        {
                            vm_free(converted_buf);
                        }
                    }
                    else
                    {
                        ret = MMI_FALSE;
                    }
                }
            }

            /* free temp memory */
            if (original_buf)
            {
                vm_free(original_buf);
            }
        }
        else
        {
            ret = MMI_FALSE;
        }
    }
    else
    {
        *des_size = 0;
        ret = MMI_FALSE;
    }

    /* Unload MRE Core */
    srv_mre_unload_core(SRV_MRE_CALLER_SERVICE);
    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_name
* DESCRIPTION
*  Get the name of a MRE application. If p_name is NULL, then return the name size by name_size.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  p_name : [OUT] Pointer to name buffer.
*  name_size : [OUT] Size of name.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_app_name(U16 *app_path, U16 *p_name, U32 *name_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef LOW_COST_SUPPORT
    VMINT namesize = 0;
    if (vm_get_vm_tag((short *)app_path, VM_CE_INFO_MULTI_NAME_LIST, NULL, &namesize) == GET_TAG_TRUE)
    {

        VMINT* app_name_list = NULL; 
        S32 language = 44;
        CHAR *lang = NULL;
        char temp[12] = {0};
        VMINT i = 0, j = 0;

        lang = (CHAR *)srv_dev_profile_get_value_string(dev_profile_current_language);

        for(i=0;i<strlen(lang);i++)
        {
            if(lang[i]>='0' && lang[i]<='9')
            {
                if(lang[i] != '0')
                {
                    temp[j] = lang[i];
                    j++;
                }
            }
        }

        if( j > 0 )
        {
            language = atoi(temp);
        }

        if (vm_get_tag_by_lang_id((short *)app_path, VM_CE_INFO_MULTI_NAME_LIST, NULL, &namesize, language) == GET_TAG_TRUE)
        {
            app_name_list = vm_calloc(namesize + 1);

            if(app_name_list)
            {
                vm_get_tag_by_lang_id((short *)app_path, VM_CE_INFO_MULTI_NAME_LIST, app_name_list, &namesize, language);

                if(p_name == NULL)
                {
                    *name_size = (U32) namesize;
                }
                else
                {
                    *name_size = (U32) namesize;
                    memcpy(p_name, app_name_list, namesize);
                }

                if (app_name_list)
                {
                    vm_free(app_name_list);
                }

                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }
        }
        else if (vm_get_tag_by_lang_id((short *)app_path, VM_CE_INFO_MULTI_NAME_LIST, NULL, &namesize, 44) == GET_TAG_TRUE)
        {
            app_name_list = vm_calloc(namesize + 1);

            if(app_name_list)
            {
                vm_get_tag_by_lang_id((short *)app_path, VM_CE_INFO_MULTI_NAME_LIST, app_name_list, &namesize, 44);

                if(p_name == NULL)
                {
                    *name_size = (U32) namesize;
                }
                else
                {
                    *name_size = (U32) namesize;
                    memcpy(p_name, app_name_list, namesize);
                }

                if (app_name_list)
                {
                    vm_free(app_name_list);
                }

                return MMI_TRUE;
            }
            else
            {
                return MMI_FALSE;
            }}
    }
    else
#endif
    {
        ret = srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_NAME, p_name, name_size, VM_LANG_NULL);
    }
    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_zimo_data
* DESCRIPTION
*  Parser the source resource data and get the zimo data beginning pointer from source buffer.
* PARAMETERS
*  source : [IN]  Source data.
*  data_buf : [OUT]  Zimo data beginning pointer.
*  lan_type : [IN]  Language type.
*  data_len : [OUT]  Length of the zimo name.
*  font_h : [OUT]  Font height.
*  data_size : [OUT]  Size of the zimo data.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
static MMI_BOOL srv_mre_get_app_zimo_data(
    U8 *source,
    U8 **data_buf,
    srv_mre_lan_type_enum lan_type,
    S32 *data_len,
    /* name length */ S32 *font_h,
    S32 *data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_dat_sz, zm_dat_sz;
    S32 offset = 13;
    srv_mre_lan_type_enum language = SRV_MRE_LAN_ENG;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (source == NULL)
        return MMI_FALSE;

    icon_dat_sz = *(source + offset + 6) +
        ((*(source + offset + 7)) << 8) + ((*(source + offset + 8)) << 16) + ((*(source + offset + 9)) << 24);

    offset = 23 + icon_dat_sz;  /* start addr of matrix */

    /* jump to the addr of specified language matrix */
    while (language < lan_type)
    {
        zm_dat_sz = *(source + offset + 8) +
            ((*(source + offset + 9)) << 8) + ((*(source + offset + 10)) << 16) + ((*(source + offset + 11)) << 24);
        offset += (12 + zm_dat_sz);
        language++;
    }

    if (offset <= 0 || offset > 10000) /* 10000: XP */
        return MMI_FALSE;

    /* get info */
    *data_len = *(source + offset + 5) + ((*(source + offset + 6)) << 8);
    *font_h = *(source + offset + 7);

    zm_dat_sz = *(source + offset + 8) +
        ((*(source + offset + 9)) << 8) + ((*(source + offset + 10)) << 16) + ((*(source + offset + 11)) << 24);

    if (zm_dat_sz <= 0 || zm_dat_sz > 1000) /* 1000: XP */
        return MMI_FALSE;

    *data_size = zm_dat_sz;

    *data_buf = (VMUINT8*) (source + offset + 12);
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_zimo_name
* DESCRIPTION
*  Get the zimo name of a MRE application. If zimo_buf is NULL, then return the name size by name_size.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  zimo_buf : [OUT] Pointer to name buffer.
*  name_size : [OUT] Size of name.
*  name_len : [OUT] Length of name.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_app_zimo_name(U16 *app_path, S8 *zimo_buf, U32 *name_size, U32 *name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    srv_mre_load_core_result_enum load_mre_core_ret;
    U8 *res_buf;
    S32 res_size;
    MMI_BOOL zimo_ret = MMI_FALSE;
    S8 *temp_zimo_buf;
    U8 *lang = NULL;
    srv_mre_lan_type_enum language = SRV_MRE_LAN_ENG;
    S32 font_height;
    S32 chset_type_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_path == NULL || name_size == NULL || name_len == NULL)
    {
        return MMI_FALSE;
    }

    /* Load MRE Core */
    if (!srv_mre_is_core_loaded())
    {
        load_mre_core_ret = srv_mre_load_core(NULL, SRV_MRE_CALLER_SERVICE);
        if (load_mre_core_ret != SRV_MRE_LOAD_CORE_SUCCESS)
        {
            return MMI_FALSE;
        }
    }

    // TODO: only support MRE3.0; do not support MRE2.0

    lang = Get_Current_Lang_CountryCode();
    if (strcmp((PS8) lang, "en-US") == 0)   /* means english */
    {
        language = SRV_MRE_LAN_ENG;
    }
    else if (strcmp((PS8) lang, "zh-CN") == 0)
    {
        language = SRV_MRE_LAN_CHS;
    }
    else if (strcmp((PS8) lang, "zh-TW") == 0)
    {
        language = SRV_MRE_LAN_CHT;
    }

    /* Load resource */
    //res_buf = vm_load_resource_from_file((PS16) app_path, SRV_MRE_APP_LOGO, &res_size);
    if (vm_get_vm_tag((PS16) app_path, VM_CE_INFO_CHARSET, NULL, &chset_type_size) == GET_TAG_TRUE)
    {
        res_buf = vm_load_resource_from_file((PS16) app_path, SRV_MRE_APP_NEW_LOGO, &res_size);
    }
    else
    {
        res_buf = vm_load_resource_from_file((PS16) app_path, SRV_MRE_APP_LOGO, &res_size);
    }
    if (!res_buf)
    {
        ret = MMI_FALSE;
    }
    else
    {
        zimo_ret = srv_mre_get_app_zimo_data(
            res_buf,
            (U8 **) & temp_zimo_buf,
            language,
            (S32*) name_len,
            &font_height,
            (S32*) name_size);
        // if get CHT or CHS zimo data failed ,we get ENG zimo data again.
        if (!zimo_ret && ( language == SRV_MRE_LAN_CHT || language == SRV_MRE_LAN_CHS) )
        {
            zimo_ret = srv_mre_get_app_zimo_data(
                res_buf,
                (U8 **) & temp_zimo_buf,
                SRV_MRE_LAN_ENG,
                (S32*) name_len,
                &font_height,
                (S32*) name_size);
            if(!zimo_ret)	// if get ENG zimo data failed ,return FALSE
            {
                ret = MMI_FALSE;
            }
            else
            {
                if (zimo_buf == NULL) // rom app 
                {
                    ret = MMI_TRUE;
                }
                else    // not rom app
                {
                    memcpy(zimo_buf, temp_zimo_buf, *name_size);
                    ret = MMI_TRUE;
                }
            }
        }
        else	// get setting'a language zimo data success.
        {
            if (zimo_buf == NULL)   /* get name size */
            {
                ret = MMI_TRUE;
            }
            else    /* get name data */
            {
                memcpy(zimo_buf, temp_zimo_buf, *name_size);
                ret = MMI_TRUE;
            }
        }

        vm_free(res_buf);
    }

    /* Unload MRE Core */
    srv_mre_unload_core(SRV_MRE_CALLER_SERVICE);
    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_version
* DESCRIPTION
*  Get the version id of a MRE application. The version id use format x.y.z which present by a U32.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  version : [OUT] Version id, first byte is x, second byte is y, third byte is z.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_app_version(U16 *app_path, S32 *version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 version_size;
    S8 tag_buf[4];
    S8 temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (version == NULL)
    {
        return MMI_FALSE;
    }

    if (srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_VER, tag_buf, &version_size, VM_LANG_NULL))
    {
        temp = tag_buf[0];
        tag_buf[0] = tag_buf[3];
        tag_buf[3] = temp;
        temp = tag_buf[1];
        tag_buf[1] = tag_buf[2];
        tag_buf[2] = temp;
        *version = *((S32*) tag_buf);
    }

    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_id
* DESCRIPTION
*  Get the id of a MRE application. The id uses 32-bits.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  p_id : [OUT] Pointer to id buffer.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_app_id(U16 *app_path, U32 *p_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U32 id_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p_id == NULL)
    {
        return MMI_FALSE;
    }

    ret = srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_APP_ID, p_id, &id_size, VM_LANG_NULL);
    if (ret == MMI_TRUE && id_size == 4)
    {
        ret = MMI_TRUE;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_developer
* DESCRIPTION
*  Get the developer name of a MRE application. If p_developer is NULL, then return the name size by developer_size.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  p_developer : [OUT] Pointer to developer name buffer.
*  developer_size : [OUT] Size of developer name.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_app_developer(U16 *app_path, U16 *p_developer, U32 *developer_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_DEV, p_developer, developer_size, VM_LANG_NULL);
    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_description
* DESCRIPTION
*  Get the description of a MRE application. If p_desc is NULL, then return the description size by desc_size.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  p_desc : [OUT] Pointer to app description buffer.
*  desc_size : [OUT] Size of app description.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_app_description(U16 *app_path, U16 *p_desc, U32 *desc_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_DESC, p_desc, desc_size, VM_LANG_NULL);
    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_tel
* DESCRIPTION
*  Get the telephone number of the developer.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  p_tel : [OUT] Pointer to telephone number buffer, and the length of number less than 20.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_app_tel(U16 *app_path, U16 *p_tel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U32 tel_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p_tel == NULL)
    {
        return MMI_FALSE;
    }
    ret = srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_TEL, p_tel, &tel_size, VM_LANG_NULL);
    return ret;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_resolution
* DESCRIPTION
*  Get resolution
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  width : [OUT] width.
*  height : [OUT] height.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_app_resolution(U16 *app_path, U16 *width, U16 *height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U32 value;
    S32 size = 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_get_vm_tag((PS16) app_path, VM_CE_INFO_RESOLUTION_REQ, (void*)&value, &size))
    {
        *height = value&0x0000ffff;
        *width = value >> 16;
        return MMI_TRUE;
    }
    return ret;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_get_app_resolution
* DESCRIPTION
*  Get resolution
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  type : [OUT] type.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_app_type(U16 *app_path, U32 *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    S32 size = 4;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (GET_TAG_TRUE == vm_get_vm_tag((PS16) app_path, VM_CE_INFO_VPP_TYPE, (void*)type, &size))
    {
        return MMI_TRUE;
    }
    return ret;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_is_app_bg_running
* DESCRIPTION
*  Check if the application is running in background.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
* RETURN VALUES
*  MMI_TRUE : If support.
*  MMI_FALSE : If not support.
*****************************************************************************/
MMI_BOOL srv_mre_is_app_bg_running(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = vm_vam_app_is_running((PS16) app_path);       // TODO: Is MRE Core required by this api?
    MMI_TRACE(MMI_MRE_TRC_G2_SERVICE, TRC_MRE_SERVICE_IS_APP_BG_RUNNING, ret);

    if (ret == TRUE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


VM_PROCESS_STATUS srv_mre_check_app_status_by_name(U16 *name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables 											   */
    /*----------------------------------------------------------------*/
    VM_PROCESS_STATUS status = VM_PMNG_MAX_NUM;

    /*----------------------------------------------------------------*/
    /* Code Body													   */
    /*----------------------------------------------------------------*/
    if (!name || name[0] == 0)
        return status;

    if ((vm_sh_pcb_in_pt(SH_TYPE_FILENAME, (VMINT)name, &status)) != NULL)
    {
        return status;
    }
    return status;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_is_app_support_bg_running
* DESCRIPTION
*  Check if the application support background running.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
* RETURN VALUES
*  MMI_TRUE : If support.
*  MMI_FALSE : If not support.
*****************************************************************************/
MMI_BOOL srv_mre_is_app_support_bg_running(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U32 tag_size;
    S32 tag_buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_mre_get_info_by_tag(app_path, SRV_MRE_INFO_BG_RUN, &tag_buf, &tag_size, VM_LANG_NULL);
    if (ret == MMI_TRUE && tag_buf == 1)
    {
        ret = MMI_TRUE;
    }
    else
    {
        ret = MMI_FALSE;
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_multi_info
* DESCRIPTION
*  Get multiple information from file or rom.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
*  tag : [IN] Tag type.
*  des_buf : [OUT] Destination buffer.
*  des_size : [OUT] Destination buffer size.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
MMI_BOOL srv_mre_get_multi_info(U16 *app_path, srv_mre_multi_info_struct *info_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // TODO: support in the next version
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_buildin_app_list
* DESCRIPTION
*  Get build-in application full path list. The length of the full path will be less than 20.
*  You should get call srv_mre_get_buildin_app_list(NULL, app_num) firstly to get application number,
*  and then prepare enough memory to get the list.
* PARAMETERS
*  app_path_list : [IN]  List of build in application full path.
*  app_num : [OUT]  Number of build in application.
* RETURNS
*  Return number of build in applications
*****************************************************************************/
U32 srv_mre_get_buildin_app_list(U16 **app_path_list, U32 *app_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 appcount, smcount, socount;
    S8 rom_app_path[20];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_init_default_game(&appcount, &smcount, &socount);

    if (appcount <= 0)
    {
        *app_num = 0;
    }
    else
    {
        *app_num = appcount;   /* app number */
        if (app_path_list)
        {
            S32 i;

            for (i = 0; i < appcount; i++)
            {
                // memset(rom_app_path, 0, sizeof(rom_app_path));
                sprintf(rom_app_path, "%c:\\%u.rom", SRV_MRE_ROM_DIR, *(mre_buildin_app_array + i));

                mmi_asc_to_wcs((PU16) app_path_list[i], rom_app_path);
            }
        }
    }
    //#endif /* WIN32 */ 
    return *app_num;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_is_buildin_app
* DESCRIPTION
*  Check if the app is build-in application.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
* RETURN VALUES
*  MMI_TRUE : If it is a build-in application.
*  MMI_FALSE : If it is not a build-in application.
*****************************************************************************/
extern MMI_BOOL srv_mre_is_buildin_app(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_parse_exec_format((VMWSTR)app_path) == VM_EXEC_ROM)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  srv_mre_is_using_media_buffer
* DESCRIPTION
*  Check if MRE using media buffer.
* PARAMETERS
*  void
* RETURN VALUES
*  MMI_TRUE : If using media buffer.
*  MMI_FALSE : If not using media buffer.
*****************************************************************************/
MMI_BOOL srv_mre_is_using_media_buffer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sysconf.memory_provide == MMI_DEVCONFIG_MEMPEY_PROVIDER_MEDIA)
    {
        return (MMI_BOOL)mre_running;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_mre_is_app_valid
* DESCRIPTION
*  Check if the application is valid.
* PARAMETERS
*  app_path : [IN]  MRE application full path.
* RETURN VALUES
*  
*****************************************************************************/
U32 srv_mre_is_app_valid(U16 *app_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mre_load_core_result_enum load_mre_core_ret;
    VMUCHAR *ce_digest_buffer = NULL;
    VMINT ce_digest_buffer_len = (10 * 1024);   // TODO: Why is it so big?
    S32 rescode = VM_CE_VERIFY_OK;
    //S32 ret = VM_CE_VERIFY_BAD_PARAM;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check parameter */
    if (app_path == NULL)
    {
        return rescode+15;
    }

    /* Load MRE Core */
    if (!srv_mre_is_core_loaded())
    {
        load_mre_core_ret = srv_mre_load_core(NULL, SRV_MRE_CALLER_SERVICE);
        if (load_mre_core_ret != SRV_MRE_LOAD_CORE_SUCCESS)
        {
            return VM_PER_MEM_ERROR+15;
        }
    }

    ce_digest_buffer = (VMUCHAR*) vm_malloc(ce_digest_buffer_len);
    if (ce_digest_buffer != NULL)
    {
#ifdef __MRE_CORE_SAFETY__
        rescode = vm_ce_auth_app_ex((VMWSTR) app_path, ce_digest_buffer, ce_digest_buffer_len,VERIFY_FULL);
#else
        rescode = VM_CE_VERIFY_OK;//VM_CE_VERIFY_VERIFY_FAILED;
#endif
        /* switch (rescode)
        {
        case VM_CE_VERITY_INSUFFICIENT_SYS_MEM://-15
        ret = SRV_MRE_VERITY_INSUFFICIENT_SYS_MEM;//0
        break;
        case VM_CE_VERIFY_KEY_EXPIRED://-14
        ret = SRV_MRE_VERIFY_KEY_EXPIRED;// 1
        break;
        case VM_CE_CHECK_PARAM_FAIL:// -13
        ret = SRV_MRE_VERIFY_CHECK_PARAM_FAIL;// 2
        break;
        case VM_PER_MEM_ERROR: //-12
        ret = SRV_MRE_VERIFY_PER_MEM_ERROR; // 3
        break;
        case VM_PER_INIT_ERROR://-11
        ret = SRV_MRE_VERIFY_PER_INIT_ERROR;//4  
        break;
        case VM_PER_CATCH_ERROR:// -10
        ret = SRV_MRE_VERIFY_PER_CATCH_ERROR;
        break;
        case VM_CE_VERIFY_RESOLUTION_DISMATCH://-9
        ret = SRV_MRE_VERIFY_RESOLUTION_DISMATCH;
        break;
        case VM_CE_VERIFY_INSUFFICIENT_MEM://-8
        ret = SRV_MRE_VERIFY_INSUFFICIENT_MEM;
        break;
        case VM_CE_VERIFY_TIMESTAMP_ERROR://-7
        ret = SRV_MRE_VERIFY_TIMESTAMP_ERROR;
        break;
        case VM_CE_VERIFY_IMSI_DISMATCH://-6
        ret = SRV_MRE_VERIFY_IMSI_DISMATCH;
        break;
        case VM_CE_VERIFY_APP_BANNED://-5
        ret = SRV_MRE_VERIFY_APP_BANNED;
        break;
        case VM_CE_VERIFY_DIGEST_DISMATCH://-4
        ret = SRV_MRE_VERIFY_DIGEST_DISMATCH;
        break;
        case VM_CE_VERIFY_VERIFY_FAILED://-3
        ret = SRV_MRE_VERIFY_VERIFY_FAILED;
        break;
        case VM_CE_VERIFY_BAD_DIGEST://-2
        ret = SRV_MRE_VERIFY_BAD_DIGEST;
        break;
        case VM_CE_VERIFY_BAD_PARAM://-1
        ret = SRV_MRE_VERIFY_BAD_PARAM;
        break;
        case VM_CE_VERIFY_OK://0
        ret = SRV_MRE_VERIFY_OK;
        break;
        default:
        ret = SRV_MRE_VERIFY_BAD_PARAM;
        break;
        }*/

        vm_free((void*)ce_digest_buffer);
    }

    /* Unload MRE Core */
    srv_mre_unload_core(SRV_MRE_CALLER_SERVICE);
    return rescode+15;/*15 is the |VM_CE_VERITY_INSUFFICIENT_SYS_MEM|*/
}


/*****************************************************************************
* FUNCTION
*  srv_mre_is_first_load_core
* DESCRIPTION
*  Check if it is the first time to load MRE Core.
* PARAMETERS
*  void
* RETURN VALUES
*  MMI_TRUE : If it is the first time.
*  MMI_FALSE : If it is not the first time.
*****************************************************************************/
MMI_BOOL srv_mre_is_first_load_core(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_nvram_get_firstflag() == 0XFF)
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
*  srv_mre_get_bg_app_num
* DESCRIPTION
*  get the number of background running app.
* PARAMETERS
*  void
* RETURN VALUES
*  background running app number
*****************************************************************************/
U32 srv_mre_get_bg_app_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32* pHandle = NULL;
    U32  number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_pmng_get_process_lst(VM_PMNG_BACKGROUND, (VM_P_HANDLE**)&pHandle, &number) == VM_PMNG_OP_OK)
    {
        if (number > 0)
        {
            _vm_kernel_free(pHandle);
        }
        return number;        
    }
    else
    {
        return 0;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_mre_get_bg_filename
* DESCRIPTION
*  get the background running file name of specified index
* PARAMETERS
*  index : [IN] the index of background running application to be checked.
*  filename : [OUT] the file name of specified index of background running application.
*  size : [IN] the buffer size of the parameter of filename
* RETURN VALUES
*  MMI_TRUE : get file name successfully
*  MMI_FALSE : there is no background running application of specified index
*****************************************************************************/
MMI_BOOL srv_mre_get_bg_filename(U32 index, U16* filename, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32* pHandle = NULL;
    U32  number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_pmng_get_process_lst(VM_PMNG_BACKGROUND, (VM_P_HANDLE**)&pHandle, &number) == VM_PMNG_OP_OK)
    {
        if ((index < number) && (number > 0))
        {            
            vm_pmng_file_name(*(pHandle + index), (VMWCHAR*)filename, size);
            _vm_kernel_free(pHandle);
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}

/***************************************************************************** 
* application communication service apis
*****************************************************************************/


/*****************************************************************************
* FUNCTION
*  srv_mre_get_running_handle
* DESCRIPTION
*  get process handle of specified file name
* PARAMETERS
*  handle : [IN] file name to be checked. 
* RETURNS
*  the process ID of specified file if larger than zero, 0 means there is no specified file running 
*****************************************************************************/
S32 srv_mre_get_running_handle(WCHAR * file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_pmng_get_handle((VMWSTR)file_name);
}


/*****************************************************************************
* FUNCTION
*  srv_mre_reg_msg_proc
* DESCRIPTION
*  register MRE message proc
* PARAMETERS
*  handle : [IN] message sender handle, if despite of sender, this parameter should be set to zero.
*  proc : [IN] message proc
* RETURNS
*  1 if register successfully
*  0 if register failed
*****************************************************************************/
S32 srv_mre_reg_msg_proc(S32 handle, SRV_MRE_MSG_PROC proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_appcomm_reg_msg_proc(handle, (VM_MESSAGE_PROC)proc);
}


/*****************************************************************************
* FUNCTION
*  srv_mre_dereg_msg_proc
* DESCRIPTION
*  deregister MRE message proc
* PARAMETERS
*  handle : [IN] message sender handle, if despite of sender, this parameter should be set to zero.
*  proc : [IN] message proc
* RETURNS
*  1 if deregister successfully
*  0 if deregister failed
*****************************************************************************/
S32 srv_mre_dereg_msg_proc(S32 handle, SRV_MRE_MSG_PROC proc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return vm_appcomm_dereg_msg_proc(handle, (VM_MESSAGE_PROC)proc);
}


/*****************************************************************************
* FUNCTION
*  srv_mre_send_msg
* DESCRIPTION
*  send message to MRE app or native app, will invoke message procedure directly.
* PARAMETERS
*  phandle : [IN] receiver process handle, if receiver is native application, this value should be zero.
*  msg_id : [IN] user defined message ID, should larger than VM_MESSAGE_ID_BASE.
*  wparam : [IN] wparam of message.
*  lparam : [IN] lparam of message.
* RETURNS
*  message procedure return value.
*****************************************************************************/
S32 srv_mre_send_msg(S32 handle, U32 msg_id, S32 wparam, S32 lparam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_appcomm_send_msg(handle, msg_id, wparam, lparam);
    return 0;
}


/*****************************************************************************
* FUNCTION
*    srv_mre_post_msg
* DESCRIPTION
*  post message to MRE app or native app, will put this message to the end of MRE message queue. 
*  when this function call finish, MMI task will dispatch MRE message and invoke message procedure. 
* PARAMETERS
*  phandle : [IN] receiver process handle, if receiver is native application, this value should be zero.
*  msg_id : [IN] user defined message ID, should larger than VM_MESSAGE_ID_BASE.
*  wparam : [IN] wparam of message.
*  lparam : [IN] lparam of message.
* RETURNS
*  message procedure return value.
*****************************************************************************/
S32 srv_mre_post_msg(S32 handle, U32 msg_id, S32 wparam, S32 lparam)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_appcomm_post_msg(handle, msg_id, wparam, lparam);
    return 0;

}

/*****************************************************************************
* FUNCTION
*  srv_mre_get_group_id
* DESCRIPTION
*  Get the screen group id of current MRE App
* RETURNS
*  Screen group id of current MRE App
*****************************************************************************/
U32 srv_mre_get_group_id(void)
{
    return GRP_ID_MRE_CORE;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_set_venus_flag
* DESCRIPTION
*  set Venus flag of MRE app, MRE will trigger key and pen handler even if app is background running
*****************************************************************************/
void srv_mre_set_venus_flag(void)
{
    vm_pmng_set_venus_flag();
}

/*****************************************************************************
* FUNCTION
*  srv_mre_get_res_base
* DESCRIPTION
*  Get the MMI resource base of current MRE App
* RETURNS
*  MMI resource base of current MRE App
*****************************************************************************/
U32 srv_mre_get_res_base(void)
{
    return MRE_BASE;
}

/*****************************************************************************
* FUNCTION
*  srv_mre_get_ua_string
* DESCRIPTION
*  Get MRE ua string
* RETURNS
*  string length
*****************************************************************************/
typedef struct
{
    VMSTR sp_name;
    VMINT sp_id;
}sp_data;

extern sp_data sp_id_array[];

U32 srv_mre_get_ua_string(char *buff, U32 size)
{
    char str[512] = "";
    U32 i = 0;
    mmi_devconfig_system_config_struct config;


    memset(&config,0,sizeof(config));
    mmi_devconfig_get_system_config(&config);

    sprintf(str,"MRE/%d.%d.%02d(%d);",MRE_VERSION/1000,(MRE_VERSION%1000)/100,MRE_VERSION%100,config.memory_size>>10);
    sprintf(str+strlen(str),"MAUI/%s;",release_verno()+5);
    sprintf(str+strlen(str),"BDATE/%s;",build_date_time());
    sprintf(str+strlen(str),"LCD/%d%d;",LCD_WIDTH,LCD_HEIGHT);
    sprintf(str+strlen(str),"CHIP/%s;",PLATFORM);

    strcat(str,"KEY/");

    if (MMI_DEVCONFIG_KEYPAD_TYPE_NORMAL == config.input_device.keypad_type)
    {
        strcat(str,"Normal;");
    }
    else if (MMI_DEVCONFIG_KEYPAD_TYPE_REDUCED == config.input_device.keypad_type)
    {
        strcat(str,"Reduced;");
    }
    else if (MMI_DEVCONFIG_KEYPAD_TYPE_QWERTY == config.input_device.keypad_type)
    {
        strcat(str,"QWERT;");
    }


    sprintf(str+strlen(str),"TOUCH/%d;",config.input_device.figner_touch_support);
    //   sprintf(str+strlen(str),"tpannel\\%d ",config.input_device.touch_screen);    
    sprintf(str+strlen(str),"CAMERA/%d;",config.camera_device.camera_support);
    sprintf(str+strlen(str),"SENSOR/%d;",config.remote_sensing.motion_sensor);

    sprintf(str+strlen(str),"DEV/%s;",release_hw_ver());
#if defined(PGDL_SUPPORT) && defined(WAP_SEC_SUPPORT)   
    strcat(str,"WAP Browser/MAUI (HTTP PGDL;HTTPS)");
#elif defined(PGDL_SUPPORT)
    strcat(str,"WAP Browser/MAUI (HTTP PGDL)");
#elif defined(WAP_SEC_SUPPORT)
    strcat(str,"WAP Browser/MAUI (HTTPS)");
#else
    strcat(str,"WAP Browser/MAUI ()");
#endif

    while (sp_id_array[i].sp_name != NULL)
    {
        sprintf(str+strlen(str),";%s/%03d",sp_id_array[i].sp_name,sp_id_array[i].sp_id);
        i++;
    }

    if (NULL == buff)
    {
        return strlen(str);
    }

    strncpy(buff,str,size);
    return strlen(buff);
}

typedef struct 
{
    vm_srv_dtcnt_info_t info;
    VMINT is_set;

}vm_srv_dtcnt_info_int_t;

static vm_srv_dtcnt_info_int_t g_dtcnt_cust_info;
const vm_srv_dtcnt_info_t * srv_mre_get_cust_dtcnt_info(void)
{
    return &g_dtcnt_cust_info.info;
}

