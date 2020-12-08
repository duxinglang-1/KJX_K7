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
 *  Vapp_rmgr_sweep.c
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  File to handle the sweep operation for Rights Manager
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *          HISTORY
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_include.h"

#ifdef __MMI_RMGR__

#include "custom_mmi_default_value.h"
#include "RightsMgrGprot.h"
#include "RightsMgrProt.h"
#include "Vapp_rmgr_service.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "TimerEvents.h"
#include "drm_gprot.h"
//#include "drm_msg.h"
#include "drm_memory.h"
#include "FileMgrSrvGProt.h"
#include "drm_errcode.h"
#include "Conversions.h"
#include "FileManagerResDef.h"
#include "FileManagerGProt.h"           /* GetFileSystemErrorString */
#include "IdleAppProt.h"                
#include "CommonScreens.h"  /* gIndexIconsImageList */

#include "stack_msgs.h" /* MSG_ID_MMI_NW_PWROFF_DETACH_REQ*/
#include "ProtocolEvents.h" /* PRT_EQ_USB_DETECT_IND */
#include "AlarmFrameworkProt.h" /* AlmDeInit */
#include "SettingResDef.h" /* STR_SETTING_NOTICE_SUCCESS_REBOOT_TEXT */
#include "USBDeviceGprot.h"             /* mmi_usb_is_in_mass_storage_mode */
#include "mmi_rp_vapp_rmgr_def.h"
#ifdef __MMI_UCM__
#include "UcmSrvGprot.h"
#endif /*__MMI_UCM__*/

#include "mdi_datatype.h"
#include "mdi_audio.h"      /* mdi_audio_stop_all */

#ifdef __MMI_OP01_DCD__
#include "DCDGprot.h"
#endif

#include "MMI_features.h"
#include "MMIDataType.h"
#include "wgui_categories_list.h"
#include "kal_general_types.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_history_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "RightsMgrResDef.h"
#include "wgui_categories_popup.h"
#include "GlobalResDef.h"
#include "CustDataRes.h"
#include "custom_events_notify.h"
#include "GlobalConstants.h"
#include "wgui_categories_util.h"
#include "drm_errcode.h"
#include "AlertScreen.h"
#include "mmi_rp_srv_filemanager_def.h"
#include "FileMgrSrvGProt.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "kal_public_api.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "stack_common.h"
#include "drm_def.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_nvram_gprot.h"
#include "menucuigprot.h"
#include "gui_data_types.h"
#include "MmsSrvGProt.h"
#include "Vapp_rmgr_cntx.h"



extern void vtst_rmgr_list_entry_format_cb(U32 i);
extern vtst_rmgr_list_entry_sweep(U32 i);



/*
 * Define
 */

/*
 * Local Variable
 */
U8 rmgr_dbchk_nv;

/*
 * Static Declaration
 */
// akhil




 rmgr_process_db_cntx_struct rmgr_process_db_cntx = {0};




/*
 * Local Function
 */
#if 0
/* under construction !*/
#endif
#ifdef WAP_SUPPORT
#ifdef OBIGO_Q03C_MMS_V02
static void mmi_rmgr_send_mms_shutdown_req(void);
void mmi_rmgr_power_off_cb_from_mms(srv_mms_result_enum result, void *rsp_data, void *user_data);
#else
static void mmi_rmgr_send_wap_shutdown_req(void);
#endif
#endif /* WAP_SUPPORT */ 
static void mmi_rmgr_send_nw_pwroff_detach_req(void);
#ifdef __MMI_DUAL_SIM_MASTER__
static void mmi_rmgr_send_nw2_pwroff_detach_req(void);
#endif
static void mmi_rmgr_disable_interrupt(void);

#ifdef __DRM_SUPPORT_SCAN_DISK__
static void mmi_rmgr_toggle_scan_disk(void);
#endif

typedef struct
{
    U16 eventID;
    MMI_BOOL slave;
    FuncPtr callback;
} mmi_rmgr_reboot_callback_struct;

