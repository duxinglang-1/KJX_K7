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

/*! \file mmsl_if.h
 * \brief  Exported libary functions from MMS Service for creation of 
 *         MMS messages.
 *
 * Exported libray functions, i.e. used by Target Device Application (TDA) to 
 * create MMS message. 
 * For every function, the following data are listed:
 * - A brief one line description of the function
 *
 * - A longer description of the function
 *
 * - The parameters for the function 
 *           In:  is input parameters 
 *           Out: is return parameters
 */



/*******************************************************************************
 *
 * Filename:
 * ---------
 * mmsl_if.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MMSL_IF_H
#define _MMSL_IF_H

/*--- Definitions/Declarations ---*/

/*--- Types ---*/

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Prototypes ---*/



/*!
 * \brief Get a specific part from a message body
 *
 * A specific bodypart is requested by the TDA.
 * 
 * Type: Function call 
 *
 * \param modId In: MSF module identification 
 * \param number In: The number of the requested body part
 * \param data In: Buffer to add data too.
 * \param size In/Out: In: Size of data buffer. Out: bytes in buffer when done.
 * \param msg In: Information about the file and message.
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
 *****************************************************************************/
MmsResult MMSlib_getBodyPart(MSF_UINT8 modId, MSF_UINT32 number, 
    unsigned char *data, MSF_UINT32 *size, 
    MmsMsgHandle *msg, MmsTransactionHandle *transaction);

/*!
 * \brief Get information about a message
 *
 * Type: Function call 
 *
 * \param modId In: MSF module identification 
 * \param header Out: The message header.
 * \param msg In: Information about the file and message.
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
*/

MmsResult MMSlib_getMessageHeaderExt(MSF_UINT8 modId, MmsGetHeader *mheader, 
    MmsMsgHandle *msg, MmsTransactionHandle *transaction, MmsHeaderType parseHeaders);


/*!
 * \brief Get a notification message
 *
 * Type: Function call 
 *
 * \param modId In: MSF module identification 
 * \param MmsNotification Out: The notification message.
 * \param msg In: Information about the file and message.
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
 *****************************************************************************/
MmsResult MMSlib_getNotification( MSF_UINT8 modId, MmsNotification *msgNotif,
    MmsMsgHandle *msg, MmsTransactionHandle *transaction);

/*!
 * \brief Appends a new part to the message body
 *
 * A new body part or attachment is appended to the message 
 *
 * Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param params In: Body parameters, e.g. contenttype. The caller is 
 *        responsible for freeing this memory when complete.
 * \param data In: Buffer holding the body data. The caller is responsible 
 *        for freeing this memory when complete.
 * \param size In: Size of data buffer.
 * \param msg In: Information about the file and message.
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
 *****************************************************************************/
MmsResult MMSlib_setMessageBody(MSF_UINT8 modId, MmsBodyParams *params,
    unsigned char *data, MSF_UINT32 size, MmsMsgHandle *msg, 
    MmsTransactionHandle *transaction);

/*!
 * \brief The header information of amessage with identidy msgId is set.
 *
 * The header is inserted in the message with the specified message ID
 * Note: This function makes use of asynchron file operations. Upon a reply 
 *       indicating a "wait and try later" must this function be called again. 
 *
 * Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param numOfBodyParts In: The number of body parts that belongs to this message.
 * \param header In: The header information for the message.
 * \param version In: The version of the MMS Server.
 * \param msg In: Information about the file and message.
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
 *****************************************************************************/
MmsResult MMSlib_setMessageHeader(MSF_UINT8 modId, MSF_UINT32 numOfBodyParts, 
    MmsSetHeader *header, MmsVersion version, MmsMsgHandle *msg, 
    MmsTransactionHandle *transaction);

/*!
 * \brief Opens a message.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param msgId In: The message id of the file to be opened.
 * \param msgType In: The type of the message. Valid types 
 *                     MMS_SUFFIX_TEMPLATE
 *                     MMS_SUFFIX_NOTIFICATION
 *                     MMS_SUFFIX_IMMEDIATE
 *                     MMS_SUFFIX_SEND_REQ
 *                     MMS_SUFFIX_MSG
 * \param msgHandle Out: The messageHandle to the file opened.
 * \return Result of the operation.
*****************************************************************************/
MmsResult MMSlib_messageOpen( MSF_UINT8 modId, MmsMsgId msgId, 
    MmsFileType msgType, MmsMsgHandle *msg, MSF_UINT8 storageType);

