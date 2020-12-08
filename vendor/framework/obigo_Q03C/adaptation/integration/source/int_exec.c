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
 *
 * Filename:
 * ---------
 *  int_exec.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file handles the creation and exection of Obigo framework
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
#include "kal_public_api.h"        /* Basic data type */
#include "kal_public_defs.h"
#include "stack_ltlcom.h" /* Task message communiction */
#include "wap_ps_struct.h"
#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "stack_ltlcom.h"

#include "msm_int.h"

#include "msm_env.h"
#include "msf_errc.h"

#ifdef MSF_MODID_MMS
#include "mms_env.h"
#endif
/*#ifdef MSF_MODID_SLS
#include "sls_env.h"
#endif*/
#ifdef MSF_MODID_MMA
#include "mma_api.h"    /* for the error of storage type enum in mma_def.h */
#include "mma_def.h"
#include "mma_env.h"
#endif
#ifdef MSF_MODID_NTS
#include "nts_env.h"
#endif    
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "msm.h"
#ifdef MSF_MODID_WIDGET
#include "widget.h"
#endif
#ifdef MSF_MODID_DAS
#include "das_env.h"
#endif
#ifdef WAP_SEC_SUPPORT
#include "sec_env.h"
#endif 
#ifdef MSF_MODID_STK
#include "stk_env.h"
#endif 
#ifdef WPS_SUPPORT
#include "wps_env.h"
#endif 
#ifdef __WAP_PUSH_SUPPORT__
#ifdef MSF_MODID_PHS
#include "phs_env.h"
#endif 
#ifdef MSF_MODID_PMG
#include "pmg_env.h"
#endif 
#endif
#ifdef MSF_MODID_BAM
#include "bam_env.h"
#endif

#ifdef MSF_MODID_BRS
#include "brs_env.h"
#endif
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
#include "kal_trace.h"
#include "gv.h"
#include "tst_def.h"

#include "mms_exec.h"
#include "int_cmmn.h"
#include "int_timer.h"
#include "int_exec.h"
#include <stdarg.h>
#include <stdio.h>

/*#include "rtc_sw.h"*/
#include "app_datetime.h"

#include <time.h>

static int current_mod_id;
static int mms_current_mod_id;

kal_uint8 mms_status = MMS_STATUS_NULL;
int mms_action;
pfAction mms_ready_cb;

#ifndef Q03C_IND_MOD_ARCH_SUPPORT
ExModuleDescr msf_modules[MSF_NUMBER_OF_MODULES] = 
{
    {MSF_MODID_MSM, "MSM", HDI_STARTUP_STATIC, TRACE_FUNC, NULL, MSMc_wantsToRun, MSMc_run, NULL, 0, 0},
#ifdef MSF_MODID_MMS
    {MSF_MODID_MMS, "MMS", HDI_STARTUP_STATIC, TRACE_GROUP_4, MMSc_start, MMSc_wantsToRun, MMSc_run, MMSc_kill, NULL, 0, 0},
#endif
/*#ifdef MSF_MODID_SLS
    {MSF_MODID_SLS, "SLS", HDI_STARTUP_DYNAMIC, TRACE_GROUP_6, SLSc_start, SLSc_wantsToRun, SLSc_run, SLSc_kill, NULL, 0, 0},
#endif*/
#ifdef MSF_MODID_MMA
    {MSF_MODID_MMA, "MMA", HDI_STARTUP_STATIC, TRACE_GROUP_8, MMAc_start, MMAc_wantsToRun, MMAc_run, MMAc_kill, mma_msg_hdlr, 0, 0},
#endif
#ifdef MSF_MODID_ASM
    {MSF_MODID_ASM, "ASM", HDI_STARTUP_DYNAMIC, TRACE_GROUP_8, ASMc_start, ASMc_wantsToRun, ASMc_run, ASMc_kill, NULL, 0, 0},
#endif
#ifdef MSF_MODID_NTS
    {MSF_MODID_NTS, "NTS", HDI_STARTUP_STATIC, TRACE_GROUP_3, NTSc_start, NTSc_wantsToRun, NTSc_run, NTSc_kill, nts_msg_hdlr, 0, 0},
#endif
#ifdef MSF_SUPPORT_EXT_MODULE
    {MSF_MODID_EXT, "EXT", HDI_STARTUP_DYNAMIC, TRACE_GROUP_3, NULL, NULL, NULL, NULL, NULL, 0, 0},
#endif
};

