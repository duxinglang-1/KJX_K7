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
 * jbt_main.c
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
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JBT_UT_C
#define _JBT_UT_C

#ifdef __SUPPORT_JBT__

#include "kal_release.h"        /* Basic data type */
#include "stack_common.h"       /* message and module IDs */
#include "stack_msgs.h" /* enum for message IDs */
#include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"     /* type of system module components */
#include "task_config.h"        /* Task creation */
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "uart_sw.h"
#include "bluetooth_struct.h"
#include "bluetooth_bm_struct.h"
#include "mmiapi_bt_struct.h"
#include "jbt_interface.h"
#include "jbt_internal.h"
#include "j2me_trace.h"

/* For file usage API definition */
#include "fs_type.h"
#include "fs_errcode.h"
#include "fs_func.h"

/* Service Discovery Protocol */
#define PROT_SDP                     0x0001

/* UDP Protocol */
#define PROT_UDP                     0x0002

/* RFCOMM Protocol */
#define PROT_RFCOMM                  0x0003

/* TCP Protocol */
#define PROT_TCP                     0x0004

/* TCS Binary Protocol */
#define PROT_TCS_BIN                 0x0005

/* TCS-AT Protocol */
#define PROT_TCS_AT                  0x0006

/* OBEX Protocol */
#define PROT_OBEX                    0x0008

/* IP Protocol */
#define PROT_IP                      0x0009

/* FTP Protocol */
#define PROT_FTP                     0x000A

/* HTTP Protocol */
#define PROT_HTTP                    0x000C

/* WSP Protocol */
#define PROT_WSP                     0x000E

/* BNEP Protocol */
#define PROT_BNEP                    0x000F

/* Universal Plug and Play */
#define PROT_UPNP                    0x0010

/* Human Interface Device Profile */
#define PROT_HIDP                    0x0011

/* Hardcopy Cable Replacement Control Channel */
#define PROT_HCR_CONTROL_CHANNEL     0x0012

/* Hardcopy Cable Replacement Data Channel */
#define PROT_HCR_DATA_CHANNEL        0x0014

/* Hardcopy Cable Replacement Notification */
#define PROT_HCR_NOTIFICATION        0x0016

/* Audio/Video Control Transport Protocol */
#define PROT_AVCTP                   0x0017

/* Audio/Video Distribution Transport Protocol */
#define PROT_AVDTP                   0x0019

/* CAPI Message Transport Protocol */
#define PROT_CMPT                    0x001B

/* Unrestricted Digital Information Control Plane */
#define PROT_UDI_C                   0x001D

/* L2CAP Protocol */
#define PROT_L2CAP                   0x0100

#define AID_SERVICE_RECORD_HANDLE               0x0000
#define AID_SERVICE_CLASS_ID_LIST               0x0001
#define AID_SERVICE_RECORD_STATE                0x0002
#define AID_SERVICE_ID                          0x0003
#define AID_PROTOCOL_DESC_LIST                  0x0004
#define AID_BROWSE_GROUP_LIST                   0x0005
#define AID_LANG_BASE_ID_LIST                   0x0006
#define AID_SERVICE_INFO_TIME_TO_LIVE           0x0007
#define AID_SERVICE_AVAILABILITY                0x0008
#define AID_BT_PROFILE_DESC_LIST                0x0009
#define AID_DOC_URL                             0x000a
#define AID_CLIENT_EXEC_URL                     0x000b
#define AID_ICON_URL                            0x000c
#define AID_ADDITIONAL_PROT_DESC_LISTS          0x000d
#define AID_SERVICE_NAME                        0x0000
#define AID_SERVICE_DESCRIPTION                 0x0001
#define AID_PROVIDER_NAME                       0x0002
#define AID_IP_SUBNET                           0x0200
#define AID_GROUP_ID                            0x0200
#define AID_VERSION_NUMBER_LIST                 0x0200
#define AID_SERVICE_DATABASE_STATE              0x0201
#define AID_SERVICE_VERSION                     0x0300
#define AID_EXTERNAL_NETWORK                    0x0301
#define AID_SUPPORTED_DATA_STORES_LIST          0x0301
#define AID_FAX_CLASS_1_SUPPORT                 0x0302
#define AID_REMOTE_AUDIO_VOL_CONTROL            0x0302
#define AID_FAX_CLASS_20_SUPPORT                0x0303
#define AID_SUPPORTED_FORMATS_LIST              0x0303
#define AID_FAX_CLASS_2_SUPPORT                 0x0304
#define AID_AUDIO_FEEDBACK_SUPPORT              0x0305
#define AID_NETWORK_ADDRESS                     0x0306
#define AID_WAP_GATEWAY                         0x0307
#define AID_HOME_PAGE_URL                       0x0308
#define AID_WAP_STACK_TYPE                      0x0309
#define AID_SECURITY_DESC                       0x030A
#define AID_NET_ACCESS_TYPE                     0x030B
#define AID_MAX_NET_ACCESS_RATE                 0x030C
#define AID_IPV4_SUBNET                         0x030D
#define AID_IPV6_SUBNET                         0x030E
#define AID_SUPPORTED_CAPABILITIES              0x0310
#define AID_SUPPORTED_FEATURES                  0x0311
#define AID_SUPPORTED_FUNCTIONS                 0x0312
#define AID_TOTAL_IMAGE_DATA_CAPACITY           0x0313
#define AID_SUPPORTED_REPOSITORIES              0x0314  /* Awaiting for an official value from CAR WG */
#define AID_SUPPORTED_DOC_FORMATS               0x0350
#define AID_SUPPORTED_CHAR_REPERTOIRES          0x0352
#define AID_SUPPORTED_XHTML_IMAGE_FORMATS       0x0354
#define AID_COLOR_SUPPORTED                     0x0356
#define AID_PRINTER_1284ID                      0x0358
#define AID_DUPLEX_SUPPORTED                    0x035E
#define AID_SUPPORTED_MEDIA_TYPES               0x0360
#define AID_MAX_MEDIA_WIDTH                     0x0362
#define AID_MAX_MEDIA_LENGTH                    0x0364
#define AID_HID_DEVICE_RELEASE        0x0200
#define AID_HID_PARSER_VERSION        0x0201
#define AID_HID_DEVICE_SUBCLASS       0x0202
#define AID_HID_COUNTRY_CODE          0x0203
#define AID_HID_VIRTUAL_CABLE         0x0204
#define AID_HID_RECONNECT_INIT        0x0205
#define AID_HID_DESCRIPTOR_LIST       0x0206
#define AID_HID_LANG_ID_BASE_LIST     0x0207
#define AID_HID_SDP_DISABLE           0x0208
#define AID_HID_BATTERY_POWER         0x0209
#define AID_HID_REMOTE_WAKE           0x020A
#define AID_HID_PROFILE_VERSION       0x020B
#define AID_HID_SUPERV_TIMEOUT        0x020C
#define AID_HID_NORM_CONNECTABLE      0x020D
#define AID_HID_BOOT_DEVICE           0x020E

#define DESD_1BYTE      0x00
#define DESD_2BYTES     0x01
#define DESD_4BYTES     0x02
#define DESD_8BYTES     0x03
#define DESD_16BYTES    0x04
#define DESD_ADD_8BITS  0x05
#define DESD_ADD_16BITS 0x06
#define DESD_ADD_32BITS 0x07
#define DESD_MASK       0x07

#define DETD_NIL  0x00
#define DETD_UINT 0x08
#define DETD_SINT 0x10
#define DETD_UUID 0x18
#define DETD_TEXT 0x20
#define DETD_BOOL 0x28
#define DETD_SEQ  0x30
#define DETD_ALT  0x38
#define DETD_URL  0x40
#define DETD_MASK 0xf8

#define SC_SERVICE_DISCOVERY_SERVER             0x1000
#define SC_BROWSE_GROUP_DESC                    0x1001
#define SC_PUBLIC_BROWSE_GROUP                  0x1002
#define SC_SERIAL_PORT                          0x1101
#define SC_LAN_ACCESS_PPP                       0x1102
#define SC_DIALUP_NETWORKING                    0x1103
#define SC_IRMC_SYNC                            0x1104
#define SC_OBEX_OBJECT_PUSH                     0x1105
#define SC_OBEX_FILE_TRANSFER                   0x1106
#define SC_IRMC_SYNC_COMMAND                    0x1107
#define SC_HEADSET                              0x1108
#define SC_CORDLESS_TELEPHONY                   0x1109
#define SC_AUDIO_SOURCE                         0x110A
#define SC_AUDIO_SINK                           0x110B
#define SC_AV_REMOTE_CONTROL_TARGET             0x110C
#define SC_AUDIO_DISTRIBUTION                   0x110D
#define SC_AV_REMOTE_CONTROL                    0x110E
#define SC_VIDEO_CONFERENCING                   0x110F
#define SC_INTERCOM                             0x1110
#define SC_FAX                                  0x1111
#define SC_HEADSET_AUDIO_GATEWAY                0x1112
#define SC_WAP                                  0x1113
#define SC_WAP_CLIENT                           0x1114
#define SC_PANU                                 0x1115
#define SC_NAP                                  0x1116
#define SC_GN                                   0x1117
#define SC_DIRECT_PRINTING                      0x1118
#define SC_REFERENCE_PRINTING                   0x1119
#define SC_IMAGING                              0x111A
#define SC_IMAGING_RESPONDER                    0x111B
#define SC_IMAGING_AUTOMATIC_ARCHIVE            0x111C
#define SC_IMAGING_REFERENCED_OBJECTS           0x111D
#define SC_HANDSFREE                            0x111E
#define SC_HANDSFREE_AUDIO_GATEWAY              0x111F
#define SC_DIRECT_PRINTING_REF_OBJECTS          0x1120
#define SC_REFLECTED_UI                         0x1121
#define SC_BASIC_PRINTING                       0x1122
#define SC_PRINTING_STATUS                      0x1123
#define SC_HUMAN_INTERFACE_DEVICE               0x1124
#define SC_HCR                                  0x1125
#define SC_HCR_PRINT                            0x1126
#define SC_HCR_SCAN                             0x1127
#define SC_ISDN                                 0x1128
#define SC_VIDEO_CONFERENCING_GW                0x1129
#define SC_UDI_MT                               0x112A