static mmi_rmgr_reboot_callback_struct mmi_rmgr_reboot_callback[] =
{
    {0, MMI_FALSE, AlmDeInit},
    {0, MMI_FALSE, (FuncPtr)mdi_audio_suspend_background_play},
    {0, MMI_FALSE, mmi_rmgr_disable_interrupt},

#ifdef __MTK_TARGET__
    {MSG_ID_MMI_NW_PWROFF_DETACH_RSP, MMI_FALSE, mmi_rmgr_send_nw_pwroff_detach_req},
    #ifdef __MMI_DUAL_SIM_MASTER__
    {MSG_ID_MMI_NW_PWROFF_DETACH_RSP, MMI_TRUE, mmi_rmgr_send_nw2_pwroff_detach_req},
    #endif
#endif /* __MTK_TARGET__ */ 

#ifdef WAP_SUPPORT
    #ifdef OBIGO_Q03C_MMS_V02
    {0, MMI_FALSE, mmi_rmgr_send_mms_shutdown_req},   /* shutdown mms and wap */
    #else
    {MSG_ID_WAP_BROWSER_POWEROFF_RSP, MMI_FALSE, mmi_rmgr_send_wap_shutdown_req},   /* shutdown wap */
    #endif
#endif /* WAP_SUPPORT */ 

#ifdef __MMI_OP01_DCD__
    {0, MMI_FALSE, (FuncPtr)mmi_dcd_finalize},  /* DCD neeed to save some setting before shutdown */
#endif

    {0, MMI_FALSE, NULL}
};

static const S32 mmi_rmgr_reboot_cb_n = sizeof(mmi_rmgr_reboot_callback) / sizeof(mmi_rmgr_reboot_callback_struct) - 1;
static U8 counter_of_reboot = 0;

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
#endif /*0*/

/*mmi_rmgr_entry_db_progressing STATE HANDLING!!!!*/

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_reboot_ms_int
 * DESCRIPTION
 *  reboot handset immediately
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_reboot_ms_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    AlmATPowerReset(MMI_FALSE, 3); /* shutdown system and reboot in 3 seconds. */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_process_database_callback
 * DESCRIPTION
 *  The protocol event handler for the sweep response msg, If there is another
 *  screen jumping in, simply remove the history node of the sweep progress screen.
 *  When the interrupter screen goes back history, it will display the rights
 *  manager screen. Otherwise, enter the sweep done screen.
 * PARAMETERS
 *  serial      [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_process_database_callback(kal_uint8 serial, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*LAUNCH RMGR Application from here to show result popup*/
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
	#endif

    if (rmgr_process_db_cntx.path)
    {
        drmt_mem_free(rmgr_process_db_cntx.path);
        rmgr_process_db_cntx.path = NULL;
    }

    if (rmgr_process_db_cntx.reboot_type > 0)
    {
        //ClearInputEventHandler(MMI_DEVICE_PEN);
        //SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_EVENT_DOWN);
        //SetGroupKeyHandler(NULL, (PU16) PresentAllKeys, (U8) TOTAL_KEYS, (U16) KEY_LONG_PRESS);
        /*mmi_frm_block_general_interrupt_event (MMI_FRM_INT_TOTAL_INTERRUPT_EVENT);*/

        rmgr_process_db_cntx.reboot_type = 0;
        StartTimer(BOOTUP_POPUP_TIMER, 800, mmi_rmgr_reboot_ms_int);
    }
}
U8 mmi_rmgr_reboot_ms_slave(void *info, int mod_src)
{
	mmi_rmgr_reboot_ms(NULL);
	return MMI_TRUE;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_recv_nw2_pwroff_detach_rsp
 * DESCRIPTION
 *  This function is to handle MSG_ID_MMI_NW_PWROFF_DETACH_RSP
 * PARAMETERS
 *  msg     [IN]        MSG_ID_MMI_NW_PWROFF_DETACH_RSP
 * RETURNS
 *  void
 *****************************************************************************/



void mmi_rmgr_reboot_ms(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for( ; counter_of_reboot < mmi_rmgr_reboot_cb_n; counter_of_reboot++)
    {
        /* need send message and wait resopnse */
        if (mmi_rmgr_reboot_callback[counter_of_reboot].eventID)
        {
#ifdef __MMI_DUAL_SIM_MASTER__
            if (!mmi_rmgr_reboot_callback[counter_of_reboot].slave)
            {
                SetProtocolEventHandler(mmi_rmgr_reboot_ms, mmi_rmgr_reboot_callback[counter_of_reboot].eventID);
            }
            else
            {
            	  mmi_frm_set_protocol_event_handler(mmi_rmgr_reboot_callback[counter_of_reboot].eventID, (PsIntFuncPtr) mmi_rmgr_reboot_ms_slave, MMI_FALSE);
                /*SetSlaveProtocolEventHandler(mmi_rmgr_reboot_ms, mmi_rmgr_reboot_callback[counter_of_reboot].eventID);*/
            }
        #else /* __MMI_DUAL_SIM_MASTER__ */ 
            SetProtocolEventHandler(mmi_rmgr_reboot_ms, mmi_rmgr_reboot_callback[counter_of_reboot].eventID);
        #endif /* __MMI_DUAL_SIM_MASTER__ */ 
            mmi_rmgr_reboot_callback[counter_of_reboot].callback();

            counter_of_reboot++;
            return;
        }
        else /* callback only */
        {
            if (mmi_rmgr_reboot_callback[counter_of_reboot].callback)
            {
                mmi_rmgr_reboot_callback[counter_of_reboot].callback();
            }
            else
            {
                ASSERT(0);
            }
        }
    }

    /* all response finished */

    counter_of_reboot = 0;

    result = DRM_process_database(
                (kal_uint8) (rmgr_process_db_cntx.reboot_type - 1),
                                  -1,
                                  (kal_wchar*)rmgr_process_db_cntx.path,
                                  (kal_uint8*)&rmgr_process_db_cntx.serial,
                                  mmi_rmgr_process_database_callback);

    if (result != DRM_PROC_ENCRYPT_BUSY)
    {
        mmi_rmgr_process_database_callback(rmgr_process_db_cntx.serial, result);
    }

}



#ifdef __MMI_DUAL_SIM_MASTER__



/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_send_nw2_pwroff_detach_req
 * DESCRIPTION
 *  This function is to handle MSG_ID_MMI_NW_PWROFF_DETACH_RSP
 * PARAMETERS
 *  msg     [IN]        MSG_ID_MMI_NW_PWROFF_DETACH_RSP
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_send_nw2_pwroff_detach_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C_2;
    Message.oslSapId = MMI_L4C_SAP;
    Message.oslMsgId = MSG_ID_MMI_NW_PWROFF_DETACH_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}
#endif /* __MMI_DUAL_SIM_MASTER__ */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_send_nw_pwroff_detach_req
 * DESCRIPTION
 *  This function is to handle MSG_ID_MMI_NW_PWROFF_DETACH_RSP
 * PARAMETERS
 *  void
 *  msg(?)      [IN]        MSG_ID_MMI_NW_PWROFF_DETACH_RSP
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_send_nw_pwroff_detach_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_L4C;
    Message.oslSapId = MMI_L4C_SAP;
    Message.oslMsgId = MSG_ID_MMI_NW_PWROFF_DETACH_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

#ifdef WAP_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_send_wap_shutdown_req
 * DESCRIPTION
 *  This function is to send  MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifndef OBIGO_Q03C_MMS_V02
static void mmi_rmgr_send_wap_shutdown_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    Message.oslSrcId = MOD_MMI;
    Message.oslDestId = MOD_WAP;
    Message.oslMsgId = MSG_ID_WAP_BROWSER_POWEROFF_REQ;
    Message.oslDataPtr = (oslParaType*) NULL;
    Message.oslPeerBuffPtr = NULL;
    OslMsgSendExtQueue(&Message);
}

