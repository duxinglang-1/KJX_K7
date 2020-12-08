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
 * mutils.h
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

#ifndef _MUTILS_H
#define _MUTILS_H
















MSF_BOOL copyMmsEncText( MSF_UINT8 modId, MmsEncodedText *to, 
    const MmsEncodedText *from);
MSF_BOOL  copyMmsAddress( MSF_UINT8 modId, MmsAddress *to, const MmsAddress *from);
MSF_BOOL  copyMmsAddressList( MSF_UINT8 modId, MmsAddressList **toList, const MmsAddressList *fromList);
MSF_BOOL  copyContentType( MSF_UINT8 modId, MmsContentType *toContent, const MmsContentType *fromContent);
MSF_BOOL  copyMmsEntryHeader( MSF_UINT8 modId, MmsEntryHeader **to, const MmsEntryHeader *from);
MmsForward *copyMmsForward( MSF_UINT8 modId, const MmsForward *mmsForward);



void freeMmsAddress( MSF_UINT8 modId, MmsAddress *address);
void freeMmsAddressList( MSF_UINT8 modId, MmsAddressList *addressList);
void freeMmsBodyInfoList( MSF_UINT8 modId, MmsBodyInfoList *bodyInfoList);
void freeMmsBodyInfoNode( MSF_UINT8 modId, MmsBodyInfoList *bodyInfoList);
void freeMmsEncodedText( MSF_UINT8 modId, MmsEncodedText *encodedText);
void freeMmsMessageClass( MSF_UINT8 modId, MmsMessageClass *messageClass);
void freeMmsContentType( MSF_UINT8 modId, MmsContentType *contentType);
void freeMmsContentTypeParams( MSF_UINT8 modId, MmsAllParams *params);
void freeMmsSetHeader( MSF_UINT8 modId, MmsSetHeader *mHeader);
void freeMmsGetHeader( MSF_UINT8 modId, MmsGetHeader *mHeader);
void freeMmsNotification( MSF_UINT8 modId, MmsNotification *mmsNotification);
void freeMmsEntryHeader( MSF_UINT8 modId, MmsEntryHeader *entryHeader);
void freeMmsMessageInfo( MSF_UINT8 modId, MmsMessageInfo *messageInfo);
void freeMmsReadOrigInd( MSF_UINT8 modId, MmsReadOrigInd *mmsOrigInd);
void freeMmsPrevSentBy( MSF_UINT8 modId, MmsPrevSentBy *mmsPrevSentBy);
void freeMmsPrevSentDate( MSF_UINT8 modId, MmsPrevSentDate *mmsPrevSentDate);
void freeMmsBodyParams( MSF_UINT8 modId, MmsBodyParams *bodyParams);
void freeMmsDeliveryInd( MSF_UINT8 modId, MmsDeliveryInd *deliveryInd);

unsigned char *mmsCvtBuf( MSF_UINT8 modId, int *charset, const unsigned char *srcData, 
    int *srcSize, int *dstSize);
unsigned long mmsStrnlen(const char *str, unsigned long length);
char *mmsStrtok(char *string, const char *control);
void updateSubjectText(MSF_UINT8 modId, MmsEncodedText *subject);

MSF_BOOL  mmsValidateAddressList(  const MmsAddressList *addrList);
MSF_BOOL  mmsValidateSubject(  const MmsEncodedText *subject);
MSF_BOOL  mmsValidateMessageClass(  const MmsMessageClass *msgClass);
MSF_BOOL  mmsValidateAddress(  const MmsAddress *fromAddress);
MSF_BOOL  mmsValidateEntryHeaders(  MSF_UINT8 modId, MmsEntryHeader *entryHeader, MmsResult *result);
MSF_BOOL  mmsValidateCharSet( int charSet);


MSF_BOOL  mmsIsMultiPart( MmsKnownMediaType value);
MSF_BOOL  mmsIsText( MmsKnownMediaType value);


MSF_UINT32 mmsGetGMTtime(MSF_BOOL ensureGMT);

#endif 

