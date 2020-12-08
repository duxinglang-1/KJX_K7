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
 *  SsCore.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Ss app core prototypes
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
 
#ifndef SS_CORE_H
#define SS_CORE_H


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "SsSrvGprot.h"

#include "kal_non_specific_general_types.h"
#include "MMIDataType.h"
#include "UcmSrvGprot.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_SS_MAX_RESULT_LEN   400

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
typedef struct
{
    srv_ss_result_enum result;
    WCHAR string[MMI_SS_MAX_RESULT_LEN + 1];
} mmi_ss_result_struct;


/***************************************************************************** 
 * Internal Function
 *****************************************************************************/
/* SsCore.c */
extern void mmi_ss_send_abort(mmi_sim_enum sim);
extern void mmi_ss_derive_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out);
extern void mmi_ss_derive_call_forward_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out);
extern void mmi_ss_derive_call_bar_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out);
extern void mmi_ss_derive_call_wait_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out);
extern void mmi_ss_derive_ussd_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out);
extern void mmi_ss_derive_ss_operation_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out);
extern void mmi_ss_derive_call_id_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out);
extern void mmi_ss_derive_cnap_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out);
extern void mmi_ss_derive_ccbs_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out);
extern void mmi_ss_derive_emlpp_result(srv_ss_rsp_struct *info, mmi_ss_result_struct *out);

/* SsUtil.c */
extern mmi_sim_enum mmi_ss_get_sim_by_ucm_call_type(srv_ucm_call_type_enum call_type);
extern void *mmi_ss_copy_act_req(srv_ss_act_enum op, void *from);
extern void *mmi_ss_copy_act_rsp(srv_ss_act_enum op, void *from);




#endif /* SS_CORE_H */