/*!
 * \brief Closes a message.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param msgHandle Out: The messageHandle to the file to close.
 * \return Result of the operation.
*****************************************************************************/
MmsResult MMSlib_messageClose( MSF_UINT8 modId, MmsMsgHandle *msg);

/*!
 * \brief Opens a transaction.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
*****************************************************************************/
MmsResult MMSlib_transactionOpen( MSF_UINT8 modId,
    MmsTransactionHandle *transaction);

/*!
 * \brief Closes a transaction.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param transaction Needed for internal use. Contains no user data. 
 * \return Result of the operation.
*****************************************************************************/
MmsResult MMSlib_transactionClose( MSF_UINT8 modId,
    MmsTransactionHandle *transaction);

/*!
 * \brief Frees a MmsGetHeader data structure.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param mHeader Out: The data to free 
*****************************************************************************/
void MMSlib_freeMmsGetHeader( MSF_UINT8 modId, MmsGetHeader *mHeader);

/*!
 * \brief Frees a MmsSetHeader data structure.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param mHeader In: The data to free 
*****************************************************************************/
void MMSlib_freeMmsSetHeader( MSF_UINT8 modId, MmsSetHeader *mHeader);

/*!
 * \brief Frees a MmsNotification data structure.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param mNotification In: The data to free 
*****************************************************************************/
void MMSlib_freeMmsNotification( MSF_UINT8 modId, MmsNotification *mNotification);

/*!
 * \brief Builds a full path from a message id.
 *
 *  Type: Function call
 *
 * \param modId In: MSF module identification 
 * \param msgId In: The mesesage id.
 * \param fileType In: The file suffix char
 * \return the full path or NULL 
*****************************************************************************/
char *MMSlib_getMessageFullPath( MSF_UINT8 modId, MmsMsgId msgId, 
                                MmsFileType fileType);

/*!
 * \brief Get total no. of message in respective storage.
 *
 *  Type: Function call
 *
 * \param storageType In:   
 * \param nMsgs In: Total no. of messages.
*****************************************************************************/
void MMSlib_fldrMgrGetNumberOfMessages(MSF_UINT8 storageType, MSF_UINT16 *nMsgs);
void MMSlib_fldrMgrFormatDriveReq(MSF_UINT8 storageType);
int MMSlib_createFolder(MSF_UINT8 storageType);

#define MMS_SYS_FOLDER "/mms_sys/"

#define MMS_SUFFIX_CHKSUM 'c'
#define MMS_MIN_CHECKSUM_FILE_SIZE 12 /* file_chksum + info_chksum + msg_chksum */
#define MMS_MIN_CHECKSUM_NODE_SIZE (sizeof(mmsCacheInfo)) /* mmsCacheInfo struct size*/
//#define MMS_MAX_CHECKSUM_NODE (MMS_MAX_NO_OF_MSG - 1) /* MAximun number of nodes in CHKSUM file*/
MmsResult MMSlib_translateMsfFileErrorToMmsError(int fileError);
MmsResult translateFileErrorToMmsError(int err);

MmsResult MMSlib_genChkSumFile(MmsMsgId msgId, MmsFileType suffix, MSF_UINT8 storage_type,
                               mms_msg_info_property_struct *Prop, mms_msg_info_large_data_struct *Large_data);
MmsResult MMSlib_delChkSumFile(MmsMsgId msgId, MSF_UINT8 storage_type);
void MMSlib_isValidMmsMSgExt(MmsMsgId msgId, MmsFileType suffix, MSF_UINT8 storage_type, MSF_BOOL *isPduValid, MSF_BOOL *isInfoValid);
MmsResult MMSlib_MoveChkSumFile(MmsMsgId oriMsgId, MmsMsgId destMsgId, MmsFileType suffix, MSF_UINT8 oriStorageType, MSF_UINT8 destStorageType);

MmsResult MMSlib_ReadFromChkSumFile_Ext(MmsMsgId msgId, MSF_UINT8 storage_type,
                               mms_msg_info_property_struct *Prop,
                               mms_msg_info_large_data_struct *Large_data);
MmsResult MMSlib_UpdateChkSumFile_Ext(MmsMsgId msgId, MmsFileType suffix, MSF_UINT8 storage_type,
                               mms_msg_info_property_struct *Prop, mms_msg_info_large_data_struct *Large_data);
MSF_BOOL  MMSlib_isValidMmsMSg_Ext1(MmsMsgId msgId, MmsFileType suffix, MSF_UINT8 storage_type);

