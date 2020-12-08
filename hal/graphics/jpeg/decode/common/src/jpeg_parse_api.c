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
 *   jpeg_parse_api.c
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "jpeg_enum_int.h"
#include "jpeg_parse_int.h"

JPEG_STATUS_ENUM jpegParserGetImageInfo(STFSAL           *pSource,
                                        JPEG_FILE_INFO   **ppInfo)
{
   FSAL_Status       FSALStatus;
   kal_uint32        fileSize;
   JPEG_FILE_INFO    *pParser;
   EXIF_APP1_INFO    *pApp1Info;
   JPEG_STATUS_ENUM  parseStatus;

   if (NULL == ppInfo)
   {
      return JPEG_STATUS_INVALID_PARAMETER;
   }

   pParser = (JPEG_FILE_INFO*)get_ctrl_buffer(sizeof(JPEG_FILE_INFO));
   if (NULL == pParser)
   {
      return JPEG_STATUS_DEC_ERROR_INVALID_BUFFER;
   }

   FSALStatus = FSAL_GetFileSize(pSource, &fileSize);
   if (FSAL_OK != FSALStatus)
   {  
      free_ctrl_buffer(pParser);
      return JPEG_STATUS_IO_ERROR;
   }

   memset(pParser, 0x0, sizeof(JPEG_FILE_INFO));

   pApp1Info = (EXIF_APP1_INFO*)get_ctrl_buffer(sizeof(EXIF_APP1_INFO));

   memset(pApp1Info, 0x0, sizeof(EXIF_APP1_INFO));

   pParser->app1Info = pApp1Info;
   
   jpeg_parser_parse_reset_internal(pParser,
                                    pSource,
                                    fileSize,
                                    pApp1Info,
                                    sizeof(EXIF_APP1_INFO));

   parseStatus = jpeg_parser_parse_start_internal(pParser, KAL_FALSE);
   if (JPEG_STATUS_OK != parseStatus)
   {
      if (NULL != pParser->app1Info)
      {
         free_ctrl_buffer(pParser->app1Info);
      }
     
      free_ctrl_buffer(pParser);
      *ppInfo = NULL;
   }
   else
   {
      *ppInfo = pParser;
   }

   return parseStatus;
}


JPEG_STATUS_ENUM jpegParserGetSourceDimension(JPEG_FILE_INFO   *pParser,
                                              kal_int32        *pWidth,
                                              kal_int32        *pHeight)
{
   if ((NULL == pParser) &&
       (NULL == pWidth) &&
       (NULL == pHeight))
   {
      return JPEG_STATUS_INVALID_PARAMETER;
   }

   return jpeg_parser_get_source_dimension(pParser, pWidth, pHeight);
}


JPEG_STATUS_ENUM jpegParserGetImageDimension(JPEG_FILE_INFO *pParser,
                                             kal_int32      *pWidth,
                                             kal_int32      *pHeight)
{
   if ((NULL == pParser) &&
       (NULL == pWidth) &&
       (NULL == pHeight))
   {
      return JPEG_STATUS_INVALID_PARAMETER;
   }

   return jpeg_parser_get_image_dimension(pParser, pWidth, pHeight);
}


JPEG_STATUS_ENUM jpegParserReleaseImageInfo(JPEG_FILE_INFO  *pParser)
{
   if (NULL != pParser->app1Info)
   {
      free_ctrl_buffer(pParser->app1Info);
   }
   
   free_ctrl_buffer(pParser);

   return JPEG_STATUS_OK;
}


JPEG_STATUS_ENUM jpegParserGetImageDescription(JPEG_FILE_INFO *pParser,
                                             kal_uint8      *pImageDescription)
{
   if ((NULL == pParser) &&
       (NULL == pImageDescription))
   {
      return JPEG_STATUS_INVALID_PARAMETER;
   }

   return jpeg_parser_get_image_description(pParser, pImageDescription);
}



