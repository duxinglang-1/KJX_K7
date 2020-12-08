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
 * vCalSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * vCalendar parse APIs.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"

#if ((defined(__MMI_CALENDAR_EVENT__) || defined(__MMI_TODOLIST__)) && !defined(__COSMOS_MMI_PACKAGE__)) || defined(__COSMOS_MMI_PACKAGE__)
//#ifdef __MMI_SRV_TODOLIST__
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "Vcalsrvgprot.h"
#include "vCalSrvProt.h"
#include "worldclock.h"
#include "app_qp.h"
#include "phonesetupgprots.h"
#include <ctype.h> 
#include "MMI_common_app_trc.h"
#include "DebugInitDef_Int.h"
#include "MMIDataType.h"
#include "fs_type.h"
#include "custom_mmi_default_value.h"
#include "kal_general_types.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "string.h"
#include "fs_func.h"
#include "mmi_common_app_trc.h"
#include "kal_trace.h"
#include "Conversions.h"
#include "gui_data_types.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "app_datetime.h"
#include "stdlib.h"
#include "DateTimeType.h"
#include "gui.h"
#include "app_qp.h"
//#include "PhoneSetupGprots.h "


/*****************************************************************************
 * Static declaration
 *****************************************************************************/
#define MMI_VCALSRV_TRACE0(sub_grp) \
            MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp)
    
#define MMI_VCALSRV_TRACE1(sub_grp, arg) \
            MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg)
            
#define MMI_VCALSRV_TRACE2(sub_grp, arg1, arg2) \
            MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2)
    
#define MMI_VCALSRV_TRACE3(sub_grp, arg1, arg2, arg3) \
            MMI_TRACE(MMI_COMMON_TRC_G2_ORG, sub_grp, arg1, arg2, arg3)
 
static const CHAR *const g_srv_vcal_fileds[SRV_VCAL_TOTAL_FILEDS] = 
{
    "BEGIN:VCALENDAR",          /* mandatory */
    "VERSION:1.0",              /* mandatory */
    "BEGIN:VEVENT",             /* mandatory */
    "BEGIN:VTODO",              /* mandatory */
    "DTSTART",                  /* mandatory */
    "DTEND",                    /* mandatory */
    "DUE",                      /* mandatory */
    "TZID",                     /* option */
    "SUMMARY",                  /* mandatory */
    "DESCRIPTION",              /* mandatory */
    "RRULE",                    /* option */
    "DALARM",                   /* option */
    "AALARM",                   /* option */
    "END:VTODO",                /* mandatory */
    "END:VEVENT",               /* mandatory */
    "END:VCALENDAR",            /* mandatory */
    "CLASS",                    /* option */
    "LOCATION",                 /* mandatory */
    "PRIORITY",                 /* mandatory */
    "COMPLETED",                /* mandatory */
    "LAST-MODIFIED",            /* option */
    "CATEGORIES",               /* mandatory */
    "STATUS",                   /* mandatory */
    "UID",                      /* option */
    "X-",                       /* option */
    "PRODID",                   /* option */
    "SEQUENCE"                  /* option */
};
static const CHAR *g_srv_vcal_encoding[SRV_VCAL_EN_TOTAL] = 
{
    "7BIT",
    "8BIT",
    "QUOTED-PRINTABLE",
    "BASE64",
    "X-"
};
static const CHAR *g_srv_vcal_charset[SRV_VCAL_CH_TOTAL] = 
{
    "UTF-8",
    "BIG5",
    "UTF-7"
};
static const CHAR *g_srv_vcal_paras[SRV_VCAL_PARA_TOTAL] = 
{
    "LANGUAGE",
    "CHARSET",
    "ENCODING"
};
static const CHAR *const g_srv_vcal_days[SRV_VCAL_NUM_OF_DAYS] = 
{
    "SU", "MO", "TU", "WE", "TH", "FR", "SA"
};
static const CHAR *const g_srv_vcal_recurr[SRV_VCAL_RECURR_TOTAL] = 
{
    "D1",
    "W1",
    "MD1",
    "YM1"
};
static S32 srv_vcal_task_build(const srv_tdl_task_struct *ptask, FS_HANDLE fh);
static S32 srv_vcal_event_build(const srv_tdl_event_struct *pevent, FS_HANDLE fh);
static void srv_vcal_build_string(CHAR *dest_buff, U16 dest_size, const CHAR *src_buff, U16 src_size);
static void srv_vcal_build_category(CHAR *out_buff, const U8 category);
static void srv_vcal_build_repeat(CHAR *out_buff, const srv_tdl_repeat_struct repeat, const MYTIME start_time);
static void srv_vcal_build_time(CHAR *out_buff, const U16 buff_size, const MYTIME date_time);
static U8 srv_vcal_build_priority(U8 priority_tdl);

static S32 srv_vcal_task_parse(srv_tdl_task_struct *ptask, srv_vcal_parse_struct *parse_handle);
static S32 srv_vcal_event_parse(srv_tdl_event_struct *pevent, srv_vcal_parse_struct *parse_handle);
static U8 srv_vcal_parse_priority(U8 priority_value);
static U16 srv_vcal_parse_repeat(CHAR *str_value, srv_tdl_repeat_struct *repeat);
static U16 srv_vcal_parse_string(CHAR *line_p, CHAR *value_p, CHAR *out_buff, U16 buff_size);
static U16 srv_vcal_parse_time(CHAR *str_time, MYTIME *date_time);
static U8 srv_vcal_parse_recurr(CHAR *str_rrule, srv_vcal_recurr_struct *recurr);
static U8 srv_vcal_parse_days(CHAR *str_days);
static U8 srv_vcal_parse_encoding_para(CHAR *source, CHAR *para_name, CHAR *result, S32 max_len);
static U8 srv_vcal_parse_charset(CHAR *string);
static U8 srv_vcal_parse_encoding_type(CHAR *string);
static CHAR srv_vcal_parse_strnicmp(CHAR *src, CHAR *dest, S32 maxlen);
static U8 srv_vcal_parse_cmp_filed(CHAR *src_string, const CHAR *ref_string);
static void srv_vcal_parse_remove_ws(CHAR *str, CHAR *seperator, U8 position);
static U8 srv_vcal_parse_get_field(CHAR *str);
static S32 srv_vcal_parse_get_line(CHAR *strOutput, srv_vcal_parse_struct *parse_handle);
static CHAR *srv_vcal_parse_get_value(CHAR *str_string);
static CHAR* srv_vcal_build_strcpy(CHAR* dst, const CHAR* src);
static CHAR* srv_vcal_stristr(const CHAR *src_str, const CHAR *tbf_str);
static void srv_vcal_set_filed_mask(U32 *field_mask, U16 field_type);
static MMI_BOOL srv_vcal_check_filed_mask(U32 field_mask, U16 field_type);


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
void* srv_vcal_build_begin(const U16 *file_path, srv_vcal_ver_enum vcal_version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_build_struct *handle;
    S32 result, len, write_byte;
    CHAR *vcal_build_buff = NULL;
    CHAR *curr_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = (srv_vcal_build_struct*)OslMalloc(sizeof(srv_vcal_build_struct));
    memset(handle, 0, sizeof(srv_vcal_build_struct));
    handle->fh = FS_Open((U16*)file_path, FS_READ_WRITE | FS_CREATE_ALWAYS); 
    vcal_build_buff = OslMalloc(SRV_VCAL_BUILD_HEADER_LEN);
    
    if (handle->fh <= 0)
    {
        result = handle->fh;
        goto SRV_VCAL_ERROR_CLEAN;
    }
    /* BEGIN:VCALENDAR */
    curr_p = srv_vcal_build_strcpy(vcal_build_buff, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_BEGIN]);    
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);

    /* VERSION */
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_VERSION]);    
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);

    len = strlen(vcal_build_buff);
    MMI_ASSERT(len <= SRV_VCAL_BUILD_HEADER_LEN);
    result = FS_Write(handle->fh, vcal_build_buff, len, (UINT*)&write_byte);

SRV_VCAL_ERROR_CLEAN:   
    MMI_VCALSRV_TRACE1(MMI_VCALSRV_BUILD_BEGIN, result); 
    if (result < 0)
    {
        FS_Close(handle->fh);       
        FS_Delete((U16*)file_path);
        handle->fh = result;
    }
    MMI_VCALSRV_TRACE1(MMI_VCALSRV_BUILD_BEGIN, result); 
    OslMfree(vcal_build_buff);
    return handle;
}


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
 *           To be srv_tdl_event_struct or srv_tdl_task_struct.
 *  vcal_type : [IN] Can be SRV_VCAL_VEVENT or SRV_VCAL_VTODO.
 * RETURNS
 *  Error cause
 *****************************************************************************/
S32 srv_vcal_build_add(void *handle, const void *object, srv_vcal_type_enum vcal_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_VCAL_RESULT_SUCCESS;
    srv_vcal_build_struct *build_handle = handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(object);

    MMI_VCALSRV_TRACE2(
            MMI_VCALSRV_BUILD_ADD_ENTER, 
            build_handle->fh,  
            vcal_type); 
    
    if (build_handle->fh <= 0)
    {
        result = build_handle->fh;
        goto SRV_VCAL_ERROR_CLEAN;
    }
    if (SRV_VCAL_VEVENT == vcal_type)
    {
        result = srv_vcal_event_build((const srv_tdl_event_struct*)object, build_handle->fh);
        build_handle->curr_obj_number++;
        build_handle->curr_src_obj = (void*)object;
        build_handle->curr_vcal_type = SRV_VCAL_VEVENT;
    }
    else
    {
        result = srv_vcal_task_build((const srv_tdl_task_struct*)object, build_handle->fh);
        build_handle->curr_obj_number++;
        build_handle->curr_src_obj = (void*)object;
        build_handle->curr_vcal_type = SRV_VCAL_VTODO;        
    }
    
SRV_VCAL_ERROR_CLEAN:
    /* Trace result, curr_obj_number, curr_src_obj, curr_vcal_type  */
    MMI_VCALSRV_TRACE3(
            MMI_VCALSRV_BUILD_ADD_LEAVE, 
            build_handle->curr_obj_number,  
            build_handle->curr_src_obj,
            build_handle->curr_vcal_type); 
    
    return result;
}


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
S32 srv_vcal_build_get_object_number(void *handle, U32 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_build_struct *build_handle = handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_VCALSRV_TRACE1(MMI_VCALSRV_BUILD_GET_NUMBER, build_handle->curr_obj_number); 
    *number = build_handle->curr_obj_number;
    return SRV_VCAL_RESULT_SUCCESS;
}


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
S32 srv_vcal_build_end(void *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_build_struct *build_handle = handle;
    U32 result, write_byte, len;
    CHAR *vcal_build_buff = NULL;
    CHAR *curr_p;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcal_build_buff = OslMalloc(SRV_VCAL_BUILD_TAIL_LEN);
    
    if (build_handle->fh <= 0)
    {
        result = build_handle->fh;
        goto SRV_VCAL_ERROR_CLEAN;
    }
    /* END:VCALENDAR */
    curr_p = srv_vcal_build_strcpy(vcal_build_buff, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_END]);    
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);    
            
    len = strlen(vcal_build_buff);
    MMI_ASSERT(len <= SRV_VCAL_BUILD_TAIL_LEN);
    result = FS_Write(build_handle->fh, vcal_build_buff, len, (UINT*)&write_byte);