#else
#ifdef WAP_QUEUE_SMS_PUSH
#define WAP_WAIT_SMS_NOTIFY_TIMEOUT 50
#endif 

ExModuleDescr msf_modules[MSF_NUMBER_OF_MODULES] = 
{
    {MSF_MODID_MSM, MOD_WAP, "MSM", HDI_STARTUP_STATIC, WAP_MEM_POOL, TRACE_FUNC, NULL, MSMc_wantsToRun, MSMc_run, NULL, 0, 0},

#ifdef MSF_MODID_STK
    {MSF_MODID_STK, MOD_WPS, "STK", HDI_STARTUP_STATIC, WAP_MEM_POOL, TRACE_STATE, STKc_start, STKc_wantsToRun, STKc_run, STKc_kill, NULL, 0, 0},
#endif

#ifdef MSF_MODID_SEC
    {MSF_MODID_SEC, MOD_WPS, "SEC", HDI_STARTUP_STATIC, WAP_MEM_POOL, TRACE_GROUP_1, SECc_start, SECc_wantsToRun, SECc_run, SECc_kill, NULL, 0, 0},
#endif

#ifdef MSF_MODID_WPS
    {MSF_MODID_WPS, MOD_WPS, "WPS", HDI_STARTUP_STATIC, WAP_MEM_POOL, TRACE_GROUP_5, WPSc_start, WPSc_wantsToRun, WPSc_run, WPSc_kill, NULL, 0, 0},
#endif

#ifdef MSF_MODID_WIDGET
    {MSF_MODID_WIDGET, MOD_WAP, "WDG", HDI_STARTUP_STATIC, WAP_MEM_POOL, TRACE_GROUP_9, WIDGETc_start, WIDGETc_wantsToRun, WIDGETc_run, WIDGETc_kill, NULL, 0, 0},
#endif
#ifdef __WAP_PUSH_SUPPORT__
#ifdef MSF_MODID_PHS
    {MSF_MODID_PHS, MOD_WPS, "PHS", HDI_STARTUP_STATIC, WAP_MEM_POOL, TRACE_ERROR, PHSc_start, PHSc_wantsToRun, PHSc_run, PHSc_kill, NULL, 0, 0},
#endif

#ifdef MSF_MODID_PMG
    {MSF_MODID_PMG, MOD_WPS, "PMG", HDI_STARTUP_STATIC, WAP_MEM_POOL, TRACE_GROUP_2, PMGc_start, PMGc_wantsToRun, PMGc_run, PMGc_kill, NULL, 0, 0},
#endif
#endif
#ifdef MSF_MODID_MMS
    {MSF_MODID_MMS, MOD_MMS, "MMS", HDI_STARTUP_STATIC, WAP_MEM_POOL, TRACE_GROUP_4, MMSc_start, MMSc_wantsToRun, MMSc_run, MMSc_kill, NULL, 0, 0},
#endif

/*#ifdef MSF_MODID_SLS
    {MSF_MODID_SLS, MOD_MMS, "SLS", HDI_STARTUP_DYNAMIC, WAP_MEM_POOL, TRACE_GROUP_6, SLSc_start, SLSc_wantsToRun, SLSc_run, SLSc_kill, NULL, 0, 0},
#endif*/

#ifdef MSF_MODID_MMA
    {MSF_MODID_MMA, MOD_MMS, "MMA", HDI_STARTUP_STATIC, WAP_MEM_POOL, TRACE_GROUP_8, MMAc_start, MMAc_wantsToRun, MMAc_run, MMAc_kill, mma_msg_hdlr, 0, 0},
#endif

#ifdef MSF_MODID_ASM
    {MSF_MODID_ASM, MOD_WAP, "ASM", HDI_STARTUP_DYNAMIC, MMS_V02_APP_MEM_POOL, TRACE_GROUP_8, ASMc_start, ASMc_wantsToRun, ASMc_run, ASMc_kill, NULL, 0, 0},
#endif
#ifdef MSF_SUPPORT_EXT_MODULE
    {MSF_MODID_EXT, MOD_WPS, "EXT", HDI_STARTUP_DYNAMIC, WAP_MEM_POOL, TRACE_GROUP_2, NULL, NULL, NULL, NULL, NULL, 0, 0},
#endif


#ifdef MSF_MODID_BRS
    {MSF_MODID_BRS, MOD_WAP, "BRS", HDI_STARTUP_DYNAMIC, 
#ifdef WAP_USE_ASM        
        WAP_APP_MEM_POOL, 
#else
        WAP_MEM_POOL,
#endif        
        TRACE_INFO, BRSc_start, BRSc_wantsToRun, BRSc_run, BRSc_kill, NULL, 0, 0},   
#endif

#ifdef MSF_MODID_DAS
    {MSF_MODID_DAS, MOD_WAP, "DAS", HDI_STARTUP_STATIC, WAP_MEM_POOL, TRACE_GROUP_3, DASc_start, DASc_wantsToRun, DASc_run, DASc_kill, NULL, 0, 0},
#endif

#ifdef MSF_MODID_BAM
    {MSF_MODID_BAM, MOD_WAP, "BAM", HDI_STARTUP_STATIC, WAP_MEM_POOL, TRACE_WARNING, BAMc_start, BAMc_wantsToRun, BAMc_run, BAMc_kill, NULL, 0, 0},
#endif

};
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