/* Unrestricted Digital Information Terminal Adapter */
#define SC_UDI_TA                               0x112B

/* Audio Video service */
#define SC_AUDIO_VIDEO                          0x112C

/* SIM Access Profile */
#define SC_SIM_ACCESS                           0x112D

/* Phonebook Access Client */
#define SC_PBAP_CLIENT                          0x112E

/* Phonebook Access Server */
#define SC_PBAP_SERVER                          0x112F

/* Plug-n-Play service */
#define SC_PNP_INFO                             0x1200

/* Generic Networking service. */
#define SC_GENERIC_NETWORKING                   0x1201

/* Generic File Transfer service. */
#define SC_GENERIC_FILE_TRANSFER                0x1202

/* Generic Audio service. */
#define SC_GENERIC_AUDIO                        0x1203

/* Generic Telephony service. */
#define SC_GENERIC_TELEPHONY                    0x1204

/* UPnP L2CAP based profile. */
#define SC_UPNP_SERVICE                         0x1205

/* UPnP IP based profile. */
#define SC_UPNP_IP_SERVICE                      0x1206

/* UPnP IP based solution using PAN */
#define SC_ESDP_UPNP_IP_PAN                     0x1300

/* UPnP IP based solution using LAP */
#define SC_ESDP_UPNP_IP_LAP                     0x1301

/* UPnP L2CAP based solution */
#define SC_ESDP_UPNP_L2CAP                      0x1302

#define BT_APP_SDP_ATTRIBUTE_ID(x)                                            \
            (kal_uint8)(((x) & 0xff00) >> 8),    /* Bits[15:8] of UUID */     \
            (kal_uint8)((x) & 0x00ff)   /* Bits[7:0] of UUID */

#define SDP_ATTRIB_HEADER_8BIT(size)                                     \
            DETD_SEQ + DESD_ADD_8BITS,      /* Type & size index 0x35 */ \
            size        /* 8-bit size */

/* Add by mtk01411: 2007-1125 */
#define SDP_TEXT_32BIT(size)                                                 \
            DETD_TEXT + DESD_ADD_32BITS,        /* Type & size index 0x27 */ \
            (U8)(((size) & 0xff000000) >> 24),  /* Bits[32:24] of size */    \
            (U8)(((size) & 0x00ff0000) >> 16),  /* Bits[23:16] of size */    \
            (U8)(((size) & 0x0000ff00) >> 8),   /* Bits[15:8] of size */     \
            (U8)((size) & 0x000000ff)   /* Bits[7:0] of size */

#define SDP_UUID_16BIT(uuid)                                                     \
            DETD_UUID + DESD_2BYTES,         /* Type & size index 0x19 */        \
            (kal_uint8)(((uuid) & 0xff00) >> 8),    /* Bits[15:8] of UUID */     \
            (kal_uint8)((uuid) & 0x00ff)        /* Bits[7:0] of UUID */

#define SDP_TEXT_8BIT(size)                                               \
            DETD_TEXT + DESD_ADD_8BITS,      /* Type & size index 0x25 */ \
            (kal_uint8)(size)   /* 8-bit size */

#define SDP_UINT_8BIT(uint)                                               \
            DETD_UINT + DESD_1BYTE,          /* Type & size index 0x08 */ \
            (kal_uint8)(uint)   /* 8-bit UINT */

#define SDP_UINT_16BIT(uint)                                                     \
            DETD_UINT + DESD_2BYTES,         /* Type & size index 0x09 */        \
            (kal_uint8)(((uint) & 0xff00) >> 8),    /* Bits[15:8] of UINT */     \
            (kal_uint8)((uint) & 0x00ff)        /* Bits[7:0] of UINT */

#define SDP_UINT_32BIT(uint)                                                        \
            DETD_UINT + DESD_4BYTES,            /* Type & size index 0x0A */        \
            (kal_uint8)(((uint) & 0xff000000) >> 24),  /* Bits[31:24] of UINT */    \
            (kal_uint8)(((uint) & 0x00ff0000) >> 16),  /* Bits[23:16] of UINT */    \
            (kal_uint8)(((uint) & 0x0000ff00) >> 8),   /* Bits[15:8] of UINT */     \
            (kal_uint8)((uint) & 0x000000ff)    /* Bits[7:0] of UINT */

#define SDP_UINT_64BIT(uint)                    /* UINT must be an 8-byte array */ \
            DETD_UINT + DESD_8BYTES,            /* Type & size index 0x0B */       \
            uint        /* 64-bit UINT */

/*---------------------------------------------------------------------------
 * SDP_UINT_128BIT()
 *
 *     Macro that forms a UINT Data Element from the supplied 128-bit UINT value. 
 *     UINT data elements are used in SDP Record Attributes and SDP Queries.
 *
 * Parameters:
 *     uint - 128-bit UINT value.
 */
#define SDP_UINT_128BIT(uint)                   /* UINT must be a 16-byte array */ \
            DETD_UINT + DESD_16BYTES,           /* Type & size index 0x0C */       \
            uint        /* 128-bit UINT */

kal_uint8 bt_sdp_test_pattern[] = 
{
    BT_APP_SDP_ATTRIBUTE_ID(AID_SERVICE_CLASS_ID_LIST),
    SDP_ATTRIB_HEADER_8BIT(3),
    SDP_UUID_16BIT(SC_OBEX_OBJECT_PUSH),

    BT_APP_SDP_ATTRIBUTE_ID(AID_PROTOCOL_DESC_LIST),
    SDP_ATTRIB_HEADER_8BIT(12), SDP_ATTRIB_HEADER_8BIT(3),
    SDP_UUID_16BIT(PROT_L2CAP), SDP_ATTRIB_HEADER_8BIT(5),
    SDP_UUID_16BIT(PROT_RFCOMM), SDP_UINT_8BIT(0x05),

    BT_APP_SDP_ATTRIBUTE_ID(AID_BROWSE_GROUP_LIST),
    SDP_ATTRIB_HEADER_8BIT(3), SDP_UUID_16BIT(SC_PUBLIC_BROWSE_GROUP),

    BT_APP_SDP_ATTRIBUTE_ID(AID_LANG_BASE_ID_LIST),
    SDP_ATTRIB_HEADER_8BIT(9), SDP_UINT_16BIT(0x656E),
    SDP_UINT_16BIT(0x006A), SDP_UINT_16BIT(0x0100),

    BT_APP_SDP_ATTRIBUTE_ID(AID_BT_PROFILE_DESC_LIST),
    SDP_ATTRIB_HEADER_8BIT(6), SDP_UUID_16BIT(0x0100),
    SDP_UINT_16BIT(0x0100),

    BT_APP_SDP_ATTRIBUTE_ID(AID_SERVICE_NAME + 0x0100),
    SDP_TEXT_8BIT(14), 'V', 'o', 'i', 'c', 'e', 'g', ' ', 'a', 't', 'e', 'w', 'a', 'y', '\0',

    BT_APP_SDP_ATTRIBUTE_ID(AID_EXTERNAL_NETWORK),
    SDP_UINT_8BIT(0x01),

    BT_APP_SDP_ATTRIBUTE_ID(AID_SUPPORTED_FEATURES),
    SDP_UINT_16BIT(0x0010)
};

/* Add by mtk01411: 2007-1123, each attribut list = Attribute ID(2bytes)+Attribute Value(its data type is defined in spec.) */
kal_uint8 bt_sdp_spp_test_pattern[] = 
{
    /* 1st attribute list */
    BT_APP_SDP_ATTRIBUTE_ID(AID_SERVICE_CLASS_ID_LIST),
    SDP_ATTRIB_HEADER_8BIT(3),
    SDP_UUID_16BIT(SC_SERIAL_PORT),

    /* 2nd attribute list */
    BT_APP_SDP_ATTRIBUTE_ID(AID_PROTOCOL_DESC_LIST),
    SDP_ATTRIB_HEADER_8BIT(12),
    SDP_ATTRIB_HEADER_8BIT(3), SDP_UUID_16BIT(PROT_L2CAP),
    SDP_ATTRIB_HEADER_8BIT(5), SDP_UUID_16BIT(PROT_RFCOMM), SDP_UINT_8BIT(0x0C),        /* for testing: this SPP uses chnl_num=12 */

    /* 3rd attribute list */
    BT_APP_SDP_ATTRIBUTE_ID(AID_BROWSE_GROUP_LIST),
    SDP_ATTRIB_HEADER_8BIT(3),
    SDP_UUID_16BIT(SC_PUBLIC_BROWSE_GROUP),

    /* 4th attribute list (its attribute value type is data element sequence and contains 3 parts: Language identifier(0x656E: english), character encoding(0x006A: UTF-8 encoding), base attribute ID(0x0010)) */
    BT_APP_SDP_ATTRIBUTE_ID(AID_LANG_BASE_ID_LIST),
    SDP_ATTRIB_HEADER_8BIT(9),
    SDP_UINT_16BIT(0x656E), SDP_UINT_16BIT(0x006A), SDP_UINT_16BIT(0x0100),

    /* 5th attribute list */
    BT_APP_SDP_ATTRIBUTE_ID(AID_SERVICE_NAME + 0x0100),
    SDP_TEXT_8BIT(11), 'J', 'S', 'R', '8', '2', 'S', 'P', 'P', '0', '1', '\0',
};

kal_uint8 bt_sdp_spp_test_pattern02[] = 
{
    0x00, 0x05, 0x35, 0x03, 0x19, 0x10, 0x02,   /* attribute_id = 0x0005 BrowseGroupList */
    0x00, 0x04, 0x35, 0x11, 0x35, 0x03, 0x19, 0x01, 0x00, 0x35, 0x05, 0x19, 0x00, 0x03, 0x08, 0x0C, 0x35, 0x03, 0x19, 0x00, 0x08,       /* attribute_id = 0x0004 ProtocolDescriptorList */
    0x01, 0x00, 0x25, 0x0A, 0x4F, 0x42, 0x45, 0x58, 0x53, 0x65, 0x72, 0x76, 0x65, 0x72, /* attribute_id = 0x0100 Service Name */
    0x00, 0x01, 0x1C, 0xF0, 0xE0, 0xD0, 0xC0, 0xB0, 0xA0, 0x00, 0x90, 0x80, 0x70, 0x60, 0x50, 0x40, 0x30, 0x20, 0x10,   /* attribute_id = 0x0001 Service Class ID List (data element sequence,each element: UUID:16 bytes) */
    0x00, 0x00, 0x0A, 0x00, 0x01, 0x00, 0x30    /* attribute_id = 0x0000 Service Record Handle */
};

