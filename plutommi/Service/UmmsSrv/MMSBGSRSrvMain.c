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
 *  MMSBGSRSrvMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contans the Event Handlers and Main flow of the MMS BGSR Application.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_MMS_BGSR_SUPPORT__) && !defined(__MMI_MMS_LOW_TIER_BGSR_SUPPORT__)


#include "CommonScreens.h"
#include "time.h"

#include "FileManagerGProt.h"
/* For Bearer Type */
#include "Custom_nvram_editor_data_item.h"

#ifndef __MMI_BGSR_PROT_H_
#include "MMSBGSRSrvProt.h"
#endif 

#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
#include "USBSrvGProt.h"
#endif 
#if (defined(__UNIFIED_COMPOSER_SUPPORT__) || defined(__MMS_STANDALONE_COMPOSER_SUPPORT__))
#include "UcSrvGprot.h"
#endif 
#if defined(OBIGO_Q03C_MMS_V01)
#include "msf_def.h"
#include "Mea_int.h"
#endif /* defined(OBIGO_Q03C_MMS_V01) */ 
#ifdef __MMI_MMS_2__
#include "MmsSrvGprot.h"
#ifdef __MMI_UMMS_JSR205__
#include "MMSJSRSrvProts.h"
#endif 
#endif /* __MMI_MMS_2__ */ 
#include "WAPProfSrvconfig.h"
#include "WAPProfileSrvGProt.h"
#ifdef __MMI_MMS_FALLBACK__
#include "cbm_api.h"
#include "WAPProfileSrvType.h"
#include "CbmSrvGprot.h"        /* For CBM related APIs and enum */
#include "CbmCuiGprot.h"        /* For the CBM CUI related APIs */
#endif /* __MMI_MMS_FALLBACK__ */ 
#include "SettingGprots.h"
#include "UcmSrvGprot.h"
#ifdef __DM_LAWMO_SUPPORT__
#include "DmSrvGprot.h"
#endif 
#include "kal_general_types.h"
#include "MmsSrvGprot.h"
#include "mma_api.h"
#include "mmi_rp_srv_mms_def.h"
#include "mmi_frm_timer_gprot.h"        /* StartTimer is also declared in MMITimer_Int.h */
#include "MMI_inet_app_trc.h"
#include "kal_public_api.h"
#include "string.h"
#include "mma_struct.h"
#include "UmSrvGprot.h"
#include "fs_type.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "FileMgrSrvGProt.h"
#include "gui_data_types.h"
#include "stack_ltlcom.h"
#include "ModeSwitchSrvGprot.h"
#include "MMIDataType.h"        /* required for mmi sim id */
#include "SimCtrlSrvGprot.h"    /* required for sim_is_blocked */
#include "Cbm_consts.h"
/* TRACE */

/*******************************************************************************
 * Static Declaration
 *******************************************************************************/
srv_mms_bgsr_context_struct g_srv_mms_bgsr_context;
srv_mms_bgsr_context_struct *srv_mms_bgsr_p = &g_srv_mms_bgsr_context;
kal_uint8 srv_mms_bgsr_adm_mem[SRV_MMS_BGSR_ADM_MEM_SIZE];
srv_mms_bgsr_msg_struct ph_mem_msg_array[SRV_MMS_BGSR_MAX_MSG_NUM];
U8 ph_mem_next_array[SRV_MMS_BGSR_MAX_MSG_NUM];

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
srv_mms_bgsr_msg_struct mem_card_msg_array[SRV_MMS_BGSR_MAX_MSG_NUM];
U8 mem_card_next_array[SRV_MMS_BGSR_MAX_MSG_NUM];
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
/*******************************************************************************
 * Global Variable
 *******************************************************************************/
/* SRV_MMS_BGSR_CFG_RETRY_INTERVAL can be customized */
static kal_uint8 SRV_MMS_BGSR_CFG_RETRY_INTERVAL[SRV_MMS_BGSR_CFG_RETRY_QUOTA] = {2, 2};

/* please specify the callback funciton here */
extern srv_mms_bgsr_callback_struct srv_mms_bgsr_callback_table
    [SRV_MMS_BGSR_TOTAL_SOLUTION_NUM][SRV_MMS_BGSR_CALLBACK_NUM] = 
    {
    #if defined(OBIGO_Q03C_MMS_V01)
    {mmi_mms_send_rsp_callback,
     mmi_mms_cancel_send_rsp_callback,
     mmi_mms_download_rsp_callback,
     mmi_mms_cancel_download_rsp_callback,
     mmi_mms_update_folder_callback,
     mmi_mms_update_menu_callback},
    #else /* defined(OBIGO_Q03C_MMS_V01) */ /* OBIGO_Q05A */
    {srv_mms_send_rsp,
     srv_mms_cancel_send_rsp,
     srv_mms_download_rsp,
     srv_mms_cancel_download_rsp,
     srv_mms_update_folder_callback,
     srv_mms_update_menu_callback},
    #endif /* defined(OBIGO_Q03C_MMS_V01) */ 
    {
     NULL,
     NULL,
     NULL,
     NULL,
     NULL}
};

/*******************************************************************************
 * Local Function
 *******************************************************************************/

/*******************************************************************************
 * Global Function
 *******************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_init
 * DESCRIPTION
 *  init the bgsr module
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 message = 0;

#ifdef __MMI_MMS_FALLBACK__
    U8 i = 0;
    U8 bgsr_sim_id = 0;
    kal_uint32 cbm_appid = 0;
#endif /* __MMI_MMS_FALLBACK__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    srv_mms_bgsr_init_context();    /* init context */
    srv_mms_bgsr_set_protocol_event_handler();
    srv_mms_bgsr_create_adm_mem();  /* create adm memory */
    srv_mms_bgsr_init_ph_mem_file_system();
    srv_mms_bgsr_init_msg_array();  /* init array */
    g_srv_mms_bgsr_context.bgsr_state = SRV_MMS_BGSR_STATE_ACTIVE;
    srv_mms_bgsr_sync(MMA_MSG_STORAGE_PHONE);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_NONE;
#endif 
    if (srv_mms_bgsr_is_ph_sync())
    {
        StartTimer(SRV_MMS_BGSR_TIMER, SRV_MMS_BGSR_CFG_RETRY_TIMER * 60000, srv_mms_bgsr_timeout_procedure);
    }
    else
    {
        StartTimer(SRV_MMS_BGSR_TIMER, SRV_MMS_BGSR_FAST_TIMEOUT_TIMER, srv_mms_bgsr_timeout_procedure);
    }

#ifdef __MMI_MMS_FALLBACK__
    /*
     * 1. get CBM app id from wap prof
     * 2. register to CBM by the app id
     */

    g_srv_mms_bgsr_context.acct_id = 0;
    g_srv_mms_bgsr_context.fallback_send_id = 0;
    g_srv_mms_bgsr_context.fallback_sim_id = 0;
    g_srv_mms_bgsr_context.fallback_download_id = 0;
    g_srv_mms_bgsr_context.fallback_mask = 0;

    for (i = 1; i <= MMA_MAX_SIM_COUNT; i++)
    {
        /* converts into bgsr sim ids 1,2,4,8... */
        bgsr_sim_id = srv_mms_bgsr_convert_index(i);
        cbm_appid = srv_wap_prof_get_cbm_app_id(
                        SRV_WAP_PROF_APPID_MMS,
                        srv_mms_bgsr_convert_bgsr_sim_id_to_wap_prof(bgsr_sim_id));
        srv_cbm_register_bearer_event(
            SRV_CBM_BEARER_FB_L1_WITH_NEW_CONN,
            cbm_appid,
            srv_mms_bgsr_bearer_fallback_proc,
            NULL);
        srv_cbm_register_bearer_event(
            SRV_CBM_BEARER_FB_L2_WITH_NEW_CONN,
            cbm_appid,
            srv_mms_bgsr_bearer_fallback_proc,
            NULL);
    }