static void *msm_timer_event_id = NULL;
kal_uint32 msf_mod_init_mask = (1 << MSF_MODID_MSM);

int mms_msf_mod_is_ready(void)
{
    return (msf_mod_init_mask == 0);
}

int mms_msf_mod_is_init(void)
{
    return (msf_mod_init_mask != 0 && mms_status != MMS_STATUS_NULL && mms_status != MMS_STATUS_TERMINATED);
}

int msf_no_of_modules(void)
{			
	return MSF_NUMBER_OF_MODULES;
}

#ifdef OBIGO_Q03C_MMS_V02
/*****************************************************************************
 * FUNCTION
 *  mms_init_framework
 * DESCRIPTION
 *  Initialization of WPS task.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_init_framework(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
    init_hdi_mem();
    init_hdi_pipe();
    init_hdi_file();
    init_hdi_signal();
    init_mms_timer();
#endif
    return;
}


/*****************************************************************************
 * FUNCTION
 *  init_framework
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
int mms_start_framework(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const char *startOptions = "-r dummy";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_status = MMS_STATUS_CREATED;
    
    MSMc_startMobileSuite(startOptions);
    
    msf_modules[MSF_MODID_MSM].isActive = 1;

    run_mms_task();

    return 1;
}


void mms_stop_framework(void)
{
    ASSERT(mms_status != MMS_STATUS_SHUTTING_DOWN);
    
    mms_status = MMS_STATUS_SHUTTING_DOWN;

    MSMc_terminateMobileSuite();
}

/*
 *  Call this function to let the modules run
 */


/*****************************************************************************
 * FUNCTION
 *  execute_framework
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mms_execute_framework(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int hasExecuted = 0;
    int i;
    
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
        extern int isSignalPending(module_type mod_id);
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!msf_modules[MSF_MODID_MSM].isActive)
    {
        return;
    }

    for (i = 0; i < MSF_NUMBER_OF_MODULES; i++)
    {

		
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
        if (((msf_modules[i].taskId == MOD_MMS))&& msf_modules[i].isActive)
#else
        if (msf_modules[i].isActive)
#endif
        {
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
            mms_current_mod_id = msf_modules[i].moduleId;
#else
            current_mod_id = msf_modules[i].moduleId;
#endif
            
            if (msf_modules[i].pTaskWantsToRun())
            {
                msf_modules[i].pTaskRun();
                hasExecuted = 1;
            }
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
            mms_current_mod_id = -1;
#else
            current_mod_id = -1;
#endif
            
        }
    }
    

		

    if (hasExecuted && msf_modules[MSF_MODID_MSM].isActive)
    {
        /* check if modules wants to run more */
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
        extern int isSignalPending(module_type mod_id);
        if (isSignalPending(MOD_MMS))
#endif
        run_mms_task();
    }
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
    if (isSignalPending(MOD_WAP))
    {
        extern void hdi_notify_task(module_type src, module_type dst, msg_type msg_id);
        
        hdi_notify_task(MOD_MMS, MOD_WAP, MSG_ID_WAP_STATUS_UPDATE_IND);
    }
    if (isSignalPending(MOD_WPS))
    {
        extern void hdi_notify_task(module_type src, module_type dst, msg_type msg_id);
        
        hdi_notify_task(MOD_MMS, MOD_WPS, MSG_ID_WAP_STATUS_UPDATE_IND);
    }
