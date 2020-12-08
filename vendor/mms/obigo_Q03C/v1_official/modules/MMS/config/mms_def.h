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

 
/*! \file mms_def.h
 * \brief  Data types and definitions used in the MMS client.
 */



/*******************************************************************************
 *
 * Filename:
 * ---------
 * mms_def.h
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

#ifndef _MMS_DEF_H
#define _MMS_DEF_H

/*--- Definitions/Declarations ---*/

/* MSF types/definition not yet implemented */
#ifndef MSF_EOS
    #define MSF_EOS '\0'
#endif /* MSF_EOS */

typedef void* MmsTransactionHandle;
typedef void* MmsMsgHandle;


/*MMS templates dynamic generate string resource based on current language*/
#ifdef MMS_SUPPORT
#define MMS_TMPLATES_MULTIPLE_LANG_SUPPORT
#endif

/*! \enum MmsVersion MMS Standard that the MMS Client understand. 
 *  Is defined as <Major version>.<Minor version>. 
 *  The major version is coded in 3 high/most significant bits and the minor 
 *  version in the 4 lower/least significant bits. Example: 0x10 = X001.0000 = 1.0
 *  and 0x12 = X001.0010 = 1.2.
 */
typedef enum
{
    MMS_VERSION_PREVIOUS_MAJOR  = 0x0F,
    MMS_VERSION_10              = 0x10,
    MMS_VERSION_11              = 0x11,
    MMS_VERSION_12              = 0x12,
    MMS_VERSION_NEXT_MAJOR      = 0x20
} MmsVersion; 

/*! Content type of MMS messages as seen by the WSP/HTTP layer. */
#define MMS_CONTENT             "application/vnd.wap.mms-message"

/*! WINA assigned string for MMS registered PUSH Application ID. */
#define MMS_PUSH_APPLICATION_ID "x-wap-application:mms.ua" 

/*! WINA assigned number for MMS registered PUSH Application ID. */
#define MMS_PUSH_APPLICATION_NO "4" 

/*! Denotes all message ID and is used in operations on all messages at the 
 *  same time. */
#define MMS_ALL_MESSAGES    0

/*! Define for the SMIL media type as a string that can be used in 
 * content type. 
 */
#define MMS_MEDIA_TYPE_STRING_SMIL "application/smil"

/*! Define for the AMR (sound) media type as a string 
 *  that can be used in content type. 
 */
#define MMS_MEDIA_TYPE_STRING_AMR  "audio/AMR"

/*! Content type for forward locked message according to Ericcson. */
//#define MMS_MEDIA_TYPE_STRING_FORWARD_LOCKED  "application/vnd.vzw.mms.protected"
#define MMS_MEDIA_TYPE_STRING_FORWARD_LOCKED  "application/vnd.oma.drm.message"

/*! Content type for forward locked message according to OMA. */
#define MMS_MEDIA_TYPE_STRING_FORWARD_LOCKED_OMA "application/vnd.oma.drm.message"


 /*--- Types ---*/
/*! MmsMsgId A unique message identity for a message in the MMS Client. This 
 *  identity is used for all operations on a message. */
typedef MSF_UINT32 MmsMsgId;

typedef enum
{
    MMS_SIM_CARD_SIM1 = 1,
    MMS_SIM_CARD_SIM2,
    MMS_SIM_CARD_SIM3,
    MMS_SIM_CARD_SIM4
} MmsSimCardEnum;

/*! \enum MmsReadStatus Indicates if the recepient has read the MM or deleted 
 *  it without reading it.
 */
typedef enum
{
    MMS_READ_STATUS_READ                            = 128,
    MMS_READ_STATUS_DELETED_WITHOUT_BEING_READ      = 129
} MmsReadStatus;

/*! \enum MmsAddressType This definition contains all types that an address
 *  in the MMS Client can have. */
typedef enum
{
    MMS_PLMN,       /*!< PLMN type of address, e.g. +467055566622 */
    MMS_EMAIL,      /*!< E-Mail type of address, e.g. foo@bar.com */
    MMS_IPV4,       /*!< IPv4 type of address, e.g. 123.456.789.123 */
    MMS_UNSUPPORTED /*!< Unknown address type, Not to be sent */
} MmsAddressType;

/*! \emum MmsMsgType This definition is used in the MmsGetHeader struct
 *   to tell if the message was an Send Request or Retrieve.confirm 
 *   messge
 */
typedef enum 
{
    MMS_MSG_TYPE_SEND_REQ = 128,      /*!< Send request message */
    MMS_MSG_TYPE_RETRIEVE_CONF = 132  /*!< Retrieve confirm */
}MmsMsgType;

/*! \enum MmsCharset Supported character sets within the MMS Client. */
typedef enum
{
    MMS_US_ASCII    = 3,   
    MMS_UTF8        = 106,
    MMS_UCS2        = 1000,
    MMS_UTF16BE     = 1013, 
    MMS_UTF16LE     = 1014, 
    /*< UTF-16 is to be used only if the document starts with a UTF-16 BOM  */
    MMS_UTF16       = 1015, 
    MMS_ISO_8859_1  = 4,
    MMS_UNKNOWN_CHARSET = 0,
    MMS_AUTO_RR =9999  /* Only used for Read report 1.0 choses to use ASCII if only ASCII chars and UTF8 in all other cases.*/
} MmsCharset;

/*! \struct MmsEncodedText 
 *  \brief Contains an encoded text and its charset. Different
 *         fields in an MMS header can have this type. 
 */
typedef struct
{
    MmsCharset  charset;    /*!< Well-known character set as defined by IANA */
    char        *text;      /*!< Text buffer, must be NULL terminated */
} MmsEncodedText;

/*! \enum MmsFolderType MMS Messages are stored in different folders. This enum 
 *  contains the different types of folders available.
 */
typedef enum
{
    MMS_NO_FOLDER = 0x00,     /*!< Folder not assiged, only for internal usage. */
    MMS_INBOX  = 0x01,        /*!< Incoming messages */
    MMS_OUTBOX = 0x02,        /*!< Outgoing messages */
    MMS_SENT   = 0x04,        /*!< Successfully sent messages */
    MMS_DRAFTS = 0x08,        /*!< Messages during work */
    MMS_NOTIFY = 0x10,        /*!< Notifications */
    MMS_HIDDEN = 0x20,        /*!< Hidden notifications (immediate) */
    MMS_TEMPLATES = 0x40,     /*!< Template folder */
    MMS_USER_DEFINED_FOLDER_OFFSET = 0x80, /*!< The offset for user defined folders  */
    MMS_ARCHIVE = MMS_USER_DEFINED_FOLDER_OFFSET, /*!< Archive messages*/
    MMS_USRDEF_TEMPLATES = 0x100,
    MMS_ALL_FOLDERS = 0xFFFF  /*!< Use this value to make a request to all folders */
} MmsFolderType;

/*! \enum MmsFileTypes Types of files that is used in the Folder Manager */
typedef enum
{
    MMS_SUFFIX_TEMPLATE         = 't',  /*!< Send request template */
    MMS_SUFFIX_IMMEDIATE        = 'q',  /*!< notification file during immediate retrieval */
    MMS_SUFFIX_INFO             = 'i',  /*!< Infofile */ 
    MMS_SUFFIX_SEND_REQ         = 's',  /*!< send request message */
    MMS_SUFFIX_MSG              = 'm',  /*!< message file */ 
    MMS_SUFFIX_NOTIFICATION     = 'n',  /*!< notification file */  
    MMS_SUFFIX_READREPORT       = 'r',  /*!< read report */ 
    MMS_SUFFIX_DELIVERYREPORT   = 'd',  /*!< delivery report */
    MMS_SUFFIX_ERROR            = 'x'   /*!< error, not a suffix! */
} MmsFileType;

#ifdef MMS_UIS_IN_USE

typedef struct 
{
    const char               *strFolderId;
    int                       folderType;
} MmsStrFolderId;

/* internal folder name translation table (from MMS folder to UIA folder STR */
#define MMS_STR_FOLDERS { \
    { UIS_MSG_KEY_VALUE_FOLDER_INBOX, MMS_INBOX }, \
    { UIS_MSG_KEY_VALUE_FOLDER_INBOX, MMS_NOTIFY }, \
    { UIS_MSG_KEY_VALUE_FOLDER_DRAFTS, MMS_DRAFTS }, \
    { UIS_MSG_KEY_VALUE_FOLDER_SENT, MMS_SENT }, \
    { UIS_MSG_KEY_VALUE_FOLDER_OUTBOX, MMS_OUTBOX }, \
    { UIS_MSG_KEY_VALUE_FOLDER_TEMPLATES, MMS_TEMPLATES }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_0, MMS_USER_DEFINED_FOLDER_OFFSET }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_1, MMS_USER_DEFINED_FOLDER_OFFSET*2 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_2, MMS_USER_DEFINED_FOLDER_OFFSET*4 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_3, MMS_USER_DEFINED_FOLDER_OFFSET*8 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_4, MMS_USER_DEFINED_FOLDER_OFFSET*16 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_5, MMS_USER_DEFINED_FOLDER_OFFSET*32 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_6, MMS_USER_DEFINED_FOLDER_OFFSET*64 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_7, MMS_USER_DEFINED_FOLDER_OFFSET*128 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_8, MMS_USER_DEFINED_FOLDER_OFFSET*256 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_9, MMS_USER_DEFINED_FOLDER_OFFSET*512 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_10, MMS_USER_DEFINED_FOLDER_OFFSET*1024 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_11, MMS_USER_DEFINED_FOLDER_OFFSET*2048 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_12, MMS_USER_DEFINED_FOLDER_OFFSET*4096 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_13, MMS_USER_DEFINED_FOLDER_OFFSET*8192 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_14, MMS_USER_DEFINED_FOLDER_OFFSET*16384 }, \
    { UIS_MSG_KEY_VALUE_FOLDER_USER_DEF_15, MMS_USER_DEFINED_FOLDER_OFFSET*32768 }, \
    { NULL, 0 }} /* Termination of table */


