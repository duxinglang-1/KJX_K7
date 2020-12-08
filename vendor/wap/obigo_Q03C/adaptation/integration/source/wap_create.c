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
 * wap_create.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for WAP task create function and message handler
 *   entry point.
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
 *
 *
 * removed!
 * removed!
 *
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
#define _FILE_CODE_  _WAP_CREATE_C_

#ifndef __MTK_TARGET__
#include <windows.h>
#endif

#include "stdio.h"

#include "mmi_platform.h"

#include "msf_cfg.h"
#include "msf_mem.h"
#include "msf_chrs.h"
#include "msf_cmmn.h"
#include "msm_env.h"
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
#include "msm.h"
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
#include "msf_file.h"

#include "soc_api.h"
#include "app2soc_struct.h"

#include "wap_trc.h"
#include "msf_log.h"

#ifdef OBIGO_Q03C_BROWSER
#include "bam_cfg.h"   
#include "bam_lib.h"
#include "bam_if.h"

#include "msf_int.h"
#include "brs_if.h"
#endif

#include "gv.h"
#include "tst_def.h"

#include "FileManagerGProt.h"
#include "fmt_struct.h"

#include "nvram_enums.h"
#include "nvram_struct.h"
#include "nvram_user_defs.h"

#include "wap_ps_struct.h"

/* added by Kevin for handling interaction with MMI */
#include "mmiapi_struct.h"
/* added by Kevin ----end */

#ifdef OBIGO_Q03C_MMS_V01
#include "mmsadp.h"
#include "mms_def.h"    /* MMS_REG_PATH_IMMEDIATE_RETRIEVAL */
#include "mea_cfg.h"    /* MEA_FOLDER_PATH */
#include "mea_def.h"    /* MEA_RETRIEVAL_MODE_AUTOMATIC ... */
#include "mmc_env.h" 
/* MMS -pbook list Jo 030825 */
#include "WapDef.h"
#include "Msf_mem.h"
#include "mea_env.h"    /* for MEAc_startWithContentInserted */
#include "mamh.h"       /* for meaWidgetResponseForUnreadMessage */
#ifdef MMSAT_SUPPORT
#include "l4a.h"
#endif /* MMSAT_SUPPORT */ 
#ifdef __MMI_MMS_IN_UM__
#include "mea_if.h"
#endif
#endif /* OBIGO_Q03C_MMS_V01 */ 

#include "wap_cmn.h"
#include "widget.h"
#include "das_env.h"
#include "wap_cmmn_utils.h"
#include "WapResDef.h"
#include <clib.h>
#include "wps_struct.h"


#ifdef OBIGO_Q03C_BROWSER
#include "bam_msg.h"
#endif
#include "wap_msg.h"

#ifdef __DRM_SUPPORT__
#include "drm_gprot.h"
#endif

#ifdef MSF_CFG_WAP_PROF_SUPPORT
#include "WAPProfileSrvType.h"
//#include "WAPprovisioningType.h"
#endif /* MSF_CFG_WAP_PROF_SUPPORT */
#include "custpack_certs.h"

#include "msf_wid.h"
#include "app2cbm_struct.h"
#include "cbm_api.h"

/* MSM */
typedef void (*msf_start_call_back_t) (void);
extern void MSF_start(kal_bool slow_start, msf_start_call_back_t callback);
extern void MSF_fsm(void);
extern int MSF_moduleIsRunning(MSF_UINT8 modId);
extern kal_bool MSM_init(void);
extern kal_bool MSM_deinit(void);
extern void msf_timer_expiry_hdlr(ilm_struct *ilm_ptr);
extern int MSF_wapIsReady(void);
extern kal_uint32 wap_get_queue_size(void);
#ifdef MMS_V01_USE_ASM
extern void wapadp_set_mms_app_mem(void *value);
#endif /*MMS_V01_USE_ASM*/

/* Signal */
extern void HDI_signalQueueInit(void);

/* Socket */
extern void HDIa_socketInit(void);
extern int HDIa_socketMsgHdlr(ilm_struct *ilm_ptr);
extern void HDIa_socketTermBearer(void);

#ifdef Q03C_IND_MOD_ARCH_SUPPORT
/* Pipe */
extern void init_hdi_pipe(void);
/* File */
extern void init_hdi_file(void);
extern void hdi_file_timer_expiry_hdlr(void);
extern void init_hdi_signal(void);
extern void initMSFmem(void);
extern void init_hdi_mem(void);
extern int mms_get_disk_label(int type);
#else
/* Pipe */
extern void HDIa_pipeInit(void);

/* File */
extern void HDI_fileInit(void);
extern void HDI_fileDeinit(void);
extern void HDI_file_timer_expiry(ilm_struct *ilm_ptr);
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/

/* Misc */
extern void set_log_filter(tst_inject_string_struct *inject_str);

/* Widget */
extern void widget_timer_expiry(ilm_struct *ilm_ptr);
extern void widget_init(void);
extern void widget_deinit(void);
extern void widget_waiting_external_queue(void);
extern void widget_finish_external_queue(void);
extern module_type stack_int_get_active_module_id( void );


/* Key */
extern void widget_wap_mmi_key_ind(ilm_struct *ilm_ptr);

/* RPC */
extern void widget_mmiapi_remote_proc_call_req(ilm_struct *ilm_ptr);


#ifdef WAP_SUPPORT
// Deprecated
//extern void bra_prs_install_prov(void);
#endif /* WAP_SUPPORT */ 

/* MEMORY */
extern void wapadp_mem_init(void);
extern void wapadp_mem_init_pool(MSF_UINT8 poolId);
extern void wapadp_mem_free_all(MSF_UINT8 modId);
extern void wapadp_mem_enable_spare_mem(MSF_UINT8 modId);

/* DISCONNECT BEARER */
//extern void HDIa_socketDiscBearerById(MSF_INT32 networkAccountID);


/* MMS */
#ifdef OBIGO_Q03C_MMS_V01
extern kal_bool isMMSBusy(void);
extern int widget_ucs2_to_utf8_length_in_bytes(const kal_uint8 *raw);
extern int widget_ucs2_to_utf8_string(kal_uint8 *dest, int dest_size, const kal_uint8 *src);
extern void meaMeRegisterExitCallback(func_ptr funcPtr, void *param);
extern void mms_unread_check(void);
extern void meaTerminateApp(void);
extern void meaMeRemoveInvalidObjects(void);
extern void mea_handle_target_dat_ind(module_type source, 
             mms_target_data_ind_struct *target_data_ind_p, peer_buff_struct *peer_buffer_p);

#ifndef __UNIFIED_COMPOSER_SUPPORT__
extern MSF_BOOL meaIsStartupModeNew(void);
extern kal_uint16 wap_get_screen_id(void);
#endif

#ifdef __USB_IN_NORMAL_MODE__
extern int is_mms_storage_exported_to_pc(void);
#endif /* __USB_IN_NORMAL_MODE__ */ 
extern char *SMAlib_getAttachment(char *filename);
extern kal_uint8 mea_handle_set_profile_req(srv_wap_prof_active_profile_changed_ind_struct *profile_data);
extern void mea_mmsV01_handle_add_bookmark_rsp(mmi_mmsv01_agent_add_bookmark_rsp_struct* data);
extern void mea_mmsV01_agent_get_setting_rsp(void *ptr);
extern void mea_mmsV01_agent_set_setting_req(void *ptr);
#endif /* OBIGO_Q03C_MMS_V01 */ 

/* Global Vars */
kal_msgqid wap_ext_qid;
kal_uint8 wap_status;
kal_uint8 wap_action;
mtk_jmpbuf wap_jmpbuf;
kal_int32 wap_external_get_id;

#define WAP_DEFAULT_BOOKMARKS_RECEIVED      0x01
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
#define WAP_DEFAULT_PUSH_TRUSTLIST_RECEIVED 0x02
#endif /* BRA_CONFIG_PUSH_TRUSTLIST */

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
/* under construction !*/
#endif
/* under construction !*/
#endif
static kal_uint8 sim_status;
static kal_uint8 sim_setting_mode;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#define MSG_MMI_EQ_POWER_ON_IND     0x01
#define MSG_MMI_READY_NOTIFY_REQ    0x02

extern void msm_remove_files_under_dir(const char *folder);
extern void msm_compute_checksum_critical_files(void);
extern void msm_compute_checksum_sec_files(void);
extern int msm_get_module_status(MSF_UINT8 modId);




