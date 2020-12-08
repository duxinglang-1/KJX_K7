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
 *  SsCore.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SS (Supplementary Service) application core
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"

#include "SsCore.h"
#ifdef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_vapp_ss_def.h"
#else
#include "mmi_rp_app_ss_def.h"
#endif
#include "mmi_rp_srv_ss_def.h"

#include "SsSrvGprot.h"

#include "MMIDataType.h"
#include "string.h"
#include "kal_non_specific_general_types.h"
#include "Unicodexdcl.h"
#include "CustDataRes.h"
#include "stdio.h"
#include "UcmSrvGprot.h"
#include "GlobalResDef.h"


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
 *  mmi_ss_abort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void mmi_ss_send_abort(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_abort_req_struct req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(&req, 0, sizeof(srv_ss_abort_req_struct));
    req.sim = sim;

    srv_ss_act_req(SRV_SS_ACT_ABORT, &req, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_derive_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 *  out     [OUT]   output
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_derive_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (info->opcode)
    {
        case SRV_SS_ACT_CALL_FORWARD:
            mmi_ss_derive_call_forward_result(info, out);
            break;

        case SRV_SS_ACT_CALL_BAR:
            mmi_ss_derive_call_bar_result(info, out);
            break;

        case SRV_SS_ACT_CALL_WAIT:
            mmi_ss_derive_call_wait_result(info, out);
            break;

        case SRV_SS_ACT_CALL_IDENTIFICATION:
            mmi_ss_derive_call_id_result(info, out);
            break;

        case SRV_SS_ACT_CNAP:
            mmi_ss_derive_cnap_result(info, out);
            break;

        case SRV_SS_ACT_CCBS:
            mmi_ss_derive_ccbs_result(info, out);
            break;

        case SRV_SS_ACT_EMLPP:
            mmi_ss_derive_emlpp_result(info, out);
            break;

        case SRV_SS_ACT_USSD:
            mmi_ss_derive_ussd_result(info, out);
            break;

        case SRV_SS_ACT_SS_OPERATION:
            mmi_ss_derive_ss_operation_result(info, out);
            break;

        case SRV_SS_ACT_ABORT:
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_derive_fail_string
 * DESCRIPTION
 *  get fail string, internal use only
 * PARAMETERS
 *  result  [IN]    result from ss service
 *  cause   [IN]    ps cause
 *  string  [OUT]   output string, shall be a string array with len >= MMI_SS_MAX_RESULT_LEN + 1
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_derive_fail_string(srv_ss_result_enum result, srv_ss_ps_cause_enum cause, CHAR *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 #ifdef __MMI_SS_SHOW_CAUSE__
    srv_ss_cause_str_struct cause_str;
#endif /* __MMI_SS_SHOW_CAUSE__ */
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_SS_SHOW_CAUSE__
    if (result == SRV_SS_RESULT_ERROR_WITH_PS_CAUSE)
    {
        srv_ss_get_cause_string(cause, &cause_str);
        mmi_ucs2ncpy(string, (CHAR*)(cause_str.string), MMI_SS_MAX_RESULT_LEN);
    }
    else
#endif /* __MMI_SS_SHOW_CAUSE__ */
    {
        mmi_ucs2cpy(string, GetString(srv_ss_get_result_string(result)));
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_derive_call_bar_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 *  out     [OUT]   output
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_derive_call_forward_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_call_forward_rsp_struct *rsp = (srv_ss_call_forward_rsp_struct*)(info->data);
    int i;
    srv_ss_call_forward_list_struct *item;
    CHAR asc_cfnry_timer_str[3];
    WCHAR ucs2_cfnry_timer_str[3];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(out->string, 0, sizeof(out->string));

    out->result = info->result;

    if (info->result == SRV_SS_RESULT_OK)
    {
        mmi_ucs2cpy(
            (CHAR*)out->string, 
            GetString(srv_ss_get_call_forward_type_string(rsp->type)));

        /* format the result string with active/deactive tags. */
        if (!rsp->result_list_count)
        {
            mmi_ucs2cat((CHAR*)out->string, GetString(STR_ID_SRV_SS_DEACTIVATED));
        }
        else if (!mmi_ucs2strlen(GetString(srv_ss_get_bs_string(rsp->result_list[0].bs_code))))
        {
            mmi_ucs2cat((CHAR*)out->string, GetString(srv_ss_get_status_string(rsp->result_list[0].status)));
        }
        else
        {
            mmi_ucs2cat((CHAR*)out->string, (CHAR*)L":");
        }
        for (i = 0; i < rsp->result_list_count; i++)
        {
            item = &(rsp->result_list[i]);

            if (!mmi_ucs2strlen(GetString(srv_ss_get_bs_string(item->bs_code))))
            {
                continue;
            }

            memset(asc_cfnry_timer_str, 0, sizeof(asc_cfnry_timer_str));
            sprintf(asc_cfnry_timer_str, "%d", item->no_reply_timer);

            if ((mmi_ucs2strlen(GetString(srv_ss_get_bs_string(item->bs_code))) +
                 mmi_ucs2strlen(GetString(srv_ss_get_status_string(item->status))) +
                 (strlen((CHAR*)asc_cfnry_timer_str) + 10) +
                 mmi_ucs2strlen((CHAR*)item->number) + 
                 mmi_ucs2strlen((CHAR*)out->string)) <= MMI_SS_MAX_RESULT_LEN)
            {
                mmi_ucs2cat((CHAR*)out->string, (CHAR*)L"\n");
                mmi_ucs2cat((CHAR*)out->string, GetString(srv_ss_get_status_string(item->status)));
                if (item->no_reply_timer)
                {
                    mmi_ucs2cat((CHAR*)out->string, (CHAR*)L" ");
                    mmi_asc_to_ucs2((CHAR*)ucs2_cfnry_timer_str, (CHAR*)asc_cfnry_timer_str);
                    mmi_ucs2cat((CHAR*)out->string, (CHAR*)ucs2_cfnry_timer_str);
                    mmi_ucs2cat((CHAR*)out->string, GetString(STR_ID_SS_SECOND));
                }
                mmi_ucs2cat((CHAR*)out->string, GetString(srv_ss_get_bs_string(item->bs_code)));
                if (mmi_ucs2strlen((CHAR*)item->number))
                {
                    mmi_ucs2cat((CHAR*)out->string, (CHAR*)L" ");
                    mmi_ucs2ncat((CHAR*)out->string, (CHAR*)item->number, SRV_UCM_MAX_NUM_URI_LEN);
                }
            }
            else
            {
                break;
            }
        }
        mmi_ucs2cat((CHAR*)out->string, GetString(STR_ID_SS_PERIOD));
    }
    else
    {
        mmi_ss_derive_fail_string(info->result, info->ps_cause, (CHAR*)(out->string));
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ss_op_derive_call_bar_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 *  out     [OUT]   output
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_derive_call_bar_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_call_bar_rsp_struct *rsp = (srv_ss_call_bar_rsp_struct*)(info->data);
    int i;
    srv_ss_call_bar_list_struct *item;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(out->string, 0, sizeof(out->string));

    out->result = info->result;

    if ((info->result == SRV_SS_RESULT_OK) && (rsp->change_passwd))
    {
        mmi_ucs2cpy(
            (CHAR*)out->string, 
            GetString(STR_ID_SS_CHANGE_PSW_SUC));
    }
    else if (info->result == SRV_SS_RESULT_OK)
    {
        mmi_ucs2cpy(
            (CHAR*)out->string, 
            GetString(srv_ss_get_call_bar_type_string(rsp->type)));

        /* format the result string with active/deactive tags. */
        if (!rsp->result_list_count)            
        {
            mmi_ucs2cat((CHAR*)out->string, GetString(STR_ID_SRV_SS_DEACTIVATED));
        }
        else if (!mmi_ucs2strlen(GetString(srv_ss_get_bs_string(rsp->result_list[0].bs_code))))
        {
            mmi_ucs2cat((CHAR*)out->string, GetString(srv_ss_get_status_string(rsp->result_list[0].status)));
        }
        else
        {
            mmi_ucs2cat((CHAR*)out->string, (CHAR*)L":");
        }
        for (i = 0; i < rsp->result_list_count; i++)
        {
            item = &(rsp->result_list[i]);

            if (!mmi_ucs2strlen(GetString(srv_ss_get_bs_string(item->bs_code))))
            {
                continue;
            }

            if ((mmi_ucs2strlen(GetString(srv_ss_get_bs_string(item->bs_code))) +
                 mmi_ucs2strlen(GetString(srv_ss_get_status_string(item->status))) + 
                 mmi_ucs2strlen((CHAR*)out->string)) <= MMI_SS_MAX_RESULT_LEN)
            {
                mmi_ucs2cat((CHAR*)out->string, (CHAR*)L"\n");
                mmi_ucs2cat((CHAR*)out->string, GetString(srv_ss_get_status_string(item->status)));
                mmi_ucs2cat((CHAR*)out->string, GetString(srv_ss_get_bs_string(item->bs_code)));
            }
            else
            {
                break;
            }
        }
        mmi_ucs2cat((CHAR*)out->string, GetString(STR_ID_SS_PERIOD));
    }
    else
    {
        mmi_ss_derive_fail_string(info->result, info->ps_cause, (CHAR*)(out->string));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_derive_call_wait_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 *  out     [OUT]   output
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_derive_call_wait_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_call_wait_rsp_struct *rsp = (srv_ss_call_wait_rsp_struct*)(info->data);
    int i;

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(out->string, 0, sizeof(out->string));

    out->result = info->result;

    mmi_ucs2cpy(
        (CHAR*)out->string, 
        GetString(srv_ss_get_call_wait_string()));

    if (info->result == SRV_SS_RESULT_OK)
    {
        mmi_ucs2cat((CHAR*)out->string, GetString(srv_ss_get_status_string(rsp->status)));
        for (i = 0; i < rsp->bs_list_count; i++)
        {
            if (!mmi_ucs2strlen(GetString(srv_ss_get_bs_string(rsp->bs_list[i]))))
            {
                continue;
            }

            if ((mmi_ucs2strlen(GetString(srv_ss_get_bs_string(rsp->bs_list[i]))) + 
                 mmi_ucs2strlen((CHAR*)out->string)) <= MMI_SS_MAX_RESULT_LEN)
            {
                mmi_ucs2cat((CHAR*)out->string, (CHAR*)L"\n");
                mmi_ucs2cat((CHAR*)out->string, GetString(srv_ss_get_bs_string(rsp->bs_list[i])));
            }
            else
            {
                break;
            }
        }
        mmi_ucs2cat((CHAR*)out->string, GetString(STR_ID_SS_PERIOD));
    }
    else
    {
        mmi_ss_derive_fail_string(info->result, info->ps_cause, (CHAR*)(out->string));
    }
}



/*****************************************************************************
 * FUNCTION
 *  mmi_ss_derive_ussd_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 *  out     [OUT]   output
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_derive_ussd_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_ussd_rsp_struct *rsp = (srv_ss_ussd_rsp_struct*)(info->data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(out->string, 0, sizeof(out->string));

    out->result = info->result;

    if (info->result == SRV_SS_RESULT_OK)
    {
        mmi_ucs2ncpy((CHAR*)out->string, (CHAR*)rsp->string, MMI_SS_MAX_RESULT_LEN);
    }
    else
    {
        mmi_ss_derive_fail_string(info->result, info->ps_cause, (CHAR*)(out->string));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_derive_ss_operation_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 *  out     [OUT]   output
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_derive_ss_operation_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(out->string, 0, sizeof(out->string));

    out->result = info->result;

    mmi_ss_derive_fail_string(info->result, info->ps_cause, (CHAR*)(out->string));

}



/*****************************************************************************
 * FUNCTION
 *  mmi_ss_derive_call_id_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 *  out     [OUT]   output
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_derive_call_id_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_call_id_rsp_struct *rsp = (srv_ss_call_id_rsp_struct*)(info->data);

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(out->string, 0, sizeof(out->string));

    out->result = info->result;

    if (info->result == SRV_SS_RESULT_OK)
    {
        mmi_ucs2cpy(
            (CHAR*)out->string, 
            (CHAR*)GetString(srv_ss_get_call_id_type_string(rsp->type)));

        mmi_ucs2cat((CHAR*)out->string, (CHAR*)GetString(srv_ss_get_status_string(rsp->status)));
        mmi_ucs2cat((CHAR*)out->string, (CHAR*)GetString(STR_ID_SS_PERIOD));
    }
    else
    {
        mmi_ss_derive_fail_string(info->result, info->ps_cause, (CHAR*)(out->string));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_derive_cnap_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 *  out     [OUT]   output
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_derive_cnap_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_cnap_rsp_struct *rsp = (srv_ss_cnap_rsp_struct*)(info->data);

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(out->string, 0, sizeof(out->string));

    out->result = info->result;

    if (info->result == SRV_SS_RESULT_OK)
    {
        mmi_ucs2cpy(
            (CHAR*)out->string, 
            (CHAR*)GetString(srv_ss_get_cnap_string()));

        mmi_ucs2cat((CHAR*)out->string, (CHAR*)GetString(srv_ss_get_status_string(rsp->status)));
        mmi_ucs2cat((CHAR*)out->string, (CHAR*)GetString(STR_ID_SS_PERIOD));
    }
    else
    {
        mmi_ss_derive_fail_string(info->result, info->ps_cause, (CHAR*)(out->string));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_derive_ccbs_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 *  out     [OUT]   output
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_derive_ccbs_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_ccbs_rsp_struct *rsp = (srv_ss_ccbs_rsp_struct*)(info->data);

   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memset(out->string, 0, sizeof(out->string));

    out->result = info->result;

    if (info->result == SRV_SS_RESULT_OK)
    {
        mmi_ucs2cpy(
            (CHAR*)out->string, 
            (CHAR*)GetString(srv_ss_get_ccbs_string()));

        mmi_ucs2cat((CHAR*)out->string, (CHAR*)GetString(srv_ss_get_status_string(rsp->status)));
        mmi_ucs2cat((CHAR*)out->string, (CHAR*)GetString(STR_ID_SS_PERIOD));
    }
    else
    {
        mmi_ss_derive_fail_string(info->result, info->ps_cause, (CHAR*)(out->string));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_derive_emlpp_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info    [IN]    information
 *  out     [OUT]   output
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_ss_derive_emlpp_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ss_emlpp_rsp_struct *rsp = (srv_ss_emlpp_rsp_struct*)(info->data);
    CHAR tmp[25];
    WCHAR tmp_ucs2[25];

   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/

    memset(out->string, 0, sizeof(out->string));

    out->result = info->result;

    if (info->result == SRV_SS_RESULT_OK)
    {
        mmi_ucs2cpy(
            (CHAR*)out->string, 
            (CHAR*)GetString(srv_ss_get_emlpp_string()));

        mmi_ucs2cat((CHAR*)out->string, (CHAR*)L":\n");
        memset(tmp, 0, sizeof(tmp));
        sprintf(tmp, "Default: %d\nMax: %d", rsp->default_pri, rsp->max_pri);
        mmi_asc_to_ucs2((CHAR*)tmp_ucs2, tmp);
        mmi_ucs2cat((CHAR*)out->string, (CHAR*)tmp_ucs2);
        mmi_ucs2cat((CHAR*)out->string, (CHAR*)GetString(STR_ID_SS_PERIOD));
    }
    else
    {
        mmi_ss_derive_fail_string(info->result, info->ps_cause, (CHAR*)(out->string));
    }
}


