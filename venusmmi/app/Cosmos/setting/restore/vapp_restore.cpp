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
 *  vapp_restore.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_restore.h"
#include "vapp_setting_framework_gprot.h"
#include "vcui_secset_gprot.h"
#include "mmi_rp_vapp_setting_def.h"

extern "C"
{
#include "GlobalResDef.h"
#include "UcmSrvGprot.h"
#include "RestoreSrvGprot.h"
#include "ShutdownSrvGprot.h"
#include "AlarmSrvGprot.h"
#include "ProtocolEvents.h"
#include "DateTimeGprot.h"

#include "SecSetSrvGprot.h"

// For restore handler
#include "reminderSrvGprot.h"
#ifdef  __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
#include "MREAppMgrSrvGprot.h"
#endif
//FOR IME plug in
#if defined(__MMI_IME_PLUG_IN__)
#include "ImeSDKGprot.h"
#include "ImeSDKProt.h"
#endif


}

#define VAPP_RESTORE_TABLE_BEGIN
#define VAPP_RESTORE_TABLE_END 
#define VAPP_RESTORE_REG(_hdlr) extern "C" srv_restore_result_enum _hdlr(void);
#include "vapp_restore_cfg.h"
#undef VAPP_RESTORE_TABLE_BEGIN
#undef VAPP_RESTORE_TABLE_END
#undef VAPP_RESTORE_REG

#define VAPP_RESTORE_TABLE_BEGIN static srv_restore_table_struct g_vapp_restore_table[] = {
#define VAPP_RESTORE_TABLE_END  {NULL}};
#define VAPP_RESTORE_REG(_hdlr) {_hdlr},
#include "vapp_restore_cfg.h"
#undef VAPP_RESTORE_TABLE_BEGIN
#undef VAPP_RESTORE_TABLE_END
#undef VAPP_RESTORE_REG

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
void vapp_factory_restore_launch(VfxMainScr *mainScr)
{
    VappRestoreController *restoreController;
    VFX_OBJ_CREATE(restoreController, VappRestoreController, mainScr);
}

extern "C"
{
#ifndef __SLIM_AT__
// AT handler
static int g_restore_src_mod_id;
static mmi_ret vapp_restore_verify_phone_password_proc(mmi_event_struct *evt);
static void vapp_restore_at_reset_confirm(MMI_BOOL result);

void vapp_restore_at_handler(void *ind, int mod_id)
{
    //MYQUEUE Message;
    WCHAR password[16];
    
    mmi_factory_restore_req_ind_struct *msg = (mmi_factory_restore_req_ind_struct*) ind;

    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
	{	
		mmi_at_general_res_req_struct *rsp_msg;
		
		rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
		
		rsp_msg->result = (kal_bool)FALSE;
        mmi_frm_send_ilm((module_type)mod_id, MSG_ID_MMI_AT_GENERAL_RES_REQ, (local_para_struct *)rsp_msg, NULL);

		return;
	}
    g_restore_src_mod_id = mod_id;
    memset(password, 0, sizeof(WCHAR) * 16);
    mmi_asc_n_to_ucs2((CHAR*)password, (CHAR*)msg->pwd, 16);


    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[Restore] vapp_restore_at_handler()");    
    srv_secset_verify_phone_password((const WCHAR*)password, vapp_restore_verify_phone_password_proc, NULL);
}

static mmi_ret vapp_restore_verify_phone_password_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_SRV_SECSET_VERIFY_PHONE_PASSWORD_RESULT)
	{
	    srv_secset_verify_phone_password_result_evt_struct *verify_evet = (srv_secset_verify_phone_password_result_evt_struct*)evt;
        vapp_restore_at_reset_confirm(verify_evet->success);
	}
	return MMI_RET_OK;
}

static void vapp_restore_at_reset_confirm(MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_at_general_res_req_struct *rsp_msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (mmi_at_general_res_req_struct*) OslConstructDataPtr(sizeof(mmi_at_general_res_req_struct));
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "vapp_restore_at_reset_confirm(%d)", result);    
    if (result)
    {
        rsp_msg->result = (kal_bool)TRUE;
        srv_restore_start((srv_restore_table_struct*)(g_vapp_restore_table), NULL);
    }
    else
    {
        rsp_msg->result = (kal_bool)FALSE;
    }
    mmi_frm_send_ilm((module_type)g_restore_src_mod_id, MSG_ID_MMI_AT_GENERAL_RES_REQ, (local_para_struct *)rsp_msg, NULL);
}