SRV_VCAL_ERROR_CLEAN:    
    FS_Close(build_handle->fh);
    OslMfree(vcal_build_buff);
    OslMfree(build_handle);
    MMI_VCALSRV_TRACE1(MMI_VCALSRV_BUILD_END, result);     
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_begin
 * DESCRIPTION
 *  To begin the vcalendar parsing and return the parser handle.
 * PARAMETERS
 *  file_path : [IN]The path to build to. Contains the file path and file name.
 *  default_encode_type : [IN]The default encoding type used in vcalendar file.
 * RETURNS
 *  Error cause
 *****************************************************************************/
void* srv_vcal_parse_begin(const U16 *file_path, mmi_chset_enum default_encode_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_parse_struct *handle;
    S32 result = SRV_VCAL_RESULT_SUCCESS;
    CHAR *line_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = (srv_vcal_parse_struct*)OslMalloc(sizeof(srv_vcal_parse_struct));
    memset(handle, 0, sizeof(srv_vcal_parse_struct));
    handle->fh = FS_Open((U16*)file_path, FS_READ_ONLY);
    handle->vcal_version = SRV_VCAL_VER_VCAL_1_0;
    handle->encode_type = default_encode_type;
    line_buff = OslMalloc(SRV_VCAL_PARSE_BUFF_LEN);
    
    if (handle->fh <= 0)
    {
        result = handle->fh;
        goto SRV_VCAL_ERROR_CLEAN;
    }                
    /* BEGIN:VCALENDAR(mandatory): it must be the first field */
    if (srv_vcal_parse_get_line(line_buff, handle) != 0)
    {
        srv_vcal_parse_remove_ws(
                line_buff, 
                (CHAR*)SRV_VCAL_SEP_STR, 
                SRV_VCAL_REMOVE_BOTH_WS);
                        
        if (srv_vcal_parse_get_field(line_buff) != SRV_VCAL_BEGIN)
        {
            result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
            goto SRV_VCAL_ERROR_CLEAN;
        }
    }
    else 
    {
        result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
        goto SRV_VCAL_ERROR_CLEAN;
    }
    
    /* VERSION(mandatory), it must appear within the vcalendar, no matter where */
    while (srv_vcal_parse_get_line(line_buff, handle) != 0)
    {
        srv_vcal_parse_remove_ws(
                line_buff, 
                (CHAR*)SRV_VCAL_SEP_STR, 
                SRV_VCAL_REMOVE_BOTH_WS);
        if (srv_vcal_parse_get_field(line_buff) == SRV_VCAL_VERSION)
        {
            break;    
        }
    }
    
SRV_VCAL_ERROR_CLEAN:
    MMI_VCALSRV_TRACE1(MMI_VCALSRV_PARSE_BEGIN, result);     
    OslMfree(line_buff);
    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse
 * DESCRIPTION
 *  To begin the vcalendar parsing and return the parser handle.
 * PARAMETERS
 *  file_path :   [IN]The path to build to. Contains the file path and file name.
 *  object :      [OUT] The value is allocated by vcalendr service.
 *  vcal_type :   [OUT] Returen the object type.
 *  flag_finish : [IN] MMI_TRUE means finish to parse.
 *                     MMI_FALSE means still having other objects in the vcalendar file.
 * RETURNS
 *  Error cause
 *****************************************************************************/
S32 srv_vcal_parse(void *handle, void **object, srv_vcal_type_enum *vcal_type, U8 *flag_finish)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_parse_struct *parse_handle = (srv_vcal_parse_struct*)handle;
    S32 result = SRV_VCAL_RESULT_SUCCESS, parse_len;
    CHAR *line_buff;
    U8 field_type;
    srv_tdl_event_struct *pevent;
    srv_tdl_task_struct *ptask;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    line_buff = OslMalloc(SRV_VCAL_PARSE_BUFF_LEN);
    if (parse_handle->fh <= 0)
    {
        result = SRV_VCAL_RESULT_FS_ERROR;
        goto SRV_VCAL_ERROR_CLEAN;
    }           

    if (parse_handle->ref_count > 0)
    {
        result = SRV_VCAL_RESULT_BUFF_ERROR;
        goto SRV_VCAL_ERROR_CLEAN;
    }
    
    /* VEVENT or VTODO(mandatory) */
    while (srv_vcal_parse_get_line(line_buff, parse_handle) != 0)
    {
        srv_vcal_parse_remove_ws(
                line_buff, 
                (CHAR*)SRV_VCAL_SEP_STR, 
                SRV_VCAL_REMOVE_BOTH_WS);
        field_type = srv_vcal_parse_get_field(line_buff);
        
        if (field_type == SRV_VCAL_VEVENT_BEGIN)
        {
            *vcal_type = SRV_VCAL_VEVENT;
            break;
        }
        else if (field_type == SRV_VCAL_VTODO_BEGIN)
        {
            *vcal_type = SRV_VCAL_VTODO;
            break;
        }
        else
        {
            *vcal_type = SRV_VCAL_VTYPE_END_OF_ENUM;
        }
    }

    /* Parse vEvent or vTodo object. */
    if (SRV_VCAL_VEVENT == *vcal_type)
    {
        pevent = (srv_tdl_event_struct*)OslMalloc(sizeof(srv_tdl_event_struct));
        result = srv_vcal_event_parse(pevent, parse_handle);
        parse_handle->current_obj_number++;
        parse_handle->curr_parsed_object = pevent;
        parse_handle->curr_vcal_type = SRV_VCAL_VEVENT;
        parse_handle->ref_count++;
        *object = pevent;
    }
    else if (SRV_VCAL_VTODO == *vcal_type)
    {
        ptask = (srv_tdl_task_struct*)OslMalloc(sizeof(srv_tdl_task_struct));
        parse_handle->curr_parsed_object = ptask;
        result = srv_vcal_task_parse(ptask, parse_handle);
        parse_handle->current_obj_number++;
        parse_handle->curr_parsed_object = ptask;
        parse_handle->curr_vcal_type = SRV_VCAL_VTODO;
        parse_handle->ref_count++;
        *object = ptask;        
    }
    else
    {
        /* no find begin vevent or vtodo */
        result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
        goto SRV_VCAL_ERROR_CLEAN;
    }
    
    while ((parse_len = srv_vcal_parse_get_line(line_buff, parse_handle)) != 0)
    {
        srv_vcal_parse_remove_ws(
                line_buff, 
                (CHAR*)SRV_VCAL_SEP_STR, 
                SRV_VCAL_REMOVE_BOTH_WS);
        field_type = srv_vcal_parse_get_field(line_buff);
        if (SRV_VCAL_END == field_type)
        {
            *flag_finish = MMI_TRUE;
        }
        else
        {
            *flag_finish = MMI_FALSE;
        }
        FS_Seek(parse_handle->fh, 0 - parse_len - strlen(SRV_VCAL_CRLF_STR), SEEK_CUR);
        break;
    }
    
SRV_VCAL_ERROR_CLEAN:
    /* Trace: result, vcal_type, result, current_obj_number, flag_finish */
    
    MMI_VCALSRV_TRACE3(
            MMI_VCALSRV_PARSE_LEAVE, 
            parse_handle->curr_vcal_type,  
            *flag_finish,
            result); 
    
    OslMfree(line_buff);
    return result;
}


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
S32 srv_vcal_parse_free_object(void *handle, void *object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_parse_struct *parse_handle = (srv_vcal_parse_struct*)handle;
    S32 result = SRV_VCAL_RESULT_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (parse_handle->curr_parsed_object)
    {
        OslMfree(parse_handle->curr_parsed_object);
        parse_handle->curr_parsed_object = NULL;
    }
    else
    {
        result = SRV_VCAL_RESULT_UNKNOW_ERROR;
    }
    
    if (parse_handle->ref_count > 0)
    {
        parse_handle->ref_count--;
    }
    else
    {
        result = SRV_VCAL_RESULT_UNKNOW_ERROR;
    }

    MMI_VCALSRV_TRACE1(MMI_VCALSRV_PARSE_FREE_OBJ, result);     
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_get_object_number
 * DESCRIPTION
 *  To get the total number of current parsed objects.
 * PARAMETERS
 *  file_path : [IN]The path to build to. Contains the file path and file name.
 *  number : [OUT] The number builded.
 * RETURNS
 *  Error cause
 *****************************************************************************/
S32 srv_vcal_parse_get_object_number(void *handle, U32 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_parse_struct *parse_handle = (srv_vcal_parse_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_VCALSRV_TRACE1(MMI_VCALSRV_PARSE_GET_NUMBER, parse_handle->current_obj_number); 
    return parse_handle->current_obj_number;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_get_version
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
S32 srv_vcal_parse_get_version(void *handle, U32 *val_version)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_parse_struct *parse_handle = (srv_vcal_parse_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_VCALSRV_TRACE1(MMI_VCALSRV_PARSE_GET_VERSION, parse_handle->vcal_version); 
    return parse_handle->vcal_version;
}


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
S32 srv_vcal_parse_end(void *handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_parse_struct *parse_handle = (srv_vcal_parse_struct*)handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_Close(parse_handle->fh);
    OslMfree(parse_handle);
    return SRV_VCAL_RESULT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_utility_get_vtype
 * DESCRIPTION
 *  Generate a task to a vCalendar object.
 * PARAMETERS
 *  ptask : [IN]Task to be convert.
 *  file_path_name : [IN]File path to store the vCalendar object.
 * RETURNS
 *  Error cause
 *****************************************************************************/
S32 srv_vcal_utility_get_vtype(const U16* file_path, U16 *vtype)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *in_buff;
    U8 filed_type;
    U8 result = SRV_VCAL_TOTAL_FILEDS;
    srv_vcal_parse_struct *parse_handle;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parse_handle = (srv_vcal_parse_struct*)OslMalloc(sizeof(srv_vcal_parse_struct));
    in_buff = OslMalloc(SRV_VCAL_PARSE_BUFF_LEN);
    memset(parse_handle, 0, sizeof(srv_vcal_parse_struct));
    parse_handle->fh = FS_Open((U16*)file_path, FS_READ_ONLY);
    if (parse_handle->fh <= 0)
    {
        goto SRV_VCAL_ERROR_CLEAN;
    }
    
    /* VEVENT or VTODO */
    while (srv_vcal_parse_get_line(in_buff, parse_handle) != 0)
    {
        srv_vcal_parse_remove_ws(in_buff, (CHAR*)SRV_VCAL_SEP_STR, SRV_VCAL_REMOVE_BOTH_WS);
        filed_type = srv_vcal_parse_get_field(in_buff);
        if (filed_type == SRV_VCAL_VEVENT_BEGIN)
        {
            result = SRV_VCAL_VEVENT;
            *vtype = SRV_VCAL_VEVENT;
            goto SRV_VCAL_ERROR_CLEAN;
        }
        else if (filed_type == SRV_VCAL_VTODO_BEGIN)
        {
            result = SRV_VCAL_VTODO;
            *vtype = SRV_VCAL_VTODO;
            goto SRV_VCAL_ERROR_CLEAN;
        }
    }

SRV_VCAL_ERROR_CLEAN:
    FS_Close(parse_handle->fh);    
    OslMfree(parse_handle);
    OslMfree(in_buff);
    
    MMI_VCALSRV_TRACE1(MMI_VCALSRV_GET_VTYPE, result); 
    return result;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_task_build
 * DESCRIPTION
 *  Generate a task to a vCalendar object.
 * PARAMETERS
 *  ptask : [IN]Task to be convert.
 *  file_path_name : [IN]File path to store the vCalendar object.
 * RETURNS
 *  Error cause
 *****************************************************************************/
static S32 srv_vcal_task_build(
                            const srv_tdl_task_struct *ptask, 
                            FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    S32 write_byte;
    CHAR str_date_time[SRV_VCAL_MAX_DT_LEN];
    CHAR *vcal_build_buff = NULL;
    S32 len;
    U8 priority = 0;
    CHAR* curr_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fh <= 0)
    {
        result = fh;
        goto MMI_VCAL_ERROR_CLEAN;
    }
    
    vcal_build_buff = (CHAR *)OslMalloc(SRV_VCAL_BUILD_BUFF_LEN);

    /* BEGIN:VTODO */
    curr_p = srv_vcal_build_strcpy(vcal_build_buff, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_VTODO_BEGIN]);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);
    srv_vcal_build_time(str_date_time, SRV_VCAL_MAX_DT_LEN, ptask->due_time);
	
    /* DUE */
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_DUE]);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);
    curr_p = srv_vcal_build_strcpy(curr_p, str_date_time);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);

    /* DALARM */
    /* AALARM */
    if (ptask->alarm.first_launch.nYear != 0)
    {
        srv_vcal_build_time(str_date_time, SRV_VCAL_MAX_DT_LEN, ptask->alarm.first_launch);
        
        curr_p = srv_vcal_build_strcpy(curr_p, g_srv_vcal_fileds[SRV_VCAL_DALARM]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, str_date_time);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);

        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_AALARM]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, str_date_time);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);
    }
    
    /* SUMMARY: */
    if (mmi_ucs2strlen((CHAR*)ptask->subject) != 0)
    {
        curr_p = srv_vcal_build_strcpy(curr_p, g_srv_vcal_fileds[SRV_VCAL_SUMMARY]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_PARA_SEP_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_ENCODING]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_EQUAL_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_encoding[2]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_PARA_SEP_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_CHARSET]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_EQUAL_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CHARSET_UTF8);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);

        len = strlen(vcal_build_buff);
        result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);
        srv_vcal_build_string((CHAR*)vcal_build_buff, SRV_VCAL_BUILD_BUFF_LEN, (CHAR*)ptask->subject, MAX_TODO_LIST_NOTE);
        len = strlen(vcal_build_buff);
        result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);
        curr_p = srv_vcal_build_strcpy(vcal_build_buff, (CHAR*)SRV_VCAL_CRLF_STR);
    }

    /* DETAILS */
    if (mmi_ucs2strlen((CHAR*)ptask->details) != 0)
    {
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_DESCRIPTION]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_PARA_SEP_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_ENCODING]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_EQUAL_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_encoding[2]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_PARA_SEP_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_CHARSET]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_EQUAL_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CHARSET_UTF8);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);

        len = strlen(vcal_build_buff);
        result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);
        srv_vcal_build_string(
                    (CHAR*)vcal_build_buff, 
                    SRV_VCAL_BUILD_BUFF_LEN, 
                    (CHAR*)ptask->details, 
                    MAX_TDL_DETAILS_SIZE * ENCODING_LENGTH);
                    
        len = strlen(vcal_build_buff);
        result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);
        curr_p = srv_vcal_build_strcpy(vcal_build_buff, (CHAR*)SRV_VCAL_CRLF_STR);
    }

    /* RRULE */
    if (ptask->repeat.rule != SRV_VCAL_RULE_ONCE && ptask->repeat.rule != SRV_VCAL_RULE_TITHI)  
    {
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_RRULE]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);        
        srv_vcal_build_repeat(str_date_time, ptask->repeat, ptask->due_time);
        curr_p = srv_vcal_build_strcpy(curr_p, str_date_time);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);
    }