#endif /* MMS_UIS_IN_USE */

/*! \enum MmsFromType The "From Address" can either be supplied by the 
 *  MMS Application or the MMS Proxy-Relay can be asked to insert it. 
 *  MmsFromType lists the different values that can be used.
 */
typedef enum
{
    MMS_FROM_ADDRESS_PRESENT = 128, /*!< The address is added by the client */
    MMS_FROM_INSERT_ADDRESS  = 129  /*!< The address is added by the server */
} MmsFromType;

/*! \struct MmsAddress 
 *  \brief An MMS address corresponds to the fields in this struct. 
 */
typedef struct
{
    MmsEncodedText name;        /*!< Display name (e.g. Bill Löfgren, AU-System) */
    char *address;              /*!< Address (e.g. bill.lofgren@ausystem.se) */
    MmsAddressType addrType;    /*!< Address Type (PLMN or EMAIL) */
} MmsAddress;

/*! \struct MmsAddressList
 *  \brief When more than one address is supplied for a field, e.g. several
 *         recipients in "To" field, the MmsAddressList contains all addresses. 
 */
typedef struct MmsAddressListStruct 
{
    /*! Address for current element */
    MmsAddress current;                 
    
    /*! Next address list element or NULL if last element */
    struct MmsAddressListStruct *next;  
} MmsAddressList;

/*! \enum MmsClassIdentifier An MMS message can have different message classes.
 *  Auto indicates a message that is automatically generated by the client. 
 *  When Message Class is AUTO, no Delivery-Report or Read-Reply should be 
 *  sent. When creating an MMS, the Message Class AUTO is not possible to set 
 *  from the MMS Application since this Message Class is reserved for 
 *  automatically generated messages in the Proxy-Relay or the MMS Client 
 *  (below the MMS Application level). The message class IS_TEXT is used when 
 *  message class is set as a text string value, for more information see: 
 *  #MmsMessageClass. 
 */
typedef enum
{
    MMS_MESSAGE_CLASS_NOT_SET       =   0,
    MMS_MESSAGE_CLASS_PERSONAL      = 128,
    MMS_MESSAGE_CLASS_ADVERTISEMENT = 129,
    MMS_MESSAGE_CLASS_INFORMATIONAL = 130,
    MMS_MESSAGE_CLASS_AUTO          = 131,
    MMS_MESSAGE_CLASS_IS_TEXT       = 254
} MmsClassIdentifier;

/*! \struct MmsMessageClass 
 *  \brief Contains the Class of the message. 
 *  Class can be an MmsClassIdentifier or a string. If string is used the 
 *  MmsClassIdentifier must be set to MMS_MESSAGE_CLASS_IS_TEXT. 
 *  If no Class is set the message is treated as Personal.
 */
typedef struct
{
    MmsClassIdentifier  classIdentifier;    /*!< Enum representation of a message class */
    char                *textString;        /*!< Textual representation of a message class */
} MmsMessageClass;

/*! \enum MmsPriority An MMS message can have different priorities. This enum 
 *  lists the possible values.
 */
typedef enum
{
    MMS_PRIORITY_NOT_SET    =   0,
    MMS_PRIORITY_LOW        = 128,
    MMS_PRIORITY_NORMAL     = 129,
    MMS_PRIORITY_HIGH       = 130
} MmsPriority;

/*! \enum MmsSenderVisibility The sender address in an MMS message can be shown
 *  or not for the recipient. Possible values are listen in this enum. 
 */
typedef enum
{
    MMS_SENDER_VISIBILITY_NOT_SET   =   0,  /*!< Show unless sender has secret address*/
    MMS_SENDER_HIDE                 = 128,  /*!< Don't show the address. */
    MMS_SENDER_SHOW                 = 129   /*!< Show even secret address. */
} MmsSenderVisibility;

/*! \enum MmsDeliveryReport Sending of a Delivery Report to the original 
 *  message sender can either be requested or not. This field is called 
 *  "Report-Allowed" in the MMS standard.
 */
typedef enum
{
    MMS_DELIVERY_REPORT_NOT_SET =   0,
    MMS_DELIVERY_REPORT_YES     = 128,  /*!< Delivery report is requested. */
    MMS_DELIVERY_REPORT_NO      = 129   /*!< Delivery report is not requested. */
} MmsDeliveryReport;

/*! \enum MmsReadReply This enum contains values possible for to set for the
 *  Read Reply request.
 */
typedef enum
{
    MMS_READ_REPLY_NOT_SET  =   0,
    MMS_READ_REPLY_YES      = 128,      /*!< Read reply is requested. */
    MMS_READ_REPLY_NO       = 129       /*!< Read reply is not requested. */
} MmsReadReply;

/*! \enum MmsStatus The status of an MMS message can be any of the following 
 *  values. 
 */
typedef enum
{
    MMS_STATUS_EXPIRED          = 128,
    MMS_STATUS_RETRIEVED        = 129,
    MMS_STATUS_REJECTED         = 130,
    MMS_STATUS_DEFERRED         = 131,
    MMS_STATUS_UNRECOGNIZED     = 132,
    MMS_STATUS_INDETERMINATE    = 133,
    MMS_STATUS_FORWARDED        = 134
} MmsStatus;

/*! \enum MmsTimeType The type of time used in fields like expiry time and
 *  delivery time.
 */
typedef enum
{
    MMS_TIME_ABSOLUTE           = 128,
    MMS_TIME_RELATIVE           = 129
} MmsTimeType;

typedef MSF_UINT32 MmsTimeSec;      /*!< Time in sec from 1970-01-01 */ 
typedef MSF_UINT32 MmsReplyChargingSize; /*!< Size allowed for a reply charging*/

/*! \enum MmsReplyCharging Indicates that the originator is willing to pay for 
 *  the Reply-MM (requested) or that a reply to this MM is free of charge for 
 *  the recepient (accepted).
 */
typedef enum
{
    MMS_REPLY_CHARGING_NOT_SET              =   0,  /*!< Reply Charging is not used */

    /* Used only in M_Send.req */
    MMS_REPLY_CHARGING_REQUESTED            = 128,  /*!< Used when sending a message */
    MMS_REPLY_CHARGING_REQUESTED_TEXT_ONLY  = 129,  /*!< Used when sending a message */

    /* Used only in M_Retrieve.conf and M_Notification.ind */
    MMS_REPLY_CHARGING_ACCEPTED             = 130,  /*!< Used when retrieving a message or notification */
    MMS_REPLY_CHARGING_ACCEPTED_TEXT_ONLY   = 131   /*!< Used when retrieving a message or notification */
} MmsReplyCharging;

/*! \struct MmsPrevSentBy Addresses of clients that previously has sent a  message*/ 
typedef struct MmsPrevSentByStruct
{
    MSF_UINT32  forwardedCountValue;
    MmsAddress  sentBy;
    struct MmsPrevSentByStruct *next;
} MmsPrevSentBy;

/*! \struct MmsPrevSentDate date when a clients previously has sent a  message*/ 
typedef struct MmsPrevSentDateStruct
{
    MSF_UINT32  forwardedCountValue;
    MmsTimeSec  date;
    struct MmsPrevSentDateStruct *next;
} MmsPrevSentDate;

/*! \enum MmsEntryHeaderValueType All valid entry header types. 
 *  This is a part of the message bodys different entries. */
