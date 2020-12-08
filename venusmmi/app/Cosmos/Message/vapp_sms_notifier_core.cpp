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
 *  vapp_sms_notifier_core.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SMS setting for Venus UI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_status_icons_def.h"
#include "vapp_sms_notifier_core.h"
#include "vapp_sms_notifier_scrn.h"
#include "mmi_rp_app_vapp_sms_def.h"
#include "vapp_sms_util.h"
#include "vapp_nmgr_gprot.h"
#include "vapp_msg_ncenter_gprot.h"
#include "mmi_rp_vapp_msg_def.h"
#include "vapp_msg_features.h"


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmsSrvGprot.h"
    #include "UmSrvGprot.h"
    #include "PhbSrvGprot.h"
    #include "SimCtrlSrvGProt.h"
    #include "ModeSwitchSrvGprot.h"
    #include "DateTimeType.h"
    #include "mmi_frm_scenario_gprot.h"
    #include "Wgui_categories_util.h"
    #include "CustDataRes.h"
    #include "gui_typedef.h"
	#include "UCMGProt.h"
#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
extern "C"
{
#endif



#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
static VfxBool tcard_mem_exceed = VFX_FALSE;
#endif
static VfxBool mem_exceed = VFX_FALSE;
static VfxBool sim_mem_exceed = VFX_FALSE;
#if (MMI_MAX_SIM_NUM >= 2)
static VfxBool sim2_mem_exceed = VFX_FALSE;
#endif
#if (MMI_MAX_SIM_NUM >= 3)
static VfxBool sim3_mem_exceed = VFX_FALSE;
#endif
#if (MMI_MAX_SIM_NUM >= 4)
static VfxBool sim4_mem_exceed = VFX_FALSE;
#endif

const mmi_event_notify_enum eventType[VAPP_SMS_TOTAL_SIM][VAPP_SMS_MAX_MSG_WAITING_TYPE] = 
{
	MMI_EVENT_SIM1_NEW_MSG_WAITING_VOICEMAIL,
#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__

	MMI_EVENT_SIM1_NEW_MSG_WAITING_FAX,
	MMI_EVENT_SIM1_NEW_MSG_WAITING_EMAIL,
	MMI_EVENT_SIM1_NEW_MSG_WAITING_NET_MSG,
	MMI_EVENT_SIM1_NEW_MSG_WAITING_VEDIO,
#endif
#if (MMI_MAX_SIM_NUM >= 2)
	MMI_EVENT_SIM2_NEW_MSG_WAITING_VOICEMAIL,
#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__

	MMI_EVENT_SIM2_NEW_MSG_WAITING_FAX,
	MMI_EVENT_SIM2_NEW_MSG_WAITING_EMAIL,
	MMI_EVENT_SIM2_NEW_MSG_WAITING_NET_MSG,
	MMI_EVENT_SIM2_NEW_MSG_WAITING_VEDIO,
#endif
#endif
#if (MMI_MAX_SIM_NUM >= 3)
	MMI_EVENT_SIM3_NEW_MSG_WAITING_VOICEMAIL,
#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__

	MMI_EVENT_SIM3_NEW_MSG_WAITING_FAX,
	MMI_EVENT_SIM3_NEW_MSG_WAITING_EMAIL,
	MMI_EVENT_SIM3_NEW_MSG_WAITING_NET_MSG,
	MMI_EVENT_SIM3_NEW_MSG_WAITING_VEDIO,
#endif
#endif
#if (MMI_MAX_SIM_NUM >= 4)
	MMI_EVENT_SIM4_NEW_MSG_WAITING_VOICEMAIL,
#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__

	MMI_EVENT_SIM4_NEW_MSG_WAITING_FAX,
	MMI_EVENT_SIM4_NEW_MSG_WAITING_EMAIL,
	MMI_EVENT_SIM4_NEW_MSG_WAITING_NET_MSG,
	MMI_EVENT_SIM4_NEW_MSG_WAITING_VEDIO,
#endif
#endif
 };

const S32 statusIcon[] = 
{
	STATUS_ICON_UNREAD_VOICE,
#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__

	STATUS_ICON_UNREAD_FAX,
	STATUS_ICON_UNREAD_SIM_EMAIL,
	STATUS_ICON_UNREAD_NET,
	STATUS_ICON_UNREAD_VIDEO,
#endif
};

#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
const S32 statusPreviewIcon[] = 
{
	IMG_SI_UNREAD_VOICE,
#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__

	IMG_SI_UNREAD_FAX,
	IMG_SI_UNREAD_SIM_EMAIL,
	IMG_SI_UNREAD_NET,
	IMG_SI_UNREAD_VIDEO
#endif
};
#endif


#define VAPP_SMS_NOTIFY_MAX_PREVIEW_TEXT_LEN    60

MMI_BOOL vapp_sms_has_sending_sms(void)
{
    U16 index;
    U16 msg_list_size;
    U16 msg_id;

    msg_list_size = srv_sms_get_list_size(SRV_SMS_BOX_UNSENT);

    for (index = 0; index < msg_list_size; index++)
    {
        msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_UNSENT, index);

        if (srv_sms_get_unsent_msg_status(msg_id) == SRV_SMS_SEND_SENDING)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


MMI_BOOL vapp_sms_has_waiting_sms(void)
{
    U16 index;
    U16 msg_list_size;
    U16 msg_id;

    msg_list_size = srv_sms_get_list_size(SRV_SMS_BOX_UNSENT);

    for (index = 0; index < msg_list_size; index++)
    {
        msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_UNSENT, index);

        if (srv_sms_get_unsent_msg_status(msg_id) == SRV_SMS_SEND_WAITING)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}

U32 vapp_sms_get_send_failed_count(void)
{
    U16 index;
    U16 msg_list_size;
    U16 msg_id;
    U32 count = 0;

    msg_list_size = srv_sms_get_list_size(SRV_SMS_BOX_UNSENT);

    for (index = 0; index < msg_list_size; index++)
    {
        msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_UNSENT, index);

        if (srv_sms_get_unsent_msg_status(msg_id) == SRV_SMS_SEND_FAIL)
        {
            count++;
        }
    }

    return count;
}

void msgWaitingNotify(l4csmsal_msg_waiting_ind_ext_struct *pMsgIndExt, srv_sms_sim_enum simId)
{
#ifdef __MMI_MSG_REL4_SUPPORT__
    if (srv_sms_check_r4_support() == MMI_TRUE)
    {
        /* R4R5 mode, only show the Line1, ignore the Line2 */
        if (pMsgIndExt->line_no >= 1)
        {
            return;
        }
    }
    else
    {
        if (pMsgIndExt->line_no >= VAPP_SMS_MSG_WAITING_LINE_NUM)
        {
            return;
        }
    }
#else /* __MMI_MSG_REL4_SUPPORT__ */
    if (pMsgIndExt->line_no >= VAPP_SMS_MSG_WAITING_LINE_NUM)
    {
        return;
    }
#endif /* __MMI_MSG_REL4_SUPPORT__ */

    SmsMsgWaitingManager::VappSmsMsgWaitingData info;
    info.lineNo = pMsgIndExt->line_no;
    info.mspNo = pMsgIndExt->msp_no;
    info.waitingNum = pMsgIndExt->waiting_num;
    info.indType = pMsgIndExt->ind_type;
    info.isShowNum = (pMsgIndExt->is_show_num? VFX_TRUE: VFX_FALSE);
    info.isClear = (pMsgIndExt->is_clear? VFX_TRUE: VFX_FALSE);
    info.isfromStorage = (pMsgIndExt->is_from_storage? VFX_TRUE: VFX_FALSE);

    SmsMsgWaitingManager *msgWaitingManager = VFX_OBJ_GET_INSTANCE(SmsMsgWaitingManager);

    if (pMsgIndExt->is_clear)
    {
        msgWaitingManager->clearInd(&info, simId, VFX_TRUE);
    }        
    else
    {
        msgWaitingManager->addNewInd(&info, simId);
    }
}

static void onGetBearerCallback(srv_sms_callback_struct *callbackData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callbackData->result == MMI_TRUE)
    {
        VfxU8 *value = (VfxU8*)callbackData->action_data;
        VfxU8 preferCon = *value;

        for (VfxU8 simIndex = 1; simIndex < VAPP_SMS_TOTAL_SIM; simIndex++)
        {
            srv_sms_sim_enum sim_id =  vapp_sms_sim_index_to_sim_id(simIndex);

            srv_sms_set_setting_para(
                SRV_SMS_PRE_BEARER,
                &preferCon,
                sim_id,
                NULL,
                NULL);
        }
    }
}

mmi_ret VappSmsHandleSmsReadyInd(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_sms_ready_struct *event_info = (srv_sms_event_sms_ready_struct*)event_data->event_info;

    // The case of SMS not Ready is only happened when SIM Refresh
    if (event_info->is_sms_ready == MMI_TRUE)
    {
		VfxBool replyPath = VFX_FALSE;


        for (VfxU8 simIndex = 0; simIndex < VAPP_SMS_TOTAL_SIM; simIndex++)
        {
        	srv_sms_sim_enum sim_id =  vapp_sms_sim_index_to_sim_id(simIndex);
			mmi_sim_enum mmi_sim = vapp_sms_sim_index_to_mmi_sim(simIndex);
        	if (srv_sim_ctrl_is_available(mmi_sim))
    		{
    			const srv_sms_setting_struct *settings = srv_sms_get_default_setting(sim_id);
				replyPath = (settings->reply_path? VFX_TRUE: VFX_FALSE);
				break;
    		}
    	}

        for (VfxU8 simIndex = 0; simIndex < VAPP_SMS_TOTAL_SIM; simIndex++)
        {
            srv_sms_sim_enum sim_id =  vapp_sms_sim_index_to_sim_id(simIndex);
			mmi_sim_enum mmi_sim = vapp_sms_sim_index_to_mmi_sim(simIndex);
			if (srv_sim_ctrl_is_available(mmi_sim))
			{
	            const srv_sms_setting_struct *settings = srv_sms_get_default_setting(sim_id);
            VfxBool cur_rp = (settings->reply_path? VFX_TRUE: VFX_FALSE);
            VfxBool cur_sr = (settings->status_report? VFX_TRUE: VFX_FALSE);
            VfxU8 set_data[2];

            if (cur_rp != replyPath)
            {
                set_data[1] = replyPath;
                set_data[0] = cur_sr;

                srv_sms_set_setting_para(
                    SRV_SMS_COMMON_SETTINGS,
                    set_data,
                    sim_id,
                    NULL,
                    NULL);
            }
        }
    	}

        srv_sms_get_setting_para(
            SRV_SMS_PRE_BEARER,
            NULL,
            SRV_SMS_SIM_1,
            onGetBearerCallback,
            NULL);
    }
    return MMI_RET_OK;
}