#ifdef __MMI_INDICAL__
    if (ptask->repeat.rule == SRV_VCAL_RULE_TITHI)
    {
        mmi_indical_set_saving_tithi_reminder(MMI_TRUE);
    }
#endif
    
    /* Status */
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_STATUS]);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);  
    
    if (1 == ptask->status)
    {
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)VCLNDR_STATUS_COMPLETED);    
    }
    else
    {
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)VCLNDR_STATUS_DEFAULT);    
    }
               
    /* Completed time */
    if (ptask->status == SRV_VCAL_STATUS_DONE)
    {
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_COMPLETED]);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);  
        srv_vcal_build_time(str_date_time, SRV_VCAL_MAX_DT_LEN, ptask->complete_time);
        curr_p = srv_vcal_build_strcpy(curr_p, str_date_time);    
    }
                
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);    

    /* Priority */
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_PRIORITY]);    
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);    
    priority = srv_vcal_build_priority(ptask->priority);
    sprintf(str_date_time, "%d\0", priority);    
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*) str_date_time);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);    

    /* END:VTODO */
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_VTODO_END]);    
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);    
            
    len = strlen(vcal_build_buff);
    MMI_ASSERT(len <= SRV_VCAL_BUILD_BUFF_LEN);
    result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);
            
MMI_VCAL_ERROR_CLEAN:
    if (vcal_build_buff)
    {
        OslMfree(vcal_build_buff);
        vcal_build_buff = NULL;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_event_build
 * DESCRIPTION
 *  Generate an event to a vCalendar object.
 * PARAMETERS
 *  pevent : [IN]Event to be convert.
 *  file_path_name : [IN]File path to store the vCalendar object.
 * RETURNS
 *  Error cause
 *****************************************************************************/
static S32 srv_vcal_event_build(const srv_tdl_event_struct *pevent, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_VCAL_RESULT_SUCCESS;
    S32 write_byte;
    CHAR str_date_time[SRV_VCAL_MAX_DT_LEN];
    CHAR *vcal_build_buff = NULL;
    S32 len;
    CHAR* curr_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (fh <= 0)
    {
        result = fh;
        goto MMI_VCAL_ERROR_CLEAN;
    }

    vcal_build_buff = (CHAR *)OslMalloc(SRV_VCAL_BUILD_BUFF_LEN);
            
    /* BEGIN:VEVENT */
    curr_p = srv_vcal_build_strcpy(vcal_build_buff, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_VEVENT_BEGIN]);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);
    
    srv_vcal_build_time(str_date_time, SRV_VCAL_MAX_DT_LEN, pevent->start_time);

    /* DTSTART: */
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_DTSTART]);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);    
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)str_date_time);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);
    
    srv_vcal_build_time(str_date_time, SRV_VCAL_MAX_DT_LEN, pevent->end_time);
    
    /* DTEND */
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_DTEND]);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)str_date_time);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);
   
    /* DALARM */
    /* AALARM */
    if (pevent->alarm.first_launch.nYear != 0)
    {
        srv_vcal_build_time(str_date_time, SRV_VCAL_MAX_DT_LEN, pevent->alarm.first_launch);

        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_DALARM]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)str_date_time);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_AALARM]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)str_date_time);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);
    }
    
    /* SUMMARY: */
    if (mmi_ucs2strlen((CHAR*)pevent->subject) != 0)
    {  
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_SUMMARY]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_PARA_SEP_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_ENCODING]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_EQUAL_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_encoding[2]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_PARA_SEP_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_CHARSET]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_EQUAL_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CHARSET_UTF8);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);

        len = strlen(vcal_build_buff);
        result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);
        srv_vcal_build_string(
                        (CHAR*)vcal_build_buff, 
                        SRV_VCAL_BUILD_BUFF_LEN, 
                        (CHAR*)pevent->subject,
                        MAX_TODO_LIST_NOTE);

        len = strlen(vcal_build_buff);
        result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);
        curr_p = srv_vcal_build_strcpy(vcal_build_buff, (CHAR*)SRV_VCAL_CRLF_STR);
    }

    /* DETAILS */
    if (mmi_ucs2strlen((CHAR*)pevent->details) != 0)
    {
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_DESCRIPTION]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_PARA_SEP_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_ENCODING]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_EQUAL_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_encoding[2]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_PARA_SEP_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_CHARSET]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_EQUAL_STR);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CHARSET_UTF8);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);    

        len = strlen(vcal_build_buff);
        result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);
        srv_vcal_build_string(
                    (CHAR*)vcal_build_buff, 
                    SRV_VCAL_BUILD_BUFF_LEN, 
                    (CHAR*)pevent->details,
                    MAX_TDL_DETAILS_SIZE * ENCODING_LENGTH);
                    
        len = strlen(vcal_build_buff);
        result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);
        curr_p = srv_vcal_build_strcpy(vcal_build_buff, (CHAR*)SRV_VCAL_CRLF_STR);
    }
    
    /* RRULE */
    if (pevent->repeat.rule != SRV_VCAL_RULE_ONCE && pevent->repeat.rule != SRV_VCAL_RULE_TITHI)
    {
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_RRULE]);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);        
        memset(str_date_time, 0, SRV_VCAL_MAX_DT_LEN);
        srv_vcal_build_repeat(str_date_time, pevent->repeat, pevent->start_time);
        curr_p = srv_vcal_build_strcpy(curr_p, str_date_time);
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);
    }
#ifdef __MMI_INDICAL__
    if (pevent->repeat.rule == SRV_VCAL_RULE_TITHI)
    {
        mmi_indical_set_saving_tithi_reminder(MMI_TRUE);
    }
