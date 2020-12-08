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

/*******************************************************************************
 * Filename:
 * ---------
 * drm_core_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for ¡K.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *******************************************************************************/
#ifndef DRM_CORE_DEF_H
#define DRM_CORE_DEF_H
#ifdef __DRM_MTK__

#include "drm_def.h"
#include "kal_general_types.h"
#include "fs_type.h"

#define DRM_RO_PATH L"z:\\@DRM\\ro\\"
#define DRM_TEMP_DECODE_FILE L"Z:\\@DRM\\tmp"


#define DRM_MAX_WBXML_SIZE    512

#ifdef __HW_CHE__
#define DRM_CRYPTO_WKBUF_SIZE (2 * 1024 - 48)
#else 
#define DRM_CRYPTO_WKBUF_SIZE (2 * 1024 - 16)
#endif 

/* new SAP for MMS virtual file - start */
#define DRM_DCF_FL_FIXED_HEADER    "Encryption-Method:AES128CBC;padding=RFC2630;plaintextlen=%010d\r\nRight-Issuer:[FL]\r\n"
#define DRM_DCF_FL_FIXED_HEADER_SIZE       90      /*--Encryption-Method:AES128CBC;padding=RFC2630;plaintextlen=0000057314\r\nRight-Issuer:[FL]\r\n*/

#define DRM_DCF_CD_FIXED_HEADER    "Encryption-Method:AES128CBC;padding=RFC2630\r\nRight-Issuer:[CD]\r\n"
#define DRM_DCF_CD_FIXED_HEADER_SIZE       66      /*--Encryption-Method:AES128CBC;padding=RFC2630\r\nRight-Issuer:[CD]\r\n*/

/* new SAP for MMS virtual file - end */

#define DRM_MAX_CID_PATTERN_LENGTH     14  /*MTK_FLDCF_cid:*/
#define DRM_MAX_CID_URL_LENGTH            (DRM_MAX_URL_LENGTH + DRM_MAX_CID_PATTERN_LENGTH)
#define DRM_FL_SIGNATURE_LEN           (1 + DRM_MAX_KEY_LENGTH) /* 1 byte offset + fl signature */


#define DRM_TOKEN_CONTENT_TYPE          "content-type:"
#define DRM_TOKEN_ENCODING_TYPE         "content-transfer-encoding:"
#define DRM_TOKEN_CONTENT_ID            "content-id:"
#define DRM_TOKEN_RIGHTS_ISSUER         "rights-issuer:"
#define DRM_TOKEN_BOUNDARY              "--boundary"
#define DRM_TOKEN_RIGHTS                "<o-ex:rights"

#define DRM_WB_RIGHTS_TAG       0x05
#define DRM_WB_CONTEXT_TAG      0x06
#define DRM_WB_VERSION_TAG      0x07
#define DRM_WB_AGREEMENT_TAG    0x09
#define DRM_WB_ASSET_TAG        0x0a
#define DRM_WB_UID_TAG          0x08
#define DRM_WB_KEYINFO_TAG      0x0b
#define DRM_WB_KEYVALUE_TAG     0x0c
#define DRM_WB_PERMISSION_TAG   0x0d
#define DRM_WB_CONSTRAINT_TAG   0x12
#define DRM_WB_PLAY_TAG         0x0e
#define DRM_WB_DISPLAY_TAG      0x0f
#define DRM_WB_PRINT_TAG        0x11
#define DRM_WB_EXECUTE_TAG      0x10
#define DRM_WB_COUNT_TAG        0x13
#define DRM_WB_DATETIME_TAG     0x14
#define DRM_WB_INTERVAL_TAG     0x17
#define DRM_WB_START_TAG        0x15
#define DRM_WB_END_TAG          0x16

typedef enum
{
    DRM_TYPE_FORWARD_LOCK,
    DRM_TYPE_COMBINED_DELIVERY,
    DRM_TYPE_SEPARATE_DELIVERY_CONTENT,
    DRM_TYPE_SEPARATE_DELIVERY_RIGHTS,
    DRM_TYPE_SEPARATE_DELIVERY_RIGHTS_WB
} drm_object_type_enum;

