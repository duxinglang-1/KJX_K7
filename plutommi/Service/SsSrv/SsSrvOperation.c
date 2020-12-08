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
 *  SsSrvOperation.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SS service operation
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "SsSrvGprot.h"
#include "SsSrvProt.h"

#include "CallSetSrvGprot.h" /* srv_callset_line_switch_get_id */
#include "UcmSrvGprot.h" /* srv_ucm_is_valid_number */

#include "GSM7BitDefaultAlphabet.h" /* CovertStringForPlatform, InputboxConvertGSMToDeviceEncoding */

#include "MMIDataType.h"
#include "l4c_common_enum.h"
#include "MMI_features.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "stdio.h"
#include "kal_non_specific_general_types.h"
#include "stack_msgs.h"
#include "wgui_categories_util.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"



/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable 
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_ss_op_call_forward
 * DESCRIPTION
 *  call forward operation
 * PARAMETERS
 *  info    [IN]    parameter
 * RETURNS
 *  srv_ss_result_enum, not OK if the request is rejected directly by ss service
 *****************************************************************************/
srv_ss_result_enum srv_ss_op_call_forward(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_call_forward_req_struct *req = (srv_ss_call_forward_req_struct*)info;
    CHAR asc_str[SRV_SS_MAX_LENGTH + 1];
    CHAR asc_num[SRV_UCM_MAX_NUM_URI_LEN + 1];
    CHAR asc_time[3];
    srv_ss_operation_req_struct ss_op_req;
    srv_ucm_call_type_enum call_type;

	static const CHAR *act_str[] = 
	{
		"**", //SRV_SS_ACTION_TYPE_ACTIVATE
		"##", //SRV_SS_ACTION_TYPE_DEACTIVATE
		"*#"  //SRV_SS_ACTION_TYPE_QUERY
	};
	
	static const CHAR *cftype_str[] = 
	{
		"21", //SRV_SS_CALL_FORWARD_CFU
		"67", //SRV_SS_CALL_FORWARD_CFB
		"61", //SRV_SS_CALL_FORWARD_CFNRY
		"62", //SRV_SS_CALL_FORWARD_CFNRC
		"002",//SRV_SS_CALL_FORWARD_CFALL
	};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      						   */
    /*----------------------------------------------------------------*/

    if (!srv_ss_is_valid_sim(req->sim) || 
		(req->action > SRV_SS_ACTION_TYPE_QUERY) ||
		(req->type > SRV_SS_CALL_FORWARD_CFALL))
    {
        return SRV_SS_RESULT_INVALID_INPUT;
    }

    /* check forward-to-number */
    memset(asc_num, 0, sizeof(asc_num));
    if (req->action == SRV_SS_ACTION_TYPE_ACTIVATE)
    {
        mmi_ucs2_n_to_asc(asc_num, (CHAR*)(req->forward_number), SRV_UCM_MAX_NUM_URI_LEN * ENCODING_LENGTH);
        call_type = srv_ss_get_call_type(req->sim);

        if (!srv_ucm_is_valid_number(call_type, (PU8)asc_num))
        {
            return SRV_SS_RESULT_INVALID_NUMBER;
        }
    }

    memset(asc_str, 0, sizeof(asc_str));
    memset(asc_time, 0, sizeof(asc_time));
    memset(&ss_op_req, 0, sizeof(srv_ss_operation_req_struct));

    ss_op_req.sim = srv_ss_p->sim;
    ss_op_req.source = srv_ss_p->act_info.source;

	/* action code */
	strcpy(asc_str, act_str[req->action]);

	/* + cf type code */
	strcat(asc_str, cftype_str[req->type]);

	/* + number */
	if (strlen(asc_num))
	{
		strcat(asc_str, "*");
		strcat(asc_str, asc_num);
	}
	else if (req->call_type != SRV_SS_ALL_CALL)
	{
		/* no number but has bs code, */
		strcat(asc_str, "*");
	}

	/* + bs code */
	srv_ss_ps_append_bs_code(req->sim, asc_str, req->call_type);

	/* + cfnry time */
	if ((req->type == SRV_SS_CALL_FORWARD_CFNRY) && (req->action == SRV_SS_ACTION_TYPE_ACTIVATE))
	{
		if ((req->no_reply_timer < SRV_SS_MIN_CFNRY_TIME) ||
			(req->no_reply_timer > SRV_SS_MAX_CFNRY_TIME))
		{
			return SRV_SS_RESULT_INVALID_INPUT;
		}
		if (req->call_type == SRV_SS_ALL_CALL)
		{
			/* no bs code */
			strcat(asc_str, "*");
		}
		if (req->no_reply_timer)
		{
			strcat(asc_str, "*");
			sprintf(asc_time, "%d", req->no_reply_timer);
			strcat(asc_str, asc_time);
		}
	}

	/* + terminator */
    strcat(asc_str, "#");
    mmi_asc_to_ucs2((CHAR*)ss_op_req.string, asc_str);

    return srv_ss_op_ss_operation(&ss_op_req, (U8)strlen(asc_num));
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_op_call_bar
 * DESCRIPTION
 *  call bar operation
 * PARAMETERS
 *  info    [IN]    parameter
 * RETURNS
 *  srv_ss_result_enum, not OK if the request is rejected directly by ss service
 *****************************************************************************/
srv_ss_result_enum srv_ss_op_call_bar(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_call_bar_req_struct *req = (srv_ss_call_bar_req_struct*)info;
    CHAR asc_str[SRV_SS_MAX_LENGTH + 1];
    CHAR asc_pass[SRV_SS_PASSWORD_MAX_LENTH + 1];
    srv_ss_operation_req_struct ss_op_req;

	static const CHAR *action_str[] = 
	{
		"*",	//SRV_SS_ACTION_TYPE_ACTIVATE
		"#",	//SRV_SS_ACTION_TYPE_DEACTIVATE
		"*#",	//SRV_SS_ACTION_TYPE_QUERY
		"*03*"	//SRV_SS_ACTION_TYPE_CHANGE_PASSWD
	};

	static const CHAR *cbtype_str[] = 
	{
		"33", //SRV_SS_CALL_BAR_BAOC
		"331",//SRV_SS_CALL_BAR_BOIC
		"332",//SRV_SS_CALL_BAR_BOICEXHC
		"35", //SRV_SS_CALL_BAR_BAIC
		"351",//SRV_SS_CALL_BAR_BAICROAM
		"330",//SRV_SS_CALL_BAR_BAC
		"333",//SRV_SS_CALL_BAR_BOC
		"353",//SRV_SS_CALL_BAR_BIC
	};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!srv_ss_is_valid_sim(req->sim) ||
		(req->action > SRV_SS_ACTION_TYPE_CHANGE_PASSWD) ||
		(req->type > SRV_SS_CALL_BAR_BIC))
    {
        return SRV_SS_RESULT_INVALID_INPUT;
    }

    /* check old password */
    memset(asc_pass, 0, sizeof(asc_pass));
    if (req->action != SRV_SS_ACTION_TYPE_QUERY)
    {
        mmi_ucs2_n_to_asc(asc_pass, (CHAR*)(req->password_old), SRV_SS_PASSWORD_MAX_LENTH * ENCODING_LENGTH);
        if (strlen(asc_pass) != SRV_SS_PASSWORD_MAX_LENTH)
        {
            return SRV_SS_RESULT_PASSWD_WRONG;
        }
    }

    memset(asc_str, 0, sizeof(asc_str));
    memset(&ss_op_req, 0, sizeof(srv_ss_operation_req_struct));

    ss_op_req.sim = srv_ss_p->sim;
    ss_op_req.source = srv_ss_p->act_info.source;

	/* action code */
	strcpy(asc_str, action_str[req->action]);

	/* + cb type code */
    if (req->action != SRV_SS_ACTION_TYPE_CHANGE_PASSWD)
    {
    	strcat(asc_str, cbtype_str[req->type]);    

        if (req->call_type < SRV_SS_ALL_CALL)
        {
            /* has bs code, */
            strcat(asc_str, "*");
            if (strlen(asc_pass))
            {
                strcat(asc_str, asc_pass);
            }
            srv_ss_ps_append_bs_code(req->sim, asc_str, req->call_type);
        }
		
        if (req->call_type == SRV_SS_ALL_CALL)
        {
            if (strlen(asc_pass))
            {
                strcat(asc_str, "*");
                strcat(asc_str, asc_pass);
            }
        }

    }
    else
    {
        strcat(asc_str, "*");
        strcat(asc_str, asc_pass);
        memset(asc_pass, 0, sizeof(asc_pass));
        mmi_ucs2_n_to_asc(asc_pass, (CHAR*)(req->password_new), SRV_SS_PASSWORD_MAX_LENTH * ENCODING_LENGTH);
        if (strlen(asc_pass) != SRV_SS_PASSWORD_MAX_LENTH)
        {
            return SRV_SS_RESULT_INVALID_NUMBER;
        }
        strcat(asc_str, "*");
        strcat(asc_str, asc_pass);
        memset(asc_pass, 0, sizeof(asc_pass));
        mmi_ucs2_n_to_asc(asc_pass, (CHAR*)(req->password_cnf), SRV_SS_PASSWORD_MAX_LENTH * ENCODING_LENGTH);
        if (strlen(asc_pass) != SRV_SS_PASSWORD_MAX_LENTH)
        {
            return SRV_SS_RESULT_INVALID_NUMBER;
        }
        strcat(asc_str, "*");
        strcat(asc_str, asc_pass);
    }

	/* + teminator */
    strcat(asc_str, "#");
    mmi_asc_to_ucs2((CHAR*)ss_op_req.string, asc_str);

    return srv_ss_op_ss_operation(&ss_op_req, 0);
}