#endif
    
    /* Category */
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_CATEGORY]);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);
    memset(str_date_time, 0, SRV_VCAL_MAX_DT_LEN);
    srv_vcal_build_category(str_date_time, pevent->category);
    curr_p = srv_vcal_build_strcpy(curr_p, str_date_time);
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);    

    /* Location */
    if (mmi_ucs2strlen((CHAR*)pevent->location) != 0)
    {
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_LOCATION]);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_PARA_SEP_STR);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_ENCODING]);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_EQUAL_STR);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_encoding[2]);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_PARA_SEP_STR);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_CHARSET]);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_EQUAL_STR);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CHARSET_UTF8);    
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_SEP_STR);  

        len = strlen(vcal_build_buff);
        MMI_ASSERT(len <= SRV_VCAL_BUILD_BUFF_LEN);  
        result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);
        srv_vcal_build_string(
                    (CHAR*)vcal_build_buff, 
                    SRV_VCAL_BUILD_BUFF_LEN, 
                    (CHAR*)pevent->location,
                    MAX_TDL_LOCATION_SIZE * ENCODING_LENGTH);
                    
        len = strlen(vcal_build_buff);
        MMI_ASSERT(len <= SRV_VCAL_BUILD_BUFF_LEN);  
        result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);
        curr_p = srv_vcal_build_strcpy(vcal_build_buff, (CHAR*)SRV_VCAL_CRLF_STR);    
    }

    /* END:VEVENT */
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_fileds[SRV_VCAL_VEVENT_END]);    
    curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CRLF_STR);    

    len = strlen(vcal_build_buff);
    MMI_ASSERT(len <= SRV_VCAL_BUILD_BUFF_LEN);
    result = FS_Write(fh, vcal_build_buff, len, (UINT *)&write_byte);

MMI_VCAL_ERROR_CLEAN:
    if (vcal_build_buff)
    {
        OslMfree(vcal_build_buff);
        vcal_build_buff = NULL;
    }
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_vclndr_write_string
* DESCRIPTION
*  Compute the filed name of a given string.s
* PARAMETERS
*  String      [IN]        String to be checked
* RETURNS
*  Type of the filed
*****************************************************************************/
static void srv_vcal_build_string(CHAR *dest_buff, U16 dest_size, const CHAR *src_buff, U16 src_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *curr_p = dest_buff;
    CHAR *temp_buff = NULL;
    CHAR *src_temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_buff = (CHAR *)OslMalloc(dest_size);
    src_temp = (CHAR *)OslMalloc(src_size);
    memcpy(src_temp, src_buff, src_size);
    
    mmi_chset_convert(
                    MMI_CHSET_UCS2, 
                    MMI_CHSET_UTF8, 
                    src_temp, 
                    temp_buff, 
                    dest_size);
    applib_qprint_encode_ext(
                        temp_buff, 
                        strlen(temp_buff), 
                        curr_p, 
                        dest_size - 1, 
                        MMI_TRUE);
    if (temp_buff)
    {
        OslMfree(temp_buff);
        temp_buff = NULL;
    }
    if (src_temp)
    {
        OslMfree(src_temp);
        src_temp = NULL;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_vclndr_write_category
* DESCRIPTION
*  Compute the filed name of a given string.s
* PARAMETERS
*  String      [IN]        String to be checked
* RETURNS
*  Type of the filed
*****************************************************************************/
static void srv_vcal_build_category(CHAR *out_buff, const U8 category)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *curr_p = out_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (category)
    {
        case SRV_VCAL_CATEGORY_TYPE_REMINDER:
            curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CATEGORY_REMINDER);
            break;
            
        case SRV_VCAL_CATEGORY_TYPE_MEETING:
            curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CATEGORY_MEETING);
            break;
            
        case SRV_VCAL_CATEGORY_TYPE_COURSE:
            curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CATEGORY_COURSE);
            break;
            
        case SRV_VCAL_CATEGORY_TYPE_DATE:
            curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CATEGORY_DATE);
            break;
            
        case SRV_VCAL_CATEGORY_TYPE_CALL:
            curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CATEGORY_CALL);
            break;
            
        case SRV_VCAL_CATEGORY_TYPE_ANNIVERSARY:
            curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CATEGORY_ANNIVERSARY);
            break;

        case SRV_VCAL_CATEGORY_TYPE_BIRTHDAY:
            curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CATEGORY_BIRTHDAY);
            break;
            
        default:
            curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_CATEGORY_REMINDER);        
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_vclndr_write_repeat
* DESCRIPTION
*  Compute the filed name of a given string.s
* PARAMETERS
*  String      [IN]        String to be checked
* RETURNS
*  Type of the filed
*****************************************************************************/
static void srv_vcal_build_repeat(CHAR *out_buff, const srv_tdl_repeat_struct repeat, const MYTIME start_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *curr_p = out_buff;
    CHAR str_date_time[SRV_VCAL_MAX_DT_LEN];
                            
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (repeat.rule != SRV_VCAL_RULE_ONCE)
    {
        switch (repeat.rule)
        {
            case SRV_VCAL_RULE_DAILY:
            {
                curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_recurr[SRV_VCAL_DAILY]);        
                
                break;
            }
            case SRV_VCAL_RULE_DAYS:
            {
                S32 i;
                curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_recurr[SRV_VCAL_WEEKLY]);        

                for (i = 0; i < SRV_VCAL_NUM_OF_DAYS; i++)
                {
                    if (repeat.dows & (0x1 << i))
                    {
                        sprintf(str_date_time, " %s", g_srv_vcal_days[i]);
                        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)str_date_time); 
                    }
                }
                break;
            }
            case SRV_VCAL_RULE_WEEKLY:
            {
                curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_recurr[SRV_VCAL_WEEKLY]);
                break;
            }
            case SRV_VCAL_RULE_MONTHLY:
            {
                curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_recurr[SRV_VCAL_MONTHLY]);
                sprintf(str_date_time, " %d", start_time.nDay);
                curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)str_date_time);

                break;
            }
            case SRV_VCAL_RULE_YEARLY:
            {
                curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)g_srv_vcal_recurr[SRV_VCAL_YEARLY]);
                break;
            }
            default:
                break;
        }
        /* #0 */
        curr_p = srv_vcal_build_strcpy(curr_p, (CHAR*)SRV_VCAL_R_FOREVER_STR);
    }
}
 
 
/*****************************************************************************
* FUNCTION
*  srv_vcal_build_time
* DESCRIPTION
*  Compute the filed name of a given string.s
* PARAMETERS
*  String      [IN]        String to be checked
* RETURNS
*  Type of the filed
*****************************************************************************/
static void srv_vcal_build_time(CHAR *out_buff, const U16 buff_size, const MYTIME date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct utc_time;
    applib_time_struct temp_time;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buff_size < SRV_VCLADR_MAX_DATE_TIME_LEN)
    {
        return;
    }
   
    memcpy(&temp_time, &date_time, sizeof(MYTIME));   
    applib_dt_rtc_to_utc_with_default_tz(&temp_time, &utc_time);

    sprintf(
        out_buff,
        "%d%02d%02d%c%02d%02d%02dZ",
        utc_time.nYear,
        utc_time.nMonth,
        utc_time.nDay,
        SRV_VCAL_DT_SEP_CHAR,
        utc_time.nHour,
        utc_time.nMin,
        utc_time.nSec);
}
 
 
/*****************************************************************************
* FUNCTION
*  srv_vcal_build_priority
* DESCRIPTION
*  Parse the priority from spec to tdl
* PARAMETERS
*  priority_tdl      [IN]        priority in tdl
* RETURNS
*  The priority in vclndr spec
*****************************************************************************/
static U8 srv_vcal_build_priority(U8 priority_tdl)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     switch (priority_tdl)
     {
         /*
          * SRV_VCAL_PRIORITY_LOW       : 9
          * SRV_VCAL_PRIORITY_MEDIUM    : 0
          * SRV_VCAL_PRIORITY_HIGH      : 1 
          */
         case SRV_VCAL_PRIORITY_LOW:
             return 9;
         case SRV_VCAL_PRIORITY_MEDIUM:
             return 0;
         case SRV_VCAL_PRIORITY_HIGH:
             return 1;
         default:
             return 0;
     }
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_build_strcpy
 * DESCRIPTION
 *  Copy one string over another
 * PARAMETERS
 *  CHAR* dst - string over which "src" is to be copied
 *  const CHAR* src - string to be copied over "dst"        
 * RETURNS
 *  The address of result in dst
 *****************************************************************************/
static CHAR* srv_vcal_build_strcpy(CHAR* dst, const CHAR* src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* curr_p = dst;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while((kal_bool)(*curr_p++ = *src++))
                ;               /* Copy src over dst */

        return(--curr_p);
}



/*****************************************************************************
 * FUNCTION
 *  srv_vcal_task_parse
 * DESCRIPTION
 *  Parse a vCalendar file to a task/event.
 *  Write the event/task to global context and tell it's event or task.
 * PARAMETERS
 *  pevent : [OUT] Output the event.
 *  fh : [IN] File handler.
 * RETURNS
 *  Error cause
 *****************************************************************************/
