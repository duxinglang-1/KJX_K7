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
 *  MMSUseDetailSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MMS Viewer Parses UseDatils 
 *
 *
 * Author: Amitesh Srivastava (MTI00171)
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
// #include "app_str.h"
//#include "MMI_include.h"
#include "MMI_features.h"
#if defined (__MMI_MMS_2__) && defined (__MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__)

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "string.h"
#include "kal_public_api.h"
#include "fs_func.h"
#include "MMI_inet_app_trc.h"

#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "fs_type.h"
#include "Unicodexdcl.h"

#include "MmsXMLDefSrv.h"
#include "MmsUseDetailSrv.h"
#include "app_str.h"
//#include "FileManagerDef.h"
//#include "kal_release.h"

#define SRV_MMS_PARSED_TXT_BUF_UCS2_SIZE (512)
#define SRV_MMS_MAX_OTHER_PARSED_COUNT (50)
#define SRV_MMS_MAX_LIST_SIZE (1500)
static srv_mms_viewer_result_enum srv_mms_parse_urls_from_unicode(U16 *new_start, U16 type);
static srv_mms_viewer_result_enum srv_mms_parse_numbers_from_unicode(U16 *new_start);
static srv_mms_viewer_result_enum srv_mms_parse_emails_from_unicode(U16 *new_start);
static void srv_mms_check_overlap_last_number_and_del_before_block(U16 *end);
static MMI_BOOL srv_mms_is_lp_paired_wchar(U16 *lp_pos, S32 length);
static MMI_BOOL srv_mms_is_valid_phoneno_wchar(U16 ch, MMI_BOOL is_written_char_valid);
static MMI_BOOL srv_mms_is_valid_email_local_part_wchar(U16 ch);
static MMI_BOOL srv_mms_is_valid_email_domain_name_wchar(U16 ch);
static MMI_BOOL srv_mms_is_valid_url_last_wchar(U16 ch);
static MMI_BOOL srv_mms_is_valid_url_scheme_wchar(U16 ch);
static MMI_BOOL srv_mms_is_valid_url_wchar(U16 ch);
static U16 *srv_mms_strchr(U16 *s, S32 c, srv_mms_detail *address_node, MMI_BOOL *is_block, S32 *length);
static U16 *srv_mms_strstr(
                U16 *a,
                MMI_BOOL count,
                S32 *type,
                srv_mms_detail *address_node,
                srv_mms_viewer_result_enum *is_block,
                S32 *length);
static void srv_mms_free_offsets(srv_mms_detail **node);
static void srv_mms_free_other_offsets(srv_mms_offset *node);
static void srv_mms_free_url_offsets(srv_mms_url_offset **node);
static U16 *srv_mms_strstr_ext(U16 *type, srv_mms_use_detail *type_detail);
static MMI_BOOL srv_mms_check_for_overlap(U16 *end, U16 *data, srv_mms_use_detail type);
static void srv_mms_free_num_offsets(srv_mms_number_detail *node);
static MMI_BOOL srv_mms_check_valid_email(PU16 data, PU16 start, S32 len);
static void srv_mms_deinit_use_detail_srv(void);
static srv_mms_use_detail_struct g_srv_mms_use_detail_parser_cntx;
static U16 *g_data_lc;


/*****************************************************************************
 * FUNCTION
 *  srv_mms_common_parse
 * DESCRIPTION
 *  
 * PARAMETERS
 *  req_data        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
srv_mms_viewer_result_enum srv_mms_common_parse(srv_mms_use_detail_req_context_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_use_detail type_detail = SRV_MMS_TYPE_DEFAULT;
    srv_mms_viewer_result_enum ret_val = SRV_MMS_VIEWER_PARSE_SUCCESS;
    S32 i = 0, count = 0;
    srv_mms_detail **addresses[3], *address = NULL, *address_last = NULL;
    srv_mms_number_detail *address_num = NULL, *address_last_num = NULL;
    U32 bytes_written;
    S32 fs_ret = 0;
    S16 *buffer = NULL, count_detail[3], *temp_buffer = NULL, alloc_size = 0, count_num = 0, index = 0;
    U16 type = SRV_MMS_USE_NONE;
    U16 *new_start = NULL;
    U16 *temp_char;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_data->mem_alloc_fn == NULL ||
        req_data->mem_free_fn == NULL || req_data->input_data == NULL || req_data->header == NULL)
    {
        return SRV_MMS_VIEWER_PARSE_FAIL;
    }
    if (req_data->dataLen == 0)
    {
        return ret_val;
    }
    if (req_data->slide_not_parsed == MMI_FALSE)
    {
        g_data_lc = req_data->mem_alloc_fn(req_data->dataLen * 2 + 2);
        if (g_data_lc == NULL)
        {
            srv_mms_deinit_use_detail_srv();
            return SRV_MMS_VIEWER_OUT_OF_MEM;
        }
        memset(g_data_lc, 0x00, req_data->dataLen * 2 + 2);
        temp_char = req_data->input_data;
        memcpy((char*)g_data_lc, (char*)req_data->input_data, req_data->dataLen * 2);
        app_ucs2_strtolower((kal_wchar*) g_data_lc);
        req_data->input_data = g_data_lc;
        //g_data_lc = temp_char;
        memset(&g_srv_mms_use_detail_parser_cntx, 0, sizeof(srv_mms_use_detail_struct));
        g_srv_mms_use_detail_parser_cntx.req_data = req_data;
        g_srv_mms_use_detail_parser_cntx.count_blocks = 1;
        new_start = (PU16) srv_mms_strstr_ext(&type, &type_detail);
        if (new_start != NULL)
        {
            switch (type_detail)
            {
                case SRV_MMS_TYPE_NUMBER:
                    g_srv_mms_use_detail_parser_cntx.order_type = SRV_MMS_USE_NEU;
                    ret_val = srv_mms_parse_numbers_from_unicode(new_start);
                    break;
                case SRV_MMS_TYPE_EMAIL:
                    g_srv_mms_use_detail_parser_cntx.order_type = SRV_MMS_USE_ENU;
                    ret_val = srv_mms_parse_emails_from_unicode(new_start);
                    break;
                case SRV_MMS_TYPE_URL:
                    g_srv_mms_use_detail_parser_cntx.order_type = SRV_MMS_USE_UNE;
                    ret_val = srv_mms_parse_urls_from_unicode(new_start, type);
                    break;
                default:
                    g_srv_mms_use_detail_parser_cntx.order_type = SRV_MMS_USE_NONE;
                    break;
            }
        }
    }
    else
    {
        g_srv_mms_use_detail_parser_cntx.req_data = req_data;
        memset(g_data_lc, 0x00, req_data->dataLen * 2 + 2);
        temp_char = req_data->input_data;
        memcpy((char*)g_data_lc, (char*)req_data->input_data, req_data->dataLen * 2);
        app_ucs2_strtolower(g_data_lc);
        req_data->input_data = g_data_lc;
        //g_data_lc = temp_char;
        switch (g_srv_mms_use_detail_parser_cntx.order_type)
        {
            case SRV_MMS_USE_NEU:
                g_srv_mms_use_detail_parser_cntx.order_type = SRV_MMS_USE_NEU;
                ret_val = srv_mms_parse_numbers_from_unicode(new_start);
                break;
            case SRV_MMS_USE_ENU:
                g_srv_mms_use_detail_parser_cntx.order_type = SRV_MMS_USE_ENU;
                ret_val = srv_mms_parse_emails_from_unicode(new_start);
                break;
            case SRV_MMS_USE_UNE:
                g_srv_mms_use_detail_parser_cntx.order_type = SRV_MMS_USE_UNE;
                ret_val = srv_mms_parse_urls_from_unicode(new_start, type);
                break;
            default:
                ASSERT(0);
                break;
        }
    }
    g_data_lc = req_data->input_data;
    if ((g_srv_mms_use_detail_parser_cntx.parsed_num
         || g_srv_mms_use_detail_parser_cntx.parsed_email
         || g_srv_mms_use_detail_parser_cntx.parsed_url) && ret_val == SRV_MMS_VIEWER_PARSE_SUCCESS)
    {
        /* Update File Headers */
        index = g_srv_mms_use_detail_parser_cntx.req_data->slide_num - 1;
        req_data->header[index] = (S16) g_srv_mms_use_detail_parser_cntx.parsed_num;
        index += g_srv_mms_use_detail_parser_cntx.req_data->total_slides;
        req_data->header[index] = (S16) g_srv_mms_use_detail_parser_cntx.parsed_email;
        index += g_srv_mms_use_detail_parser_cntx.req_data->total_slides;
        req_data->header[index] = (S16) g_srv_mms_use_detail_parser_cntx.parsed_url;
        count_num = 0;
        while (1)
        {
            temp_buffer = &req_data->header[count_num];
            fs_ret = FS_Write(
                        g_srv_mms_use_detail_parser_cntx.req_data->file_handle,
                        temp_buffer,
                        sizeof(S16) * g_srv_mms_use_detail_parser_cntx.req_data->total_slides * 3 - count_num,
                        &bytes_written);
            if (fs_ret < 0)
            {
                *(g_srv_mms_use_detail_parser_cntx.req_data->fail_reason) = fs_ret;
                srv_mms_deinit_use_detail_srv();
                return SRV_MMS_VIEWER_PARSE_FAIL;
            }
            MMI_TRACE(
                MMI_INET_TRC_G6_MMS,
                MMI_SRV_VIEWER_USE_FILE_WRITE,
                (sizeof(S16) * (g_srv_mms_use_detail_parser_cntx.req_data->total_slides + 1) * 3 - count_num),
                bytes_written);
            count_num += bytes_written;
            if (count_num == (S16) (sizeof(S16) * g_srv_mms_use_detail_parser_cntx.req_data->total_slides * 3))
            {
                break;
            }
            temp_buffer = &req_data->header[count_num / 4];
        }
        /* Update File Headers */

        /* Update File Body */
        fs_ret = FS_Seek(g_srv_mms_use_detail_parser_cntx.req_data->file_handle, 0, FS_FILE_END);
        addresses[0] = NULL;
        addresses[1] = &g_srv_mms_use_detail_parser_cntx.email_list;    /* ; */
        addresses[2] = &g_srv_mms_use_detail_parser_cntx.url_list;
        /* addresses[2] = */
        count_detail[0] = g_srv_mms_use_detail_parser_cntx.parsed_num;
        count_detail[1] = g_srv_mms_use_detail_parser_cntx.parsed_email;
        count_detail[2] = g_srv_mms_use_detail_parser_cntx.parsed_url;

        for (i = 0; i < 3; i++)
        {
            for (count = 0; count < count_detail[i]; count += SRV_MMS_MAX_LIST_SIZE)
            {
                alloc_size =
                    count_detail[i] - count > SRV_MMS_MAX_LIST_SIZE ? SRV_MMS_MAX_LIST_SIZE : count_detail[i] - count;
                alloc_size *= 2;
                buffer = (S16*) (g_srv_mms_use_detail_parser_cntx.req_data)->mem_alloc_fn(sizeof(S16) * alloc_size);
                if (!buffer)
                {
                    /* ASSERT(buffer); */
                    srv_mms_deinit_use_detail_srv();
                    return SRV_MMS_VIEWER_OUT_OF_MEM;
                }
                memset(buffer, 0, sizeof(S16) * alloc_size);
                count_num = 0;
                if (i == 0)
                {
                    address_num = address_last_num ? address_last_num : g_srv_mms_use_detail_parser_cntx.number_list;
                    address_last_num = NULL;
                    while (address_num != NULL)
                    {
                        buffer[count_num] = address_num->offset;
                        buffer[count_num + 1] = address_num->size;
                        address_num = address_num->next;
                        count_num = count_num + 2;
                        if (count_num / 2 == SRV_MMS_MAX_LIST_SIZE)
                        {
                            address_last_num = address_num;
                            break;
                        }
                    }
                }
                else
                {

                    address = address_last ? address_last : *(addresses[i]);
                    address_last = NULL;
                    while (address != NULL)
                    {
                        buffer[count_num] = address->offset;
                        buffer[count_num + 1] = address->size;
                        address = address->next;
                        count_num = count_num + 2;
                        if (count_num / 2 == SRV_MMS_MAX_LIST_SIZE)
                        {
                            address_last = address;
                            break;
                        }
                    }
                }
                count_num = 0;
                while (1)
                {
                    temp_buffer = &buffer[count_num];
                    fs_ret = FS_Write(
                                g_srv_mms_use_detail_parser_cntx.req_data->file_handle,
                                temp_buffer,
                                sizeof(S16) * alloc_size - count_num,
                                &bytes_written);
                    if (fs_ret < 0)
                    {
                        *(g_srv_mms_use_detail_parser_cntx.req_data->fail_reason) = fs_ret;
                        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(buffer);
                        srv_mms_deinit_use_detail_srv();
                        return SRV_MMS_VIEWER_PARSE_FAIL;
                    }
                    MMI_TRACE(
                        MMI_INET_TRC_G6_MMS,
                        MMI_SRV_VIEWER_USE_FILE_WRITE,
                        sizeof(S16) * alloc_size - count_num,
                        bytes_written);
                    count_num += bytes_written;
                    if (count_num == (S16) (sizeof(S16) * alloc_size))
                    {
                        break;
                    }
                    temp_buffer = &buffer[count_num / 4];
                }
                g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(buffer);
                if (g_srv_mms_use_detail_parser_cntx.number_list && !address_last_num)
                {
                    srv_mms_free_num_offsets(g_srv_mms_use_detail_parser_cntx.number_list);
                    g_srv_mms_use_detail_parser_cntx.number_list = NULL;
                    address_num = NULL;
                }
                if (addresses[i] && !address_last)
                {
                    srv_mms_free_offsets(addresses[i]);
                }

            }
        }
        *(g_srv_mms_use_detail_parser_cntx.req_data->number_count) += g_srv_mms_use_detail_parser_cntx.parsed_num;
        *(g_srv_mms_use_detail_parser_cntx.req_data->email_count) += g_srv_mms_use_detail_parser_cntx.parsed_email;
        *(g_srv_mms_use_detail_parser_cntx.req_data->url_count) += g_srv_mms_use_detail_parser_cntx.parsed_url;
    }
    if (g_data_lc && ret_val == SRV_MMS_VIEWER_PARSE_SUCCESS)
    {
        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(g_data_lc);
        g_data_lc = NULL;
    }
    return ret_val;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_parse_numbers_from_unicode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_start       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