mmi_ret VappSmsHandleNewSmsInd(mmi_event_struct *evt)
{
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_new_sms_struct* event_info;

    event_info = (srv_sms_event_new_sms_struct*)event_data->event_info;
 
    if (event_info->msg_id == SRV_SMS_INVALID_MSG_ID)
    {
    	SmsClass0NotifyManager *class0Manager = VFX_OBJ_GET_INSTANCE(SmsClass0NotifyManager);
        class0Manager->addNewInd(evt);
    }

    return MMI_RET_OK;
}

VfxResId vapp_sms_voicemail_get_numstr_id(VfxBool isShowNum, VfxU8 waitingNum, VfxU8 sim_index)
{
	VfxResId stringId = 0;
#if (MMI_MAX_SIM_NUM == 1)
    if (isShowNum && (waitingNum >= 1))
    {
        if (waitingNum == 1)
        {
            stringId = STR_ID_VAPP_SMS_NEW_VOICEMAIL_NUM_IND;
        }
        else
        {
            stringId = STR_ID_VAPP_SMS_NEW_VOICEMAIL_NUM_IND_PLURAL;
        }
    }
    else
    {
        stringId = STR_ID_VAPP_SMS_NEW_VOCIEMAIL_WAITING;
    }
#else
	mmi_rp_app_vapp_sms_str_enum str1[] =
		{
			STR_ID_VAPP_SMS_SIM1_VOICEMAIL_NUM_IND,
		#if (MMI_MAX_SIM_NUM >= 2)	
			STR_ID_VAPP_SMS_SIM2_VOICEMAIL_NUM_IND,
		#if (MMI_MAX_SIM_NUM >= 3)
			STR_ID_VAPP_SMS_SIM3_VOICEMAIL_NUM_IND,
		#if (MMI_MAX_SIM_NUM >= 4)
			STR_ID_VAPP_SMS_SIM4_VOICEMAIL_NUM_IND
		#endif
		#endif
		#endif
		};
	mmi_rp_app_vapp_sms_str_enum str2[] = 
		{
			STR_ID_VAPP_SMS_SIM1_VOICEMAIL_NUM_IND_PLURAL,
		#if (MMI_MAX_SIM_NUM >= 2)	
			STR_ID_VAPP_SMS_SIM2_VOICEMAIL_NUM_IND_PLURAL,
		#if (MMI_MAX_SIM_NUM >= 3)
			STR_ID_VAPP_SMS_SIM3_VOICEMAIL_NUM_IND_PLURAL,
		#if (MMI_MAX_SIM_NUM >= 4)
			STR_ID_VAPP_SMS_SIM4_VOICEMAIL_NUM_IND_PLURAL
		#endif
		#endif
		#endif
		};
	mmi_rp_app_vapp_sms_str_enum str3[] = 
		{
			STR_ID_VAPP_SMS_SIM1_VOICEMAIL_IND,
		#if (MMI_MAX_SIM_NUM >= 2)	
			STR_ID_VAPP_SMS_SIM2_VOICEMAIL_IND,
		#if (MMI_MAX_SIM_NUM >= 3)
			STR_ID_VAPP_SMS_SIM3_VOICEMAIL_IND,
		#if (MMI_MAX_SIM_NUM >= 4)
			STR_ID_VAPP_SMS_SIM4_VOICEMAIL_IND
		#endif
		#endif
		#endif
		};


    if (isShowNum && (waitingNum >= 1))
    {
        if (waitingNum == 1)
        {
            stringId = str1[sim_index];
        }
        else
        {
            stringId = str2[sim_index];
        }
    }
    else
    {
        stringId = str3[sim_index];
    } 
	return stringId;
}

void vapp_sms_voicemail_get_popup_str(SmsWaitingMsgUserData *waitingData, VfxWString &titleStr)
{
	mmi_sim_enum sim = waitingData->sim;
	vapp_msg_waiting_line_id_enum line = waitingData->line;
	SmsMsgWaitingManager *msgWaitingManager = VFX_OBJ_GET_INSTANCE(SmsMsgWaitingManager);
    VfxBool isShowNum = msgWaitingManager->checkIsShowNum(sim, line, VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND);
    VfxU8 waitingNum = 0;
    if (isShowNum)
    {
        waitingNum = msgWaitingManager->getWaitingNum(sim, line, VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND);
    }

    VfxWChar number[MAX_CC_ADDR_LEN + 1];
    VfxWChar name[SRV_SMS_MAX_PROFILE_NAME_LEN + 1];
    VfxWChar temp[SRV_SMS_MAX_PROFILE_NAME_LEN + 40];
    srv_sms_sim_enum sim_id = vapp_sms_mmi_sim_to_sim_id(sim);
	VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(sim_id);
	VfxResId stringId = vapp_sms_voicemail_get_numstr_id(isShowNum, waitingNum, sim_index);



	
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
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif

#endif

    if (VAPP_MSG_WAITING_LINE2 == line)
    {
        mmi_ucs2cpy((S8*)name, (S8*)srv_sms_get_mailbox_setting(sim_id)->p_mailbox_name[1]);
        mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(sim_id)->p_mailbox_number[1]);
    }
    else
    {
        mmi_ucs2cpy((S8*)name, (S8*)srv_sms_get_mailbox_setting(sim_id)->p_mailbox_name[0]);
        mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(sim_id)->p_mailbox_number[0]);
    }


    if (isShowNum && (waitingNum >= 1))
    {
        U8 ascii_num[10];
        memset(ascii_num, 0, 10);
        sprintf((S8*)ascii_num, "%d ", waitingNum);
        mmi_asc_to_ucs2((S8*) temp, (S8*) ascii_num);
        mmi_ucs2cat((S8*)temp, (S8*)GetString(stringId));
    }
    else
    {
        mmi_ucs2cpy((S8*)temp, (S8*)GetString(stringId));
    }

    if (name[0] != '\0')
    {
        mmi_ucs2cat((S8*)temp, (S8*)GetString(STR_ID_VAPP_SMS_NEW_VOICEMAIL_FROM));
        mmi_ucs2cat((S8*)temp, (S8*)name);
    }
    else if (number[0] != '\0')
    {
        mmi_ucs2cat((S8*)temp, (S8*)GetString(STR_ID_VAPP_SMS_NEW_VOICEMAIL_FROM));
        mmi_ucs2cat((S8*)temp, (S8*)number);
    }
	titleStr.loadFromMem(temp);

}

void vapp_sms_voicemail_dial_from_text_preview(SmsWaitingMsgUserData *waitingData)
{

	SmsMsgWaitingManager *msgWaiting = VFX_OBJ_GET_INSTANCE(SmsMsgWaitingManager);
	msgWaiting->setCurrentActionData(waitingData);
	msgWaiting->callVoicemail();
}

void vapp_sms_voicemail_dial_from_popup(SmsWaitingMsgUserData *waitingData)
{
	SmsMsgWaitingManager *msgWaiting = VFX_OBJ_GET_INSTANCE(SmsMsgWaitingManager);
	msgWaiting->clearCells(waitingData);
	vapp_msg_waiting_line_id_enum line = waitingData->line;
	mmi_sim_enum sim = waitingData->sim;


	
	srv_sms_sim_enum simId = vapp_sms_mmi_sim_to_sim_id(sim);
    VfxWChar number[MAX_CC_ADDR_LEN + 1];

	if (VAPP_MSG_WAITING_LINE2 == line)
	{
	    mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_number[1]);
	}
	else
	{
	    mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_number[0]);
	}
    if (number[0] == '\0')
    {
        vapp_nmgr_global_popup_show_confirm_one_button_id(
            MMI_SCENARIO_ID_DEFAULT,
            VCP_POPUP_TYPE_FAILURE,
            STR_GLOBAL_NO_NUMBER,
            STR_GLOBAL_OK,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);
		return;
    }

	mmi_ucm_make_call_para_struct make_call_para; 
	mmi_ucm_init_call_para(&make_call_para);

	srv_ucm_call_type_enum call_type[] =
		{
			SRV_UCM_VOICE_CALL_TYPE,
		#if (MMI_MAX_SIM_NUM >= 2)
			SRV_UCM_VOICE_CALL_TYPE_SIM2,
		#if (MMI_MAX_SIM_NUM >= 3)
			SRV_UCM_VOICE_CALL_TYPE_SIM3,
		#if (MMI_MAX_SIM_NUM >= 4)
			SRV_UCM_VOICE_CALL_TYPE_SIM4
		#endif
		#endif
		#endif
		};
	VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(simId);
	make_call_para.dial_type = call_type[sim_index];

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
	make_call_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_VOICE_MAIL;
	make_call_para.ucs2_num_uri = (U16*)number;
	mmi_ucm_call_launch(0, &make_call_para);
	
}

mmi_ret vapp_sms_call_voicemail_launch(mmi_event_struct *evt)
{
	SmsWaitingMsgUserData *waitingData = (SmsWaitingMsgUserData *)evt->user_data;
	if(evt->evt_id == EVT_ID_NMGR_POPUP_APP_LAUNCH)
	{
		vapp_sms_voicemail_dial_from_popup(waitingData);
	}
	else if (evt->evt_id == EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH)
	{
		vapp_sms_voicemail_dial_from_text_preview(waitingData);
	}
	
    return MMI_RET_OK;
}


