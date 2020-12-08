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

/*! \file mms_if.h
 * \brief  Exported signal functions towards the MMS Service.
 *
 * Exported connector functions, i.e. from Target Device Application to the MMS 
 * client. For every connector function, the following data are listed:
 * - A brief one line description of the function
 * - A longer description of the function
 * - The type of the function. It can be either:
 *     -# Signal function: The function encapsulates the passed parameters into
 *        a MSF signal and sent it to the MMS Service 
 *        The result will be returned in a reply signal.
 *
 *     -# Converter function: unpack the recived signals into the data types
 *        used by the MFS. This function is to be registrated in MSF
 *      
 * - Reply signal name
 * - The parameters for the function
 */



/*******************************************************************************
 *
 * Filename:
 * ---------
 * mms_if.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _MMS_IF_H
#define _MMS_IF_H

#ifndef _MMS_CFG_H  /* Check so the mms_cfg.h file is included before this file */
#error You must #include mms_cfg.h before this file.
#error The file mms_cfg.h contains configuration data for all other MMS files.
#error Please change the .c file that stopped from compiling because you came here
#error so that it includes mms_cfg.h before this file.
#endif /* _MMS_CFG_H */

/*--- Definitions/Declarations ---*/

/*--- Types ---*/


/*--- Constants ---*/

/* Signals */

/* 
 *!\brief Signal Identifications 
 *                        Format:  16 bit = ! 8bit   ! 8bit  ! 
 *                                          !  SigId ! Modid !
 */

/*--- Replied signals from MMS Service ---*/
#define MMS_SIG_CREATE_MSG_REPLY     ((MSF_MODID_MMS << 8) + 0x01) 
#define MMS_SIG_DELETE_MSG_REPLY     ((MSF_MODID_MMS << 8) + 0x02)
#define MMS_SIG_FORWARD_REQ_REPLY    ((MSF_MODID_MMS << 8) + 0x03)
#define MMS_SIG_GET_NUM_OF_MSG_REPLY ((MSF_MODID_MMS << 8) + 0x04)
#define MMS_SIG_MOV_MSG_REPLY        ((MSF_MODID_MMS << 8) + 0x05)
#define MMS_SIG_RETRIEVE_MSG_REPLY   ((MSF_MODID_MMS << 8) + 0x06)
#define MMS_SIG_SEND_MSG_REPLY       ((MSF_MODID_MMS << 8) + 0x07)
#define MMS_SIG_READ_REPORT_IND      ((MSF_MODID_MMS << 8) + 0x08)
#define MMS_SIG_DELIVERY_REPORT      ((MSF_MODID_MMS << 8) + 0x09)
#define MMS_SIG_ERROR                ((MSF_MODID_MMS << 8) + 0x0A)
#define MMS_SIG_NOTIFICATION         ((MSF_MODID_MMS << 8) + 0x0B)
#define MMS_SIG_SEND_RR_REPLY        ((MSF_MODID_MMS << 8) + 0x0C)
#define MMS_SIG_MSG_DONE_REPLY       ((MSF_MODID_MMS << 8) + 0x0D)
#define MMS_SIG_GET_FLDR_REPLY       ((MSF_MODID_MMS << 8) + 0x0E)
#define MMS_SIG_FOLDER_STATUS_REPLY  ((MSF_MODID_MMS << 8) + 0x0F)
#define MMS_SIG_PROGRESS_STATUS_REPLY ((MSF_MODID_MMS << 8) + 0x10)
//#define MMS_SIG_GET_MSG_INFO_REPLY   ((MSF_MODID_MMS << 8) + 0x11)
#define MMS_SIG_PUSH_NOTIFICATION_REPLY ((MSF_MODID_MMS << 8) + 0x12)