#endif
}
#endif /*OBIGO_Q03C_MMS_V02*/
/**********************************************************************
 * Errors
 **********************************************************************/


/*****************************************************************************
 * FUNCTION
 *  HDIa_error
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  errorNo     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_error(MSF_UINT8 modId, int errorNo)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
    int i;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(errorNo)
    {
        case HDI_ERR_SYSTEM_REG_ABORTED:
        /*case HDI_ERR_SYSTEM_REG_FILE_CORRUPT:*/
        case HDI_ERR_SYSTEM_FATAL:
        case HDI_ERR_SYSTEM_REG_TXT_PARSE:
#ifdef __MTK_INTERNAL__ 
/* under construction !*/
#endif
        case HDI_ERR_MODULE_OUT_OF_MEMORY:
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
        {
            mms_action = MMS_ACTION_RESET;
            
            for (i = 1; i < MSF_NUMBER_OF_MODULES; i++)
            {
                if (msf_modules[i].isActive)
                {
                    msf_modules[i].pTaskKill();
                }
            }
            MSMc_kill();
        }
#endif
        break;
        case HDI_ERR_SYSTEM_REG_TXT_FILE:
            break;
        case HDI_ERR_SYSTEM_REG_FILE_CORRUPT:
            /*MSF_LOG_MSG_NOARG ((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_MSM, MSF_ERROR_REG_FILE_CORRUPT, "MSF_ERROR: HDI_ERR_SYSTEM_REG_FILE_CORRUPT"));*/
            break;
        default:
            EXT_ASSERT(FALSE, (kal_uint32) modId, (kal_uint32) errorNo, (kal_uint32)-1);
    }
}

/**********************************************************************
 * Module
 **********************************************************************/


#ifndef Q03C_IND_MOD_ARCH_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  HDIa_getModuleID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MSF_UINT8 gmms_HDIa_getModuleID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MSF_UINT8) current_mod_id;
}

#else
/*****************************************************************************
 * FUNCTION
 *  HDIa_getModuleID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MSF_UINT8 HDIa_getModuleID(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    module_type modId;
    extern int wps_get_current_mod_id(void);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    modId = stack_get_active_module_id();

    if (modId == MOD_WAP )
    {
    return (MSF_UINT8) current_mod_id;
    }
    else if (modId == MOD_MMS)
    {
    return (MSF_UINT8) mms_current_mod_id;
    }
    else if (modId == MOD_WPS)
    {
        return wps_get_current_mod_id();
    }

    ASSERT(0);

    return 0xff;
}

/*****************************************************************************
 * FUNCTION
 *  HDIa_getModuleID
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void HDIa_setModuleID(int mod_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    current_mod_id = mod_id;
}
#ifdef WAP_QUEUE_SMS_PUSH
/*****************************************************************************
 * FUNCTION
 *  notify_sms_push_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_param     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void notify_sms_push_hdlr(void *event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern void HDI_notifySmsPush(void);

    HDI_notifySmsPush();
}
#endif /* WAP_QUEUE_SMS_PUSH */ 
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

