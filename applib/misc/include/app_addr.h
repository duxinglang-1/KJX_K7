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
 * app_addr.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines address encode/decode function prototype.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _APP_ADDR_H
#define _APP_ADDR_H

extern kal_uint16 applib_addr_bcd_byte_len(char *str, kal_uint16 n);

extern kal_uint16 applib_addr_bcd_strlen(kal_uint8 *bcd_array, kal_uint16 n);

extern kal_uint8 applib_addr_bcd_char_2_digit(kal_uint8 ch);

extern char applib_addr_bcd_digit_2_char(kal_uint8 digit);

extern void applib_addr_bcd_2_string(kal_uint8 *bcd_array, kal_uint16 size, char *buf, kal_uint16 buf_size);

extern kal_uint16 applib_addr_gsm7_strlen(kal_uint8 *gsm7_array, kal_uint16 size);

extern void applib_addr_gsm7_2_string(kal_uint8 *gsm7_array, kal_uint8 *buf, kal_uint16 buf_size);

extern kal_uint16 applib_addr_number_strlen(kal_uint8 *src, kal_uint16 src_size);

extern void applib_addr_number_2_string(kal_uint8 *src, kal_uint16 src_size, char *dst, kal_uint16 dst_size);

extern kal_uint16 applib_addr_ipv4_strlen(kal_uint8 *ipv4_array, kal_uint16 size);

extern void applib_addr_ipv4_2_string(kal_uint8 *src, kal_uint16 src_size, char *dst, kal_uint16 dst_size);

extern void applib_addr_string_2_ipv4(char *src, kal_uint8 *dst, kal_uint16 dst_size);

extern void applib_addr_string_2_bcd(char *src, kal_uint16 src_size, kal_uint8 *dst, kal_uint16 dst_size);


#endif  /* _APP_ADDR_H */