typedef enum
{
    MMS_SHORT_CUT_SHIFT_DELIMITER,          /*!< Value is in shortCutShiftDelimiter */
    MMS_APPLICATION_HEADER,                 /*!< Type and value is in applicationHeader */
#ifdef MTK_TMP_PATCH /* TR32806 */
    MMS_WELL_KNOWN_ACCEPT_CHARSET   = 0x01,
#endif
    MMS_WELL_KNOWN_CONTENT_AGE      = 0x05,
    MMS_WELL_KNOWN_CONTENT_BASE     = 0x0A, /*!< Value is in wellKnownFieldName */
    MMS_WELL_KNOWN_CONTENT_ENCODING = 0x0B, /*!< Value is in wellKnownFieldName */
    MMS_WELL_KNOWN_CONTENT_LANGUAGE = 0x0C, /*!< Value is in wellKnownFieldName */
    MMS_WELL_KNOWN_CONTENT_LENGTH   = 0x0D, /*!< Value is in wellKnownFieldName */
    MMS_WELL_KNOWN_CONTENT_LOCATION = 0x0E, /*!< Value is in wellKnownFieldName */
    MMS_WELL_KNOWN_CONTENT_MD5      = 0x0F, /*!< Value is in wellKnownFieldName */
    MMS_WELL_KNOWN_CONTENT_RANGE    = 0x10, /*!< Value is in wellKnownFieldName */
    MMS_WELL_KNOWN_CONTENT_TYPE     = 0x11, /*!< Value is in wellKnownFieldName */
    MMS_WELL_KNOWN_CONTENT_DISPOSITION = 0x2E, /*!< Value is in wellKnownFieldName */
    MMS_WELL_KNOWN_CONTENT_ID       = 0x40, /*!< Value is in wellKnownFieldName */ 
    MMS_WELL_KNOWN_X_WAP_CONTENT_URI = 0x30,/*!< Value is in wellKnownFieldName */ 
    MMS_WELL_KNOWN_DATE             = 0x12, /*!< Value is in wellKnownFieldName */ 
    MMS_SHIFT_DELIMITER             = 0x7f  /*!< Value is in shiftDelimiter */
} MmsEntryHeaderValueType;

/*! \struct MmsEntryHeaderData 
 *  \brief  Contains one entry header type and its value.
 *          This is a part of the message bodys different entries. 
 */
typedef struct
{
    unsigned char *name;     /*!< Well-known-field-name or a char.*/
    unsigned char *value;   /*!< Null terminated text string.*/
} MmsEntryHeaderData;

/*! \struct MmsEntryHeader 
 *  \brief The types and values of the MMS message bodys  entry header. 
 */
typedef struct MmsAllEntryHeaders
{
    /*! Info about which union type to use.*/
    MmsEntryHeaderValueType headerType; 

    union
    {
        /*! Value of a shift delimiter.*/
        unsigned char shiftDelimiter;   
        
        /*! Type of short cut shift delimiter.*/
        unsigned char shortCutShiftDelimiter; 
        
        /*! Value of a well known field name.*/
        unsigned char *wellKnownFieldName; 
        
        /*! Type and value of an application header.*/
        MmsEntryHeaderData applicationHeader;
    } value;

    /*! Next entry header for a body part, NULL if there is no more headers. */
    struct MmsAllEntryHeaders *next;
} MmsEntryHeader;

/*! \enum MmsKnownMediaType Contains the media-type values that the MMS Client supports.
 */
typedef enum
{
    /* Unknown */
    MMS_TYPE_ANY_ANY                            = 0x00,     

    /* Text */
    MMS_TYPE_TEXT_ANY                           = 0x01, 
    MMS_TYPE_TEXT_HTML                          = 0x02, 
    MMS_TYPE_TEXT_PLAIN                         = 0x03,
    MMS_TYPE_TEXT_X_HDML                        = 0x04,
    MMS_TYPE_TEXT_X_TTML                        = 0x05,
    MMS_TYPE_TEXT_X_VCALENDAR                   = 0x06,
    MMS_TYPE_TEXT_X_VCARD                       = 0x07,
    MMS_TYPE_TEXT_VND_WAP_WML                   = 0x08,
    MMS_TYPE_TEXT_VND_WAP_WMLSCRIPT             = 0x09,
    MMS_TYPE_TEXT_VND_WAP_CHANNEL               = 0x0A,

    /* Multipart */
    MMS_TYPE_MULTIPART_ANY                      = 0x0B,
    MMS_TYPE_MULTIPART_MIXED                    = 0x0C,
    MMS_TYPE_MULTIPART_FORM_DATA                = 0x0D,
    MMS_TYPE_MULTIPART_BYTERANGES               = 0x0E,
    MMS_TYPE_MULTIPART_ALTERNATIVE              = 0x0F,

    /* Application */
    MMS_TYPE_APP_ANY                            = 0x10,
    MMS_TYPE_APP_JAVA_VM                        = 0x11,
    MMS_TYPE_APP_X_WWW_FORM_URLENCODED          = 0x12,
    MMS_TYPE_APP_X_HDMLC                        = 0x13,
    MMS_TYPE_APP_VND_WAP_WMLC                   = 0x14,
    MMS_TYPE_APP_VND_WAP_WMLSCRIPTC             = 0x15,
    MMS_TYPE_APP_VND_WAP_CHANNELC               = 0x16,
    MMS_TYPE_APP_VND_WAP_UAPROF                 = 0x17,
    MMS_TYPE_APP_VND_WAP_WTLS_CA_CERTIFICATE    = 0x18,
    MMS_TYPE_APP_VND_WAP_WTLS_USER_CERTIFICATE  = 0x19,
    MMS_TYPE_APP_X_X509_CA_CERT                 = 0x1A,
    MMS_TYPE_APP_X_X509_USER_CERT               = 0x1B,

    /* Image */
    MMS_TYPE_IMAGE_ANY                          = 0x1C, 
    MMS_TYPE_IMAGE_GIF                          = 0x1D, 
    MMS_TYPE_IMAGE_JPEG                         = 0x1E,
    MMS_TYPE_IMAGE_TIFF                         = 0x1F, 
    MMS_TYPE_IMAGE_PNG                          = 0x20, 
    MMS_TYPE_IMAGE_VND_WAP_WBMP                 = 0x21,

    /* Application */
    MMS_VND_WAP_MULTIPART_ANY                   = 0x22, 
    MMS_VND_WAP_MULTIPART_MIXED                 = 0x23,
    MMS_TYPE_APP_VND_WAP_MPART_FORM_DATA        = 0x24,
    MMS_TYPE_APP_VND_WAP_MPART_BYTERANGES       = 0x25, 
    MMS_VND_WAP_MULTIPART_ALTERNATIVE           = 0x26, 
    MMS_TYPE_APP_XML                            = 0x27,

    /* Text */
    MMS_TYPE_TEXT_XML                           = 0x28,

    /* Application */
    MMS_TYPE_APP_VND_WAP_WBXML                  = 0x29,
    MMS_TYPE_APP_X_X968_CROSS_CERT              = 0x2A,
    MMS_TYPE_APP_X_X968_CA_CERT                 = 0x2B,
    MMS_TYPE_APP_X_X968_USER_CERT               = 0x2C,

    /* Text */
    MMS_TYPE_TEXT_VND_WAP_SI                    = 0x2D,

    /* Application */
    MMS_TYPE_APP_VND_WAP_SIC                    = 0x2E,

    /* Text */
    MMS_TYPE_TEXT_VND_WAP_SL                    = 0x2F,

    /* Application */
    MMS_TYPE_APP_VND_WAP_SLC                    = 0x30,

    /* Text */
    MMS_TYPE_TEXT_VND_WAP_CO                    = 0x31,

    /* Application */
    MMS_TYPE_APP_VND_WAP_COC                    = 0x32,
    MMS_VND_WAP_MULTIPART_RELATED               = 0x33, 
    MMS_TYPE_APP_VND_WAP_SIA                    = 0x34,

    /* Text */
    MMS_TYPE_TEXT_VND_WAP_CONNECTIVITY_XML      = 0x35,

    /* Application */
    MMS_TYPE_APP_VND_WAP_CONNECTIVITY_WBXML     = 0x36,
        
    /* DRM related media types */
    MMS_TYPE_APP_VND_OMA_DRM_MESSAGE            = 0x48,
    MMS_TYPE_APP_VND_OMA_DRM_CONTENT            = 0x49,
    MMS_TYPE_APP_VND_OMA_DRM_R_XML              = 0x4A,
    MMS_TYPE_APP_VND_OMA_DRM_R_WBXML            = 0x4B,

    /* Not a well known value */
    MMS_VALUE_AS_STRING                         = 0xFF 
    
} MmsKnownMediaType;


typedef enum
{
    MESSAGE_HEADERS,
    BODY_HEADERS,
    BOTH_HEADERS
} MmsHeaderType;


/*! \enum MmsParam Contains possible parameter values for the content-type 
 *  header field. [WAP-203, Table 38]
 */
typedef enum
{
    MMS_CHARSET         = 0x01, /*!< Well-known-charset */
    MMS_LEVEL           = 0x02, /*!< Version-value */
    MMS_TYPE            = 0x03, /*!< Integer-value */
    MMS_TYPE_REL        = 0x09, /*!< Text-Value, used with multipart related*/
    MMS_NAME            = 0x05, /*!< Text-Value deprecated from encoding version 14*/
    MMS_FILENAME        = 0x06, /*!< Text-Value deprecated new from encoding version 14*/
    MMS_START_REL       = 0x0A, /*!< Text-Value, used with multipart related */
    MMS_START_INFO_REL  = 0x0B, /*!< Text-Value, used with multipart related */
    MMS_NAME_14         = 0x17, /*!< Text-Value new from encoding version 14*/
    MMS_FILENAME_14     = 0x18, /*!< Text-Value new from encoding version 14*/
    MMS_START_REL_14       = 0x19, /*!< Text-Value, used with multipart related new from version 14*/
    MMS_START_INFO_REL_14  = 0x1A,  /*!< Text-Value, used with multipart related new from version 14*/
    MMS_TEXT_KEY        = 0xFE, /*!< Text-Value, untyped text key-value */
    MMS_UNHANDLED       = 0xFF  /*!< All parameters not handled by the MMS Client */
} MmsParam;