srv_mms_viewer_result_enum srv_mms_parse_numbers_from_unicode(U16 *new_start)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0, count = 0;
    S32 dataLen_other = 0, dataLen = 0;
    U16 *data = NULL;
    srv_mms_viewer_result_enum ret_val_parse = SRV_MMS_VIEWER_PARSE_SUCCESS;
    MMI_BOOL normal = MMI_TRUE;
    MMI_BOOL is_overlap = MMI_FALSE;
    MMI_BOOL is_length_exceed = MMI_FALSE;
    srv_mms_offset *last_email = NULL, *other = NULL;
    srv_mms_url_offset *last_url = NULL;
    srv_mms_offset *temp = NULL;
    srv_mms_url_offset *temp_url = NULL;
    U16 *pattern[SRV_MMS_USE_DETAILS_URL_PATTERN_NO] = {SRV_MMS_URL_UNICODE_PATTERN_1,
        SRV_MMS_URL_UNICODE_PATTERN_2,
        SRV_MMS_URL_UNICODE_PATTERN_3,
        SRV_MMS_URL_UNICODE_PATTERN_4
    };
    srv_mms_number_detail *address = NULL, *addr = NULL;
    MMI_BOOL is_remove_duplicate = MMI_TRUE;
    srv_mms_offset *temp_free = NULL;
    U16 *input_other = NULL, *input_data = NULL;

    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    S32 time1 = 0, time2 = 0, time3 = 0;

    // #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_ENTER_NUMBER_SEARCH);
    g_srv_mms_use_detail_parser_cntx.other_parse_count = 0;
    g_srv_mms_use_detail_parser_cntx.other_parse = MMI_FALSE;
    dataLen_other = dataLen = g_srv_mms_use_detail_parser_cntx.req_data->dataLen;
    dataLen = dataLen / 2;
    input_other = data = input_data = g_srv_mms_use_detail_parser_cntx.req_data->input_data;
    other = g_srv_mms_use_detail_parser_cntx.num_offset;
    if (g_srv_mms_use_detail_parser_cntx.last_offset != NULL)
    {
        data = g_srv_mms_use_detail_parser_cntx.last_offset;
        dataLen = dataLen - (data - input_data);
        input_other = data;
        g_srv_mms_use_detail_parser_cntx.last_offset = NULL;
        last_url = g_srv_mms_use_detail_parser_cntx.last_url_searched;
        g_srv_mms_use_detail_parser_cntx.last_url_searched = NULL;
        last_email = g_srv_mms_use_detail_parser_cntx.last_email_searched;
        g_srv_mms_use_detail_parser_cntx.last_email_searched = NULL;
    }
    else if (g_srv_mms_use_detail_parser_cntx.num_other_last_offset)
    {
        other = g_srv_mms_use_detail_parser_cntx.num_other_last_offset;
        g_srv_mms_use_detail_parser_cntx.num_other_last_offset = NULL;
    }
    len = dataLen;
    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    kal_get_time((kal_uint32*) & time1);
    // #endif
    while (data - input_other < dataLen || other != NULL)
    {
        S32 i = 0, no_length = 0, str_length = 0;
        U16 *start = NULL;
        U16 *end = start;

        is_overlap = MMI_FALSE;
        if (data - input_data >= (SRV_MMS_PARSED_TXT_BUF_UCS2_SIZE * g_srv_mms_use_detail_parser_cntx.count_blocks) &&
            other == NULL)
        {
            g_srv_mms_use_detail_parser_cntx.last_offset = data;
            g_srv_mms_use_detail_parser_cntx.last_url_searched = last_url;
            g_srv_mms_use_detail_parser_cntx.last_email_searched = last_email;
            break;
        }
        else if (other != NULL && g_srv_mms_use_detail_parser_cntx.other_parse_count > SRV_MMS_MAX_OTHER_PARSED_COUNT)
        {
            g_srv_mms_use_detail_parser_cntx.num_other_last_offset = other;
            g_srv_mms_use_detail_parser_cntx.order_type = SRV_MMS_USE_NEU;
            g_srv_mms_use_detail_parser_cntx.other_parse = MMI_TRUE;
            break;
        }
        if (normal == MMI_FALSE && other == NULL)
        {
            break;
        }
        if (other != NULL)
        {
            start = input_data + other->pos;
            g_srv_mms_use_detail_parser_cntx.other_parse_count++;
            normal = MMI_FALSE;
        }
        else
        {
            if (new_start != NULL)
            {
                start = new_start;
                new_start = NULL;
            }
            else
            {
                start = data;
            }
        }
        end = start;
        for (i = 0; i < len; i++)
        {
            if ((*end >= L'0') && (*end <= L'9'))
            {
                if (no_length > SRV_MMS_MAX_PHONE_NUM_LEN)  /* Phone number is too long */
                {
                    break;  /* search stop */
                }
                no_length++;
                str_length++;
            }
            else if (*end == L'+')
            {
                if (no_length == 0)
                {
                    no_length++;
                    str_length++;
                }
                else
                {
                    break;  /* search stop */
                }
            }
            else if ((*end == L'(') || (*end == L')') || (*end == L'-'))
            {
                str_length++;
                /* part of the number but not add to length */
            }
            else if ((*end == L'w') || (*end == L'p') || (*end == L'W') || (*end == L'P'))
            {
                if (no_length == 0)
                {
                }
                else
                {
                    if (no_length > SRV_MMS_MAX_PHONE_NUM_LEN)  /* Phone number is too long */
                    {
                        break;  /* search stop */
                    }
                    no_length++;
                    str_length++;
                }
            }
            else
            {
                if (str_length > 0)
                {
                    break;
                }
            }

            if (str_length == 0 && other == NULL)
            {
                if (*end == '@')
                {
                    temp =
                        (srv_mms_offset*) g_srv_mms_use_detail_parser_cntx.req_data->
                        mem_alloc_fn(sizeof(srv_mms_offset));
                    if (temp == NULL)
                    {
                        srv_mms_deinit_use_detail_srv();
                        return SRV_MMS_VIEWER_OUT_OF_MEM;
                    }
                    memset(temp, 0, sizeof(srv_mms_offset));
                    temp->pos = ((S32) end - (S32) input_data) / 2;
                    temp->next = NULL;
                    if (g_srv_mms_use_detail_parser_cntx.email_offset)
                    {
                        srv_mms_offset *itr = NULL;

                        itr = g_srv_mms_use_detail_parser_cntx.email_offset;
                        while (itr->next != NULL)
                        {
                            itr = itr->next;
                        }
                        itr->next = temp;
                    }
                    else
                    {
                        g_srv_mms_use_detail_parser_cntx.email_offset = temp;
                    }
                    last_email = temp;
                    /* check and delete for number in an email */
                    if (g_srv_mms_use_detail_parser_cntx.is_num_bet_email)
                    {
                        g_srv_mms_use_detail_parser_cntx.is_num_bet_email = MMI_FALSE;
                        while (address != NULL)
                        {
                            is_overlap = srv_mms_check_for_overlap(end, input_data + address->offset, SRV_MMS_TYPE_EMAIL);
                            if (is_overlap == MMI_TRUE && srv_mms_check_valid_email(data, end, len))
                            {
                                addr = address;
                                address = address->prev;
                                if (address != NULL)
                                {
                                    address->next = NULL;
                                }
                                else
                                {
                                    g_srv_mms_use_detail_parser_cntx.number_list = NULL;
                                }
                                g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(addr);
                                addr = NULL;
                                g_srv_mms_use_detail_parser_cntx.parsed_num--;
                                continue;
                            }
                            else
                            {
                                break;
                            }
                            address = address->prev;
                        }
                        if (!address && g_srv_mms_use_detail_parser_cntx.num_before_blk)
                        {
                            srv_mms_check_overlap_last_number_and_del_before_block(end);
                        }
                    }
                }
                else if (*end == ':' || *end == 'w')
                {

                    while (count < SRV_MMS_USE_DETAILS_URL_PATTERN_NO)
                    {
                        if (mmi_wcsnicmp((PU16) end, (PU16) pattern[count], mmi_ucs2strlen((PS8) pattern[count])) == 0)
                        {
                            temp_url =
                                (srv_mms_url_offset*) g_srv_mms_use_detail_parser_cntx.req_data->
                                mem_alloc_fn(sizeof(srv_mms_url_offset));
                            if (temp_url == NULL)
                            {
                                srv_mms_deinit_use_detail_srv();
                                return SRV_MMS_VIEWER_OUT_OF_MEM;
                            }
                            memset(temp_url, 0, sizeof(srv_mms_url_offset));
                            temp_url->pos = ((S32) end - (S32) input_data) / 2;
                            temp_url->next = NULL;
                            temp_url->type = count;
                            if (g_srv_mms_use_detail_parser_cntx.url_offset)
                            {
                                srv_mms_url_offset *itr = g_srv_mms_use_detail_parser_cntx.url_offset;

                                while (itr->next != NULL)
                                {
                                    itr = itr->next;
                                }
                                itr->next = temp_url;
                            }
                            else
                            {
                                g_srv_mms_use_detail_parser_cntx.url_offset = temp_url;
                            }
                            last_url = temp_url;
                            end += mmi_ucs2strlen((PS8) pattern[count]);
                            break;
                        }
                        count++;
                    }

                }
            }
            end += 1;
            if (str_length == 0)
            {
                start = end;
                count = 0;
            }
        }
        /* remove invalid trailing char */
        while (no_length >= SRV_MMS_MIN_PHONE_NUM_LEN && (*(end - 1) == L'w' || *(end - 1) == L'p' ||
                                                          *(end - 1) == L'W' || *(end - 1) == L'P' || *(end - 1) == L'('
                                                          || *(end - 1) == L')' || *(end - 1) == L'-'))
        {
            if (*(end - 1) == L'w' || *(end - 1) == L'p' || *(end - 1) == L'W' || *(end - 1) == L'P')
            {
                no_length -= 1;
            }
            str_length -= 1;
            end -= 1;
        }
        /* remove invalid heading char */
        while (no_length >= SRV_MMS_MIN_PHONE_NUM_LEN && (*start == L'-' || *start == L')' ||
                                                          (*start == '(' &&
                                                           srv_mms_is_lp_paired_wchar(start, str_length) == MMI_FALSE)))
        {
            str_length -= 1;
            start += 1;
        }

        /* The number sequence is too long to be a valid PLMN number */
        if ((*start != '+' && no_length >= SRV_MMS_MAX_PHONE_NUM_LEN) ||
            (*start == '+' && no_length > SRV_MMS_MAX_PHONE_NUM_LEN))
        {
            while (srv_mms_is_valid_phoneno_wchar(*end, MMI_TRUE) == MMI_TRUE)
            {
                end++;
            }
            if (other != NULL)
            {
                temp_free = other;
                g_srv_mms_use_detail_parser_cntx.num_offset = other = other->next;
                g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp_free);
                temp_free = NULL;
            }

            else
            {
                data = end; /* continue from the following char */
                len = dataLen - (end - input_other);
            }
            continue;
        }
        else if ((*start != '+' && no_length >= SRV_MMS_MIN_PHONE_NUM_LEN) ||
                 (*start == '+' && no_length > SRV_MMS_MIN_PHONE_NUM_LEN))
        {
            U16 tmp = *end;
            MMI_BOOL is_duplicated = MMI_FALSE;
            U16 *string_temp = NULL;

            *end = L'\0';
            if (is_remove_duplicate)
            {
                addr = g_srv_mms_use_detail_parser_cntx.number_list;
                while (addr != NULL && addr->next != NULL)
                {
                    string_temp =
                        g_srv_mms_use_detail_parser_cntx.req_data->mem_alloc_fn(addr->size * ENCODING_LENGTH + 2);
                    if (string_temp == NULL)
                    {
                        srv_mms_deinit_use_detail_srv();
                        return SRV_MMS_VIEWER_OUT_OF_MEM;
                    }
                    memset(string_temp, 0, addr->size * ENCODING_LENGTH + 2);
                    mmi_ucs2ncpy((S8*) string_temp, (S8*) (input_data + addr->offset), addr->size);
                    if (app_ucs2_wcsicmp((U16*) string_temp, (U16*) start) == 0)
                    {
                        is_duplicated = MMI_TRUE;
                        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(string_temp);
                        break;
                    }
                    addr = addr->next;
                    g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(string_temp);
                }
                if (addr != NULL)
                {
                    string_temp =
                        g_srv_mms_use_detail_parser_cntx.req_data->mem_alloc_fn(addr->size * ENCODING_LENGTH + 2);
                    if (string_temp == NULL)
                    {
                        srv_mms_deinit_use_detail_srv();
                        return SRV_MMS_VIEWER_OUT_OF_MEM;
                    }
                    memset(string_temp, 0, addr->size * ENCODING_LENGTH + 2);
                    mmi_ucs2ncpy((S8*) string_temp, (S8*) (input_data + addr->offset), addr->size);
                    if (app_ucs2_wcsicmp((U16*) string_temp, (U16*) start) == 0)
                    {
                        is_duplicated = MMI_TRUE;
                    }
                    g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(string_temp);
                    string_temp = NULL;
                }
                if (last_email != NULL)
                {
                    is_overlap = srv_mms_check_for_overlap(start, input_data + last_email->pos, SRV_MMS_TYPE_EMAIL);
                    if (is_overlap)
                    {
                        is_overlap = srv_mms_check_valid_email(data, start, len);
                    }
                }
                if (is_overlap != MMI_TRUE && last_url != NULL)
                {
                    is_overlap = srv_mms_check_for_overlap(start, input_data + last_url->pos, SRV_MMS_TYPE_URL);
                }
            }
            if (mmi_ucs2strlen((PS8) start) > SRV_MMS_MAX_PHONE_NUM_LEN)
            {
                is_length_exceed = MMI_TRUE;
            }
            else
            {
                is_length_exceed = MMI_FALSE;
            }
            if (is_remove_duplicate == MMI_FALSE || is_duplicated == MMI_FALSE && is_overlap == MMI_FALSE &&
                is_length_exceed == FALSE)
            {
                /* Write Code For Dumping offset into memory */
                address = g_srv_mms_use_detail_parser_cntx.req_data->mem_alloc_fn(sizeof(srv_mms_number_detail));
                if (address == NULL)
                {
                    srv_mms_deinit_use_detail_srv();
                    return SRV_MMS_VIEWER_OUT_OF_MEM;
                }
                memset(address, 0, sizeof(srv_mms_number_detail));
                address->offset = ((S32) start - (S32) input_data) / 2;
                address->size = mmi_ucs2strlen((PS8) start);
                address->next = NULL;
                address->prev = NULL;
                if (addr != NULL)
                {
                    addr->next = address;
                    address->prev = addr;
                }
                else
                {
                    g_srv_mms_use_detail_parser_cntx.number_list = address;
                }
                g_srv_mms_use_detail_parser_cntx.parsed_num++;
            }
            *end = tmp;
            if (other != NULL)
            {
                temp_free = other;
                g_srv_mms_use_detail_parser_cntx.num_offset = other = other->next;
                g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp_free);
                temp_free = NULL;
                data = NULL;
            }
            else
            {
                data = end;
                len = dataLen - (end - input_other);
            }
            g_srv_mms_use_detail_parser_cntx.is_num_bet_email = MMI_TRUE;
            continue;
        }
        else
        {
            if (other != NULL)
            {
                temp_free = other;
                g_srv_mms_use_detail_parser_cntx.num_offset = other = other->next;
                g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp_free);
                temp_free = NULL;
            }

            else
            {
                data = end; /* continue from the following char */
                len = dataLen - (end - input_other);
            }
            continue;
        }
    }
    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    kal_get_time((kal_uint32*) & time2);
    time3 = kal_ticks_to_milli_secs(time2 - time1);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TIME_NUMBER_WHILE_LOOP, time3);
    time1 = 0;
    time2 = 0;
    time3 = 0;
    // #endif
    if (data && data - input_data >= (SRV_MMS_PARSED_TXT_BUF_UCS2_SIZE * g_srv_mms_use_detail_parser_cntx.count_blocks)
        && other == NULL && (data - input_data) < dataLen_other / 2)
    {
        g_srv_mms_use_detail_parser_cntx.count_blocks++;
        g_srv_mms_use_detail_parser_cntx.num_before_blk = address;
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_EXIT_NUMBER_SEARCH_BLOCK);
        return SRV_MMS_VIEWER_PARSE_BLOCK;
    }
    else if (g_srv_mms_use_detail_parser_cntx.other_parse == MMI_TRUE)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_EXIT_NUMBER_SEARCH_BLOCK);
        return SRV_MMS_VIEWER_PARSE_BLOCK;
    }
    if (g_srv_mms_use_detail_parser_cntx.order_type == SRV_MMS_USE_NEU)
    {
        if (g_srv_mms_use_detail_parser_cntx.email_offset != NULL &&
            g_srv_mms_use_detail_parser_cntx.other_parse == MMI_FALSE)
        {
            ret_val_parse = srv_mms_parse_emails_from_unicode(NULL);
        }
        if (g_srv_mms_use_detail_parser_cntx.url_offset != NULL &&
            g_srv_mms_use_detail_parser_cntx.other_parse == MMI_FALSE)
        {
            ret_val_parse = srv_mms_parse_urls_from_unicode(NULL, 0);
        }
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_EXIT_NUMBER_SEARCH);
    return ret_val_parse;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_parse_emails_from_unicode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_start       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