mmi_ret VappSmsHandleNewMsgWaitingInd(mmi_event_struct *evt)
{
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_msg_waitting_struct* event_info = (srv_sms_event_msg_waitting_struct*)event_data->event_info;
    mmi_sms_msg_waiting_ind_struct *msgInd = (mmi_sms_msg_waiting_ind_struct*)event_info->msg_data;
    srv_sms_sim_enum sim_id = event_info->sim_id;
    l4csmsal_msg_waiting_ind_ext_struct msgIndExt;

	mmi_sim_enum mmi_sim = vapp_sms_sim_id_to_mmi_sim(sim_id);
    if (srv_sim_ctrl_get_unavailable_cause(mmi_sim) == SRV_SIM_CTRL_UA_CAUSE_NOT_INSERTED)
    {
        return MMI_RET_OK;
    }
#if 0	
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
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
/* under construction !*/
/* under construction !*/
#endif
    msgIndExt.ind_type = msgInd->ind_type;
    msgIndExt.line_no = msgInd->line_no;
    msgIndExt.msp_no = msgInd->msp_no;
    msgIndExt.waiting_num = msgInd->waiting_num;
    msgIndExt.ind_type = msgInd->ind_type;
    msgIndExt.is_show_num = msgInd->is_show_num;
    msgIndExt.is_clear = msgInd->is_clear;
    msgIndExt.is_from_storage = msgInd->is_from_storage;

    msgWaitingNotify(&msgIndExt, sim_id);

    VfxU8 ext_ind = msgInd->ext_indicator;

    for (VfxU8 i = 0; i < ext_ind; i++)
    {
        msgIndExt.ind_type = msgInd->msg_waiting[i].ind_type;
        msgIndExt.line_no = msgInd->msg_waiting[i].line_no;
        msgIndExt.msp_no = msgInd->msg_waiting[i].msp_no;
        msgIndExt.waiting_num = msgInd->msg_waiting[i].waiting_num;
        msgIndExt.ind_type = msgInd->msg_waiting[i].ind_type;
        msgIndExt.is_show_num = msgInd->msg_waiting[i].is_show_num;
        msgIndExt.is_clear = msgInd->msg_waiting[i].is_clear;
        msgIndExt.is_from_storage = msgInd->msg_waiting[i].is_from_storage;

        msgWaitingNotify(&msgIndExt, sim_id);
    }

    return MMI_RET_OK;
}


mmi_ret VappSmsHandleNewDeliveryReportInd(mmi_event_struct *evt)
{
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_new_status_report_struct *event_info = (srv_sms_event_new_status_report_struct*)event_data->event_info;
    srv_sms_status_report_struct *report_data = &event_info->report_data;
 

    mmi_frm_notification_para_struct notification_para;
    VfxWChar temp[VAPP_SMS_NOTIFY_MAX_PREVIEW_TEXT_LEN+1];
    memset((S8*)temp, 0, (VAPP_SMS_NOTIFY_MAX_PREVIEW_TEXT_LEN + 1)* ENCODING_LENGTH);
    VfxResId stringId = 0;
    if (report_data->status == SRV_SMS_SRS_SUCC)
    {
        stringId = STR_ID_VAPP_SMS_DELIVERED_TO;
    }
    else if (report_data->status == SRV_SMS_SRS_FAILED)
    {
        stringId = STR_ID_VAPP_SMS_FAILED_TO_SEND_TO;
    }
    else
    {
        return MMI_RET_OK;
    }
    mmi_ucs2cpy((S8*)temp, GetString(stringId));
    mmi_ucs2cat((S8*)temp, (S8*)L" ");
    VfxU16 len = mmi_ucs2strlen((S8*)temp);
    if (!srv_phb_get_name_by_number(report_data->number, &temp[len-1], VAPP_SMS_NOTIFY_MAX_PREVIEW_TEXT_LEN-len))
    {
        wcscat((wchar_t*)temp, (wchar_t*)report_data->number);
    }
    notification_para.text = temp;
    notification_para.option = 0;

    mmi_event_notify_enum eventType[] =
        {
            MMI_EVENT_SIM1_NEW_SMS_REPORT,
            MMI_EVENT_SIM2_NEW_SMS_REPORT,
            MMI_EVENT_SIM3_NEW_SMS_REPORT,
            MMI_EVENT_SIM4_NEW_SMS_REPORT,
        };

    VfxU8 simIndex = vapp_sms_sim_id_to_sim_index(event_info->sim_id);

    mmi_frm_nmgr_notify(
        MMI_SCENARIO_ID_NEW_SMS_REPORT,
        eventType[simIndex],
        &notification_para);

    return MMI_RET_OK;
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
#endif

static void VappSmsMemExceedProc(VfxId id, void *userData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                                                         */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                               */
    /*----------------------------------------------------------------*/
    VfxBool *excd_gid = (VfxBool*)userData;
    *excd_gid = VFX_FALSE;
}


MMI_BOOL VappSmsSimMemExceedInd(mmi_scenario_id scenario_id, void *arg)
{
    VfxResId stringId;
    VfxBool *excd_gid = (VfxBool*)arg;
    *excd_gid= MMI_TRUE;

#if (MMI_MAX_SIM_NUM >= 4)
	if (excd_gid == &sim2_mem_exceed)
	{
		stringId = STR_ID_VAPP_SMS_SIM4_STORAGE_EXCEEDED;
	}
#endif
#if (MMI_MAX_SIM_NUM >= 3)
	if (excd_gid == &sim3_mem_exceed)
	{
		stringId = STR_ID_VAPP_SMS_SIM3_STORAGE_EXCEEDED;
	}

#endif
#if (MMI_MAX_SIM_NUM >= 2)
    if (excd_gid == &sim2_mem_exceed)
    {
        stringId = STR_ID_VAPP_SMS_SIM2_STORAGE_EXCEEDED;
    }
    else
    {
        stringId = STR_ID_VAPP_SMS_SIM1_STORAGE_EXCEEDED;
    }
#else
    stringId = STR_ID_VAPP_SMS_SIM_STORAGE_EXCEEDED;
#endif

    vcp_global_popup_show_confirm_one_button_id(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_INFO,
        stringId,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VappSmsMemExceedProc,
        excd_gid);

    return MMI_TRUE;
}

MMI_BOOL VappSmsSimPhoneMemExceedInd(mmi_scenario_id scenario_id, void *arg)
{
    VfxResId stringId;
    VfxBool *excd_gid = (VfxBool*)arg;
    *excd_gid= MMI_TRUE;

#if (MMI_MAX_SIM_NUM >= 4)
	if (excd_gid == &sim2_mem_exceed)
	{
		stringId = STR_ID_VAPP_SMS_SIM4_PHONE_STORAGE_EXCEEDED;
	}
#endif
#if (MMI_MAX_SIM_NUM >= 3)
	if (excd_gid == &sim3_mem_exceed)
	{
		stringId = STR_ID_VAPP_SMS_SIM3_PHONE_STORAGE_EXCEEDED;
	}

#endif
#if (MMI_MAX_SIM_NUM >= 2)
    if (excd_gid == &sim2_mem_exceed)
    {
        stringId = STR_ID_VAPP_SMS_SIM2_PHONE_STORAGE_EXCEEDED;
    }
    else
    {
        stringId = STR_ID_VAPP_SMS_SIM1_PHONE_STORAGE_EXCEEDED;
    }
#else
    stringId = STR_ID_VAPP_SMS_SIM_PHONE_STORAGE_EXCEEDED;
#endif

    vcp_global_popup_show_confirm_one_button_id(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_INFO,
        stringId,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VappSmsMemExceedProc,
        excd_gid);

    return MMI_TRUE;
}


MMI_BOOL VappSmsPhoneMemExceedInd(mmi_scenario_id scenario_id, void *arg)
{
    mem_exceed = VFX_TRUE;

    vcp_global_popup_show_confirm_one_button_id(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_INFO,
        STR_ID_VAPP_SMS_PHONE_STORAGE_EXCEEDED,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VappSmsMemExceedProc,
        &mem_exceed);

    return MMI_TRUE;
}

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__

MMI_BOOL VappSmsTcardMemExceedInd(mmi_scenario_id scenario_id, void *arg)
{
	tcard_mem_exceed = VFX_TRUE;

    vcp_global_popup_show_confirm_one_button_id(
        GRP_ID_ROOT,
        VCP_POPUP_TYPE_INFO,
        STR_ID_VAPP_SMS_TCARD_EXCEEDED,
        STR_GLOBAL_OK,
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VappSmsMemExceedProc,
        &tcard_mem_exceed);
	return MMI_TRUE;
}
#endif

mmi_ret VappSmsHandleMemExceedInd(mmi_event_struct *evt)
{
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_mem_exceed_struct *pMemExceed = (srv_sms_event_mem_exceed_struct*)event_data->event_info;

    if (pMemExceed->mem_type & SRV_SMS_MEM_SIM_ONLY)
    {
        VfxBool *excd_gid = &sim_mem_exceed;

    #if (MMI_MAX_SIM_NUM >= 2)
        if (pMemExceed->sim_id == SRV_SMS_SIM_2)
        {
            excd_gid = &sim2_mem_exceed;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        if (pMemExceed->sim_id == SRV_SMS_SIM_3)
        {
            excd_gid = &sim3_mem_exceed;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        if (pMemExceed->sim_id == SRV_SMS_SIM_4)
        {
            excd_gid = &sim4_mem_exceed;
        }
    #endif

		if (pMemExceed->mem_type & SRV_SMS_MEM_NORMAL)
		{
        if (*excd_gid == VFX_FALSE)
        {
            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_NON_TONE,
				VappSmsSimPhoneMemExceedInd,
                excd_gid);
        }
    }
		else
		{
        if (*excd_gid == VFX_FALSE)
        {
            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_DEFAULT,
                MMI_EVENT_NON_TONE,
                VappSmsSimMemExceedInd,
                excd_gid);
        }
    }
    }

    else if ((pMemExceed->mem_type & SRV_SMS_MEM_ME_ONLY) && !mem_exceed)
    {
        mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_NON_TONE,
            VappSmsPhoneMemExceedInd,
            &mem_exceed);
    }
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	if ((pMemExceed->mem_type & SRV_SMS_MEM_TCARD_ONLY) && !tcard_mem_exceed)
	{
        mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_NON_TONE,
            VappSmsTcardMemExceedInd,
            &tcard_mem_exceed);
	}