typedef struct
{
    unsigned char *strKey; /* Key value definition */
    MmsParam       assignedValue;
} MmsParamTextKey;

/*! \enum MmsParamType Describes how the content type parameter is 
 *  represented. e.g. as a string or as an integer value.
 */
typedef enum
{
    MMS_PARAM_STRING,
    MMS_PARAM_INTEGER 
} MmsParamType;

/*! \struct MmsAllParams 
 *  \brief Contains a list of all content-type parameters of a message.
 */
typedef struct MmsAllParamsStruct
{
    MmsParam        param;  /*!< MmsParam enum */
    
    /*! Param value type. MMS_PARAM_STRING = String, MMS_PARAM_INTEGER = int */
    MmsParamType    type;  
    
    unsigned char   *key;   /*!< Parameter text key, Token-text See WAP-203-WSP 8.4.2.1 */
    
    union
    {
        unsigned char   *string;    /*! The value is a RFC2616 encoded string or NULL */
        MSF_UINT32      integer;    /*! The value is a number */
    } value;
    /*! Pointer to next param. NULL if no more params  */
    struct MmsAllParamsStruct *next;    
} MmsAllParams;

/*! \struct MmsContentType 
 *  \brief Contains the content-type value and belonging parameters.
 *         If there are no parameters "params" must be set to NULL!
 */
typedef struct
{
    /*! The media type is a known value */
    MmsKnownMediaType   knownValue; 
    /*! The media type is a us-ascii string */
    unsigned char   *strValue;      
    /*! Pointer to the content type params, NULL if there is no parameters */
    MmsAllParams    *params;    
} MmsContentType;

/*! \struct MmsBodyInfoList 
 *  \brief A List with information about the parts of a body.
 */
typedef struct MmsBodyInfoStruct
{
    MmsContentType  *contentType;   /*!< The content type information. */
    MmsEntryHeader  *entryHeader;   /*!< The entry header information. */
    MSF_UINT32      number;         /*!< Which part in the body. */
    MSF_UINT32      startPos;       /*!< Start position for the body part (data). */
    MSF_UINT32      size;           /*!< Total size of the body part (data). */
    
    /*! Number of sub parts for the current multipart. 0 if not a multipart */
    MSF_UINT32      numOfEntries;   
     
    /*! Pointer to the next body info element in the list, NULL if last */
    struct MmsBodyInfoStruct *next;    
} MmsBodyInfoList;

/*! \struct MmsSetHeader 
 *  \brief A struct containing possible header fields. 
 *  All optional field must be set to 0 or NULL when not used.
 *
 *  Creation of MMS Message :
 *          Optional fields are marked with [O]
 *          and mandatory fields marked with [M] (i.e. must be set)
 */
typedef struct
{                            
    /*! [M] The address of the message sender. */ 
    MmsAddress from;                    

    /*! [O] The addressee of the message. The address field can contain one or
     *      several addresses. The parameter is a reference to a list 
     *      containing the recipient addresses. One element in the list carries 
     *      the address (PLMN or e-mail) and the text string representing the 
     *      recipient real name (e.g. Joe User) to be used in multimedia 
     *      messages. Please note that PLMN addresses cannot make use of real 
     *      names. A message needs always at least one specified address in one
     *      of the to, cc or bcc field.    
     */ 
    
    /*! [M] The insert method of the from address. */ 
    MmsFromType fromType;   

    MmsAddressList *to;                 

    /*! [O] See To field. */    
    MmsAddressList *cc;                 

    /*! [O] See To field. */ 
    MmsAddressList *bcc;                

    /*! [O] The text string containing the subject of the message. See also 
     *      configuration setting for the maximum length of this field in 
     *      mms_cfg.h.
     */
    MmsEncodedText subject;             

    /*! [O] Arrival time (in seconds since 1970-01-01) of the message at the 
     *      MMS Proxy-Relay. The MMS Proxy-Relay will generate this field if 
     *      not supplied.
     */
    MmsTimeSec date;                    

    /*! [M] The Content-Type contains a media type and a number of parameters. 
     *      Examples of media-types are: text/plain, image/jpg, 
     *      multipart/related etc. Examples of parameters are: start, type, 
     *      filename. The MMS Application must always set this field.
     */ 
    MmsContentType *contentType;        

    /*! [O] The message class field labels the message type as Auto, 
     *      Informational or Advertisement. When the message class is not set 
     *      the class will be interpreted as Personal at the recipient. It is 
     *      recommended not to set this field in normal MMS Applications. 
     */ 
    MmsMessageClass msgClass;           

    
    /*! [O] The type of expiry time, absolute or relative. Absolute means that
     *      an absolute time (in seconds since 1970-01-01) is given. Relative
     *      means that the server will add the given number of seconds to
     *      current time.
     */
    MmsTimeType expiryTimeType;
    
    /*! [O] Defines the time when the message will be removed from the 
     *      recipient's MMS Proxy-Relay. If not set the maximum time will be 
     *      used. The maximum value is dependent on the MMS Proxy-Relay. 
     */
    MmsTimeSec expiryTime;              

    
  /*! [O] The type of expiry time, absolute or relative. Absolute means that
     *      an absolute time (in seconds since 1970-01-01) is given. Relative
     *      means that the server will add the given number of seconds to
     *      current time.
     */
    MmsTimeType deliveryTimeType;


    /*! [O] This time value indicates for the MMS Proxy-Relay when the message 
     *      should be delivered to the recipient(s) at a later time. When this 
     *      field is not set the message is delivered immediately.
     */
    MmsTimeSec deliveryTime;            

    /*! [O] This value defines the message priority. */ 
    MmsPriority priority;               

    /*! [O] This value is used to control if the "From" address is displayed 
     *      in the message at the recipient's MMS Application.
     */ 
    MmsSenderVisibility visibility;     

    /*! [O] This field is requesting the retrieving MMS Applications to send a 
     *      read reply message when the message was read. Note; a retrieving 
     *      MMS Application may cancel the request. A read reply message sent
     *      is seen as an ordinary message and the MMS Application controls 
     *      the contents.
     */ 
    MmsReadReply readReply;             

    /*! [O] The setting of this flag will cause the MMS Proxy-Relay to send 
     *      back a notification message when the recipient retrieves the 
     *      message. A retrieving MMS Application may prevent a Delivery 
     *      Report from being sent.
     */ 
    MmsDeliveryReport deliveryReport; 

    /*! [O] Allow reply charging. 
     *      This field can only be used with MMS standard version 1.1 and 
     *      greater.
     */ 
    MmsReplyCharging replyCharging;

    
    
    
     /*! [O] The type of replyChargingDeadline time, absolute or relative. Absolute means that
     *      an absolute time (in seconds since 1970-01-01) is given. Relative
     *      means that the server will add the given number of seconds to
     *      current time.
     */
    MmsTimeType replyChargingDeadlineType;
    
    
    /*! [O] Deadline for reply charging. 
     *      This field can only be used with MMS standard version 1.1 and 
     *      greater.
     */
   
       
 
    
    
    MmsTimeSec replyChargingDeadline;

    /*! [O] Deadline for reply charging. 
     *      This field can only be used with MMS standard version 1.1 and 
     *      greater.
     */
    char *replyChargingId;

    /*! [O] Allowed size for a reply charging. 
     *      This field can only be used with MMS standard version 1.1 and 
     *      greater.
     */
    MmsReplyChargingSize replyChargingSize;
} MmsSetHeader;

/*! \struct MmsGetHeader 
 *  \brief A struct containing possible header fields. 
 *  All fields are set to 0 or NULL when not used.
 *
 */
