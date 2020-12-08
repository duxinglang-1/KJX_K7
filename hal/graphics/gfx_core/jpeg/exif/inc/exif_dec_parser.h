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
 *   exif_dec_parser.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This header file defines the function prototype of EXIF parser.
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
 *============================================================================
 ****************************************************************************/
#ifndef __EXIF_DEC_PARSER_V2_H__
#define __EXIF_DEC_PARSER_V2_H__

#include "kal_general_types.h"
#include "fsal.h"
#include "jpeg_enum_int.h"
#include "exif_dec_structure.h"


/**
 * The EXIF parser APIs are designed to parse the APP1 marker segment for the JPEG parser.
 * The AP should not use these APIs directly; it should call the JPEG parser APIs to 
 * parse the JPEG file and retrieve the related information.
 */


/**
 * @brief               Initialize an APP1 parser.
 * @param app1Info      pointer to a EXIF_APP1_INFO structure
 * @param sourceFile    pointer to the STFSAL structure of the input file
 * @param offsetInFile  the offset of the APP1 marker segment in the image file
 * @return              If the function succeeds, return 1; otherwise return 0.
 * @remarks             The offsetInFile is the start position of the APP1 marker segment in the file.
 */
kal_int32 app1ParserInit(EXIF_APP1_INFO *app1Info, STFSAL *sourceFile, kal_uint32 offsetInFile);



/**
 * @brief            Start the APP1 parsing procedure.
 * @param app1Info   pointer to a EXIF_APP1_INFO structure
 * @return           If the function succeeds, return 1. If there's a file access error occured, return 0.
 *                   If the specified offsetInFile is not the start of an APP1 marker, return -1.
 * @remarks          After the parsing, the offsetInFile member variable of each IFD_INFO will be set accordingly. \n
 *                   If the IFD does not exist, the offsetInFile is set to 0. \n
 *                   If the IFD is corrupted, the offsetInFile is set to 0xFFFFFFFF. \n
 */
kal_int32 app1ParserStart(EXIF_APP1_INFO *app1Info);



/**
 * @brief               Query the information of the TIFF header.
 * @param app1Info      pointer to a EXIF_APP1_INFO structure
 * @param offsetInFile  pointer to an unsigned int to obtain the offset of the TIFF header in the file
 * @param byteOrder     pointer to an unsigned int to obtain the byte ordering field in the TIFF header
 * @return              If the function succeeds, return 1; otherwise return 0.
 * @remarks
 */
kal_int32 app1ParserQueryTIFFHeader(EXIF_APP1_INFO *app1Info, kal_uint32 *offsetInFile, kal_uint32 *byteOrder);



/**
 * @brief               Query the information of the specified IFD.
 * @param app1Info      pointer to a EXIF_APP1_INFO structure
 * @param whichIFD      the specified IFD
 * @param offsetInFile  pointer to a unsigned int to obtain the offset of the specified IFD
 * @param count         pointer to a unsigned int to obtain the number of the fields in the specified IFD
 * @param nextIFDOffset pointer to a unsigned int to obtain the offset of the next IFD
 * @return              If the function succeeds, return 1; otherwise return 0.
 * @remarks
 */
kal_int32 app1ParserQueryIFDInfo(EXIF_APP1_INFO *app1Info, JPEG_APP1_IFD_TYPE_ENUM whichIFD, kal_uint32 *offsetInFile, kal_uint32 *count, kal_uint32 *nextIFDOffset);



/**
 * @brief               Retrieve the tag list of the specified IFD.
 * @param app1Info      pointer to a EXIF_APP1_INFO structure
 * @param whichIFD      the specified IFD
 * @param list          pointer to a unsigned short to obtain the tag list
 * @param count         pointer to a unsigned int to obtain the number of the tags in the list
 * @return              If the function succeeds, return 1; otherwise return 0.
 * @remarks
 */
kal_int32 app1ParserGetIFDTagList(EXIF_APP1_INFO *app1Info, JPEG_APP1_IFD_TYPE_ENUM whichIFD, kal_uint16 *list, kal_uint32 *count);



/**
 * @brief               Query the information of the specified tag in the specified IFD.
 * @param app1Info      pointer to a EXIF_APP1_INFO structure
 * @param whichIFD      the specified IFD
 * @param tagID         the specified tag
 * @param count         pointer to a unsigned int to obtain the number of values in the specified tag
 * @param valueOffset   pointer to a unsigned int to obtain the value offset of the specified tag
 * @return              If the function succeeds, return the total size required to store the IFD information; otherwise return 0.
 * @remarks
 */
kal_int32 app1ParserQueryIFDTag(EXIF_APP1_INFO *app1Info, JPEG_APP1_IFD_TYPE_ENUM whichIFD, kal_uint32 tagID, kal_uint32 *type, kal_uint32 *count, kal_uint32 *valueOffset);



/**
 * @brief            Extract the data of the specified tag in the specified IFD.
 * @param whichIFD   the specified IFD
 * @param tagID      the specified tag
 * @param bufferPtr  pointer to a 4-byte-aligned byffer to obtain the data of the tag
 * @param bufferSize the size of the given buffer
 * @return           If the function succeeds, return the total size of the data extracted; otherwise return 0.
 * @remarks
 */
kal_int32 app1ParserExtractIFDTagData(EXIF_APP1_INFO *app1Info, JPEG_APP1_IFD_TYPE_ENUM whichIFD, kal_uint32 tagID, kal_uint32 *bufferPtr, kal_uint32 bufferSize);



/**
 * @brief               Query the information of the EXIF thumbnail (1st IFD)
 * @param app1Info      pointer to a EXIF_APP1_INFO structure
 * @param width         pointer to a unsigned int to obtain the width of the thumbnail
 * @param height        pointer to a unsigned int to obtain the height of the thumbnail
 * @param compression   pointer to a unsigned int to obtain the compression type of the thumbnail
 * @param offsetInFile  pointer to a unsigned int to obtain the offset of the thumbnail in the source image file
 * @return              If the function succeeds, return the size of the thumbnail data; otherwise return 0.
 * @remarks
 */
kal_int32 app1ParserQueryThumbnailInfo(EXIF_APP1_INFO *app1Info, kal_uint32 *width, kal_uint32 *height, kal_uint32 *compression, kal_uint32 *offsetInFile);



/// The following functions are not implemented...

/*
kal_int32 app1AddIFD(IFD_TYPE_ENUM ifd);
kal_int32 app1DeleteIFD(IFD_TYPE_ENUM ifd);
kal_int32 app1Ifd0AddField(TIFF_FIELD field, kal_int32 count);
kal_int32 app1Ifd0DeleteField(TIFF_FIELD field, kal_int32 count);
kal_int32 app1Ifd1AddField(TIFF_FIELD field, kal_int32 count);
kal_int32 app1Ifd1DeleteField(TIFF_FIELD field, kal_int32 count);
kal_int32 app1ExifIfd1AddField(EXIF_FIELD field, kal_int32 count);
kal_int32 app1ExifIfdDeleteField(EXIF_FIELD field, kal_int32 count);
kal_int32 app1GpsIfd1AddField(GPS_FIELD field, kal_int32 count);
kal_int32 app1GpsIfdDeleteField(GPS_FIELD field, kal_int32 count);
kal_int32 app1GpsIfdQueryFieldSize(GPS_FIELD field, kal_uint32 *sizeInBytes);
kal_int32 app1GpsIfdQueryFieldValue(GPS_FIELD field, void *value);
*/

#endif  // __EXIF_DEC_PARSER_V2_H__