/*****************************************************************************
 * FUNCTION
 *  HDIa_killTask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_HDIa_killTask(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (modId < MSF_NUMBER_OF_MODULES && modId > 0) /* 0 == MSM */
    {
        msf_modules[modId].isActive = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  MSMa_createTask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_MSMa_createTask(MSF_UINT8 modId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (modId < MSF_NUMBER_OF_MODULES && modId > 0) /* 0 == MSM */
    {
        msf_modules[modId].pTaskStart();
        msf_modules[modId].isActive = 1;
        if(msf_modules[modId].startup_policy == HDI_STARTUP_STATIC)
        {
            msf_mod_init_mask |= (1 << modId);
        }
    }
}


#ifndef Q03C_IND_MOD_ARCH_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  MSMa_moduleStatus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_MSMa_moduleStatus(MSF_UINT8 modId, int status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msf_modules[modId].status = status;

    if(status == MSM_MODULE_STATUS_ACTIVE)
    {
        if(msf_mod_init_mask & (1 << modId))
        {
            msf_mod_init_mask &= ~(1 << modId);
            if (msf_mod_init_mask == 0)
            {
                if(mms_action == MMS_ACTION_RESET)
                {
                }
                mms_action = MMS_ACTION_NONE;
                mms_status = MMS_STATUS_ACTIVE;
                if(mms_ready_cb)
                {
                    mms_ready_cb();
                    mms_ready_cb = NULL;
                }
                
            }
        }
    }
    else if(status == MSM_MODULE_STATUS_SHUTTING_DOWN && 
        msf_modules[modId].startup_policy == HDI_STARTUP_STATIC)
    {
        msf_mod_init_mask |= (1 << modId);
    }
}
#else
/*****************************************************************************
 * FUNCTION
 *  MSMa_moduleStatus
 * DESCRIPTION
 *  
 * PARAMETERS
 *  modId       [IN]        
 *  status      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_MSMa_moduleStatus(MSF_UINT8 modId, int status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    extern msf_start_call_back_t msf_start_call_back;
    extern eventid msf_start_timer(MSF_UINT32 timeInterval, kal_timer_func_ptr timer_hdlr, void *event_param);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msf_modules[modId].status = status;

    if(status == MSM_MODULE_STATUS_ACTIVE)
    {
        if(msf_mod_init_mask & (1 << modId))
        {
            msf_mod_init_mask &= ~(1 << modId);
            if (msf_mod_init_mask == 0)
            {
                if (msf_start_call_back != NULL)
                {
                #ifdef WAP_QUEUE_SMS_PUSH
                    mms_start_timer(WAP_WAIT_SMS_NOTIFY_TIMEOUT, notify_sms_push_hdlr, NULL);
                #endif 
                    msf_start_call_back();
                    msf_start_call_back = NULL;
                }
            }
        }
    }
    else if(status == MSM_MODULE_STATUS_SHUTTING_DOWN && 
        msf_modules[modId].startup_policy == HDI_STARTUP_STATIC)
    {
        msf_mod_init_mask |= (1 << modId);
    }
}
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/


/*****************************************************************************
 * FUNCTION
 *  MSMa_terminated
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_MSMa_terminated(void)
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msf_modules[0].isActive = 0;
    mms_status = MMS_STATUS_TERMINATED;

    if(mms_action == MMS_ACTION_RESET)
    {
        ilm_ptr = allocate_ilm(MOD_MMS);
        ilm_ptr->msg_id = MSG_ID_WAP_INTERNAL_ERROR_IND; /* Set the message id */
        ilm_ptr->peer_buff_ptr = NULL;                  /* there are no peer message */
        ilm_ptr->local_para_ptr = NULL;                 /* there are no local message */
        ilm_ptr->src_mod_id  = MOD_MMS;
        ilm_ptr->dest_mod_id = MOD_MMS;
        ilm_ptr->sap_id = INVALID_SAP;
        msg_send_ext_queue(ilm_ptr);
    }    
}
#else /*Q03C_IND_MOD_ARCH_SUPPORT*/
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern kal_uint8 wap_status;
    extern kal_uint8 wap_action;
		extern void msm_compute_checksum_critical_files(void);
		extern void msm_compute_checksum_index_files(void);
#ifdef WAP_SEC_SUPPORT		
		extern void msm_compute_checksum_sec_files(void);
#endif /* WAP_SEC_SUPPORT */
#ifdef MSF_REGISTRY_SUPPPORT
		extern void msm_compute_checksum_reg_files(void);    
#endif /*MSF_REGISTRY_SUPPPORT*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_bool wap_deinit(void);

    /*
     * for debug termination count
     */
    static int nCount = 0;

    nCount++;

    /*MSF_LOG_MSG_NOARG ((MSF_LOG_DETAIL_MEDIUM, MSF_MODID_MSM, MSF_MSM_INT_TERMINATE, "In MSMa_terminated"));*/
    
    msf_modules[MSF_MODID_MSM].status = MSM_MODULE_STATUS_TERMINATED;
        /* Delete cache when exception cause reset */
        if (wap_action == WAP_ACTION_RESET)
        {
        msm_remove_files_under_dir(WAP_STK_CACHE_DIR);
        }

    /*
     * Justin
     * * I'm not sure if I should recompute the checksum for abnormal reset
     * *
     * * If I don't, it would restore to the old backup files next time in MSF_start()
     * * I'm not sure if it will cause problems.
     */

    msm_compute_checksum_critical_files();

    msm_compute_checksum_index_files(); /* Kevin */