typedef struct
{                            
#ifdef MTK_TMP_PATCH /* CR:28786*/
    MmsVersion version;
#endif
    /*! [M] The address of the message sender. */ 
    MmsAddress from;                    

    /*! [O] The addressee of the message. The address field can contain one or
     *      several addresses. The parameter is a reference to a list 
     *      containing the recipient addresses. One element in the list carries 
     *      the address (PLMN or e-mail) and the text string representing the 
     *      recipient real name (e.g. Joe User) to be used in multimedia 
     *      messages. Please note that PLMN addresses cannot make use of real 
     *      names. A message needs always at least one specified address in one
     *      of the to, cc or bcc field.    
     */ 
    MmsAddressList *to;                 

    /*! [O] See To field. */    
    MmsAddressList *cc;                 

    /*! [O] See To field. */ 
    MmsAddressList *bcc;                

    /*! [O] The text string containing the subject of the message. See also 
     *      configuration setting for the maximum length of this field in 
     *      mms_cfg.h.
     */
    MmsEncodedText subject;             

    /*! [O] Arrival time (in seconds since 1970-01-01) of the message at the 
     *      MMS Proxy-Relay. The MMS Proxy-Relay will generate this field if 
     *      not supplied.
     */
    MmsTimeSec date;                    

    /*! [O] The message class field labels the message type as Auto, 
     *      Informational or Advertisement. When the message class is not set 
     *      the class will be interpreted as Personal at the recipient. It is 
     *      recommended not to set this field in normal MMS Applications. 
     */ 
    MmsMessageClass msgClass;           

        
    /*! [O] The type of expiry time, absolute or relative. Absolute means that
     *      an absolute time (in seconds since 1970-01-01) is given. Relative
     *      means that the server will add the given number of seconds to
     *      current time.
     */
    MmsTimeType expiryTimeType;

    /*! [O] Defines the time when the message will be removed from the 
     *      recipient's MMS Proxy-Relay. If not set the maximum time will be 
     *      used. The maximum value is dependent on the MMS Proxy-Relay. 
     */
    MmsTimeSec expiryTime;              

#ifdef MTK_TMP_PATCH  /* TR 29894 */
    /*! [O] The type of delivery time, absolute or relative. Absolute means that
     *      an absolute time (in seconds since 1970-01-01) is given. Relative
     *      means that the server will add the given number of seconds to
     *      current time.
     */
    MmsTimeType deliveryTimeType;
#endif

    /*! [O] This time value indicates for the MMS Proxy-Relay when the message 
     *      should be delivered to the recipient(s) at a later time. When this 
     *      field is not set the message is delivered immediately.
     */
    MmsTimeSec deliveryTime;            

    /*! [O] This value defines the message priority. */ 
    MmsPriority priority;               

    /*! [O] This value is used to control if the "From" address is displayed 
     *      in the message at the recipient's MMS Application.
     */ 
    MmsSenderVisibility visibility;     

    /*! [O] This field is requesting the retrieving MMS Applications to send a 
     *      read reply message when the message was read. Note; a retrieving 
     *      MMS Application may cancel the request. A read reply message sent
     *      is seen as an ordinary message and the MMS Application controls 
     *      the contents.
     */ 
    MmsReadReply readReply;             

    /*! [O] The setting of this flag will cause the MMS Proxy-Relay to send 
     *      back a notification message when the recipient retrieves the 
     *      message. A retrieving MMS Application may prevent a Delivery 
     *      Report from being sent.
     */ 
    MmsDeliveryReport deliveryReport; 
    
    /*! [M] Id of the message.
     *      This field is only used when retrieving a message, NOT used when 
     *      sending.
     */
    char *serverMessageId;

    /*! [O] Allow reply charging. 
     *      This field can only be used with MMS standard version 1.1 and 
     *      greater.
     */ 
    MmsReplyCharging replyCharging;

    /*! [O] Deadline for reply charging. 
     *      This field can only be used with MMS standard version 1.1 and 
     *      greater.
     */
    MmsTimeSec replyChargingDeadline;

    /*! [O] Deadline for reply charging. 
     *      This field can only be used with MMS standard version 1.1 and 
     *      greater.
     */
    char *replyChargingId;

    /*! [O] Allowed size for a reply charging. 
     *      This field can only be used with MMS standard version 1.1 and 
     *      greater.
     */
    MmsReplyChargingSize replyChargingSize;
    
    /*! [O] Address information about which clients that previously has 
     *      sent a message. 
     *      This field can only be used with MMS standard version 1.1 and 
     *      greater and it is only used when retrieving a message, NOT 
     *      used when sending.
     */
    MmsPrevSentBy *previouslySentBy;

    /*! [O] Date information about when clients has previously sent a message. 
     *      This field can only be used with MMS standard version 1.1 and 
     *      greater and it is only used when retrieving a message, NOT used 
     *      when sending.
     */
    MmsPrevSentDate *previouslySentDate;
      
    /*! [M] Defines the type of the messge, Send Request or Retrieve Confrim */ 
    MmsMsgType messageType; 

    /*! [M] Is message forward locked (DRM)
     */
    MSF_BOOL forwardLock;

    MmsBodyInfoList bodyInfoList;
} MmsGetHeader;

/*! \struct MmsNotification  
 *  \brief This structure represents the header values received in an 
 *         M-Notification.ind message. Further, this struct is 
 *         used for reading a notification message.
 */
typedef struct 
{
    /*! The sender address. */
    MmsAddress from;         

    /*! The subject of the MMS message */
    MmsEncodedText subject;  

    /*! Class of the message. */
    MmsMessageClass msgClass;

    /*! The length of the message to fetch. */
    MSF_UINT32 length;           

    /*! Time when the message is removed from the MMS Proxy-Relay. 
     * No expiry time type is needed since the value is always relative 
     */
    MmsTimeSec expiryTime;   

    /*! [O] Allow reply charging. 
     * This value can only be used with MMS standard version 1.1 and greater
     */ 
    MmsReplyCharging replyCharging;

    /*! [O] Deadline for reply charging. 
     * This value can only be used with MMS standard version 1.1 and greater
     */
    MmsTimeSec replyChargingDeadline;

    /*! [O] Deadline for reply charging. 
     * This value can only be used with MMS standard version 1.1 and greater
     */
    char *replyChargingId;

    /*! [O] Allowed size for a reply charging. 
     * This value can only be used with MMS standard version 1.1 and greater
     */
    MmsReplyChargingSize replyChargingSize;
     
    /*! Defines the location of the message */
    char *contentLocation;   

    /*! Notification transaction-ID */
    char *transactionId; 
    
    /*! Delivery report request */
    MmsDeliveryReport deliveryReport;



    MmsPriority priority;


    
} MmsNotification;

/*! \struct MmsForward 
 *  \brief A struct containing possible header fields. 
 *  All optional field must be set to 0 or NULL when not used.
 *
 *  Creation of MMS Forward :
 *          Optional fields are marked with [O]
 *          and mandatory fields marked with [M] (i.e. must be set)
 */
typedef struct
{                            
    /*! [O] Arrival time of the message at the MMSProxy-Relay. 
     *  MMSProxy-Relay will generate this field if not supplied. */
    MmsTimeSec date;                    

    /*! [M] Address of the message sender. */ 
    MmsAddress from;                    

    /*! [M] The insert method of the from address. */ 
    MmsFromType fromType;   
    
    /*! [O] Address of the recipient. At least one of the addresses
     *  (To, cc, bcc) MUST be present. If not used it must be set to NULL. */ 
    MmsAddressList *to;                 

    /*! [O] See To field. */    
    MmsAddressList *cc;                 

    /*! [O] See To field. */ 
    MmsAddressList *bcc;                

    /*! [O] The type of expiry time, absolute or relative. Absolute means that
     *      an absolute time (in seconds since 1970-01-01) is given. Relative
     *      means that the server will add the given number of seconds to
     *      current time.
     */
    MmsTimeType expiryTimeType;

    /*! [O] Time until the message is removed from the MMS Proxy-Relay,
     *  not set equals max time.
     */
    MmsTimeSec expiryTime;              


        /*! [O] The type of expiry time, absolute or relative. Absolute means that
     *      an absolute time (in seconds since 1970-01-01) is given. Relative
     *      means that the server will add the given number of seconds to
     *      current time.
     */
    MmsTimeType deliveryTimeType;
    
    
    /*! [O] Time the message should be delivered, not set equals immediate. */
    MmsTimeSec deliveryTime;            

    /* [O] Sending of delivery report allowed to the previous sender of the 
     * message to be forwarded */
    MmsDeliveryReport reportAllowed;

    /*! [O] Request for a Delivery Report. */ 
    MmsDeliveryReport deliveryReport;   

    /*! [O] Request for a Read Reply. */ 
    MmsReadReply readReply;             
} MmsForward;

/*! \struct MmsReadOrigInd
 *  \brief A struct containing possible header fields for a Read Orig Ind PDU. 
 */
typedef struct
{
    /*! [M] Address of the message sender. */ 
    MmsAddress from;

    /*! [M] Arrival time of the message at the MMSProxy-Relay. 
     *  MMSProxy-Relay will generate this field if not supplied. */
    MmsTimeSec date;           

    /*! [M] Read-Status of the message. */
    MmsReadStatus readStatus;

    /* [M] Message-Id of the message. */
    char *serverMessageId;
} MmsReadOrigInd;

/*!
 * \struct MmsFileReference 
 * \brief Information about the the file. Used when 
 *        MmsBodyPartStorage is MMS_BODY_PART_AS_FILE. 
 */
typedef struct
{
    char    category;   /*!< Contains the category for the current message */ 
    
    /*! A reference to the file where the body part is stored */
    MSF_UINT32  id; 
} MmsFileReference;