static S32 srv_vcal_task_parse(srv_tdl_task_struct *ptask, srv_vcal_parse_struct *parse_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_VCAL_RESULT_SUCCESS;
    U16 error_code;
    srv_tdl_task_struct *task_temp = NULL;
    CHAR *line_buff = NULL;      /* buffer to store input */
    U8 field_type;
    CHAR *str_value;             /* pointer to value of filed */
    MYTIME due_time;
    CHAR *details_p = NULL;      /* buffer to store input */
    CHAR *summary_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(ptask);
    if (parse_handle->fh <= 0)
    {
        result = parse_handle->fh;
        goto MMI_VCAL_ERROR_CLEAN;
    }
        
    details_p = OslMalloc((MAX_TDL_DETAILS_LEN + 1) * ENCODING_LENGTH);
    summary_p = OslMalloc(MAX_TODO_NOTE_LEN * ENCODING_LENGTH);
    line_buff = OslMalloc(SRV_VCAL_BUILD_BUFF_LEN);
    task_temp = OslMalloc(sizeof(srv_tdl_task_struct));
    memset(task_temp, 0, sizeof(srv_tdl_task_struct));
    task_temp->present = MMI_TRUE;
    task_temp->priority = SRV_VCAL_PRIORITY_MEDIUM;
    
    while (srv_vcal_parse_get_line(line_buff, parse_handle) != 0)
    {
        srv_vcal_parse_remove_ws(
                            line_buff, 
                            (CHAR*)SRV_VCAL_SEP_STR, 
                            SRV_VCAL_REMOVE_PRE_WS);
    
        field_type = srv_vcal_parse_get_field(line_buff);

        /* the vevent or vtodo can not be nested within another ve or vt entity */
        if (SRV_VCAL_VEVENT_BEGIN == field_type || SRV_VCAL_VTODO_BEGIN == field_type)
        {
            result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
            goto MMI_VCAL_ERROR_CLEAN;
        }

        /* To keep the white space in the notes */
        if (field_type != SRV_VCAL_SUMMARY && 
            field_type != SRV_VCAL_DESCRIPTION && 
            field_type != SRV_VCAL_LOCATION)
        {
            srv_vcal_parse_remove_ws(
                        line_buff, 
                        (CHAR*)SRV_VCAL_SEP_STR, 
                        SRV_VCAL_REMOVE_POST_WS);
        }

        str_value = srv_vcal_parse_get_value(line_buff);

        if (!str_value)
        {
            continue;
        }

        switch (field_type)
        {
            case SRV_VCAL_DUE:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_DUE);
                
                error_code = srv_vcal_parse_time(str_value, &due_time);
                if (error_code != SRV_VCAL_RESULT_SUCCESS ||
                    !applib_dt_check_valid_by_app(SRV_VCAL_MIN_START_YEAR_EXT, SRV_VCAL_MAX_END_YEAR, (applib_time_struct*)&due_time))
                {
                    result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
                    goto MMI_VCAL_ERROR_CLEAN;
                }
                else
                {
                    memcpy(&task_temp->due_time, &due_time, sizeof(MYTIME));
                }
                break;

            case SRV_VCAL_SUMMARY:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_SUMMARY);
                error_code = srv_vcal_parse_string(
                                            line_buff, 
                                            str_value, 
                                            summary_p, 
                                            MAX_TODO_NOTE_LEN * ENCODING_LENGTH);
                
                if (error_code != SRV_VCAL_RESULT_SUCCESS)
                {
                    result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
                    goto MMI_VCAL_ERROR_CLEAN;
                }
                
                mmi_ucs2ncpy((CHAR*)task_temp->subject, summary_p, MAX_TODO_NOTE_LEN - 1);
                break;
                
            case SRV_VCAL_DESCRIPTION:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_DESCRIPTION);
                error_code = srv_vcal_parse_string(
                                            line_buff, 
                                            str_value, 
                                            details_p, 
                                            (MAX_TDL_DETAILS_LEN + 1) * ENCODING_LENGTH);
                if (error_code != SRV_VCAL_RESULT_SUCCESS)
                {
                    result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
                    goto MMI_VCAL_ERROR_CLEAN;
                }
                mmi_ucs2ncpy((CHAR*)task_temp->details, details_p, MAX_TDL_DETAILS_LEN);
                break;

            case SRV_VCAL_RRULE:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_RRULE);
                error_code = srv_vcal_parse_repeat(str_value, &task_temp->repeat);
                if (error_code != SRV_VCAL_RESULT_SUCCESS)
                {
                    result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
                    goto MMI_VCAL_ERROR_CLEAN;
                }
                break;

            case SRV_VCAL_AALARM:
            case SRV_VCAL_DALARM:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_AALARM);
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_DALARM);
                
                if (strncmp((CHAR*)str_value, (CHAR*)SRV_VCAL_CRLF_STR, strlen(SRV_VCAL_CRLF_STR)) != 0)
                {
                    srv_vcal_parse_time(str_value, &task_temp->alarm.first_launch);
                }
                break;

            case SRV_VCAL_PRIORITY:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_PRIORITY);
                task_temp->priority = srv_vcal_parse_priority((U8)atoi(str_value));
                break;
                
            case SRV_VCAL_STATUS:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_STATUS);
                if (0 == strncmp(str_value, (CHAR*)VCLNDR_STATUS_COMPLETED, strlen(VCLNDR_STATUS_COMPLETED)))
                {
                    task_temp->status = 1;
                }
                else
                {
                    task_temp->status = 0;
                }
                break;
                
            case SRV_VCAL_COMPLETED:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_COMPLETED);
                error_code = srv_vcal_parse_time(str_value, &task_temp->complete_time);
                if (error_code != SRV_VCAL_RESULT_SUCCESS ||
                    !applib_dt_check_valid_by_app(SRV_VCAL_MIN_START_YEAR_EXT, SRV_VCAL_MAX_END_YEAR, (applib_time_struct*)&task_temp->complete_time))
                {
                    result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
                    goto MMI_VCAL_ERROR_CLEAN;
                }
                break;

            case SRV_VCAL_VTODO_END:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_VTODO_END);
                goto SRV_VCAL_PARSE_END;

            default:
                break;        
        }
    }

SRV_VCAL_PARSE_END:

    if (!srv_vcal_check_filed_mask(parse_handle->parsed_field, SRV_VCAL_DUE))
    {
        result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
        goto MMI_VCAL_ERROR_CLEAN;
    }

    if (!srv_vcal_check_filed_mask(parse_handle->parsed_field, SRV_VCAL_SUMMARY))
    {
        result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
        goto MMI_VCAL_ERROR_CLEAN;
    }

    task_temp->present = MMI_TRUE;
    memcpy(ptask, task_temp, sizeof(srv_tdl_task_struct));

MMI_VCAL_ERROR_CLEAN:
    if (details_p)
    {
        OslMfree(details_p);
        details_p = NULL;
    }
    
    if (summary_p)
    {
        OslMfree(summary_p);
        summary_p = NULL;
    }
    
    if (line_buff)
    {
        OslMfree(line_buff);
        line_buff = NULL;
    }

    if (task_temp)
    {
        OslMfree(task_temp);
        task_temp = NULL;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_event_parse
 * DESCRIPTION
 *  Parse a vCalendar file to a task/event.
 *  Write the event/task to global context and tell it's event or task.
 * PARAMETERS
 *  pevent : [OUT] Output the event.
 *  fh : [IN] File handler.
 * RETURNS
 *  Error cause
 *****************************************************************************/
static S32 srv_vcal_event_parse(srv_tdl_event_struct *pevent, srv_vcal_parse_struct *parse_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_VCAL_RESULT_SUCCESS;
    U16 error_code;
    srv_tdl_event_struct *event_temp = NULL;
    CHAR *line_buff = NULL;      /* buffer to store input */
    U8 field_type;
    CHAR *str_value;             /* pointer to value of filed */
    CHAR *details_p = NULL;      /* buffer to store input */
    CHAR *summary_p = NULL;
    CHAR *location_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(pevent);
    if (parse_handle->fh <= 0)
    {
        result = parse_handle->fh;
        goto MMI_VCAL_ERROR_CLEAN;
    }

    details_p = OslMalloc((MAX_TDL_DETAILS_LEN + 1) * ENCODING_LENGTH);
    summary_p = OslMalloc(MAX_TODO_NOTE_LEN * ENCODING_LENGTH);    
    location_p = OslMalloc(MAX_TDL_LOCATION_SIZE * ENCODING_LENGTH);
    line_buff = OslMalloc(SRV_VCAL_BUILD_BUFF_LEN);
    event_temp = OslMalloc(sizeof(srv_tdl_event_struct));
    memset(event_temp, 0, sizeof(srv_tdl_event_struct));
    event_temp->present = MMI_TRUE;
    event_temp->extend = 0xFFFF;
    
    while (srv_vcal_parse_get_line(line_buff, parse_handle) != 0)
    {
        srv_vcal_parse_remove_ws(
                    line_buff, 
                    (CHAR*)SRV_VCAL_SEP_STR, 
                    SRV_VCAL_REMOVE_PRE_WS);
                    
        field_type = srv_vcal_parse_get_field(line_buff);

        /* the vevent or vtodo can not be nested within another ve or vt entity */
        if (SRV_VCAL_VEVENT_BEGIN == field_type || SRV_VCAL_VTODO_BEGIN == field_type)
        {
            result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
            goto MMI_VCAL_ERROR_CLEAN;
        }

        /* To keep the white space in the notes */
        if (field_type != SRV_VCAL_SUMMARY && 
            field_type != SRV_VCAL_DESCRIPTION && 
            field_type != SRV_VCAL_LOCATION)
        {
            srv_vcal_parse_remove_ws(
                    line_buff, 
                    (CHAR*)SRV_VCAL_SEP_STR, 
                    SRV_VCAL_REMOVE_POST_WS);
        }
        str_value = srv_vcal_parse_get_value(line_buff);

        if (!str_value)
        {
            continue;
        }
        
        switch (field_type)
        {
            case SRV_VCAL_DTSTART:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_DTSTART);
                error_code = srv_vcal_parse_time(str_value, &event_temp->start_time);
                if (error_code != SRV_VCAL_RESULT_SUCCESS ||
                    !applib_dt_check_valid_by_app(SRV_VCAL_MIN_START_YEAR, SRV_VCAL_MAX_END_YEAR, (applib_time_struct*)&event_temp->start_time))
                {
                    result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
                    goto MMI_VCAL_ERROR_CLEAN;
                }
                break;
                
            case SRV_VCAL_DTEND:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_DTEND);
                error_code = srv_vcal_parse_time(str_value, &event_temp->end_time);
                if (error_code != SRV_VCAL_RESULT_SUCCESS ||
                    !applib_dt_check_valid_by_app(SRV_VCAL_MIN_START_YEAR, SRV_VCAL_MAX_END_YEAR, (applib_time_struct*)&event_temp->end_time))
                {
                    result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
                    goto MMI_VCAL_ERROR_CLEAN;
                }
                break;
                
            case SRV_VCAL_SUMMARY:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_SUMMARY);
                error_code = srv_vcal_parse_string(
                                            line_buff, 
                                            str_value, 
                                            summary_p, 
                                            MAX_TODO_NOTE_LEN * ENCODING_LENGTH);
                
                if (error_code != SRV_VCAL_RESULT_SUCCESS)
                {
                    result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
                    goto MMI_VCAL_ERROR_CLEAN;
                }
                
                mmi_ucs2ncpy((CHAR*)event_temp->subject, summary_p, MAX_TODO_NOTE_LEN - 1);
                break;
                
            case SRV_VCAL_DESCRIPTION:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_DESCRIPTION);
                error_code = srv_vcal_parse_string(
                                            line_buff, 
                                            str_value, 
                                            details_p, 
                                            (MAX_TDL_DETAILS_LEN + 1) * ENCODING_LENGTH);
                
                if (error_code != SRV_VCAL_RESULT_SUCCESS)
                {
                    result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
                    goto MMI_VCAL_ERROR_CLEAN;
                }
                
                mmi_ucs2ncpy((CHAR*)event_temp->details, details_p, MAX_TDL_DETAILS_LEN);
                break;
                
            case SRV_VCAL_LOCATION:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_LOCATION);
                error_code = srv_vcal_parse_string(
                                            line_buff, 
                                            str_value, 
                                            location_p, 
                                            MAX_TDL_LOCATION_SIZE * ENCODING_LENGTH);
                
                if (error_code != SRV_VCAL_RESULT_SUCCESS)
                {
                    result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
                    goto MMI_VCAL_ERROR_CLEAN;
                }
                
                mmi_ucs2ncpy((CHAR*)event_temp->location, location_p, MAX_TDL_LOCATION_LEN);
                break;
             
            case SRV_VCAL_RRULE:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_RRULE);
                error_code = srv_vcal_parse_repeat(str_value, &event_temp->repeat);
                if (error_code != SRV_VCAL_RESULT_SUCCESS)
                {
                    result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
                    goto MMI_VCAL_ERROR_CLEAN;
                }
                break;
                
            case SRV_VCAL_AALARM:
            case SRV_VCAL_DALARM:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_AALARM);
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_DALARM);
                if (strncmp((CHAR*)str_value, (CHAR*)SRV_VCAL_CRLF_STR, strlen(SRV_VCAL_CRLF_STR)) != 0)
                {
                    srv_vcal_parse_time(str_value, &event_temp->alarm.first_launch);
                }
                break;
                
            case SRV_VCAL_CATEGORY:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_CATEGORY);
                if (!srv_vcal_parse_strnicmp(str_value, SRV_VCAL_CATEGORY_MEETING, strlen(SRV_VCAL_CATEGORY_MEETING)))
                {
                    event_temp->category = SRV_VCAL_CATEGORY_TYPE_MEETING;
                }
                else if (!srv_vcal_parse_strnicmp(str_value, SRV_VCAL_CATEGORY_COURSE, strlen(SRV_VCAL_CATEGORY_COURSE)))
                {
                    event_temp->category = SRV_VCAL_CATEGORY_TYPE_COURSE;
                }
                else if (!srv_vcal_parse_strnicmp(str_value, SRV_VCAL_CATEGORY_DATE, strlen(SRV_VCAL_CATEGORY_DATE)))
                {
                    event_temp->category = SRV_VCAL_CATEGORY_TYPE_DATE;
                }
                else if (!srv_vcal_parse_strnicmp(str_value, SRV_VCAL_CATEGORY_CALL, strlen(SRV_VCAL_CATEGORY_CALL)))
                {
                    event_temp->category = SRV_VCAL_CATEGORY_TYPE_CALL;
                }
                else if (!srv_vcal_parse_strnicmp(str_value, SRV_VCAL_CATEGORY_ANNIVERSARY, strlen(SRV_VCAL_CATEGORY_ANNIVERSARY)))
                {
                    event_temp->category = SRV_VCAL_CATEGORY_TYPE_ANNIVERSARY;
            	}
                else if (!srv_vcal_parse_strnicmp(str_value, SRV_VCAL_CATEGORY_BIRTHDAY, strlen(SRV_VCAL_CATEGORY_BIRTHDAY)))
                {
                    event_temp->category = SRV_VCAL_CATEGORY_TYPE_BIRTHDAY;
                }
        		else 
                {
            	    event_temp->category = SRV_VCAL_CATEGORY_TYPE_REMINDER;
                }
                break; 
            case SRV_VCAL_VEVENT_END:
                srv_vcal_set_filed_mask(&(parse_handle->parsed_field), SRV_VCAL_VEVENT_END);
                goto SRV_VCAL_PARSE_END;

            default:
                break;
        }
    }

