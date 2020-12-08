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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   MapObjSrv.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains MAP object, ex. XML and vCard, handling functions.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================*/

#ifndef __BT_MAP_OBJ_H__
#define __BT_MAP_OBJ_H__

#include "BtcmSrvGprot.h"
#ifdef __BT_MAP_CLIENT__
#define MBT_MAP_MAX_MCE_NUM				2	// The number of MCE devices
#define MBT_MAP_MAX_MAS_INST_NUM		2	// [MAP_CHECK] The number of MAS Instances (using 4 in BRCM)
#define MBT_MAP_MAX_CONN_NUM			4	// (MBT_MAP_MAX_MCE_NUM * MBT_MAP_MAX_MAS_INST_NUM)
#define MBT_MAP_MAX_SVC_NAME_LEN		256	// [MAP_CHECK] (using 256 in btapp of BRCM)
#define MBT_MAP_MAX_FOLDER_PATH_LEN		512	// This shall be restricted to 512 Bytes in spec.
#define MBT_MAP_MAX_MSG_LIST_ATTR_LEN	256	// This shall not exceed 256 bytes in spec.
#define MBT_MAP_MAX_DATETIME_LEN		17	// The format shall be "YYYYMMDDTHHMMSS" in spec. (using 17 in BRCM)
#define MBT_MAP_MAX_TIME_LEN			21	// The format shall be "YYYYMMDDTHHMMSS+-hhmm" in spec.
#define MBT_MAP_MAX_FILTER_TEXT_LEN		256	// [MAP_CHECK] (using 256 in BRCM)
#define MBT_MAP_MAX_MSG_ENVELOPE_NUM	3	
#define MBT_MAX_FILE_NAME_LEN           256
#define MBT_MAX_NAME_LEN                59
#define MAP_ADP_BUFFER_SIZE             1024
#define MAP_ADP_MAX_FRAGMENT_SIZE_NUM   255 // long sms message can be divided to 255 at most 


#define MBT_MAP_MSG_TYPE_SMS_GSM			0x01	// Emails on RFC2822 or MIME type basis
#define MBT_MAP_MSG_TYPE_SMS_CDMA			0x02	// GSM short messages
#define MBT_MAP_MSG_TYPE_EMAIL				0x04	// CDMA short messages
#define MBT_MAP_MSG_TYPE_MMS				0x08	// 3GPP MMS messages
typedef unsigned char MBT_MAP_MSG_TYPE;


#define MAP_ADP_WORK_FOLDER L"z:\\@maps\\"

#define BT_MAP_FOLDER_LIST_FILE "z:\\@maps\\maps_fl%d.xml"
#define BT_MAP_MESSAGE_LIST_FILE "z:\\@maps\\maps_ml%d.xml"
#define BT_MAP_MESSAGE_GET_FILE "z:\\@maps\\maps_gm%d.vcf"
#define BT_MAP_EVENT_REPORT_FILE "z:\\@maps\\maps_er%d.xml"
#define BT_MAP_PUSH_MESSAGE_FILE "z:\\@maps\\maps_pm%d.xml"


#define BT_MAP_TMP_FILE              "z:\\@maps\\map%d.tmp"
#define BT_MAP_RCV_MESSAGE_PUSH_FILE "z:\\@maps\\pmr%d.vcf"

#define MAX_FILE_NAME  200


enum
{
	MBT_MAP_ATTACH_TYPE_OFF = 0,			// no attachments
	MBT_MAP_ATTACH_TYPE_ON = 1			// attachments to be delivered
};
typedef unsigned char MBT_MAP_ATTACH_TYPE;

enum
{
	MBT_MAP_STORAGE_TYPE_NONE = 0,
	MBT_MAP_STORAGE_TYPE_BUFFER = 1,		// struct buffer
	MBT_MAP_STORAGE_TYPE_FILE = 2,			// struct file
	MBT_MAP_STORAGE_TYPE_RAW_BUFFER = 3,	// raw buffer
	MBT_MAP_STORAGE_TYPE_RAW_FILE = 4		// raw file
};
typedef unsigned char MBT_MAP_STORAGE_TYPE;