typedef struct _jbt_file_access_operation
{
    FS_HANDLE f_handle;
    /* for read operation each time: this is actual read length, for write operation each time: this is actual writen length */
    kal_uint32 wanted_access_length_this_time;
    kal_uint32 accumulate_access_length;
    kal_uint32 file_size;
    /*
     * for read operation: This tmp buf is used to store the data removed from the RX buf
     * for write operation:This tmp buf is used to store the data read from the file,
     * Because the write action may be copied all data in tmp buf to TX buf,
     * it is also necessary to keep the tmp_buf_position for tmp buf (store the position of tmp buf should be written to TX buf at next time)
     */
    kal_uint16 tmp_buf_position;    /* It must be 16-bits */
    kal_uint8 tmp_buf[329];
    kal_uint32 session_inx;
    kal_uint16 l2cap_id;
} jbt_file_access_operation;

typedef struct _jbt_ut_acceptor_rw_struct
{
    kal_uint8 tmp_buf[329];
    kal_uint8 app_buf[329];
#ifdef __USE_BT_RING_BUF_API__
    RingBuf AppRingBuf;
#else 
    JBTRingBuf AppRingBuf;
#endif 
    kal_uint16 write_pos;   /* point to the index which can be to put data to tmp_buf continuously */
    kal_uint16 read_pos;    /* point to the index which can be read data from tmp_buf continuously */
    kal_uint16 session_inx;
    kal_uint16 l2cap_id;
    kal_uint16 dataLen;
} jbt_ut_acceptor_rw_struct;

extern void BTJSR82_SPPDisconReq_Test(void);
extern void BTJSR82_L2CAPDisconReq_Test(void);
extern void BTJSR82_SPPDeregistrationService_Test(void);
extern void BTJSR82_L2CAPDeregistrationService_Test(void);
extern void BTJSR82_SetACLSecurityTest(void);
extern void BTJSR82_SdpGetRecordHandler(void);
extern void BTJSR82_SdpDeregisterRecord(void);

extern kal_int16 jbt_session_PutBytes(
                    kal_uint8 session_type,
                    kal_uint32 session_inx,
                    kal_uint16 subsession_id,
                    kal_uint8 *Buffaddr,
                    kal_int16 Length);
extern kal_int16 jbt_session_GetBytes(
                    kal_uint8 session_type,
                    kal_uint32 session_inx,
                    kal_uint16 subsession_id,
                    kal_uint8 *Buffaddr,
                    kal_int16 Length);
extern kal_int16 jbt_session_BufFreeSpace(
                    kal_uint8 session_type,
                    kal_uint32 session_inx,
                    kal_uint8 subsession_id,
                    kal_uint8 buf_type);
extern kal_int16 jbt_session_BufAvailableDataLen(
                    kal_uint8 session_type,
                    kal_uint32 session_inx,
                    kal_uint8 subsession_id,
                    kal_uint8 buf_type);
extern kal_bool jbt_session_service_registration_use_existing_chnl_num(
                    kal_uint8 ps_type,
                    kal_uint16 mtu,
                    kal_uint8 security,
                    kal_uint32 transaction_id,
                    kal_uint8 existing_chnl_num);

/* Global content for JBT Read/Write UT */
jbt_file_access_operation jbt_ut_write;
jbt_file_access_operation jbt_ut_read;

/* Add by mtk01411: 2007-1107 */
jbt_ut_acceptor_rw_struct jbt_ut_rw_acceptor;
kal_uint8 jbt_ut_transaction_id;

kal_bool enable_txrx_loopback_mode;
kal_bool ut_initiator_send_file;



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST
 * DESCRIPTION
 *  *#905#: Using this function to start the first write action to TX 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Write data to file for Debug usage */
    /* Debug usage codes */

    kal_uint8 session_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if(f_handle == NULL) */
    {
        /* Check the Received folder is in C or D drive: This can be done via  PhoneSuite */
        /* The file UTTest.txt must be already existed in path of the File Manager */
        jbt_ut_write.f_handle = FS_Open(L"D:\\Received\\UTTest.txt", (FS_READ_WRITE));
        if (jbt_ut_write.f_handle >= FS_NO_ERROR)
        {
            int ret = 0;
            kal_int16 actual_written_len = 0;
            kal_bool continue_write = KAL_FALSE;
            kal_int16 wanted_write_this_time = 0;

            FS_GetFileSize(jbt_ut_write.f_handle, &jbt_ut_write.file_size);
            kal_trace(TRACE_INFO, FUNC_JBT_GET_FILE_SIZE, jbt_ut_write.file_size);

            ret = FS_Read(
                    jbt_ut_write.f_handle,
                    (void*)jbt_ut_write.tmp_buf,
                    (UINT) sizeof(jbt_ut_write.tmp_buf),
                    &jbt_ut_write.wanted_access_length_this_time);
            if (ret != FS_NO_ERROR)
            {
                kal_trace(TRACE_INFO, FUNC_JBT_READ_FAILED, ret);
                ASSERT(0);
            }

            /* Add by mtk01411: 2007-1107 */
            ut_initiator_send_file = KAL_TRUE;

            if (jbt_ut_write.l2cap_id == 0)
            {
                session_type = JBT_SESSION_TYPE_SPP;
            }
            else
            {
                session_type = JBT_SESSION_TYPE_L2CAP;
            }

            do
            {
                /* Using jbt_ut_write.session_inx (obtained from ) for this SPP transaction testing */
                wanted_write_this_time = jbt_ut_write.wanted_access_length_this_time;

                actual_written_len = jbt_session_PutBytes(
                                        session_type,
                                        jbt_ut_write.session_inx,
                                        jbt_ut_write.l2cap_id,
                                        jbt_ut_write.tmp_buf + jbt_ut_write.tmp_buf_position,
                                        jbt_ut_write.wanted_access_length_this_time);
                if (actual_written_len < 0)
                {
                    /* ASSERT(0); */
                    /*
                     * Modified 2007-1031
                     * If no session_entry is found, it may be the connection is closed
                     * For our UT, it can try to establishment this connection again
                     */
                    if (jbt_ut_write.f_handle != FS_FILE_NOT_FOUND)
                    {
                        FS_Close(jbt_ut_write.f_handle);
                    }
                    continue_write = KAL_FALSE;
                    jbt_ut_write.accumulate_access_length = 0;
                    jbt_ut_write.f_handle = FS_FILE_NOT_FOUND;
                    kal_trace(TRACE_INFO, FUNC_JBT_WRITE_BUT_SESSION_NOT_FIND);
                    return;
                }

                jbt_ut_write.accumulate_access_length += actual_written_len;
                jbt_ut_write.tmp_buf_position += actual_written_len;
                jbt_ut_write.wanted_access_length_this_time -= actual_written_len;

                kal_trace(
                    TRACE_INFO,
                    FUNC_JBT_PUTBYTES,
                    actual_written_len,
                    wanted_write_this_time,
                    jbt_ut_write.accumulate_access_length,
                    jbt_ut_write.tmp_buf_position,
                    jbt_ut_write.wanted_access_length_this_time,
                    jbt_ut_write.file_size);

                if (jbt_ut_write.wanted_access_length_this_time == 0)
                {
                    /* All data stored in tmp buf is already copied to TX buf, now it's time to read data from file again */
                    jbt_ut_write.tmp_buf_position = 0;
                    continue_write = KAL_TRUE;

                    if (jbt_ut_write.accumulate_access_length < jbt_ut_write.file_size)
                    {
                        ret = FS_Read(
                                jbt_ut_write.f_handle,
                                (void*)jbt_ut_write.tmp_buf,
                                (UINT) sizeof(jbt_ut_write.tmp_buf),
                                &jbt_ut_write.wanted_access_length_this_time);
                        if (ret != FS_NO_ERROR)
                        {
                            kal_trace(TRACE_INFO, FUNC_JBT_READ_FAILED, ret);
                            ASSERT(0);
                        }
                    }
                    else
                    {
                        /* Read all data from file, it is time to close this file handle */
                        FS_Close(jbt_ut_write.f_handle);
                        continue_write = KAL_FALSE;
                        /*
                         * Add 2007-1026
                         * Some fileds will be reset when open file again: press *#900#
                         * file_size: Open UTTest file to get again
                         * wanted_access_length_this_time: will be set when open file again: press *#900#
                         * session_inx: This field can not be reset! Because, if the spp connection is not closed, just send data to peer serveral time,
                         * It is not allowed to reset the session_inx's context value
                         *  
                         */
                        jbt_ut_write.accumulate_access_length = 0;
                        jbt_ut_write.f_handle = FS_FILE_NOT_FOUND;
                        kal_trace(TRACE_INFO, FUNC_JBT_PUTBYTES_CLOSE01);
                    }
                }
                else
                {
                    kal_trace(TRACE_INFO, FUNC_JBT_WAIT_FOR_READY_TO_WRITE_IND);
                    /* TX buf is full currently and wait for message ready_to_write_ind */
                    continue_write = KAL_FALSE;
                }
            } while (continue_write);
        }
        else
        {
            kal_trace(TRACE_INFO, FUNC_JBT_OPEN_FILE_FAILED, jbt_ut_write.f_handle);
            ASSERT(0);
        }

    }
}



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST1
 * DESCRIPTION
 *  *#906# :On Receiver side, open the same file to get file's size and this file will be sent from Sender side later!
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST1()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable_txrx_loopback_mode == KAL_TRUE)
    {
        enable_txrx_loopback_mode = KAL_FALSE;
    }
    else
    {
        enable_txrx_loopback_mode = KAL_TRUE;
    }

    kal_trace(TRACE_INFO, FUNC_JBT_CURRENT_LB_MODE, enable_txrx_loopback_mode);

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */ 
}



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST2
 * DESCRIPTION
 *  *#907#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST2()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BTJSR82_SPPDisconReq_Test();
}