/*--- Signals sent to MMS Service ---*/             
#define MMS_SIG_CREATE_MSG           ((MSF_MODID_MMS << 8) + 0x30) 
#define MMS_SIG_DELETE_MSG           ((MSF_MODID_MMS << 8) + 0x31) 
#define MMS_SIG_FORWARD_REQ          ((MSF_MODID_MMS << 8) + 0x32) 
//#define MMS_SIG_GET_NUM_OF_MSG       ((MSF_MODID_MMS << 8) + 0x33) 
#define MMS_SIG_MOVE_MSG             ((MSF_MODID_MMS << 8) + 0x34) 
#define MMS_SIG_RETRIEVE_MSG         ((MSF_MODID_MMS << 8) + 0x35) 
#define MMS_SIG_RETRIEVE_MSG_CANCEL  ((MSF_MODID_MMS << 8) + 0x36) 
#define MMS_SIG_SEND_MSG             ((MSF_MODID_MMS << 8) + 0x37) 
#define MMS_SIG_SEND_MSG_CANCEL      ((MSF_MODID_MMS << 8) + 0x38) 
#define MMS_SIG_READ_REPORT          ((MSF_MODID_MMS << 8) + 0x39) 
#define MMS_SIG_CONFIG_STR           ((MSF_MODID_MMS << 8) + 0x3A) 
#define MMS_SIG_MSG_DONE             ((MSF_MODID_MMS << 8) + 0x3B) 
#define MMS_SIG_GET_FLDR             ((MSF_MODID_MMS << 8) + 0x3C) 
#define MMS_SIG_FOLDER_STATUS        ((MSF_MODID_MMS << 8) + 0x3F) 
//#define MMS_SIG_APP_REG              ((MSF_MODID_MMS << 8) + 0x40) 
//#define MMS_SIG_GET_MSG_INFO         ((MSF_MODID_MMS << 8) + 0x41) 
//#define MMS_SIG_SIM_INFO_NOTIFY_IND  ((MSF_MODID_MMS << 8) + 0x42) 
#define MMS_SIG_PUSH_NOTIFICATION    ((MSF_MODID_MMS << 8) + 0x43) 


/*--- Signal parameters ---*/


/* 
 *! \brief Signal struct for sending message file type
 */ 
typedef struct
{
    MmsFileType fileType; /*!< The file type */
    kal_uint8 storageType;   /*Loaction where message is to be created*/
    MSF_BOOL alwaysCreate;     /* To create this MMS irrespect of MAX MMS state reached */
} MmsFileTypeSig; 


/* 
 *! \brief Signal struct for sending application registration 
 */ 
typedef struct
{
    MSF_UINT8 source; /*!< The caller MSF module id */
} MmsAppReg; 
 
/*
 *! \brief Signal Struct sending message id
 */
typedef struct 
{
   MmsMsgId  msgId; /*!< Message identification */
} MmsMsgSig;

typedef struct 
{
   MmsMsgId  msgId; /*!< Message identification */
   MmsSimCardEnum simId;
   MSF_UINT16 storageData; 
} MmsSendRecvSig;

typedef struct 
{
   MSF_UINT8      source;   /*!< Requesting module */
   MmsFolderType  folderId; /*!< Folder identification */
} MmsFolderSig;

/*
 * ! \brief Signal Struct sending message move/create done 
 */
typedef struct 
{
    MmsMsgId msgId; /*!< Message identification */
    MmsFileType suffix;
    MSF_UINT8 storageType;
} MmsMsgStorageSig;

typedef struct 
{
    MmsMsgId msgId; /*!< Message identification */
    MSF_UINT8 suffix;
    MSF_UINT8 OriStorageType;
    MSF_UINT8 destStorageType;
    MSF_UINT8 isMoveMsg;
} MmsMsgMoveStorageSig;
/*
 * ! \brief Signal Struct sending read report
 */
typedef struct 
{
    MmsMsgId msgId; /*!< Message identification */
    MmsSimCardEnum simId; 
    MSF_UINT16 storageData;
    MmsReadStatus readStatus; /*! Read status */
} MmsSendReadReport; 

/* 
 * ! \brief Signal Struct for manage the read mark for a specified file 
 */