#endif
    return MMI_RET_OK;
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
#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //__SRV_SMS_BACKGROUND_SEND_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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


#ifdef __MMI_MESSAGES_TEMPLATE__
mmi_ret VappSmsHandleTemplateAddInd(mmi_event_struct *evt)
{
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;

    srv_sms_event_add_template_struct *event_info = 
        (srv_sms_event_add_template_struct*)event_data->event_info;

    SmsListener *listener = VFX_OBJ_GET_INSTANCE(SmsListener);

    listener->m_signalTextTemplateAdd.emit(event_info->template_id, event_info->list_index);

    return MMI_RET_OK;
}

mmi_ret VappSmsHandleTemplateDelInd(mmi_event_struct *evt)
{
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;

    srv_sms_event_del_template_struct *event_info = 
        (srv_sms_event_del_template_struct*)event_data->event_info;

    SmsListener *listener = VFX_OBJ_GET_INSTANCE(SmsListener);

    listener->m_signalTextTemplateDel.emit(event_info->template_id, event_info->list_index);

    return MMI_RET_OK;
}
#endif /*__MMI_MESSAGES_TEMPLATE__*/

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Class SmsListener
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("SmsListener", SmsListener, VfxObject);
#ifdef __MMI_MESSAGES_TEMPLATE__

VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(SmsListener);

SmsListener::SmsListener()
{
}

void SmsListener::onInit(void)
{
    Super::onInit();
}


void SmsListener::onDeinit(void)
{
    Super::onDeinit();
}
#endif /*__MMI_MESSAGES_TEMPLATE__*/

/***************************************************************************** 
 * Class SmsClass0
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("SmsClass0", SmsClass0, VfxObject);

SmsClass0::SmsClass0():
    m_timestamp(0),
	m_contentLength(0),
	m_fo(0),
    m_dcs(SRV_SMS_DCS_UCS2),
    m_totalSeg(0),
    m_isUsed(VFX_FALSE),
    m_simId(SRV_SMS_SIM_1)    
{
    m_addr[0] = '\0';
    m_scAddr[0] = '\0';
	m_content[0] = '\0';
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
#endif


VfxU8 SmsClass0::getFo()
{
    return m_fo;
}

const VfxU8* SmsClass0::getAddress()
{
    return m_addr;
}

const VfxU8* SmsClass0::getScAddress()
{
    return m_scAddr;
}

VfxU32 SmsClass0::getTimestamp()
{
    return m_timestamp;
}

VfxU8 SmsClass0::getTotalSeg()
{
    return m_totalSeg;
}

VfxU8 SmsClass0::getPid()
{
    return m_pid;
}

VfxU8 SmsClass0::getMti()
{
    return m_mti;
}

srv_sms_sim_enum SmsClass0::getSimId()
{
    return m_simId;
}

const VfxWChar* SmsClass0::getContent()
{
    return m_content;
}

VfxU16 SmsClass0::getContentLength()
{
    return m_contentLength;
}

VfxU8 SmsClass0::getContentDcs()
{
    return m_dcs;
}

void SmsClass0::replaceData(srv_sms_event_new_sms_struct *event_data)
{
	m_isUsed = VFX_TRUE;
    srv_sms_new_msg_struct *new_msg_data = (srv_sms_new_msg_struct*)event_data->msg_data;

    m_fo = new_msg_data->fo;

    memcpy((S8*)m_addr, (S8*)new_msg_data->number, SRV_SMS_MAX_ADDR_LEN);
    m_addr[SRV_SMS_MAX_ADDR_LEN] = '\0';

    memcpy(m_scAddr, new_msg_data->sc_number, SRV_SMS_MAX_ADDR_LEN);
    m_scAddr[SRV_SMS_MAX_ADDR_LEN] = '\0';

    m_timestamp = mmi_dt_mytime_2_utc_sec(&(new_msg_data->timestamp), MMI_FALSE);

    m_simId = new_msg_data->sim_id;
    m_pid = new_msg_data->pid;
    m_mti = new_msg_data->mti;

	m_contentLength = new_msg_data->message_len;
    memcpy(m_content, event_data->content, (new_msg_data->message_len + ENCODING_LENGTH));

    m_dcs = new_msg_data->dcs;
    m_totalSeg = new_msg_data->total_seg;
}


/***************************************************************************** 
 * Class SmsClass0NotifyManager
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("SmsClass0NotifyManager", SmsClass0NotifyManager, VfxObject);


VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(SmsClass0NotifyManager);

SmsClass0NotifyManager::SmsClass0NotifyManager():
    m_indNum(0)
{
    //for (VfxU8 i = 0; i < VAPP_SMS_MAX_CLASS0_IND_NUM; i++)
    //{
        //m_class0Provider[i] = NULL;
    //}
}

SmsClass0NotifyManager::~SmsClass0NotifyManager()
{
    //for (VfxU8 i = 0; i < VAPP_SMS_MAX_CLASS0_IND_NUM; i++)
    //{
        //if (m_class0Provider[i])
        //{
            //VFX_OBJ_CLOSE(m_class0Provider[i]);
            //m_class0Provider[i] = NULL;
        //}  
    //}

    m_indNum = 0;
}
/*
void SmsClass0NotifyManager::onInit()
{
	VFX_OBJ_CREATE(m_context, VfxContext, VFX_SYS_GLOBAL_CONTEXT);
	m_context->assignPool((VfxU8 *)g_vappSmsClass0NotifyMemPool, g_memSize);
	VfxObject::onInit();
}
*/

VfxBool SmsClass0NotifyManager::addNewInd(mmi_event_struct *evt)
{
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_new_sms_struct* event_info = (srv_sms_event_new_sms_struct*)event_data->event_info;
    srv_sms_new_msg_struct *new_msg_data = (srv_sms_new_msg_struct*)event_info->msg_data;

		
    VfxBool isReplaced = VFX_FALSE;

    if ((m_indNum > 0) && (new_msg_data->pid >= 0x41) && (new_msg_data->pid <= 0x47)) // deal replace type
    {
        for (VfxU8 i = 0; i < VAPP_SMS_MAX_CLASS0_IND_NUM; i++)
        {
            if (m_class0Provider[i].isUsed())
            {
                if (
                #if (MMI_MAX_SIM_NUM >= 2)
                    (new_msg_data->sim_id == m_class0Provider[i].getSimId()) &&
                #endif 
                    (new_msg_data->pid == m_class0Provider[i].getPid()) &&
                    (new_msg_data->mti == m_class0Provider[i].getMti()) &&
                    (new_msg_data->total_seg == m_class0Provider[i].getTotalSeg()) &&
                    (strcmp((S8*)new_msg_data->number, (S8*)m_class0Provider[i].getAddress()) == 0)
                    )
                {
                    m_class0Provider[i].replaceData(event_info);
                    isReplaced = VFX_TRUE;
                }
            }       
        }
    }

    if (!isReplaced)
    {
        if (m_indNum == VAPP_SMS_MAX_CLASS0_IND_NUM)
        {
            deleteInd(findoldest());
        }

        VfxU8 unusedIndex = 0;

        while((unusedIndex < VAPP_SMS_MAX_CLASS0_IND_NUM) && m_class0Provider[unusedIndex].isUsed())
        {
            unusedIndex++;
        }

        VFX_ASSERT(unusedIndex < VAPP_SMS_MAX_CLASS0_IND_NUM);

        m_class0Provider[unusedIndex].replaceData(event_info);

        m_indNum++;
    }

    notify(VFX_TRUE);

    return MMI_RET_OK;
}



VfxBool SmsClass0NotifyManager::deleteInd(VfxU8 index)
{
    VFX_ASSERT(index < VAPP_SMS_MAX_CLASS0_IND_NUM);

    if (m_class0Provider[index].isUsed())
    {
		m_class0Provider[index].setUsed(VFX_FALSE);
        m_indNum--;
    }

    return VFX_TRUE;
}


void SmsClass0NotifyManager::getContent(VfxU8 index, VfxWString &content)
{
    content.loadFromMem(m_class0Provider[index].getContent());
}


void SmsClass0NotifyManager::getFormatAddr(VfxU8 index, VfxWString &addr)
    {
    //update phone number
	VfxWChar header[SRV_SMS_MAX_ADDR_LEN + MMI_PHB_NAME_LENGTH + 30];
	VfxWChar number[SRV_SMS_MAX_ADDR_LEN + 1];
	VfxWChar name[MMI_PHB_NAME_LENGTH + 1];
	U16 addr_len;
	addr_len = mmi_asc_n_to_ucs2((S8*)number, (S8*)m_class0Provider[index].getAddress(), SRV_SMS_MAX_ADDR_LEN);
	if (addr_len)
        {
		number[addr_len/2 - 1] = '\0';
        }       
	else
{
		number[0] = '\0';
    }
	srv_phb_get_name_by_number((U16*)number, (U16*)name, MMI_PHB_NAME_LENGTH);
	mmi_ucs2cpy((S8*)header, (S8*)GetString(STR_ID_VAPP_SMS_POPUP_FROM));
	if (name[0])
	{
		mmi_ucs2cat((S8*)header, (S8*)name);
		mmi_ucs2cat((S8*)header, (S8*)L"(");
		mmi_ucs2cat((S8*)header, (S8*)number);
	    mmi_ucs2cat((S8*)header, (S8*)L")");
}
	else
{
	    mmi_ucs2cat((S8*)header, (S8*)number);
}
	addr.loadFromMem(header);

}
void SmsClass0NotifyManager::getFormatTimestamp(VfxU8 index, VfxWString &timesatmp)
{
	VfxU32 timeInt = m_class0Provider[index].getTimestamp();
	MYTIME mytime;
	mmi_dt_utc_sec_2_mytime((U32)timeInt, &mytime, MMI_FALSE);
	VfxDateTime timeStamp;
	timeStamp.setDate(mytime.nYear, mytime.nMonth, mytime.nDay);
	timeStamp.setTime(mytime.nHour, mytime.nMin, mytime.nSec);
	VfxU32 flags = 0;
	VfxWChar temp[70];
	flags = VFX_DATE_TIME_DATE_YEAR |VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY | VFX_DATE_TIME_TIME_HOUR | VFX_DATE_TIME_TIME_MINUTE;
	timeStamp.getDateTimeString(flags, temp, 70);
	timesatmp.loadFromMem(temp);
}




