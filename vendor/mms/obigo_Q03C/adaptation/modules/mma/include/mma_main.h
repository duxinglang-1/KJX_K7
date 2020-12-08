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
 *   mma_main.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains functions definitions and functions used by MMA MAIN submodule.
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _MMA_MAIN_H
#define _MMA_MAIN_H

#include "MMI_features.h"
#include "kal_general_types.h"
#include "mma_struct.h"
#include "mma_api.h"

/************************************************************
 * Constants
 ************************************************************/

/**********************************************************************
 * Type definitions
 **********************************************************************/
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
#define MMA_MAIN_NUM_MEM_CARD_SUPPORTED 1


typedef enum
{
    MMA_MAIN_MEM_CARD_STATE_NONE,
    MMA_MAIN_MEM_CARD_STATE_PLUG_IN,
    MMA_MAIN_MEM_CARD_STATE_PLUG_OUT,
    MMA_MAIN_MEM_CARD_STATE_PLUG_OUT_PROCESS,
    MMA_MAIN_MEM_CARD_STATE_PLUG_IN_PROCESS,    
    MMA_MAIN_MEM_CARD_STATE_PLUG_OUT_PROCESS_PLUG_IN_PENDING,
    MMA_MAIN_MEM_CARD_STATE_TOTAL
}mma_main_mem_card_states_enum;


typedef struct 
{
    kal_uint32 Assigned_BIT;
    kal_uint8 status;
}mma_main_assign_bit_struct;





typedef struct
{
   kal_uint8  card_present;
   kal_uint8  card_state;
   kal_uint8  assigned_MSB_index;
   kal_uint8  is_locked;           /*Currently no way to know this*/

} mma_main_mem_card_drv_context_struct;
#endif /* __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__ */


typedef struct
{
    mma_signal_struct *pending_req_list;
#ifdef __MMI_MMS_MEMORY_CARD_STORAGE_SUPPORT__
    mma_main_mem_card_drv_context_struct memory_card_plug_in[MMA_MAIN_NUM_MEM_CARD_SUPPORTED];
#endif
    MSF_BOOL is_notify_sent;
    MSF_BOOL in_usb_mode;
    MSF_BOOL in_terminating;
} mma_main_context_struct;

extern MSF_UINT32 mma_main_get_gmt_time(void);
extern MSF_BOOL mma_main_is_in_usb_mode(void);
extern MSF_BOOL mma_main_is_in_terminate(void);
extern kal_bool mma_main_init(void);
extern kal_bool mma_main_terminate(void);
extern void mma_main_process_int_sig(mma_signal_struct *sig);
extern void mma_main_enter_terminate_mode(void);
extern void mma_main_exit_terminate_mode(void);
#ifdef  __MMI_OP12_MMS_MAX_SIZE_SUPPORT__
kal_uint32 mma_get_setting_max_mms_size(void);
#endif
#ifdef __MMI_OP01_MMS_ADD_SLIDE_TIME_FOR_MIXED_MMS_SUPPORT__
extern kal_uint32 mma_get_setting_slide_timing(void);
#endif /* __MMI_OP01_MMS_ADD_SLIDE_TIME_FOR_MIXED_MMS_SUPPORT__ */
extern kal_bool mma_main_is_storage_type_present(mma_msg_storage_type_enum mem_card);
extern mma_msg_storage_type_enum mma_get_message_storage(kal_uint32 msgid);
extern msf_mms_storage_enum mma_get_mms_type_message_storage(kal_uint32 msgid);
extern kal_uint32 mma_main_encode_msg_id(kal_uint8 storage, kal_uint32 o_msgId);

#endif /* _MMA_MAIN_H */ 