enum 
{
	MBT_MAP_NEW_MSG_STATUS_OFF = 0,
	MBT_MAP_NEW_MSG_STATUS_ON = 1
};
typedef unsigned char MBT_MAP_NEW_MSG_STATUS;

// MAP Message Type Mask for FilterMessageType
#define MBT_MAP_MSG_TYPE_MASK_SMS_GSM	0x01
#define MBT_MAP_MSG_TYPE_MASK_SMS_CDMA	0x02
#define MBT_MAP_MSG_TYPE_MASK_EMAIL		0x04
#define MBT_MAP_MSG_TYPE_MASK_MMS		0x08
typedef unsigned char MBT_MAP_MSG_TYPE_MASK;

// MAP Priority Status used for filtering message list
enum
{
	MBT_MAP_PRI_STATUS_NO_FILTERING = 0,
	MBT_MAP_PRI_STATUS_HIGH = 1,
	MBT_MAP_PRI_STATUS_NON_HIGH = 2
};
typedef unsigned char MBT_MAP_PRI_STATUS;

// MAP PushMessage Enum ----------------------------------
// MAP Transparent Type
enum
{
	MBT_MAP_TRANSP_TYPE_OFF = 0,			// keep messages in 'Sent' folder (default)
	MBT_MAP_TRANSP_TYPE_ON = 1			// don't keep messages in Sent' folder
};
typedef unsigned char MBT_MAP_TRANSP_TYPE;

// MAP Retry Type
enum
{
	MBT_MAP_RETRY_TYPE_OFF = 0,			// don't retry the successive attempts at sending the message
	MBT_MAP_RETRY_TYPE_ON = 1			// retry (default) check!!
};
typedef unsigned char MBT_MAP_RETRY_TYPE;

enum 
{
	MBT_MAP_NOTIF_STATUS_OFF = 0,
	MBT_MAP_NOTIF_STATUS_ON = 1
};
typedef unsigned char MBT_MAP_NOTIF_STATUS;
// MAP SendEvent Enum ------------------------------------
// MAP Notification Type
enum
{
	MBT_MAP_NOTIF_TYPE_NEW_MSG = 0,     
	MBT_MAP_NOTIF_TYPE_DELIVERY_SUCCESS,        
	MBT_MAP_NOTIF_TYPE_SENDING_SUCCESS,        
	MBT_MAP_NOTIF_TYPE_DELIVERY_FAILURE,     
	MBT_MAP_NOTIF_TYPE_SENDING_FAILURE,      
	MBT_MAP_NOTIF_TYPE_MEMORY_FULL,     
	MBT_MAP_NOTIF_TYPE_MEMORY_AVAILABLE,       
	MBT_MAP_NOTIF_TYPE_MSG_DELETED,     
	MBT_MAP_NOTIF_TYPE_MSG_SHIFT,            
	MBT_MAP_NOTIF_TYPE_MAX
};
typedef unsigned char MBT_MAP_NOTIF_TYPE;

// MAP Reception Status
enum
{
	MBT_MAP_RCV_STATUS_COMPLETE = 0,
	MBT_MAP_RCV_STATUS_FRACTIONED,
	MBT_MAP_RCV_STATUS_NOTIFICATION
};
typedef unsigned char MBT_MAP_RCV_STATUS;


// MAP Fraction Request
enum
{
	MBT_MAP_FRAC_REQ_FIRST = 0,
	MBT_MAP_FRAC_REQ_NEXT = 1,	
	MBT_MAP_FRAC_REQ_NO					// This is not a fraction request
};
typedef unsigned char MBT_MAP_FRAC_REQ;

// MAP Fraction Delivery
enum
{
	MBT_MAP_FRAC_DELIVER_MORE = 0,
	MBT_MAP_FRAC_DELIVER_LAST = 1,		// in case of the last email fraction of the message object
	MBT_MAP_FRAC_DELIVER_NO				// This is not a fraction request
};
typedef unsigned char MBT_MAP_FRAC_DELIVER;