VfxU8 SmsClass0NotifyManager::getNotifyIndex()
{
    VfxU8 index = VAPP_SMS_MAX_CLASS0_IND_NUM;
    VfxU32 timestamp = 0x01;

    for (VfxU8 i = 0; i < VAPP_SMS_MAX_CLASS0_IND_NUM; i++)
    {
        if (m_class0Provider[i].isUsed())
        {
            VfxU32 time = m_class0Provider[i].getTimestamp();

            if (time >= timestamp)
            {
                timestamp = time;
                index = i;
            }
        }
    }

    return index;
}

VfxU8 SmsClass0NotifyManager::findoldest()
{
    VfxU8 index = VAPP_SMS_MAX_CLASS0_IND_NUM;
    VfxU32 timestamp = 0xFFFFFFFF;

    for (VfxU8 i = 0; i < VAPP_SMS_MAX_CLASS0_IND_NUM; i++)
    {
        if (m_class0Provider[i].isUsed())
        {
            VfxU32 time = m_class0Provider[i].getTimestamp();

            if (time < timestamp)
            {
                timestamp = time;
                index = i;
            }
        }
    }

    return index;
}

void SmsClass0NotifyManager::save(VfxU8 index)
{

    SMS_HANDLE sms_handle = srv_sms_get_save_handle();

    srv_sms_set_content(sms_handle, (S8*)m_class0Provider[index].getContent(), m_class0Provider[index].getContentLength());

    srv_sms_set_status(sms_handle, SRV_SMS_STATUS_READ);
 
    if (m_class0Provider[index].getFo() & 0x20)
    {
        srv_sms_set_status_report(sms_handle, MMI_TRUE);
    }
    if (m_class0Provider[index].getFo() & 0x80)
    {
        srv_sms_set_reply_path(sms_handle, MMI_TRUE);
    }

    applib_time_struct timestamp;
    mmi_dt_utc_sec_2_mytime(m_class0Provider[index].getTimestamp(), &timestamp, MMI_FALSE);
    srv_sms_set_save_timestamp(sms_handle, (MYTIME*)&timestamp);

    U16 ucs2_addr[SRV_SMS_MAX_ADDR_LEN + 1];
    U16 addr_len;

    addr_len = mmi_asc_n_to_ucs2((S8*)ucs2_addr, (S8*)m_class0Provider[index].getAddress(), SRV_SMS_MAX_ADDR_LEN);
    if (addr_len)
    {
        ucs2_addr[addr_len/2 - 1] = '\0';
    }
    else
    {
        ucs2_addr[0] = '\0';
    }
    srv_sms_set_address(sms_handle, (S8*)ucs2_addr);

    addr_len = mmi_asc_n_to_ucs2((S8*)ucs2_addr, (S8*)m_class0Provider[index].getScAddress(), SRV_SMS_MAX_ADDR_LEN);
    if (addr_len)
    {
        ucs2_addr[addr_len/2 - 1] = '\0';
    }
    else
    {
        ucs2_addr[0] = '\0';
    }
    srv_sms_set_sc_address(sms_handle, (S8*)ucs2_addr);

    srv_sms_set_sim_id(sms_handle, m_class0Provider[index].getSimId());

    srv_sms_save_msg(
        sms_handle,
        &SmsClass0NotifyManager::SaveCallback,
        NULL);
}

void SmsClass0NotifyManager::SaveCallback(srv_sms_callback_struct* callback_data)
{

    SmsClass0NotifyManager *class0Manager = VFX_OBJ_GET_INSTANCE(SmsClass0NotifyManager);

    if (callback_data->result == MMI_TRUE)
    {
        class0Manager->m_signalClass0Saved.postEmit(VFX_TRUE, callback_data->cause);
    }
    else
    {
        class0Manager->m_signalClass0Saved.postEmit(VFX_FALSE, callback_data->cause);
    }
}

void SmsClass0NotifyManager::notify(VfxBool isNew)
{
    if (m_indNum)
    {
        if (isNew)
        {
                
            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_NEW_CLASS0_SMS,
                MMI_EVENT_SIM1_NEW_CLASS0_SMS,
                vapp_sms_class0_scrn_entry,
                NULL);
        }
        else
        {
            mmi_frm_nmgr_notify_by_app(
                MMI_SCENARIO_ID_NEW_CLASS0_SMS,
                MMI_EVENT_NON_TONE,
                vapp_sms_class0_scrn_entry,
                NULL);
        }
    }
	else
	{
		VfxApp *class0App = getRelatedApp();
		if (class0App)
		{
			VfxAppLauncher::terminate(class0App->getGroupId());
		}
	}

}



/***************************************************************************** 
* Class SmsMsgWaitingManager
*****************************************************************************/
void VappSmsWaitingMsgCallback(VsrvNotification* noti, VsrvNIntent intent, void* userData, VfxU32 userDataSize)
{
	SmsWaitingMsgUserData *mydata = (SmsWaitingMsgUserData *)userData;
	SmsMsgWaitingManager *msgWaiting = VFX_OBJ_GET_INSTANCE(SmsMsgWaitingManager);
	

	switch (intent.type)
	{
		case VSRV_NINTENT_TYPE_LAUNCH:
			{
				msgWaiting->setCurrentActionData(mydata);
				if (mydata->type == VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND)
				{
					msgWaiting->callVoicemail();
				}
			}
			break;
	#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__
			
		case VSRV_NINTENT_TYPE_TAP:
{
				if (mydata->type != VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND)
				{
					msgWaiting->clearCells(mydata);
				}
			}
			break;
	#endif
		case VSRV_NINTENT_TYPE_CLEAR:
			
			{
				msgWaiting->clearCells(mydata);
			}
			break;
		case VSRV_NINTENT_TYPE_LANGUAGE_CHANGED:
			{
				msgWaiting->notify(mydata->sim, mydata->line, mydata->type, VFX_TRUE);
			}
			break;
		default:
			break;
	}

}


//VFX_IMPLEMENT_CLASS("SmsMsgWaitingManager", SmsMsgWaitingManager, VfxObject);
VFX_OBJ_IMPLEMENT_SINGLETON_CLASS(SmsMsgWaitingManager);

SmsMsgWaitingManager::SmsMsgWaitingManager():
    m_indNum(0),
    m_suportLine(MMI_TRUE)
{
    memset(m_msgWaitingInfo, 0, sizeof(MsgWaitingData)*VAPP_SMS_TOTAL_SIM*VAPP_SMS_MSG_WAITING_LINE_NUM*VAPP_SMS_MAX_MSG_WAITING_TYPE);

    S16 error;
    if (ReadValue(VAPP_SMS_MSG_WAITING_HIDE_FLAG, &m_hideFlag, DS_DOUBLE, &error) < 0)
    {
        VFX_ASSERT(0);
    }
}

void SmsMsgWaitingManager::onInit()
{
	for (VfxS32 index = 0; index <= VAPP_SMS_MAX_MSG_WAITING_TYPE; index++)
	{
		m_notifyHandle[index] = NULL;
	}
}
void SmsMsgWaitingManager::setCurrentActionData(SmsWaitingMsgUserData *userData)
{
	m_currentActionData.sim = userData->sim;
	m_currentActionData.line = userData->line;
}

