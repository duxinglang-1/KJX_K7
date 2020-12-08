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
 *  vapp_sms_util.cpp
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "vapp_sms_util.h"
#include "vapp_sms_gprot.h"
#include "vapp_uc_gprot.h"
#include "vapp_nmgr_gprot.h"
#include "mmi_rp_app_vapp_sms_def.h"

#ifdef __MMI_SMS_COMPOSER__
    #include "vcui_sms_composer_gprot.h"
#endif


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmsSrvGprot.h"
    #include "UcSrvGprot.h"
    #include "CallSetSrvGprot.h"
    #include "app_usedetails.h"
    #include "UCMSrvGprot.h"
    #include "UCMGprot.h"
    #include "CphsSrvGprot.h"

typedef enum
{
    VAPP_SMS_SIM1 = 0,
    VAPP_SMS_SIM2 = 1,
    VAPP_SMS_SIM3 = 2,
    VAPP_SMS_SIM4 = 3
} VappSmsSimEnum;



srv_um_sim_enum vapp_sms_sim_id_to_um_sim(srv_sms_sim_enum simId)
{
	switch(simId)
	{
		case SRV_SMS_SIM_4:
			return SRV_UM_SIM_GSM_SIM4;
		case SRV_SMS_SIM_3:
			return SRV_UM_SIM_GSM_SIM3;
		case SRV_SMS_SIM_2:
			return SRV_UM_SIM_GSM_SIM2;
		default:
			return SRV_UM_SIM_GSM_SIM1;
	}
}

VfxU8 vapp_sms_sim_id_to_sim_index(srv_sms_sim_enum simId)
{
	switch(simId)
	{
		case SRV_SMS_SIM_4:
			return VAPP_SMS_SIM4;
		case SRV_SMS_SIM_3:
			return VAPP_SMS_SIM3;
		case SRV_SMS_SIM_2:
			return VAPP_SMS_SIM2;
		default:
			return VAPP_SMS_SIM1;			
	}
}


srv_sms_sim_enum vapp_sms_sim_index_to_sim_id(VfxU8 simIndex)
{
    VFX_ASSERT(simIndex < VAPP_SMS_TOTAL_SIM);
	switch(simIndex)
	{
		case VAPP_SMS_SIM4:
			return SRV_SMS_SIM_4;
		case VAPP_SMS_SIM3:
			return SRV_SMS_SIM_3;
		case VAPP_SMS_SIM2:
			return SRV_SMS_SIM_2;
		default:
			return SRV_SMS_SIM_1;		
	}

}

mmi_sim_enum vapp_sms_sim_index_to_mmi_sim(VfxU8 simIndex)
{
    VFX_ASSERT(simIndex < VAPP_SMS_TOTAL_SIM);
	switch(simIndex)
	{
		case VAPP_SMS_SIM4:
			return MMI_SIM4;
		case VAPP_SMS_SIM3:
			return MMI_SIM3;
		case VAPP_SMS_SIM2:
			return MMI_SIM2;
		default:
			return MMI_SIM1;		
	}	
}


mmi_sim_enum vapp_sms_sim_id_to_mmi_sim(srv_sms_sim_enum simId)
{
	switch(simId)
	{
		case SRV_SMS_SIM_4:
			return MMI_SIM4;
		case SRV_SMS_SIM_3:
			return MMI_SIM3;
		case SRV_SMS_SIM_2:
			return MMI_SIM2;
		default:
			return MMI_SIM1;					
	}

}

srv_sms_sim_enum vapp_sms_mmi_sim_to_sim_id(mmi_sim_enum sim)
{
    VFX_ASSERT((sim == MMI_SIM1) || (sim == MMI_SIM2) || (sim == MMI_SIM3) || (sim == MMI_SIM4));
	switch(sim)
	{
		case MMI_SIM4:
			return SRV_SMS_SIM_4;
		case MMI_SIM3:
			return SRV_SMS_SIM_3;
		case MMI_SIM2:
			return SRV_SMS_SIM_2;
		default:
			return SRV_SMS_SIM_1;			
	}
}


MMI_BOOL vapp_sms_resend_msg(U32 msg_id)
{
    MMI_BOOL result = MMI_FALSE;

#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
    srv_sms_status_enum curr_msg_status = srv_sms_get_msg_status(msg_id);
    srv_sms_send_status_enum send_status = srv_sms_get_unsent_msg_status(msg_id);

    if (curr_msg_status & SRV_SMS_STATUS_UNSENT)
    {
        if ((send_status == SRV_SMS_SEND_WAITING) || (send_status == SRV_SMS_SEND_SENDING))
        {
            result = MMI_TRUE;
        }
        else
        {
            result = srv_sms_set_unsent_msg_status((U16)msg_id, SRV_SMS_SEND_WAITING);
        }
    }
#endif

    return result;
}

MMI_BOOL vapp_sms_cancel_send_msg(U32 msg_id)
{
    MMI_BOOL result = MMI_FALSE;

#ifdef __SRV_SMS_BACKGROUND_SEND_SUPPORT__
    srv_sms_status_enum curr_msg_status = srv_sms_get_msg_status(msg_id);

    if (curr_msg_status & SRV_SMS_STATUS_UNSENT)
    {
        result = srv_sms_set_unsent_msg_status((U16)msg_id, SRV_SMS_SEND_FAIL);
    }
#endif

    return result;
}

