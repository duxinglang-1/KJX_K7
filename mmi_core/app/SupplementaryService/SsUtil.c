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
 *  SsUtil.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SS (Supplementary Service) application utilities
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
 
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMI_features.h"

#include "SsSrvGprot.h"
#include "UcmSrvGprot.h"

#include "MMIDataType.h"
#include "mmi_frm_mem_gprot.h"
#include "app_buff_alloc.h"
#include "string.h"


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
 *  mmi_ss_get_sim_by_ucm_call_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  call_type   [IN]    ucm call type
 * RETURNS
 * mmi_sim_enum
 *****************************************************************************/
mmi_sim_enum mmi_ss_get_sim_by_ucm_call_type(srv_ucm_call_type_enum call_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum sim = MMI_SIM_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((call_type & SRV_UCM_VOICE_CALL_TYPE) ||
        (call_type & SRV_UCM_VIDEO_CALL_TYPE))
    {
        sim |= MMI_SIM1;
    }

#if (MMI_MAX_SIM_NUM >= 2)
    if (call_type & SRV_UCM_VOICE_CALL_TYPE_SIM2 ||
    #ifdef __MMI_3G_SWITCH__
        call_type & SRV_UCM_VIDEO_CALL_TYPE_SIM2 ||
    #endif /* __MMI_3G_SWITCH__ */
        MMI_FALSE)
    {
        sim |= MMI_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    if (call_type & SRV_UCM_VOICE_CALL_TYPE_SIM3)
    {
        sim |= MMI_SIM3;
    }
#if (MMI_MAX_SIM_NUM == 4)
    if (call_type & SRV_UCM_VOICE_CALL_TYPE_SIM4)
    {
        sim |= MMI_SIM4;
    }
#endif /* (MMI_MAX_SIM_NUM == 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */

    return sim;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_copy_act_req
 * DESCRIPTION
 *  copy action request structure
 * PARAMETERS
 *  op              [IN]    operation code
 *  from            [IN]    data
 * RETURNS
 *  void*
 *****************************************************************************/
void *mmi_ss_copy_act_req(srv_ss_act_enum op, void *from)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *to;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (op)
    {
        case SRV_SS_ACT_CALL_FORWARD:
            to = OslMalloc(sizeof(srv_ss_call_forward_req_struct));
            memcpy(to, from, sizeof(srv_ss_call_forward_req_struct));
            break;

        case SRV_SS_ACT_CALL_BAR:
            to = OslMalloc(sizeof(srv_ss_call_bar_req_struct));
            memcpy(to, from, sizeof(srv_ss_call_bar_req_struct));
            break;

        case SRV_SS_ACT_CALL_WAIT:
            to = OslMalloc(sizeof(srv_ss_call_wait_req_struct));
            memcpy(to, from, sizeof(srv_ss_call_wait_req_struct));
            break;

        case SRV_SS_ACT_SS_OPERATION:
            to = OslMalloc(sizeof(srv_ss_operation_req_struct));
            memcpy(to, from, sizeof(srv_ss_operation_req_struct));
            break;

        case SRV_SS_ACT_ABORT:
            to = OslMalloc(sizeof(srv_ss_abort_req_struct));
            memcpy(to, from, sizeof(srv_ss_abort_req_struct));
            break;

        case SRV_SS_ACT_CALL_IDENTIFICATION:
        case SRV_SS_ACT_CNAP:
        case SRV_SS_ACT_CCBS:
        case SRV_SS_ACT_EMLPP:
        case SRV_SS_ACT_USSD:
        default:
            to = NULL;
            break;
    }

    return to;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_ss_copy_act_rsp
 * DESCRIPTION
 *  copy action response structure
 * PARAMETERS
 *  op              [IN]    operation code
 *  from            [IN]    data
 * RETURNS
 *  void*
 *****************************************************************************/
void *mmi_ss_copy_act_rsp(srv_ss_act_enum op, void *from)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *to;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!from)
    {
        return NULL;
    }

    switch (op)
    {
        case SRV_SS_ACT_CALL_FORWARD:
            to = OslMalloc(sizeof(srv_ss_call_forward_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_call_forward_rsp_struct));
            break;

        case SRV_SS_ACT_CALL_BAR:
            to = OslMalloc(sizeof(srv_ss_call_bar_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_call_bar_rsp_struct));
            break;

        case SRV_SS_ACT_CALL_WAIT:
            to = OslMalloc(sizeof(srv_ss_call_wait_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_call_wait_rsp_struct));
            break;

        case SRV_SS_ACT_CALL_IDENTIFICATION:
            to = OslMalloc(sizeof(srv_ss_call_id_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_call_id_rsp_struct));
            break;

        case SRV_SS_ACT_CNAP:
            to = OslMalloc(sizeof(srv_ss_cnap_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_cnap_rsp_struct));
            break;

        case SRV_SS_ACT_CCBS:
            to = OslMalloc(sizeof(srv_ss_ccbs_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_ccbs_rsp_struct));
            break;

        case SRV_SS_ACT_EMLPP:
            to = OslMalloc(sizeof(srv_ss_emlpp_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_emlpp_rsp_struct));
            break;

        case SRV_SS_ACT_USSD:
            to = OslMalloc(sizeof(srv_ss_ussd_rsp_struct));
            memcpy(to, from, sizeof(srv_ss_ussd_rsp_struct));
            break;

        case SRV_SS_ACT_SS_OPERATION:
        case SRV_SS_ACT_ABORT:
        default:
            to = NULL;
            break;
    }

    return to;
}





