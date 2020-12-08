/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vcui_sms_composer_iprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author: Keyu Xiang
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCUI_SMS_COMPOSER_GPROT_H__
#define __VCUI_SMS_COMPOSER_GPROT_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#ifdef __MMI_SMS_COMPOSER__

#include "vfx_datatype.h"
#include "MMIDataType.h"

#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/


/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    EVT_ID_CUI_SMS_COMPOSER_CLOSE = VCUI_SMS_COMPOSER,
    EVT_ID_CUI_SMS_COMPOSER_SMS_SENT,
    EVT_ID_CUI_SMS_COMPOSER_END
}VcuiSmsComposerEventEnum;

typedef struct
{
    MMI_EVT_GROUP_PARAM_HEADER      /* in header: evt_id, size, user_data, sender_id */
}VcuiSmsComposerEventStruct;


/* This enum is used to specify the type of address. Email or number. */
typedef enum
{
    VCUI_SMS_COMPOSER_ADDRESS_TYPE_PHONE_NUMBER = 0,   /* Phone number. */
    VCUI_SMS_COMPOSER_ADDRESS_TYPE_EMAIL,          /* Email address. */
    VCUI_SMS_COMPOSER_ADDRESS_TYPE_IP,             /* IP address. */
    VCUI_SMS_COMPOSER_ADDRESS_TYPE_TOTAL_NUM       /* Max number of address type. */
} VcuiSmsComposerAddressTypeEnum;

/* This enum is used to specify the operation type. */
typedef enum
{
    VCUI_SMS_COMPOSER_OPERATION_NEW = 0,        /* NEW SMS. */
    VCUI_SMS_COMPOSER_OPERATION_REPLY,      /* REPLY SMS. */
    VCUI_SMS_COMPOSER_OPERATION_FORWARD,    /* FORWARD SMS. */
    VCUI_SMS_COMPOSER_OPERATION_EDIT        /* EDIT SMS. */
} VcuiSmsComposerOperationEnum;

/* This structure contains the linked list for address information. */
typedef struct vcui_sms_composer_addr_struct_t
{
    struct vcui_sms_composer_addr_struct_t *next;        /* Next address, not uesed currently */
    struct vcui_sms_composer_addr_struct_t *previous;    /* Previous address, not uesed currently */
    VfxWChar *addr;                                      /* ascii for phone number while ucs2 for email address. NULL terminator is needed. */
    VcuiSmsComposerAddressTypeEnum type;                 /* only support phone number type currently */
} VcuiSmsComposerAddrStruct;

typedef struct
{
    VfxS32 addr_num;                        /* Max addresses      */  
    VcuiSmsComposerAddrStruct *addr;        /* Addresses linklist */
    
    VfxS32 text_num;                        /* content text number */
    VfxWChar *text_buffer;                  /* content text buffer */
    
    VcuiSmsComposerOperationEnum operation;
    U32 msg_id;                             /*  must set if operation != VCUI_SMS_COMPOSER_OPERATION_NEW */
    mmi_sim_enum sim_id;                    /*  must set if operation != VCUI_SMS_COMPOSER_OPERATION_NEW */
    
    void *info;         /* Info. SMS use msg ID/Index to pass */
    U8 app_id;          /* Application id, ex: UnifiedMessage, UnifiedComposer, MMS Application */
} VcuiSmsComposerEntryStruct;


/* DESCRIPTION
 *  Create an instance of "Compose a sms message CUI", 
 *  Allow user to composer a sms message and send.
 * PARAMETERS
 *  parent_grp_id           : [IN]  group id of caller
 * RETURNS
 *  id of the new created CUI
 */
mmi_id vcui_sms_composer_create(mmi_id parent_grp_id);

/* DESCRIPTION
 *  Run function of "Compose a sms message CUI".
 *  Allow user to composer a sms message and send
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void vcui_sms_composer_run(mmi_id cui_id);

/* DESCRIPTION
 *  Close function of "Compose a sms message CUI", 
 *  Caller should be responsible for closing CUI it created.
 * PARAMETERS
 *  cui_id                  : [IN]  id of CUI
 * RETURNS
 *  void
 */
void vcui_sms_composer_close(mmi_id cui_id);

/* DESCRIPTION
 *  Allow user to set entry data
 * PARAMETERS
 *  caller                  : [IN]  group id of caller
 *  provider_id             : [IN]  provider to send
 * RETURNS
 *  void
 */
void vcui_sms_composer_set_entry_data (mmi_id cui_id, 
                                       VcuiSmsComposerEntryStruct *entryData);

#ifdef __cplusplus
}
#endif

#endif /* __MMI_SMS_COMPOSER__ */
#endif /* __VCUI_SMS_COMPOSER_GPROT_H__ */