mmi_ret vapp_factory_restore_init(mmi_event_struct *evt)
{
    SetProtocolEventHandler(vapp_restore_at_handler, PRT_MMI_FACTORY_RESTORE_REQ_IND);
    return MMI_RET_OK;
}
// END of AT handler
#endif  /*__SLIM_AT__*/

#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA"

srv_restore_result_enum vapp_factory_restore_reset_alarm(void)
{
    srv_reminder_deinit();
    //srv_reminder_clear(SRV_REMINDER_TYPE_TOTAL);
    return SRV_RESTORE_OK;
}

void vapp_reset_system_time_rsp(MMI_BOOL result, void *msg)
{
    extern mmi_ret srv_reminder_on_time_change_notify(mmi_event_struct *evt);
    srv_reminder_on_time_change_notify(NULL);
    srv_restore_process_callback();
}

srv_restore_result_enum vapp_rest_system_time(void)
{
    MYTIME time;
    time.nYear = 2004;
    time.nMonth = 1;
    time.nDay = 1;
    time.nHour = 0;
    time.nMin = 0;
    time.nSec = 0;
	
    mmi_dt_set_dt(&time, vapp_reset_system_time_rsp, NULL);
    return SRV_RESTORE_HOLD;
}

srv_restore_result_enum vapp_factory_restore_reset_nvram(void)
{
    mmi_frm_reset_record(NVRAM_RESET_FACTORY, (U16)VAPP_SETTING, 0, 0, 0);
	return SRV_RESTORE_OK;
}

srv_restore_result_enum vapp_factory_restore_reboot(void)
{
    srv_alm_pwr_reset(MMI_FALSE, 3);
    return SRV_RESTORE_OK;
}

#if !defined(MMI_ON_WIN32) && defined(__J2ME__)
void vapp_factory_restore_reset_java_data_cb(void)
{
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_RESTORE_JAVA_SETTING_CNF, NULL, NULL);    
}

void vapp_factory_restore_reset_java_hdlr(void *msg)
{
    ClearProtocolEventHandler(MSG_ID_MMI_RESTORE_JAVA_SETTING_CNF);
    srv_restore_process_callback();
}
extern void mmi_java_send_restore_factory_mode_req(FuncPtr javaCBHandler);
srv_restore_result_enum vapp_factory_restore_reset_java_data(void)
{
    SetProtocolEventHandler(vapp_factory_restore_reset_java_hdlr, MSG_ID_MMI_RESTORE_JAVA_SETTING_CNF);
	mmi_java_send_restore_factory_mode_req(vapp_factory_restore_reset_java_data_cb);
    return SRV_RESTORE_HOLD;
}
#endif /* #if !defined(MMI_ON_WIN32) && defined(__J2ME__) */

#ifdef OPERA_BROWSER
void vapp_factory_restore_reset_browser_hdlr(void *msg)
{
    ClearProtocolEventHandler(MSG_ID_MMI_FULL_HTML_BROWSER_RESTORE_FACTORY_SETTING_CNF);
    srv_restore_process_callback();
}

srv_restore_result_enum vapp_factory_restore_reset_browser(void)
{
    SetProtocolEventHandler(vapp_factory_restore_reset_browser_hdlr, MSG_ID_MMI_FULL_HTML_BROWSER_RESTORE_FACTORY_SETTING_CNF);
    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_FULL_HTML_BROWSER_RESTORE_FACTORY_SETTING_REQ, NULL, NULL);
    return SRV_RESTORE_HOLD;    
}
#endif /* OPERA_BROWSER */