/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST3
 * DESCRIPTION
 *  *#908#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST3()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BTJSR82_L2CAPDisconReq_Test();
}


/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST4
 * DESCRIPTION
 *  *#909#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST4()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BTJSR82_SPPDeregistrationService_Test();
}



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST5
 * DESCRIPTION
 *  *#910#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST5()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BTJSR82_L2CAPDeregistrationService_Test();
}


/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST6
 * DESCRIPTION
 *  *#911# 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST6()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BTJSR82_SetACLSecurityTest();
}



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST7
 * DESCRIPTION
 *  *#912#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST7()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    BTJSR82_SdpGetRecordHandler();
}



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST8
 * DESCRIPTION
 *  *#913# 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST8()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST9
 * DESCRIPTION
 *  *#914#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST9()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST10
 * DESCRIPTION
 *  *#915#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST10()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST11
 * DESCRIPTION
 *  *#916#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST11()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST12
 * DESCRIPTION
 *  *#917#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST12()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST13
 * DESCRIPTION
 *  *#918#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST13()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST14
 * DESCRIPTION
 *  *#919#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST14()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}



/*****************************************************************************
 * FUNCTION
 *  BT_SPECIAL_TEST15
 * DESCRIPTION
 *  *#920#
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BT_SPECIAL_TEST15()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  jbt_ut_open_ReceivedFile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jbt_ut_open_ReceivedFile()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check the Received folder is in C or D drive: This can be done via  PhoneSuite */
    /* The file UTTest.txt must be already existed in path of the File Manager */
    if (enable_txrx_loopback_mode == KAL_FALSE)
    {
        jbt_ut_read.f_handle = FS_Open(L"D:\\Received\\UTTest.txt", (FS_READ_WRITE));
        if (jbt_ut_read.f_handle >= FS_NO_ERROR)
        {
            FS_GetFileSize(jbt_ut_read.f_handle, &jbt_ut_read.file_size);
            kal_trace(TRACE_INFO, FUNC_JBT_GET_FILE_SIZE, jbt_ut_read.file_size);
            FS_Close(jbt_ut_read.f_handle);
        }
        else
        {
            /* Return value from FS_Open() is less than zero, print the error code */
            kal_trace(TRACE_INFO, FUNC_JBT_OPEN_FILE_FAILED, jbt_ut_read.f_handle);
            ASSERT(0);
        }
    }
    else
    {
        jbt_ut_read.file_size = jbt_ut_write.file_size;
        kal_trace(TRACE_INFO, FUNC_JBT_GET_FILE_SIZE, jbt_ut_read.file_size);
    }

    /* Create the file to store the received data later */
    jbt_ut_read.f_handle = FS_Open(L"D:\\Received\\UTTestReceived.txt", (FS_READ_WRITE | FS_CREATE_ALWAYS));
    if (jbt_ut_read.f_handle >= FS_NO_ERROR)
    {
        /* Already create file to store incoming data later */
        kal_trace(TRACE_INFO, FUNC_JBT_OPEN_FILE_FOR_RECEIVED_DATA);
    }
    else
    {
        kal_trace(TRACE_INFO, FUNC_JBT_OPEN_FILE_FAILED, jbt_ut_read.f_handle);
        ASSERT(0);
    }

}


/*****************************************************************************
 * FUNCTION
 *  Jbt_ut_ready_to_write_ind_initiator_hdler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Jbt_ut_ready_to_write_ind_initiator_hdler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Continously to send the left data stored in the tmp_buf */
    int ret = 0;
    kal_int16 actual_written_len = 0;
    kal_bool continue_write = KAL_FALSE;
    kal_int16 wanted_write_this_time = 0;
    kal_uint8 session_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_ut_write.l2cap_id == 0)
    {
        session_type = JBT_SESSION_TYPE_SPP;
    }
    else
    {
        session_type = JBT_SESSION_TYPE_L2CAP;
    }

    do
    {

        wanted_write_this_time = jbt_ut_write.wanted_access_length_this_time;

        actual_written_len = jbt_session_PutBytes(
                                session_type,
                                jbt_ut_write.session_inx,
                                jbt_ut_write.l2cap_id,
                                jbt_ut_write.tmp_buf + jbt_ut_write.tmp_buf_position,
                                jbt_ut_write.wanted_access_length_this_time);
        if (actual_written_len == JBT_SESSION_FIND_NO_ENTRY)
        {
            ASSERT(0);
        }
        else if (actual_written_len < 0)
        {
            return;
        }

        jbt_ut_write.accumulate_access_length += actual_written_len;
        jbt_ut_write.tmp_buf_position += actual_written_len;
        jbt_ut_write.wanted_access_length_this_time -= actual_written_len;

        kal_trace(
            TRACE_INFO,
            FUNC_JBT_PUTBYTES,
            actual_written_len,
            wanted_write_this_time,
            jbt_ut_write.accumulate_access_length,
            jbt_ut_write.tmp_buf_position,
            jbt_ut_write.wanted_access_length_this_time,
            jbt_ut_write.file_size);

        if (jbt_ut_write.wanted_access_length_this_time == 0)
        {
            /* All data stored in tmp buf is already copied to TX buf, now it's time to read data from file again */
            jbt_ut_write.tmp_buf_position = 0;
            continue_write = KAL_TRUE;

            if (jbt_ut_write.accumulate_access_length < jbt_ut_write.file_size)
            {
                ret = FS_Read(
                        jbt_ut_write.f_handle,
                        (void*)jbt_ut_write.tmp_buf,
                        (UINT) sizeof(jbt_ut_write.tmp_buf),
                        &jbt_ut_write.wanted_access_length_this_time);
                if (ret != FS_NO_ERROR)
                {
                    kal_trace(TRACE_INFO, FUNC_JBT_READ_FAILED, ret);
                    ASSERT(0);
                }
            }
            else
            {
                /* Read all data from file, it is time to close this file handle */
                FS_Close(jbt_ut_write.f_handle);
                continue_write = KAL_FALSE;

                /*
                 * Add 2007-1026
                 * Some fileds will be reset when open file again: press *#900#
                 * file_size: Open UTTest file to get again
                 * wanted_access_length_this_time: will be set when open file again: press *#900#
                 * session_inx: This field can not be reset! Because, if the spp connection is not closed, just send data to peer serveral time,
                 * It is not allowed to reset the session_inx's context value
                 *  
                 */
                jbt_ut_write.accumulate_access_length = 0;
                jbt_ut_write.f_handle = FS_FILE_NOT_FOUND;

                kal_trace(TRACE_INFO, FUNC_JBT_PUTBYTES_CLOSE01);

            }
        }
        else
        {
            /* TX buf is full currently and wait for message ready_to_write_ind */
            kal_trace(TRACE_INFO, FUNC_JBT_WAIT_FOR_READY_TO_WRITE_IND);
            continue_write = KAL_FALSE;
        }

    } while (continue_write);

}


/*****************************************************************************
 * FUNCTION
 *  Jbt_ut_ready_to_write_ind_acceptor_hdler_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Jbt_ut_ready_to_write_ind_acceptor_hdler_1()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 session_type = 0;
    kal_bool continue_read_flag = KAL_TRUE;
    kal_bool continue_write_flag = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_ut_rw_acceptor.l2cap_id == 0)
    {
        session_type = JBT_SESSION_TYPE_SPP;
    }
    else
    {
        session_type = JBT_SESSION_TYPE_L2CAP;
    }
    do
    {

        if (continue_write_flag)
        {
            /* Put data to Buf */
            kal_int16 actual_write_len = 0;
            kal_uint8 *write_start_pos = jbt_ut_rw_acceptor.tmp_buf + jbt_ut_rw_acceptor.read_pos;
            kal_int16 wanted_to_write_len = jbt_ut_rw_acceptor.dataLen;
            kal_int16 txBuf_freespace = jbt_session_BufFreeSpace(
                                            session_type,
                                            jbt_ut_rw_acceptor.session_inx,
                                            jbt_ut_rw_acceptor.l2cap_id,
                                            JBT_SESSION_TX_BUF_TYPE);

            if (txBuf_freespace < 0)
            {
                return;
            }

            if ((wanted_to_write_len > 0) && (txBuf_freespace > 0))
            {
                actual_write_len = jbt_session_PutBytes(
                                    session_type,
                                    jbt_ut_rw_acceptor.session_inx,
                                    jbt_ut_rw_acceptor.l2cap_id,
                                    write_start_pos,
                                    jbt_ut_rw_acceptor.dataLen);
                if (actual_write_len < 0)
                {
                    return;
                }

                jbt_ut_rw_acceptor.dataLen -= actual_write_len;
                jbt_ut_rw_acceptor.read_pos += actual_write_len;
                if ((actual_write_len == wanted_to_write_len) && (jbt_ut_rw_acceptor.read_pos < 329) &&
                    (jbt_ut_rw_acceptor.dataLen > 0))
                {
                    continue_write_flag = KAL_TRUE;
                }
                else
                {
                    continue_write_flag = KAL_FALSE;
                }

                /* After putting data to TX buf, it must check if there is available space to get data from RX buf */
                if (jbt_ut_rw_acceptor.write_pos < 329)
                {
                    continue_read_flag = KAL_TRUE;
                }
                else if ((jbt_ut_rw_acceptor.read_pos == 329) && (jbt_ut_rw_acceptor.write_pos == 329))
                {
                    jbt_ut_rw_acceptor.read_pos = 0;
                    jbt_ut_rw_acceptor.write_pos = 0;
                    jbt_ut_rw_acceptor.dataLen = 0;
                    continue_read_flag = KAL_TRUE;
                    continue_write_flag = KAL_TRUE;
                }
            }
            else
            {
                continue_write_flag = KAL_FALSE;
            }
        }

        if (continue_read_flag)
        {
            kal_int16 actual_read_len = 0;
            kal_uint8 *read_start_pos = jbt_ut_rw_acceptor.tmp_buf + jbt_ut_rw_acceptor.write_pos;
            kal_int16 available_buf_len = 329 - jbt_ut_rw_acceptor.write_pos;
            kal_int16 rxBuf_dataLen = jbt_session_BufAvailableDataLen(
                                        session_type,
                                        jbt_ut_rw_acceptor.session_inx,
                                        jbt_ut_rw_acceptor.l2cap_id,
                                        JBT_SESSION_RX_BUF_TYPE);

            if (rxBuf_dataLen < 0)
            {
                return;
            }

            if ((available_buf_len > 0) && (rxBuf_dataLen > 0))
            {
                actual_read_len = jbt_session_GetBytes(
                                    session_type,
                                    jbt_ut_rw_acceptor.session_inx,
                                    jbt_ut_rw_acceptor.l2cap_id,
                                    read_start_pos,
                                    available_buf_len);

                if (actual_read_len < 0)
                {
                    return;
                }

                jbt_ut_rw_acceptor.dataLen += actual_read_len;
                jbt_ut_rw_acceptor.write_pos += actual_read_len;
                if ((actual_read_len == available_buf_len) && (jbt_ut_rw_acceptor.write_pos < 329))
                {
                    continue_read_flag = KAL_TRUE;
                }
                else
                {
                    continue_read_flag = KAL_FALSE;
                }

                /* After getting data from RX buf, it must check if there is available data can be sent to TX buf */
                if (jbt_ut_rw_acceptor.dataLen > 0)
                {
                    continue_write_flag = KAL_TRUE;
                }
            }
            else
            {
                continue_read_flag = KAL_FALSE;
            }
        }

        if ((jbt_ut_rw_acceptor.read_pos == 329) && (jbt_ut_rw_acceptor.write_pos == 329))
        {
            jbt_ut_rw_acceptor.read_pos = 0;
            jbt_ut_rw_acceptor.write_pos = 0;
            jbt_ut_rw_acceptor.dataLen = 0;
            continue_read_flag = KAL_TRUE;
            continue_write_flag = KAL_TRUE;
        }

    }
    while (continue_read_flag || continue_write_flag);

}


