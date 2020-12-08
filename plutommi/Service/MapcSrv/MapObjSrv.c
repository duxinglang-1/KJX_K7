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
 * MapObjSrv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for bluetooth map client profile and used by any application
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *-------------------------------------------------------------------------------------------*/


#include "stdio.h"
#include "stdlib.h"
#include "string.h"


#include "Conversions.h"
#include "MMIDataType.h"
#include "stack_common.h"
#include "kal_general_types.h"
#include "fs_errcode.h"
#include "fs_func.h"
#include "fs_type.h"
#include "vCard.h"
#include "BtcmSrvGprot.h"
#include "Unicodexdcl.h"

#ifdef __BT_MAP_CLIENT__
#include "MapObjSrv.h"
#endif 
#include "Mmi_frm_mem_gprot.h"
#include "QueueGprot.h"

#ifdef __BT_MAP_CLIENT__
/* Common XML doc defintion */
#define XML_TAG_ELEMENT_START       "<"
#define XML_TAG_ELEMENT_END         "</"
#define XML_TAG_SINGLE_END          "/>"
#define XML_TAG_GENERAL_END         ">"

#define MAP_XML_ATTR_VERSION "version"
#define MAP_XML_ATTR_VERSION_VALUE "1.0"
#define MAP_XML_ATTR_SIZE "size"
#define MAP_XML_ATTR_BOOL_VALUE_YES "yes"
#define MAP_XML_ATTR_BOOL_VALUE_NO "no"
#define MAP_XML_ATTR_TYPE "type"
#define MAP_XML_ATTR_HANDLE "handle"

/* Folder listing XML defintion */
#define MAP_XML_HEADER "<?xml version=\"1.0\"?>\n<!DOCTYPE folder-listing SYSTEM \"obex-folder-listing.dtd\">\n"
#define MAP_XML_ELEMENT_FOLDER_LISTING "folder-listing"
#define MAP_XML_ELEMENT_FOLDER "folder"
#define MAP_XML_ATTR_NAME "name"
#define MAP_XML_ATTR_CREATED "created"

/* Message listing XML defintion */
#define MAP_XML_ELEMENT_MSG_LISTING "MAP-msg-listing"
#define MAP_XML_ELEMENT_MSG "msg"
#define MAP_XML_ATTR_SUBJECT "subject"
#define MAP_XML_ATTR_DATETIME "datetime"
#define MAP_XML_ATTR_SENDER_NAME "sender_name"
#define MAP_XML_ATTR_SENDER_ADDRESSING "sender_addressing"
#define MAP_XML_ATTR_REPLYTO_ADDRESSING "replyto_addressing"
#define MAP_XML_ATTR_RECIPIENT_NAME "recipient_name"
#define MAP_XML_ATTR_RECIPIENT_ADDRESSING "recipient_addressing"
#define MAP_XML_ATTR_TYPE_VALUE_EMAIL "EMAIL"
#define MAP_XML_ATTR_TYPE_VALUE_SMS_GSM "SMS_GSM"
#define MAP_XML_ATTR_TYPE_VALUE_SMS_CDMA "SMS_CDMA"
#define MAP_XML_ATTR_TYPE_VALUE_MMS "MMS"
#define MAP_XML_ATTR_TEXT "text"
#define MAP_XML_ATTR_RECEPTION_STATUS "reception_status"
#define MAP_XML_ATTR_RECEPTION_STATUS_VALUE_COMPLETE "complete"
#define MAP_XML_ATTR_RECEPTION_STATUS_VALUE_FRACTIONED "fractioned"
#define MAP_XML_ATTR_RECEPTION_STATUS_VALUE_NOTIFICATION "notification"
#define MAP_XML_ATTR_ATTACHMENT_SIZE "attachment_size"
#define MAP_XML_ATTR_PRIORITY "priority"
#define MAP_XML_ATTR_READ "read"
#define MAP_XML_ATTR_SENT "sent"
#define MAP_XML_ATTR_PROTECTED "protected"

/* Event report XML defintion */
#define MAP_XML_ELEMENT_EVENT_REPORT "MAP-event-report"
#define MAP_XML_ELEMENT_EVENT "event"
#define MAP_XML_ATTR_FOLDER "folder"
#define MAP_XML_ATTR_OLD_FOLDER "old_folder"
#define MAP_XML_ATTR_MSG_TYPE "msg_type"

typedef enum
{
    MAP_XML_EVENT_ATTR_TYPE,
    MAP_XML_EVENT_ATTR_HANDLE,
    MAP_XML_EVENT_ATTR_FOLDER,
    MAP_XML_EVENT_ATTR_OLD_FOLDER,
    MAP_XML_EVENT_ATTR_MSG_TYPE,
    MAP_XML_EVENT_ATTR_TOTAL_NO
} map_xml_event_attr_type_enum;

typedef enum
{
    MAP_XML_FOLDER_LISTING_ATTR_VERSION,
    MAP_XML_FOLDER_LISTING_ATTR_TOTAL_NO
} btmtk_map_xml_folder_listing_attr_type_enum;

typedef enum
{
    MAP_XML_FOLDER_ATTR_NAME,
    MAP_XML_FOLDER_ATTR_SIZE,
    MAP_XML_FOLDER_ATTR_CREATED_TIME,
    MAP_XML_FOLDER_ATTR_TOTAL_NO
} btmtk_map_xml_folder_attr_type_enum;

typedef enum
{
    MAP_XML_MSG_LISTING_ATTR_VERSION,
    MAP_XML_MSG_LISTING_ATTR_TOTAL_NO
} btmtk_map_xml_msg_listing_attr_type_enum;

typedef enum
{
    MAP_XML_MSG_ATTR_HANDLE,
    MAP_XML_MSG_ATTR_SUBJECT,
    MAP_XML_MSG_ATTR_DATETIME,
    MAP_XML_MSG_ATTR_SENDER_NAME,
    MAP_XML_MSG_ATTR_SENDER_ADDRESSING,
    MAP_XML_MSG_ATTR_REPLYTO_ADDRESSING,
    MAP_XML_MSG_ATTR_RECIPIENT_NAME,
    MAP_XML_MSG_ATTR_RECIPIENT_ADDRESSING,
    MAP_XML_MSG_ATTR_TYPE,
    MAP_XML_MSG_ATTR_SIZE,
    MAP_XML_MSG_ATTR_TEXT,
    MAP_XML_MSG_ATTR_RECEPTION_STATUS,
    MAP_XML_MSG_ATTR_ATTACHMENT_SIZE,
    MAP_XML_MSG_ATTR_PRIORITY,
    MAP_XML_MSG_ATTR_READ,
    MAP_XML_MSG_ATTR_SENT,
    MAP_XML_MSG_ATTR_PROTECTED,
    MAP_XML_MSG_ATTR_TOTAL_NO
} btmtk_map_xml_msg_attr_type_enum;

/* Vcard doc defintion */
#define VCARD_MAX_LINE_BUFF_SIZE  512
#define VCARD_CR_CHAR         0x0D
#define VCARD_LF_CHAR         0x0A
#define VCARD_LINE_BREAK  "\r\n"
#define VCARD_SEP_STR   ":"

#define MAP_VCARD_PROP_BEGIN "BEGIN"
#define MAP_VCARD_PROP_END "END"
#define MAP_VCARD_OBJ_VALUE_BMSG "BMSG"
#define MAP_VCARD_OBJ_VALUE_VCARD "VCARD"
#define MAP_VCARD_PROP_VERSION "VERSION"
#define MAP_VCARD_PROP_VERSION_VALUE_10 "1.0"
#define MAP_VCARD_PROP_STATUS "STATUS"
#define MAP_VCARD_PROP_STATUS_VALUE_READ "READ"
#define MAP_VCARD_PROP_STATUS_VALUE_UNREAD "UNREAD"
#define MAP_VCARD_PROP_TYPE "TYPE"
#define MAP_VCARD_PROP_TYPE_VALUE_EMAIL "EMAIL"
#define MAP_VCARD_PROP_TYPE_VALUE_SMS_GSM "SMS_GSM"
#define MAP_VCARD_PROP_TYPE_VALUE_SMS_CDMA "SMS_CDMA"
#define MAP_VCARD_PROP_TYPE_VALUE_MMS "MMS"
#define MAP_VCARD_PROP_FOLDER "FOLDER"
#define MAP_VCARD_OBJ_VALUE_BENV "BENV"
#define MAP_VCARD_OBJ_VALUE_BBODY "BBODY"
#define MAP_VCARD_PROP_PARTID "PARTID"
#define MAP_VCARD_PROP_ENCODING "ENCODING"
#define MAP_VCARD_PROP_ENCODING_VALUE_8BIT "8BIT"
#define MAP_VCARD_PROP_ENCODING_VALUE_G7BIT "G-7BIT"
#define MAP_VCARD_PROP_ENCODING_VALUE_G7BITEXT "G-7BITEXT"
#define MAP_VCARD_PROP_ENCODING_VALUE_GUCS2 "G-UCS2"
#define MAP_VCARD_PROP_ENCODING_VALUE_G8BIT "G-8BIT"
#define MAP_VCARD_PROP_ENCODING_VALUE_C8BIT "C-8BIT"
#define MAP_VCARD_PROP_ENCODING_VALUE_CEPM "C-EPM"
#define MAP_VCARD_PROP_ENCODING_VALUE_C7ASCII "C-7ASCII"
#define MAP_VCARD_PROP_ENCODING_VALUE_CIA5 "C-IA5"
#define MAP_VCARD_PROP_ENCODING_VALUE_CUNICODE "C-UNICODE"
#define MAP_VCARD_PROP_ENCODING_VALUE_CSJIS "C-SJIS"
#define MAP_VCARD_PROP_ENCODING_VALUE_CKOREAN "C-KOREAN"
#define MAP_VCARD_PROP_ENCODING_VALUE_CLATINHEB "C-LATINHEB"
#define MAP_VCARD_PROP_ENCODING_VALUE_CLATIN "C-LATIN"
#define MAP_VCARD_PROP_CHARSET "CHARSET"
#define MAP_VCARD_PROP_CHARSET_VALUE_UTF8 "UTF-8"
#define MAP_VCARD_PROP_CHARSET_VALUE_NATIVE "NATIVE"
#define MAP_VCARD_PROP_LANGUAGE "LANGUAGE"
#define MAP_VCARD_PROP_LANGUAGE_VALUE_ENGLISH "ENGLISH"
#define MAP_VCARD_PROP_LANGUAGE_VALUE_FRENCH "FRENCH"
#define MAP_VCARD_PROP_LANGUAGE_VALUE_SPANISH "SPANISH"
#define MAP_VCARD_PROP_LANGUAGE_VALUE_JAPANESE "JAPANESE"
#define MAP_VCARD_PROP_LANGUAGE_VALUE_KOREAN "KOREAN"
#define MAP_VCARD_PROP_LANGUAGE_VALUE_CHINESE "CHINESE"
#define MAP_VCARD_PROP_LANGUAGE_VALUE_HEBREW "HEBREW"
#define MAP_VCARD_PROP_LANGUAGE_VALUE_TURKISH "TURKISH"
#define MAP_VCARD_PROP_LANGUAGE_VALUE_PORTUGUESE "PORTUGUESE"
#define MAP_VCARD_PROP_LANGUAGE_VALUE_UNKNOWN "UNKNOWN"
#define MAP_VCARD_PROP_LENGTH "LENGTH"
#define MAP_VCARD_OBJ_VALUE_MSG "MSG"