// MAP bmessage-version-property
enum
{
	MBT_MAP_MSG_VER_10 = 0,				// bMessage version 1.0
	MBT_MAP_MSG_VER_MAX
};
typedef unsigned char MBT_MAP_MSG_VERSION;

// MAP Read Status used for message list and bmessage-readstatus-property
enum
{
	MBT_MAP_MSG_STATUS_NO_FILTERING = 0,
	MBT_MAP_MSG_STATUS_UNREAD = 1,		// The message has not yet been read. (default)
	MBT_MAP_MSG_STATUS_READ = 2			// The message has been read.
};
typedef unsigned char MBT_MAP_MSG_READ_STATUS;

// MAP bmessage-body-encoding-property
enum
{
	MBT_MAP_MSG_ENCOD_8BIT = 0,			// For Email/MMS : 8-Bit-Clean encoding
	MBT_MAP_MSG_ENCOD_G7BIT,			// For GSM-SMS : GSM 7 bit Default Alphabet
	MBT_MAP_MSG_ENCOD_G7BITEXT,			// For GSM-SMS : GSM 7 bit Alphabet with national language extension 
	MBT_MAP_MSG_ENCOD_GUCS2,			// For GSM-SMS
	MBT_MAP_MSG_ENCOD_G8BIT,			// For GSM-SMS 
	MBT_MAP_MSG_ENCOD_C8BIT,			// For CDMA-SMS : Octet, unspecified
	MBT_MAP_MSG_ENCOD_CEPM,				// For CDMA-SMS : Extended Protocol Message
	MBT_MAP_MSG_ENCOD_C7ASCII,			// For CDMA-SMS : 7-bit ASCII
	MBT_MAP_MSG_ENCOD_CIA5,				// For CDMA-SMS : IA5
	MBT_MAP_MSG_ENCOD_CUNICODE,			// For CDMA-SMS : UNICODE
	MBT_MAP_MSG_ENCOD_CSJIS,			// For CDMA-SMS : Shift-JIS
	MBT_MAP_MSG_ENCOD_CKOREAN,			// For CDMA-SMS : Korean
	MBT_MAP_MSG_ENCOD_CLATINHEB,		// For CDMA-SMS : Latin/Hebrew
	MBT_MAP_MSG_ENCOD_CLATIN,			// For CDMA-SMS : Latin
	MBT_MAP_MSG_ENCOD_MAX
};
typedef unsigned char MBT_MAP_MSG_ENCODING;


// MAP bmessage-body-charset-property
enum
{
	MBT_MAP_MSG_CHARSET_NATIVE = 0,
	MBT_MAP_MSG_CHARSET_UTF8 = 1
};
typedef unsigned char MBT_MAP_MSG_CHARSET;

// MAP bmessage-body-language-property
enum
{
	MBT_MAP_MSG_LANG_ENGLISH = 0,		// For CDMA-SMS
	MBT_MAP_MSG_LANG_FRENCH,			// For CDMA-SMS
	MBT_MAP_MSG_LANG_SPANISH,			// For CDMA-SMS and GSM-SMS
	MBT_MAP_MSG_LANG_JAPANESE,			// For CDMA-SMS
	MBT_MAP_MSG_LANG_KOREAN,			// For CDMA-SMS
	MBT_MAP_MSG_LANG_CHINESE,			// For CDMA-SMS
	MBT_MAP_MSG_LANG_HEBREW,			// For CDMA-SMS
	MBT_MAP_MSG_LANG_TURKISH,			// For GSM-SMS
	MBT_MAP_MSG_LANG_PORTUGUESE,		// For GSM-SMS
	MBT_MAP_MSG_LANG_UNKNOWN,			// For GSM-SMS and CDMA-SMS
	MBT_MAP_MSG_LANG_MAX
};
typedef unsigned char MBT_MAP_MSG_LANG;