/*****************************************************************************
 * FUNCTION
 *  srv_ss_op_call_wait
 * DESCRIPTION
 *  call wait operation
 * PARAMETERS
 *  info    [IN]    parameter
 * RETURNS
 *  srv_ss_result_enum, not OK if the request is rejected directly by ss service
 *****************************************************************************/
srv_ss_result_enum srv_ss_op_call_wait(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_call_wait_req_struct *req = (srv_ss_call_wait_req_struct*)info;
    srv_ss_operation_req_struct ss_op_req;

	static const CHAR *act_tr[] = 
	{
		"*43#",	//SRV_SS_ACTION_TYPE_ACTIVATE
		"#43#", //SRV_SS_ACTION_TYPE_DEACTIVATE
		"*#43#" //SRV_SS_ACTION_TYPE_QUERY
	};
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (req->action > SRV_SS_ACTION_TYPE_QUERY)
	{
		return SRV_SS_RESULT_INVALID_INPUT;
	}
	
    memset(&ss_op_req, 0, sizeof(srv_ss_operation_req_struct));
    ss_op_req.sim = srv_ss_p->sim;
    ss_op_req.source = srv_ss_p->act_info.source;

    mmi_asc_to_ucs2((CHAR*)ss_op_req.string, (CHAR *)act_tr[req->action]);

    return srv_ss_op_ss_operation(&ss_op_req, 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_op_ss_operation
 * DESCRIPTION
 *  general ss operation
 * PARAMETERS
 *  info    [IN]    parameter
 *  cf_num_len [IN] call forwarding number length in character count
 * RETURNS
 *  srv_ss_result_enum, not OK if the request is rejected directly by ss service
 *****************************************************************************/
srv_ss_result_enum srv_ss_op_ss_operation(void *info, U8 cf_num_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_operation_req_struct *req = (srv_ss_operation_req_struct*)info;
    U8 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    length = mmi_ucs2strlen((CHAR*)req->string);

    if (!(srv_ss_p->in_ss_session) && 
        !srv_ss_is_valid_ss_string(srv_ss_p->sim, length, req->string))
    {
        /* doesn't check format for ussr reply */
        return SRV_SS_RESULT_INVALID_NUMBER;
    }

    srv_ss_p->in_ss_session = MMI_TRUE;

    srv_ss_l4c_ss_operation_req(length, req->string, cf_num_len);

    return SRV_SS_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  srv_ss_result_enum, not OK if the request is rejected directly by ss service
 *****************************************************************************/
srv_ss_result_enum srv_ss_op_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!(srv_ss_p->in_ss_session))
    {
        return SRV_SS_RESULT_SESSION_NOT_EXIST;
    }

    srv_ss_l4c_ss_abort_req(NULL);

    return SRV_SS_RESULT_OK;
}



/*****************************************************************************
 * FUNCTION
 *  srv_ss_ps_ss_operation
 * DESCRIPTION
 *  ss operation done
 * PARAMETERS
 *  info        [IN]    information
 *  end_session [IN]    end the ss session 
 *                          (ss session may not be ended after ss op done, 
 *                          ex. receive ussn/ussr after ss_operation_rsp)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_ps_ss_operation_done(srv_ss_rsp_struct *info, MMI_BOOL end_session)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_ss_post_act_notify_evt(SRV_SS_ACT_NOTIFY_END, info);
    srv_ss_post_rsp_evt(info);

    if (end_session)
    {
        srv_ss_p->in_ss_session = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_ps_receive_ussn_ussr
 * DESCRIPTION
 *  
 * PARAMETERS
 *    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_ps_receive_ussn_ussr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_ussn_ussr_struct *ind = (srv_ss_ussn_ussr_struct*)info;
    U8 auto_rej_cause = 0;
    srv_ss_ussd_rsp_struct ussd_rsp;
    srv_ss_rsp_struct ss_rsp;
    srv_ss_ussn_ind_struct ussn_ind;
    srv_ss_ussr_ind_struct ussr_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((srv_ss_p->act_info.op != SRV_SS_ACT_IDLE) &&
        (ind->direction != SRV_SS_DIR_MO))
    {
        /* mo mt collision, clear mo ss operation */
        if (srv_ss_p->act_info.op == SRV_SS_ACT_SS_OPERATION)
        {
            srv_ss_reset_ps_event_handler(MSG_ID_MMI_SS_OPERATION_RSP);
            ss_rsp.opcode = SRV_SS_ACT_USSD;
        }
        else
        {
            ss_rsp.opcode = srv_ss_p->act_info.op;
        }

        /* ussd rsp */
        ss_rsp.sim = srv_ss_p->sim;
        ss_rsp.source = srv_ss_p->act_info.source;
        ss_rsp.result = SRV_SS_RESULT_NOT_AVAILABLE;
        ss_rsp.ps_cause = (srv_ss_ps_cause_enum)0;
        ss_rsp.data = NULL;

        srv_ss_ps_ss_operation_done(&ss_rsp, MMI_TRUE);
    }

     /* auto reject check */