/*****************************************************************************
 * FUNCTION
 *  Jbt_ut_ready_to_write_ind_acceptor_hdler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Jbt_ut_ready_to_write_ind_acceptor_hdler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 session_type = 0;
    kal_bool continue_read_flag = KAL_TRUE;
    kal_bool continue_write_flag = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_ut_rw_acceptor.l2cap_id == 0)
    {
        session_type = JBT_SESSION_TYPE_SPP;
    }
    else
    {
        session_type = JBT_SESSION_TYPE_L2CAP;
    }

    do
    {

        if (continue_write_flag)
        {
            /* Put data to Buf */
            kal_int16 actual_write_len = 0;
            kal_uint8 *write_start_pos = jbt_ut_rw_acceptor.tmp_buf;

            /* Check how many bytes of data in Applcaiton's RingBuf can be sent */
        #ifdef __USE_BT_RING_BUF_API__
            kal_int16 wanted_put_len = RING_DataLen(&jbt_ut_rw_acceptor.AppRingBuf);
        #else 
            kal_int16 wanted_put_len = JBTRING_DataLen(&jbt_ut_rw_acceptor.AppRingBuf);
        #endif 
            kal_int16 txBuf_freespace = jbt_session_BufFreeSpace(
                                            session_type,
                                            jbt_ut_rw_acceptor.session_inx,
                                            jbt_ut_rw_acceptor.l2cap_id,
                                            JBT_SESSION_TX_BUF_TYPE);

            if (txBuf_freespace < 0)
            {
                return;
            }

            if (wanted_put_len > txBuf_freespace)
            {
                wanted_put_len = txBuf_freespace;
            }

            if ((wanted_put_len > 0) && (txBuf_freespace > 0))
            {
            #ifdef __USE_BT_RING_BUF_API__
                RING_ReadData(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.tmp_buf, wanted_put_len);
            #else 
                JBTRING_ReadData(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.tmp_buf, wanted_put_len);
            #endif 
                actual_write_len = jbt_session_PutBytes(
                                    session_type,
                                    jbt_ut_rw_acceptor.session_inx,
                                    jbt_ut_rw_acceptor.l2cap_id,
                                    write_start_pos,
                                    wanted_put_len);
                if (actual_write_len < 0)
                {
                    return;
                }

                ASSERT(actual_write_len == wanted_put_len);

                jbt_ut_rw_acceptor.dataLen -= actual_write_len;

                if (actual_write_len == wanted_put_len)
                {
                    continue_write_flag = KAL_TRUE;
                }
                else
                {
                    continue_write_flag = KAL_FALSE;
                }

                memset((kal_uint8*) jbt_ut_rw_acceptor.tmp_buf, 0, sizeof(jbt_ut_rw_acceptor.tmp_buf));

                /* After putting data to TX buf, it must check if there is available space of Application's RingBuf */
            #ifdef __USE_BT_RING_BUF_API__
                if (RING_FreeSpace(&jbt_ut_rw_acceptor.AppRingBuf) > 0)
            #else 
                if (JBTRING_FreeSpace(&jbt_ut_rw_acceptor.AppRingBuf) > 0)
            #endif 
                    continue_read_flag = KAL_TRUE;
            }
            else
            {
                continue_write_flag = KAL_FALSE;
            }
        }

        if (continue_read_flag)
        {
            kal_int16 actual_read_len = 0;
            kal_uint8 *read_start_pos = jbt_ut_rw_acceptor.tmp_buf;

            /* Check how many bytes of freespac in Application's Buf */
        #ifdef __USE_BT_RING_BUF_API__
            kal_int16 available_buf_len = RING_FreeSpace(&jbt_ut_rw_acceptor.AppRingBuf);
        #else 
            kal_int16 available_buf_len = JBTRING_FreeSpace(&jbt_ut_rw_acceptor.AppRingBuf);
        #endif 
            kal_int16 rxBuf_dataLen = jbt_session_BufAvailableDataLen(
                                        session_type,
                                        jbt_ut_rw_acceptor.session_inx,
                                        jbt_ut_rw_acceptor.l2cap_id,
                                        JBT_SESSION_RX_BUF_TYPE);

            if (rxBuf_dataLen < 0)
            {
                return;
            }

            if (available_buf_len > rxBuf_dataLen)
            {
                available_buf_len = rxBuf_dataLen;
            }

            if ((available_buf_len > 0) && (rxBuf_dataLen > 0))
            {
                actual_read_len = jbt_session_GetBytes(
                                    session_type,
                                    jbt_ut_rw_acceptor.session_inx,
                                    jbt_ut_rw_acceptor.l2cap_id,
                                    read_start_pos,
                                    available_buf_len);
                ASSERT(actual_read_len == available_buf_len);
                jbt_ut_rw_acceptor.dataLen += actual_read_len;

                if (actual_read_len == available_buf_len)
                {
                    continue_read_flag = KAL_TRUE;
                }
                else
                {
                    continue_read_flag = KAL_FALSE;
                }

                /* Put data to Application's RingBuf */
            #ifdef __USE_BT_RING_BUF_API__
                RING_WriteData(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.tmp_buf, actual_read_len);
            #else 
                JBTRING_WriteData(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.tmp_buf, actual_read_len);
            #endif 
                memset((kal_uint8*) jbt_ut_rw_acceptor.tmp_buf, 0, sizeof(jbt_ut_rw_acceptor.tmp_buf));

                /* After getting data from RX buf, it must check if there is available data can be sent to TX buf */
                if (jbt_ut_rw_acceptor.dataLen > 0)
                {
                    continue_write_flag = KAL_TRUE;
                }
            }
            else
            {
                continue_read_flag = KAL_FALSE;
            }
        }

    }
    while (continue_read_flag || continue_write_flag);

}


