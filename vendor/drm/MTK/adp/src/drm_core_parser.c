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
 * drm_parser.c
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
 *******************************************************************************/
#ifdef __DRM_MTK__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "fs_type.h"
#include "app_base64.h"

#include "drm_def.h"
#include "drm_core_prot.h"
#include "drm_util.h"
#include "drm_memory.h"
#include "drm_trace.h"
#include "drm_gprot.h"

#include "app_datetime.h"
#include "app_str.h"
#include "che_api.h"
#include "drm_core_def.h"
#include "kal_general_types.h"
#include "drm_errcode.h"
#include "kal_public_api.h"
#include "fs_func.h"
#include "fs_errcode.h"
#include "kal_trace.h"
#include "custom_em.h"

#include "custom_mmi_default_value.h"

#ifndef __MTK_TARGET__
#define __align(x)
#define DRM_COUNT_MAX 10000000000
#else
#define DRM_COUNT_MAX 10000000000LL
#endif 
#define CHE_CNTX __align(4) STCHE

/*
 * external variable
 */
extern drm_handle_struct g_drm_handles[DRM_MAX_FILE_HANDLE];

/*
 * local variable
 */
static DRM_WBXML_RIGHTS_STRUCT wb_rights;
static kal_uint8 extra_serial;

/*
 * local function
 */
static drm_proc_enum drm_parse_tag(kal_char *strOutput, kal_uint32 length, FS_HANDLE fh);
static drm_proc_enum drm_parse_context(FS_HANDLE input, drm_rights_struct *info, kal_char *line);
static drm_proc_enum drm_parse_agreement(FS_HANDLE input, drm_rights_struct *rights, kal_char *cid, kal_char *line);
static drm_proc_enum drm_parse_context(FS_HANDLE input, drm_rights_struct *info, kal_char *line);
static kal_char *drm_parse_skip_space(kal_char *line);
static drm_proc_enum drm_parse_asset(FS_HANDLE input, drm_rights_struct *rights, kal_char *cid, kal_char *line);
static drm_proc_enum drm_parse_permission(FS_HANDLE input, drm_rights_struct *rights, kal_char *line);
static void drm_parse_cid(kal_char *cid);
static drm_proc_enum drm_parse_constraint(FS_HANDLE input, drm_constraint_struct *constraint, kal_char *line);
static kal_int32 drm_parse_interval(kal_char *intv);
static kal_int32 drm_parse_time(kal_char *time);
static kal_int32 drm_parse_wb_tag(kal_uint8 type);
static drm_proc_enum drm_parse_wb_context(drm_rights_struct *rights);
static drm_proc_enum drm_parse_wb_agreement(drm_rights_struct *rights, kal_char *cid);
static drm_proc_enum drm_parse_wb_asset(drm_rights_struct *rights, kal_char *cid);
static drm_proc_enum drm_parse_wb_permission(drm_rights_struct *rights);
static drm_proc_enum drm_parse_wb_constraint(drm_constraint_struct *constraint);

/* static kal_int32 drm_uintvar_to_str(kal_uint8 *start, kal_uint32 value, kal_int32 *size); */
static void drm_core_update_multiro_rights(FS_HANDLE ro, drm_rights_struct *rights, drm_rights_struct *old_rights);
static kal_bool drm_parse_dcf_header_field(
                    drm_meta_enum meta_id,
                    drm_info_struct *info,
                    kal_char *header,
                    kal_uint32 total_header_size);
static void drm_core_generate_che_by_fixed_key(kal_uint8 *myKey, kal_uint8 key_len, STCHE *che_str);