enum
{
	MBT_MAP_STATE_NONE = 0,					// Not used
	MBT_MAP_STATE_CONNECTING,
	MBT_MAP_STATE_CONNECTED,
	MBT_MAP_STATE_DISCONNECTING,
	MBT_MAP_STATE_OPERATING
} ;
typedef unsigned char MBT_MAP_STATE;

enum
{
	MBT_MAP_OPER_NONE = 0,
	MBT_MAP_OPER_SET_NOTIF_REG,
	MBT_MAP_OPER_SET_FOLDER,
	MBT_MAP_OPER_GET_FOLDER_LIST,
	MBT_MAP_OPER_GET_MSG_LIST,
	MBT_MAP_OPER_GET_MSG,
	MBT_MAP_OPER_SET_MSG_STATUS,
	MBT_MAP_OPER_PUSH_MSG,
	MBT_MAP_OPER_UPDATE_INBOX,
	MBT_MAP_OPER_MAX
} ;
typedef unsigned char MBT_MAP_OPERATION;

enum
{
	MBT_FORBID_RES = 0,				// authorization reject
	MBT_ALLOW_RES,					// authorization allow
	MBT_ERROR_RES,					// error response
	MBT_UNAUTHORIZED_RES,			//read only
	MBT_NOT_FOUND_RES,				//file not found
	MBT_UNSUPPORTED_MEDIA_TYPE_RES, //unsupport type
	MBT_SERVICE_UNAVAILABLE_RES,	//unsupport function
	MBT_DATABASE_FULL_RES,			//no space
	MBT_INTERNAL_SERVER_ERROR_RES,	//etc
	MBT_UNSUPPORTED_DEVICE_TYPE_RES,
	MBT_BAD_REQUEST_RES,
	MBT_FORBIDDEN_RES,
	MBT_NOT_ACCEPTABLE_RES,
	MBT_PRECONDITION_FAILED_RES,
	MBT_NOT_IMPLEMENTED_RES,
};
typedef unsigned char MBT_AUTHRES;


// MAP Status Value
enum
{
	MBT_MAP_STATUS_VAL_NO = 0,
	MBT_MAP_STATUS_VAL_YES = 1
};
typedef unsigned char MBT_MAP_STATUS_VAL;

enum
{
	MBT_MAP_STATUS_IND_READ = 0,
	MBT_MAP_STATUS_IND_DELETE = 1
};
typedef unsigned char MBT_MAP_STATUS_IND;

typedef struct
{
	unsigned char	Mode;
	char			Time[MBT_MAP_MAX_DATETIME_LEN]; // "yyyymmddTHHMMSSZ", or "" if none
	U32				Size;
	char			Name[MBT_MAX_FILE_NAME_LEN];	

} MBT_MAP_FOLDER_LIST_ENTRY;


// [MAP] Structure for SendEvent
// MAP Event-Report Object
typedef struct
{
	MBT_MAP_NOTIF_TYPE	NotifType;
	U64					MsgHandle;		// The handle shall be a 64 bit unsigned integer in spec.
	char				FolderPath[MBT_MAP_MAX_FOLDER_PATH_LEN];
	char				OldFolderPath[MBT_MAP_MAX_FOLDER_PATH_LEN];
	MBT_MAP_MSG_TYPE	MsgType;

} MBT_MAP_EVT_REPORT_OBJECT;

typedef struct
{	// Request Out
	unsigned char	MasInstId;		// [M] The value range shall be 0..255 in spec.
	MBT_MAP_EVT_REPORT_OBJECT EvtRptObj;		// [M]

} MBT_MAP_SEND_EVENT_REQ;