#define MAP_VCARD_OBJ_VALUE_MSG_BEGIN_LEN 	11
#define MAP_VCARD_OBJ_VALUE_MSG_END_LEN 	9
#define MAP_VCARD_OBJ_VALUE_MSG_SHELL_LEN 	(MAP_VCARD_OBJ_VALUE_MSG_BEGIN_LEN + MAP_VCARD_OBJ_VALUE_MSG_END_LEN + 2)

/* vcard field enum */
typedef enum
{
    MAP_VCARD_FIELD_BEGIN,      /* vcard begin feild */
    MAP_VCARD_FIELD_END,        /* vcard end feild */
    MAP_VCARD_FIELD_TOTAL       /* enum total */
} btmtk_map_vcard_field_enum;

/* vcard object enum */
typedef enum
{
    MAP_VCARD_OBJECT_NULL,
    MAP_VCARD_OBJECT_BMSG,
    MAP_VCARD_OBJECT_BENV,
    MAP_VCARD_OBJECT_BBODY,
    MAP_VCARD_OBJECT_MSG,
    MAP_VCARD_OBJECT_VCARD,
    MAP_VCARD_OBJECT_TOTAL
} btmtk_map_vcard_object_enum;

/* bMessage vcard field enum */
typedef enum
{
    MAP_VCARD_BMSG_PROP_NULL,
    MAP_VCARD_BMSG_PROP_VERSION,
    MAP_VCARD_BMSG_PROP_STATUS,
    MAP_VCARD_BMSG_PROP_TYPE,
    MAP_VCARD_BMSG_PROP_FOLDER,
    MAP_VCARD_BMSG_PROP_TOTAL
} btmtk_map_vcard_bmessage_prop_enum;

/* bBody vcard field enum */
typedef enum
{
    MAP_VCARD_BBODY_PROP_NULL,
    MAP_VCARD_BBODY_PROP_PARTID,
    MAP_VCARD_BBODY_PROP_ENCODING,
    MAP_VCARD_BBODY_PROP_CHARSET,
    MAP_VCARD_BBODY_PROP_LANGUAGE,
    MAP_VCARD_BBODY_PROP_LENGTH,
    MAP_VCARD_BBODY_PROP_TOTAL
} btmtk_map_vcard_bbody_prop_enum;

/* bBody encoding enum */
typedef enum
{
    MAP_VCARD_ENC_8BIT,       /* For Email/MMS: 8-bit-clean encoding */
    MAP_VCARD_ENC_G7BIT,      /* For GSM-SMS: GSM 7-bit default alphabet */
    MAP_VCARD_ENC_G7BITEXT,   /* For GSM-SMS: GSM 7-bit alphabet with national language extension */
    MAP_VCARD_ENC_GUCS2,      /* For GSM-SMS */
    MAP_VCARD_ENC_G8BIT,      /* For GSM-SMS */
    MAP_VCARD_ENC_C8BIT,      /* For CDMA-SMS: Octet, unspecified */
    MAP_VCARD_ENC_CEPM,       /* For CDMA-SMS: Extended protocol message */
    MAP_VCARD_ENC_C7ASCII,    /* For CDMA-SMS: 7-bit ASCII */
    MAP_VCARD_ENC_CIA5,       /* For CDMA-SMS: IA5 */
    MAP_VCARD_ENC_CUNICODE,   /* For CDMA-SMS: Unicode */
    MAP_VCARD_ENC_CSJIS,      /* For CDMA-SMS: Shift-JIS */
    MAP_VCARD_ENC_CKOREAN,    /* For CDMA-SMS: Korean */
    MAP_VCARD_ENC_CLATINHEB,  /* For CDMA-SMS: Latin/Hebrew */
    MAP_VCARD_ENC_CLATIN,     /* For CDMA-SMS: Latin */
    MAP_VCARD_ENC_TOTAL
} btmtk_map_vcard_encoding_enum;

/* bBody language enum */
typedef enum
{
	MAP_VCARD_LANG_ENGLISH,   /* For CDMA-SMS */
	MAP_VCARD_LANG_FRENCH,    /* For CDMA-SMS */
	MAP_VCARD_LANG_SPANISH,   /* For CDMA-SMS, GSM-SMS */
	MAP_VCARD_LANG_JAPANESE,  /* For CDMA-SMS */
	MAP_VCARD_LANG_KOREAN,    /* For CDMA-SMS */
	MAP_VCARD_LANG_CHINESE,   /* For CDMA-SMS */
	MAP_VCARD_LANG_HEBREW,    /* For CDMA-SMS */
	MAP_VCARD_LANG_TURKISH,   /* For GSM-SMS */
	MAP_VCARD_LANG_PORTUGUESE,/* For GSM-SMS */
	MAP_VCARD_LANG_UNKNOWN,   /* For CDMA-SMS, GSM-SMS */
	MAP_VCARD_LANG_TOTAL
} btmtk_map_vcard_language_enum;

/* bBody charset enum */
typedef enum
{
	MAP_VCARD_CHARSET_UTF8,   /* For CDMA-SMS */
	MAP_VCARD_CHARSET_TOTAL
} btmtk_map_vcard_charset_enum;

#define MBT_MAP_MSG_TYPE_SMS_GSM			0x01	// Emails on RFC2822 or MIME type basis
#define MBT_MAP_MSG_TYPE_SMS_CDMA			0x02	// GSM short messages
#define MBT_MAP_MSG_TYPE_EMAIL				0x04	// CDMA short messages
#define MBT_MAP_MSG_TYPE_MMS				0x08	// 3GPP MMS messages
typedef unsigned char MBT_MAP_MSG_TYPE;

typedef struct
{
	MBT_MAP_NOTIF_STATUS		State;
	U8							MasInstId;		// MAS Instance ID
} MBT_MAP_MNS_NOTIF_REG;

	// MAP MNS Status
typedef struct
{
	MBT_MAP_STATE				State;			// The state for MNS
	MBT_MAP_MNS_NOTIF_REG		NotifReg[MBT_MAP_MAX_MAS_INST_NUM];
	MBT_MAP_SEND_EVENT_REQ		SendEvt;
} MBT_MAP_MNS_STATUS;



typedef struct {

    unsigned char state;

	MBT_MAP_MAS_STATUS		masStatus[MBT_MAP_MAX_MAS_INST_NUM];
	MBT_MAP_MNS_STATUS		mnsStatus[MBT_MAP_MAX_MCE_NUM];

	/* For XML/vCard creation */
    char file_buffer[MAP_ADP_BUFFER_SIZE];
    char builder_buffer[MAP_ADP_BUFFER_SIZE];

} map_ext_cntx_struct;

//static S32 btmtk_map_vcard_read_msg(S8 *buf, S32 buf_size, S32 fh);
MBT_MAP_MAS_STATUS *btmtk_map_util_search_mas_instance(unsigned char instance);
unsigned char *btmtk_map_util_get_virtual_folder_path(unsigned char *physical_path, unsigned char *physical_root_path);




map_ext_cntx_struct g_pi_map_cntx = {0};


static const char *btmtk_map_xml_get_msg_type_string(MBT_MAP_MSG_TYPE msg_type)
{
    switch(msg_type)
    {
    case MBT_MAP_MSG_TYPE_EMAIL:
        return MAP_XML_ATTR_TYPE_VALUE_EMAIL;
    case MBT_MAP_MSG_TYPE_SMS_GSM:
        return MAP_XML_ATTR_TYPE_VALUE_SMS_GSM;
    case MBT_MAP_MSG_TYPE_SMS_CDMA:
        return MAP_XML_ATTR_TYPE_VALUE_SMS_CDMA;
    case MBT_MAP_MSG_TYPE_MMS:
        return MAP_XML_ATTR_TYPE_VALUE_MMS;
    default:
        return NULL;
    }
}
static const char *btmtk_map_xml_get_bool_string(MMI_BOOL value)
{
    switch(value)
    {
    case KAL_TRUE:
        return MAP_XML_ATTR_BOOL_VALUE_YES;
    case KAL_FALSE:
        return MAP_XML_ATTR_BOOL_VALUE_NO;
    default:
        return NULL;
    }
}

static const char *btmtk_map_xml_get_reception_string(MBT_MAP_RCV_STATUS status)
{
    switch(status)
    {
    case MBT_MAP_RCV_STATUS_COMPLETE:
        return MAP_XML_ATTR_RECEPTION_STATUS_VALUE_COMPLETE;
    case MBT_MAP_RCV_STATUS_FRACTIONED:
        return MAP_XML_ATTR_RECEPTION_STATUS_VALUE_FRACTIONED;
    case MBT_MAP_RCV_STATUS_NOTIFICATION:
        return MAP_XML_ATTR_RECEPTION_STATUS_VALUE_NOTIFICATION;
    default:
        return NULL;
    }
}

static const char *btmtk_map_xml_get_event_string(MBT_MAP_NOTIF_TYPE from)
{
    switch (from)
    {
    case MBT_MAP_NOTIF_TYPE_NEW_MSG:
        return "NewMessage";
    case MBT_MAP_NOTIF_TYPE_DELIVERY_SUCCESS:
        return "DeliverySuccess";
    case MBT_MAP_NOTIF_TYPE_SENDING_SUCCESS:
        return "SendingSuccess";
    case MBT_MAP_NOTIF_TYPE_DELIVERY_FAILURE:
        return "DeliveryFailure";
    case MBT_MAP_NOTIF_TYPE_SENDING_FAILURE:
        return "SendingFailure";
    case MBT_MAP_NOTIF_TYPE_MEMORY_FULL:
        return "MemoryFull";
    case MBT_MAP_NOTIF_TYPE_MEMORY_AVAILABLE:
        return "MemoryAvailable";
    case MBT_MAP_NOTIF_TYPE_MSG_DELETED:
        return "MessageDeleted";
    case MBT_MAP_NOTIF_TYPE_MSG_SHIFT:
        return "MessageShift";
    default:
     //   BTMTK_ASSERT(0);
     	//bt_ext_log("unexpected type");
        return "";
    }
}