typedef struct 
{
    MmsMsgId msgId;  /*!< Message identification */
    MSF_UINT8 value; /*!< 1= set or 0= clear */
} MmsSetReadMark;    
    
/*
 * !\brief Signal struct for sending PDU 
 */
typedef struct
{
    MSF_UINT32 length;   /*!< length of PDU */
    unsigned char *pdu;  /*!< vector holding the PDU */
} MmsPduSig; 

/* 
 * !\breif Signal struct for retrieving status for the
 *   persistent storage (mms folder)
 */
typedef struct 
{
    MSF_UINT32 usedMsgBytes; /*!< the total size of files visible in MMT list*/
    MSF_UINT32 numOfMsg;     /*!< total number of message */ 
    MSF_UINT32 totalFolderSize; /*!< total size of all files in the MMS folder */
} MmsFolderStatus;

typedef struct
{
    MSF_UINT32 size;   /*!< length of buffer */
    MSF_UINT8 simId;
    MSF_UINT8 storageType;
    MSF_BOOL isDeferred;
    unsigned char *buffer;  /*!< vector holding the buffer */
} MmsPushNotificationSig; 

/******************************************************************************* 
 * Signal parameters sent from the MMS Service 
 ******************************************************************************/

/*
 *! \brief Signal Struct replying result
 */
typedef struct 
{  
    MmsResult result; /*!< Returned operation code */
    MSF_INT32 responseStatus;  /*!< Returend response status from MMS-C in case of Sending and forwarding */
    char*     responseText;     /*! < Returend response status from MMS-C in case of Sending and forwarding in text */
} MmsResultSig;


typedef struct  
{
    MmsResult result; /*!< Result of operation. */
    MmsMsgId msgId; /*!< Message reference identification */
    MSF_UINT8 storageType;
    char *retrieveText; /*!< Retrieve text on M-retrieve.conf from MMSC. */
} MmsRetrieveMsgReply;

/*
 *! \brief Signal Struct replying result
 */
typedef struct 
{  
    MSF_UINT32 msgId; /*!< Message reference identification */  
	MmsResult result; /*!< Returned operation code */
    MSF_UINT8 storageType;
} MmsMsgDoneReplySig;  // Sandeep: will be used for delete response

/*
 *! \brief Signal Structs replying data  
 */
typedef struct 
{
   MmsResult result; /*!< Returned operation code */
   MmsMsgId msgId;   /*!< Message reference identification */
} MmsMsgReplySig;

/*
 *! \brief Signal Structs replying data  
 */
typedef struct 
{
   MmsResult result; /*!< Returned operation code */
   MmsMsgId msgId;   /*!< Message reference identification */
   char*  responseText; /*! < Returend response status from MMS-C in case of Sending and forwarding in text */
} MmsRRReplySig;

/*
 * ! \brief Signal struct replying number of message 
 */
typedef struct 
{ 
    MmsResult result;      /*!< Returned operation code */
    MSF_UINT32 number;     /*!< Number of messages */
    MmsFolderType folder;  /*!< Folder identity */
} MmsMsgReplyNoOfMsg;

/*
 *! \brief Signal Structs replying data  
 */
typedef struct 
{
   MmsResult result; /*!< Returned operation code */
} PushNotificationReplySig;


/*
 * ! \brief Signal struct service  indication for received message
 */