// [MAP] Structure for GetMessagesListing
typedef struct
{
	U32					ParamMask;		// [O] [MAP_CHECK] bit 0..bit 31 in spec. (T_MBT_MAP_ML_MASK)
	U64					MsgHandle;		// [M] The handle shall be a 64 bit unsigned integer in spec.
	char				Subject[MBT_MAP_MAX_MSG_LIST_ATTR_LEN];		// [M] Title, the first words of the message, or "" (This length shall be used according to the requested value in GetMessagesListing)
	char				DateTime[MBT_MAP_MAX_DATETIME_LEN];			// [M] The sending time or the reception time in format "YYYYMMDDTHHMMSS"
	char				SenderName[MBT_MAP_MAX_MSG_LIST_ATTR_LEN];	// [C]
	char				SenderAddr[MBT_MAP_MAX_MSG_LIST_ATTR_LEN];	// [C] The senders email address or phone number
	char				ReplyToAddr[MBT_MAP_MAX_MSG_LIST_ATTR_LEN];	// [C] This shall be used only for emails to deliver the sender's reply-to email address.
	char				RecipientName[MBT_MAP_MAX_MSG_LIST_ATTR_LEN];	// [C] The recipient's email address, a list of email addresses, or phone number
	char				RecipientAddr[MBT_MAP_MAX_MSG_LIST_ATTR_LEN];	// [M] If the recipient is not known this may be left empty.
	MBT_MAP_MSG_TYPE	MsgType;		// [M]
	U32					OriginMsgSize;	// [M] [MAP_CHECK] The overall size in bytes of the original message as received from network (using UINT16 in BRCM)
	MMI_BOOL			bText;			// (default 'no') (The message includes textual content or not)
	MBT_MAP_RCV_STATUS	ReceptionStatus;	// [M]
	U32					AttachSize;		// [M] [MAP_CHECK] (using UINT16 in BRCM)
	MMI_BOOL			bPriority;		// (default 'no') The message is of high priority or not.
	MMI_BOOL			bRead;			// (default 'no') The message has already been read on the MSE or not.
	MMI_BOOL			bSent;			// (default 'no') The message has already been sent to the recipient or not.
	MMI_BOOL			bProtected;		// (default 'no') The message is protected by a DRM schem or not.

} MBT_MAP_MSG_LIST_ENTRY;



// [MAP] Structure for GetMessage
// MSE shall deliver only a bBody object if the value of FracReq is 'next'.
// vCard Object (Originator and Recipient)
// 1) vCard 2.1 : VERSION/N(Mandatory), TEL/EMAIL(Optional)
// 2) vCard 3.0 : VERSION/N/FN(Mandatory), TEL/EMAIL(Optional)
// All the other vCard properties shall not be used.
// The properties may be empty if not known by the MSE, e.g. N/FN in case of a SMS.
typedef struct
{	
	// <bmessage-property>
	MBT_MAP_MSG_VERSION			MsgVer;
	MBT_MAP_MSG_READ_STATUS		ReadStatus;
	MBT_MAP_MSG_TYPE			MsgType;
	char						FolderPath[MBT_MAP_MAX_FOLDER_PATH_LEN]; // The folder name including the path
	// [<bmessage-originator>]*
	U32							OriginatorSize;
	char*						Originator;		// Nested vCard Object
	// <bmessage-envelope>
	struct
	{	// [<bmessage-recipient>]*
		U32						RecipientSize;
		char*					Recipient;		// Nested vCard Object
	} Envelope[MBT_MAP_MAX_MSG_ENVELOPE_NUM];	// bmessage-envelope
	
	// <bmessage-content> (bBody Object)
	U16							PartId;			// This value shall have a part-ID incremented by 1 each in spec. (0 ~ 65535)
	// <bmessage-body-property>
	MBT_MAP_MSG_ENCODING		Encoding;
	MBT_MAP_MSG_CHARSET			Charset;			// This shall be used only if the message contains textual content in spec.
	MBT_MAP_MSG_LANG			Lang;			// This may be used if the message includes textual content in spec.
	// <bmessage-body-content>*
	U32							FragmentNum;
	U32							FragmentSize[MAP_ADP_MAX_FRAGMENT_SIZE_NUM];
	U32							ContentSize;
	char*						Content;
} MBT_MAP_MSG_OBJECT;