#else
/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_send_wap_shutdown_req
 * DESCRIPTION
 *  This function is to send  MSG_ID_WAP_RESTORE_FACTORY_SETTING_REQ
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_send_mms_shutdown_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MYQUEUE Message;
	srv_mms_power_off_req_struct req_by_rmgr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    memset(&req_by_rmgr,0, sizeof(req_by_rmgr));
	req_by_rmgr.user_data = NULL;
	req_by_rmgr.call_back = mmi_rmgr_power_off_cb_from_mms;
	srv_mms_power_off(&req_by_rmgr);
}

void mmi_rmgr_power_off_cb_from_mms(srv_mms_result_enum result, void *rsp_data, void *user_data)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
}


#endif
#endif /* WAP_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_disable_usb
 * DESCRIPTION
 *  This function is to disable usb
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_disable_interrupt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_USB_SUPPORT__
    ClearProtocolEventHandler(PRT_EQ_USB_DETECT_IND);
    ClearProtocolEventHandler(PRT_BATTERY_STATUS_IND);
#endif
}

/*mmi_rmgr_sweep_entry_progress state maintence*/

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
/* under construction !*/
#ifdef __DM_LAWMO_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__DM_LAWMO_SUPPORT__*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_BACKGROUND_CALL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_BACKGROUND_CALL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_RMGR_SWEEP_DB_PERIODICALLY__
/* under construction !*/
        #endif
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
#endif /*0*/
/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_db_chk_toggle
 * DESCRIPTION
 *  To toggle db space check
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_db_chk_toggle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (rmgr_dbchk_nv)
    {
        rmgr_dbchk_nv = 0;
    }
    else
    {
        rmgr_dbchk_nv = 1;
    }
    vapp_set_rmgr_spc(rmgr_dbchk_nv);
    WriteValue(NVRAM_RMGR_DB_CHECK, &rmgr_dbchk_nv, DS_BYTE, &error);

    //mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
}