/*****************************************************************************
 * FUNCTION
 *  Jbt_ut_ready_to_write_ind_hdler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Jbt_ut_ready_to_write_ind_hdler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable_txrx_loopback_mode == KAL_TRUE)
    {
        if (ut_initiator_send_file == KAL_TRUE)
        {
            Jbt_ut_ready_to_write_ind_initiator_hdler();
        }
        else
            /* Receive data then send the received data back to sender */
        {
            Jbt_ut_ready_to_write_ind_acceptor_hdler();
        }
    }
    else
    {
        /* Non-Loopback mode */
        if (ut_initiator_send_file == KAL_TRUE)
        {
            Jbt_ut_ready_to_write_ind_initiator_hdler();
        }
        else
        {
            ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  Jbt_ut_ready_to_read_ind_initiator_hdler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Jbt_ut_ready_to_read_ind_initiator_hdler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool continue_read = KAL_FALSE;
    kal_int16 actual_read_len = 0;
    int ret = 0;
    kal_uint8 session_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_ut_read.l2cap_id == 0)
    {
        session_type = JBT_SESSION_TYPE_SPP;
    }
    else
    {
        session_type = JBT_SESSION_TYPE_L2CAP;
    }

    do
    {

        actual_read_len = jbt_session_GetBytes(
                            session_type,
                            jbt_ut_read.session_inx,
                            jbt_ut_read.l2cap_id,
                            jbt_ut_read.tmp_buf + jbt_ut_read.tmp_buf_position,
                            jbt_ut_read.wanted_access_length_this_time);

        if (actual_read_len < 0)
        {
            if (actual_read_len != JBT_SESSION_FIND_NO_ENTRY)
            {
                return;
            }
            else
            {
                ASSERT(0);
            }
        }

        jbt_ut_read.accumulate_access_length += actual_read_len;
        jbt_ut_read.tmp_buf_position += actual_read_len;

        kal_trace(
            TRACE_INFO,
            FUNC_JBT_GETBYTES,
            actual_read_len,
            jbt_ut_read.wanted_access_length_this_time,
            jbt_ut_read.accumulate_access_length,
            jbt_ut_read.tmp_buf_position,
            jbt_ut_read.file_size);

        if (actual_read_len == jbt_ut_read.wanted_access_length_this_time)
        {
            continue_read = KAL_TRUE;
        }
        else
        {
            kal_trace(TRACE_INFO, FUNC_JBT_WAIT_FOR_READY_TO_READ_IND);
            continue_read = KAL_FALSE;
        }
        if (jbt_ut_read.tmp_buf_position == 329)
        {
            kal_uint32 written_len = 0;

            /* Write tmp_buf's content to file */
            /* Because each time to close file_handle, its value will be reset as FS_FILE_NOT_FOUND:2007-1031 */
            if (jbt_ut_read.f_handle == FS_FILE_NOT_FOUND)
            {
                /* If user forgets to open file to get file_size and file_handle via *#906#, do these things here */
                jbt_ut_open_ReceivedFile();
            }
            ret = FS_Write(jbt_ut_read.f_handle, (void*)jbt_ut_read.tmp_buf, sizeof(jbt_ut_read.tmp_buf), &written_len);
            if (ret != FS_NO_ERROR)
            {
                kal_trace(TRACE_INFO, FUNC_JBT_WRITE_FAILED, ret);
                ASSERT(0);
            }
            kal_trace(TRACE_INFO, FUNC_JBT_WRITE_BUF_DATA_TO_FILE);
            memset(jbt_ut_read.tmp_buf, 0, sizeof(jbt_ut_read.tmp_buf));
            jbt_ut_read.tmp_buf_position = 0;

        }
        else
        {
            /* tmp_buf is not full, it is not necessary to wirte data stored in tmp_buf to file */
        }

        /* update the wanted read length for next GetBytes() */
        jbt_ut_read.wanted_access_length_this_time = 329 - jbt_ut_read.tmp_buf_position;

        if (jbt_ut_read.accumulate_access_length == jbt_ut_read.file_size)
        {
            /* Check if the tmp_buf_position is not 0: this means data stored in the buf is not copied to file: 2007-1025 */
            if (jbt_ut_read.tmp_buf_position > 0)
            {
                kal_uint32 written_len = 0;

                /* Write tmp_buf's content to file */
                ret = FS_Write(
                        jbt_ut_read.f_handle,
                        (void*)jbt_ut_read.tmp_buf,
                        jbt_ut_read.tmp_buf_position,
                        &written_len);
                if (ret != FS_NO_ERROR)
                {
                    kal_trace(TRACE_INFO, FUNC_JBT_WRITE_FAILED, ret);
                    ASSERT(0);
                }
                memset(jbt_ut_read.tmp_buf, 0, sizeof(jbt_ut_read.tmp_buf));
                jbt_ut_read.tmp_buf_position = 0;
            }
            FS_Close(jbt_ut_read.f_handle);
            continue_read = KAL_FALSE;
            /*
             * Add 2007-1026
             * Some fileds will be reset when getting another file's data from peer
             * file_size: Open UTTest file to get again, when press: *#906#
             * session_inx: This field can not be reset! Because, if the spp connection is not closed, just send data to peer serveral time,
             * It is not allowed to reset the session_inx's context value
             *  
             */
            jbt_ut_read.accumulate_access_length = 0;
            jbt_ut_read.f_handle = FS_FILE_NOT_FOUND;
            jbt_ut_read.wanted_access_length_this_time = 329;
            kal_trace(TRACE_INFO, FUNC_JBT_RECEIVED_ALL_DATA, jbt_ut_read.accumulate_access_length);
        }

    } while (continue_read);
}


/*****************************************************************************
 * FUNCTION
 *  Jbt_ut_ready_to_read_ind_acceptor_hdler_1
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Jbt_ut_ready_to_read_ind_acceptor_hdler_1()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 session_type = 0;
    kal_bool continue_read_flag = KAL_TRUE;
    kal_bool continue_write_flag = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_ut_rw_acceptor.l2cap_id == 0)
    {
        session_type = JBT_SESSION_TYPE_SPP;
    }
    else
    {
        session_type = JBT_SESSION_TYPE_L2CAP;
    }
    do
    {

        if (continue_read_flag)
        {
            kal_int16 actual_read_len = 0;
            kal_uint8 *read_start_pos = jbt_ut_rw_acceptor.tmp_buf + jbt_ut_rw_acceptor.write_pos;
            kal_int16 available_buf_len = 329 - jbt_ut_rw_acceptor.write_pos;
            kal_int16 rxBuf_dataLen = jbt_session_BufAvailableDataLen(
                                        session_type,
                                        jbt_ut_rw_acceptor.session_inx,
                                        jbt_ut_rw_acceptor.l2cap_id,
                                        JBT_SESSION_RX_BUF_TYPE);

            if ((available_buf_len > 0) && (rxBuf_dataLen > 0))
            {
                actual_read_len = jbt_session_GetBytes(
                                    session_type,
                                    jbt_ut_rw_acceptor.session_inx,
                                    jbt_ut_rw_acceptor.l2cap_id,
                                    read_start_pos,
                                    available_buf_len);
                if (actual_read_len < 0)
                {
                    return;
                }

                jbt_ut_rw_acceptor.dataLen += actual_read_len;
                jbt_ut_rw_acceptor.write_pos += actual_read_len;
                if ((actual_read_len == available_buf_len) && (jbt_ut_rw_acceptor.write_pos < 329))
                {
                    continue_read_flag = KAL_TRUE;
                }
                else
                {
                    continue_read_flag = KAL_FALSE;
                }

                /* After getting data from RX buf, it must check if there is available data can be sent to TX buf */
                if (jbt_ut_rw_acceptor.dataLen > 0)
                {
                    continue_write_flag = KAL_TRUE;
                }
            }
            else
            {
                continue_read_flag = KAL_FALSE;
            }
        }

        if (continue_write_flag)
        {
            /* Put data to Buf */
            kal_int16 actual_write_len = 0;
            kal_uint8 *write_start_pos = jbt_ut_rw_acceptor.tmp_buf + jbt_ut_rw_acceptor.read_pos;
            kal_int16 wanted_put_len = jbt_ut_rw_acceptor.dataLen;
            kal_int16 txBuf_freespace = jbt_session_BufFreeSpace(
                                            session_type,
                                            jbt_ut_rw_acceptor.session_inx,
                                            jbt_ut_rw_acceptor.l2cap_id,
                                            JBT_SESSION_TX_BUF_TYPE);

            if ((wanted_put_len > 0) && (txBuf_freespace > 0))
            {
                actual_write_len = jbt_session_PutBytes(
                                    session_type,
                                    jbt_ut_rw_acceptor.session_inx,
                                    jbt_ut_rw_acceptor.l2cap_id,
                                    write_start_pos,
                                    wanted_put_len);
                if (actual_write_len < 0)
                {
                    return;
                }

                jbt_ut_rw_acceptor.dataLen -= actual_write_len;
                jbt_ut_rw_acceptor.read_pos += actual_write_len;
                if ((actual_write_len == wanted_put_len) && (jbt_ut_rw_acceptor.read_pos < 329) &&
                    (jbt_ut_rw_acceptor.dataLen > 0))
                {
                    continue_write_flag = KAL_TRUE;
                }
                else
                {
                    continue_write_flag = KAL_FALSE;
                }

                /* After putting data to TX buf, it must check if there is available space to get data from RX buf */
                if (jbt_ut_rw_acceptor.write_pos < 329)
                {
                    continue_read_flag = KAL_TRUE;
                }
                else if ((jbt_ut_rw_acceptor.read_pos == 329) && (jbt_ut_rw_acceptor.write_pos == 329))
                {
                    jbt_ut_rw_acceptor.read_pos = 0;
                    jbt_ut_rw_acceptor.write_pos = 0;
                    jbt_ut_rw_acceptor.dataLen = 0;
                    continue_read_flag = KAL_TRUE;
                    continue_write_flag = KAL_TRUE;
                }

            }
            else
            {
                continue_write_flag = KAL_FALSE;
            }
        }

        if ((jbt_ut_rw_acceptor.read_pos == 329) && (jbt_ut_rw_acceptor.write_pos == 329))
        {
            jbt_ut_rw_acceptor.read_pos = 0;
            jbt_ut_rw_acceptor.write_pos = 0;
            jbt_ut_rw_acceptor.dataLen = 0;
            continue_read_flag = KAL_TRUE;
            continue_write_flag = KAL_TRUE;
        }

    }
    while (continue_read_flag || continue_write_flag);
}


