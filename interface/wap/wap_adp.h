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
 *   wap_adp.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains prototypes for WAP adaptation APIs
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                              HISTORY
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
#ifndef _WAP_ADP_H
#define _WAP_ADP_H 

#include "kal_general_types.h"
#include "stack_config.h"

#define WAP_MAX_URL_LENGTH (255)    /* numeber of ascii characters, bytes */
#define WAP_MAX_SEARCH_URL_LENGTH (512)  /* For search, in bytes */

/*****************************************************************************
* FUNCTION
*    wap_get_service_module
* DESCRIPTION
*    The message send to WAP or MMS might be handled by different module/task due to different
* architecture design of each solution. Before sending primitive to WAP/MMS, the module id has to
* be obtained by invoking this function. This function returns the destination module id that
* will handle the message supplied.
* PARAMETERS
*  msg_id : [IN]  The message id to be sent
* RETURNS
*  Returns the module id that handles the provided message
*****************************************************************************/
extern module_type wap_get_service_module(kal_uint32 msg_id);


/*****************************************************************************
* FUNCTION
*    wap_is_ready
* DESCRIPTION
*    This function is to check if WAP service is ready to serve incoming request.
* PARAMETERS
*  void
* RETURNS
*  1 if WAP service is ready, 0 otherwise
*****************************************************************************/
extern int wap_is_ready(void);


/*****************************************************************************
* FUNCTION
*    wap_is_init
* DESCRIPTION
*    This function is to check if WAP service is in initialization stage.
* PARAMETERS
*  void
* RETURNS
*  1 if WAP service is still in initialization stage, 0 if it is ready or it is not started yet.
*****************************************************************************/
extern int wap_is_init(void);


/*****************************************************************************
* FUNCTION
*    WAP_memAllocExt
* DESCRIPTION
*    This function is to Allocate memory from WAP pool for external usage.
*    Memory allocted with tis function should be freed by calling WAP_memFreeExt.
*    If memory is not available, it will return NULL.
*    Since WAP has limited memory, this function should be used with care.
* PARAMETERS
*  void
* RETURNS
*  1 if WAP service is ready, 0 otherwise
*****************************************************************************/
extern void* WAP_memAllocExt(int size);


/*****************************************************************************
* FUNCTION
*    WAP_memFreeExt
* DESCRIPTION
*    This function frees memory allocated with WAP_memAllocExt.
* PARAMETERS
*  void
* RETURNS
*  1 if WAP service is ready, 0 otherwise
*****************************************************************************/
extern void WAP_memFreeExt(void* ptr);

#endif /* _WAP_ADP_H */
