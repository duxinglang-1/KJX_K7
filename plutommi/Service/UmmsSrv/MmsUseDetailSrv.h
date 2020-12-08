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
 *  MMSUseDetailSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 * Use Detail Parser related files
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
 *============================================================================
 ****************************************************************************/
#if defined (__MMI_MMS_2__) && defined (__MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__)
#include "MMIDataType.h"
#include "MmsXMLDefSrv.h"
#include "kal_general_types.h"

#define SRV_MMS_USE_DETAILS_URL_SCHEME_NO 3
#define SRV_MMS_USE_DETAILS_URL_PATTERN_NO 4
#define SRV_MMS_URL_SCHEME1 "http"
#define SRV_MMS_URL_SCHEME2 "https"
#define SRV_MMS_URL_SCHEME3 "rtsp"
#define SRV_MMS_MIN_PHONE_NUM_LEN    3
#define SRV_MMS_MAX_PHONE_NUM_LEN    41

#define SRV_MMS_URL_UNICODE_SCHEME1 L"http"
#define SRV_MMS_URL_UNICODE_SCHEME2 L"https"
#define SRV_MMS_URL_UNICODE_SCHEME3 L"rtsp"

#define SRV_MMS_URL_UNICODE_PATTERN_1  L"://"
#define SRV_MMS_URL_UNICODE_PATTERN_2  L":\\\\"
#define SRV_MMS_URL_UNICODE_PATTERN_3  L"wap."
#define SRV_MMS_URL_UNICODE_PATTERN_4  L"www."

#define SRV_MMS_MAX_OFFSET_LEN 9
typedef struct srv_mms_address_node_st
{
    S8 *data;
    S8 *data2;      /* Not null for APPLIB_ADDR_TYPE_PHONENUMBER. Same as *data but without written-seq, ex. '(', ')', '-' */
    S32 dataType;   /* APPLIB_ADDR_TYPE_EMAIL, APPLIB_ADDR_TYPE_URL and APPLIB_ADDR_TYPE_PHONENUMBER */
    S32 pos;
    S32 length;     /* Count by byte not character */
    struct srv_mms_address_node_st *next;
} srv_mms_address_node_struct;
typedef enum
{
    SRV_MMS_TYPE_DEFAULT,
    SRV_MMS_TYPE_NUMBER,
    SRV_MMS_TYPE_EMAIL,
    SRV_MMS_TYPE_URL
} srv_mms_use_detail;

typedef enum
{
    SRV_MMS_USE_NONE,
    SRV_MMS_USE_NEU,
    SRV_MMS_USE_ENU,
    SRV_MMS_USE_UNE
} srv_mms_use_detail_order_enum;

typedef struct _srv_mms_offset
{
    struct _srv_mms_offset *next;
    struct _srv_mms_offset *prev;
    S32 pos;
}
srv_mms_offset;

typedef struct _srv_mms_buffer
{
    struct _srv_mms_buffer *next;
    struct _srv_mms_buffer *prev;
    S32 count;
    S32 *buffer;
}
srv_mms_buffer;

typedef struct _srv_mms_url_offset
{
    struct _srv_mms_url_offset *next;
    S32 pos;
    U16 type;
}
srv_mms_url_offset;
typedef struct _srv_mms_detail
{
    S16 offset;
    S16 size;
    struct _srv_mms_detail *next;
} srv_mms_detail;
typedef struct _srv_mms_number_detail
{
    S16 offset;
    S16 size;
    struct _srv_mms_number_detail *next;
    struct _srv_mms_number_detail *prev;
} srv_mms_number_detail;

typedef struct
{
    srv_mms_alloc_mem mem_alloc_fn;
    srv_mms_free_mem mem_free_fn;
    U16 *input_data;
    U16 total_slides;
    U16 slide_num;
    S16 *header;
    MMI_BOOL slide_not_parsed;
    U32 *number_count;
    U32 *email_count;
    U32 *url_count;
    S32 *fail_reason;
    S32 dataLen;
    S32 file_handle;
} srv_mms_use_detail_req_context_struct;

typedef struct
{
    U8 is_num_bet_email;
    U16 *last_offset;
    U16 parsed_num;
    U16 parsed_email;
    U16 parsed_url;
    U16 other_parse_count;
    MMI_BOOL other_parse;
    U32 count_blocks;
    srv_mms_use_detail_order_enum order_type;
    srv_mms_use_detail_req_context_struct *req_data;
    srv_mms_offset *num_offset;
    srv_mms_offset *email_offset;
    srv_mms_offset *last_number_searched;
    srv_mms_offset *last_email_searched;
    srv_mms_url_offset *url_offset;
    srv_mms_url_offset *last_url_searched;
    srv_mms_number_detail *number_list;
    srv_mms_number_detail *num_before_blk;
    srv_mms_detail *url_list;
    srv_mms_detail *email_list;
    srv_mms_offset *num_other_last_offset;
    srv_mms_offset *email_other_last_offset;
    srv_mms_url_offset *url_other_last_offset;
} srv_mms_use_detail_struct;

extern srv_mms_viewer_result_enum srv_mms_common_parse(srv_mms_use_detail_req_context_struct *data);
extern U16 *srv_mms_duplicate_phoneno_no_written_sep(srv_mms_alloc_mem mem_alloc_fn, U16 *str);

#endif /* defined (__MMI_MMS_2__) && defined (__MMI_MMS_UNLIMITED_USE_DETAILS_SUPPORT__) */ 

