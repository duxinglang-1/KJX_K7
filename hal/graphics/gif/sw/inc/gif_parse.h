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
 *  gif_parse.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  parse utility for gif decoder
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _GIF_FSAL_H_
#define _GIF_FSAL_H_

#include "fsal.h"
#include "kal_general_types.h"

void _gif_fsal_gets (STFSAL *h, kal_uint8* array, kal_uint16 n);
kal_uint32 _gif_fsal_tell (STFSAL *h);
kal_bool _gif_fsal_is_eof (STFSAL* h);

kal_uint8 _gif_fsal_peek_u8 (STFSAL* h);
kal_uint8 _gif_fsal_peek_u8_n (STFSAL* h, kal_uint32 offset);

kal_uint8 _gif_fsal_get_u8(STFSAL* h);
kal_uint16 _gif_fsal_get_u16 (STFSAL* h);
kal_uint32 _gif_fsal_get_u24 (STFSAL* h);
void _gif_error_raise(void);

typedef enum
{
   GIF_FSAL_OK = 0,
   GIF_FSAL_FAIL,
   GIF_FSAL_RSVD
}GIF_FSAL_STATUS_ENUM;
GIF_FSAL_STATUS_ENUM _gifv2_fsal_gets (STFSAL *h, kal_uint8* array, kal_uint16 n);
GIF_FSAL_STATUS_ENUM _gifv2_fsal_tell (STFSAL *h, kal_uint32 *cur_position);
GIF_FSAL_STATUS_ENUM _gifv2_fsal_is_eof (STFSAL* h, kal_bool *isEof);
GIF_FSAL_STATUS_ENUM _gifv2_fsal_get_u8(STFSAL* h, kal_uint8* val);
GIF_FSAL_STATUS_ENUM _gifv2_fsal_peek_u8 (STFSAL* h, kal_uint8* val);
GIF_FSAL_STATUS_ENUM _gifv2_fsal_get_u16 (STFSAL* h, kal_uint16 *output);
GIF_FSAL_STATUS_ENUM _gifv2_fsal_get_u24 (STFSAL* h, kal_uint32 *output);
GIF_FSAL_STATUS_ENUM _gifv2_fsal_flush (STFSAL* h, kal_uint32 count);
GIF_FSAL_STATUS_ENUM _gifv2_fsal_seek(STFSAL* h, kal_uint32 offset);
GIF_FSAL_STATUS_ENUM _gifv2_fsal_get_size(STFSAL* h, kal_uint32 *cur_filesize);




#endif