typedef struct
{
    MmsNotificationType type;   /*!< Type of notification, (eg. Notification */
    MmsMsgId notifId;           /*!< Message reference identification */
    MmsMsgId msgId;
    MSF_UINT8 storageType;
    MSF_UINT8 simId;
    MSF_UINT8 result;
    MSF_UINT32 size;            /*!< Size of message */

    /* Sender address, normally an MmsAddress but here splitted into plain types */
    MmsCharset  fromCharset;    /*!< Well-known character set as defined by IANA */
    char        *fromName;      /*!< Display name (e.g. Bill Löfgren, AU-System) */
    char        *fromAddress;   /*!< Address (e.g. bill.lofgren@ausystem.se) */
    MmsAddressType fromAddrType;/*!< Address Type (PLMN or EMAIL) */

    /* Subject, normally an MmsEncodedText but here splitted into plain types */
    MmsCharset  subjectCharset; /*!< Well-known character set as defined by IANA */
    char        *subjectText;   /*!< Text buffer, must be NULL terminated */
    MSF_UINT32 expiryDate; /* Sandeep: Added */
    MmsClassIdentifier msgClass;
    MmsPriority priority;
} MmsMsgReplyNotification;

/*
 * ! \brief Signal struct received read report 
 */
typedef struct 
{
    char *address;            /*!< Address (e.g. bill.lofgren@ausystem.se) */
    MmsAddressType addrType;  /*!< Address Type (PLMN or EMAIL) */
    MmsCharset  charset;      /*!< Well-known character set as defined by IANA */
    char        *text;        /*!< Text buffer, must be NULL terminated */ 
    MmsTimeSec date;          /*!< Arrival time of the message at the MMSProxy-Relay. */
    char *serverMessageId;    /*!< Unique reference assigned to the message */
	char *subject;				
    MmsReadStatus readStatus; /*!< Read-Status of the message.*/
    MSF_UINT32 msgId;         /*!< Message is to the orignated message or zero if it is 
                                   not found */
    MSF_UINT8 simId;
	MSF_UINT8  storageType;
} MmsMsgReadReport; 

/* 
 * ! \brief Signal struct received delivery report
 */ 
typedef struct 
{
    char *serverMsgId;          /*!< The unique reference (assigned by the MMS Proxy-Relay)
                            to the message. */
    char *address;              /*!< The recipent address. */
	char *subject;
    MmsAddressType addrType;    /*!< Address Type (PLMN or EMAIL) */
    MmsCharset  charset;        /*!< Well-known character set as defined by IANA */
    char        *text;          /*!< Arrival time of the message at the MMSProxy-Relay. */
    MmsTimeSec date;            /*!< Date and time when the message was handled */
    MmsStatus status;           /*!< Status of the message. */
    MSF_UINT32 msgId;           /*!< Message id to the orignated message or zero not
                                     found */ 
    MSF_UINT8 simId;
	MSF_UINT8  storageType;
} MmsMsgDeliveryReportInd;

/* 
 * ! \brief Signal struct for requesting a conent list of message.
 */ 
typedef struct
{
  MSF_INT32 from;          /*!< starting number in the list        */
  MSF_INT32 to;            /*!< stoping number in the list         */
  MSF_UINT8 storageType;    /*!< Phone or memory card */
} MmsMsgContentReq;

/*
 *! \brief Information kept for every message stored in a folder.
 */
typedef struct 
{
    MSF_UINT32 msgId;       /*!< message Id          */
	MSF_UINT32 date;
} MmsMessageFolderInfo;

typedef struct
{
    MmsMessageFolderInfo    msgFolderInfo;
} MmsMessageProperties;

/*
 * ! \brief Signal struct replying a list of stored message in folder 
 *          reply data MMS_SIG_GET_FOLDER_CONTENT
 */
typedef struct 
{
    MSF_UINT32 startEntry;
    MSF_UINT32 noOfElements;                    /*!< Number of elements in the array below */ 
    MmsMessageProperties *msgPropertyList;      /*!<    First field in an array of unspecified length */
	MSF_UINT8 storageType;
    MSF_BOOL more;          /* for unlimited mms support */
} MmsListOfProperties;


/*--- Prototypes ---*/
 
/*!
 * \brief Creates an empty message in the draft folder.
 *
 * All operations (e.g. send, move, modify) on messages in the MMS client uses 
 * a unique message ID. Before these operations can be performed, a message 
 * must be created in the Draft folder. This function performs both operations.
 *
 * Type: Signal Function 
 *
 * Reply Signal: 
 *      signal name: #MMS_SIG_CREATE_MSG_REPLY
 *      data type    #MmsMsgReplySig
 *
 * \param source The calling module identity
 *****************************************************************************/