/*!
 * \enum MmsBodyPartTarget Information about where the bodypart will be added.
 */
typedef enum
{
    /*! The bodypart is added to a multipart message. */
    MMS_MULTIPART_MESSAGE,
    /*! The bodypart is added to a multipart entry file */
    MMS_MULTIPART_ENTRY,
    /*! The bodypart is added to a plain message (NOT a multipart).
     */
    MMS_PLAIN_MESSAGE
} MmsBodyPartTarget;



/*!
 * \struct MmsMessageInfo 
 * \brief Contains information about a message and body.
 */
typedef struct
{
    /*! Total number of message parts in a message body. */
    MSF_UINT32          numOfMsgInfo;   
    /*! Size of the header. */
    MSF_UINT32              headerSize; 
    /*! Number of sub parts for entire multipart message. 0 if not a multipart */
    MSF_UINT32          numOfEntries;   
    /*! List with all content types in a message body  */
    MmsBodyInfoList     *list;  
} MmsMessageInfo;


/*! 
 * \struct MmsMessageInfoHandle
 * \breif Holds information about the message
 */
typedef struct
{
    unsigned char *buffer;
    MSF_UINT32  bufferSize;
} MmsMessageInfoHandle;

/*! 
 * \struct MmsMsgInfo
 * \breif Holds information (msg Type and storage Type) about the message
 */
typedef struct
{
    MmsFileType msgType;
    MSF_UINT8  storageType;
} MmsMsgInfo;

/*! \struct MmsBodyParams 
 *  \brief A struct containing information about the body
 *         part. All parameters are used when adding a body part, hence
 *         none should be left unset.
 */
typedef struct
{
    MmsEntryHeader *entryHeader;        /*!< Entry headers. NULL if none. */ 
    MmsContentType contentType;         /*!< The content type information */
    MmsBodyPartTarget targetType;       /*!< The type of message the part is added to */
} MmsBodyParams; 

/*! MmsRequestId A unique ID for all active GET/POST requests towards STK */
typedef MSF_INT16 MmsRequestId;

/*! \enum MmsNotificationType Possible notification types */
typedef enum
{
    /*! A normal notification used with immediate retrieval.
     */
    MMS_NOTIFICATION_IMMEDIATE,

    /*! A normal notification used with delayed retrieval.
     */
    MMS_NOTIFICATION_NORMAL,

    /*! A notification indicating that a retrieved 
     *  Multimedia Message is stored in a folder. 
     */
    MMS_NOTIFICATION_MESSAGE
} MmsNotificationType;

typedef enum
{
    /*! All notifications are deffered, if not rejected by filters.
     *  (dlayed retrieval).
     */
    MMS_RETRIEVE_DELAYED = 0,

    /*! All message notifications are subject for immediate retrieval
     *  if the notification passes filter criterias.
     */
    MMS_RETRIEVE_IMMEDIATE,

    /*! All message notifications are rejected.
     */
    MMS_RETRIEVE_REJECT,

    /*! All message notifications are ignored.
     */
    MMS_RETRIEVE_IGNORE
} MmsRetrievalMode;


/*! \enum MmsRoamingStatus network roaming state.
 *
 * This enum is used in the registy to decide if the cllular is in roaming
 *
 */
typedef enum
{
    /*! Cellular is considered not to roaming.
     */
    MMS_NOT_ROAMING,

    /*! Cellular is considered to be roaming.
     */
    MMS_ROAMING
} MmsRoamingStatus;



/*! \enum MmsRoamingMode How message notifications are handle while in roaming.
 *
 * This enum is used in the registy to decide how message notifications are
 * handled while the cellular is in roaming mode.
 *
 * Registry key MMS_REG_KEY_NETWORK_STATUS_ROAMING is used to decide roaming state.
 */
typedef enum
{
    /*! All message notifications are handled as in non-roaming.
     * The setting for delayed of immediate retrival is used.
     */
    MMS_ROAM_DEFAULT,

    /*! No notifications are immediately retrived..
     * But when roaming is ended, all notifications suitable for
     * immediate retrival are retrived automatically.
     * 
     */
    MMS_ROAM_RESTRICTED,

    /*! All notifications are deffered (delayed retrieval).
     */
    MMS_ROAM_DELAYED,

    /*! All message notifications are rejected in roaming.
     */
    MMS_ROAM_REJECT
} MmsRoamingMode;

/*! \enum MmsNotificationReason Reason why a notification is received */
typedef enum
{
    /*! The notification is received the normal way.
    */
    MMS_NOTIFICATION_REASON_NORMAL,
                
    /*! The notification is received because the immediate retrieval conditions 
    *  where not fulfilled (requires #MMS_CFG_IMMEDIATE_RETRIEVAL to be set 
    *  to TRUE).
    */
    MMS_NOTIFICATION_REASON_CONDITION_NOT_FULFILLED,
    
    /*! The notification is received because the immediate retrieval operation 
    *  failed (requires #MMS_CFG_IMMEDIATE_RETRIEVAL to be set to TRUE).
    */
    MMS_NOTIFICATION_REASON_RETIEVAL_FAILED,
    
    /*! The notification is received because the message size exceeded the 
    *  remaining persistent storage (requires #MMS_CFG_IMMEDIATE_RETRIEVAL 
    *  to be set to TRUE).
    */
    MMS_NOTIFICATION_REASON_FULL_PERSISTENT_STORAGE,
    
    /*! The notification is received because the message size exceeded the 
    *  maximum allowed download size (requires #MMS_CFG_IMMEDIATE_RETRIEVAL 
    *  to be set to TRUE).
    */
    MMS_NOTIFICATION_REASON_MAX_RETRIEVAL_SIZE_EXCEEDED
} MmsNotificationReason;