const char *maps_create_event_report_get_msg_type_str(MBT_MAP_MSG_TYPE msg_type)
{
    switch (msg_type)
    {
    case MBT_MAP_MSG_TYPE_SMS_GSM:
        return "SMS_GSM";
    case MBT_MAP_MSG_TYPE_SMS_CDMA:
        return "SMS_CDMA";
    case MBT_MAP_MSG_TYPE_EMAIL:
        return "EMAIL";
    case MBT_MAP_MSG_TYPE_MMS:
        return "MMS";
     default:
        return NULL;
    }
}


static S32 btmtk_map_xml_create_header(S32 handle)
{
    return FS_Write(handle, MAP_XML_HEADER, strlen(MAP_XML_HEADER),0);
}

static S32 btmtk_map_xml_create_element_start(S32 handle, const char *element_name, const char **attr_list)
{
    U32 count = 0, i = 0;
    char *buf = g_pi_map_cntx.builder_buffer;

    count += sprintf(buf, "%s%s", XML_TAG_ELEMENT_START, element_name);
    if (attr_list)
    {
        while (attr_list[i])
        {
            count += sprintf((char *)(buf + count), " %s=\"%s\"", attr_list[i], attr_list[i + 1]);
            i = i + 2;
        }
    }
    count += sprintf((char *)(buf + count), "%s", XML_TAG_GENERAL_END);
//    BTMTK_ASSERT(count <= MAP_ADP_BUFFER_SIZE);
	if (count > MAP_ADP_BUFFER_SIZE) 
	{
		//bt_ext_err("count is larger than MAP_ADP_BUFFER_SIZE");
		return -1;
	}
    count = FS_Write(handle, buf, count,0);
    return count;
}

static U32 btmtk_map_xml_create_element_end(S32 handle, const char *element_name)
{
    U32 count = 0;
    char *buf = g_pi_map_cntx.builder_buffer;

    count += sprintf((char *) buf, "%s%s%s", XML_TAG_ELEMENT_END, element_name, XML_TAG_GENERAL_END);
 //   BTMTK_ASSERT(count <= MAP_ADP_BUFFER_SIZE);
	//    BTMTK_ASSERT(count <= MAP_ADP_BUFFER_SIZE);
	if (count > MAP_ADP_BUFFER_SIZE) 
	{
		//bt_ext_err("count is larger than MAP_ADP_BUFFER_SIZE");
		return (U32)-1;
	}
    count = FS_Write(handle, buf, count,0);
    return count;
}


static U32 btmtk_map_xml_create_element_single(S32 handle, const char *element_name, const char **attr_list)
{
    U32 count = 0, i = 0;
    char *buf = g_pi_map_cntx.builder_buffer;

    count = sprintf((char *)buf, "%s%s", XML_TAG_ELEMENT_START, element_name);
    if (attr_list)
    {
        while (attr_list[i])
        {
            count += sprintf((char *)(buf + count), " %s=\"%s\"", attr_list[i], attr_list[i + 1]);
            i = i + 2;
        }
    }
    count += sprintf((char *)(buf + count), "%s", XML_TAG_SINGLE_END);
 //   BTMTK_ASSERT(count <= MAP_ADP_BUFFER_SIZE);
	 if (count > MAP_ADP_BUFFER_SIZE)
	 {
		//bt_ext_err("count is too large");
		count = MAP_ADP_BUFFER_SIZE;
	 }
    count = FS_Write(handle, buf, count,0);
    return count;
}

U32 btmtk_map_xml_create_folder_list_by_buffer(S8 mas_index,
                                                        U32 FolderNum,
                                                        MBT_MAP_FOLDER_LIST_ENTRY *list,
                                                        S16 offset,
                                                        S16 more, 
                                                        S32 seq_write_fhandle)
{
   // char filename[200 + 1];
	kal_uint8 filename[MAX_FILE_NAME];
    S32 fhandle;
    U32 count, size = 0;

    kal_wsprintf(( WCHAR *)filename, BT_MAP_FOLDER_LIST_FILE, mas_index);

    if (seq_write_fhandle >= 0)
    {
        fhandle = seq_write_fhandle;

    }
    else if ((fhandle = FS_Open((WCHAR*)filename, FS_OPEN_SHARED)) < 0)
    {
        return 0;
    }

    if (offset == 0)
    {
        const char *attr_list[MAP_XML_FOLDER_LISTING_ATTR_TOTAL_NO * 2 + 1];
        int i = 0;

        size += btmtk_map_xml_create_header(fhandle);
    
        /* folder-listing */
        attr_list[i++] = MAP_XML_ATTR_VERSION;
        attr_list[i++] = MAP_XML_ATTR_VERSION_VALUE;
        attr_list[i] = NULL;
        size += btmtk_map_xml_create_element_start(fhandle, MAP_XML_ELEMENT_FOLDER_LISTING, attr_list);
    }

    for (count = 0; count < FolderNum; count++)
    {
        const char *attr_list[MAP_XML_FOLDER_ATTR_TOTAL_NO * 2 + 1];
        int i = 0;
        char n_buf[32];

        /* folder */
        attr_list[i++] = MAP_XML_ATTR_NAME;
        attr_list[i++] = list[count].Name;
        attr_list[i++] = MAP_XML_ATTR_SIZE;
        sprintf(n_buf, "%d", list[count].Size);
        attr_list[i++] = n_buf;
        if (strlen(list[count].Time))
        {
            attr_list[i++] = MAP_XML_ATTR_CREATED;
            attr_list[i++] = list[count].Time;
        }
        attr_list[i] = NULL;
      //  BTMTK_ASSERT(i <= MAP_XML_FOLDER_ATTR_TOTAL_NO * 2 + 1);
      	if (i > MAP_XML_FOLDER_ATTR_TOTAL_NO * 2 + 1) 
      	{
      		//bt_ext_err("i is too large");
      	}
        size += btmtk_map_xml_create_element_single(fhandle, MAP_XML_ELEMENT_FOLDER, attr_list);
    }

    if (!more)
    {
        size += btmtk_map_xml_create_element_end(fhandle, MAP_XML_ELEMENT_FOLDER_LISTING);
    }

    if (seq_write_fhandle < 0)
    {
        FS_Close(fhandle);
    }
    return size;
}

U32 btmtk_map_xml_create_folder_list_by_file(S8 mas_index, char *filename, U32 filesize)
{
   // char output[200 + 1];
	kal_uint8 output[MAX_FILE_NAME];
    S32 fhandle, seq_write_fhandle;
    S32 entry_size = sizeof(MBT_MAP_FOLDER_LIST_ENTRY), index = 0, total;
    U32 count, size = 0;
	U32 bytes_read = 0;

    kal_wsprintf(( WCHAR *)output, BT_MAP_FOLDER_LIST_FILE, mas_index);

    if ((seq_write_fhandle = FS_Open((WCHAR*)output, FS_OPEN_SHARED)) < 0)
    {
        return 0;
    }
    
    if ((fhandle = FS_Open((WCHAR*)filename, FS_READ_ONLY)) < 0)
    {
        return 0;
    }

    total = filesize / entry_size;
    for (count = 0; count < filesize; count+= entry_size, index++)
    {
        if (FS_Read(fhandle, g_pi_map_cntx.file_buffer, entry_size, &bytes_read) == entry_size)
        {
            size = btmtk_map_xml_create_folder_list_by_buffer(mas_index,
                                                       1, 
                                                       (MBT_MAP_FOLDER_LIST_ENTRY *) g_pi_map_cntx.file_buffer, 
                                                       (S16) index, 
                                                       (S16) (total - index), 
                                                       seq_write_fhandle);
        }
        else
        {

            break;
        }
    }
    
    FS_Close(fhandle);
    FS_Close(seq_write_fhandle);
    return size;
}

