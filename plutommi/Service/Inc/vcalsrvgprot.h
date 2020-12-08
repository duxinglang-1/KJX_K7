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
 * Vcalsrvgprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * This file defines function prototypes used in vcalendar application.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef VCAL_SERVICE_GPROT_H
#define VCAL_SERVICE_GPROT_H
#include "MMI_features.h"
#if ((defined(__MMI_CALENDAR_EVENT__) || defined(__MMI_TODOLIST__)) && !defined(__COSMOS_MMI_PACKAGE__)) || defined(__COSMOS_MMI_PACKAGE__)
//#ifdef __MMI_SRV_TODOLIST__

/******************************************************************************* 
 * Include 
 *******************************************************************************/
#include "MMIDataType.h"
#include "custom_mmi_default_value.h"
#include "Conversions.h"
#include "fs_type.h"

/*****************************************************************************
 * Const definitions
 *****************************************************************************/
#define  SRV_VCAL_R_FOREVER_STR       " #0"
#define  SRV_VCAL_PARA_SEP_STR        ";"
#define  SRV_VCAL_VALUE_SEP_STR       ":"
#define  SRV_VCAL_EQUAL_STR           "="
#define  SRV_VCAL_CHARSET_UTF8        "UTF-8"
#define  SRV_VCAL_PARA_SEP_CHAR       ';'
#define  SRV_VCAL_VALUE_SEP_CHAR      ':'
#define  SRV_VCAL_NULL                '\0'
#define  SRV_VCAL_ES_CHAR             0x5C        /* "\" */
#define  SRV_VCAL_LWSP_CHAR           0x20
#define  SRV_VCAL_TAB_CHAR            0x09
#define  SRV_VCAL_MAX_DT_LEN          32
#define  SRV_VCAL_NUM_OF_DAYS          7
#define  SRV_VCAL_MIN_RECURR_LEN       5
#define  SRV_VCAL_MAX_PARAM_LEN       24
#define  SRV_VCLADR_MAX_DATE_TIME_LEN  (16)
#define  SRV_VCAL_DT_SEP_CHAR         'T'      /* seperator of date and time */
#define  SRV_VCAL_UTC_CHAR            'Z'
#define  SRV_VCAL_POUND_CHAR          '#'

/* vCal encoding type */
typedef enum
{
    SRV_VCAL_EN_7BIT,                     /* 7-bit encoding */
    SRV_VCAL_EN_8BIT,                     /* 8-bit encoding */
    SRV_VCAL_EN_QP,                       /* Quoted-Printable */
    SRV_VCAL_EN_BASE64,                   /* Base64 */
    SRV_VCAL_EN_OTHERS,                   /* X-xxxx */
    SRV_VCAL_EN_TOTAL
} srv_vcal_ecoding_type_enum;

/* vCal charset */
typedef enum
{
    SRV_VCAL_CH_UTF8,
    SRV_VCAL_CH_BIG5,
    SRV_VCAL_CH_UTF7,
    SRV_VCAL_CH_TOTAL
} srv_vcal_charset_type_enum;
 
/* vCalendar type */
typedef enum
{
    SRV_VCAL_VEVENT,  /* vEvent */
    SRV_VCAL_VTODO,       /* vTodo */
    SRV_VCAL_VTYPE_END_OF_ENUM
} srv_vcal_type_enum;

typedef enum
{
    SRV_VCAL_RESULT_SUCCESS,                 /* Save/Parse success */
    SRV_VCAL_RESULT_BUFF_ERROR,
    SRV_VCAL_RESULT_FS_ERROR,
    SRV_VCAL_RESULT_UNSUPPORT_FORMAT,        /* Unsupport format, save failed */
    SRV_VCAL_RESULT_UNKNOW_ERROR,
    SRV_VCAL_RESULT_END_OF_ENUM
} srv_vcal_error_enum;

