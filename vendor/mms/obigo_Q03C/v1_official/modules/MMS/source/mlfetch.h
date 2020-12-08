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
 * Copyright (C) Obigo AB, 2002-2005.
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







/*******************************************************************************
 *
 * Filename:
 * ---------
 * mlfetch.h
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

#ifndef _MFETCH_H
#define _MFETCH_H




#define MMS_MESSAGE_INFO_SIZE  (POS_INT_MSG_NUMBER * sizeof(MSF_UINT32))
#define MMS_PART_INFO_SIZE (POS_INT_PART_NUMBER * sizeof(MSF_UINT32))










MSF_UINT32 getNumberOfParts( const MmsMessage *msg);
MSF_UINT32 getNumberOfSubParts( MSF_UINT32 number, const MmsMessage *msg);
MSF_UINT32 getMaxPartSize( const MmsMessage *msg);
MSF_UINT32 getMaxEntrySize( const MmsMessage *msg);
MSF_UINT32 getHeaderSize( const MmsMessage *msg);

MSF_UINT32 getEntrySize( MSF_UINT32 number, const MmsMessage *msg);
MSF_UINT32 getEntryStart( MSF_UINT32 number, const MmsMessage *msg);
MSF_UINT32 getDataSize( MSF_UINT32 number, const MmsMessage *msg); 
MSF_UINT32 getDataStart( MSF_UINT32 number, const MmsMessage *msg); 
void setHeaderSize( unsigned char *buffer, MSF_UINT32 value);
void setNumberOfParts( unsigned char *buffer, MSF_UINT32 value);
void setNumberOfSubParts( unsigned char *buffer, MSF_UINT32 number, 
    MSF_UINT32 value);
void setHeaderStart( unsigned char *buffer);
void setEntrySize( unsigned char *buffer, MSF_UINT32 number, MSF_UINT32 value);
void setEntryStart( unsigned char *buffer, MSF_UINT32 number, MSF_UINT32 value);
void setDataSize( unsigned char *buffer, MSF_UINT32 number, MSF_UINT32 value);
void setDataStart( unsigned char *buffer, MSF_UINT32 number, MSF_UINT32 value);
MmsResult readDataFromFile( MSF_UINT8 modId, unsigned char **buf, 
    MSF_UINT32 *size, int fileHandle, MSF_INT32 *filePos);

MmsResult getMessageInfoExt( MSF_UINT8 modId, MmsGetHeader *header,
    const MmsMessage *msg, MmsTransaction *tHandle);


MmsMessageInfo *parseMsgInfo( MSF_UINT8 modId, unsigned char *buffer, 
    MSF_UINT32 bufferSize, MSF_UINT32 *msgPtr);
MmsResult loadMessageInfoFile( MSF_UINT8 modId, MmsMessage *msg, 
    MmsTransaction *tHandle);
MmsResult getMmsHeader( MSF_UINT8 modId, MmsGetHeader *header, 
    const MmsMessage *msg, MmsTransaction *tHandle);
MmsResult parseBodyHeader( MSF_UINT8 modId, MSF_BOOL prevIsMultipart, 
    MmsBodyInfoList *msgInfo, unsigned char *data, MSF_UINT32 size);
unsigned char *findContentType( unsigned char *entry, MSF_UINT32 entrySize, 
    MSF_BOOL isMultiPart, MSF_UINT32 *headerLen);

#endif 