#endif /* __MMI_MMS_FALLBACK__ */ 

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    g_srv_mms_bgsr_context.vendor_send_msg_id = 0;
    g_srv_mms_bgsr_context.vendor_sim_id = 0;
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 

    if (srv_mms_bgsr_is_ready())
    {
        /* start to send and download message */
        message = srv_mms_bgsr_get_next_sending_node();
        if (message != 0)
        {
            srv_mms_bgsr_send_mms_req(message);
        }
        else
        {
            g_srv_mms_bgsr_context.send_msg_id = 0;
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CLEAR_SEND_ID);
        }

        message = srv_mms_bgsr_get_next_downloading_node();
        if (message != 0)
        {
            srv_mms_bgsr_download_mms_req(message);
        }
        else
        {
            g_srv_mms_bgsr_context.download_msg_id = 0;
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CLEAR_DOWNLOAD_ID);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_terminate
 * DESCRIPTION
 *  terminate the bgsr module
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_terminate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(SRV_MMS_BGSR_TIMER);
    kal_adm_free(g_srv_mms_bgsr_context.mem_pool_id, ph_mem_msg_array);
    kal_adm_delete(g_srv_mms_bgsr_context.mem_pool_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_init_context
 * DESCRIPTION
 *  init the bgsr context
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_init_context(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    memset(srv_mms_bgsr_p, 0, sizeof(srv_mms_bgsr_context_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_set_protocol_event_handler
 * DESCRIPTION
 *  Set protocol event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_set_protocol_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_NOTIFY_EVENT_IND,
        (PsIntFuncPtr) srv_mms_bgsr_delete_folder_ind_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_DOWNLOAD_RSP,
        (PsIntFuncPtr) srv_mms_bgsr_download_mms_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_DOWNLOAD_IND,
        (PsIntFuncPtr) srv_mms_bgsr_download_mms_ind_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_CANCEL_DOWNLOAD_RSP,
        (PsIntFuncPtr) srv_mms_bgsr_abort_download_mms_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_SEND_IND,
        (PsIntFuncPtr) srv_mms_bgsr_send_mms_ind_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_SEND_RSP, (PsIntFuncPtr) srv_mms_bgsr_send_mms_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_CANCEL_SEND_RSP,
        (PsIntFuncPtr) srv_mms_bgsr_abort_send_mms_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_DELETE_RSP, (PsIntFuncPtr) srv_mms_bgsr_delete_mms_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WAP_MMA_SAVE_RSP, (PsIntFuncPtr) srv_mms_bgsr_save_mms_rsp, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_START_IMMED_RETRIEVAL_IND,
        (PsIntFuncPtr) srv_mms_bgsr_start_immd_retr_ind,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_STOP_IMMED_RETRIEVAL_IND,
        (PsIntFuncPtr) srv_mms_bgsr_stop_immd_retr_ind,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_MSG_IS_VALID_RSP,
        (PsIntFuncPtr) srv_mms_bgsr_msg_is_valid_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_READY_IND,
        (PsIntFuncPtr) srv_mms_bgsr_mma_ready_ind_hdlr,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_TERMINATE_IND,
        (PsIntFuncPtr) srv_mms_bgsr_mma_terminate_ind_hdlr,
        MMI_TRUE);
#ifdef __MMI_MMS_FALLBACK__
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_SUSPEND_MMS_SERVICE_RSP,
        (PsIntFuncPtr) srv_mms_bgsr_suspend_mms_service_rsp,
        MMI_TRUE);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_WAP_MMA_RESUME_MMS_SERVICE_RSP,
        (PsIntFuncPtr) srv_mms_bgsr_resume_mms_service_rsp,
        MMI_TRUE);
#endif /* __MMI_MMS_FALLBACK__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_create_adm_mem
 * DESCRIPTION
 *  create adm memory
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_create_adm_mem(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    g_srv_mms_bgsr_context.mem_pool_id = kal_adm_create(
                                            srv_mms_bgsr_adm_mem,
                                            SRV_MMS_BGSR_ADM_MEM_SIZE,
                                            NULL,
                                            KAL_FALSE);

    MMI_ASSERT(g_srv_mms_bgsr_context.mem_pool_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_init_msg_array
 * DESCRIPTION
 *  synchronization
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_init_msg_array(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_MMS_BGSR_MAX_MSG_NUM; i++)
    {
        ph_mem_next_array[i] = 0;
        if (ph_mem_msg_array[i].msg_id != 0)
        {
            switch (ph_mem_msg_array[i].status)
            {
                case SRV_MMS_BGSR_STATUS_SENDING:
                    srv_mms_bgsr_set_no_of_tries((U8) (i + 1), (U8) (srv_mms_bgsr_get_no_of_tries((U8) (i + 1)) + 1));
                case SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND:
                case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND:
                    if (ph_mem_msg_array[i].ntt == 0)
                    {
                        ph_mem_msg_array[i].status = SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND;
                        srv_mms_bgsr_enqueue((U8) (i + 1), &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
                    }
                    else
                    {
                        ph_mem_msg_array[i].status = SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND;
                        srv_mms_bgsr_enqueue((U8) (i + 1), &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                    }
                    break;
                case SRV_MMS_BGSR_STATUS_DOWNLOADING:
                    srv_mms_bgsr_set_no_of_tries((U8) (i + 1), (U8) (srv_mms_bgsr_get_no_of_tries((U8) (i + 1)) + 1));
                case SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD:
                case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD:
                    if (ph_mem_msg_array[i].ntt == 0)
                    {
                        ph_mem_msg_array[i].status = SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD;
                        srv_mms_bgsr_enqueue((U8) (i + 1), &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));
                    }
                    else
                    {
                        ph_mem_msg_array[i].status = SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD;
                        srv_mms_bgsr_enqueue((U8) (i + 1), &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
                    }

                    break;
                case SRV_MMS_BGSR_STATUS_SEND_FAIL:
                case SRV_MMS_BGSR_STATUS_DEFERRED_FOR_SEND:
                case SRV_MMS_BGSR_STATUS_SAVING:
                case SRV_MMS_BGSR_STATUS_DELETING:
                    srv_mms_bgsr_enqueue((U8) (i + 1), &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                    break;
                case SRV_MMS_BGSR_STATUS_DOWNLOAD_FAIL:
                case SRV_MMS_BGSR_STATUS_DEFERRED_FOR_DOWNLOAD:
                    srv_mms_bgsr_enqueue((U8) (i + 1), &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
                    break;
                default:
                    ph_mem_msg_array[i].msg_id = 0;
                    srv_mms_bgsr_enqueue((U8) (i + 1), &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
                    break;
            }
        }
        else
        {
            srv_mms_bgsr_enqueue((U8) (i + 1), &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_timeout_procedure
 * DESCRIPTION
 *  timeout procedure,
 *  1. decrease the ntt (and expire time for DL q)
 *  2. move the msg to send / download q
 *  3. deliver the request to send and downlaod
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_timeout_procedure(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    U8 message = 0;
    U8 to_move_msg = 0;
    kal_uint32 move_msg_id = 0;
    U8 update = 0;
    kal_bool is_file_modfication_required = KAL_FALSE;
    kal_bool is_record_moved = KAL_FALSE;
    kal_bool is_valid_data_account = KAL_TRUE;
    U8 bgsr_sim_id = 0;
    U8 i = 0;
    srv_mms_bgsr_msg_struct *curr_node;

    U32 is_valid_sim_data_account = 0;  /* Each bit is for only one sim..i.e 0th bit for sim1, 1st bit for sim2..so on.....bit value 0=>INVALID & 1=>VALID */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_TIMEOUT_PROCEDURE, __LINE__);

    if (!srv_mms_bgsr_is_ph_sync())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NOT_SYNC, __LINE__);
        srv_mms_bgsr_sync(MMA_MSG_STORAGE_PHONE);
        StartTimer(SRV_MMS_BGSR_TIMER, SRV_MMS_BGSR_FAST_TIMEOUT_TIMER, srv_mms_bgsr_timeout_procedure);

        return;
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if ((g_srv_mms_bgsr_context.mem_card_state == SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN) &&
        !srv_mms_bgsr_is_mem_card_sync())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NOT_SYNC, __LINE__);
        srv_mms_bgsr_sync(MMA_MSG_STORAGE_CARD1);
    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 


    if (g_srv_mms_bgsr_context.srv_mms_bgsr_send_q ||
        g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q ||
        g_srv_mms_bgsr_context.srv_mms_bgsr_download_q || g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q)
    {
        for (i = 1; i <= MMA_MAX_SIM_COUNT; i++)
        {
            /* converts into bgsr sim ids 1,2,4,8... */
            bgsr_sim_id = srv_mms_bgsr_convert_index(i);
            if (srv_wap_prof_is_dtcnt_valid(
                    srv_mms_bgsr_convert_bgsr_sim_id_to_wap_prof(bgsr_sim_id),
                    SRV_WAP_PROF_APPID_MMS,
                    (U8) - 1))
            {
                is_valid_sim_data_account |= bgsr_sim_id;
            }
        }
    }
    else
    {
        StartTimer(SRV_MMS_BGSR_TIMER, SRV_MMS_BGSR_CFG_RETRY_TIMER * 60000, srv_mms_bgsr_timeout_procedure);
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_TIMEOUT_PROCEDURE_FINISH, __LINE__);
        return;
    }

    message = g_srv_mms_bgsr_context.srv_mms_bgsr_send_q;
    while (message != 0)
    {
        is_record_moved = KAL_FALSE;
        curr_node = srv_mms_bgsr_get_msg_array(message);
        if (!(srv_mms_bgsr_convert_mma_sim_id_to_bgsr_sim_id(curr_node->sim_id) & is_valid_sim_data_account))
        {
            if (curr_node->msg_id != g_srv_mms_bgsr_context.send_msg_id)
            {
                is_record_moved = KAL_TRUE;
                curr_node->status = SRV_MMS_BGSR_STATUS_SEND_FAILED_INVALID_DATA_ACCOUNT;
                move_msg_id = curr_node->msg_id;
                message = *(srv_mms_bgsr_get_next_array(message));
                to_move_msg = srv_mms_bgsr_extract_q(move_msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
                srv_mms_bgsr_enqueue(to_move_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback)
                    (srv_mms_bgsr_get_msg_array(to_move_msg)->msg_id, SRV_MMS_BGSR_UPDATE_STATUS);

            }
        }

        if (is_record_moved == KAL_FALSE)
        {
            message = *(srv_mms_bgsr_get_next_array(message));
        }

    }

    /* for download_q */

    message = g_srv_mms_bgsr_context.srv_mms_bgsr_download_q;
    while (message != 0)
    {
        is_record_moved = KAL_FALSE;
        curr_node = srv_mms_bgsr_get_msg_array(message);

        if (!(srv_mms_bgsr_convert_mma_sim_id_to_bgsr_sim_id(curr_node->sim_id) & is_valid_sim_data_account))
        {
            if (curr_node->msg_id != g_srv_mms_bgsr_context.download_msg_id)
            {
                is_record_moved = KAL_TRUE;
                curr_node->status = SRV_MMS_BGSR_STATUS_DOWNLOAD_FAILED_INVALID_DATA_ACCOUNT;
                move_msg_id = curr_node->msg_id;
                message = *(srv_mms_bgsr_get_next_array(message));
                to_move_msg = srv_mms_bgsr_extract_q(move_msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));
                srv_mms_bgsr_enqueue(to_move_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
                (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback)
                    (srv_mms_bgsr_get_msg_array(to_move_msg)->msg_id, SRV_MMS_BGSR_UPDATE_STATUS);

            }
        }

        if (is_record_moved == KAL_FALSE)
        {
            message = *(srv_mms_bgsr_get_next_array(message));
        }
    }

    /* decrease the next transmission time of each msg in send fail q */
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_DECREASE_NTT, __LINE__);
    message = g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q;
    while (message != 0)
    {
        is_record_moved = KAL_FALSE;
        is_valid_data_account = KAL_TRUE;
        curr_node = srv_mms_bgsr_get_msg_array(message);
        if ((curr_node->status == SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND
             || curr_node->status == SRV_MMS_BGSR_STATUS_SEND_FAILED_INVALID_DATA_ACCOUNT
            ) && curr_node->result != SRV_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT)
        {

            if (srv_mms_bgsr_convert_mma_sim_id_to_bgsr_sim_id(curr_node->sim_id) & is_valid_sim_data_account)
            {
                if (curr_node->status != SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND)
                {
                    curr_node->status = SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND;
                    update |= SRV_MMS_BGSR_UPDATE_STATUS;
                }
            }
            else
            {
                is_valid_data_account = KAL_FALSE;
                if (curr_node->status != SRV_MMS_BGSR_STATUS_SEND_FAILED_INVALID_DATA_ACCOUNT)
                {
                    curr_node->status = SRV_MMS_BGSR_STATUS_SEND_FAILED_INVALID_DATA_ACCOUNT;
                    update |= SRV_MMS_BGSR_UPDATE_STATUS;
                }
            }


            if (curr_node->ntt > 0)
            {
                curr_node->ntt--;
                update |= SRV_MMS_BGSR_UPDATE_NTT;
            }

            if (curr_node->ntt == 0 && (curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO) > 0 &&
                is_valid_data_account == KAL_TRUE)
            {
                is_record_moved = KAL_TRUE;
                is_file_modfication_required = KAL_TRUE;
                move_msg_id = curr_node->msg_id;
                curr_node->status = SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND;
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
                message = *(srv_mms_bgsr_get_next_array(message));
                to_move_msg = srv_mms_bgsr_extract_q(move_msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                srv_mms_bgsr_enqueue(to_move_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
            }

            if (update != 0)
            {
                (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (curr_node->msg_id, update);
                update = 0;
            }
        }
        if (is_record_moved == KAL_FALSE)
            message = *(srv_mms_bgsr_get_next_array(message));
    }

    /* decrease the next transmission time of each msg in download fail q */
    message = g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q;
    while (message != 0)
    {
        is_record_moved = KAL_FALSE;
        is_valid_data_account = KAL_TRUE;
        curr_node = srv_mms_bgsr_get_msg_array(message);
        if ((curr_node->status == SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD
             || curr_node->status == SRV_MMS_BGSR_STATUS_DOWNLOAD_FAILED_INVALID_DATA_ACCOUNT
            ) && curr_node->result != SRV_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT)
        {


            if (srv_mms_bgsr_convert_mma_sim_id_to_bgsr_sim_id(curr_node->sim_id) & is_valid_sim_data_account)
            {
                if (curr_node->status != SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD)
                {
                    curr_node->status = SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD;
                    update |= SRV_MMS_BGSR_UPDATE_STATUS;
                }
            }
            else
            {
                is_valid_data_account = KAL_FALSE;
                if (curr_node->status != SRV_MMS_BGSR_STATUS_DOWNLOAD_FAILED_INVALID_DATA_ACCOUNT)
                {
                    curr_node->status = SRV_MMS_BGSR_STATUS_DOWNLOAD_FAILED_INVALID_DATA_ACCOUNT;
                    update |= SRV_MMS_BGSR_UPDATE_STATUS;
                }
            }


            if (curr_node->ntt > 0)
            {
                curr_node->ntt--;
                update |= SRV_MMS_BGSR_UPDATE_NTT;
            }

            if (curr_node->ntt == 0 && (curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO) > 0 &&
                is_valid_data_account == KAL_TRUE)
            {
                is_record_moved = KAL_TRUE;
                is_file_modfication_required = KAL_TRUE;
                move_msg_id = curr_node->msg_id;
                curr_node->status = SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD;
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
                message = *(srv_mms_bgsr_get_next_array(message));
                to_move_msg = srv_mms_bgsr_extract_q(
                                move_msg_id,
                                &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
                srv_mms_bgsr_enqueue(to_move_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));
            }
        }
        if (update != 0)
        {
            (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (curr_node->msg_id, update);
            update = 0;
        }
        if (is_record_moved == KAL_FALSE)
            message = *(srv_mms_bgsr_get_next_array(message));
    }

    if (is_file_modfication_required == KAL_TRUE)
    {
        srv_mms_bgsr_write_into_ph_mem_file();
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        srv_mms_bgsr_write_into_mem_card_file();
    #endif 
    }

    if (srv_mms_bgsr_is_ready())
    {
        /* if there is no msg sending, deliver the send req */
        if (g_srv_mms_bgsr_context.send_msg_id == 0)
        {
            message = srv_mms_bgsr_get_next_sending_node();
            if (message != 0)
            {
                srv_mms_bgsr_send_mms_req(message);
            }
        }
        else
        {
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                SRV_MMS_BGSR_ALREADY_A_SENDING_MSG,
                g_srv_mms_bgsr_context.send_msg_id,
                __LINE__);
        }

        /* if there is no msg downloading, deliver the download req */
        if (g_srv_mms_bgsr_context.download_msg_id == 0 && g_srv_mms_bgsr_context.immd_retr_sim_id == 0)
        {
            message = srv_mms_bgsr_get_next_downloading_node();
            if (message != 0)
            {
                srv_mms_bgsr_download_mms_req(message);
            }
            else
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CLEAR_DOWNLOAD_ID);
            }
        }
        else
        {
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                SRV_MMS_BGSR_ALREADY_A_DOWNLOAD_MSG,
                g_srv_mms_bgsr_context.download_msg_id,
                __LINE__);
        }
    }

    StartTimer(SRV_MMS_BGSR_TIMER, SRV_MMS_BGSR_CFG_RETRY_TIMER * 60000, srv_mms_bgsr_timeout_procedure);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_TIMEOUT_PROCEDURE_FINISH, __LINE__);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_translate_result
 * DESCRIPTION
 *  translate mms result into mms bgsr result
 * PARAMETERS
 *  mma_result      [IN]        
 * RETURNS
 *  srv_mms_bgsr_result_enum
 *****************************************************************************/
srv_mms_bgsr_result_enum srv_mms_bgsr_translate_result(mma_result_enum mma_result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_TRANSLATE_RESULT, mma_result, __LINE__);

    switch (mma_result)
    {
        case MMA_RESULT_OK:
            return SRV_MMS_BGSR_RESULT_OK;
        case MMA_RESULT_FAIL_IN_CALL:
            return SRV_MMS_BGSR_RESULT_FAIL_INCALL;
        case MMA_RESULT_FAIL_NOT_READY:
            return SRV_MMS_BGSR_RESULT_FAIL_NOT_READY;
        case MMA_RESULT_FAIL_BUSY:
            return SRV_MMS_BGSR_RESULT_FAIL_BUSY;
        case MMA_RESULT_FAIL_INSUFFICIENT_MEMORY:
            return SRV_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_MEMORY;
        case MMA_RESULT_FAIL_INSUFFICIENT_STORAGE:
            return SRV_MMS_BGSR_RESULT_FAIL_INSUFFICIENT_STORAGE;
        case MMA_RESULT_FAIL_FILE_NOT_FOUND:
            return SRV_MMS_BGSR_RESULT_FAIL_FILE_NOT_FOUND;
        case MMA_RESULT_FAIL_FILE_CORRUPTED:
            return SRV_MMS_BGSR_RESULT_FAIL_FILE_CORRUPTED;
        case MMA_RESULT_FAIL_FILE_IN_USE:
            return SRV_MMS_BGSR_RESULT_FAIL_FILE_IN_USE;
        case MMA_RESULT_FAIL_FILE_IO:
            return SRV_MMS_BGSR_RESULT_FAIL_FILE_IO;
        case MMA_RESULT_FAIL_UNSUPPORT_CONTENT:
            return SRV_MMS_BGSR_RESULT_FAIL_UNSUPPORT_CONTENT;
        case MMA_RESULT_FAIL_COMM_UNSUPPORT_CONTENT:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_UNSUPPORT_CONTENT;
        case MMA_RESULT_FAIL_COMM_CONFIG_ERROR:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_CONFIG_ERROR;
        case MMA_RESULT_FAIL_COMM_CONNECT_ERROR:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_CONNECT_ERROR;
        case MMA_RESULT_FAIL_COMM_SERVER_ERROR:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_SERVER_ERROR;
        case MMA_RESULT_FAIL_COMM_SERVER_TIMEOUT:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT;
        case MMA_RESULT_FAIL_COMM_SERVICE_DENIED:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_SERVICE_DENIED;
        case MMA_RESULT_FAIL_COMM_UNAUTHORIZED:
            return SRV_MMS_BGSR_RESULT_FAIL_COMM_UNAUTHORIZED;
        case MMA_RESULT_FAIL_USER_CANCEL:
            return SRV_MMS_BGSR_RESULT_FAIL_USER_CANCEL;
        case MMA_RESULT_FAIL_INVALID_MSGID:
            return SRV_MMS_BGSR_RESULT_FAIL_INVALID_MSGID;
        case MMA_RESULT_FAIL_MSGID_IS_USING:
            return SRV_MMS_BGSR_RESULT_FAIL_MSGID_IS_USING;
        case MMA_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE:
            return SRV_MMS_BGSR_RESULT_FAIL_FILE_ACCESS_IN_USB_MODE;
        case MMA_RESULT_FAIL_MAX_MSG_SIZE_REACHED:
            return SRV_MMS_BGSR_RESULT_FAIL_MAX_MSG_SIZE_REACHED;
        case MMA_RESULT_FAIL:
        default:
            return SRV_MMS_BGSR_RESULT_FAIL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_action_send_rsp
 * DESCRIPTION
 *  action on send response
 * PARAMETERS
 *  send_rsp        [IN]        Wap_mma_send_rsp_struct
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_action_send_rsp(wap_mma_send_rsp_struct *send_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 message = 0;
    U16 *text = NULL;
    srv_mms_bgsr_msg_struct *curr_node;

#ifdef __MMI_UMMS_JSR205__
    U8 result;
#endif 
    U8 bgsr_result = SRV_MMS_BGSR_RESULT_NOT_USED;
    U8 display_flag = 0;
    S32 temp_index;
    U8 sim_id = MMA_SIM_ID_SIM1;
    U8 update = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Write your code here */
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    if (g_srv_mms_bgsr_context.vendor_send_msg_id == send_rsp->msg_id)
    {
        g_srv_mms_bgsr_context.send_msg_id = 0;
    #ifdef __MMI_MMS_FALLBACK__
        if (g_srv_mms_bgsr_context.fallback_send_id != 0
            && g_srv_mms_bgsr_context.fallback_send_id == g_srv_mms_bgsr_context.vendor_send_msg_id)
        {
            return;
        }
    #endif /* __MMI_MMS_FALLBACK__ */ 
        g_srv_mms_bgsr_context.vendor_send_msg_id = 0;
        srv_mms_vendor_send_rsp_callback(send_rsp->msg_id, send_rsp->result);
    #ifdef __MMI_UMMS_JSR205__
        if (g_srv_mms_bgsr_context.java_send_msg_id != 0)
        {
            srv_mms_bgsr_send_java_msg_req(g_srv_mms_bgsr_context.java_send_msg_id, g_srv_mms_bgsr_context.java_sim_id);
            return;
        }
    #endif /* __MMI_UMMS_JSR205__ */ 
        return;
    }
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 

    g_srv_mms_bgsr_context.send_msg_id = 0;
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CLEAR_SEND_ID);

    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_GET_SENDING_SIM_ID, g_srv_mms_bgsr_context.send_sim_id, __LINE__); */
    sim_id = g_srv_mms_bgsr_context.send_sim_id;
    srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_IDLE, SRV_MMS_BGSR_INDICATOR_SEND_OP);
    g_srv_mms_bgsr_context.send_sim_id = 0;

#ifdef __DM_LAWMO_SUPPORT__
    if ((g_srv_mms_bgsr_context.lawmo_scomo_flag & SRV_MMS_BGSR_LAWMO_SEND_MASK) == SRV_MMS_BGSR_LAWMO_SEND_MASK)
    {
        g_srv_mms_bgsr_context.lawmo_scomo_flag &= ~SRV_MMS_BGSR_LAWMO_SEND_MASK;
        if (!g_srv_mms_bgsr_context.lawmo_scomo_flag)
        {
            mmi_umms_app_core_bgsr_free_mms_data_for_wipe_callback(MMA_RESULT_OK);
        }
        return;
    }

#endif /* __DM_LAWMO_SUPPORT__ */ /* __DM_MO_SUPPORT__ */

#ifdef __MMI_UMMS_JSR205__
    if (g_srv_mms_bgsr_context.java_send_msg_id == send_rsp->msg_id)
    {
    #ifdef __MMI_MMS_FALLBACK__
        if (g_srv_mms_bgsr_context.fallback_send_id != 0
            && g_srv_mms_bgsr_context.fallback_send_id == g_srv_mms_bgsr_context.java_send_msg_id)
        {
            return;
        }
    #endif /* __MMI_MMS_FALLBACK__ */ 
        result = srv_mms_bgsr_translate_result((mma_result_enum) send_rsp->result);
        srv_mms_bgsr_delete_mms_req(send_rsp->msg_id);
        if (result == SRV_MMS_BGSR_RESULT_OK)
        {
            srv_mms_jsr_update_send_msg_icon(send_rsp->msg_id, SRV_MMS_BGSR_STATUS_NONE);
        }
        else
        {
            srv_mms_jsr_update_send_msg_icon(send_rsp->msg_id, SRV_MMS_BGSR_STATUS_SEND_FAIL);
        }
        srv_mms_jsr_send_msg_rsp((U16) send_rsp->msg_id, result);
    #ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
        if (g_srv_mms_bgsr_context.vendor_send_msg_id != 0)
        {
            srv_mms_bgsr_vendor_send_msg_req(
                g_srv_mms_bgsr_context.vendor_send_msg_id,
                g_srv_mms_bgsr_context.vendor_sim_id);
            return;
        }
    #endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 

        return;
    }
#endif /* __MMI_UMMS_JSR205__ */ 

    /* find it out from send q or send fail q */
    message = srv_mms_bgsr_extract_q(send_rsp->msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
    if (message == 0)
    {
        message = srv_mms_bgsr_extract_q(send_rsp->msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
    }
    if (message == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return;
    }
    curr_node = srv_mms_bgsr_get_msg_array(message);
    curr_node->result = srv_mms_bgsr_translate_result((mma_result_enum) send_rsp->result);
    srv_mms_bgsr_set_no_of_tries(message, (U8) (srv_mms_bgsr_get_no_of_tries(message) + 1));

    if ((curr_node)->msg_info & SRV_MMS_BGSR_IS_RR_INFO)
    {
        srv_mms_bgsr_set_rr_flag_req(curr_node->msg_id, FALSE);
    }

    if (curr_node->result == SRV_MMS_BGSR_RESULT_OK)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_OK, __LINE__);

        if (!(curr_node->msg_info & SRV_MMS_BGSR_IS_RR_INFO))
        {
            /* if it isn't a read report,check the send setting */

            if (curr_node->msg_info & SRV_MMS_BGSR_SEND_AND_SAVE_INFO)
            {
                curr_node->msg_id = 0;
            #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                if (message & SRV_MMS_BGSR_MEM_CARD_BIT)
                {
                    srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
                }
                else
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
                {
                    srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
                }
            }
            else
            {
                curr_node->status = SRV_MMS_BGSR_STATUS_DELETING;
                srv_mms_bgsr_delete_mms_req(curr_node->msg_id);
                (srv_mms_bgsr_callback_table[0][0].update_folder_callback) ();
                srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
            }

        #ifdef __MMI_MMS_BGSR_PROMPT_SEND_RESULT__
/* under construction !*/
        #endif 

        }
        else    /* if(message->is_rr == 0) */
        {

            curr_node->msg_id = 0;
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if (message & SRV_MMS_BGSR_MEM_CARD_BIT)
            {
                srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
            }
            else
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
            {
                srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
            }
        }

    }

    else if (curr_node->result == SRV_MMS_BGSR_RESULT_FAIL_USER_CANCEL)
    {
        srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));

    }
    else    /* ( message->result == SRV_MMS_BGSR_RESULT_OK) */
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_FAIL, __LINE__);

    #ifdef __MMI_MMS_FALLBACK__
        if (curr_node->msg_info & SRV_MMS_BGSR_IS_RR_INFO)
        {

            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                SRV_MMS_BGSR_FALLBACK_MASK,
                sim_id,
                g_srv_mms_bgsr_context.fallback_mask,
                __LINE__);

            if ((g_srv_mms_bgsr_context.fallback_mask & SRV_MMS_BGSR_FALLBACK_MASK_SENDING) ==
                SRV_MMS_BGSR_FALLBACK_MASK_SENDING && g_srv_mms_bgsr_context.fallback_send_id == curr_node->msg_id)
            {
                /* Fallback happened for read report */
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NEED_FALLBACK, curr_node->msg_id, __LINE__);
            }
        }
    #endif /* __MMI_MMS_FALLBACK__ */ 

        if (!(curr_node->msg_info & SRV_MMS_BGSR_IS_RR_INFO))
        {
            if (((curr_node->msg_info & SRV_MMS_BGSR_NO_OF_TRIES_INFO) >> 2) < SRV_MMS_BGSR_MAX_NO_OF_TRIES &&
                curr_node->result != SRV_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT)
            {
                if ((curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO) == 0)
                {
                #ifndef __MMI_SLIM_MMS_2__
                    display_flag = 1;
                    bgsr_result = SRV_MMS_BGSR_RESULT_FAIL_RESEND;
                #endif /* __MMI_SLIM_MMS_2__ */ 

                    curr_node->msg_info |= SRV_MMS_BGSR_CFG_RETRY_QUOTA;
                    update |= SRV_MMS_BGSR_UPDATE_QUOTA;
                }
                else
                {
                    curr_node->msg_info &= ~(SRV_MMS_BGSR_QUOTA_INFO);
                    curr_node->msg_info |= SRV_MMS_BGSR_MAX_NO_OF_TRIES - srv_mms_bgsr_get_no_of_tries(message);
                    update |= SRV_MMS_BGSR_UPDATE_QUOTA;
                }
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_RETRY, __LINE__);
                curr_node->status = SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND;
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
                temp_index = SRV_MMS_BGSR_CFG_RETRY_QUOTA - (curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO);
                if (temp_index >= 0 && temp_index < SRV_MMS_BGSR_CFG_RETRY_QUOTA)
                {
                    curr_node->ntt = SRV_MMS_BGSR_CFG_RETRY_INTERVAL[temp_index];
                    update |= SRV_MMS_BGSR_UPDATE_NTT;
                }
            }

            else    /* if the quota is used up, popup to inform user */
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NOT_RETRY, __LINE__);
                curr_node->status = SRV_MMS_BGSR_STATUS_SEND_FAIL;
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
                display_flag = 1;

            }   /* if the quota is used up, popup to inform user */
            srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
            (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (curr_node->msg_id, update);
        }
        else    /* is read report */
        {
            display_flag = 1;
            bgsr_result = SRV_MMS_BGSR_RESULT_READ_REPORT_FAIL;
            curr_node->msg_id = 0;
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if (message & SRV_MMS_BGSR_MEM_CARD_BIT)
            {
                srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
            }
            else
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
            {
                srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
            }
        }
    }
    text = srv_mms_bgsr_set_fail_cause(send_rsp, SRV_MMS_BGSR_MESSAGE_TYPE_SEND);
    if (bgsr_result == SRV_MMS_BGSR_RESULT_NOT_USED)
    {
        bgsr_result = curr_node->result;
    }