void MMSif_createMessage(MSF_UINT8 source,  MmsFileType fileType, MSF_UINT8 storageType, MSF_BOOL alwaysCreate);

/*!
 * \brief Deletes a stored message.
 *
 * A previously stored message is deleted from whatever folder it is stored in.
 * Both body and header part of the message is deleted.
 *
 * Type: Signal Function
 *
 * Reply signal
 *      signal name: #MMS_SIG_DELETE_MSG_REPLY
 *      data type    #MmsResultSig
 *
 * \param source The calling module identity
 * \param msgId A unique identity for a multimedia message.
 *****************************************************************************/
void MMSif_deleteMessage(MSF_UINT8 source, MmsMsgId msgId, MmsFileType fileType, MSF_UINT8 storage);


/*!
 * \brief Get the number of messages in one or all folder.  
 *
 * Type: Signal Function
 *
 * Reply signal:
 *       signal name: #MMS_SIG_GET_NUM_OF_MSG_REPLY
 *       data type:   #MmsMsgReplyNoOfMsg
 *
 * \param source The calling module identity
 * \param folder What folder to count messages in. If the request concerns 
 *        all folders MMS_ALL_FOLDERS should be used. 
 *****************************************************************************/
void MMSif_getNumberOfMessages(MSF_UINT8 source, MmsFolderType folder);

/*!
 * \brief Move a message between folders. 
 *
 * A message indicated by the message ID is moved from the current folder 
 * to the new folder that is given as parameter.
 *
 * Type: Signal Function 
 *
 * Reply signal:
 *       signal name: #MMS_SIG_MOV_MSG_REPLY
 *       data type:   #MmsResultSig
 *
 * \param source The calling module identity
 * \param msgId A unique identity for a multimedia message.
 * \param folder The folder that the message shall be moved to. 
 *        NOTE! MMS_ALL_FOLDERS is not a vaild value in this operation.
 *****************************************************************************/
void MMSif_moveMessage(MSF_UINT8 source, MmsMsgId msgId, MSF_UINT8 suffix, MSF_UINT8 OriStorageType, MSF_UINT8 destStorageType, MSF_UINT8 isMoveMsg);

/*!
 * \brief Cancel an ongoing Retrieve operation for a message.
 *
 * An ongoing Retrieve operation on a multimedia message is cancelled.
 * Only one type of operation can be executed at a time so the last
 * call to MMSc_retrieveMessage for the given notification ID is terminated. 
 *
 * Type: Signal Function
 *
 * Reply signal name: None.
 *
 * \param source The calling module identity
 * \param notifId The identity of a notification.
 *****************************************************************************/
void MMSif_retrieveCancel(MSF_UINT8 source, MmsMsgId notifId);

/*!
 * \brief Retrieve a message from the MMS server.
 *
 * A multimedia message is retrieved from the MMS Proxy-Relay and is stored in the 
 * Inbox.
 *
 * Type: Signal Function
 *
 * Reply signal
 *       signal name: #MMS_SIG_RETRIEVE_MSG_REPLY
 *       data type:   #MmsMsgReplySig
 *                  
 * \param source The calling module identity
 * \param notifId The identity of a notification.
 *****************************************************************************/
void MMSif_retrieveMessage(MSF_UINT8 source, MmsMsgId notifId, MmsSimCardEnum simId, MSF_UINT16 storageData);

/*!
 * \brief Cancel an ongoing Send operation for a message.
 *
 * An ongoing Send operation on a multimedia message is cancelled.
 * Only one type of operation can be executed at a time so the last call
 * to MMSc_sendMessage for the given message ID is terminated.
 *
 * Type: Signal Function 
 *
 * Reply signal name: None.
 *
 * \param source The calling module identity
 * \param msgId The unique identity for a multimedia message.
 *****************************************************************************/