/*! \enum MmsResult Result values sent from the MMS Client. */
typedef enum
{
    /* The result codes in this enum shall be held in alphabetic order,
     * except OK that shall be the first and hence has a value equal to 0.
     */

   /*! 0 The operation is successful and finished. */
    MMS_RESULT_OK,
    
   /*! 1 The supplied buffer is full */
    MMS_RESULT_BUFFER_FULL,

   /*! 2 Too many consective calls to a connector function have been made without 
    *  waiting for the outcome of the previous calls.
    */
    MMS_RESULT_BUSY,

    /*! 3 A requested body part was not found */
    MMS_RESULT_BODY_PART_NOT_FOUND,

    /*! 4 An #MMSc_sendMessage or #MMSc_retrieveMessage operation is cancelled
     *  by an #MMSc_cancel. */
    MMS_RESULT_CANCELLED_BY_USER,

    /*! 5 An send or retrieve operation is cancelled
     *  by an the system, propably because network bearer is unavailable.
     */
    MMS_RESULT_CANCELLED_BY_SYSTEM,

    /*! 6 Communication error: The address could not be resolved. */
    MMS_RESULT_COMM_ADDRESS_UNRESOLVED,
    
    /*! 7 Communication error: Bad gateway. */
    MMS_RESULT_COMM_BAD_GATEWAY,

    /*! 8 Communication error: Entity too large. */
    MMS_RESULT_COMM_ENTITY_TOO_LARGE,

    /*! 9 Communication error: Unknown communication error. */
    MMS_RESULT_COMM_FAILED,

    /*! 10 Communication error: File or message not found. */
    MMS_RESULT_COMM_FILE_NOT_FOUND,

    /*! 11 Communication error: File or message not found Permanent error. */
    MMS_RESULT_P_COMM_FILE_NOT_FOUND,

    /*! 12 Communication error: Communication not allowed, service or method 
     *  denied. */
    MMS_RESULT_COMM_FORBIDDEN,

    /*! 13 Communication error: PDU did not contain expected tag. */
    MMS_RESULT_COMM_HEADER_TAG, 

    /*! 14 Communication error: An illegal or badly formatted PDU was received. */
    MMS_RESULT_COMM_ILLEGAL_PDU,

    /*! 15 Communication error: The operation (e.g. Reply Charging) had 
     *  limitations that were violated in the request. */
    MMS_RESULT_COMM_LIMITATIONS_NOT_MET,

    /*! 16 Communication error: WSP/HTTP proxy needed or WSP/HTTP proxy 
     *  authentication required. */
    MMS_RESULT_COMM_PROXY_ERROR,

    /*! 17 Communication error: The MMS Proxy-Relay did not recognize one PDU
     *  that the MMS Service sent. This is probably due to a misconfiguration
     *  of the MMS Proxy-Relay version. */
    MMS_RESULT_COMM_MMSC_VERSION,

    /*! 18 Communication error: Error in TLS/WTLS setup. */
    MMS_RESULT_COMM_SECURITY_ERROR,

    /*! 19 Communication error: Unknown MMS Proxy-Relay error. */
    MMS_RESULT_COMM_SERVER_ERROR,

    /*! 20 Communication error: Wrong communication status. */
    MMS_RESULT_COMM_STATUS,

    /*! 21 Communication error: Operation timed out, e.g. no contact with the MMS 
     *  Proxy-Relay. */
    MMS_RESULT_COMM_TIMEOUT,

    /*! 22 Communication error: Unexpected transaction ID. */
    MMS_RESULT_COMM_TRANSACTION_ID, 

    /*! 23 Communication error: Unauthorized. */
    MMS_RESULT_COMM_UNAUTHORIZED,

    /*! 24 Communication error: Service unavailable or not supported. */
    MMS_RESULT_COMM_UNAVAILABLE,

    /*! 25 Communication error: Unexpected message received. */
    MMS_RESULT_COMM_UNEXPECTED_MESSAGE, 

    /*! 26 Communication error: Unsupported media type or content. */
    MMS_RESULT_COMM_UNSUPPORTED_MEDIA_TYPE,

    /*! 27 Communication error: Unsupported version. */
    MMS_RESULT_COMM_UNSUPPORTED_VERSION,

    /*! 28 Communication error: URI is too large. */
    MMS_RESULT_COMM_URI_TOO_LARGE,

    /*! 29 A message for a not supported MMS version is received */
    MMS_RESULT_COMM_WRONG_MMS_VERSION,

    /*! 30 Configuration is not correct. */
    MMS_RESULT_CONFIG_ERROR,

    /*! 31 The current file operation cannot be performed at the moment. */
    MMS_RESULT_DELAYED,

    /*! 32 An unknown error has occurred. No further information can be given. */
    MMS_RESULT_ERROR, 

    /*! 33 The end-of-file has been reached for a file. This does not necessarily 
     *  indicate an error. */
    MMS_RESULT_EOF, 

    /*! 34 Error when creating forward header. */
    MMS_RESULT_ERROR_CREATING_FORWARD,

    /*! 35 Error when creating a Read Report. */
    MMS_RESULT_ERROR_CREATING_READ_REPORT,

    /*! 36 Error when creating send header. */
    MMS_RESULT_ERROR_CREATING_SEND_HEADER,
    
    /*! 37 Error creating backup file. */
    MMS_RESULT_FILE_BACKUP_ERROR,

    /*! 38 A file is not found.*/
    MMS_RESULT_FILE_NOT_FOUND,
        
    /*! 39 Error reading file. */
    MMS_RESULT_FILE_READ_ERROR,

    /*! 40 Error when trying write to file */
    MMS_RESULT_FILE_WRITE_ERROR,

    /*! 41 The folder is not found. */
    MMS_RESULT_FOLDER_NOT_FOUND, 

    /*! 42 Index file is corrupt or does not exist. */
    MMS_RESULT_INDEX_FILE_ERROR,
    
    /*! 43 Information file is corrupt or does not exist. */
    MMS_RESULT_INFO_FILE_ERROR,

    /*! 44 Not enough persistent storage for the requested operation. */
    MMS_RESULT_INSUFFICIENT_PERSISTENT_STORAGE,

    /*! 45 Not enough memory for the requested operation. */
    MMS_RESULT_INSUFFICIENT_MEMORY, 
    
    /*! 46 One of the fields To, Cc, Bcc is invalid */
    MMS_RESULT_INVALID_ADDRESS,

    /*! 47 Invalid or not existing application header field. */
    MMS_RESULT_INVALID_APPLICATION_HEADER,
    
    /*! 48 Invalid or not existing Content-Id. */
    MMS_RESULT_INVALID_CONTENT_ID,

    /*! 49 Invalid or not existing Content-Location. */
    MMS_RESULT_INVALID_CONTENT_LOCATION,

    /*! 50 Content type is invalid. */
    MMS_RESULT_INVALID_CONTENT_TYPE,
    
    /*! 51 Expiry time is invalid. */
    MMS_RESULT_INVALID_EXPIRY_TIME,

    /*! 52 The total size of the MMS header is invalid. */
    MMS_RESULT_INVALID_HEADER_SIZE,

    /*! 53 Message class is invalid. */
    MMS_RESULT_INVALID_MSG_CLASS,

    /*! 54 Reply Charging Deadline is invalid.  */
    MMS_RESULT_INVALID_REPLY_CHARGING_DEADLINE,

    /*! 55 Size is invalid.  */
    MMS_RESULT_INVALID_SIZE,

    /*! 56 The storage type is invalid. */
    MMS_RESULT_INVALID_STORAGE_TYPE,

    /*! 57 Subject is invalid. */
    MMS_RESULT_INVALID_SUBJECT,

    /*! 58 The MMS version number is invalid for the requested operation. */
    MMS_RESULT_INVALID_VERSION,
   
    /*! 59 Date is invalid. */
    MMS_RESULT_INVALID_DATE,

    /*! 60 Transaction ID missing. */
    MMS_RESULT_TRANSACTION_ID_MISSING,
    
    /*! 61 The message is corrupt. */
    MMS_RESULT_MESSAGE_CORRUPT, 

    /*! 62 The message was empty. */
    MMS_RESULT_MESSAGE_EMPTY, 
    
    /*! 63 The message with the specified message ID could not be found. */
    MMS_RESULT_MESSAGE_ID_NOT_FOUND, 

    /*! 64 No report should be sent to this message. */
    MMS_RESULT_NO_REPORT,

    /*! 65 The queue holding immediate retrieval notifications is full. */
    MMS_RESULT_NOTIFICATION_QUEUE_FULL,

    /*! 66 The recipient address is not set in the message. */
    MMS_RESULT_RECIPIENT_ADDRESS_NOT_SET,

    /*! 67 The MMS Client has encountered an unrecoverable application error.
     *  The MMS Client must be stopped and restarted by the MMS Application.
     */
    MMS_RESULT_RESTART_NEEDED,
    
    /*! 68 The MMS Client has been stopped due to an internal error. */
    MMS_RESULT_STOPPED,

    /*! 69 Max number of stored message reached. */ 
    MMS_RESULT_TOO_MANY_MSG,

     /*! 70 The warning threshold of number of stored messages in
     *  the MMS folders reached.
     */
    MMS_RESULT_MANY_MSG_WARNING,

    /*! 71 The URI is not valid. */
    MMS_RESULT_URI_NOT_VALID,

    /*! 72 The message type is wrong. */ 
    MMS_RESULT_WRONG_FILE_TYPE,

    /*! 
     *  73 The received push notification was larger than 
     * MMS_MAX_NOTIFICATION_SIZE bytes.   
     */
    MMS_RESULT_MAX_NOTIFICATION_SIZE_EXCEEDED,
    
    /*! 74 During a retrieval operation, the downloaded message was larger than 
     *  the configuration variable MMS_CFG_MAX_RETRIEVAL_SIZE.
     */
    MMS_RESULT_MAX_RETRIEVAL_SIZE_EXCEEDED,

	/*! 75 During a retrieval operation, the downloaded message was Expired*/
    MMS_RESULT_MSG_EXPIRED,

    /*! 76 Resp Ok but download fail due to Memory Full. */
    MMS_RESULT_OK_MEM_FULL,

    /*! 77 The message is Unsupported. */
    MMS_RESULT_MESSAGE_UNSUPPORTED,

    /*! 78 The memory card plug out. */
    MMS_RESULT_ERROR_MEM_CARD_PLUG_OUT,

    /*! 79 The Root Directory Full. Can't create Directory. */
    MMS_RESULT_ERROR_ROOT_DIR_FULL
} MmsResult;

/*! \struct MmsDeliveryInd holds the decoded elments from a M-Delivery.ind */
typedef struct
{
    MSF_UINT8 version;    /*!< The verion of MMS (MMS Proxy/Realy) */
    MmsTimeSec date;      /*!< date&time when the message was handled */
    MmsStatus status;     /*!< the status of the message id send request */
    char *messageId;      /*!< Unique reference assigned to the message */
    MmsAddress *to;       /*!< the recipent address */
    MSF_UINT32 reportId;  /*!< Report ID */
} MmsDeliveryInd; 

/*! \struct MmsForwardConf 
 *  \brief A struct containing possible header fields for a forward confirm. 
 */
typedef struct
{             
    char *messageId;    /*!< Unique reference assigned to the message */
    void *responseText; /*!< Description which qualifies the response status value.*/
    MmsStatus status;   /*!< the status of the message id send request      */
    MSF_UINT8 version;  /*!< The verion of MMS (MMS Proxy/Realy) */
} MmsForwardConf;