MmsResult Mmslib_mmsFldrMgrSetSuffix(MSF_UINT32 msgId, MmsFileType newSuffix);

MmsResult MMSlib_genAddrObjFile(MSF_UINT32 msg_id, MSF_UINT8 storage_type, mmsAddrObjectInfo *data);

MmsResult MMSlib_UpdateAddrObjFile(MSF_UINT32 msg_id, MSF_UINT8 storage_type, mms_msg_addr_info_struct *addr);

typedef void *(*mms_mem_alloc_fn) (MSF_UINT32);
typedef void (*mms_mem_free_fn) (void *);
MmsResult MMSlib_readAddrObjFile(MmsMsgId msgId, MSF_UINT8 storage_type,
                                 MSF_UINT8 *total_address, MSF_UINT8 *total_object,
                                 mms_msg_addr_info_struct *addr_data,
                                 mms_msg_object_info_struct *object_data,
								 mms_mem_alloc_fn mem_alloc_fn,  mms_mem_free_fn mem_free_fn);
MmsResult MMSlib_delAddrObjFile(MmsMsgId msgId, MSF_UINT8 storage_type);

MmsResult MMSlib_genBodyObjFile(MSF_UINT32 msg_id, MSF_UINT8 storage_type, mmsBodyObjectInfo *data);
MmsResult MMSlib_readBodyObjFile(MmsMsgId msgId, MSF_UINT8 storage_type,
                                 MSF_UINT8 *total_object, mmsBodyObjectInfo *object_data,
                                 mms_mem_alloc_fn mem_alloc_fn,  mms_mem_free_fn mem_free_fn);
MmsResult MMSlib_delBodyObjFile(MmsMsgId msgId, MSF_UINT8 storage_type);

MSF_UINT32 MMSlib_genReportMsgId(MSF_INT32 msg_index);
MSF_UINT32 MMSlib_getReportMsgIndex(MSF_INT32 msg_id);
MSF_BOOL MMSlib_isReportMsgId(MSF_UINT32 msg_id);

MmsResult MMSlib_genReportInfoFile(MSF_UINT8 storage_type, mms_msg_report_info *data);
MmsResult MMSlib_readReportInfoFile(MSF_UINT8 storage_type, mms_msg_report_info *report_data);
MmsResult MMSlib_readReportInfoFileNode(MSF_UINT8 storage_type, MSF_UINT32 node, mms_msg_report_info_struct *addr_data);
MmsResult MMSlib_UpdateReportInfoFile(MSF_UINT8 storage_type, mms_msg_report_info_struct *data);
MmsResult MMSlib_AddEntryInReportInfoFile(MSF_UINT8 storage_type, MSF_UINT8 count, mms_msg_report_info *data);
MmsResult MMSlib_updateReportMmsCount(MSF_UINT32 count);
MmsResult MMSlib_getReportMmsCount(MSF_UINT32 *count);
MmsResult MMSlib_deleteReportMmsCount(void);
MmsResult MMSlib_deleteReportInfoFile(void);
MmsResult MMSlib_deleteEntryFromReportInfoFile(MSF_UINT32 count, MSF_UINT32 *list_of_msg);

typedef struct
{
	MSF_UINT32 prop_chksum;
    MSF_UINT32 info_chksum; 		
	MSF_UINT32 msg_date;	
	mms_msg_info_property_struct prop_data;
	mms_msg_info_large_data_struct large_data;
}mmsCacheInfo;


MSF_BOOL MMSlib_mmsAddServerMsgIdToDB(char *serMsgId, MmsMsgId msgId, MSF_UINT8 StorageType, MSF_UINT8 SimId);
extern char *MMSlib_mmsGetSerMsgId(MmsMsgId msgId, MSF_UINT8 StorageType);
extern char *MMSlib_mmsGetSubjectFromDB(const char *srvMsgId);
extern MmsMsgId MMSlib_mmsGetMsgId(const char *srvMsgId, MSF_UINT8 *storage);
extern void MMSlib_mmsRemoveMsgIdFromDB(MmsMsgId msgId, MSF_UINT8 StorageType);
extern void MMSlib_mmsfreeServerMsgIdDB(void);

extern void MMSlib_freeMmsBodyInfoList( MSF_UINT8 modId, MmsGetHeader *mHeader);
extern void MMSlib_freeMmsBodyInfoNode( MSF_UINT8 modId, MmsGetHeader *mHeader);
#endif  /* _MMSL_IF_H */


