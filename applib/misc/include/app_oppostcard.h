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
 * app_oppostcard.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains prototype for Postcard MMS utilities.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _APP_OPPOSTCARD_H
#define _APP_OPPOSTCARD_H

//#include "PhoneBookGprot.h"

#include "custom_phb_config.h"
#include "kal_general_types.h"


#define MMS_POSTCARD_TEXT_PREFIX "*GlobalPostcard*"
#define MMS_POSTCARD_TEXT_TOKEN "*"
#define MMS_POSTCARD_RECIPIENT_NUM_TOKEN 'N'
#define MMS_POSTCARD_RECIPIENT_NUM_SPACE 10     /* MMS_POSTCARD_RECIPIENT_NUM_TOKEN*8bit */
#define MMS_POSTCARD_BUF_SIZE (6 /* star */ + 1 /* space */ + (MMI_PHB_NAME_LENGTH + MMI_PHB_ADDRESS_LENGTH * 6) * MMS_POSTCARD_MAX_UTF8_ENCODING_LENGTH + 1 /* null character */)
#define MMS_POSTCARD_MAX_ENCODING_LENGTH 4
#define MMS_POSTCARD_MAX_BUF_SIZE 2048
#define MMS_POSTCARD_MAX_UTF8_ENCODING_LENGTH 3

typedef void *(*applib_oppostcard_mem_alloc_fn) (kal_uint32, void*);
typedef void (*applib_oppostcard_mem_free_fn) (void *, void*);

typedef struct
{
    applib_oppostcard_mem_alloc_fn alloc_fn;
    applib_oppostcard_mem_free_fn free_fn;
    void *user_data;
} applib_oppostcard_mem_func_struct;

typedef struct applib_oppostcard_file_offset_struct_st
{
    kal_uint32 offset;
    struct applib_oppostcard_file_offset_struct_st *prev;
    struct applib_oppostcard_file_offset_struct_st *next;
} applib_oppostcard_file_offset_struct;

typedef struct
{
    kal_char name[(MMI_PHB_NAME_LENGTH + 1) * MMS_POSTCARD_MAX_UTF8_ENCODING_LENGTH];
    kal_char additional[(MMI_PHB_ADDRESS_LENGTH + 1) * MMS_POSTCARD_MAX_UTF8_ENCODING_LENGTH];
    kal_char street[(MMI_PHB_ADDRESS_LENGTH + 1) * MMS_POSTCARD_MAX_UTF8_ENCODING_LENGTH];
    kal_char city[(MMI_PHB_ADDRESS_LENGTH + 1) * MMS_POSTCARD_MAX_UTF8_ENCODING_LENGTH];
    kal_char postalcode[(MMI_PHB_ADDRESS_LENGTH + 1) * MMS_POSTCARD_MAX_UTF8_ENCODING_LENGTH];
    kal_char state[(MMI_PHB_ADDRESS_LENGTH + 1) * MMS_POSTCARD_MAX_UTF8_ENCODING_LENGTH];
    kal_char country[(MMI_PHB_ADDRESS_LENGTH + 1) * MMS_POSTCARD_MAX_UTF8_ENCODING_LENGTH];
} mms_postcard_address_struct;

extern kal_bool applib_oppostcard_encode_text_content(
                    applib_oppostcard_mem_func_struct *mem_func,
                    const kal_wchar *filepath,
                    const kal_char *greeting_text,
                    const void *recipient);
extern kal_bool applib_oppostcard_decode_text_content(
                    applib_oppostcard_mem_func_struct *mem_func,
                    const kal_wchar *filepath,
                    kal_char **greeting_text,
                    void **recipient);
extern void applib_oppostcard_free_memory(
                    applib_oppostcard_mem_func_struct *mem_func,
                    kal_char *greeting_text,
                    void *recipient);

#endif /* _APP_OPPOSTCARD_H */

