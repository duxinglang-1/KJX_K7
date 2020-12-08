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
 *  vapp_uc_core.cpp
 *
 * Project:
 * --------
 *  Venus Golden Sample : UC
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

 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
#include "vapp_msg_features.h"

#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
#include "vfx_uc_include.h"
#include "vcp_form.h"
#include "vcp_tabctrl_page.h"
#include "vcp_navi_title_bar.h"
//#include "mmi_rp_vtst_sample_def.h"

#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_popup.h"
#include "vcp_form.h"
#include "vcp_button_util.h"
#include "mmi_features_camcorder.h"
#if defined(__LOW_COST_SUPPORT_COMMON__)
#include "vapp_camco_express_gprot.h"
#else
#include "vapp_camco_gprot.h"
#endif  
#include "..\Email\vapp_email_composer.h"
#include "vapp_usb_gprot.h"
//#include "mmi_rp_vtst_sample_def.h"
#include "mmi_rp_vapp_unifiedcomposer_def.h"
//#include "mmi_rp_app_vapp_sms_def.h"
#include "vapp_sim_setting_gprot.h"

extern "C"
{
    #include "app_asyncfile.h"
	#include "wapadp.h"
    #include "PhoneBookGprot.h"
	#include "UmSrvGprot.h"
	#include "MmsSrvGprot.h"
    #include "SmsSrvGprot.h"
    #include "app_str.h"
    #include "Custom_uc_config.h"
	#include "UcSrvGprot.h"
    #include "UcSrvIprot.h"
	#include "FileMgr.h"
	#include "FileMgrCUIGProt.h"
    #include "MMSAppCommonGProt.h"
    #include "SimCtrlSrvGprot.h"
    #include "ModeSwitchSrvGprot.h"
    #include "BootupSrvGprot.h"
    #include "USBSrvGProt.h"
	#include "vcui_bookmark_gprot.h"
	#include "conversions.h"
	#include "app_mine.h"
    #include "customer_email_num.h"
	#include "CustMenuRes.h"
	#include "med_api.h"
#if (MMI_MAX_SIM_NUM >= 2)
    #include "GeneralSettingSrvGprot.h"
#endif
    #include "ModeSwitchSrvGProt.h"

extern U16 *srv_uc_get_file_name(U16 *filePath);
extern kal_uint32 mma_get_mmi_file_size(kal_int32 file_handle, const kal_wchar *filepath);
}

#include "vapp_uc_gprot.h"
#include "vapp_uc_prot.h"

VappUcContainerStruct g_app = {0};
#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
VappUcAppDataAfterSerialize g_uc_app_data_serialized[MAX_UC_INSTANCES] = {0}; 
#endif



U8 initial_launch_mode = UC_LAUNCH_MODE_NONE ;
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
VappUcEndKeyHandleStruct EndKeyHandle[MAX_UC_INSTANCES] = {0};
#endif
//#ifdef __AFX_RT_TEST__

/*****************************************************************************
 * Menu Test Implementation
 *****************************************************************************/
/***************************************************************************** 
 * Class VtstSampleAddContactHeaderItem
 *****************************************************************************/
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
extern "C" VfxBool VappUCsmsReadyCheck(void)
{
    MMI_BOOL is_sms_ready;

    is_sms_ready = srv_sms_is_sms_ready();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_IS_SMS_READY_P1, is_sms_ready);
    return (is_sms_ready ? VFX_TRUE : VFX_FALSE);
}
#endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 

#ifdef __MMI_MMS__
extern "C" VfxBool VappUCmmsReadyCheck(void)
{
    S32 is_mms_ready;
    is_mms_ready = mms_is_ready();
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_IS_MMS_READY_P1, is_mms_ready);
    return (is_mms_ready ? VFX_TRUE : VFX_FALSE);
}
#endif

extern "C" VfxBool VappUCisReady(void)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_IS_UC_READY);
    if (srv_um_check_ready()
#ifdef __MMI_MMS__
        && VappUCmmsReadyCheck()
#endif 
#ifndef __MMI_MMS_STANDALONE_COMPOSER__
        && VappUCsmsReadyCheck()
#endif 
        )
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_IS_UC_READY_P1, 1);
        return VFX_TRUE;
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_IS_UC_READY_P1, 0);
        return VFX_FALSE;
    }
}

extern "C" mmi_id ucGetAppBaseId(VappUcEntryStruct *data, mmi_id group_id) 
{
    mmi_id appBaseId = 0;

    if(group_id >= VAPP_UNIFIEDCOMPOSER && group_id <= mmi_res_get_app_max(VAPP_UNIFIEDCOMPOSER) )
        return VAPP_UNIFIEDCOMPOSER;
       
     
#ifdef __MMI_EMAIL__
    if (data && data->edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
        appBaseId = VCUI_EMAILCOMPOSER;
    }
    else
#endif
#ifdef __MMI_MMS_2__
    if (data && data->edit_mode == SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
    {
        appBaseId = VCUI_LEMEICOMPOSER;
    }
    else
    {
		if(data && data->msg_type == SRV_UC_MSG_TYPE_SMS_ONLY)
		{
	        appBaseId = VCUI_SMSONLYCOMPOSER;
		}
		else
		{
	        appBaseId = VCUI_MSGCOMPOSER;
		}
    }
#else
        if(data && (data->msg_type == SRV_UC_MSG_TYPE_SMS_ONLY || data->msg_type == SRV_UC_MSG_TYPE_SMS_PREFER
            || data->msg_type == SRV_UC_MSG_TYPE_DEFAULT))
		{
            data->msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;
	        appBaseId = VCUI_SMSONLYCOMPOSER;
		}
		else if(!data)
		{
		    appBaseId = VCUI_SMSONLYCOMPOSER;
		}
        else
        {
            //mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)).getBuf());
            //return GRP_ID_INVALID;        
        }
#endif
    return appBaseId;
}

extern "C" BOOL vappUcCuiCreatePreCheck(VappUcEntryStruct *data, BOOL showErrorMsg)
{
    mmi_id appBaseId = 0;

    appBaseId = ucGetAppBaseId(data, VCUI_MSGCOMPOSER);
    
    if( appBaseId == 0 )
    {
        if(showErrorMsg)
        {
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)).getBuf());
        }
        return MMI_FALSE;        
    }

    if(VfxAppLauncher::findApp(appBaseId, VFX_OBJ_CLASS_INFO(VcuiUcMainCui), 
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG))
    {
        if(showErrorMsg)
        {
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)).getBuf());
        }
        return MMI_FALSE;
    }

#ifdef __MMI_EMAIL__
    if (data && data->edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
        //skip.
    }
    else
#endif
    {
        if(!VappUCisReady())
        {
            //vappUcTerminate();
            if(showErrorMsg)
            {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)).getBuf());
            }
            return MMI_FALSE;
        }
    }

#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR *) SRV_UC_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
    #if defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
            if(showErrorMsg)
            {
                vapp_usb_unavailable_popup(0);   /* pass 0 will show default string */
            }
    #endif
            //vappUcTerminate();
            //mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)).getBuf());
            return MMI_FALSE;
        }
    }
#endif /* __MMI_USB_SUPPORT__ */

    return MMI_TRUE; 

}

extern "C" mmi_ret vapp_unifiedcomposer_init(mmi_event_struct *evt)
{
	srv_uc_check_uc_folder(0);
    return MMI_RET_OK;
}

extern "C" mmi_id vcui_unifiedcomposer_create(mmi_id parent_id, VappUcEntryStruct *data)
{
    mmi_id appBaseId = 0;
    mmi_id cui_id = 0;
    if( vappUcCuiCreatePreCheck(data, MMI_TRUE) == MMI_FALSE)
        return GRP_ID_INVALID;

    appBaseId = ucGetAppBaseId(data, VCUI_MSGCOMPOSER);

    vappUcCopyInitData(data);


    VfxAppLauncherParam param(appBaseId, VFX_OBJ_CLASS_INFO(VcuiUcMainCui), parent_id );
    param.setArgument((void*)g_app.initData, (g_app.initData)?sizeof(VappUcEntryStruct):0);
    param.setHeapOffset( VAPP_UC_SERIALIZE_ASM_MEM_SIZE );
    cui_id = VfxAppLauncher::createCuiEx (param);

    if(cui_id != GRP_ID_INVALID)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_CREATE_CUI_OK);
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_CREATE_CUI_INVALID);
    }
    return cui_id;
}

extern "C" void vcui_unifiedcomposer_run(mmi_id cui_id)
{
	VfxAppLauncher::runCui(cui_id);
}

extern "C" void vcui_unifiedcomposer_close(mmi_id cui_id)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_CLOSE);
	VfxAppLauncher::terminate(cui_id);
}

extern "C" BOOL vappUcAppLauncherPreCheck(VappUcEntryStruct *data, BOOL showErrorMsg)
{
    VfxApp *app = NULL;
    app = VfxAppLauncher::findApp(
            VAPP_UNIFIEDCOMPOSER, 
            VFX_OBJ_CLASS_INFO(VcuiUcMainCui), 
            VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG | VFX_APP_LAUNACHER_FIND_APP_BG_FLAG);

    if(app)
    {
        if(showErrorMsg)
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)).getBuf());
        return MMI_FALSE;
    }


#ifdef __MMI_EMAIL__
    if (data && data->edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
        //skip.
    }
    else
#endif
    {
        if(!VappUCisReady())
        {
            if(showErrorMsg)
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)).getBuf());
            return MMI_FALSE;
        }
    }

#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        /* in mass storage mode */
        if (srv_usb_check_path_exported((WCHAR *) SRV_UC_FOLDER_DRV))
        {
            /* MMI public drive is exported, cannot use this app */
        #if defined(__MMI_USB_SUPPORT__) && defined(__COSMOS_MMI_PACKAGE__)
            if(showErrorMsg)
                vapp_usb_unavailable_popup(0);   /* pass 0 will show default string */
        #endif
            //vappUcTerminate();
            //mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE)).getBuf());
            return MMI_FALSE;
        }
    }
#endif /* __MMI_USB_SUPPORT__ */

    return MMI_TRUE;
}

extern "C" BOOL vappUcAppLauncher(VappUcEntryStruct *data)
{
    if( vappUcAppLauncherPreCheck(data, MMI_TRUE) == MMI_FALSE)
        return MMI_FALSE;
    
    vappUcCopyInitData(data);

    g_app.temp_flag = VFX_TRUE;

    VfxAppLauncherParam param(VAPP_UNIFIEDCOMPOSER, VFX_OBJ_CLASS_INFO(VcuiUcMainCui), GRP_ID_ROOT );
    param.setArgument((void*)g_app.initData, (g_app.initData)?sizeof(VappUcEntryStruct):0);
    param.setHeapOffset( VAPP_UC_SERIALIZE_ASM_MEM_SIZE );
    VfxAppLauncher::launchEx(param);

    return  MMI_TRUE;
}

extern "C" void ucGetStringFromInt(S32 number, U16* text_buffer)
{
    S8 tempStr[50] = {0,};
    S32 temp_string_len = 50;
    sprintf(tempStr, "%d", number);
    mmi_asc_n_to_ucs2((S8*) text_buffer, (S8*) tempStr, temp_string_len - 1);
    return;
}
extern "C" void ucGetSizeStringFromByteCount(S32 number, U16* text_buffer)
{
    FLOAT size = 0;
    S8 tempStr[50] = {0,};
    S32 temp_string_len = 50;
    size = (FLOAT) number / (FLOAT) 1024.0;
    sprintf(tempStr, "%.1f", size);

    mmi_asc_n_to_ucs2((S8*) text_buffer, (S8*) tempStr, temp_string_len - 1);
    mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VAPP_UC_KB_ID));
    return;
}

extern "C" void* ucSrvAllocMemCbk(kal_uint32 len, void *user_data)
{
    return (void*)kal_adm_alloc((KAL_ADM_ID)user_data, len);
}

extern "C" void ucSrvFreeMemCbk(void *ptr, void *user_data)
{
    kal_adm_free((KAL_ADM_ID)user_data, ptr);
}

extern "C" U8 getMaxMoSmsSegment(void)
{
#ifdef __EMS_DYNAMIC_SEG_NUM__
	if (srv_sms_is_long_sms_dynamic_seg_setting(SRV_SMS_SIM_1) == MMI_TRUE)
    {
        return mmi_uc_custom_get_max_mo_sms_segment();
    }
    else
    {
        return (kal_uint8) 1;   /* 1 can be change with any macro value. */
    }
#else /* __EMS_DYNAMIC_SEG_NUM__ */ 
    return mmi_uc_custom_get_max_mo_sms_segment();
#endif /* __EMS_DYNAMIC_SEG_NUM__ */ 
}

extern "C" void uc_phb_async_set_preff_sim_after_send(srv_phb_async_op_cb_struct *AsyncPhbInfo)
{
	VappUcAppData *appData = (VappUcAppData *)AsyncPhbInfo->user_data;
	/*Need to Check App exist or Not*/
	if(!vappUcCheckAppSanity((void *)appData))
	{
		return;
	}

	if(appData->CurrAsyncPhbAddr->next != NULL)
	{
		appData->CurrAsyncPhbAddr = appData->CurrAsyncPhbAddr->next ;
		appData->ucHandleDataAfterSend();
		if(appData->CurrAsyncPhbAddr == NULL)
		{
			/*All Recipients Parsing is done Now need to close UC*/
			appData->ucActionFsm(SRV_UC_ACTION_SEND, appData->send_info->send_result);
		}
	}
	else
	{
		/*All Recipients Parsing is done Now need to close UC*/
		appData->ucActionFsm(SRV_UC_ACTION_SEND, appData->send_info->send_result);
	}

}



/*phb_async_code*/
void VappUcAppData::ucHandleDataAfterSend(void)
{
	U32 size = 0 ;
	S32 needWaitToCloseProgress = 0;
	U16 *UCS2PhbAddr = NULL ;
	srv_phb_set_preferred_sim_req* ucPhbData = NULL ; /*kuldeep_async_phb*/
	ucPhbData = (srv_phb_set_preferred_sim_req *)kal_adm_alloc(main->mem_pool_id, sizeof(srv_phb_set_preferred_sim_req));
	ASSERT(ucPhbData);
	memset(ucPhbData, 0x0 ,sizeof(srv_phb_set_preferred_sim_req));
	/*Need to get the first Phone number in the address list*/
	if(CurrAsyncPhbAddr == NULL)
	{
		CurrAsyncPhbAddr = m_service_cntxt->msg->to_head;
	}
	while(CurrAsyncPhbAddr)
	{
		if(CurrAsyncPhbAddr->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
		{
			size = ((mmi_chset_utf8_strlen(CurrAsyncPhbAddr->addr))+1)*ENCODING_LENGTH;
			UCS2PhbAddr = (U16*)OslMalloc(size);
			memset(UCS2PhbAddr, 0x0 ,size);
			mmi_chset_utf8_to_ucs2_string((kal_uint8 *)UCS2PhbAddr,(kal_int32)size,(kal_uint8 *)CurrAsyncPhbAddr->addr);

			/*Set the async data for first Phone number*/
			ucPhbData->number = UCS2PhbAddr ;
			ucPhbData->id = MMI_PHB_INVALID_CONTACT_ID ;
			ucPhbData->sim_id = vappUcConvertUCSimIdToMmi(m_service_cntxt->send_info->send_sim_id) ;
			ucPhbData->op_type = SRV_PHB_NUMBER_OP_TYPE_MESSAGE ;
			ucPhbData->cb = uc_phb_async_set_preff_sim_after_send;
			ucPhbData->user_data = (void *)this ;

			needWaitToCloseProgress = srv_phb_set_preferred_sim_ex(ucPhbData);
			WaitAsyncPhbRspToCloseUC = TRUE ;
			OslMfree(UCS2PhbAddr);
			if(needWaitToCloseProgress != SRV_PHB_NOT_FOUND)
			break ;
		}
		CurrAsyncPhbAddr = CurrAsyncPhbAddr->next ;
	}
	kal_adm_free(main->mem_pool_id ,ucPhbData);
	/*Need to keep Track whether we need to wait for PHB rsp to close UC or just close UC directly
	Case : All recipients are Email addresses*/

	if(WaitAsyncPhbRspToCloseUC == FALSE || (needWaitToCloseProgress != SRV_PHB_NO_ERROR))
	{
		ucActionFsm(SRV_UC_ACTION_SEND, send_info->send_result);
	}
}

extern "C" void ucSendSmsRsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = callback_data->result;
    VfxU32 cause = (VfxU32)callback_data->cause;
    VappUcAppData *appData = (VappUcAppData *)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_SAVE_STORAGE_STATUS, &VappUcAppData::onSmsSaveStorageStatusEvtCb, appData->getObjHandle());
#endif

	if(!vappUcCheckAppSanity((void *)appData))
	{
		return;
	}

    /* When background sending is enabled, rsp ok just means first step(save) ok */
    if (result == MMI_TRUE)
    {
        cause = SRV_SMS_CAUSE_NO_ERROR;
    }
#ifndef __SRV_SMS_MULTI_ADDR__ // support sms send group address    
    if (cause != SRV_SMS_CAUSE_SEND_ABORT)
    {
        appData->m_service_cntxt->send_info->curr_send_number++;
        if (appData->m_service_cntxt->send_info->curr_send_number < appData->m_service_cntxt->msg->to_num)
        {
            appData->ucSendSmsReq();
            return;
        }
    }

    if (result != MMI_TRUE && cause != SRV_SMS_CAUSE_SEND_ABORT)
	{
		appData->m_service_cntxt->send_info->curr_send_number--;
	}
#else
//need to do nothing.
#endif
    appData->send_info->send_result = cause;
    //appData->ucActionFsm(SRV_UC_ACTION_SEND, cause);/*kuldeep_async_phb*/
	appData->ucHandleDataAfterSend();
    return;
}

extern "C" void vappUcRefresh(VcuiUcMainCui *app)
{
    app->m_scr->connectOnPage();
}

void VappUcAppData::vappUcResetAppData(void)
{
    U32 i = 0;
    while(i < MAX_UC_INSTANCES)
    {
        if(g_app.app_data[i] == this)
        {
            g_app.app_data[i] = NULL;
            return;
        }
        i++;
    }
}

void vappUcResetAppDataByInstance(U32 instance)
{
     g_app.app_data[instance] = NULL;
}

void VappUcAppData::vappUcSetAppData(void)
{
    U32 i = 0;
    while(i < MAX_UC_INSTANCES)
    {
        if(g_app.app_data[i] == NULL)
        {
            g_app.app_data[i] = this;
            
            return;
        }
        i++;
    }
}

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__

void VappUcAppData::vappUcSetSerialize(U32 instance, mmi_id group_id )
{
    MMI_ASSERT(instance < MAX_UC_INSTANCES) ;
    
    if( g_app.is_serialize[instance] == VFX_FALSE)
    {
        g_app.group_id[instance] = group_id;
        g_app.is_serialize[instance] = VFX_TRUE;
    }
}

VfxBool VappUcAppData::vappUcGetIsSerialize()
{
    U32 i = 0;
    while(i < MAX_UC_INSTANCES)
    {
        if(g_app.app_data[i] == this)
        {          
            if(g_app.is_serialize[i] == VFX_TRUE)
                return VFX_TRUE;
            else
                return VFX_FALSE; 
        }
        i++;
    }
    
    MMI_ASSERT(0);
    return VFX_FALSE;
}

void vappUcResetSerialize(U32 instance)
{
    MMI_ASSERT(instance < MAX_UC_INSTANCES) ;
    
    g_app.group_id[instance] = GRP_ID_INVALID;
    g_app.is_serialize[instance] = VFX_FALSE;
}
#endif  /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */


U16 VappUcAppData::preCheckSendMessage()
{
	if (m_service_cntxt->msg->to_num == 0)
	{
		return STR_ID_VAPP_UC_PLS_ADD_RECIPIENT_ID;
	}
	if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
    {
        if (MMI_FALSE == srv_uc_check_number_length_for_sms_in_send_case(main->instance))
        {
            return STR_ID_VAPP_UC_NUMBER_LENGTH_EXCEED_ID;
        }
    }
    else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
    {
#ifdef __MMI_MMS_2__
        {
            if (m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
            {
                if (m_service_cntxt->msg->msg_size > mms_get_max_msg_size_in_restricted_mode())
                {
                    return STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID;
                }
            }
    #ifdef __MMI_EMAIL__
            if (m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
    #endif
            /* required as edit allowed on big MMS also. */
            if (m_service_cntxt->mms_info->max_mms_size < m_service_cntxt->msg->msg_size)
            {
                return STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID;
            }
        }
#endif
    }
	return 0;
}
void VappUcAppData::sendMessage()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: See about this
    mmi_uc_set_group_id(); */
    {
        /* TODO: Code to remove duplicate recipients
        srv_uc_addr_struct *addr = NULL;

        addr = srv_uc_copy_address(main->instance, mmi_uc_get_highlighted_addr());
        srv_uc_remove_duplicate_entries(main->instance);
        done->current_addr_index = srv_uc_get_highlighted_index(main->instance, addr)
            + MMI_UC_ADD_RECIPIENT_TOTAL - mmi_uc_get_number_of_options_omitted();
        srv_uc_free_addr_memory(main->instance, addr);
        addr = NULL;
        srv_uc_update_msg_size(main->instance); */
    }
	/*kuldeep_gplus*/
	VfxS16 error;
	U8 set_sim_id = (U8)m_service_cntxt->send_info->send_sim_id ;
	WriteValue(NVRAM_UC_APP_PREFER_SIM, &set_sim_id, DS_BYTE, &error);
	
	srv_uc_remove_duplicate_entries(main->instance);
    if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
    {
        m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
    }
	srv_uc_update_msg_size(main->instance);
   
	if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
    {
        if (m_service_cntxt->msg->to_num == 0)
        {
            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_PLS_ADD_RECIPIENT_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
            m_signalConnectToCloseProgress.postEmit();
            return;
        }
        else if (MMI_FALSE == srv_uc_check_number_length_for_sms_in_send_case(main->instance))
        {
            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_NUMBER_LENGTH_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
            m_signalConnectToCloseProgress.postEmit();
            return;
        }
        else
        {
        #ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            MMI_BOOL is_send_save = MMI_FALSE;

        #if (MMI_MAX_SIM_NUM >= 2)
            if (m_service_cntxt->send_info->send_sim_id != SRV_UC_SIM_ID_GSM_SIM1)
            {
                is_send_save = srv_sms_is_save_sent_sms_setting(vappUcConvertUCSimIdToSMS(m_service_cntxt->send_info->send_sim_id));
            }
            else
        #endif /* MMI_MAX_SIM_NUM */ 
            {
                is_send_save = srv_sms_is_save_sent_sms_setting(SRV_SMS_SIM_1);
            }
            if (is_send_save == MMI_TRUE)
            {
                m_service_cntxt->send_info->action = SRV_UC_ACTION_SEND_AND_SAVE;
            }
            else
        #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
            {
                m_service_cntxt->send_info->action = SRV_UC_ACTION_SEND;
            }
            m_service_cntxt->send_info->curr_send_number = 0;
            ucPreSendSmsReq();
        }
    }
    #ifdef __MMI_EMAIL__
    else if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
       {
			if (m_service_cntxt->msg->to_num == 0)
			{
				m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_PLS_ADD_RECIPIENT_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
				m_signalConnectToCloseProgress.postEmit();
				return;
			}
			else
			{
			   ucSendEmailReq();
			}
       }
    #endif
#ifdef __MMI_MMS_2__
    else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
    {
        if (m_service_cntxt->msg->to_num == 0)
        {
            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_PLS_ADD_RECIPIENT_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
            m_signalConnectToCloseProgress.postEmit();
            return;
        }
        else
        {
            if (m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
            {
                if (m_service_cntxt->msg->msg_size > mms_get_max_msg_size_in_restricted_mode())
                {
                    vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                    m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
                    m_signalConnectToCloseProgress.postEmit();
                    return;
                }
            }
            /* required as edit allowed on big MMS also. */
            if (m_service_cntxt->mms_info->max_mms_size < m_service_cntxt->msg->msg_size)
            {
                vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
                m_signalConnectToCloseProgress.postEmit();
                return;
            }
            m_service_cntxt->send_info->action = SRV_UC_ACTION_SEND_IN_BACKGROUND;
            ucCreateMmsHandler(SRV_MMS_CREATE_SEND_MMS);
        }
    }
#endif
    else
    {
        ASSERT(0);
    }
}

#ifdef __MMI_EMAIL__
BOOL VappUcAppData::ucSendEmailReq(void)
{
    VappUcEntryStruct data;
    VfxBool result;

    data.addr_num = (U8)m_service_cntxt->msg->to_num;
    data.addr = NULL;
    data.file_path = NULL;
    data.text_buffer = m_service_cntxt->main->text_buffer;
    data.text_num = m_service_cntxt->msg->msg_body.curr_slide->txt.char_count;
    data.subject = (U8*)m_service_cntxt->msg->subject;
    data.info_type = SRV_UC_INFO_TYPE_EMAIL;
    data.callback = NULL;
    data.callback_para = NULL;
    data.msg_id = m_service_cntxt->send_info->existed_msg_id; // just to refer
#if (MMI_MAX_SIM_NUM >= 2)
    data.sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
#endif /* MMI_MAX_SIM_NUM */
    data.get_address_callback = (vmsgc_get_addr_func_ptr)vapp_uc_get_address_callback;
    data.media_num = m_service_cntxt->msg->msg_body.total_attach_no;
    data.get_media_callback = (vmsgc_get_media_func_ptr) vapp_uc_get_media_callback;

    result = VappEmailComp::send(main->callback_para, &data, this);

    if (result)
    {
        m_signalConnectOnError.postEmit();
    }
    else
    {
        m_signalConnectToCloseProgress.postEmit();
    }
    
    return TRUE;
}

BOOL VappUcAppData::ucSaveEmailReq(void)
{
    VappUcEntryStruct data;
    VfxBool result;

    data.addr_num = (U8)m_service_cntxt->msg->to_num;
    data.addr = NULL;
    data.file_path = NULL;
    data.text_buffer = m_service_cntxt->main->text_buffer;
    data.text_num = m_service_cntxt->msg->msg_body.curr_slide->txt.char_count;
    data.subject = (U8*)m_service_cntxt->msg->subject;
    data.info_type = SRV_UC_INFO_TYPE_EMAIL;
    data.callback = NULL;
    data.callback_para = NULL;
    data.msg_id = m_service_cntxt->send_info->existed_msg_id;
#if (MMI_MAX_SIM_NUM >= 2)
    data.sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
#endif /* MMI_MAX_SIM_NUM */
    data.get_address_callback = (vmsgc_get_addr_func_ptr)vapp_uc_get_address_callback;
    data.media_num = m_service_cntxt->msg->msg_body.total_attach_no;
    data.get_media_callback = (vmsgc_get_media_func_ptr) vapp_uc_get_media_callback;

    result = VappEmailComp::save(main->callback_para, &data, this);

    if (result)
    {
        m_signalConnectOnError.postEmit();
    }
    else
    {
        m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
        m_signalConnectToCloseProgress.postEmit();
    }

    return TRUE;
}
#endif

void VappUcAppData::ucPreSendSmsReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    srv_sms_setting_struct default_setting;
//    S8 *sc_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//#ifndef GUI_EDITOR_SHOW_TITLE
    ucSendSmsReq();
#if 0
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MMI_MAX_SIM_NUM */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* GUI_EDITOR_SHOW_TITLE */
}

void VappUcAppData::ucSendSmsReq()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE send_handle;
    U8 ucs2_addr[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
    U16 addr_len;
#if defined (__MMI_VCALENDAR__) || defined (__MMI_VCARD__)    
	U16 dest_port = 0;
#endif
    U16 i;
    srv_uc_addr_struct *addr;
	VcuiUcMainCui *app = (VcuiUcMainCui *)m_parent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_handle = srv_sms_get_send_handle();

#if 0
    #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* MMI_MAX_SIM_NUM */
#endif
    srv_sms_set_sim_id(send_handle, vappUcConvertUCSimIdToSMS(m_service_cntxt->send_info->send_sim_id));

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_set_send_type(send_handle, SRV_SMS_BG_SAVE_SEND);
#else
    srv_sms_set_send_type(send_handle, SRV_SMS_FG_SEND);
#endif   

    addr = m_service_cntxt->msg->to_head;
    for (i = 0; i < m_service_cntxt->send_info->curr_send_number; i++)
    {
        addr = addr->next;
    }
    addr_len = mmi_asc_n_to_ucs2((S8*)ucs2_addr, (S8*)addr->addr, SRV_SMS_MAX_ADDR_LEN);
    ucs2_addr[addr_len] = '\0';
    ucs2_addr[addr_len + 1] = '\0';
    srv_sms_set_address(send_handle, (S8*)ucs2_addr);
    //srv_phb_set_preferred_sim( (U16 *)ucs2_addr,
    //    MMI_PHB_INVALID_CONTACT_ID,
    //    vappUcConvertUCSimIdToMmi(m_service_cntxt->send_info->send_sim_id),
    //    SRV_PHB_NUMBER_OP_TYPE_MESSAGE);  /*kuldeep_async_phb*/
#ifdef __SRV_SMS_MULTI_ADDR__ // support sms send group address
	m_service_cntxt->send_info->curr_send_number++;
    addr = m_service_cntxt->msg->to_head;
	addr = addr->next;
	for (;m_service_cntxt->send_info->curr_send_number < m_service_cntxt->msg->to_num; m_service_cntxt->send_info->curr_send_number++)
    {
		WCHAR append_ucs2_addr[SRV_SMS_MAX_ADDR_LEN+1] = {0,};

		addr_len = mmi_asc_n_to_ucs2((S8*)append_ucs2_addr, (S8*)addr->addr, SRV_SMS_MAX_ADDR_LEN);
		append_ucs2_addr[addr_len] = '\0';
		append_ucs2_addr[addr_len + 1] = '\0';
		srv_sms_append_address(send_handle, append_ucs2_addr, SRV_SMS_STATUS_UNSENT);
        //srv_phb_set_preferred_sim( (U16 *)append_ucs2_addr,
        //    MMI_PHB_INVALID_CONTACT_ID,
        //    vappUcConvertUCSimIdToMmi(m_service_cntxt->send_info->send_sim_id),
        //    SRV_PHB_NUMBER_OP_TYPE_MESSAGE); /*kuldeep_async_phb*/
        addr = addr->next;
    }
#endif /* __SRV_SMS_MULTI_ADDR__ */

    if (m_service_cntxt->main->state == SRV_UC_STATE_REPLY &&
        m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER &&
        !send_info->change_in_recipient_list)
    {
        srv_sms_set_reply_msg_id(send_handle, m_service_cntxt->send_info->existed_msg_id);
    }

    if (m_service_cntxt->send_info->curr_send_number + 1 < m_service_cntxt->msg->to_num)
    {
        srv_sms_set_mms(send_handle, MMI_TRUE);
    }
    else
    {
        srv_sms_set_mms(send_handle, MMI_FALSE);
    }

#if defined (__MMI_VCALENDAR__) || defined (__MMI_VCARD__)
	 if((operation_type == UC_OPERATION_SEND_VCARD_AS_SMS) ||
        (operation_type == UC_OPERATION_SEND_VCALENDAR_AS_SMS))
	 {
		if(operation_type == UC_OPERATION_SEND_VCARD_AS_SMS) 
		{
			dest_port = 0X23F4;
		}
		else if((operation_type == UC_OPERATION_SEND_VCALENDAR_AS_SMS))
		{
			dest_port = 0X23F5;
		}
			srv_sms_set_content_dcs(send_handle, SRV_SMS_DCS_8BIT);
			mma_mms_attachment_info_struct *att = srv_uc_get_attachment_by_index(main->instance, 0);
			ASSERT(att);
			ASSERT(att->object->reference_count == 1);
			srv_sms_set_content_file(send_handle, (S8*)att->object->file_path_ucs);
			srv_sms_set_data_port(send_handle, 0, dest_port);
	 }
	else
#endif
	{
		srv_sms_set_content(send_handle, (S8*)m_service_cntxt->main->text_buffer, m_service_cntxt->msg->msg_body.curr_slide->txt.char_count * ENCODING_LENGTH);
	}
    main->send_handle = send_handle;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_SAVE_STORAGE_STATUS, &VappUcAppData::onSmsSaveStorageStatusEvtCb, getObjHandle());
    #endif   
    srv_sms_send_msg(send_handle, ucSendSmsRsp, this);
	app->vappUcSendEvtToCaller(EVT_ID_CUI_UC_SMS_SENT);
}

extern "C" void ucSaveSmsRsp(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //VfxU16 *msg_id = (VfxU16*)callback_data->action_data;
    MMI_BOOL result = callback_data->result;
    VfxU32 cause = (VfxU32)callback_data->cause;
    VappUcAppData *appData = (VappUcAppData *)callback_data->user_data;

#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_SMS_SAVE_STORAGE_STATUS, &VappUcAppData::onSmsSaveStorageStatusEvtCb, appData->getObjHandle());
#endif   


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == MMI_TRUE)
    {
        cause = SRV_SMS_CAUSE_NO_ERROR;
    }

#ifndef __SRV_SMS_MULTI_ADDR__ // support sms send group address    
        if (cause != SRV_SMS_CAUSE_SEND_ABORT)
        {
            appData->m_service_cntxt->send_info->curr_send_number++;
            if (appData->m_service_cntxt->send_info->curr_send_number < appData->m_service_cntxt->msg->to_num)
            {
                appData->ucSaveSmsReq();
                return;
            }
        }
    
        if (result != MMI_TRUE && cause != SRV_SMS_CAUSE_SEND_ABORT)
        {
            appData->m_service_cntxt->send_info->curr_send_number--;
        }
#else
    //need to do nothing.
#endif


    appData->send_info->save_result = cause;
    appData->ucActionFsm(SRV_UC_ACTION_SAVE, cause);

    return;
}


extern "C" void ucDeleteSmsCallback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappUcAppData *app = (VappUcAppData *)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(vappUcCheckAppSanity((void *)app) && app->main->instance < MAX_UC_INSTANCES)
    {
		if((app->main->instance < MAX_UC_INSTANCES) && 
		   (app->main->msg_operation < UC_OPERATION_TOTAL_NUM) &&
		   (app->main->highlighted_object_type < SRV_UC_DONE_TYPE_TOTAL_NUM))
		/*make temp condition*/
		{
			app->ucActionFsm(SRV_UC_ACTION_DELETE, (U32)callback_data->cause);
			#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
			  //  mmi_msg_update_unsent_icon();
			#endif 
		}
		srv_uc_send_um_msg_refresh_ind(
			app->main->instance,
			SRV_UM_MSG_BOX_DRAFT,
			SRV_UM_MSG_SMS);
		srv_uc_send_um_msg_refresh_ind(
			app->main->instance,
			SRV_UM_MSG_BOX_UNSENT,
			SRV_UM_MSG_SMS);
    }
}

#ifdef __MMI_COSMOS_UC_MMS_PREVIEW_SUPPORT__ 
void VappUcAppData::previewMessage(void)
{
#ifdef __MMI_MMS_2__
    if (m_service_cntxt->mms_info->max_mms_size < m_service_cntxt->msg->msg_size)
    {
        vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
        m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
        m_signalConnectToCloseProgress.postEmit();
        return;
    }
    m_service_cntxt->send_info->action = SRV_UC_ACTION_PREVIEW;
    ASSERT(m_service_cntxt->send_info->new_msg_id == 0);
    ucCreateMmsHandler(SRV_MMS_CREATE_MMS);
#endif
}
#endif /*__MMI_COSMOS_UC_MMS_PREVIEW_SUPPORT__ */

void VappUcAppData::saveMessage()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_msg_box_enum msg_box = vappUcGetMsgBox(m_service_cntxt->send_info->existed_msg_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* TODO: see about this
    mmi_uc_set_group_id(); */
    if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
    {
        if (m_service_cntxt->msg->to_num > 0)
        {
            if (MMI_FALSE == srv_uc_check_number_length_for_sms(main->instance))
            {
                m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
                vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_NUMBER_LENGTH_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                m_signalConnectToCloseProgress.postEmit();
                return;
            }
        }
    }

    //m_service_cntxt->send_info->action = SRV_UC_ACTION_SAVE;
    if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
    {
        if (msg_box == SRV_UM_MSG_BOX_DRAFT)
        {
            /* TODO: Set processing screen
            mmi_uc_set_processing_screen(0, STR_GLOBAL_SAVING, mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS), 0);

            mmi_uc_entry_processing_generic();

             save msg from SMS to SMS. Delete original one and then save new one. (for more free size) */
            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
            {
                srv_sms_delete_msg(
                    (U16) m_service_cntxt->send_info->existed_msg_id,
                    ucDeleteSmsCallback, 
                    this);
            }
            /* save msg from MMS to SMS. Save new one and then delete original one. */
            else if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
            {
                m_service_cntxt->send_info->curr_send_number = 0;
                ucSaveSmsReq();
            }
            else if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_DEFAULT)
            {
                /*
                 * this flow will happen --> when select sms in draft-->use number -->send sms (edit)-->done
                 * -->done->save, in this case, existed_msg_type= SRV_UC_MSG_TYPE_DEFAULT;
                 */
                m_service_cntxt->send_info->curr_send_number = 0; 
                ucSaveSmsReq();
            }
            else
            {
                ASSERT(0);
            }

            /* TODO: See if this is needed... highlighter need to set by UC 
            send_info->need_highlight_ind_to_um = TRUE; */
        }
        else if (msg_box == SRV_UM_MSG_BOX_UNSENT && m_service_cntxt->msg->to_num > 0)
        {
            /* TODO: Set processing screen
            mmi_uc_set_processing_screen(0, STR_GLOBAL_SAVING, mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS), 0);

            mmi_uc_entry_processing_generic();

            save msg from SMS to SMS. Delete original one and then save new one. */
            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
            {
                srv_sms_delete_msg(
                    (U16) m_service_cntxt->send_info->existed_msg_id,
                    ucDeleteSmsCallback, 
                    this);
            }
            /* save msg from MMS to SMS. Save new one and then delete original one. */
            else if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
            {
                m_service_cntxt->send_info->curr_send_number = 0;
                ucSaveSmsReq();
            }
            else if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_DEFAULT)
            {
                /*
                 * this flow will happen --> when select sms in draft-->use number -->send sms (edit)-->done
                 * -->done->save, in this case, existed_msg_type= SRV_UC_MSG_TYPE_DEFAULT;
                 */
                m_service_cntxt->send_info->curr_send_number = 0;
                ucSaveSmsReq();
            }
            else
            {
                ASSERT(0);
            }

            /* TODO: See if this is needed... highlighter need to set by UC 
            send_info->need_highlight_ind_to_um = TRUE; */
        }
        else
        {
            /* TODO: Set processing screen
            mmi_uc_set_processing_screen(0, STR_GLOBAL_SAVING, mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS), 0);
            mmi_uc_entry_processing_generic(); */
          #ifdef __MMI_MESSAGES_TEMPLATE__  
            if(m_service_cntxt->send_info->action == SRV_UC_ACTION_SAVE_AS_TEMPLATE)
            {
                srv_sms_template_result result;
                //ucSaveSmsReq();
                //srv_sms_set_content(save_handle, (S8*)m_service_cntxt->main->text_buffer, m_service_cntxt->msg->msg_body.curr_slide->txt.char_count * ENCODING_LENGTH);

                if(mmi_ucs2strlen((const CHAR*)m_service_cntxt->main->text_buffer) > SRV_SMS_TEMPLATE_MAX_CHAR_NUM)
                {
                    U8* text_buffer;
                    VFX_SYS_ALLOC_MEM(text_buffer, (SRV_SMS_TEMPLATE_MAX_CHAR_NUM + 1) * ENCODING_LENGTH);
                    memset(text_buffer, 0, (SRV_SMS_TEMPLATE_MAX_CHAR_NUM + 1) * ENCODING_LENGTH);
                    mmi_ucs2ncpy((CHAR*) text_buffer, (const CHAR*)m_service_cntxt->main->text_buffer, SRV_SMS_TEMPLATE_MAX_CHAR_NUM);
				    if( operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE)
				    {
					    result = srv_sms_template_replace((U16) m_service_cntxt->send_info->existed_msg_id, (const WCHAR*) text_buffer, (U16) SRV_SMS_TEMPLATE_MAX_CHAR_NUM * ENCODING_LENGTH);
				    }
				    else
				    {
					    result = srv_sms_template_save((const WCHAR*) text_buffer, (U16) SRV_SMS_TEMPLATE_MAX_CHAR_NUM * ENCODING_LENGTH);
				    }
                    VFX_SYS_FREE_MEM(text_buffer);
                    text_buffer = NULL;
                }
                else
                {
				    if( operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE)
				    {
					    result = srv_sms_template_replace((U16) m_service_cntxt->send_info->existed_msg_id, (const WCHAR*) m_service_cntxt->main->text_buffer, (U16) m_service_cntxt->msg->msg_body.curr_slide->txt.char_count * ENCODING_LENGTH);
				    }
				    else
				    {
					    result = srv_sms_template_save((const WCHAR*) m_service_cntxt->main->text_buffer, (U16) m_service_cntxt->msg->msg_body.curr_slide->txt.char_count * ENCODING_LENGTH);
				    }
                }
                m_service_cntxt->send_info->action = SRV_UC_ACTION_SAVE;
                if (result == SRV_SMS_TEMPLATE_RESULT_OK)
                {
                    ucActionFsm(SRV_UC_ACTION_SAVE, SRV_SMS_CAUSE_NO_ERROR);
                }
                else
                {
                    ucActionFsm(SRV_UC_ACTION_SAVE, result);
                }
            }
            else
          #endif /* __MMI_MESSAGES_TEMPLATE__ */      
            {
                m_service_cntxt->send_info->curr_send_number = 0;
                ucSaveSmsReq();
            }
        }
    }
    #ifdef __MMI_EMAIL__
    else if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
        ucSaveEmailReq();
    }
    #endif
#ifdef __MMI_MMS_2__
    else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
    {
        if (m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
        {
            if (m_service_cntxt->msg->msg_size > mms_get_max_msg_size_in_restricted_mode())
            {
                vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
				m_signalConnectToCloseProgress.postEmit();
                return;
            }
        }
        /* required as edit allowed on big MMS also. */
        if (m_service_cntxt->mms_info->max_mms_size < m_service_cntxt->msg->msg_size)
        {
            vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
            m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
			m_signalConnectToCloseProgress.postEmit();
            return;
        }
        /* The original mms msg would be deleted after mms creation if it belongs to draft folder */
        /* TODO: Set processing screen
        mmi_uc_set_processing_screen(0, STR_GLOBAL_PLEASE_WAIT, mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS), 0);
        mmi_uc_entry_processing_generic(); */
      #ifdef __MMI_MMS_TEMPLATE_SUPPORT__  
        if(m_service_cntxt->send_info->action == SRV_UC_ACTION_SAVE_AS_TEMPLATE)
        {
            ucCreateMmsHandler(SRV_MMS_CREATE_SAVE_TEMPLATE_MMS);/* SRV_MMS_CREATE_SAVE_MMS */
            /* In the create response, can handle this with SAVE Case */
            m_service_cntxt->send_info->action = SRV_UC_ACTION_SAVE;
        }
        else
      #endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */      
        {
            ucCreateMmsHandler(SRV_MMS_CREATE_SAVE_MMS);/* SRV_MMS_CREATE_SAVE_MMS */
        }
    }
#endif
    else
    {
        ASSERT(0);
    }
}

void VappUcAppData::ucSaveSmsAfterSend(U8 status, void *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE save_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    save_handle = srv_sms_get_save_handle();

#if 0
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* MMI_MAX_SIM_NUM */
#endif
    srv_sms_set_sim_id(save_handle, vappUcConvertUCSimIdToSMS(m_service_cntxt->send_info->send_sim_id));
    if(number)
    {
        S8 addr[(SRV_SMS_MAX_ADDR_LEN + 1) *ENCODING_LENGTH];
        U16 addr_len;

        addr_len = mmi_asc_n_to_ucs2((S8*)addr, (S8*)number, SRV_SMS_MAX_ADDR_LEN);
        addr[addr_len] = '\0';
        addr[addr_len + 1] = '\0';

        srv_sms_set_address(save_handle, (S8*)addr);
    }

    srv_sms_set_status(save_handle, (srv_sms_status_enum)status);
    srv_sms_set_content(save_handle, (S8*)m_service_cntxt->main->text_buffer, m_service_cntxt->msg->msg_body.curr_slide->txt.char_count * ENCODING_LENGTH);
    main->save_handle = save_handle;
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_SAVE_STORAGE_STATUS, &VappUcAppData::onSmsSaveStorageStatusEvtCb, getObjHandle());
    #endif     
    srv_sms_save_msg(save_handle, ucSaveSmsRsp, this);

}


void VappUcAppData::ucSaveSmsReq(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE save_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MESSAGES_TEMPLATE__
	if(m_service_cntxt->send_info->action == SRV_UC_ACTION_SAVE_AS_TEMPLATE)
	{
		srv_sms_template_result result;
		if(mmi_ucs2strlen((const CHAR*)m_service_cntxt->main->text_buffer) > SRV_SMS_TEMPLATE_MAX_CHAR_NUM)
		{
			U8* text_buffer;
			VFX_SYS_ALLOC_MEM(text_buffer, (SRV_SMS_TEMPLATE_MAX_CHAR_NUM + 1) * ENCODING_LENGTH);
			memset(text_buffer, 0, (SRV_SMS_TEMPLATE_MAX_CHAR_NUM + 1) * ENCODING_LENGTH);
			mmi_ucs2ncpy((CHAR*) text_buffer, (const CHAR*)m_service_cntxt->main->text_buffer, SRV_SMS_TEMPLATE_MAX_CHAR_NUM);
			if( operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE)
			{
				result = srv_sms_template_replace((U16) m_service_cntxt->send_info->existed_msg_id, (const WCHAR*) text_buffer, (U16) SRV_SMS_TEMPLATE_MAX_CHAR_NUM * ENCODING_LENGTH);
			}
			else
			{
				result = srv_sms_template_save((const WCHAR*) text_buffer, (U16) SRV_SMS_TEMPLATE_MAX_CHAR_NUM * ENCODING_LENGTH);
			}
			VFX_SYS_FREE_MEM(text_buffer);
			text_buffer = NULL;
		}
		else
		{
			if( operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE)
			{
				result = srv_sms_template_replace((U16) m_service_cntxt->send_info->existed_msg_id, (const WCHAR*) m_service_cntxt->main->text_buffer, (U16)m_service_cntxt->msg->msg_body.curr_slide->txt.char_count * ENCODING_LENGTH);
			}
			else
			{
				result = srv_sms_template_save((const WCHAR*) m_service_cntxt->main->text_buffer, (U16)m_service_cntxt->msg->msg_body.curr_slide->txt.char_count * ENCODING_LENGTH);
			}
		}
		m_service_cntxt->send_info->action = SRV_UC_ACTION_SAVE;
		if (result == SRV_SMS_TEMPLATE_RESULT_OK)
		{
			ucActionFsm(SRV_UC_ACTION_SAVE, SRV_SMS_CAUSE_NO_ERROR);
		}
		else
		{
		ucActionFsm(SRV_UC_ACTION_SAVE, result);
		}
	}
	else
#endif /* __MMI_MESSAGES_TEMPLATE__ */        
	{

        save_handle = srv_sms_get_save_handle();
    
        //ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);

#if 0
     #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* MMI_MAX_SIM_NUM */
#endif
        srv_sms_set_sim_id(save_handle, vappUcConvertUCSimIdToSMS(m_service_cntxt->send_info->send_sim_id));
    
        if(m_service_cntxt->msg->to_head)
        {
            U8 ucs2Addr[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
            U16 addr_len;
            srv_uc_addr_struct * addr;
            U16 i;
            
            addr = m_service_cntxt->msg->to_head;
            for (i = 0; i < m_service_cntxt->send_info->curr_send_number; i++)
            {
                MMI_ASSERT(addr->next);
                addr = addr->next;
            }
  
            addr_len = mmi_asc_n_to_ucs2((S8*)ucs2Addr, (S8*)addr->addr, SRV_SMS_MAX_ADDR_LEN);
            ucs2Addr[addr_len] = '\0';
            ucs2Addr[addr_len + 1] = '\0';
       
            srv_sms_set_address(save_handle, (S8*)ucs2Addr);
            //srv_phb_set_preferred_sim( (U16 *)ucs2Addr,
            //    MMI_PHB_INVALID_CONTACT_ID,
            //    vappUcConvertUCSimIdToMmi(m_service_cntxt->send_info->send_sim_id),
            //    SRV_PHB_NUMBER_OP_TYPE_MESSAGE);
    #ifdef __SRV_SMS_MULTI_ADDR__ // support sms send group address
		    addr = m_service_cntxt->msg->to_head;
		    addr = addr->next;
		    for (S32 i =1;i < m_service_cntxt->msg->to_num; i++)
		    {
			    WCHAR append_ucs2_addr[SRV_SMS_MAX_ADDR_LEN+1] = {0,};
    
			    addr_len = mmi_asc_n_to_ucs2((S8*)append_ucs2_addr, (S8*)addr->addr, SRV_SMS_MAX_ADDR_LEN);
			    append_ucs2_addr[addr_len] = '\0';
			    append_ucs2_addr[addr_len + 1] = '\0';
			    srv_sms_append_address(save_handle, append_ucs2_addr, SRV_SMS_STATUS_DRAFT);
				//srv_phb_set_preferred_sim( (U16 *)append_ucs2_addr,
				//	MMI_PHB_INVALID_CONTACT_ID,
				//	vappUcConvertUCSimIdToMmi(m_service_cntxt->send_info->send_sim_id),
				//	SRV_PHB_NUMBER_OP_TYPE_MESSAGE);
			    addr = addr->next;
		    }
    #endif /* __SRV_SMS_MULTI_ADDR__ */
    
	    }
    
       /* Not handled yet
           sendData->status = SMSAL_STO_DRAFT; protocol support. save to draft*/
    
        srv_sms_set_status(save_handle, SRV_SMS_STATUS_DRAFT);
        srv_sms_set_content(save_handle, (S8*)m_service_cntxt->main->text_buffer,m_service_cntxt->msg->msg_body.curr_slide->txt.char_count* ENCODING_LENGTH);
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        mmi_frm_cb_reg_event(EVT_ID_SRV_SMS_SAVE_STORAGE_STATUS, &VappUcAppData::onSmsSaveStorageStatusEvtCb, getObjHandle());
    #endif         
        srv_sms_save_msg(save_handle, ucSaveSmsRsp, this);

    }
}

#ifdef __MMI_MMS_2__
extern "C" void ucSaveMmsRsp(srv_mms_result_enum result, void *rsp_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappUcAppData *app = (VappUcAppData*)user_data;
    srv_mms_save_rsp_struct *msg_rsp = (srv_mms_save_rsp_struct*) rsp_data;
	

    #ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
	U8 instance = 0 ;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	instance = vappUcCheckInstanceByAppPtr((void *)app) ;
	MMI_ASSERT(instance < MAX_UC_INSTANCES) ;
	if(EndKeyHandle[instance].NeedToFreeService == VFX_TRUE)
	{
		if(EndKeyHandle[instance].xml_fs)
		{
            FS_Close(EndKeyHandle[instance].xml_fs);
            EndKeyHandle[instance].xml_fs = 0;
		}
		srv_uc_init_uc_folder(instance);
		srv_uc_delete(instance);
		VappUCFreeEndKeyHandleData(instance);
		return;
	}
    #endif
	if(!vappUcCheckAppSanity((void *)app))
	{
		return;
	}
	else if(app->wait_to_close == VFX_TRUE)
	{
		app->wait_to_close = VFX_FALSE;
		VcuiUcMainCui *m_app = (VcuiUcMainCui *)(app->m_parent);
		m_app->vappUcTerminate();
		return ;
	}

    /*if(app->m_service_cntxt->send_info->fs)
    {
        FS_Close(app->m_service_cntxt->send_info->fs);
        app->m_service_cntxt->send_info->fs = 0;
    }*/
    app->is_mma_active = VFX_FALSE ;
    if (app->m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG && 
        (app->vappUcGetMsgBox(app->m_service_cntxt->send_info->existed_msg_id) == SRV_UM_MSG_BOX_DRAFT
      #ifdef __MMI_UM_TEMPLATE_SUPPORT__
        ||  app->vappUcGetMsgBox(app->m_service_cntxt->send_info->existed_msg_id) == SRV_UM_MSG_BOX_PREDEF_TEMPLATES 
        ||  app->vappUcGetMsgBox(app->m_service_cntxt->send_info->existed_msg_id) == SRV_UM_MSG_BOX_USRDEF_TEMPLATES
      #endif  
        ))
    {
        if (app->m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
        {
			if(msg_rsp->result[0] == MMA_RESULT_OK)
			{
                app->ucDeleteExistedMms();
			    {
				    mmi_event_struct evt;
				    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UC_MESSAGE_DELETED);
				    memset(&evt, 0, sizeof(mmi_event_struct));
				    evt.evt_id = EVT_ID_SRV_UC_MESSAGE_DELETED;
				    MMI_FRM_CB_EMIT_EVENT(&evt);
			    }
            }
        }
    }

    if (msg_rsp->result[0] != MMA_RESULT_OK)
    {
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        U16 str_id = 0;
    #endif

        if (app->m_service_cntxt->send_info->action != SRV_UC_ACTION_SAVE_IN_BACKGROUND)
        {
            /* pop up working space string to indicate user */
            if (msg_rsp->result[0] == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE)
            {
                //vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_NO_ENOUGH_WORKING_SPACE_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
            }
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            else if (msg_rsp->result[0] == MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT_USE_PHONE)
            {
                str_id = STR_ID_VAPP_UC_INSERT_CARD;
            }
            else if (msg_rsp->result[0] == MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_MEM_CARD)
            {
                str_id = STR_ID_VAPP_UC_TOO_MANY_MSG_ID;
            }
            else if (msg_rsp->result[0] == MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_PHONE_MEMORY)
            {
                str_id = STR_ID_VAPP_UC_TOO_MANY_MSG_ID;
            }
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
            else
            {
                mmi_nmgr_balloon_type_enum type;
                WCHAR *str = vappUcGetMmaResultPopupStr((mma_result_enum)msg_rsp->result[0], &type);
                vappUcDisplayPopup(str, type);
            }
        }
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (str_id)
        {
            vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(str_id)), MMI_NMGR_BALLOON_TYPE_FAILURE);
        }
    #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
	}
    app->ucActionFsm(SRV_UC_ACTION_SAVE, msg_rsp->result[0]);
}
#endif

#ifdef __MMI_MMS_2__
extern "C" void ucCreateMmsRsp(srv_mms_result_enum result, void *rsp_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappUcAppData *app = (VappUcAppData*)user_data;
    srv_mms_create_rsp_struct *msg_rsp = (srv_mms_create_rsp_struct*) rsp_data;
    VfxBool isPreview = VFX_FALSE;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!vappUcCheckAppSanity((void *)app))
	{
		return;
	}
	else if(app->wait_to_close == VFX_TRUE)
	{
		app->wait_to_close = VFX_FALSE;
		VcuiUcMainCui *m_app = (VcuiUcMainCui *)(app->m_parent);
		m_app->vappUcTerminate();
		return ;
	}
	app->is_mma_active = VFX_FALSE ;
	
	if(app->m_service_cntxt->msg->msg_header.to)
	{
		srv_uc_free_mem_alloc_for_mma_addr(app->m_service_cntxt->msg->msg_header.to, app->main->instance);
		app->m_service_cntxt->msg->msg_header.to = NULL ;
	}
	if(app->m_service_cntxt->msg->msg_header.subject.text)
	{
		VFX_FREE_MEM(app->m_service_cntxt->msg->msg_header.subject.text);
		app->m_service_cntxt->msg->msg_header.subject.text = NULL ;
	}
    if(app->m_service_cntxt->send_info->action == SRV_UC_ACTION_PREVIEW)
    {
        isPreview = VFX_TRUE;
    }

// TODO: Still to handle Send fail result from BGSR


    if(app->send_info->request_id != UC_CREATE_REQ)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_CREATE_MMS_RSP_P1, app->send_info->request_id);
        /*if(app->m_service_cntxt->send_info->fs)
        {
            FS_Close(app->m_service_cntxt->send_info->fs);
            app->m_service_cntxt->send_info->fs = 0;
        }*/
    }
    else
    {
        if (msg_rsp->result != MMA_RESULT_OK)
        {
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            U16 str_id = 0;
        #endif 
            /*if(app->m_service_cntxt->send_info->fs)
            {
                FS_Close(app->m_service_cntxt->send_info->fs);
                app->m_service_cntxt->send_info->fs = 0;
            }*/

            if (app->m_service_cntxt->send_info->action != SRV_UC_ACTION_SAVE_IN_BACKGROUND)
            {
                /* pop up working space string to indicate user */
                if ((msg_rsp->result == MMA_RESULT_FAIL_INSUFFICIENT_STORAGE) && (msg_rsp->min_fs_space_required != 0))
                {
                    //vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_NO_ENOUGH_WORKING_SPACE_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                    vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                }
            #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
                else if (msg_rsp->result == MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT_USE_PHONE)
                {
                    str_id = STR_ID_VAPP_UC_INSERT_CARD;
                }
                else if (msg_rsp->result == MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_MEM_CARD)
                {
                    str_id = STR_ID_VAPP_UC_TOO_MANY_MSG_ID;
                }
                else if (msg_rsp->result == MMA_RESULT_FAIL_MAX_MSG_REACHED_ON_PHONE_MEMORY)
                {
                    str_id = STR_ID_VAPP_UC_TOO_MANY_MSG_ID;
                }
            #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
                else
                {
                    {
                        mmi_nmgr_balloon_type_enum type;
                        WCHAR *str = vappUcGetMmaResultPopupStr((mma_result_enum)msg_rsp->result, &type);
                        vappUcDisplayPopup(str, type);
                    }
                }
            }
            else
            {
                app->resetApp();
            }
        #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
            if (str_id)
            {
                vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(str_id)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                app->m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
                    /* TODO: Show UI
				mmi_confirm_property_struct arg;
                mmi_uc_setSoftkeyFunction(
                    mmi_uc_set_prefer_storage,
                    mmi_uc_reset_state,
                    (U8) mmi_get_event_based_sound(MMI_EVENT_QUERY),
                    str_id);

				mmi_confirm_property_init(&arg, CNFM_TYPE_YESNO);
				arg.callback = (mmi_proc_func)mmi_uc_set_storage;
				arg.parent_id = app->main->uc_cui_gid;
				mmi_confirm_display((WCHAR *)(get_string(str_id)), MMI_EVENT_QUERY, &arg); */
            }
            else
        #endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
            {
                /* reset state */
                app->m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
            }
            //mmi_frm_scrn_close(app->main->uc_cui_gid, SCR_ID_UC_PROCESSING); TODO:
        }
        else
        {
            /* sending XML content completes */
            {
                /*if(app->m_service_cntxt->send_info->fs)
                {
                    FS_Close(app->m_service_cntxt->send_info->fs);
                    app->m_service_cntxt->send_info->fs = 0;
                }*/
                app->m_service_cntxt->send_info->new_msg_id = msg_rsp->msg_id;
                app->send_info->new_msg_storage = (mma_msg_storage_type_enum) msg_rsp->storage;

            #if 0 /* TODO: Code for intrerrupt */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

                switch (app->m_service_cntxt->send_info->action)
                {
                    case SRV_UC_ACTION_SEND:
                    {
                        /* This case should not happened is BGSR is enabled */
                        ASSERT(0);
                    }
                        break;

                    case SRV_UC_ACTION_SEND_AND_SAVE:
                    {
                        /* This case should not happened if BGSR is enabled */
                        ASSERT(0);
                    }
                        break;

                    case SRV_UC_ACTION_SAVE:
                    {
                        srv_um_msg_box_enum msg_box = app->vappUcGetMsgBox(app->m_service_cntxt->send_info->existed_msg_id);

                        if (app->m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG && msg_box == SRV_UM_MSG_BOX_DRAFT)
                        {
                            /* TODO: Show progress screen
                            mmi_uc_set_processing_screen(
                                0,
                                STR_GLOBAL_SAVING,
                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                0);

                            mmi_uc_entry_processing_generic(); */

                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                            if (app->m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                                app->send_info->need_highlight_ind_to_um = TRUE;
                            }
                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                            else if (app->m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                app->ucDeleteExistedMms();
                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                        //mmi_frm_scrn_close(app->main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                    }
                        break;

                    case SRV_UC_ACTION_PREVIEW:
                    {
                        app->m_signalPreview.postEmit();
                        //app->ucPreviewMms(); 
                    }
                        break;

                    case SRV_UC_ACTION_SEND_IN_BACKGROUND:
                    {
                        //app->ucActionFsm(SRV_UC_ACTION_SEND, MMA_RESULT_OK); /*kuldeep_async_phb*/
                        app->m_service_cntxt->send_info->new_msg_id = 0;
						app->send_info->send_result = MMA_RESULT_OK ;
						app->ucHandleDataAfterSend();
                    }
                        break;

                    case SRV_UC_ACTION_IDLE:
						{
							app->m_signalConnectToCloseProgress.postEmit();
							//just in one case when card out during preview req.
						}
							break;

                    default:
                    {
                        ASSERT(0);
                    }
                }
            }
        }
    }

    if(isPreview || (msg_rsp->result != MMA_RESULT_OK && 
		app->m_service_cntxt->send_info->action != SRV_UC_ACTION_SAVE_IN_BACKGROUND))
    {
        app->m_signalConnectToCloseProgress.postEmit();
    }
    else
    {
        //app->m_signalConnectOnError.postEmit();  /*kuldeep_async_phb*/
    }
}
#endif

extern "C" void srv_uc_replace_duplicate_object_file_name(U32 instance);

void VappUcAppData::ucCreateMmsReq(U8 op_type)
{
#ifdef __MMI_MMS_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_create_req_struct msg_req;
 //   U32 read_size;
 //   S32 remaining_size;
 //   U16 peer_buff_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_info->request_id = UC_CREATE_REQ;
	is_mma_active = VFX_TRUE ;
    
    srv_uc_replace_duplicate_object_file_name(main->instance);

    /* reset */
    memset(&msg_req, 0, sizeof(srv_mms_create_req_struct));
    msg_req.mode = MMA_MODE_EDIT;
    msg_req.msg_id = 0;
    msg_req.sim_id = srv_uc_convert_uc_sim_id_to_mma(srv_uc_convert_sim_id(m_service_cntxt->send_info->send_sim_id));

    if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
    {
        if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD
            || m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
        {
            msg_req.msg_id = m_service_cntxt->send_info->existed_msg_id;
            msg_req.mode = MMA_MODE_FORWARD;
        }
        else if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
        {
            msg_req.msg_id = m_service_cntxt->send_info->existed_msg_id;
            msg_req.mode = MMA_MODE_SEND;
        }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        else if (m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG &&
                    m_service_cntxt->main->mode != SRV_UC_FORWARD_WITH_EDIT_MODE)
        {
            if(     (vappUcGetMsgBox(m_service_cntxt->send_info->existed_msg_id) == SRV_UM_MSG_BOX_DRAFT) 
              #ifdef __MMI_UM_TEMPLATE_SUPPORT__  
                ||  (vappUcGetMsgBox(m_service_cntxt->send_info->existed_msg_id) == SRV_UM_MSG_BOX_PREDEF_TEMPLATES) 
                ||  (vappUcGetMsgBox(m_service_cntxt->send_info->existed_msg_id) == SRV_UM_MSG_BOX_USRDEF_TEMPLATES)
              #endif  
              )
            {
                msg_req.msg_id = m_service_cntxt->send_info->existed_msg_id;
            }
        }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 
    }

#if (defined(__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) && defined(__MMI_MMS_TEMPLATE_SUPPORT__))
    if (m_service_cntxt->send_info->action == SRV_UC_ACTION_SAVE_AS_TEMPLATE)
    {
        msg_req.mode = MMA_MODE_TEMPLATE;
        if (m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG)
        {
            /* it is the case of Edit a Template & save it */
            msg_req.mode = MMA_MODE_EDIT;
        }
        else if (!(m_service_cntxt->main->state == SRV_UC_STATE_FORWARD
            || m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE))
        {
            msg_req.msg_id = 0;
        }
    }
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */ 

#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
	if(EndKeyHandle[main->instance].NeedToFreeService == VFX_TRUE)
	{
		SRV_UC_MAKE_MMS_XML_FILE_PATH(msg_req.xml_filepath, 0, main->instance);
		m_service_cntxt->send_info->xml_file_size = applib_get_file_size(msg_req.xml_filepath);
		EndKeyHandle[main->instance].xml_fs = FS_Open(msg_req.xml_filepath, FS_READ_ONLY);
		msg_req.xml_size = m_service_cntxt->send_info->xml_file_size;
		msg_req.mode = MMA_MODE_VENDOR_XML ;
		msg_req.content_info = NULL ;
	}
	else
#endif
	{
    	m_service_cntxt->msg->msg_header.to = NULL ;
    	/*mma address data*/
    	m_service_cntxt->msg->msg_header.to = srv_uc_convert_uc_addr_to_mms_addr(m_service_cntxt->msg->to_head, main->instance);
    	/*mma needs subject in utf8 convert here*/
    	m_service_cntxt->msg->msg_header.subject.text = NULL ;
    	if(mmi_ucs2strlen((S8*)m_service_cntxt->msg->subject) > 0)
    	{
    		VFX_SYS_ALLOC_MEM(m_service_cntxt->msg->msg_header.subject.text ,(SRV_UC_MAX_SUBJECT_ARRAY_LEN+1)*ENCODING_LENGTH);
    		memset(m_service_cntxt->msg->msg_header.subject.text, 0 ,(SRV_UC_MAX_SUBJECT_ARRAY_LEN+1)*ENCODING_LENGTH);
    		mmi_chset_ucs2_to_utf8_string((kal_uint8 *)m_service_cntxt->msg->msg_header.subject.text,(kal_int32)(SRV_UC_MAX_SUBJECT_ARRAY_LEN+1)*ENCODING_LENGTH,(kal_uint8 *)m_service_cntxt->msg->subject);
    		m_service_cntxt->msg->msg_header.subject.charset = MMA_CHARSET_UTF8 ;
    	}
    	m_service_cntxt->msg->msg_body.layout = srv_uc_convert_to_mms_layout_type((mma_slide_layout_enum)m_service_cntxt->msg->msg_body.layout);
    	m_service_cntxt->msg->g_msg_header.header = &(m_service_cntxt->msg->msg_header) ;
    	m_service_cntxt->msg->g_msg_header.header->to_num = m_service_cntxt->msg->to_num ;
    	srv_uc_copy_filename_filepath(main->instance);
    	m_service_cntxt->msg->g_uc_content_info.header = &(m_service_cntxt->msg->g_msg_header);
    	m_service_cntxt->msg->g_uc_content_info.body = &(m_service_cntxt->msg->msg_body);
    	msg_req.content_info = &(m_service_cntxt->msg->g_uc_content_info);
    }

    msg_req.op_type = op_type;
    msg_req.user_data = this;
  #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
    if(op_type == SRV_MMS_CREATE_SAVE_MMS || op_type == SRV_MMS_CREATE_SAVE_TEMPLATE_MMS)
  #else
    if(op_type == SRV_MMS_CREATE_SAVE_MMS)
  #endif      
    {
        msg_req.call_back = ucSaveMmsRsp;
    }
    else
    {
        msg_req.call_back = ucCreateMmsRsp;
    }
    srv_mms_create(&msg_req);
#endif
    return;
}

/*kuldeep_async_phb*/
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
#endif

void VappUcAppData::ucCreateMmsHandler(U8 op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //result = srv_uc_create_mms_xml_description_file(main->instance);
	srv_uc_set_media_duration(m_service_cntxt->msg->msg_body.slides);

    if (result == FS_NO_ERROR)
    {
		if(op_type == (U8)SRV_MMS_CREATE_SEND_MMS)
		{
			//ucSetPreferedSIMForMMSRecipients(); /*kuldeep_async_phb*/
		}
        ucCreateMmsReq(op_type);
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_CREATE_MMS_XML_DESC_FILE_P1, result);
        if (result == FS_DISK_FULL)
        {
            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
        }
        else
        {
            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_NMGR_BALLOON_TYPE_FAILURE);
        }
        /* reset state */
        m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
		m_signalConnectToCloseProgress.postEmit();
    }

}


void VappUcAppData::ucAppendTextFromApp(U8* text_buffer)
{
	/*TODO:: Rahul 
	  Has to do all the text validation and other handling in this API, before appening the text to the buffer*/	 

	 U16 bufflen = mmi_ucs2strlen((const CHAR*)text_buffer);

	 mmi_ucs2ncat((CHAR*) m_service_cntxt->main->text_buffer, (const CHAR*)text_buffer, bufflen);
	 m_signalConnectOnPage.postEmit();

}


void VappUcAppData::setContactInsertType(U8 type)
{
	contact_insert_type = type;

}
U8 VappUcAppData::getContactInsertType(void)
{
   return contact_insert_type;
}

extern "C" void processNewMsgInMmsSetting(VfxBool input, void* app_data)
{
    VappUcAppData *app = (VappUcAppData *)app_data;
    app->vappUcProcessNewMsgInMmsSetting(input);
}

void VappUcAppData::vappUcProcessNewMsgInMmsSetting(VfxBool input)
{
    main->confirm_handler = NULL;

    if(input)
    {
        if(!handleObjectInsertIfFilePathExist())
        {
            return;
        }
        changeMsgTypeIfNeeded();
        switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
        if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
        {
            m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
        }
        srv_uc_update_msg_size(main->instance);
        m_signalConnectOnPage.postEmit();
    }
    else
    {
        //VcuiUcMainCui* app = (VcuiUcMainCui *)m_parent;
        if (m_service_cntxt->main->file_path != NULL && srv_uc_is_resized_image((U16*) m_service_cntxt->main->file_path, main->instance) == MMI_TRUE)
        {
            FS_Delete((WCHAR*) m_service_cntxt->main->file_path);
            kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
            m_service_cntxt->main->file_path = NULL;
        }
        m_signalConnectOnError.postEmit();
        //app->vappUcTerminate();
    }
}

extern "C" void processSelectObjectFromFmToInsert(VfxBool input, void* app_data)
{
    VappUcAppData *app = (VappUcAppData *)app_data;
    app->vappUcProcessSelectObjectFromFmToInsert(input);
}

void VappUcAppData::vappUcProcessSelectObjectFromFmToInsert(VfxBool input)
{
    main->confirm_handler = NULL;

    if(input)
    {
        ucSelectObjectFromFmToInsert((U16*) m_service_cntxt->main->file_path, main->is_short);
    }
    else
    {
        if (m_service_cntxt->main->file_path)
        {
            kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
            m_service_cntxt->main->file_path = NULL;
        }
    }
}
#ifdef __MMI_EMAIL__

void vapp_UC_email_comp_proc(VappEmailComp::ResultEnum result, void* user_data)
{
    VappUcAppData *app = (VappUcAppData*)user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!vappUcCheckAppSanity((void *)app))
	{
		return;
	}
    if (result != VappEmailComp::SUCC)
    {
		VfxResId resId = STR_GLOBAL_ERROR;
		switch (result)
		{
			case VappEmailComp::FILE_IS_EMPTY:
				resId = STR_EMAIL_FTO_EMPTY_FILE;
				break;
			case VappEmailComp::FILE_NOT_FOUND:
				resId = STR_GLOBAL_FILE_NOT_FOUND;
				break;
			case VappEmailComp::FILE_TOO_LARGE:
			case VappEmailComp::MAIL_TOO_LARGE:
				resId = STR_EMAIL_FTO_ATTCH_TOO_LARGE;
				break;
			case VappEmailComp::DRM_PROHIBITED:
				resId = STR_GLOBAL_DRM_PROHIBITED;
				break;
            case VappEmailComp::FS_ERROR:
                resId = VappEmailComp::getFsErrorStrId(app->main->callback_para);
                break;
		}
		vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(resId)), MMI_NMGR_BALLOON_TYPE_FAILURE);
        app->m_signalConnectOnFileSelection.postEmit();
		app->main->active_app_flag = VFX_FALSE;
        return;
    }
    app->ucSelectObjectFromFmToInsertWarningModeCheck( (PU16)app->m_service_cntxt->main->file_path, app->main->is_short);
    app->m_signalConnectOnFileSelection.postEmit();
	app->main->active_app_flag = VFX_FALSE;
}
#endif /*__MMI_EMAIL__*/

void VappUcAppData::ucAddObjectFromAppSelection(U16 *filePath, S32 is_short)
{
    FS_HANDLE handle;
    U32 flie_path_len = 0;
	VcuiUcMainCui*  parentCui = (VcuiUcMainCui*)m_parent;

    if (filePath == NULL)
    {
//        cui_file_selector_close(main->cui_gid);
        return;
    }

    if ((handle = FS_GetAttributes((PU16) filePath)) < 0)
    {
        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(handle))), MMI_NMGR_BALLOON_TYPE_FAILURE);
		m_signalConnectOnFileSelection.postEmit();
        return;
    }
    /* use self parameter to save file name info */
    if (m_service_cntxt->main->file_path)
    {
        kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
        m_service_cntxt->main->file_path = NULL;
    }

    flie_path_len = mmi_ucs2strlen((S8*) filePath);

    m_service_cntxt->main->file_path = (U8*)kal_adm_alloc(main->mem_pool_id, (flie_path_len + 1) * ENCODING_LENGTH);

    ASSERT(m_service_cntxt->main->file_path);
    mmi_ucs2ncpy((S8*) m_service_cntxt->main->file_path, (S8*) filePath, flie_path_len);

    main->is_short = is_short;
    {
    #ifdef __MMI_EMAIL__
        if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
        {
            vapp_uc_media_info media;
		    VappEmailComp::ResultEnum result = VappEmailComp::SUCC;
            memset(&media, 0, sizeof(vapp_uc_media_info));
            media.offset = 0;
            media.size = applib_get_file_size((kal_wchar*) filePath);;
            media.file_path = filePath;
            media.file_name = srv_uc_get_file_name((U16*) filePath);
            media.is_virtual_file = 0;
		    result = VappEmailComp::addAttchAsync(&media, m_service_cntxt->msg->msg_size, main->callback_para, vapp_UC_email_comp_proc, this);
            if (result != VappEmailComp::SUCC && result != VappEmailComp::WOULD_BLOCK)
            {
                // TODO: UC should not add the attachments to the list
			    VfxResId resId = STR_GLOBAL_ERROR;
			    switch (result)
			    {
				    case VappEmailComp::FILE_IS_EMPTY:
					    resId = STR_EMAIL_FTO_EMPTY_FILE;
					    break;
				    case VappEmailComp::FILE_NOT_FOUND:
					    resId = STR_GLOBAL_FILE_NOT_FOUND;
					    break;
				    case VappEmailComp::FILE_TOO_LARGE:
				    case VappEmailComp::MAIL_TOO_LARGE:
					    resId = STR_EMAIL_FTO_ATTCH_TOO_LARGE;
					    break;
				    case VappEmailComp::DRM_PROHIBITED:
					    resId = STR_GLOBAL_DRM_PROHIBITED;
					    break;
                    case VappEmailComp::FS_ERROR:
                        resId = VappEmailComp::getFsErrorStrId(main->callback_para);
                        break;
			    }
			    vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(resId)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                m_signalConnectOnFileSelection.postEmit();
		        main->active_app_flag = VFX_FALSE;
                return;
            }
            else if (result == VappEmailComp::SUCC)
            {
            //We can add media here.
                ucSelectObjectFromFmToInsertWarningModeCheck( filePath, is_short);
                m_signalConnectOnFileSelection.postEmit();
		        main->active_app_flag = VFX_FALSE;
            }
            return;
        }
        else
    #endif
        if(parentCui->isActive())
        {
            ucSelectObjectFromFmToInsertWarningModeCheck( filePath, is_short);
            m_signalConnectOnFileSelection.postEmit();
		    main->active_app_flag = VFX_FALSE;
        }
        else
        {
	        main->active_app_flag = VFX_TRUE;
        }
    }

}

void VappUcAppData::ucSelectObjectFromFmToInsertWarningModeCheck(U16 *filePath, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mma_insert_check_struct check_result;
    mma_insert_type_enum mms_type = (mma_insert_type_enum)srv_uc_convert_to_mms_insert_type(main->highlighted_object_type);
    FS_HANDLE handle;
    mma_insert_info_struct insert_info;
    MMI_BOOL img_resolution_need_resize = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&check_result, 0, sizeof(mma_insert_check_struct));

    if (filePath == NULL)
    {
//        cui_file_selector_close(main->cui_gid);
        return;
    }

    if ((handle = FS_GetAttributes((PU16) filePath)) < 0)
    {
        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(handle))), MMI_NMGR_BALLOON_TYPE_FAILURE);
        return;
    }
#ifdef __MMI_EMAIL__
    if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
      ucSelectObjectFromFmToInsert((U16*) m_service_cntxt->main->file_path, main->is_short);
      return;
    }
#endif
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
#endif
    /* because here is only check for warning mode, no need to reserve the size for greeting and address in advance */

    insert_info.creation_mode = m_service_cntxt->mms_info->creation_mode;
    insert_info.current_msg_size = 0;   /* becasue only check warning mode, no need curr size */
    insert_info.max_msg_size = m_service_cntxt->mms_info->max_mms_size - srv_uc_reserved_size(main->instance);
    insert_info.insert_type = mms_type;
    insert_info.filepath = (kal_wchar*) filePath;
    insert_info.mms_type = srv_uc_get_mms_type(main->instance);

    mma_uc_insert_object_check(&insert_info, &check_result);

    /* Main use is in Image case to show error popup before resize test. */
    if (!(check_result.result) &&
        ((MMA_RESULT_FAIL_FILE_IO == check_result.detail_result) ||
         (MMA_RESULT_FAIL_FILE_CORRUPTED == check_result.detail_result) ||
         (MMA_RESULT_FAIL_FILE_EMPTY == check_result.detail_result) ||
         (MMA_RESULT_FAIL_IMAGE_TOO_LARGE == check_result.detail_result)))
    {
        srv_uc_result result;

        result = srv_uc_convert_mms_check_result(&check_result);
        {
            mmi_nmgr_balloon_type_enum type;
            WCHAR *str = vappUcGetSrvResultPopupStr(result, &type);
            vappUcDisplayPopup(str, type);
        }
        /* TODO: 
        mmi_uc_set_group_id();
        mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_PROCESSING);
        mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_CONFIRM); */
        kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
        m_service_cntxt->main->file_path = NULL;
        return;
    }
    /* Check if it is DRM file */
    /* all DRM files can not be resized. */
    if (main->highlighted_object_type == SRV_UC_OBJECT_TYPE_IMAGE && check_result.drm_type == MMA_DRM_NONE)
    {
        if (main->image_resize_limit && applib_get_file_size((U16*)m_service_cntxt->main->file_path) > main->image_resize_limit)
        {
            img_resolution_need_resize = MMI_TRUE;
        }
    #ifdef __MMI_UC_MMS_IMG_RESOLUTION__
        else if (m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
        {
            img_resolution_need_resize = srv_uc_img_resolution_exceed_limitation(filePath);
        }
    #endif /* __MMI_UC_MMS_IMG_RESOLUTION__ */ 
    }
    if (!img_resolution_need_resize &&
        check_result.result && (MMA_RESULT_OK_WITH_WARNING_CONTENT == check_result.detail_result))
    {
        main->confirm_handler = processSelectObjectFromFmToInsert;
        m_signalShowConfirm.postEmit(STR_ID_VAPP_UC_WARNING_MODE_CONFIRM);
        return;
    }
#if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__)    
    else if (img_resolution_need_resize)
    {
        S32 fmgr_ret = 0 ;
//        srv_uc_result result;

        if (!check_result.result)
        {
     //       mmi_fmgr_util_file_limit_check2(FMGR_LIMIT_MMS_CATEGORY, (PS8) m_service_cntxt->main->file_path, &fmgr_ret);

            if (fmgr_ret < 0)
            {
                if (fmgr_ret == GDI_IMAGE_ERR_IMAGE_TOO_LARGE)
                {
                    vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_IMAGE_TOO_LARGE)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                }
                else
                {
                    vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FAILED_TO_ADD_MEDIA_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                }
                kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
                m_service_cntxt->main->file_path = NULL;
                return;
            }
        }
        vappUcResizeBeforeVerification((U16 *) m_service_cntxt->main->file_path, main->is_short);
        return;
    }
#endif    
    ucSelectObjectFromFmToInsert((U16*) m_service_cntxt->main->file_path, main->is_short);
    return;
}


#if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__) 
U16 VappUcAppData::vappUcResizeBeforeVerification(U16 *file_path, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 uc_image_path[SRV_UC_MAX_TEMP_FILE_LEN];
	S32 img_width = 0, img_height = 0;
    mma_insert_type_enum mms_type = (mma_insert_type_enum) srv_uc_convert_to_mms_insert_type(main->highlighted_object_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(uc_image_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);

    /* move file path related check to mmi_uc_select_object_from_fm_to_insert_warning_mode_check */
    /* 1. processing screen */
	gdi_image_get_dimension_file((S8*) file_path, &img_width, &img_height);
	if ((img_width != 0) && (img_height != 0))
    {
        /* calculate the dimension of the resize JPEG */
        if (applib_get_file_size(file_path) > main->image_resize_limit)
        {
            /* TODO: Show procesing screen
			mmi_uc_set_group_id();
			cui_file_selector_close(g_uc_p->main->cui_fmgr_gid);
			mmi_uc_set_processing_screen(0, STR_GLOBAL_PLEASE_WAIT, mmi_get_event_based_image(MMI_EVENT_PROGRESS), 0);
			mmi_uc_entry_processing_generic(); */
		}
	}
    /* 2. for image need resize cases, resize it to get finally file path */
    {
        S32 left_size = 0;
#ifdef __MMI_MMS_2__
        MMI_BOOL flag_for_restricted_popup = (m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED &&
                                              mms_get_max_msg_size_in_restricted_mode() <=
                                              m_service_cntxt->mms_info->max_mms_size) ? MMI_TRUE : MMI_FALSE;
        U32 max_mms_size =
            (flag_for_restricted_popup) ? mms_get_max_msg_size_in_restricted_mode() : m_service_cntxt->mms_info->
            max_mms_size;
#else
        MMI_BOOL flag_for_restricted_popup = MMI_FALSE;
        U32 max_mms_size = m_service_cntxt->mms_info->max_mms_size;
#endif


        /* in case user to select a very big image, and it will taks a lot of time just for resize once */
        if (!vappUcIsValidImage(file_path))
        {
			if(is_short != 1)
			{
				vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FAIL_TO_RESIZE_IMAGE_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
			}
            /* TODO: 
            mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_PROCESSING);
            mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_CONFIRM); */
            kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
            m_service_cntxt->main->file_path = NULL; 
            return STR_ID_VAPP_UC_FAIL_TO_RESIZE_IMAGE_ID;
        }
        /* gdi_image_get_dimension_file here should be return ok, becasue if not ok, already return in previous check */
        gdi_image_get_dimension_file(
            (PS8) file_path,
            (S32*) & (main->resized_w),
            (S32*) & (main->resized_h));

        srv_uc_make_image_file_path(uc_image_path, main->instance);

        /* the orig img file path is already kept by m_service_cntxt->main->file_path */

        left_size = main->image_resize_limit
            - mma_uc_calc_object_overhead_size(
                MMA_INSERT_IMAGE,
                (U16 *) uc_image_path,
                max_mms_size,
                srv_uc_get_mms_type(main->instance));

        if (left_size <= 0)
        {
			if(is_short != 1)
			{
            (flag_for_restricted_popup) ? vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE) :
                vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
			}
            kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
            m_service_cntxt->main->file_path = NULL;
            return (flag_for_restricted_popup) ? STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID:STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID;
        }
        main->post_handler = imageObjectVerification;
        g_app.curr_app = this;
        /* here, file path is = m_service_cntxt->main->file_path */
        if(vappUcAutoResizeImgHandler(
            main->post_handler,
            (U8*) file_path,
            uc_image_path,
            mms_type,
            main->resized_w,
            main->resized_h,
            left_size,
            MMI_TRUE))
        {
            return STR_GLOBAL_OK;
        }
        else
        {
            return STR_GLOBAL_FAILED;
        }
    }
}
#endif /* #if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__)  */

extern "C" MMI_BOOL vappUcCalImgResolution(S32 old_width, S32 old_height, S32 *new_width, S32 *new_height)
{
    if ((old_width == 1) && (old_height == 1))  /* mean already tried 1*1 but fail */
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_CAL_MG_RESOLUTION_P4, old_width, old_height, 0, 0);
        return MMI_FALSE;
    }

    *new_width = (old_width * 3) / 4;
    *new_height = (old_height * 3) / 4;

    if (*new_width == 0)
    {
        *new_width = 1;
    }

    if (*new_height == 0)
    {
        *new_height = 1;
    }
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_CAL_MG_RESOLUTION_P4, old_width, old_height, *new_width, *new_height);
    return MMI_TRUE;
}

#if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__) 
VappUcResultEnum VappUcAppData::vappUcAutoResizeImgHandler(
        vmsgc_resize_func_ptr post_handler,
        U8 *filePath,
        U8 *dest_file,
        mma_insert_type_enum mms_type,
        S32 width,
        S32 height,
        S32 left_mms_size,
        BOOL first)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 new_width = width;
    S32 new_height = height;
    S32 max_res_width = 0;
    S32 max_res_height = 0;
    S32 resize_result;
    S32 encoded_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((MMA_INSERT_IMAGE != mms_type) || (left_mms_size < 0))
    {
        ASSERT(0);
        return UC_RESULT_FAIL;
    }

    if (post_handler == NULL)
    {
        MMI_ASSERT(0);
        return UC_RESULT_FAIL;
    }
    main->resize_attempts++;
    if(first)
    {
        main->resize_attempts = 0;
    }
    /* 1. Decide the resolution W*H */
    if (!first)
    {
        if (vappUcCalImgResolution(width, height, (S32*) & new_width, (S32*) & new_height) == MMI_FALSE)
        {
            vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FAIL_TO_RESIZE_IMAGE_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
            /* TODO: 
            mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_PROCESSING);
            mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_CONFIRM); */
            if (m_service_cntxt->main->file_path)
            {
                kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
                m_service_cntxt->main->file_path = NULL;
            }
            return UC_RESULT_FAIL;
        }
    }
#ifdef __MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__
    else
    {
        MMI_BOOL local_flag = MMI_TRUE;

    #if (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __160x120__)
        {
            max_res_width = 160;
            max_res_height = 120;
        }
    #elif (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __320x240__)
        {
            max_res_width = 320;
            max_res_height = 240;
        }
    #elif (__MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ == __640x480__)
        {
            max_res_width = 640;
            max_res_height = 480;
        }
    #endif 
        while (((max_res_width * max_res_height) < (new_width * new_height)) && local_flag)
        {
            width = new_width;
            height = new_height;
            local_flag = vappUcCalImgResolution(width, height, (S32*) & new_width, (S32*) & new_height);
        }
    }
#endif /* __MMI_MMS_MAX_IMAGE_RESIZING_RESOLUTION__ */ 

    /* 2. Try to resize, encode to jpeg file, filePath should always be the orignal one which is returned by fmgr, 
       here, = m_service_cntxt->main->file_path */
    resize_result = vappUcResizeImageAndCheck(filePath, dest_file, new_width, new_height, left_mms_size, &encoded_size);

    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_AUTO_RESIZE_IMG_HDLR_P5, resize_result, new_width, new_height, left_mms_size, encoded_size);
    main->resized_w = new_width;
    main->resized_h = new_height;

    if (SRV_UC_RESIZING_ERR_SIZE_LARGER_THAN_EXPECTATION == resize_result)      /* if still larger than expected size */
    {
        if(main->resize_attempts > UC_MAX_RESIZE_ATTEMPTS)
        {
            vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FAIL_TO_RESIZE_IMAGE_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
            /* TODO: 
            mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_PROCESSING);
            mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_CONFIRM); */
            if (m_service_cntxt->main->file_path)
            {
                kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
                m_service_cntxt->main->file_path = NULL;
            }
        }
        else
        {
            main->post_handler = post_handler;
            VFX_ALLOC_NEW(main->m_timer, VfxTimer, this);
		    main->m_timer->setStartDelay(0);
		    main->m_timer->setDuration(2);
		    main->m_timer->m_signalTick.connect(this, &VappUcAppData::vappUcTimerExpiryCbk);
		    main->m_timer->start();
            return UC_RESULT_WAIT;
        }
    }
    else if (SRV_UC_RESIZING_SUCCEED == resize_result)  /* img is resized successfully and already saved to dest_file */
    {
        /* if succeed, mean the resized file is produced by vappUcResizeImageAndCheck. */
        srv_uc_update_filepath_with_string(main->instance, (S8*) dest_file);
        post_handler(MMA_INSERT_IMAGE, dest_file, (U16*) dest_file);
        return UC_RESULT_OK;
    }
    else    /* error */
    {
        {
            mmi_nmgr_balloon_type_enum type;
            WCHAR *str = vappUcGetResizeResultPopupStr((S32) resize_result, &type);
            vappUcDisplayPopup(str, type);
        }
        /* TODO: 
        mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_PROCESSING);
        mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_CONFIRM); */
        if (m_service_cntxt->main->file_path)
        {
            kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
            m_service_cntxt->main->file_path = NULL;
        }
    }
    return UC_RESULT_FAIL;
}

void VappUcAppData::vappUcTimerExpiryCbk(VfxTimer *timer)
{
	main->m_timer->stop();
    VFX_DELETE(main->m_timer);
    main->m_timer = NULL;
    if(vappUcAutoResizeImgTimeoutHandler())
    {
        vappUcRefresh((VcuiUcMainCui *)m_parent);
    }
}

VfxBool VappUcAppData::vappUcAutoResizeImgTimeoutHandler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 uc_image_path[SRV_UC_MAX_TEMP_FILE_LEN];
    S32 curr_left_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 1. use same name, because the img file still not be resized and encoded */
    memset(uc_image_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
    srv_uc_make_image_file_path(uc_image_path, main->instance);

    curr_left_size = main->image_resize_limit - mma_uc_calc_object_overhead_size(
            MMA_INSERT_IMAGE,
            (U16*) uc_image_path,
            m_service_cntxt->mms_info->max_mms_size,
            srv_uc_get_mms_type(main->instance));

    if (curr_left_size < 0)
    {
        ASSERT(0);
    }

    if(vappUcAutoResizeImgHandler(
        main->post_handler,
        m_service_cntxt->main->file_path,
        uc_image_path,
        MMA_INSERT_IMAGE,
        main->resized_w,
        main->resized_h,
        curr_left_size,
        MMI_FALSE) == UC_RESULT_OK)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}


S32 VappUcAppData::vappUcResizeImageAndCheck(
        U8 *src_file,
        U8 *dest_file,
        U32 resize_w,
        U32 resize_h,
        S32 left_mms_size,
        S32 *encoded_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 buf_size = 0;
    U8 *buf_ptr = NULL;
    S32 encoded_file_size = 0;
    GDI_RESULT gdi_ret = GDI_FAILED;
    S32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* resize the image and encode to jpeg file */
    buf_size = (resize_w * resize_h * GDI_MAINLCD_BIT_PER_PIXEL) >> 3;
    buf_size = ((buf_size + 3) / 4) * 4;
    if (buf_size > 0)
    {
        VcuiUcMainCui *app = (VcuiUcMainCui *)m_parent;
        buf_ptr = (U8 *)media_get_asm_buffer(app->getGroupId(), MOD_MMI, (void **)&buf_ptr, buf_size);
        if (buf_ptr != NULL)
        {
            if (mmi_ucs2strlen((S8*) dest_file))
            {
                FS_Delete((WCHAR*) dest_file);
            }
            gdi_ret = gdi_image_encode_file_to_jpeg_with_exp_size(
                        (S8*) src_file,
                        (S8*) dest_file,
                        resize_w,
                        resize_h,
                        buf_ptr,
                        buf_size,
                        left_mms_size,
                        &encoded_file_size);
            media_free_asm_buffer(app->getGroupId(), MOD_MMI, (void **)&buf_ptr);
        }
        else
        {   /* if the memory is not enough, treat it as disk size not enough, let it can try smaller cases. maybe the size will be enough */
            gdi_ret = GDI_IMAGE_ENCODER_ERR_SIZE_LARGER_THAN_EXPECTATION;
        }
        switch (gdi_ret)
        {
            case GDI_IMAGE_ENCODER_ERR_SIZE_LARGER_THAN_EXPECTATION:
                ret = SRV_UC_RESIZING_ERR_SIZE_LARGER_THAN_EXPECTATION;
                break;
            case GDI_SUCCEED:
                if (applib_get_file_size((kal_wchar*)dest_file) > main->image_resize_limit)
                {
                    ret = SRV_UC_RESIZING_ERR_SIZE_LARGER_THAN_EXPECTATION;
                }
                else
                {
                    ret = SRV_UC_RESIZING_SUCCEED;
                }
                break;
            case GDI_IMAGE_ENCODER_ERR_DISK_FULL:
                ret = SRV_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL;
                break;
            case GDI_IMAGE_ENCODER_ERR_WRITE_PROTECTION:
                ret = SRV_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION;
                break;
            case GDI_IMAGE_ENCODER_ERR_NO_DISK:
                ret = SRV_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK;
                break;
            default:
                ret = SRV_UC_RESIZING_FAILED_IN_GDI_FAILED;
        }
    }
    else
    {
        /* -12: can't allocate gdi_layer for drawing image */
        ret = SRV_UC_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF;
    }

    *encoded_size = encoded_file_size;
    return ret;
}
#endif /* #if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__)  */

extern "C" void imageObjectVerification(mma_insert_type_enum insert_mms_type, U8 *uc_image_path, U16* file_path)
{
    VappUcAppData* app = g_app.curr_app;
    g_app.curr_app = NULL;
    app->vappUcImageObjectVerification(insert_mms_type, uc_image_path, file_path);
}

void VappUcAppData::vappUcImageObjectVerification(mma_insert_type_enum insert_mms_type, U8 *uc_image_path, U16* file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_insert_check_struct check_result;
    mma_insert_type_enum mms_type = insert_mms_type;
    mma_insert_info_struct insert_info = {0, };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&check_result, 0, sizeof(mma_insert_check_struct));
    insert_info.creation_mode = m_service_cntxt->mms_info->creation_mode;
    insert_info.current_msg_size = 0;   /* becasue only check warning mode, no need curr size */
    insert_info.max_msg_size = m_service_cntxt->mms_info->max_mms_size - srv_uc_reserved_size(main->instance);
    insert_info.insert_type = mms_type;
    insert_info.filepath = (kal_wchar*) uc_image_path;
    insert_info.mms_type = srv_uc_get_mms_type(main->instance);

    mma_uc_insert_object_check(&insert_info, &check_result);
    if (check_result.result && (MMA_RESULT_OK_WITH_WARNING_CONTENT == check_result.detail_result))
    {
        /* TODO: Show confirm
		mmi_uc_set_group_id();
		cui_file_selector_close(g_uc_p->main->cui_fmgr_gid);
        mmi_uc_setSoftkeyFunction(
            mmi_uc_process_resized_object_to_insert,
            mmi_uc_goback_history_to_editor,
            (U8) mmi_get_event_based_sound(MMI_EVENT_QUERY),
            (U16) STR_UC_WARNING_MODE_CONFIRM);
        mmi_uc_entry_displayConfirm_generic(); */
		main->confirm_handler = processSelectObjectFromFmToInsert;
		m_signalShowConfirm.postEmit(STR_ID_VAPP_UC_WARNING_MODE_CONFIRM);
        return;
    }
    ucPostHandlerSelectObjectFromFmToInsert(insert_mms_type, m_service_cntxt->main->file_path, (U16*) m_service_cntxt->main->file_path);
    return;
}

void VappUcAppData::ucSelectObjectFromFmToInsert(U16 *filePath, S32 is_short)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_insert_type_enum mms_type = (mma_insert_type_enum)srv_uc_convert_to_mms_insert_type(main->highlighted_object_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* move file path related check to mmi_uc_select_object_from_fm_to_insert_warning_mode_check */
    /* 1. processing screen */
 /*   mmi_uc_set_processing_screen(0, STR_GLOBAL_PLEASE_WAIT, mmi_get_event_based_image(MMI_EVENT_PROGRESS), 0);
    mmi_uc_entry_processing_generic();*/
    ucPostHandlerSelectObjectFromFmToInsert(mms_type, (PU8) filePath, filePath);
    return;
}

void VappUcAppData::ucPostHandlerSelectObjectFromFmToInsert(mma_insert_type_enum mms_type, U8 *uc_image_path, U16 *filePath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 new_slide_size = 0;
    mma_mms_slide_struct *slide = m_service_cntxt->msg->msg_body.curr_slide;
    mma_insert_check_struct check_result;
    mma_mms_attachment_info_struct *att;
    mma_mms_object_struct *object = NULL;
    mma_insert_info_struct insert_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&check_result, 0, sizeof(mma_insert_check_struct));
    /* 3. calculate new_slide_size */
    switch (main->highlighted_object_type)
    {
        case SRV_UC_OBJECT_TYPE_IMAGE:
        {
            if (m_service_cntxt->msg->msg_body.curr_slide->img.object != NULL ||
                m_service_cntxt->msg->msg_body.curr_slide->vid.object != NULL)
            {

                new_slide_size = mma_uc_calc_slide_smil_size(m_service_cntxt->msg->slide_timing);
            }
        }
            break;

        case SRV_UC_OBJECT_TYPE_AUDIO:
        {
            if (m_service_cntxt->msg->msg_body.curr_slide->aud.object != NULL ||
                m_service_cntxt->msg->msg_body.curr_slide->vid.object != NULL)
            {

                new_slide_size = mma_uc_calc_slide_smil_size(m_service_cntxt->msg->slide_timing);
            }
        }
            break;

        case SRV_UC_OBJECT_TYPE_VIDEO:
        {
            if (m_service_cntxt->msg->msg_body.curr_slide->vid.object != NULL ||
                m_service_cntxt->msg->msg_body.curr_slide->img.object != NULL ||
                m_service_cntxt->msg->msg_body.curr_slide->aud.object != NULL)
            {

                new_slide_size = mma_uc_calc_slide_smil_size(m_service_cntxt->msg->slide_timing);
            }
        }
            break;

        default:
        {
            ;
        }
            break;
    }

    /* 4. really insert to uc structure */
    object = srv_uc_check_duplicate_object(main->instance, filePath);

    if (main->highlighted_object_type != SRV_UC_OBJECT_TYPE_ATTACHMENT &&
        object && object->type != SRV_UC_OBJECT_TYPE_ATTACHMENT)
    {
        U32 obj_smil_size = mma_uc_calc_object_smil_size(mms_type, filePath);
        U32 new_slide_size_tmp = new_slide_size;
        MMI_BOOL fail_in_restricted_size_check = MMI_FALSE;

        if (srv_uc_get_mms_type(main->instance) == MMA_MMS_TYPE_MIXED_MMS)
        {
            new_slide_size_tmp = 0;
        }

        /* only affect size check, still insert slide as usual */
        if (!srv_uc_check_if_exceed_MMS_size_limitation
            (main->instance, obj_smil_size + new_slide_size_tmp + m_service_cntxt->msg->msg_size,
             &fail_in_restricted_size_check))
        {
            if (new_slide_size > 0)
            {
                slide = srv_uc_insert_slide(main->instance, m_service_cntxt->msg->msg_body.curr_slide);
                ucHandleTextInCurrentSlide(); /* we can force call too. But put here to see switchSlide call as generic. *///vikas
                m_service_cntxt->msg->msg_body.curr_slide = slide;
                m_service_cntxt->msg->current_slide_num = (U8)slide->slide_num;
            }

            srv_uc_insert_object_to_slide(main->instance, object, slide, main->highlighted_object_type);
        }
        else
        {
            (fail_in_restricted_size_check) ? vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE) :
                vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
            /* TODO:
            mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_PROCESSING);
            mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_CONFIRM); */
            kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
            m_service_cntxt->main->file_path = NULL;
            main->post_handler = NULL;
            return;
        }
    }
    else
    {

        insert_info.creation_mode = m_service_cntxt->mms_info->creation_mode;
        if (srv_uc_get_mms_type(main->instance) == MMA_MMS_TYPE_MIXED_MMS)
        {
            insert_info.current_msg_size = m_service_cntxt->msg->msg_size;
        }
        else
        {
            insert_info.current_msg_size = m_service_cntxt->msg->msg_size + new_slide_size;
        }
        insert_info.max_msg_size = m_service_cntxt->mms_info->max_mms_size - srv_uc_reserved_size(main->instance);
        insert_info.insert_type = mms_type;
        insert_info.filepath = (kal_wchar*) filePath;
        insert_info.mms_type = srv_uc_get_mms_type(main->instance);

        mma_uc_insert_object_check(&insert_info, &check_result);

#ifdef __MMI_EMAIL__
    if (m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
#endif
	{
        if (!(check_result.result))
        {
            srv_uc_result result;

            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_INSERT_OBJECT_CHECK_FAIL_FMGR);

            result = srv_uc_convert_mms_check_result(&check_result);
            {
                mmi_nmgr_balloon_type_enum type;
                WCHAR *str = vappUcGetSrvResultPopupStr(result, &type);
                vappUcDisplayPopup(str, type);
            }
            /* TODO: Show popup
            mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_PROCESSING); */
            if (mmi_ucs2strlen((S8*) uc_image_path) &&
                srv_uc_is_resized_image((U16*) uc_image_path, main->instance) == MMI_TRUE)
            {
                FS_Delete((WCHAR*) uc_image_path);
            }

            // TODO: mmi_frm_scrn_close(g_uc_p->main->uc_cui_gid, SCR_ID_UC_CONFIRM);
            kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
            m_service_cntxt->main->file_path = NULL;
            main->post_handler = NULL;
            return;
        }
	}

        if (new_slide_size > 0)
        {
            slide = srv_uc_insert_slide(main->instance, m_service_cntxt->msg->msg_body.curr_slide);
            ucHandleTextInCurrentSlide(); /* we can force call too. But put here to see switchSlide call as generic. *///vikas
            m_service_cntxt->msg->msg_body.curr_slide = slide;
            m_service_cntxt->msg->current_slide_num = (U8)slide->slide_num;
        }

        object = srv_uc_insert_object(main->instance, (S8*) filePath, main->highlighted_object_type);
        object->auto_delete_file = (kal_bool)m_service_cntxt->main->auto_delete_file;
        m_service_cntxt->main->auto_delete_file = FALSE;
        object->drm_type = check_result.drm_type;

        if (main->highlighted_object_type == SRV_UC_OBJECT_TYPE_ATTACHMENT)
        {
        #ifdef __MMI_UC_REF__
            if (srv_uc_is_in_ref_obj_type_range((S8*) filePath))
            {

                mma_mms_slide_ref_object_struct *new_ref_obj_info;

                /* do not care id, so set 0 here */
                new_ref_obj_info = srv_uc_insert_ref_obj_info_to_tail(
                                    main->instance,
                                    slide,
                                    0,
                                    SRV_UC_INVALID_VALUE,
                                    SRV_UC_INVALID_VALUE);

                /* associate real object and the new ref obj info */
                new_ref_obj_info->object = object;
                object->reference_count++;
            }
            else
        #endif /* __MMI_UC_REF__ */ 
            {
                att = srv_uc_insert_attachment(main->instance);
                srv_uc_insert_object_to_attachment(object, att);
            }
        }
        else
        {
            srv_uc_insert_object_to_slide(main->instance, object, slide, main->highlighted_object_type);
        }
    }
    /* 5. fmgr */
//    cui_file_selector_close(g_uc_p->main->cui_fmgr_gid);

    /* 6. Determine layout */
    if (main->highlighted_object_type == SRV_UC_OBJECT_TYPE_IMAGE ||
        main->highlighted_object_type == SRV_UC_OBJECT_TYPE_VIDEO)
    {
        if (m_service_cntxt->msg->msg_body.layout == MMA_LAYOUT_NONE)
        {
            if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count)
            {
                m_service_cntxt->msg->msg_body.layout = MMA_LAYOUT_TEXT_ON_TOP;
            }
            else
            {
                m_service_cntxt->msg->msg_body.layout = MMA_LAYOUT_IMAGE_ON_TOP;
            }
        }
    }

    /* 7-1. check signature -1 */
    changeMsgTypeIfNeeded();
    if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
    {
        m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
    }
    srv_uc_update_msg_size(main->instance);

    /* 8. update wgui info */
    if (new_slide_size)
    {
        switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
    }
    else
    {
        /* TODO: 
        mmi_uc_editor_initialize();
        mmi_uc_set_editor_info(m_service_cntxt->msg->msg_body.curr_slide); */
    }

    /* TODO: */
    //mmi_uc_set_group_id();
    //cui_file_selector_close(main->cui_gid);
    m_signalConnectOnPage.postEmit();
//    m_signalConenctOnPage.postEmit();
    /* 10. free memory */
    if (m_service_cntxt->main->file_path)
    {
        kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
        m_service_cntxt->main->file_path = NULL;
        main->post_handler = NULL;
    }

    if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
    {
        m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
    }
    return;
}


void VappUcAppData::ucSelectObjectFromFmToReplaceWarningModeCheck(U16 *filePath, S32 is_short)
{
}

void VappUcAppData::VappUCRemoveMedia(mma_mms_object_struct *obj)
{
    mma_mms_viewer_object_type_enum obj_type = (mma_mms_viewer_object_type_enum)obj->type;

	switch (obj_type)
	{
	case SRV_UC_OBJECT_TYPE_IMAGE:
		if(srv_uc_is_resized_image((U16*)(obj->file_path_ucs), main->instance))
		{        
			FS_Delete((const WCHAR *)(obj->file_path_ucs));
		}
		memset(&m_service_cntxt->msg->msg_body.curr_slide->img, 0, sizeof(mma_mms_slide_object_struct));
		break;
	case SRV_UC_OBJECT_TYPE_AUDIO:
		memset(&m_service_cntxt->msg->msg_body.curr_slide->aud, 0, sizeof(mma_mms_slide_object_struct));
		break;
	case SRV_UC_OBJECT_TYPE_VIDEO:
		memset(&m_service_cntxt->msg->msg_body.curr_slide->vid, 0, sizeof(mma_mms_slide_object_struct));
		break;
	default:
		break;
	}
    
    if (obj->reference_count > 1)
    {
        obj->reference_count--;
    }
    else
    {
        srv_uc_delete_object_from_list(main->instance, obj);
    }

    changeMsgTypeIfNeeded();
	ucHandleTextInCurrentSlide(); /* we can force call too. But put here to see switchSlide call as generic. *///vikas
    if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
    {
        m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
    }
    srv_uc_update_msg_size(main->instance);
}


void VappUcAppData::VappUCRemoveAttachment(VfxId index)
{
#if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__)
	applib_mime_type_struct *mime = NULL;
#endif
	VfxBool shouldDelete = VFX_FALSE;

	/* List == ref list + attachment list */
    /* 1. REF */
    if (index < m_service_cntxt->msg->msg_body.total_ref_no)
    {
        /* selected object in the list is ref object */
        mma_mms_slide_ref_object_struct *ref = srv_uc_get_ref_by_index(main->instance, index);
        /* because ref, could be multiple refereced */

        if (ref->object->reference_count > 1)
        {
            ref->object->reference_count--;
        }
        else
        {
            srv_uc_delete_object_from_list(main->instance, ref->object);
        }

        /* remove it from slide structure */
        srv_uc_delete_ref_by_index(main->instance, index);

    }
    /* 2. Attachment */
    else
    {
        /* selected object in the list is attach object */

        mma_mms_attachment_info_struct *att = srv_uc_get_attachment_by_index(
                                                main->instance,
                                                (U16) (index - m_service_cntxt->msg->msg_body.total_ref_no));

		ASSERT(att);
		//ASSERT(att->object->reference_count == 1); 
		
    #if defined(__MMI_VCARD__) || defined(__MMI_VCALENDAR__)
		mime = applib_mime_get_file_type(att->object->file_name_ucs);
    #endif

    #if defined(__MMI_VCARD__)
		if (mime && (mime->mime_subtype == MIME_SUBTYPE_XVCARD ||
			mime->mime_subtype == MIME_SUBTYPE_VCARD))

	    {
		    shouldDelete = VFX_TRUE;
	    }
    #endif

    #if defined(__MMI_VCALENDAR__)
	    if (mime!= NULL && (mime->mime_subtype == MIME_SUBTYPE_XVCALENDAR ||
		    mime->mime_subtype == MIME_SUBTYPE_HBSVCS ||
		    mime->mime_subtype == MIME_SUBTYPE_CALENDAR))
	    {
		    shouldDelete = VFX_TRUE;
	    }
    #endif    
	    if (shouldDelete)
	    {
			VfxWChar *folderName = NULL;
			
			VFX_SYS_ALLOC_MEM(folderName, MMA_MAX_EXTERNAL_FILE_PATH_LEN);
			memset(folderName, 0x0, MMA_MAX_EXTERNAL_FILE_PATH_LEN);
				

			kal_wsprintf(
				(kal_uint16*) folderName,
				"%c:\\%s%03d\\",
				SRV_UC_FOLDER_DRV,
				SRV_UC_FOLDER_NAME,
				main->instance);
			if (app_ucs2_strstr((kal_wchar*) att->object->file_path_ucs, (kal_wchar*)folderName))
			{
				FS_Delete((WCHAR*)att->object->file_path_ucs);
			}
			VFX_FREE_MEM(folderName);
		}
	#ifdef __MMI_EMAIL__
		if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
		{
			vapp_uc_media_info mediaInfo;
			memset(&mediaInfo, 0, sizeof(vapp_uc_media_info));
			mediaInfo.file_name = att->object->file_name_ucs;
			mediaInfo.file_path = att->object->file_path_ucs;
			if (VappEmailComp::removeAttch(&mediaInfo, main->callback_para) != VappEmailComp::SUCC)
			{
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(L"Fail to remove!"));
				return;
			}
		}
	#endif

		srv_uc_delete_object_from_list(main->instance, att->object);
		srv_uc_delete_attachment_from_list(main->instance, att);
		changeMsgTypeIfNeeded();
		ucHandleTextInCurrentSlide(); /* we can force call too. But put here to see switchSlide call as generic. *///vikas
	    if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
        {
            m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
        }
		srv_uc_update_msg_size(main->instance);
    }
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
#endif


extern "C" void ucSetTextInfoToSlide(mma_mms_slide_struct *slide, VappUcTextInfoStruct *text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    slide->txt.char_count = text_info->char_count;
    slide->txt.UCS2_count = text_info->UCS2_count;
    slide->txt.utf8_msg_len = text_info->utf8_msg_len;
    slide->txt.extension_char_count = text_info->extension_char_count;
}


S32 VappUcAppData::ucMatchObjectId(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *cur_slide = m_service_cntxt->msg->msg_body.slides;
    U32 slide_num = 0;
    U32 temp_size = 0;
    mma_mms_object_struct *cur_object = NULL;
    S32 error = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; cur_slide != NULL; cur_slide = cur_slide->next, slide_num++)
    {

        if (cur_slide->txt.id)
        {
            VappUcTextInfoStruct text_info;
            U8 mmi_uc_text_path[SRV_UC_MAX_TEMP_FILE_LEN];
            U8 virtual_file_name[(FS_GenVFN_SIZE + 1) * ENCODING_LENGTH];
            S32 ori_file_handle;
            S32 result;
            U8 *file_name;

        #ifdef __MMI_MMS_2__
            S32 start_time = cur_slide->txt.begin;
            S32 end_time = cur_slide->txt.end;
        #endif /* __MMI_MMS_2__ */ 
            U32 bg_color = cur_slide->txt.bg_color;
            U32 fg_color = cur_slide->txt.fg_color;
            U16 file_path_len = 0;
            U16 file_name_len = 0;
			U16 msg_char_count = 0 ;

            memset(mmi_uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
            SRV_UC_MAKE_TEXT_FILE_PATH(mmi_uc_text_path, cur_slide->slide_num, main->instance);

            /* the object maybe reomoved because creation mode (reference and removed in previous slide) */
            cur_object = srv_uc_get_object_by_id(main->instance, cur_slide->txt.id);

            if (cur_object == NULL) /* the object is removed from object list when handling previous page--creation mode */
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_ALREADY_REMOVED_TEXT);
                memset(&(cur_slide->txt), 0, sizeof(mma_mms_slide_object_struct));
                return FS_ERROR_RESERVED;
            }
            else if (cur_object->reference_count > 0)   /* same text obj is refered more than once */
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_REF_MORE_TEXT);
                memset(&(cur_slide->txt), 0, sizeof(mma_mms_slide_object_struct));
                return FS_ERROR_RESERVED;
            }
        #ifdef __MMI_MMS_2__
            /* first handled and object exists */
            else if (MMI_FALSE == srv_uc_check_virtual_file_object_for_creation_mode(
                                    main->instance,
                                    cur_object,
                                    SRV_UC_OBJECT_TYPE_TEXT))
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_FIRST_HANDLED_TEXT);
                srv_uc_delete_object_from_list(main->instance, cur_object);
                memset(&(cur_slide->txt), 0, sizeof(mma_mms_slide_object_struct));
            }
        #endif /* __MMI_MMS_2__ */ 
            else    /* already handled before and passed creation mode check */
            {
                if (cur_slide->txt.object->is_virtual_file)
                {
                    ori_file_handle = FS_Open(cur_slide->txt.object->file_path_ucs, FS_READ_ONLY | FS_OPEN_SHARED);

                    if (ori_file_handle <= 0)
                    {
                        ASSERT(0);
                        return ori_file_handle;
                    }

                    result = FS_GenVirtualFileName(
                                ori_file_handle,
                                (U16*) virtual_file_name,
                                (unsigned int)FS_GenVFN_SIZE,
                                cur_slide->txt.object->offset,
                                cur_slide->txt.object->size);

                    if (result < 0)
                    {
                        ASSERT(0);
                        return result;
                    }

                    srv_uc_read_file_to_text_buffer(
                        main->instance,
                        virtual_file_name,
                        cur_slide->txt.object->encoding);

                    FS_Close(ori_file_handle);

                }
                else
                {
                    srv_uc_read_file_to_text_buffer(main->instance, (U8*) cur_slide->txt.object->file_path_ucs, 0);
                }

                msg_char_count = mmi_ucs2strlen((S8*) m_service_cntxt->main->text_buffer) ;

				if(msg_char_count == 0)
				{
					srv_uc_delete_object_from_list(main->instance, cur_object);
					memset(&(cur_slide->txt), 0, sizeof(mma_mms_slide_object_struct));
				}
				else
				{
					srv_uc_insert_object_to_slide(main->instance, cur_object, cur_slide, SRV_UC_OBJECT_TYPE_TEXT);
					cur_slide->txt.object->type = MMA_MMS_OBJECT_TYPE_TEXT;

				#ifdef __MMI_MMS_2__
					if (start_time != 0 || end_time != 0)
					{
						cur_slide->txt.begin = start_time;
						cur_slide->txt.end = end_time;
					}
				#endif /* __MMI_MMS_2__ */ 

					cur_slide->txt.bg_color = bg_color;
					cur_slide->txt.fg_color = fg_color;
					ASSERT(cur_slide->txt.object->file_path_ucs);

			#ifdef __MMI_EMAIL__
						if (m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
			#endif /*__MMI_EMAIL__*/
						{
							if(msg_char_count > UC_MMS_MAX_TEXT_CHAR_COUNT)
							{
                                VfxU32 max_pos,pos1,pos2;
                                pos1 = SRV_UC_TEXT_BUFFER_SIZE - 4;
                                pos2 = UC_MMS_MAX_TEXT_CHAR_COUNT * 2;
                                max_pos = (pos1<pos2) ? (pos1) : (pos2);
								m_service_cntxt->main->text_buffer[max_pos] = '\0' ;
								m_service_cntxt->main->text_buffer[max_pos + 1] = '\0' ;
								m_service_cntxt->main->text_buffer[max_pos + 2] = '\0' ;

							}
						}
					memset(&text_info, 0, sizeof(VappUcTextInfoStruct));
					ucGetTextInfoForBuffer(&text_info, m_service_cntxt->main->text_buffer);

					ucSetTextInfoToSlide(cur_slide, &text_info);

					/* should not return here, or the fle name will not be updated to UC's path. If srv_uc_reset_msg is called
					   will remove mms real body */
					result = srv_uc_save_buffer_to_file(
								main->instance,
								mmi_uc_text_path,
								m_service_cntxt->main->text_buffer,
								text_info.char_count);

					cur_slide->txt.object->encoding = MMA_CHARSET_UTF8;    /* because the text's encode already UTF8 when srv_uc_save_buffer_to_file to file */
					/* file path */
					kal_adm_free(main->mem_pool_id, cur_slide->txt.object->file_path_ucs);
					file_path_len = mmi_ucs2strlen((S8*) mmi_uc_text_path);
					cur_slide->txt.object->file_path_ucs = (U16 *)kal_adm_alloc(main->mem_pool_id, (file_path_len + 1) * 2);
					ASSERT(cur_slide->txt.object->file_path_ucs);
					memset(cur_slide->txt.object->file_path_ucs, 0, (file_path_len + 1) * 2);
					mmi_ucs2ncpy((S8*) cur_slide->txt.object->file_path_ucs, (S8*) mmi_uc_text_path, file_path_len);

					/* file name */
					if (cur_slide->txt.object->file_name_ucs)
					{
						kal_adm_free(main->mem_pool_id, cur_slide->txt.object->file_name_ucs);
					}
					file_name = (U8*) srv_uc_get_file_name((U16*) mmi_uc_text_path);
					file_name_len = mmi_ucs2strlen((S8*) file_name);
					cur_slide->txt.object->file_name_ucs = (U16 *)kal_adm_alloc(main->mem_pool_id, (file_name_len + 1) * 2);
					ASSERT(cur_slide->txt.object->file_name_ucs);
					memset(cur_slide->txt.object->file_name_ucs, 0, (file_name_len + 1) * 2);
					mmi_ucs2ncpy((S8*) cur_slide->txt.object->file_name_ucs, (S8*) file_name, file_name_len);

					cur_slide->txt.object->offset = 0;
					temp_size = applib_get_file_size((kal_wchar*) cur_slide->txt.object->file_path_ucs);
					if (temp_size < cur_slide->txt.object->size &&
						text_info.char_count == SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE)
					{
						m_service_cntxt->send_info->content_truncated_type = srv_uc_msg_truncation_type_enum((U16)m_service_cntxt->send_info->content_truncated_type | (U16)SRV_UC_TRUNCATED_TYPE_TEXT);
					}
					cur_slide->txt.object->size = temp_size;
					cur_slide->txt.object->drm_type = MMA_DRM_NONE;
					cur_slide->txt.object->is_virtual_file = MMI_FALSE;
					if (result != FS_NO_ERROR)
					{
						error = result;
					}
				}
            }
        }

        if (cur_slide->img.id)
        {
            cur_object = srv_uc_get_object_by_id(main->instance, cur_slide->img.id);

            if (cur_object != NULL)
            {
            #ifdef __MMI_MMS_2__
                if (MMI_FALSE == srv_uc_check_virtual_file_object_for_creation_mode(
                                    main->instance,
                                    cur_object,
                                    SRV_UC_OBJECT_TYPE_IMAGE))
                {

                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_REMOVE_IMG);
                    srv_uc_delete_object_from_list(main->instance, cur_object);
                    memset(&(cur_slide->img), 0, sizeof(mma_mms_slide_object_struct));
                }
                else
            #endif /* __MMI_MMS_2__ */ 
                {
                #ifdef __MMI_MMS_2__
                    S32 start_time = cur_slide->img.begin;
                    S32 end_time = cur_slide->img.end;
                #endif /* __MMI_MMS_2__ */ 

                    srv_uc_insert_object_to_slide(
                        main->instance,
                        cur_object,
                        cur_slide,
                        SRV_UC_OBJECT_TYPE_IMAGE);
                    cur_slide->img.object->type = SRV_UC_OBJECT_TYPE_IMAGE;

                #ifdef __MMI_MMS_2__
                    if (start_time != 0 || end_time != 0)
                    {
                        cur_slide->img.begin = start_time;
                        cur_slide->img.end = end_time;
                    }
                #endif /* __MMI_MMS_2__ */ 

                }
            }
            else    /* the object is removed from object list when handling previous page--creation mode */
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_REMOVE_BEFORE_IMG);
                memset(&(cur_slide->img), 0, sizeof(mma_mms_slide_object_struct));
            }
        }
        if (cur_slide->aud.id)
        {
            cur_object = srv_uc_get_object_by_id(main->instance, cur_slide->aud.id);

            if (cur_object != NULL)
            {
            #ifdef __MMI_MMS_2__
                if (MMI_FALSE == srv_uc_check_virtual_file_object_for_creation_mode(
                                    main->instance,
                                    cur_object,
                                    SRV_UC_OBJECT_TYPE_AUDIO))
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_REMOVE_AUDIO);
                    srv_uc_delete_object_from_list(main->instance, cur_object);
                    memset(&(cur_slide->aud), 0, sizeof(mma_mms_slide_object_struct));
                }
                else
            #endif /* __MMI_MMS_2__ */ 
                {
                #ifdef __MMI_MMS_2__
                    S32 start_time = cur_slide->aud.begin;
                    S32 end_time = cur_slide->aud.end;
                #endif /* __MMI_MMS_2__ */ 

                    srv_uc_insert_object_to_slide(
                        main->instance,
                        cur_object,
                        cur_slide,
                        SRV_UC_OBJECT_TYPE_AUDIO);
                    cur_slide->aud.object->type = SRV_UC_OBJECT_TYPE_AUDIO;

                #ifdef __MMI_MMS_2__
                    if (start_time != 0 || end_time != 0)
                    {
                        cur_slide->aud.begin = start_time;
                        cur_slide->aud.end = end_time;
                    }
                #endif /* __MMI_MMS_2__ */ 
                }
            }
            else    /* the object is removed from object list when handling previous page--creation mode */
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_REMOVE_AUDIO);
                memset(&(cur_slide->aud), 0, sizeof(mma_mms_slide_object_struct));
            }
        }
        if (cur_slide->vid.id)
        {
            cur_object = srv_uc_get_object_by_id(main->instance, cur_slide->vid.id);

            if (cur_object != NULL)
            {
            #ifdef __MMI_MMS_2__
                if (MMI_FALSE == srv_uc_check_virtual_file_object_for_creation_mode(
                                    main->instance,
                                    cur_object,
                                    SRV_UC_OBJECT_TYPE_VIDEO))
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_REMOVE_VEDIO);
                    srv_uc_delete_object_from_list(main->instance, cur_object);
                    memset(&(cur_slide->vid), 0, sizeof(mma_mms_slide_object_struct));
                }
                else
            #endif /* __MMI_MMS_2__ */ 
                {
                #ifdef __MMI_MMS_2__
                    S32 start_time = cur_slide->vid.begin;
                    S32 end_time = cur_slide->vid.end;
                #endif /* __MMI_MMS_2__ */ 

                    srv_uc_insert_object_to_slide(
                        main->instance,
                        cur_object,
                        cur_slide,
                        SRV_UC_OBJECT_TYPE_VIDEO);
                    cur_slide->vid.object->type = SRV_UC_OBJECT_TYPE_VIDEO;

                #ifdef __MMI_MMS_2__
                    if (start_time != 0 || end_time != 0)
                    {
                        cur_slide->vid.begin = start_time;
                        cur_slide->vid.end = end_time;
                    }
                #endif /* __MMI_MMS_2__ */ 
                }
            }
            else
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_REMOVE_BEFORE_VEDIO);
                memset(&(cur_slide->vid), 0, sizeof(mma_mms_slide_object_struct));
            }
        }

        /* ref */
        {
            mma_mms_slide_ref_object_struct *cur_ref = cur_slide->ref_items;
            mma_mms_slide_ref_object_struct *next_ref = NULL;

            while (cur_ref)
            {
                cur_object = srv_uc_get_object_by_id(main->instance, cur_ref->id);

                if (cur_object != NULL)
                {
                #ifdef __MMI_MMS_2__
                    /* ref will be treated as attachment */
                    if (MMI_FALSE == srv_uc_check_virtual_file_object_for_creation_mode(
                                        main->instance,
                                        cur_object,
                                        SRV_UC_OBJECT_TYPE_ATTACHMENT))
                    {
                        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_REMOVE_REF);
                        /* remove it from object list */
                        srv_uc_delete_object_from_list(main->instance, cur_object);
                        /* remove it from slide structure */
                        if (cur_slide->ref_items == cur_ref)
                        {
                            cur_slide->ref_items = cur_ref->next;

                            if (cur_ref->next)
                            {
                                cur_ref->next->prev = NULL;
                            }
                            m_service_cntxt->msg->msg_body.total_attach_no--;
                            next_ref = cur_ref->next;
                            kal_adm_free(main->mem_pool_id, cur_ref);
                        }
                        else
                        {
                            next_ref = cur_ref->next;
                            srv_uc_delete_ref_obj_info_from_list(main->instance, cur_ref);
                        }

                    }
                    else
                #endif /* __MMI_MMS_2__ */ 
                    {
                    #ifdef __MMI_MMS_2__
                        S32 start_time = cur_ref->begin;
                        S32 end_time = cur_ref->end;
                    #endif /* __MMI_MMS_2__ */ 
                        /* associate obj(in slide) to obj(in obj list) */
                        cur_ref->object = cur_object;
                        cur_ref->begin = SRV_UC_INVALID_VALUE;
                        cur_ref->end = SRV_UC_INVALID_VALUE;
                        cur_object->reference_count++;
                        cur_ref->object->type = SRV_UC_OBJECT_TYPE_REF;

                    #ifdef __MMI_MMS_2__
                        if (start_time != 0 || end_time != 0)
                        {
                            cur_ref->begin = start_time;
                            cur_ref->end = end_time;
                        }
                    #endif /* __MMI_MMS_2__ */ 
                        next_ref = cur_ref->next;
                    }
                }
                else
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_REMOVE_BEFORE_VEDIO);
                    /* remove it from slide sturture. because can not find the mapping */
                    if (cur_slide->ref_items == cur_ref)
                    {
                        cur_slide->ref_items = cur_ref->next;

                        if (cur_ref->next)
                        {
                            cur_ref->next->prev = NULL;
                        }

                        m_service_cntxt->msg->msg_body.total_attach_no--;

                        next_ref = cur_ref->next;
                        kal_adm_free(main->mem_pool_id, cur_ref);
                    }
                    else
                    {
                        next_ref = cur_ref->next;
                        srv_uc_delete_ref_obj_info_from_list(main->instance, cur_ref);
                    }
                }
                cur_ref = next_ref;
            }

        }   /* ref */

        if (m_service_cntxt->msg->msg_body.layout == MMA_LAYOUT_NONE)
        {
            if (cur_slide->img.object || cur_slide->vid.object)
            {
                m_service_cntxt->msg->msg_body.layout = MMA_LAYOUT_IMAGE_ON_TOP;
            }
        }
    }

    ASSERT(slide_num == m_service_cntxt->msg->msg_body.slide_no);

#ifdef __MMI_MMS_2__
    {
        mma_mms_attachment_info_struct *cur_attach = m_service_cntxt->msg->msg_body.attachment;
        mma_mms_attachment_info_struct *next_attach = NULL;
        for (; cur_attach != NULL; cur_attach = next_attach)
        {
            cur_object = cur_attach->object;
            next_attach = cur_attach->next;
            if (MMI_FALSE == srv_uc_check_virtual_file_object_for_creation_mode(
                                main->instance,
                                cur_attach->object,
                                SRV_UC_OBJECT_TYPE_ATTACHMENT))
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_MATCH_OBJ_ID_REMOVE_ATTACH);
                srv_uc_delete_object_from_list(main->instance, cur_object);
                srv_uc_delete_attachment_from_list(main->instance, cur_attach);
            }
        }
    }
#endif /* __MMI_MMS_2__ */ 
    return error;
}

#ifdef __MMI_UC_SUB_PREFIX_MMS__

VfxBool VappUcAppData::vappUcIsPrefixAlreadyExist(srv_uc_state_enum state, S8 *ucs2_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 *pPrefixStr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((state != SRV_UC_STATE_FORWARD) && (state != SRV_UC_STATE_REPLY) && (state != SRV_UC_STATE_REPLY_ALL)
        && (m_service_cntxt->main->mode == SRV_UC_NORMAL_EDIT_MODE))
    {
        ASSERT(0);
        return VFX_TRUE;
    }

    if (ucs2_string == NULL)
    {
        return VFX_FALSE;
    }

    if (SRV_UC_STATE_FORWARD == state || m_service_cntxt->main->mode != SRV_UC_NORMAL_EDIT_MODE)
    {
        pPrefixStr = GetString(STR_ID_VAPP_UC_FW_ID);
    }
    else
    {
        pPrefixStr = GetString(STR_ID_VAPP_UC_RE_ID);
    }

    if (!mmi_ucs2ncmp(ucs2_string, pPrefixStr, mmi_ucs2strlen(pPrefixStr)))     /* no prefix in ucs2_string */
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;

}

void VappUcAppData::vappUcAddPrefixBeforeSubject(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 *pSubject_Prefix = NULL;
    U16 subject_buff[SRV_UC_MAX_SUBJECT_LEN + 1];   /* UCS2 */
    int prefix_char_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ADD_PREFIX_BEFORE_SUBJECT_P1, m_service_cntxt->main->state);

    if ((SRV_UC_STATE_FORWARD != m_service_cntxt->main->state) &&
        (SRV_UC_STATE_REPLY != m_service_cntxt->main->state) &&
        (SRV_UC_STATE_REPLY_ALL != m_service_cntxt->main->state)
        && m_service_cntxt->main->mode == SRV_UC_NORMAL_EDIT_MODE)
    {
        return;
    }

    if (MMI_TRUE == vappUcIsPrefixAlreadyExist(m_service_cntxt->main->state, (S8*) m_service_cntxt->msg->subject))
    {
        return;
    }
    /* add prefix */
    memset(subject_buff, 0, sizeof(subject_buff));

    mmi_ucs2ncpy((S8*) subject_buff, (S8*) m_service_cntxt->msg->subject, SRV_UC_MAX_SUBJECT_LEN);

    memset(m_service_cntxt->msg->subject, 0, sizeof(m_service_cntxt->msg->subject));

    if (SRV_UC_STATE_FORWARD == m_service_cntxt->main->state
        || m_service_cntxt->main->mode != SRV_UC_NORMAL_EDIT_MODE)
    {
        pSubject_Prefix = GetString(STR_ID_VAPP_UC_FW_ID);
    }
    else
    {
        pSubject_Prefix = GetString(STR_ID_VAPP_UC_RE_ID);
    }

    prefix_char_num = mmi_ucs2strlen(pSubject_Prefix);

    mmi_ucs2ncpy((S8*) m_service_cntxt->msg->subject, pSubject_Prefix, prefix_char_num);

    mmi_ucs2ncat(
        (S8*) m_service_cntxt->msg->subject,    /* m_service_cntxt->msg->subject: MMI_UC_MAX_SUBJECT_LEN+1 */
        (const S8*)subject_buff,
        SRV_UC_MAX_SUBJECT_LEN - prefix_char_num);
    return;
}
#endif /* __MMI_UC_SUB_PREFIX_MMS__ */

S32 VappUcAppData::ucParseMmsXmlDescriptionFile(void)
{
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
#endif
    {
        S32 match_obj_result = ucMatchObjectId();

        /* Add prefix RE: for reply msg and FW: for forward msg */
        /* Only add that for MMS, because SMS has no subject */
    #ifdef __MMI_UC_SUB_PREFIX_MMS__
    #ifndef __MMI_MMS_STANDALONE_COMPOSER__
    //#ifndef __MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__
        if (determineMsgTypeByContent() == SRV_UC_MSG_TYPE_MMS_PREFER)
    //#endif 
    #endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
            vappUcAddPrefixBeforeSubject();
    #endif /* __MMI_UC_SUB_PREFIX_MMS__ */ 

        if (FS_NO_ERROR == match_obj_result)
        {
            return SRV_UC_OK;
        }
        else if (FS_ERROR_RESERVED == match_obj_result) /* mean text obj is refered more than once */
        {
            return SRV_UC_NOT_SUPPORT;
        }
        else
        {
            return SRV_UC_STORAGE_FULL;
        }
    }
}
extern "C" void ucFreeAddrMemOfMmaAddr(mma_mms_addr_list_struct *mma_addr, void* user_data)
{
	mma_mms_addr_list_struct *temp_addr = NULL ;
	VappUcAppData *app = (VappUcAppData*)user_data;
	while(mma_addr)
	{
		temp_addr = mma_addr ;
		mma_addr = mma_addr->next ;
		ucSrvFreeMemCbk(temp_addr->address, (void *)(app->main->mem_pool_id));
		ucSrvFreeMemCbk(temp_addr, (void *)(app->main->mem_pool_id));
		temp_addr = NULL ;
	}

}

#ifdef __MMI_MMS_2__
extern "C" void ucGetMmsContentRsp(srv_mms_result_enum mms_result, void *rsp_data, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappUcAppData *app = (VappUcAppData*)user_data;
#ifndef __MMI_MMS_USE_ASM__
    VcuiUcMainCui *cui ;
#endif
    srv_mms_get_content_rsp_struct *msg_rsp = (srv_mms_get_content_rsp_struct*) rsp_data;
	mma_mms_description_struct *comp_msg = (mma_mms_description_struct *)msg_rsp->content_info;
    srv_uc_result result = SRV_UC_OK;
	/*xml_removal code added here*/
	/*begin*/
	mma_app_mode_enum app_mode ;
    mma_mms_description_header_struct *get_mms_header = (mma_mms_description_header_struct *)comp_msg->header;
	mma_mms_description_body_struct *get_mms_body = (mma_mms_description_body_struct *)comp_msg->body;
	
	/*end*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!vappUcCheckAppSanity((void *)app))
    {
        return;
    }
    else if(app->wait_to_close == VFX_TRUE)
    {
    #ifdef __MMI_MMS_USE_ASM__
        /* we are expecting mms service will send  event: EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE later then UC will terminate */   
        return ;
    #else
        app->wait_to_close = VFX_FALSE;
        VcuiUcMainCui *m_app = (VcuiUcMainCui *)(app->m_parent);
        m_app->vappUcTerminate();
        return ;
    #endif
    }
    app->is_mma_active = VFX_FALSE ;

#ifndef __MMI_MMS_USE_ASM__
	cui = (VcuiUcMainCui *)app->m_parent; 
#endif
    app->m_service_cntxt->msg->g_msg_header.header = &(app->m_service_cntxt->msg->msg_header);
	
    ASSERT(msg_rsp->msg_id == app->m_service_cntxt->send_info->existed_msg_id);
    //ASSERT(msg_rsp->buffer_index == app->m_service_cntxt->send_info->buffer_index);

    if (msg_rsp->result != MMA_RESULT_OK)
    {
        {
            mmi_nmgr_balloon_type_enum type;
            WCHAR *str = vappUcGetMmaResultPopupStr((mma_result_enum)msg_rsp->result, &type);
            vappUcDisplayPopup(str, type);
        }
        #ifdef __MMI_MMS_USE_ASM__
            /* we are expecting mms service will send  event: EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE later then UC will terminate */   
            app->wait_to_close = VFX_TRUE;    
            return ;
        #else
            cui->vappUcTerminate();
        #endif
        /* TODO: Error handling
        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING); */

    }
    else
    {
        app->m_service_cntxt->msg->msg_body_size = msg_rsp->mms_body_size;
        app->m_service_cntxt->msg->msg_size = msg_rsp->mms_header_size + msg_rsp->mms_body_size;

        {
            MMI_BOOL fail_in_restricted_size_check = MMI_FALSE;

        #ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
            /* Check require only to disallow large MMS to send or FW only */
            U32 max_size = app->m_service_cntxt->mms_info->max_mms_size;
            result = SRV_UC_SIZE_EXCEEDS;

            if (((app->m_service_cntxt->main->state == SRV_UC_STATE_FORWARD) || (app->m_service_cntxt->main->state == SRV_UC_STATE_SEND)) &&
                (max_size < msg_rsp->mms_header_size + msg_rsp->mms_body_size))
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_GET_MMS_CONTENT_RSP_CHECK_SIZE_ERR);
                if (app->m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED &&
                    mms_get_max_msg_size_in_restricted_mode() < msg_rsp->mms_header_size + msg_rsp->mms_body_size)
                {
                    vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                }
                else
                {
                    vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                }
                #ifdef __MMI_MMS_USE_ASM__
                    /* we are expecting mms service will send  event: EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE later then UC will terminate */   
                    app->wait_to_close = VFX_TRUE;    
                    return ;
                #else
                    cui->vappUcTerminate();
                #endif

                /*
                mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING); */
                return;
            }
        #else /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
            if ((app->m_service_cntxt->main->state != SRV_UC_STATE_REPLY) && (app->m_service_cntxt->main->state != SRV_UC_STATE_REPLY_ALL)
                && srv_uc_check_if_exceed_MMS_size_limitation(
                    app->main->instance,
                    msg_rsp->mms_header_size + msg_rsp->mms_body_size,
                    &fail_in_restricted_size_check))
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_GET_MMS_CONTENT_RSP_CHECK_SIZE_ERR);
                (fail_in_restricted_size_check) ? vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE) :
                    vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
            #ifdef __MMI_MMS_USE_ASM__
                /* we are expecting mms service will send  event: EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE later then UC will terminate */   
                app->wait_to_close = VFX_TRUE;    
                return ;
            #else
                cui->vappUcTerminate();
                return;
            #endif
            }
        #endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 

            //app->m_service_cntxt->send_info->xml_file_size = msg_rsp->xml_size;
            /* TODO: What to do?
            mmi_uc_editor_initialize(); */
			/*new code added for getting the response from mma in mma_structures instead of xml_parsing*/
			/*begin*/
			if (app->m_service_cntxt->main->state == SRV_UC_STATE_REPLY)
			{
				app_mode = MMA_MODE_REPLY;
			}
			else if (app->m_service_cntxt->main->state == SRV_UC_STATE_REPLY_ALL)
			{
				app_mode = MMA_MODE_REPLY_ALL;
			}
			else if (app->m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
			{
				app_mode= MMA_MODE_FORWARD;
			}
			else if (app->m_service_cntxt->main->state == SRV_UC_STATE_SEND)
			{
				app_mode = MMA_MODE_SEND;
			}
			else
			{
				app_mode = MMA_MODE_EDIT;
			}
			ASSERT(get_mms_header);
			srv_mms_container_copy_header(get_mms_header,
					&(app->m_service_cntxt->msg->g_msg_header),
					ucSrvAllocMemCbk,
					ucSrvFreeMemCbk,
					(mma_mms_state_enum)app->m_service_cntxt->main->state,
					app->m_service_cntxt->main->mode,
				    app_mode,
					(void *)(app->main->mem_pool_id));
			if(app_mode != MMA_MODE_REPLY
				&& app_mode != MMA_MODE_REPLY_ALL)
			{
				ASSERT(get_mms_body);
				srv_mms_container_copy_body(get_mms_body,
				&(app->m_service_cntxt->msg->msg_body),
				ucSrvAllocMemCbk,
				ucSrvFreeMemCbk,
				(void *)(app->main->mem_pool_id));
			}
			/*end*/
            /* parse the XML file */
			/*subject will be copied in utf8 we need it in ucs2 so convert here*/
			if(app->m_service_cntxt->msg->g_msg_header.header->subject.text)
			{
				mmi_chset_utf8_to_ucs2_string((kal_uint8 *)app->m_service_cntxt->msg->subject,sizeof(app->m_service_cntxt->msg->subject),(kal_uint8 *)app->m_service_cntxt->msg->g_msg_header.header->subject.text);
				ucSrvFreeMemCbk(app->m_service_cntxt->msg->g_msg_header.header->subject.text, (void *)(app->main->mem_pool_id));
				app->m_service_cntxt->msg->g_msg_header.header->subject.text = NULL ;
			}

		/*address need to be copied in UC to_head*/
			if(app->m_service_cntxt->msg->msg_header.to)
			{
				app->m_service_cntxt->msg->to_head = srv_uc_cpy_address(app->m_service_cntxt->msg->msg_header.to, app->main->instance) ;
				app->m_service_cntxt->msg->to_num = app->m_service_cntxt->msg->msg_header.to_num ;
				ucFreeAddrMemOfMmaAddr(app->m_service_cntxt->msg->msg_header.to, user_data);
				app->m_service_cntxt->msg->msg_header.to = NULL ;
			}

            result = (srv_uc_result)app->ucParseMmsXmlDescriptionFile();

            if (result != SRV_UC_OK)
            {
                mmi_nmgr_balloon_type_enum type;
                WCHAR *str = vappUcGetSrvResultPopupStr(result, &type);
                vappUcDisplayPopup(str, type);
                /* TODO: Error handling
                mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING); */

            #ifdef __MMI_MMS_USE_ASM__     
                /* we are expecting mms service will send  event: EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE later then UC will terminate */
                app->wait_to_close = VFX_TRUE;
            #else
                cui->vappUcTerminate();
            #endif
            }
            else
            {
                srv_uc_handle_extra_information_from_mma(app->main->instance, msg_rsp->content_truncate_info);
                app->ucSuccessCaseProcessAfterGetContentRsp();
            }
        }
    }
}
#endif

void VappUcAppData::getMmsContentReq(void)
{
#ifdef __MMI_MMS_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_get_content_req_struct msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_mma_active = VFX_TRUE ;
    send_info->request_id = UC_GET_CONTENT_REQ;
    memset(&msg_req, 0, sizeof(srv_mms_get_content_req_struct));
    msg_req.msg_id = m_service_cntxt->send_info->existed_msg_id;
#ifdef __MMI_MMS_USE_ASM__
    msg_req.app_id = (mmi_id)((VcuiUcMainCui *)m_parent)->getGroupId();
#endif
    /* For Forward and Re-send MMS cases, the MMS msg may become SMS message before send */
    /* so the msg content should be gotten besides addresses */
    /* msg_req.mode = srv_uc_convert_uc_state_to_mms_app_mode(main->state); */
    if (m_service_cntxt->main->state == SRV_UC_STATE_REPLY)
    {
        msg_req.mode = MMA_MODE_REPLY;
    }
    else if (m_service_cntxt->main->state == SRV_UC_STATE_REPLY_ALL)
    {
        msg_req.mode = MMA_MODE_REPLY_ALL;
    }
    else if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
    {
        msg_req.mode = MMA_MODE_FORWARD;
    }
    else if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
    {
        msg_req.mode = MMA_MODE_SEND;
    }
    else
    {
        msg_req.mode = MMA_MODE_EDIT;
    }

#ifdef __MMI_MMS_USE_ASM__     
    VcuiUcMainCui* cui = (VcuiUcMainCui *)this->m_parent;
    cui->setWaitToBeClose(VFX_TRUE);
#endif
    msg_req.user_data = this;
    msg_req.call_back = (srv_mms_funcptr_type) ucGetMmsContentRsp;
    srv_mms_get_content(&msg_req);
#endif
    return;
}


void VappUcAppData::ucSuccessCaseProcessAfterGetContentRsp(void)
{
#ifdef __MMI_MMS_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (m_service_cntxt->main->state)
    {
        case SRV_UC_STATE_EDIT_EXISTED_MSG:
         {
            /* In reply case, there is no content. */
            if (m_service_cntxt->msg->msg_body.slide_no == 0)
            {
                m_service_cntxt->msg->msg_body.curr_slide = srv_uc_insert_slide(main->instance, NULL);
            }
            else
            {
                m_service_cntxt->msg->msg_body.curr_slide = m_service_cntxt->msg->msg_body.slides;            
            }                        
            
            m_service_cntxt->msg->current_slide_num = (U8)m_service_cntxt->msg->msg_body.curr_slide->slide_num;
			m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_MMS_PREFER;
            changeMsgTypeIfNeeded();

            /* Reset slide time if the msg type is changed to SMS */
            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
            {
                m_service_cntxt->msg->msg_body.curr_slide->duration = m_service_cntxt->mms_info->sliding_time.value;
            }
            else
            {
                /* tricky! disallow to insert signature for forward and send case */
                m_service_cntxt->msg->auto_signature_inserted = MMI_TRUE;
            }
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__            
            /* (MMS template -> write msg) should be taken as write new msg case */
            if ((mma_get_box(m_service_cntxt->send_info->existed_msg_id) == MMA_FOLDER_TEMPLATE ||
                 mma_get_box(m_service_cntxt->send_info->existed_msg_id) == MMA_FOLDER_USRDEF_TEMPLATE))
            {
                m_service_cntxt->main->state = SRV_UC_STATE_WRITE_NEW_MSG;
            }
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            /* Editing archive MMS should be taken as write new msg case */
            if (mma_get_box(m_service_cntxt->send_info->existed_msg_id) == MMA_FOLDER_ARCHIVE)
            {
                m_service_cntxt->main->state = SRV_UC_STATE_WRITE_NEW_MSG;
            }                        
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

            switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
            if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
            {
                m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
            }
            srv_uc_update_msg_size(main->instance);
            send_info->curr_folder = (U16) vappUcGetMsgBox(m_service_cntxt->send_info->existed_msg_id);

            m_signalConnectOnPage.postEmit();
			mma_folder_enum msg_folder =  mma_get_box(m_service_cntxt->send_info->existed_msg_id);
           if (m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG ||
              (m_service_cntxt->main->state == SRV_UC_STATE_WRITE_NEW_MSG &&
              (   msg_folder == MMA_FOLDER_ARCHIVE
              #ifdef __MMI_MMS_TEMPLATE_SUPPORT__ 
               || msg_folder == MMA_FOLDER_TEMPLATE 
               || msg_folder == MMA_FOLDER_USRDEF_TEMPLATE
              #endif 
              )
              ))
           {
            
             if (m_service_cntxt->send_info->content_truncated_type & MMA_TRUNCATED_SLIDE ||
                 m_service_cntxt->send_info->content_truncated_type & MMA_TRUNCATED_ATTACHMENT ||
                  m_service_cntxt->send_info->content_truncated_type & MMA_TRUNCATE_TEXT)
              {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_SOME_OBJECT_WITHDREW)).getBuf());
              m_service_cntxt->send_info->content_truncated_type = SRV_UC_TRUNCATED_TYPE_NONE ;
               }
         }
           else
          {
             m_service_cntxt->send_info->content_truncated_type = SRV_UC_TRUNCATED_TYPE_NONE ;
           }
        }
        break;
        case SRV_UC_STATE_REPLY:
        case SRV_UC_STATE_REPLY_ALL:
        {
            /* In reply case, there is no content. */
            if (m_service_cntxt->msg->msg_body.slide_no == 0)
            {
                m_service_cntxt->msg->msg_body.curr_slide = srv_uc_insert_slide(main->instance, NULL);
            }
            else
            {
                m_service_cntxt->msg->msg_body.curr_slide = m_service_cntxt->msg->msg_body.slides;
            }

            m_service_cntxt->msg->current_slide_num = (U8)m_service_cntxt->msg->msg_body.curr_slide->slide_num;

            changeMsgTypeIfNeeded();

            /* Reset slide time if the msg type is changed to SMS */
            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
            {
                m_service_cntxt->msg->msg_body.curr_slide->duration = m_service_cntxt->mms_info->sliding_time.value;
            }

#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
            /* (MMS template -> write msg) should be taken as write new msg case */
            if (m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG &&
                (mma_get_box(m_service_cntxt->send_info->existed_msg_id) == MMA_FOLDER_TEMPLATE ||
                 mma_get_box(m_service_cntxt->send_info->existed_msg_id) == MMA_FOLDER_USRDEF_TEMPLATE))
            {
                m_service_cntxt->main->state = SRV_UC_STATE_WRITE_NEW_MSG;
            }
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__*/
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            /* Editing archive MMS should be taken as write new msg case */
            if (m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG &&
                mma_get_box(m_service_cntxt->send_info->existed_msg_id) == MMA_FOLDER_ARCHIVE)
            {
                m_service_cntxt->main->state = SRV_UC_STATE_WRITE_NEW_MSG;
            }
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 

            /* srv_uc_change_msg_type_if_needed(main->instance); */

            switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
            if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
            {
                m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
            }
            srv_uc_update_msg_size(main->instance);
            send_info->curr_folder = (U16) vappUcGetMsgBox(m_service_cntxt->send_info->existed_msg_id);
            m_signalConnectOnPage.postEmit();
        }
            break;

        case SRV_UC_STATE_FORWARD:
        case SRV_UC_STATE_SEND:
        {
            m_service_cntxt->msg->msg_body.curr_slide = m_service_cntxt->msg->msg_body.slides;

            /* In forward case, there is no content. */
            if (m_service_cntxt->msg->msg_body.curr_slide)
            {
                m_service_cntxt->msg->current_slide_num = (U8)m_service_cntxt->msg->msg_body.curr_slide->slide_num;
            }

            /* srv_uc_change_msg_type_if_needed(main->instance); */
            m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;
            m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_MMS_PREFER;

            done->pre_msg_type = m_service_cntxt->msg_type->curr_msg_type;

            /* tricky! disallow to insert signature for forward and send case */
            m_service_cntxt->msg->auto_signature_inserted = MMI_TRUE;

            switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
            if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
            {
                m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
            }
            srv_uc_update_msg_size(main->instance);
            preProcessSendTo();
            m_signalConnectOnPage.postEmit();
			mma_folder_enum msg_folder =  mma_get_box(m_service_cntxt->send_info->existed_msg_id);
            if (m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG ||
              (m_service_cntxt->main->state == SRV_UC_STATE_WRITE_NEW_MSG &&
              (msg_folder == MMA_FOLDER_ARCHIVE 
            #ifdef __MMI_MMS_TEMPLATE_SUPPORT__   
              || msg_folder == MMA_FOLDER_TEMPLATE 
              || msg_folder == MMA_FOLDER_USRDEF_TEMPLATE
            #endif  
              )))
           {
            
              if (m_service_cntxt->send_info->content_truncated_type & MMA_TRUNCATED_SLIDE ||
                  m_service_cntxt->send_info->content_truncated_type & MMA_TRUNCATED_ATTACHMENT ||
                  m_service_cntxt->send_info->content_truncated_type & MMA_TRUNCATE_TEXT)
                {
                mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_SOME_OBJECT_WITHDREW)).getBuf());
                m_service_cntxt->send_info->content_truncated_type = SRV_UC_TRUNCATED_TYPE_NONE ;
                }
           }
            else
           {
              m_service_cntxt->send_info->content_truncated_type = SRV_UC_TRUNCATED_TYPE_NONE ;
           }		
        }
            break;

        default:
        {
            ASSERT(0);
        }
            break;
    }
#endif
    return;
}


void VappUcAppData::preProcessSendTo(void)
{
    m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
    send_info->abort = UC_ABORT_NONE;
    send_info->curr_folder = (U16) vappUcGetMsgBox(m_service_cntxt->send_info->existed_msg_id);
}

void VappUcAppData::ucSaveMsgType(void)
{
    if (main->object_index == 0)
    {
        m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_SMS_PREFER;
        m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_SMS_PREFER;
    }
    else if (main->object_index == 1)
    {
        m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_MMS_PREFER;
        m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_MMS_PREFER;
    }
    else
    {
        ASSERT(0);
    }

    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DONE)), MMI_NMGR_BALLOON_TYPE_SUCCESS);

    if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD || m_service_cntxt->main->state == SRV_UC_STATE_SEND)
    {
        /* Prevent the msg change ind popup display */
        done->pre_msg_type = m_service_cntxt->msg_type->curr_msg_type;
    }
    else
    {
        /* TODO: See about this
        mmi_uc_set_group_id(); */
    }
}


void VappUcAppData::ucChangeMsgTypeToSms(void)
{
    main->object_index = 0;
    ucSaveMsgType();
}

void VappUcAppData::ucChangeMsgTypeToMms(void)
{
    main->object_index = 1;
    ucSaveMsgType();
}

void VappUcAppData::switchSlide(mma_mms_slide_struct *slide)
{
    //ucHandleTextInCurrentSlide(); /* we can force call too. But put here to see switchSlide call as generic. */
    srv_uc_reset_text_buffer(main->instance);

    /* TODO: See about these
    mmi_uc_editor_initialize();
    mmi_uc_reset_history_guibuffer(SCR_ID_UC_EDITOR); */

    if (slide != NULL && slide->txt.object)
    {
        srv_uc_read_file_to_text_buffer(
            main->instance,
            (U8*) slide->txt.object->file_path_ucs,
            slide->txt.object->encoding);
    }

    /* TODO: See this
    mmi_uc_set_editor_info(slide); */
}

void VappUcAppData::ucEntryInsertSlide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 new_slide_size = 0;
    mma_mms_slide_struct *slide;
    MMI_BOOL fail_in_restricted_size_check = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_uc_get_mms_type(main->instance) == MMA_MMS_TYPE_SMIL_MMS)
    {
        new_slide_size = mma_uc_calc_slide_smil_size(m_service_cntxt->msg->slide_timing);
    }

    if (!srv_uc_check_if_exceed_MMS_size_limitation
        (main->instance, new_slide_size + m_service_cntxt->msg->msg_size, &fail_in_restricted_size_check))
    {
        slide = srv_uc_insert_slide(main->instance, m_service_cntxt->msg->msg_body.curr_slide);
        ucHandleTextInCurrentSlide(); /* we can force call too. But put here to see switchSlide call as generic. *///vikas
        m_service_cntxt->msg->msg_body.curr_slide = slide;
        m_service_cntxt->msg->current_slide_num = (U8)slide->slide_num;

        changeMsgTypeIfNeeded();
        if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
        {
            m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
        }
        srv_uc_update_msg_size(main->instance);
        switchSlide(m_service_cntxt->msg->msg_body.curr_slide);

        //srv_uc_reset_text_buffer();
        //mmi_uc_editor_initialize();

        /* TODO: See about this
        mmi_uc_set_group_id(); */
        if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
        {
            m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
        }
    }
    else
    {
        (fail_in_restricted_size_check) ? vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE) :
            vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
        return;
    }
}


void VappUcAppData::ucEntryDeleteSlide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide = m_service_cntxt->msg->msg_body.curr_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slide->next)
    {
        m_service_cntxt->msg->msg_body.curr_slide = slide->next;
    }
    else if (slide->prev)
    {
        m_service_cntxt->msg->msg_body.curr_slide = slide->prev;
    }
    else
    {
        m_service_cntxt->msg->msg_body.curr_slide = NULL;
    }

    srv_uc_delete_slide_with_object(main->instance, slide);
    if (m_service_cntxt->msg->msg_body.curr_slide != NULL)
    {
        m_service_cntxt->msg->current_slide_num = (U8)m_service_cntxt->msg->msg_body.curr_slide->slide_num;
    }

    switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
    changeMsgTypeIfNeeded();
    if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
    {
        m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
    }
    srv_uc_update_msg_size(main->instance);

    /* TODO: See about this
    mmi_uc_set_group_id(); */
    if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
    {
        m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
    }
}


void vappUcResetApp(VappUcMainStruct *main,     
                    VappUcSendInfoStruct *send_info,
                    srv_uc_cntxt_reference_struct *m_service_cntxt)
{
    /* TODO: figure out what all is needed */
#ifdef __MMI_MMS_2__
    if (main->create_msg_rsp)
    {
        kal_adm_free(main->mem_pool_id, main->create_msg_rsp);
        main->create_msg_rsp = NULL;
    }
#endif

    if (send_info->fail_cause)
    {
        kal_adm_free(main->mem_pool_id, send_info->fail_cause);
        send_info->fail_cause = NULL;
    }

    /*  volunteer free */
    //memset(&(send_info), 0, sizeof(send_info));
    memset(send_info, 0, sizeof(VappUcSendInfoStruct));
    /*  volunteer free */
    
    main->is_short = MMI_FALSE;
    main->is_warning = MMI_FALSE;
    if(m_service_cntxt->main->auto_delete_file && mmi_ucs2strlen((S8*) main->file_path_to_delete))
    {
        FS_Delete((WCHAR*) main->file_path_to_delete);
    }
    if (main->callback != NULL)
    {
        main->callback((void*)main->callback_para);
        main->callback = NULL;
    }
    main->callback_para = NULL;

#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
	if(EndKeyHandle[main->instance].NeedToFreeService == VFX_TRUE)
	{
		srv_uc_reset_msg_ext(main->instance);
	}
	else
#endif
	{
		srv_uc_reset_msg(main->instance);
	}
/* TODO: See where to put this 
    if (!other_app_temp_uc_info)
*/
    {
        //kal_adm_delete(main->mem_pool_id);
        //main->mem_pool_id = kal_adm_create(main->uc_adm_mem, UC_ADM_MEM_SIZE, NULL, KAL_FALSE);
    }
}

void VappUcAppData::resetApp(void)
{
    vappUcResetApp(main, send_info, m_service_cntxt);
}


srv_uc_msg_type_enum VappUcAppData::determineMsgTypeByContent(void)
{
    return vappUcDetermineMsgTypeByContent(m_service_cntxt, main);
}    

extern "C" srv_uc_msg_type_enum vappUcDetermineMsgTypeByContent(srv_uc_cntxt_reference_struct *m_service_cntxt,VappUcMainStruct *main)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_addr_struct *addr = m_service_cntxt->msg->to_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/* TODO: This may be needed */
    if(main->m_itemForceOn > 0)
    {
        return SRV_UC_MSG_TYPE_MMS_PREFER;
    }

 //   if(!main->check_buffer_flag)
    {
        while (addr)
        {
        #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__  
            if (addr->group == SRV_UC_ADDRESS_GROUP_TYPE_CC)
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DETEMINE_MSG_TYPE_BY_CONTENT_CC, 0);
                return SRV_UC_MSG_TYPE_MMS_PREFER;
            }
            else if (addr->group == SRV_UC_ADDRESS_GROUP_TYPE_BCC)
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DETEMINE_MSG_TYPE_BY_CONTENT_BCC, 0);
                return SRV_UC_MSG_TYPE_MMS_PREFER;
            }
       #endif     
            addr = addr->next;
        }
    }


    if (mmi_ucs2strlen((S8*) m_service_cntxt->msg->subject))
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DETEMINE_MSG_TYPE_BY_CONTENT_SUB);
        return SRV_UC_MSG_TYPE_MMS_PREFER;
    }
    else if (m_service_cntxt->msg->msg_body.slide_no > 1)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DETEMINE_MSG_TYPE_BY_CONTENT_SLIDE, m_service_cntxt->msg->msg_body.slide_no);
        return SRV_UC_MSG_TYPE_MMS_PREFER;
    }
    else if (m_service_cntxt->msg->msg_body.obj_no > 1)
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DETEMINE_MSG_TYPE_BY_CONTENT_OBJ, m_service_cntxt->msg->msg_body.obj_no);
        return SRV_UC_MSG_TYPE_MMS_PREFER;
    }
    else if ((m_service_cntxt->msg->msg_body.obj_no == 1) &&
             (m_service_cntxt->msg->msg_body.objects->type != MMA_MMS_OBJECT_TYPE_TEXT))
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DETEMINE_MSG_TYPE_BY_CONTENT_ONE_OBJ);
        return SRV_UC_MSG_TYPE_MMS_PREFER;
    }
    else
    {
        {
            addr = m_service_cntxt->msg->to_head;

            for (; addr != NULL; addr = addr->next)
            {
                if (addr->type == SRV_UC_ADDRESS_TYPE_EMAIL)
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DETEMINE_MSG_TYPE_BY_CONTENT_EMAIL);
                    return SRV_UC_MSG_TYPE_MMS_PREFER;
                }
            }
        }
        /* Add text object when the UC screen is exited */
        /* ASSERT(m_service_cntxt->msg->msg_body.curr_slide->txt.object); */

        if (m_service_cntxt->msg->msg_body.curr_slide)
        {
            if (srv_sms_get_sms_segment_number(
                    m_service_cntxt->msg->msg_body.curr_slide->txt.UCS2_count,
                    m_service_cntxt->msg->msg_body.curr_slide->txt.char_count,
                    m_service_cntxt->msg->msg_body.curr_slide->txt.extension_char_count) > getMaxMoSmsSegment())
            {
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DETEMINE_MSG_TYPE_BY_CONTENT_SEG_EXCEED);
                return SRV_UC_MSG_TYPE_MMS_PREFER;
            }

            if (m_service_cntxt->msg->msg_body.curr_slide->txt.UCS2_count)
            {
                if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count >
                    (srv_sms_get_usable_text_len(SMSAL_UCS2_DCS) / 2))
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DETEMINE_MSG_TYPE_BY_CONTENT_UCS2_TEXT_EXCEED);
                    return SRV_UC_MSG_TYPE_MMS_PREFER;
                }
            }
            else if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count)
            {
                if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count +
                    m_service_cntxt->msg->msg_body.curr_slide->txt.extension_char_count >
                    (srv_sms_get_usable_text_len(SMSAL_DEFAULT_DCS) / 2))
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DETEMINE_MSG_TYPE_BY_CONTENT_ASCII_TEXT_EXCEED);
                    return SRV_UC_MSG_TYPE_MMS_PREFER;
                }
            }
        }
    }

    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DETEMINE_MSG_TYPE_BY_CONTENT_SMS);
    return SRV_UC_MSG_TYPE_SMS_PREFER;
}

MMI_BOOL VappUcAppData::changeMsgTypeIfNeeded(void)
{
    return vappUcChangeMsgTypeIfNeeded(m_service_cntxt, main);
}

extern "C" MMI_BOOL vappUcChangeMsgTypeIfNeeded(srv_uc_cntxt_reference_struct *m_service_cntxt, VappUcMainStruct *main)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_msg_type_enum msg_type;
    static VfxBool skip_change_to_sms_popup = VFX_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_CHANGE_MSG_TYPE_IF_NEEDED_P3, m_service_cntxt->msg_type->curr_msg_type, m_service_cntxt->msg_type->caller_specific_msg_type, m_service_cntxt->msg_type->setting_msg_type);

#ifdef __MMI_EMAIL__
     if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
	 {
		 return MMI_FALSE;
	 }
#endif
    msg_type = vappUcDetermineMsgTypeByContent(m_service_cntxt, main);

    switch (m_service_cntxt->msg_type->caller_specific_msg_type)
    {
        case SRV_UC_MSG_TYPE_SMS_ONLY:
        {
            ASSERT(m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER);
        }
            break;
        case SRV_UC_MSG_TYPE_MMS_ONLY:
        {
            /* Reach this state when VCard & VCalendar send as MMS */
            ASSERT(m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER);
        }
            break;
        case SRV_UC_MSG_TYPE_DEFAULT:
        {
            if (m_service_cntxt->msg_type->setting_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
            {
                if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                {
                    if (msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                    {
                        VappUcAppData * app_data = g_app.app_data[main->instance];                        
                        if(app_data != NULL && app_data->batchEdit )
                        {
                            skip_change_to_sms_popup = VFX_TRUE;
                        }                        
                        
                        m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_SMS_PREFER;
                        m_service_cntxt->msg->msg_body.curr_slide->duration = m_service_cntxt->msg->slide_timing;
                        if(!skip_change_to_sms_popup)
                        {
                            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_SWITCHED_TO_SMS_ID)).getBuf());
                        }
                        return MMI_TRUE;
                    }
                }
                else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                {
                    if (msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                    {
                        m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_MMS_PREFER;
                        skip_change_to_sms_popup = VFX_FALSE;
                        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_SWITCHED_TO_MMS_ID)).getBuf());
                        return MMI_TRUE;
                    }
                }
                else
                {
                    ASSERT(0);
                } 
            }
            else if (m_service_cntxt->msg_type->setting_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
            {
                if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                {
                    /* Do nothing. */
                }
                else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                {
                    ASSERT(0);
                }
                else
                {
                    ASSERT(0);
                }
            }
            else
            {
                ASSERT(0);
            }
        }
            break;
        case SRV_UC_MSG_TYPE_SMS_PREFER:
        {
            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
            {
                if (msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                {
                    VappUcAppData * app_data = g_app.app_data[main->instance];                        
                    if(app_data != NULL && app_data->batchEdit )
                    {
                        skip_change_to_sms_popup = VFX_TRUE;
                    }                        
                        
                    m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_SMS_PREFER;
                    m_service_cntxt->msg->msg_body.curr_slide->duration = m_service_cntxt->msg->slide_timing;
                    if(!skip_change_to_sms_popup)
                    {
                        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_SWITCHED_TO_SMS_ID)).getBuf());
                    }

                    return MMI_TRUE;
                }
            }
            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
            {
                if (msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                {
                    m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_MMS_PREFER;
                    skip_change_to_sms_popup = VFX_FALSE;
                    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_SWITCHED_TO_MMS_ID)).getBuf());
                    return MMI_TRUE;
                }
            }
            else
            {
                ASSERT(0);
            }
        }
            break;

        case SRV_UC_MSG_TYPE_MMS_PREFER:
        {
            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
            {
                /* Do nothing. */
            }
            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
            {
                ASSERT(0);
            }
            else
            {
                ASSERT(0);
            }
        }
            break;

        default:
        {
            ASSERT(0);
        }
    }

    if(skip_change_to_sms_popup)
    {
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)(VFX_WSTR_RES(STR_ID_VAPP_UC_SWITCHED_TO_SMS_ID)).getBuf());
        skip_change_to_sms_popup = VFX_FALSE;
    }
        
    return MMI_FALSE;
}

MMI_BOOL VappUcAppData::isPendingContent(void)
{
    if (m_service_cntxt->msg->msg_body.slide_no > 0)
    {
        if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count ||
            m_service_cntxt->msg->msg_body.slide_no > 1 ||
            m_service_cntxt->msg->msg_body.objects ||
            m_service_cntxt->msg->to_num > 0 || 
           mmi_ucs2strlen((S8*) m_service_cntxt->msg->subject))
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_IS_PENDING_CONTENT_P1, 1);
            return MMI_TRUE;
        }
        else
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_IS_PENDING_CONTENT_P1, 0);
            return MMI_FALSE;
        }
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_IS_PENDING_CONTENT_P1, 0);
        return MMI_FALSE;
    }
}

U32 VappUcAppData::getMaxMediaFileSizeAllowed(srv_uc_object_type object_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 new_slide_size = 0;
    U32 max_file_size = 0;
    U32 smil_size = 0;

    /* max "file name" size, not path size. not include file extension, the max file name that user can edit is 35 */
    kal_wchar temp_file_path[43] = {0};
    mmi_ucs2ncpy((S8*)temp_file_path, (S8*)L"D:\\temp1234567890123456789012345678901.tmp", mmi_ucs2strlen((S8*)L"D:\\temp1234567890123456789012345678901.tmp"));
    U16 file_name_size = (35 + 4) * 3 + 50; /* (max+file extension) *3 + constant for mms calculation */
#ifdef __MMI_MMS_2__
    U32 max_mms_size_available = (m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED && mms_get_max_msg_size_in_restricted_mode() <=
                                          m_service_cntxt->mms_info->max_mms_size) ? mms_get_max_msg_size_in_restricted_mode() : m_service_cntxt->mms_info->max_mms_size;
#else
    U32 max_mms_size_available = m_service_cntxt->mms_info->max_mms_size;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ENTER_MULTIMEDIA_APP_P1, main->highlighted_object_type);
 #ifdef __MMI_EMAIL__
     if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
	 {
		U32 attchSize = ucGetAttachmentItemsTotalSize();
		if(attchSize <= MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE)
		{
			max_file_size = MMI_EMAIL_TOTAL_MAX_ATTACH_SIZE - attchSize;
		}
		else
		{
			max_file_size = 1;
		}
	 }
	 else
#endif    
	 {
        switch (object_type)
        {
            case SRV_UC_OBJECT_TYPE_IMAGE:
            {
                if (m_service_cntxt->msg->msg_body.curr_slide->img.object != NULL ||
                    m_service_cntxt->msg->msg_body.curr_slide->vid.object != NULL)
                {
                    new_slide_size = mma_uc_calc_slide_smil_size(m_service_cntxt->msg->slide_timing);
                }
                smil_size = mma_uc_calc_object_smil_size(MMA_INSERT_IMAGE, (kal_wchar*) temp_file_path);
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ENTER_MULTIMEDIA_APP_P5, max_file_size, max_mms_size_available, m_service_cntxt->msg->msg_size, new_slide_size, smil_size);
            }
                break; 
    
            case SRV_UC_OBJECT_TYPE_AUDIO:
            {
                if (m_service_cntxt->msg->msg_body.curr_slide->aud.object  != NULL ||
                    m_service_cntxt->msg->msg_body.curr_slide->vid.object  != NULL)
                {
                    new_slide_size = mma_uc_calc_slide_smil_size(m_service_cntxt->msg->slide_timing);
                }
                smil_size = mma_uc_calc_object_smil_size(MMA_INSERT_AUDIO, (kal_wchar*) temp_file_path);
            }
                break;
    
            case SRV_UC_OBJECT_TYPE_VIDEO:
            {
                if (m_service_cntxt->msg->msg_body.curr_slide->vid.object  != NULL ||
                    m_service_cntxt->msg->msg_body.curr_slide->img.object  != NULL ||
                    m_service_cntxt->msg->msg_body.curr_slide->aud.object  != NULL)
                {
                    new_slide_size = mma_uc_calc_slide_smil_size(m_service_cntxt->msg->slide_timing);
                }
                smil_size = mma_uc_calc_object_smil_size(MMA_INSERT_VIDEO, (kal_wchar*) temp_file_path);
                VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ENTER_MULTIMEDIA_APP_P5, max_file_size, max_mms_size_available, m_service_cntxt->msg->msg_size, new_slide_size, smil_size);
            }
                break;
            default:
            {
                MMI_ASSERT(0);
            }
                break;
        }
    
        if (srv_uc_get_mms_type(main->instance) == MMA_MMS_TYPE_MIXED_MMS)
        {
            new_slide_size = 0;
            smil_size = 0;
        }
    
        if (max_mms_size_available < (m_service_cntxt->msg->msg_size + new_slide_size + smil_size + file_name_size))
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ENTER_MULTIMEDIA_APP_SIZE_EXCEED_P5, max_file_size, max_mms_size_available, m_service_cntxt->msg->msg_size, new_slide_size, smil_size);
            max_file_size = 0;
        }
        else    /* avoid overflow */
        {
            max_file_size = max_mms_size_available - m_service_cntxt->msg->msg_size - new_slide_size - smil_size - file_name_size;
        }
    }
    return max_file_size;
}

VfxBool VappUcAppData::getServiceContext(void)
{
    srv_uc_app_registered_data_struct app_registered_data = {0, };
    main->mem_pool_id = kal_adm_create(main->uc_adm_mem, UC_ADM_MEM_SIZE, NULL, KAL_FALSE);
    app_registered_data.user_data = main->mem_pool_id;
    app_registered_data.app_mem_alloc_fun = ucSrvAllocMemCbk;
    app_registered_data.app_mem_free_fun = ucSrvFreeMemCbk;
    app_registered_data.app_text_buffer_mem_alloc_fun = ucSrvAllocMemCbk;
    app_registered_data.app_text_buffer_mem_free_fun = ucSrvFreeMemCbk;
    main->instance = srv_uc_create(app_registered_data);

    if(0xffffffff == main->instance)
    {
        return VFX_FALSE;
    }
    else
    {  
        m_service_cntxt->main = srv_uc_get_srv_main_context(main->instance);
        m_service_cntxt->msg_type = srv_uc_get_srv_msg_type_context(main->instance);
        m_service_cntxt->mms_info = srv_uc_get_srv_mms_info_context(main->instance);
        m_service_cntxt->sms_info = srv_uc_get_srv_sms_info_context(main->instance);
        m_service_cntxt->msg = srv_uc_get_srv_msg_info_context(main->instance);
        m_service_cntxt->send_info = srv_uc_get_srv_send_info_context(main->instance);

	#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
	m_service_cntxt->xml = srv_uc_get_srv_xml_info_context(main->instance);
	#endif
        #if (MMI_MAX_SIM_NUM >= 2)
            m_service_cntxt->sim_info = srv_uc_get_srv_sim_info_context(main->instance);
        #endif
        return VFX_TRUE;
    }
}


VfxBool VappUcAppData::getMmsSetting(void)
{
    m_service_cntxt->msg->display_no_resize = MMI_FALSE;
 #ifdef __MMI_EMAIL__
     if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
	 {
		m_service_cntxt->mms_info->creation_mode = MMA_CREATION_MODE_FREE;
		m_service_cntxt->mms_info->max_mms_size = MMI_EMAIL_MAX_MSG_SIZE;
        main->image_resize_limit = 0;
	 }
	 else
 #endif
	 {
#ifdef __MMI_MMS_2__
		if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
		{
			m_service_cntxt->mms_info->creation_mode = MMA_CREATION_MODE_FREE;
		}
		else
		{
		    m_service_cntxt->mms_info->creation_mode = srv_mms_compose_settings_creation_mode();
		}
#endif
		if(m_service_cntxt->msg_type->caller_specific_msg_type == SRV_UC_MSG_TYPE_SMS_ONLY)
		{
			m_service_cntxt->mms_info->creation_mode = MMA_CREATION_MODE_FREE;
			 main->image_resize_limit = 0;
		}
#ifdef __MMI_MMS_2__
        m_service_cntxt->mms_info->priority = srv_mms_sending_settings_priority();
        m_service_cntxt->mms_info->validity_period = srv_mms_sending_settings_validity_period();
        m_service_cntxt->mms_info->delivery_time = srv_mms_sending_settings_delivery_time();
        m_service_cntxt->mms_info->delivery_report = srv_mms_sending_settings_delivery_report();
        m_service_cntxt->mms_info->read_report = srv_mms_sending_settings_read_report();
    #ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
        m_service_cntxt->mms_info->max_mms_size = (U32)srv_mms_sending_mms_size_limit();
    #else
        m_service_cntxt->mms_info->max_mms_size = wap_custom_get_max_mms_msg_size();
    #endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */
        m_service_cntxt->mms_info->best_page_duration = srv_mms_compose_settings_best_page_duration();
		if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
		{
		#ifdef __MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__	
			main->image_resize_limit = vappUcConvertUmmsResizeToUc(E_PICTURE_RESIZE_100KB);
		#else
			main->image_resize_limit = 0;
		#endif
		}
		else
		{
		#ifdef __MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__	
			main->image_resize_limit = vappUcConvertUmmsResizeToUc(srv_mms_compose_setting_image_resize_based_upon_size());
		#else
			main->image_resize_limit = 0;
		#endif
		}
        srv_mms_compose_settings_default_slide_time(&m_service_cntxt->mms_info->sliding_time);
        m_service_cntxt->mms_info->hide_sender = srv_mms_sending_settings_hide_sender();
#endif
        m_service_cntxt->msg->read_report = m_service_cntxt->mms_info->read_report;
        m_service_cntxt->msg->delivery_report = m_service_cntxt->mms_info->delivery_report;
        m_service_cntxt->msg->priority = m_service_cntxt->mms_info->priority;
        m_service_cntxt->msg->expiry_time = srv_uc_convert_mms_expiry_time_to_uc(m_service_cntxt->mms_info->validity_period);
        m_service_cntxt->msg->delivery_time = srv_uc_convert_mms_delivery_time_to_uc(m_service_cntxt->mms_info->delivery_time);
        m_service_cntxt->msg->slide_timing = m_service_cntxt->mms_info->sliding_time.value;
        m_service_cntxt->msg->hide_sender = m_service_cntxt->mms_info->hide_sender;
        m_service_cntxt->msg->best_page_duration = m_service_cntxt->mms_info->best_page_duration;

		/*header info copy to new mma structure here*/
		/*begin*/
		m_service_cntxt->msg->msg_header.read_reply = srv_uc_convert_mms_rr_to_mma_rr(m_service_cntxt->mms_info->read_report);
		m_service_cntxt->msg->msg_header.delivery_report = srv_uc_convert_mms_dr_to_mma_dr(m_service_cntxt->mms_info->delivery_report);
		m_service_cntxt->msg->msg_header.priority = m_service_cntxt->mms_info->priority;
		m_service_cntxt->msg->msg_header.expiry_time = (mma_mms_time_sec)m_service_cntxt->mms_info->validity_period;
		m_service_cntxt->msg->msg_header.delivery_time = (mma_mms_time_sec)m_service_cntxt->mms_info->delivery_time;
		m_service_cntxt->msg->msg_header.visibility = srv_uc_convert_mms_vis_to_mma_vis(m_service_cntxt->mms_info->hide_sender);
		if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_LEMEI_MMS)
		{
			m_service_cntxt->msg->msg_header.msg_class.class_identifier = MMA_MSG_CLASS_INFORMATIONAL ;
		}
		/*end*/
	 }
#ifdef __MMI_MMS_2__
    m_service_cntxt->msg->msg_body.bgColor = SRV_UC_DEFAULT_BG_COLOR;
    m_service_cntxt->msg->msg_body.fgColor = SRV_UC_DEFAULT_FG_COLOR;
#endif
#if (MMI_MAX_SIM_NUM >= 2)
	 main->sim_setting_primary_card = vappUcConvertMmiSimIdToUc(srv_setting_get_primary_card());
#endif

    switch(m_service_cntxt->main->state)
    {
        case SRV_UC_STATE_WRITE_NEW_MSG:
        {
            VfxBool img_resolution_need_resize = VFX_FALSE;

            /* If enter from mmi_uc_entry_write_msg_with_content, the first slide is ready. */
            if (m_service_cntxt->msg->msg_body.slide_no == 0)
            {
                m_service_cntxt->msg->msg_body.curr_slide = srv_uc_insert_slide(main->instance, NULL);
                m_service_cntxt->msg->current_slide_num = (U8)m_service_cntxt->msg->msg_body.curr_slide->slide_num;

                /* Set duration of current slide as the value of MMS slide setting */
                m_service_cntxt->msg->msg_body.curr_slide->duration = m_service_cntxt->msg->slide_timing;
            }
            else
            {
                /* Set duration of current slide as the value of MMS slide setting */
                /* srv_uc_insert_object_to_slide below will use m_service_cntxt->msg->msg_body.curr_slide->duration, and also maybe change this value */
                m_service_cntxt->msg->msg_body.curr_slide->duration = m_service_cntxt->msg->slide_timing;

                if (m_service_cntxt->main->file_path)
                {
                    mma_insert_check_struct check_result;
                    mma_insert_info_struct insert_info;
                    VfxS32 result;

                    memset(&check_result, 0, sizeof(check_result));

                    insert_info.creation_mode = m_service_cntxt->mms_info->creation_mode;
                    insert_info.current_msg_size = m_service_cntxt->msg->msg_size;
                    insert_info.max_msg_size =
                        m_service_cntxt->mms_info->max_mms_size - srv_uc_reserved_size(main->instance);
                    insert_info.insert_type = MMA_INSERT_UNKNOWN;
                    insert_info.filepath = (kal_wchar*) m_service_cntxt->main->file_path;
                    insert_info.mms_type = srv_uc_get_mms_type(main->instance);

                    mma_uc_insert_object_check(&insert_info, &check_result);
 
                    /* the file maybe be deleted before UC is triggered */
                    /* might be corrupted */
                    /* might be high resolution */
                    if (!(check_result.result) &&
                        ((MMA_RESULT_FAIL_FILE_IO == check_result.detail_result) ||
                         (MMA_RESULT_FAIL_FILE_CORRUPTED == check_result.detail_result) ||
                         (MMA_RESULT_FAIL_FILE_NOT_FOUND == check_result.detail_result) ||
                         (MMA_RESULT_FAIL_FILE_EMPTY == check_result.detail_result) ||
                         (MMA_RESULT_FAIL_IMAGE_TOO_LARGE == check_result.detail_result)))
                    {
                        result = srv_uc_convert_mms_check_result(&check_result);
                        kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
                        m_service_cntxt->main->file_path = NULL;
                        //app->vappUcTerminate();
                        {
                            mmi_nmgr_balloon_type_enum type;
                            WCHAR *str = vappUcGetSrvResultPopupStr((srv_uc_result)result, &type);
                            //vappUcDisplayPopup(str, type);
                            m_signalTerminate.postEmit(str, type);
                        }
                        /* TODO: close processing screen */
                        //mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING); 
                        //resetApp();
                        return VFX_FALSE;
                    }
                    if (check_result.insert_type == MMA_INSERT_IMAGE && check_result.drm_type == MMA_DRM_NONE)
                    {
                        if (main->image_resize_limit && applib_get_file_size((U16*)m_service_cntxt->main->file_path) > main->image_resize_limit)
                        {
                            img_resolution_need_resize = VFX_TRUE;
                        }
                    #ifdef __MMI_UC_MMS_IMG_RESOLUTION__
                        else if (m_service_cntxt->mms_info->creation_mode == MMA_CREATION_MODE_RESTRICTED)
                        {
                            img_resolution_need_resize = srv_uc_img_resolution_exceed_limitation((U16*) m_service_cntxt->main->file_path);
                        }
                    #endif /* __MMI_UC_MMS_IMG_RESOLUTION__ */ 
                    }

                    if (!img_resolution_need_resize &&
                        check_result.result && (MMA_RESULT_OK_WITH_WARNING_CONTENT == check_result.detail_result))
                    {
                        main->confirm_handler = processNewMsgInMmsSetting;
                        return VFX_TRUE;
                    }
                #if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__)     
                    else if (img_resolution_need_resize)
                    {
                        S32 fmgr_ret = 0 ;
                        srv_uc_result result_fm_check;

                        if (!check_result.result)
                        {
                   /*
                            mmi_fmgr_util_file_limit_check2(
                                FMGR_LIMIT_MMS_CATEGORY,
                                (PS8) m_service_cntxt->main->file_path,
                                &fmgr_ret);
                   */
                            if (fmgr_ret < 0)
                            {
                                if (fmgr_ret == GDI_IMAGE_ERR_IMAGE_TOO_LARGE)
                                {
                                    result_fm_check = SRV_UC_FAIL_IMAGE_TOO_LARGE;
                                }
                                else
                                {
                                    result_fm_check = SRV_UC_FILE_CORRUPT;
                                }
                                kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
                                m_service_cntxt->main->file_path = NULL;
                                //app->vappUcTerminate();
                                {
                                    mmi_nmgr_balloon_type_enum type;
                                    WCHAR *str = vappUcGetSrvResultPopupStr((srv_uc_result)result_fm_check, &type);
                                    //vappUcDisplayPopup(str, type);
                                    m_signalTerminate.postEmit(str, type);
                                }
                                /* TODO: close processing screen mmi_frm_scrn_close (main->uc_cui_gid, SCR_ID_UC_PROCESSING); */
                                //resetApp();
                                return VFX_FALSE;
                            }
                        }
						{
							U16 errorString = vappUcResizeBeforeVerification((U16*) m_service_cntxt->main->file_path, 1);
							if(errorString != STR_GLOBAL_OK)
							{
                                if(errorString == STR_GLOBAL_FAILED)
                                {
                                    m_signalTerminateWtPopUp.postEmit();
                                }
                                else
                                {
								    m_signalTerminate.postEmit((WCHAR*)((UI_string_type) GetString(errorString)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
								return VFX_FALSE;
							}
						}
                        return VFX_TRUE;
                    }
                #endif /* #if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__)  */    
                    if (!handleObjectInsertIfFilePathExist())
                    {
                        return VFX_FALSE;
                    }
                    /* moved to mmi_uc_process_state_write_new_msg_in_mms_setting_rsp */
                }
                changeMsgTypeIfNeeded();
            }
            switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
            if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
            {
                m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
            }
            srv_uc_update_msg_size(main->instance);
            /* TODO: 
            if (mmi_frm_scrn_is_present(main->uc_cui_gid, SCR_ID_UC_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
            {
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_UC_GET_MMS_CONTENT_RSP_INTERRUPT);
                mmi_uc_replace_screen(SCR_ID_UC_PROCESSING, SCR_ID_UC_EDITOR, (mmi_proc_func) mmi_uc_entry_write_msg, 0);
            }
            else
            {
                mmi_uc_entry_write_msg();
                mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
            }*/
            

        }
            break;

        case SRV_UC_STATE_EDIT_EXISTED_MSG:
        case SRV_UC_STATE_FORWARD:
        case SRV_UC_STATE_SEND:
        case SRV_UC_STATE_REPLY:
        case SRV_UC_STATE_REPLY_ALL:
        {
            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
            {
            #ifndef __MMI_MMS_STANDALONE_COMPOSER__
                if (m_service_cntxt->msg->msg_body.slide_no > 0)
                {
                    m_service_cntxt->msg->msg_body.curr_slide->duration = m_service_cntxt->msg->slide_timing;
                }
                changeMsgTypeIfNeeded();

                if (m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG)
                {   
                    switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
                    send_info->curr_folder = (U16) vappUcGetMsgBox(m_service_cntxt->send_info->existed_msg_id);
                    /*handle interrupt issue*/
                    /* TODO:
                    if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                    {
                        mmi_uc_entry_write_msg();
                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                    }
                    else
                    {
                        if (mmi_frm_scrn_is_present(main->uc_cui_gid, SCR_ID_UC_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                        {
                            mmi_uc_replace_screen(SCR_ID_UC_PROCESSING, SCR_ID_UC_EDITOR, (mmi_proc_func) mmi_uc_entry_write_msg, 0);
                        }
                    } */
                }
                else if (m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG ||
                    m_service_cntxt->main->state == SRV_UC_STATE_REPLY || m_service_cntxt->main->state == SRV_UC_STATE_REPLY_ALL)
                {
                    switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
                    send_info->curr_folder =
                        (U16) vappUcGetMsgBox(m_service_cntxt->send_info->existed_msg_id);
                    /* handle interrupt issue */
                    /* TODO:
                    if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                    {
                        mmi_uc_entry_write_msg();
                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                    }
                    else
                    {
                        if (mmi_frm_scrn_is_present(main->uc_cui_gid, SCR_ID_UC_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                        {
                            mmi_uc_replace_screen(SCR_ID_UC_PROCESSING, SCR_ID_UC_EDITOR, (mmi_proc_func) mmi_uc_entry_write_msg, 0);
                        }
                    } */
                }
                else
                {
                    pre_msg_type = m_service_cntxt->msg_type->curr_msg_type;
                    preProcessSendTo();
                    /* TODO:
                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING); */
                }
            #else /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
                ASSERT(0);
            #endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
            }
            else if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
            {
                getMmsContentReq();
            }
            else
            {
                ASSERT(0);
            }
        }
            break;

        default:
        {
            ASSERT(0);
        }
            break;
    }
    return VFX_TRUE;
}

BOOL VappUcAppData::handleObjectInsertIfFilePathExist(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mmi_uc_image_path[SRV_UC_MAX_TEMP_FILE_LEN];
    U16 *filePath = (U16*) m_service_cntxt->main->file_path;
    mma_insert_check_struct check_result;
    S32 result;
    mma_insert_info_struct insert_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (m_service_cntxt->main->file_path == NULL)
    {
        ASSERT(0);
        return MMI_TRUE;    /* even no file path, caller still go on following flow */
    }

    memset(&check_result, 0, sizeof(check_result));

    insert_info.creation_mode = m_service_cntxt->mms_info->creation_mode;
    insert_info.current_msg_size = m_service_cntxt->msg->msg_size;
    insert_info.max_msg_size = m_service_cntxt->mms_info->max_mms_size - srv_uc_reserved_size(main->instance);
    insert_info.insert_type = MMA_INSERT_UNKNOWN;
    insert_info.filepath = (kal_wchar*) m_service_cntxt->main->file_path;
    insert_info.mms_type = srv_uc_get_mms_type(main->instance);

    mma_uc_insert_object_check(&insert_info, &check_result);

#ifdef __MMI_MMS_POSTCARD__
    if ((m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS) && (check_result.result))
    {
        ASSERT(check_result.insert_type == MMA_INSERT_IMAGE);
    }
#endif /* __MMI_MMS_POSTCARD__ */ 

    memset(mmi_uc_image_path, 0x00, SRV_UC_MAX_TEMP_FILE_LEN);

    /* Treat .txt files as attachments */
    if (check_result.insert_type == MMA_INSERT_TEXT)
    {

        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_GET_MMS_SETTING_RSP_TO_ATT);
        check_result.insert_type = MMA_INSERT_ATTACHMENT;
    }

    if (!(check_result.result))
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_GET_MMS_SETTING_RSP_INSERT_OBJ_CHECK_ERR);

        result = srv_uc_convert_mms_check_result(&check_result);
        kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
        m_service_cntxt->main->file_path = NULL;
        //resetApp();
        //app->vappUcTerminate();
        {
            mmi_nmgr_balloon_type_enum type;
            WCHAR *str = vappUcGetSrvResultPopupStr((srv_uc_result)result, &type);
            //vappUcDisplayPopup(str, type);
            m_signalTerminate.postEmit(str, type);
        }
        /*
        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_CONFIRM); */
        return MMI_FALSE;
    }
    srv_uc_post_handler_handle_object_insert_if_file_path_exist(
        main->instance,
        check_result.insert_type,
        mmi_uc_image_path,
        filePath);
    return MMI_TRUE;
}


void VcuiUcMainCui::vappUcSendEvtToCaller(cui_msgcomposer_evt_enum evt_id)
{
    /* TODO: Find a way to identify the type UC that exited */
    if(!temp_flag)
    {
        cui_msgcomposer_evt_struct evt;
        MMI_FRM_INIT_GROUP_EVENT(&evt, evt_id, getGroupId());
        postToCaller((mmi_group_event_struct*)&evt);
    }
}

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__

VfxBool VcuiUcMainCui::handleDataOnRestore(VfxArchive &archive)
{

    VappUcAppArchive ucArchive;  
    U32 instance;
    VappUcAppDataAfterSerialize *app;
        
    //archive.readU16((U32)hint); 
    archive.read( (VfxU8 *)&ucArchive,sizeof(VappUcAppArchive));
    instance = ucArchive.instance;
    app = ucArchive.app;
    
    VFX_ALLOC_NEW(m_app_data, VappUcAppData, this);

    g_app.app_data[instance] = m_app_data;
    m_app_data->m_parent = (void *)this;
    vappUcResetSerialize(instance);
        
    m_app_data->main             = app->main ;
    m_app_data->send_info       = app->send_info ;
    m_app_data->done             = app->done ;
    m_app_data->m_service_cntxt  = app->m_service_cntxt;

    m_app_data->pre_msg_type            = app->archive_data.pre_msg_type ;
    m_app_data->operation_type          = app->archive_data.operation_type;
    m_app_data->otherAppTempUcInfo      = app->archive_data.otherAppTempUcInfo ;
    m_app_data->contact_insert_type     = app->archive_data.contact_insert_type;  
    m_app_data->available_size          = app->archive_data.available_size;
    m_app_data->taken_pref_phb_sim      = app->archive_data.taken_pref_phb_sim;   
    m_app_data->is_mma_active           = app->archive_data.is_mma_active;
    m_app_data->wait_to_close           = app->archive_data.wait_to_close;
    m_app_data->nvram_sim_id            = app->archive_data.nvram_sim_id;
    m_app_data->CurrAsyncPhbAddr        = app->archive_data.CurrAsyncPhbAddr;    
    m_app_data->WaitAsyncPhbRspToCloseUC= app->archive_data.WaitAsyncPhbRspToCloseUC;
    m_app_data->g_settingLimitation     = app->archive_data.g_settingLimitation;
    m_app_data->m_pbInsertState         = app->archive_data.m_pbInsertState;
    m_app_data->m_useSecondStage        = VFX_TRUE; 
    m_app_data->appBaseId               = app->archive_data.appBaseId;
    m_app_data->p_vapp_uc_asm           = app->archive_data.p_vapp_uc_asm ;

    //m_app_data->main->launch_mode = UC_LAUNCH_MODE_NONE;
    
    m_app_data->m_signalTerminate.connect(m_app_data, &VappUcAppData::vappUcTerminateWithPopup);
	m_app_data->m_signalTerminateWtPopUp.connect(this, &VcuiUcMainCui::vappUcTerminate);

    app->is_serialized = VFX_FALSE;
    app->group_id = GRP_ID_INVALID;
    return VFX_TRUE;
}    

VfxBool VcuiUcMainCui::handleDataOnSerialize(void *hint, VfxArchive &archive)
{

    U32 instance = m_app_data->main->instance;
    VappUcAppDataAfterSerialize *app = &(g_uc_app_data_serialized[instance]);
    VappUcAppArchive ucArchive={app,instance};
        
    //archive.writeU16((U32)hint); 
    archive.write((VfxU8 *)&ucArchive, sizeof(VappUcAppArchive));

    /* backup necesarry data into VappUcAppDataAfterSerialize */
    app->main            = m_app_data->main;
    app->send_info       = m_app_data->send_info;
    app->done            = m_app_data->done;
    app->m_service_cntxt = m_app_data->m_service_cntxt;

    app->archive_data.pre_msg_type            = m_app_data->pre_msg_type;
    app->archive_data.operation_type          = m_app_data->operation_type;
    app->archive_data.otherAppTempUcInfo      = m_app_data->otherAppTempUcInfo;
    app->archive_data.contact_insert_type     = m_app_data->contact_insert_type;  
    app->archive_data.available_size          = m_app_data->available_size;
    app->archive_data.taken_pref_phb_sim      = m_app_data->taken_pref_phb_sim;   
    app->archive_data.is_mma_active           = m_app_data->is_mma_active;
    app->archive_data.wait_to_close           = m_app_data->wait_to_close;
    app->archive_data.nvram_sim_id            = m_app_data->nvram_sim_id;
    app->archive_data.CurrAsyncPhbAddr        = m_app_data->CurrAsyncPhbAddr;    
    app->archive_data.WaitAsyncPhbRspToCloseUC= m_app_data->WaitAsyncPhbRspToCloseUC;
    app->archive_data.g_settingLimitation     = m_app_data->g_settingLimitation;
    app->archive_data.m_pbInsertState         = m_app_data->m_pbInsertState;
    app->archive_data.m_useSecondStage        = m_app_data->m_useSecondStage;
    app->archive_data.appBaseId               = m_app_data->appBaseId;
    app->archive_data.p_vapp_uc_asm           = m_app_data->p_vapp_uc_asm;

    app->is_serialized = VFX_TRUE;
    app->is_closing_cui = VFX_FALSE;
    app->group_id = getGroupId();
    
    memset( &(app->cui_result), 0, sizeof(VappUcCuiResult) );
    
    return VFX_TRUE;
}
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */ 

extern "C" mma_msg_storage_type_enum convertStorageTypeFromMmsToMma(srv_mms_msg_storage_enum storage_in)
{
    mma_msg_storage_type_enum storage_out = MMA_MSG_STORAGE_NONE;
    switch(storage_in)
    {
        case SRV_MMS_STORAGE_PHONE:
            storage_out = MMA_MSG_STORAGE_PHONE;             
            break;
        case SRV_MMS_STORAGE_CARD1:
            storage_out = MMA_MSG_STORAGE_CARD1;                
            break;                
        default:
            break;
    }

    return storage_out;
}

VfxBool VcuiUcMainCui::handleData(void* args, VfxU32 argsize)
{
    VappUcEntryStruct *data = (VappUcEntryStruct *)args;

    VFX_ALLOC_NEW(m_app_data, VappUcAppData, this);
    m_app_data->vappUcSetAppData();
    m_app_data->m_parent = (void *)this;

    m_app_data->appBaseId = ucGetAppBaseId(data,this->getGroupId());
    if( m_app_data->appBaseId == 0 )
    {
        MMI_ASSERT(0);
        vappUcDeInitData();
        m_app_data->m_signalTerminate.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_NMGR_BALLOON_TYPE_FAILURE);
        return VFX_FALSE;
    }
    m_app_data->p_vapp_uc_asm = (VappUcAppDataAfterSerializeBuffer *)vadpAsmAlloc(getGroupId(), VAPP_UC_SERIALIZE_ASM_SIZE); 
    if( !(m_app_data->p_vapp_uc_asm) )
        MMI_ASSERT(0);
    m_app_data->main            = &(m_app_data->p_vapp_uc_asm->main);
    m_app_data->send_info       = &(m_app_data->p_vapp_uc_asm->send_info);
    m_app_data->done            = &(m_app_data->p_vapp_uc_asm->done);
    m_app_data->m_service_cntxt = &(m_app_data->p_vapp_uc_asm->m_service_cntxt);

    memset(m_app_data->main, 0, sizeof(VappUcMainStruct));
    memset(m_app_data->send_info, 0, sizeof(VappUcSendInfoStruct));
    memset(m_app_data->done, 0, sizeof(VappUcDoneStruct));
    memset(m_app_data->m_service_cntxt, 0, sizeof(srv_uc_cntxt_reference_struct));

    if( VFX_FALSE == m_app_data->getServiceContext() )
    {
        vappUcDeInitData();
        m_app_data->m_signalTerminate.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_NMGR_BALLOON_TYPE_FAILURE);
        return VFX_FALSE;
    }

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
    vappUcResetSerialize(m_app_data->main->instance);
#endif        

 #ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
	EndKeyHandle[m_app_data->main->instance].EndKeyAppData = m_app_data;  
#endif     
    
    m_app_data->m_service_cntxt->main->app_id = getGroupId();
	{
		/*kuldeep_gplus*/
		VfxS16 error;
		U8 get_sim_id = 0;
		ReadValue(NVRAM_UC_APP_PREFER_SIM, &get_sim_id, DS_BYTE, &error);
		m_app_data->nvram_sim_id = (srv_uc_sim_id)get_sim_id ;
	}
    if(m_app_data->m_service_cntxt->send_info->action != SRV_UC_ACTION_IDLE)
    {
        vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE)), MMI_NMGR_BALLOON_TYPE_FAILURE);
        vappUcDeInitData();
        return VFX_FALSE;
    }

	m_app_data->m_signalTerminate.connect(m_app_data, &VappUcAppData::vappUcTerminateWithPopup);
	m_app_data->m_signalTerminateWtPopUp.connect(this, &VcuiUcMainCui::vappUcTerminate);

	m_app_data->main->max_text_limit = UC_MMS_MAX_TEXT_CHAR_COUNT;
#ifdef __MMI_EMAIL__
    if (data && data->edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
	{
		m_app_data->main->max_text_limit = UC_EMAIL_MAX_TEXT_CHAR_COUNT;
	}
#endif
    m_app_data->m_useSecondStage = VFX_TRUE;

    if(!data) /* WRITE MESSAGE  only from UM*/
    {
        m_app_data->m_useSecondStage = VFX_FALSE;
        m_app_data->m_service_cntxt->main->state = SRV_UC_STATE_WRITE_NEW_MSG;
        m_app_data->resetApp();

        m_app_data->m_service_cntxt->msg_type->setting_msg_type = srv_uc_get_setting_msg_type();
        m_app_data->m_service_cntxt->msg_type->curr_msg_type = m_app_data->m_service_cntxt->msg_type->setting_msg_type;
    #ifdef __MMI_MMS_STANDALONE_COMPOSER__
        m_app_data->m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;
    #else /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
		#ifndef __MMI_MMS_2__
			m_app_data->m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;
		#else
			m_app_data->m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_DEFAULT;
		#endif
    #endif /* __MMI_MMS_STANDALONE_COMPOSER__ */
        m_app_data->m_service_cntxt->msg_type->backup_msg_type = SRV_UC_MSG_TYPE_DEFAULT;
        m_app_data->m_service_cntxt->send_info->send_sim_id = vappUcGetCurrSimId();

        VfxS32 result = srv_uc_check_uc_folder(m_app_data->main->instance);
        if (result < 0)
        {
            //vappUcTerminate();
            vappUcDeInitData();
            //vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_NMGR_BALLOON_TYPE_FAILURE);
            m_app_data->m_signalTerminate.postEmit((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_NMGR_BALLOON_TYPE_FAILURE);
            return VFX_FALSE;
        }
        if(m_app_data->m_service_cntxt->main->state != SRV_UC_STATE_WRITE_NEW_MSG)
        {
            /* TODO: Show progressing screen */
        }
        srv_uc_get_sms_setting(m_app_data->main->instance);
        if(!m_app_data->getMmsSetting())
        {
            vappUcDeInitData();
            return VFX_FALSE;
        }
    }
    else if(data->type == SRV_UC_STATE_WRITE_NEW_MSG ||	/* WRITE MESSAGE from any application */
		(data->info_type == SRV_UC_INFO_TYPE_EMAIL && data->type == SRV_UC_STATE_EDIT_EXISTED_MSG ) ||
		(data->info_type == SRV_UC_INFO_TYPE_SMS_TEMPLATE && data->type == SRV_UC_STATE_EDIT_EXISTED_MSG ) ) 
    //else if(data->file_path) /* WRITE MESSAGE from filemanager */
    {
      #ifdef __MMI_MESSAGES_TEMPLATE__ 
        if(data->operation == UC_OPERATION_WRITE_NEW_SMS_TEMPLATE)
        {
            m_app_data->operation_type = (vappUcMsgOperationEnum)UC_OPERATION_WRITE_NEW_SMS_TEMPLATE;
            m_app_data->m_service_cntxt->msg_type->setting_msg_type = SRV_UC_MSG_TYPE_SMS_PREFER;
            m_app_data->m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_SMS_PREFER;
            m_app_data->m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;
            m_app_data->m_service_cntxt->send_info->send_sim_id = vappUcGetCurrSimId();
            m_app_data->main->max_text_limit = SRV_SMS_TEMPLATE_MAX_CHAR_NUM;
            VfxS32 result = srv_uc_check_uc_folder(m_app_data->main->instance);
            if (result < 0)
            {
                //vappUcTerminate();
                vappUcDeInitData();
                //vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_NMGR_BALLOON_TYPE_FAILURE);
                m_app_data->m_signalTerminate.postEmit((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_NMGR_BALLOON_TYPE_FAILURE);
                return VFX_FALSE;
            }
            srv_uc_get_sms_setting(m_app_data->main->instance);
            if(!m_app_data->getMmsSetting())
            {
                vappUcDeInitData();
                return VFX_FALSE;
            }
        }
        else
      #endif 
      #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        if(data->operation == UC_OPERATION_WRITE_NEW_MMS_TEMPLATE)
        {
            /* Create a new MMS Template */
            m_app_data->operation_type = (vappUcMsgOperationEnum)UC_OPERATION_WRITE_NEW_MMS_TEMPLATE;
            m_app_data->m_service_cntxt->msg_type->setting_msg_type = SRV_UC_MSG_TYPE_MMS_PREFER;
            m_app_data->m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_MMS_PREFER;
            m_app_data->m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;
            VfxS32 result = srv_uc_check_uc_folder(m_app_data->main->instance);
            m_app_data->m_service_cntxt->send_info->send_sim_id = vappUcGetCurrSimId();
            if (result < 0)
            {
                //vappUcTerminate();
                vappUcDeInitData();
                //vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_NMGR_BALLOON_TYPE_FAILURE);
                m_app_data->m_signalTerminate.postEmit((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_NMGR_BALLOON_TYPE_FAILURE);
                return VFX_FALSE;
            }
            srv_uc_get_sms_setting(m_app_data->main->instance);
            if(!m_app_data->getMmsSetting())
            {
                vappUcDeInitData();
                return VFX_FALSE;
            }
        }
        else
      #endif      
        if(data->info_type == SRV_UC_INFO_TYPE_EMAIL && data->type == SRV_UC_STATE_EDIT_EXISTED_MSG )
        {
        #ifdef __MMI_EMAIL__
            m_app_data->m_service_cntxt->msg_type->MMS_edit_mode = (srv_uc_MMS_edit_mode_enum)data->edit_mode;
            m_app_data->m_service_cntxt->send_info->send_sim_id = vappUcGetCurrSimId();
            if (m_app_data->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
                m_app_data->m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;
            }
        #endif /* __MMI_EMAIL__ */ 
            if(!m_app_data->ucEntryWriteMsgWithContent(data))
            {
                vappUcDeInitData();
                return VFX_FALSE;
            }
        }
		else if(data->operation == UC_OPERATION_EDIT_SMS_TEMPLATE)
        {
        #ifdef __MMI_MESSAGES_TEMPLATE__ 
            m_app_data->m_service_cntxt->msg_type->MMS_edit_mode = (srv_uc_MMS_edit_mode_enum)data->edit_mode;
            m_app_data->m_service_cntxt->main->state = SRV_UC_STATE_EDIT_EXISTED_MSG;
            m_app_data->m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_SMS_ONLY;
            m_app_data->m_service_cntxt->send_info->send_sim_id = vappUcGetCurrSimId();
            m_app_data->operation_type = data->operation;
            m_app_data->main->max_text_limit = SRV_SMS_TEMPLATE_MAX_CHAR_NUM;
            if(!m_app_data->ucEntryWriteMsgWithContent(data))
            {
                vappUcDeInitData();
                return VFX_FALSE;
            }
        #endif    
        }
        else
        {
            m_app_data->m_service_cntxt->msg_type->MMS_edit_mode = (srv_uc_MMS_edit_mode_enum)data->edit_mode;
            m_app_data->m_service_cntxt->main->state = SRV_UC_STATE_WRITE_NEW_MSG;
			if(data->launch_mode != UC_LAUNCH_MODE_NONE)
			{
				m_app_data->m_service_cntxt->send_info->send_sim_id = data->sim_id;
			}
			else
			{
				m_app_data->m_service_cntxt->send_info->send_sim_id = vappUcGetCurrSimId();
			}
            m_app_data->operation_type = data->operation;
			 m_app_data->m_service_cntxt->msg_type->caller_specific_msg_type = data->msg_type;
			m_app_data->main->launch_mode = data->launch_mode;
            if(!m_app_data->ucEntryWriteMsgWithContent(data))
            {
                vappUcDeInitData();
                return VFX_FALSE;
            }
        }
    }
#ifdef __MMI_MMS_2__
    else if(data->info_type == SRV_UC_INFO_TYPE_MMS)
    {
        /* Edit, Reply or Forward an existed MMS */
        
        m_app_data->resetApp();
        m_app_data->m_service_cntxt->main->state = (srv_uc_state_enum)srv_uc_convert_mms_app_mode_to_uc_state(data->mode);
        if (m_app_data->m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
        {
            m_app_data->m_service_cntxt->main->mode = SRV_UC_FORWARD_WITHOUT_EDIT_MODE;
            m_app_data->m_service_cntxt->main->state = SRV_UC_STATE_EDIT_EXISTED_MSG;
        }
        else if (m_app_data->m_service_cntxt->main->state == SRV_UC_STATE_SEND)
        {
            m_app_data->send_info->curr_folder = (U16) mma_get_box(data->msg_id);
        }
        m_app_data->m_service_cntxt->send_info->existed_msg_id = data->msg_id;
        m_app_data->m_service_cntxt->send_info->existed_msg_type = SRV_UC_MSG_TYPE_MMS_PREFER;
        
        if(data->curr_storage)
        {
            m_app_data->send_info->existed_msg_storage = convertStorageTypeFromMmsToMma( (srv_mms_msg_storage_enum) data->curr_storage );
        }
        else
        {
            m_app_data->send_info->existed_msg_storage = convertStorageTypeFromMmsToMma(srv_mms_get_msg_storage(data->msg_id));
        }
        
        if (m_app_data->m_service_cntxt->main->state == SRV_UC_STATE_REPLY || m_app_data->m_service_cntxt->main->state == SRV_UC_STATE_REPLY_ALL)
        {
            m_app_data->m_service_cntxt->send_info->send_sim_id = srv_uc_convert_sim_id(data->sim_id);
        }
        else
        {
            m_app_data->m_service_cntxt->send_info->send_sim_id = vappUcGetCurrSimId();
        }
        m_app_data->operation_type = data->operation;
		m_app_data->main->launch_mode = data->launch_mode;
        m_app_data->m_service_cntxt->msg_type->setting_msg_type = srv_uc_get_setting_msg_type();
        m_app_data->m_service_cntxt->msg_type->curr_msg_type = m_app_data->m_service_cntxt->msg_type->setting_msg_type;
    #ifdef __MMI_MMS_STANDALONE_COMPOSER__
        m_app_data->m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;
    #else 
        m_app_data->m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_DEFAULT;
    #endif 
        m_app_data->m_service_cntxt->msg_type->backup_msg_type = SRV_UC_MSG_TYPE_DEFAULT;
    #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
		if(m_app_data->operation_type == UC_OPERATION_EDIT_MMS_TEMPLATE)
		{
		m_app_data->m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;
		}
    #endif
    #if /*__MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__*/ 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_OP01_202_MMS_REPLY_BY_SMS_MMS_SUPPORT__ */ 
        VfxS32 result = srv_uc_check_uc_folder(m_app_data->main->instance);
        if (result < 0)
        {
            //vappUcTerminate();
            vappUcDeInitData();
            //vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_NMGR_BALLOON_TYPE_FAILURE);
            m_app_data->m_signalTerminate.postEmit((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_NMGR_BALLOON_TYPE_FAILURE);
            return VFX_FALSE;
        }
        m_app_data->main->busy_getting_data = 1;
        if(!m_app_data->getMmsSetting())
        {
            vappUcDeInitData();
            return VFX_FALSE;
        }
    }
#endif
    else if(data->info_type == SRV_UC_INFO_TYPE_SMS)
    {
        /* Edit, Reply or Forward an existed SMS */
        
        VFX_SYS_ALLOC_MEM(m_app_data->otherAppTempUcInfo, sizeof(VappUcEntryStruct));
        if(m_app_data->otherAppTempUcInfo)
        {
            memset(m_app_data->otherAppTempUcInfo, 0, sizeof(VappUcEntryStruct));
        }
        else
        {
            ASSERT(0);
        }
        m_app_data->m_service_cntxt->send_info->send_sim_id = vappUcGetCurrSimId();

#ifdef  __MMI_SMS_TCARD_STORAGE_SUPPORT__
        if(data->curr_storage)
        {
             if ( (srv_sms_storage_enum)data->curr_storage == SRV_SMS_STORAGE_TCARD);
             m_app_data->send_info->existed_msg_storage = MMA_MSG_STORAGE_CARD1;
        }
        else
        {
            if(srv_sms_get_msg_storage_type(data->msg_id)== SRV_SMS_STORAGE_TCARD)
                m_app_data->send_info->existed_msg_storage = MMA_MSG_STORAGE_CARD1;
        }
#endif        
        m_app_data->main->busy_getting_data = 1;
        m_app_data->ucSmsMsgOperationTrigger(data);
    }
/*    else if(data->info_type == SRV_UC_INFO_TYPE_EMAIL)
    {
        VFX_SYS_ALLOC_MEM(m_app_data->otherAppTempUcInfo, sizeof(VappUcEntryStruct));
        if(m_app_data->otherAppTempUcInfo)
        {
            memset(m_app_data->otherAppTempUcInfo, 0, sizeof(VappUcEntryStruct));
        }
        else
        {
            ASSERT(0);
        }
        m_app_data->main->busy_getting_data = 1;
        m_app_data->ucSmsMsgOperationTrigger(data);
    }    */
    vappUcDeInitData();
    return VFX_TRUE;
}

#ifdef __MMI_MMS_USE_ASM__  
VfxAppCloseAnswerEnum VcuiUcMainCui::onProcessClose(VfxAppCloseOption options)
{
    m_inCloseProcess = VFX_TRUE;
    if(m_app_data)
    {
        if(isWaitToBeClose())
        {        

            return VFX_APP_CLOSE_ANSWER_LATER;
        }
    }
    m_inCloseProcess = VFX_FALSE;
    return VFX_APP_CLOSE_ANSWER_YES;
}
VfxBool VcuiUcMainCui::callContinueClose(void)
{
    if(m_inCloseProcess)
    { 
        continueClose(VFX_APP_CLOSE_ANSWER_YES);
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}
void VcuiUcMainCui::setWaitToBeClose(VfxBool isWaitToBeClose)
{
    m_isWaitToBeClose = isWaitToBeClose;
}
VfxBool VcuiUcMainCui::isWaitToBeClose(void)
{
    return m_isWaitToBeClose;    
}

mmi_ret VcuiUcMainCui::onMmsSrvEvtCb(mmi_event_struct *param)
{
    VcuiUcMainCui *self = (VcuiUcMainCui *)VfxObject::handleToObject((VfxObjHandle)param->user_data);
    
    
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "[UC] onMmsSrvEvtCb");
    
    /* Need to check if it is NULL pointer. Otherwise, it may cause fatal error of NULL pointer access */
    if (NULL != self)
    {
        VappUcAppData *app = self->m_app_data;

        self->setWaitToBeClose(VFX_FALSE);
        if( self->callContinueClose() == VFX_FALSE) 
        {
            if(NULL != app && app->wait_to_close )
            {
                self->vappUcTerminate();
            }
        }
    }
    return MMI_RET_OK;
}
#endif

void VappUcAppData::vappUcTerminateWithPopup(WCHAR* str, mmi_nmgr_balloon_type_enum type)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TERMINATE_WITH_POPUP);
    VcuiUcMainCui *app = (VcuiUcMainCui *)m_parent;
    app->vappUcTerminate();
    vappUcDisplayPopup(str, type);
}

void VcuiUcMainCui::vappUcTerminate(void)
{
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TERMINATE);
	m_app_data->main->skip_save_on_deinit = VFX_TRUE;
    VfxAppLauncher::terminate(getGroupId());
}


extern "C" void ucMsgOperationTriggerCallback(srv_sms_callback_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sms_msg_data_struct * msg_data;
    VappUcAppData *app = (VappUcAppData *)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!vappUcCheckAppSanity((void *)app))
	{
		return;
	}
	msg_data = (srv_sms_msg_data_struct *)(((srv_sms_read_msg_cb_struct*)callback_data->action_data)->msg_data);

    if (callback_data->result)
    {
        if(msg_data->is_with_obj &&
            (app->main->msg_operation == UC_OPERATION_FORWARD ||
            app->main->msg_operation == UC_OPERATION_EDIT_EXISTED_MSG))
        {
            if (msg_data)
	        {
		        OslMfree(msg_data);
		        msg_data = NULL;
	        }
            /* TODO:
			mmi_uc_enable_csk_for_confirmation_popup();
            mmi_uc_setSoftkeyFunction(
                mmi_uc_msg_operation_trigger_ems_object_yes_callback,
				mmi_uc_msg_operation_trigger_ems_object_no_callback,
                (U8) mmi_get_event_based_sound(MMI_EVENT_QUERY),
                (U16) STR_ID_VAPP_UC_REMOVE_EMS_OBJECT_CONFIRM);
            mmi_uc_entry_displayConfirm_generic();
            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
            */
            return;
        }
        if (msg_data)
	    {
		    OslMfree(msg_data);
		    msg_data = NULL;
	    }
        switch (app->main->msg_operation)
        {
            case UC_OPERATION_FORWARD:
            case UC_OPERATION_EDIT_EXISTED_MSG:
            {
                app->ucPreEntryForSms();
                break;
            }

            default:
                app->ucPreEntryForSms();
                break;
        }
    }
    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    else if(callback_data->cause == SRV_SMS_CAUSE_ARCH_FILE_NOT_EXIST)
    {
        /* 
		mmi_uc_disable_csk_for_confirmation_popup();
        mmi_uc_setSoftkeyFunction(
            mmi_uc_delete_arch_msg_yes_callback,
            mmi_uc_go_back_history_from_confirm,
            (U8) mmi_get_event_based_sound(MMI_EVENT_QUERY),
            (U16) STR_ID_VAPP_UC_CORRUPT_MSG_DELETE_CONFIRM);
        mmi_uc_entry_displayConfirm_generic();
        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING); */
    }
    #endif
    else
    {
        // might require to show any popup.
        if (msg_data)
	    {
		    OslMfree(msg_data);
		    msg_data = NULL;
	    }
        app->m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_UNFINISHED)), MMI_NMGR_BALLOON_TYPE_FAILURE); 
        app->m_signalConnectOnError.postEmit();
    }
}

MMI_BOOL VappUcAppData::ucSmsMsgOperationTrigger(VappUcEntryStruct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_msg_data_struct * msg_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/* Moved to handleData()
    VFX_ALLOC_MEM(otherAppTempUcInfo, sizeof(VappUcEntryStruct), this);
    if(otherAppTempUcInfo)
    {
        memset(otherAppTempUcInfo, 0, sizeof(VappUcEntryStruct));
    }
    else
    {
        ASSERT(0);
    }
*/
    m_service_cntxt->send_info->existed_msg_id = data->msg_id;
    main->msg_operation = data->operation;
    msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
    memset(msg_data, 0, sizeof(srv_sms_msg_data_struct));

    msg_data->para_flag = SRV_SMS_PARA_CONTENT_BUFF;
    msg_data->content_buff_size = 160 * (SRV_SMS_MAX_SEG) * ENCODING_LENGTH; //MMI_UC_MAX_SMS_CONTENT  * ENCODING_LENGTH;

    VFX_SYS_ALLOC_MEM(msg_data->content_buff, msg_data->content_buff_size);
    memset(msg_data->content_buff, 0, msg_data->content_buff_size);

    otherAppTempUcInfo->text_buffer = (U8 *)msg_data->content_buff;

	  otherAppTempUcInfo->msg_type = data->msg_type ; /*kuldeep_change_legler*/
//    msg_data->content_buff;
    //msg_data->para_flag = SRV_SMS_PARA_CONTENT_BUFF;
    /*  it will read the SMS as text format
    we will skip the EMS's object if exists*/

    //msg_data->content_ems = (EMSData*)GetEMSDataForView(NULL, 1);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    msg_data->para_flag |= SRV_SMS_PARA_PID;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

    srv_sms_read_msg(
        data->msg_id,
        MMI_FALSE,
        msg_data,
        ucMsgOperationTriggerCallback,
        (void*)this);
    return MMI_TRUE;
}

void VappUcAppData::ucPreEntryForSms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_add_num = MMI_TRUE;
    MMI_BOOL is_add_content = MMI_TRUE;
    S8 *ucs2_addr = NULL;
    VappUcEntryStruct *uc_data = otherAppTempUcInfo;
    srv_uc_addr_struct *addr;
    U32 state_type = 0;
    //mmi_id uc_cui_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    uc_data->info = &m_service_cntxt->send_info->existed_msg_id;

    //uc_data->msg_type = SRV_UC_MSG_TYPE_DEFAULT;/*kuldeep_change_legler*/
    uc_data->info_type = SRV_UC_INFO_TYPE_SMS;
#if (MMI_MAX_SIM_NUM >= 2)
    uc_data->sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
#endif /* MMI_MAX_SIM_NUM */

    switch (main->msg_operation)
    {
        case UC_OPERATION_REPLY:
        {
        #if (MMI_MAX_SIM_NUM >= 2)
            srv_sms_sim_enum sms_sim_id;
        #endif /* MMI_MAX_SIM_NUM */

            is_add_content = MMI_FALSE;

            state_type = SRV_UC_STATE_REPLY;

        #if (MMI_MAX_SIM_NUM >= 2)
            sms_sim_id = srv_sms_get_msg_sim_id(m_service_cntxt->send_info->existed_msg_id);

           uc_data->sim_id = vappUcConvertSMSSimIdToUc(sms_sim_id);
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
#endif
		#else
			uc_data->sim_id = m_service_cntxt->send_info->send_sim_id ;
        #endif /* MMI_MAX_SIM_NUM */
            break;
        }
        /*comment :need to check archive reply here */
        case UC_OPERATION_FORWARD:
        {
            is_add_num = MMI_FALSE;
            state_type = SRV_UC_STATE_FORWARD;
			uc_data->sim_id = m_service_cntxt->send_info->send_sim_id ;
            break;
        }

        case UC_OPERATION_EDIT_EXISTED_MSG:
        {
            state_type = SRV_UC_STATE_EDIT_EXISTED_MSG;
			uc_data->sim_id = m_service_cntxt->send_info->send_sim_id ;
            break;
        }
            
        default:
        {
            ASSERT(0);
            break;
        }
    }
    if (is_add_content == MMI_TRUE)
    {
//        uc_data->text_buffer = main->sms_temp_text_buffer;
        uc_data->text_num = mmi_ucs2strlen((PS8)uc_data->text_buffer);
    }
    else
    {
//        uc_data->text_buffer = NULL;
        uc_data->text_num = 0;
    }
    if (is_add_num == MMI_TRUE)
    {
	#ifdef __SRV_SMS_MULTI_ADDR__
		uc_data->addr_num = srv_sms_get_msg_addr_num(m_service_cntxt->send_info->existed_msg_id);
		if(uc_data->addr_num > 1)
		{
			g_app.curr_app = this;
			uc_data->get_address_callback = vapp_uc_get_sms_address_callback;		
		}
		else
	#endif
		{
			uc_data->addr_num = 0;
            VFX_SYS_ALLOC_MEM(ucs2_addr, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
		    memset(ucs2_addr, 0, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
            VFX_SYS_ALLOC_MEM(addr, sizeof(srv_uc_addr_struct));
		    memset(addr, 0, sizeof(srv_uc_addr_struct));
            srv_sms_get_msg_address(m_service_cntxt->send_info->existed_msg_id, ucs2_addr);
            addr->addr = (kal_uint8 *) ucs2_addr;
            if (mmi_ucs2strlen((PS8)addr->addr) > 0)
            {
                uc_data->addr_num++;
                if (mmi_ucs2chr((PS8)addr->addr, L'@') == NULL)
                {
                    addr->type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
                }
                else
                {
                    addr->type = SRV_UC_ADDRESS_TYPE_EMAIL;
                }
                addr->group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
                uc_data->addr = addr;
            }
            uc_data->get_address_callback = NULL;
        }
    }
    uc_data->type = (srv_uc_state_enum)state_type;
    ucEntryWriteMsgWithContent(uc_data);

    #ifdef  __MMI_SMS_TCARD_STORAGE_SUPPORT__
        if(uc_data->curr_storage)
        {
             if ( (srv_sms_storage_enum)uc_data->curr_storage == SRV_SMS_STORAGE_TCARD);
                 send_info->existed_msg_storage = MMA_MSG_STORAGE_CARD1;
        }
        else
        {
            if(srv_sms_get_msg_storage_type(m_service_cntxt->send_info->existed_msg_id)== SRV_SMS_STORAGE_TCARD)
                send_info->existed_msg_storage = MMA_MSG_STORAGE_CARD1;
        }
   #endif  

/*    if (ucs2_addr != NULL)
    {
        OslMfree(ucs2_addr);
        //uc_data->addr
    }*/
    if(otherAppTempUcInfo)
    {
	#ifdef __SRV_SMS_MULTI_ADDR__
		if(otherAppTempUcInfo->addr_num > 1)
		{
			g_app.curr_app = NULL;
		}
	#endif
        if(otherAppTempUcInfo->text_buffer)
        {
            VFX_SYS_FREE_MEM(otherAppTempUcInfo->text_buffer);
            otherAppTempUcInfo->text_buffer = NULL;
        }
        ucFreeCollectedObjectIndData();
    }
}


void VappUcAppData::ucFreeCollectedObjectIndData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_addr_struct *addr_top_node = otherAppTempUcInfo->addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (addr_top_node)
    {
        srv_uc_addr_struct *temp_node_p = addr_top_node->next;

        VFX_SYS_FREE_MEM(addr_top_node->addr);
        VFX_SYS_FREE_MEM(addr_top_node);
        addr_top_node = temp_node_p;
    }
    VFX_SYS_FREE_MEM(otherAppTempUcInfo);
    otherAppTempUcInfo = NULL;
}

extern "C" U16 vapp_uc_entry_validation_checks_for_recipient(srv_uc_addr_struct *addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 string_id = STR_GLOBAL_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((addr->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER) && (mmi_ucs2strlen((S8*) addr->addr) == 0))
    {
        string_id = STR_ID_VAPP_UC_NUM_CANNOT_BE_EMPTY_ID;
    }
    else if ((addr->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER) &&
             (vapp_uc_is_ascii_string((S8*) addr->addr) && srv_uc_is_phone_number_valid((S8*) addr->addr) == KAL_FALSE))
    {
        string_id = STR_ID_VAPP_UC_INVALID_RECIPIENT;//STR_GLOBAL_INVALID_NUMBER;
    }
    else if ((addr->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER) &&
             (mmi_ucs2strlen((S8*) addr->addr) > SRV_UC_MAX_PHONE_NUMBER_LEN))
    {
        string_id = STR_ID_VAPP_UC_NUMBER_LENGTH_EXCEED_ID;
    }
    else if ((addr->type == SRV_UC_ADDRESS_TYPE_EMAIL) &&
             applib_is_valid_email_address_unicode((kal_wchar*) addr->addr) == KAL_FALSE)
    {
        string_id = STR_ID_VAPP_UC_INVALID_RECIPIENT;//STR_GLOBAL_INVALID_EMAIL_ADDRESS;
    }
    return string_id;
}

VfxBool VappUcAppData::ucEntryWriteMsgWithContent(VappUcEntryStruct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 addr_num = 0;
    S32 media_num = 0;
    srv_uc_addr_struct *addr = data->addr;
    mma_mms_object_struct *object;
    VappUcTextInfoStruct text_info;
    U8 *mmi_uc_text_path = NULL;
    S32 result;
    U16 msg_id = 0;
    U16 error_string = STR_GLOBAL_OK;
    VfxBool simAlreadySet = VFX_FALSE;
//    kal_uint32 current_tick_count ;
 //   kal_uint32 tick_count_at_start;
 //   kal_uint32 time_gap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ENTRY_WRITE_MSG_WITH_CONTENT_P2, data->type, data->info_type);
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_START_ENTRY_WRITE_MSG_WITH_CONTENT);
//    kal_get_time(&tick_count_at_start);

    /* if caller only give one phone number, and the number exceed its max digit limitaton, popup here */
    /* if there are many addresses, will continue, but the number which exceed number digit limitation will not be added */
    if (data->get_address_callback)
    {
        // Skip here do operation later */
        /* Addr should be NULL if there is callback register for getting input. */
        ASSERT(data->addr == NULL);
    }
    else
    {
        if (data->addr_num == 1)
        {
            U16 string_id = vapp_uc_entry_validation_checks_for_recipient(data->addr);

            if (string_id != STR_GLOBAL_OK)
            {
                /*
                mmi_uc_handle_progress_entry_composer_write_msg_on_fail();

                #ifdef __MMI_FTE_SUPPORT__
                    //DeleteScreenIfPresent(SCR_ID_UC_PROCESSING);
                mmi_frm_scrn_close (main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                #endif */
                if(data->file_path && data->auto_delete_file)
                {
                    FS_Delete((WCHAR*) data->file_path);
                    data->auto_delete_file = FALSE;
                }
                if (data->callback != NULL)
                {
                    data->callback((void*)data->callback_para);
                }
                /*
				mmi_frm_group_close (main->uc_cui_gid);
				main->uc_cui_gid = GRP_ID_INVALID; */
                //app->vappUcTerminate();
                // Show popup
				m_signalTerminate.postEmit((WCHAR*)((UI_string_type) GetString(string_id)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                //vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(string_id)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                return VFX_FALSE;
            }
        }
    }
    if (data->type != SRV_UC_STATE_WRITE_NEW_MSG)
    {
    #ifndef __MMI_MMS_STANDALONE_COMPOSER__
        if (data->info_type == SRV_UC_INFO_TYPE_SMS)
        {
            msg_id = *((U16*)data->info);
        }
    #endif
    }
/*
    if (mmi_frm_group_get_active_id() == main->uc_cui_gid &&  main->uc_cui_gid == GRP_ID_UNIFIED_COMPOSER)
    {
        group_id = main->uc_cui_gid;
        main->uc_cui_gid = GRP_ID_INVALID;
    }
	else 
	{
		mmi_frm_group_close (main->uc_cui_gid);
		main->uc_cui_gid = GRP_ID_INVALID;
	}
*/
    resetApp();

    result = srv_uc_check_uc_folder(main->instance);

    if (result < 0)
    {
        if(data->file_path && data->auto_delete_file)
        {
            FS_Delete((WCHAR*) data->file_path);
            data->auto_delete_file = FALSE;
        }
        /*mmi_uc_handle_progress_entry_composer_write_msg_on_fail(); */
        if (data->callback != NULL)
        {
            data->callback((void*)data->callback_para);
        }
        //app->vappUcTerminate();
        //vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_NMGR_BALLOON_TYPE_FAILURE);
        m_signalTerminate.postEmit((WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(result))), MMI_NMGR_BALLOON_TYPE_FAILURE);
        return VFX_FALSE;
    }

    m_service_cntxt->main->state = data->type;
	if(data->launch_mode != UC_LAUNCH_MODE_NONE)
	{
		m_service_cntxt->send_info->send_sim_id = data->sim_id;
        simAlreadySet = VFX_TRUE;
	}
	else
	{
		m_service_cntxt->send_info->send_sim_id = vappUcGetCurrSimId();
	}
    if (data->type != SRV_UC_STATE_WRITE_NEW_MSG)
    {
    #ifndef __MMI_MMS_STANDALONE_COMPOSER__
        if (data->info_type == SRV_UC_INFO_TYPE_SMS)
        {
			m_service_cntxt->send_info->send_sim_id = data->sim_id ;
            simAlreadySet = VFX_TRUE;
		}
		else
	#endif
		{
			m_service_cntxt->send_info->send_sim_id = vappUcGetCurrSimId();
		}
	}

    if (data->type != SRV_UC_STATE_WRITE_NEW_MSG)
    {
    #ifndef __MMI_MMS_STANDALONE_COMPOSER__
      #ifdef __MMI_MESSAGES_TEMPLATE__  
		if(data->operation == UC_OPERATION_EDIT_SMS_TEMPLATE)
		{
                m_service_cntxt->send_info->existed_msg_type = SRV_UC_MSG_TYPE_SMS_PREFER;
                m_service_cntxt->send_info->existed_msg_id = data->msg_id;		
		}
        else
      #endif      
        if (data->info_type == SRV_UC_INFO_TYPE_SMS)
        {

            if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
            {
                m_service_cntxt->main->state = SRV_UC_STATE_EDIT_EXISTED_MSG;
            }
        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            /* Treat edit archive box SMS msg as write new msg. */
            srv_sms_box_enum msg_box_type;
            srv_sms_get_msg_list_index(&msg_box_type, (U16)msg_id);
            if (m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG &&
                SRV_SMS_BOX_ARCHIVE == msg_box_type)
            {
                m_service_cntxt->main->state = SRV_UC_STATE_WRITE_NEW_MSG;
            }
            else
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */ 
            {
                m_service_cntxt->send_info->existed_msg_type = SRV_UC_MSG_TYPE_SMS_PREFER;
                m_service_cntxt->send_info->existed_msg_id = msg_id;
            }
        }
        else
        {
            ASSERT(0);
        }
    #else /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
        ASSERT(0);
    #endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
    }

    for (; addr_num < data->addr_num; addr_num++)
    {
        srv_uc_addr_struct *addr_node = NULL;

        if (data->get_address_callback)
        {
            srv_uc_addr_struct *addr_node_recieve = NULL;
            S32 str_length = 0;
           // U16 address_type = 0;

            ASSERT(addr == NULL);
            addr_node = (srv_uc_addr_struct *)OslMalloc(sizeof(srv_uc_addr_struct));
            memset(addr_node, 0, sizeof(srv_uc_addr_struct));
            addr_node_recieve = data->get_address_callback((kal_uint16) addr_num, data->callback_para);
            str_length = mmi_ucs2strlen((S8*) addr_node_recieve->addr);
            addr_node->addr = (kal_uint8 *)OslMalloc((str_length + 1) * ENCODING_LENGTH);
            memset(addr_node->addr, 0, (str_length + 1) * ENCODING_LENGTH);
            memcpy(addr_node->addr, addr_node_recieve->addr, (str_length + 1) * ENCODING_LENGTH);
         /*   addr_node->type =
                (address_type ==
                 MMI_PHB_ADDRESS_TYPE_NUMBER) ? SRV_UC_ADDRESS_TYPE_PHONE_NUMBER : SRV_UC_ADDRESS_TYPE_EMAIL;*/
            addr_node->group = addr_node_recieve->group;//SRV_UC_ADDRESS_GROUP_TYPE_TO;
            addr_node->type = addr_node_recieve->type;
            addr = addr_node;
        }

        ASSERT(addr);
        /* because pbh has valid number +(40 digit), but current UC only handle 40 digits or +(39 digits)
           so if the total digit > 40, will not allow user to add, because intercept number is meaningless */
        if (data->addr_num == 1)
        {
            U16 local_flag = vapp_uc_entry_validation_checks_for_recipient(addr);

            if (local_flag != STR_GLOBAL_OK)
            {
                if (addr_node)
                {
                    OslMfree(addr_node->addr);
                    OslMfree(addr_node);
                    addr_node = NULL;
                }
                if(data->file_path && data->auto_delete_file)
                {
                    FS_Delete((WCHAR*) data->file_path);
                    data->auto_delete_file = FALSE;
                }
                if (data->callback != NULL)
                {
                    data->callback((void*)data->callback_para);
                }
                //app->vappUcTerminate();
                //vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(local_flag)), MMI_NMGR_BALLOON_TYPE_FAILURE); 
                m_signalTerminate.postEmit((WCHAR*)((UI_string_type) GetString(local_flag)), MMI_NMGR_BALLOON_TYPE_FAILURE); 
                return VFX_FALSE;
            }
        }
        {
			U16 local_flag = vapp_uc_entry_validation_checks_for_recipient(addr);
			if (local_flag != STR_GLOBAL_OK)
			{
				/* will not added without showing popup */
				#ifdef __MMI_EMAIL__
				if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
				{
					error_string = STR_ID_VAPP_UC_INVALID_ADDRESSES_REMOVED;
				}
                else
				#endif
                {
					error_string = STR_ID_VAPP_UC_INVALID_RECIPIENTS_REMOVED;
                }
			}
			else if ((m_service_cntxt->msg->to_num) >= vappUcGetMaxRecipientCount())
			{
				/* the recipient limitation is vappUcGetMaxRecipientCount() */
			
				if(error_string == STR_GLOBAL_OK)
				{
					error_string = STR_ID_VAPP_UC_RECIPIENT_NUMBER_EXCEED_ID ;
				}
				break;
			}
            else
            {
                if(addr->type == SRV_UC_ADDRESS_TYPE_PHONE_NUMBER)
                {
                    mmi_sim_enum sim_id = MMI_SIM_NONE;
                    srv_phb_get_preferred_sim( (U16 *) addr->addr,
                    MMI_PHB_INVALID_CONTACT_ID,
                    SRV_PHB_NUMBER_OP_TYPE_MESSAGE,
                    &sim_id);
                    if(sim_id > MMI_SIM_NONE && sim_id < MMI_SIM_END_OF_ENUM
                        && data->launch_mode == UC_LAUNCH_MODE_NONE
                        && simAlreadySet != VFX_TRUE)
                    {
						taken_pref_phb_sim = VFX_TRUE ;
						if(vappUcGetValidSimInfo() & vappUcConvertMmiSimIdToUc(sim_id))
						{
							m_service_cntxt->send_info->send_sim_id = vappUcConvertMmiSimIdToUc(sim_id);
						}
                    }
                }

                srv_uc_add_address(main->instance, addr->addr, addr->type, addr->group);
            #ifdef __MMI_COSMOS_UC_CC_BCC_SUPPORT__      
			    if(addr->group == SRV_UC_ADDRESS_GROUP_TYPE_CC)
			    {
				    main->m_itemForceOn |= UC_RECIPIENT_CC;			
			    }
			    else if(addr->group == SRV_UC_ADDRESS_GROUP_TYPE_BCC)
			    {
				    main->m_itemForceOn |= UC_RECIPIENT_BCC;			
			    }
            #endif    
            }
		}
        addr = addr->next;
        if (addr_node)
        {
            OslMfree(addr_node->addr);
            OslMfree(addr_node);
            addr_node = NULL;
        }
    }
	if (m_service_cntxt->msg->to_num == 0 && error_string != STR_GLOBAL_OK)
	{
		#ifdef __MMI_EMAIL__
		if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
		{
			error_string = STR_GLOBAL_INVALID_EMAIL_ADDRESSES;
		}
		else
		#endif
		{
			error_string = STR_GLOBAL_INVALID_RECIPIENTS;
		}
        if(data->file_path && data->auto_delete_file)
        {
            FS_Delete((WCHAR*) data->file_path);
            data->auto_delete_file = FALSE;
        }
		if (data->callback != NULL)
		{
			data->callback((void*)data->callback_para);
		}
		m_signalTerminate.postEmit((WCHAR*)((UI_string_type) GetString(error_string)), MMI_NMGR_BALLOON_TYPE_FAILURE); 
		return VFX_FALSE;
	}
    m_service_cntxt->msg->msg_body.curr_slide = srv_uc_insert_slide(main->instance, NULL);
    m_service_cntxt->msg->current_slide_num = (U8)m_service_cntxt->msg->msg_body.curr_slide->slide_num;

    memset(m_service_cntxt->msg->subject, 0, sizeof(m_service_cntxt->msg->subject));
    if (mmi_ucs2strlen((S8*) data->subject))
    {
        mmi_ucs2ncpy((S8*) m_service_cntxt->msg->subject, (S8*) data->subject, vappUcGetMaxSubjectLength());
		main->m_itemForceOn |= UC_SUBJECT;		
    }

    /* text file */
    if (data->text_num)
    {
        {
            U32 buffer_size = 0;
            U8 *buffer = NULL;
            U32 buffer_len = 0;

            /* Discard the exceeding part */
            if (data->text_num > SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE)
            {
                data->text_num = SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE;
            }
            if (data->msg_type == SRV_UC_MSG_TYPE_SMS_ONLY && data->text_num > UC_MAX_SMS_CONTENT)
            {
                data->text_num = UC_MAX_SMS_CONTENT;
            }

            buffer_size = (data->text_num + 1) * ENCODING_LENGTH;
        #ifdef __MMI_EMAIL__
            if (data && data->edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
                buffer = data->text_buffer;
                buffer_len = mmi_ucs2strlen((S8*) buffer);
            }
            else
        #endif /*__MMI_EMAIL__*/
            {
				VFX_SYS_ALLOC_MEM(buffer, buffer_size);

				ASSERT(buffer_size <= SRV_UC_UTF8_TEXT_BUFFER_SIZE);

				memset(buffer, 0, buffer_size);
				srv_sms_remove_escape_char(
					(S8*) buffer,
					(S8*) data->text_buffer,
					(U16) data->text_num);
				buffer_len = mmi_ucs2strlen((S8*) buffer);
			}

            srv_uc_reset_text_buffer(main->instance);
            if (buffer_len <= (SRV_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH) - 1)
            {
                mmi_ucs2ncpy((S8*) m_service_cntxt->main->text_buffer, (S8*) buffer, buffer_len);
            }
            else
            {
                mmi_ucs2ncpy(
                    (S8*) m_service_cntxt->main->text_buffer,
                    (S8*) buffer,
                    (SRV_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH) - 1);
            }
        #ifdef __MMI_EMAIL__
            if (data && data->edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
        #endif /*__MMI_EMAIL__*/
			{
				VFX_SYS_FREE_MEM(buffer);
			}
        }

        mmi_uc_text_path = (U8 *)OslMalloc(SRV_UC_MAX_TEMP_FILE_LEN);
        memset(mmi_uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
        SRV_UC_MAKE_TEXT_FILE_PATH(mmi_uc_text_path, m_service_cntxt->msg->msg_body.curr_slide->slide_num, main->instance);

        memset(&text_info, 0, sizeof(VappUcTextInfoStruct));
        ucGetTextInfoForBuffer(&text_info, m_service_cntxt->main->text_buffer);

        result = srv_uc_save_buffer_to_file(
                    main->instance,
                    mmi_uc_text_path,
                    m_service_cntxt->main->text_buffer,
                    text_info.char_count);

        if (result == FS_NO_ERROR)
        {
            ucSetTextInfoToSlide(m_service_cntxt->msg->msg_body.curr_slide, &text_info);

            object = srv_uc_insert_object(main->instance, (S8*) mmi_uc_text_path, SRV_UC_OBJECT_TYPE_TEXT);
            srv_uc_insert_object_to_slide(
                main->instance,
                object,
                m_service_cntxt->msg->msg_body.curr_slide,
                SRV_UC_OBJECT_TYPE_TEXT);
            m_service_cntxt->msg->msg_body.curr_slide->txt.object->encoding = MMA_CHARSET_UTF8;   /* because the text's encode already UTF8 when mmi_uc_save_buffer_to_file to file */
        }
        else
        {
            if(data->file_path && data->auto_delete_file)
            {
                FS_Delete((WCHAR*) data->file_path);
                data->auto_delete_file = FALSE;
            }
            if (data->callback != NULL)
            {
                data->callback((void*)data->callback_para);
            }
            OslMfree(mmi_uc_text_path);
            mmi_uc_text_path = NULL;
            /*
			mmi_frm_group_close(main->uc_cui_gid);
			mmi_frm_group_close(group_id);
			main->uc_cui_gid = GRP_ID_INVALID; */
            //app->vappUcTerminate();
            {
                mmi_nmgr_balloon_type_enum type;
                WCHAR *str = vappUcGetSrvResultPopupStr(SRV_UC_STORAGE_FULL, &type);
                //vappUcDisplayPopup(str, type);
                m_signalTerminate.postEmit(str, type);
            }
            return VFX_FALSE;
        }
        OslMfree(mmi_uc_text_path);
        mmi_uc_text_path = NULL;
    }

    if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
    {
        m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
    }

    srv_uc_update_msg_size(main->instance);

    if (data->info_type == SRV_UC_INFO_TYPE_SMS)
    {
        ASSERT(data->file_path == NULL);
    }

    for (; media_num < data->media_num; media_num++)
    {
        //srv_uc_addr_struct *addr_node = NULL;

        if (data->get_media_callback)
        {
            U8 *temp_media_string = NULL;
            srv_uc_object_type media_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
            vapp_uc_media_info media_info = {0,};
            mma_mms_attachment_info_struct *att = NULL;
            mma_mms_object_struct *object = NULL;

            data->get_media_callback((kal_uint16) media_num, &media_info, (void *)data->callback_para);
//            str_length = mmi_ucs2strlen((S8*) temp_media_string);
/*            media_type =
                (media_num > 1) ? SRV_UC_OBJECT_TYPE_ATTACHMENT : media_type;*/
            media_type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
            if(media_info.is_virtual_file == MMI_TRUE)
            {
               // object = srv_uc_insert_object(main->instance, (S8*) media_info.file_path, media_type);
                object = srv_uc_insert_object_virtual_file(main->instance, (S8*) media_info.file_name, (S8*) media_info.file_path, media_type);
                //   object = srv_uc_insert_object_to_list_tail(main->instance);
                object->type = MMA_MMS_OBJECT_TYPE_ATTACHMENT;
                object->is_virtual_file = (kal_bool)media_info.is_virtual_file;
                object->size = media_info.size;
                object->offset = media_info.offset;
                object->auto_delete_file = (kal_bool)media_info.auto_delete_file;

                att = srv_uc_insert_attachment(main->instance);
                srv_uc_insert_object_to_attachment(object, att);
            }
            else
            {
              //object = srv_uc_insert_object(main->instance, (S8*) media_info.file_path, media_type);
              srv_uc_post_handler_handle_object_insert_if_file_path_exist(
                main->instance,
                (mma_insert_type_enum)srv_uc_convert_to_mms_insert_type(media_type),
                temp_media_string,
                (PU16)media_info.file_path);
            }
        }
    }
    if (data->file_path)
    {
        U32 flie_path_len = mmi_ucs2strlen((S8*) data->file_path);

        if (m_service_cntxt->main->file_path)
        {
            kal_adm_free(main->mem_pool_id, m_service_cntxt->main->file_path);
        }

        m_service_cntxt->main->file_path = (U8 *)kal_adm_alloc(main->mem_pool_id, (flie_path_len + 1) * ENCODING_LENGTH);
        ASSERT(m_service_cntxt->main->file_path);
        mmi_ucs2ncpy((S8*) m_service_cntxt->main->file_path, (S8*) data->file_path, flie_path_len);
        mmi_ucs2ncpy((S8*) main->file_path_to_delete, (S8*) data->file_path, flie_path_len);
        m_service_cntxt->main->auto_delete_file = data->auto_delete_file;
    }

    if (data->callback != NULL)
    {
        main->callback = data->callback;
        main->callback_para = data->callback_para;
    }

    m_service_cntxt->msg_type->setting_msg_type = srv_uc_get_setting_msg_type();
    m_service_cntxt->msg_type->curr_msg_type = m_service_cntxt->msg_type->setting_msg_type;

    if (data->msg_type == SRV_UC_MSG_TYPE_SMS_ONLY)
    {
        m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_SMS_PREFER;
    }
    else if (data->msg_type == SRV_UC_MSG_TYPE_MMS_ONLY)
    {
        m_service_cntxt->msg_type->curr_msg_type = SRV_UC_MSG_TYPE_MMS_PREFER;
    }

    m_service_cntxt->msg_type->caller_specific_msg_type = data->msg_type;
#ifdef __MMI_MMS_STANDALONE_COMPOSER__
    m_service_cntxt->msg_type->caller_specific_msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;
#endif /* __MMI_MMS_STANDALONE_COMPOSER__ */ 
    m_service_cntxt->msg_type->backup_msg_type = SRV_UC_MSG_TYPE_DEFAULT;
/*
    if (group_id == 0)
    {
        main->uc_cui_gid = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_UNIFIED_COMPOSER, mmi_uc_editor_proc, NULL);
        mmi_frm_group_enter(main->uc_cui_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }
    else
    {
        main->uc_cui_gid = group_id;
    }
    mmi_uc_process_entry_write_msg();
	kal_get_time(&current_tick_count);
	time_gap = (current_tick_count)-(tick_count_at_start);
	VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_EXIT_ENTRY_WRITE_MSG_WITH_CONTENT,time_gap);
*/
    srv_uc_get_sms_setting(main->instance);
    if(!getMmsSetting())
    {
        return  VFX_FALSE;
    }
    m_signalConnectOnPage.postEmit();
	if (error_string != STR_GLOBAL_OK)
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_WARNING, (WCHAR*)(VFX_WSTR_RES(error_string)).getBuf());
	}
    return VFX_TRUE;
}

void VappUcAppData::ucGenerateFilePath(mma_mms_object_struct * m_object, U8* virtual_file_name)
{
          if (m_object->is_virtual_file)
            {
                S32 result;
                U16 virtual_file_name_len =(SRV_FMGR_PATH_MAX_LEN + 1) * ENCODING_LENGTH/* sizeof(virtual_file_name)*/;

                memset(virtual_file_name, 0, virtual_file_name_len);
                if (m_service_cntxt->main->file_handle > 0)
                {
                    FS_Close(m_service_cntxt->main->file_handle);
                    m_service_cntxt->main->file_handle = 0;
                }

                m_service_cntxt->main->file_handle = FS_Open(m_object->file_path_ucs, FS_READ_ONLY | FS_OPEN_SHARED);

                if (m_service_cntxt->main->file_handle <= 0)
                {
                    return; 
                }

                result = FS_GenVirtualFileName(
                            m_service_cntxt->main->file_handle,
                            (U16*) virtual_file_name,
                            (unsigned int)FS_GenVFN_SIZE,
                            m_object->offset,
                            m_object->size);

                if (result < 0)
                {
                    return;
                }

                mmi_ucs2cat((PS8) virtual_file_name, (PS8) L".");
                if (srv_uc_get_file_extension(m_object->file_name_ucs) == NULL)
                {
                    return;
                }

                mmi_ucs2ncat(
                    (PS8) virtual_file_name,
                    (PS8) srv_uc_get_file_extension(m_object->file_name_ucs),
                    virtual_file_name_len / ENCODING_LENGTH);
                return;
            }
            else
            {
				mmi_ucs2cpy((CHAR*) virtual_file_name, (CHAR*)m_object->file_path_ucs);
                return;
            }
}

void VappUcAppData::ucGetTextInfoForBuffer(VappUcTextInfoStruct *text_info, U8 *text_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_7bit_counter_struct *count_info;
    S32 counter;
    U16 tmp_char;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    text_info->char_count = mmi_ucs2strlen((S8*) text_buffer);
    mmi_7bit_counter_init((U8*) text_buffer);
    count_info = mmi_7bit_counter_get_info();
    text_info->UCS2_count = count_info->ucs2_count;
    text_info->extension_char_count = count_info->gsm_ext_count;

    for (counter = 0; counter < (text_info->char_count * ENCODING_LENGTH); counter += ENCODING_LENGTH)
    {
        tmp_char = ((U16) text_buffer[counter + 1] << 8) | ((U8) text_buffer[counter]);
        text_info->utf8_msg_len += app_unicode_to_utf8_len(tmp_char);
    }
    mmi_7bit_counter_init((U8*) m_service_cntxt->main->text_buffer);
}

VfxBool VappUcAppData::ucCharInputHandler(VappUcTextInfoStruct *new_text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_2__
    max_size = mms_get_max_msg_size_in_restricted_mode();
    max_size =
        (m_service_cntxt->mms_info->creation_mode ==
         MMA_CREATION_MODE_RESTRICTED) && (max_size < (S32)m_service_cntxt->mms_info->max_mms_size) ? max_size : m_service_cntxt->mms_info->max_mms_size;
#else
    max_size = m_service_cntxt->mms_info->max_mms_size;
#endif
    if (new_text_info->char_count > vappUcGetMaxTextCharCount())
    {
        return VFX_FALSE;
    }
    else
    {
        if (m_service_cntxt->msg_type->caller_specific_msg_type == SRV_UC_MSG_TYPE_SMS_ONLY)
        {
            if (new_text_info->UCS2_count > 0)
            {
                if (new_text_info->char_count > (srv_sms_get_usable_text_len(SMSAL_UCS2_DCS) / 2))
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_UCS2_TEXT_SIZE_EXCEED);
                    return VFX_FALSE;
                }
            }
            else
            {
                if (new_text_info->char_count + new_text_info->extension_char_count >
                    (srv_sms_get_usable_text_len(SMSAL_DEFAULT_DCS) / 2))
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_ASCII_TEXT_SIZE_EXCEED);
                    return VFX_FALSE;
                }
            }
        }

        if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
        {
            if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count == 0)
            {
                U8 uc_text_path[SRV_UC_MAX_TEMP_FILE_LEN];
                U32 text_obj_size = 0;

                memset(uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
                SRV_UC_MAKE_TEXT_FILE_PATH(uc_text_path, m_service_cntxt->msg->current_slide_num, main->instance);
                if (srv_uc_get_mms_type(main->instance) == MMA_MMS_TYPE_SMIL_MMS)
                {
                    text_obj_size = mma_uc_calc_object_smil_size(MMA_INSERT_TEXT, (U16*) uc_text_path);
                }
                text_obj_size += mma_uc_calc_object_multipart_size((U16*) uc_text_path);

                if ((S32)(m_service_cntxt->msg->msg_size + text_obj_size + new_text_info->utf8_msg_len) > max_size)
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_MMS_SIZE_EXCEED_0_P3, m_service_cntxt->msg->msg_size, text_obj_size, new_text_info->utf8_msg_len);
                    return VFX_FALSE;
                }
            }
            else
            {
                U8 uc_text_path[SRV_UC_MAX_TEMP_FILE_LEN];
                U32 text_obj_size = 0;
				U32 filesize = 0;

                memset(uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
                SRV_UC_MAKE_TEXT_FILE_PATH(uc_text_path, m_service_cntxt->msg->current_slide_num, main->instance);
                if (srv_uc_get_mms_type(main->instance) == MMA_MMS_TYPE_SMIL_MMS)
                {
                    text_obj_size = mma_uc_calc_object_smil_size(MMA_INSERT_TEXT, (U16*) uc_text_path);
                }
                text_obj_size += mma_uc_calc_object_multipart_size((U16*) uc_text_path);
				filesize = mma_get_mmi_file_size(-1,  (const kal_wchar *)uc_text_path);
				text_obj_size = text_obj_size - filesize;

                if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count > new_text_info->char_count)
                {
                    /* Always allow to delete characters operation */
                }
                else if ((U32)(m_service_cntxt->msg->msg_size_without_text_buffer + new_text_info->utf8_msg_len + text_obj_size +
                          mma_uc_calc_text_uintvar_overhead_size(new_text_info->utf8_msg_len)) > (U32)max_size)
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_MMS_SIZE_EXCEED_P2, m_service_cntxt->msg->msg_size_without_text_buffer, new_text_info->utf8_msg_len);
                    return VFX_FALSE;
                }
            }
        }
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_ORI_P4, m_service_cntxt->msg->msg_body.curr_slide->txt.char_count, m_service_cntxt->msg->msg_body.curr_slide->txt.utf8_msg_len, m_service_cntxt->msg->msg_body.curr_slide->txt.extension_char_count, m_service_cntxt->msg->msg_body.curr_slide->txt.UCS2_count);

        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_NEW_P4, new_text_info->char_count, new_text_info->utf8_msg_len, new_text_info->extension_char_count, new_text_info->UCS2_count);
    }
    return VFX_TRUE;
}
VfxBool VappUcAppData::ucTextChangeHandler(VappUcTextInfoStruct *new_text_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 max_size = 0;
    VfxBool Is_delete_char = VFX_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_2__
    max_size = mms_get_max_msg_size_in_restricted_mode();
    max_size =
        (m_service_cntxt->mms_info->creation_mode ==
         MMA_CREATION_MODE_RESTRICTED) && (max_size < (S32)m_service_cntxt->mms_info->max_mms_size) ? max_size : m_service_cntxt->mms_info->max_mms_size;
#else
    max_size = m_service_cntxt->mms_info->max_mms_size;
#endif
    if (new_text_info->char_count > vappUcGetMaxTextCharCount())
    {
        return VFX_FALSE;
    }
    else
    {
        if (m_service_cntxt->msg_type->caller_specific_msg_type == SRV_UC_MSG_TYPE_SMS_ONLY)
        {
            if (new_text_info->UCS2_count > 0)
            {
                if (new_text_info->char_count > (srv_sms_get_usable_text_len(SMSAL_UCS2_DCS) / 2))
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_UCS2_TEXT_SIZE_EXCEED);
                    return VFX_FALSE;
                }
            }
            else
            {
                if (new_text_info->char_count + new_text_info->extension_char_count >
                    (srv_sms_get_usable_text_len(SMSAL_DEFAULT_DCS) / 2))
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_ASCII_TEXT_SIZE_EXCEED);
                    return VFX_FALSE;
                }
            }
        }

        if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
        {
            if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count == 0)
            {
                U8 uc_text_path[SRV_UC_MAX_TEMP_FILE_LEN];
                U32 text_obj_size = 0;

                memset(uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
                SRV_UC_MAKE_TEXT_FILE_PATH(uc_text_path, m_service_cntxt->msg->current_slide_num, main->instance);
                if (srv_uc_get_mms_type(main->instance) == MMA_MMS_TYPE_SMIL_MMS)
                {
                    text_obj_size = mma_uc_calc_object_smil_size(MMA_INSERT_TEXT, (U16*) uc_text_path);
                }
                text_obj_size += mma_uc_calc_object_multipart_size((U16*) uc_text_path);

                if ((S32)(m_service_cntxt->msg->msg_size + text_obj_size + new_text_info->utf8_msg_len) > max_size)
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_MMS_SIZE_EXCEED_0_P3, m_service_cntxt->msg->msg_size, text_obj_size, new_text_info->utf8_msg_len);
                    return VFX_FALSE;
                }
            }
            else
            {
                U8 uc_text_path[SRV_UC_MAX_TEMP_FILE_LEN];
                U32 text_obj_size = 0;
				U32 filesize = 0;

                memset(uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
                SRV_UC_MAKE_TEXT_FILE_PATH(uc_text_path, m_service_cntxt->msg->current_slide_num, main->instance);
                if (srv_uc_get_mms_type(main->instance) == MMA_MMS_TYPE_SMIL_MMS)
                {
                    text_obj_size = mma_uc_calc_object_smil_size(MMA_INSERT_TEXT, (U16*) uc_text_path);
                }
                text_obj_size += mma_uc_calc_object_multipart_size((U16*) uc_text_path);
				filesize = mma_get_mmi_file_size(-1,  (const kal_wchar *)uc_text_path);
				text_obj_size = text_obj_size - filesize;

                if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count > new_text_info->char_count)
                {
                    /* Always allow to delete characters operation */
                }
                else if ((U32)(m_service_cntxt->msg->msg_size_without_text_buffer + new_text_info->utf8_msg_len + text_obj_size +
                          mma_uc_calc_text_uintvar_overhead_size(new_text_info->utf8_msg_len)) > (U32)max_size)
                {
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_MMS_SIZE_EXCEED_P2, m_service_cntxt->msg->msg_size_without_text_buffer, new_text_info->utf8_msg_len); 
                    return VFX_FALSE;
                }
            }
        }
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_ORI_P4, m_service_cntxt->msg->msg_body.curr_slide->txt.char_count, m_service_cntxt->msg->msg_body.curr_slide->txt.utf8_msg_len, m_service_cntxt->msg->msg_body.curr_slide->txt.extension_char_count, m_service_cntxt->msg->msg_body.curr_slide->txt.UCS2_count);

        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TEXT_CHANGE_CB_NEW_P4, new_text_info->char_count, new_text_info->utf8_msg_len, new_text_info->extension_char_count, new_text_info->UCS2_count);
        if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count > new_text_info->char_count)
        {
            Is_delete_char = VFX_TRUE;
        }
        else
        {
            Is_delete_char = VFX_FALSE;
        }

        m_service_cntxt->msg->msg_body.curr_slide->txt.char_count = new_text_info->char_count;
        m_service_cntxt->msg->msg_body.curr_slide->txt.utf8_msg_len = new_text_info->utf8_msg_len;
        m_service_cntxt->msg->msg_body.curr_slide->txt.extension_char_count = new_text_info->extension_char_count;
        m_service_cntxt->msg->msg_body.curr_slide->txt.UCS2_count = new_text_info->UCS2_count;

        /* For better performance, only update text buffer to text object when char count is one or zero */
        /* That is, text object is existed or not. */
        if ((Is_delete_char == VFX_FALSE) && (new_text_info->char_count == 1) ||
            (Is_delete_char == VFX_TRUE) && (new_text_info->char_count == 0))
        {
            if (m_service_cntxt->msg->msg_body.curr_slide)
            {
                m_service_cntxt->main->current_text_file_save_result = srv_uc_handle_text_in_current_slide(main->instance);
            }
            /* actually, srv_uc_exit_write_msg */
            /* Tricky: because before return WGUI_UCE_TEXT_CHANGE_ALLOWED, editor will not copy string to dst:m_service_cntxt->main->text_buffer
               so, when srv_uc_save_buffer_to_file is called, no character will be saved to uc txt file, and obj size will not be updated.
               When wap call calculate api, use the obj->size, will use the wrong error -- */
            if (new_text_info->char_count == 1) /* only for add characters */
            {
                if (m_service_cntxt->main->current_text_file_save_result == FS_NO_ERROR)
                {
                    m_service_cntxt->msg->msg_body.curr_slide->txt.object->size =
                        m_service_cntxt->msg->msg_body.curr_slide->txt.utf8_msg_len;
                }
                else
                {
                    return VFX_FALSE;
                }
            }
            else
            {
                if (m_service_cntxt->main->current_text_file_save_result != FS_NO_ERROR)
                {
                    ASSERT(0);  /* because should can save successfully for delete char case */
                }
            }
            if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
            {
                m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
            }            
            srv_uc_update_msg_size(main->instance);
        }
        if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
        {
            m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
        }
        return VFX_TRUE;
    }
}

U32 VappUcAppData::ucGetAttachmentItemsTotalSize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    mma_mms_slide_struct *slide = m_service_cntxt->msg->msg_body.slides;
    mma_mms_attachment_info_struct *attachment = m_service_cntxt->msg->msg_body.attachment;
    U32 total_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* total_attachment_num = ref + attach obj */

    /* 1. Ref */
    for (i = 0; i < m_service_cntxt->msg->msg_body.slide_no; i++)
    {
        if (slide->ref_items != NULL)
        {
            mma_mms_slide_ref_object_struct *curr_ref = slide->ref_items;

            while (curr_ref != NULL)
            {
                total_size+= curr_ref->object->size;
                curr_ref = curr_ref->next;
            }
        }
        slide = slide->next;
    }

    /* 2. attachment */
    while (attachment != NULL)
    {
        total_size+= attachment->object->size;
        attachment = attachment->next;
    }
    return total_size;
}

void VappUcAppData::ucGetMmsSlideBarText(U16* text_buffer)
{
	U16 temp_buffer[24] = {0,};
    U16 temp_string_len = 24;

    sprintf((char*)temp_buffer, "%d/%d ", m_service_cntxt->msg->current_slide_num, m_service_cntxt->msg->msg_body.slide_no);
    mmi_asc_n_to_ucs2((S8*) text_buffer, (S8*) temp_buffer, temp_string_len);
    mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VAPP_UC_SLIDES_ID));
    return;
}

void VappUcAppData::ucGetComposerTitleString(U16* text_buffer)
{
    mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VAPP_UC_WRITE_MSG_ID));
#if (MMI_MAX_SIM_NUM >= 3)
    if (vappUcGetCurrValidSimCount() >= 3 || (main->sim_setting_primary_card != SRV_UC_SIM_ID_UNCLASSIFIED))
    {
        mmi_ucs2cat((PS8) text_buffer, (PS8) L"("); 
        if (m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM2)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
        }
        else if(m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM1)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
        }
		else if (m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM3)
		{
			mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
		}
		else if (m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM4)
		{
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));		
		}
        mmi_ucs2cat((PS8) text_buffer, (PS8) L")");    
    }
#elif (MMI_MAX_SIM_NUM >= 2)
    if (vappUcGetValidSimInfo() == (SRV_UC_SIM_ID_GSM_SIM1 | SRV_UC_SIM_ID_GSM_SIM2)
		|| (main->sim_setting_primary_card != SRV_UC_SIM_ID_UNCLASSIFIED))
    {
        mmi_ucs2cat((PS8) text_buffer, (PS8) L"("); 
        if (m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM2)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
        }
        else if(m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM1)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
        }
		else if (main->sim_setting_primary_card == SRV_UC_SIM_ID_GSM_SIM2)
		{
			mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
		}
		else	// if (main->sim_setting_primary_card == SRV_UC_SIM_ID_GSM_SIM1)
		{
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));		
		}
        mmi_ucs2cat((PS8) text_buffer, (PS8) L")");
    }
    #endif /* MMI_MAX_SIM_NUM */ 
    return;
}


void VappUcAppData::ucGetComposerSendString(U16* text_buffer)
{
    mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SEND));

#if (MMI_MAX_SIM_NUM >= 2)
    if (vappUcGetCurrValidSimCount() >= 2 || (main->sim_setting_primary_card != SRV_UC_SIM_ID_UNCLASSIFIED))
    {
        mmi_ucs2cat((PS8) text_buffer, (PS8) L"("); 
        if (m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM2)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
        }
        else if(m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM1)
        {
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
        }
		else if (m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM3)
		{
			mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
		}
		else if (m_service_cntxt->send_info->send_sim_id == SRV_UC_SIM_ID_GSM_SIM4)
		{
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));		
		}
        else if (main->sim_setting_primary_card == SRV_UC_SIM_ID_GSM_SIM2)
		{
			mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
		}
		else if (main->sim_setting_primary_card == SRV_UC_SIM_ID_GSM_SIM1)
		{
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));		
		}
        else if (main->sim_setting_primary_card == SRV_UC_SIM_ID_GSM_SIM3)
		{
			mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
		}
		else if (main->sim_setting_primary_card == SRV_UC_SIM_ID_GSM_SIM4)
		{
          mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));		
		}
        
        mmi_ucs2cat((PS8) text_buffer, (PS8) L")");    
    }
#endif /* MMI_MAX_SIM_NUM */ 

    return;
}


VfxBool VappUcAppData::handleUcUnSavedData(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop timer here to prevent the timer is timeout after UC screen does not exist 
       ps. in SRV_UC_ACTION_SAVE_IN_BACKGROUND, won't trigger create_rsp interrupt retry handling. */
#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
	if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER ||
		m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_ONLY)
	{
		EndKeyHandle[main->instance].NeedToFreeService = VFX_TRUE ;
	}
	else
	{
		VappUCFreeEndKeyHandleData(main->instance);
	}
#endif
	VappUcTextInfoStruct new_text_info = {0,};
	ucGetTextInfoForBuffer(&new_text_info, (U8*)m_service_cntxt->main->text_buffer);
	ucTextChangeHandler(&new_text_info);
	ucHandleTextInCurrentSlide();
    if (m_service_cntxt->send_info->action == SRV_UC_ACTION_IDLE)
    {
        if (isPendingContent())
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_WRITE_MSG_DELETE_HISTORY_HDLR_SAVE_IN_BG_P1, m_service_cntxt->msg_type->curr_msg_type);

            m_service_cntxt->send_info->action = SRV_UC_ACTION_SAVE_IN_BACKGROUND;

            /* Save the edited msg. */

          #ifdef __MMI_MESSAGES_TEMPLATE__
			if((operation_type == UC_OPERATION_WRITE_NEW_SMS_TEMPLATE) ||
					(operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE))
			{
                if(mmi_ucs2strlen((const CHAR*)m_service_cntxt->main->text_buffer) > SRV_SMS_TEMPLATE_MAX_CHAR_NUM)
                {
                    U8* text_buffer;
                    VFX_SYS_ALLOC_MEM(text_buffer, (SRV_SMS_TEMPLATE_MAX_CHAR_NUM + 1) * ENCODING_LENGTH);
                    memset(text_buffer, 0, (SRV_SMS_TEMPLATE_MAX_CHAR_NUM + 1) * ENCODING_LENGTH);
                    mmi_ucs2ncpy((CHAR*) text_buffer, (const CHAR*)m_service_cntxt->main->text_buffer, SRV_SMS_TEMPLATE_MAX_CHAR_NUM);
					srv_sms_template_save((const WCHAR*) text_buffer, (U16) SRV_SMS_TEMPLATE_MAX_CHAR_NUM * ENCODING_LENGTH);
                    VFX_SYS_FREE_MEM(text_buffer);
                    text_buffer = NULL;
                }
                else
                {
				   srv_sms_template_save((const WCHAR*) m_service_cntxt->main->text_buffer, (U16) m_service_cntxt->msg->msg_body.curr_slide->txt.char_count * ENCODING_LENGTH);
			    }			
			}					
            else
          #endif      
            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
            {
            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
				SMS_HANDLE save_handle;
				
            //    srv_uc_set_valid_sim(g_uc_p->main->instance);
				save_handle = srv_sms_get_save_handle();
#if 0
			 #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#endif /* MMI_MAX_SIM_NUM */
#endif
                srv_sms_set_sim_id(save_handle, vappUcConvertUCSimIdToSMS(m_service_cntxt->send_info->send_sim_id));
				if(m_service_cntxt->msg->to_head)
				{
					U8 ucs2Addr[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
					U16 addr_len;
		       
					addr_len = mmi_asc_n_to_ucs2((S8*)ucs2Addr, (S8*)m_service_cntxt->msg->to_head->addr, SRV_SMS_MAX_ADDR_LEN);
					ucs2Addr[addr_len] = '\0';
					ucs2Addr[addr_len + 1] = '\0';
		       
					srv_sms_set_address(save_handle, (S8*)ucs2Addr);
			#ifdef __SRV_SMS_MULTI_ADDR__ // support sms send group address
                    srv_uc_addr_struct *addr;
					addr = m_service_cntxt->msg->to_head;
					addr = addr->next;
					for (S32 i =1;i < m_service_cntxt->msg->to_num; i++)
					{
						WCHAR append_ucs2_addr[SRV_SMS_MAX_ADDR_LEN+1] = {0,};
		    
						addr_len = mmi_asc_n_to_ucs2((S8*)append_ucs2_addr, (S8*)addr->addr, SRV_SMS_MAX_ADDR_LEN);
						append_ucs2_addr[addr_len] = '\0';
						append_ucs2_addr[addr_len + 1] = '\0';
						srv_sms_append_address(save_handle, append_ucs2_addr, SRV_SMS_STATUS_UNSENT);
						addr = addr->next;
					}
			#endif /* __SRV_SMS_MULTI_ADDR__ */    
				}
			   /* Not handled yet
				sendData->status = SMSAL_STO_DRAFT; protocol support. save to draft*/
				srv_sms_set_status(save_handle, SRV_SMS_STATUS_DRAFT);
				srv_sms_set_content(save_handle, (S8*)m_service_cntxt->main->text_buffer, m_service_cntxt->msg->msg_body.curr_slide->txt.char_count * ENCODING_LENGTH);
				srv_sms_save_msg(save_handle, NULL, this);
            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                MMI_ASSERT(0);
            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
            }
			#ifdef __MMI_EMAIL__
			else if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
			{
				ucSaveEmailReq();
			}
			#endif
#ifdef __MMI_MMS_2__
            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
            {
                if (m_service_cntxt->msg->msg_size > m_service_cntxt->mms_info->max_mms_size)
                {
                #ifdef __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
                    /* Required as edit allowed on big MMS also. So restrict to save on end key. */
                    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_WRITE_MSG_DELETE_HISTORY_HDLR_RESET_MSG);
                    return FALSE;
                #else /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
                    /* because in size exceed case, not clear subject, if the screen is deleted at this time, the 
                       size will exceed the mms limitaion */
                    memset(m_service_cntxt->msg->subject, 0, sizeof(m_service_cntxt->msg->subject));
                #endif /* __MMI_OP12_MMS_MAX_SIZE_SUPPORT__ */ 
                }
				#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
				if(EndKeyHandle[main->instance].NeedToFreeService == VFX_TRUE)
				{
					srv_uc_copy_filename_filepath(main->instance);
					result = srv_uc_create_mms_xml_description_file(main->instance);
				}
				#endif

                if (result == FS_NO_ERROR)
                {
                #ifdef __MMI_MMS_TEMPLATE_SUPPORT__
                    if((operation_type == UC_OPERATION_WRITE_NEW_MMS_TEMPLATE) ||
							(operation_type == UC_OPERATION_EDIT_MMS_TEMPLATE))
					{
						ucCreateMmsReq(SRV_MMS_CREATE_SAVE_TEMPLATE_MMS);					
					}
					else
                #endif        
					{
						ucCreateMmsReq(SRV_MMS_CREATE_SAVE_MMS);
					}
                }
            }
#endif
        }
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_WRITE_MSG_DELETE_HISTORY_HDLR_DO_NOTHING);
    }
    return VFX_TRUE;
}

void VappUcAppData::ucGetMmsHintBarText(U16* text_buffer)
{
    FLOAT size = 0;
	U16 temp_buffer[24] = {0,};
    U16 temp_string_len = 24;
	U16 temp_UCS2_buffer[50] = {0,};

	   size = (FLOAT)( m_service_cntxt->msg->msg_body.curr_slide->txt.utf8_msg_len + m_service_cntxt->msg->msg_size_without_text_buffer) / (FLOAT) 1024.0;
      //  size = (FLOAT) m_service_cntxt->msg->msg_size / (FLOAT) 1024.0;

        /* Msg size */
        memset(temp_buffer, 0, temp_string_len);
	    mmi_ucs2cat((PS8) text_buffer, (PS8)GetString( STR_ID_VAPP_UC_TOTAL));
        sprintf((char*)temp_buffer, " %.1f ", size);
        mmi_asc_n_to_ucs2((S8*) temp_UCS2_buffer, (S8*) temp_buffer, temp_string_len);
	    mmi_ucs2cat((PS8) text_buffer, (PS8) temp_UCS2_buffer);
        memset(temp_UCS2_buffer, 0, 50);
	    mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VAPP_UC_KB_ID)); //TODO: Get string
        sprintf((char*)temp_buffer, "/%d ", m_service_cntxt->mms_info->max_mms_size/1024);
        mmi_asc_n_to_ucs2((S8*) temp_UCS2_buffer, (S8*) temp_buffer, temp_string_len);
	    mmi_ucs2cat((PS8) text_buffer, (PS8) temp_UCS2_buffer);
        mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VAPP_UC_KB_ID)); //TODO: Get string
        return;
}

S32 VappUcAppData::ucGetTotalNumberOfAttachment(void)
{
    return m_service_cntxt->msg->msg_body.total_attach_no;
}


void VappUcAppData::ucGetAttachmentString(U16* text_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S8 tempStr[50] = {0,};
    S32 temp_string_len = 50;
    S32 count = m_service_cntxt->msg->msg_body.total_attach_no;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(count > 1)
    {
        sprintf(tempStr, "%d ", count);
        mmi_asc_n_to_ucs2((S8*) text_buffer, (S8*) tempStr, temp_string_len - 1);
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VAPP_UC_ATTACHMENTS));
	    mmi_ucs2cat((PS8) text_buffer, (PS8) L" (");
         memset(tempStr, 0, sizeof(tempStr));
        ucGetSizeStringFromByteCount(ucGetAttachmentItemsTotalSize(), (U16*)tempStr);
        mmi_ucs2cat((PS8) text_buffer, (PS8)tempStr);
	    //mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_ID_VAPP_UC_KB_ID)); TODO: Get string
	    mmi_ucs2cat((PS8) text_buffer, (PS8) L")");
    }
    else
    {
        U32 i = 0;
        mma_mms_slide_struct *slide = m_service_cntxt->msg->msg_body.slides;
        mma_mms_attachment_info_struct *attachment = m_service_cntxt->msg->msg_body.attachment;


        /* total_attachment_num = ref + attach obj */

        /* 1. Ref */
        for (i = 0; i < m_service_cntxt->msg->msg_body.slide_no; i++)
        {
            if (slide->ref_items != NULL)
            {
                mma_mms_slide_ref_object_struct *curr_ref = slide->ref_items;

                if (curr_ref != NULL)
                {
                    U16 temp_string[25] = {0,};
                    mmi_ucs2cpy((S8*) text_buffer, (S8*) curr_ref->object->file_name_ucs);
                    ucGetSizeStringFromByteCount(curr_ref->object->size, temp_string);
	                mmi_ucs2cat((PS8) text_buffer, (PS8) L" (");
	                mmi_ucs2cat((PS8) text_buffer, (PS8) temp_string);
	                mmi_ucs2cat((PS8) text_buffer, (PS8) L")");
                    return;
                }
            }
            slide = slide->next;
        }

        /* 2. attachment */
        if (attachment != NULL)
        {
            U16 temp_string[25] = {0,};
            mmi_ucs2cpy((S8*) text_buffer, (S8*) attachment->object->file_name_ucs);
            ucGetSizeStringFromByteCount(attachment->object->size, temp_string);
            mmi_ucs2cat((PS8) text_buffer, (PS8) L" (");
            mmi_ucs2cat((PS8) text_buffer, (PS8) temp_string);
            mmi_ucs2cat((PS8) text_buffer, (PS8) L")");
            return;
        }
    }
    return;
}


void VappUcAppData::ucSetRefMediaCount(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i = 0;
    U32 submenu_index = 0;
    mma_mms_slide_struct *slide = m_service_cntxt->msg->msg_body.slides;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for (i = 0; i < m_service_cntxt->msg->msg_body.slide_no; i++)
    {
        if (slide->ref_items != NULL)
        {
            mma_mms_slide_ref_object_struct *curr_ref = slide->ref_items;

            while (curr_ref != NULL)
            {
                submenu_index++;
                curr_ref = curr_ref->next;
            }
        }
        slide = slide->next;
    }
    m_service_cntxt->msg->msg_body.total_ref_no = submenu_index;
}


void VappUcAppData::ucGetAttachmentItemList(U16 attachmentlist[][260], U16 attachmentSizeList[][UC_MAX_SIZE_STRING], VfxS32 *attachment_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    U32 submenu_index = 0;  /* subMenuDataPtrs[] -- start from 0 */
    mma_mms_slide_struct *slide = m_service_cntxt->msg->msg_body.slides;

    mma_mms_attachment_info_struct *attachment = m_service_cntxt->msg->msg_body.attachment;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* total_attachment_num = ref + attach obj */

    /* 1. Ref */
    for (i = 0; i < m_service_cntxt->msg->msg_body.slide_no; i++)
    {
        if (slide->ref_items != NULL)
        {
            mma_mms_slide_ref_object_struct *curr_ref = slide->ref_items;

            while (curr_ref != NULL)
            {
                mmi_ucs2cpy((S8*) attachmentlist[submenu_index], (S8*) curr_ref->object->file_name_ucs);
                ucGetSizeStringFromByteCount(curr_ref->object->size, attachmentSizeList[submenu_index]);
                submenu_index++;
                ASSERT(submenu_index <= m_service_cntxt->msg->msg_body.total_attach_no);
                curr_ref = curr_ref->next;
            }
        }
        slide = slide->next;
    }
    m_service_cntxt->msg->msg_body.total_ref_no = submenu_index;

    /* 2. attachment */
    while (attachment != NULL)
    {
        mmi_ucs2cpy((S8*) attachmentlist[submenu_index], (S8*) attachment->object->file_name_ucs);
        ucGetSizeStringFromByteCount(attachment->object->size, attachmentSizeList[submenu_index]);
        submenu_index++;
        ASSERT(submenu_index <= m_service_cntxt->msg->msg_body.total_attach_no);
        attachment = attachment->next;
    }
    *attachment_count = submenu_index;
    return ;
}


void VappUcAppData::ucEntryNextSlide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide = m_service_cntxt->msg->msg_body.curr_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    ASSERT(slide->next);
    ucHandleTextInCurrentSlide(); /* we can force call too. But put here to see switchSlide call as generic. *///vikas
    if(slide->next == NULL)
    {
       m_service_cntxt->msg->msg_body.curr_slide = m_service_cntxt->msg->msg_body.slides;
    }
    else
    {
       m_service_cntxt->msg->msg_body.curr_slide = slide->next;
    }
    m_service_cntxt->msg->current_slide_num = (U8)m_service_cntxt->msg->msg_body.curr_slide->slide_num;

    switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
    if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
    {
        m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
    }
    srv_uc_update_msg_size(main->instance);
   
}


void VappUcAppData::ucEntryPreviousSlide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide = m_service_cntxt->msg->msg_body.curr_slide;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   // ASSERT(slide->prev);
    ucHandleTextInCurrentSlide(); /* we can force call too. But put here to see switchSlide call as generic. *///vikas
    if(slide->prev == NULL)
    {
        while (slide && (slide->slide_num < m_service_cntxt->msg->msg_body.slide_no))
        {            
            slide = slide->next;
        }
       m_service_cntxt->msg->msg_body.curr_slide = slide;
    }
    else
    {
       m_service_cntxt->msg->msg_body.curr_slide = slide->prev;
    }
    m_service_cntxt->msg->current_slide_num = (U8)m_service_cntxt->msg->msg_body.curr_slide->slide_num;

    switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
    if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
    {
        m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
    }
    srv_uc_update_msg_size(main->instance);

}

S32 VappUcAppData::ucHandleTextInCurrentSlide(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 uc_text_path[SRV_UC_MAX_TEMP_FILE_LEN];
    mma_mms_object_struct *object = NULL;
    S32 result = FS_NO_ERROR;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(uc_text_path, 0, SRV_UC_MAX_TEMP_FILE_LEN);
    SRV_UC_MAKE_TEXT_FILE_PATH(uc_text_path, m_service_cntxt->msg->current_slide_num, main->instance);

	 if (!m_service_cntxt->msg->msg_body.curr_slide)
	 {
		return FS_NO_ERROR;
	 }
    /* Add text object with empty content to the slide */
    if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count > 0)
    {
        result = srv_uc_save_buffer_to_file(
                    main->instance,
                    uc_text_path,
                    m_service_cntxt->main->text_buffer,
                    m_service_cntxt->msg->msg_body.curr_slide->txt.char_count);

        if (result == FS_NO_ERROR)
        {
            if (m_service_cntxt->msg->msg_body.curr_slide->txt.object == NULL)
            {
                object = srv_uc_insert_object(main->instance, (S8*) uc_text_path, SRV_UC_OBJECT_TYPE_TEXT);
                srv_uc_insert_object_to_slide(
                    main->instance,
                    object,
                    m_service_cntxt->msg->msg_body.curr_slide,
                    SRV_UC_OBJECT_TYPE_TEXT);
            }
            else
            {
                m_service_cntxt->msg->msg_body.curr_slide->txt.object->size = applib_get_file_size((kal_wchar*) uc_text_path);
            }
            m_service_cntxt->msg->msg_body.curr_slide->txt.object->encoding = MMA_CHARSET_UTF8;   /* because the text's encode already UTF8 when mmi_uc_save_buffer_to_file to file */
        }
        else
        {
            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_HANDLE_TEXT_IN_CURR_SLIDE_RESULT_P1, result);

        }
    }
    /* Delete the text object */
    else if (m_service_cntxt->msg->msg_body.curr_slide->txt.char_count == 0)
    {
        if (m_service_cntxt->msg->msg_body.curr_slide->txt.object)
        {
            if (FS_Delete((U16*) uc_text_path) != FS_NO_ERROR)
            {
                ASSERT(0);
            }
            srv_uc_delete_object_from_list(main->instance, m_service_cntxt->msg->msg_body.curr_slide->txt.object);
            memset(&(m_service_cntxt->msg->msg_body.curr_slide->txt), 0, sizeof(mma_mms_slide_text_object_struct));
        }
    }
    else
    {
        ASSERT(0);
    }
    return result;
}

void vappUcClearMsgBearer(srv_uc_cntxt_reference_struct *m_service_cntxt, VappUcSendInfoStruct *send_info, srv_uc_msg_type_enum msg_type)
{
    if (msg_type == SRV_UC_MSG_TYPE_DEFAULT || msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
    {
        //ReleaseEMSEditBuffer();
    }

    if (msg_type == SRV_UC_MSG_TYPE_DEFAULT || msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
    {
        /* Delete MMS temp msg ID */
        vappUcDeleteMmsReq(m_service_cntxt->send_info->new_msg_id, send_info->new_msg_storage, send_info, NULL);
        m_service_cntxt->send_info->new_msg_id = 0;  /* tricky! */
    }
}

void VappUcAppData::ucClearMsgBearer(srv_uc_msg_type_enum msg_type)
{
    vappUcClearMsgBearer(m_service_cntxt, send_info, msg_type);
}


#ifdef __MMI_MMS_2__
extern "C" void vappUcDeleteMmsRsp(srv_mms_result_enum result, void *rsp_data, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappUcAppData *app = (VappUcAppData*)user_data;
    srv_mms_delete_rsp_struct *msg_rsp = (srv_mms_delete_rsp_struct*) rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(vappUcCheckAppSanity((void *)app) && app->send_info->request_id == UC_DELETE_REQ)
    {
        app->ucActionFsm(SRV_UC_ACTION_DELETE, msg_rsp->result[0]);
    }
    else
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_DEL_MMS_RSP_IGNORE_P1, 0);
    }
    srv_uc_send_um_msg_refresh_ind(
        0,
        SRV_UM_MSG_BOX_DRAFT,
        SRV_UM_MSG_MMS);
    srv_uc_send_um_msg_refresh_ind(
        0,
        SRV_UM_MSG_BOX_UNSENT,
        SRV_UM_MSG_MMS);
}
#endif

void vappUcDeleteMmsReq(U32 msg_id, U8 storage, VappUcSendInfoStruct *send_info, void *user_data)
{
#ifdef __MMI_MMS_2__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_delete_req_struct msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    send_info->request_id = UC_DELETE_REQ;
    memset(&msg_req, 0, sizeof(srv_mms_delete_req_struct));

    srv_mms_bgsr_change_msg_notify(
        msg_id,
        SRV_MMS_BGSR_OP_DELETE,
        (srv_mms_bgsr_msg_box_enum) srv_uc_convert_mma_folder_to_bgsr_folder((S32) mma_get_box (msg_id)),
        NULL,
        storage);
    MMI_ASSERT(msg_id);
    msg_req.msg_id[0] = msg_id;
    msg_req.no_of_msg = 1;
    msg_req.user_data = user_data;
    msg_req.call_back = vappUcDeleteMmsRsp;
    srv_mms_delete(&msg_req);
#endif
    return;
}

void VappUcAppData::ucDeleteMmsReq(U32 msg_id, U8 storage)
{
    vappUcDeleteMmsReq(msg_id, storage, send_info, this);
}

void VappUcAppData::ucDeleteExistedMms(void)
{
    if (m_service_cntxt->main->file_handle > 0)
    {
        FS_Close(m_service_cntxt->main->file_handle);
        m_service_cntxt->main->file_handle = 0;
    }
    ucDeleteMmsReq(m_service_cntxt->send_info->existed_msg_id, send_info->existed_msg_storage);
}

void VappUcAppData::ucEnterMultimediaApp(void)
{
}

void VappUcAppData::vappUcUsbMsModePlugInHdlr(void)
{
    VcuiUcMainCui* app = (VcuiUcMainCui*)this->m_parent;

#ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    if(m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER && 
       send_info->abort != UC_ABORT_BY_END_KEY && 
       (m_service_cntxt->send_info->action == SRV_UC_ACTION_SEND_AND_SAVE ||
        m_service_cntxt->send_info->action == SRV_UC_ACTION_SEND))
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_USB_MS_PLUG_IN_HDLR_FG_SEND_CNCL);
        srv_sms_clear_send_callback(main->send_handle);
        srv_sms_abort_send(main->send_handle);
        resetApp();
    }
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    app->vappUcTerminate();

}
    

void VappUcAppData::vappUcSdPlugInHdlr(void)
{
    /* Code here needed only for MMS storage in memory card */
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_SD_CARD_PLUG_IN_HDLR);
}

void VappUcAppData::vappUcSdPlugOutHdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/  
    VfxBool close_uc = VFX_FALSE;
    VfxBool deinit_preview = VFX_FALSE;
    VfxBool attach_removed = VFX_FALSE;
    VfxBool close_cui = VFX_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_SD_CARD_PLUG_OUT_HDLR);
    /* There is a popup when memory card is removed! */

    
#if defined(__MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__) || defined(__MMI_SMS_TCARD_STORAGE_SUPPORT__)
    vappUcCheckIfNeedCloseUcOnSdPlugOut(&close_uc, &deinit_preview, m_service_cntxt, send_info);

    if (deinit_preview)
    {
        m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
        send_info->abort = UC_ABORT_NONE;
        if (m_service_cntxt->send_info->new_msg_id)
        {
            ucDeleteMmsReq(m_service_cntxt->send_info->new_msg_id, send_info->new_msg_storage);
            m_service_cntxt->send_info->new_msg_id = 0;
        }
    }

    if (close_uc)
    {
        /* Close UC */
		if(is_mma_active == VFX_FALSE)
		{
            VcuiUcMainCui* app = (VcuiUcMainCui *)m_parent;
            app->vappUcTerminate();
		}
		else
		{
			wait_to_close = VFX_TRUE ;
		}
        return;
    }
#endif
    vappUcHandleObjOnSdPlugOut(m_service_cntxt, main, &attach_removed, &close_cui);

    /* info stored in global structure, it's impossbile to from sms to mms or mms to sms  */
    changeMsgTypeIfNeeded();

#ifdef __MMI_MMS_2__
    if (m_service_cntxt->send_info->action == SRV_UC_ACTION_PREVIEW
        && m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
    {
    #ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if(!deinit_preview)
    #endif
        {
            deinit_preview = VFX_TRUE;
	        m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
            if (m_service_cntxt->send_info->new_msg_id)
            {
                ucDeleteMmsReq(m_service_cntxt->send_info->new_msg_id, send_info->new_msg_storage);
                m_service_cntxt->send_info->new_msg_id = 0;
            }
        }
    }
#endif /* __MMI_MMS_2__ */ 

    if(deinit_preview || attach_removed)
    {
        close_cui = VFX_TRUE;
    }
    ucHandleTextInCurrentSlide();
    if (m_service_cntxt->main->mode == SRV_UC_FORWARD_WITHOUT_EDIT_MODE)
    {
        m_service_cntxt->main->mode = SRV_UC_FORWARD_WITH_EDIT_MODE;
    }
    srv_uc_update_msg_size(main->instance);
    switchSlide(m_service_cntxt->msg->msg_body.curr_slide);
    m_signalRefreshPage.postEmit(close_cui, attach_removed);

}

extern "C" void vappUcHandleObjOnSdPlugOut(srv_uc_cntxt_reference_struct *m_service_cntxt, VappUcMainStruct *main, VfxBool *attach_removed, VfxBool *close_cui )
//vappUcHandleObjOnSdPlugOut(VfxBool *attach_removed, VfxBool *close_cui )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mma_mms_slide_struct *slide = NULL;
    mma_mms_object_struct *object = NULL;
    mma_mms_attachment_info_struct *attachment = m_service_cntxt->msg->msg_body.attachment;
    U16 shift_attachment_num = 0;
    U8 cur_slide_num = 0;
    U8 cur_attachment_num = 0;

    *attach_removed = VFX_FALSE;
    *close_cui = VFX_FALSE;
       
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (slide = m_service_cntxt->msg->msg_body.slides; cur_slide_num < m_service_cntxt->msg->msg_body.slide_no; cur_slide_num++)
    {
        ASSERT(slide);
        if (slide->img.object)
        {
            object = slide->img.object;

            if (!(object->is_virtual_file))
            {
                if (FS_GetAttributes(object->file_path_ucs) < 0)
                {
                    if (object->reference_count > 1)
                    {
                        object->reference_count--;
                    }
                    else
                    {
                        srv_uc_delete_object_from_list(main->instance, object);
                    }
                    memset(&slide->img, 0, sizeof(mma_mms_slide_object_struct));
                    *close_cui = VFX_TRUE;
                }
            }
        }

        if (slide->aud.object)
        {
            object = slide->aud.object;

            if (!(object->is_virtual_file))
            {
                if (FS_GetAttributes(object->file_path_ucs) < 0)
                {
                    if (object->reference_count > 1)
                    {
                        object->reference_count--;
                    }
                    else
                    {
                        srv_uc_delete_object_from_list(main->instance, object);
                    }
                    memset(&slide->aud, 0, sizeof(mma_mms_slide_object_struct));
                    *close_cui = VFX_TRUE;
                }
            }
        }

        if (slide->vid.object)
        {
            object = slide->vid.object;

            if (!(object->is_virtual_file))
            {
                if (FS_GetAttributes(object->file_path_ucs) < 0)
                {
                    if (object->reference_count > 1)
                    {
                        object->reference_count--;
                    }
                    else
                    {
                        srv_uc_delete_object_from_list(main->instance, object);
                    }
                    memset(&slide->vid, 0, sizeof(mma_mms_slide_object_struct));
                    *close_cui = VFX_TRUE;
                }
            }
        }

        if (slide->ref_items != NULL)
		{
		    if (slide->ref_items->object)
		    {
			    mma_mms_slide_ref_object_struct *cur_ref = slide->ref_items;
			    mma_mms_slide_ref_object_struct *next_ref = NULL;
			    object = slide->ref_items->object;

				if (!(object->is_virtual_file))
				{
					if (FS_GetAttributes(object->file_path_ucs) < 0)
					{
						if (object->reference_count > 1)
						{
							object->reference_count--;
						}
						else
						{
							srv_uc_delete_object_from_list(main->instance, object);
						}

						if (slide->ref_items == cur_ref)
						{
							slide->ref_items = cur_ref->next;

							if (cur_ref->next)
							{
								cur_ref->next->prev = NULL;
							}
							m_service_cntxt->msg->msg_body.total_attach_no--;
							next_ref = cur_ref->next;
							kal_adm_free(main->mem_pool_id, cur_ref);
						}
						else
						{
							next_ref = cur_ref->next;
							srv_uc_delete_ref_obj_info_from_list(main->instance, cur_ref);
						}
						cur_ref = next_ref;
                        *close_cui = VFX_TRUE;
					}
				}
			}
		}
        slide = slide->next;
    }

    while (attachment != NULL)
    {
        object = attachment->object;

#ifdef __MMI_EMAIL__
		if ( !(object->is_virtual_file) || m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
#else
        if (!(object->is_virtual_file))
#endif
        {
            if (FS_GetAttributes(object->file_path_ucs) < 0)
            {
                mma_mms_attachment_info_struct *att_temp = attachment->next;

                ASSERT(object->reference_count == 1);
				#ifdef __MMI_EMAIL__
					if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
					{
						vapp_uc_media_info mediaInfo;
						memset(&mediaInfo, 0, sizeof(vapp_uc_media_info));
						mediaInfo.file_name = object->file_name_ucs;
						mediaInfo.file_path = object->file_path_ucs;
						VappEmailComp::removeAttch(&mediaInfo, main->callback_para);
					}
				#endif
                srv_uc_delete_object_from_list(main->instance, object);
            #ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
                /* Replace attachment handling */
                if (main->select_media_opt == UC_MEDIA_OPT_REPLACE || 
                main->select_media_opt == UC_MEDIA_OPT_ATTACHMENT_LIST)
                {
                    if (main->object_index == cur_attachment_num)
                    {
                        shift_attachment_num = SRV_UC_INVALID_INDEX;
                    }

                    if (shift_attachment_num != SRV_UC_INVALID_INDEX &&
                        main->object_index > cur_attachment_num)
                    {
                        shift_attachment_num++;
                    }
                }
            #endif /* __MMI_UC_REPLACE_MEDIA_SUPPORT__ */ 

                srv_uc_delete_attachment_from_list(main->instance, attachment);
                attachment = att_temp;
                cur_attachment_num++;
                *attach_removed = VFX_TRUE;
                *close_cui = VFX_TRUE;
                continue;
            }
        }
        cur_attachment_num++;
        attachment = attachment->next;
    }
#ifdef __MMI_UC_REPLACE_MEDIA_SUPPORT__
    /* Replace attachment handling */
    if (shift_attachment_num > 0)
    {
        if (shift_attachment_num == SRV_UC_INVALID_INDEX)
        {
            main->object_index = SRV_UC_INVALID_INDEX;
        }
        else
        {
            ASSERT(main->object_index >= shift_attachment_num);
            main->object_index -= shift_attachment_num;
        }
    }
#endif /* __MMI_UC_REPLACE_MEDIA_SUPPORT__ */ 

}


extern "C" void vappUcCheckIfNeedCloseUcOnSdPlugOut(VfxBool *close_uc, VfxBool *deinit_preview, srv_uc_cntxt_reference_struct *service_cntxt, VappUcSendInfoStruct *send_info)
{
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        if (service_cntxt->send_info->new_msg_id)
        {
            if (send_info->new_msg_storage != MMA_MSG_STORAGE_PHONE)
            {
                *close_uc = VFX_TRUE;
                if(service_cntxt->send_info->action == SRV_UC_ACTION_PREVIEW)
                {
                    *deinit_preview = VFX_TRUE;
                    if((service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
                        service_cntxt->send_info->existed_msg_id && 
                        send_info->existed_msg_storage == MMA_MSG_STORAGE_PHONE) ||
                        (service_cntxt->main->state == SRV_UC_STATE_WRITE_NEW_MSG &&
                        !service_cntxt->send_info->existed_msg_id))
                    {
                        *close_uc = VFX_FALSE;
                    }
                }
            }
            else
            {
                if (service_cntxt->send_info->action == SRV_UC_ACTION_PREVIEW &&
                        service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
                        service_cntxt->send_info->existed_msg_id && 
                        send_info->existed_msg_storage != MMA_MSG_STORAGE_PHONE)
                {
                    *deinit_preview = VFX_TRUE;
                    *close_uc = VFX_TRUE;
                }
            }
        }
        else if (service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
                 service_cntxt->send_info->existed_msg_id)
        {
            if (send_info->existed_msg_storage != MMA_MSG_STORAGE_PHONE)
            {
                *close_uc = VFX_TRUE;
            }
        }
    
#else
    *close_uc = VFX_FALSE;
    *deinit_preview = VFX_FALSE;
#endif

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
    if (service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER &&
        service_cntxt->send_info->existed_msg_id)
    {
        if (send_info->existed_msg_storage == SRV_SMS_STORAGE_TCARD)
        {
            *close_uc = VFX_TRUE;
        }
    }
#endif

}

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
#if 0
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* #if 0 */
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */

void VappUcAppData::ucActionFsm(srv_uc_action_type_enum action, VfxU32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxBool skip_deinit = VFX_FALSE;
    VfxBool close_processing = VFX_FALSE;
//    U16 end_screen_id;  /* uc_src_id_enum */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ACTION_FSM_P4, m_service_cntxt->send_info->action, m_service_cntxt->main->state, action, result);
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ACTION_FSM_MSG_TYPE_P2, m_service_cntxt->msg_type->curr_msg_type, m_service_cntxt->send_info->existed_msg_type);
/*
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    end_screen_id = SCR_ID_UC_PROCESSING;
#else 
    end_screen_id = SCR_ID_UC_SENDING;
#endif 
*/
    switch (m_service_cntxt->send_info->action)
    {
        case SRV_UC_ACTION_SEND:
        {
            switch (m_service_cntxt->main->state)
            {
                case SRV_UC_STATE_WRITE_NEW_MSG:
                case SRV_UC_STATE_FORWARD:
                case SRV_UC_STATE_REPLY:
                case SRV_UC_STATE_REPLY_ALL:
                {
                    switch (action)
                    {
                            /* send , write new */
                        case SRV_UC_ACTION_SEND:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                switch (result)
                                {
                                    case SRV_SMS_CAUSE_NO_ERROR:
                                    {
                                        /* For background send, this case is triggerred when "save" successfully */
                                    #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                                        {
                                         //   mmi_popup_property_struct arg;
	                                    //    mmi_popup_property_init(&arg);
	                                    //    arg.msg_icon = IMG_NEW_SMS_SEND;
	                                        //m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SENT)), MMI_NMGR_BALLOON_TYPE_SUCCESS);                                       
                                        }
                                    #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                      /*  mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_SMS,
                                            result,
                                            end_screen_id);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 

/*
                                        if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_ADD_RECIPIENT, end_screen_id);
                                        }
                                        else
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, end_screen_id);
                                        }
                        
Code to remove the GUI here
*/
                                        vappUcSmsSrvSaveStorageStatusShowPopup();

                                        resetApp();
                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();
*/
                                    }
                                        break;

                                        /* the following cases will not happened in background send, because only save successfully (SRV_SMS_CAUSE_NO_ERROR) or 
                                           fail (MMI_FRM_SMS_ERROR) result will be returned */
                                #ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                                    case SRV_SMS_CAUSE_SEND_ABORT:
                                    {
                                        if (send_info->abort == UC_ABORT_NORMAL)
                                        {

                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_ABORTED_ID)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
/*
                                            if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                            {
                                                U16 next_scrn_id = 0;

                                                next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_OPT_ADD_RECIPIENT, MMI_FRM_NODE_AFTER_FLAG); 
                                                mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                            }
                                            else
                                            {
                                                U16 next_scrn_id = 0;

                                                next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG); 
                                                mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                            }
Code to remove the GUI here
*/
                                            m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
                                            send_info->abort = UC_ABORT_NONE;
/*
                                            mmi_uc_delete_sms_frm_screen();
                                            AlmEnableSPOF();
*/
                                        }
                                        else if (send_info->abort == UC_ABORT_BY_END_KEY)
                                        {
                                            srv_uc_addr_struct *addr = NULL;

                                            addr = srv_uc_get_addr(
                                                    main->instance,
                                                    m_service_cntxt->send_info->curr_send_number);
                                            ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);   /* send-->end key to abort */
/*
                                            AlmEnableSPOF();
*/
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }
                                    }
                                        break;

                                #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                                    case SRV_SMS_CAUSE_NUMBER_INVALID:
                                    case SRV_SMS_CAUSE_SC_EMPTY:
                                   case SRV_SMS_CAUSE_DATA_EXCEED:
                                    case SRV_SMS_CAUSE_TCARD_NOT_AVAILABLE:
                                    {

                                        if (SRV_SMS_CAUSE_NUMBER_INVALID == result)
                                        {
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INVALID_NUMBER)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else if(SRV_SMS_CAUSE_DATA_EXCEED == result)
                                        {
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else if(SRV_SMS_CAUSE_TCARD_NOT_AVAILABLE == result)
                                        {       
                                              m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_INSERT_CARD)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else
                                        {
//                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_SMS_FAILURE_SC_NUM_EMPTY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }

                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                       /* mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_SMS,
                                            result,
                                            end_screen_id);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 

                                        if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                        {
/*
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_ADD_RECIPIENT, end_screen_id);
*/
                                        }
                                        else
                                        {
/*
                                            U16 next_scrn_id = 0;

                                            next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG); 
                                            mmi_uc_delete_between_screens(next_scrn_id, end_screen_id);
*/
                                        }
                                        m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
                                        skip_deinit = VFX_TRUE;
                                        close_processing = VFX_TRUE;
/*
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();
*/
                                    }
                                        break;

                                    case SRV_SMS_CAUSE_NOT_READY:
                                    {

//                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_SMS_MSG_NOT_READY_YET)), MMI_NMGR_BALLOON_TYPE_FAILURE);

                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                       /* mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_SMS,
                                            result,
                                            end_screen_id);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/*
                                        mmi_frm_scrn_close(main->uc_cui_gid, end_screen_id);
*/
                                        m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
/*
                                        AlmEnableSPOF();
*/
                                    }
                                        break;
                                #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__

                                    case SRV_SMS_CAUSE_MEM_FULL:
                                      m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_MEMORY_FULL)), MMI_NMGR_BALLOON_TYPE_FAILURE);

/*                                  case SRV_SMS_CAUSE_MEM_INSUFFICIENT:
                                    case MMI_FRM_SMS_DATAEMPTY: 
                                    case SRV_SMS_CAUSE_DATA_EXCEED:
                                    case SRV_SMS_CAUSE_DATA_INVALID:
                                    case MMI_FRM_SMS_ERROR: 
*/
                                    default:
                                    {
                            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/* under construction !*/
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
                                        resetApp();
                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();
*/
                                    }
                                        break;
/*
                                    default:
                                        ASSERT(0);
                                        break;
*/
                                #else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 

                                    default:
                                    {
                                        srv_uc_addr_struct *addr = NULL;

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);
                                            mmi_uc_entry_processing_after_send();
                                        }
*/
                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
/*
                                        mmi_frm_scrn_close(main->uc_cui_gid, end_screen_id);
*/
                                        addr = srv_uc_get_addr(
                                                main->instance,
                                                m_service_cntxt->send_info->curr_send_number);
                                        ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);
                                    }
                                        break;
                                #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 

                                }
                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                ASSERT(0);
                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                            }
                            /* send , write new mms */
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMA_RESULT_OK:
                                    {
                                        /* Avoid user to send abort after sending rsp is received. */
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_SENDING)
                                        {
                                            ClearInputEventHandler(MMI_DEVICE_ALL);
                                            ClearKeyHandler(KEY_END, KEY_EVENT_UP);
                                            ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
                                            ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
                                            ClearKeyHandler(KEY_END, KEY_REPEAT);
                                        }
                                        else if (send_info->abort != UC_ABORT_NONE)
                                        {

                                            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ACTION_FSM_CANCEL);

                                            send_info->send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            ucActionFsm(SRV_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }
*/
                                        /* no matter send ok or fail, should notify anyway. */
                                        /* foreground send. should not be postcard cases. because postcard will be dependent with bgsr */
                                        /* won't notify if user select cancel send */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                    /*    mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_NORMAL_MMS,
                                            result,
                                            SCR_ID_UC_SENDING);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 

                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
                                    }
                                        break;

                                    case MMA_RESULT_FAIL_USER_CANCEL:
                                    {
                                        if (send_info->abort == UC_ABORT_NORMAL)
                                        {
                                            ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
                                        }
                                        else if (send_info->abort == UC_ABORT_BY_END_KEY)
                                        {
                                            //mmi_uc_save_mms_req(m_service_cntxt->send_info->new_msg_id, MMA_FOLDER_OUTBOX); No need
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }

                                    }
                                        break;

                                    default:
                                    {
                                        if (send_info->abort != UC_ABORT_NONE)
                                        {

                                            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ACTION_FSM_CANCEL);
                                            send_info->send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            ucActionFsm(SRV_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }
                                        /* no matter send ok or fail, should notify anyway. */
                                        /* foreground send. should not be postcard cases. because postcard will be dependent with bgsr */
                                        /* won't notify if user select cancel send */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                      /*  mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_NORMAL_MMS,
                                            result,
                                            SCR_ID_UC_SENDING);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
*/
                                        //mmi_uc_save_mms_req(m_service_cntxt->send_info->new_msg_id, MMA_FOLDER_OUTBOX); NO NEED
                                    }
                                        break;

                                }

                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                            /* send , write new */
                        case SRV_UC_ACTION_SAVE:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                /* For background send, the following case will not happen, L4/mmsgrsr will take care */
                            #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                                ASSERT(0);
                            #else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                                if (send_info->send_result == SRV_SMS_CAUSE_SEND_ABORT)
                                {
                                    if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
/*
                                        AlmEnableSPOF();
*/
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (result == SRV_SMS_CAUSE_NO_ERROR)
                                    {
                                        /* send > save and use the same tone for all send fail reasons */

                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_SUCCESS)), MMI_NMGR_BALLOON_TYPE_FAILURE);

                                    }
                                    else
                                    {
                                        /* send > save and use the same tone for all send fail reasons */

                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_FAIL)), MMI_NMGR_BALLOON_TYPE_FAILURE);

                                    }
                                /*no matter send(1st save for sms-bg) ok or fail, should notify anyway*/
            					#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
            					//	mmi_uc_phb_save_contact_notify_check(SRV_UC_PHB_LIST_TYPE_SMS, result, SCR_ID_UC_PROCESSING);
            					#endif /*__MMI_PHB_SAVE_CONTACT_NOTIFY__*/ 
/*
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }

                                    mmi_uc_delete_sms_frm_screen();
*/
                                    resetApp();
                                    ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                    AlmEnableSPOF();
*/
                                }
                            #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                ASSERT(0);
                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                            }
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                if (send_info->send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
/*
                                        AlmEnableSPOF();
*/
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {

                                    /* Should handle save result */
/*
                                    if (result != MMA_RESULT_OK)
                                    {
                                        mmi_uc_display_mma_send_result_popup(send_info->send_result, MMI_FALSE);
                                    }
                                    else
                                    {
                                        mmi_uc_display_mma_send_result_popup(send_info->send_result, MMI_TRUE);
                                    }
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
*/
                                    resetApp();
/*
                                    AlmEnableSPOF();
*/
                                }
                            }
                            else
                            {
                                ASSERT(0);
                            }

                        }
                            break;

                            /* send , write new */
                        case SRV_UC_ACTION_DELETE:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                                ASSERT(0);
                            }
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                /* Deletion may fail in USB normal mode. */

                                if (send_info->send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {

                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_ABORTED_ID)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
/*
                                    mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_UC_ABORTED_ID)), MMI_EVENT_SUCCESS, NULL);
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD ||
                                        m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        U16 next_scrn_id = 0;

                                        next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_OPT_ADD_RECIPIENT, MMI_FRM_NODE_AFTER_FLAG); 
                                        mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        U16 next_scrn_id = 0;

                                        next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG); 
                                        mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                    }
                                    AlmEnableSPOF();
*/
                                }
                                else
                                {
/*
                                    mmi_uc_display_mma_send_result_popup(send_info->send_result, MMI_TRUE);

                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_OPT_ADD_RECIPIENT, SCR_ID_UC_SENDING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_SENDING);
                                    }
*/
                                    resetApp();
/*
                                    AlmEnableSPOF();
*/
                                }

                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                            /* send , write new */
                        default:
                        {
                            ASSERT(0);
                        }
                            break;
                    }
                }
                    break;  /* send , write new  */

                    /* send , edit */
                case SRV_UC_STATE_EDIT_EXISTED_MSG:
                case SRV_UC_STATE_SEND:
                {
                    srv_um_msg_box_enum msg_box = (srv_um_msg_box_enum) send_info->curr_folder;

                    ASSERT(msg_box);

                    switch (action)
                    {
                            /* send , edit */
                            /* if background sending is enabled, the "SEND" here only mean "SAVE successfully */
                        case SRV_UC_ACTION_SEND:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                switch (result)
                                {
                                    case SRV_SMS_CAUSE_NO_ERROR:
                                    {
                                        //m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SENT)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                        if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            /* For background send, this case is triggerred when "save" successfully */
                                        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                                            {
/*
                                                mmi_popup_property_struct arg;
	                                            mmi_popup_property_init(&arg);
	                                            arg.msg_icon = IMG_NEW_SMS_SEND;
                                                arg.duration = MMI_UC_POPUP_TIME_OUT;
                                                arg.tone_id = (U8) SUCCESS_TONE;
*/	                                                                                   

                                            }
                                        #else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 

                                            //m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SENT)), MMI_NMGR_BALLOON_TYPE_SUCCESS);

                                        #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                                            /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                        #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                        /*    mmi_uc_phb_save_contact_notify_check(
                                                SRV_UC_PHB_LIST_TYPE_SMS,
                                                result,
                                                end_screen_id);*/
                                        #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/*
                                            if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                            {
                                                mmi_uc_delete_between_screens(
                                                    SCR_ID_UC_OPT_ADD_RECIPIENT,
                                                    end_screen_id);
                                            }
                                            else
                                            {
                                                mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, end_screen_id);
                                            }
*/
                                            vappUcSmsSrvSaveStorageStatusShowPopup();
                                            resetApp();
                                            ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                            mmi_uc_delete_sms_frm_screen();
                                            AlmEnableSPOF();
*/
                                        }
                                        else    /* sent ok, then delete msg from draft */
                                        {
                                            /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                        #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                            /* because phb notify will be triggered in ucDeleteSmsCallback */
                                            if (msg_box != SRV_UM_MSG_BOX_DRAFT && msg_box != SRV_UM_MSG_BOX_UNSENT)
                                            {
                                              /*  mmi_uc_phb_save_contact_notify_check(
                                                    SRV_UC_PHB_LIST_TYPE_SMS,
                                                    result,
                                                    end_screen_id);*/
                                            }
                                        #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
                                            /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                            /* Do not display processing screen in such cases. */
/*
                                            if (mmi_uc_is_uc_screen_in_history())
                                            {
                                                mmi_uc_set_processing_screen(
                                                    0,
                                                    STR_GLOBAL_SENDING,
                                                    IMG_NEW_SMS_SEND,
                                                    0);
                                                mmi_uc_entry_processing_after_send();
                                            }
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
*/
                                            /* Delete the orignal message in draft/unsent */
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                if (msg_box == SRV_UM_MSG_BOX_DRAFT ||
                                                    msg_box == SRV_UM_MSG_BOX_UNSENT)
                                                {
                                                    srv_sms_delete_msg(
                                                        (U16) m_service_cntxt->send_info->existed_msg_id,
                                                        ucDeleteSmsCallback, 
                                                        this);
                                                }
                                            }
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                ucDeleteExistedMms();
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                    }
                                        break;

                                        /* if BGS is enabled, the following case will be handled by L4 */
                                #ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                                    case SRV_SMS_CAUSE_SEND_ABORT:
                                    {
                                        if (send_info->abort == UC_ABORT_NORMAL)
                                        {

                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_ABORTED_ID)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
/*
                                            mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_UC_ABORTED_ID)), MMI_EVENT_SUCCESS, NULL);

                                            if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD ||
                                                m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                            {
                                                U16 next_scrn_id = 0;

                                                next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_OPT_ADD_RECIPIENT, MMI_FRM_NODE_AFTER_FLAG); 
                                                mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                            }
                                            else
                                            {
                                                U16 next_scrn_id = 0;

                                                next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG); 
                                                mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                            }
*/
                                            m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
/*
                                            mmi_uc_delete_sms_frm_screen();
                                            AlmEnableSPOF();
*/
                                        }
                                        else if (send_info->abort == UC_ABORT_BY_END_KEY)
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                            {
                                                srv_uc_addr_struct *addr = NULL;

                                                addr = srv_uc_get_addr(
                                                        main->instance,
                                                        m_service_cntxt->send_info->curr_send_number);
                                                ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);       /* send-->end ket to abort-->not sent--outbox */
/*
                                                AlmEnableSPOF();
*/
                                            }
                                            else
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    if (msg_box == SRV_UM_MSG_BOX_DRAFT ||
                                                        msg_box == SRV_UM_MSG_BOX_UNSENT)
                                                    {
                                                        srv_sms_delete_msg(
                                                            (U16) m_service_cntxt->send_info->existed_msg_id,
                                                            ucDeleteSmsCallback, 
                                                            this);
                                                    }

                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    srv_uc_addr_struct *addr = NULL;

                                                    addr = srv_uc_get_addr(
                                                            main->instance,
                                                            m_service_cntxt->send_info->curr_send_number);
                                                    ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);   /* send-->end ket to abort-->not sent--outbox */
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }
                                    }
                                        break;

                                #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/* under construction !*/
/* under construction !*/
                                #endif

                                    case SRV_SMS_CAUSE_NOT_READY:
                                    {
//                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_SMS_MSG_NOT_READY_YET)), MMI_NMGR_BALLOON_TYPE_FAILURE);

                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                      /*  mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_SMS,
                                            result,
                                            end_screen_id);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/*
                                        mmi_frm_scrn_close(main->uc_cui_gid, end_screen_id);
                                        AlmEnableSPOF();
*/
                                    }
                                        break;

                                    case SRV_SMS_CAUSE_NUMBER_INVALID:
                                    case SRV_SMS_CAUSE_SC_EMPTY:
                                   case SRV_SMS_CAUSE_DATA_EXCEED:
                                    case SRV_SMS_CAUSE_TCARD_NOT_AVAILABLE:
                                    {

                                        if (SRV_SMS_CAUSE_NUMBER_INVALID == result)
                                        {
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INVALID_NUMBER)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else if(SRV_SMS_CAUSE_DATA_EXCEED == result)
                                        {
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else if(SRV_SMS_CAUSE_TCARD_NOT_AVAILABLE == result)
                                        {       
                                              m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_INSERT_CARD)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else
                                        {
//                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_SMS_FAILURE_SC_NUM_EMPTY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }

                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                       /* mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_SMS,
                                            result,
                                            end_screen_id);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/*
                                        if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_OPT_ADD_RECIPIENT, end_screen_id);
                                        }
                                        else
                                        {
                                            U16 next_scrn_id = 0;

                                            next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG); 
                                            mmi_uc_delete_between_screens(next_scrn_id, end_screen_id);
                                        }
*/
                                        m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
/*
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();
*/
                                    }
                                        break;

                                #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__

                                    case SRV_SMS_CAUSE_MEM_FULL:
                                      m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_MEMORY_FULL)), MMI_NMGR_BALLOON_TYPE_FAILURE);

/*                                  case SRV_SMS_CAUSE_MEM_INSUFFICIENT:
                                    case MMI_FRM_SMS_DATAEMPTY: 
                                    case SRV_SMS_CAUSE_DATA_EXCEED:
                                    case SRV_SMS_CAUSE_DATA_INVALID:
                                    case MMI_FRM_SMS_ERROR: 
*/
                                    default:
                                    {
                            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/* under construction !*/
/* under construction !*/
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
                                        resetApp();
                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();
*/

                                    }
                                        break;
/*
                                    default:
                                    {
                                        ASSERT(0);
                                    }
                                        break;
*/
                                #else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 

                                    default:
                                    {
                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                          mmi_frm_scrn_close(main->uc_cui_gid, end_screen_id);
*/
                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                    /*    mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_SMS,
                                            result,
                                            end_screen_id);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
                                        if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            srv_uc_addr_struct *addr = NULL;

                                            addr = srv_uc_get_addr(
                                                    main->instance,
                                                    m_service_cntxt->send_info->curr_send_number);
                                            ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);   /* send-->error-->not sent ok--outbox */
                                        }
                                        else
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT)
                                            {
                                                /* highlighter need to set by UC */
                                                send_info->need_highlight_ind_to_um = TRUE;
                                            }

                                            /* save msg from SMS to SMS. Delete original one and then save new one. */
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {

                                                if (msg_box == SRV_UM_MSG_BOX_DRAFT ||
                                                    msg_box == SRV_UM_MSG_BOX_UNSENT)
                                                {
                                                    srv_sms_delete_msg(
                                                        (U16) m_service_cntxt->send_info->existed_msg_id,
                                                        ucDeleteSmsCallback, 
                                                        this);
                                                }
                                            }
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                srv_uc_addr_struct *addr = NULL;

                                                addr = srv_uc_get_addr(
                                                        main->instance,
                                                        m_service_cntxt->send_info->curr_send_number);
                                                ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);       /* send-->error-->not sent ok--outbox */
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                    }
                                        break;
                                #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                                }
                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                ASSERT(0);
                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                            }
                            /* send , edit */
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMA_RESULT_OK:
                                    {
                                        if (send_info->abort != UC_ABORT_NONE)
                                        {

                                            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ACTION_FSM_CANCEL);
                                            send_info->send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            ucActionFsm(SRV_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }

                                        /* no matter send ok or fail, should notify anyway. */
                                        /* foreground send. should not be postcard cases. because postcard will be dependent with bgsr */
                                        /* won't notify if user select cancel send */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                      /*  mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_NORMAL_MMS,
                                            result,
                                            SCR_ID_UC_SENDING);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 

                                        if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            /* Avoid user to send abort after sending rsp is received. */
/*
                                            if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_SENDING)
                                            {
                                                ClearInputEventHandler(MMI_DEVICE_ALL);
                                                ClearKeyHandler(KEY_END, KEY_EVENT_UP);
                                                ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
                                                ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
                                                ClearKeyHandler(KEY_END, KEY_REPEAT);
                                            }
                                            ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
*/
                                        }
                                        else
                                        {
                                            /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                            /* Do not display processing screen in such cases. */
/*
                                            if (mmi_uc_is_uc_screen_in_history())
                                            {
                                                mmi_uc_set_processing_screen(
                                                    0,
                                                    STR_GLOBAL_SENDING,
                                                    IMG_NEW_SMS_SEND,
                                                    0);
                                                mmi_uc_entry_processing_after_send();
                                            }
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
*/
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {

                                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                                if (msg_box == SRV_UM_MSG_BOX_DRAFT ||
                                                    msg_box == SRV_UM_MSG_BOX_UNSENT)
                                                {
                                                    srv_sms_delete_msg(
                                                        (U16) m_service_cntxt->send_info->existed_msg_id,
                                                        ucDeleteSmsCallback, 
                                                        this);
                                                }
                                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                ASSERT(0);
                                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                            }
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                ucDeleteExistedMms();
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                    }
                                        break;

                                    case MMA_RESULT_FAIL_USER_CANCEL:
                                    {
                                        if (send_info->abort == UC_ABORT_NORMAL)
                                        {
                                            ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
                                        }
                                        else if (send_info->abort == UC_ABORT_BY_END_KEY)
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                            {
                                                /*mmi_uc_save_mms_req(
                                                    m_service_cntxt->send_info->new_msg_id,
                                                    MMA_FOLDER_OUTBOX); NO NEED */
                                            }
                                            else
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    /* mmi_uc_save_mms_req(
                                                        m_service_cntxt->send_info->new_msg_id,
                                                        MMA_FOLDER_OUTBOX);  NO NEED */
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    ucDeleteExistedMms();
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }
                                    }
                                        break;

                                    default:
                                    {
                                        if (send_info->abort != UC_ABORT_NONE)
                                        {

                                            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ACTION_FSM_CANCEL);
                                            send_info->send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            ucActionFsm(SRV_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
*/
                                        if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            //mmi_uc_save_mms_req(m_service_cntxt->send_info->new_msg_id, MMA_FOLDER_OUTBOX); NO NEED
                                        }
                                        else
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT)
                                            {
                                                /* highlighter need to set by UC */
                                                send_info->need_highlight_ind_to_um = TRUE;
                                            }

                                            /* save msg from SMS to MMS. Save new one and then delete original one */
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                /* mmi_uc_save_mms_req(
                                                    m_service_cntxt->send_info->new_msg_id,
                                                    MMA_FOLDER_OUTBOX); NO NEED */
                                            }
                                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                ucDeleteExistedMms();
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                    }
                                        break;

                                }

                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                            /* send , edit */
                        case SRV_UC_ACTION_SAVE:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                /* For background send, the following case will not happen, L4 will take care */
                            #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                                ASSERT(0);
                            #else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                                if (send_info->send_result == SRV_SMS_CAUSE_SEND_ABORT)
                                {
                                    if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
                                        if (result == SRV_SMS_CAUSE_NO_ERROR)
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    ucDeleteExistedMms();
                                                    return;
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                        }

                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
//                                        AlmEnableSPOF();

                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (result == SRV_SMS_CAUSE_NO_ERROR)
                                    {
                                        if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                        {
                                            /* save msg from SMS to SMS. Delete original one and then save new one. */
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                /* Do nothing. */
                                            }
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                ucDeleteExistedMms();
                                                return;
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }

                                        /* send > save, use same tone for all send fail reasons */
                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_SUCCESS)), MMI_NMGR_BALLOON_TYPE_FAILURE);

                                    }
                                    else
                                    {
                                        /* send > save, use same tone for all send fail reasons */
                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_FAIL)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                    }
/*
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
                                    mmi_uc_delete_sms_frm_screen();
*/
                                    resetApp();
/*
                                    ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
                                    AlmEnableSPOF();
*/
                                }
                            #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                ASSERT(0);
                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                            }
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                if (send_info->send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
                                        if (result == MMA_RESULT_OK)
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                                    srv_sms_delete_msg(
                                                        (U16) m_service_cntxt->send_info->existed_msg_id,
                                                        ucDeleteSmsCallback, 
                                                        this);
                                                    return;
                                                #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                    ASSERT(0);
                                                #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                        }
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
//                                        AlmEnableSPOF();
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (result == MMA_RESULT_OK)
                                    {
                                        if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                        {
                                            /* save msg from SMS to MMS. Save new one and then delete original one. */
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                                srv_sms_delete_msg(
                                                    (U16) m_service_cntxt->send_info->existed_msg_id,
                                                    ucDeleteSmsCallback, 
                                                    this);
                                                return;
                                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                ASSERT(0);
                                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                            }
                                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                /* Do nothing. */
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                    }
/*
                                    mmi_uc_display_mma_send_result_popup(send_info->send_result, MMI_TRUE);
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 

                                    if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
*/
                                    resetApp();
//                                    AlmEnableSPOF();
                                }
                            }
                            else
                            {
                                ASSERT(0);
                            }

                        }
                            break;

                            /* send , edit */
                        case SRV_UC_ACTION_DELETE:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                if (send_info->send_result == SRV_SMS_CAUSE_NO_ERROR)
                                {

                                    /* For background send, this case is triggerred when "save" successfully, mean send from draft, send req already process 1st save ok, here, delete this sms from draft ok */

                                #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
/*
                                    {
                                            mmi_popup_property_struct arg;
	                                        mmi_popup_property_init(&arg);
	                                        arg.msg_icon = IMG_NEW_SMS_SEND;
                                            arg.duration = MMI_UC_POPUP_TIME_OUT;
                                            arg.tone_id = (U8) SUCCESS_TONE;
	                                    */
                                    //m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SENT)), MMI_NMGR_BALLOON_TYPE_SUCCESS);                                       
                                /*
                                    }
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
*/
                                #else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
//                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SENT)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                  /*  mmi_uc_phb_save_contact_notify_check(
                                        SRV_UC_PHB_LIST_TYPE_SMS,
                                        result,
                                        SCR_ID_UC_PROCESSING);*/
                                #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/*
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
*/
                                #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                                    resetApp();
                                    ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                    mmi_uc_delete_sms_frm_screen();
                                    AlmEnableSPOF();
*/
                                }
                            #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                                else
                                {
                                    ASSERT(0);  /* if 1st save fail, not delete msg from draft, so here this case will not happened */
                                }
                            #else /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                                else if (send_info->send_result == SRV_SMS_CAUSE_SEND_ABORT)
                                {
                                    if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
                                        if ((m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER &&
                                             result == SRV_SMS_CAUSE_NO_ERROR) ||
                                            (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
                                             result == MMA_RESULT_OK))
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    srv_uc_addr_struct *addr = NULL;

                                                    addr = srv_uc_get_addr(
                                                            main->instance,
                                                            m_service_cntxt->send_info->curr_send_number);
                                                    ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);   /* abort */
                                                    return;
                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
//                                        AlmEnableSPOF();
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if ((m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER &&
                                         result == SRV_SMS_CAUSE_NO_ERROR) ||
                                        (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
                                         result == MMA_RESULT_OK))
                                    {
                                        if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                        {
                                            /* save msg from SMS to SMS. Delete original one and then save new one. */
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                srv_uc_addr_struct *addr = NULL;

                                                addr = srv_uc_get_addr(
                                                        main->instance,
                                                        m_service_cntxt->send_info->curr_send_number);
                                                ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);       /* sent, del not ok */
                                                return;
                                            }
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                /* Do nothing. */
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }

                                        /* send > save, use same tone for all send fail reasons */
                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_SUCCESS)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                    }
                                    else
                                    {
                                        /* send > save, use same tone for all send fail reasons */
                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_FAIL)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                    }
/*
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
                                    mmi_uc_delete_sms_frm_screen();
*/
                                    resetApp();
/*
                                    ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
                                    AlmEnableSPOF();
*/

                                }
                            #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */ 
                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                ASSERT(0);
                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                            }
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                if (send_info->send_result == MMA_RESULT_OK)
                                {
                                    /* Original msg is deleted first in unsent and draft box cases */
                                    if (m_service_cntxt->send_info->new_msg_id)
                                    {
                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
                                        return;
                                    }
/*
                                    mmi_uc_display_mma_send_result_popup(send_info->send_result, MMI_TRUE);

                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        if (mmi_frm_scrn_is_present(main->uc_cui_gid, SCR_ID_UC_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                                        {
                                            mmi_uc_delete_between_screens(
                                                SCR_ID_UC_OPT_ADD_RECIPIENT,
                                                SCR_ID_UC_PROCESSING);
                                        }
                                        else if (mmi_frm_scrn_is_present(main->uc_cui_gid, SCR_ID_UC_SENDING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                                        {
                                            mmi_uc_delete_between_screens(
                                                SCR_ID_UC_OPT_ADD_RECIPIENT,
                                                SCR_ID_UC_SENDING);
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }
                                    }
                                    else
                                    {
                                        if (mmi_frm_scrn_is_present(main->uc_cui_gid, SCR_ID_UC_PROCESSING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                        }
                                        else if (mmi_frm_scrn_is_present(main->uc_cui_gid, SCR_ID_UC_SENDING, MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                                        {
                                            mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_SENDING);
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }
                                    }
*/
                                    resetApp();
//                                    AlmEnableSPOF();
                                }
                                else if (send_info->send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    if (send_info->abort == UC_ABORT_NORMAL)
                                    {
                                        /* Deletion may fail in USB normal mode. */

                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_ABORTED_ID)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
/*
                                        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_UC_ABORTED_ID)), MMI_EVENT_SUCCESS, NULL);

                                    #ifdef __MMI_MMS_POSTCARD__
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                    #endif 
                                        if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD ||
                                            m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                        {
                                            U16 next_scrn_id = 0;

                                            next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_OPT_ADD_RECIPIENT, MMI_FRM_NODE_AFTER_FLAG); 
                                            mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                        }
                                        else
                                        {
                                            U16 next_scrn_id = 0;

                                            next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG); 
                                            mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                        }
                                        AlmEnableSPOF();
*/
                                    }
                                    else if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
                                        if ((m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER &&
                                             result == SRV_SMS_CAUSE_NO_ERROR) ||
                                            (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
                                             result == MMA_RESULT_OK))
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* mmi_uc_save_mms_req(
                                                        m_service_cntxt->send_info->new_msg_id,
                                                        MMA_FOLDER_OUTBOX); */
                                                    return;
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
//                                        AlmEnableSPOF();
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if ((m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER &&
                                         result == SRV_SMS_CAUSE_NO_ERROR) ||
                                        (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
                                         result == MMA_RESULT_OK))
                                    {
                                        if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                        {
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                /* Do nothing. */
                                            }
                                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                /* mmi_uc_save_mms_req(
                                                    m_service_cntxt->send_info->new_msg_id,
                                                    MMA_FOLDER_OUTBOX);  NO NEED */
                                                return;
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }

                                    }
/*
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    mmi_uc_display_mma_send_result_popup(send_info->send_result, MMI_TRUE);

                                    if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
*/
                                    resetApp();
//                                    AlmEnableSPOF();
                                }

                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                            /* send , write new */
                        default:
                        {
                            ASSERT(0);
                        }
                            break;
                    }
                }
                    break;  /* send , edit existed  */

                default:
                {
                    ASSERT(0);
                }
                    break;

            }

        }
            break;

        case SRV_UC_ACTION_SEND_AND_SAVE:
        {
            
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__    
            ASSERT(0);
#else
            srv_um_msg_box_enum msg_box = (srv_um_msg_box_enum) send_info->curr_folder;

        #ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
            ASSERT(m_service_cntxt->msg_type->curr_msg_type != SRV_UC_MSG_TYPE_SMS_PREFER);
        #endif 
        #ifdef __MMI_MMS_BGSR_SUPPORT__
            ASSERT(m_service_cntxt->msg_type->curr_msg_type != SRV_UC_MSG_TYPE_MMS_PREFER);
        #endif 

            switch (m_service_cntxt->main->state)
            {
                    /* send and save, write new */
                case SRV_UC_STATE_WRITE_NEW_MSG:
                case SRV_UC_STATE_FORWARD:
                case SRV_UC_STATE_REPLY:
                case SRV_UC_STATE_REPLY_ALL:
                {
                    switch (action)
                    {
                            /* send and save, write new */
                        case SRV_UC_ACTION_SEND:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                switch (result)
                                {
                                    case SRV_SMS_CAUSE_NO_ERROR:
                                    {
                                        srv_uc_addr_struct *addr = NULL;

                                        if (msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            /* highlighter need to set by UC */
                                            send_info->need_highlight_ind_to_um = TRUE;
                                        }

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
*/

                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                      /*  mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_SMS,
                                            result,
                                            SCR_ID_UC_SENDING);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
                                        addr = srv_uc_get_addr(main->instance, 0);
                                        ucSaveSmsAfterSend(SRV_SMS_STATUS_SENT, addr->addr);
                                    }
                                        break;

                                    case SRV_SMS_CAUSE_SEND_ABORT:
                                    {
                                        if (send_info->abort == UC_ABORT_NORMAL)
                                        {

                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_ABORTED_ID)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
/*
                                            if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                            {
                                                U16 next_scrn_id = 0;

                                                next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_OPT_ADD_RECIPIENT, MMI_FRM_NODE_AFTER_FLAG); 
                                                mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                            }
                                            else
                                            {
                                                U16 next_scrn_id = 0;

                                                next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG); 
                                                mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                            }
*/
                                            m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
                                            send_info->abort = UC_ABORT_NONE;
/*
                                            mmi_uc_delete_sms_frm_screen();
                                            AlmEnableSPOF();
*/
                                        }
                                        else if (send_info->abort == UC_ABORT_BY_END_KEY)
                                        {
                                            srv_uc_addr_struct *addr = NULL;

                                            addr = srv_uc_get_addr(
                                                    main->instance,
                                                    m_service_cntxt->send_info->curr_send_number);
                                            ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);
//                                           AlmEnableSPOF();
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }
                                    }
                                        break;

                                    case SRV_SMS_CAUSE_NOT_READY:
                                    {
//                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_SMS_MSG_NOT_READY_YET)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                     /*   mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_SMS,
                                            result,
                                            SCR_ID_UC_SENDING);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
//                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
                                        m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
//                                        AlmEnableSPOF();
                                    }
                                        break;

                                    case SRV_SMS_CAUSE_NUMBER_INVALID:
                                    case SRV_SMS_CAUSE_SC_EMPTY:
                                   case SRV_SMS_CAUSE_DATA_EXCEED:
                                    {

                                        if (SRV_SMS_CAUSE_NUMBER_INVALID == result)
                                        {
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INVALID_NUMBER)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else if(SRV_SMS_CAUSE_DATA_EXCEED == result)
                                        {
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else
                                        {
//                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_SMS_FAILURE_SC_NUM_EMPTY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }

                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                       /* mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_SMS,
                                            result,
                                            SCR_ID_UC_SENDING);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/*
                                        if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                        {
                                            U16 next_scrn_id = 0;

                                            next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_OPT_ADD_RECIPIENT, MMI_FRM_NODE_AFTER_FLAG); 
                                            mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_SENDING);
                                        }
                                        else
                                        {
                                            U16 next_scrn_id = 0;

                                            next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG); 
                                            mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_SENDING);
                                        }
*/
                                        m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
/*
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();
*/
                                    }
                                        break;
                                #if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/* under construction !*/
/* under construction !*/
                            #endif 
                                    default:
                                    {
                                        srv_uc_addr_struct *addr = NULL;

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);
                                            mmi_uc_entry_processing_after_send();
                                        }
*/
                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
//                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
                                        addr = srv_uc_get_addr(
                                                main->instance,
                                                m_service_cntxt->send_info->curr_send_number);
                                        ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);
                                    }
                                        break;
                                }
                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                ASSERT(0);
                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                            }
                            /* send and save, write new */
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMA_RESULT_OK:
                                    {
                                        if (send_info->abort != UC_ABORT_NONE)
                                        {
                                            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ACTION_FSM_CANCEL);
                                            send_info->send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            ucActionFsm(SRV_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }

                                        /* no matter send ok or fail, should notify anyway. */
                                        /* foreground send. should not be postcard cases. because postcard will be dependent with bgsr */
                                        /* won't notify if user select cancel send */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                    /*    mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_NORMAL_MMS,
                                            result,
                                            SCR_ID_UC_SENDING);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 

                                        if (msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            /* highlighter need to set by UC */
                                            send_info->need_highlight_ind_to_um = TRUE;
                                        }

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);

                                            mmi_uc_entry_processing_after_send();
                                        }
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
*/
                                        // mmi_uc_save_mms_req(m_service_cntxt->send_info->new_msg_id, MMA_FOLDER_SENT); NO NEED
                                    }
                                        break;

                                    case MMA_RESULT_FAIL_USER_CANCEL:
                                    {
                                        if (send_info->abort == UC_ABORT_NORMAL)
                                        {
                                            ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
                                        }
                                        else if (send_info->abort == UC_ABORT_BY_END_KEY)
                                        {
                                            // mmi_uc_save_mms_req(m_service_cntxt->send_info->new_msg_id, MMA_FOLDER_OUTBOX); NO NEED
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }

                                    }
                                        break;

                                    default:
                                    {
                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
*/
                                        // mmi_uc_save_mms_req(m_service_cntxt->send_info->new_msg_id, MMA_FOLDER_OUTBOX); NO NEED
                                    }
                                        break;

                                }
                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                            /* send and save, write new */
                        case SRV_UC_ACTION_SAVE:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                if (send_info->send_result == SRV_SMS_CAUSE_SEND_ABORT)
                                {
                                    if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
//                                        AlmEnableSPOF();
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (send_info->send_result == SRV_SMS_CAUSE_NO_ERROR)
                                    {
                                        if (result == SRV_SMS_CAUSE_NO_ERROR)
                                        {
                                            /* send > save */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_SUCCESS_SAVE_SUCCESS)), MMI_NMGR_BALLOON_TYPE_SUCCESS);

                                        }
                                        else
                                        {
                                            /* send > save */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_SUCCESS_SAVE_FAIL)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                        }

                                    }
                                    else
                                    {
                                        if (result == SRV_SMS_CAUSE_NO_ERROR)
                                        {
                                            /* send > save and play same tone for all send fail reasons */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_SUCCESS)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else
                                        {
                                            /* send > save and play same tone for all send fail reasons */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_FAIL)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                    }
                                    /*temp */
                                /*no matter send(1st save for sms-bg) ok or fail, should notify anyway*/
            						#ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
            						//	mmi_uc_phb_save_contact_notify_check(SRV_UC_PHB_LIST_TYPE_SMS, result, SCR_ID_UC_PROCESSING);
            						#endif /*__MMI_PHB_SAVE_CONTACT_NOTIFY__*/ 
/*
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
                                    mmi_uc_delete_sms_frm_screen();
*/
                                }
                                resetApp();
                                ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
//                                AlmEnableSPOF();
                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                ASSERT(0);
                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                            }
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                if (send_info->send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
//                                        AlmEnableSPOF();
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (send_info->send_result == MMA_RESULT_OK)
                                    {
                                        if (result == MMA_RESULT_OK)
                                        {
                                            /* send > save, use same tone for all send fail reasons */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_SUCCESS_SAVE_SUCCESS)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                        }
                                        else
                                        {
                                            /* send > save, use same tone for all send fail reasons */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_SUCCESS_SAVE_FAIL)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                        }

                                    }
/*
                                    else if (result != MMA_RESULT_OK)
                                    {
                                        mmi_uc_display_mma_send_result_popup(send_info->send_result, MMI_FALSE);
                                    }
                                    else
                                    {
                                        mmi_uc_display_mma_send_result_popup(send_info->send_result, MMI_TRUE);
                                    }                                   
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
*/
                                }
                                resetApp();
//                                AlmEnableSPOF();
                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                        case SRV_UC_ACTION_DELETE:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                                ASSERT(0);
                            }
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                /* Deletion may fail in USB normal mode. */

                                if (send_info->send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {

                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_ABORTED_ID)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
/*
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD ||
                                        m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        U16 next_scrn_id = 0;

                                        next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_OPT_ADD_RECIPIENT, MMI_FRM_NODE_AFTER_FLAG); 
                                        mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        U16 next_scrn_id = 0;

                                        next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG); 
                                        mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                    }
                                    AlmEnableSPOF();
*/
                                }
                                else
                                {
                                    ASSERT(0);
                                }

                            }
                            else
                            {
                                ASSERT(0);
                            }

                        }
                            break;

                            /* send and save, write new */
                        default:
                        {
                            ASSERT(0);
                        }
                            break;
                    }

                }
                    break;  /* send and save, write new */

                case SRV_UC_STATE_EDIT_EXISTED_MSG:
                case SRV_UC_STATE_SEND:
                {
                    ASSERT(msg_box);

                    switch (action)
                    {
                            /* send and save, edit */
                        case SRV_UC_ACTION_SEND:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                            #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                             /*   mmi_uc_phb_save_contact_notify_check(
                                    SRV_UC_PHB_LIST_TYPE_SMS,
                                    result,
                                    SCR_ID_UC_SENDING);*/
                            #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
                                switch (result)
                                {
                                    case SRV_SMS_CAUSE_NO_ERROR:
                                    {
                                        if (msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            /* highlighter need to set by UC */
                                            send_info->need_highlight_ind_to_um = TRUE;
                                        }

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
*/
                                        if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            srv_uc_addr_struct *addr = NULL;

                                            addr = srv_uc_get_addr(main->instance, 0);
                                            ucSaveSmsAfterSend(SRV_SMS_STATUS_SENT, addr->addr);
                                        }
                                        else
                                        {
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                if (msg_box == SRV_UM_MSG_BOX_DRAFT ||
                                                    msg_box == SRV_UM_MSG_BOX_UNSENT)
                                                {
                                                    srv_sms_delete_msg(
                                                        (U16) m_service_cntxt->send_info->existed_msg_id,
                                                        ucDeleteSmsCallback, 
                                                        this);
                                                }
                                            }
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                ucDeleteExistedMms();
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                    }
                                        break;

                                    case SRV_SMS_CAUSE_SEND_ABORT:
                                    {
                                        if (send_info->abort == UC_ABORT_NORMAL)
                                        {
/*
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_ABORTED_ID)), MMI_NMGR_BALLOON_TYPE_SUCCESS);

                                            if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD ||
                                                m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                            {
                                                U16 next_scrn_id = 0;

                                                next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_OPT_ADD_RECIPIENT, MMI_FRM_NODE_AFTER_FLAG); 
                                                mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                            }
                                            else
                                            {
                                                U16 next_scrn_id = 0;

                                                next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG); 
                                                mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                            }
*/
                                            m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
/*
                                            mmi_uc_delete_sms_frm_screen();
                                            AlmEnableSPOF();
*/
                                        }
                                        else if (send_info->abort == UC_ABORT_BY_END_KEY)
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                            {
                                                srv_uc_addr_struct *addr = NULL;

                                                addr = srv_uc_get_addr(
                                                        main->instance,
                                                        m_service_cntxt->send_info->curr_send_number);
                                                ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);
//                                                AlmEnableSPOF();
                                            }
                                            else
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    if (msg_box == SRV_UM_MSG_BOX_DRAFT ||
                                                        msg_box == SRV_UM_MSG_BOX_UNSENT)
                                                    {
                                                        srv_sms_delete_msg(
                                                            (U16) m_service_cntxt->send_info->existed_msg_id,
                                                            ucDeleteSmsCallback, 
                                                            this);
                                                    }

                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    srv_uc_addr_struct *addr = NULL;

                                                    addr = srv_uc_get_addr(
                                                            main->instance,
                                                            m_service_cntxt->send_info->curr_send_number);
                                                    ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }
                                    }
                                        break;

                                    case SRV_SMS_CAUSE_NOT_READY:
                                    {

//                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_SMS_MSG_NOT_READY_YET)), MMI_NMGR_BALLOON_TYPE_FAILURE);
/*
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
                                        AlmEnableSPOF();
*/
                                    }
                                        break;

                                    case SRV_SMS_CAUSE_NUMBER_INVALID:
                                    case SRV_SMS_CAUSE_SC_EMPTY:
                                   case SRV_SMS_CAUSE_DATA_EXCEED:

                                    {
                                        if (SRV_SMS_CAUSE_NUMBER_INVALID == result)
                                        {
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INVALID_NUMBER)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else if(SRV_SMS_CAUSE_DATA_EXCEED == result)
                                        {
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else
                                        {
//                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_SMS_FAILURE_SC_NUM_EMPTY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        /* no matter send(1st save for sms-bg) ok or fail, should notify anyway */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                      /*  mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_SMS,
                                            result,
                                            SCR_ID_UC_SENDING);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/*
                                        if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                        {
                                            mmi_uc_delete_between_screens(
                                                SCR_ID_UC_OPT_ADD_RECIPIENT,
                                                SCR_ID_UC_SENDING);
                                        }
                                        else
                                        {
                                            U16 next_scrn_id = 0;

                                            next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG);
                                            mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_SENDING);
                                        }
*/
                                        m_service_cntxt->send_info->action = SRV_UC_ACTION_IDLE;
/*
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();
*/
                                    }
                                        break;
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
                                #endif
                                    default:
                                    {
                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
*/
                                        if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            srv_uc_addr_struct *addr = NULL;

                                            addr = srv_uc_get_addr(
                                                    main->instance,
                                                    m_service_cntxt->send_info->curr_send_number);
                                            ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);
                                        }
                                        else
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT)
                                            {
                                                /* highlighter need to set by UC */
                                                send_info->need_highlight_ind_to_um = TRUE;
                                            }

                                            /* save msg from SMS to SMS. Delete original one and then save new one. */
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                if (msg_box == SRV_UM_MSG_BOX_DRAFT ||
                                                    msg_box == SRV_UM_MSG_BOX_UNSENT)
                                                {
                                                    srv_sms_delete_msg(
                                                        (U16) m_service_cntxt->send_info->existed_msg_id,
                                                        ucDeleteSmsCallback, 
                                                        this);
                                                }
                                            }
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                srv_uc_addr_struct *addr = NULL;

                                                addr = srv_uc_get_addr(
                                                        main->instance,
                                                        m_service_cntxt->send_info->curr_send_number);
                                                ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                    }
                                        break;
                                }
                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                ASSERT(0);
                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                            }
                            /* send and save , edit */
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                switch (result)
                                {
                                    case MMA_RESULT_OK:
                                    {
                                        if (send_info->abort != UC_ABORT_NONE)
                                        {
                                            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ACTION_FSM_CANCEL);
                                            send_info->send_result = MMA_RESULT_FAIL_USER_CANCEL;
                                            ucActionFsm(SRV_UC_ACTION_SEND, MMA_RESULT_FAIL_USER_CANCEL);
                                            return;
                                        }

                                        /* no matter send ok or fail, should notify anyway. */
                                        /* foreground send. should not be postcard cases. because postcard will be dependent with bgsr */
                                        /* won't notify if user select cancel send */
                                    #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                      /*  mmi_uc_phb_save_contact_notify_check(
                                            SRV_UC_PHB_LIST_TYPE_NORMAL_MMS,
                                            result,
                                            SCR_ID_UC_SENDING);*/
                                    #endif /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 

                                        if (msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            /* highlighter need to set by UC */
                                            send_info->need_highlight_ind_to_um = TRUE;
                                        }

                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
*/
                                        if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            // mmi_uc_save_mms_req(m_service_cntxt->send_info->new_msg_id, MMA_FOLDER_SENT); NO NEED
                                        }
                                        else
                                        {
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                                if (msg_box == SRV_UM_MSG_BOX_DRAFT ||
                                                    msg_box == SRV_UM_MSG_BOX_UNSENT)
                                                {
                                                    srv_sms_delete_msg(
                                                        (U16) m_service_cntxt->send_info->existed_msg_id,
                                                        ucDeleteSmsCallback, 
                                                        this);
                                                }
                                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                ASSERT(0);
                                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                            }
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                ucDeleteExistedMms();
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                    }
                                        break;

                                    case MMA_RESULT_FAIL_USER_CANCEL:
                                    {
                                        if (send_info->abort == UC_ABORT_NORMAL)
                                        {
                                            ucClearMsgBearer(SRV_UC_MSG_TYPE_MMS_PREFER);
                                        }
                                        else if (send_info->abort == UC_ABORT_BY_END_KEY)
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                            {
                                                /* mmi_uc_save_mms_req(
                                                    m_service_cntxt->send_info->new_msg_id,
                                                    MMA_FOLDER_OUTBOX);  NO NEED */
                                            }
                                            else
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                                    /* srv_sms_delete_msg(
                                                            (U16) m_service_cntxt->send_info->existed_msg_id,
                                                            ucDeleteSmsCallback, 
                                                            this); */

                                                    /* mmi_uc_save_mms_req(
                                                        m_service_cntxt->send_info->new_msg_id,
                                                        MMA_FOLDER_OUTBOX);  NO NEED */

                                                #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                    ASSERT(0);
                                                #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    ucDeleteExistedMms();
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }
                                    }
                                        break;

                                    default:
                                    {
                                        /* UC Screens may be deleted by other Apps, ex. USB normal mode. */
                                        /* Do not display processing screen in such cases. */
/*
                                        if (mmi_uc_is_uc_screen_in_history())
                                        {
                                            mmi_uc_set_processing_screen(
                                                0,
                                                STR_GLOBAL_SAVING,
                                                mmi_get_event_based_image(VCP_POPUP_TYPE_PROGRESS),
                                                0);
                                            mmi_uc_entry_processing_after_send();
                                        }
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_SENDING);
*/
                                        if (msg_box == SRV_UM_MSG_BOX_INBOX || msg_box == SRV_UM_MSG_BOX_SENT)
                                        {
                                            // mmi_uc_save_mms_req(m_service_cntxt->send_info->new_msg_id, MMA_FOLDER_OUTBOX); NO NEED
                                        }
                                        else
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT)
                                            {
                                                /* highlighter need to set by UC */
                                                send_info->need_highlight_ind_to_um = TRUE;
                                            }

                                            /* save msg from SMS to MMS. Save new one and then delete original one */
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                                /* srv_sms_delete_msg(
                                                    (U16) m_service_cntxt->send_info->existed_msg_id,
                                                    ucDeleteSmsCallback, 
                                                    this); */

                                                /* mmi_uc_save_mms_req(
                                                    m_service_cntxt->send_info->new_msg_id,
                                                    MMA_FOLDER_OUTBOX); NO NEED */

                                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                ASSERT(0);
                                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                            }
                                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                ucDeleteExistedMms();
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                    }
                                        break;

                                }

                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                            /* send and save, edit */
                        case SRV_UC_ACTION_SAVE:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                if (send_info->send_result == SRV_SMS_CAUSE_SEND_ABORT)
                                {
                                    if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
                                        if (result == SRV_SMS_CAUSE_NO_ERROR)
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    ucDeleteExistedMms();
                                                    return;
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                        }

                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
//                                        AlmEnableSPOF();
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (send_info->send_result == SRV_SMS_CAUSE_NO_ERROR)
                                    {
                                        if (result == SRV_SMS_CAUSE_NO_ERROR)
                                        {
                                            /* send > save, use same tone for all send fail reasons */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_SUCCESS_SAVE_SUCCESS)), MMI_NMGR_BALLOON_TYPE_SUCCESS);

                                        }
                                        else
                                        {
                                            /* send > save, use same tone for all send fail reasons */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_SUCCESS_SAVE_FAIL)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                        }

                                    }
                                    else
                                    {
                                        if (result == SRV_SMS_CAUSE_NO_ERROR)
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    ucDeleteExistedMms();
                                                    return;
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }

                                            /* send > save, use same tone for all send fail reasons */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_SUCCESS)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                        else
                                        {
                                            /* send > save, use same tone for all send fail reasons */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_FAIL)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        }
                                    }
/*
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
                                    mmi_uc_delete_sms_frm_screen();
*/
                                    resetApp();
                                    ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
//                                    AlmEnableSPOF();
                                }
                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                ASSERT(0);
                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                            }
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                if (send_info->send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
                                        if (result == MMA_RESULT_OK)
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                                    srv_sms_delete_msg(
                                                        (U16) m_service_cntxt->send_info->existed_msg_id,
                                                        ucDeleteSmsCallback, 
                                                        this);
                                                    return;
                                                #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                    ASSERT(0);
                                                #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                        }
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
//                                        AlmEnableSPOF();
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if (send_info->send_result == MMA_RESULT_OK)
                                    {
                                        if (result == MMA_RESULT_OK)
                                        {
                                            /* send > save */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_SUCCESS_SAVE_SUCCESS)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                        }
                                        else
                                        {
                                            /* send > save */
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_SUCCESS_SAVE_FAIL)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                        }

                                    }
                                    else
                                    {
                                        if (result == MMA_RESULT_OK)
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                                    srv_sms_delete_msg(
                                                        (U16) m_service_cntxt->send_info->existed_msg_id,
                                                        ucDeleteSmsCallback, 
                                                        this);
                                                    return;
                                                #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                    ASSERT(0);
                                                #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                        }

                                        /* should handle save fail. not move to above, because assert(0) maybe define to nothing in release version */
/*
                                        if (result != MMA_RESULT_OK)
                                        {
                                            mmi_uc_display_mma_send_result_popup(
                                                send_info->send_result,
                                                MMI_FALSE);
                                        }
                                        else
                                        {
                                            mmi_uc_display_mma_send_result_popup(
                                                send_info->send_result,
                                                MMI_TRUE);
                                        }
*/
                                    }
/*
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
*/
                                    resetApp();
//                                    AlmEnableSPOF();
                                }
                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                        case SRV_UC_ACTION_DELETE:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                if (send_info->send_result == SRV_SMS_CAUSE_NO_ERROR)
                                {
                                    srv_uc_addr_struct *addr = NULL;

                                    addr = srv_uc_get_addr(main->instance, 0);
                                    ucSaveSmsAfterSend(SRV_SMS_STATUS_SENT, addr->addr);
                                }
                                else if (send_info->send_result == SRV_SMS_CAUSE_SEND_ABORT)
                                {
                                    if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
                                        if ((m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER &&
                                             result == SRV_SMS_CAUSE_NO_ERROR) ||
                                            (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
                                             result == MMA_RESULT_OK))
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                            {
                                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    srv_uc_addr_struct *addr = NULL;

                                                    addr = srv_uc_get_addr(
                                                            main->instance,
                                                            m_service_cntxt->send_info->curr_send_number);
                                                    ucSaveSmsAfterSend(SRV_SMS_STATUS_SENT, addr->addr);
                                                    return;

                                                }
                                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
//                                        AlmEnableSPOF();
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {
                                    if ((m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER &&
                                         result == SRV_SMS_CAUSE_NO_ERROR) ||
                                        (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
                                         result == MMA_RESULT_OK))
                                    {
                                        if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                        {
                                            /* save msg from SMS to SMS. Delete original one and then save new one. */
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                srv_uc_addr_struct *addr = NULL;

                                                addr = srv_uc_get_addr(
                                                        main->instance,
                                                        m_service_cntxt->send_info->curr_send_number);
                                                ucSaveSmsAfterSend(SRV_SMS_STATUS_UNSENT, addr->addr);
                                                return;
                                            }
                                            /* save msg from MMS to SMS. Save new one and then delete original one. */
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                /* Do nothing. */
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }

                                        /* send > save, use same tone for all send fail reasons */
                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_SUCCESS)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                    }
                                    else
                                    {
                                        /* send > save, use same tone for all send fail reasons */
                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SEND_FAIL_SAVE_FAIL)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                    }
/*
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
                                    mmi_uc_delete_sms_frm_screen();
*/
                                    resetApp();
                                    ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
//                                    AlmEnableSPOF();
                                }
                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                ASSERT(0);
                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                            }
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                if (send_info->send_result == MMA_RESULT_OK)
                                {
                                    // mmi_uc_save_mms_req(m_service_cntxt->send_info->new_msg_id, MMA_FOLDER_SENT); NO NEED
                                }
                                else if (send_info->send_result == MMA_RESULT_FAIL_USER_CANCEL)
                                {
                                    if (send_info->abort == UC_ABORT_NORMAL)
                                    {
                                        ASSERT(result == MMA_RESULT_OK);

                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_ABORTED_ID)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
/*
                                        mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_UC_ABORTED_ID)), MMI_EVENT_SUCCESS, NULL);

                                    #ifdef __MMI_MMS_POSTCARD__
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                    #endif 
                                        if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD ||
                                            m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                        {
                                            U16 next_scrn_id = 0;

                                            next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_OPT_ADD_RECIPIENT, MMI_FRM_NODE_AFTER_FLAG); 
                                            mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                        }
                                        else
                                        {
                                            U16 next_scrn_id = 0;

                                            next_scrn_id = mmi_frm_scrn_get_neighbor_id(main->uc_cui_gid, SCR_ID_UC_EDITOR, MMI_FRM_NODE_AFTER_FLAG); 
                                            mmi_uc_delete_between_screens(next_scrn_id, SCR_ID_UC_PROCESSING);
                                        }
                                        AlmEnableSPOF();
*/
                                    }
                                    else if (send_info->abort == UC_ABORT_BY_END_KEY)
                                    {
                                        if ((m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER &&
                                             result == SRV_SMS_CAUSE_NO_ERROR) ||
                                            (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
                                             result == MMA_RESULT_OK))
                                        {
                                            if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                            {
                                                /* save msg from SMS to MMS. Save new one and then delete original one. */
                                                if (m_service_cntxt->send_info->existed_msg_type ==
                                                    SRV_UC_MSG_TYPE_SMS_PREFER)
                                                {
                                                    /* Do nothing. */
                                                }
                                                /* save msg from MMS to MMS. Delete original one and then save new one. */
                                                else if (m_service_cntxt->send_info->existed_msg_type ==
                                                         SRV_UC_MSG_TYPE_MMS_PREFER)
                                                {
                                                    /* mmi_uc_save_mms_req(
                                                        m_service_cntxt->send_info->new_msg_id,
                                                        MMA_FOLDER_OUTBOX); NO NEED */
                                                    return;
                                                }
                                                else
                                                {
                                                    ASSERT(0);
                                                }
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
/*
                                        if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                        {
                                            mmi_frm_scrn_close_active_id();
                                        }
                                        else
                                        {
                                            mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                        }
*/
                                        resetApp();
//                                        AlmEnableSPOF();
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else    /* send fail */
                                {
                                    if ((m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER &&
                                         result == SRV_SMS_CAUSE_NO_ERROR) ||
                                        (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER &&
                                         result == MMA_RESULT_OK))
                                    {
                                        if (msg_box == SRV_UM_MSG_BOX_UNSENT || msg_box == SRV_UM_MSG_BOX_DRAFT)
                                        {
                                            /* save msg from SMS to MMS. Save new one and then delete original one. */
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                                /* Do nothing. */
                                            }
                                            /* save msg from MMS to MMS. Delete original one and then save new one. */
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                /* mmi_uc_save_mms_req(
                                                    m_service_cntxt->send_info->new_msg_id,
                                                    MMA_FOLDER_OUTBOX);  NO NEED */
                                                return;
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }

                                    }
/*
                                    mmi_uc_display_mma_send_result_popup(send_info->send_result, MMI_TRUE);
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                    {
                                        mmi_uc_delete_between_screens(
                                            SCR_ID_UC_OPT_ADD_RECIPIENT,
                                            SCR_ID_UC_PROCESSING);
                                    }
                                    else
                                    {
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                    }
*/
                                    resetApp();
//                                    AlmEnableSPOF();
                                }
                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                            /* send , write new */
                        default:
                        {
                            ASSERT(0);
                        }
                            break;
                    }
                }
                    break;

                default:
                {
                    ASSERT(0);
                }
                    break;

            }
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */            
        }
            break;


#if defined(__MMI_MESSAGES_TEMPLATE__) || defined(__MMI_MMS_TEMPLATE_SUPPORT__)
		case SRV_UC_ACTION_SAVE_AS_TEMPLATE:
#endif            
        case SRV_UC_ACTION_SAVE:
        {
            srv_um_msg_box_enum msg_box = (srv_um_msg_box_enum) send_info->curr_folder;

            /* save */
            switch (m_service_cntxt->main->state)
            {
                    /* save, write new */
                case SRV_UC_STATE_WRITE_NEW_MSG:
                case SRV_UC_STATE_REPLY:
                case SRV_UC_STATE_REPLY_ALL:
                {
                    /* save, write new */
                    if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                    {
                    #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                        /* save, write new, sms */
                        if (action == SRV_UC_ACTION_SAVE)
                        {
                            /* check the case of Template & other save operation */
                        #ifdef __MMI_MESSAGES_TEMPLATE__    
                            if(operation_type == UC_OPERATION_WRITE_NEW_SMS_TEMPLATE)
                            {
                                if (result == SRV_SMS_TEMPLATE_RESULT_OK)
                                {
    //                                mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_EVENT_EXPLICITLY_SAVED, NULL);
                                      m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                }
                                else if (result == SRV_SMS_TEMPLATE_REACH_MAX_NUM)
                                {
    //                                mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_MEMORY_FULL)), MMI_EVENT_PROPLEM, NULL);
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MAX_TEMPLATE_ALREADY_PRESENT_ID)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                                else if (result == SRV_SMS_TEMPLATE_CONTENT_EMPTY)
                                {
    //                                mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY)), MMI_EVENT_PROPLEM, NULL);
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FAILURE_TEXT_CONTENT_EMPTY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                                else if (result == SRV_SMS_TEMPLATE_CONTENT_EXCEED)
                                {
    //                                mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY)), MMI_EVENT_PROPLEM, NULL);
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FAILURE_TEXT_CONTENT_EXCEED)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                                else
                                {
                                    /* SRV_SMS_TEMPLATE_FAIL_UNKNOW */
                                     m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_FAILED_TO_SAVE)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                            }
                            else
                        #endif /* __MMI_MESSAGES_TEMPLATE__ */        
                            {
                                if (result == SRV_SMS_CAUSE_NO_ERROR)
                                {
                                    if( !vappUcSmsSrvSaveStorageStatusShowPopup() )                                  
                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                }
                                else if (result == SRV_SMS_CAUSE_MEM_FULL)
                                {
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_MEMORY_FULL)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                                else if (result == SRV_SMS_CAUSE_MEM_INSUFFICIENT)
                                {
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                                else if (result == SRV_SMS_CAUSE_TCARD_NOT_AVAILABLE)
                                {
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_INSERT_CARD)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                                else
                                {
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_FAILED_TO_SAVE)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }

								if(result == SRV_SMS_CAUSE_NO_ERROR)
								{
									resetApp();
									ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
								}
								else
								{
									skip_deinit = VFX_TRUE;
									close_processing = VFX_TRUE;
								}


                            }
                        }
                        else
                        {
                            ASSERT(0);
                        }
                        #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                            ASSERT(0);
                        #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                    }
                    /* save, write new */
                    else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                    {
                        /* save, write new, mms */
                        if (action == SRV_UC_ACTION_SAVE)
                        {
                            if (result == MMA_RESULT_OK)
                            {
                                m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
							/*	resetApp();*/
                            }
                            else
                            {
								skip_deinit = VFX_TRUE;
								close_processing = VFX_TRUE;
                               // m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                            }
                            //resetApp();
                        }
                        else
                        {
                            ASSERT(0);
                        }

                    }
                    else
                    {
                        ASSERT(0);
                    }
                }
                    break;
                /* save, edit existed, save as template, edit existing template sms/mms */
                case SRV_UC_STATE_EDIT_EXISTED_MSG:
                {
                    /* save, edit */
                    if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                    {
                    #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                        /* save, edit, sms */
                        if (action == SRV_UC_ACTION_SAVE)
                        {
                             /* check the case of Template & other save operation */
                        #ifdef __MMI_MESSAGES_TEMPLATE__   
                            if(operation_type == UC_OPERATION_EDIT_SMS_TEMPLATE)
                            {
                                if (result == SRV_SMS_TEMPLATE_RESULT_OK)
                                {
                                      m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                }
                                else if (result == SRV_SMS_TEMPLATE_CONTENT_EMPTY)
                                {
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FAILURE_TEXT_CONTENT_EMPTY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                                else if (result == SRV_SMS_TEMPLATE_CONTENT_EXCEED)
                                {
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FAILURE_TEXT_CONTENT_EXCEED)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                                else
                                {
                                    /* SRV_SMS_TEMPLATE_FAIL_UNKNOW */
    //                                mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_FAILED_TO_SAVE)), MMI_EVENT_PROPLEM, NULL);
                                }
                            }
                            else
                        #endif /* __MMI_MESSAGES_TEMPLATE__ */         
                            {
                                if (result == SRV_SMS_CAUSE_NO_ERROR)
                                {
                                    if (msg_box == SRV_UM_MSG_BOX_DRAFT ||
                                        (msg_box == SRV_UM_MSG_BOX_UNSENT && m_service_cntxt->msg->to_num > 0))
                                    {
                                        /* save msg from SMS to SMS. Delete original one and then save new one. */
                                        if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                        {
                                            if( !vappUcSmsSrvSaveStorageStatusShowPopup() ) 
                                                m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                        }
                                        /* save msg from MMS to SMS. Save new one and then delete original one. */
                                        else if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                                        {
                                            ucDeleteExistedMms();
                                            return;
                                        }
                                        else
                                        {
                                            ASSERT(0);
                                        }
                                    }
                                    else
                                    {
                                        if( !vappUcSmsSrvSaveStorageStatusShowPopup() ) 
                                            m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
    
                                    }
                                }
                                else if (result == SRV_SMS_CAUSE_MEM_FULL)
                                {
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_MEMORY_FULL)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                                else if (result == SRV_SMS_CAUSE_MEM_INSUFFICIENT)
                                {
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                                else if (result == SRV_SMS_CAUSE_TCARD_NOT_AVAILABLE)
                                {
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_INSERT_CARD)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                                else
                                {
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_FAILED_TO_SAVE)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                }
                            }

				if(result == SRV_SMS_CAUSE_NO_ERROR)
				{
					resetApp();
					ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
				}
				else
				{
					skip_deinit = VFX_TRUE;
					close_processing = VFX_TRUE;
				}
/*
                            mmi_uc_delete_sms_frm_screen();
                            AlmEnableSPOF();
*/
                        }
                        else if (action == SRV_UC_ACTION_DELETE)
                        {
                            if (msg_box == SRV_UM_MSG_BOX_DRAFT ||
                                (msg_box == SRV_UM_MSG_BOX_UNSENT && m_service_cntxt->msg->to_num > 0))
                            {
                                /* save msg from SMS to SMS. Delete original one and then save new one. */
                                if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                {
                                    /* In SMS, delete orig one and then save new one, here, save new one if delete successfully */
                                    if (result == SRV_SMS_CAUSE_NO_ERROR)
                                    {
                                        m_service_cntxt->send_info->curr_send_number = 0;
                                        ucSaveSmsReq();
                                        skip_deinit = VFX_TRUE;
                                    }
                                    else
                                    {
                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_UNFINISHED)), MMI_NMGR_BALLOON_TYPE_FAILURE);
/*
                                    #ifdef __MMI_MMS_POSTCARD__
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                    #endif 
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
*/
                                        resetApp();
                                        ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                        mmi_uc_delete_sms_frm_screen();
                                        AlmEnableSPOF();
*/
                                    }
                                }
                                /* save msg from MMS to SMS. Save new one and then delete original one. */
                                else if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                                {
                                    /* Deletion may fail in USB normal mode. */

                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
/*
                                    mmi_popup_display((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_EVENT_EXPLICITLY_SAVED, NULL);
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
*/
                                    resetApp();
                                    ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER);
/*
                                    mmi_uc_delete_sms_frm_screen();
                                    AlmEnableSPOF();
*/
                                }
                                else
                                {
                                    ASSERT(0);
                                }
                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                        else
                        {
                            ASSERT(0);
                        }
                    #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                        ASSERT(0);
                    #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                    }
                    /* save, edit */
                    else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                    {
                        /* save, edit, mms */
                        if (action == SRV_UC_ACTION_SAVE)
                        {
                            if (result == MMA_RESULT_OK)
                            {
                                if (msg_box == SRV_UM_MSG_BOX_DRAFT)
                                {
                                    /* save msg from SMS to MMS. Save new one and then delete original one. */
                                    if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                    {
                                    #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                        srv_sms_delete_msg(
                                            (U16) m_service_cntxt->send_info->existed_msg_id,
                                            ucDeleteSmsCallback, 
                                            this);
                                        return;
                                    #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                        ASSERT(0);
                                    #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                    }
                                    /* save msg from MMS to MMS. Delete original one and then save new one. */
                                    else if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                                    {
                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                    }
                                    else
                                    {
                                        ASSERT(0);
                                    }
                                }
                                else
                                {
                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                }
								resetApp();
                            }
                            else
                            {
								skip_deinit = VFX_TRUE;
								close_processing = VFX_TRUE;
                                //m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                            }
                            {
/*
                            #ifdef __MMI_MMS_POSTCARD__
                                mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                            #endif 
                                mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
*/
                                //resetApp();
//                                AlmEnableSPOF();
                            }
                        }
                        else if (action == SRV_UC_ACTION_DELETE)
                        {
                            if (msg_box == SRV_UM_MSG_BOX_DRAFT)
                            {
                                /* save msg from SMS to MMS. save new one and then delete original one . */
                                if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                {
                                #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                    ASSERT(result == SRV_SMS_CAUSE_NO_ERROR);

                                    m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SAVED)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                    /*
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                    mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
*/
                                    resetApp();
//                                    AlmEnableSPOF();
                                #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                    ASSERT(0);
                                #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                }
                                /* save msg from MMS to MMS. delete original one and then Save new one. */
                                else if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                                {
                                    if (result == MMA_RESULT_OK)
                                    {
                                        send_info->need_highlight_ind_to_um = TRUE;
                                        // mmi_uc_save_mms_req(m_service_cntxt->send_info->new_msg_id, MMA_FOLDER_DRAFT); NO NEED
                                    }
                                    else
                                    {

                                        m_signalPopup.postEmit((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_UNFINISHED)), MMI_NMGR_BALLOON_TYPE_FAILURE);
                                        /*
                                    #ifdef __MMI_MMS_POSTCARD__
                                        mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                    #endif 
                                        mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
*/
                                        resetApp();
//                                        AlmEnableSPOF();
                                    }
                                }
                                else
                                {
                                    ASSERT(0);
                                }
                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                        else
                        {
                            ASSERT(0);
                        }
                    }
                    else
                    {
                        ASSERT(0);
                    }
                }
                    break;

                default:
                {
                    ASSERT(0);
                }
                    break;

            }
        }
            break;  /* save */

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
#endif

        case SRV_UC_ACTION_SAVE_IN_BACKGROUND:
        {
            /* save in background */
            switch (m_service_cntxt->main->state)
            {
                    /* save in background, write new */
                case SRV_UC_STATE_WRITE_NEW_MSG:
                case SRV_UC_STATE_REPLY:
                case SRV_UC_STATE_REPLY_ALL:
                case SRV_UC_STATE_EDIT_EXISTED_MSG:
                {
                    /* save in background, write new */
                    if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                    {
                    #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                        /* save, write new, sms */
                        if (action == SRV_UC_ACTION_SAVE)
                        {
                            resetApp();

                            /* The ems buffer would be reset in SMS framework. */
                            /* ucClearMsgBearer(SRV_UC_MSG_TYPE_SMS_PREFER); */
//                            AlmEnableSPOF();
                        }
                        else
                        {
                            ASSERT(0);
                        }
                    #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                        ASSERT(0);
                    #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                    }
                    /* save in background, write new */
                    else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                    {
                        /* save in background, write new, mms */
                        if (action == SRV_UC_ACTION_SAVE)
                        {
                            resetApp();
//                            AlmEnableSPOF();
                        }
                        else
                        {
                            ASSERT(0);
                        }
                    }
                    else
                    {
                        ASSERT(0);
                    }
                }
                    break;

                default:
                {
                    ASSERT(0);
                }
                    break;

            }
        }
            break;  /* save in background */

    #if (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__))

        case SRV_UC_ACTION_SEND_IN_BACKGROUND:
        {
            switch (m_service_cntxt->main->state)
            {
                case SRV_UC_STATE_WRITE_NEW_MSG:
                case SRV_UC_STATE_FORWARD:
                case SRV_UC_STATE_REPLY:
                case SRV_UC_STATE_REPLY_ALL:
                {
                    switch (action)
                    {
                            /* send in background , write new */
                        case SRV_UC_ACTION_SEND:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                                ASSERT(0);
                            }
                            /* send in background , write new mms */
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
                                /* no matter send ok or fail, should notify anyway. */
                                /* background send. postcard cases also run this path for sending to one recipient */
                                /* If postcard mode-- ???? wait for postcard feature is done */

/*
                                if (m_service_cntxt->main->state == SRV_UC_STATE_FORWARD)
                                {
                                    mmi_uc_delete_between_screens(SCR_ID_UC_OPT_ADD_RECIPIENT, SCR_ID_UC_PROCESSING);
                                }
                                else
                                {
                                    mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                }

                                if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                {
                                    mmi_frm_scrn_close_active_id();
                                }
                                else
                                {
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                #ifdef __MMI_MMS_POSTCARD__
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_WRITE_MSG_SELECTION);
                                #endif 
                                }
*/
                                //vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SENT)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                //resetApp();
                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                            /* send in background, write new */
                        case SRV_UC_ACTION_SAVE:
                        {
                            ASSERT(0);
                        }
                            break;

                            /* send in background, write new */
                        case SRV_UC_ACTION_DELETE:
                        {
                            ASSERT(0);
                        }
                            break;

                            /* send in background, write new */
                        default:
                        {
                            ASSERT(0);
                        }
                            break;
                    }
                }
                    break;  /* send in background, write new  */

                    /* send in background, edit */
                case SRV_UC_STATE_EDIT_EXISTED_MSG:
                case SRV_UC_STATE_SEND:
                {
                    srv_um_msg_box_enum msg_box = (srv_um_msg_box_enum) send_info->curr_folder;

                    ASSERT(msg_box);

                    switch (action)
                    {
                            /* send in background, edit */
                        case SRV_UC_ACTION_SEND:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                                ASSERT(0);
                            }
                            /* send in background, edit */
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
/*
                                if (m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                                {
                                    mmi_uc_delete_between_screens(SCR_ID_UC_OPT_ADD_RECIPIENT, SCR_ID_UC_PROCESSING);
                                }
                                else
                                {
                                    mmi_uc_delete_between_screens(SCR_ID_UC_EDITOR, SCR_ID_UC_PROCESSING);
                                }
*/
                                switch (result)
                                {
                                    case MMA_RESULT_OK:
                                    {
                                        if (
                                    #ifndef __MMI_MMS_BGSR_SUPPORT__
                                               msg_box == SRV_UM_MSG_BOX_UNSENT ||
                                    #endif 
                                               msg_box == SRV_UM_MSG_BOX_DRAFT)
                                        {
                                            if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                                            {
                                            #if !defined(__MMI_MMS_STANDALONE_COMPOSER__)
                                                /* when sms deleting, use this screen to block mmi, to aviod display list, 
                                                   UM will get wrong info from sms */
/*
                                                if ((mmi_frm_scrn_get_active_id() > SCR_ID_UC_START) &&
                                                      (mmi_frm_scrn_get_active_id() < SCR_ID_UC_END))
                                                {
                                                    mmi_uc_set_processing_screen(
                                                        0,
                                                        STR_GLOBAL_DELETING,
                                                        mmi_get_event_based_image (VCP_POPUP_TYPE_PROGRESS),
                                                        0);

                                                    mmi_uc_entry_processing_generic();
                                                }
                                                else
                                                {
                                                    mmi_uc_add_processing_to_history();
                                                }
*/
                                                srv_sms_delete_msg(
                                                    (U16) m_service_cntxt->send_info->existed_msg_id,
                                                    ucDeleteSmsCallback, 
                                                    this);
                                            #else /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 
                                                ASSERT(0);
                                            #endif /* !defined(__MMI_MMS_STANDALONE_COMPOSER__) */ 

                                            }
                                            else if (m_service_cntxt->send_info->existed_msg_type ==
                                                     SRV_UC_MSG_TYPE_MMS_PREFER)
                                            {
                                                /* Will be trigger after ucDeleteExistedMms */
                                                ucDeleteExistedMms();
                                            }
                                            else
                                            {
                                                ASSERT(0);
                                            }
                                        }
                                        else
                                        {
/*
                                            if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                            {
                                                mmi_frm_scrn_close_active_id();
                                            }
                                            else
                                            {
                                                mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                            }
*/
                                            resetApp();
                                        }
                                        if (m_service_cntxt->main->state == SRV_UC_STATE_EDIT_EXISTED_MSG)
                                        {
                                        #ifdef __MMI_MMS_POSTCARD__
                                            if (m_service_cntxt->msg_type->MMS_edit_mode ==
                                                SRV_UC_MMS_EDIT_MODE_POSTCARD_MMS)
                                            {
                                                srv_postcard_clear_all_context(main->instance);
                                            }
                                        #endif /* __MMI_MMS_POSTCARD__ */ 

                                        }
                                    }
                                    //vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(STR_GLOBAL_SENT)), MMI_NMGR_BALLOON_TYPE_SUCCESS);
                                        break;

                                    default:
                                    {
                                        ASSERT(0);
                                    }
                                        break;

                                }

                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                            /* send in background , edit */
                        case SRV_UC_ACTION_SAVE:
                        {
                            ASSERT(0);
                        }
                            break;

                            /* send in background , edit */
                        case SRV_UC_ACTION_DELETE:
                        {
                            if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
                            {
                                ASSERT(0);
                            }
                            else if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
                            {
/*                            #ifdef __MMI_PHB_SAVE_CONTACT_NOTIFY__
                                mmi_uc_phb_save_contact_notify_check(
                                    SRV_UC_PHB_LIST_TYPE_NORMAL_MMS,
                                    result,
                                    SCR_ID_UC_PROCESSING);
                            #endif */ /* __MMI_PHB_SAVE_CONTACT_NOTIFY__ */ 
/*
                                if (mmi_frm_scrn_get_active_id() == SCR_ID_UC_PROCESSING)
                                {
                                    mmi_frm_scrn_close_active_id();
                                }
                                else
                                {
                                    mmi_frm_scrn_close(main->uc_cui_gid, SCR_ID_UC_PROCESSING);
                                }
*/
                                resetApp();
                            }
                            else
                            {
                                ASSERT(0);
                            }
                        }
                            break;

                            /* send , write new */
                        default:
                        {
                            ASSERT(0);
                        }
                            break;
                    }
                }
                    break;  /* send , edit existed  */

                default:
                {
                    ASSERT(0);
                }
                    break;
            }
        }
            break;
    #endif /* (defined(__MMI_MMS_2__) || defined(__MMI_MMS_BGSR_SUPPORT__)) */ 

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
#endif
        case SRV_UC_ACTION_IDLE:
        {

            VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_ACTION_FSM_DO_NOTHING);
            skip_deinit = VFX_TRUE;
        }
            break;

        default:
        {
            ASSERT(0);
        }
            break;
    }

    if(skip_deinit == VFX_FALSE)
    {
        m_signalConnectOnError.postEmit();
    }
    if(close_processing == VFX_TRUE)
    {
        m_signalConnectToCloseProgress.postEmit();
    }
}

void VappUcAppData::ucSetInsertMenu(void)
{
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_MULTIMEDIA);
#if (!defined(__LOW_COST_SUPPORT_COMMON__))
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_IMAGE_OPTIONS);
#else
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_INSERT_IMAGE);
#endif

#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
#if (!defined(__LOW_COST_SUPPORT_COMMON__))
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_VIDEO_OPTIONS);
#else
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_INSERT_VIDEO);
#endif
#endif

#ifdef __MMI_SOUNDREC_CUI__
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_AUDIO_OPTIONS);					
#else
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_INSERT_AUDIO);
#endif
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_ATTACHMENT);
#if (defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__) || defined(__MMI_MESSAGES_TEMPLATE__))   
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_TEMPLATE);
#endif
#if defined(__MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__)    
	mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_INSERT_EMOTICON);
#endif
#if defined(__MMI_MESSAGES_TEMPLATE__) 
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_INSERT_TEMPLATE);
#endif

#if defined(__MMI_VCARD__)
    mmi_frm_unhide_menu_item(MENU_ID_VUC_INSERT_VCARD);
#endif

#ifdef __MMI_VCALENDAR__
    mmi_frm_unhide_menu_item(MENU_ID_VUC_INSERT_VTASK);
	mmi_frm_unhide_menu_item(MENU_ID_VUC_INSERT_VEVENT);
#endif /* __MMI_VCALENDAR__ */
  
    mmi_frm_unhide_menu_item(MENU_ID_VUC_INSERT_FILE);

    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_TEXT);
#ifdef	__MMI_COSMOS_UC_INSERT_PHONE_NAME_ADD_SUPPORT__
#if 0
/* under construction !*/
/* under construction !*/
#endif    
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_INSERT_PHB_NAME_AND_NUM);
#else
#if 0
/* under construction !*/
/* under construction !*/
#endif    
    mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_INSERT_PHB_NAME_AND_NUM);
#endif

	/*Cosmos Opera Turbo */
#if !defined(__MMI_BRW_BKM_INTERFACE_SUPPORT__) || !defined(BROWSER_SUPPORT)	
    mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_INSERT_BOOKMARK);
#else
    mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_INSERT_BOOKMARK);
#endif

 if(GetNumOfChild_Ext(MENU_ID_VUC_OPT_TEXT) == 0)
 {
   mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_TEXT);
 }

 #ifdef __MMI_EMAIL__
     if (m_service_cntxt->msg_type->MMS_edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
 #endif
     {
       mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_SLIDE);
       mmi_frm_unhide_menu_item(MENU_ID_VUC_OPT_SLIDE_INSERT);
     }
	
    if (m_service_cntxt->msg_type->caller_specific_msg_type == SRV_UC_MSG_TYPE_SMS_ONLY)
    {
        mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_SLIDE);
        mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_SLIDE_INSERT);
#if (!defined(__LOW_COST_SUPPORT_COMMON__))
        mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_IMAGE_OPTIONS);
#else
        mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_INSERT_IMAGE);
#endif
#ifdef __MMI_SOUNDREC_CUI__
        mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_AUDIO_OPTIONS);					
#else
        mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_INSERT_AUDIO);
#endif

#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
#if (!defined(__LOW_COST_SUPPORT_COMMON__))

        mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_VIDEO_OPTIONS);
#else
        mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_INSERT_VIDEO);
#endif
#endif
        mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_ATTACHMENT);
#if defined(__MMI_VCARD__)
        mmi_frm_hide_menu_item( MENU_ID_VUC_INSERT_VCARD);
#endif
#ifdef __MMI_VCALENDAR__
        mmi_frm_hide_menu_item( MENU_ID_VUC_INSERT_VTASK);
		mmi_frm_hide_menu_item( MENU_ID_VUC_INSERT_VEVENT);
#endif /* __MMI_VCALENDAR__ */        

     //   mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_INSERT_BOOKMARK);
    }
    else
    {
    #ifdef __MMI_EMAIL__
        if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
        {
  //          /* EMAIL disallow to add other media */
           mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_SLIDE);
           mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_SLIDE_INSERT);
            if (m_service_cntxt->msg->msg_body.total_attach_no == vappUcGetMaxAttachemntCount())
            {
                mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_ATTACHMENT);
#if defined(__MMI_VCARD__)
                mmi_frm_hide_menu_item( MENU_ID_VUC_INSERT_VCARD);
#endif
#ifdef __MMI_VCALENDAR__
				mmi_frm_hide_menu_item( MENU_ID_VUC_INSERT_VTASK);
				mmi_frm_hide_menu_item( MENU_ID_VUC_INSERT_VEVENT);
#endif /* __MMI_VCALENDAR__ */
				mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_MULTIMEDIA);
#if (defined(__LOW_COST_SUPPORT_COMMON__))
				mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_INSERT_IMAGE);
#else
				mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_IMAGE_OPTIONS);
#endif

#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
#if (defined(__LOW_COST_SUPPORT_COMMON__))
				mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_INSERT_VIDEO);
#else
				mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_VIDEO_OPTIONS);
#endif
#endif

#ifdef __MMI_SOUNDREC_CUI__
				mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_AUDIO_OPTIONS);					
#else
				mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_INSERT_AUDIO);
#endif
            }
        }
      //  else
    #endif /* __MMI_EMAIL__ */ 
        {
            if (m_service_cntxt->msg->msg_body.total_attach_no == vappUcGetMaxAttachemntCount())
            {
                mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_ATTACHMENT);
#if defined(__MMI_VCARD__)
                mmi_frm_hide_menu_item( MENU_ID_VUC_INSERT_VCARD);
#endif
#ifdef __MMI_VCALENDAR__
				mmi_frm_hide_menu_item( MENU_ID_VUC_INSERT_VTASK);
				mmi_frm_hide_menu_item( MENU_ID_VUC_INSERT_VEVENT);
#endif               
            }
            else
            {
                mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_ATTACHMENT);
            }
            if (m_service_cntxt->msg->msg_body.slide_no == SRV_UC_MAX_MMS_SLIDE_NUM)
            {
                mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_SLIDE);
                if (m_service_cntxt->msg->msg_body.curr_slide->img.object != NULL ||
                    m_service_cntxt->msg->msg_body.curr_slide->vid.object != NULL)
                {
#if (defined(__LOW_COST_SUPPORT_COMMON__))
                    mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_INSERT_IMAGE);
#else
                    mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_IMAGE_OPTIONS);
#endif
                }
		        else
		        {
#if (defined(__LOW_COST_SUPPORT_COMMON__))
                    mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_INSERT_IMAGE);
#else
                    mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_IMAGE_OPTIONS);
#endif
		        }

                if (m_service_cntxt->msg->msg_body.curr_slide->aud.object != NULL ||
                    m_service_cntxt->msg->msg_body.curr_slide->vid.object != NULL)
                {
#ifdef __MMI_SOUNDREC_CUI__
                    mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_AUDIO_OPTIONS);
#else
                    mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_INSERT_AUDIO);
#endif
                }
		        else
		        {
#ifdef __MMI_SOUNDREC_CUI__
                    mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_AUDIO_OPTIONS);
#else
                    mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_INSERT_AUDIO);
#endif
		        }

             #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
                    if (m_service_cntxt->msg->msg_body.curr_slide->vid.object != NULL ||
                    m_service_cntxt->msg->msg_body.curr_slide->img.object != NULL ||
                    m_service_cntxt->msg->msg_body.curr_slide->aud.object != NULL)
                {
#if (defined(__LOW_COST_SUPPORT_COMMON__))
                    mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_INSERT_VIDEO);
#else
                    mmi_frm_hide_menu_item( MENU_ID_VUC_OPT_VIDEO_OPTIONS);
#endif
                }
		        else
		        {
#if (defined(__LOW_COST_SUPPORT_COMMON__))
                    mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_INSERT_VIDEO);
#else
                    mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_VIDEO_OPTIONS);
#endif
                }
		    #endif
            }
            else
            {
#if (!defined(__LOW_COST_SUPPORT_COMMON__))
                mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_IMAGE_OPTIONS);
#else
                mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_INSERT_IMAGE);
#endif
#ifdef __MMI_SOUNDREC_CUI__
                mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_AUDIO_OPTIONS);
#else
                mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_INSERT_AUDIO);
#endif

#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
#if (!defined(__LOW_COST_SUPPORT_COMMON__))      
                mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_VIDEO_OPTIONS);
#else
                mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_INSERT_VIDEO);
#endif
#endif/* #ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__ */ 
 //               mmi_frm_unhide_menu_item( MENU_ID_VUC_OPT_SLIDE);
            }
            if(GetNumOfChild_Ext(MENU_ID_VUC_OPT_MULTIMEDIA) == 0)
            {
              mmi_frm_hide_menu_item(MENU_ID_VUC_OPT_MULTIMEDIA);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  vapp_uc_get_address_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  type        [IN]        
 * RETURNS
 *  number pointer
 *****************************************************************************/
extern "C" srv_uc_addr_struct *vapp_uc_get_address_callback(U16 index, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappUcAppData *app = (VappUcAppData*)user_data;
    srv_uc_addr_struct* addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //   ASSERT(index < member_count);
    addr= srv_uc_get_addr( app->main->instance, index);
  //  *type = MMI_PHB_ADDRESS_TYPE_EMAIL;
    return addr;
}

/*****************************************************************************
 * FUNCTION
 *  vapp_uc_get_media_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  offset        [IN]        Offset only in case virtual file
 *  Size    [IN]    Must need in case virtual file.
 *  user_data   [IN]    Caller demand for identifying its instance.
 * RETURNS
 *  U8*
 *****************************************************************************/
extern "C" void *vapp_uc_get_media_callback(U16 index, vapp_uc_media_info *media_info, void* user_data)   /* Offset in case virtual file */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappUcAppData *app = (VappUcAppData*)user_data;
    mma_mms_attachment_info_struct * attachment_media = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //   ASSERT(index < member_count);
    attachment_media = srv_uc_get_attachment_by_index( app->main->instance, index);
    //*type = SRV_UC_OBJECT_TYPE_ATTACHMENT;
//    if(attachment_media->is_virtual_file)
    {
        media_info->is_virtual_file = attachment_media->object->is_virtual_file;
        media_info->size = attachment_media->object->size;
        media_info->offset = (attachment_media->object->is_virtual_file)? attachment_media->object->offset: 0;
        media_info->file_path = (U16*)attachment_media->object->file_path_ucs;
        media_info->file_name = (U16*)attachment_media->object->file_name_ucs;
    }
 //   else
    {
 //       memset( *media_info, 0, sizeof(media_info));
  //      *media_info->file_path = attachment_media->object->file_path_ucs;    
    }
    return NULL;
}


extern "C" mmi_ret vappUcHandleSmsMsgDelEvent(mmi_event_struct *event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sms_event_struct *sms_event_data = (srv_sms_event_struct *) event_data;
    srv_sms_event_delete_struct *event_info = (srv_sms_event_delete_struct*)sms_event_data->event_info;
    U32 instance = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(event_info);
    while(instance < MAX_UC_INSTANCES)
    {
        if(g_app.app_data[instance])
        {
            if (srv_uc_is_sms_in_use(g_app.app_data[instance]->main->instance, event_info->msg_id))
            {
                if (g_app.app_data[instance]->m_service_cntxt->main->state == SRV_UC_STATE_FORWARD ||
                                g_app.app_data[instance]->m_service_cntxt->main->state == SRV_UC_STATE_SEND)
                {
                    //mmi_uc_delete_all_uc_screens(); TODO: What to do about this?
                }
                else
                {
                    g_app.app_data[instance]->m_service_cntxt->main->state = SRV_UC_STATE_WRITE_NEW_MSG;
                }
                g_app.app_data[instance]->m_service_cntxt->send_info->existed_msg_id = 0;
            }
        }
        instance++;
    }
    return MMI_RET_OK;
}


extern "C" mmi_ret vappUcSdCardPlugInHdlr(mmi_event_struct *event_data)
{
	U8 i = 0;
	U8 drive_counter = 0;
	switch(event_data->evt_id)
	{
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
	        srv_fmgr_notification_dev_plug_event_struct *plug_in_info = (srv_fmgr_notification_dev_plug_event_struct*)event_data;

			for (i = 0; i < plug_in_info->count; i++)
			{
				if (plug_in_info->drv_letters[i] == SRV_FMGR_CARD_DRV)
				{
					drive_counter++;
				}
			}
			if(drive_counter)
			{
                U32 instance = 0;
                while(instance < MAX_UC_INSTANCES)
                {
                #ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
                    if(g_app.is_serialize[instance] == VFX_TRUE)
                    {
                        // call vapp_uc_proxy_proc() later to hanlde this event
                    }
                    else
                #endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */          
                    {
                        if(g_app.app_data[instance])
                        {
            				g_app.app_data[instance]->vappUcSdPlugInHdlr();
                        }
                    }
                    instance++;
                }
			}
			
			break;
	}

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
    vapp_uc_proxy_proc(event_data);
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */ 

	return MMI_RET_OK;
}


extern "C" mmi_ret vappUcSdCardPlugOutHdlr(mmi_event_struct *event_data)
{
	U8 i = 0;
	U8 drive_counter = 0;
	switch(event_data->evt_id)
	{
		case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:

	        srv_fmgr_notification_dev_plug_event_struct *plug_in_info = (srv_fmgr_notification_dev_plug_event_struct*)event_data;

			for (i = 0; i < plug_in_info->count; i++)
			{
				if (plug_in_info->drv_letters[i] == SRV_FMGR_CARD_DRV)
				{
					drive_counter++;
				}
			}
			if(drive_counter)
			{
                U32 instance = 0;
                while(instance < MAX_UC_INSTANCES)
                {
                    VappUcAppData *app_data = g_app.app_data[instance];
                    
                #ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
                    if(g_app.is_serialize[instance] == VFX_TRUE)
                    {
                        // call vapp_uc_proxy_proc() later to hanlde this event
                    }
                    else
                #endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */   
                    {
                        if(app_data)
                        {
            				app_data->vappUcSdPlugOutHdlr();
                        }
                    }
                    instance++;
                }
			}
			
			break;
	}

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
    vapp_uc_proxy_proc(event_data);
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */ 

	return MMI_RET_OK;
}


extern "C" void vappUcTerminateAllApps(void)
{

    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_TERMINATE_ALL_APPS);
    U32 i = 0;
    while(i < MAX_UC_INSTANCES)
    {
        if(g_app.app_data[i])
        {
            VcuiUcMainCui* app = (VcuiUcMainCui *)g_app.app_data[i]->m_parent;
            app->vappUcTerminate();
        }
        i++;
    }
}

extern "C" mmi_ret vappUcForceClose(mmi_event_struct *event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bootup_is_booting())
    {
        /* No data account screen yet */
        return MMI_RET_OK;
    }

    while(i < MAX_UC_INSTANCES)
    {
        if(g_app.app_data[i])
        {
            VcuiUcMainCui* app = (VcuiUcMainCui *)g_app.app_data[i]->m_parent;
            #ifndef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
                if(g_app.app_data[i]->m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER && 
                    g_app.app_data[i]->send_info->abort != UC_ABORT_BY_END_KEY && 
                    (g_app.app_data[i]->m_service_cntxt->send_info->action == SRV_UC_ACTION_SEND_AND_SAVE ||
                    g_app.app_data[i]->m_service_cntxt->send_info->action == SRV_UC_ACTION_SEND))
                {
                    srv_sms_clear_send_callback(g_app.app_data[i]->main->send_handle);
                    srv_sms_abort_send(g_app.app_data[i]->main->send_handle);
                    app->vappUcTerminate();
                    //AlmEnableSPOF();
                    i++;
		            continue;
                }
            #endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
                app->vappUcTerminate();
        }
        i++;
    }
    return MMI_RET_OK;
}


//#ifdef __MMI_USB_SUPPORT__
extern "C" mmi_ret vappUcUsbMsPlugInHdlr(mmi_event_struct *event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(i < MAX_UC_INSTANCES)
    {
        VappUcAppData *app_data = g_app.app_data[i];
    #ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
        if(g_app.is_serialize[i] == VFX_TRUE)
        {
            // call vapp_uc_proxy_proc() later to hanlde this event
        }
        else
    #endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */   
        {
            if(app_data)
            {
                app_data->vappUcUsbMsModePlugInHdlr();
            }
        }
        i++;
    }

#ifdef __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__
    vapp_uc_proxy_proc(event_data);
#endif /* __MMI_COSMOS_UC_VOLUNTEER_FREE_SUPPORT__ */ 

	return MMI_RET_OK;
}
//#endif

extern "C" srv_uc_sim_id vappUcConvertMmiSimIdToUc(U32 sim_id)
{
    switch((mmi_sim_enum)sim_id)
    {
        case MMI_SIM1:
            return SRV_UC_SIM_ID_GSM_SIM1;
        case MMI_SIM2:
            return SRV_UC_SIM_ID_GSM_SIM2;
        case MMI_SIM3:
            return SRV_UC_SIM_ID_GSM_SIM3;
        case MMI_SIM4:
            return SRV_UC_SIM_ID_GSM_SIM4;
        default:
            return SRV_UC_SIM_ID_UNCLASSIFIED;
    }
}

extern "C" mmi_sim_enum vappUcConvertUCSimIdToMmi(U32 sim_id)
{
    switch((srv_uc_sim_id)sim_id)
    {
        case SRV_UC_SIM_ID_GSM_SIM1:
            return MMI_SIM1;
        case SRV_UC_SIM_ID_GSM_SIM2:
            return MMI_SIM2;
        case SRV_UC_SIM_ID_GSM_SIM3:
            return MMI_SIM3;
        case SRV_UC_SIM_ID_GSM_SIM4:
            return MMI_SIM4;
        default:
            return MMI_SIM_NONE;
    }
}


extern "C" srv_sms_sim_enum vappUcConvertUCSimIdToSMS(U32 sim_id)
{
    switch((srv_uc_sim_id)sim_id)
    {
        case SRV_UC_SIM_ID_GSM_SIM1:
            return SRV_SMS_SIM_1;
        case SRV_UC_SIM_ID_GSM_SIM2:
            return SRV_SMS_SIM_2;
#if (MMI_MAX_SIM_NUM >= 3)
        case SRV_UC_SIM_ID_GSM_SIM3:
            return SRV_SMS_SIM_3;
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        case SRV_UC_SIM_ID_GSM_SIM4:
            return SRV_SMS_SIM_4;
#endif
        default:
            return SRV_SMS_SIM_TOTAL;
    }
}

extern "C" srv_uc_sim_id vappUcConvertSMSSimIdToUc(U32 sim_id)
{
    switch((srv_sms_sim_enum)sim_id)
    {
        case SRV_SMS_SIM_1:
            return SRV_UC_SIM_ID_GSM_SIM1;
        case SRV_SMS_SIM_2:
            return SRV_UC_SIM_ID_GSM_SIM2;
#if (MMI_MAX_SIM_NUM >= 3)
        case SRV_SMS_SIM_3:
            return SRV_UC_SIM_ID_GSM_SIM3;
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        case SRV_SMS_SIM_4:
            return SRV_UC_SIM_ID_GSM_SIM4;
#endif
        default:
            return SRV_UC_SIM_ID_UNCLASSIFIED;
    }
}

extern "C" U32 vappUcConvertSwitchModeToUcSimId(U32 swith_mode)
{
    switch((srv_mode_switch_type_enum)swith_mode)
    {
        case SRV_MODE_SWITCH_SIM1:
            return SRV_UC_SIM_ID_GSM_SIM1;
#if (MMI_MAX_SIM_NUM >= 2)
        case SRV_MODE_SWITCH_SIM2:
            return SRV_UC_SIM_ID_GSM_SIM2;
        case SRV_MODE_SWITCH_SIM3:
            return SRV_UC_SIM_ID_GSM_SIM3;
        case SRV_MODE_SWITCH_SIM4:
            return SRV_UC_SIM_ID_GSM_SIM4;
#if (MMI_MAX_SIM_NUM == 2)
        case SRV_MODE_SWITCH_SIM_ALL:
            return SRV_UC_SIM_ID_GSM_SIM1 | SRV_UC_SIM_ID_GSM_SIM2;
#endif
#if (MMI_MAX_SIM_NUM == 3)
        case SRV_MODE_SWITCH_SIM_ALL:
            return SRV_UC_SIM_ID_GSM_SIM1 | SRV_UC_SIM_ID_GSM_SIM2| SRV_UC_SIM_ID_GSM_SIM3;
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        case SRV_MODE_SWITCH_SIM_ALL:
            return SRV_UC_SIM_ID_GSM_SIM1 | SRV_UC_SIM_ID_GSM_SIM2| SRV_UC_SIM_ID_GSM_SIM3|SRV_UC_SIM_ID_GSM_SIM4;
#endif
#endif
        default:
            return SRV_UC_SIM_ID_UNCLASSIFIED;
    }
}

extern "C" mmi_ret vappUcSimStatusInfoHdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(evt);
/*
    if(g_app_ptr == NULL)
    {
        g_app_ptr = &g_app_cntx;
        memset(g_app_ptr, 0, sizeof(VappUcContainerStruct));
    }
*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED:
        {
            srv_uc_sim_id sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
            srv_sim_ctrl_availability_changed_evt_struct *sim_status = (srv_sim_ctrl_availability_changed_evt_struct*)evt;
            mmi_sim_enum sim = sim_status->sim;
            sim_id = vappUcConvertMmiSimIdToUc(sim);
            if(sim_id != SRV_UC_SIM_ID_UNCLASSIFIED)
            {
                g_app.valid_sim_id_info &= ~sim_id;
				srv_mode_switch_type_enum curr_mode = srv_mode_switch_get_current_mode();
                if(sim & curr_mode)
                {
                    if(srv_sim_ctrl_is_available(sim) ||
                        (srv_sim_ctrl_is_inserted(sim) && srv_sim_ctrl_chv1_is_blocked(sim)))
                    {
                        g_app.valid_sim_id_info |= sim_id;
                    }
					/*kuldeep_gplus*/
					if((srv_sim_ctrl_is_inserted(sim) && srv_sim_ctrl_chv1_is_blocked(sim)))
					{
						g_app.blocked_sim_info |= sim_id;
					}

                }

                if(vappUcConvertSwitchModeToUcSimId(curr_mode == sim_id))
                {
                    g_app.valid_sim_id_info &= sim_id;
                }
            }            

            break;
        }

        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
        {
			/*kuldeep_gplus*/
			srv_uc_sim_id sim_id = SRV_UC_SIM_ID_UNCLASSIFIED;
			U32 sim = 1;
			U32 max_sim_num = 1 ;
			srv_mode_switch_notify_struct *mode_status = (srv_mode_switch_notify_struct*)evt;
			U32 mode = (U32)mode_status->gsm_select_mode;
			g_app.is_flight_mode_enable = VFX_FALSE ;
			if(mode_status->select_flight_mode == SRV_MODE_SWITCH_ON)
			{
				g_app.is_flight_mode_enable = VFX_TRUE ;
			}

			while(max_sim_num <= MMI_MAX_SIM_NUM)
			{
				sim_id = vappUcConvertMmiSimIdToUc(sim);
				
				if(mode & sim)
				{
                    if(srv_sim_ctrl_is_available((mmi_sim_enum)sim) || (srv_sim_ctrl_is_inserted((mmi_sim_enum)sim) && 
                        srv_sim_ctrl_chv1_is_blocked((mmi_sim_enum)sim)))
					{
						g_app.valid_sim_id_info |= sim_id;
						g_app.closed_sim_info &= ~sim_id ;
					}
				}
				else if(srv_sim_ctrl_is_inserted((mmi_sim_enum)sim))
				{
					g_app.valid_sim_id_info |= sim_id;
					g_app.closed_sim_info |=sim_id ;
				}
				sim = sim << 1;
				max_sim_num++ ;
			}
	    }

        default:
            break;
    }
    return MMI_RET_OK;
}

extern "C" U32 vappUcGetValidSimInfo(void)
{
    return g_app.valid_sim_id_info;
}
extern "C" VfxBool vappUcFlightModecheck(void)
{
    if( srv_mode_switch_is_network_service_available() == MMI_TRUE )
    {
        return VFX_FALSE;
    }
    else

    {
        return VFX_TRUE;
    }
}
/*kuldeep_gplus*/
extern "C" U32 vappUcGetBlockedSimInfo(void)
{
    return g_app.blocked_sim_info;
}

extern "C" U32 vappUcGetClosedSimInfo(void)
{
    return g_app.closed_sim_info;
}

extern "C" U32 vappUcGetInvalidSimInfo(void)
{
	U32 result = g_app.closed_sim_info | g_app.blocked_sim_info;
    return result ;
}

extern "C" U32 vappUcGetValidSimToSend(void)
{
        if(SRV_UC_SIM_ID_GSM_SIM1 & g_app.valid_sim_id_info)
        {
            return SRV_UC_SIM_ID_GSM_SIM1;
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        else if(SRV_UC_SIM_ID_GSM_SIM2 & g_app.valid_sim_id_info)
        {
            return SRV_UC_SIM_ID_GSM_SIM2;        
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        else if(SRV_UC_SIM_ID_GSM_SIM3 & g_app.valid_sim_id_info)
        {
            return SRV_UC_SIM_ID_GSM_SIM3;        
        }
    #if (MMI_MAX_SIM_NUM >= 4)
        else if(SRV_UC_SIM_ID_GSM_SIM4 & g_app.valid_sim_id_info)
        {
            return SRV_UC_SIM_ID_GSM_SIM4;        
        }
    #endif
    #endif
    #endif
        else
        {
            return SRV_UC_SIM_ID_GSM_SIM1;
        }
}

extern "C" VfxBool vappUcGetSimNameString(srv_uc_sim_id sim, WCHAR* text_buffer)
{
//    VfxBool result = VFX_TRUE;
//	U16 temp_buffer[24] = {0,};

//    result = vapp_sim_settings_get_sim_name(vappUcConvertUCSimIdToMmi(sim), temp_buffer, 10);
    if(sim == SRV_UC_SIM_ID_GSM_SIM1)
    {
      mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_1));
    }
    else if (sim == SRV_UC_SIM_ID_GSM_SIM2)
    {
      mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_2));
    }
	else if (sim == SRV_UC_SIM_ID_GSM_SIM3)
	{
		mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_3));
	}
	else if (sim == SRV_UC_SIM_ID_GSM_SIM4)
	{
      mmi_ucs2cat((PS8) text_buffer, (PS8) GetString(STR_GLOBAL_SIM_4));		
	}
    if(!(vapp_sim_settings_get_sim_name(vappUcConvertUCSimIdToMmi(sim))).isEmpty())
    {
        mmi_ucs2cat((PS8) text_buffer, (PS8) L" ( ");
        mmi_ucs2cat((PS8) text_buffer, (PS8) ((vapp_sim_settings_get_sim_name(vappUcConvertUCSimIdToMmi(sim))).getBuf())); 
        mmi_ucs2cat((PS8) text_buffer, (PS8) L" )");
    }
    return VFX_TRUE;
}
/*kuldeep_gplus*/
extern "C" VfxS32 vappUcGetCurrValidSimCount(void)
{
    VfxS32 count = 0;

    if((g_app.valid_sim_id_info & ~(vappUcGetInvalidSimInfo())) & SRV_UC_SIM_ID_GSM_SIM1)
	{
		count++;
	}
    if((g_app.valid_sim_id_info & ~(vappUcGetInvalidSimInfo())) & SRV_UC_SIM_ID_GSM_SIM2)
	{
		count++;
	}
    if((g_app.valid_sim_id_info & ~(vappUcGetInvalidSimInfo())) & SRV_UC_SIM_ID_GSM_SIM3)
	{
		count++;
	}
    if((g_app.valid_sim_id_info & ~(vappUcGetInvalidSimInfo())) & SRV_UC_SIM_ID_GSM_SIM4)
	{
		count++;
	}
	return count;
}
extern "C" VfxS32 vappUcGetAllSimCount(void)
{
    VfxS32 count = 0;

    if(g_app.valid_sim_id_info  & SRV_UC_SIM_ID_GSM_SIM1)
	{
		count++;
	}
    if(g_app.valid_sim_id_info  & SRV_UC_SIM_ID_GSM_SIM2)
	{
		count++;
	}
    if(g_app.valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM3)
	{
		count++;
	}
    if(g_app.valid_sim_id_info  & SRV_UC_SIM_ID_GSM_SIM4)
	{
		count++;
	}
	return count;
}
extern "C" srv_uc_sim_id vappUcGetCurrSimId(void)
{
#if (MMI_MAX_SIM_NUM >= 2)
    srv_uc_sim_id settingSim = vappUcConvertMmiSimIdToUc((U32)srv_setting_get_primary_card());
    if((!g_app.valid_sim_id_info) || (g_app.valid_sim_id_info & settingSim))
    {
        return settingSim;
    }
#endif
    if(g_app.valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM1)
	{
		return SRV_UC_SIM_ID_GSM_SIM1;
	}
	else if(g_app.valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM2)
	{
		return SRV_UC_SIM_ID_GSM_SIM2;
	}
    else if(g_app.valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM3)
	{
		return SRV_UC_SIM_ID_GSM_SIM3;
	}
    else if(g_app.valid_sim_id_info & SRV_UC_SIM_ID_GSM_SIM4)
	{
		return SRV_UC_SIM_ID_GSM_SIM4;
	}
	return SRV_UC_SIM_ID_UNCLASSIFIED;
}

    
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
mmi_ret VappUcAppData::onSmsSaveStorageStatusEvtCb(mmi_event_struct *param)
{
    VappUcAppData *self = (VappUcAppData *)VfxObject::handleToObject((VfxObjHandle)param->user_data);
    
    
    MMI_PRINT(MOD_MMI_COMMON_APP, TRACE_GROUP_6, "[UC] onSmsSrvEvtCb");
    
    /* Need to check if it is NULL pointer. Otherwise, it may cause fatal error of NULL pointer access */
    if (NULL != self)
    {
        self->vappUcSmsSrvSaveStorageStatusData = self->vappUcSmsSrvSaveStorageStatus(param, VFX_FALSE);
    }
    return MMI_RET_OK;
}

vappUcSmsSrvSaveStorageStatusEnum VappUcAppData::vappUcSmsSrvSaveStorageStatus(mmi_event_struct *event_data, VfxBool isShowPopup)
{
    ASSERT(event_data);

    srv_sms_event_struct* sms_event = NULL;
    srv_sms_event_for_memory_status_struct* sms_state = NULL;
    U16 str_id = 0;
    vappUcSmsSrvSaveStorageStatusEnum ret_val = SMS_SRV_SAVE_STOR_STATUS_NONE;
    
    switch (event_data->evt_id)
    {
        case EVT_ID_SRV_SMS_SAVE_STORAGE_STATUS:
            sms_event = (srv_sms_event_struct*) event_data;
            sms_state =  (srv_sms_event_for_memory_status_struct*)sms_event->event_info;

            if(sms_state->save_to_type == sms_state->pref_storage_type ||
               sms_state->save_to_type == SRV_SMS_STORAGE_UNSPECIFIC ||
               sms_state->pref_storage_type == SRV_SMS_STORAGE_UNSPECIFIC)
                break;
                
            switch(sms_state->save_to_type)
            {
                case SRV_SMS_STORAGE_ME:
                    if(sms_state->pref_storage_type == SRV_SMS_STORAGE_TCARD &&
                       !sms_state->is_tcard_avail)
                    {
                        str_id = STR_ID_VAPP_UC_TCARD_NOT_PRESENT_USE_PHONE;
                        ret_val = SMS_SRV_SAVE_STOR_STATUS_TCARD_NOT_PRESENT_SAVE_TO_PHONE;
                    }
                    else if(sms_state->pref_storage_type == SRV_SMS_STORAGE_TCARD &&
                            sms_state->is_tcard_full)
                    {
                        str_id = STR_ID_VAPP_UC_TCARD_FULL_SAVE_TO_PHONE;
                         ret_val = SMS_SRV_SAVE_STOR_STATUS_TCARD_FULL_SAVE_TO_PHONE;
                    }
                    
                    break;
                case SRV_SMS_STORAGE_SIM:
                    break;
                case SRV_SMS_STORAGE_TCARD:
                    if(sms_state->pref_storage_type == SRV_SMS_STORAGE_ME &&
                       sms_state->is_phone_full)
                    {
                        str_id = STR_ID_VAPP_UC_PHONE_FULL_SAVE_TO_TCARD;
                        ret_val = SMS_SRV_SAVE_STOR_STATUS_PHONE_FULL_SAVE_TO_TCARD;
                    }    
                    
                    break;                
                case SRV_SMS_STORAGE_UNSPECIFIC:
                    break;
                default :
                    break;

            }
            
            break;
        default:
            break;
            
    }
    
    if (str_id && isShowPopup)
    {
        vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(str_id)), MMI_NMGR_BALLOON_TYPE_FAILURE);
    }     
    return ret_val;
}
#endif


VfxBool VappUcAppData::vappUcSmsSrvSaveStorageStatusShowPopup()
{
    VfxBool isShowPop = VFX_FALSE;

#ifdef    __SRV_SMS_TCARD_STORAGE_SUPPORT__
    U16 str_id = 0;

    switch(vappUcSmsSrvSaveStorageStatusData)
    {
        case SMS_SRV_SAVE_STOR_STATUS_TCARD_FULL_SAVE_TO_PHONE:
            str_id = STR_ID_VAPP_UC_TCARD_FULL_SAVE_TO_PHONE;
            break;
        case SMS_SRV_SAVE_STOR_STATUS_TCARD_NOT_PRESENT_SAVE_TO_PHONE:
            str_id = STR_ID_VAPP_UC_TCARD_NOT_PRESENT_USE_PHONE;
            break;
        case SMS_SRV_SAVE_STOR_STATUS_PHONE_FULL_SAVE_TO_TCARD:
            str_id = STR_ID_VAPP_UC_PHONE_FULL_SAVE_TO_TCARD;
            break;
        default:
            break;
    }
    vappUcSmsSrvSaveStorageStatusData = SMS_SRV_SAVE_STOR_STATUS_NONE;
        
    if (str_id)
    {
        vappUcDisplayPopup((WCHAR*)((UI_string_type) GetString(str_id)), MMI_NMGR_BALLOON_TYPE_FAILURE);
        isShowPop = VFX_TRUE;
    } 
#endif

    return isShowPop;
}

U32 VappUcAppData::vappUcGetMaxSubjectLength(void)
{
#ifdef __MMI_EMAIL__
    if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
        return MMI_EMAIL_MAX_SUBJ_LEN;
    }
    else
#endif
    return SRV_UC_MAX_SUBJECT_LEN;
}

U32 VappUcAppData::vappUcGetMaxRecipientCount(void)
{
#ifdef __MMI_EMAIL__
    if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
        return MMI_EMAIL_MAX_ADDR_NUM;
    }
    else
#endif
#ifdef __MMI_MMS_2__
    return SRV_UC_MAX_ADDRESS_NUM;
#else
        return 20;
#endif
}

U32 VappUcAppData::vappUcGetMaxAttachemntCount(void)
{
#ifdef __MMI_EMAIL__
    if (m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
    {
        return MMI_EMAIL_MAX_ATTACH_NUMBER;
    }
    else
#endif
#ifdef __MMI_MMS_2__
    return SRV_UC_MAX_ATTACHMENT_NUM;
#else
     return 1;
#endif
}


U32 VappUcAppData::vappUcGetMaxTextCharCount(void)
{
    return main->max_text_limit;
}


VfxBool VappUcAppData::ucRemoveRecipientByGroup(srv_uc_address_group_type_enum group)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_uc_addr_struct *addr = NULL;
    srv_uc_addr_struct *next_addr = NULL;
    addr = m_service_cntxt->msg->to_head;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(addr)
    {
		next_addr = addr->next;
		if (addr->group == group)
        {
            srv_uc_delete_addr(main->instance, addr);
        }
        addr = next_addr;
    }
    return VFX_TRUE;
}

#ifdef __MMI_EMAIL__
extern "C" void vappUcTerminateEmailApp(void)
{
    U32 i = 0;
    while(i < MAX_UC_INSTANCES)
    {
        if(g_app.app_data[i])
        {
            if(g_app.app_data[i]->m_service_cntxt->msg_type->MMS_edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
                VcuiUcMainCui* app = (VcuiUcMainCui *)g_app.app_data[i]->m_parent;
                app->vappUcTerminate();
            }
        }
        i++;
    }
}
#endif


extern "C" BOOL vappUcIsValidImage(U16 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    GDI_RESULT gdi_ret = GDI_FAILED;
    S32 width = 0, height = 0;

#ifdef __MMI_CAMCORDER__
    S32 width_max = 0, height_max = 0;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check image resolution */
    gdi_ret = gdi_image_get_dimension_file((S8 *) file_path, (S32*) & width, (S32*) & height);

#ifdef __MMI_CAMCORDER__
      vapp_camco_cam_get_max_capture_resolution(&width_max, &height_max);
    if (gdi_ret < 0 || width <= 0 || height <= 0 || width > width_max || height > height_max)
#else /* __MMI_CAMCORDER__ */ 
    if (gdi_ret < 0 || width <= 0 || height <= 0 || width > SRV_UC_MAX_IMAGE_WIDTH || height > SRV_UC_MAX_IMAGE_HEIGHT)
#endif /* __MMI_CAMCORDER__ */ 
    {
        VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_IS_VALID_IMG_NO_P1, gdi_ret);
        return MMI_FALSE;
    }
    VFX_LOG(VFX_FUNC3, TRC_VAPP_UC_IS_VALID_IMG_YES);
    return MMI_TRUE;
}

#ifdef __MMI_MMS_2__
#if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__) 
extern "C" U32 vappUcConvertUmmsResizeToUc(srv_umms_picture_size_enum size)
{
    U32 image_resize_limit;
    switch (size)
    {
        case E_PICTURE_RESIZE_10KB:
            image_resize_limit = 10*1024;
            break;
        case E_PICTURE_RESIZE_50KB:
            image_resize_limit = 50*1024;
            break;
        case E_PICTURE_RESIZE_100KB:
            image_resize_limit = 100*1024;
            break;
        case E_PICTURE_RESIZE_OFF:
            image_resize_limit = 0;
            break;
        default:
            image_resize_limit = 0;
    }
    return image_resize_limit;
}
#endif
#endif

extern "C" void vappUcDisplayPopup( WCHAR* title, mmi_nmgr_balloon_type_enum event_type)
{
    mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, event_type, (WCHAR*)title);
}

extern "C" WCHAR* vappUcGetMmaResultPopupStr(mma_result_enum result, mmi_nmgr_balloon_type_enum *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case MMA_RESULT_OK:
        {
            *type = MMI_NMGR_BALLOON_TYPE_SUCCESS;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_OK));
        }

        case MMA_RESULT_FAIL_UNSUPPORT_CONTENT:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_UNSUPPORT_CONTENT_ID));
        }

        case MMA_RESULT_FAIL_CREATION_MODE_MAX_MSG_SIZE_REACHED:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_CREATION_MODE_MAX_MSG_SIZE_REACHED_ID));
        }

        case MMA_RESULT_FAIL_MAX_SLIDE_NUM_REACHED:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MAX_SLIDE_NUM_REACHED_ID));
        }
#ifdef __MMI_MMS_TEMPLATE_SUPPORT__
        case MMA_RESULT_FAIL_USERDEF_TEMPLATE_FULL:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MAX_TEMPLATE_ALREADY_PRESENT_ID));
        }
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */
        case MMA_RESULT_FAIL_MAX_MSG_NUM_REACHED:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_TOO_MANY_MSG_ID));
        }

        case MMA_RESULT_FAIL_INSUFFICIENT_STORAGE:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY));
        }
        case MMA_RESULT_FAIL_INSUFFICIENT_MEMORY:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY));
        }

        case MMA_RESULT_FAIL_FILE_IO:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_STORAGE_FILE_IO_ERROR_ID));
        }

        case MMA_RESULT_FAIL_NOT_READY:
        case MMA_RESULT_FAIL_BUSY:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_AVAILABLE));
        }
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
        case MMA_RESULT_FAIL_MEM_CARD_NOT_PRESENT_INSERT_CARD:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_INSERT_CARD));
        }
#endif
        case MMA_RESULT_FAIL_ROOT_DIR_FULL:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(FS_ROOT_DIR_FULL)));
        }

        default:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_UNFINISHED));
        }
    }
}

#if defined(__MMI_MMS_SETTING_COMPOSE_PICTURE_RESIZING__) || defined(__MMI_UC_MMS_IMG_RESOLUTION__) 
extern "C" WCHAR* vappUcGetResizeResultPopupStr(S32 result, mmi_nmgr_balloon_type_enum *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case SRV_UC_RESIZING_SUCCEED:
        {
            MMI_ASSERT(0);
        }

        case SRV_UC_RESIZING_SUCCEED_WITH_UNCHANGED:
        {
            *type = MMI_NMGR_BALLOON_TYPE_INFO;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_RESIZE_IMAGE_UNCHANGED_ID));
        }

        case SRV_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_DISK_FULL:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY));
        }

        case SRV_UC_RESIZING_FAILED_IN_INSUFFICIENT_DRAWING_BUF:
        case SRV_UC_RESIZING_FAILED_IN_NO_QUOTA:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SYSTEM_RESOURCES_EXHAUSTED_ID));
        }

        case SRV_UC_RESIZING_FAILED_IN_UNKNOWN_DIMENSION:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FILE_CORRUPT_ID));
        }

        case SRV_UC_RESIZING_FAILED_IN_GDI_FAILED:
        case SRV_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_WRITE_PROTECTION:
        case SRV_UC_RESIZING_FAILED_IN_GDI_ENCODER_ERR_NO_DISK:
        default:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FAIL_TO_RESIZE_IMAGE_ID));
        }
    }
}
#endif

extern "C" WCHAR* vappUcGetSrvResultPopupStr(srv_uc_result result, mmi_nmgr_balloon_type_enum *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

//    int msg_size;
 //   PU8 str_msg_size_exceed, str_kb;
//    PU8 msg_with_max_size;
    //U32 len_max_size = 10;
//    U8 str_max_size[15], str_max_size_ucs[15 * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case SRV_UC_OK:
        {
            *type = MMI_NMGR_BALLOON_TYPE_SUCCESS;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_OK));
        }
    #ifdef __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__
        case SRV_UC_WAP_CONN_MAX_MSG_SIZE_REACHED:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_CONN_TYPE_MAX_SIZE_REACHED_ID));
        }
    #endif /* __MMI_UC_WAP_CONNECTION_MAX_SIZE_CHECK_SUPPORT__ */ 

        case SRV_UC_SIZE_EXCEEDS:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID));
        }
        case SRV_UC_CREATION_MODE_SIZE_EXCEEDS:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID));
        }
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        case SRV_UC_SIZE_NOT_ENOUGH_FOR_REC_VIDEO:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_SIZE_NOT_ENOUGH_FOR_REC_VIDEO_ID));
        }
#endif
        case SRV_UC_PROHIBIT_BY_CREATION_MODE:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_PROHIBIT_BY_CREATION_MODE_ID));
        }
        case SRV_UC_PROHIBIT_BY_DRM:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_DRM_PROHIBITED));
        }
            /* Because editor already play the error tone, therefore for no space case, app(UC) should not play tone again, fill tone ID =0 */
        case SRV_UC_NO_SPACE:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_NO_SPACE_ID));
        }
            /* This is called when UC itself calculates that the space is not enough, so editor doesn't play any tone */
        case SRV_UC_NO_SPACE_TONE:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_NO_SPACE_ID));
        }
        case SRV_UC_STORAGE_FULL:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_ENOUGH_MEMORY));
        }
        case SRV_UC_INSUFFICIENT_MEMORY:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_INSUFFICIENT_MEMORY));
        }
        case SRV_UC_XML_ERROR:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_CONTENT_ERROR_ID));
        }
        case SRV_UC_ERROR:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_UNFINISHED));
        }
        case SRV_UC_NOT_SUPPORT:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_NOT_SUPPORTED));
        }
        case SRV_UC_FILE_CORRUPT:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FAILED_TO_ADD_MEDIA_ID));
        }

        case SRV_UC_FILE_EMPTY:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_FILE_EMPTY_ID));
        }
        case SRV_UC_FILE_NOT_FOUND:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_FILE_NOT_FOUND));
        }
        case SRV_UC_FOLDER_NOT_FOUND:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(srv_fmgr_fs_error_get_string(FS_PATH_NOT_FOUND)));
        }
        case SRV_UC_FAIL_IN_VIDEO_CALL:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL));
        }
        case SRV_UC_FAIL_IMAGE_TOO_LARGE:
        {
            *type = MMI_NMGR_BALLOON_TYPE_FAILURE;
            return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_IMAGE_TOO_LARGE));
        }

        default:
        {
            MMI_ASSERT(0);
        }
    }
    // Just to avoid warning. Additional line only.
    return (WCHAR*)((UI_string_type) GetString(STR_ID_VAPP_UC_IMAGE_TOO_LARGE));
}

extern "C" srv_um_msg_box_enum vappUcConvertMmaBoxToUm(mma_folder_enum msg_box)
{
	switch(msg_box)
	{
		case MMA_FOLDER_NONE:
			return SRV_UM_MSG_BOX_NONE;
		case MMA_FOLDER_INBOX:
			return SRV_UM_MSG_BOX_INBOX;
		case MMA_FOLDER_OUTBOX:
			return SRV_UM_MSG_BOX_UNSENT;
		case MMA_FOLDER_SENT:
			return SRV_UM_MSG_BOX_SENT;
		case MMA_FOLDER_DRAFT:
			return SRV_UM_MSG_BOX_DRAFT;
		case MMA_FOLDER_TEMPLATE:
			return SRV_UM_MSG_BOX_PREDEF_TEMPLATES;
		case MMA_FOLDER_USRDEF_TEMPLATE:
			return SRV_UM_MSG_BOX_USRDEF_TEMPLATES;
		case MMA_FOLDER_ARCHIVE:
			return SRV_UM_MSG_BOX_ARCHIVE;
		default:
			return SRV_UM_MSG_BOX_DRAFT;
	}
}

extern "C" srv_um_msg_box_enum vappUcConvertSmsBoxToUm(srv_sms_box_enum msg_box)
{
	switch(msg_box)
	{
		case SRV_SMS_BOX_NONE:
			return SRV_UM_MSG_BOX_NONE;
		case SRV_SMS_BOX_INBOX:
			return SRV_UM_MSG_BOX_INBOX;
		case SRV_SMS_BOX_OUTBOX:
            return SRV_UM_MSG_BOX_SENT;
		case SRV_SMS_BOX_DRAFTS:
			return SRV_UM_MSG_BOX_DRAFT;
        case SRV_SMS_BOX_UNSENT:
			return SRV_UM_MSG_BOX_UNSENT;
        case SRV_SMS_BOX_SIM:
            return SRV_UM_MSG_BOX_SIM;
		case SRV_SMS_BOX_ARCHIVE:
			return SRV_UM_MSG_BOX_ARCHIVE;
		default:
			return SRV_UM_MSG_BOX_DRAFT;
	}
}

srv_um_msg_box_enum VappUcAppData::vappUcGetMsgBox(U32 msg_id)
{
    if (m_service_cntxt->main->state == SRV_UC_STATE_WRITE_NEW_MSG)
    {
        return SRV_UM_MSG_BOX_NONE;
    }
    else if (m_service_cntxt->send_info->existed_msg_type == SRV_UC_MSG_TYPE_SMS_PREFER)
    {
        srv_sms_box_enum msg_box_type;
        srv_sms_get_msg_list_index(&msg_box_type, (U16)msg_id);
        return vappUcConvertSmsBoxToUm(msg_box_type);
    }
    else
#ifdef __MMI_MMS_2__
    {
        return vappUcConvertMmaBoxToUm(mma_get_box(msg_id));
    }
#else
    {
            return SRV_UM_MSG_BOX_NONE;
    }
#endif
}


extern "C" VfxBool vappUcCheckAppSanity(void *ptr)
{
    if(ptr)
    {
        U32 i = 0;
        while(i < MAX_UC_INSTANCES)
        {
            if(g_app.app_data[i] == (VappUcAppData *)ptr)
            {
                return VFX_TRUE;
            }
            i++;
        }
    }
    return VFX_FALSE;
}

#ifdef __MMI_COSMOS_UC_END_KEY_SAVE_SUPPORT__
extern "C" U8 vappUcCheckInstanceByAppPtr(void *ptr)
{
    U32 i = 0;
	if(ptr)
    {
        while(i < MAX_UC_INSTANCES)
        {
            if(EndKeyHandle[i].EndKeyAppData == (VappUcAppData *)ptr)
            {
                return i ;
            }
            i++;
        }
    }
    return i ;
}

extern "C" VfxBool VappUCneedTofreeService(U8 instance)
{
	return EndKeyHandle[instance].NeedToFreeService ;
}

extern "C" void VappUCFreeEndKeyHandleData(U8 instance)
{
	EndKeyHandle[instance].EndKeyAppData = NULL ;
	EndKeyHandle[instance].NeedToFreeService = VFX_FALSE ;
}

#endif
extern "C" void vappUcCopyInitData(VappUcEntryStruct *data)
{
    vappUcResetInitData();
    
    if(data)
    {
        VappUcEntryStruct *cpyData = NULL;
        VFX_SYS_ALLOC_MEM(cpyData, sizeof(VappUcEntryStruct));
        memset(cpyData, 0, sizeof(VappUcEntryStruct));
        cpyData->addr_num = data->addr_num;
        cpyData->media_num = data->media_num;

        if(data->addr)
        {
            srv_uc_addr_struct *currAddr = data->addr;
            srv_uc_addr_struct *cpyAddr = NULL, *tempPtr = NULL;
            U8 firstNode = 1;
            while(currAddr)
            {
                U16 len = mmi_ucs2strlen((S8*) currAddr->addr);
                VFX_SYS_ALLOC_MEM(cpyAddr, sizeof(srv_uc_addr_struct));
                memset(cpyAddr, 0, sizeof(srv_uc_addr_struct));
                if(firstNode)
                {
                    cpyData->addr = cpyAddr;
                    tempPtr = cpyAddr;
                }

                VFX_SYS_ALLOC_MEM(cpyAddr->addr, ((len + 1) * ENCODING_LENGTH));
                MMI_ASSERT(cpyAddr->addr);
                memset(cpyAddr->addr, 0, ((len + 1) * ENCODING_LENGTH));
                memcpy(cpyAddr->addr, currAddr->addr, (len * ENCODING_LENGTH));

                cpyAddr->type = currAddr->type;
                cpyAddr->group = currAddr->group;
                currAddr = currAddr->next;
                if(firstNode)
                {
                    firstNode = 0;
                }
                else
                {
                    tempPtr->next = cpyAddr;
                    cpyAddr->previous = tempPtr;
                    tempPtr = tempPtr->next;
                }
            }
        }

        cpyData->msg_type = data->msg_type;

        if (data->file_path)
        {
            U32 file_path_len = mmi_ucs2strlen((S8*) data->file_path);

            VFX_SYS_ALLOC_MEM(cpyData->file_path, (file_path_len + 1) * ENCODING_LENGTH);
            ASSERT(cpyData->file_path);
            memset(cpyData->file_path, 0, (file_path_len + 1) * ENCODING_LENGTH);
            mmi_ucs2ncpy((S8*) cpyData->file_path, (S8*) data->file_path, file_path_len);
            cpyData->auto_delete_file = data->auto_delete_file;
        }

        if (data->text_num)
        {
            U32 buffer_size = 0;
            U8 *buffer = NULL;
            U32 buffer_len = 0;

            /* Discard the exceeding part */
            if (data->text_num > SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE)
            {
                data->text_num = SRV_UC_MAX_CHAR_NUM_IN_ONE_SLIDE;
            }
            if (data->msg_type == SRV_UC_MSG_TYPE_SMS_ONLY && data->text_num > UC_MAX_SMS_CONTENT)
            {
                data->text_num = UC_MAX_SMS_CONTENT;
            }

            buffer_size = (data->text_num + 1) * ENCODING_LENGTH;
        #ifdef __MMI_EMAIL__
            if (data && data->edit_mode == SRV_UC_MMS_EDIT_MODE_EMAIL)
            {
                buffer = data->text_buffer;
                buffer_len = mmi_ucs2strlen((S8*) buffer);
            }
            else
        #endif
            {
                VFX_SYS_ALLOC_MEM(buffer, buffer_size);

                ASSERT(buffer_size <= SRV_UC_UTF8_TEXT_BUFFER_SIZE);

                memset(buffer, 0, buffer_size);
                srv_sms_remove_escape_char(
                    (S8*) buffer,
                    (S8*) data->text_buffer,
                    (U16) data->text_num);
                buffer_len = mmi_ucs2strlen((S8*) buffer);
            }

            if (buffer_len <= (SRV_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH) - 1)
            {
                VFX_SYS_ALLOC_MEM(cpyData->text_buffer, (buffer_len + 1) * ENCODING_LENGTH);
                memset(cpyData->text_buffer, 0, (buffer_len + 1) * ENCODING_LENGTH);
                mmi_ucs2ncpy((S8*) cpyData->text_buffer, (S8*) buffer, buffer_len);
            }
            else
            {
                VFX_SYS_ALLOC_MEM(cpyData->text_buffer, SRV_UC_TEXT_BUFFER_SIZE);
                memset(cpyData->text_buffer, 0, SRV_UC_TEXT_BUFFER_SIZE);
                mmi_ucs2ncpy((S8*) cpyData->text_buffer, (S8*) buffer, (SRV_UC_TEXT_BUFFER_SIZE / ENCODING_LENGTH) - 1);
            }
        #ifdef __MMI_EMAIL__
            if (data && data->edit_mode != SRV_UC_MMS_EDIT_MODE_EMAIL)
        #endif
            {
                VFX_SYS_FREE_MEM(buffer);
            }
        }
        cpyData->text_num = data->text_num;

        if(data->subject)
        {
            U32 len = mmi_ucs2strlen((S8*) data->subject);

            VFX_SYS_ALLOC_MEM(cpyData->subject, ((len + 1) * ENCODING_LENGTH));
            MMI_ASSERT(cpyData->subject);
            memset(cpyData->subject, 0, ((len + 1) * ENCODING_LENGTH));
            mmi_ucs2ncpy((S8*) cpyData->subject, (S8*) data->subject, len);
        }

        cpyData->info_type = data->info_type;
        cpyData->info = data->info;
        cpyData->callback = data->callback;
        cpyData->callback_para = data->callback_para;
        cpyData->sim_id = data->sim_id;
        cpyData->get_address_callback = data->get_address_callback;
        cpyData->get_media_callback = data->get_media_callback;
        cpyData->app_id = data->app_id;
        cpyData->mode = data->mode;
        cpyData->msg_id = data->msg_id;
        cpyData->edit_mode = data->edit_mode;
        cpyData->curr_storage = data->curr_storage;
        cpyData->type = data->type;
        cpyData->operation = data->operation;
		cpyData->launch_mode = data->launch_mode;
		initial_launch_mode = data->launch_mode;

        g_app.initData = cpyData;
    }
}

void VcuiUcMainCui::vappUcDeInitData(void)
{
    if(g_app.initData)
    {
       // vappUcSendEvtToCaller(EVT_ID_UC_DATA_COLLECTION_CALLBACK_FINISH);
        if(temp_flag)
	    {
		    mmi_event_struct evt;
		    memset(&evt, 0, sizeof(mmi_event_struct));
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_UC_DATA_COLLECTION_CB_FINISH_NOTIFY);
		    evt.evt_id = EVT_ID_UC_DATA_COLLECTION_CB_FINISH_NOTIFY;
		    evt.user_data = g_app.initData->callback_para;
		    MMI_FRM_CB_EMIT_POST_EVENT(&evt);
            vappUcResetInitData();
	    }
        return;
    }
    else
    {
        return;
    }
}

extern "C" void vappUcResetInitData(void)
{
    VappUcEntryStruct *data = NULL;

    if(g_app.initData)
    {
        data = g_app.initData;
        if(data->addr)
        {
            srv_uc_addr_struct *currAddr = data->addr;
            srv_uc_addr_struct *tempPtr = currAddr->next;
            while(tempPtr)
            {
                VFX_SYS_FREE_MEM(currAddr->addr);
                VFX_SYS_FREE_MEM(currAddr);
                currAddr = tempPtr;
                tempPtr = tempPtr->next;
            }
            VFX_SYS_FREE_MEM(currAddr->addr);
            VFX_SYS_FREE_MEM(currAddr);
        }
        if (data->file_path)
        {
            VFX_SYS_FREE_MEM(data->file_path);
        }
        if(data->text_buffer)
        {
            VFX_SYS_FREE_MEM(data->text_buffer);
        }
        if(data->subject)
        {
            VFX_SYS_FREE_MEM(data->subject);
        }

        VFX_SYS_FREE_MEM(g_app.initData);
        g_app.initData = NULL;
    }

    return;
}

/*****************************************************************************
 * FUNCTION
 *  vapp_uc_get_sms_address_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  type        [IN]        
 * RETURNS
 *  number pointer
 *****************************************************************************/
extern "C" srv_uc_addr_struct *vapp_uc_get_sms_address_callback(U16 index, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappUcAppData *app = (VappUcAppData*)g_app.curr_app;
    srv_uc_addr_struct* addr = NULL;
	WCHAR*ucs2_addr = NULL;
	srv_sms_status_enum status;
    srv_uc_addr_struct *addr_top_node = app->otherAppTempUcInfo->addr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //   ASSERT(index < member_count);
 //   addr= srv_uc_get_addr( app->main->instance, index);
  //  *type = MMI_PHB_ADDRESS_TYPE_EMAIL;
			VFX_SYS_ALLOC_MEM(ucs2_addr, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
			memset(ucs2_addr, 0, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
			VFX_SYS_ALLOC_MEM(addr, sizeof(srv_uc_addr_struct));
			memset(addr, 0, sizeof(srv_uc_addr_struct));
			srv_sms_get_msg_multi_addr( ucs2_addr,
                &status,
                app->m_service_cntxt->send_info->existed_msg_id,
                index);
			addr->addr = (kal_uint8 *) ucs2_addr;
			if (mmi_ucs2strlen((PS8)addr->addr) > 0)
			{
				if (mmi_ucs2chr((PS8)addr->addr, L'@') == NULL)
				{
					addr->type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
				}
				else
				{
					addr->type = SRV_UC_ADDRESS_TYPE_EMAIL;
				}
				addr->group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
				if(app->otherAppTempUcInfo->addr == NULL)
				{
					app->otherAppTempUcInfo->addr = addr;
				}
				else
				{
					while (addr_top_node->next)
					{
						addr_top_node = addr_top_node->next;
					}
					addr_top_node->next = addr;
				}
			}
    return addr;
}

VfxBool vapp_uc_is_ascii_string(const S8 *ucs2_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 utf8_str[(SRV_UC_MAX_EMAIL_LEN + 2) * 3] = {0,};
	S32 utf8_buffer_size = (SRV_UC_MAX_EMAIL_LEN + 2) * 3;
	U8* number = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_chset_ucs2_to_utf8_string(utf8_str, utf8_buffer_size, (U8*)ucs2_str);
	number = utf8_str;
    /* If this is an ASCII string, each octet should be an ASCII character. */
    for (; *number != '\0'; ++number)
    {
        if (*number > 0x7F)
        {
            return VFX_FALSE;
        }
    }
    return VFX_TRUE;
}

VfxBool VappUcAppData::recipientCheckMsgSize(VfxWChar* buff)
{
#ifdef __MMI_MMS_2__
		if (m_service_cntxt->msg_type->curr_msg_type == SRV_UC_MSG_TYPE_MMS_PREFER)
        {
            /* Check if the msg size exceeds the MMS limitation */
            VfxU32 addr_size = mma_uc_calc_header_attribute_size(MMA_HEADER_ADDRESS, (const kal_wchar*)buff);
            MMI_BOOL fail_in_restricted_size_check = MMI_FALSE;

            if (srv_uc_check_if_exceed_MMS_size_limitation
                (main->instance, addr_size + m_service_cntxt->msg->msg_size, &fail_in_restricted_size_check))
            {
                if (fail_in_restricted_size_check)
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, 
							(WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_RESTRICTED_MODE_MSG_SIZE_EXCEED_ID).getBuf());
					 return VFX_FALSE;
				}
				else
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, 
							(WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_UC_MSG_SIZE_EXCEED_ID).getBuf());
					 return VFX_FALSE;
				}
            }
		}
#endif
		return VFX_TRUE;
}

#ifndef MMS_SUPPORT

#include "FileMgrSrvGProt.h"
#include "FileMgrType.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"

#include "drm_def.h"
#include "drm_gprot.h"



#define IS_EMAIL(x) (strchr(x, '@') != NULL)
/* Refer to Sls_if.c */
#define SLS_SMIL_START      "<smil>\n"
#define SLS_SMIL_END        "</smil>\n"
#define SLS_HEAD_START      "<head>\n"
#define SLS_HEAD_END        "</head>\n"
#define SLS_BODY_START      "<body>\n"
#define SLS_BODY_END        "</body>\n"
#define SLS_PAR_START       "<par dur=\"%dms\">\n"
#define SLS_PAR_END         "</par>\n"

#define SLS_TEXT_T1         "<text src=\"%s\" region=\"%s\" "
#define SLS_TEXT_T2         "begin=\"%lums\" "
#define SLS_TEXT_T3         "end=\"%lums\" "
#define SLS_TEXT_T4         "dur=\"%lums\" "
#define SLS_TEXT_T5         "<param name=\"foreground-color\" value=\"%s\" />\n"
#define SLS_TEXT_T6         "/>\n"
#define SLS_TEXT_T7         ">\n"
#define SLS_TEXT_T8         "<param name=\"textsize\" value=\"%s\" />\n"
#define SLS_TEXT_T9         "</text>\n"
#define SLS_IMAGE_T1        "<img src=\"%s\" region=\"%s\" "
#define SLS_IMAGE_T2         "begin=\"%lums\" "
#define SLS_IMAGE_T3         "end=\"%lums\" "
#define SLS_IMAGE_T4         "dur=\"%lums\" "
#define SLS_IMAGE_T5        "/>\n"
#define SLS_VIDEO_T1        "<video src=\"%s\" region=\"%s\" "
#define SLS_VIDEO_T2        "begin=\"%lums\" "
#define SLS_VIDEO_T3        "end=\"%lums\" "
#define SLS_VIDEO_T4        "dur=\"%lums\" "
#define SLS_VIDEO_T5        "/>\n"
#define SLS_AUDIO_T1         "<audio src=\"%s\" "
#define SLS_AUDIO_T2         "begin=\"%lums\" "
#define SLS_AUDIO_T3         "end=\"%lums\" "
#define SLS_AUDIO_T4         "dur=\"%lums\" "
#define SLS_AUDIO_T5        "/>\n"
#define SLS_REF_T1         "<ref src=\"%s\" "
#define SLS_REF_T2         "begin=\"%lums\" "
#define SLS_REF_T3         "end=\"%lums\" "
#define SLS_REF_T4         "dur=\"%lums\" "
#define SLS_REF_T5        "/>\n"
#define SLS_LAYOUT_START    "<layout>\n"
#define SLS_LAYOUT_END      "</layout>\n"
#define SLS_ROOT_LAYOUT_T1  "<root-layout width=\""
#define SLS_ROOT_LAYOUT_T2  "\" height=\""
#define SLS_ROOT_LAYOUT_T3  "\" background-color=\""
#define SLS_ROOT_LAYOUT_T4  "\"/>\n"
#define SLS_REGION_T1       "<region id=\""
#define SLS_REGION_T2       "\" width=\""
#define SLS_REGION_T3       "\" height=\""
#define SLS_REGION_T4       "\" left=\""
#define SLS_REGION_T5       "\" top=\""
#define SLS_REGION_T6       "\" fit=\""
#define SLS_REGION_T7       "\" />\n"

#define SLS_FIT_FILL   "fill"
#define SLS_FIT_HIDDEN "hidden"
#define SLS_FIT_MEET   "meet"
#define SLS_FIT_SCROLL "scroll"
#define SLS_FIT_SLICE  "slice"

#define SLS_INTSZ           (S32)12
#define SLS_UINTSZ          (U32)SLS_INTSZ
#define COLOR_RGB_STR       "#RRGGBB"

#define MMA_COLOR_NOT_USED      (0xFF000000)

extern kal_mutexid mma_ctrl_mutex;
const unsigned char mma_charset_utf8_bytes_per_character[16] = {
  1, 1, 1, 1, 1, 1, 1, 1,
  0, 0, 0, 0, 2, 2, 3, 4};
const U32 mma_charset_offsets_from_utf8[5] =  {
  0UL, 0UL, 0x00003080UL, 0x000e2080UL, 0x03c82080UL};

void mma_uc_insert_object_check(mma_insert_info_struct *insert_info,
        mma_insert_check_struct *info)
{
    info->result = KAL_TRUE;
    info->detail_result = MMA_RESULT_OK;
    info->drm_type = MMA_DRM_NONE;
    insert_info->insert_type = MMA_INSERT_ATTACHMENT;
	info->insert_type = MMA_INSERT_ATTACHMENT;
    info->oversize = KAL_FALSE;
    info->creation_mode_violate = KAL_FALSE;
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mma_unicode_to_utf8_len
 * DESCRIPTION
 *  Get UTF8 string len from UCS2 string.
 * PARAMETERS
 *  ucs2        [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 mma_um_unicode_to_utf8_len(kal_wchar *ucs2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar temp;
    kal_int32 length = 0;
    kal_wchar *str = ucs2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	temp = *str;
    while (temp != NULL)
    {
        temp = *str;
        if (temp < (kal_wchar) 0x80)
            length += 1;
        else if (temp < (kal_wchar) 0x800)
            length += 2;
        else
            length += 3;
        str++;
    }
    return length;
}

static int
mma_charset_ucs2any_to_utf8 (const char *src, long *src_len,
                             char *dst, long *dst_len,
                             int big_endian)
{
  U32 w;
  int        sidx = 0, didx = 0;
  int        sn, dn;
  U8  mask;
  int        i0, i1;

  if (big_endian) {
    i0 = 0; i1 = 1; 
  }
  else {
    i0 = 1; i1 = 0; 
  }

  for (;;) {
    /* First, translate to UCS4 */
    if (sidx + 2 > *src_len)
      break;
    w = ((unsigned char)src[sidx + i0] << 8) |
      (unsigned char)src[sidx + i1];
    sn = 2;

    /* Determine how many UTF8-bytes are needed for this character,
     * and which bits should be set in the first byte. */
    if (w < 0x80) {
      dn = 1;
      mask = 0;
    }
    else if (w < 0x800) {
      dn = 2;
      mask = 0xc0;
    }
    else {
      dn = 3;
      mask = 0xe0;
    }

    /* Is there room for this in the destination vector? */
    if (didx + dn > *dst_len)
      break;

    /* Only write to destination vector if dst != NULL */
    if (dst != NULL) {
      switch (dn) {
      case 3:
        dst[didx + 2] = (char) ((w & 0x3f) | 0x80);
        w >>= 6;
      case 2:
        dst[didx + 1] = (char) ((w & 0x3f) | 0x80);
        w >>= 6;
      case 1:
        dst[didx] = (char) (w | mask);
      }
    }

    sidx += sn;
    didx += dn;
  }
  *src_len = sidx;
  *dst_len = didx;

  return 0;
}

static int
mma_charset_utf8_to_ucs2any (const char *src, long *src_len,
                              char *dst, long *dst_len,
                              int big_endian)
{
  int        sidx = 0, didx = 0;
  int        sn, dn;
  U32 w;
  int        i0, i1;

  if (big_endian) {
    i0 = 0; i1 = 1;
  }
  else {
    i0 = 1; i1 = 0;
  }

  while (sidx < *src_len) {
    /* Read one Unicode character in UTF-8 format: */
    sn = mma_charset_utf8_bytes_per_character[(unsigned char)*src >> 4];
    if (sidx + sn > *src_len)
      break;

    w = 0;
    switch (sn) {
    case 0:
      return -1;

    case 4: w += (unsigned char)*src++; w <<= 6;
    case 3: w += (unsigned char)*src++; w <<= 6;
    case 2: w += (unsigned char)*src++; w <<= 6;
    case 1: w += (unsigned char)*src++;
    }
    w -= mma_charset_offsets_from_utf8[sn];

    /* Write one Unicode character in UCS-2 format: */
    w &= 0xffff;
    if (didx + 2 > *dst_len)
      break;
    if (dst != NULL) {
      dst[didx + i0] = (char)((w >> 8) & 0xff);
      dst[didx + i1] = (char)((w & 0xff));
    }
    dn = 2;
    sidx += sn;
    didx += dn;
  }
  *src_len = sidx;
  *dst_len = didx;

  return 0;
}


/*****************************************************************************
 * FUNCTION
 *  mma_um_ucs2_to_utf8_string
 * DESCRIPTION
 *  Get UTF8 string from UCS2 string, caller should release the returned UTF8 string
 * PARAMETERS
 *  ucs2_str        [IN]        
 * RETURNS
 *  UTF8 string
 *****************************************************************************/
char *mma_um_ucs2_to_utf8_string(const kal_wchar *ucs2_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *utf8_str = NULL;
    long src_len = (long)app_ucs2_strlen((kal_int8*) ucs2_str) * ENCODING_LENGTH;
    long dst_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dst_len = (long)mma_um_unicode_to_utf8_len((kal_wchar*) ucs2_str);
    if (src_len > 0)
    {
        utf8_str = (char*)OslMalloc(dst_len + 1);
        memset(utf8_str, 0, dst_len + 1);
        mma_charset_ucs2any_to_utf8((const char*)ucs2_str, &src_len, utf8_str, &dst_len, FALSE);
    }
    return utf8_str;
}


/*****************************************************************************
 * FUNCTION
 *  mma_um_charset_utf8_to_ucs2le
 * DESCRIPTION
 *  Get UCS2 string from UTF8 string, caller should release the returned UCS2 string
 * PARAMETERS
 *  ucs2_str        [IN]        
 * RETURNS
 *  UTF8 string
 *****************************************************************************/
kal_uint8* mma_um_charset_utf8_to_ucs2le ( const char *src_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *dest_buffer = NULL;
    long dest_len = 0, src_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    src_len = strlen(src_str);
    src_len++;

    dest_len = src_len * ENCODING_LENGTH;

    dest_buffer = (char*)OslMalloc(dest_len);
    memset(dest_buffer, 0, dest_len);
    if (dest_buffer)
    {
		mma_charset_utf8_to_ucs2any(src_str, &src_len, dest_buffer, &dest_len, FALSE);
    }
    
    return (kal_uint8 *)dest_buffer;
}

kal_uint32 mma_get_mmi_file_size(FS_HANDLE file_handle, const kal_wchar *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 fh;
    kal_uint32 size = 0;
	/* we should not used DRM api to get size as discussed with Eric the DRM Owner.*/
	/* DRM Api not return proper size. In FS use no use of file_handle. As its DRM file_handle.*/
	kal_bool need_fs_api_to_get_size = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//if(need_fs_api_to_get_size)
	{
		fh = FS_Open((kal_wchar *)filepath, FS_READ_ONLY | FS_OPEN_SHARED);
    
		if(fh >= 0)
		{
			FS_GetFileSize(fh, &size);
			FS_Close(fh);
		}
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
#endif
    return size;
}

const char *mma_get_name_from_path(char *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *c = strrchr(path, '\\');
    char *c1 = strrchr(path, '/');

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (c == NULL && c1 == NULL)
    {
        return path;
    }
    else
    {
        c = (c1 > c) ? c1 : c;  /* find the last / or \ */
    }

    /* Skip past "\" */
    return (++c);
}

kal_uint8 mma_get_uintvar_length_bytes(kal_uint32 n)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (n < 0x80)
    {
        return 1;
    }
    else if (n < 0x4000)
    {
        return 2;
    }
    else if (n < 0x200000)
    {
        return 3;
    }
    else if (n < 0x10000000)
    {
        return 4;
    }
    else
    {
        return 5;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_multipart_size
 * DESCRIPTION
 *  Calculate multipart size including
 *  - header:
 *  + HeadersLen, Headers: mma_uc_calc_object_multipart_header_size()
 *  + DataLen
 *  - body:
 * PARAMETERS
 *  filepath        [IN]        UCS2 encoding
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 mma_uc_calc_object_multipart_size(const kal_wchar *filepath)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0, filesize = mma_get_mmi_file_size(-1, filepath);

#ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
    char *utf8_filepath = NULL;
    const char *utf8_filename = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* DataLen */
    size += mma_get_uintvar_length_bytes(filesize);

    utf8_filepath = mma_um_ucs2_to_utf8_string(filepath);
    utf8_filename = mma_get_name_from_path(utf8_filepath);

    /* HeadersLen, Headers */
   // size += mma_uc_calc_object_multipart_header_size(utf8_filename, KAL_FALSE);
    if(utf8_filepath)
    {
        OslMfree(utf8_filepath);
    }
#endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
    /* body */
    size += filesize;

    return size;
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_object_smil_size_precise
 * DESCRIPTION
 *  This function is to calculate object SMIL description size, including being, end attributes
 *  ("alt" still not supported)
 * CALLS
 *  
 * PARAMETERS
 *  type            [IN]        
 *  filepath        [IN]        
 *  obj             [IN]         
 *  dur             [IN]        
 * RETURNS
 *  smil description size
 *****************************************************************************/
kal_uint32 mma_uc_calc_object_smil_size_precise(
            mma_insert_type_enum type,
            const kal_wchar *filepath,
            void *obj,
            kal_uint32 dur)

{
	
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size = 0, buffer_len = 0;
    char *utf8_filepath = NULL, *buffer = NULL, *tmp = NULL;
    const char *utf8_filename = NULL, *t_region_name = NULL, *i_region_name = NULL;
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
    kal_bool is_ascii_name = FALSE;
    char *temp_file_name = NULL;
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MMS_COSMOS_VIDEO_SLIM__
    if (type == MMA_INSERT_VIDEO)
	{
		type = MMA_INSERT_ATTACHMENT;
	}
#endif
    if (type != MMA_INSERT_ATTACHMENT)
    {
        utf8_filepath = mma_um_ucs2_to_utf8_string(filepath);
        utf8_filename = mma_get_name_from_path(utf8_filepath);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT

        is_ascii_name = mma_is_ascii_string(utf8_filename);
        //If non_ascii name change to ascii name "XX.ext"
        if(!is_ascii_name)
        {
            mma_uc_get_ascii_name(utf8_filename, &temp_file_name);
        }
        else
        {
            temp_file_name = (char*)utf8_filename;
        }
#endif
        t_region_name = MMA_CFG_TEXT_REGION_NAME;
        i_region_name = MMA_CFG_IMAGE_REGION_NAME;
    }

    switch (type)
    {
        case MMA_INSERT_TEXT:
        {
            char str[8];
            mma_mms_slide_text_object_struct *text = (mma_mms_slide_text_object_struct*) obj;

#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            buffer_len = sizeof(SLS_TEXT_T1) + sizeof(SLS_TEXT_T2) + sizeof(SLS_TEXT_T3) + sizeof(SLS_TEXT_T4) +
                sizeof(SLS_TEXT_T5) + sizeof(SLS_TEXT_T8) + sizeof(SLS_TEXT_T9) + strlen(temp_file_name) +
                strlen(t_region_name) + strlen(COLOR_RGB_STR) + 3 * SLS_INTSZ + 1;
#else
            buffer_len = sizeof(SLS_TEXT_T1) + sizeof(SLS_TEXT_T2) + sizeof(SLS_TEXT_T3) + sizeof(SLS_TEXT_T4) +
                sizeof(SLS_TEXT_T5) + sizeof(SLS_TEXT_T8) + sizeof(SLS_TEXT_T9) + strlen(utf8_filename) +
                strlen(t_region_name) + strlen(COLOR_RGB_STR) + 3 * SLS_INTSZ + 1;

#endif
            tmp = (char*)OslMalloc(buffer_len);
            memset(tmp, 0, buffer_len);
            buffer = (char*)OslMalloc(buffer_len);
            memset(buffer, 0, buffer_len);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            sprintf(tmp, SLS_TEXT_T1, temp_file_name, t_region_name);    /* <text src="??.??" region="Text" */
#else
            sprintf(tmp, SLS_TEXT_T1, utf8_filename, t_region_name);    /* <text src="??.??" region="Text" */
#endif
            strcpy(buffer, tmp);

            if (text)
            {
                /* begin, end */
                if (text->begin == 0 && text->end == dur)   /* same with slide time setting */
                {
                }
                else
                {
                    /* Sync with copyTimingAttrs() in Sls_if.c */
                    if (text->begin != SRV_UC_INVALID_VALUE && text->begin != 0)
                    {
                        sprintf(tmp, SLS_TEXT_T2, (unsigned long)text->begin * MMA_1_SEC_IN_MSEC);      /* begin="??ms" */
                        strcat(buffer, tmp);
                    }
                    if (text->end != SRV_UC_INVALID_VALUE && text->end != 0)
                    {
                        sprintf(tmp, SLS_TEXT_T3, (unsigned long)text->end * MMA_1_SEC_IN_MSEC);        /* end="??ms" */
                        strcat(buffer, tmp);
                    }
                }

                /* "alt" not suppported now */
            }

            /* Check if the color or text size parameter needs to be set */
            if (text == NULL || (SLS_COLOR_NOT_USED | text->fg_color) == SLS_COLOR_NOT_USED
                                                                        /* && SLS_TEXT_SIZE_DEFAULT == list->text.textSize */ )
                                                                        /* UC doesn't support text size setting */
            {
                strcat(buffer, SLS_TEXT_T6);    /* /> */
            }
            else
            {
                strcat(buffer, SLS_TEXT_T7);    /* > */
                if ((SLS_COLOR_NOT_USED | text->fg_color) != SLS_COLOR_NOT_USED)
                {
                    sprintf(str, "#%6x", text->fg_color);
                    sprintf(tmp, SLS_TEXT_T5, str);     /* <param name="foregroundcolor" value="#RRGGBB" /> */
                    strcat(buffer, tmp);
                }

                /* UC doesn't support text size setting
                   if (SLS_TEXT_SIZE_DEFAULT != list->text.textSize)
                   {
                   sprintf(tmp, SLS_TEXT_T8, sls_textSizeToStr(
                   list->text.textSize));
                   strcat(buffer, tmp);
                   } */

                strcat(buffer, SLS_TEXT_T9);    /* </text> */
            }
            size = strlen(buffer);
            break;
        }

        case MMA_INSERT_IMAGE:
        {
            mma_mms_slide_object_struct *image = (mma_mms_slide_object_struct*) obj;

#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            buffer_len = sizeof(SLS_IMAGE_T1) + sizeof(SLS_IMAGE_T2) + sizeof(SLS_IMAGE_T3) + sizeof(SLS_IMAGE_T4) +
                strlen(temp_file_name) + strlen(i_region_name) + 2 * SLS_INTSZ + 1;
#else
            buffer_len = sizeof(SLS_IMAGE_T1) + sizeof(SLS_IMAGE_T2) + sizeof(SLS_IMAGE_T3) + sizeof(SLS_IMAGE_T4) +
                strlen(utf8_filename) + strlen(i_region_name) + 2 * SLS_INTSZ + 1;
#endif 
            tmp = (char*)OslMalloc(buffer_len);
            memset(tmp, 0, buffer_len);
            buffer = (char*)OslMalloc(buffer_len);
            memset(buffer, 0, buffer_len);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            sprintf(tmp, SLS_IMAGE_T1, temp_file_name, i_region_name);   /* <img src="??.??" region="Image" */
#else
            sprintf(tmp, SLS_IMAGE_T1, utf8_filename, i_region_name);   /* <img src="??.??" region="Image" */
#endif
            strcpy(buffer, tmp);
            if (image)
            {
                /* begin, end */
                if (image->begin == 0 && image->end == dur) /* same with slide time setting */
                {
                }
                else
                {
                    /* Sync with copyTimingAttrs() in Sls_if.c */
                    if (image->begin != SRV_UC_INVALID_VALUE && image->begin != 0)
                    {
                        sprintf(tmp, SLS_IMAGE_T2, (unsigned long)image->begin * MMA_1_SEC_IN_MSEC);    /* begin="??ms" */
                        strcat(buffer, tmp);
                    }
                    if (image->end != SRV_UC_INVALID_VALUE && image->end != 0)
                    {
                        sprintf(tmp, SLS_IMAGE_T3, (unsigned long)image->end * MMA_1_SEC_IN_MSEC);      /* end="??ms" */
                        strcat(buffer, tmp);
                    }
                }
                /* "alt" not suppported now */
            }

            strcat(buffer, SLS_IMAGE_T5);   /* /> */
            size = strlen(buffer);
            break;
        }

        case MMA_INSERT_AUDIO:
        {
            mma_mms_slide_object_struct *audio = (mma_mms_slide_object_struct*) obj;

#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            buffer_len = sizeof(SLS_AUDIO_T1) + sizeof(SLS_AUDIO_T2) + sizeof(SLS_AUDIO_T3) + sizeof(SLS_AUDIO_T4) +
                strlen(temp_file_name) + 2 * SLS_INTSZ + 1;
#else
            buffer_len = sizeof(SLS_AUDIO_T1) + sizeof(SLS_AUDIO_T2) + sizeof(SLS_AUDIO_T3) + sizeof(SLS_AUDIO_T4) +
                strlen(utf8_filename) + 2 * SLS_INTSZ + 1;
#endif
            tmp = (char*)OslMalloc(buffer_len);
            memset(tmp, 0, buffer_len);
            buffer = (char*)OslMalloc(buffer_len);
            memset(buffer, 0, buffer_len);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            sprintf(tmp, SLS_AUDIO_T1, temp_file_name);  /* <audio src="??.??" /> */
#else
            sprintf(tmp, SLS_AUDIO_T1, utf8_filename);  /* <audio src="??.??" /> */
#endif
            strcpy(buffer, tmp);
            if (audio)
            {
                /* begin, end */
                if (audio->begin == 0 && audio->end == dur) /* same with slide time setting */
                {
                }
                else
                {
                    /* Sync with copyTimingAttrs() in Sls_if.c */
                    if (audio->begin != SRV_UC_INVALID_VALUE && audio->begin != 0)
                    {
                        sprintf(tmp, SLS_AUDIO_T2, (unsigned long)audio->begin * MMA_1_SEC_IN_MSEC);    /* begin="??ms" */
                        strcat(buffer, tmp);
                    }
                    if (audio->end != SRV_UC_INVALID_VALUE && audio->end != 0)
                    {
                        sprintf(tmp, SLS_AUDIO_T3, (unsigned long)audio->end * MMA_1_SEC_IN_MSEC);      /* end="??ms" */
                        strcat(buffer, tmp);
                    }
                }
                /* "alt" not suppported now */
            }

            strcat(buffer, SLS_AUDIO_T5);   /* /> */
            size = strlen(buffer);
            break;
        }

        case MMA_INSERT_VIDEO:
#ifndef __MMI_MMS_COSMOS_VIDEO_SLIM__
        {
            mma_mms_slide_object_struct *video = (mma_mms_slide_object_struct*) obj;

#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            buffer_len = sizeof(SLS_VIDEO_T1) + sizeof(SLS_VIDEO_T2) + sizeof(SLS_VIDEO_T3) + sizeof(SLS_VIDEO_T4) +
                strlen(temp_file_name) + strlen(i_region_name) + 2 * SLS_INTSZ + 1;
#else
            buffer_len = sizeof(SLS_VIDEO_T1) + sizeof(SLS_VIDEO_T2) + sizeof(SLS_VIDEO_T3) + sizeof(SLS_VIDEO_T4) +
                strlen(utf8_filename) + strlen(i_region_name) + 2 * SLS_INTSZ + 1;
#endif    
            tmp = (char*)OslMalloc(buffer_len);
            memset(tmp, 0, buffer_len);
            buffer = (char*)OslMalloc(buffer_len);
            memset(buffer, 0, buffer_len);
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
            sprintf(tmp, SLS_VIDEO_T1, temp_file_name, i_region_name);   /* <video src="??.??" region="Image" */
#else
            sprintf(tmp, SLS_VIDEO_T1, utf8_filename, i_region_name);   /* <video src="??.??" region="Image" */
#endif
            strcpy(buffer, tmp);
            if (video)
            {
                /* begin, end */
                if (video->begin == 0 && video->end == dur) /* same with slide time setting */
                {
                }
                else
                {
                    /* Sync with copyTimingAttrs() in Sls_if.c */
                    if (video->begin != SRV_UC_INVALID_VALUE && video->begin != 0)
                    {
                        sprintf(tmp, SLS_VIDEO_T2, (unsigned long)video->begin * MMA_1_SEC_IN_MSEC);    /* begin="??ms" */
                        strcat(buffer, tmp);
                    }
                    if (video->end != SRV_UC_INVALID_VALUE && video->end != 0)
                    {
                        sprintf(tmp, SLS_VIDEO_T3, (unsigned long)video->end * MMA_1_SEC_IN_MSEC);      /* end="??ms" */
                        strcat(buffer, tmp);
                    }
                }
                /* "alt" not suppported now */
            }

            strcat(buffer, SLS_VIDEO_T5);   /* /> */
            size = strlen(buffer);
            break;
        }
#endif

        case MMA_INSERT_ATTACHMENT:
            size = 0;
            break;

		case MMA_INSERT_REF:
    	{
        	mma_mms_slide_ref_object_struct *refs = (mma_mms_slide_ref_object_struct *) obj;
        	buffer_len = sizeof(SLS_REF_T1) + sizeof(SLS_REF_T2) + sizeof(SLS_REF_T3) + sizeof(SLS_REF_T4) + 
        	strlen(utf8_filename) + 2 * SLS_INTSZ + 1;
        	tmp = (char*)OslMalloc(buffer_len);
        	memset(tmp, 0, buffer_len);
        	buffer = (char*)OslMalloc(buffer_len);
        	memset(buffer, 0, buffer_len);
        	sprintf(tmp, SLS_REF_T1, utf8_filename);  /* <ref src="??.??" /> */
        	strcpy(buffer, tmp);
        	if (refs)
        	{
            	/* begin, end */
            	if (refs->begin == 0 && refs->end == dur)  /* same with slide time setting */
            	{
            	}
            	else
            	{
                	/* Sync with copyTimingAttrs() in Sls_if.c */
                	if (refs->begin != SRV_UC_INVALID_VALUE && refs->begin != 0)
                	{
                    	sprintf(tmp, SLS_REF_T2, (unsigned long)refs->begin * MMA_1_SEC_IN_MSEC);  /* begin="??ms" */
                    	strcat(buffer, tmp);
                	}
                	if (refs->end != SRV_UC_INVALID_VALUE && refs->end != 0)
                	{
                    	sprintf(tmp, SLS_REF_T3, (unsigned long)refs->end * MMA_1_SEC_IN_MSEC);  /* end="??ms" */
                    	strcat(buffer, tmp);
                	}
            	}
            	/* "alt" not suppported now */
        	}

        	strcat(buffer, SLS_REF_T5);  /* /> */
        	size = strlen(buffer);
        	ASSERT(size < buffer_len);
        	break;
    	}

        default:
            ASSERT(0);
    }

    if(tmp)
    {
        OslMfree(tmp);
    }
    if(buffer)
    {
        OslMfree(buffer);
    }
    if(utf8_filepath)
    {
        OslMfree(utf8_filepath);
    }
#ifdef MMA_NON_ASCII_NAME_CONV_SUPPORT
    if(!is_ascii_name && temp_file_name)
    {
        OslMfree(temp_file_name);
    }
#endif   
    return size;

}
/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_header_size
 * DESCRIPTION
 *  Calculate MMS header size including
 *  - X-Mms-Message-Type: 8C 80
 *  - X-Mms-Transaction-Id: 98 XX XX XX XX XX XX XX XX XX XX 00  (possible longest length)
 *  - X-Mms-MMS_Version: 8D 9X
 *  - Date: 85 04 XX XX XX XX  (possible longest length)
 *  - From: 89 01 81
 *  - To: mma_uc_calc_header_attribute_addr_size_int()
 *  - Cc: mma_uc_calc_header_attribute_addr_size_int()
 *  - Bcc: mma_uc_calc_header_attribute_addr_size_int()
 *  - Subject: mma_uc_calc_header_attribute_size()
 *  - X-Mms-Expiry: 88 [Value-Length] 81 [Short-length] XX XX (XX)
 *  - X-Mms-Delivery-Time: 87 [Value-Length:05] 81 [Short-length:03] 01 51 80  (approximate: use 1 day as delivery time)
 *  - X-Mms-Sender-Visibility: 94 80
 *  - X-Mms-Priority: 8F 8X
 *  - X-Mms-Delivery-Report: 86 8X
 *  - X-Mms-Read-Report: 90 8X
 *  - Content-type: 84  [Value-Length:1D] B3 89 [MMS_MEDIA_TYPE_STRING_SMIL: application/smil] 00 8A 3C [MEAlib_getSmilContentId()] 3E 00
 *  - nEntries: [uintvar]
 * PARAMETERS
 *  input       [IN]        
 *  mms(?)      [IN]        
 * RETURNS
 *  size in bytes
 *****************************************************************************/
kal_uint32 mma_uc_calc_header_size(const void *input, mma_mms_type_enum mms_type)
{
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_slide_smil_size
 * DESCRIPTION
 *  This function is to calculate SMIL description size for slide (<par ...></par>)
 * CALLS
 *  
 * PARAMETERS
 *  sec     [IN]        
 * RETURNS
 *  smil description size
 *****************************************************************************/
kal_uint32 mma_uc_calc_slide_smil_size(kal_uint32 sec)
{
    return 0;
}

kal_uint32 mma_uc_calc_text_uintvar_overhead_size(kal_uint32 utf8_byte_size)
{
    return 0;
}

kal_uint32 mma_uc_calc_object_smil_size(mma_insert_type_enum type, const kal_wchar *filepath)
{
    return mma_uc_calc_object_smil_size_precise(type, filepath, NULL, 0);
}

kal_uint32 mma_uc_calc_object_overhead_size(mma_insert_type_enum type, const kal_wchar *filename, kal_uint32 filesize, mma_mms_type_enum mms_type)
{
	return 0;
}
/*****************************************************************************
 * FUNCTION
 *  mma_uc_calc_msg_size
 * DESCRIPTION
 *  This function is to
 * CALLS
 *  
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 mma_uc_calc_msg_size(const void *input, mma_mms_type_enum mms_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char buffer[8];
    kal_uint32 size = 0, smil_size = 0;
    srv_uc_slide_struct *slide = NULL;
    srv_uc_object_struct *obj = NULL;
    srv_uc_msg_struct *mms = (srv_uc_msg_struct*) input;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    size = mma_uc_calc_header_size(mms, mms_type);
	if(mms_type != MMA_MMS_TYPE_MIXED_MMS)
	{
        /* SMIL body: slide info */
        slide = mms->slide_head;
        while (slide)
        {
            if (slide->text.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_TEXT,
                                slide->text.object->file_name,
                                &slide->text,
                                slide->duration);
            }
            if (slide->image.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_IMAGE,
                                slide->image.object->file_name,
                                &slide->image,
                                slide->duration);
            }
            if (slide->audio.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_AUDIO,
                                slide->audio.object->file_name,
                                &slide->audio,
                                slide->duration);
            }
            if (slide->video.object != NULL)
            {
                smil_size += mma_uc_calc_object_smil_size_precise(
                                MMA_INSERT_VIDEO,
                                slide->video.object->file_name,
                                &slide->video,
                                slide->duration);
            }
            slide = slide->next;
        }
        size += smil_size;
    
	}
    /* multipart excepts SMIL, refer to  wap_mma_uc_calc_object_multipart_size() */
    obj = mms->object_head;
    while (obj)
    {
    #ifndef __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__
        char *utf8_filename = NULL;

        utf8_filename = mma_um_ucs2_to_utf8_string((const kal_wchar*)obj->file_name);
        /* DataLen */
        size += mma_get_uintvar_length_bytes(obj->size);

        /* HeadersLen, Headers */
       // size += mma_uc_calc_object_multipart_header_size((const char*)utf8_filename, KAL_FALSE);
        if(utf8_filename)
        {
            OslMfree(utf8_filename);
        }
    #endif /* __MMI_MMS_CALC_MSG_SIZE_BY_USER_ELEMENTS__ */ 
        /* body */
        size += obj->size;

        obj = obj->next;
    }
    return size;
}
#endif

#endif /* #if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__)) */