MMI_BOOL vapp_sms_check_is_voicemail_valid(mmi_sim_enum mmi_sim)
{
    srv_sms_sim_enum simId = vapp_sms_mmi_sim_to_sim_id(mmi_sim);

    srv_callset_line_id_enum lineId = srv_callset_line_switch_get_id(mmi_sim);

    const srv_sms_mailbox_struct *mailbox = srv_sms_get_mailbox_setting(simId);

    VfxWChar number[MAX_CC_ADDR_LEN + 1];

    if (lineId == SRV_CALLSET_LINE2)
    {
        memcpy(number, mailbox->p_mailbox_number[1], (MAX_CC_ADDR_LEN + 1) *ENCODING_LENGTH);
    }
    else
    {
        memcpy(number, mailbox->p_mailbox_number[0], (MAX_CC_ADDR_LEN + 1) *ENCODING_LENGTH);
    }

    if ((number[0]=='\0') || (applib_is_valid_number_unicode(number) != APPLIB_TEL_NUMBER))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

void vapp_sms_call_voicemail(mmi_sim_enum mmi_sim)
{
    if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_VPS, mmi_sim))
    {
        vapp_nmgr_global_popup_show_confirm_one_button_id(
            MMI_SCENARIO_ID_DEFAULT,
            VCP_POPUP_TYPE_FAILURE,
            STR_ID_VAPP_SMS_VOICEMAIL_NOT_AVAILABLE,
            STR_GLOBAL_OK,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);
        return;
    }

    srv_sms_sim_enum simId = vapp_sms_mmi_sim_to_sim_id(mmi_sim);

    srv_callset_line_id_enum lineId = srv_callset_line_switch_get_id(mmi_sim);

    const srv_sms_mailbox_struct *mailbox = srv_sms_get_mailbox_setting(simId);

    VfxWChar number[MAX_CC_ADDR_LEN + 1];

    if (lineId == SRV_CALLSET_LINE2)
    {
        memcpy(number, mailbox->p_mailbox_number[1], (MAX_CC_ADDR_LEN + 1) *ENCODING_LENGTH);
    }
    else
    {
        memcpy(number, mailbox->p_mailbox_number[0], (MAX_CC_ADDR_LEN + 1) *ENCODING_LENGTH);
    }

    if ((number[0]!='\0') && (applib_is_valid_number_unicode(number) == APPLIB_TEL_NUMBER))
    {
        mmi_ucm_make_call_para_struct make_call_para; 

        mmi_ucm_init_call_para(&make_call_para);

	if (simId == SRV_SMS_SIM_1)
        {
            make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
        }
    #if (MMI_MAX_SIM_NUM >= 2)
        if (simId == SRV_SMS_SIM_2)
        {
            make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        if (simId == SRV_SMS_SIM_3)
        {
            make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        if (simId == SRV_SMS_SIM_4)
        {
            make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
        }
    #endif

        make_call_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_VOICE_MAIL;
        make_call_para.ucs2_num_uri = (U16*)number;
        mmi_ucm_call_launch(0, &make_call_para);
    }
}


#ifdef __MMI_URI_AGENT__
#include "UriAgentSrvGprot.h"
#include "Conversions.h"
#include "Stdlib.h"
#include "Unicodexdcl.h"
#include "Mmi_frm_mem_gprot.h"

#define VAPP_SMS_MAX_URI_RECIPIENT		6
#define VAPP_SMS_MAX_URI_TOKEN_LENGTH	(SRV_SMS_MAX_ADDR_LEN+ 10)
#define VAPP_SMS_MAX_URI_BUFF_SIZE       2048

typedef enum
{
	SMS_URI_TOKEN_SCHEME,
	SMS_URI_TOKEN_RECIPIENT,
	SMS_URI_TOKEN_GSTN_PHONE,
	SMS_URI_TOKEN_SMS_QUALIFIER,
	SMS_URI_TOKEN_SMSC,
	SMS_URI_TOKEN_PID,
	SMS_URI_TOKEN_VALUE,
	SMS_URI_TOKEN_BODY,
	SMS_URI_TOKEN_BODY_CONTENT,
	SMS_URI_TOKEN_EOF,
	SMS_URI_TOKEN_ERROR
}vapp_sms_uri_token_enum;

typedef enum
{
    SMS_URI_RESULT_OK,
    SMS_URI_RESULT_INVALID_URL,
    SMS_URI_RESULT_DATA_EXCEED,
	SMS_URI_RESULT_ERROR
}vapp_sms_uri_result_enum;

typedef enum
{
	SMS_URI_STATE_START,
	SMS_URI_STATE_SCHEME,
	SMS_URI_STATE_RECIPIENT,
	SMS_URI_STATE_GSTN_PHONE,
	SMS_URI_STATE_SMS_QUALIFIER,
	SMS_URI_STATE_SMS_BODY,
	SMS_URI_STATE_VALUE,	
	SMS_URI_STATE_DONE
}vapp_sms_uri_state_enum;


typedef enum
{
	SMS_URI_MASK_GSTN = 0x01,
	SMS_URI_MASK_SMSC = 0x02,
	SMS_URI_MASK_PID = 0x04
}vapp_sms_uri_mask_enum;


typedef struct
{
	S8 ucs2_dest_addr[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
	U8 smsc_addr[SRV_SMS_MAX_ADDR_LEN + 1];
	U16 pid;
	U8 mask;
}vapp_sms_uri_recipient_struct;


typedef struct
{
	U16 uri_offset;
	S8 *url_string;
	S8 *sms_uri_url;
	S8 token_string[VAPP_SMS_MAX_URI_TOKEN_LENGTH + 1];
	vapp_sms_uri_token_enum token;
}vapp_sms_uri_struct;

typedef struct
{
    vapp_sms_uri_result_enum result;
    U16 addr_count;
    WCHAR *ucs2_addr_list[VAPP_SMS_MAX_URI_RECIPIENT];
    WCHAR *ucs2_content;
    U16 content_buff_len;
}vapp_sms_uri_send_data_struct;

static S8 *sms_uri_string = NULL;
static WCHAR *ucs2_addr_list = NULL;
static VfxS32 uri_send_sms_popup = VCP_GLOBAL_POPUP_INVALID_HANDLE;


static void vapp_sms_uri_request_handle(
 			srv_uriagent_appid_enum ura_appid,
 			char *url,
 			char *param,
 			srv_uriagent_options_enum options,
 			srv_uriagent_uri_request_hdlr_cb callback);
static void vapp_sms_uri_pre_send_sms(VfxId id, void *userData);
static srv_uc_addr_struct* vapp_sms_get_uri_address(U16 index, void* user_data);
static mmi_ret vapp_sms_send_uri_proc(mmi_event_struct *evt);
static void vapp_sms_uri_send_sms_launch(void);
static mmi_ret vapp_sms_uri_send_sms_prepare(mmi_frm_asm_evt_struct *evt);
static void vapp_sms_uri_send_sms(void);
static S8 vapp_sms_uri_get_next_char(vapp_sms_uri_struct *sms_uri_data);
static void vapp_sms_uri_unget_next_char(vapp_sms_uri_struct *sms_uri_data);
static MMI_BOOL vapp_sms_is_alpha(S8 ascii_char);
static MMI_BOOL vapp_sms_is_gstn_char(S8 ascii_char);
static void vapp_sms_to_lower(S8* str);
static vapp_sms_uri_token_enum vapp_sms_get_uri_token(vapp_sms_uri_struct *sms_uri_data);
static void vapp_sms_uri_get_send_data(S8 *url, vapp_sms_uri_send_data_struct *data);

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

void vapp_sms_send_uri_init(void)
{
	srv_uriagent_register_hdlr_by_scheme(
                                "sms",
                                vapp_sms_uri_request_handle,
                                MMI_FALSE);
	srv_uriagent_register_hdlr_by_scheme(
                                "smsto",
                                vapp_sms_uri_request_handle,
                                MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_uri_request_handle
 * DESCRIPTION
 *  URI scheme "sms" or "smsto" handle application function
 * PARAMETERS
 *  ura_appid		[IN]	URI request application ID
 *	url				[IN]	URL string
 *	param			[IN]	param part of URL string(except the URI scheme)
 *	options			[IN]	Option
 *	callback		[IN]	URI request handle callbakc  function
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_uri_request_handle(
 			srv_uriagent_appid_enum ura_appid,
 			char *url,
 			char *param,
 			srv_uriagent_options_enum options,
 			srv_uriagent_uri_request_hdlr_cb callback)
{
	if (sms_uri_string != NULL)
	{
		OslMfree(sms_uri_string);
		sms_uri_string = NULL;
	}

	sms_uri_string = (S8*)OslMalloc(strlen(url) + 1);
	strcpy(sms_uri_string, (S8*)url);

	if (options == SRV_URIAGENT_OPTION_NEED_CONFIRM_POPUP)
	{
		if (uri_send_sms_popup != VCP_GLOBAL_POPUP_INVALID_HANDLE)
		{
			vcp_global_popup_cancel(uri_send_sms_popup);
			uri_send_sms_popup = VCP_GLOBAL_POPUP_INVALID_HANDLE;
		}
        uri_send_sms_popup = vcp_global_popup_show_confirm_two_button_id(
            GRP_ID_ROOT,
            VCP_POPUP_TYPE_QUESTION,
            STR_ID_VAPP_SMS_SEND_SMS_QUERY,
            STR_GLOBAL_SEND,
            STR_GLOBAL_CANCEL,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            VCP_POPUP_BUTTON_TYPE_CANCEL,
            vapp_sms_uri_pre_send_sms,
            NULL);
	}
	else
	{
        vapp_sms_uri_send_sms_launch();
	}

	if (callback != NULL)
	{
		callback(ura_appid, SRV_URIAGENT_APPID_SMS, MMI_TRUE);
	}
}

mmi_ret vapp_sms_uri_send_sms_evt_proc(mmi_event_struct *evt)
{
    vapp_sms_uri_send_sms_launch();

    return MMI_RET_OK;
}

static void vapp_sms_uri_pre_send_sms(VfxId id, void *userData)
{
	uri_send_sms_popup = VCP_GLOBAL_POPUP_INVALID_HANDLE;
    if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
	    mmi_event_struct post_evt;
        MMI_FRM_INIT_EVENT(&post_evt, EVT_ID_VAPP_SMS_SEND_URI_IND);
        MMI_FRM_POST_EVENT(&post_evt, vapp_sms_uri_send_sms_evt_proc, NULL);
    }
    else if (id == VCP_CONFIRM_POPUP_BUTTON_USER_2)
    {
		if (sms_uri_string != NULL)
		{
        OslMfree(sms_uri_string);
        sms_uri_string = NULL;
    }

    }
}

static srv_uc_addr_struct* vapp_sms_get_uri_address(U16 index, void* user_data)
{
    static srv_uc_addr_struct data;
    WCHAR *ucs2_addr;

    VFX_ASSERT(index < VAPP_SMS_MAX_URI_RECIPIENT);

    data.next = NULL;
    data.previous = NULL;
    if (index == 0)
    {
        ucs2_addr = ucs2_addr_list;
    }
    else
    {
        ucs2_addr = ucs2_addr_list + index*(SRV_SMS_MAX_ADDR_LEN+1) ;
    }

    data.addr = (U8*)ucs2_addr;
    data.type = SRV_UC_ADDRESS_TYPE_PHONE_NUMBER;
    data.group = SRV_UC_ADDRESS_GROUP_TYPE_TO;
    return &data;
}

static mmi_ret vapp_sms_send_uri_proc(mmi_event_struct *evt)
{
	mmi_group_event_struct *groupEvent = (mmi_group_event_struct*)evt;
    mmi_id senderId = groupEvent->sender_id;

	switch(evt->evt_id)
    {
		case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
			vcui_unifiedcomposer_close(senderId);
			break;

        case EVT_ID_ASM_FORCE_FREE:
            mmi_frm_group_close(VAPP_SMS_SEND_URI);
            break;

        case EVT_ID_GROUP_DEINIT:
            if (sms_uri_string != NULL)
            {
                OslMfree(sms_uri_string);
                sms_uri_string = NULL;
            }
            break;

		default:
			break;
	}

    return MMI_RET_OK;
}

static void vapp_sms_uri_send_sms_launch(void)
{
    if (mmi_frm_group_get_state(VAPP_SMS_SEND_URI) == MMI_SCENARIO_STATE_NONE)
    {
        mmi_frm_asm_property_struct property;

        mmi_frm_group_create(GRP_ID_ROOT, VAPP_SMS_SEND_URI, vapp_sms_send_uri_proc, NULL);
        mmi_frm_group_enter(VAPP_SMS_SEND_URI, MMI_FRM_NODE_SMART_CLOSE_FLAG);

        mmi_frm_asm_property_init(&property);
        property.f_prepare_w_reserve = 1;
        mmi_frm_asm_set_property(VAPP_SMS_SEND_URI, &property);

        mmi_frm_asm_prepare(VAPP_SMS_SEND_URI, 0, (mmi_proc_func)vapp_sms_uri_send_sms_prepare, NULL, MMI_FRM_ASM_F_NONE);
    }
}


static mmi_ret vapp_sms_uri_send_sms_prepare(mmi_frm_asm_evt_struct *evt)
{
    switch (evt->evt_id)
    {
    case EVT_ID_ASM_CANCELED:
        mmi_frm_group_close(VAPP_SMS_SEND_URI);
        break;

    case EVT_ID_ASM_PREPARED:
        vapp_sms_uri_send_sms();
        break;
    }

    return MMI_RET_OK;
}


static void vapp_sms_uri_send_sms(void)
{
    U8 i;
    vapp_sms_uri_send_data_struct sendData;

    ucs2_addr_list = (WCHAR*)OslMalloc((SRV_SMS_MAX_ADDR_LEN+1)*ENCODING_LENGTH* VAPP_SMS_MAX_URI_RECIPIENT);
    sendData.ucs2_content = (WCHAR*)OslMalloc(VAPP_SMS_MAX_URI_BUFF_SIZE);

    sendData.ucs2_addr_list[0] = ucs2_addr_list;
    for (i = 1; i< VAPP_SMS_MAX_URI_RECIPIENT; i++)
    {
        sendData.ucs2_addr_list[i] = ucs2_addr_list + i*(SRV_SMS_MAX_ADDR_LEN+1);
    }

    VFX_ASSERT(sms_uri_string != NULL);

    vapp_sms_uri_get_send_data(sms_uri_string, &sendData);

    if (sendData.result == SMS_URI_RESULT_OK)
    {
#if (defined(__MMI_UNIFIED_COMPOSER__) || defined(__MMI_MMS_STANDALONE_COMPOSER__))
        VappUcEntryStruct data;
        mmi_id cuiId;
        memset(&data, 0, sizeof(VappUcEntryStruct));
        data.text_buffer = (U8*)sendData.ucs2_content;
        data.text_num = (U16)wcslen((wchar_t*)sendData.ucs2_content);
        if (sendData.addr_count > 0)
        {
            data.addr_num = sendData.addr_count;
            data.get_address_callback = vapp_sms_get_uri_address;
        }
        data.info_type = SRV_UC_INFO_TYPE_SMS;
        data.operation = UC_OPERATION_WRITE_NEW_MSG;
        data.type = SRV_UC_STATE_WRITE_NEW_MSG;
        //vappUcAppLauncher(&data);

	    cuiId = vcui_unifiedcomposer_create(VAPP_SMS_SEND_URI, &data);

        if (cuiId != GRP_ID_INVALID)
    	{
    		//mmi_frm_group_set_caller_proc(cuiId, vapp_sms_send_uri_proc, NULL);
    		vcui_unifiedcomposer_run(cuiId);
    	}
        else
        {
            mmi_frm_group_close(VAPP_SMS_SEND_URI);
        }
#endif /*(__MMI_UNIFIED_COMPOSER__) || (__MMI_MMS_STANDALONE_COMPOSER__)*/
#ifdef __MMI_SMS_COMPOSER__
		mmi_id smsComposerCui = 0;
		VcuiSmsComposerEntryStruct *entryData;
		VFX_ALLOC_MEM(entryData, sizeof(VcuiSmsComposerEntryStruct), this);
		vfx_sys_mem_zero(entryData, sizeof(VcuiSmsComposerEntryStruct) );
	
		// set address
		VcuiSmsComposerAddrStruct address;
		address.next = NULL;
		address.previous = NULL;
		address.type = VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER;
		entryData->addr_num = sendData.addr_count;

		WCHAR *ucs2_addr;
    	VFX_ASSERT(index < VAPP_SMS_MAX_URI_RECIPIENT);
	    for (int index = 0; index < entryData->addr_num; index++)
    	{
	        ucs2_addr = ucs2_addr_list + index*(SRV_SMS_MAX_ADDR_LEN+1) ;
    	}
        address.addr = (VfxWChar *)ucs2_addr;
		
		entryData->addr = &address;
	
		// set text
		entryData.text_buffer = (U8*)sendData.ucs2_content;
		entryData.text_num = (U16)wcslen((wchar_t*)sendData.ucs2_content);
		
	
		// set operation method to a existed msg, only for message app internal use
		entryData->operation = VCUI_SMS_COMPOSER_OPERATION_NEW;
	
		smsComposerCui = vcui_sms_composer_create(VAPP_SMS_SEND_URI);
		if(smsComposerCui !=  GRP_ID_INVALID)
		{
			vcui_sms_composer_set_entry_data(smsComposerCui, entryData);		
			//vfxSetCuiCallerScr(smsComposerCui, getMainScr());
			vcui_sms_composer_run(smsComposerCui);
		}
		VFX_FREE_MEM(entryData);
#endif /* __MMI_SMS_COMPOSER__ */
    }

    else if (sendData.result == SMS_URI_RESULT_DATA_EXCEED)
    {
        vapp_nmgr_global_popup_show_confirm_one_button_id(
            MMI_SCENARIO_ID_DEFAULT,
            VCP_POPUP_TYPE_FAILURE,
            STR_ID_VAPP_SMS_DATA_EXCEED,
            STR_GLOBAL_OK,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);

        mmi_frm_group_close(VAPP_SMS_SEND_URI);
    }
    else
    {
        vapp_nmgr_global_popup_show_confirm_one_button_id(
            MMI_SCENARIO_ID_DEFAULT,
            VCP_POPUP_TYPE_FAILURE,
            STR_GLOBAL_INVALID_URL,
            STR_GLOBAL_OK,
            VCP_POPUP_BUTTON_TYPE_NORMAL,
            NULL,
            NULL);

        mmi_frm_group_close(VAPP_SMS_SEND_URI);
    }

    OslMfree(ucs2_addr_list);
    OslMfree(sendData.ucs2_content);
    if (sms_uri_string != NULL)
    {
        OslMfree(sms_uri_string);
        sms_uri_string = NULL;
    }
    ucs2_addr_list = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  vapp_sms_uri_get_next_char
 * DESCRIPTION
 *  get the next char in the URL string buffer
 * PARAMETERS
 *  void  
 * RETURNS
 *  S8		char
 *****************************************************************************/
static S8 vapp_sms_uri_get_next_char(vapp_sms_uri_struct *sms_uri_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return sms_uri_data->url_string[sms_uri_data->uri_offset++];
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_uri_unget_next_char
 * DESCRIPTION
 *  un-get the next char in the URL string buffer
 * PARAMETERS
 *  void  
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_uri_unget_next_char(vapp_sms_uri_struct *sms_uri_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	sms_uri_data->uri_offset--;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_is_alpha
 * DESCRIPTION
 *  Is the char alpha
 * PARAMETERS
 *  ascii_char		[IN] ascii char  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL vapp_sms_is_alpha(S8 ascii_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((ascii_char >= 'A' && ascii_char <= 'Z')|| 
		(ascii_char >= 'a' && ascii_char <= 'z'))
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
 *  vapp_sms_is_gstn_char
 * DESCRIPTION
 *  check the char whether it is a GSTN phone address char
 * PARAMETERS
 *  ascii_char		[IN]	Ascii char  
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL vapp_sms_is_gstn_char(S8 ascii_char)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (ascii_char >= '0' && ascii_char <= '9')
	{
		return MMI_TRUE;
	}
	else
	{
		switch (ascii_char)
		{
			case '*':
			case '#':
			case 'p':
			case 'P':
			case 'w':
			case 'W':
			case 'A':
			case 'B':
			case 'C':
			case 'D':
			case 'a':
			case 'b':
			case 'c':
			case 'd':
			case '.':
			case '-':
				return MMI_TRUE;
				break;

			default:
				return MMI_FALSE;
				break;		
		}
	}
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_to_lower
 * DESCRIPTION
 *  change the string to the lower
 * PARAMETERS
 *  str  		[IN]	string will be changed
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_to_lower(S8* str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S8* pstr = str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*pstr != 0)
    {
        if ((*pstr >= 'A') && (*pstr <= 'Z'))
        {
            *pstr += 'a' - 'A';
        }
        pstr++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_get_uri_token
 * DESCRIPTION
 *  Get the a token in the URL string
 * PARAMETERS
 *  void  
 * RETURNS
 *  vapp_sms_uri_token_enum
 *****************************************************************************/
static vapp_sms_uri_token_enum vapp_sms_get_uri_token(vapp_sms_uri_struct *sms_uri_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 token_length = 0;
	vapp_sms_uri_token_enum curr_token = SMS_URI_TOKEN_ERROR;
	vapp_sms_uri_state_enum state = SMS_URI_STATE_START;
	S8 token_string[VAPP_SMS_MAX_URI_TOKEN_LENGTH + 1];
	MMI_BOOL save;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (state != SMS_URI_STATE_DONE)
	{
		S8 ascii_char = vapp_sms_uri_get_next_char(sms_uri_data);

		save = MMI_TRUE;

		switch (state)
		{
			case SMS_URI_STATE_START:
				if (ascii_char == '\0')
				{
					save = MMI_FALSE;
					state = SMS_URI_STATE_DONE;
					curr_token = SMS_URI_TOKEN_EOF;
				}
				else
				if ((ascii_char == ' ') || (ascii_char == '\t') ||
					(ascii_char == '\r') || (ascii_char == '\n'))
				{
					save = MMI_FALSE;
				}
				else if (vapp_sms_is_alpha(ascii_char) == MMI_TRUE)
				{
					state = SMS_URI_STATE_SCHEME;
				}
				else
				{
					switch (ascii_char)
					{
						case ':':
						case ',':
							save = MMI_FALSE;
							state = SMS_URI_STATE_RECIPIENT;
							break;

						case ';':
							save = MMI_FALSE;
							state = SMS_URI_STATE_SMS_QUALIFIER;
							break;
							
						case '?':
							save = MMI_FALSE;
							state = SMS_URI_STATE_SMS_BODY;
							break;

						case '=':
							save = MMI_FALSE;
							state = SMS_URI_STATE_VALUE;
							break;

						default:
							state = SMS_URI_STATE_DONE;
							curr_token = SMS_URI_TOKEN_ERROR;
							break;
					}
				}
				break;

			case SMS_URI_STATE_SCHEME:
				if (vapp_sms_is_alpha(ascii_char) == MMI_FALSE)
				{
					state = SMS_URI_STATE_DONE;
					if (ascii_char == ':')
					{
						save = MMI_FALSE;

						curr_token = SMS_URI_TOKEN_SCHEME;
						vapp_sms_uri_unget_next_char(sms_uri_data);
					}
					else
					{
						curr_token = SMS_URI_TOKEN_ERROR;
					}
				}
				break;

			case SMS_URI_STATE_RECIPIENT:
				if ((ascii_char == '+') || (vapp_sms_is_gstn_char(ascii_char) == MMI_TRUE))
				{
					state = SMS_URI_STATE_GSTN_PHONE;
				}
				else
				{
					state = SMS_URI_STATE_DONE;
					curr_token = SMS_URI_TOKEN_ERROR;
				}
				break;
				
			case SMS_URI_STATE_GSTN_PHONE:
				if (vapp_sms_is_gstn_char(ascii_char) == MMI_TRUE)
				{
					if ((ascii_char == '-') || (ascii_char == '.'))
					{
						save = MMI_FALSE;
					}
				}
				else
				{
					state = SMS_URI_STATE_DONE;
					
					if ((ascii_char == ';') || (ascii_char == '?') || 
						(ascii_char == ',') || (ascii_char == '\0'))
					{
						save = MMI_FALSE;
						curr_token = SMS_URI_TOKEN_GSTN_PHONE;
						vapp_sms_uri_unget_next_char(sms_uri_data);
					}
					else
					{
						curr_token = SMS_URI_TOKEN_ERROR;
					}
				}
					
				break;

			case SMS_URI_STATE_SMS_QUALIFIER:
				if (vapp_sms_is_alpha(ascii_char) == MMI_FALSE)
				{
					state = SMS_URI_STATE_DONE;
					if (ascii_char == '=')
					{
						save = MMI_FALSE;
						curr_token = SMS_URI_TOKEN_SMS_QUALIFIER;
						vapp_sms_uri_unget_next_char(sms_uri_data);
					}
					else
					{
						curr_token = SMS_URI_TOKEN_ERROR;
					}
				}
				break;
			
			case SMS_URI_STATE_SMS_BODY:
				if (vapp_sms_is_alpha(ascii_char) == MMI_FALSE)
				{
					state = SMS_URI_STATE_DONE;
					if (ascii_char == '=')
					{
						save = MMI_FALSE;
						curr_token = SMS_URI_TOKEN_BODY;
						vapp_sms_uri_unget_next_char(sms_uri_data);
					}
					else
					{
						curr_token = SMS_URI_TOKEN_ERROR;
					}
				}
				break;

			case SMS_URI_STATE_VALUE:
				if ((ascii_char == ';') || (ascii_char == '?') ||
					(ascii_char == ',') || (ascii_char == '\0'))
				{
					save = MMI_FALSE;
					state = SMS_URI_STATE_DONE;
					curr_token = SMS_URI_TOKEN_VALUE;
					vapp_sms_uri_unget_next_char(sms_uri_data);
				}
				break;

			case SMS_URI_STATE_DONE:
			default:
				state = SMS_URI_STATE_DONE;
				curr_token = SMS_URI_TOKEN_ERROR;
				break;
		}

		if ((save == MMI_TRUE) && (token_length < VAPP_SMS_MAX_URI_TOKEN_LENGTH))
		{
			token_string[token_length++] = ascii_char;
		}

		if (state == SMS_URI_STATE_DONE)
		{
			token_string[token_length] = '\0';
			
			switch(curr_token)
			{
				case SMS_URI_TOKEN_SCHEME:
					vapp_sms_to_lower(token_string);
					if ((strcmp(token_string, "sms") != 0) &&
						(strcmp(token_string, "smsto") != 0))
					{
						curr_token = SMS_URI_TOKEN_ERROR;
					}
					break;

				case SMS_URI_TOKEN_BODY:
					if (strcmp(token_string, "body") != 0)
					{
						curr_token = SMS_URI_TOKEN_ERROR;
					}
					break;

				case SMS_URI_TOKEN_GSTN_PHONE:
					if ((token_length > SRV_SMS_MAX_ADDR_LEN) || 
                        ((token_length == SRV_SMS_MAX_ADDR_LEN) && (token_string[0] != '+')))
					{
						curr_token = SMS_URI_TOKEN_ERROR;
					}
					else
					{
						if(srv_sms_check_dst_number((U8*)token_string, (U8)token_length) != MMI_TRUE)
						{
							curr_token = SMS_URI_TOKEN_ERROR;
						}
					}
					break;
					
				case SMS_URI_TOKEN_SMS_QUALIFIER:
					if (strcmp(token_string, "smsc") == 0)
					{
						curr_token = SMS_URI_TOKEN_SMSC;
					}
					else if (strcmp(token_string, "pid") == 0)
					{
						curr_token = SMS_URI_TOKEN_PID;
					}
					else
					{
						curr_token = SMS_URI_TOKEN_ERROR;
					}
					break;
				
				default:
					break;
			}
		}
	}

	memcpy(sms_uri_data->token_string, token_string, (VAPP_SMS_MAX_URI_TOKEN_LENGTH + 1));
	return curr_token;
}

//data buffer and data member buffer is provided by caller, sms only set value
void vapp_sms_uri_get_send_data(S8 *url, vapp_sms_uri_send_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vapp_sms_uri_token_enum curr_token;
	S8 *content = NULL;
	vapp_sms_uri_recipient_struct recipient;
	U16 recipient_num = 0;
    vapp_sms_uri_result_enum result = SMS_URI_RESULT_OK;
    vapp_sms_uri_struct *sms_uri_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_uri_data = (vapp_sms_uri_struct*)OslMalloc(sizeof(vapp_sms_uri_struct));
    sms_uri_data->url_string = url;
	sms_uri_data->uri_offset = 0;

	curr_token = vapp_sms_get_uri_token(sms_uri_data);

	if (curr_token == SMS_URI_TOKEN_SCHEME)
	{
		curr_token = vapp_sms_get_uri_token(sms_uri_data);

		do
		{
			if (recipient_num < VAPP_SMS_MAX_URI_RECIPIENT)
			{
				recipient.mask = 0;
			}

			if (curr_token == SMS_URI_TOKEN_GSTN_PHONE)
			{
				if (recipient_num < VAPP_SMS_MAX_URI_RECIPIENT)
				{
                    mmi_asc_to_ucs2(recipient.ucs2_dest_addr,
                        sms_uri_data->token_string);

                    recipient.mask |= SMS_URI_MASK_GSTN;
				}

				curr_token = vapp_sms_get_uri_token(sms_uri_data);
			}
			else
			{
                result = SMS_URI_RESULT_INVALID_URL;
		        break;
			}

			if (curr_token == SMS_URI_TOKEN_SMSC)
			{
				vapp_sms_get_uri_token(sms_uri_data);
				if (recipient_num < VAPP_SMS_MAX_URI_RECIPIENT)
				{
					strncpy((S8*)recipient.smsc_addr,
						sms_uri_data->token_string, SRV_SMS_MAX_ADDR_LEN);
					recipient.mask |= SMS_URI_MASK_SMSC;
				}
				
				curr_token = vapp_sms_get_uri_token(sms_uri_data);
			}

			if (curr_token == SMS_URI_TOKEN_PID)
			{
				vapp_sms_get_uri_token(sms_uri_data);
				if (recipient_num < VAPP_SMS_MAX_URI_RECIPIENT)
				{
					recipient.pid = (U16)atoi(sms_uri_data->token_string);
					recipient.mask |= SMS_URI_MASK_PID;
				}
				
				curr_token = vapp_sms_get_uri_token(sms_uri_data);
			}

			recipient_num++;

            if (recipient_num <= VAPP_SMS_MAX_URI_RECIPIENT)
            {
                memcpy(data->ucs2_addr_list[recipient_num-1], recipient.ucs2_dest_addr, (SRV_SMS_MAX_ADDR_LEN +1)*ENCODING_LENGTH);
                data->addr_count = recipient_num;
            }
		}while (curr_token == SMS_URI_TOKEN_GSTN_PHONE);

        if (result == SMS_URI_RESULT_OK)
        {
    		if (curr_token == SMS_URI_TOKEN_BODY)
    		{
    			content = sms_uri_data->url_string + sms_uri_data->uri_offset + 1;
    		}
    		else if (curr_token != SMS_URI_TOKEN_EOF)
    		{
                result = SMS_URI_RESULT_INVALID_URL;
    		}
        }		
	}
	else
	{
        result = SMS_URI_RESULT_INVALID_URL;
	}

	if (result == SMS_URI_RESULT_OK)
	{
	    if ((content != NULL) && (*content != '\0'))
        {   
            U32 content_len = strlen(content);

            if (content_len > ((VAPP_SMS_MAX_URI_BUFF_SIZE / ENCODING_LENGTH) - 1))
            {
                result = SMS_URI_RESULT_DATA_EXCEED;
            }
            else
            {
                mmi_chset_utf8_to_ucs2_string(
                    (U8*)data->ucs2_content, 
    				((content_len + 1) * ENCODING_LENGTH),
    				(U8*)content);
            }
        }
        else
        {
            data->ucs2_content[0] = '\0';
        }
	}

    data->result = result;

    OslMfree(sms_uri_data);
    sms_uri_data = NULL;
}
#endif /* __MMI_URI_AGENT__ */

#ifdef __cplusplus
}
#endif

#if 1

#ifdef __cplusplus
extern "C"
{
#endif

#include "MMI_include.h"

#ifdef __MOD_SMSAL__ //CUI part
#include "SmsSrvGprot.h"
#include "SmsCuiGprot.h"
//mmi_id cui_sms_save_create(mmi_id parent_gid){return GRP_ID_INVALID;}
//void cui_sms_save_run(mmi_id sms_gid){}
//void cui_sms_save_close(mmi_id sms_gid){}
//void cui_sms_set_save_address(mmi_id sms_gid, U16 *ucs2_addr){}
//void cui_sms_set_save_sc_addr(mmi_id sms_gid, U16 *ucs2_addr){}
//void cui_sms_set_save_content_text(mmi_id sms_gid, U16 *content_buff, U16 content_size){}
//void cui_sms_set_save_content_text_file(mmi_id sms_gid, U16 *content_file_path){}
//void cui_sms_set_save_content_ems(mmi_id sms_gid, void *content_ems){}
//void cui_sms_set_save_sim_id(mmi_id sms_gid, srv_sms_sim_enum sim_id){}
//void cui_sms_set_save_status_report(mmi_id sms_gid, MMI_BOOL is_set){}
//void cui_sms_set_save_reply_path(mmi_id sms_gid, MMI_BOOL is_set){}
//void cui_sms_set_save_msg_status(mmi_id sms_gid, srv_sms_status_enum status){}
//void cui_sms_set_save_pid(mmi_id sms_gid, srv_sms_pid_enum pid){}
//void cui_sms_set_save_timestamp(mmi_id sms_gid, MYTIME *timestamp){}
//void cui_sms_set_save_title_id(mmi_id sms_gid, U16 title_id){}
//void cui_sms_set_save_success_popup_string_id(mmi_id sms_gid, U16 string_id){}
//void cui_sms_set_save_edit_draft_msg_id(mmi_id sms_gid, U16 msg_id){}
//MMI_BOOL cui_sms_is_send_busy(srv_sms_send_type_enum type){return MMI_TRUE;}
mmi_id cui_sms_send_create(mmi_id parent_gid){return GRP_ID_INVALID;}
void cui_sms_send_run(mmi_id sms_send_gid){}
void cui_sms_send_close(mmi_id sms_send_gid){}
//void cui_sms_set_send_unhide_add_recipient_scrn(mmi_id sms_gid){}
//void cui_sms_set_send_unhide_save_menu(mmi_id sms_gid){}
//void cui_sms_set_send_content_data(mmi_id sms_gid, S8 *content_buff, U16 content_size){}
void cui_sms_set_send_content_data_file(mmi_id sms_gid, U16 *content_file_path){}
void cui_sms_set_send_address(mmi_id sms_gid, U16 **ucs2_addr_list, U16 addr_count){}
//void cui_sms_set_send_each_address(mmi_id sms_gid, U16 *ucs2_addr){}
//void cui_sms_get_send_address(mmi_id sms_gid, U16 **ucs2_addr_list, U16 *addr_count){}
void cui_sms_set_send_content_text(mmi_id sms_gid, U16 *content_buff, U16 content_size){}
//void cui_sms_set_send_content_text_file(mmi_id sms_gid, U16 *content_file_path){}
//void cui_sms_set_send_content_ems(mmi_id sms_gid, void *content_ems){}
//void cui_sms_set_send_sim_id(mmi_id sms_gid, srv_sms_sim_enum sim_id){}
//void cui_sms_set_send_msg_id(mmi_id sms_gid, U16 msg_id){}
//void cui_sms_set_send_status_report(mmi_id sms_gid, MMI_BOOL is_set){}
//void cui_sms_set_send_sc_address(mmi_id sms_gid, U16 *sc_addr){}
//void cui_sms_set_send_vp(mmi_id sms_gid, srv_sms_vp_enum vp){}
//void cui_sms_set_send_content_text_dcs(mmi_id sms_gid, srv_sms_dcs_enum dcs){}
//void cui_sms_set_send_sending_string_id(mmi_id sms_gid, U16 string_id){}
//void cui_sms_set_send_pid(mmi_id sms_gid, srv_sms_pid_enum pid){}
//void cui_sms_set_send_class_type(mmi_id sms_gid, srv_sms_class_enum class_type){}
//void cui_sms_set_send_reply_path(mmi_id sms_gid, MMI_BOOL is_set){}
void cui_sms_set_send_data_port(mmi_id sms_gid, U16 src_port, U16 dest_port){}
//void cui_sms_set_send_reply_msg_id(mmi_id sms_gid, U16 msg_id){}
//void cui_sms_set_send_type(mmi_id sms_gid, srv_sms_send_type_enum type){}
//void cui_sms_set_send_mms(mmi_id sms_gid, MMI_BOOL is_set){}
//void cui_sms_set_send_msg_case(mmi_id sms_gid, cui_sms_send_case_enum send_msg_case){}
//void cui_sms_set_not_allow_empty_sc(mmi_id sms_gid){}
//void cui_sms_abort_send(mmi_id sms_gid, cui_sms_abort_send_enum type){}
#endif /* __MOD_SMSAL__ */

#ifdef __MOD_SMSAL__ // SmsMoMtGuiinterface.c
//void mmi_msg_exit_generic(void){}
pBOOL mmi_msg_is_new_msg_popup_scr_active(void){return MMI_TRUE;}
//void mmi_msg_init_msg_data(void){}
//void mmi_msg_pre_entry_write_new_msg(void){}
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
//void mmi_msg_update_unsent_icon(void){}
#endif /*__UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__*/
#ifdef __MMI_DUAL_SIM_MASTER__
//void mmi_msg_check_sim2_sms_waiting_icon(void){}
#endif /* __MMI_DUAL_SIM_MASTER__ */
#ifdef __MMI_MESSAGES_SMS_EMAIL__
//U8 mmi_msg_get_email_and_subject_from_msgtxt(S8 *pText, U16 txtLen, S8 *pEmail,U16 emailLen, S8 *pSubject, U16 subLen){return MMI_FALSE;}
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */
#endif /* __MOD_SMSAL__ */

U8 IsKeyPadLockState(void){return MMI_FALSE;}

#if 0 //emsmiscell.c
#ifdef __MMI_SMS_APP_EMS_SUPPORT__
/* under construction !*/
#else /* __MMI_SMS_APP_EMS_SUPPORT__) */
#ifdef __MMI_MESSAGES_EMS__
/* under construction !*/
#endif /* __MMI_MESSAGES_EMS__ */
#endif /* __MMI_SMS_APP_EMS_SUPPORT__) */ 
#endif /* __MOD_SMSAL__ */ 

#ifdef __MOD_SMSAL__
//#include "SmsSrvGprot.h"
#include "UmSrvDefs.h"
//MMI_BOOL mmi_sms_is_sms_ready(void){return MMI_FALSE;}
//MMI_BOOL mmi_sms_hide_send_sms_menu(void){return MMI_TRUE;}
//void mmi_sms_set_msg_icon(MMI_BOOL is_set_mem_icon, srv_sms_sim_enum sim_id){}
//void mmi_sms_hide_msg_icon(srv_sms_sim_enum sim_id){}
//MMI_MENU_ID mmi_sms_get_list_opt_menu_id(U32 msg_id){return 0;}
//MMI_BOOL mmi_sms_is_allow_reentry(void){return MMI_FALSE;}
srv_um_msg_box_enum mmi_msg_get_um_type_by_msgid(U32 msgid){return SRV_UM_MSG_BOX_NONE;}
//srv_um_msg_box_enum mmi_sms_query_um_msg_box(U32 msg_id){return SRV_UM_MSG_BOX_NONE;}
#endif /* __MOD_SMSAL__ */

#ifdef __SMS_R8_NATION_LANGUAGE__
#include "ems.h"
#include "Gsm7BitNationalLang.h"

extern EMSNationalLanguageType srv_sms_get_system_ems_lang_type(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_msg_set_system_ems_lang_type
 * DESCRIPTION
 *  Set System EMS Language Type
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_msg_set_system_ems_lang_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    EMSNationalLanguageType lang;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    lang = srv_sms_get_system_ems_lang_type();

    mmi_7bit_set_national_lang(lang);
}
#endif /* __SMS_R8_NATION_LANGUAGE__ */

#ifdef __cplusplus
}
#endif


#endif //endif 1


