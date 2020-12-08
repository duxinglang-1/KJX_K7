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
 *  SmsStorageManagerSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Storage Manager core codes
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *============================================================================
 *****************************************************************************/
#ifndef __SRV_SMS_STORAGE_TCARD_SRV_H__
#define __SRV_SMS_STORAGE_TCARD_SRV_H__

#include "MMI_features.h"
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "ps_public_enum.h"
#include "stack_config.h"
#include "customer_ps_inc.h"
#include "nvram_common_defs.h"
#include "Fs_gprot.h"
#include "TcardSrvGprot.h"
#include "SmsProtSrv.h"
#include "SmsStorageSrv.h"


/**************************************************************
* MARCO
**************************************************************/
#define SRV_SMS_TCARD_INVALID_ENTRY_ID       0xFFFF

#define SRV_SMS_MAX_TCARD_ENTRY         SRV_TCARD_MAX_MSG_NUM



/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    U8 segment;
    U8 type;
    U8 read_count;
    U8 status;
    U8 msg_ref;
    U8 tp_st;
    U16 prev_pdu_id;
    U16 next_pdu_id;
} srv_sms_tcard_pdu_node_struct;

typedef struct
{
    /* srv_sms_status_enum */
    U8 status;
	U8 dcs;
	U8 ext_status;
    U8 resend_count;
    /* <<-- msg node compare range start */
    U8 storage_type;
    U8 mti;
	U8 pid;

    /* Concatenated inforamtion */
    U8 total_seg;
    U8 start_seg;
    U16 ref_num;
	U16 sim_id;
    /* Extension address number */
    U16 ext_addr_num;
    /* Start Externsion Address ID */
    U16 start_addr_id;
    U16 port_num;
    U16 start_pdu_id;
    S8 number[SRV_SMS_MAX_ADDR_LEN + 1];
    U16 content[SRV_SMS_TCARD_MSG_INFO_CONTENT_LEN + 1];
    U32 timestamp;
} srv_sms_tcard_msg_node_struct;

/**************************************************************
* Global Variables Declaration
**************************************************************/ 

extern srv_sms_tcard_pdu_node_struct srv_sms_tcard_pdu_list[SRV_SMS_MAX_TCARD_ENTRY];
#ifdef __SRV_SMS_MULTI_ADDR__
extern srv_sms_tcard_addr_node_struct srv_sms_tcard_addr_list[SRV_SMS_MAX_TCARD_ADDR_ENTRY];
#endif /* __SRV_SMS_MULTI_ADDR__ */


/**************************************************************
* Extern Function Declaration
**************************************************************/
extern srv_sms_tcard_msg_node_struct * srv_sms_get_tcard_msg_list();


/**************************************************************
* Static Variables Defination
**************************************************************/
//static srv_sms_tcard_entry_struct srv_sms_tcard_msg_list[SRV_SMS_MAX_TCARD_ENTRY];  

/**************************************************************
* Static Function Declaration
**************************************************************/




#endif /*__SRV_SMS_STORAGE_TCARD_SRV_H__*/
#endif