SRV_VCAL_PARSE_END:

    if (!srv_vcal_check_filed_mask(parse_handle->parsed_field, SRV_VCAL_DTSTART) ||
        !srv_vcal_check_filed_mask(parse_handle->parsed_field, SRV_VCAL_DTEND))
    {
        result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
        goto MMI_VCAL_ERROR_CLEAN;
    }

    if (!srv_vcal_check_filed_mask(parse_handle->parsed_field, SRV_VCAL_SUMMARY))
    {
        result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
        goto MMI_VCAL_ERROR_CLEAN;
    }

    if (CompareTime(event_temp->end_time, event_temp->start_time, NULL) < 0)
    {
        result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
        goto MMI_VCAL_ERROR_CLEAN;
    }
    
    if (event_temp->category != SRV_VCAL_CATEGORY_TYPE_BIRTHDAY)
    {
        if (!applib_dt_check_valid_by_app(SRV_VCAL_MIN_START_YEAR_EXT, SRV_VCAL_MAX_END_YEAR, (applib_time_struct*)&event_temp->start_time)
            || !applib_dt_check_valid_by_app(SRV_VCAL_MIN_START_YEAR_EXT, SRV_VCAL_MAX_END_YEAR, (applib_time_struct*)&event_temp->end_time))
        {
            result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
            goto MMI_VCAL_ERROR_CLEAN;
        }
    }
    else
    {
        if (!applib_dt_check_valid_by_app(SRV_VCAL_MIN_START_YEAR, SRV_VCAL_MAX_END_YEAR, (applib_time_struct*)&event_temp->start_time))
        {
            result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
            goto MMI_VCAL_ERROR_CLEAN;
        }
    }
    
    event_temp->present = MMI_TRUE;
    memcpy(pevent, event_temp, sizeof(srv_tdl_event_struct));
    
MMI_VCAL_ERROR_CLEAN:
    if (details_p)
    {
        OslMfree(details_p);
        details_p = NULL;
    }
    if (line_buff)
    {
        OslMfree(line_buff);
        line_buff = NULL;
    }
    if (summary_p)
    {
        OslMfree(summary_p);
        summary_p = NULL;
    }
    if (location_p)
    {
        OslMfree(location_p);
        location_p = NULL;
    }
    if (event_temp)
    {
        OslMfree(event_temp);
        event_temp = NULL;
    }
    return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_vclndr_uti_read_priority