//the structure just indicate a mas infomation
typedef struct
{
	U8					MasInstId;		// MAS Instance ID (The value range shall be 0..255 in spec. But zero(0) is not used.)
	U8					SvcName[MBT_MAP_MAX_SVC_NAME_LEN]; // The service name of MAS Instance
	U8					SupMsgType;	// The message type(s) to be supported (SMS, MMS, Email)
	U8					RootPath[MBT_MAX_FILE_NAME_LEN]; // The root path of MAS Server

} MBT_MAP_MAS_INFO;

typedef struct
{	// Request In
	U16					MaxListCount;	// [O] 2bytes in spec (default 1024)
	U16					ListStartOffset;	// [O] 2bytes in spec (default 0)

} MBT_MAP_GET_FOLDER_LIST_REQ;


typedef struct
{	// Request In
	MBT_MAP_NOTIF_STATUS		NotifStatus;		// [M]

} MBT_MAP_SET_NOTIF_REG_REQ;

typedef struct
{	// Request In
	U64					MsgHandle;		// [M] The handle shall be a 64 bit unsigned integer in spec.
	MBT_MAP_STATUS_IND	StatusInicator;	// [M]
	MBT_MAP_STATUS_VAL	StatusVal;		// [M]

} MBT_MAP_SET_MSG_STATUS_REQ;

typedef struct
{	// Request In
	U64						MsgHandle;		// [M] The handle shall be a 64 bit unsigned integer in spec.
	MBT_MAP_ATTACH_TYPE		Attach;			// [M]
	MBT_MAP_MSG_CHARSET		Charset;			// [M]
	MBT_MAP_FRAC_REQ		FracReq;		// [O]

} MBT_MAP_GET_MSG_REQ;

typedef struct
{	// Response Out
	U64					MsgHandle;		// [C] The handle shall be a 64 bit unsigned integer in spec.
} MBT_MAP_PUSH_MSG_RSP;

// [MAP] Structure for PushMessage
typedef struct
{	// Request In
	char					FolderPath[MBT_MAP_MAX_FOLDER_PATH_LEN]; // [M] PI should save the full folder path.
	MBT_MAP_TRANSP_TYPE		Transp;			// [O]
	MBT_MAP_RETRY_TYPE		Retry;			// [O]
	MBT_MAP_MSG_CHARSET		Charset;			// [M]

	MBT_MAP_STORAGE_TYPE		StorageType;	// The storage type
	union
	{
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_BUFFER
		{
			MBT_MAP_MSG_OBJECT Msg;
			U32			AllocatedContentSize;
		} Buffer;
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_RAW_BUFFER
		{		
			U32			Size;
			char*			RawData;
		} RawBuffer;
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_FILE or MBT_MAP_STORAGE_TYPE_RAW_FILE
		{			
			MBT_MAP_MSG_OBJECT Msg;			// This is used for only MBT_MAP_STORAGE_TYPE_FILE. (Except the message contents)
			U32			Size;
			char			FileName[MBT_MAX_FILE_NAME_LEN]; // The file name including the full path
		} File;
	} Data;
} MBT_MAP_PUSH_MSG_REQ;



typedef struct
{	// Response Out
	MBT_MAP_FRAC_DELIVER		FracDeliver;		// [C1]

	MBT_MAP_STORAGE_TYPE		StorageType;	// The storage type
	union
	{
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_BUFFER
		{
			MBT_MAP_MSG_OBJECT Msg;
		} Buffer;
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_RAW_BUFFER
		{		
			U32			Size;
			char*			RawData;
		} RawBuffer;
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_FILE or MBT_MAP_STORAGE_TYPE_RAW_FILE
		{
			MBT_MAP_MSG_OBJECT Msg;			// This is used for only MBT_MAP_STORAGE_TYPE_FILE. (Except the message contents)
			U32			Size;
			char			FileName[MBT_MAX_FILE_NAME_LEN]; // The file name including the full path
		} File;
	} Data;
}MBT_MAP_GET_MSG_RSP;