/* SAP specific to MMA start*/
#define JSR_MAX_APP_ID_LENGTH 100
#define MMS_MAX_ADDR_LEN 128
#define MMS_MAX_SUBJECT_LEN 41
#define MMS_MAX_APP_DATA_LENGTH 32
typedef struct
{
    MSF_UINT32 num_of_recipient;	/* TRUE: msg has more than 1 recipent */
	MSF_UINT32 compose_date;
    MSF_UINT32 expiry_date;
    MSF_UINT32 receive_date;
    MSF_UINT32 user_elements_size;
    MSF_UINT32 msg_size;
    MSF_UINT32 ori_reported_msg_id;
    MSF_BOOL has_attachment;
    MSF_BOOL is_drm;            /* When MMS contain any DRM object, the value is KAL_TRUE */
    MSF_BOOL is_follow_phone_mms_content_class;
	MSF_BOOL need_read_report;
    MSF_BOOL need_delivery_report;
	MSF_BOOL is_forward_lock;
    MSF_BOOL is_read;
    MSF_BOOL is_rr_send;
    MSF_UINT8 reserve_space;
    MSF_UINT8 priority;     /* mma_priority_enum */
    MSF_UINT8 msg_type;         /* mma_msg_type_enum */
    MSF_UINT8 msg_media_type;   /* mma_media_msg_enum */
	MSF_UINT8 folder;
    MSF_UINT8 suffix;                       /* MmsFileType */
    MSF_UINT8 msg_sim_id;
    MSF_UINT8 msg_class;
    MSF_UINT8 msg_report_status;   /* For DR & RR */
    MSF_UINT8 object_count;
} mms_msg_info_property_struct;

/* data in the app_data array */
#define MMA_MMS_LOCK_MODE_APP_DATA_POS 0
#define MMA_MMS_CORRUPT_MMS_POS 1
#define MMA_MMS_PREV_FOLDER_POS 2
#define MMA_MMS_INT_VERSION_POS 3     /* To track the mms created on which build, 0 - Pluto, 1 - FTO */

typedef struct
{
    MSF_UINT8 from_address_type;                /* mma_addr_type_enum */
    MSF_UINT8 address_type;                /* mma_addr_type_enum */
    MSF_WCHAR from_address[MMS_MAX_ADDR_LEN];   /* Encoded by USC2 */    
    MSF_WCHAR address[MMS_MAX_ADDR_LEN];   /* Encoded by USC2 */
    MSF_WCHAR subject[MMS_MAX_SUBJECT_LEN];   /* Encoded by USC2 */
    MSF_UINT8 java_app_id[JSR_MAX_APP_ID_LENGTH];       /* For JSR205  Encoded by ASCII */
    MSF_UINT8 java_reply_app_id[JSR_MAX_APP_ID_LENGTH]; /* For JSR205  Encoded by ASCII */
    MSF_UINT8 app_data[MMS_MAX_APP_DATA_LENGTH];        /* add to remove the space from the FLDR */
} mms_msg_info_large_data_struct;

typedef struct
{
    mms_msg_info_property_struct *property;
    mms_msg_info_large_data_struct *large_data;
} mms_msg_info_struct;

/* file containing address, report status & Object details */
#define MMS_MAX_ADDR_COUNT 20
#define MMS_MAX_OBJECT_COUNT 20
#define MMS_MAX_ADDR_DATA_LEN 61
#define MMS_MAX_OBJECT_FILE_NAME_LEN 21
#define MMS_SUFFIX_OBJADDR "oad"
#define MMS_SUFFIX_OBJBODY "obd"

typedef struct
{
	MSF_UINT16 addr_len;
    MSF_UINT8 addr_group; 	/* TO/CC/BCC/FROM */	
	MSF_UINT8 addr_type;    /* Phone/Email */
    MSF_UINT8 rr_status;    /* Read report status for this address */ 		
	MSF_UINT8 dr_status;    /* Delivery report status for this address */
	MSF_WCHAR address[MMS_MAX_ADDR_DATA_LEN];   /* Encoded by USC2 */
}mms_msg_addr_info_struct;

typedef struct
{
	MSF_UINT32 file_name_len;
	MSF_WCHAR file_name[MMS_MAX_OBJECT_FILE_NAME_LEN];   /* Encoded by USC2 */
}mms_msg_object_info_struct;

typedef struct
{
	MSF_UINT32 chksum;
    MSF_UINT8 total_address; 		
	MSF_UINT8 total_object;
    MSF_UINT16 temp_data;   /* 4N Aligned future use */
	mms_msg_addr_info_struct addr_data[MMS_MAX_ADDR_COUNT];
    mms_msg_object_info_struct object_data[MMS_MAX_OBJECT_COUNT];
}mmsAddrObjectInfo;

typedef struct
{    
    MSF_UINT32 body_size;
    MSF_UINT32 body_offset;
	MSF_UINT16 body_name_len;
    MSF_UINT8 body_type;         /* Text, Image, Audio, Video */
    MSF_UINT8 is_drm;         /* Text, Image, Audio, Video */
	MSF_WCHAR body_name[MMS_MAX_OBJECT_FILE_NAME_LEN];
}mms_msg_body_object_info_struct;


typedef struct
{
	MSF_UINT32 chksum; 		
	MSF_UINT8 total_object;
	mms_msg_body_object_info_struct body_data[1];
}mmsBodyObjectInfo;

#define MMS_MAX_OBJECT_FILE_SIZE (sizeof(MSF_UINT32) * 2 + sizeof(mms_msg_body_object_info_struct) * MMS_MAX_OBJECT_COUNT)

/* SAP for the report BOX feature */
//#ifndef __MMI_MMS_REPORT_BOX_SUPPORT__
//#define __MMI_MMS_REPORT_BOX_SUPPORT__
//#endif

/* MAX 60 Nodes in the Report status file */
//#define MMS_MAX_REPORT_COUNT_DATA 60 /* MMS_MAX_REPORT_COUNT */
#define MMS_REPORT_INFO_FILE "report_index.txt"
#define MMS_REPORT_COUNT_FILE "report_count.txt"
#define MMS_STATUS_IS_DR 0
#define MMS_STATUS_IS_RR 1
#define MMS_REPORT_MSG_MSG_ID_BASE 500
#define MMS_REPORT_MSG_MSG_ID_END 560
#define MMS_REPORT_FILE_SIZE (sizeof(mms_msg_report_info) + (sizeof(mms_msg_report_info_struct) * (MMS_MAX_REPORT_COUNT - 1)))
typedef struct
{
	MSF_UINT32 orig_msgId;  /* Original msg_id for which this report come */
    MSF_UINT32 date;
    MSF_UINT8 storage_type;    /* Storage of the MMS */
    MSF_UINT8 report_type;    /* Read/Delivery report. 0 means DR, 1 means RR */
    MSF_UINT8 status;    /* Read/Delivery report status for this address */
    MSF_UINT8 sim_id;    /* sim ID status. For Dual SIM */
	MSF_UINT8 addr_type;    /* Phone/Email */    
	MSF_WCHAR address[MMS_MAX_ADDR_DATA_LEN];   /* Encoded by UCS2 */
}mms_msg_report_info_struct;

typedef struct
{
	MSF_UINT32 chksum;
    MSF_UINT32 report_count;    /* number of current entry of reports */
    mms_msg_report_info_struct data[1];
}mms_msg_report_info;
/* SAP specific to MMA end*/

/* 
 * ! \brief Signal struct replying progress status
 */ 
typedef struct 
{
    MSF_UINT8 operation;        /*!< send/retrieve/imm-retrieve */
    MSF_UINT8 state;            /*!< start/completed/progress/stop */
	MSF_UINT8 simId;
    MSF_UINT8 storageType;    /*!< storage Type */
    MmsMsgId msgId;             /*!< folder manager file Id number */
    MSF_UINT32 progress;        /*!< data read/sent */
    MSF_UINT32 totalLength;     /*!< total data to send/read (estimate) */
} MmsProgressStatus;

#define MMS_PROGRESS_STATUS_START      (0) /* Start of send/retrive */
#define MMS_PROGRESS_STATUS_COMPLETED  (1) /* Send/retrieve completed */
#define MMS_PROGRESS_STATUS_STOP       (2) /* fail/cancel */
#define MMS_PROGRESS_STATUS_PROGRESS   (3) /* Intermediate progress status */
#ifdef MTK_TMP_PATCH /* CR33553: CMCC: send retry indication */
#define MMS_PROGRESS_STATUS_RETRY      (4) /* Intermediate progress status */
#endif

#define MMS_PROGRESS_STATUS_SEND        (0) /* Send */
#define MMS_PROGRESS_STATUS_RETRIEVE    (1) /* Delayed retrive */
#define MMS_PROGRESS_STATUS_IMMRETRIEVE (2) /* Immediate retrieve */

#ifdef MTK_TMP_PATCH
/*! \enum MmsMMIFeature This enum is used to check if the corresponding option being turned on/off.
 * IMPORTANT: New enum should be appended as the last entry.
 */
typedef enum
{
    /* Do not reject MMS receiving by the notification-specified size: OMA(on); CMCC(off) */
    MMS_MMI_FEATUER_NO_REJECT_NOTIFICATION_BY_SIZE,
    MMS_MMI_FEATUER_NO_DEFAULT_VALUE_IN_PDU_SUPPORT,
    MMS_MMI_FEATUER_SLIM_MMS,
    MMS_MMI_FEATUER_TOTAL
} MmsMMIFeature;

#define MMS_MAX_MEDIA_SUPPORT   0x7F
#endif

/*--- Constants ---*/

/*--- Forwards ---*/

/*--- Externs ---*/

/*--- Macros ---*/

/*--- Prototypes ---*/

#endif  /* _MMS_DEF_H */





