* DESCRIPTION
*  Parse the priority from spec to tdl
* PARAMETERS
*  priority_value      [IN]        priority according to the vclndr spec
* RETURNS
*  The priority in TDL
*****************************************************************************/
static U8 srv_vcal_parse_priority(U8 priority_value)
{
     /*----------------------------------------------------------------*/
     /* Local Variables                                                */
     /*----------------------------------------------------------------*/
     
     /*----------------------------------------------------------------*/
     /* Code Body                                                      */
     /*----------------------------------------------------------------*/
     switch (priority_value)
     {
         /*
          * PRIORITY:0      -- default, medium priority
          * PRIORITY:1~3    -- highest priority
          * PRIORITY:7~9    -- lowest priority
          * PRIORITY:4~6    -- medium priority 
          */
         case 1:
         case 2:
         case 3:
             return SRV_VCAL_PRIORITY_HIGH;
         case 7:
         case 8:
         case 9:
             return SRV_VCAL_PRIORITY_LOW;
         default:
             return SRV_VCAL_PRIORITY_MEDIUM;
     }
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_repeat
 * DESCRIPTION
 *  Get time value from a date/time string
 * PARAMETERS
 *  str_value : [IN] Value buffer.
 *  repeat : [OUT] Repeat type.
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_vcal_parse_repeat(CHAR *str_value, srv_tdl_repeat_struct *repeat)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_vcal_recurr_struct recurr;
    CHAR *result_buff = OslMalloc(SRV_VCAL_PARSE_BUFF_LEN);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_qprint_decode(str_value, strlen(str_value), result_buff, SRV_VCAL_PARSE_BUFF_LEN);

    if (srv_vcal_parse_recurr(result_buff, &recurr))
    {
        repeat->rule = recurr.repeat;
        repeat->dows = recurr.days;
    }
    else
    {
        repeat->rule = SRV_VCAL_RULE_ONCE;
    }
    OslMfree(result_buff);
    return SRV_VCAL_RESULT_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_string
 * DESCRIPTION
 *  Get time value from a date/time string
 * PARAMETERS
 *  line_buff : [IN] Line buffer.
 *  str_value : [IN] Value buffer.
 *  out_string : [OUT] Parsing result.
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_vcal_parse_string(CHAR *line_p, CHAR *value_p, CHAR *out_buff, U16 buff_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_VCAL_RESULT_SUCCESS;
    U8 encoding;
    U8 charset1 = SRV_VCAL_CH_UTF8;
    mmi_chset_enum charset2 = MMI_CHSET_UTF8;
    CHAR *encode_buff = NULL;      /* buffer to store encoding type */
    CHAR *charset_buff = NULL;     /* buffer to store charset */
    CHAR *result_buff = NULL;      /* for UTF-8 case */

    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    encode_buff = OslMalloc(SRV_VCAL_MAX_PARAM_LEN);      /* buffer to store encoding type */
    charset_buff = OslMalloc(SRV_VCAL_MAX_PARAM_LEN);     /* buffer to store charset */
    result_buff = OslMalloc(SRV_VCAL_PARSE_BUFF_LEN);                      /* for UTF-8 case */
    memcpy(result_buff, value_p, SRV_VCAL_PARSE_BUFF_LEN);

    /* Encoding type */
    if (srv_vcal_parse_encoding_para(
                line_p, 
                (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_ENCODING], 
                encode_buff, 
                SRV_VCAL_MAX_PARAM_LEN))
    {
        encoding = srv_vcal_parse_encoding_type(encode_buff);
        if (encoding == SRV_VCAL_EN_QP)
        {
            applib_qprint_decode(value_p, strlen(value_p), result_buff, SRV_VCAL_PARSE_BUFF_LEN);
        }
        else
        {
            result = SRV_VCAL_RESULT_UNSUPPORT_FORMAT;
            goto MMI_CLNDR_ERROR_CLEAN;
        }
    }
    else
    {
        encoding = SRV_VCAL_EN_TOTAL;
    }

    /* Charset */
    if (srv_vcal_parse_encoding_para(
                line_p, 
                (CHAR*)g_srv_vcal_paras[SRV_VCAL_PARA_CHARSET], 
                charset_buff, 
                SRV_VCAL_MAX_PARAM_LEN))
    {
        charset1 = srv_vcal_parse_charset(charset_buff);
        if (charset1 == SRV_VCAL_CH_UTF8)
        {
            charset2 = MMI_CHSET_UTF8;
        }
    #ifdef __MMI_CHSET_UTF7__
        else if (charset1 == SRV_VCAL_CH_UTF7)
        {
            charset2 = MMI_CHSET_UTF7;
        }
    #endif
        else
        {
            //charset2 = (mmi_chset_enum)g_vcal_cntx.vcalendar_encoding;
        }
    }
    else
    {
//          charset2 = (mmi_chset_enum)g_vcal_cntx.vcalendar_encoding;
    }

    mmi_chset_convert(
            charset2,
            MMI_CHSET_UCS2,
            result_buff,
            out_buff,
            buff_size);

MMI_CLNDR_ERROR_CLEAN:
    if (encode_buff)
    {
        OslMfree(encode_buff);
        encode_buff = NULL;
    }
    
    if (charset_buff)
    {
        OslMfree(charset_buff);
        charset_buff = NULL;
    }
    
    if (result_buff)
    {
        OslMfree(result_buff);
        result_buff = NULL;
    }
        
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_time
 * DESCRIPTION
 *  Get time value from a date/time string
 * PARAMETERS
 *  strTime     [IN]        Date/time string in yyyymmddThhmmssZ format.
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_vcal_parse_time(CHAR *str_time, MYTIME *date_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result = SRV_VCAL_RESULT_SUCCESS;
    CHAR *str_cursor = str_time;
    CHAR str_buff[SRV_VCAL_MAX_DT_LEN];
    applib_time_struct temp_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(date_time, 0, sizeof(MYTIME));

    /* year */
	memset(str_buff, 0, SRV_VCAL_MAX_DT_LEN);	
    mmi_asc_n_to_ucs2(str_buff, str_cursor, 4);
    date_time->nYear = (U16)gui_atoi((U16*)str_buff);
    str_cursor += 4;

    /* month */
	memset(str_buff, 0, SRV_VCAL_MAX_DT_LEN);	
    mmi_asc_n_to_ucs2(str_buff, str_cursor, 2);
    date_time->nMonth = (U8)gui_atoi((U16*)str_buff);
    str_cursor += 2;

    /* day */
    //memset(str_buff, 0, SRV_VCAL_MAX_DT_LEN);
    mmi_asc_n_to_ucs2(str_buff, str_cursor, 2);
    date_time->nDay = (U8)gui_atoi((U16*)str_buff);
    str_cursor += 2;

    /* ignore 'T' */
    if (str_cursor[0] != SRV_VCAL_DT_SEP_CHAR)
    {
        /* Because DT format of vCalendar from HP phone may be YYYYMMDD */
        if (str_cursor[0] == 0)
		{        
            return result;    
        }
        memset(date_time, 0, sizeof(MYTIME));
        return result;
    }

    str_cursor++;

    /* hour */
    //memset(str_buff, 0, SRV_VCAL_MAX_DT_LEN);
    mmi_asc_n_to_ucs2(str_buff, str_cursor, 2);
    date_time->nHour = (U8)gui_atoi((U16*)str_buff);
    str_cursor += 2;

    /* minute */
    //memset(str_buff, 0, SRV_VCAL_MAX_DT_LEN);
    mmi_asc_n_to_ucs2(str_buff, str_cursor, 2);
    date_time->nMin = (U8)gui_atoi((U16*)str_buff);
    str_cursor += 2;

    /* second */
    //memset(str_buff, 0, SRV_VCAL_MAX_DT_LEN);
    mmi_asc_n_to_ucs2(str_buff, str_cursor, 2);
    date_time->nSec = (U8)gui_atoi((U16*)str_buff);
    str_cursor += 2;

    /* utc to rtc*/
    if (str_cursor[0] == SRV_VCAL_UTC_CHAR)    /* UTC time */
    {
		memcpy(&temp_time, date_time, sizeof(MYTIME));   
		applib_dt_utc_to_rtc_with_default_tz(&temp_time, (applib_time_struct*)date_time);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_recurr
 * DESCRIPTION
 *  Get recurrence of a vCalendar object from an RRULE string
 * PARAMETERS
 *  strRRule        [IN]            String represents the RRULE
 *  recurr          [IN/OUT]        Struct variable the store the result of converting
 * RETURNS
 *  TURE if the RRULE supported, otherwise, FALSE
 *****************************************************************************/
static U8 srv_vcal_parse_recurr(CHAR *str_rule, srv_vcal_recurr_struct *recurr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *tmp_string = str_rule;
    CHAR comp_string[SRV_VCAL_MAX_DT_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    recurr->days = 0;

    if (strlen(tmp_string) < SRV_VCAL_MIN_RECURR_LEN)  /* string too short */
    {
        return MMI_FALSE;
    }
    /* Daily */
    sprintf(comp_string, "%s", g_srv_vcal_recurr[SRV_VCAL_DAILY]);
    if (srv_vcal_parse_cmp_filed(tmp_string, comp_string))
    {
        recurr->repeat = SRV_VCAL_RULE_DAILY;
        return MMI_TRUE;
    }
    /* Days */
    if (srv_vcal_parse_cmp_filed(tmp_string, (CHAR*)g_srv_vcal_recurr[SRV_VCAL_WEEKLY]))
    {
        /* get week days */
        tmp_string += 3; /* move to starting point */
        recurr->days = srv_vcal_parse_days(tmp_string);
        if (recurr->days)
        {
            recurr->repeat = SRV_VCAL_RULE_DAYS;
            return MMI_TRUE;
        }
        tmp_string -= 3; /* move to RRULE starting point */        
    }
     /* Weekly */
    sprintf(comp_string, "%s", g_srv_vcal_recurr[SRV_VCAL_WEEKLY]);
    if (srv_vcal_parse_cmp_filed(tmp_string, comp_string))
    {
        recurr->repeat = SRV_VCAL_RULE_WEEKLY;
        return MMI_TRUE;
    }
    /* Monthly */
    sprintf(comp_string, "%s", g_srv_vcal_recurr[SRV_VCAL_MONTHLY]);
    if (srv_vcal_parse_cmp_filed(tmp_string, g_srv_vcal_recurr[SRV_VCAL_MONTHLY]))
    {
        recurr->repeat = SRV_VCAL_RULE_MONTHLY;
        return MMI_TRUE;
    }
    /* Yearly */
    sprintf(comp_string, "%s", g_srv_vcal_recurr[SRV_VCAL_YEARLY]);
    if (srv_vcal_parse_cmp_filed(tmp_string, comp_string))
    {
        /* Yearly is a special case for TDL repeat type */
        recurr->repeat = SRV_VCAL_RULE_YEARLY; 
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_days
 * DESCRIPTION
 *  Get the day of week value from string
 * PARAMETERS
 *  strDays     [IN]        String to be converted
 * RETURNS
 *  the value of days if found, otherwise 0;
 *****************************************************************************/
static U8 srv_vcal_parse_days(CHAR *str_days)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = SRV_VCAL_RESULT_SUCCESS;
    CHAR *tmp_str = str_days;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (tmp_str[0] == SRV_VCAL_LWSP_CHAR)
    {
        tmp_str++;
    }
    while (tmp_str[0] != SRV_VCAL_NULL && tmp_str[0] != SRV_VCAL_POUND_CHAR)
    {
        for (i = 0; i < SRV_VCAL_NUM_OF_DAYS; i++)
        {
            if (!srv_vcal_parse_strnicmp(tmp_str, (CHAR*)g_srv_vcal_days[i], 2))
            {
                result |= (0x1 << i);
                tmp_str += 2;
                break;
            }
        }
        if (i == SRV_VCAL_NUM_OF_DAYS && result == 0)
        {
            return 0;
        }
        if (tmp_str[0] != SRV_VCAL_LWSP_CHAR && result == 0)
        {
            return 0;
        }
        tmp_str++;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_encoding_para
 * DESCRIPTION
 *  To retrieve the parameter value from a string
 * PARAMETERS
 *  source          [IN]            Source string to be computed.
 *  para_name       [IN]            Parameter to be retrieve.
 *  result          [IN/OUT]        Value of parameter
 *  max_len         [IN]            Maximum length to be convert
 * RETURNS
 *  TRUE if parameter found; otherwise FALSE
 *****************************************************************************/
static U8 srv_vcal_parse_encoding_para(CHAR *source, CHAR *para_name, CHAR *result, S32 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *cursor, *para_end;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    para_end = strstr(source, (CHAR*)SRV_VCAL_VALUE_SEP_STR);

    if ((cursor = strstr(source, para_name)) == NULL)
    {
        return MMI_FALSE;
    }

    /* Encoding keyword may appear in value of parameter */
    if (cursor >= para_end)
    {
        return MMI_FALSE;
    }

    if ((cursor = strstr(cursor, (CHAR*)SRV_VCAL_EQUAL_STR)) == NULL)     /* move cursor next to "=" */
    {
        return MMI_FALSE;
    }

    cursor++;

    for (i = 0; i < max_len; cursor++)
    {
        if (cursor[0] == SRV_VCAL_VALUE_SEP_CHAR || 
            cursor[0] == SRV_VCAL_PARA_SEP_CHAR || 
            cursor[0] == SRV_VCAL_NULL)
        {
            break;
        }
		else if (cursor[0] == SRV_VCAL_LWSP_CHAR)
		{
			continue;
		}

        result[i] = cursor[0];
		i++;
    }

    result[i] = SRV_VCAL_NULL;

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_charset
 * DESCRIPTION
 *  To retrieve the charset
 * PARAMETERS
 *  string      [IN]        String to be parsed
 * RETURNS
 *  Enum value of charset.
 *****************************************************************************/
static U8 srv_vcal_parse_charset(CHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* currently only support UTF-8 */
    if (!srv_vcal_parse_strnicmp(
                        str, 
                        (CHAR*)g_srv_vcal_charset[SRV_VCAL_CH_UTF8], 
                        strlen(g_srv_vcal_charset[SRV_VCAL_CH_UTF8])))
    {
        return SRV_VCAL_CH_UTF8;
    }
#ifdef __MMI_CHSET_UTF7__
    else if (!srv_vcal_parse_strnicmp(
                        str, 
                        (CHAR*)g_srv_vcal_charset[SRV_VCAL_CH_UTF7], 
                        strlen(g_srv_vcal_charset[SRV_VCAL_CH_UTF7])))
    {
        return SRV_VCAL_CH_UTF7;
    }
#endif
    else
    {
        return 0xff;
    }
}

    
/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_encoding_type
 * DESCRIPTION
 *  To retrieve the coding type
 * PARAMETERS
 *  string      [IN]        String to be parsed
 * RETURNS
 *  Enum value of encoding type.
 *****************************************************************************/
static U8 srv_vcal_parse_encoding_type(CHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_VCAL_EN_TOTAL; i++)
    {
        if (!srv_vcal_parse_strnicmp(str, (CHAR*)g_srv_vcal_encoding[i], strlen(g_srv_vcal_encoding[i])))
        {
            break;
        }
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_strnicmp
 * DESCRIPTION
 *  Convert a charcater to lower case
 * PARAMETERS
 *  src         [IN]        String pointer to be compared
 *  dest        [IN]        String pointer to be compared
 *  maxlen      [IN]        Lengh to be compared
 * RETURNS
 *  Ture if two string is identical, otherwise, false
 *****************************************************************************/
static CHAR srv_vcal_parse_strnicmp(CHAR *src, CHAR *dest, S32 maxlen)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int ch1, ch2;
    CHAR *s1, *s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    s1 = src;
    s2 = dest;

    while (maxlen-- > 0)
    {
        ch1 = tolower(*s1++);
        ch2 = tolower(*s2++);
        if (ch1 != ch2)
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_uti_cmp_filed
 * DESCRIPTION
 *  Check if the string constains a filed.
 * PARAMETERS
 *  srcString       [IN]        Source string to be compared.
 *  refString       [IN]        Header of the filed
 * RETURNS
 *  TRUE if string exists, otherwise FALSE.
 *****************************************************************************/
static U8 srv_vcal_parse_cmp_filed(CHAR *src_string, const CHAR *ref_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 refLen, srcLen;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srcLen = strlen(src_string);
    refLen = strlen(ref_string);

    if (srcLen < refLen)
    {
        return MMI_FALSE;
    }
    if (srv_vcal_parse_strnicmp(src_string, (CHAR*)ref_string, refLen))
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_remove_ws
 * DESCRIPTION
 *  Remove white sapce of a string.
 * PARAMETERS
 *  String          [IN/OUT]        String to be converted
 *  Seperator       [IN]            WS before and next to this Seperator will be removed.
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_vcal_parse_remove_ws(CHAR *str, CHAR *seperator, U8 position)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *s_cursor;    /* position of start seperator */
    CHAR *e_cursor;    /* position of end of seperator */
    CHAR *curr_cursor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* locate to seperator */
    if ((s_cursor = strstr(str, seperator)) != NULL)
    {
        if (s_cursor == str)  /* to prevent abnormal case */
        {
            return;
        }
        /* remove ws after seperator */
        if (position != SRV_VCAL_REMOVE_PRE_WS)
        {
            curr_cursor = e_cursor = s_cursor + strlen(seperator);
            while ((curr_cursor[0] == SRV_VCAL_LWSP_CHAR || curr_cursor[0] == SRV_VCAL_TAB_CHAR) && 
                   (curr_cursor[0] != '\0'))
            {
                curr_cursor++;
            }
            if (curr_cursor != e_cursor)
            {
                strcpy(e_cursor, curr_cursor);
            }
        }
        /* remove ws before seperator */
        if (position != SRV_VCAL_REMOVE_POST_WS)
        {
            curr_cursor = s_cursor - 1;
            while ((curr_cursor[0] == SRV_VCAL_LWSP_CHAR || curr_cursor[0] == SRV_VCAL_TAB_CHAR) && 
                   (curr_cursor != str))
            {
                curr_cursor--;
            }
            curr_cursor++;
            if (curr_cursor != s_cursor)
            {
                strcpy(curr_cursor, s_cursor);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_get_field
 * DESCRIPTION
 *  Compute the filed name of a given string.s
 * PARAMETERS
 *  String      [IN]        String to be checked
 * RETURNS
 *  Type of the filed
 *****************************************************************************/
static U8 srv_vcal_parse_get_field(CHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strlen(str) == 0)
    {
        return SRV_VCAL_TOTAL_FILEDS;
    }
    for (i = 0; i < SRV_VCAL_TOTAL_FILEDS; i++)
    {
        if (srv_vcal_parse_cmp_filed(str, g_srv_vcal_fileds[i]))
        {
            break;
        }
    }
    return i;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_parse_get_line
 * DESCRIPTION
 *  read SRV_VCAL_BUILD_BUFF_LEN size buffer from vcs file, then extract vcalendar
 *  field from buffer and output;
 * PARAMETERS
 *  strOutput       [IN/OUT]        Storage location for data
 *  parse_handle    [IN]            vcs File handle
 * RETURNS
 *  S32             field string len
 *****************************************************************************/
static S32 srv_vcal_parse_get_line(CHAR *str_output, srv_vcal_parse_struct *parse_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *original_buffer = NULL;     /* original buffer from argument */
    CHAR *valid_buffer = NULL;        /* pointer to the first valid field */
    CHAR *next_cursor = NULL;         /* pointer to the next field need by parse*/
    CHAR *curr_cursor = NULL;         /* pionter to current position */
    S32 invalid_strlen = 0;         /* invalid string length before the first valid field */
    S32 removed_CRLF = 0;           /* CRLF count that is removed */
    S32 filed_strlen = 0;           /* the current field string length */
    U8 field_type = 0;              /* field type */
    S32 out_bytes = 0;
    S32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (NULL == str_output)
    {
        return 0;
    }
    
    original_buffer = str_output;
    
    FS_Read(parse_handle->fh, original_buffer, SRV_VCAL_BUILD_BUFF_LEN - 1, (UINT *)&out_bytes);
    original_buffer[out_bytes] = 0;

    if (0 == out_bytes)
    {
        return 0;
    }
    /* Remove "\r\n(0D0A)" before original_buffer, only for parsing the first vcalendar*/
    valid_buffer = original_buffer;
    while (strncmp(valid_buffer, SRV_VCAL_CRLF_STR, strlen(SRV_VCAL_CRLF_STR)) == 0)
    {
        valid_buffer += strlen(SRV_VCAL_CRLF_STR);
    }
    invalid_strlen = valid_buffer - original_buffer;
    
    for (i = SRV_VCAL_BEGIN; i < SRV_VCAL_TOTAL_FILEDS; i++)
    {
        if (srv_vcal_parse_strnicmp((CHAR*) g_srv_vcal_fileds[i], valid_buffer, strlen(g_srv_vcal_fileds[i])) == 0)
        {
            field_type = i;
            break;
        }
    }
        
    for (i = SRV_VCAL_BEGIN; i < SRV_VCAL_TOTAL_FILEDS; i++)
    {
        if (i == field_type)
        {
            /* skip the current field to sarech the next field */
            continue;
        }

        /* match the next field addr */
        curr_cursor = srv_vcal_stristr(valid_buffer, g_srv_vcal_fileds[i]);
        
        if (NULL == curr_cursor)
        {
            continue;
        }
        /* Fix the issue AALARM;X-.....*/
        else if (*(curr_cursor - 2) != 0x0D && *(curr_cursor - 1) != 0x0A)
        {
            curr_cursor = next_cursor;
        }
        else if (next_cursor == NULL)
        {
            next_cursor = curr_cursor;
        }
        else
        {
            /* current cursor is nearer than next currsor */
            if ((S32)next_cursor > (S32)curr_cursor)
            {
                next_cursor = curr_cursor;
            }
        }
    }

    /* not find only one */
    if (NULL == next_cursor)
    {
        return out_bytes;
    }

    /* Remove "\r\n(0D0A)" before the next field */
    while (strncmp(
                (CHAR*)(next_cursor - strlen(SRV_VCAL_CRLF_STR)), 
                (CHAR*)SRV_VCAL_CRLF_STR, 
                strlen(SRV_VCAL_CRLF_STR)) == 0)
    {
        next_cursor -= strlen(SRV_VCAL_CRLF_STR);
        removed_CRLF++;
    }

    filed_strlen = (S32)(next_cursor - valid_buffer);

    /* copy the current field to output buffer*/
    if (0 != invalid_strlen)
    {
        for (i = 0; i < filed_strlen; i++)
        {
            *original_buffer = *valid_buffer;
            original_buffer++;
            valid_buffer++;
        }
        *original_buffer = SRV_VCAL_NULL;
    }
    else
    {
        original_buffer[filed_strlen] = SRV_VCAL_NULL;
    }
    
    parse_handle->fs_curr_parse_pos += invalid_strlen + filed_strlen;

    /* move the file position ptr to the next field */
    if (removed_CRLF)
    {
        FS_Seek(parse_handle->fh, (S32)(invalid_strlen + filed_strlen + removed_CRLF * strlen(SRV_VCAL_CRLF_STR) - out_bytes), SEEK_CUR);
    }
    else
    {
        FS_Seek(parse_handle->fh, (S32)(invalid_strlen + filed_strlen - out_bytes), SEEK_CUR);
    }

    return filed_strlen;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_vobj_uti_get_value
 * DESCRIPTION
 *  Get the string after ":"
 * PARAMETERS
 *  strString       [IN]        Input string.
 * RETURNS
 *  pointer to the starting point after ":"
 *****************************************************************************/
static CHAR *srv_vcal_parse_get_value(CHAR *str_string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strstr(str_string, (CHAR*)SRV_VCAL_SEP_STR) != NULL)
    {
	    return (CHAR*)(strstr(str_string, (CHAR*)SRV_VCAL_SEP_STR) + 1);
    }
    else
    {
		return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_stristr
 * DESCRIPTION
 *  This function performs strstr in case-insensitive way.
 * PARAMETERS
 *  src_str     [IN]        Source string
 *  tbf_str     [IN]        String to be found
 * RETURNS
 *  NULL: not found
 *  non-NULL: pointer of 1st found substring
 *****************************************************************************/
static CHAR* srv_vcal_stristr(const CHAR *src_str, const CHAR *tbf_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 match_flag = 0;   /* reset */
    S32 i = 0;            /* reset */
    S32 j = 0;            /* reset */
    S32 reset_i = -1;     /* reset */
    S32 left, left_fixed;
    CHAR s1, s2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!src_str || !tbf_str || !strlen(tbf_str) || !strlen(src_str) || strlen(tbf_str) > strlen(src_str))
    {
        return NULL;
    }

    left = left_fixed = strlen(tbf_str);

    while (*(src_str + i) && *(tbf_str + j) && left)
    {
        if ((*(src_str + i)) <= 'z' && (*(src_str + i)) >= 'A' )
        {
            /* both convert to lower case */
            s1 = (CHAR) (islower((S32) * (src_str + i)) ? *(src_str + i) : tolower((S32) * (src_str + i)));
            s2 = (CHAR) (islower((S32) * (tbf_str + j)) ? *(tbf_str + j) : tolower((S32) * (tbf_str + j)));
        }
        else
        {
            s1 = *(src_str + i);
            s2 = *(tbf_str + j);
        }

        if (s1 != s2)
        {
            if (reset_i >= 0)
            {
                i = reset_i + 1;
                reset_i = -1;
            }
            else
            {
                i++;
            }

            j = 0;
            match_flag = 0;
            left = left_fixed;
        }
        else
        {
            if (match_flag == 0)
            {
                /* 1st matched */
                reset_i = i;
                match_flag = 1;
            }

            i++;
            j++;
            left--;
        }
    }

    if (left == 0)
    {
        /* return 1st matched substring */
        return (CHAR*) src_str + i - left_fixed;
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_set_filed_mask
 * DESCRIPTION
 *  This function performs set filed type mask
 * PARAMETERS
 *  field_mask     [IN/OUT]    filed_mask(MASK VALUE)
 *  field_type     [IN]        vcalendar field type
 * RETURNS
 *  NULL: not found
 *  non-NULL: pointer of 1st found substring
 *****************************************************************************/
static void srv_vcal_set_filed_mask(U32 *field_mask, U16 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *field_mask |= (1 << field_type); 
}


/*****************************************************************************
 * FUNCTION
 *  srv_vcal_check_filed_mask
 * DESCRIPTION
 *  This function performs to check the filed if exist
 * PARAMETERS
 *  field_mask     [IN]        field mask (MASK)
 *  field_type     [IN]        to be checked filed type
 * RETURNS
 *  NULL: not found
 *  non-NULL: pointer of 1st found substring
 *****************************************************************************/
static MMI_BOOL srv_vcal_check_filed_mask(U32 field_mask, U16 field_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (field_mask & (1 << field_type))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#endif /* __MMI_SRV_TODOLIST__ */