#ifdef __DRM_V02__
/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_backup_entry_main
 * DESCRIPTION
 *  Entry function of sweep main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_backup_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL), MMI_EVENT_FAILURE, NULL);
        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    if (DRM_consume_table_is_in_use())
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_DRM_DB_LOCKED_BY_APP), MMI_EVENT_FAILURE, NULL);
        return;
    }

    {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.softkey[0].str = (WCHAR *)GetString(STR_GLOBAL_YES);
	arg.softkey[2].str = (WCHAR *)GetString(STR_GLOBAL_NO);
	arg.callback = (mmi_proc_func)mmi_rmgr_backup_conf_callback;
	mmi_confirm_display((WCHAR *)GetString(STR_ID_RMGR_BACKUP_AND_REBOOT), MMI_EVENT_QUERY, &arg);
    }

    /*mmi_display_popup_confirm(
            (UI_string_type)GetString(STR_GLOBAL_YES),
            (PU8)GetImage(IMG_GLOBAL_YES),
            (UI_string_type)GetString(STR_GLOBAL_NO),
            (PU8)GetImage(IMG_GLOBAL_NO),
            (UI_string_type)GetString(STR_ID_RMGR_BACKUP_AND_REBOOT),
            MMI_EVENT_QUERY);

    SetLeftSoftkeyFunction(mmi_rmgr_entry_fmgr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);*/
}

mmi_ret mmi_rmgr_backup_conf_callback(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alertEvt = (mmi_alert_result_evt_struct *)evt;
	
    if (alertEvt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alertEvt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_rmgr_entry_fmgr();
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
	  default:
	  	break;
        }
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_restore_entry_main
 * DESCRIPTION
 *  Entry function of sweep main screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_restore_entry_main(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if (srv_ucm_is_background_call())
    {
        mmi_popup_display((WCHAR*) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL), MMI_EVENT_FAILURE, NULL);

        return;
    }
#endif /* __MMI_BACKGROUND_CALL__ */

    if (DRM_consume_table_is_in_use())
    {
        mmi_popup_display((WCHAR*) GetString(STR_ID_DRM_DB_LOCKED_BY_APP), MMI_EVENT_FAILURE, NULL);
        return;
    }

    {
	mmi_confirm_property_struct arg;
	mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
	arg.softkey[0].str = (WCHAR *) GetString(STR_GLOBAL_YES);
	arg.softkey[2].str = (WCHAR *) GetString(STR_GLOBAL_NO);
	arg.callback = (mmi_proc_func)mmi_rmgr_restore_conf_callback;
	mmi_confirm_display((WCHAR *)GetString(STR_ID_RMGR_RESTORE_AND_REBOOT), MMI_EVENT_QUERY, &arg);
    }

    /*mmi_display_popup_confirm(
            (UI_string_type)GetString(STR_GLOBAL_YES),
            (PU8)GetImage(IMG_GLOBAL_YES),
            (UI_string_type)GetString(STR_GLOBAL_NO),
            (PU8)GetImage(IMG_GLOBAL_NO),
            (UI_string_type)GetString(STR_ID_RMGR_RESTORE_AND_REBOOT),
            MMI_EVENT_QUERY);

    SetLeftSoftkeyFunction(mmi_rmgr_entry_fmgr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);*/
}


mmi_ret mmi_rmgr_restore_conf_callback(mmi_event_struct *evt)
{
    mmi_alert_result_evt_struct *alertEvt = (mmi_alert_result_evt_struct *)evt;
	
    if (alertEvt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (alertEvt->result)
        {
        case MMI_ALERT_CNFM_YES:
            mmi_rmgr_entry_fmgr();
            break;
        case MMI_ALERT_CNFM_NO:
            mmi_frm_scrn_close_active_id();
            break;
	  default:
	  	break;
        }
    }
    return MMI_RET_OK;
}