srv_restore_result_enum vapp_factory_restore_end_call(void)
{
    /* End all call */
    srv_ucm_act_request(SRV_UCM_END_ALL_ACT, NULL, NULL, NULL);
    srv_ucm_act_request(SRV_UCM_END_ALL_PROCESSING_ACT, NULL, NULL, NULL);
    return SRV_RESTORE_OK;
}
#ifdef  __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
srv_restore_result_enum vapp_factory_restore_mre(void)
{
	srv_mre_appmgr_preinstall_tcard_app_uninstall();
	return SRV_RESTORE_OK;
}
#endif

#if defined(__MMI_IME_PLUG_IN__)
srv_restore_result_enum vapp_factory_restore_rest_ime(void)
{
    /* inform vendor to rest ime to factory setting*/
    mmi_ime_sdk_send_sdk_msg(MMI_IME_SDK_MSG_RESTOR_FACTRORY_SETTING, 0, 0);
    return SRV_RESTORE_OK;
}
#endif


}
/***************************************************************************** 
 * Class 
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappRestoreController", VappRestoreController, VfxObject);
void VappRestoreController::onInit()
{
    VappSettingFWMgr *manager = VFX_OBJ_GET_INSTANCE(VappSettingFWMgr);
    m_cuiId = vcui_verify_create(manager->getAppId(), VCUI_VERIFY_TYPE_PHONE_PASSWORD);
    mmi_frm_group_set_caller_proc(m_cuiId, &VappRestoreController::verifyCuiProc, this);
    vcui_verify_run(m_cuiId);
}

void VappRestoreController::onDeinit()
{
    vcui_verify_close(m_cuiId);
}

mmi_ret VappRestoreController::verifyCuiProc(mmi_event_struct *evt)
{
    VfxObject *obj = (VfxObject*)evt->user_data;
    VappRestoreController *restoreController = VFX_OBJ_DYNAMIC_CAST(obj, VappRestoreController);
    if (!restoreController)
	{
	    return MMI_RET_ERR;
	}
    switch (evt->evt_id)
	{
	case EVT_ID_VCUI_VERIFY_RESULT:
    {
        vcui_verify_result_evt_struct *result_evt = (vcui_verify_result_evt_struct*)evt;
        if (result_evt->success)
    	{
            restoreController->showConfrimPopup();            
    	}
        else
        {
            restoreController->close();
        }		
		break;
    }
	default:
        restoreController->close();
        break;		
	}
    
    return MMI_RET_OK;
}

void VappRestoreController::showConfrimPopup()
{
    VcpConfirmPopup *popup;
    VfxAppScr *screen = ((VfxApp*)VfxApp::getObject(m_cuiId))->getTopScreen();
    VFX_OBJ_CREATE(popup, VcpConfirmPopup, screen);
    popup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    popup->setCustomButton(
        STR_ID_VAPP_SETTING_RESTORE, 
        STR_GLOBAL_CANCEL, 
        VCP_POPUP_BUTTON_TYPE_WARNING, 
        VCP_POPUP_BUTTON_TYPE_CANCEL);
    popup->setText(STR_ID_VAPP_SETTING_RESTORE_CONFIRM);
    popup->setTextAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    popup->setInfoType(VCP_POPUP_TYPE_WARNING);
    popup->m_signalButtonClicked.connect(this, &VappRestoreController::onConfirmPopupTapped);
    popup->show(VFX_TRUE);
}

void VappRestoreController::close()
{
    VfxObject* self = this;
    VFX_OBJ_CLOSE(self);
}

void VappRestoreController::onConfirmPopupTapped(VfxObject *sender, VfxId id)
{
    switch (id)
	{
	case 'USR1':
    {
        VappRestoreProcessingPopup *popup;
        VfxAppScr *screen = ((VfxApp*)VfxApp::getObject(m_cuiId))->getTopScreen();
        VFX_OBJ_CREATE(popup, VappRestoreProcessingPopup, screen);
        popup->setText(STR_GLOBAL_PLEASE_WAIT);
        popup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
		popup->show(VFX_TRUE);
        srv_restore_start((srv_restore_table_struct*)(g_vapp_restore_table), NULL);
    }
		break;
    case 'USR2':
        vcui_verify_close(m_cuiId); 
        close();
        break;
	default:
		break;
	}      
}
#pragma arm section code, rodata

 
