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
 *  SmsDispatchSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service dispatch Handler Internal Header File
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef __SMS_DISPATCH_HANDLER_SRV_H__
#define __SMS_DISPATCH_HANDLER_SRV_H__
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "SmsSrvGprot.h"

/* define event structure */ 
typedef struct {
    MMI_EVT_PARAM_HEADER
    void* data;
    U32 msg_id;
    U16 sim_id;
} mmi_evt_sms_disp_struct; 

/* define callback structure */ 
typedef struct {
    void* data;
    void* user_data;
    U32 msg_id;
    U16 sim_id;
} srv_sms_disp_cb_struct;

typedef void(*SrvSmsDispCallbackFunc)(srv_sms_disp_cb_struct* callback_data);

/* the following api is handle send message dispatch */
typedef enum
{
    SRV_SMS_FILE_DETAIL_FROFILE = 0x00,
    SRV_SMS_FILE_PROFILE_NUM,
    SRV_SMS_FILE_COMMON_PROFILE,
    SRV_SMS_FILE_PRE_STORAGE,
    SRV_SMS_FILE_SMS_WAITING,
    SRV_SMS_FILE_MAIL_ADDRESS,
    SRV_SMS_FILE_MBI,
    SRV_SMS_FILE_MSP,
    SRV_SMS_CB_SUBSCRIBE,
    SRV_SMS_CB_MODE,

    SRV_SMS_FILE_INDEX_ALL
} srv_sms_sim_file_index_enum;

extern void srv_sms_dispatch_init(void);

extern MMI_BOOL srv_sms_write_sim_req(
                    srv_sms_sim_file_index_enum file_index,
                    U16 record_index,
                    U16 record_size,
                    void* data,
                    srv_sms_sim_enum sim_id,
                    SrvSmsDispCallbackFunc callback,
                    void *user_data);
                    
extern MMI_BOOL srv_sms_read_sim_req(
                    srv_sms_sim_file_index_enum file_index,
                    U16 record_index,
                    U16 record_size,
                    srv_sms_sim_enum sim_id,
                    SrvSmsDispCallbackFunc callback,
                    void *user_data);

/* the following api is handle send message dispatch */
extern MMI_BOOL srv_sms_send_sms(void *data, srv_sms_sim_enum sim_id, SrvSmsDispCallbackFunc callback, void *user_data);
extern MMI_BOOL srv_sms_abort_sendig_sms(
                    void *data,
                    srv_sms_sim_enum sim_id,
                    SrvSmsDispCallbackFunc callback,
                    void *user_data);

/* the following api is handle res message */
extern void srv_sms_disp_send_msg_req(
       U32 msg_id,
       srv_sms_sim_enum sim_id,
       void *data);


#endif /* __SMS_DISPATCH_HANDLER_SRV_H__ */ 

