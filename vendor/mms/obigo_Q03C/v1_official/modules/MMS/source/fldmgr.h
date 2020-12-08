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
 * fldmgr.h
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
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _FLDMGR_H
#define _FLDMGR_H

//#define MMS_SUPPORT_RESTORE_PDU

typedef enum
{
    STATE_FOLDER_STOPPED = 0,   
        STATE_FOLDER_IDLE,          
        STATE_FOLDER_READING,
        STATE_FOLDER_READING_LIST,
        STATE_FOLDER_READING_LIST_RSP,
        STATE_FOLDER_WRITING,      
#ifdef MMS_SUPPORT_RESTORE_PDU        
        STATE_FOLDER_RESTORING,     
#endif
        STATE_FOLDER_TERMINATING    
} MmsFmState;

#define MMS_FILE        "mms"             
#define MMS_MMTTMP      "mms.tp"          
#define MMS_MMTBACK     "mms.bk"             
#define MMS_MMT         "mms.cn"          
#define MMS_INFO_SUFFIX "i"               
#define MMS_MESSAGE_SUFFIX "m"
#define MMS_FOLDER      "/mmt/"          
#define MMS_PDU_FOLDER      "/mms_pdu/" 
#define MMS_INFO_FOLDER     "/mms_info/" 
#define MMS_SYS_FOLDER      "/mms_sys/"          
#define MMS_MMT_BACKUP_FILE MMS_FOLDER MMS_MMTBACK  
#define MMS_MMT_TMP_FILE MMS_FOLDER MMS_MMTTMP 
#define MMS_MMT_FILE    MMS_FOLDER MMS_MMT  
#define MMS_FILE_LEN    15                
#define MMS_PATH_LEN    (sizeof(MMS_PDU_FOLDER) + MMS_FILE_LEN)



typedef struct
{
    MSF_UINT32      size;
    MmsFileType     suffix;     
    MSF_UINT8   storageType;   /* signify the Phone or Memory card */  
    MSF_BOOL    alwaysCreate;
} MmsFmgCreateParam;



typedef struct
{
    MmsMsgId   msgId;
	MmsFileType suffix;
    MSF_UINT8   storageType;   /* signify the Phone or Memory card */
} MmsFmgDeleteParam;

typedef struct
{     
    MSF_UINT8   storageType;   /* signify the Phone or Memory card */      
} MmsFmgStorageParam;

typedef enum
{
    M_FSM_MMT_OPERATION_FINISHED,
    MMS_SIG_FMG_TERMINATE,
    MMS_SIG_FMG_CREATE_MSG,
    MMS_SIG_FMG_MOVE_MSG,
#ifdef __NON_BLOCKING_FILE_MOVE_SUPPORT__
    MMS_SIG_FMG_FILE_MOVE_RESPONSE,
#endif
    MMS_SIG_FMG_DELETE_MSG,
    MMS_SIG_FMG_GET_LIST,
    MMS_SIG_FMG_INT_WRITE_MMT,
    MMS_SIG_FMG_INT_CREATE_MSG,
    MMS_SIG_FMG_INT_DELETE_MSG,
#ifdef MMS_SUPPORT_RESTORE_PDU
    MMS_SIG_FMG_INT_MMT_RESTORE, 
    MMS_SIG_FMG_INT_MMT_RESTORE_EXT, 
    MMS_SIG_FMG_INT_START_ASYNC_RESTORE, 
    MMS_SIG_FMG_INT_INF_DONE,
    MMS_SIG_FMG_INT_NOTIF_DONE,
    MMS_SIG_FMG_INT_RR_PDU_RESTORE,
    MMS_SIG_FMG_INT_DR_RESTORE,
#endif /* MMS_SUPPORT_RESTORE_PDU */
    MMS_SIG_FMG_TOTAL
} MmsFldrMgrSignalId;










void fldrEmergencyAbort(void);
void fldrInit( MmsStateMachine fsm, MSF_UINT32 signal, long instance);
MmsFmState fldrGetWorkingState(MSF_UINT8 storageType);
char *fldrMsgId2Name(MSF_UINT32 msgId, MmsFileType suffix);

void fldrTerminate( MmsStateMachine fsm, MSF_UINT32 signal, long instance);
/* Right now, no one is using this API */

MmsFileType fldrGetFileSuffix(MmsMsgId msgId);

MmsFolderType fldrGetFolderId(MmsMsgId msgId);

unsigned char *fldrGetServerMsgId(MmsMsgId msgId);

MSF_UINT32 fldrMgrSearchMsgId(MSF_UINT32 startMsgId, const char *srvMsgId, MmsFileType suffix);


MSF_UINT32 mmsCountNotifInQueue(void);

MmsFileType getMsgType (MSF_UINT32 msgId);

void fldrGetFolderStatus(MSF_UINT32 *usedMsgBytes, MSF_UINT32 *numOfMsg, 
      MSF_UINT32 *totalFolderSize, MSF_UINT32 folderMask);

MSF_UINT32 fldrGetNoOfFreeMsg(void);

int createFolder( MSF_UINT8 storageType);

void fldrGetInboxStatus(MSF_UINT32 *numOfMsg,   MSF_UINT32 *numOfUnreadMsg,
                        MSF_UINT32 *numOfNotif, MSF_UINT32 *numOfUnreadNotif,
                        MSF_UINT32 *numOfRR,    MSF_UINT32 *numOfUnreadRR,
                        MSF_UINT32 *numOfDR,    MSF_UINT32 *numOfUnreadDR);




void fldrMgrGetNumberOfMessages(MSF_UINT8 storageType, MSF_UINT16 *nMsgs);
void fldrMgrFormatDriveReq(MSF_UINT8 storageType);

MmsResult fldrMgrDeleteMessage(MSF_UINT32 msgId, MmsFileType suffix, MSF_UINT8 storageType);

MmsResult mmsChangeMsgType(MSF_UINT32 msgId, MmsFileType newSuffix);
MmsResult mmsFldrMgrSetFolderQuiet(MSF_UINT32 msgId, MSF_UINT32 folder);

void mmsShowAllImmediateNotif(void);
MmsResult mmsFldrMgrSetSuffix(MSF_UINT32 msgId, MmsFileType newSuffix);
#endif 