srv_mms_viewer_result_enum srv_mms_parse_emails_from_unicode(U16 *new_start)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0, dataLen_other = 0, dataLen = 0;
    srv_mms_viewer_result_enum ret_val_parse = SRV_MMS_VIEWER_PARSE_SUCCESS;
    MMI_BOOL normal = MMI_TRUE;
    U16 *data = NULL, *input_data = NULL;
    srv_mms_offset *temp_free = NULL, *other = NULL;
    srv_mms_detail *address = NULL, *addr = NULL, *last_address = NULL;
    MMI_BOOL is_remove_duplicate = MMI_TRUE;
    U16 *input_other = NULL;

    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    S32 time1 = 0, time2 = 0, time3 = 0;

    // #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_ENTER_EMAIL_SEARCH);
    g_srv_mms_use_detail_parser_cntx.other_parse_count = 0;
    g_srv_mms_use_detail_parser_cntx.other_parse = MMI_FALSE;
    dataLen_other = dataLen = g_srv_mms_use_detail_parser_cntx.req_data->dataLen;
    other = g_srv_mms_use_detail_parser_cntx.email_offset;
    /* UCS2 character number */
    dataLen = dataLen / 2;
    input_other = data = input_data = g_srv_mms_use_detail_parser_cntx.req_data->input_data;
    if (g_srv_mms_use_detail_parser_cntx.last_offset != NULL && !other)
    {
        data = g_srv_mms_use_detail_parser_cntx.last_offset;
        dataLen = dataLen - (data - input_data);
        input_other = data;
        g_srv_mms_use_detail_parser_cntx.last_offset = NULL;
    }
    else if (g_srv_mms_use_detail_parser_cntx.email_other_last_offset)
    {
        other = g_srv_mms_use_detail_parser_cntx.email_other_last_offset;
        g_srv_mms_use_detail_parser_cntx.email_other_last_offset = NULL;
    }
    len = dataLen;
    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    kal_get_time((kal_uint32*) & time1);
    // #endif
    while (data - input_other < dataLen || other != NULL)
    {
        U16 *start = NULL;
        U16 *end = NULL;
        S32 length_covered = 0;
        MMI_BOOL is_block = MMI_FALSE;

        if (data - input_data >= (SRV_MMS_PARSED_TXT_BUF_UCS2_SIZE * g_srv_mms_use_detail_parser_cntx.count_blocks) &&
            other == NULL)
        {
            g_srv_mms_use_detail_parser_cntx.last_offset = data;
            break;
        }
        else if (other != NULL && g_srv_mms_use_detail_parser_cntx.other_parse_count > SRV_MMS_MAX_OTHER_PARSED_COUNT)
        {
            g_srv_mms_use_detail_parser_cntx.email_other_last_offset = other;
            g_srv_mms_use_detail_parser_cntx.order_type = SRV_MMS_USE_ENU;
            g_srv_mms_use_detail_parser_cntx.other_parse = MMI_TRUE;
            break;
        }
        if (other == NULL && normal == MMI_FALSE)
        {
            break;
        }
        if (other != NULL)
        {
            start = input_data + other->pos;
            g_srv_mms_use_detail_parser_cntx.other_parse_count++;
            /* if(data > start)
               {
               data = start;
               } */
            normal = MMI_FALSE;
        }
        else
        {
            if (new_start != NULL)
            {
                start = new_start;
                new_start = NULL;
            }
            else
            {
                start = (PU16) srv_mms_strchr(data, (S32) L'@', last_address, &is_block, &length_covered);
            }
        }
        end = start + mmi_ucs2strlen((PS8) L"@");
        if (start == NULL)  /* not found */
        {
            if (is_block)
            {
                if (other == NULL)
                {
                    data = input_data + length_covered;
                    g_srv_mms_use_detail_parser_cntx.last_offset = data + 1;
                }
            }
            break;
        }
        else if (start == data || srv_mms_is_valid_email_local_part_wchar(*(start - 1)) == MMI_FALSE || *(start - 1) == L'.')   /* '.' should not be the last character in the local-part */
        {
            if (other != NULL)
            {
                temp_free = other;
                g_srv_mms_use_detail_parser_cntx.email_offset = other = other->next;
                g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp_free);
                temp_free = NULL;
            }
            else
            {
                data = start + mmi_ucs2strlen((PS8) L"@");  /* continue from the end of the pattern */
                len = dataLen - (data - input_data);
            }
            continue;
        }
        else
        {
            while ((start - 1 >= data) && srv_mms_is_valid_email_local_part_wchar(*(start - 1)))
            {
                start--;
            }
            if (start < data)
            {
                EXT_ASSERT(0, 0, 0, 0);
            }

            while (*start == L'.')  /* '.' should not be the first character in the local-part */
            {
                start++;
            }

            /* we get the begining of URL string and go to find its end */
            while ((end - data) < len && srv_mms_is_valid_email_domain_name_wchar(*end))
            {
                end++;
            }
            while (*(end - 1) == L'.')  /* removing trailing dot(s) */
            {
                end--;
            }

            if ((other && end == input_data + other->pos + mmi_ucs2strlen((PS8) L"@")) || (!other && end == app_ucs2_strstr((PU16) data, L"@") + mmi_ucs2strlen((PS8) L"@")))   /* host string is NULL */
            {
                if ((end - data) < len)
                {
                    if (other != NULL)
                    {
                        temp_free = other;
                        g_srv_mms_use_detail_parser_cntx.email_offset = other = other->next;
                        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp_free);
                        temp_free = NULL;
                    }
                    data = end; /* continue from the following char */
                    len = dataLen - (end - input_other);
                    continue;
                }
                else
                {
                    break;
                }
            }
            else if ((end - data) <= len)
            {
                U16 tmp = *end;
                MMI_BOOL is_duplicated;
                U16 *string_temp = NULL;

                *end = L'\0';
                is_duplicated = MMI_FALSE;
                if (is_remove_duplicate)
                {
                    addr = g_srv_mms_use_detail_parser_cntx.email_list;
                    while (addr != NULL && addr->next != NULL)
                    {
                        string_temp =
                            g_srv_mms_use_detail_parser_cntx.req_data->mem_alloc_fn(addr->size * ENCODING_LENGTH + 2);
                        if (string_temp == NULL)
                        {
                            srv_mms_deinit_use_detail_srv();
                            return SRV_MMS_VIEWER_OUT_OF_MEM;
                        }
                        memset(string_temp, 0, addr->size * ENCODING_LENGTH + 2);
                        mmi_ucs2ncpy((S8*) string_temp, (S8*) (input_data + addr->offset), addr->size);
                        if (app_ucs2_wcsicmp((U16*) string_temp, (U16*) start) == 0)
                        {
                            is_duplicated = MMI_TRUE;
                            g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(string_temp);
                            string_temp = NULL;
                            break;
                        }
                        addr = addr->next;
                        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(string_temp);
                        string_temp = NULL;
                    }
                    if (addr != NULL)
                    {
                        string_temp =
                            g_srv_mms_use_detail_parser_cntx.req_data->mem_alloc_fn(addr->size * ENCODING_LENGTH + 2);
                        if (string_temp == NULL)
                        {
                            srv_mms_deinit_use_detail_srv();
                            return SRV_MMS_VIEWER_OUT_OF_MEM;
                        }
                        memset(string_temp, 0, addr->size * ENCODING_LENGTH + 2);
                        mmi_ucs2ncpy((S8*) string_temp, (S8*) (input_data + addr->offset), addr->size);
                        if (app_ucs2_wcsicmp((U16*) string_temp, (U16*) start) == 0)
                        {
                            is_duplicated = MMI_TRUE;
                        }
                        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(string_temp);
                        string_temp = NULL;
                    }
                }

                if (!is_remove_duplicate || !is_duplicated)
                {
                    /* Write Code For Dumping offset into memory */
                    address = g_srv_mms_use_detail_parser_cntx.req_data->mem_alloc_fn(sizeof(srv_mms_detail));
                    if (address == NULL)
                    {
                        srv_mms_deinit_use_detail_srv();
                        return SRV_MMS_VIEWER_OUT_OF_MEM;
                    }
                    memset(address, 0, sizeof(srv_mms_detail));
                    address->offset = ((S32) start - (S32) input_data) / 2;
                    address->size = mmi_ucs2strlen((PS8) start);
                    address->next = NULL;
                    if (addr != NULL)
                    {
                        addr->next = address;
                        last_address = addr->next;
                    }
                    else
                    {
                        g_srv_mms_use_detail_parser_cntx.email_list = address;
                        last_address = g_srv_mms_use_detail_parser_cntx.email_list;
                    }
                    g_srv_mms_use_detail_parser_cntx.parsed_email++;
                }
                *end = tmp;
                if (other != NULL)
                {
                    temp_free = other;
                    g_srv_mms_use_detail_parser_cntx.email_offset = other = other->next;
                    g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp_free);
                    temp_free = NULL;
                }
                else
                {
                    data = end; /* continue from the following char */
                    len = dataLen - (end - input_other);
                }
                continue;
            }
            else
            {
                break;
            }
        }
    }
    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    kal_get_time((kal_uint32*) & time2);
    time3 = kal_ticks_to_milli_secs(time2 - time1);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TIME_EMAIL_WHILE_LOOP, time3);
    time1 = 0;
    time2 = 0;
    time3 = 0;
    // #endif
    if (data && data - input_data >= (SRV_MMS_PARSED_TXT_BUF_UCS2_SIZE * g_srv_mms_use_detail_parser_cntx.count_blocks)
        && other == NULL && (data - input_data) < dataLen_other / 2)
    {
        g_srv_mms_use_detail_parser_cntx.count_blocks++;
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_EXIT_EMAIL_SEARCH_BLOCK);
        return SRV_MMS_VIEWER_PARSE_BLOCK;
    }
    else if (g_srv_mms_use_detail_parser_cntx.other_parse == MMI_TRUE)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_EXIT_EMAIL_SEARCH_BLOCK);
        return SRV_MMS_VIEWER_PARSE_BLOCK;
    }
    if (g_srv_mms_use_detail_parser_cntx.order_type == SRV_MMS_USE_ENU)
    {
        if (g_srv_mms_use_detail_parser_cntx.num_offset != NULL &&
            g_srv_mms_use_detail_parser_cntx.other_parse == MMI_FALSE)
        {
            ret_val_parse = srv_mms_parse_numbers_from_unicode(NULL);
        }
        if (g_srv_mms_use_detail_parser_cntx.url_offset != NULL &&
            g_srv_mms_use_detail_parser_cntx.other_parse == MMI_FALSE)
        {
            ret_val_parse = srv_mms_parse_urls_from_unicode(NULL, 0);
        }
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_EXIT_EMAIL_SEARCH);
    return ret_val_parse;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_parse_urls_from_unicode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  new_start       [?]         [?]
 *  url_type        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_mms_viewer_result_enum srv_mms_parse_urls_from_unicode(U16 *new_start, U16 url_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0;
    S32 dataLen_other = 0, dataLen = 0;
    srv_mms_viewer_result_enum ret_val_parse = SRV_MMS_VIEWER_PARSE_SUCCESS;
    U16 *data = NULL, *input_data = NULL;
    U16 *scheme[SRV_MMS_USE_DETAILS_URL_SCHEME_NO] = {SRV_MMS_URL_UNICODE_SCHEME1,
        SRV_MMS_URL_UNICODE_SCHEME2,
        SRV_MMS_URL_UNICODE_SCHEME3
    };
    U16 *pattern[SRV_MMS_USE_DETAILS_URL_PATTERN_NO] = {SRV_MMS_URL_UNICODE_PATTERN_1,
        SRV_MMS_URL_UNICODE_PATTERN_2,
        SRV_MMS_URL_UNICODE_PATTERN_3,
        SRV_MMS_URL_UNICODE_PATTERN_4
    };
    MMI_BOOL normal = MMI_TRUE;
    srv_mms_detail *address = NULL, *addr = NULL;
    MMI_BOOL is_remove_duplicate = MMI_TRUE, other_parse = MMI_FALSE;
    srv_mms_url_offset *temp_free = NULL, *other = NULL;
    srv_mms_offset *temp = NULL;
    U16 *input_other = NULL;

    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    S32 time1 = 0, time2 = 0, time3 = 0;

    // #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_ENTER_URL_SEARCH);
    g_srv_mms_use_detail_parser_cntx.other_parse_count = 0;
    g_srv_mms_use_detail_parser_cntx.other_parse = MMI_FALSE;
    dataLen_other = dataLen = g_srv_mms_use_detail_parser_cntx.req_data->dataLen;
    /* UCS2 character number */
    dataLen = dataLen / 2;
    other = g_srv_mms_use_detail_parser_cntx.url_offset;
    input_other = data = input_data = g_srv_mms_use_detail_parser_cntx.req_data->input_data;
    if (g_srv_mms_use_detail_parser_cntx.last_offset != NULL && !other)
    {
        data = g_srv_mms_use_detail_parser_cntx.last_offset;
        dataLen = dataLen - (data - input_data);
        input_other = data;
        g_srv_mms_use_detail_parser_cntx.last_offset = NULL;
    }
    else if (g_srv_mms_use_detail_parser_cntx.url_other_last_offset)
    {
        other = g_srv_mms_use_detail_parser_cntx.url_other_last_offset;
        g_srv_mms_use_detail_parser_cntx.url_other_last_offset = NULL;
    }
    len = dataLen;
    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    kal_get_time((kal_uint32*) & time1);
    // #endif
    while ((data - input_other) < dataLen || other != NULL)
    {
        U16 *start = NULL, *end = NULL;
        S32 i = 0, type = 0;

        if (data - input_data >= (SRV_MMS_PARSED_TXT_BUF_UCS2_SIZE * g_srv_mms_use_detail_parser_cntx.count_blocks) &&
            other == NULL)
        {
            g_srv_mms_use_detail_parser_cntx.last_offset = data;
            break;
        }
        else if (other != NULL && g_srv_mms_use_detail_parser_cntx.other_parse_count > SRV_MMS_MAX_OTHER_PARSED_COUNT)
        {
            g_srv_mms_use_detail_parser_cntx.url_other_last_offset = other;
            g_srv_mms_use_detail_parser_cntx.order_type = SRV_MMS_USE_UNE;
            g_srv_mms_use_detail_parser_cntx.other_parse = MMI_TRUE;
            break;
        }
        if (normal == MMI_FALSE && other == NULL)
        {
            break;
        }
        if (other != NULL)
        {
            start = input_data + other->pos;
            g_srv_mms_use_detail_parser_cntx.other_parse_count++;
            normal = MMI_FALSE;
            type = other->type;
        }
        else
        {
            if (new_start != NULL)
            {
                start = new_start;
                new_start = NULL;
                type = url_type;
            }
            else
            {
                /* for(i  = 0; i < SRV_MMS_USE_DETAILS_URL_PATTERN_NO; i++)   find the 1st show-up pattern */
                {
                    U16 *new_start_one = NULL;
                    srv_mms_viewer_result_enum is_block = SRV_MMS_VIEWER_OK;
                    S32 length_covered = 0;

                    new_start_one =
                        (PU16) srv_mms_strstr(data, other_parse, &type, address, &is_block, &length_covered);
                    if (new_start_one != NULL)
                    {
                        /* new_start_one = data + (int)(new_start_one - data_lc); */
                        if (start == NULL)
                        {
                            start = new_start_one;
                        }
                        else if ((S32) new_start_one < (S32) start)
                        {
                            start = new_start_one;
                        }
                    }
                    else if (is_block == SRV_MMS_VIEWER_PARSE_BLOCK)
                    {
                        if (other == NULL)
                        {
                            data = input_data + length_covered;
                            g_srv_mms_use_detail_parser_cntx.last_offset = data + 1;
                            break;
                        }
                    }
                    else if (is_block == SRV_MMS_VIEWER_OUT_OF_MEM)
                    {
                        return SRV_MMS_VIEWER_OUT_OF_MEM;
                    }
                    else
                    {
                        other_parse = MMI_TRUE;
                    }

                }
            }
        }

        /* mem_free_fn(data_lc); */
        if (start == NULL)  /* not found */
        {
            break;
        }
        else if ((type == 0 || type == 1) && (start == data || srv_mms_is_valid_url_scheme_wchar(*(start - 1)) == MMI_FALSE))   /* unknown scheme */
        {
            if (other != NULL)
            {
                temp_free = other;
                g_srv_mms_use_detail_parser_cntx.url_offset = other = other->next;
                g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp_free);
                temp_free = NULL;
            }
            else
            {
                data = start + mmi_ucs2strlen((PS8) pattern[type]);     /* continue from the end of the pattern */
                len = dataLen - (data - input_data);
            }
            continue;
        }
        else
        {
            end = start + mmi_ucs2strlen((PS8) pattern[type]);

            if (type == 0 || type == 1) /* "://" or ":\\\\" */
            {
                MMI_BOOL is_known_scheme = MMI_FALSE;

                /* Check known scheme */
                for (i = 0; i < SRV_MMS_USE_DETAILS_URL_SCHEME_NO; i++)
                {
                    int len = mmi_ucs2strlen((PS8) scheme[i]);

                    if (mmi_ucs2nicmp((PS8) (start - len), (PS8) scheme[i], len) == 0)
                    {
                        start -= len;
                        is_known_scheme = MMI_TRUE;
                        break;
                    }
                }

                /* Unknown scheme */
                if (!is_known_scheme)
                {
                    if (other != NULL)
                    {
                        temp_free = other;
                        g_srv_mms_use_detail_parser_cntx.url_offset = other = other->next;
                        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp_free);
                        temp_free = NULL;
                    }
                    else
                    {
                        data = end; /* continue from the end of the pattern */
                        len = dataLen - (data - input_data);
                    }
                    continue;

                    /*                    while((start - 1 >= data) && applib_is_valid_url_scheme_wchar(*(start - 1)))
                       {
                       start--;
                       } */
                }
                if (start < data)
                {
                    ASSERT(start >= data);
                }
            }

            /* we get the begining of URL string and go to find its end */
            while ((end - data) < len && srv_mms_is_valid_url_wchar(*end))
            {
                if (mmi_ucs2nicmp((PS8) end, (PS8) SRV_MMS_URL_UNICODE_PATTERN_2, 3) == 0)      /* for fault tolerance */
                {
                    end += 3;
                }
                else
                {
                    if (*end == '@' && other == NULL)
                    {
                        temp =
                            (srv_mms_offset*) g_srv_mms_use_detail_parser_cntx.req_data->
                            mem_alloc_fn(sizeof(srv_mms_offset));
                        if (temp == NULL)
                        {
                            srv_mms_deinit_use_detail_srv();
                            return SRV_MMS_VIEWER_OUT_OF_MEM;
                        }
                        memset(temp, 0, sizeof(srv_mms_offset));
                        temp->pos = ((S32) end - (S32) input_data) / 2;
                        temp->next = NULL;
                        if (g_srv_mms_use_detail_parser_cntx.email_offset)
                        {
                            srv_mms_offset *itr = NULL;

                            itr = g_srv_mms_use_detail_parser_cntx.email_offset;
                            while (itr->next != NULL)
                            {
                                itr = itr->next;
                            }
                            itr->next = temp;
                        }
                        else
                        {
                            g_srv_mms_use_detail_parser_cntx.email_offset = temp;
                        }
                    }
                    end++;
                }
            }
            if ((end - data) <= len)
            {
                U16 tmp = *end;
                MMI_BOOL is_duplicated = MMI_FALSE;

                *end = L'\0';

                {
                    /* Remove invalied characters */
                    U16 *end_of_valid_char = end - 1;

                    while (end_of_valid_char > start &&
                           srv_mms_is_valid_url_last_wchar(*end_of_valid_char) == MMI_FALSE)
                    {
                        end_of_valid_char--;
                    }
                    if (end_of_valid_char > start && end_of_valid_char < end)
                    {
                        end_of_valid_char++;
                        *end_of_valid_char = L'\0';
                    }
                }

                if (is_remove_duplicate)
                {
                    U16 *string_temp = NULL;

                    addr = g_srv_mms_use_detail_parser_cntx.url_list;
                    while (addr != NULL && addr->next != NULL)
                    {
                        string_temp =
                            g_srv_mms_use_detail_parser_cntx.req_data->mem_alloc_fn(addr->size * ENCODING_LENGTH + 2);
                        if (string_temp == NULL)
                        {
                            srv_mms_deinit_use_detail_srv();
                            return SRV_MMS_VIEWER_OUT_OF_MEM;
                        }
                        memset(string_temp, 0, addr->size * ENCODING_LENGTH + 2);
                        mmi_ucs2ncpy((S8*) string_temp, (S8*) (input_data + addr->offset), addr->size);
                        if (app_ucs2_wcsicmp((U16*) string_temp, (U16*) start) == 0)
                        {
                            is_duplicated = MMI_TRUE;
                            g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(string_temp);
                            break;
                        }
                        addr = addr->next;
                        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(string_temp);
                    }
                    if (addr != NULL)
                    {
                        string_temp =
                            g_srv_mms_use_detail_parser_cntx.req_data->mem_alloc_fn(addr->size * ENCODING_LENGTH + 2);
                        if (string_temp == NULL)
                        {
                            srv_mms_deinit_use_detail_srv();
                            return SRV_MMS_VIEWER_OUT_OF_MEM;
                        }
                        memset(string_temp, 0, addr->size * ENCODING_LENGTH + 2);
                        mmi_ucs2ncpy((S8*) string_temp, (S8*) (input_data + addr->offset), addr->size);
                        if (app_ucs2_wcsicmp((U16*) string_temp, (U16*) start) == 0)
                        {
                            is_duplicated = MMI_TRUE;
                        }
                        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(string_temp);
                        string_temp = NULL;
                    }
                }

                if (is_remove_duplicate == MMI_FALSE || is_duplicated == MMI_FALSE)
                {
                    address = g_srv_mms_use_detail_parser_cntx.req_data->mem_alloc_fn(sizeof(srv_mms_detail));
                    if (address == NULL)
                    {
                        srv_mms_deinit_use_detail_srv();
                        return SRV_MMS_VIEWER_OUT_OF_MEM;
                    }
                    memset(address, 0, sizeof(srv_mms_detail));
                    address->offset = ((S32) start - (S32) input_data) / 2;
                    address->size = mmi_ucs2strlen((PS8) start);
                    address->next = NULL;
                    if (addr != NULL)
                    {
                        addr->next = address;
                    }
                    else
                    {
                        g_srv_mms_use_detail_parser_cntx.url_list = address;
                    }
                    g_srv_mms_use_detail_parser_cntx.parsed_url++;

                }
                *end = tmp;
                if (other != NULL)
                {
                    temp_free = other;
                    g_srv_mms_use_detail_parser_cntx.url_offset = other = other->next;
                    g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp_free);
                    temp_free = NULL;
                }
                else
                {
                    /* continue from the following char */
                    data = end;
                    len = dataLen - (end - input_other);
                }
                continue;
            }
            else
            {
                break;
            }
        }
    }
    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    kal_get_time((kal_uint32*) & time2);
    time3 = kal_ticks_to_milli_secs(time2 - time1);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TIME_URL_WHILE_LOOP, time3);
    time1 = 0;
    time2 = 0;
    time3 = 0;
    // #endif

    if (data && data - input_data >= (SRV_MMS_PARSED_TXT_BUF_UCS2_SIZE * g_srv_mms_use_detail_parser_cntx.count_blocks)
        && other == NULL && (data - input_data) < dataLen_other / 2)
    {
        g_srv_mms_use_detail_parser_cntx.count_blocks++;
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_EXIT_URL_SEARCH_BLOCK);
        return SRV_MMS_VIEWER_PARSE_BLOCK;
    }
    else if (g_srv_mms_use_detail_parser_cntx.other_parse == MMI_TRUE)
    {
        MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_EXIT_URL_SEARCH_BLOCK);
        return SRV_MMS_VIEWER_PARSE_BLOCK;
    }
    if (g_srv_mms_use_detail_parser_cntx.order_type == SRV_MMS_USE_UNE)
    {
        if (g_srv_mms_use_detail_parser_cntx.num_offset != NULL &&
            g_srv_mms_use_detail_parser_cntx.other_parse == MMI_FALSE)
        {
            ret_val_parse = srv_mms_parse_numbers_from_unicode(NULL);
        }
        if (g_srv_mms_use_detail_parser_cntx.email_offset != NULL &&
            g_srv_mms_use_detail_parser_cntx.other_parse == MMI_FALSE)
        {
            ret_val_parse = srv_mms_parse_emails_from_unicode(NULL);
        }
    }
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_EXIT_URL_SEARCH);
    return ret_val_parse;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_lp_paired_wchar
 * DESCRIPTION
 *  This internal function is used to check if the left parenthesis '(' is paired with
 *  a right parenthesis ')'
 * PARAMETERS
 *  lp_pos      [IN]        Left parenthesis position
 *  length      [IN]        The string length to check (string started with the lp)
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL srv_mms_is_lp_paired_wchar(U16 *lp_pos, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const U16 *ch = lp_pos;
    U16 lp_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (length > 0)
    {
        if (*ch == L'(')
        {
            lp_count++;
        }
        else if (*ch == L')')
        {
            lp_count--;
        }
        length--;
        ch++;
    }
    return ((lp_count == 0) ? MMI_TRUE : MMI_FALSE);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_valid_phoneno_wchar
 * DESCRIPTION
 *  This internal function is used to check if input char is valid phone number character
 * PARAMETERS
 *  ch                          [IN]        Character being checked
 *  is_written_char_valid       [IN]        Count written char,ex. '-','(',')', as valid char
 * RETURNS
 *  MMI_TRUE or MMI_FALSE
 *****************************************************************************/
static MMI_BOOL srv_mms_is_valid_phoneno_wchar(U16 ch, MMI_BOOL is_written_char_valid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 phoneno_special_chars[] = {L'+', L'w', L'p', L'W', L'P' };
    U16 phoneno_written_chars[] = {L'-', L'(', L')' };

    S32 num_phoneno_special_chars = (sizeof(phoneno_special_chars) / 2);
    S32 num_phoneno_written_chars = (sizeof(phoneno_written_chars) / 2);
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch != 0)
    {
        if (ch >= L'0' && ch <= L'9')
        {
            return MMI_TRUE;
        }

        for (i = 0; i < num_phoneno_special_chars; i++)
        {
            if (ch == phoneno_special_chars[i])
            {
                return MMI_TRUE;
            }
        }

        if (is_written_char_valid == MMI_TRUE)
        {
            for (i = 0; i < num_phoneno_written_chars; i++)
            {
                if (ch == phoneno_written_chars[i])
                {
                    return MMI_TRUE;
                }
            }
        }

        return MMI_FALSE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_valid_email_local_part_wchar
 * DESCRIPTION
 *  This internal function is used to check if input char is valid Email local part character
 * PARAMETERS
 *  ch      [IN]        Character being checked
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static MMI_BOOL srv_mms_is_valid_email_local_part_wchar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((ch >= L'a' && ch <= L'z') || (ch >= L'A' && ch <= L'Z') || (ch >= L'0' && ch <= L'9'))
    {
        return MMI_TRUE;
    }
    switch (ch)
    {
            /* Reference RFC 2822 */
        case L'.':
        case L'!':
        case L'#':
        case L'$':
        case L'%':
        case L'&':
        case L'\'':
        case L'*':
        case L'+':
        case L'-':
        case L'/':
        case L'=':
        case L'?':
        case L'^':
        case L'_':
        case L'`':
        case L'{':
        case L'|':
        case L'}':
        case L'~':
            return MMI_TRUE;
        default:
            return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_valid_email_domain_name_wchar
 * DESCRIPTION
 *  This internal function is used to check if input char is valid Email character
 * PARAMETERS
 *  ch      [IN]        Character being checked
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static MMI_BOOL srv_mms_is_valid_email_domain_name_wchar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!((ch >= L'a' && ch <= L'z') ||
          (ch >= L'A' && ch <= L'Z') || (ch >= L'0' && ch <= L'9') || (ch == L'-') || (ch == L'.')))
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_valid_url_scheme_wchar
 * DESCRIPTION
 *  This internal function is used to check if input char is valid URL scheme character
 * PARAMETERS
 *  ch      [IN]        Character being checked
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static MMI_BOOL srv_mms_is_valid_url_scheme_wchar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch != 0)
    {
        if ((ch >= L'a' && ch <= L'z') || (ch >= L'A' && ch <= L'Z'))
        {
            return MMI_TRUE;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_valid_url_wchar
 * DESCRIPTION
 *  This internal function is used to check if input char is valid URL character
 * PARAMETERS
 *  ch      [IN]        Character being checked
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
MMI_BOOL srv_mms_is_valid_url_wchar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 url_special_chars[] =
        {L':', L';', L'/', L'\\', L'.', L',', L'#', L'?', L'$', L'+', L'@', L'&', L'=', L'%', L'-', L'_', L'(', L')',
        L'[', L']', L'{', L'}', L'<', L'>', L'`', L'~', L'!', L'^', L'*', L'|', L'"', L'\''
    };
    S32 num_url_special_chars = (sizeof(url_special_chars) / 2);
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ch != 0)
    {
        if ((ch >= L'a' && ch <= L'z') || (ch >= L'A' && ch <= L'Z') || (ch >= L'0' && ch <= L'9'))
        {
            return MMI_TRUE;
        }
        else
        {
            for (i = 0; i < num_url_special_chars; i++)
            {
                if (ch == url_special_chars[i])
                {
                    return MMI_TRUE;
                }
            }
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_valid_url_last_wchar
 * DESCRIPTION
 *  This internal function is used to check if input char is valid last URL character
 * PARAMETERS
 *  ch      [IN]        Character being checked
 * RETURNS
 *  KAL_TRUE or KAL_FALSE
 *****************************************************************************/
static MMI_BOOL srv_mms_is_valid_url_last_wchar(U16 ch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 url_invlid_chars[] =
        {L'(', L')', L'[', L']', L'{', L'}', L'<', L'>', L',', L'.', L'"', L'\'', L'?', L':', L';', L'-' };
    S32 num_url_invalid_chars = (sizeof(url_invlid_chars) / 2);
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mms_is_valid_url_wchar(ch) == MMI_TRUE)
    {
        for (i = 0; i < num_url_invalid_chars; i++)
        {
            if (ch == url_invlid_chars[i])
            {
                return MMI_FALSE;
            }
        }
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_strchr
 * DESCRIPTION
 *  search for some character in the given string
 * PARAMETERS
 *  s                   [?]         [?]
 *  c                   [IN]        
 *  address_node        [?]         [?]
 *  is_block            [?]         [?]
 *  length              [?]         [?]
 *  input_data(?)       [IN](?)
 * RETURNS
 *  
 *****************************************************************************/
static U16 *srv_mms_strchr(U16 *s, S32 c, srv_mms_detail *address_node, MMI_BOOL *is_block, S32 *length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_offset *temp = NULL, *last_num = NULL, *addr;
    srv_mms_url_offset *temp_url = NULL, *last_url = NULL;
    S32 no_length = 0, count = 0, offset = 0;
    U16 *pattern[SRV_MMS_USE_DETAILS_URL_PATTERN_NO] = {SRV_MMS_URL_UNICODE_PATTERN_1,
        SRV_MMS_URL_UNICODE_PATTERN_2,
        SRV_MMS_URL_UNICODE_PATTERN_3,
        SRV_MMS_URL_UNICODE_PATTERN_4
    };
    MMI_BOOL is_overlap = MMI_FALSE;

    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    S32 time1 = 0, time2 = 0, time3 = 0;

    // #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    kal_get_time((kal_uint32*) & time1);
    // #endif
    if (g_srv_mms_use_detail_parser_cntx.last_number_searched)
    {
        last_num = g_srv_mms_use_detail_parser_cntx.last_number_searched;
        g_srv_mms_use_detail_parser_cntx.last_number_searched = NULL;
    }
    if (g_srv_mms_use_detail_parser_cntx.last_url_searched)
    {
        last_url = g_srv_mms_use_detail_parser_cntx.last_url_searched;
        g_srv_mms_use_detail_parser_cntx.last_url_searched = NULL;
    }
    if (address_node)
    {
        offset = address_node->offset;
    }
    do
    {
        if (*s == c)
        {
            while (last_num != NULL)
            {
                is_overlap = srv_mms_check_for_overlap(
                                s,
                                g_srv_mms_use_detail_parser_cntx.req_data->input_data + last_num->pos,
                                SRV_MMS_TYPE_EMAIL);
                if (is_overlap == MMI_TRUE)
                {
                    addr = last_num;
                    last_num = last_num->prev;
                    if (last_num != NULL)
                    {
                        last_num->next = NULL;
                    }
                    else
                    {
                        g_srv_mms_use_detail_parser_cntx.num_offset = NULL;
                    }
                    g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(addr);
                    addr = NULL;
                    continue;
                }
                else
                {
                    break;
                }
                last_num = last_num->prev;
            }
            // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
            kal_get_time((kal_uint32*) & time2);
            time3 = kal_ticks_to_milli_secs(time2 - time1);
            MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TIME_EMAIL_SEARCH_WHILE, time3);
            time1 = 0;
            time2 = 0;
            time3 = 0;
            // #endif
            return (U16*) s;
        }
        else
        {
            if (*s == L'+' && no_length == 0)
            {
                no_length++;
            }
            else if (*s >= '0' && *s <= '9')
            {
                no_length++;
            }
            else if ((*s == L'(') || (*s == L')') || (*s == L'-') || (*s == L'w') || (*s == L'p') || (*s == L'P') ||
                     (*s == L'W'))
            {
                if (no_length > 0)
                {
                    no_length++;
                }
            }
            else if (no_length >= SRV_MMS_MIN_PHONE_NUM_LEN)
            {
                is_overlap = srv_mms_check_for_overlap(
                                s - no_length,
                                g_srv_mms_use_detail_parser_cntx.req_data->input_data + offset,
                                SRV_MMS_TYPE_EMAIL);
                if (is_overlap == MMI_FALSE && last_url != NULL)
                {
                    is_overlap = srv_mms_check_for_overlap(
                                    s - no_length,
                                    g_srv_mms_use_detail_parser_cntx.req_data->input_data + last_url->pos,
                                    SRV_MMS_TYPE_URL);
                }
                if (!is_overlap)
                {
                    temp =
                        (srv_mms_offset*) g_srv_mms_use_detail_parser_cntx.req_data->
                        mem_alloc_fn(sizeof(srv_mms_offset));
                    if (temp == NULL)
                    {
                        srv_mms_deinit_use_detail_srv();
                        return NULL;    /* SRV_MMS_VIEWER_OUT_OF_MEM; */
                    }
                    memset(temp, 0, sizeof(srv_mms_offset));
                    temp->pos = ((S32) s - (S32) g_srv_mms_use_detail_parser_cntx.req_data->input_data) / 2 - no_length;
                    temp->next = NULL;
                    temp->prev = NULL;
                    if (g_srv_mms_use_detail_parser_cntx.num_offset)
                    {
                        srv_mms_offset *itr = g_srv_mms_use_detail_parser_cntx.num_offset;

                        while (itr->next != NULL)
                        {
                            itr = itr->next;
                        }
                        itr->next = temp;
                        temp->prev = itr;
                    }
                    else
                    {
                        g_srv_mms_use_detail_parser_cntx.num_offset = temp;
                    }
                    last_num = temp;
                    if (s - g_srv_mms_use_detail_parser_cntx.req_data->input_data >=
                        (SRV_MMS_PARSED_TXT_BUF_UCS2_SIZE * g_srv_mms_use_detail_parser_cntx.count_blocks))
                    {
                        *is_block = MMI_TRUE;
                        *length = s - g_srv_mms_use_detail_parser_cntx.req_data->input_data;
                        g_srv_mms_use_detail_parser_cntx.last_number_searched = last_num;
                        g_srv_mms_use_detail_parser_cntx.last_url_searched = last_url;
                        break;
                    }
                }
                no_length = 0;
                if (*s == L'+')
                {
                    no_length++;
                }
            }
            else
            {
                no_length = 0;
                if (*s == L'+')
                {
                    no_length++;
                }
            }
            if ((*s == L'w') || (*s == L':'))
            {
                count = 0;
                while (count < SRV_MMS_USE_DETAILS_URL_PATTERN_NO)
                {
                    if (mmi_ucs2ncmp((PS8) s, (PS8) pattern[count], mmi_ucs2strlen((PS8) pattern[count])) == 0)
                    {
                        temp_url =
                            (srv_mms_url_offset*) g_srv_mms_use_detail_parser_cntx.req_data->
                            mem_alloc_fn(sizeof(srv_mms_url_offset));
                        if (temp_url == NULL)
                        {
                            srv_mms_deinit_use_detail_srv();
                            return NULL;    /* SRV_MMS_VIEWER_OUT_OF_MEM; */
                        }
                        memset(temp_url, 0, sizeof(srv_mms_url_offset));
                        temp_url->pos = ((S32) s - (S32) g_srv_mms_use_detail_parser_cntx.req_data->input_data) / 2;
                        temp_url->next = NULL;
                        temp_url->type = count;
                        if (g_srv_mms_use_detail_parser_cntx.url_offset)
                        {
                            srv_mms_url_offset *itr = g_srv_mms_use_detail_parser_cntx.url_offset;

                            while (itr->next != NULL)
                            {
                                itr = itr->next;
                            }
                            itr->next = temp_url;
                        }
                        else
                        {
                            g_srv_mms_use_detail_parser_cntx.url_offset = temp_url;
                        }
                        last_url = temp_url;
                        if (s - g_srv_mms_use_detail_parser_cntx.req_data->input_data >=
                            (SRV_MMS_PARSED_TXT_BUF_UCS2_SIZE * g_srv_mms_use_detail_parser_cntx.count_blocks))
                        {
                            *is_block = MMI_TRUE;
                            *length = s - g_srv_mms_use_detail_parser_cntx.req_data->input_data;
                            g_srv_mms_use_detail_parser_cntx.last_number_searched = last_num;
                            g_srv_mms_use_detail_parser_cntx.last_url_searched = last_url;
                            return (0);
                        }
                        break;
                    }
                    count++;
                }
            }
        }
    } while (*s++);
    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    kal_get_time((kal_uint32*) & time2);
    time3 = kal_ticks_to_milli_secs(time2 - time1);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TIME_EMAIL_SEARCH_WHILE, time3);
    time1 = 0;
    time2 = 0;
    time3 = 0;
    // #endif
    return (0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_strstr
 * DESCRIPTION
 *  search for a pattern in the string
 * PARAMETERS
 *  a                   [?]         [?]
 *  count               [IN]        
 *  type                [?]         [?]
 *  address_node        [?]         [?]
 *  is_block            [?]         [?]
 *  length              [?]         [?]
 *  input_data(?)       [IN](?)
 * RETURNS
 *  
 *****************************************************************************/
U16 *srv_mms_strstr(
        U16 *a,
        MMI_BOOL count,
        S32 *type,
        srv_mms_detail *address_node,
        srv_mms_viewer_result_enum *is_block,
        S32 *length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, m, n1, n2, n3, n4;
    U16 *p1 = SRV_MMS_URL_UNICODE_PATTERN_1, *p2 = SRV_MMS_URL_UNICODE_PATTERN_2, *p3 =
        SRV_MMS_URL_UNICODE_PATTERN_3, *p4 = SRV_MMS_URL_UNICODE_PATTERN_4;
    srv_mms_offset *temp = NULL, *last_email = NULL, *addr = NULL, *last_num = NULL;
    S32 no_length = 0, offset = 0;
    MMI_BOOL is_overlap = MMI_FALSE;
    kal_wchar *ret_str = NULL;

    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    S32 time1 = 0, time2 = 0, time3 = 0;

    // #endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    kal_get_time((kal_uint32*) & time1);
    // #endif
    if (g_srv_mms_use_detail_parser_cntx.last_number_searched)
    {
        last_num = g_srv_mms_use_detail_parser_cntx.last_number_searched;
        g_srv_mms_use_detail_parser_cntx.last_number_searched = NULL;
    }
    if (g_srv_mms_use_detail_parser_cntx.last_email_searched)
    {
        last_email = g_srv_mms_use_detail_parser_cntx.last_email_searched;
        g_srv_mms_use_detail_parser_cntx.last_email_searched = NULL;
    }
    if (address_node)
    {
        offset = address_node->offset;
    }
    if (p1 == NULL || a == NULL)
    {
        return NULL;
    }

    m = app_ucs2_wcslen(a);
    n1 = app_ucs2_wcslen(p1);
    n2 = app_ucs2_wcslen(p2);
    n3 = app_ucs2_wcslen(p3);
    n4 = app_ucs2_wcslen(p4);
    i = 0;
    for (i = 0; i < m; i++)
    {
        int i_tmp = i;
        int j1 = 0, j2 = 0, j3 = 0, j4 = 0;

        while (*(a + i) == *(p1 + j1) || *(a + i) == *(p2 + j2) || *(a + i) == *(p3 + j3) || *(a + i) == *(p4 + j4))
        {
            if (*(a + i) == *(p1 + j1))
            {
                j1++;
            }
            if (*(a + i) == *(p2 + j2))
            {
                j2++;
            }
            if (*(a + i) == *(p3 + j3))
            {
                j3++;
            }
            if (*(a + i) == *(p4 + j4))
            {
                j4++;
            }
            i++;
            if (no_length > 0)
            {
                no_length++;
            }
            if (j1 == n1)
            {
                *type = 0;
                // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
                kal_get_time((kal_uint32*) & time2);
                time3 = kal_ticks_to_milli_secs(time2 - time1);
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TIME_URL_SEARCH_WHILE, time3);
                time1 = 0;
                time2 = 0;
                time3 = 0;
                // #endif
                ret_str = (kal_wchar*) (a + i_tmp);
                break;
            }
            else if (j2 == n2)
            {
                // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
                kal_get_time((kal_uint32*) & time2);
                time3 = kal_ticks_to_milli_secs(time2 - time1);
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TIME_URL_SEARCH_WHILE, time3);
                time1 = 0;
                time2 = 0;
                time3 = 0;
                // #endif
                *type = 1;
                ret_str = (kal_wchar*) (a + i_tmp);
                break;
            }
            else if (j3 == n3)
            {
                // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
                kal_get_time((kal_uint32*) & time2);
                time3 = kal_ticks_to_milli_secs(time2 - time1);
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TIME_URL_SEARCH_WHILE, time3);
                time1 = 0;
                time2 = 0;
                time3 = 0;
                // #endif
                *type = 2;
                ret_str = (kal_wchar*) (a + i_tmp);
                break;
            }
            else if (j4 == n4)
            {
                // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
                kal_get_time((kal_uint32*) & time2);
                time3 = kal_ticks_to_milli_secs(time2 - time1);
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TIME_URL_SEARCH_WHILE, time3);
                time1 = 0;
                time2 = 0;
                time3 = 0;
                // #endif
                *type = 3;
                ret_str = (kal_wchar*) (a + i_tmp);
                break;
            }
            else if (i >= m)
            {
                // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
                kal_get_time((kal_uint32*) & time2);
                time3 = kal_ticks_to_milli_secs(time2 - time1);
                MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TIME_URL_SEARCH_WHILE, time3);
                time1 = 0;
                time2 = 0;
                time3 = 0;
                // #endif
                break;
            }
        }
        if (i >= m || ret_str)
        {
            break;
        }
        if (*(a + i) == L'+' && no_length == 0)
        {
            no_length++;
        }
        else if (*(a + i) >= '0' && *(a + i) <= '9' && count == MMI_FALSE)
        {
            no_length++;
        }
        else if ((*(a + i) == L'(') || (*(a + i) == L')') || (*(a + i) == L'-') || (*(a + i) == L'w') ||
                 (*(a + i) == L'p') || (*(a + i) == L'P') || (*(a + i) == L'W'))
        {
            if (no_length > 0)
            {
                no_length++;
            }
        }
        else
        {
            if (no_length >= SRV_MMS_MIN_PHONE_NUM_LEN)
            {
                is_overlap = srv_mms_check_for_overlap(
                                a + i - no_length,
                                g_srv_mms_use_detail_parser_cntx.req_data->input_data + offset,
                                SRV_MMS_TYPE_URL);
                if (is_overlap == MMI_FALSE && last_email != NULL)
                {
                    is_overlap = srv_mms_check_for_overlap(
                                    a + i - no_length,
                                    g_srv_mms_use_detail_parser_cntx.req_data->input_data + last_email->pos,
                                    SRV_MMS_TYPE_EMAIL);
                }
                if (!is_overlap)
                {
                    temp =
                        (srv_mms_offset*) g_srv_mms_use_detail_parser_cntx.req_data->
                        mem_alloc_fn(sizeof(srv_mms_offset));
                    if (temp == NULL)
                    {
                        srv_mms_deinit_use_detail_srv();
                        *is_block = SRV_MMS_VIEWER_OUT_OF_MEM;
                        return NULL;    /* SRV_MMS_VIEWER_OUT_OF_MEM; */
                    }
                    memset(temp, 0, sizeof(srv_mms_offset));
                    temp->pos =
                        ((S32) (a + i) - (S32) g_srv_mms_use_detail_parser_cntx.req_data->input_data) / 2 - no_length;
                    temp->next = NULL;
                    if (g_srv_mms_use_detail_parser_cntx.num_offset)
                    {
                        srv_mms_offset *itr = g_srv_mms_use_detail_parser_cntx.num_offset;

                        while (itr->next != NULL)
                        {
                            itr = itr->next;
                        }
                        itr->next = temp;
                        temp->prev = itr;
                    }
                    else
                    {
                        g_srv_mms_use_detail_parser_cntx.num_offset = temp;
                    }
                    last_num = temp;
                    if (a + i - g_srv_mms_use_detail_parser_cntx.req_data->input_data >=
                        (SRV_MMS_PARSED_TXT_BUF_UCS2_SIZE * g_srv_mms_use_detail_parser_cntx.count_blocks))
                    {
                        *is_block = SRV_MMS_VIEWER_PARSE_BLOCK;
                        no_length = 0;
                        *length = a + i - g_srv_mms_use_detail_parser_cntx.req_data->input_data;
                        g_srv_mms_use_detail_parser_cntx.last_number_searched = last_num;
                        g_srv_mms_use_detail_parser_cntx.last_email_searched = last_email;
                        break;
                    }
                }
                no_length = 0;
            }
            no_length = 0;
            if (*(a + i) == L'+')
            {
                no_length++;
            }
            if (*(a + i) == '@' && count == MMI_FALSE)
            {
                temp =
                    (srv_mms_offset*) g_srv_mms_use_detail_parser_cntx.req_data->mem_alloc_fn(sizeof(srv_mms_offset));
                if (temp == NULL)
                {
                    srv_mms_deinit_use_detail_srv();
                    *is_block = SRV_MMS_VIEWER_OUT_OF_MEM;
                    return NULL;    /* SRV_MMS_VIEWER_OUT_OF_MEM; */
                }
                memset(temp, 0, sizeof(srv_mms_offset));
                temp->pos = ((S32) (a + i) - (S32) g_srv_mms_use_detail_parser_cntx.req_data->input_data) / 2;
                if (temp->pos == 2563)
                {
                    temp->pos = 2563;
                }
                temp->next = NULL;
                if (g_srv_mms_use_detail_parser_cntx.email_offset)
                {
                    srv_mms_offset *itr = g_srv_mms_use_detail_parser_cntx.email_offset;

                    while (itr->next != NULL)
                    {
                        itr = itr->next;
                    }
                    itr->next = temp;
                }
                else
                {
                    g_srv_mms_use_detail_parser_cntx.email_offset = temp;
                }
                while (last_num != NULL)
                {
                    is_overlap = srv_mms_check_for_overlap(
                                    a + i,
                                    g_srv_mms_use_detail_parser_cntx.req_data->input_data + last_num->pos,
                                    SRV_MMS_TYPE_EMAIL);
                    if (is_overlap == MMI_TRUE)
                    {
                        addr = last_num;
                        last_num = last_num->prev;
                        if (last_num != NULL)
                        {
                            last_num->next = NULL;
                        }
                        else
                        {
                            g_srv_mms_use_detail_parser_cntx.num_offset = NULL;
                        }
                        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(addr);
                        addr = NULL;
                        continue;
                    }
                    else
                    {
                        break;
                    }
                    last_num = last_num->prev;
                }
                last_email = temp;
                if (a + i - g_srv_mms_use_detail_parser_cntx.req_data->input_data >=
                    (SRV_MMS_PARSED_TXT_BUF_UCS2_SIZE * g_srv_mms_use_detail_parser_cntx.count_blocks))
                {
                    *is_block = SRV_MMS_VIEWER_PARSE_BLOCK;
                    *length = a + i - g_srv_mms_use_detail_parser_cntx.req_data->input_data;
                    g_srv_mms_use_detail_parser_cntx.last_number_searched = last_num;
                    g_srv_mms_use_detail_parser_cntx.last_email_searched = last_email;
                    break;
                }
            }
        }

        i = i_tmp;
    }
    if (no_length >= SRV_MMS_MIN_PHONE_NUM_LEN)
    {
        is_overlap = srv_mms_check_for_overlap(
                        a + i - no_length,
                        g_srv_mms_use_detail_parser_cntx.req_data->input_data + offset,
                        SRV_MMS_TYPE_URL);
        if (is_overlap == MMI_FALSE && last_email != NULL)
        {
            is_overlap = srv_mms_check_for_overlap(
                            a + i - no_length,
                            g_srv_mms_use_detail_parser_cntx.req_data->input_data + last_email->pos,
                            SRV_MMS_TYPE_EMAIL);
        }
        if (!is_overlap)
        {
            temp = (srv_mms_offset*) g_srv_mms_use_detail_parser_cntx.req_data->mem_alloc_fn(sizeof(srv_mms_offset));
            if (temp == NULL)
            {
                srv_mms_deinit_use_detail_srv();
                *is_block = SRV_MMS_VIEWER_OUT_OF_MEM;
                return NULL;    /* SRV_MMS_VIEWER_OUT_OF_MEM; */
            }
            memset(temp, 0, sizeof(srv_mms_offset));
            temp->pos = ((S32) (a + i) - (S32) g_srv_mms_use_detail_parser_cntx.req_data->input_data) / 2 - no_length;
            temp->next = NULL;
            if (g_srv_mms_use_detail_parser_cntx.num_offset)
            {
                srv_mms_offset *itr = g_srv_mms_use_detail_parser_cntx.num_offset;

                while (itr->next != NULL)
                {
                    itr = itr->next;
                }
                itr->next = temp;
            }
            else
            {
                g_srv_mms_use_detail_parser_cntx.num_offset = temp;
            }
            no_length = 0;
        }
    }
    // #ifdef MMI_MV_USE_DETAIL_UNIT_TEST
    kal_get_time((kal_uint32*) & time2);
    time3 = kal_ticks_to_milli_secs(time2 - time1);
    MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_SRV_VIEWER_TIME_URL_SEARCH_WHILE, time3);
    time1 = 0;
    time2 = 0;
    time3 = 0;
    // #endif
    return ret_str;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_free_offsets
 * DESCRIPTION
 *  Free memory of nodes
 * PARAMETERS
 *  node        [IN]        
 *  input_data(?)       [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_free_offsets(srv_mms_detail **node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_detail *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*node != NULL)
    {
        temp = *node;
        *node = (*node)->next;
        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp);
        temp = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_free_num_offsets
 * DESCRIPTION
 *  Free memory of nodes
 * PARAMETERS
 *  node        [?]     [?]
 *  input_data(?)       [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_free_num_offsets(srv_mms_number_detail *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_number_detail *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (node != NULL)
    {
        temp = node;
        node = node->next;
        if (node)
        {
            node->prev = NULL;
        }
        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp);
        temp = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_free_other_offsets
 * DESCRIPTION
 *  Free memory of nodes
 * PARAMETERS
 *  node        [?]     [?]
 *  input_data(?)       [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_free_other_offsets(srv_mms_offset *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_offset *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (node != NULL)
    {
        temp = node;
        node = node->next;
        if (node)
        {
            node->prev = NULL;
        }
        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp);
        temp = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_free_url_offsets
 * DESCRIPTION
 *  Free memory of URL nodes
 * PARAMETERS
 *  node        [IN]        
 *  input_data(?)       [IN](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_free_url_offsets(srv_mms_url_offset **node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_url_offset *temp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*node != NULL)
    {
        temp = *node;
        *node = (*node)->next;
        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp);
        temp = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_strstr_ext
 * DESCRIPTION
 *  search for a pattern in the string
 * PARAMETERS
 *  type            [?]     [?]
 *  type_detail     [?]     [?]
 *  input_data(?)       [IN](?)
 * RETURNS
 *  
 *****************************************************************************/
U16 *srv_mms_strstr_ext(U16 *type, srv_mms_use_detail *type_detail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, m, n1, n2, n3, n4;
    U16 *p1 = SRV_MMS_URL_UNICODE_PATTERN_1, *p2 = SRV_MMS_URL_UNICODE_PATTERN_2, *p3 =
        SRV_MMS_URL_UNICODE_PATTERN_3, *p4 = SRV_MMS_URL_UNICODE_PATTERN_4;
    U16 *a = g_srv_mms_use_detail_parser_cntx.req_data->input_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (p1 == NULL || a == NULL)
    {
        return NULL;
    }

    m = app_ucs2_wcslen(a);
    n1 = app_ucs2_wcslen(p1);
    n2 = app_ucs2_wcslen(p2);
    n3 = app_ucs2_wcslen(p3);
    n4 = app_ucs2_wcslen(p4);
    i = 0;
    for (i = 0; i < m; i++)
    {
        int i_tmp = i;
        int j1 = 0, j2 = 0, j3 = 0, j4 = 0;

        while (*(a + i) == *(p1 + j1) || *(a + i) == *(p2 + j2) || *(a + i) == *(p3 + j3) || *(a + i) == *(p4 + j4))
        {
            if (*(a + i) == *(p1 + j1))
            {
                if (!j1)
                {
                    i_tmp = i;
                }
                j1++;
            }
            if (*(a + i) == *(p2 + j2))
            {
                if (!j2)
                {
                    i_tmp = i;
                }
                j2++;
            }
            if (*(a + i) == *(p3 + j3))
            {
                if (!j3)
                {
                    i_tmp = i;
                }
                j3++;
            }
            if (*(a + i) == *(p4 + j4))
            {
                if (!j4)
                {
                    i_tmp = i;
                }
                j4++;
            }
            i++;
            if (j1 == n1)
            {
                *type = 0;
                *type_detail = SRV_MMS_TYPE_URL;
                return (kal_wchar*) (a + i_tmp);
            }
            else if (j2 == n2)
            {
                *type = 1;
                *type_detail = SRV_MMS_TYPE_URL;
                return (kal_wchar*) (a + i_tmp);
            }
            else if (j3 == n3)
            {
                *type = 2;
                *type_detail = SRV_MMS_TYPE_URL;
                return (kal_wchar*) (a + i_tmp);
            }
            else if (j4 == n4)
            {
                *type = 3;
                *type_detail = SRV_MMS_TYPE_URL;
                return (kal_wchar*) (a + i_tmp);
            }
            else if (i >= m)
            {
                return NULL;
            }
        }
        if (*(a + i) >= '0' && *(a + i) <= '9' || *(a + i) == L'+' || *(a + i) == L'(' || *(a + i) == L')' ||
            *(a + i) == L'-')
        {
            /* set Type detail */
            *type_detail = SRV_MMS_TYPE_NUMBER;
            return (kal_wchar*) (a + i);
        }
        else if (*(a + i) == '@')
        {
            /* set Type detail */
            *type_detail = SRV_MMS_TYPE_EMAIL;
            return (kal_wchar*) (a + i);
        }
        i = i_tmp;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_for_overlap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  end         [?]         [?]
 *  data        [?]         [?]
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_check_for_overlap(U16 *end, U16 *data, srv_mms_use_detail type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *temp = data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*temp == L'@')
    {
        temp++; /* avoid "@" to be validated as local or domain char */
    }
    while (temp != end)
    {
        if (*temp == 32 || *temp == 13)
        {
            return MMI_FALSE;
        }
        if (type == SRV_MMS_TYPE_EMAIL && !srv_mms_is_valid_email_local_part_wchar(*temp) &&
            !srv_mms_is_valid_email_domain_name_wchar(*temp))
        {
            return MMI_FALSE;
        }
        else if (type == SRV_MMS_TYPE_URL && !srv_mms_is_valid_url_wchar(*temp))
        {
            return MMI_FALSE;
        }
        temp++;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_duplicate_phoneno_no_written_sep
 * DESCRIPTION
 *  This function is used to duplicate a phone number.
 *  The duplicate contains only digit and '+', 'w', 'p' characters, that is, skipping '(', ')', '-', '.', etc.
 * PARAMETERS
 *  mem_alloc_fn        [IN]        Memory allication function
 *  str                 [IN]        Input phone number string
 * RETURNS
 *  phone number string
 *****************************************************************************/
U16 *srv_mms_duplicate_phoneno_no_written_sep(srv_mms_alloc_mem mem_alloc_fn, U16 *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *number = NULL;
    U16 *ptr = NULL;
    S32 dest_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (str == NULL)
    {
        return NULL;
    }

    number = mem_alloc_fn(mmi_ucs2strlen((S8*) str) * 2 + 2);
    if (!number)
    {
        srv_mms_deinit_use_detail_srv();
        return NULL;    /* SRV_MMS_VIEWER_OUT_OF_MEM; */
    }
    memset(number, 0, mmi_ucs2strlen((S8*) str) * 2 + 2);
    ptr = str;
    while (*ptr != L'\0')
    {
        if (srv_mms_is_valid_phoneno_wchar(*ptr, MMI_FALSE) == MMI_TRUE)
        {
            number[dest_len++] = *ptr;
        }
        ptr++;
    }
    number[dest_len] = L'\0';
    return number;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_valid_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  data        [IN]        
 *  start       [IN]        
 *  len         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_check_valid_email(PU16 data, PU16 start, S32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *end = NULL, *data_new = NULL;
    MMI_BOOL is_length_increased = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_new = data;
    while (*start != L'@')
    {
        start--;
        is_length_increased = MMI_TRUE;
        data_new--;
    }
    end = start + mmi_ucs2strlen((PS8) L"@");
    if (is_length_increased)
    {
        is_length_increased = MMI_FALSE;
        len += data - data_new;
        data = data_new;
    }
    if (srv_mms_is_valid_email_local_part_wchar(*(start - 1)) == MMI_FALSE || *(start - 1) == L'.')     /* '.' should not be the last character in the local-part */
    {
        return MMI_FALSE;
    }
    else
    {
        while ((start - 1 >= data) && srv_mms_is_valid_email_local_part_wchar(*(start - 1)))
        {
            start--;
        }
        while (*start == L'.')  /* '.' should not be the first character in the local-part */
        {
            start++;
        }

        /* we get the begining of URL string and go to find its end */
        while ((end - data) < len && srv_mms_is_valid_email_domain_name_wchar(*end))
        {
            end++;
        }
        while (*(end - 1) == L'.')  /* removing trailing dot(s) */
        {
            end--;
        }
        if (end == app_ucs2_strstr((PU16) start, L"@") + mmi_ucs2strlen((PS8) L"@"))     /* host string is NULL */
        {
            if ((end - data) < len)
            {
                return MMI_FALSE;
            }
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_deinit_use_detail_srv
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_deinit_use_detail_srv(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_mms_use_detail_parser_cntx.num_offset)
    {
        srv_mms_free_other_offsets(g_srv_mms_use_detail_parser_cntx.num_offset);
        g_srv_mms_use_detail_parser_cntx.num_offset = NULL;
    }
    if (g_srv_mms_use_detail_parser_cntx.email_offset)
    {
        srv_mms_free_other_offsets(g_srv_mms_use_detail_parser_cntx.email_offset);
        g_srv_mms_use_detail_parser_cntx.email_offset = NULL;
    }
    if (g_srv_mms_use_detail_parser_cntx.url_offset)
    {
        srv_mms_free_url_offsets(&g_srv_mms_use_detail_parser_cntx.url_offset);
        g_srv_mms_use_detail_parser_cntx.url_offset = NULL;
    }
    if (g_srv_mms_use_detail_parser_cntx.number_list)
    {
        srv_mms_free_num_offsets(g_srv_mms_use_detail_parser_cntx.number_list);
        g_srv_mms_use_detail_parser_cntx.number_list = NULL;
    }
    if (g_srv_mms_use_detail_parser_cntx.url_list)
    {
        srv_mms_free_offsets(&g_srv_mms_use_detail_parser_cntx.url_list);
        g_srv_mms_use_detail_parser_cntx.url_list = NULL;
    }
    if (g_srv_mms_use_detail_parser_cntx.email_list)
    {
        srv_mms_free_offsets(&g_srv_mms_use_detail_parser_cntx.email_list);
        g_srv_mms_use_detail_parser_cntx.email_list = NULL;
    }
    if (g_data_lc)
    {
        g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(g_data_lc);
        g_data_lc = NULL;
    }
    memset(&g_srv_mms_use_detail_parser_cntx, 0, sizeof(srv_mms_use_detail_struct));
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_overlap_last_number_and_del_before_block
 * DESCRIPTION
 *  
 * PARAMETERS
 *  end     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_check_overlap_last_number_and_del_before_block(U16 *end)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_number_detail *iterator = g_srv_mms_use_detail_parser_cntx.num_before_blk, *temp = NULL;
    MMI_BOOL is_overlap = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (iterator)
    {
        is_overlap = srv_mms_check_for_overlap(
                        end,
                        g_srv_mms_use_detail_parser_cntx.req_data->input_data + iterator->offset,
                        SRV_MMS_TYPE_EMAIL);
        if (is_overlap == MMI_TRUE)
        {
            temp = g_srv_mms_use_detail_parser_cntx.num_before_blk;
            g_srv_mms_use_detail_parser_cntx.num_before_blk = g_srv_mms_use_detail_parser_cntx.num_before_blk->prev;
            if (g_srv_mms_use_detail_parser_cntx.num_before_blk)
            {
                g_srv_mms_use_detail_parser_cntx.num_before_blk->next = NULL;
            }
            g_srv_mms_use_detail_parser_cntx.req_data->mem_free_fn(temp);
            if (g_srv_mms_use_detail_parser_cntx.num_before_blk == NULL)
            {
                g_srv_mms_use_detail_parser_cntx.number_list = NULL;
            }
            temp = NULL;
            g_srv_mms_use_detail_parser_cntx.parsed_num--;
        }
        else
        {
            break;
        }
        iterator = iterator->prev;
    }
}

#endif /* defined (__MMI_MMS_2__) && defined (__MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__) */ 