// [MAP] Structure for SetFolder
typedef struct
{	// Request In
	char					FolderPath[MBT_MAP_MAX_FOLDER_PATH_LEN]; // [M] PI should save the full folder path.
} MBT_MAP_SET_FOLDER_REQ;

typedef struct
{	// Response Out
	MBT_MAP_STORAGE_TYPE		StorageType;	// The storage type
	U16					TotalFolderNum;	// [C] 2bytes in spec (The actual number of accessible folders)
	U16					TodoFolderNum;	
	union
	{
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_BUFFER
		{
			U32			FolderNum;
			MBT_MAP_FOLDER_LIST_ENTRY* FolderList;
		} Buffer;
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_RAW_BUFFER
		{		
			U32			Size;
			char*			RawData;
		} RawBuffer;
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_FILE or MBT_MAP_STORAGE_TYPE_RAW_FILE
		{			
			U32			Size;
			char			FileName[MBT_MAX_FILE_NAME_LEN]; // The file name including the full path
		} File;
	} Data;
}MBT_MAP_GET_FOLDER_LIST_RSP;

typedef struct
{	// Response Out
	// If 'MaxListCount=0' in the request shall response with the headers 'NewMsg' and 'MsgListSize' only in spec.
	MBT_MAP_NEW_MSG_STATUS	NewMsg;		// [C]
	char					MSETime[MBT_MAP_MAX_TIME_LEN]; // [C] The format shall be "YYYYMMDDTHHMMSS+-hhmm" in spec.

	MBT_MAP_STORAGE_TYPE		StorageType;	// The storage type
	U16					TotalMsgNum;	// [C] 2bytes in spec (The number of accessible messages)
	U16					TodoMsgNum;	//
	union
	{
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_BUFFER
		{
			U32			MsgNum;
			MBT_MAP_MSG_LIST_ENTRY* MsgList;
		} Buffer;
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_RAW_BUFFER
		{		
			U32			Size;
			char*			RawData;
		} RawBuffer;
		struct	// StorageType = MBT_MAP_STORAGE_TYPE_FILE or MBT_MAP_STORAGE_TYPE_RAW_FILE
		{			
			U32			Size;
			char			FileName[MBT_MAX_FILE_NAME_LEN]; // The file name including the full path
		} File;
	} Data;
} MBT_MAP_GET_MSG_LIST_RSP;

// If 'MaxListCount' and 'ListStartOffset' is requested, then it shall be applied first.
typedef struct
{	// Request In
	char					FolderPath[MBT_MAP_MAX_FOLDER_PATH_LEN]; // [M] PI should save the full folder path.
	unsigned char					SubjectLen;		// [O] The value range shall be 1...255 in spec.
	U16					MaxListCount;	// [O] 2bytes in spec (PI: This shall be 1,024 if this header is not specified in spec.)
	U16					ListStartOffset;	// [O] 2bytes in spec (Starting from this value)
	U32					ParamMask;		// [O] bit 0..bit 31 in spec. (MBT_MAP_ML_MASK)
	MBT_MAP_MSG_TYPE_MASK		FilterMsgType;	// [O]
	char					FilterPeriodBegin[MBT_MAP_MAX_DATETIME_LEN];	// [O] The format shall be "YYYYMMDDTHHMMSS" in spec.
	char					FilterPeriodEnd[MBT_MAP_MAX_DATETIME_LEN];		// [O] The format shall be "YYYYMMDDTHHMMSS" in spec.
	MBT_MAP_MSG_READ_STATUS		FilterReadStatus; // [O] 
	char					FilterRecipient[MBT_MAP_MAX_FILTER_TEXT_LEN];		// [O] 
	char					FilterOriginator[MBT_MAP_MAX_FILTER_TEXT_LEN];	// [O] 
	MBT_MAP_PRI_STATUS			FilterPriority;	// [O]
} MBT_MAP_GET_MSG_LIST_REQ;