#ifdef __MMI_MMS_FALLBACK__
    if ((g_srv_mms_bgsr_context.fallback_mask & SRV_MMS_BGSR_FALLBACK_MASK_SENDING) ==
        SRV_MMS_BGSR_FALLBACK_MASK_SENDING && g_srv_mms_bgsr_context.fallback_send_id == curr_node->msg_id)
    {
        display_flag = 0;
    }
#endif /* __MMI_MMS_FALLBACK__ */ 
    if (curr_node->msg_info & SRV_MMS_BGSR_SEND_AND_SAVE_INFO)
    {
        display_flag |= SRV_MMS_BGSR_RSP_SAVE;
    }
    (srv_mms_bgsr_callback_table[0][0].send_rsp_callback) (send_rsp->msg_id, bgsr_result, text, display_flag, sim_id);

    if (text != NULL)
    {
        kal_adm_free(g_srv_mms_bgsr_context.mem_pool_id, text);
    }

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    if (g_srv_mms_bgsr_context.vendor_send_msg_id != 0)
    {
        srv_mms_bgsr_vendor_send_msg_req(
            g_srv_mms_bgsr_context.vendor_send_msg_id,
            g_srv_mms_bgsr_context.vendor_sim_id);
        return;
    }
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (g_srv_mms_bgsr_context.send_receive_flag & SRV_MMS_BGSR_MEM_CARD_SENDING)
    {
        if (!(g_srv_mms_bgsr_context.send_receive_flag & SRV_MMS_BGSR_MEM_CARD_DOWNLOADING))
        {
            if (g_srv_mms_bgsr_context.mem_card_state == SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS ||
                g_srv_mms_bgsr_context.mem_card_state == SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS_PLUG_IN_PENDING)
            {
                srv_mms_bgsr_mem_card_plug_out_state_hdlr();
                g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q = 0;
                if (g_srv_mms_bgsr_context.mem_card_state ==
                    SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS_PLUG_IN_PENDING)
                {
                    srv_mms_bgsr_init_mem_card_file_system();
                    srv_mms_bgsr_init_mem_card_msg_array();
                    g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN;
                    srv_mms_bgsr_sync(MMA_MSG_STORAGE_CARD1);
                }
                else
                {
                    g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT;
                }
            }
        }
        g_srv_mms_bgsr_context.send_receive_flag &= ~SRV_MMS_BGSR_MEM_CARD_SENDING;
    }
    else if (message & (SRV_MMS_BGSR_MEM_CARD_BIT))
    {
        srv_mms_bgsr_write_into_mem_card_file();

    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
        srv_mms_bgsr_write_into_ph_mem_file();
    }

#ifdef __MMI_UMMS_JSR205__
    if (g_srv_mms_bgsr_context.java_send_msg_id != 0)
    {
        srv_mms_bgsr_send_java_msg_req(g_srv_mms_bgsr_context.java_send_msg_id, g_srv_mms_bgsr_context.java_sim_id);
        return;
    }
