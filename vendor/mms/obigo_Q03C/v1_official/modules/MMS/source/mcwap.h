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
 * mcwap.h
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

#ifndef _MCWAP_H
#define _MCWAP_H






typedef enum
{
    MMS_COMM_GET,   
    MMS_COMM_POST   
} MmsCommMethod;



typedef struct
{
    
    
    MSF_INT32 dataLen;      
    
    
    union
    {
        char *fileName;
        char *pipeName;
        char *buffer;
    } data;

    MSF_INT16 dataType;
    
    MmsRequestId id;    
    
    
    MmsResult errorNo;
    
    

} MmsHttpContent;


typedef enum
{
    





    MMS_SIG_COH_WAP_START,

    





    MMS_SIG_COH_WAP_START_RESPONSE,

    





    MMS_SIG_COH_WAP_STOP,

    





    MMS_SIG_COH_WAP_STOP_RESPONSE

    







    

    







    
} MmsCohWapSignalId;




void mmsWapChannelDisconnect(MmsSimCardEnum simId);
void mmsWapRemoveStartReqFromWaitingQueue(MSF_INT32 fsm, long instance);
MSF_INT32 mmsWapIsUsingBearer(void);

void mmsWapHttpPostPipe(MmsSimCardEnum simId, MmsRequestId requestId, const char *uri, char *pipeName, 
    MSF_INT32 dataLen);
void mmsWapHttpPostPdu(MmsSimCardEnum simId, MmsRequestId requestId, const char *uri, void *pdu, 
    MSF_INT32 size);
void mmsWapHttpGet(MmsSimCardEnum simId, MmsRequestId requestId, const char *uri);
void mmsWapChannelIsDisconnected(void);
void mmsWapConnectionCheck(void);
void mmsWapEmergencyAbort(void);
MmsRequestId mmsWapGetRequestId(void);
long mmsWapGetTransactionId(void);
void mmsWapFreeContentParams(MmsHttpContent *cont);
void mmsWapHttpCancel(MmsRequestId requestId);
void mmsWapHttpResponse(MmsRequestId id, MSF_INT16 status, MSF_INT16 dataType, 
    MSF_INT32 dataLen, void *data);
void mmsWapInit(void);
void mmsWapTerminate(void);
MmsResult mmsWapTranslateError(MSF_INT32 error);
MmsResult mmsWapTranslateResponseStatus(MmsResponseStatus status);
MmsResult mmsWapTranslateRetrieveStatus(MmsRetrieveStatus status);

#endif 