// MAP MAS Status
typedef struct
{
	/*it is neccessary to keep the MAS info for porting*/
	MBT_MAP_MAS_INFO         	masInfo;

	MMI_BOOL						registered;

	MBT_MAP_STATE				State;			// The state for MAS
	
	
	srv_bt_cm_bt_addr				BdAddr;			// The address of the remote device (MCE)
	char					DevName[MBT_MAX_NAME_LEN]; // The name of the remote device (MCE)
//	unsigned char					MasInfoIdx;		// The index for MasInfo
	
	MBT_MAP_OPERATION			OperType;		// The MAS operation for the access request
	char					CurFolderPath[MBT_MAP_MAX_FOLDER_PATH_LEN]; // Current folder path
	MBT_AUTHRES					FailReason;		// This should only be used in case of the fail event.	

	MBT_MAP_FRAC_REQ          FracReq;        //only be used when get message
	
	union
	{	
		MBT_MAP_SET_NOTIF_REG_REQ		SetNotifReg;
		MBT_MAP_SET_FOLDER_REQ			SetFolderReq;
		MBT_MAP_SET_MSG_STATUS_REQ		SetMsgStatusReq;

		struct
		{
			MBT_MAP_GET_FOLDER_LIST_REQ	Req;
			MBT_MAP_GET_FOLDER_LIST_RSP	Rsp;
		} GetFolderList;
		struct
		{		
			MBT_MAP_GET_MSG_LIST_REQ	Req;
			MBT_MAP_GET_MSG_LIST_RSP		Rsp;
		} GetMsgList;
		struct
		{		
			MBT_MAP_GET_MSG_REQ			Req;
			MBT_MAP_GET_MSG_RSP			Rsp;
		} GetMsg;
		struct
		{				
			MBT_MAP_PUSH_MSG_REQ		Req;
			MBT_MAP_PUSH_MSG_RSP		Rsp;
		} PushMsg;		
	} Oper;
}MBT_MAP_MAS_STATUS;


U32 btmtk_map_xml_create_folder_list_by_buffer(S8 mas_index,
                                               U32 FolderNum,
                                               MBT_MAP_FOLDER_LIST_ENTRY *list,
                                               S16 offset,
                                               S16 more, 
                                               S32 seq_write_fhandle);

U32 btmtk_map_xml_create_folder_list_by_file(S8 mas_index,
											 char *filename,
											 U32 filesize);

U32 btmtk_map_xml_create_message_list_by_buffer(S8 mas_index,
                                                U32 msg_num,
                                                MBT_MAP_MSG_LIST_ENTRY *list,
                                                S16 offset,
                                                S16 more, 
                                                S32 seq_write_fhandle);

U32 btmtk_map_xml_create_message_list_by_file(S8 mas_index,
											  char *filename,
											  U32 filesize);

U32 btmtk_map_xml_create_event_report(S8 mas_index, 
									  MBT_MAP_SEND_EVENT_REQ *event);

MMI_BOOL btmtk_map_vcard_create_message_by_buffer(S8 mas_index, 
                                                  MBT_MAP_FRAC_REQ frac_req,
                                                  MBT_MAP_FRAC_DELIVER frac_deliv,
                                                  MBT_MAP_MSG_OBJECT *msg,
                                                  S32 rhandle,
                                                  U32 file_size);

MMI_BOOL btmtk_map_vcard_create_message_by_file(S8 mas_index, 
                                                MBT_MAP_FRAC_REQ frac_req,
                                                MBT_MAP_FRAC_DELIVER frac_deliv,
                                                MBT_MAP_MSG_OBJECT *msg, 
                                                U32 file_size, 
                                                kal_wchar *file_name);


MMI_BOOL btmtk_map_vcard_parse_message_by_buffer(S8 mas_index,
                                                 MBT_MAP_MSG_OBJECT *msg,
                                                 U32 msg_buf_size,
                                                 kal_wchar *to_file);


MMI_BOOL btmtk_map_vcard_parse_message_by_file(S8 mas_index,
                                               MBT_MAP_MSG_OBJECT *msg,
                                               U32 *file_size,
                                               kal_wchar *file_name);

#endif  /* __BT_MAP_OBJ_H__ */
#endif 