typedef enum
{
    SRV_VCAL_VER_VCAL_1_0,
    SRV_VCAL_VER_ICAL,
    SRV_VCAL_VER_TOTAL
}srv_vcal_ver_enum;

typedef enum
{
    SRV_VCAL_CATEGORY_TYPE_REMINDER,
    SRV_VCAL_CATEGORY_TYPE_MEETING,
    SRV_VCAL_CATEGORY_TYPE_COURSE,
    SRV_VCAL_CATEGORY_TYPE_DATE,
    SRV_VCAL_CATEGORY_TYPE_CALL,
    SRV_VCAL_CATEGORY_TYPE_ANNIVERSARY,
    SRV_VCAL_CATEGORY_TYPE_BIRTHDAY,
    SRV_VCAL_CATEGORY_TYPE_TOTAL
}srv_vcal_category_type_enum;

typedef enum
{
    SRV_VCAL_STATUS_UNDONE,
    SRV_VCAL_STATUS_DONE,
    SRV_VCAL_STATUS_TOTAL
}srv_vcal_status_enum;

typedef enum
{
    SRV_VCAL_PRIORITY_LOW,
    SRV_VCAL_PRIORITY_MEDIUM,
    SRV_VCAL_PRIORITY_HIGH,
    SRV_VCAL_PRIORITY_TOTAL
}srv_vcal_priority_enum;

typedef enum
{
    SRV_VCAL_ALARM_OFF,
    SRV_VCAL_ALARM_ON,
    SRV_VCAL_ALARM_BEFORE_5_MINS,
    SRV_VCAL_ALARM_BEFORE_10_MINS,
    SRV_VCAL_ALARM_BEFORE_15_MINS,
    SRV_VCAL_ALARM_BEFORE_30_MINS,
    SRV_VCAL_ALARM_CUSTOM,
    SRV_VCAL_ALARM_TOTAL
} srv_vcal_alarm_enum;

typedef enum
{
    SRV_VCAL_RULE_ONCE,
    SRV_VCAL_RULE_DAILY,
    SRV_VCAL_RULE_DAYS,
    SRV_VCAL_RULE_WEEKLY,
    SRV_VCAL_RULE_MONTHLY,
    SRV_VCAL_RULE_YEARLY,
    SRV_VCAL_RULE_TITHI,
    SRV_VCAL_RULE_TOTAL
}srv_vcal_repeat_rule_enum;


/* The structure of the builder handle. */
typedef struct
{
    FS_HANDLE fh;         /* file handle to generate vcal */
    S32 curr_obj_number;  /* used by srv_vcal_build_get_object_number */
    srv_vcal_type_enum curr_vcal_type;    /* pass to internal functions */
    void *curr_src_obj;   /* value of input object pointer */
} srv_vcal_build_struct;

/* This is the structure of the handle */
typedef struct
{
    FS_HANDLE fh;                 /* file handle of source vcal file to parse */
    S32 current_obj_number;       /* used by srv_vcal_parse_get_object_number */
    U8 curr_vcal_type;            /* vtype of parsing object */
    U8 vcal_version;              /* vcal 1.0 or icalendar */
    mmi_chset_enum encode_type;   /* Encoding charset */
    void *curr_parsed_object;     /* pointer of the last parsed object */
    U8 ref_count;                 /* to check the buffer is free or not */
    U32 fs_curr_parse_pos;        /* current parsed position of the file */
    U32 parsed_field;             /* have parsed filed */
} srv_vcal_parse_struct;

/*****************************************************************************
 * Enumeration definitions
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_vcal_build_begin
 * DESCRIPTION
 *  To begin the vcalendr builder and return the builder handle.
 * PARAMETERS
 *  file_path : [IN]The path to build to. Contains the file path and file name.
 *  vcal_version : [IN]vCal/iCal version.
 * RETURNS
 *  Error cause
 *****************************************************************************/