#endif /* __DRM_V02__ */ 
/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_db_hint
 * DESCRIPTION
 *  Hint handler for Advance menu
 * PARAMETERS
 *  hint_idx        [IN]        Hint index
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_db_hint(U16 hint_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*
    if (rmgr_dbchk_nv)
    {
        mmi_ucs2cpy((S8*) hintData[hint_idx], GetString(STR_GLOBAL_ON));
    }
    else
    {
        mmi_ucs2cpy((S8*) hintData[hint_idx], GetString(STR_GLOBAL_OFF));
    }*/
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
    #ifdef __DRM_SUPPORT_SCAN_DISK__
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
    #endif /* __DRM_SUPPORT_SCAN_DISK__ */ 
/* under construction !*/
    #ifdef __DRM_V02__
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
    #endif /* __DRM_V02__ */
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
#ifndef __DRM_SUPPORT_SCAN_DISK__
/* under construction !*/
#endif 
/* under construction !*/
#if 0
/* under construction !*/
#ifndef __DRM_SUPPORT_SCAN_DISK__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifndef __DRM_SUPPORT_SCAN_DISK__
/* under construction !*/
#endif
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
#endif /*0*/
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
            #ifdef __DRM_SUPPORT_SCAN_DISK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __DRM_SUPPORT_SCAN_DISK__ */ 
            #ifdef __DRM_V02__
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
            #endif /* __DRM_V02__ */ 
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
#endif /*0*/
#ifdef __DRM_V02__


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_select_file
 * DESCRIPTION
 *  Callback function for file manager when shared folder selection is finished.
 * PARAMETERS
 *  path            [IN]        User selected path
 *  is_short        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_select_file_result(S32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (error < 0)
    {
        S8 str_buf[20], unicode_buf[40];

        sprintf(str_buf, "Error: -0x%8x", -error);
        mmi_asc_to_ucs2(unicode_buf, str_buf);

        mmi_popup_display((WCHAR*)unicode_buf, MMI_EVENT_FAILURE, NULL);
    }
    else
    {
        mmi_popup_display((WCHAR*) GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_select_file
 * DESCRIPTION
 *  Callback function for file manager when shared folder selection is finished.
 * PARAMETERS
 *  path            [IN]        User selected path
 *  is_short        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_select_file(void *path, int is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (path)
    {
        U16 menu_seq = GetSeqItemId_Ext(MENU_ID_RMGR, (U16) mmi_rmgr_p->rmgr_sel_idx);

        switch(menu_seq)
        {
            case MENU_ID_RMGR_DB_PROC:
            {
                U16 menu_seq2 = GetSeqItemId_Ext(MENU_ID_RMGR_DB_PROC, (U16)mmi_rmgr_p->current_idx);

            #ifdef __MMI_BACKGROUND_CALL__
                if (srv_ucm_is_background_call())
                {
                    mmi_popup_display((WCHAR*)GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL), MMI_EVENT_FAILURE, NULL);
                    break;
                }
            #endif /* __MMI_BACKGROUND_CALL__ */

                if (DRM_consume_table_is_in_use())
                {
                    mmi_popup_display((WCHAR*) GetString(STR_ID_DRM_DB_LOCKED_BY_APP), MMI_EVENT_FAILURE, NULL);
                    break;
                }

                rmgr_process_db_cntx.path = (S8*)drmt_mem_alloc(mmi_ucs2strlen((S8*)path) << 1 + 2);
                mmi_ucs2cpy(rmgr_process_db_cntx.path, (S8*)path);

                if (menu_seq2 == MENU_ID_RMGR_DB_BACKUP)
                {
                    rmgr_process_db_cntx.reboot_type = DRM_PROCESS_DATABASE_BACKUP + 1;
                   // mmi_rmgr_entry_db_progressing(STR_ID_RMGR_PROCESSING, 0xFF, MMI_FALSE, MMI_FALSE);
                        mmi_rmgr_reboot_ms(NULL);
                    }
                    else if (menu_seq2 == MENU_ID_RMGR_DB_RESTORE)
                    {
                    rmgr_process_db_cntx.reboot_type = DRM_PROCESS_DATABASE_RESTORE + 1;
                   // mmi_rmgr_entry_db_progressing(STR_ID_RMGR_PROCESSING, 0xFF, MMI_FALSE, MMI_FALSE);
                    mmi_rmgr_reboot_ms(NULL);
                }

                break;
            }
            case MENU_ID_RMGR_CERMGR:
                mmi_rmgr_select_file_result(DRM_import_certificate(path));
                break;
            default:
                ASSERT(0);
                break;
        }

    }
    else
    {
        mmi_frm_scrn_close_active_id();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_entry_fmgr
 * DESCRIPTION
 *  Entry function of certificate manager
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_entry_fmgr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FMGR_FILTER filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (DRM_consume_table_is_in_use())
    {
    mmi_popup_display((WCHAR*)GetString(STR_ID_DRM_DB_LOCKED_BY_APP), MMI_EVENT_FAILURE, NULL);
        return;
    }

    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    mmi_fmgr_select_path_and_enter(APP_RMGR, (FMGR_SELECT_FOLDER), filter, (S8*) L"root", mmi_rmgr_select_file);
}

#endif /* __DRM_V02__ */

#ifdef __MMI_RMGR_SWEEP_DB_PERIODICALLY__


/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_period_sweep_db_callback
 * DESCRIPTION
 *  the callback function when we sweep database finished.
 * PARAMETERS
 *  serial  [IN]    serial number
 *  result  [IN]    result
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_rmgr_period_sweep_db_callback(kal_uint8 serial, kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (serial != rmgr_process_db_cntx.period_sweep_db_serial)
    {
        ASSERT(0);
        return;

    }

#ifdef MMI_RMGR_SWEEP_DB_TRIGGER_BY_TIMER
    /* stop the timer check if we are in idle */
    StopTimer(RMGR_SWEEP_DB_TIMER);
#endif /* MMI_RMGR_SWEEP_DB_TRIGGER_BY_TIMER */ 

    rmgr_process_db_cntx.period_sweep_db_serial = 0;

    /* try to sweep again next time */
    if (result == DRM_RESULT_OK)
    {
        rmgr_process_db_cntx.period_sweep_db_finished = MMI_TRUE;
    }
#ifdef MMI_RMGR_SWEEP_DB_TRIGGER_BY_TIMER
    else
    {
        mmi_rmgr_period_sweep_db_timeout_hdlr();
    }
#endif
}
/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_period_sweep_db_timeout_hdlr
 * DESCRIPTION
 *  1. Check periodically if we can sweep database
 *  2. Check periodically if need to stop sweeping
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_period_sweep_db_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef MMI_RMGR_SWEEP_DB_TRIGGER_BY_TIMER
    if (rmgr_process_db_cntx.period_sweep_db_serial == 0) /* we are not sweeping now. */
    {
        if (!rmgr_process_db_cntx.period_sweep_db_finished) /* we only do one time period sweep during one bootup */
        {
            if (mmi_idle_is_active() && !DRM_consume_table_is_in_use())
            {
                DRM_process_database(
                    DRMT_PROCESS_DATABASE_SWEEP,
                    -1,
                    NULL,
                    &rmgr_process_db_cntx.period_sweep_db_serial,
                    mmi_rmgr_period_sweep_db_callback);
                StartTimer(RMGR_SWEEP_DB_TIMER, 1000, mmi_rmgr_period_sweep_db_timeout_hdlr);
            }
            else    /* if no, we check this later */
            {
                StartTimer(RMGR_SWEEP_DB_TIMER, MMI_RMGR_SWEEP_DB_PERIOD, mmi_rmgr_period_sweep_db_timeout_hdlr);
            }
        }
    }
    else
    {
        if (!mmi_idle_is_active())
        {
            DRM_async_cancel_process(rmgr_process_db_cntx.period_sweep_db_serial);
        }
    }
#endif /* MMI_RMGR_SWEEP_DB_TRIGGER_BY_TIMER */ 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_period_sweep_db
 * DESCRIPTION
 *  try to sweep database.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_period_sweep_db(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!rmgr_process_db_cntx.period_sweep_db_serial && !rmgr_process_db_cntx.period_sweep_db_finished) /* we only do one time period sweep during one bootup */
    {
        DRM_process_database(
            DRM_PROCESS_DATABASE_SWEEP,
            -1,
            NULL,
            &rmgr_process_db_cntx.period_sweep_db_serial,
            mmi_rmgr_period_sweep_db_callback);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_rmgr_period_sweep_db_cancel
 * DESCRIPTION
 *  try to cancel period sweep database.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_rmgr_period_sweep_db_cancel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (rmgr_process_db_cntx.period_sweep_db_serial)
    {
        DRM_async_cancel_process(rmgr_process_db_cntx.period_sweep_db_serial);
    }
}

#endif /* __MMI_RMGR_SWEEP_DB_PERIODICALLY__ */ 


#endif /* __MMI_RMGR__ */