#ifdef __USSD_AUTO_REJECT__
    if (srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0 ||
        srv_ucm_query_call_count(SRV_UCM_OUTGOING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        /* use busy to show the inforamtion*/
        auto_rej_cause = 72;
    }
    else if (ind->dcs == 0x0c) 
    {
        /* dcs equals to OTHER VALUEs */
        auto_rej_cause = 36;
    }
    else if (wgui_is_display_medium_font_string((PU8)ussr_ind.string, (S32)mmi_ucs2strlen((CHAR*)ussr_ind.string)) == MMI_FALSE)
    {
        /* contain unknown alphabet */
        auto_rej_cause = 71;
    }
#endif /* __USSD_AUTO_REJECT__ */

    /* ussd rsp */
    if (srv_ss_p->act_info.op == SRV_SS_ACT_SS_OPERATION)
    {
        ss_rsp.sim = srv_ss_p->sim;
        ss_rsp.source = srv_ss_p->act_info.source;
        ss_rsp.result = auto_rej_cause ? SRV_SS_RESULT_NOT_AVAILABLE : SRV_SS_RESULT_OK;
        ss_rsp.ps_cause = (srv_ss_ps_cause_enum)0;
        ss_rsp.opcode = SRV_SS_ACT_USSD;

        if (ss_rsp.result == SRV_SS_RESULT_OK)
        {
            memset(&ussd_rsp, 0, sizeof(srv_ss_ussd_rsp_struct));
            ussd_rsp.end_of_session = (auto_rej_cause || (ind->ind == SRV_SS_IND_USSN)) ? MMI_TRUE : MMI_FALSE;
            ss_rsp.data = (void*)(&ussd_rsp);
        }
        else
        {
            ss_rsp.data = NULL;
        }

        srv_ss_ps_ss_operation_done(&ss_rsp, ussd_rsp.end_of_session);
    }

#ifdef __USSD_AUTO_REJECT__
    srv_ss_l4c_ack_req(auto_rej_cause);
#endif /* __USSD_AUTO_REJECT__ */

    /* post ussn / ussr indication */
    if (!auto_rej_cause)
    {
        if (ind->ind == SRV_SS_IND_USSN)
        {
            memset(&ussn_ind, 0, sizeof(srv_ss_ussn_ind_struct));
            ussn_ind.direction = ind->direction;
            mmi_ucs2cpy((CHAR*)ussn_ind.string, (CHAR*)(ind->ussd_string));
            srv_ss_post_ind_evt(SRV_SS_IND_USSN, &ussn_ind);
        }
        else if (ind->ind == SRV_SS_IND_USSR)
        {
            memset(&ussr_ind, 0, sizeof(srv_ss_ussr_ind_struct));
            ussr_ind.direction = ind->direction;
            mmi_ucs2cpy((CHAR*)ussr_ind.string, (CHAR*)(ind->ussd_string));
            srv_ss_post_ind_evt(SRV_SS_IND_USSR, &ussr_ind);
            srv_ss_p->in_ss_session = MMI_TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_ps_derive_ussd
 * DESCRIPTION
 *  Function derives data in USSN, USSR, and USSD messages
 * PARAMETERS
 *  dcs         [IN]    decoding scheme  
 *  length      [IN]    string length
 *  str         [IN]    raw data of USSD string
 *  out_str     [OUT]   output string
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ss_ps_derive_ussd(U8 dcs, U8 length, PU8 str, WCHAR *out_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *temp_str = NULL;
    U16 checked_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!out_str || !length)
    {
        return;
    }

    checked_len = (U16)length;

    if (length > SRV_SS_MAX_LENGTH)
    {
        if (dcs == MMI_UCS2_DCS)
        {
            checked_len = SRV_SS_MAX_LENGTH - 2; /* 180 */
        }
        else
        {
            checked_len = SRV_SS_MAX_LENGTH; /* 182 */
        }
    }

    if (dcs == MMI_8BIT_DCS)
    {
        temp_str = CovertStringForPlatform(str, checked_len, dcs, &checked_len);
    }
    else if(dcs == 0x11) /* If dcs is 0x11, skip the first two chars (lang indicator)*/
    {
        temp_str = OslMalloc((SRV_SS_MAX_LENGTH + 1) * ENCODING_LENGTH);
        memset(temp_str, 0, (SRV_SS_MAX_LENGTH + 1) * ENCODING_LENGTH);
        str[checked_len] = 0; /*InputboxConvertGSMToDeviceEncoding requirement*/
        str[checked_len + 1] = 0;
        checked_len = checked_len - 2;
        InputboxConvertGSMToDeviceEncoding(str+2, temp_str, (U8)checked_len, (SRV_SS_MAX_LENGTH + 1) * ENCODING_LENGTH, MMI_UCS2_DCS, 0, 1);
    }
    else
    {
        temp_str = OslMalloc((SRV_SS_MAX_LENGTH + 1) * ENCODING_LENGTH);
        memset(temp_str, 0, (SRV_SS_MAX_LENGTH + 1) * ENCODING_LENGTH);
        str[checked_len] = 0; /*InputboxConvertGSMToDeviceEncoding requirement*/
        if (checked_len < SRV_SS_MAX_LENGTH) /* < 182 */
        {
            str[checked_len + 1] = 0; /* for UCS2 scenarios */
        }
        InputboxConvertGSMToDeviceEncoding(str, temp_str, (U8)checked_len, (SRV_SS_MAX_LENGTH + 1) * ENCODING_LENGTH, dcs, 0, 1);
    }

    if (temp_str)
    {
        mmi_ucs2ncpy((CHAR*)out_str, (CHAR*)temp_str, SRV_SS_MAX_LENGTH);
        OslMfree(temp_str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_ps_derive_result
 * DESCRIPTION
 *  Derive result from ps
 * PARAMETERS
 *  cause       [IN]    ps error cause
 * RETURNS
 *  srv_ss_result_enum result
 *****************************************************************************/
srv_ss_result_enum srv_ss_ps_derive_result(srv_ss_ps_cause_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (cause)
    {
        case PHB_CAUSE_FDN_BLOCKED:
            return SRV_SS_RESULT_FDN_FAIL;

        case CM_SS_ERR_NEGATIVEPW_CHECK:
            return SRV_SS_RESULT_PASSWD_WRONG;

        case CM_SS_ERR_NUMBEROFPW_ATTEMPTSVIOLATION:
            return SRV_SS_RESULT_PASSWD_BLOCK;
			
		default:
			break;
    }

    /* advanced result */
    return SRV_SS_RESULT_ERROR_WITH_PS_CAUSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ss_ps_append_bs_code
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_ss_result_enum srv_ss_ps_append_bs_code(mmi_sim_enum sim, CHAR *buf, srv_ss_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (call_type == SRV_SS_VOICE_CALL)
    {
        if (srv_callset_line_switch_get_id(sim) == SRV_CALLSET_LINE2)
        {
            strcat(buf, "*89");
        }
        else
        {
            strcat(buf, "*11");
        }
    }
    else if (call_type == SRV_SS_VIDEO_CALL)
    {
    #ifdef __MMI_VIDEO_TELEPHONY__
        strcat(buf, "*24");
    #else /* __MMI_VIDEO_TELEPHONY__ */
        return SRV_SS_RESULT_INVALID_INPUT;
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }
    else if (call_type == SRV_SS_DATA_CALL)
    {
    #ifdef __MMI_VIDEO_TELEPHONY__
        strcat(buf, "*25");
    #else /* __MMI_VIDEO_TELEPHONY__ */
        strcat(buf, "*20");
    #endif /* __MMI_VIDEO_TELEPHONY__ */
    }
    else if (call_type == SRV_SS_ALL_CALL)
    {
        /* do nothing */
    }
    else
    {
        return SRV_SS_RESULT_CMD_NOT_SUPPORT;
    }

    return SRV_SS_RESULT_OK;
}