extern void* srv_vcal_build_begin(const U16 *file_path, srv_vcal_ver_enum vcal_version);


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_build_add
 * DESCRIPTION
 *  To build the object into the destination file.
 *  User can call this API repetitiously to go on building new object into 
 *  the same vcalendar file. So it can support multi object into one file.
 * PARAMETERS
 *  handle : [IN] The value returned by srv_vcal_build_begin.
 *  object : [IN] The type conversion is according to the vcal_type.
 *           To be srv_tdl_v=event_struct or srv_tdl_task_struct.
 *  vcal_type : [IN] Can be SRV_VCAL_VEVENT or SRV_VCAL_VTODO.
 * RETURNS
 *  Error cause
 *****************************************************************************/
extern S32 srv_vcal_build_add(void *handle, const void *object, srv_vcal_type_enum vcal_type);


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_build_get_object_number
 * DESCRIPTION
 *  To get the total number of the objects in the current generated vcalendar file.
 * PARAMETERS
 *  handle : [IN] The value returned by srv_vcal_build_begin.
 *  number : [OUT] The number builded.
 * RETURNS
 *  Error cause
 *****************************************************************************/
extern S32 srv_vcal_build_get_object_number(void *handle, U32 *number);


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_utility_get_vtype
 * DESCRIPTION
 *  To get the first vcalendar type.
 * PARAMETERS
 *  file_path : [IN] file patch that will be parsed
 *  vtype :     [OUT] the vcalendar type: vevent or vtodo
 * RETURNS
 *  Error cause
 *****************************************************************************/
extern S32 srv_vcal_utility_get_vtype(const U16* file_path, U16 *vtype);


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_build_end
 * DESCRIPTION
 *  To close file and free buffer.
 * PARAMETERS
 *  handle : [IN] The value returned by srv_vcal_build_begin.
 * RETURNS
 *  Error cause
 *****************************************************************************/
extern S32 srv_vcal_build_end(void *handle);


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_begin
 * DESCRIPTION
 *  To begin the vcalendar parsing and return the parser handle.
 * PARAMETERS
 *  ptask : [IN]Task to be convert.
 *  default_encode_type : [IN]The default encoding type used in vcalendar file.
 * RETURNS
 *  Error cause
 *****************************************************************************/
extern void* srv_vcal_parse_begin(const U16 *file_path, mmi_chset_enum default_encode_type);

/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse
 * DESCRIPTION
 *  To begin the vcalendar parsing and return the parser handle.
 * PARAMETERS
 *  file_path : [IN]The path to build to. Contains the file path and file name.
 *  object : [OUT] The value is allocated by vcalendr service.
 *  vcal_type : [OUT] Returen the object type.
 *  flag_finish : [IN] MMI_TRUE means finish to parse.
 *                     MMI_FALSE means still having other objects in the vcalendar file.
 * RETURNS
 *  Error cause
 *****************************************************************************/
extern S32 srv_vcal_parse(void *handle, void **object, srv_vcal_type_enum *vcal_type, U8 *flag_finish);

/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_free_object
 * DESCRIPTION
 *  To free the buffer of the last one parsed object.
 *  The buffer used by parsed object should be free every time before to get
 *  next parse object.
 * PARAMETERS
 *  file_path : [IN]The path to build to. Contains the file path and file name.
 *  object : [IN] The buffer to free.
 * RETURNS
 *  Error cause
 *****************************************************************************/
extern S32 srv_vcal_parse_free_object(void *handle, void *object);

/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_end
 * DESCRIPTION
 *  To free the buffer of the last one parsed object.
 *  The buffer used by parsed object should be free every time before to get
 *  next parse object.
 * PARAMETERS
 * RETURNS
 *  Error cause
 *****************************************************************************/
extern S32 srv_vcal_parse_end(void *handle);

#endif /* __MMI_SRV_TODOLIST__ */
#endif /* VCAL_SERVICE_GPROT_H */                    