VfxBool SmsMsgWaitingManager::getHideFlag(mmi_sim_enum mmi_sim, VfxU8 lineNo, VfxU8 waitingType)
{
    U32 flagIndex = 0;
#if (MMI_MAX_SIM_NUM >= 2)
    flagIndex = mmi_frm_sim_to_index(mmi_sim) *VAPP_SMS_MSG_WAITING_LINE_NUM *VAPP_SMS_MAX_MSG_WAITING_TYPE;
#endif
    flagIndex = flagIndex+ waitingType * VAPP_SMS_MSG_WAITING_LINE_NUM + lineNo;
    
    VFX_ASSERT(flagIndex < 64);

    if ((m_hideFlag>>flagIndex)&0x01)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

void SmsMsgWaitingManager::setHideFlag(mmi_sim_enum mmi_sim, VfxU8 lineNo, VfxU8 waitingType, VfxBool hideFlag)
{
    U32 flagIndex = 0;
#if (MMI_MAX_SIM_NUM >= 2)
    flagIndex = mmi_frm_sim_to_index(mmi_sim) *VAPP_SMS_MSG_WAITING_LINE_NUM *VAPP_SMS_MAX_MSG_WAITING_TYPE;
#endif
    flagIndex = flagIndex+ waitingType * VAPP_SMS_MSG_WAITING_LINE_NUM + lineNo;

    VFX_ASSERT(flagIndex < 64);

    if (hideFlag)
    {
        m_hideFlag |= (U64)1<<flagIndex;
    }
    else
    {
        m_hideFlag &= ~((U64)1<<flagIndex);
    }

    S16 error;
    if (WriteValue(VAPP_SMS_MSG_WAITING_HIDE_FLAG, &m_hideFlag, DS_DOUBLE, &error) < 0)
    {
        VFX_ASSERT(0);
    }
}

void SmsMsgWaitingManager::addNewInd(VappSmsMsgWaitingData *info, srv_sms_sim_enum simId)
{
    VfxU8 simIndex = vapp_sms_sim_id_to_sim_index(simId);

    MsgWaitingData *addInfo = &m_msgWaitingInfo[simIndex][info->lineNo][info->indType];
    mmi_sim_enum mmi_sim = vapp_sms_sim_id_to_mmi_sim(simId);



    if (info->indType < VAPP_SMS_MAX_MSG_WAITING_TYPE)
    {
        addInfo->waitingNum = info->waitingNum;
        addInfo->indType = info->indType;
        addInfo->isShowNum = info->isShowNum;
        addInfo->isValid = MMI_TRUE;

        if (addInfo->isShowNum && addInfo->waitingNum == 0xFF)
        {
            addInfo->isShowNum = VFX_FALSE; 
            addInfo->waitingNum = 0;
        }

        vapp_msg_waiting_line_id_enum lineId = VAPP_MSG_WAITING_NOT_SUPPORT;

        if (info->lineNo == 1)
        {
            lineId = VAPP_MSG_WAITING_LINE2;
        }
        else
        {
            lineId = VAPP_MSG_WAITING_LINE1;
        }
        if (info->isfromStorage)
        {
        		return;
            /*if (getHideFlag(mmi_sim, info->lineNo, info->indType))
            {
                return;
            }

            //only show status icon
			mmi_frm_nmgr_alert_struct alert_info;
			memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));
			alert_info.app_id = VAPP_MSG;
			alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
			alert_info.behavior_mask = FORCE_ICON_ONLY;
			alert_info.status_bar_icon_para.icon_id = statusIcon[info->indType];


			
			m_notifyHandle[info->indType] = mmi_frm_nmgr_alert(&alert_info);*/

        }
        else
        {
            


            U16 stringId = 0;

			mmi_rp_app_vapp_sms_str_enum str[] =
				{
					STR_ID_VAPP_SMS_NEW_VOCIEMAIL_WAITING,
				#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__
					STR_ID_VAPP_SMS_NEW_FAX_WAITING,
					STR_ID_VAPP_SMS_NEW_EMAIL_WAITING,
					STR_ID_VAPP_SMS_NEW_NET_MSG_WAITING,
					STR_ID_VAPP_SMS_NEW_VEDIO_WAITING
				#endif
				};
			stringId = str[addInfo->indType];
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
			#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
		#endif

            VfxWChar temp[VAPP_SMS_NOTIFY_MAX_PREVIEW_TEXT_LEN+1];
            mmi_ucs2cpy((CHAR *)temp, GetString(stringId));

            if (addInfo->indType == VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND)
            {
                VfxWChar number[MAX_CC_ADDR_LEN + 1];
                VfxWChar name[SRV_SMS_MAX_PROFILE_NAME_LEN + 1];

                if (VAPP_MSG_WAITING_LINE2 == lineId)
                {
                    mmi_ucs2cpy((S8*)name, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_name[1]);
                    mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_number[1]);
                }
                else
                {
                    mmi_ucs2cpy((S8*)name, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_name[0]);
                    mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_number[0]);
                }

                if (name[0] != '\0')
                {
                    mmi_ucs2cpy((S8*)temp, (S8*)GetString(STR_ID_VAPP_SMS_NEW_VOCIEMAIL_WAITING_FROM));
                    mmi_ucs2cat((S8*)temp, (S8*)name);
                }
                else if (number[0] != '\0')
                {
                    mmi_ucs2cpy((S8*)temp, GetString(STR_ID_VAPP_SMS_NEW_VOCIEMAIL_WAITING_FROM));
                    mmi_ucs2cat((S8*)temp, (S8*)number);
                }
            }

            //notification_para.text = temp;

            setHideFlag(mmi_sim, info->lineNo, info->indType, VFX_FALSE);

			
			mmi_frm_nmgr_alert_struct alert_info;
			memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));
			if (addInfo->indType == VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND)
			{
				alert_info.app_id = VAPP_MSG;
				alert_info.alert_option = 0;
				alert_info.scen_id = MMI_SCENARIO_ID_MESSAGE_WAITING;
				alert_info.event_type = eventType[simIndex][info->indType];
				alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK | MMI_FRM_NMGR_UI_STATUS_BAR_MASK | MMI_FRM_NMGR_UI_POPUP_MASK;
				alert_info.behavior_mask = PREFER_STATUS_BAR;
				alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
				alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
			#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
				alert_info.status_bar_para.image.id = statusPreviewIcon[info->indType];
			#else
				alert_info.status_bar_para.image.id = IMG_SI_COMMON_NEW;
			#endif
				alert_info.status_bar_para.display_string = temp;
				alert_info.status_bar_icon_para.icon_id = statusIcon[info->indType];

			    alert_info.app_proc_para.scrn_group_proc = &vapp_sms_call_voicemail_launch;
				SmsWaitingMsgUserData userdata;
				userdata.sim = mmi_sim;
				userdata.line = lineId;
				userdata.type = (vapp_sms_msg_waiting_type_enum)addInfo->indType;
			    alert_info.app_proc_para.user_data = &userdata;
			    alert_info.app_proc_para.data_size = sizeof (SmsWaitingMsgUserData);

				
			    alert_info.popup_para.popup_type = MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE;
			    alert_info.popup_para.image_type = MMI_NMGR_IMG_RES_ID;
			    alert_info.popup_para.image.id = IMG_SI_MESSAGE_UNREAD;
				VfxWString titleStr;
				vapp_sms_voicemail_get_popup_str(&userdata, titleStr);
			    alert_info.popup_para.popup_string = titleStr.getBuf();
			    VfxWString button_string;
				button_string.loadFromRes(STR_ID_VAPP_SMS_VM_CALL_VOICE);
			    alert_info.popup_para.popup_button_string = button_string.getBuf();
				m_notifyHandle[info->indType] = mmi_frm_nmgr_alert(&alert_info);
			}
		#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__
			else
			{
			alert_info.app_id = VAPP_MSG;
			alert_info.scen_id = MMI_SCENARIO_ID_MESSAGE_WAITING;
			alert_info.event_type = eventType[simIndex][info->indType];
			alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK | MMI_FRM_NMGR_UI_STATUS_BAR_MASK;
			alert_info.behavior_mask = FORCE_STATUS_BAR;
			alert_info.status_bar_para.status_bar_type = MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE;
			alert_info.status_bar_para.image_type = MMI_NMGR_IMG_RES_ID;
	    #ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
			alert_info.status_bar_para.image.id = statusPreviewIcon[info->indType];
		#else
			alert_info.status_bar_para.image.id = IMG_SI_COMMON_NEW;
		#endif
			alert_info.status_bar_para.display_string = temp;
			alert_info.status_bar_icon_para.icon_id = statusIcon[info->indType];			
			m_notifyHandle[info->indType] = mmi_frm_nmgr_alert(&alert_info);
        }
		#endif
        }
        notify(mmi_sim, lineId, (vapp_sms_msg_waiting_type_enum)addInfo->indType, VFX_TRUE);
    }
}

void SmsMsgWaitingManager::clearInd(VappSmsMsgWaitingData *info, srv_sms_sim_enum simId, VfxBool needCloseCell)
{
    VfxU8 simIndex = vapp_sms_sim_id_to_sim_index(simId);

    MsgWaitingData *clearInfo = &m_msgWaitingInfo[simIndex][info->lineNo][info->indType];
    
    memset(clearInfo, 0, sizeof(MsgWaitingData));

    VfxBool hideIcon = VFX_TRUE;
    VfxU8 index;

    for (index = 0; index < VAPP_SMS_TOTAL_SIM; index++)
    {
        mmi_sim_enum curSim = vapp_sms_sim_index_to_mmi_sim(index);

        if (checkIsValid(curSim, VAPP_MSG_WAITING_LINE1, (vapp_sms_msg_waiting_type_enum)info->indType))
        {
            hideIcon = VFX_FALSE;
            break;
        }
        else if (checkIsValid(curSim, VAPP_MSG_WAITING_LINE2, (vapp_sms_msg_waiting_type_enum)info->indType))
        {
            hideIcon = VFX_FALSE;
            break;
        }
    }


    if (hideIcon)
    {
    	if (m_notifyHandle[info->indType])
    	{
        	mmi_frm_nmgr_alert_cancel(m_notifyHandle[info->indType]); //cancel preview and status icon
        	m_notifyHandle[info->indType] = NULL;
		}
    }

    vapp_msg_waiting_line_id_enum lineId = VAPP_MSG_WAITING_NOT_SUPPORT;
    
    if (info->lineNo == 1)
    {
        lineId = VAPP_MSG_WAITING_LINE2;
    }
    else
    {
        lineId = VAPP_MSG_WAITING_LINE1;
    }

    mmi_sim_enum mmi_sim = vapp_sms_sim_id_to_mmi_sim(simId);

    setHideFlag(mmi_sim, info->lineNo, info->indType, VFX_TRUE);

	if (needCloseCell)
	{
		notify(mmi_sim, lineId, (vapp_sms_msg_waiting_type_enum)info->indType, VFX_FALSE);
	}

}

VfxBool SmsMsgWaitingManager::checkIsValid(mmi_sim_enum sim, vapp_msg_waiting_line_id_enum lineId, VfxU8 WaitingType)
{
	srv_sms_sim_enum sim_id = vapp_sms_mmi_sim_to_sim_id(sim);
	
    VfxU8 simIndex = vapp_sms_sim_id_to_sim_index(sim_id);
	

    VfxU8 line;

    if (lineId == VAPP_MSG_WAITING_LINE2)
    {
        line = 1;
    }
    else
    {
        line = 0;
    }

    return (m_msgWaitingInfo[simIndex][line][WaitingType].isValid && !getHideFlag(sim, line, WaitingType));
}