U32 btmtk_map_xml_create_message_list_by_buffer(S8 mas_index,
                                                    U32 msg_num,
                                                    MBT_MAP_MSG_LIST_ENTRY *list,
                                                    S16 offset,
                                                    S16 more, 
                                                    S32 seq_write_fhandle)
{
    kal_uint8 filename[MAX_FILE_NAME];
    S32 fhandle;
    U32 count, size = 0;

    kal_wsprintf(( WCHAR *)filename, BT_MAP_MESSAGE_LIST_FILE, mas_index);

    if (seq_write_fhandle >= 0)
    {
        fhandle = seq_write_fhandle;

    }
    else if ((fhandle = FS_Open((WCHAR*)filename, FS_OPEN_SHARED)) < 0)
    {
        return 0;
    }

    if (offset == 0)
    {
        const char *attr_list[MAP_XML_MSG_ATTR_TOTAL_NO * 2 + 1];
        int i = 0;

        /* MAP-msg-listing */
        attr_list[i++] = MAP_XML_ATTR_VERSION;
        attr_list[i++] = MAP_XML_ATTR_VERSION_VALUE;
        attr_list[i] = NULL;
        size += btmtk_map_xml_create_element_start(fhandle, MAP_XML_ELEMENT_MSG_LISTING, attr_list);
    }

    for (count = 0; count < msg_num; count++)
    {
        const char *attr_list[MAP_XML_MSG_ATTR_TOTAL_NO * 2 + 1];
        int i = 0;
        char n_buf[32], n_buf2[32], n_buf3[32];

        /* msg */
        /* handle [M] */
		/* 16 hex digits*/
        attr_list[i++] = MAP_XML_ATTR_HANDLE;
    //    sprintf(n_buf, "%llu", list[count].MsgHandle);
   	sprintf(n_buf, "%llx", list[count].MsgHandle);
        attr_list[i++] = n_buf;
        /* subject [M] */
        attr_list[i++] = MAP_XML_ATTR_SUBJECT;
        attr_list[i++] = list[count].Subject;
        /* datetime [M] */
        attr_list[i++] = MAP_XML_ATTR_DATETIME;
        attr_list[i++] = list[count].DateTime;
        /* sender_name [O] */
        if (strlen(list[count].SenderName))
        {
            attr_list[i++] = MAP_XML_ATTR_SENDER_NAME;
            attr_list[i++] = list[count].SenderName;
        }
        /* sender_addressing [O] */
        if (strlen(list[count].SenderAddr))
        {
            attr_list[i++] = MAP_XML_ATTR_SENDER_ADDRESSING;
            attr_list[i++] = list[count].SenderAddr;
        }
        /* replyto_addressing [O] */
        if (strlen(list[count].ReplyToAddr))
        {
            attr_list[i++] = MAP_XML_ATTR_REPLYTO_ADDRESSING;
            attr_list[i++] = list[count].ReplyToAddr;
        }
        /* recipient_name [O] */
        if (strlen(list[count].RecipientName))
        {
            attr_list[i++] = MAP_XML_ATTR_RECIPIENT_NAME;
            attr_list[i++] = list[count].RecipientName;
        }
        /* recipient_addressing [M] */
        if (strlen(list[count].RecipientAddr))
        {
            attr_list[i++] = MAP_XML_ATTR_RECIPIENT_ADDRESSING;
            attr_list[i++] = list[count].RecipientAddr;
        }
        /* type [M] */
        attr_list[i++] = MAP_XML_ATTR_TYPE;
        attr_list[i++] = btmtk_map_xml_get_msg_type_string(list[count].MsgType);
        /* size [M] */
        attr_list[i++] = MAP_XML_ATTR_SIZE;
        sprintf(n_buf2, "%u", list[count].OriginMsgSize);
        attr_list[i++] = n_buf2;
        /* text [O] */
        attr_list[i++] = MAP_XML_ATTR_TEXT;
        attr_list[i++] = btmtk_map_xml_get_bool_string(list[count].bText);
        /* reception_status [M] */
        attr_list[i++] = MAP_XML_ATTR_RECEPTION_STATUS;
        attr_list[i++] = btmtk_map_xml_get_reception_string(list[count].ReceptionStatus);
        /* attachment size [M] */
        attr_list[i++] = MAP_XML_ATTR_ATTACHMENT_SIZE;
        sprintf(n_buf3, "%u", list[count].AttachSize);
        attr_list[i++] = n_buf3;
        /* priority [O] */
        attr_list[i++] = MAP_XML_ATTR_PRIORITY;
        attr_list[i++] = btmtk_map_xml_get_bool_string(list[count].bPriority);
        /* read [O] */
        attr_list[i++] = MAP_XML_ATTR_READ;
        attr_list[i++] = btmtk_map_xml_get_bool_string(list[count].bRead);
        /* sent [O] */
        attr_list[i++] = MAP_XML_ATTR_SENT;
        attr_list[i++] = btmtk_map_xml_get_bool_string(list[count].bSent);
        /* protected [O] */
        attr_list[i++] = MAP_XML_ATTR_PROTECTED;
        attr_list[i++] = btmtk_map_xml_get_bool_string(list[count].bProtected);

        attr_list[i] = NULL;
    //    BTMTK_ASSERT(i <= MAP_XML_MSG_ATTR_TOTAL_NO * 2 + 1);
    	if (i > MAP_XML_MSG_ATTR_TOTAL_NO * 2 + 1)
    	{
    		//bt_ext_err("i is too large");
			return 0;
    	}
        size += btmtk_map_xml_create_element_single(fhandle, MAP_XML_ELEMENT_MSG, attr_list);
    }

    if (!more)
    {
        size += btmtk_map_xml_create_element_end(fhandle, MAP_XML_ELEMENT_MSG_LISTING);
    }

    if (seq_write_fhandle < 0)
    {
        FS_Close(fhandle);
    }
    return size;
}

U32 btmtk_map_xml_create_message_list_by_file(S8 mas_index, char *filename, U32 filesize)
{
    kal_uint8 output[MAX_FILE_NAME];
    S32 fhandle, seq_write_fhandle;
    S32 entry_size = sizeof(MBT_MAP_MSG_LIST_ENTRY), index = 0, total;
    U32 count, size = 0;
	U32 bytes_read = 0;

    kal_wsprintf(( WCHAR *)output, BT_MAP_MESSAGE_LIST_FILE, mas_index);

    if ((seq_write_fhandle = FS_Open((WCHAR*)output, FS_OPEN_SHARED)) < 0)
    {
        return 0;
    }
    
    if ((fhandle = FS_Open((WCHAR*)filename, FS_READ_ONLY)) < 0)
    {
        return 0;
    }

    total = filesize / entry_size;
    for (count = 0; count < filesize; count+= entry_size, index++)
    {
        if (FS_Read(fhandle, g_pi_map_cntx.file_buffer, entry_size, &bytes_read) == entry_size)
        {
            size = btmtk_map_xml_create_message_list_by_buffer(mas_index, 
                                                        1, 
                                                        (MBT_MAP_MSG_LIST_ENTRY *) g_pi_map_cntx.file_buffer, 
                                                        (S16) index, 
                                                        (S16) (total - index), 
                                                        seq_write_fhandle);
        }
        else
        {

            break;
        }
    }
    
    FS_Close(fhandle);
    FS_Close(seq_write_fhandle);
    return size;
}

U32 btmtk_map_xml_create_event_report(S8 mas_index, MBT_MAP_SEND_EVENT_REQ *event)
{
    U32 size = 0, i = 0;
    const char *attr_list[MAP_XML_EVENT_ATTR_TOTAL_NO * 2 + 1];
    kal_uint8 filename[MAX_FILE_NAME];
    S32 fhandle;
    char n_buf[32];

    kal_wsprintf(( WCHAR *)filename, BT_MAP_EVENT_REPORT_FILE, mas_index);
    if ((fhandle = FS_Open((WCHAR*)filename, FS_READ_WRITE | FS_CREATE)) < 0)
    {
        return 0;
    }

    /* MAP-event-report */
    attr_list[i++] = MAP_XML_ATTR_VERSION;
    attr_list[i++] = MAP_XML_ATTR_VERSION_VALUE;
    attr_list[i] = NULL;
    size = btmtk_map_xml_create_element_start(fhandle, MAP_XML_ELEMENT_EVENT_REPORT, attr_list);

    /* event */
    i = 0;
    attr_list[i++] = MAP_XML_ATTR_TYPE;
    attr_list[i++] = btmtk_map_xml_get_event_string(event->EvtRptObj.NotifType);

 //   sprintf(n_buf, "%llu", event->EvtRptObj.MsgHandle);
	sprintf(n_buf, "%llx", event->EvtRptObj.MsgHandle);
    if (strlen(n_buf))
    {
        attr_list[i++] = MAP_XML_ATTR_HANDLE;
        attr_list[i++] = n_buf;
    }
    if (strlen(event->EvtRptObj.FolderPath))
    {
        attr_list[i++] = MAP_XML_ATTR_FOLDER;
        attr_list[i++] = event->EvtRptObj.FolderPath;
    }
    if (strlen(event->EvtRptObj.OldFolderPath))
    {
        attr_list[i++] = MAP_XML_ATTR_OLD_FOLDER;
        attr_list[i++] = event->EvtRptObj.OldFolderPath;
    }
    if (event->EvtRptObj.NotifType != MBT_MAP_NOTIF_TYPE_MEMORY_FULL ||
        event->EvtRptObj.NotifType != MBT_MAP_NOTIF_TYPE_MEMORY_AVAILABLE)
    {
        attr_list[i++] = MAP_XML_ATTR_MSG_TYPE;
        attr_list[i++] = maps_create_event_report_get_msg_type_str(event->EvtRptObj.MsgType);;
    }
    attr_list[i] = NULL;
    size += btmtk_map_xml_create_element_single(fhandle, MAP_XML_ELEMENT_EVENT, attr_list);
    size += btmtk_map_xml_create_element_end(fhandle, MAP_XML_ELEMENT_EVENT_REPORT);
    FS_Close(fhandle);
    return size;
}


static U8 btmtk_vcard_cmp_field(S8 *srcString, const S8 *refString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 refLen, srcLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srcLen = strlen(srcString);
    refLen = strlen(refString);

    if (srcLen < refLen)
    {
        return MMI_FALSE;
    }
    if (strncmp(srcString, (S8*) refString, refLen))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }

}

static S8 *btmtk_vcard_get_value(S8 *strString)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strstr(strString, (S8*) VCARD_SEP_STR) != NULL)
    {
	    return (S8*) (strstr(strString, (S8*) VCARD_SEP_STR) + 1);
    }
    else
    {
		return NULL;
    }
}

static const char *btmtk_map_vcard_get_status_string(MBT_MAP_MSG_READ_STATUS status)
{
    switch(status)
    {
    case MBT_MAP_MSG_STATUS_UNREAD:
        return MAP_VCARD_PROP_STATUS_VALUE_UNREAD;
    case MBT_MAP_MSG_STATUS_READ:
        return MAP_VCARD_PROP_STATUS_VALUE_READ;
    default:
        return NULL;
    }
}

static const char *btmtk_map_vcard_get_msg_type_string(MBT_MAP_MSG_TYPE msg_type)
{
    switch(msg_type)
    {
    case MBT_MAP_MSG_TYPE_EMAIL:
        return MAP_VCARD_PROP_TYPE_VALUE_EMAIL;
    case MBT_MAP_MSG_TYPE_SMS_GSM:
        return MAP_VCARD_PROP_TYPE_VALUE_SMS_GSM;
    case MBT_MAP_MSG_TYPE_SMS_CDMA:
        return MAP_VCARD_PROP_TYPE_VALUE_SMS_CDMA;
    case MBT_MAP_MSG_TYPE_MMS:
        return MAP_VCARD_PROP_TYPE_VALUE_MMS;
    default:
        return NULL;
    }
}