void MMSif_sendCancel(MSF_UINT8 source, MmsMsgId msgId);

/*!
 * \brief Sends a Multimedia Message
 * 
 * The Multimedia Message must exist and be stored in one 
 * of the folders before this function can be called. 
 *
 * Type: Signal Function 
 *
 * Reply signal:
 *       signal name: #MMS_SIG_SEND_MSG_REPLY
 *       data type:   #MmsResultSig
 *
 * \param source The calling module identity
 * \param msgId A unique identity for a multimedia message.
 *****************************************************************************/
void MMSif_sendMessage(MSF_UINT8 source, MmsMsgId msgId, MmsSimCardEnum simId, MSF_UINT8 storageData);


/*!
 * \brief Sends a Read Report for a Multimedia Message
 * 
 * The TDA has detected that the Multimedia Message identified by msgId 
 * contains a Read Report flag and the TDA has decided that a Read Report shall 
 * be sent. When calling this function, all data needed will be collected an 
 * the Read Report will be sent.
 *
 * Type: Signal Function 
 *
 * Reply signal 
 *       signal name: #MMS_SIG_SEND_RR_REPLY
 *       data type:   #MmsResultSig
 *
 * \param source The calling module identity
 * \param msgId A unique identity for a multimedia message.
 * \param readStatus Status of the message to send read report on.
 *****************************************************************************/
void MMSif_sendReadReport(MSF_UINT8 source, MmsMsgId msgId,
    MmsReadStatus readStatus, MmsSimCardEnum simId, MSF_UINT16 storageData);
                        
/*!
 * \brief Indicates end of messge creation
 *
 * Type: Signal Function 
 *
 * Reply signal: 
 *       signal name: #MMS_SIG_MSG_DONE_REPLY
 *       data type:   #MmsMsgReplySig
 *
 * This function indicates to the MMS client that the creation of a message is 
 * done. When creating a Multimedia Message, it can contain multiple parts. 
 * When this connector is called, no more parts will be added. 
 *
 * \param msgId A unique identity for a multimedia message.
 *****************************************************************************/
 void MMSif_createMessageDone(MSF_UINT8 source, MmsMsgId msgId, MmsFileType fileType, MSF_UINT8 storageType);

/*!
 * \brief Request a content of messages from a folder
 *
 * Type: Signal Function 
 *
 * Reply signal
 *       signal name: #MMS_SIG_GET_FLDR_REPLY
 *       data type: (void *) byte vector that must be casted to 
 *                  the type #MmsListOfProperties.
 *
 * This function reqests a list of message information stored in one of the 
 * folders. The order of the list can be sorted by fields: 
 *  - received  date
 *  - address   when the message is in the Draft, Outbox or Sent folder is 
 *              the "To" field used else is the "From" field used (inbox).
 *  - subject   compers the XX firt chars in the subject field. 
 *
 * \param folderId The folder where message is stored.  
 * \param sortedBy The content list is sorted by date, address or subject.
 * \param from  starting number in the list
 * \param to    stoping number in the list
  *****************************************************************************/
 void MMSif_getMMSList(MSF_UINT8 source, int from, int to, MSF_UINT8 storageType);


/*
 * MSF functions 
 *
 *****************************************************************************/

MSF_BOOL mmsSendSignalExt(MSF_UINT8 senderModId, MSF_UINT8 destModule,
    MSF_UINT16 signal, void *data, MSF_UINT32 size); 



/*!
 * \brief Copy the internal structure of MmsMessageProperties.
 *
 * \param toProperties    Structure to be updated.
 * \param properties      Structure to be copied.
 * \param module          Memory owner.
 */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif



void MMSif_pushNotification(MSF_UINT8 source, unsigned char * buffer, MSF_UINT32 size, MSF_UINT8 simId, MSF_UINT8 storageType, MSF_BOOL isDeferred);

#endif /* _MMS_IF_H */