#endif /* __MMI_UMMS_JSR205__ */ 
    message = srv_mms_bgsr_get_next_sending_node();

    if (message != 0)
    {
        /* send the next message */
        srv_mms_bgsr_send_mms_req(message);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_action_cancel_send_rsp
 * DESCRIPTION
 *  action for cancel send response
 * PARAMETERS
 *  cancel_send_rsp     [IN]        Wap_mma_rsp_struct
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_action_cancel_send_rsp(wap_mma_rsp_struct *cancel_send_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg = 0;
    srv_mms_bgsr_result_enum cancel_result = srv_mms_bgsr_translate_result((mma_result_enum) cancel_send_rsp->result);

#ifdef __MMI_UMMS_JSR205__
    U8 result;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset the cancel_send_msg_id */
    g_srv_mms_bgsr_context.cancel_send_msg_id = 0;
#ifdef __DM_LAWMO_SUPPORT__
    if (g_srv_mms_bgsr_context.lawmo_scomo_flag)
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 

#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
    if (cancel_send_rsp->msg_id == g_srv_mms_bgsr_context.vendor_send_msg_id)
    {
        return;
    }
#endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
#ifdef __MMI_UMMS_JSR205__

    if (cancel_send_rsp->msg_id == g_srv_mms_bgsr_context.java_send_msg_id)
    {
        result = srv_mms_bgsr_translate_result((mma_result_enum) cancel_send_rsp->result);
        srv_mms_jsr_cancel_send_msg_rsp(result);
        return;
    }
#endif /* __MMI_UMMS_JSR205__ */ 

    if (cancel_result != SRV_MMS_BGSR_RESULT_OK)
    {
        if (cancel_send_rsp->msg_id == g_srv_mms_bgsr_context.send_msg_id)
        {
            (srv_mms_bgsr_callback_table[0][0].cancel_send_rsp_callback) (cancel_send_rsp->msg_id, cancel_result);
        }
        return;
    }
    else
    {
        if (cancel_send_rsp->msg_id == g_srv_mms_bgsr_context.send_msg_id)
        {
            msg = srv_mms_bgsr_extract_q(cancel_send_rsp->msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
            srv_mms_bgsr_get_msg_array(msg)->status = SRV_MMS_BGSR_STATUS_DEFERRED_FOR_SEND;
            srv_mms_bgsr_enqueue(msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
        }
    }

    (srv_mms_bgsr_callback_table[0][0].cancel_send_rsp_callback) (cancel_send_rsp->msg_id, cancel_result);
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (msg & (SRV_MMS_BGSR_MEM_CARD_BIT))
    {
        srv_mms_bgsr_write_into_mem_card_file();

    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
        srv_mms_bgsr_write_into_ph_mem_file();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_action_download_rsp
 * DESCRIPTION
 *  action for action download response
 * PARAMETERS
 *  dl_rsp              [?]         
 *  download_rsp(?)     [IN]        Wap_mma_download_rsp_struct
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_action_download_rsp(wap_mma_download_rsp_struct *dl_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 message = 0;
    U16 *text = NULL;
    srv_mms_bgsr_msg_struct *curr_node;
    S32 temp_index;
    U8 display_flag = 0;
    U8 sim_id = MMA_SIM_ID_SIM1;
    U8 update = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if ((g_srv_mms_bgsr_context.lawmo_scomo_flag & SRV_MMS_BGSR_LAWMO_DOWNLOAD_MASK) ==
        SRV_MMS_BGSR_LAWMO_DOWNLOAD_MASK)
    {
        g_srv_mms_bgsr_context.lawmo_scomo_flag &= ~SRV_MMS_BGSR_LAWMO_DOWNLOAD_MASK;
        if (!g_srv_mms_bgsr_context.lawmo_scomo_flag)
        {
            mmi_umms_app_core_bgsr_free_mms_data_for_wipe_callback(MMA_RESULT_OK);
        }
        return;
    }

#endif /* __DM_LAWMO_SUPPORT__ */ 

    message = srv_mms_bgsr_extract_q(dl_rsp->msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));
    if (message == 0)
    {
        message = srv_mms_bgsr_extract_q(dl_rsp->msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
    }
    if (message == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return;
    }

    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_CLEAR_DOWNLOAD_ID);
    g_srv_mms_bgsr_context.download_msg_id = 0;

    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_GET_DOWNLOADING_SIM_ID, g_srv_mms_bgsr_context.download_sim_id,__LINE__); */
    sim_id = g_srv_mms_bgsr_context.download_sim_id;
    srv_mms_bgsr_show_mms_status_icon(SRV_MMS_BGSR_INDICATOR_IDLE, SRV_MMS_BGSR_INDICATOR_DOWNLOAD_OP);
    g_srv_mms_bgsr_context.download_sim_id = 0;
    curr_node = srv_mms_bgsr_get_msg_array(message);
    curr_node->result = srv_mms_bgsr_translate_result((mma_result_enum) dl_rsp->result);
    srv_mms_bgsr_set_no_of_tries(message, (U8) (srv_mms_bgsr_get_no_of_tries(message) + 1));

    if (curr_node->result == SRV_MMS_BGSR_RESULT_OK)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_OK, __LINE__);
        curr_node->msg_id = 0;
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        {
            srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
        }
    }
    else if (curr_node->result == SRV_MMS_BGSR_RESULT_FAIL_USER_CANCEL)
    {
        if ((curr_node->msg_info & SRV_MMS_BGSR_FAIL_FLAG_INFO) == SRV_MMS_BGSR_FAIL_FLAG_INFO)
        {
            curr_node->msg_id = 0;
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if (message & SRV_MMS_BGSR_MEM_CARD_BIT)
            {
                srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
            }
            else
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
            {
                srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
            }
        }
        else
        {
            srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
        }
    }

    else    /* message->result == SRV_MMS_BGSR_RESULT_OK) */
    {
        if ((curr_node->msg_info & SRV_MMS_BGSR_FAIL_FLAG_INFO) == SRV_MMS_BGSR_FAIL_FLAG_INFO)
        {
            curr_node->status = SRV_MMS_BGSR_STATUS_DOWNLOAD_FAIL;
            (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback)
                (curr_node->msg_id, SRV_MMS_BGSR_UPDATE_STATUS);

            curr_node->msg_id = 0;
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if (message & SRV_MMS_BGSR_MEM_CARD_BIT)
            {
                srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
            }
            else
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
            {
                srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
            }
        }
        else
        {
            /* check the fail result */

            if (srv_mms_bgsr_get_no_of_tries(message) < SRV_MMS_BGSR_MAX_NO_OF_TRIES &&
                curr_node->result != SRV_MMS_BGSR_RESULT_FAIL_COMM_SERVER_TIMEOUT)
            {
                if ((curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO) == 0)
                {
                    curr_node->msg_info |= SRV_MMS_BGSR_CFG_RETRY_QUOTA;
                    update |= SRV_MMS_BGSR_UPDATE_QUOTA;
                }
                else
                {
                    curr_node->msg_info &= ~(SRV_MMS_BGSR_QUOTA_INFO);
                    (curr_node->msg_info) |=
                        (SRV_MMS_BGSR_MAX_NO_OF_TRIES -
                         srv_mms_bgsr_get_no_of_tries(message)) & SRV_MMS_BGSR_QUOTA_INFO;
                    update |= SRV_MMS_BGSR_UPDATE_QUOTA;
                }
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_RETRY, __LINE__);

                curr_node->status = SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD;
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
                temp_index = SRV_MMS_BGSR_CFG_RETRY_QUOTA - (curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO);
                if (temp_index >= 0 && temp_index < SRV_MMS_BGSR_CFG_RETRY_QUOTA)
                {
                    curr_node->ntt = SRV_MMS_BGSR_CFG_RETRY_INTERVAL[temp_index];
                    update |= SRV_MMS_BGSR_UPDATE_NTT;
                }
            }
            else    /* if the quota is used up, popup to inform user */
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NOT_RETRY, __LINE__);
                curr_node->status = SRV_MMS_BGSR_STATUS_DOWNLOAD_FAIL;
                update |= SRV_MMS_BGSR_UPDATE_STATUS;
                if (dl_rsp->result != MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT)
                {
                    display_flag = 1;
                }

            }   /* if the quota is used up, popup to inform user */

            srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
            (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback) (curr_node->msg_id, update);

        }
    }
    text = srv_mms_bgsr_set_fail_cause(dl_rsp, SRV_MMS_BGSR_MESSAGE_TYPE_DOWNLOAD);
#ifdef __MMI_MMS_FALLBACK__
    if ((g_srv_mms_bgsr_context.fallback_mask & SRV_MMS_BGSR_FALLBACK_MASK_DOWNLOADING) ==
        SRV_MMS_BGSR_FALLBACK_MASK_DOWNLOADING && g_srv_mms_bgsr_context.fallback_download_id == curr_node->msg_id)
    {
        display_flag = 0;
    }