static const char *btmtk_map_vcard_get_encoding_string(MBT_MAP_MSG_ENCODING encoding)
{
    switch(encoding)
    {
    case MBT_MAP_MSG_ENCOD_8BIT:
        return MAP_VCARD_PROP_ENCODING_VALUE_8BIT;
    case MBT_MAP_MSG_ENCOD_G7BIT:
        return MAP_VCARD_PROP_ENCODING_VALUE_G7BIT;
    case MBT_MAP_MSG_ENCOD_G7BITEXT:
        return MAP_VCARD_PROP_ENCODING_VALUE_G7BITEXT;
    case MBT_MAP_MSG_ENCOD_GUCS2:
        return MAP_VCARD_PROP_ENCODING_VALUE_GUCS2;
    case MBT_MAP_MSG_ENCOD_G8BIT:
        return MAP_VCARD_PROP_ENCODING_VALUE_G8BIT;
    case MBT_MAP_MSG_ENCOD_C8BIT:
        return MAP_VCARD_PROP_ENCODING_VALUE_C8BIT;
    case MBT_MAP_MSG_ENCOD_CEPM:
        return MAP_VCARD_PROP_ENCODING_VALUE_CEPM;
    case MBT_MAP_MSG_ENCOD_C7ASCII:
        return MAP_VCARD_PROP_ENCODING_VALUE_C7ASCII;
    case MBT_MAP_MSG_ENCOD_CIA5:
        return MAP_VCARD_PROP_ENCODING_VALUE_CIA5;
    case MBT_MAP_MSG_ENCOD_CUNICODE:
        return MAP_VCARD_PROP_ENCODING_VALUE_CUNICODE;
    case MBT_MAP_MSG_ENCOD_CSJIS:
        return MAP_VCARD_PROP_ENCODING_VALUE_CSJIS;
    case MBT_MAP_MSG_ENCOD_CKOREAN:
        return MAP_VCARD_PROP_ENCODING_VALUE_CKOREAN;
    case MBT_MAP_MSG_ENCOD_CLATINHEB:
        return MAP_VCARD_PROP_ENCODING_VALUE_CLATINHEB;
    case MBT_MAP_MSG_ENCOD_CLATIN:
        return MAP_VCARD_PROP_ENCODING_VALUE_CLATIN;
    default:
        return NULL;
    }
}
static const char *btmtk_map_vcard_get_charset_string(MBT_MAP_MSG_ENCODING encoding)
{
    switch(encoding)
    {
    case MBT_MAP_MSG_CHARSET_NATIVE:
        return MAP_VCARD_PROP_CHARSET_VALUE_NATIVE;
    case MBT_MAP_MSG_CHARSET_UTF8:
        return MAP_VCARD_PROP_CHARSET_VALUE_UTF8;
    default:
        return NULL;
    }
}