/*****************************************************************************
 * FUNCTION
 *  Jbt_ut_ready_to_read_ind_acceptor_hdler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Jbt_ut_ready_to_read_ind_acceptor_hdler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 session_type = 0;
    kal_bool continue_read_flag = KAL_TRUE;
    kal_bool continue_write_flag = KAL_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (jbt_ut_rw_acceptor.l2cap_id == 0)
    {
        session_type = JBT_SESSION_TYPE_SPP;
    }
    else
    {
        session_type = JBT_SESSION_TYPE_L2CAP;
    }
    do
    {

        if (continue_read_flag)
        {
            kal_int16 actual_read_len = 0;
            kal_uint8 *read_start_pos = jbt_ut_rw_acceptor.tmp_buf;

            /* Check how many bytes of freespac in Application's Buf */
        #ifdef __USE_BT_RING_BUF_API__
            kal_int16 available_buf_len = RING_FreeSpace(&jbt_ut_rw_acceptor.AppRingBuf);
        #else 
            kal_int16 available_buf_len = JBTRING_FreeSpace(&jbt_ut_rw_acceptor.AppRingBuf);
        #endif 
            kal_int16 rxBuf_dataLen = jbt_session_BufAvailableDataLen(
                                        session_type,
                                        jbt_ut_rw_acceptor.session_inx,
                                        jbt_ut_rw_acceptor.l2cap_id,
                                        JBT_SESSION_RX_BUF_TYPE);

            if (rxBuf_dataLen < 0)
            {
                return;
            }

            if (available_buf_len > rxBuf_dataLen)
            {
                available_buf_len = rxBuf_dataLen;
            }

            if ((available_buf_len > 0) && (rxBuf_dataLen > 0))
            {
                actual_read_len = jbt_session_GetBytes(
                                    session_type,
                                    jbt_ut_rw_acceptor.session_inx,
                                    jbt_ut_rw_acceptor.l2cap_id,
                                    read_start_pos,
                                    available_buf_len);
                ASSERT(actual_read_len == available_buf_len);
                jbt_ut_rw_acceptor.dataLen += actual_read_len;

                if (actual_read_len == available_buf_len)
                {
                    continue_read_flag = KAL_TRUE;
                }
                else
                {
                    continue_read_flag = KAL_FALSE;
                }

                /* Put data to Application's RingBuf */
            #ifdef __USE_BT_RING_BUF_API__
                RING_WriteData(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.tmp_buf, actual_read_len);
            #else 
                JBTRING_WriteData(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.tmp_buf, actual_read_len);
            #endif 
                memset((kal_uint8*) jbt_ut_rw_acceptor.tmp_buf, 0, sizeof(jbt_ut_rw_acceptor.tmp_buf));

                /* After getting data from RX buf, it must check if there is available data can be sent to TX buf */
                if (jbt_ut_rw_acceptor.dataLen > 0)
                {
                    continue_write_flag = KAL_TRUE;
                }
            }
            else
            {
                continue_read_flag = KAL_FALSE;
            }
        }

        if (continue_write_flag)
        {
            /* Put data to Buf */
            kal_int16 actual_write_len = 0;
            kal_uint8 *write_start_pos = jbt_ut_rw_acceptor.tmp_buf;

            /* Check how many bytes of data in Applcaiton's RingBuf can be sent */
        #ifdef __USE_BT_RING_BUF_API__
            kal_int16 wanted_put_len = RING_DataLen(&jbt_ut_rw_acceptor.AppRingBuf);
        #else 
            kal_int16 wanted_put_len = JBTRING_DataLen(&jbt_ut_rw_acceptor.AppRingBuf);
        #endif 

            kal_int16 txBuf_freespace = jbt_session_BufFreeSpace(
                                            session_type,
                                            jbt_ut_rw_acceptor.session_inx,
                                            jbt_ut_rw_acceptor.l2cap_id,
                                            JBT_SESSION_TX_BUF_TYPE);

            if (txBuf_freespace < 0)
            {
                return;
            }

            if (wanted_put_len > txBuf_freespace)
            {
                wanted_put_len = txBuf_freespace;
            }

            if ((wanted_put_len > 0) && (txBuf_freespace > 0))
            {
            #ifdef __USE_BT_RING_BUF_API__
                RING_ReadData(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.tmp_buf, wanted_put_len);
            #else 
                JBTRING_ReadData(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.tmp_buf, wanted_put_len);
            #endif 

                actual_write_len = jbt_session_PutBytes(
                                    session_type,
                                    jbt_ut_rw_acceptor.session_inx,
                                    jbt_ut_rw_acceptor.l2cap_id,
                                    write_start_pos,
                                    wanted_put_len);
                ASSERT(actual_write_len == wanted_put_len);

                jbt_ut_rw_acceptor.dataLen -= actual_write_len;

                if (actual_write_len == wanted_put_len)
                {
                    continue_write_flag = KAL_TRUE;
                }
                else
                {
                    continue_write_flag = KAL_FALSE;
                }

                memset((kal_uint8*) jbt_ut_rw_acceptor.tmp_buf, 0, sizeof(jbt_ut_rw_acceptor.tmp_buf));

                /* After putting data to TX buf, it must check if there is available space of Application's RingBuf */
            #ifdef __USE_BT_RING_BUF_API__
                if (RING_FreeSpace(&jbt_ut_rw_acceptor.AppRingBuf) > 0)
            #else 
                if (JBTRING_FreeSpace(&jbt_ut_rw_acceptor.AppRingBuf) > 0)
            #endif 
                    continue_read_flag = KAL_TRUE;
            }
            else
            {
                continue_write_flag = KAL_FALSE;
            }
        }

    }
    while (continue_read_flag || continue_write_flag);
}


