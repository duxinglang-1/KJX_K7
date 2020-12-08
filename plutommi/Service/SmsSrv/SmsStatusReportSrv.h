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
 *  SmsStatusReportSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Status Report Header File
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SRV_SMS_STATUS_REPROT_H__
#define __SRV_SMS_STATUS_REPROT_H__
#include "MMI_features.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "SmsSrvGprot.h"

typedef struct
{
    U8 fo;
    U8 discharge_time[7];
    U8 number[SRV_SMS_MAX_ADDR_LEN + 1];
    U8 tp_st;  /* smsal_st_enum */
    U8 msg_ref;
} srv_sms_status_report_ind_struct;

#ifdef __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__
typedef struct
{
    U8 number[SRV_SMS_MAX_ADDR_LEN + 1];
    U8 total_seg;
    U8 curr_seg;
    U8 curr_msg_ref;
    srv_sms_sr_status_enum curr_status;
    srv_sms_sim_enum sim_id;
    MMI_BOOL is_hidden;
} srv_sms_sr_add_struct;

extern void srv_sms_status_report_init(void);
extern U16 srv_sms_sr_add_report(srv_sms_sr_add_struct *add_data);
extern MMI_BOOL srv_sms_sr_update_report(
                    U16 report_id,
                    U8 curr_seg,
                    U8 msg_ref,
                    U32 timestamp,
                    srv_sms_sr_status_enum status);
extern U16 srv_sms_sr_unhide_report(U16 report_id);
extern void srv_sms_sr_del_report(U16 report_id);
extern srv_sms_sr_status_enum srv_sms_sr_get_seg_status(U16 report_id, U8 curr_seg);
extern U8 srv_sms_sr_get_total_status(U16 report_id, srv_sms_sr_status_enum sr_status[]);
#endif /* __MMI_MESSAGES_SINGLE_DELIVERY_REPORT__ */

extern void srv_sms_status_report_ind_hdlr(
                srv_sms_status_report_ind_struct *ind_data,
                srv_sms_sim_enum sim_id);

#endif /* __SRV_SMS_STATUS_REPROT_H__ */