#ifdef WAP_SEC_SUPPORT
    msm_compute_checksum_sec_files();   /* Kevin */
#endif /* WAP_SEC_SUPPORT */
#ifdef MSF_REGISTRY_SUPPPORT
    msm_compute_checksum_reg_files();   /* johnnie */
#endif /*MSF_REGISTRY_SUPPPORT*/

    wap_status = WAP_RESET_COMPLETE;
#ifdef MSF_MODID_BRA
    BRAa_stopBearerTimer();
#endif    
    wap_deinit();
    
	{
		module_type modId;
    extern void hdi_notify_task(module_type src, module_type dst, msg_type msg_id);		

		modId = stack_get_active_module_id();
		if(modId != MOD_WAP)
		{
			hdi_notify_task(modId, MOD_WAP, MSG_ID_WAP_STATUS_UPDATE_IND);
		}
	}
}
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
/*****************************************************************************
 * FUNCTION
 *  msm_timer_expiry_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_param     [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
static void int_timer_expiry_hdlr(void *event_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msm_timer_event_id = NULL;
    MSMc_timerExpiredEvent();
}


/*****************************************************************************
 * FUNCTION
 *  MSMa_setTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timeInterval        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_MSMa_setTimer(MSF_UINT32 timeInterval)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msm_timer_event_id)
    {
        MSMa_resetTimer();
    }
    msm_timer_event_id = mms_start_timer(timeInterval, int_timer_expiry_hdlr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  MSMa_resetTimer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gmms_MSMa_resetTimer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mms_stop_timer(&msm_timer_event_id);
    msm_timer_event_id = NULL;
}
int gmms_msf_module_isactive(int modId)
{
	if(modId >=MSF_NUMBER_OF_MODULES)
		return KAL_FALSE;
	else
		return msf_modules[modId].isActive;
}
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#ifdef MSF_REGISTRY_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  MSMa_registryResponse
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MSMa_registryResponse(MSF_UINT8 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSMc_registryRespFree(id);
}

/*****************************************************************************
 * FUNCTION
 *  MSMa_externalGet
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id          [IN]        
 *  path        [IN]        
 *  key         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void MSMa_externalGet(MSF_INT32 id, const char *path, const char *key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSMc_externalResponse(id, NULL);
}
#endif /*MSF_REGISTRY_SUPPORT*/

void hdi_notify_task(module_type src, module_type dst, msg_type msg_id)
{

    switch(dst)
    {
    case MOD_MMS:
		if (msg_get_task_extq_messages(INDX_MMS) > 0)
            return;
        break;
    case MOD_WAP:
        if (msg_get_task_extq_messages(INDX_WAP) > 0)
            return;
        break;
    case MOD_WPS:
        if (msg_get_task_extq_messages(INDX_WPS) > 0)
            return;
        break;
    default:
        ASSERT(0);
    }

	msg_send4(src, dst, INVALID_SAP, msg_id);
}

#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

/**********************************************************************
 * Logging
 **********************************************************************/

#ifdef __MTK_TARGET__

void gmms_HDIa_logTrace (int type, MSF_UINT8 modId, int msgId, char *format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    va_list arg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == HDI_LOG_TYPE_DETAILED_HIGH)
    {
        return;
    }
    
    if (type == HDI_LOG_TYPE_MEMORY)
    {
        return;
    }

    va_start(arg_list, format);
    kal_trace_for_3rd_party((trace_class_enum)msf_modules[modId].traceClass, msgId, format, arg_list);
    va_end(arg_list);

}

#else

void gmms_HDIa_logTrace (int type, MSF_UINT8 modId, int msgId, char *dummy, char *format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char log[129] = "";
    va_list arg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == HDI_LOG_TYPE_DETAILED_HIGH)
    {
        return;
    }
    if (type == HDI_LOG_TYPE_MEMORY)
    {
        return;
    }

    va_start(arg_list, format);
    _vsnprintf(log, 128, format, arg_list);
    va_end(arg_list);
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
    kal_wap_trace(MOD_MMS, msf_modules[modId].traceClass, "%s", log);