VfxBool SmsMsgWaitingManager::checkIsShowNum(mmi_sim_enum sim, vapp_msg_waiting_line_id_enum lineId, VfxU8 WaitingType)
{

    VfxBool showNum = VFX_TRUE;
	srv_sms_sim_enum sim_id = vapp_sms_mmi_sim_to_sim_id(sim);
	
    VfxU8 simIndex = vapp_sms_sim_id_to_sim_index(sim_id);



    VfxU8 line;

    if (lineId == VAPP_MSG_WAITING_NOT_SUPPORT)
    {
        MsgWaitingData *info[VAPP_SMS_MSG_WAITING_LINE_NUM];
        info[0] = &(m_msgWaitingInfo[simIndex][0][WaitingType]);
        info[1] = &(m_msgWaitingInfo[simIndex][0][WaitingType]);

        if ((info[0]->isValid && !(info[0]->isShowNum))
            || (info[1]->isValid && !(info[1]->isShowNum))
            )
        {
            showNum = VFX_FALSE;
        }
    }
    else
    {
        if (lineId == VAPP_MSG_WAITING_LINE2)
        {
            line = 1;
        }
        else
        {
            line = 0;
        }

        showNum = m_msgWaitingInfo[simIndex][line][WaitingType].isShowNum;
    }

    return showNum;
}

VfxU8 SmsMsgWaitingManager::getWaitingNum(mmi_sim_enum sim, vapp_msg_waiting_line_id_enum lineId, VfxU8 WaitingType)
{
	srv_sms_sim_enum sim_id = vapp_sms_mmi_sim_to_sim_id(sim);
	
    VfxU8 simIndex = vapp_sms_sim_id_to_sim_index(sim_id);



    VfxU8 line;

    if (lineId == VAPP_MSG_WAITING_LINE2)
    {
        line = 1;
    }
    else
    {
        line = 0;
    }

    return m_msgWaitingInfo[simIndex][line][WaitingType].waitingNum;
}

void SmsMsgWaitingManager::notify(mmi_sim_enum sim, //sim
        vapp_msg_waiting_line_id_enum line, // lineId
        vapp_sms_msg_waiting_type_enum type, //msg waiting type
        VfxBool isShow)
{
	VsrvNotificationId noti_id = getNotificationId(sim, line, type);
	VsrvNGroupSingleTitle *group = NULL;
	VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_MSG));
	group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_MSG));

	SmsWaitingMsgUserData userdata;
	userdata.sim = sim;
	userdata.line = line;
	userdata.type = type;
	if (isShow)
	{
		VsrvNotificationEvent *noti = NULL;
		VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroup *)group, noti_id));
		noti->setIntentCallback(VappSmsWaitingMsgCallback, &userdata, sizeof(SmsWaitingMsgUserData));
		
		if (type == VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND)
		{
			noti->setAutoClose(VFX_FALSE);
			setVoicemailContent(noti, sim, line, type);
			VfxDateTime dateTime;
			dateTime.setCurrentTime();
			noti->setTimeStamp(dateTime);
			noti->notify();
		}
	#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__
		else
		{
			noti->setAutoLaunch(VFX_FALSE);
			setOtherWaitngMsgContent(noti, sim, line, type);
		VfxDateTime dateTime;
		dateTime.setCurrentTime();
		noti->setTimeStamp(dateTime);
		noti->notify();
	}
	#endif

	}
	else
	{
        VsrvNCenter *nm = VFX_OBJ_GET_INSTANCE(VsrvNCenter);
        VsrvNotificationEvent *noti = (VsrvNotificationEvent *)nm->queryNotification(group, noti_id);
		if (checkIsValid(sim, VAPP_MSG_WAITING_LINE1, type) || checkIsValid(sim, VAPP_MSG_WAITING_LINE2, type))
		{
			if (type == VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND)
			{
				setVoicemailContent(noti, sim, line, type);
			}
		#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__
			else
			{
				setOtherWaitngMsgContent(noti, sim, line, type);
			}
		#endif
			VfxDateTime dateTime;
			dateTime.setCurrentTime();
			noti->setTimeStamp(dateTime);
			noti->notify();
		}
		else
		{
			VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_MSG, noti_id);
		}

	}
}
VsrvNotificationId SmsMsgWaitingManager::getNotificationId(mmi_sim_enum sim, //sim
        vapp_msg_waiting_line_id_enum line, // lineId
        vapp_sms_msg_waiting_type_enum type)
{
	srv_sms_sim_enum sim_id = vapp_sms_mmi_sim_to_sim_id(sim);
	
    VfxU8 offset = vapp_sms_sim_id_to_sim_index(sim_id);


	VfxU32 id = 0;
	if (type == VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND)
	{
		id = VAPP_MSG_NCENTER_SMS_WAITING_CELL_BEGIN + MMI_MAX_SIM_NUM * (line - 1) + offset;
	}
	else
	{
		VfxU32 voicemailWaitingCellNumBase = MMI_MAX_SIM_NUM * (VAPP_MSG_WAITING_LINE_END - 1);
		id = VAPP_MSG_NCENTER_SMS_WAITING_CELL_BEGIN + voicemailWaitingCellNumBase + MMI_MAX_SIM_NUM * (type - VAPP_SMS_NEW_FAX_WAITING_IND) + offset;
	}
	return (VsrvNotificationId)id;
}

void SmsMsgWaitingManager::setVoicemailContent(VsrvNotificationEvent *noti, 
		mmi_sim_enum sim, //sim
        vapp_msg_waiting_line_id_enum line,
        vapp_sms_msg_waiting_type_enum type)
{
    VfxBool isShowNum = checkIsShowNum(sim, line, type);
    VfxU8 waitingNum = 0;
    if (isShowNum)
    {
        waitingNum = getWaitingNum(sim, line, type);
    }

    VfxResId stringId = 0;
    VfxWChar temp[40];

    if (isShowNum && (waitingNum >= 1))
    {
        if (waitingNum == 1)
        {
            if (VAPP_MSG_WAITING_LINE2 == line)
            {
                stringId = STR_ID_VAPP_SMS_LINE2_VOICEMAIL_NUM_IND;
            }
            else
            {
                stringId = STR_ID_VAPP_SMS_NEW_VOICEMAIL_NUM_IND;
            }
        }
        else
        {
            if (VAPP_MSG_WAITING_LINE2 == line)
            {
                stringId = STR_ID_VAPP_SMS_LINE2_VOICEMAIL_NUM_IND_PLURAL;
            }
            else
            {
                stringId = STR_ID_VAPP_SMS_NEW_VOICEMAIL_NUM_IND_PLURAL;
            }
        }
    }
    else
    {
        if (VAPP_MSG_WAITING_LINE2 == line)
        {
            stringId = STR_ID_VAPP_SMS_LINE2_NEW_VOCIEMAIL_WAITING;
        }
        else
        {
            stringId = STR_ID_VAPP_SMS_NEW_VOCIEMAIL_WAITING;
        }
    }

    if (isShowNum && (waitingNum >= 1))
{
        U8 ascii_num[10];
        memset(ascii_num, 0, 10);
        sprintf((S8*)ascii_num, "%d ", waitingNum);
        mmi_asc_to_ucs2((S8*) temp, (S8*) ascii_num);
        mmi_ucs2cat((S8*)temp, (S8*)GetString(stringId));
    }
    else
    {
        mmi_ucs2cpy((S8*)temp, (S8*)GetString(stringId));
    }


    VfxWChar number[MAX_CC_ADDR_LEN + 1];
    VfxWChar name[SRV_SMS_MAX_PROFILE_NAME_LEN + 1];
	VfxWString simStr;


	srv_sms_sim_enum simId = vapp_sms_mmi_sim_to_sim_id(sim);
	
    VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(simId);
	STR_GLOBAL_LIST_ENUM str[] =
		{
			STR_GLOBAL_SIM_1,
		#if (MMI_MAX_SIM_NUM >= 2)
			STR_GLOBAL_SIM_2,
		#if (MMI_MAX_SIM_NUM >= 3)
			STR_GLOBAL_SIM_3,
		#if (MMI_MAX_SIM_NUM >= 4)
			STR_GLOBAL_SIM_4
		#endif
		#endif
		#endif
		};
	
	simStr.loadFromRes(str[sim_index]);

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
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
	noti->setIcon(VfxImageSrc(IMG_ID_VAPP_MSG_NCENTER_UNREAD));
	VfxWString tempStr;
	tempStr.loadFromMem(temp);

	if (!simStr.isEmpty())
	{
        tempStr += VFX_WSTR("(");
        tempStr += simStr;
        tempStr += VFX_WSTR(")");
	}

	noti->setMainText(tempStr);

    if (VAPP_MSG_WAITING_LINE2 == line)
    {
        mmi_ucs2cpy((S8*)name, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_name[1]);
        mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_number[1]);
    }
    else
    {
        mmi_ucs2cpy((S8*)name, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_name[0]);
        mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_number[0]);
    }

    if (name[0] != '\0')
    {
        noti->setSubText(VFX_WSTR_MEM(name));
    }
    else if (number[0] != '\0')
    {
        noti->setSubText(VFX_WSTR_MEM(number));
    }
    else
    {
        noti->setSubText(VFX_WSTR_RES(STR_GLOBAL_EMPTY));
    }
}

#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__

