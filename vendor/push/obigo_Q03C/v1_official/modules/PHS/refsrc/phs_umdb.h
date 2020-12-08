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
 

/*
 * Copyright (C) Obigo AB, 2002-2007.
 * All rights reserved.
 * 
 * This software is covered by the license agreement between
 * the end user and Obigo AB, and may be 
 * used and copied only in accordance with the terms of the 
 * said agreement.
 * 
 * Obigo AB assumes no responsibility or 
 * liability for any errors or inaccuracies in this software, 
 * or any consequential, incidental or indirect damage arising
 * out of the use of the software.
 */

/*******************************************************************************
 *
 * Filename:
 * ---------
 * phs_umdb.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * 
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/



/* ARK OLD CODE FOR PMG START */

#ifndef _phs_umdb_h
#define _phs_umdb_h

#include "pmg_if.h"
/*
#ifndef _phs_cfg_h
#error phs_cfg.h must be included before phs_umdb.h!
#endif
*/
#ifdef PHS_CONFIG_WAP_PUSH_MESSAGES
/*

#ifndef  _umdb_acc_h
#error umdb_acc.h must be included before phs_umdb.h!
#endif

#ifndef _phs_main_h
#error umdb_main.h must be included before phs_umdb.h!
#endif

#ifndef  _phs_sig_h
#error umdb_sig.h must be included before phs_umdb.h!
#endif

#ifndef  _phs_attr_h
#include "phs_attr.h"
#endif


extern umdb_acc_pck_handle_t *umdb_pck_handle;


void
phs_umdb_init (void);
*/

/* ARK OLD CODE FOR PMG END */

/* ARK NEW CODE */


/* ARK NEW CODE END */

int
phs_umdb_handle_external_signal (MSF_UINT8    srcModule,
                                 MSF_UINT16   signal,
                                 void        *p);


void
phs_umdb_get_msg (MSF_UINT16  transaction_id,
                  char       *attribute,
                  MSF_UINT8   msg_type);

void
phs_umdb_delete_msg (MSF_UINT32 msg_id, MSF_UINT8 is_replace);

void
phs_umdb_create_msg (phs_msg_list_t  *msg,
                     MSF_UINT8        msg_type);

void
phs_umdb_content_data_route (MSF_UINT8 src_modId, char* startOptions, 
                         pmg_content_data_t* contentData, int sendAck, MSF_UINT8 id);


umdb_msg_t*
phs_umdb_get_msg_from_list (umdb_msg_list_handle_t *list_handle);

MSF_BOOL
phs_umdb_get_attribute_read (umdb_attr_key_value_list_handle_t *key_value_list);

MSF_UINT8
phs_umdb_get_attribute_sl_priority (umdb_attr_key_value_list_handle_t *key_value_list);

MSF_UINT32
phs_umdb_get_attribute_created (umdb_attr_key_value_list_handle_t *key_value_list);

/*****************************************************************************
 * Functions to delete reply data from UMDB.
 *****************************************************************************/

void
phs_umdb_free_get_data (void *oper_data);

#endif /* PHS_CONFIG_WAP_PUSH_MESSAGES */

#endif /* _phs_umdb_h */