#else
#ifdef OBIGO_Q03C_MMS_V02
    if(modId == MSF_MODID_MMA/*||modId == MSF_MODID_SLS*/||modId == MSF_MODID_MMS)
        kal_wap_trace(MOD_MMS, msf_modules[modId].traceClass, "%s", log);
    else
#endif        
        kal_wap_trace(msf_modules[modId].taskId, msf_modules[modId].traceClass, "%s", log);
#endif
	/* kal_printf("%s", log); */
}

#endif

void gmms_HDIa_logMsg (int type, MSF_UINT8 modId, const char *format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char log[128];
    va_list arg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type == HDI_LOG_TYPE_DETAILED_HIGH)
    {
        return;
    }
    if (type == HDI_LOG_TYPE_MEMORY)
    {
        return;
    }

    va_start(arg_list, format);
#ifdef __MTK_TARGET__
    vsnprintf(log, 128, format, arg_list);
#else
    _vsnprintf(log, 128, format, arg_list);
#endif
    va_end(arg_list);

#ifdef __MTK_TARGET__
    kal_wap_trace(MOD_MMS, (trace_class_enum)msf_modules[modId].traceClass, "%s", log);
#else
    kal_wap_trace(MOD_MMS, msf_modules[modId].traceClass, "%s", log);
	/* kal_printf("%s", log); */
#endif
}

void gmms_HDIa_logData (int type, MSF_UINT8 modId, const unsigned char *data, int dataLen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 log[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_mem_cpy(log, data, dataLen > 128 ? 128 : dataLen);

#ifdef __MTK_TARGET__
    kal_wap_trace(MOD_MMS, (trace_class_enum)msf_modules[modId].traceClass, "%s", log);
#else
    kal_wap_trace(MOD_MMS, msf_modules[modId].traceClass, "%s", log);
	/* kal_printf("%s", log); */
#endif
}

void gmms_HDIa_logSignal (MSF_UINT8 srcModId, MSF_UINT8 dstModId, const char *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MSF_UINT8 log[128];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_mem_cpy(log, data, (strlen(data) > 128 ? 128 : strlen(data)));

#ifdef __MTK_TARGET__
    kal_wap_trace(MOD_MMS, (trace_class_enum)msf_modules[srcModId].traceClass, "%s", log);
#else
    kal_wap_trace(MOD_MMS, msf_modules[srcModId].traceClass, "%s", log);
	/* kal_printf("%s", log); */
#endif
}


/**********************************************************************
 * Time
 **********************************************************************/

MSF_UINT32 gmms_HDIa_timeGetCurrent (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct t;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&t);    
    return applib_dt_mytime_2_utc_sec(&t, KAL_TRUE);   
}

/*
Time without day light saving
*/
MSF_UINT32 gmms_HDIa_timeGetCurrent_Wdls(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct t;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&t);    
    return applib_dt_mytime_2_utc_sec(&t, KAL_FALSE);   
}

MSF_INT16 gmms_HDIa_timeGetTimeZone (void)
{
    extern float GetTimeZone(unsigned char);
    extern unsigned char PhnsetGetHomeCity(void);

    return (MSF_INT16) (GetTimeZone(PhnsetGetHomeCity()) * 60);
}

MSF_UINT32 gmms_HDIa_timeSecureClock (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&t);
    return (MSF_UINT32) applib_dt_sec_local_to_utc(applib_dt_mytime_2_utc_sec(&t, KAL_FALSE));
}

MSF_UINT32 gmms_HDIa_timeGetTicks (void)
{
    kal_uint32 ticks;
    
    kal_get_time(&ticks);
  
    return (MSF_UINT32)ticks;
}

MSF_UINT32
gmms_HDIa_timeUTCToLocal(MSF_UINT32 utc_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MSF_UINT32)applib_dt_sec_utc_to_local(utc_time);
}

#ifndef Q03C_IND_MOD_ARCH_SUPPORT
int gmms_HDIa_widgetDeviceGetProperties(MsfDeviceProperties* theDeviceProperties)
{
    return 0;
}
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

void gmms_adp_mms_jmpbuf_hdlr(void)
{
#ifdef OBIGO_Q03C_MMS_V02


	extern mtk_jmpbuf mms_jmpbuf;

	longjmp(mms_jmpbuf, 1);

#else
	return;

#endif	
}