#endif /* __MMI_MMS_FALLBACK__ */ 
    (srv_mms_bgsr_callback_table[0][0].download_rsp_callback)
        (dl_rsp->msg_id, dl_rsp->new_msg_id, curr_node->result, text, (curr_node->msg_info & SRV_MMS_BGSR_QUOTA_INFO),
         display_flag, sim_id);
    if (text != NULL)
    {
        kal_adm_free(g_srv_mms_bgsr_context.mem_pool_id, text);
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (g_srv_mms_bgsr_context.send_receive_flag & SRV_MMS_BGSR_MEM_CARD_DOWNLOADING)
    {
        if (!(g_srv_mms_bgsr_context.send_receive_flag & SRV_MMS_BGSR_MEM_CARD_SENDING))
        {
            if (g_srv_mms_bgsr_context.mem_card_state == SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS ||
                g_srv_mms_bgsr_context.mem_card_state == SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS_PLUG_IN_PENDING)
            {
                srv_mms_bgsr_mem_card_plug_out_state_hdlr();
                g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q = 0;
                if (g_srv_mms_bgsr_context.mem_card_state ==
                    SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS_PLUG_IN_PENDING)
                {
                    srv_mms_bgsr_init_mem_card_file_system();
                    srv_mms_bgsr_init_mem_card_msg_array();
                    g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN;
                    srv_mms_bgsr_sync(MMA_MSG_STORAGE_CARD1);
                }
                else
                {
                    g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT;
                }
            }
        }
        g_srv_mms_bgsr_context.send_receive_flag &= ~SRV_MMS_BGSR_MEM_CARD_DOWNLOADING;
    }
    else if (message & (SRV_MMS_BGSR_MEM_CARD_BIT))
    {
        srv_mms_bgsr_write_into_mem_card_file();

    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
        srv_mms_bgsr_write_into_ph_mem_file();
    }

    if (g_srv_mms_bgsr_context.immd_retr_sim_id == 0)
    {
        message = srv_mms_bgsr_get_next_downloading_node();

        if (message != 0)
        {
            /* download the next message */
            srv_mms_bgsr_download_mms_req(message);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_action_cancel_download_rsp
 * DESCRIPTION
 *  action for cancel_donload_rsp
 * PARAMETERS
 *  cancel_dl_rsp       [?]         
 *  text(?)             [IN]        Response texts
 *  rsp(?)              [IN]        Response struct
 *  action(?)           [IN]        Action type
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_action_cancel_download_rsp(wap_mma_rsp_struct *cancel_dl_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg = 0;
    srv_mms_bgsr_result_enum cancel_result = srv_mms_bgsr_translate_result((mma_result_enum) cancel_dl_rsp->result);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Reset the cancel_download_msg_id */
    g_srv_mms_bgsr_context.cancel_download_msg_id = 0;
#ifdef __DM_LAWMO_SUPPORT__
    if (g_srv_mms_bgsr_context.lawmo_scomo_flag)
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ /* __DM_MO_SUPPORT__ */

    if (cancel_result != SRV_MMS_BGSR_RESULT_OK)
    {
        if (cancel_dl_rsp->msg_id == g_srv_mms_bgsr_context.download_msg_id)
        {
            (srv_mms_bgsr_callback_table[0][0].cancel_download_rsp_callback) (cancel_dl_rsp->msg_id, cancel_result);
        }
        return;
    }
    else
    {
        if (cancel_dl_rsp->msg_id == g_srv_mms_bgsr_context.download_msg_id)
        {
            msg = srv_mms_bgsr_extract_q(cancel_dl_rsp->msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));
            srv_mms_bgsr_get_msg_array(msg)->status = SRV_MMS_BGSR_STATUS_DEFERRED_FOR_DOWNLOAD;
            (srv_mms_bgsr_callback_table[0][0].update_menu_item_callback)
                (cancel_dl_rsp->msg_id, SRV_MMS_BGSR_UPDATE_STATUS);
            srv_mms_bgsr_enqueue(msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
        }

        (srv_mms_bgsr_callback_table[0][0].cancel_download_rsp_callback) (cancel_dl_rsp->msg_id, cancel_result);
    }

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (msg & (SRV_MMS_BGSR_MEM_CARD_BIT))
    {
        srv_mms_bgsr_write_into_mem_card_file();

    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
        srv_mms_bgsr_write_into_ph_mem_file();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_action_save_rsp
 * DESCRIPTION
 *  action for save_rsp
 * PARAMETERS
 *  save_rsp        [IN]        Wap_mma_save_rsp_struct
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_action_save_rsp(wap_mma_save_rsp_struct *save_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 message = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if (g_srv_mms_bgsr_context.lawmo_scomo_flag)
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 

    if (srv_mms_bgsr_find_q(save_rsp->msg_id[0], 0, g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q))
    {

        message = srv_mms_bgsr_extract_q(save_rsp->msg_id[0], &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));

        srv_mms_bgsr_get_msg_array(message)->msg_id = 0;
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
            srv_mms_bgsr_write_into_mem_card_file();
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        {
            srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
            srv_mms_bgsr_write_into_ph_mem_file();
        }

    #ifdef __MMI_MMS_2__
        srv_mms_send_save_rsp_to_app();
    #endif 
    }
    else
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        srv_mms_bgsr_echo_current_info();
    }
    (srv_mms_bgsr_callback_table[0][0].update_folder_callback) ();
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_action_delete_rsp
 * DESCRIPTION
 *  action for delete_rsp
 * PARAMETERS
 *  delete_rsp      [IN]        Wap_mma_delete_rsp_struct
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_action_delete_rsp(wap_mma_delete_rsp_struct *delete_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 message = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __DM_LAWMO_SUPPORT__
    if (g_srv_mms_bgsr_context.lawmo_scomo_flag)
    {
        return;
    }
#endif /* __DM_LAWMO_SUPPORT__ */ 
#ifdef __MMI_UMMS_JSR205__
    if (g_srv_mms_bgsr_context.java_send_msg_id == delete_rsp->msg_id[0])
    {
        g_srv_mms_bgsr_context.java_send_msg_id = 0;
        g_srv_mms_bgsr_context.java_sim_id = 0;
        return;
    }
#endif /* __MMI_UMMS_JSR205__ */ 

    message = srv_mms_bgsr_extract_q(delete_rsp->msg_id[0], &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
    if (message == 0)
    {
        message = srv_mms_bgsr_extract_q(delete_rsp->msg_id[0], &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
    }
    if (message == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
        srv_mms_bgsr_echo_current_info();
        return;
    }
    srv_mms_bgsr_get_msg_array(message)->msg_id = 0;
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (message & SRV_MMS_BGSR_MEM_CARD_BIT)
    {
        srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
        srv_mms_bgsr_write_into_mem_card_file();
    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
        srv_mms_bgsr_enqueue(message, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
        /* file operation */
        srv_mms_bgsr_write_into_ph_mem_file();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_action_sync_rsp
 * DESCRIPTION
 *  action for sync_rsp
 * PARAMETERS
 *  sync_rsp        [IN]        Wap_mma_msg_is_valid_rsp_struct
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_action_sync_rsp(wap_mma_msg_is_valid_rsp_struct *sync_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 j = 0;
    U8 local_msg = 0;
    U32 msg_id = 0;
    U8 write_ph = 0;

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    U8 write_mem = 0;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sync_rsp->result == MMA_RESULT_OK)
    {
        for (i = 0; i < SRV_MMS_BGSR_MAX_MSG_NUM; i++)
        {
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if (g_srv_mms_bgsr_context.sync_flag & SRV_MMS_BGSR_SYNC_REQ_MEM_CARD)
            {
                msg_id = mem_card_msg_array[i].msg_id;
            }
            else
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
            {
                msg_id = ph_mem_msg_array[i].msg_id;
            }
            if (msg_id != 0 && (sync_rsp->msg_validity_list[j++] != 1))
            {

                local_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_q));
                if (local_msg == 0)
                {
                    local_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                }
                if (local_msg == 0)
                {
                    local_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_q));
                }
                if (local_msg == 0)
                {
                    local_msg = srv_mms_bgsr_extract_q(msg_id, &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
                }

                if (local_msg == 0)
                {
                    MMI_TRACE(MMI_TRACE_INFO, SRV_MMS_BGSR_MSG_NOT_FOUND, __LINE__);
                    srv_mms_bgsr_echo_current_info();
                    continue;
                }
                srv_mms_bgsr_get_msg_array(local_msg)->msg_id = 0;
            #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                if (local_msg & SRV_MMS_BGSR_MEM_CARD_BIT)
                {
                    srv_mms_bgsr_enqueue(local_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
                    write_mem = 1;
                }
                else
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
                {
                    srv_mms_bgsr_enqueue(local_msg, &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
                    write_ph = 1;
                }

            }
        }

    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__

        if (g_srv_mms_bgsr_context.sync_flag & SRV_MMS_BGSR_SYNC_REQ_MEM_CARD)
        {
            g_srv_mms_bgsr_context.sync_flag &= ~SRV_MMS_BGSR_SYNC_REQ_MEM_CARD;
            g_srv_mms_bgsr_context.sync_flag |= SRV_MMS_BGSR_MEM_CARD_SYNCED;
            if (write_mem == 1)
            {
                srv_mms_bgsr_write_into_mem_card_file();
            }
            return;
        }
        if (g_srv_mms_bgsr_context.sync_flag & SRV_MMS_BGSR_SYNC_REQ_MEM_CARD_PENDING)
        {
            g_srv_mms_bgsr_context.sync_flag &= ~SRV_MMS_BGSR_SYNC_REQ_MEM_CARD_PENDING;
            srv_mms_bgsr_sync(MMA_MSG_STORAGE_CARD1);
            return;
        }
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

        if (g_srv_mms_bgsr_context.sync_flag & SRV_MMS_BGSR_SYNC_REQ_PH_MEM)
        {
            g_srv_mms_bgsr_context.sync_flag &= ~SRV_MMS_BGSR_SYNC_REQ_PH_MEM;
            g_srv_mms_bgsr_context.sync_flag |= SRV_MMS_BGSR_PH_MEM_SYNCED;
            if (write_ph == 1)
            {
                srv_mms_bgsr_write_into_ph_mem_file();
            }
            StartTimer(SRV_MMS_BGSR_TIMER, SRV_MMS_BGSR_CFG_RETRY_TIMER * 60000, srv_mms_bgsr_timeout_procedure);
            return;
        }

        if (g_srv_mms_bgsr_context.sync_flag & SRV_MMS_BGSR_SYNC_REQ_PH_MEM_PENDING)
        {
            g_srv_mms_bgsr_context.sync_flag &= ~SRV_MMS_BGSR_SYNC_REQ_PH_MEM_PENDING;
            srv_mms_bgsr_sync(MMA_MSG_STORAGE_PHONE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_no_of_tries
 * DESCRIPTION
 *  get no of tries
 * PARAMETERS
 *  index       [IN]        U8
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
U8 srv_mms_bgsr_get_no_of_tries(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((srv_mms_bgsr_get_msg_array(index)->msg_info & SRV_MMS_BGSR_NO_OF_TRIES_INFO) >> 2);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_set_no_of_tries
 * DESCRIPTION
 *  set no of tries
 * PARAMETERS
 *  index       [IN]        U8
 *  value       [IN]        U8
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_set_no_of_tries(U8 index, U8 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_msg_struct *curr_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (value < 4)
    {
        curr_node = srv_mms_bgsr_get_msg_array(index);
        curr_node->msg_info &= ~(SRV_MMS_BGSR_NO_OF_TRIES_INFO);
        curr_node->msg_info |= (value << 2);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_is_ready
 * DESCRIPTION
 *  check bgsr is ready or not
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
U8 srv_mms_bgsr_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 ready_flag = TRUE;

    if (!srv_mms_bgsr_is_mma_ready())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NOT_READY, 1, __LINE__);
        ready_flag = FALSE;
    }
    else if (!srv_um_check_ready())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NOT_READY, 2, __LINE__);
        ready_flag = FALSE;
    }
    else if (!srv_mode_switch_is_network_service_available())
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_NOT_READY, 3, __LINE__);
        ready_flag = FALSE;
    }

    return ready_flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_is_ph_sync
 * DESCRIPTION
 *  check bgsr is sync with MMA or not
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
U8 srv_mms_bgsr_is_ph_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_mms_bgsr_context.sync_flag & SRV_MMS_BGSR_PH_MEM_SYNCED);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_mms_is_exported
 * DESCRIPTION
 *  get the mms is exported
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint32
 *****************************************************************************/
U8 srv_mms_bgsr_mms_is_exported(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_bgsr_context.storage_exported;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_is_mma_ready
 * DESCRIPTION
 *  check if mma is ready or not
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
U8 srv_mms_bgsr_is_mma_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_mms_bgsr_context.mma_ready_flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_next_sending_node
 * DESCRIPTION
 *  Returns next node from the send_q
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_get_next_sending_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 message = 0;
    U32 sim_valid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message = g_srv_mms_bgsr_context.srv_mms_bgsr_send_q;
    if (message)
    {
    #ifdef __DM_LAWMO_SUPPORT__
        if(srv_dm_lawmo_is_locked())
        {
            return 0;
        }
    #endif /* __DM_LAWMO_SUPPORT__ */ 
    #ifdef __MMI_MMS_FALLBACK__
        if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
        {
            return 0;
        }
    #endif /* __MMI_MMS_FALLBACK__ */ 
        if (!srv_mms_bgsr_is_sim_profile_valid(&sim_valid))
        {
            return 0;
        }
        while (message)
        {
            if (srv_mms_bgsr_is_message_ready(message, sim_valid, SRV_MMS_BGSR_MESSAGE_TYPE_SEND))
            {
                break;
            }
            else
            {
                message = *(srv_mms_bgsr_get_next_array(message));
            }
        }
    }
    return message;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_next_downloading_node
 * DESCRIPTION
 *  Returns next node from the download_q
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_get_next_downloading_node(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 message = 0;
    U32 sim_valid = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message = g_srv_mms_bgsr_context.srv_mms_bgsr_download_q;

    if (message)
    {
    #ifdef __DM_LAWMO_SUPPORT__
        if(srv_dm_lawmo_is_locked())
        {
            return 0;
        }
    #endif /* __DM_LAWMO_SUPPORT__ */ 
    #ifdef __MMI_MMS_FALLBACK__
        if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
        {
            return 0;
        }
    #endif /* __MMI_MMS_FALLBACK__ */ 
        if (!srv_mms_bgsr_is_sim_profile_valid(&sim_valid))
        {
            return 0;
        }
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (srv_mms_get_mms_prefer_storage() == MMA_MSG_STORAGE_CARD1 &&
            (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR))
        {
            return 0;
        }
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        while (message)
        {
            if (srv_mms_bgsr_is_message_ready(message, sim_valid, SRV_MMS_BGSR_MESSAGE_TYPE_DOWNLOAD))
            {
                break;
            }
            else
            {
                message = *(srv_mms_bgsr_get_next_array(message));
            }
        }
    }
    return message;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_is_message_ready
 * DESCRIPTION
 *  (U32 msg_id)
 * PARAMETERS
 *  message             [IN]        
 *  sim_valid           [IN]        
 *  message_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool srv_mms_bgsr_is_message_ready(U8 message, U32 sim_valid, U8 message_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 msg_id;
    U8 sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sim_id = srv_mms_bgsr_get_msg_array(message)->sim_id;   /* Application uses MMA Sim Ids which bgsr is also storing...i.e. 1,2,4,8.. */
    if (!(sim_valid & sim_id))
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_READY, 1, sim_valid, __LINE__);
        return KAL_FALSE;
    }

    msg_id = srv_mms_bgsr_get_msg_array(message)->msg_id;
    switch (message_type)
    {
        case SRV_MMS_BGSR_MESSAGE_TYPE_SEND:
    #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
            if (srv_uc_is_mms_in_use(msg_id))
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_READY, 5, msg_id, __LINE__);
                return KAL_FALSE;
            }
            else
    #endif /* __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ */ 
        #ifdef __MMI_MMS_2__
            if (srv_mms_if_is_mms_in_open_state(msg_id))
            {
                MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_MSG_NOT_READY, 6, msg_id, __LINE__);
                return KAL_FALSE;
            }
        #endif /* __MMI_MMS_2__ */ /* __MMI_MMS_2 */
            break;
        case SRV_MMS_BGSR_MESSAGE_TYPE_DOWNLOAD:
            {
                return KAL_TRUE;
            }
        default:
            break;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_is_sim_profile_valid
 * DESCRIPTION
 *  (U16 *sim_valid )
 * PARAMETERS
 *  sim_valid       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool srv_mms_bgsr_is_sim_profile_valid(U32 *sim_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;
    U8 bgsr_sim_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *sim_valid = 0;

    for (i = 1; i <= MMA_MAX_SIM_COUNT; i++)
    {
        /* converts into bgsr sim ids 1,2,4,8... */
        bgsr_sim_id = srv_mms_bgsr_convert_index(i);
        if (srv_mms_bgsr_is_sim_valid(bgsr_sim_id)
            && srv_wap_prof_is_dtcnt_valid(srv_mms_bgsr_convert_bgsr_sim_id_to_wap_prof(bgsr_sim_id),
                                           SRV_WAP_PROF_APPID_MMS, (U8) - 1)
            )
        {
            *sim_valid |= bgsr_sim_id;
        }
    }
    if (*sim_valid == 0)
    {
        return KAL_FALSE;
    }
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_init_ph_mem_file_system
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_init_ph_mem_file_system()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = 0;
    U32 size = 0;
    U8 checksum = 0;
    kal_wchar folder_path[SRV_MMS_BGSR_MAX_PATH_LEN];
    kal_wchar file_path[SRV_MMS_BGSR_MAX_PATH_LEN];
    kal_wchar file_path_bk[SRV_MMS_BGSR_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((kal_uint16*) folder_path, "%c:\\%s", SRV_MMS_BGSR_SYSTEM_DRV, SRV_MMS_BGSR_FLDR_NAME);
    kal_wsprintf(
        (kal_uint16*) file_path,
        "%c:\\%s\\%s",
        SRV_MMS_BGSR_SYSTEM_DRV,
        SRV_MMS_BGSR_FLDR_NAME,
        SRV_MMS_BGSR_FILE_NAME);
    kal_wsprintf(
        (kal_uint16*) file_path_bk,
        "%c:\\%s\\%s",
        SRV_MMS_BGSR_SYSTEM_DRV,
        SRV_MMS_BGSR_FLDR_NAME,
        SRV_MMS_BGSR_FILE_NAME_BACKUP);
    file_handle = FS_Open((UI_string_type) folder_path, FS_READ_ONLY);

    if (file_handle > 0)
    {
        FS_Close(file_handle);
    }
    else
    {
        FS_CreateDir((PU16) folder_path);
        FS_SetAttributes((unsigned short*)folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }

    /* Infor file */

    file_handle = FS_Open((UI_string_type) file_path, FS_READ_ONLY);
    if (file_handle < 0)
    {
        file_handle = FS_Open((UI_string_type) file_path_bk, FS_READ_ONLY);
        if (file_handle > 0)
        {
            FS_Read(file_handle, &checksum, 1, &size);
            FS_Read(file_handle, ph_mem_msg_array, sizeof(ph_mem_msg_array), &size);
            FS_Close(file_handle);
        }
    }
    else
    {
        FS_Read(file_handle, &checksum, 1, &size);
        FS_Read(file_handle, ph_mem_msg_array, sizeof(ph_mem_msg_array), &size);
        if (checksum != srv_mms_bgsr_generate_check_sum((U8*) ph_mem_msg_array, sizeof(ph_mem_msg_array)))
        {
            FS_Close(file_handle);
            file_handle = FS_Open((UI_string_type) file_path_bk, FS_READ_ONLY);
            if (file_handle > 0)
            {
                FS_Read(file_handle, &checksum, 1, &size);
                FS_Read(file_handle, ph_mem_msg_array, sizeof(ph_mem_msg_array), &size);
                FS_Close(file_handle);
            }
        }
        else
        {
            FS_Close(file_handle);
            return;
        }
    }
    if (file_handle < 0 ||
        checksum != srv_mms_bgsr_generate_check_sum((U8*) ph_mem_msg_array, sizeof(ph_mem_msg_array)))
    {
        file_handle = FS_Open((UI_string_type) file_path, FS_CREATE);
        memset(ph_mem_msg_array, 0, sizeof(srv_mms_bgsr_msg_struct) * SRV_MMS_BGSR_MAX_MSG_NUM);
        checksum = 0;
        FS_Write(file_handle, &checksum, 1, &size);
        FS_Write(file_handle, ph_mem_msg_array, sizeof(ph_mem_msg_array), &size);
        FS_Close(file_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_write_into_ph_mem_file
 * DESCRIPTION
 *  synchronization
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_write_into_ph_mem_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = 0;
    U32 size = 0;
    U8 checksum = 0;
    kal_wchar file_path[SRV_MMS_BGSR_MAX_PATH_LEN];
    kal_wchar file_path_bk[SRV_MMS_BGSR_MAX_PATH_LEN];
    kal_wchar file_path_tmp[SRV_MMS_BGSR_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(
        (kal_uint16*) file_path,
        "%c:\\%s\\%s",
        SRV_MMS_BGSR_SYSTEM_DRV,
        SRV_MMS_BGSR_FLDR_NAME,
        SRV_MMS_BGSR_FILE_NAME);
    kal_wsprintf(
        (kal_uint16*) file_path_bk,
        "%c:\\%s\\%s",
        SRV_MMS_BGSR_SYSTEM_DRV,
        SRV_MMS_BGSR_FLDR_NAME,
        SRV_MMS_BGSR_FILE_NAME_BACKUP);
    kal_wsprintf(
        (kal_uint16*) file_path_tmp,
        "%c:\\%s\\%s",
        SRV_MMS_BGSR_SYSTEM_DRV,
        SRV_MMS_BGSR_FLDR_NAME,
        SRV_MMS_BGSR_FILE_NAME_TEMP);
    FS_Rename(file_path_bk, file_path_tmp);
    /* FS_Delete((U16*) file_path_bk); */
    FS_Rename(file_path, file_path_bk);
    FS_Rename(file_path_tmp, file_path);
    file_handle = FS_Open((UI_string_type) file_path, FS_CREATE);
    if (file_handle > 0)
    {
        FS_Truncate(file_handle);   /* Delete the whole content of file */
        checksum = srv_mms_bgsr_generate_check_sum((U8*) ph_mem_msg_array, sizeof(ph_mem_msg_array));
        FS_Write(file_handle, &checksum, 1, &size);
        FS_Write(file_handle, ph_mem_msg_array, sizeof(ph_mem_msg_array), &size);
        FS_Close(file_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_msg_array
 * DESCRIPTION
 *  synchronization
 * CALLS
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_mms_bgsr_msg_struct *srv_mms_bgsr_get_msg_array(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (index & (SRV_MMS_BGSR_MEM_CARD_BIT))
    {
        index &= (~SRV_MMS_BGSR_MEM_CARD_BIT);
        return &mem_card_msg_array[index - 1];
    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
        return &ph_mem_msg_array[index - 1];
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_next_array
 * DESCRIPTION
 *  synchronization
 * CALLS
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 *srv_mms_bgsr_get_next_array(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (index & (SRV_MMS_BGSR_MEM_CARD_BIT))
    {
        index &= (~SRV_MMS_BGSR_MEM_CARD_BIT);
        return &mem_card_next_array[index - 1];
    }
    else
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    {
        return &ph_mem_next_array[index - 1];
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_generate_check_sum
 * DESCRIPTION
 *  synchronization
 * CALLS
 *  
 * PARAMETERS
 *  data        [?]         
 *  len         [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_generate_check_sum(U8 *data, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 checksum = 0;
    U32 i;
    U8 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < len; i++)
    {
        checksum += data[i];
    }
    ret = (U8) (checksum % 256);
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_update_status
 * DESCRIPTION
 *  get the message status
 * CALLS
 *  
 * PARAMETERS
 *  local_msg       [IN]        
 *  status          [IN]        
 *  msg_id(?)       [IN]        The message id
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_update_status(U8 local_msg, U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 updated_status = status;
    U8 mma_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mma_sim_id = srv_mms_bgsr_get_msg_array(local_msg)->sim_id;
    switch (status)
    {
        case SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND:
        case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND:
        {
            if (!srv_mms_bgsr_is_sim_valid(srv_mms_bgsr_convert_mma_sim_id_to_bgsr_sim_id(mma_sim_id)))
            {
                updated_status = SRV_MMS_BGSR_STATUS_SEND_SIM_UNAVAILABLE;
            }
            else
            {
                updated_status = status;
            }
            break;
        }
        case SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD:
        case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD:
        {

            if (!srv_mms_bgsr_is_sim_valid(srv_mms_bgsr_convert_mma_sim_id_to_bgsr_sim_id(mma_sim_id)))
            {
                updated_status = SRV_MMS_BGSR_STATUS_DOWNLOAD_SIM_UNAVAILABLE;
            }
            else
            {
                updated_status = status;
            }
            break;
        }
        default:
        {
            updated_status = status;
            break;
        }
    }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    if (updated_status == SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD ||
        updated_status == SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD)
    {
        if (srv_mms_get_mms_prefer_storage() == MMA_MSG_STORAGE_CARD1 &&
            (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) != FS_NO_ERROR))
        {
            updated_status = SRV_MMS_BGSR_STATUS_DOWNLOAD_MEM_CARD_UNAVAILABLE;
        }
    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    return updated_status;
}

#ifdef MMS_IN_LARGE_STORAGE


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_ph_mem_format_hdlr
 * DESCRIPTION
 *  echo current infomation
 * PARAMETERS
 *  void
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_ph_mem_format_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *message;
    U8 next;

#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    U8 node;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_send_q;
    while (*message != 0)
    {
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            node = (*message) & (~SRV_MMS_BGSR_MEM_CARD_BIT);
            message = &mem_card_next_array[node - 1];
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        {
            next = ph_mem_next_array[(*message) - 1];
            ph_mem_next_array[(*message) - 1] = 0;
            ph_mem_msg_array[(*message) - 1].msg_id = 0;
            srv_mms_bgsr_enqueue(*(message), &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
            *(message) = next;
        }
    }
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q;
    while (*message != 0)
    {
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            node = (*message) & (~SRV_MMS_BGSR_MEM_CARD_BIT);
            message = &mem_card_next_array[node - 1];
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        {
            next = ph_mem_next_array[(*message) - 1];
            ph_mem_next_array[(*message) - 1] = 0;
            ph_mem_msg_array[(*message) - 1].msg_id = 0;
            srv_mms_bgsr_enqueue(*(message), &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
            *(message) = next;
        }
    }
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_download_q;
    while (*message != 0)
    {
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            node = (*message) & (~SRV_MMS_BGSR_MEM_CARD_BIT);
            message = &mem_card_next_array[node - 1];
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        {
            next = ph_mem_next_array[(*message) - 1];
            ph_mem_next_array[(*message) - 1] = 0;
            ph_mem_msg_array[(*message) - 1].msg_id = 0;
            srv_mms_bgsr_enqueue(*(message), &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
            *(message) = next;
        }
    }
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q;
    while (*message != 0)
    {
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            node = (*message) & (~SRV_MMS_BGSR_MEM_CARD_BIT);
            message = &mem_card_next_array[node - 1];
        }
        else
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
        {
            next = ph_mem_next_array[(*message) - 1];
            ph_mem_next_array[(*message) - 1] = 0;
            ph_mem_msg_array[(*message) - 1].msg_id = 0;
            srv_mms_bgsr_enqueue(*(message), &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_q));
            *(message) = next;
        }
    }
    srv_mms_bgsr_write_into_ph_mem_file();
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    srv_mms_bgsr_write_into_mem_card_file();
#endif 
}
#endif /* MMS_IN_LARGE_STORAGE */ 
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_init_mem_card_state_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_init_mem_card_state_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)
    if (srv_usb_is_in_mass_storage_mode() || srv_mms_bgsr_mms_is_exported())
    {
        g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN_PENDING;
        return;
    }
#endif /* defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__) */ 
    if (FS_GetDevStatus(SRV_FMGR_CARD_DRV, FS_MOUNT_STATE_ENUM) == FS_NO_ERROR)
    {
        g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN_PROCESS;
        srv_mms_bgsr_init_mem_card_file_system();
        srv_mms_bgsr_init_mem_card_msg_array();
        g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN;
        srv_mms_bgsr_sync(MMA_MSG_STORAGE_CARD1);
    }
    else
    {
        g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_NONE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_mem_card_plug_in_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_mem_card_plug_in_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_mms_bgsr_context.mem_card_state)
    {
        case SRV_MMS_BGSR_MEM_CARD_STATE_NONE:
        case SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT:
            g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN_PROCESS;
    #if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)

            if (srv_usb_is_in_mass_storage_mode() || srv_mms_bgsr_mms_is_exported())
            {
                g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN_PENDING;
                return;
            }
    #endif /* defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__) */ 

            srv_mms_bgsr_init_mem_card_file_system();
            srv_mms_bgsr_init_mem_card_msg_array();
            g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN;
            srv_mms_bgsr_sync(MMA_MSG_STORAGE_CARD1);
            break;
        case SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS:
            g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS_PLUG_IN_PENDING;
            break;
        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_mem_card_plug_out_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_mem_card_plug_out_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 msg = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_srv_mms_bgsr_context.mem_card_state)
    {
        case SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN_PENDING:
            g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT;
            break;

        case SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN_PROCESS:
        case SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_IN:
            msg = srv_mms_bgsr_get_q(g_srv_mms_bgsr_context.send_msg_id, g_srv_mms_bgsr_context.srv_mms_bgsr_send_q);
            if (msg == 0)
            {
                msg = srv_mms_bgsr_get_q(
                        g_srv_mms_bgsr_context.send_msg_id,
                        g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q);
            }
            if (msg != 0 && (msg & SRV_MMS_BGSR_MEM_CARD_BIT))
            {
                g_srv_mms_bgsr_context.send_receive_flag |= SRV_MMS_BGSR_MEM_CARD_SENDING;
            }
            msg = 0;
            msg = srv_mms_bgsr_get_q(
                    g_srv_mms_bgsr_context.download_msg_id,
                    g_srv_mms_bgsr_context.srv_mms_bgsr_download_q);
            if (msg == 0)
            {
                msg = srv_mms_bgsr_get_q(
                        g_srv_mms_bgsr_context.download_msg_id,
                        g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q);
            }
            if (msg != 0 && (msg & SRV_MMS_BGSR_MEM_CARD_BIT))
            {
                g_srv_mms_bgsr_context.send_receive_flag |= SRV_MMS_BGSR_MEM_CARD_DOWNLOADING;
            }
            if (g_srv_mms_bgsr_context.send_receive_flag)
            {
                g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS;
            }
            else
            {
                srv_mms_bgsr_mem_card_plug_out_state_hdlr();
                g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q = 0;
                g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT;
            }
            break;
        case SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS_PLUG_IN_PENDING:
            g_srv_mms_bgsr_context.mem_card_state = SRV_MMS_BGSR_MEM_CARD_STATE_PLUG_OUT_PROCESS;
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_mem_card_plug_out_state_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_mem_card_plug_out_state_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *message;

#ifdef __MMI_MMS_FALLBACK__
    U8 send_msg = 0;
    U8 download_msg = 0;
#endif /* __MMI_MMS_FALLBACK__ */ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_FALLBACK__
    if (g_srv_mms_bgsr_context.fallback_send_id || g_srv_mms_bgsr_context.fallback_download_id)
    {
        send_msg = srv_mms_bgsr_find_msg(g_srv_mms_bgsr_context.fallback_send_id);
        download_msg = srv_mms_bgsr_find_msg(g_srv_mms_bgsr_context.fallback_download_id);
        if (send_msg & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                SRV_MMS_BGSR_DELETE_FALLBACK_SCREEN,
                g_srv_mms_bgsr_context.fallback_send_id,
                __LINE__);
            srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
            /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
            if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
            {
                srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                g_srv_mms_bgsr_context.fallback_sim_id = 0;
            }
        }
        else if (download_msg & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                SRV_MMS_BGSR_DELETE_FALLBACK_SCREEN,
                g_srv_mms_bgsr_context.fallback_download_id,
                __LINE__);
            srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
            /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
            if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
            {
                srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                g_srv_mms_bgsr_context.fallback_sim_id = 0;
            }
        }
    }
#endif /* __MMI_MMS_FALLBACK__ */ 
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_send_q;
    while (*message != 0)
    {
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            *(message) &= (~SRV_MMS_BGSR_MEM_CARD_BIT);
            *(message) = mem_card_next_array[*(message) - 1];
        }
        else
        {
            message = &ph_mem_next_array[(*message) - 1];
        }
    }
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q;
    while (*message != 0)
    {
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            *(message) &= (~SRV_MMS_BGSR_MEM_CARD_BIT);
            *(message) = mem_card_next_array[*(message) - 1];
        }
        else
        {
            message = &ph_mem_next_array[(*message) - 1];
        }
    }
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_download_q;
    while (*message != 0)
    {
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            *(message) &= (~SRV_MMS_BGSR_MEM_CARD_BIT);
            *(message) = mem_card_next_array[*(message) - 1];
        }
        else
        {
            message = &ph_mem_next_array[(*message) - 1];
        }
    }
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q;
    while (*message != 0)
    {
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            *(message) &= (~SRV_MMS_BGSR_MEM_CARD_BIT);
            *(message) = mem_card_next_array[*(message) - 1];
        }
        else
        {
            message = &ph_mem_next_array[(*message) - 1];
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_init_mem_card_file_system
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_init_mem_card_file_system()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = 0;
    U32 size = 0;
    U8 checksum = 0;
    kal_wchar folder_path[SRV_MMS_BGSR_MAX_PATH_LEN];
    kal_wchar file_path[SRV_MMS_BGSR_MAX_PATH_LEN];
    kal_wchar file_path_bk[SRV_MMS_BGSR_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf((kal_uint16*) folder_path, "%c:\\%s", SRV_MMS_BGSR_MEM_CARD_DRV, SRV_MMS_BGSR_MEM_CARD_FLDR_NAME);
    kal_wsprintf(
        (kal_uint16*) file_path,
        "%c:\\%s\\%s",
        SRV_MMS_BGSR_MEM_CARD_DRV,
        SRV_MMS_BGSR_MEM_CARD_FLDR_NAME,
        SRV_MMS_BGSR_FILE_NAME);
    kal_wsprintf(
        (kal_uint16*) file_path_bk,
        "%c:\\%s\\%s",
        SRV_MMS_BGSR_MEM_CARD_DRV,
        SRV_MMS_BGSR_MEM_CARD_FLDR_NAME,
        SRV_MMS_BGSR_FILE_NAME_BACKUP);
    file_handle = FS_Open((UI_string_type) folder_path, FS_READ_ONLY);

    if (file_handle > 0)
    {
        FS_Close(file_handle);
    }
    else
    {
        FS_CreateDir((PU16) folder_path);
        FS_SetAttributes((unsigned short*)folder_path, FS_ATTR_DIR | FS_ATTR_HIDDEN);
    }

    /* Infor file */

    file_handle = FS_Open((UI_string_type) file_path, FS_READ_ONLY);
    if (file_handle < 0)
    {
        file_handle = FS_Open((UI_string_type) file_path_bk, FS_READ_ONLY);
        if (file_handle > 0)
        {
            FS_Read(file_handle, &checksum, 1, &size);
            FS_Read(file_handle, mem_card_msg_array, sizeof(mem_card_msg_array), &size);
            FS_Close(file_handle);
        }
    }
    else
    {
        FS_Read(file_handle, &checksum, 1, &size);
        FS_Read(file_handle, mem_card_msg_array, sizeof(mem_card_msg_array), &size);
        if (checksum != srv_mms_bgsr_generate_check_sum((U8*) mem_card_msg_array, sizeof(mem_card_msg_array)))
        {
            FS_Close(file_handle);
            file_handle = FS_Open((UI_string_type) file_path_bk, FS_READ_ONLY);
            if (file_handle > 0)
            {
                FS_Read(file_handle, &checksum, 1, &size);
                FS_Read(file_handle, mem_card_msg_array, sizeof(mem_card_msg_array), &size);
                FS_Close(file_handle);
            }
        }
        else
        {
            FS_Close(file_handle);
            return;
        }
    }
    if (checksum != srv_mms_bgsr_generate_check_sum((U8*) mem_card_msg_array, sizeof(mem_card_msg_array)) ||
        file_handle < 0)
    {
        file_handle = FS_Open((UI_string_type) file_path, FS_CREATE);
        memset(mem_card_msg_array, 0, sizeof(srv_mms_bgsr_msg_struct) * SRV_MMS_BGSR_MAX_MSG_NUM);
        checksum = 0;
        FS_Write(file_handle, &checksum, 1, &size);
        FS_Write(file_handle, mem_card_msg_array, sizeof(mem_card_msg_array), &size);
        FS_Close(file_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_init_mem_card_msg_array
 * DESCRIPTION
 *  synchronization
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_init_mem_card_msg_array(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write your local var declare here */

    int i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(mem_card_next_array, 0, sizeof(mem_card_next_array));
    for (i = 0; i < SRV_MMS_BGSR_MAX_MSG_NUM; i++)
    {
        if (mem_card_msg_array[i].msg_id != 0)
        {
            switch (mem_card_msg_array[i].status)
            {
                case SRV_MMS_BGSR_STATUS_SENDING:
                    srv_mms_bgsr_set_no_of_tries(
                        (U8) (i + 1 | SRV_MMS_BGSR_MEM_CARD_BIT),
                        (U8) (srv_mms_bgsr_get_no_of_tries ((U8) (i + 1 | SRV_MMS_BGSR_MEM_CARD_BIT)) + 1));
                case SRV_MMS_BGSR_STATUS_WAITING_FOR_SEND:
                case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_SEND:
                    mem_card_msg_array[i].status = SRV_MMS_BGSR_STATUS_DEFERRED_FOR_SEND;
                case SRV_MMS_BGSR_STATUS_SEND_FAIL:
                case SRV_MMS_BGSR_STATUS_DEFERRED_FOR_SEND:
                case SRV_MMS_BGSR_STATUS_SAVING:
                case SRV_MMS_BGSR_STATUS_DELETING:
                    srv_mms_bgsr_enqueue(
                        (U8) (i + 1 | SRV_MMS_BGSR_MEM_CARD_BIT),
                        &(g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q));
                    break;
                case SRV_MMS_BGSR_STATUS_DOWNLOADING:
                    srv_mms_bgsr_set_no_of_tries(
                        (U8) (i + 1 | SRV_MMS_BGSR_MEM_CARD_BIT),
                        (U8) (srv_mms_bgsr_get_no_of_tries ((U8) (i + 1 | SRV_MMS_BGSR_MEM_CARD_BIT)) + 1));
                case SRV_MMS_BGSR_STATUS_WAITING_FOR_DOWNLOAD:
                case SRV_MMS_BGSR_STATUS_POSTPONE_FOR_DOWNLOAD:
                    mem_card_msg_array[i].status = SRV_MMS_BGSR_STATUS_DEFERRED_FOR_DOWNLOAD;

                case SRV_MMS_BGSR_STATUS_DOWNLOAD_FAIL:
                case SRV_MMS_BGSR_STATUS_DEFERRED_FOR_DOWNLOAD:
                    srv_mms_bgsr_enqueue(
                        (U8) (i + 1 | SRV_MMS_BGSR_MEM_CARD_BIT),
                        &(g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q));
                    break;
                default:
                    mem_card_msg_array[i].msg_id = 0;
                    srv_mms_bgsr_enqueue(
                        (U8) (i + 1 | SRV_MMS_BGSR_MEM_CARD_BIT),
                        &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
                    break;
            }
        }
        else
        {
            srv_mms_bgsr_enqueue(
                (U8) (i + 1 | SRV_MMS_BGSR_MEM_CARD_BIT),
                &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
        }
        mem_card_next_array[i] = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_is_mem_card_sync
 * DESCRIPTION
 *  check bgsr is sync with MMA or not
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
U8 srv_mms_bgsr_is_mem_card_sync(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (g_srv_mms_bgsr_context.sync_flag & SRV_MMS_BGSR_MEM_CARD_SYNCED);

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_write_into_mem_card_file
 * DESCRIPTION
 *  synchronization
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_write_into_mem_card_file()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle = 0;
    U32 size = 0;
    U8 checksum = 0;
    kal_wchar file_path[SRV_MMS_BGSR_MAX_PATH_LEN];
    kal_wchar file_path_bk[SRV_MMS_BGSR_MAX_PATH_LEN];
    kal_wchar file_path_tmp[SRV_MMS_BGSR_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__)

    if (srv_usb_is_in_mass_storage_mode() || srv_mms_bgsr_mms_is_exported())
    {
        g_srv_mms_bgsr_context.bgsr_state |= SRV_MMS_BGSR_STATE_MEM_CARD_FILE_OP_PENDING;
        return;
    }
#endif /* defined(__MMI_USB_SUPPORT__) && defined(__USB_IN_NORMAL_MODE__) */ 
    kal_wsprintf(
        (kal_uint16*) file_path,
        "%c:\\%s\\%s",
        SRV_MMS_BGSR_MEM_CARD_DRV,
        SRV_MMS_BGSR_MEM_CARD_FLDR_NAME,
        SRV_MMS_BGSR_FILE_NAME);
    kal_wsprintf(
        (kal_uint16*) file_path_bk,
        "%c:\\%s\\%s",
        SRV_MMS_BGSR_MEM_CARD_DRV,
        SRV_MMS_BGSR_MEM_CARD_FLDR_NAME,
        SRV_MMS_BGSR_FILE_NAME_BACKUP);
    kal_wsprintf(
        (kal_uint16*) file_path_tmp,
        "%c:\\%s\\%s",
        SRV_MMS_BGSR_MEM_CARD_DRV,
        SRV_MMS_BGSR_MEM_CARD_FLDR_NAME,
        SRV_MMS_BGSR_FILE_NAME_TEMP);
    FS_Rename(file_path_bk, file_path_tmp);
    /* FS_Delete((U16*) file_path_bk); */
    FS_Rename(file_path, file_path_bk);
    FS_Rename(file_path_tmp, file_path);
    file_handle = FS_Open((UI_string_type) file_path, FS_CREATE);
    if (file_handle > 0)
    {
        FS_Truncate(file_handle);
        checksum = srv_mms_bgsr_generate_check_sum((U8*) mem_card_msg_array, sizeof(mem_card_msg_array));
        FS_Write(file_handle, &checksum, 1, &size);
        FS_Write(file_handle, mem_card_msg_array, sizeof(mem_card_msg_array), &size);
        FS_Close(file_handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_mem_card_format_hdlr
 * DESCRIPTION
 *  echo current infomation
 * PARAMETERS
 *  void
 * STATUS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_mem_card_format_hdlr()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *message;
    U8 next;
    U8 node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_send_q;
    while (*message != 0)
    {
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            node = (*message) & (~SRV_MMS_BGSR_MEM_CARD_BIT);
            next = mem_card_next_array[node - 1];
            mem_card_next_array[node - 1] = 0;
            srv_mms_bgsr_enqueue(*(message), &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
            *(message) = next;
        }
        else
        {
            message = &ph_mem_next_array[(*message) - 1];
        }
    }
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_send_fail_q;
    while (*message != 0)
    {
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            node = (*message) & (~SRV_MMS_BGSR_MEM_CARD_BIT);
            next = mem_card_next_array[node - 1];
            mem_card_next_array[node - 1] = 0;
            srv_mms_bgsr_enqueue(*(message), &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
            *(message) = next;
        }
        else
        {
            message = &ph_mem_next_array[(*message) - 1];
        }
    }
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_download_q;
    while (*message != 0)
    {
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            node = (*message) & (~SRV_MMS_BGSR_MEM_CARD_BIT);
            next = mem_card_next_array[node - 1];
            mem_card_next_array[node - 1] = 0;
            srv_mms_bgsr_enqueue(*(message), &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
            *(message) = next;
        }
        else
        {
            message = &ph_mem_next_array[(*message) - 1];
        }
    }
    message = &g_srv_mms_bgsr_context.srv_mms_bgsr_download_fail_q;
    while (*message != 0)
    {
        if (*message & SRV_MMS_BGSR_MEM_CARD_BIT)
        {
            node = (*message) & (~SRV_MMS_BGSR_MEM_CARD_BIT);
            next = mem_card_next_array[node - 1];
            mem_card_next_array[node - 1] = 0;
            srv_mms_bgsr_enqueue(*(message), &(g_srv_mms_bgsr_context.srv_mms_bgsr_free_mem_q));
            *(message) = next;
        }
        else
        {
            message = &ph_mem_next_array[(*message) - 1];
        }
    }
    srv_mms_bgsr_write_into_ph_mem_file();
}

#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 



/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_convert_bgsr_sim_id_to_wap_prof
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bgsr_sim_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_wap_prof_sim_id_enum srv_mms_bgsr_convert_bgsr_sim_id_to_wap_prof(U8 bgsr_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_sim_id_enum wap_prof_sim_id = SRV_WAP_PROF_SIMID_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (bgsr_sim_id)
    {
        case SRV_MMS_BGSR_SIM1:
        {
            wap_prof_sim_id = SRV_WAP_PROF_SIMID_SIM1;
        }
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case SRV_MMS_BGSR_SIM2:
        {
            wap_prof_sim_id = SRV_WAP_PROF_SIMID_SIM2;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (MMI_MAX_SIM_NUM >= 2) */
    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_MMS_BGSR_SIM3:
        {
            wap_prof_sim_id = SRV_WAP_PROF_SIMID_SIM3;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ /* (MMI_MAX_SIM_NUM >= 3) */
    #if (MMI_MAX_SIM_NUM >= 4)
        case SRV_MMS_BGSR_SIM4:
        {
            wap_prof_sim_id = SRV_WAP_PROF_SIMID_SIM4;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ /* (MMI_MAX_SIM_NUM >= 4) */
        default:
        {
            ASSERT(0);
        }
    }
    return wap_prof_sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_convert_wap_sim_to_mma
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wap_sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mma_sim_id_enum srv_mms_bgsr_convert_wap_sim_to_mma(kal_uint8 wap_sim_id)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_sim_id_enum mma_sim_id = MMA_SIM_ID_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (wap_sim_id)
    {
        case SRV_WAP_PROF_SIMID_SIM1:
            mma_sim_id = MMA_SIM_ID_SIM1;
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case SRV_WAP_PROF_SIMID_SIM2:
            mma_sim_id = MMA_SIM_ID_SIM2;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (MMI_MAX_SIM_NUM) */
    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_WAP_PROF_SIMID_SIM3:
            mma_sim_id = MMA_SIM_ID_SIM3;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ /* (MMI_MAX_SIM_NUM >= 3) */
    #if (MMI_MAX_SIM_NUM >= 4)
        case SRV_WAP_PROF_SIMID_SIM4:
            mma_sim_id = MMA_SIM_ID_SIM4;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ /* (MMI_MAX_SIM_NUM >= 4) */
        default:
            ASSERT(0);
    }
    return mma_sim_id;

}
#ifdef __MMI_MMS_FALLBACK__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_bearer_fallback_proc
 * DESCRIPTION
 *  get the bearer fallback notify
 * PARAMETERS
 *  event       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_mms_bgsr_bearer_fallback_proc(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = MMA_SIM_ID_SIM1;
    srv_cbm_bearer_event_struct *evt = (srv_cbm_bearer_event_struct*) event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_BEARER_FALLBACK_PROC, evt->account_id, evt->type, __LINE__);

    g_srv_mms_bgsr_context.acct_id = evt->account_id;

    sim_id = srv_mms_bgsr_get_sim_id(evt->account_id);

    if (g_srv_mms_bgsr_context.fallback_mask == 0)
    {
        if (g_srv_mms_bgsr_context.download_msg_id == 0 && g_srv_mms_bgsr_context.send_msg_id == 0
    #ifdef __MMI_MMS_AUTO_DWNLD_IMMED_NOTI_AFTER_INTERRUPT__
            && g_srv_mms_bgsr_context.immd_retr_sim_id == 0
    #endif 
            )
        {
            MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_FALLBACK_NOT_REQUIRED, __LINE__);

            g_srv_mms_bgsr_context.fallback_mask |= SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK;
            srv_mms_bgsr_suspend_mms_service_req();
            srv_mms_refresh_profile_settings(sim_id);
            return SRV_CBM_ERROR;
        }
    }
    if (evt->type == SRV_CBM_BEARER_FB_L1_WITH_NEW_CONN || evt->type == SRV_CBM_BEARER_FB_L2_WITH_NEW_CONN)
    {
        srv_mms_bgsr_suspend_mms_service_req();

        /* stop the application timer by aborting the current connection */

        if (sim_id == g_srv_mms_bgsr_context.send_sim_id)
        {
            g_srv_mms_bgsr_context.fallback_send_id = g_srv_mms_bgsr_context.send_msg_id;
            g_srv_mms_bgsr_context.fallback_mask |= SRV_MMS_BGSR_FALLBACK_MASK_SENDING;
        }

        if (sim_id == g_srv_mms_bgsr_context.download_sim_id)
        {
            g_srv_mms_bgsr_context.fallback_download_id = g_srv_mms_bgsr_context.download_msg_id;
            g_srv_mms_bgsr_context.fallback_mask |= SRV_MMS_BGSR_FALLBACK_MASK_DOWNLOADING;
        }
    #ifdef __MMI_MMS_AUTO_DWNLD_IMMED_NOTI_AFTER_INTERRUPT__
        if (sim_id == g_srv_mms_bgsr_context.immd_retr_sim_id)
        {
            g_srv_mms_bgsr_context.fallback_mask |= SRV_MMS_BGSR_FALLBACK_MASK_IMME_RETR;
        }
    #endif /* __MMI_MMS_AUTO_DWNLD_IMMED_NOTI_AFTER_INTERRUPT__ */ 

        g_srv_mms_bgsr_context.fallback_mask |= SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK;
        g_srv_mms_bgsr_context.fallback_sim_id = sim_id;
        srv_mms_bgsr_update_profile(sim_id);
        MMI_TRACE(
            MMI_INET_TRC_G6_MMS,
            SRV_MMS_BGSR_BEARER_FALLBACK_NOTIFY_MASK_INFO,
            g_srv_mms_bgsr_context.fallback_send_id,
            g_srv_mms_bgsr_context.fallback_download_id,
            g_srv_mms_bgsr_context.fallback_mask,
            g_srv_mms_bgsr_context.immd_retr_sim_id,
            __LINE__);

        return SRV_CBM_OK;
    }

    return SRV_CBM_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_update_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mma_sim_id      [IN]        
 *  sim_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_update_profile(U8 mma_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_profile_content_struct *profile_struct = NULL;
    U8 bgsr_sim_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_UPDATE_PROFILE, mma_sim_id);
    if (mma_sim_id)
    {
        bgsr_sim_id = srv_mms_bgsr_convert_mma_sim_id_to_bgsr_sim_id(mma_sim_id);
        profile_struct =
            (srv_wap_prof_profile_content_struct*)
            srv_wap_prof_get_profile_content(
                srv_mms_bgsr_convert_bgsr_sim_id_to_wap_prof(bgsr_sim_id),
                SRV_WAP_PROF_APPID_MMS,
                (U8) - 1,
                SRV_WAP_PROF_DTCNT_SECONDARY,
                NULL);
    }

    MMI_ASSERT(profile_struct);
    if (profile_struct)
    {
        srv_mms_bgsr_set_profile_req(profile_struct, mma_sim_id);
        OslMfree(profile_struct);
        profile_struct = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_send_select_rsp_handler
 * DESCRIPTION
 *  Get memory status request
 * PARAMETERS
 *  sim_id      [IN]        
 *  U8(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_send_select_rsp_handler(U8 sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MMI_ID    app_id; 
    //cui_cbm_parameter_struct param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_FALLBACK_MASK, sim_id, g_srv_mms_bgsr_context.fallback_mask, __LINE__);

    if (g_srv_mms_bgsr_context.fallback_mask == SRV_MMS_BGSR_FALLBACK_MASK_NEED_FALLBACK)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_SELECT_RSP_HANDLER_NEED_FALLBACK, sim_id, __LINE__);

        srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CREATE, g_srv_mms_bgsr_context.acct_id);

        /* app_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, srv_mms_bgsr_bearer_fallback_cui_proc, NULL);
           mmi_frm_group_enter(app_id,  MMI_FRM_NODE_SMART_CLOSE_FLAG);
           g_srv_mms_bgsr_context.cbm_cui_id = cui_cbm_bearer_fallback_create(app_id);
           param.account_id = g_srv_mms_bgsr_context.acct_id;
           param.res.icon_id = GetRootTitleIcon(SERVICES_WAP_MENU_ID); //GetRootTitleIcon(MAIN_MENU_MESSAGES_MENUID);
           param.res.str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;  //STR_MMS_MENUENTRY
           cui_cbm_bearer_fallback_set_param(g_srv_mms_bgsr_context.cbm_cui_id, &param);
           cui_cbm_bearer_fallback_run(g_srv_mms_bgsr_context.cbm_cui_id); */
    }
    else if (g_srv_mms_bgsr_context.fallback_sim_id != 0 && g_srv_mms_bgsr_context.fallback_mask == 0)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_SEND_SELECT_RSP_HANDLER_SET_PROFILE, sim_id, __LINE__);
        srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
        g_srv_mms_bgsr_context.fallback_sim_id = 0;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_bearer_fallback_cui_proc
 * DESCRIPTION
 *  Process function for the Level 1 bearer fallback CUI
 * PARAMETERS
 *  evt     [?]     
 *  mmi_event_struct(?)
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_mms_bgsr_bearer_fallback_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = MMA_SIM_ID_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, SRV_MMS_BGSR_BEARER_FALLBACK_CUI_PROC, evt->evt_id);
    sim_id = srv_mms_bgsr_get_sim_id(g_srv_mms_bgsr_context.acct_id);
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_CBM_OK:
        {
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                SRV_MMS_BGSR_BEARER_FALLBACK_NOTIFY_MASK_INFO,
                g_srv_mms_bgsr_context.fallback_send_id,
                g_srv_mms_bgsr_context.fallback_download_id,
                g_srv_mms_bgsr_context.fallback_mask,
                g_srv_mms_bgsr_context.immd_retr_sim_id,
                __LINE__);

            srv_mms_bgsr_resume_mms_service_req();
            srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
            /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
            break;
        }
        case EVT_ID_CUI_CBM_CANCEL:
        case EVT_ID_CUI_CBM_FAIL:
        {
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                SRV_MMS_BGSR_BEARER_FALLBACK_NOTIFY_MASK_INFO,
                g_srv_mms_bgsr_context.fallback_send_id,
                g_srv_mms_bgsr_context.fallback_download_id,
                g_srv_mms_bgsr_context.fallback_mask,
                g_srv_mms_bgsr_context.immd_retr_sim_id,
                __LINE__);

            srv_mms_bgsr_resume_mms_service_req();
        #ifdef __MMI_UMMS_JSR205__
            if (g_srv_mms_bgsr_context.fallback_send_id != 0
                && g_srv_mms_bgsr_context.fallback_send_id == g_srv_mms_bgsr_context.java_send_msg_id)
            {
                srv_mms_bgsr_delete_mms_req(g_srv_mms_bgsr_context.java_send_msg_id);
                srv_mms_jsr_update_send_msg_icon(
                    g_srv_mms_bgsr_context.java_send_msg_id,
                    SRV_MMS_BGSR_STATUS_SEND_FAIL);
                srv_mms_jsr_send_msg_rsp(
                    (U16) g_srv_mms_bgsr_context.java_send_msg_id,
                    SRV_MMS_BGSR_RESULT_FAIL_USER_CANCEL);
                g_srv_mms_bgsr_context.java_send_msg_id = 0;

            }
        #endif /* __MMI_UMMS_JSR205__ */ 
        #ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
            if (g_srv_mms_bgsr_context.fallback_send_id != 0
                && g_srv_mms_bgsr_context.fallback_send_id == g_srv_mms_bgsr_context.vendor_send_msg_id)
            {
                srv_mms_vendor_send_rsp_callback(
                    g_srv_mms_bgsr_context.vendor_send_msg_id,
                    SRV_MMS_BGSR_RESULT_FAIL_USER_CANCEL);
                g_srv_mms_bgsr_context.vendor_send_msg_id = 0;
            }
        #endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
            g_srv_mms_bgsr_context.fallback_send_id = 0;
            g_srv_mms_bgsr_context.fallback_download_id = 0;
            srv_mms_bgsr_send_events(EVT_ID_SRV_BGSR_FALLBACK_CUI_CLOSE, g_srv_mms_bgsr_context.acct_id);
            /* cui_cbm_bearer_fallback_close(g_srv_mms_bgsr_context.cbm_cui_id); */
            if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
            {
                srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                g_srv_mms_bgsr_context.fallback_sim_id = 0;
            }
            break;
        }
        case EVT_ID_GROUP_GOBACK_IN_END_KEY:
        {
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                SRV_MMS_BGSR_BEARER_FALLBACK_NOTIFY_MASK_INFO,
                g_srv_mms_bgsr_context.fallback_send_id,
                g_srv_mms_bgsr_context.fallback_download_id,
                g_srv_mms_bgsr_context.fallback_mask,
                g_srv_mms_bgsr_context.immd_retr_sim_id,
                __LINE__);

            if (g_srv_mms_bgsr_context.fallback_sim_id != 0)
            {
                srv_mms_bgsr_resume_mms_service_req();
            #ifdef __MMI_UMMS_JSR205__
                if (g_srv_mms_bgsr_context.fallback_send_id != 0
                    && g_srv_mms_bgsr_context.fallback_send_id == g_srv_mms_bgsr_context.java_send_msg_id)
                {
                    srv_mms_bgsr_delete_mms_req(g_srv_mms_bgsr_context.java_send_msg_id);
                    srv_mms_jsr_update_send_msg_icon(
                        g_srv_mms_bgsr_context.java_send_msg_id,
                        SRV_MMS_BGSR_STATUS_SEND_FAIL);
                    srv_mms_jsr_send_msg_rsp(
                        (U16) g_srv_mms_bgsr_context.java_send_msg_id,
                        SRV_MMS_BGSR_RESULT_FAIL_USER_CANCEL);
                    g_srv_mms_bgsr_context.java_send_msg_id = 0;
                }
            #endif /* __MMI_UMMS_JSR205__ */ 
            #ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
                if (g_srv_mms_bgsr_context.fallback_send_id != 0
                    && g_srv_mms_bgsr_context.fallback_send_id == g_srv_mms_bgsr_context.vendor_send_msg_id)
                {
                    srv_mms_vendor_send_rsp_callback(
                        g_srv_mms_bgsr_context.vendor_send_msg_id,
                        SRV_MMS_BGSR_RESULT_FAIL_USER_CANCEL);
                    g_srv_mms_bgsr_context.vendor_send_msg_id = 0;
                }
            #endif /* __MMI_MMS_VENDOR_APP_SUPPORT__ */ 
                g_srv_mms_bgsr_context.fallback_send_id = 0;
                g_srv_mms_bgsr_context.fallback_download_id = 0;
                srv_mms_refresh_profile_settings(g_srv_mms_bgsr_context.fallback_sim_id);
                g_srv_mms_bgsr_context.fallback_sim_id = 0;
            }
            break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_get_sim_id
 * DESCRIPTION
 *  Get the sim id for the give accoung id
 * PARAMETERS
 *  acct_id     [IN]        
 *  U8(?)
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_mms_bgsr_get_sim_id(U32 acct_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_account_info_struct acct_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cbm_decode_data_account_id_ext(acct_id, &acct_info);
    switch (acct_info.account[0].sim_id)
    {
        case CBM_SIM_ID_SIM1:
            return MMA_SIM_ID_SIM1;
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case CBM_SIM_ID_SIM2:
            return MMA_SIM_ID_SIM2;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (MMI_MAX_SIM_NUM >= 2) */
    #if (MMI_MAX_SIM_NUM >= 3)
        case CBM_SIM_ID_SIM3:
            return MMA_SIM_ID_SIM3;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ /* (MMI_MAX_SIM_NUM >=  3) */
    #if (MMI_MAX_SIM_NUM >= 4)
        case CBM_SIM_ID_SIM4:
            return MMA_SIM_ID_SIM4;
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ /* (MMI_MAX_SIM_NUM >= 4) */
        default:
            return MMA_SIM_ID_SIM1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_send_events
 * DESCRIPTION
 *  Sends the event
 * PARAMETERS
 *  evt_id      [IN]        
 *  act_id      [IN]        
 *  event id and account id(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_bgsr_send_events(mmi_id evt_id, U32 act_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_fallback_cui_struct bearer_evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&bearer_evt, evt_id);
    bearer_evt.account_id = act_id;
    MMI_FRM_CB_EMIT_EVENT(&bearer_evt);
}

#endif /* __MMI_MMS_FALLBACK__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_is_sim_valid
 * DESCRIPTION
 *  ;
 *  return TRUE if the given sim is valid
 * CALLS
 *  
 * PARAMETERS
 *  bgsr_sim_id     [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_mms_bgsr_is_sim_valid(U8 bgsr_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_srv_mms_bgsr_context.is_sim_valid & bgsr_sim_id) &&
        !srv_sim_ctrl_chv1_is_blocked(srv_mms_bgsr_convert_bgsr_sim_id_to_mmi_sim_id(bgsr_sim_id)))
    {
        return TRUE;
    }
    return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_convert_mmi_sim_id_to_bgsr_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mmi_sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_mms_bgsr_sim_id_enum srv_mms_bgsr_convert_mmi_sim_id_to_bgsr_sim_id(U8 mmi_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_sim_id_enum bgsr_sim_id = SRV_MMS_BGSR_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mmi_sim_id)
    {
        case MMI_SIM1:
        {
            bgsr_sim_id = SRV_MMS_BGSR_SIM1;
        }
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMI_SIM2:
        {
            bgsr_sim_id = SRV_MMS_BGSR_SIM2;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (MMI_MAX_SIM_NUM >= 2) */
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMI_SIM3:
        {
            bgsr_sim_id = SRV_MMS_BGSR_SIM3;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ /* (MMI_MAX_SIM_NUM >= 3) */
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMI_SIM4:
        {
            bgsr_sim_id = SRV_MMS_BGSR_SIM4;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ /* (MMI_MAX_SIM_NUM >= 4) */
        default:
        {
            ASSERT(0);
        }
    }
    return bgsr_sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_convert_bgsr_sim_id_to_mmi_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bgsr_sim_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_sim_enum srv_mms_bgsr_convert_bgsr_sim_id_to_mmi_sim_id(U8 bgsr_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum mmi_sim_id = MMI_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (bgsr_sim_id)
    {
        case SRV_MMS_BGSR_SIM1:
        {
            mmi_sim_id = MMI_SIM1;
        }
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case SRV_MMS_BGSR_SIM2:
        {
            mmi_sim_id = MMI_SIM2;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (MMI_MAX_SIM_NUM >= 2) */
    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_MMS_BGSR_SIM3:
        {
            mmi_sim_id = MMI_SIM3;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ /* (MMI_MAX_SIM_NUM >= 3) */
    #if (MMI_MAX_SIM_NUM >= 4)
        case SRV_MMS_BGSR_SIM4:
        {
            mmi_sim_id = MMI_SIM4;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ /* (MMI_MAX_SIM_NUM >= 4) */
        default:
        {
            ASSERT(0);
        }
    }
    return mmi_sim_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_convert_index
 * DESCRIPTION
 *  this function gives bgsr sim ids
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_mms_bgsr_convert_index(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (0x01 << (index - 1));
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_convert_mma_sim_id_to_bgsr_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mma_sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_mms_bgsr_sim_id_enum srv_mms_bgsr_convert_mma_sim_id_to_bgsr_sim_id(U8 mma_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_bgsr_sim_id_enum bgsr_sim_id = SRV_MMS_BGSR_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mma_sim_id)
    {
        case MMA_SIM_ID_SIM1:
        {
            bgsr_sim_id = SRV_MMS_BGSR_SIM1;
        }
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMA_SIM_ID_SIM2:
        {
            bgsr_sim_id = SRV_MMS_BGSR_SIM2;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (MMI_MAX_SIM_NUM) */
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMA_SIM_ID_SIM3:
        {
            bgsr_sim_id = SRV_MMS_BGSR_SIM3;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ /* (MMI_MAX_SIM_NUM >= 3) */
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMA_SIM_ID_SIM4:
        {
            bgsr_sim_id = SRV_MMS_BGSR_SIM4;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ /* (MMI_MAX_SIM_NUM >= 4) */
        default:
        {
            ASSERT(0);
        }
    }
    return bgsr_sim_id;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_bgsr_convert_mma_sim_id_to_cbm_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mma_sim_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
cbm_sim_id_enum srv_mms_bgsr_convert_mma_sim_id_to_cbm_sim_id(U8 mma_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_sim_id_enum cbm_sim_id = CBM_SIM_ID_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (mma_sim_id)
    {
        case MMA_SIM_ID_SIM1:
        {
            cbm_sim_id = CBM_SIM_ID_SIM1;
        }
            break;
    #if (MMI_MAX_SIM_NUM >= 2)
        case MMA_SIM_ID_SIM2:
        {
            cbm_sim_id = CBM_SIM_ID_SIM2;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 2) */ /* (MMI_MAX_SIM_NUM) */
    #if (MMI_MAX_SIM_NUM >= 3)
        case MMA_SIM_ID_SIM3:
        {
            cbm_sim_id = CBM_SIM_ID_SIM3;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 3) */ /* (MMI_MAX_SIM_NUM >= 3) */
    #if (MMI_MAX_SIM_NUM >= 4)
        case MMA_SIM_ID_SIM4:
        {
            cbm_sim_id = CBM_SIM_ID_SIM4;
        }
            break;
    #endif /* (MMI_MAX_SIM_NUM >= 4) */ /* (MMI_MAX_SIM_NUM >= 4) */
        default:
        {
            ASSERT(0);
        }
    }
    return cbm_sim_id;
}

#endif /* __MMI_MMS_BGSR_SUPPORT__ */ 