typedef enum
{
    DRM_ENCODING_INVALID,
    DRM_ENCODING_BINARY,
    DRM_ENCODING_BASE64
} drm_encoding_type_enum;

typedef enum
{
    DRM_WB_TAG_START,
    DRM_WB_TAG_END
}drm_wb_tag_type_enum;

typedef enum
{
    DRM_DB_GET     = 0x00,
    DRM_DB_KILL    = 0x01,
    DRM_DB_FL      = 0x02,
    DRM_DB_ALL     = 0x04,
    DRM_DB_VALID   = 0x08,
    DRM_DB_INVALID = 0x10,
    DRM_DB_HIDDEN  = 0x20
}drm_proc_db_enum;

typedef enum
{
    DRM_CONSTRAINT_PLAY_INDEX = 0,
    DRM_CONSTRAINT_DISPLAY_INDEX,
    DRM_CONSTRAINT_EXECUTE_INDEX,
    DRM_CONSTRAINT_PRINT_INDEX,
    DRM_CONSTRAINT_TOTAL_INDEX
} drm_constraint_index;

typedef enum
{
    DRM_CONSTRAINT_HIGH = 0,
    DRM_CONSTRAINT_EQUAL,
    DRM_CONSTRAINT_LOW
} drm_constraint_priority_enum;
#define DRM_MULTIRO_COUNT(x) (x[0] + x[1] + x[2] + x[3])

#define DRM_CONSTRAINT_SIZE sizeof(drm_constraint_struct)
#define DRM_RIGHTS_SIZE sizeof(drm_rights_struct)
#define DRM_CONSTRAINT_ENTRY_SIZE sizeof(drm_constraint_entry_struct)

typedef struct
{
    drm_constraint_struct cons;
    kal_uint32 next;
    kal_uint32 status;
} drm_constraint_entry_struct;

typedef struct
{
    kal_uint8 key[DRM_MAX_KEY_LENGTH];
    kal_uint8 iv[DRM_MAX_KEY_LENGTH];
    kal_uint32 offset;            /*Data offset, inside DRM file (propriety dcf format)*/
    kal_uint32 data_len;          /*DRM content length*/
    kal_uint32 mime_type;
    drm_constraint_entry_struct *constraint_list;    
    kal_uint8 best[4];
    kal_uint8 key_len;
    kal_uint8 permission;
    kal_uint8 status;
    kal_uint8 method;
    kal_uint8 num[4];   /* number of constraint appended after original RO */
} drm_rights_struct;

typedef struct
{
    drm_rights_struct *rights;
    kal_wchar *content_path;
    kal_char *meta[DRM_META_01_TOTAL];
} drm_info_struct;

typedef struct
{
    kal_uint32 len;
    kal_uint32 offset;
    kal_uint8 data[DRM_MAX_WBXML_SIZE];
} DRM_WBXML_RIGHTS_STRUCT;

typedef struct
{
    FS_HANDLE ro;       /* NULL: non DRM, handle: FL, CD, SD */
    FS_HANDLE handle;   /* Native Handle */
    kal_int64 start;    /* start address of cache in originial file */
    kal_int64 position; /* position in originial file */
    kal_int64 end;      /* end adress of cache in originial file */
    kal_uint32 dcf_size;     /* file size of DCF */
    kal_int32 previous_blk;  /* the previous cached block number */
    kal_uint32 *size_log;
    kal_uint32 *posi_log;
    kal_uint8 *cache;   /* cache buffer */
    drm_info_struct *info;
} drm_handle_struct;


typedef struct
{
    kal_int32 ro_index;
    kal_uint32 ro_count;
    drm_rights_struct rights;
    kal_bool  key_assigned;
    kal_uint8 key_buf[DRM_MAX_KEY_LENGTH];
    kal_uint8 is_ro_update;
} drm_cntx_struct;


#endif /* __DRM_MTK__ */ 

#endif /* DRM_CORE_DEF_H */ 