/*****************************************************************************
 * FUNCTION
 *  drm_parse_rights
 * DESCRIPTION
 *  parse rights object in combined and separate delivery
 * PARAMETERS
 *  input       [IN]        
 *  rights      [IN]        
 *  cid         [IN]        
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
drm_proc_enum drm_parse_rights(FS_HANDLE input, drm_rights_struct *rights, kal_char *cid, kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *line, *cid_ptr;
    drm_proc_enum result = DRM_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    line = get_ctrl_buffer(DRM_MAX_LINE_LENGTH);
    if (line == NULL)
    {
        return DRM_RESULT_INVALID_FORMAT;
    }

    cid[0] = 0;
    cid[1] = 0;

    if (type == DRM_TYPE_COMBINED_DELIVERY)
    {
        while (1)
        {
            kal_uint32 pos;

            FS_GetFilePosition(input, &pos);
            if (drm_get_line(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
            {
                free_ctrl_buffer(line);
                return DRM_RESULT_INVALID_FORMAT;
            }
            if (strstr(line, "<o-ex:rights") != NULL)
            {
                FS_Seek(input, pos, FS_FILE_BEGIN);
                break;
            }
        }
    }

    /* invoke XML parser */

    /* fill in info struct */

    /* read till next newline => start of content */
    while (1)
    {
        if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
        {
            free_ctrl_buffer(line);
            return DRM_RESULT_INVALID_FORMAT;
        }

        /* skip rights model */
        if (strstr(line, "</o-ex:rights>") != NULL)
        {
            break;
        }
        if (strstr(line, "<o-ex:rights") != NULL)
        {
            if (strstr(line, ">") == NULL)
            {
                while (1)
                {
                    if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
                    {
                        free_ctrl_buffer(line);
                        return DRM_RESULT_INVALID_FORMAT;
                    }
                    if (strstr(line, ">") != NULL)
                    {
                        break;
                    }
                }
            }
            if ((result = drm_parse_context(input, rights, line)) == DRM_RESULT_OK)
            {
                result = drm_parse_agreement(input, rights, cid, line);

                /* check if cid is empty */
                cid_ptr = strstr(cid, "cid:");
                if ( (!cid_ptr) || (strlen(cid_ptr) <= 4) )
                {
                    free_ctrl_buffer(line);
                    return DRM_RESULT_INVALID_FORMAT;
                }
            }
        }
    }

    while (1)
    {
        kal_uint32 pos;

        FS_GetFilePosition(input, &pos);
        if (drm_get_line(line, DRM_MAX_LINE_LENGTH, input) >= FS_NO_ERROR)
        {
            if (line[0] != 0 && line[0] != 0x0a)
            {
                FS_Seek(input, pos, FS_FILE_BEGIN);
                break;
            }
        }
        else
        {
            break;
        }
    }

    free_ctrl_buffer(line);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_context
 * DESCRIPTION
 *  parse context information in rights object
 * PARAMETERS
 *  input       [IN]        
 *  info        [IN]        
 *  line        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drm_proc_enum drm_parse_context(FS_HANDLE input, drm_rights_struct *info, kal_char *line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* get version */
    while (1)
    {
        if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
        {
            return DRM_RESULT_INVALID_FORMAT;
        }
        if (strstr(line, "</o-ex:context>") != NULL)
        {
            break;
        }
        if (strstr(line, "<o-ex:context") != NULL)
        {

        }
        if (strstr(line, "<o-dd:version>") != NULL)
        {
            kal_char *ptr1, *ptr2;

            if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
            {
                return DRM_RESULT_INVALID_FORMAT;
            }
            ptr2 = strstr(line, "</o-dd:version>");
            if (ptr2 == NULL)
            {
                line[DRM_MAX_LINE_LENGTH - 1] = '\0';
            }
            else
            {
                ptr2[0] = '\0';
            }
            ptr1 = drm_parse_skip_space(line);

            if (!ptr1 || strncmp(ptr1, "1.0", 3) != 0)
            {
                return DRM_RESULT_INVALID_FORMAT;
            }
        }

    }

    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_agreement
 * DESCRIPTION
 *  parse agreement information in rights object
 * PARAMETERS
 *  input       [IN]        
 *  rights      [IN]        
 *  cid         [IN]        
 *  line        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drm_proc_enum drm_parse_agreement(FS_HANDLE input, drm_rights_struct *rights, kal_char *cid, kal_char *line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_proc_enum result = DRM_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
        {
            return DRM_RESULT_INVALID_FORMAT;
        }

        /* skip agreement model */
        if (strstr(line, "</o-ex:agreement>") != NULL)
        {
            break;
        }

        if (strstr(line, "<o-ex:agreement>") != NULL)
        {
            if ((result = drm_parse_asset(input, rights, cid, line)) == DRM_RESULT_OK)
            {
                result = drm_parse_permission(input, rights, line);
            }
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_asset
 * DESCRIPTION
 *  parse asset information in rights object
 * PARAMETERS
 *  input       [IN]        
 *  rights      [IN]        
 *  cid         [IN]        
 *  line        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drm_proc_enum drm_parse_asset(FS_HANDLE input, drm_rights_struct *rights, kal_char *cid, kal_char *line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *ptr1, *ptr2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
        {
            return DRM_RESULT_INVALID_FORMAT;
        }

        /* skip agreement model */
        if (strstr(line, "</o-ex:asset>") != NULL)
        {
            break;
        }
        if (strstr(line, "<o-ex:asset>") != NULL)
        {
            kal_bool tag_start = KAL_FALSE, tag_end = KAL_FALSE;

            /* get cid */
            while (1)
            {
                if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
                {
                    return DRM_RESULT_INVALID_FORMAT;
                }
                if (strstr(line, "</o-ex:context>") != NULL)
                {
                    if (tag_start == tag_end)
                    {
                        break;
                    }
                    else
                    {
                        return DRM_RESULT_INVALID_FORMAT;
                    }
                }
                if ((ptr1 = strstr(line, "<o-dd:uid>")) != NULL)
                {
                    tag_start = KAL_TRUE;
                    if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
                    {
                        return DRM_RESULT_INVALID_FORMAT;
                    }

                    ptr2 = strstr(line, "</o-dd:uid>");
                    if (ptr2 == NULL)
                    {
                        line[DRM_MAX_LINE_LENGTH - 1] = '\0';
                    }
                    else
                    {
                        tag_end = KAL_TRUE;
                        ptr2[0] = '\0';
                    }
                    ptr1 = drm_parse_skip_space(line);

                    if (!ptr1)
                    {
                        if (rights->method == DRM_METHOD_SEPARATE_DELIVERY)
                        {
                            return DRM_RESULT_INVALID_FORMAT;
                        }
                        else
                        {
                            continue;
                        }
                    }

                    drm_parse_cid(ptr1);
                    if (rights->method == DRM_METHOD_COMBINED_DELIVERY)
                    {
                        strcpy(cid, "MTK_CD_");
                    }
                    strcat((char*)cid, (char*)ptr1);
                }
            }
            if (rights->method & DRM_METHOD_SEPARATE_DELIVERY)
            {
                while (1)
                {
                    if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
                    {
                        return DRM_RESULT_INVALID_FORMAT;
                    }
                    if (strstr(line, "</ds:KeyInfo>") != NULL)
                    {
                        break;
                    }
                    if ((ptr1 = strstr(line, "<ds:KeyValue>")) != NULL)
                    {
                        kal_uint32 len = 0;
                        kal_uint8 buffer[24];

                        if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
                        {
                            return DRM_RESULT_INVALID_FORMAT;
                        }
                        ptr2 = strstr(line, "</ds:KeyValue>");
                        /* remove space at the end of key */
                        if (ptr2 == NULL)
                        {
                            return DRM_RESULT_INVALID_FORMAT;
                        }

                        while (*(ptr2 - 1) == ' ')
                        {
                            ptr2--;
                        }
                        rights->key_len = ptr2 - line;
                        memcpy(buffer, line, rights->key_len);

                        len = applib_base64_decode(
                                (kal_char*) buffer,
                                rights->key_len,
                                (kal_char*) buffer,
                                rights->key_len);

                        if (len > 16)   /* AES 128 bit */
                        {
                            return DRM_RESULT_INVALID_KEY;
                        }

                        memcpy(rights->key, buffer, len);
                        rights->key_len = len;
                    }
                }
            }
        }
    }
    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_permission
 * DESCRIPTION
 *  parse permission information in rights object
 * PARAMETERS
 *  input       [IN]        
 *  rights      [IN]        
 *  line        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drm_proc_enum drm_parse_permission(FS_HANDLE input, drm_rights_struct *rights, kal_char *line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_constraint_struct *constraint;
    drm_proc_enum result = DRM_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
        {
            return DRM_RESULT_INVALID_FORMAT;
        }

        if (strstr(line, "<o-ex:permission/>") != NULL)
        {
            rights->permission = DRM_PERMISSION_ALL;

            break;
        }

        /* skip agreement model */
        if (strstr(line, "</o-ex:permission>") != NULL)
        {
            break;
        }

        if (strstr(line, "<o-ex:permission>") != NULL)
        {
            continue;
        }

        if (strstr(line, "<o-dd:play") != NULL)
        {
            rights->permission |= DRM_PERMISSION_PLAY;

            constraint = &rights->constraint_list[DRM_MULTIRO_COUNT(rights->num)].cons;
            rights->best[DRM_CONSTRAINT_PLAY_INDEX] = DRM_MULTIRO_COUNT(rights->num);
            rights->num[DRM_CONSTRAINT_PLAY_INDEX]++;
            rights->constraint_list[rights->best[DRM_CONSTRAINT_PLAY_INDEX]].next = 0xFF;

            if (strstr(line, "<o-dd:play/>") != NULL)
            {
                constraint->type = DRM_CONSTRAINT_NONE;
            }
        }
        else if (strstr(line, "<o-dd:display") != NULL)
        {
            rights->permission |= DRM_PERMISSION_DISPLAY;

            constraint = &rights->constraint_list[DRM_MULTIRO_COUNT(rights->num)].cons;
            rights->best[DRM_CONSTRAINT_DISPLAY_INDEX] = DRM_MULTIRO_COUNT(rights->num);
            rights->num[DRM_CONSTRAINT_DISPLAY_INDEX]++;
            rights->constraint_list[rights->best[DRM_CONSTRAINT_DISPLAY_INDEX]].next = 0xFF;

            if (strstr(line, "<o-dd:display/>") != NULL)
            {
                constraint->type = DRM_CONSTRAINT_NONE;
            }
        }
        else if (strstr(line, "<o-dd:execute") != NULL)
        {
            rights->permission |= DRM_PERMISSION_EXECUTE;

            constraint = &rights->constraint_list[DRM_MULTIRO_COUNT(rights->num)].cons;
            rights->best[DRM_CONSTRAINT_EXECUTE_INDEX] = DRM_MULTIRO_COUNT(rights->num);
            rights->num[DRM_CONSTRAINT_EXECUTE_INDEX]++;
            rights->constraint_list[rights->best[DRM_CONSTRAINT_EXECUTE_INDEX]].next = 0xFF;

            if (strstr(line, "<o-dd:execute/>") != NULL)
            {
                constraint->type = DRM_CONSTRAINT_NONE;
            }
        }
        else if (strstr(line, "<o-dd:print") != NULL)
        {
            rights->permission |= DRM_PERMISSION_PRINT;

            constraint = &rights->constraint_list[DRM_MULTIRO_COUNT(rights->num)].cons;
            rights->best[DRM_CONSTRAINT_PRINT_INDEX] = DRM_MULTIRO_COUNT(rights->num);
            rights->num[DRM_CONSTRAINT_PRINT_INDEX]++;
            rights->constraint_list[rights->best[DRM_CONSTRAINT_PRINT_INDEX]].next = 0xFF;

            if (strstr(line, "<o-dd:print/>") != NULL)
            {
                constraint->type = DRM_CONSTRAINT_NONE;
            }
        }
        else
        {
            continue;
        }

        if (strstr(line, "/>") == NULL)
        {
            /* get constraint */
            result = drm_parse_constraint(input, constraint, line);
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_constraint
 * DESCRIPTION
 *  parse constraint information in rights object
 * PARAMETERS
 *  input           [IN]        
 *  constraint      [IN]        
 *  line            [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drm_proc_enum drm_parse_constraint(FS_HANDLE input, drm_constraint_struct *constraint, kal_char *line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *ptr1, *ptr2;
    drm_proc_enum result = DRM_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (1)
    {
        if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
        {
            return DRM_RESULT_INVALID_FORMAT;
        }

        if (strstr(line, "</o-dd:") != NULL)
        {
            break;
        }
        if (strstr(line, "<o-ex:constraint>") != NULL)
        {
            constraint->type = DRM_CONSTRAINT_UNINIT;
            result = DRM_RESULT_OK;

            while (1)
            {
                if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
                {
                    return DRM_RESULT_INVALID_FORMAT;
                }
                if (strstr(line, "</o-ex:constraint>") != NULL)
                {
                    if (constraint->type == DRM_CONSTRAINT_UNINIT && result != DRM_RESULT_INVALID_FORMAT)
                    {
                        constraint->type = DRM_CONSTRAINT_NONE;
                    }
                    break;
                }
                if ((ptr1 = strstr(line, "<o-dd:count>")) != NULL)
                {
                    if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
                    {
                        return DRM_RESULT_INVALID_FORMAT;
                    }
                    ptr2 = strstr(line, "</o-dd:count>");
                    if (ptr2 == NULL)
                    {
                        return DRM_RESULT_INVALID_FORMAT;
                    }
                    ptr2[0] = '\0';
                    ptr1 = drm_parse_skip_space(line);
                    constraint->type |= DRM_CONSTRAINT_COUNT;
                    if ( strlen(ptr1) > 11)
                    {
                        return DRM_RESULT_INVALID_FORMAT;
                    }

                    constraint->total_count = (kal_int64)atof(ptr1);
                    if ( constraint->total_count > DRM_COUNT_MAX )
                    {
                        constraint->total_count = DRM_COUNT_MAX;
                    }

                    constraint->used_count = constraint->total_count;
                    if (ptr1[0] == '-')
                    {
                        result = DRM_RESULT_INVALID_FORMAT;
                    }
                }
                else if ((ptr1 = strstr(line, "<o-dd:interval>")) != NULL)
                {
                    if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
                    {
                        return DRM_RESULT_INVALID_FORMAT;
                    }
                    ptr2 = strstr(line, "</o-dd:interval>");

                    if (ptr2 == NULL)
                    {
                        return DRM_RESULT_INVALID_FORMAT;
                    }

                    ptr2[0] = '\0';
                    ptr1 = drm_parse_skip_space(line);
                    constraint->type |= DRM_CONSTRAINT_INTERVAL;
                    constraint->interval = drm_parse_interval(ptr1);
                    if (constraint->interval == -1)
                    {
                        result = DRM_RESULT_INVALID_FORMAT;
                    }
                }
                else if (strstr(line, "<o-dd:datetime>") != NULL)
                {
                    constraint->type |= DRM_CONSTRAINT_DATETIME;
                    while (1)
                    {
                        if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
                        {
                            return DRM_RESULT_INVALID_FORMAT;
                        }
                        if (strstr(line, "</o-dd:datetime>") != NULL)
                        {
                            break;
                        }
                        if ((ptr1 = strstr(line, "<o-dd:start>")) != NULL)
                        {
                            if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
                            {
                                return DRM_RESULT_INVALID_FORMAT;
                            }
                            ptr2 = strstr(line, "</o-dd:start>");

                            if (ptr2 == NULL)
                            {
                                return DRM_RESULT_INVALID_FORMAT;
                            }

                            ptr2[0] = '\0';
                            ptr1 = drm_parse_skip_space(line);
                            constraint->start_time = drm_parse_time(ptr1);
                            if (constraint->start_time == -1)
                            {
                                result = DRM_RESULT_INVALID_FORMAT;
                            }
                        }
                        else if ((ptr1 = strstr(line, "<o-dd:end>")) != NULL)
                        {
                            if (drm_parse_tag(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
                            {
                                return DRM_RESULT_INVALID_FORMAT;
                            }
                            ptr2 = strstr(line, "</o-dd:end>");
                            if (ptr2 == NULL)
                            {
                                return DRM_RESULT_INVALID_FORMAT;
                            }

                            ptr2[0] = '\0';
                            ptr1 = drm_parse_skip_space(line);
                            constraint->end_time = drm_parse_time(ptr1);
                            if (constraint->end_time == -1)
                            {
                                result = DRM_RESULT_INVALID_FORMAT;
                            }
                        }
                    }
                }
            }

            if (constraint->type == DRM_CONSTRAINT_UNINIT)
            {
                constraint->type = DRM_CONSTRAINT_NONE;
            }

        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_interval
 * DESCRIPTION
 *  parse interval information in rights object
 * PARAMETERS
 *  intv        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 drm_parse_interval(kal_char *intv)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;
    kal_uint32 value = 0;
    kal_uint8 i, len, next, anchor;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&time, 0, sizeof(applib_time_struct));

    len = strlen(intv);

    /* Parse Year */
    i = 1;
    anchor = i;
    for (i = 1; i < len; i++)
    {
        if (intv[i] == 'Y')
        {
            intv[i] = 0;
            break;
        }
    }
    if (i == len)
    {
        next = anchor;
    }
    else
    {
        time.nYear = atoi(&intv[1]);
        next = i + 1;
        anchor = next;
    }

    /* Parse Month */
    for (i = next; i < len; i++)
    {
        if (intv[i] == 'M')
        {
            intv[i] = 0;
            break;
        }
    }
    if (i == len)
    {
        next = anchor;
    }
    else
    {
        time.nMonth = atoi(&intv[next]);
        next = i + 1;
        anchor = next;
    }

    /* Parse Day */
    for (i = next; i < len; i++)
    {
        if (intv[i] == 'D')
        {
            intv[i] = 0;
            break;
        }
    }
    if (i == len)
    {
        next = anchor;
    }
    else
    {
        time.nDay = atoi(&intv[next]);
        next = i + 2;
        anchor = next;
    }

    /* Parse Hour */
    for (i = next; i < len; i++)
    {
        if (intv[i] == 'H')
        {
            intv[i] = 0;
            break;
        }
    }
    if (i == len)
    {
        next = anchor;
    }
    else
    {
        time.nHour = atoi(&intv[next]);
        next = i + 1;
        anchor = next;
    }

    /* Parse Minute */
    for (i = next; i < len; i++)
    {
        if (intv[i] == 'M')
        {
            intv[i] = 0;
            break;
        }
    }
    if (i == len)
    {
        next = anchor;
    }
    else
    {
        time.nMin = atoi(&intv[next]);
        next = i + 1;
        anchor = next;
    }

    /* Parse Second */
    for (i = next; i < len; i++)
    {
        if (intv[i] == 'S')
        {
            intv[i] = 0;
            break;
        }
    }
    if (i == len)
    {
        next = anchor;
    }
    else
    {
        time.nSec = atoi(&intv[next]);
    }

    value = (kal_uint32) time.nYear * 365 * DT_SEC_PER_DAY +
        (kal_uint32) time.nMonth * 30 * DT_SEC_PER_DAY +
        (kal_uint32) time.nDay * DT_SEC_PER_DAY +
        (kal_uint32) time.nHour * DT_SEC_PER_HOUR + time.nMin * DT_SEC_PER_MIN + time.nSec;

    if (value > 0x7FFFFFFF)
    {
        value = 0x7FFFFFFF;
    }

    return value;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_time
 * DESCRIPTION
 *  parse time information in rights object
 * PARAMETERS
 *  time        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 drm_parse_time(kal_char *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct t;
    kal_char temp[5];
    kal_uint32 value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    strncpy(temp, time, 5);
    if (temp[4] != '-')
    {
        return -1;
    }
    temp[4] = '\0';
    t.nYear = atoi(temp);

    strncpy(temp, &time[5], 3);
    if (temp[2] != '-')
    {
        return -1;
    }
    temp[2] = '\0';
    t.nMonth = atoi(temp);

    strncpy(temp, &time[8], 3);
    if (temp[2] != 'T')
    {
        return -1;
    }
    temp[2] = '\0';
    t.nDay = atoi(temp);

    strncpy(temp, &time[11], 3);
    if (temp[2] != ':')
    {
        return -1;
    }
    temp[2] = '\0';
    t.nHour = atoi(temp);

    strncpy(temp, &time[14], 3);
    if (temp[2] != ':')
    {
        return -1;
    }
    temp[2] = '\0';
    t.nMin = atoi(temp);

    strncpy(temp, &time[17], 3);
    if (temp[2] != '\0')
    {
        return -1;
    }
    temp[2] = '\0';
    t.nSec = atoi(temp);

    value = applib_dt_mytime_2_utc_sec(&t, KAL_FALSE);

    return value;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_encoding
 * DESCRIPTION
 *  parse encoding in content header of forward lock and combined delivery
 * PARAMETERS
 *  encoding        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint8 drm_parse_encoding(kal_char *encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strncmp(encoding, "binary", 6) == 0)
    {
        return DRM_ENCODING_BINARY;
    }
    if (strncmp(encoding, "base64", 6) == 0)
    {
        return DRM_ENCODING_BASE64;
    }
    return DRM_ENCODING_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_wb_rights
 * DESCRIPTION
 *  parse wbxml rights object
 * PARAMETERS
 *  input       [IN]        
 *  rights      [IN]        
 *  cid         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
drm_proc_enum drm_parse_wb_rights(FS_HANDLE input, drm_rights_struct *rights, kal_char *cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    drm_proc_enum result = DRM_RESULT_OK;
    kal_char *cid_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&wb_rights, 0, sizeof(DRM_WBXML_RIGHTS_STRUCT));

    FS_GetFileSize(input, &wb_rights.len);

    if (wb_rights.len > DRM_MAX_WBXML_SIZE)
    {
        return DRM_RESULT_SIZE_TOO_BIG;
    }

    if (FS_Read(input, wb_rights.data, DRM_MAX_WBXML_SIZE, &len) >= FS_NO_ERROR)
    {
        if (wb_rights.data[0] == 0x03 && wb_rights.data[1] == 0x0e && wb_rights.data[2] == 0x6a)
        {
            wb_rights.offset += 3;
            /* skip string table */
            if (wb_rights.data[wb_rights.offset++] > 0)
            {

            }

            if (drm_parse_wb_tag(DRM_WB_TAG_START) < FS_NO_ERROR)
            {
                return DRM_RESULT_INVALID_FORMAT;
            }
            if ((wb_rights.data[wb_rights.offset - 1] & 0x3f) == DRM_WB_RIGHTS_TAG)     /* <o-ex:rights> */
            {
                while (1)   /* skip rights info */
                {
                    if (drm_parse_wb_tag(DRM_WB_TAG_END) < FS_NO_ERROR)
                    {
                        return DRM_RESULT_INVALID_FORMAT;
                    }
                    else
                    {
                        break;
                    }
                }
                if ((result = drm_parse_wb_context(rights)) == DRM_RESULT_OK)
                {
                    result = drm_parse_wb_agreement(rights, cid);

                    /* check if cid is empty */
                    cid_ptr = strstr(cid, "cid:");
                    if ( (!cid_ptr) || (strlen(cid_ptr) <= 4) )
                    {
                        return DRM_RESULT_INVALID_FORMAT;
                    }
                }
            }
            if (drm_parse_wb_tag(DRM_WB_TAG_END) >= FS_NO_ERROR)        /* </o-ex:rights> */
            {
                return result;
            }
        }
    }
    return DRM_RESULT_INVALID_FORMAT;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_wb_context
 * DESCRIPTION
 *  parse context information in rights object
 * PARAMETERS
 *  rights      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drm_proc_enum drm_parse_wb_context(drm_rights_struct *rights)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_parse_wb_tag(DRM_WB_TAG_START) >= FS_NO_ERROR)
    {
        if ((wb_rights.data[wb_rights.offset - 1] & 0x3f) == DRM_WB_CONTEXT_TAG)        /* <o-ex:context> */
        {
            while (1)
            {
                if (drm_parse_wb_tag(DRM_WB_TAG_START) >= FS_NO_ERROR)
                {
                    if ((wb_rights.data[wb_rights.offset - 1] & 0x3f) == DRM_WB_VERSION_TAG)
                    {
                        kal_char *ptr;

                        ptr = (kal_char*) & wb_rights.data[wb_rights.offset + 1];

                        if (strncmp(ptr, "1.0", 3) != 0)
                        {
                            return DRM_RESULT_INVALID_FORMAT;
                        }
                        drm_parse_wb_tag(DRM_WB_TAG_END);   /* </o-dd:version> */
                        break;
                    }
                }
                else
                {
                    return DRM_RESULT_INVALID_FORMAT;
                }
            }

            drm_parse_wb_tag(DRM_WB_TAG_END);   /* </o-ex:context> */
            return DRM_RESULT_OK;
        }
    }
    return DRM_RESULT_INVALID_FORMAT;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_wb_agreement
 * DESCRIPTION
 *  parse agreement information in rights object
 * PARAMETERS
 *  rights      [IN]        
 *  cid         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drm_proc_enum drm_parse_wb_agreement(drm_rights_struct *rights, kal_char *cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_proc_enum result = DRM_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_parse_wb_tag(DRM_WB_TAG_START) >= FS_NO_ERROR)
    {
        if ((wb_rights.data[wb_rights.offset - 1] & 0x3f) == DRM_WB_AGREEMENT_TAG)      /* <o-ex:agreement> */
        {
            if (drm_parse_wb_asset(rights, cid) == DRM_RESULT_INVALID_FORMAT)
            {
                return DRM_RESULT_INVALID_FORMAT;
            }

            result = drm_parse_wb_permission(rights);
            if (drm_parse_wb_tag(DRM_WB_TAG_END) != FS_NO_ERROR)        /* </o-ex:agreement> */
            {
                return DRM_RESULT_INVALID_FORMAT;
            }

            return result;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_wb_asset
 * DESCRIPTION
 *  parse asset information in rights object
 * PARAMETERS
 *  rights      [IN]        
 *  cid         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drm_proc_enum drm_parse_wb_asset(drm_rights_struct *rights, kal_char *cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_parse_wb_tag(DRM_WB_TAG_START) >= FS_NO_ERROR)
    {
        if ((wb_rights.data[wb_rights.offset - 1] & 0x3f) == DRM_WB_ASSET_TAG)  /* <o-ex:asset> */
        {
            while (1)
            {
                if (drm_parse_wb_tag(DRM_WB_TAG_START) >= FS_NO_ERROR)
                {
                    if ((wb_rights.data[wb_rights.offset - 1] & 0x3f) == DRM_WB_UID_TAG)
                    {
                        kal_char *ptr;

                        ptr = (kal_char*) & wb_rights.data[wb_rights.offset + 1];
                        ptr = drm_parse_skip_space(ptr);
						if (!ptr)
						{
							return DRM_RESULT_INVALID_FORMAT;
						}
						drm_parse_cid(ptr);
                        strncpy(cid, ptr, DRM_MAX_URL_LENGTH);
                        if (drm_parse_wb_tag(DRM_WB_TAG_END) != FS_NO_ERROR)    /* </o-dd:uid> */
                        {
                            return DRM_RESULT_INVALID_FORMAT;
                        }
                        if (drm_parse_wb_tag(DRM_WB_TAG_END) != FS_NO_ERROR)    /* </o-ex:context> */
                        {
                            return DRM_RESULT_INVALID_FORMAT;
                        }
                        break;
                    }
                }
                else
                {
                    return DRM_RESULT_INVALID_FORMAT;
                }

            }
            while (1)
            {
                if (drm_parse_wb_tag(DRM_WB_TAG_START) >= FS_NO_ERROR)
                {
                    if ((wb_rights.data[wb_rights.offset - 1] & 0x3f) == DRM_WB_KEYVALUE_TAG)
                    {
                        rights->key_len = wb_rights.data[wb_rights.offset + 1];
                        wb_rights.offset++;
                        memcpy(rights->key, &wb_rights.data[wb_rights.offset + 1], rights->key_len);
                        wb_rights.offset += rights->key_len;
                        if (drm_parse_wb_tag(DRM_WB_TAG_END) != FS_NO_ERROR)    /* </ds:KeyValue> */
                        {
                            return DRM_RESULT_INVALID_FORMAT;
                        }
                        if (drm_parse_wb_tag(DRM_WB_TAG_END) != FS_NO_ERROR)    /* </ds:KeyInfo> */
                        {
                            return DRM_RESULT_INVALID_FORMAT;
                        }
                        break;
                    }
                }
                else
                {
                    return DRM_RESULT_INVALID_FORMAT;
                }

            }

            if (drm_parse_wb_tag(DRM_WB_TAG_END) != FS_NO_ERROR)        /* </o-ex:asset> */
            {
                return DRM_RESULT_INVALID_FORMAT;
            }
            else
            {
                return DRM_RESULT_OK;
            }
        }
    }

    return DRM_RESULT_INVALID_FORMAT;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_wb_permission
 * DESCRIPTION
 *  parse permission information in rights object
 * PARAMETERS
 *  rights      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drm_proc_enum drm_parse_wb_permission(drm_rights_struct *rights)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_constraint_struct *constraint;
    drm_proc_enum result = DRM_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_parse_wb_tag(DRM_WB_TAG_START) >= FS_NO_ERROR)
    {
        if ((wb_rights.data[wb_rights.offset - 1] & 0x3f) == DRM_WB_PERMISSION_TAG)     /* <o-ex:permission> */
        {
            while (1)
            {
                if (drm_parse_wb_tag(DRM_WB_TAG_START) >= FS_NO_ERROR)
                {
                    kal_uint8 tag;

                    tag = wb_rights.data[wb_rights.offset - 1];
                    if ((tag & 0x3f) == DRM_WB_PLAY_TAG)
                    {
                        rights->permission |= DRM_PERMISSION_PLAY;

                        constraint = &rights->constraint_list[DRM_MULTIRO_COUNT(rights->num)].cons;
                        rights->best[DRM_CONSTRAINT_PLAY_INDEX] = DRM_MULTIRO_COUNT(rights->num);
                        rights->num[DRM_CONSTRAINT_PLAY_INDEX]++;
                        rights->constraint_list[rights->best[DRM_CONSTRAINT_PLAY_INDEX]].next = 0xFF;

                        if(tag == DRM_WB_PLAY_TAG)
                        {
                            constraint->type = DRM_CONSTRAINT_NONE;
                        }
                    }
                    else if ((tag & 0x3f) == DRM_WB_DISPLAY_TAG)
                    {
                        rights->permission |= DRM_PERMISSION_DISPLAY;

                        constraint = &rights->constraint_list[DRM_MULTIRO_COUNT(rights->num)].cons;
                        rights->best[DRM_CONSTRAINT_DISPLAY_INDEX] = DRM_MULTIRO_COUNT(rights->num);
                        rights->num[DRM_CONSTRAINT_DISPLAY_INDEX]++;
                        rights->constraint_list[rights->best[DRM_CONSTRAINT_DISPLAY_INDEX]].next = 0xFF;

                        if(tag == DRM_WB_DISPLAY_TAG)
                        {
                            constraint->type = DRM_CONSTRAINT_NONE;
                        }
                    }
                    else if ((tag & 0x3f) == DRM_WB_PRINT_TAG)
                    {
                        rights->permission |= DRM_PERMISSION_PRINT;

                        constraint = &rights->constraint_list[DRM_MULTIRO_COUNT(rights->num)].cons;
                        rights->best[DRM_CONSTRAINT_PRINT_INDEX] = DRM_MULTIRO_COUNT(rights->num);
                        rights->num[DRM_CONSTRAINT_PRINT_INDEX]++;
                        rights->constraint_list[rights->best[DRM_CONSTRAINT_PRINT_INDEX]].next = 0xFF;

                        if(tag == DRM_WB_PRINT_TAG)
                        {
                            constraint->type = DRM_CONSTRAINT_NONE;
                        }
                    }
                    else if ((tag & 0x3f) == DRM_WB_EXECUTE_TAG)
                    {
                        rights->permission |= DRM_PERMISSION_EXECUTE;

                        constraint = &rights->constraint_list[DRM_MULTIRO_COUNT(rights->num)].cons;
                        rights->best[DRM_CONSTRAINT_EXECUTE_INDEX] = DRM_MULTIRO_COUNT(rights->num);
                        rights->num[DRM_CONSTRAINT_EXECUTE_INDEX]++;
                        rights->constraint_list[rights->best[DRM_CONSTRAINT_EXECUTE_INDEX]].next = 0xFF;

                        if(tag == DRM_WB_EXECUTE_TAG)
                        {
                            constraint->type = DRM_CONSTRAINT_NONE;
                        }
                    }
                    else
                    {
                        break;
                    }

                    if (tag & 0x40)
                    {
                        result = drm_parse_wb_constraint(constraint);
                        drm_parse_wb_tag(DRM_WB_TAG_END);   /* </o-dd:xxx> */
                    }
                }
                else
                {
                    break;
                }
            }
            drm_parse_wb_tag(DRM_WB_TAG_END);   /* </o-ex:permission> */
            return result;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_wb_constraint
 * DESCRIPTION
 *  parse constraint information in rights object
 * PARAMETERS
 *  constraint      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drm_proc_enum drm_parse_wb_constraint(drm_constraint_struct *constraint)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_proc_enum result = DRM_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (drm_parse_wb_tag(DRM_WB_TAG_START) >= FS_NO_ERROR)
    {
        if ((wb_rights.data[wb_rights.offset - 1] & 0x3f) == DRM_WB_CONSTRAINT_TAG)     /* <o-ex:constraint> */
        {
            constraint->type = DRM_CONSTRAINT_UNINIT;

            while (1)
            {
                kal_uint32 offset;

                offset = wb_rights.offset;
                if (drm_parse_wb_tag(DRM_WB_TAG_START) >= FS_NO_ERROR)
                {
                    kal_uint8 tag;
                    kal_char *ptr;

                    tag = wb_rights.data[wb_rights.offset - 1];
                    ptr = (kal_char*) & wb_rights.data[wb_rights.offset + 1];
                    if ((tag & 0x3f) == DRM_WB_COUNT_TAG)
                    {
                        constraint->type |= DRM_CONSTRAINT_COUNT;
                        if ( strlen(ptr) > 11)
                        {
                            return DRM_RESULT_INVALID_FORMAT;
                        }

                        constraint->total_count = (kal_int64)atof(ptr);
                        if ( constraint->total_count > DRM_COUNT_MAX )
                        {
                            constraint->total_count = DRM_COUNT_MAX;
                        }

                        constraint->used_count = constraint->total_count;
                        if (ptr[0] == '-')
                        {
                            result = DRM_RESULT_INVALID_FORMAT;
                        }
                        wb_rights.offset += strlen(ptr) + 2;
                        drm_parse_wb_tag(DRM_WB_TAG_END);   /* </o-dd:count> */
                    }
                    else if ((tag & 0x3f) == DRM_WB_DATETIME_TAG)
                    {
                        constraint->type |= DRM_CONSTRAINT_DATETIME;
                        while (1)
                        {
                            offset = wb_rights.offset;
                            if (drm_parse_wb_tag(DRM_WB_TAG_START) >= FS_NO_ERROR)
                            {
                                ptr = (kal_char*) & wb_rights.data[wb_rights.offset + 1];
                                if ((wb_rights.data[wb_rights.offset - 1] & 0x3f) == DRM_WB_START_TAG)
                                {
                                    constraint->start_time = drm_parse_time(ptr);
                                    if (constraint->start_time == -1)
                                    {
                                        result = DRM_RESULT_INVALID_FORMAT;
                                    }
                                    wb_rights.offset += strlen(ptr) + 2;
                                    drm_parse_wb_tag(DRM_WB_TAG_END);   /* </o-dd:start> */
                                }
                                else if ((wb_rights.data[wb_rights.offset - 1] & 0x3f) == DRM_WB_END_TAG)
                                {
                                    constraint->end_time = drm_parse_time(ptr);
                                    if (constraint->end_time == -1)
                                    {
                                        result = DRM_RESULT_INVALID_FORMAT;
                                    }
                                    wb_rights.offset += strlen(ptr) + 2;
                                    drm_parse_wb_tag(DRM_WB_TAG_END);   /* </o-dd:end> */
                                }
                                else    /* unknown */
                                {
                                    wb_rights.offset = offset;
                                    break;
                                }
                            }
                            else
                            {
                                break;
                            }
                        }
                        drm_parse_wb_tag(DRM_WB_TAG_END);   /* </o-dd:datetime> */
                    }
                    else if ((tag & 0x3f) == DRM_WB_INTERVAL_TAG)
                    {
                        constraint->type |= DRM_CONSTRAINT_INTERVAL;
                        wb_rights.offset += strlen(ptr) + 2;
                        constraint->interval = drm_parse_interval(ptr);
                        if (constraint->interval == -1)
                        {
                            result = DRM_RESULT_INVALID_FORMAT;
                        }
                        drm_parse_wb_tag(DRM_WB_TAG_END);   /* </o-dd:interval> */
                    }
                    else
                    {
                        wb_rights.offset = offset;
                        break;
                    }
                }
                else
                {
                    break;
                }
            }

            if (constraint->type == DRM_CONSTRAINT_UNINIT)
            {
                constraint->type = DRM_CONSTRAINT_NONE;
            }

            drm_parse_wb_tag(DRM_WB_TAG_END);   /* </o-ex:constraint> */
            return result;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_content
 * DESCRIPTION
 *  parse content for forward lock and combined delivery
 * PARAMETERS
 *  input           [IN]        
 *  rights          [IN]        
 *  encoding        [IN]        
 *  cid             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
drm_proc_enum drm_parse_content(FS_HANDLE input, drm_rights_struct *rights, kal_uint8 *encoding, kal_char *cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_FileInfo file_info;
    kal_char *line;
    kal_uint32 len;
	kal_bool valid_content_type = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    line = get_ctrl_buffer(DRM_MAX_LINE_LENGTH);
    if (line == NULL)
    {
        return DRM_RESULT_INVALID_FORMAT;
    }

    /* get boundary */
    while (1)
    {
        if (drm_get_line(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
        {
            free_ctrl_buffer(line);
            return DRM_RESULT_INVALID_FORMAT;
        }
        if (strlen(line) > 0)
        {
            break;
        }
    }
    /* 6: \r\nboundary--\r\n */
    FS_GetFileSize(input, &len);
    rights->data_len = len - strlen(line) - 6;
    /* skip content id, content transfer encoding..., etc. until new line */
    while (1)
    {
        if (drm_get_line(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
        {
            free_ctrl_buffer(line);
            return DRM_RESULT_INVALID_FORMAT;
        }
        if (strlen((char*)line) == 0)
        {
            break;
        }
        toLower((kal_uint8*) line);
		if (strstr(line, DRM_TOKEN_CONTENT_TYPE))
		{
			kal_char *ptr, *pos;
			kal_int32 mime;

			ptr = drm_parse_skip_space(&line[strlen(DRM_TOKEN_CONTENT_TYPE)]);

			if (!ptr)
			{
				free_ctrl_buffer(line);
				return DRM_RESULT_INVALID_FORMAT;
			}

			pos = strstr(ptr, ";");
			if (pos != NULL)
			{
				*pos = 0;
			}
			/* multiple RO */
			if (strcmp(ptr, DRM_MIMETYPE_RIGHTS) == 0)
			{
				free_ctrl_buffer(line);
				return DRM_RESULT_INVALID_FORMAT;
			}
			DRM_MTK_TRACE(("Mime type = %s"), (TRACE_INFO, DRM_MTK_PARSER_TYPE, ptr));
			mime = mime_to_int(ptr);
			rights->mime_type = (mime == -1) ? 0xff : mime;
			valid_content_type = KAL_TRUE;
		}
        if (strstr(line, DRM_TOKEN_CONTENT_ID))
        {
            kal_char *ptr, *pos;

            /* FL will not have content id */
            if (!(rights->method & DRM_METHOD_FORWARD_LOCK))
            {
                ptr = drm_parse_skip_space(&line[strlen(DRM_TOKEN_CONTENT_ID)]);
                if (!ptr)
                {
                    free_ctrl_buffer(line);
                    return DRM_RESULT_INVALID_FORMAT;
                }

                /* skip <> */
                ptr++;
                pos = strstr(ptr, ">");
                if (pos != NULL)
                {
                    *pos = 0;
                }
                drm_parse_cid(ptr);
                /* match content id between rights and content */
                if (cid != NULL && rights->method == DRM_METHOD_COMBINED_DELIVERY)
                {
                    pos = strstr(cid, ptr);
                    /* not match */
                    if (pos == NULL)
                    {
                        free_ctrl_buffer(line);
                        return DRM_RESULT_INVALID_FORMAT;
                    }
                }
            }
        }
        else if (strstr(line, DRM_TOKEN_ENCODING_TYPE))
        {
            kal_char *ptr;

            ptr = drm_parse_skip_space(&line[strlen(DRM_TOKEN_ENCODING_TYPE)]);
            if (!ptr)
            {
                free_ctrl_buffer(line);
                return DRM_RESULT_INVALID_FORMAT;
            }

            if (encoding != NULL)
            {
                *encoding = drm_parse_encoding(ptr);
            }
        }
    }

    if (valid_content_type == KAL_FALSE)
	{
		free_ctrl_buffer(line);
		return DRM_RESULT_INVALID_FORMAT;
	}

	if (FS_GetFileInfo(input, &file_info) == FS_NO_ERROR)
    {
        rights->offset = file_info.FilePos;
    }
    rights->data_len -= rights->offset;

    /* if last two byte is not \r\n, file len + 2 */
    FS_Seek(input, len - 2, FS_FILE_BEGIN);
    if (FS_Read(input, line, 2, &len) >= FS_NO_ERROR && line[0] != '\r' && line[1] != '\n')
    {
        rights->data_len += 2;
    }
    FS_Seek(input, rights->offset, FS_FILE_BEGIN);

    free_ctrl_buffer(line);
    return DRM_RESULT_OK;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_dcf
 * DESCRIPTION
 *  parse separate delivery content
 * PARAMETERS
 *  input       [IN]        
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
drm_proc_enum drm_parse_dcf(FS_HANDLE input, drm_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *buffer = NULL;
    kal_char *line, *ptr;
    kal_uint32 len1, len2, length = 0, len;
    kal_int32 temp, result = DRM_RESULT_OK;
    kal_uint32 sd_pos;
    drm_rights_struct *rights = info->rights;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FS_GetFilePosition(input, &sd_pos);
    buffer = drmt_mem_alloc(DRM_MAX_LINE_LENGTH);
    if (FS_Read(input, buffer, 3, &length) == FS_NO_ERROR && length > 0)
    {
        if (buffer[0] != 1)
        {
            DRM_RESULT(result, DRM_RESULT_INVALID_FORMAT, finally);
        }

        /* ContentTypeLen */
        len1 = buffer[1];
        /* ContentURILen */
        len2 = buffer[2];

        if (len2 > 128)
        {
            DRM_RESULT(result, DRM_RESULT_INVALID_FORMAT, finally);
        }

        /* get content type */
        memset(buffer, 0, DRM_MAX_LINE_LENGTH);
        FS_Read(input, buffer, len1, &len);
        length += len;
        {
            kal_int32 mime;

            mime = mime_to_int((char*)buffer);
            rights->mime_type = (mime == -1) ? 0xff : mime;
        }

        /* get new file extension name according to mime type */
        drm_replace_file_extension(info->content_path, rights->mime_type);

        /* get content id */
        len2 = ((len2 > DRM_MAX_URL_LENGTH) ? DRM_MAX_URL_LENGTH : len2);
        memset(buffer, 0, DRM_MAX_LINE_LENGTH);
        FS_Read(input, buffer, len2, &len);
        length += len;
        drm_parse_cid((char*)buffer);
        strncpy(info->meta[DRM_META_CONTENTURI], (char*)buffer, DRM_MAX_URL_LENGTH);

        FS_Read(input, buffer, 10, &len);
        /* len1: header length */
        temp = drm_parse_uintvar(buffer, &len1, len);
        if (len1 == 0)
        {
            /* RI Header is mandatory */
            DRM_RESULT(result, DRM_RESULT_INVALID_FORMAT, finally);
        }

        length += temp;
        /* len2: data length */
        temp = drm_parse_uintvar(&buffer[temp], &len2, len - temp);
        length += temp;
        FS_Seek(input, length + sd_pos, FS_FILE_BEGIN);

        length += len1;

        /* get header, use dynamic allocate memory */
        line = (kal_char*) buffer;
        while (len1 > 0)
        {
            kal_int32 result;
            kal_uint32 size;

            size = (len1 > DRM_MAX_LINE_LENGTH) ? DRM_MAX_LINE_LENGTH : len1;
            if ((result = drm_get_line(line, size, input)) > 0)
            {
                len1 -= result;
                if ((ptr = strstr(line, ":")) != NULL)
                {
                    kal_char ch;

                    ch = ptr[1];
                    ptr[1] = 0;
                    toLower((kal_uint8*) line);
                    ptr[1] = ch;
                    if ((ptr = strstr(line, DRM_TOKEN_RIGHTS_ISSUER)) != NULL)
                    {
                        kal_uint32 value_len = 0;

                        ptr = drm_parse_skip_space(&ptr[strlen(DRM_TOKEN_RIGHTS_ISSUER)]);
						if(ptr)
						{
							value_len = strlen(ptr);
							if (value_len > DRM_MAX_CID_URL_LENGTH)
							{
								free_ctrl_buffer(line);
								DRM_RESULT(result, DRM_RESULT_INVALID_FORMAT, finally);
							}
							if (info->meta[DRM_META_RIGHTS_ISSUER] == NULL)
								info->meta[DRM_META_RIGHTS_ISSUER] = (kal_char*) drmt_mem_alloc(value_len + 1);

							if (info->meta[DRM_META_RIGHTS_ISSUER])
								strncpy((kal_char*) info->meta[DRM_META_RIGHTS_ISSUER], ptr, value_len + 1);
						}
					}
                }
            }
            else
            {
                break;
            }
        }

        rights->offset += length;

        /* reset file pointer to the begining of file */
        FS_Seek(input, 0, FS_FILE_BEGIN);
        DRM_RESULT(result, DRM_RESULT_OK, finally);
    }
    else
    {
        /* fail */
        DRM_RESULT(result, DRM_RESULT_INVALID_FORMAT, finally);
    }

  finally:
    if (buffer)
        drmt_mem_free(buffer);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_cid
 * DESCRIPTION
 *  parse content id in DCF
 * PARAMETERS
 *  cid     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void drm_parse_cid(kal_char *cid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *ptr, *convert_cid = cid;
    kal_uint32 cid_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (((ptr = strstr(cid, "http://")) != NULL) || ((ptr = strstr(cid, "HTTP://")) != NULL))
    {
        cid_len = strlen(&ptr[7]);
        *ptr = 0;
        strncat(convert_cid, &ptr[7], cid_len);
    }

    else if (((ptr = strstr(cid, "MTK_FL_cid")) != NULL) || ((ptr = strstr(cid, "MTK_CD_cid")) != NULL))
    {
        convert_cid += 7;
    }
    else if ((ptr = strstr(cid, "MTK_FLDCF_cid")) != NULL)
    {
        convert_cid += 10;
    }
    toLower((kal_uint8*) convert_cid);
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_method
 * DESCRIPTION
 *  parse method in DRM message
 * PARAMETERS
 *  input       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 drm_parse_method(FS_HANDLE input)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *line;
    kal_int32 obj_type = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    line = get_ctrl_buffer(DRM_MAX_LINE_LENGTH);

    /* read boundary */

         
    while (1)
    {
        if (drm_get_line(line, DRM_MAX_LINE_LENGTH, input) < FS_NO_ERROR)
        {
            free_ctrl_buffer(line);
            return DRM_RESULT_INVALID_FORMAT;
        }
        if (strlen(line) > 0)
        {   
            break;
        }
    }

    /* read content type */
    drm_get_line(line, DRM_MAX_LINE_LENGTH, input);
    toLower((kal_uint8*) line);
    if (strstr(line, DRM_TOKEN_CONTENT_TYPE))
    {
        kal_char *ptr;

        ptr = drm_parse_skip_space(&line[strlen(DRM_TOKEN_CONTENT_TYPE)]);
        obj_type = mime_to_int(ptr);
    }

    FS_Seek(input, 0, FS_FILE_BEGIN);
    free_ctrl_buffer(line);
    return obj_type;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_skip_space
 * DESCRIPTION
 *  skip white space in an ASCII string
 * PARAMETERS
 *  line        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_char *drm_parse_skip_space(kal_char *line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i, len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    len = strlen(line);
    for (i = len - 1; i >= 0; i--)
    {
        if (line[i] != ' ' && line[i] != 0x0a && line[i] != 0x0d)
        {
            line[i + 1] = 0;
            break;
        }
    }
    for (i = 0; i < len; i++)
    {
        if (line[i] != ' ' && line[i] != 0x0d && line[i] != 0x0a)
        {
            return &line[i];
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_uintvar
 * DESCRIPTION
 *  convert UINTVAR value to UINT32
 * PARAMETERS
 *  start       [IN]        
 *  value       [IN]        
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 drm_parse_uintvar(void *start, kal_uint32 *value, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i, U8;
    kal_uint8 *ptr;
    kal_int32 result = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = start;

    for (i = 0; i < size && i < 5; i++)
    {
        /* append to result */
        U8 = ptr[i] & 0x7f;
        result <<= 7;
        result |= U8;
        if ((ptr[i] & 0x80) == 0)
        {
            break;
        }
    }
    if (i == 5 || i == size)
    {
        return -1;
    }
    *value = result;

    /* return how many bytes consumed */
    return i + 1;
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
/* under construction !*/
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  drm_parse_base64
 * DESCRIPTION
 *  convert base64 encoding content to binary
 * PARAMETERS
 *  input           [IN]        
 *  output          [IN]        The source file may be read only
 *  rights          [IN]        
 *  out_offset      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_parse_base64(FS_HANDLE input, FS_HANDLE output, drm_rights_struct *rights, kal_uint32 out_offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len2, read_p = 0, write_p = 0;
    kal_int32 size, len = 0;
    kal_char *line;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    line = get_ctrl_buffer(DRM_MAX_LINE_LENGTH);
    FS_Seek(input, rights->offset, FS_FILE_BEGIN);

    while (read_p < rights->data_len)
    {
        kal_uint32 half = 0;

        size = drm_get_line(line, DRM_MAX_LINE_LENGTH - 3, input);
        if (size < FS_NO_ERROR)
        {
            free_ctrl_buffer(line);
            return;
        }

        line[size++] = 0x0d;
        if (line[size] != 0x0a)
            half = 1;
        line[size++] = 0x0a;
        line[size] = 0;
        read_p += size - half;

        len = applib_base64_decode(line, size, line, size);

        FS_Seek(output, out_offset + write_p, FS_FILE_BEGIN);
        FS_Write(output, line, len, &len2);
        write_p += len2;
        FS_Seek(input, rights->offset + read_p, FS_FILE_BEGIN);
    }
    rights->data_len = write_p;
    /* feed boundary */
    len = drm_get_line(line, DRM_MAX_LINE_LENGTH - 3, input);
    if (len >= FS_NO_ERROR)
    {
        line[len++] = 0x0d;
        line[len++] = 0x0a;
        line[len] = 0;
        FS_Write(output, line, len, &len2);
    }
    FS_Truncate(input);
    FS_Seek(input, rights->offset, FS_FILE_BEGIN);
    free_ctrl_buffer(line);
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_tag
 * DESCRIPTION
 *  read a line (ended with >) from file
 * PARAMETERS
 *  strOutput       [IN]        
 *  length          [IN]        
 *  fh              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static drm_proc_enum drm_parse_tag(kal_char *strOutput, kal_uint32 length, FS_HANDLE fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char str[2];
    kal_char *currCursor;
    kal_uint32 strLen = 0;
    kal_uint32 nBytes = 0;
    kal_int32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(str, "%c", '>');

    memset(strOutput, 0, length);

    result = FS_Read(fh, strOutput, length - 1, &nBytes);
    if (result >= FS_NO_ERROR)
    {
        if (nBytes == 0)
            /* EOF */
        {
            return DRM_RESULT_EOF;
        }
    }
    else
    {
        return result;
    }

    if ((currCursor = strstr(strOutput, str)) != NULL)  /* find out first CRLF */
    {
        strLen = (int)(currCursor - strOutput) + 1;
        strOutput[strLen] = 0;

        FS_Seek(fh, (strLen - nBytes), FS_FILE_CURRENT);
        nBytes = strLen;
    }
    else    /* CRLF not found, read until CRLF */
    {
        strOutput[nBytes] = 0;
    }

    return nBytes;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_wb_tag
 * DESCRIPTION
 *  read a line (ended with >) from file
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static kal_int32 drm_parse_wb_tag(kal_uint8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = wb_rights.offset;

    while (i < wb_rights.len)
    {
        kal_uint8 U8;

        U8 = wb_rights.data[i] & 0x3f;
        if ((type == DRM_WB_TAG_START &&
             U8 >= DRM_WB_RIGHTS_TAG && U8 <= DRM_WB_INTERVAL_TAG) || (type == DRM_WB_TAG_END && U8 == 0x01))
        {
            wb_rights.offset = i + 1;
            return FS_NO_ERROR;
        }
        i++;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_buffer_line
 * DESCRIPTION
 *  read a line (ended with CRLF) from buffer
 * PARAMETERS
 *  strOutput       [IN]        
 *  length          [IN]        
 *  fh              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 drm_parse_buffer_line(kal_char *strOutput, kal_uint32 length, kal_uint8 **fh)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *fh_p;
    kal_char strCRLF[4];
    kal_char *currCursor;
    kal_uint32 strLen = 0;
    kal_uint32 nBytes = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    fh_p = *fh;
    sprintf(strCRLF, "%c%c", 0x0d, 0x0a);
    memset(strOutput, 0, length);

    /* result = FS_Read(fh, strOutput, length - 1, &nBytes); */
    nBytes = length - 1;
    memcpy(strOutput, fh_p, nBytes);
    fh_p += nBytes;

    if ((currCursor = strstr(strOutput, strCRLF)) != NULL)  /* find out first CRLF */
    {
        strLen = (int)(currCursor - strOutput);
        strOutput[strLen] = 0;

        /* FS_Seek(fh, (strLen - nBytes + 2), FS_FILE_CURRENT); */
        *fh = fh_p + (strLen - nBytes + 2);
        nBytes = strLen;
    }
    else    /* CRLF not found, read until CRLF */
    {
        strOutput[nBytes] = 0;
    }

    return nBytes;
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_buffer_dcf
 * DESCRIPTION
 *  parse separate delivery content
 * PARAMETERS
 *  input       [IN]        
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
drm_proc_enum drm_parse_buffer_dcf(kal_uint8 *input, drm_info_struct *info)
{
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

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return DRM_RESULT_OK;

}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_hash
 * DESCRIPTION
 *  seed/time -> hash -> value
 * PARAMETERS
 *  seed                [IN]        
 *  seed_len            [IN]        
 *  value_str           [OUT]       
 *  value_in_wchar      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_parse_hash(kal_uint8 *seed, kal_int32 seed_len, kal_char *value_str, kal_bool value_in_wchar)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 index = 0;
    kal_wchar int_str[sizeof("4294967295") + 1];
    kal_uint8 *hash_output;
    kal_char *align4str;
    STCHE *hash_cntx;
    kal_uint32 str_len = strlen((char*)seed);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str_len < (kal_uint32)seed_len)
    {
        align4str = (kal_char*) get_ctrl_buffer(seed_len);
    }
    else
    {
        align4str = (kal_char*) get_ctrl_buffer(str_len);
    }

    hash_output = (kal_uint8*) get_ctrl_buffer(16);

    strncpy(align4str, (kal_char*) seed, str_len);

    hash_cntx = (STCHE*) drmt_mem_alloc(sizeof(STCHE));

    ASSERT(((kal_int32) hash_cntx & 0x03) == 0);

    che_init(hash_cntx,CHE_MD5);

    che_process(hash_cntx, CHE_MD5, CHE_MODE_NULL, CHE_HASH, (kal_uint8*) align4str, hash_output, str_len, KAL_TRUE);

    che_deinit(hash_cntx);
    while (index <= 16)
    {
        if (value_in_wchar)
        {
            kal_wsprintf((kal_wchar*) int_str, "%u\0", hash_output[index]);
            kal_wstrcat((kal_wchar*) value_str, (kal_wchar*) int_str);
        }
        else
        {
            kal_sprintf((kal_char*) int_str, "%u\0", hash_output[index]);
            strcat((kal_char*) value_str, (kal_char*) int_str);
        }
        index++;
    }

    free_ctrl_buffer(align4str);
    free_ctrl_buffer(hash_output);

    drmt_mem_free(hash_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  drm_parse_dcf_header_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  meta_id                 [IN]        
 *  info                    [IN]        
 *  header                  [IN]        
 *  total_header_size       [IN]        
 * RETURNS
 *  KAL_TRUE: Valid Header
 *  KAL_FALSE: Invalid Header
 *****************************************************************************/
static kal_bool drm_parse_dcf_header_field(
                    drm_meta_enum meta_id,
                    drm_info_struct *info,
                    kal_char *header,
                    kal_uint32 total_header_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0, max_value_len = 0, current_header_len = 0, current_value_len = 0;
    kal_char *ptr = NULL;
    kal_char header_temp[DRM_MAX_ID_LENGTH + 1 + 2] = {0};   /* for oxod and 0x0a */
    kal_bool result = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (meta_id)
    {
        case DRM_META_RIGHTS_ISSUER:
        {
            ptr = "Rights-Issuer:";
            max_value_len = DRM_MAX_CID_URL_LENGTH;
            break;
        }
        case DRM_META_CONTENT_LOCATION:
        {
            ptr = "Content-Location:";
            max_value_len = DRM_MAX_CID_URL_LENGTH;
            break;
        }
        case DRM_META_CONTENT_NAME:
        {
            ptr = "Content-Name:";
            max_value_len = DRM_MAX_ID_LENGTH;
            break;
        }
        case DRM_META_CONTENT_DESCRIPTION:
        {
            ptr = "Content-Description:";
            max_value_len = DRM_MAX_LINE_LENGTH;
            break;
        }
        case DRM_META_CONTENT_VENDOR:
        {
            ptr = "Content-Vendor:";
            max_value_len = DRM_MAX_ID_LENGTH;
            break;
        }
        case DRM_META_ICON_URI:
        {
            ptr = "Icon-URI:";
            max_value_len = DRM_MAX_CID_URL_LENGTH;
            break;
        }
        case DRM_META_CONTENTURI:
        default:
        {
            ASSERT(0);
        }
    }

    current_header_len = strlen(ptr);

    /*
     * xxx:yyy 
     * * ^
     */	
    header = strstr(header, ptr);	
	if (header)
    {
        /*
         * xxx:yyy 
         * *     ^
         */
        header += current_header_len;
        current_value_len = strlen(header);
        current_value_len = (current_value_len > max_value_len) ? max_value_len : current_value_len;
		strncpy(header_temp, header, current_value_len+2);

        while (i < current_value_len && i < ((kal_int32)total_header_size - current_header_len))
        {
            if (header_temp[i] == '\r' || header_temp[i] == '\n' || header_temp[i] == ';' || header_temp[i] == '\t')
            {
                header_temp[i] = 0;
                current_value_len = strlen(header_temp);
                result = KAL_TRUE;
                break;
            }
            i++;
        }

        if (result)
        {
            ptr = drm_parse_skip_space(header_temp);
            if (ptr)
            {
                if (info->meta[meta_id] == NULL)
                    info->meta[meta_id] = (kal_char*) drmt_mem_alloc(current_value_len + 1);

                strncpy(info->meta[meta_id], ptr, current_value_len);
                (info->meta[meta_id])[current_value_len] = '\0';
            }
        }
    }

    if (result == KAL_FALSE)
    {
        info->meta[meta_id] = NULL;
    }
	
	return result;

}


/*****************************************************************************
 * FUNCTION
 *  drm_core_encode_dcf
 * DESCRIPTION
 *  encode forward lock and combined delivery content into DCF format
 * PARAMETERS
 *  input           [IN]        
 *  info            [IN]        
 *  append          [IN]        
 *  offset          [IN]        
 *  encoding        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
drm_proc_enum drm_core_encode_dcf(
                FS_HANDLE input,
                drm_info_struct *info,
                kal_uint8 append,
                kal_uint32 offset,
                kal_uint8 encoding)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE object;
    kal_char *buffer = NULL;
    kal_char *ptr;
    kal_uint32 size = 0, header_len;
    kal_uint32 length = 0, cid_offset;
    kal_int32 result;
    drm_rights_struct *rights = info->rights;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer = (kal_char*) get_ctrl_buffer(512);
    ASSERT(buffer);

    if (append == KAL_FALSE)
    {
        object = FS_OpenHint(info->content_path, FS_READ_ONLY, DRM_get_open_hint(info->content_path));
        if (object >= FS_NO_ERROR)
        {
            FS_Close(object);
            free_ctrl_buffer(buffer);
            return DRM_RESULT_FILE_EXISTS;
        }
        object = FS_Open(info->content_path, FS_READ_WRITE | FS_CREATE_ALWAYS);
    }
    else
    {
        object = FS_OpenHint(info->content_path, FS_READ_WRITE, DRM_get_open_hint(info->content_path));
        if (object == FS_FILE_NOT_FOUND)
        {
            object = FS_OpenHint(
                        info->content_path,
                        FS_READ_WRITE | FS_CREATE_ALWAYS,
                        DRM_get_open_hint(info->content_path));
        }

        if (object >= FS_NO_ERROR)
        {
            FS_Seek(object, offset, FS_FILE_BEGIN);
        }
    }

    if (object < FS_NO_ERROR)
    {
        free_ctrl_buffer(buffer);
        return DRM_RESULT_FS_ERROR;
    }

    memset(buffer, 0, sizeof(buffer));

    buffer[0] = 1;
    ptr = (char*)int_to_mime(rights->mime_type);
	size += 3;
    if (!ptr)
    {
        buffer[1] = 0;
    }
    else
    {
        buffer[1] = strlen(ptr);
		strncpy(&buffer[size], ptr, (kal_uint8) buffer[1]);
    }    
    
    size += buffer[1];
    
    if (rights->method == DRM_METHOD_FORWARD_LOCK)
    {
        buffer[2] = strlen(info->meta[DRM_META_CONTENTURI]) + DRM_FL_SIGNATURE_LEN;        
    }
    else
    {
        buffer[2] = strlen(info->meta[DRM_META_CONTENTURI]);        
    }
    strncpy(&buffer[size], info->meta[DRM_META_CONTENTURI], (kal_uint8) buffer[2]);
    size += buffer[2];
    FS_Write(object, buffer, size, &length);

    /* header */
    memset(buffer, 0, sizeof(buffer));
    if (rights->method == DRM_METHOD_FORWARD_LOCK)
    {
        sprintf(
            &buffer[2],
            DRM_DCF_FL_FIXED_HEADER,
            rights->data_len);
    }
    else
    {
        sprintf(&buffer[2], DRM_DCF_CD_FIXED_HEADER);
    }
    header_len = strlen(&buffer[2]);
    buffer[0] = header_len;
    /* skip data len for MTK proprietary dcf */
    FS_Write(object, buffer, header_len + 2, &length);
    size += 2;
    size += header_len;

    /* data : encrypt from input file offset */
    memset(buffer, 0, sizeof(buffer));
    FS_Seek(input, rights->offset, FS_FILE_BEGIN);

    if (encoding == DRM_ENCODING_BASE64)
    {
        FS_GetFilePosition(object, &header_len);
        drm_parse_base64(input, object, rights, header_len + 16);

        input = object;

        if (rights->method == DRM_METHOD_FORWARD_LOCK) /* Update FL data lenth*/
        {            
            sprintf(
                &buffer[2],
                DRM_DCF_FL_FIXED_HEADER,
                rights->data_len);

            buffer[0] = strlen(&buffer[2]);

            length = size - DRM_DCF_FL_FIXED_HEADER_SIZE; /* the offset of DRM header*/
            FS_Seek(input, offset + length, FS_FILE_BEGIN);
            FS_Write(object, buffer, DRM_DCF_FL_FIXED_HEADER_SIZE, &length);
        }
        
        FS_Seek(object, header_len, FS_FILE_BEGIN);
    }    
    
    /* new offset of encoded dcf */
    rights->offset = size;

    result = drm_core_encrypt(rights->key, object, input, rights->data_len);

    FS_GetFileSize(object, &size);
    DRM_MTK_TRACE(("encrypt size = %d"), (TRACE_INFO, DRM_MTK_PARSER_ENC, size));

    if (rights->method == DRM_METHOD_FORWARD_LOCK)
    {
        if (ptr)
        {
            cid_offset = offset + 3 + strlen(ptr) + 11;
        }
        else
        {
            cid_offset = offset + 3 + 0 + 11;
        }
        drm_core_gen_fl_signature(&info->meta[DRM_META_CONTENTURI][11], object, rights->data_len, offset + rights->offset);

        FS_Seek(object, cid_offset, FS_FILE_BEGIN);
        FS_Write(object, &info->meta[DRM_META_CONTENTURI][11], DRM_FL_SIGNATURE_LEN, &length);
    }    

    FS_Close(object);
    free_ctrl_buffer(buffer);
    if (result == FS_NO_ERROR)
    {
        return DRM_RESULT_OK;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_is_dcf_format
 * DESCRIPTION
 *  check if a file is of DCF format
 * PARAMETERS
 *  input               [IN]        
 *  info                [IN]        
 *  file_size(?)        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drm_core_is_dcf_format(FS_HANDLE input, drm_info_struct *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 size1, size2, len = 0, total = 0;
    kal_int32 bytes_scaned = 0;
    kal_uint8 *buffer = NULL, *encrypt_buff;
    kal_bool fl_or_cd = KAL_FALSE, valid_ri = KAL_FALSE;
    kal_uint32 sd_pos;
    drm_rights_struct *rights = info->rights;
    kal_uint8 key[DRM_MAX_KEY_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer = (kal_uint8*) drmt_mem_alloc(DRM_MAX_LINE_LENGTH);
    memset(buffer, 0, DRM_MAX_LINE_LENGTH);

    FS_GetFilePosition(input, &sd_pos);
    FS_Read(input, buffer, 3, &len);
    /* DCF: version */
    if (buffer[0] == 0x01)
    {
        total += len;
        total += buffer[1];
        total += buffer[2];

        /* DCF: ContentTypeLen */
        size1 = buffer[1];
        /* DCF: ContentURILen */
        size2 = buffer[2];

        /* read mime type */
        memset(buffer, 0, DRM_MAX_LINE_LENGTH);

        /* unsupported content type */
        if (size1 > DRM_MAX_LINE_LENGTH)
        {
            drmt_mem_free(buffer);
            return KAL_FALSE;
        }

        if (size2 > DRM_MAX_CID_URL_LENGTH)
        {
            drmt_mem_free(buffer);
            return KAL_FALSE;
        }

        /* DCF: ContentType */
        FS_Read(input, buffer, size1, &len);
        {
            kal_int32 mime;

            mime = mime_to_int((char*)buffer);
            rights->mime_type = (mime == -1) ? 0xff : mime;
            if (rights->mime_type == -1)
            {
                drmt_mem_free(buffer);
                return KAL_FALSE;
            }
        }

        if (info->content_path)
        {
            /* get new file extension name according to mime type */
            drm_replace_file_extension(info->content_path, rights->mime_type);
        }
        else
        {
            ;   /* just for DRM_validate_dcf */
        }

        /* DCF: ContentURI */
        info->meta[DRM_META_CONTENTURI] = (kal_char*) drmt_mem_alloc(size2 + 1);
        FS_Read(input, info->meta[DRM_META_CONTENTURI], size2, &len);
        (info->meta[DRM_META_CONTENTURI])[len] = 0;

        if (strncmp(info->meta[DRM_META_CONTENTURI] + 7, "cid", 3) == 0)
        {
            /* forward lock or combined delivery */
            fl_or_cd = KAL_TRUE;
            if (strncmp(info->meta[DRM_META_CONTENTURI], "MTK_FL_cid", 10) == 0)
            {
                rights->method = DRM_METHOD_FORWARD_LOCK;
                rights->status = DRM_STATUS_NO_RIGHTS;
            }
            else if (strncmp(info->meta[DRM_META_CONTENTURI], "MTK_CD_cid", 10) == 0)
            {
                rights->method = DRM_METHOD_COMBINED_DELIVERY;
                rights->status = DRM_STATUS_NO_RIGHTS;
            }
            else
            {
                fl_or_cd = KAL_FALSE;
            }
        }
        else if (strncmp(info->meta[DRM_META_CONTENTURI], "MTK_FLDCF_cid", 13) == 0)
        {
            encrypt_buff = (kal_uint8*) drmt_mem_alloc(DRM_MAX_LINE_LENGTH);
            rights->method = DRM_METHOD_FORWARD_LOCK | DRM_METHOD_SEPARATE_DELIVERY;

            drm_core_get_key(key);

            memset(buffer, 0, DRM_MAX_LINE_LENGTH);
            memset(encrypt_buff, 0, DRM_MAX_LINE_LENGTH);
            memcpy(encrypt_buff, &(info->meta[DRM_META_CONTENTURI][14]), DRM_MAX_LINE_LENGTH - 14);
            /* the encrypted cid is after "MTK_FLDCF_cid:" */
            drm_core_rc4_decrypt_buff(key, 16, buffer, encrypt_buff, size2 - 14);

            memcpy(&(info->meta[DRM_META_CONTENTURI][14]), buffer, strlen((kal_char*) buffer));

            drm_parse_cid(&(info->meta[DRM_META_CONTENTURI][14]));
            drmt_mem_free(encrypt_buff);
        }
        else if (strncmp(info->meta[DRM_META_CONTENTURI], "cid", 3) == 0)
        {
            /* take as separate delivery */
            drm_parse_cid(info->meta[DRM_META_CONTENTURI]);
            rights->method |= DRM_METHOD_SEPARATE_DELIVERY;
            rights->status = DRM_STATUS_RIGHTS_PENDING;
        }
        else
        {
            /* not drm */
            drmt_mem_free(buffer);
            return KAL_FALSE;
        }

        /* read header length, data length */
        memset(buffer, 0, DRM_MAX_LINE_LENGTH);
        FS_Read(input, buffer, 10, &len);

        /* DCF: HeadersLen */
        /* size1 = header length */
        bytes_scaned = drm_parse_uintvar(buffer, &size1, len);
        if (size1 == 0)
        {
            /* RI Header is mandatory */
            drmt_mem_free(buffer);
            return KAL_FALSE;
        }

        /* length of HeadersLen */
        if (bytes_scaned > 0)
        {
            total += bytes_scaned;

            /* DCF: DataLen */
            /* size2 = data length */
            bytes_scaned = drm_parse_uintvar(&buffer[bytes_scaned], &size2, len - bytes_scaned);

            /* length of DataLen */
            if (bytes_scaned > 0)
            {
                kal_char *header, *ptr;

                total += bytes_scaned + sd_pos;

                /* header start */
                FS_Seek(input, total, FS_FILE_BEGIN);
                total += size1;
                rights->offset = total;
                total += size2;

                if (size1 && size1 < 2000)
                {
                    header = get_ctrl_buffer(size1);
                }
                else
                {
                    drmt_mem_free(buffer);
                    return KAL_FALSE;
                }

                memset(header, 0, size1);
                FS_Read(input, header, size1, &len);
                /* DCF: Encryption-Method Header */
                /* DCF: Encryption-method parameter */
                /* SKIP */
                /* DCF: padding-scheme parameter */
                /* SKIP */
                /* DCF: plaintest-length parameter */
                if (rights->method == DRM_METHOD_FORWARD_LOCK)
                {
                    if ((ptr = strstr(header, "plaintextlen=")) != NULL)
                    {
                        ptr += strlen("plaintextlen=");
                        rights->data_len = atoi(ptr);
                    }
                }

                /* DCF: Rights-Issuer Header */
                if (fl_or_cd == KAL_TRUE && size2 == 0)
                {
                    /* foward lock or combined delivery */
                    /* read header */
                    if ((ptr = strstr(header, "Right-Issuer:")) != NULL)
                    {
                        if (rights->method == DRM_METHOD_FORWARD_LOCK && strncmp(ptr, "Right-Issuer:[FL]", 17) != 0)
                        {
                            valid_ri = KAL_FALSE;
                        }
                        else if (rights->method == DRM_METHOD_COMBINED_DELIVERY &&
                                 strncmp(ptr, "Right-Issuer:[CD]", 17) != 0)
                        {
                            valid_ri = KAL_FALSE;
                        }
                    }
                    else
                    {
                        valid_ri = KAL_FALSE;
                    }
                    info->meta[DRM_META_RIGHTS_ISSUER] = NULL;
                }
                else
                {
                    if (!drm_parse_dcf_header_field(DRM_META_RIGHTS_ISSUER, info, header, len))
                    {
                        valid_ri = KAL_FALSE;
                    }
                }

                /* DCF: Content-Name Header */
                drm_parse_dcf_header_field(DRM_META_CONTENT_NAME, info, header, len);

                /* DCF: Content-Description Header */
                drm_parse_dcf_header_field(DRM_META_CONTENT_DESCRIPTION, info, header, len);

                /* DCF: Content-Vendor Header */
                drm_parse_dcf_header_field(DRM_META_CONTENT_VENDOR, info, header, len);

                /* DCF: Icon-URL Header */
                drm_parse_dcf_header_field(DRM_META_ICON_URI, info, header, len);

                free_ctrl_buffer(header);

                /* FS_GetFileSize(input, &file_size); */
                if (valid_ri == KAL_TRUE)
                {
                    drmt_mem_free(buffer);
                    return KAL_TRUE;
                }
                if (FS_Seek(input, total, FS_FILE_BEGIN) >= FS_NO_ERROR)
                {
                    FS_Truncate(input);
                    drmt_mem_free(buffer);
                    return KAL_TRUE;
                }
            }
        }
    }

    drmt_mem_free(buffer);
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_create_rights_object
 * DESCRIPTION
 *  write rights object to file
 * PARAMETERS
 *  ro                  [IN]        
 *  rights              [IN]        
 *  content_path        [IN]        
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 drm_core_create_rights_object(FS_HANDLE ro, drm_rights_struct *rights, kal_wchar *content_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *buffer;
    kal_uint8 key[DRM_MAX_KEY_LENGTH];
    FS_FileInfo *file_info;
    kal_wchar *ro_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ro >= FS_NO_ERROR)
    {
        kal_uint32 len;
        kal_int32 ro_ret = FS_NO_ERROR;

        if (content_path)
        {
            FS_Seek(ro, 0, FS_FILE_BEGIN);
            ro_ret = FS_Write(ro, content_path, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH, &len);
        }
        else
        {
            ro_ret = FS_Seek(ro, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH, FS_FILE_BEGIN);
        }

        if (rights)
        {
            kal_uint32 i;

            if (rights->method & DRM_METHOD_SEPARATE_DELIVERY && rights->method & DRM_METHOD_FORWARD_LOCK)
            {
                rights->data_len = 0;
            }

            /* Encrypt ro */
            buffer = drmt_mem_alloc(DRM_RIGHTS_SIZE);
            memset(buffer, 0, DRM_RIGHTS_SIZE);
            drm_core_get_key(key);
            drm_core_rc4_encrypt_buff(key, 16, buffer, (kal_uint8*) rights, sizeof(drm_rights_struct));

            ro_ret = FS_Write(ro, buffer, sizeof(drm_rights_struct), &len);
            /* constraint list */
            for (i = DRM_CONSTRAINT_PLAY_INDEX; i < DRM_CONSTRAINT_TOTAL_INDEX; i++)
            {
                if (rights->num[i] > 0)
                {
                    rights->constraint_list[rights->best[i]].status = KAL_TRUE;
                    drm_core_update_constraint(ro, rights, (kal_uint8)(1 << i));
                }
            }
            drmt_mem_free(buffer);
            if (ro_ret == FS_APP_QUOTA_FULL)
            {
                file_info = drmt_mem_alloc(sizeof(FS_FileInfo));
                ro_path = drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);

                FS_GetFileInfo(ro, file_info);
                app_ucs2_strcpy((kal_int8*) ro_path, (kal_int8*) file_info->FullName);
                FS_Close(ro);
                FS_Delete((kal_wchar*) ro_path);
                ro_ret = DRM_RESULT_NO_RIGHTS_SPACE;

                drmt_mem_free(file_info);
                drmt_mem_free(ro_path);
            }
            else
            {
                if (rights->status == DRM_STATUS_RIGHTS_PENDING ||
                    rights->status == DRM_STATUS_RIGHTS_IN_FUTURE ||
                    rights->status == DRM_STATUS_CONTENT_PENDING)
                {
                    /* notice the modification of ro database */
                    drm_core_update_ro_db();
                }
            }
        }
        return ro_ret;
    }
    return ro;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_update_constraint
 * DESCRIPTION
 *  write constraint into file
 * PARAMETERS
 *  ro              [IN]        
 *  rights          [IN]        
 *  permission      [IN]        
 * RETURNS
 *  kal_int32(?)
 *****************************************************************************/
void drm_core_update_constraint(FS_HANDLE ro, drm_rights_struct *rights, kal_uint8 permission)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 *buffer;
    kal_uint8 key[DRM_MAX_KEY_LENGTH];
    kal_uint32 len;
    kal_uint8 best_cons = 0;
    drm_constraint_entry_struct* cons_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (permission)
    {
        case DRM_PERMISSION_ALL:
        {
            best_cons = 0;
            return;
        }
        case DRM_PERMISSION_PLAY:
        {
            best_cons = rights->best[DRM_CONSTRAINT_PLAY_INDEX];
            break;
        }
        case DRM_PERMISSION_DISPLAY:
        {
            best_cons = rights->best[DRM_CONSTRAINT_DISPLAY_INDEX];
            break;
        }
        case DRM_PERMISSION_EXECUTE:
        {
            best_cons = rights->best[DRM_CONSTRAINT_EXECUTE_INDEX];
            break;
        }
        case DRM_PERMISSION_PRINT:
        {
            best_cons = rights->best[DRM_CONSTRAINT_PRINT_INDEX];
            break;
        }
    }

    cons_entry = &rights->constraint_list[best_cons];
    while (drm_core_is_constraint_valid(&(cons_entry->cons), KAL_FALSE) == DRM_STATUS_RIGHTS_IN_FUTURE)
    {
        if (cons_entry->next != 0xFF)
        {
            best_cons = cons_entry->next;
            cons_entry = &rights->constraint_list[cons_entry->next];
        }
        else
        {
            cons_entry = NULL;
            break;
        }        
    }

    buffer = drmt_mem_alloc(DRM_CONSTRAINT_ENTRY_SIZE);
    memset(buffer, 0, DRM_CONSTRAINT_ENTRY_SIZE);
    drm_core_get_key(key);

    FS_Seek(
        ro,
        DRM_MAX_PATH_LENGTH * ENCODING_LENGTH + DRM_RIGHTS_SIZE + (best_cons * DRM_CONSTRAINT_ENTRY_SIZE),
        FS_FILE_BEGIN);
    drm_core_rc4_encrypt_buff(
        key,
        16,
        buffer,
        (kal_uint8*) & rights->constraint_list[best_cons],
        DRM_CONSTRAINT_ENTRY_SIZE);
    FS_Write(ro, buffer, DRM_CONSTRAINT_ENTRY_SIZE, &len);

    drmt_mem_free(buffer);

}


/*****************************************************************************
 * FUNCTION
 *  drm_core_open_rights_object
 * DESCRIPTION
 *  open rights object of a DRM content
 * PARAMETERS
 *  flags       [IN]        
 *  cid         [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
FS_HANDLE drm_core_open_rights_object(kal_uint32 flags, kal_char *cid, kal_bool hide)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_wchar *ro_path;
    FS_HANDLE ro;
    kal_uint8 i;
    kal_uint32 ro_size;
    kal_char *cid_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ro_path = get_ctrl_buffer(DRM_MAX_PATH_LENGTH << 1);
    if (ro_path == NULL)
    {
        return FS_ERROR_RESERVED;
    }

    memset(ro_path, 0, DRM_MAX_PATH_LENGTH << 1);
    app_ucs2_strcpy((kal_int8*) ro_path, (kal_int8*) DRM_RO_PATH);

    if (strncmp(cid, "MTK_FL_cid", 10) == 0 || strncmp(cid, "MTK_CD_cid", 10) == 0)
    {
        cid_ptr = & cid[11];
    }
    else if (strncmp(cid, "MTK_FLDCF_cid", 10) == 0)
    {
        cid_ptr = & cid[14];
    }
    else
    {
        cid_ptr = & cid[4];
    }
    if (strlen(cid_ptr) == 0)
    {
        free_ctrl_buffer(ro_path);
        DRM_MTK_TRACE(("Empty CID"), (TRACE_INFO, DRM_MTK_PARSER_CID));
        return DRM_RESULT_INVALID_FORMAT;
    }
    drm_parse_hash((kal_uint8*) cid_ptr, 0, (kal_char*) ro_path, KAL_TRUE);

    ro = FS_Open(ro_path, flags);

    if (ro >= FS_NO_ERROR)
    {
        /* Check rights size */
        FS_GetFileSize(ro, &ro_size);
        if (ro_size > (DRM_RIGHTS_SIZE + (DRM_MAX_PATH_LENGTH * ENCODING_LENGTH)) &&
            ((ro_size - DRM_RIGHTS_SIZE - (DRM_MAX_PATH_LENGTH * ENCODING_LENGTH)) % DRM_CONSTRAINT_ENTRY_SIZE) != 0)
        {
            FS_Close(ro);
            FS_Delete(ro_path);
            free_ctrl_buffer(ro_path);
            return FS_FILE_NOT_FOUND;
        }
    }

    if (ro == FS_ACCESS_DENIED)
    {
        /* right already opened as read write, return the opened one */
        for (i = 0; i < DRM_MAX_FILE_HANDLE; i++)
        {
            if (g_drm_handles[i].ro > 0)
            {
                FS_FileInfo file_info;

                FS_Seek(g_drm_handles[i].ro, 0, FS_FILE_BEGIN);
                FS_GetFileInfo(g_drm_handles[i].ro, &file_info);
                if (app_ucs2_strcmp((kal_int8*) (&ro_path[1]), (kal_int8*) & file_info.FullName[2]) == 0)
                {
                    free_ctrl_buffer(ro_path);
                    return g_drm_handles[i].ro;
                }
            }
        }
    }
	if(hide)
	{
		kal_int32 attr = FS_GetAttributes((const WCHAR*)ro_path);
        FS_SetAttributes((const WCHAR*)ro_path, (kal_uint8) (attr | FS_ATTR_HIDDEN));                
    }
    free_ctrl_buffer(ro_path);
    return ro;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_load_rights_ro
 * DESCRIPTION
 *  load rights object from FS and compare with newly parsed rights object
 * PARAMETERS
 *  ro          [IN]        
 *  rights      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drm_core_load_rights_ro(FS_HANDLE ro, drm_rights_struct *rights)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    drm_rights_struct old_rights;
    kal_uint32 len;
    kal_uint8 *buffer;
    kal_uint8 key[DRM_MAX_KEY_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer = (kal_uint8*) drmt_mem_alloc(sizeof(drm_rights_struct));

    FS_Seek(ro, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH, FS_FILE_BEGIN);
    FS_Read(ro, buffer, sizeof(drm_rights_struct), &len);

    /* Decrypt RO */
    drm_core_get_key(key);
    drm_core_rc4_decrypt_buff(key, 16, (kal_uint8*) & old_rights, buffer, len);
    drmt_mem_free(buffer);

    /* rights arrival, keep old content offset, mimetype,
       content length, rights issuer, merge rights */

    DRM_MTK_TRACE(("[SD] RO best[N]"), (TRACE_INFO, DRM_MTK_LOAD_RO_BEST, old_rights.best[0], old_rights.best[1], old_rights.best[2], old_rights.best[3]));
    DRM_MTK_TRACE(("[SD] RO num[N]"), (TRACE_INFO, DRM_MTK_LOAD_RO_NUM, old_rights.num[0], old_rights.num[1], old_rights.num[2], old_rights.num[3]));

    drm_core_update_multiro_rights(ro, rights, &old_rights);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_load_rights_dcf
 * DESCRIPTION
 *  load rights object from FS and compare with newly parsed rights object
 *  receive DCF, check if previous RO present
 * PARAMETERS
 *  ro          [IN]        
 *  rights      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool drm_core_load_rights_dcf(FS_HANDLE ro, drm_rights_struct *rights)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_FileInfo *file_info;
    kal_wchar *ro_path;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rights->method == DRM_METHOD_FORWARD_LOCK)
    {
        rights->permission = DRM_PERMISSION_ALL;

        rights->status = DRM_STATUS_RIGHTS_PRESENT;

        drm_core_get_key(rights->key);
        rights->key_len = 16;
        return KAL_TRUE;
    }
    else if (ro >= FS_NO_ERROR)
    {
        kal_uint32 len;
        kal_uint8 *buffer;
        kal_uint8 key[DRM_MAX_KEY_LENGTH];
        drm_constraint_entry_struct *appending = NULL;
        kal_uint8 j, cons_num;

        drm_rights_struct old_rights;

        buffer = (kal_uint8*) drmt_mem_alloc(sizeof(drm_rights_struct));

        FS_Seek(ro, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH, FS_FILE_BEGIN);
        FS_Read(ro, buffer, sizeof(drm_rights_struct), &len);
        /* Decrypt RO */
        drm_core_get_key(key);
        drm_core_rc4_decrypt_buff(key, 16, (kal_uint8*) & old_rights, buffer, len);

        if (old_rights.key_len && old_rights.key_len != 16)
        {
            drmt_mem_free(buffer);
            FS_Close(ro);
            return KAL_FALSE;
        }

        if (rights->status == DRM_STATUS_RIGHTS_PENDING)
        {
            /* content arrival, use old key, key length, permission, constraint */
            rights->key_len = old_rights.key_len;
            rights->permission = old_rights.permission;
            if (old_rights.method == DRM_METHOD_FORWARD_LOCK || old_rights.method == DRM_METHOD_COMBINED_DELIVERY)
            {
                rights->method = old_rights.method;
            }
            else /* FL + SD */
            {
                rights->method |= old_rights.method;
            }

            if (!rights->data_len && old_rights.data_len)
                rights->data_len = old_rights.data_len;

            memcpy(rights->key, old_rights.key, sizeof(old_rights.key));

            memcpy(&(rights->num), &(old_rights.num), DRM_CONSTRAINT_TOTAL_INDEX);
            memcpy(&(rights->best), &(old_rights.best), DRM_CONSTRAINT_TOTAL_INDEX);

            if (old_rights.status == DRM_STATUS_CONTENT_PENDING || old_rights.status == DRM_STATUS_RIGHTS_PRESENT)
            {
                /* rights present, wait for content or
                   content + rights present, content comes again */
                rights->status = DRM_STATUS_RIGHTS_PRESENT;
            }
        }
        else    /* open content CD or FL, use old stuff */
        {
            if (old_rights.offset == 0)
            {
                rights->status = DRM_STATUS_RIGHTS_PENDING;
                return KAL_TRUE;
            }
            memcpy(rights, &old_rights, sizeof(drm_rights_struct));
        }

        /* calculate constraint number */
        FS_GetFileSize(ro, &len);
        cons_num = (len - DRM_RIGHTS_SIZE - (DRM_MAX_PATH_LENGTH * ENCODING_LENGTH)) / DRM_CONSTRAINT_ENTRY_SIZE;

        appending = rights->constraint_list =
            (drm_constraint_entry_struct*) drmt_mem_alloc(cons_num * DRM_CONSTRAINT_ENTRY_SIZE);
        /* FS_Seek(ro, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH + DRM_RIGHTS_SIZE, FS_FILE_BEGIN); */
        for (j = 0; j < cons_num; j++)
        {
            FS_Read(ro, buffer, DRM_CONSTRAINT_ENTRY_SIZE, &len);
            drm_core_rc4_decrypt_buff(key, 16, (kal_uint8*) appending, buffer, DRM_CONSTRAINT_ENTRY_SIZE);

           /* Check constraint */
            if (appending->status != KAL_TRUE)
            {
                file_info = drmt_mem_alloc(sizeof(FS_FileInfo));
                ro_path = drmt_mem_alloc(DRM_MAX_CID_URL_LENGTH);

                FS_GetFileInfo(ro, file_info);
                app_ucs2_strcpy((kal_int8*) ro_path, (kal_int8*) file_info->FullName);
                FS_Close(ro);
                FS_Delete((kal_wchar*) ro_path);

                return KAL_FALSE;    
            }
            appending++;
        }
        drmt_mem_free(buffer);

        /* cid present => rights already there */
        DRM_MTK_TRACE(("SD w/ rights"), (TRACE_INFO, DRM_MTK_OBJ_SD_02));
        return KAL_TRUE;
    }
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_update_multiro_rights
 * DESCRIPTION
 *  update rights object when receives new rights object from network
 * PARAMETERS
 *  ro              [IN]        
 *  rights          [IN]        
 *  old_rights      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void drm_core_update_multiro_rights(FS_HANDLE ro, drm_rights_struct *rights, drm_rights_struct *old_rights)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    drm_constraint_struct *old_constraints = NULL;  /* = &old_rights->play; */
    drm_constraint_struct *new_constraints = NULL;  /* = &rights->play; */
    kal_uint8 i, j = 0, prev_cons, next_cons, is_merge, cons_index;
    kal_uint32 size = 0, total_cons;
    kal_int32 new_cons;
    kal_uint8 *buffer;
    kal_uint8 key[DRM_MAX_KEY_LENGTH];
    drm_constraint_entry_struct *appending = NULL;

    old_rights->permission |= rights->permission;

    for (i = DRM_PERMISSION_NONE; (1 << i) <= DRM_PERMISSION_PRINT; i++)
    {
        /* calculate constraint number */
        FS_GetFileSize(ro, &total_cons);
        total_cons = (total_cons - DRM_MAX_PATH_LENGTH * ENCODING_LENGTH - DRM_RIGHTS_SIZE) / DRM_CONSTRAINT_ENTRY_SIZE;

        DRM_MTK_TRACE(("Multi RO permission = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_PERMISSION, i));
        if (old_rights->best[i] == 0xFF)
        {
            old_rights->num[i] = 0;
        }
        if (old_rights->num[i] != 0 && rights->num[i] != 0)
        {
            new_cons = -1;
            old_constraints = &(old_rights->constraint_list[old_rights->best[i]].cons);
            new_constraints = &(rights->constraint_list[rights->best[i]].cons);
            DRM_MTK_TRACE(("Multi RO new constraint type = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_NEW_CONS_TYPE, new_constraints->type));

            appending = old_rights->constraint_list =
                (drm_constraint_entry_struct*) drmt_mem_alloc((total_cons + 1) * DRM_CONSTRAINT_ENTRY_SIZE);
            ASSERT(appending);

            buffer = (kal_uint8*) drmt_mem_alloc(DRM_CONSTRAINT_ENTRY_SIZE);

            /* Decrypt constraint */
            drm_core_get_key(key);
            cons_index = old_rights->best[i];
            while(cons_index != 0xFF)
            {
                FS_Seek(
                    ro,
                    DRM_MAX_PATH_LENGTH * ENCODING_LENGTH + DRM_RIGHTS_SIZE + (cons_index * DRM_CONSTRAINT_ENTRY_SIZE),
                    FS_FILE_BEGIN);
                FS_Read(ro, buffer, DRM_CONSTRAINT_ENTRY_SIZE, &size);
                appending = old_rights->constraint_list + cons_index;
                drm_core_rc4_decrypt_buff(key, 16, (kal_uint8*) appending, buffer, DRM_CONSTRAINT_ENTRY_SIZE);
                DRM_MTK_TRACE(("Multi RO constraint index = %d, type = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_CONS, cons_index, appending->cons.type));
                /* Select a invalid constraint to insert */
                if (appending->status == KAL_FALSE && new_cons < 0)
                {
                    new_cons = j;
                }
                cons_index = appending->next;
                j++;
            }
            appending = old_rights->constraint_list;

            /* all the constraint are valid, insert into new entry */
            if (new_cons < 0)
            {
                new_cons = total_cons;
            }

            drmt_mem_free(buffer);

            is_merge = drm_core_insert_multiro_constraint(new_constraints, old_rights, i, &prev_cons, &next_cons);
            DRM_MTK_TRACE(("Multi RO insert prev_cons = %d, next_cons = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_INSERT_RESULT, prev_cons, next_cons));

            /* adjust new constraint index for <count> constraint */
            /* overwirte old count */
            if (prev_cons != 0xFF && new_constraints->type == DRM_CONSTRAINT_COUNT) /* previous constraint is not count one */
            {
                total_cons = appending[prev_cons].next; /* index of old count constraint */
                if (appending[total_cons].cons.type == DRM_CONSTRAINT_COUNT)
                {
                    new_cons = total_cons;
                }
            }

            if (appending[prev_cons].cons.type == DRM_CONSTRAINT_COUNT && new_constraints->type == DRM_CONSTRAINT_COUNT && prev_cons != 0xFF)
            {
                new_cons = prev_cons;
            }
            DRM_MTK_TRACE(("Multi RO new constraint pos = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_NEW_CONS_POS, new_cons));

            if (is_merge)   /* update ro list */
            {
                appending[new_cons].status = KAL_TRUE;

                buffer = drmt_mem_alloc((DRM_RIGHTS_SIZE >
                                    DRM_CONSTRAINT_ENTRY_SIZE) ? DRM_RIGHTS_SIZE : DRM_CONSTRAINT_ENTRY_SIZE);

                if (prev_cons == 0xFF && next_cons == 0xFF) /* the coverage of the constraint include all */
                {
                    appending[new_cons].status = KAL_FALSE;
                    new_cons = old_rights->best[i];
                    appending[new_cons].next = 0xFF;
                    //old_rights->best[i] = new_cons;
                    old_rights->num[i]++;
                }
                else if (prev_cons == 0xFF) /* First one */
                {
                    appending[new_cons].next = next_cons;
                    old_rights->best[i] = new_cons;
                    old_rights->num[i]++;
                }
                else if (next_cons == 0xFF) /* Last one */
                {
                    appending[prev_cons].next = new_cons;
                    appending[new_cons].next = 0xFF;
                    old_rights->num[i]++;

                    /* Write previous constraint */
                    memset(buffer, 0, DRM_CONSTRAINT_ENTRY_SIZE);
                    drm_core_rc4_encrypt_buff(
                        key,
                        16,
                        buffer,
                        (kal_uint8*) & (appending[prev_cons]),
                        DRM_CONSTRAINT_ENTRY_SIZE);
                    FS_Seek(
                        ro,
                        DRM_MAX_PATH_LENGTH * ENCODING_LENGTH + DRM_RIGHTS_SIZE + (prev_cons * DRM_CONSTRAINT_ENTRY_SIZE),
                        FS_FILE_BEGIN);
                    FS_Write(ro, buffer, DRM_CONSTRAINT_ENTRY_SIZE, &size);
                }
                else
                {
                    if(prev_cons==next_cons)
					{
						appending[new_cons].next=appending[prev_cons].next;
						appending[prev_cons].next=new_cons;
					}
					else
					{
                    appending[prev_cons].next = new_cons;
                    appending[new_cons].next = next_cons;
					}
                    
                    old_rights->num[i]++;

                    /* Write previous constraint */
                    memset(buffer, 0, DRM_CONSTRAINT_ENTRY_SIZE);
                    drm_core_rc4_encrypt_buff(
                        key,
                        16,
                        buffer,
                        (kal_uint8*) & (appending[prev_cons]),
                        DRM_CONSTRAINT_ENTRY_SIZE);
                    FS_Seek(
                        ro,
                        DRM_MAX_PATH_LENGTH * ENCODING_LENGTH + DRM_RIGHTS_SIZE + (prev_cons * DRM_CONSTRAINT_ENTRY_SIZE),
                        FS_FILE_BEGIN);
                    FS_Write(ro, buffer, DRM_CONSTRAINT_ENTRY_SIZE, &size);
                }

                /* Write rights and last constraint */

                /* RO */
                memset(buffer, 0, DRM_RIGHTS_SIZE);
                drm_core_rc4_encrypt_buff(key, 16, buffer, (kal_uint8*) old_rights, DRM_RIGHTS_SIZE);
                FS_Seek(ro, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH, FS_FILE_BEGIN);
                FS_Write(ro, buffer, DRM_RIGHTS_SIZE, &size);

                /* Next constraint */
                memcpy(&(appending[new_cons].cons), new_constraints, DRM_CONSTRAINT_SIZE);
                memset(buffer, 0, DRM_CONSTRAINT_ENTRY_SIZE);
                drm_core_rc4_encrypt_buff(
                    key,
                    16,
                    buffer,
                    (kal_uint8*) & (appending[new_cons]),
                    DRM_CONSTRAINT_ENTRY_SIZE);
                FS_Seek(
                    ro,
                    DRM_MAX_PATH_LENGTH * ENCODING_LENGTH + DRM_RIGHTS_SIZE + (new_cons * DRM_CONSTRAINT_ENTRY_SIZE),
                    FS_FILE_BEGIN);
                FS_Write(ro, buffer, DRM_CONSTRAINT_ENTRY_SIZE, &size);

                drmt_mem_free(buffer);

            }
            else    /* not merge */
            {
            }
            drmt_mem_free(old_rights->constraint_list);
        }
        else
        {
            if (rights->num[i] != 0)    /* old rights are empty */
            {
                memcpy(old_rights->key, rights->key, rights->key_len);
                old_rights->key_len = rights->key_len;
                old_rights->data_len = rights->data_len;
                if (old_rights->status == DRM_STATUS_RIGHTS_PENDING || old_rights->status == DRM_STATUS_RIGHTS_PRESENT)
                {
                    /* rights pending => content present */
                    old_rights->status = DRM_STATUS_RIGHTS_PRESENT;
                }

                old_rights->best[i] = total_cons;
                old_rights->num[i]++;
                rights->constraint_list[rights->best[i]].next = 0xFF;
                rights->constraint_list[rights->best[i]].status = KAL_TRUE;
                DRM_MTK_TRACE(("Multi RO insert into empty list, best = %d, number = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_INSERT_NEW, old_rights->best[i], old_rights->num[i]));

                buffer = drmt_mem_alloc((DRM_RIGHTS_SIZE >
                                    DRM_CONSTRAINT_ENTRY_SIZE) ? DRM_RIGHTS_SIZE : DRM_CONSTRAINT_ENTRY_SIZE);
                drm_core_get_key(key);
                /* Encrypt ro */
                memset(buffer, 0, DRM_RIGHTS_SIZE);
                drm_core_rc4_encrypt_buff(key, 16, buffer, (kal_uint8*) old_rights, DRM_RIGHTS_SIZE);
                FS_Seek(ro, DRM_MAX_PATH_LENGTH * ENCODING_LENGTH, FS_FILE_BEGIN);
                FS_Write(ro, buffer, DRM_RIGHTS_SIZE, &size);

                /* Encrypt constraint */
                memset(buffer, 0, DRM_CONSTRAINT_ENTRY_SIZE);
                drm_core_rc4_encrypt_buff(
                    key,
                    16,
                    buffer,
                    (kal_uint8*) & (rights->constraint_list[rights->best[i]]),
                    DRM_CONSTRAINT_ENTRY_SIZE);
                FS_Seek(ro, 0, FS_FILE_END);
                FS_Write(ro, buffer, DRM_CONSTRAINT_ENTRY_SIZE, &size);

                drmt_mem_free(buffer);
            }
        }

    }

}


/*****************************************************************************
 * FUNCTION
 *  drm_core_is_trivail_constraint
 * DESCRIPTION
 *  Check if it is a trivial constraint
 * PARAMETERS
 *  constraints     [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool drm_core_is_trivail_constraint(drm_constraint_struct *constraints)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (constraints->type == DRM_CONSTRAINT_COUNT
        || constraints->type == DRM_CONSTRAINT_DATETIME
        || constraints->type == DRM_CONSTRAINT_INTERVAL || constraints->type == DRM_CONSTRAINT_NONE)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }

}


/*****************************************************************************
 * FUNCTION
 *  drm_core_insert_multiro_constraint
 * DESCRIPTION
 *  insert new constraint into ro
 * PARAMETERS
 *  new_cons            [?]         
 *  old_rights          [?]         
 *  permission          [IN]        
 *  perv_cons           [?]         
 *  next_cons           [?]         
 *  constraints(?)      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool drm_core_insert_multiro_constraint(
            drm_constraint_struct *new_cons,
            drm_rights_struct *old_rights,
            kal_uint8 permission,
            kal_uint8 *perv_cons,
            kal_uint8 *next_cons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 is_trivial, i, base, dt_merge;
    drm_constraint_struct *cons;
    drm_constraint_entry_struct *appending = old_rights->constraint_list;
    kal_uint8 best_cons = old_rights->best[permission];
    kal_uint8 cons_num = old_rights->num[permission];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *perv_cons = 0xFF;

    is_trivial = drm_core_is_trivail_constraint(new_cons);
    base = best_cons;

    for (i = 0; i < cons_num; i++)
    {
        /*
         *   1. if it could be merged
         */
        cons = &(appending[base].cons);
        if (is_trivial && drm_core_is_trivail_constraint(cons))
        {
            if (new_cons->type == cons->type)
            {
                if (new_cons->type == DRM_CONSTRAINT_DATETIME)
                {
                    dt_merge = drm_core_merge_dt_constraint(new_cons, old_rights, permission, perv_cons, next_cons);
                    return dt_merge;
                }
                else if (new_cons->type == DRM_CONSTRAINT_COUNT)
                {
                    new_cons->used_count += cons->used_count;
                    new_cons->total_count += cons->total_count;

                    if (new_cons->total_count > DRM_COUNT_MAX)
                    {
                        new_cons->total_count = DRM_COUNT_MAX;
                    }

                    if (new_cons->used_count > DRM_COUNT_MAX)
                    {
                        new_cons->used_count = DRM_COUNT_MAX;
                    }
                    DRM_MTK_TRACE(("Multi RO merge count, used_count = %d, total_count = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_COUNT, new_cons->used_count, new_cons->total_count));
                    old_rights->num[permission]--;
                    /* *perv_cons = 0xFF; */
                    *next_cons = 0xFF;
                    return KAL_TRUE;
                }
                else if (new_cons->type == DRM_CONSTRAINT_INTERVAL)
                {
                    break;
                }
                else if (new_cons->type == DRM_CONSTRAINT_NONE)
                {
                    return KAL_FALSE;
                }
                /* DRM_CONSTRAINT_INTERVAL do not merge */

            }
        }
        *perv_cons = base;
        base = appending[base].next;
    }

    *next_cons = base;
    /*
     *  2. insert ro by priority
     */
    drm_core_update_multiro_order(new_cons, appending, old_rights->best[permission], perv_cons, next_cons);
    return KAL_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  drm_core_update_multiro_order
 * DESCRIPTION
 *  insert new constraint into ro
 * PARAMETERS
 *  new_cons            [?]         
 *  appending           [?]         
 *  base_cons           [IN]        
 *  prev_cons           [?]         
 *  next_cons           [?]         
 *  constraints(?)      [IN]        
 * RETURNS
 *  kal_bool(?)
 *****************************************************************************/
void drm_core_update_multiro_order(
        drm_constraint_struct *new_cons,
        drm_constraint_entry_struct *appending,
        kal_uint8 base_cons,
        kal_uint8 *prev_cons,
        kal_uint8 *next_cons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 cons_status;
    drm_constraint_struct *cons = &(appending[base_cons].cons);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DRM_MTK_TRACE(("Update multi RO order"), (TRACE_INFO, DRM_MTK_MULTIRO_ORDER, cons->type));
    DRM_MTK_TRACE(("Multi RO new constraint type = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_NEW_CONS_TYPE, new_cons->type));
    
    *prev_cons = *next_cons = 0xFF;

    while (cons)
    {
        DRM_MTK_TRACE(("Multi RO constraint index = %d, type = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_CONS, base_cons, cons->type));
        cons_status = drm_core_is_constraint_valid(cons, KAL_FALSE);

        if (cons_status == DRM_STATUS_NO_RIGHTS)
        {
            base_cons = appending[base_cons].next;
            *next_cons = base_cons;
        }
        else if (cons_status == DRM_STATUS_RIGHTS_PRESENT || cons_status == DRM_STATUS_RIGHTS_IN_FUTURE)
        {
            if (drm_core_compare_constraint(new_cons, cons) == DRM_CONSTRAINT_HIGH)
            {
                *next_cons = base_cons;
                return;
            }
            else
            {
                *prev_cons = base_cons;
                base_cons = appending[base_cons].next;
                *next_cons = base_cons;
            }
        }

        if (base_cons != 0xFF)
        {
            cons = &(appending[base_cons].cons);
        }
        else
        {
            cons = NULL;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  drm_core_compare_constraint
 * DESCRIPTION
 *  Compare priority of constraints
 * PARAMETERS
 *  compare         [IN]        
 *  reference       [IN]        
 * RETURNS
 *  kal_uint8
 *****************************************************************************/
kal_uint8 drm_core_compare_constraint(drm_constraint_struct *compare, drm_constraint_struct *reference)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* constraint with no limitation */
    if (compare->type == DRM_CONSTRAINT_NONE)
    {
        return DRM_CONSTRAINT_HIGH;
    }

    if (reference->type == DRM_CONSTRAINT_NONE)
    {
        return DRM_CONSTRAINT_LOW;
    }
    if (compare->type & DRM_CONSTRAINT_DATETIME)
    {
        if ((reference->type & DRM_CONSTRAINT_DATETIME) == 0)
        {
            return DRM_CONSTRAINT_HIGH;
        }
        else
        {
            if (compare->end_time < reference->end_time)    /* compare end time */
            {
                return DRM_CONSTRAINT_HIGH;
            }
            else if (compare->end_time > reference->end_time)
            {
                return DRM_CONSTRAINT_LOW;
            }
            else
            {
                if ((compare->type & DRM_CONSTRAINT_INTERVAL) && ((reference->type & DRM_CONSTRAINT_INTERVAL) == 0))
                {
                    return DRM_CONSTRAINT_HIGH;
                }
                else if (((compare->type & DRM_CONSTRAINT_INTERVAL) == 0) && (reference->type & DRM_CONSTRAINT_INTERVAL))
                {
                    return DRM_CONSTRAINT_LOW;
                }
                else
                {
                    if (compare->type & DRM_CONSTRAINT_COUNT)
                    {
                        return DRM_CONSTRAINT_LOW;
                    }
                    else
                    {
                        return DRM_CONSTRAINT_HIGH;
                    }
                }
            }

        }
    }
    else if (compare->type & DRM_CONSTRAINT_INTERVAL)
    {
        if (reference->type & DRM_CONSTRAINT_DATETIME)
        {
            return DRM_CONSTRAINT_LOW;
        }
        else if (reference->type & DRM_CONSTRAINT_COUNT)
        {
            return DRM_CONSTRAINT_HIGH;
        }
        else
        {
            return DRM_CONSTRAINT_EQUAL;
        }
    }
    else if (compare->type & DRM_CONSTRAINT_COUNT)
    {
        if (reference->type & DRM_CONSTRAINT_DATETIME || reference->type & DRM_CONSTRAINT_INTERVAL)
        {
            return DRM_CONSTRAINT_LOW;
        }
        else
        {
            /* should be merged */
            ASSERT(0);
            return DRM_CONSTRAINT_EQUAL;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_merge_dt_constraint
 * DESCRIPTION
 *  Merge datetime constraints
 * PARAMETERS
 *  cons            [IN]        
 *  old_rights      [?]         
 *  permission      [IN]        
 *  perv_cons       [OUT]       If the constraint is not merged, return correct position to insert
 *  next_cons       [?]         
 *  new_cons(?)     [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_uint8 drm_core_merge_dt_constraint(
            drm_constraint_struct *cons,
            drm_rights_struct *old_rights,
            kal_uint8 permission,
            kal_uint8 *perv_cons,
            kal_uint8 *next_cons)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_uint8 *dt_cons_indices;	/* array to hold indices of all dt constraints */
    drm_constraint_struct *old_cons, *compared_end_with_DT_other_cons = NULL;
    applib_time_struct time;
    kal_uint32 ltime;
    kal_uint8 next, last_cons, dt_cons_num = 0;
	kal_uint8 prev_of_best_cons = 0xff;
    drm_constraint_entry_struct *appending = old_rights->constraint_list;
    kal_uint8 best_cons = old_rights->best[permission];
	kal_uint8 flag_for_best_cons = KAL_TRUE;
	kal_uint16 prev_temp_iterator;
	kal_bool flag_for_prev_temp_changes = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	dt_cons_indices = drmt_mem_alloc((old_rights->num[permission] + 1));   /* allocating memory to array holding dt constraints indices */
    memset(dt_cons_indices, 0xff, sizeof(dt_cons_indices));
	//applib_dt_get_secure_time(&time);
	drm_core_get_stime(&time);
    ltime = applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);

    DRM_MTK_TRACE(("Multi RO merge DT compare start = %d, end = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_DT_CONS_DT, cons->start_time, cons->end_time));
    old_cons = (drm_constraint_struct*) drmt_mem_alloc(DRM_CONSTRAINT_SIZE);
    ASSERT(old_cons);

    /* check constraint and get last one */
    last_cons = next = best_cons;
    /*dt_cons_num++;*/	/* need not increment it once before search of dt constraints */
    while (next != 0xFF) /* use array here to store the indices of DT only constraint and put 0xff in end as marker */
    {
        
        if (appending[next].cons.type == DRM_CONSTRAINT_DATETIME)  /* check if it do not contain DT use & operator */
        {
            dt_cons_indices[dt_cons_num] = last_cons = next;    /* filling array containing indices of DT only cons, last_cons should have constraints of last DT only constraints */
			dt_cons_num++;	/* is to be incremented only when DT constraint is there because only they can be merged */
			if ( flag_for_best_cons )
			{
				best_cons = next;	/* assigning indices of first DT constraint to best_cons */
				flag_for_best_cons = KAL_FALSE;
			}
        }
        if ( flag_for_best_cons )
		{
			prev_of_best_cons = next;    /* prev_of_best_cons will contain the previous of best_cons */
		}
		next = appending[next].next;
    }


	/* here we can remove all if checks and use dt_cons_indices only to assign values to best_cons, last_cons, prev_of_best_cons
	/* best_cons will be first only DT constraint */
	/* last_cons will be last only DT constraint */
	/* prev_of_best_cons will be previous of best_cons */
	/* next will be 0xff at end of this loop */
	/* dt_cons_num will be count of only DT constraint */
    DRM_MTK_TRACE(("Multi RO DT start = %d, end = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_DT_CONS_RANGE, best_cons, last_cons));

    memcpy(old_cons, &(appending[best_cons].cons), DRM_CONSTRAINT_SIZE);   /* best_cons use here the first found DT only constraint */

    if ((old_cons->type == DRM_CONSTRAINT_DATETIME) && (cons->type == DRM_CONSTRAINT_DATETIME)) 
    {
        if (old_cons->start_time == 0 && old_cons->end_time == 0)       /* there's no dt constraint */
        {
            *perv_cons = 0xFF; 
            *next_cons = 0xFF;
        }
        else if (cons->start_time == 0 && cons->end_time == 0)
        {
            drmt_mem_free(old_cons);	/* old_cons mem was not getting free in this flow */
			drmt_mem_free(dt_cons_indices);
			return KAL_FALSE;
        }
        else
            /*
             *            [---OLD---]
             * [---NEW---]
             */
        if (cons->end_time < old_cons->start_time)
        {
            *next_cons = best_cons;				/* best_cons is first only DT constraint */
            *perv_cons = prev_of_best_cons;		/* rather than 0xff we need to use perv_cons of first found DT constraint  */
            DRM_MTK_TRACE(("Multi RO first DT constraint"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_FIRST, best_cons, last_cons));
        }
        else
            /*
             * [---OLD---]
             *            [---NEW---]
             */
        if (cons->start_time > appending[last_cons].cons.end_time) /* last_cons should have the index of last DT only constraint */
        {
            *perv_cons = last_cons;
            *next_cons = appending[last_cons].next;
            DRM_MTK_TRACE(("Multi RO last DT constraint"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_LAST, best_cons, last_cons));

        }
        else
        {
            kal_uint32 flag = 0, i = 0, j = 0;
            kal_uint8 prev_index = prev_of_best_cons;	/* prev_index is not 0xff always */
            drm_constraint_struct *compared_start = NULL, *nextcons, *compared_end = NULL;

            /*
             * 1.
             *        [---OLD ...
             * [---NEW...
             */
            next = best_cons;
            if (cons->start_time <= old_cons->start_time)
            {
                flag = 1 << 1;
                DRM_MTK_TRACE(("Multi RO merge DT S1"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_S1));
            }
            else
            {
                for (i = 0; i < dt_cons_num; i++)
                {
                    compared_start = &(appending[dt_cons_indices[i]].cons);    /* using dt_cons_indices array instead of next */
                    nextcons = &(appending[dt_cons_indices[i+1]].cons); /* here we should check if nxt->next != 0xff */
                    DRM_MTK_TRACE(("Multi RO merge DT compare = %d, next = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_COMPARE_INDEX, next, appending[next].next));                    
                    DRM_MTK_TRACE(("Multi RO merge DT compare dt, start = %d, end = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_COMPARE_DT, compared_start->start_time, compared_start->end_time));                    
                    DRM_MTK_TRACE(("Multi RO merge DT next dt, start = %d, end = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_NEXT_DT, nextcons->start_time, nextcons->end_time));                    
                    /*
                     * 2.
                     * [---OLD ...][....
                     *        [---NEW---]
                     */
                    if (cons->start_time >= compared_start->start_time && cons->start_time <= compared_start->end_time)
                    {
                        flag = 1 << 2;
                        DRM_MTK_TRACE(("Multi RO merge DT S2"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_S2));
                        break;
                    }

                    /*
                     * 3.
                     *  ...]    [---OLD ...
                     *        [---NEW---]
                     */
                    if (cons->start_time < nextcons->start_time && cons->start_time > compared_start->end_time)
                    {
                        flag = 1 << 3;
                        DRM_MTK_TRACE(("Multi RO merge DT S3"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_S3));
                        /*
                         * 7.
                         * ...]           [---OLD ...
                         *     [---NEW---]
                         */
                        if (cons->end_time < nextcons->start_time)
                        {
                            flag |= 1 << 7;
                            DRM_MTK_TRACE(("Multi RO merge DT S7"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_S7));
                        }
                        prev_index = next;
                        break;
                    }
                    prev_index = next;
                    next = dt_cons_indices[i+1];   /* this will assign the next DT constraints index to next */
                }
            }

            /*
             * 4.
             * ...OLD---]
             *     [---NEW---]
             */
            if (cons->end_time >= appending[last_cons].cons.end_time)
            {
                flag |= 1 << 4;
                old_rights->num[permission] -= (dt_cons_num - i);
                DRM_MTK_TRACE(("Multi RO merge DT S4"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_S4));
            }
            else if (flag != 0x88)
            {
                for (j = i; j < dt_cons_num; j++)
                {
                    compared_end = &(appending[dt_cons_indices[j]].cons);
                    nextcons = &(appending[dt_cons_indices[j+1]].cons);
                    DRM_MTK_TRACE(("Multi RO merge DT compare = %d, next = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_COMPARE_INDEX, next, appending[next].next));                    
                    DRM_MTK_TRACE(("Multi RO merge DT compare dt, start = %d, end = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_COMPARE_DT, compared_end->start_time, compared_end->end_time));                    
                    DRM_MTK_TRACE(("Multi RO merge DT next dt, start = %d, end = %d"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_NEXT_DT, nextcons->start_time, nextcons->end_time));                    
                    /*
                     * 5.
                     * .......OLD---]
                     * ...NEW---]
                     */
                    if (cons->end_time >= compared_end->start_time && cons->end_time <= compared_end->end_time)
                    {
                        flag |= 1 << 5;
						if (flag == 40 )
						{
							old_rights->num[permission] -= (j - i);    /* +1 is to be removed from here in case flag is 40 or 0x28  */
						}
						else
						{
							old_rights->num[permission] -= (j - i + 1);    /* +1 is to be removed from here in case flag is 40 or 0x28  */
						}
                        DRM_MTK_TRACE(("Multi RO merge DT S5"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_S5));
                        break;
                    }

                    /*
                     * 6.
                     * ...OLD---]     [...
                     *    ...NEW---]
                     */
                    if (cons->end_time > compared_end->end_time && cons->end_time < nextcons->start_time)
                    {
                        flag |= 1 << 6;
                        old_rights->num[permission] -= (j - i + 1);
                        DRM_MTK_TRACE(("Multi RO merge DT S6"), (TRACE_INFO, DRM_MTK_MULTIRO_MERGE_DT_S6));
                        break;
                    }
                    next = dt_cons_indices[j+1];
                }
            }

            switch (flag)
            {
                case 0x12:  /* 1.4. */
                {
                    /*
                     *    [...OLD...]
                     * [   ...NEW...      ]
                     */
                    *perv_cons = prev_of_best_cons;    
                    *next_cons = appending[last_cons].next;
                    break;
                }
                case 0x22:  /* 1.5. */
                {
                    /*
                     *    [---OLD---]...[---j---][---j+1---]
                     * [   ...   NEW   ...   ]
                     */
                    *perv_cons = prev_of_best_cons;
                    *next_cons = appending[next].next;
                    cons->end_time = compared_end->end_time;
                    /*  pass to 1.6. */
                }
                case 0x42:  /* 1.6. */
                {
                    /*
                     *   [---OLD---]...[---j---]   [---j+1---]
                     * [    ...    NEW    ...    ]
                     */
                    *perv_cons = prev_of_best_cons;
                    *next_cons = appending[next].next;
                    break;
                }
                case 0x14:  /* 2.4. */
                {
                    /*
                     * ...[---i---]...[--- num-1 ---]
                     *           [   ...   NEW   ...   ]
                     */
                    cons->start_time = compared_start->start_time;
                    *perv_cons = prev_index;    /* prev_index should get value from prev_of_best_cons or value of true prev_index prev_index should not be initialised with 0xff */
                    *next_cons = appending[last_cons].next;
                    break;
                }
                case 0x24:  /* 2.5. */
                {
                    /*
                     * ...[---i---]...[---j---][---j+1---]
                     *         [---NEW---]
                     */
                    cons->start_time = compared_start->start_time;
                    cons->end_time = compared_end->end_time;

                    *perv_cons = prev_index;
                    *next_cons = appending[next].next;
                    break;
                }
                case 0x44:  /* 2.6. */
                {
                    /*
                     * ...[---i---]...[---j---]     [---j+1---]
                     *         [  ...  NEW  ...  ]
                     */
                    cons->start_time = compared_start->start_time;

                    *perv_cons = prev_index;
                    *next_cons = appending[next].next;
                    break;
                }
                case 0x88:  /* 3.7. */
                {
                    /*
                     * i---]             [---i+1---]...
                     *       [---NEW---]
                     */
                    *perv_cons = prev_index;
                    *next_cons = appending[next].next;
                    break;
                }
                case 0x18:  /* 3.4. */
                {
                    /*
                     * i---]    [---i+1  ...[---num-1---]
                     *        [     ...     NEW     ...     ]
                     */
                    *perv_cons = prev_index;
                    *next_cons = appending[last_cons].next;
                    break;
                }
                case 0x28:  /* 3.5. */
                {
                    /*
                     * i---]    [---i+1  ...[---j---][---j+1---]
                     *        [  ...  NEW  ...  ]
                     */
                    cons->end_time = compared_end->end_time;
                    *perv_cons = prev_index;
                    *next_cons = appending[next].next;
                    break;

                    /* pass to 3.6. */
                }
                case 0x48:  /* 3.6. */
                {
                    /*
                     * i---]    [---i+1  ...[---j---]      [---j+1---]
                     *        [    ...    NEW    ..  .  ]
                     */

                    /* Same as 3.7??? */

                    /*
                     * [---CUR---] <- [---OLD---]
                     */
                    break;
                }
                default:
                {
                    /* equal to existed constraint */
                    break;
                }
            }

        }
    }
	
	/* prev_temp_iterator will be used to traverse the linked list and to find the actual previous constraint by comparing the end time */
	
	if (*perv_cons != 0xff)
	{
		prev_temp_iterator = *perv_cons;	/* we will have to start comparing from the prev_of_best_cons only */
	}
	else
	{
		prev_temp_iterator = old_rights->best[permission];	/* in this case as per DT only it will be the first constraint but there may be DT||INT||Count constraints present so we need to compare end time with them to find the actul prev and next constraints */
	}
	
	while (prev_temp_iterator != 0xff)
	{
		compared_end_with_DT_other_cons = &(appending[prev_temp_iterator].cons);
		if( ( (appending[prev_temp_iterator].cons.type & DRM_CONSTRAINT_DATETIME) == 0 ) )
		{
			break;
		}
		else
		{
			if (appending[prev_temp_iterator].cons.type == DRM_CONSTRAINT_DATETIME)
			{
				prev_temp_iterator = appending[prev_temp_iterator].next;
			}
			else
			{
				if(cons->end_time >= compared_end_with_DT_other_cons->end_time)
				{
					*perv_cons = prev_temp_iterator;
					prev_temp_iterator = appending[prev_temp_iterator].next;   
					/* when next is date time only then next should not be updated because DT only are already considered*/
					if (appending[prev_temp_iterator].cons.type != DRM_CONSTRAINT_DATETIME)
					{
						*next_cons = prev_temp_iterator;
					}
				}
				else
				{
					next = old_rights->best[permission];
					if( prev_temp_iterator == next )
					{
						*perv_cons = 0xff;
						*next_cons = old_rights->best[permission];
					}
					else
					{
						/*while(appending[next].next != prev_temp_iterator)
							next = appending[next].next;
						
						*next_cons = appending[next].next;*/
						*next_cons = prev_temp_iterator;
					}
					break;
				}
			}
		}
	}
	
    drmt_mem_free(old_cons);
	drmt_mem_free(dt_cons_indices);
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_gen_cid
 * DESCRIPTION
 *  generate content id for forward lock content
 * PARAMETERS
 *  cid             [IN]        
 *  seed            [?]         
 *  seed_len        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_gen_cid(kal_char *cid, kal_char *seed, kal_int32 seed_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (seed == NULL)
    {
        applib_time_struct time;
        kal_uint32 ltime;

        applib_dt_get_rtc_time(&time);
        ltime = applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);

        sprintf(&cid[11], "%d-%d", ltime, extra_serial++);
    }
    else
    {
        drm_parse_hash((kal_uint8*) seed, seed_len, (kal_char*) cid, KAL_FALSE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  drm_core_gen_fl_signature
 * DESCRIPTION
 *  generate signature of fl
 * PARAMETERS
 *  cid             [IN]        
 *  seed            [?]         
 *  seed_len        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_gen_fl_signature(kal_char *sign, FS_HANDLE seed_fl, kal_uint32 seed_len, kal_uint32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;
    kal_uint32 ltime, len;
    kal_uint8 key[DRM_MAX_KEY_LENGTH], seed_buf[DRM_MAX_KEY_LENGTH];
    kal_uint8 seed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&time);
    ltime = applib_dt_mytime_2_utc_sec(&time, KAL_FALSE);

    /* The signature source buffer is within first 128 bytes of DRM data (not including header) */
    seed = ltime % (DRM_MAX_URL_LENGTH - DRM_MAX_KEY_LENGTH); 

    sign[0] = seed; /* The size of signature offset is 1 byte */
    
    FS_Seek(seed_fl, seed + offset, FS_FILE_BEGIN);
    FS_Read(seed_fl, seed_buf, DRM_MAX_KEY_LENGTH, &len);
        
    drm_core_get_key(key);
    drm_core_rc4_encrypt_buff(key, DRM_MAX_KEY_LENGTH, (kal_uint8*)&sign[1], (kal_uint8*) seed_buf, DRM_MAX_KEY_LENGTH);
    
}

/*****************************************************************************
 * FUNCTION
 *  drm_core_varify_fl_signature
 * DESCRIPTION
 *  validate signature of fl
 * PARAMETERS
 *  cid             [IN]        
 *  seed            [?]         
 *  seed_len        [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool drm_core_varify_fl_signature(kal_char *sign, FS_HANDLE seed_fl, kal_int32 seed_len, kal_uint32 offset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    kal_uint8 key[DRM_MAX_KEY_LENGTH], seed_buf[DRM_MAX_KEY_LENGTH];
    kal_uint8 seed;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    seed = (kal_uint8)sign[0];
    
    FS_Seek(seed_fl, seed + offset, FS_FILE_BEGIN);
    FS_Read(seed_fl, seed_buf, DRM_MAX_KEY_LENGTH, &len);
        
    drm_core_get_key(key);
    drm_core_rc4_encrypt_buff(key, 16, seed_buf, seed_buf, DRM_MAX_KEY_LENGTH);

    if (strncmp((kal_char*)&sign[1], (kal_char*)seed_buf, DRM_MAX_KEY_LENGTH) == 0)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }        
}

/*****************************************************************************
 * FUNCTION
 *  drm_core_rc4_encrypt_buff
 * DESCRIPTION
 *  decrypt content id for DCF in FL
 * PARAMETERS
 *  myKey       [?]         
 *  key_len     [IN]        
 *  out_buf     [?]         
 *  in_buf      [?]         
 *  length      [IN]        
 *  cid(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_rc4_encrypt_buff(
        kal_uint8 *myKey,
        kal_uint8 key_len,
        kal_uint8 *out_buf,
        kal_uint8 *in_buf,
        kal_uint32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STCHE *che_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    che_str = (STCHE*) drmt_mem_alloc(sizeof(STCHE));

    drm_core_generate_che_by_fixed_key(myKey, key_len, che_str);

    che_process(che_str, CHE_RC4, CHE_CBC, CHE_DEC, in_buf, out_buf, length, KAL_TRUE);

    che_deinit(che_str);
    drmt_mem_free(che_str);
    /* drm_core_rm_padding(out_buf, &length); */
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_rc4_decrypt_buff
 * DESCRIPTION
 *  decrypt content id for DCF in FL
 * PARAMETERS
 *  myKey       [?]         
 *  key_len     [IN]        
 *  out_buf     [?]         
 *  in_buf      [?]         
 *  length      [IN]        
 *  cid(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_rc4_decrypt_buff(
        kal_uint8 *myKey,
        kal_uint8 key_len,
        kal_uint8 *out_buf,
        kal_uint8 *in_buf,
        kal_uint32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STCHE *che_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    che_str = (STCHE*) drmt_mem_alloc(sizeof(STCHE));

    drm_core_generate_che_by_fixed_key(myKey, key_len, che_str);

    che_process(che_str, CHE_RC4, CHE_CBC, CHE_DEC, in_buf, out_buf, length, KAL_TRUE);
    che_deinit(che_str);

    drmt_mem_free(che_str);
    /* drm_core_rm_padding(out_buf, &length); */
}


/*****************************************************************************
 * FUNCTION
 *  drm_core_generate_che_by_fixed_key
 * DESCRIPTION
 *  decrypt content id for DCF in FL
 * PARAMETERS
 *  myKey       [?]         
 *  key_len     [IN]        
 *  che_str     [?]         
 *  cid(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_generate_che_by_fixed_key(kal_uint8 *myKey, kal_uint8 key_len, STCHE *che_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    __align(4) kal_uint8 iv[16];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(((kal_int32) che_str & 0x03) == 0);

    che_init(che_str, CHE_RC4);
    che_key_action(che_str, CHE_SET_RC4_KEY, myKey, key_len);

    memcpy(iv, "4074BCC61602B5BE5EDF3586C1C7E90905D", 16);
    che_set_iv(che_str, iv, key_len);

}


/*****************************************************************************
 * FUNCTION
 *  drm_core_parse_dcf_in_fl
 * DESCRIPTION
 *  Create dcf which is wrapped in FL message
 * PARAMETERS
 *  input           [IN]        
 *  new_dcf         [IN]        
 *  rights          [?]         
 *  info            [?]         
 *  sd_pos          [IN]        
 *  cid             [IN]        
 *  cid_length      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void drm_core_parse_dcf_in_fl(
        FS_HANDLE input,
        FS_HANDLE new_dcf,
        drm_rights_struct *rights,
        drm_info_struct *info,
        kal_uint32 sd_pos,
        kal_char *cid,
        kal_uint32 cid_length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *buffer = NULL, *ptr;
    kal_uint32 length = 0, header_pos = 0, header_length, data_length, temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    buffer = (kal_char*) get_ctrl_buffer(512);
    memset(buffer, 0, sizeof(buffer));
    info->rights->offset = 0;

    header_pos += 3;    /* version, content type length, and content URL length */

    buffer[0] = 1;  /* version */

    ptr = (char*)int_to_mime(rights->mime_type);

    if (!ptr)
    {
        buffer[1] = length = 0;
    }
    else
    {
        buffer[1] = length = strlen(ptr);
		memcpy(&buffer[3], ptr, length);
    }
	
	header_pos += length;
    header_pos += cid_length;
    buffer[2] = cid_length;
    memcpy(&buffer[length + 3], info->meta[DRM_META_CONTENTURI], cid_length);

    /* write header */
    FS_Write(new_dcf, buffer, header_pos, &temp);
    info->rights->offset += temp; 

    if (input == new_dcf) /* DCF in Base64-encoded FL in MMS*/
    {
        FS_Read(input, buffer, 10, &length);
        temp = drm_parse_uintvar(buffer, &header_length, length); /* header length */            
        temp += drm_parse_uintvar(&buffer[temp], &data_length, length - temp); /* data length */
        header_pos += temp;
            
        rights->data_len = data_length;
        rights->offset = header_pos + header_length;
        return;
    }
        
    FS_Seek(input, sd_pos, FS_FILE_BEGIN);              /* Start of DCF */
    FS_Read(input, buffer, 10, &length);
    header_pos = sd_pos + 3 + buffer[1] + buffer[2];    /* content type + content rul */

    FS_Seek(input, header_pos, FS_FILE_BEGIN);  /* Start of DCF header */
    FS_Read(input, buffer, 10, &length);
    temp = drm_parse_uintvar(buffer, &header_length, length);   /* header length */
    /* header_pos += temp; */
    temp += drm_parse_uintvar(&buffer[temp], &data_length, length - temp);      /* data length */
    header_pos += temp;

    /* skip data len for MTK proprietary dcf */
    FS_Write(new_dcf, buffer, temp, &length);
    info->rights->offset += (temp + header_length);

    /* copy original header */
    FS_Seek(input, header_pos, FS_FILE_BEGIN);
    /* header_length -= strlen(DRM_DCF_IN_FL_FLAG); */
    while (header_length > 0)
    {
        length = (header_length > 512) ? 512 : header_length;
        FS_Read(input, buffer, length, &temp);
        header_length -= length;
        FS_Write(new_dcf, buffer, length, &temp);
    }

    /* add flag */
    /* FS_Write(new_dcf, DRM_DCF_IN_FL_FLAG, strlen(DRM_DCF_IN_FL_FLAG), &temp); */

    /* copy data */
    while (data_length > 0)
    {
        length = (data_length > 512) ? 512 : data_length;
        FS_Read(input, buffer, length, &temp);
        data_length -= length;
        FS_Write(new_dcf, buffer, length, &temp);
    }

    free_ctrl_buffer(buffer);
}

#endif /* __DRM_MTK__ */ 