/*****************************************************************************
 * FUNCTION
 *  Jbt_ut_ready_to_read_ind_hdler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Jbt_ut_ready_to_read_ind_hdler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable_txrx_loopback_mode == KAL_TRUE)
    {
        if (ut_initiator_send_file == KAL_TRUE)
        {
            /* Receive data then put to file */ 
            Jbt_ut_ready_to_read_ind_initiator_hdler();
        }
        else
        {
            Jbt_ut_ready_to_read_ind_acceptor_hdler();
        }
    }
    else
    {
        /* Non-Loopback mode: initiator will not receive ready_to_read_ind */
        if (ut_initiator_send_file == KAL_FALSE)
        {
            /* Receive data then put to file */ 
            Jbt_ut_ready_to_read_ind_initiator_hdler();
        }
        else
        {
            ASSERT(0);
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  Jbt_ut_reset_all_rw_access_hdler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void Jbt_ut_reset_all_rw_access_hdler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Check if there is any file handle is opened not closed */
    if (jbt_ut_read.f_handle >= FS_NO_ERROR)
    {
        FS_Close(jbt_ut_read.f_handle);
    }
    if (jbt_ut_write.f_handle >= FS_NO_ERROR)
    {
        FS_Close(jbt_ut_write.f_handle);
    }

    memset((kal_uint8*) (&jbt_ut_read), 0, sizeof(jbt_ut_read));
    memset((kal_uint8*) (&jbt_ut_write), 0, sizeof(jbt_ut_write));

    jbt_ut_read.wanted_access_length_this_time = 329;
    jbt_ut_read.f_handle = FS_FILE_NOT_FOUND;
    jbt_ut_write.f_handle = FS_FILE_NOT_FOUND;
    ut_initiator_send_file = KAL_FALSE;

#ifdef __USE_BT_RING_BUF_API__
    RING_BufFlush(&jbt_ut_rw_acceptor.AppRingBuf);
#else 
    JBTRING_BufFlush(&jbt_ut_rw_acceptor.AppRingBuf);
#endif 
    memset((kal_uint8*) & jbt_ut_rw_acceptor, 0, sizeof(jbt_ut_rw_acceptor));

}


/*****************************************************************************
 * FUNCTION
 *  JbtEventCallback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  opcode              [IN]        
 *  transaction_id      [IN]        
 *  parm                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void JbtEventCallback(kal_uint8 opcode, kal_uint32 transaction_id, void *parm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_INFO, FUNC_JBT_OPCODE, opcode);
    kal_trace(TRACE_INFO, FUNC_JBT_TRANSACTION_ID, transaction_id);
    switch (opcode)
    {
            /*      GAP               */
            /*      GAP               */
            /*      GAP               */
            /*      GAP               */
            /*      GAP               */
            /*      GAP               */
        case JBT_OPCODE_POWER_ON:
        {
            jbt_power_on_result *rsp;

            rsp = (jbt_power_on_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->result);
        }
            break;
        case JBT_OPCODE_POWER_OFF:
            break;

        case JBT_OPCODE_SYSTEM_ABNORMAL_RESET:
            break;
        case JBT_OPCODE_GET_LOCAL_NAME:
        {
            jbt_get_local_name_result *rsp;

            rsp = (jbt_get_local_name_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->result);
        }
            break;
        case JBT_OPCODE_GET_LOCAL_ADDR:
        {
            jbt_get_local_addr_result *rsp;

            rsp = (jbt_get_local_addr_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->result);
            kal_trace(
                TRACE_INFO,
                FUNC_JBT_ADDR,
                rsp->bd_addr[0],
                rsp->bd_addr[1],
                rsp->bd_addr[2],
                rsp->bd_addr[3],
                rsp->bd_addr[4],
                rsp->bd_addr[5]);
        }
            break;
        case JBT_OPCODE_GET_LOCAL_DISCOVERY_MODE:
        {
            jbt_get_local_discovery_mode_result *rsp;

            rsp = (jbt_get_local_discovery_mode_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->result);
            kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->mode);
        }
            break;
        case JBT_OPCODE_GET_LOCAL_COD:
        {
            jbt_get_local_cod_result *rsp;

            rsp = (jbt_get_local_cod_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->result);
            kal_trace(TRACE_INFO, FUNC_JBT_SHOW_COD, rsp->cod);
        }
            break;

        case JBT_OPCODE_SET_LOCAL_DISCOVERY_MODE:
        {
            jbt_set_local_discovery_result *rsp;

            rsp = (jbt_set_local_discovery_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->result);
        }
            break;
        case JBT_OPCODE_SET_LOCAL_COD:
        {
            jbt_set_local_cod_result *rsp;

            rsp = (jbt_set_local_cod_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->result);
            /* jbt_power_off_cmd(0x10); */
        }
            break;
        case JBT_OPCODE_GET_REMOTE_NAME:
        {
        #if 0
/* under construction !*/
/* under construction !*/
        #endif /* 0 */ 
            kal_uint16 attribute_p2[] = {0x0001};   /* ServiceClassIDList */
            jbt_get_remote_name_result *rsp;

            rsp = (jbt_get_remote_name_result*) parm;

            kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->result);
            kal_trace(
                TRACE_INFO,
                FUNC_JBT_ADDR,
                rsp->addr[0],
                rsp->addr[1],
                rsp->addr[2],
                rsp->addr[3],
                rsp->addr[4],
                rsp->addr[5]);
            {
                kal_uint16 k = 0;

                kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->length);
                for (k = 0; k < rsp->length; k++)
                {
                    kal_trace(TRACE_INFO, FUNC_JBT_SHOW_NAME, rsp->name[k], rsp->name[k]);
                }
            }
            /* Do SDP SSA cmd */
            /* jbt_sdap_ssa_cmd(0x15,rsp->addr, uuid_p, 1, attribute_p, 1); */
            jbt_sdap_sa_cmd(0x15, rsp->addr, 0x00010001, attribute_p2, 1);

        }
            break;
        case JBT_OPCODE_GET_REMOTE_ACL_INFO:
        {
            jbt_get_acl_info_result *rsp;

            rsp = (jbt_get_acl_info_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->result);
            kal_trace(TRACE_INFO, FUNC_JBT_GET_ACL_INFO, rsp->is_master, rsp->is_authenticated, rsp->is_encrypted);
        }
            break;
        case JBT_OPCODE_SET_ACL_SECURITY_INFO:
        {
            jbt_set_acl_security_result *rsp;

            rsp = (jbt_set_acl_security_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_UT_SET_ACL_SECURITY_INFO);
            kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->result);
            kal_trace(
                TRACE_INFO,
                FUNC_JBT_ADDR,
                rsp->bdAddr[0],
                rsp->bdAddr[1],
                rsp->bdAddr[2],
                rsp->bdAddr[3],
                rsp->bdAddr[4],
                rsp->bdAddr[5]);
        }
            break;
        case JBT_OPCODE_DEVICE_DISCOVERY_RESULT:
        {
            jbt_device_discovery_entry_result *rsp;

            rsp = (jbt_device_discovery_entry_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_SHOW_COD, rsp->cod);
            kal_trace(
                TRACE_INFO,
                FUNC_JBT_ADDR,
                rsp->addr[0],
                rsp->addr[1],
                rsp->addr[2],
                rsp->addr[3],
                rsp->addr[4],
                rsp->addr[5]);
            {
                kal_uint16 k = 0;

                kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->length);
                for (k = 0; k < rsp->length; k++)
                {
                    kal_trace(TRACE_INFO, FUNC_JBT_SHOW_NAME, rsp->name[k], rsp->name[k]);
                }
            }
        }
            break;
        case JBT_OPCODE_DEVICE_DISCOVERY_COMPLETED:
            kal_trace(TRACE_INFO, FUNC_JBT_UT_INQUIRY_COMPLETED);
            {
                jbt_device_discovery_completed_result *rsp;

                rsp = (jbt_device_discovery_completed_result*) parm;
                kal_trace(TRACE_INFO, FUNC_JBT_RESULT, rsp->result);
            }
            break;
            /*      SDPDB               */
            /*      SDPDB               */
            /*      SDPDB               */
            /*      SDPDB               */
            /*      SDPDB               */
            /*      SDPDB               */
        case JBT_OPCODE_GET_RECORD_HANDLE:
        {
            jbt_get_record_handle_result *rsp;

            rsp = (jbt_get_record_handle_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_SDPDB_GET_RECORD_HDL, rsp->result, rsp->record_handle);
            if (rsp->result == 0x00)
            {
                /* jbt_register_record_cmd(0x01, rsp->record_handle, bt_sdp_test_pattern, sizeof(bt_sdp_test_pattern), 0); */
                jbt_register_record_cmd(
                    0x01,
                    rsp->record_handle,
                    bt_sdp_spp_test_pattern02,
                    sizeof(bt_sdp_spp_test_pattern02),
                    0);
            }
        }
            break;
        case JBT_OPCODE_REGISTER_RECORD_RESULT:
        {
            jbt_register_record_result *rsp;

            rsp = (jbt_register_record_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_SDPDB_REGISTER_RECORD_RESULT, rsp->result, rsp->record_handle);
        }
            break;
        case JBT_OPCODE_DEREGISTER_RECORD_RESULT:
        {
            jbt_deregister_record_result *rsp;

            rsp = (jbt_deregister_record_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_SDPDB_DEREGISTER_RECORD_RESULT, rsp->result, rsp->record_handle);
        }
            break;
        case JBT_OPCODE_SESSION_REGISTRATION_RESULT:
        {
            jbt_session_registration_result *rsp;

            rsp = (jbt_session_registration_result*) parm;
            kal_trace(
                TRACE_INFO,
                FUNC_JBT_SESSION_REGISTRATION_RESULT,
                rsp->result,
                rsp->transaction_id,
                rsp->psm_channel,
                rsp->con_id);
            if (rsp->result == JBT_CMD_SUCCESS)
            {
                kal_uint8 status_result = 0;
                jbt_session_service_turn_on(rsp->ps_type, rsp->con_id, (++jbt_ut_transaction_id) + 1000, &status_result);
            }
            /* jbt_set_local_cod_cmd(0x05, 0x110011); */
        }
            break;
        case JBT_OPCODE_SESSION_TURN_ON_RESULT:
        {
            static kal_uint8 count = 0;
            jbt_session_turnon_result *rsp;

            rsp = (jbt_session_turnon_result*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_SESSION_TURNON_RESULT, rsp->result, rsp->transaction_id, rsp->con_id);
            if ((rsp->result == JBT_CMD_SUCCESS) && (count == 0))
            {
                count++;
                jbt_session_service_registration_use_existing_chnl_num(
                    JSR82_SESSION_PS_RFCOMM,
                    JSR82_SESSION_PS_RFCOMM_MTU,
                    0x00,
                    (++jbt_ut_transaction_id) + 1000,
                    12);
            }
            else if ((rsp->result == JBT_CMD_SUCCESS) && (count == 1))
            {
                kal_uint8 status_result = 0;
                count++;
                /* Register L2CAP service */
                jbt_session_service_registration(JSR82_SESSION_PS_L2CAP, JSR82_SESSION_PS_L2CAP_MTU, 0x00, (++jbt_ut_transaction_id) + 1000, &status_result);
            }

        }
            break;
        case JBT_OPCODE_SESSION_TURN_OFF_RESULT:
        {
            jbt_session_turnoff_result *rsp;

            rsp = (jbt_session_turnoff_result*) parm;
        }
            break;
        case JBT_OPCODE_SESSION_CON_IND:
        {
            jbt_session_connect_ind *con_ind;

            con_ind = (jbt_session_connect_ind*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_SESSION_CON_IND, con_ind->result, con_ind->transaction_id, con_ind->con_id);

            jbt_ut_write.session_inx = con_ind->con_id;
            jbt_ut_write.l2cap_id = con_ind->l2cap_id;
            jbt_ut_write.tmp_buf_position = 0;
            jbt_ut_write.f_handle = FS_FILE_NOT_FOUND;
            jbt_ut_read.session_inx = con_ind->con_id;
            jbt_ut_read.l2cap_id = con_ind->l2cap_id;
            jbt_ut_read.tmp_buf_position = 0;
            /* Config the first time wanted read length for GetBytes() when receiving ready_to_read_ind later */
            jbt_ut_read.wanted_access_length_this_time = 329;
            jbt_ut_read.f_handle = FS_FILE_NOT_FOUND;

            jbt_ut_rw_acceptor.session_inx = con_ind->con_id;
            jbt_ut_rw_acceptor.l2cap_id = con_ind->l2cap_id;
            /* Add by mtk01411: 2007-1109 */
        #ifdef __USE_BT_RING_BUF_API__
            RING_BufInit(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.app_buf, 329);
        #else 
            JBTRING_BufInit(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.app_buf, 329);
        #endif 

            /* jbt_session_disconnect_req(1000, JSR82_SESSION_PS_RFCOMM, con_ind->con_id); */
        }
            break;
        case JBT_OPCODE_SESSION_CON_CNF:
        {
            jbt_session_connect_cnf *con_cnf;

            con_cnf = (jbt_session_connect_cnf*) parm;
            jbt_ut_write.session_inx = con_cnf->con_id;
            jbt_ut_write.l2cap_id = con_cnf->l2cap_id;
            jbt_ut_write.tmp_buf_position = 0;
            jbt_ut_write.f_handle = FS_FILE_NOT_FOUND;
            jbt_ut_read.session_inx = con_cnf->con_id;
            jbt_ut_read.l2cap_id = con_cnf->l2cap_id;
            jbt_ut_read.tmp_buf_position = 0;
            /* Config the first time wanted read length for GetBytes() when receiving ready_to_read_ind later */
            jbt_ut_read.wanted_access_length_this_time = 329;
            jbt_ut_read.f_handle = FS_FILE_NOT_FOUND;

            jbt_ut_rw_acceptor.session_inx = con_cnf->con_id;
            jbt_ut_rw_acceptor.l2cap_id = con_cnf->l2cap_id;
            /* Add by mtk01411: 2007-1109 */
        #ifdef __USE_BT_RING_BUF_API__
            RING_BufInit(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.app_buf, 329);
        #else 
            JBTRING_BufInit(&jbt_ut_rw_acceptor.AppRingBuf, (char*)jbt_ut_rw_acceptor.app_buf, 329);
        #endif 
            kal_trace(
                TRACE_INFO,
                FUNC_JBT_UT_RW_PTR,
                jbt_ut_rw_acceptor.AppRingBuf.pStart,
                jbt_ut_rw_acceptor.AppRingBuf.pRead,
                jbt_ut_rw_acceptor.AppRingBuf.pWrite,
                jbt_ut_rw_acceptor.AppRingBuf.pEnd);
            kal_trace(
                TRACE_INFO,
                FUNC_JBT_SESSION_CON_REQ_RESULT,
                con_cnf->result,
                con_cnf->transaction_id,
                con_cnf->con_id);

            kal_trace(TRACE_INFO, FUNC_JBT_SESSION_CON_IND, con_cnf->result, con_cnf->transaction_id, con_cnf->con_id);

            if (con_cnf->result == JBT_CMD_SUCCESS)
            {
                kal_uint8 status_result = 0;
                jbt_session_disconnect_req(1000, JSR82_SESSION_PS_L2CAP, con_cnf->con_id, con_cnf->l2cap_id, &status_result);
            }

        }
            break;
        case JBT_OPCODE_SESSION_RX_READY_IND:
        {
            jbt_session_rx_ready_ind *rx_ind;

            rx_ind = (jbt_session_rx_ready_ind*) parm;
            jbt_ut_read.l2cap_id = rx_ind->l2cap_id;
            kal_trace(TRACE_INFO, FUNC_JBT_SESSION_RX_READY_IND, rx_ind->con_id, rx_ind->length);
            Jbt_ut_ready_to_read_ind_hdler();

        }
            break;

        case JBT_OPCODE_SESSION_TX_READY_IND:
        {
            jbt_session_tx_ready_ind *tx_ind;

            tx_ind = (jbt_session_tx_ready_ind*) parm;
            jbt_ut_write.l2cap_id = tx_ind->l2cap_id;
            kal_trace(TRACE_INFO, FUNC_JBT_SESSION_TX_READY_IND, tx_ind->con_id);
            Jbt_ut_ready_to_write_ind_hdler();
        }
            break;

        case JBT_OPCODE_SESSION_DISCONNECT_IND:
        {
            jbt_session_disconnect_ind *disc_ind;

            disc_ind = (jbt_session_disconnect_ind*) parm;
            kal_trace(TRACE_INFO, FUNC_JBT_DISC_IND, disc_ind->con_id);
            Jbt_ut_reset_all_rw_access_hdler();
        }
            break;
    }
}
#endif /* __SUPPORT_JBT__ */ 
#endif /* _JBT_UT_C */ 

