/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   jpeg_parse_int.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Structure definition of JPEG parser.
 *
 * Author:
 * -------
 * -------
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __JPEG_PARSE_INT_H__
#define __JPEG_PARSE_INT_H__

#include "fsal.h"
#include "jpeg_parse_structure.h"
#include "jpeg_marker.h"

#ifdef __cplusplus
extern "C" {
#endif

JPEG_STATUS_ENUM jpeg_parser_parse_reset_internal(JPEG_FILE_INFO   *pParser,
                                                  STFSAL           *pSource,
                                                  kal_uint32       fileSize,
                                                  void             *pAPP1Buffer,
                                                  kal_uint32       bufferSize);


JPEG_STATUS_ENUM jpeg_parser_parse_start_internal(JPEG_FILE_INFO  *pParser,
                                                  kal_bool        forceImmediateSOI);


JPEG_STATUS_ENUM jpeg_parser_get_encode_process(JPEG_FILE_INFO             *pParser,
                                                JPEG_ENCODE_PROCESS_ENUM   *pProcess);


JPEG_STATUS_ENUM jpeg_parser_get_source_dimension(JPEG_FILE_INFO  *pParser,
                                                  kal_int32       *pWidth,
                                                  kal_int32       *pHeight);


JPEG_STATUS_ENUM jpeg_parser_get_image_dimension(JPEG_FILE_INFO   *pParser,
                                                 kal_int32        *pWidth,
                                                 kal_int32        *pHeight);


JPEG_STATUS_ENUM jpeg_parser_get_thumbnail_info(JPEG_FILE_INFO             *pParser,
                                                JPEG_THUMBNAIL_TYPE_ENUM   *pTNType,
                                                kal_int32                  *pOffset,
                                                kal_int32                  *pSize,
                                                kal_int32                  *pWidth,
                                                kal_int32                  *pHeight);


JPEG_STATUS_ENUM jpeg_parser_get_quick_view_info(JPEG_FILE_INFO            *pParser,
                                                 JPEG_THUMBNAIL_TYPE_ENUM  *pTNType,
                                                 kal_int32                 *pOffset,
                                                 kal_int32                 *pSize,
                                                 kal_int32                 *pWidth,
                                                 kal_int32                 *pHeight);


JPEG_STATUS_ENUM jpeg_parser_get_image_description(JPEG_FILE_INFO   *pParser,
                                                 kal_uint8        *pImageDescription);

#ifdef __cplusplus
}
#endif

#endif  // __JPEG_PARSE_INT_H__