static const char *btmtk_map_vcard_get_language_string(MBT_MAP_MSG_LANG language)
{
    switch(language)
    {
    case MBT_MAP_MSG_LANG_ENGLISH:
        return MAP_VCARD_PROP_LANGUAGE_VALUE_ENGLISH;
    case MBT_MAP_MSG_LANG_FRENCH:
        return MAP_VCARD_PROP_LANGUAGE_VALUE_FRENCH;
    case MBT_MAP_MSG_LANG_SPANISH:
        return MAP_VCARD_PROP_LANGUAGE_VALUE_SPANISH;
    case MBT_MAP_MSG_LANG_JAPANESE:
        return MAP_VCARD_PROP_LANGUAGE_VALUE_JAPANESE;
    case MBT_MAP_MSG_LANG_KOREAN:
        return MAP_VCARD_PROP_LANGUAGE_VALUE_KOREAN;
    case MBT_MAP_MSG_LANG_CHINESE:
        return MAP_VCARD_PROP_LANGUAGE_VALUE_CHINESE;
    case MBT_MAP_MSG_LANG_HEBREW:
        return MAP_VCARD_PROP_LANGUAGE_VALUE_HEBREW;
    case MBT_MAP_MSG_LANG_TURKISH:
        return MAP_VCARD_PROP_LANGUAGE_VALUE_TURKISH;
    case MBT_MAP_MSG_LANG_PORTUGUESE:
        return MAP_VCARD_PROP_LANGUAGE_VALUE_PORTUGUESE;
    case MBT_MAP_MSG_LANG_UNKNOWN:
        return MAP_VCARD_PROP_LANGUAGE_VALUE_UNKNOWN;
    default:
        return NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_vcard_uti_get_single_line
 * DESCRIPTION
 *  Get a line from file system, excluding the escape characters for vcard.
 * PARAMETERS
 *  strOutput       [IN/OUT]        Storage location for data
 *  fh              [IN]            File handle
 * RETURNS
 *  void
 *****************************************************************************/
static S32 btmtk_map_vcard_get_single_line(S8 *buf, S32 fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 nBytes = 0;
    S8 strCRLF[4];
    S8 strLF[2];
    S8 *currCursor;
    S8 str_photo_end[12];
    S8 *photo_end_cursor;
    S32 strLen = 0;
	U32 bytes_read=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(strCRLF, "%c%c", VCARD_CR_CHAR, VCARD_LF_CHAR);
    sprintf(strLF, "%c", VCARD_LF_CHAR);
    sprintf(str_photo_end, "//Z%s%s", strCRLF, strCRLF);
    nBytes = FS_Read(fh, buf, VCARD_MAX_LINE_BUFF_SIZE - 1, &bytes_read);

    if (nBytes < 0)
    {
        return 0;
    }
	nBytes = bytes_read;
    buf[nBytes] = '\0';

    if ((currCursor = strstr(buf, strLF)) != NULL)  /* find out first LF */
    {
        if ((photo_end_cursor = strstr(buf, str_photo_end)) != NULL)  /* find out photo end */
        {
            if (currCursor > photo_end_cursor)
            {
                currCursor = photo_end_cursor + 6;
            }
        }

	/*in this case, strlen is smaller than VCARD_MAX_LINE_BUFF_SIZE - 1, even if is just a signle line*/
        strLen = (S32) (currCursor - buf);
        if (buf[strLen - 1] == VCARD_CR_CHAR)
        {
            buf[strLen - 1] = '\0';
        }
        else
        {
            buf[strLen] = '\0';
        }

        FS_Seek(fh, (S32) (strLen - nBytes + 1), FS_FILE_CURRENT);
        nBytes = strLen;
    }
    else    /* CRLF not found, read until CRLF */
    {
        buf[nBytes] = '\0';
    }

    return nBytes;
}

static S32 btmtk_map_vcard_create_object_start(S32 handle, const char *object_name)
{
    U32 count = 0;
    char *buf = g_pi_map_cntx.builder_buffer;

    count += sprintf(buf, "%s:%s%s", MAP_VCARD_PROP_BEGIN, object_name, VCARD_LINE_BREAK);
  //  BTMTK_ASSERT(count <= MAP_ADP_BUFFER_SIZE);
  	if (count > MAP_ADP_BUFFER_SIZE)
  	{
  		//bt_ext_err("fail to create object start");
		
  	}
    count = FS_Write(handle, buf, count,0);
    return count;
}

static S32 btmtk_map_vcard_create_object_properties(S32 handle, const char **prop_list)
{
    U32 count = 0, i = 0;
    char *buf = g_pi_map_cntx.builder_buffer;

    if (prop_list)
    {
        while (prop_list[i])
        {
            count += sprintf((char *)(buf + count), "%s:%s%s", prop_list[i], prop_list[i + 1], VCARD_LINE_BREAK);
            i = i + 2;
        }
    }
 //   BTMTK_ASSERT(count <= MAP_ADP_BUFFER_SIZE);
 	if (count > MAP_ADP_BUFFER_SIZE)
  	{
  		//bt_ext_err("fail to create object start");
		
  	}
    count = FS_Write(handle, buf, count,0);
    return count;
}

static U32 btmtk_map_vcard_create_object_end(S32 handle, const char *object_name)
{
    U32 count = 0;
    char *buf = g_pi_map_cntx.builder_buffer;

    count += sprintf((char *) buf, "%s:%s%s", MAP_VCARD_PROP_END, object_name, VCARD_LINE_BREAK);
  //  BTMTK_ASSERT(count <= MAP_ADP_BUFFER_SIZE);
	if (count > MAP_ADP_BUFFER_SIZE)
  	{
  		//bt_ext_err("fail to create object start");
		
  	}
    count = FS_Write(handle, buf, count,0);
    return count;
}

static MBT_MAP_MSG_VERSION btmtk_map_vcard_str2version(S8* str)
{
    if (strncmp(str, MAP_VCARD_PROP_VERSION_VALUE_10, strlen(MAP_VCARD_PROP_VERSION_VALUE_10)) == 0)
    {
        return MBT_MAP_MSG_VER_10;
    }
    return MBT_MAP_MSG_VER_10;
}

static MBT_MAP_MSG_READ_STATUS btmtk_map_vcard_str2status(S8* str)
{
    if (strncmp(str, MAP_VCARD_PROP_STATUS_VALUE_READ, strlen(MAP_VCARD_PROP_STATUS_VALUE_READ)) == 0)
    {
        return MBT_MAP_MSG_STATUS_READ;
    }
    else
    {
        return MBT_MAP_MSG_STATUS_UNREAD;
    }
}

static MBT_MAP_MSG_TYPE btmtk_map_vcard_str2msgtype(S8* str)
{
    if (strncmp(str, MAP_VCARD_PROP_TYPE_VALUE_EMAIL, strlen(MAP_VCARD_PROP_TYPE_VALUE_EMAIL)) == 0)
    {
        return MBT_MAP_MSG_TYPE_EMAIL;
    }
    else if (strncmp(str, MAP_VCARD_PROP_TYPE_VALUE_SMS_GSM, strlen(MAP_VCARD_PROP_TYPE_VALUE_SMS_GSM)) == 0)
    {
        return MBT_MAP_MSG_TYPE_SMS_GSM;
    }
    else if (strncmp(str, MAP_VCARD_PROP_TYPE_VALUE_SMS_CDMA, strlen(MAP_VCARD_PROP_TYPE_VALUE_SMS_CDMA)) == 0)
    {
        return MBT_MAP_MSG_TYPE_SMS_CDMA;
    }
    else
    {
        return MBT_MAP_MSG_TYPE_MMS;
    }
}

static MBT_MAP_MSG_ENCODING btmtk_map_vcard_str2encoding(S8* str)
{
    if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_8BIT, strlen(MAP_VCARD_PROP_ENCODING_VALUE_8BIT)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_8BIT;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_G7BIT, strlen(MAP_VCARD_PROP_ENCODING_VALUE_G7BIT)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_G7BIT;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_G7BITEXT, strlen(MAP_VCARD_PROP_ENCODING_VALUE_G7BITEXT)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_G7BITEXT;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_GUCS2, strlen(MAP_VCARD_PROP_ENCODING_VALUE_GUCS2)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_GUCS2;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_G8BIT, strlen(MAP_VCARD_PROP_ENCODING_VALUE_G8BIT)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_G8BIT;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_C8BIT, strlen(MAP_VCARD_PROP_ENCODING_VALUE_C8BIT)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_C8BIT;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_CEPM, strlen(MAP_VCARD_PROP_ENCODING_VALUE_CEPM)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_CEPM;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_C7ASCII, strlen(MAP_VCARD_PROP_ENCODING_VALUE_C7ASCII)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_C7ASCII;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_CIA5, strlen(MAP_VCARD_PROP_ENCODING_VALUE_CIA5)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_CIA5;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_CUNICODE, strlen(MAP_VCARD_PROP_ENCODING_VALUE_CUNICODE)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_CUNICODE;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_CSJIS, strlen(MAP_VCARD_PROP_ENCODING_VALUE_CSJIS)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_CSJIS;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_CKOREAN, strlen(MAP_VCARD_PROP_ENCODING_VALUE_CKOREAN)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_CKOREAN;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_CLATINHEB, strlen(MAP_VCARD_PROP_ENCODING_VALUE_CLATINHEB)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_CLATINHEB;
    }
    else if (strncmp(str, MAP_VCARD_PROP_ENCODING_VALUE_CLATIN, strlen(MAP_VCARD_PROP_ENCODING_VALUE_CLATIN)) == 0)
    {
        return MBT_MAP_MSG_ENCOD_CLATIN;
    }
    else
    {
        return MBT_MAP_MSG_ENCOD_8BIT;
    }
}

static MBT_MAP_MSG_CHARSET btmtk_map_vcard_str2charset(S8* str)
{
    if (strncmp(str, MAP_VCARD_PROP_CHARSET_VALUE_UTF8, strlen(MAP_VCARD_PROP_CHARSET_VALUE_UTF8)) == 0)
    {
        return MBT_MAP_MSG_CHARSET_UTF8;
    }
    else
    {
        return MBT_MAP_MSG_CHARSET_NATIVE;
    }
}

static MBT_MAP_MSG_LANG btmtk_map_vcard_str2language(S8* str)
{
    if (strncmp(str, MAP_VCARD_PROP_LANGUAGE_VALUE_ENGLISH, strlen(MAP_VCARD_PROP_LANGUAGE_VALUE_ENGLISH)) == 0)
    {
        return MBT_MAP_MSG_LANG_ENGLISH;
    }
    else if (strncmp(str, MAP_VCARD_PROP_LANGUAGE_VALUE_FRENCH, strlen(MAP_VCARD_PROP_LANGUAGE_VALUE_FRENCH)) == 0)
    {
        return MBT_MAP_MSG_LANG_FRENCH;
    }
    else if (strncmp(str, MAP_VCARD_PROP_LANGUAGE_VALUE_SPANISH, strlen(MAP_VCARD_PROP_LANGUAGE_VALUE_SPANISH)) == 0)
    {
        return MBT_MAP_MSG_LANG_SPANISH;
    }
    else if (strncmp(str, MAP_VCARD_PROP_LANGUAGE_VALUE_JAPANESE, strlen(MAP_VCARD_PROP_LANGUAGE_VALUE_JAPANESE)) == 0)
    {
        return MBT_MAP_MSG_LANG_JAPANESE;
    }
    else if (strncmp(str, MAP_VCARD_PROP_LANGUAGE_VALUE_KOREAN, strlen(MAP_VCARD_PROP_LANGUAGE_VALUE_KOREAN)) == 0)
    {
        return MBT_MAP_MSG_LANG_KOREAN;
    }
    else if (strncmp(str, MAP_VCARD_PROP_LANGUAGE_VALUE_CHINESE, strlen(MAP_VCARD_PROP_LANGUAGE_VALUE_CHINESE)) == 0)
    {
        return MBT_MAP_MSG_LANG_CHINESE;
    }
    else if (strncmp(str, MAP_VCARD_PROP_LANGUAGE_VALUE_HEBREW, strlen(MAP_VCARD_PROP_LANGUAGE_VALUE_HEBREW)) == 0)
    {
        return MBT_MAP_MSG_LANG_HEBREW;
    }
    else if (strncmp(str, MAP_VCARD_PROP_LANGUAGE_VALUE_TURKISH, strlen(MAP_VCARD_PROP_LANGUAGE_VALUE_TURKISH)) == 0)
    {
        return MBT_MAP_MSG_LANG_TURKISH;
    }
    else if (strncmp(str, MAP_VCARD_PROP_LANGUAGE_VALUE_PORTUGUESE, strlen(MAP_VCARD_PROP_LANGUAGE_VALUE_PORTUGUESE)) == 0)
    {
        return MBT_MAP_MSG_LANG_PORTUGUESE;
    }
    else
    {
        return MBT_MAP_MSG_LANG_UNKNOWN;
    }
}

static MMI_BOOL btmtk_map_vcard_is_object_begin(S8 *str, btmtk_map_vcard_object_enum obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 *obj_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (btmtk_vcard_cmp_field(str, MAP_VCARD_PROP_BEGIN))
    {
        char *value = btmtk_vcard_get_value(str);
        switch (obj)
        {
        case MAP_VCARD_OBJECT_BMSG:
            obj_str = MAP_VCARD_OBJ_VALUE_BMSG;
            break;
        case MAP_VCARD_OBJECT_BBODY:
            obj_str = MAP_VCARD_OBJ_VALUE_BBODY;
            break;
        case MAP_VCARD_OBJECT_BENV:
            obj_str = MAP_VCARD_OBJ_VALUE_BENV;
            break;
        case MAP_VCARD_OBJECT_MSG:
            obj_str = MAP_VCARD_OBJ_VALUE_MSG;
            break;
        case MAP_VCARD_OBJECT_VCARD:
            obj_str = MAP_VCARD_OBJ_VALUE_VCARD;
            break;
        default:
            return MMI_FALSE;
        }

        if (strncmp(value, obj_str, strlen(obj_str)) == 0)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

static MMI_BOOL btmtk_map_vcard_is_object_end(S8 *str, btmtk_map_vcard_object_enum obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const S8 *obj_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (btmtk_vcard_cmp_field(str, MAP_VCARD_PROP_END))
    {
        char *value = btmtk_vcard_get_value(str);
        switch (obj)
        {
        case MAP_VCARD_OBJECT_BMSG:
            obj_str = MAP_VCARD_OBJ_VALUE_BMSG;
            break;
        case MAP_VCARD_OBJECT_BBODY:
            obj_str = MAP_VCARD_OBJ_VALUE_BBODY;
            break;
        case MAP_VCARD_OBJECT_BENV:
            obj_str = MAP_VCARD_OBJ_VALUE_BENV;
            break;
        case MAP_VCARD_OBJECT_MSG:
            obj_str = MAP_VCARD_OBJ_VALUE_MSG;
            break;
        case MAP_VCARD_OBJECT_VCARD:
            obj_str = MAP_VCARD_OBJ_VALUE_VCARD;
            break;
        default:
            return MMI_FALSE;
        }

        if (strncmp(value, obj_str, strlen(obj_str)) == 0)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

static S32 btmtk_map_vcard_read_vcard(S8 *buf, S32 fh, MMI_BOOL add_header)
{
    int len;

    if (add_header)
    {
        strcpy(buf, MAP_VCARD_PROP_BEGIN ":" MAP_VCARD_OBJ_VALUE_VCARD VCARD_LINE_BREAK);
    }
    else
    {
        buf[0] = '\0';
    }
    while (btmtk_map_vcard_get_single_line(g_pi_map_cntx.builder_buffer, fh) > 0)
    {
        strcat(buf, g_pi_map_cntx.builder_buffer);
        strcat(buf, VCARD_LINE_BREAK);
        if (btmtk_map_vcard_is_object_end(g_pi_map_cntx.builder_buffer, MAP_VCARD_OBJECT_VCARD))
        {
            len = strlen(buf);
           // BTMTK_ASSERT(len < MAP_ADP_BUFFER_SIZE);
			if (len >= MAP_ADP_BUFFER_SIZE)
  			{
  				//bt_ext_err("fail to create object start");		
  			}
            return len;
        }
    }
	len = strlen(buf);
  //  BTMTK_ASSERT(len < MAP_ADP_BUFFER_SIZE);
	if (len >= MAP_ADP_BUFFER_SIZE)
  			{
  				//bt_ext_err("fail to create object start");		
  			}
	return 0;
}
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

static btmtk_map_vcard_bmessage_prop_enum btmtk_map_vcard_get_bmsg_prop_type(S8* String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (btmtk_vcard_cmp_field(String, MAP_VCARD_PROP_VERSION))
    {
        return MAP_VCARD_BMSG_PROP_VERSION;
    }
    else if (btmtk_vcard_cmp_field(String, MAP_VCARD_PROP_STATUS))
    {
        return MAP_VCARD_BMSG_PROP_STATUS;
    }
    else if (btmtk_vcard_cmp_field(String, MAP_VCARD_PROP_TYPE))
    {
        return MAP_VCARD_BMSG_PROP_TYPE;
    }
    else if (btmtk_vcard_cmp_field(String, MAP_VCARD_PROP_FOLDER))
    {
        return MAP_VCARD_BMSG_PROP_FOLDER;
    }
    return MAP_VCARD_BMSG_PROP_NULL;
}

static btmtk_map_vcard_bbody_prop_enum btmtk_map_vcard_get_bbody_prop_type(S8* String)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (btmtk_vcard_cmp_field(String, MAP_VCARD_PROP_PARTID))
    {
        return MAP_VCARD_BBODY_PROP_PARTID;
    }
    else if (btmtk_vcard_cmp_field(String, MAP_VCARD_PROP_ENCODING))
    {
        return MAP_VCARD_BBODY_PROP_ENCODING;
    }
    else if (btmtk_vcard_cmp_field(String, MAP_VCARD_PROP_CHARSET))
    {
        return MAP_VCARD_BBODY_PROP_CHARSET;
    }
    else if (btmtk_vcard_cmp_field(String, MAP_VCARD_PROP_LANGUAGE))
    {
        return MAP_VCARD_BBODY_PROP_LANGUAGE;
    }
    else if (btmtk_vcard_cmp_field(String, MAP_VCARD_PROP_LENGTH))
    {
        return MAP_VCARD_BBODY_PROP_LENGTH;
    }
    return MAP_VCARD_BBODY_PROP_NULL;
}

MMI_BOOL btmtk_map_vcard_create_message_by_buffer(S8 mas_index, 
                                                      MBT_MAP_FRAC_REQ frac_req, 
                                                      MBT_MAP_FRAC_DELIVER frac_deliv,
                                                      MBT_MAP_MSG_OBJECT *msg,
                                                      S32 rhandle,
                                                      U32 file_size
													  )
{
    kal_uint8 filename[MAX_FILE_NAME];
    S32 fhandle, level = 0;
    S32 index =0;
	S32 msgcount = 0;
	S32 msglength = 0;
    char n_buf1[32], n_buf2[32];
	U32 bytes_read =0;
	U32 bytes_written =0;

    kal_wsprintf(( WCHAR *)filename, BT_MAP_MESSAGE_GET_FILE, mas_index);

	FS_Delete((WCHAR*)filename);

    if ((fhandle = FS_Open((WCHAR*)filename, FS_READ_WRITE | FS_CREATE)) < 0)
    {
        return MMI_FALSE;
    }

    if (frac_req != MBT_MAP_FRAC_REQ_NEXT)
    {
 		MBT_MAP_MAS_STATUS *status = btmtk_map_util_search_mas_instance(mas_index);
        const char *prop_list[MAP_VCARD_BMSG_PROP_TOTAL * 2 + 1];
        int i = 0;

        /* BEGIN:BMSG */
        btmtk_map_vcard_create_object_start(fhandle, MAP_VCARD_OBJ_VALUE_BMSG);

        prop_list[i++] = MAP_VCARD_PROP_VERSION;
        prop_list[i++] = MAP_VCARD_PROP_VERSION_VALUE_10;
        prop_list[i++] = MAP_VCARD_PROP_STATUS;
        prop_list[i++] = btmtk_map_vcard_get_status_string(msg->ReadStatus);
        prop_list[i++] = MAP_VCARD_PROP_TYPE;
        prop_list[i++] = btmtk_map_vcard_get_msg_type_string(msg->MsgType);
		if(msg->FolderPath){
        prop_list[i++] = MAP_VCARD_PROP_FOLDER;
			prop_list[i++] = msg->FolderPath;
		}
		else if (status) 
		{
		    prop_list[i++] = (const char*)btmtk_map_util_get_virtual_folder_path((unsigned char*)status->CurFolderPath, (unsigned char*)status->masInfo.RootPath);
		} else {
		    //bt_ext_err("[BT][MAP][EXT]btmtk_map_vcard_create_message_by_buffer: status is null");
		}


//        prop_list[i++] = msg->FolderPath;
        prop_list[i] = NULL;
        btmtk_map_vcard_create_object_properties(fhandle, prop_list);
        if (msg->OriginatorSize && msg->Originator)
        {
            FS_Write(fhandle, msg->Originator, msg->OriginatorSize, (U32*)&bytes_written);
            FS_Write(fhandle, VCARD_LINE_BREAK, 2, (U32*)&bytes_written);
        }


        /* BEGIN:BENV */
        for (index = 0; index < MBT_MAP_MAX_MSG_ENVELOPE_NUM;index ++)
        {
            btmtk_map_vcard_create_object_start(fhandle, MAP_VCARD_OBJ_VALUE_BENV);
	    level++;
            if (msg->Envelope[index].RecipientSize && msg->Envelope[index].Recipient)
            {
            	FS_Write(fhandle, msg->Envelope[index].Recipient, msg->Envelope[index].RecipientSize, (U32*)&bytes_written);
                FS_Write(fhandle, VCARD_LINE_BREAK, 2, (U32*)&bytes_written);
            }
            else
            {

                break;
            }
        }
        
    }

    /* BEGIN:BBODY */
    btmtk_map_vcard_create_object_start(fhandle, MAP_VCARD_OBJ_VALUE_BBODY);
    {
        int i = 0;
        const char *prop_list[MAP_VCARD_BBODY_PROP_TOTAL * 2 + 1];
        char* value = NULL;
        if (frac_deliv != MBT_MAP_FRAC_DELIVER_NO)
        {
            prop_list[i++] = MAP_VCARD_PROP_PARTID;
            sprintf(n_buf1, "%d", msg->PartId);
            prop_list[i++] = n_buf1;
        }
			value = (char*)btmtk_map_vcard_get_encoding_string(msg->Encoding);
			if (value != NULL)
			{
        prop_list[i++] = MAP_VCARD_PROP_ENCODING;
  	 			prop_list[i++] = value;
			}
			value = (char*)btmtk_map_vcard_get_charset_string(msg->Charset);
			if(value!= NULL)
			{
        prop_list[i++] = MAP_VCARD_PROP_CHARSET;
        	prop_list[i++] = value;
			}
			value = (char*)btmtk_map_vcard_get_language_string(msg->Lang);
			if (value != NULL)
			{
        prop_list[i++] = MAP_VCARD_PROP_LANGUAGE;
  		      prop_list[i++] = value;
			}
        prop_list[i++] = MAP_VCARD_PROP_LENGTH;
        	sprintf(n_buf2, "%d", msg->ContentSize + (MAP_VCARD_OBJ_VALUE_MSG_SHELL_LEN) * msg->FragmentNum);
        prop_list[i++] = n_buf2;
        prop_list[i] = NULL;
        btmtk_map_vcard_create_object_properties(fhandle, prop_list);
    }

	/*MSG group*/
	while (msgcount < msg->FragmentNum) 
	{   
    /* BEGIN:MSG */
    btmtk_map_vcard_create_object_start(fhandle, MAP_VCARD_OBJ_VALUE_MSG);
    if (rhandle >= 0)
    {
        	int read, buffersize, remain = msg->FragmentSize[msgcount];

        while (remain > 0)
        {
        		buffersize = (remain < MAP_ADP_BUFFER_SIZE) ? remain : MAP_ADP_BUFFER_SIZE;
            	if((read = FS_Read(rhandle, g_pi_map_cntx.file_buffer, buffersize, &bytes_read)) < 0)
            {
                FS_Close(fhandle);
                return MMI_FALSE;
            }
	    		if (read < 0)
	   			{
					break;
	    		}
			read = bytes_read;
            remain -= read;
            if((FS_Write(fhandle, g_pi_map_cntx.file_buffer, read, (U32*)&bytes_written)) < 0)
            {
                FS_Close(fhandle);
                return MMI_FALSE;
            }
			
        }
        }
    else
    {
    		if (FS_Write(fhandle, (msg->Content + msglength), msg->FragmentSize[msgcount], (U32*)&bytes_written) < 0)
    		{
				return MMI_FALSE;
    }
    else
    {
				msglength += msg->FragmentSize[msgcount];
    }
    	}
        FS_Write(fhandle, VCARD_LINE_BREAK, 2, (U32*)&bytes_written);

    /* END:MSG */
    btmtk_map_vcard_create_object_end(fhandle, MAP_VCARD_OBJ_VALUE_MSG);
   
		msgcount++;	

	}
    /* END:BBODY */
    btmtk_map_vcard_create_object_end(fhandle, MAP_VCARD_OBJ_VALUE_BBODY);

    /* END:BENV */
    /* END:BMSG */
    if (frac_req != MBT_MAP_FRAC_REQ_NEXT)
    {
        for (; level > 0; level--)
        {
            btmtk_map_vcard_create_object_end(fhandle, MAP_VCARD_OBJ_VALUE_BENV);
        }
        btmtk_map_vcard_create_object_end(fhandle, MAP_VCARD_OBJ_VALUE_BMSG);
    }

    FS_Close(fhandle);
    return MMI_TRUE;
}

MMI_BOOL btmtk_map_vcard_create_message_by_file(S8 mas_index, 
                                                    MBT_MAP_FRAC_REQ frac_req, 
                                                    MBT_MAP_FRAC_DELIVER frac_deliv,
                                                    MBT_MAP_MSG_OBJECT *msg, 
                                                    U32 file_size, 
                                                    kal_wchar *file_name)
{
    S32 fhandle = 0;
    
    if ((fhandle = FS_Open((WCHAR*)file_name, FS_READ_ONLY)) < 0)
    {
        return MMI_FALSE;
    }

    if (btmtk_map_vcard_create_message_by_buffer(mas_index, frac_req, frac_deliv, msg, fhandle, file_size) == MMI_FALSE)
    {
        FS_Close(fhandle);
        return MMI_FALSE;
    }

    FS_Close(fhandle);
    return MMI_TRUE;
}

/*Usage: extract message body part from bMessage content,                     		*/
/*		especially when that message content contains multi bodies, eg.SMS     	*/
/*Notes: if body size is known, no need to call this API                              		*/
MMI_BOOL btmtk_map_vcard_extract_content_body_by_single_line(S32 fhandle,MBT_MAP_MSG_OBJECT *msg, kal_wchar *to_file)
{
	S32 whandle;
	S32 count = 0;
	MMI_BOOL ret = MMI_TRUE;
	MMI_BOOL endOfLine = MMI_FALSE;
	U32 bytes_written =0;
	U32 filesize = 0;
	//bt_ext_log("[MAP][EXT]btmtk_map_vcard_extract_content_body_by_single_line");
	if ((msg == NULL)
		|| (to_file == NULL) 
		|| (whandle = FS_Open((WCHAR *)to_file, FS_OPEN_SHARED | FS_CREATE)) < 0)
	{
		return MMI_FALSE;
	}
	FS_GetFileSize(whandle , &filesize);
	FS_Seek(whandle, filesize, FS_FILE_BEGIN);
	while ((count = btmtk_map_vcard_get_single_line(g_pi_map_cntx.file_buffer, fhandle)) >= 0)
    {            
		/*when  arriving end to file or end to single line, */
        if ((count < VCARD_MAX_LINE_BUFF_SIZE - 1))
        {
        	/*Notes: btmtk_map_vcard_get_single_line return the actual string length plus 1*/
			count --;
			msg->FragmentSize[msg->FragmentNum] += count;
			msg->ContentSize -= MAP_VCARD_OBJ_VALUE_MSG_SHELL_LEN;
			msg->FragmentNum++;
			//bt_ext_log("end for current body");
			endOfLine = MMI_TRUE;
        }
		else
		{
			/*Notes: notice the case that \r and \n happen to be seperated, so we just seek back one byte to avoid it */
        	FS_Seek(fhandle, -1, FS_FILE_CURRENT);
			count--;
			msg->FragmentSize[msg->FragmentNum] += count;
			//bt_ext_log("keep going");
		}
		if(FS_Write(whandle, g_pi_map_cntx.file_buffer, count, (U32*)&bytes_written) < 0 || endOfLine)
        {
        	break;
        }	
	}
	FS_Close(whandle);
	return ret;
}


MMI_BOOL btmtk_map_vcard_extract_content_body_by_size(S32 fhandle,MBT_MAP_MSG_OBJECT *msg, kal_wchar *to_file, U32 *msg_buf_size)
{
	MMI_BOOL ret = MMI_TRUE;	
	U32 size;
	U32 bytes_read = 0;
	U32 bytes_written = 0;
	msg->ContentSize -= MAP_VCARD_OBJ_VALUE_MSG_SHELL_LEN;
	size = msg->ContentSize;


	//bt_ext_log("[MAP][EXT]btmtk_map_vcard_extract_content_body_by_size");
	if (*msg_buf_size < size)
	{
		S32 whandle, current, read, remain = size;
		if ((whandle = FS_Open((WCHAR*)to_file, FS_OPEN_SHARED | FS_CREATE)) >= 0)
		{
			while (remain > 0)
			{
				current = (remain < MAP_ADP_BUFFER_SIZE)? remain : MAP_ADP_BUFFER_SIZE;
				//bt_ext_log("remain is %d", remain);
				if((read = FS_Read(fhandle, g_pi_map_cntx.file_buffer, current, &bytes_read)) < 0)
				{
					break;
				}
				remain -= read;
				if(FS_Write(whandle, g_pi_map_cntx.file_buffer, read, (U32*)&bytes_written) < 0)
				{
				   break;
				}
			}   
			FS_Close(whandle);
		}

		
	}
	else
	{
		S32 length;
		length = FS_Read(fhandle, msg->Content, size, &bytes_read);
		*msg_buf_size -= length;
	}
	msg->FragmentSize[msg->FragmentNum] = size;
	msg->FragmentNum ++;
	return ret;
}



MMI_BOOL btmtk_map_vcard_parse_message_by_buffer(S8 mas_index,
                                                MBT_MAP_MSG_OBJECT *msg,
                                                U32 msg_buf_size,
                                                kal_wchar *to_file)
{
    kal_uint8 filename[MAX_FILE_NAME];
    S32 fhandle, count, benv_level = 0;
	U8 index = 0;
	U32 bufferSize = msg_buf_size;
	kal_mem_set(msg,0,sizeof(MBT_MAP_MSG_OBJECT));


	if (msg == NULL)
	{
		//bt_ext_err("input msg is null");
		return MMI_FALSE;
	}
    if (mmi_wcslen(to_file) == 0)
	{
    	kal_wsprintf(( WCHAR *)to_file, BT_MAP_TMP_FILE, mas_index);
    }
    FS_Delete((WCHAR*)to_file);
	//fisrt clear memory if memory has not been released
	if (msg->Originator)
	{
		OslMfree(msg->Originator);
		msg->Originator = NULL;
	}
	for( ;index < MBT_MAP_MAX_MSG_ENVELOPE_NUM; index++)
	{
		if (msg->Envelope[index].Recipient) 
		{
			OslMfree(msg->Envelope[index].Recipient);
			msg->Envelope[index].Recipient = NULL;
		}
	}
	
    kal_wsprintf(( WCHAR *)filename, BT_MAP_RCV_MESSAGE_PUSH_FILE, mas_index);
    if ((fhandle = FS_Open((WCHAR*)filename, FS_READ_ONLY)) < 0)
    {
        return MMI_FALSE;
    }
    
    while ((count = btmtk_map_vcard_get_single_line(g_pi_map_cntx.file_buffer, fhandle)) > 0)
    {
        /* BEGIN:BMSG */
        if (btmtk_map_vcard_is_object_begin(g_pi_map_cntx.file_buffer, MAP_VCARD_OBJECT_BMSG))
        {
            MMI_BOOL in_bmsg = MMI_TRUE;
            while (in_bmsg && (count = btmtk_map_vcard_get_single_line(g_pi_map_cntx.file_buffer, fhandle)) > 0)
            {
                btmtk_map_vcard_bmessage_prop_enum prop = 
                    btmtk_map_vcard_get_bmsg_prop_type(g_pi_map_cntx.file_buffer);
                char *prop_value = btmtk_vcard_get_value(g_pi_map_cntx.file_buffer);
                
                switch (prop)
                {
                case MAP_VCARD_BMSG_PROP_VERSION:
                    msg->MsgVer = btmtk_map_vcard_str2version(prop_value);
                    break;
                case MAP_VCARD_BMSG_PROP_STATUS:
                    msg->ReadStatus = btmtk_map_vcard_str2status(prop_value);
                    break;
                case MAP_VCARD_BMSG_PROP_TYPE:
                    msg->MsgType = btmtk_map_vcard_str2msgtype(prop_value);
                    break;
                case MAP_VCARD_BMSG_PROP_FOLDER:
                    strcpy(msg->FolderPath, prop_value);
                    break;
                default:
                    FS_Seek(fhandle, 0 - count - 1, FS_FILE_CURRENT);
                    in_bmsg = MMI_FALSE;
                    break;
                }
            }
        }
        else if (btmtk_map_vcard_is_object_begin(g_pi_map_cntx.file_buffer, MAP_VCARD_OBJECT_VCARD))
        {
            /* BEGIN:VCARD */
            int len;
            FS_Seek(fhandle, 0 - count - 1, FS_FILE_CURRENT);
            len = btmtk_map_vcard_read_vcard(g_pi_map_cntx.file_buffer, fhandle, MMI_FALSE);
        
          	if (len > MAP_ADP_BUFFER_SIZE)
  			{
  				//bt_ext_err("fail to create object start");		
  			}
			//bt_ext_log("benv_level is %d, len is %d", benv_level, len);
            if (benv_level == 0)
            {
            	msg->OriginatorSize = len;
				msg->Originator = (char*)OslMalloc(len+1);
		if (msg->Originator == NULL) 
		{
		    //bt_ext_err("fail to allocate memory for msg->Originator");
		    continue;
		}
                strncpy(msg->Originator, g_pi_map_cntx.file_buffer, msg->OriginatorSize);
		msg->Originator[len] = '\0';
  			
            }
            else
            {
            	msg->Envelope[benv_level - 1].RecipientSize = len;
				
				msg->Envelope[benv_level - 1].Recipient = OslMalloc(len+1);				
		if (msg->Envelope[benv_level - 1].Recipient == NULL) 
	        {
		    //bt_ext_err("fail to allocate memory for msg->Envelope[%d - 1].Recipient", benv_level);
		    continue;
		}
                strncpy(msg->Envelope[benv_level - 1].Recipient, 
                        g_pi_map_cntx.file_buffer, 
                        msg->Envelope[benv_level - 1].RecipientSize);
			//	msg->Originator[len] = '\0';
		msg->Envelope[benv_level - 1].Recipient[len] = '\0';
//                msg->Envelope[benv_level - 1].RecipientSize = strlen(g_pi_map_cntx.file_buffer);
            }
        }
        else if (btmtk_map_vcard_is_object_begin(g_pi_map_cntx.file_buffer, MAP_VCARD_OBJECT_BENV))
        {
            /* BEGIN:BENV */
            benv_level++;
        }
        else if (btmtk_map_vcard_is_object_begin(g_pi_map_cntx.file_buffer, MAP_VCARD_OBJECT_BBODY))
        {	
        	//TODO: notice the case that Bmessage contains multi Bbody
            /* BEGIN:BBODY */
            MMI_BOOL in_bbody = MMI_TRUE;
            while (in_bbody && (count = btmtk_map_vcard_get_single_line(g_pi_map_cntx.file_buffer, fhandle)) > 0)
            {
                btmtk_map_vcard_bbody_prop_enum prop = 
                    btmtk_map_vcard_get_bbody_prop_type(g_pi_map_cntx.file_buffer);
                char *prop_value = btmtk_vcard_get_value(g_pi_map_cntx.file_buffer);
                
                switch (prop)
                {
                case MAP_VCARD_BBODY_PROP_PARTID:
                    msg->PartId = (U16) atoi(prop_value);
                    break;
                case MAP_VCARD_BBODY_PROP_ENCODING:
                    msg->Encoding = btmtk_map_vcard_str2encoding(prop_value);
                    break;
                case MAP_VCARD_BBODY_PROP_CHARSET:
                    msg->Charset = btmtk_map_vcard_str2charset(prop_value);
                    break;
                case MAP_VCARD_BBODY_PROP_LANGUAGE:
                    msg->Lang = btmtk_map_vcard_str2language(prop_value);
                    break;
                case MAP_VCARD_BBODY_PROP_LENGTH:
         //           msg->ContentSize += (U32) atoi(prop_value);
		 //   msg->FragmentSize[msg->FragmentNum++] = (U32) atoi(prop_value);
		      msg->ContentSize = (U32) atoi(prop_value);
                    break;
                default:
                    FS_Seek(fhandle, 0 - count - 1, FS_FILE_CURRENT);
                    in_bbody = MMI_FALSE;
                    break;
                }
            }
        }
        else if (btmtk_map_vcard_is_object_begin(g_pi_map_cntx.file_buffer, MAP_VCARD_OBJECT_MSG))
	{
            /* BEGIN:MSG */
            if (msg->MsgType == MBT_MAP_MSG_TYPE_SMS_CDMA ||
				msg->MsgType == MBT_MAP_MSG_TYPE_SMS_GSM)
                        {
	    	btmtk_map_vcard_extract_content_body_by_single_line(fhandle, msg, to_file);
            }
            else
            {
			btmtk_map_vcard_extract_content_body_by_size(fhandle, msg, to_file, &bufferSize);
            }
        }
    }

    FS_Close(fhandle);
    return MMI_TRUE;
}

MMI_BOOL btmtk_map_vcard_parse_message_by_file(S8 mas_index,
                                                     MBT_MAP_MSG_OBJECT *msg,
                                                     U32 *file_size,
                                                     kal_wchar *file_name)
{
    return btmtk_map_vcard_parse_message_by_buffer(mas_index, msg, 0, file_name);
}

MBT_MAP_MAS_STATUS *btmtk_map_util_search_mas_instance(unsigned char instance)
{
	U8 i;
	for(i = 0; i < MBT_MAP_MAX_MAS_INST_NUM; i++) 
	{
		if((g_pi_map_cntx.masStatus[i].registered == KAL_TRUE) && 
			(g_pi_map_cntx.masStatus[i].masInfo.MasInstId == instance))
		{
			return &g_pi_map_cntx.masStatus[i];
		}
	}
	return NULL;

}

unsigned char *btmtk_map_util_get_virtual_folder_path(unsigned char *physical_path, unsigned char *physical_root_path)
{
    if (strstr((const char*)physical_path, (const char*)physical_root_path) == physical_path)
    {
        unsigned char *vf = physical_path + strlen((const char*)physical_root_path);
        if (*vf == '/')
        {
            vf++;
        }
        return vf;
    }
    return NULL;
}
#endif 
