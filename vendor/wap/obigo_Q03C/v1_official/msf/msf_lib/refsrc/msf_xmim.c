#ifndef Q03C_IND_MOD_ARCH_SUPPORT
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
 * Copyright (C) Obigo AB, 2002-2006.
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
 *
 */
/*
 * msf_xmim.c
 * 
 * Additional Mime Type Support
 *
 *
 * Place in this file all additional Mime Types that should be
 * possible to recognise. As an example, two  additional 
 * mime types are included. These can be removed
 * if not required.
 * If no additional mime type support is required, this
 * whole file can be left empty.
 */


/*******************************************************************************
 *
 * Filename:
 * ---------
 * msf_xmim.c
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
 * 
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#include "msf_def.h"
#include "msf_xmim.h"


/*
 * This is the table that holds information about all additional
 * mime types that are supported.
 *
 * The first field, 'value', should hold a registered integer
 * value if such are available else a number int the range 0x010000 
 * to 0x7FFFFF and not in conflict with any other type defined 
 * in msf_hdr.h must be used.
 *
 * The second field, 'mime', should hold a string with the mime type.
 *
 * The third field, 'extension', should hold a string with the extension
 * to be associated with this mime type.
 *
 */
#if MSF_NUMBER_OF_ADDITIONAL_MIME_TYPES > 0

const msf_xmim_entry_t msf_xmim_table[MSF_NUMBER_OF_ADDITIONAL_MIME_TYPES] = {
  {0x010000, "text/x-imelody", "imy"},   
  {0x010001, "audio/wav", "wav"},   
  {0x010002, "audio/mpg", "mp3"},
  {0x010003, "application/java-archive", "jar"},
  {0x010004, "text/vnd.sun.j2me.app-descriptor", "jad"},
  {0x010005, "audio/amr-wb", "awb"},
  {0x010006, "video/3gpp", "3gp"},
  {0x010007, "video/x-msvideo", "avi"},
  {0x010008, "video/mpeg", "mp4"},
  {0x010009, "video/mpg", "mp4"},
  {0x01000a, "video/mp4", "mp4"},
  {0x01000b, "audio/m4a", "m4a"},
  {0x01000c, "audio/x-m4a", "m4a"},
  {0x01000d, "audio/aac", "aac"},
  {0x01000e, "audio/x-aac", "aac"},
  {0x01000f, "video/3gp", "3gp"},
  {0x010010, "audio/3gpp", "3gp"},
  {0x010011, "audio/mp3", "mp3"},
  {0x010012, "audio/mpg3", "mp3"},
  {0x010013, "video/avi", "avi"}, 
  {0x010014, "image/x-MS-bmp", "bmp"},
  {0x010015, "audio/sp-midi", "mid"},  
  {0x010016, "audio/x-midi", "mid"},  
  {0x010017, "audio/x-ms-wma", "wma"},
  {0x010018, "audio/wma", "wma"},  
  {0x010019, "audio/spmidi", "mid"},
  {0x01001a, "audio/x-mp3", "mp3"},  
  {0x01001b, "audio/mp4", "m4a"},
  {0x01001c, "audio/x-aiff", "aiff"},
  {0x01001d, "audio/x-aiff", "aif"},
  {0x01001e, "audio/x-aiff", "aifc"},
  {0x01001f, "audio/basic", "au"},
  {0x010020, "audio/basic", "snd"},
  {0x010021, "video/3gpp2", "3g2"}
};

#endif
#endif/*Q03C_IND_MOD_ARCH_SUPPORT*/