#define WAP_INT_QUEUE_SIZE    (5)
#define WIDGET_QUEUE_SIZE_HIGH_WATERMARK     (15)



static kal_uint8 wap_int_q_size = 0;
static kal_uint8 wap_int_q_read_index = 0;
static kal_uint8 wap_int_q_write_index = 0;
static ilm_struct wap_int_q_array[WAP_INT_QUEUE_SIZE];

static kal_bool wap_is_timer_msg_in_int_q = KAL_FALSE;

static void wap_default_settings_done(void);
static void wap_ready_callback_func(void);


/*****************************************************************************
 * FUNCTION
 *  wap_get_wap_status
 * DESCRIPTION
 *  This function is to get wap status
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  wap status
 *****************************************************************************/
kal_uint8 wap_get_wap_status(void)
{
    return wap_status;
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_wap_action
 * DESCRIPTION
 *  This function is to get wap action
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  wap action
 *****************************************************************************/
kal_uint8 wap_get_wap_action(void)
{
    return wap_action;
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_sim_status
 * DESCRIPTION
 *  This function is used to restart WAP when internal state is incorrect
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 wap_get_sim_status(void)
{
    return sim_status;
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_sim_setting_mode
 * DESCRIPTION
 *  This function is used to restart WAP when internal state is incorrect
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 wap_get_sim_setting_mode(void)
{
    return sim_setting_mode;
}


#if 0
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
#endif


/*****************************************************************************
 * FUNCTION
 *  notifiy_mmi_wap_poweroff_completed
 * DESCRIPTION
 *  This function is used to notify MMI that WAP poweroff procedure is completed
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void notifiy_mmi_wap_poweroff_completed()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static int isCalled = 0;    /* it should be called only once */

    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (isCalled)
    {
        return;
    }
    isCalled = 1;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->msg_id = (kal_uint16) MSG_ID_WAP_BROWSER_POWEROFF_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->local_para_ptr = (local_para_struct*) NULL;

    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  start_poweroff_watchdog
 * DESCRIPTION
 *  start watchdog timer for the poweroff procedure in order to
 *  prevent infinite loop in the termination process
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void start_poweroff_watchdog()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * NOT IMPLEMENTED. We should add a timer to invoke
     * notifiy_mmi_wap_poweroff_completed()
     * with the timer MSF_POWEROFF_TIMER_ID
     * and directly terminate the mobile suite
     */
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif


#if 0    
#if !defined(READ_WAP_DEFAULT_FROM_CONST) && !defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK)
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
#endif /* !defined(READ_WAP_DEFAULT_FROM_CONST) && !defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK) */
#endif


#ifdef WAP_SEC_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  wap_write_root_ca_default
 * DESCRIPTION
 *  This function is used to the default value of WAP pre-installed root ca
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_write_root_ca_default(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i, j;
    kal_int32 fd;
    kal_uint8 *raw;
    kal_uint32 size = 0;
    kal_int32 ret;
    char filename[32];
    int num_rd_certs = 0;
	kal_uint32 num_certs;

#define     BRA_DFT_CERT_WTLS   1
#define     BRA_DFT_CERT_X509   2
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    raw = (kal_uint8*) MSF_MEM_ALLOC(MSF_MODID_MSM, 1024);

    ret = MSF_FILE_MKDIR(WAP_SEC_FILE_DIR  );
    if (!(ret == HDI_FILE_OK || ret == HDI_FILE_ERROR_EXIST))
        ASSERT(0);
            ret = MSF_FILE_MKDIR(WAP_SEC_STORAGE_DIR );
    if (!(ret == HDI_FILE_OK || ret == HDI_FILE_ERROR_EXIST))
        ASSERT(0);
            sprintf(filename, "%s/S_%u", WAP_SEC_STORAGE_DIR, 0);
    fd = MSF_FILE_OPEN(
            MSF_MODID_MSM,
            (char*)filename,
            HDI_FILE_SET_CREATE | HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
            0);

    if (fd < 0)
        ASSERT(0);

    j = 0;

	num_certs = certman_cfg_get_max_certs_num();

    num_rd_certs = (num_certs < resource_root_ca->num_certs) ? num_certs : resource_root_ca->num_certs;
    for (i = 0; i < num_rd_certs; i++)
    {
/*        if (CUST_WAP_ROOT_CA_DEFAULT->root_ca[i].empty == 1)
        {
            continue;
        }*/
        j++;

        raw[size++] = 0x43,
            raw[size++] = 0x00,
            raw[size++] = 0x00,
            raw[size++] = 0x00,
            raw[size++] = j,
            raw[size++] =
            (kal_uint8) (((resource_root_ca->certs[i].cert_len + 1) & 0xff000000) >> 24);
        raw[size++] = (kal_uint8) (((resource_root_ca->certs[i].cert_len + 1) & 0x00ff0000) >> 16);
        raw[size++] = (kal_uint8) (((resource_root_ca->certs[i].cert_len + 1) & 0x0000ff00) >> 8);
        raw[size++] = (kal_uint8) ((resource_root_ca->certs[i].cert_len + 1) & 0x000000ff);
#ifdef MSF_CFG_RDONLY_CERT_SUPPORT
        if(resource_root_ca->certs[i].read_only)    
			raw[size++] = 0;
		else
			raw[size++] = 1;
#endif /* MSM_CFG_RDONLY_CERT_SUPPORT */        
    }

    ret = MSF_FILE_WRITE(fd, raw, size);
    if (ret != size)
        ASSERT(0);

    MSF_FILE_CLOSE(fd);
    size = 0;
    j = 0;

    for (i = 0; i < num_rd_certs; i++)
    {
/*        if (CUST_WAP_ROOT_CA_DEFAULT->root_ca[i].empty == 1)
        {
            continue;
        }*/
        j++;

        sprintf(filename, "%s/S_%u", WAP_SEC_STORAGE_DIR, j);
        fd = MSF_FILE_OPEN(
                MSF_MODID_MSM,
                (char*)filename,
                HDI_FILE_SET_CREATE | HDI_FILE_SET_WRONLY | HDI_FILE_SET_CUSTOM_BLOCKING,
                0);

        if (fd < 0)
            ASSERT(0);
        raw[0] = 'C';
        if (resource_root_ca->certs[i].format == CERT_FORMAT_X509)
            raw[1] = BRA_DFT_CERT_X509;
        else
            raw[1] = BRA_DFT_CERT_WTLS;
        ret = MSF_FILE_WRITE(fd, raw, 2);
        if (ret != 2)
            ASSERT(0);
        ret = MSF_FILE_WRITE(
                fd,
                (void*)resource_root_ca->certs[i].cert,
                resource_root_ca->certs[i].cert_len);
        if (ret != resource_root_ca->certs[i].cert_len)
            ASSERT(0);
        MSF_FILE_CLOSE(fd);
    }

    goto open_error;

  open_error:
    MSF_MEM_FREE(MSF_MODID_MSM, raw);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  wap_read_factory_setting
 * DESCRIPTION
 *  This function is used to read WAP factory setting, including profile,
 *  bookmark, common setting, and pre-install root-CA
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_read_factory_setting(void) 
{
#ifdef OBIGO_Q03C_BROWSER
    kal_int32       ret;

    ret = MSF_FILE_MKDIR(WAP_BAM_FILE_DIR );
    if (!(ret == HDI_FILE_OK || ret == HDI_FILE_ERROR_EXIST))
        ASSERT(0);
#endif

#if 0
/* under construction !*/
/* under construction !*/
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
/* under construction !*/
/* under construction !*/
#endif
#else
    if (wap_get_wap_action() == WAP_ACTION_FIRST_POWER_ON || wap_get_wap_action() == WAP_ACTION_RESTORE_FACTORY_SETTING)
    {
        msm_compute_checksum_critical_files();
    }
#ifdef WAP_SEC_SUPPORT
    wap_write_root_ca_default();
    if (wap_get_wap_action() == WAP_ACTION_FIRST_POWER_ON || wap_get_wap_action() == WAP_ACTION_RESTORE_FACTORY_SETTING)
    {
        msm_compute_checksum_sec_files();
    }
#endif
    wap_default_settings_done();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wap_restore_factory_setting
 * DESCRIPTION
 *  This function is used to restore system settings data.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_restore_factory_setting(void)
{
    msf_start_call_back_t callback = NULL;

    if (FS_GetAttributes(L"z:\\@wap_bak\\secchksum.dat") >= 0)
    {
        FS_Move(L"z:\\@wap_bak\\secchksum.dat", L"z:\\@wap\\msm\\secchksum.dat",	FS_MOVE_OVERWRITE |	FS_MOVE_KILL, 0, NULL, 0);
    }
    if (FS_GetAttributes(L"z:\\@wap_bak\\idxchksum.dat") >= 0)
    {
        FS_Move(L"z:\\@wap_bak\\idxchksum.dat", L"z:\\@wap\\msm\\idxchksum.dat",	FS_MOVE_OVERWRITE |	FS_MOVE_KILL, 0, NULL, 0);
    }
    if (wap_action == WAP_ACTION_FIRST_POWER_ON || wap_action == WAP_ACTION_RESTORE_FACTORY_SETTING)
    {
        msm_compute_checksum_critical_files();
    }

    if ((wap_action  == WAP_ACTION_POWER_ON) || (wap_action == WAP_ACTION_RESTORE_FACTORY_SETTING) || (wap_action == WAP_ACTION_FIRST_POWER_ON))
    {
        wap_action = WAP_ACTION_NONE;
        callback = wap_ready_callback_func;
    }
    if (wap_status == WAP_RESET_COMPLETE)
    {
        MSF_start(KAL_TRUE, callback);
    }
#ifdef OBIGO_Q03C_MMS_V01
    mms_unread_check();
#endif    
}

#if 0
#if !defined(READ_WAP_DEFAULT_FROM_CONST) && !defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK)
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
#ifdef BRA_CONFIG_PUSH_TRUSTLIST
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
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* !defined(READ_WAP_DEFAULT_FROM_CONST) && !defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK) */ 
#endif


/*****************************************************************************
 * FUNCTION
 *  wap_send_mmi_restore_factory_cnf
 * DESCRIPTION
 *  This function is used to send MMI restore factory setting confirmation
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_send_mmi_restore_factory_cnf(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->msg_id = MSG_ID_WAP_RESTORE_FACTORY_SETTING_CNF;
    ilm_ptr->peer_buff_ptr = NULL;
SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr)}


/*****************************************************************************
 * FUNCTION
 *  wap_send_fmt_format_rsp
 * DESCRIPTION
 *  This function is used to send FMT format response
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_send_fmt_format_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    mmi_fmt_format_rsp_strcut *fmt_format_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fmt_format_rsp =
        (mmi_fmt_format_rsp_strcut*) construct_local_para((kal_uint16) sizeof(mmi_fmt_format_rsp_strcut), TD_CTRL);
    fmt_format_rsp->result = FS_NO_ERROR;

    ilm_ptr = allocate_ilm(MOD_WAP);
    ilm_ptr->local_para_ptr = (local_para_struct*) fmt_format_rsp;
    ilm_ptr->msg_id = MSG_ID_MMI_FMT_FORMAT_RSP;
    ilm_ptr->peer_buff_ptr = NULL;
SEND_ILM(MOD_WAP, MOD_FMT, WAP_MMI_SAP, ilm_ptr)}

#ifdef __USB_IN_NORMAL_MODE__

#ifdef OBIGO_Q03C_MMS_V01


/*****************************************************************************
 * FUNCTION
 *  wap_send_mmi_mms_enter_usb_mode_rsp
 * DESCRIPTION
 *  This function is used to send mms ready signal to MMI task for entering USB mode
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_send_mmi_mms_enter_usb_mode_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr->msg_id = MSG_ID_MMS_ENTER_USB_MODE_RSP;
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  wap_send_mmi_mms_exit_usb_mode_rsp
 * DESCRIPTION
 *  This function is used to send mms ready signal to MMI task for exiting USB mode
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_send_mmi_mms_exit_usb_mode_rsp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = allocate_ilm(MOD_WAP);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr->msg_id = MSG_ID_MMS_EXIT_USB_MODE_RSP;
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
}
#endif /* OBIGO_Q03C_MMS_V01 */ 
#endif /* __USB_IN_NORMAL_MODE__ */ 

#ifdef WPS_TASK_SUPPORT


/*****************************************************************************
 * FUNCTION
 *  wap_send_wps_wap_ready_ind
 * DESCRIPTION
 *  This function is used to send WAP ready indication to WPS task, then WPS task
 *  can notify its user that it is ready to provide service
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_send_wps_wap_ready_ind(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	ilm_struct *ilm_ptr;
    module_type srcId;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srcId = stack_get_active_module_id();

    ilm_ptr = allocate_ilm(srcId);    
    ilm_ptr->msg_id = MSG_ID_WAP_READY_IND;
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->peer_buff_ptr = NULL;
    ilm_ptr->src_mod_id  = srcId;
    ilm_ptr->dest_mod_id = MOD_WPS;
    ilm_ptr->sap_id = INVALID_SAP;
    msg_send_ext_queue(ilm_ptr);
}

#endif /* WPS_TASK_SUPPORT */ 


/*****************************************************************************
 * FUNCTION
 *  wap_ready_callback_func
 * DESCRIPTION
 *  This function is used for call back function when wap init. finish
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_ready_callback_func(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef WPS_TASK_SUPPORT
    wap_send_wps_wap_ready_ind();
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  wap_task_sleep
 * DESCRIPTION
 *  Put the wap task to sleep (wait protocol ready or give control to MMI task)
 * CALLS
 *  
 * PARAMETERS
 *  milliseconds        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void wap_task_sleep(int milliseconds)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_sleep_task(kal_milli_secs_to_ticks(milliseconds));
}


/*****************************************************************************
 * FUNCTION
 *  wap_simulate_out_of_memory
 * DESCRIPTION
 *  Put the wap task to sleep (wait protocol ready or give control to MMI task)
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_simulate_out_of_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < 20; i++)
    {
        MSF_MEM_ALLOC(MSF_MODID_MSM, 10 * 1024);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_init_framework
 * DESCRIPTION
 *  This function should be called to Initialize the Teleca mobile suite.
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_init_framework(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_action = WAP_ACTION_NONE;
    wap_status = WAP_RESET_COMPLETE;
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
    wapadp_mem_init_pool(WAP_MEM_POOL);
    MSM_init();
    HDI_signalQueueInit();
    HDIa_socketInit();
    HDIa_pipeInit();
    HDI_fileInit();
#else
    wapadp_mem_init();
    MSM_init();
    init_hdi_signal();
    HDIa_socketInit();
    init_hdi_pipe();
    init_hdi_file();
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
    widget_init();

    return;
}


/*****************************************************************************
 * FUNCTION
 *  wap_init
 * DESCRIPTION
 *  This function should be called to Initialize the WAP task
 * CALLS
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool wap_init(task_indx_type task_indx)
{
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
    extern void MSMc_start(void);
#endif
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_action = WAP_ACTION_NONE;
    wap_status = WAP_RESET_COMPLETE;
    wapadp_mem_init();
#endif    
    MSM_init(); /* Mainly for wap_ctrl_mutex */
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
    MSMc_start();
    init_hdi_signal();
#endif
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_deinit
 * DESCRIPTION
 *  This function should be called to deinit the WAP task
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_bool wap_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MSM_deinit();
#ifndef Q03C_IND_MOD_ARCH_SUPPORT
    HDI_fileDeinit();
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
    widget_deinit();
    wapadp_mem_free_all(WAP_MEM_POOL);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_reset
 * DESCRIPTION
 *  This function should be called to reset the WAP task
 * CALLS
 *  
 * PARAMETERS
 *  task_indx       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool wap_reset(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //HDIa_socketDiscBearerById(0xff);
    wap_status = WAP_RESET_ONGOING;
    //wapadp_mem_enable_spare_mem(WAP_MEM_POOL);
    MSMc_terminateMobileSuite();
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_proc_inject_string
 * DESCRIPTION
 *  This function should be called from wap_fsm to process injection string
 * CALLS
 *  
 * PARAMETERS
 *  inject_str      [IN]        Injection string
 * RETURNS
 *  void
 *****************************************************************************/
static void wap_proc_inject_string(tst_inject_string_struct *inject_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (inject_str->index < 2)
    {
        /* set log filter */
        set_log_filter(inject_str);
    }
    else if (inject_str->index == 5)
    {
        if (wap_status != WAP_RUNNING)
            ASSERT(0);
                wap_action = WAP_ACTION_RESET_BEFORE_RESTORE_FACTORY_SETTING, wap_reset(INDX_WAP);
    }
    else if (inject_str->index == 9)
    {
        wap_simulate_out_of_memory();
    }
#ifdef DEBUG_FILE_WITH_INJECTION
    else if (inject_str->index == 21)   /* get file size */
    {
        /* TODO compute checksum */

        long size = MSF_FILE_GETSIZE((char*)inject_str->string );

        if (size >= 0)
        {
            kal_prompt_trace(MOD_WAP, "%s size %d", inject_str->string, (int)size);
        }
        else
        {
            kal_prompt_trace(MOD_WAP, "%s open error: No. %d", inject_str->string, (int)size);
        }
    }
    else if (inject_str->index == 22)   /* get file size (chinese+english) */
    {
        /* open chinese file name in the format by UTF8 string (\xAB) */
        char longname[128];
        long size;

        utf8_modify_name_backward((unsigned char*)longname, (unsigned char*)inject_str->string, 128);
        size = MSF_FILE_GETSIZE(longname );
        if (size >= 0)
        {
            kal_prompt_trace(MOD_WAP, "%s size %d", inject_str->string, (int)size);
        }
        else
        {
            kal_prompt_trace(MOD_WAP, "%s open error: No. %d", inject_str->string, (int)size);
        }
    }
    else if (inject_str->index == 23)   /* list directory */
    {
        int num_entry;
        int i;

        num_entry = MSF_FILE_GETSIZE_DIR((char*)inject_str->string );
        if (num_entry < 0)
        {
            kal_prompt_trace(MOD_WAP, "open dir failed");
        }
        else
        {
            /* it would show short file name by default */
            char namebuf[32];
            char namebuf_modified[200];
            int size;
            int type;

            kal_prompt_trace(MOD_WAP, "Start of directory %s", inject_str->string);
            for (i = 0; i < num_entry; i++)
            {
                MSF_FILE_READ_DIR((char*)inject_str->string, i, namebuf, 32, &type, &size );
                utf8_modify_name((unsigned char*)namebuf_modified, (unsigned char*)namebuf, 128);
                kal_prompt_trace(MOD_WAP, "%s %s - %d", type == HDI_FILE_FILETYPE ? "f" : "d", namebuf_modified, size);
            }
            kal_prompt_trace(MOD_WAP, "End of directory %s", inject_str->string);
        }
    }
    else if (inject_str->index == 24)
    {   /* create file (UTF8) */
        char longname[128];
        int fd;

        utf8_modify_name_backward((unsigned char*)longname, (unsigned char*)inject_str->string, 128);
        fd = MSF_FILE_OPEN(MSF_MODID_MSM, longname, HDI_FILE_SET_CREATE | HDI_FILE_SET_RDWR, 100 );
        if (fd > 0)
        {
            MSF_FILE_CLOSE(fd);
            kal_prompt_trace(MOD_WAP, "Create success %s", longname);
        }
        else
        {
            /* However, it might return HDI_FILE_ERROR_DELAYED */
            kal_prompt_trace(MOD_WAP, "Create fail %d %s", fd, longname);
        }
    }
    else if (inject_str->index == 25)   /* get file checksum */
    {
        /* open chinese file name in the format by UTF8 string (\xAB) */
        extern int msm_compute_checksum_from_file(const char *filename);

        char longname[128];
        int checksum;

        utf8_modify_name_backward((unsigned char*)longname, (unsigned char*)inject_str->string, 128);

        checksum = msm_compute_checksum_from_file(longname);

        kal_prompt_trace(MOD_WAP, "%s checksum %d", inject_str->string, checksum);
    }
    else if (inject_str->index == 26)   /* remove file */
    {
        /* open chinese file name in the format by UTF8 string (\xAB) */
        char longname[128];

        utf8_modify_name_backward((unsigned char*)longname, (unsigned char*)inject_str->string, 128);

        MSF_FILE_REMOVE(longname );
        kal_prompt_trace(MOD_WAP, "%s removed", inject_str->string);
    }
    else if (inject_str->index == 27)   /* show disk free space */
    {
        kal_uint32 size;

        size = msm_get_disk_free_space(WAP_STORAGE_SYSTEM);
        kal_prompt_trace(MOD_WAP, "Free space of wap system: %d", size);
        size = msm_get_disk_free_space(WAP_STORAGE_MMS);
        kal_prompt_trace(MOD_WAP, "Free space of /mms: %d", size);
        size = msm_get_disk_free_space(WAP_STORAGE_PUBLIC);
        kal_prompt_trace(MOD_WAP, "Free space of /public: %d", size);
    }
    else if (inject_str->index == 28)
    {
        int files, type;
        long size;
        int i = 0;
        char tmpName[256], pathName[256];
        char *root_folder = (char*)inject_str->string;

        files = MSF_FILE_GETSIZE_DIR(root_folder );

        kal_prompt_trace(MOD_WAP, "Total %d folders", files);

        if (files >= 1)
        {
            while ((MSF_FILE_READ_DIR(root_folder, i, tmpName, 256, &type, (int*)&size ) == HDI_FILE_OK) && (i < files))
            {
                strcpy(pathName, root_folder);
                strcat(pathName, "\\");
                strcat(pathName, tmpName);
                if (type == HDI_FILE_FILETYPE)
                {
                    size = MSF_FILE_GETSIZE(pathName );
                    kal_prompt_trace(MOD_WAP, "f %d - %s ", (int)size, tmpName);
                }
                else
                {
                    int dummy = 0;

                    size = 0;
                    msm_get_folder_info_recursive(pathName, &dummy, &size);
                    kal_prompt_trace(MOD_WAP, "d %d/ - %s ", (int)size, tmpName);
                }

                i++;
            }
        }

        kal_prompt_trace(MOD_WAP, "End of %d folders", files);
    }
#endif /* DEBUG_FILE_WITH_INJECTION */ 
#if defined(FILE_DEBUG_VERBOSE) && defined(__MTK_TARGET__)
    else if (inject_str->index == 31)
    {
        extern void HDI_list_opened_files(void);

        HDI_list_opened_files();
    }
    else if (inject_str->index == 32)
    {
        extern void HDI_reset_number_opened_files(void);

        HDI_reset_number_opened_files();
    }
#endif /* defined(FILE_DEBUG_VERBOSE) && defined(__MTK_TARGET__) */ 
    else if(inject_str->index == 17)
    {
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ;

    Message.oslDataPtr = NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_start_framework
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void wap_start_framework(void)
{
    if(wap_prepare_root_folder(L"z:\\@wap", "obigo_q03c") == 2)
    {
        wap_action = WAP_ACTION_FIRST_POWER_ON;
        MSF_FILE_MKDIR(WAP_MSM_FILE_DIR );
        wap_restore_factory_setting();
        return;
    }
    if (MSF_FILE_GETSIZE_DIR(WAP_MSM_FILE_DIR ) == HDI_FILE_ERROR_PATH)
    {
        /* first power on, so restore all wap setting */
        wap_action = WAP_ACTION_FIRST_POWER_ON;
        MSF_FILE_MKDIR(WAP_MSM_FILE_DIR );
        /* load factory setting first */
        wap_read_factory_setting();
        return;
    }
    else
    {
        /* not first power on, restore common setting only -- registry.txt */
        wap_action = WAP_ACTION_NONE;
    }

    if (wap_status == WAP_RESET_COMPLETE)
    {
        MSF_start(KAL_TRUE, wap_ready_callback_func);
    }
#ifdef OBIGO_Q03C_MMS_V01
    mms_unread_check();
#endif    
}


/*****************************************************************************
 * FUNCTION
 *  wap_fsm
 * DESCRIPTION
 *  (ilm_struct *ilm_ptr)
 *  This procedure is used to dispatch receiving message
 *  to message handler.
 * CALLS
 *  wap_fsm(ilm_struct *ilm_ptr)
 * PARAMETERS
 *  ilm_ptr     [IN]        First variable, used as input
 * RETURNS
 *  void
 *****************************************************************************/
void wap_fsm(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
	int i;
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/    
#if defined(WPS_SUPPORT) && !defined(WPS_TASK_SUPPORT)
    extern void wps_fsm(ilm_struct * ilm_ptr);
#endif

#if defined(__MMI_MMS_IN_UM__)
    extern int wap_um_msg_hdlr(ilm_struct * ilm_ptr);
  #if defined(__UNIFIED_COMPOSER_SUPPORT__) && defined(OBIGO_Q03C_MMS_V01)
    extern int wap_mma_msg_hdlr(ilm_struct *ilm_ptr);
  #endif
#endif 

#if defined(__MMI_MMS_BGSR_SUPPORT__) && defined(OBIGO_Q03C_MMS_V01)
    extern int wap_bgsr_msg_hdlr(ilm_struct *ilm_ptr);
#endif /*__MMI_MMS_BGSR_SUPPORT__*/

#if defined(OBIGO_Q03C_MMS_V01) && defined (__MMI_MMS_VENDOR_APP_SUPPORT__)
    extern int wap_slim_mma_msg_hdlr(ilm_struct *ilm_ptr);
#endif

    kal_bool is_shutdown_UI = KAL_FALSE, is_handled = KAL_FALSE;
    static kal_uint32 init_mask = MSG_MMI_EQ_POWER_ON_IND | MSG_MMI_READY_NOTIFY_REQ;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(HDIa_socketMsgHdlr(ilm_ptr)
#ifdef __MMI_MMS_IN_UM__
    || wap_um_msg_hdlr(ilm_ptr)
#endif 
#if defined(__UNIFIED_COMPOSER_SUPPORT__) && defined(OBIGO_Q03C_MMS_V01)
    || wap_mma_msg_hdlr(ilm_ptr)
#endif 
#if defined(OBIGO_Q03C_MMS_V01) && defined (__MMI_MMS_VENDOR_APP_SUPPORT__)
    || wap_slim_mma_msg_hdlr(ilm_ptr)
#endif
#if defined(__MMI_MMS_BGSR_SUPPORT__) && defined(OBIGO_Q03C_MMS_V01)
    || wap_bgsr_msg_hdlr(ilm_ptr)
#endif /*__MMI_MMS_BGSR_SUPPORT__*/
#ifdef __DRM_SUPPORT__
    || DRM_app_common_hdlr(ilm_ptr)
#endif
#ifdef OBIGO_Q03C_BROWSER    
    || das_handle_message((void *)ilm_ptr)
#endif
#ifdef OBIGO_Q03C_MMS_V01
    || wap_mmc_msg_hdlr(ilm_ptr)
#endif /* OBIGO_Q03C_MMS_V01 */   
#ifdef OBIGO_Q03C_BROWSER        
    || bam_handle_message(ilm_ptr)
#endif
    )
    {
        is_handled = TRUE;
    }
    else
    {
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
    for (i = 0; i < MSF_NUMBER_OF_MODULES; i++)
    {
				if ((msf_modules[i].taskId == MOD_WAP) && (msf_modules[i].isActive) && (msf_modules[i].pMsgHdlr))
        {
            if (msf_modules[i].pMsgHdlr((void*)ilm_ptr) == TRUE)
            {
                    is_handled = TRUE;
                break;
            }
        }
    }
#endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
    }
#if defined(WPS_SUPPORT) && !defined(WPS_TASK_SUPPORT)
    wps_fsm(ilm_ptr);
#endif 
    
    if(!is_handled)
    {
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MMI_EQ_POWER_ON_IND:
            init_mask &= ~MSG_MMI_EQ_POWER_ON_IND;
            if (!init_mask && wap_status == WAP_RESET_COMPLETE && wap_action == WAP_ACTION_NONE)
            {
                wap_start_framework();
            }
            break;

        case MSG_ID_MMI_READY_NOTIFY_REQ:
            init_mask &= ~MSG_MMI_READY_NOTIFY_REQ;
            if (!init_mask && wap_status == WAP_RESET_COMPLETE && wap_action == WAP_ACTION_NONE)
            {
                wap_start_framework();
            }
            break;

        case MSG_ID_WAP_SIM_INFO_NOTIFY_IND:
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
  #if defined(OBIGO_Q03C_MMS_V01) && defined(__MMS_DUAL_SIM__)           
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    								#ifdef OBIGO_Q03C_MMS_V01
/* under construction !*/
#endif                    
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            break;

        /* L4 IMSI response */
#if 0
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
    #if !defined(READ_WAP_DEFAULT_FROM_CONST) && !defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* !defined(READ_WAP_DEFAULT_FROM_CONST) && !defined(READ_WAP_DEFAULT_FROM_CUSTOM_PACK) */ 
#endif /* 0 */

        case MSG_ID_MMI_FMT_FORMAT_REQ:
    #ifdef OBIGO_Q03C_MMS_V01
            if (MSF_wapIsReady())
            {
                mmi_fmt_format_req_strcut *fmt_format_req = (mmi_fmt_format_req_strcut*) ilm_ptr->local_para_ptr;

                if (fmt_format_req->drive == (kal_uint8) HDI_FileGetDiskLabel(WAP_STORAGE_MMS))
                {
                    wap_action = WAP_ACTION_FMT_FORMAT;
                    wap_reset(INDX_WAP);
                }
                else
                {
                    wap_send_fmt_format_rsp();
                }
            }
            else
    #endif
            {
                wap_send_fmt_format_rsp();
            }
            break;

        case MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ:
            if (!MSF_wapIsReady()
        #ifdef OBIGO_Q03C_MMS_V01
                || isMMSBusy()
        #endif 
                )
            {
                wap_send_mmi_restore_factory_cnf();
                break;
            }
            wap_action = WAP_ACTION_RESET_BEFORE_RESTORE_FACTORY_SETTING;
            wap_reset(INDX_WAP);
            break;

        case MSG_ID_WAP_INTERNAL_ERROR_IND:
#ifdef MSF_NEW_EXCEPTION_HANDLING
        {
            extern MSF_UINT8 MSF_getExceptionPool(void);
            extern void wapadp_mem_enable_spare_mem(MSF_UINT8 modId);

            if(MSF_getExceptionPool() == WAP_MEM_POOL)
            {
                wapadp_mem_enable_spare_mem(0);
#endif
                wap_action = WAP_ACTION_RESET;
                wap_reset(INDX_WAP);
#ifdef MSF_NEW_EXCEPTION_HANDLING
            }
#ifdef BROWSER_SUPPORT
            else
            {
                extern void brs_abort();
                brs_abort();
            }
#endif
        }
#endif
            break;

        case MSG_ID_WAP_BROWSER_SHUTDOWN_REQ:
            if (wap_status != WAP_RUNNING)
                break;
            is_shutdown_UI = KAL_TRUE;

        #ifdef OBIGO_Q03C_MMS_V01
            if (MSF_moduleIsRunning(MSF_MODID_MEA))
            {
                meaTerminateApp();
            }
        #endif /* OBIGO_Q03C_MMS_V01 */
            break;
        
        case MSG_ID_WAP_BROWSER_POWEROFF_REQ:
        {
            /*
             * Justin. Power off procedure
             * * Reference: wap_task_main
             */
            start_poweroff_watchdog();

            wap_action = WAP_ACTION_POWER_OFF;

            /* If WAP is currently running and is not in initialization process, then terminate WAP first. */
            if (wap_status == WAP_RUNNING && !MSF_wapIsInit())
            {
                wap_reset(INDX_WAP);
            }
            else
            {
                /* If wap task is not yet done with initialization, then do not perform termination
                   to avoid unexpected problems. Simply let the shutdown process continue. */
                wap_status = WAP_RESET_COMPLETE;
            }

            break;
            /* the subsequent MSF_fsm() might return prematurely
               before MSMa_terminated is executed if something is in the external queue */
        }

        case MSG_ID_TIMER_EXPIRY:
        {
				kal_uint16 timer_indx = evshed_get_index(ilm_ptr);

                switch (timer_indx)
                {
                    case MSF_FILE_TIMER_ID:
                #ifndef Q03C_IND_MOD_ARCH_SUPPORT
                        HDI_file_timer_expiry(ilm_ptr);
                #else
                        hdi_file_timer_expiry_hdlr();
                #endif /*Q03C_IND_MOD_ARCH_SUPPORT*/
                        break;
                    case MSF_MSM_TIMER_ID:
                        msf_timer_expiry_hdlr(ilm_ptr);
                        break;
					case MSF_WIDGET_TIMER_ID:
						widget_timer_expiry(ilm_ptr);
						break;
                }
            break;
        }

            /* KEY */
        case MSG_ID_WAP_MMI_KEY_INDICATION:
            widget_wap_mmi_key_ind(ilm_ptr);
            break;

            /* RPC (remote procedure call) */
        case MSG_ID_MMIAPI_REMOTE_PROC_CALL_REQ:
            widget_mmiapi_remote_proc_call_req(ilm_ptr);
            break;

    #ifdef OBIGO_Q03C_MMS_V01

        case MSG_ID_MMS_OBJ_IND:
            {
                extern void mmsRecvObjIndReq(mmi_mmsv01_agent_mms_obj_ind_struct *recv_push_info);
                mmsRecvObjIndReq((mmi_mmsv01_agent_mms_obj_ind_struct*) ilm_ptr->local_para_ptr);
            }
            break;
             
        case MSG_ID_MMS_TARGET_DATA_IND:
            {               
                mea_handle_target_dat_ind(ilm_ptr->src_mod_id, (mms_target_data_ind_struct*) 
                        ilm_ptr->local_para_ptr, (peer_buff_struct*) ilm_ptr->peer_buff_ptr);
                break;
            }
        case MSG_ID_MEA_STARTUP_REQ:
            {
                mea_startup_req_struct  *req = (mea_startup_req_struct*) ilm_ptr->local_para_ptr;
#ifdef MMS_V01_USE_ASM
                wapadp_set_mms_app_mem(req->asm_pool_id);
#endif
                if (req->folder_id == MEA_FOLDER_NONE)
                {
                    MSMc_startModule(MSF_MODID_MEA, "-mode menu");
                }
                else
                {
                    if (req->folder_id == MEA_FOLDER_INBOX)
                    {
                        MSMc_startModule(MSF_MODID_MEA, "-mode view");

                    }
                }

                
            }
            break;

        case MSG_ID_MEA_STARTUP_NEW_MMS_REQ:
        {
            mea_new_mms_req_struct *local_data = (mea_new_mms_req_struct*) ilm_ptr->local_para_ptr;
            mms_content_entry_struct_peer_buf *peer_pdu = NULL;
            MSF_UINT16 peer_pdu_len = 0;

#ifdef MMS_V01_USE_ASM
            wapadp_set_mms_app_mem(local_data->asm_pool_id);
#endif

            if (local_data->mode == MMS_NEW_FILE)
            {
                MEAc_startWithContentInserted((char*)local_data->commandInfo);
                meaMeRegisterExitCallback((func_ptr)local_data->funcPtr, local_data->funcParam);
            }
            else if (local_data->mode == MMS_NEW_BUFFER)
            {
                if (ilm_ptr->peer_buff_ptr)
                {
                    peer_pdu = (mms_content_entry_struct_peer_buf*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &peer_pdu_len);
                }

                MEAc_startWithTextInserted((char *)local_data->commandInfo, (char *)peer_pdu, local_data->isContentTruncated);
            }
            else if (local_data->mode == MMS_NEW_ADDRESS)
            {
                char *meaNewCmd;    /* [56]; */
                int size;
                char *strAddress;

                size = widget_ucs2_to_utf8_length_in_bytes((const kal_uint8*)local_data->commandInfo) + 1;
                strAddress = MSF_MEM_ALLOC(MSF_MODID_MSM, size + 1);
                widget_ucs2_to_utf8_string(
                    (kal_uint8*) strAddress,
                    size + 1,
                    (const kal_uint8*)local_data->commandInfo);

                //memset(meaNewCmd, 0x00, 56);  /* maximum phone number is 40. Notice: e-mail address will overflow*/
                //sprintf(meaNewCmd,"%s%lx\n","-mode new -to ", msgId);
                meaNewCmd = msf_cmmn_strcat(MSF_MODID_MSM, "-mode new -to ", (const char*)strAddress);
                MSMc_startModule(MSF_MODID_MEA, meaNewCmd);
                MSF_MEM_FREE(MSF_MODID_MSM, strAddress);
                MSF_MEM_FREE(MSF_MODID_MSM, meaNewCmd);
            }
            else if (local_data->mode == MMS_NEW_GENERAL)
            {
                if (ilm_ptr->peer_buff_ptr)
                {
                    peer_pdu = (mms_content_entry_struct_peer_buf*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &peer_pdu_len);
                }
        
                MEAc_startWithGeneralInserted((char *)peer_pdu->subject, (char *)peer_pdu->text_buffer, local_data->isContentTruncated, (char *)peer_pdu->addr, (char *)local_data->commandInfo);
                meaMeRegisterExitCallback((func_ptr)local_data->funcPtr, local_data->funcParam);
            }
#if defined(__MMI_URI_AGENT__) && defined(OBIGO_Q03C_MMS_V01)
            else if(local_data->mode == MMS_NEW_URI)
            {
                if (ilm_ptr->peer_buff_ptr)
                {
                    peer_pdu = (mms_content_entry_struct_peer_buf*) get_pdu_ptr(ilm_ptr->peer_buff_ptr, &peer_pdu_len);
                }
                MEAc_startWithURIInserted((char *)peer_pdu);
            }
#endif /* defined(__MMI_URI_AGENT__) && defined(OBIGO_Q03C_MMS_V01) */            
            break;
        }

#ifdef MMS_V01_USE_ASM
        case MSG_ID_MEA_SHUTDOWN_REQ:
            {
                /*Terminate MEA*/
                meaTerminateApp();
                break;

            }
#endif /* MMS_V01_USE_ASM*/

        case MSG_ID_MEA_SET_PROFILE_REQ:
            {   
                mea_handle_set_profile_req((srv_wap_prof_active_profile_changed_ind_struct*)ilm_ptr->local_para_ptr);        
                break;
            }

        case MSG_ID_MEA_ADD_BOOKMARK_RSP: /*Replace with correct "MSG_ID MSG_ID_WAP_SELECT_BOOKMARK_REQ"*/
            {
                mea_mmsV01_handle_add_bookmark_rsp((mmi_mmsv01_agent_add_bookmark_rsp_struct*)ilm_ptr->local_para_ptr);
                break;
            }
        case MSG_ID_MEA_GET_SETTING_RSP:
            {
                mea_mmsV01_agent_get_setting_rsp((void*) ilm_ptr->local_para_ptr);   
                break;
            }
        case MSG_ID_MEA_SET_SETTING_REQ:
            {
                mea_mmsV01_agent_set_setting_req((void*) ilm_ptr->local_para_ptr);   
                break;
            }

    #ifdef __MMI_MMS_IN_UM__ 
        case MSG_ID_MEA_UM_ENTRY_REQ:
        {
            mea_um_entry_req_struct *local_data = (mea_um_entry_req_struct*) ilm_ptr->local_para_ptr;

            switch ((MeaUmEntryTypeEnum) local_data->mode)
            {
                case MEA_UM_ENTRY_WRITE_MSG:
                    MEAif_createMessage(MSF_MODID_MSM);
                    break;
                case MEA_UM_ENTRY_READ_MSG:
                    MEAif_readMessage(MSF_MODID_MSM, local_data->msg_box, local_data->msg_index);
                    break;
                case MEA_UM_ENTRY_TEMPLATE:
                    MEAif_enterTemplate(MSF_MODID_MSM);
                    break;
                case MEA_UM_ENTRY_SETTING:
                    MEAif_enterSetting(MSF_MODID_MSM);
                    break;
                default:
                    ASSERT(0);
            }
            break;
        }
    #endif /* __MMI_MMS_IN_UM__ */ 

    #ifdef __USB_IN_NORMAL_MODE__

        case MSG_ID_MMS_ENTER_USB_MODE_REQ:
        {
            wap_send_mmi_mms_enter_usb_mode_rsp();
            break;
        }

        case MSG_ID_MMS_EXIT_USB_MODE_REQ:
        {
            if (is_mms_storage_exported_to_pc())    /* Check if MMS was disabled */
            {
                extern void mmsUpdateIndicator(void);            
                extern int directoryCleanupForUSB(unsigned char check, const char *dirName);
                (void)directoryCleanupForUSB(1, "/mms/"); /* MMS_FOLDER */
                mmsUpdateIndicator();
                HDIa_fileHideDir("/mms/"); /* MMS_FOLDER */
            }
            wap_send_mmi_mms_exit_usb_mode_rsp();
            break;
        }

    #endif /* __USB_IN_NORMAL_MODE__ */ 

        case MSG_ID_MMS_NMGR_INFO_REQ:
        {
            struct ilm_struct *ilm_ptr = NULL;
            mms_nmgr_info_rsp_struct *nmgr_rsp; 

            nmgr_rsp = (mms_nmgr_info_rsp_struct*) construct_local_para((kal_uint16) sizeof(mms_nmgr_info_rsp_struct), TD_CTRL);
	    nmgr_rsp->total_unread_num = meaWidgetResponseForUnreadMessage();
            ilm_ptr = allocate_ilm(MOD_WAP);
            ilm_ptr->local_para_ptr = (local_para_struct*) nmgr_rsp;
            ilm_ptr->msg_id = MSG_ID_MMS_NMGR_INFO_RSP;
            ilm_ptr->peer_buff_ptr = NULL;
            SEND_ILM(MOD_WAP, MOD_MMI, WAP_MMI_SAP, ilm_ptr);
        }
        break;
    #endif /* OBIGO_Q03C_MMS_V01 */ 

        case MSG_ID_TST_INJECT_STRING:
        {
            tst_inject_string_struct *inject_str = (tst_inject_string_struct*) (ilm_ptr->local_para_ptr);

            wap_proc_inject_string(inject_str);
            break;
        }

        case MSG_ID_WAP_STATUS_UPDATE_IND:
        {
            /*
             * Before WAP receives this message, MMI doesn't need send it again.
             * We don't need the mutex to protect the variable because MMI task
             * and WAP task have the same priority and won't access the variable
             * at the same time.
             */
#ifdef WIDGET_SUPPORT_SOUND
            widget_check_play_waiting_sound();
#endif /* WIDGET_SUPPORT_SOUND */
            WIPC_CTX->update_event_is_sent = 0;
            break;
        }

        
        case MSG_ID_WAP_MEM_CARD_PLUG_OUT:
        {
        #ifdef OBIGO_Q03C_MMS_V01
            #ifndef __UNIFIED_COMPOSER_SUPPORT__
                if (MSF_moduleIsRunning(MSF_MODID_MEA))
                {
                    if (TRUE == meaIsStartupModeNew() && !IsScreenPresent(wap_get_screen_id()))
                    {
                        meaTerminateApp();
                    }
                    else
                    {
                        meaMeRemoveInvalidObjects();
                    }
                }
            #endif /* __UNIFIED_COMPOSER_SUPPORT__ */
        #endif /* OBIGO_Q03C_MMS_V01 */
            break;
        }
#if defined (WAP_SUPPORT)  && defined(OBIGO_Q03C_MMS_V01)
         case MSG_ID_MMI_WAP_PROF_CFG_DTCNT_CNF:
         {
            extern void MEAif_WapProfCfgDtcntCnf(MSF_UINT8 app_id, MSF_UINT8 sim_id, MSF_INT8 profile_id, MSF_UINT8 response);
            srv_wap_prof_configure_dtcnt_cnf_struct *p;

            p = (srv_wap_prof_configure_dtcnt_cnf_struct*)ilm_ptr->local_para_ptr;
        
            MEAif_WapProfCfgDtcntCnf((MSF_UINT8)p->app_id,
                                  (MSF_UINT8)p->sim_id,
                                  (MSF_INT8)p->profile_id,
                                  (MSF_UINT8)p->response);
            break;
         }
#endif
         case MSG_ID_APP_CBM_BEARER_INFO_IND:
         {
           #ifdef OBIGO_Q03C_BROWSER
             app_cbm_bearer_info_ind_struct *soc_bearer_info = (app_cbm_bearer_info_ind_struct*) ilm_ptr->local_para_ptr;
             MSF_LOG_MSG_ARGS((HDI_LOG_TYPE_DETAILED_MEDIUM, MSF_MODID_BAM, BAM_HANDLE_BEARER_INFO, "BAM: handle bearer info : bam netid %d, account_id %d, state %d, bearer %d\n", bam_get_net_acc_id(), soc_bearer_info->account_id, soc_bearer_info->state, soc_bearer_info->bearer));
             if(soc_bearer_info->account_id == bam_get_net_acc_id())
             {
                if(((soc_bearer_info->bearer == CBM_CSD) && (soc_bearer_info->state == CBM_CSD_AUTO_DISC_TIMEOUT)) || ((soc_bearer_info->bearer & CBM_PS) && (soc_bearer_info->state == CBM_GPRS_AUTO_DISC_TIMEOUT)))
                {
                #if 0
/* under construction !*/
                #endif
                }
             }
            #endif
          break;
         }

#ifdef OBIGO_Q03C_BROWSER
		 case MSG_ID_WAP_CONTINUE_PROCESS_IND:
		 {
			 wap_continue_ind_struct *ilm_data;
			 ASSERT(ilm_ptr->local_para_ptr);

			 ilm_data = (wap_continue_ind_struct *) ilm_ptr->local_para_ptr;

    			 switch (ilm_data->signal_type)
			 {
			 case WAP_CONTINUE_BRS_HTTP_ABORT:
				 {
					 extern void brs_httpRequestAborted(MSF_UINT8 dst, int requestId, int errorCode);
					 brs_http_request_aborted_t *p = (brs_http_request_aborted_t *) ilm_data->data;

                     if (msm_get_module_status(MSF_MODID_BRS) == MODULE_STATUS_ACTIVE)  /* MAUI_02567888 */
                     {
					     brs_httpRequestAborted(ilm_data->dst_mod_id, p->requestId, p->errorCode);
					     MSF_MEM_FREE (MSF_MODID_BRS, (p));
                     }
				 }
			 break;

			 default:
				 /*
				  * leave blank.
				  */
			 break;
			 }
		 }

		 break;
#endif /* OBIGO_Q03C_BROWSER */

        default:
            break;
    }
    }
    free_ilm(ilm_ptr);
    if (wap_status != WAP_RESET_COMPLETE)
    {
        MSF_fsm();  /* process MSF signal */
    }

    if (is_shutdown_UI)
    {
        /* Finish processing WAP internal queue */
        widget_notify_shutdown_UI_finished();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_restart_task
 * DESCRIPTION
 *  This function is used to restart WAP when internal state is incorrect
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_restart_task(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(++restart_count < 5); */
    longjmp(wap_jmpbuf, 1);
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_int_queue_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint8 wap_get_int_queue_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return wap_int_q_size;
}


/*****************************************************************************
 * FUNCTION
 *  wap_is_int_q_full
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool wap_is_int_q_full(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (wap_int_q_size == WAP_INT_QUEUE_SIZE);
}


/*****************************************************************************
 * FUNCTION
 *  wap_read_int_q
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool wap_read_int_q(ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_int_q_size == 0)
    {
        return KAL_FALSE;
    }

    memcpy(ilm, wap_int_q_array + wap_int_q_read_index, sizeof(ilm_struct));

    if (ilm->msg_id == MSG_ID_TIMER_EXPIRY)
    {
        wap_is_timer_msg_in_int_q = KAL_FALSE;
    }

    wap_int_q_read_index++;
    if (wap_int_q_read_index == WAP_INT_QUEUE_SIZE)
    {
        wap_int_q_read_index = 0;
    }
    wap_int_q_size--;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_write_int_q
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ilm     [?]     
 * RETURNS
 *  
 *****************************************************************************/
static kal_bool wap_write_int_q(ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_int_q_size == WAP_INT_QUEUE_SIZE)
    {
        return KAL_FALSE;
    }

    memcpy(wap_int_q_array + wap_int_q_write_index, ilm, sizeof(ilm_struct));
    wap_int_q_write_index++;
    if (wap_int_q_write_index == WAP_INT_QUEUE_SIZE)
    {
        wap_int_q_write_index = 0;
    }
    wap_int_q_size++;

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_fetch_msg_to_int_q
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_fetch_msg_to_int_q(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_get_queue_size() > WIDGET_QUEUE_SIZE_HIGH_WATERMARK)
    {
        /* Try to get the message from external queue to internal queue */
        while (!wap_is_int_q_full() && wap_get_queue_size())
        {
            receive_msg_ext_q(wap_ext_qid, &current_ilm);

            if (current_ilm.msg_id == MSG_ID_TIMER_EXPIRY)
            {
                if (wap_is_timer_msg_in_int_q == KAL_FALSE)
                {
                    /* There is no timer_expiry msg in intQ */
                    wap_write_int_q(&current_ilm);
                    wap_is_timer_msg_in_int_q = KAL_TRUE;
                }
                else
                {
                    /* drop timer_expiry msg because there is one msg in intQ */
                    /*Need to be reviewed by TK*/
                }
            }
            else
            {
                wap_write_int_q(&current_ilm);
                hold_local_para(current_ilm.local_para_ptr);
                hold_peer_buff(current_ilm.peer_buff_ptr);
            }
            free_ilm(&current_ilm);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_get_queue_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 wap_get_queue_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 queue_node_number = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_get_ext_queue_info(wap_ext_qid, &queue_node_number);

    return queue_node_number;
}


/*****************************************************************************
 * FUNCTION
 *  wap_task_main
 * DESCRIPTION
 *  This function is used to be WAP task entry point
 * CALLS
 *  
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void wap_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wap_init_framework();
    kal_get_my_task_index(&my_index);

#ifdef WAP_QUEUE_SMS_PUSH
    {
        extern void HDI_registerSmsPush(void);

        HDI_registerSmsPush();
    }
#endif /* WAP_QUEUE_SMS_PUSH */ 

    msm_remove_files_under_dir(WAP_DOWNLOAD_FOLDER);

    memset(wap_int_q_array, 0, sizeof(ilm_struct) * WAP_INT_QUEUE_SIZE);
    wap_ext_qid = task_info_g[task_entry_ptr->task_indx].task_ext_qid;

    while (1)
    {
        widget_waiting_external_queue();
        if (wap_get_int_queue_size() == 0)
        {
            receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        }
        else
        {
            wap_read_int_q(&current_ilm);
        }
        widget_finish_external_queue();

        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

        if (setjmp(wap_jmpbuf) == 0)
        {
            wap_fsm(&current_ilm);  /* process external ILM */
        }
        else
        {
        #ifdef WPS_TASK_SUPPORT
            /* force the mutex owner to release because the control is out from Msf_fsm and Msf_wps_fsm */
            extern kal_mutexid wap_ctrl_mutex;
            extern kal_bool wap_in_critical_section;
            
            if(wap_in_critical_section == KAL_TRUE)
            {
                kal_give_mutex(wap_ctrl_mutex);
            }
        #endif /* WPS_TASK_SUPPORT */ 
            if (wap_action == WAP_ACTION_POWER_OFF)
            {
                /*
                 * exception happen in the last termination procedure invoked in wap_fsm()
                 * * We shall NOT call MSMc_terminateMobileSuite because it might become
                 * * infinite loop
                 */
                break;
            }
#ifdef MSF_NEW_EXCEPTION_HANDLING
            {
                extern MSF_UINT8 MSF_getExceptionPool(void);
                extern void wapadp_mem_enable_spare_mem(MSF_UINT8 modId);

                if(MSF_getExceptionPool() == WAP_MEM_POOL)
                {
                    wapadp_mem_enable_spare_mem(0);
#endif					
            /* Exception happen so terminate Mobile Suite */
                    wap_action = WAP_ACTION_RESET;
                    wap_reset(task_entry_ptr->task_indx);
#ifdef MSF_NEW_EXCEPTION_HANDLING
                }
#ifdef BROWSER_SUPPORT
                else
                { 
                    extern void brs_abort();
                    brs_abort();
                }
#endif
            }           
#endif
            MSF_fsm();
        }

        if (wap_status == WAP_RESET_COMPLETE)
        {
            /* Note that MSMa_terminated and wap_deinit was called before this point */
            if (wap_action == WAP_ACTION_POWER_OFF)
            {
                break;  /* We don't restart WAP again */
            }
            else if (wap_action == WAP_ACTION_RESET_BEFORE_RESTORE_FACTORY_SETTING)
            {
                wap_delete_all_files(); /* delete all wap related files for restore factory setting */
                wap_action = WAP_ACTION_NONE;
                wap_send_mmi_restore_factory_cnf();
                break;
            }
            else if (wap_action == WAP_ACTION_SHUTDOWN)
            {
                wap_init_framework();
                MSF_start(KAL_FALSE, NULL);
                MSF_fsm();
            }
            else if (wap_action == WAP_ACTION_FMT_FORMAT)
            {
                wap_init_framework();
                MSF_start(KAL_TRUE, wap_send_fmt_format_rsp);
                MSF_fsm();
            }
            else if (wap_action == WAP_ACTION_RESET)
            {
                	wap_init_framework();
					MSF_start(KAL_FALSE, NULL);
					MSF_fsm();
#ifdef OBIGO_Q03C_BROWSER
                    HDIa_widgetExtShowPopupWithType(MSF_MODID_MSM, 
                        MSF_WIDGET_STRING_GET_PREDEFINED(MSF_STR_ID_INTERNAL_ERROR), 
                        MsfFailure);
#else
#ifdef Q03C_IND_MOD_ARCH_SUPPORT
                    MSF_DISPLAY_ERROR();
#endif
#endif
#ifdef OBIGO_Q03C_BROWSER
                bam_msg_out_of_mem_wap_reset_ind();
#endif
            }
        }
    }

    /*
     * Power off at this point
     * * it is critical to tell MMI that WAP is completed
     * * otherwise MMI will not finish the poweroff procedure
     */
    notifiy_mmi_wap_poweroff_completed();

    /*
     * dummy loop
     * * We don't want busy wait here
     */
    for (;;)
    {
        receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        free_ilm(&current_ilm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wap_create
 * DESCRIPTION
 *  This function is used to create CC task
 * CALLS
 *  
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_bool wap_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct ms_handler_info = 
    {
        wap_task_main,  /* task entry function */
        wap_init,       /* task initialization function */
        NULL,           /* task configuration function */
        NULL,           /* task reset handler */
        NULL,           /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) & ms_handler_info;
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  wap_support_background_image
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
int wap_support_background_image(void)
{
#ifdef OBIGO_Q03C_BROWSER
    /* 
     * WAP_CUSTOM_CFG_SUPPORT_BACKGROUND_IMAGE is defined in custom_wap_config.h
     * 
     * WAP supports background image has the defect.
     * The marquee donesn't work well when enable backgound image.
     * The marguee's background color is white and overlap the background image.
     */
/* MAUI_03076686 starts */
#if (defined(__OP01__) || defined(__OP02__))
    return 0;
#endif
/* MAUI_03076686 ends */

#ifdef WAP_CUSTOM_CFG_SUPPORT_BACKGROUND_IMAGE
    return 1;
#else
    return 0;
#endif
#else
    return 0;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  wap_min_background_image_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  min_w - returns min width
 *  min_h - returns min height
 * RETURNS
 *  void
 *****************************************************************************/
void wap_min_background_image_size(int* min_w, int* min_h)
{
#ifdef OBIGO_Q03C_BROWSER
    /* 
     * WAP_CUSTOM_CFG_SUPPORT_MIN_BACKGROUND_IMAGE_WIDTH and
     * WAP_CUSTOM_CFG_SUPPORT_MIN_BACKGROUND_IMAGE_HEIGHT
     * is defined in custom_wap_config.h
     * 
     */
    *min_w = WAP_CUSTOM_CFG_SUPPORT_MIN_BACKGROUND_IMAGE_WIDTH;
    *min_h = WAP_CUSTOM_CFG_SUPPORT_MIN_BACKGROUND_IMAGE_HEIGHT;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  wap_max_background_image_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  max_w - returns max width
 *  max_h - returns max height
 * RETURNS
 *  void
 *****************************************************************************/
void wap_max_background_image_size(int* max_w, int* max_h)
{
#ifdef OBIGO_Q03C_BROWSER
    /* 
     * WAP_CUSTOM_CFG_SUPPORT_MAX_BACKGROUND_IMAGE_WIDTH and
     * WAP_CUSTOM_CFG_SUPPORT_MAX_BACKGROUND_IMAGE_HEIGHT
     * is defined in custom_wap_config.h
     * 
     */
    *max_w = WAP_CUSTOM_CFG_SUPPORT_MAX_BACKGROUND_IMAGE_WIDTH;
    *max_h = WAP_CUSTOM_CFG_SUPPORT_MAX_BACKGROUND_IMAGE_HEIGHT;
#endif
}

static void wap_default_settings_done(void)
{
    if (wap_action  == WAP_ACTION_POWER_ON)
    {
        wap_action = WAP_ACTION_NONE;
    }
    else if ((wap_action == WAP_ACTION_RESTORE_FACTORY_SETTING) || (wap_action == WAP_ACTION_FIRST_POWER_ON))
    {
#ifdef OBIGO_Q03C_BROWSER
        wap_reserve_file(BAM_CFG_HISTORY_LIST_FILE_PATH, BAM_CFG_HISTORY_INITIAL_SIZE);
        wap_action = WAP_ACTION_NONE;
#endif
    }
    if (wap_status == WAP_RESET_COMPLETE)
    {
        MSF_start(KAL_TRUE, wap_ready_callback_func);
    }
#ifdef OBIGO_Q03C_MMS_V01
    mms_unread_check();
#endif    
}
