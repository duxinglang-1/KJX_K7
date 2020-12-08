/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   jam_msg_util.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements J2ME message handler utilities
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __SUN_RI__

#ifndef JAM_MSG_UTIL_H
#define JAM_MSG_UTIL_H


extern mids_list_info_struct *find_mids_info_by_id(kal_uint32 mids_id);
extern void trans_ucs2_to_utf8(kal_char *utf8, kal_wchar *ucs2string);
extern void trans_utf8_to_ucs2(kal_wchar *ucs2string, kal_char *utf8);
extern kal_uint32 get_ucs2_len(kal_wchar *ucs2string);
extern kal_uint32 get_dec_len(kal_uint32 dec);
extern void trans_dec_to_ascii(kal_char *dec_buffer, kal_uint32 dec);
extern mid_struct *find_mid_info_by_id(mids_list_info_struct *mids_info_ptr, kal_uint32 mid_id);
extern kal_wchar *get_string_by_error_code(kal_int32 error_code);

/* DRM Error Code: Must Less Than 0 */
#define JAVA_DRM_NOT_DRM_FILE -1
#define JAVA_DRM_NO_RIGHT -2


#endif /* JAM_MSG_UTIL_H */ 
#endif /* __SUN_RI__ */ 