void SmsMsgWaitingManager::setOtherWaitngMsgContent(VsrvNotificationEvent *noti, 
	mmi_sim_enum sim, //sim
	vapp_msg_waiting_line_id_enum line,
	vapp_sms_msg_waiting_type_enum type)
{

	VfxBool isShowNum = checkIsShowNum(sim, line, type);
	VfxU16 waitingNum = 0;
	if (isShowNum)
	{
		if (VAPP_MSG_WAITING_NOT_SUPPORT == line)
		{
			if (checkIsValid(sim, VAPP_MSG_WAITING_LINE2, type))
			{
				waitingNum += getWaitingNum(sim, VAPP_MSG_WAITING_LINE2, type);
			}

			if (checkIsValid(sim, VAPP_MSG_WAITING_LINE1, type))
			{
				waitingNum += getWaitingNum(sim, VAPP_MSG_WAITING_LINE1, type);
			}
		}
		else
		{
			waitingNum = getWaitingNum(sim, line, type);

			if (VAPP_MSG_WAITING_LINE1 == line)
			{
				if (checkIsValid(sim, VAPP_MSG_WAITING_LINE2, type))
				{
					waitingNum += getWaitingNum(sim, VAPP_MSG_WAITING_LINE2, type);
				}
			}
			else if (VAPP_MSG_WAITING_LINE2 == line)
			{
				if (checkIsValid(sim, VAPP_MSG_WAITING_LINE1, type))
				{
					waitingNum += getWaitingNum(sim, VAPP_MSG_WAITING_LINE1, type);
				}
			}
		}
	}

	VfxResId stringId = 0;
	VfxWChar temp[40];

	if (isShowNum && (waitingNum >= 1) && (waitingNum < 255))
	{
		if (waitingNum == 1)
		{
			mmi_rp_app_vapp_sms_str_enum str[] =
				{
					STR_ID_VAPP_SMS_NEW_VOICEMAIL_NUM_IND,
				#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__
					STR_ID_VAPP_SMS_NEW_FAX_NUM_IND,
					STR_ID_VAPP_SMS_NEW_EMAIL_NUM_IND,
					STR_ID_VAPP_SMS_NEW_NET_MSG_NUM_IND,
					STR_ID_VAPP_SMS_NEW_VEDIO_NUM_IND
				#endif
				};
			stringId = str[type];
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
		}
		else
		{
			mmi_rp_app_vapp_sms_str_enum str[] =
				{
					STR_ID_VAPP_SMS_NEW_VOICEMAIL_NUM_IND_PLURAL,
				#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__
					STR_ID_VAPP_SMS_NEW_FAX_NUM_IND_PLURAL,
					STR_ID_VAPP_SMS_NEW_EMAIL_NUM_IND_PLURAL,
					STR_ID_VAPP_SMS_NEW_NET_MSG_NUM_IND_PLURAL,
					STR_ID_VAPP_SMS_NEW_VEDIO_NUM_IND_PLURAL
				#endif
				};
			stringId = str[type];
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
		}
	}
	else
	{
		mmi_rp_app_vapp_sms_str_enum str[] =
			{
				STR_ID_VAPP_SMS_NEW_VOCIEMAIL_WAITING,
			#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__
				STR_ID_VAPP_SMS_NEW_FAX_WAITING,
				STR_ID_VAPP_SMS_NEW_EMAIL_WAITING,
				STR_ID_VAPP_SMS_NEW_NET_MSG_WAITING,
				STR_ID_VAPP_SMS_NEW_VEDIO_WAITING
			#endif
			};
		stringId = str[type];
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
	}

	if (isShowNum && (waitingNum >= 1) && (waitingNum < 255))
	{
		U8 ascii_num[10];
		memset(ascii_num, 0, 10);
		sprintf((S8*)ascii_num, "%d ", waitingNum);
		mmi_asc_to_ucs2((S8*) temp, (S8*) ascii_num);
		mmi_ucs2cat((S8*)temp, (S8*)GetString(stringId));
	}
	else
	{
		mmi_ucs2cpy((S8*)temp, (S8*)GetString(stringId));
	}

	noti->setMainText(VFX_WSTR_MEM(temp));

	srv_sms_sim_enum sim_id = vapp_sms_mmi_sim_to_sim_id(sim);
	
    VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(sim_id);
	STR_GLOBAL_LIST_ENUM str[] =
		{
			STR_GLOBAL_SIM_1,
		#if (MMI_MAX_SIM_NUM >= 2)
			STR_GLOBAL_SIM_2,
		#if (MMI_MAX_SIM_NUM >= 3)
			STR_GLOBAL_SIM_3,
		#if (MMI_MAX_SIM_NUM >= 4)
			STR_GLOBAL_SIM_4
		#endif
		#endif
		#endif
		};
	noti->setSubText(VFX_WSTR_RES(str[sim_index]));


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
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#endif
	noti->setIcon(VfxImageSrc(IMG_ID_VAPP_MSG_NCENTER_UNREAD));
}
#endif
void SmsMsgWaitingManager::callVoicemail()
{
	mmi_sim_enum sim = m_currentActionData.sim;
	vapp_msg_waiting_line_id_enum line = m_currentActionData.line;
    VfxBool isShowNum = checkIsShowNum(sim, line, VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND);
    VfxU8 waitingNum = 0;
    if (isShowNum)
    {
        waitingNum = getWaitingNum(sim, line, VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND);
    }

    VfxWChar number[MAX_CC_ADDR_LEN + 1];
    VfxWChar name[SRV_SMS_MAX_PROFILE_NAME_LEN + 1];
    VfxWChar temp[SRV_SMS_MAX_PROFILE_NAME_LEN + 40];

	srv_sms_sim_enum simId = vapp_sms_mmi_sim_to_sim_id(sim);
	VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(simId);
	VfxResId stringId = vapp_sms_voicemail_get_numstr_id(isShowNum, waitingNum, sim_index);

#if 0
#if (MMI_MAX_SIM_NUM == 1)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif
/* under construction !*/
#endif

    if (VAPP_MSG_WAITING_LINE2 == line)
    {
        mmi_ucs2cpy((S8*)name, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_name[1]);
        mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_number[1]);
    }
    else
    {
        mmi_ucs2cpy((S8*)name, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_name[0]);
        mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_number[0]);
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
#endif

    {
        if (isShowNum && (waitingNum >= 1))
        {
            U8 ascii_num[10];
            memset(ascii_num, 0, 10);
            sprintf((S8*)ascii_num, "%d ", waitingNum);
            mmi_asc_to_ucs2((S8*) temp, (S8*) ascii_num);
            mmi_ucs2cat((S8*)temp, (S8*)GetString(stringId));
        }
        else
        {
            mmi_ucs2cpy((S8*)temp, (S8*)GetString(stringId));
        }

        if (name[0] != '\0')
        {
            mmi_ucs2cat((S8*)temp, (S8*)GetString(STR_ID_VAPP_SMS_NEW_VOICEMAIL_FROM));
            mmi_ucs2cat((S8*)temp, (S8*)name);
        }
        else if (number[0] != '\0')
        {
            mmi_ucs2cat((S8*)temp, (S8*)GetString(STR_ID_VAPP_SMS_NEW_VOICEMAIL_FROM));
            mmi_ucs2cat((S8*)temp, (S8*)number);
        }

        vcp_global_popup_show_confirm_two_button_str(
            GRP_ID_ROOT,
            VCP_POPUP_TYPE_INFO,
            VFX_WSTR_MEM(temp),
            VFX_WSTR_RES(STR_ID_VAPP_SMS_VM_CALL_VOICE),
            VFX_WSTR_RES(STR_GLOBAL_CANCEL),
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_CANCEL,
            &SmsMsgWaitingManager::onPopupButtonClick,
            NULL);
    }

	//clearCells(&m_currentActionData);
}

void SmsMsgWaitingManager::clearCells(SmsWaitingMsgUserData *data)
{
	if (data->type == VAPP_SMS_NEW_VOCIEMAIL_WAITING_IND)
	{
	    VappSmsMsgWaitingData info;
	    info.lineNo = data->line - 1;
	    info.indType = data->type;
		clearInd(&info, SRV_SMS_MMI_SIM_TO_SMS(data->sim), VFX_TRUE);
	}
#ifdef __MMI_SMS_SUPPORT_OTHER_WAITING_MSG__

	else
	{
	    for (VfxU8 lineNo = 0; lineNo < VAPP_SMS_MSG_WAITING_LINE_NUM; lineNo++)
	    {
	        VappSmsMsgWaitingData info;
	        info.lineNo = lineNo;
	        info.indType = data->type;
	        clearInd(&info, SRV_SMS_MMI_SIM_TO_SMS(data->sim), VFX_FALSE);
	    }
	}
#endif
}

void SmsMsgWaitingManager::onPopupButtonClick(VfxId id, void *userData)
{
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
		SmsMsgWaitingManager *msgWaitingManager = VFX_OBJ_GET_INSTANCE(SmsMsgWaitingManager);
		msgWaitingManager->clearCells(&(msgWaitingManager->m_currentActionData));
		mmi_sim_enum sim = msgWaitingManager->m_currentActionData.sim;
		vapp_msg_waiting_line_id_enum line = msgWaitingManager->m_currentActionData.line;

        VfxWChar number[MAX_CC_ADDR_LEN + 1];


		srv_sms_sim_enum simId = vapp_sms_mmi_sim_to_sim_id(sim);


        if (VAPP_MSG_WAITING_LINE2 == line)
        {
            mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_number[1]);
        }
        else
        {
            mmi_ucs2cpy((S8*)number, (S8*)srv_sms_get_mailbox_setting(simId)->p_mailbox_number[0]);
        }


	
	    if (number[0] == '\0')
	    {
	        vapp_nmgr_global_popup_show_confirm_one_button_id(
	            MMI_SCENARIO_ID_DEFAULT,
	            VCP_POPUP_TYPE_FAILURE,
	            STR_GLOBAL_NO_NUMBER,
	            STR_GLOBAL_OK,
	            VCP_POPUP_BUTTON_TYPE_NORMAL,
	            NULL,
	            NULL);
			return;
	    }

        mmi_ucm_make_call_para_struct make_call_para; 
        mmi_ucm_init_call_para(&make_call_para);
		VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(simId);
		srv_ucm_call_type_enum call_type[] = 
			{
				SRV_UCM_VOICE_CALL_TYPE,
			#if (MMI_MAX_SIM_NUM >= 2)
				SRV_UCM_VOICE_CALL_TYPE_SIM2,
			#if (MMI_MAX_SIM_NUM >= 3)
				SRV_UCM_VOICE_CALL_TYPE_SIM3,
			#if (MMI_MAX_SIM_NUM >= 4)
				SRV_UCM_VOICE_CALL_TYPE_SIM4
			#endif
			#endif
			#endif
			};

		make_call_para.dial_type = call_type[sim_index];

	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
	#endif
        make_call_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_VOICE_MAIL;
        make_call_para.ucs2_num_uri = (U16*)number;
        mmi_ucm_call_launch(0, &make_call_para);
    }
}


